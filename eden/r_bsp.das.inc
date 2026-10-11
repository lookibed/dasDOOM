var curline : int = default<int>

var sidedef : int = default<int>

var linedef : int = default<int>

var frontsector : int = default<int>

var backsector : int = default<int>

var ds_p : int = default<int>

[export, sideeffects]
def R_ClearDrawSegs() {
    ds_p = 67456
    return
}
var newend : int = default<int>

[export, sideeffects]
def R_ClipSolidWallSegment(var first : int; var last : int) {
    var next : int
    var start : int = 83840
    label 0:
    if (int(uint(c2da_mem[start + 4]) | uint(c2da_mem[start + 5]) << 0x8 | uint(c2da_mem[start + 6]) << 0x10 | uint(c2da_mem[start + 7]) << 0x18) < first - 1) {
        goto label 14
    }
    if (first < int(uint(c2da_mem[start]) | uint(c2da_mem[start + 1]) << 0x8 | uint(c2da_mem[start + 2]) << 0x10 | uint(c2da_mem[start + 3]) << 0x18)) {
        goto label 10
    }
    label 1:
    if (last <= int(uint(c2da_mem[start + 4]) | uint(c2da_mem[start + 5]) << 0x8 | uint(c2da_mem[start + 6]) << 0x10 | uint(c2da_mem[start + 7]) << 0x18)) {
        goto label 9
    }
    next = start
    label 2:
    if (last >= int(uint(c2da_mem[next + 1 * 8]) | uint(c2da_mem[next + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[next + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[next + 1 * 8 + 3]) << 0x18) - 1) {
        goto label 7
    }
    R_StoreWallRange(int(uint(c2da_mem[next + 4]) | uint(c2da_mem[next + 5]) << 0x8 | uint(c2da_mem[next + 6]) << 0x10 | uint(c2da_mem[next + 7]) << 0x18) + 1, last)
    let c2da_fresh5 : uint = uint(last)
    c2da_mem[start + 4] = uint8(c2da_fresh5)
    c2da_mem[start + 5] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[start + 6] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[start + 7] = uint8(c2da_fresh5 >> 0x18)
    label 3:
    if (next == start) {
        goto label 6
    }
    label 4:
    let c2da_fresh6 : int = next
    next += 8
    if (c2da_fresh6 != newend) {
        goto label 5
    }
    newend = start + 1 * 8
    return
    label 5:
    start += 8
    c2da_lin_memmove(start, next, 8ul)
    goto label 4
    label 6:
    return
    label 7:
    R_StoreWallRange(int(uint(c2da_mem[next + 4]) | uint(c2da_mem[next + 5]) << 0x8 | uint(c2da_mem[next + 6]) << 0x10 | uint(c2da_mem[next + 7]) << 0x18) + 1, int(uint(c2da_mem[next + 1 * 8]) | uint(c2da_mem[next + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[next + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[next + 1 * 8 + 3]) << 0x18) - 1)
    next += 8
    if (last <= int(uint(c2da_mem[next + 4]) | uint(c2da_mem[next + 5]) << 0x8 | uint(c2da_mem[next + 6]) << 0x10 | uint(c2da_mem[next + 7]) << 0x18)) {
        goto label 8
    }
    goto label 2
    label 8:
    let c2da_fresh3 : int = int(uint(c2da_mem[next + 4]) | uint(c2da_mem[next + 5]) << 0x8 | uint(c2da_mem[next + 6]) << 0x10 | uint(c2da_mem[next + 7]) << 0x18)
    let c2da_fresh4 : uint = uint(c2da_fresh3)
    c2da_mem[start + 4] = uint8(c2da_fresh4)
    c2da_mem[start + 5] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[start + 6] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[start + 7] = uint8(c2da_fresh4 >> 0x18)
    goto label 3
    label 9:
    return
    label 10:
    if (last < int(uint(c2da_mem[start]) | uint(c2da_mem[start + 1]) << 0x8 | uint(c2da_mem[start + 2]) << 0x10 | uint(c2da_mem[start + 3]) << 0x18) - 1) {
        goto label 11
    }
    R_StoreWallRange(first, int(uint(c2da_mem[start]) | uint(c2da_mem[start + 1]) << 0x8 | uint(c2da_mem[start + 2]) << 0x10 | uint(c2da_mem[start + 3]) << 0x18) - 1)
    let c2da_fresh2 : uint = uint(first)
    c2da_mem[start] = uint8(c2da_fresh2)
    c2da_mem[start + 1] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[start + 2] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[start + 3] = uint8(c2da_fresh2 >> 0x18)
    goto label 1
    label 11:
    R_StoreWallRange(first, last)
    next = newend
    newend += 8
    label 12:
    if (next != start) {
        goto label 13
    }
    let c2da_fresh0 : uint = uint(first)
    c2da_mem[next] = uint8(c2da_fresh0)
    c2da_mem[next + 1] = uint8(c2da_fresh0 >> 0x8)
    c2da_mem[next + 2] = uint8(c2da_fresh0 >> 0x10)
    c2da_mem[next + 3] = uint8(c2da_fresh0 >> 0x18)
    let c2da_fresh1 : uint = uint(last)
    c2da_mem[next + 4] = uint8(c2da_fresh1)
    c2da_mem[next + 5] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[next + 6] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[next + 7] = uint8(c2da_fresh1 >> 0x18)
    return
    label 13:
    c2da_lin_memmove(next, next - 1 * 8, 8ul)
    next -= 8
    goto label 12
    label 14:
    start += 8
    goto label 0
    panic("unreachable: fell out of a translated control-flow graph")
}
[export, sideeffects]
def R_ClipPassWallSegment(var first_0 : int; var last_0 : int) {
    var start_0 : int = 83840
    while (int(uint(c2da_mem[start_0 + 4]) | uint(c2da_mem[start_0 + 5]) << 0x8 | uint(c2da_mem[start_0 + 6]) << 0x10 | uint(c2da_mem[start_0 + 7]) << 0x18) < first_0 - 1) {
        start_0 += 8
    }
    if (first_0 < int(uint(c2da_mem[start_0]) | uint(c2da_mem[start_0 + 1]) << 0x8 | uint(c2da_mem[start_0 + 2]) << 0x10 | uint(c2da_mem[start_0 + 3]) << 0x18)) {
        if (last_0 < int(uint(c2da_mem[start_0]) | uint(c2da_mem[start_0 + 1]) << 0x8 | uint(c2da_mem[start_0 + 2]) << 0x10 | uint(c2da_mem[start_0 + 3]) << 0x18) - 1) {
            R_StoreWallRange(first_0, last_0)
            return
        }
        R_StoreWallRange(first_0, int(uint(c2da_mem[start_0]) | uint(c2da_mem[start_0 + 1]) << 0x8 | uint(c2da_mem[start_0 + 2]) << 0x10 | uint(c2da_mem[start_0 + 3]) << 0x18) - 1)
    }
    if (last_0 <= int(uint(c2da_mem[start_0 + 4]) | uint(c2da_mem[start_0 + 5]) << 0x8 | uint(c2da_mem[start_0 + 6]) << 0x10 | uint(c2da_mem[start_0 + 7]) << 0x18)) {
        return
    }
    while (last_0 >= int(uint(c2da_mem[start_0 + 1 * 8]) | uint(c2da_mem[start_0 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[start_0 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[start_0 + 1 * 8 + 3]) << 0x18) - 1) {
        R_StoreWallRange(int(uint(c2da_mem[start_0 + 4]) | uint(c2da_mem[start_0 + 5]) << 0x8 | uint(c2da_mem[start_0 + 6]) << 0x10 | uint(c2da_mem[start_0 + 7]) << 0x18) + 1, int(uint(c2da_mem[start_0 + 1 * 8]) | uint(c2da_mem[start_0 + 1 * 8 + 1]) << 0x8 | uint(c2da_mem[start_0 + 1 * 8 + 2]) << 0x10 | uint(c2da_mem[start_0 + 1 * 8 + 3]) << 0x18) - 1)
        start_0 += 8
        if (last_0 <= int(uint(c2da_mem[start_0 + 4]) | uint(c2da_mem[start_0 + 5]) << 0x8 | uint(c2da_mem[start_0 + 6]) << 0x10 | uint(c2da_mem[start_0 + 7]) << 0x18)) {
            return
        }
    }
    R_StoreWallRange(int(uint(c2da_mem[start_0 + 4]) | uint(c2da_mem[start_0 + 5]) << 0x8 | uint(c2da_mem[start_0 + 6]) << 0x10 | uint(c2da_mem[start_0 + 7]) << 0x18) + 1, last_0)
    return
}
[export, sideeffects]
def R_ClearClipSegs() {
    let c2da_fresh7 : int = -2147483647
    let c2da_fresh8 : uint = uint(c2da_fresh7)
    c2da_mem[83840 + 0 * 8] = uint8(c2da_fresh8)
    c2da_mem[83840 + 0 * 8 + 1] = uint8(c2da_fresh8 >> 0x8)
    c2da_mem[83840 + 0 * 8 + 2] = uint8(c2da_fresh8 >> 0x10)
    c2da_mem[83840 + 0 * 8 + 3] = uint8(c2da_fresh8 >> 0x18)
    let c2da_fresh9 : int = -1
    let c2da_fresh10 : uint = uint(c2da_fresh9)
    c2da_mem[83840 + 0 * 8 + 4] = uint8(c2da_fresh10)
    c2da_mem[83840 + 0 * 8 + 5] = uint8(c2da_fresh10 >> 0x8)
    c2da_mem[83840 + 0 * 8 + 6] = uint8(c2da_fresh10 >> 0x10)
    c2da_mem[83840 + 0 * 8 + 7] = uint8(c2da_fresh10 >> 0x18)
    let c2da_fresh11 : uint = uint(viewwidth)
    c2da_mem[83840 + 1 * 8] = uint8(c2da_fresh11)
    c2da_mem[83840 + 1 * 8 + 1] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[83840 + 1 * 8 + 2] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[83840 + 1 * 8 + 3] = uint8(c2da_fresh11 >> 0x18)
    let c2da_fresh12 : int = 2147483647
    let c2da_fresh13 : uint = uint(c2da_fresh12)
    c2da_mem[83840 + 1 * 8 + 4] = uint8(c2da_fresh13)
    c2da_mem[83840 + 1 * 8 + 5] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[83840 + 1 * 8 + 6] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[83840 + 1 * 8 + 7] = uint8(c2da_fresh13 >> 0x18)
    newend = 83840 + 2 * 8
    return
}
[export, sideeffects]
def R_AddLine(var line : int) {
    var x1 : int
    var x2 : int
    var angle1 : uint
    var angle2 : uint
    var span : uint
    var tspan : uint
    var c2da_fresh19 : int
    curline = int(line)  // nolint:PERF020
    let c2da_fresh14 : int = int(uint(c2da_mem[line]) | uint(c2da_mem[line + 1]) << 0x8 | uint(c2da_mem[line + 2]) << 0x10 | uint(c2da_mem[line + 3]) << 0x18)
    let c2da_fresh15 : int = int(uint(c2da_mem[line]) | uint(c2da_mem[line + 1]) << 0x8 | uint(c2da_mem[line + 2]) << 0x10 | uint(c2da_mem[line + 3]) << 0x18) + 4
    angle1 = uint(R_PointToAngle(int(uint(c2da_mem[c2da_fresh14]) | uint(c2da_mem[c2da_fresh14 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh14 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh14 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh15]) | uint(c2da_mem[c2da_fresh15 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh15 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh15 + 3]) << 0x18)))
    let c2da_fresh16 : int = int(uint(c2da_mem[line + 8]) | uint(c2da_mem[line + 9]) << 0x8 | uint(c2da_mem[line + 10]) << 0x10 | uint(c2da_mem[line + 11]) << 0x18)
    let c2da_fresh17 : int = int(uint(c2da_mem[line + 8]) | uint(c2da_mem[line + 9]) << 0x8 | uint(c2da_mem[line + 10]) << 0x10 | uint(c2da_mem[line + 11]) << 0x18) + 4
    angle2 = uint(R_PointToAngle(int(uint(c2da_mem[c2da_fresh16]) | uint(c2da_mem[c2da_fresh16 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh16 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh16 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh17]) | uint(c2da_mem[c2da_fresh17 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh17 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh17 + 3]) << 0x18)))
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
    backsector = int(uint(c2da_mem[line + 48]) | uint(c2da_mem[line + 49]) << 0x8 | uint(c2da_mem[line + 50]) << 0x10 | uint(c2da_mem[line + 51]) << 0x18)
    if (backsector == 0) {
        goto label 7
    }
    if (int(uint(c2da_mem[backsector + 4]) | uint(c2da_mem[backsector + 5]) << 0x8 | uint(c2da_mem[backsector + 6]) << 0x10 | uint(c2da_mem[backsector + 7]) << 0x18) <= int(uint(c2da_mem[frontsector]) | uint(c2da_mem[frontsector + 1]) << 0x8 | uint(c2da_mem[frontsector + 2]) << 0x10 | uint(c2da_mem[frontsector + 3]) << 0x18) || int(uint(c2da_mem[backsector]) | uint(c2da_mem[backsector + 1]) << 0x8 | uint(c2da_mem[backsector + 2]) << 0x10 | uint(c2da_mem[backsector + 3]) << 0x18) >= int(uint(c2da_mem[frontsector + 4]) | uint(c2da_mem[frontsector + 5]) << 0x8 | uint(c2da_mem[frontsector + 6]) << 0x10 | uint(c2da_mem[frontsector + 7]) << 0x18)) {
        goto label 5
    }
    if (int(uint(c2da_mem[backsector + 4]) | uint(c2da_mem[backsector + 5]) << 0x8 | uint(c2da_mem[backsector + 6]) << 0x10 | uint(c2da_mem[backsector + 7]) << 0x18) != int(uint(c2da_mem[frontsector + 4]) | uint(c2da_mem[frontsector + 5]) << 0x8 | uint(c2da_mem[frontsector + 6]) << 0x10 | uint(c2da_mem[frontsector + 7]) << 0x18) || int(uint(c2da_mem[backsector]) | uint(c2da_mem[backsector + 1]) << 0x8 | uint(c2da_mem[backsector + 2]) << 0x10 | uint(c2da_mem[backsector + 3]) << 0x18) != int(uint(c2da_mem[frontsector]) | uint(c2da_mem[frontsector + 1]) << 0x8 | uint(c2da_mem[frontsector + 2]) << 0x10 | uint(c2da_mem[frontsector + 3]) << 0x18)) {
        goto label 4
    }
    c2da_fresh19 = 0
    if (int(int16(uint(c2da_mem[backsector + 10]) | uint(c2da_mem[backsector + 11]) << 0x8)) == int(int16(uint(c2da_mem[frontsector + 10]) | uint(c2da_mem[frontsector + 11]) << 0x8)) && int(int16(uint(c2da_mem[backsector + 8]) | uint(c2da_mem[backsector + 9]) << 0x8)) == int(int16(uint(c2da_mem[frontsector + 8]) | uint(c2da_mem[frontsector + 9]) << 0x8)) && int(int16(uint(c2da_mem[backsector + 12]) | uint(c2da_mem[backsector + 13]) << 0x8)) == int(int16(uint(c2da_mem[frontsector + 12]) | uint(c2da_mem[frontsector + 13]) << 0x8))) {
        let c2da_fresh18 : int = int(uint(c2da_mem[curline + 24]) | uint(c2da_mem[curline + 25]) << 0x8 | uint(c2da_mem[curline + 26]) << 0x10 | uint(c2da_mem[curline + 27]) << 0x18) + 12
        if (int(int16(uint(c2da_mem[c2da_fresh18]) | uint(c2da_mem[c2da_fresh18 + 1]) << 0x8)) == 0) {
            c2da_fresh19 = 1
        }
    }
    if (c2da_fresh19 != 0) {
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
def R_CheckBBox(var bspcoord : int) : uint {
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
    var start_1 : int
    var sx1 : int
    var sx2 : int
    if (viewx <= int(uint(c2da_mem[bspcoord + 2 * 4]) | uint(c2da_mem[bspcoord + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[bspcoord + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[bspcoord + 2 * 4 + 3]) << 0x18)) {
        boxx = 0
    } elif (viewx < int(uint(c2da_mem[bspcoord + 3 * 4]) | uint(c2da_mem[bspcoord + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[bspcoord + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[bspcoord + 3 * 4 + 3]) << 0x18)) {
        boxx = 1
    } else {
        boxx = 2
    }
    if (viewy >= int(uint(c2da_mem[bspcoord + 0 * 4]) | uint(c2da_mem[bspcoord + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[bspcoord + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[bspcoord + 0 * 4 + 3]) << 0x18)) {
        boxy = 0
    } elif (viewy > int(uint(c2da_mem[bspcoord + 1 * 4]) | uint(c2da_mem[bspcoord + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[bspcoord + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[bspcoord + 1 * 4 + 3]) << 0x18)) {
        boxy = 1
    } else {
        boxy = 2
    }
    boxpos = (boxy << 2) + boxx
    if (boxpos == 5) {
        return 1u
    }
    let c2da_fresh20 : int = bspcoord + checkcoord[boxpos][0] * 4
    x1_0 = int(uint(c2da_mem[c2da_fresh20]) | uint(c2da_mem[c2da_fresh20 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh20 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh20 + 3]) << 0x18)
    let c2da_fresh21 : int = bspcoord + checkcoord[boxpos][1] * 4
    y1 = int(uint(c2da_mem[c2da_fresh21]) | uint(c2da_mem[c2da_fresh21 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh21 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh21 + 3]) << 0x18)
    let c2da_fresh22 : int = bspcoord + checkcoord[boxpos][2] * 4
    x2_0 = int(uint(c2da_mem[c2da_fresh22]) | uint(c2da_mem[c2da_fresh22 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh22 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh22 + 3]) << 0x18)
    let c2da_fresh23 : int = bspcoord + checkcoord[boxpos][3] * 4
    y2 = int(uint(c2da_mem[c2da_fresh23]) | uint(c2da_mem[c2da_fresh23 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh23 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh23 + 3]) << 0x18)
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
    start_1 = 83840
    while (int(uint(c2da_mem[start_1 + 4]) | uint(c2da_mem[start_1 + 5]) << 0x8 | uint(c2da_mem[start_1 + 6]) << 0x10 | uint(c2da_mem[start_1 + 7]) << 0x18) < sx2) {
        start_1 += 8
    }
    if (sx1 >= int(uint(c2da_mem[start_1]) | uint(c2da_mem[start_1 + 1]) << 0x8 | uint(c2da_mem[start_1 + 2]) << 0x10 | uint(c2da_mem[start_1 + 3]) << 0x18) && sx2 <= int(uint(c2da_mem[start_1 + 4]) | uint(c2da_mem[start_1 + 5]) << 0x8 | uint(c2da_mem[start_1 + 6]) << 0x10 | uint(c2da_mem[start_1 + 7]) << 0x18)) {
        return 0u
    }
    return 1u
}
[export, sideeffects]
def R_Subsector(var num : int) {
    var count : int
    var line_0 : int
    var sub : int
    if (num >= numsubsectors) {
        I_Error(361840, [C2daVaArg(tag = 1, i64 = int64(num), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(numsubsectors), f64 = 0.0lf, raw = 0x0)])
    }
    sscount = sscount + 1
    sub = subsectors + num * 16
    frontsector = int(uint(c2da_mem[sub]) | uint(c2da_mem[sub + 1]) << 0x8 | uint(c2da_mem[sub + 2]) << 0x10 | uint(c2da_mem[sub + 3]) << 0x18)
    count = int(int16(uint(c2da_mem[sub + 8]) | uint(c2da_mem[sub + 9]) << 0x8))
    line_0 = segs + int(int16(uint(c2da_mem[sub + 10]) | uint(c2da_mem[sub + 11]) << 0x8)) * 56
    if (int(uint(c2da_mem[frontsector]) | uint(c2da_mem[frontsector + 1]) << 0x8 | uint(c2da_mem[frontsector + 2]) << 0x10 | uint(c2da_mem[frontsector + 3]) << 0x18) < viewz) {
        floorplane = R_FindPlane(int(uint(c2da_mem[frontsector]) | uint(c2da_mem[frontsector + 1]) << 0x8 | uint(c2da_mem[frontsector + 2]) << 0x10 | uint(c2da_mem[frontsector + 3]) << 0x18), int(int16(uint(c2da_mem[frontsector + 8]) | uint(c2da_mem[frontsector + 9]) << 0x8)), int(int16(uint(c2da_mem[frontsector + 12]) | uint(c2da_mem[frontsector + 13]) << 0x8)))
    } else {
        floorplane = 0
    }
    if (int(uint(c2da_mem[frontsector + 4]) | uint(c2da_mem[frontsector + 5]) << 0x8 | uint(c2da_mem[frontsector + 6]) << 0x10 | uint(c2da_mem[frontsector + 7]) << 0x18) > viewz || int(int16(uint(c2da_mem[frontsector + 10]) | uint(c2da_mem[frontsector + 11]) << 0x8)) == skyflatnum) {
        ceilingplane = R_FindPlane(int(uint(c2da_mem[frontsector + 4]) | uint(c2da_mem[frontsector + 5]) << 0x8 | uint(c2da_mem[frontsector + 6]) << 0x10 | uint(c2da_mem[frontsector + 7]) << 0x18), int(int16(uint(c2da_mem[frontsector + 10]) | uint(c2da_mem[frontsector + 11]) << 0x8)), int(int16(uint(c2da_mem[frontsector + 12]) | uint(c2da_mem[frontsector + 13]) << 0x8)))
    } else {
        ceilingplane = 0
    }
    R_AddSprites(frontsector)
    while (true) {
        let c2da_postinc : int = count
        count--
        if (c2da_postinc == 0) {
            break
        }
        R_AddLine(line_0)
        line_0 += 56
    }
    return
}
[export, sideeffects]
def R_RenderBSPNode(var bspnum : int) {
    var bsp : int
    var side : int
    if ((bspnum & 32768) != 0) {
        if (bspnum == -1) {
            R_Subsector(0)
        } else {
            R_Subsector(bspnum & ~32768)
        }
        return
    }
    bsp = nodes + bspnum * 52
    side = R_PointOnSide(viewx, viewy, bsp)
    R_RenderBSPNode(int(uint16(uint(c2da_mem[bsp + 48 + side * 2]) | uint(c2da_mem[bsp + 48 + side * 2 + 1]) << 0x8)))
    if (R_CheckBBox(bsp + 16 + (side ^ 1) * 16) != 0x0) {
        let c2da_fresh24 : int = bsp + 48 + (side ^ 1) * 2
        R_RenderBSPNode(int(uint16(uint(c2da_mem[c2da_fresh24]) | uint(c2da_mem[c2da_fresh24 + 1]) << 0x8)))
    }
    return
}

// This unit's static data, at heap offset 361840.
let private c2da_lin_static_r_bsp_seg = fixed_array<int>(361840, 34)
let private c2da_lin_static_r_bsp = fixed_array<uint64>(0x6365736275535f52ul, 0x207373203a726f74ul, 0x2068746977206925ul, 0x203d2073736d756eul, 0x6925ul)

[init]
def private c2da_lin_init_static_r_bsp() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_r_bsp_seg[s * 2]
        for (k in range(c2da_lin_static_r_bsp_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_r_bsp[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
