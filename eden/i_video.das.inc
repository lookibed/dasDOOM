[export, sideeffects]
def I_InitGraphics() {
    var i : int
    var gfxmodeparm : int
    var mode : int
    c2da_lin_memset(378240, 0, 52ul)
    let c2da_fresh0 : uint = 320u
    let c2da_fresh1 : uint = c2da_fresh0
    c2da_mem[378240] = uint8(c2da_fresh1)
    c2da_mem[378241] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[378242] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[378243] = uint8(c2da_fresh1 >> 0x18)
    let c2da_fresh2 : uint = 200u
    let c2da_fresh3 : uint = c2da_fresh2
    c2da_mem[378244] = uint8(c2da_fresh3)
    c2da_mem[378245] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[378246] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[378247] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : uint = uint(c2da_mem[378240]) | uint(c2da_mem[378241]) << 0x8 | uint(c2da_mem[378242]) << 0x10 | uint(c2da_mem[378243]) << 0x18
    let c2da_fresh5 : uint = c2da_fresh4
    c2da_mem[378248] = uint8(c2da_fresh5)
    c2da_mem[378249] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[378250] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[378251] = uint8(c2da_fresh5 >> 0x18)
    let c2da_fresh6 : uint = uint(c2da_mem[378244]) | uint(c2da_mem[378245]) << 0x8 | uint(c2da_mem[378246]) << 0x10 | uint(c2da_mem[378247]) << 0x18
    let c2da_fresh7 : uint = c2da_fresh6
    c2da_mem[378252] = uint8(c2da_fresh7)
    c2da_mem[378253] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[378254] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[378255] = uint8(c2da_fresh7 >> 0x18)
    let c2da_fresh8 : uint = 8u
    let c2da_fresh9 : uint = c2da_fresh8
    c2da_mem[378256] = uint8(c2da_fresh9)
    c2da_mem[378257] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[378258] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[378259] = uint8(c2da_fresh9 >> 0x18)
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 378292, [C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[378240]) | uint(c2da_mem[378241]) << 0x8 | uint(c2da_mem[378242]) << 0x10 | uint(c2da_mem[378243]) << 0x18), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[378244]) | uint(c2da_mem[378245]) << 0x8 | uint(c2da_mem[378246]) << 0x10 | uint(c2da_mem[378247]) << 0x18), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[378248]) | uint(c2da_mem[378249]) << 0x8 | uint(c2da_mem[378250]) << 0x10 | uint(c2da_mem[378251]) << 0x18), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[378252]) | uint(c2da_mem[378253]) << 0x8 | uint(c2da_mem[378254]) << 0x10 | uint(c2da_mem[378255]) << 0x18), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[378256]) | uint(c2da_mem[378257]) << 0x8 | uint(c2da_mem[378258]) << 0x10 | uint(c2da_mem[378259]) << 0x18), f64 = 0.0lf, raw = 0x0)])
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 378382, [C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[378264]) | uint(c2da_mem[378265]) << 0x8 | uint(c2da_mem[378266]) << 0x10 | uint(c2da_mem[378267]) << 0x18), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[378272]) | uint(c2da_mem[378273]) << 0x8 | uint(c2da_mem[378274]) << 0x10 | uint(c2da_mem[378275]) << 0x18), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[378280]) | uint(c2da_mem[378281]) << 0x8 | uint(c2da_mem[378282]) << 0x10 | uint(c2da_mem[378283]) << 0x18), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[378288]) | uint(c2da_mem[378289]) << 0x8 | uint(c2da_mem[378290]) << 0x10 | uint(c2da_mem[378291]) << 0x18), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[378260]) | uint(c2da_mem[378261]) << 0x8 | uint(c2da_mem[378262]) << 0x10 | uint(c2da_mem[378263]) << 0x18), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[378268]) | uint(c2da_mem[378269]) << 0x8 | uint(c2da_mem[378270]) << 0x10 | uint(c2da_mem[378271]) << 0x18), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[378276]) | uint(c2da_mem[378277]) << 0x8 | uint(c2da_mem[378278]) << 0x10 | uint(c2da_mem[378279]) << 0x18), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[378284]) | uint(c2da_mem[378285]) << 0x8 | uint(c2da_mem[378286]) << 0x10 | uint(c2da_mem[378287]) << 0x18), f64 = 0.0lf, raw = 0x0)])
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 378485, [C2daVaArg(tag = 1, i64 = 320l, f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = 200l, f64 = 0.0lf, raw = 0x0)])
    i = M_CheckParmWithArgs(378535, 1)
    if (i > 0) {
        i = c2da_lin_atoi(int(uint(c2da_mem[myargv + (i + 1) * 8]) | uint(c2da_mem[myargv + (i + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (i + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (i + 1) * 8 + 3]) << 0x18))
        fb_scaling = i
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 378544, [C2daVaArg(tag = 1, i64 = int64(fb_scaling), f64 = 0.0lf, raw = 0x0)])
    } else {
        fb_scaling = int((uint(c2da_mem[378240]) | uint(c2da_mem[378241]) << 0x8 | uint(c2da_mem[378242]) << 0x10 | uint(c2da_mem[378243]) << 0x18) / 320u)
        if ((uint(c2da_mem[378244]) | uint(c2da_mem[378245]) << 0x8 | uint(c2da_mem[378246]) << 0x10 | uint(c2da_mem[378247]) << 0x18) / 200u < uint(fb_scaling)) {
            fb_scaling = int((uint(c2da_mem[378244]) | uint(c2da_mem[378245]) << 0x8 | uint(c2da_mem[378246]) << 0x10 | uint(c2da_mem[378247]) << 0x18) / 200u)
        }
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 378580, [C2daVaArg(tag = 1, i64 = int64(fb_scaling), f64 = 0.0lf, raw = 0x0)])
    }
    I_VideoBuffer = Z_Malloc(320 * 200, 1, 0)
    screenvisible = 1u
    I_InitInput()
    return
}
var screenvisible : uint = default<uint>

var I_VideoBuffer : int = 0

var fb_scaling : int = 1

[export, sideeffects]
def I_GraphicsCheckCommandLine() {
    return
}
[export, sideeffects]
def I_ShutdownGraphics() {
    Z_Free(I_VideoBuffer)
    return
}
[export, sideeffects]
def I_SetPalette(var palette : int) {
    for (i_0 in range(0, 256)) {
        let c2da_fresh10 : uint = 0u
        let c2da_fresh11 : uint = (uint(c2da_mem[298928 + i_0 * 4]) | uint(c2da_mem[298928 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[298928 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[298928 + i_0 * 4 + 3]) << 0x18) & 0xffffffu | c2da_fresh10 << 24
        c2da_mem[298928 + i_0 * 4] = uint8(c2da_fresh11)
        c2da_mem[298928 + i_0 * 4 + 1] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[298928 + i_0 * 4 + 2] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[298928 + i_0 * 4 + 3] = uint8(c2da_fresh11 >> 0x18)
        let c2da_fresh12 : int = palette
        palette++
        let c2da_fresh13 : uint = uint(gammatable[usegamma][int(c2da_mem[c2da_fresh12])])
        let c2da_fresh14 : uint = (uint(c2da_mem[298928 + i_0 * 4]) | uint(c2da_mem[298928 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[298928 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[298928 + i_0 * 4 + 3]) << 0x18) & 0xff00ffffu | (c2da_fresh13 & 0xffu) << 16
        c2da_mem[298928 + i_0 * 4] = uint8(c2da_fresh14)
        c2da_mem[298928 + i_0 * 4 + 1] = uint8(c2da_fresh14 >> 0x8)
        c2da_mem[298928 + i_0 * 4 + 2] = uint8(c2da_fresh14 >> 0x10)
        c2da_mem[298928 + i_0 * 4 + 3] = uint8(c2da_fresh14 >> 0x18)
        let c2da_fresh15 : int = palette
        palette++
        let c2da_fresh16 : uint = uint(gammatable[usegamma][int(c2da_mem[c2da_fresh15])])
        let c2da_fresh17 : uint = (uint(c2da_mem[298928 + i_0 * 4]) | uint(c2da_mem[298928 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[298928 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[298928 + i_0 * 4 + 3]) << 0x18) & 0xffff00ffu | (c2da_fresh16 & 0xffu) << 8
        c2da_mem[298928 + i_0 * 4] = uint8(c2da_fresh17)
        c2da_mem[298928 + i_0 * 4 + 1] = uint8(c2da_fresh17 >> 0x8)
        c2da_mem[298928 + i_0 * 4 + 2] = uint8(c2da_fresh17 >> 0x10)
        c2da_mem[298928 + i_0 * 4 + 3] = uint8(c2da_fresh17 >> 0x18)
        let c2da_fresh18 : int = palette
        palette++
        let c2da_fresh19 : uint = uint(gammatable[usegamma][int(c2da_mem[c2da_fresh18])])
        let c2da_fresh20 : uint = (uint(c2da_mem[298928 + i_0 * 4]) | uint(c2da_mem[298928 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[298928 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[298928 + i_0 * 4 + 3]) << 0x18) & 0xffffff00u | c2da_fresh19 & 0xffu
        c2da_mem[298928 + i_0 * 4] = uint8(c2da_fresh20)
        c2da_mem[298928 + i_0 * 4 + 1] = uint8(c2da_fresh20 >> 0x8)
        c2da_mem[298928 + i_0 * 4 + 2] = uint8(c2da_fresh20 >> 0x10)
        c2da_mem[298928 + i_0 * 4 + 3] = uint8(c2da_fresh20 >> 0x18)
    }
    palette_changed = 1u
    return
}
var palette_changed : uint = default<uint>

var usegamma : int = 0

[export, sideeffects]
def I_GetPaletteIndex(var r : int; var g : int; var b : int) : int {
    var best : int
    var best_diff : int
    var diff : int
    var color : col_t
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 378621, [])
    best = 0
    best_diff = 2147483647
    for (i_1 in range(0, 256)) {
        color.r = uint8((63488 & int(rgb565_palette[i_1])) >> 11)
        color.g = uint8((2016 & int(rgb565_palette[i_1])) >> 5)
        color.b = uint8(31 & int(rgb565_palette[i_1]))
        diff = (r - int(color.r)) * (r - int(color.r)) + (g - int(color.g)) * (g - int(color.g)) + (b - int(color.b)) * (b - int(color.b))
        if (diff < best_diff) {
            best = i_1
            best_diff = diff
        }
        if (diff == 0) {
            break
        }
    }
    return best
}
var private rgb565_palette : uint16[256]

[export, sideeffects]
def I_UpdateNoBlit() {
    return
}
[export, sideeffects]
def I_FinishUpdate() {
    var y : int
    var x_offset : int
    var y_offset : int
    var x_offset_end : int
    var line_in : int
    var line_out : int
    var i_2 : int
    var k : int
    y_offset = int(((uint(c2da_mem[378244]) | uint(c2da_mem[378245]) << 0x8 | uint(c2da_mem[378246]) << 0x10 | uint(c2da_mem[378247]) << 0x18) - uint(200 * fb_scaling)) * (uint(c2da_mem[378256]) | uint(c2da_mem[378257]) << 0x8 | uint(c2da_mem[378258]) << 0x10 | uint(c2da_mem[378259]) << 0x18) / 8u / 2u)
    x_offset = int(((uint(c2da_mem[378240]) | uint(c2da_mem[378241]) << 0x8 | uint(c2da_mem[378242]) << 0x10 | uint(c2da_mem[378243]) << 0x18) - uint(320 * fb_scaling)) * (uint(c2da_mem[378256]) | uint(c2da_mem[378257]) << 0x8 | uint(c2da_mem[378258]) << 0x10 | uint(c2da_mem[378259]) << 0x18) / 8u / 2u)
    x_offset_end = int(((uint(c2da_mem[378240]) | uint(c2da_mem[378241]) << 0x8 | uint(c2da_mem[378242]) << 0x10 | uint(c2da_mem[378243]) << 0x18) - uint(320 * fb_scaling)) * (uint(c2da_mem[378256]) | uint(c2da_mem[378257]) << 0x8 | uint(c2da_mem[378258]) << 0x10 | uint(c2da_mem[378259]) << 0x18) / 8u - uint(x_offset))
    line_in = I_VideoBuffer
    line_out = DG_ScreenBuffer
    y = 200
    while (true) {
        let c2da_postinc : int = y
        y--
        if (c2da_postinc == 0) {
            break
        }
        i_2 = 0
        while (i_2 < fb_scaling) {
            line_out += x_offset
            if (fb_scaling == 1) {
                c2da_lin_memcpy(line_out, line_in, 320ul)
            } else {
                for (j in range(0, 320)) {
                    k = 0
                    while (k < fb_scaling) {
                        let c2da_fresh21 : uint8 = c2da_mem[line_in + j]
                        c2da_mem[line_out + (j * fb_scaling + k)] = c2da_fresh21
                        k++
                    }
                }
            }
            line_out += int(uint(320 * fb_scaling) * ((uint(c2da_mem[378256]) | uint(c2da_mem[378257]) << 0x8 | uint(c2da_mem[378258]) << 0x10 | uint(c2da_mem[378259]) << 0x18) / 8u) + uint(x_offset_end))
            i_2++
        }
        line_in += 320
    }
    DG_DrawFrame()
    return
}
[export, sideeffects]
def I_ReadScreen(var scr : int) {
    c2da_lin_memcpy(scr, I_VideoBuffer, uint64(320 * 200))
    return
}
[export, sideeffects]
def I_BeginRead() {
    return
}
[export, sideeffects]
def I_SetWindowTitle(var title_0 : int) {
    DG_SetWindowTitle(title_0)
    return
}
[export, sideeffects]
def I_CheckIsScreensaver() {
    return
}
[export, sideeffects]
def I_SetGrabMouseCallback(var func : grabmouse_callback_t) {
    return
}
[export, sideeffects]
def I_DisplayFPSDots(var dots_on : uint) {
    return
}
[export, sideeffects]
def I_BindVideoVariables() {
    return
}
[export, sideeffects]
def I_StartFrame() {
    return
}
[export, sideeffects]
def I_StartTic() {
    I_GetEvent()
    return
}
[export, sideeffects]
def I_EnableLoadingDisk() {
    return
}
[export, sideeffects]
def I_EndRead() {
    return
}
var mouse_acceleration : float = 2.0

var mouse_threshold : int = 10

var screensaver_mode : uint = 0u

[sideeffects]
def private c2da___bswap_16_20(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_20(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_20(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_20(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_20(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_20(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
var usemouse : int = 0

[export, sideeffects]
def cmap_to_rgb565(var out : int; var in_0 : int; var in_pixels : int) {
    var j_0 : int
    var c : color
    for (i_3 in range(0, in_pixels)) {
        let c2da_fresh22 : int = 298928 + int(c2da_mem[in_0]) * 4
        var c2da_fresh23 : color
        c2da_fresh23.c2da_bits_0 = uint(c2da_mem[c2da_fresh22]) | uint(c2da_mem[c2da_fresh22 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh22 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh22 + 3]) << 0x18
        c = c2da_fresh23
        let c2da_fresh24 : uint16 = uint16(int(uint16(int(uint16(int(c.c2da_bits_0 >> 16 & 0xff) >> 3)) << 11)) | int(uint16(int(uint16(int(c.c2da_bits_0 >> 8 & 0xff) >> 2)) << 5)) | int(uint16(int(uint16(int(c.c2da_bits_0 & 0xff) >> 3)) << 0)))
        let c2da_fresh25 : uint = uint(c2da_fresh24)
        c2da_mem[out] = uint8(c2da_fresh25)
        c2da_mem[out + 1] = uint8(c2da_fresh25 >> 0x8)
        in_0++
        j_0 = 0
        while (j_0 < fb_scaling) {
            out += 2
            j_0++
        }
    }
    return
}
[export, sideeffects]
def cmap_to_fb(var out_0 : int; var in_1 : int; var in_pixels_0 : int) {
    var k_0 : int
    var c_0 : color
    var pix : uint
    var p : uint16
    for (i_4 in range(0, in_pixels_0)) {
        let c2da_fresh26 : int = 298928 + int(c2da_mem[in_1]) * 4
        var c2da_fresh27 : color
        c2da_fresh27.c2da_bits_0 = uint(c2da_mem[c2da_fresh26]) | uint(c2da_mem[c2da_fresh26 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh26 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh26 + 3]) << 0x18
        c_0 = c2da_fresh27
        if ((uint(c2da_mem[378256]) | uint(c2da_mem[378257]) << 0x8 | uint(c2da_mem[378258]) << 0x10 | uint(c2da_mem[378259]) << 0x18) == 16u) {
            p = uint16((int(c_0.c2da_bits_0 >> 16 & 0xff) & 248) << 8 | (int(c_0.c2da_bits_0 >> 8 & 0xff) & 252) << 3 | int(c_0.c2da_bits_0 & 0xff) >> 3)
            k_0 = 0
            while (k_0 < fb_scaling) {
                let c2da_fresh28 : uint = uint(p)
                c2da_mem[out_0] = uint8(c2da_fresh28)
                c2da_mem[out_0 + 1] = uint8(c2da_fresh28 >> 0x8)
                out_0 += 2
                k_0++
            }
        } elif ((uint(c2da_mem[378256]) | uint(c2da_mem[378257]) << 0x8 | uint(c2da_mem[378258]) << 0x10 | uint(c2da_mem[378259]) << 0x18) == 32u) {
            pix = uint(int(c_0.c2da_bits_0 >> 16 & 0xff) << int(uint(c2da_mem[378260]) | uint(c2da_mem[378261]) << 0x8 | uint(c2da_mem[378262]) << 0x10 | uint(c2da_mem[378263]) << 0x18) | int(c_0.c2da_bits_0 >> 8 & 0xff) << int(uint(c2da_mem[378268]) | uint(c2da_mem[378269]) << 0x8 | uint(c2da_mem[378270]) << 0x10 | uint(c2da_mem[378271]) << 0x18) | int(c_0.c2da_bits_0 & 0xff) << int(uint(c2da_mem[378276]) | uint(c2da_mem[378277]) << 0x8 | uint(c2da_mem[378278]) << 0x10 | uint(c2da_mem[378279]) << 0x18))
            k_0 = 0
            while (k_0 < fb_scaling) {
                let c2da_fresh29 : uint = pix
                c2da_mem[out_0] = uint8(c2da_fresh29)
                c2da_mem[out_0 + 1] = uint8(c2da_fresh29 >> 0x8)
                c2da_mem[out_0 + 2] = uint8(c2da_fresh29 >> 0x10)
                c2da_mem[out_0 + 3] = uint8(c2da_fresh29 >> 0x18)
                out_0 += 4
                k_0++
            }
        } else {
            I_Error(378640, [C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[378256]) | uint(c2da_mem[378257]) << 0x8 | uint(c2da_mem[378258]) << 0x10 | uint(c2da_mem[378259]) << 0x18), f64 = 0.0lf, raw = 0x0)])
        }
        in_1++
    }
    return
}

// This unit's static data, at heap offset 378240.
let private c2da_lin_static_i_video_seg = fixed_array<int>(378292, 384)
let private c2da_lin_static_i_video = fixed_array<uint64>(0x724774696e495f49ul, 0x203a736369687061ul, 0x667562656d617266ul, 0x725f78203a726566ul, 0x202c6425203a7365ul, 0x25203a7365725f79ul, 0x7269765f78202c64ul, 0x6425203a6c617574ul, 0x747269765f79202cul, 0x2c6425203a6c6175ul, 0x6425203a70706220ul, 0x74696e495f49000aul, 0x7363696870617247ul, 0x62656d617266203aul, 0x52203a7265666675ul, 0x256425203a414247ul, 0x72202c6425642564ul, 0x203a66666f5f6465ul, 0x65657267202c6425ul, 0x25203a66666f5f6eul, 0x5f65756c62202c64ul, 0x2c6425203a66666ful, 0x5f70736e61727420ul, 0xa6425203a66666ful, 0x4774696e495f4900ul, 0x3a73636968706172ul, 0x6373204d4f4f4420ul, 0x7a6973206e656572ul, 0x6820782077203a65ul, 0x252078206425203aul, 0x6c6163732d000a64ul, 0x6e495f4900676e69ul, 0x6968706172477469ul, 0x6c616353203a7363ul, 0x7463616620676e69ul, 0xa6425203a726ful, 0x724774696e495f49ul, 0x203a736369687061ul, 0x6163732d6f747541ul, 0x63616620676e696cul, 0xa6425203a726f74ul, 0x61507465475f4900ul, 0x646e49657474656cul, 0x69206f4e000a7865ul, 0x20776f6820616564ul, 0x65766e6f63206f74ul, 0x7062206425207472ul, 0x736c657869702070ul)

[init]
def private c2da_lin_init_static_i_video() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_i_video_seg[s * 2]
        for (k in range(c2da_lin_static_i_video_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_i_video[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
