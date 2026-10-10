var private c2da_str_st_lib_0 : array<int8> = [int8(83), int8(84), int8(84), int8(77), int8(73), int8(78), int8(85), int8(83), int8(0)]

var private c2da_str_st_lib_1 : array<int8> = [int8(100), int8(114), int8(97), int8(119), int8(78), int8(117), int8(109), int8(58), int8(32), int8(110), int8(45), int8(62), int8(121), int8(32), int8(45), int8(32), int8(83), int8(84), int8(95), int8(89), int8(32), int8(60), int8(32), int8(48), int8(0)]

var private c2da_str_st_lib_2 : array<int8> = [int8(117), int8(112), int8(100), int8(97), int8(116), int8(101), int8(77), int8(117), int8(108), int8(116), int8(73), int8(99), int8(111), int8(110), int8(58), int8(32), int8(121), int8(32), int8(45), int8(32), int8(83), int8(84), int8(95), int8(89), int8(32), int8(60), int8(32), int8(48), int8(0)]

var private c2da_str_st_lib_3 : array<int8> = [int8(117), int8(112), int8(100), int8(97), int8(116), int8(101), int8(66), int8(105), int8(110), int8(73), int8(99), int8(111), int8(110), int8(58), int8(32), int8(121), int8(32), int8(45), int8(32), int8(83), int8(84), int8(95), int8(89), int8(32), int8(60), int8(32), int8(48), int8(0)]

[export, sideeffects]
def STlib_init() {
    sttminus = unsafe(reinterpret<patch_t?>(unsafe(reinterpret<patch_t?>(unsafe(reinterpret<patch_t?>(W_CacheLumpName(unsafe(addr<int8?>(c2da_str_st_lib_0[0])), 1)))))))
    return
}
var sttminus : patch_t? = default<patch_t?>

[export, sideeffects]
def STlib_initNum(var n : st_number_t?; var x : int; var y : int; var pl : patch_t??; var num : int?; var on : uint?; var width : int) {
    n.x = int(x)  // nolint:PERF020
    n.y = int(y)  // nolint:PERF020
    n.oldnum = 0
    n.width = int(width)  // nolint:PERF020
    n.num = num
    n.on = on
    n.p = pl
    return
}
[export, sideeffects]
def STlib_updateNum(var n_0 : st_number_t?; var refresh : uint) {
    if (*n_0.on != 0x0) {
        STlib_drawNum(n_0, refresh)
    }
    return
}
[export, sideeffects]
def STlib_drawNum(var n_1 : st_number_t?; var refresh_0 : uint) {
    var numdigits : int
    var num_0 : int
    var w : int
    var h : int
    var x_0 : int
    var neg : int
    numdigits = n_1.width
    num_0 = *n_1.num
    w = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(n_1.p[0])))))[0]))
    h = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(n_1.p[0])))))[1]))
    x_0 = n_1.x
    n_1.oldnum = int(*n_1.num)  // nolint:PERF020
    neg = num_0 < 0 ? 1 : 0
    if (neg != 0) {
        if (numdigits == 2 && num_0 < -9) {
            num_0 = -9
        } elif (numdigits == 3 && num_0 < -99) {
            num_0 = -99
        }
        num_0 = -num_0
    }
    x_0 = n_1.x - numdigits * w
    if (n_1.y - (200 - 32) < 0) {
        I_Error(unsafe(addr<int8?>(c2da_str_st_lib_1[0])), [])
    }
    V_CopyRect(x_0, n_1.y - (200 - 32), st_backing_screen, w * numdigits, h, x_0, n_1.y)
    if (num_0 == 1994) {
        return
    }
    x_0 = n_1.x
    if (num_0 == 0) {
        V_DrawPatch(x_0 - w, n_1.y, unsafe(reinterpret<patch_t?>(unsafe(n_1.p[0]))))
    }
    while (true) {
        var c2da_fresh0 : int = 0
        if (num_0 != 0) {
            let c2da_postinc : int = numdigits
            numdigits--
            if (c2da_postinc != 0) {
                c2da_fresh0 = 1
            }
        }
        if (c2da_fresh0 == 0) {
            break
        }
        x_0 -= w
        V_DrawPatch(x_0, n_1.y, unsafe(reinterpret<patch_t?>(unsafe(n_1.p[num_0 % 10]))))
        num_0 /= 10
    }
    if (neg != 0) {
        V_DrawPatch(x_0 - 8, n_1.y, sttminus)
    }
    return
}
[export, sideeffects]
def STlib_initPercent(var p : st_percent_t?; var x_1 : int; var y_0 : int; var pl_0 : patch_t??; var num_1 : int?; var on_0 : uint?; var percent : patch_t?) {
    var c2da_fresh1 : st_number_t? = unsafe(reinterpret<st_number_t?>(unsafe(reinterpret<uint64>(p))))
    STlib_initNum(unsafe(reinterpret<st_number_t?>(c2da_fresh1)), x_1, y_0, pl_0, num_1, on_0, 3)
    p.p = percent
    return
}
[export, sideeffects]
def STlib_updatePercent(var per : st_percent_t?; var refresh_1 : int) {
    if (refresh_1 != 0 && *per.n.on != 0x0) {
        V_DrawPatch(per.n.x, per.n.y, per.p)
    }
    var c2da_fresh2 : st_number_t? = unsafe(reinterpret<st_number_t?>(unsafe(reinterpret<uint64>(per))))
    STlib_updateNum(unsafe(reinterpret<st_number_t?>(c2da_fresh2)), uint(refresh_1))
    return
}
[export, sideeffects]
def STlib_initMultIcon(var i : st_multicon_t?; var x_2 : int; var y_1 : int; var il : patch_t??; var inum : int?; var on_1 : uint?) {
    i.x = int(x_2)  // nolint:PERF020
    i.y = int(y_1)  // nolint:PERF020
    i.oldinum = -1
    i.inum = inum
    i.on = on_1
    i.p = il
    return
}
[export, sideeffects]
def STlib_updateMultIcon(var mi : st_multicon_t?; var refresh_2 : uint) {
    var w_0 : int
    var h_0 : int
    var x_3 : int
    var y_3 : int
    if (*mi.on != 0x0 && (mi.oldinum != *mi.inum || refresh_2 != 0x0) && *mi.inum != -1) {
        if (mi.oldinum != -1) {
            x_3 = mi.x - int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(mi.p[mi.oldinum])))))[2]))
            y_3 = mi.y - int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(mi.p[mi.oldinum])))))[3]))
            w_0 = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(mi.p[mi.oldinum])))))[0]))
            h_0 = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(mi.p[mi.oldinum])))))[1]))
            if (y_3 - (200 - 32) < 0) {
                I_Error(unsafe(addr<int8?>(c2da_str_st_lib_2[0])), [])
            }
            V_CopyRect(x_3, y_3 - (200 - 32), st_backing_screen, w_0, h_0, x_3, y_3)
        }
        V_DrawPatch(mi.x, mi.y, unsafe(reinterpret<patch_t?>(unsafe(mi.p[*mi.inum]))))
        mi.oldinum = int(*mi.inum)  // nolint:PERF020
    }
    return
}
[export, sideeffects]
def STlib_initBinIcon(var b : st_binicon_t?; var x_4 : int; var y_4 : int; var i_0 : patch_t?; var val : uint?; var on_2 : uint?) {
    b.x = int(x_4)  // nolint:PERF020
    b.y = int(y_4)  // nolint:PERF020
    b.oldval = 0u
    b.val = val
    b.on = on_2
    b.p = i_0
    return
}
[export, sideeffects]
def STlib_updateBinIcon(var bi : st_binicon_t?; var refresh_3 : uint) {
    var x_5 : int
    var y_5 : int
    var w_1 : int
    var h_1 : int
    if (*bi.on != 0x0 && (bi.oldval != *bi.val || refresh_3 != 0x0)) {
        x_5 = bi.x - int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(bi.p))))[2]))
        y_5 = bi.y - int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(bi.p))))[3]))
        w_1 = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(bi.p))))[0]))
        h_1 = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(bi.p))))[1]))
        if (y_5 - (200 - 32) < 0) {
            I_Error(unsafe(addr<int8?>(c2da_str_st_lib_3[0])), [])
        }
        if (*bi.val != 0x0) {
            V_DrawPatch(bi.x, bi.y, bi.p)
        } else {
            V_CopyRect(x_5, y_5 - (200 - 32), st_backing_screen, w_1, h_1, x_5, y_5)
        }
        bi.oldval = uint(*bi.val)  // nolint:PERF020
    }
    return
}
[sideeffects]
def private c2da_layout_proofs_35() {
    static_assert(typeinfo sizeof(type<st_number_t>) == 48, "C layout of st_number_t: sizeof")
    static_assert(typeinfo alignof(type<st_number_t>) == 8, "C layout of st_number_t: alignof")
    static_assert(typeinfo offsetof<x>(type<st_number_t>) == 0, "C layout of st_number_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<st_number_t>) == 4, "C layout of st_number_t: offsetof y")
    static_assert(typeinfo offsetof<width>(type<st_number_t>) == 8, "C layout of st_number_t: offsetof width")
    static_assert(typeinfo offsetof<oldnum>(type<st_number_t>) == 12, "C layout of st_number_t: offsetof oldnum")
    static_assert(typeinfo offsetof<num>(type<st_number_t>) == 16, "C layout of st_number_t: offsetof num")
    static_assert(typeinfo offsetof<on>(type<st_number_t>) == 24, "C layout of st_number_t: offsetof on")
    static_assert(typeinfo offsetof<p>(type<st_number_t>) == 32, "C layout of st_number_t: offsetof p")
    static_assert(typeinfo offsetof<data>(type<st_number_t>) == 40, "C layout of st_number_t: offsetof data")
    static_assert(typeinfo sizeof(type<st_percent_t>) == 56, "C layout of st_percent_t: sizeof")
    static_assert(typeinfo alignof(type<st_percent_t>) == 8, "C layout of st_percent_t: alignof")
    static_assert(typeinfo offsetof<n>(type<st_percent_t>) == 0, "C layout of st_percent_t: offsetof n")
    static_assert(typeinfo offsetof<p>(type<st_percent_t>) == 48, "C layout of st_percent_t: offsetof p")
    static_assert(typeinfo sizeof(type<st_multicon_t>) == 48, "C layout of st_multicon_t: sizeof")
    static_assert(typeinfo alignof(type<st_multicon_t>) == 8, "C layout of st_multicon_t: alignof")
    static_assert(typeinfo offsetof<x>(type<st_multicon_t>) == 0, "C layout of st_multicon_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<st_multicon_t>) == 4, "C layout of st_multicon_t: offsetof y")
    static_assert(typeinfo offsetof<oldinum>(type<st_multicon_t>) == 8, "C layout of st_multicon_t: offsetof oldinum")
    static_assert(typeinfo offsetof<inum>(type<st_multicon_t>) == 16, "C layout of st_multicon_t: offsetof inum")
    static_assert(typeinfo offsetof<on>(type<st_multicon_t>) == 24, "C layout of st_multicon_t: offsetof on")
    static_assert(typeinfo offsetof<p>(type<st_multicon_t>) == 32, "C layout of st_multicon_t: offsetof p")
    static_assert(typeinfo offsetof<data>(type<st_multicon_t>) == 40, "C layout of st_multicon_t: offsetof data")
    static_assert(typeinfo sizeof(type<st_binicon_t>) == 48, "C layout of st_binicon_t: sizeof")
    static_assert(typeinfo alignof(type<st_binicon_t>) == 8, "C layout of st_binicon_t: alignof")
    static_assert(typeinfo offsetof<x>(type<st_binicon_t>) == 0, "C layout of st_binicon_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<st_binicon_t>) == 4, "C layout of st_binicon_t: offsetof y")
    static_assert(typeinfo offsetof<oldval>(type<st_binicon_t>) == 8, "C layout of st_binicon_t: offsetof oldval")
    static_assert(typeinfo offsetof<val>(type<st_binicon_t>) == 16, "C layout of st_binicon_t: offsetof val")
    static_assert(typeinfo offsetof<on>(type<st_binicon_t>) == 24, "C layout of st_binicon_t: offsetof on")
    static_assert(typeinfo offsetof<p>(type<st_binicon_t>) == 32, "C layout of st_binicon_t: offsetof p")
    static_assert(typeinfo offsetof<data>(type<st_binicon_t>) == 40, "C layout of st_binicon_t: offsetof data")
}
