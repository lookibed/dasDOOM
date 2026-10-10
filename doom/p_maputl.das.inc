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
var intercepts : intercept_t[189]

var intercept_p : intercept_t? = default<intercept_t?>

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
def P_PointOnLineSide(var x : int; var y : int; var line : line_s?) : int {
    var dx_0 : int
    var dy_0 : int
    var left : int
    var right : int
    if (line.dx == 0) {
        if (x <= line.v1.x) {
            return line.dy > 0 ? 1 : 0
        }
        return line.dy < 0 ? 1 : 0
    }
    if (line.dy == 0) {
        if (y <= line.v1.y) {
            return line.dx < 0 ? 1 : 0
        }
        return line.dx > 0 ? 1 : 0
    }
    dx_0 = x - line.v1.x
    dy_0 = y - line.v1.y
    left = FixedMul(line.dy >> 16, dx_0)
    right = FixedMul(dy_0, line.dx >> 16)
    if (right < left) {
        return 0
    }
    return 1
}
[export, sideeffects]
def P_PointOnDivlineSide(var x_0 : int; var y_0 : int; var line_0 : divline_t?) : int {
    var dx_1 : int
    var dy_1 : int
    var left_0 : int
    var right_0 : int
    if (line_0.dx == 0) {
        if (x_0 <= line_0.x) {
            return line_0.dy > 0 ? 1 : 0
        }
        return line_0.dy < 0 ? 1 : 0
    }
    if (line_0.dy == 0) {
        if (y_0 <= line_0.y) {
            return line_0.dx < 0 ? 1 : 0
        }
        return line_0.dx > 0 ? 1 : 0
    }
    dx_1 = x_0 - line_0.x
    dy_1 = y_0 - line_0.y
    if ((uint(line_0.dy ^ line_0.dx ^ dx_1 ^ dy_1) & 0x80000000u) != 0x0) {
        if ((uint(line_0.dy ^ dx_1) & 0x80000000u) != 0x0) {
            return 1
        }
        return 0
    }
    left_0 = FixedMul(line_0.dy >> 8, dx_1 >> 8)
    right_0 = FixedMul(dy_1 >> 8, line_0.dx >> 8)
    if (right_0 < left_0) {
        return 0
    }
    return 1
}
[export, sideeffects]
def P_MakeDivline(var li : line_s?; var dl : divline_t?) {
    dl.x = int(li.v1.x)  // nolint:PERF020
    dl.y = int(li.v1.y)  // nolint:PERF020
    dl.dx = int(li.dx)  // nolint:PERF020
    dl.dy = int(li.dy)  // nolint:PERF020
    return
}
[export, sideeffects]
def P_InterceptVector(var v2 : divline_t?; var v1 : divline_t?) : int {
    var frac : int
    var num : int
    var den : int = FixedMul(v1.dy >> 8, v2.dx) - FixedMul(v1.dx >> 8, v2.dy)
    if (den == 0) {
        return 0
    }
    num = FixedMul(v1.x - v2.x >> 8, v1.dy) + FixedMul(v2.y - v1.y >> 8, v1.dx)
    frac = FixedDiv(num, den)
    return frac
}
[export, sideeffects]
def P_BoxOnLineSide(var tmbox : int?; var ld : line_s?) : int {
    var c2da_fresh0 : uint
    var p1 : int
    var p2 : int
    p1 = 0
    p2 = 0
    c2da_fresh0 = uint(ld.slopetype)
    if (c2da_fresh0 == 0x0u) {
        p1 = unsafe(tmbox[0]) > ld.v1.y ? 1 : 0
        p2 = unsafe(tmbox[1]) > ld.v1.y ? 1 : 0
        if (ld.dx < 0) {
            p1 ^= 1
            p2 ^= 1
        }
    } elif (c2da_fresh0 == 0x1u) {
        p1 = unsafe(tmbox[3]) < ld.v1.x ? 1 : 0
        p2 = unsafe(tmbox[2]) < ld.v1.x ? 1 : 0
        if (ld.dy < 0) {
            p1 ^= 1
            p2 ^= 1
        }
    } elif (c2da_fresh0 == 0x2u) {
        p1 = P_PointOnLineSide(unsafe(tmbox[2]), unsafe(tmbox[0]), ld)
        p2 = P_PointOnLineSide(unsafe(tmbox[3]), unsafe(tmbox[1]), ld)
    } elif (c2da_fresh0 == 0x3u) {
        p1 = P_PointOnLineSide(unsafe(tmbox[3]), unsafe(tmbox[0]), ld)
        p2 = P_PointOnLineSide(unsafe(tmbox[2]), unsafe(tmbox[1]), ld)
    }
    if (p1 == p2) {
        return p1
    }
    return -1
}
var opentop : int = default<int>

var openbottom : int = default<int>

var openrange : int = default<int>

var lowfloor : int = default<int>

[export, sideeffects]
def P_LineOpening(var linedef_0 : line_s?) {
    var front : sector_t?
    var back : sector_t?
    var c2da_fresh1 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(linedef_0)) + 30ul))
    if (int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh1))[1])) == -1) {
        openrange = 0
        return
    }
    front = unsafe(reinterpret<sector_t?>(linedef_0.frontsector))
    back = unsafe(reinterpret<sector_t?>(linedef_0.backsector))
    if (front.ceilingheight < back.ceilingheight) {
        opentop = int(front.ceilingheight)  // nolint:PERF020
    } else {
        opentop = int(back.ceilingheight)  // nolint:PERF020
    }
    if (front.floorheight > back.floorheight) {
        openbottom = int(front.floorheight)  // nolint:PERF020
        lowfloor = int(back.floorheight)  // nolint:PERF020
    } else {
        openbottom = int(back.floorheight)  // nolint:PERF020
        lowfloor = int(front.floorheight)  // nolint:PERF020
    }
    openrange = opentop - openbottom
    return
}
[export, sideeffects]
def P_BlockLinesIterator(var x_1 : int; var y_1 : int; var func : function<(var _arg0:line_s?):uint>) : uint {
    var offset : int
    var list : int16?
    var ld_0 : line_s?
    if (x_1 < 0 || y_1 < 0 || x_1 >= bmapwidth || y_1 >= bmapheight) {
        return 1u
    }
    offset = y_1 * bmapwidth + x_1
    list = unsafe(reinterpret<int16?>(unsafe(blockmaplump + int(*unsafe(blockmap + offset)))))
    while (int(*list) != -1) {
        ld_0 = unsafe(addr<line_s?>(unsafe(lines[int(*list)])))
        if (ld_0.validcount == validcount) {
            unsafe {  // nolint:STYLE025
                list += 1
            }
            continue
        }
        ld_0.validcount = validcount
        if (invoke(func, ld_0) == 0) {
            return 0u
        }
        unsafe {  // nolint:STYLE025
            list += 1
        }
    }
    return 1u
}
[export, sideeffects]
def P_BlockThingsIterator(var x_2 : int; var y_3 : int; var func_0 : function<(var _arg0:mobj_s?):uint>) : uint {
    var mobj : mobj_s?
    if (x_2 < 0 || y_3 < 0 || x_2 >= bmapwidth || y_3 >= bmapheight) {
        return 1u
    }
    mobj = unsafe(reinterpret<mobj_s?>(unsafe(blocklinks[int(y_3 * bmapwidth + x_2)])))
    while (mobj != null) {
        if (invoke(func_0, mobj) == 0) {
            return 0u
        }
        mobj = unsafe(reinterpret<mobj_s?>(mobj.bnext))
    }
    return 1u
}
var trace : divline_t = default<divline_t>

[export, sideeffects]
def P_PathTraverse(var x1 : int; var y1 : int; var x2 : int; var y2 : int; var flags : int; var trav : function<(var _arg0:intercept_t?):uint>) : uint {
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
    intercept_p = unsafe(addr<intercept_t?>(intercepts[0]))
    if ((x1 - bmaporgx & 128 * (1 << 16) - 1) == 0) {
        x1 += 1 << 16
    }
    if ((y1 - bmaporgy & 128 * (1 << 16) - 1) == 0) {
        y1 += 1 << 16
    }
    trace.x = int(x1)  // nolint:PERF020
    trace.y = int(y1)  // nolint:PERF020
    trace.dx = x2 - x1
    trace.dy = y2 - y1
    x1 = x1 - bmaporgx
    y1 = y1 - bmaporgy
    xt1 = x1 >> 16 + 7
    yt1 = y1 >> 16 + 7
    x2 = x2 - bmaporgx
    y2 = y2 - bmaporgy
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
            if (P_BlockLinesIterator(mapx, mapy, @@PIT_AddLineIntercepts) == 0) {
                return 0u
            }
        }
        if ((flags & 2) != 0) {
            if (P_BlockThingsIterator(mapx, mapy, @@PIT_AddThingIntercepts) == 0) {
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
    var scan : intercept_t?
    var in_0 : intercept_t?
    count_0 = int(unsafe(intercept_p - unsafe(addr(intercepts[0]))))
    in_0 = null
    while (true) {
        let c2da_postinc : int = count_0
        count_0--
        if (c2da_postinc == 0) {
            break
        }
        dist = 2147483647
        scan = unsafe(addr<intercept_t?>(intercepts[0]))
        while (unsafe(reinterpret<uint64>(scan)) < unsafe(reinterpret<uint64>(intercept_p))) {
            if (scan.frac < dist) {
                dist = scan.frac
                in_0 = unsafe(reinterpret<intercept_t?>(scan))
            }
            unsafe {  // nolint:STYLE025
                scan += 1
            }
        }
        if (dist > maxfrac) {
            return 1u
        }
        if (invoke(func_1, in_0) == 0) {
            return 0u
        }
        in_0.frac = 2147483647
    }
    return 1u
}
[export, sideeffects]
def PIT_AddThingIntercepts(var thing : mobj_s?) : uint {
    var x1_0 : int
    var y1_0 : int
    var x2_0 : int
    var y2_0 : int
    var s1 : int
    var s2 : int
    var dl_0 : divline_t
    var frac_0 : int
    if (uint((trace.dx ^ trace.dy) > 0 ? 1 : 0) != 0x0) {
        x1_0 = thing.x - thing.radius
        y1_0 = thing.y + thing.radius
        x2_0 = thing.x + thing.radius
        y2_0 = thing.y - thing.radius
    } else {
        x1_0 = thing.x - thing.radius
        y1_0 = thing.y - thing.radius
        x2_0 = thing.x + thing.radius
        y2_0 = thing.y + thing.radius
    }
    s1 = P_PointOnDivlineSide(x1_0, y1_0, unsafe(addr<divline_t?>(trace)))
    s2 = P_PointOnDivlineSide(x2_0, y2_0, unsafe(addr<divline_t?>(trace)))
    if (s1 == s2) {
        return 1u
    }
    dl_0.x = x1_0
    dl_0.y = y1_0
    dl_0.dx = x2_0 - x1_0
    dl_0.dy = y2_0 - y1_0
    frac_0 = P_InterceptVector(unsafe(addr<divline_t?>(trace)), unsafe(addr<divline_t?>(dl_0)))
    if (frac_0 < 0) {
        return 1u
    }
    intercept_p.frac = frac_0
    intercept_p.isaline = 0u
    unsafe(unsafe(reinterpret<mobj_s??>(unsafe(reinterpret<uint64>(intercept_p))))[1]) = thing
    InterceptsOverrun(int(unsafe(intercept_p - unsafe(addr(intercepts[0])))), intercept_p)
    unsafe {  // nolint:STYLE025
        intercept_p += 1
    }
    return 1u
}
[sideeffects]
def private InterceptsOverrun(var num_intercepts : int; var intercept : intercept_t?) {
    var location : int
    if (num_intercepts <= 128) {
        return
    }
    location = (num_intercepts - 128 - 1) * 12
    InterceptsMemoryOverrun(location, intercept.frac)
    InterceptsMemoryOverrun(location + 4, int(intercept.isaline))
    InterceptsMemoryOverrun(location + 8, int(unsafe(reinterpret<uint64>(unsafe(unsafe(reinterpret<mobj_s??>(unsafe(reinterpret<uint64>(intercept))))[1])))))
    return
}
[sideeffects]
def private InterceptsMemoryOverrun(var location_0 : int; var value : int) {
    var i : int
    var offset_0 : int
    var index : int
    var addr_0 : uint8?
    i = 0
    offset_0 = 0
    while (intercepts_overrun[i].len != 0) {
        if (offset_0 + intercepts_overrun[i].len > location_0) {
            addr_0 = unsafe(reinterpret<uint8?>(intercepts_overrun[i].addr_0))
            if (addr_0 != null) {
                if (intercepts_overrun[i].int16_array != 0x0) {
                    index = (location_0 - offset_0) / 2
                    unsafe(unsafe(reinterpret<int16?>(addr_0))[index]) = int16(value & 65535)
                    unsafe(unsafe(reinterpret<int16?>(addr_0))[index + 1]) = int16(value >> 16 & 65535)
                } else {
                    index = (location_0 - offset_0) / 4
                    unsafe(unsafe(reinterpret<int?>(addr_0))[index]) = int(value)  // nolint:PERF020
                }
            }
            break
        }
        offset_0 += intercepts_overrun[i].len
        i++
    }
    return
}
var private intercepts_overrun : intercepts_overrun_t[23] = fixed_array<intercepts_overrun_t>(intercepts_overrun_t(len = 4, addr_0 = null, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = null, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = null, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = unsafe(addr<uint8?>(lowfloor)), int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = unsafe(addr<uint8?>(openbottom)), int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = unsafe(addr<uint8?>(opentop)), int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = unsafe(addr<uint8?>(openrange)), int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = null, int16_array = 0u), intercepts_overrun_t(len = 120, addr_0 = null, int16_array = 0u), intercepts_overrun_t(len = 8, addr_0 = null, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = unsafe(addr<uint8?>(bulletslope)), int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = null, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = null, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = null, int16_array = 0u), intercepts_overrun_t(len = 40, addr_0 = unsafe(addr<uint8?>(playerstarts)), int16_array = 1u), intercepts_overrun_t(len = 4, addr_0 = null, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = unsafe(addr<uint8?>(bmapwidth)), int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = null, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = unsafe(addr<uint8?>(bmaporgx)), int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = unsafe(addr<uint8?>(bmaporgy)), int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = null, int16_array = 0u), intercepts_overrun_t(len = 4, addr_0 = unsafe(addr<uint8?>(bmapheight)), int16_array = 0u), intercepts_overrun_t(len = 0, addr_0 = null, int16_array = 0u))

[export, sideeffects]
def PIT_AddLineIntercepts(var ld_1 : line_s?) : uint {
    var s1_0 : int
    var s2_0 : int
    var frac_1 : int
    var dl_1 : divline_t
    if (trace.dx > (1 << 16) * 16 || trace.dy > (1 << 16) * 16 || trace.dx < -(1 << 16) * 16 || trace.dy < -(1 << 16) * 16) {
        s1_0 = P_PointOnDivlineSide(ld_1.v1.x, ld_1.v1.y, unsafe(addr<divline_t?>(trace)))
        s2_0 = P_PointOnDivlineSide(ld_1.v2.x, ld_1.v2.y, unsafe(addr<divline_t?>(trace)))
    } else {
        s1_0 = P_PointOnLineSide(trace.x, trace.y, ld_1)
        s2_0 = P_PointOnLineSide(trace.x + trace.dx, trace.y + trace.dy, ld_1)
    }
    if (s1_0 == s2_0) {
        return 1u
    }
    P_MakeDivline(ld_1, unsafe(addr<divline_t?>(dl_1)))
    frac_1 = P_InterceptVector(unsafe(addr<divline_t?>(trace)), unsafe(addr<divline_t?>(dl_1)))
    if (frac_1 < 0) {
        return 1u
    }
    if (earlyout != 0x0 && frac_1 < 1 << 16 && ld_1.backsector == null) {
        return 0u
    }
    intercept_p.frac = frac_1
    intercept_p.isaline = 1u
    unsafe(unsafe(reinterpret<line_s??>(unsafe(reinterpret<uint64>(intercept_p))))[1]) = ld_1
    InterceptsOverrun(int(unsafe(intercept_p - unsafe(addr(intercepts[0])))), intercept_p)
    unsafe {  // nolint:STYLE025
        intercept_p += 1
    }
    return 1u
}
var earlyout : uint = default<uint>

[export, sideeffects]
def P_UnsetThingPosition(var thing_0 : mobj_s?) {
    var blockx : int
    var blocky : int
    if ((thing_0.flags & 8) == 0) {
        if (thing_0.snext != null) {
            thing_0.snext.sprev = thing_0.sprev
        }
        if (thing_0.sprev != null) {
            thing_0.sprev.snext = thing_0.snext
        } else {
            thing_0.subsector.sector.thinglist = thing_0.snext
        }
    }
    if ((thing_0.flags & 16) == 0) {
        if (thing_0.bnext != null) {
            thing_0.bnext.bprev = thing_0.bprev
        }
        if (thing_0.bprev != null) {
            thing_0.bprev.bnext = thing_0.bnext
        } else {
            blockx = thing_0.x - bmaporgx >> 16 + 7
            blocky = thing_0.y - bmaporgy >> 16 + 7
            if (blockx >= 0 && blockx < bmapwidth && blocky >= 0 && blocky < bmapheight) {
                unsafe(blocklinks[int(blocky * bmapwidth + blockx)]) = unsafe(reinterpret<mobj_s?>(thing_0.bnext))
            }
        }
    }
    return
}
[export, sideeffects]
def P_SetThingPosition(var thing_1 : mobj_s?) {
    var ss : subsector_s?
    var sec : sector_t?
    var blockx_0 : int
    var blocky_0 : int
    var link : mobj_s??
    ss = unsafe(reinterpret<subsector_s?>(unsafe(reinterpret<subsector_s?>(R_PointInSubsector(thing_1.x, thing_1.y)))))
    thing_1.subsector = ss
    if ((thing_1.flags & 8) == 0) {
        sec = unsafe(reinterpret<sector_t?>(ss.sector))
        thing_1.sprev = null
        thing_1.snext = sec.thinglist
        if (sec.thinglist != null) {
            sec.thinglist.sprev = thing_1
        }
        sec.thinglist = thing_1
    }
    if ((thing_1.flags & 16) == 0) {
        blockx_0 = thing_1.x - bmaporgx >> 16 + 7
        blocky_0 = thing_1.y - bmaporgy >> 16 + 7
        if (blockx_0 >= 0 && blockx_0 < bmapwidth && blocky_0 >= 0 && blocky_0 < bmapheight) {
            link = unsafe(addr<mobj_s??>(unsafe(blocklinks[int(blocky_0 * bmapwidth + blockx_0)])))
            thing_1.bprev = null
            thing_1.bnext = *link
            if (*link != null) {
                (*link).bprev = thing_1
            }
            *link = unsafe(reinterpret<mobj_s?>(thing_1))
        } else {
            var c2da_fresh2 : mobj_s? = null
            thing_1.bprev = c2da_fresh2
            thing_1.bnext = c2da_fresh2
        }
    }
    return
}
var ptflags : int = default<int>

[sideeffects]
def private c2da_layout_proofs_17() {
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
    static_assert(typeinfo sizeof(type<pspdef_t>) == 24, "C layout of pspdef_t: sizeof")
    static_assert(typeinfo alignof(type<pspdef_t>) == 8, "C layout of pspdef_t: alignof")
    static_assert(typeinfo offsetof<state>(type<pspdef_t>) == 0, "C layout of pspdef_t: offsetof state")
    static_assert(typeinfo offsetof<tics>(type<pspdef_t>) == 8, "C layout of pspdef_t: offsetof tics")
    static_assert(typeinfo offsetof<sx>(type<pspdef_t>) == 12, "C layout of pspdef_t: offsetof sx")
    static_assert(typeinfo offsetof<sy>(type<pspdef_t>) == 16, "C layout of pspdef_t: offsetof sy")
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
    static_assert(typeinfo sizeof(type<intercepts_overrun_t>) == 24, "C layout of intercepts_overrun_t: sizeof")
    static_assert(typeinfo alignof(type<intercepts_overrun_t>) == 8, "C layout of intercepts_overrun_t: alignof")
    static_assert(typeinfo offsetof<len>(type<intercepts_overrun_t>) == 0, "C layout of intercepts_overrun_t: offsetof len")
    static_assert(typeinfo offsetof<addr_0>(type<intercepts_overrun_t>) == 8, "C layout of intercepts_overrun_t: offsetof addr_0")
    static_assert(typeinfo offsetof<int16_array>(type<intercepts_overrun_t>) == 16, "C layout of intercepts_overrun_t: offsetof int16_array")
}
