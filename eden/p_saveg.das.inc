var private P_TempSaveGameFile__filename : int = 0

var private P_SaveGameFile__filename : int = 0

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
def P_TempSaveGameFile() : int {
    if (P_TempSaveGameFile__filename == 0) {
        P_TempSaveGameFile__filename = M_StringJoin(savegamedir, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 360672ul), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 0ul)])
    }
    return P_TempSaveGameFile__filename
}
[export, sideeffects]
def P_SaveGameFile(var slot : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = P_SaveGameFile_c2da_frame(slot, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def P_ReadSaveGameHeader() : uint {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : uint = P_ReadSaveGameHeader_c2da_frame(c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[sideeffects]
def private saveg_read8() : uint8 {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : uint8 = saveg_read8_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
var savegame_error : uint = default<uint>

var save_stream : int = default<int>

[export, sideeffects]
def P_WriteSaveGameHeader(var description : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    P_WriteSaveGameHeader_c2da_frame(description, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private saveg_write8(var value : uint8) {
    let c2da_saved_sp : int = c2da_lin_sp
    saveg_write8_c2da_frame(value, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
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
        saveg_write_player_t(96 + i_1 * 328)
    }
    return
}
[sideeffects]
def private saveg_write_player_t(var str : int) {
    var i_2 : int
    saveg_writep(int(uint(c2da_mem[str]) | uint(c2da_mem[str + 1]) << 0x8 | uint(c2da_mem[str + 2]) << 0x10 | uint(c2da_mem[str + 3]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 8]) | uint(c2da_mem[str + 9]) << 0x8 | uint(c2da_mem[str + 10]) << 0x10 | uint(c2da_mem[str + 11]) << 0x18))
    saveg_write_ticcmd_t(str + 12)
    saveg_write32(int(uint(c2da_mem[str + 28]) | uint(c2da_mem[str + 29]) << 0x8 | uint(c2da_mem[str + 30]) << 0x10 | uint(c2da_mem[str + 31]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 32]) | uint(c2da_mem[str + 33]) << 0x8 | uint(c2da_mem[str + 34]) << 0x10 | uint(c2da_mem[str + 35]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 36]) | uint(c2da_mem[str + 37]) << 0x8 | uint(c2da_mem[str + 38]) << 0x10 | uint(c2da_mem[str + 39]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 40]) | uint(c2da_mem[str + 41]) << 0x8 | uint(c2da_mem[str + 42]) << 0x10 | uint(c2da_mem[str + 43]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 44]) | uint(c2da_mem[str + 45]) << 0x8 | uint(c2da_mem[str + 46]) << 0x10 | uint(c2da_mem[str + 47]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 48]) | uint(c2da_mem[str + 49]) << 0x8 | uint(c2da_mem[str + 50]) << 0x10 | uint(c2da_mem[str + 51]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 52]) | uint(c2da_mem[str + 53]) << 0x8 | uint(c2da_mem[str + 54]) << 0x10 | uint(c2da_mem[str + 55]) << 0x18))
    i_2 = 0
    while (i_2 < 6) {
        saveg_write32(int(uint(c2da_mem[str + 56 + i_2 * 4]) | uint(c2da_mem[str + 56 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[str + 56 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[str + 56 + i_2 * 4 + 3]) << 0x18))
        i_2++
    }
    i_2 = 0
    while (i_2 < 6) {
        saveg_write32(int(uint(c2da_mem[str + 80 + i_2 * 4]) | uint(c2da_mem[str + 80 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[str + 80 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[str + 80 + i_2 * 4 + 3]) << 0x18))
        i_2++
    }
    saveg_write32(int(uint(c2da_mem[str + 104]) | uint(c2da_mem[str + 105]) << 0x8 | uint(c2da_mem[str + 106]) << 0x10 | uint(c2da_mem[str + 107]) << 0x18))
    i_2 = 0
    while (i_2 < 4) {
        saveg_write32(int(uint(c2da_mem[str + 108 + i_2 * 4]) | uint(c2da_mem[str + 108 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[str + 108 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[str + 108 + i_2 * 4 + 3]) << 0x18))
        i_2++
    }
    saveg_write32(int(uint(c2da_mem[str + 124]) | uint(c2da_mem[str + 125]) << 0x8 | uint(c2da_mem[str + 126]) << 0x10 | uint(c2da_mem[str + 127]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 128]) | uint(c2da_mem[str + 129]) << 0x8 | uint(c2da_mem[str + 130]) << 0x10 | uint(c2da_mem[str + 131]) << 0x18))
    i_2 = 0
    while (i_2 < 9) {
        saveg_write32(int(uint(c2da_mem[str + 132 + i_2 * 4]) | uint(c2da_mem[str + 132 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[str + 132 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[str + 132 + i_2 * 4 + 3]) << 0x18))
        i_2++
    }
    i_2 = 0
    while (i_2 < 4) {
        saveg_write32(int(uint(c2da_mem[str + 168 + i_2 * 4]) | uint(c2da_mem[str + 168 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[str + 168 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[str + 168 + i_2 * 4 + 3]) << 0x18))
        i_2++
    }
    i_2 = 0
    while (i_2 < 4) {
        saveg_write32(int(uint(c2da_mem[str + 184 + i_2 * 4]) | uint(c2da_mem[str + 184 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[str + 184 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[str + 184 + i_2 * 4 + 3]) << 0x18))
        i_2++
    }
    saveg_write32(int(uint(c2da_mem[str + 200]) | uint(c2da_mem[str + 201]) << 0x8 | uint(c2da_mem[str + 202]) << 0x10 | uint(c2da_mem[str + 203]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 204]) | uint(c2da_mem[str + 205]) << 0x8 | uint(c2da_mem[str + 206]) << 0x10 | uint(c2da_mem[str + 207]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 208]) | uint(c2da_mem[str + 209]) << 0x8 | uint(c2da_mem[str + 210]) << 0x10 | uint(c2da_mem[str + 211]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 212]) | uint(c2da_mem[str + 213]) << 0x8 | uint(c2da_mem[str + 214]) << 0x10 | uint(c2da_mem[str + 215]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 216]) | uint(c2da_mem[str + 217]) << 0x8 | uint(c2da_mem[str + 218]) << 0x10 | uint(c2da_mem[str + 219]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 220]) | uint(c2da_mem[str + 221]) << 0x8 | uint(c2da_mem[str + 222]) << 0x10 | uint(c2da_mem[str + 223]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 224]) | uint(c2da_mem[str + 225]) << 0x8 | uint(c2da_mem[str + 226]) << 0x10 | uint(c2da_mem[str + 227]) << 0x18))
    saveg_writep(int(uint(c2da_mem[str + 232]) | uint(c2da_mem[str + 233]) << 0x8 | uint(c2da_mem[str + 234]) << 0x10 | uint(c2da_mem[str + 235]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 240]) | uint(c2da_mem[str + 241]) << 0x8 | uint(c2da_mem[str + 242]) << 0x10 | uint(c2da_mem[str + 243]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 244]) | uint(c2da_mem[str + 245]) << 0x8 | uint(c2da_mem[str + 246]) << 0x10 | uint(c2da_mem[str + 247]) << 0x18))
    saveg_writep(int(uint(c2da_mem[str + 248]) | uint(c2da_mem[str + 249]) << 0x8 | uint(c2da_mem[str + 250]) << 0x10 | uint(c2da_mem[str + 251]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 256]) | uint(c2da_mem[str + 257]) << 0x8 | uint(c2da_mem[str + 258]) << 0x10 | uint(c2da_mem[str + 259]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 260]) | uint(c2da_mem[str + 261]) << 0x8 | uint(c2da_mem[str + 262]) << 0x10 | uint(c2da_mem[str + 263]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str + 264]) | uint(c2da_mem[str + 265]) << 0x8 | uint(c2da_mem[str + 266]) << 0x10 | uint(c2da_mem[str + 267]) << 0x18))
    i_2 = 0
    for (c2da_i_2 in range(i_2, 2)) {
        saveg_write_pspdef_t(str + 272 + c2da_i_2 * 24)
    }
    saveg_write32(int(uint(c2da_mem[str + 320]) | uint(c2da_mem[str + 321]) << 0x8 | uint(c2da_mem[str + 322]) << 0x10 | uint(c2da_mem[str + 323]) << 0x18))
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
def private saveg_write_pspdef_t(var str_0 : int) {
    if (int(uint(c2da_mem[str_0]) | uint(c2da_mem[str_0 + 1]) << 0x8 | uint(c2da_mem[str_0 + 2]) << 0x10 | uint(c2da_mem[str_0 + 3]) << 0x18) != 0) {
        saveg_write32((int(uint(c2da_mem[str_0]) | uint(c2da_mem[str_0 + 1]) << 0x8 | uint(c2da_mem[str_0 + 2]) << 0x10 | uint(c2da_mem[str_0 + 3]) << 0x18) - 2080) / 40)
    } else {
        saveg_write32(0)
    }
    saveg_write32(int(uint(c2da_mem[str_0 + 8]) | uint(c2da_mem[str_0 + 9]) << 0x8 | uint(c2da_mem[str_0 + 10]) << 0x10 | uint(c2da_mem[str_0 + 11]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_0 + 12]) | uint(c2da_mem[str_0 + 13]) << 0x8 | uint(c2da_mem[str_0 + 14]) << 0x10 | uint(c2da_mem[str_0 + 15]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_0 + 16]) | uint(c2da_mem[str_0 + 17]) << 0x8 | uint(c2da_mem[str_0 + 18]) << 0x10 | uint(c2da_mem[str_0 + 19]) << 0x18))
    return
}
[sideeffects]
def private saveg_writep(var p : int) {
    saveg_write32(p)
    return
}
[sideeffects]
def private saveg_write_ticcmd_t(var str_1 : int) {
    saveg_write8(uint8(int8(c2da_mem[str_1])))
    saveg_write8(uint8(int8(c2da_mem[str_1 + 1])))
    saveg_write16(int16(uint(c2da_mem[str_1 + 2]) | uint(c2da_mem[str_1 + 3]) << 0x8))
    saveg_write16(int16(c2da_mem[str_1 + 6]))
    saveg_write8(c2da_mem[str_1 + 4])
    saveg_write8(c2da_mem[str_1 + 5])
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
    pos = uint64(c2da_std_ftell(uint64(save_stream)))
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
        saveg_read_player_t(96 + i_4 * 328)
        let c2da_fresh1 : uint = 0u
        c2da_mem[96 + i_4 * 328] = uint8(c2da_fresh1)
        c2da_mem[96 + i_4 * 328 + 1] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[96 + i_4 * 328 + 2] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[96 + i_4 * 328 + 3] = uint8(c2da_fresh1 >> 0x18)
        c2da_mem[96 + i_4 * 328 + 4] = 0u8
        c2da_mem[96 + i_4 * 328 + 5] = 0u8
        c2da_mem[96 + i_4 * 328 + 6] = 0u8
        c2da_mem[96 + i_4 * 328 + 7] = 0u8
        let c2da_fresh2 : uint = 0u
        c2da_mem[96 + i_4 * 328 + 232] = uint8(c2da_fresh2)
        c2da_mem[96 + i_4 * 328 + 233] = uint8(c2da_fresh2 >> 0x8)
        c2da_mem[96 + i_4 * 328 + 234] = uint8(c2da_fresh2 >> 0x10)
        c2da_mem[96 + i_4 * 328 + 235] = uint8(c2da_fresh2 >> 0x18)
        c2da_mem[96 + i_4 * 328 + 236] = 0u8
        c2da_mem[96 + i_4 * 328 + 237] = 0u8
        c2da_mem[96 + i_4 * 328 + 238] = 0u8
        c2da_mem[96 + i_4 * 328 + 239] = 0u8
        let c2da_fresh3 : uint = 0u
        c2da_mem[96 + i_4 * 328 + 248] = uint8(c2da_fresh3)
        c2da_mem[96 + i_4 * 328 + 249] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[96 + i_4 * 328 + 250] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[96 + i_4 * 328 + 251] = uint8(c2da_fresh3 >> 0x18)
        c2da_mem[96 + i_4 * 328 + 252] = 0u8
        c2da_mem[96 + i_4 * 328 + 253] = 0u8
        c2da_mem[96 + i_4 * 328 + 254] = 0u8
        c2da_mem[96 + i_4 * 328 + 255] = 0u8
    }
    return
}
[sideeffects]
def private saveg_read_player_t(var str_2 : int) {
    var i_5 : int
    let c2da_fresh4 : int = saveg_readp()
    let c2da_fresh5 : uint = uint(c2da_fresh4)
    c2da_mem[str_2] = uint8(c2da_fresh5)
    c2da_mem[str_2 + 1] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[str_2 + 2] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[str_2 + 3] = uint8(c2da_fresh5 >> 0x18)
    c2da_mem[str_2 + 4] = 0u8
    c2da_mem[str_2 + 5] = 0u8
    c2da_mem[str_2 + 6] = 0u8
    c2da_mem[str_2 + 7] = 0u8
    let c2da_fresh6 : uint = uint(saveg_read32())
    let c2da_fresh7 : uint = c2da_fresh6
    c2da_mem[str_2 + 8] = uint8(c2da_fresh7)
    c2da_mem[str_2 + 9] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[str_2 + 10] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[str_2 + 11] = uint8(c2da_fresh7 >> 0x18)
    saveg_read_ticcmd_t(str_2 + 12)
    let c2da_fresh8 : int = saveg_read32()
    let c2da_fresh9 : uint = uint(c2da_fresh8)
    c2da_mem[str_2 + 28] = uint8(c2da_fresh9)
    c2da_mem[str_2 + 29] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[str_2 + 30] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[str_2 + 31] = uint8(c2da_fresh9 >> 0x18)
    let c2da_fresh10 : int = saveg_read32()
    let c2da_fresh11 : uint = uint(c2da_fresh10)
    c2da_mem[str_2 + 32] = uint8(c2da_fresh11)
    c2da_mem[str_2 + 33] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[str_2 + 34] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[str_2 + 35] = uint8(c2da_fresh11 >> 0x18)
    let c2da_fresh12 : int = saveg_read32()
    let c2da_fresh13 : uint = uint(c2da_fresh12)
    c2da_mem[str_2 + 36] = uint8(c2da_fresh13)
    c2da_mem[str_2 + 37] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[str_2 + 38] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[str_2 + 39] = uint8(c2da_fresh13 >> 0x18)
    let c2da_fresh14 : int = saveg_read32()
    let c2da_fresh15 : uint = uint(c2da_fresh14)
    c2da_mem[str_2 + 40] = uint8(c2da_fresh15)
    c2da_mem[str_2 + 41] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[str_2 + 42] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[str_2 + 43] = uint8(c2da_fresh15 >> 0x18)
    let c2da_fresh16 : int = saveg_read32()
    let c2da_fresh17 : uint = uint(c2da_fresh16)
    c2da_mem[str_2 + 44] = uint8(c2da_fresh17)
    c2da_mem[str_2 + 45] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[str_2 + 46] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[str_2 + 47] = uint8(c2da_fresh17 >> 0x18)
    let c2da_fresh18 : int = saveg_read32()
    let c2da_fresh19 : uint = uint(c2da_fresh18)
    c2da_mem[str_2 + 48] = uint8(c2da_fresh19)
    c2da_mem[str_2 + 49] = uint8(c2da_fresh19 >> 0x8)
    c2da_mem[str_2 + 50] = uint8(c2da_fresh19 >> 0x10)
    c2da_mem[str_2 + 51] = uint8(c2da_fresh19 >> 0x18)
    let c2da_fresh20 : int = saveg_read32()
    let c2da_fresh21 : uint = uint(c2da_fresh20)
    c2da_mem[str_2 + 52] = uint8(c2da_fresh21)
    c2da_mem[str_2 + 53] = uint8(c2da_fresh21 >> 0x8)
    c2da_mem[str_2 + 54] = uint8(c2da_fresh21 >> 0x10)
    c2da_mem[str_2 + 55] = uint8(c2da_fresh21 >> 0x18)
    i_5 = 0
    while (i_5 < 6) {
        let c2da_fresh22 : int = saveg_read32()
        let c2da_fresh23 : uint = uint(c2da_fresh22)
        c2da_mem[str_2 + 56 + i_5 * 4] = uint8(c2da_fresh23)
        c2da_mem[str_2 + 56 + i_5 * 4 + 1] = uint8(c2da_fresh23 >> 0x8)
        c2da_mem[str_2 + 56 + i_5 * 4 + 2] = uint8(c2da_fresh23 >> 0x10)
        c2da_mem[str_2 + 56 + i_5 * 4 + 3] = uint8(c2da_fresh23 >> 0x18)
        i_5++
    }
    i_5 = 0
    while (i_5 < 6) {
        let c2da_fresh24 : uint = uint(saveg_read32())
        let c2da_fresh25 : uint = c2da_fresh24
        c2da_mem[str_2 + 80 + i_5 * 4] = uint8(c2da_fresh25)
        c2da_mem[str_2 + 80 + i_5 * 4 + 1] = uint8(c2da_fresh25 >> 0x8)
        c2da_mem[str_2 + 80 + i_5 * 4 + 2] = uint8(c2da_fresh25 >> 0x10)
        c2da_mem[str_2 + 80 + i_5 * 4 + 3] = uint8(c2da_fresh25 >> 0x18)
        i_5++
    }
    let c2da_fresh26 : uint = uint(saveg_read32())
    let c2da_fresh27 : uint = c2da_fresh26
    c2da_mem[str_2 + 104] = uint8(c2da_fresh27)
    c2da_mem[str_2 + 105] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[str_2 + 106] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[str_2 + 107] = uint8(c2da_fresh27 >> 0x18)
    i_5 = 0
    while (i_5 < 4) {
        let c2da_fresh28 : int = saveg_read32()
        let c2da_fresh29 : uint = uint(c2da_fresh28)
        c2da_mem[str_2 + 108 + i_5 * 4] = uint8(c2da_fresh29)
        c2da_mem[str_2 + 108 + i_5 * 4 + 1] = uint8(c2da_fresh29 >> 0x8)
        c2da_mem[str_2 + 108 + i_5 * 4 + 2] = uint8(c2da_fresh29 >> 0x10)
        c2da_mem[str_2 + 108 + i_5 * 4 + 3] = uint8(c2da_fresh29 >> 0x18)
        i_5++
    }
    let c2da_fresh30 : uint = uint(saveg_read32())
    let c2da_fresh31 : uint = c2da_fresh30
    c2da_mem[str_2 + 124] = uint8(c2da_fresh31)
    c2da_mem[str_2 + 125] = uint8(c2da_fresh31 >> 0x8)
    c2da_mem[str_2 + 126] = uint8(c2da_fresh31 >> 0x10)
    c2da_mem[str_2 + 127] = uint8(c2da_fresh31 >> 0x18)
    let c2da_fresh32 : uint = uint(saveg_read32())
    let c2da_fresh33 : uint = c2da_fresh32
    c2da_mem[str_2 + 128] = uint8(c2da_fresh33)
    c2da_mem[str_2 + 129] = uint8(c2da_fresh33 >> 0x8)
    c2da_mem[str_2 + 130] = uint8(c2da_fresh33 >> 0x10)
    c2da_mem[str_2 + 131] = uint8(c2da_fresh33 >> 0x18)
    i_5 = 0
    while (i_5 < 9) {
        let c2da_fresh34 : uint = uint(saveg_read32())
        let c2da_fresh35 : uint = c2da_fresh34
        c2da_mem[str_2 + 132 + i_5 * 4] = uint8(c2da_fresh35)
        c2da_mem[str_2 + 132 + i_5 * 4 + 1] = uint8(c2da_fresh35 >> 0x8)
        c2da_mem[str_2 + 132 + i_5 * 4 + 2] = uint8(c2da_fresh35 >> 0x10)
        c2da_mem[str_2 + 132 + i_5 * 4 + 3] = uint8(c2da_fresh35 >> 0x18)
        i_5++
    }
    i_5 = 0
    while (i_5 < 4) {
        let c2da_fresh36 : int = saveg_read32()
        let c2da_fresh37 : uint = uint(c2da_fresh36)
        c2da_mem[str_2 + 168 + i_5 * 4] = uint8(c2da_fresh37)
        c2da_mem[str_2 + 168 + i_5 * 4 + 1] = uint8(c2da_fresh37 >> 0x8)
        c2da_mem[str_2 + 168 + i_5 * 4 + 2] = uint8(c2da_fresh37 >> 0x10)
        c2da_mem[str_2 + 168 + i_5 * 4 + 3] = uint8(c2da_fresh37 >> 0x18)
        i_5++
    }
    i_5 = 0
    while (i_5 < 4) {
        let c2da_fresh38 : int = saveg_read32()
        let c2da_fresh39 : uint = uint(c2da_fresh38)
        c2da_mem[str_2 + 184 + i_5 * 4] = uint8(c2da_fresh39)
        c2da_mem[str_2 + 184 + i_5 * 4 + 1] = uint8(c2da_fresh39 >> 0x8)
        c2da_mem[str_2 + 184 + i_5 * 4 + 2] = uint8(c2da_fresh39 >> 0x10)
        c2da_mem[str_2 + 184 + i_5 * 4 + 3] = uint8(c2da_fresh39 >> 0x18)
        i_5++
    }
    let c2da_fresh40 : int = saveg_read32()
    let c2da_fresh41 : uint = uint(c2da_fresh40)
    c2da_mem[str_2 + 200] = uint8(c2da_fresh41)
    c2da_mem[str_2 + 201] = uint8(c2da_fresh41 >> 0x8)
    c2da_mem[str_2 + 202] = uint8(c2da_fresh41 >> 0x10)
    c2da_mem[str_2 + 203] = uint8(c2da_fresh41 >> 0x18)
    let c2da_fresh42 : int = saveg_read32()
    let c2da_fresh43 : uint = uint(c2da_fresh42)
    c2da_mem[str_2 + 204] = uint8(c2da_fresh43)
    c2da_mem[str_2 + 205] = uint8(c2da_fresh43 >> 0x8)
    c2da_mem[str_2 + 206] = uint8(c2da_fresh43 >> 0x10)
    c2da_mem[str_2 + 207] = uint8(c2da_fresh43 >> 0x18)
    let c2da_fresh44 : int = saveg_read32()
    let c2da_fresh45 : uint = uint(c2da_fresh44)
    c2da_mem[str_2 + 208] = uint8(c2da_fresh45)
    c2da_mem[str_2 + 209] = uint8(c2da_fresh45 >> 0x8)
    c2da_mem[str_2 + 210] = uint8(c2da_fresh45 >> 0x10)
    c2da_mem[str_2 + 211] = uint8(c2da_fresh45 >> 0x18)
    let c2da_fresh46 : int = saveg_read32()
    let c2da_fresh47 : uint = uint(c2da_fresh46)
    c2da_mem[str_2 + 212] = uint8(c2da_fresh47)
    c2da_mem[str_2 + 213] = uint8(c2da_fresh47 >> 0x8)
    c2da_mem[str_2 + 214] = uint8(c2da_fresh47 >> 0x10)
    c2da_mem[str_2 + 215] = uint8(c2da_fresh47 >> 0x18)
    let c2da_fresh48 : int = saveg_read32()
    let c2da_fresh49 : uint = uint(c2da_fresh48)
    c2da_mem[str_2 + 216] = uint8(c2da_fresh49)
    c2da_mem[str_2 + 217] = uint8(c2da_fresh49 >> 0x8)
    c2da_mem[str_2 + 218] = uint8(c2da_fresh49 >> 0x10)
    c2da_mem[str_2 + 219] = uint8(c2da_fresh49 >> 0x18)
    let c2da_fresh50 : int = saveg_read32()
    let c2da_fresh51 : uint = uint(c2da_fresh50)
    c2da_mem[str_2 + 220] = uint8(c2da_fresh51)
    c2da_mem[str_2 + 221] = uint8(c2da_fresh51 >> 0x8)
    c2da_mem[str_2 + 222] = uint8(c2da_fresh51 >> 0x10)
    c2da_mem[str_2 + 223] = uint8(c2da_fresh51 >> 0x18)
    let c2da_fresh52 : int = saveg_read32()
    let c2da_fresh53 : uint = uint(c2da_fresh52)
    c2da_mem[str_2 + 224] = uint8(c2da_fresh53)
    c2da_mem[str_2 + 225] = uint8(c2da_fresh53 >> 0x8)
    c2da_mem[str_2 + 226] = uint8(c2da_fresh53 >> 0x10)
    c2da_mem[str_2 + 227] = uint8(c2da_fresh53 >> 0x18)
    let c2da_fresh54 : int = saveg_readp()
    let c2da_fresh55 : uint = uint(c2da_fresh54)
    c2da_mem[str_2 + 232] = uint8(c2da_fresh55)
    c2da_mem[str_2 + 233] = uint8(c2da_fresh55 >> 0x8)
    c2da_mem[str_2 + 234] = uint8(c2da_fresh55 >> 0x10)
    c2da_mem[str_2 + 235] = uint8(c2da_fresh55 >> 0x18)
    c2da_mem[str_2 + 236] = 0u8
    c2da_mem[str_2 + 237] = 0u8
    c2da_mem[str_2 + 238] = 0u8
    c2da_mem[str_2 + 239] = 0u8
    let c2da_fresh56 : int = saveg_read32()
    let c2da_fresh57 : uint = uint(c2da_fresh56)
    c2da_mem[str_2 + 240] = uint8(c2da_fresh57)
    c2da_mem[str_2 + 241] = uint8(c2da_fresh57 >> 0x8)
    c2da_mem[str_2 + 242] = uint8(c2da_fresh57 >> 0x10)
    c2da_mem[str_2 + 243] = uint8(c2da_fresh57 >> 0x18)
    let c2da_fresh58 : int = saveg_read32()
    let c2da_fresh59 : uint = uint(c2da_fresh58)
    c2da_mem[str_2 + 244] = uint8(c2da_fresh59)
    c2da_mem[str_2 + 245] = uint8(c2da_fresh59 >> 0x8)
    c2da_mem[str_2 + 246] = uint8(c2da_fresh59 >> 0x10)
    c2da_mem[str_2 + 247] = uint8(c2da_fresh59 >> 0x18)
    let c2da_fresh60 : int = saveg_readp()
    let c2da_fresh61 : uint = uint(c2da_fresh60)
    c2da_mem[str_2 + 248] = uint8(c2da_fresh61)
    c2da_mem[str_2 + 249] = uint8(c2da_fresh61 >> 0x8)
    c2da_mem[str_2 + 250] = uint8(c2da_fresh61 >> 0x10)
    c2da_mem[str_2 + 251] = uint8(c2da_fresh61 >> 0x18)
    c2da_mem[str_2 + 252] = 0u8
    c2da_mem[str_2 + 253] = 0u8
    c2da_mem[str_2 + 254] = 0u8
    c2da_mem[str_2 + 255] = 0u8
    let c2da_fresh62 : int = saveg_read32()
    let c2da_fresh63 : uint = uint(c2da_fresh62)
    c2da_mem[str_2 + 256] = uint8(c2da_fresh63)
    c2da_mem[str_2 + 257] = uint8(c2da_fresh63 >> 0x8)
    c2da_mem[str_2 + 258] = uint8(c2da_fresh63 >> 0x10)
    c2da_mem[str_2 + 259] = uint8(c2da_fresh63 >> 0x18)
    let c2da_fresh64 : int = saveg_read32()
    let c2da_fresh65 : uint = uint(c2da_fresh64)
    c2da_mem[str_2 + 260] = uint8(c2da_fresh65)
    c2da_mem[str_2 + 261] = uint8(c2da_fresh65 >> 0x8)
    c2da_mem[str_2 + 262] = uint8(c2da_fresh65 >> 0x10)
    c2da_mem[str_2 + 263] = uint8(c2da_fresh65 >> 0x18)
    let c2da_fresh66 : int = saveg_read32()
    let c2da_fresh67 : uint = uint(c2da_fresh66)
    c2da_mem[str_2 + 264] = uint8(c2da_fresh67)
    c2da_mem[str_2 + 265] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[str_2 + 266] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[str_2 + 267] = uint8(c2da_fresh67 >> 0x18)
    i_5 = 0
    for (c2da_i_5 in range(i_5, 2)) {
        saveg_read_pspdef_t(str_2 + 272 + c2da_i_5 * 24)
    }
    let c2da_fresh68 : uint = uint(saveg_read32())
    let c2da_fresh69 : uint = c2da_fresh68
    c2da_mem[str_2 + 320] = uint8(c2da_fresh69)
    c2da_mem[str_2 + 321] = uint8(c2da_fresh69 >> 0x8)
    c2da_mem[str_2 + 322] = uint8(c2da_fresh69 >> 0x10)
    c2da_mem[str_2 + 323] = uint8(c2da_fresh69 >> 0x18)
    return
}
[sideeffects]
def private saveg_read32() : int {
    var result_0 : int = int(saveg_read8())
    result_0 = result_0 | int(saveg_read8()) << 8
    result_0 = result_0 | int(saveg_read8()) << 16
    result_0 = result_0 | int(saveg_read8()) << 24
    return result_0
}
[sideeffects]
def private saveg_read_pspdef_t(var str_3 : int) {
    var state : int = saveg_read32()
    if (state > 0) {
        let c2da_fresh70 : int = 2080 + state * 40
        let c2da_fresh71 : uint = uint(c2da_fresh70)
        c2da_mem[str_3] = uint8(c2da_fresh71)
        c2da_mem[str_3 + 1] = uint8(c2da_fresh71 >> 0x8)
        c2da_mem[str_3 + 2] = uint8(c2da_fresh71 >> 0x10)
        c2da_mem[str_3 + 3] = uint8(c2da_fresh71 >> 0x18)
        c2da_mem[str_3 + 4] = 0u8
        c2da_mem[str_3 + 5] = 0u8
        c2da_mem[str_3 + 6] = 0u8
        c2da_mem[str_3 + 7] = 0u8
    } else {
        let c2da_fresh72 : uint = 0u
        c2da_mem[str_3] = uint8(c2da_fresh72)
        c2da_mem[str_3 + 1] = uint8(c2da_fresh72 >> 0x8)
        c2da_mem[str_3 + 2] = uint8(c2da_fresh72 >> 0x10)
        c2da_mem[str_3 + 3] = uint8(c2da_fresh72 >> 0x18)
        c2da_mem[str_3 + 4] = 0u8
        c2da_mem[str_3 + 5] = 0u8
        c2da_mem[str_3 + 6] = 0u8
        c2da_mem[str_3 + 7] = 0u8
    }
    let c2da_fresh73 : int = saveg_read32()
    let c2da_fresh74 : uint = uint(c2da_fresh73)
    c2da_mem[str_3 + 8] = uint8(c2da_fresh74)
    c2da_mem[str_3 + 9] = uint8(c2da_fresh74 >> 0x8)
    c2da_mem[str_3 + 10] = uint8(c2da_fresh74 >> 0x10)
    c2da_mem[str_3 + 11] = uint8(c2da_fresh74 >> 0x18)
    let c2da_fresh75 : int = saveg_read32()
    let c2da_fresh76 : uint = uint(c2da_fresh75)
    c2da_mem[str_3 + 12] = uint8(c2da_fresh76)
    c2da_mem[str_3 + 13] = uint8(c2da_fresh76 >> 0x8)
    c2da_mem[str_3 + 14] = uint8(c2da_fresh76 >> 0x10)
    c2da_mem[str_3 + 15] = uint8(c2da_fresh76 >> 0x18)
    let c2da_fresh77 : int = saveg_read32()
    let c2da_fresh78 : uint = uint(c2da_fresh77)
    c2da_mem[str_3 + 16] = uint8(c2da_fresh78)
    c2da_mem[str_3 + 17] = uint8(c2da_fresh78 >> 0x8)
    c2da_mem[str_3 + 18] = uint8(c2da_fresh78 >> 0x10)
    c2da_mem[str_3 + 19] = uint8(c2da_fresh78 >> 0x18)
    return
}
[sideeffects]
def private saveg_readp() : int {
    return saveg_read32()
}
[sideeffects]
def private saveg_read_ticcmd_t(var str_4 : int) {
    let c2da_fresh79 : int8 = int8(saveg_read8())
    c2da_mem[str_4] = uint8(c2da_fresh79)
    let c2da_fresh80 : int8 = int8(saveg_read8())
    c2da_mem[str_4 + 1] = uint8(c2da_fresh80)
    let c2da_fresh81 : int16 = saveg_read16()
    let c2da_fresh82 : uint = uint(c2da_fresh81)
    c2da_mem[str_4 + 2] = uint8(c2da_fresh82)
    c2da_mem[str_4 + 3] = uint8(c2da_fresh82 >> 0x8)
    let c2da_fresh83 : uint8 = uint8(saveg_read16())
    c2da_mem[str_4 + 6] = c2da_fresh83
    let c2da_fresh84 : uint8 = saveg_read8()
    c2da_mem[str_4 + 4] = c2da_fresh84
    let c2da_fresh85 : uint8 = saveg_read8()
    c2da_mem[str_4 + 5] = c2da_fresh85
    return
}
[sideeffects]
def private saveg_read16() : int16 {
    var result_1 : int = int(saveg_read8())
    result_1 = result_1 | int(saveg_read8()) << 8
    return int16(result_1)
}
[sideeffects]
def private saveg_read_pad() {
    var pos_0 : uint64
    var padding_0 : int
    pos_0 = uint64(c2da_std_ftell(uint64(save_stream)))
    padding_0 = int(4ul - (pos_0 & 3ul) & 3ul)
    for (i_6 in range(0, padding_0)) {
        saveg_read8()
    }
    return
}
[export, sideeffects]
def P_ArchiveWorld() {
    var i_7 : int
    var sec : int
    var li : int
    var si : int
    i_7 = 0
    sec = sectors
    while (i_7 < numsectors) {
        saveg_write16(int16(int(uint(c2da_mem[sec]) | uint(c2da_mem[sec + 1]) << 0x8 | uint(c2da_mem[sec + 2]) << 0x10 | uint(c2da_mem[sec + 3]) << 0x18) >> 16))
        saveg_write16(int16(int(uint(c2da_mem[sec + 4]) | uint(c2da_mem[sec + 5]) << 0x8 | uint(c2da_mem[sec + 6]) << 0x10 | uint(c2da_mem[sec + 7]) << 0x18) >> 16))
        saveg_write16(int16(uint(c2da_mem[sec + 8]) | uint(c2da_mem[sec + 9]) << 0x8))
        saveg_write16(int16(uint(c2da_mem[sec + 10]) | uint(c2da_mem[sec + 11]) << 0x8))
        saveg_write16(int16(uint(c2da_mem[sec + 12]) | uint(c2da_mem[sec + 13]) << 0x8))
        saveg_write16(int16(uint(c2da_mem[sec + 14]) | uint(c2da_mem[sec + 15]) << 0x8))
        saveg_write16(int16(uint(c2da_mem[sec + 16]) | uint(c2da_mem[sec + 17]) << 0x8))
        i_7++
        sec += 128
    }
    i_7 = 0
    li = lines
    while (i_7 < numlines) {
        saveg_write16(int16(uint(c2da_mem[li + 24]) | uint(c2da_mem[li + 25]) << 0x8))
        saveg_write16(int16(uint(c2da_mem[li + 26]) | uint(c2da_mem[li + 27]) << 0x8))
        saveg_write16(int16(uint(c2da_mem[li + 28]) | uint(c2da_mem[li + 29]) << 0x8))
        for (j in range(0, 2)) {
            if (int(int16(uint(c2da_mem[li + 30 + j * 2]) | uint(c2da_mem[li + 30 + j * 2 + 1]) << 0x8)) == -1) {
                continue
            }
            si = sides + int(int16(uint(c2da_mem[li + 30 + j * 2]) | uint(c2da_mem[li + 30 + j * 2 + 1]) << 0x8)) * 24
            saveg_write16(int16(int(uint(c2da_mem[si]) | uint(c2da_mem[si + 1]) << 0x8 | uint(c2da_mem[si + 2]) << 0x10 | uint(c2da_mem[si + 3]) << 0x18) >> 16))
            saveg_write16(int16(int(uint(c2da_mem[si + 4]) | uint(c2da_mem[si + 5]) << 0x8 | uint(c2da_mem[si + 6]) << 0x10 | uint(c2da_mem[si + 7]) << 0x18) >> 16))
            saveg_write16(int16(uint(c2da_mem[si + 8]) | uint(c2da_mem[si + 9]) << 0x8))
            saveg_write16(int16(uint(c2da_mem[si + 10]) | uint(c2da_mem[si + 11]) << 0x8))
            saveg_write16(int16(uint(c2da_mem[si + 12]) | uint(c2da_mem[si + 13]) << 0x8))
        }
        i_7++
        li += 88
    }
    return
}
[export, sideeffects]
def P_UnArchiveWorld() {
    var i_8 : int
    var sec_0 : int
    var li_0 : int
    var si_0 : int
    i_8 = 0
    sec_0 = sectors
    while (i_8 < numsectors) {
        let c2da_fresh86 : int = int(saveg_read16()) << 16
        let c2da_fresh87 : uint = uint(c2da_fresh86)
        c2da_mem[sec_0] = uint8(c2da_fresh87)
        c2da_mem[sec_0 + 1] = uint8(c2da_fresh87 >> 0x8)
        c2da_mem[sec_0 + 2] = uint8(c2da_fresh87 >> 0x10)
        c2da_mem[sec_0 + 3] = uint8(c2da_fresh87 >> 0x18)
        let c2da_fresh88 : int = int(saveg_read16()) << 16
        let c2da_fresh89 : uint = uint(c2da_fresh88)
        c2da_mem[sec_0 + 4] = uint8(c2da_fresh89)
        c2da_mem[sec_0 + 5] = uint8(c2da_fresh89 >> 0x8)
        c2da_mem[sec_0 + 6] = uint8(c2da_fresh89 >> 0x10)
        c2da_mem[sec_0 + 7] = uint8(c2da_fresh89 >> 0x18)
        let c2da_fresh90 : int16 = saveg_read16()
        let c2da_fresh91 : uint = uint(c2da_fresh90)
        c2da_mem[sec_0 + 8] = uint8(c2da_fresh91)
        c2da_mem[sec_0 + 9] = uint8(c2da_fresh91 >> 0x8)
        let c2da_fresh92 : int16 = saveg_read16()
        let c2da_fresh93 : uint = uint(c2da_fresh92)
        c2da_mem[sec_0 + 10] = uint8(c2da_fresh93)
        c2da_mem[sec_0 + 11] = uint8(c2da_fresh93 >> 0x8)
        let c2da_fresh94 : int16 = saveg_read16()
        let c2da_fresh95 : uint = uint(c2da_fresh94)
        c2da_mem[sec_0 + 12] = uint8(c2da_fresh95)
        c2da_mem[sec_0 + 13] = uint8(c2da_fresh95 >> 0x8)
        let c2da_fresh96 : int16 = saveg_read16()
        let c2da_fresh97 : uint = uint(c2da_fresh96)
        c2da_mem[sec_0 + 14] = uint8(c2da_fresh97)
        c2da_mem[sec_0 + 15] = uint8(c2da_fresh97 >> 0x8)
        let c2da_fresh98 : int16 = saveg_read16()
        let c2da_fresh99 : uint = uint(c2da_fresh98)
        c2da_mem[sec_0 + 16] = uint8(c2da_fresh99)
        c2da_mem[sec_0 + 17] = uint8(c2da_fresh99 >> 0x8)
        let c2da_fresh100 : uint = 0u
        c2da_mem[sec_0 + 104] = uint8(c2da_fresh100)
        c2da_mem[sec_0 + 105] = uint8(c2da_fresh100 >> 0x8)
        c2da_mem[sec_0 + 106] = uint8(c2da_fresh100 >> 0x10)
        c2da_mem[sec_0 + 107] = uint8(c2da_fresh100 >> 0x18)
        c2da_mem[sec_0 + 108] = 0u8
        c2da_mem[sec_0 + 109] = 0u8
        c2da_mem[sec_0 + 110] = 0u8
        c2da_mem[sec_0 + 111] = 0u8
        let c2da_fresh101 : uint = 0u
        c2da_mem[sec_0 + 24] = uint8(c2da_fresh101)
        c2da_mem[sec_0 + 25] = uint8(c2da_fresh101 >> 0x8)
        c2da_mem[sec_0 + 26] = uint8(c2da_fresh101 >> 0x10)
        c2da_mem[sec_0 + 27] = uint8(c2da_fresh101 >> 0x18)
        c2da_mem[sec_0 + 28] = 0u8
        c2da_mem[sec_0 + 29] = 0u8
        c2da_mem[sec_0 + 30] = 0u8
        c2da_mem[sec_0 + 31] = 0u8
        i_8++
        sec_0 += 128
    }
    i_8 = 0
    li_0 = lines
    while (i_8 < numlines) {
        let c2da_fresh102 : int16 = saveg_read16()
        let c2da_fresh103 : uint = uint(c2da_fresh102)
        c2da_mem[li_0 + 24] = uint8(c2da_fresh103)
        c2da_mem[li_0 + 25] = uint8(c2da_fresh103 >> 0x8)
        let c2da_fresh104 : int16 = saveg_read16()
        let c2da_fresh105 : uint = uint(c2da_fresh104)
        c2da_mem[li_0 + 26] = uint8(c2da_fresh105)
        c2da_mem[li_0 + 27] = uint8(c2da_fresh105 >> 0x8)
        let c2da_fresh106 : int16 = saveg_read16()
        let c2da_fresh107 : uint = uint(c2da_fresh106)
        c2da_mem[li_0 + 28] = uint8(c2da_fresh107)
        c2da_mem[li_0 + 29] = uint8(c2da_fresh107 >> 0x8)
        for (j_0 in range(0, 2)) {
            if (int(int16(uint(c2da_mem[li_0 + 30 + j_0 * 2]) | uint(c2da_mem[li_0 + 30 + j_0 * 2 + 1]) << 0x8)) == -1) {
                continue
            }
            si_0 = sides + int(int16(uint(c2da_mem[li_0 + 30 + j_0 * 2]) | uint(c2da_mem[li_0 + 30 + j_0 * 2 + 1]) << 0x8)) * 24
            let c2da_fresh108 : int = int(saveg_read16()) << 16
            let c2da_fresh109 : uint = uint(c2da_fresh108)
            c2da_mem[si_0] = uint8(c2da_fresh109)
            c2da_mem[si_0 + 1] = uint8(c2da_fresh109 >> 0x8)
            c2da_mem[si_0 + 2] = uint8(c2da_fresh109 >> 0x10)
            c2da_mem[si_0 + 3] = uint8(c2da_fresh109 >> 0x18)
            let c2da_fresh110 : int = int(saveg_read16()) << 16
            let c2da_fresh111 : uint = uint(c2da_fresh110)
            c2da_mem[si_0 + 4] = uint8(c2da_fresh111)
            c2da_mem[si_0 + 5] = uint8(c2da_fresh111 >> 0x8)
            c2da_mem[si_0 + 6] = uint8(c2da_fresh111 >> 0x10)
            c2da_mem[si_0 + 7] = uint8(c2da_fresh111 >> 0x18)
            let c2da_fresh112 : int16 = saveg_read16()
            let c2da_fresh113 : uint = uint(c2da_fresh112)
            c2da_mem[si_0 + 8] = uint8(c2da_fresh113)
            c2da_mem[si_0 + 9] = uint8(c2da_fresh113 >> 0x8)
            let c2da_fresh114 : int16 = saveg_read16()
            let c2da_fresh115 : uint = uint(c2da_fresh114)
            c2da_mem[si_0 + 10] = uint8(c2da_fresh115)
            c2da_mem[si_0 + 11] = uint8(c2da_fresh115 >> 0x8)
            let c2da_fresh116 : int16 = saveg_read16()
            let c2da_fresh117 : uint = uint(c2da_fresh116)
            c2da_mem[si_0 + 12] = uint8(c2da_fresh117)
            c2da_mem[si_0 + 13] = uint8(c2da_fresh117 >> 0x8)
        }
        i_8++
        li_0 += 88
    }
    return
}
[export, sideeffects]
def P_ArchiveThinkers() {
    var th : int = int(uint(c2da_mem[46552]) | uint(c2da_mem[46553]) << 0x8 | uint(c2da_mem[46554]) << 0x10 | uint(c2da_mem[46555]) << 0x18)
    while (th != 46544) {
        if (int(uint(c2da_mem[th + 16]) | uint(c2da_mem[th + 17]) << 0x8 | uint(c2da_mem[th + 18]) << 0x10 | uint(c2da_mem[th + 19]) << 0x18) == 126) {
            saveg_write8(1u8)
            saveg_write_pad()
            saveg_write_mobj_t(th)
            th = int(uint(c2da_mem[th + 8]) | uint(c2da_mem[th + 9]) << 0x8 | uint(c2da_mem[th + 10]) << 0x10 | uint(c2da_mem[th + 11]) << 0x18)
            continue
        }
        th = int(uint(c2da_mem[th + 8]) | uint(c2da_mem[th + 9]) << 0x8 | uint(c2da_mem[th + 10]) << 0x10 | uint(c2da_mem[th + 11]) << 0x18)
    }
    saveg_write8(0u8)
    return
}
[sideeffects]
def private saveg_write_mobj_t(var str_5 : int) {
    saveg_write_thinker_t(str_5)
    saveg_write32(int(uint(c2da_mem[str_5 + 24]) | uint(c2da_mem[str_5 + 25]) << 0x8 | uint(c2da_mem[str_5 + 26]) << 0x10 | uint(c2da_mem[str_5 + 27]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 28]) | uint(c2da_mem[str_5 + 29]) << 0x8 | uint(c2da_mem[str_5 + 30]) << 0x10 | uint(c2da_mem[str_5 + 31]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 32]) | uint(c2da_mem[str_5 + 33]) << 0x8 | uint(c2da_mem[str_5 + 34]) << 0x10 | uint(c2da_mem[str_5 + 35]) << 0x18))
    saveg_writep(int(uint(c2da_mem[str_5 + 40]) | uint(c2da_mem[str_5 + 41]) << 0x8 | uint(c2da_mem[str_5 + 42]) << 0x10 | uint(c2da_mem[str_5 + 43]) << 0x18))
    saveg_writep(int(uint(c2da_mem[str_5 + 48]) | uint(c2da_mem[str_5 + 49]) << 0x8 | uint(c2da_mem[str_5 + 50]) << 0x10 | uint(c2da_mem[str_5 + 51]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 56]) | uint(c2da_mem[str_5 + 57]) << 0x8 | uint(c2da_mem[str_5 + 58]) << 0x10 | uint(c2da_mem[str_5 + 59]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 60]) | uint(c2da_mem[str_5 + 61]) << 0x8 | uint(c2da_mem[str_5 + 62]) << 0x10 | uint(c2da_mem[str_5 + 63]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 64]) | uint(c2da_mem[str_5 + 65]) << 0x8 | uint(c2da_mem[str_5 + 66]) << 0x10 | uint(c2da_mem[str_5 + 67]) << 0x18))
    saveg_writep(int(uint(c2da_mem[str_5 + 72]) | uint(c2da_mem[str_5 + 73]) << 0x8 | uint(c2da_mem[str_5 + 74]) << 0x10 | uint(c2da_mem[str_5 + 75]) << 0x18))
    saveg_writep(int(uint(c2da_mem[str_5 + 80]) | uint(c2da_mem[str_5 + 81]) << 0x8 | uint(c2da_mem[str_5 + 82]) << 0x10 | uint(c2da_mem[str_5 + 83]) << 0x18))
    saveg_writep(int(uint(c2da_mem[str_5 + 88]) | uint(c2da_mem[str_5 + 89]) << 0x8 | uint(c2da_mem[str_5 + 90]) << 0x10 | uint(c2da_mem[str_5 + 91]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 96]) | uint(c2da_mem[str_5 + 97]) << 0x8 | uint(c2da_mem[str_5 + 98]) << 0x10 | uint(c2da_mem[str_5 + 99]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 100]) | uint(c2da_mem[str_5 + 101]) << 0x8 | uint(c2da_mem[str_5 + 102]) << 0x10 | uint(c2da_mem[str_5 + 103]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 104]) | uint(c2da_mem[str_5 + 105]) << 0x8 | uint(c2da_mem[str_5 + 106]) << 0x10 | uint(c2da_mem[str_5 + 107]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 108]) | uint(c2da_mem[str_5 + 109]) << 0x8 | uint(c2da_mem[str_5 + 110]) << 0x10 | uint(c2da_mem[str_5 + 111]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 112]) | uint(c2da_mem[str_5 + 113]) << 0x8 | uint(c2da_mem[str_5 + 114]) << 0x10 | uint(c2da_mem[str_5 + 115]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 116]) | uint(c2da_mem[str_5 + 117]) << 0x8 | uint(c2da_mem[str_5 + 118]) << 0x10 | uint(c2da_mem[str_5 + 119]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 120]) | uint(c2da_mem[str_5 + 121]) << 0x8 | uint(c2da_mem[str_5 + 122]) << 0x10 | uint(c2da_mem[str_5 + 123]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 124]) | uint(c2da_mem[str_5 + 125]) << 0x8 | uint(c2da_mem[str_5 + 126]) << 0x10 | uint(c2da_mem[str_5 + 127]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 128]) | uint(c2da_mem[str_5 + 129]) << 0x8 | uint(c2da_mem[str_5 + 130]) << 0x10 | uint(c2da_mem[str_5 + 131]) << 0x18))
    saveg_writep(int(uint(c2da_mem[str_5 + 136]) | uint(c2da_mem[str_5 + 137]) << 0x8 | uint(c2da_mem[str_5 + 138]) << 0x10 | uint(c2da_mem[str_5 + 139]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 144]) | uint(c2da_mem[str_5 + 145]) << 0x8 | uint(c2da_mem[str_5 + 146]) << 0x10 | uint(c2da_mem[str_5 + 147]) << 0x18))
    saveg_write32((int(uint(c2da_mem[str_5 + 152]) | uint(c2da_mem[str_5 + 153]) << 0x8 | uint(c2da_mem[str_5 + 154]) << 0x10 | uint(c2da_mem[str_5 + 155]) << 0x18) - 2080) / 40)
    saveg_write32(int(uint(c2da_mem[str_5 + 160]) | uint(c2da_mem[str_5 + 161]) << 0x8 | uint(c2da_mem[str_5 + 162]) << 0x10 | uint(c2da_mem[str_5 + 163]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 164]) | uint(c2da_mem[str_5 + 165]) << 0x8 | uint(c2da_mem[str_5 + 166]) << 0x10 | uint(c2da_mem[str_5 + 167]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 168]) | uint(c2da_mem[str_5 + 169]) << 0x8 | uint(c2da_mem[str_5 + 170]) << 0x10 | uint(c2da_mem[str_5 + 171]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 172]) | uint(c2da_mem[str_5 + 173]) << 0x8 | uint(c2da_mem[str_5 + 174]) << 0x10 | uint(c2da_mem[str_5 + 175]) << 0x18))
    saveg_writep(int(uint(c2da_mem[str_5 + 176]) | uint(c2da_mem[str_5 + 177]) << 0x8 | uint(c2da_mem[str_5 + 178]) << 0x10 | uint(c2da_mem[str_5 + 179]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 184]) | uint(c2da_mem[str_5 + 185]) << 0x8 | uint(c2da_mem[str_5 + 186]) << 0x10 | uint(c2da_mem[str_5 + 187]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_5 + 188]) | uint(c2da_mem[str_5 + 189]) << 0x8 | uint(c2da_mem[str_5 + 190]) << 0x10 | uint(c2da_mem[str_5 + 191]) << 0x18))
    if (int(uint(c2da_mem[str_5 + 192]) | uint(c2da_mem[str_5 + 193]) << 0x8 | uint(c2da_mem[str_5 + 194]) << 0x10 | uint(c2da_mem[str_5 + 195]) << 0x18) != 0) {
        saveg_write32(int(int64((int(uint(c2da_mem[str_5 + 192]) | uint(c2da_mem[str_5 + 193]) << 0x8 | uint(c2da_mem[str_5 + 194]) << 0x10 | uint(c2da_mem[str_5 + 195]) << 0x18) - 96) / 328) + 1l))
    } else {
        saveg_write32(0)
    }
    saveg_write32(int(uint(c2da_mem[str_5 + 200]) | uint(c2da_mem[str_5 + 201]) << 0x8 | uint(c2da_mem[str_5 + 202]) << 0x10 | uint(c2da_mem[str_5 + 203]) << 0x18))
    saveg_write_mapthing_t(str_5 + 204)
    saveg_writep(int(uint(c2da_mem[str_5 + 216]) | uint(c2da_mem[str_5 + 217]) << 0x8 | uint(c2da_mem[str_5 + 218]) << 0x10 | uint(c2da_mem[str_5 + 219]) << 0x18))
    return
}
[sideeffects]
def private saveg_write_mapthing_t(var str_6 : int) {
    saveg_write16(int16(uint(c2da_mem[str_6]) | uint(c2da_mem[str_6 + 1]) << 0x8))
    saveg_write16(int16(uint(c2da_mem[str_6 + 2]) | uint(c2da_mem[str_6 + 3]) << 0x8))
    saveg_write16(int16(uint(c2da_mem[str_6 + 4]) | uint(c2da_mem[str_6 + 5]) << 0x8))
    saveg_write16(int16(uint(c2da_mem[str_6 + 6]) | uint(c2da_mem[str_6 + 7]) << 0x8))
    saveg_write16(int16(uint(c2da_mem[str_6 + 8]) | uint(c2da_mem[str_6 + 9]) << 0x8))
    return
}
[sideeffects]
def private saveg_write_thinker_t(var str_7 : int) {
    saveg_writep(int(uint(c2da_mem[str_7]) | uint(c2da_mem[str_7 + 1]) << 0x8 | uint(c2da_mem[str_7 + 2]) << 0x10 | uint(c2da_mem[str_7 + 3]) << 0x18))
    saveg_writep(int(uint(c2da_mem[str_7 + 8]) | uint(c2da_mem[str_7 + 9]) << 0x8 | uint(c2da_mem[str_7 + 10]) << 0x10 | uint(c2da_mem[str_7 + 11]) << 0x18))
    saveg_write_actionf_t(str_7 + 16)
    return
}
[sideeffects]
def private saveg_write_actionf_t(var str_8 : int) {
    saveg_writep(int(uint(c2da_mem[str_8]) | uint(c2da_mem[str_8 + 1]) << 0x8 | uint(c2da_mem[str_8 + 2]) << 0x10 | uint(c2da_mem[str_8 + 3]) << 0x18))
    return
}
[export, sideeffects]
def P_UnArchiveThinkers() {
    var c2da_fresh118 : int
    var tclass : uint8
    var currentthinker : int
    var next : int
    var mobj : int
    currentthinker = int(uint(c2da_mem[46552]) | uint(c2da_mem[46553]) << 0x8 | uint(c2da_mem[46554]) << 0x10 | uint(c2da_mem[46555]) << 0x18)
    while (currentthinker != 46544) {
        next = int(uint(c2da_mem[currentthinker + 8]) | uint(c2da_mem[currentthinker + 9]) << 0x8 | uint(c2da_mem[currentthinker + 10]) << 0x10 | uint(c2da_mem[currentthinker + 11]) << 0x18)
        if (int(uint(c2da_mem[currentthinker + 16]) | uint(c2da_mem[currentthinker + 17]) << 0x8 | uint(c2da_mem[currentthinker + 18]) << 0x10 | uint(c2da_mem[currentthinker + 19]) << 0x18) == 126) {
            P_RemoveMobj(currentthinker)
        } else {
            Z_Free(currentthinker)
        }
        currentthinker = next
    }
    P_InitThinkers()
    while (true) {
        tclass = saveg_read8()
        c2da_fresh118 = int(tclass)
        if (c2da_fresh118 == 0) {
            return
        } elif (c2da_fresh118 == 1) {
            saveg_read_pad()
            mobj = Z_Malloc(224, 5, 0)
            saveg_read_mobj_t(mobj)
            let c2da_fresh119 : uint = 0u
            c2da_mem[mobj + 176] = uint8(c2da_fresh119)
            c2da_mem[mobj + 177] = uint8(c2da_fresh119 >> 0x8)
            c2da_mem[mobj + 178] = uint8(c2da_fresh119 >> 0x10)
            c2da_mem[mobj + 179] = uint8(c2da_fresh119 >> 0x18)
            c2da_mem[mobj + 180] = 0u8
            c2da_mem[mobj + 181] = 0u8
            c2da_mem[mobj + 182] = 0u8
            c2da_mem[mobj + 183] = 0u8
            let c2da_fresh120 : uint = 0u
            c2da_mem[mobj + 216] = uint8(c2da_fresh120)
            c2da_mem[mobj + 217] = uint8(c2da_fresh120 >> 0x8)
            c2da_mem[mobj + 218] = uint8(c2da_fresh120 >> 0x10)
            c2da_mem[mobj + 219] = uint8(c2da_fresh120 >> 0x18)
            c2da_mem[mobj + 220] = 0u8
            c2da_mem[mobj + 221] = 0u8
            c2da_mem[mobj + 222] = 0u8
            c2da_mem[mobj + 223] = 0u8
            P_SetThingPosition(mobj)
            let c2da_fresh121 : int = 51056 + int(uint(c2da_mem[mobj + 128]) | uint(c2da_mem[mobj + 129]) << 0x8 | uint(c2da_mem[mobj + 130]) << 0x10 | uint(c2da_mem[mobj + 131]) << 0x18) * 92
            let c2da_fresh122 : uint = uint(c2da_fresh121)
            c2da_mem[mobj + 136] = uint8(c2da_fresh122)
            c2da_mem[mobj + 137] = uint8(c2da_fresh122 >> 0x8)
            c2da_mem[mobj + 138] = uint8(c2da_fresh122 >> 0x10)
            c2da_mem[mobj + 139] = uint8(c2da_fresh122 >> 0x18)
            c2da_mem[mobj + 140] = 0u8
            c2da_mem[mobj + 141] = 0u8
            c2da_mem[mobj + 142] = 0u8
            c2da_mem[mobj + 143] = 0u8
            let c2da_fresh123 : int = int(uint(c2da_mem[mobj + 88]) | uint(c2da_mem[mobj + 89]) << 0x8 | uint(c2da_mem[mobj + 90]) << 0x10 | uint(c2da_mem[mobj + 91]) << 0x18)
            let c2da_fresh124 : int = int(uint(c2da_mem[c2da_fresh123]) | uint(c2da_mem[c2da_fresh123 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh123 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh123 + 3]) << 0x18)
            let c2da_fresh125 : int = int(uint(c2da_mem[c2da_fresh124]) | uint(c2da_mem[c2da_fresh124 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh124 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh124 + 3]) << 0x18)
            let c2da_fresh126 : uint = uint(c2da_fresh125)
            c2da_mem[mobj + 96] = uint8(c2da_fresh126)
            c2da_mem[mobj + 97] = uint8(c2da_fresh126 >> 0x8)
            c2da_mem[mobj + 98] = uint8(c2da_fresh126 >> 0x10)
            c2da_mem[mobj + 99] = uint8(c2da_fresh126 >> 0x18)
            let c2da_fresh127 : int = int(uint(c2da_mem[mobj + 88]) | uint(c2da_mem[mobj + 89]) << 0x8 | uint(c2da_mem[mobj + 90]) << 0x10 | uint(c2da_mem[mobj + 91]) << 0x18)
            let c2da_fresh128 : int = int(uint(c2da_mem[c2da_fresh127]) | uint(c2da_mem[c2da_fresh127 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh127 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh127 + 3]) << 0x18) + 4
            let c2da_fresh129 : int = int(uint(c2da_mem[c2da_fresh128]) | uint(c2da_mem[c2da_fresh128 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh128 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh128 + 3]) << 0x18)
            let c2da_fresh130 : uint = uint(c2da_fresh129)
            c2da_mem[mobj + 100] = uint8(c2da_fresh130)
            c2da_mem[mobj + 101] = uint8(c2da_fresh130 >> 0x8)
            c2da_mem[mobj + 102] = uint8(c2da_fresh130 >> 0x10)
            c2da_mem[mobj + 103] = uint8(c2da_fresh130 >> 0x18)
            let c2da_fresh131 : uint = 126u
            c2da_mem[mobj + 16] = uint8(c2da_fresh131)
            c2da_mem[mobj + 17] = uint8(c2da_fresh131 >> 0x8)
            c2da_mem[mobj + 18] = uint8(c2da_fresh131 >> 0x10)
            c2da_mem[mobj + 19] = uint8(c2da_fresh131 >> 0x18)
            c2da_mem[mobj + 20] = 0u8
            c2da_mem[mobj + 21] = 0u8
            c2da_mem[mobj + 22] = 0u8
            c2da_mem[mobj + 23] = 0u8
            P_AddThinker(mobj)
        } else {
            I_Error(360817, [C2daVaArg(tag = 1, i64 = int64(tclass), f64 = 0.0lf, raw = 0x0)])
        }
    }
}
[sideeffects]
def private saveg_read_mobj_t(var str_9 : int) {
    var pl : int
    saveg_read_thinker_t(str_9)
    let c2da_fresh132 : int = saveg_read32()
    let c2da_fresh133 : uint = uint(c2da_fresh132)
    c2da_mem[str_9 + 24] = uint8(c2da_fresh133)
    c2da_mem[str_9 + 25] = uint8(c2da_fresh133 >> 0x8)
    c2da_mem[str_9 + 26] = uint8(c2da_fresh133 >> 0x10)
    c2da_mem[str_9 + 27] = uint8(c2da_fresh133 >> 0x18)
    let c2da_fresh134 : int = saveg_read32()
    let c2da_fresh135 : uint = uint(c2da_fresh134)
    c2da_mem[str_9 + 28] = uint8(c2da_fresh135)
    c2da_mem[str_9 + 29] = uint8(c2da_fresh135 >> 0x8)
    c2da_mem[str_9 + 30] = uint8(c2da_fresh135 >> 0x10)
    c2da_mem[str_9 + 31] = uint8(c2da_fresh135 >> 0x18)
    let c2da_fresh136 : int = saveg_read32()
    let c2da_fresh137 : uint = uint(c2da_fresh136)
    c2da_mem[str_9 + 32] = uint8(c2da_fresh137)
    c2da_mem[str_9 + 33] = uint8(c2da_fresh137 >> 0x8)
    c2da_mem[str_9 + 34] = uint8(c2da_fresh137 >> 0x10)
    c2da_mem[str_9 + 35] = uint8(c2da_fresh137 >> 0x18)
    let c2da_fresh138 : int = saveg_readp()
    let c2da_fresh139 : uint = uint(c2da_fresh138)
    c2da_mem[str_9 + 40] = uint8(c2da_fresh139)
    c2da_mem[str_9 + 41] = uint8(c2da_fresh139 >> 0x8)
    c2da_mem[str_9 + 42] = uint8(c2da_fresh139 >> 0x10)
    c2da_mem[str_9 + 43] = uint8(c2da_fresh139 >> 0x18)
    c2da_mem[str_9 + 44] = 0u8
    c2da_mem[str_9 + 45] = 0u8
    c2da_mem[str_9 + 46] = 0u8
    c2da_mem[str_9 + 47] = 0u8
    let c2da_fresh140 : int = saveg_readp()
    let c2da_fresh141 : uint = uint(c2da_fresh140)
    c2da_mem[str_9 + 48] = uint8(c2da_fresh141)
    c2da_mem[str_9 + 49] = uint8(c2da_fresh141 >> 0x8)
    c2da_mem[str_9 + 50] = uint8(c2da_fresh141 >> 0x10)
    c2da_mem[str_9 + 51] = uint8(c2da_fresh141 >> 0x18)
    c2da_mem[str_9 + 52] = 0u8
    c2da_mem[str_9 + 53] = 0u8
    c2da_mem[str_9 + 54] = 0u8
    c2da_mem[str_9 + 55] = 0u8
    let c2da_fresh142 : uint = uint(saveg_read32())
    let c2da_fresh143 : uint = c2da_fresh142
    c2da_mem[str_9 + 56] = uint8(c2da_fresh143)
    c2da_mem[str_9 + 57] = uint8(c2da_fresh143 >> 0x8)
    c2da_mem[str_9 + 58] = uint8(c2da_fresh143 >> 0x10)
    c2da_mem[str_9 + 59] = uint8(c2da_fresh143 >> 0x18)
    let c2da_fresh144 : uint = uint(saveg_read32())
    let c2da_fresh145 : uint = c2da_fresh144
    c2da_mem[str_9 + 60] = uint8(c2da_fresh145)
    c2da_mem[str_9 + 61] = uint8(c2da_fresh145 >> 0x8)
    c2da_mem[str_9 + 62] = uint8(c2da_fresh145 >> 0x10)
    c2da_mem[str_9 + 63] = uint8(c2da_fresh145 >> 0x18)
    let c2da_fresh146 : int = saveg_read32()
    let c2da_fresh147 : uint = uint(c2da_fresh146)
    c2da_mem[str_9 + 64] = uint8(c2da_fresh147)
    c2da_mem[str_9 + 65] = uint8(c2da_fresh147 >> 0x8)
    c2da_mem[str_9 + 66] = uint8(c2da_fresh147 >> 0x10)
    c2da_mem[str_9 + 67] = uint8(c2da_fresh147 >> 0x18)
    let c2da_fresh148 : int = saveg_readp()
    let c2da_fresh149 : uint = uint(c2da_fresh148)
    c2da_mem[str_9 + 72] = uint8(c2da_fresh149)
    c2da_mem[str_9 + 73] = uint8(c2da_fresh149 >> 0x8)
    c2da_mem[str_9 + 74] = uint8(c2da_fresh149 >> 0x10)
    c2da_mem[str_9 + 75] = uint8(c2da_fresh149 >> 0x18)
    c2da_mem[str_9 + 76] = 0u8
    c2da_mem[str_9 + 77] = 0u8
    c2da_mem[str_9 + 78] = 0u8
    c2da_mem[str_9 + 79] = 0u8
    let c2da_fresh150 : int = saveg_readp()
    let c2da_fresh151 : uint = uint(c2da_fresh150)
    c2da_mem[str_9 + 80] = uint8(c2da_fresh151)
    c2da_mem[str_9 + 81] = uint8(c2da_fresh151 >> 0x8)
    c2da_mem[str_9 + 82] = uint8(c2da_fresh151 >> 0x10)
    c2da_mem[str_9 + 83] = uint8(c2da_fresh151 >> 0x18)
    c2da_mem[str_9 + 84] = 0u8
    c2da_mem[str_9 + 85] = 0u8
    c2da_mem[str_9 + 86] = 0u8
    c2da_mem[str_9 + 87] = 0u8
    let c2da_fresh152 : int = saveg_readp()
    let c2da_fresh153 : uint = uint(c2da_fresh152)
    c2da_mem[str_9 + 88] = uint8(c2da_fresh153)
    c2da_mem[str_9 + 89] = uint8(c2da_fresh153 >> 0x8)
    c2da_mem[str_9 + 90] = uint8(c2da_fresh153 >> 0x10)
    c2da_mem[str_9 + 91] = uint8(c2da_fresh153 >> 0x18)
    c2da_mem[str_9 + 92] = 0u8
    c2da_mem[str_9 + 93] = 0u8
    c2da_mem[str_9 + 94] = 0u8
    c2da_mem[str_9 + 95] = 0u8
    let c2da_fresh154 : int = saveg_read32()
    let c2da_fresh155 : uint = uint(c2da_fresh154)
    c2da_mem[str_9 + 96] = uint8(c2da_fresh155)
    c2da_mem[str_9 + 97] = uint8(c2da_fresh155 >> 0x8)
    c2da_mem[str_9 + 98] = uint8(c2da_fresh155 >> 0x10)
    c2da_mem[str_9 + 99] = uint8(c2da_fresh155 >> 0x18)
    let c2da_fresh156 : int = saveg_read32()
    let c2da_fresh157 : uint = uint(c2da_fresh156)
    c2da_mem[str_9 + 100] = uint8(c2da_fresh157)
    c2da_mem[str_9 + 101] = uint8(c2da_fresh157 >> 0x8)
    c2da_mem[str_9 + 102] = uint8(c2da_fresh157 >> 0x10)
    c2da_mem[str_9 + 103] = uint8(c2da_fresh157 >> 0x18)
    let c2da_fresh158 : int = saveg_read32()
    let c2da_fresh159 : uint = uint(c2da_fresh158)
    c2da_mem[str_9 + 104] = uint8(c2da_fresh159)
    c2da_mem[str_9 + 105] = uint8(c2da_fresh159 >> 0x8)
    c2da_mem[str_9 + 106] = uint8(c2da_fresh159 >> 0x10)
    c2da_mem[str_9 + 107] = uint8(c2da_fresh159 >> 0x18)
    let c2da_fresh160 : int = saveg_read32()
    let c2da_fresh161 : uint = uint(c2da_fresh160)
    c2da_mem[str_9 + 108] = uint8(c2da_fresh161)
    c2da_mem[str_9 + 109] = uint8(c2da_fresh161 >> 0x8)
    c2da_mem[str_9 + 110] = uint8(c2da_fresh161 >> 0x10)
    c2da_mem[str_9 + 111] = uint8(c2da_fresh161 >> 0x18)
    let c2da_fresh162 : int = saveg_read32()
    let c2da_fresh163 : uint = uint(c2da_fresh162)
    c2da_mem[str_9 + 112] = uint8(c2da_fresh163)
    c2da_mem[str_9 + 113] = uint8(c2da_fresh163 >> 0x8)
    c2da_mem[str_9 + 114] = uint8(c2da_fresh163 >> 0x10)
    c2da_mem[str_9 + 115] = uint8(c2da_fresh163 >> 0x18)
    let c2da_fresh164 : int = saveg_read32()
    let c2da_fresh165 : uint = uint(c2da_fresh164)
    c2da_mem[str_9 + 116] = uint8(c2da_fresh165)
    c2da_mem[str_9 + 117] = uint8(c2da_fresh165 >> 0x8)
    c2da_mem[str_9 + 118] = uint8(c2da_fresh165 >> 0x10)
    c2da_mem[str_9 + 119] = uint8(c2da_fresh165 >> 0x18)
    let c2da_fresh166 : int = saveg_read32()
    let c2da_fresh167 : uint = uint(c2da_fresh166)
    c2da_mem[str_9 + 120] = uint8(c2da_fresh167)
    c2da_mem[str_9 + 121] = uint8(c2da_fresh167 >> 0x8)
    c2da_mem[str_9 + 122] = uint8(c2da_fresh167 >> 0x10)
    c2da_mem[str_9 + 123] = uint8(c2da_fresh167 >> 0x18)
    let c2da_fresh168 : int = saveg_read32()
    let c2da_fresh169 : uint = uint(c2da_fresh168)
    c2da_mem[str_9 + 124] = uint8(c2da_fresh169)
    c2da_mem[str_9 + 125] = uint8(c2da_fresh169 >> 0x8)
    c2da_mem[str_9 + 126] = uint8(c2da_fresh169 >> 0x10)
    c2da_mem[str_9 + 127] = uint8(c2da_fresh169 >> 0x18)
    let c2da_fresh170 : uint = uint(saveg_read32())
    let c2da_fresh171 : uint = c2da_fresh170
    c2da_mem[str_9 + 128] = uint8(c2da_fresh171)
    c2da_mem[str_9 + 129] = uint8(c2da_fresh171 >> 0x8)
    c2da_mem[str_9 + 130] = uint8(c2da_fresh171 >> 0x10)
    c2da_mem[str_9 + 131] = uint8(c2da_fresh171 >> 0x18)
    let c2da_fresh172 : int = saveg_readp()
    let c2da_fresh173 : uint = uint(c2da_fresh172)
    c2da_mem[str_9 + 136] = uint8(c2da_fresh173)
    c2da_mem[str_9 + 137] = uint8(c2da_fresh173 >> 0x8)
    c2da_mem[str_9 + 138] = uint8(c2da_fresh173 >> 0x10)
    c2da_mem[str_9 + 139] = uint8(c2da_fresh173 >> 0x18)
    c2da_mem[str_9 + 140] = 0u8
    c2da_mem[str_9 + 141] = 0u8
    c2da_mem[str_9 + 142] = 0u8
    c2da_mem[str_9 + 143] = 0u8
    let c2da_fresh174 : int = saveg_read32()
    let c2da_fresh175 : uint = uint(c2da_fresh174)
    c2da_mem[str_9 + 144] = uint8(c2da_fresh175)
    c2da_mem[str_9 + 145] = uint8(c2da_fresh175 >> 0x8)
    c2da_mem[str_9 + 146] = uint8(c2da_fresh175 >> 0x10)
    c2da_mem[str_9 + 147] = uint8(c2da_fresh175 >> 0x18)
    let c2da_fresh176 : int = 2080 + saveg_read32() * 40
    let c2da_fresh177 : uint = uint(c2da_fresh176)
    c2da_mem[str_9 + 152] = uint8(c2da_fresh177)
    c2da_mem[str_9 + 153] = uint8(c2da_fresh177 >> 0x8)
    c2da_mem[str_9 + 154] = uint8(c2da_fresh177 >> 0x10)
    c2da_mem[str_9 + 155] = uint8(c2da_fresh177 >> 0x18)
    c2da_mem[str_9 + 156] = 0u8
    c2da_mem[str_9 + 157] = 0u8
    c2da_mem[str_9 + 158] = 0u8
    c2da_mem[str_9 + 159] = 0u8
    let c2da_fresh178 : int = saveg_read32()
    let c2da_fresh179 : uint = uint(c2da_fresh178)
    c2da_mem[str_9 + 160] = uint8(c2da_fresh179)
    c2da_mem[str_9 + 161] = uint8(c2da_fresh179 >> 0x8)
    c2da_mem[str_9 + 162] = uint8(c2da_fresh179 >> 0x10)
    c2da_mem[str_9 + 163] = uint8(c2da_fresh179 >> 0x18)
    let c2da_fresh180 : int = saveg_read32()
    let c2da_fresh181 : uint = uint(c2da_fresh180)
    c2da_mem[str_9 + 164] = uint8(c2da_fresh181)
    c2da_mem[str_9 + 165] = uint8(c2da_fresh181 >> 0x8)
    c2da_mem[str_9 + 166] = uint8(c2da_fresh181 >> 0x10)
    c2da_mem[str_9 + 167] = uint8(c2da_fresh181 >> 0x18)
    let c2da_fresh182 : int = saveg_read32()
    let c2da_fresh183 : uint = uint(c2da_fresh182)
    c2da_mem[str_9 + 168] = uint8(c2da_fresh183)
    c2da_mem[str_9 + 169] = uint8(c2da_fresh183 >> 0x8)
    c2da_mem[str_9 + 170] = uint8(c2da_fresh183 >> 0x10)
    c2da_mem[str_9 + 171] = uint8(c2da_fresh183 >> 0x18)
    let c2da_fresh184 : int = saveg_read32()
    let c2da_fresh185 : uint = uint(c2da_fresh184)
    c2da_mem[str_9 + 172] = uint8(c2da_fresh185)
    c2da_mem[str_9 + 173] = uint8(c2da_fresh185 >> 0x8)
    c2da_mem[str_9 + 174] = uint8(c2da_fresh185 >> 0x10)
    c2da_mem[str_9 + 175] = uint8(c2da_fresh185 >> 0x18)
    let c2da_fresh186 : int = saveg_readp()
    let c2da_fresh187 : uint = uint(c2da_fresh186)
    c2da_mem[str_9 + 176] = uint8(c2da_fresh187)
    c2da_mem[str_9 + 177] = uint8(c2da_fresh187 >> 0x8)
    c2da_mem[str_9 + 178] = uint8(c2da_fresh187 >> 0x10)
    c2da_mem[str_9 + 179] = uint8(c2da_fresh187 >> 0x18)
    c2da_mem[str_9 + 180] = 0u8
    c2da_mem[str_9 + 181] = 0u8
    c2da_mem[str_9 + 182] = 0u8
    c2da_mem[str_9 + 183] = 0u8
    let c2da_fresh188 : int = saveg_read32()
    let c2da_fresh189 : uint = uint(c2da_fresh188)
    c2da_mem[str_9 + 184] = uint8(c2da_fresh189)
    c2da_mem[str_9 + 185] = uint8(c2da_fresh189 >> 0x8)
    c2da_mem[str_9 + 186] = uint8(c2da_fresh189 >> 0x10)
    c2da_mem[str_9 + 187] = uint8(c2da_fresh189 >> 0x18)
    let c2da_fresh190 : int = saveg_read32()
    let c2da_fresh191 : uint = uint(c2da_fresh190)
    c2da_mem[str_9 + 188] = uint8(c2da_fresh191)
    c2da_mem[str_9 + 189] = uint8(c2da_fresh191 >> 0x8)
    c2da_mem[str_9 + 190] = uint8(c2da_fresh191 >> 0x10)
    c2da_mem[str_9 + 191] = uint8(c2da_fresh191 >> 0x18)
    pl = saveg_read32()
    if (pl > 0) {
        let c2da_fresh192 : int = 96 + (pl - 1) * 328
        let c2da_fresh193 : uint = uint(c2da_fresh192)
        c2da_mem[str_9 + 192] = uint8(c2da_fresh193)
        c2da_mem[str_9 + 193] = uint8(c2da_fresh193 >> 0x8)
        c2da_mem[str_9 + 194] = uint8(c2da_fresh193 >> 0x10)
        c2da_mem[str_9 + 195] = uint8(c2da_fresh193 >> 0x18)
        c2da_mem[str_9 + 196] = 0u8
        c2da_mem[str_9 + 197] = 0u8
        c2da_mem[str_9 + 198] = 0u8
        c2da_mem[str_9 + 199] = 0u8
        let c2da_fresh194 : int = int(uint(c2da_mem[str_9 + 192]) | uint(c2da_mem[str_9 + 193]) << 0x8 | uint(c2da_mem[str_9 + 194]) << 0x10 | uint(c2da_mem[str_9 + 195]) << 0x18)
        let c2da_fresh195 : uint = uint(str_9)
        c2da_mem[c2da_fresh194] = uint8(c2da_fresh195)
        c2da_mem[c2da_fresh194 + 1] = uint8(c2da_fresh195 >> 0x8)
        c2da_mem[c2da_fresh194 + 2] = uint8(c2da_fresh195 >> 0x10)
        c2da_mem[c2da_fresh194 + 3] = uint8(c2da_fresh195 >> 0x18)
        c2da_mem[c2da_fresh194 + 4] = 0u8
        c2da_mem[c2da_fresh194 + 5] = 0u8
        c2da_mem[c2da_fresh194 + 6] = 0u8
        c2da_mem[c2da_fresh194 + 7] = 0u8
    } else {
        let c2da_fresh196 : uint = 0u
        c2da_mem[str_9 + 192] = uint8(c2da_fresh196)
        c2da_mem[str_9 + 193] = uint8(c2da_fresh196 >> 0x8)
        c2da_mem[str_9 + 194] = uint8(c2da_fresh196 >> 0x10)
        c2da_mem[str_9 + 195] = uint8(c2da_fresh196 >> 0x18)
        c2da_mem[str_9 + 196] = 0u8
        c2da_mem[str_9 + 197] = 0u8
        c2da_mem[str_9 + 198] = 0u8
        c2da_mem[str_9 + 199] = 0u8
    }
    let c2da_fresh197 : int = saveg_read32()
    let c2da_fresh198 : uint = uint(c2da_fresh197)
    c2da_mem[str_9 + 200] = uint8(c2da_fresh198)
    c2da_mem[str_9 + 201] = uint8(c2da_fresh198 >> 0x8)
    c2da_mem[str_9 + 202] = uint8(c2da_fresh198 >> 0x10)
    c2da_mem[str_9 + 203] = uint8(c2da_fresh198 >> 0x18)
    saveg_read_mapthing_t(str_9 + 204)
    let c2da_fresh199 : int = saveg_readp()
    let c2da_fresh200 : uint = uint(c2da_fresh199)
    c2da_mem[str_9 + 216] = uint8(c2da_fresh200)
    c2da_mem[str_9 + 217] = uint8(c2da_fresh200 >> 0x8)
    c2da_mem[str_9 + 218] = uint8(c2da_fresh200 >> 0x10)
    c2da_mem[str_9 + 219] = uint8(c2da_fresh200 >> 0x18)
    c2da_mem[str_9 + 220] = 0u8
    c2da_mem[str_9 + 221] = 0u8
    c2da_mem[str_9 + 222] = 0u8
    c2da_mem[str_9 + 223] = 0u8
    return
}
[sideeffects]
def private saveg_read_mapthing_t(var str_10 : int) {
    let c2da_fresh201 : int16 = saveg_read16()
    let c2da_fresh202 : uint = uint(c2da_fresh201)
    c2da_mem[str_10] = uint8(c2da_fresh202)
    c2da_mem[str_10 + 1] = uint8(c2da_fresh202 >> 0x8)
    let c2da_fresh203 : int16 = saveg_read16()
    let c2da_fresh204 : uint = uint(c2da_fresh203)
    c2da_mem[str_10 + 2] = uint8(c2da_fresh204)
    c2da_mem[str_10 + 3] = uint8(c2da_fresh204 >> 0x8)
    let c2da_fresh205 : int16 = saveg_read16()
    let c2da_fresh206 : uint = uint(c2da_fresh205)
    c2da_mem[str_10 + 4] = uint8(c2da_fresh206)
    c2da_mem[str_10 + 5] = uint8(c2da_fresh206 >> 0x8)
    let c2da_fresh207 : int16 = saveg_read16()
    let c2da_fresh208 : uint = uint(c2da_fresh207)
    c2da_mem[str_10 + 6] = uint8(c2da_fresh208)
    c2da_mem[str_10 + 7] = uint8(c2da_fresh208 >> 0x8)
    let c2da_fresh209 : int16 = saveg_read16()
    let c2da_fresh210 : uint = uint(c2da_fresh209)
    c2da_mem[str_10 + 8] = uint8(c2da_fresh210)
    c2da_mem[str_10 + 9] = uint8(c2da_fresh210 >> 0x8)
    return
}
[sideeffects]
def private saveg_read_thinker_t(var str_11 : int) {
    let c2da_fresh211 : int = saveg_readp()
    let c2da_fresh212 : uint = uint(c2da_fresh211)
    c2da_mem[str_11] = uint8(c2da_fresh212)
    c2da_mem[str_11 + 1] = uint8(c2da_fresh212 >> 0x8)
    c2da_mem[str_11 + 2] = uint8(c2da_fresh212 >> 0x10)
    c2da_mem[str_11 + 3] = uint8(c2da_fresh212 >> 0x18)
    c2da_mem[str_11 + 4] = 0u8
    c2da_mem[str_11 + 5] = 0u8
    c2da_mem[str_11 + 6] = 0u8
    c2da_mem[str_11 + 7] = 0u8
    let c2da_fresh213 : int = saveg_readp()
    let c2da_fresh214 : uint = uint(c2da_fresh213)
    c2da_mem[str_11 + 8] = uint8(c2da_fresh214)
    c2da_mem[str_11 + 9] = uint8(c2da_fresh214 >> 0x8)
    c2da_mem[str_11 + 10] = uint8(c2da_fresh214 >> 0x10)
    c2da_mem[str_11 + 11] = uint8(c2da_fresh214 >> 0x18)
    c2da_mem[str_11 + 12] = 0u8
    c2da_mem[str_11 + 13] = 0u8
    c2da_mem[str_11 + 14] = 0u8
    c2da_mem[str_11 + 15] = 0u8
    saveg_read_actionf_t(str_11 + 16)
    return
}
[sideeffects]
def private saveg_read_actionf_t(var str_12 : int) {
    let c2da_fresh215 : int = saveg_readp()
    let c2da_fresh216 : uint = uint(c2da_fresh215)
    c2da_mem[str_12] = uint8(c2da_fresh216)
    c2da_mem[str_12 + 1] = uint8(c2da_fresh216 >> 0x8)
    c2da_mem[str_12 + 2] = uint8(c2da_fresh216 >> 0x10)
    c2da_mem[str_12 + 3] = uint8(c2da_fresh216 >> 0x18)
    c2da_mem[str_12 + 4] = 0u8
    c2da_mem[str_12 + 5] = 0u8
    c2da_mem[str_12 + 6] = 0u8
    c2da_mem[str_12 + 7] = 0u8
    return
}
[export, sideeffects]
def P_ArchiveSpecials() {
    var th_0 : int
    var i_9 : int
    th_0 = int(uint(c2da_mem[46552]) | uint(c2da_mem[46553]) << 0x8 | uint(c2da_mem[46554]) << 0x10 | uint(c2da_mem[46555]) << 0x18)
    while (th_0 != 46544) {
        if (int(uint(c2da_mem[th_0 + 16]) | uint(c2da_mem[th_0 + 17]) << 0x8 | uint(c2da_mem[th_0 + 18]) << 0x10 | uint(c2da_mem[th_0 + 19]) << 0x18) == 0) {
            i_9 = 0
            while (i_9 < 30) {
                if (activeceilings[i_9] == th_0) {
                    break
                }
                i_9++
            }
            if (i_9 < 30) {
                saveg_write8(0u8)
                saveg_write_pad()
                saveg_write_ceiling_t(th_0)
            }
            th_0 = int(uint(c2da_mem[th_0 + 8]) | uint(c2da_mem[th_0 + 9]) << 0x8 | uint(c2da_mem[th_0 + 10]) << 0x10 | uint(c2da_mem[th_0 + 11]) << 0x18)
            continue
        }
        if (int(uint(c2da_mem[th_0 + 16]) | uint(c2da_mem[th_0 + 17]) << 0x8 | uint(c2da_mem[th_0 + 18]) << 0x10 | uint(c2da_mem[th_0 + 19]) << 0x18) == 123) {
            saveg_write8(0u8)
            saveg_write_pad()
            saveg_write_ceiling_t(th_0)
            th_0 = int(uint(c2da_mem[th_0 + 8]) | uint(c2da_mem[th_0 + 9]) << 0x8 | uint(c2da_mem[th_0 + 10]) << 0x10 | uint(c2da_mem[th_0 + 11]) << 0x18)
            continue
        }
        if (int(uint(c2da_mem[th_0 + 16]) | uint(c2da_mem[th_0 + 17]) << 0x8 | uint(c2da_mem[th_0 + 18]) << 0x10 | uint(c2da_mem[th_0 + 19]) << 0x18) == 124) {
            saveg_write8(1u8)
            saveg_write_pad()
            saveg_write_vldoor_t(th_0)
            th_0 = int(uint(c2da_mem[th_0 + 8]) | uint(c2da_mem[th_0 + 9]) << 0x8 | uint(c2da_mem[th_0 + 10]) << 0x10 | uint(c2da_mem[th_0 + 11]) << 0x18)
            continue
        }
        if (int(uint(c2da_mem[th_0 + 16]) | uint(c2da_mem[th_0 + 17]) << 0x8 | uint(c2da_mem[th_0 + 18]) << 0x10 | uint(c2da_mem[th_0 + 19]) << 0x18) == 128) {
            saveg_write8(2u8)
            saveg_write_pad()
            saveg_write_floormove_t(th_0)
            th_0 = int(uint(c2da_mem[th_0 + 8]) | uint(c2da_mem[th_0 + 9]) << 0x8 | uint(c2da_mem[th_0 + 10]) << 0x10 | uint(c2da_mem[th_0 + 11]) << 0x18)
            continue
        }
        if (int(uint(c2da_mem[th_0 + 16]) | uint(c2da_mem[th_0 + 17]) << 0x8 | uint(c2da_mem[th_0 + 18]) << 0x10 | uint(c2da_mem[th_0 + 19]) << 0x18) == 125) {
            saveg_write8(3u8)
            saveg_write_pad()
            saveg_write_plat_t(th_0)
            th_0 = int(uint(c2da_mem[th_0 + 8]) | uint(c2da_mem[th_0 + 9]) << 0x8 | uint(c2da_mem[th_0 + 10]) << 0x10 | uint(c2da_mem[th_0 + 11]) << 0x18)
            continue
        }
        if (int(uint(c2da_mem[th_0 + 16]) | uint(c2da_mem[th_0 + 17]) << 0x8 | uint(c2da_mem[th_0 + 18]) << 0x10 | uint(c2da_mem[th_0 + 19]) << 0x18) == 130) {
            saveg_write8(4u8)
            saveg_write_pad()
            saveg_write_lightflash_t(th_0)
            th_0 = int(uint(c2da_mem[th_0 + 8]) | uint(c2da_mem[th_0 + 9]) << 0x8 | uint(c2da_mem[th_0 + 10]) << 0x10 | uint(c2da_mem[th_0 + 11]) << 0x18)
            continue
        }
        if (int(uint(c2da_mem[th_0 + 16]) | uint(c2da_mem[th_0 + 17]) << 0x8 | uint(c2da_mem[th_0 + 18]) << 0x10 | uint(c2da_mem[th_0 + 19]) << 0x18) == 131) {
            saveg_write8(5u8)
            saveg_write_pad()
            saveg_write_strobe_t(th_0)
            th_0 = int(uint(c2da_mem[th_0 + 8]) | uint(c2da_mem[th_0 + 9]) << 0x8 | uint(c2da_mem[th_0 + 10]) << 0x10 | uint(c2da_mem[th_0 + 11]) << 0x18)
            continue
        }
        if (int(uint(c2da_mem[th_0 + 16]) | uint(c2da_mem[th_0 + 17]) << 0x8 | uint(c2da_mem[th_0 + 18]) << 0x10 | uint(c2da_mem[th_0 + 19]) << 0x18) == 132) {
            saveg_write8(6u8)
            saveg_write_pad()
            saveg_write_glow_t(th_0)
            th_0 = int(uint(c2da_mem[th_0 + 8]) | uint(c2da_mem[th_0 + 9]) << 0x8 | uint(c2da_mem[th_0 + 10]) << 0x10 | uint(c2da_mem[th_0 + 11]) << 0x18)
            continue
        }
        th_0 = int(uint(c2da_mem[th_0 + 8]) | uint(c2da_mem[th_0 + 9]) << 0x8 | uint(c2da_mem[th_0 + 10]) << 0x10 | uint(c2da_mem[th_0 + 11]) << 0x18)
    }
    saveg_write8(7u8)
    return
}
[sideeffects]
def private saveg_write_glow_t(var str_13 : int) {
    saveg_write_thinker_t(str_13)
    saveg_write32(int(int64((int(uint(c2da_mem[str_13 + 24]) | uint(c2da_mem[str_13 + 25]) << 0x8 | uint(c2da_mem[str_13 + 26]) << 0x10 | uint(c2da_mem[str_13 + 27]) << 0x18) - sectors) / 128)))
    saveg_write32(int(uint(c2da_mem[str_13 + 32]) | uint(c2da_mem[str_13 + 33]) << 0x8 | uint(c2da_mem[str_13 + 34]) << 0x10 | uint(c2da_mem[str_13 + 35]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_13 + 36]) | uint(c2da_mem[str_13 + 37]) << 0x8 | uint(c2da_mem[str_13 + 38]) << 0x10 | uint(c2da_mem[str_13 + 39]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_13 + 40]) | uint(c2da_mem[str_13 + 41]) << 0x8 | uint(c2da_mem[str_13 + 42]) << 0x10 | uint(c2da_mem[str_13 + 43]) << 0x18))
    return
}
[sideeffects]
def private saveg_write_strobe_t(var str_14 : int) {
    saveg_write_thinker_t(str_14)
    saveg_write32(int(int64((int(uint(c2da_mem[str_14 + 24]) | uint(c2da_mem[str_14 + 25]) << 0x8 | uint(c2da_mem[str_14 + 26]) << 0x10 | uint(c2da_mem[str_14 + 27]) << 0x18) - sectors) / 128)))
    saveg_write32(int(uint(c2da_mem[str_14 + 32]) | uint(c2da_mem[str_14 + 33]) << 0x8 | uint(c2da_mem[str_14 + 34]) << 0x10 | uint(c2da_mem[str_14 + 35]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_14 + 36]) | uint(c2da_mem[str_14 + 37]) << 0x8 | uint(c2da_mem[str_14 + 38]) << 0x10 | uint(c2da_mem[str_14 + 39]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_14 + 40]) | uint(c2da_mem[str_14 + 41]) << 0x8 | uint(c2da_mem[str_14 + 42]) << 0x10 | uint(c2da_mem[str_14 + 43]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_14 + 44]) | uint(c2da_mem[str_14 + 45]) << 0x8 | uint(c2da_mem[str_14 + 46]) << 0x10 | uint(c2da_mem[str_14 + 47]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_14 + 48]) | uint(c2da_mem[str_14 + 49]) << 0x8 | uint(c2da_mem[str_14 + 50]) << 0x10 | uint(c2da_mem[str_14 + 51]) << 0x18))
    return
}
[sideeffects]
def private saveg_write_lightflash_t(var str_15 : int) {
    saveg_write_thinker_t(str_15)
    saveg_write32(int(int64((int(uint(c2da_mem[str_15 + 24]) | uint(c2da_mem[str_15 + 25]) << 0x8 | uint(c2da_mem[str_15 + 26]) << 0x10 | uint(c2da_mem[str_15 + 27]) << 0x18) - sectors) / 128)))
    saveg_write32(int(uint(c2da_mem[str_15 + 32]) | uint(c2da_mem[str_15 + 33]) << 0x8 | uint(c2da_mem[str_15 + 34]) << 0x10 | uint(c2da_mem[str_15 + 35]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_15 + 36]) | uint(c2da_mem[str_15 + 37]) << 0x8 | uint(c2da_mem[str_15 + 38]) << 0x10 | uint(c2da_mem[str_15 + 39]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_15 + 40]) | uint(c2da_mem[str_15 + 41]) << 0x8 | uint(c2da_mem[str_15 + 42]) << 0x10 | uint(c2da_mem[str_15 + 43]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_15 + 44]) | uint(c2da_mem[str_15 + 45]) << 0x8 | uint(c2da_mem[str_15 + 46]) << 0x10 | uint(c2da_mem[str_15 + 47]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_15 + 48]) | uint(c2da_mem[str_15 + 49]) << 0x8 | uint(c2da_mem[str_15 + 50]) << 0x10 | uint(c2da_mem[str_15 + 51]) << 0x18))
    return
}
[sideeffects]
def private saveg_write_plat_t(var str_16 : int) {
    saveg_write_thinker_t(str_16)
    saveg_write32(int(int64((int(uint(c2da_mem[str_16 + 24]) | uint(c2da_mem[str_16 + 25]) << 0x8 | uint(c2da_mem[str_16 + 26]) << 0x10 | uint(c2da_mem[str_16 + 27]) << 0x18) - sectors) / 128)))
    saveg_write32(int(uint(c2da_mem[str_16 + 32]) | uint(c2da_mem[str_16 + 33]) << 0x8 | uint(c2da_mem[str_16 + 34]) << 0x10 | uint(c2da_mem[str_16 + 35]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_16 + 36]) | uint(c2da_mem[str_16 + 37]) << 0x8 | uint(c2da_mem[str_16 + 38]) << 0x10 | uint(c2da_mem[str_16 + 39]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_16 + 40]) | uint(c2da_mem[str_16 + 41]) << 0x8 | uint(c2da_mem[str_16 + 42]) << 0x10 | uint(c2da_mem[str_16 + 43]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_16 + 44]) | uint(c2da_mem[str_16 + 45]) << 0x8 | uint(c2da_mem[str_16 + 46]) << 0x10 | uint(c2da_mem[str_16 + 47]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_16 + 48]) | uint(c2da_mem[str_16 + 49]) << 0x8 | uint(c2da_mem[str_16 + 50]) << 0x10 | uint(c2da_mem[str_16 + 51]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_16 + 52]) | uint(c2da_mem[str_16 + 53]) << 0x8 | uint(c2da_mem[str_16 + 54]) << 0x10 | uint(c2da_mem[str_16 + 55]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_16 + 56]) | uint(c2da_mem[str_16 + 57]) << 0x8 | uint(c2da_mem[str_16 + 58]) << 0x10 | uint(c2da_mem[str_16 + 59]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_16 + 60]) | uint(c2da_mem[str_16 + 61]) << 0x8 | uint(c2da_mem[str_16 + 62]) << 0x10 | uint(c2da_mem[str_16 + 63]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_16 + 64]) | uint(c2da_mem[str_16 + 65]) << 0x8 | uint(c2da_mem[str_16 + 66]) << 0x10 | uint(c2da_mem[str_16 + 67]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_16 + 68]) | uint(c2da_mem[str_16 + 69]) << 0x8 | uint(c2da_mem[str_16 + 70]) << 0x10 | uint(c2da_mem[str_16 + 71]) << 0x18))
    return
}
[sideeffects]
def private saveg_write_floormove_t(var str_17 : int) {
    saveg_write_thinker_t(str_17)
    saveg_write32(int(uint(c2da_mem[str_17 + 24]) | uint(c2da_mem[str_17 + 25]) << 0x8 | uint(c2da_mem[str_17 + 26]) << 0x10 | uint(c2da_mem[str_17 + 27]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_17 + 28]) | uint(c2da_mem[str_17 + 29]) << 0x8 | uint(c2da_mem[str_17 + 30]) << 0x10 | uint(c2da_mem[str_17 + 31]) << 0x18))
    saveg_write32(int(int64((int(uint(c2da_mem[str_17 + 32]) | uint(c2da_mem[str_17 + 33]) << 0x8 | uint(c2da_mem[str_17 + 34]) << 0x10 | uint(c2da_mem[str_17 + 35]) << 0x18) - sectors) / 128)))
    saveg_write32(int(uint(c2da_mem[str_17 + 40]) | uint(c2da_mem[str_17 + 41]) << 0x8 | uint(c2da_mem[str_17 + 42]) << 0x10 | uint(c2da_mem[str_17 + 43]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_17 + 44]) | uint(c2da_mem[str_17 + 45]) << 0x8 | uint(c2da_mem[str_17 + 46]) << 0x10 | uint(c2da_mem[str_17 + 47]) << 0x18))
    saveg_write16(int16(uint(c2da_mem[str_17 + 48]) | uint(c2da_mem[str_17 + 49]) << 0x8))
    saveg_write32(int(uint(c2da_mem[str_17 + 52]) | uint(c2da_mem[str_17 + 53]) << 0x8 | uint(c2da_mem[str_17 + 54]) << 0x10 | uint(c2da_mem[str_17 + 55]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_17 + 56]) | uint(c2da_mem[str_17 + 57]) << 0x8 | uint(c2da_mem[str_17 + 58]) << 0x10 | uint(c2da_mem[str_17 + 59]) << 0x18))
    return
}
[sideeffects]
def private saveg_write_vldoor_t(var str_18 : int) {
    saveg_write_thinker_t(str_18)
    saveg_write32(int(uint(c2da_mem[str_18 + 24]) | uint(c2da_mem[str_18 + 25]) << 0x8 | uint(c2da_mem[str_18 + 26]) << 0x10 | uint(c2da_mem[str_18 + 27]) << 0x18))
    saveg_write32(int(int64((int(uint(c2da_mem[str_18 + 32]) | uint(c2da_mem[str_18 + 33]) << 0x8 | uint(c2da_mem[str_18 + 34]) << 0x10 | uint(c2da_mem[str_18 + 35]) << 0x18) - sectors) / 128)))
    saveg_write32(int(uint(c2da_mem[str_18 + 40]) | uint(c2da_mem[str_18 + 41]) << 0x8 | uint(c2da_mem[str_18 + 42]) << 0x10 | uint(c2da_mem[str_18 + 43]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_18 + 44]) | uint(c2da_mem[str_18 + 45]) << 0x8 | uint(c2da_mem[str_18 + 46]) << 0x10 | uint(c2da_mem[str_18 + 47]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_18 + 48]) | uint(c2da_mem[str_18 + 49]) << 0x8 | uint(c2da_mem[str_18 + 50]) << 0x10 | uint(c2da_mem[str_18 + 51]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_18 + 52]) | uint(c2da_mem[str_18 + 53]) << 0x8 | uint(c2da_mem[str_18 + 54]) << 0x10 | uint(c2da_mem[str_18 + 55]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_18 + 56]) | uint(c2da_mem[str_18 + 57]) << 0x8 | uint(c2da_mem[str_18 + 58]) << 0x10 | uint(c2da_mem[str_18 + 59]) << 0x18))
    return
}
[sideeffects]
def private saveg_write_ceiling_t(var str_19 : int) {
    saveg_write_thinker_t(str_19)
    saveg_write32(int(uint(c2da_mem[str_19 + 24]) | uint(c2da_mem[str_19 + 25]) << 0x8 | uint(c2da_mem[str_19 + 26]) << 0x10 | uint(c2da_mem[str_19 + 27]) << 0x18))
    saveg_write32(int(int64((int(uint(c2da_mem[str_19 + 32]) | uint(c2da_mem[str_19 + 33]) << 0x8 | uint(c2da_mem[str_19 + 34]) << 0x10 | uint(c2da_mem[str_19 + 35]) << 0x18) - sectors) / 128)))
    saveg_write32(int(uint(c2da_mem[str_19 + 40]) | uint(c2da_mem[str_19 + 41]) << 0x8 | uint(c2da_mem[str_19 + 42]) << 0x10 | uint(c2da_mem[str_19 + 43]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_19 + 44]) | uint(c2da_mem[str_19 + 45]) << 0x8 | uint(c2da_mem[str_19 + 46]) << 0x10 | uint(c2da_mem[str_19 + 47]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_19 + 48]) | uint(c2da_mem[str_19 + 49]) << 0x8 | uint(c2da_mem[str_19 + 50]) << 0x10 | uint(c2da_mem[str_19 + 51]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_19 + 52]) | uint(c2da_mem[str_19 + 53]) << 0x8 | uint(c2da_mem[str_19 + 54]) << 0x10 | uint(c2da_mem[str_19 + 55]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_19 + 56]) | uint(c2da_mem[str_19 + 57]) << 0x8 | uint(c2da_mem[str_19 + 58]) << 0x10 | uint(c2da_mem[str_19 + 59]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_19 + 60]) | uint(c2da_mem[str_19 + 61]) << 0x8 | uint(c2da_mem[str_19 + 62]) << 0x10 | uint(c2da_mem[str_19 + 63]) << 0x18))
    saveg_write32(int(uint(c2da_mem[str_19 + 64]) | uint(c2da_mem[str_19 + 65]) << 0x8 | uint(c2da_mem[str_19 + 66]) << 0x10 | uint(c2da_mem[str_19 + 67]) << 0x18))
    return
}
[export, sideeffects]
def P_UnArchiveSpecials() {
    var c2da_fresh217 : int
    var tclass_0 : uint8
    var ceiling : int
    var door : int
    var floor : int
    var plat : int
    var flash : int
    var strobe : int
    var glow : int
    while (true) {
        tclass_0 = saveg_read8()
        c2da_fresh217 = int(tclass_0)
        if (c2da_fresh217 == 7) {
            return
        } elif (c2da_fresh217 == 0) {
            saveg_read_pad()
            ceiling = Z_Malloc(72, 5, 0)
            saveg_read_ceiling_t(ceiling)
            let c2da_fresh218 : int = int(uint(c2da_mem[ceiling + 32]) | uint(c2da_mem[ceiling + 33]) << 0x8 | uint(c2da_mem[ceiling + 34]) << 0x10 | uint(c2da_mem[ceiling + 35]) << 0x18) + 104
            let c2da_fresh219 : uint = uint(ceiling)
            c2da_mem[c2da_fresh218] = uint8(c2da_fresh219)
            c2da_mem[c2da_fresh218 + 1] = uint8(c2da_fresh219 >> 0x8)
            c2da_mem[c2da_fresh218 + 2] = uint8(c2da_fresh219 >> 0x10)
            c2da_mem[c2da_fresh218 + 3] = uint8(c2da_fresh219 >> 0x18)
            c2da_mem[c2da_fresh218 + 4] = 0u8
            c2da_mem[c2da_fresh218 + 5] = 0u8
            c2da_mem[c2da_fresh218 + 6] = 0u8
            c2da_mem[c2da_fresh218 + 7] = 0u8
            if (int(uint(c2da_mem[ceiling + 16]) | uint(c2da_mem[ceiling + 17]) << 0x8 | uint(c2da_mem[ceiling + 18]) << 0x10 | uint(c2da_mem[ceiling + 19]) << 0x18) != default<actionf_p1>) {
                let c2da_fresh220 : uint = 123u
                c2da_mem[ceiling + 16] = uint8(c2da_fresh220)
                c2da_mem[ceiling + 17] = uint8(c2da_fresh220 >> 0x8)
                c2da_mem[ceiling + 18] = uint8(c2da_fresh220 >> 0x10)
                c2da_mem[ceiling + 19] = uint8(c2da_fresh220 >> 0x18)
                c2da_mem[ceiling + 20] = 0u8
                c2da_mem[ceiling + 21] = 0u8
                c2da_mem[ceiling + 22] = 0u8
                c2da_mem[ceiling + 23] = 0u8
            }
            P_AddThinker(ceiling)
            P_AddActiveCeiling(ceiling)
        } elif (c2da_fresh217 == 1) {
            saveg_read_pad()
            door = Z_Malloc(64, 5, 0)
            saveg_read_vldoor_t(door)
            let c2da_fresh221 : int = int(uint(c2da_mem[door + 32]) | uint(c2da_mem[door + 33]) << 0x8 | uint(c2da_mem[door + 34]) << 0x10 | uint(c2da_mem[door + 35]) << 0x18) + 104
            let c2da_fresh222 : uint = uint(door)
            c2da_mem[c2da_fresh221] = uint8(c2da_fresh222)
            c2da_mem[c2da_fresh221 + 1] = uint8(c2da_fresh222 >> 0x8)
            c2da_mem[c2da_fresh221 + 2] = uint8(c2da_fresh222 >> 0x10)
            c2da_mem[c2da_fresh221 + 3] = uint8(c2da_fresh222 >> 0x18)
            c2da_mem[c2da_fresh221 + 4] = 0u8
            c2da_mem[c2da_fresh221 + 5] = 0u8
            c2da_mem[c2da_fresh221 + 6] = 0u8
            c2da_mem[c2da_fresh221 + 7] = 0u8
            let c2da_fresh223 : uint = 124u
            c2da_mem[door + 16] = uint8(c2da_fresh223)
            c2da_mem[door + 17] = uint8(c2da_fresh223 >> 0x8)
            c2da_mem[door + 18] = uint8(c2da_fresh223 >> 0x10)
            c2da_mem[door + 19] = uint8(c2da_fresh223 >> 0x18)
            c2da_mem[door + 20] = 0u8
            c2da_mem[door + 21] = 0u8
            c2da_mem[door + 22] = 0u8
            c2da_mem[door + 23] = 0u8
            P_AddThinker(door)
        } elif (c2da_fresh217 == 2) {
            saveg_read_pad()
            floor = Z_Malloc(64, 5, 0)
            saveg_read_floormove_t(floor)
            let c2da_fresh224 : int = int(uint(c2da_mem[floor + 32]) | uint(c2da_mem[floor + 33]) << 0x8 | uint(c2da_mem[floor + 34]) << 0x10 | uint(c2da_mem[floor + 35]) << 0x18) + 104
            let c2da_fresh225 : uint = uint(floor)
            c2da_mem[c2da_fresh224] = uint8(c2da_fresh225)
            c2da_mem[c2da_fresh224 + 1] = uint8(c2da_fresh225 >> 0x8)
            c2da_mem[c2da_fresh224 + 2] = uint8(c2da_fresh225 >> 0x10)
            c2da_mem[c2da_fresh224 + 3] = uint8(c2da_fresh225 >> 0x18)
            c2da_mem[c2da_fresh224 + 4] = 0u8
            c2da_mem[c2da_fresh224 + 5] = 0u8
            c2da_mem[c2da_fresh224 + 6] = 0u8
            c2da_mem[c2da_fresh224 + 7] = 0u8
            let c2da_fresh226 : uint = 128u
            c2da_mem[floor + 16] = uint8(c2da_fresh226)
            c2da_mem[floor + 17] = uint8(c2da_fresh226 >> 0x8)
            c2da_mem[floor + 18] = uint8(c2da_fresh226 >> 0x10)
            c2da_mem[floor + 19] = uint8(c2da_fresh226 >> 0x18)
            c2da_mem[floor + 20] = 0u8
            c2da_mem[floor + 21] = 0u8
            c2da_mem[floor + 22] = 0u8
            c2da_mem[floor + 23] = 0u8
            P_AddThinker(floor)
        } elif (c2da_fresh217 == 3) {
            saveg_read_pad()
            plat = Z_Malloc(72, 5, 0)
            saveg_read_plat_t(plat)
            let c2da_fresh227 : int = int(uint(c2da_mem[plat + 24]) | uint(c2da_mem[plat + 25]) << 0x8 | uint(c2da_mem[plat + 26]) << 0x10 | uint(c2da_mem[plat + 27]) << 0x18) + 104
            let c2da_fresh228 : uint = uint(plat)
            c2da_mem[c2da_fresh227] = uint8(c2da_fresh228)
            c2da_mem[c2da_fresh227 + 1] = uint8(c2da_fresh228 >> 0x8)
            c2da_mem[c2da_fresh227 + 2] = uint8(c2da_fresh228 >> 0x10)
            c2da_mem[c2da_fresh227 + 3] = uint8(c2da_fresh228 >> 0x18)
            c2da_mem[c2da_fresh227 + 4] = 0u8
            c2da_mem[c2da_fresh227 + 5] = 0u8
            c2da_mem[c2da_fresh227 + 6] = 0u8
            c2da_mem[c2da_fresh227 + 7] = 0u8
            if (int(uint(c2da_mem[plat + 16]) | uint(c2da_mem[plat + 17]) << 0x8 | uint(c2da_mem[plat + 18]) << 0x10 | uint(c2da_mem[plat + 19]) << 0x18) != default<actionf_p1>) {
                let c2da_fresh229 : uint = 125u
                c2da_mem[plat + 16] = uint8(c2da_fresh229)
                c2da_mem[plat + 17] = uint8(c2da_fresh229 >> 0x8)
                c2da_mem[plat + 18] = uint8(c2da_fresh229 >> 0x10)
                c2da_mem[plat + 19] = uint8(c2da_fresh229 >> 0x18)
                c2da_mem[plat + 20] = 0u8
                c2da_mem[plat + 21] = 0u8
                c2da_mem[plat + 22] = 0u8
                c2da_mem[plat + 23] = 0u8
            }
            P_AddThinker(plat)
            P_AddActivePlat(plat)
        } elif (c2da_fresh217 == 4) {
            saveg_read_pad()
            flash = Z_Malloc(56, 5, 0)
            saveg_read_lightflash_t(flash)
            let c2da_fresh230 : uint = 130u
            c2da_mem[flash + 16] = uint8(c2da_fresh230)
            c2da_mem[flash + 17] = uint8(c2da_fresh230 >> 0x8)
            c2da_mem[flash + 18] = uint8(c2da_fresh230 >> 0x10)
            c2da_mem[flash + 19] = uint8(c2da_fresh230 >> 0x18)
            c2da_mem[flash + 20] = 0u8
            c2da_mem[flash + 21] = 0u8
            c2da_mem[flash + 22] = 0u8
            c2da_mem[flash + 23] = 0u8
            P_AddThinker(flash)
        } elif (c2da_fresh217 == 5) {
            saveg_read_pad()
            strobe = Z_Malloc(56, 5, 0)
            saveg_read_strobe_t(strobe)
            let c2da_fresh231 : uint = 131u
            c2da_mem[strobe + 16] = uint8(c2da_fresh231)
            c2da_mem[strobe + 17] = uint8(c2da_fresh231 >> 0x8)
            c2da_mem[strobe + 18] = uint8(c2da_fresh231 >> 0x10)
            c2da_mem[strobe + 19] = uint8(c2da_fresh231 >> 0x18)
            c2da_mem[strobe + 20] = 0u8
            c2da_mem[strobe + 21] = 0u8
            c2da_mem[strobe + 22] = 0u8
            c2da_mem[strobe + 23] = 0u8
            P_AddThinker(strobe)
        } elif (c2da_fresh217 == 6) {
            saveg_read_pad()
            glow = Z_Malloc(48, 5, 0)
            saveg_read_glow_t(glow)
            let c2da_fresh232 : uint = 132u
            c2da_mem[glow + 16] = uint8(c2da_fresh232)
            c2da_mem[glow + 17] = uint8(c2da_fresh232 >> 0x8)
            c2da_mem[glow + 18] = uint8(c2da_fresh232 >> 0x10)
            c2da_mem[glow + 19] = uint8(c2da_fresh232 >> 0x18)
            c2da_mem[glow + 20] = 0u8
            c2da_mem[glow + 21] = 0u8
            c2da_mem[glow + 22] = 0u8
            c2da_mem[glow + 23] = 0u8
            P_AddThinker(glow)
        } else {
            I_Error(360847, [C2daVaArg(tag = 1, i64 = int64(tclass_0), f64 = 0.0lf, raw = 0x0)])
        }
    }
}
[sideeffects]
def private saveg_read_glow_t(var str_20 : int) {
    var sector : int
    saveg_read_thinker_t(str_20)
    sector = saveg_read32()
    let c2da_fresh233 : int = sectors + sector * 128
    let c2da_fresh234 : uint = uint(c2da_fresh233)
    c2da_mem[str_20 + 24] = uint8(c2da_fresh234)
    c2da_mem[str_20 + 25] = uint8(c2da_fresh234 >> 0x8)
    c2da_mem[str_20 + 26] = uint8(c2da_fresh234 >> 0x10)
    c2da_mem[str_20 + 27] = uint8(c2da_fresh234 >> 0x18)
    c2da_mem[str_20 + 28] = 0u8
    c2da_mem[str_20 + 29] = 0u8
    c2da_mem[str_20 + 30] = 0u8
    c2da_mem[str_20 + 31] = 0u8
    let c2da_fresh235 : int = saveg_read32()
    let c2da_fresh236 : uint = uint(c2da_fresh235)
    c2da_mem[str_20 + 32] = uint8(c2da_fresh236)
    c2da_mem[str_20 + 33] = uint8(c2da_fresh236 >> 0x8)
    c2da_mem[str_20 + 34] = uint8(c2da_fresh236 >> 0x10)
    c2da_mem[str_20 + 35] = uint8(c2da_fresh236 >> 0x18)
    let c2da_fresh237 : int = saveg_read32()
    let c2da_fresh238 : uint = uint(c2da_fresh237)
    c2da_mem[str_20 + 36] = uint8(c2da_fresh238)
    c2da_mem[str_20 + 37] = uint8(c2da_fresh238 >> 0x8)
    c2da_mem[str_20 + 38] = uint8(c2da_fresh238 >> 0x10)
    c2da_mem[str_20 + 39] = uint8(c2da_fresh238 >> 0x18)
    let c2da_fresh239 : int = saveg_read32()
    let c2da_fresh240 : uint = uint(c2da_fresh239)
    c2da_mem[str_20 + 40] = uint8(c2da_fresh240)
    c2da_mem[str_20 + 41] = uint8(c2da_fresh240 >> 0x8)
    c2da_mem[str_20 + 42] = uint8(c2da_fresh240 >> 0x10)
    c2da_mem[str_20 + 43] = uint8(c2da_fresh240 >> 0x18)
    return
}
[sideeffects]
def private saveg_read_strobe_t(var str_21 : int) {
    var sector_0 : int
    saveg_read_thinker_t(str_21)
    sector_0 = saveg_read32()
    let c2da_fresh241 : int = sectors + sector_0 * 128
    let c2da_fresh242 : uint = uint(c2da_fresh241)
    c2da_mem[str_21 + 24] = uint8(c2da_fresh242)
    c2da_mem[str_21 + 25] = uint8(c2da_fresh242 >> 0x8)
    c2da_mem[str_21 + 26] = uint8(c2da_fresh242 >> 0x10)
    c2da_mem[str_21 + 27] = uint8(c2da_fresh242 >> 0x18)
    c2da_mem[str_21 + 28] = 0u8
    c2da_mem[str_21 + 29] = 0u8
    c2da_mem[str_21 + 30] = 0u8
    c2da_mem[str_21 + 31] = 0u8
    let c2da_fresh243 : int = saveg_read32()
    let c2da_fresh244 : uint = uint(c2da_fresh243)
    c2da_mem[str_21 + 32] = uint8(c2da_fresh244)
    c2da_mem[str_21 + 33] = uint8(c2da_fresh244 >> 0x8)
    c2da_mem[str_21 + 34] = uint8(c2da_fresh244 >> 0x10)
    c2da_mem[str_21 + 35] = uint8(c2da_fresh244 >> 0x18)
    let c2da_fresh245 : int = saveg_read32()
    let c2da_fresh246 : uint = uint(c2da_fresh245)
    c2da_mem[str_21 + 36] = uint8(c2da_fresh246)
    c2da_mem[str_21 + 37] = uint8(c2da_fresh246 >> 0x8)
    c2da_mem[str_21 + 38] = uint8(c2da_fresh246 >> 0x10)
    c2da_mem[str_21 + 39] = uint8(c2da_fresh246 >> 0x18)
    let c2da_fresh247 : int = saveg_read32()
    let c2da_fresh248 : uint = uint(c2da_fresh247)
    c2da_mem[str_21 + 40] = uint8(c2da_fresh248)
    c2da_mem[str_21 + 41] = uint8(c2da_fresh248 >> 0x8)
    c2da_mem[str_21 + 42] = uint8(c2da_fresh248 >> 0x10)
    c2da_mem[str_21 + 43] = uint8(c2da_fresh248 >> 0x18)
    let c2da_fresh249 : int = saveg_read32()
    let c2da_fresh250 : uint = uint(c2da_fresh249)
    c2da_mem[str_21 + 44] = uint8(c2da_fresh250)
    c2da_mem[str_21 + 45] = uint8(c2da_fresh250 >> 0x8)
    c2da_mem[str_21 + 46] = uint8(c2da_fresh250 >> 0x10)
    c2da_mem[str_21 + 47] = uint8(c2da_fresh250 >> 0x18)
    let c2da_fresh251 : int = saveg_read32()
    let c2da_fresh252 : uint = uint(c2da_fresh251)
    c2da_mem[str_21 + 48] = uint8(c2da_fresh252)
    c2da_mem[str_21 + 49] = uint8(c2da_fresh252 >> 0x8)
    c2da_mem[str_21 + 50] = uint8(c2da_fresh252 >> 0x10)
    c2da_mem[str_21 + 51] = uint8(c2da_fresh252 >> 0x18)
    return
}
[sideeffects]
def private saveg_read_lightflash_t(var str_22 : int) {
    var sector_1 : int
    saveg_read_thinker_t(str_22)
    sector_1 = saveg_read32()
    let c2da_fresh253 : int = sectors + sector_1 * 128
    let c2da_fresh254 : uint = uint(c2da_fresh253)
    c2da_mem[str_22 + 24] = uint8(c2da_fresh254)
    c2da_mem[str_22 + 25] = uint8(c2da_fresh254 >> 0x8)
    c2da_mem[str_22 + 26] = uint8(c2da_fresh254 >> 0x10)
    c2da_mem[str_22 + 27] = uint8(c2da_fresh254 >> 0x18)
    c2da_mem[str_22 + 28] = 0u8
    c2da_mem[str_22 + 29] = 0u8
    c2da_mem[str_22 + 30] = 0u8
    c2da_mem[str_22 + 31] = 0u8
    let c2da_fresh255 : int = saveg_read32()
    let c2da_fresh256 : uint = uint(c2da_fresh255)
    c2da_mem[str_22 + 32] = uint8(c2da_fresh256)
    c2da_mem[str_22 + 33] = uint8(c2da_fresh256 >> 0x8)
    c2da_mem[str_22 + 34] = uint8(c2da_fresh256 >> 0x10)
    c2da_mem[str_22 + 35] = uint8(c2da_fresh256 >> 0x18)
    let c2da_fresh257 : int = saveg_read32()
    let c2da_fresh258 : uint = uint(c2da_fresh257)
    c2da_mem[str_22 + 36] = uint8(c2da_fresh258)
    c2da_mem[str_22 + 37] = uint8(c2da_fresh258 >> 0x8)
    c2da_mem[str_22 + 38] = uint8(c2da_fresh258 >> 0x10)
    c2da_mem[str_22 + 39] = uint8(c2da_fresh258 >> 0x18)
    let c2da_fresh259 : int = saveg_read32()
    let c2da_fresh260 : uint = uint(c2da_fresh259)
    c2da_mem[str_22 + 40] = uint8(c2da_fresh260)
    c2da_mem[str_22 + 41] = uint8(c2da_fresh260 >> 0x8)
    c2da_mem[str_22 + 42] = uint8(c2da_fresh260 >> 0x10)
    c2da_mem[str_22 + 43] = uint8(c2da_fresh260 >> 0x18)
    let c2da_fresh261 : int = saveg_read32()
    let c2da_fresh262 : uint = uint(c2da_fresh261)
    c2da_mem[str_22 + 44] = uint8(c2da_fresh262)
    c2da_mem[str_22 + 45] = uint8(c2da_fresh262 >> 0x8)
    c2da_mem[str_22 + 46] = uint8(c2da_fresh262 >> 0x10)
    c2da_mem[str_22 + 47] = uint8(c2da_fresh262 >> 0x18)
    let c2da_fresh263 : int = saveg_read32()
    let c2da_fresh264 : uint = uint(c2da_fresh263)
    c2da_mem[str_22 + 48] = uint8(c2da_fresh264)
    c2da_mem[str_22 + 49] = uint8(c2da_fresh264 >> 0x8)
    c2da_mem[str_22 + 50] = uint8(c2da_fresh264 >> 0x10)
    c2da_mem[str_22 + 51] = uint8(c2da_fresh264 >> 0x18)
    return
}
[sideeffects]
def private saveg_read_plat_t(var str_23 : int) {
    var sector_2 : int
    saveg_read_thinker_t(str_23)
    sector_2 = saveg_read32()
    let c2da_fresh265 : int = sectors + sector_2 * 128
    let c2da_fresh266 : uint = uint(c2da_fresh265)
    c2da_mem[str_23 + 24] = uint8(c2da_fresh266)
    c2da_mem[str_23 + 25] = uint8(c2da_fresh266 >> 0x8)
    c2da_mem[str_23 + 26] = uint8(c2da_fresh266 >> 0x10)
    c2da_mem[str_23 + 27] = uint8(c2da_fresh266 >> 0x18)
    c2da_mem[str_23 + 28] = 0u8
    c2da_mem[str_23 + 29] = 0u8
    c2da_mem[str_23 + 30] = 0u8
    c2da_mem[str_23 + 31] = 0u8
    let c2da_fresh267 : int = saveg_read32()
    let c2da_fresh268 : uint = uint(c2da_fresh267)
    c2da_mem[str_23 + 32] = uint8(c2da_fresh268)
    c2da_mem[str_23 + 33] = uint8(c2da_fresh268 >> 0x8)
    c2da_mem[str_23 + 34] = uint8(c2da_fresh268 >> 0x10)
    c2da_mem[str_23 + 35] = uint8(c2da_fresh268 >> 0x18)
    let c2da_fresh269 : int = saveg_read32()
    let c2da_fresh270 : uint = uint(c2da_fresh269)
    c2da_mem[str_23 + 36] = uint8(c2da_fresh270)
    c2da_mem[str_23 + 37] = uint8(c2da_fresh270 >> 0x8)
    c2da_mem[str_23 + 38] = uint8(c2da_fresh270 >> 0x10)
    c2da_mem[str_23 + 39] = uint8(c2da_fresh270 >> 0x18)
    let c2da_fresh271 : int = saveg_read32()
    let c2da_fresh272 : uint = uint(c2da_fresh271)
    c2da_mem[str_23 + 40] = uint8(c2da_fresh272)
    c2da_mem[str_23 + 41] = uint8(c2da_fresh272 >> 0x8)
    c2da_mem[str_23 + 42] = uint8(c2da_fresh272 >> 0x10)
    c2da_mem[str_23 + 43] = uint8(c2da_fresh272 >> 0x18)
    let c2da_fresh273 : int = saveg_read32()
    let c2da_fresh274 : uint = uint(c2da_fresh273)
    c2da_mem[str_23 + 44] = uint8(c2da_fresh274)
    c2da_mem[str_23 + 45] = uint8(c2da_fresh274 >> 0x8)
    c2da_mem[str_23 + 46] = uint8(c2da_fresh274 >> 0x10)
    c2da_mem[str_23 + 47] = uint8(c2da_fresh274 >> 0x18)
    let c2da_fresh275 : int = saveg_read32()
    let c2da_fresh276 : uint = uint(c2da_fresh275)
    c2da_mem[str_23 + 48] = uint8(c2da_fresh276)
    c2da_mem[str_23 + 49] = uint8(c2da_fresh276 >> 0x8)
    c2da_mem[str_23 + 50] = uint8(c2da_fresh276 >> 0x10)
    c2da_mem[str_23 + 51] = uint8(c2da_fresh276 >> 0x18)
    let c2da_fresh277 : uint = uint(saveg_read32())
    let c2da_fresh278 : uint = c2da_fresh277
    c2da_mem[str_23 + 52] = uint8(c2da_fresh278)
    c2da_mem[str_23 + 53] = uint8(c2da_fresh278 >> 0x8)
    c2da_mem[str_23 + 54] = uint8(c2da_fresh278 >> 0x10)
    c2da_mem[str_23 + 55] = uint8(c2da_fresh278 >> 0x18)
    let c2da_fresh279 : uint = uint(saveg_read32())
    let c2da_fresh280 : uint = c2da_fresh279
    c2da_mem[str_23 + 56] = uint8(c2da_fresh280)
    c2da_mem[str_23 + 57] = uint8(c2da_fresh280 >> 0x8)
    c2da_mem[str_23 + 58] = uint8(c2da_fresh280 >> 0x10)
    c2da_mem[str_23 + 59] = uint8(c2da_fresh280 >> 0x18)
    let c2da_fresh281 : uint = uint(saveg_read32())
    let c2da_fresh282 : uint = c2da_fresh281
    c2da_mem[str_23 + 60] = uint8(c2da_fresh282)
    c2da_mem[str_23 + 61] = uint8(c2da_fresh282 >> 0x8)
    c2da_mem[str_23 + 62] = uint8(c2da_fresh282 >> 0x10)
    c2da_mem[str_23 + 63] = uint8(c2da_fresh282 >> 0x18)
    let c2da_fresh283 : int = saveg_read32()
    let c2da_fresh284 : uint = uint(c2da_fresh283)
    c2da_mem[str_23 + 64] = uint8(c2da_fresh284)
    c2da_mem[str_23 + 65] = uint8(c2da_fresh284 >> 0x8)
    c2da_mem[str_23 + 66] = uint8(c2da_fresh284 >> 0x10)
    c2da_mem[str_23 + 67] = uint8(c2da_fresh284 >> 0x18)
    let c2da_fresh285 : uint = uint(saveg_read32())
    let c2da_fresh286 : uint = c2da_fresh285
    c2da_mem[str_23 + 68] = uint8(c2da_fresh286)
    c2da_mem[str_23 + 69] = uint8(c2da_fresh286 >> 0x8)
    c2da_mem[str_23 + 70] = uint8(c2da_fresh286 >> 0x10)
    c2da_mem[str_23 + 71] = uint8(c2da_fresh286 >> 0x18)
    return
}
[sideeffects]
def private saveg_read_floormove_t(var str_24 : int) {
    var sector_3 : int
    saveg_read_thinker_t(str_24)
    let c2da_fresh287 : uint = uint(saveg_read32())
    let c2da_fresh288 : uint = c2da_fresh287
    c2da_mem[str_24 + 24] = uint8(c2da_fresh288)
    c2da_mem[str_24 + 25] = uint8(c2da_fresh288 >> 0x8)
    c2da_mem[str_24 + 26] = uint8(c2da_fresh288 >> 0x10)
    c2da_mem[str_24 + 27] = uint8(c2da_fresh288 >> 0x18)
    let c2da_fresh289 : uint = uint(saveg_read32())
    let c2da_fresh290 : uint = c2da_fresh289
    c2da_mem[str_24 + 28] = uint8(c2da_fresh290)
    c2da_mem[str_24 + 29] = uint8(c2da_fresh290 >> 0x8)
    c2da_mem[str_24 + 30] = uint8(c2da_fresh290 >> 0x10)
    c2da_mem[str_24 + 31] = uint8(c2da_fresh290 >> 0x18)
    sector_3 = saveg_read32()
    let c2da_fresh291 : int = sectors + sector_3 * 128
    let c2da_fresh292 : uint = uint(c2da_fresh291)
    c2da_mem[str_24 + 32] = uint8(c2da_fresh292)
    c2da_mem[str_24 + 33] = uint8(c2da_fresh292 >> 0x8)
    c2da_mem[str_24 + 34] = uint8(c2da_fresh292 >> 0x10)
    c2da_mem[str_24 + 35] = uint8(c2da_fresh292 >> 0x18)
    c2da_mem[str_24 + 36] = 0u8
    c2da_mem[str_24 + 37] = 0u8
    c2da_mem[str_24 + 38] = 0u8
    c2da_mem[str_24 + 39] = 0u8
    let c2da_fresh293 : int = saveg_read32()
    let c2da_fresh294 : uint = uint(c2da_fresh293)
    c2da_mem[str_24 + 40] = uint8(c2da_fresh294)
    c2da_mem[str_24 + 41] = uint8(c2da_fresh294 >> 0x8)
    c2da_mem[str_24 + 42] = uint8(c2da_fresh294 >> 0x10)
    c2da_mem[str_24 + 43] = uint8(c2da_fresh294 >> 0x18)
    let c2da_fresh295 : int = saveg_read32()
    let c2da_fresh296 : uint = uint(c2da_fresh295)
    c2da_mem[str_24 + 44] = uint8(c2da_fresh296)
    c2da_mem[str_24 + 45] = uint8(c2da_fresh296 >> 0x8)
    c2da_mem[str_24 + 46] = uint8(c2da_fresh296 >> 0x10)
    c2da_mem[str_24 + 47] = uint8(c2da_fresh296 >> 0x18)
    let c2da_fresh297 : int16 = saveg_read16()
    let c2da_fresh298 : uint = uint(c2da_fresh297)
    c2da_mem[str_24 + 48] = uint8(c2da_fresh298)
    c2da_mem[str_24 + 49] = uint8(c2da_fresh298 >> 0x8)
    let c2da_fresh299 : int = saveg_read32()
    let c2da_fresh300 : uint = uint(c2da_fresh299)
    c2da_mem[str_24 + 52] = uint8(c2da_fresh300)
    c2da_mem[str_24 + 53] = uint8(c2da_fresh300 >> 0x8)
    c2da_mem[str_24 + 54] = uint8(c2da_fresh300 >> 0x10)
    c2da_mem[str_24 + 55] = uint8(c2da_fresh300 >> 0x18)
    let c2da_fresh301 : int = saveg_read32()
    let c2da_fresh302 : uint = uint(c2da_fresh301)
    c2da_mem[str_24 + 56] = uint8(c2da_fresh302)
    c2da_mem[str_24 + 57] = uint8(c2da_fresh302 >> 0x8)
    c2da_mem[str_24 + 58] = uint8(c2da_fresh302 >> 0x10)
    c2da_mem[str_24 + 59] = uint8(c2da_fresh302 >> 0x18)
    return
}
[sideeffects]
def private saveg_read_vldoor_t(var str_25 : int) {
    var sector_4 : int
    saveg_read_thinker_t(str_25)
    let c2da_fresh303 : uint = uint(saveg_read32())
    let c2da_fresh304 : uint = c2da_fresh303
    c2da_mem[str_25 + 24] = uint8(c2da_fresh304)
    c2da_mem[str_25 + 25] = uint8(c2da_fresh304 >> 0x8)
    c2da_mem[str_25 + 26] = uint8(c2da_fresh304 >> 0x10)
    c2da_mem[str_25 + 27] = uint8(c2da_fresh304 >> 0x18)
    sector_4 = saveg_read32()
    let c2da_fresh305 : int = sectors + sector_4 * 128
    let c2da_fresh306 : uint = uint(c2da_fresh305)
    c2da_mem[str_25 + 32] = uint8(c2da_fresh306)
    c2da_mem[str_25 + 33] = uint8(c2da_fresh306 >> 0x8)
    c2da_mem[str_25 + 34] = uint8(c2da_fresh306 >> 0x10)
    c2da_mem[str_25 + 35] = uint8(c2da_fresh306 >> 0x18)
    c2da_mem[str_25 + 36] = 0u8
    c2da_mem[str_25 + 37] = 0u8
    c2da_mem[str_25 + 38] = 0u8
    c2da_mem[str_25 + 39] = 0u8
    let c2da_fresh307 : int = saveg_read32()
    let c2da_fresh308 : uint = uint(c2da_fresh307)
    c2da_mem[str_25 + 40] = uint8(c2da_fresh308)
    c2da_mem[str_25 + 41] = uint8(c2da_fresh308 >> 0x8)
    c2da_mem[str_25 + 42] = uint8(c2da_fresh308 >> 0x10)
    c2da_mem[str_25 + 43] = uint8(c2da_fresh308 >> 0x18)
    let c2da_fresh309 : int = saveg_read32()
    let c2da_fresh310 : uint = uint(c2da_fresh309)
    c2da_mem[str_25 + 44] = uint8(c2da_fresh310)
    c2da_mem[str_25 + 45] = uint8(c2da_fresh310 >> 0x8)
    c2da_mem[str_25 + 46] = uint8(c2da_fresh310 >> 0x10)
    c2da_mem[str_25 + 47] = uint8(c2da_fresh310 >> 0x18)
    let c2da_fresh311 : int = saveg_read32()
    let c2da_fresh312 : uint = uint(c2da_fresh311)
    c2da_mem[str_25 + 48] = uint8(c2da_fresh312)
    c2da_mem[str_25 + 49] = uint8(c2da_fresh312 >> 0x8)
    c2da_mem[str_25 + 50] = uint8(c2da_fresh312 >> 0x10)
    c2da_mem[str_25 + 51] = uint8(c2da_fresh312 >> 0x18)
    let c2da_fresh313 : int = saveg_read32()
    let c2da_fresh314 : uint = uint(c2da_fresh313)
    c2da_mem[str_25 + 52] = uint8(c2da_fresh314)
    c2da_mem[str_25 + 53] = uint8(c2da_fresh314 >> 0x8)
    c2da_mem[str_25 + 54] = uint8(c2da_fresh314 >> 0x10)
    c2da_mem[str_25 + 55] = uint8(c2da_fresh314 >> 0x18)
    let c2da_fresh315 : int = saveg_read32()
    let c2da_fresh316 : uint = uint(c2da_fresh315)
    c2da_mem[str_25 + 56] = uint8(c2da_fresh316)
    c2da_mem[str_25 + 57] = uint8(c2da_fresh316 >> 0x8)
    c2da_mem[str_25 + 58] = uint8(c2da_fresh316 >> 0x10)
    c2da_mem[str_25 + 59] = uint8(c2da_fresh316 >> 0x18)
    return
}
[sideeffects]
def private saveg_read_ceiling_t(var str_26 : int) {
    var sector_5 : int
    saveg_read_thinker_t(str_26)
    let c2da_fresh317 : uint = uint(saveg_read32())
    let c2da_fresh318 : uint = c2da_fresh317
    c2da_mem[str_26 + 24] = uint8(c2da_fresh318)
    c2da_mem[str_26 + 25] = uint8(c2da_fresh318 >> 0x8)
    c2da_mem[str_26 + 26] = uint8(c2da_fresh318 >> 0x10)
    c2da_mem[str_26 + 27] = uint8(c2da_fresh318 >> 0x18)
    sector_5 = saveg_read32()
    let c2da_fresh319 : int = sectors + sector_5 * 128
    let c2da_fresh320 : uint = uint(c2da_fresh319)
    c2da_mem[str_26 + 32] = uint8(c2da_fresh320)
    c2da_mem[str_26 + 33] = uint8(c2da_fresh320 >> 0x8)
    c2da_mem[str_26 + 34] = uint8(c2da_fresh320 >> 0x10)
    c2da_mem[str_26 + 35] = uint8(c2da_fresh320 >> 0x18)
    c2da_mem[str_26 + 36] = 0u8
    c2da_mem[str_26 + 37] = 0u8
    c2da_mem[str_26 + 38] = 0u8
    c2da_mem[str_26 + 39] = 0u8
    let c2da_fresh321 : int = saveg_read32()
    let c2da_fresh322 : uint = uint(c2da_fresh321)
    c2da_mem[str_26 + 40] = uint8(c2da_fresh322)
    c2da_mem[str_26 + 41] = uint8(c2da_fresh322 >> 0x8)
    c2da_mem[str_26 + 42] = uint8(c2da_fresh322 >> 0x10)
    c2da_mem[str_26 + 43] = uint8(c2da_fresh322 >> 0x18)
    let c2da_fresh323 : int = saveg_read32()
    let c2da_fresh324 : uint = uint(c2da_fresh323)
    c2da_mem[str_26 + 44] = uint8(c2da_fresh324)
    c2da_mem[str_26 + 45] = uint8(c2da_fresh324 >> 0x8)
    c2da_mem[str_26 + 46] = uint8(c2da_fresh324 >> 0x10)
    c2da_mem[str_26 + 47] = uint8(c2da_fresh324 >> 0x18)
    let c2da_fresh325 : int = saveg_read32()
    let c2da_fresh326 : uint = uint(c2da_fresh325)
    c2da_mem[str_26 + 48] = uint8(c2da_fresh326)
    c2da_mem[str_26 + 49] = uint8(c2da_fresh326 >> 0x8)
    c2da_mem[str_26 + 50] = uint8(c2da_fresh326 >> 0x10)
    c2da_mem[str_26 + 51] = uint8(c2da_fresh326 >> 0x18)
    let c2da_fresh327 : uint = uint(saveg_read32())
    let c2da_fresh328 : uint = c2da_fresh327
    c2da_mem[str_26 + 52] = uint8(c2da_fresh328)
    c2da_mem[str_26 + 53] = uint8(c2da_fresh328 >> 0x8)
    c2da_mem[str_26 + 54] = uint8(c2da_fresh328 >> 0x10)
    c2da_mem[str_26 + 55] = uint8(c2da_fresh328 >> 0x18)
    let c2da_fresh329 : int = saveg_read32()
    let c2da_fresh330 : uint = uint(c2da_fresh329)
    c2da_mem[str_26 + 56] = uint8(c2da_fresh330)
    c2da_mem[str_26 + 57] = uint8(c2da_fresh330 >> 0x8)
    c2da_mem[str_26 + 58] = uint8(c2da_fresh330 >> 0x10)
    c2da_mem[str_26 + 59] = uint8(c2da_fresh330 >> 0x18)
    let c2da_fresh331 : int = saveg_read32()
    let c2da_fresh332 : uint = uint(c2da_fresh331)
    c2da_mem[str_26 + 60] = uint8(c2da_fresh332)
    c2da_mem[str_26 + 61] = uint8(c2da_fresh332 >> 0x8)
    c2da_mem[str_26 + 62] = uint8(c2da_fresh332 >> 0x10)
    c2da_mem[str_26 + 63] = uint8(c2da_fresh332 >> 0x18)
    let c2da_fresh333 : int = saveg_read32()
    let c2da_fresh334 : uint = uint(c2da_fresh333)
    c2da_mem[str_26 + 64] = uint8(c2da_fresh334)
    c2da_mem[str_26 + 65] = uint8(c2da_fresh334 >> 0x8)
    c2da_mem[str_26 + 66] = uint8(c2da_fresh334 >> 0x10)
    c2da_mem[str_26 + 67] = uint8(c2da_fresh334 >> 0x18)
    return
}
var savegamelength : int = default<int>

var specials_e : uint = default<uint>

[sideeffects]
def private P_SaveGameFile_c2da_frame(var slot : int; c2da_fp : int) : int {
    if (P_SaveGameFile__filename == 0) {
        P_SaveGameFile__filename_size = uint64(c2da_lin_strlen(int(savegamedir)) + 32ul)
        P_SaveGameFile__filename = c2da_lin_malloc(P_SaveGameFile__filename_size)
    }
    c2da_lin_snprintf(c2da_fp, 32ul, 360681, [C2daVaArg(tag = 1, i64 = int64(slot), f64 = 0.0lf, raw = 0x0)])
    M_snprintf(P_SaveGameFile__filename, P_SaveGameFile__filename_size, 360695, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(savegamedir)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    return P_SaveGameFile__filename
}
[sideeffects]
def private P_ReadSaveGameHeader_c2da_frame(c2da_fp : int) : uint {
    var i : int
    var a : uint8
    var b : uint8
    var c : uint8
    i = 0
    while (i < 24) {
        saveg_read8()
        i++
    }
    i = 0
    while (i < 16) {
        let c2da_fresh0 : int8 = int8(saveg_read8())
        c2da_mem[c2da_fp + 16 + i] = uint8(c2da_fresh0)
        i++
    }
    c2da_lin_memset(c2da_fp, 0, 16ul)
    M_snprintf(c2da_fp, 16ul, 360700, [C2daVaArg(tag = 1, i64 = int64(G_VanillaVersionCode()), f64 = 0.0lf, raw = 0x0)])
    if (c2da_lin_strcmp(c2da_fp + 16, c2da_fp) != 0) {
        return 0u
    }
    gameskill = int(saveg_read8())
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
def private saveg_read8_c2da_frame(c2da_fp : int) : uint8 {
    if (c2da_lin_fread(c2da_fp, 1ul, 1ul, uint64(save_stream)) < 1ul) {
        if (savegame_error == 0) {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 360711, [])
            savegame_error = 1u
        }
    }
    return c2da_mem[c2da_fp]
}
[sideeffects]
def private P_WriteSaveGameHeader_c2da_frame(var description : int; c2da_fp : int) {
    var i_0 : int = 0
    while (int(int8(c2da_mem[description + i_0])) != 0) {
        saveg_write8(uint8(int8(c2da_mem[description + i_0])))
        i_0++
    }
    while (i_0 < 24) {
        saveg_write8(0u8)
        i_0++
    }
    c2da_lin_memset(c2da_fp, 0, 16ul)
    M_snprintf(c2da_fp, 16ul, 360700, [C2daVaArg(tag = 1, i64 = int64(G_VanillaVersionCode()), f64 = 0.0lf, raw = 0x0)])
    i_0 = 0
    while (i_0 < 16) {
        saveg_write8(uint8(int8(c2da_mem[c2da_fp + i_0])))
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
def private saveg_write8_c2da_frame(var value : uint8; c2da_fp : int) {
    c2da_mem[c2da_fp] = value
    if (c2da_lin_fwrite(c2da_fp, 1ul, 1ul, uint64(save_stream)) < 1ul) {
        if (savegame_error == 0) {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 360772, [])
            savegame_error = 1u
        }
    }
    return
}

// This unit's static data, at heap offset 360672.
let private c2da_lin_static_p_saveg_seg = fixed_array<int>(360672, 224)
let private c2da_lin_static_p_saveg = fixed_array<uint64>(0x6773642e706d6574ul, 0x7661736d6f6f6400ul, 0x25006773642e6425ul, 0x7372657600732573ul, 0x73006925206e6f69ul, 0x6165725f67657661ul, 0x78656e55203a3864ul, 0x6520646574636570ul, 0x696620666f20646eul, 0x656c69687720656cul, 0x676e696461657220ul, 0x6167206576617320ul, 0x65766173000a656dul, 0x3865746972775f67ul, 0x20726f727245203aul, 0x727720656c696877ul, 0x617320676e697469ul, 0xa656d6167206576ul, 0x6e776f6e6b6e5500ul, 0x207373616c637420ul, 0x6173206e69206925ul, 0x5000656d61676576ul, 0x69686372616e555ful, 0x6169636570536576ul, 0x6f6e6b6e553a736cul, 0x73616c6374206e77ul, 0x206e692069252073ul, 0x656d616765766173ul)

[init]
def private c2da_lin_init_static_p_saveg() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_p_saveg_seg[s * 2]
        for (k in range(c2da_lin_static_p_saveg_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_p_saveg[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
