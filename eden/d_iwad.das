options gen2
options stack = 4194304
module d_iwad public

require dasdoom_runtime
require i_system_cluster
require m_argv
require strings
require daslib/math_bits
[sideeffects]
def private c2da___bswap_16(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
[export, sideeffects]
def D_FindWADByName(var name : int) : int {
    var path : int
    var i : int
    if (M_FileExists(name) != 0x0) {
        return name
    }
    BuildIWADDirList()
    i = 0
    while (i < num_iwad_dirs) {
        if (DirIsFile(iwad_dirs[i], name) != 0x0 && M_FileExists(iwad_dirs[i]) != 0x0) {
            return c2da_lin_strdup(iwad_dirs[i])
        }
        path = M_StringJoin(iwad_dirs[i], [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 302995ul), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(name)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 0ul)])
        if (M_FileExists(path) != 0x0) {
            return path
        }
        c2da_lin_free(path)
        i++
    }
    return 0
}
var private iwad_dirs : int[128]

[sideeffects]
def private DirIsFile(var path_0 : int; var filename : int) : uint {
    var path_len : uint64
    var filename_len : uint64
    path_len = uint64(c2da_lin_strlen(path_0))
    filename_len = uint64(c2da_lin_strlen(filename))
    return uint(path_len >= filename_len + 1ul && int(int8(c2da_mem[path_0 + int(path_len - filename_len - 1ul)])) == 47 && c2da_lin_strcasecmp(path_0 + int(path_len - filename_len), filename) == 0 ? 1 : 0)
}
var private num_iwad_dirs : int = 0

[sideeffects]
def private BuildIWADDirList() {
    AddIWADDir(302997)
    iwad_dirs_built = 1u
    return
}
var private iwad_dirs_built : uint = 0u

[sideeffects]
def private AddIWADDir(var dir : int) {
    if (num_iwad_dirs < 128) {
        iwad_dirs[num_iwad_dirs] = int(dir)  // nolint:PERF020
        num_iwad_dirs++
    }
    return
}
[export, sideeffects]
def D_TryFindWADByName(var filename_0 : int) : int {
    var result_0 : int = D_FindWADByName(filename_0)
    if (result_0 != 0) {
        return result_0
    } else {
        return filename_0
    }
}
[export, sideeffects]
def D_FindIWAD(var mask : int; var mission : int) : int {
    var result_1 : int
    var iwadfile : int
    var iwadparm : int
    var i_0 : int
    iwadparm = M_CheckParmWithArgs(302999, 1)
    if (iwadparm != 0) {
        iwadfile = int(uint(c2da_mem[myargv + (iwadparm + 1) * 8]) | uint(c2da_mem[myargv + (iwadparm + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (iwadparm + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (iwadparm + 1) * 8 + 3]) << 0x18)
        result_1 = D_FindWADByName(iwadfile)
        if (result_1 == 0) {
            I_Error(303005, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(iwadfile))])
        }
        let c2da_fresh0 : uint = IdentifyIWADByName(result_1, mask)
        let c2da_fresh1 : uint = c2da_fresh0
        c2da_mem[mission] = uint8(c2da_fresh1)
        c2da_mem[mission + 1] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[mission + 2] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[mission + 3] = uint8(c2da_fresh1 >> 0x18)
    } else {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 303031, [])
        result_1 = 0
        BuildIWADDirList()
        i_0 = 0
        while (result_1 == 0 && i_0 < num_iwad_dirs) {
            result_1 = SearchDirectoryForIWAD(iwad_dirs[i_0], mask, mission)
            i_0++
        }
    }
    return result_1
}
[sideeffects]
def private SearchDirectoryForIWAD(var dir_0 : int; var mask_0 : int; var mission_0 : int) : int {
    var filename_1 : int
    var i_1 : uint64 = 0ul
    while (i_1 < 336ul / 24ul) {
        if ((1 << int(uint(c2da_mem[302320 + int(i_1) * 24 + 8]) | uint(c2da_mem[302320 + int(i_1) * 24 + 9]) << 0x8 | uint(c2da_mem[302320 + int(i_1) * 24 + 10]) << 0x10 | uint(c2da_mem[302320 + int(i_1) * 24 + 11]) << 0x18) & mask_0) == 0) {
            i_1++
            continue
        }
        filename_1 = CheckDirectoryHasIWAD(dir_0, int(uint(c2da_mem[302320 + int(i_1) * 24]) | uint(c2da_mem[302320 + int(i_1) * 24 + 1]) << 0x8 | uint(c2da_mem[302320 + int(i_1) * 24 + 2]) << 0x10 | uint(c2da_mem[302320 + int(i_1) * 24 + 3]) << 0x18))
        if (filename_1 != 0) {
            let c2da_fresh2 : uint = uint(c2da_mem[302320 + int(i_1) * 24 + 8]) | uint(c2da_mem[302320 + int(i_1) * 24 + 9]) << 0x8 | uint(c2da_mem[302320 + int(i_1) * 24 + 10]) << 0x10 | uint(c2da_mem[302320 + int(i_1) * 24 + 11]) << 0x18
            let c2da_fresh3 : uint = c2da_fresh2
            c2da_mem[mission_0] = uint8(c2da_fresh3)
            c2da_mem[mission_0 + 1] = uint8(c2da_fresh3 >> 0x8)
            c2da_mem[mission_0 + 2] = uint8(c2da_fresh3 >> 0x10)
            c2da_mem[mission_0 + 3] = uint8(c2da_fresh3 >> 0x18)
            return filename_1
        }
        i_1++
    }
    return 0
}
[sideeffects]
def private CheckDirectoryHasIWAD(var dir_1 : int; var iwadname : int) : int {
    var filename_2 : int
    if (DirIsFile(dir_1, iwadname) != 0x0 && M_FileExists(dir_1) != 0x0) {
        return c2da_lin_strdup(dir_1)
    }
    if (c2da_lin_strcmp(dir_1, 302997) == 0) {
        filename_2 = c2da_lin_strdup(iwadname)
    } else {
        filename_2 = M_StringJoin(dir_1, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 302995ul), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(iwadname)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 0ul)])
    }
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 303077, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(filename_2))])
    if (M_FileExists(filename_2) != 0x0) {
        return filename_2
    }
    c2da_lin_free(filename_2)
    return 0
}
[sideeffects]
def private IdentifyIWADByName(var name_0 : int; var mask_1 : int) : uint {
    var i_2 : uint64
    var mission_1 : uint
    var p : int = c2da_lin_strrchr(name_0, 47)
    if (p != 0) {
        name_0 = p + 1
    }
    mission_1 = 9u
    i_2 = 0ul
    while (i_2 < 336ul / 24ul) {
        if ((1 << int(uint(c2da_mem[302320 + int(i_2) * 24 + 8]) | uint(c2da_mem[302320 + int(i_2) * 24 + 9]) << 0x8 | uint(c2da_mem[302320 + int(i_2) * 24 + 10]) << 0x10 | uint(c2da_mem[302320 + int(i_2) * 24 + 11]) << 0x18) & mask_1) == 0) {
            i_2++
            continue
        }
        if (c2da_lin_strcasecmp(name_0, int(uint(c2da_mem[302320 + int(i_2) * 24]) | uint(c2da_mem[302320 + int(i_2) * 24 + 1]) << 0x8 | uint(c2da_mem[302320 + int(i_2) * 24 + 2]) << 0x10 | uint(c2da_mem[302320 + int(i_2) * 24 + 3]) << 0x18)) == 0) {
            mission_1 = uint(c2da_mem[302320 + int(i_2) * 24 + 8]) | uint(c2da_mem[302320 + int(i_2) * 24 + 9]) << 0x8 | uint(c2da_mem[302320 + int(i_2) * 24 + 10]) << 0x10 | uint(c2da_mem[302320 + int(i_2) * 24 + 11]) << 0x18
            break
        }
        i_2++
    }
    return mission_1
}
[export, sideeffects]
def D_FindAllIWADs(var mask_2 : int) : int {
    var result_2 : int
    var result_len : int
    var filename_3 : int
    var i_3 : int
    result_2 = c2da_lin_malloc(8ul * (336ul / 24ul + 1ul))
    result_len = 0
    i_3 = 0
    while (uint64(i_3) < 336ul / 24ul) {
        if ((1 << int(uint(c2da_mem[302320 + i_3 * 24 + 8]) | uint(c2da_mem[302320 + i_3 * 24 + 9]) << 0x8 | uint(c2da_mem[302320 + i_3 * 24 + 10]) << 0x10 | uint(c2da_mem[302320 + i_3 * 24 + 11]) << 0x18) & mask_2) == 0) {
            i_3++
            continue
        }
        filename_3 = D_FindWADByName(int(uint(c2da_mem[302320 + i_3 * 24]) | uint(c2da_mem[302320 + i_3 * 24 + 1]) << 0x8 | uint(c2da_mem[302320 + i_3 * 24 + 2]) << 0x10 | uint(c2da_mem[302320 + i_3 * 24 + 3]) << 0x18))
        if (filename_3 != 0) {
            let c2da_fresh4 : int = 302320 + i_3 * 24
            let c2da_fresh5 : uint = uint(c2da_fresh4)
            c2da_mem[result_2 + result_len * 8] = uint8(c2da_fresh5)
            c2da_mem[result_2 + result_len * 8 + 1] = uint8(c2da_fresh5 >> 0x8)
            c2da_mem[result_2 + result_len * 8 + 2] = uint8(c2da_fresh5 >> 0x10)
            c2da_mem[result_2 + result_len * 8 + 3] = uint8(c2da_fresh5 >> 0x18)
            c2da_mem[result_2 + result_len * 8 + 4] = 0u8
            c2da_mem[result_2 + result_len * 8 + 5] = 0u8
            c2da_mem[result_2 + result_len * 8 + 6] = 0u8
            c2da_mem[result_2 + result_len * 8 + 7] = 0u8
            result_len++
        }
        i_3++
    }
    let c2da_fresh6 : uint = 0u
    c2da_mem[result_2 + result_len * 8] = uint8(c2da_fresh6)
    c2da_mem[result_2 + result_len * 8 + 1] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[result_2 + result_len * 8 + 2] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[result_2 + result_len * 8 + 3] = uint8(c2da_fresh6 >> 0x18)
    c2da_mem[result_2 + result_len * 8 + 4] = 0u8
    c2da_mem[result_2 + result_len * 8 + 5] = 0u8
    c2da_mem[result_2 + result_len * 8 + 6] = 0u8
    c2da_mem[result_2 + result_len * 8 + 7] = 0u8
    return result_2
}
[export, sideeffects]
def D_SaveGameIWADName(var gamemission : uint) : int {
    var i_4 : uint64 = 0ul
    while (i_4 < 336ul / 24ul) {
        if (gamemission == (uint(c2da_mem[302320 + int(i_4) * 24 + 8]) | uint(c2da_mem[302320 + int(i_4) * 24 + 9]) << 0x8 | uint(c2da_mem[302320 + int(i_4) * 24 + 10]) << 0x10 | uint(c2da_mem[302320 + int(i_4) * 24 + 11]) << 0x18)) {
            return int(uint(c2da_mem[302320 + int(i_4) * 24]) | uint(c2da_mem[302320 + int(i_4) * 24 + 1]) << 0x8 | uint(c2da_mem[302320 + int(i_4) * 24 + 2]) << 0x10 | uint(c2da_mem[302320 + int(i_4) * 24 + 3]) << 0x18)
        }
        i_4++
    }
    return 303098
}
[export, sideeffects]
def D_SuggestIWADName(var mission_2 : uint; var mode : uint) : int {
    var i_5 : int = 0
    while (uint64(i_5) < 336ul / 24ul) {
        if ((uint(c2da_mem[302320 + i_5 * 24 + 8]) | uint(c2da_mem[302320 + i_5 * 24 + 9]) << 0x8 | uint(c2da_mem[302320 + i_5 * 24 + 10]) << 0x10 | uint(c2da_mem[302320 + i_5 * 24 + 11]) << 0x18) == mission_2 && (uint(c2da_mem[302320 + i_5 * 24 + 12]) | uint(c2da_mem[302320 + i_5 * 24 + 13]) << 0x8 | uint(c2da_mem[302320 + i_5 * 24 + 14]) << 0x10 | uint(c2da_mem[302320 + i_5 * 24 + 15]) << 0x18) == mode) {
            return int(uint(c2da_mem[302320 + i_5 * 24]) | uint(c2da_mem[302320 + i_5 * 24 + 1]) << 0x8 | uint(c2da_mem[302320 + i_5 * 24 + 2]) << 0x10 | uint(c2da_mem[302320 + i_5 * 24 + 3]) << 0x18)
        }
        i_5++
    }
    return 303098
}
[export, sideeffects]
def D_SuggestGameName(var mission_3 : uint; var mode_0 : uint) : int {
    var i_6 : int = 0
    while (uint64(i_6) < 336ul / 24ul) {
        if ((uint(c2da_mem[302320 + i_6 * 24 + 8]) | uint(c2da_mem[302320 + i_6 * 24 + 9]) << 0x8 | uint(c2da_mem[302320 + i_6 * 24 + 10]) << 0x10 | uint(c2da_mem[302320 + i_6 * 24 + 11]) << 0x18) == mission_3 && (mode_0 == 4u || (uint(c2da_mem[302320 + i_6 * 24 + 12]) | uint(c2da_mem[302320 + i_6 * 24 + 13]) << 0x8 | uint(c2da_mem[302320 + i_6 * 24 + 14]) << 0x10 | uint(c2da_mem[302320 + i_6 * 24 + 15]) << 0x18) == mode_0)) {
            return int(uint(c2da_mem[302320 + i_6 * 24 + 16]) | uint(c2da_mem[302320 + i_6 * 24 + 17]) << 0x8 | uint(c2da_mem[302320 + i_6 * 24 + 18]) << 0x10 | uint(c2da_mem[302320 + i_6 * 24 + 19]) << 0x18)
        }
        i_6++
    }
    return 303110
}

// This unit's static data, at heap offset 302320.
let private c2da_lin_static_d_iwad_seg = fixed_array<int>(302320, 803)
let private c2da_lin_static_d_iwad = fixed_array<uint64>(0x49e40ul, 0x200000001ul, 0x49e4aul, 0x49e52ul, 0x200000003ul, 0x49e5ful, 0x49e7ful, 0x200000002ul, 0x49e87ul, 0x49ea2ul, 0x300000000ul, 0x49eabul, 0x49eb0ul, 0x0ul, 0x49ebaul, 0x49ec9ul, 0x4ul, 0x49ed2ul, 0x49eddul, 0x200000005ul, 0x49ee6ul, 0x49eebul, 0x200000001ul, 0x49ef6ul, 0x49efdul, 0x200000001ul, 0x49f0bul, 0x49f1dul, 0x300000000ul, 0x49f2bul, 0x49f3dul, 0x300000006ul, 0x49f49ul, 0x49f51ul, 0x6ul, 0x49f5eul, 0x49f70ul, 0x200000007ul, 0x49f7aul, 0x49f80ul, 0x200000008ul, 0x49f8cul, 0x61772e326d6f6f64ul, 0x49206d6f6f440064ul, 0x6e6f74756c700049ul, 0x46006461772e6169ul, 0x6f6f44206c616e69ul, 0x6f74756c50203a6dul, 0x657078452061696eul, 0x7400746e656d6972ul, 0x46006461772e746eul, 0x6f6f44206c616e69ul, 0x203a544e54203a6dul, 0x6f6974756c697645ul, 0x772e6d6f6f64006eul, 0x6d6f6f44006461ul, 0x61772e316d6f6f64ul, 0x53206d6f6f440064ul, 0x6572617765726168ul, 0x61772e7865686300ul, 0x5120786568430064ul, 0x6361680074736575ul, 0x6148006461772e78ul, 0x6465657266007863ul, 0x7246006461772e6dul, 0x657266004d446565ul, 0x772e326d6f6f6465ul, 0x6465657246006461ul, 0x616850203a6d6f6ful, 0x6572660032206573ul, 0x772e316d6f6f6465ul, 0x6465657246006461ul, 0x616850203a6d6f6ful, 0x7265680031206573ul, 0x6461772e63697465ul, 0x6369746572654800ul, 0x6369746572656800ul, 0x6548006461772e31ul, 0x6853206369746572ul, 0x65726177657261ul, 0x61772e6e65786568ul, 0x6e657865480064ul, 0x2e31656669727473ul, 0x6972745300646177ul, 0x2d002e002f006566ul, 0x4157490064617769ul, 0x2720656c69662044ul, 0x20746f6e20277325ul, 0x2d0021646e756f66ul, 0x746f6e2064617769ul, 0x6966696365707320ul, 0x69797274202c6465ul, 0x776566206120676eul, 0x616e206461776920ul, 0x797254000a73656dul, 0x4441574920676e69ul, 0x73253a656c696620ul, 0x776f6e6b6e75000aul, 0x6e55006461772e6eul, 0x6167206e776f6e6bul, 0x3f656dul)

[init]
def private c2da_lin_init_static_d_iwad() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_d_iwad_seg[s * 2]
        for (k in range(c2da_lin_static_d_iwad_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_d_iwad[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
