options gen2
options stack = 4194304
module m_config public

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
var configdir : int

var private default_main_config : int

var private default_extra_config : int

[sideeffects]
def private SearchCollection(var collection : int; var name : int) : int {
    var i : int = 0
    while (i < int(uint(c2da_mem[collection + 8]) | uint(c2da_mem[collection + 9]) << 0x8 | uint(c2da_mem[collection + 10]) << 0x10 | uint(c2da_mem[collection + 11]) << 0x18)) {
        let c2da_fresh0 : int = int(uint(c2da_mem[collection]) | uint(c2da_mem[collection + 1]) << 0x8 | uint(c2da_mem[collection + 2]) << 0x10 | uint(c2da_mem[collection + 3]) << 0x18) + i * 32
        if (c2da_lin_strcmp(name, int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18)) == 0) {
            return int(uint(c2da_mem[collection]) | uint(c2da_mem[collection + 1]) << 0x8 | uint(c2da_mem[collection + 2]) << 0x10 | uint(c2da_mem[collection + 3]) << 0x18) + i * 32
        }
        i++
    }
    return 0
}
var private scantokey : int[128] const = fixed_array<int>(0, 27, 49, 50, 51, 52, 53, 54, 55, 56, 57, 48, 45, 61, 127, 9, 113, 119, 101, 114, 116, 121, 117, 105, 111, 112, 91, 93, 13, 128 + 29, 97, 115, 100, 102, 103, 104, 106, 107, 108, 59, 39, 96, 128 + 54, 92, 122, 120, 99, 118, 98, 110, 109, 44, 46, 47, 128 + 54, 42, 128 + 56, 32, 128 + 58, 128 + 59, 128 + 60, 128 + 61, 128 + 62, 128 + 63, 128 + 64, 128 + 65, 128 + 66, 128 + 67, 128 + 68, 255, 128 + 70, 128 + 71, 173, 128 + 73, 45, 172, 53, 174, 43, 128 + 79, 175, 128 + 81, 128 + 82, 128 + 83, 0, 0, 0, 128 + 87, 128 + 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128 + 89, 0)

[sideeffects]
def private SaveDefaultCollection(var collection_0 : int) {
    return
}
[sideeffects]
def private ParseIntParameter(var strparm : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = ParseIntParameter_c2da_frame(strparm, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[sideeffects]
def private SetVariable(var def_0 : int; var value : int) {
    var c2da_fresh1 : uint
    var intparm : int
    c2da_fresh1 = uint(c2da_mem[def_0 + 16]) | uint(c2da_mem[def_0 + 17]) << 0x8 | uint(c2da_mem[def_0 + 18]) << 0x10 | uint(c2da_mem[def_0 + 19]) << 0x18
    if (c2da_fresh1 == 0x2u) {
        let c2da_fresh2 : int = int(uint(c2da_mem[def_0 + 8]) | uint(c2da_mem[def_0 + 9]) << 0x8 | uint(c2da_mem[def_0 + 10]) << 0x10 | uint(c2da_mem[def_0 + 11]) << 0x18)
        let c2da_fresh3 : int = c2da_lin_strdup(value)
        let c2da_fresh4 : uint = uint(c2da_fresh3)
        c2da_mem[c2da_fresh2] = uint8(c2da_fresh4)
        c2da_mem[c2da_fresh2 + 1] = uint8(c2da_fresh4 >> 0x8)
        c2da_mem[c2da_fresh2 + 2] = uint8(c2da_fresh4 >> 0x10)
        c2da_mem[c2da_fresh2 + 3] = uint8(c2da_fresh4 >> 0x18)
        c2da_mem[c2da_fresh2 + 4] = 0u8
        c2da_mem[c2da_fresh2 + 5] = 0u8
        c2da_mem[c2da_fresh2 + 6] = 0u8
        c2da_mem[c2da_fresh2 + 7] = 0u8
    } elif (c2da_fresh1 == 0x0u || c2da_fresh1 == 0x1u) {
        let c2da_fresh5 : int = int(uint(c2da_mem[def_0 + 8]) | uint(c2da_mem[def_0 + 9]) << 0x8 | uint(c2da_mem[def_0 + 10]) << 0x10 | uint(c2da_mem[def_0 + 11]) << 0x18)
        let c2da_fresh6 : int = ParseIntParameter(value)
        let c2da_fresh7 : uint = uint(c2da_fresh6)
        c2da_mem[c2da_fresh5] = uint8(c2da_fresh7)
        c2da_mem[c2da_fresh5 + 1] = uint8(c2da_fresh7 >> 0x8)
        c2da_mem[c2da_fresh5 + 2] = uint8(c2da_fresh7 >> 0x10)
        c2da_mem[c2da_fresh5 + 3] = uint8(c2da_fresh7 >> 0x18)
    } elif (c2da_fresh1 == 0x4u) {
        intparm = ParseIntParameter(value)
        let c2da_fresh8 : uint = uint(intparm)
        c2da_mem[def_0 + 20] = uint8(c2da_fresh8)
        c2da_mem[def_0 + 21] = uint8(c2da_fresh8 >> 0x8)
        c2da_mem[def_0 + 22] = uint8(c2da_fresh8 >> 0x10)
        c2da_mem[def_0 + 23] = uint8(c2da_fresh8 >> 0x18)
        if (intparm >= 0 && intparm < 128) {
            intparm = scantokey[intparm]
        } else {
            intparm = 0
        }
        let c2da_fresh9 : uint = uint(intparm)
        c2da_mem[def_0 + 24] = uint8(c2da_fresh9)
        c2da_mem[def_0 + 25] = uint8(c2da_fresh9 >> 0x8)
        c2da_mem[def_0 + 26] = uint8(c2da_fresh9 >> 0x10)
        c2da_mem[def_0 + 27] = uint8(c2da_fresh9 >> 0x18)
        let c2da_fresh10 : int = int(uint(c2da_mem[def_0 + 8]) | uint(c2da_mem[def_0 + 9]) << 0x8 | uint(c2da_mem[def_0 + 10]) << 0x10 | uint(c2da_mem[def_0 + 11]) << 0x18)
        let c2da_fresh11 : uint = uint(intparm)
        c2da_mem[c2da_fresh10] = uint8(c2da_fresh11)
        c2da_mem[c2da_fresh10 + 1] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[c2da_fresh10 + 2] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[c2da_fresh10 + 3] = uint8(c2da_fresh11 >> 0x18)
    } elif (c2da_fresh1 == 0x3u) {
        let c2da_fresh12 : int = int(uint(c2da_mem[def_0 + 8]) | uint(c2da_mem[def_0 + 9]) << 0x8 | uint(c2da_mem[def_0 + 10]) << 0x10 | uint(c2da_mem[def_0 + 11]) << 0x18)
        let c2da_fresh13 : float = float(c2da_lin_atof(value))
        let c2da_fresh14 : uint = float_bits_to_uint(c2da_fresh13)
        c2da_mem[c2da_fresh12] = uint8(c2da_fresh14)
        c2da_mem[c2da_fresh12 + 1] = uint8(c2da_fresh14 >> 0x8)
        c2da_mem[c2da_fresh12 + 2] = uint8(c2da_fresh14 >> 0x10)
        c2da_mem[c2da_fresh12 + 3] = uint8(c2da_fresh14 >> 0x18)
    }
    return
}
[sideeffects]
def private LoadDefaultCollection(var collection_1 : int) {
    return
}
[export, sideeffects]
def M_SetConfigFilenames(var main_config : int; var extra_config : int) {
    default_main_config = int(main_config)  // nolint:PERF020
    default_extra_config = int(extra_config)  // nolint:PERF020
    return
}
[export, sideeffects]
def M_SaveDefaults() {
    SaveDefaultCollection(352704)
    SaveDefaultCollection(352736)
    return
}
[export, sideeffects]
def M_SaveDefaultsAlternate(var main_0 : int; var extra : int) {
    var orig_main : int
    var orig_extra : int
    orig_main = int(uint(c2da_mem[352720]) | uint(c2da_mem[352721]) << 0x8 | uint(c2da_mem[352722]) << 0x10 | uint(c2da_mem[352723]) << 0x18)
    orig_extra = int(uint(c2da_mem[352752]) | uint(c2da_mem[352753]) << 0x8 | uint(c2da_mem[352754]) << 0x10 | uint(c2da_mem[352755]) << 0x18)
    let c2da_fresh15 : uint = uint(main_0)
    c2da_mem[352720] = uint8(c2da_fresh15)
    c2da_mem[352721] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[352722] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[352723] = uint8(c2da_fresh15 >> 0x18)
    c2da_mem[352724] = 0u8
    c2da_mem[352725] = 0u8
    c2da_mem[352726] = 0u8
    c2da_mem[352727] = 0u8
    let c2da_fresh16 : uint = uint(extra)
    c2da_mem[352752] = uint8(c2da_fresh16)
    c2da_mem[352753] = uint8(c2da_fresh16 >> 0x8)
    c2da_mem[352754] = uint8(c2da_fresh16 >> 0x10)
    c2da_mem[352755] = uint8(c2da_fresh16 >> 0x18)
    c2da_mem[352756] = 0u8
    c2da_mem[352757] = 0u8
    c2da_mem[352758] = 0u8
    c2da_mem[352759] = 0u8
    M_SaveDefaults()
    let c2da_fresh17 : uint = uint(orig_main)
    c2da_mem[352720] = uint8(c2da_fresh17)
    c2da_mem[352721] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[352722] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[352723] = uint8(c2da_fresh17 >> 0x18)
    c2da_mem[352724] = 0u8
    c2da_mem[352725] = 0u8
    c2da_mem[352726] = 0u8
    c2da_mem[352727] = 0u8
    let c2da_fresh18 : uint = uint(orig_extra)
    c2da_mem[352752] = uint8(c2da_fresh18)
    c2da_mem[352753] = uint8(c2da_fresh18 >> 0x8)
    c2da_mem[352754] = uint8(c2da_fresh18 >> 0x10)
    c2da_mem[352755] = uint8(c2da_fresh18 >> 0x18)
    c2da_mem[352756] = 0u8
    c2da_mem[352757] = 0u8
    c2da_mem[352758] = 0u8
    c2da_mem[352759] = 0u8
    return
}
[export, sideeffects]
def M_LoadDefaults() {
    var i_0 : int = M_CheckParmWithArgs(355730, 1)
    if (i_0 != 0) {
        let c2da_fresh19 : int = int(uint(c2da_mem[myargv + (i_0 + 1) * 8]) | uint(c2da_mem[myargv + (i_0 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (i_0 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (i_0 + 1) * 8 + 3]) << 0x18)
        let c2da_fresh20 : uint = uint(c2da_fresh19)
        c2da_mem[352720] = uint8(c2da_fresh20)
        c2da_mem[352721] = uint8(c2da_fresh20 >> 0x8)
        c2da_mem[352722] = uint8(c2da_fresh20 >> 0x10)
        c2da_mem[352723] = uint8(c2da_fresh20 >> 0x18)
        c2da_mem[352724] = 0u8
        c2da_mem[352725] = 0u8
        c2da_mem[352726] = 0u8
        c2da_mem[352727] = 0u8
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 355738, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[352720]) | uint(c2da_mem[352721]) << 0x8 | uint(c2da_mem[352722]) << 0x10 | uint(c2da_mem[352723]) << 0x18)))])
    } else {
        let c2da_fresh21 : int = M_StringJoin(configdir, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(default_main_config)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 0ul)])
        let c2da_fresh22 : uint = uint(c2da_fresh21)
        c2da_mem[352720] = uint8(c2da_fresh22)
        c2da_mem[352721] = uint8(c2da_fresh22 >> 0x8)
        c2da_mem[352722] = uint8(c2da_fresh22 >> 0x10)
        c2da_mem[352723] = uint8(c2da_fresh22 >> 0x18)
        c2da_mem[352724] = 0u8
        c2da_mem[352725] = 0u8
        c2da_mem[352726] = 0u8
        c2da_mem[352727] = 0u8
    }
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 355757, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[352720]) | uint(c2da_mem[352721]) << 0x8 | uint(c2da_mem[352722]) << 0x10 | uint(c2da_mem[352723]) << 0x18)))])
    i_0 = M_CheckParmWithArgs(355778, 1)
    if (i_0 != 0) {
        let c2da_fresh23 : int = int(uint(c2da_mem[myargv + (i_0 + 1) * 8]) | uint(c2da_mem[myargv + (i_0 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (i_0 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (i_0 + 1) * 8 + 3]) << 0x18)
        let c2da_fresh24 : uint = uint(c2da_fresh23)
        c2da_mem[352752] = uint8(c2da_fresh24)
        c2da_mem[352753] = uint8(c2da_fresh24 >> 0x8)
        c2da_mem[352754] = uint8(c2da_fresh24 >> 0x10)
        c2da_mem[352755] = uint8(c2da_fresh24 >> 0x18)
        c2da_mem[352756] = 0u8
        c2da_mem[352757] = 0u8
        c2da_mem[352758] = 0u8
        c2da_mem[352759] = 0u8
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 355791, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[352752]) | uint(c2da_mem[352753]) << 0x8 | uint(c2da_mem[352754]) << 0x10 | uint(c2da_mem[352755]) << 0x18)))])
    } else {
        let c2da_fresh25 : int = M_StringJoin(configdir, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(default_extra_config)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 0ul)])
        let c2da_fresh26 : uint = uint(c2da_fresh25)
        c2da_mem[352752] = uint8(c2da_fresh26)
        c2da_mem[352753] = uint8(c2da_fresh26 >> 0x8)
        c2da_mem[352754] = uint8(c2da_fresh26 >> 0x10)
        c2da_mem[352755] = uint8(c2da_fresh26 >> 0x18)
        c2da_mem[352756] = 0u8
        c2da_mem[352757] = 0u8
        c2da_mem[352758] = 0u8
        c2da_mem[352759] = 0u8
    }
    LoadDefaultCollection(352704)
    LoadDefaultCollection(352736)
    return
}
[sideeffects]
def private GetDefaultForName(var name_0 : int) : int {
    var result_0 : int = SearchCollection(352704, name_0)
    if (result_0 == 0) {
        result_0 = SearchCollection(352736, name_0)
    }
    if (result_0 == 0) {
        I_Error(355829, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(name_0))])
    }
    return result_0
}
[export, sideeffects]
def M_BindVariable(var name_1 : int; var location : int) {
    var variable : int = GetDefaultForName(name_1)
    let c2da_fresh27 : uint = uint(location)
    c2da_mem[variable + 8] = uint8(c2da_fresh27)
    c2da_mem[variable + 9] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[variable + 10] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[variable + 11] = uint8(c2da_fresh27 >> 0x18)
    c2da_mem[variable + 12] = 0u8
    c2da_mem[variable + 13] = 0u8
    c2da_mem[variable + 14] = 0u8
    c2da_mem[variable + 15] = 0u8
    let c2da_fresh28 : uint = 1u
    let c2da_fresh29 : uint = c2da_fresh28
    c2da_mem[variable + 28] = uint8(c2da_fresh29)
    c2da_mem[variable + 29] = uint8(c2da_fresh29 >> 0x8)
    c2da_mem[variable + 30] = uint8(c2da_fresh29 >> 0x10)
    c2da_mem[variable + 31] = uint8(c2da_fresh29 >> 0x18)
    return
}
[export, sideeffects]
def M_SetVariable(var name_2 : int; var value_0 : int) : uint {
    var variable_0 : int = GetDefaultForName(name_2)
    if (variable_0 == 0 || (uint(c2da_mem[variable_0 + 28]) | uint(c2da_mem[variable_0 + 29]) << 0x8 | uint(c2da_mem[variable_0 + 30]) << 0x10 | uint(c2da_mem[variable_0 + 31]) << 0x18) == 0) {
        return 0u
    }
    SetVariable(variable_0, value_0)
    return 1u
}
[export, sideeffects]
def M_GetIntVariable(var name_3 : int) : int {
    var variable_1 : int = GetDefaultForName(name_3)
    if (variable_1 == 0 || (uint(c2da_mem[variable_1 + 28]) | uint(c2da_mem[variable_1 + 29]) << 0x8 | uint(c2da_mem[variable_1 + 30]) << 0x10 | uint(c2da_mem[variable_1 + 31]) << 0x18) == 0 || (uint(c2da_mem[variable_1 + 16]) | uint(c2da_mem[variable_1 + 17]) << 0x8 | uint(c2da_mem[variable_1 + 18]) << 0x10 | uint(c2da_mem[variable_1 + 19]) << 0x18) != 0u && (uint(c2da_mem[variable_1 + 16]) | uint(c2da_mem[variable_1 + 17]) << 0x8 | uint(c2da_mem[variable_1 + 18]) << 0x10 | uint(c2da_mem[variable_1 + 19]) << 0x18) != 1u) {
        return 0
    }
    let c2da_fresh30 : int = int(uint(c2da_mem[variable_1 + 8]) | uint(c2da_mem[variable_1 + 9]) << 0x8 | uint(c2da_mem[variable_1 + 10]) << 0x10 | uint(c2da_mem[variable_1 + 11]) << 0x18)
    return int(uint(c2da_mem[c2da_fresh30]) | uint(c2da_mem[c2da_fresh30 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh30 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh30 + 3]) << 0x18)
}
[export, sideeffects]
def M_GetStrVariable(var name_4 : int) : int {
    var variable_2 : int = GetDefaultForName(name_4)
    if (variable_2 == 0 || (uint(c2da_mem[variable_2 + 28]) | uint(c2da_mem[variable_2 + 29]) << 0x8 | uint(c2da_mem[variable_2 + 30]) << 0x10 | uint(c2da_mem[variable_2 + 31]) << 0x18) == 0 || (uint(c2da_mem[variable_2 + 16]) | uint(c2da_mem[variable_2 + 17]) << 0x8 | uint(c2da_mem[variable_2 + 18]) << 0x10 | uint(c2da_mem[variable_2 + 19]) << 0x18) != 2u) {
        return 0
    }
    let c2da_fresh31 : int = int(uint(c2da_mem[variable_2 + 8]) | uint(c2da_mem[variable_2 + 9]) << 0x8 | uint(c2da_mem[variable_2 + 10]) << 0x10 | uint(c2da_mem[variable_2 + 11]) << 0x18)
    return int(uint(c2da_mem[c2da_fresh31]) | uint(c2da_mem[c2da_fresh31 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh31 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh31 + 3]) << 0x18)
}
[export, sideeffects]
def M_GetFloatVariable(var name_5 : int) : float {
    var variable_3 : int = GetDefaultForName(name_5)
    if (variable_3 == 0 || (uint(c2da_mem[variable_3 + 28]) | uint(c2da_mem[variable_3 + 29]) << 0x8 | uint(c2da_mem[variable_3 + 30]) << 0x10 | uint(c2da_mem[variable_3 + 31]) << 0x18) == 0 || (uint(c2da_mem[variable_3 + 16]) | uint(c2da_mem[variable_3 + 17]) << 0x8 | uint(c2da_mem[variable_3 + 18]) << 0x10 | uint(c2da_mem[variable_3 + 19]) << 0x18) != 3u) {
        return 0.0
    }
    let c2da_fresh32 : int = int(uint(c2da_mem[variable_3 + 8]) | uint(c2da_mem[variable_3 + 9]) << 0x8 | uint(c2da_mem[variable_3 + 10]) << 0x10 | uint(c2da_mem[variable_3 + 11]) << 0x18)
    return uint_bits_to_float(uint(c2da_mem[c2da_fresh32]) | uint(c2da_mem[c2da_fresh32 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh32 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh32 + 3]) << 0x18)
}
[sideeffects]
def private GetDefaultConfigDir() : int {
    var result_1 : int = c2da_lin_malloc(2ul)
    let c2da_fresh33 : int8 = int8(46)
    c2da_mem[result_1 + 0] = uint8(c2da_fresh33)
    let c2da_fresh34 : int8 = int8(0)
    c2da_mem[result_1 + 1] = uint8(c2da_fresh34)
    return result_1
}
[export, sideeffects]
def M_SetConfigDir(var dir : int) {
    if (dir != 0) {
        configdir = int(dir)  // nolint:PERF020
    } else {
        configdir = GetDefaultConfigDir()
    }
    if (c2da_lin_strcmp(configdir, 355866) != 0) {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 355867, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(configdir))])
    }
    M_MakeDirectory(configdir)
    return
}
[export, sideeffects]
def M_GetSaveGameDir(var iwadname : int) : int {
    var savegamedir : int
    if (c2da_lin_strcmp(configdir, 355866) == 0) {
        savegamedir = c2da_lin_strdup(355866)
    } else {
        savegamedir = M_StringJoin(configdir, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 355905ul), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 355907ul), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 0ul)])
        M_MakeDirectory(savegamedir)
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 355918, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(savegamedir))])
    }
    return savegamedir
}
[sideeffects]
def private ParseIntParameter_c2da_frame(var strparm : int; c2da_fp : int) : int {
    if (int(int8(c2da_mem[strparm + 0])) == 48 && int(int8(c2da_mem[strparm + 1])) == 120) {
        c2da_lin_sscanf(strparm + 2, 355724, c2da_fp, 0, 0, 0)
    } else {
        c2da_lin_sscanf(strparm, 355727, c2da_fp, 0, 0, 0)
    }
    return int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18)
}

// This unit's static data, at heap offset 346304.
let private c2da_lin_static_m_config_seg = fixed_array<int>(346304, 3, 346336, 3, 346368, 3, 346400, 3, 346432, 3, 346464, 3, 346496, 1059, 347584, 3, 347616, 3, 347648, 3, 347680, 3, 347712, 3, 347744, 3, 347776, 3, 347808, 3, 347840, 3, 347872, 3, 347904, 3, 347936, 3, 347968, 3, 348000, 3, 348032, 3, 348064, 3, 348096, 3, 348128, 3, 348160, 3, 348192, 3, 348224, 3, 348256, 35, 348320, 387, 348736, 3, 348768, 3, 348800, 3, 348832, 3, 348864, 3, 348896, 3, 348928, 3, 348960, 3, 348992, 3, 349024, 3, 349056, 35, 349120, 3, 349152, 3, 349184, 3, 349216, 67, 349312, 3, 349344, 3, 349376, 3, 349408, 3, 349440, 67, 349536, 3, 349568, 3, 349600, 3, 349632, 3, 349664, 3, 349696, 3, 349728, 3, 349760, 3, 349792, 3, 349824, 3, 349856, 3, 349888, 3, 349920, 3, 349952, 3, 349984, 3, 350016, 3, 350048, 3, 350080, 3, 350112, 3, 350144, 3, 350176, 3, 350208, 3, 350240, 3, 350272, 3, 350304, 3, 350336, 3, 350368, 3, 350400, 3, 350432, 3, 350464, 99, 350592, 2121, 352736, 3205)
let private c2da_lin_static_m_config = fixed_array<uint64>(0x621505620a0561f8ul, 0x3905622c05622205ul, 0x562470562ul, 0x0ul, 0x40000ul, 0x0ul, 0x562510000ul, 0x0ul, 0x40000ul, 0x0ul, 0x5625a0000ul, 0x0ul, 0x40000ul, 0x0ul, 0x562610000ul, 0x0ul, 0x40000ul, 0x0ul, 0x5626a0000ul, 0x0ul, 0x40000ul, 0x0ul, 0x562790000ul, 0x0ul, 0x40000ul, 0x0ul, 0x562890000ul, 0x0ul, 0x40000ul, 0x0ul, 0x562970000ul, 0x0ul, 0x40000ul, 0x0ul, 0x562a00000ul, 0x0ul, 0x40000ul, 0x0ul, 0x562aa0000ul, 0x0ul, 0x40000ul, 0x0ul, 0x562b60000ul, 0x0ul, 0x40000ul, 0x0ul, 0x562c40000ul, 0x0ul, 0x40000ul, 0x0ul, 0x562cf0000ul, 0x0ul, 0x40000ul, 0x0ul, 0x562dc0000ul, 0x0ul, 0x40000ul, 0x0ul, 0x562eb0000ul, 0x0ul, 0x40000ul, 0x0ul, 0x562f80000ul, 0x0ul, 0x40000ul, 0x0ul, 0x563040000ul, 0x0ul, 0x40000ul, 0x0ul, 0x5630f0000ul, 0x0ul, 0x40000ul, 0x0ul, 0x5631a0000ul, 0x0ul, 0x40000ul, 0x0ul, 0x563260000ul, 0x0ul, 0x40000ul, 0x0ul, 0x563310000ul, 0x0ul, 0x40000ul, 0x0ul, 0x5633d0000ul, 0x0ul, 0x40000ul, 0x0ul, 0x5634a0000ul, 0x0ul, 0x40000ul, 0x0ul, 0x563560000ul, 0x0ul, 0x40000ul, 0x0ul, 0x563630000ul, 0x0ul, 0x40000ul, 0x0ul, 0x563730000ul, 0x0ul, 0x40000ul, 0x0ul, 0x5637e0000ul, 0x0ul, 0x40000ul, 0x0ul, 0x5638a0000ul, 0x0ul, 0x40000ul, 0x0ul, 0x563950000ul, 0x0ul, 0x40000ul, 0x0ul, 0x563a20000ul, 0x0ul, 0x40000ul, 0x0ul, 0x563ab0000ul, 0x0ul, 0x40000ul, 0x0ul, 0x563b30000ul, 0x0ul, 0x40000ul, 0x0ul, 0x563be0000ul, 0x0ul, 0x40000ul, 0x0ul, 0x563d20563c80000ul, 0x63fb0563ec0563deul, 0x1e05641405640705ul, 0x5643305642a0564ul, 0x645505644805643eul, 0x7905646c05646005ul, 0x564970564890564ul, 0x64b60564ac0564a2ul, 0x564c90564c005ul, 0x0ul, 0x200000000ul, 0x0ul, 0xdc0564d100000000ul, 0x564ul, 0x200000000000000ul, 0x0ul, 0xe600000000000000ul, 0x564ul, 0x200000000000000ul, 0x0ul, 0xef00000000000000ul, 0x564ul, 0x200000000000000ul, 0x0ul, 0xfa00000000000000ul, 0x564ul, 0x200000000000000ul, 0x0ul, 0x500000000000000ul, 0x565ul, 0x200000000000000ul, 0x0ul, 0x1000000000000000ul, 0x565ul, 0x200000000000000ul, 0x0ul, 0x1b00000000000000ul, 0x565ul, 0x200000000000000ul, 0x0ul, 0x2600000000000000ul, 0x565ul, 0x200000000000000ul, 0x0ul, 0x3100000000000000ul, 0x565ul, 0x200000000000000ul, 0x0ul, 0x3c00000000000000ul, 0x565ul, 0x200000000000000ul, 0x0ul, 0x4700000000000000ul, 0x565ul, 0x200000000000000ul, 0x0ul, 0x5200000000000000ul, 0x565ul, 0x200000000000000ul, 0x0ul, 0x5d00000000000000ul, 0x565770565650565ul, 0x65b105659c056591ul, 0xda0565cc0565bf05ul, 0x565ef0565e50565ul, 0x565f6ul, 0x0ul, 0x3ul, 0x0ul, 0x6628056619056609ul, 0x5664a05663605ul, 0x0ul, 0x200000000ul, 0x0ul, 0x5665700000000ul, 0x0ul, 0x100000000ul, 0x0ul, 0x6f05666300000000ul, 0x5669605667f0566ul, 0x566c20566a9ul, 0x0ul, 0x2000000ul, 0x0ul, 0x566cf000000ul, 0x0ul, 0x2000000ul, 0x0ul, 0x66ee0566df000000ul, 0x200567100566fe05ul, 0x567470567320567ul, 0x679205677805675eul, 0xe00567c60567ac05ul, 0x568140567fa0567ul, 0x686205684805682eul, 0x9605688305687205ul, 0x568b60568a60568ul, 0x68e60568db0568c8ul, 0x1a0569080568f605ul, 0x569370569250569ul, 0x0ul, 0x30000000000ul, 0x0ul, 0x5694b0000000000ul, 0x0ul, 0x20000000000ul, 0x0ul, 0x5695d0000000000ul, 0x0ul, 0x20000000000ul, 0x0ul, 0x5696c0000000000ul, 0x56977ul, 0x0ul, 0x4ul, 0x0ul, 0x56981ul, 0x0ul, 0x4ul, 0x0ul, 0x56993ul, 0x0ul, 0x4ul, 0x0ul, 0x5699ful, 0x0ul, 0x4ul, 0x0ul, 0x569adul, 0x0ul, 0x4ul, 0x0ul, 0x569bbul, 0x0ul, 0x4ul, 0x0ul, 0x569caul, 0x0ul, 0x4ul, 0x0ul, 0x569d8ul, 0x0ul, 0x4ul, 0x0ul, 0x569e9ul, 0x0ul, 0x4ul, 0x0ul, 0x569faul, 0x0ul, 0x4ul, 0x0ul, 0x56a09ul, 0x0ul, 0x4ul, 0x0ul, 0x56a17ul, 0x0ul, 0x4ul, 0x0ul, 0x56a25ul, 0x0ul, 0x4ul, 0x0ul, 0x56a33ul, 0x0ul, 0x4ul, 0x0ul, 0x56a43ul, 0x0ul, 0x4ul, 0x0ul, 0x56a53ul, 0x0ul, 0x4ul, 0x0ul, 0x56a62ul, 0x0ul, 0x4ul, 0x0ul, 0x56a73ul, 0x0ul, 0x4ul, 0x0ul, 0x56a85ul, 0x0ul, 0x4ul, 0x0ul, 0x56a94ul, 0x0ul, 0x4ul, 0x0ul, 0x56aa2ul, 0x0ul, 0x4ul, 0x0ul, 0x56ab1ul, 0x0ul, 0x4ul, 0x0ul, 0x56ab9ul, 0x0ul, 0x4ul, 0x0ul, 0x56accul, 0x0ul, 0x4ul, 0x0ul, 0x56adful, 0x0ul, 0x4ul, 0x0ul, 0x56af3ul, 0x0ul, 0x4ul, 0x0ul, 0x56b02ul, 0x0ul, 0x4ul, 0x0ul, 0x56b10ul, 0x0ul, 0x4ul, 0x0ul, 0x56b1eul, 0x0ul, 0x4ul, 0x0ul, 0x56b2bul, 0x0ul, 0x4ul, 0x0ul, 0x56b38ul, 0x0ul, 0x4ul, 0x0ul, 0x56b47ul, 0x0ul, 0x4ul, 0x0ul, 0x56b57ul, 0x0ul, 0x4ul, 0x0ul, 0x56b67ul, 0x0ul, 0x4ul, 0x0ul, 0x56b76ul, 0x0ul, 0x4ul, 0x0ul, 0x56b83ul, 0x0ul, 0x4ul, 0x0ul, 0x56b90ul, 0x0ul, 0x4ul, 0x0ul, 0x56ba2ul, 0x0ul, 0x4ul, 0x0ul, 0x56baeul, 0x0ul, 0x4ul, 0x0ul, 0x56bbaul, 0x0ul, 0x4ul, 0x0ul, 0x56bc6ul, 0x0ul, 0x4ul, 0x0ul, 0x56bd2ul, 0x0ul, 0x4ul, 0x0ul, 0x56bdeul, 0x0ul, 0x4ul, 0x0ul, 0x56beaul, 0x0ul, 0x4ul, 0x0ul, 0x56bf6ul, 0x0ul, 0x4ul, 0x0ul, 0x56c02ul, 0x0ul, 0x4ul, 0x0ul, 0x56c11ul, 0x0ul, 0x4ul, 0x0ul, 0x56c20ul, 0x0ul, 0x4ul, 0x0ul, 0x56c2dul, 0x0ul, 0x4ul, 0x0ul, 0x56c3dul, 0x0ul, 0x4ul, 0x0ul, 0x56c50ul, 0x0ul, 0x4ul, 0x0ul, 0x56c65ul, 0x0ul, 0x4ul, 0x0ul, 0x56c77ul, 0x0ul, 0x4ul, 0x0ul, 0x56c8eul, 0x0ul, 0x4ul, 0x0ul, 0x56c9bul, 0x0ul, 0x4ul, 0x0ul, 0x56cb4ul, 0x0ul, 0x4ul, 0x0ul, 0x56cc8ul, 0x0ul, 0x4ul, 0x0ul, 0x56cd6ul, 0x0ul, 0x4ul, 0x0ul, 0x56ce4ul, 0x0ul, 0x4ul, 0x0ul, 0x56cf9ul, 0x0ul, 0x4ul, 0x0ul, 0x56d0eul, 0x0ul, 0x4ul, 0x0ul, 0x56d23ul, 0x0ul, 0x4ul, 0x0ul, 0x56d38ul, 0x0ul, 0x4ul, 0x0ul, 0x56d4dul, 0x0ul, 0x4ul, 0x0ul, 0x56d62ul, 0x0ul, 0x4ul, 0x0ul, 0x56d77ul, 0x0ul, 0x4ul, 0x0ul, 0x548c0ul, 0x552404cul, 0x7c00ul, 0x0ul, 0x735f6573756f6d00ul, 0x6976697469736e65ul, 0x765f786673007974ul, 0x756d00656d756c6ful, 0x756c6f765f636973ul, 0x5f776f687300656dul, 0x696f76006b6c6174ul, 0x6d756c6f765f6563ul, 0x6d5f776f68730065ul, 0x73656761737365ul, 0x686769725f79656bul, 0x656c5f79656b0074ul, 0x755f79656b007466ul, 0x6f645f79656b0070ul, 0x735f79656b006e77ul, 0x66656c6566617274ul, 0x74735f79656b0074ul, 0x6867697265666172ul, 0x73755f79656b0074ul, 0x68746c61654865ul, 0x706d756a5f79656bul, 0x796c665f79656b00ul, 0x665f79656b007075ul, 0x6b006e776f64796cul, 0x6563796c665f7965ul, 0x79656b007265746eul, 0x70756b6f6f6c5ful, 0x6b6f6f6c5f79656bul, 0x79656b006e776f64ul, 0x6e65636b6f6f6c5ful, 0x5f79656b00726574ul, 0x7972657571766e69ul, 0x73696d5f79656b00ul, 0x79656b006e6f6973ul, 0x706f50766e695ful, 0x4b766e695f79656bul, 0x695f79656b007965ul, 0x6b00656d6f48766eul, 0x6e45766e695f7965ul, 0x6e695f79656b0064ul, 0x656b007466656c76ul, 0x676972766e695f79ul, 0x695f79656b007468ul, 0x6b007466654c766eul, 0x6952766e695f7965ul, 0x5f79656b00746867ul, 0x6669747261657375ul, 0x5f79656b00746361ul, 0x6b00657355766e69ul, 0x7244766e695f7965ul, 0x6c5f79656b00706ful, 0x656b0070556b6f6ful, 0x6f446b6f6f6c5f79ul, 0x665f79656b006e77ul, 0x5f79656b00657269ul, 0x5f79656b00657375ul, 0x6b00656661727473ul, 0x64656570735f7965ul, 0x756f6d5f65737500ul, 0x6573756f6d006573ul, 0x6d00657269665f62ul, 0x74735f626573756ful, 0x756f6d0065666172ul, 0x77726f665f626573ul, 0x73756f6d00647261ul, 0x706d756a5f6265ul, 0x73796f6a5f657375ul, 0x796f6a006b636974ul, 0x6a00657269665f62ul, 0x617274735f62796ful, 0x5f62796f6a006566ul, 0x62796f6a00657375ul, 0x6a0064656570735ful, 0x706d756a5f62796ful, 0x626e656572637300ul, 0x637300736b636f6cul, 0x657a69736e656572ul, 0x6c6c696174656400ul, 0x646e73006c657665ul, 0x6c656e6e6168635ful, 0x756d5f646e730073ul, 0x6369766564636973ul, 0x66735f646e730065ul, 0x65636976656478ul, 0x6f7062735f646e73ul, 0x735f646e73007472ul, 0x646e730071726962ul, 0x7300616d6462735ful, 0x74726f706d5f646eul, 0x6d6d616765737500ul, 0x6964657661730061ul, 0x67617373656d0072ul, 0x636162006e6f7365ul, 0x6e0074616c665f6bul, 0x656d616e6b6369ul, 0x7263616d74616863ul, 0x6d7461686300306ful, 0x686300316f726361ul, 0x326f7263616d7461ul, 0x63616d7461686300ul, 0x7461686300336f72ul, 0x6300346f7263616dul, 0x6f7263616d746168ul, 0x616d746168630035ul, 0x61686300366f7263ul, 0x376f7263616d74ul, 0x7263616d74616863ul, 0x6d7461686300386ful, 0x6f6300396f726361ul, 0x72670074726f706dul, 0x5f6c616369687061ul, 0x70757472617473ul, 0x756a64616f747561ul, 0x6f656469765f7473ul, 0x676e69747465735ful, 0x63736c6c75660073ul, 0x707361006e656572ul, 0x697461725f746365ul, 0x636572726f635f6ful, 0x7574726174730074ul, 0x79616c65645f70ul, 0x775f6e6565726373ul, 0x7263730068746469ul, 0x676965685f6e6565ul, 0x6565726373007468ul, 0x7267007070625f6eul, 0x6573756f6d6261ul, 0x6d00747265766f6eul, 0x6363615f6573756ful, 0x6f69746172656c65ul, 0x5f6573756f6d006eul, 0x6c6f687365726874ul, 0x61735f646e730064ul, 0x65746172656c706dul, 0x6361635f646e7300ul, 0x7300657a69736568ul, 0x6c7378616d5f646eul, 0x5f656d6974656369ul, 0x6d5f646e7300736dul, 0x646d6363697375ul, 0x705f6f695f6c706ful, 0x776f68730074726ful, 0x6d6f6f646e655ful, 0x657263735f676e70ul, 0x73746f68736e65ul, 0x5f616c6c696e6176ul, 0x656d616765766173ul, 0x760074696d696c5ful, 0x645f616c6c696e61ul, 0x696d696c5f6f6d65ul, 0x6c6c696e61760074ul, 0x616f6279656b5f61ul, 0x697070616d5f6472ul, 0x6f6564697600676eul, 0x7265766972645ful, 0x705f776f646e6977ul, 0x6e6f697469736ful, 0x6b63697473796f6aul, 0x6a007865646e695ful, 0x5f6b63697473796ful, 0x6a00736978615f78ul, 0x5f6b63697473796ful, 0x747265766e695f78ul, 0x63697473796f6a00ul, 0x736978615f795f6bul, 0x63697473796f6a00ul, 0x65766e695f795f6bul, 0x7473796f6a007472ul, 0x617274735f6b6369ul, 0x736978615f6566ul, 0x6b63697473796f6aul, 0x5f6566617274735ful, 0x6a00747265766e69ul, 0x5f6b63697473796ful, 0x6c61636973796870ul, 0x306e6f747475625ful, 0x63697473796f6a00ul, 0x6369737968705f6bul, 0x6f747475625f6c61ul, 0x7473796f6a00316eul, 0x737968705f6b6369ul, 0x7475625f6c616369ul, 0x796f6a00326e6f74ul, 0x68705f6b63697473ul, 0x625f6c6163697379ul, 0x6a00336e6f747475ul, 0x5f6b63697473796ful, 0x6c61636973796870ul, 0x346e6f747475625ful, 0x63697473796f6a00ul, 0x6369737968705f6bul, 0x6f747475625f6c61ul, 0x7473796f6a00356eul, 0x737968705f6b6369ul, 0x7475625f6c616369ul, 0x796f6a00366e6f74ul, 0x68705f6b63697473ul, 0x625f6c6163697379ul, 0x6a00376e6f747475ul, 0x5f6b63697473796ful, 0x6c61636973796870ul, 0x386e6f747475625ful, 0x63697473796f6a00ul, 0x6369737968705f6bul, 0x6f747475625f6c61ul, 0x5f62796f6a00396eul, 0x656c656661727473ul, 0x5f62796f6a007466ul, 0x6972656661727473ul, 0x62796f6a00746867ul, 0x63615f756e656d5ful, 0x6a00657461766974ul, 0x766572705f62796ful, 0x6a006e6f70616577ul, 0x7478656e5f62796ful, 0x6d006e6f70616577ul, 0x74735f626573756ful, 0x7466656c65666172ul, 0x5f626573756f6d00ul, 0x6972656661727473ul, 0x73756f6d00746867ul, 0x6d006573755f6265ul, 0x61625f626573756ful, 0x6d00647261776b63ul, 0x72705f626573756ful, 0x6e6f706165777665ul, 0x5f626573756f6d00ul, 0x706165777478656eul, 0x63696c6364006e6ful, 0x7375006573755f6bul, 0x6d617362696c5f65ul, 0x65746172656c70ul, 0x6c706d617362696cul, 0x63735f6574617265ul, 0x696d697400656c61ul, 0x6766635f79746964ul, 0x756700687461705ful, 0x5f68637461705f73ul, 0x7375670068746170ul, 0x626b5f6d61725ful, 0x737561705f79656bul, 0x656d5f79656b0065ul, 0x76697463615f756eul, 0x5f79656b00657461ul, 0x70755f756e656dul, 0x756e656d5f79656bul, 0x656b006e776f645ful, 0x6c5f756e656d5f79ul, 0x5f79656b00746665ul, 0x6769725f756e656dul, 0x6d5f79656b007468ul, 0x6b6361625f756e65ul, 0x6e656d5f79656b00ul, 0x726177726f665f75ul, 0x656d5f79656b0064ul, 0x69666e6f635f756eul, 0x6d5f79656b006d72ul, 0x726f62615f756e65ul, 0x656d5f79656b0074ul, 0x706c65685f756eul, 0x756e656d5f79656bul, 0x656b00657661735ful, 0x6c5f756e656d5f79ul, 0x5f79656b0064616ful, 0x6c6f765f756e656dul, 0x5f79656b00656d75ul, 0x7465645f756e656dul, 0x5f79656b006c6961ul, 0x6173715f756e656dul, 0x6d5f79656b006576ul, 0x67646e655f756e65ul, 0x5f79656b00656d61ul, 0x73656d5f756e656dul, 0x656b007365676173ul, 0x715f756e656d5f79ul, 0x79656b0064616f6cul, 0x75715f756e656d5ful, 0x6d5f79656b007469ul, 0x6d6d61675f756e65ul, 0x70735f79656b0061ul, 0x656d5f79656b0079ul, 0x6373636e695f756eul, 0x79656b006e656572ul, 0x65645f756e656d5ful, 0x6e656572637363ul, 0x756e656d5f79656bul, 0x736e65657263735ful, 0x5f79656b00746f68ul, 0x67676f745f70616dul, 0x6d5f79656b00656cul, 0x6874726f6e5f7061ul, 0x70616d5f79656b00ul, 0x6b006874756f735ful, 0x655f70616d5f7965ul, 0x5f79656b00747361ul, 0x747365775f70616dul, 0x70616d5f79656b00ul, 0x6e696d6f6f7a5ful, 0x5f70616d5f79656bul, 0x74756f6d6f6f7aul, 0x5f70616d5f79656bul, 0x6d6f6f7a78616dul, 0x5f70616d5f79656bul, 0x6b00776f6c6c6f66ul, 0x675f70616d5f7965ul, 0x5f79656b00646972ul, 0x6b72616d5f70616dul, 0x70616d5f79656b00ul, 0x616d7261656c635ful, 0x775f79656b006b72ul, 0x6b00316e6f706165ul, 0x6f706165775f7965ul, 0x775f79656b00326eul, 0x6b00336e6f706165ul, 0x6f706165775f7965ul, 0x775f79656b00346eul, 0x6b00356e6f706165ul, 0x6f706165775f7965ul, 0x775f79656b00366eul, 0x6b00376e6f706165ul, 0x6f706165775f7965ul, 0x705f79656b00386eul, 0x6f70616577766572ul, 0x656e5f79656b006eul, 0x6e6f706165777478ul, 0x7472615f79656b00ul, 0x656b006c6c615f69ul, 0x685f697472615f79ul, 0x656b0068746c6165ul, 0x705f697472615f79ul, 0x6761626e6f73696ful, 0x7472615f79656b00ul, 0x727473616c625f69ul, 0x656b007375696461ul, 0x745f697472615f79ul, 0x74726f70656c65ul, 0x697472615f79656bul, 0x726f70656c65745ful, 0x6b00726568746f74ul, 0x5f697472615f7965ul, 0x5f79656b00676765ul, 0x766e695f69747261ul, 0x69626172656e6c75ul, 0x79656b007974696cul, 0x6567617373656d5ful, 0x687365726665725ful, 0x6d65645f79656b00ul, 0x6b00746975715f6ful, 0x69746c756d5f7965ul, 0x79656b0067736d5ful, 0x6d5f69746c756d5ful, 0x726579616c706773ul, 0x756d5f79656b0031ul, 0x7067736d5f69746cul, 0x6b0032726579616cul, 0x69746c756d5f7965ul, 0x79616c7067736d5ful, 0x5f79656b00337265ul, 0x736d5f69746c756dul, 0x34726579616c7067ul, 0x6c756d5f79656b00ul, 0x6c7067736d5f6974ul, 0x656b003572657961ul, 0x5f69746c756d5f79ul, 0x6579616c7067736dul, 0x6d5f79656b003672ul, 0x67736d5f69746c75ul, 0x37726579616c70ul, 0x746c756d5f79656bul, 0x616c7067736d5f69ul, 0x78250038726579ul, 0x666e6f632d006925ul, 0x6166656409006769ul, 0x656c696620746c75ul, 0x6173000a7325203aul, 0x6e6f6320676e6976ul, 0x25206e6920676966ul, 0x727478652d000a73ul, 0x6769666e6f6361ul, 0x2020202020202020ul, 0x6f63206172747865ul, 0x746172756769666eul, 0x656c6966206e6f69ul, 0x6e55000a7325203aul, 0x6f63206e776f6e6bul, 0x746172756769666eul, 0x69726176206e6f69ul, 0x2527203a656c6261ul, 0x6e69735500002773ul, 0x726f662073252067ul, 0x756769666e6f6320ul, 0x61206e6f69746172ul, 0x736576617320646eul, 0x7661732e002f000aul, 0x55002f656d616765ul, 0x20732520676e6973ul, 0x6576617320726f66ul, 0xa73656d6167ul)

[init]
def private c2da_lin_init_static_m_config() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(82)) {
        let at = c2da_lin_static_m_config_seg[s * 2]
        for (k in range(c2da_lin_static_m_config_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_m_config[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_m_config() {
    if (length(c2da_fn_table0) < 4) {
        resize(c2da_fn_table0, 4)
    }
    c2da_fn_table0[3] = @@M_SaveDefaults
}

[init]
def private c2da_lin_relink_init_m_config() {
    c2da_relink_m_config()
}
