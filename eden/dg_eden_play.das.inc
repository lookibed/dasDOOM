[sideeffects]
def private c2da___bswap_16_22(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_22(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_22(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_22(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_22(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_22(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
[export, sideeffects]
def DG_Init() {
    return
}
[export, sideeffects]
def DG_DrawFrame() {
    dge_frame_count++
    return
}
var private dge_frame_count : int = 0

[export, sideeffects]
def DG_SleepMs(var ms : uint) {
    dge_slept_ms += ms
    dge_clock_ms = 1000u + dge_host_ms + dge_slept_ms
    return
}
var private dge_slept_ms : uint = 0u

var private dge_host_ms : uint = 0u

var private dge_clock_ms : uint = 1000u

[export, sideeffects]
def DG_GetTicksMs() : uint {
    return dge_clock_ms
}
[export, sideeffects]
def DG_GetKey(var pressed : int; var key : int) : int {
    if (dge_key_head == dge_key_tail) {
        return 0
    }
    let c2da_fresh0 : int = dge_key_pressed[dge_key_head]
    let c2da_fresh1 : uint = uint(c2da_fresh0)
    c2da_mem[pressed] = uint8(c2da_fresh1)
    c2da_mem[pressed + 1] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[pressed + 2] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[pressed + 3] = uint8(c2da_fresh1 >> 0x18)
    let c2da_fresh2 : uint8 = dge_key_code[dge_key_head]
    c2da_mem[key] = c2da_fresh2
    dge_key_head = (dge_key_head + 1) % 64
    return 1
}
var private dge_key_head : int = 0

var private dge_key_code : uint8[64]

var private dge_key_pressed : int[64]

var private dge_key_tail : int = 0

[export, sideeffects]
def DG_SetWindowTitle(var title_0 : int) {
    return
}
var private dge_audio_clock_ms : uint = 0u

[export, sideeffects]
def dge_init() : int {
    let c2da_fresh3 : uint = 395168u
    c2da_mem[395104 + 0 * 8] = uint8(c2da_fresh3)
    c2da_mem[395104 + 0 * 8 + 1] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[395104 + 0 * 8 + 2] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[395104 + 0 * 8 + 3] = uint8(c2da_fresh3 >> 0x18)
    c2da_mem[395104 + 0 * 8 + 4] = 0u8
    c2da_mem[395104 + 0 * 8 + 5] = 0u8
    c2da_mem[395104 + 0 * 8 + 6] = 0u8
    c2da_mem[395104 + 0 * 8 + 7] = 0u8
    let c2da_fresh4 : uint = 395173u
    c2da_mem[395104 + 1 * 8] = uint8(c2da_fresh4)
    c2da_mem[395104 + 1 * 8 + 1] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[395104 + 1 * 8 + 2] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[395104 + 1 * 8 + 3] = uint8(c2da_fresh4 >> 0x18)
    c2da_mem[395104 + 1 * 8 + 4] = 0u8
    c2da_mem[395104 + 1 * 8 + 5] = 0u8
    c2da_mem[395104 + 1 * 8 + 6] = 0u8
    c2da_mem[395104 + 1 * 8 + 7] = 0u8
    let c2da_fresh5 : uint = 395179u
    c2da_mem[395104 + 2 * 8] = uint8(c2da_fresh5)
    c2da_mem[395104 + 2 * 8 + 1] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[395104 + 2 * 8 + 2] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[395104 + 2 * 8 + 3] = uint8(c2da_fresh5 >> 0x18)
    c2da_mem[395104 + 2 * 8 + 4] = 0u8
    c2da_mem[395104 + 2 * 8 + 5] = 0u8
    c2da_mem[395104 + 2 * 8 + 6] = 0u8
    c2da_mem[395104 + 2 * 8 + 7] = 0u8
    let c2da_fresh6 : uint = 395189u
    c2da_mem[395104 + 3 * 8] = uint8(c2da_fresh6)
    c2da_mem[395104 + 3 * 8 + 1] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[395104 + 3 * 8 + 2] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[395104 + 3 * 8 + 3] = uint8(c2da_fresh6 >> 0x18)
    c2da_mem[395104 + 3 * 8 + 4] = 0u8
    c2da_mem[395104 + 3 * 8 + 5] = 0u8
    c2da_mem[395104 + 3 * 8 + 6] = 0u8
    c2da_mem[395104 + 3 * 8 + 7] = 0u8
    let c2da_fresh7 : uint = 0u
    c2da_mem[395104 + 4 * 8] = uint8(c2da_fresh7)
    c2da_mem[395104 + 4 * 8 + 1] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[395104 + 4 * 8 + 2] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[395104 + 4 * 8 + 3] = uint8(c2da_fresh7 >> 0x18)
    c2da_mem[395104 + 4 * 8 + 4] = 0u8
    c2da_mem[395104 + 4 * 8 + 5] = 0u8
    c2da_mem[395104 + 4 * 8 + 6] = 0u8
    c2da_mem[395104 + 4 * 8 + 7] = 0u8
    doomgeneric_Create(4, 395104)
    dge_audio_clock_ms = uint(dge_clock_ms)  // nolint:PERF020
    return dge_frame_count
}
[export, sideeffects]
def dge_tick(var ms_0 : uint) {
    dge_host_ms = uint(ms_0)  // nolint:PERF020
    dge_clock_ms = 1000u + dge_host_ms + dge_slept_ms
    doomgeneric_Tick()
    dge_audio_mix(dge_clock_ms - dge_audio_clock_ms)
    dge_audio_clock_ms = uint(dge_clock_ms)  // nolint:PERF020
    return
}
[export, sideeffects]
def dge_key(var pressed_0 : int; var doomkey : int) {
    var next : int = (dge_key_tail + 1) % 64
    if (next == dge_key_head) {
        return
    }
    dge_key_pressed[dge_key_tail] = pressed_0 != 0 ? 1 : 0
    dge_key_code[dge_key_tail] = uint8(doomkey)
    dge_key_tail = next
    return
}
[export, sideeffects]
def dge_screen() : uint {
    return uint(uint64(DG_ScreenBuffer))
}
[export, sideeffects]
def dge_palette() : uint {
    return 298928u
}
[export, sideeffects]
def dge_frames() : int {
    return dge_frame_count
}

// This unit's static data, at heap offset 395104.
let private c2da_lin_static_dg_eden_play_seg = fixed_array<int>(395168, 29)
let private c2da_lin_static_dg_eden_play = fixed_array<uint64>(0x77692d006d6f6f64ul, 0x316d6f6f64006461ul, 0x6f6e2d006461772eul, 0x636973756dul)

[init]
def private c2da_lin_init_static_dg_eden_play() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_dg_eden_play_seg[s * 2]
        for (k in range(c2da_lin_static_dg_eden_play_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_dg_eden_play[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
