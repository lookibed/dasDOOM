options gen2
options stack = 4194304
module i_scale public

require c2da_runtime
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
var private src_buffer : int

var private dest_buffer : int

var private dest_pitch : int

var private stretch_tables : int[2] = fixed_array<int>(0, 0)

var private half_stretch_table : int = 0

[export, sideeffects]
def I_InitScale(var _src_buffer : int; var _dest_buffer : int; var _dest_pitch : int) {
    src_buffer = int(_src_buffer)  // nolint:PERF020
    dest_buffer = int(_dest_buffer)  // nolint:PERF020
    dest_pitch = int(_dest_pitch)  // nolint:PERF020
    return
}
[sideeffects]
def private I_Scale1x(var x1 : int; var y1 : int; var x2 : int; var y2 : int) : uint {
    var bufp : int
    var screenp : int
    var w : int = x2 - x1
    bufp = src_buffer + y1 * 320 + x1
    screenp = dest_buffer + y1 * dest_pitch + x1
    for (y in range(y1, y2)) {
        c2da_lin_memcpy(screenp, bufp, uint64(w))
        screenp += dest_pitch
        bufp += 320
    }
    return 1u
}
var mode_scale_1x : screen_mode_t = screen_mode_t(width = 320, height = 200, InitMode = 0, DrawScreen = 156, poor_quality = 0u)

[sideeffects]
def private I_Scale2x(var x1_0 : int; var y1_0 : int; var x2_0 : int; var y2_0 : int) : uint {
    var bufp_0 : int
    var screenp_0 : int
    var screenp2 : int
    var multi_pitch : int
    var sp : int
    var sp2 : int
    var bp : int
    multi_pitch = dest_pitch * 2
    bufp_0 = src_buffer + y1_0 * 320 + x1_0
    screenp_0 = dest_buffer + (y1_0 * dest_pitch + x1_0) * 2
    screenp2 = screenp_0 + dest_pitch
    for (y_0 in range(y1_0, y2_0)) {
        sp = screenp_0
        sp2 = screenp2
        bp = bufp_0
        for (x in range(x1_0, x2_0)) {
            let c2da_fresh0 : int = sp
            sp++
            let c2da_fresh1 : uint8 = c2da_mem[bp]
            c2da_mem[c2da_fresh0] = c2da_fresh1
            let c2da_fresh2 : int = sp
            sp++
            let c2da_fresh3 : uint8 = c2da_mem[bp]
            c2da_mem[c2da_fresh2] = c2da_fresh3
            let c2da_fresh4 : int = sp2
            sp2++
            let c2da_fresh5 : uint8 = c2da_mem[bp]
            c2da_mem[c2da_fresh4] = c2da_fresh5
            let c2da_fresh6 : int = sp2
            sp2++
            let c2da_fresh7 : uint8 = c2da_mem[bp]
            c2da_mem[c2da_fresh6] = c2da_fresh7
            bp++
        }
        screenp_0 += multi_pitch
        screenp2 += multi_pitch
        bufp_0 += 320
    }
    return 1u
}
var mode_scale_2x : screen_mode_t = screen_mode_t(width = 320 * 2, height = 200 * 2, InitMode = 0, DrawScreen = 157, poor_quality = 0u)

[sideeffects]
def private I_Scale3x(var x1_1 : int; var y1_1 : int; var x2_1 : int; var y2_1 : int) : uint {
    var bufp_1 : int
    var screenp_1 : int
    var screenp2_0 : int
    var screenp3 : int
    var multi_pitch_0 : int
    var sp_0 : int
    var sp2_0 : int
    var sp3 : int
    var bp_0 : int
    multi_pitch_0 = dest_pitch * 3
    bufp_1 = src_buffer + y1_1 * 320 + x1_1
    screenp_1 = dest_buffer + (y1_1 * dest_pitch + x1_1) * 3
    screenp2_0 = screenp_1 + dest_pitch
    screenp3 = screenp_1 + dest_pitch * 2
    for (y_1 in range(y1_1, y2_1)) {
        sp_0 = screenp_1
        sp2_0 = screenp2_0
        sp3 = screenp3
        bp_0 = bufp_1
        for (x_0 in range(x1_1, x2_1)) {
            let c2da_fresh8 : int = sp_0
            sp_0++
            let c2da_fresh9 : uint8 = c2da_mem[bp_0]
            c2da_mem[c2da_fresh8] = c2da_fresh9
            let c2da_fresh10 : int = sp_0
            sp_0++
            let c2da_fresh11 : uint8 = c2da_mem[bp_0]
            c2da_mem[c2da_fresh10] = c2da_fresh11
            let c2da_fresh12 : int = sp_0
            sp_0++
            let c2da_fresh13 : uint8 = c2da_mem[bp_0]
            c2da_mem[c2da_fresh12] = c2da_fresh13
            let c2da_fresh14 : int = sp2_0
            sp2_0++
            let c2da_fresh15 : uint8 = c2da_mem[bp_0]
            c2da_mem[c2da_fresh14] = c2da_fresh15
            let c2da_fresh16 : int = sp2_0
            sp2_0++
            let c2da_fresh17 : uint8 = c2da_mem[bp_0]
            c2da_mem[c2da_fresh16] = c2da_fresh17
            let c2da_fresh18 : int = sp2_0
            sp2_0++
            let c2da_fresh19 : uint8 = c2da_mem[bp_0]
            c2da_mem[c2da_fresh18] = c2da_fresh19
            let c2da_fresh20 : int = sp3
            sp3++
            let c2da_fresh21 : uint8 = c2da_mem[bp_0]
            c2da_mem[c2da_fresh20] = c2da_fresh21
            let c2da_fresh22 : int = sp3
            sp3++
            let c2da_fresh23 : uint8 = c2da_mem[bp_0]
            c2da_mem[c2da_fresh22] = c2da_fresh23
            let c2da_fresh24 : int = sp3
            sp3++
            let c2da_fresh25 : uint8 = c2da_mem[bp_0]
            c2da_mem[c2da_fresh24] = c2da_fresh25
            bp_0++
        }
        screenp_1 += multi_pitch_0
        screenp2_0 += multi_pitch_0
        screenp3 += multi_pitch_0
        bufp_1 += 320
    }
    return 1u
}
var mode_scale_3x : screen_mode_t = screen_mode_t(width = 320 * 3, height = 200 * 3, InitMode = 0, DrawScreen = 158, poor_quality = 0u)

[sideeffects]
def private I_Scale4x(var x1_2 : int; var y1_2 : int; var x2_2 : int; var y2_2 : int) : uint {
    var bufp_2 : int
    var screenp_2 : int
    var screenp2_1 : int
    var screenp3_0 : int
    var screenp4 : int
    var multi_pitch_1 : int
    var sp_1 : int
    var sp2_1 : int
    var sp3_0 : int
    var sp4 : int
    var bp_1 : int
    multi_pitch_1 = dest_pitch * 4
    bufp_2 = src_buffer + y1_2 * 320 + x1_2
    screenp_2 = dest_buffer + (y1_2 * dest_pitch + x1_2) * 4
    screenp2_1 = screenp_2 + dest_pitch
    screenp3_0 = screenp_2 + dest_pitch * 2
    screenp4 = screenp_2 + dest_pitch * 3
    for (y_2 in range(y1_2, y2_2)) {
        sp_1 = screenp_2
        sp2_1 = screenp2_1
        sp3_0 = screenp3_0
        sp4 = screenp4
        bp_1 = bufp_2
        for (x_1 in range(x1_2, x2_2)) {
            let c2da_fresh26 : int = sp_1
            sp_1++
            let c2da_fresh27 : uint8 = c2da_mem[bp_1]
            c2da_mem[c2da_fresh26] = c2da_fresh27
            let c2da_fresh28 : int = sp_1
            sp_1++
            let c2da_fresh29 : uint8 = c2da_mem[bp_1]
            c2da_mem[c2da_fresh28] = c2da_fresh29
            let c2da_fresh30 : int = sp_1
            sp_1++
            let c2da_fresh31 : uint8 = c2da_mem[bp_1]
            c2da_mem[c2da_fresh30] = c2da_fresh31
            let c2da_fresh32 : int = sp_1
            sp_1++
            let c2da_fresh33 : uint8 = c2da_mem[bp_1]
            c2da_mem[c2da_fresh32] = c2da_fresh33
            let c2da_fresh34 : int = sp2_1
            sp2_1++
            let c2da_fresh35 : uint8 = c2da_mem[bp_1]
            c2da_mem[c2da_fresh34] = c2da_fresh35
            let c2da_fresh36 : int = sp2_1
            sp2_1++
            let c2da_fresh37 : uint8 = c2da_mem[bp_1]
            c2da_mem[c2da_fresh36] = c2da_fresh37
            let c2da_fresh38 : int = sp2_1
            sp2_1++
            let c2da_fresh39 : uint8 = c2da_mem[bp_1]
            c2da_mem[c2da_fresh38] = c2da_fresh39
            let c2da_fresh40 : int = sp2_1
            sp2_1++
            let c2da_fresh41 : uint8 = c2da_mem[bp_1]
            c2da_mem[c2da_fresh40] = c2da_fresh41
            let c2da_fresh42 : int = sp3_0
            sp3_0++
            let c2da_fresh43 : uint8 = c2da_mem[bp_1]
            c2da_mem[c2da_fresh42] = c2da_fresh43
            let c2da_fresh44 : int = sp3_0
            sp3_0++
            let c2da_fresh45 : uint8 = c2da_mem[bp_1]
            c2da_mem[c2da_fresh44] = c2da_fresh45
            let c2da_fresh46 : int = sp3_0
            sp3_0++
            let c2da_fresh47 : uint8 = c2da_mem[bp_1]
            c2da_mem[c2da_fresh46] = c2da_fresh47
            let c2da_fresh48 : int = sp3_0
            sp3_0++
            let c2da_fresh49 : uint8 = c2da_mem[bp_1]
            c2da_mem[c2da_fresh48] = c2da_fresh49
            let c2da_fresh50 : int = sp4
            sp4++
            let c2da_fresh51 : uint8 = c2da_mem[bp_1]
            c2da_mem[c2da_fresh50] = c2da_fresh51
            let c2da_fresh52 : int = sp4
            sp4++
            let c2da_fresh53 : uint8 = c2da_mem[bp_1]
            c2da_mem[c2da_fresh52] = c2da_fresh53
            let c2da_fresh54 : int = sp4
            sp4++
            let c2da_fresh55 : uint8 = c2da_mem[bp_1]
            c2da_mem[c2da_fresh54] = c2da_fresh55
            let c2da_fresh56 : int = sp4
            sp4++
            let c2da_fresh57 : uint8 = c2da_mem[bp_1]
            c2da_mem[c2da_fresh56] = c2da_fresh57
            bp_1++
        }
        screenp_2 += multi_pitch_1
        screenp2_1 += multi_pitch_1
        screenp3_0 += multi_pitch_1
        screenp4 += multi_pitch_1
        bufp_2 += 320
    }
    return 1u
}
var mode_scale_4x : screen_mode_t = screen_mode_t(width = 320 * 4, height = 200 * 4, InitMode = 0, DrawScreen = 159, poor_quality = 0u)

[sideeffects]
def private I_Scale5x(var x1_3 : int; var y1_3 : int; var x2_3 : int; var y2_3 : int) : uint {
    var bufp_3 : int
    var screenp_3 : int
    var screenp2_2 : int
    var screenp3_1 : int
    var screenp4_0 : int
    var screenp5 : int
    var multi_pitch_2 : int
    var sp_2 : int
    var sp2_2 : int
    var sp3_1 : int
    var sp4_0 : int
    var sp5 : int
    var bp_2 : int
    multi_pitch_2 = dest_pitch * 5
    bufp_3 = src_buffer + y1_3 * 320 + x1_3
    screenp_3 = dest_buffer + (y1_3 * dest_pitch + x1_3) * 5
    screenp2_2 = screenp_3 + dest_pitch
    screenp3_1 = screenp_3 + dest_pitch * 2
    screenp4_0 = screenp_3 + dest_pitch * 3
    screenp5 = screenp_3 + dest_pitch * 4
    for (y_3 in range(y1_3, y2_3)) {
        sp_2 = screenp_3
        sp2_2 = screenp2_2
        sp3_1 = screenp3_1
        sp4_0 = screenp4_0
        sp5 = screenp5
        bp_2 = bufp_3
        for (x_2 in range(x1_3, x2_3)) {
            let c2da_fresh58 : int = sp_2
            sp_2++
            let c2da_fresh59 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh58] = c2da_fresh59
            let c2da_fresh60 : int = sp_2
            sp_2++
            let c2da_fresh61 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh60] = c2da_fresh61
            let c2da_fresh62 : int = sp_2
            sp_2++
            let c2da_fresh63 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh62] = c2da_fresh63
            let c2da_fresh64 : int = sp_2
            sp_2++
            let c2da_fresh65 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh64] = c2da_fresh65
            let c2da_fresh66 : int = sp_2
            sp_2++
            let c2da_fresh67 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh66] = c2da_fresh67
            let c2da_fresh68 : int = sp2_2
            sp2_2++
            let c2da_fresh69 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh68] = c2da_fresh69
            let c2da_fresh70 : int = sp2_2
            sp2_2++
            let c2da_fresh71 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh70] = c2da_fresh71
            let c2da_fresh72 : int = sp2_2
            sp2_2++
            let c2da_fresh73 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh72] = c2da_fresh73
            let c2da_fresh74 : int = sp2_2
            sp2_2++
            let c2da_fresh75 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh74] = c2da_fresh75
            let c2da_fresh76 : int = sp2_2
            sp2_2++
            let c2da_fresh77 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh76] = c2da_fresh77
            let c2da_fresh78 : int = sp3_1
            sp3_1++
            let c2da_fresh79 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh78] = c2da_fresh79
            let c2da_fresh80 : int = sp3_1
            sp3_1++
            let c2da_fresh81 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh80] = c2da_fresh81
            let c2da_fresh82 : int = sp3_1
            sp3_1++
            let c2da_fresh83 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh82] = c2da_fresh83
            let c2da_fresh84 : int = sp3_1
            sp3_1++
            let c2da_fresh85 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh84] = c2da_fresh85
            let c2da_fresh86 : int = sp3_1
            sp3_1++
            let c2da_fresh87 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh86] = c2da_fresh87
            let c2da_fresh88 : int = sp4_0
            sp4_0++
            let c2da_fresh89 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh88] = c2da_fresh89
            let c2da_fresh90 : int = sp4_0
            sp4_0++
            let c2da_fresh91 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh90] = c2da_fresh91
            let c2da_fresh92 : int = sp4_0
            sp4_0++
            let c2da_fresh93 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh92] = c2da_fresh93
            let c2da_fresh94 : int = sp4_0
            sp4_0++
            let c2da_fresh95 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh94] = c2da_fresh95
            let c2da_fresh96 : int = sp4_0
            sp4_0++
            let c2da_fresh97 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh96] = c2da_fresh97
            let c2da_fresh98 : int = sp5
            sp5++
            let c2da_fresh99 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh98] = c2da_fresh99
            let c2da_fresh100 : int = sp5
            sp5++
            let c2da_fresh101 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh100] = c2da_fresh101
            let c2da_fresh102 : int = sp5
            sp5++
            let c2da_fresh103 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh102] = c2da_fresh103
            let c2da_fresh104 : int = sp5
            sp5++
            let c2da_fresh105 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh104] = c2da_fresh105
            let c2da_fresh106 : int = sp5
            sp5++
            let c2da_fresh107 : uint8 = c2da_mem[bp_2]
            c2da_mem[c2da_fresh106] = c2da_fresh107
            bp_2++
        }
        screenp_3 += multi_pitch_2
        screenp2_2 += multi_pitch_2
        screenp3_1 += multi_pitch_2
        screenp4_0 += multi_pitch_2
        screenp5 += multi_pitch_2
        bufp_3 += 320
    }
    return 1u
}
var mode_scale_5x : screen_mode_t = screen_mode_t(width = 320 * 5, height = 200 * 5, InitMode = 0, DrawScreen = 160, poor_quality = 0u)

[sideeffects]
def private FindNearestColor(var palette : int; var r : int; var g : int; var b : int) : int {
    var col : int
    var best : int
    var best_diff : int
    var diff : int
    best = 0
    best_diff = 2147483647
    for (i in range(0, 256)) {
        col = palette + i * 3
        diff = (r - int(c2da_mem[col + 0])) * (r - int(c2da_mem[col + 0])) + (g - int(c2da_mem[col + 1])) * (g - int(c2da_mem[col + 1])) + (b - int(c2da_mem[col + 2])) * (b - int(c2da_mem[col + 2]))
        if (diff == 0) {
            return i
        } elif (diff < best_diff) {
            best = i
            best_diff = diff
        }
    }
    return best
}
[sideeffects]
def private GenerateStretchTable(var palette_0 : int; var pct : int) : int {
    var result_0 : int
    var r_0 : int
    var g_0 : int
    var b_0 : int
    var col1 : int
    var col2 : int
    result_0 = Z_Malloc(256 * 256, 1, 0)
    for (x_3 in range(0, 256)) {
        for (y_4 in range(0, 256)) {
            col1 = palette_0 + x_3 * 3
            col2 = palette_0 + y_4 * 3
            r_0 = (int(c2da_mem[col1 + 0]) * pct + int(c2da_mem[col2 + 0]) * (100 - pct)) / 100
            g_0 = (int(c2da_mem[col1 + 1]) * pct + int(c2da_mem[col2 + 1]) * (100 - pct)) / 100
            b_0 = (int(c2da_mem[col1 + 2]) * pct + int(c2da_mem[col2 + 2]) * (100 - pct)) / 100
            let c2da_fresh108 : uint8 = uint8(FindNearestColor(palette_0, r_0, g_0, b_0))
            c2da_mem[result_0 + (x_3 * 256 + y_4)] = c2da_fresh108
        }
    }
    return result_0
}
[sideeffects]
def private I_InitStretchTables(var palette_1 : int) {
    if (stretch_tables[0] != 0) {
        return
    }
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 345184, [])
    c2da_std_fflush(uint64(int(c2da_std_stdout())))
    stretch_tables[0] = GenerateStretchTable(palette_1, 20)
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 345232, [])
    c2da_std_fflush(uint64(int(c2da_std_stdout())))
    stretch_tables[1] = GenerateStretchTable(palette_1, 40)
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 345235, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 345239ul)])
    return
}
[sideeffects]
def private I_InitSquashTable(var palette_2 : int) {
    if (half_stretch_table != 0) {
        return
    }
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 345240, [])
    c2da_std_fflush(uint64(int(c2da_std_stdout())))
    half_stretch_table = GenerateStretchTable(palette_2, 50)
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 345235, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 345239ul)])
    return
}
[export, sideeffects]
def I_ResetScaleTables(var palette_3 : int) {
    if (stretch_tables[0] != 0) {
        Z_Free(stretch_tables[0])
        Z_Free(stretch_tables[1])
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 345285, [])
        stretch_tables[0] = GenerateStretchTable(palette_3, 20)
        stretch_tables[1] = GenerateStretchTable(palette_3, 40)
    }
    if (half_stretch_table != 0) {
        Z_Free(half_stretch_table)
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 345335, [])
        half_stretch_table = GenerateStretchTable(palette_3, 50)
    }
    return
}
[sideeffects]
def private WriteBlendedLine1x(var dest : int; var src1 : int; var src2 : int; var stretch_table : int) {
    for (x_4 in range(0, 320)) {
        let c2da_fresh109 : int = stretch_table + (int(c2da_mem[src1]) * 256 + int(c2da_mem[src2]))
        let c2da_fresh110 : uint8 = c2da_mem[c2da_fresh109]
        c2da_mem[dest] = c2da_fresh110
        dest++
        src1++
        src2++
    }
    return
}
[sideeffects]
def private I_Stretch1x(var x1_4 : int; var y1_4 : int; var x2_4 : int; var y2_4 : int) : uint {
    var bufp_4 : int
    var screenp_4 : int
    var y_5 : int
    if (x1_4 != 0 || y1_4 != 0 || x2_4 != 320 || y2_4 != 200) {
        return 0u
    }
    bufp_4 = src_buffer + y1_4 * 320 + x1_4
    screenp_4 = dest_buffer + y1_4 * dest_pitch + x1_4
    y_5 = 0
    while (y_5 < 200) {
        c2da_lin_memcpy(screenp_4, bufp_4, 320ul)
        screenp_4 += dest_pitch
        WriteBlendedLine1x(screenp_4, bufp_4, bufp_4 + 320, stretch_tables[0])
        screenp_4 += dest_pitch
        bufp_4 += 320
        WriteBlendedLine1x(screenp_4, bufp_4, bufp_4 + 320, stretch_tables[1])
        screenp_4 += dest_pitch
        bufp_4 += 320
        WriteBlendedLine1x(screenp_4, bufp_4 + 320, bufp_4, stretch_tables[1])
        screenp_4 += dest_pitch
        bufp_4 += 320
        WriteBlendedLine1x(screenp_4, bufp_4 + 320, bufp_4, stretch_tables[0])
        screenp_4 += dest_pitch
        bufp_4 += 320
        c2da_lin_memcpy(screenp_4, bufp_4, 320ul)
        screenp_4 += dest_pitch
        bufp_4 += 320
        y_5 += 5
    }
    return 1u
}
var mode_stretch_1x : screen_mode_t = screen_mode_t(width = 320, height = 240, InitMode = 161, DrawScreen = 162, poor_quality = 1u)

[sideeffects]
def private WriteLine2x(var dest_0 : int; var src : int) {
    for (x_5 in range(0, 320)) {
        let c2da_fresh111 : uint8 = c2da_mem[src]
        c2da_mem[dest_0 + 0] = c2da_fresh111
        let c2da_fresh112 : uint8 = c2da_mem[src]
        c2da_mem[dest_0 + 1] = c2da_fresh112
        dest_0 += 2
        src++
    }
    return
}
[sideeffects]
def private WriteBlendedLine2x(var dest_1 : int; var src1_0 : int; var src2_0 : int; var stretch_table_0 : int) {
    var val : int
    for (x_6 in range(0, 320)) {
        let c2da_fresh113 : int = stretch_table_0 + (int(c2da_mem[src1_0]) * 256 + int(c2da_mem[src2_0]))
        val = int(c2da_mem[c2da_fresh113])
        let c2da_fresh114 : uint8 = uint8(val)
        c2da_mem[dest_1 + 0] = c2da_fresh114
        let c2da_fresh115 : uint8 = uint8(val)
        c2da_mem[dest_1 + 1] = c2da_fresh115
        dest_1 += 2
        src1_0++
        src2_0++
    }
    return
}
[sideeffects]
def private I_Stretch2x(var x1_5 : int; var y1_5 : int; var x2_5 : int; var y2_5 : int) : uint {
    var bufp_5 : int
    var screenp_5 : int
    var y_6 : int
    if (x1_5 != 0 || y1_5 != 0 || x2_5 != 320 || y2_5 != 200) {
        return 0u
    }
    bufp_5 = src_buffer + y1_5 * 320 + x1_5
    screenp_5 = dest_buffer + y1_5 * dest_pitch + x1_5
    y_6 = 0
    while (y_6 < 200) {
        WriteLine2x(screenp_5, bufp_5)
        screenp_5 += dest_pitch
        WriteLine2x(screenp_5, bufp_5)
        screenp_5 += dest_pitch
        WriteBlendedLine2x(screenp_5, bufp_5, bufp_5 + 320, stretch_tables[1])
        screenp_5 += dest_pitch
        bufp_5 += 320
        WriteLine2x(screenp_5, bufp_5)
        screenp_5 += dest_pitch
        WriteBlendedLine2x(screenp_5, bufp_5 + 320, bufp_5, stretch_tables[0])
        screenp_5 += dest_pitch
        bufp_5 += 320
        WriteLine2x(screenp_5, bufp_5)
        screenp_5 += dest_pitch
        WriteLine2x(screenp_5, bufp_5)
        screenp_5 += dest_pitch
        WriteBlendedLine2x(screenp_5, bufp_5, bufp_5 + 320, stretch_tables[0])
        screenp_5 += dest_pitch
        bufp_5 += 320
        WriteLine2x(screenp_5, bufp_5)
        screenp_5 += dest_pitch
        WriteBlendedLine2x(screenp_5, bufp_5 + 320, bufp_5, stretch_tables[1])
        screenp_5 += dest_pitch
        bufp_5 += 320
        WriteLine2x(screenp_5, bufp_5)
        screenp_5 += dest_pitch
        WriteLine2x(screenp_5, bufp_5)
        screenp_5 += dest_pitch
        bufp_5 += 320
        y_6 += 5
    }
    return 1u
}
var mode_stretch_2x : screen_mode_t = screen_mode_t(width = 320 * 2, height = 240 * 2, InitMode = 161, DrawScreen = 163, poor_quality = 0u)

[sideeffects]
def private WriteLine3x(var dest_2 : int; var src_0 : int) {
    for (x_7 in range(0, 320)) {
        let c2da_fresh116 : uint8 = c2da_mem[src_0]
        c2da_mem[dest_2 + 0] = c2da_fresh116
        let c2da_fresh117 : uint8 = c2da_mem[src_0]
        c2da_mem[dest_2 + 1] = c2da_fresh117
        let c2da_fresh118 : uint8 = c2da_mem[src_0]
        c2da_mem[dest_2 + 2] = c2da_fresh118
        dest_2 += 3
        src_0++
    }
    return
}
[sideeffects]
def private WriteBlendedLine3x(var dest_3 : int; var src1_1 : int; var src2_1 : int; var stretch_table_1 : int) {
    var val_0 : int
    for (x_8 in range(0, 320)) {
        let c2da_fresh119 : int = stretch_table_1 + (int(c2da_mem[src1_1]) * 256 + int(c2da_mem[src2_1]))
        val_0 = int(c2da_mem[c2da_fresh119])
        let c2da_fresh120 : uint8 = uint8(val_0)
        c2da_mem[dest_3 + 0] = c2da_fresh120
        let c2da_fresh121 : uint8 = uint8(val_0)
        c2da_mem[dest_3 + 1] = c2da_fresh121
        let c2da_fresh122 : uint8 = uint8(val_0)
        c2da_mem[dest_3 + 2] = c2da_fresh122
        dest_3 += 3
        src1_1++
        src2_1++
    }
    return
}
[sideeffects]
def private I_Stretch3x(var x1_6 : int; var y1_6 : int; var x2_6 : int; var y2_6 : int) : uint {
    var bufp_6 : int
    var screenp_6 : int
    var y_7 : int
    if (x1_6 != 0 || y1_6 != 0 || x2_6 != 320 || y2_6 != 200) {
        return 0u
    }
    bufp_6 = src_buffer + y1_6 * 320 + x1_6
    screenp_6 = dest_buffer + y1_6 * dest_pitch + x1_6
    y_7 = 0
    while (y_7 < 200) {
        WriteLine3x(screenp_6, bufp_6)
        screenp_6 += dest_pitch
        WriteLine3x(screenp_6, bufp_6)
        screenp_6 += dest_pitch
        WriteLine3x(screenp_6, bufp_6)
        screenp_6 += dest_pitch
        WriteBlendedLine3x(screenp_6, bufp_6 + 320, bufp_6, stretch_tables[1])
        screenp_6 += dest_pitch
        bufp_6 += 320
        WriteLine3x(screenp_6, bufp_6)
        screenp_6 += dest_pitch
        WriteLine3x(screenp_6, bufp_6)
        screenp_6 += dest_pitch
        WriteLine3x(screenp_6, bufp_6)
        screenp_6 += dest_pitch
        WriteBlendedLine3x(screenp_6, bufp_6, bufp_6 + 320, stretch_tables[0])
        screenp_6 += dest_pitch
        bufp_6 += 320
        WriteLine3x(screenp_6, bufp_6)
        screenp_6 += dest_pitch
        WriteLine3x(screenp_6, bufp_6)
        screenp_6 += dest_pitch
        WriteBlendedLine3x(screenp_6, bufp_6 + 320, bufp_6, stretch_tables[0])
        screenp_6 += dest_pitch
        bufp_6 += 320
        WriteLine3x(screenp_6, bufp_6)
        screenp_6 += dest_pitch
        WriteLine3x(screenp_6, bufp_6)
        screenp_6 += dest_pitch
        WriteLine3x(screenp_6, bufp_6)
        screenp_6 += dest_pitch
        WriteBlendedLine3x(screenp_6, bufp_6, bufp_6 + 320, stretch_tables[1])
        screenp_6 += dest_pitch
        bufp_6 += 320
        WriteLine3x(screenp_6, bufp_6)
        screenp_6 += dest_pitch
        WriteLine3x(screenp_6, bufp_6)
        screenp_6 += dest_pitch
        WriteLine3x(screenp_6, bufp_6)
        screenp_6 += dest_pitch
        bufp_6 += 320
        y_7 += 5
    }
    return 1u
}
var mode_stretch_3x : screen_mode_t = screen_mode_t(width = 320 * 3, height = 240 * 3, InitMode = 161, DrawScreen = 164, poor_quality = 0u)

[sideeffects]
def private WriteLine4x(var dest_4 : int; var src_1 : int) {
    for (x_9 in range(0, 320)) {
        let c2da_fresh123 : uint8 = c2da_mem[src_1]
        c2da_mem[dest_4 + 0] = c2da_fresh123
        let c2da_fresh124 : uint8 = c2da_mem[src_1]
        c2da_mem[dest_4 + 1] = c2da_fresh124
        let c2da_fresh125 : uint8 = c2da_mem[src_1]
        c2da_mem[dest_4 + 2] = c2da_fresh125
        let c2da_fresh126 : uint8 = c2da_mem[src_1]
        c2da_mem[dest_4 + 3] = c2da_fresh126
        dest_4 += 4
        src_1++
    }
    return
}
[sideeffects]
def private WriteBlendedLine4x(var dest_5 : int; var src1_2 : int; var src2_2 : int; var stretch_table_2 : int) {
    var val_1 : int
    for (x_10 in range(0, 320)) {
        let c2da_fresh127 : int = stretch_table_2 + (int(c2da_mem[src1_2]) * 256 + int(c2da_mem[src2_2]))
        val_1 = int(c2da_mem[c2da_fresh127])
        let c2da_fresh128 : uint8 = uint8(val_1)
        c2da_mem[dest_5 + 0] = c2da_fresh128
        let c2da_fresh129 : uint8 = uint8(val_1)
        c2da_mem[dest_5 + 1] = c2da_fresh129
        let c2da_fresh130 : uint8 = uint8(val_1)
        c2da_mem[dest_5 + 2] = c2da_fresh130
        let c2da_fresh131 : uint8 = uint8(val_1)
        c2da_mem[dest_5 + 3] = c2da_fresh131
        dest_5 += 4
        src1_2++
        src2_2++
    }
    return
}
[sideeffects]
def private I_Stretch4x(var x1_7 : int; var y1_7 : int; var x2_7 : int; var y2_7 : int) : uint {
    var bufp_7 : int
    var screenp_7 : int
    var y_8 : int
    if (x1_7 != 0 || y1_7 != 0 || x2_7 != 320 || y2_7 != 200) {
        return 0u
    }
    bufp_7 = src_buffer + y1_7 * 320 + x1_7
    screenp_7 = dest_buffer + y1_7 * dest_pitch + x1_7
    y_8 = 0
    while (y_8 < 200) {
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteBlendedLine4x(screenp_7, bufp_7 + 320, bufp_7, stretch_tables[0])
        screenp_7 += dest_pitch
        bufp_7 += 320
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteBlendedLine4x(screenp_7, bufp_7 + 320, bufp_7, stretch_tables[1])
        screenp_7 += dest_pitch
        bufp_7 += 320
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteBlendedLine4x(screenp_7, bufp_7, bufp_7 + 320, stretch_tables[1])
        screenp_7 += dest_pitch
        bufp_7 += 320
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteBlendedLine4x(screenp_7, bufp_7, bufp_7 + 320, stretch_tables[0])
        screenp_7 += dest_pitch
        bufp_7 += 320
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        WriteLine4x(screenp_7, bufp_7)
        screenp_7 += dest_pitch
        bufp_7 += 320
        y_8 += 5
    }
    return 1u
}
var mode_stretch_4x : screen_mode_t = screen_mode_t(width = 320 * 4, height = 240 * 4, InitMode = 161, DrawScreen = 165, poor_quality = 0u)

[sideeffects]
def private WriteLine5x(var dest_6 : int; var src_2 : int) {
    for (x_11 in range(0, 320)) {
        let c2da_fresh132 : uint8 = c2da_mem[src_2]
        c2da_mem[dest_6 + 0] = c2da_fresh132
        let c2da_fresh133 : uint8 = c2da_mem[src_2]
        c2da_mem[dest_6 + 1] = c2da_fresh133
        let c2da_fresh134 : uint8 = c2da_mem[src_2]
        c2da_mem[dest_6 + 2] = c2da_fresh134
        let c2da_fresh135 : uint8 = c2da_mem[src_2]
        c2da_mem[dest_6 + 3] = c2da_fresh135
        let c2da_fresh136 : uint8 = c2da_mem[src_2]
        c2da_mem[dest_6 + 4] = c2da_fresh136
        dest_6 += 5
        src_2++
    }
    return
}
[sideeffects]
def private I_Stretch5x(var x1_8 : int; var y1_8 : int; var x2_8 : int; var y2_8 : int) : uint {
    var bufp_8 : int
    var screenp_8 : int
    var y_9 : int
    if (x1_8 != 0 || y1_8 != 0 || x2_8 != 320 || y2_8 != 200) {
        return 0u
    }
    bufp_8 = src_buffer + y1_8 * 320 + x1_8
    screenp_8 = dest_buffer + y1_8 * dest_pitch + x1_8
    y_9 = 0
    while (y_9 < 200) {
        WriteLine5x(screenp_8, bufp_8)
        screenp_8 += dest_pitch
        WriteLine5x(screenp_8, bufp_8)
        screenp_8 += dest_pitch
        WriteLine5x(screenp_8, bufp_8)
        screenp_8 += dest_pitch
        WriteLine5x(screenp_8, bufp_8)
        screenp_8 += dest_pitch
        WriteLine5x(screenp_8, bufp_8)
        screenp_8 += dest_pitch
        WriteLine5x(screenp_8, bufp_8)
        screenp_8 += dest_pitch
        bufp_8 += 320
        y_9++
    }
    if (M_CheckParm(345384) > 0) {
        screenp_8 = dest_buffer + 2 * dest_pitch
        y_9 = 0
        while (y_9 < 1198) {
            c2da_lin_memset(screenp_8, 0, 1600ul)
            screenp_8 += dest_pitch * 3
            y_9 += 3
        }
    }
    return 1u
}
var mode_stretch_5x : screen_mode_t = screen_mode_t(width = 320 * 5, height = 240 * 5, InitMode = 161, DrawScreen = 166, poor_quality = 0u)

[sideeffects]
def private WriteSquashedLine1x(var dest_7 : int; var src_3 : int) {
    var x_12 : int = 0
    while (x_12 < 320) {
        let c2da_fresh137 : int = dest_7
        dest_7++
        let c2da_fresh138 : int = stretch_tables[0] + (int(c2da_mem[src_3 + 1]) * 256 + int(c2da_mem[src_3 + 0]))
        let c2da_fresh139 : uint8 = c2da_mem[c2da_fresh138]
        c2da_mem[c2da_fresh137] = c2da_fresh139
        let c2da_fresh140 : int = dest_7
        dest_7++
        let c2da_fresh141 : int = stretch_tables[1] + (int(c2da_mem[src_3 + 2]) * 256 + int(c2da_mem[src_3 + 1]))
        let c2da_fresh142 : uint8 = c2da_mem[c2da_fresh141]
        c2da_mem[c2da_fresh140] = c2da_fresh142
        let c2da_fresh143 : int = dest_7
        dest_7++
        let c2da_fresh144 : int = stretch_tables[1] + (int(c2da_mem[src_3 + 2]) * 256 + int(c2da_mem[src_3 + 3]))
        let c2da_fresh145 : uint8 = c2da_mem[c2da_fresh144]
        c2da_mem[c2da_fresh143] = c2da_fresh145
        let c2da_fresh146 : int = dest_7
        dest_7++
        let c2da_fresh147 : int = stretch_tables[0] + (int(c2da_mem[src_3 + 3]) * 256 + int(c2da_mem[src_3 + 4]))
        let c2da_fresh148 : uint8 = c2da_mem[c2da_fresh147]
        c2da_mem[c2da_fresh146] = c2da_fresh148
        x_12 += 5
        src_3 += 5
    }
    return
}
[sideeffects]
def private I_Squash1x(var x1_9 : int; var y1_9 : int; var x2_9 : int; var y2_9 : int) : uint {
    var bufp_9 : int
    var screenp_9 : int
    if (x1_9 != 0 || y1_9 != 0 || x2_9 != 320 || y2_9 != 200) {
        return 0u
    }
    bufp_9 = src_buffer
    screenp_9 = dest_buffer
    for (y_10 in range(0, 200)) {
        WriteSquashedLine1x(screenp_9, bufp_9)
        screenp_9 += dest_pitch
        bufp_9 += 320
    }
    return 1u
}
var mode_squash_1x : screen_mode_t = screen_mode_t(width = 256, height = 200, InitMode = 161, DrawScreen = 167, poor_quality = 1u)

[sideeffects]
def private WriteSquashedLine2x(var dest_8 : int; var src_4 : int) {
    var dest2 : int
    var x_13 : int
    var c : int
    dest2 = dest_8 + dest_pitch
    x_13 = 0
    while (x_13 < 320) {
        c = int(c2da_mem[src_4 + 0])
        let c2da_fresh149 : int = dest_8
        dest_8++
        let c2da_fresh150 : int = dest2
        dest2++
        let c2da_fresh151 : uint8 = uint8(c)
        c2da_mem[c2da_fresh150] = c2da_fresh151
        c2da_mem[c2da_fresh149] = c2da_fresh151
        let c2da_fresh152 : int = stretch_tables[1] + (int(c2da_mem[src_4 + 1]) * 256 + int(c2da_mem[src_4 + 0]))
        c = int(c2da_mem[c2da_fresh152])
        let c2da_fresh153 : int = dest_8
        dest_8++
        let c2da_fresh154 : int = dest2
        dest2++
        let c2da_fresh155 : uint8 = uint8(c)
        c2da_mem[c2da_fresh154] = c2da_fresh155
        c2da_mem[c2da_fresh153] = c2da_fresh155
        c = int(c2da_mem[src_4 + 1])
        let c2da_fresh156 : int = dest_8
        dest_8++
        let c2da_fresh157 : int = dest2
        dest2++
        let c2da_fresh158 : uint8 = uint8(c)
        c2da_mem[c2da_fresh157] = c2da_fresh158
        c2da_mem[c2da_fresh156] = c2da_fresh158
        let c2da_fresh159 : int = stretch_tables[0] + (int(c2da_mem[src_4 + 1]) * 256 + int(c2da_mem[src_4 + 2]))
        c = int(c2da_mem[c2da_fresh159])
        let c2da_fresh160 : int = dest_8
        dest_8++
        let c2da_fresh161 : int = dest2
        dest2++
        let c2da_fresh162 : uint8 = uint8(c)
        c2da_mem[c2da_fresh161] = c2da_fresh162
        c2da_mem[c2da_fresh160] = c2da_fresh162
        let c2da_fresh163 : int = stretch_tables[0] + (int(c2da_mem[src_4 + 3]) * 256 + int(c2da_mem[src_4 + 2]))
        c = int(c2da_mem[c2da_fresh163])
        let c2da_fresh164 : int = dest_8
        dest_8++
        let c2da_fresh165 : int = dest2
        dest2++
        let c2da_fresh166 : uint8 = uint8(c)
        c2da_mem[c2da_fresh165] = c2da_fresh166
        c2da_mem[c2da_fresh164] = c2da_fresh166
        c = int(c2da_mem[src_4 + 3])
        let c2da_fresh167 : int = dest_8
        dest_8++
        let c2da_fresh168 : int = dest2
        dest2++
        let c2da_fresh169 : uint8 = uint8(c)
        c2da_mem[c2da_fresh168] = c2da_fresh169
        c2da_mem[c2da_fresh167] = c2da_fresh169
        let c2da_fresh170 : int = stretch_tables[1] + (int(c2da_mem[src_4 + 3]) * 256 + int(c2da_mem[src_4 + 4]))
        c = int(c2da_mem[c2da_fresh170])
        let c2da_fresh171 : int = dest_8
        dest_8++
        let c2da_fresh172 : int = dest2
        dest2++
        let c2da_fresh173 : uint8 = uint8(c)
        c2da_mem[c2da_fresh172] = c2da_fresh173
        c2da_mem[c2da_fresh171] = c2da_fresh173
        c = int(c2da_mem[src_4 + 4])
        let c2da_fresh174 : int = dest_8
        dest_8++
        let c2da_fresh175 : int = dest2
        dest2++
        let c2da_fresh176 : uint8 = uint8(c)
        c2da_mem[c2da_fresh175] = c2da_fresh176
        c2da_mem[c2da_fresh174] = c2da_fresh176
        x_13 += 5
        src_4 += 5
    }
    return
}
[sideeffects]
def private I_Squash2x(var x1_10 : int; var y1_10 : int; var x2_10 : int; var y2_10 : int) : uint {
    var bufp_10 : int
    var screenp_10 : int
    if (x1_10 != 0 || y1_10 != 0 || x2_10 != 320 || y2_10 != 200) {
        return 0u
    }
    bufp_10 = src_buffer
    screenp_10 = dest_buffer
    for (y_11 in range(0, 200)) {
        WriteSquashedLine2x(screenp_10, bufp_10)
        screenp_10 += dest_pitch * 2
        bufp_10 += 320
    }
    return 1u
}
var mode_squash_2x : screen_mode_t = screen_mode_t(width = 256 * 2, height = 200 * 2, InitMode = 161, DrawScreen = 168, poor_quality = 0u)

[sideeffects]
def private WriteSquashedLine3x(var dest_9 : int; var src_5 : int) {
    var dest2_0 : int
    var dest3 : int
    var x_14 : int
    var c_0 : int
    dest2_0 = dest_9 + dest_pitch
    dest3 = dest_9 + dest_pitch * 2
    x_14 = 0
    while (x_14 < 320) {
        c_0 = int(c2da_mem[src_5 + 0])
        let c2da_fresh177 : int = dest_9
        dest_9++
        let c2da_fresh178 : int = dest2_0
        dest2_0++
        let c2da_fresh179 : int = dest3
        dest3++
        let c2da_fresh180 : uint8 = uint8(c_0)
        c2da_mem[c2da_fresh179] = c2da_fresh180
        c2da_mem[c2da_fresh178] = c2da_fresh180
        c2da_mem[c2da_fresh177] = c2da_fresh180
        let c2da_fresh181 : int = dest_9
        dest_9++
        let c2da_fresh182 : int = dest2_0
        dest2_0++
        let c2da_fresh183 : int = dest3
        dest3++
        let c2da_fresh184 : uint8 = uint8(c_0)
        c2da_mem[c2da_fresh183] = c2da_fresh184
        c2da_mem[c2da_fresh182] = c2da_fresh184
        c2da_mem[c2da_fresh181] = c2da_fresh184
        let c2da_fresh185 : int = half_stretch_table + (int(c2da_mem[src_5 + 0]) * 256 + int(c2da_mem[src_5 + 1]))
        c_0 = int(c2da_mem[c2da_fresh185])
        let c2da_fresh186 : int = dest_9
        dest_9++
        let c2da_fresh187 : int = dest2_0
        dest2_0++
        let c2da_fresh188 : int = dest3
        dest3++
        let c2da_fresh189 : uint8 = uint8(c_0)
        c2da_mem[c2da_fresh188] = c2da_fresh189
        c2da_mem[c2da_fresh187] = c2da_fresh189
        c2da_mem[c2da_fresh186] = c2da_fresh189
        c_0 = int(c2da_mem[src_5 + 1])
        let c2da_fresh190 : int = dest_9
        dest_9++
        let c2da_fresh191 : int = dest2_0
        dest2_0++
        let c2da_fresh192 : int = dest3
        dest3++
        let c2da_fresh193 : uint8 = uint8(c_0)
        c2da_mem[c2da_fresh192] = c2da_fresh193
        c2da_mem[c2da_fresh191] = c2da_fresh193
        c2da_mem[c2da_fresh190] = c2da_fresh193
        let c2da_fresh194 : int = dest_9
        dest_9++
        let c2da_fresh195 : int = dest2_0
        dest2_0++
        let c2da_fresh196 : int = dest3
        dest3++
        let c2da_fresh197 : uint8 = uint8(c_0)
        c2da_mem[c2da_fresh196] = c2da_fresh197
        c2da_mem[c2da_fresh195] = c2da_fresh197
        c2da_mem[c2da_fresh194] = c2da_fresh197
        x_14 += 2
        src_5 += 2
    }
    return
}
[sideeffects]
def private I_Squash3x(var x1_11 : int; var y1_11 : int; var x2_11 : int; var y2_11 : int) : uint {
    var bufp_11 : int
    var screenp_11 : int
    if (x1_11 != 0 || y1_11 != 0 || x2_11 != 320 || y2_11 != 200) {
        return 0u
    }
    bufp_11 = src_buffer
    screenp_11 = dest_buffer
    for (y_12 in range(0, 200)) {
        WriteSquashedLine3x(screenp_11, bufp_11)
        screenp_11 += dest_pitch * 3
        bufp_11 += 320
    }
    return 1u
}
var mode_squash_3x : screen_mode_t = screen_mode_t(width = 800, height = 600, InitMode = 169, DrawScreen = 170, poor_quality = 0u)

[sideeffects]
def private WriteSquashedLine4x(var dest_10 : int; var src_6 : int) {
    var x_15 : int
    var c_1 : int
    var dest2_1 : int
    var dest3_0 : int
    var dest4 : int
    dest2_1 = dest_10 + dest_pitch
    dest3_0 = dest_10 + dest_pitch * 2
    dest4 = dest_10 + dest_pitch * 3
    x_15 = 0
    while (x_15 < 320) {
        c_1 = int(c2da_mem[src_6 + 0])
        let c2da_fresh198 : int = dest_10
        dest_10++
        let c2da_fresh199 : int = dest2_1
        dest2_1++
        let c2da_fresh200 : int = dest3_0
        dest3_0++
        let c2da_fresh201 : int = dest4
        dest4++
        let c2da_fresh202 : uint8 = uint8(c_1)
        c2da_mem[c2da_fresh201] = c2da_fresh202
        c2da_mem[c2da_fresh200] = c2da_fresh202
        c2da_mem[c2da_fresh199] = c2da_fresh202
        c2da_mem[c2da_fresh198] = c2da_fresh202
        let c2da_fresh203 : int = dest_10
        dest_10++
        let c2da_fresh204 : int = dest2_1
        dest2_1++
        let c2da_fresh205 : int = dest3_0
        dest3_0++
        let c2da_fresh206 : int = dest4
        dest4++
        let c2da_fresh207 : uint8 = uint8(c_1)
        c2da_mem[c2da_fresh206] = c2da_fresh207
        c2da_mem[c2da_fresh205] = c2da_fresh207
        c2da_mem[c2da_fresh204] = c2da_fresh207
        c2da_mem[c2da_fresh203] = c2da_fresh207
        let c2da_fresh208 : int = dest_10
        dest_10++
        let c2da_fresh209 : int = dest2_1
        dest2_1++
        let c2da_fresh210 : int = dest3_0
        dest3_0++
        let c2da_fresh211 : int = dest4
        dest4++
        let c2da_fresh212 : uint8 = uint8(c_1)
        c2da_mem[c2da_fresh211] = c2da_fresh212
        c2da_mem[c2da_fresh210] = c2da_fresh212
        c2da_mem[c2da_fresh209] = c2da_fresh212
        c2da_mem[c2da_fresh208] = c2da_fresh212
        let c2da_fresh213 : int = stretch_tables[0] + (int(c2da_mem[src_6 + 0]) * 256 + int(c2da_mem[src_6 + 1]))
        c_1 = int(c2da_mem[c2da_fresh213])
        let c2da_fresh214 : int = dest_10
        dest_10++
        let c2da_fresh215 : int = dest2_1
        dest2_1++
        let c2da_fresh216 : int = dest3_0
        dest3_0++
        let c2da_fresh217 : int = dest4
        dest4++
        let c2da_fresh218 : uint8 = uint8(c_1)
        c2da_mem[c2da_fresh217] = c2da_fresh218
        c2da_mem[c2da_fresh216] = c2da_fresh218
        c2da_mem[c2da_fresh215] = c2da_fresh218
        c2da_mem[c2da_fresh214] = c2da_fresh218
        c_1 = int(c2da_mem[src_6 + 1])
        let c2da_fresh219 : int = dest_10
        dest_10++
        let c2da_fresh220 : int = dest2_1
        dest2_1++
        let c2da_fresh221 : int = dest3_0
        dest3_0++
        let c2da_fresh222 : int = dest4
        dest4++
        let c2da_fresh223 : uint8 = uint8(c_1)
        c2da_mem[c2da_fresh222] = c2da_fresh223
        c2da_mem[c2da_fresh221] = c2da_fresh223
        c2da_mem[c2da_fresh220] = c2da_fresh223
        c2da_mem[c2da_fresh219] = c2da_fresh223
        let c2da_fresh224 : int = dest_10
        dest_10++
        let c2da_fresh225 : int = dest2_1
        dest2_1++
        let c2da_fresh226 : int = dest3_0
        dest3_0++
        let c2da_fresh227 : int = dest4
        dest4++
        let c2da_fresh228 : uint8 = uint8(c_1)
        c2da_mem[c2da_fresh227] = c2da_fresh228
        c2da_mem[c2da_fresh226] = c2da_fresh228
        c2da_mem[c2da_fresh225] = c2da_fresh228
        c2da_mem[c2da_fresh224] = c2da_fresh228
        let c2da_fresh229 : int = stretch_tables[1] + (int(c2da_mem[src_6 + 1]) * 256 + int(c2da_mem[src_6 + 2]))
        c_1 = int(c2da_mem[c2da_fresh229])
        let c2da_fresh230 : int = dest_10
        dest_10++
        let c2da_fresh231 : int = dest2_1
        dest2_1++
        let c2da_fresh232 : int = dest3_0
        dest3_0++
        let c2da_fresh233 : int = dest4
        dest4++
        let c2da_fresh234 : uint8 = uint8(c_1)
        c2da_mem[c2da_fresh233] = c2da_fresh234
        c2da_mem[c2da_fresh232] = c2da_fresh234
        c2da_mem[c2da_fresh231] = c2da_fresh234
        c2da_mem[c2da_fresh230] = c2da_fresh234
        c_1 = int(c2da_mem[src_6 + 2])
        let c2da_fresh235 : int = dest_10
        dest_10++
        let c2da_fresh236 : int = dest2_1
        dest2_1++
        let c2da_fresh237 : int = dest3_0
        dest3_0++
        let c2da_fresh238 : int = dest4
        dest4++
        let c2da_fresh239 : uint8 = uint8(c_1)
        c2da_mem[c2da_fresh238] = c2da_fresh239
        c2da_mem[c2da_fresh237] = c2da_fresh239
        c2da_mem[c2da_fresh236] = c2da_fresh239
        c2da_mem[c2da_fresh235] = c2da_fresh239
        let c2da_fresh240 : int = dest_10
        dest_10++
        let c2da_fresh241 : int = dest2_1
        dest2_1++
        let c2da_fresh242 : int = dest3_0
        dest3_0++
        let c2da_fresh243 : int = dest4
        dest4++
        let c2da_fresh244 : uint8 = uint8(c_1)
        c2da_mem[c2da_fresh243] = c2da_fresh244
        c2da_mem[c2da_fresh242] = c2da_fresh244
        c2da_mem[c2da_fresh241] = c2da_fresh244
        c2da_mem[c2da_fresh240] = c2da_fresh244
        let c2da_fresh245 : int = stretch_tables[1] + (int(c2da_mem[src_6 + 3]) * 256 + int(c2da_mem[src_6 + 2]))
        c_1 = int(c2da_mem[c2da_fresh245])
        let c2da_fresh246 : int = dest_10
        dest_10++
        let c2da_fresh247 : int = dest2_1
        dest2_1++
        let c2da_fresh248 : int = dest3_0
        dest3_0++
        let c2da_fresh249 : int = dest4
        dest4++
        let c2da_fresh250 : uint8 = uint8(c_1)
        c2da_mem[c2da_fresh249] = c2da_fresh250
        c2da_mem[c2da_fresh248] = c2da_fresh250
        c2da_mem[c2da_fresh247] = c2da_fresh250
        c2da_mem[c2da_fresh246] = c2da_fresh250
        c_1 = int(c2da_mem[src_6 + 3])
        let c2da_fresh251 : int = dest_10
        dest_10++
        let c2da_fresh252 : int = dest2_1
        dest2_1++
        let c2da_fresh253 : int = dest3_0
        dest3_0++
        let c2da_fresh254 : int = dest4
        dest4++
        let c2da_fresh255 : uint8 = uint8(c_1)
        c2da_mem[c2da_fresh254] = c2da_fresh255
        c2da_mem[c2da_fresh253] = c2da_fresh255
        c2da_mem[c2da_fresh252] = c2da_fresh255
        c2da_mem[c2da_fresh251] = c2da_fresh255
        let c2da_fresh256 : int = dest_10
        dest_10++
        let c2da_fresh257 : int = dest2_1
        dest2_1++
        let c2da_fresh258 : int = dest3_0
        dest3_0++
        let c2da_fresh259 : int = dest4
        dest4++
        let c2da_fresh260 : uint8 = uint8(c_1)
        c2da_mem[c2da_fresh259] = c2da_fresh260
        c2da_mem[c2da_fresh258] = c2da_fresh260
        c2da_mem[c2da_fresh257] = c2da_fresh260
        c2da_mem[c2da_fresh256] = c2da_fresh260
        let c2da_fresh261 : int = stretch_tables[0] + (int(c2da_mem[src_6 + 4]) * 256 + int(c2da_mem[src_6 + 3]))
        c_1 = int(c2da_mem[c2da_fresh261])
        let c2da_fresh262 : int = dest_10
        dest_10++
        let c2da_fresh263 : int = dest2_1
        dest2_1++
        let c2da_fresh264 : int = dest3_0
        dest3_0++
        let c2da_fresh265 : int = dest4
        dest4++
        let c2da_fresh266 : uint8 = uint8(c_1)
        c2da_mem[c2da_fresh265] = c2da_fresh266
        c2da_mem[c2da_fresh264] = c2da_fresh266
        c2da_mem[c2da_fresh263] = c2da_fresh266
        c2da_mem[c2da_fresh262] = c2da_fresh266
        c_1 = int(c2da_mem[src_6 + 4])
        let c2da_fresh267 : int = dest_10
        dest_10++
        let c2da_fresh268 : int = dest2_1
        dest2_1++
        let c2da_fresh269 : int = dest3_0
        dest3_0++
        let c2da_fresh270 : int = dest4
        dest4++
        let c2da_fresh271 : uint8 = uint8(c_1)
        c2da_mem[c2da_fresh270] = c2da_fresh271
        c2da_mem[c2da_fresh269] = c2da_fresh271
        c2da_mem[c2da_fresh268] = c2da_fresh271
        c2da_mem[c2da_fresh267] = c2da_fresh271
        let c2da_fresh272 : int = dest_10
        dest_10++
        let c2da_fresh273 : int = dest2_1
        dest2_1++
        let c2da_fresh274 : int = dest3_0
        dest3_0++
        let c2da_fresh275 : int = dest4
        dest4++
        let c2da_fresh276 : uint8 = uint8(c_1)
        c2da_mem[c2da_fresh275] = c2da_fresh276
        c2da_mem[c2da_fresh274] = c2da_fresh276
        c2da_mem[c2da_fresh273] = c2da_fresh276
        c2da_mem[c2da_fresh272] = c2da_fresh276
        let c2da_fresh277 : int = dest_10
        dest_10++
        let c2da_fresh278 : int = dest2_1
        dest2_1++
        let c2da_fresh279 : int = dest3_0
        dest3_0++
        let c2da_fresh280 : int = dest4
        dest4++
        let c2da_fresh281 : uint8 = uint8(c_1)
        c2da_mem[c2da_fresh280] = c2da_fresh281
        c2da_mem[c2da_fresh279] = c2da_fresh281
        c2da_mem[c2da_fresh278] = c2da_fresh281
        c2da_mem[c2da_fresh277] = c2da_fresh281
        x_15 += 5
        src_6 += 5
    }
    return
}
[sideeffects]
def private I_Squash4x(var x1_12 : int; var y1_12 : int; var x2_12 : int; var y2_12 : int) : uint {
    var bufp_12 : int
    var screenp_12 : int
    if (x1_12 != 0 || y1_12 != 0 || x2_12 != 320 || y2_12 != 200) {
        return 0u
    }
    bufp_12 = src_buffer
    screenp_12 = dest_buffer
    for (y_13 in range(0, 200)) {
        WriteSquashedLine4x(screenp_12, bufp_12)
        screenp_12 += dest_pitch * 4
        bufp_12 += 320
    }
    return 1u
}
var mode_squash_4x : screen_mode_t = screen_mode_t(width = 256 * 4, height = 200 * 4, InitMode = 161, DrawScreen = 171, poor_quality = 0u)

[sideeffects]
def private WriteSquashedLine5x(var dest_11 : int; var src_7 : int) {
    var c_2 : int
    var dest2_2 : int
    var dest3_1 : int
    var dest4_0 : int
    var dest5 : int
    dest2_2 = dest_11 + dest_pitch
    dest3_1 = dest_11 + dest_pitch * 2
    dest4_0 = dest_11 + dest_pitch * 3
    dest5 = dest_11 + dest_pitch * 4
    for (x_16 in range(0, 320)) {
        let c2da_fresh282 : int = src_7
        src_7++
        c_2 = int(c2da_mem[c2da_fresh282])
        let c2da_fresh283 : int = dest_11
        dest_11++
        let c2da_fresh284 : int = dest2_2
        dest2_2++
        let c2da_fresh285 : int = dest3_1
        dest3_1++
        let c2da_fresh286 : int = dest4_0
        dest4_0++
        let c2da_fresh287 : int = dest5
        dest5++
        let c2da_fresh288 : uint8 = uint8(c_2)
        c2da_mem[c2da_fresh287] = c2da_fresh288
        c2da_mem[c2da_fresh286] = c2da_fresh288
        c2da_mem[c2da_fresh285] = c2da_fresh288
        c2da_mem[c2da_fresh284] = c2da_fresh288
        c2da_mem[c2da_fresh283] = c2da_fresh288
        let c2da_fresh289 : int = dest_11
        dest_11++
        let c2da_fresh290 : int = dest2_2
        dest2_2++
        let c2da_fresh291 : int = dest3_1
        dest3_1++
        let c2da_fresh292 : int = dest4_0
        dest4_0++
        let c2da_fresh293 : int = dest5
        dest5++
        let c2da_fresh294 : uint8 = uint8(c_2)
        c2da_mem[c2da_fresh293] = c2da_fresh294
        c2da_mem[c2da_fresh292] = c2da_fresh294
        c2da_mem[c2da_fresh291] = c2da_fresh294
        c2da_mem[c2da_fresh290] = c2da_fresh294
        c2da_mem[c2da_fresh289] = c2da_fresh294
        let c2da_fresh295 : int = dest_11
        dest_11++
        let c2da_fresh296 : int = dest2_2
        dest2_2++
        let c2da_fresh297 : int = dest3_1
        dest3_1++
        let c2da_fresh298 : int = dest4_0
        dest4_0++
        let c2da_fresh299 : int = dest5
        dest5++
        let c2da_fresh300 : uint8 = uint8(c_2)
        c2da_mem[c2da_fresh299] = c2da_fresh300
        c2da_mem[c2da_fresh298] = c2da_fresh300
        c2da_mem[c2da_fresh297] = c2da_fresh300
        c2da_mem[c2da_fresh296] = c2da_fresh300
        c2da_mem[c2da_fresh295] = c2da_fresh300
        let c2da_fresh301 : int = dest_11
        dest_11++
        let c2da_fresh302 : int = dest2_2
        dest2_2++
        let c2da_fresh303 : int = dest3_1
        dest3_1++
        let c2da_fresh304 : int = dest4_0
        dest4_0++
        let c2da_fresh305 : int = dest5
        dest5++
        let c2da_fresh306 : uint8 = uint8(c_2)
        c2da_mem[c2da_fresh305] = c2da_fresh306
        c2da_mem[c2da_fresh304] = c2da_fresh306
        c2da_mem[c2da_fresh303] = c2da_fresh306
        c2da_mem[c2da_fresh302] = c2da_fresh306
        c2da_mem[c2da_fresh301] = c2da_fresh306
    }
    return
}
[sideeffects]
def private I_Squash5x(var x1_13 : int; var y1_13 : int; var x2_13 : int; var y2_13 : int) : uint {
    var bufp_13 : int
    var screenp_13 : int
    if (x1_13 != 0 || y1_13 != 0 || x2_13 != 320 || y2_13 != 200) {
        return 0u
    }
    bufp_13 = src_buffer
    screenp_13 = dest_buffer
    for (y_14 in range(0, 200)) {
        WriteSquashedLine5x(screenp_13, bufp_13)
        screenp_13 += dest_pitch * 5
        bufp_13 += 320
    }
    return 1u
}
var mode_squash_5x : screen_mode_t = screen_mode_t(width = 256 * 5, height = 200 * 5, InitMode = 161, DrawScreen = 172, poor_quality = 0u)


// This unit's static data, at heap offset 345184.
let private c2da_lin_static_i_scale_seg = fixed_array<int>(345184, 209)
let private c2da_lin_static_i_scale = fixed_array<uint64>(0x745374696e495f49ul, 0x6261546863746572ul, 0x6e6547203a73656cul, 0x20676e6974617265ul, 0x742070756b6f6f6cul, 0x2e2e73656c6261ul, 0xa7325002e2eul, 0x715374696e495f49ul, 0x6c62615468736175ul, 0x72656e6547203a65ul, 0x6f6c20676e697461ul, 0x6261742070756b6ful, 0x525f49002e2e656cul, 0x6c61635374657365ul, 0x3a73656c62615465ul, 0x72656e6567655220ul, 0x6f6c20676e697461ul, 0x6261742070756b6ful, 0x49000a2e2e73656cul, 0x635374657365525ful, 0x656c626154656c61ul, 0x6e65676552203a73ul, 0x20676e6974617265ul, 0x742070756b6f6f6cul, 0xa2e2e656c6261ul, 0x6e696c6e6163732dul, 0x65ul)

[init]
def private c2da_lin_init_static_i_scale() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_i_scale_seg[s * 2]
        for (k in range(c2da_lin_static_i_scale_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_i_scale[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_i_scale() {
    if (length(c2da_fn_table4) < 173) {
        resize(c2da_fn_table4, 173)
    }
    c2da_fn_table4[156] = @@I_Scale1x
    c2da_fn_table4[157] = @@I_Scale2x
    c2da_fn_table4[158] = @@I_Scale3x
    c2da_fn_table4[159] = @@I_Scale4x
    c2da_fn_table4[160] = @@I_Scale5x
    c2da_fn_table4[162] = @@I_Stretch1x
    c2da_fn_table4[163] = @@I_Stretch2x
    c2da_fn_table4[164] = @@I_Stretch3x
    c2da_fn_table4[165] = @@I_Stretch4x
    c2da_fn_table4[166] = @@I_Stretch5x
    c2da_fn_table4[167] = @@I_Squash1x
    c2da_fn_table4[168] = @@I_Squash2x
    c2da_fn_table4[170] = @@I_Squash3x
    c2da_fn_table4[171] = @@I_Squash4x
    c2da_fn_table4[172] = @@I_Squash5x
    if (length(c2da_fn_table5) < 173) {
        resize(c2da_fn_table5, 173)
    }
    c2da_fn_table5[161] = @@I_InitStretchTables
    c2da_fn_table5[169] = @@I_InitSquashTable
}

[init]
def private c2da_lin_relink_init_i_scale() {
    c2da_relink_i_scale()
}
