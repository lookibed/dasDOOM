[sideeffects]
def private c2da___bswap_16_9(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_9(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_9(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_9(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_9(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_9(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
var intercept_p : int = default<int>

[export, sideeffects]
def P_AproxDistance(var dx : int; var dy : int) : int {
    dx = c2da_std_abs(dx)
    dy = c2da_std_abs(dy)
    if (dx < dy) {
        return dx + dy - (dx >> 1)
    }
    return dx + dy - (dy >> 1)
}
[export, sideeffects]
def P_PointOnLineSide(var x : int; var y : int; var line : int) : int {
    var dx_0 : int
    var dy_0 : int
    var left : int
    var right : int
    if (int(uint(c2da_mem[line + 16]) | uint(c2da_mem[line + 17]) << 0x8 | uint(c2da_mem[line + 18]) << 0x10 | uint(c2da_mem[line + 19]) << 0x18) == 0) {
        let c2da_fresh0 : int = int(uint(c2da_mem[line]) | uint(c2da_mem[line + 1]) << 0x8 | uint(c2da_mem[line + 2]) << 0x10 | uint(c2da_mem[line + 3]) << 0x18)
        if (x <= int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18)) {
            return int(uint(c2da_mem[line + 20]) | uint(c2da_mem[line + 21]) << 0x8 | uint(c2da_mem[line + 22]) << 0x10 | uint(c2da_mem[line + 23]) << 0x18) > 0 ? 1 : 0
        }
        return int(uint(c2da_mem[line + 20]) | uint(c2da_mem[line + 21]) << 0x8 | uint(c2da_mem[line + 22]) << 0x10 | uint(c2da_mem[line + 23]) << 0x18) < 0 ? 1 : 0
    }
    if (int(uint(c2da_mem[line + 20]) | uint(c2da_mem[line + 21]) << 0x8 | uint(c2da_mem[line + 22]) << 0x10 | uint(c2da_mem[line + 23]) << 0x18) == 0) {
        let c2da_fresh1 : int = int(uint(c2da_mem[line]) | uint(c2da_mem[line + 1]) << 0x8 | uint(c2da_mem[line + 2]) << 0x10 | uint(c2da_mem[line + 3]) << 0x18) + 4
        if (y <= int(uint(c2da_mem[c2da_fresh1]) | uint(c2da_mem[c2da_fresh1 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh1 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh1 + 3]) << 0x18)) {
            return int(uint(c2da_mem[line + 16]) | uint(c2da_mem[line + 17]) << 0x8 | uint(c2da_mem[line + 18]) << 0x10 | uint(c2da_mem[line + 19]) << 0x18) < 0 ? 1 : 0
        }
        return int(uint(c2da_mem[line + 16]) | uint(c2da_mem[line + 17]) << 0x8 | uint(c2da_mem[line + 18]) << 0x10 | uint(c2da_mem[line + 19]) << 0x18) > 0 ? 1 : 0
    }
    let c2da_fresh2 : int = int(uint(c2da_mem[line]) | uint(c2da_mem[line + 1]) << 0x8 | uint(c2da_mem[line + 2]) << 0x10 | uint(c2da_mem[line + 3]) << 0x18)
    dx_0 = x - int(uint(c2da_mem[c2da_fresh2]) | uint(c2da_mem[c2da_fresh2 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh2 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh2 + 3]) << 0x18)
    let c2da_fresh3 : int = int(uint(c2da_mem[line]) | uint(c2da_mem[line + 1]) << 0x8 | uint(c2da_mem[line + 2]) << 0x10 | uint(c2da_mem[line + 3]) << 0x18) + 4
    dy_0 = y - int(uint(c2da_mem[c2da_fresh3]) | uint(c2da_mem[c2da_fresh3 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh3 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh3 + 3]) << 0x18)
    left = FixedMul(int(uint(c2da_mem[line + 20]) | uint(c2da_mem[line + 21]) << 0x8 | uint(c2da_mem[line + 22]) << 0x10 | uint(c2da_mem[line + 23]) << 0x18) >> 16, dx_0)
    right = FixedMul(dy_0, int(uint(c2da_mem[line + 16]) | uint(c2da_mem[line + 17]) << 0x8 | uint(c2da_mem[line + 18]) << 0x10 | uint(c2da_mem[line + 19]) << 0x18) >> 16)
    if (right < left) {
        return 0
    }
    return 1
}
[export, sideeffects]
def P_PointOnDivlineSide(var x_0 : int; var y_0 : int; var line_0 : int) : int {
    var dx_1 : int
    var dy_1 : int
    var left_0 : int
    var right_0 : int
    if (int(uint(c2da_mem[line_0 + 8]) | uint(c2da_mem[line_0 + 9]) << 0x8 | uint(c2da_mem[line_0 + 10]) << 0x10 | uint(c2da_mem[line_0 + 11]) << 0x18) == 0) {
        if (x_0 <= int(uint(c2da_mem[line_0]) | uint(c2da_mem[line_0 + 1]) << 0x8 | uint(c2da_mem[line_0 + 2]) << 0x10 | uint(c2da_mem[line_0 + 3]) << 0x18)) {
            return int(uint(c2da_mem[line_0 + 12]) | uint(c2da_mem[line_0 + 13]) << 0x8 | uint(c2da_mem[line_0 + 14]) << 0x10 | uint(c2da_mem[line_0 + 15]) << 0x18) > 0 ? 1 : 0
        }
        return int(uint(c2da_mem[line_0 + 12]) | uint(c2da_mem[line_0 + 13]) << 0x8 | uint(c2da_mem[line_0 + 14]) << 0x10 | uint(c2da_mem[line_0 + 15]) << 0x18) < 0 ? 1 : 0
    }
    if (int(uint(c2da_mem[line_0 + 12]) | uint(c2da_mem[line_0 + 13]) << 0x8 | uint(c2da_mem[line_0 + 14]) << 0x10 | uint(c2da_mem[line_0 + 15]) << 0x18) == 0) {
        if (y_0 <= int(uint(c2da_mem[line_0 + 4]) | uint(c2da_mem[line_0 + 5]) << 0x8 | uint(c2da_mem[line_0 + 6]) << 0x10 | uint(c2da_mem[line_0 + 7]) << 0x18)) {
            return int(uint(c2da_mem[line_0 + 8]) | uint(c2da_mem[line_0 + 9]) << 0x8 | uint(c2da_mem[line_0 + 10]) << 0x10 | uint(c2da_mem[line_0 + 11]) << 0x18) < 0 ? 1 : 0
        }
        return int(uint(c2da_mem[line_0 + 8]) | uint(c2da_mem[line_0 + 9]) << 0x8 | uint(c2da_mem[line_0 + 10]) << 0x10 | uint(c2da_mem[line_0 + 11]) << 0x18) > 0 ? 1 : 0
    }
    dx_1 = x_0 - int(uint(c2da_mem[line_0]) | uint(c2da_mem[line_0 + 1]) << 0x8 | uint(c2da_mem[line_0 + 2]) << 0x10 | uint(c2da_mem[line_0 + 3]) << 0x18)
    dy_1 = y_0 - int(uint(c2da_mem[line_0 + 4]) | uint(c2da_mem[line_0 + 5]) << 0x8 | uint(c2da_mem[line_0 + 6]) << 0x10 | uint(c2da_mem[line_0 + 7]) << 0x18)
    if ((uint(int(uint(c2da_mem[line_0 + 12]) | uint(c2da_mem[line_0 + 13]) << 0x8 | uint(c2da_mem[line_0 + 14]) << 0x10 | uint(c2da_mem[line_0 + 15]) << 0x18) ^ int(uint(c2da_mem[line_0 + 8]) | uint(c2da_mem[line_0 + 9]) << 0x8 | uint(c2da_mem[line_0 + 10]) << 0x10 | uint(c2da_mem[line_0 + 11]) << 0x18) ^ dx_1 ^ dy_1) & 0x80000000u) != 0x0) {
        if ((uint(int(uint(c2da_mem[line_0 + 12]) | uint(c2da_mem[line_0 + 13]) << 0x8 | uint(c2da_mem[line_0 + 14]) << 0x10 | uint(c2da_mem[line_0 + 15]) << 0x18) ^ dx_1) & 0x80000000u) != 0x0) {
            return 1
        }
        return 0
    }
    left_0 = FixedMul(int(uint(c2da_mem[line_0 + 12]) | uint(c2da_mem[line_0 + 13]) << 0x8 | uint(c2da_mem[line_0 + 14]) << 0x10 | uint(c2da_mem[line_0 + 15]) << 0x18) >> 8, dx_1 >> 8)
    right_0 = FixedMul(dy_1 >> 8, int(uint(c2da_mem[line_0 + 8]) | uint(c2da_mem[line_0 + 9]) << 0x8 | uint(c2da_mem[line_0 + 10]) << 0x10 | uint(c2da_mem[line_0 + 11]) << 0x18) >> 8)
    if (right_0 < left_0) {
        return 0
    }
    return 1
}
[export, sideeffects]
def P_MakeDivline(var li : int; var dl : int) {
    let c2da_fresh4 : int = int(uint(c2da_mem[li]) | uint(c2da_mem[li + 1]) << 0x8 | uint(c2da_mem[li + 2]) << 0x10 | uint(c2da_mem[li + 3]) << 0x18)
    let c2da_fresh5 : int = int(uint(c2da_mem[c2da_fresh4]) | uint(c2da_mem[c2da_fresh4 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh4 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh4 + 3]) << 0x18)
    let c2da_fresh6 : uint = uint(c2da_fresh5)
    c2da_mem[dl] = uint8(c2da_fresh6)
    c2da_mem[dl + 1] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[dl + 2] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[dl + 3] = uint8(c2da_fresh6 >> 0x18)
    let c2da_fresh7 : int = int(uint(c2da_mem[li]) | uint(c2da_mem[li + 1]) << 0x8 | uint(c2da_mem[li + 2]) << 0x10 | uint(c2da_mem[li + 3]) << 0x18) + 4
    let c2da_fresh8 : int = int(uint(c2da_mem[c2da_fresh7]) | uint(c2da_mem[c2da_fresh7 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh7 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh7 + 3]) << 0x18)
    let c2da_fresh9 : uint = uint(c2da_fresh8)
    c2da_mem[dl + 4] = uint8(c2da_fresh9)
    c2da_mem[dl + 5] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[dl + 6] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[dl + 7] = uint8(c2da_fresh9 >> 0x18)
    let c2da_fresh10 : int = int(uint(c2da_mem[li + 16]) | uint(c2da_mem[li + 17]) << 0x8 | uint(c2da_mem[li + 18]) << 0x10 | uint(c2da_mem[li + 19]) << 0x18)
    let c2da_fresh11 : uint = uint(c2da_fresh10)
    c2da_mem[dl + 8] = uint8(c2da_fresh11)
    c2da_mem[dl + 9] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[dl + 10] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[dl + 11] = uint8(c2da_fresh11 >> 0x18)
    let c2da_fresh12 : int = int(uint(c2da_mem[li + 20]) | uint(c2da_mem[li + 21]) << 0x8 | uint(c2da_mem[li + 22]) << 0x10 | uint(c2da_mem[li + 23]) << 0x18)
    let c2da_fresh13 : uint = uint(c2da_fresh12)
    c2da_mem[dl + 12] = uint8(c2da_fresh13)
    c2da_mem[dl + 13] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[dl + 14] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[dl + 15] = uint8(c2da_fresh13 >> 0x18)
    return
}
[export, sideeffects]
def P_InterceptVector(var v2 : int; var v1 : int) : int {
    var frac : int
    var num : int
    var den : int = FixedMul(int(uint(c2da_mem[v1 + 12]) | uint(c2da_mem[v1 + 13]) << 0x8 | uint(c2da_mem[v1 + 14]) << 0x10 | uint(c2da_mem[v1 + 15]) << 0x18) >> 8, int(uint(c2da_mem[v2 + 8]) | uint(c2da_mem[v2 + 9]) << 0x8 | uint(c2da_mem[v2 + 10]) << 0x10 | uint(c2da_mem[v2 + 11]) << 0x18)) - FixedMul(int(uint(c2da_mem[v1 + 8]) | uint(c2da_mem[v1 + 9]) << 0x8 | uint(c2da_mem[v1 + 10]) << 0x10 | uint(c2da_mem[v1 + 11]) << 0x18) >> 8, int(uint(c2da_mem[v2 + 12]) | uint(c2da_mem[v2 + 13]) << 0x8 | uint(c2da_mem[v2 + 14]) << 0x10 | uint(c2da_mem[v2 + 15]) << 0x18))
    if (den == 0) {
        return 0
    }
    num = FixedMul(int(uint(c2da_mem[v1]) | uint(c2da_mem[v1 + 1]) << 0x8 | uint(c2da_mem[v1 + 2]) << 0x10 | uint(c2da_mem[v1 + 3]) << 0x18) - int(uint(c2da_mem[v2]) | uint(c2da_mem[v2 + 1]) << 0x8 | uint(c2da_mem[v2 + 2]) << 0x10 | uint(c2da_mem[v2 + 3]) << 0x18) >> 8, int(uint(c2da_mem[v1 + 12]) | uint(c2da_mem[v1 + 13]) << 0x8 | uint(c2da_mem[v1 + 14]) << 0x10 | uint(c2da_mem[v1 + 15]) << 0x18)) + FixedMul(int(uint(c2da_mem[v2 + 4]) | uint(c2da_mem[v2 + 5]) << 0x8 | uint(c2da_mem[v2 + 6]) << 0x10 | uint(c2da_mem[v2 + 7]) << 0x18) - int(uint(c2da_mem[v1 + 4]) | uint(c2da_mem[v1 + 5]) << 0x8 | uint(c2da_mem[v1 + 6]) << 0x10 | uint(c2da_mem[v1 + 7]) << 0x18) >> 8, int(uint(c2da_mem[v1 + 8]) | uint(c2da_mem[v1 + 9]) << 0x8 | uint(c2da_mem[v1 + 10]) << 0x10 | uint(c2da_mem[v1 + 11]) << 0x18))
    frac = FixedDiv(num, den)
    return frac
}
[export, sideeffects]
def P_BoxOnLineSide(var tmbox : int; var ld : int) : int {
    var c2da_fresh14 : uint
    var p1 : int
    var p2 : int
    p1 = 0
    p2 = 0
    c2da_fresh14 = uint(c2da_mem[ld + 52]) | uint(c2da_mem[ld + 53]) << 0x8 | uint(c2da_mem[ld + 54]) << 0x10 | uint(c2da_mem[ld + 55]) << 0x18
    if (c2da_fresh14 == 0x0u) {
        let c2da_fresh15 : int = int(uint(c2da_mem[ld]) | uint(c2da_mem[ld + 1]) << 0x8 | uint(c2da_mem[ld + 2]) << 0x10 | uint(c2da_mem[ld + 3]) << 0x18) + 4
        p1 = int(uint(c2da_mem[tmbox + 0 * 4]) | uint(c2da_mem[tmbox + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[tmbox + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[tmbox + 0 * 4 + 3]) << 0x18) > int(uint(c2da_mem[c2da_fresh15]) | uint(c2da_mem[c2da_fresh15 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh15 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh15 + 3]) << 0x18) ? 1 : 0
        let c2da_fresh16 : int = int(uint(c2da_mem[ld]) | uint(c2da_mem[ld + 1]) << 0x8 | uint(c2da_mem[ld + 2]) << 0x10 | uint(c2da_mem[ld + 3]) << 0x18) + 4
        p2 = int(uint(c2da_mem[tmbox + 1 * 4]) | uint(c2da_mem[tmbox + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[tmbox + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[tmbox + 1 * 4 + 3]) << 0x18) > int(uint(c2da_mem[c2da_fresh16]) | uint(c2da_mem[c2da_fresh16 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh16 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh16 + 3]) << 0x18) ? 1 : 0
        if (int(uint(c2da_mem[ld + 16]) | uint(c2da_mem[ld + 17]) << 0x8 | uint(c2da_mem[ld + 18]) << 0x10 | uint(c2da_mem[ld + 19]) << 0x18) < 0) {
            p1 ^= 1
            p2 ^= 1
        }
    } elif (c2da_fresh14 == 0x1u) {
        let c2da_fresh17 : int = int(uint(c2da_mem[ld]) | uint(c2da_mem[ld + 1]) << 0x8 | uint(c2da_mem[ld + 2]) << 0x10 | uint(c2da_mem[ld + 3]) << 0x18)
        p1 = int(uint(c2da_mem[tmbox + 3 * 4]) | uint(c2da_mem[tmbox + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[tmbox + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[tmbox + 3 * 4 + 3]) << 0x18) < int(uint(c2da_mem[c2da_fresh17]) | uint(c2da_mem[c2da_fresh17 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh17 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh17 + 3]) << 0x18) ? 1 : 0
        let c2da_fresh18 : int = int(uint(c2da_mem[ld]) | uint(c2da_mem[ld + 1]) << 0x8 | uint(c2da_mem[ld + 2]) << 0x10 | uint(c2da_mem[ld + 3]) << 0x18)
        p2 = int(uint(c2da_mem[tmbox + 2 * 4]) | uint(c2da_mem[tmbox + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[tmbox + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[tmbox + 2 * 4 + 3]) << 0x18) < int(uint(c2da_mem[c2da_fresh18]) | uint(c2da_mem[c2da_fresh18 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh18 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh18 + 3]) << 0x18) ? 1 : 0
        if (int(uint(c2da_mem[ld + 20]) | uint(c2da_mem[ld + 21]) << 0x8 | uint(c2da_mem[ld + 22]) << 0x10 | uint(c2da_mem[ld + 23]) << 0x18) < 0) {
            p1 ^= 1
            p2 ^= 1
        }
    } elif (c2da_fresh14 == 0x2u) {
        p1 = P_PointOnLineSide(int(uint(c2da_mem[tmbox + 2 * 4]) | uint(c2da_mem[tmbox + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[tmbox + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[tmbox + 2 * 4 + 3]) << 0x18), int(uint(c2da_mem[tmbox + 0 * 4]) | uint(c2da_mem[tmbox + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[tmbox + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[tmbox + 0 * 4 + 3]) << 0x18), ld)
        p2 = P_PointOnLineSide(int(uint(c2da_mem[tmbox + 3 * 4]) | uint(c2da_mem[tmbox + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[tmbox + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[tmbox + 3 * 4 + 3]) << 0x18), int(uint(c2da_mem[tmbox + 1 * 4]) | uint(c2da_mem[tmbox + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[tmbox + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[tmbox + 1 * 4 + 3]) << 0x18), ld)
    } elif (c2da_fresh14 == 0x3u) {
        p1 = P_PointOnLineSide(int(uint(c2da_mem[tmbox + 3 * 4]) | uint(c2da_mem[tmbox + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[tmbox + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[tmbox + 3 * 4 + 3]) << 0x18), int(uint(c2da_mem[tmbox + 0 * 4]) | uint(c2da_mem[tmbox + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[tmbox + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[tmbox + 0 * 4 + 3]) << 0x18), ld)
        p2 = P_PointOnLineSide(int(uint(c2da_mem[tmbox + 2 * 4]) | uint(c2da_mem[tmbox + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[tmbox + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[tmbox + 2 * 4 + 3]) << 0x18), int(uint(c2da_mem[tmbox + 1 * 4]) | uint(c2da_mem[tmbox + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[tmbox + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[tmbox + 1 * 4 + 3]) << 0x18), ld)
    }
    if (p1 == p2) {
        return p1
    }
    return -1
}
[export, sideeffects]
def P_LineOpening(var linedef_0 : int) {
    var front : int
    var back : int
    if (int(int16(uint(c2da_mem[linedef_0 + 30 + 1 * 2]) | uint(c2da_mem[linedef_0 + 30 + 1 * 2 + 1]) << 0x8)) == -1) {
        let c2da_fresh19 : int = 0
        let c2da_fresh20 : uint = uint(c2da_fresh19)
        c2da_mem[49680] = uint8(c2da_fresh20)
        c2da_mem[49681] = uint8(c2da_fresh20 >> 0x8)
        c2da_mem[49682] = uint8(c2da_fresh20 >> 0x10)
        c2da_mem[49683] = uint8(c2da_fresh20 >> 0x18)
        return
    }
    front = int(uint(c2da_mem[linedef_0 + 56]) | uint(c2da_mem[linedef_0 + 57]) << 0x8 | uint(c2da_mem[linedef_0 + 58]) << 0x10 | uint(c2da_mem[linedef_0 + 59]) << 0x18)
    back = int(uint(c2da_mem[linedef_0 + 64]) | uint(c2da_mem[linedef_0 + 65]) << 0x8 | uint(c2da_mem[linedef_0 + 66]) << 0x10 | uint(c2da_mem[linedef_0 + 67]) << 0x18)
    if (int(uint(c2da_mem[front + 4]) | uint(c2da_mem[front + 5]) << 0x8 | uint(c2da_mem[front + 6]) << 0x10 | uint(c2da_mem[front + 7]) << 0x18) < int(uint(c2da_mem[back + 4]) | uint(c2da_mem[back + 5]) << 0x8 | uint(c2da_mem[back + 6]) << 0x10 | uint(c2da_mem[back + 7]) << 0x18)) {
        let c2da_fresh21 : int = int(uint(c2da_mem[front + 4]) | uint(c2da_mem[front + 5]) << 0x8 | uint(c2da_mem[front + 6]) << 0x10 | uint(c2da_mem[front + 7]) << 0x18)
        let c2da_fresh22 : uint = uint(c2da_fresh21)
        c2da_mem[49664] = uint8(c2da_fresh22)
        c2da_mem[49665] = uint8(c2da_fresh22 >> 0x8)
        c2da_mem[49666] = uint8(c2da_fresh22 >> 0x10)
        c2da_mem[49667] = uint8(c2da_fresh22 >> 0x18)
    } else {
        let c2da_fresh23 : int = int(uint(c2da_mem[back + 4]) | uint(c2da_mem[back + 5]) << 0x8 | uint(c2da_mem[back + 6]) << 0x10 | uint(c2da_mem[back + 7]) << 0x18)
        let c2da_fresh24 : uint = uint(c2da_fresh23)
        c2da_mem[49664] = uint8(c2da_fresh24)
        c2da_mem[49665] = uint8(c2da_fresh24 >> 0x8)
        c2da_mem[49666] = uint8(c2da_fresh24 >> 0x10)
        c2da_mem[49667] = uint8(c2da_fresh24 >> 0x18)
    }
    if (int(uint(c2da_mem[front]) | uint(c2da_mem[front + 1]) << 0x8 | uint(c2da_mem[front + 2]) << 0x10 | uint(c2da_mem[front + 3]) << 0x18) > int(uint(c2da_mem[back]) | uint(c2da_mem[back + 1]) << 0x8 | uint(c2da_mem[back + 2]) << 0x10 | uint(c2da_mem[back + 3]) << 0x18)) {
        let c2da_fresh25 : int = int(uint(c2da_mem[front]) | uint(c2da_mem[front + 1]) << 0x8 | uint(c2da_mem[front + 2]) << 0x10 | uint(c2da_mem[front + 3]) << 0x18)
        let c2da_fresh26 : uint = uint(c2da_fresh25)
        c2da_mem[49648] = uint8(c2da_fresh26)
        c2da_mem[49649] = uint8(c2da_fresh26 >> 0x8)
        c2da_mem[49650] = uint8(c2da_fresh26 >> 0x10)
        c2da_mem[49651] = uint8(c2da_fresh26 >> 0x18)
        let c2da_fresh27 : int = int(uint(c2da_mem[back]) | uint(c2da_mem[back + 1]) << 0x8 | uint(c2da_mem[back + 2]) << 0x10 | uint(c2da_mem[back + 3]) << 0x18)
        let c2da_fresh28 : uint = uint(c2da_fresh27)
        c2da_mem[49632] = uint8(c2da_fresh28)
        c2da_mem[49633] = uint8(c2da_fresh28 >> 0x8)
        c2da_mem[49634] = uint8(c2da_fresh28 >> 0x10)
        c2da_mem[49635] = uint8(c2da_fresh28 >> 0x18)
    } else {
        let c2da_fresh29 : int = int(uint(c2da_mem[back]) | uint(c2da_mem[back + 1]) << 0x8 | uint(c2da_mem[back + 2]) << 0x10 | uint(c2da_mem[back + 3]) << 0x18)
        let c2da_fresh30 : uint = uint(c2da_fresh29)
        c2da_mem[49648] = uint8(c2da_fresh30)
        c2da_mem[49649] = uint8(c2da_fresh30 >> 0x8)
        c2da_mem[49650] = uint8(c2da_fresh30 >> 0x10)
        c2da_mem[49651] = uint8(c2da_fresh30 >> 0x18)
        let c2da_fresh31 : int = int(uint(c2da_mem[front]) | uint(c2da_mem[front + 1]) << 0x8 | uint(c2da_mem[front + 2]) << 0x10 | uint(c2da_mem[front + 3]) << 0x18)
        let c2da_fresh32 : uint = uint(c2da_fresh31)
        c2da_mem[49632] = uint8(c2da_fresh32)
        c2da_mem[49633] = uint8(c2da_fresh32 >> 0x8)
        c2da_mem[49634] = uint8(c2da_fresh32 >> 0x10)
        c2da_mem[49635] = uint8(c2da_fresh32 >> 0x18)
    }
    let c2da_fresh33 : int = int(uint(c2da_mem[49664]) | uint(c2da_mem[49665]) << 0x8 | uint(c2da_mem[49666]) << 0x10 | uint(c2da_mem[49667]) << 0x18) - int(uint(c2da_mem[49648]) | uint(c2da_mem[49649]) << 0x8 | uint(c2da_mem[49650]) << 0x10 | uint(c2da_mem[49651]) << 0x18)
    let c2da_fresh34 : uint = uint(c2da_fresh33)
    c2da_mem[49680] = uint8(c2da_fresh34)
    c2da_mem[49681] = uint8(c2da_fresh34 >> 0x8)
    c2da_mem[49682] = uint8(c2da_fresh34 >> 0x10)
    c2da_mem[49683] = uint8(c2da_fresh34 >> 0x18)
    return
}
[export, sideeffects]
def P_BlockLinesIterator(var x_1 : int; var y_1 : int; var func : int) : uint {
    var offset : int
    var list : int
    var ld_0 : int
    if (x_1 < 0 || y_1 < 0 || x_1 >= int(uint(c2da_mem[49712]) | uint(c2da_mem[49713]) << 0x8 | uint(c2da_mem[49714]) << 0x10 | uint(c2da_mem[49715]) << 0x18) || y_1 >= int(uint(c2da_mem[49760]) | uint(c2da_mem[49761]) << 0x8 | uint(c2da_mem[49762]) << 0x10 | uint(c2da_mem[49763]) << 0x18)) {
        return 1u
    }
    offset = y_1 * int(uint(c2da_mem[49712]) | uint(c2da_mem[49713]) << 0x8 | uint(c2da_mem[49714]) << 0x10 | uint(c2da_mem[49715]) << 0x18) + x_1
    list = blockmaplump + int(int16(uint(c2da_mem[blockmap + offset * 2]) | uint(c2da_mem[blockmap + offset * 2 + 1]) << 0x8)) * 2
    while (int(int16(uint(c2da_mem[list]) | uint(c2da_mem[list + 1]) << 0x8)) != -1) {
        ld_0 = lines + int(int16(uint(c2da_mem[list]) | uint(c2da_mem[list + 1]) << 0x8)) * 88
        if (int(uint(c2da_mem[ld_0 + 72]) | uint(c2da_mem[ld_0 + 73]) << 0x8 | uint(c2da_mem[ld_0 + 74]) << 0x10 | uint(c2da_mem[ld_0 + 75]) << 0x18) == validcount) {
            list += 2
            continue
        }
        let c2da_fresh35 : uint = uint(validcount)
        c2da_mem[ld_0 + 72] = uint8(c2da_fresh35)
        c2da_mem[ld_0 + 73] = uint8(c2da_fresh35 >> 0x8)
        c2da_mem[ld_0 + 74] = uint8(c2da_fresh35 >> 0x10)
        c2da_mem[ld_0 + 75] = uint8(c2da_fresh35 >> 0x18)
        if (invoke(c2da_fn_table10[func], ld_0) == 0) {
            return 0u
        }
        list += 2
    }
    return 1u
}
[export, sideeffects]
def P_BlockThingsIterator(var x_2 : int; var y_3 : int; var func_0 : int) : uint {
    var mobj : int
    if (x_2 < 0 || y_3 < 0 || x_2 >= int(uint(c2da_mem[49712]) | uint(c2da_mem[49713]) << 0x8 | uint(c2da_mem[49714]) << 0x10 | uint(c2da_mem[49715]) << 0x18) || y_3 >= int(uint(c2da_mem[49760]) | uint(c2da_mem[49761]) << 0x8 | uint(c2da_mem[49762]) << 0x10 | uint(c2da_mem[49763]) << 0x18)) {
        return 1u
    }
    let c2da_fresh36 : int = blocklinks + (y_3 * int(uint(c2da_mem[49712]) | uint(c2da_mem[49713]) << 0x8 | uint(c2da_mem[49714]) << 0x10 | uint(c2da_mem[49715]) << 0x18) + x_2) * 8
    mobj = int(uint(c2da_mem[c2da_fresh36]) | uint(c2da_mem[c2da_fresh36 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh36 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh36 + 3]) << 0x18)
    while (mobj != 0) {
        if (invoke(c2da_fn_table10[func_0], mobj) == 0) {
            return 0u
        }
        mobj = int(uint(c2da_mem[mobj + 72]) | uint(c2da_mem[mobj + 73]) << 0x8 | uint(c2da_mem[mobj + 74]) << 0x10 | uint(c2da_mem[mobj + 75]) << 0x18)
    }
    return 1u
}
[export, sideeffects]
def P_PathTraverse(var x1 : int; var y1 : int; var x2 : int; var y2 : int; var flags : int; var trav : int) : uint {
    var xt1 : int
    var yt1 : int
    var xt2 : int
    var yt2 : int
    var xstep : int
    var ystep : int
    var partial : int
    var xintercept : int
    var yintercept : int
    var mapx : int
    var mapy : int
    var mapxstep : int
    var mapystep : int
    earlyout = uint(flags & 4)
    validcount = validcount + 1
    intercept_p = 46592
    if ((x1 - int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18) & 128 * (1 << 16) - 1) == 0) {
        x1 += 1 << 16
    }
    if ((y1 - int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18) & 128 * (1 << 16) - 1) == 0) {
        y1 += 1 << 16
    }
    let c2da_fresh37 : uint = uint(x1)
    c2da_mem[49616] = uint8(c2da_fresh37)
    c2da_mem[49617] = uint8(c2da_fresh37 >> 0x8)
    c2da_mem[49618] = uint8(c2da_fresh37 >> 0x10)
    c2da_mem[49619] = uint8(c2da_fresh37 >> 0x18)
    let c2da_fresh38 : uint = uint(y1)
    c2da_mem[49620] = uint8(c2da_fresh38)
    c2da_mem[49621] = uint8(c2da_fresh38 >> 0x8)
    c2da_mem[49622] = uint8(c2da_fresh38 >> 0x10)
    c2da_mem[49623] = uint8(c2da_fresh38 >> 0x18)
    let c2da_fresh39 : int = x2 - x1
    let c2da_fresh40 : uint = uint(c2da_fresh39)
    c2da_mem[49624] = uint8(c2da_fresh40)
    c2da_mem[49625] = uint8(c2da_fresh40 >> 0x8)
    c2da_mem[49626] = uint8(c2da_fresh40 >> 0x10)
    c2da_mem[49627] = uint8(c2da_fresh40 >> 0x18)
    let c2da_fresh41 : int = y2 - y1
    let c2da_fresh42 : uint = uint(c2da_fresh41)
    c2da_mem[49628] = uint8(c2da_fresh42)
    c2da_mem[49629] = uint8(c2da_fresh42 >> 0x8)
    c2da_mem[49630] = uint8(c2da_fresh42 >> 0x10)
    c2da_mem[49631] = uint8(c2da_fresh42 >> 0x18)
    x1 -= int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18)
    y1 -= int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18)
    xt1 = x1 >> 16 + 7
    yt1 = y1 >> 16 + 7
    x2 -= int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18)
    y2 -= int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18)
    xt2 = x2 >> 16 + 7
    yt2 = y2 >> 16 + 7
    if (xt2 > xt1) {
        mapxstep = 1
        partial = (1 << 16) - (x1 >> 16 + 7 - 16 & (1 << 16) - 1)
        ystep = FixedDiv(y2 - y1, c2da_std_abs(x2 - x1))
    } elif (xt2 < xt1) {
        mapxstep = -1
        partial = x1 >> 16 + 7 - 16 & (1 << 16) - 1
        ystep = FixedDiv(y2 - y1, c2da_std_abs(x2 - x1))
    } else {
        mapxstep = 0
        partial = 1 << 16
        ystep = 256 * (1 << 16)
    }
    yintercept = (y1 >> 16 + 7 - 16) + FixedMul(partial, ystep)
    if (yt2 > yt1) {
        mapystep = 1
        partial = (1 << 16) - (y1 >> 16 + 7 - 16 & (1 << 16) - 1)
        xstep = FixedDiv(x2 - x1, c2da_std_abs(y2 - y1))
    } elif (yt2 < yt1) {
        mapystep = -1
        partial = y1 >> 16 + 7 - 16 & (1 << 16) - 1
        xstep = FixedDiv(x2 - x1, c2da_std_abs(y2 - y1))
    } else {
        mapystep = 0
        partial = 1 << 16
        xstep = 256 * (1 << 16)
    }
    xintercept = (x1 >> 16 + 7 - 16) + FixedMul(partial, xstep)
    mapx = xt1
    mapy = yt1
    for (count in range(0, 64)) {
        if ((flags & 1) != 0) {
            if (P_BlockLinesIterator(mapx, mapy, 142) == 0) {
                return 0u
            }
        }
        if ((flags & 2) != 0) {
            if (P_BlockThingsIterator(mapx, mapy, 143) == 0) {
                return 0u
            }
        }
        if (mapx == xt2 && mapy == yt2) {
            break
        }
        if (yintercept >> 16 == mapy) {
            yintercept += ystep
            mapx += mapxstep
        } elif (xintercept >> 16 == mapx) {
            xintercept += xstep
            mapy += mapystep
        }
    }
    return P_TraverseIntercepts(trav, 1 << 16)
}
[export, sideeffects]
def P_TraverseIntercepts(var func_1 : traverser_t; var maxfrac : int) : uint {
    var count_0 : int
    var dist : int
    var scan : int
    var in_0 : int
    count_0 = (intercept_p - 46592) / 16
    in_0 = 0
    while (true) {
        let c2da_postinc : int = count_0
        count_0--
        if (c2da_postinc == 0) {
            break
        }
        dist = 2147483647
        scan = 46592
        while (scan < intercept_p) {
            if (int(uint(c2da_mem[scan]) | uint(c2da_mem[scan + 1]) << 0x8 | uint(c2da_mem[scan + 2]) << 0x10 | uint(c2da_mem[scan + 3]) << 0x18) < dist) {
                dist = int(uint(c2da_mem[scan]) | uint(c2da_mem[scan + 1]) << 0x8 | uint(c2da_mem[scan + 2]) << 0x10 | uint(c2da_mem[scan + 3]) << 0x18)
                in_0 = scan
            }
            scan += 16
        }
        if (dist > maxfrac) {
            return 1u
        }
        if (invoke(c2da_fn_table10[func_1], in_0) == 0) {
            return 0u
        }
        let c2da_fresh43 : int = 2147483647
        let c2da_fresh44 : uint = uint(c2da_fresh43)
        c2da_mem[in_0] = uint8(c2da_fresh44)
        c2da_mem[in_0 + 1] = uint8(c2da_fresh44 >> 0x8)
        c2da_mem[in_0 + 2] = uint8(c2da_fresh44 >> 0x10)
        c2da_mem[in_0 + 3] = uint8(c2da_fresh44 >> 0x18)
    }
    return 1u
}
[export, sideeffects]
def PIT_AddThingIntercepts(var thing : int) : uint {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : uint = PIT_AddThingIntercepts_c2da_frame(thing, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[sideeffects]
def private InterceptsOverrun(var num_intercepts : int; var intercept : int) {
    var location : int
    if (num_intercepts <= 128) {
        return
    }
    location = (num_intercepts - 128 - 1) * 12
    InterceptsMemoryOverrun(location, int(uint(c2da_mem[intercept]) | uint(c2da_mem[intercept + 1]) << 0x8 | uint(c2da_mem[intercept + 2]) << 0x10 | uint(c2da_mem[intercept + 3]) << 0x18))
    InterceptsMemoryOverrun(location + 4, int(uint(c2da_mem[intercept + 4]) | uint(c2da_mem[intercept + 5]) << 0x8 | uint(c2da_mem[intercept + 6]) << 0x10 | uint(c2da_mem[intercept + 7]) << 0x18))
    InterceptsMemoryOverrun(location + 8, int(uint(c2da_mem[intercept + 8]) | uint(c2da_mem[intercept + 9]) << 0x8 | uint(c2da_mem[intercept + 10]) << 0x10 | uint(c2da_mem[intercept + 11]) << 0x18))
    return
}
[sideeffects]
def private InterceptsMemoryOverrun(var location_0 : int; var value : int) {
    var i : int
    var offset_0 : int
    var index : int
    var addr_0 : int
    i = 0
    offset_0 = 0
    while (intercepts_overrun[i].len != 0) {
        if (offset_0 + intercepts_overrun[i].len > location_0) {
            addr_0 = intercepts_overrun[i].addr_0
            if (addr_0 != 0) {
                if (intercepts_overrun[i].int16_array != 0x0) {
                    index = (location_0 - offset_0) / 2
                    let c2da_fresh55 : int16 = int16(value & 65535)
                    let c2da_fresh56 : uint = uint(c2da_fresh55)
                    c2da_mem[addr_0 + index * 2] = uint8(c2da_fresh56)
                    c2da_mem[addr_0 + index * 2 + 1] = uint8(c2da_fresh56 >> 0x8)
                    let c2da_fresh57 : int16 = int16(value >> 16 & 65535)
                    let c2da_fresh58 : uint = uint(c2da_fresh57)
                    c2da_mem[addr_0 + (index + 1) * 2] = uint8(c2da_fresh58)
                    c2da_mem[addr_0 + (index + 1) * 2 + 1] = uint8(c2da_fresh58 >> 0x8)
                } else {
                    index = (location_0 - offset_0) / 4
                    let c2da_fresh59 : uint = uint(value)
                    c2da_mem[addr_0 + index * 4] = uint8(c2da_fresh59)
                    c2da_mem[addr_0 + index * 4 + 1] = uint8(c2da_fresh59 >> 0x8)
                    c2da_mem[addr_0 + index * 4 + 2] = uint8(c2da_fresh59 >> 0x10)
                    c2da_mem[addr_0 + index * 4 + 3] = uint8(c2da_fresh59 >> 0x18)
                }
            }
            break
        }
        offset_0 += intercepts_overrun[i].len
        i++
    }
    return
}
var private intercepts_overrun : intercepts_overrun_t[23] = fixed_array<intercepts_overrun_t>(intercepts_overrun_t(len = 4, addr_0 = 0, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = 0, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = 0, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = 49632, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = 49648, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = 49664, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = 49680, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = 0, int16_array = 0u), intercepts_overrun_t(len = 120, addr_0 = 0, int16_array = 0u), intercepts_overrun_t(len = 8, addr_0 = 0, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = 49696, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = 0, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = 0, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = 0, int16_array = 0u), intercepts_overrun_t(len = 40, addr_0 = 40880, int16_array = 1u), intercepts_overrun_t(len = 4, addr_0 = 0, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = 49712, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = 0, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = 49728, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = 49744, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = 0, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = 49760, int16_array = 0u), intercepts_overrun_t(len = 0, addr_0 = 0, int16_array = 0u))

[export, sideeffects]
def PIT_AddLineIntercepts(var ld_1 : int) : uint {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : uint = PIT_AddLineIntercepts_c2da_frame(ld_1, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
var earlyout : uint = default<uint>

[export, sideeffects]
def P_UnsetThingPosition(var thing_0 : int) {
    var blockx : int
    var blocky : int
    if ((int(uint(c2da_mem[thing_0 + 160]) | uint(c2da_mem[thing_0 + 161]) << 0x8 | uint(c2da_mem[thing_0 + 162]) << 0x10 | uint(c2da_mem[thing_0 + 163]) << 0x18) & 8) == 0) {
        if (int(uint(c2da_mem[thing_0 + 40]) | uint(c2da_mem[thing_0 + 41]) << 0x8 | uint(c2da_mem[thing_0 + 42]) << 0x10 | uint(c2da_mem[thing_0 + 43]) << 0x18) != 0) {
            let c2da_fresh68 : int = int(uint(c2da_mem[thing_0 + 40]) | uint(c2da_mem[thing_0 + 41]) << 0x8 | uint(c2da_mem[thing_0 + 42]) << 0x10 | uint(c2da_mem[thing_0 + 43]) << 0x18) + 48
            let c2da_fresh69 : int = int(uint(c2da_mem[thing_0 + 48]) | uint(c2da_mem[thing_0 + 49]) << 0x8 | uint(c2da_mem[thing_0 + 50]) << 0x10 | uint(c2da_mem[thing_0 + 51]) << 0x18)
            let c2da_fresh70 : uint = uint(c2da_fresh69)
            c2da_mem[c2da_fresh68] = uint8(c2da_fresh70)
            c2da_mem[c2da_fresh68 + 1] = uint8(c2da_fresh70 >> 0x8)
            c2da_mem[c2da_fresh68 + 2] = uint8(c2da_fresh70 >> 0x10)
            c2da_mem[c2da_fresh68 + 3] = uint8(c2da_fresh70 >> 0x18)
            c2da_mem[c2da_fresh68 + 4] = 0u8
            c2da_mem[c2da_fresh68 + 5] = 0u8
            c2da_mem[c2da_fresh68 + 6] = 0u8
            c2da_mem[c2da_fresh68 + 7] = 0u8
        }
        if (int(uint(c2da_mem[thing_0 + 48]) | uint(c2da_mem[thing_0 + 49]) << 0x8 | uint(c2da_mem[thing_0 + 50]) << 0x10 | uint(c2da_mem[thing_0 + 51]) << 0x18) != 0) {
            let c2da_fresh71 : int = int(uint(c2da_mem[thing_0 + 48]) | uint(c2da_mem[thing_0 + 49]) << 0x8 | uint(c2da_mem[thing_0 + 50]) << 0x10 | uint(c2da_mem[thing_0 + 51]) << 0x18) + 40
            let c2da_fresh72 : int = int(uint(c2da_mem[thing_0 + 40]) | uint(c2da_mem[thing_0 + 41]) << 0x8 | uint(c2da_mem[thing_0 + 42]) << 0x10 | uint(c2da_mem[thing_0 + 43]) << 0x18)
            let c2da_fresh73 : uint = uint(c2da_fresh72)
            c2da_mem[c2da_fresh71] = uint8(c2da_fresh73)
            c2da_mem[c2da_fresh71 + 1] = uint8(c2da_fresh73 >> 0x8)
            c2da_mem[c2da_fresh71 + 2] = uint8(c2da_fresh73 >> 0x10)
            c2da_mem[c2da_fresh71 + 3] = uint8(c2da_fresh73 >> 0x18)
            c2da_mem[c2da_fresh71 + 4] = 0u8
            c2da_mem[c2da_fresh71 + 5] = 0u8
            c2da_mem[c2da_fresh71 + 6] = 0u8
            c2da_mem[c2da_fresh71 + 7] = 0u8
        } else {
            let c2da_fresh74 : int = int(uint(c2da_mem[thing_0 + 88]) | uint(c2da_mem[thing_0 + 89]) << 0x8 | uint(c2da_mem[thing_0 + 90]) << 0x10 | uint(c2da_mem[thing_0 + 91]) << 0x18)
            let c2da_fresh75 : int = int(uint(c2da_mem[c2da_fresh74]) | uint(c2da_mem[c2da_fresh74 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh74 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh74 + 3]) << 0x18) + 96
            let c2da_fresh76 : int = int(uint(c2da_mem[thing_0 + 40]) | uint(c2da_mem[thing_0 + 41]) << 0x8 | uint(c2da_mem[thing_0 + 42]) << 0x10 | uint(c2da_mem[thing_0 + 43]) << 0x18)
            let c2da_fresh77 : uint = uint(c2da_fresh76)
            c2da_mem[c2da_fresh75] = uint8(c2da_fresh77)
            c2da_mem[c2da_fresh75 + 1] = uint8(c2da_fresh77 >> 0x8)
            c2da_mem[c2da_fresh75 + 2] = uint8(c2da_fresh77 >> 0x10)
            c2da_mem[c2da_fresh75 + 3] = uint8(c2da_fresh77 >> 0x18)
            c2da_mem[c2da_fresh75 + 4] = 0u8
            c2da_mem[c2da_fresh75 + 5] = 0u8
            c2da_mem[c2da_fresh75 + 6] = 0u8
            c2da_mem[c2da_fresh75 + 7] = 0u8
        }
    }
    if ((int(uint(c2da_mem[thing_0 + 160]) | uint(c2da_mem[thing_0 + 161]) << 0x8 | uint(c2da_mem[thing_0 + 162]) << 0x10 | uint(c2da_mem[thing_0 + 163]) << 0x18) & 16) == 0) {
        if (int(uint(c2da_mem[thing_0 + 72]) | uint(c2da_mem[thing_0 + 73]) << 0x8 | uint(c2da_mem[thing_0 + 74]) << 0x10 | uint(c2da_mem[thing_0 + 75]) << 0x18) != 0) {
            let c2da_fresh78 : int = int(uint(c2da_mem[thing_0 + 72]) | uint(c2da_mem[thing_0 + 73]) << 0x8 | uint(c2da_mem[thing_0 + 74]) << 0x10 | uint(c2da_mem[thing_0 + 75]) << 0x18) + 80
            let c2da_fresh79 : int = int(uint(c2da_mem[thing_0 + 80]) | uint(c2da_mem[thing_0 + 81]) << 0x8 | uint(c2da_mem[thing_0 + 82]) << 0x10 | uint(c2da_mem[thing_0 + 83]) << 0x18)
            let c2da_fresh80 : uint = uint(c2da_fresh79)
            c2da_mem[c2da_fresh78] = uint8(c2da_fresh80)
            c2da_mem[c2da_fresh78 + 1] = uint8(c2da_fresh80 >> 0x8)
            c2da_mem[c2da_fresh78 + 2] = uint8(c2da_fresh80 >> 0x10)
            c2da_mem[c2da_fresh78 + 3] = uint8(c2da_fresh80 >> 0x18)
            c2da_mem[c2da_fresh78 + 4] = 0u8
            c2da_mem[c2da_fresh78 + 5] = 0u8
            c2da_mem[c2da_fresh78 + 6] = 0u8
            c2da_mem[c2da_fresh78 + 7] = 0u8
        }
        if (int(uint(c2da_mem[thing_0 + 80]) | uint(c2da_mem[thing_0 + 81]) << 0x8 | uint(c2da_mem[thing_0 + 82]) << 0x10 | uint(c2da_mem[thing_0 + 83]) << 0x18) != 0) {
            let c2da_fresh81 : int = int(uint(c2da_mem[thing_0 + 80]) | uint(c2da_mem[thing_0 + 81]) << 0x8 | uint(c2da_mem[thing_0 + 82]) << 0x10 | uint(c2da_mem[thing_0 + 83]) << 0x18) + 72
            let c2da_fresh82 : int = int(uint(c2da_mem[thing_0 + 72]) | uint(c2da_mem[thing_0 + 73]) << 0x8 | uint(c2da_mem[thing_0 + 74]) << 0x10 | uint(c2da_mem[thing_0 + 75]) << 0x18)
            let c2da_fresh83 : uint = uint(c2da_fresh82)
            c2da_mem[c2da_fresh81] = uint8(c2da_fresh83)
            c2da_mem[c2da_fresh81 + 1] = uint8(c2da_fresh83 >> 0x8)
            c2da_mem[c2da_fresh81 + 2] = uint8(c2da_fresh83 >> 0x10)
            c2da_mem[c2da_fresh81 + 3] = uint8(c2da_fresh83 >> 0x18)
            c2da_mem[c2da_fresh81 + 4] = 0u8
            c2da_mem[c2da_fresh81 + 5] = 0u8
            c2da_mem[c2da_fresh81 + 6] = 0u8
            c2da_mem[c2da_fresh81 + 7] = 0u8
        } else {
            blockx = int(uint(c2da_mem[thing_0 + 24]) | uint(c2da_mem[thing_0 + 25]) << 0x8 | uint(c2da_mem[thing_0 + 26]) << 0x10 | uint(c2da_mem[thing_0 + 27]) << 0x18) - int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18) >> 16 + 7
            blocky = int(uint(c2da_mem[thing_0 + 28]) | uint(c2da_mem[thing_0 + 29]) << 0x8 | uint(c2da_mem[thing_0 + 30]) << 0x10 | uint(c2da_mem[thing_0 + 31]) << 0x18) - int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18) >> 16 + 7
            if (blockx >= 0 && blockx < int(uint(c2da_mem[49712]) | uint(c2da_mem[49713]) << 0x8 | uint(c2da_mem[49714]) << 0x10 | uint(c2da_mem[49715]) << 0x18) && blocky >= 0 && blocky < int(uint(c2da_mem[49760]) | uint(c2da_mem[49761]) << 0x8 | uint(c2da_mem[49762]) << 0x10 | uint(c2da_mem[49763]) << 0x18)) {
                let c2da_fresh84 : int = blocklinks + (blocky * int(uint(c2da_mem[49712]) | uint(c2da_mem[49713]) << 0x8 | uint(c2da_mem[49714]) << 0x10 | uint(c2da_mem[49715]) << 0x18) + blockx) * 8
                let c2da_fresh85 : int = int(uint(c2da_mem[thing_0 + 72]) | uint(c2da_mem[thing_0 + 73]) << 0x8 | uint(c2da_mem[thing_0 + 74]) << 0x10 | uint(c2da_mem[thing_0 + 75]) << 0x18)
                let c2da_fresh86 : uint = uint(c2da_fresh85)
                c2da_mem[c2da_fresh84] = uint8(c2da_fresh86)
                c2da_mem[c2da_fresh84 + 1] = uint8(c2da_fresh86 >> 0x8)
                c2da_mem[c2da_fresh84 + 2] = uint8(c2da_fresh86 >> 0x10)
                c2da_mem[c2da_fresh84 + 3] = uint8(c2da_fresh86 >> 0x18)
                c2da_mem[c2da_fresh84 + 4] = 0u8
                c2da_mem[c2da_fresh84 + 5] = 0u8
                c2da_mem[c2da_fresh84 + 6] = 0u8
                c2da_mem[c2da_fresh84 + 7] = 0u8
            }
        }
    }
    return
}
[export, sideeffects]
def P_SetThingPosition(var thing_1 : int) {
    var ss : int
    var sec : int
    var blockx_0 : int
    var blocky_0 : int
    var link : int
    ss = R_PointInSubsector(int(uint(c2da_mem[thing_1 + 24]) | uint(c2da_mem[thing_1 + 25]) << 0x8 | uint(c2da_mem[thing_1 + 26]) << 0x10 | uint(c2da_mem[thing_1 + 27]) << 0x18), int(uint(c2da_mem[thing_1 + 28]) | uint(c2da_mem[thing_1 + 29]) << 0x8 | uint(c2da_mem[thing_1 + 30]) << 0x10 | uint(c2da_mem[thing_1 + 31]) << 0x18))
    let c2da_fresh87 : uint = uint(ss)
    c2da_mem[thing_1 + 88] = uint8(c2da_fresh87)
    c2da_mem[thing_1 + 89] = uint8(c2da_fresh87 >> 0x8)
    c2da_mem[thing_1 + 90] = uint8(c2da_fresh87 >> 0x10)
    c2da_mem[thing_1 + 91] = uint8(c2da_fresh87 >> 0x18)
    c2da_mem[thing_1 + 92] = 0u8
    c2da_mem[thing_1 + 93] = 0u8
    c2da_mem[thing_1 + 94] = 0u8
    c2da_mem[thing_1 + 95] = 0u8
    if ((int(uint(c2da_mem[thing_1 + 160]) | uint(c2da_mem[thing_1 + 161]) << 0x8 | uint(c2da_mem[thing_1 + 162]) << 0x10 | uint(c2da_mem[thing_1 + 163]) << 0x18) & 8) == 0) {
        sec = int(uint(c2da_mem[ss]) | uint(c2da_mem[ss + 1]) << 0x8 | uint(c2da_mem[ss + 2]) << 0x10 | uint(c2da_mem[ss + 3]) << 0x18)
        let c2da_fresh88 : uint = 0u
        c2da_mem[thing_1 + 48] = uint8(c2da_fresh88)
        c2da_mem[thing_1 + 49] = uint8(c2da_fresh88 >> 0x8)
        c2da_mem[thing_1 + 50] = uint8(c2da_fresh88 >> 0x10)
        c2da_mem[thing_1 + 51] = uint8(c2da_fresh88 >> 0x18)
        c2da_mem[thing_1 + 52] = 0u8
        c2da_mem[thing_1 + 53] = 0u8
        c2da_mem[thing_1 + 54] = 0u8
        c2da_mem[thing_1 + 55] = 0u8
        let c2da_fresh89 : int = int(uint(c2da_mem[sec + 96]) | uint(c2da_mem[sec + 97]) << 0x8 | uint(c2da_mem[sec + 98]) << 0x10 | uint(c2da_mem[sec + 99]) << 0x18)
        let c2da_fresh90 : uint = uint(c2da_fresh89)
        c2da_mem[thing_1 + 40] = uint8(c2da_fresh90)
        c2da_mem[thing_1 + 41] = uint8(c2da_fresh90 >> 0x8)
        c2da_mem[thing_1 + 42] = uint8(c2da_fresh90 >> 0x10)
        c2da_mem[thing_1 + 43] = uint8(c2da_fresh90 >> 0x18)
        c2da_mem[thing_1 + 44] = 0u8
        c2da_mem[thing_1 + 45] = 0u8
        c2da_mem[thing_1 + 46] = 0u8
        c2da_mem[thing_1 + 47] = 0u8
        if (int(uint(c2da_mem[sec + 96]) | uint(c2da_mem[sec + 97]) << 0x8 | uint(c2da_mem[sec + 98]) << 0x10 | uint(c2da_mem[sec + 99]) << 0x18) != 0) {
            let c2da_fresh91 : int = int(uint(c2da_mem[sec + 96]) | uint(c2da_mem[sec + 97]) << 0x8 | uint(c2da_mem[sec + 98]) << 0x10 | uint(c2da_mem[sec + 99]) << 0x18) + 48
            let c2da_fresh92 : uint = uint(thing_1)
            c2da_mem[c2da_fresh91] = uint8(c2da_fresh92)
            c2da_mem[c2da_fresh91 + 1] = uint8(c2da_fresh92 >> 0x8)
            c2da_mem[c2da_fresh91 + 2] = uint8(c2da_fresh92 >> 0x10)
            c2da_mem[c2da_fresh91 + 3] = uint8(c2da_fresh92 >> 0x18)
            c2da_mem[c2da_fresh91 + 4] = 0u8
            c2da_mem[c2da_fresh91 + 5] = 0u8
            c2da_mem[c2da_fresh91 + 6] = 0u8
            c2da_mem[c2da_fresh91 + 7] = 0u8
        }
        let c2da_fresh93 : uint = uint(thing_1)
        c2da_mem[sec + 96] = uint8(c2da_fresh93)
        c2da_mem[sec + 97] = uint8(c2da_fresh93 >> 0x8)
        c2da_mem[sec + 98] = uint8(c2da_fresh93 >> 0x10)
        c2da_mem[sec + 99] = uint8(c2da_fresh93 >> 0x18)
        c2da_mem[sec + 100] = 0u8
        c2da_mem[sec + 101] = 0u8
        c2da_mem[sec + 102] = 0u8
        c2da_mem[sec + 103] = 0u8
    }
    if ((int(uint(c2da_mem[thing_1 + 160]) | uint(c2da_mem[thing_1 + 161]) << 0x8 | uint(c2da_mem[thing_1 + 162]) << 0x10 | uint(c2da_mem[thing_1 + 163]) << 0x18) & 16) == 0) {
        blockx_0 = int(uint(c2da_mem[thing_1 + 24]) | uint(c2da_mem[thing_1 + 25]) << 0x8 | uint(c2da_mem[thing_1 + 26]) << 0x10 | uint(c2da_mem[thing_1 + 27]) << 0x18) - int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18) >> 16 + 7
        blocky_0 = int(uint(c2da_mem[thing_1 + 28]) | uint(c2da_mem[thing_1 + 29]) << 0x8 | uint(c2da_mem[thing_1 + 30]) << 0x10 | uint(c2da_mem[thing_1 + 31]) << 0x18) - int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18) >> 16 + 7
        if (blockx_0 >= 0 && blockx_0 < int(uint(c2da_mem[49712]) | uint(c2da_mem[49713]) << 0x8 | uint(c2da_mem[49714]) << 0x10 | uint(c2da_mem[49715]) << 0x18) && blocky_0 >= 0 && blocky_0 < int(uint(c2da_mem[49760]) | uint(c2da_mem[49761]) << 0x8 | uint(c2da_mem[49762]) << 0x10 | uint(c2da_mem[49763]) << 0x18)) {
            link = blocklinks + (blocky_0 * int(uint(c2da_mem[49712]) | uint(c2da_mem[49713]) << 0x8 | uint(c2da_mem[49714]) << 0x10 | uint(c2da_mem[49715]) << 0x18) + blockx_0) * 8
            let c2da_fresh94 : uint = 0u
            c2da_mem[thing_1 + 80] = uint8(c2da_fresh94)
            c2da_mem[thing_1 + 81] = uint8(c2da_fresh94 >> 0x8)
            c2da_mem[thing_1 + 82] = uint8(c2da_fresh94 >> 0x10)
            c2da_mem[thing_1 + 83] = uint8(c2da_fresh94 >> 0x18)
            c2da_mem[thing_1 + 84] = 0u8
            c2da_mem[thing_1 + 85] = 0u8
            c2da_mem[thing_1 + 86] = 0u8
            c2da_mem[thing_1 + 87] = 0u8
            let c2da_fresh95 : int = int(uint(c2da_mem[link]) | uint(c2da_mem[link + 1]) << 0x8 | uint(c2da_mem[link + 2]) << 0x10 | uint(c2da_mem[link + 3]) << 0x18)
            let c2da_fresh96 : uint = uint(c2da_fresh95)
            c2da_mem[thing_1 + 72] = uint8(c2da_fresh96)
            c2da_mem[thing_1 + 73] = uint8(c2da_fresh96 >> 0x8)
            c2da_mem[thing_1 + 74] = uint8(c2da_fresh96 >> 0x10)
            c2da_mem[thing_1 + 75] = uint8(c2da_fresh96 >> 0x18)
            c2da_mem[thing_1 + 76] = 0u8
            c2da_mem[thing_1 + 77] = 0u8
            c2da_mem[thing_1 + 78] = 0u8
            c2da_mem[thing_1 + 79] = 0u8
            if (int(uint(c2da_mem[link]) | uint(c2da_mem[link + 1]) << 0x8 | uint(c2da_mem[link + 2]) << 0x10 | uint(c2da_mem[link + 3]) << 0x18) != 0) {
                let c2da_fresh97 : int = int(uint(c2da_mem[link]) | uint(c2da_mem[link + 1]) << 0x8 | uint(c2da_mem[link + 2]) << 0x10 | uint(c2da_mem[link + 3]) << 0x18) + 80
                let c2da_fresh98 : uint = uint(thing_1)
                c2da_mem[c2da_fresh97] = uint8(c2da_fresh98)
                c2da_mem[c2da_fresh97 + 1] = uint8(c2da_fresh98 >> 0x8)
                c2da_mem[c2da_fresh97 + 2] = uint8(c2da_fresh98 >> 0x10)
                c2da_mem[c2da_fresh97 + 3] = uint8(c2da_fresh98 >> 0x18)
                c2da_mem[c2da_fresh97 + 4] = 0u8
                c2da_mem[c2da_fresh97 + 5] = 0u8
                c2da_mem[c2da_fresh97 + 6] = 0u8
                c2da_mem[c2da_fresh97 + 7] = 0u8
            }
            let c2da_fresh99 : uint = uint(thing_1)
            c2da_mem[link] = uint8(c2da_fresh99)
            c2da_mem[link + 1] = uint8(c2da_fresh99 >> 0x8)
            c2da_mem[link + 2] = uint8(c2da_fresh99 >> 0x10)
            c2da_mem[link + 3] = uint8(c2da_fresh99 >> 0x18)
            c2da_mem[link + 4] = 0u8
            c2da_mem[link + 5] = 0u8
            c2da_mem[link + 6] = 0u8
            c2da_mem[link + 7] = 0u8
        } else {
            let c2da_fresh100 : uint = 0u
            c2da_mem[thing_1 + 80] = uint8(c2da_fresh100)
            c2da_mem[thing_1 + 81] = uint8(c2da_fresh100 >> 0x8)
            c2da_mem[thing_1 + 82] = uint8(c2da_fresh100 >> 0x10)
            c2da_mem[thing_1 + 83] = uint8(c2da_fresh100 >> 0x18)
            c2da_mem[thing_1 + 84] = 0u8
            c2da_mem[thing_1 + 85] = 0u8
            c2da_mem[thing_1 + 86] = 0u8
            c2da_mem[thing_1 + 87] = 0u8
            let c2da_fresh101 : uint = 0u
            c2da_mem[thing_1 + 72] = uint8(c2da_fresh101)
            c2da_mem[thing_1 + 73] = uint8(c2da_fresh101 >> 0x8)
            c2da_mem[thing_1 + 74] = uint8(c2da_fresh101 >> 0x10)
            c2da_mem[thing_1 + 75] = uint8(c2da_fresh101 >> 0x18)
            c2da_mem[thing_1 + 76] = 0u8
            c2da_mem[thing_1 + 77] = 0u8
            c2da_mem[thing_1 + 78] = 0u8
            c2da_mem[thing_1 + 79] = 0u8
        }
    }
    return
}
var ptflags : int = default<int>

[sideeffects]
def private PIT_AddThingIntercepts_c2da_frame(var thing : int; c2da_fp : int) : uint {
    var x1_0 : int
    var y1_0 : int
    var x2_0 : int
    var y2_0 : int
    var s1 : int
    var s2 : int
    var frac_0 : int
    if (uint((int(uint(c2da_mem[49624]) | uint(c2da_mem[49625]) << 0x8 | uint(c2da_mem[49626]) << 0x10 | uint(c2da_mem[49627]) << 0x18) ^ int(uint(c2da_mem[49628]) | uint(c2da_mem[49629]) << 0x8 | uint(c2da_mem[49630]) << 0x10 | uint(c2da_mem[49631]) << 0x18)) > 0 ? 1 : 0) != 0x0) {
        x1_0 = int(uint(c2da_mem[thing + 24]) | uint(c2da_mem[thing + 25]) << 0x8 | uint(c2da_mem[thing + 26]) << 0x10 | uint(c2da_mem[thing + 27]) << 0x18) - int(uint(c2da_mem[thing + 104]) | uint(c2da_mem[thing + 105]) << 0x8 | uint(c2da_mem[thing + 106]) << 0x10 | uint(c2da_mem[thing + 107]) << 0x18)
        y1_0 = int(uint(c2da_mem[thing + 28]) | uint(c2da_mem[thing + 29]) << 0x8 | uint(c2da_mem[thing + 30]) << 0x10 | uint(c2da_mem[thing + 31]) << 0x18) + int(uint(c2da_mem[thing + 104]) | uint(c2da_mem[thing + 105]) << 0x8 | uint(c2da_mem[thing + 106]) << 0x10 | uint(c2da_mem[thing + 107]) << 0x18)
        x2_0 = int(uint(c2da_mem[thing + 24]) | uint(c2da_mem[thing + 25]) << 0x8 | uint(c2da_mem[thing + 26]) << 0x10 | uint(c2da_mem[thing + 27]) << 0x18) + int(uint(c2da_mem[thing + 104]) | uint(c2da_mem[thing + 105]) << 0x8 | uint(c2da_mem[thing + 106]) << 0x10 | uint(c2da_mem[thing + 107]) << 0x18)
        y2_0 = int(uint(c2da_mem[thing + 28]) | uint(c2da_mem[thing + 29]) << 0x8 | uint(c2da_mem[thing + 30]) << 0x10 | uint(c2da_mem[thing + 31]) << 0x18) - int(uint(c2da_mem[thing + 104]) | uint(c2da_mem[thing + 105]) << 0x8 | uint(c2da_mem[thing + 106]) << 0x10 | uint(c2da_mem[thing + 107]) << 0x18)
    } else {
        x1_0 = int(uint(c2da_mem[thing + 24]) | uint(c2da_mem[thing + 25]) << 0x8 | uint(c2da_mem[thing + 26]) << 0x10 | uint(c2da_mem[thing + 27]) << 0x18) - int(uint(c2da_mem[thing + 104]) | uint(c2da_mem[thing + 105]) << 0x8 | uint(c2da_mem[thing + 106]) << 0x10 | uint(c2da_mem[thing + 107]) << 0x18)
        y1_0 = int(uint(c2da_mem[thing + 28]) | uint(c2da_mem[thing + 29]) << 0x8 | uint(c2da_mem[thing + 30]) << 0x10 | uint(c2da_mem[thing + 31]) << 0x18) - int(uint(c2da_mem[thing + 104]) | uint(c2da_mem[thing + 105]) << 0x8 | uint(c2da_mem[thing + 106]) << 0x10 | uint(c2da_mem[thing + 107]) << 0x18)
        x2_0 = int(uint(c2da_mem[thing + 24]) | uint(c2da_mem[thing + 25]) << 0x8 | uint(c2da_mem[thing + 26]) << 0x10 | uint(c2da_mem[thing + 27]) << 0x18) + int(uint(c2da_mem[thing + 104]) | uint(c2da_mem[thing + 105]) << 0x8 | uint(c2da_mem[thing + 106]) << 0x10 | uint(c2da_mem[thing + 107]) << 0x18)
        y2_0 = int(uint(c2da_mem[thing + 28]) | uint(c2da_mem[thing + 29]) << 0x8 | uint(c2da_mem[thing + 30]) << 0x10 | uint(c2da_mem[thing + 31]) << 0x18) + int(uint(c2da_mem[thing + 104]) | uint(c2da_mem[thing + 105]) << 0x8 | uint(c2da_mem[thing + 106]) << 0x10 | uint(c2da_mem[thing + 107]) << 0x18)
    }
    s1 = P_PointOnDivlineSide(x1_0, y1_0, 49616)
    s2 = P_PointOnDivlineSide(x2_0, y2_0, 49616)
    if (s1 == s2) {
        return 1u
    }
    let c2da_fresh45 : uint = uint(x1_0)
    c2da_mem[c2da_fp] = uint8(c2da_fresh45)
    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh45 >> 0x8)
    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh45 >> 0x10)
    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh45 >> 0x18)
    let c2da_fresh46 : uint = uint(y1_0)
    c2da_mem[c2da_fp + 4] = uint8(c2da_fresh46)
    c2da_mem[c2da_fp + 5] = uint8(c2da_fresh46 >> 0x8)
    c2da_mem[c2da_fp + 6] = uint8(c2da_fresh46 >> 0x10)
    c2da_mem[c2da_fp + 7] = uint8(c2da_fresh46 >> 0x18)
    let c2da_fresh47 : int = x2_0 - x1_0
    let c2da_fresh48 : uint = uint(c2da_fresh47)
    c2da_mem[c2da_fp + 8] = uint8(c2da_fresh48)
    c2da_mem[c2da_fp + 9] = uint8(c2da_fresh48 >> 0x8)
    c2da_mem[c2da_fp + 10] = uint8(c2da_fresh48 >> 0x10)
    c2da_mem[c2da_fp + 11] = uint8(c2da_fresh48 >> 0x18)
    let c2da_fresh49 : int = y2_0 - y1_0
    let c2da_fresh50 : uint = uint(c2da_fresh49)
    c2da_mem[c2da_fp + 12] = uint8(c2da_fresh50)
    c2da_mem[c2da_fp + 13] = uint8(c2da_fresh50 >> 0x8)
    c2da_mem[c2da_fp + 14] = uint8(c2da_fresh50 >> 0x10)
    c2da_mem[c2da_fp + 15] = uint8(c2da_fresh50 >> 0x18)
    frac_0 = P_InterceptVector(49616, c2da_fp)
    if (frac_0 < 0) {
        return 1u
    }
    let c2da_fresh51 : uint = uint(frac_0)
    c2da_mem[intercept_p] = uint8(c2da_fresh51)
    c2da_mem[intercept_p + 1] = uint8(c2da_fresh51 >> 0x8)
    c2da_mem[intercept_p + 2] = uint8(c2da_fresh51 >> 0x10)
    c2da_mem[intercept_p + 3] = uint8(c2da_fresh51 >> 0x18)
    let c2da_fresh52 : uint = 0u
    let c2da_fresh53 : uint = c2da_fresh52
    c2da_mem[intercept_p + 4] = uint8(c2da_fresh53)
    c2da_mem[intercept_p + 5] = uint8(c2da_fresh53 >> 0x8)
    c2da_mem[intercept_p + 6] = uint8(c2da_fresh53 >> 0x10)
    c2da_mem[intercept_p + 7] = uint8(c2da_fresh53 >> 0x18)
    let c2da_fresh54 : uint = uint(thing)
    c2da_mem[intercept_p + 8] = uint8(c2da_fresh54)
    c2da_mem[intercept_p + 9] = uint8(c2da_fresh54 >> 0x8)
    c2da_mem[intercept_p + 10] = uint8(c2da_fresh54 >> 0x10)
    c2da_mem[intercept_p + 11] = uint8(c2da_fresh54 >> 0x18)
    c2da_mem[intercept_p + 12] = 0u8
    c2da_mem[intercept_p + 13] = 0u8
    c2da_mem[intercept_p + 14] = 0u8
    c2da_mem[intercept_p + 15] = 0u8
    InterceptsOverrun((intercept_p - 46592) / 16, intercept_p)
    intercept_p += 16
    return 1u
}
[sideeffects]
def private PIT_AddLineIntercepts_c2da_frame(var ld_1 : int; c2da_fp : int) : uint {
    var s1_0 : int
    var s2_0 : int
    var frac_1 : int
    if (int(uint(c2da_mem[49624]) | uint(c2da_mem[49625]) << 0x8 | uint(c2da_mem[49626]) << 0x10 | uint(c2da_mem[49627]) << 0x18) > (1 << 16) * 16 || int(uint(c2da_mem[49628]) | uint(c2da_mem[49629]) << 0x8 | uint(c2da_mem[49630]) << 0x10 | uint(c2da_mem[49631]) << 0x18) > (1 << 16) * 16 || int(uint(c2da_mem[49624]) | uint(c2da_mem[49625]) << 0x8 | uint(c2da_mem[49626]) << 0x10 | uint(c2da_mem[49627]) << 0x18) < -(1 << 16) * 16 || int(uint(c2da_mem[49628]) | uint(c2da_mem[49629]) << 0x8 | uint(c2da_mem[49630]) << 0x10 | uint(c2da_mem[49631]) << 0x18) < -(1 << 16) * 16) {
        let c2da_fresh60 : int = int(uint(c2da_mem[ld_1]) | uint(c2da_mem[ld_1 + 1]) << 0x8 | uint(c2da_mem[ld_1 + 2]) << 0x10 | uint(c2da_mem[ld_1 + 3]) << 0x18)
        let c2da_fresh61 : int = int(uint(c2da_mem[ld_1]) | uint(c2da_mem[ld_1 + 1]) << 0x8 | uint(c2da_mem[ld_1 + 2]) << 0x10 | uint(c2da_mem[ld_1 + 3]) << 0x18) + 4
        s1_0 = P_PointOnDivlineSide(int(uint(c2da_mem[c2da_fresh60]) | uint(c2da_mem[c2da_fresh60 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh60 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh60 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh61]) | uint(c2da_mem[c2da_fresh61 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh61 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh61 + 3]) << 0x18), 49616)
        let c2da_fresh62 : int = int(uint(c2da_mem[ld_1 + 8]) | uint(c2da_mem[ld_1 + 9]) << 0x8 | uint(c2da_mem[ld_1 + 10]) << 0x10 | uint(c2da_mem[ld_1 + 11]) << 0x18)
        let c2da_fresh63 : int = int(uint(c2da_mem[ld_1 + 8]) | uint(c2da_mem[ld_1 + 9]) << 0x8 | uint(c2da_mem[ld_1 + 10]) << 0x10 | uint(c2da_mem[ld_1 + 11]) << 0x18) + 4
        s2_0 = P_PointOnDivlineSide(int(uint(c2da_mem[c2da_fresh62]) | uint(c2da_mem[c2da_fresh62 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh62 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh62 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh63]) | uint(c2da_mem[c2da_fresh63 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh63 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh63 + 3]) << 0x18), 49616)
    } else {
        s1_0 = P_PointOnLineSide(int(uint(c2da_mem[49616]) | uint(c2da_mem[49617]) << 0x8 | uint(c2da_mem[49618]) << 0x10 | uint(c2da_mem[49619]) << 0x18), int(uint(c2da_mem[49620]) | uint(c2da_mem[49621]) << 0x8 | uint(c2da_mem[49622]) << 0x10 | uint(c2da_mem[49623]) << 0x18), ld_1)
        s2_0 = P_PointOnLineSide(int(uint(c2da_mem[49616]) | uint(c2da_mem[49617]) << 0x8 | uint(c2da_mem[49618]) << 0x10 | uint(c2da_mem[49619]) << 0x18) + int(uint(c2da_mem[49624]) | uint(c2da_mem[49625]) << 0x8 | uint(c2da_mem[49626]) << 0x10 | uint(c2da_mem[49627]) << 0x18), int(uint(c2da_mem[49620]) | uint(c2da_mem[49621]) << 0x8 | uint(c2da_mem[49622]) << 0x10 | uint(c2da_mem[49623]) << 0x18) + int(uint(c2da_mem[49628]) | uint(c2da_mem[49629]) << 0x8 | uint(c2da_mem[49630]) << 0x10 | uint(c2da_mem[49631]) << 0x18), ld_1)
    }
    if (s1_0 == s2_0) {
        return 1u
    }
    P_MakeDivline(ld_1, c2da_fp)
    frac_1 = P_InterceptVector(49616, c2da_fp)
    if (frac_1 < 0) {
        return 1u
    }
    if (earlyout != 0x0 && frac_1 < 1 << 16 && int(uint(c2da_mem[ld_1 + 64]) | uint(c2da_mem[ld_1 + 65]) << 0x8 | uint(c2da_mem[ld_1 + 66]) << 0x10 | uint(c2da_mem[ld_1 + 67]) << 0x18) == 0) {
        return 0u
    }
    let c2da_fresh64 : uint = uint(frac_1)
    c2da_mem[intercept_p] = uint8(c2da_fresh64)
    c2da_mem[intercept_p + 1] = uint8(c2da_fresh64 >> 0x8)
    c2da_mem[intercept_p + 2] = uint8(c2da_fresh64 >> 0x10)
    c2da_mem[intercept_p + 3] = uint8(c2da_fresh64 >> 0x18)
    let c2da_fresh65 : uint = 1u
    let c2da_fresh66 : uint = c2da_fresh65
    c2da_mem[intercept_p + 4] = uint8(c2da_fresh66)
    c2da_mem[intercept_p + 5] = uint8(c2da_fresh66 >> 0x8)
    c2da_mem[intercept_p + 6] = uint8(c2da_fresh66 >> 0x10)
    c2da_mem[intercept_p + 7] = uint8(c2da_fresh66 >> 0x18)
    let c2da_fresh67 : uint = uint(ld_1)
    c2da_mem[intercept_p + 8] = uint8(c2da_fresh67)
    c2da_mem[intercept_p + 9] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[intercept_p + 10] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[intercept_p + 11] = uint8(c2da_fresh67 >> 0x18)
    c2da_mem[intercept_p + 12] = 0u8
    c2da_mem[intercept_p + 13] = 0u8
    c2da_mem[intercept_p + 14] = 0u8
    c2da_mem[intercept_p + 15] = 0u8
    InterceptsOverrun((intercept_p - 46592) / 16, intercept_p)
    intercept_p += 16
    return 1u
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_p_maputl() {
    if (length(c2da_fn_table10) < 144) {
        resize(c2da_fn_table10, 144)
    }
    c2da_fn_table10[143] = @@PIT_AddThingIntercepts
    c2da_fn_table10[142] = @@PIT_AddLineIntercepts
}

[init]
def private c2da_lin_relink_init_p_maputl() {
    c2da_relink_p_maputl()
}
