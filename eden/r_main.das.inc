[sideeffects]
def private c2da___bswap_16_12(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_12(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_12(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_12(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_12(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_12(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
var viewx : int = default<int>

var viewy : int = default<int>

var viewz : int = default<int>

var viewangle : uint = default<uint>

var viewplayer : int = default<int>

var clipangle : uint = default<uint>

var viewangletox : int[4096]

var xtoviewangle : uint[321]

var sscount : int = default<int>

var viewcos : int = default<int>

var viewsin : int = default<int>

var centerx : int = default<int>

var centery : int = default<int>

var centerxfrac : int = default<int>

var centeryfrac : int = default<int>

var projection : int = default<int>

var validcount : int = 1

var linecount : int = default<int>

var loopcount : int = default<int>

var extralight : int = default<int>

var fixedcolormap : int = default<int>

var detailshift : int = default<int>

var colfunc : int = default<int>

var transcolfunc : int = default<int>

var basecolfunc : int = default<int>

var fuzzcolfunc : int = default<int>

var spanfunc : int = default<int>

[export, sideeffects]
def R_PointOnSide(var x : int; var y : int; var node : int) : int {
    var dx : int
    var dy : int
    var left : int
    var right : int
    if (int(uint(c2da_mem[node + 8]) | uint(c2da_mem[node + 9]) << 0x8 | uint(c2da_mem[node + 10]) << 0x10 | uint(c2da_mem[node + 11]) << 0x18) == 0) {
        if (x <= int(uint(c2da_mem[node]) | uint(c2da_mem[node + 1]) << 0x8 | uint(c2da_mem[node + 2]) << 0x10 | uint(c2da_mem[node + 3]) << 0x18)) {
            return int(uint(c2da_mem[node + 12]) | uint(c2da_mem[node + 13]) << 0x8 | uint(c2da_mem[node + 14]) << 0x10 | uint(c2da_mem[node + 15]) << 0x18) > 0 ? 1 : 0
        }
        return int(uint(c2da_mem[node + 12]) | uint(c2da_mem[node + 13]) << 0x8 | uint(c2da_mem[node + 14]) << 0x10 | uint(c2da_mem[node + 15]) << 0x18) < 0 ? 1 : 0
    }
    if (int(uint(c2da_mem[node + 12]) | uint(c2da_mem[node + 13]) << 0x8 | uint(c2da_mem[node + 14]) << 0x10 | uint(c2da_mem[node + 15]) << 0x18) == 0) {
        if (y <= int(uint(c2da_mem[node + 4]) | uint(c2da_mem[node + 5]) << 0x8 | uint(c2da_mem[node + 6]) << 0x10 | uint(c2da_mem[node + 7]) << 0x18)) {
            return int(uint(c2da_mem[node + 8]) | uint(c2da_mem[node + 9]) << 0x8 | uint(c2da_mem[node + 10]) << 0x10 | uint(c2da_mem[node + 11]) << 0x18) < 0 ? 1 : 0
        }
        return int(uint(c2da_mem[node + 8]) | uint(c2da_mem[node + 9]) << 0x8 | uint(c2da_mem[node + 10]) << 0x10 | uint(c2da_mem[node + 11]) << 0x18) > 0 ? 1 : 0
    }
    dx = x - int(uint(c2da_mem[node]) | uint(c2da_mem[node + 1]) << 0x8 | uint(c2da_mem[node + 2]) << 0x10 | uint(c2da_mem[node + 3]) << 0x18)
    dy = y - int(uint(c2da_mem[node + 4]) | uint(c2da_mem[node + 5]) << 0x8 | uint(c2da_mem[node + 6]) << 0x10 | uint(c2da_mem[node + 7]) << 0x18)
    if ((uint(int(uint(c2da_mem[node + 12]) | uint(c2da_mem[node + 13]) << 0x8 | uint(c2da_mem[node + 14]) << 0x10 | uint(c2da_mem[node + 15]) << 0x18) ^ int(uint(c2da_mem[node + 8]) | uint(c2da_mem[node + 9]) << 0x8 | uint(c2da_mem[node + 10]) << 0x10 | uint(c2da_mem[node + 11]) << 0x18) ^ dx ^ dy) & 0x80000000u) != 0x0) {
        if ((uint(int(uint(c2da_mem[node + 12]) | uint(c2da_mem[node + 13]) << 0x8 | uint(c2da_mem[node + 14]) << 0x10 | uint(c2da_mem[node + 15]) << 0x18) ^ dx) & 0x80000000u) != 0x0) {
            return 1
        }
        return 0
    }
    left = FixedMul(int(uint(c2da_mem[node + 12]) | uint(c2da_mem[node + 13]) << 0x8 | uint(c2da_mem[node + 14]) << 0x10 | uint(c2da_mem[node + 15]) << 0x18) >> 16, dx)
    right = FixedMul(dy, int(uint(c2da_mem[node + 8]) | uint(c2da_mem[node + 9]) << 0x8 | uint(c2da_mem[node + 10]) << 0x10 | uint(c2da_mem[node + 11]) << 0x18) >> 16)
    if (right < left) {
        return 0
    }
    return 1
}
[export, sideeffects]
def R_PointOnSegSide(var x_0 : int; var y_0 : int; var line : int) : int {
    var lx : int
    var ly : int
    var ldx : int
    var ldy : int
    var dx_0 : int
    var dy_0 : int
    var left_0 : int
    var right_0 : int
    let c2da_fresh0 : int = int(uint(c2da_mem[line]) | uint(c2da_mem[line + 1]) << 0x8 | uint(c2da_mem[line + 2]) << 0x10 | uint(c2da_mem[line + 3]) << 0x18)
    lx = int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18)
    let c2da_fresh1 : int = int(uint(c2da_mem[line]) | uint(c2da_mem[line + 1]) << 0x8 | uint(c2da_mem[line + 2]) << 0x10 | uint(c2da_mem[line + 3]) << 0x18) + 4
    ly = int(uint(c2da_mem[c2da_fresh1]) | uint(c2da_mem[c2da_fresh1 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh1 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh1 + 3]) << 0x18)
    let c2da_fresh2 : int = int(uint(c2da_mem[line + 8]) | uint(c2da_mem[line + 9]) << 0x8 | uint(c2da_mem[line + 10]) << 0x10 | uint(c2da_mem[line + 11]) << 0x18)
    ldx = int(uint(c2da_mem[c2da_fresh2]) | uint(c2da_mem[c2da_fresh2 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh2 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh2 + 3]) << 0x18) - lx
    let c2da_fresh3 : int = int(uint(c2da_mem[line + 8]) | uint(c2da_mem[line + 9]) << 0x8 | uint(c2da_mem[line + 10]) << 0x10 | uint(c2da_mem[line + 11]) << 0x18) + 4
    ldy = int(uint(c2da_mem[c2da_fresh3]) | uint(c2da_mem[c2da_fresh3 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh3 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh3 + 3]) << 0x18) - ly
    if (ldx == 0) {
        if (x_0 <= lx) {
            return ldy > 0 ? 1 : 0
        }
        return ldy < 0 ? 1 : 0
    }
    if (ldy == 0) {
        if (y_0 <= ly) {
            return ldx < 0 ? 1 : 0
        }
        return ldx > 0 ? 1 : 0
    }
    dx_0 = x_0 - lx
    dy_0 = y_0 - ly
    if ((uint(ldy ^ ldx ^ dx_0 ^ dy_0) & 0x80000000u) != 0x0) {
        if ((uint(ldy ^ dx_0) & 0x80000000u) != 0x0) {
            return 1
        }
        return 0
    }
    left_0 = FixedMul(ldy >> 16, dx_0)
    right_0 = FixedMul(dy_0, ldx >> 16)
    if (right_0 < left_0) {
        return 0
    }
    return 1
}
[export, sideeffects]
def R_PointToAngle(var x_1 : int; var y_1 : int) : uint {
    x_1 -= viewx
    y_1 -= viewy
    if (x_1 == 0 && y_1 == 0) {
        return 0u
    }
    if (x_1 >= 0) {
        if (y_1 >= 0) {
            if (x_1 > y_1) {
                return tantoangle[int(SlopeDiv(uint(y_1), uint(x_1)))]
            } else {
                return uint(1073741824 - 1) - tantoangle[int(SlopeDiv(uint(x_1), uint(y_1)))]
            }
        } else {
            y_1 = -y_1
            if (x_1 > y_1) {
                return -tantoangle[int(SlopeDiv(uint(y_1), uint(x_1)))]
            } else {
                return 0xc0000000u + tantoangle[int(SlopeDiv(uint(x_1), uint(y_1)))]
            }
        }
    } else {
        x_1 = -x_1
        if (y_1 >= 0) {
            if (x_1 > y_1) {
                return 0x80000000u - 1u - tantoangle[int(SlopeDiv(uint(y_1), uint(x_1)))]
            } else {
                return 0x40000000u + tantoangle[int(SlopeDiv(uint(x_1), uint(y_1)))]
            }
        } else {
            y_1 = -y_1
            if (x_1 > y_1) {
                return 0x80000000u + tantoangle[int(SlopeDiv(uint(y_1), uint(x_1)))]
            } else {
                return 0xc0000000u - 1u - tantoangle[int(SlopeDiv(uint(x_1), uint(y_1)))]
            }
        }
    }
}
[export, sideeffects]
def R_PointToAngle2(var x1 : int; var y1 : int; var x2 : int; var y2 : int) : uint {
    viewx = int(x1)  // nolint:PERF020
    viewy = int(y1)  // nolint:PERF020
    return R_PointToAngle(x2, y2)
}
[export, sideeffects]
def R_PointToDist(var x_2 : int; var y_3 : int) : int {
    var angle : int
    var dx_1 : int
    var dy_1 : int
    var temp : int
    var dist : int
    var frac : int
    dx_1 = c2da_std_abs(x_2 - viewx)
    dy_1 = c2da_std_abs(y_3 - viewy)
    if (dy_1 > dx_1) {
        temp = dx_1
        dx_1 = dy_1
        dy_1 = temp
    }
    if (dx_1 != 0) {
        frac = FixedDiv(dy_1, dx_1)
    } else {
        frac = 0
    }
    angle = int(tantoangle[frac >> 16 - 11] + 0x40000000u >> 19u)
    dist = FixedDiv(dx_1, int(uint(c2da_mem[257920 + angle * 4]) | uint(c2da_mem[257920 + angle * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + angle * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + angle * 4 + 3]) << 0x18))
    return dist
}
[export, sideeffects]
def R_ScaleFromGlobalAngle(var visangle : uint) : int {
    var scale : int
    var sinea : int
    var sineb : int
    var num : int
    var den : int
    let c2da_fresh4 : int = 257920 + int(0x40000000u + (visangle - viewangle) >> 19u) * 4
    sinea = int(uint(c2da_mem[c2da_fresh4]) | uint(c2da_mem[c2da_fresh4 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh4 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh4 + 3]) << 0x18)
    let c2da_fresh5 : int = 257920 + int(uint(0x40000000u + (visangle - rw_normalangle)) >> 19u) * 4
    sineb = int(uint(c2da_mem[c2da_fresh5]) | uint(c2da_mem[c2da_fresh5 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh5 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh5 + 3]) << 0x18)
    num = FixedMul(projection, sineb) << detailshift
    den = FixedMul(rw_distance, sinea)
    if (den > num >> 16) {
        scale = FixedDiv(num, den)
        if (scale > 64 * (1 << 16)) {
            scale = 64 * (1 << 16)
        } elif (scale < 256) {
            scale = 256
        }
    } else {
        scale = 64 * (1 << 16)
    }
    return scale
}
[export, sideeffects]
def R_PointInSubsector(var x_3 : int; var y_4 : int) : int {
    var node_0 : int
    var side : int
    var nodenum : int
    if (numnodes == 0) {
        return subsectors
    }
    nodenum = numnodes - 1
    while ((nodenum & 32768) == 0) {
        node_0 = nodes + nodenum * 52
        side = R_PointOnSide(x_3, y_4, node_0)
        nodenum = int(uint16(uint(c2da_mem[node_0 + 48 + side * 2]) | uint(c2da_mem[node_0 + 48 + side * 2 + 1]) << 0x8))
    }
    return subsectors + (nodenum & ~32768) * 16
}
[export, sideeffects]
def R_AddPointToBox(var x_4 : int; var y_5 : int; var box : int) {
    if (x_4 < int(uint(c2da_mem[box + 2 * 4]) | uint(c2da_mem[box + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[box + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[box + 2 * 4 + 3]) << 0x18)) {
        let c2da_fresh6 : uint = uint(x_4)
        c2da_mem[box + 2 * 4] = uint8(c2da_fresh6)
        c2da_mem[box + 2 * 4 + 1] = uint8(c2da_fresh6 >> 0x8)
        c2da_mem[box + 2 * 4 + 2] = uint8(c2da_fresh6 >> 0x10)
        c2da_mem[box + 2 * 4 + 3] = uint8(c2da_fresh6 >> 0x18)
    }
    if (x_4 > int(uint(c2da_mem[box + 3 * 4]) | uint(c2da_mem[box + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[box + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[box + 3 * 4 + 3]) << 0x18)) {
        let c2da_fresh7 : uint = uint(x_4)
        c2da_mem[box + 3 * 4] = uint8(c2da_fresh7)
        c2da_mem[box + 3 * 4 + 1] = uint8(c2da_fresh7 >> 0x8)
        c2da_mem[box + 3 * 4 + 2] = uint8(c2da_fresh7 >> 0x10)
        c2da_mem[box + 3 * 4 + 3] = uint8(c2da_fresh7 >> 0x18)
    }
    if (y_5 < int(uint(c2da_mem[box + 1 * 4]) | uint(c2da_mem[box + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[box + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[box + 1 * 4 + 3]) << 0x18)) {
        let c2da_fresh8 : uint = uint(y_5)
        c2da_mem[box + 1 * 4] = uint8(c2da_fresh8)
        c2da_mem[box + 1 * 4 + 1] = uint8(c2da_fresh8 >> 0x8)
        c2da_mem[box + 1 * 4 + 2] = uint8(c2da_fresh8 >> 0x10)
        c2da_mem[box + 1 * 4 + 3] = uint8(c2da_fresh8 >> 0x18)
    }
    if (y_5 > int(uint(c2da_mem[box + 0 * 4]) | uint(c2da_mem[box + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[box + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[box + 0 * 4 + 3]) << 0x18)) {
        let c2da_fresh9 : uint = uint(y_5)
        c2da_mem[box + 0 * 4] = uint8(c2da_fresh9)
        c2da_mem[box + 0 * 4 + 1] = uint8(c2da_fresh9 >> 0x8)
        c2da_mem[box + 0 * 4 + 2] = uint8(c2da_fresh9 >> 0x10)
        c2da_mem[box + 0 * 4 + 3] = uint8(c2da_fresh9 >> 0x18)
    }
    return
}
[export, sideeffects]
def R_RenderPlayerView(var player : int) {
    R_SetupFrame(player)
    R_ClearClipSegs()
    R_ClearDrawSegs()
    R_ClearPlanes()
    R_ClearSprites()
    NetUpdate()
    R_RenderBSPNode(numnodes - 1)
    NetUpdate()
    R_DrawPlanes()
    NetUpdate()
    R_DrawMasked()
    NetUpdate()
    return
}
[export, sideeffects]
def R_SetupFrame(var player_0 : int) {
    viewplayer = int(player_0)  // nolint:PERF020
    let c2da_fresh10 : int = int(uint(c2da_mem[player_0]) | uint(c2da_mem[player_0 + 1]) << 0x8 | uint(c2da_mem[player_0 + 2]) << 0x10 | uint(c2da_mem[player_0 + 3]) << 0x18) + 24
    viewx = int(uint(c2da_mem[c2da_fresh10]) | uint(c2da_mem[c2da_fresh10 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh10 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh10 + 3]) << 0x18)
    let c2da_fresh11 : int = int(uint(c2da_mem[player_0]) | uint(c2da_mem[player_0 + 1]) << 0x8 | uint(c2da_mem[player_0 + 2]) << 0x10 | uint(c2da_mem[player_0 + 3]) << 0x18) + 28
    viewy = int(uint(c2da_mem[c2da_fresh11]) | uint(c2da_mem[c2da_fresh11 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh11 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh11 + 3]) << 0x18)
    let c2da_fresh12 : int = int(uint(c2da_mem[player_0]) | uint(c2da_mem[player_0 + 1]) << 0x8 | uint(c2da_mem[player_0 + 2]) << 0x10 | uint(c2da_mem[player_0 + 3]) << 0x18) + 56
    viewangle = (uint(c2da_mem[c2da_fresh12]) | uint(c2da_mem[c2da_fresh12 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh12 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh12 + 3]) << 0x18) + uint(viewangleoffset)
    extralight = int(uint(c2da_mem[player_0 + 256]) | uint(c2da_mem[player_0 + 257]) << 0x8 | uint(c2da_mem[player_0 + 258]) << 0x10 | uint(c2da_mem[player_0 + 259]) << 0x18)
    viewz = int(uint(c2da_mem[player_0 + 28]) | uint(c2da_mem[player_0 + 29]) << 0x8 | uint(c2da_mem[player_0 + 30]) << 0x10 | uint(c2da_mem[player_0 + 31]) << 0x18)
    let c2da_fresh13 : int = 257920 + int(viewangle >> 19u) * 4
    viewsin = int(uint(c2da_mem[c2da_fresh13]) | uint(c2da_mem[c2da_fresh13 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh13 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh13 + 3]) << 0x18)
    let c2da_fresh14 : int = finecosine + int(viewangle >> 19u) * 4
    viewcos = int(uint(c2da_mem[c2da_fresh14]) | uint(c2da_mem[c2da_fresh14 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh14 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh14 + 3]) << 0x18)
    sscount = 0
    if (int(uint(c2da_mem[player_0 + 260]) | uint(c2da_mem[player_0 + 261]) << 0x8 | uint(c2da_mem[player_0 + 262]) << 0x10 | uint(c2da_mem[player_0 + 263]) << 0x18) != 0) {
        fixedcolormap = colormaps + int(uint64(int(uint(c2da_mem[player_0 + 260]) | uint(c2da_mem[player_0 + 261]) << 0x8 | uint(c2da_mem[player_0 + 262]) << 0x10 | uint(c2da_mem[player_0 + 263]) << 0x18) * 256) * 1ul)
        walllights = 84096
        for (i in range(0, 48)) {
            let c2da_fresh15 : uint = uint(fixedcolormap)
            c2da_mem[84096 + i * 8] = uint8(c2da_fresh15)
            c2da_mem[84096 + i * 8 + 1] = uint8(c2da_fresh15 >> 0x8)
            c2da_mem[84096 + i * 8 + 2] = uint8(c2da_fresh15 >> 0x10)
            c2da_mem[84096 + i * 8 + 3] = uint8(c2da_fresh15 >> 0x18)
            c2da_mem[84096 + i * 8 + 4] = 0u8
            c2da_mem[84096 + i * 8 + 5] = 0u8
            c2da_mem[84096 + i * 8 + 6] = 0u8
            c2da_mem[84096 + i * 8 + 7] = 0u8
        }
    } else {
        fixedcolormap = 0
    }
    framecount++
    validcount++
    return
}
var framecount : int = default<int>

var viewangleoffset : int = default<int>

[export, sideeffects]
def R_Init() {
    R_InitData()
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 362448, [])
    R_InitPointToAngle()
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 362448, [])
    R_InitTables()
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 362448, [])
    R_SetViewSize(int(uint(c2da_mem[1888]) | uint(c2da_mem[1889]) << 0x8 | uint(c2da_mem[1890]) << 0x10 | uint(c2da_mem[1891]) << 0x18), int(uint(c2da_mem[1904]) | uint(c2da_mem[1905]) << 0x8 | uint(c2da_mem[1906]) << 0x10 | uint(c2da_mem[1907]) << 0x18))
    R_InitPlanes()
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 362448, [])
    R_InitLightTables()
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 362448, [])
    R_InitSkyMap()
    R_InitTranslationTables()
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 362448, [])
    framecount = 0
    return
}
[export, sideeffects]
def R_InitLightTables() {
    var level : int
    var startmap_0 : int
    var scale_0 : int
    for (i_0 in range(0, 16)) {
        startmap_0 = (16 - 1 - i_0) * 2 * 32 / 16
        for (j in range(0, 128)) {
            scale_0 = FixedDiv(320 / 2 * (1 << 16), j + 1 << 20)
            scale_0 >>= 12
            level = startmap_0 - scale_0 / 2
            if (level < 0) {
                level = 0
            }
            if (level >= 32) {
                level = 32 - 1
            }
            let c2da_fresh16 : int = colormaps + level * 256
            let c2da_fresh17 : uint = uint(c2da_fresh16)
            c2da_mem[211232 + i_0 * 1024 + j * 8] = uint8(c2da_fresh17)
            c2da_mem[211232 + i_0 * 1024 + j * 8 + 1] = uint8(c2da_fresh17 >> 0x8)
            c2da_mem[211232 + i_0 * 1024 + j * 8 + 2] = uint8(c2da_fresh17 >> 0x10)
            c2da_mem[211232 + i_0 * 1024 + j * 8 + 3] = uint8(c2da_fresh17 >> 0x18)
            c2da_mem[211232 + i_0 * 1024 + j * 8 + 4] = 0u8
            c2da_mem[211232 + i_0 * 1024 + j * 8 + 5] = 0u8
            c2da_mem[211232 + i_0 * 1024 + j * 8 + 6] = 0u8
            c2da_mem[211232 + i_0 * 1024 + j * 8 + 7] = 0u8
        }
    }
    return
}
[export, sideeffects]
def R_SetViewSize(var blocks : int; var detail : int) {
    setsizeneeded = 1u
    setblocks = int(blocks)  // nolint:PERF020
    setdetail = int(detail)  // nolint:PERF020
    return
}
var setdetail : int = default<int>

var setblocks : int = default<int>

var setsizeneeded : uint = default<uint>

[export, sideeffects]
def R_InitTables() {
    return
}
[export, sideeffects]
def R_InitPointToAngle() {
    return
}
[export, sideeffects]
def R_InitTextureMapping() {
    var i_1 : int
    var x_5 : int
    var t : int
    var focallength : int = FixedDiv(centerxfrac, finetangent[8192 / 4 + 2048 / 2])
    i_1 = 0
    while (i_1 < 8192 / 2) {
        if (finetangent[i_1] > (1 << 16) * 2) {
            t = -1
        } elif (finetangent[i_1] < -(1 << 16) * 2) {
            t = viewwidth + 1
        } else {
            t = FixedMul(finetangent[i_1], focallength)
            t = centerxfrac - t + (1 << 16) - 1 >> 16
            if (t < -1) {
                t = -1
            } elif (t > viewwidth + 1) {
                t = viewwidth + 1
            }
        }
        viewangletox[i_1] = t
        i_1++
    }
    x_5 = 0
    while (x_5 <= viewwidth) {
        i_1 = 0
        while (viewangletox[i_1] > x_5) {
            i_1++
        }
        xtoviewangle[x_5] = uint((i_1 << 19) - 1073741824)
        x_5++
    }
    i_1 = 0
    for (c2da_i_1 in range(i_1, 8192 / 2)) {
        t = FixedMul(finetangent[c2da_i_1], focallength)
        t = centerx - t
        if (viewangletox[c2da_i_1] == -1) {
            viewangletox[c2da_i_1] = 0
        } elif (viewangletox[c2da_i_1] == viewwidth + 1) {
            viewangletox[c2da_i_1] = viewwidth
        }
    }
    clipangle = uint(xtoviewangle[0])  // nolint:PERF020
    return
}
[export, sideeffects]
def R_ExecuteSetViewSize() {
    var cosadj : int
    var dy_2 : int
    var i_2 : int
    var level_0 : int
    var startmap_1 : int
    setsizeneeded = 0u
    if (setblocks == 11) {
        scaledviewwidth = 320
        viewheight = 200
    } else {
        scaledviewwidth = setblocks * 32
        viewheight = setblocks * 168 / 10 & ~7
    }
    detailshift = int(setdetail)  // nolint:PERF020
    viewwidth = scaledviewwidth >> detailshift
    centery = viewheight / 2
    centerx = viewwidth / 2
    centerxfrac = centerx << 16
    centeryfrac = centery << 16
    projection = int(centerxfrac)  // nolint:PERF020
    if (detailshift == 0) {
        basecolfunc = 144
        colfunc = int(basecolfunc)  // nolint:PERF020
        fuzzcolfunc = 145
        transcolfunc = 146
        spanfunc = 147
    } else {
        basecolfunc = 148
        colfunc = int(basecolfunc)  // nolint:PERF020
        fuzzcolfunc = 149
        transcolfunc = 150
        spanfunc = 151
    }
    R_InitBuffer(scaledviewwidth, viewheight)
    R_InitTextureMapping()
    pspritescale = (1 << 16) * viewwidth / 320
    pspriteiscale = (1 << 16) * 320 / viewwidth
    i_2 = 0
    while (i_2 < viewwidth) {
        let c2da_fresh18 : int16 = int16(viewheight)
        let c2da_fresh19 : uint = uint(c2da_fresh18)
        c2da_mem[233760 + i_2 * 2] = uint8(c2da_fresh19)
        c2da_mem[233760 + i_2 * 2 + 1] = uint8(c2da_fresh19 >> 0x8)
        i_2++
    }
    i_2 = 0
    while (i_2 < viewheight) {
        dy_2 = (i_2 - viewheight / 2 << 16) + (1 << 16) / 2
        dy_2 = c2da_std_abs(dy_2)
        yslope[i_2] = FixedDiv((viewwidth << detailshift) / 2 * (1 << 16), dy_2)
        i_2++
    }
    i_2 = 0
    while (i_2 < viewwidth) {
        let c2da_fresh20 : int = finecosine + int(xtoviewangle[i_2] >> 19u) * 4
        cosadj = c2da_std_abs(int(uint(c2da_mem[c2da_fresh20]) | uint(c2da_mem[c2da_fresh20 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh20 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh20 + 3]) << 0x18))
        distscale[i_2] = FixedDiv(1 << 16, cosadj)
        i_2++
    }
    i_2 = 0
    for (c2da_i_2 in range(i_2, 16)) {
        startmap_1 = (16 - 1 - c2da_i_2) * 2 * 32 / 16
        for (j_0 in range(0, 48)) {
            level_0 = startmap_1 - j_0 * 320 / (viewwidth << detailshift) / 2
            if (level_0 < 0) {
                level_0 = 0
            }
            if (level_0 >= 32) {
                level_0 = 32 - 1
            }
            let c2da_fresh21 : int = colormaps + level_0 * 256
            let c2da_fresh22 : uint = uint(c2da_fresh21)
            c2da_mem[227616 + c2da_i_2 * 384 + j_0 * 8] = uint8(c2da_fresh22)
            c2da_mem[227616 + c2da_i_2 * 384 + j_0 * 8 + 1] = uint8(c2da_fresh22 >> 0x8)
            c2da_mem[227616 + c2da_i_2 * 384 + j_0 * 8 + 2] = uint8(c2da_fresh22 >> 0x10)
            c2da_mem[227616 + c2da_i_2 * 384 + j_0 * 8 + 3] = uint8(c2da_fresh22 >> 0x18)
            c2da_mem[227616 + c2da_i_2 * 384 + j_0 * 8 + 4] = 0u8
            c2da_mem[227616 + c2da_i_2 * 384 + j_0 * 8 + 5] = 0u8
            c2da_mem[227616 + c2da_i_2 * 384 + j_0 * 8 + 6] = 0u8
            c2da_mem[227616 + c2da_i_2 * 384 + j_0 * 8 + 7] = 0u8
        }
    }
    return
}

// This unit's static data, at heap offset 362448.
let private c2da_lin_static_r_main_seg = fixed_array<int>(362448, 1)
let private c2da_lin_static_r_main = fixed_array<uint64>(0x2eul)

[init]
def private c2da_lin_init_static_r_main() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_r_main_seg[s * 2]
        for (k in range(c2da_lin_static_r_main_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_r_main[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
