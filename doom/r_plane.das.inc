var private c2da_str_r_plane_0 : array<int8> = [int8(82), int8(95), int8(77), int8(97), int8(112), int8(80), int8(108), int8(97), int8(110), int8(101), int8(58), int8(32), int8(37), int8(105), int8(44), int8(32), int8(37), int8(105), int8(32), int8(97), int8(116), int8(32), int8(37), int8(105), int8(0)]

var private c2da_str_r_plane_1 : array<int8> = [int8(82), int8(95), int8(68), int8(114), int8(97), int8(119), int8(80), int8(108), int8(97), int8(110), int8(101), int8(115), int8(58), int8(32), int8(100), int8(114), int8(97), int8(119), int8(115), int8(101), int8(103), int8(115), int8(32), int8(111), int8(118), int8(101), int8(114), int8(102), int8(108), int8(111), int8(119), int8(32), int8(40), int8(37), int8(105), int8(41), int8(0)]

var private c2da_str_r_plane_2 : array<int8> = [int8(82), int8(95), int8(68), int8(114), int8(97), int8(119), int8(80), int8(108), int8(97), int8(110), int8(101), int8(115), int8(58), int8(32), int8(118), int8(105), int8(115), int8(112), int8(108), int8(97), int8(110), int8(101), int8(32), int8(111), int8(118), int8(101), int8(114), int8(102), int8(108), int8(111), int8(119), int8(32), int8(40), int8(37), int8(105), int8(41), int8(0)]

var private c2da_str_r_plane_3 : array<int8> = [int8(82), int8(95), int8(68), int8(114), int8(97), int8(119), int8(80), int8(108), int8(97), int8(110), int8(101), int8(115), int8(58), int8(32), int8(111), int8(112), int8(101), int8(110), int8(105), int8(110), int8(103), int8(32), int8(111), int8(118), int8(101), int8(114), int8(102), int8(108), int8(111), int8(119), int8(32), int8(40), int8(37), int8(105), int8(41), int8(0)]

var private c2da_str_r_plane_4 : array<int8> = [int8(82), int8(95), int8(70), int8(105), int8(110), int8(100), int8(80), int8(108), int8(97), int8(110), int8(101), int8(58), int8(32), int8(110), int8(111), int8(32), int8(109), int8(111), int8(114), int8(101), int8(32), int8(118), int8(105), int8(115), int8(112), int8(108), int8(97), int8(110), int8(101), int8(115), int8(0)]

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
var floorplane : visplane_t? = default<visplane_t?>

var ceilingplane : visplane_t? = default<visplane_t?>

var lastopening : int16? = default<int16?>

var floorfunc : planefunction_t = default<planefunction_t>

var floorclip : int16[320]

var ceilingclip : int16[320]

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
        floorclip[i] = int16(viewheight)
        ceilingclip[i] = int16(-1)
        i++
    }
    lastvisplane = unsafe(addr<visplane_t?>(visplanes[0]))
    lastopening = unsafe(addr<int16?>(openings[0]))
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(addr<uint8?>(cachedheight[0])))), 0u8, 800ul)))
    angle = uint(viewangle - 0x40000000u >> 19u)
    basexscale = FixedDiv(unsafe(finecosine[int(angle)]), centerxfrac)
    baseyscale = -FixedDiv(finesine[int(angle)], centerxfrac)
    return
}
var baseyscale : int = default<int>

var basexscale : int = default<int>

var cachedheight : int[200]

var openings : int16[20480]

var visplanes : visplane_t[128]

var lastvisplane : visplane_t? = default<visplane_t?>

[export, sideeffects]
def R_MapPlane(var y : int; var x1 : int; var x2 : int) {
    var angle_0 : uint
    var distance : int
    var length_0 : int
    var index : uint
    if (x2 < x1 || x1 < 0 || x2 >= viewwidth || y > viewheight) {
        I_Error(unsafe(addr<int8?>(c2da_str_r_plane_0[0])), [C2daVaArg(tag = 1, i64 = int64(x1), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(x2), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(y), f64 = 0.0lf, raw = 0x0)])
    }
    if (planeheight != cachedheight[y]) {
        cachedheight[y] = int(planeheight)  // nolint:PERF020
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
    ds_xfrac = viewx + FixedMul(unsafe(finecosine[int(angle_0)]), length_0)
    ds_yfrac = -viewy - FixedMul(finesine[int(angle_0)], length_0)
    if (fixedcolormap != null) {
        ds_colormap = unsafe(reinterpret<uint8?>(fixedcolormap))
    } else {
        index = uint(distance >> 20)
        if (index >= 128u) {
            index = uint(128 - 1)
        }
        ds_colormap = unsafe(reinterpret<uint8?>(unsafe(planezlight[int(index)])))
    }
    ds_y = y
    ds_x1 = x1
    ds_x2 = x2
    invoke(spanfunc)
    return
}
var planezlight : uint8?? = default<uint8??>

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
    var pl : visplane_t?
    var light : int
    var x_0 : int
    var stop : int
    var angle_1 : int
    var lumpnum : int
    if (unsafe(ds_p - unsafe(addr(drawsegs[0]))) > 256l) {
        I_Error(unsafe(addr<int8?>(c2da_str_r_plane_1[0])), [C2daVaArg(tag = 1, i64 = unsafe(ds_p - unsafe(addr(drawsegs[0]))), f64 = 0.0lf, raw = 0x0)])
    }
    if (unsafe(lastvisplane - unsafe(addr(visplanes[0]))) > 128l) {
        I_Error(unsafe(addr<int8?>(c2da_str_r_plane_2[0])), [C2daVaArg(tag = 1, i64 = unsafe(lastvisplane - unsafe(addr(visplanes[0]))), f64 = 0.0lf, raw = 0x0)])
    }
    if (unsafe(lastopening - unsafe(addr(openings[0]))) > int64(320 * 64)) {
        I_Error(unsafe(addr<int8?>(c2da_str_r_plane_3[0])), [C2daVaArg(tag = 1, i64 = unsafe(lastopening - unsafe(addr(openings[0]))), f64 = 0.0lf, raw = 0x0)])
    }
    pl = unsafe(addr<visplane_t?>(visplanes[0]))
    while (unsafe(reinterpret<uint64>(pl)) < unsafe(reinterpret<uint64>(lastvisplane))) {
        if (pl.minx > pl.maxx) {
            unsafe {  // nolint:STYLE025
                pl += 1
            }
            continue
        }
        if (pl.picnum == skyflatnum) {
            dc_iscale = pspriteiscale >> detailshift
            dc_colormap = unsafe(reinterpret<uint8?>(colormaps))
            dc_texturemid = skytexturemid
            x_0 = pl.minx
            while (x_0 <= pl.maxx) {
                var c2da_fresh0 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pl)) + 21ul))
                dc_yl = int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh0))[x_0]))
                var c2da_fresh1 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pl)) + 343ul))
                dc_yh = int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh1))[x_0]))
                if (dc_yl <= dc_yh) {
                    angle_1 = int(viewangle + xtoviewangle[x_0] >> 22u)
                    dc_x = x_0
                    dc_source = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(R_GetColumn(skytexture, angle_1)))))
                    invoke(colfunc)
                }
                x_0++
            }
            unsafe {  // nolint:STYLE025
                pl += 1
            }
            continue
        }
        lumpnum = firstflat + unsafe(flattranslation[pl.picnum])
        ds_source = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(W_CacheLumpNum(lumpnum, 1)))))
        planeheight = c2da_std_abs(pl.height - viewz)
        light = (pl.lightlevel >> 4) + extralight
        if (light >= 16) {
            light = 16 - 1
        }
        if (light < 0) {
            light = 0
        }
        planezlight = unsafe(addr<uint8??>(zlight[light][0]))
        var c2da_fresh2 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pl)) + 21ul))
        unsafe(unsafe(reinterpret<uint8?>(c2da_fresh2))[pl.maxx + 1]) = 0xffu8
        var c2da_fresh3 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pl)) + 21ul))
        unsafe(unsafe(reinterpret<uint8?>(c2da_fresh3))[pl.minx - 1]) = 0xffu8
        stop = pl.maxx + 1
        x_0 = pl.minx
        while (x_0 <= stop) {
            var c2da_fresh4 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pl)) + 21ul))
            var c2da_fresh5 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pl)) + 343ul))
            var c2da_fresh6 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pl)) + 21ul))
            var c2da_fresh7 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pl)) + 343ul))
            R_MakeSpans(x_0, int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh4))[x_0 - 1])), int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh5))[x_0 - 1])), int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh6))[x_0])), int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh7))[x_0])))
            x_0++
        }
        W_ReleaseLumpNum(lumpnum)
        unsafe {  // nolint:STYLE025
            pl += 1
        }
    }
    return
}
[export, sideeffects]
def R_FindPlane(var height : int; var picnum : int; var lightlevel : int) : visplane_t? {
    var check : visplane_t?
    if (picnum == skyflatnum) {
        height = 0
        lightlevel = 0
    }
    check = unsafe(addr<visplane_t?>(visplanes[0]))
    while (unsafe(reinterpret<uint64>(check)) < unsafe(reinterpret<uint64>(lastvisplane))) {
        if (height == check.height && picnum == check.picnum && lightlevel == check.lightlevel) {
            break
        }
        unsafe {  // nolint:STYLE025
            check += 1
        }
    }
    if (unsafe(reinterpret<uint64>(check)) < unsafe(reinterpret<uint64>(lastvisplane))) {
        return unsafe(reinterpret<visplane_t?>(check))
    }
    if (unsafe(lastvisplane - unsafe(addr(visplanes[0]))) == 128l) {
        I_Error(unsafe(addr<int8?>(c2da_str_r_plane_4[0])), [])
    }
    unsafe {  // nolint:STYLE025
        lastvisplane += 1
    }
    check.height = int(height)  // nolint:PERF020
    check.picnum = int(picnum)  // nolint:PERF020
    check.lightlevel = int(lightlevel)  // nolint:PERF020
    check.minx = 320
    check.maxx = -1
    var c2da_fresh8 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(check)) + 21ul))
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(c2da_fresh8)))), 0xffu8, 320ul)))
    return unsafe(reinterpret<visplane_t?>(check))
}
[export, sideeffects]
def R_CheckPlane(var pl_0 : visplane_t?; var start : int; var stop_0 : int) : visplane_t? {
    var intrl : int
    var intrh : int
    var unionl : int
    var unionh : int
    var x_1 : int
    if (start < pl_0.minx) {
        intrl = pl_0.minx
        unionl = start
    } else {
        unionl = pl_0.minx
        intrl = start
    }
    if (stop_0 > pl_0.maxx) {
        intrh = pl_0.maxx
        unionh = stop_0
    } else {
        unionh = pl_0.maxx
        intrh = stop_0
    }
    x_1 = intrl
    while (x_1 <= intrh) {
        var c2da_fresh9 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pl_0)) + 21ul))
        if (int(unsafe(unsafe(reinterpret<uint8?>(c2da_fresh9))[x_1])) != 255) {
            break
        }
        x_1++
    }
    if (x_1 > intrh) {
        pl_0.minx = unionl
        pl_0.maxx = unionh
        return unsafe(reinterpret<visplane_t?>(pl_0))
    }
    lastvisplane.height = int(pl_0.height)  // nolint:PERF020
    lastvisplane.picnum = int(pl_0.picnum)  // nolint:PERF020
    lastvisplane.lightlevel = int(pl_0.lightlevel)  // nolint:PERF020
    var c2da_postinc : visplane_t? = lastvisplane
    unsafe {  // nolint:STYLE025
        lastvisplane += 1
    }
    pl_0 = unsafe(reinterpret<visplane_t?>(c2da_postinc))
    pl_0.minx = int(start)  // nolint:PERF020
    pl_0.maxx = int(stop_0)  // nolint:PERF020
    var c2da_fresh10 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(pl_0)) + 21ul))
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(c2da_fresh10)))), 0xffu8, 320ul)))
    return unsafe(reinterpret<visplane_t?>(pl_0))
}
var ceilingfunc : planefunction_t = default<planefunction_t>

var spanstop : int[200]

[sideeffects]
def private c2da_layout_proofs_32() {
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
}
