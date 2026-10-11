[export, sideeffects]
def STlib_init() {
    sttminus = W_CacheLumpName(371264, 1)
    return
}
var sttminus : int = default<int>

[export, sideeffects]
def STlib_initNum(var n : int; var x : int; var y : int; var pl : int; var num : int; var on : int; var width : int) {
    let c2da_fresh0 : uint = uint(x)
    c2da_mem[n] = uint8(c2da_fresh0)
    c2da_mem[n + 1] = uint8(c2da_fresh0 >> 0x8)
    c2da_mem[n + 2] = uint8(c2da_fresh0 >> 0x10)
    c2da_mem[n + 3] = uint8(c2da_fresh0 >> 0x18)
    let c2da_fresh1 : uint = uint(y)
    c2da_mem[n + 4] = uint8(c2da_fresh1)
    c2da_mem[n + 5] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[n + 6] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[n + 7] = uint8(c2da_fresh1 >> 0x18)
    let c2da_fresh2 : int = 0
    let c2da_fresh3 : uint = uint(c2da_fresh2)
    c2da_mem[n + 12] = uint8(c2da_fresh3)
    c2da_mem[n + 13] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[n + 14] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[n + 15] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : uint = uint(width)
    c2da_mem[n + 8] = uint8(c2da_fresh4)
    c2da_mem[n + 9] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[n + 10] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[n + 11] = uint8(c2da_fresh4 >> 0x18)
    let c2da_fresh5 : uint = uint(num)
    c2da_mem[n + 16] = uint8(c2da_fresh5)
    c2da_mem[n + 17] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[n + 18] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[n + 19] = uint8(c2da_fresh5 >> 0x18)
    c2da_mem[n + 20] = 0u8
    c2da_mem[n + 21] = 0u8
    c2da_mem[n + 22] = 0u8
    c2da_mem[n + 23] = 0u8
    let c2da_fresh6 : uint = uint(on)
    c2da_mem[n + 24] = uint8(c2da_fresh6)
    c2da_mem[n + 25] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[n + 26] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[n + 27] = uint8(c2da_fresh6 >> 0x18)
    c2da_mem[n + 28] = 0u8
    c2da_mem[n + 29] = 0u8
    c2da_mem[n + 30] = 0u8
    c2da_mem[n + 31] = 0u8
    let c2da_fresh7 : uint = uint(pl)
    c2da_mem[n + 32] = uint8(c2da_fresh7)
    c2da_mem[n + 33] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[n + 34] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[n + 35] = uint8(c2da_fresh7 >> 0x18)
    c2da_mem[n + 36] = 0u8
    c2da_mem[n + 37] = 0u8
    c2da_mem[n + 38] = 0u8
    c2da_mem[n + 39] = 0u8
    return
}
[export, sideeffects]
def STlib_updateNum(var n_0 : int; var refresh : uint) {
    let c2da_fresh8 : int = int(uint(c2da_mem[n_0 + 24]) | uint(c2da_mem[n_0 + 25]) << 0x8 | uint(c2da_mem[n_0 + 26]) << 0x10 | uint(c2da_mem[n_0 + 27]) << 0x18)
    if ((uint(c2da_mem[c2da_fresh8]) | uint(c2da_mem[c2da_fresh8 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh8 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh8 + 3]) << 0x18) != 0x0) {
        STlib_drawNum(n_0, refresh)
    }
    return
}
[export, sideeffects]
def STlib_drawNum(var n_1 : int; var refresh_0 : uint) {
    var numdigits : int
    var num_0 : int
    var w : int
    var h : int
    var x_0 : int
    var neg : int
    numdigits = int(uint(c2da_mem[n_1 + 8]) | uint(c2da_mem[n_1 + 9]) << 0x8 | uint(c2da_mem[n_1 + 10]) << 0x10 | uint(c2da_mem[n_1 + 11]) << 0x18)
    let c2da_fresh9 : int = int(uint(c2da_mem[n_1 + 16]) | uint(c2da_mem[n_1 + 17]) << 0x8 | uint(c2da_mem[n_1 + 18]) << 0x10 | uint(c2da_mem[n_1 + 19]) << 0x18)
    num_0 = int(uint(c2da_mem[c2da_fresh9]) | uint(c2da_mem[c2da_fresh9 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh9 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh9 + 3]) << 0x18)
    let c2da_fresh10 : int = int(uint(c2da_mem[n_1 + 32]) | uint(c2da_mem[n_1 + 33]) << 0x8 | uint(c2da_mem[n_1 + 34]) << 0x10 | uint(c2da_mem[n_1 + 35]) << 0x18) + 0 * 8
    let c2da_fresh11 : int = int(uint(c2da_mem[c2da_fresh10]) | uint(c2da_mem[c2da_fresh10 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh10 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh10 + 3]) << 0x18)
    w = int(int16(uint(c2da_mem[c2da_fresh11]) | uint(c2da_mem[c2da_fresh11 + 1]) << 0x8))
    let c2da_fresh12 : int = int(uint(c2da_mem[n_1 + 32]) | uint(c2da_mem[n_1 + 33]) << 0x8 | uint(c2da_mem[n_1 + 34]) << 0x10 | uint(c2da_mem[n_1 + 35]) << 0x18) + 0 * 8
    let c2da_fresh13 : int = int(uint(c2da_mem[c2da_fresh12]) | uint(c2da_mem[c2da_fresh12 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh12 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh12 + 3]) << 0x18) + 2
    h = int(int16(uint(c2da_mem[c2da_fresh13]) | uint(c2da_mem[c2da_fresh13 + 1]) << 0x8))
    x_0 = int(uint(c2da_mem[n_1]) | uint(c2da_mem[n_1 + 1]) << 0x8 | uint(c2da_mem[n_1 + 2]) << 0x10 | uint(c2da_mem[n_1 + 3]) << 0x18)
    let c2da_fresh14 : int = int(uint(c2da_mem[n_1 + 16]) | uint(c2da_mem[n_1 + 17]) << 0x8 | uint(c2da_mem[n_1 + 18]) << 0x10 | uint(c2da_mem[n_1 + 19]) << 0x18)
    let c2da_fresh15 : int = int(uint(c2da_mem[c2da_fresh14]) | uint(c2da_mem[c2da_fresh14 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh14 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh14 + 3]) << 0x18)
    let c2da_fresh16 : uint = uint(c2da_fresh15)
    c2da_mem[n_1 + 12] = uint8(c2da_fresh16)
    c2da_mem[n_1 + 13] = uint8(c2da_fresh16 >> 0x8)
    c2da_mem[n_1 + 14] = uint8(c2da_fresh16 >> 0x10)
    c2da_mem[n_1 + 15] = uint8(c2da_fresh16 >> 0x18)
    neg = num_0 < 0 ? 1 : 0
    if (neg != 0) {
        if (numdigits == 2 && num_0 < -9) {
            num_0 = -9
        } elif (numdigits == 3 && num_0 < -99) {
            num_0 = -99
        }
        num_0 = -num_0
    }
    x_0 = int(uint(c2da_mem[n_1]) | uint(c2da_mem[n_1 + 1]) << 0x8 | uint(c2da_mem[n_1 + 2]) << 0x10 | uint(c2da_mem[n_1 + 3]) << 0x18) - numdigits * w
    if (int(uint(c2da_mem[n_1 + 4]) | uint(c2da_mem[n_1 + 5]) << 0x8 | uint(c2da_mem[n_1 + 6]) << 0x10 | uint(c2da_mem[n_1 + 7]) << 0x18) - (200 - 32) < 0) {
        I_Error(371273, [])
    }
    V_CopyRect(x_0, int(uint(c2da_mem[n_1 + 4]) | uint(c2da_mem[n_1 + 5]) << 0x8 | uint(c2da_mem[n_1 + 6]) << 0x10 | uint(c2da_mem[n_1 + 7]) << 0x18) - (200 - 32), st_backing_screen, w * numdigits, h, x_0, int(uint(c2da_mem[n_1 + 4]) | uint(c2da_mem[n_1 + 5]) << 0x8 | uint(c2da_mem[n_1 + 6]) << 0x10 | uint(c2da_mem[n_1 + 7]) << 0x18))
    if (num_0 == 1994) {
        return
    }
    x_0 = int(uint(c2da_mem[n_1]) | uint(c2da_mem[n_1 + 1]) << 0x8 | uint(c2da_mem[n_1 + 2]) << 0x10 | uint(c2da_mem[n_1 + 3]) << 0x18)
    if (num_0 == 0) {
        let c2da_fresh17 : int = int(uint(c2da_mem[n_1 + 32]) | uint(c2da_mem[n_1 + 33]) << 0x8 | uint(c2da_mem[n_1 + 34]) << 0x10 | uint(c2da_mem[n_1 + 35]) << 0x18) + 0 * 8
        V_DrawPatch(x_0 - w, int(uint(c2da_mem[n_1 + 4]) | uint(c2da_mem[n_1 + 5]) << 0x8 | uint(c2da_mem[n_1 + 6]) << 0x10 | uint(c2da_mem[n_1 + 7]) << 0x18), int(uint(c2da_mem[c2da_fresh17]) | uint(c2da_mem[c2da_fresh17 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh17 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh17 + 3]) << 0x18))
    }
    while (true) {
        var c2da_fresh18 : int = 0
        if (num_0 != 0) {
            let c2da_postinc : int = numdigits
            numdigits--
            if (c2da_postinc != 0) {
                c2da_fresh18 = 1
            }
        }
        if (c2da_fresh18 == 0) {
            break
        }
        x_0 -= w
        let c2da_fresh19 : int = int(uint(c2da_mem[n_1 + 32]) | uint(c2da_mem[n_1 + 33]) << 0x8 | uint(c2da_mem[n_1 + 34]) << 0x10 | uint(c2da_mem[n_1 + 35]) << 0x18) + num_0 % 10 * 8
        V_DrawPatch(x_0, int(uint(c2da_mem[n_1 + 4]) | uint(c2da_mem[n_1 + 5]) << 0x8 | uint(c2da_mem[n_1 + 6]) << 0x10 | uint(c2da_mem[n_1 + 7]) << 0x18), int(uint(c2da_mem[c2da_fresh19]) | uint(c2da_mem[c2da_fresh19 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh19 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh19 + 3]) << 0x18))
        num_0 /= 10
    }
    if (neg != 0) {
        V_DrawPatch(x_0 - 8, int(uint(c2da_mem[n_1 + 4]) | uint(c2da_mem[n_1 + 5]) << 0x8 | uint(c2da_mem[n_1 + 6]) << 0x10 | uint(c2da_mem[n_1 + 7]) << 0x18), sttminus)
    }
    return
}
[export, sideeffects]
def STlib_initPercent(var p : int; var x_1 : int; var y_0 : int; var pl_0 : int; var num_1 : int; var on_0 : int; var percent : int) {
    STlib_initNum(p, x_1, y_0, pl_0, num_1, on_0, 3)
    let c2da_fresh20 : uint = uint(percent)
    c2da_mem[p + 48] = uint8(c2da_fresh20)
    c2da_mem[p + 49] = uint8(c2da_fresh20 >> 0x8)
    c2da_mem[p + 50] = uint8(c2da_fresh20 >> 0x10)
    c2da_mem[p + 51] = uint8(c2da_fresh20 >> 0x18)
    c2da_mem[p + 52] = 0u8
    c2da_mem[p + 53] = 0u8
    c2da_mem[p + 54] = 0u8
    c2da_mem[p + 55] = 0u8
    return
}
[export, sideeffects]
def STlib_updatePercent(var per : int; var refresh_1 : int) {
    var c2da_fresh22 : int = 0
    if (refresh_1 != 0) {
        let c2da_fresh21 : int = int(uint(c2da_mem[per + 24]) | uint(c2da_mem[per + 25]) << 0x8 | uint(c2da_mem[per + 26]) << 0x10 | uint(c2da_mem[per + 27]) << 0x18)
        if ((uint(c2da_mem[c2da_fresh21]) | uint(c2da_mem[c2da_fresh21 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh21 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh21 + 3]) << 0x18) != 0x0) {
            c2da_fresh22 = 1
        }
    }
    if (c2da_fresh22 != 0) {
        V_DrawPatch(int(uint(c2da_mem[per]) | uint(c2da_mem[per + 1]) << 0x8 | uint(c2da_mem[per + 2]) << 0x10 | uint(c2da_mem[per + 3]) << 0x18), int(uint(c2da_mem[per + 4]) | uint(c2da_mem[per + 5]) << 0x8 | uint(c2da_mem[per + 6]) << 0x10 | uint(c2da_mem[per + 7]) << 0x18), int(uint(c2da_mem[per + 48]) | uint(c2da_mem[per + 49]) << 0x8 | uint(c2da_mem[per + 50]) << 0x10 | uint(c2da_mem[per + 51]) << 0x18))
    }
    STlib_updateNum(per, uint(refresh_1))
    return
}
[export, sideeffects]
def STlib_initMultIcon(var i : int; var x_2 : int; var y_1 : int; var il : int; var inum : int; var on_1 : int) {
    let c2da_fresh23 : uint = uint(x_2)
    c2da_mem[i] = uint8(c2da_fresh23)
    c2da_mem[i + 1] = uint8(c2da_fresh23 >> 0x8)
    c2da_mem[i + 2] = uint8(c2da_fresh23 >> 0x10)
    c2da_mem[i + 3] = uint8(c2da_fresh23 >> 0x18)
    let c2da_fresh24 : uint = uint(y_1)
    c2da_mem[i + 4] = uint8(c2da_fresh24)
    c2da_mem[i + 5] = uint8(c2da_fresh24 >> 0x8)
    c2da_mem[i + 6] = uint8(c2da_fresh24 >> 0x10)
    c2da_mem[i + 7] = uint8(c2da_fresh24 >> 0x18)
    let c2da_fresh25 : int = -1
    let c2da_fresh26 : uint = uint(c2da_fresh25)
    c2da_mem[i + 8] = uint8(c2da_fresh26)
    c2da_mem[i + 9] = uint8(c2da_fresh26 >> 0x8)
    c2da_mem[i + 10] = uint8(c2da_fresh26 >> 0x10)
    c2da_mem[i + 11] = uint8(c2da_fresh26 >> 0x18)
    let c2da_fresh27 : uint = uint(inum)
    c2da_mem[i + 16] = uint8(c2da_fresh27)
    c2da_mem[i + 17] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[i + 18] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[i + 19] = uint8(c2da_fresh27 >> 0x18)
    c2da_mem[i + 20] = 0u8
    c2da_mem[i + 21] = 0u8
    c2da_mem[i + 22] = 0u8
    c2da_mem[i + 23] = 0u8
    let c2da_fresh28 : uint = uint(on_1)
    c2da_mem[i + 24] = uint8(c2da_fresh28)
    c2da_mem[i + 25] = uint8(c2da_fresh28 >> 0x8)
    c2da_mem[i + 26] = uint8(c2da_fresh28 >> 0x10)
    c2da_mem[i + 27] = uint8(c2da_fresh28 >> 0x18)
    c2da_mem[i + 28] = 0u8
    c2da_mem[i + 29] = 0u8
    c2da_mem[i + 30] = 0u8
    c2da_mem[i + 31] = 0u8
    let c2da_fresh29 : uint = uint(il)
    c2da_mem[i + 32] = uint8(c2da_fresh29)
    c2da_mem[i + 33] = uint8(c2da_fresh29 >> 0x8)
    c2da_mem[i + 34] = uint8(c2da_fresh29 >> 0x10)
    c2da_mem[i + 35] = uint8(c2da_fresh29 >> 0x18)
    c2da_mem[i + 36] = 0u8
    c2da_mem[i + 37] = 0u8
    c2da_mem[i + 38] = 0u8
    c2da_mem[i + 39] = 0u8
    return
}
[export, sideeffects]
def STlib_updateMultIcon(var mi : int; var refresh_2 : uint) {
    var w_0 : int
    var h_0 : int
    var x_3 : int
    var y_3 : int
    let c2da_fresh30 : int = int(uint(c2da_mem[mi + 24]) | uint(c2da_mem[mi + 25]) << 0x8 | uint(c2da_mem[mi + 26]) << 0x10 | uint(c2da_mem[mi + 27]) << 0x18)
    var c2da_fresh32 : int = 0
    if ((uint(c2da_mem[c2da_fresh30]) | uint(c2da_mem[c2da_fresh30 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh30 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh30 + 3]) << 0x18) != 0x0) {
        let c2da_fresh31 : int = int(uint(c2da_mem[mi + 16]) | uint(c2da_mem[mi + 17]) << 0x8 | uint(c2da_mem[mi + 18]) << 0x10 | uint(c2da_mem[mi + 19]) << 0x18)
        if (int(uint(c2da_mem[mi + 8]) | uint(c2da_mem[mi + 9]) << 0x8 | uint(c2da_mem[mi + 10]) << 0x10 | uint(c2da_mem[mi + 11]) << 0x18) != int(uint(c2da_mem[c2da_fresh31]) | uint(c2da_mem[c2da_fresh31 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh31 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh31 + 3]) << 0x18) || refresh_2 != 0x0) {
            c2da_fresh32 = 1
        }
    }
    var c2da_fresh34 : int = 0
    if (c2da_fresh32 != 0) {
        let c2da_fresh33 : int = int(uint(c2da_mem[mi + 16]) | uint(c2da_mem[mi + 17]) << 0x8 | uint(c2da_mem[mi + 18]) << 0x10 | uint(c2da_mem[mi + 19]) << 0x18)
        if (int(uint(c2da_mem[c2da_fresh33]) | uint(c2da_mem[c2da_fresh33 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh33 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh33 + 3]) << 0x18) != -1) {
            c2da_fresh34 = 1
        }
    }
    if (c2da_fresh34 != 0) {
        if (int(uint(c2da_mem[mi + 8]) | uint(c2da_mem[mi + 9]) << 0x8 | uint(c2da_mem[mi + 10]) << 0x10 | uint(c2da_mem[mi + 11]) << 0x18) != -1) {
            let c2da_fresh35 : int = int(uint(c2da_mem[mi + 32]) | uint(c2da_mem[mi + 33]) << 0x8 | uint(c2da_mem[mi + 34]) << 0x10 | uint(c2da_mem[mi + 35]) << 0x18) + int(uint(c2da_mem[mi + 8]) | uint(c2da_mem[mi + 9]) << 0x8 | uint(c2da_mem[mi + 10]) << 0x10 | uint(c2da_mem[mi + 11]) << 0x18) * 8
            let c2da_fresh36 : int = int(uint(c2da_mem[c2da_fresh35]) | uint(c2da_mem[c2da_fresh35 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh35 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh35 + 3]) << 0x18) + 4
            x_3 = int(uint(c2da_mem[mi]) | uint(c2da_mem[mi + 1]) << 0x8 | uint(c2da_mem[mi + 2]) << 0x10 | uint(c2da_mem[mi + 3]) << 0x18) - int(int16(uint(c2da_mem[c2da_fresh36]) | uint(c2da_mem[c2da_fresh36 + 1]) << 0x8))
            let c2da_fresh37 : int = int(uint(c2da_mem[mi + 32]) | uint(c2da_mem[mi + 33]) << 0x8 | uint(c2da_mem[mi + 34]) << 0x10 | uint(c2da_mem[mi + 35]) << 0x18) + int(uint(c2da_mem[mi + 8]) | uint(c2da_mem[mi + 9]) << 0x8 | uint(c2da_mem[mi + 10]) << 0x10 | uint(c2da_mem[mi + 11]) << 0x18) * 8
            let c2da_fresh38 : int = int(uint(c2da_mem[c2da_fresh37]) | uint(c2da_mem[c2da_fresh37 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh37 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh37 + 3]) << 0x18) + 6
            y_3 = int(uint(c2da_mem[mi + 4]) | uint(c2da_mem[mi + 5]) << 0x8 | uint(c2da_mem[mi + 6]) << 0x10 | uint(c2da_mem[mi + 7]) << 0x18) - int(int16(uint(c2da_mem[c2da_fresh38]) | uint(c2da_mem[c2da_fresh38 + 1]) << 0x8))
            let c2da_fresh39 : int = int(uint(c2da_mem[mi + 32]) | uint(c2da_mem[mi + 33]) << 0x8 | uint(c2da_mem[mi + 34]) << 0x10 | uint(c2da_mem[mi + 35]) << 0x18) + int(uint(c2da_mem[mi + 8]) | uint(c2da_mem[mi + 9]) << 0x8 | uint(c2da_mem[mi + 10]) << 0x10 | uint(c2da_mem[mi + 11]) << 0x18) * 8
            let c2da_fresh40 : int = int(uint(c2da_mem[c2da_fresh39]) | uint(c2da_mem[c2da_fresh39 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh39 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh39 + 3]) << 0x18)
            w_0 = int(int16(uint(c2da_mem[c2da_fresh40]) | uint(c2da_mem[c2da_fresh40 + 1]) << 0x8))
            let c2da_fresh41 : int = int(uint(c2da_mem[mi + 32]) | uint(c2da_mem[mi + 33]) << 0x8 | uint(c2da_mem[mi + 34]) << 0x10 | uint(c2da_mem[mi + 35]) << 0x18) + int(uint(c2da_mem[mi + 8]) | uint(c2da_mem[mi + 9]) << 0x8 | uint(c2da_mem[mi + 10]) << 0x10 | uint(c2da_mem[mi + 11]) << 0x18) * 8
            let c2da_fresh42 : int = int(uint(c2da_mem[c2da_fresh41]) | uint(c2da_mem[c2da_fresh41 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh41 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh41 + 3]) << 0x18) + 2
            h_0 = int(int16(uint(c2da_mem[c2da_fresh42]) | uint(c2da_mem[c2da_fresh42 + 1]) << 0x8))
            if (y_3 - (200 - 32) < 0) {
                I_Error(371298, [])
            }
            V_CopyRect(x_3, y_3 - (200 - 32), st_backing_screen, w_0, h_0, x_3, y_3)
        }
        let c2da_fresh43 : int = int(uint(c2da_mem[mi + 16]) | uint(c2da_mem[mi + 17]) << 0x8 | uint(c2da_mem[mi + 18]) << 0x10 | uint(c2da_mem[mi + 19]) << 0x18)
        let c2da_fresh44 : int = int(uint(c2da_mem[mi + 32]) | uint(c2da_mem[mi + 33]) << 0x8 | uint(c2da_mem[mi + 34]) << 0x10 | uint(c2da_mem[mi + 35]) << 0x18) + int(uint(c2da_mem[c2da_fresh43]) | uint(c2da_mem[c2da_fresh43 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh43 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh43 + 3]) << 0x18) * 8
        V_DrawPatch(int(uint(c2da_mem[mi]) | uint(c2da_mem[mi + 1]) << 0x8 | uint(c2da_mem[mi + 2]) << 0x10 | uint(c2da_mem[mi + 3]) << 0x18), int(uint(c2da_mem[mi + 4]) | uint(c2da_mem[mi + 5]) << 0x8 | uint(c2da_mem[mi + 6]) << 0x10 | uint(c2da_mem[mi + 7]) << 0x18), int(uint(c2da_mem[c2da_fresh44]) | uint(c2da_mem[c2da_fresh44 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh44 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh44 + 3]) << 0x18))
        let c2da_fresh45 : int = int(uint(c2da_mem[mi + 16]) | uint(c2da_mem[mi + 17]) << 0x8 | uint(c2da_mem[mi + 18]) << 0x10 | uint(c2da_mem[mi + 19]) << 0x18)
        let c2da_fresh46 : int = int(uint(c2da_mem[c2da_fresh45]) | uint(c2da_mem[c2da_fresh45 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh45 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh45 + 3]) << 0x18)
        let c2da_fresh47 : uint = uint(c2da_fresh46)
        c2da_mem[mi + 8] = uint8(c2da_fresh47)
        c2da_mem[mi + 9] = uint8(c2da_fresh47 >> 0x8)
        c2da_mem[mi + 10] = uint8(c2da_fresh47 >> 0x10)
        c2da_mem[mi + 11] = uint8(c2da_fresh47 >> 0x18)
    }
    return
}
[export, sideeffects]
def STlib_initBinIcon(var b : int; var x_4 : int; var y_4 : int; var i_0 : int; var val : int; var on_2 : int) {
    let c2da_fresh48 : uint = uint(x_4)
    c2da_mem[b] = uint8(c2da_fresh48)
    c2da_mem[b + 1] = uint8(c2da_fresh48 >> 0x8)
    c2da_mem[b + 2] = uint8(c2da_fresh48 >> 0x10)
    c2da_mem[b + 3] = uint8(c2da_fresh48 >> 0x18)
    let c2da_fresh49 : uint = uint(y_4)
    c2da_mem[b + 4] = uint8(c2da_fresh49)
    c2da_mem[b + 5] = uint8(c2da_fresh49 >> 0x8)
    c2da_mem[b + 6] = uint8(c2da_fresh49 >> 0x10)
    c2da_mem[b + 7] = uint8(c2da_fresh49 >> 0x18)
    let c2da_fresh50 : uint = 0u
    let c2da_fresh51 : uint = c2da_fresh50
    c2da_mem[b + 8] = uint8(c2da_fresh51)
    c2da_mem[b + 9] = uint8(c2da_fresh51 >> 0x8)
    c2da_mem[b + 10] = uint8(c2da_fresh51 >> 0x10)
    c2da_mem[b + 11] = uint8(c2da_fresh51 >> 0x18)
    let c2da_fresh52 : uint = uint(val)
    c2da_mem[b + 16] = uint8(c2da_fresh52)
    c2da_mem[b + 17] = uint8(c2da_fresh52 >> 0x8)
    c2da_mem[b + 18] = uint8(c2da_fresh52 >> 0x10)
    c2da_mem[b + 19] = uint8(c2da_fresh52 >> 0x18)
    c2da_mem[b + 20] = 0u8
    c2da_mem[b + 21] = 0u8
    c2da_mem[b + 22] = 0u8
    c2da_mem[b + 23] = 0u8
    let c2da_fresh53 : uint = uint(on_2)
    c2da_mem[b + 24] = uint8(c2da_fresh53)
    c2da_mem[b + 25] = uint8(c2da_fresh53 >> 0x8)
    c2da_mem[b + 26] = uint8(c2da_fresh53 >> 0x10)
    c2da_mem[b + 27] = uint8(c2da_fresh53 >> 0x18)
    c2da_mem[b + 28] = 0u8
    c2da_mem[b + 29] = 0u8
    c2da_mem[b + 30] = 0u8
    c2da_mem[b + 31] = 0u8
    let c2da_fresh54 : uint = uint(i_0)
    c2da_mem[b + 32] = uint8(c2da_fresh54)
    c2da_mem[b + 33] = uint8(c2da_fresh54 >> 0x8)
    c2da_mem[b + 34] = uint8(c2da_fresh54 >> 0x10)
    c2da_mem[b + 35] = uint8(c2da_fresh54 >> 0x18)
    c2da_mem[b + 36] = 0u8
    c2da_mem[b + 37] = 0u8
    c2da_mem[b + 38] = 0u8
    c2da_mem[b + 39] = 0u8
    return
}
[export, sideeffects]
def STlib_updateBinIcon(var bi : int; var refresh_3 : uint) {
    var x_5 : int
    var y_5 : int
    var w_1 : int
    var h_1 : int
    let c2da_fresh55 : int = int(uint(c2da_mem[bi + 24]) | uint(c2da_mem[bi + 25]) << 0x8 | uint(c2da_mem[bi + 26]) << 0x10 | uint(c2da_mem[bi + 27]) << 0x18)
    var c2da_fresh57 : int = 0
    if ((uint(c2da_mem[c2da_fresh55]) | uint(c2da_mem[c2da_fresh55 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh55 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh55 + 3]) << 0x18) != 0x0) {
        let c2da_fresh56 : int = int(uint(c2da_mem[bi + 16]) | uint(c2da_mem[bi + 17]) << 0x8 | uint(c2da_mem[bi + 18]) << 0x10 | uint(c2da_mem[bi + 19]) << 0x18)
        if ((uint(c2da_mem[bi + 8]) | uint(c2da_mem[bi + 9]) << 0x8 | uint(c2da_mem[bi + 10]) << 0x10 | uint(c2da_mem[bi + 11]) << 0x18) != (uint(c2da_mem[c2da_fresh56]) | uint(c2da_mem[c2da_fresh56 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh56 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh56 + 3]) << 0x18) || refresh_3 != 0x0) {
            c2da_fresh57 = 1
        }
    }
    if (c2da_fresh57 != 0) {
        let c2da_fresh58 : int = int(uint(c2da_mem[bi + 32]) | uint(c2da_mem[bi + 33]) << 0x8 | uint(c2da_mem[bi + 34]) << 0x10 | uint(c2da_mem[bi + 35]) << 0x18) + 4
        x_5 = int(uint(c2da_mem[bi]) | uint(c2da_mem[bi + 1]) << 0x8 | uint(c2da_mem[bi + 2]) << 0x10 | uint(c2da_mem[bi + 3]) << 0x18) - int(int16(uint(c2da_mem[c2da_fresh58]) | uint(c2da_mem[c2da_fresh58 + 1]) << 0x8))
        let c2da_fresh59 : int = int(uint(c2da_mem[bi + 32]) | uint(c2da_mem[bi + 33]) << 0x8 | uint(c2da_mem[bi + 34]) << 0x10 | uint(c2da_mem[bi + 35]) << 0x18) + 6
        y_5 = int(uint(c2da_mem[bi + 4]) | uint(c2da_mem[bi + 5]) << 0x8 | uint(c2da_mem[bi + 6]) << 0x10 | uint(c2da_mem[bi + 7]) << 0x18) - int(int16(uint(c2da_mem[c2da_fresh59]) | uint(c2da_mem[c2da_fresh59 + 1]) << 0x8))
        let c2da_fresh60 : int = int(uint(c2da_mem[bi + 32]) | uint(c2da_mem[bi + 33]) << 0x8 | uint(c2da_mem[bi + 34]) << 0x10 | uint(c2da_mem[bi + 35]) << 0x18)
        w_1 = int(int16(uint(c2da_mem[c2da_fresh60]) | uint(c2da_mem[c2da_fresh60 + 1]) << 0x8))
        let c2da_fresh61 : int = int(uint(c2da_mem[bi + 32]) | uint(c2da_mem[bi + 33]) << 0x8 | uint(c2da_mem[bi + 34]) << 0x10 | uint(c2da_mem[bi + 35]) << 0x18) + 2
        h_1 = int(int16(uint(c2da_mem[c2da_fresh61]) | uint(c2da_mem[c2da_fresh61 + 1]) << 0x8))
        if (y_5 - (200 - 32) < 0) {
            I_Error(371327, [])
        }
        let c2da_fresh62 : int = int(uint(c2da_mem[bi + 16]) | uint(c2da_mem[bi + 17]) << 0x8 | uint(c2da_mem[bi + 18]) << 0x10 | uint(c2da_mem[bi + 19]) << 0x18)
        if ((uint(c2da_mem[c2da_fresh62]) | uint(c2da_mem[c2da_fresh62 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh62 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh62 + 3]) << 0x18) != 0x0) {
            V_DrawPatch(int(uint(c2da_mem[bi]) | uint(c2da_mem[bi + 1]) << 0x8 | uint(c2da_mem[bi + 2]) << 0x10 | uint(c2da_mem[bi + 3]) << 0x18), int(uint(c2da_mem[bi + 4]) | uint(c2da_mem[bi + 5]) << 0x8 | uint(c2da_mem[bi + 6]) << 0x10 | uint(c2da_mem[bi + 7]) << 0x18), int(uint(c2da_mem[bi + 32]) | uint(c2da_mem[bi + 33]) << 0x8 | uint(c2da_mem[bi + 34]) << 0x10 | uint(c2da_mem[bi + 35]) << 0x18))
        } else {
            V_CopyRect(x_5, y_5 - (200 - 32), st_backing_screen, w_1, h_1, x_5, y_5)
        }
        let c2da_fresh63 : int = int(uint(c2da_mem[bi + 16]) | uint(c2da_mem[bi + 17]) << 0x8 | uint(c2da_mem[bi + 18]) << 0x10 | uint(c2da_mem[bi + 19]) << 0x18)
        let c2da_fresh64 : uint = uint(c2da_mem[c2da_fresh63]) | uint(c2da_mem[c2da_fresh63 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh63 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh63 + 3]) << 0x18
        let c2da_fresh65 : uint = c2da_fresh64
        c2da_mem[bi + 8] = uint8(c2da_fresh65)
        c2da_mem[bi + 9] = uint8(c2da_fresh65 >> 0x8)
        c2da_mem[bi + 10] = uint8(c2da_fresh65 >> 0x10)
        c2da_mem[bi + 11] = uint8(c2da_fresh65 >> 0x18)
    }
    return
}

// This unit's static data, at heap offset 371264.
let private c2da_lin_static_st_lib_seg = fixed_array<int>(371264, 90)
let private c2da_lin_static_st_lib = fixed_array<uint64>(0x53554e494d545453ul, 0x6d754e7761726400ul, 0x2d20793e2d6e203aul, 0x203c20595f545320ul, 0x6574616470750030ul, 0x6e6f6349746c754dul, 0x5453202d2079203aul, 0x750030203c20595ful, 0x6e69426574616470ul, 0x2079203a6e6f6349ul, 0x3c20595f5453202dul, 0x3020ul)

[init]
def private c2da_lin_init_static_st_lib() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_st_lib_seg[s * 2]
        for (k in range(c2da_lin_static_st_lib_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_st_lib[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
