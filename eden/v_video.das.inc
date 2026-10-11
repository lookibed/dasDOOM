var tinttable : int = 0

[export, sideeffects]
def V_SetPatchClipCallback(var func : vpatchclipfunc_t) {
    patchclip_callback = int(func)  // nolint:PERF020
    return
}
var private patchclip_callback : vpatchclipfunc_t = 0

[export, sideeffects]
def V_Init() {
    return
}
[export, sideeffects]
def V_CopyRect(var srcx : int; var srcy : int; var source : int; var width : int; var height : int; var destx : int; var desty : int) {
    var src : int
    var dest : int
    if (srcx < 0 || srcx + width > 320 || srcy < 0 || srcy + height > 200 || destx < 0 || destx + width > 320 || desty < 0 || desty + height > 200) {
        I_Error(373952, [])
    }
    V_MarkRect(destx, desty, width, height)
    src = source + 320 * srcy + srcx
    dest = dest_screen + 320 * desty + destx
    while (height > 0) {
        c2da_lin_memcpy(dest, src, uint64(width))
        src += 320
        dest += 320
        height--
    }
    return
}
var private dest_screen : int = 0

[export, sideeffects]
def V_MarkRect(var x : int; var y : int; var width_0 : int; var height_0 : int) {
    if (dest_screen == I_VideoBuffer) {
        M_AddToBox(298880, x, y)
        M_AddToBox(298880, x + width_0 - 1, y + height_0 - 1)
    }
    return
}
[export, sideeffects]
def V_DrawPatch(var x_0 : int; var y_0 : int; var patch : int) {
    var count : int
    var col : int
    var column : int
    var desttop : int
    var dest_0 : int
    var source_0 : int
    var w : int
    y_0 -= int(int16(uint(c2da_mem[patch + 6]) | uint(c2da_mem[patch + 7]) << 0x8))
    x_0 -= int(int16(uint(c2da_mem[patch + 4]) | uint(c2da_mem[patch + 5]) << 0x8))
    if (patchclip_callback != default<vpatchclipfunc_t>) {
        if (invoke(c2da_fn_table13[patchclip_callback], patch, x_0, y_0) == 0) {
            return
        }
    }
    if (x_0 < 0 || x_0 + int(int16(uint(c2da_mem[patch]) | uint(c2da_mem[patch + 1]) << 0x8)) > 320 || y_0 < 0 || y_0 + int(int16(uint(c2da_mem[patch + 2]) | uint(c2da_mem[patch + 3]) << 0x8)) > 200) {
        I_Error(373967, [C2daVaArg(tag = 1, i64 = int64(x_0), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(y_0), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int16(uint(c2da_mem[patch]) | uint(c2da_mem[patch + 1]) << 0x8)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int16(uint(c2da_mem[patch + 2]) | uint(c2da_mem[patch + 3]) << 0x8)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int16(uint(c2da_mem[patch + 6]) | uint(c2da_mem[patch + 7]) << 0x8)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int16(uint(c2da_mem[patch + 4]) | uint(c2da_mem[patch + 5]) << 0x8)), f64 = 0.0lf, raw = 0x0)])
    }
    V_MarkRect(x_0, y_0, int(int16(uint(c2da_mem[patch]) | uint(c2da_mem[patch + 1]) << 0x8)), int(int16(uint(c2da_mem[patch + 2]) | uint(c2da_mem[patch + 3]) << 0x8)))
    col = 0
    desttop = dest_screen + y_0 * 320 + x_0
    w = int(int16(uint(c2da_mem[patch]) | uint(c2da_mem[patch + 1]) << 0x8))
    while (col < w) {
        column = patch + int(uint(c2da_mem[patch + 8 + col * 4]) | uint(c2da_mem[patch + 8 + col * 4 + 1]) << 0x8 | uint(c2da_mem[patch + 8 + col * 4 + 2]) << 0x10 | uint(c2da_mem[patch + 8 + col * 4 + 3]) << 0x18)
        while (int(c2da_mem[column]) != 255) {
            source_0 = column + 3
            dest_0 = desttop + int(c2da_mem[column]) * 320
            count = int(c2da_mem[column + 1])
            while (true) {
                let c2da_postinc : int = count
                count--
                if (c2da_postinc == 0) {
                    break
                }
                let c2da_fresh0 : int = source_0
                source_0++
                let c2da_fresh1 : uint8 = c2da_mem[c2da_fresh0]
                c2da_mem[dest_0] = c2da_fresh1
                dest_0 += 320
            }
            column = column + int(c2da_mem[column + 1]) + 4
        }
        x_0++
        col++
        desttop++
    }
    return
}
[export, sideeffects]
def V_DrawPatchFlipped(var x_1 : int; var y_1 : int; var patch_0 : int) {
    var count_0 : int
    var col_0 : int
    var column_0 : int
    var desttop_0 : int
    var dest_1 : int
    var source_1 : int
    var w_0 : int
    y_1 -= int(int16(uint(c2da_mem[patch_0 + 6]) | uint(c2da_mem[patch_0 + 7]) << 0x8))
    x_1 -= int(int16(uint(c2da_mem[patch_0 + 4]) | uint(c2da_mem[patch_0 + 5]) << 0x8))
    if (patchclip_callback != default<vpatchclipfunc_t>) {
        if (invoke(c2da_fn_table13[patchclip_callback], patch_0, x_1, y_1) == 0) {
            return
        }
    }
    if (x_1 < 0 || x_1 + int(int16(uint(c2da_mem[patch_0]) | uint(c2da_mem[patch_0 + 1]) << 0x8)) > 320 || y_1 < 0 || y_1 + int(int16(uint(c2da_mem[patch_0 + 2]) | uint(c2da_mem[patch_0 + 3]) << 0x8)) > 200) {
        I_Error(374051, [])
    }
    V_MarkRect(x_1, y_1, int(int16(uint(c2da_mem[patch_0]) | uint(c2da_mem[patch_0 + 1]) << 0x8)), int(int16(uint(c2da_mem[patch_0 + 2]) | uint(c2da_mem[patch_0 + 3]) << 0x8)))
    col_0 = 0
    desttop_0 = dest_screen + y_1 * 320 + x_1
    w_0 = int(int16(uint(c2da_mem[patch_0]) | uint(c2da_mem[patch_0 + 1]) << 0x8))
    while (col_0 < w_0) {
        column_0 = patch_0 + int(uint(c2da_mem[patch_0 + 8 + (w_0 - 1 - col_0) * 4]) | uint(c2da_mem[patch_0 + 8 + (w_0 - 1 - col_0) * 4 + 1]) << 0x8 | uint(c2da_mem[patch_0 + 8 + (w_0 - 1 - col_0) * 4 + 2]) << 0x10 | uint(c2da_mem[patch_0 + 8 + (w_0 - 1 - col_0) * 4 + 3]) << 0x18)
        while (int(c2da_mem[column_0]) != 255) {
            source_1 = column_0 + 3
            dest_1 = desttop_0 + int(c2da_mem[column_0]) * 320
            count_0 = int(c2da_mem[column_0 + 1])
            while (true) {
                let c2da_postinc_0 : int = count_0
                count_0--
                if (c2da_postinc_0 == 0) {
                    break
                }
                let c2da_fresh2 : int = source_1
                source_1++
                let c2da_fresh3 : uint8 = c2da_mem[c2da_fresh2]
                c2da_mem[dest_1] = c2da_fresh3
                dest_1 += 320
            }
            column_0 = column_0 + int(c2da_mem[column_0 + 1]) + 4
        }
        x_1++
        col_0++
        desttop_0++
    }
    return
}
[export, sideeffects]
def V_DrawTLPatch(var x_2 : int; var y_3 : int; var patch_1 : int) {
    var count_1 : int
    var col_1 : int
    var column_1 : int
    var desttop_1 : int
    var dest_2 : int
    var source_2 : int
    var w_1 : int
    y_3 -= int(int16(uint(c2da_mem[patch_1 + 6]) | uint(c2da_mem[patch_1 + 7]) << 0x8))
    x_2 -= int(int16(uint(c2da_mem[patch_1 + 4]) | uint(c2da_mem[patch_1 + 5]) << 0x8))
    if (x_2 < 0 || x_2 + int(int16(uint(c2da_mem[patch_1]) | uint(c2da_mem[patch_1 + 1]) << 0x8)) > 320 || y_3 < 0 || y_3 + int(int16(uint(c2da_mem[patch_1 + 2]) | uint(c2da_mem[patch_1 + 3]) << 0x8)) > 200) {
        I_Error(374074, [])
    }
    col_1 = 0
    desttop_1 = dest_screen + y_3 * 320 + x_2
    w_1 = int(int16(uint(c2da_mem[patch_1]) | uint(c2da_mem[patch_1 + 1]) << 0x8))
    while (col_1 < w_1) {
        column_1 = patch_1 + int(uint(c2da_mem[patch_1 + 8 + col_1 * 4]) | uint(c2da_mem[patch_1 + 8 + col_1 * 4 + 1]) << 0x8 | uint(c2da_mem[patch_1 + 8 + col_1 * 4 + 2]) << 0x10 | uint(c2da_mem[patch_1 + 8 + col_1 * 4 + 3]) << 0x18)
        while (int(c2da_mem[column_1]) != 255) {
            source_2 = column_1 + 3
            dest_2 = desttop_1 + int(c2da_mem[column_1]) * 320
            count_1 = int(c2da_mem[column_1 + 1])
            while (true) {
                let c2da_postinc_1 : int = count_1
                count_1--
                if (c2da_postinc_1 == 0) {
                    break
                }
                let c2da_fresh4 : int = source_2
                source_2++
                let c2da_fresh5 : int = tinttable + ((int(c2da_mem[dest_2]) << 8) + int(c2da_mem[c2da_fresh4]))
                let c2da_fresh6 : uint8 = c2da_mem[c2da_fresh5]
                c2da_mem[dest_2] = c2da_fresh6
                dest_2 += 320
            }
            column_1 = column_1 + int(c2da_mem[column_1 + 1]) + 4
        }
        x_2++
        col_1++
        desttop_1++
    }
    return
}
[export, sideeffects]
def V_DrawAltTLPatch(var x_3 : int; var y_4 : int; var patch_2 : int) {
    var count_2 : int
    var col_2 : int
    var column_2 : int
    var desttop_2 : int
    var dest_3 : int
    var source_3 : int
    var w_2 : int
    y_4 -= int(int16(uint(c2da_mem[patch_2 + 6]) | uint(c2da_mem[patch_2 + 7]) << 0x8))
    x_3 -= int(int16(uint(c2da_mem[patch_2 + 4]) | uint(c2da_mem[patch_2 + 5]) << 0x8))
    if (x_3 < 0 || x_3 + int(int16(uint(c2da_mem[patch_2]) | uint(c2da_mem[patch_2 + 1]) << 0x8)) > 320 || y_4 < 0 || y_4 + int(int16(uint(c2da_mem[patch_2 + 2]) | uint(c2da_mem[patch_2 + 3]) << 0x8)) > 200) {
        I_Error(374092, [])
    }
    col_2 = 0
    desttop_2 = dest_screen + y_4 * 320 + x_3
    w_2 = int(int16(uint(c2da_mem[patch_2]) | uint(c2da_mem[patch_2 + 1]) << 0x8))
    while (col_2 < w_2) {
        column_2 = patch_2 + int(uint(c2da_mem[patch_2 + 8 + col_2 * 4]) | uint(c2da_mem[patch_2 + 8 + col_2 * 4 + 1]) << 0x8 | uint(c2da_mem[patch_2 + 8 + col_2 * 4 + 2]) << 0x10 | uint(c2da_mem[patch_2 + 8 + col_2 * 4 + 3]) << 0x18)
        while (int(c2da_mem[column_2]) != 255) {
            source_3 = column_2 + 3
            dest_3 = desttop_2 + int(c2da_mem[column_2]) * 320
            count_2 = int(c2da_mem[column_2 + 1])
            while (true) {
                let c2da_postinc_2 : int = count_2
                count_2--
                if (c2da_postinc_2 == 0) {
                    break
                }
                let c2da_fresh7 : int = source_3
                source_3++
                let c2da_fresh8 : int = tinttable + ((int(c2da_mem[dest_3]) << 8) + int(c2da_mem[c2da_fresh7]))
                let c2da_fresh9 : uint8 = c2da_mem[c2da_fresh8]
                c2da_mem[dest_3] = c2da_fresh9
                dest_3 += 320
            }
            column_2 = column_2 + int(c2da_mem[column_2 + 1]) + 4
        }
        x_3++
        col_2++
        desttop_2++
    }
    return
}
[export, sideeffects]
def V_DrawShadowedPatch(var x_4 : int; var y_5 : int; var patch_3 : int) {
    var count_3 : int
    var col_3 : int
    var column_3 : int
    var desttop_3 : int
    var dest_4 : int
    var source_4 : int
    var desttop2 : int
    var dest2 : int
    var w_3 : int
    y_5 -= int(int16(uint(c2da_mem[patch_3 + 6]) | uint(c2da_mem[patch_3 + 7]) << 0x8))
    x_4 -= int(int16(uint(c2da_mem[patch_3 + 4]) | uint(c2da_mem[patch_3 + 5]) << 0x8))
    if (x_4 < 0 || x_4 + int(int16(uint(c2da_mem[patch_3]) | uint(c2da_mem[patch_3 + 1]) << 0x8)) > 320 || y_5 < 0 || y_5 + int(int16(uint(c2da_mem[patch_3 + 2]) | uint(c2da_mem[patch_3 + 3]) << 0x8)) > 200) {
        I_Error(374113, [])
    }
    col_3 = 0
    desttop_3 = dest_screen + y_5 * 320 + x_4
    desttop2 = dest_screen + (y_5 + 2) * 320 + x_4 + 2
    w_3 = int(int16(uint(c2da_mem[patch_3]) | uint(c2da_mem[patch_3 + 1]) << 0x8))
    while (col_3 < w_3) {
        column_3 = patch_3 + int(uint(c2da_mem[patch_3 + 8 + col_3 * 4]) | uint(c2da_mem[patch_3 + 8 + col_3 * 4 + 1]) << 0x8 | uint(c2da_mem[patch_3 + 8 + col_3 * 4 + 2]) << 0x10 | uint(c2da_mem[patch_3 + 8 + col_3 * 4 + 3]) << 0x18)
        while (int(c2da_mem[column_3]) != 255) {
            source_4 = column_3 + 3
            dest_4 = desttop_3 + int(c2da_mem[column_3]) * 320
            dest2 = desttop2 + int(c2da_mem[column_3]) * 320
            count_3 = int(c2da_mem[column_3 + 1])
            while (true) {
                let c2da_postinc_3 : int = count_3
                count_3--
                if (c2da_postinc_3 == 0) {
                    break
                }
                let c2da_fresh10 : int = tinttable + (int(c2da_mem[dest2]) << 8)
                let c2da_fresh11 : uint8 = c2da_mem[c2da_fresh10]
                c2da_mem[dest2] = c2da_fresh11
                dest2 += 320
                let c2da_fresh12 : int = source_4
                source_4++
                let c2da_fresh13 : uint8 = c2da_mem[c2da_fresh12]
                c2da_mem[dest_4] = c2da_fresh13
                dest_4 += 320
            }
            column_3 = column_3 + int(c2da_mem[column_3 + 1]) + 4
        }
        x_4++
        col_3++
        desttop_3++
        desttop2++
    }
    return
}
[export, sideeffects]
def V_DrawXlaPatch(var x_5 : int; var y_6 : int; var patch_4 : int) {
    var count_4 : int
    var col_4 : int
    var column_4 : int
    var desttop_4 : int
    var dest_5 : int
    var source_5 : int
    var w_4 : int
    y_6 -= int(int16(uint(c2da_mem[patch_4 + 6]) | uint(c2da_mem[patch_4 + 7]) << 0x8))
    x_5 -= int(int16(uint(c2da_mem[patch_4 + 4]) | uint(c2da_mem[patch_4 + 5]) << 0x8))
    if (patchclip_callback != default<vpatchclipfunc_t>) {
        if (invoke(c2da_fn_table13[patchclip_callback], patch_4, x_5, y_6) == 0) {
            return
        }
    }
    col_4 = 0
    desttop_4 = dest_screen + y_6 * 320 + x_5
    w_4 = int(int16(uint(c2da_mem[patch_4]) | uint(c2da_mem[patch_4 + 1]) << 0x8))
    while (col_4 < w_4) {
        column_4 = patch_4 + int(uint(c2da_mem[patch_4 + 8 + col_4 * 4]) | uint(c2da_mem[patch_4 + 8 + col_4 * 4 + 1]) << 0x8 | uint(c2da_mem[patch_4 + 8 + col_4 * 4 + 2]) << 0x10 | uint(c2da_mem[patch_4 + 8 + col_4 * 4 + 3]) << 0x18)
        while (int(c2da_mem[column_4]) != 255) {
            source_5 = column_4 + 3
            dest_5 = desttop_4 + int(c2da_mem[column_4]) * 320
            count_4 = int(c2da_mem[column_4 + 1])
            while (true) {
                let c2da_postinc_4 : int = count_4
                count_4--
                if (c2da_postinc_4 == 0) {
                    break
                }
                let c2da_fresh14 : int = xlatab + (int(c2da_mem[dest_5]) + (int(c2da_mem[source_5]) << 8))
                let c2da_fresh15 : uint8 = c2da_mem[c2da_fresh14]
                c2da_mem[dest_5] = c2da_fresh15
                source_5++
                dest_5 += 320
            }
            column_4 = column_4 + int(c2da_mem[column_4 + 1]) + 4
        }
        x_5++
        col_4++
        desttop_4++
    }
    return
}
var xlatab : int = 0

[export, sideeffects]
def V_DrawPatchDirect(var x_6 : int; var y_7 : int; var patch_5 : int) {
    V_DrawPatch(x_6, y_7, patch_5)
    return
}
[export, sideeffects]
def V_DrawBlock(var x_7 : int; var y_8 : int; var width_1 : int; var height_1 : int; var src_0 : int) {
    var dest_6 : int
    if (x_7 < 0 || x_7 + width_1 > 320 || y_8 < 0 || y_8 + height_1 > 200) {
        I_Error(374137, [])
    }
    V_MarkRect(x_7, y_8, width_1, height_1)
    dest_6 = dest_screen + y_8 * 320 + x_7
    while (true) {
        let c2da_postinc_5 : int = height_1
        height_1--
        if (c2da_postinc_5 == 0) {
            break
        }
        c2da_lin_memcpy(dest_6, src_0, uint64(width_1))
        src_0 += width_1
        dest_6 += 320
    }
    return
}
[export, sideeffects]
def V_DrawFilledBox(var x_8 : int; var y_9 : int; var w_5 : int; var h : int; var c : int) {
    var buf : int
    var buf1 : int
    buf = I_VideoBuffer + 320 * y_9 + x_8
    for (y1 in range(0, h)) {
        buf1 = buf
        for (x1 in range(0, w_5)) {
            let c2da_fresh16 : int = buf1
            buf1++
            let c2da_fresh17 : uint8 = uint8(c)
            c2da_mem[c2da_fresh16] = c2da_fresh17
        }
        buf += 320
    }
    return
}
[export, sideeffects]
def V_DrawHorizLine(var x_9 : int; var y_10 : int; var w_6 : int; var c_0 : int) {
    var buf_0 : int = I_VideoBuffer + 320 * y_10 + x_9
    for (x1_0 in range(0, w_6)) {
        let c2da_fresh18 : int = buf_0
        buf_0++
        let c2da_fresh19 : uint8 = uint8(c_0)
        c2da_mem[c2da_fresh18] = c2da_fresh19
    }
    return
}
[export, sideeffects]
def V_DrawVertLine(var x_10 : int; var y_11 : int; var h_0 : int; var c_1 : int) {
    var buf_1 : int = I_VideoBuffer + 320 * y_11 + x_10
    for (y1_0 in range(0, h_0)) {
        let c2da_fresh20 : uint8 = uint8(c_1)
        c2da_mem[buf_1] = c2da_fresh20
        buf_1 += 320
    }
    return
}
[export, sideeffects]
def V_DrawBox(var x_11 : int; var y_12 : int; var w_7 : int; var h_1 : int; var c_2 : int) {
    V_DrawHorizLine(x_11, y_12, w_7, c_2)
    V_DrawHorizLine(x_11, y_12 + h_1 - 1, w_7, c_2)
    V_DrawVertLine(x_11, y_12, h_1, c_2)
    V_DrawVertLine(x_11 + w_7 - 1, y_12, h_1, c_2)
    return
}
[export, sideeffects]
def V_DrawRawScreen(var raw : int) {
    c2da_lin_memcpy(dest_screen, raw, uint64(320 * 200))
    return
}
[export, sideeffects]
def V_UseBuffer(var buffer : int) {
    dest_screen = int(buffer)  // nolint:PERF020
    return
}
[export, sideeffects]
def V_RestoreBuffer() {
    dest_screen = I_VideoBuffer
    return
}
[export, sideeffects]
def V_ScreenShot(var format : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    V_ScreenShot_c2da_frame(format, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def WritePCXfile(var filename : int; var data : int; var width_2 : int; var height_2 : int; var palette : int) {
    var i_0 : int
    var pcx : int
    var pack : int
    pcx = Z_Malloc(width_2 * height_2 * 2 + 1000, 1, 0)
    let c2da_fresh21 : int8 = int8(10)
    c2da_mem[pcx] = uint8(c2da_fresh21)
    let c2da_fresh22 : int8 = int8(5)
    c2da_mem[pcx + 1] = uint8(c2da_fresh22)
    let c2da_fresh23 : int8 = int8(1)
    c2da_mem[pcx + 2] = uint8(c2da_fresh23)
    let c2da_fresh24 : int8 = int8(8)
    c2da_mem[pcx + 3] = uint8(c2da_fresh24)
    let c2da_fresh25 : uint16 = uint16(0)
    let c2da_fresh26 : uint = uint(c2da_fresh25)
    c2da_mem[pcx + 4] = uint8(c2da_fresh26)
    c2da_mem[pcx + 5] = uint8(c2da_fresh26 >> 0x8)
    let c2da_fresh27 : uint16 = uint16(0)
    let c2da_fresh28 : uint = uint(c2da_fresh27)
    c2da_mem[pcx + 6] = uint8(c2da_fresh28)
    c2da_mem[pcx + 7] = uint8(c2da_fresh28 >> 0x8)
    let c2da_fresh29 : uint16 = uint16(int16(width_2 - 1))
    let c2da_fresh30 : uint = uint(c2da_fresh29)
    c2da_mem[pcx + 8] = uint8(c2da_fresh30)
    c2da_mem[pcx + 9] = uint8(c2da_fresh30 >> 0x8)
    let c2da_fresh31 : uint16 = uint16(int16(height_2 - 1))
    let c2da_fresh32 : uint = uint(c2da_fresh31)
    c2da_mem[pcx + 10] = uint8(c2da_fresh32)
    c2da_mem[pcx + 11] = uint8(c2da_fresh32 >> 0x8)
    let c2da_fresh33 : uint16 = uint16(int16(width_2))
    let c2da_fresh34 : uint = uint(c2da_fresh33)
    c2da_mem[pcx + 12] = uint8(c2da_fresh34)
    c2da_mem[pcx + 13] = uint8(c2da_fresh34 >> 0x8)
    let c2da_fresh35 : uint16 = uint16(int16(height_2))
    let c2da_fresh36 : uint = uint(c2da_fresh35)
    c2da_mem[pcx + 14] = uint8(c2da_fresh36)
    c2da_mem[pcx + 15] = uint8(c2da_fresh36 >> 0x8)
    c2da_lin_memset(pcx + 16, 0, 48ul)
    let c2da_fresh37 : int8 = int8(1)
    c2da_mem[pcx + 65] = uint8(c2da_fresh37)
    let c2da_fresh38 : uint16 = uint16(int16(width_2))
    let c2da_fresh39 : uint = uint(c2da_fresh38)
    c2da_mem[pcx + 66] = uint8(c2da_fresh39)
    c2da_mem[pcx + 67] = uint8(c2da_fresh39 >> 0x8)
    let c2da_fresh40 : uint16 = uint16(2)
    let c2da_fresh41 : uint = uint(c2da_fresh40)
    c2da_mem[pcx + 68] = uint8(c2da_fresh41)
    c2da_mem[pcx + 69] = uint8(c2da_fresh41 >> 0x8)
    c2da_lin_memset(pcx + 70, 0, 58ul)
    pack = pcx + 128
    i_0 = 0
    while (i_0 < width_2 * height_2) {
        if ((int(c2da_mem[data]) & 192) != 192) {
            let c2da_fresh42 : int = pack
            pack++
            let c2da_fresh43 : int = data
            data++
            let c2da_fresh44 : uint8 = c2da_mem[c2da_fresh43]
            c2da_mem[c2da_fresh42] = c2da_fresh44
        } else {
            let c2da_fresh45 : int = pack
            pack++
            let c2da_fresh46 : uint8 = 0xc1u8
            c2da_mem[c2da_fresh45] = c2da_fresh46
            let c2da_fresh47 : int = pack
            pack++
            let c2da_fresh48 : int = data
            data++
            let c2da_fresh49 : uint8 = c2da_mem[c2da_fresh48]
            c2da_mem[c2da_fresh47] = c2da_fresh49
        }
        i_0++
    }
    let c2da_fresh50 : int = pack
    pack++
    let c2da_fresh51 : uint8 = 0xcu8
    c2da_mem[c2da_fresh50] = c2da_fresh51
    i_0 = 0
    for (c2da_i_0 in range(i_0, 768)) {
        let c2da_fresh52 : int = pack
        pack++
        let c2da_fresh53 : int = palette
        palette++
        let c2da_fresh54 : uint8 = c2da_mem[c2da_fresh53]
        c2da_mem[c2da_fresh52] = c2da_fresh54
    }
    M_WriteFile(filename, pcx, pack - pcx)
    Z_Free(pcx)
    return
}
[export, sideeffects]
def V_LoadTintTable() {
    tinttable = W_CacheLumpName(374201, 1)
    return
}
[export, sideeffects]
def V_LoadXlaTable() {
    xlatab = W_CacheLumpName(374209, 1)
    return
}
[export, sideeffects]
def V_DrawMouseSpeedBox(var speed : int) {
    var bgcolor : int
    var bordercolor : int
    var red : int
    var black : int
    var white : int
    var yellow : int
    var box_x : int
    var box_y : int
    var original_speed : int
    var redline_x : int
    var linelen : int
    bgcolor = I_GetPaletteIndex(119, 119, 119)
    bordercolor = I_GetPaletteIndex(85, 85, 85)
    red = I_GetPaletteIndex(255, 0, 0)
    black = I_GetPaletteIndex(0, 0, 0)
    yellow = I_GetPaletteIndex(255, 255, 0)
    white = I_GetPaletteIndex(255, 255, 255)
    if (usemouse == 0 || c2da_std_fabs(double(mouse_acceleration - 1.0)) < 0.01lf) {
        return
    }
    box_x = 320 - 120 - 10
    box_y = 15
    V_DrawFilledBox(box_x, box_y, 120, 9, bgcolor)
    V_DrawBox(box_x, box_y, 120, 9, bordercolor)
    redline_x = 120 / 3
    if (speed < mouse_threshold) {
        original_speed = speed
    } else {
        original_speed = speed - mouse_threshold
        original_speed = int(float(original_speed) / mouse_acceleration)
        original_speed = original_speed + mouse_threshold
    }
    linelen = original_speed * redline_x / mouse_threshold
    if (linelen > 120 - 1) {
        linelen = 120 - 1
    }
    V_DrawHorizLine(box_x + 1, box_y + 4, 120 - 2, black)
    if (linelen < redline_x) {
        V_DrawHorizLine(box_x + 1, box_y + 9 / 2, linelen, white)
    } else {
        V_DrawHorizLine(box_x + 1, box_y + 9 / 2, redline_x, white)
        V_DrawHorizLine(box_x + redline_x, box_y + 9 / 2, linelen - redline_x, yellow)
    }
    V_DrawVertLine(box_x + redline_x, box_y + 1, 9 - 2, red)
    return
}
[sideeffects]
def private V_ScreenShot_c2da_frame(var format : int; c2da_fp : int) {
    var i : int
    var ext : int = 374153
    i = 0
    while (i <= 99) {
        M_snprintf(c2da_fp, 16ul, format, [C2daVaArg(tag = 1, i64 = int64(i), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(ext))])
        if (M_FileExists(c2da_fp) == 0) {
            break
        }
        i++
    }
    if (i == 100) {
        I_Error(374157, [])
    }
    WritePCXfile(c2da_fp, I_VideoBuffer, 320, 200, W_CacheLumpName(374193, 8))
    return
}

// This unit's static data, at heap offset 373952.
let private c2da_lin_static_v_video_seg = fixed_array<int>(373952, 263)
let private c2da_lin_static_v_video = fixed_array<uint64>(0x6f435f5620646142ul, 0x4200746365527970ul, 0x6172445f56206461ul, 0x7820686374615077ul, 0x69253d792069253dul, 0x772e686374617020ul, 0x2069253d68746469ul, 0x65682e6863746170ul, 0x2069253d74686769ul, 0x657366666f706f74ul, 0x66656c2069253d74ul, 0x3d74657366666f74ul, 0x5620646142006925ul, 0x746150776172445ful, 0x657070696c466863ul, 0x5f56206461420064ul, 0x61504c5477617244ul, 0x2064614200686374ul, 0x6c41776172445f56ul, 0x68637461504c5474ul, 0x445f562064614200ul, 0x6f64616853776172ul, 0x6863746150646577ul, 0x445f562064614200ul, 0x6b636f6c42776172ul, 0x535f560078637000ul, 0x6f68536e65657263ul, 0x646c756f43203a74ul, 0x616572632074276eul, 0x5843502061206574ul, 0x4c415059414c5000ul, 0x424154544e495400ul, 0x424154414c5800ul)

[init]
def private c2da_lin_init_static_v_video() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_v_video_seg[s * 2]
        for (k in range(c2da_lin_static_v_video_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_v_video[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
