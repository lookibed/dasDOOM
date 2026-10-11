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
def R_RenderMaskedSegRange(var ds : int; var x1 : int; var x2 : int) {
    var index : uint
    var col : int
    var lightnum : int
    var texnum : int
    curline = int(uint(c2da_mem[ds]) | uint(c2da_mem[ds + 1]) << 0x8 | uint(c2da_mem[ds + 2]) << 0x10 | uint(c2da_mem[ds + 3]) << 0x18)
    frontsector = int(uint(c2da_mem[curline + 40]) | uint(c2da_mem[curline + 41]) << 0x8 | uint(c2da_mem[curline + 42]) << 0x10 | uint(c2da_mem[curline + 43]) << 0x18)
    backsector = int(uint(c2da_mem[curline + 48]) | uint(c2da_mem[curline + 49]) << 0x8 | uint(c2da_mem[curline + 50]) << 0x10 | uint(c2da_mem[curline + 51]) << 0x18)
    let c2da_fresh0 : int = int(uint(c2da_mem[curline + 24]) | uint(c2da_mem[curline + 25]) << 0x8 | uint(c2da_mem[curline + 26]) << 0x10 | uint(c2da_mem[curline + 27]) << 0x18) + 12
    let c2da_fresh1 : int = texturetranslation + int(int16(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8)) * 4
    texnum = int(uint(c2da_mem[c2da_fresh1]) | uint(c2da_mem[c2da_fresh1 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh1 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh1 + 3]) << 0x18)
    lightnum = (int(int16(uint(c2da_mem[frontsector + 12]) | uint(c2da_mem[frontsector + 13]) << 0x8)) >> 4) + extralight
    let c2da_fresh2 : int = int(uint(c2da_mem[curline]) | uint(c2da_mem[curline + 1]) << 0x8 | uint(c2da_mem[curline + 2]) << 0x10 | uint(c2da_mem[curline + 3]) << 0x18) + 4
    let c2da_fresh3 : int = int(uint(c2da_mem[curline + 8]) | uint(c2da_mem[curline + 9]) << 0x8 | uint(c2da_mem[curline + 10]) << 0x10 | uint(c2da_mem[curline + 11]) << 0x18) + 4
    if (int(uint(c2da_mem[c2da_fresh2]) | uint(c2da_mem[c2da_fresh2 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh2 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh2 + 3]) << 0x18) == int(uint(c2da_mem[c2da_fresh3]) | uint(c2da_mem[c2da_fresh3 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh3 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh3 + 3]) << 0x18)) {
        lightnum--
    } else {
        let c2da_fresh4 : int = int(uint(c2da_mem[curline]) | uint(c2da_mem[curline + 1]) << 0x8 | uint(c2da_mem[curline + 2]) << 0x10 | uint(c2da_mem[curline + 3]) << 0x18)
        let c2da_fresh5 : int = int(uint(c2da_mem[curline + 8]) | uint(c2da_mem[curline + 9]) << 0x8 | uint(c2da_mem[curline + 10]) << 0x10 | uint(c2da_mem[curline + 11]) << 0x18)
        if (int(uint(c2da_mem[c2da_fresh4]) | uint(c2da_mem[c2da_fresh4 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh4 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh4 + 3]) << 0x18) == int(uint(c2da_mem[c2da_fresh5]) | uint(c2da_mem[c2da_fresh5 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh5 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh5 + 3]) << 0x18)) {
            lightnum++
        }
    }
    if (lightnum < 0) {
        walllights = 227616 + 0 * 384
    } elif (lightnum >= 16) {
        walllights = 227616 + (16 - 1) * 384
    } else {
        walllights = 227616 + lightnum * 384
    }
    maskedtexturecol = int(uint(c2da_mem[ds + 56]) | uint(c2da_mem[ds + 57]) << 0x8 | uint(c2da_mem[ds + 58]) << 0x10 | uint(c2da_mem[ds + 59]) << 0x18)
    rw_scalestep = int(uint(c2da_mem[ds + 24]) | uint(c2da_mem[ds + 25]) << 0x8 | uint(c2da_mem[ds + 26]) << 0x10 | uint(c2da_mem[ds + 27]) << 0x18)
    spryscale = int(uint(c2da_mem[ds + 16]) | uint(c2da_mem[ds + 17]) << 0x8 | uint(c2da_mem[ds + 18]) << 0x10 | uint(c2da_mem[ds + 19]) << 0x18) + (x1 - int(uint(c2da_mem[ds + 8]) | uint(c2da_mem[ds + 9]) << 0x8 | uint(c2da_mem[ds + 10]) << 0x10 | uint(c2da_mem[ds + 11]) << 0x18)) * rw_scalestep
    mfloorclip = int(uint(c2da_mem[ds + 48]) | uint(c2da_mem[ds + 49]) << 0x8 | uint(c2da_mem[ds + 50]) << 0x10 | uint(c2da_mem[ds + 51]) << 0x18)
    mceilingclip = int(uint(c2da_mem[ds + 40]) | uint(c2da_mem[ds + 41]) << 0x8 | uint(c2da_mem[ds + 42]) << 0x10 | uint(c2da_mem[ds + 43]) << 0x18)
    let c2da_fresh6 : int = int(uint(c2da_mem[curline + 32]) | uint(c2da_mem[curline + 33]) << 0x8 | uint(c2da_mem[curline + 34]) << 0x10 | uint(c2da_mem[curline + 35]) << 0x18) + 24
    if ((int(int16(uint(c2da_mem[c2da_fresh6]) | uint(c2da_mem[c2da_fresh6 + 1]) << 0x8)) & 16) != 0) {
        dc_texturemid = int(int(uint(c2da_mem[frontsector]) | uint(c2da_mem[frontsector + 1]) << 0x8 | uint(c2da_mem[frontsector + 2]) << 0x10 | uint(c2da_mem[frontsector + 3]) << 0x18) > int(uint(c2da_mem[backsector]) | uint(c2da_mem[backsector + 1]) << 0x8 | uint(c2da_mem[backsector + 2]) << 0x10 | uint(c2da_mem[backsector + 3]) << 0x18) ? uint(c2da_mem[frontsector]) | uint(c2da_mem[frontsector + 1]) << 0x8 | uint(c2da_mem[frontsector + 2]) << 0x10 | uint(c2da_mem[frontsector + 3]) << 0x18 : uint(c2da_mem[backsector]) | uint(c2da_mem[backsector + 1]) << 0x8 | uint(c2da_mem[backsector + 2]) << 0x10 | uint(c2da_mem[backsector + 3]) << 0x18)
        dc_texturemid = dc_texturemid + int(uint(c2da_mem[textureheight + texnum * 4]) | uint(c2da_mem[textureheight + texnum * 4 + 1]) << 0x8 | uint(c2da_mem[textureheight + texnum * 4 + 2]) << 0x10 | uint(c2da_mem[textureheight + texnum * 4 + 3]) << 0x18) - viewz
    } else {
        dc_texturemid = int(int(uint(c2da_mem[frontsector + 4]) | uint(c2da_mem[frontsector + 5]) << 0x8 | uint(c2da_mem[frontsector + 6]) << 0x10 | uint(c2da_mem[frontsector + 7]) << 0x18) < int(uint(c2da_mem[backsector + 4]) | uint(c2da_mem[backsector + 5]) << 0x8 | uint(c2da_mem[backsector + 6]) << 0x10 | uint(c2da_mem[backsector + 7]) << 0x18) ? uint(c2da_mem[frontsector + 4]) | uint(c2da_mem[frontsector + 5]) << 0x8 | uint(c2da_mem[frontsector + 6]) << 0x10 | uint(c2da_mem[frontsector + 7]) << 0x18 : uint(c2da_mem[backsector + 4]) | uint(c2da_mem[backsector + 5]) << 0x8 | uint(c2da_mem[backsector + 6]) << 0x10 | uint(c2da_mem[backsector + 7]) << 0x18)
        dc_texturemid = dc_texturemid - viewz
    }
    let c2da_fresh7 : int = int(uint(c2da_mem[curline + 24]) | uint(c2da_mem[curline + 25]) << 0x8 | uint(c2da_mem[curline + 26]) << 0x10 | uint(c2da_mem[curline + 27]) << 0x18) + 4
    dc_texturemid = dc_texturemid + int(uint(c2da_mem[c2da_fresh7]) | uint(c2da_mem[c2da_fresh7 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh7 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh7 + 3]) << 0x18)
    if (fixedcolormap != 0) {
        dc_colormap = fixedcolormap
    }
    dc_x = x1
    while (dc_x <= x2) {
        if (int(int16(uint(c2da_mem[maskedtexturecol + int(dc_x) * 2]) | uint(c2da_mem[maskedtexturecol + int(dc_x) * 2 + 1]) << 0x8)) != 32767) {
            if (fixedcolormap == 0) {
                index = uint(spryscale >> 12)
                if (index >= 48u) {
                    index = uint(48 - 1)
                }
                dc_colormap = int(uint(c2da_mem[walllights + int(index) * 8]) | uint(c2da_mem[walllights + int(index) * 8 + 1]) << 0x8 | uint(c2da_mem[walllights + int(index) * 8 + 2]) << 0x10 | uint(c2da_mem[walllights + int(index) * 8 + 3]) << 0x18)
            }
            sprtopscreen = centeryfrac - FixedMul(dc_texturemid, spryscale)
            dc_iscale = int(0xffffffffu / uint(spryscale))
            col = R_GetColumn(texnum, int(int16(uint(c2da_mem[maskedtexturecol + int(dc_x) * 2]) | uint(c2da_mem[maskedtexturecol + int(dc_x) * 2 + 1]) << 0x8))) - 3
            R_DrawMaskedColumn(col)
            let c2da_fresh8 : int16 = int16(32767)
            let c2da_fresh9 : uint = uint(c2da_fresh8)
            c2da_mem[maskedtexturecol + int(dc_x) * 2] = uint8(c2da_fresh9)
            c2da_mem[maskedtexturecol + int(dc_x) * 2 + 1] = uint8(c2da_fresh9 >> 0x8)
        }
        spryscale = spryscale + rw_scalestep
        dc_x = dc_x + 1
    }
    return
}
var rw_scalestep : int = default<int>

var maskedtexturecol : int = default<int>

var walllights : int = default<int>

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
        if (yl < int(int16(uint(c2da_mem[235040 + rw_x * 2]) | uint(c2da_mem[235040 + rw_x * 2 + 1]) << 0x8)) + 1) {
            yl = int(int16(uint(c2da_mem[235040 + rw_x * 2]) | uint(c2da_mem[235040 + rw_x * 2 + 1]) << 0x8)) + 1
        }
        if (markceiling != 0x0) {
            top = int(int16(uint(c2da_mem[235040 + rw_x * 2]) | uint(c2da_mem[235040 + rw_x * 2 + 1]) << 0x8)) + 1
            bottom = yl - 1
            if (bottom >= int(int16(uint(c2da_mem[235680 + rw_x * 2]) | uint(c2da_mem[235680 + rw_x * 2 + 1]) << 0x8))) {
                bottom = int(int16(uint(c2da_mem[235680 + rw_x * 2]) | uint(c2da_mem[235680 + rw_x * 2 + 1]) << 0x8)) - 1
            }
            if (top <= bottom) {
                let c2da_fresh10 : uint8 = uint8(top)
                c2da_mem[ceilingplane + 21 + rw_x] = c2da_fresh10
                let c2da_fresh11 : uint8 = uint8(bottom)
                c2da_mem[ceilingplane + 343 + rw_x] = c2da_fresh11
            }
        }
        yh = bottomfrac >> 12
        if (yh >= int(int16(uint(c2da_mem[235680 + rw_x * 2]) | uint(c2da_mem[235680 + rw_x * 2 + 1]) << 0x8))) {
            yh = int(int16(uint(c2da_mem[235680 + rw_x * 2]) | uint(c2da_mem[235680 + rw_x * 2 + 1]) << 0x8)) - 1
        }
        if (markfloor != 0x0) {
            top = yh + 1
            bottom = int(int16(uint(c2da_mem[235680 + rw_x * 2]) | uint(c2da_mem[235680 + rw_x * 2 + 1]) << 0x8)) - 1
            if (top <= int(int16(uint(c2da_mem[235040 + rw_x * 2]) | uint(c2da_mem[235040 + rw_x * 2 + 1]) << 0x8))) {
                top = int(int16(uint(c2da_mem[235040 + rw_x * 2]) | uint(c2da_mem[235040 + rw_x * 2 + 1]) << 0x8)) + 1
            }
            if (top <= bottom) {
                let c2da_fresh12 : uint8 = uint8(top)
                c2da_mem[floorplane + 21 + rw_x] = c2da_fresh12
                let c2da_fresh13 : uint8 = uint8(bottom)
                c2da_mem[floorplane + 343 + rw_x] = c2da_fresh13
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
            dc_colormap = int(uint(c2da_mem[walllights + int(index_0) * 8]) | uint(c2da_mem[walllights + int(index_0) * 8 + 1]) << 0x8 | uint(c2da_mem[walllights + int(index_0) * 8 + 2]) << 0x10 | uint(c2da_mem[walllights + int(index_0) * 8 + 3]) << 0x18)
            dc_x = rw_x
            dc_iscale = int(0xffffffffu / uint(rw_scale))
        } else {
            texturecolumn = 0
        }
        if (midtexture != 0) {
            dc_yl = yl
            dc_yh = yh
            dc_texturemid = rw_midtexturemid
            dc_source = R_GetColumn(midtexture, texturecolumn)
            invoke(c2da_fn_table0[colfunc])
            let c2da_fresh14 : int16 = int16(viewheight)
            let c2da_fresh15 : uint = uint(c2da_fresh14)
            c2da_mem[235040 + rw_x * 2] = uint8(c2da_fresh15)
            c2da_mem[235040 + rw_x * 2 + 1] = uint8(c2da_fresh15 >> 0x8)
            let c2da_fresh16 : int16 = int16(-1)
            let c2da_fresh17 : uint = uint(c2da_fresh16)
            c2da_mem[235680 + rw_x * 2] = uint8(c2da_fresh17)
            c2da_mem[235680 + rw_x * 2 + 1] = uint8(c2da_fresh17 >> 0x8)
        } else {
            if (toptexture != 0) {
                mid = pixhigh >> 12
                pixhigh += pixhighstep
                if (mid >= int(int16(uint(c2da_mem[235680 + rw_x * 2]) | uint(c2da_mem[235680 + rw_x * 2 + 1]) << 0x8))) {
                    mid = int(int16(uint(c2da_mem[235680 + rw_x * 2]) | uint(c2da_mem[235680 + rw_x * 2 + 1]) << 0x8)) - 1
                }
                if (mid >= yl) {
                    dc_yl = yl
                    dc_yh = mid
                    dc_texturemid = rw_toptexturemid
                    dc_source = R_GetColumn(toptexture, texturecolumn)
                    invoke(c2da_fn_table0[colfunc])
                    let c2da_fresh18 : int16 = int16(mid)
                    let c2da_fresh19 : uint = uint(c2da_fresh18)
                    c2da_mem[235040 + rw_x * 2] = uint8(c2da_fresh19)
                    c2da_mem[235040 + rw_x * 2 + 1] = uint8(c2da_fresh19 >> 0x8)
                } else {
                    let c2da_fresh20 : int16 = int16(yl - 1)
                    let c2da_fresh21 : uint = uint(c2da_fresh20)
                    c2da_mem[235040 + rw_x * 2] = uint8(c2da_fresh21)
                    c2da_mem[235040 + rw_x * 2 + 1] = uint8(c2da_fresh21 >> 0x8)
                }
            } elif (markceiling != 0x0) {
                let c2da_fresh22 : int16 = int16(yl - 1)
                let c2da_fresh23 : uint = uint(c2da_fresh22)
                c2da_mem[235040 + rw_x * 2] = uint8(c2da_fresh23)
                c2da_mem[235040 + rw_x * 2 + 1] = uint8(c2da_fresh23 >> 0x8)
            }
            if (bottomtexture != 0) {
                mid = pixlow + (1 << 12) - 1 >> 12
                pixlow += pixlowstep
                if (mid <= int(int16(uint(c2da_mem[235040 + rw_x * 2]) | uint(c2da_mem[235040 + rw_x * 2 + 1]) << 0x8))) {
                    mid = int(int16(uint(c2da_mem[235040 + rw_x * 2]) | uint(c2da_mem[235040 + rw_x * 2 + 1]) << 0x8)) + 1
                }
                if (mid <= yh) {
                    dc_yl = mid
                    dc_yh = yh
                    dc_texturemid = rw_bottomtexturemid
                    dc_source = R_GetColumn(bottomtexture, texturecolumn)
                    invoke(c2da_fn_table0[colfunc])
                    let c2da_fresh24 : int16 = int16(mid)
                    let c2da_fresh25 : uint = uint(c2da_fresh24)
                    c2da_mem[235680 + rw_x * 2] = uint8(c2da_fresh25)
                    c2da_mem[235680 + rw_x * 2 + 1] = uint8(c2da_fresh25 >> 0x8)
                } else {
                    let c2da_fresh26 : int16 = int16(yh + 1)
                    let c2da_fresh27 : uint = uint(c2da_fresh26)
                    c2da_mem[235680 + rw_x * 2] = uint8(c2da_fresh27)
                    c2da_mem[235680 + rw_x * 2 + 1] = uint8(c2da_fresh27 >> 0x8)
                }
            } elif (markfloor != 0x0) {
                let c2da_fresh28 : int16 = int16(yh + 1)
                let c2da_fresh29 : uint = uint(c2da_fresh28)
                c2da_mem[235680 + rw_x * 2] = uint8(c2da_fresh29)
                c2da_mem[235680 + rw_x * 2 + 1] = uint8(c2da_fresh29 >> 0x8)
            }
            if (maskedtexture != 0x0) {
                let c2da_fresh30 : int16 = int16(texturecolumn)
                let c2da_fresh31 : uint = uint(c2da_fresh30)
                c2da_mem[maskedtexturecol + rw_x * 2] = uint8(c2da_fresh31)
                c2da_mem[maskedtexturecol + rw_x * 2 + 1] = uint8(c2da_fresh31 >> 0x8)
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
    var vtop : int
    var lightnum_0 : int
    if (ds_p == 67456 + 256 * 64) {
        return
    }
    if (start >= viewwidth || start > stop) {
        I_Error(362640, [C2daVaArg(tag = 1, i64 = int64(start), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(stop), f64 = 0.0lf, raw = 0x0)])
    }
    sidedef = int(uint(c2da_mem[curline + 24]) | uint(c2da_mem[curline + 25]) << 0x8 | uint(c2da_mem[curline + 26]) << 0x10 | uint(c2da_mem[curline + 27]) << 0x18)
    linedef = int(uint(c2da_mem[curline + 32]) | uint(c2da_mem[curline + 33]) << 0x8 | uint(c2da_mem[curline + 34]) << 0x10 | uint(c2da_mem[curline + 35]) << 0x18)
    let c2da_fresh32 : int16 = int16(int(int16(uint(c2da_mem[linedef + 24]) | uint(c2da_mem[linedef + 25]) << 0x8)) | 256)
    let c2da_fresh33 : uint = uint(c2da_fresh32)
    c2da_mem[linedef + 24] = uint8(c2da_fresh33)
    c2da_mem[linedef + 25] = uint8(c2da_fresh33 >> 0x8)
    rw_normalangle = (uint(c2da_mem[curline + 20]) | uint(c2da_mem[curline + 21]) << 0x8 | uint(c2da_mem[curline + 22]) << 0x10 | uint(c2da_mem[curline + 23]) << 0x18) + 0x40000000u
    offsetangle = uint(c2da_std_abs(int(rw_normalangle - uint(rw_angle1))))
    if (offsetangle > 0x40000000u) {
        offsetangle = 0x40000000u
    }
    let c2da_fresh34 : int = int(uint(c2da_mem[curline]) | uint(c2da_mem[curline + 1]) << 0x8 | uint(c2da_mem[curline + 2]) << 0x10 | uint(c2da_mem[curline + 3]) << 0x18)
    let c2da_fresh35 : int = int(uint(c2da_mem[curline]) | uint(c2da_mem[curline + 1]) << 0x8 | uint(c2da_mem[curline + 2]) << 0x10 | uint(c2da_mem[curline + 3]) << 0x18) + 4
    hyp = R_PointToDist(int(uint(c2da_mem[c2da_fresh34]) | uint(c2da_mem[c2da_fresh34 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh34 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh34 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh35]) | uint(c2da_mem[c2da_fresh35 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh35 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh35 + 3]) << 0x18))
    let c2da_fresh36 : int = 257920 + int(0x40000000u - offsetangle >> 19u) * 4
    sineval = int(uint(c2da_mem[c2da_fresh36]) | uint(c2da_mem[c2da_fresh36 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh36 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh36 + 3]) << 0x18)
    rw_distance = FixedMul(hyp, sineval)
    rw_x = int(start)  // nolint:PERF020
    let c2da_fresh37 : uint = uint(rw_x)
    c2da_mem[ds_p + 8] = uint8(c2da_fresh37)
    c2da_mem[ds_p + 9] = uint8(c2da_fresh37 >> 0x8)
    c2da_mem[ds_p + 10] = uint8(c2da_fresh37 >> 0x10)
    c2da_mem[ds_p + 11] = uint8(c2da_fresh37 >> 0x18)
    let c2da_fresh38 : uint = uint(stop)
    c2da_mem[ds_p + 12] = uint8(c2da_fresh38)
    c2da_mem[ds_p + 13] = uint8(c2da_fresh38 >> 0x8)
    c2da_mem[ds_p + 14] = uint8(c2da_fresh38 >> 0x10)
    c2da_mem[ds_p + 15] = uint8(c2da_fresh38 >> 0x18)
    let c2da_fresh39 : uint = uint(curline)
    c2da_mem[ds_p] = uint8(c2da_fresh39)
    c2da_mem[ds_p + 1] = uint8(c2da_fresh39 >> 0x8)
    c2da_mem[ds_p + 2] = uint8(c2da_fresh39 >> 0x10)
    c2da_mem[ds_p + 3] = uint8(c2da_fresh39 >> 0x18)
    c2da_mem[ds_p + 4] = 0u8
    c2da_mem[ds_p + 5] = 0u8
    c2da_mem[ds_p + 6] = 0u8
    c2da_mem[ds_p + 7] = 0u8
    rw_stopx = stop + 1
    rw_scale = R_ScaleFromGlobalAngle(viewangle + xtoviewangle[start])
    let c2da_fresh40 : uint = uint(rw_scale)
    c2da_mem[ds_p + 16] = uint8(c2da_fresh40)
    c2da_mem[ds_p + 17] = uint8(c2da_fresh40 >> 0x8)
    c2da_mem[ds_p + 18] = uint8(c2da_fresh40 >> 0x10)
    c2da_mem[ds_p + 19] = uint8(c2da_fresh40 >> 0x18)
    if (stop > start) {
        let c2da_fresh41 : int = R_ScaleFromGlobalAngle(viewangle + xtoviewangle[stop])
        let c2da_fresh42 : uint = uint(c2da_fresh41)
        c2da_mem[ds_p + 20] = uint8(c2da_fresh42)
        c2da_mem[ds_p + 21] = uint8(c2da_fresh42 >> 0x8)
        c2da_mem[ds_p + 22] = uint8(c2da_fresh42 >> 0x10)
        c2da_mem[ds_p + 23] = uint8(c2da_fresh42 >> 0x18)
        rw_scalestep = (int(uint(c2da_mem[ds_p + 20]) | uint(c2da_mem[ds_p + 21]) << 0x8 | uint(c2da_mem[ds_p + 22]) << 0x10 | uint(c2da_mem[ds_p + 23]) << 0x18) - rw_scale) / (stop - start)
        let c2da_fresh43 : uint = uint(rw_scalestep)
        c2da_mem[ds_p + 24] = uint8(c2da_fresh43)
        c2da_mem[ds_p + 25] = uint8(c2da_fresh43 >> 0x8)
        c2da_mem[ds_p + 26] = uint8(c2da_fresh43 >> 0x10)
        c2da_mem[ds_p + 27] = uint8(c2da_fresh43 >> 0x18)
    } else {
        let c2da_fresh44 : int = int(uint(c2da_mem[ds_p + 16]) | uint(c2da_mem[ds_p + 17]) << 0x8 | uint(c2da_mem[ds_p + 18]) << 0x10 | uint(c2da_mem[ds_p + 19]) << 0x18)
        let c2da_fresh45 : uint = uint(c2da_fresh44)
        c2da_mem[ds_p + 20] = uint8(c2da_fresh45)
        c2da_mem[ds_p + 21] = uint8(c2da_fresh45 >> 0x8)
        c2da_mem[ds_p + 22] = uint8(c2da_fresh45 >> 0x10)
        c2da_mem[ds_p + 23] = uint8(c2da_fresh45 >> 0x18)
    }
    worldtop = int(uint(c2da_mem[frontsector + 4]) | uint(c2da_mem[frontsector + 5]) << 0x8 | uint(c2da_mem[frontsector + 6]) << 0x10 | uint(c2da_mem[frontsector + 7]) << 0x18) - viewz
    worldbottom = int(uint(c2da_mem[frontsector]) | uint(c2da_mem[frontsector + 1]) << 0x8 | uint(c2da_mem[frontsector + 2]) << 0x10 | uint(c2da_mem[frontsector + 3]) << 0x18) - viewz
    maskedtexture = 0u
    bottomtexture = int(maskedtexture)
    toptexture = int(bottomtexture)  // nolint:PERF020
    midtexture = int(toptexture)  // nolint:PERF020
    let c2da_fresh46 : uint = 0u
    c2da_mem[ds_p + 56] = uint8(c2da_fresh46)
    c2da_mem[ds_p + 57] = uint8(c2da_fresh46 >> 0x8)
    c2da_mem[ds_p + 58] = uint8(c2da_fresh46 >> 0x10)
    c2da_mem[ds_p + 59] = uint8(c2da_fresh46 >> 0x18)
    c2da_mem[ds_p + 60] = 0u8
    c2da_mem[ds_p + 61] = 0u8
    c2da_mem[ds_p + 62] = 0u8
    c2da_mem[ds_p + 63] = 0u8
    if (backsector == 0) {
        let c2da_fresh47 : int = texturetranslation + int(int16(uint(c2da_mem[sidedef + 12]) | uint(c2da_mem[sidedef + 13]) << 0x8)) * 4
        midtexture = int(uint(c2da_mem[c2da_fresh47]) | uint(c2da_mem[c2da_fresh47 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh47 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh47 + 3]) << 0x18)
        markceiling = 1u
        markfloor = uint(markceiling)  // nolint:PERF020
        if ((int(int16(uint(c2da_mem[linedef + 24]) | uint(c2da_mem[linedef + 25]) << 0x8)) & 16) != 0) {
            let c2da_fresh48 : int = textureheight + int(int16(uint(c2da_mem[sidedef + 12]) | uint(c2da_mem[sidedef + 13]) << 0x8)) * 4
            vtop = int(uint(c2da_mem[frontsector]) | uint(c2da_mem[frontsector + 1]) << 0x8 | uint(c2da_mem[frontsector + 2]) << 0x10 | uint(c2da_mem[frontsector + 3]) << 0x18) + int(uint(c2da_mem[c2da_fresh48]) | uint(c2da_mem[c2da_fresh48 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh48 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh48 + 3]) << 0x18)
            let c2da_fresh49 : int = textureheight + int(int16(uint(c2da_mem[sidedef + 12]) | uint(c2da_mem[sidedef + 13]) << 0x8)) * 4
            vtop = int(uint(c2da_mem[frontsector]) | uint(c2da_mem[frontsector + 1]) << 0x8 | uint(c2da_mem[frontsector + 2]) << 0x10 | uint(c2da_mem[frontsector + 3]) << 0x18) + int(uint(c2da_mem[c2da_fresh49]) | uint(c2da_mem[c2da_fresh49 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh49 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh49 + 3]) << 0x18)
            rw_midtexturemid = vtop - viewz
        } else {
            rw_midtexturemid = int(worldtop)  // nolint:PERF020
        }
        rw_midtexturemid += int(uint(c2da_mem[sidedef + 4]) | uint(c2da_mem[sidedef + 5]) << 0x8 | uint(c2da_mem[sidedef + 6]) << 0x10 | uint(c2da_mem[sidedef + 7]) << 0x18)
        let c2da_fresh50 : int = 3
        let c2da_fresh51 : uint = uint(c2da_fresh50)
        c2da_mem[ds_p + 28] = uint8(c2da_fresh51)
        c2da_mem[ds_p + 29] = uint8(c2da_fresh51 >> 0x8)
        c2da_mem[ds_p + 30] = uint8(c2da_fresh51 >> 0x10)
        c2da_mem[ds_p + 31] = uint8(c2da_fresh51 >> 0x18)
        let c2da_fresh52 : uint = 233760u
        c2da_mem[ds_p + 40] = uint8(c2da_fresh52)
        c2da_mem[ds_p + 41] = uint8(c2da_fresh52 >> 0x8)
        c2da_mem[ds_p + 42] = uint8(c2da_fresh52 >> 0x10)
        c2da_mem[ds_p + 43] = uint8(c2da_fresh52 >> 0x18)
        c2da_mem[ds_p + 44] = 0u8
        c2da_mem[ds_p + 45] = 0u8
        c2da_mem[ds_p + 46] = 0u8
        c2da_mem[ds_p + 47] = 0u8
        let c2da_fresh53 : uint = 234400u
        c2da_mem[ds_p + 48] = uint8(c2da_fresh53)
        c2da_mem[ds_p + 49] = uint8(c2da_fresh53 >> 0x8)
        c2da_mem[ds_p + 50] = uint8(c2da_fresh53 >> 0x10)
        c2da_mem[ds_p + 51] = uint8(c2da_fresh53 >> 0x18)
        c2da_mem[ds_p + 52] = 0u8
        c2da_mem[ds_p + 53] = 0u8
        c2da_mem[ds_p + 54] = 0u8
        c2da_mem[ds_p + 55] = 0u8
        let c2da_fresh54 : int = 2147483647
        let c2da_fresh55 : uint = uint(c2da_fresh54)
        c2da_mem[ds_p + 32] = uint8(c2da_fresh55)
        c2da_mem[ds_p + 33] = uint8(c2da_fresh55 >> 0x8)
        c2da_mem[ds_p + 34] = uint8(c2da_fresh55 >> 0x10)
        c2da_mem[ds_p + 35] = uint8(c2da_fresh55 >> 0x18)
        let c2da_fresh56 : int = -2147483647 - 1
        let c2da_fresh57 : uint = uint(c2da_fresh56)
        c2da_mem[ds_p + 36] = uint8(c2da_fresh57)
        c2da_mem[ds_p + 37] = uint8(c2da_fresh57 >> 0x8)
        c2da_mem[ds_p + 38] = uint8(c2da_fresh57 >> 0x10)
        c2da_mem[ds_p + 39] = uint8(c2da_fresh57 >> 0x18)
    } else {
        let c2da_fresh58 : uint = 0u
        c2da_mem[ds_p + 48] = uint8(c2da_fresh58)
        c2da_mem[ds_p + 49] = uint8(c2da_fresh58 >> 0x8)
        c2da_mem[ds_p + 50] = uint8(c2da_fresh58 >> 0x10)
        c2da_mem[ds_p + 51] = uint8(c2da_fresh58 >> 0x18)
        c2da_mem[ds_p + 52] = 0u8
        c2da_mem[ds_p + 53] = 0u8
        c2da_mem[ds_p + 54] = 0u8
        c2da_mem[ds_p + 55] = 0u8
        let c2da_fresh59 : uint = 0u
        c2da_mem[ds_p + 40] = uint8(c2da_fresh59)
        c2da_mem[ds_p + 41] = uint8(c2da_fresh59 >> 0x8)
        c2da_mem[ds_p + 42] = uint8(c2da_fresh59 >> 0x10)
        c2da_mem[ds_p + 43] = uint8(c2da_fresh59 >> 0x18)
        c2da_mem[ds_p + 44] = 0u8
        c2da_mem[ds_p + 45] = 0u8
        c2da_mem[ds_p + 46] = 0u8
        c2da_mem[ds_p + 47] = 0u8
        let c2da_fresh60 : int = 0
        let c2da_fresh61 : uint = uint(c2da_fresh60)
        c2da_mem[ds_p + 28] = uint8(c2da_fresh61)
        c2da_mem[ds_p + 29] = uint8(c2da_fresh61 >> 0x8)
        c2da_mem[ds_p + 30] = uint8(c2da_fresh61 >> 0x10)
        c2da_mem[ds_p + 31] = uint8(c2da_fresh61 >> 0x18)
        if (int(uint(c2da_mem[frontsector]) | uint(c2da_mem[frontsector + 1]) << 0x8 | uint(c2da_mem[frontsector + 2]) << 0x10 | uint(c2da_mem[frontsector + 3]) << 0x18) > int(uint(c2da_mem[backsector]) | uint(c2da_mem[backsector + 1]) << 0x8 | uint(c2da_mem[backsector + 2]) << 0x10 | uint(c2da_mem[backsector + 3]) << 0x18)) {
            let c2da_fresh62 : int = 1
            let c2da_fresh63 : uint = uint(c2da_fresh62)
            c2da_mem[ds_p + 28] = uint8(c2da_fresh63)
            c2da_mem[ds_p + 29] = uint8(c2da_fresh63 >> 0x8)
            c2da_mem[ds_p + 30] = uint8(c2da_fresh63 >> 0x10)
            c2da_mem[ds_p + 31] = uint8(c2da_fresh63 >> 0x18)
            let c2da_fresh64 : int = int(uint(c2da_mem[frontsector]) | uint(c2da_mem[frontsector + 1]) << 0x8 | uint(c2da_mem[frontsector + 2]) << 0x10 | uint(c2da_mem[frontsector + 3]) << 0x18)
            let c2da_fresh65 : uint = uint(c2da_fresh64)
            c2da_mem[ds_p + 32] = uint8(c2da_fresh65)
            c2da_mem[ds_p + 33] = uint8(c2da_fresh65 >> 0x8)
            c2da_mem[ds_p + 34] = uint8(c2da_fresh65 >> 0x10)
            c2da_mem[ds_p + 35] = uint8(c2da_fresh65 >> 0x18)
        } elif (int(uint(c2da_mem[backsector]) | uint(c2da_mem[backsector + 1]) << 0x8 | uint(c2da_mem[backsector + 2]) << 0x10 | uint(c2da_mem[backsector + 3]) << 0x18) > viewz) {
            let c2da_fresh66 : int = 1
            let c2da_fresh67 : uint = uint(c2da_fresh66)
            c2da_mem[ds_p + 28] = uint8(c2da_fresh67)
            c2da_mem[ds_p + 29] = uint8(c2da_fresh67 >> 0x8)
            c2da_mem[ds_p + 30] = uint8(c2da_fresh67 >> 0x10)
            c2da_mem[ds_p + 31] = uint8(c2da_fresh67 >> 0x18)
            let c2da_fresh68 : int = 2147483647
            let c2da_fresh69 : uint = uint(c2da_fresh68)
            c2da_mem[ds_p + 32] = uint8(c2da_fresh69)
            c2da_mem[ds_p + 33] = uint8(c2da_fresh69 >> 0x8)
            c2da_mem[ds_p + 34] = uint8(c2da_fresh69 >> 0x10)
            c2da_mem[ds_p + 35] = uint8(c2da_fresh69 >> 0x18)
        }
        if (int(uint(c2da_mem[frontsector + 4]) | uint(c2da_mem[frontsector + 5]) << 0x8 | uint(c2da_mem[frontsector + 6]) << 0x10 | uint(c2da_mem[frontsector + 7]) << 0x18) < int(uint(c2da_mem[backsector + 4]) | uint(c2da_mem[backsector + 5]) << 0x8 | uint(c2da_mem[backsector + 6]) << 0x10 | uint(c2da_mem[backsector + 7]) << 0x18)) {
            let c2da_fresh70 : int = int(uint(c2da_mem[ds_p + 28]) | uint(c2da_mem[ds_p + 29]) << 0x8 | uint(c2da_mem[ds_p + 30]) << 0x10 | uint(c2da_mem[ds_p + 31]) << 0x18) | 2
            let c2da_fresh71 : uint = uint(c2da_fresh70)
            c2da_mem[ds_p + 28] = uint8(c2da_fresh71)
            c2da_mem[ds_p + 29] = uint8(c2da_fresh71 >> 0x8)
            c2da_mem[ds_p + 30] = uint8(c2da_fresh71 >> 0x10)
            c2da_mem[ds_p + 31] = uint8(c2da_fresh71 >> 0x18)
            let c2da_fresh72 : int = int(uint(c2da_mem[frontsector + 4]) | uint(c2da_mem[frontsector + 5]) << 0x8 | uint(c2da_mem[frontsector + 6]) << 0x10 | uint(c2da_mem[frontsector + 7]) << 0x18)
            let c2da_fresh73 : uint = uint(c2da_fresh72)
            c2da_mem[ds_p + 36] = uint8(c2da_fresh73)
            c2da_mem[ds_p + 37] = uint8(c2da_fresh73 >> 0x8)
            c2da_mem[ds_p + 38] = uint8(c2da_fresh73 >> 0x10)
            c2da_mem[ds_p + 39] = uint8(c2da_fresh73 >> 0x18)
        } elif (int(uint(c2da_mem[backsector + 4]) | uint(c2da_mem[backsector + 5]) << 0x8 | uint(c2da_mem[backsector + 6]) << 0x10 | uint(c2da_mem[backsector + 7]) << 0x18) < viewz) {
            let c2da_fresh74 : int = int(uint(c2da_mem[ds_p + 28]) | uint(c2da_mem[ds_p + 29]) << 0x8 | uint(c2da_mem[ds_p + 30]) << 0x10 | uint(c2da_mem[ds_p + 31]) << 0x18) | 2
            let c2da_fresh75 : uint = uint(c2da_fresh74)
            c2da_mem[ds_p + 28] = uint8(c2da_fresh75)
            c2da_mem[ds_p + 29] = uint8(c2da_fresh75 >> 0x8)
            c2da_mem[ds_p + 30] = uint8(c2da_fresh75 >> 0x10)
            c2da_mem[ds_p + 31] = uint8(c2da_fresh75 >> 0x18)
            let c2da_fresh76 : int = -2147483647 - 1
            let c2da_fresh77 : uint = uint(c2da_fresh76)
            c2da_mem[ds_p + 36] = uint8(c2da_fresh77)
            c2da_mem[ds_p + 37] = uint8(c2da_fresh77 >> 0x8)
            c2da_mem[ds_p + 38] = uint8(c2da_fresh77 >> 0x10)
            c2da_mem[ds_p + 39] = uint8(c2da_fresh77 >> 0x18)
        }
        if (int(uint(c2da_mem[backsector + 4]) | uint(c2da_mem[backsector + 5]) << 0x8 | uint(c2da_mem[backsector + 6]) << 0x10 | uint(c2da_mem[backsector + 7]) << 0x18) <= int(uint(c2da_mem[frontsector]) | uint(c2da_mem[frontsector + 1]) << 0x8 | uint(c2da_mem[frontsector + 2]) << 0x10 | uint(c2da_mem[frontsector + 3]) << 0x18)) {
            let c2da_fresh78 : uint = 234400u
            c2da_mem[ds_p + 48] = uint8(c2da_fresh78)
            c2da_mem[ds_p + 49] = uint8(c2da_fresh78 >> 0x8)
            c2da_mem[ds_p + 50] = uint8(c2da_fresh78 >> 0x10)
            c2da_mem[ds_p + 51] = uint8(c2da_fresh78 >> 0x18)
            c2da_mem[ds_p + 52] = 0u8
            c2da_mem[ds_p + 53] = 0u8
            c2da_mem[ds_p + 54] = 0u8
            c2da_mem[ds_p + 55] = 0u8
            let c2da_fresh79 : int = 2147483647
            let c2da_fresh80 : uint = uint(c2da_fresh79)
            c2da_mem[ds_p + 32] = uint8(c2da_fresh80)
            c2da_mem[ds_p + 33] = uint8(c2da_fresh80 >> 0x8)
            c2da_mem[ds_p + 34] = uint8(c2da_fresh80 >> 0x10)
            c2da_mem[ds_p + 35] = uint8(c2da_fresh80 >> 0x18)
            let c2da_fresh81 : int = int(uint(c2da_mem[ds_p + 28]) | uint(c2da_mem[ds_p + 29]) << 0x8 | uint(c2da_mem[ds_p + 30]) << 0x10 | uint(c2da_mem[ds_p + 31]) << 0x18) | 1
            let c2da_fresh82 : uint = uint(c2da_fresh81)
            c2da_mem[ds_p + 28] = uint8(c2da_fresh82)
            c2da_mem[ds_p + 29] = uint8(c2da_fresh82 >> 0x8)
            c2da_mem[ds_p + 30] = uint8(c2da_fresh82 >> 0x10)
            c2da_mem[ds_p + 31] = uint8(c2da_fresh82 >> 0x18)
        }
        if (int(uint(c2da_mem[backsector]) | uint(c2da_mem[backsector + 1]) << 0x8 | uint(c2da_mem[backsector + 2]) << 0x10 | uint(c2da_mem[backsector + 3]) << 0x18) >= int(uint(c2da_mem[frontsector + 4]) | uint(c2da_mem[frontsector + 5]) << 0x8 | uint(c2da_mem[frontsector + 6]) << 0x10 | uint(c2da_mem[frontsector + 7]) << 0x18)) {
            let c2da_fresh83 : uint = 233760u
            c2da_mem[ds_p + 40] = uint8(c2da_fresh83)
            c2da_mem[ds_p + 41] = uint8(c2da_fresh83 >> 0x8)
            c2da_mem[ds_p + 42] = uint8(c2da_fresh83 >> 0x10)
            c2da_mem[ds_p + 43] = uint8(c2da_fresh83 >> 0x18)
            c2da_mem[ds_p + 44] = 0u8
            c2da_mem[ds_p + 45] = 0u8
            c2da_mem[ds_p + 46] = 0u8
            c2da_mem[ds_p + 47] = 0u8
            let c2da_fresh84 : int = -2147483647 - 1
            let c2da_fresh85 : uint = uint(c2da_fresh84)
            c2da_mem[ds_p + 36] = uint8(c2da_fresh85)
            c2da_mem[ds_p + 37] = uint8(c2da_fresh85 >> 0x8)
            c2da_mem[ds_p + 38] = uint8(c2da_fresh85 >> 0x10)
            c2da_mem[ds_p + 39] = uint8(c2da_fresh85 >> 0x18)
            let c2da_fresh86 : int = int(uint(c2da_mem[ds_p + 28]) | uint(c2da_mem[ds_p + 29]) << 0x8 | uint(c2da_mem[ds_p + 30]) << 0x10 | uint(c2da_mem[ds_p + 31]) << 0x18) | 2
            let c2da_fresh87 : uint = uint(c2da_fresh86)
            c2da_mem[ds_p + 28] = uint8(c2da_fresh87)
            c2da_mem[ds_p + 29] = uint8(c2da_fresh87 >> 0x8)
            c2da_mem[ds_p + 30] = uint8(c2da_fresh87 >> 0x10)
            c2da_mem[ds_p + 31] = uint8(c2da_fresh87 >> 0x18)
        }
        worldhigh = int(uint(c2da_mem[backsector + 4]) | uint(c2da_mem[backsector + 5]) << 0x8 | uint(c2da_mem[backsector + 6]) << 0x10 | uint(c2da_mem[backsector + 7]) << 0x18) - viewz
        worldlow = int(uint(c2da_mem[backsector]) | uint(c2da_mem[backsector + 1]) << 0x8 | uint(c2da_mem[backsector + 2]) << 0x10 | uint(c2da_mem[backsector + 3]) << 0x18) - viewz
        if (int(int16(uint(c2da_mem[frontsector + 10]) | uint(c2da_mem[frontsector + 11]) << 0x8)) == skyflatnum && int(int16(uint(c2da_mem[backsector + 10]) | uint(c2da_mem[backsector + 11]) << 0x8)) == skyflatnum) {
            worldtop = int(worldhigh)  // nolint:PERF020
        }
        if (worldlow != worldbottom || int(int16(uint(c2da_mem[backsector + 8]) | uint(c2da_mem[backsector + 9]) << 0x8)) != int(int16(uint(c2da_mem[frontsector + 8]) | uint(c2da_mem[frontsector + 9]) << 0x8)) || int(int16(uint(c2da_mem[backsector + 12]) | uint(c2da_mem[backsector + 13]) << 0x8)) != int(int16(uint(c2da_mem[frontsector + 12]) | uint(c2da_mem[frontsector + 13]) << 0x8))) {
            markfloor = 1u
        } else {
            markfloor = 0u
        }
        if (worldhigh != worldtop || int(int16(uint(c2da_mem[backsector + 10]) | uint(c2da_mem[backsector + 11]) << 0x8)) != int(int16(uint(c2da_mem[frontsector + 10]) | uint(c2da_mem[frontsector + 11]) << 0x8)) || int(int16(uint(c2da_mem[backsector + 12]) | uint(c2da_mem[backsector + 13]) << 0x8)) != int(int16(uint(c2da_mem[frontsector + 12]) | uint(c2da_mem[frontsector + 13]) << 0x8))) {
            markceiling = 1u
        } else {
            markceiling = 0u
        }
        if (int(uint(c2da_mem[backsector + 4]) | uint(c2da_mem[backsector + 5]) << 0x8 | uint(c2da_mem[backsector + 6]) << 0x10 | uint(c2da_mem[backsector + 7]) << 0x18) <= int(uint(c2da_mem[frontsector]) | uint(c2da_mem[frontsector + 1]) << 0x8 | uint(c2da_mem[frontsector + 2]) << 0x10 | uint(c2da_mem[frontsector + 3]) << 0x18) || int(uint(c2da_mem[backsector]) | uint(c2da_mem[backsector + 1]) << 0x8 | uint(c2da_mem[backsector + 2]) << 0x10 | uint(c2da_mem[backsector + 3]) << 0x18) >= int(uint(c2da_mem[frontsector + 4]) | uint(c2da_mem[frontsector + 5]) << 0x8 | uint(c2da_mem[frontsector + 6]) << 0x10 | uint(c2da_mem[frontsector + 7]) << 0x18)) {
            markfloor = 1u
            markceiling = uint(markfloor)  // nolint:PERF020
        }
        if (worldhigh < worldtop) {
            let c2da_fresh88 : int = texturetranslation + int(int16(uint(c2da_mem[sidedef + 8]) | uint(c2da_mem[sidedef + 9]) << 0x8)) * 4
            toptexture = int(uint(c2da_mem[c2da_fresh88]) | uint(c2da_mem[c2da_fresh88 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh88 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh88 + 3]) << 0x18)
            if ((int(int16(uint(c2da_mem[linedef + 24]) | uint(c2da_mem[linedef + 25]) << 0x8)) & 8) != 0) {
                rw_toptexturemid = int(worldtop)  // nolint:PERF020
            } else {
                let c2da_fresh89 : int = textureheight + int(int16(uint(c2da_mem[sidedef + 8]) | uint(c2da_mem[sidedef + 9]) << 0x8)) * 4
                vtop = int(uint(c2da_mem[backsector + 4]) | uint(c2da_mem[backsector + 5]) << 0x8 | uint(c2da_mem[backsector + 6]) << 0x10 | uint(c2da_mem[backsector + 7]) << 0x18) + int(uint(c2da_mem[c2da_fresh89]) | uint(c2da_mem[c2da_fresh89 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh89 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh89 + 3]) << 0x18)
                let c2da_fresh90 : int = textureheight + int(int16(uint(c2da_mem[sidedef + 8]) | uint(c2da_mem[sidedef + 9]) << 0x8)) * 4
                vtop = int(uint(c2da_mem[backsector + 4]) | uint(c2da_mem[backsector + 5]) << 0x8 | uint(c2da_mem[backsector + 6]) << 0x10 | uint(c2da_mem[backsector + 7]) << 0x18) + int(uint(c2da_mem[c2da_fresh90]) | uint(c2da_mem[c2da_fresh90 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh90 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh90 + 3]) << 0x18)
                rw_toptexturemid = vtop - viewz
            }
        }
        if (worldlow > worldbottom) {
            let c2da_fresh91 : int = texturetranslation + int(int16(uint(c2da_mem[sidedef + 10]) | uint(c2da_mem[sidedef + 11]) << 0x8)) * 4
            bottomtexture = int(uint(c2da_mem[c2da_fresh91]) | uint(c2da_mem[c2da_fresh91 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh91 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh91 + 3]) << 0x18)
            if ((int(int16(uint(c2da_mem[linedef + 24]) | uint(c2da_mem[linedef + 25]) << 0x8)) & 16) != 0) {
                rw_bottomtexturemid = int(worldtop)  // nolint:PERF020
            } else {
                rw_bottomtexturemid = int(worldlow)  // nolint:PERF020
            }
        }
        rw_toptexturemid += int(uint(c2da_mem[sidedef + 4]) | uint(c2da_mem[sidedef + 5]) << 0x8 | uint(c2da_mem[sidedef + 6]) << 0x10 | uint(c2da_mem[sidedef + 7]) << 0x18)
        rw_bottomtexturemid += int(uint(c2da_mem[sidedef + 4]) | uint(c2da_mem[sidedef + 5]) << 0x8 | uint(c2da_mem[sidedef + 6]) << 0x10 | uint(c2da_mem[sidedef + 7]) << 0x18)
        if (int16(uint(c2da_mem[sidedef + 12]) | uint(c2da_mem[sidedef + 13]) << 0x8) != 0) {
            maskedtexture = 1u
            maskedtexturecol = lastopening - rw_x * 2
            let c2da_fresh92 : uint = uint(maskedtexturecol)
            c2da_mem[ds_p + 56] = uint8(c2da_fresh92)
            c2da_mem[ds_p + 57] = uint8(c2da_fresh92 >> 0x8)
            c2da_mem[ds_p + 58] = uint8(c2da_fresh92 >> 0x10)
            c2da_mem[ds_p + 59] = uint8(c2da_fresh92 >> 0x18)
            c2da_mem[ds_p + 60] = 0u8
            c2da_mem[ds_p + 61] = 0u8
            c2da_mem[ds_p + 62] = 0u8
            c2da_mem[ds_p + 63] = 0u8
            lastopening = lastopening + (rw_stopx - rw_x) * 2
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
        let c2da_fresh93 : int = 257920 + int(offsetangle >> 19u) * 4
        sineval = int(uint(c2da_mem[c2da_fresh93]) | uint(c2da_mem[c2da_fresh93 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh93 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh93 + 3]) << 0x18)
        rw_offset = FixedMul(hyp, sineval)
        if (rw_normalangle - uint(rw_angle1) < 0x80000000u) {
            rw_offset = -rw_offset
        }
        rw_offset += int(uint(c2da_mem[sidedef]) | uint(c2da_mem[sidedef + 1]) << 0x8 | uint(c2da_mem[sidedef + 2]) << 0x10 | uint(c2da_mem[sidedef + 3]) << 0x18) + int(uint(c2da_mem[curline + 16]) | uint(c2da_mem[curline + 17]) << 0x8 | uint(c2da_mem[curline + 18]) << 0x10 | uint(c2da_mem[curline + 19]) << 0x18)
        rw_centerangle = uint(0x40000000u + viewangle - rw_normalangle)
        if (fixedcolormap == 0) {
            lightnum_0 = (int(int16(uint(c2da_mem[frontsector + 12]) | uint(c2da_mem[frontsector + 13]) << 0x8)) >> 4) + extralight
            let c2da_fresh94 : int = int(uint(c2da_mem[curline]) | uint(c2da_mem[curline + 1]) << 0x8 | uint(c2da_mem[curline + 2]) << 0x10 | uint(c2da_mem[curline + 3]) << 0x18) + 4
            let c2da_fresh95 : int = int(uint(c2da_mem[curline + 8]) | uint(c2da_mem[curline + 9]) << 0x8 | uint(c2da_mem[curline + 10]) << 0x10 | uint(c2da_mem[curline + 11]) << 0x18) + 4
            if (int(uint(c2da_mem[c2da_fresh94]) | uint(c2da_mem[c2da_fresh94 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh94 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh94 + 3]) << 0x18) == int(uint(c2da_mem[c2da_fresh95]) | uint(c2da_mem[c2da_fresh95 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh95 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh95 + 3]) << 0x18)) {
                lightnum_0--
            } else {
                let c2da_fresh96 : int = int(uint(c2da_mem[curline]) | uint(c2da_mem[curline + 1]) << 0x8 | uint(c2da_mem[curline + 2]) << 0x10 | uint(c2da_mem[curline + 3]) << 0x18)
                let c2da_fresh97 : int = int(uint(c2da_mem[curline + 8]) | uint(c2da_mem[curline + 9]) << 0x8 | uint(c2da_mem[curline + 10]) << 0x10 | uint(c2da_mem[curline + 11]) << 0x18)
                if (int(uint(c2da_mem[c2da_fresh96]) | uint(c2da_mem[c2da_fresh96 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh96 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh96 + 3]) << 0x18) == int(uint(c2da_mem[c2da_fresh97]) | uint(c2da_mem[c2da_fresh97 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh97 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh97 + 3]) << 0x18)) {
                    lightnum_0++
                }
            }
            if (lightnum_0 < 0) {
                walllights = 227616 + 0 * 384
            } elif (lightnum_0 >= 16) {
                walllights = 227616 + (16 - 1) * 384
            } else {
                walllights = 227616 + lightnum_0 * 384
            }
        }
    }
    if (int(uint(c2da_mem[frontsector]) | uint(c2da_mem[frontsector + 1]) << 0x8 | uint(c2da_mem[frontsector + 2]) << 0x10 | uint(c2da_mem[frontsector + 3]) << 0x18) >= viewz) {
        markfloor = 0u
    }
    if (int(uint(c2da_mem[frontsector + 4]) | uint(c2da_mem[frontsector + 5]) << 0x8 | uint(c2da_mem[frontsector + 6]) << 0x10 | uint(c2da_mem[frontsector + 7]) << 0x18) <= viewz && int(int16(uint(c2da_mem[frontsector + 10]) | uint(c2da_mem[frontsector + 11]) << 0x8)) != skyflatnum) {
        markceiling = 0u
    }
    worldtop >>= 4
    worldbottom >>= 4
    topstep = -FixedMul(rw_scalestep, worldtop)
    topfrac = (centeryfrac >> 4) - FixedMul(worldtop, rw_scale)
    bottomstep = -FixedMul(rw_scalestep, worldbottom)
    bottomfrac = (centeryfrac >> 4) - FixedMul(worldbottom, rw_scale)
    if (backsector != 0) {
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
        ceilingplane = R_CheckPlane(ceilingplane, rw_x, rw_stopx - 1)
    }
    if (markfloor != 0x0) {
        floorplane = R_CheckPlane(floorplane, rw_x, rw_stopx - 1)
    }
    R_RenderSegLoop()
    if (((int(uint(c2da_mem[ds_p + 28]) | uint(c2da_mem[ds_p + 29]) << 0x8 | uint(c2da_mem[ds_p + 30]) << 0x10 | uint(c2da_mem[ds_p + 31]) << 0x18) & 2) != 0 || maskedtexture != 0x0) && int(uint(c2da_mem[ds_p + 40]) | uint(c2da_mem[ds_p + 41]) << 0x8 | uint(c2da_mem[ds_p + 42]) << 0x10 | uint(c2da_mem[ds_p + 43]) << 0x18) == 0) {
        c2da_lin_memcpy(int(lastopening), 235040 + start * 2, uint64(2 * (rw_stopx - start)))
        let c2da_fresh98 : int = lastopening - start * 2
        let c2da_fresh99 : uint = uint(c2da_fresh98)
        c2da_mem[ds_p + 40] = uint8(c2da_fresh99)
        c2da_mem[ds_p + 41] = uint8(c2da_fresh99 >> 0x8)
        c2da_mem[ds_p + 42] = uint8(c2da_fresh99 >> 0x10)
        c2da_mem[ds_p + 43] = uint8(c2da_fresh99 >> 0x18)
        c2da_mem[ds_p + 44] = 0u8
        c2da_mem[ds_p + 45] = 0u8
        c2da_mem[ds_p + 46] = 0u8
        c2da_mem[ds_p + 47] = 0u8
        lastopening = lastopening + (rw_stopx - start) * 2
    }
    if (((int(uint(c2da_mem[ds_p + 28]) | uint(c2da_mem[ds_p + 29]) << 0x8 | uint(c2da_mem[ds_p + 30]) << 0x10 | uint(c2da_mem[ds_p + 31]) << 0x18) & 1) != 0 || maskedtexture != 0x0) && int(uint(c2da_mem[ds_p + 48]) | uint(c2da_mem[ds_p + 49]) << 0x8 | uint(c2da_mem[ds_p + 50]) << 0x10 | uint(c2da_mem[ds_p + 51]) << 0x18) == 0) {
        c2da_lin_memcpy(int(lastopening), 235680 + start * 2, uint64(2 * (rw_stopx - start)))
        let c2da_fresh100 : int = lastopening - start * 2
        let c2da_fresh101 : uint = uint(c2da_fresh100)
        c2da_mem[ds_p + 48] = uint8(c2da_fresh101)
        c2da_mem[ds_p + 49] = uint8(c2da_fresh101 >> 0x8)
        c2da_mem[ds_p + 50] = uint8(c2da_fresh101 >> 0x10)
        c2da_mem[ds_p + 51] = uint8(c2da_fresh101 >> 0x18)
        c2da_mem[ds_p + 52] = 0u8
        c2da_mem[ds_p + 53] = 0u8
        c2da_mem[ds_p + 54] = 0u8
        c2da_mem[ds_p + 55] = 0u8
        lastopening = lastopening + (rw_stopx - start) * 2
    }
    if (maskedtexture != 0x0 && (int(uint(c2da_mem[ds_p + 28]) | uint(c2da_mem[ds_p + 29]) << 0x8 | uint(c2da_mem[ds_p + 30]) << 0x10 | uint(c2da_mem[ds_p + 31]) << 0x18) & 2) == 0) {
        let c2da_fresh102 : int = int(uint(c2da_mem[ds_p + 28]) | uint(c2da_mem[ds_p + 29]) << 0x8 | uint(c2da_mem[ds_p + 30]) << 0x10 | uint(c2da_mem[ds_p + 31]) << 0x18) | 2
        let c2da_fresh103 : uint = uint(c2da_fresh102)
        c2da_mem[ds_p + 28] = uint8(c2da_fresh103)
        c2da_mem[ds_p + 29] = uint8(c2da_fresh103 >> 0x8)
        c2da_mem[ds_p + 30] = uint8(c2da_fresh103 >> 0x10)
        c2da_mem[ds_p + 31] = uint8(c2da_fresh103 >> 0x18)
        let c2da_fresh104 : int = -2147483647 - 1
        let c2da_fresh105 : uint = uint(c2da_fresh104)
        c2da_mem[ds_p + 36] = uint8(c2da_fresh105)
        c2da_mem[ds_p + 37] = uint8(c2da_fresh105 >> 0x8)
        c2da_mem[ds_p + 38] = uint8(c2da_fresh105 >> 0x10)
        c2da_mem[ds_p + 39] = uint8(c2da_fresh105 >> 0x18)
    }
    if (maskedtexture != 0x0 && (int(uint(c2da_mem[ds_p + 28]) | uint(c2da_mem[ds_p + 29]) << 0x8 | uint(c2da_mem[ds_p + 30]) << 0x10 | uint(c2da_mem[ds_p + 31]) << 0x18) & 1) == 0) {
        let c2da_fresh106 : int = int(uint(c2da_mem[ds_p + 28]) | uint(c2da_mem[ds_p + 29]) << 0x8 | uint(c2da_mem[ds_p + 30]) << 0x10 | uint(c2da_mem[ds_p + 31]) << 0x18) | 1
        let c2da_fresh107 : uint = uint(c2da_fresh106)
        c2da_mem[ds_p + 28] = uint8(c2da_fresh107)
        c2da_mem[ds_p + 29] = uint8(c2da_fresh107 >> 0x8)
        c2da_mem[ds_p + 30] = uint8(c2da_fresh107 >> 0x10)
        c2da_mem[ds_p + 31] = uint8(c2da_fresh107 >> 0x18)
        let c2da_fresh108 : int = 2147483647
        let c2da_fresh109 : uint = uint(c2da_fresh108)
        c2da_mem[ds_p + 32] = uint8(c2da_fresh109)
        c2da_mem[ds_p + 33] = uint8(c2da_fresh109 >> 0x8)
        c2da_mem[ds_p + 34] = uint8(c2da_fresh109 >> 0x10)
        c2da_mem[ds_p + 35] = uint8(c2da_fresh109 >> 0x18)
    }
    ds_p = ds_p + 64
    return
}

// This unit's static data, at heap offset 362640.
let private c2da_lin_static_r_segs_seg = fixed_array<int>(362640, 31)
let private c2da_lin_static_r_segs = fixed_array<uint64>(0x65525f5220646142ul, 0x6c6c61577265646eul, 0x25203a65676e6152ul, 0x6925206f742069ul)

[init]
def private c2da_lin_init_static_r_segs() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_r_segs_seg[s * 2]
        for (k in range(c2da_lin_static_r_segs_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_r_segs[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
