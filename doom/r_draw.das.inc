var private c2da_str_r_draw_0 : array<int8> = [int8(82), int8(95), int8(68), int8(114), int8(97), int8(119), int8(67), int8(111), int8(108), int8(117), int8(109), int8(110), int8(58), int8(32), int8(37), int8(105), int8(32), int8(116), int8(111), int8(32), int8(37), int8(105), int8(32), int8(97), int8(116), int8(32), int8(37), int8(105), int8(0)]

var private c2da_str_r_draw_1 : array<int8> = [int8(82), int8(95), int8(68), int8(114), int8(97), int8(119), int8(70), int8(117), int8(122), int8(122), int8(67), int8(111), int8(108), int8(117), int8(109), int8(110), int8(58), int8(32), int8(37), int8(105), int8(32), int8(116), int8(111), int8(32), int8(37), int8(105), int8(32), int8(97), int8(116), int8(32), int8(37), int8(105), int8(0)]

var private c2da_str_r_draw_2 : array<int8> = [int8(82), int8(95), int8(68), int8(114), int8(97), int8(119), int8(83), int8(112), int8(97), int8(110), int8(58), int8(32), int8(37), int8(105), int8(32), int8(116), int8(111), int8(32), int8(37), int8(105), int8(32), int8(97), int8(116), int8(32), int8(37), int8(105), int8(0)]

var private c2da_str_r_draw_3 : array<int8> = [int8(70), int8(76), int8(79), int8(79), int8(82), int8(55), int8(95), int8(50), int8(0)]

var private c2da_str_r_draw_4 : array<int8> = [int8(71), int8(82), int8(78), int8(82), int8(79), int8(67), int8(75), int8(0)]

var private c2da_str_r_draw_5 : array<int8> = [int8(98), int8(114), int8(100), int8(114), int8(95), int8(116), int8(0)]

var private c2da_str_r_draw_6 : array<int8> = [int8(98), int8(114), int8(100), int8(114), int8(95), int8(98), int8(0)]

var private c2da_str_r_draw_7 : array<int8> = [int8(98), int8(114), int8(100), int8(114), int8(95), int8(108), int8(0)]

var private c2da_str_r_draw_8 : array<int8> = [int8(98), int8(114), int8(100), int8(114), int8(95), int8(114), int8(0)]

var private c2da_str_r_draw_9 : array<int8> = [int8(98), int8(114), int8(100), int8(114), int8(95), int8(116), int8(108), int8(0)]

var private c2da_str_r_draw_10 : array<int8> = [int8(98), int8(114), int8(100), int8(114), int8(95), int8(116), int8(114), int8(0)]

var private c2da_str_r_draw_11 : array<int8> = [int8(98), int8(114), int8(100), int8(114), int8(95), int8(98), int8(108), int8(0)]

var private c2da_str_r_draw_12 : array<int8> = [int8(98), int8(114), int8(100), int8(114), int8(95), int8(98), int8(114), int8(0)]

var viewwidth : int = default<int>

var scaledviewwidth : int = default<int>

var viewheight : int = default<int>

var viewwindowx : int = default<int>

var viewwindowy : int = default<int>

var dc_colormap : uint8? = default<uint8?>

var dc_x : int = default<int>

var dc_yl : int = default<int>

var dc_yh : int = default<int>

var dc_iscale : int = default<int>

var dc_texturemid : int = default<int>

var dc_source : uint8? = default<uint8?>

[export, sideeffects]
def R_DrawColumn() {
    var count : int
    var dest : uint8?
    var frac : int
    var fracstep : int
    count = dc_yh - dc_yl
    if (count < 0) {
        return
    }
    if (uint(dc_x) >= 320u || dc_yl < 0 || dc_yh >= 200) {
        I_Error(unsafe(addr<int8?>(c2da_str_r_draw_0[0])), [C2daVaArg(tag = 1, i64 = int64(dc_yl), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_yh), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_x), f64 = 0.0lf, raw = 0x0)])
    }
    dest = unsafe(reinterpret<uint8?>(unsafe(ylookup[dc_yl] + columnofs[dc_x])))
    fracstep = dc_iscale
    frac = dc_texturemid + (dc_yl - centery) * fracstep
    var c2da_dest_addr : uint64 = unsafe(reinterpret<uint64>(dest))
    for (c2da_iter in urange64(0ul, uint64(uint(count)) + 1ul)) {
        *unsafe(reinterpret<uint8?>(c2da_dest_addr)) = uint8(unsafe(dc_colormap[int(unsafe(dc_source[frac >> 16 & 127]))]))  // nolint:PERF020
        c2da_dest_addr += 320ul
        frac += fracstep
    }
    return
}
var columnofs : int[1120]

var ylookup : uint8? [832]

[export, sideeffects]
def R_DrawColumnLow() {
    var count_0 : int
    var dest_0 : uint8?
    var dest2 : uint8?
    var frac_0 : int
    var fracstep_0 : int
    var x : int
    count_0 = dc_yh - dc_yl
    if (count_0 < 0) {
        return
    }
    if (uint(dc_x) >= 320u || dc_yl < 0 || dc_yh >= 200) {
        I_Error(unsafe(addr<int8?>(c2da_str_r_draw_0[0])), [C2daVaArg(tag = 1, i64 = int64(dc_yl), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_yh), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_x), f64 = 0.0lf, raw = 0x0)])
    }
    x = dc_x << 1
    dest_0 = unsafe(reinterpret<uint8?>(unsafe(ylookup[dc_yl] + columnofs[x])))
    dest2 = unsafe(reinterpret<uint8?>(unsafe(ylookup[dc_yl] + columnofs[x + 1])))
    fracstep_0 = dc_iscale
    frac_0 = dc_texturemid + (dc_yl - centery) * fracstep_0
    var c2da_dest_0_addr : uint64 = unsafe(reinterpret<uint64>(dest_0))
    var c2da_dest2_addr : uint64 = unsafe(reinterpret<uint64>(dest2))
    for (c2da_iter_0 in urange64(0ul, uint64(uint(count_0)) + 1ul)) {
        *unsafe(reinterpret<uint8?>(c2da_dest_0_addr)) = uint8(unsafe(dc_colormap[int(unsafe(dc_source[frac_0 >> 16 & 127]))]))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest_0_addr)))  // nolint:PERF020
        c2da_dest_0_addr += 320ul
        c2da_dest2_addr += 320ul
        frac_0 += fracstep_0
    }
    return
}
[export, sideeffects]
def R_DrawFuzzColumn() {
    var count_1 : int
    var dest_1 : uint8?
    var frac_1 : int
    var fracstep_1 : int
    if (dc_yl == 0) {
        dc_yl = 1
    }
    if (dc_yh == viewheight - 1) {
        dc_yh = viewheight - 2
    }
    count_1 = dc_yh - dc_yl
    if (count_1 < 0) {
        return
    }
    if (uint(dc_x) >= 320u || dc_yl < 0 || dc_yh >= 200) {
        I_Error(unsafe(addr<int8?>(c2da_str_r_draw_1[0])), [C2daVaArg(tag = 1, i64 = int64(dc_yl), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_yh), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_x), f64 = 0.0lf, raw = 0x0)])
    }
    dest_1 = unsafe(reinterpret<uint8?>(unsafe(ylookup[dc_yl] + columnofs[dc_x])))
    fracstep_1 = dc_iscale
    frac_1 = dc_texturemid + (dc_yl - centery) * fracstep_1
    var c2da_dest_1_addr : uint64 = unsafe(reinterpret<uint64>(dest_1))
    for (c2da_iter_1 in urange64(0ul, uint64(uint(count_1)) + 1ul)) {
        *unsafe(reinterpret<uint8?>(c2da_dest_1_addr)) = uint8(unsafe(colormaps[6 * 256 + int(unsafe(unsafe(reinterpret<uint8?>(c2da_dest_1_addr))[fuzzoffset[fuzzpos]]))]))
        fuzzpos++
        if (fuzzpos == 50) {
            fuzzpos = 0
        }
        c2da_dest_1_addr += 320ul
        frac_1 += fracstep_1
    }
    return
}
var fuzzpos : int = 0

var fuzzoffset : int[50] = fixed_array<int>(320, -320, 320, -320, 320, 320, -320, 320, 320, -320, 320, 320, 320, -320, 320, 320, 320, -320, -320, -320, -320, 320, -320, -320, 320, 320, 320, 320, -320, 320, -320, 320, 320, -320, -320, 320, 320, -320, -320, -320, -320, 320, 320, 320, 320, -320, 320, 320, -320, 320)

[export, sideeffects]
def R_DrawFuzzColumnLow() {
    var count_2 : int
    var dest_2 : uint8?
    var dest2_0 : uint8?
    var frac_2 : int
    var fracstep_2 : int
    var x_0 : int
    if (dc_yl == 0) {
        dc_yl = 1
    }
    if (dc_yh == viewheight - 1) {
        dc_yh = viewheight - 2
    }
    count_2 = dc_yh - dc_yl
    if (count_2 < 0) {
        return
    }
    x_0 = dc_x << 1
    if (uint(x_0) >= 320u || dc_yl < 0 || dc_yh >= 200) {
        I_Error(unsafe(addr<int8?>(c2da_str_r_draw_1[0])), [C2daVaArg(tag = 1, i64 = int64(dc_yl), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_yh), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_x), f64 = 0.0lf, raw = 0x0)])
    }
    dest_2 = unsafe(reinterpret<uint8?>(unsafe(ylookup[dc_yl] + columnofs[x_0])))
    dest2_0 = unsafe(reinterpret<uint8?>(unsafe(ylookup[dc_yl] + columnofs[x_0 + 1])))
    fracstep_2 = dc_iscale
    frac_2 = dc_texturemid + (dc_yl - centery) * fracstep_2
    var c2da_dest_2_addr : uint64 = unsafe(reinterpret<uint64>(dest_2))
    var c2da_dest2_0_addr : uint64 = unsafe(reinterpret<uint64>(dest2_0))
    for (c2da_iter_2 in urange64(0ul, uint64(uint(count_2)) + 1ul)) {
        *unsafe(reinterpret<uint8?>(c2da_dest_2_addr)) = uint8(unsafe(colormaps[6 * 256 + int(unsafe(unsafe(reinterpret<uint8?>(c2da_dest_2_addr))[fuzzoffset[fuzzpos]]))]))
        *unsafe(reinterpret<uint8?>(c2da_dest2_0_addr)) = uint8(unsafe(colormaps[6 * 256 + int(unsafe(unsafe(reinterpret<uint8?>(c2da_dest2_0_addr))[fuzzoffset[fuzzpos]]))]))
        fuzzpos++
        if (fuzzpos == 50) {
            fuzzpos = 0
        }
        c2da_dest_2_addr += 320ul
        c2da_dest2_0_addr += 320ul
        frac_2 += fracstep_2
    }
    return
}
[export, sideeffects]
def R_DrawTranslatedColumn() {
    var count_3 : int
    var dest_3 : uint8?
    var frac_3 : int
    var fracstep_3 : int
    count_3 = dc_yh - dc_yl
    if (count_3 < 0) {
        return
    }
    if (uint(dc_x) >= 320u || dc_yl < 0 || dc_yh >= 200) {
        I_Error(unsafe(addr<int8?>(c2da_str_r_draw_0[0])), [C2daVaArg(tag = 1, i64 = int64(dc_yl), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_yh), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_x), f64 = 0.0lf, raw = 0x0)])
    }
    dest_3 = unsafe(reinterpret<uint8?>(unsafe(ylookup[dc_yl] + columnofs[dc_x])))
    fracstep_3 = dc_iscale
    frac_3 = dc_texturemid + (dc_yl - centery) * fracstep_3
    var c2da_dest_3_addr : uint64 = unsafe(reinterpret<uint64>(dest_3))
    for (c2da_iter_3 in urange64(0ul, uint64(uint(count_3)) + 1ul)) {
        *unsafe(reinterpret<uint8?>(c2da_dest_3_addr)) = uint8(unsafe(dc_colormap[int(unsafe(dc_translation[int(unsafe(dc_source[frac_3 >> 16]))]))]))  // nolint:PERF020
        c2da_dest_3_addr += 320ul
        frac_3 += fracstep_3
    }
    return
}
var dc_translation : uint8? = default<uint8?>

[export, sideeffects]
def R_DrawTranslatedColumnLow() {
    var count_4 : int
    var dest_4 : uint8?
    var dest2_1 : uint8?
    var frac_4 : int
    var fracstep_4 : int
    var x_1 : int
    count_4 = dc_yh - dc_yl
    if (count_4 < 0) {
        return
    }
    x_1 = dc_x << 1
    if (uint(x_1) >= 320u || dc_yl < 0 || dc_yh >= 200) {
        I_Error(unsafe(addr<int8?>(c2da_str_r_draw_0[0])), [C2daVaArg(tag = 1, i64 = int64(dc_yl), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_yh), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(x_1), f64 = 0.0lf, raw = 0x0)])
    }
    dest_4 = unsafe(reinterpret<uint8?>(unsafe(ylookup[dc_yl] + columnofs[x_1])))
    dest2_1 = unsafe(reinterpret<uint8?>(unsafe(ylookup[dc_yl] + columnofs[x_1 + 1])))
    fracstep_4 = dc_iscale
    frac_4 = dc_texturemid + (dc_yl - centery) * fracstep_4
    var c2da_dest_4_addr : uint64 = unsafe(reinterpret<uint64>(dest_4))
    var c2da_dest2_1_addr : uint64 = unsafe(reinterpret<uint64>(dest2_1))
    for (c2da_iter_4 in urange64(0ul, uint64(uint(count_4)) + 1ul)) {
        *unsafe(reinterpret<uint8?>(c2da_dest_4_addr)) = uint8(unsafe(dc_colormap[int(unsafe(dc_translation[int(unsafe(dc_source[frac_4 >> 16]))]))]))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)) = uint8(unsafe(dc_colormap[int(unsafe(dc_translation[int(unsafe(dc_source[frac_4 >> 16]))]))]))  // nolint:PERF020
        c2da_dest_4_addr += 320ul
        c2da_dest2_1_addr += 320ul
        frac_4 += fracstep_4
    }
    return
}
[export, sideeffects]
def R_VideoErase(var ofs : uint; var count_5 : int) {
    if (background_buffer != null) {
        var c2da_fresh0 : uint8? = unsafe(reinterpret<uint8?>(unsafe(I_VideoBuffer + int64(ofs))))
        var c2da_fresh1 : uint8? = unsafe(reinterpret<uint8?>(unsafe(background_buffer + int64(ofs))))
        let c2da_fresh2 : uint64 = unsafe(reinterpret<uint64>(c2da_fresh0))
        let c2da_fresh3 : uint64 = unsafe(reinterpret<uint64>(c2da_fresh1))
        let c2da_fresh4 : uint64 = uint64(count_5)
        if (c2da_fresh4 != 0x0) {
            unsafe(memcpy(unsafe(reinterpret<void?>(c2da_fresh2)), unsafe(reinterpret<void?>(c2da_fresh3)), c2da_fresh4))
        }
    }
    return
}
var private background_buffer : uint8? = null

var ds_y : int = default<int>

var ds_x1 : int = default<int>

var ds_x2 : int = default<int>

var ds_colormap : uint8? = default<uint8?>

var ds_xfrac : int = default<int>

var ds_yfrac : int = default<int>

var ds_xstep : int = default<int>

var ds_ystep : int = default<int>

var ds_source : uint8? = default<uint8?>

var translationtables : uint8? = default<uint8?>

[export, sideeffects]
def R_DrawSpan() {
    var position : uint
    var step : uint
    var dest_5 : uint8?
    var count_6 : int
    if (ds_x2 < ds_x1 || ds_x1 < 0 || ds_x2 >= 320 || uint(ds_y) > 200u) {
        I_Error(unsafe(addr<int8?>(c2da_str_r_draw_2[0])), [C2daVaArg(tag = 1, i64 = int64(ds_x1), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(ds_x2), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(ds_y), f64 = 0.0lf, raw = 0x0)])
    }
    position = uint(ds_xfrac << 10) & 0xffff0000u | uint(ds_yfrac >> 6 & 65535)
    step = uint(ds_xstep << 10) & 0xffff0000u | uint(ds_ystep >> 6 & 65535)
    dest_5 = unsafe(reinterpret<uint8?>(unsafe(ylookup[ds_y] + columnofs[ds_x1])))
    count_6 = ds_x2 - ds_x1
    var c2da_dest_5_addr : uint64 = unsafe(reinterpret<uint64>(dest_5))
    for (c2da_iter_5 in urange64(0ul, uint64(uint(count_6)) + 1ul)) {
        *unsafe(reinterpret<uint8?>(c2da_dest_5_addr)) = uint8(unsafe(ds_colormap[int(unsafe(ds_source[int(position >> 26u | position >> 4u & 0xfc0u)]))]))  // nolint:PERF020
        c2da_dest_5_addr++
        position += step
    }
    return
}
[export, sideeffects]
def R_DrawSpanLow() {
    var position_0 : uint
    var step_0 : uint
    var dest_6 : uint8?
    var count_7 : int
    var spot_0 : int
    if (ds_x2 < ds_x1 || ds_x1 < 0 || ds_x2 >= 320 || uint(ds_y) > 200u) {
        I_Error(unsafe(addr<int8?>(c2da_str_r_draw_2[0])), [C2daVaArg(tag = 1, i64 = int64(ds_x1), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(ds_x2), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(ds_y), f64 = 0.0lf, raw = 0x0)])
    }
    position_0 = uint(ds_xfrac << 10) & 0xffff0000u | uint(ds_yfrac >> 6 & 65535)
    step_0 = uint(ds_xstep << 10) & 0xffff0000u | uint(ds_ystep >> 6 & 65535)
    count_7 = ds_x2 - ds_x1
    ds_x1 <<= 1
    ds_x2 <<= 1
    dest_6 = unsafe(reinterpret<uint8?>(unsafe(ylookup[ds_y] + columnofs[ds_x1])))
    var c2da_dest_6_addr : uint64 = unsafe(reinterpret<uint64>(dest_6))
    for (c2da_iter_6 in urange64(0ul, uint64(uint(count_7)) + 1ul)) {
        spot_0 = int(position_0 >> 26u | position_0 >> 4u & 0xfc0u)
        *unsafe(reinterpret<uint8?>(c2da_dest_6_addr)) = uint8(unsafe(ds_colormap[int(unsafe(ds_source[spot_0]))]))  // nolint:PERF020
        c2da_dest_6_addr++
        *unsafe(reinterpret<uint8?>(c2da_dest_6_addr)) = uint8(unsafe(ds_colormap[int(unsafe(ds_source[spot_0]))]))  // nolint:PERF020
        c2da_dest_6_addr++
        position_0 += step_0
    }
    return
}
[export, sideeffects]
def R_InitBuffer(var width : int; var height : int) {
    var i : int
    viewwindowx = 320 - width >> 1
    i = 0
    while (i < width) {
        columnofs[i] = viewwindowx + i
        i++
    }
    if (width == 320) {
        viewwindowy = 0
    } else {
        viewwindowy = 200 - 32 - height >> 1
    }
    i = 0
    for (c2da_i in range(i, height)) {
        ylookup[c2da_i] = unsafe(reinterpret<uint8?>(unsafe(I_VideoBuffer + int64((c2da_i + viewwindowy) * 320))))
    }
    return
}
[export, sideeffects]
def R_InitTranslationTables() {
    translationtables = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(Z_Malloc(256 * 3, 1, null)))))
    for (i_0 in range(0, 256)) {
        if (i_0 >= 112 && i_0 <= 127) {
            unsafe(translationtables[i_0]) = uint8(96 + (i_0 & 15))
            unsafe(translationtables[i_0 + 256]) = uint8(64 + (i_0 & 15))
            unsafe(translationtables[i_0 + 512]) = uint8(32 + (i_0 & 15))
        } else {
            unsafe(translationtables[i_0 + 512]) = uint8(i_0)
            unsafe(translationtables[i_0 + 256]) = uint8(unsafe(translationtables[i_0 + 512]))  // nolint:PERF020
            unsafe(translationtables[i_0]) = uint8(unsafe(translationtables[i_0 + 256]))  // nolint:PERF020
        }
    }
    return
}
[export, sideeffects]
def R_FillBackScreen() {
    var src : uint8?
    var dest_7 : uint8?
    var x_2 : int
    var y : int
    var patch : patch_t?
    var name1 : int8?
    var name2 : int8?
    var name : int8?
    name1 = unsafe(addr(c2da_str_r_draw_3[0]))
    name2 = unsafe(addr(c2da_str_r_draw_4[0]))
    if (scaledviewwidth == 320) {
        if (background_buffer != null) {
            Z_Free(unsafe(reinterpret<uint8?>(background_buffer)))
            background_buffer = null
        }
        return
    }
    if (background_buffer == null) {
        background_buffer = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(Z_Malloc(320 * (200 - 32), 1, null)))))
    }
    if (uint(gamemode) == 2u) {
        name = unsafe(reinterpret<int8?>(name2))
    } else {
        name = unsafe(reinterpret<int8?>(name1))
    }
    src = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(W_CacheLumpName(name, 8)))))
    dest_7 = unsafe(reinterpret<uint8?>(background_buffer))
    y = 0
    while (y < 200 - 32) {
        x_2 = 0
        while (x_2 < 320 / 64) {
            var c2da_fresh5 : uint8? = unsafe(reinterpret<uint8?>(unsafe(src + int64((y & 63) << 6))))
            unsafe(memcpy(unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(dest_7)))))), unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(c2da_fresh5)))), 64ul))
            unsafe {  // nolint:STYLE025
                dest_7 += 64
            }
            x_2++
        }
        if ((320 & 63) != 0) {
            var c2da_fresh6 : uint8? = unsafe(reinterpret<uint8?>(unsafe(src + int64((y & 63) << 6))))
            let c2da_fresh7 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(dest_7))))
            let c2da_fresh8 : uint64 = unsafe(reinterpret<uint64>(c2da_fresh6))
            let c2da_fresh9 : uint64 = uint64(320 & 63)
            if (c2da_fresh9 != 0x0) {
                unsafe(memcpy(unsafe(reinterpret<void?>(c2da_fresh7)), unsafe(reinterpret<void?>(c2da_fresh8)), c2da_fresh9))
            }
            unsafe {  // nolint:STYLE025
                dest_7 += 320 & 63
            }
        }
        y++
    }
    V_UseBuffer(background_buffer)
    patch = unsafe(reinterpret<patch_t?>(unsafe(reinterpret<patch_t?>(W_CacheLumpName(unsafe(addr<int8?>(c2da_str_r_draw_5[0])), 8)))))
    x_2 = 0
    while (x_2 < scaledviewwidth) {
        V_DrawPatch(viewwindowx + x_2, viewwindowy - 8, patch)
        x_2 += 8
    }
    patch = unsafe(reinterpret<patch_t?>(unsafe(reinterpret<patch_t?>(W_CacheLumpName(unsafe(addr<int8?>(c2da_str_r_draw_6[0])), 8)))))
    x_2 = 0
    while (x_2 < scaledviewwidth) {
        V_DrawPatch(viewwindowx + x_2, viewwindowy + viewheight, patch)
        x_2 += 8
    }
    patch = unsafe(reinterpret<patch_t?>(unsafe(reinterpret<patch_t?>(W_CacheLumpName(unsafe(addr<int8?>(c2da_str_r_draw_7[0])), 8)))))
    y = 0
    while (y < viewheight) {
        V_DrawPatch(viewwindowx - 8, viewwindowy + y, patch)
        y += 8
    }
    patch = unsafe(reinterpret<patch_t?>(unsafe(reinterpret<patch_t?>(W_CacheLumpName(unsafe(addr<int8?>(c2da_str_r_draw_8[0])), 8)))))
    y = 0
    while (y < viewheight) {
        V_DrawPatch(viewwindowx + scaledviewwidth, viewwindowy + y, patch)
        y += 8
    }
    V_DrawPatch(viewwindowx - 8, viewwindowy - 8, unsafe(reinterpret<patch_t?>(W_CacheLumpName(unsafe(addr<int8?>(c2da_str_r_draw_9[0])), 8))))
    V_DrawPatch(viewwindowx + scaledviewwidth, viewwindowy - 8, unsafe(reinterpret<patch_t?>(W_CacheLumpName(unsafe(addr<int8?>(c2da_str_r_draw_10[0])), 8))))
    V_DrawPatch(viewwindowx - 8, viewwindowy + viewheight, unsafe(reinterpret<patch_t?>(W_CacheLumpName(unsafe(addr<int8?>(c2da_str_r_draw_11[0])), 8))))
    V_DrawPatch(viewwindowx + scaledviewwidth, viewwindowy + viewheight, unsafe(reinterpret<patch_t?>(W_CacheLumpName(unsafe(addr<int8?>(c2da_str_r_draw_12[0])), 8))))
    V_RestoreBuffer()
    return
}
[export, sideeffects]
def R_DrawViewBorder() {
    var top : int
    var side : int
    var ofs_0 : int
    var i_1 : int
    if (scaledviewwidth == 320) {
        return
    }
    top = (200 - 32 - viewheight) / 2
    side = (320 - scaledviewwidth) / 2
    R_VideoErase(0u, top * 320 + side)
    ofs_0 = (viewheight + top) * 320 - side
    R_VideoErase(uint(ofs_0), top * 320 + side)
    ofs_0 = top * 320 + 320 - side
    side <<= 1
    i_1 = 1
    while (i_1 < viewheight) {
        R_VideoErase(uint(ofs_0), side)
        ofs_0 += 320
        i_1++
    }
    V_MarkRect(0, 0, 320, 200 - 32)
    return
}
var viewimage : uint8? = default<uint8?>

var translations : uint8[3][256]

var dccount : int = default<int>

var dscount : int = default<int>

