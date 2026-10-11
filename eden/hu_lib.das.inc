[export, sideeffects]
def HUlib_init() {
    return
}
[export, sideeffects]
def HUlib_clearTextLine(var t : int) {
    let c2da_fresh0 : int = 0
    let c2da_fresh1 : uint = uint(c2da_fresh0)
    c2da_mem[t + 104] = uint8(c2da_fresh1)
    c2da_mem[t + 105] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[t + 106] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[t + 107] = uint8(c2da_fresh1 >> 0x18)
    let c2da_fresh2 : int8 = int8(0)
    c2da_mem[t + 20 + 0] = uint8(c2da_fresh2)
    let c2da_fresh3 : int = 1
    let c2da_fresh4 : uint = uint(c2da_fresh3)
    c2da_mem[t + 108] = uint8(c2da_fresh4)
    c2da_mem[t + 109] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[t + 110] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[t + 111] = uint8(c2da_fresh4 >> 0x18)
    return
}
[export, sideeffects]
def HUlib_initTextLine(var t_0 : int; var x : int; var y : int; var f : int; var sc : int) {
    let c2da_fresh5 : uint = uint(x)
    c2da_mem[t_0] = uint8(c2da_fresh5)
    c2da_mem[t_0 + 1] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[t_0 + 2] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[t_0 + 3] = uint8(c2da_fresh5 >> 0x18)
    let c2da_fresh6 : uint = uint(y)
    c2da_mem[t_0 + 4] = uint8(c2da_fresh6)
    c2da_mem[t_0 + 5] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[t_0 + 6] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[t_0 + 7] = uint8(c2da_fresh6 >> 0x18)
    let c2da_fresh7 : uint = uint(f)
    c2da_mem[t_0 + 8] = uint8(c2da_fresh7)
    c2da_mem[t_0 + 9] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[t_0 + 10] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[t_0 + 11] = uint8(c2da_fresh7 >> 0x18)
    c2da_mem[t_0 + 12] = 0u8
    c2da_mem[t_0 + 13] = 0u8
    c2da_mem[t_0 + 14] = 0u8
    c2da_mem[t_0 + 15] = 0u8
    let c2da_fresh8 : uint = uint(sc)
    c2da_mem[t_0 + 16] = uint8(c2da_fresh8)
    c2da_mem[t_0 + 17] = uint8(c2da_fresh8 >> 0x8)
    c2da_mem[t_0 + 18] = uint8(c2da_fresh8 >> 0x10)
    c2da_mem[t_0 + 19] = uint8(c2da_fresh8 >> 0x18)
    HUlib_clearTextLine(t_0)
    return
}
[export, sideeffects]
def HUlib_addCharToTextLine(var t_1 : int; var ch : int8) : uint {
    if (int(uint(c2da_mem[t_1 + 104]) | uint(c2da_mem[t_1 + 105]) << 0x8 | uint(c2da_mem[t_1 + 106]) << 0x10 | uint(c2da_mem[t_1 + 107]) << 0x18) == 80) {
        return 0u
    } else {
        let c2da_fresh9 : int = int(uint(c2da_mem[t_1 + 104]) | uint(c2da_mem[t_1 + 105]) << 0x8 | uint(c2da_mem[t_1 + 106]) << 0x10 | uint(c2da_mem[t_1 + 107]) << 0x18)
        let c2da_fresh10 : int = c2da_fresh9 + 1
        let c2da_fresh11 : uint = uint(c2da_fresh10)
        c2da_mem[t_1 + 104] = uint8(c2da_fresh11)
        c2da_mem[t_1 + 105] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[t_1 + 106] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[t_1 + 107] = uint8(c2da_fresh11 >> 0x18)
        c2da_mem[t_1 + 20 + c2da_fresh9] = uint8(ch)
        let c2da_fresh12 : int = t_1 + 20 + int(uint(c2da_mem[t_1 + 104]) | uint(c2da_mem[t_1 + 105]) << 0x8 | uint(c2da_mem[t_1 + 106]) << 0x10 | uint(c2da_mem[t_1 + 107]) << 0x18)
        let c2da_fresh13 : int8 = int8(0)
        c2da_mem[c2da_fresh12] = uint8(c2da_fresh13)
        let c2da_fresh14 : int = 4
        let c2da_fresh15 : uint = uint(c2da_fresh14)
        c2da_mem[t_1 + 108] = uint8(c2da_fresh15)
        c2da_mem[t_1 + 109] = uint8(c2da_fresh15 >> 0x8)
        c2da_mem[t_1 + 110] = uint8(c2da_fresh15 >> 0x10)
        c2da_mem[t_1 + 111] = uint8(c2da_fresh15 >> 0x18)
        return 1u
    }
}
[export, sideeffects]
def HUlib_delCharFromTextLine(var t_2 : int) : uint {
    if (int(uint(c2da_mem[t_2 + 104]) | uint(c2da_mem[t_2 + 105]) << 0x8 | uint(c2da_mem[t_2 + 106]) << 0x10 | uint(c2da_mem[t_2 + 107]) << 0x18) == 0) {
        return 0u
    } else {
        let c2da_fresh16 : int = int(uint(c2da_mem[t_2 + 104]) | uint(c2da_mem[t_2 + 105]) << 0x8 | uint(c2da_mem[t_2 + 106]) << 0x10 | uint(c2da_mem[t_2 + 107]) << 0x18)
        let c2da_fresh17 : int = c2da_fresh16 - 1
        let c2da_fresh18 : uint = uint(c2da_fresh17)
        c2da_mem[t_2 + 104] = uint8(c2da_fresh18)
        c2da_mem[t_2 + 105] = uint8(c2da_fresh18 >> 0x8)
        c2da_mem[t_2 + 106] = uint8(c2da_fresh18 >> 0x10)
        c2da_mem[t_2 + 107] = uint8(c2da_fresh18 >> 0x18)
        let c2da_fresh19 : int8 = int8(0)
        c2da_mem[t_2 + 20 + c2da_fresh17] = uint8(c2da_fresh19)
        let c2da_fresh20 : int = 4
        let c2da_fresh21 : uint = uint(c2da_fresh20)
        c2da_mem[t_2 + 108] = uint8(c2da_fresh21)
        c2da_mem[t_2 + 109] = uint8(c2da_fresh21 >> 0x8)
        c2da_mem[t_2 + 110] = uint8(c2da_fresh21 >> 0x10)
        c2da_mem[t_2 + 111] = uint8(c2da_fresh21 >> 0x18)
        return 1u
    }
}
[export, sideeffects]
def HUlib_drawTextLine(var l : int; var drawcursor : uint) {
    var i : int
    var w : int
    var x_0 : int
    var c : uint8
    x_0 = int(uint(c2da_mem[l]) | uint(c2da_mem[l + 1]) << 0x8 | uint(c2da_mem[l + 2]) << 0x10 | uint(c2da_mem[l + 3]) << 0x18)
    i = 0
    while (i < int(uint(c2da_mem[l + 104]) | uint(c2da_mem[l + 105]) << 0x8 | uint(c2da_mem[l + 106]) << 0x10 | uint(c2da_mem[l + 107]) << 0x18)) {
        c = uint8(c2da_std_toupper(int(int8(c2da_mem[l + 20 + i]))))
        if (int(c) != 32 && int(c) >= int(uint(c2da_mem[l + 16]) | uint(c2da_mem[l + 17]) << 0x8 | uint(c2da_mem[l + 18]) << 0x10 | uint(c2da_mem[l + 19]) << 0x18) && int(c) <= 95) {
            let c2da_fresh22 : int = int(uint(c2da_mem[l + 8]) | uint(c2da_mem[l + 9]) << 0x8 | uint(c2da_mem[l + 10]) << 0x10 | uint(c2da_mem[l + 11]) << 0x18) + (int(c) - int(uint(c2da_mem[l + 16]) | uint(c2da_mem[l + 17]) << 0x8 | uint(c2da_mem[l + 18]) << 0x10 | uint(c2da_mem[l + 19]) << 0x18)) * 8
            let c2da_fresh23 : int = int(uint(c2da_mem[c2da_fresh22]) | uint(c2da_mem[c2da_fresh22 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh22 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh22 + 3]) << 0x18)
            w = int(int16(uint(c2da_mem[c2da_fresh23]) | uint(c2da_mem[c2da_fresh23 + 1]) << 0x8))
            if (x_0 + w > 320) {
                break
            }
            let c2da_fresh24 : int = int(uint(c2da_mem[l + 8]) | uint(c2da_mem[l + 9]) << 0x8 | uint(c2da_mem[l + 10]) << 0x10 | uint(c2da_mem[l + 11]) << 0x18) + (int(c) - int(uint(c2da_mem[l + 16]) | uint(c2da_mem[l + 17]) << 0x8 | uint(c2da_mem[l + 18]) << 0x10 | uint(c2da_mem[l + 19]) << 0x18)) * 8
            V_DrawPatchDirect(x_0, int(uint(c2da_mem[l + 4]) | uint(c2da_mem[l + 5]) << 0x8 | uint(c2da_mem[l + 6]) << 0x10 | uint(c2da_mem[l + 7]) << 0x18), int(uint(c2da_mem[c2da_fresh24]) | uint(c2da_mem[c2da_fresh24 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh24 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh24 + 3]) << 0x18))
            x_0 += w
        } else {
            x_0 += 4
            if (x_0 >= 320) {
                break
            }
        }
        i++
    }
    var c2da_fresh27 : int = 0
    if (drawcursor != 0x0) {
        let c2da_fresh25 : int = int(uint(c2da_mem[l + 8]) | uint(c2da_mem[l + 9]) << 0x8 | uint(c2da_mem[l + 10]) << 0x10 | uint(c2da_mem[l + 11]) << 0x18) + (95 - int(uint(c2da_mem[l + 16]) | uint(c2da_mem[l + 17]) << 0x8 | uint(c2da_mem[l + 18]) << 0x10 | uint(c2da_mem[l + 19]) << 0x18)) * 8
        let c2da_fresh26 : int = int(uint(c2da_mem[c2da_fresh25]) | uint(c2da_mem[c2da_fresh25 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh25 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh25 + 3]) << 0x18)
        if (x_0 + int(int16(uint(c2da_mem[c2da_fresh26]) | uint(c2da_mem[c2da_fresh26 + 1]) << 0x8)) <= 320) {
            c2da_fresh27 = 1
        }
    }
    if (c2da_fresh27 != 0) {
        let c2da_fresh28 : int = int(uint(c2da_mem[l + 8]) | uint(c2da_mem[l + 9]) << 0x8 | uint(c2da_mem[l + 10]) << 0x10 | uint(c2da_mem[l + 11]) << 0x18) + (95 - int(uint(c2da_mem[l + 16]) | uint(c2da_mem[l + 17]) << 0x8 | uint(c2da_mem[l + 18]) << 0x10 | uint(c2da_mem[l + 19]) << 0x18)) * 8
        V_DrawPatchDirect(x_0, int(uint(c2da_mem[l + 4]) | uint(c2da_mem[l + 5]) << 0x8 | uint(c2da_mem[l + 6]) << 0x10 | uint(c2da_mem[l + 7]) << 0x18), int(uint(c2da_mem[c2da_fresh28]) | uint(c2da_mem[c2da_fresh28 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh28 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh28 + 3]) << 0x18))
    }
    return
}
[export, sideeffects]
def HUlib_eraseTextLine(var l_0 : int) {
    var lh : int
    var y_0 : int
    var yoffset : int
    if (automapactive == 0 && viewwindowx != 0 && int(uint(c2da_mem[l_0 + 108]) | uint(c2da_mem[l_0 + 109]) << 0x8 | uint(c2da_mem[l_0 + 110]) << 0x10 | uint(c2da_mem[l_0 + 111]) << 0x18) != 0) {
        let c2da_fresh29 : int = int(uint(c2da_mem[l_0 + 8]) | uint(c2da_mem[l_0 + 9]) << 0x8 | uint(c2da_mem[l_0 + 10]) << 0x10 | uint(c2da_mem[l_0 + 11]) << 0x18) + 0 * 8
        let c2da_fresh30 : int = int(uint(c2da_mem[c2da_fresh29]) | uint(c2da_mem[c2da_fresh29 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh29 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh29 + 3]) << 0x18) + 2
        lh = int(int16(uint(c2da_mem[c2da_fresh30]) | uint(c2da_mem[c2da_fresh30 + 1]) << 0x8)) + 1
        y_0 = int(uint(c2da_mem[l_0 + 4]) | uint(c2da_mem[l_0 + 5]) << 0x8 | uint(c2da_mem[l_0 + 6]) << 0x10 | uint(c2da_mem[l_0 + 7]) << 0x18)
        yoffset = y_0 * 320
        while (y_0 < int(uint(c2da_mem[l_0 + 4]) | uint(c2da_mem[l_0 + 5]) << 0x8 | uint(c2da_mem[l_0 + 6]) << 0x10 | uint(c2da_mem[l_0 + 7]) << 0x18) + lh) {
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
    if (int(uint(c2da_mem[l_0 + 108]) | uint(c2da_mem[l_0 + 109]) << 0x8 | uint(c2da_mem[l_0 + 110]) << 0x10 | uint(c2da_mem[l_0 + 111]) << 0x18) != 0) {
        let c2da_fresh31 : int = int(uint(c2da_mem[l_0 + 108]) | uint(c2da_mem[l_0 + 109]) << 0x8 | uint(c2da_mem[l_0 + 110]) << 0x10 | uint(c2da_mem[l_0 + 111]) << 0x18)
        let c2da_fresh32 : int = c2da_fresh31 - 1
        let c2da_fresh33 : uint = uint(c2da_fresh32)
        c2da_mem[l_0 + 108] = uint8(c2da_fresh33)
        c2da_mem[l_0 + 109] = uint8(c2da_fresh33 >> 0x8)
        c2da_mem[l_0 + 110] = uint8(c2da_fresh33 >> 0x10)
        c2da_mem[l_0 + 111] = uint8(c2da_fresh33 >> 0x18)
    }
    return
}
[export, sideeffects]
def HUlib_initSText(var s : int; var x_1 : int; var y_1 : int; var h : int; var font : int; var startchar : int; var on : int) {
    let c2da_fresh34 : uint = uint(h)
    c2da_mem[s + 448] = uint8(c2da_fresh34)
    c2da_mem[s + 449] = uint8(c2da_fresh34 >> 0x8)
    c2da_mem[s + 450] = uint8(c2da_fresh34 >> 0x10)
    c2da_mem[s + 451] = uint8(c2da_fresh34 >> 0x18)
    let c2da_fresh35 : uint = uint(on)
    c2da_mem[s + 456] = uint8(c2da_fresh35)
    c2da_mem[s + 457] = uint8(c2da_fresh35 >> 0x8)
    c2da_mem[s + 458] = uint8(c2da_fresh35 >> 0x10)
    c2da_mem[s + 459] = uint8(c2da_fresh35 >> 0x18)
    c2da_mem[s + 460] = 0u8
    c2da_mem[s + 461] = 0u8
    c2da_mem[s + 462] = 0u8
    c2da_mem[s + 463] = 0u8
    let c2da_fresh36 : uint = 1u
    let c2da_fresh37 : uint = c2da_fresh36
    c2da_mem[s + 464] = uint8(c2da_fresh37)
    c2da_mem[s + 465] = uint8(c2da_fresh37 >> 0x8)
    c2da_mem[s + 466] = uint8(c2da_fresh37 >> 0x10)
    c2da_mem[s + 467] = uint8(c2da_fresh37 >> 0x18)
    let c2da_fresh38 : int = 0
    let c2da_fresh39 : uint = uint(c2da_fresh38)
    c2da_mem[s + 452] = uint8(c2da_fresh39)
    c2da_mem[s + 453] = uint8(c2da_fresh39 >> 0x8)
    c2da_mem[s + 454] = uint8(c2da_fresh39 >> 0x10)
    c2da_mem[s + 455] = uint8(c2da_fresh39 >> 0x18)
    for (i_0 in range(0, h)) {
        let c2da_fresh40 : int = int(uint(c2da_mem[font + 0 * 8]) | uint(c2da_mem[font + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[font + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[font + 0 * 8 + 3]) << 0x18) + 2
        HUlib_initTextLine(s + i_0 * 112, x_1, y_1 - i_0 * (int(int16(uint(c2da_mem[c2da_fresh40]) | uint(c2da_mem[c2da_fresh40 + 1]) << 0x8)) + 1), font, startchar)
    }
    return
}
[export, sideeffects]
def HUlib_addLineToSText(var s_0 : int) {
    var i_1 : int
    let c2da_fresh41 : int = int(uint(c2da_mem[s_0 + 452]) | uint(c2da_mem[s_0 + 453]) << 0x8 | uint(c2da_mem[s_0 + 454]) << 0x10 | uint(c2da_mem[s_0 + 455]) << 0x18)
    let c2da_fresh42 : int = c2da_fresh41 + 1
    let c2da_fresh43 : uint = uint(c2da_fresh42)
    c2da_mem[s_0 + 452] = uint8(c2da_fresh43)
    c2da_mem[s_0 + 453] = uint8(c2da_fresh43 >> 0x8)
    c2da_mem[s_0 + 454] = uint8(c2da_fresh43 >> 0x10)
    c2da_mem[s_0 + 455] = uint8(c2da_fresh43 >> 0x18)
    if (c2da_fresh42 == int(uint(c2da_mem[s_0 + 448]) | uint(c2da_mem[s_0 + 449]) << 0x8 | uint(c2da_mem[s_0 + 450]) << 0x10 | uint(c2da_mem[s_0 + 451]) << 0x18)) {
        let c2da_fresh44 : int = 0
        let c2da_fresh45 : uint = uint(c2da_fresh44)
        c2da_mem[s_0 + 452] = uint8(c2da_fresh45)
        c2da_mem[s_0 + 453] = uint8(c2da_fresh45 >> 0x8)
        c2da_mem[s_0 + 454] = uint8(c2da_fresh45 >> 0x10)
        c2da_mem[s_0 + 455] = uint8(c2da_fresh45 >> 0x18)
    }
    HUlib_clearTextLine(s_0 + int(uint(c2da_mem[s_0 + 452]) | uint(c2da_mem[s_0 + 453]) << 0x8 | uint(c2da_mem[s_0 + 454]) << 0x10 | uint(c2da_mem[s_0 + 455]) << 0x18) * 112)
    i_1 = 0
    while (i_1 < int(uint(c2da_mem[s_0 + 448]) | uint(c2da_mem[s_0 + 449]) << 0x8 | uint(c2da_mem[s_0 + 450]) << 0x10 | uint(c2da_mem[s_0 + 451]) << 0x18)) {
        let c2da_fresh46 : int = 4
        let c2da_fresh47 : uint = uint(c2da_fresh46)
        c2da_mem[s_0 + i_1 * 112 + 108] = uint8(c2da_fresh47)
        c2da_mem[s_0 + i_1 * 112 + 109] = uint8(c2da_fresh47 >> 0x8)
        c2da_mem[s_0 + i_1 * 112 + 110] = uint8(c2da_fresh47 >> 0x10)
        c2da_mem[s_0 + i_1 * 112 + 111] = uint8(c2da_fresh47 >> 0x18)
        i_1++
    }
    return
}
[export, sideeffects]
def HUlib_addMessageToSText(var s_1 : int; var prefix : int; var msg : int) {
    HUlib_addLineToSText(s_1)
    if (prefix != 0) {
        while (int8(c2da_mem[prefix]) != 0) {
            let c2da_fresh48 : int = prefix
            prefix++
            HUlib_addCharToTextLine(s_1 + int(uint(c2da_mem[s_1 + 452]) | uint(c2da_mem[s_1 + 453]) << 0x8 | uint(c2da_mem[s_1 + 454]) << 0x10 | uint(c2da_mem[s_1 + 455]) << 0x18) * 112, int8(c2da_mem[c2da_fresh48]))
        }
    }
    while (int8(c2da_mem[msg]) != 0) {
        let c2da_fresh49 : int = msg
        msg++
        HUlib_addCharToTextLine(s_1 + int(uint(c2da_mem[s_1 + 452]) | uint(c2da_mem[s_1 + 453]) << 0x8 | uint(c2da_mem[s_1 + 454]) << 0x10 | uint(c2da_mem[s_1 + 455]) << 0x18) * 112, int8(c2da_mem[c2da_fresh49]))
    }
    return
}
[export, sideeffects]
def HUlib_drawSText(var s_2 : int) {
    var i_2 : int
    var idx : int
    var l_1 : int
    let c2da_fresh50 : int = int(uint(c2da_mem[s_2 + 456]) | uint(c2da_mem[s_2 + 457]) << 0x8 | uint(c2da_mem[s_2 + 458]) << 0x10 | uint(c2da_mem[s_2 + 459]) << 0x18)
    if ((uint(c2da_mem[c2da_fresh50]) | uint(c2da_mem[c2da_fresh50 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh50 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh50 + 3]) << 0x18) == 0) {
        return
    }
    i_2 = 0
    while (i_2 < int(uint(c2da_mem[s_2 + 448]) | uint(c2da_mem[s_2 + 449]) << 0x8 | uint(c2da_mem[s_2 + 450]) << 0x10 | uint(c2da_mem[s_2 + 451]) << 0x18)) {
        idx = int(uint(c2da_mem[s_2 + 452]) | uint(c2da_mem[s_2 + 453]) << 0x8 | uint(c2da_mem[s_2 + 454]) << 0x10 | uint(c2da_mem[s_2 + 455]) << 0x18) - i_2
        if (idx < 0) {
            idx += int(uint(c2da_mem[s_2 + 448]) | uint(c2da_mem[s_2 + 449]) << 0x8 | uint(c2da_mem[s_2 + 450]) << 0x10 | uint(c2da_mem[s_2 + 451]) << 0x18)
        }
        l_1 = s_2 + idx * 112
        HUlib_drawTextLine(l_1, 0u)
        i_2++
    }
    return
}
[export, sideeffects]
def HUlib_eraseSText(var s_3 : int) {
    var i_3 : int = 0
    while (i_3 < int(uint(c2da_mem[s_3 + 448]) | uint(c2da_mem[s_3 + 449]) << 0x8 | uint(c2da_mem[s_3 + 450]) << 0x10 | uint(c2da_mem[s_3 + 451]) << 0x18)) {
        var c2da_fresh52 : int = 0
        if ((uint(c2da_mem[s_3 + 464]) | uint(c2da_mem[s_3 + 465]) << 0x8 | uint(c2da_mem[s_3 + 466]) << 0x10 | uint(c2da_mem[s_3 + 467]) << 0x18) != 0x0) {
            let c2da_fresh51 : int = int(uint(c2da_mem[s_3 + 456]) | uint(c2da_mem[s_3 + 457]) << 0x8 | uint(c2da_mem[s_3 + 458]) << 0x10 | uint(c2da_mem[s_3 + 459]) << 0x18)
            if ((uint(c2da_mem[c2da_fresh51]) | uint(c2da_mem[c2da_fresh51 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh51 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh51 + 3]) << 0x18) == 0) {
                c2da_fresh52 = 1
            }
        }
        if (c2da_fresh52 != 0) {
            let c2da_fresh53 : int = 4
            let c2da_fresh54 : uint = uint(c2da_fresh53)
            c2da_mem[s_3 + i_3 * 112 + 108] = uint8(c2da_fresh54)
            c2da_mem[s_3 + i_3 * 112 + 109] = uint8(c2da_fresh54 >> 0x8)
            c2da_mem[s_3 + i_3 * 112 + 110] = uint8(c2da_fresh54 >> 0x10)
            c2da_mem[s_3 + i_3 * 112 + 111] = uint8(c2da_fresh54 >> 0x18)
        }
        HUlib_eraseTextLine(s_3 + i_3 * 112)
        i_3++
    }
    let c2da_fresh55 : int = int(uint(c2da_mem[s_3 + 456]) | uint(c2da_mem[s_3 + 457]) << 0x8 | uint(c2da_mem[s_3 + 458]) << 0x10 | uint(c2da_mem[s_3 + 459]) << 0x18)
    let c2da_fresh56 : uint = uint(c2da_mem[c2da_fresh55]) | uint(c2da_mem[c2da_fresh55 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh55 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh55 + 3]) << 0x18
    let c2da_fresh57 : uint = c2da_fresh56
    c2da_mem[s_3 + 464] = uint8(c2da_fresh57)
    c2da_mem[s_3 + 465] = uint8(c2da_fresh57 >> 0x8)
    c2da_mem[s_3 + 466] = uint8(c2da_fresh57 >> 0x10)
    c2da_mem[s_3 + 467] = uint8(c2da_fresh57 >> 0x18)
    return
}
[export, sideeffects]
def HUlib_initIText(var it : int; var x_2 : int; var y_3 : int; var font_0 : int; var startchar_0 : int; var on_0 : int) {
    let c2da_fresh58 : int = 0
    let c2da_fresh59 : uint = uint(c2da_fresh58)
    c2da_mem[it + 112] = uint8(c2da_fresh59)
    c2da_mem[it + 113] = uint8(c2da_fresh59 >> 0x8)
    c2da_mem[it + 114] = uint8(c2da_fresh59 >> 0x10)
    c2da_mem[it + 115] = uint8(c2da_fresh59 >> 0x18)
    let c2da_fresh60 : uint = uint(on_0)
    c2da_mem[it + 120] = uint8(c2da_fresh60)
    c2da_mem[it + 121] = uint8(c2da_fresh60 >> 0x8)
    c2da_mem[it + 122] = uint8(c2da_fresh60 >> 0x10)
    c2da_mem[it + 123] = uint8(c2da_fresh60 >> 0x18)
    c2da_mem[it + 124] = 0u8
    c2da_mem[it + 125] = 0u8
    c2da_mem[it + 126] = 0u8
    c2da_mem[it + 127] = 0u8
    let c2da_fresh61 : uint = 1u
    let c2da_fresh62 : uint = c2da_fresh61
    c2da_mem[it + 128] = uint8(c2da_fresh62)
    c2da_mem[it + 129] = uint8(c2da_fresh62 >> 0x8)
    c2da_mem[it + 130] = uint8(c2da_fresh62 >> 0x10)
    c2da_mem[it + 131] = uint8(c2da_fresh62 >> 0x18)
    HUlib_initTextLine(it, x_2, y_3, font_0, startchar_0)
    return
}
[export, sideeffects]
def HUlib_delCharFromIText(var it_0 : int) {
    if (int(uint(c2da_mem[it_0 + 104]) | uint(c2da_mem[it_0 + 105]) << 0x8 | uint(c2da_mem[it_0 + 106]) << 0x10 | uint(c2da_mem[it_0 + 107]) << 0x18) != int(uint(c2da_mem[it_0 + 112]) | uint(c2da_mem[it_0 + 113]) << 0x8 | uint(c2da_mem[it_0 + 114]) << 0x10 | uint(c2da_mem[it_0 + 115]) << 0x18)) {
        HUlib_delCharFromTextLine(it_0)
    }
    return
}
[export, sideeffects]
def HUlib_eraseLineFromIText(var it_1 : int) {
    while (int(uint(c2da_mem[it_1 + 112]) | uint(c2da_mem[it_1 + 113]) << 0x8 | uint(c2da_mem[it_1 + 114]) << 0x10 | uint(c2da_mem[it_1 + 115]) << 0x18) != int(uint(c2da_mem[it_1 + 104]) | uint(c2da_mem[it_1 + 105]) << 0x8 | uint(c2da_mem[it_1 + 106]) << 0x10 | uint(c2da_mem[it_1 + 107]) << 0x18)) {
        HUlib_delCharFromTextLine(it_1)
    }
    return
}
[export, sideeffects]
def HUlib_resetIText(var it_2 : int) {
    let c2da_fresh63 : int = 0
    let c2da_fresh64 : uint = uint(c2da_fresh63)
    c2da_mem[it_2 + 112] = uint8(c2da_fresh64)
    c2da_mem[it_2 + 113] = uint8(c2da_fresh64 >> 0x8)
    c2da_mem[it_2 + 114] = uint8(c2da_fresh64 >> 0x10)
    c2da_mem[it_2 + 115] = uint8(c2da_fresh64 >> 0x18)
    HUlib_clearTextLine(it_2)
    return
}
[export, sideeffects]
def HUlib_addPrefixToIText(var it_3 : int; var str : int) {
    while (int8(c2da_mem[str]) != 0) {
        let c2da_fresh65 : int = str
        str++
        HUlib_addCharToTextLine(it_3, int8(c2da_mem[c2da_fresh65]))
    }
    let c2da_fresh66 : int = int(uint(c2da_mem[it_3 + 104]) | uint(c2da_mem[it_3 + 105]) << 0x8 | uint(c2da_mem[it_3 + 106]) << 0x10 | uint(c2da_mem[it_3 + 107]) << 0x18)
    let c2da_fresh67 : uint = uint(c2da_fresh66)
    c2da_mem[it_3 + 112] = uint8(c2da_fresh67)
    c2da_mem[it_3 + 113] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[it_3 + 114] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[it_3 + 115] = uint8(c2da_fresh67 >> 0x18)
    return
}
[export, sideeffects]
def HUlib_keyInIText(var it_4 : int; var ch_0 : uint8) : uint {
    ch_0 = uint8(c2da_std_toupper(int(ch_0)))
    if (int(ch_0) >= 32 && int(ch_0) <= 95) {
        HUlib_addCharToTextLine(it_4, int8(ch_0))
    } elif (int(ch_0) == 127) {
        HUlib_delCharFromIText(it_4)
    } elif (int(ch_0) != 13) {
        return 0u
    }
    return 1u
}
[export, sideeffects]
def HUlib_drawIText(var it_5 : int) {
    var l_2 : int = it_5
    let c2da_fresh68 : int = int(uint(c2da_mem[it_5 + 120]) | uint(c2da_mem[it_5 + 121]) << 0x8 | uint(c2da_mem[it_5 + 122]) << 0x10 | uint(c2da_mem[it_5 + 123]) << 0x18)
    if ((uint(c2da_mem[c2da_fresh68]) | uint(c2da_mem[c2da_fresh68 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh68 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh68 + 3]) << 0x18) == 0) {
        return
    }
    HUlib_drawTextLine(l_2, 1u)
    return
}
[export, sideeffects]
def HUlib_eraseIText(var it_6 : int) {
    var c2da_fresh70 : int = 0
    if ((uint(c2da_mem[it_6 + 128]) | uint(c2da_mem[it_6 + 129]) << 0x8 | uint(c2da_mem[it_6 + 130]) << 0x10 | uint(c2da_mem[it_6 + 131]) << 0x18) != 0x0) {
        let c2da_fresh69 : int = int(uint(c2da_mem[it_6 + 120]) | uint(c2da_mem[it_6 + 121]) << 0x8 | uint(c2da_mem[it_6 + 122]) << 0x10 | uint(c2da_mem[it_6 + 123]) << 0x18)
        if ((uint(c2da_mem[c2da_fresh69]) | uint(c2da_mem[c2da_fresh69 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh69 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh69 + 3]) << 0x18) == 0) {
            c2da_fresh70 = 1
        }
    }
    if (c2da_fresh70 != 0) {
        let c2da_fresh71 : int = 4
        let c2da_fresh72 : uint = uint(c2da_fresh71)
        c2da_mem[it_6 + 108] = uint8(c2da_fresh72)
        c2da_mem[it_6 + 109] = uint8(c2da_fresh72 >> 0x8)
        c2da_mem[it_6 + 110] = uint8(c2da_fresh72 >> 0x10)
        c2da_mem[it_6 + 111] = uint8(c2da_fresh72 >> 0x18)
    }
    HUlib_eraseTextLine(it_6)
    let c2da_fresh73 : int = int(uint(c2da_mem[it_6 + 120]) | uint(c2da_mem[it_6 + 121]) << 0x8 | uint(c2da_mem[it_6 + 122]) << 0x10 | uint(c2da_mem[it_6 + 123]) << 0x18)
    let c2da_fresh74 : uint = uint(c2da_mem[c2da_fresh73]) | uint(c2da_mem[c2da_fresh73 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh73 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh73 + 3]) << 0x18
    let c2da_fresh75 : uint = c2da_fresh74
    c2da_mem[it_6 + 128] = uint8(c2da_fresh75)
    c2da_mem[it_6 + 129] = uint8(c2da_fresh75 >> 0x8)
    c2da_mem[it_6 + 130] = uint8(c2da_fresh75 >> 0x10)
    c2da_mem[it_6 + 131] = uint8(c2da_fresh75 >> 0x18)
    return
}
