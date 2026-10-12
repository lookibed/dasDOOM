options gen2
options solid_context = true
options stack = 4194304
module d_iwad public

require dasdoom_runtime
require i_system_cluster
require m_argv
require strings
require daslib/fio
var private c2da_str_0 : array<int8> = [int8(47), int8(0)]

var private c2da_str_1 : array<int8> = [int8(46), int8(0)]

var private c2da_str_2 : array<int8> = [int8(45), int8(105), int8(119), int8(97), int8(100), int8(0)]

var private c2da_str_3 : array<int8> = [int8(73), int8(87), int8(65), int8(68), int8(32), int8(102), int8(105), int8(108), int8(101), int8(32), int8(39), int8(37), int8(115), int8(39), int8(32), int8(110), int8(111), int8(116), int8(32), int8(102), int8(111), int8(117), int8(110), int8(100), int8(33), int8(0)]

var private c2da_str_4 : array<int8> = [int8(45), int8(105), int8(119), int8(97), int8(100), int8(32), int8(110), int8(111), int8(116), int8(32), int8(115), int8(112), int8(101), int8(99), int8(105), int8(102), int8(105), int8(101), int8(100), int8(44), int8(32), int8(116), int8(114), int8(121), int8(105), int8(110), int8(103), int8(32), int8(97), int8(32), int8(102), int8(101), int8(119), int8(32), int8(105), int8(119), int8(97), int8(100), int8(32), int8(110), int8(97), int8(109), int8(101), int8(115), int8(10), int8(0)]

var private c2da_str_5 : array<int8> = [int8(100), int8(111), int8(111), int8(109), int8(50), int8(46), int8(119), int8(97), int8(100), int8(0)]

var private c2da_str_6 : array<int8> = [int8(68), int8(111), int8(111), int8(109), int8(32), int8(73), int8(73), int8(0)]

var private c2da_str_7 : array<int8> = [int8(112), int8(108), int8(117), int8(116), int8(111), int8(110), int8(105), int8(97), int8(46), int8(119), int8(97), int8(100), int8(0)]

var private c2da_str_8 : array<int8> = [int8(70), int8(105), int8(110), int8(97), int8(108), int8(32), int8(68), int8(111), int8(111), int8(109), int8(58), int8(32), int8(80), int8(108), int8(117), int8(116), int8(111), int8(110), int8(105), int8(97), int8(32), int8(69), int8(120), int8(112), int8(101), int8(114), int8(105), int8(109), int8(101), int8(110), int8(116), int8(0)]

var private c2da_str_9 : array<int8> = [int8(116), int8(110), int8(116), int8(46), int8(119), int8(97), int8(100), int8(0)]

var private c2da_str_10 : array<int8> = [int8(70), int8(105), int8(110), int8(97), int8(108), int8(32), int8(68), int8(111), int8(111), int8(109), int8(58), int8(32), int8(84), int8(78), int8(84), int8(58), int8(32), int8(69), int8(118), int8(105), int8(108), int8(117), int8(116), int8(105), int8(111), int8(110), int8(0)]

var private c2da_str_11 : array<int8> = [int8(100), int8(111), int8(111), int8(109), int8(46), int8(119), int8(97), int8(100), int8(0)]

var private c2da_str_12 : array<int8> = [int8(68), int8(111), int8(111), int8(109), int8(0)]

var private c2da_str_13 : array<int8> = [int8(100), int8(111), int8(111), int8(109), int8(49), int8(46), int8(119), int8(97), int8(100), int8(0)]

var private c2da_str_14 : array<int8> = [int8(68), int8(111), int8(111), int8(109), int8(32), int8(83), int8(104), int8(97), int8(114), int8(101), int8(119), int8(97), int8(114), int8(101), int8(0)]

var private c2da_str_15 : array<int8> = [int8(99), int8(104), int8(101), int8(120), int8(46), int8(119), int8(97), int8(100), int8(0)]

var private c2da_str_16 : array<int8> = [int8(67), int8(104), int8(101), int8(120), int8(32), int8(81), int8(117), int8(101), int8(115), int8(116), int8(0)]

var private c2da_str_17 : array<int8> = [int8(104), int8(97), int8(99), int8(120), int8(46), int8(119), int8(97), int8(100), int8(0)]

var private c2da_str_18 : array<int8> = [int8(72), int8(97), int8(99), int8(120), int8(0)]

var private c2da_str_19 : array<int8> = [int8(102), int8(114), int8(101), int8(101), int8(100), int8(109), int8(46), int8(119), int8(97), int8(100), int8(0)]

var private c2da_str_20 : array<int8> = [int8(70), int8(114), int8(101), int8(101), int8(68), int8(77), int8(0)]

var private c2da_str_21 : array<int8> = [int8(102), int8(114), int8(101), int8(101), int8(100), int8(111), int8(111), int8(109), int8(50), int8(46), int8(119), int8(97), int8(100), int8(0)]

var private c2da_str_22 : array<int8> = [int8(70), int8(114), int8(101), int8(101), int8(100), int8(111), int8(111), int8(109), int8(58), int8(32), int8(80), int8(104), int8(97), int8(115), int8(101), int8(32), int8(50), int8(0)]

var private c2da_str_23 : array<int8> = [int8(102), int8(114), int8(101), int8(101), int8(100), int8(111), int8(111), int8(109), int8(49), int8(46), int8(119), int8(97), int8(100), int8(0)]

var private c2da_str_24 : array<int8> = [int8(70), int8(114), int8(101), int8(101), int8(100), int8(111), int8(111), int8(109), int8(58), int8(32), int8(80), int8(104), int8(97), int8(115), int8(101), int8(32), int8(49), int8(0)]

var private c2da_str_25 : array<int8> = [int8(104), int8(101), int8(114), int8(101), int8(116), int8(105), int8(99), int8(46), int8(119), int8(97), int8(100), int8(0)]

var private c2da_str_26 : array<int8> = [int8(72), int8(101), int8(114), int8(101), int8(116), int8(105), int8(99), int8(0)]

var private c2da_str_27 : array<int8> = [int8(104), int8(101), int8(114), int8(101), int8(116), int8(105), int8(99), int8(49), int8(46), int8(119), int8(97), int8(100), int8(0)]

var private c2da_str_28 : array<int8> = [int8(72), int8(101), int8(114), int8(101), int8(116), int8(105), int8(99), int8(32), int8(83), int8(104), int8(97), int8(114), int8(101), int8(119), int8(97), int8(114), int8(101), int8(0)]

var private c2da_str_29 : array<int8> = [int8(104), int8(101), int8(120), int8(101), int8(110), int8(46), int8(119), int8(97), int8(100), int8(0)]

var private c2da_str_30 : array<int8> = [int8(72), int8(101), int8(120), int8(101), int8(110), int8(0)]

var private c2da_str_31 : array<int8> = [int8(115), int8(116), int8(114), int8(105), int8(102), int8(101), int8(49), int8(46), int8(119), int8(97), int8(100), int8(0)]

var private c2da_str_32 : array<int8> = [int8(83), int8(116), int8(114), int8(105), int8(102), int8(101), int8(0)]

var private c2da_str_33 : array<int8> = [int8(84), int8(114), int8(121), int8(105), int8(110), int8(103), int8(32), int8(73), int8(87), int8(65), int8(68), int8(32), int8(102), int8(105), int8(108), int8(101), int8(58), int8(37), int8(115), int8(10), int8(0)]

var private c2da_str_34 : array<int8> = [int8(117), int8(110), int8(107), int8(110), int8(111), int8(119), int8(110), int8(46), int8(119), int8(97), int8(100), int8(0)]

var private c2da_str_35 : array<int8> = [int8(85), int8(110), int8(107), int8(110), int8(111), int8(119), int8(110), int8(32), int8(103), int8(97), int8(109), int8(101), int8(63), int8(0)]

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
def D_FindWADByName(var name : int8?) : int8? {
    var path : int8?
    var i : int
    if (M_FileExists(name) != 0x0) {
        return unsafe(reinterpret<int8?>(name))
    }
    BuildIWADDirList()
    i = 0
    while (i < num_iwad_dirs) {
        if (DirIsFile(unsafe(reinterpret<int8?>(iwad_dirs[i])), name) != 0x0 && M_FileExists(unsafe(reinterpret<int8?>(iwad_dirs[i]))) != 0x0) {
            return unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(c2da_std_strdup(unsafe(reinterpret<uint64>(iwad_dirs[i])))))))
        }
        path = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(M_StringJoin(unsafe(reinterpret<int8 const?>(iwad_dirs[i])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_0[0]))))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(name))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(null)))])))))
        if (M_FileExists(path) != 0x0) {
            return unsafe(reinterpret<int8?>(path))
        }
        c2da_rt_free(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(path)))))
        i++
    }
    return unsafe(reinterpret<int8?>(null))
}
var private iwad_dirs : int8? [128]

[sideeffects]
def private DirIsFile(var path_0 : int8?; var filename : int8?) : uint {
    var path_len : uint64
    var filename_len : uint64
    path_len = c2da_std_strlen(unsafe(reinterpret<uint64>(path_0)))
    filename_len = c2da_std_strlen(unsafe(reinterpret<uint64>(filename)))
    return uint(path_len >= filename_len + 1ul && int(unsafe(path_0[int(path_len - filename_len - 1ul)])) == 47 && c2da_std_strcasecmp(unsafe(reinterpret<uint64>(unsafe(addr(unsafe(path_0[int(path_len - filename_len)]))))), unsafe(reinterpret<uint64>(filename))) == 0 ? 1 : 0)
}
var private num_iwad_dirs : int = 0

[sideeffects]
def private BuildIWADDirList() {
    AddIWADDir(unsafe(addr<int8?>(c2da_str_1[0])))
    iwad_dirs_built = 1u
    return
}
var private iwad_dirs_built : uint = 0u

[sideeffects]
def private AddIWADDir(var dir : int8?) {
    if (num_iwad_dirs < 128) {
        iwad_dirs[num_iwad_dirs] = unsafe(reinterpret<int8?>(dir))
        num_iwad_dirs++
    }
    return
}
[export, sideeffects]
def D_TryFindWADByName(var filename_0 : int8?) : int8? {
    var result_0 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(D_FindWADByName(filename_0)))))
    if (result_0 != null) {
        return unsafe(reinterpret<int8?>(result_0))
    } else {
        return unsafe(reinterpret<int8?>(filename_0))
    }
}
[export, sideeffects]
def D_FindIWAD(var mask : int; var mission : GameMission_t?) : int8? {
    var result_1 : int8?
    var iwadfile : int8?
    var iwadparm : int
    var i_0 : int
    iwadparm = M_CheckParmWithArgs(unsafe(addr<int8?>(c2da_str_2[0])), 1)
    if (iwadparm != 0) {
        iwadfile = unsafe(reinterpret<int8?>(unsafe(myargv[iwadparm + 1])))
        result_1 = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(D_FindWADByName(iwadfile)))))
        if (result_1 == null) {
            I_Error(unsafe(addr<int8?>(c2da_str_3[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(iwadfile)))])
        }
        *mission = IdentifyIWADByName(result_1, mask)
    } else {
        c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_4[0])), [])
        result_1 = null
        BuildIWADDirList()
        i_0 = 0
        while (result_1 == null && i_0 < num_iwad_dirs) {
            result_1 = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(SearchDirectoryForIWAD(unsafe(reinterpret<int8?>(iwad_dirs[i_0])), mask, mission)))))
            i_0++
        }
    }
    return unsafe(reinterpret<int8?>(result_1))
}
[sideeffects]
def private SearchDirectoryForIWAD(var dir_0 : int8?; var mask_0 : int; var mission_0 : GameMission_t?) : int8? {
    var filename_1 : int8?
    var i_1 : uint64 = 0ul
    while (i_1 < 336ul / 24ul) {
        if ((1 << int(uint(iwads[int(i_1)].mission)) & mask_0) == 0) {
            i_1++
            continue
        }
        filename_1 = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(CheckDirectoryHasIWAD(dir_0, unsafe(reinterpret<int8?>(iwads[int(i_1)].name)))))))
        if (filename_1 != null) {
            *mission_0 = iwads[int(i_1)].mission
            return unsafe(reinterpret<int8?>(filename_1))
        }
        i_1++
    }
    return unsafe(reinterpret<int8?>(null))
}
var private iwads : iwad_t[14] const = fixed_array<iwad_t>(iwad_t(name = unsafe(addr(c2da_str_5[0])), mission = unsafe(reinterpret<GameMission_t>(1u)), mode = unsafe(reinterpret<GameMode_t>(2u)), description = unsafe(addr(c2da_str_6[0]))), iwad_t(name = unsafe(addr(c2da_str_7[0])), mission = unsafe(reinterpret<GameMission_t>(3u)), mode = unsafe(reinterpret<GameMode_t>(2u)), description = unsafe(addr(c2da_str_8[0]))), iwad_t(name = unsafe(addr(c2da_str_9[0])), mission = unsafe(reinterpret<GameMission_t>(2u)), mode = unsafe(reinterpret<GameMode_t>(2u)), description = unsafe(addr(c2da_str_10[0]))), iwad_t(name = unsafe(addr(c2da_str_11[0])), mission = unsafe(reinterpret<GameMission_t>(0u)), mode = unsafe(reinterpret<GameMode_t>(3u)), description = unsafe(addr(c2da_str_12[0]))), iwad_t(name = unsafe(addr(c2da_str_13[0])), mission = unsafe(reinterpret<GameMission_t>(0u)), mode = unsafe(reinterpret<GameMode_t>(0u)), description = unsafe(addr(c2da_str_14[0]))), iwad_t(name = unsafe(addr(c2da_str_15[0])), mission = unsafe(reinterpret<GameMission_t>(4u)), mode = unsafe(reinterpret<GameMode_t>(0u)), description = unsafe(addr(c2da_str_16[0]))), iwad_t(name = unsafe(addr(c2da_str_17[0])), mission = unsafe(reinterpret<GameMission_t>(5u)), mode = unsafe(reinterpret<GameMode_t>(2u)), description = unsafe(addr(c2da_str_18[0]))), iwad_t(name = unsafe(addr(c2da_str_19[0])), mission = unsafe(reinterpret<GameMission_t>(1u)), mode = unsafe(reinterpret<GameMode_t>(2u)), description = unsafe(addr(c2da_str_20[0]))), iwad_t(name = unsafe(addr(c2da_str_21[0])), mission = unsafe(reinterpret<GameMission_t>(1u)), mode = unsafe(reinterpret<GameMode_t>(2u)), description = unsafe(addr(c2da_str_22[0]))), iwad_t(name = unsafe(addr(c2da_str_23[0])), mission = unsafe(reinterpret<GameMission_t>(0u)), mode = unsafe(reinterpret<GameMode_t>(3u)), description = unsafe(addr(c2da_str_24[0]))), iwad_t(name = unsafe(addr(c2da_str_25[0])), mission = unsafe(reinterpret<GameMission_t>(6u)), mode = unsafe(reinterpret<GameMode_t>(3u)), description = unsafe(addr(c2da_str_26[0]))), iwad_t(name = unsafe(addr(c2da_str_27[0])), mission = unsafe(reinterpret<GameMission_t>(6u)), mode = unsafe(reinterpret<GameMode_t>(0u)), description = unsafe(addr(c2da_str_28[0]))), iwad_t(name = unsafe(addr(c2da_str_29[0])), mission = unsafe(reinterpret<GameMission_t>(7u)), mode = unsafe(reinterpret<GameMode_t>(2u)), description = unsafe(addr(c2da_str_30[0]))), iwad_t(name = unsafe(addr(c2da_str_31[0])), mission = unsafe(reinterpret<GameMission_t>(8u)), mode = unsafe(reinterpret<GameMode_t>(2u)), description = unsafe(addr(c2da_str_32[0]))))

[sideeffects]
def private CheckDirectoryHasIWAD(var dir_1 : int8?; var iwadname : int8?) : int8? {
    var filename_2 : int8?
    if (DirIsFile(dir_1, iwadname) != 0x0 && M_FileExists(dir_1) != 0x0) {
        return unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(c2da_std_strdup(unsafe(reinterpret<uint64>(dir_1)))))))
    }
    if (c2da_std_strcmp(unsafe(reinterpret<uint64>(dir_1)), unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_1[0]))))) == 0) {
        filename_2 = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(c2da_std_strdup(unsafe(reinterpret<uint64>(iwadname)))))))
    } else {
        filename_2 = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(M_StringJoin(unsafe(reinterpret<int8 const?>(dir_1)), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_0[0]))))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(iwadname))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(null)))])))))
    }
    c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_33[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(filename_2)))])
    if (M_FileExists(filename_2) != 0x0) {
        return unsafe(reinterpret<int8?>(filename_2))
    }
    c2da_rt_free(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(filename_2)))))
    return unsafe(reinterpret<int8?>(null))
}
[sideeffects]
def private IdentifyIWADByName(var name_0 : int8?; var mask_1 : int) : GameMission_t {
    var i_2 : uint64
    var mission_1 : GameMission_t = GameMission_t()
    var p : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(c2da_std_strrchr(unsafe(reinterpret<uint64>(name_0)), 47)))))
    if (p != null) {
        name_0 = unsafe(reinterpret<int8?>(unsafe(p + 1)))
    }
    mission_1 = unsafe(reinterpret<GameMission_t>(9u))
    i_2 = 0ul
    while (i_2 < 336ul / 24ul) {
        if ((1 << int(uint(iwads[int(i_2)].mission)) & mask_1) == 0) {
            i_2++
            continue
        }
        if (c2da_std_strcasecmp(unsafe(reinterpret<uint64>(name_0)), unsafe(reinterpret<uint64>(iwads[int(i_2)].name))) == 0) {
            mission_1 = iwads[int(i_2)].mission
            break
        }
        i_2++
    }
    return mission_1
}
[export, sideeffects]
def D_FindAllIWADs(var mask_2 : int) : iwad_t const?? {
    var result_2 : iwad_t const??
    var result_len : int
    var filename_3 : int8?
    var i_3 : int
    result_2 = unsafe(reinterpret<iwad_t const??>(unsafe(reinterpret<iwad_t const??>(unsafe(reinterpret<uint8?>(c2da_rt_malloc(8ul * (336ul / 24ul + 1ul))))))))
    result_len = 0
    i_3 = 0
    while (uint64(i_3) < 336ul / 24ul) {
        if ((1 << int(uint(iwads[i_3].mission)) & mask_2) == 0) {
            i_3++
            continue
        }
        filename_3 = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(D_FindWADByName(unsafe(reinterpret<int8?>(iwads[i_3].name)))))))
        if (filename_3 != null) {
            unsafe(result_2[result_len]) = unsafe(addr<iwad_t const?>(unsafe(unsafe(addr(iwads[0]))[i_3])))
            result_len++
        }
        i_3++
    }
    unsafe(result_2[result_len]) = null
    return unsafe(reinterpret<iwad_t const??>(result_2))
}
[export, sideeffects]
def D_SaveGameIWADName(var gamemission : GameMission_t) : int8? {
    var i_4 : uint64 = 0ul
    while (i_4 < 336ul / 24ul) {
        if (uint(gamemission) == uint(iwads[int(i_4)].mission)) {
            return unsafe(reinterpret<int8?>(iwads[int(i_4)].name))
        }
        i_4++
    }
    return unsafe(addr<int8?>(c2da_str_34[0]))
}
[export, sideeffects]
def D_SuggestIWADName(var mission_2 : GameMission_t; var mode : GameMode_t) : int8? {
    var i_5 : int = 0
    while (uint64(i_5) < 336ul / 24ul) {
        if (uint(iwads[i_5].mission) == uint(mission_2) && uint(iwads[i_5].mode) == uint(mode)) {
            return unsafe(reinterpret<int8?>(iwads[i_5].name))
        }
        i_5++
    }
    return unsafe(addr<int8?>(c2da_str_34[0]))
}
[export, sideeffects]
def D_SuggestGameName(var mission_3 : GameMission_t; var mode_0 : GameMode_t) : int8? {
    var i_6 : int = 0
    while (uint64(i_6) < 336ul / 24ul) {
        if (uint(iwads[i_6].mission) == uint(mission_3) && (uint(mode_0) == 4u || uint(iwads[i_6].mode) == uint(mode_0))) {
            return unsafe(reinterpret<int8?>(iwads[i_6].description))
        }
        i_6++
    }
    return unsafe(addr<int8?>(c2da_str_35[0]))
}
[sideeffects]
def private c2da_layout_proofs() {
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
    static_assert(typeinfo sizeof(type<iwad_t>) == 24, "C layout of iwad_t: sizeof")
    static_assert(typeinfo alignof(type<iwad_t>) == 8, "C layout of iwad_t: alignof")
    static_assert(typeinfo offsetof<name>(type<iwad_t>) == 0, "C layout of iwad_t: offsetof name")
    static_assert(typeinfo offsetof<mission>(type<iwad_t>) == 8, "C layout of iwad_t: offsetof mission")
    static_assert(typeinfo offsetof<mode>(type<iwad_t>) == 12, "C layout of iwad_t: offsetof mode")
    static_assert(typeinfo offsetof<description>(type<iwad_t>) == 16, "C layout of iwad_t: offsetof description")
}
