[sideeffects]
def private c2da___bswap_16_8(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_8(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_8(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_8(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_8(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_8(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
var floatok : uint = default<uint>

var tmfloorz : int = default<int>

var tmceilingz : int = default<int>

var ceilingline : int = default<int>

var spechit : int[20]

var numspechit : int = default<int>

[export, sideeffects]
def P_CheckPosition(var thing : int; var x : int; var y : int) : uint {
    var xh : int
    var yl : int
    var yh : int
    var bx : int
    var by : int
    var newsubsec : int
    tmthing = int(thing)  // nolint:PERF020
    tmflags = int(uint(c2da_mem[thing + 160]) | uint(c2da_mem[thing + 161]) << 0x8 | uint(c2da_mem[thing + 162]) << 0x10 | uint(c2da_mem[thing + 163]) << 0x18)
    tmx = int(x)  // nolint:PERF020
    tmy = int(y)  // nolint:PERF020
    let c2da_fresh0 : int = y + int(uint(c2da_mem[tmthing + 104]) | uint(c2da_mem[tmthing + 105]) << 0x8 | uint(c2da_mem[tmthing + 106]) << 0x10 | uint(c2da_mem[tmthing + 107]) << 0x18)
    let c2da_fresh1 : uint = uint(c2da_fresh0)
    c2da_mem[46576 + 0 * 4] = uint8(c2da_fresh1)
    c2da_mem[46576 + 0 * 4 + 1] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[46576 + 0 * 4 + 2] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[46576 + 0 * 4 + 3] = uint8(c2da_fresh1 >> 0x18)
    let c2da_fresh2 : int = y - int(uint(c2da_mem[tmthing + 104]) | uint(c2da_mem[tmthing + 105]) << 0x8 | uint(c2da_mem[tmthing + 106]) << 0x10 | uint(c2da_mem[tmthing + 107]) << 0x18)
    let c2da_fresh3 : uint = uint(c2da_fresh2)
    c2da_mem[46576 + 1 * 4] = uint8(c2da_fresh3)
    c2da_mem[46576 + 1 * 4 + 1] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[46576 + 1 * 4 + 2] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[46576 + 1 * 4 + 3] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : int = x + int(uint(c2da_mem[tmthing + 104]) | uint(c2da_mem[tmthing + 105]) << 0x8 | uint(c2da_mem[tmthing + 106]) << 0x10 | uint(c2da_mem[tmthing + 107]) << 0x18)
    let c2da_fresh5 : uint = uint(c2da_fresh4)
    c2da_mem[46576 + 3 * 4] = uint8(c2da_fresh5)
    c2da_mem[46576 + 3 * 4 + 1] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[46576 + 3 * 4 + 2] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[46576 + 3 * 4 + 3] = uint8(c2da_fresh5 >> 0x18)
    let c2da_fresh6 : int = x - int(uint(c2da_mem[tmthing + 104]) | uint(c2da_mem[tmthing + 105]) << 0x8 | uint(c2da_mem[tmthing + 106]) << 0x10 | uint(c2da_mem[tmthing + 107]) << 0x18)
    let c2da_fresh7 : uint = uint(c2da_fresh6)
    c2da_mem[46576 + 2 * 4] = uint8(c2da_fresh7)
    c2da_mem[46576 + 2 * 4 + 1] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[46576 + 2 * 4 + 2] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[46576 + 2 * 4 + 3] = uint8(c2da_fresh7 >> 0x18)
    newsubsec = R_PointInSubsector(x, y)
    ceilingline = 0
    let c2da_fresh8 : int = int(uint(c2da_mem[newsubsec]) | uint(c2da_mem[newsubsec + 1]) << 0x8 | uint(c2da_mem[newsubsec + 2]) << 0x10 | uint(c2da_mem[newsubsec + 3]) << 0x18)
    tmdropoffz = int(uint(c2da_mem[c2da_fresh8]) | uint(c2da_mem[c2da_fresh8 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh8 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh8 + 3]) << 0x18)
    tmfloorz = int(tmdropoffz)  // nolint:PERF020
    let c2da_fresh9 : int = int(uint(c2da_mem[newsubsec]) | uint(c2da_mem[newsubsec + 1]) << 0x8 | uint(c2da_mem[newsubsec + 2]) << 0x10 | uint(c2da_mem[newsubsec + 3]) << 0x18) + 4
    tmceilingz = int(uint(c2da_mem[c2da_fresh9]) | uint(c2da_mem[c2da_fresh9 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh9 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh9 + 3]) << 0x18)
    validcount = validcount + 1
    numspechit = 0
    if ((tmflags & 4096) != 0) {
        return 1u
    }
    xh = int(uint(c2da_mem[46576 + 3 * 4]) | uint(c2da_mem[46576 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[46576 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[46576 + 3 * 4 + 3]) << 0x18) - int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18) + 32 * (1 << 16) >> 16 + 7
    yl = int(uint(c2da_mem[46576 + 1 * 4]) | uint(c2da_mem[46576 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[46576 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[46576 + 1 * 4 + 3]) << 0x18) - int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18) - 32 * (1 << 16) >> 16 + 7
    yh = int(uint(c2da_mem[46576 + 0 * 4]) | uint(c2da_mem[46576 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[46576 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[46576 + 0 * 4 + 3]) << 0x18) - int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18) + 32 * (1 << 16) >> 16 + 7
    bx = int(uint(c2da_mem[46576 + 2 * 4]) | uint(c2da_mem[46576 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[46576 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[46576 + 2 * 4 + 3]) << 0x18) - int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18) - 32 * (1 << 16) >> 16 + 7
    while (bx <= xh) {
        by = yl
        while (by <= yh) {
            if (P_BlockThingsIterator(bx, by, 133) == 0) {
                return 0u
            }
            by++
        }
        bx++
    }
    xh = int(uint(c2da_mem[46576 + 3 * 4]) | uint(c2da_mem[46576 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[46576 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[46576 + 3 * 4 + 3]) << 0x18) - int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18) >> 16 + 7
    yl = int(uint(c2da_mem[46576 + 1 * 4]) | uint(c2da_mem[46576 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[46576 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[46576 + 1 * 4 + 3]) << 0x18) - int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18) >> 16 + 7
    yh = int(uint(c2da_mem[46576 + 0 * 4]) | uint(c2da_mem[46576 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[46576 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[46576 + 0 * 4 + 3]) << 0x18) - int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18) >> 16 + 7
    bx = int(uint(c2da_mem[46576 + 2 * 4]) | uint(c2da_mem[46576 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[46576 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[46576 + 2 * 4 + 3]) << 0x18) - int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18) >> 16 + 7
    while (bx <= xh) {
        by = yl
        while (by <= yh) {
            if (P_BlockLinesIterator(bx, by, 134) == 0) {
                return 0u
            }
            by++
        }
        bx++
    }
    return 1u
}
[export, sideeffects]
def PIT_CheckLine(var ld : int) : uint {
    if (int(uint(c2da_mem[46576 + 3 * 4]) | uint(c2da_mem[46576 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[46576 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[46576 + 3 * 4 + 3]) << 0x18) <= int(uint(c2da_mem[ld + 36 + 2 * 4]) | uint(c2da_mem[ld + 36 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[ld + 36 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[ld + 36 + 2 * 4 + 3]) << 0x18) || int(uint(c2da_mem[46576 + 2 * 4]) | uint(c2da_mem[46576 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[46576 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[46576 + 2 * 4 + 3]) << 0x18) >= int(uint(c2da_mem[ld + 36 + 3 * 4]) | uint(c2da_mem[ld + 36 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[ld + 36 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[ld + 36 + 3 * 4 + 3]) << 0x18) || int(uint(c2da_mem[46576 + 0 * 4]) | uint(c2da_mem[46576 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[46576 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[46576 + 0 * 4 + 3]) << 0x18) <= int(uint(c2da_mem[ld + 36 + 1 * 4]) | uint(c2da_mem[ld + 36 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[ld + 36 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[ld + 36 + 1 * 4 + 3]) << 0x18) || int(uint(c2da_mem[46576 + 1 * 4]) | uint(c2da_mem[46576 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[46576 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[46576 + 1 * 4 + 3]) << 0x18) >= int(uint(c2da_mem[ld + 36 + 0 * 4]) | uint(c2da_mem[ld + 36 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[ld + 36 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[ld + 36 + 0 * 4 + 3]) << 0x18)) {
        return 1u
    }
    if (P_BoxOnLineSide(46576, ld) != -1) {
        return 1u
    }
    if (int(uint(c2da_mem[ld + 64]) | uint(c2da_mem[ld + 65]) << 0x8 | uint(c2da_mem[ld + 66]) << 0x10 | uint(c2da_mem[ld + 67]) << 0x18) == 0) {
        return 0u
    }
    if ((int(uint(c2da_mem[tmthing + 160]) | uint(c2da_mem[tmthing + 161]) << 0x8 | uint(c2da_mem[tmthing + 162]) << 0x10 | uint(c2da_mem[tmthing + 163]) << 0x18) & 65536) == 0) {
        if ((int(int16(uint(c2da_mem[ld + 24]) | uint(c2da_mem[ld + 25]) << 0x8)) & 1) != 0) {
            return 0u
        }
        if (int(uint(c2da_mem[tmthing + 192]) | uint(c2da_mem[tmthing + 193]) << 0x8 | uint(c2da_mem[tmthing + 194]) << 0x10 | uint(c2da_mem[tmthing + 195]) << 0x18) == 0 && (int(int16(uint(c2da_mem[ld + 24]) | uint(c2da_mem[ld + 25]) << 0x8)) & 2) != 0) {
            return 0u
        }
    }
    P_LineOpening(ld)
    if (int(uint(c2da_mem[49664]) | uint(c2da_mem[49665]) << 0x8 | uint(c2da_mem[49666]) << 0x10 | uint(c2da_mem[49667]) << 0x18) < tmceilingz) {
        tmceilingz = int(uint(c2da_mem[49664]) | uint(c2da_mem[49665]) << 0x8 | uint(c2da_mem[49666]) << 0x10 | uint(c2da_mem[49667]) << 0x18)
        ceilingline = int(ld)  // nolint:PERF020
    }
    if (int(uint(c2da_mem[49648]) | uint(c2da_mem[49649]) << 0x8 | uint(c2da_mem[49650]) << 0x10 | uint(c2da_mem[49651]) << 0x18) > tmfloorz) {
        tmfloorz = int(uint(c2da_mem[49648]) | uint(c2da_mem[49649]) << 0x8 | uint(c2da_mem[49650]) << 0x10 | uint(c2da_mem[49651]) << 0x18)
    }
    if (int(uint(c2da_mem[49632]) | uint(c2da_mem[49633]) << 0x8 | uint(c2da_mem[49634]) << 0x10 | uint(c2da_mem[49635]) << 0x18) < tmdropoffz) {
        tmdropoffz = int(uint(c2da_mem[49632]) | uint(c2da_mem[49633]) << 0x8 | uint(c2da_mem[49634]) << 0x10 | uint(c2da_mem[49635]) << 0x18)
    }
    if (int16(uint(c2da_mem[ld + 26]) | uint(c2da_mem[ld + 27]) << 0x8) != 0) {
        spechit[numspechit] = int(ld)  // nolint:PERF020
        numspechit++
        if (numspechit > 8) {
            SpechitOverrun(ld)
        }
    }
    return 1u
}
[sideeffects]
def private SpechitOverrun(var ld_0 : int) {
    var addr_0 : uint
    var p : int
    if ((uint(c2da_mem[360192]) | uint(c2da_mem[360193]) << 0x8 | uint(c2da_mem[360194]) << 0x10 | uint(c2da_mem[360195]) << 0x18) == 0u) {
        p = M_CheckParmWithArgs(360196, 1)
        if (p > 0) {
            M_StrToInt(int(uint(c2da_mem[myargv + (p + 1) * 8]) | uint(c2da_mem[myargv + (p + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p + 1) * 8 + 3]) << 0x18), 360192)
        } else {
            let c2da_fresh10 : uint = 0x1c09c98u
            let c2da_fresh11 : uint = c2da_fresh10
            c2da_mem[360192] = uint8(c2da_fresh11)
            c2da_mem[360193] = uint8(c2da_fresh11 >> 0x8)
            c2da_mem[360194] = uint8(c2da_fresh11 >> 0x10)
            c2da_mem[360195] = uint8(c2da_fresh11 >> 0x18)
        }
    }
    addr_0 = uint(int64(uint(c2da_mem[360192]) | uint(c2da_mem[360193]) << 0x8 | uint(c2da_mem[360194]) << 0x10 | uint(c2da_mem[360195]) << 0x18) + int64((ld_0 - lines) / 88) * 62l)
    if (numspechit == 9 || numspechit == 10 || numspechit == 11 || numspechit == 12) {
        let c2da_fresh12 : int = int(addr_0)
        let c2da_fresh13 : uint = uint(c2da_fresh12)
        c2da_mem[46576 + (numspechit - 9) * 4] = uint8(c2da_fresh13)
        c2da_mem[46576 + (numspechit - 9) * 4 + 1] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[46576 + (numspechit - 9) * 4 + 2] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[46576 + (numspechit - 9) * 4 + 3] = uint8(c2da_fresh13 >> 0x18)
    } elif (numspechit == 13) {
        crushchange = addr_0
    } elif (numspechit == 14) {
        nofit = addr_0
    } else {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 360205, [C2daVaArg(tag = 1, i64 = int64(numspechit), f64 = 0.0lf, raw = 0x0)])
    }
    return
}
var nofit : uint = default<uint>

var crushchange : uint = default<uint>

var tmdropoffz : int = default<int>

var tmthing : int = default<int>

[export, sideeffects]
def PIT_CheckThing(var thing_0 : int) : uint {
    var blockdist : int
    var solid : uint
    var damage : int
    if ((int(uint(c2da_mem[thing_0 + 160]) | uint(c2da_mem[thing_0 + 161]) << 0x8 | uint(c2da_mem[thing_0 + 162]) << 0x10 | uint(c2da_mem[thing_0 + 163]) << 0x18) & (2 | 1 | 4)) == 0) {
        return 1u
    }
    blockdist = int(uint(c2da_mem[thing_0 + 104]) | uint(c2da_mem[thing_0 + 105]) << 0x8 | uint(c2da_mem[thing_0 + 106]) << 0x10 | uint(c2da_mem[thing_0 + 107]) << 0x18) + int(uint(c2da_mem[tmthing + 104]) | uint(c2da_mem[tmthing + 105]) << 0x8 | uint(c2da_mem[tmthing + 106]) << 0x10 | uint(c2da_mem[tmthing + 107]) << 0x18)
    if (c2da_std_abs(int(uint(c2da_mem[thing_0 + 24]) | uint(c2da_mem[thing_0 + 25]) << 0x8 | uint(c2da_mem[thing_0 + 26]) << 0x10 | uint(c2da_mem[thing_0 + 27]) << 0x18) - tmx) >= blockdist || c2da_std_abs(int(uint(c2da_mem[thing_0 + 28]) | uint(c2da_mem[thing_0 + 29]) << 0x8 | uint(c2da_mem[thing_0 + 30]) << 0x10 | uint(c2da_mem[thing_0 + 31]) << 0x18) - tmy) >= blockdist) {
        return 1u
    }
    if (thing_0 == tmthing) {
        return 1u
    }
    if ((int(uint(c2da_mem[tmthing + 160]) | uint(c2da_mem[tmthing + 161]) << 0x8 | uint(c2da_mem[tmthing + 162]) << 0x10 | uint(c2da_mem[tmthing + 163]) << 0x18) & 16777216) != 0) {
        let c2da_fresh14 : int = int(uint(c2da_mem[tmthing + 136]) | uint(c2da_mem[tmthing + 137]) << 0x8 | uint(c2da_mem[tmthing + 138]) << 0x10 | uint(c2da_mem[tmthing + 139]) << 0x18) + 76
        damage = (P_Random() % 8 + 1) * int(uint(c2da_mem[c2da_fresh14]) | uint(c2da_mem[c2da_fresh14 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh14 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh14 + 3]) << 0x18)
        P_DamageMobj(thing_0, tmthing, tmthing, damage)
        let c2da_fresh15 : int = int(uint(c2da_mem[tmthing + 160]) | uint(c2da_mem[tmthing + 161]) << 0x8 | uint(c2da_mem[tmthing + 162]) << 0x10 | uint(c2da_mem[tmthing + 163]) << 0x18) & ~16777216
        let c2da_fresh16 : uint = uint(c2da_fresh15)
        c2da_mem[tmthing + 160] = uint8(c2da_fresh16)
        c2da_mem[tmthing + 161] = uint8(c2da_fresh16 >> 0x8)
        c2da_mem[tmthing + 162] = uint8(c2da_fresh16 >> 0x10)
        c2da_mem[tmthing + 163] = uint8(c2da_fresh16 >> 0x18)
        let c2da_fresh17 : int = 0
        let c2da_fresh18 : uint = uint(c2da_fresh17)
        c2da_mem[tmthing + 120] = uint8(c2da_fresh18)
        c2da_mem[tmthing + 121] = uint8(c2da_fresh18 >> 0x8)
        c2da_mem[tmthing + 122] = uint8(c2da_fresh18 >> 0x10)
        c2da_mem[tmthing + 123] = uint8(c2da_fresh18 >> 0x18)
        let c2da_fresh19 : uint = uint(c2da_fresh17)
        c2da_mem[tmthing + 116] = uint8(c2da_fresh19)
        c2da_mem[tmthing + 117] = uint8(c2da_fresh19 >> 0x8)
        c2da_mem[tmthing + 118] = uint8(c2da_fresh19 >> 0x10)
        c2da_mem[tmthing + 119] = uint8(c2da_fresh19 >> 0x18)
        let c2da_fresh20 : uint = uint(c2da_fresh17)
        c2da_mem[tmthing + 112] = uint8(c2da_fresh20)
        c2da_mem[tmthing + 113] = uint8(c2da_fresh20 >> 0x8)
        c2da_mem[tmthing + 114] = uint8(c2da_fresh20 >> 0x10)
        c2da_mem[tmthing + 115] = uint8(c2da_fresh20 >> 0x18)
        let c2da_fresh21 : int = int(uint(c2da_mem[tmthing + 136]) | uint(c2da_mem[tmthing + 137]) << 0x8 | uint(c2da_mem[tmthing + 138]) << 0x10 | uint(c2da_mem[tmthing + 139]) << 0x18) + 4
        P_SetMobjState(tmthing, uint(int(uint(c2da_mem[c2da_fresh21]) | uint(c2da_mem[c2da_fresh21 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh21 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh21 + 3]) << 0x18)))
        return 0u
    }
    if ((int(uint(c2da_mem[tmthing + 160]) | uint(c2da_mem[tmthing + 161]) << 0x8 | uint(c2da_mem[tmthing + 162]) << 0x10 | uint(c2da_mem[tmthing + 163]) << 0x18) & 65536) != 0) {
        if (int(uint(c2da_mem[tmthing + 32]) | uint(c2da_mem[tmthing + 33]) << 0x8 | uint(c2da_mem[tmthing + 34]) << 0x10 | uint(c2da_mem[tmthing + 35]) << 0x18) > int(uint(c2da_mem[thing_0 + 32]) | uint(c2da_mem[thing_0 + 33]) << 0x8 | uint(c2da_mem[thing_0 + 34]) << 0x10 | uint(c2da_mem[thing_0 + 35]) << 0x18) + int(uint(c2da_mem[thing_0 + 108]) | uint(c2da_mem[thing_0 + 109]) << 0x8 | uint(c2da_mem[thing_0 + 110]) << 0x10 | uint(c2da_mem[thing_0 + 111]) << 0x18)) {
            return 1u
        }
        if (int(uint(c2da_mem[tmthing + 32]) | uint(c2da_mem[tmthing + 33]) << 0x8 | uint(c2da_mem[tmthing + 34]) << 0x10 | uint(c2da_mem[tmthing + 35]) << 0x18) + int(uint(c2da_mem[tmthing + 108]) | uint(c2da_mem[tmthing + 109]) << 0x8 | uint(c2da_mem[tmthing + 110]) << 0x10 | uint(c2da_mem[tmthing + 111]) << 0x18) < int(uint(c2da_mem[thing_0 + 32]) | uint(c2da_mem[thing_0 + 33]) << 0x8 | uint(c2da_mem[thing_0 + 34]) << 0x10 | uint(c2da_mem[thing_0 + 35]) << 0x18)) {
            return 1u
        }
        var c2da_fresh27 : int = 0
        if (int(uint(c2da_mem[tmthing + 176]) | uint(c2da_mem[tmthing + 177]) << 0x8 | uint(c2da_mem[tmthing + 178]) << 0x10 | uint(c2da_mem[tmthing + 179]) << 0x18) != 0) {
            let c2da_fresh22 : int = int(uint(c2da_mem[tmthing + 176]) | uint(c2da_mem[tmthing + 177]) << 0x8 | uint(c2da_mem[tmthing + 178]) << 0x10 | uint(c2da_mem[tmthing + 179]) << 0x18) + 128
            var c2da_fresh24 : int = 1
            if (!((uint(c2da_mem[c2da_fresh22]) | uint(c2da_mem[c2da_fresh22 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh22 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh22 + 3]) << 0x18) == (uint(c2da_mem[thing_0 + 128]) | uint(c2da_mem[thing_0 + 129]) << 0x8 | uint(c2da_mem[thing_0 + 130]) << 0x10 | uint(c2da_mem[thing_0 + 131]) << 0x18))) {
                let c2da_fresh23 : int = int(uint(c2da_mem[tmthing + 176]) | uint(c2da_mem[tmthing + 177]) << 0x8 | uint(c2da_mem[tmthing + 178]) << 0x10 | uint(c2da_mem[tmthing + 179]) << 0x18) + 128
                if (!((uint(c2da_mem[c2da_fresh23]) | uint(c2da_mem[c2da_fresh23 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh23 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh23 + 3]) << 0x18) == 17u && (uint(c2da_mem[thing_0 + 128]) | uint(c2da_mem[thing_0 + 129]) << 0x8 | uint(c2da_mem[thing_0 + 130]) << 0x10 | uint(c2da_mem[thing_0 + 131]) << 0x18) == 15u)) {
                    c2da_fresh24 = 0
                }
            }
            var c2da_fresh26 : int = 1
            if (!(c2da_fresh24 != 0)) {
                let c2da_fresh25 : int = int(uint(c2da_mem[tmthing + 176]) | uint(c2da_mem[tmthing + 177]) << 0x8 | uint(c2da_mem[tmthing + 178]) << 0x10 | uint(c2da_mem[tmthing + 179]) << 0x18) + 128
                if (!((uint(c2da_mem[c2da_fresh25]) | uint(c2da_mem[c2da_fresh25 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh25 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh25 + 3]) << 0x18) == 15u && (uint(c2da_mem[thing_0 + 128]) | uint(c2da_mem[thing_0 + 129]) << 0x8 | uint(c2da_mem[thing_0 + 130]) << 0x10 | uint(c2da_mem[thing_0 + 131]) << 0x18) == 17u)) {
                    c2da_fresh26 = 0
                }
            }
            if (c2da_fresh26 != 0) {
                c2da_fresh27 = 1
            }
        }
        if (c2da_fresh27 != 0) {
            if (thing_0 == int(uint(c2da_mem[tmthing + 176]) | uint(c2da_mem[tmthing + 177]) << 0x8 | uint(c2da_mem[tmthing + 178]) << 0x10 | uint(c2da_mem[tmthing + 179]) << 0x18)) {
                return 1u
            }
            if ((uint(c2da_mem[thing_0 + 128]) | uint(c2da_mem[thing_0 + 129]) << 0x8 | uint(c2da_mem[thing_0 + 130]) << 0x10 | uint(c2da_mem[thing_0 + 131]) << 0x18) != 0u && 0 == 0) {
                return 0u
            }
        }
        if ((int(uint(c2da_mem[thing_0 + 160]) | uint(c2da_mem[thing_0 + 161]) << 0x8 | uint(c2da_mem[thing_0 + 162]) << 0x10 | uint(c2da_mem[thing_0 + 163]) << 0x18) & 4) == 0) {
            return (int(uint(c2da_mem[thing_0 + 160]) | uint(c2da_mem[thing_0 + 161]) << 0x8 | uint(c2da_mem[thing_0 + 162]) << 0x10 | uint(c2da_mem[thing_0 + 163]) << 0x18) & 2) == 0 ? 1u : 0u
        }
        let c2da_fresh28 : int = int(uint(c2da_mem[tmthing + 136]) | uint(c2da_mem[tmthing + 137]) << 0x8 | uint(c2da_mem[tmthing + 138]) << 0x10 | uint(c2da_mem[tmthing + 139]) << 0x18) + 76
        damage = (P_Random() % 8 + 1) * int(uint(c2da_mem[c2da_fresh28]) | uint(c2da_mem[c2da_fresh28 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh28 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh28 + 3]) << 0x18)
        P_DamageMobj(thing_0, tmthing, int(uint(c2da_mem[tmthing + 176]) | uint(c2da_mem[tmthing + 177]) << 0x8 | uint(c2da_mem[tmthing + 178]) << 0x10 | uint(c2da_mem[tmthing + 179]) << 0x18), damage)
        return 0u
    }
    if ((int(uint(c2da_mem[thing_0 + 160]) | uint(c2da_mem[thing_0 + 161]) << 0x8 | uint(c2da_mem[thing_0 + 162]) << 0x10 | uint(c2da_mem[thing_0 + 163]) << 0x18) & 1) != 0) {
        solid = uint(int(uint(c2da_mem[thing_0 + 160]) | uint(c2da_mem[thing_0 + 161]) << 0x8 | uint(c2da_mem[thing_0 + 162]) << 0x10 | uint(c2da_mem[thing_0 + 163]) << 0x18) & 2)
        if ((tmflags & 2048) != 0) {
            P_TouchSpecialThing(thing_0, tmthing)
        }
        return solid == 0 ? 1u : 0u
    }
    return (int(uint(c2da_mem[thing_0 + 160]) | uint(c2da_mem[thing_0 + 161]) << 0x8 | uint(c2da_mem[thing_0 + 162]) << 0x10 | uint(c2da_mem[thing_0 + 163]) << 0x18) & 2) == 0 ? 1u : 0u
}
var tmflags : int = default<int>

var tmy : int = default<int>

var tmx : int = default<int>

[export, sideeffects]
def P_TryMove(var thing_1 : int; var x_0 : int; var y_0 : int) : uint {
    var oldx : int
    var oldy : int
    var side : int
    var oldside : int
    var ld_1 : int
    floatok = 0u
    if (P_CheckPosition(thing_1, x_0, y_0) == 0) {
        return 0u
    }
    if ((int(uint(c2da_mem[thing_1 + 160]) | uint(c2da_mem[thing_1 + 161]) << 0x8 | uint(c2da_mem[thing_1 + 162]) << 0x10 | uint(c2da_mem[thing_1 + 163]) << 0x18) & 4096) == 0) {
        if (tmceilingz - tmfloorz < int(uint(c2da_mem[thing_1 + 108]) | uint(c2da_mem[thing_1 + 109]) << 0x8 | uint(c2da_mem[thing_1 + 110]) << 0x10 | uint(c2da_mem[thing_1 + 111]) << 0x18)) {
            return 0u
        }
        floatok = 1u
        if ((int(uint(c2da_mem[thing_1 + 160]) | uint(c2da_mem[thing_1 + 161]) << 0x8 | uint(c2da_mem[thing_1 + 162]) << 0x10 | uint(c2da_mem[thing_1 + 163]) << 0x18) & 32768) == 0 && tmceilingz - int(uint(c2da_mem[thing_1 + 32]) | uint(c2da_mem[thing_1 + 33]) << 0x8 | uint(c2da_mem[thing_1 + 34]) << 0x10 | uint(c2da_mem[thing_1 + 35]) << 0x18) < int(uint(c2da_mem[thing_1 + 108]) | uint(c2da_mem[thing_1 + 109]) << 0x8 | uint(c2da_mem[thing_1 + 110]) << 0x10 | uint(c2da_mem[thing_1 + 111]) << 0x18)) {
            return 0u
        }
        if ((int(uint(c2da_mem[thing_1 + 160]) | uint(c2da_mem[thing_1 + 161]) << 0x8 | uint(c2da_mem[thing_1 + 162]) << 0x10 | uint(c2da_mem[thing_1 + 163]) << 0x18) & 32768) == 0 && tmfloorz - int(uint(c2da_mem[thing_1 + 32]) | uint(c2da_mem[thing_1 + 33]) << 0x8 | uint(c2da_mem[thing_1 + 34]) << 0x10 | uint(c2da_mem[thing_1 + 35]) << 0x18) > 24 * (1 << 16)) {
            return 0u
        }
        if ((int(uint(c2da_mem[thing_1 + 160]) | uint(c2da_mem[thing_1 + 161]) << 0x8 | uint(c2da_mem[thing_1 + 162]) << 0x10 | uint(c2da_mem[thing_1 + 163]) << 0x18) & (1024 | 16384)) == 0 && tmfloorz - tmdropoffz > 24 * (1 << 16)) {
            return 0u
        }
    }
    P_UnsetThingPosition(thing_1)
    oldx = int(uint(c2da_mem[thing_1 + 24]) | uint(c2da_mem[thing_1 + 25]) << 0x8 | uint(c2da_mem[thing_1 + 26]) << 0x10 | uint(c2da_mem[thing_1 + 27]) << 0x18)
    oldy = int(uint(c2da_mem[thing_1 + 28]) | uint(c2da_mem[thing_1 + 29]) << 0x8 | uint(c2da_mem[thing_1 + 30]) << 0x10 | uint(c2da_mem[thing_1 + 31]) << 0x18)
    let c2da_fresh29 : uint = uint(tmfloorz)
    c2da_mem[thing_1 + 96] = uint8(c2da_fresh29)
    c2da_mem[thing_1 + 97] = uint8(c2da_fresh29 >> 0x8)
    c2da_mem[thing_1 + 98] = uint8(c2da_fresh29 >> 0x10)
    c2da_mem[thing_1 + 99] = uint8(c2da_fresh29 >> 0x18)
    let c2da_fresh30 : uint = uint(tmceilingz)
    c2da_mem[thing_1 + 100] = uint8(c2da_fresh30)
    c2da_mem[thing_1 + 101] = uint8(c2da_fresh30 >> 0x8)
    c2da_mem[thing_1 + 102] = uint8(c2da_fresh30 >> 0x10)
    c2da_mem[thing_1 + 103] = uint8(c2da_fresh30 >> 0x18)
    let c2da_fresh31 : uint = uint(x_0)
    c2da_mem[thing_1 + 24] = uint8(c2da_fresh31)
    c2da_mem[thing_1 + 25] = uint8(c2da_fresh31 >> 0x8)
    c2da_mem[thing_1 + 26] = uint8(c2da_fresh31 >> 0x10)
    c2da_mem[thing_1 + 27] = uint8(c2da_fresh31 >> 0x18)
    let c2da_fresh32 : uint = uint(y_0)
    c2da_mem[thing_1 + 28] = uint8(c2da_fresh32)
    c2da_mem[thing_1 + 29] = uint8(c2da_fresh32 >> 0x8)
    c2da_mem[thing_1 + 30] = uint8(c2da_fresh32 >> 0x10)
    c2da_mem[thing_1 + 31] = uint8(c2da_fresh32 >> 0x18)
    P_SetThingPosition(thing_1)
    if ((int(uint(c2da_mem[thing_1 + 160]) | uint(c2da_mem[thing_1 + 161]) << 0x8 | uint(c2da_mem[thing_1 + 162]) << 0x10 | uint(c2da_mem[thing_1 + 163]) << 0x18) & (32768 | 4096)) == 0) {
        while (true) {
            let c2da_postinc : int = numspechit
            numspechit--
            if (c2da_postinc == 0) {
                break
            }
            ld_1 = spechit[numspechit]
            side = P_PointOnLineSide(int(uint(c2da_mem[thing_1 + 24]) | uint(c2da_mem[thing_1 + 25]) << 0x8 | uint(c2da_mem[thing_1 + 26]) << 0x10 | uint(c2da_mem[thing_1 + 27]) << 0x18), int(uint(c2da_mem[thing_1 + 28]) | uint(c2da_mem[thing_1 + 29]) << 0x8 | uint(c2da_mem[thing_1 + 30]) << 0x10 | uint(c2da_mem[thing_1 + 31]) << 0x18), ld_1)
            oldside = P_PointOnLineSide(oldx, oldy, ld_1)
            if (side != oldside) {
                if (int16(uint(c2da_mem[ld_1 + 26]) | uint(c2da_mem[ld_1 + 27]) << 0x8) != 0) {
                    P_CrossSpecialLine(int(int64((ld_1 - lines) / 88)), oldside, thing_1)
                }
            }
        }
    }
    return 1u
}
[export, sideeffects]
def P_TeleportMove(var thing_2 : int; var x_1 : int; var y_1 : int) : uint {
    var xh_0 : int
    var yl_0 : int
    var yh_0 : int
    var bx_0 : int
    var by_0 : int
    var newsubsec_0 : int
    tmthing = int(thing_2)  // nolint:PERF020
    tmflags = int(uint(c2da_mem[thing_2 + 160]) | uint(c2da_mem[thing_2 + 161]) << 0x8 | uint(c2da_mem[thing_2 + 162]) << 0x10 | uint(c2da_mem[thing_2 + 163]) << 0x18)
    tmx = int(x_1)  // nolint:PERF020
    tmy = int(y_1)  // nolint:PERF020
    let c2da_fresh33 : int = y_1 + int(uint(c2da_mem[tmthing + 104]) | uint(c2da_mem[tmthing + 105]) << 0x8 | uint(c2da_mem[tmthing + 106]) << 0x10 | uint(c2da_mem[tmthing + 107]) << 0x18)
    let c2da_fresh34 : uint = uint(c2da_fresh33)
    c2da_mem[46576 + 0 * 4] = uint8(c2da_fresh34)
    c2da_mem[46576 + 0 * 4 + 1] = uint8(c2da_fresh34 >> 0x8)
    c2da_mem[46576 + 0 * 4 + 2] = uint8(c2da_fresh34 >> 0x10)
    c2da_mem[46576 + 0 * 4 + 3] = uint8(c2da_fresh34 >> 0x18)
    let c2da_fresh35 : int = y_1 - int(uint(c2da_mem[tmthing + 104]) | uint(c2da_mem[tmthing + 105]) << 0x8 | uint(c2da_mem[tmthing + 106]) << 0x10 | uint(c2da_mem[tmthing + 107]) << 0x18)
    let c2da_fresh36 : uint = uint(c2da_fresh35)
    c2da_mem[46576 + 1 * 4] = uint8(c2da_fresh36)
    c2da_mem[46576 + 1 * 4 + 1] = uint8(c2da_fresh36 >> 0x8)
    c2da_mem[46576 + 1 * 4 + 2] = uint8(c2da_fresh36 >> 0x10)
    c2da_mem[46576 + 1 * 4 + 3] = uint8(c2da_fresh36 >> 0x18)
    let c2da_fresh37 : int = x_1 + int(uint(c2da_mem[tmthing + 104]) | uint(c2da_mem[tmthing + 105]) << 0x8 | uint(c2da_mem[tmthing + 106]) << 0x10 | uint(c2da_mem[tmthing + 107]) << 0x18)
    let c2da_fresh38 : uint = uint(c2da_fresh37)
    c2da_mem[46576 + 3 * 4] = uint8(c2da_fresh38)
    c2da_mem[46576 + 3 * 4 + 1] = uint8(c2da_fresh38 >> 0x8)
    c2da_mem[46576 + 3 * 4 + 2] = uint8(c2da_fresh38 >> 0x10)
    c2da_mem[46576 + 3 * 4 + 3] = uint8(c2da_fresh38 >> 0x18)
    let c2da_fresh39 : int = x_1 - int(uint(c2da_mem[tmthing + 104]) | uint(c2da_mem[tmthing + 105]) << 0x8 | uint(c2da_mem[tmthing + 106]) << 0x10 | uint(c2da_mem[tmthing + 107]) << 0x18)
    let c2da_fresh40 : uint = uint(c2da_fresh39)
    c2da_mem[46576 + 2 * 4] = uint8(c2da_fresh40)
    c2da_mem[46576 + 2 * 4 + 1] = uint8(c2da_fresh40 >> 0x8)
    c2da_mem[46576 + 2 * 4 + 2] = uint8(c2da_fresh40 >> 0x10)
    c2da_mem[46576 + 2 * 4 + 3] = uint8(c2da_fresh40 >> 0x18)
    newsubsec_0 = R_PointInSubsector(x_1, y_1)
    ceilingline = 0
    let c2da_fresh41 : int = int(uint(c2da_mem[newsubsec_0]) | uint(c2da_mem[newsubsec_0 + 1]) << 0x8 | uint(c2da_mem[newsubsec_0 + 2]) << 0x10 | uint(c2da_mem[newsubsec_0 + 3]) << 0x18)
    tmdropoffz = int(uint(c2da_mem[c2da_fresh41]) | uint(c2da_mem[c2da_fresh41 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh41 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh41 + 3]) << 0x18)
    tmfloorz = int(tmdropoffz)  // nolint:PERF020
    let c2da_fresh42 : int = int(uint(c2da_mem[newsubsec_0]) | uint(c2da_mem[newsubsec_0 + 1]) << 0x8 | uint(c2da_mem[newsubsec_0 + 2]) << 0x10 | uint(c2da_mem[newsubsec_0 + 3]) << 0x18) + 4
    tmceilingz = int(uint(c2da_mem[c2da_fresh42]) | uint(c2da_mem[c2da_fresh42 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh42 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh42 + 3]) << 0x18)
    validcount = validcount + 1
    numspechit = 0
    xh_0 = int(uint(c2da_mem[46576 + 3 * 4]) | uint(c2da_mem[46576 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[46576 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[46576 + 3 * 4 + 3]) << 0x18) - int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18) + 32 * (1 << 16) >> 16 + 7
    yl_0 = int(uint(c2da_mem[46576 + 1 * 4]) | uint(c2da_mem[46576 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[46576 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[46576 + 1 * 4 + 3]) << 0x18) - int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18) - 32 * (1 << 16) >> 16 + 7
    yh_0 = int(uint(c2da_mem[46576 + 0 * 4]) | uint(c2da_mem[46576 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[46576 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[46576 + 0 * 4 + 3]) << 0x18) - int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18) + 32 * (1 << 16) >> 16 + 7
    bx_0 = int(uint(c2da_mem[46576 + 2 * 4]) | uint(c2da_mem[46576 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[46576 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[46576 + 2 * 4 + 3]) << 0x18) - int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18) - 32 * (1 << 16) >> 16 + 7
    while (bx_0 <= xh_0) {
        by_0 = yl_0
        while (by_0 <= yh_0) {
            if (P_BlockThingsIterator(bx_0, by_0, 135) == 0) {
                return 0u
            }
            by_0++
        }
        bx_0++
    }
    P_UnsetThingPosition(thing_2)
    let c2da_fresh43 : uint = uint(tmfloorz)
    c2da_mem[thing_2 + 96] = uint8(c2da_fresh43)
    c2da_mem[thing_2 + 97] = uint8(c2da_fresh43 >> 0x8)
    c2da_mem[thing_2 + 98] = uint8(c2da_fresh43 >> 0x10)
    c2da_mem[thing_2 + 99] = uint8(c2da_fresh43 >> 0x18)
    let c2da_fresh44 : uint = uint(tmceilingz)
    c2da_mem[thing_2 + 100] = uint8(c2da_fresh44)
    c2da_mem[thing_2 + 101] = uint8(c2da_fresh44 >> 0x8)
    c2da_mem[thing_2 + 102] = uint8(c2da_fresh44 >> 0x10)
    c2da_mem[thing_2 + 103] = uint8(c2da_fresh44 >> 0x18)
    let c2da_fresh45 : uint = uint(x_1)
    c2da_mem[thing_2 + 24] = uint8(c2da_fresh45)
    c2da_mem[thing_2 + 25] = uint8(c2da_fresh45 >> 0x8)
    c2da_mem[thing_2 + 26] = uint8(c2da_fresh45 >> 0x10)
    c2da_mem[thing_2 + 27] = uint8(c2da_fresh45 >> 0x18)
    let c2da_fresh46 : uint = uint(y_1)
    c2da_mem[thing_2 + 28] = uint8(c2da_fresh46)
    c2da_mem[thing_2 + 29] = uint8(c2da_fresh46 >> 0x8)
    c2da_mem[thing_2 + 30] = uint8(c2da_fresh46 >> 0x10)
    c2da_mem[thing_2 + 31] = uint8(c2da_fresh46 >> 0x18)
    P_SetThingPosition(thing_2)
    return 1u
}
[export, sideeffects]
def PIT_StompThing(var thing_3 : int) : uint {
    var blockdist_0 : int
    if ((int(uint(c2da_mem[thing_3 + 160]) | uint(c2da_mem[thing_3 + 161]) << 0x8 | uint(c2da_mem[thing_3 + 162]) << 0x10 | uint(c2da_mem[thing_3 + 163]) << 0x18) & 4) == 0) {
        return 1u
    }
    blockdist_0 = int(uint(c2da_mem[thing_3 + 104]) | uint(c2da_mem[thing_3 + 105]) << 0x8 | uint(c2da_mem[thing_3 + 106]) << 0x10 | uint(c2da_mem[thing_3 + 107]) << 0x18) + int(uint(c2da_mem[tmthing + 104]) | uint(c2da_mem[tmthing + 105]) << 0x8 | uint(c2da_mem[tmthing + 106]) << 0x10 | uint(c2da_mem[tmthing + 107]) << 0x18)
    if (c2da_std_abs(int(uint(c2da_mem[thing_3 + 24]) | uint(c2da_mem[thing_3 + 25]) << 0x8 | uint(c2da_mem[thing_3 + 26]) << 0x10 | uint(c2da_mem[thing_3 + 27]) << 0x18) - tmx) >= blockdist_0 || c2da_std_abs(int(uint(c2da_mem[thing_3 + 28]) | uint(c2da_mem[thing_3 + 29]) << 0x8 | uint(c2da_mem[thing_3 + 30]) << 0x10 | uint(c2da_mem[thing_3 + 31]) << 0x18) - tmy) >= blockdist_0) {
        return 1u
    }
    if (thing_3 == tmthing) {
        return 1u
    }
    if (int(uint(c2da_mem[tmthing + 192]) | uint(c2da_mem[tmthing + 193]) << 0x8 | uint(c2da_mem[tmthing + 194]) << 0x10 | uint(c2da_mem[tmthing + 195]) << 0x18) == 0 && gamemap != 30) {
        return 0u
    }
    P_DamageMobj(thing_3, tmthing, tmthing, 10000)
    return 1u
}
[export, sideeffects]
def P_SlideMove(var mo : int) {
    var leadx : int
    var leady : int
    var trailx : int
    var traily : int
    var newx : int
    var newy : int
    var hitcount : int
    slidemo = int(mo)  // nolint:PERF020
    hitcount = 0
    label 0:
    hitcount++
    if (hitcount == 3) {
        goto label 16
    }
    if (int(uint(c2da_mem[mo + 112]) | uint(c2da_mem[mo + 113]) << 0x8 | uint(c2da_mem[mo + 114]) << 0x10 | uint(c2da_mem[mo + 115]) << 0x18) > 0) {
        goto label 15
    }
    leadx = int(uint(c2da_mem[mo + 24]) | uint(c2da_mem[mo + 25]) << 0x8 | uint(c2da_mem[mo + 26]) << 0x10 | uint(c2da_mem[mo + 27]) << 0x18) - int(uint(c2da_mem[mo + 104]) | uint(c2da_mem[mo + 105]) << 0x8 | uint(c2da_mem[mo + 106]) << 0x10 | uint(c2da_mem[mo + 107]) << 0x18)
    trailx = int(uint(c2da_mem[mo + 24]) | uint(c2da_mem[mo + 25]) << 0x8 | uint(c2da_mem[mo + 26]) << 0x10 | uint(c2da_mem[mo + 27]) << 0x18) + int(uint(c2da_mem[mo + 104]) | uint(c2da_mem[mo + 105]) << 0x8 | uint(c2da_mem[mo + 106]) << 0x10 | uint(c2da_mem[mo + 107]) << 0x18)
    label 1:
    if (int(uint(c2da_mem[mo + 116]) | uint(c2da_mem[mo + 117]) << 0x8 | uint(c2da_mem[mo + 118]) << 0x10 | uint(c2da_mem[mo + 119]) << 0x18) > 0) {
        goto label 14
    }
    leady = int(uint(c2da_mem[mo + 28]) | uint(c2da_mem[mo + 29]) << 0x8 | uint(c2da_mem[mo + 30]) << 0x10 | uint(c2da_mem[mo + 31]) << 0x18) - int(uint(c2da_mem[mo + 104]) | uint(c2da_mem[mo + 105]) << 0x8 | uint(c2da_mem[mo + 106]) << 0x10 | uint(c2da_mem[mo + 107]) << 0x18)
    traily = int(uint(c2da_mem[mo + 28]) | uint(c2da_mem[mo + 29]) << 0x8 | uint(c2da_mem[mo + 30]) << 0x10 | uint(c2da_mem[mo + 31]) << 0x18) + int(uint(c2da_mem[mo + 104]) | uint(c2da_mem[mo + 105]) << 0x8 | uint(c2da_mem[mo + 106]) << 0x10 | uint(c2da_mem[mo + 107]) << 0x18)
    label 2:
    bestslidefrac = (1 << 16) + 1
    P_PathTraverse(leadx, leady, leadx + int(uint(c2da_mem[mo + 112]) | uint(c2da_mem[mo + 113]) << 0x8 | uint(c2da_mem[mo + 114]) << 0x10 | uint(c2da_mem[mo + 115]) << 0x18), leady + int(uint(c2da_mem[mo + 116]) | uint(c2da_mem[mo + 117]) << 0x8 | uint(c2da_mem[mo + 118]) << 0x10 | uint(c2da_mem[mo + 119]) << 0x18), 1, 136)
    P_PathTraverse(trailx, leady, trailx + int(uint(c2da_mem[mo + 112]) | uint(c2da_mem[mo + 113]) << 0x8 | uint(c2da_mem[mo + 114]) << 0x10 | uint(c2da_mem[mo + 115]) << 0x18), leady + int(uint(c2da_mem[mo + 116]) | uint(c2da_mem[mo + 117]) << 0x8 | uint(c2da_mem[mo + 118]) << 0x10 | uint(c2da_mem[mo + 119]) << 0x18), 1, 136)
    P_PathTraverse(leadx, traily, leadx + int(uint(c2da_mem[mo + 112]) | uint(c2da_mem[mo + 113]) << 0x8 | uint(c2da_mem[mo + 114]) << 0x10 | uint(c2da_mem[mo + 115]) << 0x18), traily + int(uint(c2da_mem[mo + 116]) | uint(c2da_mem[mo + 117]) << 0x8 | uint(c2da_mem[mo + 118]) << 0x10 | uint(c2da_mem[mo + 119]) << 0x18), 1, 136)
    if (bestslidefrac == (1 << 16) + 1) {
        goto label 13
    }
    bestslidefrac -= 2048
    if (bestslidefrac > 0) {
        goto label 8
    }
    label 3:
    bestslidefrac = (1 << 16) - (bestslidefrac + 2048)
    if (bestslidefrac > 1 << 16) {
        goto label 7
    }
    label 4:
    if (bestslidefrac <= 0) {
        goto label 6
    }
    tmxmove = FixedMul(int(uint(c2da_mem[mo + 112]) | uint(c2da_mem[mo + 113]) << 0x8 | uint(c2da_mem[mo + 114]) << 0x10 | uint(c2da_mem[mo + 115]) << 0x18), bestslidefrac)
    tmymove = FixedMul(int(uint(c2da_mem[mo + 116]) | uint(c2da_mem[mo + 117]) << 0x8 | uint(c2da_mem[mo + 118]) << 0x10 | uint(c2da_mem[mo + 119]) << 0x18), bestslidefrac)
    P_HitSlideLine(bestslideline)
    let c2da_fresh47 : uint = uint(tmxmove)
    c2da_mem[mo + 112] = uint8(c2da_fresh47)
    c2da_mem[mo + 113] = uint8(c2da_fresh47 >> 0x8)
    c2da_mem[mo + 114] = uint8(c2da_fresh47 >> 0x10)
    c2da_mem[mo + 115] = uint8(c2da_fresh47 >> 0x18)
    let c2da_fresh48 : uint = uint(tmymove)
    c2da_mem[mo + 116] = uint8(c2da_fresh48)
    c2da_mem[mo + 117] = uint8(c2da_fresh48 >> 0x8)
    c2da_mem[mo + 118] = uint8(c2da_fresh48 >> 0x10)
    c2da_mem[mo + 119] = uint8(c2da_fresh48 >> 0x18)
    if (P_TryMove(mo, int(uint(c2da_mem[mo + 24]) | uint(c2da_mem[mo + 25]) << 0x8 | uint(c2da_mem[mo + 26]) << 0x10 | uint(c2da_mem[mo + 27]) << 0x18) + tmxmove, int(uint(c2da_mem[mo + 28]) | uint(c2da_mem[mo + 29]) << 0x8 | uint(c2da_mem[mo + 30]) << 0x10 | uint(c2da_mem[mo + 31]) << 0x18) + tmymove) == 0) {
        goto label 5
    }
    return
    label 5:
    goto label 0
    label 6:
    return
    label 7:
    bestslidefrac = 1 << 16
    goto label 4
    label 8:
    newx = FixedMul(int(uint(c2da_mem[mo + 112]) | uint(c2da_mem[mo + 113]) << 0x8 | uint(c2da_mem[mo + 114]) << 0x10 | uint(c2da_mem[mo + 115]) << 0x18), bestslidefrac)
    newy = FixedMul(int(uint(c2da_mem[mo + 116]) | uint(c2da_mem[mo + 117]) << 0x8 | uint(c2da_mem[mo + 118]) << 0x10 | uint(c2da_mem[mo + 119]) << 0x18), bestslidefrac)
    if (P_TryMove(mo, int(uint(c2da_mem[mo + 24]) | uint(c2da_mem[mo + 25]) << 0x8 | uint(c2da_mem[mo + 26]) << 0x10 | uint(c2da_mem[mo + 27]) << 0x18) + newx, int(uint(c2da_mem[mo + 28]) | uint(c2da_mem[mo + 29]) << 0x8 | uint(c2da_mem[mo + 30]) << 0x10 | uint(c2da_mem[mo + 31]) << 0x18) + newy) == 0) {
        goto label 9
    }
    goto label 3
    label 9:
    label 10:
    if (P_TryMove(mo, int(uint(c2da_mem[mo + 24]) | uint(c2da_mem[mo + 25]) << 0x8 | uint(c2da_mem[mo + 26]) << 0x10 | uint(c2da_mem[mo + 27]) << 0x18), int(uint(c2da_mem[mo + 28]) | uint(c2da_mem[mo + 29]) << 0x8 | uint(c2da_mem[mo + 30]) << 0x10 | uint(c2da_mem[mo + 31]) << 0x18) + int(uint(c2da_mem[mo + 116]) | uint(c2da_mem[mo + 117]) << 0x8 | uint(c2da_mem[mo + 118]) << 0x10 | uint(c2da_mem[mo + 119]) << 0x18)) == 0) {
        goto label 12
    }
    label 11:
    return
    label 12:
    P_TryMove(mo, int(uint(c2da_mem[mo + 24]) | uint(c2da_mem[mo + 25]) << 0x8 | uint(c2da_mem[mo + 26]) << 0x10 | uint(c2da_mem[mo + 27]) << 0x18) + int(uint(c2da_mem[mo + 112]) | uint(c2da_mem[mo + 113]) << 0x8 | uint(c2da_mem[mo + 114]) << 0x10 | uint(c2da_mem[mo + 115]) << 0x18), int(uint(c2da_mem[mo + 28]) | uint(c2da_mem[mo + 29]) << 0x8 | uint(c2da_mem[mo + 30]) << 0x10 | uint(c2da_mem[mo + 31]) << 0x18))
    goto label 11
    label 13:
    goto label 10
    label 14:
    leady = int(uint(c2da_mem[mo + 28]) | uint(c2da_mem[mo + 29]) << 0x8 | uint(c2da_mem[mo + 30]) << 0x10 | uint(c2da_mem[mo + 31]) << 0x18) + int(uint(c2da_mem[mo + 104]) | uint(c2da_mem[mo + 105]) << 0x8 | uint(c2da_mem[mo + 106]) << 0x10 | uint(c2da_mem[mo + 107]) << 0x18)
    traily = int(uint(c2da_mem[mo + 28]) | uint(c2da_mem[mo + 29]) << 0x8 | uint(c2da_mem[mo + 30]) << 0x10 | uint(c2da_mem[mo + 31]) << 0x18) - int(uint(c2da_mem[mo + 104]) | uint(c2da_mem[mo + 105]) << 0x8 | uint(c2da_mem[mo + 106]) << 0x10 | uint(c2da_mem[mo + 107]) << 0x18)
    goto label 2
    label 15:
    leadx = int(uint(c2da_mem[mo + 24]) | uint(c2da_mem[mo + 25]) << 0x8 | uint(c2da_mem[mo + 26]) << 0x10 | uint(c2da_mem[mo + 27]) << 0x18) + int(uint(c2da_mem[mo + 104]) | uint(c2da_mem[mo + 105]) << 0x8 | uint(c2da_mem[mo + 106]) << 0x10 | uint(c2da_mem[mo + 107]) << 0x18)
    trailx = int(uint(c2da_mem[mo + 24]) | uint(c2da_mem[mo + 25]) << 0x8 | uint(c2da_mem[mo + 26]) << 0x10 | uint(c2da_mem[mo + 27]) << 0x18) - int(uint(c2da_mem[mo + 104]) | uint(c2da_mem[mo + 105]) << 0x8 | uint(c2da_mem[mo + 106]) << 0x10 | uint(c2da_mem[mo + 107]) << 0x18)
    goto label 1
    label 16:
    goto label 10
    panic("unreachable: fell out of a translated control-flow graph")
}
var tmymove : int = default<int>

var tmxmove : int = default<int>

var bestslideline : int = default<int>

[export, sideeffects]
def P_HitSlideLine(var ld_2 : int) {
    var side_0 : int
    var lineangle : uint
    var moveangle : uint
    var deltaangle : uint
    var movelen : int
    var newlen : int
    if ((uint(c2da_mem[ld_2 + 52]) | uint(c2da_mem[ld_2 + 53]) << 0x8 | uint(c2da_mem[ld_2 + 54]) << 0x10 | uint(c2da_mem[ld_2 + 55]) << 0x18) == 0u) {
        tmymove = 0
        return
    }
    if ((uint(c2da_mem[ld_2 + 52]) | uint(c2da_mem[ld_2 + 53]) << 0x8 | uint(c2da_mem[ld_2 + 54]) << 0x10 | uint(c2da_mem[ld_2 + 55]) << 0x18) == 1u) {
        tmxmove = 0
        return
    }
    side_0 = P_PointOnLineSide(int(uint(c2da_mem[slidemo + 24]) | uint(c2da_mem[slidemo + 25]) << 0x8 | uint(c2da_mem[slidemo + 26]) << 0x10 | uint(c2da_mem[slidemo + 27]) << 0x18), int(uint(c2da_mem[slidemo + 28]) | uint(c2da_mem[slidemo + 29]) << 0x8 | uint(c2da_mem[slidemo + 30]) << 0x10 | uint(c2da_mem[slidemo + 31]) << 0x18), ld_2)
    lineangle = uint(R_PointToAngle2(0, 0, int(uint(c2da_mem[ld_2 + 16]) | uint(c2da_mem[ld_2 + 17]) << 0x8 | uint(c2da_mem[ld_2 + 18]) << 0x10 | uint(c2da_mem[ld_2 + 19]) << 0x18), int(uint(c2da_mem[ld_2 + 20]) | uint(c2da_mem[ld_2 + 21]) << 0x8 | uint(c2da_mem[ld_2 + 22]) << 0x10 | uint(c2da_mem[ld_2 + 23]) << 0x18)))
    if (side_0 == 1) {
        lineangle += 0x80000000u
    }
    moveangle = uint(R_PointToAngle2(0, 0, tmxmove, tmymove))
    deltaangle = moveangle - lineangle
    if (deltaangle > 0x80000000u) {
        deltaangle += 0x80000000u
    }
    lineangle >>= 19u
    deltaangle >>= 19u
    movelen = P_AproxDistance(tmxmove, tmymove)
    newlen = FixedMul(movelen, int(uint(c2da_mem[finecosine + int(deltaangle) * 4]) | uint(c2da_mem[finecosine + int(deltaangle) * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + int(deltaangle) * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + int(deltaangle) * 4 + 3]) << 0x18))
    tmxmove = FixedMul(newlen, int(uint(c2da_mem[finecosine + int(lineangle) * 4]) | uint(c2da_mem[finecosine + int(lineangle) * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + int(lineangle) * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + int(lineangle) * 4 + 3]) << 0x18))
    tmymove = FixedMul(newlen, int(uint(c2da_mem[257920 + int(lineangle) * 4]) | uint(c2da_mem[257920 + int(lineangle) * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + int(lineangle) * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + int(lineangle) * 4 + 3]) << 0x18))
    return
}
var slidemo : int = default<int>

var bestslidefrac : int = default<int>

[export, sideeffects]
def PTR_SlideTraverse(var in_0 : int) : uint {
    var li : int
    if ((uint(c2da_mem[in_0 + 4]) | uint(c2da_mem[in_0 + 5]) << 0x8 | uint(c2da_mem[in_0 + 6]) << 0x10 | uint(c2da_mem[in_0 + 7]) << 0x18) == 0) {
        goto label 9
    }
    label 0:
    li = int(uint(c2da_mem[in_0 + 8]) | uint(c2da_mem[in_0 + 9]) << 0x8 | uint(c2da_mem[in_0 + 10]) << 0x10 | uint(c2da_mem[in_0 + 11]) << 0x18)
    if ((int(int16(uint(c2da_mem[li + 24]) | uint(c2da_mem[li + 25]) << 0x8)) & 4) == 0) {
        goto label 7
    }
    P_LineOpening(li)
    if (int(uint(c2da_mem[49680]) | uint(c2da_mem[49681]) << 0x8 | uint(c2da_mem[49682]) << 0x10 | uint(c2da_mem[49683]) << 0x18) < int(uint(c2da_mem[slidemo + 108]) | uint(c2da_mem[slidemo + 109]) << 0x8 | uint(c2da_mem[slidemo + 110]) << 0x10 | uint(c2da_mem[slidemo + 111]) << 0x18)) {
        goto label 6
    }
    if (int(uint(c2da_mem[49664]) | uint(c2da_mem[49665]) << 0x8 | uint(c2da_mem[49666]) << 0x10 | uint(c2da_mem[49667]) << 0x18) - int(uint(c2da_mem[slidemo + 32]) | uint(c2da_mem[slidemo + 33]) << 0x8 | uint(c2da_mem[slidemo + 34]) << 0x10 | uint(c2da_mem[slidemo + 35]) << 0x18) < int(uint(c2da_mem[slidemo + 108]) | uint(c2da_mem[slidemo + 109]) << 0x8 | uint(c2da_mem[slidemo + 110]) << 0x10 | uint(c2da_mem[slidemo + 111]) << 0x18)) {
        goto label 5
    }
    if (int(uint(c2da_mem[49648]) | uint(c2da_mem[49649]) << 0x8 | uint(c2da_mem[49650]) << 0x10 | uint(c2da_mem[49651]) << 0x18) - int(uint(c2da_mem[slidemo + 32]) | uint(c2da_mem[slidemo + 33]) << 0x8 | uint(c2da_mem[slidemo + 34]) << 0x10 | uint(c2da_mem[slidemo + 35]) << 0x18) > 24 * (1 << 16)) {
        goto label 1
    }
    return 1u
    label 1:
    label 2:
    if (int(uint(c2da_mem[in_0]) | uint(c2da_mem[in_0 + 1]) << 0x8 | uint(c2da_mem[in_0 + 2]) << 0x10 | uint(c2da_mem[in_0 + 3]) << 0x18) < bestslidefrac) {
        goto label 4
    }
    label 3:
    return 0u
    label 4:
    secondslidefrac = int(bestslidefrac)  // nolint:PERF020
    secondslideline = int(bestslideline)  // nolint:PERF020
    bestslidefrac = int(uint(c2da_mem[in_0]) | uint(c2da_mem[in_0 + 1]) << 0x8 | uint(c2da_mem[in_0 + 2]) << 0x10 | uint(c2da_mem[in_0 + 3]) << 0x18)
    bestslideline = li
    goto label 3
    label 5:
    goto label 2
    label 6:
    goto label 2
    label 7:
    if (P_PointOnLineSide(int(uint(c2da_mem[slidemo + 24]) | uint(c2da_mem[slidemo + 25]) << 0x8 | uint(c2da_mem[slidemo + 26]) << 0x10 | uint(c2da_mem[slidemo + 27]) << 0x18), int(uint(c2da_mem[slidemo + 28]) | uint(c2da_mem[slidemo + 29]) << 0x8 | uint(c2da_mem[slidemo + 30]) << 0x10 | uint(c2da_mem[slidemo + 31]) << 0x18), li) != 0) {
        goto label 8
    }
    goto label 2
    label 8:
    return 1u
    label 9:
    I_Error(360279, [])
    goto label 0
    panic("unreachable: fell out of a translated control-flow graph")
}
var secondslideline : int = default<int>

var secondslidefrac : int = default<int>

[export, sideeffects]
def P_UseLines(var player : int) {
    var angle : int
    var x1 : int
    var y1 : int
    var x2 : int
    var y2 : int
    usething = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18)
    let c2da_fresh49 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 56
    angle = int((uint(c2da_mem[c2da_fresh49]) | uint(c2da_mem[c2da_fresh49 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh49 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh49 + 3]) << 0x18) >> 19u)
    let c2da_fresh50 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 24
    x1 = int(uint(c2da_mem[c2da_fresh50]) | uint(c2da_mem[c2da_fresh50 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh50 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh50 + 3]) << 0x18)
    let c2da_fresh51 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 28
    y1 = int(uint(c2da_mem[c2da_fresh51]) | uint(c2da_mem[c2da_fresh51 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh51 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh51 + 3]) << 0x18)
    x2 = x1 + (64 * (1 << 16) >> 16) * int(uint(c2da_mem[finecosine + angle * 4]) | uint(c2da_mem[finecosine + angle * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + angle * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + angle * 4 + 3]) << 0x18)
    y2 = y1 + (64 * (1 << 16) >> 16) * int(uint(c2da_mem[257920 + angle * 4]) | uint(c2da_mem[257920 + angle * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + angle * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + angle * 4 + 3]) << 0x18)
    P_PathTraverse(x1, y1, x2, y2, 1, 137)
    return
}
[export, sideeffects]
def PTR_UseTraverse(var in_1 : int) : uint {
    var side_1 : int
    let c2da_fresh52 : int = int(uint(c2da_mem[in_1 + 8]) | uint(c2da_mem[in_1 + 9]) << 0x8 | uint(c2da_mem[in_1 + 10]) << 0x10 | uint(c2da_mem[in_1 + 11]) << 0x18) + 26
    if (int16(uint(c2da_mem[c2da_fresh52]) | uint(c2da_mem[c2da_fresh52 + 1]) << 0x8) == 0) {
        P_LineOpening(int(uint(c2da_mem[in_1 + 8]) | uint(c2da_mem[in_1 + 9]) << 0x8 | uint(c2da_mem[in_1 + 10]) << 0x10 | uint(c2da_mem[in_1 + 11]) << 0x18))
        if (int(uint(c2da_mem[49680]) | uint(c2da_mem[49681]) << 0x8 | uint(c2da_mem[49682]) << 0x10 | uint(c2da_mem[49683]) << 0x18) <= 0) {
            S_StartSound(usething, 81)
            return 0u
        }
        return 1u
    }
    side_1 = 0
    if (P_PointOnLineSide(int(uint(c2da_mem[usething + 24]) | uint(c2da_mem[usething + 25]) << 0x8 | uint(c2da_mem[usething + 26]) << 0x10 | uint(c2da_mem[usething + 27]) << 0x18), int(uint(c2da_mem[usething + 28]) | uint(c2da_mem[usething + 29]) << 0x8 | uint(c2da_mem[usething + 30]) << 0x10 | uint(c2da_mem[usething + 31]) << 0x18), int(uint(c2da_mem[in_1 + 8]) | uint(c2da_mem[in_1 + 9]) << 0x8 | uint(c2da_mem[in_1 + 10]) << 0x10 | uint(c2da_mem[in_1 + 11]) << 0x18)) == 1) {
        side_1 = 1
    }
    P_UseSpecialLine(usething, int(uint(c2da_mem[in_1 + 8]) | uint(c2da_mem[in_1 + 9]) << 0x8 | uint(c2da_mem[in_1 + 10]) << 0x10 | uint(c2da_mem[in_1 + 11]) << 0x18), side_1)
    return 0u
}
var usething : int = default<int>

[export, sideeffects]
def P_ChangeSector(var sector : int; var crunch : uint) : uint {
    var x_2 : int
    var y_3 : int
    nofit = 0u
    crushchange = uint(crunch)  // nolint:PERF020
    x_2 = int(uint(c2da_mem[sector + 32 + 2 * 4]) | uint(c2da_mem[sector + 32 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[sector + 32 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[sector + 32 + 2 * 4 + 3]) << 0x18)
    while (x_2 <= int(uint(c2da_mem[sector + 32 + 3 * 4]) | uint(c2da_mem[sector + 32 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[sector + 32 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[sector + 32 + 3 * 4 + 3]) << 0x18)) {
        y_3 = int(uint(c2da_mem[sector + 32 + 1 * 4]) | uint(c2da_mem[sector + 32 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[sector + 32 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[sector + 32 + 1 * 4 + 3]) << 0x18)
        while (y_3 <= int(uint(c2da_mem[sector + 32 + 0 * 4]) | uint(c2da_mem[sector + 32 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[sector + 32 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[sector + 32 + 0 * 4 + 3]) << 0x18)) {
            P_BlockThingsIterator(x_2, y_3, 138)
            y_3++
        }
        x_2++
    }
    return nofit
}
[export, sideeffects]
def PIT_ChangeSector(var thing_4 : int) : uint {
    var mo_0 : int
    if (P_ThingHeightClip(thing_4) != 0x0) {
        return 1u
    }
    if (int(uint(c2da_mem[thing_4 + 164]) | uint(c2da_mem[thing_4 + 165]) << 0x8 | uint(c2da_mem[thing_4 + 166]) << 0x10 | uint(c2da_mem[thing_4 + 167]) << 0x18) <= 0) {
        P_SetMobjState(thing_4, 895u)
        let c2da_fresh53 : int = int(uint(c2da_mem[thing_4 + 160]) | uint(c2da_mem[thing_4 + 161]) << 0x8 | uint(c2da_mem[thing_4 + 162]) << 0x10 | uint(c2da_mem[thing_4 + 163]) << 0x18) & ~2
        let c2da_fresh54 : uint = uint(c2da_fresh53)
        c2da_mem[thing_4 + 160] = uint8(c2da_fresh54)
        c2da_mem[thing_4 + 161] = uint8(c2da_fresh54 >> 0x8)
        c2da_mem[thing_4 + 162] = uint8(c2da_fresh54 >> 0x10)
        c2da_mem[thing_4 + 163] = uint8(c2da_fresh54 >> 0x18)
        let c2da_fresh55 : int = 0
        let c2da_fresh56 : uint = uint(c2da_fresh55)
        c2da_mem[thing_4 + 108] = uint8(c2da_fresh56)
        c2da_mem[thing_4 + 109] = uint8(c2da_fresh56 >> 0x8)
        c2da_mem[thing_4 + 110] = uint8(c2da_fresh56 >> 0x10)
        c2da_mem[thing_4 + 111] = uint8(c2da_fresh56 >> 0x18)
        let c2da_fresh57 : int = 0
        let c2da_fresh58 : uint = uint(c2da_fresh57)
        c2da_mem[thing_4 + 104] = uint8(c2da_fresh58)
        c2da_mem[thing_4 + 105] = uint8(c2da_fresh58 >> 0x8)
        c2da_mem[thing_4 + 106] = uint8(c2da_fresh58 >> 0x10)
        c2da_mem[thing_4 + 107] = uint8(c2da_fresh58 >> 0x18)
        return 1u
    }
    if ((int(uint(c2da_mem[thing_4 + 160]) | uint(c2da_mem[thing_4 + 161]) << 0x8 | uint(c2da_mem[thing_4 + 162]) << 0x10 | uint(c2da_mem[thing_4 + 163]) << 0x18) & 131072) != 0) {
        P_RemoveMobj(thing_4)
        return 1u
    }
    if ((int(uint(c2da_mem[thing_4 + 160]) | uint(c2da_mem[thing_4 + 161]) << 0x8 | uint(c2da_mem[thing_4 + 162]) << 0x10 | uint(c2da_mem[thing_4 + 163]) << 0x18) & 4) == 0) {
        return 1u
    }
    nofit = 1u
    if (crushchange != 0x0 && (leveltime & 3) == 0) {
        P_DamageMobj(thing_4, 0, 0, 10)
        mo_0 = P_SpawnMobj(int(uint(c2da_mem[thing_4 + 24]) | uint(c2da_mem[thing_4 + 25]) << 0x8 | uint(c2da_mem[thing_4 + 26]) << 0x10 | uint(c2da_mem[thing_4 + 27]) << 0x18), int(uint(c2da_mem[thing_4 + 28]) | uint(c2da_mem[thing_4 + 29]) << 0x8 | uint(c2da_mem[thing_4 + 30]) << 0x10 | uint(c2da_mem[thing_4 + 31]) << 0x18), int(uint(c2da_mem[thing_4 + 32]) | uint(c2da_mem[thing_4 + 33]) << 0x8 | uint(c2da_mem[thing_4 + 34]) << 0x10 | uint(c2da_mem[thing_4 + 35]) << 0x18) + int(uint(c2da_mem[thing_4 + 108]) | uint(c2da_mem[thing_4 + 109]) << 0x8 | uint(c2da_mem[thing_4 + 110]) << 0x10 | uint(c2da_mem[thing_4 + 111]) << 0x18) / 2, 38u)
        let c2da_fresh59 : int = P_Random() - P_Random() << 12
        let c2da_fresh60 : uint = uint(c2da_fresh59)
        c2da_mem[mo_0 + 112] = uint8(c2da_fresh60)
        c2da_mem[mo_0 + 113] = uint8(c2da_fresh60 >> 0x8)
        c2da_mem[mo_0 + 114] = uint8(c2da_fresh60 >> 0x10)
        c2da_mem[mo_0 + 115] = uint8(c2da_fresh60 >> 0x18)
        let c2da_fresh61 : int = P_Random() - P_Random() << 12
        let c2da_fresh62 : uint = uint(c2da_fresh61)
        c2da_mem[mo_0 + 116] = uint8(c2da_fresh62)
        c2da_mem[mo_0 + 117] = uint8(c2da_fresh62 >> 0x8)
        c2da_mem[mo_0 + 118] = uint8(c2da_fresh62 >> 0x10)
        c2da_mem[mo_0 + 119] = uint8(c2da_fresh62 >> 0x18)
    }
    return 1u
}
[export, sideeffects]
def P_ThingHeightClip(var thing_5 : int) : uint {
    var onfloor : uint = uint(int(uint(c2da_mem[thing_5 + 32]) | uint(c2da_mem[thing_5 + 33]) << 0x8 | uint(c2da_mem[thing_5 + 34]) << 0x10 | uint(c2da_mem[thing_5 + 35]) << 0x18) == int(uint(c2da_mem[thing_5 + 96]) | uint(c2da_mem[thing_5 + 97]) << 0x8 | uint(c2da_mem[thing_5 + 98]) << 0x10 | uint(c2da_mem[thing_5 + 99]) << 0x18) ? 1 : 0)
    P_CheckPosition(thing_5, int(uint(c2da_mem[thing_5 + 24]) | uint(c2da_mem[thing_5 + 25]) << 0x8 | uint(c2da_mem[thing_5 + 26]) << 0x10 | uint(c2da_mem[thing_5 + 27]) << 0x18), int(uint(c2da_mem[thing_5 + 28]) | uint(c2da_mem[thing_5 + 29]) << 0x8 | uint(c2da_mem[thing_5 + 30]) << 0x10 | uint(c2da_mem[thing_5 + 31]) << 0x18))
    let c2da_fresh63 : uint = uint(tmfloorz)
    c2da_mem[thing_5 + 96] = uint8(c2da_fresh63)
    c2da_mem[thing_5 + 97] = uint8(c2da_fresh63 >> 0x8)
    c2da_mem[thing_5 + 98] = uint8(c2da_fresh63 >> 0x10)
    c2da_mem[thing_5 + 99] = uint8(c2da_fresh63 >> 0x18)
    let c2da_fresh64 : uint = uint(tmceilingz)
    c2da_mem[thing_5 + 100] = uint8(c2da_fresh64)
    c2da_mem[thing_5 + 101] = uint8(c2da_fresh64 >> 0x8)
    c2da_mem[thing_5 + 102] = uint8(c2da_fresh64 >> 0x10)
    c2da_mem[thing_5 + 103] = uint8(c2da_fresh64 >> 0x18)
    if (onfloor != 0x0) {
        let c2da_fresh65 : int = int(uint(c2da_mem[thing_5 + 96]) | uint(c2da_mem[thing_5 + 97]) << 0x8 | uint(c2da_mem[thing_5 + 98]) << 0x10 | uint(c2da_mem[thing_5 + 99]) << 0x18)
        let c2da_fresh66 : uint = uint(c2da_fresh65)
        c2da_mem[thing_5 + 32] = uint8(c2da_fresh66)
        c2da_mem[thing_5 + 33] = uint8(c2da_fresh66 >> 0x8)
        c2da_mem[thing_5 + 34] = uint8(c2da_fresh66 >> 0x10)
        c2da_mem[thing_5 + 35] = uint8(c2da_fresh66 >> 0x18)
    } elif (int(uint(c2da_mem[thing_5 + 32]) | uint(c2da_mem[thing_5 + 33]) << 0x8 | uint(c2da_mem[thing_5 + 34]) << 0x10 | uint(c2da_mem[thing_5 + 35]) << 0x18) + int(uint(c2da_mem[thing_5 + 108]) | uint(c2da_mem[thing_5 + 109]) << 0x8 | uint(c2da_mem[thing_5 + 110]) << 0x10 | uint(c2da_mem[thing_5 + 111]) << 0x18) > int(uint(c2da_mem[thing_5 + 100]) | uint(c2da_mem[thing_5 + 101]) << 0x8 | uint(c2da_mem[thing_5 + 102]) << 0x10 | uint(c2da_mem[thing_5 + 103]) << 0x18)) {
        let c2da_fresh67 : int = int(uint(c2da_mem[thing_5 + 100]) | uint(c2da_mem[thing_5 + 101]) << 0x8 | uint(c2da_mem[thing_5 + 102]) << 0x10 | uint(c2da_mem[thing_5 + 103]) << 0x18) - int(uint(c2da_mem[thing_5 + 108]) | uint(c2da_mem[thing_5 + 109]) << 0x8 | uint(c2da_mem[thing_5 + 110]) << 0x10 | uint(c2da_mem[thing_5 + 111]) << 0x18)
        let c2da_fresh68 : uint = uint(c2da_fresh67)
        c2da_mem[thing_5 + 32] = uint8(c2da_fresh68)
        c2da_mem[thing_5 + 33] = uint8(c2da_fresh68 >> 0x8)
        c2da_mem[thing_5 + 34] = uint8(c2da_fresh68 >> 0x10)
        c2da_mem[thing_5 + 35] = uint8(c2da_fresh68 >> 0x18)
    }
    if (int(uint(c2da_mem[thing_5 + 100]) | uint(c2da_mem[thing_5 + 101]) << 0x8 | uint(c2da_mem[thing_5 + 102]) << 0x10 | uint(c2da_mem[thing_5 + 103]) << 0x18) - int(uint(c2da_mem[thing_5 + 96]) | uint(c2da_mem[thing_5 + 97]) << 0x8 | uint(c2da_mem[thing_5 + 98]) << 0x10 | uint(c2da_mem[thing_5 + 99]) << 0x18) < int(uint(c2da_mem[thing_5 + 108]) | uint(c2da_mem[thing_5 + 109]) << 0x8 | uint(c2da_mem[thing_5 + 110]) << 0x10 | uint(c2da_mem[thing_5 + 111]) << 0x18)) {
        return 0u
    }
    return 1u
}
var linetarget : int = default<int>

[export, sideeffects]
def P_AimLineAttack(var t1 : int; var angle_0 : uint; var distance : int) : int {
    var x2_0 : int
    var y2_0 : int
    t1 = P_SubstNullMobj(t1)
    angle_0 >>= 19u
    shootthing = int(t1)  // nolint:PERF020
    x2_0 = int(uint(c2da_mem[t1 + 24]) | uint(c2da_mem[t1 + 25]) << 0x8 | uint(c2da_mem[t1 + 26]) << 0x10 | uint(c2da_mem[t1 + 27]) << 0x18) + (distance >> 16) * int(uint(c2da_mem[finecosine + int(angle_0) * 4]) | uint(c2da_mem[finecosine + int(angle_0) * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + int(angle_0) * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + int(angle_0) * 4 + 3]) << 0x18)
    y2_0 = int(uint(c2da_mem[t1 + 28]) | uint(c2da_mem[t1 + 29]) << 0x8 | uint(c2da_mem[t1 + 30]) << 0x10 | uint(c2da_mem[t1 + 31]) << 0x18) + (distance >> 16) * int(uint(c2da_mem[257920 + int(angle_0) * 4]) | uint(c2da_mem[257920 + int(angle_0) * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + int(angle_0) * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + int(angle_0) * 4 + 3]) << 0x18)
    shootz = int(uint(c2da_mem[t1 + 32]) | uint(c2da_mem[t1 + 33]) << 0x8 | uint(c2da_mem[t1 + 34]) << 0x10 | uint(c2da_mem[t1 + 35]) << 0x18) + (int(uint(c2da_mem[t1 + 108]) | uint(c2da_mem[t1 + 109]) << 0x8 | uint(c2da_mem[t1 + 110]) << 0x10 | uint(c2da_mem[t1 + 111]) << 0x18) >> 1) + 8 * (1 << 16)
    topslope = 100 * (1 << 16) / 160
    bottomslope = -100 * (1 << 16) / 160
    attackrange = int(distance)  // nolint:PERF020
    linetarget = 0
    P_PathTraverse(int(uint(c2da_mem[t1 + 24]) | uint(c2da_mem[t1 + 25]) << 0x8 | uint(c2da_mem[t1 + 26]) << 0x10 | uint(c2da_mem[t1 + 27]) << 0x18), int(uint(c2da_mem[t1 + 28]) | uint(c2da_mem[t1 + 29]) << 0x8 | uint(c2da_mem[t1 + 30]) << 0x10 | uint(c2da_mem[t1 + 31]) << 0x18), x2_0, y2_0, 1 | 2, 139)
    if (linetarget != 0) {
        return aimslope
    }
    return 0
}
var aimslope : int = default<int>

[export, sideeffects]
def PTR_AimTraverse(var in_2 : int) : uint {
    var li_0 : int
    var th : int
    var slope : int
    var thingtopslope : int
    var thingbottomslope : int
    var dist : int
    if ((uint(c2da_mem[in_2 + 4]) | uint(c2da_mem[in_2 + 5]) << 0x8 | uint(c2da_mem[in_2 + 6]) << 0x10 | uint(c2da_mem[in_2 + 7]) << 0x18) != 0x0) {
        li_0 = int(uint(c2da_mem[in_2 + 8]) | uint(c2da_mem[in_2 + 9]) << 0x8 | uint(c2da_mem[in_2 + 10]) << 0x10 | uint(c2da_mem[in_2 + 11]) << 0x18)
        if ((int(int16(uint(c2da_mem[li_0 + 24]) | uint(c2da_mem[li_0 + 25]) << 0x8)) & 4) == 0) {
            return 0u
        }
        P_LineOpening(li_0)
        if (int(uint(c2da_mem[49648]) | uint(c2da_mem[49649]) << 0x8 | uint(c2da_mem[49650]) << 0x10 | uint(c2da_mem[49651]) << 0x18) >= int(uint(c2da_mem[49664]) | uint(c2da_mem[49665]) << 0x8 | uint(c2da_mem[49666]) << 0x10 | uint(c2da_mem[49667]) << 0x18)) {
            return 0u
        }
        dist = FixedMul(attackrange, int(uint(c2da_mem[in_2]) | uint(c2da_mem[in_2 + 1]) << 0x8 | uint(c2da_mem[in_2 + 2]) << 0x10 | uint(c2da_mem[in_2 + 3]) << 0x18))
        var c2da_fresh71 : int = 1
        if (!(int(uint(c2da_mem[li_0 + 64]) | uint(c2da_mem[li_0 + 65]) << 0x8 | uint(c2da_mem[li_0 + 66]) << 0x10 | uint(c2da_mem[li_0 + 67]) << 0x18) == 0)) {
            let c2da_fresh69 : int = int(uint(c2da_mem[li_0 + 56]) | uint(c2da_mem[li_0 + 57]) << 0x8 | uint(c2da_mem[li_0 + 58]) << 0x10 | uint(c2da_mem[li_0 + 59]) << 0x18)
            let c2da_fresh70 : int = int(uint(c2da_mem[li_0 + 64]) | uint(c2da_mem[li_0 + 65]) << 0x8 | uint(c2da_mem[li_0 + 66]) << 0x10 | uint(c2da_mem[li_0 + 67]) << 0x18)
            if (!(int(uint(c2da_mem[c2da_fresh69]) | uint(c2da_mem[c2da_fresh69 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh69 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh69 + 3]) << 0x18) != int(uint(c2da_mem[c2da_fresh70]) | uint(c2da_mem[c2da_fresh70 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh70 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh70 + 3]) << 0x18))) {
                c2da_fresh71 = 0
            }
        }
        if (c2da_fresh71 != 0) {
            slope = FixedDiv(int(uint(c2da_mem[49648]) | uint(c2da_mem[49649]) << 0x8 | uint(c2da_mem[49650]) << 0x10 | uint(c2da_mem[49651]) << 0x18) - shootz, dist)
            if (slope > bottomslope) {
                bottomslope = slope
            }
        }
        var c2da_fresh74 : int = 1
        if (!(int(uint(c2da_mem[li_0 + 64]) | uint(c2da_mem[li_0 + 65]) << 0x8 | uint(c2da_mem[li_0 + 66]) << 0x10 | uint(c2da_mem[li_0 + 67]) << 0x18) == 0)) {
            let c2da_fresh72 : int = int(uint(c2da_mem[li_0 + 56]) | uint(c2da_mem[li_0 + 57]) << 0x8 | uint(c2da_mem[li_0 + 58]) << 0x10 | uint(c2da_mem[li_0 + 59]) << 0x18) + 4
            let c2da_fresh73 : int = int(uint(c2da_mem[li_0 + 64]) | uint(c2da_mem[li_0 + 65]) << 0x8 | uint(c2da_mem[li_0 + 66]) << 0x10 | uint(c2da_mem[li_0 + 67]) << 0x18) + 4
            if (!(int(uint(c2da_mem[c2da_fresh72]) | uint(c2da_mem[c2da_fresh72 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh72 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh72 + 3]) << 0x18) != int(uint(c2da_mem[c2da_fresh73]) | uint(c2da_mem[c2da_fresh73 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh73 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh73 + 3]) << 0x18))) {
                c2da_fresh74 = 0
            }
        }
        if (c2da_fresh74 != 0) {
            slope = FixedDiv(int(uint(c2da_mem[49664]) | uint(c2da_mem[49665]) << 0x8 | uint(c2da_mem[49666]) << 0x10 | uint(c2da_mem[49667]) << 0x18) - shootz, dist)
            if (slope < topslope) {
                topslope = slope
            }
        }
        if (topslope <= bottomslope) {
            return 0u
        }
        return 1u
    }
    th = int(uint(c2da_mem[in_2 + 8]) | uint(c2da_mem[in_2 + 9]) << 0x8 | uint(c2da_mem[in_2 + 10]) << 0x10 | uint(c2da_mem[in_2 + 11]) << 0x18)
    if (th == shootthing) {
        return 1u
    }
    if ((int(uint(c2da_mem[th + 160]) | uint(c2da_mem[th + 161]) << 0x8 | uint(c2da_mem[th + 162]) << 0x10 | uint(c2da_mem[th + 163]) << 0x18) & 4) == 0) {
        return 1u
    }
    dist = FixedMul(attackrange, int(uint(c2da_mem[in_2]) | uint(c2da_mem[in_2 + 1]) << 0x8 | uint(c2da_mem[in_2 + 2]) << 0x10 | uint(c2da_mem[in_2 + 3]) << 0x18))
    thingtopslope = FixedDiv(int(uint(c2da_mem[th + 32]) | uint(c2da_mem[th + 33]) << 0x8 | uint(c2da_mem[th + 34]) << 0x10 | uint(c2da_mem[th + 35]) << 0x18) + int(uint(c2da_mem[th + 108]) | uint(c2da_mem[th + 109]) << 0x8 | uint(c2da_mem[th + 110]) << 0x10 | uint(c2da_mem[th + 111]) << 0x18) - shootz, dist)
    if (thingtopslope < bottomslope) {
        return 1u
    }
    thingbottomslope = FixedDiv(int(uint(c2da_mem[th + 32]) | uint(c2da_mem[th + 33]) << 0x8 | uint(c2da_mem[th + 34]) << 0x10 | uint(c2da_mem[th + 35]) << 0x18) - shootz, dist)
    if (thingbottomslope > topslope) {
        return 1u
    }
    if (thingtopslope > topslope) {
        thingtopslope = topslope
    }
    if (thingbottomslope < bottomslope) {
        thingbottomslope = bottomslope
    }
    aimslope = (thingtopslope + thingbottomslope) / 2
    linetarget = th
    return 0u
}
var shootz : int = default<int>

var attackrange : int = default<int>

var shootthing : int = default<int>

[export, sideeffects]
def P_LineAttack(var t1_0 : int; var angle_1 : uint; var distance_0 : int; var slope_0 : int; var damage_0 : int) {
    var x2_1 : int
    var y2_1 : int
    angle_1 >>= 19u
    shootthing = int(t1_0)  // nolint:PERF020
    la_damage = int(damage_0)  // nolint:PERF020
    x2_1 = int(uint(c2da_mem[t1_0 + 24]) | uint(c2da_mem[t1_0 + 25]) << 0x8 | uint(c2da_mem[t1_0 + 26]) << 0x10 | uint(c2da_mem[t1_0 + 27]) << 0x18) + (distance_0 >> 16) * int(uint(c2da_mem[finecosine + int(angle_1) * 4]) | uint(c2da_mem[finecosine + int(angle_1) * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + int(angle_1) * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + int(angle_1) * 4 + 3]) << 0x18)
    y2_1 = int(uint(c2da_mem[t1_0 + 28]) | uint(c2da_mem[t1_0 + 29]) << 0x8 | uint(c2da_mem[t1_0 + 30]) << 0x10 | uint(c2da_mem[t1_0 + 31]) << 0x18) + (distance_0 >> 16) * int(uint(c2da_mem[257920 + int(angle_1) * 4]) | uint(c2da_mem[257920 + int(angle_1) * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + int(angle_1) * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + int(angle_1) * 4 + 3]) << 0x18)
    shootz = int(uint(c2da_mem[t1_0 + 32]) | uint(c2da_mem[t1_0 + 33]) << 0x8 | uint(c2da_mem[t1_0 + 34]) << 0x10 | uint(c2da_mem[t1_0 + 35]) << 0x18) + (int(uint(c2da_mem[t1_0 + 108]) | uint(c2da_mem[t1_0 + 109]) << 0x8 | uint(c2da_mem[t1_0 + 110]) << 0x10 | uint(c2da_mem[t1_0 + 111]) << 0x18) >> 1) + 8 * (1 << 16)
    attackrange = int(distance_0)  // nolint:PERF020
    aimslope = int(slope_0)  // nolint:PERF020
    P_PathTraverse(int(uint(c2da_mem[t1_0 + 24]) | uint(c2da_mem[t1_0 + 25]) << 0x8 | uint(c2da_mem[t1_0 + 26]) << 0x10 | uint(c2da_mem[t1_0 + 27]) << 0x18), int(uint(c2da_mem[t1_0 + 28]) | uint(c2da_mem[t1_0 + 29]) << 0x8 | uint(c2da_mem[t1_0 + 30]) << 0x10 | uint(c2da_mem[t1_0 + 31]) << 0x18), x2_1, y2_1, 1 | 2, 140)
    return
}
[export, sideeffects]
def PTR_ShootTraverse(var in_3 : int) : uint {
    var x_3 : int
    var y_4 : int
    var z : int
    var frac : int
    var li_1 : int
    var th_0 : int
    var slope_1 : int
    var dist_0 : int
    var thingtopslope_0 : int
    var thingbottomslope_0 : int
    var c2da_fresh82 : int
    if ((uint(c2da_mem[in_3 + 4]) | uint(c2da_mem[in_3 + 5]) << 0x8 | uint(c2da_mem[in_3 + 6]) << 0x10 | uint(c2da_mem[in_3 + 7]) << 0x18) != 0x0) {
        goto label 8
    }
    th_0 = int(uint(c2da_mem[in_3 + 8]) | uint(c2da_mem[in_3 + 9]) << 0x8 | uint(c2da_mem[in_3 + 10]) << 0x10 | uint(c2da_mem[in_3 + 11]) << 0x18)
    if (th_0 == shootthing) {
        goto label 7
    }
    if ((int(uint(c2da_mem[th_0 + 160]) | uint(c2da_mem[th_0 + 161]) << 0x8 | uint(c2da_mem[th_0 + 162]) << 0x10 | uint(c2da_mem[th_0 + 163]) << 0x18) & 4) == 0) {
        goto label 6
    }
    dist_0 = FixedMul(attackrange, int(uint(c2da_mem[in_3]) | uint(c2da_mem[in_3 + 1]) << 0x8 | uint(c2da_mem[in_3 + 2]) << 0x10 | uint(c2da_mem[in_3 + 3]) << 0x18))
    thingtopslope_0 = FixedDiv(int(uint(c2da_mem[th_0 + 32]) | uint(c2da_mem[th_0 + 33]) << 0x8 | uint(c2da_mem[th_0 + 34]) << 0x10 | uint(c2da_mem[th_0 + 35]) << 0x18) + int(uint(c2da_mem[th_0 + 108]) | uint(c2da_mem[th_0 + 109]) << 0x8 | uint(c2da_mem[th_0 + 110]) << 0x10 | uint(c2da_mem[th_0 + 111]) << 0x18) - shootz, dist_0)
    if (thingtopslope_0 < aimslope) {
        goto label 5
    }
    thingbottomslope_0 = FixedDiv(int(uint(c2da_mem[th_0 + 32]) | uint(c2da_mem[th_0 + 33]) << 0x8 | uint(c2da_mem[th_0 + 34]) << 0x10 | uint(c2da_mem[th_0 + 35]) << 0x18) - shootz, dist_0)
    if (thingbottomslope_0 > aimslope) {
        goto label 4
    }
    frac = int(uint(c2da_mem[in_3]) | uint(c2da_mem[in_3 + 1]) << 0x8 | uint(c2da_mem[in_3 + 2]) << 0x10 | uint(c2da_mem[in_3 + 3]) << 0x18) - FixedDiv(10 * (1 << 16), attackrange)
    x_3 = int(uint(c2da_mem[49616]) | uint(c2da_mem[49617]) << 0x8 | uint(c2da_mem[49618]) << 0x10 | uint(c2da_mem[49619]) << 0x18) + FixedMul(int(uint(c2da_mem[49624]) | uint(c2da_mem[49625]) << 0x8 | uint(c2da_mem[49626]) << 0x10 | uint(c2da_mem[49627]) << 0x18), frac)
    y_4 = int(uint(c2da_mem[49620]) | uint(c2da_mem[49621]) << 0x8 | uint(c2da_mem[49622]) << 0x10 | uint(c2da_mem[49623]) << 0x18) + FixedMul(int(uint(c2da_mem[49628]) | uint(c2da_mem[49629]) << 0x8 | uint(c2da_mem[49630]) << 0x10 | uint(c2da_mem[49631]) << 0x18), frac)
    z = shootz + FixedMul(aimslope, FixedMul(frac, attackrange))
    let c2da_fresh83 : int = int(uint(c2da_mem[in_3 + 8]) | uint(c2da_mem[in_3 + 9]) << 0x8 | uint(c2da_mem[in_3 + 10]) << 0x10 | uint(c2da_mem[in_3 + 11]) << 0x18) + 160
    if ((int(uint(c2da_mem[c2da_fresh83]) | uint(c2da_mem[c2da_fresh83 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh83 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh83 + 3]) << 0x18) & 524288) != 0) {
        goto label 3
    }
    P_SpawnBlood(x_3, y_4, z, la_damage)
    label 0:
    if (la_damage != 0) {
        goto label 2
    }
    label 1:
    return 0u
    label 2:
    P_DamageMobj(th_0, shootthing, shootthing, la_damage)
    goto label 1
    label 3:
    P_SpawnPuff(x_3, y_4, z)
    goto label 0
    label 4:
    return 1u
    label 5:
    return 1u
    label 6:
    return 1u
    label 7:
    return 1u
    label 8:
    li_1 = int(uint(c2da_mem[in_3 + 8]) | uint(c2da_mem[in_3 + 9]) << 0x8 | uint(c2da_mem[in_3 + 10]) << 0x10 | uint(c2da_mem[in_3 + 11]) << 0x18)
    if (int16(uint(c2da_mem[li_1 + 26]) | uint(c2da_mem[li_1 + 27]) << 0x8) != 0) {
        goto label 26
    }
    label 9:
    if ((int(int16(uint(c2da_mem[li_1 + 24]) | uint(c2da_mem[li_1 + 25]) << 0x8)) & 4) == 0) {
        goto label 25
    }
    P_LineOpening(li_1)
    dist_0 = FixedMul(attackrange, int(uint(c2da_mem[in_3]) | uint(c2da_mem[in_3 + 1]) << 0x8 | uint(c2da_mem[in_3 + 2]) << 0x10 | uint(c2da_mem[in_3 + 3]) << 0x18))
    if (int(uint(c2da_mem[li_1 + 64]) | uint(c2da_mem[li_1 + 65]) << 0x8 | uint(c2da_mem[li_1 + 66]) << 0x10 | uint(c2da_mem[li_1 + 67]) << 0x18) == 0) {
        goto label 22
    }
    let c2da_fresh75 : int = int(uint(c2da_mem[li_1 + 56]) | uint(c2da_mem[li_1 + 57]) << 0x8 | uint(c2da_mem[li_1 + 58]) << 0x10 | uint(c2da_mem[li_1 + 59]) << 0x18)
    let c2da_fresh76 : int = int(uint(c2da_mem[li_1 + 64]) | uint(c2da_mem[li_1 + 65]) << 0x8 | uint(c2da_mem[li_1 + 66]) << 0x10 | uint(c2da_mem[li_1 + 67]) << 0x18)
    if (int(uint(c2da_mem[c2da_fresh75]) | uint(c2da_mem[c2da_fresh75 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh75 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh75 + 3]) << 0x18) != int(uint(c2da_mem[c2da_fresh76]) | uint(c2da_mem[c2da_fresh76 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh76 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh76 + 3]) << 0x18)) {
        goto label 20
    }
    label 10:
    let c2da_fresh77 : int = int(uint(c2da_mem[li_1 + 56]) | uint(c2da_mem[li_1 + 57]) << 0x8 | uint(c2da_mem[li_1 + 58]) << 0x10 | uint(c2da_mem[li_1 + 59]) << 0x18) + 4
    let c2da_fresh78 : int = int(uint(c2da_mem[li_1 + 64]) | uint(c2da_mem[li_1 + 65]) << 0x8 | uint(c2da_mem[li_1 + 66]) << 0x10 | uint(c2da_mem[li_1 + 67]) << 0x18) + 4
    if (int(uint(c2da_mem[c2da_fresh77]) | uint(c2da_mem[c2da_fresh77 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh77 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh77 + 3]) << 0x18) != int(uint(c2da_mem[c2da_fresh78]) | uint(c2da_mem[c2da_fresh78 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh78 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh78 + 3]) << 0x18)) {
        goto label 13
    }
    label 11:
    label 12:
    return 1u
    label 13:
    slope_1 = FixedDiv(int(uint(c2da_mem[49664]) | uint(c2da_mem[49665]) << 0x8 | uint(c2da_mem[49666]) << 0x10 | uint(c2da_mem[49667]) << 0x18) - shootz, dist_0)
    if (slope_1 < aimslope) {
        goto label 14
    }
    goto label 11
    label 14:
    label 15:
    frac = int(uint(c2da_mem[in_3]) | uint(c2da_mem[in_3 + 1]) << 0x8 | uint(c2da_mem[in_3 + 2]) << 0x10 | uint(c2da_mem[in_3 + 3]) << 0x18) - FixedDiv(4 * (1 << 16), attackrange)
    x_3 = int(uint(c2da_mem[49616]) | uint(c2da_mem[49617]) << 0x8 | uint(c2da_mem[49618]) << 0x10 | uint(c2da_mem[49619]) << 0x18) + FixedMul(int(uint(c2da_mem[49624]) | uint(c2da_mem[49625]) << 0x8 | uint(c2da_mem[49626]) << 0x10 | uint(c2da_mem[49627]) << 0x18), frac)
    y_4 = int(uint(c2da_mem[49620]) | uint(c2da_mem[49621]) << 0x8 | uint(c2da_mem[49622]) << 0x10 | uint(c2da_mem[49623]) << 0x18) + FixedMul(int(uint(c2da_mem[49628]) | uint(c2da_mem[49629]) << 0x8 | uint(c2da_mem[49630]) << 0x10 | uint(c2da_mem[49631]) << 0x18), frac)
    z = shootz + FixedMul(aimslope, FixedMul(frac, attackrange))
    let c2da_fresh79 : int = int(uint(c2da_mem[li_1 + 56]) | uint(c2da_mem[li_1 + 57]) << 0x8 | uint(c2da_mem[li_1 + 58]) << 0x10 | uint(c2da_mem[li_1 + 59]) << 0x18) + 10
    if (int(int16(uint(c2da_mem[c2da_fresh79]) | uint(c2da_mem[c2da_fresh79 + 1]) << 0x8)) == skyflatnum) {
        goto label 17
    }
    label 16:
    P_SpawnPuff(x_3, y_4, z)
    return 0u
    label 17:
    let c2da_fresh80 : int = int(uint(c2da_mem[li_1 + 56]) | uint(c2da_mem[li_1 + 57]) << 0x8 | uint(c2da_mem[li_1 + 58]) << 0x10 | uint(c2da_mem[li_1 + 59]) << 0x18) + 4
    if (z > int(uint(c2da_mem[c2da_fresh80]) | uint(c2da_mem[c2da_fresh80 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh80 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh80 + 3]) << 0x18)) {
        goto label 19
    }
    c2da_fresh82 = 0
    if (int(uint(c2da_mem[li_1 + 64]) | uint(c2da_mem[li_1 + 65]) << 0x8 | uint(c2da_mem[li_1 + 66]) << 0x10 | uint(c2da_mem[li_1 + 67]) << 0x18) != 0) {
        let c2da_fresh81 : int = int(uint(c2da_mem[li_1 + 64]) | uint(c2da_mem[li_1 + 65]) << 0x8 | uint(c2da_mem[li_1 + 66]) << 0x10 | uint(c2da_mem[li_1 + 67]) << 0x18) + 10
        if (int(int16(uint(c2da_mem[c2da_fresh81]) | uint(c2da_mem[c2da_fresh81 + 1]) << 0x8)) == skyflatnum) {
            c2da_fresh82 = 1
        }
    }
    if (c2da_fresh82 != 0) {
        goto label 18
    }
    goto label 16
    label 18:
    return 0u
    label 19:
    return 0u
    label 20:
    slope_1 = FixedDiv(int(uint(c2da_mem[49648]) | uint(c2da_mem[49649]) << 0x8 | uint(c2da_mem[49650]) << 0x10 | uint(c2da_mem[49651]) << 0x18) - shootz, dist_0)
    if (slope_1 > aimslope) {
        goto label 21
    }
    goto label 10
    label 21:
    goto label 15
    label 22:
    slope_1 = FixedDiv(int(uint(c2da_mem[49648]) | uint(c2da_mem[49649]) << 0x8 | uint(c2da_mem[49650]) << 0x10 | uint(c2da_mem[49651]) << 0x18) - shootz, dist_0)
    if (slope_1 > aimslope) {
        goto label 24
    }
    slope_1 = FixedDiv(int(uint(c2da_mem[49664]) | uint(c2da_mem[49665]) << 0x8 | uint(c2da_mem[49666]) << 0x10 | uint(c2da_mem[49667]) << 0x18) - shootz, dist_0)
    if (slope_1 < aimslope) {
        goto label 23
    }
    goto label 12
    label 23:
    goto label 15
    label 24:
    goto label 15
    label 25:
    goto label 15
    label 26:
    P_ShootSpecialLine(shootthing, li_1)
    goto label 9
    panic("unreachable: fell out of a translated control-flow graph")
}
var la_damage : int = default<int>

[export, sideeffects]
def P_RadiusAttack(var spot : int; var source : int; var damage_1 : int) {
    var x_4 : int
    var y_5 : int
    var xl_1 : int
    var xh_1 : int
    var yl_1 : int
    var yh_1 : int
    var dist_1 : int = damage_1 + 32 * (1 << 16) << 16
    yh_1 = int(uint(c2da_mem[spot + 28]) | uint(c2da_mem[spot + 29]) << 0x8 | uint(c2da_mem[spot + 30]) << 0x10 | uint(c2da_mem[spot + 31]) << 0x18) + dist_1 - int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18) >> 16 + 7
    yl_1 = int(uint(c2da_mem[spot + 28]) | uint(c2da_mem[spot + 29]) << 0x8 | uint(c2da_mem[spot + 30]) << 0x10 | uint(c2da_mem[spot + 31]) << 0x18) - dist_1 - int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18) >> 16 + 7
    xh_1 = int(uint(c2da_mem[spot + 24]) | uint(c2da_mem[spot + 25]) << 0x8 | uint(c2da_mem[spot + 26]) << 0x10 | uint(c2da_mem[spot + 27]) << 0x18) + dist_1 - int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18) >> 16 + 7
    xl_1 = int(uint(c2da_mem[spot + 24]) | uint(c2da_mem[spot + 25]) << 0x8 | uint(c2da_mem[spot + 26]) << 0x10 | uint(c2da_mem[spot + 27]) << 0x18) - dist_1 - int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18) >> 16 + 7
    bombspot = int(spot)  // nolint:PERF020
    bombsource = int(source)  // nolint:PERF020
    bombdamage = int(damage_1)  // nolint:PERF020
    y_5 = yl_1
    while (y_5 <= yh_1) {
        x_4 = xl_1
        while (x_4 <= xh_1) {
            P_BlockThingsIterator(x_4, y_5, 141)
            x_4++
        }
        y_5++
    }
    return
}
[export, sideeffects]
def PIT_RadiusAttack(var thing_6 : int) : uint {
    var dx : int
    var dy : int
    var dist_2 : int
    if ((int(uint(c2da_mem[thing_6 + 160]) | uint(c2da_mem[thing_6 + 161]) << 0x8 | uint(c2da_mem[thing_6 + 162]) << 0x10 | uint(c2da_mem[thing_6 + 163]) << 0x18) & 4) == 0) {
        return 1u
    }
    if ((uint(c2da_mem[thing_6 + 128]) | uint(c2da_mem[thing_6 + 129]) << 0x8 | uint(c2da_mem[thing_6 + 130]) << 0x10 | uint(c2da_mem[thing_6 + 131]) << 0x18) == 21u || (uint(c2da_mem[thing_6 + 128]) | uint(c2da_mem[thing_6 + 129]) << 0x8 | uint(c2da_mem[thing_6 + 130]) << 0x10 | uint(c2da_mem[thing_6 + 131]) << 0x18) == 19u) {
        return 1u
    }
    dx = c2da_std_abs(int(uint(c2da_mem[thing_6 + 24]) | uint(c2da_mem[thing_6 + 25]) << 0x8 | uint(c2da_mem[thing_6 + 26]) << 0x10 | uint(c2da_mem[thing_6 + 27]) << 0x18) - int(uint(c2da_mem[bombspot + 24]) | uint(c2da_mem[bombspot + 25]) << 0x8 | uint(c2da_mem[bombspot + 26]) << 0x10 | uint(c2da_mem[bombspot + 27]) << 0x18))
    dy = c2da_std_abs(int(uint(c2da_mem[thing_6 + 28]) | uint(c2da_mem[thing_6 + 29]) << 0x8 | uint(c2da_mem[thing_6 + 30]) << 0x10 | uint(c2da_mem[thing_6 + 31]) << 0x18) - int(uint(c2da_mem[bombspot + 28]) | uint(c2da_mem[bombspot + 29]) << 0x8 | uint(c2da_mem[bombspot + 30]) << 0x10 | uint(c2da_mem[bombspot + 31]) << 0x18))
    dist_2 = dx > dy ? dx : dy
    dist_2 = dist_2 - int(uint(c2da_mem[thing_6 + 104]) | uint(c2da_mem[thing_6 + 105]) << 0x8 | uint(c2da_mem[thing_6 + 106]) << 0x10 | uint(c2da_mem[thing_6 + 107]) << 0x18) >> 16
    if (dist_2 < 0) {
        dist_2 = 0
    }
    if (dist_2 >= bombdamage) {
        return 1u
    }
    if (P_CheckSight(thing_6, bombspot) != 0x0) {
        P_DamageMobj(thing_6, bombspot, bombsource, bombdamage - dist_2)
    }
    return 1u
}
var bombdamage : int = default<int>

var bombsource : int = default<int>

var bombspot : int = default<int>


// This unit's static data, at heap offset 360192.
let private c2da_lin_static_p_map_seg = fixed_array<int>(360196, 113)
let private c2da_lin_static_p_map = fixed_array<uint64>(0x746968636570732dul, 0x7469686365705300ul, 0x3a6e75727265764ful, 0x676e696e72615720ul, 0x656c62616e75203aul, 0x6c756d65206f7420ul, 0x766f206e61657461ul, 0x6877206e75727265ul, 0x736d756e20657265ul, 0x253d746968636570ul, 0x535f525450000a69ul, 0x766172546564696cul, 0x6f6e203a65737265ul, 0x656e696c20612074ul, 0x3ful)

[init]
def private c2da_lin_init_static_p_map() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_p_map_seg[s * 2]
        for (k in range(c2da_lin_static_p_map_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_p_map[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_p_map() {
    if (length(c2da_fn_table10) < 142) {
        resize(c2da_fn_table10, 142)
    }
    c2da_fn_table10[134] = @@PIT_CheckLine
    c2da_fn_table10[133] = @@PIT_CheckThing
    c2da_fn_table10[135] = @@PIT_StompThing
    c2da_fn_table10[136] = @@PTR_SlideTraverse
    c2da_fn_table10[137] = @@PTR_UseTraverse
    c2da_fn_table10[138] = @@PIT_ChangeSector
    c2da_fn_table10[139] = @@PTR_AimTraverse
    c2da_fn_table10[140] = @@PTR_ShootTraverse
    c2da_fn_table10[141] = @@PIT_RadiusAttack
}

[init]
def private c2da_lin_relink_init_p_map() {
    c2da_relink_p_map()
}
