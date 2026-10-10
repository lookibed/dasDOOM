var private c2da_str_p_map_0 : array<int8> = [int8(45), int8(115), int8(112), int8(101), int8(99), int8(104), int8(105), int8(116), int8(0)]

var private c2da_str_p_map_1 : array<int8> = [int8(83), int8(112), int8(101), int8(99), int8(104), int8(105), int8(116), int8(79), int8(118), int8(101), int8(114), int8(114), int8(117), int8(110), int8(58), int8(32), int8(87), int8(97), int8(114), int8(110), int8(105), int8(110), int8(103), int8(58), int8(32), int8(117), int8(110), int8(97), int8(98), int8(108), int8(101), int8(32), int8(116), int8(111), int8(32), int8(101), int8(109), int8(117), int8(108), int8(97), int8(116), int8(101), int8(97), int8(110), int8(32), int8(111), int8(118), int8(101), int8(114), int8(114), int8(117), int8(110), int8(32), int8(119), int8(104), int8(101), int8(114), int8(101), int8(32), int8(110), int8(117), int8(109), int8(115), int8(112), int8(101), int8(99), int8(104), int8(105), int8(116), int8(61), int8(37), int8(105), int8(10), int8(0)]

var private c2da_str_p_map_2 : array<int8> = [int8(80), int8(84), int8(82), int8(95), int8(83), int8(108), int8(105), int8(100), int8(101), int8(84), int8(114), int8(97), int8(118), int8(101), int8(114), int8(115), int8(101), int8(58), int8(32), int8(110), int8(111), int8(116), int8(32), int8(97), int8(32), int8(108), int8(105), int8(110), int8(101), int8(63), int8(0)]

var private SpechitOverrun__baseaddr : uint = 0u

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

var ceilingline : line_s? = default<line_s?>

var spechit : line_s? [20]

var numspechit : int = default<int>

[export, sideeffects]
def P_CheckPosition(var thing : mobj_s?; var x : int; var y : int) : uint {
    var xh : int
    var yl : int
    var yh : int
    var bx : int
    var by : int
    var newsubsec : subsector_s?
    tmthing = unsafe(reinterpret<mobj_s?>(thing))
    tmflags = int(thing.flags)  // nolint:PERF020
    tmx = int(x)  // nolint:PERF020
    tmy = int(y)  // nolint:PERF020
    tmbbox[0] = y + tmthing.radius
    tmbbox[1] = y - tmthing.radius
    tmbbox[3] = x + tmthing.radius
    tmbbox[2] = x - tmthing.radius
    newsubsec = unsafe(reinterpret<subsector_s?>(unsafe(reinterpret<subsector_s?>(R_PointInSubsector(x, y)))))
    ceilingline = null
    tmdropoffz = int(newsubsec.sector.floorheight)  // nolint:PERF020
    tmfloorz = int(tmdropoffz)  // nolint:PERF020
    tmceilingz = int(newsubsec.sector.ceilingheight)  // nolint:PERF020
    validcount = validcount + 1
    numspechit = 0
    if ((tmflags & 4096) != 0) {
        return 1u
    }
    xh = tmbbox[3] - bmaporgx + 32 * (1 << 16) >> 16 + 7
    yl = tmbbox[1] - bmaporgy - 32 * (1 << 16) >> 16 + 7
    yh = tmbbox[0] - bmaporgy + 32 * (1 << 16) >> 16 + 7
    bx = tmbbox[2] - bmaporgx - 32 * (1 << 16) >> 16 + 7
    while (bx <= xh) {
        by = yl
        while (by <= yh) {
            if (P_BlockThingsIterator(bx, by, @@PIT_CheckThing) == 0) {
                return 0u
            }
            by++
        }
        bx++
    }
    xh = tmbbox[3] - bmaporgx >> 16 + 7
    yl = tmbbox[1] - bmaporgy >> 16 + 7
    yh = tmbbox[0] - bmaporgy >> 16 + 7
    bx = tmbbox[2] - bmaporgx >> 16 + 7
    while (bx <= xh) {
        by = yl
        while (by <= yh) {
            if (P_BlockLinesIterator(bx, by, @@PIT_CheckLine) == 0) {
                return 0u
            }
            by++
        }
        bx++
    }
    return 1u
}
[export, sideeffects]
def PIT_CheckLine(var ld : line_s?) : uint {
    var c2da_fresh0 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(ld)) + 36ul))
    var c2da_fresh2 : int = 1
    if (!(tmbbox[3] <= unsafe(unsafe(reinterpret<int?>(c2da_fresh0))[2]))) {
        var c2da_fresh1 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(ld)) + 36ul))
        if (!(tmbbox[2] >= unsafe(unsafe(reinterpret<int?>(c2da_fresh1))[3]))) {
            c2da_fresh2 = 0
        }
    }
    var c2da_fresh4 : int = 1
    if (!(c2da_fresh2 != 0)) {
        var c2da_fresh3 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(ld)) + 36ul))
        if (!(tmbbox[0] <= unsafe(unsafe(reinterpret<int?>(c2da_fresh3))[1]))) {
            c2da_fresh4 = 0
        }
    }
    var c2da_fresh6 : int = 1
    if (!(c2da_fresh4 != 0)) {
        var c2da_fresh5 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(ld)) + 36ul))
        if (!(tmbbox[1] >= unsafe(unsafe(reinterpret<int?>(c2da_fresh5))[0]))) {
            c2da_fresh6 = 0
        }
    }
    if (c2da_fresh6 != 0) {
        return 1u
    }
    if (P_BoxOnLineSide(unsafe(addr<int?>(tmbbox[0])), ld) != -1) {
        return 1u
    }
    if (ld.backsector == null) {
        return 0u
    }
    if ((tmthing.flags & 65536) == 0) {
        if ((int(ld.flags) & 1) != 0) {
            return 0u
        }
        if (tmthing.player == null && (int(ld.flags) & 2) != 0) {
            return 0u
        }
    }
    P_LineOpening(ld)
    if (opentop < tmceilingz) {
        tmceilingz = opentop
        ceilingline = unsafe(reinterpret<line_s?>(ld))
    }
    if (openbottom > tmfloorz) {
        tmfloorz = openbottom
    }
    if (lowfloor < tmdropoffz) {
        tmdropoffz = lowfloor
    }
    if (ld.special != 0) {
        spechit[numspechit] = unsafe(reinterpret<line_s?>(ld))
        numspechit++
        if (numspechit > 8) {
            SpechitOverrun(ld)
        }
    }
    return 1u
}
[sideeffects]
def private SpechitOverrun(var ld_0 : line_s?) {
    var addr_0 : uint
    var p : int
    if (SpechitOverrun__baseaddr == 0u) {
        p = M_CheckParmWithArgs(unsafe(addr<int8?>(c2da_str_p_map_0[0])), 1)
        if (p > 0) {
            M_StrToInt(unsafe(reinterpret<int8 const?>(unsafe(myargv[p + 1]))), unsafe(addr<int?>(SpechitOverrun__baseaddr)))
        } else {
            SpechitOverrun__baseaddr = 0x1c09c98u
        }
    }
    addr_0 = uint(int64(SpechitOverrun__baseaddr) + unsafe(ld_0 - lines) * 62l)
    if (numspechit == 9 || numspechit == 10 || numspechit == 11 || numspechit == 12) {
        tmbbox[numspechit - 9] = int(addr_0)
    } elif (numspechit == 13) {
        crushchange = addr_0
    } elif (numspechit == 14) {
        nofit = addr_0
    } else {
        c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_p_map_1[0])), [C2daVaArg(tag = 1, i64 = int64(numspechit), f64 = 0.0lf, raw = 0x0)])
    }
    return
}
var nofit : uint = default<uint>

var crushchange : uint = default<uint>

var tmbbox : int[4]

var tmdropoffz : int = default<int>

var tmthing : mobj_s? = default<mobj_s?>

[export, sideeffects]
def PIT_CheckThing(var thing_0 : mobj_s?) : uint {
    var blockdist : int
    var solid : uint
    var damage : int
    if ((thing_0.flags & (2 | 1 | 4)) == 0) {
        return 1u
    }
    blockdist = thing_0.radius + tmthing.radius
    if (c2da_std_abs(thing_0.x - tmx) >= blockdist || c2da_std_abs(thing_0.y - tmy) >= blockdist) {
        return 1u
    }
    if (thing_0 == tmthing) {
        return 1u
    }
    if ((tmthing.flags & 16777216) != 0) {
        damage = (P_Random() % 8 + 1) * tmthing.info.damage
        P_DamageMobj(thing_0, tmthing, tmthing, damage)
        tmthing.flags &= ~16777216
        let c2da_fresh7 : int = 0
        tmthing.momz = c2da_fresh7
        let c2da_fresh8 : int = c2da_fresh7
        tmthing.momy = c2da_fresh8
        tmthing.momx = c2da_fresh8
        P_SetMobjState(tmthing, unsafe(reinterpret<statenum_t>(uint(tmthing.info.spawnstate))))
        return 0u
    }
    if ((tmthing.flags & 65536) != 0) {
        if (tmthing.z > thing_0.z + thing_0.height) {
            return 1u
        }
        if (tmthing.z + tmthing.height < thing_0.z) {
            return 1u
        }
        if (tmthing.target != null && (uint(tmthing.target.type_0) == uint(thing_0.type_0) || uint(tmthing.target.type_0) == 17u && uint(thing_0.type_0) == 15u || uint(tmthing.target.type_0) == 15u && uint(thing_0.type_0) == 17u)) {
            if (thing_0 == tmthing.target) {
                return 1u
            }
            if (uint(thing_0.type_0) != 0u && 0 == 0) {
                return 0u
            }
        }
        if ((thing_0.flags & 4) == 0) {
            return (thing_0.flags & 2) == 0 ? 1u : 0u
        }
        damage = (P_Random() % 8 + 1) * tmthing.info.damage
        P_DamageMobj(thing_0, tmthing, tmthing.target, damage)
        return 0u
    }
    if ((thing_0.flags & 1) != 0) {
        solid = uint(thing_0.flags & 2)
        if ((tmflags & 2048) != 0) {
            P_TouchSpecialThing(thing_0, tmthing)
        }
        return solid == 0 ? 1u : 0u
    }
    return (thing_0.flags & 2) == 0 ? 1u : 0u
}
var tmflags : int = default<int>

var tmy : int = default<int>

var tmx : int = default<int>

[export, sideeffects]
def P_TryMove(var thing_1 : mobj_s?; var x_0 : int; var y_0 : int) : uint {
    var oldx : int
    var oldy : int
    var side : int
    var oldside : int
    var ld_1 : line_s?
    floatok = 0u
    if (P_CheckPosition(thing_1, x_0, y_0) == 0) {
        return 0u
    }
    if ((thing_1.flags & 4096) == 0) {
        if (tmceilingz - tmfloorz < thing_1.height) {
            return 0u
        }
        floatok = 1u
        if ((thing_1.flags & 32768) == 0 && tmceilingz - thing_1.z < thing_1.height) {
            return 0u
        }
        if ((thing_1.flags & 32768) == 0 && tmfloorz - thing_1.z > 24 * (1 << 16)) {
            return 0u
        }
        if ((thing_1.flags & (1024 | 16384)) == 0 && tmfloorz - tmdropoffz > 24 * (1 << 16)) {
            return 0u
        }
    }
    P_UnsetThingPosition(thing_1)
    oldx = thing_1.x
    oldy = thing_1.y
    thing_1.floorz = int(tmfloorz)  // nolint:PERF020
    thing_1.ceilingz = int(tmceilingz)  // nolint:PERF020
    thing_1.x = int(x_0)  // nolint:PERF020
    thing_1.y = int(y_0)  // nolint:PERF020
    P_SetThingPosition(thing_1)
    if ((thing_1.flags & (32768 | 4096)) == 0) {
        while (true) {
            let c2da_postinc : int = numspechit
            numspechit--
            if (c2da_postinc == 0) {
                break
            }
            ld_1 = unsafe(reinterpret<line_s?>(spechit[numspechit]))
            side = P_PointOnLineSide(thing_1.x, thing_1.y, ld_1)
            oldside = P_PointOnLineSide(oldx, oldy, ld_1)
            if (side != oldside) {
                if (ld_1.special != 0) {
                    P_CrossSpecialLine(int(unsafe(ld_1 - lines)), oldside, thing_1)
                }
            }
        }
    }
    return 1u
}
[export, sideeffects]
def P_TeleportMove(var thing_2 : mobj_s?; var x_1 : int; var y_1 : int) : uint {
    var xh_0 : int
    var yl_0 : int
    var yh_0 : int
    var bx_0 : int
    var by_0 : int
    var newsubsec_0 : subsector_s?
    tmthing = unsafe(reinterpret<mobj_s?>(thing_2))
    tmflags = int(thing_2.flags)  // nolint:PERF020
    tmx = int(x_1)  // nolint:PERF020
    tmy = int(y_1)  // nolint:PERF020
    tmbbox[0] = y_1 + tmthing.radius
    tmbbox[1] = y_1 - tmthing.radius
    tmbbox[3] = x_1 + tmthing.radius
    tmbbox[2] = x_1 - tmthing.radius
    newsubsec_0 = unsafe(reinterpret<subsector_s?>(unsafe(reinterpret<subsector_s?>(R_PointInSubsector(x_1, y_1)))))
    ceilingline = null
    tmdropoffz = int(newsubsec_0.sector.floorheight)  // nolint:PERF020
    tmfloorz = int(tmdropoffz)  // nolint:PERF020
    tmceilingz = int(newsubsec_0.sector.ceilingheight)  // nolint:PERF020
    validcount = validcount + 1
    numspechit = 0
    xh_0 = tmbbox[3] - bmaporgx + 32 * (1 << 16) >> 16 + 7
    yl_0 = tmbbox[1] - bmaporgy - 32 * (1 << 16) >> 16 + 7
    yh_0 = tmbbox[0] - bmaporgy + 32 * (1 << 16) >> 16 + 7
    bx_0 = tmbbox[2] - bmaporgx - 32 * (1 << 16) >> 16 + 7
    while (bx_0 <= xh_0) {
        by_0 = yl_0
        while (by_0 <= yh_0) {
            if (P_BlockThingsIterator(bx_0, by_0, @@PIT_StompThing) == 0) {
                return 0u
            }
            by_0++
        }
        bx_0++
    }
    P_UnsetThingPosition(thing_2)
    thing_2.floorz = int(tmfloorz)  // nolint:PERF020
    thing_2.ceilingz = int(tmceilingz)  // nolint:PERF020
    thing_2.x = int(x_1)  // nolint:PERF020
    thing_2.y = int(y_1)  // nolint:PERF020
    P_SetThingPosition(thing_2)
    return 1u
}
[export, sideeffects]
def PIT_StompThing(var thing_3 : mobj_s?) : uint {
    var blockdist_0 : int
    if ((thing_3.flags & 4) == 0) {
        return 1u
    }
    blockdist_0 = thing_3.radius + tmthing.radius
    if (c2da_std_abs(thing_3.x - tmx) >= blockdist_0 || c2da_std_abs(thing_3.y - tmy) >= blockdist_0) {
        return 1u
    }
    if (thing_3 == tmthing) {
        return 1u
    }
    if (tmthing.player == null && gamemap != 30) {
        return 0u
    }
    P_DamageMobj(thing_3, tmthing, tmthing, 10000)
    return 1u
}
[export, sideeffects]
def P_SlideMove(var mo : mobj_s?) {
    var leadx : int
    var leady : int
    var trailx : int
    var traily : int
    var newx : int
    var newy : int
    var hitcount : int
    slidemo = unsafe(reinterpret<mobj_s?>(mo))
    hitcount = 0
    label 0:
    hitcount++
    if (hitcount == 3) {
        goto label 16
    }
    if (mo.momx > 0) {
        goto label 15
    }
    leadx = mo.x - mo.radius
    trailx = mo.x + mo.radius
    label 1:
    if (mo.momy > 0) {
        goto label 14
    }
    leady = mo.y - mo.radius
    traily = mo.y + mo.radius
    label 2:
    bestslidefrac = (1 << 16) + 1
    P_PathTraverse(leadx, leady, leadx + mo.momx, leady + mo.momy, 1, @@PTR_SlideTraverse)
    P_PathTraverse(trailx, leady, trailx + mo.momx, leady + mo.momy, 1, @@PTR_SlideTraverse)
    P_PathTraverse(leadx, traily, leadx + mo.momx, traily + mo.momy, 1, @@PTR_SlideTraverse)
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
    tmxmove = FixedMul(mo.momx, bestslidefrac)
    tmymove = FixedMul(mo.momy, bestslidefrac)
    P_HitSlideLine(bestslideline)
    mo.momx = int(tmxmove)  // nolint:PERF020
    mo.momy = int(tmymove)  // nolint:PERF020
    if (P_TryMove(mo, mo.x + tmxmove, mo.y + tmymove) == 0) {
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
    newx = FixedMul(mo.momx, bestslidefrac)
    newy = FixedMul(mo.momy, bestslidefrac)
    if (P_TryMove(mo, mo.x + newx, mo.y + newy) == 0) {
        goto label 9
    }
    goto label 3
    label 9:
    label 10:
    if (P_TryMove(mo, mo.x, mo.y + mo.momy) == 0) {
        goto label 12
    }
    label 11:
    return
    label 12:
    P_TryMove(mo, mo.x + mo.momx, mo.y)
    goto label 11
    label 13:
    goto label 10
    label 14:
    leady = mo.y + mo.radius
    traily = mo.y - mo.radius
    goto label 2
    label 15:
    leadx = mo.x + mo.radius
    trailx = mo.x - mo.radius
    goto label 1
    label 16:
    goto label 10
    panic("unreachable: fell out of a translated control-flow graph")
}
var tmymove : int = default<int>

var tmxmove : int = default<int>

var bestslideline : line_s? = default<line_s?>

[export, sideeffects]
def P_HitSlideLine(var ld_2 : line_s?) {
    var side_0 : int
    var lineangle : uint
    var moveangle : uint
    var deltaangle : uint
    var movelen : int
    var newlen : int
    if (uint(ld_2.slopetype) == 0u) {
        tmymove = 0
        return
    }
    if (uint(ld_2.slopetype) == 1u) {
        tmxmove = 0
        return
    }
    side_0 = P_PointOnLineSide(slidemo.x, slidemo.y, ld_2)
    lineangle = uint(R_PointToAngle2(0, 0, ld_2.dx, ld_2.dy))
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
    newlen = FixedMul(movelen, unsafe(finecosine[int(deltaangle)]))
    tmxmove = FixedMul(newlen, unsafe(finecosine[int(lineangle)]))
    tmymove = FixedMul(newlen, finesine[int(lineangle)])
    return
}
var slidemo : mobj_s? = default<mobj_s?>

var bestslidefrac : int = default<int>

[export, sideeffects]
def PTR_SlideTraverse(var in_0 : intercept_t?) : uint {
    var li : line_s?
    if (in_0.isaline == 0) {
        goto label 9
    }
    label 0:
    li = unsafe(reinterpret<line_s?>(unsafe(unsafe(reinterpret<line_s??>(unsafe(reinterpret<uint64>(in_0))))[1])))
    if ((int(li.flags) & 4) == 0) {
        goto label 7
    }
    P_LineOpening(li)
    if (openrange < slidemo.height) {
        goto label 6
    }
    if (opentop - slidemo.z < slidemo.height) {
        goto label 5
    }
    if (openbottom - slidemo.z > 24 * (1 << 16)) {
        goto label 1
    }
    return 1u
    label 1:
    label 2:
    if (in_0.frac < bestslidefrac) {
        goto label 4
    }
    label 3:
    return 0u
    label 4:
    secondslidefrac = int(bestslidefrac)  // nolint:PERF020
    secondslideline = unsafe(reinterpret<line_s?>(bestslideline))
    bestslidefrac = int(in_0.frac)  // nolint:PERF020
    bestslideline = unsafe(reinterpret<line_s?>(li))
    goto label 3
    label 5:
    goto label 2
    label 6:
    goto label 2
    label 7:
    if (P_PointOnLineSide(slidemo.x, slidemo.y, li) != 0) {
        goto label 8
    }
    goto label 2
    label 8:
    return 1u
    label 9:
    I_Error(unsafe(addr<int8?>(c2da_str_p_map_2[0])), [])
    goto label 0
    panic("unreachable: fell out of a translated control-flow graph")
}
var secondslideline : line_s? = default<line_s?>

var secondslidefrac : int = default<int>

[export, sideeffects]
def P_UseLines(var player : player_s?) {
    var angle : int
    var x1 : int
    var y1 : int
    var x2 : int
    var y2 : int
    usething = unsafe(reinterpret<mobj_s?>(player.mo))
    angle = int(player.mo.angle >> 19u)
    x1 = player.mo.x
    y1 = player.mo.y
    x2 = x1 + (64 * (1 << 16) >> 16) * unsafe(finecosine[angle])
    y2 = y1 + (64 * (1 << 16) >> 16) * finesine[angle]
    P_PathTraverse(x1, y1, x2, y2, 1, @@PTR_UseTraverse)
    return
}
[export, sideeffects]
def PTR_UseTraverse(var in_1 : intercept_t?) : uint {
    var side_1 : int
    if (unsafe(unsafe(reinterpret<line_s??>(unsafe(reinterpret<uint64>(in_1))))[1]).special == 0) {
        P_LineOpening(unsafe(unsafe(reinterpret<line_s??>(unsafe(reinterpret<uint64>(in_1))))[1]))
        if (openrange <= 0) {
            S_StartSound(unsafe(reinterpret<uint8?>(usething)), 81)
            return 0u
        }
        return 1u
    }
    side_1 = 0
    if (P_PointOnLineSide(usething.x, usething.y, unsafe(unsafe(reinterpret<line_s??>(unsafe(reinterpret<uint64>(in_1))))[1])) == 1) {
        side_1 = 1
    }
    P_UseSpecialLine(usething, unsafe(unsafe(reinterpret<line_s??>(unsafe(reinterpret<uint64>(in_1))))[1]), side_1)
    return 0u
}
var usething : mobj_s? = default<mobj_s?>

[export, sideeffects]
def P_ChangeSector(var sector : sector_t?; var crunch : uint) : uint {
    var x_2 : int
    var y_3 : int
    nofit = 0u
    crushchange = uint(crunch)  // nolint:PERF020
    var c2da_fresh9 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(sector)) + 32ul))
    x_2 = unsafe(unsafe(reinterpret<int?>(c2da_fresh9))[2])
    while (true) {
        var c2da_fresh10 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(sector)) + 32ul))
        if (x_2 > unsafe(unsafe(reinterpret<int?>(c2da_fresh10))[3])) {
            break
        }
        var c2da_fresh11 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(sector)) + 32ul))
        y_3 = unsafe(unsafe(reinterpret<int?>(c2da_fresh11))[1])
        while (true) {
            var c2da_fresh12 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(sector)) + 32ul))
            if (y_3 > unsafe(unsafe(reinterpret<int?>(c2da_fresh12))[0])) {
                break
            }
            P_BlockThingsIterator(x_2, y_3, @@PIT_ChangeSector)
            y_3++
        }
        x_2++
    }
    return nofit
}
[export, sideeffects]
def PIT_ChangeSector(var thing_4 : mobj_s?) : uint {
    var mo_0 : mobj_s?
    if (P_ThingHeightClip(thing_4) != 0x0) {
        return 1u
    }
    if (thing_4.health <= 0) {
        P_SetMobjState(thing_4, unsafe(reinterpret<statenum_t>(895u)))
        thing_4.flags &= ~2
        thing_4.height = 0
        thing_4.radius = 0
        return 1u
    }
    if ((thing_4.flags & 131072) != 0) {
        P_RemoveMobj(thing_4)
        return 1u
    }
    if ((thing_4.flags & 4) == 0) {
        return 1u
    }
    nofit = 1u
    if (crushchange != 0x0 && (leveltime & 3) == 0) {
        P_DamageMobj(thing_4, null, null, 10)
        mo_0 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SpawnMobj(thing_4.x, thing_4.y, thing_4.z + thing_4.height / 2, unsafe(reinterpret<mobjtype_t>(38u)))))))
        mo_0.momx = P_Random() - P_Random() << 12
        mo_0.momy = P_Random() - P_Random() << 12
    }
    return 1u
}
[export, sideeffects]
def P_ThingHeightClip(var thing_5 : mobj_s?) : uint {
    var onfloor : uint = uint(thing_5.z == thing_5.floorz ? 1 : 0)
    P_CheckPosition(thing_5, thing_5.x, thing_5.y)
    thing_5.floorz = int(tmfloorz)  // nolint:PERF020
    thing_5.ceilingz = int(tmceilingz)  // nolint:PERF020
    if (onfloor != 0x0) {
        thing_5.z = int(thing_5.floorz)  // nolint:PERF020
    } elif (thing_5.z + thing_5.height > thing_5.ceilingz) {
        thing_5.z = thing_5.ceilingz - thing_5.height
    }
    if (thing_5.ceilingz - thing_5.floorz < thing_5.height) {
        return 0u
    }
    return 1u
}
var linetarget : mobj_s? = default<mobj_s?>

[export, sideeffects]
def P_AimLineAttack(var t1 : mobj_s?; var angle_0 : uint; var distance : int) : int {
    var x2_0 : int
    var y2_0 : int
    t1 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SubstNullMobj(t1)))))
    angle_0 >>= 19u
    shootthing = unsafe(reinterpret<mobj_s?>(t1))
    x2_0 = t1.x + (distance >> 16) * unsafe(finecosine[int(angle_0)])
    y2_0 = t1.y + (distance >> 16) * finesine[int(angle_0)]
    shootz = t1.z + (t1.height >> 1) + 8 * (1 << 16)
    topslope = 100 * (1 << 16) / 160
    bottomslope = -100 * (1 << 16) / 160
    attackrange = int(distance)  // nolint:PERF020
    linetarget = null
    P_PathTraverse(t1.x, t1.y, x2_0, y2_0, 1 | 2, @@PTR_AimTraverse)
    if (linetarget != null) {
        return aimslope
    }
    return 0
}
var aimslope : int = default<int>

[export, sideeffects]
def PTR_AimTraverse(var in_2 : intercept_t?) : uint {
    var li_0 : line_s?
    var th : mobj_s?
    var slope : int
    var thingtopslope : int
    var thingbottomslope : int
    var dist : int
    if (in_2.isaline != 0x0) {
        li_0 = unsafe(reinterpret<line_s?>(unsafe(unsafe(reinterpret<line_s??>(unsafe(reinterpret<uint64>(in_2))))[1])))
        if ((int(li_0.flags) & 4) == 0) {
            return 0u
        }
        P_LineOpening(li_0)
        if (openbottom >= opentop) {
            return 0u
        }
        dist = FixedMul(attackrange, in_2.frac)
        if (li_0.backsector == null || li_0.frontsector.floorheight != li_0.backsector.floorheight) {
            slope = FixedDiv(openbottom - shootz, dist)
            if (slope > bottomslope) {
                bottomslope = slope
            }
        }
        if (li_0.backsector == null || li_0.frontsector.ceilingheight != li_0.backsector.ceilingheight) {
            slope = FixedDiv(opentop - shootz, dist)
            if (slope < topslope) {
                topslope = slope
            }
        }
        if (topslope <= bottomslope) {
            return 0u
        }
        return 1u
    }
    th = unsafe(reinterpret<mobj_s?>(unsafe(unsafe(reinterpret<mobj_s??>(unsafe(reinterpret<uint64>(in_2))))[1])))
    if (th == shootthing) {
        return 1u
    }
    if ((th.flags & 4) == 0) {
        return 1u
    }
    dist = FixedMul(attackrange, in_2.frac)
    thingtopslope = FixedDiv(th.z + th.height - shootz, dist)
    if (thingtopslope < bottomslope) {
        return 1u
    }
    thingbottomslope = FixedDiv(th.z - shootz, dist)
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
    linetarget = unsafe(reinterpret<mobj_s?>(th))
    return 0u
}
var shootz : int = default<int>

var attackrange : int = default<int>

var shootthing : mobj_s? = default<mobj_s?>

[export, sideeffects]
def P_LineAttack(var t1_0 : mobj_s?; var angle_1 : uint; var distance_0 : int; var slope_0 : int; var damage_0 : int) {
    var x2_1 : int
    var y2_1 : int
    angle_1 >>= 19u
    shootthing = unsafe(reinterpret<mobj_s?>(t1_0))
    la_damage = int(damage_0)  // nolint:PERF020
    x2_1 = t1_0.x + (distance_0 >> 16) * unsafe(finecosine[int(angle_1)])
    y2_1 = t1_0.y + (distance_0 >> 16) * finesine[int(angle_1)]
    shootz = t1_0.z + (t1_0.height >> 1) + 8 * (1 << 16)
    attackrange = int(distance_0)  // nolint:PERF020
    aimslope = int(slope_0)  // nolint:PERF020
    P_PathTraverse(t1_0.x, t1_0.y, x2_1, y2_1, 1 | 2, @@PTR_ShootTraverse)
    return
}
[export, sideeffects]
def PTR_ShootTraverse(var in_3 : intercept_t?) : uint {
    var x_3 : int
    var y_4 : int
    var z : int
    var frac : int
    var li_1 : line_s?
    var th_0 : mobj_s?
    var slope_1 : int
    var dist_0 : int
    var thingtopslope_0 : int
    var thingbottomslope_0 : int
    if (in_3.isaline != 0x0) {
        goto label 8
    }
    th_0 = unsafe(reinterpret<mobj_s?>(unsafe(unsafe(reinterpret<mobj_s??>(unsafe(reinterpret<uint64>(in_3))))[1])))
    if (th_0 == shootthing) {
        goto label 7
    }
    if ((th_0.flags & 4) == 0) {
        goto label 6
    }
    dist_0 = FixedMul(attackrange, in_3.frac)
    thingtopslope_0 = FixedDiv(th_0.z + th_0.height - shootz, dist_0)
    if (thingtopslope_0 < aimslope) {
        goto label 5
    }
    thingbottomslope_0 = FixedDiv(th_0.z - shootz, dist_0)
    if (thingbottomslope_0 > aimslope) {
        goto label 4
    }
    frac = in_3.frac - FixedDiv(10 * (1 << 16), attackrange)
    x_3 = trace.x + FixedMul(trace.dx, frac)
    y_4 = trace.y + FixedMul(trace.dy, frac)
    z = shootz + FixedMul(aimslope, FixedMul(frac, attackrange))
    if ((unsafe(unsafe(reinterpret<mobj_s??>(unsafe(reinterpret<uint64>(in_3))))[1]).flags & 524288) != 0) {
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
    li_1 = unsafe(reinterpret<line_s?>(unsafe(unsafe(reinterpret<line_s??>(unsafe(reinterpret<uint64>(in_3))))[1])))
    if (li_1.special != 0) {
        goto label 26
    }
    label 9:
    if ((int(li_1.flags) & 4) == 0) {
        goto label 25
    }
    P_LineOpening(li_1)
    dist_0 = FixedMul(attackrange, in_3.frac)
    if (li_1.backsector == null) {
        goto label 22
    }
    if (li_1.frontsector.floorheight != li_1.backsector.floorheight) {
        goto label 20
    }
    label 10:
    if (li_1.frontsector.ceilingheight != li_1.backsector.ceilingheight) {
        goto label 13
    }
    label 11:
    label 12:
    return 1u
    label 13:
    slope_1 = FixedDiv(opentop - shootz, dist_0)
    if (slope_1 < aimslope) {
        goto label 14
    }
    goto label 11
    label 14:
    label 15:
    frac = in_3.frac - FixedDiv(4 * (1 << 16), attackrange)
    x_3 = trace.x + FixedMul(trace.dx, frac)
    y_4 = trace.y + FixedMul(trace.dy, frac)
    z = shootz + FixedMul(aimslope, FixedMul(frac, attackrange))
    if (int(li_1.frontsector.ceilingpic) == skyflatnum) {
        goto label 17
    }
    label 16:
    P_SpawnPuff(x_3, y_4, z)
    return 0u
    label 17:
    if (z > li_1.frontsector.ceilingheight) {
        goto label 19
    }
    if (li_1.backsector != null && int(li_1.backsector.ceilingpic) == skyflatnum) {
        goto label 18
    }
    goto label 16
    label 18:
    return 0u
    label 19:
    return 0u
    label 20:
    slope_1 = FixedDiv(openbottom - shootz, dist_0)
    if (slope_1 > aimslope) {
        goto label 21
    }
    goto label 10
    label 21:
    goto label 15
    label 22:
    slope_1 = FixedDiv(openbottom - shootz, dist_0)
    if (slope_1 > aimslope) {
        goto label 24
    }
    slope_1 = FixedDiv(opentop - shootz, dist_0)
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
def P_RadiusAttack(var spot : mobj_s?; var source : mobj_s?; var damage_1 : int) {
    var x_4 : int
    var y_5 : int
    var xl_1 : int
    var xh_1 : int
    var yl_1 : int
    var yh_1 : int
    var dist_1 : int = damage_1 + 32 * (1 << 16) << 16
    yh_1 = spot.y + dist_1 - bmaporgy >> 16 + 7
    yl_1 = spot.y - dist_1 - bmaporgy >> 16 + 7
    xh_1 = spot.x + dist_1 - bmaporgx >> 16 + 7
    xl_1 = spot.x - dist_1 - bmaporgx >> 16 + 7
    bombspot = unsafe(reinterpret<mobj_s?>(spot))
    bombsource = unsafe(reinterpret<mobj_s?>(source))
    bombdamage = int(damage_1)  // nolint:PERF020
    y_5 = yl_1
    while (y_5 <= yh_1) {
        x_4 = xl_1
        while (x_4 <= xh_1) {
            P_BlockThingsIterator(x_4, y_5, @@PIT_RadiusAttack)
            x_4++
        }
        y_5++
    }
    return
}
[export, sideeffects]
def PIT_RadiusAttack(var thing_6 : mobj_s?) : uint {
    var dx : int
    var dy : int
    var dist_2 : int
    if ((thing_6.flags & 4) == 0) {
        return 1u
    }
    if (uint(thing_6.type_0) == 21u || uint(thing_6.type_0) == 19u) {
        return 1u
    }
    dx = c2da_std_abs(thing_6.x - bombspot.x)
    dy = c2da_std_abs(thing_6.y - bombspot.y)
    dist_2 = dx > dy ? dx : dy
    dist_2 = dist_2 - thing_6.radius >> 16
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

var bombsource : mobj_s? = default<mobj_s?>

var bombspot : mobj_s? = default<mobj_s?>

[sideeffects]
def private c2da_layout_proofs_16() {
    static_assert(typeinfo sizeof(type<_IO_FILE>) == 216, "C layout of _IO_FILE: sizeof")
    static_assert(typeinfo alignof(type<_IO_FILE>) == 8, "C layout of _IO_FILE: alignof")
    static_assert(typeinfo offsetof<_flags>(type<_IO_FILE>) == 0, "C layout of _IO_FILE: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<_IO_FILE>) == 8, "C layout of _IO_FILE: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<_IO_FILE>) == 16, "C layout of _IO_FILE: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<_IO_FILE>) == 24, "C layout of _IO_FILE: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<_IO_FILE>) == 32, "C layout of _IO_FILE: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<_IO_FILE>) == 40, "C layout of _IO_FILE: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<_IO_FILE>) == 48, "C layout of _IO_FILE: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<_IO_FILE>) == 56, "C layout of _IO_FILE: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<_IO_FILE>) == 64, "C layout of _IO_FILE: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<_IO_FILE>) == 72, "C layout of _IO_FILE: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<_IO_FILE>) == 80, "C layout of _IO_FILE: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<_IO_FILE>) == 88, "C layout of _IO_FILE: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<_IO_FILE>) == 96, "C layout of _IO_FILE: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<_IO_FILE>) == 104, "C layout of _IO_FILE: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<_IO_FILE>) == 112, "C layout of _IO_FILE: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<_IO_FILE>) == 116, "C layout of _IO_FILE: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<_IO_FILE>) == 120, "C layout of _IO_FILE: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<_IO_FILE>) == 128, "C layout of _IO_FILE: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<_IO_FILE>) == 130, "C layout of _IO_FILE: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<_IO_FILE>) == 131, "C layout of _IO_FILE: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<_IO_FILE>) == 136, "C layout of _IO_FILE: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<_IO_FILE>) == 144, "C layout of _IO_FILE: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<_IO_FILE>) == 152, "C layout of _IO_FILE: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<_IO_FILE>) == 160, "C layout of _IO_FILE: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<_IO_FILE>) == 168, "C layout of _IO_FILE: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<_IO_FILE>) == 176, "C layout of _IO_FILE: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<_IO_FILE>) == 184, "C layout of _IO_FILE: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<_IO_FILE>) == 192, "C layout of _IO_FILE: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<_IO_FILE>) == 196, "C layout of _IO_FILE: offsetof _unused2")
    static_assert(typeinfo sizeof(type<FILE_0>) == 216, "C layout of FILE_0: sizeof")
    static_assert(typeinfo alignof(type<FILE_0>) == 8, "C layout of FILE_0: alignof")
    static_assert(typeinfo offsetof<_flags>(type<FILE_0>) == 0, "C layout of FILE_0: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<FILE_0>) == 8, "C layout of FILE_0: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<FILE_0>) == 16, "C layout of FILE_0: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<FILE_0>) == 24, "C layout of FILE_0: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<FILE_0>) == 32, "C layout of FILE_0: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<FILE_0>) == 40, "C layout of FILE_0: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<FILE_0>) == 48, "C layout of FILE_0: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<FILE_0>) == 56, "C layout of FILE_0: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<FILE_0>) == 64, "C layout of FILE_0: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<FILE_0>) == 72, "C layout of FILE_0: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<FILE_0>) == 80, "C layout of FILE_0: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<FILE_0>) == 88, "C layout of FILE_0: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<FILE_0>) == 96, "C layout of FILE_0: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<FILE_0>) == 104, "C layout of FILE_0: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<FILE_0>) == 112, "C layout of FILE_0: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<FILE_0>) == 116, "C layout of FILE_0: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<FILE_0>) == 120, "C layout of FILE_0: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<FILE_0>) == 128, "C layout of FILE_0: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<FILE_0>) == 130, "C layout of FILE_0: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<FILE_0>) == 131, "C layout of FILE_0: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<FILE_0>) == 136, "C layout of FILE_0: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<FILE_0>) == 144, "C layout of FILE_0: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<FILE_0>) == 152, "C layout of FILE_0: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<FILE_0>) == 160, "C layout of FILE_0: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<FILE_0>) == 168, "C layout of FILE_0: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<FILE_0>) == 176, "C layout of FILE_0: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<FILE_0>) == 184, "C layout of FILE_0: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<FILE_0>) == 192, "C layout of FILE_0: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<FILE_0>) == 196, "C layout of FILE_0: offsetof _unused2")
    static_assert(typeinfo sizeof(type<ticcmd_t>) == 16, "C layout of ticcmd_t: sizeof")
    static_assert(typeinfo alignof(type<ticcmd_t>) == 4, "C layout of ticcmd_t: alignof")
    static_assert(typeinfo offsetof<forwardmove>(type<ticcmd_t>) == 0, "C layout of ticcmd_t: offsetof forwardmove")
    static_assert(typeinfo offsetof<sidemove>(type<ticcmd_t>) == 1, "C layout of ticcmd_t: offsetof sidemove")
    static_assert(typeinfo offsetof<angleturn>(type<ticcmd_t>) == 2, "C layout of ticcmd_t: offsetof angleturn")
    static_assert(typeinfo offsetof<chatchar>(type<ticcmd_t>) == 4, "C layout of ticcmd_t: offsetof chatchar")
    static_assert(typeinfo offsetof<buttons>(type<ticcmd_t>) == 5, "C layout of ticcmd_t: offsetof buttons")
    static_assert(typeinfo offsetof<consistancy>(type<ticcmd_t>) == 6, "C layout of ticcmd_t: offsetof consistancy")
    static_assert(typeinfo offsetof<buttons2>(type<ticcmd_t>) == 7, "C layout of ticcmd_t: offsetof buttons2")
    static_assert(typeinfo offsetof<inventory>(type<ticcmd_t>) == 8, "C layout of ticcmd_t: offsetof inventory")
    static_assert(typeinfo offsetof<lookfly>(type<ticcmd_t>) == 12, "C layout of ticcmd_t: offsetof lookfly")
    static_assert(typeinfo offsetof<arti>(type<ticcmd_t>) == 13, "C layout of ticcmd_t: offsetof arti")
    static_assert(typeinfo sizeof(type<thinker_s>) == 24, "C layout of thinker_s: sizeof")
    static_assert(typeinfo alignof(type<thinker_s>) == 8, "C layout of thinker_s: alignof")
    static_assert(typeinfo offsetof<prev>(type<thinker_s>) == 0, "C layout of thinker_s: offsetof prev")
    static_assert(typeinfo offsetof<next>(type<thinker_s>) == 8, "C layout of thinker_s: offsetof next")
    static_assert(typeinfo offsetof<function_0>(type<thinker_s>) == 16, "C layout of thinker_s: offsetof function_0")
    static_assert(typeinfo sizeof(type<thinker_t>) == 24, "C layout of thinker_t: sizeof")
    static_assert(typeinfo alignof(type<thinker_t>) == 8, "C layout of thinker_t: alignof")
    static_assert(typeinfo offsetof<prev>(type<thinker_t>) == 0, "C layout of thinker_t: offsetof prev")
    static_assert(typeinfo offsetof<next>(type<thinker_t>) == 8, "C layout of thinker_t: offsetof next")
    static_assert(typeinfo offsetof<function_0>(type<thinker_t>) == 16, "C layout of thinker_t: offsetof function_0")
    static_assert(typeinfo sizeof(type<state_t>) == 40, "C layout of state_t: sizeof")
    static_assert(typeinfo alignof(type<state_t>) == 8, "C layout of state_t: alignof")
    static_assert(typeinfo offsetof<sprite>(type<state_t>) == 0, "C layout of state_t: offsetof sprite")
    static_assert(typeinfo offsetof<frame>(type<state_t>) == 4, "C layout of state_t: offsetof frame")
    static_assert(typeinfo offsetof<tics>(type<state_t>) == 8, "C layout of state_t: offsetof tics")
    static_assert(typeinfo offsetof<action>(type<state_t>) == 16, "C layout of state_t: offsetof action")
    static_assert(typeinfo offsetof<nextstate>(type<state_t>) == 24, "C layout of state_t: offsetof nextstate")
    static_assert(typeinfo offsetof<misc1>(type<state_t>) == 28, "C layout of state_t: offsetof misc1")
    static_assert(typeinfo offsetof<misc2>(type<state_t>) == 32, "C layout of state_t: offsetof misc2")
    static_assert(typeinfo sizeof(type<mobjinfo_t>) == 92, "C layout of mobjinfo_t: sizeof")
    static_assert(typeinfo alignof(type<mobjinfo_t>) == 4, "C layout of mobjinfo_t: alignof")
    static_assert(typeinfo offsetof<doomednum>(type<mobjinfo_t>) == 0, "C layout of mobjinfo_t: offsetof doomednum")
    static_assert(typeinfo offsetof<spawnstate>(type<mobjinfo_t>) == 4, "C layout of mobjinfo_t: offsetof spawnstate")
    static_assert(typeinfo offsetof<spawnhealth>(type<mobjinfo_t>) == 8, "C layout of mobjinfo_t: offsetof spawnhealth")
    static_assert(typeinfo offsetof<seestate>(type<mobjinfo_t>) == 12, "C layout of mobjinfo_t: offsetof seestate")
    static_assert(typeinfo offsetof<seesound>(type<mobjinfo_t>) == 16, "C layout of mobjinfo_t: offsetof seesound")
    static_assert(typeinfo offsetof<reactiontime>(type<mobjinfo_t>) == 20, "C layout of mobjinfo_t: offsetof reactiontime")
    static_assert(typeinfo offsetof<attacksound>(type<mobjinfo_t>) == 24, "C layout of mobjinfo_t: offsetof attacksound")
    static_assert(typeinfo offsetof<painstate>(type<mobjinfo_t>) == 28, "C layout of mobjinfo_t: offsetof painstate")
    static_assert(typeinfo offsetof<painchance>(type<mobjinfo_t>) == 32, "C layout of mobjinfo_t: offsetof painchance")
    static_assert(typeinfo offsetof<painsound>(type<mobjinfo_t>) == 36, "C layout of mobjinfo_t: offsetof painsound")
    static_assert(typeinfo offsetof<meleestate>(type<mobjinfo_t>) == 40, "C layout of mobjinfo_t: offsetof meleestate")
    static_assert(typeinfo offsetof<missilestate>(type<mobjinfo_t>) == 44, "C layout of mobjinfo_t: offsetof missilestate")
    static_assert(typeinfo offsetof<deathstate>(type<mobjinfo_t>) == 48, "C layout of mobjinfo_t: offsetof deathstate")
    static_assert(typeinfo offsetof<xdeathstate>(type<mobjinfo_t>) == 52, "C layout of mobjinfo_t: offsetof xdeathstate")
    static_assert(typeinfo offsetof<deathsound>(type<mobjinfo_t>) == 56, "C layout of mobjinfo_t: offsetof deathsound")
    static_assert(typeinfo offsetof<speed>(type<mobjinfo_t>) == 60, "C layout of mobjinfo_t: offsetof speed")
    static_assert(typeinfo offsetof<radius>(type<mobjinfo_t>) == 64, "C layout of mobjinfo_t: offsetof radius")
    static_assert(typeinfo offsetof<height>(type<mobjinfo_t>) == 68, "C layout of mobjinfo_t: offsetof height")
    static_assert(typeinfo offsetof<mass>(type<mobjinfo_t>) == 72, "C layout of mobjinfo_t: offsetof mass")
    static_assert(typeinfo offsetof<damage>(type<mobjinfo_t>) == 76, "C layout of mobjinfo_t: offsetof damage")
    static_assert(typeinfo offsetof<activesound>(type<mobjinfo_t>) == 80, "C layout of mobjinfo_t: offsetof activesound")
    static_assert(typeinfo offsetof<flags>(type<mobjinfo_t>) == 84, "C layout of mobjinfo_t: offsetof flags")
    static_assert(typeinfo offsetof<raisestate>(type<mobjinfo_t>) == 88, "C layout of mobjinfo_t: offsetof raisestate")
    static_assert(typeinfo sizeof(type<mobj_s>) == 224, "C layout of mobj_s: sizeof")
    static_assert(typeinfo alignof(type<mobj_s>) == 8, "C layout of mobj_s: alignof")
    static_assert(typeinfo offsetof<thinker>(type<mobj_s>) == 0, "C layout of mobj_s: offsetof thinker")
    static_assert(typeinfo offsetof<x>(type<mobj_s>) == 24, "C layout of mobj_s: offsetof x")
    static_assert(typeinfo offsetof<y>(type<mobj_s>) == 28, "C layout of mobj_s: offsetof y")
    static_assert(typeinfo offsetof<z>(type<mobj_s>) == 32, "C layout of mobj_s: offsetof z")
    static_assert(typeinfo offsetof<snext>(type<mobj_s>) == 40, "C layout of mobj_s: offsetof snext")
    static_assert(typeinfo offsetof<sprev>(type<mobj_s>) == 48, "C layout of mobj_s: offsetof sprev")
    static_assert(typeinfo offsetof<angle>(type<mobj_s>) == 56, "C layout of mobj_s: offsetof angle")
    static_assert(typeinfo offsetof<sprite>(type<mobj_s>) == 60, "C layout of mobj_s: offsetof sprite")
    static_assert(typeinfo offsetof<frame>(type<mobj_s>) == 64, "C layout of mobj_s: offsetof frame")
    static_assert(typeinfo offsetof<bnext>(type<mobj_s>) == 72, "C layout of mobj_s: offsetof bnext")
    static_assert(typeinfo offsetof<bprev>(type<mobj_s>) == 80, "C layout of mobj_s: offsetof bprev")
    static_assert(typeinfo offsetof<subsector>(type<mobj_s>) == 88, "C layout of mobj_s: offsetof subsector")
    static_assert(typeinfo offsetof<floorz>(type<mobj_s>) == 96, "C layout of mobj_s: offsetof floorz")
    static_assert(typeinfo offsetof<ceilingz>(type<mobj_s>) == 100, "C layout of mobj_s: offsetof ceilingz")
    static_assert(typeinfo offsetof<radius>(type<mobj_s>) == 104, "C layout of mobj_s: offsetof radius")
    static_assert(typeinfo offsetof<height>(type<mobj_s>) == 108, "C layout of mobj_s: offsetof height")
    static_assert(typeinfo offsetof<momx>(type<mobj_s>) == 112, "C layout of mobj_s: offsetof momx")
    static_assert(typeinfo offsetof<momy>(type<mobj_s>) == 116, "C layout of mobj_s: offsetof momy")
    static_assert(typeinfo offsetof<momz>(type<mobj_s>) == 120, "C layout of mobj_s: offsetof momz")
    static_assert(typeinfo offsetof<validcount>(type<mobj_s>) == 124, "C layout of mobj_s: offsetof validcount")
    static_assert(typeinfo offsetof<type_0>(type<mobj_s>) == 128, "C layout of mobj_s: offsetof type_0")
    static_assert(typeinfo offsetof<info>(type<mobj_s>) == 136, "C layout of mobj_s: offsetof info")
    static_assert(typeinfo offsetof<tics>(type<mobj_s>) == 144, "C layout of mobj_s: offsetof tics")
    static_assert(typeinfo offsetof<state>(type<mobj_s>) == 152, "C layout of mobj_s: offsetof state")
    static_assert(typeinfo offsetof<flags>(type<mobj_s>) == 160, "C layout of mobj_s: offsetof flags")
    static_assert(typeinfo offsetof<health>(type<mobj_s>) == 164, "C layout of mobj_s: offsetof health")
    static_assert(typeinfo offsetof<movedir>(type<mobj_s>) == 168, "C layout of mobj_s: offsetof movedir")
    static_assert(typeinfo offsetof<movecount>(type<mobj_s>) == 172, "C layout of mobj_s: offsetof movecount")
    static_assert(typeinfo offsetof<target>(type<mobj_s>) == 176, "C layout of mobj_s: offsetof target")
    static_assert(typeinfo offsetof<reactiontime>(type<mobj_s>) == 184, "C layout of mobj_s: offsetof reactiontime")
    static_assert(typeinfo offsetof<threshold>(type<mobj_s>) == 188, "C layout of mobj_s: offsetof threshold")
    static_assert(typeinfo offsetof<player>(type<mobj_s>) == 192, "C layout of mobj_s: offsetof player")
    static_assert(typeinfo offsetof<lastlook>(type<mobj_s>) == 200, "C layout of mobj_s: offsetof lastlook")
    static_assert(typeinfo offsetof<spawnpoint>(type<mobj_s>) == 204, "C layout of mobj_s: offsetof spawnpoint")
    static_assert(typeinfo offsetof<tracer>(type<mobj_s>) == 216, "C layout of mobj_s: offsetof tracer")
    static_assert(typeinfo sizeof(type<player_s>) == 328, "C layout of player_s: sizeof")
    static_assert(typeinfo alignof(type<player_s>) == 8, "C layout of player_s: alignof")
    static_assert(typeinfo offsetof<mo>(type<player_s>) == 0, "C layout of player_s: offsetof mo")
    static_assert(typeinfo offsetof<playerstate>(type<player_s>) == 8, "C layout of player_s: offsetof playerstate")
    static_assert(typeinfo offsetof<cmd>(type<player_s>) == 12, "C layout of player_s: offsetof cmd")
    static_assert(typeinfo offsetof<viewz>(type<player_s>) == 28, "C layout of player_s: offsetof viewz")
    static_assert(typeinfo offsetof<viewheight>(type<player_s>) == 32, "C layout of player_s: offsetof viewheight")
    static_assert(typeinfo offsetof<deltaviewheight>(type<player_s>) == 36, "C layout of player_s: offsetof deltaviewheight")
    static_assert(typeinfo offsetof<bob>(type<player_s>) == 40, "C layout of player_s: offsetof bob")
    static_assert(typeinfo offsetof<health>(type<player_s>) == 44, "C layout of player_s: offsetof health")
    static_assert(typeinfo offsetof<armorpoints>(type<player_s>) == 48, "C layout of player_s: offsetof armorpoints")
    static_assert(typeinfo offsetof<armortype>(type<player_s>) == 52, "C layout of player_s: offsetof armortype")
    static_assert(typeinfo offsetof<powers>(type<player_s>) == 56, "C layout of player_s: offsetof powers")
    static_assert(typeinfo offsetof<cards>(type<player_s>) == 80, "C layout of player_s: offsetof cards")
    static_assert(typeinfo offsetof<backpack>(type<player_s>) == 104, "C layout of player_s: offsetof backpack")
    static_assert(typeinfo offsetof<frags>(type<player_s>) == 108, "C layout of player_s: offsetof frags")
    static_assert(typeinfo offsetof<readyweapon>(type<player_s>) == 124, "C layout of player_s: offsetof readyweapon")
    static_assert(typeinfo offsetof<pendingweapon>(type<player_s>) == 128, "C layout of player_s: offsetof pendingweapon")
    static_assert(typeinfo offsetof<weaponowned>(type<player_s>) == 132, "C layout of player_s: offsetof weaponowned")
    static_assert(typeinfo offsetof<ammo>(type<player_s>) == 168, "C layout of player_s: offsetof ammo")
    static_assert(typeinfo offsetof<maxammo>(type<player_s>) == 184, "C layout of player_s: offsetof maxammo")
    static_assert(typeinfo offsetof<attackdown>(type<player_s>) == 200, "C layout of player_s: offsetof attackdown")
    static_assert(typeinfo offsetof<usedown>(type<player_s>) == 204, "C layout of player_s: offsetof usedown")
    static_assert(typeinfo offsetof<cheats>(type<player_s>) == 208, "C layout of player_s: offsetof cheats")
    static_assert(typeinfo offsetof<refire>(type<player_s>) == 212, "C layout of player_s: offsetof refire")
    static_assert(typeinfo offsetof<killcount>(type<player_s>) == 216, "C layout of player_s: offsetof killcount")
    static_assert(typeinfo offsetof<itemcount>(type<player_s>) == 220, "C layout of player_s: offsetof itemcount")
    static_assert(typeinfo offsetof<secretcount>(type<player_s>) == 224, "C layout of player_s: offsetof secretcount")
    static_assert(typeinfo offsetof<message>(type<player_s>) == 232, "C layout of player_s: offsetof message")
    static_assert(typeinfo offsetof<damagecount>(type<player_s>) == 240, "C layout of player_s: offsetof damagecount")
    static_assert(typeinfo offsetof<bonuscount>(type<player_s>) == 244, "C layout of player_s: offsetof bonuscount")
    static_assert(typeinfo offsetof<attacker>(type<player_s>) == 248, "C layout of player_s: offsetof attacker")
    static_assert(typeinfo offsetof<extralight>(type<player_s>) == 256, "C layout of player_s: offsetof extralight")
    static_assert(typeinfo offsetof<fixedcolormap>(type<player_s>) == 260, "C layout of player_s: offsetof fixedcolormap")
    static_assert(typeinfo offsetof<colormap>(type<player_s>) == 264, "C layout of player_s: offsetof colormap")
    static_assert(typeinfo offsetof<psprites>(type<player_s>) == 272, "C layout of player_s: offsetof psprites")
    static_assert(typeinfo offsetof<didsecret>(type<player_s>) == 320, "C layout of player_s: offsetof didsecret")
    static_assert(typeinfo sizeof(type<pspdef_t>) == 24, "C layout of pspdef_t: sizeof")
    static_assert(typeinfo alignof(type<pspdef_t>) == 8, "C layout of pspdef_t: alignof")
    static_assert(typeinfo offsetof<state>(type<pspdef_t>) == 0, "C layout of pspdef_t: offsetof state")
    static_assert(typeinfo offsetof<tics>(type<pspdef_t>) == 8, "C layout of pspdef_t: offsetof tics")
    static_assert(typeinfo offsetof<sx>(type<pspdef_t>) == 12, "C layout of pspdef_t: offsetof sx")
    static_assert(typeinfo offsetof<sy>(type<pspdef_t>) == 16, "C layout of pspdef_t: offsetof sy")
    static_assert(typeinfo sizeof(type<mobj_t>) == 224, "C layout of mobj_t: sizeof")
    static_assert(typeinfo alignof(type<mobj_t>) == 8, "C layout of mobj_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<mobj_t>) == 0, "C layout of mobj_t: offsetof thinker")
    static_assert(typeinfo offsetof<x>(type<mobj_t>) == 24, "C layout of mobj_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<mobj_t>) == 28, "C layout of mobj_t: offsetof y")
    static_assert(typeinfo offsetof<z>(type<mobj_t>) == 32, "C layout of mobj_t: offsetof z")
    static_assert(typeinfo offsetof<snext>(type<mobj_t>) == 40, "C layout of mobj_t: offsetof snext")
    static_assert(typeinfo offsetof<sprev>(type<mobj_t>) == 48, "C layout of mobj_t: offsetof sprev")
    static_assert(typeinfo offsetof<angle>(type<mobj_t>) == 56, "C layout of mobj_t: offsetof angle")
    static_assert(typeinfo offsetof<sprite>(type<mobj_t>) == 60, "C layout of mobj_t: offsetof sprite")
    static_assert(typeinfo offsetof<frame>(type<mobj_t>) == 64, "C layout of mobj_t: offsetof frame")
    static_assert(typeinfo offsetof<bnext>(type<mobj_t>) == 72, "C layout of mobj_t: offsetof bnext")
    static_assert(typeinfo offsetof<bprev>(type<mobj_t>) == 80, "C layout of mobj_t: offsetof bprev")
    static_assert(typeinfo offsetof<subsector>(type<mobj_t>) == 88, "C layout of mobj_t: offsetof subsector")
    static_assert(typeinfo offsetof<floorz>(type<mobj_t>) == 96, "C layout of mobj_t: offsetof floorz")
    static_assert(typeinfo offsetof<ceilingz>(type<mobj_t>) == 100, "C layout of mobj_t: offsetof ceilingz")
    static_assert(typeinfo offsetof<radius>(type<mobj_t>) == 104, "C layout of mobj_t: offsetof radius")
    static_assert(typeinfo offsetof<height>(type<mobj_t>) == 108, "C layout of mobj_t: offsetof height")
    static_assert(typeinfo offsetof<momx>(type<mobj_t>) == 112, "C layout of mobj_t: offsetof momx")
    static_assert(typeinfo offsetof<momy>(type<mobj_t>) == 116, "C layout of mobj_t: offsetof momy")
    static_assert(typeinfo offsetof<momz>(type<mobj_t>) == 120, "C layout of mobj_t: offsetof momz")
    static_assert(typeinfo offsetof<validcount>(type<mobj_t>) == 124, "C layout of mobj_t: offsetof validcount")
    static_assert(typeinfo offsetof<type_0>(type<mobj_t>) == 128, "C layout of mobj_t: offsetof type_0")
    static_assert(typeinfo offsetof<info>(type<mobj_t>) == 136, "C layout of mobj_t: offsetof info")
    static_assert(typeinfo offsetof<tics>(type<mobj_t>) == 144, "C layout of mobj_t: offsetof tics")
    static_assert(typeinfo offsetof<state>(type<mobj_t>) == 152, "C layout of mobj_t: offsetof state")
    static_assert(typeinfo offsetof<flags>(type<mobj_t>) == 160, "C layout of mobj_t: offsetof flags")
    static_assert(typeinfo offsetof<health>(type<mobj_t>) == 164, "C layout of mobj_t: offsetof health")
    static_assert(typeinfo offsetof<movedir>(type<mobj_t>) == 168, "C layout of mobj_t: offsetof movedir")
    static_assert(typeinfo offsetof<movecount>(type<mobj_t>) == 172, "C layout of mobj_t: offsetof movecount")
    static_assert(typeinfo offsetof<target>(type<mobj_t>) == 176, "C layout of mobj_t: offsetof target")
    static_assert(typeinfo offsetof<reactiontime>(type<mobj_t>) == 184, "C layout of mobj_t: offsetof reactiontime")
    static_assert(typeinfo offsetof<threshold>(type<mobj_t>) == 188, "C layout of mobj_t: offsetof threshold")
    static_assert(typeinfo offsetof<player>(type<mobj_t>) == 192, "C layout of mobj_t: offsetof player")
    static_assert(typeinfo offsetof<lastlook>(type<mobj_t>) == 200, "C layout of mobj_t: offsetof lastlook")
    static_assert(typeinfo offsetof<spawnpoint>(type<mobj_t>) == 204, "C layout of mobj_t: offsetof spawnpoint")
    static_assert(typeinfo offsetof<tracer>(type<mobj_t>) == 216, "C layout of mobj_t: offsetof tracer")
    static_assert(typeinfo sizeof(type<subsector_s>) == 16, "C layout of subsector_s: sizeof")
    static_assert(typeinfo alignof(type<subsector_s>) == 8, "C layout of subsector_s: alignof")
    static_assert(typeinfo offsetof<sector>(type<subsector_s>) == 0, "C layout of subsector_s: offsetof sector")
    static_assert(typeinfo offsetof<numlines>(type<subsector_s>) == 8, "C layout of subsector_s: offsetof numlines")
    static_assert(typeinfo offsetof<firstline>(type<subsector_s>) == 10, "C layout of subsector_s: offsetof firstline")
    static_assert(typeinfo sizeof(type<sector_t>) == 128, "C layout of sector_t: sizeof")
    static_assert(typeinfo alignof(type<sector_t>) == 8, "C layout of sector_t: alignof")
    static_assert(typeinfo offsetof<floorheight>(type<sector_t>) == 0, "C layout of sector_t: offsetof floorheight")
    static_assert(typeinfo offsetof<ceilingheight>(type<sector_t>) == 4, "C layout of sector_t: offsetof ceilingheight")
    static_assert(typeinfo offsetof<floorpic>(type<sector_t>) == 8, "C layout of sector_t: offsetof floorpic")
    static_assert(typeinfo offsetof<ceilingpic>(type<sector_t>) == 10, "C layout of sector_t: offsetof ceilingpic")
    static_assert(typeinfo offsetof<lightlevel>(type<sector_t>) == 12, "C layout of sector_t: offsetof lightlevel")
    static_assert(typeinfo offsetof<special>(type<sector_t>) == 14, "C layout of sector_t: offsetof special")
    static_assert(typeinfo offsetof<tag>(type<sector_t>) == 16, "C layout of sector_t: offsetof tag")
    static_assert(typeinfo offsetof<soundtraversed>(type<sector_t>) == 20, "C layout of sector_t: offsetof soundtraversed")
    static_assert(typeinfo offsetof<soundtarget>(type<sector_t>) == 24, "C layout of sector_t: offsetof soundtarget")
    static_assert(typeinfo offsetof<blockbox>(type<sector_t>) == 32, "C layout of sector_t: offsetof blockbox")
    static_assert(typeinfo offsetof<soundorg>(type<sector_t>) == 48, "C layout of sector_t: offsetof soundorg")
    static_assert(typeinfo offsetof<validcount>(type<sector_t>) == 88, "C layout of sector_t: offsetof validcount")
    static_assert(typeinfo offsetof<thinglist>(type<sector_t>) == 96, "C layout of sector_t: offsetof thinglist")
    static_assert(typeinfo offsetof<specialdata>(type<sector_t>) == 104, "C layout of sector_t: offsetof specialdata")
    static_assert(typeinfo offsetof<linecount>(type<sector_t>) == 112, "C layout of sector_t: offsetof linecount")
    static_assert(typeinfo offsetof<lines>(type<sector_t>) == 120, "C layout of sector_t: offsetof lines")
    static_assert(typeinfo sizeof(type<line_s>) == 88, "C layout of line_s: sizeof")
    static_assert(typeinfo alignof(type<line_s>) == 8, "C layout of line_s: alignof")
    static_assert(typeinfo offsetof<v1>(type<line_s>) == 0, "C layout of line_s: offsetof v1")
    static_assert(typeinfo offsetof<v2>(type<line_s>) == 8, "C layout of line_s: offsetof v2")
    static_assert(typeinfo offsetof<dx>(type<line_s>) == 16, "C layout of line_s: offsetof dx")
    static_assert(typeinfo offsetof<dy>(type<line_s>) == 20, "C layout of line_s: offsetof dy")
    static_assert(typeinfo offsetof<flags>(type<line_s>) == 24, "C layout of line_s: offsetof flags")
    static_assert(typeinfo offsetof<special>(type<line_s>) == 26, "C layout of line_s: offsetof special")
    static_assert(typeinfo offsetof<tag>(type<line_s>) == 28, "C layout of line_s: offsetof tag")
    static_assert(typeinfo offsetof<sidenum>(type<line_s>) == 30, "C layout of line_s: offsetof sidenum")
    static_assert(typeinfo offsetof<bbox>(type<line_s>) == 36, "C layout of line_s: offsetof bbox")
    static_assert(typeinfo offsetof<slopetype>(type<line_s>) == 52, "C layout of line_s: offsetof slopetype")
    static_assert(typeinfo offsetof<frontsector>(type<line_s>) == 56, "C layout of line_s: offsetof frontsector")
    static_assert(typeinfo offsetof<backsector>(type<line_s>) == 64, "C layout of line_s: offsetof backsector")
    static_assert(typeinfo offsetof<validcount>(type<line_s>) == 72, "C layout of line_s: offsetof validcount")
    static_assert(typeinfo offsetof<specialdata>(type<line_s>) == 80, "C layout of line_s: offsetof specialdata")
    static_assert(typeinfo sizeof(type<vertex_t>) == 8, "C layout of vertex_t: sizeof")
    static_assert(typeinfo alignof(type<vertex_t>) == 4, "C layout of vertex_t: alignof")
    static_assert(typeinfo offsetof<x>(type<vertex_t>) == 0, "C layout of vertex_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<vertex_t>) == 4, "C layout of vertex_t: offsetof y")
    static_assert(typeinfo sizeof(type<degenmobj_t>) == 40, "C layout of degenmobj_t: sizeof")
    static_assert(typeinfo alignof(type<degenmobj_t>) == 8, "C layout of degenmobj_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<degenmobj_t>) == 0, "C layout of degenmobj_t: offsetof thinker")
    static_assert(typeinfo offsetof<x>(type<degenmobj_t>) == 24, "C layout of degenmobj_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<degenmobj_t>) == 28, "C layout of degenmobj_t: offsetof y")
    static_assert(typeinfo offsetof<z>(type<degenmobj_t>) == 32, "C layout of degenmobj_t: offsetof z")
    static_assert(typeinfo sizeof(type<line_t>) == 88, "C layout of line_t: sizeof")
    static_assert(typeinfo alignof(type<line_t>) == 8, "C layout of line_t: alignof")
    static_assert(typeinfo offsetof<v1>(type<line_t>) == 0, "C layout of line_t: offsetof v1")
    static_assert(typeinfo offsetof<v2>(type<line_t>) == 8, "C layout of line_t: offsetof v2")
    static_assert(typeinfo offsetof<dx>(type<line_t>) == 16, "C layout of line_t: offsetof dx")
    static_assert(typeinfo offsetof<dy>(type<line_t>) == 20, "C layout of line_t: offsetof dy")
    static_assert(typeinfo offsetof<flags>(type<line_t>) == 24, "C layout of line_t: offsetof flags")
    static_assert(typeinfo offsetof<special>(type<line_t>) == 26, "C layout of line_t: offsetof special")
    static_assert(typeinfo offsetof<tag>(type<line_t>) == 28, "C layout of line_t: offsetof tag")
    static_assert(typeinfo offsetof<sidenum>(type<line_t>) == 30, "C layout of line_t: offsetof sidenum")
    static_assert(typeinfo offsetof<bbox>(type<line_t>) == 36, "C layout of line_t: offsetof bbox")
    static_assert(typeinfo offsetof<slopetype>(type<line_t>) == 52, "C layout of line_t: offsetof slopetype")
    static_assert(typeinfo offsetof<frontsector>(type<line_t>) == 56, "C layout of line_t: offsetof frontsector")
    static_assert(typeinfo offsetof<backsector>(type<line_t>) == 64, "C layout of line_t: offsetof backsector")
    static_assert(typeinfo offsetof<validcount>(type<line_t>) == 72, "C layout of line_t: offsetof validcount")
    static_assert(typeinfo offsetof<specialdata>(type<line_t>) == 80, "C layout of line_t: offsetof specialdata")
    static_assert(typeinfo sizeof(type<subsector_t>) == 16, "C layout of subsector_t: sizeof")
    static_assert(typeinfo alignof(type<subsector_t>) == 8, "C layout of subsector_t: alignof")
    static_assert(typeinfo offsetof<sector>(type<subsector_t>) == 0, "C layout of subsector_t: offsetof sector")
    static_assert(typeinfo offsetof<numlines>(type<subsector_t>) == 8, "C layout of subsector_t: offsetof numlines")
    static_assert(typeinfo offsetof<firstline>(type<subsector_t>) == 10, "C layout of subsector_t: offsetof firstline")
    static_assert(typeinfo sizeof(type<player_t>) == 328, "C layout of player_t: sizeof")
    static_assert(typeinfo alignof(type<player_t>) == 8, "C layout of player_t: alignof")
    static_assert(typeinfo offsetof<mo>(type<player_t>) == 0, "C layout of player_t: offsetof mo")
    static_assert(typeinfo offsetof<playerstate>(type<player_t>) == 8, "C layout of player_t: offsetof playerstate")
    static_assert(typeinfo offsetof<cmd>(type<player_t>) == 12, "C layout of player_t: offsetof cmd")
    static_assert(typeinfo offsetof<viewz>(type<player_t>) == 28, "C layout of player_t: offsetof viewz")
    static_assert(typeinfo offsetof<viewheight>(type<player_t>) == 32, "C layout of player_t: offsetof viewheight")
    static_assert(typeinfo offsetof<deltaviewheight>(type<player_t>) == 36, "C layout of player_t: offsetof deltaviewheight")
    static_assert(typeinfo offsetof<bob>(type<player_t>) == 40, "C layout of player_t: offsetof bob")
    static_assert(typeinfo offsetof<health>(type<player_t>) == 44, "C layout of player_t: offsetof health")
    static_assert(typeinfo offsetof<armorpoints>(type<player_t>) == 48, "C layout of player_t: offsetof armorpoints")
    static_assert(typeinfo offsetof<armortype>(type<player_t>) == 52, "C layout of player_t: offsetof armortype")
    static_assert(typeinfo offsetof<powers>(type<player_t>) == 56, "C layout of player_t: offsetof powers")
    static_assert(typeinfo offsetof<cards>(type<player_t>) == 80, "C layout of player_t: offsetof cards")
    static_assert(typeinfo offsetof<backpack>(type<player_t>) == 104, "C layout of player_t: offsetof backpack")
    static_assert(typeinfo offsetof<frags>(type<player_t>) == 108, "C layout of player_t: offsetof frags")
    static_assert(typeinfo offsetof<readyweapon>(type<player_t>) == 124, "C layout of player_t: offsetof readyweapon")
    static_assert(typeinfo offsetof<pendingweapon>(type<player_t>) == 128, "C layout of player_t: offsetof pendingweapon")
    static_assert(typeinfo offsetof<weaponowned>(type<player_t>) == 132, "C layout of player_t: offsetof weaponowned")
    static_assert(typeinfo offsetof<ammo>(type<player_t>) == 168, "C layout of player_t: offsetof ammo")
    static_assert(typeinfo offsetof<maxammo>(type<player_t>) == 184, "C layout of player_t: offsetof maxammo")
    static_assert(typeinfo offsetof<attackdown>(type<player_t>) == 200, "C layout of player_t: offsetof attackdown")
    static_assert(typeinfo offsetof<usedown>(type<player_t>) == 204, "C layout of player_t: offsetof usedown")
    static_assert(typeinfo offsetof<cheats>(type<player_t>) == 208, "C layout of player_t: offsetof cheats")
    static_assert(typeinfo offsetof<refire>(type<player_t>) == 212, "C layout of player_t: offsetof refire")
    static_assert(typeinfo offsetof<killcount>(type<player_t>) == 216, "C layout of player_t: offsetof killcount")
    static_assert(typeinfo offsetof<itemcount>(type<player_t>) == 220, "C layout of player_t: offsetof itemcount")
    static_assert(typeinfo offsetof<secretcount>(type<player_t>) == 224, "C layout of player_t: offsetof secretcount")
    static_assert(typeinfo offsetof<message>(type<player_t>) == 232, "C layout of player_t: offsetof message")
    static_assert(typeinfo offsetof<damagecount>(type<player_t>) == 240, "C layout of player_t: offsetof damagecount")
    static_assert(typeinfo offsetof<bonuscount>(type<player_t>) == 244, "C layout of player_t: offsetof bonuscount")
    static_assert(typeinfo offsetof<attacker>(type<player_t>) == 248, "C layout of player_t: offsetof attacker")
    static_assert(typeinfo offsetof<extralight>(type<player_t>) == 256, "C layout of player_t: offsetof extralight")
    static_assert(typeinfo offsetof<fixedcolormap>(type<player_t>) == 260, "C layout of player_t: offsetof fixedcolormap")
    static_assert(typeinfo offsetof<colormap>(type<player_t>) == 264, "C layout of player_t: offsetof colormap")
    static_assert(typeinfo offsetof<psprites>(type<player_t>) == 272, "C layout of player_t: offsetof psprites")
    static_assert(typeinfo offsetof<didsecret>(type<player_t>) == 320, "C layout of player_t: offsetof didsecret")
    static_assert(typeinfo sizeof(type<divline_t>) == 16, "C layout of divline_t: sizeof")
    static_assert(typeinfo alignof(type<divline_t>) == 4, "C layout of divline_t: alignof")
    static_assert(typeinfo offsetof<x>(type<divline_t>) == 0, "C layout of divline_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<divline_t>) == 4, "C layout of divline_t: offsetof y")
    static_assert(typeinfo offsetof<dx>(type<divline_t>) == 8, "C layout of divline_t: offsetof dx")
    static_assert(typeinfo offsetof<dy>(type<divline_t>) == 12, "C layout of divline_t: offsetof dy")
    static_assert(typeinfo sizeof(type<intercept_t>) == 16, "C layout of intercept_t: sizeof")
    static_assert(typeinfo alignof(type<intercept_t>) == 8, "C layout of intercept_t: alignof")
    static_assert(typeinfo offsetof<frac>(type<intercept_t>) == 0, "C layout of intercept_t: offsetof frac")
    static_assert(typeinfo offsetof<isaline>(type<intercept_t>) == 4, "C layout of intercept_t: offsetof isaline")
    static_assert(typeinfo offsetof<d>(type<intercept_t>) == 8, "C layout of intercept_t: offsetof d")
}
