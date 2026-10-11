[sideeffects]
def private c2da___bswap_16_18(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_18(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_18(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_18(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_18(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_18(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
var lumpinfo : int = default<int>

var numlumps : uint = 0u

[export, sideeffects]
def W_AddFile(var filename : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = W_AddFile_c2da_frame(filename, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
var private lumphash : int = default<int>

[sideeffects]
def private ExtendLumpInfo(var newnumlumps_0 : int) {
    var newlumpinfo : int
    var i_0 : uint
    var nextlumpnum : int
    newlumpinfo = c2da_lin_calloc(uint64(newnumlumps_0), 40ul)
    if (newlumpinfo == 0) {
        I_Error(376983, [])
    }
    i_0 = 0u
    while (i_0 < numlumps && i_0 < uint(newnumlumps_0)) {
        c2da_lin_memcpy(newlumpinfo + int(i_0) * 40, lumpinfo + int(i_0) * 40, 40ul)
        if (int(uint(c2da_mem[newlumpinfo + int(i_0) * 40 + 24]) | uint(c2da_mem[newlumpinfo + int(i_0) * 40 + 25]) << 0x8 | uint(c2da_mem[newlumpinfo + int(i_0) * 40 + 26]) << 0x10 | uint(c2da_mem[newlumpinfo + int(i_0) * 40 + 27]) << 0x18) != 0) {
            Z_ChangeUser(int(uint(c2da_mem[newlumpinfo + int(i_0) * 40 + 24]) | uint(c2da_mem[newlumpinfo + int(i_0) * 40 + 25]) << 0x8 | uint(c2da_mem[newlumpinfo + int(i_0) * 40 + 26]) << 0x10 | uint(c2da_mem[newlumpinfo + int(i_0) * 40 + 27]) << 0x18), newlumpinfo + int(i_0) * 40 + 24)
        }
        if (int(uint(c2da_mem[lumpinfo + int(i_0) * 40 + 32]) | uint(c2da_mem[lumpinfo + int(i_0) * 40 + 33]) << 0x8 | uint(c2da_mem[lumpinfo + int(i_0) * 40 + 34]) << 0x10 | uint(c2da_mem[lumpinfo + int(i_0) * 40 + 35]) << 0x18) != 0) {
            nextlumpnum = (int(uint(c2da_mem[lumpinfo + int(i_0) * 40 + 32]) | uint(c2da_mem[lumpinfo + int(i_0) * 40 + 33]) << 0x8 | uint(c2da_mem[lumpinfo + int(i_0) * 40 + 34]) << 0x10 | uint(c2da_mem[lumpinfo + int(i_0) * 40 + 35]) << 0x18) - lumpinfo) / 40
            let c2da_fresh14 : int = newlumpinfo + nextlumpnum * 40
            let c2da_fresh15 : uint = uint(c2da_fresh14)
            c2da_mem[newlumpinfo + int(i_0) * 40 + 32] = uint8(c2da_fresh15)
            c2da_mem[newlumpinfo + int(i_0) * 40 + 33] = uint8(c2da_fresh15 >> 0x8)
            c2da_mem[newlumpinfo + int(i_0) * 40 + 34] = uint8(c2da_fresh15 >> 0x10)
            c2da_mem[newlumpinfo + int(i_0) * 40 + 35] = uint8(c2da_fresh15 >> 0x18)
            c2da_mem[newlumpinfo + int(i_0) * 40 + 36] = 0u8
            c2da_mem[newlumpinfo + int(i_0) * 40 + 37] = 0u8
            c2da_mem[newlumpinfo + int(i_0) * 40 + 38] = 0u8
            c2da_mem[newlumpinfo + int(i_0) * 40 + 39] = 0u8
        }
        i_0++
    }
    c2da_lin_free(lumpinfo)
    lumpinfo = newlumpinfo
    numlumps = uint(newnumlumps_0)
    return
}
[export, sideeffects]
def W_CheckNumForName(var name : int) : int {
    var lump_p_0 : int
    var i_1 : int
    var hash : int
    if (lumphash != 0) {
        hash = int(W_LumpNameHash(name) % numlumps)
        lump_p_0 = int(uint(c2da_mem[lumphash + hash * 8]) | uint(c2da_mem[lumphash + hash * 8 + 1]) << 0x8 | uint(c2da_mem[lumphash + hash * 8 + 2]) << 0x10 | uint(c2da_mem[lumphash + hash * 8 + 3]) << 0x18)
        while (lump_p_0 != 0) {
            if (c2da_lin_strncasecmp(lump_p_0, name, 8ul) == 0) {
                return (lump_p_0 - lumpinfo) / 40
            }
            lump_p_0 = int(uint(c2da_mem[lump_p_0 + 32]) | uint(c2da_mem[lump_p_0 + 33]) << 0x8 | uint(c2da_mem[lump_p_0 + 34]) << 0x10 | uint(c2da_mem[lump_p_0 + 35]) << 0x18)
        }
    } else {
        i_1 = int(numlumps - 1u)
        while (i_1 >= 0) {
            if (c2da_lin_strncasecmp(lumpinfo + i_1 * 40, name, 8ul) == 0) {
                return i_1
            }
            i_1--
        }
    }
    return -1
}
[export, sideeffects]
def W_LumpNameHash(var s : int) : uint {
    var result_0 : uint
    var i_2 : uint
    result_0 = 5381u
    i_2 = 0u
    while (i_2 < 8u && int(int8(c2da_mem[s + int(i_2)])) != 0) {
        result_0 = result_0 << 5u ^ result_0 ^ uint(c2da_std_toupper(int(int8(c2da_mem[s + int(i_2)]))))
        i_2++
    }
    return result_0
}
[export, sideeffects]
def W_GetNumForName(var name_0 : int) : int {
    var i_3 : int = W_CheckNumForName(name_0)
    if (i_3 < 0) {
        I_Error(377009, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(name_0))])
    }
    return i_3
}
[export, sideeffects]
def W_LumpLength(var lump : uint) : int {
    if (lump >= numlumps) {
        I_Error(377040, [C2daVaArg(tag = 1, i64 = int64(lump), f64 = 0.0lf, raw = 0x0)])
    }
    return int(uint(c2da_mem[lumpinfo + int(lump) * 40 + 20]) | uint(c2da_mem[lumpinfo + int(lump) * 40 + 21]) << 0x8 | uint(c2da_mem[lumpinfo + int(lump) * 40 + 22]) << 0x10 | uint(c2da_mem[lumpinfo + int(lump) * 40 + 23]) << 0x18)
}
[export, sideeffects]
def W_ReadLump(var lump_0 : uint; var dest : int) {
    var c : int
    var l : int
    if (lump_0 >= numlumps) {
        I_Error(377069, [C2daVaArg(tag = 1, i64 = int64(lump_0), f64 = 0.0lf, raw = 0x0)])
    }
    l = lumpinfo + int(lump_0) * 40
    I_BeginRead()
    c = int(W_Read(int(uint(c2da_mem[l + 8]) | uint(c2da_mem[l + 9]) << 0x8 | uint(c2da_mem[l + 10]) << 0x10 | uint(c2da_mem[l + 11]) << 0x18), uint(int(uint(c2da_mem[l + 16]) | uint(c2da_mem[l + 17]) << 0x8 | uint(c2da_mem[l + 18]) << 0x10 | uint(c2da_mem[l + 19]) << 0x18)), dest, uint64(int(uint(c2da_mem[l + 20]) | uint(c2da_mem[l + 21]) << 0x8 | uint(c2da_mem[l + 22]) << 0x10 | uint(c2da_mem[l + 23]) << 0x18))))
    if (c < int(uint(c2da_mem[l + 20]) | uint(c2da_mem[l + 21]) << 0x8 | uint(c2da_mem[l + 22]) << 0x10 | uint(c2da_mem[l + 23]) << 0x18)) {
        I_Error(377096, [C2daVaArg(tag = 1, i64 = int64(c), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[l + 20]) | uint(c2da_mem[l + 21]) << 0x8 | uint(c2da_mem[l + 22]) << 0x10 | uint(c2da_mem[l + 23]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(lump_0), f64 = 0.0lf, raw = 0x0)])
    }
    I_EndRead()
    return
}
[export, sideeffects]
def W_CacheLumpNum(var lumpnum : int; var tag : int) : int {
    var result_1 : int
    var lump_1 : int
    if (uint(lumpnum) >= numlumps) {
        I_Error(377138, [C2daVaArg(tag = 1, i64 = int64(lumpnum), f64 = 0.0lf, raw = 0x0)])
    }
    lump_1 = lumpinfo + lumpnum * 40
    let c2da_fresh16 : int = int(uint(c2da_mem[lump_1 + 8]) | uint(c2da_mem[lump_1 + 9]) << 0x8 | uint(c2da_mem[lump_1 + 10]) << 0x10 | uint(c2da_mem[lump_1 + 11]) << 0x18) + 8
    if (int(uint(c2da_mem[c2da_fresh16]) | uint(c2da_mem[c2da_fresh16 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh16 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh16 + 3]) << 0x18) != 0) {
        let c2da_fresh17 : int = int(uint(c2da_mem[lump_1 + 8]) | uint(c2da_mem[lump_1 + 9]) << 0x8 | uint(c2da_mem[lump_1 + 10]) << 0x10 | uint(c2da_mem[lump_1 + 11]) << 0x18) + 8
        result_1 = int(uint(c2da_mem[c2da_fresh17]) | uint(c2da_mem[c2da_fresh17 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh17 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh17 + 3]) << 0x18) + int(uint(c2da_mem[lump_1 + 16]) | uint(c2da_mem[lump_1 + 17]) << 0x8 | uint(c2da_mem[lump_1 + 18]) << 0x10 | uint(c2da_mem[lump_1 + 19]) << 0x18)
    } elif (int(uint(c2da_mem[lump_1 + 24]) | uint(c2da_mem[lump_1 + 25]) << 0x8 | uint(c2da_mem[lump_1 + 26]) << 0x10 | uint(c2da_mem[lump_1 + 27]) << 0x18) != 0) {
        result_1 = int(uint(c2da_mem[lump_1 + 24]) | uint(c2da_mem[lump_1 + 25]) << 0x8 | uint(c2da_mem[lump_1 + 26]) << 0x10 | uint(c2da_mem[lump_1 + 27]) << 0x18)
        Z_ChangeTag2(int(uint(c2da_mem[lump_1 + 24]) | uint(c2da_mem[lump_1 + 25]) << 0x8 | uint(c2da_mem[lump_1 + 26]) << 0x10 | uint(c2da_mem[lump_1 + 27]) << 0x18), tag, 377169, 410)
    } else {
        let c2da_fresh18 : int = Z_Malloc(W_LumpLength(uint(lumpnum)), tag, lump_1 + 24)
        let c2da_fresh19 : uint = uint(c2da_fresh18)
        c2da_mem[lump_1 + 24] = uint8(c2da_fresh19)
        c2da_mem[lump_1 + 25] = uint8(c2da_fresh19 >> 0x8)
        c2da_mem[lump_1 + 26] = uint8(c2da_fresh19 >> 0x10)
        c2da_mem[lump_1 + 27] = uint8(c2da_fresh19 >> 0x18)
        c2da_mem[lump_1 + 28] = 0u8
        c2da_mem[lump_1 + 29] = 0u8
        c2da_mem[lump_1 + 30] = 0u8
        c2da_mem[lump_1 + 31] = 0u8
        W_ReadLump(uint(lumpnum), int(uint(c2da_mem[lump_1 + 24]) | uint(c2da_mem[lump_1 + 25]) << 0x8 | uint(c2da_mem[lump_1 + 26]) << 0x10 | uint(c2da_mem[lump_1 + 27]) << 0x18))
        result_1 = int(uint(c2da_mem[lump_1 + 24]) | uint(c2da_mem[lump_1 + 25]) << 0x8 | uint(c2da_mem[lump_1 + 26]) << 0x10 | uint(c2da_mem[lump_1 + 27]) << 0x18)
    }
    return result_1
}
[export, sideeffects]
def W_CacheLumpName(var name_1 : int; var tag_0 : int) : int {
    return W_CacheLumpNum(W_GetNumForName(name_1), tag_0)
}
[export, sideeffects]
def W_GenerateHashTable() {
    var i_4 : uint
    var hash_0 : uint
    if (lumphash != 0) {
        Z_Free(lumphash)
    }
    if (numlumps > 0u) {
        lumphash = Z_Malloc(int(8ul * uint64(numlumps)), 1, 0)
        c2da_lin_memset(lumphash, 0, 8ul * uint64(numlumps))
        i_4 = 0u
        while (i_4 < numlumps) {
            hash_0 = W_LumpNameHash(lumpinfo + int(i_4) * 40) % numlumps
            let c2da_fresh20 : int = int(uint(c2da_mem[lumphash + int(hash_0) * 8]) | uint(c2da_mem[lumphash + int(hash_0) * 8 + 1]) << 0x8 | uint(c2da_mem[lumphash + int(hash_0) * 8 + 2]) << 0x10 | uint(c2da_mem[lumphash + int(hash_0) * 8 + 3]) << 0x18)
            let c2da_fresh21 : uint = uint(c2da_fresh20)
            c2da_mem[lumpinfo + int(i_4) * 40 + 32] = uint8(c2da_fresh21)
            c2da_mem[lumpinfo + int(i_4) * 40 + 33] = uint8(c2da_fresh21 >> 0x8)
            c2da_mem[lumpinfo + int(i_4) * 40 + 34] = uint8(c2da_fresh21 >> 0x10)
            c2da_mem[lumpinfo + int(i_4) * 40 + 35] = uint8(c2da_fresh21 >> 0x18)
            c2da_mem[lumpinfo + int(i_4) * 40 + 36] = 0u8
            c2da_mem[lumpinfo + int(i_4) * 40 + 37] = 0u8
            c2da_mem[lumpinfo + int(i_4) * 40 + 38] = 0u8
            c2da_mem[lumpinfo + int(i_4) * 40 + 39] = 0u8
            let c2da_fresh22 : int = lumpinfo + int(i_4) * 40
            let c2da_fresh23 : uint = uint(c2da_fresh22)
            c2da_mem[lumphash + int(hash_0) * 8] = uint8(c2da_fresh23)
            c2da_mem[lumphash + int(hash_0) * 8 + 1] = uint8(c2da_fresh23 >> 0x8)
            c2da_mem[lumphash + int(hash_0) * 8 + 2] = uint8(c2da_fresh23 >> 0x10)
            c2da_mem[lumphash + int(hash_0) * 8 + 3] = uint8(c2da_fresh23 >> 0x18)
            c2da_mem[lumphash + int(hash_0) * 8 + 4] = 0u8
            c2da_mem[lumphash + int(hash_0) * 8 + 5] = 0u8
            c2da_mem[lumphash + int(hash_0) * 8 + 6] = 0u8
            c2da_mem[lumphash + int(hash_0) * 8 + 7] = 0u8
            i_4++
        }
    }
    return
}
[export, sideeffects]
def W_ReleaseLumpNum(var lumpnum_0 : int) {
    var lump_2 : int
    if (uint(lumpnum_0) >= numlumps) {
        I_Error(377247, [C2daVaArg(tag = 1, i64 = int64(lumpnum_0), f64 = 0.0lf, raw = 0x0)])
    }
    lump_2 = lumpinfo + lumpnum_0 * 40
    let c2da_fresh24 : int = int(uint(c2da_mem[lump_2 + 8]) | uint(c2da_mem[lump_2 + 9]) << 0x8 | uint(c2da_mem[lump_2 + 10]) << 0x10 | uint(c2da_mem[lump_2 + 11]) << 0x18) + 8
    if (int(uint(c2da_mem[c2da_fresh24]) | uint(c2da_mem[c2da_fresh24 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh24 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh24 + 3]) << 0x18) == 0) {
        Z_ChangeTag2(int(uint(c2da_mem[lump_2 + 24]) | uint(c2da_mem[lump_2 + 25]) << 0x8 | uint(c2da_mem[lump_2 + 26]) << 0x10 | uint(c2da_mem[lump_2 + 27]) << 0x18), 8, 377169, 461)
    }
    return
}
[export, sideeffects]
def W_ReleaseLumpName(var name_2 : int) {
    W_ReleaseLumpNum(W_GetNumForName(name_2))
    return
}
[export, sideeffects]
def W_CheckCorrectIWAD(var mission : uint) {
    var i_5 : int
    var lumpnum_1 : int
    i_5 = 0
    while (uint64(i_5) < 64ul / 16ul) {
        if (mission != (uint(c2da_mem[376816 + i_5 * 16]) | uint(c2da_mem[376816 + i_5 * 16 + 1]) << 0x8 | uint(c2da_mem[376816 + i_5 * 16 + 2]) << 0x10 | uint(c2da_mem[376816 + i_5 * 16 + 3]) << 0x18)) {
            lumpnum_1 = W_CheckNumForName(int(uint(c2da_mem[376816 + i_5 * 16 + 8]) | uint(c2da_mem[376816 + i_5 * 16 + 9]) << 0x8 | uint(c2da_mem[376816 + i_5 * 16 + 10]) << 0x10 | uint(c2da_mem[376816 + i_5 * 16 + 11]) << 0x18))
            if (lumpnum_1 >= 0) {
                I_Error(377280, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(D_SuggestGameName(uint(c2da_mem[376816 + i_5 * 16]) | uint(c2da_mem[376816 + i_5 * 16 + 1]) << 0x8 | uint(c2da_mem[376816 + i_5 * 16 + 2]) << 0x10 | uint(c2da_mem[376816 + i_5 * 16 + 3]) << 0x18, 4u))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 377408ul), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(D_GameMissionString(mission))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 377408ul), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(D_GameMissionString(uint(c2da_mem[376816 + i_5 * 16]) | uint(c2da_mem[376816 + i_5 * 16 + 1]) << 0x8 | uint(c2da_mem[376816 + i_5 * 16 + 2]) << 0x10 | uint(c2da_mem[376816 + i_5 * 16 + 3]) << 0x18)))])
            }
        }
        i_5++
    }
    return
}
[export, sideeffects]
def W_NumLumps() : int {
    return int(numlumps)
}
[sideeffects]
def private W_AddFile_c2da_frame(var filename : int; c2da_fp : int) : int {
    var lump_p : int
    var i : uint
    var wad_file : int
    var length_0 : int
    var startlump : int
    var fileinfo : int
    var filerover : int
    var newnumlumps : int
    wad_file = W_OpenFile(filename)
    if (wad_file == 0) {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 376908, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(filename))])
        return 0
    }
    newnumlumps = int(numlumps)
    if (c2da_lin_strcasecmp(filename + int(c2da_lin_strlen(filename)) - 3, 376927) != 0) {
        fileinfo = Z_Malloc(16, 1, 0)
        let c2da_fresh0 : int = 0
        let c2da_fresh1 : uint = uint(c2da_fresh0)
        c2da_mem[fileinfo] = uint8(c2da_fresh1)
        c2da_mem[fileinfo + 1] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[fileinfo + 2] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[fileinfo + 3] = uint8(c2da_fresh1 >> 0x18)
        let c2da_fresh2 : int = int(uint(c2da_mem[wad_file + 16]) | uint(c2da_mem[wad_file + 17]) << 0x8 | uint(c2da_mem[wad_file + 18]) << 0x10 | uint(c2da_mem[wad_file + 19]) << 0x18)
        let c2da_fresh3 : uint = uint(c2da_fresh2)
        c2da_mem[fileinfo + 4] = uint8(c2da_fresh3)
        c2da_mem[fileinfo + 5] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[fileinfo + 6] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[fileinfo + 7] = uint8(c2da_fresh3 >> 0x18)
        M_ExtractFileBase(filename, fileinfo + 8)
        newnumlumps++
    } else {
        W_Read(wad_file, 0u, c2da_fp, 12ul)
        if (c2da_lin_strncmp(c2da_fp, 376931, 4ul) != 0) {
            if (c2da_lin_strncmp(c2da_fp, 376936, 4ul) != 0) {
                I_Error(376941, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(filename))])
            }
        }
        let c2da_fresh4 : int = int(uint(c2da_mem[c2da_fp + 4]) | uint(c2da_mem[c2da_fp + 5]) << 0x8 | uint(c2da_mem[c2da_fp + 6]) << 0x10 | uint(c2da_mem[c2da_fp + 7]) << 0x18)
        let c2da_fresh5 : uint = uint(c2da_fresh4)
        c2da_mem[c2da_fp + 4] = uint8(c2da_fresh5)
        c2da_mem[c2da_fp + 5] = uint8(c2da_fresh5 >> 0x8)
        c2da_mem[c2da_fp + 6] = uint8(c2da_fresh5 >> 0x10)
        c2da_mem[c2da_fp + 7] = uint8(c2da_fresh5 >> 0x18)
        let c2da_fresh6 : int = int(uint(c2da_mem[c2da_fp + 8]) | uint(c2da_mem[c2da_fp + 9]) << 0x8 | uint(c2da_mem[c2da_fp + 10]) << 0x10 | uint(c2da_mem[c2da_fp + 11]) << 0x18)
        let c2da_fresh7 : uint = uint(c2da_fresh6)
        c2da_mem[c2da_fp + 8] = uint8(c2da_fresh7)
        c2da_mem[c2da_fp + 9] = uint8(c2da_fresh7 >> 0x8)
        c2da_mem[c2da_fp + 10] = uint8(c2da_fresh7 >> 0x10)
        c2da_mem[c2da_fp + 11] = uint8(c2da_fresh7 >> 0x18)
        length_0 = int(uint64(int(uint(c2da_mem[c2da_fp + 4]) | uint(c2da_mem[c2da_fp + 5]) << 0x8 | uint(c2da_mem[c2da_fp + 6]) << 0x10 | uint(c2da_mem[c2da_fp + 7]) << 0x18)) * 16ul)
        fileinfo = Z_Malloc(length_0, 1, 0)
        W_Read(wad_file, uint(int(uint(c2da_mem[c2da_fp + 8]) | uint(c2da_mem[c2da_fp + 9]) << 0x8 | uint(c2da_mem[c2da_fp + 10]) << 0x10 | uint(c2da_mem[c2da_fp + 11]) << 0x18)), fileinfo, uint64(length_0))
        newnumlumps += int(uint(c2da_mem[c2da_fp + 4]) | uint(c2da_mem[c2da_fp + 5]) << 0x8 | uint(c2da_mem[c2da_fp + 6]) << 0x10 | uint(c2da_mem[c2da_fp + 7]) << 0x18)
    }
    startlump = int(numlumps)
    ExtendLumpInfo(newnumlumps)
    lump_p = lumpinfo + startlump * 40
    filerover = fileinfo
    i = uint(startlump)
    while (i < numlumps) {
        let c2da_fresh8 : uint = uint(wad_file)
        c2da_mem[lump_p + 8] = uint8(c2da_fresh8)
        c2da_mem[lump_p + 9] = uint8(c2da_fresh8 >> 0x8)
        c2da_mem[lump_p + 10] = uint8(c2da_fresh8 >> 0x10)
        c2da_mem[lump_p + 11] = uint8(c2da_fresh8 >> 0x18)
        c2da_mem[lump_p + 12] = 0u8
        c2da_mem[lump_p + 13] = 0u8
        c2da_mem[lump_p + 14] = 0u8
        c2da_mem[lump_p + 15] = 0u8
        let c2da_fresh9 : int = int(uint(c2da_mem[filerover]) | uint(c2da_mem[filerover + 1]) << 0x8 | uint(c2da_mem[filerover + 2]) << 0x10 | uint(c2da_mem[filerover + 3]) << 0x18)
        let c2da_fresh10 : uint = uint(c2da_fresh9)
        c2da_mem[lump_p + 16] = uint8(c2da_fresh10)
        c2da_mem[lump_p + 17] = uint8(c2da_fresh10 >> 0x8)
        c2da_mem[lump_p + 18] = uint8(c2da_fresh10 >> 0x10)
        c2da_mem[lump_p + 19] = uint8(c2da_fresh10 >> 0x18)
        let c2da_fresh11 : int = int(uint(c2da_mem[filerover + 4]) | uint(c2da_mem[filerover + 5]) << 0x8 | uint(c2da_mem[filerover + 6]) << 0x10 | uint(c2da_mem[filerover + 7]) << 0x18)
        let c2da_fresh12 : uint = uint(c2da_fresh11)
        c2da_mem[lump_p + 20] = uint8(c2da_fresh12)
        c2da_mem[lump_p + 21] = uint8(c2da_fresh12 >> 0x8)
        c2da_mem[lump_p + 22] = uint8(c2da_fresh12 >> 0x10)
        c2da_mem[lump_p + 23] = uint8(c2da_fresh12 >> 0x18)
        let c2da_fresh13 : uint = 0u
        c2da_mem[lump_p + 24] = uint8(c2da_fresh13)
        c2da_mem[lump_p + 25] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[lump_p + 26] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[lump_p + 27] = uint8(c2da_fresh13 >> 0x18)
        c2da_mem[lump_p + 28] = 0u8
        c2da_mem[lump_p + 29] = 0u8
        c2da_mem[lump_p + 30] = 0u8
        c2da_mem[lump_p + 31] = 0u8
        c2da_lin_strncpy(lump_p, filerover + 8, 8ul)
        lump_p += 40
        filerover += 16
        i++
    }
    Z_Free(fileinfo)
    if (lumphash != 0) {
        Z_Free(lumphash)
        lumphash = 0
    }
    return wad_file
}

// This unit's static data, at heap offset 376816.
let private c2da_lin_static_w_wad_seg = fixed_array<int>(376824, 595)
let private c2da_lin_static_w_wad = fixed_array<uint64>(0x5c030ul, 0x6ul, 0x5c037ul, 0x7ul, 0x5c03eul, 0x8ul, 0x5c045ul, 0x4900314153534f50ul, 0x544500314158504dul, 0x5247410031414e54ul, 0x756f632000314144ul, 0x706f2074276e646cul, 0x77000a7325206e65ul, 0x44415749006461ul, 0x6461570044415750ul, 0x732520656c696620ul, 0x74276e73656f6420ul, 0x5749206576616820ul, 0x575020726f204441ul, 0x43000a6469204441ul, 0x2074276e646c756ful, 0x20636f6c6c616572ul, 0x6f666e69706d756cul, 0x754e7465475f5700ul, 0x656d614e726f466dul, 0x746f6e207325203aul, 0x21646e756f6620ul, 0x654c706d754c5f57ul, 0x6925203a6874676eul, 0x6c6d756e203d3e20ul, 0x525f570073706d75ul, 0x3a706d754c646165ul, 0x6e203d3e20692520ul, 0x73706d756c6d75ul, 0x754c646165525f57ul, 0x796c6e6f203a706dul, 0x6925206461657220ul, 0x6f20692520666f20ul, 0x2520706d756c206eul, 0x686361435f570069ul, 0x6d754e706d754c65ul, 0x203d3e206925203aul, 0x73706d756c6d756eul, 0x632f746f6f722f00ul, 0x7365742f73616432ul, 0x61756e616d2f7374ul, 0x65676d6f6f642f6cul, 0x70752f636972656eul, 0x642f6d6165727473ul, 0x72656e65676d6f6ful, 0x676d6f6f642f6369ul, 0x772f636972656e65ul, 0x5700632e6461775ful, 0x657361656c65525ful, 0x3a6d754e706d754cul, 0x6e203d3e20692520ul, 0x73706d756c6d75ul, 0x65726120756f590aul, 0x20676e6979727420ul, 0x6120657375206f74ul, 0x4441574920732520ul, 0x697720656c696620ul, 0x2520656874206874ul, 0x616e696220732573ul, 0x736968540a2e7972ul, 0x672074276e736920ul, 0x206f7420676e696ful, 0x6f590a2e6b726f77ul, 0x6261626f72702075ul, 0x20746e617720796cul, 0x7420657375206f74ul, 0x2073257325206568ul, 0x2e7972616e6962ul, 0x656e65676d6f6f64ul, 0x636972ul)

[init]
def private c2da_lin_init_static_w_wad() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_w_wad_seg[s * 2]
        for (k in range(c2da_lin_static_w_wad_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_w_wad[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
