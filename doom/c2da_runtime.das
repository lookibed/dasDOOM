options gen2
options solid_context = true
options stack = 4194304
module c2da_runtime public

require strings
require daslib/fio
var c2da_rt_heap : array<uint8>

var c2da_rt_locals : array<uint64>

var c2da_rt_next : uint64 = 0x0

var c2da_rt_alloc_addrs : array<uint64>

var c2da_rt_alloc_sizes : array<uint64>

var c2da_rt_alloc_live : array<bool>

var c2da_rt_alloc_free : array<int>

[sideeffects]
def c2da_rt_init_heap() {
    if (empty(c2da_rt_heap)) {
        reserve(c2da_rt_heap, 1073741824l)
        resize(c2da_rt_heap, 1)
    }
}
[sideeffects]
def c2da_rt_reset() {
    c2da_rt_next = 0x0
    resize(c2da_rt_alloc_addrs, 0)
    resize(c2da_rt_alloc_sizes, 0)
    resize(c2da_rt_alloc_live, 0)
    resize(c2da_rt_alloc_free, 0)
}
[sideeffects]
def c2da_rt_find_record(address : uint64) : int {
    var lo : int = 0
    var hi : int = length(c2da_rt_alloc_addrs)
    while (lo < hi) {
        let mid : int = (lo + hi) / 2
        if (c2da_rt_alloc_addrs[mid] < address) {
            lo = mid + 1
        } else {
            hi = mid
        }
    }
    if (lo < length(c2da_rt_alloc_addrs) && c2da_rt_alloc_addrs[lo] == address) {
        return lo
    }
    return -1
}
[sideeffects]
def c2da_rt_take_free(need : uint64) : int {
    var best : int = -1
    var best_slot : int = -1
    var slot : int = length(c2da_rt_alloc_free) - 1
    while (slot >= 0) {
        let record : int = c2da_rt_alloc_free[slot]
        let capacity : uint64 = c2da_rt_alloc_sizes[record]
        if (capacity >= need && capacity - need <= need) {
            if (best < 0 || capacity < c2da_rt_alloc_sizes[best]) {
                best = record
                best_slot = slot
            }
            if (capacity == need) {
                break
            }
        }
        slot--
    }
    if (best >= 0) {
        c2da_rt_alloc_free[best_slot] = int(c2da_rt_alloc_free[length(c2da_rt_alloc_free) - 1])  // nolint:PERF020
        pop(c2da_rt_alloc_free)
    }
    return best
}
[sideeffects]
def c2da_rt_malloc(size : uint64) : uint64 {
    c2da_rt_init_heap()
    if (size == 0x0 || size > 0x40000000) {
        return 0x0
    }
    let need : uint64 = (size + 0xf) / 0x10 * 0x10
    let reused : int = c2da_rt_take_free(need)
    if (reused >= 0) {
        c2da_rt_alloc_live[reused] = true
        return c2da_rt_alloc_addrs[reused]
    }
    let base : uint64 = unsafe(intptr(unsafe(addr(c2da_rt_heap[0x0]))))
    let start : uint64 = (base + c2da_rt_next + 0xf) / 0x10 * 0x10 - base
    let end : uint64 = start + need
    if (end > 0x40000000) {
        return 0x0
    }
    if (int64(end) > long_length(c2da_rt_heap)) {
        resize(c2da_rt_heap, int64(end))
    }
    c2da_rt_next = end
    let address : uint64 = unsafe(intptr(unsafe(addr(c2da_rt_heap[start]))))
    let record : uint64 = uint64(long_length(c2da_rt_alloc_addrs))
    resize(c2da_rt_alloc_addrs, int64(record + 0x1))
    resize(c2da_rt_alloc_sizes, int64(record + 0x1))
    resize(c2da_rt_alloc_live, int64(record + 0x1))
    c2da_rt_alloc_addrs[record] = address
    c2da_rt_alloc_sizes[record] = need
    c2da_rt_alloc_live[record] = true
    return address
}
[sideeffects]
def c2da_rt_free(address : uint64) {
    let record : int = c2da_rt_find_record(address)
    if (record >= 0 && c2da_rt_alloc_live[record]) {
        c2da_rt_alloc_live[record] = false
        push(c2da_rt_alloc_free, record)
    }
}
[sideeffects]
def c2da_rt_realloc(address : uint64; size : uint64) : uint64 {
    if (address == 0x0) {
        return c2da_rt_malloc(size)
    }
    if (size == 0x0) {
        c2da_rt_free(address)
        return 0x0
    }
    let record : int = c2da_rt_find_record(address)
    if (record < 0 || !c2da_rt_alloc_live[record]) {
        return 0x0
    }
    let capacity : uint64 = c2da_rt_alloc_sizes[record]
    if (size <= capacity) {
        return address
    }
    if (size > 0x40000000) {
        return 0x0
    }
    let need : uint64 = (size + 0xf) / 0x10 * 0x10
    let start : uint64 = address - unsafe(intptr(unsafe(addr(c2da_rt_heap[0x0]))))
    let end : uint64 = start + need
    if (start + capacity == c2da_rt_next && end <= 0x40000000) {
        if (int64(end) > long_length(c2da_rt_heap)) {
            resize(c2da_rt_heap, int64(end))
        }
        c2da_rt_next = end
        c2da_rt_alloc_sizes[record] = need
        return address
    }
    let replacement : uint64 = c2da_rt_malloc(size)
    if (replacement == 0x0) {
        return 0x0
    }
    c2da_rt_memcpy(replacement, address, capacity)
    c2da_rt_free(address)
    return replacement
}
[sideeffects]
def c2da_rt_memset(dst : uint64; value : uint8; count : uint64) : uint64 {
    var done : uint64 = 0x0
    while (done < count) {
        let chunk : uint64 = count - done < 0x40000000ul ? count - done : 0x40000000ul
        unsafe(memset8(unsafe(reinterpret<void?>(dst + done)), value, int(chunk)))
        done += chunk
    }
    return dst
}
[sideeffects]
def c2da_rt_calloc(count : uint64; size : uint64) : uint64 {
    let total : uint64 = count * size
    if (size != 0x0 && total / size != count) {
        return 0x0
    }
    let address : uint64 = c2da_rt_malloc(total)
    if (address != 0x0) {
        c2da_rt_memset(address, 0x0u8, total)
    }
    return address
}
[sideeffects]
def c2da_rt_memcpy(dst : uint64; src : uint64; count : uint64) : uint64 {
    var i : uint64 = 0x0
    while (i < count) {
        unsafe(unsafe(reinterpret<uint8?>(dst))[i]) = uint8(unsafe(unsafe(reinterpret<uint8?>(src))[i]))  // nolint:PERF020
        i = i + 0x1
    }
    return dst
}
[sideeffects]
def c2da_rt_memcmp(left : uint64; right : uint64; count : uint64) : int {
    var i : uint64 = 0x0
    while (i < count) {
        if (uint(unsafe(unsafe(reinterpret<uint8?>(left))[i])) < uint(unsafe(unsafe(reinterpret<uint8?>(right))[i]))) {
            return -1
        }
        if (uint(unsafe(unsafe(reinterpret<uint8?>(left))[i])) > uint(unsafe(unsafe(reinterpret<uint8?>(right))[i]))) {
            return 1
        }
        i = i + 0x1
    }
    return 0
}
[sideeffects]
def c2da_rt_memmove(dst : uint64; src : uint64; count : uint64) : uint64 {
    if (dst < src) {
        var i : uint64 = 0x0
        while (i < count) {
            unsafe(unsafe(reinterpret<uint8?>(dst))[i]) = uint8(unsafe(unsafe(reinterpret<uint8?>(src))[i]))  // nolint:PERF020
            i = i + 0x1
        }
    } else {
        var i : uint64 = count
        while (i > 0x0) {
            i = i - 0x1
            unsafe(unsafe(reinterpret<uint8?>(dst))[i]) = uint8(unsafe(unsafe(reinterpret<uint8?>(src))[i]))  // nolint:PERF020
        }
    }
    return dst
}
[sideeffects]
def c2da_rt_memchr(src : uint64; value : uint8; count : uint64) : uint64 {
    var i : uint64 = 0x0
    while (i < count) {
        if (unsafe(unsafe(reinterpret<uint8?>(src))[i]) == value) {
            return src + i
        }
        i = i + 0x1
    }
    return 0x0
}
[sideeffects]
def c2da_rt_frame_enter() : int {
    return length(c2da_rt_locals)
}
[sideeffects]
def c2da_rt_frame_leave(mark : int) {
    while (length(c2da_rt_locals) > mark) {
        c2da_rt_free(c2da_rt_locals[length(c2da_rt_locals) - 1])
        pop(c2da_rt_locals)
    }
}
[sideeffects]
def c2da_rt_local(size : uint64; align : uint64) : uint64 {
    let address = c2da_rt_calloc(0x1ul, size + 0x1)
    if (address == 0x0) {
        panic("c2da runtime: the 1073741824-byte heap reserve cannot hold storage for a C local")
    }
    push(c2da_rt_locals, address)
    return address
}
[sideeffects]
def c2da_rt_static(size : uint64; align : uint64) : uint64 {
    let address = c2da_rt_calloc(0x1ul, size + 0x1)
    if (address == 0x0) {
        panic("c2da runtime: the 1073741824-byte heap reserve cannot hold storage for a C static object")
    }
    return address
}
struct C2daVaArg {
    tag : int
    i64 : int64
    f64 : double
    raw : uint64
}
struct C2daVaCursor {
    index : int
}
[sideeffects]
def c2da_clip_uint(v : int) : uint {
    if (v < 0) {
        return 0x0
    }
    if (v > 255) {
        return 0xff
    }
    return uint(v)
}
[sideeffects]
def c2da_bool_to_uint(v : bool) : uint {
    if (v) {
        return 0x1
    } else {
        return 0x0
    }
}
[sideeffects]
def c2da___assert_fail(expr : void?; file : void?; line : uint; func : void?) {
}
typedef boolean = uint
typedef size_t = uint64
struct _IO_FILE {
    _flags : int
    _IO_read_ptr : int8?
    _IO_read_end : int8?
    _IO_read_base : int8?
    _IO_write_base : int8?
    _IO_write_ptr : int8?
    _IO_write_end : int8?
    _IO_buf_base : int8?
    _IO_buf_end : int8?
    _IO_save_base : int8?
    _IO_backup_base : int8?
    _IO_save_end : int8?
    _markers : _IO_marker?
    _chain : _IO_FILE?
    _fileno : int
    _flags2 : int
    _old_offset : int64
    _cur_column : uint16
    _vtable_offset : int8
    _shortbuf : int8[1]
    _lock : uint8?
    _offset : int64
    _codecvt : _IO_codecvt?
    _wide_data : _IO_wide_data?
    _freeres_list : _IO_FILE?
    _freeres_buf : uint8?
    c2da___pad5 : uint64
    _mode : int
    _unused2 : int8[20]
}
struct _IO_wide_data {
}
struct _IO_codecvt {
}
typedef _IO_lock_t = void
struct _IO_marker {
}
struct FILE_0 {
    _flags : int
    _IO_read_ptr : int8?
    _IO_read_end : int8?
    _IO_read_base : int8?
    _IO_write_base : int8?
    _IO_write_ptr : int8?
    _IO_write_end : int8?
    _IO_buf_base : int8?
    _IO_buf_end : int8?
    _IO_save_base : int8?
    _IO_backup_base : int8?
    _IO_save_end : int8?
    _markers : _IO_marker?
    _chain : _IO_FILE?
    _fileno : int
    _flags2 : int
    _old_offset : int64
    _cur_column : uint16
    _vtable_offset : int8
    _shortbuf : int8[1]
    _lock : uint8?
    _offset : int64
    _codecvt : _IO_codecvt?
    _wide_data : _IO_wide_data?
    _freeres_list : _IO_FILE?
    _freeres_buf : uint8?
    c2da___pad5 : uint64
    _mode : int
    _unused2 : int8[20]
}
typedef uint8_t = uint8
typedef byte = uint8
enum weapontype_t : uint {
    wp_fist = 0
    wp_pistol = 1
    wp_shotgun = 2
    wp_chaingun = 3
    wp_missile = 4
    wp_plasma = 5
    wp_bfg = 6
    wp_chainsaw = 7
    wp_supershotgun = 8
    NUMWEAPONS = 9
    wp_nochange = 10
}
enum evtype_t : uint {
    ev_keydown = 0
    ev_keyup = 1
    ev_mouse = 2
    ev_joystick = 3
    ev_quit = 4
}
struct event_t {
    type_0 : evtype_t
    data1 : int
    data2 : int
    data3 : int
    data4 : int
}
struct cheatseq_t {
    sequence : int8[25]
    sequence_len : uint64
    parameter_chars : int
    chars_read : uint64
    param_chars_read : int
    parameter_buf : int8[5]
}
typedef fixed_t = int
typedef angle_t = uint
typedef actionf_v = function<():void>
typedef actionf_p1 = function<(var _arg0:uint8?):void>
typedef actionf_p2 = function<(var _arg0:uint8?;var _arg1:uint8?):void>
struct actionf_t {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 8ul)
}
struct thinker_s {
    prev : thinker_s?
    next : thinker_s?
    function_0 : uint64
}
struct thinker_t {
    prev : thinker_s?
    next : thinker_s?
    function_0 : uint64
}
struct mapthing_t {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 10ul)
}
enum spritenum_t : uint {
    SPR_TROO = 0
    SPR_SHTG = 1
    SPR_PUNG = 2
    SPR_PISG = 3
    SPR_PISF = 4
    SPR_SHTF = 5
    SPR_SHT2 = 6
    SPR_CHGG = 7
    SPR_CHGF = 8
    SPR_MISG = 9
    SPR_MISF = 10
    SPR_SAWG = 11
    SPR_PLSG = 12
    SPR_PLSF = 13
    SPR_BFGG = 14
    SPR_BFGF = 15
    SPR_BLUD = 16
    SPR_PUFF = 17
    SPR_BAL1 = 18
    SPR_BAL2 = 19
    SPR_PLSS = 20
    SPR_PLSE = 21
    SPR_MISL = 22
    SPR_BFS1 = 23
    SPR_BFE1 = 24
    SPR_BFE2 = 25
    SPR_TFOG = 26
    SPR_IFOG = 27
    SPR_PLAY = 28
    SPR_POSS = 29
    SPR_SPOS = 30
    SPR_VILE = 31
    SPR_FIRE = 32
    SPR_FATB = 33
    SPR_FBXP = 34
    SPR_SKEL = 35
    SPR_MANF = 36
    SPR_FATT = 37
    SPR_CPOS = 38
    SPR_SARG = 39
    SPR_HEAD = 40
    SPR_BAL7 = 41
    SPR_BOSS = 42
    SPR_BOS2 = 43
    SPR_SKUL = 44
    SPR_SPID = 45
    SPR_BSPI = 46
    SPR_APLS = 47
    SPR_APBX = 48
    SPR_CYBR = 49
    SPR_PAIN = 50
    SPR_SSWV = 51
    SPR_KEEN = 52
    SPR_BBRN = 53
    SPR_BOSF = 54
    SPR_ARM1 = 55
    SPR_ARM2 = 56
    SPR_BAR1 = 57
    SPR_BEXP = 58
    SPR_FCAN = 59
    SPR_BON1 = 60
    SPR_BON2 = 61
    SPR_BKEY = 62
    SPR_RKEY = 63
    SPR_YKEY = 64
    SPR_BSKU = 65
    SPR_RSKU = 66
    SPR_YSKU = 67
    SPR_STIM = 68
    SPR_MEDI = 69
    SPR_SOUL = 70
    SPR_PINV = 71
    SPR_PSTR = 72
    SPR_PINS = 73
    SPR_MEGA = 74
    SPR_SUIT = 75
    SPR_PMAP = 76
    SPR_PVIS = 77
    SPR_CLIP = 78
    SPR_AMMO = 79
    SPR_ROCK = 80
    SPR_BROK = 81
    SPR_CELL = 82
    SPR_CELP = 83
    SPR_SHEL = 84
    SPR_SBOX = 85
    SPR_BPAK = 86
    SPR_BFUG = 87
    SPR_MGUN = 88
    SPR_CSAW = 89
    SPR_LAUN = 90
    SPR_PLAS = 91
    SPR_SHOT = 92
    SPR_SGN2 = 93
    SPR_COLU = 94
    SPR_SMT2 = 95
    SPR_GOR1 = 96
    SPR_POL2 = 97
    SPR_POL5 = 98
    SPR_POL4 = 99
    SPR_POL3 = 100
    SPR_POL1 = 101
    SPR_POL6 = 102
    SPR_GOR2 = 103
    SPR_GOR3 = 104
    SPR_GOR4 = 105
    SPR_GOR5 = 106
    SPR_SMIT = 107
    SPR_COL1 = 108
    SPR_COL2 = 109
    SPR_COL3 = 110
    SPR_COL4 = 111
    SPR_CAND = 112
    SPR_CBRA = 113
    SPR_COL6 = 114
    SPR_TRE1 = 115
    SPR_TRE2 = 116
    SPR_ELEC = 117
    SPR_CEYE = 118
    SPR_FSKU = 119
    SPR_COL5 = 120
    SPR_TBLU = 121
    SPR_TGRN = 122
    SPR_TRED = 123
    SPR_SMBT = 124
    SPR_SMGT = 125
    SPR_SMRT = 126
    SPR_HDB1 = 127
    SPR_HDB2 = 128
    SPR_HDB3 = 129
    SPR_HDB4 = 130
    SPR_HDB5 = 131
    SPR_HDB6 = 132
    SPR_POB1 = 133
    SPR_POB2 = 134
    SPR_BRS1 = 135
    SPR_TLMP = 136
    SPR_TLP2 = 137
    NUMSPRITES = 138
}
enum statenum_t : uint {
    S_NULL = 0
    S_LIGHTDONE = 1
    S_PUNCH = 2
    S_PUNCHDOWN = 3
    S_PUNCHUP = 4
    S_PUNCH1 = 5
    S_PUNCH2 = 6
    S_PUNCH3 = 7
    S_PUNCH4 = 8
    S_PUNCH5 = 9
    S_PISTOL = 10
    S_PISTOLDOWN = 11
    S_PISTOLUP = 12
    S_PISTOL1 = 13
    S_PISTOL2 = 14
    S_PISTOL3 = 15
    S_PISTOL4 = 16
    S_PISTOLFLASH = 17
    S_SGUN = 18
    S_SGUNDOWN = 19
    S_SGUNUP = 20
    S_SGUN1 = 21
    S_SGUN2 = 22
    S_SGUN3 = 23
    S_SGUN4 = 24
    S_SGUN5 = 25
    S_SGUN6 = 26
    S_SGUN7 = 27
    S_SGUN8 = 28
    S_SGUN9 = 29
    S_SGUNFLASH1 = 30
    S_SGUNFLASH2 = 31
    S_DSGUN = 32
    S_DSGUNDOWN = 33
    S_DSGUNUP = 34
    S_DSGUN1 = 35
    S_DSGUN2 = 36
    S_DSGUN3 = 37
    S_DSGUN4 = 38
    S_DSGUN5 = 39
    S_DSGUN6 = 40
    S_DSGUN7 = 41
    S_DSGUN8 = 42
    S_DSGUN9 = 43
    S_DSGUN10 = 44
    S_DSNR1 = 45
    S_DSNR2 = 46
    S_DSGUNFLASH1 = 47
    S_DSGUNFLASH2 = 48
    S_CHAIN = 49
    S_CHAINDOWN = 50
    S_CHAINUP = 51
    S_CHAIN1 = 52
    S_CHAIN2 = 53
    S_CHAIN3 = 54
    S_CHAINFLASH1 = 55
    S_CHAINFLASH2 = 56
    S_MISSILE = 57
    S_MISSILEDOWN = 58
    S_MISSILEUP = 59
    S_MISSILE1 = 60
    S_MISSILE2 = 61
    S_MISSILE3 = 62
    S_MISSILEFLASH1 = 63
    S_MISSILEFLASH2 = 64
    S_MISSILEFLASH3 = 65
    S_MISSILEFLASH4 = 66
    S_SAW = 67
    S_SAWB = 68
    S_SAWDOWN = 69
    S_SAWUP = 70
    S_SAW1 = 71
    S_SAW2 = 72
    S_SAW3 = 73
    S_PLASMA = 74
    S_PLASMADOWN = 75
    S_PLASMAUP = 76
    S_PLASMA1 = 77
    S_PLASMA2 = 78
    S_PLASMAFLASH1 = 79
    S_PLASMAFLASH2 = 80
    S_BFG = 81
    S_BFGDOWN = 82
    S_BFGUP = 83
    S_BFG1 = 84
    S_BFG2 = 85
    S_BFG3 = 86
    S_BFG4 = 87
    S_BFGFLASH1 = 88
    S_BFGFLASH2 = 89
    S_BLOOD1 = 90
    S_BLOOD2 = 91
    S_BLOOD3 = 92
    S_PUFF1 = 93
    S_PUFF2 = 94
    S_PUFF3 = 95
    S_PUFF4 = 96
    S_TBALL1 = 97
    S_TBALL2 = 98
    S_TBALLX1 = 99
    S_TBALLX2 = 100
    S_TBALLX3 = 101
    S_RBALL1 = 102
    S_RBALL2 = 103
    S_RBALLX1 = 104
    S_RBALLX2 = 105
    S_RBALLX3 = 106
    S_PLASBALL = 107
    S_PLASBALL2 = 108
    S_PLASEXP = 109
    S_PLASEXP2 = 110
    S_PLASEXP3 = 111
    S_PLASEXP4 = 112
    S_PLASEXP5 = 113
    S_ROCKET = 114
    S_BFGSHOT = 115
    S_BFGSHOT2 = 116
    S_BFGLAND = 117
    S_BFGLAND2 = 118
    S_BFGLAND3 = 119
    S_BFGLAND4 = 120
    S_BFGLAND5 = 121
    S_BFGLAND6 = 122
    S_BFGEXP = 123
    S_BFGEXP2 = 124
    S_BFGEXP3 = 125
    S_BFGEXP4 = 126
    S_EXPLODE1 = 127
    S_EXPLODE2 = 128
    S_EXPLODE3 = 129
    S_TFOG = 130
    S_TFOG01 = 131
    S_TFOG02 = 132
    S_TFOG2 = 133
    S_TFOG3 = 134
    S_TFOG4 = 135
    S_TFOG5 = 136
    S_TFOG6 = 137
    S_TFOG7 = 138
    S_TFOG8 = 139
    S_TFOG9 = 140
    S_TFOG10 = 141
    S_IFOG = 142
    S_IFOG01 = 143
    S_IFOG02 = 144
    S_IFOG2 = 145
    S_IFOG3 = 146
    S_IFOG4 = 147
    S_IFOG5 = 148
    S_PLAY = 149
    S_PLAY_RUN1 = 150
    S_PLAY_RUN2 = 151
    S_PLAY_RUN3 = 152
    S_PLAY_RUN4 = 153
    S_PLAY_ATK1 = 154
    S_PLAY_ATK2 = 155
    S_PLAY_PAIN = 156
    S_PLAY_PAIN2 = 157
    S_PLAY_DIE1 = 158
    S_PLAY_DIE2 = 159
    S_PLAY_DIE3 = 160
    S_PLAY_DIE4 = 161
    S_PLAY_DIE5 = 162
    S_PLAY_DIE6 = 163
    S_PLAY_DIE7 = 164
    S_PLAY_XDIE1 = 165
    S_PLAY_XDIE2 = 166
    S_PLAY_XDIE3 = 167
    S_PLAY_XDIE4 = 168
    S_PLAY_XDIE5 = 169
    S_PLAY_XDIE6 = 170
    S_PLAY_XDIE7 = 171
    S_PLAY_XDIE8 = 172
    S_PLAY_XDIE9 = 173
    S_POSS_STND = 174
    S_POSS_STND2 = 175
    S_POSS_RUN1 = 176
    S_POSS_RUN2 = 177
    S_POSS_RUN3 = 178
    S_POSS_RUN4 = 179
    S_POSS_RUN5 = 180
    S_POSS_RUN6 = 181
    S_POSS_RUN7 = 182
    S_POSS_RUN8 = 183
    S_POSS_ATK1 = 184
    S_POSS_ATK2 = 185
    S_POSS_ATK3 = 186
    S_POSS_PAIN = 187
    S_POSS_PAIN2 = 188
    S_POSS_DIE1 = 189
    S_POSS_DIE2 = 190
    S_POSS_DIE3 = 191
    S_POSS_DIE4 = 192
    S_POSS_DIE5 = 193
    S_POSS_XDIE1 = 194
    S_POSS_XDIE2 = 195
    S_POSS_XDIE3 = 196
    S_POSS_XDIE4 = 197
    S_POSS_XDIE5 = 198
    S_POSS_XDIE6 = 199
    S_POSS_XDIE7 = 200
    S_POSS_XDIE8 = 201
    S_POSS_XDIE9 = 202
    S_POSS_RAISE1 = 203
    S_POSS_RAISE2 = 204
    S_POSS_RAISE3 = 205
    S_POSS_RAISE4 = 206
    S_SPOS_STND = 207
    S_SPOS_STND2 = 208
    S_SPOS_RUN1 = 209
    S_SPOS_RUN2 = 210
    S_SPOS_RUN3 = 211
    S_SPOS_RUN4 = 212
    S_SPOS_RUN5 = 213
    S_SPOS_RUN6 = 214
    S_SPOS_RUN7 = 215
    S_SPOS_RUN8 = 216
    S_SPOS_ATK1 = 217
    S_SPOS_ATK2 = 218
    S_SPOS_ATK3 = 219
    S_SPOS_PAIN = 220
    S_SPOS_PAIN2 = 221
    S_SPOS_DIE1 = 222
    S_SPOS_DIE2 = 223
    S_SPOS_DIE3 = 224
    S_SPOS_DIE4 = 225
    S_SPOS_DIE5 = 226
    S_SPOS_XDIE1 = 227
    S_SPOS_XDIE2 = 228
    S_SPOS_XDIE3 = 229
    S_SPOS_XDIE4 = 230
    S_SPOS_XDIE5 = 231
    S_SPOS_XDIE6 = 232
    S_SPOS_XDIE7 = 233
    S_SPOS_XDIE8 = 234
    S_SPOS_XDIE9 = 235
    S_SPOS_RAISE1 = 236
    S_SPOS_RAISE2 = 237
    S_SPOS_RAISE3 = 238
    S_SPOS_RAISE4 = 239
    S_SPOS_RAISE5 = 240
    S_VILE_STND = 241
    S_VILE_STND2 = 242
    S_VILE_RUN1 = 243
    S_VILE_RUN2 = 244
    S_VILE_RUN3 = 245
    S_VILE_RUN4 = 246
    S_VILE_RUN5 = 247
    S_VILE_RUN6 = 248
    S_VILE_RUN7 = 249
    S_VILE_RUN8 = 250
    S_VILE_RUN9 = 251
    S_VILE_RUN10 = 252
    S_VILE_RUN11 = 253
    S_VILE_RUN12 = 254
    S_VILE_ATK1 = 255
    S_VILE_ATK2 = 256
    S_VILE_ATK3 = 257
    S_VILE_ATK4 = 258
    S_VILE_ATK5 = 259
    S_VILE_ATK6 = 260
    S_VILE_ATK7 = 261
    S_VILE_ATK8 = 262
    S_VILE_ATK9 = 263
    S_VILE_ATK10 = 264
    S_VILE_ATK11 = 265
    S_VILE_HEAL1 = 266
    S_VILE_HEAL2 = 267
    S_VILE_HEAL3 = 268
    S_VILE_PAIN = 269
    S_VILE_PAIN2 = 270
    S_VILE_DIE1 = 271
    S_VILE_DIE2 = 272
    S_VILE_DIE3 = 273
    S_VILE_DIE4 = 274
    S_VILE_DIE5 = 275
    S_VILE_DIE6 = 276
    S_VILE_DIE7 = 277
    S_VILE_DIE8 = 278
    S_VILE_DIE9 = 279
    S_VILE_DIE10 = 280
    S_FIRE1 = 281
    S_FIRE2 = 282
    S_FIRE3 = 283
    S_FIRE4 = 284
    S_FIRE5 = 285
    S_FIRE6 = 286
    S_FIRE7 = 287
    S_FIRE8 = 288
    S_FIRE9 = 289
    S_FIRE10 = 290
    S_FIRE11 = 291
    S_FIRE12 = 292
    S_FIRE13 = 293
    S_FIRE14 = 294
    S_FIRE15 = 295
    S_FIRE16 = 296
    S_FIRE17 = 297
    S_FIRE18 = 298
    S_FIRE19 = 299
    S_FIRE20 = 300
    S_FIRE21 = 301
    S_FIRE22 = 302
    S_FIRE23 = 303
    S_FIRE24 = 304
    S_FIRE25 = 305
    S_FIRE26 = 306
    S_FIRE27 = 307
    S_FIRE28 = 308
    S_FIRE29 = 309
    S_FIRE30 = 310
    S_SMOKE1 = 311
    S_SMOKE2 = 312
    S_SMOKE3 = 313
    S_SMOKE4 = 314
    S_SMOKE5 = 315
    S_TRACER = 316
    S_TRACER2 = 317
    S_TRACEEXP1 = 318
    S_TRACEEXP2 = 319
    S_TRACEEXP3 = 320
    S_SKEL_STND = 321
    S_SKEL_STND2 = 322
    S_SKEL_RUN1 = 323
    S_SKEL_RUN2 = 324
    S_SKEL_RUN3 = 325
    S_SKEL_RUN4 = 326
    S_SKEL_RUN5 = 327
    S_SKEL_RUN6 = 328
    S_SKEL_RUN7 = 329
    S_SKEL_RUN8 = 330
    S_SKEL_RUN9 = 331
    S_SKEL_RUN10 = 332
    S_SKEL_RUN11 = 333
    S_SKEL_RUN12 = 334
    S_SKEL_FIST1 = 335
    S_SKEL_FIST2 = 336
    S_SKEL_FIST3 = 337
    S_SKEL_FIST4 = 338
    S_SKEL_MISS1 = 339
    S_SKEL_MISS2 = 340
    S_SKEL_MISS3 = 341
    S_SKEL_MISS4 = 342
    S_SKEL_PAIN = 343
    S_SKEL_PAIN2 = 344
    S_SKEL_DIE1 = 345
    S_SKEL_DIE2 = 346
    S_SKEL_DIE3 = 347
    S_SKEL_DIE4 = 348
    S_SKEL_DIE5 = 349
    S_SKEL_DIE6 = 350
    S_SKEL_RAISE1 = 351
    S_SKEL_RAISE2 = 352
    S_SKEL_RAISE3 = 353
    S_SKEL_RAISE4 = 354
    S_SKEL_RAISE5 = 355
    S_SKEL_RAISE6 = 356
    S_FATSHOT1 = 357
    S_FATSHOT2 = 358
    S_FATSHOTX1 = 359
    S_FATSHOTX2 = 360
    S_FATSHOTX3 = 361
    S_FATT_STND = 362
    S_FATT_STND2 = 363
    S_FATT_RUN1 = 364
    S_FATT_RUN2 = 365
    S_FATT_RUN3 = 366
    S_FATT_RUN4 = 367
    S_FATT_RUN5 = 368
    S_FATT_RUN6 = 369
    S_FATT_RUN7 = 370
    S_FATT_RUN8 = 371
    S_FATT_RUN9 = 372
    S_FATT_RUN10 = 373
    S_FATT_RUN11 = 374
    S_FATT_RUN12 = 375
    S_FATT_ATK1 = 376
    S_FATT_ATK2 = 377
    S_FATT_ATK3 = 378
    S_FATT_ATK4 = 379
    S_FATT_ATK5 = 380
    S_FATT_ATK6 = 381
    S_FATT_ATK7 = 382
    S_FATT_ATK8 = 383
    S_FATT_ATK9 = 384
    S_FATT_ATK10 = 385
    S_FATT_PAIN = 386
    S_FATT_PAIN2 = 387
    S_FATT_DIE1 = 388
    S_FATT_DIE2 = 389
    S_FATT_DIE3 = 390
    S_FATT_DIE4 = 391
    S_FATT_DIE5 = 392
    S_FATT_DIE6 = 393
    S_FATT_DIE7 = 394
    S_FATT_DIE8 = 395
    S_FATT_DIE9 = 396
    S_FATT_DIE10 = 397
    S_FATT_RAISE1 = 398
    S_FATT_RAISE2 = 399
    S_FATT_RAISE3 = 400
    S_FATT_RAISE4 = 401
    S_FATT_RAISE5 = 402
    S_FATT_RAISE6 = 403
    S_FATT_RAISE7 = 404
    S_FATT_RAISE8 = 405
    S_CPOS_STND = 406
    S_CPOS_STND2 = 407
    S_CPOS_RUN1 = 408
    S_CPOS_RUN2 = 409
    S_CPOS_RUN3 = 410
    S_CPOS_RUN4 = 411
    S_CPOS_RUN5 = 412
    S_CPOS_RUN6 = 413
    S_CPOS_RUN7 = 414
    S_CPOS_RUN8 = 415
    S_CPOS_ATK1 = 416
    S_CPOS_ATK2 = 417
    S_CPOS_ATK3 = 418
    S_CPOS_ATK4 = 419
    S_CPOS_PAIN = 420
    S_CPOS_PAIN2 = 421
    S_CPOS_DIE1 = 422
    S_CPOS_DIE2 = 423
    S_CPOS_DIE3 = 424
    S_CPOS_DIE4 = 425
    S_CPOS_DIE5 = 426
    S_CPOS_DIE6 = 427
    S_CPOS_DIE7 = 428
    S_CPOS_XDIE1 = 429
    S_CPOS_XDIE2 = 430
    S_CPOS_XDIE3 = 431
    S_CPOS_XDIE4 = 432
    S_CPOS_XDIE5 = 433
    S_CPOS_XDIE6 = 434
    S_CPOS_RAISE1 = 435
    S_CPOS_RAISE2 = 436
    S_CPOS_RAISE3 = 437
    S_CPOS_RAISE4 = 438
    S_CPOS_RAISE5 = 439
    S_CPOS_RAISE6 = 440
    S_CPOS_RAISE7 = 441
    S_TROO_STND = 442
    S_TROO_STND2 = 443
    S_TROO_RUN1 = 444
    S_TROO_RUN2 = 445
    S_TROO_RUN3 = 446
    S_TROO_RUN4 = 447
    S_TROO_RUN5 = 448
    S_TROO_RUN6 = 449
    S_TROO_RUN7 = 450
    S_TROO_RUN8 = 451
    S_TROO_ATK1 = 452
    S_TROO_ATK2 = 453
    S_TROO_ATK3 = 454
    S_TROO_PAIN = 455
    S_TROO_PAIN2 = 456
    S_TROO_DIE1 = 457
    S_TROO_DIE2 = 458
    S_TROO_DIE3 = 459
    S_TROO_DIE4 = 460
    S_TROO_DIE5 = 461
    S_TROO_XDIE1 = 462
    S_TROO_XDIE2 = 463
    S_TROO_XDIE3 = 464
    S_TROO_XDIE4 = 465
    S_TROO_XDIE5 = 466
    S_TROO_XDIE6 = 467
    S_TROO_XDIE7 = 468
    S_TROO_XDIE8 = 469
    S_TROO_RAISE1 = 470
    S_TROO_RAISE2 = 471
    S_TROO_RAISE3 = 472
    S_TROO_RAISE4 = 473
    S_TROO_RAISE5 = 474
    S_SARG_STND = 475
    S_SARG_STND2 = 476
    S_SARG_RUN1 = 477
    S_SARG_RUN2 = 478
    S_SARG_RUN3 = 479
    S_SARG_RUN4 = 480
    S_SARG_RUN5 = 481
    S_SARG_RUN6 = 482
    S_SARG_RUN7 = 483
    S_SARG_RUN8 = 484
    S_SARG_ATK1 = 485
    S_SARG_ATK2 = 486
    S_SARG_ATK3 = 487
    S_SARG_PAIN = 488
    S_SARG_PAIN2 = 489
    S_SARG_DIE1 = 490
    S_SARG_DIE2 = 491
    S_SARG_DIE3 = 492
    S_SARG_DIE4 = 493
    S_SARG_DIE5 = 494
    S_SARG_DIE6 = 495
    S_SARG_RAISE1 = 496
    S_SARG_RAISE2 = 497
    S_SARG_RAISE3 = 498
    S_SARG_RAISE4 = 499
    S_SARG_RAISE5 = 500
    S_SARG_RAISE6 = 501
    S_HEAD_STND = 502
    S_HEAD_RUN1 = 503
    S_HEAD_ATK1 = 504
    S_HEAD_ATK2 = 505
    S_HEAD_ATK3 = 506
    S_HEAD_PAIN = 507
    S_HEAD_PAIN2 = 508
    S_HEAD_PAIN3 = 509
    S_HEAD_DIE1 = 510
    S_HEAD_DIE2 = 511
    S_HEAD_DIE3 = 512
    S_HEAD_DIE4 = 513
    S_HEAD_DIE5 = 514
    S_HEAD_DIE6 = 515
    S_HEAD_RAISE1 = 516
    S_HEAD_RAISE2 = 517
    S_HEAD_RAISE3 = 518
    S_HEAD_RAISE4 = 519
    S_HEAD_RAISE5 = 520
    S_HEAD_RAISE6 = 521
    S_BRBALL1 = 522
    S_BRBALL2 = 523
    S_BRBALLX1 = 524
    S_BRBALLX2 = 525
    S_BRBALLX3 = 526
    S_BOSS_STND = 527
    S_BOSS_STND2 = 528
    S_BOSS_RUN1 = 529
    S_BOSS_RUN2 = 530
    S_BOSS_RUN3 = 531
    S_BOSS_RUN4 = 532
    S_BOSS_RUN5 = 533
    S_BOSS_RUN6 = 534
    S_BOSS_RUN7 = 535
    S_BOSS_RUN8 = 536
    S_BOSS_ATK1 = 537
    S_BOSS_ATK2 = 538
    S_BOSS_ATK3 = 539
    S_BOSS_PAIN = 540
    S_BOSS_PAIN2 = 541
    S_BOSS_DIE1 = 542
    S_BOSS_DIE2 = 543
    S_BOSS_DIE3 = 544
    S_BOSS_DIE4 = 545
    S_BOSS_DIE5 = 546
    S_BOSS_DIE6 = 547
    S_BOSS_DIE7 = 548
    S_BOSS_RAISE1 = 549
    S_BOSS_RAISE2 = 550
    S_BOSS_RAISE3 = 551
    S_BOSS_RAISE4 = 552
    S_BOSS_RAISE5 = 553
    S_BOSS_RAISE6 = 554
    S_BOSS_RAISE7 = 555
    S_BOS2_STND = 556
    S_BOS2_STND2 = 557
    S_BOS2_RUN1 = 558
    S_BOS2_RUN2 = 559
    S_BOS2_RUN3 = 560
    S_BOS2_RUN4 = 561
    S_BOS2_RUN5 = 562
    S_BOS2_RUN6 = 563
    S_BOS2_RUN7 = 564
    S_BOS2_RUN8 = 565
    S_BOS2_ATK1 = 566
    S_BOS2_ATK2 = 567
    S_BOS2_ATK3 = 568
    S_BOS2_PAIN = 569
    S_BOS2_PAIN2 = 570
    S_BOS2_DIE1 = 571
    S_BOS2_DIE2 = 572
    S_BOS2_DIE3 = 573
    S_BOS2_DIE4 = 574
    S_BOS2_DIE5 = 575
    S_BOS2_DIE6 = 576
    S_BOS2_DIE7 = 577
    S_BOS2_RAISE1 = 578
    S_BOS2_RAISE2 = 579
    S_BOS2_RAISE3 = 580
    S_BOS2_RAISE4 = 581
    S_BOS2_RAISE5 = 582
    S_BOS2_RAISE6 = 583
    S_BOS2_RAISE7 = 584
    S_SKULL_STND = 585
    S_SKULL_STND2 = 586
    S_SKULL_RUN1 = 587
    S_SKULL_RUN2 = 588
    S_SKULL_ATK1 = 589
    S_SKULL_ATK2 = 590
    S_SKULL_ATK3 = 591
    S_SKULL_ATK4 = 592
    S_SKULL_PAIN = 593
    S_SKULL_PAIN2 = 594
    S_SKULL_DIE1 = 595
    S_SKULL_DIE2 = 596
    S_SKULL_DIE3 = 597
    S_SKULL_DIE4 = 598
    S_SKULL_DIE5 = 599
    S_SKULL_DIE6 = 600
    S_SPID_STND = 601
    S_SPID_STND2 = 602
    S_SPID_RUN1 = 603
    S_SPID_RUN2 = 604
    S_SPID_RUN3 = 605
    S_SPID_RUN4 = 606
    S_SPID_RUN5 = 607
    S_SPID_RUN6 = 608
    S_SPID_RUN7 = 609
    S_SPID_RUN8 = 610
    S_SPID_RUN9 = 611
    S_SPID_RUN10 = 612
    S_SPID_RUN11 = 613
    S_SPID_RUN12 = 614
    S_SPID_ATK1 = 615
    S_SPID_ATK2 = 616
    S_SPID_ATK3 = 617
    S_SPID_ATK4 = 618
    S_SPID_PAIN = 619
    S_SPID_PAIN2 = 620
    S_SPID_DIE1 = 621
    S_SPID_DIE2 = 622
    S_SPID_DIE3 = 623
    S_SPID_DIE4 = 624
    S_SPID_DIE5 = 625
    S_SPID_DIE6 = 626
    S_SPID_DIE7 = 627
    S_SPID_DIE8 = 628
    S_SPID_DIE9 = 629
    S_SPID_DIE10 = 630
    S_SPID_DIE11 = 631
    S_BSPI_STND = 632
    S_BSPI_STND2 = 633
    S_BSPI_SIGHT = 634
    S_BSPI_RUN1 = 635
    S_BSPI_RUN2 = 636
    S_BSPI_RUN3 = 637
    S_BSPI_RUN4 = 638
    S_BSPI_RUN5 = 639
    S_BSPI_RUN6 = 640
    S_BSPI_RUN7 = 641
    S_BSPI_RUN8 = 642
    S_BSPI_RUN9 = 643
    S_BSPI_RUN10 = 644
    S_BSPI_RUN11 = 645
    S_BSPI_RUN12 = 646
    S_BSPI_ATK1 = 647
    S_BSPI_ATK2 = 648
    S_BSPI_ATK3 = 649
    S_BSPI_ATK4 = 650
    S_BSPI_PAIN = 651
    S_BSPI_PAIN2 = 652
    S_BSPI_DIE1 = 653
    S_BSPI_DIE2 = 654
    S_BSPI_DIE3 = 655
    S_BSPI_DIE4 = 656
    S_BSPI_DIE5 = 657
    S_BSPI_DIE6 = 658
    S_BSPI_DIE7 = 659
    S_BSPI_RAISE1 = 660
    S_BSPI_RAISE2 = 661
    S_BSPI_RAISE3 = 662
    S_BSPI_RAISE4 = 663
    S_BSPI_RAISE5 = 664
    S_BSPI_RAISE6 = 665
    S_BSPI_RAISE7 = 666
    S_ARACH_PLAZ = 667
    S_ARACH_PLAZ2 = 668
    S_ARACH_PLEX = 669
    S_ARACH_PLEX2 = 670
    S_ARACH_PLEX3 = 671
    S_ARACH_PLEX4 = 672
    S_ARACH_PLEX5 = 673
    S_CYBER_STND = 674
    S_CYBER_STND2 = 675
    S_CYBER_RUN1 = 676
    S_CYBER_RUN2 = 677
    S_CYBER_RUN3 = 678
    S_CYBER_RUN4 = 679
    S_CYBER_RUN5 = 680
    S_CYBER_RUN6 = 681
    S_CYBER_RUN7 = 682
    S_CYBER_RUN8 = 683
    S_CYBER_ATK1 = 684
    S_CYBER_ATK2 = 685
    S_CYBER_ATK3 = 686
    S_CYBER_ATK4 = 687
    S_CYBER_ATK5 = 688
    S_CYBER_ATK6 = 689
    S_CYBER_PAIN = 690
    S_CYBER_DIE1 = 691
    S_CYBER_DIE2 = 692
    S_CYBER_DIE3 = 693
    S_CYBER_DIE4 = 694
    S_CYBER_DIE5 = 695
    S_CYBER_DIE6 = 696
    S_CYBER_DIE7 = 697
    S_CYBER_DIE8 = 698
    S_CYBER_DIE9 = 699
    S_CYBER_DIE10 = 700
    S_PAIN_STND = 701
    S_PAIN_RUN1 = 702
    S_PAIN_RUN2 = 703
    S_PAIN_RUN3 = 704
    S_PAIN_RUN4 = 705
    S_PAIN_RUN5 = 706
    S_PAIN_RUN6 = 707
    S_PAIN_ATK1 = 708
    S_PAIN_ATK2 = 709
    S_PAIN_ATK3 = 710
    S_PAIN_ATK4 = 711
    S_PAIN_PAIN = 712
    S_PAIN_PAIN2 = 713
    S_PAIN_DIE1 = 714
    S_PAIN_DIE2 = 715
    S_PAIN_DIE3 = 716
    S_PAIN_DIE4 = 717
    S_PAIN_DIE5 = 718
    S_PAIN_DIE6 = 719
    S_PAIN_RAISE1 = 720
    S_PAIN_RAISE2 = 721
    S_PAIN_RAISE3 = 722
    S_PAIN_RAISE4 = 723
    S_PAIN_RAISE5 = 724
    S_PAIN_RAISE6 = 725
    S_SSWV_STND = 726
    S_SSWV_STND2 = 727
    S_SSWV_RUN1 = 728
    S_SSWV_RUN2 = 729
    S_SSWV_RUN3 = 730
    S_SSWV_RUN4 = 731
    S_SSWV_RUN5 = 732
    S_SSWV_RUN6 = 733
    S_SSWV_RUN7 = 734
    S_SSWV_RUN8 = 735
    S_SSWV_ATK1 = 736
    S_SSWV_ATK2 = 737
    S_SSWV_ATK3 = 738
    S_SSWV_ATK4 = 739
    S_SSWV_ATK5 = 740
    S_SSWV_ATK6 = 741
    S_SSWV_PAIN = 742
    S_SSWV_PAIN2 = 743
    S_SSWV_DIE1 = 744
    S_SSWV_DIE2 = 745
    S_SSWV_DIE3 = 746
    S_SSWV_DIE4 = 747
    S_SSWV_DIE5 = 748
    S_SSWV_XDIE1 = 749
    S_SSWV_XDIE2 = 750
    S_SSWV_XDIE3 = 751
    S_SSWV_XDIE4 = 752
    S_SSWV_XDIE5 = 753
    S_SSWV_XDIE6 = 754
    S_SSWV_XDIE7 = 755
    S_SSWV_XDIE8 = 756
    S_SSWV_XDIE9 = 757
    S_SSWV_RAISE1 = 758
    S_SSWV_RAISE2 = 759
    S_SSWV_RAISE3 = 760
    S_SSWV_RAISE4 = 761
    S_SSWV_RAISE5 = 762
    S_KEENSTND = 763
    S_COMMKEEN = 764
    S_COMMKEEN2 = 765
    S_COMMKEEN3 = 766
    S_COMMKEEN4 = 767
    S_COMMKEEN5 = 768
    S_COMMKEEN6 = 769
    S_COMMKEEN7 = 770
    S_COMMKEEN8 = 771
    S_COMMKEEN9 = 772
    S_COMMKEEN10 = 773
    S_COMMKEEN11 = 774
    S_COMMKEEN12 = 775
    S_KEENPAIN = 776
    S_KEENPAIN2 = 777
    S_BRAIN = 778
    S_BRAIN_PAIN = 779
    S_BRAIN_DIE1 = 780
    S_BRAIN_DIE2 = 781
    S_BRAIN_DIE3 = 782
    S_BRAIN_DIE4 = 783
    S_BRAINEYE = 784
    S_BRAINEYESEE = 785
    S_BRAINEYE1 = 786
    S_SPAWN1 = 787
    S_SPAWN2 = 788
    S_SPAWN3 = 789
    S_SPAWN4 = 790
    S_SPAWNFIRE1 = 791
    S_SPAWNFIRE2 = 792
    S_SPAWNFIRE3 = 793
    S_SPAWNFIRE4 = 794
    S_SPAWNFIRE5 = 795
    S_SPAWNFIRE6 = 796
    S_SPAWNFIRE7 = 797
    S_SPAWNFIRE8 = 798
    S_BRAINEXPLODE1 = 799
    S_BRAINEXPLODE2 = 800
    S_BRAINEXPLODE3 = 801
    S_ARM1 = 802
    S_ARM1A = 803
    S_ARM2 = 804
    S_ARM2A = 805
    S_BAR1 = 806
    S_BAR2 = 807
    S_BEXP = 808
    S_BEXP2 = 809
    S_BEXP3 = 810
    S_BEXP4 = 811
    S_BEXP5 = 812
    S_BBAR1 = 813
    S_BBAR2 = 814
    S_BBAR3 = 815
    S_BON1 = 816
    S_BON1A = 817
    S_BON1B = 818
    S_BON1C = 819
    S_BON1D = 820
    S_BON1E = 821
    S_BON2 = 822
    S_BON2A = 823
    S_BON2B = 824
    S_BON2C = 825
    S_BON2D = 826
    S_BON2E = 827
    S_BKEY = 828
    S_BKEY2 = 829
    S_RKEY = 830
    S_RKEY2 = 831
    S_YKEY = 832
    S_YKEY2 = 833
    S_BSKULL = 834
    S_BSKULL2 = 835
    S_RSKULL = 836
    S_RSKULL2 = 837
    S_YSKULL = 838
    S_YSKULL2 = 839
    S_STIM = 840
    S_MEDI = 841
    S_SOUL = 842
    S_SOUL2 = 843
    S_SOUL3 = 844
    S_SOUL4 = 845
    S_SOUL5 = 846
    S_SOUL6 = 847
    S_PINV = 848
    S_PINV2 = 849
    S_PINV3 = 850
    S_PINV4 = 851
    S_PSTR = 852
    S_PINS = 853
    S_PINS2 = 854
    S_PINS3 = 855
    S_PINS4 = 856
    S_MEGA = 857
    S_MEGA2 = 858
    S_MEGA3 = 859
    S_MEGA4 = 860
    S_SUIT = 861
    S_PMAP = 862
    S_PMAP2 = 863
    S_PMAP3 = 864
    S_PMAP4 = 865
    S_PMAP5 = 866
    S_PMAP6 = 867
    S_PVIS = 868
    S_PVIS2 = 869
    S_CLIP = 870
    S_AMMO = 871
    S_ROCK = 872
    S_BROK = 873
    S_CELL = 874
    S_CELP = 875
    S_SHEL = 876
    S_SBOX = 877
    S_BPAK = 878
    S_BFUG = 879
    S_MGUN = 880
    S_CSAW = 881
    S_LAUN = 882
    S_PLAS = 883
    S_SHOT = 884
    S_SHOT2 = 885
    S_COLU = 886
    S_STALAG = 887
    S_BLOODYTWITCH = 888
    S_BLOODYTWITCH2 = 889
    S_BLOODYTWITCH3 = 890
    S_BLOODYTWITCH4 = 891
    S_DEADTORSO = 892
    S_DEADBOTTOM = 893
    S_HEADSONSTICK = 894
    S_GIBS = 895
    S_HEADONASTICK = 896
    S_HEADCANDLES = 897
    S_HEADCANDLES2 = 898
    S_DEADSTICK = 899
    S_LIVESTICK = 900
    S_LIVESTICK2 = 901
    S_MEAT2 = 902
    S_MEAT3 = 903
    S_MEAT4 = 904
    S_MEAT5 = 905
    S_STALAGTITE = 906
    S_TALLGRNCOL = 907
    S_SHRTGRNCOL = 908
    S_TALLREDCOL = 909
    S_SHRTREDCOL = 910
    S_CANDLESTIK = 911
    S_CANDELABRA = 912
    S_SKULLCOL = 913
    S_TORCHTREE = 914
    S_BIGTREE = 915
    S_TECHPILLAR = 916
    S_EVILEYE = 917
    S_EVILEYE2 = 918
    S_EVILEYE3 = 919
    S_EVILEYE4 = 920
    S_FLOATSKULL = 921
    S_FLOATSKULL2 = 922
    S_FLOATSKULL3 = 923
    S_HEARTCOL = 924
    S_HEARTCOL2 = 925
    S_BLUETORCH = 926
    S_BLUETORCH2 = 927
    S_BLUETORCH3 = 928
    S_BLUETORCH4 = 929
    S_GREENTORCH = 930
    S_GREENTORCH2 = 931
    S_GREENTORCH3 = 932
    S_GREENTORCH4 = 933
    S_REDTORCH = 934
    S_REDTORCH2 = 935
    S_REDTORCH3 = 936
    S_REDTORCH4 = 937
    S_BTORCHSHRT = 938
    S_BTORCHSHRT2 = 939
    S_BTORCHSHRT3 = 940
    S_BTORCHSHRT4 = 941
    S_GTORCHSHRT = 942
    S_GTORCHSHRT2 = 943
    S_GTORCHSHRT3 = 944
    S_GTORCHSHRT4 = 945
    S_RTORCHSHRT = 946
    S_RTORCHSHRT2 = 947
    S_RTORCHSHRT3 = 948
    S_RTORCHSHRT4 = 949
    S_HANGNOGUTS = 950
    S_HANGBNOBRAIN = 951
    S_HANGTLOOKDN = 952
    S_HANGTSKULL = 953
    S_HANGTLOOKUP = 954
    S_HANGTNOBRAIN = 955
    S_COLONGIBS = 956
    S_SMALLPOOL = 957
    S_BRAINSTEM = 958
    S_TECHLAMP = 959
    S_TECHLAMP2 = 960
    S_TECHLAMP3 = 961
    S_TECHLAMP4 = 962
    S_TECH2LAMP = 963
    S_TECH2LAMP2 = 964
    S_TECH2LAMP3 = 965
    S_TECH2LAMP4 = 966
    NUMSTATES = 967
}
struct state_t {
    sprite : spritenum_t
    frame : int
    tics : int
    action : uint64
    nextstate : statenum_t
    misc1 : int
    misc2 : int
}
enum mobjtype_t : uint {
    MT_PLAYER = 0
    MT_POSSESSED = 1
    MT_SHOTGUY = 2
    MT_VILE = 3
    MT_FIRE = 4
    MT_UNDEAD = 5
    MT_TRACER = 6
    MT_SMOKE = 7
    MT_FATSO = 8
    MT_FATSHOT = 9
    MT_CHAINGUY = 10
    MT_TROOP = 11
    MT_SERGEANT = 12
    MT_SHADOWS = 13
    MT_HEAD = 14
    MT_BRUISER = 15
    MT_BRUISERSHOT = 16
    MT_KNIGHT = 17
    MT_SKULL = 18
    MT_SPIDER = 19
    MT_BABY = 20
    MT_CYBORG = 21
    MT_PAIN = 22
    MT_WOLFSS = 23
    MT_KEEN = 24
    MT_BOSSBRAIN = 25
    MT_BOSSSPIT = 26
    MT_BOSSTARGET = 27
    MT_SPAWNSHOT = 28
    MT_SPAWNFIRE = 29
    MT_BARREL = 30
    MT_TROOPSHOT = 31
    MT_HEADSHOT = 32
    MT_ROCKET = 33
    MT_PLASMA = 34
    MT_BFG = 35
    MT_ARACHPLAZ = 36
    MT_PUFF = 37
    MT_BLOOD = 38
    MT_TFOG = 39
    MT_IFOG = 40
    MT_TELEPORTMAN = 41
    MT_EXTRABFG = 42
    MT_MISC0 = 43
    MT_MISC1 = 44
    MT_MISC2 = 45
    MT_MISC3 = 46
    MT_MISC4 = 47
    MT_MISC5 = 48
    MT_MISC6 = 49
    MT_MISC7 = 50
    MT_MISC8 = 51
    MT_MISC9 = 52
    MT_MISC10 = 53
    MT_MISC11 = 54
    MT_MISC12 = 55
    MT_INV = 56
    MT_MISC13 = 57
    MT_INS = 58
    MT_MISC14 = 59
    MT_MISC15 = 60
    MT_MISC16 = 61
    MT_MEGA = 62
    MT_CLIP = 63
    MT_MISC17 = 64
    MT_MISC18 = 65
    MT_MISC19 = 66
    MT_MISC20 = 67
    MT_MISC21 = 68
    MT_MISC22 = 69
    MT_MISC23 = 70
    MT_MISC24 = 71
    MT_MISC25 = 72
    MT_CHAINGUN = 73
    MT_MISC26 = 74
    MT_MISC27 = 75
    MT_MISC28 = 76
    MT_SHOTGUN = 77
    MT_SUPERSHOTGUN = 78
    MT_MISC29 = 79
    MT_MISC30 = 80
    MT_MISC31 = 81
    MT_MISC32 = 82
    MT_MISC33 = 83
    MT_MISC34 = 84
    MT_MISC35 = 85
    MT_MISC36 = 86
    MT_MISC37 = 87
    MT_MISC38 = 88
    MT_MISC39 = 89
    MT_MISC40 = 90
    MT_MISC41 = 91
    MT_MISC42 = 92
    MT_MISC43 = 93
    MT_MISC44 = 94
    MT_MISC45 = 95
    MT_MISC46 = 96
    MT_MISC47 = 97
    MT_MISC48 = 98
    MT_MISC49 = 99
    MT_MISC50 = 100
    MT_MISC51 = 101
    MT_MISC52 = 102
    MT_MISC53 = 103
    MT_MISC54 = 104
    MT_MISC55 = 105
    MT_MISC56 = 106
    MT_MISC57 = 107
    MT_MISC58 = 108
    MT_MISC59 = 109
    MT_MISC60 = 110
    MT_MISC61 = 111
    MT_MISC62 = 112
    MT_MISC63 = 113
    MT_MISC64 = 114
    MT_MISC65 = 115
    MT_MISC66 = 116
    MT_MISC67 = 117
    MT_MISC68 = 118
    MT_MISC69 = 119
    MT_MISC70 = 120
    MT_MISC71 = 121
    MT_MISC72 = 122
    MT_MISC73 = 123
    MT_MISC74 = 124
    MT_MISC75 = 125
    MT_MISC76 = 126
    MT_MISC77 = 127
    MT_MISC78 = 128
    MT_MISC79 = 129
    MT_MISC80 = 130
    MT_MISC81 = 131
    MT_MISC82 = 132
    MT_MISC83 = 133
    MT_MISC84 = 134
    MT_MISC85 = 135
    MT_MISC86 = 136
    NUMMOBJTYPES = 137
}
struct mobjinfo_t {
    doomednum : int
    spawnstate : int
    spawnhealth : int
    seestate : int
    seesound : int
    reactiontime : int
    attacksound : int
    painstate : int
    painchance : int
    painsound : int
    meleestate : int
    missilestate : int
    deathstate : int
    xdeathstate : int
    deathsound : int
    speed : int
    radius : int
    height : int
    mass : int
    damage : int
    activesound : int
    flags : int
    raisestate : int
}
struct mobj_s {
    thinker : thinker_s
    x : int
    y : int
    z : int
    snext : mobj_s?
    sprev : mobj_s?
    angle : uint
    sprite : spritenum_t
    frame : int
    bnext : mobj_s?
    bprev : mobj_s?
    subsector : subsector_s?
    floorz : int
    ceilingz : int
    radius : int
    height : int
    momx : int
    momy : int
    momz : int
    validcount : int
    type_0 : mobjtype_t
    info : mobjinfo_t?
    tics : int
    state : state_t?
    flags : int
    health : int
    movedir : int
    movecount : int
    target : mobj_s?
    reactiontime : int
    threshold : int
    player : player_s?
    lastlook : int
    spawnpoint : uint8[10]
    tracer : mobj_s?
}
struct pspdef_t {
    state : state_t?
    tics : int
    sx : int
    sy : int
}
struct ticcmd_t {
    forwardmove : int8
    sidemove : int8
    angleturn : int16
    chatchar : uint8
    buttons : uint8
    consistancy : uint8
    buttons2 : uint8
    inventory : int
    lookfly : uint8
    arti : uint8
}
enum playerstate_t : uint {
    PST_LIVE = 0
    PST_DEAD = 1
    PST_REBORN = 2
}
struct player_s {
    mo : mobj_s?
    playerstate : playerstate_t
    cmd : ticcmd_t
    viewz : int
    viewheight : int
    deltaviewheight : int
    bob : int
    health : int
    armorpoints : int
    armortype : int
    powers : int[6]
    cards : uint[6]
    backpack : uint
    frags : int[4]
    readyweapon : weapontype_t
    pendingweapon : weapontype_t
    weaponowned : uint[9]
    ammo : int[4]
    maxammo : int[4]
    attackdown : int
    usedown : int
    cheats : int
    refire : int
    killcount : int
    itemcount : int
    secretcount : int
    message : int8?
    damagecount : int
    bonuscount : int
    attacker : mobj_s?
    extralight : int
    fixedcolormap : int
    colormap : int
    psprites : pspdef_t[2]
    didsecret : uint
}
struct mobj_t {
    thinker : thinker_s
    x : int
    y : int
    z : int
    snext : mobj_s?
    sprev : mobj_s?
    angle : uint
    sprite : spritenum_t
    frame : int
    bnext : mobj_s?
    bprev : mobj_s?
    subsector : subsector_s?
    floorz : int
    ceilingz : int
    radius : int
    height : int
    momx : int
    momy : int
    momz : int
    validcount : int
    type_0 : mobjtype_t
    info : mobjinfo_t?
    tics : int
    state : state_t?
    flags : int
    health : int
    movedir : int
    movecount : int
    target : mobj_s?
    reactiontime : int
    threshold : int
    player : player_s?
    lastlook : int
    spawnpoint : uint8[10]
    tracer : mobj_s?
}
struct subsector_s {
    sector : sector_t?
    numlines : int16
    firstline : int16
}
struct degenmobj_t {
    thinker : thinker_s
    x : int
    y : int
    z : int
}
struct sector_t {
    floorheight : int
    ceilingheight : int
    floorpic : int16
    ceilingpic : int16
    lightlevel : int16
    special : int16
    tag : int16
    soundtraversed : int
    soundtarget : mobj_s?
    blockbox : int[4]
    soundorg : degenmobj_t
    validcount : int
    thinglist : mobj_s?
    specialdata : uint8?
    linecount : int
    lines : line_s??
}
enum slopetype_t : uint {
    ST_HORIZONTAL = 0
    ST_VERTICAL = 1
    ST_POSITIVE = 2
    ST_NEGATIVE = 3
}
struct line_s {
    v1 : vertex_t?
    v2 : vertex_t?
    dx : int
    dy : int
    flags : int16
    special : int16
    tag : int16
    sidenum : int16[2]
    bbox : int[4]
    slopetype : slopetype_t
    frontsector : sector_t?
    backsector : sector_t?
    validcount : int
    specialdata : uint8?
}
struct vertex_t {
    x : int
    y : int
}
struct patch_t {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 40ul)
}
struct line_t {
    v1 : vertex_t?
    v2 : vertex_t?
    dx : int
    dy : int
    flags : int16
    special : int16
    tag : int16
    sidenum : int16[2]
    bbox : int[4]
    slopetype : slopetype_t
    frontsector : sector_t?
    backsector : sector_t?
    validcount : int
    specialdata : uint8?
}
struct player_t {
    mo : mobj_s?
    playerstate : playerstate_t
    cmd : ticcmd_t
    viewz : int
    viewheight : int
    deltaviewheight : int
    bob : int
    health : int
    armorpoints : int
    armortype : int
    powers : int[6]
    cards : uint[6]
    backpack : uint
    frags : int[4]
    readyweapon : weapontype_t
    pendingweapon : weapontype_t
    weaponowned : uint[9]
    ammo : int[4]
    maxammo : int[4]
    attackdown : int
    usedown : int
    cheats : int
    refire : int
    killcount : int
    itemcount : int
    secretcount : int
    message : int8?
    damagecount : int
    bonuscount : int
    attacker : mobj_s?
    extralight : int
    fixedcolormap : int
    colormap : int
    psprites : pspdef_t[2]
    didsecret : uint
}
struct mpoint_t {
    x : int
    y : int
}
struct mline_t {
    a : mpoint_t
    b : mpoint_t
}
struct fpoint_t {
    x : int
    y : int
}
struct fline_t {
    a : fpoint_t
    b : fpoint_t
}
struct islope_t {
    slp : int
    islp : int
}
enum GameMission_t : uint {
    doom = 0
    doom2 = 1
    pack_tnt = 2
    pack_plut = 3
    pack_chex = 4
    pack_hacx = 5
    heretic = 6
    hexen = 7
    strife = 8
    none_0 = 9
}
enum GameMode_t : uint {
    shareware = 0
    registered = 1
    commercial = 2
    retail = 3
    indetermined = 4
}
enum GameVersion_t : uint {
    exe_doom_1_2 = 0
    exe_doom_1_666 = 1
    exe_doom_1_7 = 2
    exe_doom_1_8 = 3
    exe_doom_1_9 = 4
    exe_hacx = 5
    exe_ultimate = 6
    exe_final = 7
    exe_final2 = 8
    exe_chex = 9
    exe_heretic_1_3 = 10
    exe_hexen_1_1 = 11
    exe_strife_1_2 = 12
    exe_strife_1_31 = 13
}
enum ammotype_t : uint {
    am_clip = 0
    am_shell = 1
    am_cell = 2
    am_misl = 3
    NUMAMMO = 4
    am_noammo = 5
}
struct weaponinfo_t {
    ammo : ammotype_t
    upstate : int
    downstate : int
    readystate : int
    atkstate : int
    flashstate : int
}
struct iwad_t {
    name : int8?
    mission : GameMission_t
    mode : GameMode_t
    description : int8?
}
typedef sha1_digest_t = uint8[20]
struct net_connect_data_t {
    gamemode : int
    gamemission : int
    lowres_turn : int
    drone : int
    max_players : int
    is_freedoom : int
    wad_sha1sum : sha1_digest_t
    deh_sha1sum : sha1_digest_t
    player_class : int
}
struct net_gamesettings_t {
    ticdup : int
    extratics : int
    deathmatch : int
    episode : int
    nomonsters : int
    fast_monsters : int
    respawn_monsters : int
    map : int
    skill : int
    gameversion : int
    lowres_turn : int
    new_sync : int
    timelimit : int
    loadgame : int
    random : int
    num_players : int
    consoleplayer : int
    player_classes : int[8]
}
typedef netgame_startup_callback_t = function<(var _arg0:int;var _arg1:int):uint>
struct loop_interface_t {
    ProcessEvents : function<():void>
    BuildTiccmd : function<(var _arg0:ticcmd_t?;var _arg1:int):void>
    RunTic : function<(var _arg0:ticcmd_t?;var _arg1:uint?):void>
    RunMenu : function<():void>
}
struct ticcmd_set_t {
    cmds : ticcmd_t[8]
    ingame : uint[8]
}
typedef atexit_func_t = function<():void>
enum skill_t {
    sk_noitems = -1
    sk_baby = 0
    sk_easy = 1
    sk_medium = 2
    sk_hard = 3
    sk_nightmare = 4
}
enum gamestate_t : uint {
    GS_LEVEL = 0
    GS_INTERMISSION = 1
    GS_FINALE = 2
    GS_DEMOSCREEN = 3
}
enum gameaction_t : uint {
    ga_nothing = 0
    ga_loadlevel = 1
    ga_newgame = 2
    ga_loadgame = 3
    ga_savegame = 4
    ga_playdemo = 5
    ga_completed = 6
    ga_victory = 7
    ga_worlddone = 8
    ga_screenshot = 9
}
struct _wad_file_s {
    file_class : wad_file_class_t?
    mapped : uint8?
    length : uint
}
struct wad_file_class_t {
    OpenFile : function<(var _arg0:int8?):_wad_file_s?>
    CloseFile : function<(var _arg0:_wad_file_s?):void>
    Read : function<(var _arg0:_wad_file_s?;var _arg1:uint;var _arg2:uint8?;var _arg3:uint64):uint64>
}
struct wad_file_t {
    file_class : wad_file_class_t?
    mapped : uint8?
    length : uint
}
struct lumpinfo_s {
    name : int8[8]
    wad_file : _wad_file_s?
    position : int
    size : int
    cache : uint8?
    next : lumpinfo_s?
}
struct lumpinfo_t {
    name : int8[8]
    wad_file : _wad_file_s?
    position : int
    size : int
    cache : uint8?
    next : lumpinfo_s?
}
typedef grabmouse_callback_t = function<():uint>
struct Unnamed_d_main_689 {
    name : int8?
    mission : int
}
struct Unnamed_d_main_928 {
    description : int8?
    cmdline : int8?
    version : GameVersion_t
}
struct Unnamed_d_mode_26 {
    mission : GameMission_t
    mode : GameMode_t
    episode : int
    map : int
}
struct Unnamed_d_mode_119 {
    mission : GameMission_t
    version : GameVersion_t
}
struct post_t {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 2ul)
}
struct spriteframe_t {
    rotate : uint
    lump : int16[8]
    flip : uint8[8]
}
struct spritedef_t {
    numframes : int
    spriteframes : spriteframe_t?
}
enum finalestage_t : uint {
    F_STAGE_TEXT = 0
    F_STAGE_ARTSCREEN = 1
    F_STAGE_CAST = 2
}
struct textscreen_t {
    mission : GameMission_t
    episode : int
    level : int
    background : int8?
    text : int8?
}
struct castinfo_t {
    name : int8?
    type_0 : mobjtype_t
}
struct wbplayerstruct_t {
    in_0 : uint
    skills : int
    sitems : int
    ssecret : int
    stime : int
    frags : int[4]
    score : int
}
struct wbstartstruct_t {
    epsd : int
    didsecret : uint
    last : int
    next : int
    maxkills : int
    maxitems : int
    maxsecret : int
    maxfrags : int
    partime : int
    pnum : int
    plyr : wbplayerstruct_t[4]
}
struct subsector_t {
    sector : sector_t?
    numlines : int16
    firstline : int16
}
struct Unnamed_g_game_177 {
    weapon : weapontype_t
    weapon_num : weapontype_t
}
struct hu_textline_t {
    x : int
    y : int
    f : patch_t??
    sc : int
    l : int8[81]
    len : int
    needsupdate : int
}
struct hu_stext_t {
    l : hu_textline_t[4]
    h : int
    cl : int
    on : uint?
    laston : uint
}
struct hu_itext_t {
    l : hu_textline_t
    lm : int
    on : uint?
    laston : uint
}
struct screen_mode_t {
    width : int
    height : int
    InitMode : function<(var _arg0:uint8?):void>
    DrawScreen : function<(var _arg0:int;var _arg1:int;var _arg2:int;var _arg3:int):uint>
    poor_quality : uint
}
struct sfxinfo_struct {
    tagname : int8?
    name : int8[9]
    priority : int
    link : sfxinfo_struct?
    pitch : int
    volume : int
    usefulness : int
    lumpnum : int
    numchannels : int
    driver_data : uint8?
}
struct sfxinfo_t {
    tagname : int8?
    name : int8[9]
    priority : int
    link : sfxinfo_struct?
    pitch : int
    volume : int
    usefulness : int
    lumpnum : int
    numchannels : int
    driver_data : uint8?
}
enum snddevice_t : uint {
    SNDDEVICE_NONE = 0
    SNDDEVICE_PCSPEAKER = 1
    SNDDEVICE_ADLIB = 2
    SNDDEVICE_SB = 3
    SNDDEVICE_PAS = 4
    SNDDEVICE_GUS = 5
    SNDDEVICE_WAVEBLASTER = 6
    SNDDEVICE_SOUNDCANVAS = 7
    SNDDEVICE_GENMIDI = 8
    SNDDEVICE_AWE32 = 9
    SNDDEVICE_CD = 10
}
struct sound_module_t {
    sound_devices : snddevice_t?
    num_sound_devices : int
    Init : function<(var _arg0:uint):uint>
    Shutdown : function<():void>
    GetSfxLumpNum : function<(var _arg0:sfxinfo_struct?):int>
    Update : function<():void>
    UpdateSoundParams : function<(var _arg0:int;var _arg1:int;var _arg2:int):void>
    StartSound : function<(var _arg0:sfxinfo_struct?;var _arg1:int;var _arg2:int;var _arg3:int):int>
    StopSound : function<(var _arg0:int):void>
    SoundIsPlaying : function<(var _arg0:int):uint>
    CacheSounds : function<(var _arg0:sfxinfo_struct?;var _arg1:int):void>
}
struct music_module_t {
    sound_devices : snddevice_t?
    num_sound_devices : int
    Init : function<():uint>
    Shutdown : function<():void>
    SetMusicVolume : function<(var _arg0:int):void>
    PauseMusic : function<():void>
    ResumeMusic : function<():void>
    RegisterSong : function<(var _arg0:uint8?;var _arg1:int):uint8?>
    UnRegisterSong : function<(var _arg0:uint8?):void>
    PlaySong : function<(var _arg0:uint8?;var _arg1:uint):void>
    StopSong : function<():void>
    MusicIsPlaying : function<():uint>
    Poll : function<():void>
}
struct c2da___va_list_tag {
    gp_offset : uint
    fp_offset : uint
    overflow_arg_area : uint8?
    reg_save_area : uint8?
}
typedef va_list = c2da___va_list_tag[1]
struct atexit_listentry_t {
    func : atexit_func_t
    run_on_error : uint
    next : atexit_listentry_s?
}
struct atexit_listentry_s {
    func : atexit_func_t
    run_on_error : uint
    next : atexit_listentry_s?
}
typedef uint32_t = uint
enum memfile_mode_t : uint {
    MODE_READ = 0
    MODE_WRITE = 1
}
struct _MEMFILE {
    buf : uint8?
    buflen : uint64
    alloced : uint64
    position : uint
    mode : memfile_mode_t
}
struct MEMFILE {
    buf : uint8?
    buflen : uint64
    alloced : uint64
    position : uint
    mode : memfile_mode_t
}
enum mem_rel_t : uint {
    MEM_SEEK_SET = 0
    MEM_SEEK_CUR = 1
    MEM_SEEK_END = 2
}
enum default_type_t : uint {
    DEFAULT_INT = 0
    DEFAULT_INT_HEX = 1
    DEFAULT_STRING = 2
    DEFAULT_FLOAT = 3
    DEFAULT_KEY = 4
}
struct default_t {
    name : int8?
    location : uint8?
    type_0 : default_type_t
    untranslated : int
    original_translated : int
    bound : uint
}
struct default_collection_t {
    defaults : default_t?
    numdefaults : int
    filename : int8?
}
typedef int64_t = int64
struct menuitem_t {
    status : int16
    name : int8[10]
    routine : function<(var _arg0:int):void>
    alphaKey : int8
}
struct menu_t {
    numitems : int16
    prevMenu : menu_s?
    menuitems : menuitem_t?
    routine : function<():void>
    x : int16
    y : int16
    lastOn : int16
}
struct menu_s {
    numitems : int16
    prevMenu : menu_s?
    menuitems : menuitem_t?
    routine : function<():void>
    x : int16
    y : int16
    lastOn : int16
}
enum ceiling_e : uint {
    lowerToFloor = 0
    raiseToHighest = 1
    lowerAndCrush = 2
    crushAndRaise = 3
    fastCrushAndRaise = 4
    silentCrushAndRaise = 5
}
struct ceiling_t {
    thinker : thinker_s
    type_0 : ceiling_e
    sector : sector_t?
    bottomheight : int
    topheight : int
    speed : int
    crush : uint
    direction : int
    tag : int
    olddirection : int
}
enum result_e : uint {
    ok = 0
    crushed = 1
    pastdest = 2
}
struct side_t {
    textureoffset : int
    rowoffset : int
    toptexture : int16
    bottomtexture : int16
    midtexture : int16
    sector : sector_t?
}
enum plat_e : uint {
    up = 0
    down = 1
    waiting = 2
    in_stasis = 3
}
enum plattype_e : uint {
    perpetualRaise = 0
    downWaitUpStay = 1
    raiseAndChange = 2
    raiseToNearestAndChange = 3
    blazeDWUS = 4
}
struct plat_t {
    thinker : thinker_s
    sector : sector_t?
    speed : int
    low : int
    high : int
    wait : int
    count : int
    status : plat_e
    oldstatus : plat_e
    crush : uint
    tag : int
    type_0 : plattype_e
}
enum vldoor_e : uint {
    vld_normal = 0
    vld_close30ThenOpen = 1
    vld_close = 2
    vld_open = 3
    vld_raiseIn5Mins = 4
    vld_blazeRaise = 5
    vld_blazeOpen = 6
    vld_blazeClose = 7
}
struct vldoor_t {
    thinker : thinker_s
    type_0 : vldoor_e
    sector : sector_t?
    topheight : int
    speed : int
    direction : int
    topwait : int
    topcountdown : int
}
enum floor_e : uint {
    lowerFloor = 0
    lowerFloorToLowest = 1
    turboLower = 2
    raiseFloor = 3
    raiseFloorToNearest = 4
    raiseToTexture = 5
    lowerAndChange = 6
    raiseFloor24 = 7
    raiseFloor24AndChange = 8
    raiseFloorCrush = 9
    raiseFloorTurbo = 10
    donutRaise = 11
    raiseFloor512 = 12
}
enum dirtype_t : uint {
    DI_EAST = 0
    DI_NORTHEAST = 1
    DI_NORTH = 2
    DI_NORTHWEST = 3
    DI_WEST = 4
    DI_SOUTHWEST = 5
    DI_SOUTH = 6
    DI_SOUTHEAST = 7
    DI_NODIR = 8
    NUMDIRS = 9
}
enum stair_e : uint {
    build8 = 0
    turbo16 = 1
}
struct floormove_t {
    thinker : thinker_s
    type_0 : floor_e
    crush : uint
    sector : sector_t?
    direction : int
    newspecial : int
    texture : int16
    floordestheight : int
    speed : int
}
enum card_t : uint {
    it_bluecard = 0
    it_yellowcard = 1
    it_redcard = 2
    it_blueskull = 3
    it_yellowskull = 4
    it_redskull = 5
    NUMCARDS = 6
}
struct fireflicker_t {
    thinker : thinker_s
    sector : sector_t?
    count : int
    maxlight : int
    minlight : int
}
struct lightflash_t {
    thinker : thinker_s
    sector : sector_t?
    count : int
    maxlight : int
    minlight : int
    maxtime : int
    mintime : int
}
struct strobe_t {
    thinker : thinker_s
    sector : sector_t?
    count : int
    minlight : int
    maxlight : int
    darktime : int
    brighttime : int
}
struct glow_t {
    thinker : thinker_s
    sector : sector_t?
    minlight : int
    maxlight : int
    direction : int
}
struct divline_t {
    x : int
    y : int
    dx : int
    dy : int
}
struct Unnamed_p_local_146 {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 8ul)
}
struct intercept_t {
    frac : int
    isaline : uint
    d : uint64
}
typedef traverser_t = function<(var _arg0:intercept_t?):uint>
struct intercepts_overrun_t {
    len : int
    addr_0 : uint8?
    int16_array : uint
}
typedef intptr_t = int64
struct mapvertex_t {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 4ul)
}
struct mapsidedef_t {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 30ul)
}
struct maplinedef_t {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 14ul)
}
struct mapsector_t {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 26ul)
}
struct mapsubsector_t {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 4ul)
}
struct mapseg_t {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 12ul)
}
struct mapnode_t {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 28ul)
}
struct seg_t {
    v1 : vertex_t?
    v2 : vertex_t?
    offset : int
    angle : uint
    sidedef : side_t?
    linedef : line_s?
    frontsector : sector_t?
    backsector : sector_t?
}
struct node_t {
    x : int
    y : int
    dx : int
    dy : int
    bbox : int[2][4]
    children : uint16[2]
}
struct anim_t {
    istexture : uint
    picnum : int
    basepic : int
    numpics : int
    speed : int
}
struct animdef_t {
    istexture : int
    endname : int8[9]
    startname : int8[9]
    speed : int
}
enum bwhere_e : uint {
    top = 0
    middle = 1
    bottom = 2
}
struct button_t {
    line : line_s?
    where_0 : bwhere_e
    btexture : int
    btimer : int
    soundorg : degenmobj_t?
}
struct switchlist_t {
    name1 : int8[9]
    name2 : int8[9]
    episode : int16
}
struct drawseg_s {
    curline : seg_t?
    x1 : int
    x2 : int
    scale1 : int
    scale2 : int
    scalestep : int
    silhouette : int
    bsilheight : int
    tsilheight : int
    sprtopclip : int16?
    sprbottomclip : int16?
    maskedtexturecol : int16?
}
struct drawseg_t {
    curline : seg_t?
    x1 : int
    x2 : int
    scale1 : int
    scale2 : int
    scalestep : int
    silhouette : int
    bsilheight : int
    tsilheight : int
    sprtopclip : int16?
    sprbottomclip : int16?
    maskedtexturecol : int16?
}
struct visplane_t {
    height : int
    picnum : int
    lightlevel : int
    minx : int
    maxx : int
    pad1 : uint8
    top : uint8[320]
    pad2 : uint8
    pad3 : uint8
    bottom : uint8[320]
    pad4 : uint8
}
struct cliprange_t {
    first : int
    last : int
}
typedef lighttable_t = uint8
struct texpatch_t {
    originx : int16
    originy : int16
    patch : int
}
struct texture_t {
    name : int8[8]
    width : int16
    height : int16
    index : int
    next : texture_s?
    patchcount : int16
    patches : texpatch_t[1]
}
struct texture_s {
    name : int8[8]
    width : int16
    height : int16
    index : int
    next : texture_s?
    patchcount : int16
    patches : texpatch_t[1]
}
struct mappatch_t {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 10ul)
}
struct maptexture_t {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 32ul)
}
typedef planefunction_t = function<(var _arg0:int;var _arg1:int):void>
struct vissprite_s {
    prev : vissprite_s?
    next : vissprite_s?
    x1 : int
    x2 : int
    gx : int
    gy : int
    gz : int
    gzt : int
    startfrac : int
    scale : int
    xiscale : int
    texturemid : int
    patch : int
    colormap : uint8?
    mobjflags : int
}
struct vissprite_t {
    prev : vissprite_s?
    next : vissprite_s?
    x1 : int
    x2 : int
    gx : int
    gy : int
    gz : int
    gzt : int
    startfrac : int
    scale : int
    xiscale : int
    texturemid : int
    patch : int
    colormap : uint8?
    mobjflags : int
}
struct sha1_context_s {
    h0 : uint
    h1 : uint
    h2 : uint
    h3 : uint
    h4 : uint
    nblocks : uint
    buf : uint8[64]
    count : int
}
struct sha1_context_t {
    h0 : uint
    h1 : uint
    h2 : uint
    h3 : uint
    h4 : uint
    nblocks : uint
    buf : uint8[64]
    count : int
}
struct musicinfo_t {
    name : int8?
    lumpnum : int
    data : uint8?
    handle : uint8?
}
struct st_number_t {
    x : int
    y : int
    width : int
    oldnum : int
    num : int?
    on : uint?
    p : patch_t??
    data : int
}
struct st_percent_t {
    n : st_number_t
    p : patch_t?
}
struct st_multicon_t {
    x : int
    y : int
    oldinum : int
    inum : int?
    on : uint?
    p : patch_t??
    data : int
}
struct st_binicon_t {
    x : int
    y : int
    oldval : uint
    val : uint?
    on : uint?
    p : patch_t?
    data : int
}
enum st_stateenum_t : uint {
    AutomapState = 0
    FirstPersonState = 1
}
enum st_chatstateenum_t : uint {
    StartChatState = 0
    WaitDestState = 1
    GetChatState = 2
}
typedef load_callback_t = function<(var _arg0:int8?;var _arg1:patch_t??):void>
struct channel_t {
    sfxinfo : sfxinfo_struct?
    origin : mobj_s?
    handle : int
}
typedef vpatchclipfunc_t = function<(var _arg0:patch_t?;var _arg1:int;var _arg2:int):uint>
struct pcx_t {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 129ul)
}
enum stateenum_t {
    NoState = -1
    StatCount = 0
    ShowNextLoc = 1
}
struct point_t {
    x : int
    y : int
}
enum animenum_t : uint {
    ANIM_ALWAYS = 0
    ANIM_RANDOM = 1
    ANIM_LEVEL = 2
}
struct anim_t_0 {
    type_0 : animenum_t
    period : int
    nanims : int
    loc : point_t
    data1 : int
    data2 : int
    p : patch_t? [3]
    nexttic : int
    lastdrawn : int
    ctr : int
    state : int
}
typedef load_callback_t_0 = function<(var _arg0:int8?;var _arg1:patch_t??):void>
struct filelump_t {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 16ul)
}
struct wadinfo_t {
    c2da_storage : uint64 = c2da_rt_calloc(1ul, 12ul)
}
struct Unnamed_w_wad_575 {
    mission : GameMission_t
    lumpname : int8?
}
struct memblock_s {
    size : int
    user : uint8??
    tag : int
    id : int
    next : memblock_s?
    prev : memblock_s?
}
struct memzone_t {
    size : int
    blocklist : memblock_s
    rover : memblock_s?
}
struct memblock_t {
    size : int
    user : uint8??
    tag : int
    id : int
    next : memblock_s?
    prev : memblock_s?
}
struct stdc_wad_file_t {
    wad : _wad_file_s
    fstream : _IO_FILE?
}
typedef uint16_t = uint16
struct FB_BitField {
    offset : uint
    length : uint
}
struct FB_ScreenInfo {
    xres : uint
    yres : uint
    xres_virtual : uint
    yres_virtual : uint
    bits_per_pixel : uint
    red : FB_BitField
    green : FB_BitField
    blue : FB_BitField
    transp : FB_BitField
}
struct color {
    c2da_bits_0 : uint
}
struct col_t {
    r : uint8
    g : uint8
    b : uint8
}
typedef pixel_t = uint8
typedef int32_t = int
let PU_NUM_TAGS : int = 9

let PU_CACHE : int = 8

let PU_PURGELEVEL : int = 7

let PU_LEVSPEC : int = 6

let PU_LEVEL : int = 5

let PU_FREE : int = 4

let PU_MUSIC : int = 3

let PU_SOUND : int = 2

let PU_STATIC : int = 1

let wp_nochange : int = 10

let NUMWEAPONS : int = 9

let wp_supershotgun : int = 8

let wp_chainsaw : int = 7

let wp_bfg : int = 6

let wp_plasma : int = 5

let wp_missile : int = 4

let wp_chaingun : int = 3

let wp_shotgun : int = 2

let wp_pistol : int = 1

let wp_fist : int = 0

let NUMPOWERS : int = 6

let pw_infrared : int = 5

let pw_allmap : int = 4

let pw_ironfeet : int = 3

let pw_invisibility : int = 2

let pw_strength : int = 1

let pw_invulnerability : int = 0

let ev_quit : int = 4

let ev_joystick : int = 3

let ev_mouse : int = 2

let ev_keyup : int = 1

let ev_keydown : int = 0

let NUMSPRITES : int = 138

let SPR_TLP2 : int = 137

let SPR_TLMP : int = 136

let SPR_BRS1 : int = 135

let SPR_POB2 : int = 134

let SPR_POB1 : int = 133

let SPR_HDB6 : int = 132

let SPR_HDB5 : int = 131

let SPR_HDB4 : int = 130

let SPR_HDB3 : int = 129

let SPR_HDB2 : int = 128

let SPR_HDB1 : int = 127

let SPR_SMRT : int = 126

let SPR_SMGT : int = 125

let SPR_SMBT : int = 124

let SPR_TRED : int = 123

let SPR_TGRN : int = 122

let SPR_TBLU : int = 121

let SPR_COL5 : int = 120

let SPR_FSKU : int = 119

let SPR_CEYE : int = 118

let SPR_ELEC : int = 117

let SPR_TRE2 : int = 116

let SPR_TRE1 : int = 115

let SPR_COL6 : int = 114

let SPR_CBRA : int = 113

let SPR_CAND : int = 112

let SPR_COL4 : int = 111

let SPR_COL3 : int = 110

let SPR_COL2 : int = 109

let SPR_COL1 : int = 108

let SPR_SMIT : int = 107

let SPR_GOR5 : int = 106

let SPR_GOR4 : int = 105

let SPR_GOR3 : int = 104

let SPR_GOR2 : int = 103

let SPR_POL6 : int = 102

let SPR_POL1 : int = 101

let SPR_POL3 : int = 100

let SPR_POL4 : int = 99

let SPR_POL5 : int = 98

let SPR_POL2 : int = 97

let SPR_GOR1 : int = 96

let SPR_SMT2 : int = 95

let SPR_COLU : int = 94

let SPR_SGN2 : int = 93

let SPR_SHOT : int = 92

let SPR_PLAS : int = 91

let SPR_LAUN : int = 90

let SPR_CSAW : int = 89

let SPR_MGUN : int = 88

let SPR_BFUG : int = 87

let SPR_BPAK : int = 86

let SPR_SBOX : int = 85

let SPR_SHEL : int = 84

let SPR_CELP : int = 83

let SPR_CELL : int = 82

let SPR_BROK : int = 81

let SPR_ROCK : int = 80

let SPR_AMMO : int = 79

let SPR_CLIP : int = 78

let SPR_PVIS : int = 77

let SPR_PMAP : int = 76

let SPR_SUIT : int = 75

let SPR_MEGA : int = 74

let SPR_PINS : int = 73

let SPR_PSTR : int = 72

let SPR_PINV : int = 71

let SPR_SOUL : int = 70

let SPR_MEDI : int = 69

let SPR_STIM : int = 68

let SPR_YSKU : int = 67

let SPR_RSKU : int = 66

let SPR_BSKU : int = 65

let SPR_YKEY : int = 64

let SPR_RKEY : int = 63

let SPR_BKEY : int = 62

let SPR_BON2 : int = 61

let SPR_BON1 : int = 60

let SPR_FCAN : int = 59

let SPR_BEXP : int = 58

let SPR_BAR1 : int = 57

let SPR_ARM2 : int = 56

let SPR_ARM1 : int = 55

let SPR_BOSF : int = 54

let SPR_BBRN : int = 53

let SPR_KEEN : int = 52

let SPR_SSWV : int = 51

let SPR_PAIN : int = 50

let SPR_CYBR : int = 49

let SPR_APBX : int = 48

let SPR_APLS : int = 47

let SPR_BSPI : int = 46

let SPR_SPID : int = 45

let SPR_SKUL : int = 44

let SPR_BOS2 : int = 43

let SPR_BOSS : int = 42

let SPR_BAL7 : int = 41

let SPR_HEAD : int = 40

let SPR_SARG : int = 39

let SPR_CPOS : int = 38

let SPR_FATT : int = 37

let SPR_MANF : int = 36

let SPR_SKEL : int = 35

let SPR_FBXP : int = 34

let SPR_FATB : int = 33

let SPR_FIRE : int = 32

let SPR_VILE : int = 31

let SPR_SPOS : int = 30

let SPR_POSS : int = 29

let SPR_PLAY : int = 28

let SPR_IFOG : int = 27

let SPR_TFOG : int = 26

let SPR_BFE2 : int = 25

let SPR_BFE1 : int = 24

let SPR_BFS1 : int = 23

let SPR_MISL : int = 22

let SPR_PLSE : int = 21

let SPR_PLSS : int = 20

let SPR_BAL2 : int = 19

let SPR_BAL1 : int = 18

let SPR_PUFF : int = 17

let SPR_BLUD : int = 16

let SPR_BFGF : int = 15

let SPR_BFGG : int = 14

let SPR_PLSF : int = 13

let SPR_PLSG : int = 12

let SPR_SAWG : int = 11

let SPR_MISF : int = 10

let SPR_MISG : int = 9

let SPR_CHGF : int = 8

let SPR_CHGG : int = 7

let SPR_SHT2 : int = 6

let SPR_SHTF : int = 5

let SPR_PISF : int = 4

let SPR_PISG : int = 3

let SPR_PUNG : int = 2

let SPR_SHTG : int = 1

let SPR_TROO : int = 0

let NUMSTATES : int = 967

let S_TECH2LAMP4 : int = 966

let S_TECH2LAMP3 : int = 965

let S_TECH2LAMP2 : int = 964

let S_TECH2LAMP : int = 963

let S_TECHLAMP4 : int = 962

let S_TECHLAMP3 : int = 961

let S_TECHLAMP2 : int = 960

let S_TECHLAMP : int = 959

let S_BRAINSTEM : int = 958

let S_SMALLPOOL : int = 957

let S_COLONGIBS : int = 956

let S_HANGTNOBRAIN : int = 955

let S_HANGTLOOKUP : int = 954

let S_HANGTSKULL : int = 953

let S_HANGTLOOKDN : int = 952

let S_HANGBNOBRAIN : int = 951

let S_HANGNOGUTS : int = 950

let S_RTORCHSHRT4 : int = 949

let S_RTORCHSHRT3 : int = 948

let S_RTORCHSHRT2 : int = 947

let S_RTORCHSHRT : int = 946

let S_GTORCHSHRT4 : int = 945

let S_GTORCHSHRT3 : int = 944

let S_GTORCHSHRT2 : int = 943

let S_GTORCHSHRT : int = 942

let S_BTORCHSHRT4 : int = 941

let S_BTORCHSHRT3 : int = 940

let S_BTORCHSHRT2 : int = 939

let S_BTORCHSHRT : int = 938

let S_REDTORCH4 : int = 937

let S_REDTORCH3 : int = 936

let S_REDTORCH2 : int = 935

let S_REDTORCH : int = 934

let S_GREENTORCH4 : int = 933

let S_GREENTORCH3 : int = 932

let S_GREENTORCH2 : int = 931

let S_GREENTORCH : int = 930

let S_BLUETORCH4 : int = 929

let S_BLUETORCH3 : int = 928

let S_BLUETORCH2 : int = 927

let S_BLUETORCH : int = 926

let S_HEARTCOL2 : int = 925

let S_HEARTCOL : int = 924

let S_FLOATSKULL3 : int = 923

let S_FLOATSKULL2 : int = 922

let S_FLOATSKULL : int = 921

let S_EVILEYE4 : int = 920

let S_EVILEYE3 : int = 919

let S_EVILEYE2 : int = 918

let S_EVILEYE : int = 917

let S_TECHPILLAR : int = 916

let S_BIGTREE : int = 915

let S_TORCHTREE : int = 914

let S_SKULLCOL : int = 913

let S_CANDELABRA : int = 912

let S_CANDLESTIK : int = 911

let S_SHRTREDCOL : int = 910

let S_TALLREDCOL : int = 909

let S_SHRTGRNCOL : int = 908

let S_TALLGRNCOL : int = 907

let S_STALAGTITE : int = 906

let S_MEAT5 : int = 905

let S_MEAT4 : int = 904

let S_MEAT3 : int = 903

let S_MEAT2 : int = 902

let S_LIVESTICK2 : int = 901

let S_LIVESTICK : int = 900

let S_DEADSTICK : int = 899

let S_HEADCANDLES2 : int = 898

let S_HEADCANDLES : int = 897

let S_HEADONASTICK : int = 896

let S_GIBS : int = 895

let S_HEADSONSTICK : int = 894

let S_DEADBOTTOM : int = 893

let S_DEADTORSO : int = 892

let S_BLOODYTWITCH4 : int = 891

let S_BLOODYTWITCH3 : int = 890

let S_BLOODYTWITCH2 : int = 889

let S_BLOODYTWITCH : int = 888

let S_STALAG : int = 887

let S_COLU : int = 886

let S_SHOT2 : int = 885

let S_SHOT : int = 884

let S_PLAS : int = 883

let S_LAUN : int = 882

let S_CSAW : int = 881

let S_MGUN : int = 880

let S_BFUG : int = 879

let S_BPAK : int = 878

let S_SBOX : int = 877

let S_SHEL : int = 876

let S_CELP : int = 875

let S_CELL : int = 874

let S_BROK : int = 873

let S_ROCK : int = 872

let S_AMMO : int = 871

let S_CLIP : int = 870

let S_PVIS2 : int = 869

let S_PVIS : int = 868

let S_PMAP6 : int = 867

let S_PMAP5 : int = 866

let S_PMAP4 : int = 865

let S_PMAP3 : int = 864

let S_PMAP2 : int = 863

let S_PMAP : int = 862

let S_SUIT : int = 861

let S_MEGA4 : int = 860

let S_MEGA3 : int = 859

let S_MEGA2 : int = 858

let S_MEGA : int = 857

let S_PINS4 : int = 856

let S_PINS3 : int = 855

let S_PINS2 : int = 854

let S_PINS : int = 853

let S_PSTR : int = 852

let S_PINV4 : int = 851

let S_PINV3 : int = 850

let S_PINV2 : int = 849

let S_PINV : int = 848

let S_SOUL6 : int = 847

let S_SOUL5 : int = 846

let S_SOUL4 : int = 845

let S_SOUL3 : int = 844

let S_SOUL2 : int = 843

let S_SOUL : int = 842

let S_MEDI : int = 841

let S_STIM : int = 840

let S_YSKULL2 : int = 839

let S_YSKULL : int = 838

let S_RSKULL2 : int = 837

let S_RSKULL : int = 836

let S_BSKULL2 : int = 835

let S_BSKULL : int = 834

let S_YKEY2 : int = 833

let S_YKEY : int = 832

let S_RKEY2 : int = 831

let S_RKEY : int = 830

let S_BKEY2 : int = 829

let S_BKEY : int = 828

let S_BON2E : int = 827

let S_BON2D : int = 826

let S_BON2C : int = 825

let S_BON2B : int = 824

let S_BON2A : int = 823

let S_BON2 : int = 822

let S_BON1E : int = 821

let S_BON1D : int = 820

let S_BON1C : int = 819

let S_BON1B : int = 818

let S_BON1A : int = 817

let S_BON1 : int = 816

let S_BBAR3 : int = 815

let S_BBAR2 : int = 814

let S_BBAR1 : int = 813

let S_BEXP5 : int = 812

let S_BEXP4 : int = 811

let S_BEXP3 : int = 810

let S_BEXP2 : int = 809

let S_BEXP : int = 808

let S_BAR2 : int = 807

let S_BAR1 : int = 806

let S_ARM2A : int = 805

let S_ARM2 : int = 804

let S_ARM1A : int = 803

let S_ARM1 : int = 802

let S_BRAINEXPLODE3 : int = 801

let S_BRAINEXPLODE2 : int = 800

let S_BRAINEXPLODE1 : int = 799

let S_SPAWNFIRE8 : int = 798

let S_SPAWNFIRE7 : int = 797

let S_SPAWNFIRE6 : int = 796

let S_SPAWNFIRE5 : int = 795

let S_SPAWNFIRE4 : int = 794

let S_SPAWNFIRE3 : int = 793

let S_SPAWNFIRE2 : int = 792

let S_SPAWNFIRE1 : int = 791

let S_SPAWN4 : int = 790

let S_SPAWN3 : int = 789

let S_SPAWN2 : int = 788

let S_SPAWN1 : int = 787

let S_BRAINEYE1 : int = 786

let S_BRAINEYESEE : int = 785

let S_BRAINEYE : int = 784

let S_BRAIN_DIE4 : int = 783

let S_BRAIN_DIE3 : int = 782

let S_BRAIN_DIE2 : int = 781

let S_BRAIN_DIE1 : int = 780

let S_BRAIN_PAIN : int = 779

let S_BRAIN : int = 778

let S_KEENPAIN2 : int = 777

let S_KEENPAIN : int = 776

let S_COMMKEEN12 : int = 775

let S_COMMKEEN11 : int = 774

let S_COMMKEEN10 : int = 773

let S_COMMKEEN9 : int = 772

let S_COMMKEEN8 : int = 771

let S_COMMKEEN7 : int = 770

let S_COMMKEEN6 : int = 769

let S_COMMKEEN5 : int = 768

let S_COMMKEEN4 : int = 767

let S_COMMKEEN3 : int = 766

let S_COMMKEEN2 : int = 765

let S_COMMKEEN : int = 764

let S_KEENSTND : int = 763

let S_SSWV_RAISE5 : int = 762

let S_SSWV_RAISE4 : int = 761

let S_SSWV_RAISE3 : int = 760

let S_SSWV_RAISE2 : int = 759

let S_SSWV_RAISE1 : int = 758

let S_SSWV_XDIE9 : int = 757

let S_SSWV_XDIE8 : int = 756

let S_SSWV_XDIE7 : int = 755

let S_SSWV_XDIE6 : int = 754

let S_SSWV_XDIE5 : int = 753

let S_SSWV_XDIE4 : int = 752

let S_SSWV_XDIE3 : int = 751

let S_SSWV_XDIE2 : int = 750

let S_SSWV_XDIE1 : int = 749

let S_SSWV_DIE5 : int = 748

let S_SSWV_DIE4 : int = 747

let S_SSWV_DIE3 : int = 746

let S_SSWV_DIE2 : int = 745

let S_SSWV_DIE1 : int = 744

let S_SSWV_PAIN2 : int = 743

let S_SSWV_PAIN : int = 742

let S_SSWV_ATK6 : int = 741

let S_SSWV_ATK5 : int = 740

let S_SSWV_ATK4 : int = 739

let S_SSWV_ATK3 : int = 738

let S_SSWV_ATK2 : int = 737

let S_SSWV_ATK1 : int = 736

let S_SSWV_RUN8 : int = 735

let S_SSWV_RUN7 : int = 734

let S_SSWV_RUN6 : int = 733

let S_SSWV_RUN5 : int = 732

let S_SSWV_RUN4 : int = 731

let S_SSWV_RUN3 : int = 730

let S_SSWV_RUN2 : int = 729

let S_SSWV_RUN1 : int = 728

let S_SSWV_STND2 : int = 727

let S_SSWV_STND : int = 726

let S_PAIN_RAISE6 : int = 725

let S_PAIN_RAISE5 : int = 724

let S_PAIN_RAISE4 : int = 723

let S_PAIN_RAISE3 : int = 722

let S_PAIN_RAISE2 : int = 721

let S_PAIN_RAISE1 : int = 720

let S_PAIN_DIE6 : int = 719

let S_PAIN_DIE5 : int = 718

let S_PAIN_DIE4 : int = 717

let S_PAIN_DIE3 : int = 716

let S_PAIN_DIE2 : int = 715

let S_PAIN_DIE1 : int = 714

let S_PAIN_PAIN2 : int = 713

let S_PAIN_PAIN : int = 712

let S_PAIN_ATK4 : int = 711

let S_PAIN_ATK3 : int = 710

let S_PAIN_ATK2 : int = 709

let S_PAIN_ATK1 : int = 708

let S_PAIN_RUN6 : int = 707

let S_PAIN_RUN5 : int = 706

let S_PAIN_RUN4 : int = 705

let S_PAIN_RUN3 : int = 704

let S_PAIN_RUN2 : int = 703

let S_PAIN_RUN1 : int = 702

let S_PAIN_STND : int = 701

let S_CYBER_DIE10 : int = 700

let S_CYBER_DIE9 : int = 699

let S_CYBER_DIE8 : int = 698

let S_CYBER_DIE7 : int = 697

let S_CYBER_DIE6 : int = 696

let S_CYBER_DIE5 : int = 695

let S_CYBER_DIE4 : int = 694

let S_CYBER_DIE3 : int = 693

let S_CYBER_DIE2 : int = 692

let S_CYBER_DIE1 : int = 691

let S_CYBER_PAIN : int = 690

let S_CYBER_ATK6 : int = 689

let S_CYBER_ATK5 : int = 688

let S_CYBER_ATK4 : int = 687

let S_CYBER_ATK3 : int = 686

let S_CYBER_ATK2 : int = 685

let S_CYBER_ATK1 : int = 684

let S_CYBER_RUN8 : int = 683

let S_CYBER_RUN7 : int = 682

let S_CYBER_RUN6 : int = 681

let S_CYBER_RUN5 : int = 680

let S_CYBER_RUN4 : int = 679

let S_CYBER_RUN3 : int = 678

let S_CYBER_RUN2 : int = 677

let S_CYBER_RUN1 : int = 676

let S_CYBER_STND2 : int = 675

let S_CYBER_STND : int = 674

let S_ARACH_PLEX5 : int = 673

let S_ARACH_PLEX4 : int = 672

let S_ARACH_PLEX3 : int = 671

let S_ARACH_PLEX2 : int = 670

let S_ARACH_PLEX : int = 669

let S_ARACH_PLAZ2 : int = 668

let S_ARACH_PLAZ : int = 667

let S_BSPI_RAISE7 : int = 666

let S_BSPI_RAISE6 : int = 665

let S_BSPI_RAISE5 : int = 664

let S_BSPI_RAISE4 : int = 663

let S_BSPI_RAISE3 : int = 662

let S_BSPI_RAISE2 : int = 661

let S_BSPI_RAISE1 : int = 660

let S_BSPI_DIE7 : int = 659

let S_BSPI_DIE6 : int = 658

let S_BSPI_DIE5 : int = 657

let S_BSPI_DIE4 : int = 656

let S_BSPI_DIE3 : int = 655

let S_BSPI_DIE2 : int = 654

let S_BSPI_DIE1 : int = 653

let S_BSPI_PAIN2 : int = 652

let S_BSPI_PAIN : int = 651

let S_BSPI_ATK4 : int = 650

let S_BSPI_ATK3 : int = 649

let S_BSPI_ATK2 : int = 648

let S_BSPI_ATK1 : int = 647

let S_BSPI_RUN12 : int = 646

let S_BSPI_RUN11 : int = 645

let S_BSPI_RUN10 : int = 644

let S_BSPI_RUN9 : int = 643

let S_BSPI_RUN8 : int = 642

let S_BSPI_RUN7 : int = 641

let S_BSPI_RUN6 : int = 640

let S_BSPI_RUN5 : int = 639

let S_BSPI_RUN4 : int = 638

let S_BSPI_RUN3 : int = 637

let S_BSPI_RUN2 : int = 636

let S_BSPI_RUN1 : int = 635

let S_BSPI_SIGHT : int = 634

let S_BSPI_STND2 : int = 633

let S_BSPI_STND : int = 632

let S_SPID_DIE11 : int = 631

let S_SPID_DIE10 : int = 630

let S_SPID_DIE9 : int = 629

let S_SPID_DIE8 : int = 628

let S_SPID_DIE7 : int = 627

let S_SPID_DIE6 : int = 626

let S_SPID_DIE5 : int = 625

let S_SPID_DIE4 : int = 624

let S_SPID_DIE3 : int = 623

let S_SPID_DIE2 : int = 622

let S_SPID_DIE1 : int = 621

let S_SPID_PAIN2 : int = 620

let S_SPID_PAIN : int = 619

let S_SPID_ATK4 : int = 618

let S_SPID_ATK3 : int = 617

let S_SPID_ATK2 : int = 616

let S_SPID_ATK1 : int = 615

let S_SPID_RUN12 : int = 614

let S_SPID_RUN11 : int = 613

let S_SPID_RUN10 : int = 612

let S_SPID_RUN9 : int = 611

let S_SPID_RUN8 : int = 610

let S_SPID_RUN7 : int = 609

let S_SPID_RUN6 : int = 608

let S_SPID_RUN5 : int = 607

let S_SPID_RUN4 : int = 606

let S_SPID_RUN3 : int = 605

let S_SPID_RUN2 : int = 604

let S_SPID_RUN1 : int = 603

let S_SPID_STND2 : int = 602

let S_SPID_STND : int = 601

let S_SKULL_DIE6 : int = 600

let S_SKULL_DIE5 : int = 599

let S_SKULL_DIE4 : int = 598

let S_SKULL_DIE3 : int = 597

let S_SKULL_DIE2 : int = 596

let S_SKULL_DIE1 : int = 595

let S_SKULL_PAIN2 : int = 594

let S_SKULL_PAIN : int = 593

let S_SKULL_ATK4 : int = 592

let S_SKULL_ATK3 : int = 591

let S_SKULL_ATK2 : int = 590

let S_SKULL_ATK1 : int = 589

let S_SKULL_RUN2 : int = 588

let S_SKULL_RUN1 : int = 587

let S_SKULL_STND2 : int = 586

let S_SKULL_STND : int = 585

let S_BOS2_RAISE7 : int = 584

let S_BOS2_RAISE6 : int = 583

let S_BOS2_RAISE5 : int = 582

let S_BOS2_RAISE4 : int = 581

let S_BOS2_RAISE3 : int = 580

let S_BOS2_RAISE2 : int = 579

let S_BOS2_RAISE1 : int = 578

let S_BOS2_DIE7 : int = 577

let S_BOS2_DIE6 : int = 576

let S_BOS2_DIE5 : int = 575

let S_BOS2_DIE4 : int = 574

let S_BOS2_DIE3 : int = 573

let S_BOS2_DIE2 : int = 572

let S_BOS2_DIE1 : int = 571

let S_BOS2_PAIN2 : int = 570

let S_BOS2_PAIN : int = 569

let S_BOS2_ATK3 : int = 568

let S_BOS2_ATK2 : int = 567

let S_BOS2_ATK1 : int = 566

let S_BOS2_RUN8 : int = 565

let S_BOS2_RUN7 : int = 564

let S_BOS2_RUN6 : int = 563

let S_BOS2_RUN5 : int = 562

let S_BOS2_RUN4 : int = 561

let S_BOS2_RUN3 : int = 560

let S_BOS2_RUN2 : int = 559

let S_BOS2_RUN1 : int = 558

let S_BOS2_STND2 : int = 557

let S_BOS2_STND : int = 556

let S_BOSS_RAISE7 : int = 555

let S_BOSS_RAISE6 : int = 554

let S_BOSS_RAISE5 : int = 553

let S_BOSS_RAISE4 : int = 552

let S_BOSS_RAISE3 : int = 551

let S_BOSS_RAISE2 : int = 550

let S_BOSS_RAISE1 : int = 549

let S_BOSS_DIE7 : int = 548

let S_BOSS_DIE6 : int = 547

let S_BOSS_DIE5 : int = 546

let S_BOSS_DIE4 : int = 545

let S_BOSS_DIE3 : int = 544

let S_BOSS_DIE2 : int = 543

let S_BOSS_DIE1 : int = 542

let S_BOSS_PAIN2 : int = 541

let S_BOSS_PAIN : int = 540

let S_BOSS_ATK3 : int = 539

let S_BOSS_ATK2 : int = 538

let S_BOSS_ATK1 : int = 537

let S_BOSS_RUN8 : int = 536

let S_BOSS_RUN7 : int = 535

let S_BOSS_RUN6 : int = 534

let S_BOSS_RUN5 : int = 533

let S_BOSS_RUN4 : int = 532

let S_BOSS_RUN3 : int = 531

let S_BOSS_RUN2 : int = 530

let S_BOSS_RUN1 : int = 529

let S_BOSS_STND2 : int = 528

let S_BOSS_STND : int = 527

let S_BRBALLX3 : int = 526

let S_BRBALLX2 : int = 525

let S_BRBALLX1 : int = 524

let S_BRBALL2 : int = 523

let S_BRBALL1 : int = 522

let S_HEAD_RAISE6 : int = 521

let S_HEAD_RAISE5 : int = 520

let S_HEAD_RAISE4 : int = 519

let S_HEAD_RAISE3 : int = 518

let S_HEAD_RAISE2 : int = 517

let S_HEAD_RAISE1 : int = 516

let S_HEAD_DIE6 : int = 515

let S_HEAD_DIE5 : int = 514

let S_HEAD_DIE4 : int = 513

let S_HEAD_DIE3 : int = 512

let S_HEAD_DIE2 : int = 511

let S_HEAD_DIE1 : int = 510

let S_HEAD_PAIN3 : int = 509

let S_HEAD_PAIN2 : int = 508

let S_HEAD_PAIN : int = 507

let S_HEAD_ATK3 : int = 506

let S_HEAD_ATK2 : int = 505

let S_HEAD_ATK1 : int = 504

let S_HEAD_RUN1 : int = 503

let S_HEAD_STND : int = 502

let S_SARG_RAISE6 : int = 501

let S_SARG_RAISE5 : int = 500

let S_SARG_RAISE4 : int = 499

let S_SARG_RAISE3 : int = 498

let S_SARG_RAISE2 : int = 497

let S_SARG_RAISE1 : int = 496

let S_SARG_DIE6 : int = 495

let S_SARG_DIE5 : int = 494

let S_SARG_DIE4 : int = 493

let S_SARG_DIE3 : int = 492

let S_SARG_DIE2 : int = 491

let S_SARG_DIE1 : int = 490

let S_SARG_PAIN2 : int = 489

let S_SARG_PAIN : int = 488

let S_SARG_ATK3 : int = 487

let S_SARG_ATK2 : int = 486

let S_SARG_ATK1 : int = 485

let S_SARG_RUN8 : int = 484

let S_SARG_RUN7 : int = 483

let S_SARG_RUN6 : int = 482

let S_SARG_RUN5 : int = 481

let S_SARG_RUN4 : int = 480

let S_SARG_RUN3 : int = 479

let S_SARG_RUN2 : int = 478

let S_SARG_RUN1 : int = 477

let S_SARG_STND2 : int = 476

let S_SARG_STND : int = 475

let S_TROO_RAISE5 : int = 474

let S_TROO_RAISE4 : int = 473

let S_TROO_RAISE3 : int = 472

let S_TROO_RAISE2 : int = 471

let S_TROO_RAISE1 : int = 470

let S_TROO_XDIE8 : int = 469

let S_TROO_XDIE7 : int = 468

let S_TROO_XDIE6 : int = 467

let S_TROO_XDIE5 : int = 466

let S_TROO_XDIE4 : int = 465

let S_TROO_XDIE3 : int = 464

let S_TROO_XDIE2 : int = 463

let S_TROO_XDIE1 : int = 462

let S_TROO_DIE5 : int = 461

let S_TROO_DIE4 : int = 460

let S_TROO_DIE3 : int = 459

let S_TROO_DIE2 : int = 458

let S_TROO_DIE1 : int = 457

let S_TROO_PAIN2 : int = 456

let S_TROO_PAIN : int = 455

let S_TROO_ATK3 : int = 454

let S_TROO_ATK2 : int = 453

let S_TROO_ATK1 : int = 452

let S_TROO_RUN8 : int = 451

let S_TROO_RUN7 : int = 450

let S_TROO_RUN6 : int = 449

let S_TROO_RUN5 : int = 448

let S_TROO_RUN4 : int = 447

let S_TROO_RUN3 : int = 446

let S_TROO_RUN2 : int = 445

let S_TROO_RUN1 : int = 444

let S_TROO_STND2 : int = 443

let S_TROO_STND : int = 442

let S_CPOS_RAISE7 : int = 441

let S_CPOS_RAISE6 : int = 440

let S_CPOS_RAISE5 : int = 439

let S_CPOS_RAISE4 : int = 438

let S_CPOS_RAISE3 : int = 437

let S_CPOS_RAISE2 : int = 436

let S_CPOS_RAISE1 : int = 435

let S_CPOS_XDIE6 : int = 434

let S_CPOS_XDIE5 : int = 433

let S_CPOS_XDIE4 : int = 432

let S_CPOS_XDIE3 : int = 431

let S_CPOS_XDIE2 : int = 430

let S_CPOS_XDIE1 : int = 429

let S_CPOS_DIE7 : int = 428

let S_CPOS_DIE6 : int = 427

let S_CPOS_DIE5 : int = 426

let S_CPOS_DIE4 : int = 425

let S_CPOS_DIE3 : int = 424

let S_CPOS_DIE2 : int = 423

let S_CPOS_DIE1 : int = 422

let S_CPOS_PAIN2 : int = 421

let S_CPOS_PAIN : int = 420

let S_CPOS_ATK4 : int = 419

let S_CPOS_ATK3 : int = 418

let S_CPOS_ATK2 : int = 417

let S_CPOS_ATK1 : int = 416

let S_CPOS_RUN8 : int = 415

let S_CPOS_RUN7 : int = 414

let S_CPOS_RUN6 : int = 413

let S_CPOS_RUN5 : int = 412

let S_CPOS_RUN4 : int = 411

let S_CPOS_RUN3 : int = 410

let S_CPOS_RUN2 : int = 409

let S_CPOS_RUN1 : int = 408

let S_CPOS_STND2 : int = 407

let S_CPOS_STND : int = 406

let S_FATT_RAISE8 : int = 405

let S_FATT_RAISE7 : int = 404

let S_FATT_RAISE6 : int = 403

let S_FATT_RAISE5 : int = 402

let S_FATT_RAISE4 : int = 401

let S_FATT_RAISE3 : int = 400

let S_FATT_RAISE2 : int = 399

let S_FATT_RAISE1 : int = 398

let S_FATT_DIE10 : int = 397

let S_FATT_DIE9 : int = 396

let S_FATT_DIE8 : int = 395

let S_FATT_DIE7 : int = 394

let S_FATT_DIE6 : int = 393

let S_FATT_DIE5 : int = 392

let S_FATT_DIE4 : int = 391

let S_FATT_DIE3 : int = 390

let S_FATT_DIE2 : int = 389

let S_FATT_DIE1 : int = 388

let S_FATT_PAIN2 : int = 387

let S_FATT_PAIN : int = 386

let S_FATT_ATK10 : int = 385

let S_FATT_ATK9 : int = 384

let S_FATT_ATK8 : int = 383

let S_FATT_ATK7 : int = 382

let S_FATT_ATK6 : int = 381

let S_FATT_ATK5 : int = 380

let S_FATT_ATK4 : int = 379

let S_FATT_ATK3 : int = 378

let S_FATT_ATK2 : int = 377

let S_FATT_ATK1 : int = 376

let S_FATT_RUN12 : int = 375

let S_FATT_RUN11 : int = 374

let S_FATT_RUN10 : int = 373

let S_FATT_RUN9 : int = 372

let S_FATT_RUN8 : int = 371

let S_FATT_RUN7 : int = 370

let S_FATT_RUN6 : int = 369

let S_FATT_RUN5 : int = 368

let S_FATT_RUN4 : int = 367

let S_FATT_RUN3 : int = 366

let S_FATT_RUN2 : int = 365

let S_FATT_RUN1 : int = 364

let S_FATT_STND2 : int = 363

let S_FATT_STND : int = 362

let S_FATSHOTX3 : int = 361

let S_FATSHOTX2 : int = 360

let S_FATSHOTX1 : int = 359

let S_FATSHOT2 : int = 358

let S_FATSHOT1 : int = 357

let S_SKEL_RAISE6 : int = 356

let S_SKEL_RAISE5 : int = 355

let S_SKEL_RAISE4 : int = 354

let S_SKEL_RAISE3 : int = 353

let S_SKEL_RAISE2 : int = 352

let S_SKEL_RAISE1 : int = 351

let S_SKEL_DIE6 : int = 350

let S_SKEL_DIE5 : int = 349

let S_SKEL_DIE4 : int = 348

let S_SKEL_DIE3 : int = 347

let S_SKEL_DIE2 : int = 346

let S_SKEL_DIE1 : int = 345

let S_SKEL_PAIN2 : int = 344

let S_SKEL_PAIN : int = 343

let S_SKEL_MISS4 : int = 342

let S_SKEL_MISS3 : int = 341

let S_SKEL_MISS2 : int = 340

let S_SKEL_MISS1 : int = 339

let S_SKEL_FIST4 : int = 338

let S_SKEL_FIST3 : int = 337

let S_SKEL_FIST2 : int = 336

let S_SKEL_FIST1 : int = 335

let S_SKEL_RUN12 : int = 334

let S_SKEL_RUN11 : int = 333

let S_SKEL_RUN10 : int = 332

let S_SKEL_RUN9 : int = 331

let S_SKEL_RUN8 : int = 330

let S_SKEL_RUN7 : int = 329

let S_SKEL_RUN6 : int = 328

let S_SKEL_RUN5 : int = 327

let S_SKEL_RUN4 : int = 326

let S_SKEL_RUN3 : int = 325

let S_SKEL_RUN2 : int = 324

let S_SKEL_RUN1 : int = 323

let S_SKEL_STND2 : int = 322

let S_SKEL_STND : int = 321

let S_TRACEEXP3 : int = 320

let S_TRACEEXP2 : int = 319

let S_TRACEEXP1 : int = 318

let S_TRACER2 : int = 317

let S_TRACER : int = 316

let S_SMOKE5 : int = 315

let S_SMOKE4 : int = 314

let S_SMOKE3 : int = 313

let S_SMOKE2 : int = 312

let S_SMOKE1 : int = 311

let S_FIRE30 : int = 310

let S_FIRE29 : int = 309

let S_FIRE28 : int = 308

let S_FIRE27 : int = 307

let S_FIRE26 : int = 306

let S_FIRE25 : int = 305

let S_FIRE24 : int = 304

let S_FIRE23 : int = 303

let S_FIRE22 : int = 302

let S_FIRE21 : int = 301

let S_FIRE20 : int = 300

let S_FIRE19 : int = 299

let S_FIRE18 : int = 298

let S_FIRE17 : int = 297

let S_FIRE16 : int = 296

let S_FIRE15 : int = 295

let S_FIRE14 : int = 294

let S_FIRE13 : int = 293

let S_FIRE12 : int = 292

let S_FIRE11 : int = 291

let S_FIRE10 : int = 290

let S_FIRE9 : int = 289

let S_FIRE8 : int = 288

let S_FIRE7 : int = 287

let S_FIRE6 : int = 286

let S_FIRE5 : int = 285

let S_FIRE4 : int = 284

let S_FIRE3 : int = 283

let S_FIRE2 : int = 282

let S_FIRE1 : int = 281

let S_VILE_DIE10 : int = 280

let S_VILE_DIE9 : int = 279

let S_VILE_DIE8 : int = 278

let S_VILE_DIE7 : int = 277

let S_VILE_DIE6 : int = 276

let S_VILE_DIE5 : int = 275

let S_VILE_DIE4 : int = 274

let S_VILE_DIE3 : int = 273

let S_VILE_DIE2 : int = 272

let S_VILE_DIE1 : int = 271

let S_VILE_PAIN2 : int = 270

let S_VILE_PAIN : int = 269

let S_VILE_HEAL3 : int = 268

let S_VILE_HEAL2 : int = 267

let S_VILE_HEAL1 : int = 266

let S_VILE_ATK11 : int = 265

let S_VILE_ATK10 : int = 264

let S_VILE_ATK9 : int = 263

let S_VILE_ATK8 : int = 262

let S_VILE_ATK7 : int = 261

let S_VILE_ATK6 : int = 260

let S_VILE_ATK5 : int = 259

let S_VILE_ATK4 : int = 258

let S_VILE_ATK3 : int = 257

let S_VILE_ATK2 : int = 256

let S_VILE_ATK1 : int = 255

let S_VILE_RUN12 : int = 254

let S_VILE_RUN11 : int = 253

let S_VILE_RUN10 : int = 252

let S_VILE_RUN9 : int = 251

let S_VILE_RUN8 : int = 250

let S_VILE_RUN7 : int = 249

let S_VILE_RUN6 : int = 248

let S_VILE_RUN5 : int = 247

let S_VILE_RUN4 : int = 246

let S_VILE_RUN3 : int = 245

let S_VILE_RUN2 : int = 244

let S_VILE_RUN1 : int = 243

let S_VILE_STND2 : int = 242

let S_VILE_STND : int = 241

let S_SPOS_RAISE5 : int = 240

let S_SPOS_RAISE4 : int = 239

let S_SPOS_RAISE3 : int = 238

let S_SPOS_RAISE2 : int = 237

let S_SPOS_RAISE1 : int = 236

let S_SPOS_XDIE9 : int = 235

let S_SPOS_XDIE8 : int = 234

let S_SPOS_XDIE7 : int = 233

let S_SPOS_XDIE6 : int = 232

let S_SPOS_XDIE5 : int = 231

let S_SPOS_XDIE4 : int = 230

let S_SPOS_XDIE3 : int = 229

let S_SPOS_XDIE2 : int = 228

let S_SPOS_XDIE1 : int = 227

let S_SPOS_DIE5 : int = 226

let S_SPOS_DIE4 : int = 225

let S_SPOS_DIE3 : int = 224

let S_SPOS_DIE2 : int = 223

let S_SPOS_DIE1 : int = 222

let S_SPOS_PAIN2 : int = 221

let S_SPOS_PAIN : int = 220

let S_SPOS_ATK3 : int = 219

let S_SPOS_ATK2 : int = 218

let S_SPOS_ATK1 : int = 217

let S_SPOS_RUN8 : int = 216

let S_SPOS_RUN7 : int = 215

let S_SPOS_RUN6 : int = 214

let S_SPOS_RUN5 : int = 213

let S_SPOS_RUN4 : int = 212

let S_SPOS_RUN3 : int = 211

let S_SPOS_RUN2 : int = 210

let S_SPOS_RUN1 : int = 209

let S_SPOS_STND2 : int = 208

let S_SPOS_STND : int = 207

let S_POSS_RAISE4 : int = 206

let S_POSS_RAISE3 : int = 205

let S_POSS_RAISE2 : int = 204

let S_POSS_RAISE1 : int = 203

let S_POSS_XDIE9 : int = 202

let S_POSS_XDIE8 : int = 201

let S_POSS_XDIE7 : int = 200

let S_POSS_XDIE6 : int = 199

let S_POSS_XDIE5 : int = 198

let S_POSS_XDIE4 : int = 197

let S_POSS_XDIE3 : int = 196

let S_POSS_XDIE2 : int = 195

let S_POSS_XDIE1 : int = 194

let S_POSS_DIE5 : int = 193

let S_POSS_DIE4 : int = 192

let S_POSS_DIE3 : int = 191

let S_POSS_DIE2 : int = 190

let S_POSS_DIE1 : int = 189

let S_POSS_PAIN2 : int = 188

let S_POSS_PAIN : int = 187

let S_POSS_ATK3 : int = 186

let S_POSS_ATK2 : int = 185

let S_POSS_ATK1 : int = 184

let S_POSS_RUN8 : int = 183

let S_POSS_RUN7 : int = 182

let S_POSS_RUN6 : int = 181

let S_POSS_RUN5 : int = 180

let S_POSS_RUN4 : int = 179

let S_POSS_RUN3 : int = 178

let S_POSS_RUN2 : int = 177

let S_POSS_RUN1 : int = 176

let S_POSS_STND2 : int = 175

let S_POSS_STND : int = 174

let S_PLAY_XDIE9 : int = 173

let S_PLAY_XDIE8 : int = 172

let S_PLAY_XDIE7 : int = 171

let S_PLAY_XDIE6 : int = 170

let S_PLAY_XDIE5 : int = 169

let S_PLAY_XDIE4 : int = 168

let S_PLAY_XDIE3 : int = 167

let S_PLAY_XDIE2 : int = 166

let S_PLAY_XDIE1 : int = 165

let S_PLAY_DIE7 : int = 164

let S_PLAY_DIE6 : int = 163

let S_PLAY_DIE5 : int = 162

let S_PLAY_DIE4 : int = 161

let S_PLAY_DIE3 : int = 160

let S_PLAY_DIE2 : int = 159

let S_PLAY_DIE1 : int = 158

let S_PLAY_PAIN2 : int = 157

let S_PLAY_PAIN : int = 156

let S_PLAY_ATK2 : int = 155

let S_PLAY_ATK1 : int = 154

let S_PLAY_RUN4 : int = 153

let S_PLAY_RUN3 : int = 152

let S_PLAY_RUN2 : int = 151

let S_PLAY_RUN1 : int = 150

let S_PLAY : int = 149

let S_IFOG5 : int = 148

let S_IFOG4 : int = 147

let S_IFOG3 : int = 146

let S_IFOG2 : int = 145

let S_IFOG02 : int = 144

let S_IFOG01 : int = 143

let S_IFOG : int = 142

let S_TFOG10 : int = 141

let S_TFOG9 : int = 140

let S_TFOG8 : int = 139

let S_TFOG7 : int = 138

let S_TFOG6 : int = 137

let S_TFOG5 : int = 136

let S_TFOG4 : int = 135

let S_TFOG3 : int = 134

let S_TFOG2 : int = 133

let S_TFOG02 : int = 132

let S_TFOG01 : int = 131

let S_TFOG : int = 130

let S_EXPLODE3 : int = 129

let S_EXPLODE2 : int = 128

let S_EXPLODE1 : int = 127

let S_BFGEXP4 : int = 126

let S_BFGEXP3 : int = 125

let S_BFGEXP2 : int = 124

let S_BFGEXP : int = 123

let S_BFGLAND6 : int = 122

let S_BFGLAND5 : int = 121

let S_BFGLAND4 : int = 120

let S_BFGLAND3 : int = 119

let S_BFGLAND2 : int = 118

let S_BFGLAND : int = 117

let S_BFGSHOT2 : int = 116

let S_BFGSHOT : int = 115

let S_ROCKET : int = 114

let S_PLASEXP5 : int = 113

let S_PLASEXP4 : int = 112

let S_PLASEXP3 : int = 111

let S_PLASEXP2 : int = 110

let S_PLASEXP : int = 109

let S_PLASBALL2 : int = 108

let S_PLASBALL : int = 107

let S_RBALLX3 : int = 106

let S_RBALLX2 : int = 105

let S_RBALLX1 : int = 104

let S_RBALL2 : int = 103

let S_RBALL1 : int = 102

let S_TBALLX3 : int = 101

let S_TBALLX2 : int = 100

let S_TBALLX1 : int = 99

let S_TBALL2 : int = 98

let S_TBALL1 : int = 97

let S_PUFF4 : int = 96

let S_PUFF3 : int = 95

let S_PUFF2 : int = 94

let S_PUFF1 : int = 93

let S_BLOOD3 : int = 92

let S_BLOOD2 : int = 91

let S_BLOOD1 : int = 90

let S_BFGFLASH2 : int = 89

let S_BFGFLASH1 : int = 88

let S_BFG4 : int = 87

let S_BFG3 : int = 86

let S_BFG2 : int = 85

let S_BFG1 : int = 84

let S_BFGUP : int = 83

let S_BFGDOWN : int = 82

let S_BFG : int = 81

let S_PLASMAFLASH2 : int = 80

let S_PLASMAFLASH1 : int = 79

let S_PLASMA2 : int = 78

let S_PLASMA1 : int = 77

let S_PLASMAUP : int = 76

let S_PLASMADOWN : int = 75

let S_PLASMA : int = 74

let S_SAW3 : int = 73

let S_SAW2 : int = 72

let S_SAW1 : int = 71

let S_SAWUP : int = 70

let S_SAWDOWN : int = 69

let S_SAWB : int = 68

let S_SAW : int = 67

let S_MISSILEFLASH4 : int = 66

let S_MISSILEFLASH3 : int = 65

let S_MISSILEFLASH2 : int = 64

let S_MISSILEFLASH1 : int = 63

let S_MISSILE3 : int = 62

let S_MISSILE2 : int = 61

let S_MISSILE1 : int = 60

let S_MISSILEUP : int = 59

let S_MISSILEDOWN : int = 58

let S_MISSILE : int = 57

let S_CHAINFLASH2 : int = 56

let S_CHAINFLASH1 : int = 55

let S_CHAIN3 : int = 54

let S_CHAIN2 : int = 53

let S_CHAIN1 : int = 52

let S_CHAINUP : int = 51

let S_CHAINDOWN : int = 50

let S_CHAIN : int = 49

let S_DSGUNFLASH2 : int = 48

let S_DSGUNFLASH1 : int = 47

let S_DSNR2 : int = 46

let S_DSNR1 : int = 45

let S_DSGUN10 : int = 44

let S_DSGUN9 : int = 43

let S_DSGUN8 : int = 42

let S_DSGUN7 : int = 41

let S_DSGUN6 : int = 40

let S_DSGUN5 : int = 39

let S_DSGUN4 : int = 38

let S_DSGUN3 : int = 37

let S_DSGUN2 : int = 36

let S_DSGUN1 : int = 35

let S_DSGUNUP : int = 34

let S_DSGUNDOWN : int = 33

let S_DSGUN : int = 32

let S_SGUNFLASH2 : int = 31

let S_SGUNFLASH1 : int = 30

let S_SGUN9 : int = 29

let S_SGUN8 : int = 28

let S_SGUN7 : int = 27

let S_SGUN6 : int = 26

let S_SGUN5 : int = 25

let S_SGUN4 : int = 24

let S_SGUN3 : int = 23

let S_SGUN2 : int = 22

let S_SGUN1 : int = 21

let S_SGUNUP : int = 20

let S_SGUNDOWN : int = 19

let S_SGUN : int = 18

let S_PISTOLFLASH : int = 17

let S_PISTOL4 : int = 16

let S_PISTOL3 : int = 15

let S_PISTOL2 : int = 14

let S_PISTOL1 : int = 13

let S_PISTOLUP : int = 12

let S_PISTOLDOWN : int = 11

let S_PISTOL : int = 10

let S_PUNCH5 : int = 9

let S_PUNCH4 : int = 8

let S_PUNCH3 : int = 7

let S_PUNCH2 : int = 6

let S_PUNCH1 : int = 5

let S_PUNCHUP : int = 4

let S_PUNCHDOWN : int = 3

let S_PUNCH : int = 2

let S_LIGHTDONE : int = 1

let S_NULL : int = 0

let NUMMOBJTYPES : int = 137

let MT_MISC86 : int = 136

let MT_MISC85 : int = 135

let MT_MISC84 : int = 134

let MT_MISC83 : int = 133

let MT_MISC82 : int = 132

let MT_MISC81 : int = 131

let MT_MISC80 : int = 130

let MT_MISC79 : int = 129

let MT_MISC78 : int = 128

let MT_MISC77 : int = 127

let MT_MISC76 : int = 126

let MT_MISC75 : int = 125

let MT_MISC74 : int = 124

let MT_MISC73 : int = 123

let MT_MISC72 : int = 122

let MT_MISC71 : int = 121

let MT_MISC70 : int = 120

let MT_MISC69 : int = 119

let MT_MISC68 : int = 118

let MT_MISC67 : int = 117

let MT_MISC66 : int = 116

let MT_MISC65 : int = 115

let MT_MISC64 : int = 114

let MT_MISC63 : int = 113

let MT_MISC62 : int = 112

let MT_MISC61 : int = 111

let MT_MISC60 : int = 110

let MT_MISC59 : int = 109

let MT_MISC58 : int = 108

let MT_MISC57 : int = 107

let MT_MISC56 : int = 106

let MT_MISC55 : int = 105

let MT_MISC54 : int = 104

let MT_MISC53 : int = 103

let MT_MISC52 : int = 102

let MT_MISC51 : int = 101

let MT_MISC50 : int = 100

let MT_MISC49 : int = 99

let MT_MISC48 : int = 98

let MT_MISC47 : int = 97

let MT_MISC46 : int = 96

let MT_MISC45 : int = 95

let MT_MISC44 : int = 94

let MT_MISC43 : int = 93

let MT_MISC42 : int = 92

let MT_MISC41 : int = 91

let MT_MISC40 : int = 90

let MT_MISC39 : int = 89

let MT_MISC38 : int = 88

let MT_MISC37 : int = 87

let MT_MISC36 : int = 86

let MT_MISC35 : int = 85

let MT_MISC34 : int = 84

let MT_MISC33 : int = 83

let MT_MISC32 : int = 82

let MT_MISC31 : int = 81

let MT_MISC30 : int = 80

let MT_MISC29 : int = 79

let MT_SUPERSHOTGUN : int = 78

let MT_SHOTGUN : int = 77

let MT_MISC28 : int = 76

let MT_MISC27 : int = 75

let MT_MISC26 : int = 74

let MT_CHAINGUN : int = 73

let MT_MISC25 : int = 72

let MT_MISC24 : int = 71

let MT_MISC23 : int = 70

let MT_MISC22 : int = 69

let MT_MISC21 : int = 68

let MT_MISC20 : int = 67

let MT_MISC19 : int = 66

let MT_MISC18 : int = 65

let MT_MISC17 : int = 64

let MT_CLIP : int = 63

let MT_MEGA : int = 62

let MT_MISC16 : int = 61

let MT_MISC15 : int = 60

let MT_MISC14 : int = 59

let MT_INS : int = 58

let MT_MISC13 : int = 57

let MT_INV : int = 56

let MT_MISC12 : int = 55

let MT_MISC11 : int = 54

let MT_MISC10 : int = 53

let MT_MISC9 : int = 52

let MT_MISC8 : int = 51

let MT_MISC7 : int = 50

let MT_MISC6 : int = 49

let MT_MISC5 : int = 48

let MT_MISC4 : int = 47

let MT_MISC3 : int = 46

let MT_MISC2 : int = 45

let MT_MISC1 : int = 44

let MT_MISC0 : int = 43

let MT_EXTRABFG : int = 42

let MT_TELEPORTMAN : int = 41

let MT_IFOG : int = 40

let MT_TFOG : int = 39

let MT_BLOOD : int = 38

let MT_PUFF : int = 37

let MT_ARACHPLAZ : int = 36

let MT_BFG : int = 35

let MT_PLASMA : int = 34

let MT_ROCKET : int = 33

let MT_HEADSHOT : int = 32

let MT_TROOPSHOT : int = 31

let MT_BARREL : int = 30

let MT_SPAWNFIRE : int = 29

let MT_SPAWNSHOT : int = 28

let MT_BOSSTARGET : int = 27

let MT_BOSSSPIT : int = 26

let MT_BOSSBRAIN : int = 25

let MT_KEEN : int = 24

let MT_WOLFSS : int = 23

let MT_PAIN : int = 22

let MT_CYBORG : int = 21

let MT_BABY : int = 20

let MT_SPIDER : int = 19

let MT_SKULL : int = 18

let MT_KNIGHT : int = 17

let MT_BRUISERSHOT : int = 16

let MT_BRUISER : int = 15

let MT_HEAD : int = 14

let MT_SHADOWS : int = 13

let MT_SERGEANT : int = 12

let MT_TROOP : int = 11

let MT_CHAINGUY : int = 10

let MT_FATSHOT : int = 9

let MT_FATSO : int = 8

let MT_SMOKE : int = 7

let MT_TRACER : int = 6

let MT_UNDEAD : int = 5

let MT_FIRE : int = 4

let MT_VILE : int = 3

let MT_SHOTGUY : int = 2

let MT_POSSESSED : int = 1

let MT_PLAYER : int = 0

let PST_REBORN : int = 2

let PST_DEAD : int = 1

let PST_LIVE : int = 0

let ST_NEGATIVE : int = 3

let ST_POSITIVE : int = 2

let ST_VERTICAL : int = 1

let ST_HORIZONTAL : int = 0

let RIGHT : int = 2

let LEFT : int = 1

let BOTTOM : int = 4

let TOP : int = 8

let none_0 : int = 9

let strife : int = 8

let hexen : int = 7

let heretic : int = 6

let pack_hacx : int = 5

let pack_chex : int = 4

let pack_plut : int = 3

let pack_tnt : int = 2

let doom2 : int = 1

let doom : int = 0

let indetermined : int = 4

let retail : int = 3

let commercial : int = 2

let registered : int = 1

let shareware : int = 0

let exe_strife_1_31 : int = 13

let exe_strife_1_2 : int = 12

let exe_hexen_1_1 : int = 11

let exe_heretic_1_3 : int = 10

let exe_chex : int = 9

let exe_final2 : int = 8

let exe_final : int = 7

let exe_ultimate : int = 6

let exe_hacx : int = 5

let exe_doom_1_9 : int = 4

let exe_doom_1_8 : int = 3

let exe_doom_1_7 : int = 2

let exe_doom_1_666 : int = 1

let exe_doom_1_2 : int = 0

let am_noammo : int = 5

let NUMAMMO : int = 4

let am_misl : int = 3

let am_cell : int = 2

let am_shell : int = 1

let am_clip : int = 0

let BTS_SAVESHIFT : int = 2

let BTS_SAVEMASK : int = 28

let BTS_SAVEGAME : int = 2

let BTS_PAUSE : int = 1

let BT_WEAPONSHIFT : int = 3

let BT_WEAPONMASK : int = 56

let BT_CHANGE : int = 4

let BT_SPECIALMASK : int = 3

let BT_SPECIAL : int = 128

let BT_USE : int = 2

let BT_ATTACK : int = 1

let sk_nightmare : int = 4

let sk_hard : int = 3

let sk_medium : int = 2

let sk_easy : int = 1

let sk_baby : int = 0

let sk_noitems : int = -1

let GS_DEMOSCREEN : int = 3

let GS_FINALE : int = 2

let GS_INTERMISSION : int = 1

let GS_LEVEL : int = 0

let ga_screenshot : int = 9

let ga_worlddone : int = 8

let ga_victory : int = 7

let ga_completed : int = 6

let ga_playdemo : int = 5

let ga_savegame : int = 4

let ga_loadgame : int = 3

let ga_newgame : int = 2

let ga_loadlevel : int = 1

let ga_nothing : int = 0

let NUMMUSIC : int = 68

let mus_dm2int : int = 67

let mus_dm2ttl : int = 66

let mus_read_m : int = 65

let mus_ultima : int = 64

let mus_evil : int = 63

let mus_openin : int = 62

let mus_shawn3 : int = 61

let mus_tense : int = 60

let mus_romer2 : int = 59

let mus_messg2 : int = 58

let mus_adrian : int = 57

let mus_theda3 : int = 56

let mus_ampie : int = 55

let mus_ddtbl3 : int = 54

let mus_count2 : int = 53

let mus_messag : int = 52

let mus_shawn2 : int = 51

let mus_romero : int = 50

let mus_stlks3 : int = 49

let mus_dead2 : int = 48

let mus_runni2 : int = 47

let mus_ddtbl2 : int = 46

let mus_doom2 : int = 45

let mus_theda2 : int = 44

let mus_stlks2 : int = 43

let mus_dead : int = 42

let mus_in_cit : int = 41

let mus_ddtblu : int = 40

let mus_shawn : int = 39

let mus_the_da : int = 38

let mus_doom : int = 37

let mus_betwee : int = 36

let mus_countd : int = 35

let mus_stalks : int = 34

let mus_runnin : int = 33

let mus_introa : int = 32

let mus_victor : int = 31

let mus_bunny : int = 30

let mus_intro : int = 29

let mus_inter : int = 28

let mus_e3m9 : int = 27

let mus_e3m8 : int = 26

let mus_e3m7 : int = 25

let mus_e3m6 : int = 24

let mus_e3m5 : int = 23

let mus_e3m4 : int = 22

let mus_e3m3 : int = 21

let mus_e3m2 : int = 20

let mus_e3m1 : int = 19

let mus_e2m9 : int = 18

let mus_e2m8 : int = 17

let mus_e2m7 : int = 16

let mus_e2m6 : int = 15

let mus_e2m5 : int = 14

let mus_e2m4 : int = 13

let mus_e2m3 : int = 12

let mus_e2m2 : int = 11

let mus_e2m1 : int = 10

let mus_e1m9 : int = 9

let mus_e1m8 : int = 8

let mus_e1m7 : int = 7

let mus_e1m6 : int = 6

let mus_e1m5 : int = 5

let mus_e1m4 : int = 4

let mus_e1m3 : int = 3

let mus_e1m2 : int = 2

let mus_e1m1 : int = 1

let mus_None : int = 0

let wipe_NUMWIPES : int = 2

let wipe_Melt : int = 1

let wipe_ColorXForm : int = 0

let NUMSFX : int = 109

let sfx_radio : int = 108

let sfx_skeatk : int = 107

let sfx_skesit : int = 106

let sfx_skeact : int = 105

let sfx_keendt : int = 104

let sfx_keenpn : int = 103

let sfx_ssdth : int = 102

let sfx_sssit : int = 101

let sfx_mandth : int = 100

let sfx_manatk : int = 99

let sfx_bosdth : int = 98

let sfx_bospn : int = 97

let sfx_bossit : int = 96

let sfx_boscub : int = 95

let sfx_bospit : int = 94

let sfx_getpow : int = 93

let sfx_flamst : int = 92

let sfx_flame : int = 91

let sfx_itmbk : int = 90

let sfx_bdcls : int = 89

let sfx_bdopn : int = 88

let sfx_tink : int = 87

let sfx_chgun : int = 86

let sfx_metal : int = 85

let sfx_hoof : int = 84

let sfx_punch : int = 83

let sfx_barexp : int = 82

let sfx_noway : int = 81

let sfx_vilact : int = 80

let sfx_bspwlk : int = 79

let sfx_bspact : int = 78

let sfx_dmact : int = 77

let sfx_bgact : int = 76

let sfx_posact : int = 75

let sfx_skedth : int = 74

let sfx_pedth : int = 73

let sfx_kntdth : int = 72

let sfx_vildth : int = 71

let sfx_bspdth : int = 70

let sfx_spidth : int = 69

let sfx_cybdth : int = 68

let sfx_brsdth : int = 67

let sfx_skldth : int = 66

let sfx_cacdth : int = 65

let sfx_sgtdth : int = 64

let sfx_bgdth2 : int = 63

let sfx_bgdth1 : int = 62

let sfx_podth3 : int = 61

let sfx_podth2 : int = 60

let sfx_podth1 : int = 59

let sfx_pdiehi : int = 58

let sfx_pldeth : int = 57

let sfx_skeswg : int = 56

let sfx_claw : int = 55

let sfx_vilatk : int = 54

let sfx_skepch : int = 53

let sfx_sgtatk : int = 52

let sfx_sklatk : int = 51

let sfx_pesit : int = 50

let sfx_mansit : int = 49

let sfx_vilsit : int = 48

let sfx_kntsit : int = 47

let sfx_bspsit : int = 46

let sfx_spisit : int = 45

let sfx_cybsit : int = 44

let sfx_brssit : int = 43

let sfx_cacsit : int = 42

let sfx_sgtsit : int = 41

let sfx_bgsit2 : int = 40

let sfx_bgsit1 : int = 39

let sfx_posit3 : int = 38

let sfx_posit2 : int = 37

let sfx_posit1 : int = 36

let sfx_telept : int = 35

let sfx_oof : int = 34

let sfx_wpnup : int = 33

let sfx_itemup : int = 32

let sfx_slop : int = 31

let sfx_pepain : int = 30

let sfx_mnpain : int = 29

let sfx_vipain : int = 28

let sfx_popain : int = 27

let sfx_dmpain : int = 26

let sfx_plpain : int = 25

let sfx_swtchx : int = 24

let sfx_swtchn : int = 23

let sfx_stnmov : int = 22

let sfx_dorcls : int = 21

let sfx_doropn : int = 20

let sfx_pstop : int = 19

let sfx_pstart : int = 18

let sfx_firxpl : int = 17

let sfx_firsht : int = 16

let sfx_rxplod : int = 15

let sfx_rlaunc : int = 14

let sfx_sawhit : int = 13

let sfx_sawful : int = 12

let sfx_sawidl : int = 11

let sfx_sawup : int = 10

let sfx_bfg : int = 9

let sfx_plasma : int = 8

let sfx_dbload : int = 7

let sfx_dbcls : int = 6

let sfx_dbopn : int = 5

let sfx_dshtgn : int = 4

let sfx_sgcock : int = 3

let sfx_shotgn : int = 2

let sfx_pistol : int = 1

let sfx_None : int = 0

let F_STAGE_CAST : int = 2

let F_STAGE_ARTSCREEN : int = 1

let F_STAGE_TEXT : int = 0

let MF_TRANSSHIFT : int = 26

let MF_TRANSLATION : int = 201326592

let MF_NOTDMATCH : int = 33554432

let MF_SKULLFLY : int = 16777216

let MF_COUNTITEM : int = 8388608

let MF_COUNTKILL : int = 4194304

let MF_INFLOAT : int = 2097152

let MF_CORPSE : int = 1048576

let MF_NOBLOOD : int = 524288

let MF_SHADOW : int = 262144

let MF_DROPPED : int = 131072

let MF_MISSILE : int = 65536

let MF_TELEPORT : int = 32768

let MF_FLOAT : int = 16384

let MF_SLIDE : int = 8192

let MF_NOCLIP : int = 4096

let MF_PICKUP : int = 2048

let MF_DROPOFF : int = 1024

let MF_NOGRAVITY : int = 512

let MF_SPAWNCEILING : int = 256

let MF_JUSTATTACKED : int = 128

let MF_JUSTHIT : int = 64

let MF_AMBUSH : int = 32

let MF_NOBLOCKMAP : int = 16

let MF_NOSECTOR : int = 8

let MF_SHOOTABLE : int = 4

let MF_SOLID : int = 2

let MF_SPECIAL : int = 1

let SNDDEVICE_CD : int = 10

let SNDDEVICE_AWE32 : int = 9

let SNDDEVICE_GENMIDI : int = 8

let SNDDEVICE_SOUNDCANVAS : int = 7

let SNDDEVICE_WAVEBLASTER : int = 6

let SNDDEVICE_GUS : int = 5

let SNDDEVICE_PAS : int = 4

let SNDDEVICE_SB : int = 3

let SNDDEVICE_ADLIB : int = 2

let SNDDEVICE_PCSPEAKER : int = 1

let SNDDEVICE_NONE : int = 0

let MODE_WRITE : int = 1

let MODE_READ : int = 0

let MEM_SEEK_END : int = 2

let MEM_SEEK_CUR : int = 1

let MEM_SEEK_SET : int = 0

let BOXRIGHT : int = 3

let BOXLEFT : int = 2

let BOXBOTTOM : int = 1

let BOXTOP : int = 0

let DEFAULT_KEY : int = 4

let DEFAULT_FLOAT : int = 3

let DEFAULT_STRING : int = 2

let DEFAULT_INT_HEX : int = 1

let DEFAULT_INT : int = 0

let read2_end : int = 1

let read1_end : int = 1

let load_end : int = 6

let scrnsize : int = 3

let mousesens : int = 5

let messages : int = 1

let detail : int = 2

let music_vol : int = 2

let sfx_vol : int = 0

let sound_end : int = 4

let opt_end : int = 8

let ep1 : int = 0

let hurtme : int = 2

let nightmare : int = 4

let newg_end : int = 5

let ep_end : int = 4

let main_end : int = 6

let quitdoom : int = 5

let readthis : int = 4

let savegame : int = 3

let loadgame : int = 2

let options_0 : int = 1

let newgame : int = 0

let ep4 : int = 3

let ep3 : int = 2

let ep2 : int = 1

let violence : int = 3

let toorough : int = 1

let killthings : int = 0

let soundvol : int = 7

let option_empty2 : int = 6

let option_empty1 : int = 4

let endgame : int = 0

let rdthsempty1 : int = 0

let rdthsempty2 : int = 0

let sfx_empty2 : int = 3

let sfx_empty1 : int = 1

let load6 : int = 5

let load5 : int = 4

let load4 : int = 3

let load3 : int = 2

let load2 : int = 1

let load1 : int = 0

let silentCrushAndRaise : int = 5

let fastCrushAndRaise : int = 4

let crushAndRaise : int = 3

let lowerAndCrush : int = 2

let raiseToHighest : int = 1

let lowerToFloor : int = 0

let crushed : int = 1

let pastdest : int = 2

let ok : int = 0

let NUMCARDS : int = 6

let it_redskull : int = 5

let it_yellowskull : int = 4

let it_blueskull : int = 3

let it_redcard : int = 2

let it_yellowcard : int = 1

let it_bluecard : int = 0

let in_stasis : int = 3

let waiting : int = 2

let down : int = 1

let up : int = 0

let blazeDWUS : int = 4

let raiseToNearestAndChange : int = 3

let raiseAndChange : int = 2

let downWaitUpStay : int = 1

let perpetualRaise : int = 0

let vld_blazeClose : int = 7

let vld_blazeOpen : int = 6

let vld_blazeRaise : int = 5

let vld_raiseIn5Mins : int = 4

let vld_open : int = 3

let vld_close : int = 2

let vld_close30ThenOpen : int = 1

let vld_normal : int = 0

let raiseFloor512 : int = 12

let donutRaise : int = 11

let raiseFloorTurbo : int = 10

let raiseFloorCrush : int = 9

let raiseFloor24AndChange : int = 8

let raiseFloor24 : int = 7

let lowerAndChange : int = 6

let raiseToTexture : int = 5

let raiseFloorToNearest : int = 4

let raiseFloor : int = 3

let turboLower : int = 2

let lowerFloorToLowest : int = 1

let lowerFloor : int = 0

let NUMDIRS : int = 9

let DI_NODIR : int = 8

let DI_SOUTHEAST : int = 7

let DI_SOUTH : int = 6

let DI_SOUTHWEST : int = 5

let DI_WEST : int = 4

let DI_NORTHWEST : int = 3

let DI_NORTH : int = 2

let DI_NORTHEAST : int = 1

let DI_EAST : int = 0

let turbo16 : int = 1

let build8 : int = 0

let IRONTICS : int = 2100

let INFRATICS : int = 4200

let INVISTICS : int = 2100

let INVULNTICS : int = 1050

let CF_NOMOMENTUM : int = 4

let CF_GODMODE : int = 2

let CF_NOCLIP : int = 1

let NUMPSPRITES : int = 2

let ps_flash : int = 1

let ps_weapon : int = 0

let tc_end : int = 0

let tc_mobj : int = 1

let tc_endspecials : int = 7

let tc_glow : int = 6

let tc_strobe : int = 5

let tc_flash : int = 4

let tc_plat : int = 3

let tc_floor : int = 2

let tc_door : int = 1

let tc_ceiling : int = 0

let ML_BLOCKMAP : int = 10

let ML_REJECT : int = 9

let ML_SECTORS : int = 8

let ML_NODES : int = 7

let ML_SSECTORS : int = 6

let ML_SEGS : int = 5

let ML_VERTEXES : int = 4

let ML_SIDEDEFS : int = 3

let ML_LINEDEFS : int = 2

let ML_THINGS : int = 1

let ML_LABEL : int = 0

let bottom : int = 2

let middle : int = 1

let top : int = 0

let FirstPersonState : int = 1

let AutomapState : int = 0

let GetChatState : int = 2

let WaitDestState : int = 1

let StartChatState : int = 0

let ShowNextLoc : int = 1

let StatCount : int = 0

let NoState : int = -1

let ANIM_LEVEL : int = 2

let ANIM_RANDOM : int = 1

let ANIM_ALWAYS : int = 0

var c2da_std_errno_cell : uint64 = c2da_std_cell_alloc()

var c2da_std_io_byte : uint64 = c2da_std_cell_alloc()

var c2da_std_lost_bytes : int = 0

var c2da_std_stream_fd : array<int>

var c2da_std_stream_flags : array<int>

var c2da_std_stream_keys : array<uint64>

var c2da_std_stream_next_fd : int = 3

var c2da_std_stream_push : array<int>

[sideeffects]
def c2da_std_abs(x : int) : int {
    if (x < 0) {
        return 0 - x
    }
    return x
}
[sideeffects]
def c2da_std_arg_f64(args : array<C2daVaArg>; index : int) : double {
    if (index < 0 || index >= length(args)) {
        return 0.0lf
    }
    let item = args[index]
    if (item.tag == 2) {
        return item.f64
    }
    return double(item.i64)
}
[sideeffects]
def c2da_std_arg_i64(args : array<C2daVaArg>; index : int) : int64 {
    if (index < 0 || index >= length(args)) {
        return 0l
    }
    let item = args[index]
    if (item.tag == 2) {
        return int64(item.f64)
    }
    if (item.tag == 3) {
        return int64(item.raw)
    }
    return item.i64
}
[sideeffects]
def c2da_std_arg_u64(args : array<C2daVaArg>; index : int) : uint64 {
    if (index < 0 || index >= length(args)) {
        return 0x0ul
    }
    let item = args[index]
    if (item.tag == 3) {
        return item.raw
    }
    if (item.tag == 2) {
        return uint64(item.f64)
    }
    return uint64(item.i64)
}
[sideeffects]
def c2da_std_atof(nptr : uint64) : double {
    return c2da_std_strtod(nptr, 0x0ul)
}
[sideeffects]
def c2da_std_atoi(nptr : uint64) : int {
    return int(int64(c2da_std_strto(nptr, 0x0ul, 10, 0x7ffffffffffffffful, 0x8000000000000000ul)))
}
[sideeffects]
def c2da_std_byte(s : int8 const?; index : int) : int {
    if (s == null) {
        return 0
    }
    return int(unsafe(s[index])) & 255
}
[sideeffects]
def c2da_std_cell_alloc() : uint64 {
    let raw : uint64 = c2da_rt_malloc(0xcul)
    if (raw == 0x0ul) {
        panic("--libc std prelude: the raw heap is exhausted")
    }
    let aligned : uint64 = (raw + 0x7ul) / 0x8ul * 0x8ul
    c2da_std_raw_put(aligned, 0x0ul, 0)
    c2da_std_raw_put(aligned, 0x1ul, 0)
    c2da_std_raw_put(aligned, 0x2ul, 0)
    c2da_std_raw_put(aligned, 0x3ul, 0)
    return aligned
}
[sideeffects]
def c2da_std_digit(ch : int; base : int) : int {
    var v : int = -1
    if (is_number(ch)) {
        v = ch - 48
    } elif (ch >= 97 && ch <= 122) {
        v = ch - 97 + 10
    } elif (ch >= 65 && ch <= 90) {
        v = ch - 65 + 10
    }
    if (v < 0 || v >= base) {
        return -1
    }
    return v
}
[sideeffects]
def c2da_std_errno_location() : uint64 {
    return c2da_std_errno_cell
}
[sideeffects]
def c2da_std_exit(code : int) {
    unsafe(exit_now(code))
}
[sideeffects]
def c2da_std_fabs(x : double) : double {
    return unsafe(reinterpret<double>(unsafe(reinterpret<uint64>(x)) & 0x7ffffffffffffffful))
}
[sideeffects]
def c2da_std_fclose(handle : uint64) : int {
    if (handle == 0x0ul) {
        c2da_std_set_errno(9)
        return -1
    }
    fclose(c2da_std_file(handle))
    let slot = c2da_std_stream_slot(handle)
    c2da_std_stream_flags[slot] = 0
    c2da_std_stream_push[slot] = -1
    c2da_std_stream_fd[slot] = -1
    return 0
}
[sideeffects]
def c2da_std_fflush(handle : uint64) : int {
    if (handle == 0x0ul) {
        fflush(c2da_std_file(c2da_std_stdout()))
        fflush(c2da_std_file(c2da_std_stderr()))
    } else {
        fflush(c2da_std_file(handle))
    }
    return 0
}
[sideeffects]
def c2da_std_file(handle : uint64) : FILE const? {
    return unsafe(reinterpret<FILE const?>(handle))
}
[sideeffects]
def c2da_std_fopen(path : int8 const?; mode : int8 const?) : uint64 {
    let spelled : string = c2da_std_string(mode)
    if (empty(spelled)) {
        c2da_std_set_errno(22)
        return 0x0ul
    }
    let head = first_character(spelled)
    if (head != 114 && (head != 119 && head != 97)) {
        c2da_std_set_errno(22)
        return 0x0ul
    }
    let accepted : string = build_string($(var writer : StringBuilderWriter) {
        write_char(writer, head)
        var k : int = 1
        while (k < length(spelled)) {
            let letter = unsafe(character_uat(spelled, k))
            if (letter == 44) {
                break
            }
            if (letter == 43 || (letter == 98 || (letter == 116 || letter == 120))) {
                write_char(writer, letter)
            }
            k++
        }
    })
    var opened : FILE const? = fopen(c2da_std_string(path), accepted)
    if (opened == null) {
        c2da_std_fopen_errno(path)
        return 0x0ul
    }
    let handle : uint64 = unsafe(reinterpret<uint64>(opened))
    c2da_std_stream_open(handle)
    return handle
}
[sideeffects]
def c2da_std_fopen_errno(path : int8 const?) {
    c2da_std_path_errno(c2da_std_string(path))
}
[sideeffects]
def c2da_std_format(f : int8 const?; args : array<C2daVaArg>) : string {
    var from : int = 0
    return c2da_std_vformat(f, args, from)
}
[sideeffects]
def c2da_std_fprintf(handle : uint64; f : int8 const?; args : array<C2daVaArg>) : int {
    let body : string = c2da_std_format(f, args)
    c2da_std_write(handle, body)
    return length(body) + c2da_std_lost_bytes
}
[sideeffects]
def c2da_std_fputc(ch : int; handle : uint64) : int {
    if (handle == 0x0ul) {
        return -1
    }
    c2da_std_raw_put(c2da_std_io_byte, 0x0ul, ch)
    var buffer : uint8? = unsafe(reinterpret<uint8?>(c2da_std_io_byte))
    let wrote : int = _builtin_write(c2da_std_file(handle), buffer, 1)
    if (wrote != 1) {
        c2da_std_stream_fail(handle)
        return -1
    }
    return ch & 255
}
[sideeffects]
def c2da_std_fread(dst : uint64; size : uint64; count : uint64; handle : uint64) : uint64 {
    if (handle == 0x0ul || dst == 0x0ul || size == 0x0ul || count == 0x0ul) {
        return 0x0ul
    }
    if (count > 0xfffffffffffffffful / size) {
        c2da_std_set_errno(12)
        return 0x0ul
    }
    var total : uint64 = size * count
    if (total > 0x7ffffffffffffffful) {
        c2da_std_set_errno(12)
        return 0x0ul
    }
    let pushed : int = c2da_std_stream_take_push(handle)
    var head : uint64 = 0x0ul
    if (pushed >= 0) {
        c2da_std_raw_put(dst, 0x0ul, pushed)
        head = 0x1ul
        total--
    }
    if (total == 0x0ul) {
        return head / size
    }
    var buffer : uint8? = unsafe(reinterpret<uint8?>(dst + head))
    let got : int64 = _builtin_read64(c2da_std_file(handle), buffer, int64(total))
    if (got < 0l) {
        c2da_std_stream_fail(handle)
        return head / size
    }
    return (head + uint64(got)) / size
}
[sideeffects]
def c2da_std_fseek(handle : uint64; offset : int64; whence : int) : int {
    if (handle == 0x0ul) {
        return -1
    }
    if (whence < 0 || whence > 2) {
        c2da_std_set_errno(22)
        return -1
    }
    if (whence == 0 && offset < 0l) {
        c2da_std_set_errno(22)
        return -1
    }
    let slot = c2da_std_stream_slot(handle)
    c2da_std_stream_push[slot] = -1
    var mode : int = seek_set
    if (whence == 1) {
        mode = seek_cur
    } elif (whence == 2) {
        mode = seek_end
    }
    let moved : int64 = fseek(c2da_std_file(handle), offset, mode)
    if (moved != 0l) {
        return -1
    }
    return 0
}
[sideeffects]
def c2da_std_ftell(handle : uint64) : int64 {
    if (handle == 0x0ul) {
        return -1l
    }
    return ftell(c2da_std_file(handle))
}
[sideeffects]
def c2da_std_fwrite(src : uint64; size : uint64; count : uint64; handle : uint64) : uint64 {
    if (handle == 0x0ul || src == 0x0ul) {
        return 0x0ul
    }
    let total : uint64 = size * count
    if (total == 0x0ul) {
        return 0x0ul
    }
    var buffer : uint8? = unsafe(reinterpret<uint8?>(src))
    let wrote : int = _builtin_write(c2da_std_file(handle), buffer, int(total))
    if (wrote < 0 || uint64(wrote) < total) {
        c2da_std_stream_fail(handle)
    }
    if (wrote <= 0) {
        return 0x0ul
    }
    return uint64(wrote) / size
}
[sideeffects]
def c2da_std_huge() : double {
    return to_double("inf")
}
[sideeffects]
def c2da_std_isspace(c : int) : int {
    if (c == 32 || c >= 9 && c <= 13) {
        return 1
    }
    return 0
}
[sideeffects]
def c2da_std_mkdir(path : uint64; mode : uint) : int {
    c2da_std_set_errno(1)
    return -1
}
[sideeffects]
def c2da_std_number(value : uint64; base : int; upper : bool; sign : string; alt : bool; has_precision : bool; precision : int; width : int; left : bool; zero : bool) : string {
    var digits : string = c2da_std_utoa(value, base, upper)
    if (has_precision) {
        if (precision == 0 && value == 0x0ul) {
            digits = ""
        } elif (length(digits) < precision) {
            digits = repeat("0", precision - length(digits)) + digits
        }
    }
    var prefix : string = sign
    if (alt) {
        if (base == 16 && value != 0x0ul) {
            if (upper) {
                prefix += "0X"
            } else {
                prefix += "0x"
            }
        }
        if (base == 8) {
            if (empty(digits)) {
                digits = "0"
            } elif (first_character(digits) != 48) {
                digits = "0" + digits
            }
        }
    }
    let body : string = prefix + digits
    let gap : int = width - length(body)
    if (gap <= 0) {
        return body
    }
    if (left) {
        return body + repeat(" ", gap)
    }
    if (zero && !has_precision) {
        return prefix + repeat("0", gap) + digits
    }
    return repeat(" ", gap) + body
}
[sideeffects]
def c2da_std_pad(body : string; width : int; left : bool) : string {
    let gap : int = width - length(body)
    if (gap <= 0) {
        return body
    }
    let spaces : string = repeat(" ", gap)
    if (left) {
        return body + spaces
    }
    return spaces + body
}
[sideeffects]
def c2da_std_path_errno(path : string) {
    if (!fexist(path)) {
        c2da_std_set_errno(2)
        return
    }
    let info = stat(path)
    if (info.is_dir) {
        c2da_std_set_errno(21)
        return
    }
    c2da_std_set_errno(13)
}
[sideeffects]
def c2da_std_place(dst : uint64; size : uint64; body : string) : int {
    let n : int = length(body)
    if (size != 0x0ul && dst != 0x0ul) {
        let cap : int = int(size) - 1
        var i : int = 0
        while (i < n && i < cap) {
            c2da_std_raw_put(dst, uint64(i), unsafe(character_uat(body, i)))
            i++
        }
        c2da_std_raw_put(dst, uint64(i), 0)
    }
    return n
}
[sideeffects]
def c2da_std_printf(f : int8 const?; args : array<C2daVaArg>) : int {
    let body : string = c2da_std_format(f, args)
    print(body)
    return length(body) + c2da_std_lost_bytes
}
[sideeffects]
def c2da_std_raw_byte(base : uint64; index : uint64) : int {
    if (base == 0x0ul) {
        return 0
    }
    return int(unsafe(unsafe(reinterpret<uint8?>(base))[index])) & 255
}
[sideeffects]
def c2da_std_raw_put(base : uint64; index : uint64; value : int) {
    if (base == 0x0ul) {
        return
    }
    unsafe(unsafe(reinterpret<uint8?>(base))[index]) = uint8(value & 255)
}
[sideeffects]
def c2da_std_raw_string(base : uint64) : string {
    if (base == 0x0ul) {
        return ""
    }
    return build_string($(var writer : StringBuilderWriter) {
        var i : uint64 = 0x0ul
        while (true) {
            let b = c2da_std_raw_byte(base, i)
            if (b == 0) {
                break
            }
            write_char(writer, b)
            i++
        }
    })
}
[sideeffects]
def c2da_std_remove(path : uint64) : int {
    let name : string = c2da_std_raw_string(path)
    if (remove(name)) {
        return 0
    }
    c2da_std_path_errno(name)
    return -1
}
[sideeffects]
def c2da_std_rename(from : uint64; to : uint64) : int {
    let old_name : string = c2da_std_raw_string(from)
    let new_name : string = c2da_std_raw_string(to)
    if (rename(old_name, new_name)) {
        return 0
    }
    c2da_std_path_errno(old_name)
    return -1
}
[sideeffects]
def c2da_std_set_errno(code : int) {
    var cell : uint64 = c2da_std_errno_location()
    unsafe(unsafe(reinterpret<int?>(cell))[0]) = int(code)  // nolint:PERF020
}
[sideeffects]
def c2da_std_setvbuf(handle : uint64; buffer : uint64; mode : int; size : uint64) : int {
    if (handle == 0x0ul) {
        return -1
    }
    if (mode == 2) {
        funbuffered(c2da_std_file(handle))
    }
    return 0
}
[sideeffects]
def c2da_std_snprintf(dst : uint64; size : uint64; f : int8 const?; args : array<C2daVaArg>) : int {
    let placed : int = c2da_std_place(dst, size, c2da_std_format(f, args))
    return placed + c2da_std_lost_bytes
}
[sideeffects]
def c2da_std_sscanf(s : uint64; f : uint64; args : array<C2daVaArg>) : int {
    var done : int = 0
    var arg : int = 0
    var i : uint64 = 0x0ul
    var p : uint64 = 0x0ul
    while (true) {
        let fc = c2da_std_raw_byte(f, i)
        if (fc == 0) {
            break
        }
        if (c2da_std_isspace(fc) != 0) {
            while (c2da_std_isspace(c2da_std_raw_byte(f, i)) != 0) {
                i++
            }
            while (c2da_std_isspace(c2da_std_raw_byte(s, p)) != 0) {
                p++
            }
            continue
        }
        if (fc != 37) {
            let oc = c2da_std_raw_byte(s, p)
            if (oc == 0) {
                if (done == 0) {
                    return -1
                }
                return done
            }
            if (oc != fc) {
                return done
            }
            p++
            i++
            continue
        }
        let conv = c2da_std_raw_byte(f, i + 0x1ul)
        if (conv == 37) {
            while (c2da_std_isspace(c2da_std_raw_byte(s, p)) != 0) {
                p++
            }
            let pc = c2da_std_raw_byte(s, p)
            if (pc == 0) {
                if (done == 0) {
                    return -1
                }
                return done
            }
            if (pc != 37) {
                return done
            }
            p++
            i += 0x2ul
            continue
        }
        var base : int = -1
        var signed_conv : bool = false
        if (conv == 100) {
            base = 10
            signed_conv = true
        } elif (conv == 105) {
            base = 0
            signed_conv = true
        } elif (conv == 111) {
            base = 8
            signed_conv = false
        } elif (conv == 117) {
            base = 10
            signed_conv = false
        } elif (conv == 120 || conv == 88) {
            base = 16
            signed_conv = false
        }
        if (base < 0) {
            var j : uint64 = i + 0x1ul
            while (true) {
                let sb = c2da_std_raw_byte(f, j)
                if (!(is_number(sb) || (sb == 42 || sb == 104 || sb == 108 || sb == 76 || sb == 113 || sb == 106 || sb == 122 || sb == 116 || sb == 109 || sb == 39))) {
                    break
                }
                j++
            }
            panic("--libc std: sscanf conversion is not implemented: " + build_string($(var writer : StringBuilderWriter) {
    var k : uint64 = i
    while (k <= j && c2da_std_raw_byte(f, k) != 0) {
        write_char(writer, c2da_std_raw_byte(f, k))
        k++
    }
}))
        }
        i += 0x2ul
        while (c2da_std_isspace(c2da_std_raw_byte(s, p)) != 0) {
            p++
        }
        if (c2da_std_raw_byte(s, p) == 0) {
            if (done == 0) {
                return -1
            }
            return done
        }
        let start : uint64 = p
        var radix : int = base
        var any : bool = false
        var b : int = c2da_std_raw_byte(s, p)
        if (b == 45 || b == 43) {
            p++
            b = c2da_std_raw_byte(s, p)
        }
        if (b == 48) {
            any = true
            p++
            b = c2da_std_raw_byte(s, p)
            if ((b | 32) == 120) {
                if (radix == 0 || radix == 16) {
                    radix = 16
                    p++
                    b = c2da_std_raw_byte(s, p)
                }
            } elif (radix == 0) {
                radix = 8
            }
        } elif (radix == 0) {
            radix = 10
        }
        while (c2da_std_digit(b, radix) >= 0) {
            any = true
            p++
            b = c2da_std_raw_byte(s, p)
        }
        if (!any) {
            return done
        }
        var value : uint64 = 0x0ul
        if (signed_conv) {
            value = c2da_std_strto(s + start, 0x0ul, base, 0x7ffffffffffffffful, 0x8000000000000000ul)
        } else {
            value = c2da_std_strto(s + start, 0x0ul, base, 0xfffffffffffffffful, 0xfffffffffffffffful)
        }
        let cell : uint64 = c2da_std_arg_u64(args, arg)
        if (cell == 0x0ul) {
            panic("--libc std: sscanf has no pointer argument to store a conversion through")
        }
        unsafe(unsafe(reinterpret<uint?>(cell))[0]) = uint(value & 0xfffffffful)
        arg++
        done++
    }
    return done
}
[sideeffects]
def c2da_std_stderr() : uint64 {
    var stream : FILE const? = fstderr()
    return unsafe(reinterpret<uint64>(stream))
}
[sideeffects]
def c2da_std_stdout() : uint64 {
    var stream : FILE const? = fstdout()
    return unsafe(reinterpret<uint64>(stream))
}
[sideeffects]
def c2da_std_store(s : string) : uint64 {
    let n : int = length(s)
    var base : uint64 = c2da_rt_malloc(uint64(n + 1))
    var i : int = 0
    while (i < n) {
        unsafe(unsafe(reinterpret<uint8?>(base))[i]) = uint8(unsafe(character_uat(s, i)) & 255)
        i++
    }
    unsafe(unsafe(reinterpret<uint8?>(base))[n]) = 0u8
    return base
}
[sideeffects]
def c2da_std_store_addr(cell : uint64; value : uint64) {
    if (cell == 0x0ul) {
        return
    }
    unsafe(unsafe(reinterpret<uint64?>(cell))[0]) = uint64(value)  // nolint:PERF020
}
[sideeffects]
def c2da_std_strcasecmp(a : uint64; b : uint64) : int {
    var i : uint64 = 0x0ul
    while (true) {
        let ca = c2da_std_tolower(c2da_std_raw_byte(a, i))
        let cb = c2da_std_tolower(c2da_std_raw_byte(b, i))
        if (ca != cb) {
            return ca - cb
        }
        if (ca == 0) {
            return 0
        }
        i++
    }
    return 0
}
[sideeffects]
def c2da_std_strchr(s : uint64; ch : int) : uint64 {
    if (s == 0x0ul) {
        return 0x0ul
    }
    let target : int = ch & 255
    var i : uint64 = 0x0ul
    while (true) {
        let b = c2da_std_raw_byte(s, i)
        if (b == target) {
            return s + i
        }
        if (b == 0) {
            break
        }
        i++
    }
    return 0x0ul
}
[sideeffects]
def c2da_std_strcmp(a : uint64; b : uint64) : int {
    var i : uint64 = 0x0ul
    while (true) {
        let ca = c2da_std_raw_byte(a, i)
        let cb = c2da_std_raw_byte(b, i)
        if (ca != cb) {
            if (ca < cb) {
                return -1
            }
            return 1
        }
        if (ca == 0) {
            return 0
        }
        i++
    }
    return 0
}
[sideeffects]
def c2da_std_strdup(s : uint64) : uint64 {
    let n : uint64 = c2da_std_strlen(s)
    let base : uint64 = c2da_rt_malloc(n + 0x1ul)
    if (base == 0x0ul) {
        c2da_std_set_errno(12)
        return 0x0ul
    }
    var i : uint64 = 0x0ul
    while (i <= n) {
        c2da_std_raw_put(base, i, c2da_std_raw_byte(s, i))
        i++
    }
    return base
}
[sideeffects]
def c2da_std_stream_fail(handle : uint64) {
    if (handle == 0x0ul) {
        return
    }
    let slot = c2da_std_stream_slot(handle)
    c2da_std_stream_flags[slot] = 1
}
[sideeffects]
def c2da_std_stream_open(handle : uint64) {
    let slot = c2da_std_stream_slot(handle)
    c2da_std_stream_flags[slot] = 0
    c2da_std_stream_push[slot] = -1
    c2da_std_stream_fd[slot] = int(c2da_std_stream_next_fd)  // nolint:PERF020
    c2da_std_stream_next_fd++
}
[sideeffects]
def c2da_std_stream_slot(handle : uint64) : int {
    var i : int = 0
    while (i < length(c2da_std_stream_keys)) {
        if (c2da_std_stream_keys[i] == handle) {
            return i
        }
        i++
    }
    push(c2da_std_stream_keys, handle)
    push(c2da_std_stream_flags, 0)
    push(c2da_std_stream_push, -1)
    push(c2da_std_stream_fd, c2da_std_stream_next_fd)
    c2da_std_stream_next_fd++
    return i
}
[sideeffects]
def c2da_std_stream_take_push(handle : uint64) : int {
    if (handle == 0x0ul) {
        return -1
    }
    let slot = c2da_std_stream_slot(handle)
    let pushed : int = c2da_std_stream_push[slot]
    c2da_std_stream_push[slot] = -1
    return pushed
}
[sideeffects]
def c2da_std_string(s : int8 const?) : string {
    if (s == null) {
        return ""
    }
    return build_string($(var writer : StringBuilderWriter) {
        var i : int = 0
        while (true) {
            let b = c2da_std_byte(s, i)
            if (b == 0) {
                break
            }
            write_char(writer, b)
            i++
        }
    })
}
[sideeffects]
def c2da_std_strlen(s : uint64) : uint64 {
    var n : uint64 = 0x0ul
    while (c2da_std_raw_byte(s, n) != 0) {
        n++
    }
    return n
}
[sideeffects]
def c2da_std_strncasecmp(a : uint64; b : uint64; n : uint64) : int {
    var i : uint64 = 0x0ul
    while (i < n) {
        let ca = c2da_std_tolower(c2da_std_raw_byte(a, i))
        let cb = c2da_std_tolower(c2da_std_raw_byte(b, i))
        if (ca != cb) {
            return ca - cb
        }
        if (ca == 0) {
            return 0
        }
        i++
    }
    return 0
}
[sideeffects]
def c2da_std_strncmp(a : uint64; b : uint64; n : uint64) : int {
    var i : uint64 = 0x0ul
    while (i < n) {
        let ca = c2da_std_raw_byte(a, i)
        let cb = c2da_std_raw_byte(b, i)
        if (ca != cb) {
            if (ca < cb) {
                return -1
            }
            return 1
        }
        if (ca == 0) {
            return 0
        }
        i++
    }
    return 0
}
[sideeffects]
def c2da_std_strncpy(dst : uint64; src : uint64; n : uint64) : uint64 {
    var i : uint64 = 0x0ul
    while (i < n) {
        let c = c2da_std_raw_byte(src, i)
        c2da_std_raw_put(dst, i, c)
        if (c == 0) {
            break
        }
        i++
    }
    while (i < n) {
        c2da_std_raw_put(dst, i, 0)
        i++
    }
    return dst
}
[sideeffects]
def c2da_std_strrchr(s : uint64; ch : int) : uint64 {
    if (s == 0x0ul) {
        return 0x0ul
    }
    let target : int = ch & 255
    var found : uint64 = 0x0ul
    var seen : bool = false
    var i : uint64 = 0x0ul
    while (true) {
        let b = c2da_std_raw_byte(s, i)
        if (b == target) {
            found = s + i
            seen = true
        }
        if (b == 0) {
            break
        }
        i++
    }
    if (!seen) {
        return 0x0ul
    }
    return found
}
[sideeffects]
def c2da_std_strstr(h : uint64; n : uint64) : uint64 {
    if (h == 0x0ul) {
        return 0x0ul
    }
    if (c2da_std_raw_byte(n, 0x0ul) == 0) {
        return h
    }
    var i : uint64 = 0x0ul
    while (c2da_std_raw_byte(h, i) != 0) {
        var j : uint64 = 0x0ul
        while (c2da_std_raw_byte(n, j) != 0 && c2da_std_raw_byte(h, i + j) == c2da_std_raw_byte(n, j)) {
            j++
        }
        if (c2da_std_raw_byte(n, j) == 0) {
            return h + i
        }
        i++
    }
    return 0x0ul
}
[sideeffects]
def c2da_std_strto(nptr : uint64; endptr : uint64; base : int; pos_limit : uint64; neg_limit : uint64) : uint64 {
    if (base != 0 && (base < 2 || base > 36)) {
        c2da_std_set_errno(22)
        return 0x0ul
    }
    c2da_std_store_addr(endptr, nptr)
    if (nptr == 0x0ul) {
        return 0x0ul
    }
    var i : uint64 = 0x0ul
    while (c2da_std_isspace(c2da_std_raw_byte(nptr, i)) != 0) {
        i++
    }
    var neg : bool = false
    let sign = c2da_std_raw_byte(nptr, i)
    if (sign == 45) {
        neg = true
        i++
    } elif (sign == 43) {
        i++
    }
    var radix : uint64 = 0xaul
    if ((base == 0 || base == 16) && (c2da_std_raw_byte(nptr, i) == 48 && ((c2da_std_raw_byte(nptr, i + 0x1ul) | 32) == 120 && c2da_std_digit(c2da_std_raw_byte(nptr, i + 0x2ul), 16) >= 0))) {
        i += 0x2ul
        radix = 0x10ul
    } elif (base != 0) {
        radix = uint64(base)
    } elif (c2da_std_raw_byte(nptr, i) == 48) {
        radix = 0x8ul
    }
    var limit : uint64 = pos_limit
    if (neg) {
        limit = neg_limit
    }
    var acc : uint64 = 0x0ul
    var any : bool = false
    var over : bool = false
    while (true) {
        let d = c2da_std_digit(c2da_std_raw_byte(nptr, i), int(radix))
        if (d < 0) {
            break
        }
        any = true
        let dv = uint64(d)
        if (acc > limit / radix || acc == limit / radix && dv > limit % radix) {
            over = true
        } else {
            acc = acc * radix + dv
        }
        i++
    }
    if (!any) {
        return 0x0ul
    }
    c2da_std_store_addr(endptr, nptr + i)
    if (over) {
        c2da_std_set_errno(34)
        return limit
    }
    if (neg) {
        return 0x0ul - acc
    }
    return acc
}
[sideeffects]
def c2da_std_strtod(nptr : uint64; endptr : uint64) : double {
    c2da_std_store_addr(endptr, nptr)
    if (nptr == 0x0ul) {
        return 0.0lf
    }
    var i : uint64 = 0x0ul
    while (c2da_std_isspace(c2da_std_raw_byte(nptr, i)) != 0) {
        i++
    }
    var negative : bool = false
    let sign = c2da_std_raw_byte(nptr, i)
    if (sign == 45) {
        negative = true
        i++
    } elif (sign == 43) {
        i++
    }
    if (c2da_std_raw_byte(nptr, i) == 48 && (c2da_std_raw_byte(nptr, i + 0x1ul) | 32) == 120) {
        panic("--libc std: strtod does not implement hexadecimal floating constants")
    }
    let head = c2da_std_raw_byte(nptr, i) | 32
    if (head == 105 || head == 110) {
        panic("--libc std: strtod does not implement inf and nan")
    }
    let start : uint64 = i
    var digits : int = 0
    var exponent : int = 0
    var nonzero : bool = false
    var lead : bool = true
    var point : bool = false
    while (true) {
        let b = c2da_std_raw_byte(nptr, i)
        if (is_number(b)) {
            digits++
            if (b != 48) {
                nonzero = true
                lead = false
            }
            if (!point) {
                if (!lead) {
                    exponent++
                }
            } else {
                if (lead) {
                    exponent--
                }
            }
            i++
        } elif (b == 46 && !point) {
            point = true
            i++
        } else {
            break
        }
    }
    if (digits == 0) {
        return 0.0lf
    }
    var stop : uint64 = i
    if ((c2da_std_raw_byte(nptr, i) | 32) == 101) {
        var j : uint64 = i + 0x1ul
        var negative_exponent : bool = false
        if (c2da_std_raw_byte(nptr, j) == 45) {
            negative_exponent = true
            j++
        } elif (c2da_std_raw_byte(nptr, j) == 43) {
            j++
        }
        var written : int = 0
        var value : int = 0
        while (true) {
            let d = c2da_std_digit(c2da_std_raw_byte(nptr, j), 10)
            if (d < 0) {
                break
            }
            if (value < 100000) {
                value = value * 10 + d
            }
            written++
            j++
        }
        if (written > 0) {
            stop = j
            if (negative_exponent) {
                exponent -= value
            } else {
                exponent += value
            }
        }
    }
    c2da_std_store_addr(endptr, nptr + stop)
    let body : string = build_string($(var writer : StringBuilderWriter) {
        var k : uint64 = start
        while (k < stop) {
            write_char(writer, c2da_std_raw_byte(nptr, k))
            k++
        }
    })
    var value : double = to_double(body)
    if (nonzero && (value == 0.0lf || value == c2da_std_huge())) {
        c2da_std_set_errno(34)
        if (exponent > 0) {
            value = c2da_std_huge()
        } else {
            value = 0.0lf
        }
    }
    if (negative) {
        value = 0.0lf - value
    }
    return value
}
[sideeffects]
def c2da_std_system(command : uint64) : int {
    if (command == 0x0ul) {
        return 0
    }
    c2da_std_set_errno(38)
    return -1
}
[sideeffects]
def c2da_std_take(s : int8 const?; from : int; limit : int) : string {
    if (s == null) {
        return ""
    }
    return build_string($(var writer : StringBuilderWriter) {
        var k : int = 0
        while (k < limit) {
            let ch = c2da_std_byte(s, from + k)
            if (ch == 0) {
                break
            }
            write_char(writer, ch)
            k++
        }
    })
}
[sideeffects]
def c2da_std_tolower(c : int) : int {
    if (c >= 65 && c <= 90) {
        return c + 32
    }
    return c
}
[sideeffects]
def c2da_std_toupper(c : int) : int {
    if (c >= 97 && c <= 122) {
        return c + -32
    }
    return c
}
[sideeffects]
def c2da_std_utoa(value : uint64; base : int; upper : bool) : string {
    if (value == 0x0ul) {
        return "0"
    }
    let radix : uint64 = uint64(base)
    var rest : uint64 = value
    var out : string = ""
    while (rest != 0x0ul) {
        let d : int = int(rest % radix)
        var code : int = 48
        if (d < 10) {
            code = 48 + d
        } elif (upper) {
            code = 55 + d
        } else {
            code = 87 + d
        }
        out = to_char(code) + out
        rest /= radix
    }
    return out
}
[sideeffects]
def c2da_std_vformat(f : int8 const?; args : array<C2daVaArg>; var start : int&) : string {
    c2da_std_lost_bytes = 0
    if (f == null) {
        return ""
    }
    var next : int = start
    let out : string = build_string($(var writer : StringBuilderWriter) {
        var i : int = 0
        while (true) {
            let ch = c2da_std_byte(f, i)
            if (ch == 0) {
                break
            }
            if (ch != 37) {
                write_char(writer, ch)
                i++
                continue
            }
            var j : int = i + 1
            var left : bool = false
            var zero : bool = false
            var plus : bool = false
            var blank : bool = false
            var alt : bool = false
            var width : int = 0
            var has_precision : bool = false
            var precision : int = 0
            var wide : bool = false
            while (true) {
                let fc = c2da_std_byte(f, j)
                if (fc == 45) {
                    left = true
                } elif (fc == 48) {
                    zero = true
                } elif (fc == 43) {
                    plus = true
                } elif (fc == 32) {
                    blank = true
                } elif (fc == 35) {
                    alt = true
                } else {
                    break
                }
                j++
            }
            if (c2da_std_byte(f, j) == 42) {
                let given : int = int(c2da_std_arg_i64(args, next))
                next++
                j++
                if (given < 0) {
                    left = true
                    width = 0 - given
                } else {
                    width = given
                }
            } else {
                while (true) {
                    let wc = c2da_std_byte(f, j)
                    if (!is_number(wc)) {
                        break
                    }
                    width = width * 10 + (wc - 48)
                    j++
                }
            }
            if (c2da_std_byte(f, j) == 46) {
                j++
                has_precision = true
                if (c2da_std_byte(f, j) == 42) {
                    let given : int = int(c2da_std_arg_i64(args, next))
                    next++
                    j++
                    if (given < 0) {
                        has_precision = false
                    } else {
                        precision = given
                    }
                } else {
                    while (true) {
                        let pc = c2da_std_byte(f, j)
                        if (!is_number(pc)) {
                            break
                        }
                        precision = precision * 10 + (pc - 48)
                        j++
                    }
                }
            }
            while (true) {
                let lc = c2da_std_byte(f, j)
                if (lc == 108 || lc == 122 || lc == 106 || lc == 116) {
                    wide = true
                } elif (lc != 104) {
                    break
                }
                j++
            }
            let conv = c2da_std_byte(f, j)
            if (conv == 37) {
                write(writer, "%")
                i = j + 1
                continue
            }
            if (conv == 0) {
                write(writer, c2da_std_take(f, i, j - i))
                i = j
                continue
            }
            if (conv == 100 || conv == 105) {
                var value : int64 = c2da_std_arg_i64(args, next)
                if (!wide) {
                    value = int64(int(value))
                }
                var magnitude : uint64 = unsafe(reinterpret<uint64>(value))
                var sign : string = ""
                if (value < 0l) {
                    sign = "-"
                    magnitude = 0x0ul - magnitude
                } elif (plus) {
                    sign = "+"
                } elif (blank) {
                    sign = " "
                }
                write(writer, c2da_std_number(magnitude, 10, false, sign, false, has_precision, precision, width, left, zero))
                next++
            } elif (conv == 117 || conv == 120 || conv == 88 || conv == 111) {
                var uvalue : uint64 = c2da_std_arg_u64(args, next)
                if (!wide) {
                    uvalue = uint64(uint(uvalue))
                }
                var radix : int = 10
                if (conv == 120 || conv == 88) {
                    radix = 16
                } elif (conv == 111) {
                    radix = 8
                }
                write(writer, c2da_std_number(uvalue, radix, conv == 88, "", alt, has_precision, precision, width, left, zero))
                next++
            } elif (conv == 99) {
                let code : int = int(c2da_std_arg_i64(args, next)) & 255
                var field : int = width
                if (code == 0) {
                    c2da_std_lost_bytes++
                    field--
                }
                write(writer, c2da_std_pad(to_char(code), field, left))
                next++
            } elif (conv == 102 || conv == 70 || conv == 101 || conv == 69 || conv == 103 || conv == 71) {
                var spec : string = ":"
                if (left) {
                    spec += "<"
                }
                if (plus) {
                    spec += "+"
                } elif (blank) {
                    spec += " "
                }
                if (alt) {
                    spec += "#"
                }
                if (zero && !left) {
                    spec += "0"
                }
                if (width > 0) {
                    spec += c2da_std_utoa(uint64(width), 10, false)
                }
                if (has_precision) {
                    spec += "."
                    spec += c2da_std_utoa(uint64(precision), 10, false)
                }
                write(writer, fmt(spec + to_char(conv), c2da_std_arg_f64(args, next)))
                next++
            } elif (conv == 115) {
                let address : uint64 = c2da_std_arg_u64(args, next)
                var body : string = ""
                if (address == 0x0ul) {
                    if (!(has_precision && precision < 6)) {
                        body = "(null)"
                    }
                } elif (has_precision) {
                    body = c2da_std_take(unsafe(reinterpret<int8 const?>(address)), 0, precision)
                } else {
                    body = c2da_std_string(unsafe(reinterpret<int8 const?>(address)))
                }
                write(writer, c2da_std_pad(body, width, left))
                next++
            } elif (conv == 112) {
                let target : uint64 = c2da_std_arg_u64(args, next)
                var body : string = "(nil)"
                if (target != 0x0ul) {
                    body = "0x" + c2da_std_utoa(target, 16, false)
                }
                write(writer, c2da_std_pad(body, width, left))
                next++
            } elif (conv == 110) {
                next++
            } else {
                panic("--libc std: printf conversion is not implemented: " + c2da_std_take(f, i, j + 1 - i))
            }
            i = j + 1
        }
    })
    start = next
    return out
}
[sideeffects]
def c2da_std_vfprintf(handle : uint64; f : int8 const?; var ap : C2daVaCursor; args : array<C2daVaArg>) : int {
    var from : int = ap.index
    let body : string = c2da_std_vformat(f, args, from)
    ap.index = from
    c2da_std_write(handle, body)
    return length(body) + c2da_std_lost_bytes
}
[sideeffects]
def c2da_std_vsnprintf(dst : uint64; size : uint64; f : int8 const?; var ap : C2daVaCursor; args : array<C2daVaArg>) : int {
    var from : int = ap.index
    let body : string = c2da_std_vformat(f, args, from)
    ap.index = from
    let placed : int = c2da_std_place(dst, size, body)
    return placed + c2da_std_lost_bytes
}
[sideeffects]
def c2da_std_write(handle : uint64; body : string) {
    if (handle == 0x0ul) {
        return
    }
    fprint(c2da_std_file(handle), body)
}
