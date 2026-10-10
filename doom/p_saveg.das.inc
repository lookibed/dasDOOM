var private c2da_str_p_saveg_0 : array<int8> = [int8(116), int8(101), int8(109), int8(112), int8(46), int8(100), int8(115), int8(103), int8(0)]

var private c2da_str_p_saveg_1 : array<int8> = [int8(100), int8(111), int8(111), int8(109), int8(115), int8(97), int8(118), int8(37), int8(100), int8(46), int8(100), int8(115), int8(103), int8(0)]

var private c2da_str_p_saveg_2 : array<int8> = [int8(37), int8(115), int8(37), int8(115), int8(0)]

var private c2da_str_p_saveg_3 : array<int8> = [int8(118), int8(101), int8(114), int8(115), int8(105), int8(111), int8(110), int8(32), int8(37), int8(105), int8(0)]

var private c2da_str_p_saveg_4 : array<int8> = [int8(115), int8(97), int8(118), int8(101), int8(103), int8(95), int8(114), int8(101), int8(97), int8(100), int8(56), int8(58), int8(32), int8(85), int8(110), int8(101), int8(120), int8(112), int8(101), int8(99), int8(116), int8(101), int8(100), int8(32), int8(101), int8(110), int8(100), int8(32), int8(111), int8(102), int8(32), int8(102), int8(105), int8(108), int8(101), int8(32), int8(119), int8(104), int8(105), int8(108), int8(101), int8(32), int8(114), int8(101), int8(97), int8(100), int8(105), int8(110), int8(103), int8(32), int8(115), int8(97), int8(118), int8(101), int8(32), int8(103), int8(97), int8(109), int8(101), int8(10), int8(0)]

var private c2da_str_p_saveg_5 : array<int8> = [int8(115), int8(97), int8(118), int8(101), int8(103), int8(95), int8(119), int8(114), int8(105), int8(116), int8(101), int8(56), int8(58), int8(32), int8(69), int8(114), int8(114), int8(111), int8(114), int8(32), int8(119), int8(104), int8(105), int8(108), int8(101), int8(32), int8(119), int8(114), int8(105), int8(116), int8(105), int8(110), int8(103), int8(32), int8(115), int8(97), int8(118), int8(101), int8(32), int8(103), int8(97), int8(109), int8(101), int8(10), int8(0)]

var private c2da_str_p_saveg_6 : array<int8> = [int8(85), int8(110), int8(107), int8(110), int8(111), int8(119), int8(110), int8(32), int8(116), int8(99), int8(108), int8(97), int8(115), int8(115), int8(32), int8(37), int8(105), int8(32), int8(105), int8(110), int8(32), int8(115), int8(97), int8(118), int8(101), int8(103), int8(97), int8(109), int8(101), int8(0)]

var private c2da_str_p_saveg_7 : array<int8> = [int8(80), int8(95), int8(85), int8(110), int8(97), int8(114), int8(99), int8(104), int8(105), int8(118), int8(101), int8(83), int8(112), int8(101), int8(99), int8(105), int8(97), int8(108), int8(115), int8(58), int8(85), int8(110), int8(107), int8(110), int8(111), int8(119), int8(110), int8(32), int8(116), int8(99), int8(108), int8(97), int8(115), int8(115), int8(32), int8(37), int8(105), int8(32), int8(105), int8(110), int8(32), int8(115), int8(97), int8(118), int8(101), int8(103), int8(97), int8(109), int8(101), int8(0)]

var private P_TempSaveGameFile__filename : int8? = null

var private P_SaveGameFile__filename : int8? = null

var private P_SaveGameFile__filename_size : uint64 = 0ul

[sideeffects]
def private c2da___bswap_16_10(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_10(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_10(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_10(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_10(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_10(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
[export, sideeffects]
def P_TempSaveGameFile() : int8? {
    if (P_TempSaveGameFile__filename == null) {
        P_TempSaveGameFile__filename = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(M_StringJoin(unsafe(reinterpret<int8 const?>(savegamedir)), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_p_saveg_0[0]))))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(null)))])))))
    }
    return unsafe(reinterpret<int8?>(P_TempSaveGameFile__filename))
}
[export, sideeffects]
def P_SaveGameFile(var slot : int) : int8? {
    var basename : int8[32]
    if (P_SaveGameFile__filename == null) {
        P_SaveGameFile__filename_size = c2da_std_strlen(unsafe(reinterpret<uint64>(savegamedir))) + 32ul
        P_SaveGameFile__filename = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(unsafe(reinterpret<uint8?>(c2da_rt_malloc(P_SaveGameFile__filename_size)))))))
    }
    c2da_std_snprintf(unsafe(reinterpret<uint64>(unsafe(addr(basename[0])))), 32ul, unsafe(addr<int8 const?>(c2da_str_p_saveg_1[0])), [C2daVaArg(tag = 1, i64 = int64(slot), f64 = 0.0lf, raw = 0x0)])
    M_snprintf(P_SaveGameFile__filename, P_SaveGameFile__filename_size, unsafe(addr<int8 const?>(c2da_str_p_saveg_2[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(savegamedir))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(basename[0])))))])
    return unsafe(reinterpret<int8?>(P_SaveGameFile__filename))
}
[export, sideeffects]
def P_ReadSaveGameHeader() : uint {
    var i : int
    var a : uint8
    var b : uint8
    var c : uint8
    var vcheck : int8[16]
    var read_vcheck : int8[16]
    i = 0
    while (i < 24) {
        saveg_read8()
        i++
    }
    i = 0
    while (i < 16) {
        read_vcheck[i] = int8(saveg_read8())
        i++
    }
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(addr<uint8?>(vcheck[0])))), 0u8, 16ul)))
    M_snprintf(unsafe(addr<int8?>(vcheck[0])), 16ul, unsafe(addr<int8 const?>(c2da_str_p_saveg_3[0])), [C2daVaArg(tag = 1, i64 = int64(G_VanillaVersionCode()), f64 = 0.0lf, raw = 0x0)])
    if (c2da_std_strcmp(unsafe(reinterpret<uint64>(unsafe(addr(read_vcheck[0])))), unsafe(reinterpret<uint64>(unsafe(addr(vcheck[0]))))) != 0) {
        return 0u
    }
    gameskill = unsafe(reinterpret<skill_t>(int(saveg_read8())))
    gameepisode = int(saveg_read8())
    gamemap = int(saveg_read8())
    i = 0
    for (c2da_i in range(i, 4)) {
        playeringame[c2da_i] = uint(saveg_read8())
    }
    a = saveg_read8()
    b = saveg_read8()
    c = saveg_read8()
    leveltime = (int(a) << 16) + (int(b) << 8) + int(c)
    return 1u
}
[sideeffects]
def private saveg_read8() : uint8 {
    var result_0 : uint8
    if (c2da_std_fread(unsafe(reinterpret<uint64>(unsafe(addr<uint8?>(result_0)))), 1ul, 1ul, unsafe(reinterpret<uint64>(save_stream))) < 1ul) {
        if (savegame_error == 0) {
            c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_p_saveg_4[0])), [])
            savegame_error = 1u
        }
    }
    return result_0
}
var savegame_error : uint = default<uint>

var save_stream : _IO_FILE? = default<_IO_FILE?>

[export, sideeffects]
def P_WriteSaveGameHeader(var description : int8?) {
    var name : int8[16]
    var i_0 : int = 0
    while (int(unsafe(description[i_0])) != 0) {
        saveg_write8(uint8(unsafe(description[i_0])))
        i_0++
    }
    while (i_0 < 24) {
        saveg_write8(0u8)
        i_0++
    }
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(addr<uint8?>(name[0])))), 0u8, 16ul)))
    M_snprintf(unsafe(addr<int8?>(name[0])), 16ul, unsafe(addr<int8 const?>(c2da_str_p_saveg_3[0])), [C2daVaArg(tag = 1, i64 = int64(G_VanillaVersionCode()), f64 = 0.0lf, raw = 0x0)])
    i_0 = 0
    while (i_0 < 16) {
        saveg_write8(uint8(name[i_0]))
        i_0++
    }
    saveg_write8(uint8(gameskill))
    saveg_write8(uint8(gameepisode))
    saveg_write8(uint8(gamemap))
    i_0 = 0
    for (c2da_i_0 in range(i_0, 4)) {
        saveg_write8(uint8(playeringame[c2da_i_0]))
    }
    saveg_write8(uint8(leveltime >> 16 & 255))
    saveg_write8(uint8(leveltime >> 8 & 255))
    saveg_write8(uint8(leveltime & 255))
    return
}
[sideeffects]
def private saveg_write8(var value : uint8) {
    if (c2da_std_fwrite(unsafe(reinterpret<uint64>(unsafe(addr<uint8?>(value)))), 1ul, 1ul, unsafe(reinterpret<uint64>(save_stream))) < 1ul) {
        if (savegame_error == 0) {
            c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_p_saveg_5[0])), [])
            savegame_error = 1u
        }
    }
    return
}
[export, sideeffects]
def P_ReadSaveGameEOF() : uint {
    var value_0 : int = int(saveg_read8())
    return uint(value_0 == 29 ? 1 : 0)
}
[export, sideeffects]
def P_WriteSaveGameEOF() {
    saveg_write8(0x1du8)
    return
}
[export, sideeffects]
def P_ArchivePlayers() {
    for (i_1 in range(0, 4)) {
        if (playeringame[i_1] == 0) {
            continue
        }
        saveg_write_pad()
        saveg_write_player_t(unsafe(addr<player_s?>(unsafe(unsafe(addr(players[0]))[i_1]))))
    }
    return
}
[sideeffects]
def private saveg_write_player_t(var str : player_s?) {
    var i_2 : int
    saveg_writep(unsafe(reinterpret<uint8?>(str.mo)))
    saveg_write32(int(str.playerstate))
    var c2da_fresh0 : ticcmd_t? = unsafe(reinterpret<ticcmd_t?>(unsafe(reinterpret<uint64>(str)) + 12ul))
    saveg_write_ticcmd_t(unsafe(reinterpret<ticcmd_t?>(c2da_fresh0)))
    saveg_write32(str.viewz)
    saveg_write32(str.viewheight)
    saveg_write32(str.deltaviewheight)
    saveg_write32(str.bob)
    saveg_write32(str.health)
    saveg_write32(str.armorpoints)
    saveg_write32(str.armortype)
    i_2 = 0
    while (i_2 < 6) {
        var c2da_fresh1 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(str)) + 56ul))
        saveg_write32(unsafe(unsafe(reinterpret<int?>(c2da_fresh1))[i_2]))
        i_2++
    }
    i_2 = 0
    while (i_2 < 6) {
        var c2da_fresh2 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(str)) + 80ul))
        saveg_write32(int(unsafe(unsafe(reinterpret<uint?>(c2da_fresh2))[i_2])))
        i_2++
    }
    saveg_write32(int(str.backpack))
    i_2 = 0
    while (i_2 < 4) {
        var c2da_fresh3 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(str)) + 108ul))
        saveg_write32(unsafe(unsafe(reinterpret<int?>(c2da_fresh3))[i_2]))
        i_2++
    }
    saveg_write32(int(str.readyweapon))
    saveg_write32(int(str.pendingweapon))
    i_2 = 0
    while (i_2 < 9) {
        var c2da_fresh4 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(str)) + 132ul))
        saveg_write32(int(unsafe(unsafe(reinterpret<uint?>(c2da_fresh4))[i_2])))
        i_2++
    }
    i_2 = 0
    while (i_2 < 4) {
        var c2da_fresh5 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(str)) + 168ul))
        saveg_write32(unsafe(unsafe(reinterpret<int?>(c2da_fresh5))[i_2]))
        i_2++
    }
    i_2 = 0
    while (i_2 < 4) {
        var c2da_fresh6 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(str)) + 184ul))
        saveg_write32(unsafe(unsafe(reinterpret<int?>(c2da_fresh6))[i_2]))
        i_2++
    }
    saveg_write32(str.attackdown)
    saveg_write32(str.usedown)
    saveg_write32(str.cheats)
    saveg_write32(str.refire)
    saveg_write32(str.killcount)
    saveg_write32(str.itemcount)
    saveg_write32(str.secretcount)
    saveg_writep(unsafe(reinterpret<uint8?>(str.message)))
    saveg_write32(str.damagecount)
    saveg_write32(str.bonuscount)
    saveg_writep(unsafe(reinterpret<uint8?>(str.attacker)))
    saveg_write32(str.extralight)
    saveg_write32(str.fixedcolormap)
    saveg_write32(str.colormap)
    i_2 = 0
    for (c2da_i_2 in range(i_2, 2)) {
        var c2da_fresh7 : pspdef_t? = unsafe(reinterpret<pspdef_t?>(unsafe(reinterpret<uint64>(str)) + 272ul))
        saveg_write_pspdef_t(unsafe(addr<pspdef_t?>(unsafe(unsafe(reinterpret<pspdef_t?>(c2da_fresh7))[c2da_i_2]))))
    }
    saveg_write32(int(str.didsecret))
    return
}
[sideeffects]
def private saveg_write32(var value_1 : int) {
    saveg_write8(uint8(value_1 & 255))
    saveg_write8(uint8(value_1 >> 8 & 255))
    saveg_write8(uint8(value_1 >> 16 & 255))
    saveg_write8(uint8(value_1 >> 24 & 255))
    return
}
[sideeffects]
def private saveg_write_pspdef_t(var str_0 : pspdef_t?) {
    if (str_0.state != null) {
        saveg_write32(int(unsafe(str_0.state - unsafe(addr(states[0])))))
    } else {
        saveg_write32(0)
    }
    saveg_write32(str_0.tics)
    saveg_write32(str_0.sx)
    saveg_write32(str_0.sy)
    return
}
[sideeffects]
def private saveg_writep(var p : uint8?) {
    saveg_write32(int(int64(unsafe(reinterpret<uint64>(p)))))
    return
}
[sideeffects]
def private saveg_write_ticcmd_t(var str_1 : ticcmd_t?) {
    saveg_write8(uint8(str_1.forwardmove))
    saveg_write8(uint8(str_1.sidemove))
    saveg_write16(str_1.angleturn)
    saveg_write16(int16(str_1.consistancy))
    saveg_write8(str_1.chatchar)
    saveg_write8(str_1.buttons)
    return
}
[sideeffects]
def private saveg_write16(var value_2 : int16) {
    saveg_write8(uint8(int(value_2) & 255))
    saveg_write8(uint8(int(value_2) >> 8 & 255))
    return
}
[sideeffects]
def private saveg_write_pad() {
    var pos : uint64
    var padding : int
    pos = uint64(c2da_std_ftell(unsafe(reinterpret<uint64>(save_stream))))
    padding = int(4ul - (pos & 3ul) & 3ul)
    for (i_3 in range(0, padding)) {
        saveg_write8(0u8)
    }
    return
}
[export, sideeffects]
def P_UnArchivePlayers() {
    for (i_4 in range(0, 4)) {
        if (playeringame[i_4] == 0) {
            continue
        }
        saveg_read_pad()
        saveg_read_player_t(unsafe(addr<player_s?>(unsafe(unsafe(addr(players[0]))[i_4]))))
        players[i_4].mo = null
        players[i_4].message = null
        players[i_4].attacker = null
    }
    return
}
[sideeffects]
def private saveg_read_player_t(var str_2 : player_s?) {
    var i_5 : int
    str_2.mo = unsafe(reinterpret<mobj_s?>(saveg_readp()))
    str_2.playerstate = unsafe(reinterpret<playerstate_t>(uint(saveg_read32())))
    var c2da_fresh8 : ticcmd_t? = unsafe(reinterpret<ticcmd_t?>(unsafe(reinterpret<uint64>(str_2)) + 12ul))
    saveg_read_ticcmd_t(unsafe(reinterpret<ticcmd_t?>(c2da_fresh8)))
    str_2.viewz = saveg_read32()
    str_2.viewheight = saveg_read32()
    str_2.deltaviewheight = saveg_read32()
    str_2.bob = saveg_read32()
    str_2.health = saveg_read32()
    str_2.armorpoints = saveg_read32()
    str_2.armortype = saveg_read32()
    i_5 = 0
    while (i_5 < 6) {
        var c2da_fresh9 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(str_2)) + 56ul))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh9))[i_5]) = saveg_read32()
        i_5++
    }
    i_5 = 0
    while (i_5 < 6) {
        var c2da_fresh10 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(str_2)) + 80ul))
        unsafe(unsafe(reinterpret<uint?>(c2da_fresh10))[i_5]) = uint(saveg_read32())
        i_5++
    }
    str_2.backpack = uint(saveg_read32())
    i_5 = 0
    while (i_5 < 4) {
        var c2da_fresh11 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(str_2)) + 108ul))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh11))[i_5]) = saveg_read32()
        i_5++
    }
    str_2.readyweapon = unsafe(reinterpret<weapontype_t>(uint(saveg_read32())))
    str_2.pendingweapon = unsafe(reinterpret<weapontype_t>(uint(saveg_read32())))
    i_5 = 0
    while (i_5 < 9) {
        var c2da_fresh12 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(str_2)) + 132ul))
        unsafe(unsafe(reinterpret<uint?>(c2da_fresh12))[i_5]) = uint(saveg_read32())
        i_5++
    }
    i_5 = 0
    while (i_5 < 4) {
        var c2da_fresh13 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(str_2)) + 168ul))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh13))[i_5]) = saveg_read32()
        i_5++
    }
    i_5 = 0
    while (i_5 < 4) {
        var c2da_fresh14 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(str_2)) + 184ul))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh14))[i_5]) = saveg_read32()
        i_5++
    }
    str_2.attackdown = saveg_read32()
    str_2.usedown = saveg_read32()
    str_2.cheats = saveg_read32()
    str_2.refire = saveg_read32()
    str_2.killcount = saveg_read32()
    str_2.itemcount = saveg_read32()
    str_2.secretcount = saveg_read32()
    str_2.message = unsafe(reinterpret<int8?>(saveg_readp()))
    str_2.damagecount = saveg_read32()
    str_2.bonuscount = saveg_read32()
    str_2.attacker = unsafe(reinterpret<mobj_s?>(saveg_readp()))
    str_2.extralight = saveg_read32()
    str_2.fixedcolormap = saveg_read32()
    str_2.colormap = saveg_read32()
    i_5 = 0
    for (c2da_i_5 in range(i_5, 2)) {
        var c2da_fresh15 : pspdef_t? = unsafe(reinterpret<pspdef_t?>(unsafe(reinterpret<uint64>(str_2)) + 272ul))
        saveg_read_pspdef_t(unsafe(addr<pspdef_t?>(unsafe(unsafe(reinterpret<pspdef_t?>(c2da_fresh15))[c2da_i_5]))))
    }
    str_2.didsecret = uint(saveg_read32())
    return
}
[sideeffects]
def private saveg_read32() : int {
    var result_1 : int = int(saveg_read8())
    result_1 = result_1 | int(saveg_read8()) << 8
    result_1 = result_1 | int(saveg_read8()) << 16
    result_1 = result_1 | int(saveg_read8()) << 24
    return result_1
}
[sideeffects]
def private saveg_read_pspdef_t(var str_3 : pspdef_t?) {
    var state : int = saveg_read32()
    if (state > 0) {
        str_3.state = unsafe(addr(unsafe(unsafe(addr(states[0]))[state])))
    } else {
        str_3.state = null
    }
    str_3.tics = saveg_read32()
    str_3.sx = saveg_read32()
    str_3.sy = saveg_read32()
    return
}
[sideeffects]
def private saveg_readp() : uint8? {
    return unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(uint64(saveg_read32())))))
}
[sideeffects]
def private saveg_read_ticcmd_t(var str_4 : ticcmd_t?) {
    str_4.forwardmove = int8(saveg_read8())
    str_4.sidemove = int8(saveg_read8())
    str_4.angleturn = saveg_read16()
    str_4.consistancy = uint8(saveg_read16())
    str_4.chatchar = saveg_read8()
    str_4.buttons = saveg_read8()
    return
}
[sideeffects]
def private saveg_read16() : int16 {
    var result_2 : int = int(saveg_read8())
    result_2 = result_2 | int(saveg_read8()) << 8
    return int16(result_2)
}
[sideeffects]
def private saveg_read_pad() {
    var pos_0 : uint64
    var padding_0 : int
    pos_0 = uint64(c2da_std_ftell(unsafe(reinterpret<uint64>(save_stream))))
    padding_0 = int(4ul - (pos_0 & 3ul) & 3ul)
    for (i_6 in range(0, padding_0)) {
        saveg_read8()
    }
    return
}
[export, sideeffects]
def P_ArchiveWorld() {
    var i_7 : int
    var sec : sector_t?
    var li : line_s?
    var si : side_t?
    i_7 = 0
    sec = unsafe(reinterpret<sector_t?>(sectors))
    while (i_7 < numsectors) {
        saveg_write16(int16(sec.floorheight >> 16))
        saveg_write16(int16(sec.ceilingheight >> 16))
        saveg_write16(sec.floorpic)
        saveg_write16(sec.ceilingpic)
        saveg_write16(sec.lightlevel)
        saveg_write16(sec.special)
        saveg_write16(sec.tag)
        i_7++
        unsafe {  // nolint:STYLE025
            sec += 1
        }
    }
    i_7 = 0
    li = unsafe(reinterpret<line_s?>(lines))
    while (i_7 < numlines) {
        saveg_write16(li.flags)
        saveg_write16(li.special)
        saveg_write16(li.tag)
        for (j in range(0, 2)) {
            var c2da_fresh16 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(li)) + 30ul))
            if (int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh16))[j])) == -1) {
                continue
            }
            var c2da_fresh17 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(li)) + 30ul))
            si = unsafe(addr<side_t?>(unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh17))[j]))])))
            saveg_write16(int16(si.textureoffset >> 16))
            saveg_write16(int16(si.rowoffset >> 16))
            saveg_write16(si.toptexture)
            saveg_write16(si.bottomtexture)
            saveg_write16(si.midtexture)
        }
        i_7++
        unsafe {  // nolint:STYLE025
            li += 1
        }
    }
    return
}
[export, sideeffects]
def P_UnArchiveWorld() {
    var i_8 : int
    var sec_0 : sector_t?
    var li_0 : line_s?
    var si_0 : side_t?
    i_8 = 0
    sec_0 = unsafe(reinterpret<sector_t?>(sectors))
    while (i_8 < numsectors) {
        sec_0.floorheight = int(saveg_read16()) << 16
        sec_0.ceilingheight = int(saveg_read16()) << 16
        sec_0.floorpic = saveg_read16()
        sec_0.ceilingpic = saveg_read16()
        sec_0.lightlevel = saveg_read16()
        sec_0.special = saveg_read16()
        sec_0.tag = saveg_read16()
        sec_0.specialdata = null
        sec_0.soundtarget = null
        i_8++
        unsafe {  // nolint:STYLE025
            sec_0 += 1
        }
    }
    i_8 = 0
    li_0 = unsafe(reinterpret<line_s?>(lines))
    while (i_8 < numlines) {
        li_0.flags = saveg_read16()
        li_0.special = saveg_read16()
        li_0.tag = saveg_read16()
        for (j_0 in range(0, 2)) {
            var c2da_fresh18 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(li_0)) + 30ul))
            if (int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh18))[j_0])) == -1) {
                continue
            }
            var c2da_fresh19 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(li_0)) + 30ul))
            si_0 = unsafe(addr<side_t?>(unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh19))[j_0]))])))
            si_0.textureoffset = int(saveg_read16()) << 16
            si_0.rowoffset = int(saveg_read16()) << 16
            si_0.toptexture = saveg_read16()
            si_0.bottomtexture = saveg_read16()
            si_0.midtexture = saveg_read16()
        }
        i_8++
        unsafe {  // nolint:STYLE025
            li_0 += 1
        }
    }
    return
}
[export, sideeffects]
def P_ArchiveThinkers() {
    var th : thinker_s? = unsafe(reinterpret<thinker_s?>(thinkercap.next))
    while (th != unsafe(addr(thinkercap))) {
        if (unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(th))))[2]) == unsafe(reinterpret<actionf_p1>(@@P_MobjThinker))) {
            saveg_write8(1u8)
            saveg_write_pad()
            saveg_write_mobj_t(unsafe(reinterpret<mobj_s?>(th)))
            th = unsafe(reinterpret<thinker_s?>(th.next))
            continue
        }
        th = unsafe(reinterpret<thinker_s?>(th.next))
    }
    saveg_write8(0u8)
    return
}
[sideeffects]
def private saveg_write_mobj_t(var str_5 : mobj_s?) {
    var c2da_fresh20 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(str_5))))
    saveg_write_thinker_t(unsafe(reinterpret<thinker_s?>(c2da_fresh20)))
    saveg_write32(str_5.x)
    saveg_write32(str_5.y)
    saveg_write32(str_5.z)
    saveg_writep(unsafe(reinterpret<uint8?>(str_5.snext)))
    saveg_writep(unsafe(reinterpret<uint8?>(str_5.sprev)))
    saveg_write32(int(str_5.angle))
    saveg_write32(int(str_5.sprite))
    saveg_write32(str_5.frame)
    saveg_writep(unsafe(reinterpret<uint8?>(str_5.bnext)))
    saveg_writep(unsafe(reinterpret<uint8?>(str_5.bprev)))
    saveg_writep(unsafe(reinterpret<uint8?>(str_5.subsector)))
    saveg_write32(str_5.floorz)
    saveg_write32(str_5.ceilingz)
    saveg_write32(str_5.radius)
    saveg_write32(str_5.height)
    saveg_write32(str_5.momx)
    saveg_write32(str_5.momy)
    saveg_write32(str_5.momz)
    saveg_write32(str_5.validcount)
    saveg_write32(int(str_5.type_0))
    saveg_writep(unsafe(reinterpret<uint8?>(str_5.info)))
    saveg_write32(str_5.tics)
    saveg_write32(int(unsafe(str_5.state - unsafe(addr(states[0])))))
    saveg_write32(str_5.flags)
    saveg_write32(str_5.health)
    saveg_write32(str_5.movedir)
    saveg_write32(str_5.movecount)
    saveg_writep(unsafe(reinterpret<uint8?>(str_5.target)))
    saveg_write32(str_5.reactiontime)
    saveg_write32(str_5.threshold)
    if (str_5.player != null) {
        saveg_write32(int(unsafe(str_5.player - unsafe(addr(players[0]))) + 1l))
    } else {
        saveg_write32(0)
    }
    saveg_write32(str_5.lastlook)
    var c2da_fresh21 : mapthing_t? = unsafe(reinterpret<mapthing_t?>(unsafe(reinterpret<uint64>(str_5)) + 204ul))
    saveg_write_mapthing_t(unsafe(reinterpret<mapthing_t?>(c2da_fresh21)))
    saveg_writep(unsafe(reinterpret<uint8?>(str_5.tracer)))
    return
}
[sideeffects]
def private saveg_write_mapthing_t(var str_6 : mapthing_t?) {
    saveg_write16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(str_6))))[0]))
    saveg_write16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(str_6))))[1]))
    saveg_write16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(str_6))))[2]))
    saveg_write16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(str_6))))[3]))
    saveg_write16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(str_6))))[4]))
    return
}
[sideeffects]
def private saveg_write_thinker_t(var str_7 : thinker_s?) {
    saveg_writep(unsafe(reinterpret<uint8?>(str_7.prev)))
    saveg_writep(unsafe(reinterpret<uint8?>(str_7.next)))
    var c2da_fresh22 : actionf_t? = unsafe(reinterpret<actionf_t?>(unsafe(reinterpret<uint64>(str_7)) + 16ul))
    saveg_write_actionf_t(unsafe(reinterpret<actionf_t?>(c2da_fresh22)))
    return
}
[sideeffects]
def private saveg_write_actionf_t(var str_8 : actionf_t?) {
    saveg_writep(unsafe(reinterpret<uint8?>(unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(str_8))))[0]))))
    return
}
[export, sideeffects]
def P_UnArchiveThinkers() {
    var c2da_fresh23 : int
    var tclass : uint8
    var currentthinker : thinker_s?
    var next : thinker_s?
    var mobj : mobj_s?
    currentthinker = unsafe(reinterpret<thinker_s?>(thinkercap.next))
    while (currentthinker != unsafe(addr(thinkercap))) {
        next = unsafe(reinterpret<thinker_s?>(currentthinker.next))
        if (unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(currentthinker))))[2]) == unsafe(reinterpret<actionf_p1>(@@P_MobjThinker))) {
            P_RemoveMobj(unsafe(reinterpret<mobj_s?>(currentthinker)))
        } else {
            Z_Free(unsafe(reinterpret<uint8?>(currentthinker)))
        }
        currentthinker = unsafe(reinterpret<thinker_s?>(next))
    }
    P_InitThinkers()
    while (true) {
        tclass = saveg_read8()
        c2da_fresh23 = int(tclass)
        if (c2da_fresh23 == 0) {
            return
        } elif (c2da_fresh23 == 1) {
            saveg_read_pad()
            mobj = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(Z_Malloc(224, 5, null)))))
            saveg_read_mobj_t(mobj)
            mobj.target = null
            mobj.tracer = null
            P_SetThingPosition(mobj)
            mobj.info = unsafe(addr(unsafe(unsafe(addr(mobjinfo[0]))[int(mobj.type_0)])))
            mobj.floorz = int(mobj.subsector.sector.floorheight)  // nolint:PERF020
            mobj.ceilingz = int(mobj.subsector.sector.ceilingheight)  // nolint:PERF020
            unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(mobj))))[2]) = unsafe(reinterpret<actionf_p1>(@@P_MobjThinker))
            var c2da_fresh24 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(mobj))))
            P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh24)))
        } else {
            I_Error(unsafe(addr<int8?>(c2da_str_p_saveg_6[0])), [C2daVaArg(tag = 1, i64 = int64(tclass), f64 = 0.0lf, raw = 0x0)])
        }
    }
}
[sideeffects]
def private saveg_read_mobj_t(var str_9 : mobj_s?) {
    var pl : int
    var c2da_fresh25 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(str_9))))
    saveg_read_thinker_t(unsafe(reinterpret<thinker_s?>(c2da_fresh25)))
    str_9.x = saveg_read32()
    str_9.y = saveg_read32()
    str_9.z = saveg_read32()
    str_9.snext = unsafe(reinterpret<mobj_s?>(saveg_readp()))
    str_9.sprev = unsafe(reinterpret<mobj_s?>(saveg_readp()))
    str_9.angle = uint(saveg_read32())
    str_9.sprite = unsafe(reinterpret<spritenum_t>(uint(saveg_read32())))
    str_9.frame = saveg_read32()
    str_9.bnext = unsafe(reinterpret<mobj_s?>(saveg_readp()))
    str_9.bprev = unsafe(reinterpret<mobj_s?>(saveg_readp()))
    str_9.subsector = unsafe(reinterpret<subsector_s?>(saveg_readp()))
    str_9.floorz = saveg_read32()
    str_9.ceilingz = saveg_read32()
    str_9.radius = saveg_read32()
    str_9.height = saveg_read32()
    str_9.momx = saveg_read32()
    str_9.momy = saveg_read32()
    str_9.momz = saveg_read32()
    str_9.validcount = saveg_read32()
    str_9.type_0 = unsafe(reinterpret<mobjtype_t>(uint(saveg_read32())))
    str_9.info = unsafe(reinterpret<mobjinfo_t?>(saveg_readp()))
    str_9.tics = saveg_read32()
    str_9.state = unsafe(addr(unsafe(unsafe(addr(states[0]))[saveg_read32()])))
    str_9.flags = saveg_read32()
    str_9.health = saveg_read32()
    str_9.movedir = saveg_read32()
    str_9.movecount = saveg_read32()
    str_9.target = unsafe(reinterpret<mobj_s?>(saveg_readp()))
    str_9.reactiontime = saveg_read32()
    str_9.threshold = saveg_read32()
    pl = saveg_read32()
    if (pl > 0) {
        str_9.player = unsafe(addr(unsafe(unsafe(addr(players[0]))[pl - 1])))
        str_9.player.mo = str_9
    } else {
        str_9.player = null
    }
    str_9.lastlook = saveg_read32()
    var c2da_fresh26 : mapthing_t? = unsafe(reinterpret<mapthing_t?>(unsafe(reinterpret<uint64>(str_9)) + 204ul))
    saveg_read_mapthing_t(unsafe(reinterpret<mapthing_t?>(c2da_fresh26)))
    str_9.tracer = unsafe(reinterpret<mobj_s?>(saveg_readp()))
    return
}
[sideeffects]
def private saveg_read_mapthing_t(var str_10 : mapthing_t?) {
    unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(str_10))))[0]) = saveg_read16()
    unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(str_10))))[1]) = saveg_read16()
    unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(str_10))))[2]) = saveg_read16()
    unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(str_10))))[3]) = saveg_read16()
    unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(str_10))))[4]) = saveg_read16()
    return
}
[sideeffects]
def private saveg_read_thinker_t(var str_11 : thinker_s?) {
    str_11.prev = unsafe(reinterpret<thinker_s?>(saveg_readp()))
    str_11.next = unsafe(reinterpret<thinker_s?>(saveg_readp()))
    var c2da_fresh27 : actionf_t? = unsafe(reinterpret<actionf_t?>(unsafe(reinterpret<uint64>(str_11)) + 16ul))
    saveg_read_actionf_t(unsafe(reinterpret<actionf_t?>(c2da_fresh27)))
    return
}
[sideeffects]
def private saveg_read_actionf_t(var str_12 : actionf_t?) {
    unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(str_12))))[0]) = unsafe(reinterpret<actionf_p1>(saveg_readp()))
    return
}
[export, sideeffects]
def P_ArchiveSpecials() {
    var th_0 : thinker_s?
    var i_9 : int
    th_0 = unsafe(reinterpret<thinker_s?>(thinkercap.next))
    while (th_0 != unsafe(addr(thinkercap))) {
        if (unsafe(unsafe(reinterpret<actionf_v?>(unsafe(reinterpret<uint64>(th_0))))[2]) == unsafe(reinterpret<actionf_v>(null))) {
            i_9 = 0
            while (i_9 < 30) {
                if (activeceilings[i_9] == unsafe(reinterpret<ceiling_t?>(th_0))) {
                    break
                }
                i_9++
            }
            if (i_9 < 30) {
                saveg_write8(0u8)
                saveg_write_pad()
                saveg_write_ceiling_t(unsafe(reinterpret<ceiling_t?>(th_0)))
            }
            th_0 = unsafe(reinterpret<thinker_s?>(th_0.next))
            continue
        }
        if (unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(th_0))))[2]) == unsafe(reinterpret<actionf_p1>(@@T_MoveCeiling))) {
            saveg_write8(0u8)
            saveg_write_pad()
            saveg_write_ceiling_t(unsafe(reinterpret<ceiling_t?>(th_0)))
            th_0 = unsafe(reinterpret<thinker_s?>(th_0.next))
            continue
        }
        if (unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(th_0))))[2]) == unsafe(reinterpret<actionf_p1>(@@T_VerticalDoor))) {
            saveg_write8(1u8)
            saveg_write_pad()
            saveg_write_vldoor_t(unsafe(reinterpret<vldoor_t?>(th_0)))
            th_0 = unsafe(reinterpret<thinker_s?>(th_0.next))
            continue
        }
        if (unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(th_0))))[2]) == unsafe(reinterpret<actionf_p1>(@@T_MoveFloor))) {
            saveg_write8(2u8)
            saveg_write_pad()
            saveg_write_floormove_t(unsafe(reinterpret<floormove_t?>(th_0)))
            th_0 = unsafe(reinterpret<thinker_s?>(th_0.next))
            continue
        }
        if (unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(th_0))))[2]) == unsafe(reinterpret<actionf_p1>(@@T_PlatRaise))) {
            saveg_write8(3u8)
            saveg_write_pad()
            saveg_write_plat_t(unsafe(reinterpret<plat_t?>(th_0)))
            th_0 = unsafe(reinterpret<thinker_s?>(th_0.next))
            continue
        }
        if (unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(th_0))))[2]) == unsafe(reinterpret<actionf_p1>(@@T_LightFlash))) {
            saveg_write8(4u8)
            saveg_write_pad()
            saveg_write_lightflash_t(unsafe(reinterpret<lightflash_t?>(th_0)))
            th_0 = unsafe(reinterpret<thinker_s?>(th_0.next))
            continue
        }
        if (unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(th_0))))[2]) == unsafe(reinterpret<actionf_p1>(@@T_StrobeFlash))) {
            saveg_write8(5u8)
            saveg_write_pad()
            saveg_write_strobe_t(unsafe(reinterpret<strobe_t?>(th_0)))
            th_0 = unsafe(reinterpret<thinker_s?>(th_0.next))
            continue
        }
        if (unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(th_0))))[2]) == unsafe(reinterpret<actionf_p1>(@@T_Glow))) {
            saveg_write8(6u8)
            saveg_write_pad()
            saveg_write_glow_t(unsafe(reinterpret<glow_t?>(th_0)))
            th_0 = unsafe(reinterpret<thinker_s?>(th_0.next))
            continue
        }
        th_0 = unsafe(reinterpret<thinker_s?>(th_0.next))
    }
    saveg_write8(7u8)
    return
}
[sideeffects]
def private saveg_write_glow_t(var str_13 : glow_t?) {
    var c2da_fresh28 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(str_13))))
    saveg_write_thinker_t(unsafe(reinterpret<thinker_s?>(c2da_fresh28)))
    saveg_write32(int(unsafe(str_13.sector - sectors)))
    saveg_write32(str_13.minlight)
    saveg_write32(str_13.maxlight)
    saveg_write32(str_13.direction)
    return
}
[sideeffects]
def private saveg_write_strobe_t(var str_14 : strobe_t?) {
    var c2da_fresh29 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(str_14))))
    saveg_write_thinker_t(unsafe(reinterpret<thinker_s?>(c2da_fresh29)))
    saveg_write32(int(unsafe(str_14.sector - sectors)))
    saveg_write32(str_14.count)
    saveg_write32(str_14.minlight)
    saveg_write32(str_14.maxlight)
    saveg_write32(str_14.darktime)
    saveg_write32(str_14.brighttime)
    return
}
[sideeffects]
def private saveg_write_lightflash_t(var str_15 : lightflash_t?) {
    var c2da_fresh30 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(str_15))))
    saveg_write_thinker_t(unsafe(reinterpret<thinker_s?>(c2da_fresh30)))
    saveg_write32(int(unsafe(str_15.sector - sectors)))
    saveg_write32(str_15.count)
    saveg_write32(str_15.maxlight)
    saveg_write32(str_15.minlight)
    saveg_write32(str_15.maxtime)
    saveg_write32(str_15.mintime)
    return
}
[sideeffects]
def private saveg_write_plat_t(var str_16 : plat_t?) {
    var c2da_fresh31 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(str_16))))
    saveg_write_thinker_t(unsafe(reinterpret<thinker_s?>(c2da_fresh31)))
    saveg_write32(int(unsafe(str_16.sector - sectors)))
    saveg_write32(str_16.speed)
    saveg_write32(str_16.low)
    saveg_write32(str_16.high)
    saveg_write32(str_16.wait)
    saveg_write32(str_16.count)
    saveg_write32(int(str_16.status))
    saveg_write32(int(str_16.oldstatus))
    saveg_write32(int(str_16.crush))
    saveg_write32(str_16.tag)
    saveg_write32(int(str_16.type_0))
    return
}
[sideeffects]
def private saveg_write_floormove_t(var str_17 : floormove_t?) {
    var c2da_fresh32 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(str_17))))
    saveg_write_thinker_t(unsafe(reinterpret<thinker_s?>(c2da_fresh32)))
    saveg_write32(int(str_17.type_0))
    saveg_write32(int(str_17.crush))
    saveg_write32(int(unsafe(str_17.sector - sectors)))
    saveg_write32(str_17.direction)
    saveg_write32(str_17.newspecial)
    saveg_write16(str_17.texture)
    saveg_write32(str_17.floordestheight)
    saveg_write32(str_17.speed)
    return
}
[sideeffects]
def private saveg_write_vldoor_t(var str_18 : vldoor_t?) {
    var c2da_fresh33 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(str_18))))
    saveg_write_thinker_t(unsafe(reinterpret<thinker_s?>(c2da_fresh33)))
    saveg_write32(int(str_18.type_0))
    saveg_write32(int(unsafe(str_18.sector - sectors)))
    saveg_write32(str_18.topheight)
    saveg_write32(str_18.speed)
    saveg_write32(str_18.direction)
    saveg_write32(str_18.topwait)
    saveg_write32(str_18.topcountdown)
    return
}
[sideeffects]
def private saveg_write_ceiling_t(var str_19 : ceiling_t?) {
    var c2da_fresh34 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(str_19))))
    saveg_write_thinker_t(unsafe(reinterpret<thinker_s?>(c2da_fresh34)))
    saveg_write32(int(str_19.type_0))
    saveg_write32(int(unsafe(str_19.sector - sectors)))
    saveg_write32(str_19.bottomheight)
    saveg_write32(str_19.topheight)
    saveg_write32(str_19.speed)
    saveg_write32(int(str_19.crush))
    saveg_write32(str_19.direction)
    saveg_write32(str_19.tag)
    saveg_write32(str_19.olddirection)
    return
}
[export, sideeffects]
def P_UnArchiveSpecials() {
    var c2da_fresh35 : int
    var tclass_0 : uint8
    var ceiling : ceiling_t?
    var door : vldoor_t?
    var floor : floormove_t?
    var plat : plat_t?
    var flash : lightflash_t?
    var strobe : strobe_t?
    var glow : glow_t?
    while (true) {
        tclass_0 = saveg_read8()
        c2da_fresh35 = int(tclass_0)
        if (c2da_fresh35 == 7) {
            return
        } elif (c2da_fresh35 == 0) {
            saveg_read_pad()
            ceiling = unsafe(reinterpret<ceiling_t?>(unsafe(reinterpret<ceiling_t?>(Z_Malloc(72, 5, null)))))
            saveg_read_ceiling_t(ceiling)
            ceiling.sector.specialdata = unsafe(reinterpret<uint8?>(ceiling))
            if (unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(ceiling))))[2]) != default<actionf_p1>) {
                unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(ceiling))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_MoveCeiling))
            }
            var c2da_fresh36 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(ceiling))))
            P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh36)))
            P_AddActiveCeiling(ceiling)
        } elif (c2da_fresh35 == 1) {
            saveg_read_pad()
            door = unsafe(reinterpret<vldoor_t?>(unsafe(reinterpret<vldoor_t?>(Z_Malloc(64, 5, null)))))
            saveg_read_vldoor_t(door)
            door.sector.specialdata = unsafe(reinterpret<uint8?>(door))
            unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(door))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_VerticalDoor))
            var c2da_fresh37 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(door))))
            P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh37)))
        } elif (c2da_fresh35 == 2) {
            saveg_read_pad()
            floor = unsafe(reinterpret<floormove_t?>(unsafe(reinterpret<floormove_t?>(Z_Malloc(64, 5, null)))))
            saveg_read_floormove_t(floor)
            floor.sector.specialdata = unsafe(reinterpret<uint8?>(floor))
            unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(floor))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_MoveFloor))
            var c2da_fresh38 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(floor))))
            P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh38)))
        } elif (c2da_fresh35 == 3) {
            saveg_read_pad()
            plat = unsafe(reinterpret<plat_t?>(unsafe(reinterpret<plat_t?>(Z_Malloc(72, 5, null)))))
            saveg_read_plat_t(plat)
            plat.sector.specialdata = unsafe(reinterpret<uint8?>(plat))
            if (unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(plat))))[2]) != default<actionf_p1>) {
                unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(plat))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_PlatRaise))
            }
            var c2da_fresh39 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(plat))))
            P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh39)))
            P_AddActivePlat(plat)
        } elif (c2da_fresh35 == 4) {
            saveg_read_pad()
            flash = unsafe(reinterpret<lightflash_t?>(unsafe(reinterpret<lightflash_t?>(Z_Malloc(56, 5, null)))))
            saveg_read_lightflash_t(flash)
            unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(flash))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_LightFlash))
            var c2da_fresh40 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(flash))))
            P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh40)))
        } elif (c2da_fresh35 == 5) {
            saveg_read_pad()
            strobe = unsafe(reinterpret<strobe_t?>(unsafe(reinterpret<strobe_t?>(Z_Malloc(56, 5, null)))))
            saveg_read_strobe_t(strobe)
            unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(strobe))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_StrobeFlash))
            var c2da_fresh41 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(strobe))))
            P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh41)))
        } elif (c2da_fresh35 == 6) {
            saveg_read_pad()
            glow = unsafe(reinterpret<glow_t?>(unsafe(reinterpret<glow_t?>(Z_Malloc(48, 5, null)))))
            saveg_read_glow_t(glow)
            unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(glow))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_Glow))
            var c2da_fresh42 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(glow))))
            P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh42)))
        } else {
            I_Error(unsafe(addr<int8?>(c2da_str_p_saveg_7[0])), [C2daVaArg(tag = 1, i64 = int64(tclass_0), f64 = 0.0lf, raw = 0x0)])
        }
    }
}
[sideeffects]
def private saveg_read_glow_t(var str_20 : glow_t?) {
    var sector : int
    var c2da_fresh43 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(str_20))))
    saveg_read_thinker_t(unsafe(reinterpret<thinker_s?>(c2da_fresh43)))
    sector = saveg_read32()
    str_20.sector = unsafe(addr(unsafe(sectors[sector])))
    str_20.minlight = saveg_read32()
    str_20.maxlight = saveg_read32()
    str_20.direction = saveg_read32()
    return
}
[sideeffects]
def private saveg_read_strobe_t(var str_21 : strobe_t?) {
    var sector_0 : int
    var c2da_fresh44 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(str_21))))
    saveg_read_thinker_t(unsafe(reinterpret<thinker_s?>(c2da_fresh44)))
    sector_0 = saveg_read32()
    str_21.sector = unsafe(addr(unsafe(sectors[sector_0])))
    str_21.count = saveg_read32()
    str_21.minlight = saveg_read32()
    str_21.maxlight = saveg_read32()
    str_21.darktime = saveg_read32()
    str_21.brighttime = saveg_read32()
    return
}
[sideeffects]
def private saveg_read_lightflash_t(var str_22 : lightflash_t?) {
    var sector_1 : int
    var c2da_fresh45 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(str_22))))
    saveg_read_thinker_t(unsafe(reinterpret<thinker_s?>(c2da_fresh45)))
    sector_1 = saveg_read32()
    str_22.sector = unsafe(addr(unsafe(sectors[sector_1])))
    str_22.count = saveg_read32()
    str_22.maxlight = saveg_read32()
    str_22.minlight = saveg_read32()
    str_22.maxtime = saveg_read32()
    str_22.mintime = saveg_read32()
    return
}
[sideeffects]
def private saveg_read_plat_t(var str_23 : plat_t?) {
    var sector_2 : int
    var c2da_fresh46 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(str_23))))
    saveg_read_thinker_t(unsafe(reinterpret<thinker_s?>(c2da_fresh46)))
    sector_2 = saveg_read32()
    str_23.sector = unsafe(addr(unsafe(sectors[sector_2])))
    str_23.speed = saveg_read32()
    str_23.low = saveg_read32()
    str_23.high = saveg_read32()
    str_23.wait = saveg_read32()
    str_23.count = saveg_read32()
    str_23.status = unsafe(reinterpret<plat_e>(uint(saveg_read32())))
    str_23.oldstatus = unsafe(reinterpret<plat_e>(uint(saveg_read32())))
    str_23.crush = uint(saveg_read32())
    str_23.tag = saveg_read32()
    str_23.type_0 = unsafe(reinterpret<plattype_e>(uint(saveg_read32())))
    return
}
[sideeffects]
def private saveg_read_floormove_t(var str_24 : floormove_t?) {
    var sector_3 : int
    var c2da_fresh47 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(str_24))))
    saveg_read_thinker_t(unsafe(reinterpret<thinker_s?>(c2da_fresh47)))
    str_24.type_0 = unsafe(reinterpret<floor_e>(uint(saveg_read32())))
    str_24.crush = uint(saveg_read32())
    sector_3 = saveg_read32()
    str_24.sector = unsafe(addr(unsafe(sectors[sector_3])))
    str_24.direction = saveg_read32()
    str_24.newspecial = saveg_read32()
    str_24.texture = saveg_read16()
    str_24.floordestheight = saveg_read32()
    str_24.speed = saveg_read32()
    return
}
[sideeffects]
def private saveg_read_vldoor_t(var str_25 : vldoor_t?) {
    var sector_4 : int
    var c2da_fresh48 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(str_25))))
    saveg_read_thinker_t(unsafe(reinterpret<thinker_s?>(c2da_fresh48)))
    str_25.type_0 = unsafe(reinterpret<vldoor_e>(uint(saveg_read32())))
    sector_4 = saveg_read32()
    str_25.sector = unsafe(addr(unsafe(sectors[sector_4])))
    str_25.topheight = saveg_read32()
    str_25.speed = saveg_read32()
    str_25.direction = saveg_read32()
    str_25.topwait = saveg_read32()
    str_25.topcountdown = saveg_read32()
    return
}
[sideeffects]
def private saveg_read_ceiling_t(var str_26 : ceiling_t?) {
    var sector_5 : int
    var c2da_fresh49 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(str_26))))
    saveg_read_thinker_t(unsafe(reinterpret<thinker_s?>(c2da_fresh49)))
    str_26.type_0 = unsafe(reinterpret<ceiling_e>(uint(saveg_read32())))
    sector_5 = saveg_read32()
    str_26.sector = unsafe(addr(unsafe(sectors[sector_5])))
    str_26.bottomheight = saveg_read32()
    str_26.topheight = saveg_read32()
    str_26.speed = saveg_read32()
    str_26.crush = uint(saveg_read32())
    str_26.direction = saveg_read32()
    str_26.tag = saveg_read32()
    str_26.olddirection = saveg_read32()
    return
}
var savegamelength : int = default<int>

var specials_e : uint = default<uint>

[sideeffects]
def private c2da_layout_proofs_21() {
    static_assert(typeinfo sizeof(type<_IO_FILE>) == 216, "C layout of _IO_FILE: sizeof")
    static_assert(typeinfo alignof(type<_IO_FILE>) == 8, "C layout of _IO_FILE: alignof")
    static_assert(typeinfo offsetof<_flags>(type<_IO_FILE>) == 0, "C layout of _IO_FILE: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<_IO_FILE>) == 8, "C layout of _IO_FILE: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<_IO_FILE>) == 16, "C layout of _IO_FILE: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<_IO_FILE>) == 24, "C layout of _IO_FILE: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<_IO_FILE>) == 32, "C layout of _IO_FILE: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<_IO_FILE>) == 40, "C layout of _IO_FILE: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<_IO_FILE>) == 48, "C layout of _IO_FILE: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<_IO_FILE>) == 56, "C layout of _IO_FILE: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<_IO_FILE>) == 64, "C layout of _IO_FILE: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<_IO_FILE>) == 72, "C layout of _IO_FILE: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<_IO_FILE>) == 80, "C layout of _IO_FILE: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<_IO_FILE>) == 88, "C layout of _IO_FILE: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<_IO_FILE>) == 96, "C layout of _IO_FILE: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<_IO_FILE>) == 104, "C layout of _IO_FILE: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<_IO_FILE>) == 112, "C layout of _IO_FILE: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<_IO_FILE>) == 116, "C layout of _IO_FILE: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<_IO_FILE>) == 120, "C layout of _IO_FILE: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<_IO_FILE>) == 128, "C layout of _IO_FILE: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<_IO_FILE>) == 130, "C layout of _IO_FILE: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<_IO_FILE>) == 131, "C layout of _IO_FILE: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<_IO_FILE>) == 136, "C layout of _IO_FILE: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<_IO_FILE>) == 144, "C layout of _IO_FILE: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<_IO_FILE>) == 152, "C layout of _IO_FILE: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<_IO_FILE>) == 160, "C layout of _IO_FILE: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<_IO_FILE>) == 168, "C layout of _IO_FILE: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<_IO_FILE>) == 176, "C layout of _IO_FILE: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<_IO_FILE>) == 184, "C layout of _IO_FILE: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<_IO_FILE>) == 192, "C layout of _IO_FILE: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<_IO_FILE>) == 196, "C layout of _IO_FILE: offsetof _unused2")
    static_assert(typeinfo sizeof(type<FILE_0>) == 216, "C layout of FILE_0: sizeof")
    static_assert(typeinfo alignof(type<FILE_0>) == 8, "C layout of FILE_0: alignof")
    static_assert(typeinfo offsetof<_flags>(type<FILE_0>) == 0, "C layout of FILE_0: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<FILE_0>) == 8, "C layout of FILE_0: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<FILE_0>) == 16, "C layout of FILE_0: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<FILE_0>) == 24, "C layout of FILE_0: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<FILE_0>) == 32, "C layout of FILE_0: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<FILE_0>) == 40, "C layout of FILE_0: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<FILE_0>) == 48, "C layout of FILE_0: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<FILE_0>) == 56, "C layout of FILE_0: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<FILE_0>) == 64, "C layout of FILE_0: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<FILE_0>) == 72, "C layout of FILE_0: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<FILE_0>) == 80, "C layout of FILE_0: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<FILE_0>) == 88, "C layout of FILE_0: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<FILE_0>) == 96, "C layout of FILE_0: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<FILE_0>) == 104, "C layout of FILE_0: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<FILE_0>) == 112, "C layout of FILE_0: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<FILE_0>) == 116, "C layout of FILE_0: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<FILE_0>) == 120, "C layout of FILE_0: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<FILE_0>) == 128, "C layout of FILE_0: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<FILE_0>) == 130, "C layout of FILE_0: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<FILE_0>) == 131, "C layout of FILE_0: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<FILE_0>) == 136, "C layout of FILE_0: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<FILE_0>) == 144, "C layout of FILE_0: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<FILE_0>) == 152, "C layout of FILE_0: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<FILE_0>) == 160, "C layout of FILE_0: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<FILE_0>) == 168, "C layout of FILE_0: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<FILE_0>) == 176, "C layout of FILE_0: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<FILE_0>) == 184, "C layout of FILE_0: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<FILE_0>) == 192, "C layout of FILE_0: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<FILE_0>) == 196, "C layout of FILE_0: offsetof _unused2")
    static_assert(typeinfo sizeof(type<ticcmd_t>) == 16, "C layout of ticcmd_t: sizeof")
    static_assert(typeinfo alignof(type<ticcmd_t>) == 4, "C layout of ticcmd_t: alignof")
    static_assert(typeinfo offsetof<forwardmove>(type<ticcmd_t>) == 0, "C layout of ticcmd_t: offsetof forwardmove")
    static_assert(typeinfo offsetof<sidemove>(type<ticcmd_t>) == 1, "C layout of ticcmd_t: offsetof sidemove")
    static_assert(typeinfo offsetof<angleturn>(type<ticcmd_t>) == 2, "C layout of ticcmd_t: offsetof angleturn")
    static_assert(typeinfo offsetof<chatchar>(type<ticcmd_t>) == 4, "C layout of ticcmd_t: offsetof chatchar")
    static_assert(typeinfo offsetof<buttons>(type<ticcmd_t>) == 5, "C layout of ticcmd_t: offsetof buttons")
    static_assert(typeinfo offsetof<consistancy>(type<ticcmd_t>) == 6, "C layout of ticcmd_t: offsetof consistancy")
    static_assert(typeinfo offsetof<buttons2>(type<ticcmd_t>) == 7, "C layout of ticcmd_t: offsetof buttons2")
    static_assert(typeinfo offsetof<inventory>(type<ticcmd_t>) == 8, "C layout of ticcmd_t: offsetof inventory")
    static_assert(typeinfo offsetof<lookfly>(type<ticcmd_t>) == 12, "C layout of ticcmd_t: offsetof lookfly")
    static_assert(typeinfo offsetof<arti>(type<ticcmd_t>) == 13, "C layout of ticcmd_t: offsetof arti")
    static_assert(typeinfo sizeof(type<thinker_s>) == 24, "C layout of thinker_s: sizeof")
    static_assert(typeinfo alignof(type<thinker_s>) == 8, "C layout of thinker_s: alignof")
    static_assert(typeinfo offsetof<prev>(type<thinker_s>) == 0, "C layout of thinker_s: offsetof prev")
    static_assert(typeinfo offsetof<next>(type<thinker_s>) == 8, "C layout of thinker_s: offsetof next")
    static_assert(typeinfo offsetof<function_0>(type<thinker_s>) == 16, "C layout of thinker_s: offsetof function_0")
    static_assert(typeinfo sizeof(type<thinker_t>) == 24, "C layout of thinker_t: sizeof")
    static_assert(typeinfo alignof(type<thinker_t>) == 8, "C layout of thinker_t: alignof")
    static_assert(typeinfo offsetof<prev>(type<thinker_t>) == 0, "C layout of thinker_t: offsetof prev")
    static_assert(typeinfo offsetof<next>(type<thinker_t>) == 8, "C layout of thinker_t: offsetof next")
    static_assert(typeinfo offsetof<function_0>(type<thinker_t>) == 16, "C layout of thinker_t: offsetof function_0")
    static_assert(typeinfo sizeof(type<state_t>) == 40, "C layout of state_t: sizeof")
    static_assert(typeinfo alignof(type<state_t>) == 8, "C layout of state_t: alignof")
    static_assert(typeinfo offsetof<sprite>(type<state_t>) == 0, "C layout of state_t: offsetof sprite")
    static_assert(typeinfo offsetof<frame>(type<state_t>) == 4, "C layout of state_t: offsetof frame")
    static_assert(typeinfo offsetof<tics>(type<state_t>) == 8, "C layout of state_t: offsetof tics")
    static_assert(typeinfo offsetof<action>(type<state_t>) == 16, "C layout of state_t: offsetof action")
    static_assert(typeinfo offsetof<nextstate>(type<state_t>) == 24, "C layout of state_t: offsetof nextstate")
    static_assert(typeinfo offsetof<misc1>(type<state_t>) == 28, "C layout of state_t: offsetof misc1")
    static_assert(typeinfo offsetof<misc2>(type<state_t>) == 32, "C layout of state_t: offsetof misc2")
    static_assert(typeinfo sizeof(type<mobjinfo_t>) == 92, "C layout of mobjinfo_t: sizeof")
    static_assert(typeinfo alignof(type<mobjinfo_t>) == 4, "C layout of mobjinfo_t: alignof")
    static_assert(typeinfo offsetof<doomednum>(type<mobjinfo_t>) == 0, "C layout of mobjinfo_t: offsetof doomednum")
    static_assert(typeinfo offsetof<spawnstate>(type<mobjinfo_t>) == 4, "C layout of mobjinfo_t: offsetof spawnstate")
    static_assert(typeinfo offsetof<spawnhealth>(type<mobjinfo_t>) == 8, "C layout of mobjinfo_t: offsetof spawnhealth")
    static_assert(typeinfo offsetof<seestate>(type<mobjinfo_t>) == 12, "C layout of mobjinfo_t: offsetof seestate")
    static_assert(typeinfo offsetof<seesound>(type<mobjinfo_t>) == 16, "C layout of mobjinfo_t: offsetof seesound")
    static_assert(typeinfo offsetof<reactiontime>(type<mobjinfo_t>) == 20, "C layout of mobjinfo_t: offsetof reactiontime")
    static_assert(typeinfo offsetof<attacksound>(type<mobjinfo_t>) == 24, "C layout of mobjinfo_t: offsetof attacksound")
    static_assert(typeinfo offsetof<painstate>(type<mobjinfo_t>) == 28, "C layout of mobjinfo_t: offsetof painstate")
    static_assert(typeinfo offsetof<painchance>(type<mobjinfo_t>) == 32, "C layout of mobjinfo_t: offsetof painchance")
    static_assert(typeinfo offsetof<painsound>(type<mobjinfo_t>) == 36, "C layout of mobjinfo_t: offsetof painsound")
    static_assert(typeinfo offsetof<meleestate>(type<mobjinfo_t>) == 40, "C layout of mobjinfo_t: offsetof meleestate")
    static_assert(typeinfo offsetof<missilestate>(type<mobjinfo_t>) == 44, "C layout of mobjinfo_t: offsetof missilestate")
    static_assert(typeinfo offsetof<deathstate>(type<mobjinfo_t>) == 48, "C layout of mobjinfo_t: offsetof deathstate")
    static_assert(typeinfo offsetof<xdeathstate>(type<mobjinfo_t>) == 52, "C layout of mobjinfo_t: offsetof xdeathstate")
    static_assert(typeinfo offsetof<deathsound>(type<mobjinfo_t>) == 56, "C layout of mobjinfo_t: offsetof deathsound")
    static_assert(typeinfo offsetof<speed>(type<mobjinfo_t>) == 60, "C layout of mobjinfo_t: offsetof speed")
    static_assert(typeinfo offsetof<radius>(type<mobjinfo_t>) == 64, "C layout of mobjinfo_t: offsetof radius")
    static_assert(typeinfo offsetof<height>(type<mobjinfo_t>) == 68, "C layout of mobjinfo_t: offsetof height")
    static_assert(typeinfo offsetof<mass>(type<mobjinfo_t>) == 72, "C layout of mobjinfo_t: offsetof mass")
    static_assert(typeinfo offsetof<damage>(type<mobjinfo_t>) == 76, "C layout of mobjinfo_t: offsetof damage")
    static_assert(typeinfo offsetof<activesound>(type<mobjinfo_t>) == 80, "C layout of mobjinfo_t: offsetof activesound")
    static_assert(typeinfo offsetof<flags>(type<mobjinfo_t>) == 84, "C layout of mobjinfo_t: offsetof flags")
    static_assert(typeinfo offsetof<raisestate>(type<mobjinfo_t>) == 88, "C layout of mobjinfo_t: offsetof raisestate")
    static_assert(typeinfo sizeof(type<mobj_s>) == 224, "C layout of mobj_s: sizeof")
    static_assert(typeinfo alignof(type<mobj_s>) == 8, "C layout of mobj_s: alignof")
    static_assert(typeinfo offsetof<thinker>(type<mobj_s>) == 0, "C layout of mobj_s: offsetof thinker")
    static_assert(typeinfo offsetof<x>(type<mobj_s>) == 24, "C layout of mobj_s: offsetof x")
    static_assert(typeinfo offsetof<y>(type<mobj_s>) == 28, "C layout of mobj_s: offsetof y")
    static_assert(typeinfo offsetof<z>(type<mobj_s>) == 32, "C layout of mobj_s: offsetof z")
    static_assert(typeinfo offsetof<snext>(type<mobj_s>) == 40, "C layout of mobj_s: offsetof snext")
    static_assert(typeinfo offsetof<sprev>(type<mobj_s>) == 48, "C layout of mobj_s: offsetof sprev")
    static_assert(typeinfo offsetof<angle>(type<mobj_s>) == 56, "C layout of mobj_s: offsetof angle")
    static_assert(typeinfo offsetof<sprite>(type<mobj_s>) == 60, "C layout of mobj_s: offsetof sprite")
    static_assert(typeinfo offsetof<frame>(type<mobj_s>) == 64, "C layout of mobj_s: offsetof frame")
    static_assert(typeinfo offsetof<bnext>(type<mobj_s>) == 72, "C layout of mobj_s: offsetof bnext")
    static_assert(typeinfo offsetof<bprev>(type<mobj_s>) == 80, "C layout of mobj_s: offsetof bprev")
    static_assert(typeinfo offsetof<subsector>(type<mobj_s>) == 88, "C layout of mobj_s: offsetof subsector")
    static_assert(typeinfo offsetof<floorz>(type<mobj_s>) == 96, "C layout of mobj_s: offsetof floorz")
    static_assert(typeinfo offsetof<ceilingz>(type<mobj_s>) == 100, "C layout of mobj_s: offsetof ceilingz")
    static_assert(typeinfo offsetof<radius>(type<mobj_s>) == 104, "C layout of mobj_s: offsetof radius")
    static_assert(typeinfo offsetof<height>(type<mobj_s>) == 108, "C layout of mobj_s: offsetof height")
    static_assert(typeinfo offsetof<momx>(type<mobj_s>) == 112, "C layout of mobj_s: offsetof momx")
    static_assert(typeinfo offsetof<momy>(type<mobj_s>) == 116, "C layout of mobj_s: offsetof momy")
    static_assert(typeinfo offsetof<momz>(type<mobj_s>) == 120, "C layout of mobj_s: offsetof momz")
    static_assert(typeinfo offsetof<validcount>(type<mobj_s>) == 124, "C layout of mobj_s: offsetof validcount")
    static_assert(typeinfo offsetof<type_0>(type<mobj_s>) == 128, "C layout of mobj_s: offsetof type_0")
    static_assert(typeinfo offsetof<info>(type<mobj_s>) == 136, "C layout of mobj_s: offsetof info")
    static_assert(typeinfo offsetof<tics>(type<mobj_s>) == 144, "C layout of mobj_s: offsetof tics")
    static_assert(typeinfo offsetof<state>(type<mobj_s>) == 152, "C layout of mobj_s: offsetof state")
    static_assert(typeinfo offsetof<flags>(type<mobj_s>) == 160, "C layout of mobj_s: offsetof flags")
    static_assert(typeinfo offsetof<health>(type<mobj_s>) == 164, "C layout of mobj_s: offsetof health")
    static_assert(typeinfo offsetof<movedir>(type<mobj_s>) == 168, "C layout of mobj_s: offsetof movedir")
    static_assert(typeinfo offsetof<movecount>(type<mobj_s>) == 172, "C layout of mobj_s: offsetof movecount")
    static_assert(typeinfo offsetof<target>(type<mobj_s>) == 176, "C layout of mobj_s: offsetof target")
    static_assert(typeinfo offsetof<reactiontime>(type<mobj_s>) == 184, "C layout of mobj_s: offsetof reactiontime")
    static_assert(typeinfo offsetof<threshold>(type<mobj_s>) == 188, "C layout of mobj_s: offsetof threshold")
    static_assert(typeinfo offsetof<player>(type<mobj_s>) == 192, "C layout of mobj_s: offsetof player")
    static_assert(typeinfo offsetof<lastlook>(type<mobj_s>) == 200, "C layout of mobj_s: offsetof lastlook")
    static_assert(typeinfo offsetof<spawnpoint>(type<mobj_s>) == 204, "C layout of mobj_s: offsetof spawnpoint")
    static_assert(typeinfo offsetof<tracer>(type<mobj_s>) == 216, "C layout of mobj_s: offsetof tracer")
    static_assert(typeinfo sizeof(type<player_s>) == 328, "C layout of player_s: sizeof")
    static_assert(typeinfo alignof(type<player_s>) == 8, "C layout of player_s: alignof")
    static_assert(typeinfo offsetof<mo>(type<player_s>) == 0, "C layout of player_s: offsetof mo")
    static_assert(typeinfo offsetof<playerstate>(type<player_s>) == 8, "C layout of player_s: offsetof playerstate")
    static_assert(typeinfo offsetof<cmd>(type<player_s>) == 12, "C layout of player_s: offsetof cmd")
    static_assert(typeinfo offsetof<viewz>(type<player_s>) == 28, "C layout of player_s: offsetof viewz")
    static_assert(typeinfo offsetof<viewheight>(type<player_s>) == 32, "C layout of player_s: offsetof viewheight")
    static_assert(typeinfo offsetof<deltaviewheight>(type<player_s>) == 36, "C layout of player_s: offsetof deltaviewheight")
    static_assert(typeinfo offsetof<bob>(type<player_s>) == 40, "C layout of player_s: offsetof bob")
    static_assert(typeinfo offsetof<health>(type<player_s>) == 44, "C layout of player_s: offsetof health")
    static_assert(typeinfo offsetof<armorpoints>(type<player_s>) == 48, "C layout of player_s: offsetof armorpoints")
    static_assert(typeinfo offsetof<armortype>(type<player_s>) == 52, "C layout of player_s: offsetof armortype")
    static_assert(typeinfo offsetof<powers>(type<player_s>) == 56, "C layout of player_s: offsetof powers")
    static_assert(typeinfo offsetof<cards>(type<player_s>) == 80, "C layout of player_s: offsetof cards")
    static_assert(typeinfo offsetof<backpack>(type<player_s>) == 104, "C layout of player_s: offsetof backpack")
    static_assert(typeinfo offsetof<frags>(type<player_s>) == 108, "C layout of player_s: offsetof frags")
    static_assert(typeinfo offsetof<readyweapon>(type<player_s>) == 124, "C layout of player_s: offsetof readyweapon")
    static_assert(typeinfo offsetof<pendingweapon>(type<player_s>) == 128, "C layout of player_s: offsetof pendingweapon")
    static_assert(typeinfo offsetof<weaponowned>(type<player_s>) == 132, "C layout of player_s: offsetof weaponowned")
    static_assert(typeinfo offsetof<ammo>(type<player_s>) == 168, "C layout of player_s: offsetof ammo")
    static_assert(typeinfo offsetof<maxammo>(type<player_s>) == 184, "C layout of player_s: offsetof maxammo")
    static_assert(typeinfo offsetof<attackdown>(type<player_s>) == 200, "C layout of player_s: offsetof attackdown")
    static_assert(typeinfo offsetof<usedown>(type<player_s>) == 204, "C layout of player_s: offsetof usedown")
    static_assert(typeinfo offsetof<cheats>(type<player_s>) == 208, "C layout of player_s: offsetof cheats")
    static_assert(typeinfo offsetof<refire>(type<player_s>) == 212, "C layout of player_s: offsetof refire")
    static_assert(typeinfo offsetof<killcount>(type<player_s>) == 216, "C layout of player_s: offsetof killcount")
    static_assert(typeinfo offsetof<itemcount>(type<player_s>) == 220, "C layout of player_s: offsetof itemcount")
    static_assert(typeinfo offsetof<secretcount>(type<player_s>) == 224, "C layout of player_s: offsetof secretcount")
    static_assert(typeinfo offsetof<message>(type<player_s>) == 232, "C layout of player_s: offsetof message")
    static_assert(typeinfo offsetof<damagecount>(type<player_s>) == 240, "C layout of player_s: offsetof damagecount")
    static_assert(typeinfo offsetof<bonuscount>(type<player_s>) == 244, "C layout of player_s: offsetof bonuscount")
    static_assert(typeinfo offsetof<attacker>(type<player_s>) == 248, "C layout of player_s: offsetof attacker")
    static_assert(typeinfo offsetof<extralight>(type<player_s>) == 256, "C layout of player_s: offsetof extralight")
    static_assert(typeinfo offsetof<fixedcolormap>(type<player_s>) == 260, "C layout of player_s: offsetof fixedcolormap")
    static_assert(typeinfo offsetof<colormap>(type<player_s>) == 264, "C layout of player_s: offsetof colormap")
    static_assert(typeinfo offsetof<psprites>(type<player_s>) == 272, "C layout of player_s: offsetof psprites")
    static_assert(typeinfo offsetof<didsecret>(type<player_s>) == 320, "C layout of player_s: offsetof didsecret")
    static_assert(typeinfo sizeof(type<pspdef_t>) == 24, "C layout of pspdef_t: sizeof")
    static_assert(typeinfo alignof(type<pspdef_t>) == 8, "C layout of pspdef_t: alignof")
    static_assert(typeinfo offsetof<state>(type<pspdef_t>) == 0, "C layout of pspdef_t: offsetof state")
    static_assert(typeinfo offsetof<tics>(type<pspdef_t>) == 8, "C layout of pspdef_t: offsetof tics")
    static_assert(typeinfo offsetof<sx>(type<pspdef_t>) == 12, "C layout of pspdef_t: offsetof sx")
    static_assert(typeinfo offsetof<sy>(type<pspdef_t>) == 16, "C layout of pspdef_t: offsetof sy")
    static_assert(typeinfo sizeof(type<mobj_t>) == 224, "C layout of mobj_t: sizeof")
    static_assert(typeinfo alignof(type<mobj_t>) == 8, "C layout of mobj_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<mobj_t>) == 0, "C layout of mobj_t: offsetof thinker")
    static_assert(typeinfo offsetof<x>(type<mobj_t>) == 24, "C layout of mobj_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<mobj_t>) == 28, "C layout of mobj_t: offsetof y")
    static_assert(typeinfo offsetof<z>(type<mobj_t>) == 32, "C layout of mobj_t: offsetof z")
    static_assert(typeinfo offsetof<snext>(type<mobj_t>) == 40, "C layout of mobj_t: offsetof snext")
    static_assert(typeinfo offsetof<sprev>(type<mobj_t>) == 48, "C layout of mobj_t: offsetof sprev")
    static_assert(typeinfo offsetof<angle>(type<mobj_t>) == 56, "C layout of mobj_t: offsetof angle")
    static_assert(typeinfo offsetof<sprite>(type<mobj_t>) == 60, "C layout of mobj_t: offsetof sprite")
    static_assert(typeinfo offsetof<frame>(type<mobj_t>) == 64, "C layout of mobj_t: offsetof frame")
    static_assert(typeinfo offsetof<bnext>(type<mobj_t>) == 72, "C layout of mobj_t: offsetof bnext")
    static_assert(typeinfo offsetof<bprev>(type<mobj_t>) == 80, "C layout of mobj_t: offsetof bprev")
    static_assert(typeinfo offsetof<subsector>(type<mobj_t>) == 88, "C layout of mobj_t: offsetof subsector")
    static_assert(typeinfo offsetof<floorz>(type<mobj_t>) == 96, "C layout of mobj_t: offsetof floorz")
    static_assert(typeinfo offsetof<ceilingz>(type<mobj_t>) == 100, "C layout of mobj_t: offsetof ceilingz")
    static_assert(typeinfo offsetof<radius>(type<mobj_t>) == 104, "C layout of mobj_t: offsetof radius")
    static_assert(typeinfo offsetof<height>(type<mobj_t>) == 108, "C layout of mobj_t: offsetof height")
    static_assert(typeinfo offsetof<momx>(type<mobj_t>) == 112, "C layout of mobj_t: offsetof momx")
    static_assert(typeinfo offsetof<momy>(type<mobj_t>) == 116, "C layout of mobj_t: offsetof momy")
    static_assert(typeinfo offsetof<momz>(type<mobj_t>) == 120, "C layout of mobj_t: offsetof momz")
    static_assert(typeinfo offsetof<validcount>(type<mobj_t>) == 124, "C layout of mobj_t: offsetof validcount")
    static_assert(typeinfo offsetof<type_0>(type<mobj_t>) == 128, "C layout of mobj_t: offsetof type_0")
    static_assert(typeinfo offsetof<info>(type<mobj_t>) == 136, "C layout of mobj_t: offsetof info")
    static_assert(typeinfo offsetof<tics>(type<mobj_t>) == 144, "C layout of mobj_t: offsetof tics")
    static_assert(typeinfo offsetof<state>(type<mobj_t>) == 152, "C layout of mobj_t: offsetof state")
    static_assert(typeinfo offsetof<flags>(type<mobj_t>) == 160, "C layout of mobj_t: offsetof flags")
    static_assert(typeinfo offsetof<health>(type<mobj_t>) == 164, "C layout of mobj_t: offsetof health")
    static_assert(typeinfo offsetof<movedir>(type<mobj_t>) == 168, "C layout of mobj_t: offsetof movedir")
    static_assert(typeinfo offsetof<movecount>(type<mobj_t>) == 172, "C layout of mobj_t: offsetof movecount")
    static_assert(typeinfo offsetof<target>(type<mobj_t>) == 176, "C layout of mobj_t: offsetof target")
    static_assert(typeinfo offsetof<reactiontime>(type<mobj_t>) == 184, "C layout of mobj_t: offsetof reactiontime")
    static_assert(typeinfo offsetof<threshold>(type<mobj_t>) == 188, "C layout of mobj_t: offsetof threshold")
    static_assert(typeinfo offsetof<player>(type<mobj_t>) == 192, "C layout of mobj_t: offsetof player")
    static_assert(typeinfo offsetof<lastlook>(type<mobj_t>) == 200, "C layout of mobj_t: offsetof lastlook")
    static_assert(typeinfo offsetof<spawnpoint>(type<mobj_t>) == 204, "C layout of mobj_t: offsetof spawnpoint")
    static_assert(typeinfo offsetof<tracer>(type<mobj_t>) == 216, "C layout of mobj_t: offsetof tracer")
    static_assert(typeinfo sizeof(type<subsector_s>) == 16, "C layout of subsector_s: sizeof")
    static_assert(typeinfo alignof(type<subsector_s>) == 8, "C layout of subsector_s: alignof")
    static_assert(typeinfo offsetof<sector>(type<subsector_s>) == 0, "C layout of subsector_s: offsetof sector")
    static_assert(typeinfo offsetof<numlines>(type<subsector_s>) == 8, "C layout of subsector_s: offsetof numlines")
    static_assert(typeinfo offsetof<firstline>(type<subsector_s>) == 10, "C layout of subsector_s: offsetof firstline")
    static_assert(typeinfo sizeof(type<sector_t>) == 128, "C layout of sector_t: sizeof")
    static_assert(typeinfo alignof(type<sector_t>) == 8, "C layout of sector_t: alignof")
    static_assert(typeinfo offsetof<floorheight>(type<sector_t>) == 0, "C layout of sector_t: offsetof floorheight")
    static_assert(typeinfo offsetof<ceilingheight>(type<sector_t>) == 4, "C layout of sector_t: offsetof ceilingheight")
    static_assert(typeinfo offsetof<floorpic>(type<sector_t>) == 8, "C layout of sector_t: offsetof floorpic")
    static_assert(typeinfo offsetof<ceilingpic>(type<sector_t>) == 10, "C layout of sector_t: offsetof ceilingpic")
    static_assert(typeinfo offsetof<lightlevel>(type<sector_t>) == 12, "C layout of sector_t: offsetof lightlevel")
    static_assert(typeinfo offsetof<special>(type<sector_t>) == 14, "C layout of sector_t: offsetof special")
    static_assert(typeinfo offsetof<tag>(type<sector_t>) == 16, "C layout of sector_t: offsetof tag")
    static_assert(typeinfo offsetof<soundtraversed>(type<sector_t>) == 20, "C layout of sector_t: offsetof soundtraversed")
    static_assert(typeinfo offsetof<soundtarget>(type<sector_t>) == 24, "C layout of sector_t: offsetof soundtarget")
    static_assert(typeinfo offsetof<blockbox>(type<sector_t>) == 32, "C layout of sector_t: offsetof blockbox")
    static_assert(typeinfo offsetof<soundorg>(type<sector_t>) == 48, "C layout of sector_t: offsetof soundorg")
    static_assert(typeinfo offsetof<validcount>(type<sector_t>) == 88, "C layout of sector_t: offsetof validcount")
    static_assert(typeinfo offsetof<thinglist>(type<sector_t>) == 96, "C layout of sector_t: offsetof thinglist")
    static_assert(typeinfo offsetof<specialdata>(type<sector_t>) == 104, "C layout of sector_t: offsetof specialdata")
    static_assert(typeinfo offsetof<linecount>(type<sector_t>) == 112, "C layout of sector_t: offsetof linecount")
    static_assert(typeinfo offsetof<lines>(type<sector_t>) == 120, "C layout of sector_t: offsetof lines")
    static_assert(typeinfo sizeof(type<line_s>) == 88, "C layout of line_s: sizeof")
    static_assert(typeinfo alignof(type<line_s>) == 8, "C layout of line_s: alignof")
    static_assert(typeinfo offsetof<v1>(type<line_s>) == 0, "C layout of line_s: offsetof v1")
    static_assert(typeinfo offsetof<v2>(type<line_s>) == 8, "C layout of line_s: offsetof v2")
    static_assert(typeinfo offsetof<dx>(type<line_s>) == 16, "C layout of line_s: offsetof dx")
    static_assert(typeinfo offsetof<dy>(type<line_s>) == 20, "C layout of line_s: offsetof dy")
    static_assert(typeinfo offsetof<flags>(type<line_s>) == 24, "C layout of line_s: offsetof flags")
    static_assert(typeinfo offsetof<special>(type<line_s>) == 26, "C layout of line_s: offsetof special")
    static_assert(typeinfo offsetof<tag>(type<line_s>) == 28, "C layout of line_s: offsetof tag")
    static_assert(typeinfo offsetof<sidenum>(type<line_s>) == 30, "C layout of line_s: offsetof sidenum")
    static_assert(typeinfo offsetof<bbox>(type<line_s>) == 36, "C layout of line_s: offsetof bbox")
    static_assert(typeinfo offsetof<slopetype>(type<line_s>) == 52, "C layout of line_s: offsetof slopetype")
    static_assert(typeinfo offsetof<frontsector>(type<line_s>) == 56, "C layout of line_s: offsetof frontsector")
    static_assert(typeinfo offsetof<backsector>(type<line_s>) == 64, "C layout of line_s: offsetof backsector")
    static_assert(typeinfo offsetof<validcount>(type<line_s>) == 72, "C layout of line_s: offsetof validcount")
    static_assert(typeinfo offsetof<specialdata>(type<line_s>) == 80, "C layout of line_s: offsetof specialdata")
    static_assert(typeinfo sizeof(type<vertex_t>) == 8, "C layout of vertex_t: sizeof")
    static_assert(typeinfo alignof(type<vertex_t>) == 4, "C layout of vertex_t: alignof")
    static_assert(typeinfo offsetof<x>(type<vertex_t>) == 0, "C layout of vertex_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<vertex_t>) == 4, "C layout of vertex_t: offsetof y")
    static_assert(typeinfo sizeof(type<degenmobj_t>) == 40, "C layout of degenmobj_t: sizeof")
    static_assert(typeinfo alignof(type<degenmobj_t>) == 8, "C layout of degenmobj_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<degenmobj_t>) == 0, "C layout of degenmobj_t: offsetof thinker")
    static_assert(typeinfo offsetof<x>(type<degenmobj_t>) == 24, "C layout of degenmobj_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<degenmobj_t>) == 28, "C layout of degenmobj_t: offsetof y")
    static_assert(typeinfo offsetof<z>(type<degenmobj_t>) == 32, "C layout of degenmobj_t: offsetof z")
    static_assert(typeinfo sizeof(type<side_t>) == 24, "C layout of side_t: sizeof")
    static_assert(typeinfo alignof(type<side_t>) == 8, "C layout of side_t: alignof")
    static_assert(typeinfo offsetof<textureoffset>(type<side_t>) == 0, "C layout of side_t: offsetof textureoffset")
    static_assert(typeinfo offsetof<rowoffset>(type<side_t>) == 4, "C layout of side_t: offsetof rowoffset")
    static_assert(typeinfo offsetof<toptexture>(type<side_t>) == 8, "C layout of side_t: offsetof toptexture")
    static_assert(typeinfo offsetof<bottomtexture>(type<side_t>) == 10, "C layout of side_t: offsetof bottomtexture")
    static_assert(typeinfo offsetof<midtexture>(type<side_t>) == 12, "C layout of side_t: offsetof midtexture")
    static_assert(typeinfo offsetof<sector>(type<side_t>) == 16, "C layout of side_t: offsetof sector")
    static_assert(typeinfo sizeof(type<line_t>) == 88, "C layout of line_t: sizeof")
    static_assert(typeinfo alignof(type<line_t>) == 8, "C layout of line_t: alignof")
    static_assert(typeinfo offsetof<v1>(type<line_t>) == 0, "C layout of line_t: offsetof v1")
    static_assert(typeinfo offsetof<v2>(type<line_t>) == 8, "C layout of line_t: offsetof v2")
    static_assert(typeinfo offsetof<dx>(type<line_t>) == 16, "C layout of line_t: offsetof dx")
    static_assert(typeinfo offsetof<dy>(type<line_t>) == 20, "C layout of line_t: offsetof dy")
    static_assert(typeinfo offsetof<flags>(type<line_t>) == 24, "C layout of line_t: offsetof flags")
    static_assert(typeinfo offsetof<special>(type<line_t>) == 26, "C layout of line_t: offsetof special")
    static_assert(typeinfo offsetof<tag>(type<line_t>) == 28, "C layout of line_t: offsetof tag")
    static_assert(typeinfo offsetof<sidenum>(type<line_t>) == 30, "C layout of line_t: offsetof sidenum")
    static_assert(typeinfo offsetof<bbox>(type<line_t>) == 36, "C layout of line_t: offsetof bbox")
    static_assert(typeinfo offsetof<slopetype>(type<line_t>) == 52, "C layout of line_t: offsetof slopetype")
    static_assert(typeinfo offsetof<frontsector>(type<line_t>) == 56, "C layout of line_t: offsetof frontsector")
    static_assert(typeinfo offsetof<backsector>(type<line_t>) == 64, "C layout of line_t: offsetof backsector")
    static_assert(typeinfo offsetof<validcount>(type<line_t>) == 72, "C layout of line_t: offsetof validcount")
    static_assert(typeinfo offsetof<specialdata>(type<line_t>) == 80, "C layout of line_t: offsetof specialdata")
    static_assert(typeinfo sizeof(type<player_t>) == 328, "C layout of player_t: sizeof")
    static_assert(typeinfo alignof(type<player_t>) == 8, "C layout of player_t: alignof")
    static_assert(typeinfo offsetof<mo>(type<player_t>) == 0, "C layout of player_t: offsetof mo")
    static_assert(typeinfo offsetof<playerstate>(type<player_t>) == 8, "C layout of player_t: offsetof playerstate")
    static_assert(typeinfo offsetof<cmd>(type<player_t>) == 12, "C layout of player_t: offsetof cmd")
    static_assert(typeinfo offsetof<viewz>(type<player_t>) == 28, "C layout of player_t: offsetof viewz")
    static_assert(typeinfo offsetof<viewheight>(type<player_t>) == 32, "C layout of player_t: offsetof viewheight")
    static_assert(typeinfo offsetof<deltaviewheight>(type<player_t>) == 36, "C layout of player_t: offsetof deltaviewheight")
    static_assert(typeinfo offsetof<bob>(type<player_t>) == 40, "C layout of player_t: offsetof bob")
    static_assert(typeinfo offsetof<health>(type<player_t>) == 44, "C layout of player_t: offsetof health")
    static_assert(typeinfo offsetof<armorpoints>(type<player_t>) == 48, "C layout of player_t: offsetof armorpoints")
    static_assert(typeinfo offsetof<armortype>(type<player_t>) == 52, "C layout of player_t: offsetof armortype")
    static_assert(typeinfo offsetof<powers>(type<player_t>) == 56, "C layout of player_t: offsetof powers")
    static_assert(typeinfo offsetof<cards>(type<player_t>) == 80, "C layout of player_t: offsetof cards")
    static_assert(typeinfo offsetof<backpack>(type<player_t>) == 104, "C layout of player_t: offsetof backpack")
    static_assert(typeinfo offsetof<frags>(type<player_t>) == 108, "C layout of player_t: offsetof frags")
    static_assert(typeinfo offsetof<readyweapon>(type<player_t>) == 124, "C layout of player_t: offsetof readyweapon")
    static_assert(typeinfo offsetof<pendingweapon>(type<player_t>) == 128, "C layout of player_t: offsetof pendingweapon")
    static_assert(typeinfo offsetof<weaponowned>(type<player_t>) == 132, "C layout of player_t: offsetof weaponowned")
    static_assert(typeinfo offsetof<ammo>(type<player_t>) == 168, "C layout of player_t: offsetof ammo")
    static_assert(typeinfo offsetof<maxammo>(type<player_t>) == 184, "C layout of player_t: offsetof maxammo")
    static_assert(typeinfo offsetof<attackdown>(type<player_t>) == 200, "C layout of player_t: offsetof attackdown")
    static_assert(typeinfo offsetof<usedown>(type<player_t>) == 204, "C layout of player_t: offsetof usedown")
    static_assert(typeinfo offsetof<cheats>(type<player_t>) == 208, "C layout of player_t: offsetof cheats")
    static_assert(typeinfo offsetof<refire>(type<player_t>) == 212, "C layout of player_t: offsetof refire")
    static_assert(typeinfo offsetof<killcount>(type<player_t>) == 216, "C layout of player_t: offsetof killcount")
    static_assert(typeinfo offsetof<itemcount>(type<player_t>) == 220, "C layout of player_t: offsetof itemcount")
    static_assert(typeinfo offsetof<secretcount>(type<player_t>) == 224, "C layout of player_t: offsetof secretcount")
    static_assert(typeinfo offsetof<message>(type<player_t>) == 232, "C layout of player_t: offsetof message")
    static_assert(typeinfo offsetof<damagecount>(type<player_t>) == 240, "C layout of player_t: offsetof damagecount")
    static_assert(typeinfo offsetof<bonuscount>(type<player_t>) == 244, "C layout of player_t: offsetof bonuscount")
    static_assert(typeinfo offsetof<attacker>(type<player_t>) == 248, "C layout of player_t: offsetof attacker")
    static_assert(typeinfo offsetof<extralight>(type<player_t>) == 256, "C layout of player_t: offsetof extralight")
    static_assert(typeinfo offsetof<fixedcolormap>(type<player_t>) == 260, "C layout of player_t: offsetof fixedcolormap")
    static_assert(typeinfo offsetof<colormap>(type<player_t>) == 264, "C layout of player_t: offsetof colormap")
    static_assert(typeinfo offsetof<psprites>(type<player_t>) == 272, "C layout of player_t: offsetof psprites")
    static_assert(typeinfo offsetof<didsecret>(type<player_t>) == 320, "C layout of player_t: offsetof didsecret")
    static_assert(typeinfo sizeof(type<lightflash_t>) == 56, "C layout of lightflash_t: sizeof")
    static_assert(typeinfo alignof(type<lightflash_t>) == 8, "C layout of lightflash_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<lightflash_t>) == 0, "C layout of lightflash_t: offsetof thinker")
    static_assert(typeinfo offsetof<sector>(type<lightflash_t>) == 24, "C layout of lightflash_t: offsetof sector")
    static_assert(typeinfo offsetof<count>(type<lightflash_t>) == 32, "C layout of lightflash_t: offsetof count")
    static_assert(typeinfo offsetof<maxlight>(type<lightflash_t>) == 36, "C layout of lightflash_t: offsetof maxlight")
    static_assert(typeinfo offsetof<minlight>(type<lightflash_t>) == 40, "C layout of lightflash_t: offsetof minlight")
    static_assert(typeinfo offsetof<maxtime>(type<lightflash_t>) == 44, "C layout of lightflash_t: offsetof maxtime")
    static_assert(typeinfo offsetof<mintime>(type<lightflash_t>) == 48, "C layout of lightflash_t: offsetof mintime")
    static_assert(typeinfo sizeof(type<strobe_t>) == 56, "C layout of strobe_t: sizeof")
    static_assert(typeinfo alignof(type<strobe_t>) == 8, "C layout of strobe_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<strobe_t>) == 0, "C layout of strobe_t: offsetof thinker")
    static_assert(typeinfo offsetof<sector>(type<strobe_t>) == 24, "C layout of strobe_t: offsetof sector")
    static_assert(typeinfo offsetof<count>(type<strobe_t>) == 32, "C layout of strobe_t: offsetof count")
    static_assert(typeinfo offsetof<minlight>(type<strobe_t>) == 36, "C layout of strobe_t: offsetof minlight")
    static_assert(typeinfo offsetof<maxlight>(type<strobe_t>) == 40, "C layout of strobe_t: offsetof maxlight")
    static_assert(typeinfo offsetof<darktime>(type<strobe_t>) == 44, "C layout of strobe_t: offsetof darktime")
    static_assert(typeinfo offsetof<brighttime>(type<strobe_t>) == 48, "C layout of strobe_t: offsetof brighttime")
    static_assert(typeinfo sizeof(type<glow_t>) == 48, "C layout of glow_t: sizeof")
    static_assert(typeinfo alignof(type<glow_t>) == 8, "C layout of glow_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<glow_t>) == 0, "C layout of glow_t: offsetof thinker")
    static_assert(typeinfo offsetof<sector>(type<glow_t>) == 24, "C layout of glow_t: offsetof sector")
    static_assert(typeinfo offsetof<minlight>(type<glow_t>) == 32, "C layout of glow_t: offsetof minlight")
    static_assert(typeinfo offsetof<maxlight>(type<glow_t>) == 36, "C layout of glow_t: offsetof maxlight")
    static_assert(typeinfo offsetof<direction>(type<glow_t>) == 40, "C layout of glow_t: offsetof direction")
    static_assert(typeinfo sizeof(type<plat_t>) == 72, "C layout of plat_t: sizeof")
    static_assert(typeinfo alignof(type<plat_t>) == 8, "C layout of plat_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<plat_t>) == 0, "C layout of plat_t: offsetof thinker")
    static_assert(typeinfo offsetof<sector>(type<plat_t>) == 24, "C layout of plat_t: offsetof sector")
    static_assert(typeinfo offsetof<speed>(type<plat_t>) == 32, "C layout of plat_t: offsetof speed")
    static_assert(typeinfo offsetof<low>(type<plat_t>) == 36, "C layout of plat_t: offsetof low")
    static_assert(typeinfo offsetof<high>(type<plat_t>) == 40, "C layout of plat_t: offsetof high")
    static_assert(typeinfo offsetof<wait>(type<plat_t>) == 44, "C layout of plat_t: offsetof wait")
    static_assert(typeinfo offsetof<count>(type<plat_t>) == 48, "C layout of plat_t: offsetof count")
    static_assert(typeinfo offsetof<status>(type<plat_t>) == 52, "C layout of plat_t: offsetof status")
    static_assert(typeinfo offsetof<oldstatus>(type<plat_t>) == 56, "C layout of plat_t: offsetof oldstatus")
    static_assert(typeinfo offsetof<crush>(type<plat_t>) == 60, "C layout of plat_t: offsetof crush")
    static_assert(typeinfo offsetof<tag>(type<plat_t>) == 64, "C layout of plat_t: offsetof tag")
    static_assert(typeinfo offsetof<type_0>(type<plat_t>) == 68, "C layout of plat_t: offsetof type_0")
    static_assert(typeinfo sizeof(type<vldoor_t>) == 64, "C layout of vldoor_t: sizeof")
    static_assert(typeinfo alignof(type<vldoor_t>) == 8, "C layout of vldoor_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<vldoor_t>) == 0, "C layout of vldoor_t: offsetof thinker")
    static_assert(typeinfo offsetof<type_0>(type<vldoor_t>) == 24, "C layout of vldoor_t: offsetof type_0")
    static_assert(typeinfo offsetof<sector>(type<vldoor_t>) == 32, "C layout of vldoor_t: offsetof sector")
    static_assert(typeinfo offsetof<topheight>(type<vldoor_t>) == 40, "C layout of vldoor_t: offsetof topheight")
    static_assert(typeinfo offsetof<speed>(type<vldoor_t>) == 44, "C layout of vldoor_t: offsetof speed")
    static_assert(typeinfo offsetof<direction>(type<vldoor_t>) == 48, "C layout of vldoor_t: offsetof direction")
    static_assert(typeinfo offsetof<topwait>(type<vldoor_t>) == 52, "C layout of vldoor_t: offsetof topwait")
    static_assert(typeinfo offsetof<topcountdown>(type<vldoor_t>) == 56, "C layout of vldoor_t: offsetof topcountdown")
    static_assert(typeinfo sizeof(type<ceiling_t>) == 72, "C layout of ceiling_t: sizeof")
    static_assert(typeinfo alignof(type<ceiling_t>) == 8, "C layout of ceiling_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<ceiling_t>) == 0, "C layout of ceiling_t: offsetof thinker")
    static_assert(typeinfo offsetof<type_0>(type<ceiling_t>) == 24, "C layout of ceiling_t: offsetof type_0")
    static_assert(typeinfo offsetof<sector>(type<ceiling_t>) == 32, "C layout of ceiling_t: offsetof sector")
    static_assert(typeinfo offsetof<bottomheight>(type<ceiling_t>) == 40, "C layout of ceiling_t: offsetof bottomheight")
    static_assert(typeinfo offsetof<topheight>(type<ceiling_t>) == 44, "C layout of ceiling_t: offsetof topheight")
    static_assert(typeinfo offsetof<speed>(type<ceiling_t>) == 48, "C layout of ceiling_t: offsetof speed")
    static_assert(typeinfo offsetof<crush>(type<ceiling_t>) == 52, "C layout of ceiling_t: offsetof crush")
    static_assert(typeinfo offsetof<direction>(type<ceiling_t>) == 56, "C layout of ceiling_t: offsetof direction")
    static_assert(typeinfo offsetof<tag>(type<ceiling_t>) == 60, "C layout of ceiling_t: offsetof tag")
    static_assert(typeinfo offsetof<olddirection>(type<ceiling_t>) == 64, "C layout of ceiling_t: offsetof olddirection")
    static_assert(typeinfo sizeof(type<floormove_t>) == 64, "C layout of floormove_t: sizeof")
    static_assert(typeinfo alignof(type<floormove_t>) == 8, "C layout of floormove_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<floormove_t>) == 0, "C layout of floormove_t: offsetof thinker")
    static_assert(typeinfo offsetof<type_0>(type<floormove_t>) == 24, "C layout of floormove_t: offsetof type_0")
    static_assert(typeinfo offsetof<crush>(type<floormove_t>) == 28, "C layout of floormove_t: offsetof crush")
    static_assert(typeinfo offsetof<sector>(type<floormove_t>) == 32, "C layout of floormove_t: offsetof sector")
    static_assert(typeinfo offsetof<direction>(type<floormove_t>) == 40, "C layout of floormove_t: offsetof direction")
    static_assert(typeinfo offsetof<newspecial>(type<floormove_t>) == 44, "C layout of floormove_t: offsetof newspecial")
    static_assert(typeinfo offsetof<texture>(type<floormove_t>) == 48, "C layout of floormove_t: offsetof texture")
    static_assert(typeinfo offsetof<floordestheight>(type<floormove_t>) == 52, "C layout of floormove_t: offsetof floordestheight")
    static_assert(typeinfo offsetof<speed>(type<floormove_t>) == 56, "C layout of floormove_t: offsetof speed")
}
