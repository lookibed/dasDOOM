[sideeffects]
def private c2da___bswap_16_13(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_13(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_13(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_13(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_13(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_13(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
var floorplane : int = default<int>

var ceilingplane : int = default<int>

var lastopening : int = default<int>

var floorfunc : planefunction_t = default<planefunction_t>

var yslope : int[200]

var distscale : int[320]

[export, sideeffects]
def R_InitPlanes() {
    return
}
[export, sideeffects]
def R_ClearPlanes() {
    var i : int
    var angle : uint
    i = 0
    while (i < viewwidth) {
        let c2da_fresh0 : int16 = int16(viewheight)
        let c2da_fresh1 : uint = uint(c2da_fresh0)
        c2da_mem[235680 + i * 2] = uint8(c2da_fresh1)
        c2da_mem[235680 + i * 2 + 1] = uint8(c2da_fresh1 >> 0x8)
        let c2da_fresh2 : int16 = int16(-1)
        let c2da_fresh3 : uint = uint(c2da_fresh2)
        c2da_mem[235040 + i * 2] = uint8(c2da_fresh3)
        c2da_mem[235040 + i * 2 + 1] = uint8(c2da_fresh3 >> 0x8)
        i++
    }
    lastvisplane = 84480
    lastopening = 169472
    c2da_lin_memset(210432, 0, 800ul)
    angle = uint(viewangle - 0x40000000u >> 19u)
    basexscale = FixedDiv(int(uint(c2da_mem[finecosine + int(angle) * 4]) | uint(c2da_mem[finecosine + int(angle) * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + int(angle) * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + int(angle) * 4 + 3]) << 0x18), centerxfrac)
    baseyscale = -FixedDiv(int(uint(c2da_mem[257920 + int(angle) * 4]) | uint(c2da_mem[257920 + int(angle) * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + int(angle) * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + int(angle) * 4 + 3]) << 0x18), centerxfrac)
    return
}
var baseyscale : int = default<int>

var basexscale : int = default<int>

var lastvisplane : int = default<int>

[export, sideeffects]
def R_MapPlane(var y : int; var x1 : int; var x2 : int) {
    var angle_0 : uint
    var distance : int
    var length_0 : int
    var index : uint
    if (x2 < x1 || x1 < 0 || x2 >= viewwidth || y > viewheight) {
        I_Error(362464, [C2daVaArg(tag = 1, i64 = int64(x1), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(x2), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(y), f64 = 0.0lf, raw = 0x0)])
    }
    if (planeheight != int(uint(c2da_mem[210432 + y * 4]) | uint(c2da_mem[210432 + y * 4 + 1]) << 0x8 | uint(c2da_mem[210432 + y * 4 + 2]) << 0x10 | uint(c2da_mem[210432 + y * 4 + 3]) << 0x18)) {
        let c2da_fresh4 : uint = uint(planeheight)
        c2da_mem[210432 + y * 4] = uint8(c2da_fresh4)
        c2da_mem[210432 + y * 4 + 1] = uint8(c2da_fresh4 >> 0x8)
        c2da_mem[210432 + y * 4 + 2] = uint8(c2da_fresh4 >> 0x10)
        c2da_mem[210432 + y * 4 + 3] = uint8(c2da_fresh4 >> 0x18)
        cacheddistance[y] = FixedMul(planeheight, yslope[y])
        distance = cacheddistance[y]
        cachedxstep[y] = FixedMul(distance, basexscale)
        ds_xstep = cachedxstep[y]
        cachedystep[y] = FixedMul(distance, baseyscale)
        ds_ystep = cachedystep[y]
    } else {
        distance = cacheddistance[y]
        ds_xstep = cachedxstep[y]
        ds_ystep = cachedystep[y]
    }
    length_0 = FixedMul(distance, distscale[x1])
    angle_0 = uint(viewangle + xtoviewangle[x1] >> 19u)
    ds_xfrac = viewx + FixedMul(int(uint(c2da_mem[finecosine + int(angle_0) * 4]) | uint(c2da_mem[finecosine + int(angle_0) * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + int(angle_0) * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + int(angle_0) * 4 + 3]) << 0x18), length_0)
    ds_yfrac = -viewy - FixedMul(int(uint(c2da_mem[257920 + int(angle_0) * 4]) | uint(c2da_mem[257920 + int(angle_0) * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + int(angle_0) * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + int(angle_0) * 4 + 3]) << 0x18), length_0)
    if (fixedcolormap != 0) {
        ds_colormap = fixedcolormap
    } else {
        index = uint(distance >> 20)
        if (index >= 128u) {
            index = uint(128 - 1)
        }
        ds_colormap = int(uint(c2da_mem[planezlight + int(index) * 8]) | uint(c2da_mem[planezlight + int(index) * 8 + 1]) << 0x8 | uint(c2da_mem[planezlight + int(index) * 8 + 2]) << 0x10 | uint(c2da_mem[planezlight + int(index) * 8 + 3]) << 0x18)
    }
    ds_y = y
    ds_x1 = x1
    ds_x2 = x2
    invoke(c2da_fn_table0[spanfunc])
    return
}
var planezlight : int = default<int>

var cachedystep : int[200]

var cachedxstep : int[200]

var cacheddistance : int[200]

var planeheight : int = default<int>

[export, sideeffects]
def R_MakeSpans(var x : int; var t1 : int; var b1 : int; var t2 : int; var b2 : int) {
    while (t1 < t2 && t1 <= b1) {
        R_MapPlane(t1, spanstart[t1], x - 1)
        t1++
    }
    while (b1 > b2 && b1 >= t1) {
        R_MapPlane(b1, spanstart[b1], x - 1)
        b1--
    }
    while (t2 < t1 && t2 <= b2) {
        spanstart[t2] = int(x)  // nolint:PERF020
        t2++
    }
    while (b2 > b1 && b2 >= t2) {
        spanstart[b2] = int(x)  // nolint:PERF020
        b2--
    }
    return
}
var spanstart : int[200]

[export, sideeffects]
def R_DrawPlanes() {
    var pl : int
    var light : int
    var x_0 : int
    var stop : int
    var angle_1 : int
    var lumpnum : int
    if (int64((ds_p - 67456) / 64) > 256l) {
        I_Error(362489, [C2daVaArg(tag = 1, i64 = int64((ds_p - 67456) / 64), f64 = 0.0lf, raw = 0x0)])
    }
    if (int64((lastvisplane - 84480) / 664) > 128l) {
        I_Error(362526, [C2daVaArg(tag = 1, i64 = int64((lastvisplane - 84480) / 664), f64 = 0.0lf, raw = 0x0)])
    }
    if (int64((lastopening - 169472) / 2) > int64(320 * 64)) {
        I_Error(362563, [C2daVaArg(tag = 1, i64 = int64((lastopening - 169472) / 2), f64 = 0.0lf, raw = 0x0)])
    }
    pl = 84480
    while (pl < lastvisplane) {
        if (int(uint(c2da_mem[pl + 12]) | uint(c2da_mem[pl + 13]) << 0x8 | uint(c2da_mem[pl + 14]) << 0x10 | uint(c2da_mem[pl + 15]) << 0x18) > int(uint(c2da_mem[pl + 16]) | uint(c2da_mem[pl + 17]) << 0x8 | uint(c2da_mem[pl + 18]) << 0x10 | uint(c2da_mem[pl + 19]) << 0x18)) {
            pl += 664
            continue
        }
        if (int(uint(c2da_mem[pl + 4]) | uint(c2da_mem[pl + 5]) << 0x8 | uint(c2da_mem[pl + 6]) << 0x10 | uint(c2da_mem[pl + 7]) << 0x18) == skyflatnum) {
            dc_iscale = pspriteiscale >> detailshift
            dc_colormap = colormaps
            dc_texturemid = skytexturemid
            x_0 = int(uint(c2da_mem[pl + 12]) | uint(c2da_mem[pl + 13]) << 0x8 | uint(c2da_mem[pl + 14]) << 0x10 | uint(c2da_mem[pl + 15]) << 0x18)
            while (x_0 <= int(uint(c2da_mem[pl + 16]) | uint(c2da_mem[pl + 17]) << 0x8 | uint(c2da_mem[pl + 18]) << 0x10 | uint(c2da_mem[pl + 19]) << 0x18)) {
                dc_yl = int(c2da_mem[pl + 21 + x_0])
                dc_yh = int(c2da_mem[pl + 343 + x_0])
                if (dc_yl <= dc_yh) {
                    angle_1 = int(viewangle + xtoviewangle[x_0] >> 22u)
                    dc_x = x_0
                    dc_source = R_GetColumn(skytexture, angle_1)
                    invoke(c2da_fn_table0[colfunc])
                }
                x_0++
            }
            pl += 664
            continue
        }
        let c2da_fresh5 : int = flattranslation + int(uint(c2da_mem[pl + 4]) | uint(c2da_mem[pl + 5]) << 0x8 | uint(c2da_mem[pl + 6]) << 0x10 | uint(c2da_mem[pl + 7]) << 0x18) * 4
        lumpnum = firstflat + int(uint(c2da_mem[c2da_fresh5]) | uint(c2da_mem[c2da_fresh5 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh5 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh5 + 3]) << 0x18)
        ds_source = W_CacheLumpNum(lumpnum, 1)
        planeheight = c2da_std_abs(int(uint(c2da_mem[pl]) | uint(c2da_mem[pl + 1]) << 0x8 | uint(c2da_mem[pl + 2]) << 0x10 | uint(c2da_mem[pl + 3]) << 0x18) - viewz)
        light = (int(uint(c2da_mem[pl + 8]) | uint(c2da_mem[pl + 9]) << 0x8 | uint(c2da_mem[pl + 10]) << 0x10 | uint(c2da_mem[pl + 11]) << 0x18) >> 4) + extralight
        if (light >= 16) {
            light = 16 - 1
        }
        if (light < 0) {
            light = 0
        }
        planezlight = 211232 + light * 1024
        let c2da_fresh6 : int = pl + 21 + (int(uint(c2da_mem[pl + 16]) | uint(c2da_mem[pl + 17]) << 0x8 | uint(c2da_mem[pl + 18]) << 0x10 | uint(c2da_mem[pl + 19]) << 0x18) + 1)
        let c2da_fresh7 : uint8 = 0xffu8
        c2da_mem[c2da_fresh6] = c2da_fresh7
        let c2da_fresh8 : int = pl + 21 + (int(uint(c2da_mem[pl + 12]) | uint(c2da_mem[pl + 13]) << 0x8 | uint(c2da_mem[pl + 14]) << 0x10 | uint(c2da_mem[pl + 15]) << 0x18) - 1)
        let c2da_fresh9 : uint8 = 0xffu8
        c2da_mem[c2da_fresh8] = c2da_fresh9
        stop = int(uint(c2da_mem[pl + 16]) | uint(c2da_mem[pl + 17]) << 0x8 | uint(c2da_mem[pl + 18]) << 0x10 | uint(c2da_mem[pl + 19]) << 0x18) + 1
        x_0 = int(uint(c2da_mem[pl + 12]) | uint(c2da_mem[pl + 13]) << 0x8 | uint(c2da_mem[pl + 14]) << 0x10 | uint(c2da_mem[pl + 15]) << 0x18)
        while (x_0 <= stop) {
            R_MakeSpans(x_0, int(c2da_mem[pl + 21 + (x_0 - 1)]), int(c2da_mem[pl + 343 + (x_0 - 1)]), int(c2da_mem[pl + 21 + x_0]), int(c2da_mem[pl + 343 + x_0]))
            x_0++
        }
        W_ReleaseLumpNum(lumpnum)
        pl += 664
    }
    return
}
[export, sideeffects]
def R_FindPlane(var height : int; var picnum : int; var lightlevel : int) : int {
    var check : int
    if (picnum == skyflatnum) {
        height = 0
        lightlevel = 0
    }
    check = 84480
    while (check < lastvisplane) {
        if (height == int(uint(c2da_mem[check]) | uint(c2da_mem[check + 1]) << 0x8 | uint(c2da_mem[check + 2]) << 0x10 | uint(c2da_mem[check + 3]) << 0x18) && picnum == int(uint(c2da_mem[check + 4]) | uint(c2da_mem[check + 5]) << 0x8 | uint(c2da_mem[check + 6]) << 0x10 | uint(c2da_mem[check + 7]) << 0x18) && lightlevel == int(uint(c2da_mem[check + 8]) | uint(c2da_mem[check + 9]) << 0x8 | uint(c2da_mem[check + 10]) << 0x10 | uint(c2da_mem[check + 11]) << 0x18)) {
            break
        }
        check += 664
    }
    if (check < lastvisplane) {
        return check
    }
    if (int64((lastvisplane - 84480) / 664) == 128l) {
        I_Error(362599, [])
    }
    lastvisplane += 664
    let c2da_fresh10 : uint = uint(height)
    c2da_mem[check] = uint8(c2da_fresh10)
    c2da_mem[check + 1] = uint8(c2da_fresh10 >> 0x8)
    c2da_mem[check + 2] = uint8(c2da_fresh10 >> 0x10)
    c2da_mem[check + 3] = uint8(c2da_fresh10 >> 0x18)
    let c2da_fresh11 : uint = uint(picnum)
    c2da_mem[check + 4] = uint8(c2da_fresh11)
    c2da_mem[check + 5] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[check + 6] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[check + 7] = uint8(c2da_fresh11 >> 0x18)
    let c2da_fresh12 : uint = uint(lightlevel)
    c2da_mem[check + 8] = uint8(c2da_fresh12)
    c2da_mem[check + 9] = uint8(c2da_fresh12 >> 0x8)
    c2da_mem[check + 10] = uint8(c2da_fresh12 >> 0x10)
    c2da_mem[check + 11] = uint8(c2da_fresh12 >> 0x18)
    let c2da_fresh13 : int = 320
    let c2da_fresh14 : uint = uint(c2da_fresh13)
    c2da_mem[check + 12] = uint8(c2da_fresh14)
    c2da_mem[check + 13] = uint8(c2da_fresh14 >> 0x8)
    c2da_mem[check + 14] = uint8(c2da_fresh14 >> 0x10)
    c2da_mem[check + 15] = uint8(c2da_fresh14 >> 0x18)
    let c2da_fresh15 : int = -1
    let c2da_fresh16 : uint = uint(c2da_fresh15)
    c2da_mem[check + 16] = uint8(c2da_fresh16)
    c2da_mem[check + 17] = uint8(c2da_fresh16 >> 0x8)
    c2da_mem[check + 18] = uint8(c2da_fresh16 >> 0x10)
    c2da_mem[check + 19] = uint8(c2da_fresh16 >> 0x18)
    c2da_lin_memset(check + 21, 255, 320ul)
    return check
}
[export, sideeffects]
def R_CheckPlane(var pl_0 : int; var start : int; var stop_0 : int) : int {
    var intrl : int
    var intrh : int
    var unionl : int
    var unionh : int
    var x_1 : int
    if (start < int(uint(c2da_mem[pl_0 + 12]) | uint(c2da_mem[pl_0 + 13]) << 0x8 | uint(c2da_mem[pl_0 + 14]) << 0x10 | uint(c2da_mem[pl_0 + 15]) << 0x18)) {
        intrl = int(uint(c2da_mem[pl_0 + 12]) | uint(c2da_mem[pl_0 + 13]) << 0x8 | uint(c2da_mem[pl_0 + 14]) << 0x10 | uint(c2da_mem[pl_0 + 15]) << 0x18)
        unionl = start
    } else {
        unionl = int(uint(c2da_mem[pl_0 + 12]) | uint(c2da_mem[pl_0 + 13]) << 0x8 | uint(c2da_mem[pl_0 + 14]) << 0x10 | uint(c2da_mem[pl_0 + 15]) << 0x18)
        intrl = start
    }
    if (stop_0 > int(uint(c2da_mem[pl_0 + 16]) | uint(c2da_mem[pl_0 + 17]) << 0x8 | uint(c2da_mem[pl_0 + 18]) << 0x10 | uint(c2da_mem[pl_0 + 19]) << 0x18)) {
        intrh = int(uint(c2da_mem[pl_0 + 16]) | uint(c2da_mem[pl_0 + 17]) << 0x8 | uint(c2da_mem[pl_0 + 18]) << 0x10 | uint(c2da_mem[pl_0 + 19]) << 0x18)
        unionh = stop_0
    } else {
        unionh = int(uint(c2da_mem[pl_0 + 16]) | uint(c2da_mem[pl_0 + 17]) << 0x8 | uint(c2da_mem[pl_0 + 18]) << 0x10 | uint(c2da_mem[pl_0 + 19]) << 0x18)
        intrh = stop_0
    }
    x_1 = intrl
    while (x_1 <= intrh) {
        if (int(c2da_mem[pl_0 + 21 + x_1]) != 255) {
            break
        }
        x_1++
    }
    if (x_1 > intrh) {
        let c2da_fresh17 : uint = uint(unionl)
        c2da_mem[pl_0 + 12] = uint8(c2da_fresh17)
        c2da_mem[pl_0 + 13] = uint8(c2da_fresh17 >> 0x8)
        c2da_mem[pl_0 + 14] = uint8(c2da_fresh17 >> 0x10)
        c2da_mem[pl_0 + 15] = uint8(c2da_fresh17 >> 0x18)
        let c2da_fresh18 : uint = uint(unionh)
        c2da_mem[pl_0 + 16] = uint8(c2da_fresh18)
        c2da_mem[pl_0 + 17] = uint8(c2da_fresh18 >> 0x8)
        c2da_mem[pl_0 + 18] = uint8(c2da_fresh18 >> 0x10)
        c2da_mem[pl_0 + 19] = uint8(c2da_fresh18 >> 0x18)
        return pl_0
    }
    let c2da_fresh19 : int = int(uint(c2da_mem[pl_0]) | uint(c2da_mem[pl_0 + 1]) << 0x8 | uint(c2da_mem[pl_0 + 2]) << 0x10 | uint(c2da_mem[pl_0 + 3]) << 0x18)
    let c2da_fresh20 : uint = uint(c2da_fresh19)
    c2da_mem[lastvisplane] = uint8(c2da_fresh20)
    c2da_mem[lastvisplane + 1] = uint8(c2da_fresh20 >> 0x8)
    c2da_mem[lastvisplane + 2] = uint8(c2da_fresh20 >> 0x10)
    c2da_mem[lastvisplane + 3] = uint8(c2da_fresh20 >> 0x18)
    let c2da_fresh21 : int = int(uint(c2da_mem[pl_0 + 4]) | uint(c2da_mem[pl_0 + 5]) << 0x8 | uint(c2da_mem[pl_0 + 6]) << 0x10 | uint(c2da_mem[pl_0 + 7]) << 0x18)
    let c2da_fresh22 : uint = uint(c2da_fresh21)
    c2da_mem[lastvisplane + 4] = uint8(c2da_fresh22)
    c2da_mem[lastvisplane + 5] = uint8(c2da_fresh22 >> 0x8)
    c2da_mem[lastvisplane + 6] = uint8(c2da_fresh22 >> 0x10)
    c2da_mem[lastvisplane + 7] = uint8(c2da_fresh22 >> 0x18)
    let c2da_fresh23 : int = int(uint(c2da_mem[pl_0 + 8]) | uint(c2da_mem[pl_0 + 9]) << 0x8 | uint(c2da_mem[pl_0 + 10]) << 0x10 | uint(c2da_mem[pl_0 + 11]) << 0x18)
    let c2da_fresh24 : uint = uint(c2da_fresh23)
    c2da_mem[lastvisplane + 8] = uint8(c2da_fresh24)
    c2da_mem[lastvisplane + 9] = uint8(c2da_fresh24 >> 0x8)
    c2da_mem[lastvisplane + 10] = uint8(c2da_fresh24 >> 0x10)
    c2da_mem[lastvisplane + 11] = uint8(c2da_fresh24 >> 0x18)
    let c2da_fresh25 : int = lastvisplane
    lastvisplane += 664
    pl_0 = c2da_fresh25
    let c2da_fresh26 : uint = uint(start)
    c2da_mem[pl_0 + 12] = uint8(c2da_fresh26)
    c2da_mem[pl_0 + 13] = uint8(c2da_fresh26 >> 0x8)
    c2da_mem[pl_0 + 14] = uint8(c2da_fresh26 >> 0x10)
    c2da_mem[pl_0 + 15] = uint8(c2da_fresh26 >> 0x18)
    let c2da_fresh27 : uint = uint(stop_0)
    c2da_mem[pl_0 + 16] = uint8(c2da_fresh27)
    c2da_mem[pl_0 + 17] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[pl_0 + 18] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[pl_0 + 19] = uint8(c2da_fresh27 >> 0x18)
    c2da_lin_memset(pl_0 + 21, 255, 320ul)
    return pl_0
}
var ceilingfunc : planefunction_t = default<planefunction_t>

var spanstop : int[200]


// This unit's static data, at heap offset 362464.
let private c2da_lin_static_r_plane_seg = fixed_array<int>(362464, 165)
let private c2da_lin_static_r_plane = fixed_array<uint64>(0x616c5070614d5f52ul, 0x202c6925203a656eul, 0x6925207461206925ul, 0x50776172445f5200ul, 0x64203a73656e616cul, 0x2073676573776172ul, 0x776f6c667265766ful, 0x5f52002969252820ul, 0x6e616c5077617244ul, 0x70736976203a7365ul, 0x65766f20656e616cul, 0x252820776f6c6672ul, 0x6172445f52002969ul, 0x3a73656e616c5077ul, 0x676e696e65706f20ul, 0x6f6c667265766f20ul, 0x5200296925282077ul, 0x616c50646e69465ful, 0x6d206f6e203a656eul, 0x707369762065726ful, 0x73656e616cul)

[init]
def private c2da_lin_init_static_r_plane() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_r_plane_seg[s * 2]
        for (k in range(c2da_lin_static_r_plane_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_r_plane[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
