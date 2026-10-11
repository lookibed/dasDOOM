var viewwidth : int = default<int>

var scaledviewwidth : int = default<int>

var viewheight : int = default<int>

var viewwindowx : int = default<int>

var viewwindowy : int = default<int>

var dc_colormap : int = default<int>

var dc_x : int = default<int>

var dc_yl : int = default<int>

var dc_yh : int = default<int>

var dc_iscale : int = default<int>

var dc_texturemid : int = default<int>

var dc_source : int = default<int>

[export, sideeffects]
def R_DrawColumn() {
    var count : int
    var dest : int
    var frac : int
    var fracstep : int
    count = dc_yh - dc_yl
    if (count < 0) {
        return
    }
    if (uint(dc_x) >= 320u || dc_yl < 0 || dc_yh >= 200) {
        I_Error(362272, [C2daVaArg(tag = 1, i64 = int64(dc_yl), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_yh), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_x), f64 = 0.0lf, raw = 0x0)])
    }
    dest = ylookup[dc_yl] + columnofs[dc_x]
    fracstep = dc_iscale
    frac = dc_texturemid + (dc_yl - centery) * fracstep
    for (c2da_iter in urange64(0ul, uint64(uint(count)) + 1ul)) {
        let c2da_fresh0 : int = dc_source + (frac >> 16 & 127)
        let c2da_fresh1 : int = dc_colormap + int(c2da_mem[c2da_fresh0])
        let c2da_fresh2 : uint8 = c2da_mem[c2da_fresh1]
        c2da_mem[dest] = c2da_fresh2
        dest += 320
        frac += fracstep
    }
    return
}
var columnofs : int[1120]

var ylookup : int[832]

[export, sideeffects]
def R_DrawColumnLow() {
    var count_0 : int
    var dest_0 : int
    var dest2 : int
    var frac_0 : int
    var fracstep_0 : int
    var x : int
    count_0 = dc_yh - dc_yl
    if (count_0 < 0) {
        return
    }
    if (uint(dc_x) >= 320u || dc_yl < 0 || dc_yh >= 200) {
        I_Error(362272, [C2daVaArg(tag = 1, i64 = int64(dc_yl), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_yh), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_x), f64 = 0.0lf, raw = 0x0)])
    }
    x = dc_x << 1
    dest_0 = ylookup[dc_yl] + columnofs[x]
    dest2 = ylookup[dc_yl] + columnofs[x + 1]
    fracstep_0 = dc_iscale
    frac_0 = dc_texturemid + (dc_yl - centery) * fracstep_0
    for (c2da_iter_0 in urange64(0ul, uint64(uint(count_0)) + 1ul)) {
        let c2da_fresh3 : int = dc_source + (frac_0 >> 16 & 127)
        let c2da_fresh4 : int = dc_colormap + int(c2da_mem[c2da_fresh3])
        let c2da_fresh5 : uint8 = c2da_mem[c2da_fresh4]
        c2da_mem[dest_0] = c2da_fresh5
        c2da_mem[dest2] = c2da_fresh5
        dest_0 += 320
        dest2 += 320
        frac_0 += fracstep_0
    }
    return
}
[export, sideeffects]
def R_DrawFuzzColumn() {
    var count_1 : int
    var dest_1 : int
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
        I_Error(362301, [C2daVaArg(tag = 1, i64 = int64(dc_yl), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_yh), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_x), f64 = 0.0lf, raw = 0x0)])
    }
    dest_1 = ylookup[dc_yl] + columnofs[dc_x]
    fracstep_1 = dc_iscale
    frac_1 = dc_texturemid + (dc_yl - centery) * fracstep_1
    for (c2da_iter_1 in urange64(0ul, uint64(uint(count_1)) + 1ul)) {
        let c2da_fresh6 : int = dest_1 + fuzzoffset[fuzzpos]
        let c2da_fresh7 : int = colormaps + (6 * 256 + int(c2da_mem[c2da_fresh6]))
        let c2da_fresh8 : uint8 = c2da_mem[c2da_fresh7]
        c2da_mem[dest_1] = c2da_fresh8
        fuzzpos++
        if (fuzzpos == 50) {
            fuzzpos = 0
        }
        dest_1 += 320
        frac_1 += fracstep_1
    }
    return
}
var fuzzpos : int = 0

var fuzzoffset : int[50] = fixed_array<int>(320, -320, 320, -320, 320, 320, -320, 320, 320, -320, 320, 320, 320, -320, 320, 320, 320, -320, -320, -320, -320, 320, -320, -320, 320, 320, 320, 320, -320, 320, -320, 320, 320, -320, -320, 320, 320, -320, -320, -320, -320, 320, 320, 320, 320, -320, 320, 320, -320, 320)

[export, sideeffects]
def R_DrawFuzzColumnLow() {
    var count_2 : int
    var dest_2 : int
    var dest2_0 : int
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
        I_Error(362301, [C2daVaArg(tag = 1, i64 = int64(dc_yl), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_yh), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_x), f64 = 0.0lf, raw = 0x0)])
    }
    dest_2 = ylookup[dc_yl] + columnofs[x_0]
    dest2_0 = ylookup[dc_yl] + columnofs[x_0 + 1]
    fracstep_2 = dc_iscale
    frac_2 = dc_texturemid + (dc_yl - centery) * fracstep_2
    for (c2da_iter_2 in urange64(0ul, uint64(uint(count_2)) + 1ul)) {
        let c2da_fresh9 : int = dest_2 + fuzzoffset[fuzzpos]
        let c2da_fresh10 : int = colormaps + (6 * 256 + int(c2da_mem[c2da_fresh9]))
        let c2da_fresh11 : uint8 = c2da_mem[c2da_fresh10]
        c2da_mem[dest_2] = c2da_fresh11
        let c2da_fresh12 : int = dest2_0 + fuzzoffset[fuzzpos]
        let c2da_fresh13 : int = colormaps + (6 * 256 + int(c2da_mem[c2da_fresh12]))
        let c2da_fresh14 : uint8 = c2da_mem[c2da_fresh13]
        c2da_mem[dest2_0] = c2da_fresh14
        fuzzpos++
        if (fuzzpos == 50) {
            fuzzpos = 0
        }
        dest_2 += 320
        dest2_0 += 320
        frac_2 += fracstep_2
    }
    return
}
[export, sideeffects]
def R_DrawTranslatedColumn() {
    var count_3 : int
    var dest_3 : int
    var frac_3 : int
    var fracstep_3 : int
    count_3 = dc_yh - dc_yl
    if (count_3 < 0) {
        return
    }
    if (uint(dc_x) >= 320u || dc_yl < 0 || dc_yh >= 200) {
        I_Error(362272, [C2daVaArg(tag = 1, i64 = int64(dc_yl), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_yh), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_x), f64 = 0.0lf, raw = 0x0)])
    }
    dest_3 = ylookup[dc_yl] + columnofs[dc_x]
    fracstep_3 = dc_iscale
    frac_3 = dc_texturemid + (dc_yl - centery) * fracstep_3
    for (c2da_iter_3 in urange64(0ul, uint64(uint(count_3)) + 1ul)) {
        let c2da_fresh15 : int = dc_source + (frac_3 >> 16)
        let c2da_fresh16 : int = dc_translation + int(c2da_mem[c2da_fresh15])
        let c2da_fresh17 : int = dc_colormap + int(c2da_mem[c2da_fresh16])
        let c2da_fresh18 : uint8 = c2da_mem[c2da_fresh17]
        c2da_mem[dest_3] = c2da_fresh18
        dest_3 += 320
        frac_3 += fracstep_3
    }
    return
}
var dc_translation : int = default<int>

[export, sideeffects]
def R_DrawTranslatedColumnLow() {
    var count_4 : int
    var dest_4 : int
    var dest2_1 : int
    var frac_4 : int
    var fracstep_4 : int
    var x_1 : int
    count_4 = dc_yh - dc_yl
    if (count_4 < 0) {
        return
    }
    x_1 = dc_x << 1
    if (uint(x_1) >= 320u || dc_yl < 0 || dc_yh >= 200) {
        I_Error(362272, [C2daVaArg(tag = 1, i64 = int64(dc_yl), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(dc_yh), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(x_1), f64 = 0.0lf, raw = 0x0)])
    }
    dest_4 = ylookup[dc_yl] + columnofs[x_1]
    dest2_1 = ylookup[dc_yl] + columnofs[x_1 + 1]
    fracstep_4 = dc_iscale
    frac_4 = dc_texturemid + (dc_yl - centery) * fracstep_4
    for (c2da_iter_4 in urange64(0ul, uint64(uint(count_4)) + 1ul)) {
        let c2da_fresh19 : int = dc_source + (frac_4 >> 16)
        let c2da_fresh20 : int = dc_translation + int(c2da_mem[c2da_fresh19])
        let c2da_fresh21 : int = dc_colormap + int(c2da_mem[c2da_fresh20])
        let c2da_fresh22 : uint8 = c2da_mem[c2da_fresh21]
        c2da_mem[dest_4] = c2da_fresh22
        let c2da_fresh23 : int = dc_source + (frac_4 >> 16)
        let c2da_fresh24 : int = dc_translation + int(c2da_mem[c2da_fresh23])
        let c2da_fresh25 : int = dc_colormap + int(c2da_mem[c2da_fresh24])
        let c2da_fresh26 : uint8 = c2da_mem[c2da_fresh25]
        c2da_mem[dest2_1] = c2da_fresh26
        dest_4 += 320
        dest2_1 += 320
        frac_4 += fracstep_4
    }
    return
}
[export, sideeffects]
def R_VideoErase(var ofs : uint; var count_5 : int) {
    if (background_buffer != 0) {
        c2da_lin_memcpy(int(I_VideoBuffer + int(ofs)), background_buffer + int(ofs), uint64(count_5))
    }
    return
}
var private background_buffer : int = 0

var ds_y : int = default<int>

var ds_x1 : int = default<int>

var ds_x2 : int = default<int>

var ds_colormap : int = default<int>

var ds_xfrac : int = default<int>

var ds_yfrac : int = default<int>

var ds_xstep : int = default<int>

var ds_ystep : int = default<int>

var ds_source : int = default<int>

var translationtables : int = default<int>

[export, sideeffects]
def R_DrawSpan() {
    var position : uint
    var step : uint
    var dest_5 : int
    var count_6 : int
    if (ds_x2 < ds_x1 || ds_x1 < 0 || ds_x2 >= 320 || uint(ds_y) > 200u) {
        I_Error(362334, [C2daVaArg(tag = 1, i64 = int64(ds_x1), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(ds_x2), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(ds_y), f64 = 0.0lf, raw = 0x0)])
    }
    position = uint(ds_xfrac << 10) & 0xffff0000u | uint(ds_yfrac >> 6 & 65535)
    step = uint(ds_xstep << 10) & 0xffff0000u | uint(ds_ystep >> 6 & 65535)
    dest_5 = ylookup[ds_y] + columnofs[ds_x1]
    count_6 = ds_x2 - ds_x1
    for (c2da_iter_5 in urange64(0ul, uint64(uint(count_6)) + 1ul)) {
        let c2da_fresh27 : int = dest_5
        dest_5++
        let c2da_fresh28 : int = ds_source + int(position >> 26u | position >> 4u & 0xfc0u)
        let c2da_fresh29 : int = ds_colormap + int(c2da_mem[c2da_fresh28])
        let c2da_fresh30 : uint8 = c2da_mem[c2da_fresh29]
        c2da_mem[c2da_fresh27] = c2da_fresh30
        position += step
    }
    return
}
[export, sideeffects]
def R_DrawSpanLow() {
    var position_0 : uint
    var step_0 : uint
    var dest_6 : int
    var count_7 : int
    var spot_0 : int
    if (ds_x2 < ds_x1 || ds_x1 < 0 || ds_x2 >= 320 || uint(ds_y) > 200u) {
        I_Error(362334, [C2daVaArg(tag = 1, i64 = int64(ds_x1), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(ds_x2), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(ds_y), f64 = 0.0lf, raw = 0x0)])
    }
    position_0 = uint(ds_xfrac << 10) & 0xffff0000u | uint(ds_yfrac >> 6 & 65535)
    step_0 = uint(ds_xstep << 10) & 0xffff0000u | uint(ds_ystep >> 6 & 65535)
    count_7 = ds_x2 - ds_x1
    ds_x1 <<= 1
    ds_x2 <<= 1
    dest_6 = ylookup[ds_y] + columnofs[ds_x1]
    for (c2da_iter_6 in urange64(0ul, uint64(uint(count_7)) + 1ul)) {
        spot_0 = int(position_0 >> 26u | position_0 >> 4u & 0xfc0u)
        let c2da_fresh31 : int = dest_6
        dest_6++
        let c2da_fresh32 : int = ds_colormap + int(c2da_mem[ds_source + spot_0])
        let c2da_fresh33 : uint8 = c2da_mem[c2da_fresh32]
        c2da_mem[c2da_fresh31] = c2da_fresh33
        let c2da_fresh34 : int = dest_6
        dest_6++
        let c2da_fresh35 : int = ds_colormap + int(c2da_mem[ds_source + spot_0])
        let c2da_fresh36 : uint8 = c2da_mem[c2da_fresh35]
        c2da_mem[c2da_fresh34] = c2da_fresh36
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
        ylookup[c2da_i] = I_VideoBuffer + (c2da_i + viewwindowy) * 320
    }
    return
}
[export, sideeffects]
def R_InitTranslationTables() {
    translationtables = Z_Malloc(256 * 3, 1, 0)
    for (i_0 in range(0, 256)) {
        if (i_0 >= 112 && i_0 <= 127) {
            let c2da_fresh37 : uint8 = uint8(96 + (i_0 & 15))
            c2da_mem[translationtables + i_0] = c2da_fresh37
            let c2da_fresh38 : uint8 = uint8(64 + (i_0 & 15))
            c2da_mem[translationtables + (i_0 + 256)] = c2da_fresh38
            let c2da_fresh39 : uint8 = uint8(32 + (i_0 & 15))
            c2da_mem[translationtables + (i_0 + 512)] = c2da_fresh39
        } else {
            let c2da_fresh40 : uint8 = uint8(i_0)
            c2da_mem[translationtables + (i_0 + 512)] = c2da_fresh40
            c2da_mem[translationtables + (i_0 + 256)] = c2da_fresh40
            c2da_mem[translationtables + i_0] = c2da_fresh40
        }
    }
    return
}
[export, sideeffects]
def R_FillBackScreen() {
    var src : int
    var dest_7 : int
    var x_2 : int
    var y : int
    var patch : int
    var name1 : int
    var name2 : int
    var name : int
    name1 = 362361
    name2 = 362370
    if (scaledviewwidth == 320) {
        if (background_buffer != 0) {
            Z_Free(background_buffer)
            background_buffer = 0
        }
        return
    }
    if (background_buffer == 0) {
        background_buffer = Z_Malloc(320 * (200 - 32), 1, 0)
    }
    if (uint(gamemode) == 2u) {
        name = name2
    } else {
        name = name1
    }
    src = W_CacheLumpName(name, 8)
    dest_7 = background_buffer
    y = 0
    while (y < 200 - 32) {
        x_2 = 0
        while (x_2 < 320 / 64) {
            c2da_lin_memcpy(dest_7, src + ((y & 63) << 6), 64ul)
            dest_7 += 64
            x_2++
        }
        if ((320 & 63) != 0) {
            c2da_lin_memcpy(dest_7, src + ((y & 63) << 6), uint64(320 & 63))
            dest_7 += 320 & 63
        }
        y++
    }
    V_UseBuffer(background_buffer)
    patch = W_CacheLumpName(362378, 8)
    x_2 = 0
    while (x_2 < scaledviewwidth) {
        V_DrawPatch(viewwindowx + x_2, viewwindowy - 8, patch)
        x_2 += 8
    }
    patch = W_CacheLumpName(362385, 8)
    x_2 = 0
    while (x_2 < scaledviewwidth) {
        V_DrawPatch(viewwindowx + x_2, viewwindowy + viewheight, patch)
        x_2 += 8
    }
    patch = W_CacheLumpName(362392, 8)
    y = 0
    while (y < viewheight) {
        V_DrawPatch(viewwindowx - 8, viewwindowy + y, patch)
        y += 8
    }
    patch = W_CacheLumpName(362399, 8)
    y = 0
    while (y < viewheight) {
        V_DrawPatch(viewwindowx + scaledviewwidth, viewwindowy + y, patch)
        y += 8
    }
    V_DrawPatch(viewwindowx - 8, viewwindowy - 8, W_CacheLumpName(362406, 8))
    V_DrawPatch(viewwindowx + scaledviewwidth, viewwindowy - 8, W_CacheLumpName(362414, 8))
    V_DrawPatch(viewwindowx - 8, viewwindowy + viewheight, W_CacheLumpName(362422, 8))
    V_DrawPatch(viewwindowx + scaledviewwidth, viewwindowy + viewheight, W_CacheLumpName(362430, 8))
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
var viewimage : int = default<int>

var translations : uint8[3][256]

var dccount : int = default<int>

var dscount : int = default<int>


// This unit's static data, at heap offset 362272.
let private c2da_lin_static_r_draw_seg = fixed_array<int>(362272, 165)
let private c2da_lin_static_r_draw = fixed_array<uint64>(0x6f43776172445f52ul, 0x6925203a6e6d756cul, 0x61206925206f7420ul, 0x445f520069252074ul, 0x437a7a7546776172ul, 0x25203a6e6d756c6ful, 0x206925206f742069ul, 0x5f52006925207461ul, 0x6e61705377617244ul, 0x206f74206925203aul, 0x6925207461206925ul, 0x5f37524f4f4c4600ul, 0x434f524e52470032ul, 0x745f72647262004bul, 0x625f7264726200ul, 0x62006c5f72647262ul, 0x726200725f726472ul, 0x7262006c745f7264ul, 0x72620072745f7264ul, 0x7262006c625f7264ul, 0x72625f7264ul)

[init]
def private c2da_lin_init_static_r_draw() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_r_draw_seg[s * 2]
        for (k in range(c2da_lin_static_r_draw_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_r_draw[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_r_draw() {
    if (length(c2da_fn_table0) < 152) {
        resize(c2da_fn_table0, 152)
    }
    c2da_fn_table0[144] = @@R_DrawColumn
    c2da_fn_table0[148] = @@R_DrawColumnLow
    c2da_fn_table0[145] = @@R_DrawFuzzColumn
    c2da_fn_table0[149] = @@R_DrawFuzzColumnLow
    c2da_fn_table0[146] = @@R_DrawTranslatedColumn
    c2da_fn_table0[150] = @@R_DrawTranslatedColumnLow
    c2da_fn_table0[147] = @@R_DrawSpan
    c2da_fn_table0[151] = @@R_DrawSpanLow
}

[init]
def private c2da_lin_relink_init_r_draw() {
    c2da_relink_r_draw()
}
