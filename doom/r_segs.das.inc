var private c2da_str_r_segs_0 : array<int8> = [int8(66), int8(97), int8(100), int8(32), int8(82), int8(95), int8(82), int8(101), int8(110), int8(100), int8(101), int8(114), int8(87), int8(97), int8(108), int8(108), int8(82), int8(97), int8(110), int8(103), int8(101), int8(58), int8(32), int8(37), int8(105), int8(32), int8(116), int8(111), int8(32), int8(37), int8(105), int8(0)]

[sideeffects]
def private c2da___bswap_16_14(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_14(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_14(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_14(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_14(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_14(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
var rw_distance : int = default<int>

var rw_normalangle : uint = default<uint>

var rw_angle1 : int = default<int>

var rw_x : int = default<int>

var rw_stopx : int = default<int>

var segtextured : uint = default<uint>

var markfloor : uint = default<uint>

var markceiling : uint = default<uint>

[export, sideeffects]
def R_RenderMaskedSegRange(var ds : drawseg_s?; var x1 : int; var x2 : int) {
    var index : uint
    var col : post_t?
    var lightnum : int
    var texnum : int
    curline = unsafe(reinterpret<seg_t?>(ds.curline))
    frontsector = unsafe(reinterpret<sector_t?>(curline.frontsector))
    backsector = unsafe(reinterpret<sector_t?>(curline.backsector))
    texnum = unsafe(texturetranslation[int(curline.sidedef.midtexture)])
    lightnum = (int(frontsector.lightlevel) >> 4) + extralight
    if (curline.v1.y == curline.v2.y) {
        lightnum--
    } elif (curline.v1.x == curline.v2.x) {
        lightnum++
    }
    if (lightnum < 0) {
        walllights = unsafe(addr<uint8??>(scalelight[0][0]))
    } elif (lightnum >= 16) {
        walllights = unsafe(addr<uint8??>(scalelight[16 - 1][0]))
    } else {
        walllights = unsafe(addr<uint8??>(scalelight[lightnum][0]))
    }
    maskedtexturecol = unsafe(reinterpret<int16?>(ds.maskedtexturecol))
    rw_scalestep = int(ds.scalestep)  // nolint:PERF020
    spryscale = ds.scale1 + (x1 - ds.x1) * rw_scalestep
    mfloorclip = unsafe(reinterpret<int16?>(ds.sprbottomclip))
    mceilingclip = unsafe(reinterpret<int16?>(ds.sprtopclip))
    if ((int(curline.linedef.flags) & 16) != 0) {
        dc_texturemid = frontsector.floorheight > backsector.floorheight ? frontsector.floorheight : backsector.floorheight
        dc_texturemid = dc_texturemid + unsafe(textureheight[texnum]) - viewz
    } else {
        dc_texturemid = frontsector.ceilingheight < backsector.ceilingheight ? frontsector.ceilingheight : backsector.ceilingheight
        dc_texturemid = dc_texturemid - viewz
    }
    dc_texturemid = dc_texturemid + curline.sidedef.rowoffset
    if (fixedcolormap != null) {
        dc_colormap = unsafe(reinterpret<uint8?>(fixedcolormap))
    }
    dc_x = x1
    while (dc_x <= x2) {
        if (int(unsafe(maskedtexturecol[int(dc_x)])) != 32767) {
            if (fixedcolormap == null) {
                index = uint(spryscale >> 12)
                if (index >= 48u) {
                    index = uint(48 - 1)
                }
                dc_colormap = unsafe(reinterpret<uint8?>(unsafe(walllights[int(index)])))
            }
            sprtopscreen = centeryfrac - FixedMul(dc_texturemid, spryscale)
            dc_iscale = int(0xffffffffu / uint(spryscale))
            col = unsafe(reinterpret<post_t?>(unsafe(reinterpret<post_t?>(unsafe(unsafe(reinterpret<uint8?>(R_GetColumn(texnum, int(unsafe(maskedtexturecol[int(dc_x)]))))) + -3)))))
            R_DrawMaskedColumn(col)
            unsafe(maskedtexturecol[int(dc_x)]) = int16(32767)
        }
        spryscale = spryscale + rw_scalestep
        dc_x = dc_x + 1
    }
    return
}
var rw_scalestep : int = default<int>

var maskedtexturecol : int16? = default<int16?>

var walllights : uint8?? = default<uint8??>

var maskedtexture : uint = default<uint>

var toptexture : int = default<int>

var bottomtexture : int = default<int>

var midtexture : int = default<int>

var rw_centerangle : uint = default<uint>

var rw_offset : int = default<int>

var rw_scale : int = default<int>

var rw_midtexturemid : int = default<int>

var rw_toptexturemid : int = default<int>

var rw_bottomtexturemid : int = default<int>

var worldtop : int = default<int>

var worldbottom : int = default<int>

var worldhigh : int = default<int>

var worldlow : int = default<int>

var pixhigh : int = default<int>

var pixlow : int = default<int>

var pixhighstep : int = default<int>

var pixlowstep : int = default<int>

var topfrac : int = default<int>

var topstep : int = default<int>

var bottomfrac : int = default<int>

var bottomstep : int = default<int>

[export, sideeffects]
def R_RenderSegLoop() {
    var angle : uint
    var index_0 : uint
    var yl : int
    var yh : int
    var mid : int
    var texturecolumn : int
    var top : int
    var bottom : int
    while (rw_x < rw_stopx) {
        yl = topfrac + (1 << 12) - 1 >> 12
        if (yl < int(ceilingclip[rw_x]) + 1) {
            yl = int(ceilingclip[rw_x]) + 1
        }
        if (markceiling != 0x0) {
            top = int(ceilingclip[rw_x]) + 1
            bottom = yl - 1
            if (bottom >= int(floorclip[rw_x])) {
                bottom = int(floorclip[rw_x]) - 1
            }
            if (top <= bottom) {
                var c2da_fresh0 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(ceilingplane)) + 21ul))
                unsafe(unsafe(reinterpret<uint8?>(c2da_fresh0))[rw_x]) = uint8(top)
                var c2da_fresh1 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(ceilingplane)) + 343ul))
                unsafe(unsafe(reinterpret<uint8?>(c2da_fresh1))[rw_x]) = uint8(bottom)
            }
        }
        yh = bottomfrac >> 12
        if (yh >= int(floorclip[rw_x])) {
            yh = int(floorclip[rw_x]) - 1
        }
        if (markfloor != 0x0) {
            top = yh + 1
            bottom = int(floorclip[rw_x]) - 1
            if (top <= int(ceilingclip[rw_x])) {
                top = int(ceilingclip[rw_x]) + 1
            }
            if (top <= bottom) {
                var c2da_fresh2 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(floorplane)) + 21ul))
                unsafe(unsafe(reinterpret<uint8?>(c2da_fresh2))[rw_x]) = uint8(top)
                var c2da_fresh3 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(floorplane)) + 343ul))
                unsafe(unsafe(reinterpret<uint8?>(c2da_fresh3))[rw_x]) = uint8(bottom)
            }
        }
        if (segtextured != 0x0) {
            angle = uint(rw_centerangle + xtoviewangle[rw_x] >> 19u)
            texturecolumn = rw_offset - FixedMul(finetangent[int(angle)], rw_distance)
            texturecolumn >>= 16
            index_0 = uint(rw_scale >> 12)
            if (index_0 >= 48u) {
                index_0 = uint(48 - 1)
            }
            dc_colormap = unsafe(reinterpret<uint8?>(unsafe(walllights[int(index_0)])))
            dc_x = rw_x
            dc_iscale = int(0xffffffffu / uint(rw_scale))
        } else {
            texturecolumn = 0
        }
        if (midtexture != 0) {
            dc_yl = yl
            dc_yh = yh
            dc_texturemid = rw_midtexturemid
            dc_source = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(R_GetColumn(midtexture, texturecolumn)))))
            invoke(colfunc)
            ceilingclip[rw_x] = int16(viewheight)
            floorclip[rw_x] = int16(-1)
        } else {
            if (toptexture != 0) {
                mid = pixhigh >> 12
                pixhigh += pixhighstep
                if (mid >= int(floorclip[rw_x])) {
                    mid = int(floorclip[rw_x]) - 1
                }
                if (mid >= yl) {
                    dc_yl = yl
                    dc_yh = mid
                    dc_texturemid = rw_toptexturemid
                    dc_source = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(R_GetColumn(toptexture, texturecolumn)))))
                    invoke(colfunc)
                    ceilingclip[rw_x] = int16(mid)
                } else {
                    ceilingclip[rw_x] = int16(yl - 1)
                }
            } elif (markceiling != 0x0) {
                ceilingclip[rw_x] = int16(yl - 1)
            }
            if (bottomtexture != 0) {
                mid = pixlow + (1 << 12) - 1 >> 12
                pixlow += pixlowstep
                if (mid <= int(ceilingclip[rw_x])) {
                    mid = int(ceilingclip[rw_x]) + 1
                }
                if (mid <= yh) {
                    dc_yl = mid
                    dc_yh = yh
                    dc_texturemid = rw_bottomtexturemid
                    dc_source = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(R_GetColumn(bottomtexture, texturecolumn)))))
                    invoke(colfunc)
                    floorclip[rw_x] = int16(mid)
                } else {
                    floorclip[rw_x] = int16(yh + 1)
                }
            } elif (markfloor != 0x0) {
                floorclip[rw_x] = int16(yh + 1)
            }
            if (maskedtexture != 0x0) {
                unsafe(maskedtexturecol[rw_x]) = int16(texturecolumn)
            }
        }
        rw_scale += rw_scalestep
        topfrac += topstep
        bottomfrac += bottomstep
        rw_x++
    }
    return
}
[export, sideeffects]
def R_StoreWallRange(var start : int; var stop : int) {
    var hyp : int
    var sineval : int
    var offsetangle : uint
    var lightnum_0 : int
    if (ds_p == unsafe(addr(unsafe(unsafe(addr(drawsegs[0]))[256])))) {
        return
    }
    if (start >= viewwidth || start > stop) {
        I_Error(unsafe(addr<int8?>(c2da_str_r_segs_0[0])), [C2daVaArg(tag = 1, i64 = int64(start), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(stop), f64 = 0.0lf, raw = 0x0)])
    }
    sidedef = unsafe(reinterpret<side_t?>(curline.sidedef))
    linedef = unsafe(reinterpret<line_s?>(curline.linedef))
    linedef.flags = int16(int(linedef.flags) | 256)
    rw_normalangle = uint(curline.angle + 0x40000000u)
    offsetangle = uint(c2da_std_abs(int(rw_normalangle - uint(rw_angle1))))
    if (offsetangle > 0x40000000u) {
        offsetangle = 0x40000000u
    }
    hyp = R_PointToDist(curline.v1.x, curline.v1.y)
    sineval = finesine[int(0x40000000u - offsetangle >> 19u)]
    rw_distance = FixedMul(hyp, sineval)
    rw_x = int(start)  // nolint:PERF020
    ds_p.x1 = rw_x
    ds_p.x2 = stop
    ds_p.curline = curline
    rw_stopx = stop + 1
    rw_scale = R_ScaleFromGlobalAngle(viewangle + xtoviewangle[start])
    ds_p.scale1 = rw_scale
    if (stop > start) {
        ds_p.scale2 = R_ScaleFromGlobalAngle(viewangle + xtoviewangle[stop])
        rw_scalestep = (ds_p.scale2 - rw_scale) / (stop - start)
        ds_p.scalestep = rw_scalestep
    } else {
        ds_p.scale2 = ds_p.scale1
    }
    worldtop = frontsector.ceilingheight - viewz
    worldbottom = frontsector.floorheight - viewz
    maskedtexture = 0u
    bottomtexture = int(maskedtexture)
    toptexture = int(bottomtexture)  // nolint:PERF020
    midtexture = int(toptexture)  // nolint:PERF020
    ds_p.maskedtexturecol = null
    if (backsector == null) {
        midtexture = unsafe(texturetranslation[int(sidedef.midtexture)])
        markceiling = 1u
        markfloor = uint(markceiling)  // nolint:PERF020
        if ((int(linedef.flags) & 16) != 0) {
            rw_midtexturemid = frontsector.floorheight + unsafe(textureheight[int(sidedef.midtexture)]) - viewz
        } else {
            rw_midtexturemid = int(worldtop)  // nolint:PERF020
        }
        rw_midtexturemid = rw_midtexturemid + sidedef.rowoffset
        ds_p.silhouette = 3
        ds_p.sprtopclip = unsafe(addr(screenheightarray[0]))
        ds_p.sprbottomclip = unsafe(addr(negonearray[0]))
        ds_p.bsilheight = 2147483647
        ds_p.tsilheight = -2147483647 - 1
    } else {
        var c2da_fresh4 : int16? = null
        ds_p.sprbottomclip = c2da_fresh4
        ds_p.sprtopclip = c2da_fresh4
        ds_p.silhouette = 0
        if (frontsector.floorheight > backsector.floorheight) {
            ds_p.silhouette = 1
            ds_p.bsilheight = frontsector.floorheight
        } elif (backsector.floorheight > viewz) {
            ds_p.silhouette = 1
            ds_p.bsilheight = 2147483647
        }
        if (frontsector.ceilingheight < backsector.ceilingheight) {
            ds_p.silhouette = ds_p.silhouette | 2
            ds_p.tsilheight = frontsector.ceilingheight
        } elif (backsector.ceilingheight < viewz) {
            ds_p.silhouette = ds_p.silhouette | 2
            ds_p.tsilheight = -2147483647 - 1
        }
        if (backsector.ceilingheight <= frontsector.floorheight) {
            ds_p.sprbottomclip = unsafe(addr(negonearray[0]))
            ds_p.bsilheight = 2147483647
            ds_p.silhouette = ds_p.silhouette | 1
        }
        if (backsector.floorheight >= frontsector.ceilingheight) {
            ds_p.sprtopclip = unsafe(addr(screenheightarray[0]))
            ds_p.tsilheight = -2147483647 - 1
            ds_p.silhouette = ds_p.silhouette | 2
        }
        worldhigh = backsector.ceilingheight - viewz
        worldlow = backsector.floorheight - viewz
        if (int(frontsector.ceilingpic) == skyflatnum && int(backsector.ceilingpic) == skyflatnum) {
            worldtop = int(worldhigh)  // nolint:PERF020
        }
        if (worldlow != worldbottom || int(backsector.floorpic) != int(frontsector.floorpic) || int(backsector.lightlevel) != int(frontsector.lightlevel)) {
            markfloor = 1u
        } else {
            markfloor = 0u
        }
        if (worldhigh != worldtop || int(backsector.ceilingpic) != int(frontsector.ceilingpic) || int(backsector.lightlevel) != int(frontsector.lightlevel)) {
            markceiling = 1u
        } else {
            markceiling = 0u
        }
        if (backsector.ceilingheight <= frontsector.floorheight || backsector.floorheight >= frontsector.ceilingheight) {
            markfloor = 1u
            markceiling = uint(markfloor)  // nolint:PERF020
        }
        if (worldhigh < worldtop) {
            toptexture = unsafe(texturetranslation[int(sidedef.toptexture)])
            if ((int(linedef.flags) & 8) != 0) {
                rw_toptexturemid = int(worldtop)  // nolint:PERF020
            } else {
                rw_toptexturemid = backsector.ceilingheight + unsafe(textureheight[int(sidedef.toptexture)]) - viewz
            }
        }
        if (worldlow > worldbottom) {
            bottomtexture = unsafe(texturetranslation[int(sidedef.bottomtexture)])
            if ((int(linedef.flags) & 16) != 0) {
                rw_bottomtexturemid = int(worldtop)  // nolint:PERF020
            } else {
                rw_bottomtexturemid = int(worldlow)  // nolint:PERF020
            }
        }
        rw_toptexturemid = rw_toptexturemid + sidedef.rowoffset
        rw_bottomtexturemid = rw_bottomtexturemid + sidedef.rowoffset
        if (sidedef.midtexture != 0) {
            maskedtexture = 1u
            maskedtexturecol = unsafe(reinterpret<int16?>(unsafe(lastopening + -rw_x)))
            ds_p.maskedtexturecol = maskedtexturecol
            lastopening = unsafe(lastopening + int64(rw_stopx - rw_x))
        }
    }
    segtextured = uint(midtexture | toptexture | bottomtexture) | maskedtexture
    if (segtextured != 0x0) {
        offsetangle = rw_normalangle - uint(rw_angle1)
        if (offsetangle > 0x80000000u) {
            offsetangle = -offsetangle
        }
        if (offsetangle > 0x40000000u) {
            offsetangle = 0x40000000u
        }
        sineval = finesine[int(offsetangle >> 19u)]
        rw_offset = FixedMul(hyp, sineval)
        if (rw_normalangle - uint(rw_angle1) < 0x80000000u) {
            rw_offset = -rw_offset
        }
        rw_offset = rw_offset + (sidedef.textureoffset + curline.offset)
        rw_centerangle = uint(0x40000000u + viewangle - rw_normalangle)
        if (fixedcolormap == null) {
            lightnum_0 = (int(frontsector.lightlevel) >> 4) + extralight
            if (curline.v1.y == curline.v2.y) {
                lightnum_0--
            } elif (curline.v1.x == curline.v2.x) {
                lightnum_0++
            }
            if (lightnum_0 < 0) {
                walllights = unsafe(addr<uint8??>(scalelight[0][0]))
            } elif (lightnum_0 >= 16) {
                walllights = unsafe(addr<uint8??>(scalelight[16 - 1][0]))
            } else {
                walllights = unsafe(addr<uint8??>(scalelight[lightnum_0][0]))
            }
        }
    }
    if (frontsector.floorheight >= viewz) {
        markfloor = 0u
    }
    if (frontsector.ceilingheight <= viewz && int(frontsector.ceilingpic) != skyflatnum) {
        markceiling = 0u
    }
    worldtop >>= 4
    worldbottom >>= 4
    topstep = -FixedMul(rw_scalestep, worldtop)
    topfrac = (centeryfrac >> 4) - FixedMul(worldtop, rw_scale)
    bottomstep = -FixedMul(rw_scalestep, worldbottom)
    bottomfrac = (centeryfrac >> 4) - FixedMul(worldbottom, rw_scale)
    if (backsector != null) {
        worldhigh >>= 4
        worldlow >>= 4
        if (worldhigh < worldtop) {
            pixhigh = (centeryfrac >> 4) - FixedMul(worldhigh, rw_scale)
            pixhighstep = -FixedMul(rw_scalestep, worldhigh)
        }
        if (worldlow > worldbottom) {
            pixlow = (centeryfrac >> 4) - FixedMul(worldlow, rw_scale)
            pixlowstep = -FixedMul(rw_scalestep, worldlow)
        }
    }
    if (markceiling != 0x0) {
        ceilingplane = unsafe(reinterpret<visplane_t?>(unsafe(reinterpret<visplane_t?>(R_CheckPlane(ceilingplane, rw_x, rw_stopx - 1)))))
    }
    if (markfloor != 0x0) {
        floorplane = unsafe(reinterpret<visplane_t?>(unsafe(reinterpret<visplane_t?>(R_CheckPlane(floorplane, rw_x, rw_stopx - 1)))))
    }
    R_RenderSegLoop()
    if (((ds_p.silhouette & 2) != 0 || maskedtexture != 0x0) && ds_p.sprtopclip == null) {
        var c2da_fresh5 : uint8? = unsafe(reinterpret<uint8?>(unsafe(unsafe(addr(ceilingclip[0])) + start)))
        let c2da_fresh6 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(lastopening))))
        let c2da_fresh7 : uint64 = unsafe(reinterpret<uint64>(c2da_fresh5))
        let c2da_fresh8 : uint64 = uint64(2 * (rw_stopx - start))
        if (c2da_fresh8 != 0x0) {
            unsafe(memcpy(unsafe(reinterpret<void?>(c2da_fresh6)), unsafe(reinterpret<void?>(c2da_fresh7)), c2da_fresh8))
        }
        ds_p.sprtopclip = unsafe(lastopening + -start)
        lastopening = unsafe(lastopening + int64(rw_stopx - start))
    }
    if (((ds_p.silhouette & 1) != 0 || maskedtexture != 0x0) && ds_p.sprbottomclip == null) {
        var c2da_fresh9 : uint8? = unsafe(reinterpret<uint8?>(unsafe(unsafe(addr(floorclip[0])) + start)))
        let c2da_fresh10 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(lastopening))))
        let c2da_fresh11 : uint64 = unsafe(reinterpret<uint64>(c2da_fresh9))
        let c2da_fresh12 : uint64 = uint64(2 * (rw_stopx - start))
        if (c2da_fresh12 != 0x0) {
            unsafe(memcpy(unsafe(reinterpret<void?>(c2da_fresh10)), unsafe(reinterpret<void?>(c2da_fresh11)), c2da_fresh12))
        }
        ds_p.sprbottomclip = unsafe(lastopening + -start)
        lastopening = unsafe(lastopening + int64(rw_stopx - start))
    }
    if (maskedtexture != 0x0 && (ds_p.silhouette & 2) == 0) {
        ds_p.silhouette = ds_p.silhouette | 2
        ds_p.tsilheight = -2147483647 - 1
    }
    if (maskedtexture != 0x0 && (ds_p.silhouette & 1) == 0) {
        ds_p.silhouette = ds_p.silhouette | 1
        ds_p.bsilheight = 2147483647
    }
    ds_p = unsafe(ds_p + 1)
    return
}
[sideeffects]
def private c2da_layout_proofs_33() {
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
