var private c2da_str_r_bsp_0 : array<int8> = [int8(82), int8(95), int8(83), int8(117), int8(98), int8(115), int8(101), int8(99), int8(116), int8(111), int8(114), int8(58), int8(32), int8(115), int8(115), int8(32), int8(37), int8(105), int8(32), int8(119), int8(105), int8(116), int8(104), int8(32), int8(110), int8(117), int8(109), int8(115), int8(115), int8(32), int8(61), int8(32), int8(37), int8(105), int8(0)]

var curline : seg_t? = default<seg_t?>

var sidedef : side_t? = default<side_t?>

var linedef : line_s? = default<line_s?>

var frontsector : sector_t? = default<sector_t?>

var backsector : sector_t? = default<sector_t?>

var drawsegs : drawseg_s[256]

var ds_p : drawseg_s? = default<drawseg_s?>

[export, sideeffects]
def R_ClearDrawSegs() {
    ds_p = unsafe(addr<drawseg_s?>(drawsegs[0]))
    return
}
var newend : cliprange_t? = default<cliprange_t?>

var solidsegs : cliprange_t[32]

[export, sideeffects]
def R_ClipSolidWallSegment(var first : int; var last : int) {
    var next : cliprange_t?
    var start : cliprange_t?
    var c2da_postinc : cliprange_t?
    start = unsafe(addr<cliprange_t?>(solidsegs[0]))
    label 0:
    if (start.last < first - 1) {
        goto label 14
    }
    if (first < start.first) {
        goto label 10
    }
    label 1:
    if (last <= start.last) {
        goto label 9
    }
    next = unsafe(reinterpret<cliprange_t?>(start))
    label 2:
    if (last >= unsafe(next + 1).first - 1) {
        goto label 7
    }
    R_StoreWallRange(next.last + 1, last)
    start.last = int(last)  // nolint:PERF020
    label 3:
    if (next == start) {
        goto label 6
    }
    label 4:
    c2da_postinc = next
    unsafe {  // nolint:STYLE025
        next += 1
    }
    if (c2da_postinc != newend) {
        goto label 5
    }
    newend = unsafe(reinterpret<cliprange_t?>(unsafe(start + 1)))
    return
    label 5:
    unsafe {  // nolint:STYLE025
        start += 1
    }
    *start = *next
    goto label 4
    label 6:
    return
    label 7:
    R_StoreWallRange(next.last + 1, unsafe(next + 1).first - 1)
    unsafe {  // nolint:STYLE025
        next += 1
    }
    if (last <= next.last) {
        goto label 8
    }
    goto label 2
    label 8:
    start.last = int(next.last)  // nolint:PERF020
    goto label 3
    label 9:
    return
    label 10:
    if (last < start.first - 1) {
        goto label 11
    }
    R_StoreWallRange(first, start.first - 1)
    start.first = int(first)  // nolint:PERF020
    goto label 1
    label 11:
    R_StoreWallRange(first, last)
    next = unsafe(reinterpret<cliprange_t?>(newend))
    unsafe {  // nolint:STYLE025
        newend += 1
    }
    label 12:
    if (next != start) {
        goto label 13
    }
    next.first = int(first)  // nolint:PERF020
    next.last = int(last)  // nolint:PERF020
    return
    label 13:
    *next = *unsafe(next + -1)
    unsafe {  // nolint:STYLE025
        next -= 1
    }
    goto label 12
    label 14:
    unsafe {  // nolint:STYLE025
        start += 1
    }
    goto label 0
    panic("unreachable: fell out of a translated control-flow graph")
}
[export, sideeffects]
def R_ClipPassWallSegment(var first_0 : int; var last_0 : int) {
    var start_0 : cliprange_t? = unsafe(addr<cliprange_t?>(solidsegs[0]))
    var c2da_start_0_addr : uint64 = unsafe(reinterpret<uint64>(start_0))
    while (unsafe(reinterpret<cliprange_t?>(c2da_start_0_addr)).last < first_0 - 1) {
        c2da_start_0_addr += 8ul
    }
    start_0 = unsafe(reinterpret<cliprange_t?>(c2da_start_0_addr))
    if (first_0 < start_0.first) {
        if (last_0 < start_0.first - 1) {
            R_StoreWallRange(first_0, last_0)
            return
        }
        R_StoreWallRange(first_0, start_0.first - 1)
    }
    if (last_0 <= start_0.last) {
        return
    }
    while (last_0 >= unsafe(start_0 + 1).first - 1) {
        R_StoreWallRange(start_0.last + 1, unsafe(start_0 + 1).first - 1)
        unsafe {  // nolint:STYLE025
            start_0 += 1
        }
        if (last_0 <= start_0.last) {
            return
        }
    }
    R_StoreWallRange(start_0.last + 1, last_0)
    return
}
[export, sideeffects]
def R_ClearClipSegs() {
    solidsegs[0].first = -2147483647
    solidsegs[0].last = -1
    solidsegs[1].first = viewwidth
    solidsegs[1].last = 2147483647
    newend = unsafe(reinterpret<cliprange_t?>(unsafe(unsafe(addr(solidsegs[0])) + 2)))
    return
}
[export, sideeffects]
def R_AddLine(var line : seg_t?) {
    var x1 : int
    var x2 : int
    var angle1 : uint
    var angle2 : uint
    var span : uint
    var tspan : uint
    curline = unsafe(reinterpret<seg_t?>(line))
    angle1 = uint(R_PointToAngle(line.v1.x, line.v1.y))
    angle2 = uint(R_PointToAngle(line.v2.x, line.v2.y))
    span = angle1 - angle2
    if (span >= 0x80000000u) {
        return
    }
    rw_angle1 = int(angle1)
    angle1 = angle1 - viewangle
    angle2 = angle2 - viewangle
    tspan = uint(angle1 + clipangle)
    if (tspan > 2u * clipangle) {
        goto label 11
    }
    label 0:
    tspan = uint(clipangle - angle2)
    if (tspan > 2u * clipangle) {
        goto label 9
    }
    label 1:
    angle1 = angle1 + 0x40000000u >> 19u
    angle2 = angle2 + 0x40000000u >> 19u
    x1 = viewangletox[int(angle1)]
    x2 = viewangletox[int(angle2)]
    if (x1 == x2) {
        goto label 8
    }
    backsector = unsafe(reinterpret<sector_t?>(line.backsector))
    if (backsector == null) {
        goto label 7
    }
    if (backsector.ceilingheight <= frontsector.floorheight || backsector.floorheight >= frontsector.ceilingheight) {
        goto label 5
    }
    if (backsector.ceilingheight != frontsector.ceilingheight || backsector.floorheight != frontsector.floorheight) {
        goto label 4
    }
    if (int(backsector.ceilingpic) == int(frontsector.ceilingpic) && int(backsector.floorpic) == int(frontsector.floorpic) && int(backsector.lightlevel) == int(frontsector.lightlevel) && int(curline.sidedef.midtexture) == 0) {
        goto label 3
    }
    label 2:
    R_ClipPassWallSegment(x1, x2 - 1)
    return
    label 3:
    return
    label 4:
    goto label 2
    label 5:
    label 6:
    R_ClipSolidWallSegment(x1, x2 - 1)
    return
    label 7:
    goto label 6
    label 8:
    return
    label 9:
    tspan = tspan - 2u * clipangle
    if (tspan >= span) {
        goto label 10
    }
    angle2 = uint(-clipangle)
    goto label 1
    label 10:
    return
    label 11:
    tspan = tspan - 2u * clipangle
    if (tspan >= span) {
        return
    }
    angle1 = uint(clipangle)
    goto label 0
    return
}
var checkcoord : int[12][4] = fixed_array<int[4]>(fixed_array<int>(3, 0, 2, 1), fixed_array<int>(3, 0, 2, 0), fixed_array<int>(3, 1, 2, 0), fixed_array<int>(0, 0, 0, 0), fixed_array<int>(2, 0, 2, 1), fixed_array<int>(0, 0, 0, 0), fixed_array<int>(3, 1, 3, 0), fixed_array<int>(0, 0, 0, 0), fixed_array<int>(2, 0, 3, 1), fixed_array<int>(2, 1, 3, 1), fixed_array<int>(2, 1, 3, 0), fixed_array<int>(0, 0, 0, 0))

[export, sideeffects]
def R_CheckBBox(var bspcoord : int?) : uint {
    var boxx : int
    var boxy : int
    var boxpos : int
    var x1_0 : int
    var y1 : int
    var x2_0 : int
    var y2 : int
    var angle1_0 : uint
    var angle2_0 : uint
    var span_0 : uint
    var tspan_0 : uint
    var start_1 : cliprange_t?
    var sx1 : int
    var sx2 : int
    if (viewx <= unsafe(bspcoord[2])) {
        boxx = 0
    } elif (viewx < unsafe(bspcoord[3])) {
        boxx = 1
    } else {
        boxx = 2
    }
    if (viewy >= unsafe(bspcoord[0])) {
        boxy = 0
    } elif (viewy > unsafe(bspcoord[1])) {
        boxy = 1
    } else {
        boxy = 2
    }
    boxpos = (boxy << 2) + boxx
    if (boxpos == 5) {
        return 1u
    }
    x1_0 = unsafe(bspcoord[checkcoord[boxpos][0]])
    y1 = unsafe(bspcoord[checkcoord[boxpos][1]])
    x2_0 = unsafe(bspcoord[checkcoord[boxpos][2]])
    y2 = unsafe(bspcoord[checkcoord[boxpos][3]])
    angle1_0 = uint(R_PointToAngle(x1_0, y1) - viewangle)
    angle2_0 = uint(R_PointToAngle(x2_0, y2) - viewangle)
    span_0 = angle1_0 - angle2_0
    if (span_0 >= 0x80000000u) {
        return 1u
    }
    tspan_0 = uint(angle1_0 + clipangle)
    if (tspan_0 > 2u * clipangle) {
        tspan_0 = tspan_0 - 2u * clipangle
        if (tspan_0 >= span_0) {
            return 0u
        }
        angle1_0 = uint(clipangle)
    }
    tspan_0 = uint(clipangle - angle2_0)
    if (tspan_0 > 2u * clipangle) {
        tspan_0 = tspan_0 - 2u * clipangle
        if (tspan_0 >= span_0) {
            return 0u
        }
        angle2_0 = uint(-clipangle)
    }
    sx1 = viewangletox[int(angle1_0 + 0x40000000u >> 19u)]
    sx2 = viewangletox[int(angle2_0 + 0x40000000u >> 19u)]
    if (sx1 == sx2) {
        return 0u
    }
    sx2--
    start_1 = unsafe(addr<cliprange_t?>(solidsegs[0]))
    var c2da_start_1_addr : uint64 = unsafe(reinterpret<uint64>(start_1))
    while (unsafe(reinterpret<cliprange_t?>(c2da_start_1_addr)).last < sx2) {
        c2da_start_1_addr += 8ul
    }
    start_1 = unsafe(reinterpret<cliprange_t?>(c2da_start_1_addr))
    if (sx1 >= start_1.first && sx2 <= start_1.last) {
        return 0u
    }
    return 1u
}
[export, sideeffects]
def R_Subsector(var num : int) {
    var count : int
    var line_0 : seg_t?
    var sub : subsector_s?
    if (num >= numsubsectors) {
        I_Error(unsafe(addr<int8?>(c2da_str_r_bsp_0[0])), [C2daVaArg(tag = 1, i64 = int64(num), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(numsubsectors), f64 = 0.0lf, raw = 0x0)])
    }
    sscount = sscount + 1
    sub = unsafe(addr<subsector_s?>(unsafe(subsectors[num])))
    frontsector = unsafe(reinterpret<sector_t?>(sub.sector))
    count = int(sub.numlines)
    line_0 = unsafe(addr<seg_t?>(unsafe(segs[int(sub.firstline)])))
    if (frontsector.floorheight < viewz) {
        floorplane = unsafe(reinterpret<visplane_t?>(unsafe(reinterpret<visplane_t?>(R_FindPlane(frontsector.floorheight, int(frontsector.floorpic), int(frontsector.lightlevel))))))
    } else {
        floorplane = null
    }
    if (frontsector.ceilingheight > viewz || int(frontsector.ceilingpic) == skyflatnum) {
        ceilingplane = unsafe(reinterpret<visplane_t?>(unsafe(reinterpret<visplane_t?>(R_FindPlane(frontsector.ceilingheight, int(frontsector.ceilingpic), int(frontsector.lightlevel))))))
    } else {
        ceilingplane = null
    }
    R_AddSprites(frontsector)
    while (true) {
        let c2da_postinc_0 : int = count
        count--
        if (c2da_postinc_0 == 0) {
            break
        }
        R_AddLine(line_0)
        unsafe {  // nolint:STYLE025
            line_0 += 1
        }
    }
    return
}
[export, sideeffects]
def R_RenderBSPNode(var bspnum : int) {
    var bsp : node_t?
    var side : int
    if ((bspnum & 32768) != 0) {
        if (bspnum == -1) {
            R_Subsector(0)
        } else {
            R_Subsector(bspnum & ~32768)
        }
        return
    }
    bsp = unsafe(addr<node_t?>(unsafe(nodes[bspnum])))
    side = R_PointOnSide(viewx, viewy, bsp)
    var c2da_fresh0 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(bsp)) + 48ul))
    R_RenderBSPNode(int(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh0))[side])))
    var c2da_fresh1 : int[4]? = unsafe(reinterpret<int[4]?>(unsafe(reinterpret<uint64>(bsp)) + 16ul))
    if (R_CheckBBox(unsafe(addr<int?>(unsafe(unsafe(reinterpret<int[4]?>(c2da_fresh1))[side ^ 1])[0]))) != 0x0) {
        var c2da_fresh2 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(bsp)) + 48ul))
        R_RenderBSPNode(int(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh2))[side ^ 1])))
    }
    return
}
[sideeffects]
def private c2da_layout_proofs_29() {
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
    static_assert(typeinfo sizeof(type<side_t>) == 24, "C layout of side_t: sizeof")
    static_assert(typeinfo alignof(type<side_t>) == 8, "C layout of side_t: alignof")
    static_assert(typeinfo offsetof<textureoffset>(type<side_t>) == 0, "C layout of side_t: offsetof textureoffset")
    static_assert(typeinfo offsetof<rowoffset>(type<side_t>) == 4, "C layout of side_t: offsetof rowoffset")
    static_assert(typeinfo offsetof<toptexture>(type<side_t>) == 8, "C layout of side_t: offsetof toptexture")
    static_assert(typeinfo offsetof<bottomtexture>(type<side_t>) == 10, "C layout of side_t: offsetof bottomtexture")
    static_assert(typeinfo offsetof<midtexture>(type<side_t>) == 12, "C layout of side_t: offsetof midtexture")
    static_assert(typeinfo offsetof<sector>(type<side_t>) == 16, "C layout of side_t: offsetof sector")
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
    static_assert(typeinfo sizeof(type<seg_t>) == 56, "C layout of seg_t: sizeof")
    static_assert(typeinfo alignof(type<seg_t>) == 8, "C layout of seg_t: alignof")
    static_assert(typeinfo offsetof<v1>(type<seg_t>) == 0, "C layout of seg_t: offsetof v1")
    static_assert(typeinfo offsetof<v2>(type<seg_t>) == 8, "C layout of seg_t: offsetof v2")
    static_assert(typeinfo offsetof<offset>(type<seg_t>) == 16, "C layout of seg_t: offsetof offset")
    static_assert(typeinfo offsetof<angle>(type<seg_t>) == 20, "C layout of seg_t: offsetof angle")
    static_assert(typeinfo offsetof<sidedef>(type<seg_t>) == 24, "C layout of seg_t: offsetof sidedef")
    static_assert(typeinfo offsetof<linedef>(type<seg_t>) == 32, "C layout of seg_t: offsetof linedef")
    static_assert(typeinfo offsetof<frontsector>(type<seg_t>) == 40, "C layout of seg_t: offsetof frontsector")
    static_assert(typeinfo offsetof<backsector>(type<seg_t>) == 48, "C layout of seg_t: offsetof backsector")
    static_assert(typeinfo sizeof(type<node_t>) == 52, "C layout of node_t: sizeof")
    static_assert(typeinfo alignof(type<node_t>) == 4, "C layout of node_t: alignof")
    static_assert(typeinfo offsetof<x>(type<node_t>) == 0, "C layout of node_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<node_t>) == 4, "C layout of node_t: offsetof y")
    static_assert(typeinfo offsetof<dx>(type<node_t>) == 8, "C layout of node_t: offsetof dx")
    static_assert(typeinfo offsetof<dy>(type<node_t>) == 12, "C layout of node_t: offsetof dy")
    static_assert(typeinfo offsetof<bbox>(type<node_t>) == 16, "C layout of node_t: offsetof bbox")
    static_assert(typeinfo offsetof<children>(type<node_t>) == 48, "C layout of node_t: offsetof children")
    static_assert(typeinfo sizeof(type<drawseg_s>) == 64, "C layout of drawseg_s: sizeof")
    static_assert(typeinfo alignof(type<drawseg_s>) == 8, "C layout of drawseg_s: alignof")
    static_assert(typeinfo offsetof<curline>(type<drawseg_s>) == 0, "C layout of drawseg_s: offsetof curline")
    static_assert(typeinfo offsetof<x1>(type<drawseg_s>) == 8, "C layout of drawseg_s: offsetof x1")
    static_assert(typeinfo offsetof<x2>(type<drawseg_s>) == 12, "C layout of drawseg_s: offsetof x2")
    static_assert(typeinfo offsetof<scale1>(type<drawseg_s>) == 16, "C layout of drawseg_s: offsetof scale1")
    static_assert(typeinfo offsetof<scale2>(type<drawseg_s>) == 20, "C layout of drawseg_s: offsetof scale2")
    static_assert(typeinfo offsetof<scalestep>(type<drawseg_s>) == 24, "C layout of drawseg_s: offsetof scalestep")
    static_assert(typeinfo offsetof<silhouette>(type<drawseg_s>) == 28, "C layout of drawseg_s: offsetof silhouette")
    static_assert(typeinfo offsetof<bsilheight>(type<drawseg_s>) == 32, "C layout of drawseg_s: offsetof bsilheight")
    static_assert(typeinfo offsetof<tsilheight>(type<drawseg_s>) == 36, "C layout of drawseg_s: offsetof tsilheight")
    static_assert(typeinfo offsetof<sprtopclip>(type<drawseg_s>) == 40, "C layout of drawseg_s: offsetof sprtopclip")
    static_assert(typeinfo offsetof<sprbottomclip>(type<drawseg_s>) == 48, "C layout of drawseg_s: offsetof sprbottomclip")
    static_assert(typeinfo offsetof<maskedtexturecol>(type<drawseg_s>) == 56, "C layout of drawseg_s: offsetof maskedtexturecol")
    static_assert(typeinfo sizeof(type<drawseg_t>) == 64, "C layout of drawseg_t: sizeof")
    static_assert(typeinfo alignof(type<drawseg_t>) == 8, "C layout of drawseg_t: alignof")
    static_assert(typeinfo offsetof<curline>(type<drawseg_t>) == 0, "C layout of drawseg_t: offsetof curline")
    static_assert(typeinfo offsetof<x1>(type<drawseg_t>) == 8, "C layout of drawseg_t: offsetof x1")
    static_assert(typeinfo offsetof<x2>(type<drawseg_t>) == 12, "C layout of drawseg_t: offsetof x2")
    static_assert(typeinfo offsetof<scale1>(type<drawseg_t>) == 16, "C layout of drawseg_t: offsetof scale1")
    static_assert(typeinfo offsetof<scale2>(type<drawseg_t>) == 20, "C layout of drawseg_t: offsetof scale2")
    static_assert(typeinfo offsetof<scalestep>(type<drawseg_t>) == 24, "C layout of drawseg_t: offsetof scalestep")
    static_assert(typeinfo offsetof<silhouette>(type<drawseg_t>) == 28, "C layout of drawseg_t: offsetof silhouette")
    static_assert(typeinfo offsetof<bsilheight>(type<drawseg_t>) == 32, "C layout of drawseg_t: offsetof bsilheight")
    static_assert(typeinfo offsetof<tsilheight>(type<drawseg_t>) == 36, "C layout of drawseg_t: offsetof tsilheight")
    static_assert(typeinfo offsetof<sprtopclip>(type<drawseg_t>) == 40, "C layout of drawseg_t: offsetof sprtopclip")
    static_assert(typeinfo offsetof<sprbottomclip>(type<drawseg_t>) == 48, "C layout of drawseg_t: offsetof sprbottomclip")
    static_assert(typeinfo offsetof<maskedtexturecol>(type<drawseg_t>) == 56, "C layout of drawseg_t: offsetof maskedtexturecol")
    static_assert(typeinfo sizeof(type<visplane_t>) == 664, "C layout of visplane_t: sizeof")
    static_assert(typeinfo alignof(type<visplane_t>) == 4, "C layout of visplane_t: alignof")
    static_assert(typeinfo offsetof<height>(type<visplane_t>) == 0, "C layout of visplane_t: offsetof height")
    static_assert(typeinfo offsetof<picnum>(type<visplane_t>) == 4, "C layout of visplane_t: offsetof picnum")
    static_assert(typeinfo offsetof<lightlevel>(type<visplane_t>) == 8, "C layout of visplane_t: offsetof lightlevel")
    static_assert(typeinfo offsetof<minx>(type<visplane_t>) == 12, "C layout of visplane_t: offsetof minx")
    static_assert(typeinfo offsetof<maxx>(type<visplane_t>) == 16, "C layout of visplane_t: offsetof maxx")
    static_assert(typeinfo offsetof<pad1>(type<visplane_t>) == 20, "C layout of visplane_t: offsetof pad1")
    static_assert(typeinfo offsetof<top>(type<visplane_t>) == 21, "C layout of visplane_t: offsetof top")
    static_assert(typeinfo offsetof<pad2>(type<visplane_t>) == 341, "C layout of visplane_t: offsetof pad2")
    static_assert(typeinfo offsetof<pad3>(type<visplane_t>) == 342, "C layout of visplane_t: offsetof pad3")
    static_assert(typeinfo offsetof<bottom>(type<visplane_t>) == 343, "C layout of visplane_t: offsetof bottom")
    static_assert(typeinfo offsetof<pad4>(type<visplane_t>) == 663, "C layout of visplane_t: offsetof pad4")
    static_assert(typeinfo sizeof(type<cliprange_t>) == 8, "C layout of cliprange_t: sizeof")
    static_assert(typeinfo alignof(type<cliprange_t>) == 4, "C layout of cliprange_t: alignof")
    static_assert(typeinfo offsetof<first>(type<cliprange_t>) == 0, "C layout of cliprange_t: offsetof first")
    static_assert(typeinfo offsetof<last>(type<cliprange_t>) == 4, "C layout of cliprange_t: offsetof last")
}
