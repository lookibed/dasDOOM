[export, sideeffects]
def HUlib_init() {
    return
}
[export, sideeffects]
def HUlib_clearTextLine(var t : hu_textline_t?) {
    t.len = 0
    var c2da_fresh0 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(t)) + 20ul))
    unsafe(unsafe(reinterpret<int8?>(c2da_fresh0))[0]) = int8(0)
    t.needsupdate = 1
    return
}
[export, sideeffects]
def HUlib_initTextLine(var t_0 : hu_textline_t?; var x : int; var y : int; var f : patch_t??; var sc : int) {
    t_0.x = int(x)  // nolint:PERF020
    t_0.y = int(y)  // nolint:PERF020
    t_0.f = f
    t_0.sc = int(sc)  // nolint:PERF020
    HUlib_clearTextLine(t_0)
    return
}
[export, sideeffects]
def HUlib_addCharToTextLine(var t_1 : hu_textline_t?; var ch : int8) : uint {
    if (t_1.len == 80) {
        return 0u
    } else {
        var c2da_fresh1 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(t_1)) + 20ul))
        let c2da_postinc : int = t_1.len
        t_1.len = c2da_postinc + 1
        unsafe(unsafe(reinterpret<int8?>(c2da_fresh1))[c2da_postinc]) = int8(ch)  // nolint:PERF020
        var c2da_fresh2 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(t_1)) + 20ul))
        unsafe(unsafe(reinterpret<int8?>(c2da_fresh2))[t_1.len]) = int8(0)
        t_1.needsupdate = 4
        return 1u
    }
}
[export, sideeffects]
def HUlib_delCharFromTextLine(var t_2 : hu_textline_t?) : uint {
    if (t_2.len == 0) {
        return 0u
    } else {
        var c2da_fresh3 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(t_2)) + 20ul))
        let c2da_postinc_0 : int = t_2.len
        t_2.len = c2da_postinc_0 - 1
        unsafe(unsafe(reinterpret<int8?>(c2da_fresh3))[c2da_postinc_0 - 1]) = int8(0)
        t_2.needsupdate = 4
        return 1u
    }
}
[export, sideeffects]
def HUlib_drawTextLine(var l : hu_textline_t?; var drawcursor : uint) {
    var i : int
    var w : int
    var x_0 : int
    var c : uint8
    x_0 = l.x
    i = 0
    while (i < l.len) {
        var c2da_fresh4 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(l)) + 20ul))
        c = uint8(c2da_std_toupper(int(unsafe(unsafe(reinterpret<int8?>(c2da_fresh4))[i]))))
        if (int(c) != 32 && int(c) >= l.sc && int(c) <= 95) {
            w = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(l.f[int(c) - l.sc])))))[0]))
            if (x_0 + w > 320) {
                break
            }
            V_DrawPatchDirect(x_0, l.y, unsafe(reinterpret<patch_t?>(unsafe(l.f[int(c) - l.sc]))))
            x_0 += w
        } else {
            x_0 += 4
            if (x_0 >= 320) {
                break
            }
        }
        i++
    }
    if (drawcursor != 0x0 && x_0 + int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(l.f[95 - l.sc])))))[0])) <= 320) {
        V_DrawPatchDirect(x_0, l.y, unsafe(reinterpret<patch_t?>(unsafe(l.f[95 - l.sc]))))
    }
    return
}
[export, sideeffects]
def HUlib_eraseTextLine(var l_0 : hu_textline_t?) {
    var lh : int
    var y_0 : int
    var yoffset : int
    if (automapactive == 0 && viewwindowx != 0 && l_0.needsupdate != 0) {
        lh = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(l_0.f[0])))))[1])) + 1
        y_0 = l_0.y
        yoffset = y_0 * 320
        while (y_0 < l_0.y + lh) {
            if (y_0 < viewwindowy || y_0 >= viewwindowy + viewheight) {
                R_VideoErase(uint(yoffset), 320)
            } else {
                R_VideoErase(uint(yoffset), viewwindowx)
                R_VideoErase(uint(yoffset + viewwindowx + viewwidth), viewwindowx)
            }
            y_0++
            yoffset += 320
        }
    }
    if (l_0.needsupdate != 0) {
        let c2da_postinc_1 : int = l_0.needsupdate
        l_0.needsupdate = c2da_postinc_1 - 1
    }
    return
}
[export, sideeffects]
def HUlib_initSText(var s : hu_stext_t?; var x_1 : int; var y_1 : int; var h : int; var font : patch_t??; var startchar : int; var on : uint?) {
    s.h = int(h)  // nolint:PERF020
    s.on = on
    s.laston = 1u
    s.cl = 0
    for (i_0 in range(0, h)) {
        var c2da_fresh5 : hu_textline_t? = unsafe(reinterpret<hu_textline_t?>(unsafe(reinterpret<uint64>(s))))
        HUlib_initTextLine(unsafe(addr<hu_textline_t?>(unsafe(unsafe(reinterpret<hu_textline_t?>(c2da_fresh5))[i_0]))), x_1, y_1 - i_0 * (int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(font[0])))))[1])) + 1), font, startchar)
    }
    return
}
[export, sideeffects]
def HUlib_addLineToSText(var s_0 : hu_stext_t?) {
    var i_1 : int
    let c2da_postinc_2 : int = s_0.cl
    s_0.cl = c2da_postinc_2 + 1
    if (c2da_postinc_2 + 1 == s_0.h) {
        s_0.cl = 0
    }
    var c2da_fresh6 : hu_textline_t? = unsafe(reinterpret<hu_textline_t?>(unsafe(reinterpret<uint64>(s_0))))
    HUlib_clearTextLine(unsafe(addr<hu_textline_t?>(unsafe(unsafe(reinterpret<hu_textline_t?>(c2da_fresh6))[s_0.cl]))))
    i_1 = 0
    while (i_1 < s_0.h) {
        var c2da_fresh7 : hu_textline_t? = unsafe(reinterpret<hu_textline_t?>(unsafe(reinterpret<uint64>(s_0))))
        unsafe(unsafe(reinterpret<hu_textline_t?>(c2da_fresh7))[i_1]).needsupdate = 4
        i_1++
    }
    return
}
[export, sideeffects]
def HUlib_addMessageToSText(var s_1 : hu_stext_t?; var prefix : int8?; var msg : int8?) {
    HUlib_addLineToSText(s_1)
    if (prefix != null) {
        var c2da_prefix_addr : uint64 = unsafe(reinterpret<uint64>(prefix))
        while (*unsafe(reinterpret<int8?>(c2da_prefix_addr)) != 0) {
            var c2da_fresh8 : hu_textline_t? = unsafe(reinterpret<hu_textline_t?>(unsafe(reinterpret<uint64>(s_1))))
            HUlib_addCharToTextLine(unsafe(addr<hu_textline_t?>(unsafe(unsafe(reinterpret<hu_textline_t?>(c2da_fresh8))[s_1.cl]))), *unsafe(reinterpret<int8?>(c2da_prefix_addr)))
            c2da_prefix_addr++
        }
    }
    var c2da_msg_addr : uint64 = unsafe(reinterpret<uint64>(msg))
    while (*unsafe(reinterpret<int8?>(c2da_msg_addr)) != 0) {
        var c2da_fresh9 : hu_textline_t? = unsafe(reinterpret<hu_textline_t?>(unsafe(reinterpret<uint64>(s_1))))
        HUlib_addCharToTextLine(unsafe(addr<hu_textline_t?>(unsafe(unsafe(reinterpret<hu_textline_t?>(c2da_fresh9))[s_1.cl]))), *unsafe(reinterpret<int8?>(c2da_msg_addr)))
        c2da_msg_addr++
    }
    return
}
[export, sideeffects]
def HUlib_drawSText(var s_2 : hu_stext_t?) {
    var i_2 : int
    var idx : int
    var l_1 : hu_textline_t?
    if (*s_2.on == 0) {
        return
    }
    i_2 = 0
    while (i_2 < s_2.h) {
        idx = s_2.cl - i_2
        if (idx < 0) {
            idx += s_2.h
        }
        var c2da_fresh10 : hu_textline_t? = unsafe(reinterpret<hu_textline_t?>(unsafe(reinterpret<uint64>(s_2))))
        l_1 = unsafe(addr<hu_textline_t?>(unsafe(unsafe(reinterpret<hu_textline_t?>(c2da_fresh10))[idx])))
        HUlib_drawTextLine(l_1, 0u)
        i_2++
    }
    return
}
[export, sideeffects]
def HUlib_eraseSText(var s_3 : hu_stext_t?) {
    var i_3 : int = 0
    while (i_3 < s_3.h) {
        if (s_3.laston != 0x0 && *s_3.on == 0) {
            var c2da_fresh11 : hu_textline_t? = unsafe(reinterpret<hu_textline_t?>(unsafe(reinterpret<uint64>(s_3))))
            unsafe(unsafe(reinterpret<hu_textline_t?>(c2da_fresh11))[i_3]).needsupdate = 4
        }
        var c2da_fresh12 : hu_textline_t? = unsafe(reinterpret<hu_textline_t?>(unsafe(reinterpret<uint64>(s_3))))
        HUlib_eraseTextLine(unsafe(addr<hu_textline_t?>(unsafe(unsafe(reinterpret<hu_textline_t?>(c2da_fresh12))[i_3]))))
        i_3++
    }
    s_3.laston = uint(*s_3.on)  // nolint:PERF020
    return
}
[export, sideeffects]
def HUlib_initIText(var it : hu_itext_t?; var x_2 : int; var y_3 : int; var font_0 : patch_t??; var startchar_0 : int; var on_0 : uint?) {
    it.lm = 0
    it.on = on_0
    it.laston = 1u
    var c2da_fresh13 : hu_textline_t? = unsafe(reinterpret<hu_textline_t?>(unsafe(reinterpret<uint64>(it))))
    HUlib_initTextLine(unsafe(reinterpret<hu_textline_t?>(c2da_fresh13)), x_2, y_3, font_0, startchar_0)
    return
}
[export, sideeffects]
def HUlib_delCharFromIText(var it_0 : hu_itext_t?) {
    if (it_0.l.len != it_0.lm) {
        var c2da_fresh14 : hu_textline_t? = unsafe(reinterpret<hu_textline_t?>(unsafe(reinterpret<uint64>(it_0))))
        HUlib_delCharFromTextLine(unsafe(reinterpret<hu_textline_t?>(c2da_fresh14)))
    }
    return
}
[export, sideeffects]
def HUlib_eraseLineFromIText(var it_1 : hu_itext_t?) {
    while (it_1.lm != it_1.l.len) {
        var c2da_fresh15 : hu_textline_t? = unsafe(reinterpret<hu_textline_t?>(unsafe(reinterpret<uint64>(it_1))))
        HUlib_delCharFromTextLine(unsafe(reinterpret<hu_textline_t?>(c2da_fresh15)))
    }
    return
}
[export, sideeffects]
def HUlib_resetIText(var it_2 : hu_itext_t?) {
    it_2.lm = 0
    var c2da_fresh16 : hu_textline_t? = unsafe(reinterpret<hu_textline_t?>(unsafe(reinterpret<uint64>(it_2))))
    HUlib_clearTextLine(unsafe(reinterpret<hu_textline_t?>(c2da_fresh16)))
    return
}
[export, sideeffects]
def HUlib_addPrefixToIText(var it_3 : hu_itext_t?; var str : int8?) {
    var c2da_str_addr : uint64 = unsafe(reinterpret<uint64>(str))
    while (*unsafe(reinterpret<int8?>(c2da_str_addr)) != 0) {
        var c2da_fresh17 : hu_textline_t? = unsafe(reinterpret<hu_textline_t?>(unsafe(reinterpret<uint64>(it_3))))
        HUlib_addCharToTextLine(unsafe(reinterpret<hu_textline_t?>(c2da_fresh17)), *unsafe(reinterpret<int8?>(c2da_str_addr)))
        c2da_str_addr++
    }
    it_3.lm = int(it_3.l.len)  // nolint:PERF020
    return
}
[export, sideeffects]
def HUlib_keyInIText(var it_4 : hu_itext_t?; var ch_0 : uint8) : uint {
    ch_0 = uint8(c2da_std_toupper(int(ch_0)))
    if (int(ch_0) >= 32 && int(ch_0) <= 95) {
        var c2da_fresh18 : hu_textline_t? = unsafe(reinterpret<hu_textline_t?>(unsafe(reinterpret<uint64>(it_4))))
        HUlib_addCharToTextLine(unsafe(reinterpret<hu_textline_t?>(c2da_fresh18)), int8(ch_0))
    } elif (int(ch_0) == 127) {
        HUlib_delCharFromIText(it_4)
    } elif (int(ch_0) != 13) {
        return 0u
    }
    return 1u
}
[export, sideeffects]
def HUlib_drawIText(var it_5 : hu_itext_t?) {
    var l_2 : hu_textline_t?
    var c2da_fresh19 : hu_textline_t? = unsafe(reinterpret<hu_textline_t?>(unsafe(reinterpret<uint64>(it_5))))
    l_2 = c2da_fresh19
    if (*it_5.on == 0) {
        return
    }
    HUlib_drawTextLine(l_2, 1u)
    return
}
[export, sideeffects]
def HUlib_eraseIText(var it_6 : hu_itext_t?) {
    if (it_6.laston != 0x0 && *it_6.on == 0) {
        it_6.l.needsupdate = 4
    }
    var c2da_fresh20 : hu_textline_t? = unsafe(reinterpret<hu_textline_t?>(unsafe(reinterpret<uint64>(it_6))))
    HUlib_eraseTextLine(unsafe(reinterpret<hu_textline_t?>(c2da_fresh20)))
    it_6.laston = uint(*it_6.on)  // nolint:PERF020
    return
}
[sideeffects]
def private c2da_layout_proofs_5() {
    static_assert(typeinfo sizeof(type<hu_textline_t>) == 112, "C layout of hu_textline_t: sizeof")
    static_assert(typeinfo alignof(type<hu_textline_t>) == 8, "C layout of hu_textline_t: alignof")
    static_assert(typeinfo offsetof<x>(type<hu_textline_t>) == 0, "C layout of hu_textline_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<hu_textline_t>) == 4, "C layout of hu_textline_t: offsetof y")
    static_assert(typeinfo offsetof<f>(type<hu_textline_t>) == 8, "C layout of hu_textline_t: offsetof f")
    static_assert(typeinfo offsetof<sc>(type<hu_textline_t>) == 16, "C layout of hu_textline_t: offsetof sc")
    static_assert(typeinfo offsetof<l>(type<hu_textline_t>) == 20, "C layout of hu_textline_t: offsetof l")
    static_assert(typeinfo offsetof<len>(type<hu_textline_t>) == 104, "C layout of hu_textline_t: offsetof len")
    static_assert(typeinfo offsetof<needsupdate>(type<hu_textline_t>) == 108, "C layout of hu_textline_t: offsetof needsupdate")
    static_assert(typeinfo sizeof(type<hu_stext_t>) == 472, "C layout of hu_stext_t: sizeof")
    static_assert(typeinfo alignof(type<hu_stext_t>) == 8, "C layout of hu_stext_t: alignof")
    static_assert(typeinfo offsetof<l>(type<hu_stext_t>) == 0, "C layout of hu_stext_t: offsetof l")
    static_assert(typeinfo offsetof<h>(type<hu_stext_t>) == 448, "C layout of hu_stext_t: offsetof h")
    static_assert(typeinfo offsetof<cl>(type<hu_stext_t>) == 452, "C layout of hu_stext_t: offsetof cl")
    static_assert(typeinfo offsetof<on>(type<hu_stext_t>) == 456, "C layout of hu_stext_t: offsetof on")
    static_assert(typeinfo offsetof<laston>(type<hu_stext_t>) == 464, "C layout of hu_stext_t: offsetof laston")
    static_assert(typeinfo sizeof(type<hu_itext_t>) == 136, "C layout of hu_itext_t: sizeof")
    static_assert(typeinfo alignof(type<hu_itext_t>) == 8, "C layout of hu_itext_t: alignof")
    static_assert(typeinfo offsetof<l>(type<hu_itext_t>) == 0, "C layout of hu_itext_t: offsetof l")
    static_assert(typeinfo offsetof<lm>(type<hu_itext_t>) == 112, "C layout of hu_itext_t: offsetof lm")
    static_assert(typeinfo offsetof<on>(type<hu_itext_t>) == 120, "C layout of hu_itext_t: offsetof on")
    static_assert(typeinfo offsetof<laston>(type<hu_itext_t>) == 128, "C layout of hu_itext_t: offsetof laston")
}
