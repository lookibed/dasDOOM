var private c2da_str_v_video_0 : array<int8> = [int8(66), int8(97), int8(100), int8(32), int8(86), int8(95), int8(67), int8(111), int8(112), int8(121), int8(82), int8(101), int8(99), int8(116), int8(0)]

var private c2da_str_v_video_1 : array<int8> = [int8(66), int8(97), int8(100), int8(32), int8(86), int8(95), int8(68), int8(114), int8(97), int8(119), int8(80), int8(97), int8(116), int8(99), int8(104), int8(32), int8(120), int8(61), int8(37), int8(105), int8(32), int8(121), int8(61), int8(37), int8(105), int8(32), int8(112), int8(97), int8(116), int8(99), int8(104), int8(46), int8(119), int8(105), int8(100), int8(116), int8(104), int8(61), int8(37), int8(105), int8(32), int8(112), int8(97), int8(116), int8(99), int8(104), int8(46), int8(104), int8(101), int8(105), int8(103), int8(104), int8(116), int8(61), int8(37), int8(105), int8(32), int8(116), int8(111), int8(112), int8(111), int8(102), int8(102), int8(115), int8(101), int8(116), int8(61), int8(37), int8(105), int8(32), int8(108), int8(101), int8(102), int8(116), int8(111), int8(102), int8(102), int8(115), int8(101), int8(116), int8(61), int8(37), int8(105), int8(0)]

var private c2da_str_v_video_2 : array<int8> = [int8(66), int8(97), int8(100), int8(32), int8(86), int8(95), int8(68), int8(114), int8(97), int8(119), int8(80), int8(97), int8(116), int8(99), int8(104), int8(70), int8(108), int8(105), int8(112), int8(112), int8(101), int8(100), int8(0)]

var private c2da_str_v_video_3 : array<int8> = [int8(66), int8(97), int8(100), int8(32), int8(86), int8(95), int8(68), int8(114), int8(97), int8(119), int8(84), int8(76), int8(80), int8(97), int8(116), int8(99), int8(104), int8(0)]

var private c2da_str_v_video_4 : array<int8> = [int8(66), int8(97), int8(100), int8(32), int8(86), int8(95), int8(68), int8(114), int8(97), int8(119), int8(65), int8(108), int8(116), int8(84), int8(76), int8(80), int8(97), int8(116), int8(99), int8(104), int8(0)]

var private c2da_str_v_video_5 : array<int8> = [int8(66), int8(97), int8(100), int8(32), int8(86), int8(95), int8(68), int8(114), int8(97), int8(119), int8(83), int8(104), int8(97), int8(100), int8(111), int8(119), int8(101), int8(100), int8(80), int8(97), int8(116), int8(99), int8(104), int8(0)]

var private c2da_str_v_video_6 : array<int8> = [int8(66), int8(97), int8(100), int8(32), int8(86), int8(95), int8(68), int8(114), int8(97), int8(119), int8(66), int8(108), int8(111), int8(99), int8(107), int8(0)]

var private c2da_str_v_video_7 : array<int8> = [int8(112), int8(99), int8(120), int8(0)]

var private c2da_str_v_video_8 : array<int8> = [int8(86), int8(95), int8(83), int8(99), int8(114), int8(101), int8(101), int8(110), int8(83), int8(104), int8(111), int8(116), int8(58), int8(32), int8(67), int8(111), int8(117), int8(108), int8(100), int8(110), int8(39), int8(116), int8(32), int8(99), int8(114), int8(101), int8(97), int8(116), int8(101), int8(32), int8(97), int8(32), int8(80), int8(67), int8(88), int8(0)]

var private c2da_str_v_video_9 : array<int8> = [int8(80), int8(76), int8(65), int8(89), int8(80), int8(65), int8(76), int8(0)]

var private c2da_str_v_video_10 : array<int8> = [int8(84), int8(73), int8(78), int8(84), int8(84), int8(65), int8(66), int8(0)]

var private c2da_str_v_video_11 : array<int8> = [int8(88), int8(76), int8(65), int8(84), int8(65), int8(66), int8(0)]

var dirtybox : int[4]

var tinttable : uint8? = null

[export, sideeffects]
def V_SetPatchClipCallback(var func : vpatchclipfunc_t) {
    patchclip_callback = func
    return
}
var private patchclip_callback : vpatchclipfunc_t = default<vpatchclipfunc_t>

[export, sideeffects]
def V_Init() {
    return
}
[export, sideeffects]
def V_CopyRect(var srcx : int; var srcy : int; var source : uint8?; var width : int; var height : int; var destx : int; var desty : int) {
    var src : uint8?
    var dest : uint8?
    if (srcx < 0 || srcx + width > 320 || srcy < 0 || srcy + height > 200 || destx < 0 || destx + width > 320 || desty < 0 || desty + height > 200) {
        I_Error(unsafe(addr<int8?>(c2da_str_v_video_0[0])), [])
    }
    V_MarkRect(destx, desty, width, height)
    src = unsafe(reinterpret<uint8?>(unsafe(unsafe(source + 320 * srcy) + srcx)))
    dest = unsafe(reinterpret<uint8?>(unsafe(unsafe(dest_screen + 320 * desty) + destx)))
    while (height > 0) {
        let c2da_fresh0 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(dest))))
        let c2da_fresh1 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(src))))
        let c2da_fresh2 : uint64 = uint64(width)
        if (c2da_fresh2 != 0x0) {
            unsafe(memcpy(unsafe(reinterpret<void?>(c2da_fresh0)), unsafe(reinterpret<void?>(c2da_fresh1)), c2da_fresh2))
        }
        unsafe {  // nolint:STYLE025
            src += 320
        }
        unsafe {  // nolint:STYLE025
            dest += 320
        }
        height--
    }
    return
}
var private dest_screen : uint8? = null

[export, sideeffects]
def V_MarkRect(var x : int; var y : int; var width_0 : int; var height_0 : int) {
    if (dest_screen == I_VideoBuffer) {
        M_AddToBox(unsafe(addr<int?>(dirtybox[0])), x, y)
        M_AddToBox(unsafe(addr<int?>(dirtybox[0])), x + width_0 - 1, y + height_0 - 1)
    }
    return
}
[export, sideeffects]
def V_DrawPatch(var x_0 : int; var y_0 : int; var patch : patch_t?) {
    var count : int
    var col : int
    var column : post_t?
    var desttop : uint8?
    var dest_0 : uint8?
    var source_0 : uint8?
    var w : int
    y_0 -= int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch))))[3]))
    x_0 -= int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch))))[2]))
    if (patchclip_callback != default<vpatchclipfunc_t>) {
        if (invoke(patchclip_callback, patch, x_0, y_0) == 0) {
            return
        }
    }
    if (x_0 < 0 || x_0 + int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch))))[0])) > 320 || y_0 < 0 || y_0 + int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch))))[1])) > 200) {
        I_Error(unsafe(addr<int8?>(c2da_str_v_video_1[0])), [C2daVaArg(tag = 1, i64 = int64(x_0), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(y_0), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch))))[0])), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch))))[1])), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch))))[3])), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch))))[2])), f64 = 0.0lf, raw = 0x0)])
    }
    V_MarkRect(x_0, y_0, int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch))))[0])), int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch))))[1])))
    col = 0
    desttop = unsafe(reinterpret<uint8?>(unsafe(unsafe(dest_screen + int64(y_0 * 320)) + x_0)))
    w = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch))))[0]))
    while (col < w) {
        var c2da_fresh3 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(patch)) + 8ul))
        column = unsafe(reinterpret<post_t?>(unsafe(reinterpret<post_t?>(unsafe(unsafe(reinterpret<uint8?>(patch)) + int64(unsafe(unsafe(reinterpret<int?>(c2da_fresh3))[col])))))))
        while (int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column))))[0])) != 255) {
            source_0 = unsafe(reinterpret<uint8?>(unsafe(unsafe(reinterpret<uint8?>(column)) + 3)))
            dest_0 = unsafe(reinterpret<uint8?>(unsafe(desttop + int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column))))[0])) * 320)))
            count = int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column))))[1]))
            var c2da_source_0_addr : uint64 = unsafe(reinterpret<uint64>(source_0))
            var c2da_dest_0_addr : uint64 = unsafe(reinterpret<uint64>(dest_0))
            while (true) {
                let c2da_postinc : int = count
                count--
                if (c2da_postinc == 0) {
                    break
                }
                *unsafe(reinterpret<uint8?>(c2da_dest_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_source_0_addr)))  // nolint:PERF020
                c2da_source_0_addr++
                c2da_dest_0_addr += 320ul
            }
            source_0 = unsafe(reinterpret<uint8?>(c2da_source_0_addr))
            dest_0 = unsafe(reinterpret<uint8?>(c2da_dest_0_addr))
            column = unsafe(reinterpret<post_t?>(unsafe(reinterpret<post_t?>(unsafe(unsafe(unsafe(reinterpret<uint8?>(column)) + int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column))))[1]))) + 4)))))
        }
        x_0++
        col++
        unsafe {  // nolint:STYLE025
            desttop += 1
        }
    }
    return
}
[export, sideeffects]
def V_DrawPatchFlipped(var x_1 : int; var y_1 : int; var patch_0 : patch_t?) {
    var count_0 : int
    var col_0 : int
    var column_0 : post_t?
    var desttop_0 : uint8?
    var dest_1 : uint8?
    var source_1 : uint8?
    var w_0 : int
    y_1 -= int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_0))))[3]))
    x_1 -= int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_0))))[2]))
    if (patchclip_callback != default<vpatchclipfunc_t>) {
        if (invoke(patchclip_callback, patch_0, x_1, y_1) == 0) {
            return
        }
    }
    if (x_1 < 0 || x_1 + int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_0))))[0])) > 320 || y_1 < 0 || y_1 + int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_0))))[1])) > 200) {
        I_Error(unsafe(addr<int8?>(c2da_str_v_video_2[0])), [])
    }
    V_MarkRect(x_1, y_1, int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_0))))[0])), int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_0))))[1])))
    col_0 = 0
    desttop_0 = unsafe(reinterpret<uint8?>(unsafe(unsafe(dest_screen + int64(y_1 * 320)) + x_1)))
    w_0 = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_0))))[0]))
    while (col_0 < w_0) {
        var c2da_fresh4 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(patch_0)) + 8ul))
        column_0 = unsafe(reinterpret<post_t?>(unsafe(reinterpret<post_t?>(unsafe(unsafe(reinterpret<uint8?>(patch_0)) + int64(unsafe(unsafe(reinterpret<int?>(c2da_fresh4))[w_0 - 1 - col_0])))))))
        while (int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_0))))[0])) != 255) {
            source_1 = unsafe(reinterpret<uint8?>(unsafe(unsafe(reinterpret<uint8?>(column_0)) + 3)))
            dest_1 = unsafe(reinterpret<uint8?>(unsafe(desttop_0 + int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_0))))[0])) * 320)))
            count_0 = int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_0))))[1]))
            var c2da_source_1_addr : uint64 = unsafe(reinterpret<uint64>(source_1))
            var c2da_dest_1_addr : uint64 = unsafe(reinterpret<uint64>(dest_1))
            while (true) {
                let c2da_postinc_0 : int = count_0
                count_0--
                if (c2da_postinc_0 == 0) {
                    break
                }
                *unsafe(reinterpret<uint8?>(c2da_dest_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_source_1_addr)))  // nolint:PERF020
                c2da_source_1_addr++
                c2da_dest_1_addr += 320ul
            }
            source_1 = unsafe(reinterpret<uint8?>(c2da_source_1_addr))
            dest_1 = unsafe(reinterpret<uint8?>(c2da_dest_1_addr))
            column_0 = unsafe(reinterpret<post_t?>(unsafe(reinterpret<post_t?>(unsafe(unsafe(unsafe(reinterpret<uint8?>(column_0)) + int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_0))))[1]))) + 4)))))
        }
        x_1++
        col_0++
        unsafe {  // nolint:STYLE025
            desttop_0 += 1
        }
    }
    return
}
[export, sideeffects]
def V_DrawTLPatch(var x_2 : int; var y_3 : int; var patch_1 : patch_t?) {
    var count_1 : int
    var col_1 : int
    var column_1 : post_t?
    var desttop_1 : uint8?
    var dest_2 : uint8?
    var source_2 : uint8?
    var w_1 : int
    y_3 -= int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_1))))[3]))
    x_2 -= int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_1))))[2]))
    if (x_2 < 0 || x_2 + int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_1))))[0])) > 320 || y_3 < 0 || y_3 + int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_1))))[1])) > 200) {
        I_Error(unsafe(addr<int8?>(c2da_str_v_video_3[0])), [])
    }
    col_1 = 0
    desttop_1 = unsafe(reinterpret<uint8?>(unsafe(unsafe(dest_screen + int64(y_3 * 320)) + x_2)))
    w_1 = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_1))))[0]))
    while (col_1 < w_1) {
        var c2da_fresh5 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(patch_1)) + 8ul))
        column_1 = unsafe(reinterpret<post_t?>(unsafe(reinterpret<post_t?>(unsafe(unsafe(reinterpret<uint8?>(patch_1)) + int64(unsafe(unsafe(reinterpret<int?>(c2da_fresh5))[col_1])))))))
        while (int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_1))))[0])) != 255) {
            source_2 = unsafe(reinterpret<uint8?>(unsafe(unsafe(reinterpret<uint8?>(column_1)) + 3)))
            dest_2 = unsafe(reinterpret<uint8?>(unsafe(desttop_1 + int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_1))))[0])) * 320)))
            count_1 = int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_1))))[1]))
            var c2da_source_2_addr : uint64 = unsafe(reinterpret<uint64>(source_2))
            while (true) {
                let c2da_postinc_1 : int = count_1
                count_1--
                if (c2da_postinc_1 == 0) {
                    break
                }
                *dest_2 = uint8(unsafe(tinttable[(int(*dest_2) << 8) + int(*unsafe(reinterpret<uint8?>(c2da_source_2_addr)))]))  // nolint:PERF020
                c2da_source_2_addr++
                unsafe {  // nolint:STYLE025
                    dest_2 += 320
                }
            }
            source_2 = unsafe(reinterpret<uint8?>(c2da_source_2_addr))
            column_1 = unsafe(reinterpret<post_t?>(unsafe(reinterpret<post_t?>(unsafe(unsafe(unsafe(reinterpret<uint8?>(column_1)) + int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_1))))[1]))) + 4)))))
        }
        x_2++
        col_1++
        unsafe {  // nolint:STYLE025
            desttop_1 += 1
        }
    }
    return
}
[export, sideeffects]
def V_DrawAltTLPatch(var x_3 : int; var y_4 : int; var patch_2 : patch_t?) {
    var count_2 : int
    var col_2 : int
    var column_2 : post_t?
    var desttop_2 : uint8?
    var dest_3 : uint8?
    var source_3 : uint8?
    var w_2 : int
    y_4 -= int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_2))))[3]))
    x_3 -= int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_2))))[2]))
    if (x_3 < 0 || x_3 + int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_2))))[0])) > 320 || y_4 < 0 || y_4 + int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_2))))[1])) > 200) {
        I_Error(unsafe(addr<int8?>(c2da_str_v_video_4[0])), [])
    }
    col_2 = 0
    desttop_2 = unsafe(reinterpret<uint8?>(unsafe(unsafe(dest_screen + int64(y_4 * 320)) + x_3)))
    w_2 = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_2))))[0]))
    while (col_2 < w_2) {
        var c2da_fresh6 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(patch_2)) + 8ul))
        column_2 = unsafe(reinterpret<post_t?>(unsafe(reinterpret<post_t?>(unsafe(unsafe(reinterpret<uint8?>(patch_2)) + int64(unsafe(unsafe(reinterpret<int?>(c2da_fresh6))[col_2])))))))
        while (int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_2))))[0])) != 255) {
            source_3 = unsafe(reinterpret<uint8?>(unsafe(unsafe(reinterpret<uint8?>(column_2)) + 3)))
            dest_3 = unsafe(reinterpret<uint8?>(unsafe(desttop_2 + int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_2))))[0])) * 320)))
            count_2 = int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_2))))[1]))
            var c2da_source_3_addr : uint64 = unsafe(reinterpret<uint64>(source_3))
            while (true) {
                let c2da_postinc_2 : int = count_2
                count_2--
                if (c2da_postinc_2 == 0) {
                    break
                }
                *dest_3 = uint8(unsafe(tinttable[(int(*dest_3) << 8) + int(*unsafe(reinterpret<uint8?>(c2da_source_3_addr)))]))  // nolint:PERF020
                c2da_source_3_addr++
                unsafe {  // nolint:STYLE025
                    dest_3 += 320
                }
            }
            source_3 = unsafe(reinterpret<uint8?>(c2da_source_3_addr))
            column_2 = unsafe(reinterpret<post_t?>(unsafe(reinterpret<post_t?>(unsafe(unsafe(unsafe(reinterpret<uint8?>(column_2)) + int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_2))))[1]))) + 4)))))
        }
        x_3++
        col_2++
        unsafe {  // nolint:STYLE025
            desttop_2 += 1
        }
    }
    return
}
[export, sideeffects]
def V_DrawShadowedPatch(var x_4 : int; var y_5 : int; var patch_3 : patch_t?) {
    var count_3 : int
    var col_3 : int
    var column_3 : post_t?
    var desttop_3 : uint8?
    var dest_4 : uint8?
    var source_4 : uint8?
    var desttop2 : uint8?
    var dest2 : uint8?
    var w_3 : int
    y_5 -= int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_3))))[3]))
    x_4 -= int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_3))))[2]))
    if (x_4 < 0 || x_4 + int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_3))))[0])) > 320 || y_5 < 0 || y_5 + int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_3))))[1])) > 200) {
        I_Error(unsafe(addr<int8?>(c2da_str_v_video_5[0])), [])
    }
    col_3 = 0
    desttop_3 = unsafe(reinterpret<uint8?>(unsafe(unsafe(dest_screen + int64(y_5 * 320)) + x_4)))
    desttop2 = unsafe(reinterpret<uint8?>(unsafe(unsafe(unsafe(dest_screen + int64((y_5 + 2) * 320)) + x_4) + 2)))
    w_3 = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_3))))[0]))
    while (col_3 < w_3) {
        var c2da_fresh7 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(patch_3)) + 8ul))
        column_3 = unsafe(reinterpret<post_t?>(unsafe(reinterpret<post_t?>(unsafe(unsafe(reinterpret<uint8?>(patch_3)) + int64(unsafe(unsafe(reinterpret<int?>(c2da_fresh7))[col_3])))))))
        while (int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_3))))[0])) != 255) {
            source_4 = unsafe(reinterpret<uint8?>(unsafe(unsafe(reinterpret<uint8?>(column_3)) + 3)))
            dest_4 = unsafe(reinterpret<uint8?>(unsafe(desttop_3 + int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_3))))[0])) * 320)))
            dest2 = unsafe(reinterpret<uint8?>(unsafe(desttop2 + int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_3))))[0])) * 320)))
            count_3 = int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_3))))[1]))
            var c2da_source_4_addr : uint64 = unsafe(reinterpret<uint64>(source_4))
            var c2da_dest_4_addr : uint64 = unsafe(reinterpret<uint64>(dest_4))
            while (true) {
                let c2da_postinc_3 : int = count_3
                count_3--
                if (c2da_postinc_3 == 0) {
                    break
                }
                *dest2 = uint8(unsafe(tinttable[int(*dest2) << 8]))  // nolint:PERF020
                unsafe {  // nolint:STYLE025
                    dest2 += 320
                }
                *unsafe(reinterpret<uint8?>(c2da_dest_4_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_source_4_addr)))  // nolint:PERF020
                c2da_source_4_addr++
                c2da_dest_4_addr += 320ul
            }
            source_4 = unsafe(reinterpret<uint8?>(c2da_source_4_addr))
            dest_4 = unsafe(reinterpret<uint8?>(c2da_dest_4_addr))
            column_3 = unsafe(reinterpret<post_t?>(unsafe(reinterpret<post_t?>(unsafe(unsafe(unsafe(reinterpret<uint8?>(column_3)) + int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_3))))[1]))) + 4)))))
        }
        x_4++
        col_3++
        unsafe {  // nolint:STYLE025
            desttop_3 += 1
        }
        unsafe {  // nolint:STYLE025
            desttop2 += 1
        }
    }
    return
}
[export, sideeffects]
def V_DrawXlaPatch(var x_5 : int; var y_6 : int; var patch_4 : patch_t?) {
    var count_4 : int
    var col_4 : int
    var column_4 : post_t?
    var desttop_4 : uint8?
    var dest_5 : uint8?
    var source_5 : uint8?
    var w_4 : int
    y_6 -= int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_4))))[3]))
    x_5 -= int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_4))))[2]))
    if (patchclip_callback != default<vpatchclipfunc_t>) {
        if (invoke(patchclip_callback, patch_4, x_5, y_6) == 0) {
            return
        }
    }
    col_4 = 0
    desttop_4 = unsafe(reinterpret<uint8?>(unsafe(unsafe(dest_screen + int64(y_6 * 320)) + x_5)))
    w_4 = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(patch_4))))[0]))
    while (col_4 < w_4) {
        var c2da_fresh8 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(patch_4)) + 8ul))
        column_4 = unsafe(reinterpret<post_t?>(unsafe(reinterpret<post_t?>(unsafe(unsafe(reinterpret<uint8?>(patch_4)) + int64(unsafe(unsafe(reinterpret<int?>(c2da_fresh8))[col_4])))))))
        while (int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_4))))[0])) != 255) {
            source_5 = unsafe(reinterpret<uint8?>(unsafe(unsafe(reinterpret<uint8?>(column_4)) + 3)))
            dest_5 = unsafe(reinterpret<uint8?>(unsafe(desttop_4 + int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_4))))[0])) * 320)))
            count_4 = int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_4))))[1]))
            var c2da_dest_5_addr : uint64 = unsafe(reinterpret<uint64>(dest_5))
            while (true) {
                let c2da_postinc_4 : int = count_4
                count_4--
                if (c2da_postinc_4 == 0) {
                    break
                }
                *unsafe(reinterpret<uint8?>(c2da_dest_5_addr)) = uint8(unsafe(xlatab[int(*unsafe(reinterpret<uint8?>(c2da_dest_5_addr))) + (int(*source_5) << 8)]))  // nolint:PERF020
                unsafe {  // nolint:STYLE025
                    source_5 += 1
                }
                c2da_dest_5_addr += 320ul
            }
            dest_5 = unsafe(reinterpret<uint8?>(c2da_dest_5_addr))
            column_4 = unsafe(reinterpret<post_t?>(unsafe(reinterpret<post_t?>(unsafe(unsafe(unsafe(reinterpret<uint8?>(column_4)) + int(unsafe(unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(column_4))))[1]))) + 4)))))
        }
        x_5++
        col_4++
        unsafe {  // nolint:STYLE025
            desttop_4 += 1
        }
    }
    return
}
var xlatab : uint8? = null

[export, sideeffects]
def V_DrawPatchDirect(var x_6 : int; var y_7 : int; var patch_5 : patch_t?) {
    V_DrawPatch(x_6, y_7, patch_5)
    return
}
[export, sideeffects]
def V_DrawBlock(var x_7 : int; var y_8 : int; var width_1 : int; var height_1 : int; var src_0 : uint8?) {
    var dest_6 : uint8?
    if (x_7 < 0 || x_7 + width_1 > 320 || y_8 < 0 || y_8 + height_1 > 200) {
        I_Error(unsafe(addr<int8?>(c2da_str_v_video_6[0])), [])
    }
    V_MarkRect(x_7, y_8, width_1, height_1)
    dest_6 = unsafe(reinterpret<uint8?>(unsafe(unsafe(dest_screen + int64(y_8 * 320)) + x_7)))
    while (true) {
        let c2da_postinc_5 : int = height_1
        height_1--
        if (c2da_postinc_5 == 0) {
            break
        }
        let c2da_fresh9 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(dest_6))))
        let c2da_fresh10 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(src_0))))
        let c2da_fresh11 : uint64 = uint64(width_1)
        if (c2da_fresh11 != 0x0) {
            unsafe(memcpy(unsafe(reinterpret<void?>(c2da_fresh9)), unsafe(reinterpret<void?>(c2da_fresh10)), c2da_fresh11))
        }
        unsafe {  // nolint:STYLE025
            src_0 += int64(width_1)
        }
        unsafe {  // nolint:STYLE025
            dest_6 += 320
        }
    }
    return
}
[export, sideeffects]
def V_DrawFilledBox(var x_8 : int; var y_9 : int; var w_5 : int; var h : int; var c : int) {
    var buf : uint8?
    var buf1 : uint8?
    buf = unsafe(reinterpret<uint8?>(unsafe(unsafe(I_VideoBuffer + 320 * y_9) + x_8)))
    for (y1 in range(0, h)) {
        buf1 = unsafe(reinterpret<uint8?>(buf))
        var c2da_buf1_addr : uint64 = unsafe(reinterpret<uint64>(buf1))
        for (x1 in range(0, w_5)) {
            *unsafe(reinterpret<uint8?>(c2da_buf1_addr)) = uint8(c)
            c2da_buf1_addr++
        }
        unsafe {  // nolint:STYLE025
            buf += 320
        }
    }
    return
}
[export, sideeffects]
def V_DrawHorizLine(var x_9 : int; var y_10 : int; var w_6 : int; var c_0 : int) {
    var buf_0 : uint8? = unsafe(reinterpret<uint8?>(unsafe(unsafe(I_VideoBuffer + 320 * y_10) + x_9)))
    var c2da_buf_0_addr : uint64 = unsafe(reinterpret<uint64>(buf_0))
    for (x1_0 in range(0, w_6)) {
        *unsafe(reinterpret<uint8?>(c2da_buf_0_addr)) = uint8(c_0)
        c2da_buf_0_addr++
    }
    return
}
[export, sideeffects]
def V_DrawVertLine(var x_10 : int; var y_11 : int; var h_0 : int; var c_1 : int) {
    var buf_1 : uint8? = unsafe(reinterpret<uint8?>(unsafe(unsafe(I_VideoBuffer + 320 * y_11) + x_10)))
    var c2da_buf_1_addr : uint64 = unsafe(reinterpret<uint64>(buf_1))
    for (y1_0 in range(0, h_0)) {
        *unsafe(reinterpret<uint8?>(c2da_buf_1_addr)) = uint8(c_1)
        c2da_buf_1_addr += 320ul
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
def V_DrawRawScreen(var raw : uint8?) {
    let c2da_fresh12 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(dest_screen))))
    let c2da_fresh13 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(raw))))
    let c2da_fresh14 : uint64 = uint64(320 * 200)
    if (c2da_fresh14 != 0x0) {
        unsafe(memcpy(unsafe(reinterpret<void?>(c2da_fresh12)), unsafe(reinterpret<void?>(c2da_fresh13)), c2da_fresh14))
    }
    return
}
[export, sideeffects]
def V_UseBuffer(var buffer : uint8?) {
    dest_screen = unsafe(reinterpret<uint8?>(buffer))
    return
}
[export, sideeffects]
def V_RestoreBuffer() {
    dest_screen = unsafe(reinterpret<uint8?>(I_VideoBuffer))
    return
}
[export, sideeffects]
def V_ScreenShot(var format : int8?) {
    var i : int
    var lbmname : int8[16]
    var ext : int8? = unsafe(addr<int8?>(c2da_str_v_video_7[0]))
    i = 0
    while (i <= 99) {
        M_snprintf(unsafe(addr<int8?>(lbmname[0])), 16ul, unsafe(reinterpret<int8 const?>(format)), [C2daVaArg(tag = 1, i64 = int64(i), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(ext)))])
        if (M_FileExists(unsafe(addr<int8?>(lbmname[0]))) == 0) {
            break
        }
        i++
    }
    if (i == 100) {
        I_Error(unsafe(addr<int8?>(c2da_str_v_video_8[0])), [])
    }
    WritePCXfile(unsafe(addr<int8?>(lbmname[0])), I_VideoBuffer, 320, 200, unsafe(reinterpret<uint8?>(W_CacheLumpName(unsafe(addr<int8?>(c2da_str_v_video_9[0])), 8))))
    return
}
[export, sideeffects]
def WritePCXfile(var filename : int8?; var data : uint8?; var width_2 : int; var height_2 : int; var palette : uint8?) {
    var i_0 : int
    var pcx : pcx_t?
    var pack : uint8?
    pcx = unsafe(reinterpret<pcx_t?>(unsafe(reinterpret<pcx_t?>(Z_Malloc(width_2 * height_2 * 2 + 1000, 1, null)))))
    unsafe(unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(pcx))))[0]) = int8(10)
    unsafe(unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(pcx))))[1]) = int8(5)
    unsafe(unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(pcx))))[2]) = int8(1)
    unsafe(unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(pcx))))[3]) = int8(8)
    unsafe(unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(pcx))))[2]) = uint16(0)
    unsafe(unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(pcx))))[3]) = uint16(0)
    unsafe(unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(pcx))))[4]) = uint16(int16(width_2 - 1))
    unsafe(unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(pcx))))[5]) = uint16(int16(height_2 - 1))
    unsafe(unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(pcx))))[6]) = uint16(int16(width_2))
    unsafe(unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(pcx))))[7]) = uint16(int16(height_2))
    var c2da_fresh15 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pcx)) + 16ul))
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(c2da_fresh15)))), 0u8, 48ul)))
    unsafe(unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(pcx))))[65]) = int8(1)
    unsafe(unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(pcx))))[33]) = uint16(int16(width_2))
    unsafe(unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(pcx))))[34]) = uint16(2)
    var c2da_fresh16 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(pcx)) + 70ul))
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(c2da_fresh16)))), 0u8, 58ul)))
    var c2da_fresh17 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pcx)) + 128ul))
    pack = unsafe(reinterpret<uint8?>(c2da_fresh17))
    i_0 = 0
    while (i_0 < width_2 * height_2) {
        if ((int(*data) & 192) != 192) {
            var c2da_postinc_6 : uint8? = data
            unsafe {  // nolint:STYLE025
                data += 1
            }
            *pack = uint8(*c2da_postinc_6)  // nolint:PERF020
            unsafe {  // nolint:STYLE025
                pack += 1
            }
        } else {
            *pack = 0xc1u8
            unsafe {  // nolint:STYLE025
                pack += 1
            }
            var c2da_postinc_7 : uint8? = data
            unsafe {  // nolint:STYLE025
                data += 1
            }
            *pack = uint8(*c2da_postinc_7)  // nolint:PERF020
            unsafe {  // nolint:STYLE025
                pack += 1
            }
        }
        i_0++
    }
    *pack = 0xcu8
    unsafe {  // nolint:STYLE025
        pack += 1
    }
    var c2da_pack_addr : uint64 = unsafe(reinterpret<uint64>(pack))
    var c2da_palette_addr : uint64 = unsafe(reinterpret<uint64>(palette))
    i_0 = 0
    for (c2da_i_0 in range(i_0, 768)) {
        *unsafe(reinterpret<uint8?>(c2da_pack_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_palette_addr)))  // nolint:PERF020
        c2da_pack_addr++
        c2da_palette_addr++
    }
    pack = unsafe(reinterpret<uint8?>(c2da_pack_addr))
    M_WriteFile(filename, unsafe(reinterpret<uint8?>(pcx)), int(unsafe(pack - unsafe(reinterpret<uint8?>(pcx)))))
    Z_Free(unsafe(reinterpret<uint8?>(pcx)))
    return
}
[export, sideeffects]
def V_LoadTintTable() {
    tinttable = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(W_CacheLumpName(unsafe(addr<int8?>(c2da_str_v_video_10[0])), 1)))))
    return
}
[export, sideeffects]
def V_LoadXlaTable() {
    xlatab = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(W_CacheLumpName(unsafe(addr<int8?>(c2da_str_v_video_11[0])), 1)))))
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
