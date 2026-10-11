[sideeffects]
def private c2da___bswap_16_15(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_15(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_15(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_15(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_15(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_15(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
var numsprites : int = default<int>

var sprites : int = default<int>

var vissprite_p : int = default<int>

var mfloorclip : int = default<int>

var mceilingclip : int = default<int>

var spryscale : int = default<int>

var sprtopscreen : int = default<int>

var pspritescale : int = default<int>

var pspriteiscale : int = default<int>

[export, sideeffects]
def R_DrawMaskedColumn(var column : int) {
    var topscreen : int
    var bottomscreen : int
    var basetexturemid : int = dc_texturemid
    while (int(c2da_mem[column]) != 255) {
        topscreen = sprtopscreen + spryscale * int(c2da_mem[column])
        bottomscreen = topscreen + spryscale * int(c2da_mem[column + 1])
        dc_yl = topscreen + (1 << 16) - 1 >> 16
        dc_yh = bottomscreen - 1 >> 16
        if (dc_yh >= int(int16(uint(c2da_mem[mfloorclip + int(dc_x) * 2]) | uint(c2da_mem[mfloorclip + int(dc_x) * 2 + 1]) << 0x8))) {
            dc_yh = int(int16(uint(c2da_mem[mfloorclip + int(dc_x) * 2]) | uint(c2da_mem[mfloorclip + int(dc_x) * 2 + 1]) << 0x8)) - 1
        }
        if (dc_yl <= int(int16(uint(c2da_mem[mceilingclip + int(dc_x) * 2]) | uint(c2da_mem[mceilingclip + int(dc_x) * 2 + 1]) << 0x8))) {
            dc_yl = int(int16(uint(c2da_mem[mceilingclip + int(dc_x) * 2]) | uint(c2da_mem[mceilingclip + int(dc_x) * 2 + 1]) << 0x8)) + 1
        }
        if (dc_yl <= dc_yh) {
            dc_source = column + 3
            dc_texturemid = basetexturemid - (int(c2da_mem[column]) << 16)
            invoke(c2da_fn_table0[colfunc])
        }
        column = column + int(c2da_mem[column + 1]) + 4
    }
    dc_texturemid = basetexturemid
    return
}
[export, sideeffects]
def R_SortVisSprites() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_SortVisSprites_c2da_frame(c2da_lin_enter(80))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_AddSprites(var sec : int) {
    var thing : int
    var lightnum : int
    if (int(uint(c2da_mem[sec + 88]) | uint(c2da_mem[sec + 89]) << 0x8 | uint(c2da_mem[sec + 90]) << 0x10 | uint(c2da_mem[sec + 91]) << 0x18) == validcount) {
        return
    }
    let c2da_fresh26 : uint = uint(validcount)
    c2da_mem[sec + 88] = uint8(c2da_fresh26)
    c2da_mem[sec + 89] = uint8(c2da_fresh26 >> 0x8)
    c2da_mem[sec + 90] = uint8(c2da_fresh26 >> 0x10)
    c2da_mem[sec + 91] = uint8(c2da_fresh26 >> 0x18)
    lightnum = (int(int16(uint(c2da_mem[sec + 12]) | uint(c2da_mem[sec + 13]) << 0x8)) >> 4) + extralight
    if (lightnum < 0) {
        spritelights = 227616 + 0 * 384
    } elif (lightnum >= 16) {
        spritelights = 227616 + (16 - 1) * 384
    } else {
        spritelights = 227616 + lightnum * 384
    }
    thing = int(uint(c2da_mem[sec + 96]) | uint(c2da_mem[sec + 97]) << 0x8 | uint(c2da_mem[sec + 98]) << 0x10 | uint(c2da_mem[sec + 99]) << 0x18)
    while (thing != 0) {
        R_ProjectSprite(thing)
        thing = int(uint(c2da_mem[thing + 40]) | uint(c2da_mem[thing + 41]) << 0x8 | uint(c2da_mem[thing + 42]) << 0x10 | uint(c2da_mem[thing + 43]) << 0x18)
    }
    return
}
[export, sideeffects]
def R_ProjectSprite(var thing_0 : int) {
    var tr_x : int
    var tr_y : int
    var gxt : int
    var gyt : int
    var tx : int
    var tz : int
    var xscale : int
    var x1 : int
    var x2 : int
    var sprdef : int
    var sprframe : int
    var lump : int
    var rot : uint
    var flip : uint
    var index : int
    var vis : int
    var ang : uint
    var iscale : int
    tr_x = int(uint(c2da_mem[thing_0 + 24]) | uint(c2da_mem[thing_0 + 25]) << 0x8 | uint(c2da_mem[thing_0 + 26]) << 0x10 | uint(c2da_mem[thing_0 + 27]) << 0x18) - viewx
    tr_y = int(uint(c2da_mem[thing_0 + 28]) | uint(c2da_mem[thing_0 + 29]) << 0x8 | uint(c2da_mem[thing_0 + 30]) << 0x10 | uint(c2da_mem[thing_0 + 31]) << 0x18) - viewy
    gxt = FixedMul(tr_x, viewcos)
    gyt = -FixedMul(tr_y, viewsin)
    tz = gxt - gyt
    if (tz < (1 << 16) * 4) {
        return
    }
    xscale = FixedDiv(projection, tz)
    gxt = -FixedMul(tr_x, viewsin)
    gyt = FixedMul(tr_y, viewcos)
    tx = -(gyt + gxt)
    if (c2da_std_abs(tx) > tz << 2) {
        return
    }
    if ((uint(c2da_mem[thing_0 + 60]) | uint(c2da_mem[thing_0 + 61]) << 0x8 | uint(c2da_mem[thing_0 + 62]) << 0x10 | uint(c2da_mem[thing_0 + 63]) << 0x18) >= uint(numsprites)) {
        I_Error(363952, [C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[thing_0 + 60]) | uint(c2da_mem[thing_0 + 61]) << 0x8 | uint(c2da_mem[thing_0 + 62]) << 0x10 | uint(c2da_mem[thing_0 + 63]) << 0x18), f64 = 0.0lf, raw = 0x0)])
    }
    sprdef = sprites + int(uint(c2da_mem[thing_0 + 60]) | uint(c2da_mem[thing_0 + 61]) << 0x8 | uint(c2da_mem[thing_0 + 62]) << 0x10 | uint(c2da_mem[thing_0 + 63]) << 0x18) * 16
    if ((int(uint(c2da_mem[thing_0 + 64]) | uint(c2da_mem[thing_0 + 65]) << 0x8 | uint(c2da_mem[thing_0 + 66]) << 0x10 | uint(c2da_mem[thing_0 + 67]) << 0x18) & 32767) >= int(uint(c2da_mem[sprdef]) | uint(c2da_mem[sprdef + 1]) << 0x8 | uint(c2da_mem[sprdef + 2]) << 0x10 | uint(c2da_mem[sprdef + 3]) << 0x18)) {
        I_Error(363995, [C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[thing_0 + 60]) | uint(c2da_mem[thing_0 + 61]) << 0x8 | uint(c2da_mem[thing_0 + 62]) << 0x10 | uint(c2da_mem[thing_0 + 63]) << 0x18), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[thing_0 + 64]) | uint(c2da_mem[thing_0 + 65]) << 0x8 | uint(c2da_mem[thing_0 + 66]) << 0x10 | uint(c2da_mem[thing_0 + 67]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
    }
    sprframe = int(uint(c2da_mem[sprdef + 8]) | uint(c2da_mem[sprdef + 9]) << 0x8 | uint(c2da_mem[sprdef + 10]) << 0x10 | uint(c2da_mem[sprdef + 11]) << 0x18) + (int(uint(c2da_mem[thing_0 + 64]) | uint(c2da_mem[thing_0 + 65]) << 0x8 | uint(c2da_mem[thing_0 + 66]) << 0x10 | uint(c2da_mem[thing_0 + 67]) << 0x18) & 32767) * 28
    if ((uint(c2da_mem[sprframe]) | uint(c2da_mem[sprframe + 1]) << 0x8 | uint(c2da_mem[sprframe + 2]) << 0x10 | uint(c2da_mem[sprframe + 3]) << 0x18) != 0x0) {
        ang = uint(R_PointToAngle(int(uint(c2da_mem[thing_0 + 24]) | uint(c2da_mem[thing_0 + 25]) << 0x8 | uint(c2da_mem[thing_0 + 26]) << 0x10 | uint(c2da_mem[thing_0 + 27]) << 0x18), int(uint(c2da_mem[thing_0 + 28]) | uint(c2da_mem[thing_0 + 29]) << 0x8 | uint(c2da_mem[thing_0 + 30]) << 0x10 | uint(c2da_mem[thing_0 + 31]) << 0x18)))
        rot = ang - (uint(c2da_mem[thing_0 + 56]) | uint(c2da_mem[thing_0 + 57]) << 0x8 | uint(c2da_mem[thing_0 + 58]) << 0x10 | uint(c2da_mem[thing_0 + 59]) << 0x18) + uint(536870912 / 2) * 9u >> 29u
        lump = int(int16(uint(c2da_mem[sprframe + 4 + int(rot) * 2]) | uint(c2da_mem[sprframe + 4 + int(rot) * 2 + 1]) << 0x8))
        flip = uint(c2da_mem[sprframe + 20 + int(rot)])
    } else {
        lump = int(int16(uint(c2da_mem[sprframe + 4 + 0 * 2]) | uint(c2da_mem[sprframe + 4 + 0 * 2 + 1]) << 0x8))
        flip = uint(c2da_mem[sprframe + 20 + 0])
    }
    tx -= int(uint(c2da_mem[spriteoffset + lump * 4]) | uint(c2da_mem[spriteoffset + lump * 4 + 1]) << 0x8 | uint(c2da_mem[spriteoffset + lump * 4 + 2]) << 0x10 | uint(c2da_mem[spriteoffset + lump * 4 + 3]) << 0x18)
    x1 = centerxfrac + FixedMul(tx, xscale) >> 16
    if (x1 > viewwidth) {
        return
    }
    tx += int(uint(c2da_mem[spritewidth + lump * 4]) | uint(c2da_mem[spritewidth + lump * 4 + 1]) << 0x8 | uint(c2da_mem[spritewidth + lump * 4 + 2]) << 0x10 | uint(c2da_mem[spritewidth + lump * 4 + 3]) << 0x18)
    x2 = (centerxfrac + FixedMul(tx, xscale) >> 16) - 1
    if (x2 < 0) {
        return
    }
    vis = R_NewVisSprite()
    let c2da_fresh27 : int = int(uint(c2da_mem[thing_0 + 160]) | uint(c2da_mem[thing_0 + 161]) << 0x8 | uint(c2da_mem[thing_0 + 162]) << 0x10 | uint(c2da_mem[thing_0 + 163]) << 0x18)
    let c2da_fresh28 : uint = uint(c2da_fresh27)
    c2da_mem[vis + 72] = uint8(c2da_fresh28)
    c2da_mem[vis + 73] = uint8(c2da_fresh28 >> 0x8)
    c2da_mem[vis + 74] = uint8(c2da_fresh28 >> 0x10)
    c2da_mem[vis + 75] = uint8(c2da_fresh28 >> 0x18)
    let c2da_fresh29 : int = xscale << detailshift
    let c2da_fresh30 : uint = uint(c2da_fresh29)
    c2da_mem[vis + 44] = uint8(c2da_fresh30)
    c2da_mem[vis + 45] = uint8(c2da_fresh30 >> 0x8)
    c2da_mem[vis + 46] = uint8(c2da_fresh30 >> 0x10)
    c2da_mem[vis + 47] = uint8(c2da_fresh30 >> 0x18)
    let c2da_fresh31 : int = int(uint(c2da_mem[thing_0 + 24]) | uint(c2da_mem[thing_0 + 25]) << 0x8 | uint(c2da_mem[thing_0 + 26]) << 0x10 | uint(c2da_mem[thing_0 + 27]) << 0x18)
    let c2da_fresh32 : uint = uint(c2da_fresh31)
    c2da_mem[vis + 24] = uint8(c2da_fresh32)
    c2da_mem[vis + 25] = uint8(c2da_fresh32 >> 0x8)
    c2da_mem[vis + 26] = uint8(c2da_fresh32 >> 0x10)
    c2da_mem[vis + 27] = uint8(c2da_fresh32 >> 0x18)
    let c2da_fresh33 : int = int(uint(c2da_mem[thing_0 + 28]) | uint(c2da_mem[thing_0 + 29]) << 0x8 | uint(c2da_mem[thing_0 + 30]) << 0x10 | uint(c2da_mem[thing_0 + 31]) << 0x18)
    let c2da_fresh34 : uint = uint(c2da_fresh33)
    c2da_mem[vis + 28] = uint8(c2da_fresh34)
    c2da_mem[vis + 29] = uint8(c2da_fresh34 >> 0x8)
    c2da_mem[vis + 30] = uint8(c2da_fresh34 >> 0x10)
    c2da_mem[vis + 31] = uint8(c2da_fresh34 >> 0x18)
    let c2da_fresh35 : int = int(uint(c2da_mem[thing_0 + 32]) | uint(c2da_mem[thing_0 + 33]) << 0x8 | uint(c2da_mem[thing_0 + 34]) << 0x10 | uint(c2da_mem[thing_0 + 35]) << 0x18)
    let c2da_fresh36 : uint = uint(c2da_fresh35)
    c2da_mem[vis + 32] = uint8(c2da_fresh36)
    c2da_mem[vis + 33] = uint8(c2da_fresh36 >> 0x8)
    c2da_mem[vis + 34] = uint8(c2da_fresh36 >> 0x10)
    c2da_mem[vis + 35] = uint8(c2da_fresh36 >> 0x18)
    let c2da_fresh37 : int = int(uint(c2da_mem[thing_0 + 32]) | uint(c2da_mem[thing_0 + 33]) << 0x8 | uint(c2da_mem[thing_0 + 34]) << 0x10 | uint(c2da_mem[thing_0 + 35]) << 0x18) + int(uint(c2da_mem[spritetopoffset + lump * 4]) | uint(c2da_mem[spritetopoffset + lump * 4 + 1]) << 0x8 | uint(c2da_mem[spritetopoffset + lump * 4 + 2]) << 0x10 | uint(c2da_mem[spritetopoffset + lump * 4 + 3]) << 0x18)
    let c2da_fresh38 : uint = uint(c2da_fresh37)
    c2da_mem[vis + 36] = uint8(c2da_fresh38)
    c2da_mem[vis + 37] = uint8(c2da_fresh38 >> 0x8)
    c2da_mem[vis + 38] = uint8(c2da_fresh38 >> 0x10)
    c2da_mem[vis + 39] = uint8(c2da_fresh38 >> 0x18)
    let c2da_fresh39 : int = int(uint(c2da_mem[vis + 36]) | uint(c2da_mem[vis + 37]) << 0x8 | uint(c2da_mem[vis + 38]) << 0x10 | uint(c2da_mem[vis + 39]) << 0x18) - viewz
    let c2da_fresh40 : uint = uint(c2da_fresh39)
    c2da_mem[vis + 52] = uint8(c2da_fresh40)
    c2da_mem[vis + 53] = uint8(c2da_fresh40 >> 0x8)
    c2da_mem[vis + 54] = uint8(c2da_fresh40 >> 0x10)
    c2da_mem[vis + 55] = uint8(c2da_fresh40 >> 0x18)
    let c2da_fresh41 : int = x1 < 0 ? 0 : x1
    let c2da_fresh42 : uint = uint(c2da_fresh41)
    c2da_mem[vis + 16] = uint8(c2da_fresh42)
    c2da_mem[vis + 17] = uint8(c2da_fresh42 >> 0x8)
    c2da_mem[vis + 18] = uint8(c2da_fresh42 >> 0x10)
    c2da_mem[vis + 19] = uint8(c2da_fresh42 >> 0x18)
    let c2da_fresh43 : int = x2 >= viewwidth ? viewwidth - 1 : x2
    let c2da_fresh44 : uint = uint(c2da_fresh43)
    c2da_mem[vis + 20] = uint8(c2da_fresh44)
    c2da_mem[vis + 21] = uint8(c2da_fresh44 >> 0x8)
    c2da_mem[vis + 22] = uint8(c2da_fresh44 >> 0x10)
    c2da_mem[vis + 23] = uint8(c2da_fresh44 >> 0x18)
    iscale = FixedDiv(1 << 16, xscale)
    if (flip != 0x0) {
        let c2da_fresh45 : int = int(uint(c2da_mem[spritewidth + lump * 4]) | uint(c2da_mem[spritewidth + lump * 4 + 1]) << 0x8 | uint(c2da_mem[spritewidth + lump * 4 + 2]) << 0x10 | uint(c2da_mem[spritewidth + lump * 4 + 3]) << 0x18) - 1
        let c2da_fresh46 : uint = uint(c2da_fresh45)
        c2da_mem[vis + 40] = uint8(c2da_fresh46)
        c2da_mem[vis + 41] = uint8(c2da_fresh46 >> 0x8)
        c2da_mem[vis + 42] = uint8(c2da_fresh46 >> 0x10)
        c2da_mem[vis + 43] = uint8(c2da_fresh46 >> 0x18)
        let c2da_fresh47 : int = -iscale
        let c2da_fresh48 : uint = uint(c2da_fresh47)
        c2da_mem[vis + 48] = uint8(c2da_fresh48)
        c2da_mem[vis + 49] = uint8(c2da_fresh48 >> 0x8)
        c2da_mem[vis + 50] = uint8(c2da_fresh48 >> 0x10)
        c2da_mem[vis + 51] = uint8(c2da_fresh48 >> 0x18)
    } else {
        let c2da_fresh49 : int = 0
        let c2da_fresh50 : uint = uint(c2da_fresh49)
        c2da_mem[vis + 40] = uint8(c2da_fresh50)
        c2da_mem[vis + 41] = uint8(c2da_fresh50 >> 0x8)
        c2da_mem[vis + 42] = uint8(c2da_fresh50 >> 0x10)
        c2da_mem[vis + 43] = uint8(c2da_fresh50 >> 0x18)
        let c2da_fresh51 : uint = uint(iscale)
        c2da_mem[vis + 48] = uint8(c2da_fresh51)
        c2da_mem[vis + 49] = uint8(c2da_fresh51 >> 0x8)
        c2da_mem[vis + 50] = uint8(c2da_fresh51 >> 0x10)
        c2da_mem[vis + 51] = uint8(c2da_fresh51 >> 0x18)
    }
    if (int(uint(c2da_mem[vis + 16]) | uint(c2da_mem[vis + 17]) << 0x8 | uint(c2da_mem[vis + 18]) << 0x10 | uint(c2da_mem[vis + 19]) << 0x18) > x1) {
        let c2da_fresh52 : int = int(uint(c2da_mem[vis + 40]) | uint(c2da_mem[vis + 41]) << 0x8 | uint(c2da_mem[vis + 42]) << 0x10 | uint(c2da_mem[vis + 43]) << 0x18) + int(uint(c2da_mem[vis + 48]) | uint(c2da_mem[vis + 49]) << 0x8 | uint(c2da_mem[vis + 50]) << 0x10 | uint(c2da_mem[vis + 51]) << 0x18) * (int(uint(c2da_mem[vis + 16]) | uint(c2da_mem[vis + 17]) << 0x8 | uint(c2da_mem[vis + 18]) << 0x10 | uint(c2da_mem[vis + 19]) << 0x18) - x1)
        let c2da_fresh53 : uint = uint(c2da_fresh52)
        c2da_mem[vis + 40] = uint8(c2da_fresh53)
        c2da_mem[vis + 41] = uint8(c2da_fresh53 >> 0x8)
        c2da_mem[vis + 42] = uint8(c2da_fresh53 >> 0x10)
        c2da_mem[vis + 43] = uint8(c2da_fresh53 >> 0x18)
    }
    let c2da_fresh54 : uint = uint(lump)
    c2da_mem[vis + 56] = uint8(c2da_fresh54)
    c2da_mem[vis + 57] = uint8(c2da_fresh54 >> 0x8)
    c2da_mem[vis + 58] = uint8(c2da_fresh54 >> 0x10)
    c2da_mem[vis + 59] = uint8(c2da_fresh54 >> 0x18)
    if ((int(uint(c2da_mem[thing_0 + 160]) | uint(c2da_mem[thing_0 + 161]) << 0x8 | uint(c2da_mem[thing_0 + 162]) << 0x10 | uint(c2da_mem[thing_0 + 163]) << 0x18) & 262144) != 0) {
        let c2da_fresh55 : uint = 0u
        c2da_mem[vis + 64] = uint8(c2da_fresh55)
        c2da_mem[vis + 65] = uint8(c2da_fresh55 >> 0x8)
        c2da_mem[vis + 66] = uint8(c2da_fresh55 >> 0x10)
        c2da_mem[vis + 67] = uint8(c2da_fresh55 >> 0x18)
        c2da_mem[vis + 68] = 0u8
        c2da_mem[vis + 69] = 0u8
        c2da_mem[vis + 70] = 0u8
        c2da_mem[vis + 71] = 0u8
    } elif (fixedcolormap != 0) {
        let c2da_fresh56 : uint = uint(fixedcolormap)
        c2da_mem[vis + 64] = uint8(c2da_fresh56)
        c2da_mem[vis + 65] = uint8(c2da_fresh56 >> 0x8)
        c2da_mem[vis + 66] = uint8(c2da_fresh56 >> 0x10)
        c2da_mem[vis + 67] = uint8(c2da_fresh56 >> 0x18)
        c2da_mem[vis + 68] = 0u8
        c2da_mem[vis + 69] = 0u8
        c2da_mem[vis + 70] = 0u8
        c2da_mem[vis + 71] = 0u8
    } elif ((int(uint(c2da_mem[thing_0 + 64]) | uint(c2da_mem[thing_0 + 65]) << 0x8 | uint(c2da_mem[thing_0 + 66]) << 0x10 | uint(c2da_mem[thing_0 + 67]) << 0x18) & 32768) != 0) {
        let c2da_fresh57 : uint = uint(colormaps)
        c2da_mem[vis + 64] = uint8(c2da_fresh57)
        c2da_mem[vis + 65] = uint8(c2da_fresh57 >> 0x8)
        c2da_mem[vis + 66] = uint8(c2da_fresh57 >> 0x10)
        c2da_mem[vis + 67] = uint8(c2da_fresh57 >> 0x18)
        c2da_mem[vis + 68] = 0u8
        c2da_mem[vis + 69] = 0u8
        c2da_mem[vis + 70] = 0u8
        c2da_mem[vis + 71] = 0u8
    } else {
        index = xscale >> 12 - detailshift
        if (index >= 48) {
            index = 48 - 1
        }
        let c2da_fresh58 : int = int(uint(c2da_mem[spritelights + index * 8]) | uint(c2da_mem[spritelights + index * 8 + 1]) << 0x8 | uint(c2da_mem[spritelights + index * 8 + 2]) << 0x10 | uint(c2da_mem[spritelights + index * 8 + 3]) << 0x18)
        let c2da_fresh59 : uint = uint(c2da_fresh58)
        c2da_mem[vis + 64] = uint8(c2da_fresh59)
        c2da_mem[vis + 65] = uint8(c2da_fresh59 >> 0x8)
        c2da_mem[vis + 66] = uint8(c2da_fresh59 >> 0x10)
        c2da_mem[vis + 67] = uint8(c2da_fresh59 >> 0x18)
        c2da_mem[vis + 68] = 0u8
        c2da_mem[vis + 69] = 0u8
        c2da_mem[vis + 70] = 0u8
        c2da_mem[vis + 71] = 0u8
    }
    return
}
var spritelights : int = default<int>

[export, sideeffects]
def R_NewVisSprite() : int {
    if (vissprite_p == 236320 + 128 * 80) {
        return 246640
    }
    vissprite_p += 80
    return vissprite_p - 1 * 80
}
[export, sideeffects]
def R_InitSprites(var namelist : int) {
    for (i_0 in range(0, 320)) {
        let c2da_fresh60 : int16 = int16(-1)
        let c2da_fresh61 : uint = uint(c2da_fresh60)
        c2da_mem[234400 + i_0 * 2] = uint8(c2da_fresh61)
        c2da_mem[234400 + i_0 * 2 + 1] = uint8(c2da_fresh61 >> 0x8)
    }
    R_InitSpriteDefs(namelist)
    return
}
[export, sideeffects]
def R_InitSpriteDefs(var namelist_0 : int) {
    var c2da_fresh64 : int
    var check : int
    var i_1 : int
    var frame : int
    var rotation : int
    var start : int
    var end : int
    var patched : int
    check = namelist_0
    while (int(uint(c2da_mem[check]) | uint(c2da_mem[check + 1]) << 0x8 | uint(c2da_mem[check + 2]) << 0x10 | uint(c2da_mem[check + 3]) << 0x18) != 0) {
        check += 8
    }
    numsprites = (check - namelist_0) / 8
    if (numsprites == 0) {
        return
    }
    sprites = Z_Malloc(int(uint64(numsprites) * 16ul), 1, 0)
    start = firstspritelump - 1
    end = lastspritelump + 1
    i_1 = 0
    while (i_1 < numsprites) {
        spritename = int(uint(c2da_mem[namelist_0 + i_1 * 8]) | uint(c2da_mem[namelist_0 + i_1 * 8 + 1]) << 0x8 | uint(c2da_mem[namelist_0 + i_1 * 8 + 2]) << 0x10 | uint(c2da_mem[namelist_0 + i_1 * 8 + 3]) << 0x18)
        c2da_lin_memset(246720, -1, 812ul)
        maxframe = -1
        for (l in range(start + 1, end)) {
            if (c2da_lin_strncasecmp(int(lumpinfo + l * 40), spritename, 4ul) == 0) {
                frame = int(int8(c2da_mem[lumpinfo + l * 40 + 4])) - 65
                rotation = int(int8(c2da_mem[lumpinfo + l * 40 + 5])) - 48
                if (modifiedgame != 0x0) {
                    patched = W_GetNumForName(lumpinfo + l * 40)
                } else {
                    patched = l
                }
                R_InstallSpriteLump(patched, uint(frame), uint(rotation), 0u)
                if (int8(c2da_mem[lumpinfo + l * 40 + 6]) != 0) {
                    frame = int(int8(c2da_mem[lumpinfo + l * 40 + 6])) - 65
                    rotation = int(int8(c2da_mem[lumpinfo + l * 40 + 7])) - 48
                    R_InstallSpriteLump(l, uint(frame), uint(rotation), 1u)
                }
            }
        }
        if (maxframe == -1) {
            let c2da_fresh62 : int = 0
            let c2da_fresh63 : uint = uint(c2da_fresh62)
            c2da_mem[sprites + i_1 * 16] = uint8(c2da_fresh63)
            c2da_mem[sprites + i_1 * 16 + 1] = uint8(c2da_fresh63 >> 0x8)
            c2da_mem[sprites + i_1 * 16 + 2] = uint8(c2da_fresh63 >> 0x10)
            c2da_mem[sprites + i_1 * 16 + 3] = uint8(c2da_fresh63 >> 0x18)
            i_1++
            continue
        }
        maxframe++
        frame = 0
        while (frame < maxframe) {
            c2da_fresh64 = int(uint(c2da_mem[246720 + frame * 28]) | uint(c2da_mem[246720 + frame * 28 + 1]) << 0x8 | uint(c2da_mem[246720 + frame * 28 + 2]) << 0x10 | uint(c2da_mem[246720 + frame * 28 + 3]) << 0x18)
            if (c2da_fresh64 == -1) {
                I_Error(364042, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(spritename)), C2daVaArg(tag = 1, i64 = int64(frame + 65), f64 = 0.0lf, raw = 0x0)])
            } elif (c2da_fresh64 == 0) {
            } elif (c2da_fresh64 == 1) {
                rotation = 0
                while (rotation < 8) {
                    if (int(int16(uint(c2da_mem[246720 + frame * 28 + 4 + rotation * 2]) | uint(c2da_mem[246720 + frame * 28 + 4 + rotation * 2 + 1]) << 0x8)) == -1) {
                        I_Error(364090, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(spritename)), C2daVaArg(tag = 1, i64 = int64(frame + 65), f64 = 0.0lf, raw = 0x0)])
                    }
                    rotation++
                }
            }
            frame++
        }
        let c2da_fresh65 : uint = uint(maxframe)
        c2da_mem[sprites + i_1 * 16] = uint8(c2da_fresh65)
        c2da_mem[sprites + i_1 * 16 + 1] = uint8(c2da_fresh65 >> 0x8)
        c2da_mem[sprites + i_1 * 16 + 2] = uint8(c2da_fresh65 >> 0x10)
        c2da_mem[sprites + i_1 * 16 + 3] = uint8(c2da_fresh65 >> 0x18)
        let c2da_fresh66 : int = Z_Malloc(int(uint64(maxframe) * 28ul), 1, 0)
        let c2da_fresh67 : uint = uint(c2da_fresh66)
        c2da_mem[sprites + i_1 * 16 + 8] = uint8(c2da_fresh67)
        c2da_mem[sprites + i_1 * 16 + 9] = uint8(c2da_fresh67 >> 0x8)
        c2da_mem[sprites + i_1 * 16 + 10] = uint8(c2da_fresh67 >> 0x10)
        c2da_mem[sprites + i_1 * 16 + 11] = uint8(c2da_fresh67 >> 0x18)
        c2da_mem[sprites + i_1 * 16 + 12] = 0u8
        c2da_mem[sprites + i_1 * 16 + 13] = 0u8
        c2da_mem[sprites + i_1 * 16 + 14] = 0u8
        c2da_mem[sprites + i_1 * 16 + 15] = 0u8
        c2da_lin_memcpy(int(uint(c2da_mem[sprites + i_1 * 16 + 8]) | uint(c2da_mem[sprites + i_1 * 16 + 9]) << 0x8 | uint(c2da_mem[sprites + i_1 * 16 + 10]) << 0x10 | uint(c2da_mem[sprites + i_1 * 16 + 11]) << 0x18), 246720, uint64(maxframe) * 28ul)
        i_1++
    }
    return
}
var maxframe : int = default<int>

var spritename : int = default<int>

[export, sideeffects]
def R_InstallSpriteLump(var lump_0 : int; var frame_0 : uint; var rotation_0 : uint; var flipped : uint) {
    if (frame_0 >= 29u || rotation_0 > 8u) {
        I_Error(364145, [C2daVaArg(tag = 1, i64 = int64(lump_0), f64 = 0.0lf, raw = 0x0)])
    }
    if (int(frame_0) > maxframe) {
        maxframe = int(frame_0)
    }
    if (rotation_0 == 0u) {
        if ((uint(c2da_mem[246720 + int(frame_0) * 28]) | uint(c2da_mem[246720 + int(frame_0) * 28 + 1]) << 0x8 | uint(c2da_mem[246720 + int(frame_0) * 28 + 2]) << 0x10 | uint(c2da_mem[246720 + int(frame_0) * 28 + 3]) << 0x18) == 0u) {
            I_Error(364198, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(spritename)), C2daVaArg(tag = 1, i64 = int64(65u + frame_0), f64 = 0.0lf, raw = 0x0)])
        }
        if ((uint(c2da_mem[246720 + int(frame_0) * 28]) | uint(c2da_mem[246720 + int(frame_0) * 28 + 1]) << 0x8 | uint(c2da_mem[246720 + int(frame_0) * 28 + 2]) << 0x10 | uint(c2da_mem[246720 + int(frame_0) * 28 + 3]) << 0x18) == 1u) {
            I_Error(364254, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(spritename)), C2daVaArg(tag = 1, i64 = int64(65u + frame_0), f64 = 0.0lf, raw = 0x0)])
        }
        let c2da_fresh68 : uint = 0u
        let c2da_fresh69 : uint = c2da_fresh68
        c2da_mem[246720 + int(frame_0) * 28] = uint8(c2da_fresh69)
        c2da_mem[246720 + int(frame_0) * 28 + 1] = uint8(c2da_fresh69 >> 0x8)
        c2da_mem[246720 + int(frame_0) * 28 + 2] = uint8(c2da_fresh69 >> 0x10)
        c2da_mem[246720 + int(frame_0) * 28 + 3] = uint8(c2da_fresh69 >> 0x18)
        for (r in range(0, 8)) {
            let c2da_fresh70 : int16 = int16(lump_0 - firstspritelump)
            let c2da_fresh71 : uint = uint(c2da_fresh70)
            c2da_mem[246720 + int(frame_0) * 28 + 4 + r * 2] = uint8(c2da_fresh71)
            c2da_mem[246720 + int(frame_0) * 28 + 4 + r * 2 + 1] = uint8(c2da_fresh71 >> 0x8)
            let c2da_fresh72 : uint8 = uint8(flipped)
            c2da_mem[246720 + int(frame_0) * 28 + 20 + r] = c2da_fresh72
        }
        return
    }
    if ((uint(c2da_mem[246720 + int(frame_0) * 28]) | uint(c2da_mem[246720 + int(frame_0) * 28 + 1]) << 0x8 | uint(c2da_mem[246720 + int(frame_0) * 28 + 2]) << 0x10 | uint(c2da_mem[246720 + int(frame_0) * 28 + 3]) << 0x18) == 0u) {
        I_Error(364254, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(spritename)), C2daVaArg(tag = 1, i64 = int64(65u + frame_0), f64 = 0.0lf, raw = 0x0)])
    }
    let c2da_fresh73 : uint = 1u
    let c2da_fresh74 : uint = c2da_fresh73
    c2da_mem[246720 + int(frame_0) * 28] = uint8(c2da_fresh74)
    c2da_mem[246720 + int(frame_0) * 28 + 1] = uint8(c2da_fresh74 >> 0x8)
    c2da_mem[246720 + int(frame_0) * 28 + 2] = uint8(c2da_fresh74 >> 0x10)
    c2da_mem[246720 + int(frame_0) * 28 + 3] = uint8(c2da_fresh74 >> 0x18)
    rotation_0--
    if (int(int16(uint(c2da_mem[246720 + int(frame_0) * 28 + 4 + int(rotation_0) * 2]) | uint(c2da_mem[246720 + int(frame_0) * 28 + 4 + int(rotation_0) * 2 + 1]) << 0x8)) != -1) {
        I_Error(364319, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(spritename)), C2daVaArg(tag = 1, i64 = int64(65u + frame_0), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(49u + rotation_0), f64 = 0.0lf, raw = 0x0)])
    }
    let c2da_fresh75 : int16 = int16(lump_0 - firstspritelump)
    let c2da_fresh76 : uint = uint(c2da_fresh75)
    c2da_mem[246720 + int(frame_0) * 28 + 4 + int(rotation_0) * 2] = uint8(c2da_fresh76)
    c2da_mem[246720 + int(frame_0) * 28 + 4 + int(rotation_0) * 2 + 1] = uint8(c2da_fresh76 >> 0x8)
    let c2da_fresh77 : uint8 = uint8(flipped)
    c2da_mem[246720 + int(frame_0) * 28 + 20 + int(rotation_0)] = c2da_fresh77
    return
}
[export, sideeffects]
def R_ClearSprites() {
    vissprite_p = 236320
    return
}
[export, sideeffects]
def R_DrawMasked() {
    var spr : int
    var ds_0 : int
    R_SortVisSprites()
    if (vissprite_p > 236320) {
        spr = int(uint(c2da_mem[246568]) | uint(c2da_mem[246569]) << 0x8 | uint(c2da_mem[246570]) << 0x10 | uint(c2da_mem[246571]) << 0x18)
        while (spr != 246560) {
            R_DrawSprite(spr)
            spr = int(uint(c2da_mem[spr + 8]) | uint(c2da_mem[spr + 9]) << 0x8 | uint(c2da_mem[spr + 10]) << 0x10 | uint(c2da_mem[spr + 11]) << 0x18)
        }
    }
    ds_0 = ds_p - 1 * 64
    while (ds_0 >= 67456) {
        if (int(uint(c2da_mem[ds_0 + 56]) | uint(c2da_mem[ds_0 + 57]) << 0x8 | uint(c2da_mem[ds_0 + 58]) << 0x10 | uint(c2da_mem[ds_0 + 59]) << 0x18) != 0) {
            R_RenderMaskedSegRange(ds_0, int(uint(c2da_mem[ds_0 + 8]) | uint(c2da_mem[ds_0 + 9]) << 0x8 | uint(c2da_mem[ds_0 + 10]) << 0x10 | uint(c2da_mem[ds_0 + 11]) << 0x18), int(uint(c2da_mem[ds_0 + 12]) | uint(c2da_mem[ds_0 + 13]) << 0x8 | uint(c2da_mem[ds_0 + 14]) << 0x10 | uint(c2da_mem[ds_0 + 15]) << 0x18))
        }
        ds_0 -= 64
    }
    if (viewangleoffset == 0) {
        R_DrawPlayerSprites()
    }
    return
}
[export, sideeffects]
def R_DrawPlayerSprites() {
    var i_2 : int
    var lightnum_0 : int
    var psp : int
    let c2da_fresh78 : int = int(uint(c2da_mem[viewplayer]) | uint(c2da_mem[viewplayer + 1]) << 0x8 | uint(c2da_mem[viewplayer + 2]) << 0x10 | uint(c2da_mem[viewplayer + 3]) << 0x18) + 88
    let c2da_fresh79 : int = int(uint(c2da_mem[c2da_fresh78]) | uint(c2da_mem[c2da_fresh78 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh78 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh78 + 3]) << 0x18)
    let c2da_fresh80 : int = int(uint(c2da_mem[c2da_fresh79]) | uint(c2da_mem[c2da_fresh79 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh79 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh79 + 3]) << 0x18) + 12
    lightnum_0 = (int(int16(uint(c2da_mem[c2da_fresh80]) | uint(c2da_mem[c2da_fresh80 + 1]) << 0x8)) >> 4) + extralight
    if (lightnum_0 < 0) {
        spritelights = 227616 + 0 * 384
    } elif (lightnum_0 >= 16) {
        spritelights = 227616 + (16 - 1) * 384
    } else {
        spritelights = 227616 + lightnum_0 * 384
    }
    mfloorclip = 233760
    mceilingclip = 234400
    i_2 = 0
    psp = viewplayer + 272
    while (i_2 < 2) {
        if (int(uint(c2da_mem[psp]) | uint(c2da_mem[psp + 1]) << 0x8 | uint(c2da_mem[psp + 2]) << 0x10 | uint(c2da_mem[psp + 3]) << 0x18) != 0) {
            R_DrawPSprite(psp)
        }
        i_2++
        psp += 24
    }
    return
}
[export, sideeffects]
def R_DrawPSprite(var psp_0 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    R_DrawPSprite_c2da_frame(psp_0, c2da_lin_enter(80))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_DrawVisSprite(var vis_1 : int; var x1_1 : int; var x2_1 : int) {
    var column_0 : int
    var texturecolumn : int
    var frac : int
    var patch : int = W_CacheLumpNum(int(uint(c2da_mem[vis_1 + 56]) | uint(c2da_mem[vis_1 + 57]) << 0x8 | uint(c2da_mem[vis_1 + 58]) << 0x10 | uint(c2da_mem[vis_1 + 59]) << 0x18) + firstspritelump, 8)
    dc_colormap = int(uint(c2da_mem[vis_1 + 64]) | uint(c2da_mem[vis_1 + 65]) << 0x8 | uint(c2da_mem[vis_1 + 66]) << 0x10 | uint(c2da_mem[vis_1 + 67]) << 0x18)
    if (dc_colormap == 0) {
        colfunc = fuzzcolfunc
    } elif ((int(uint(c2da_mem[vis_1 + 72]) | uint(c2da_mem[vis_1 + 73]) << 0x8 | uint(c2da_mem[vis_1 + 74]) << 0x10 | uint(c2da_mem[vis_1 + 75]) << 0x18) & 201326592) != 0) {
        colfunc = transcolfunc
        dc_translation = translationtables - 256 + ((int(uint(c2da_mem[vis_1 + 72]) | uint(c2da_mem[vis_1 + 73]) << 0x8 | uint(c2da_mem[vis_1 + 74]) << 0x10 | uint(c2da_mem[vis_1 + 75]) << 0x18) & 201326592) >> 26 - 8)
    }
    dc_iscale = c2da_std_abs(int(uint(c2da_mem[vis_1 + 48]) | uint(c2da_mem[vis_1 + 49]) << 0x8 | uint(c2da_mem[vis_1 + 50]) << 0x10 | uint(c2da_mem[vis_1 + 51]) << 0x18)) >> detailshift
    dc_texturemid = int(uint(c2da_mem[vis_1 + 52]) | uint(c2da_mem[vis_1 + 53]) << 0x8 | uint(c2da_mem[vis_1 + 54]) << 0x10 | uint(c2da_mem[vis_1 + 55]) << 0x18)
    frac = int(uint(c2da_mem[vis_1 + 40]) | uint(c2da_mem[vis_1 + 41]) << 0x8 | uint(c2da_mem[vis_1 + 42]) << 0x10 | uint(c2da_mem[vis_1 + 43]) << 0x18)
    spryscale = int(uint(c2da_mem[vis_1 + 44]) | uint(c2da_mem[vis_1 + 45]) << 0x8 | uint(c2da_mem[vis_1 + 46]) << 0x10 | uint(c2da_mem[vis_1 + 47]) << 0x18)
    sprtopscreen = centeryfrac - FixedMul(dc_texturemid, spryscale)
    dc_x = int(uint(c2da_mem[vis_1 + 16]) | uint(c2da_mem[vis_1 + 17]) << 0x8 | uint(c2da_mem[vis_1 + 18]) << 0x10 | uint(c2da_mem[vis_1 + 19]) << 0x18)
    while (dc_x <= int(uint(c2da_mem[vis_1 + 20]) | uint(c2da_mem[vis_1 + 21]) << 0x8 | uint(c2da_mem[vis_1 + 22]) << 0x10 | uint(c2da_mem[vis_1 + 23]) << 0x18)) {
        texturecolumn = frac >> 16
        if (texturecolumn < 0 || texturecolumn >= int(int16(uint(c2da_mem[patch]) | uint(c2da_mem[patch + 1]) << 0x8))) {
            I_Error(364381, [])
        }
        column_0 = patch + int(uint(c2da_mem[patch + 8 + texturecolumn * 4]) | uint(c2da_mem[patch + 8 + texturecolumn * 4 + 1]) << 0x8 | uint(c2da_mem[patch + 8 + texturecolumn * 4 + 2]) << 0x10 | uint(c2da_mem[patch + 8 + texturecolumn * 4 + 3]) << 0x18)
        R_DrawMaskedColumn(column_0)
        dc_x = dc_x + 1
        frac += int(uint(c2da_mem[vis_1 + 48]) | uint(c2da_mem[vis_1 + 49]) << 0x8 | uint(c2da_mem[vis_1 + 50]) << 0x10 | uint(c2da_mem[vis_1 + 51]) << 0x18)
    }
    colfunc = basecolfunc
    return
}
[export, sideeffects]
def R_DrawSprite(var spr_0 : int) {
    var ds_1 : int
    var x : int
    var r1 : int
    var r2 : int
    var scale : int
    var lowscale : int
    var silhouette : int
    x = int(uint(c2da_mem[spr_0 + 16]) | uint(c2da_mem[spr_0 + 17]) << 0x8 | uint(c2da_mem[spr_0 + 18]) << 0x10 | uint(c2da_mem[spr_0 + 19]) << 0x18)
    while (x <= int(uint(c2da_mem[spr_0 + 20]) | uint(c2da_mem[spr_0 + 21]) << 0x8 | uint(c2da_mem[spr_0 + 22]) << 0x10 | uint(c2da_mem[spr_0 + 23]) << 0x18)) {
        let c2da_fresh114 : int16 = int16(-2)
        let c2da_fresh115 : uint = uint(c2da_fresh114)
        c2da_mem[363312 + x * 2] = uint8(c2da_fresh115)
        c2da_mem[363312 + x * 2 + 1] = uint8(c2da_fresh115 >> 0x8)
        let c2da_fresh116 : uint = uint(c2da_fresh114)
        c2da_mem[362672 + x * 2] = uint8(c2da_fresh116)
        c2da_mem[362672 + x * 2 + 1] = uint8(c2da_fresh116 >> 0x8)
        x++
    }
    ds_1 = ds_p - 1 * 64
    while (ds_1 >= 67456) {
        if (int(uint(c2da_mem[ds_1 + 8]) | uint(c2da_mem[ds_1 + 9]) << 0x8 | uint(c2da_mem[ds_1 + 10]) << 0x10 | uint(c2da_mem[ds_1 + 11]) << 0x18) > int(uint(c2da_mem[spr_0 + 20]) | uint(c2da_mem[spr_0 + 21]) << 0x8 | uint(c2da_mem[spr_0 + 22]) << 0x10 | uint(c2da_mem[spr_0 + 23]) << 0x18) || int(uint(c2da_mem[ds_1 + 12]) | uint(c2da_mem[ds_1 + 13]) << 0x8 | uint(c2da_mem[ds_1 + 14]) << 0x10 | uint(c2da_mem[ds_1 + 15]) << 0x18) < int(uint(c2da_mem[spr_0 + 16]) | uint(c2da_mem[spr_0 + 17]) << 0x8 | uint(c2da_mem[spr_0 + 18]) << 0x10 | uint(c2da_mem[spr_0 + 19]) << 0x18) || int(uint(c2da_mem[ds_1 + 28]) | uint(c2da_mem[ds_1 + 29]) << 0x8 | uint(c2da_mem[ds_1 + 30]) << 0x10 | uint(c2da_mem[ds_1 + 31]) << 0x18) == 0 && int(uint(c2da_mem[ds_1 + 56]) | uint(c2da_mem[ds_1 + 57]) << 0x8 | uint(c2da_mem[ds_1 + 58]) << 0x10 | uint(c2da_mem[ds_1 + 59]) << 0x18) == 0) {
            ds_1 -= 64
            continue
        }
        r1 = int(int(uint(c2da_mem[ds_1 + 8]) | uint(c2da_mem[ds_1 + 9]) << 0x8 | uint(c2da_mem[ds_1 + 10]) << 0x10 | uint(c2da_mem[ds_1 + 11]) << 0x18) < int(uint(c2da_mem[spr_0 + 16]) | uint(c2da_mem[spr_0 + 17]) << 0x8 | uint(c2da_mem[spr_0 + 18]) << 0x10 | uint(c2da_mem[spr_0 + 19]) << 0x18) ? uint(c2da_mem[spr_0 + 16]) | uint(c2da_mem[spr_0 + 17]) << 0x8 | uint(c2da_mem[spr_0 + 18]) << 0x10 | uint(c2da_mem[spr_0 + 19]) << 0x18 : uint(c2da_mem[ds_1 + 8]) | uint(c2da_mem[ds_1 + 9]) << 0x8 | uint(c2da_mem[ds_1 + 10]) << 0x10 | uint(c2da_mem[ds_1 + 11]) << 0x18)
        r2 = int(int(uint(c2da_mem[ds_1 + 12]) | uint(c2da_mem[ds_1 + 13]) << 0x8 | uint(c2da_mem[ds_1 + 14]) << 0x10 | uint(c2da_mem[ds_1 + 15]) << 0x18) > int(uint(c2da_mem[spr_0 + 20]) | uint(c2da_mem[spr_0 + 21]) << 0x8 | uint(c2da_mem[spr_0 + 22]) << 0x10 | uint(c2da_mem[spr_0 + 23]) << 0x18) ? uint(c2da_mem[spr_0 + 20]) | uint(c2da_mem[spr_0 + 21]) << 0x8 | uint(c2da_mem[spr_0 + 22]) << 0x10 | uint(c2da_mem[spr_0 + 23]) << 0x18 : uint(c2da_mem[ds_1 + 12]) | uint(c2da_mem[ds_1 + 13]) << 0x8 | uint(c2da_mem[ds_1 + 14]) << 0x10 | uint(c2da_mem[ds_1 + 15]) << 0x18)
        if (int(uint(c2da_mem[ds_1 + 16]) | uint(c2da_mem[ds_1 + 17]) << 0x8 | uint(c2da_mem[ds_1 + 18]) << 0x10 | uint(c2da_mem[ds_1 + 19]) << 0x18) > int(uint(c2da_mem[ds_1 + 20]) | uint(c2da_mem[ds_1 + 21]) << 0x8 | uint(c2da_mem[ds_1 + 22]) << 0x10 | uint(c2da_mem[ds_1 + 23]) << 0x18)) {
            lowscale = int(uint(c2da_mem[ds_1 + 20]) | uint(c2da_mem[ds_1 + 21]) << 0x8 | uint(c2da_mem[ds_1 + 22]) << 0x10 | uint(c2da_mem[ds_1 + 23]) << 0x18)
            scale = int(uint(c2da_mem[ds_1 + 16]) | uint(c2da_mem[ds_1 + 17]) << 0x8 | uint(c2da_mem[ds_1 + 18]) << 0x10 | uint(c2da_mem[ds_1 + 19]) << 0x18)
        } else {
            lowscale = int(uint(c2da_mem[ds_1 + 16]) | uint(c2da_mem[ds_1 + 17]) << 0x8 | uint(c2da_mem[ds_1 + 18]) << 0x10 | uint(c2da_mem[ds_1 + 19]) << 0x18)
            scale = int(uint(c2da_mem[ds_1 + 20]) | uint(c2da_mem[ds_1 + 21]) << 0x8 | uint(c2da_mem[ds_1 + 22]) << 0x10 | uint(c2da_mem[ds_1 + 23]) << 0x18)
        }
        if (scale < int(uint(c2da_mem[spr_0 + 44]) | uint(c2da_mem[spr_0 + 45]) << 0x8 | uint(c2da_mem[spr_0 + 46]) << 0x10 | uint(c2da_mem[spr_0 + 47]) << 0x18) || lowscale < int(uint(c2da_mem[spr_0 + 44]) | uint(c2da_mem[spr_0 + 45]) << 0x8 | uint(c2da_mem[spr_0 + 46]) << 0x10 | uint(c2da_mem[spr_0 + 47]) << 0x18) && R_PointOnSegSide(int(uint(c2da_mem[spr_0 + 24]) | uint(c2da_mem[spr_0 + 25]) << 0x8 | uint(c2da_mem[spr_0 + 26]) << 0x10 | uint(c2da_mem[spr_0 + 27]) << 0x18), int(uint(c2da_mem[spr_0 + 28]) | uint(c2da_mem[spr_0 + 29]) << 0x8 | uint(c2da_mem[spr_0 + 30]) << 0x10 | uint(c2da_mem[spr_0 + 31]) << 0x18), int(uint(c2da_mem[ds_1]) | uint(c2da_mem[ds_1 + 1]) << 0x8 | uint(c2da_mem[ds_1 + 2]) << 0x10 | uint(c2da_mem[ds_1 + 3]) << 0x18)) == 0) {
            if (int(uint(c2da_mem[ds_1 + 56]) | uint(c2da_mem[ds_1 + 57]) << 0x8 | uint(c2da_mem[ds_1 + 58]) << 0x10 | uint(c2da_mem[ds_1 + 59]) << 0x18) != 0) {
                R_RenderMaskedSegRange(ds_1, r1, r2)
            }
            ds_1 -= 64
            continue
        }
        silhouette = int(uint(c2da_mem[ds_1 + 28]) | uint(c2da_mem[ds_1 + 29]) << 0x8 | uint(c2da_mem[ds_1 + 30]) << 0x10 | uint(c2da_mem[ds_1 + 31]) << 0x18)
        if (int(uint(c2da_mem[spr_0 + 32]) | uint(c2da_mem[spr_0 + 33]) << 0x8 | uint(c2da_mem[spr_0 + 34]) << 0x10 | uint(c2da_mem[spr_0 + 35]) << 0x18) >= int(uint(c2da_mem[ds_1 + 32]) | uint(c2da_mem[ds_1 + 33]) << 0x8 | uint(c2da_mem[ds_1 + 34]) << 0x10 | uint(c2da_mem[ds_1 + 35]) << 0x18)) {
            silhouette &= ~1
        }
        if (int(uint(c2da_mem[spr_0 + 36]) | uint(c2da_mem[spr_0 + 37]) << 0x8 | uint(c2da_mem[spr_0 + 38]) << 0x10 | uint(c2da_mem[spr_0 + 39]) << 0x18) <= int(uint(c2da_mem[ds_1 + 36]) | uint(c2da_mem[ds_1 + 37]) << 0x8 | uint(c2da_mem[ds_1 + 38]) << 0x10 | uint(c2da_mem[ds_1 + 39]) << 0x18)) {
            silhouette &= ~2
        }
        if (silhouette == 1) {
            x = r1
            while (x <= r2) {
                if (int(int16(uint(c2da_mem[362672 + x * 2]) | uint(c2da_mem[362672 + x * 2 + 1]) << 0x8)) == -2) {
                    let c2da_fresh117 : int = int(uint(c2da_mem[ds_1 + 48]) | uint(c2da_mem[ds_1 + 49]) << 0x8 | uint(c2da_mem[ds_1 + 50]) << 0x10 | uint(c2da_mem[ds_1 + 51]) << 0x18) + x * 2
                    let c2da_fresh118 : int16 = int16(uint(c2da_mem[c2da_fresh117]) | uint(c2da_mem[c2da_fresh117 + 1]) << 0x8)
                    let c2da_fresh119 : uint = uint(c2da_fresh118)
                    c2da_mem[362672 + x * 2] = uint8(c2da_fresh119)
                    c2da_mem[362672 + x * 2 + 1] = uint8(c2da_fresh119 >> 0x8)
                }
                x++
            }
        } elif (silhouette == 2) {
            x = r1
            while (x <= r2) {
                if (int(int16(uint(c2da_mem[363312 + x * 2]) | uint(c2da_mem[363312 + x * 2 + 1]) << 0x8)) == -2) {
                    let c2da_fresh120 : int = int(uint(c2da_mem[ds_1 + 40]) | uint(c2da_mem[ds_1 + 41]) << 0x8 | uint(c2da_mem[ds_1 + 42]) << 0x10 | uint(c2da_mem[ds_1 + 43]) << 0x18) + x * 2
                    let c2da_fresh121 : int16 = int16(uint(c2da_mem[c2da_fresh120]) | uint(c2da_mem[c2da_fresh120 + 1]) << 0x8)
                    let c2da_fresh122 : uint = uint(c2da_fresh121)
                    c2da_mem[363312 + x * 2] = uint8(c2da_fresh122)
                    c2da_mem[363312 + x * 2 + 1] = uint8(c2da_fresh122 >> 0x8)
                }
                x++
            }
        } elif (silhouette == 3) {
            x = r1
            while (x <= r2) {
                if (int(int16(uint(c2da_mem[362672 + x * 2]) | uint(c2da_mem[362672 + x * 2 + 1]) << 0x8)) == -2) {
                    let c2da_fresh123 : int = int(uint(c2da_mem[ds_1 + 48]) | uint(c2da_mem[ds_1 + 49]) << 0x8 | uint(c2da_mem[ds_1 + 50]) << 0x10 | uint(c2da_mem[ds_1 + 51]) << 0x18) + x * 2
                    let c2da_fresh124 : int16 = int16(uint(c2da_mem[c2da_fresh123]) | uint(c2da_mem[c2da_fresh123 + 1]) << 0x8)
                    let c2da_fresh125 : uint = uint(c2da_fresh124)
                    c2da_mem[362672 + x * 2] = uint8(c2da_fresh125)
                    c2da_mem[362672 + x * 2 + 1] = uint8(c2da_fresh125 >> 0x8)
                }
                if (int(int16(uint(c2da_mem[363312 + x * 2]) | uint(c2da_mem[363312 + x * 2 + 1]) << 0x8)) == -2) {
                    let c2da_fresh126 : int = int(uint(c2da_mem[ds_1 + 40]) | uint(c2da_mem[ds_1 + 41]) << 0x8 | uint(c2da_mem[ds_1 + 42]) << 0x10 | uint(c2da_mem[ds_1 + 43]) << 0x18) + x * 2
                    let c2da_fresh127 : int16 = int16(uint(c2da_mem[c2da_fresh126]) | uint(c2da_mem[c2da_fresh126 + 1]) << 0x8)
                    let c2da_fresh128 : uint = uint(c2da_fresh127)
                    c2da_mem[363312 + x * 2] = uint8(c2da_fresh128)
                    c2da_mem[363312 + x * 2 + 1] = uint8(c2da_fresh128 >> 0x8)
                }
                x++
            }
        }
        ds_1 -= 64
    }
    x = int(uint(c2da_mem[spr_0 + 16]) | uint(c2da_mem[spr_0 + 17]) << 0x8 | uint(c2da_mem[spr_0 + 18]) << 0x10 | uint(c2da_mem[spr_0 + 19]) << 0x18)
    while (x <= int(uint(c2da_mem[spr_0 + 20]) | uint(c2da_mem[spr_0 + 21]) << 0x8 | uint(c2da_mem[spr_0 + 22]) << 0x10 | uint(c2da_mem[spr_0 + 23]) << 0x18)) {
        if (int(int16(uint(c2da_mem[362672 + x * 2]) | uint(c2da_mem[362672 + x * 2 + 1]) << 0x8)) == -2) {
            let c2da_fresh129 : int16 = int16(viewheight)
            let c2da_fresh130 : uint = uint(c2da_fresh129)
            c2da_mem[362672 + x * 2] = uint8(c2da_fresh130)
            c2da_mem[362672 + x * 2 + 1] = uint8(c2da_fresh130 >> 0x8)
        }
        if (int(int16(uint(c2da_mem[363312 + x * 2]) | uint(c2da_mem[363312 + x * 2 + 1]) << 0x8)) == -2) {
            let c2da_fresh131 : int16 = int16(-1)
            let c2da_fresh132 : uint = uint(c2da_fresh131)
            c2da_mem[363312 + x * 2] = uint8(c2da_fresh132)
            c2da_mem[363312 + x * 2 + 1] = uint8(c2da_fresh132 >> 0x8)
        }
        x++
    }
    mfloorclip = 362672
    mceilingclip = 363312
    R_DrawVisSprite(spr_0, int(uint(c2da_mem[spr_0 + 16]) | uint(c2da_mem[spr_0 + 17]) << 0x8 | uint(c2da_mem[spr_0 + 18]) << 0x10 | uint(c2da_mem[spr_0 + 19]) << 0x18), int(uint(c2da_mem[spr_0 + 20]) | uint(c2da_mem[spr_0 + 21]) << 0x8 | uint(c2da_mem[spr_0 + 22]) << 0x10 | uint(c2da_mem[spr_0 + 23]) << 0x18))
    return
}
var newvissprite : int = default<int>

[sideeffects]
def private R_SortVisSprites_c2da_frame(c2da_fp : int) {
    var count : int
    var ds : int
    var best : int
    var bestscale : int
    count = (vissprite_p - 236320) / 80
    let c2da_fresh0 : uint = uint(c2da_fp)
    c2da_mem[c2da_fp] = uint8(c2da_fresh0)
    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh0 >> 0x8)
    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh0 >> 0x10)
    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh0 >> 0x18)
    c2da_mem[c2da_fp + 4] = 0u8
    c2da_mem[c2da_fp + 5] = 0u8
    c2da_mem[c2da_fp + 6] = 0u8
    c2da_mem[c2da_fp + 7] = 0u8
    let c2da_fresh1 : uint = uint(c2da_fp)
    c2da_mem[c2da_fp + 8] = uint8(c2da_fresh1)
    c2da_mem[c2da_fp + 9] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[c2da_fp + 10] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[c2da_fp + 11] = uint8(c2da_fresh1 >> 0x18)
    c2da_mem[c2da_fp + 12] = 0u8
    c2da_mem[c2da_fp + 13] = 0u8
    c2da_mem[c2da_fp + 14] = 0u8
    c2da_mem[c2da_fp + 15] = 0u8
    if (count == 0) {
        return
    }
    ds = 236320
    while (ds < vissprite_p) {
        let c2da_fresh2 : int = ds + 1 * 80
        let c2da_fresh3 : uint = uint(c2da_fresh2)
        c2da_mem[ds + 8] = uint8(c2da_fresh3)
        c2da_mem[ds + 9] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[ds + 10] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[ds + 11] = uint8(c2da_fresh3 >> 0x18)
        c2da_mem[ds + 12] = 0u8
        c2da_mem[ds + 13] = 0u8
        c2da_mem[ds + 14] = 0u8
        c2da_mem[ds + 15] = 0u8
        let c2da_fresh4 : int = ds - 1 * 80
        let c2da_fresh5 : uint = uint(c2da_fresh4)
        c2da_mem[ds] = uint8(c2da_fresh5)
        c2da_mem[ds + 1] = uint8(c2da_fresh5 >> 0x8)
        c2da_mem[ds + 2] = uint8(c2da_fresh5 >> 0x10)
        c2da_mem[ds + 3] = uint8(c2da_fresh5 >> 0x18)
        c2da_mem[ds + 4] = 0u8
        c2da_mem[ds + 5] = 0u8
        c2da_mem[ds + 6] = 0u8
        c2da_mem[ds + 7] = 0u8
        ds += 80
    }
    let c2da_fresh6 : uint = uint(c2da_fp)
    c2da_mem[236320 + 0 * 80] = uint8(c2da_fresh6)
    c2da_mem[236320 + 0 * 80 + 1] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[236320 + 0 * 80 + 2] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[236320 + 0 * 80 + 3] = uint8(c2da_fresh6 >> 0x18)
    c2da_mem[236320 + 0 * 80 + 4] = 0u8
    c2da_mem[236320 + 0 * 80 + 5] = 0u8
    c2da_mem[236320 + 0 * 80 + 6] = 0u8
    c2da_mem[236320 + 0 * 80 + 7] = 0u8
    let c2da_fresh7 : int = 236320 + 0 * 80
    let c2da_fresh8 : uint = uint(c2da_fresh7)
    c2da_mem[c2da_fp + 8] = uint8(c2da_fresh8)
    c2da_mem[c2da_fp + 9] = uint8(c2da_fresh8 >> 0x8)
    c2da_mem[c2da_fp + 10] = uint8(c2da_fresh8 >> 0x10)
    c2da_mem[c2da_fp + 11] = uint8(c2da_fresh8 >> 0x18)
    c2da_mem[c2da_fp + 12] = 0u8
    c2da_mem[c2da_fp + 13] = 0u8
    c2da_mem[c2da_fp + 14] = 0u8
    c2da_mem[c2da_fp + 15] = 0u8
    let c2da_fresh9 : uint = uint(c2da_fp)
    c2da_mem[vissprite_p - 1 * 80 + 8] = uint8(c2da_fresh9)
    c2da_mem[vissprite_p - 1 * 80 + 9] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[vissprite_p - 1 * 80 + 10] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[vissprite_p - 1 * 80 + 11] = uint8(c2da_fresh9 >> 0x18)
    c2da_mem[vissprite_p - 1 * 80 + 12] = 0u8
    c2da_mem[vissprite_p - 1 * 80 + 13] = 0u8
    c2da_mem[vissprite_p - 1 * 80 + 14] = 0u8
    c2da_mem[vissprite_p - 1 * 80 + 15] = 0u8
    let c2da_fresh10 : int = vissprite_p - 1 * 80
    let c2da_fresh11 : uint = uint(c2da_fresh10)
    c2da_mem[c2da_fp] = uint8(c2da_fresh11)
    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh11 >> 0x18)
    c2da_mem[c2da_fp + 4] = 0u8
    c2da_mem[c2da_fp + 5] = 0u8
    c2da_mem[c2da_fp + 6] = 0u8
    c2da_mem[c2da_fp + 7] = 0u8
    let c2da_fresh12 : uint = 246560u
    c2da_mem[246560] = uint8(c2da_fresh12)
    c2da_mem[246561] = uint8(c2da_fresh12 >> 0x8)
    c2da_mem[246562] = uint8(c2da_fresh12 >> 0x10)
    c2da_mem[246563] = uint8(c2da_fresh12 >> 0x18)
    c2da_mem[246564] = 0u8
    c2da_mem[246565] = 0u8
    c2da_mem[246566] = 0u8
    c2da_mem[246567] = 0u8
    let c2da_fresh13 : uint = 246560u
    c2da_mem[246568] = uint8(c2da_fresh13)
    c2da_mem[246569] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[246570] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[246571] = uint8(c2da_fresh13 >> 0x18)
    c2da_mem[246572] = 0u8
    c2da_mem[246573] = 0u8
    c2da_mem[246574] = 0u8
    c2da_mem[246575] = 0u8
    for (i in range(0, count)) {
        bestscale = 2147483647
        best = int(uint(c2da_mem[c2da_fp + 8]) | uint(c2da_mem[c2da_fp + 9]) << 0x8 | uint(c2da_mem[c2da_fp + 10]) << 0x10 | uint(c2da_mem[c2da_fp + 11]) << 0x18)
        ds = int(uint(c2da_mem[c2da_fp + 8]) | uint(c2da_mem[c2da_fp + 9]) << 0x8 | uint(c2da_mem[c2da_fp + 10]) << 0x10 | uint(c2da_mem[c2da_fp + 11]) << 0x18)
        while (ds != c2da_fp) {
            if (int(uint(c2da_mem[ds + 44]) | uint(c2da_mem[ds + 45]) << 0x8 | uint(c2da_mem[ds + 46]) << 0x10 | uint(c2da_mem[ds + 47]) << 0x18) < bestscale) {
                bestscale = int(uint(c2da_mem[ds + 44]) | uint(c2da_mem[ds + 45]) << 0x8 | uint(c2da_mem[ds + 46]) << 0x10 | uint(c2da_mem[ds + 47]) << 0x18)
                best = ds
            }
            ds = int(uint(c2da_mem[ds + 8]) | uint(c2da_mem[ds + 9]) << 0x8 | uint(c2da_mem[ds + 10]) << 0x10 | uint(c2da_mem[ds + 11]) << 0x18)
        }
        let c2da_fresh14 : int = int(uint(c2da_mem[best + 8]) | uint(c2da_mem[best + 9]) << 0x8 | uint(c2da_mem[best + 10]) << 0x10 | uint(c2da_mem[best + 11]) << 0x18)
        let c2da_fresh15 : int = int(uint(c2da_mem[best]) | uint(c2da_mem[best + 1]) << 0x8 | uint(c2da_mem[best + 2]) << 0x10 | uint(c2da_mem[best + 3]) << 0x18)
        let c2da_fresh16 : uint = uint(c2da_fresh15)
        c2da_mem[c2da_fresh14] = uint8(c2da_fresh16)
        c2da_mem[c2da_fresh14 + 1] = uint8(c2da_fresh16 >> 0x8)
        c2da_mem[c2da_fresh14 + 2] = uint8(c2da_fresh16 >> 0x10)
        c2da_mem[c2da_fresh14 + 3] = uint8(c2da_fresh16 >> 0x18)
        c2da_mem[c2da_fresh14 + 4] = 0u8
        c2da_mem[c2da_fresh14 + 5] = 0u8
        c2da_mem[c2da_fresh14 + 6] = 0u8
        c2da_mem[c2da_fresh14 + 7] = 0u8
        let c2da_fresh17 : int = int(uint(c2da_mem[best]) | uint(c2da_mem[best + 1]) << 0x8 | uint(c2da_mem[best + 2]) << 0x10 | uint(c2da_mem[best + 3]) << 0x18) + 8
        let c2da_fresh18 : int = int(uint(c2da_mem[best + 8]) | uint(c2da_mem[best + 9]) << 0x8 | uint(c2da_mem[best + 10]) << 0x10 | uint(c2da_mem[best + 11]) << 0x18)
        let c2da_fresh19 : uint = uint(c2da_fresh18)
        c2da_mem[c2da_fresh17] = uint8(c2da_fresh19)
        c2da_mem[c2da_fresh17 + 1] = uint8(c2da_fresh19 >> 0x8)
        c2da_mem[c2da_fresh17 + 2] = uint8(c2da_fresh19 >> 0x10)
        c2da_mem[c2da_fresh17 + 3] = uint8(c2da_fresh19 >> 0x18)
        c2da_mem[c2da_fresh17 + 4] = 0u8
        c2da_mem[c2da_fresh17 + 5] = 0u8
        c2da_mem[c2da_fresh17 + 6] = 0u8
        c2da_mem[c2da_fresh17 + 7] = 0u8
        let c2da_fresh20 : uint = 246560u
        c2da_mem[best + 8] = uint8(c2da_fresh20)
        c2da_mem[best + 9] = uint8(c2da_fresh20 >> 0x8)
        c2da_mem[best + 10] = uint8(c2da_fresh20 >> 0x10)
        c2da_mem[best + 11] = uint8(c2da_fresh20 >> 0x18)
        c2da_mem[best + 12] = 0u8
        c2da_mem[best + 13] = 0u8
        c2da_mem[best + 14] = 0u8
        c2da_mem[best + 15] = 0u8
        let c2da_fresh21 : int = int(uint(c2da_mem[246560]) | uint(c2da_mem[246561]) << 0x8 | uint(c2da_mem[246562]) << 0x10 | uint(c2da_mem[246563]) << 0x18)
        let c2da_fresh22 : uint = uint(c2da_fresh21)
        c2da_mem[best] = uint8(c2da_fresh22)
        c2da_mem[best + 1] = uint8(c2da_fresh22 >> 0x8)
        c2da_mem[best + 2] = uint8(c2da_fresh22 >> 0x10)
        c2da_mem[best + 3] = uint8(c2da_fresh22 >> 0x18)
        c2da_mem[best + 4] = 0u8
        c2da_mem[best + 5] = 0u8
        c2da_mem[best + 6] = 0u8
        c2da_mem[best + 7] = 0u8
        let c2da_fresh23 : int = int(uint(c2da_mem[246560]) | uint(c2da_mem[246561]) << 0x8 | uint(c2da_mem[246562]) << 0x10 | uint(c2da_mem[246563]) << 0x18) + 8
        let c2da_fresh24 : uint = uint(best)
        c2da_mem[c2da_fresh23] = uint8(c2da_fresh24)
        c2da_mem[c2da_fresh23 + 1] = uint8(c2da_fresh24 >> 0x8)
        c2da_mem[c2da_fresh23 + 2] = uint8(c2da_fresh24 >> 0x10)
        c2da_mem[c2da_fresh23 + 3] = uint8(c2da_fresh24 >> 0x18)
        c2da_mem[c2da_fresh23 + 4] = 0u8
        c2da_mem[c2da_fresh23 + 5] = 0u8
        c2da_mem[c2da_fresh23 + 6] = 0u8
        c2da_mem[c2da_fresh23 + 7] = 0u8
        let c2da_fresh25 : uint = uint(best)
        c2da_mem[246560] = uint8(c2da_fresh25)
        c2da_mem[246561] = uint8(c2da_fresh25 >> 0x8)
        c2da_mem[246562] = uint8(c2da_fresh25 >> 0x10)
        c2da_mem[246563] = uint8(c2da_fresh25 >> 0x18)
        c2da_mem[246564] = 0u8
        c2da_mem[246565] = 0u8
        c2da_mem[246566] = 0u8
        c2da_mem[246567] = 0u8
    }
    return
}
[sideeffects]
def private R_DrawPSprite_c2da_frame(var psp_0 : int; c2da_fp : int) {
    var tx_0 : int
    var x1_0 : int
    var x2_0 : int
    var sprdef_0 : int
    var sprframe_0 : int
    var lump_1 : int
    var flip_0 : uint
    var vis_0 : int
    let c2da_fresh81 : int = int(uint(c2da_mem[psp_0]) | uint(c2da_mem[psp_0 + 1]) << 0x8 | uint(c2da_mem[psp_0 + 2]) << 0x10 | uint(c2da_mem[psp_0 + 3]) << 0x18)
    if ((uint(c2da_mem[c2da_fresh81]) | uint(c2da_mem[c2da_fresh81 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh81 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh81 + 3]) << 0x18) >= uint(numsprites)) {
        let c2da_fresh82 : int = int(uint(c2da_mem[psp_0]) | uint(c2da_mem[psp_0 + 1]) << 0x8 | uint(c2da_mem[psp_0 + 2]) << 0x10 | uint(c2da_mem[psp_0 + 3]) << 0x18)
        I_Error(363952, [C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[c2da_fresh82]) | uint(c2da_mem[c2da_fresh82 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh82 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh82 + 3]) << 0x18), f64 = 0.0lf, raw = 0x0)])
    }
    let c2da_fresh83 : int = int(uint(c2da_mem[psp_0]) | uint(c2da_mem[psp_0 + 1]) << 0x8 | uint(c2da_mem[psp_0 + 2]) << 0x10 | uint(c2da_mem[psp_0 + 3]) << 0x18)
    sprdef_0 = sprites + int(uint(c2da_mem[c2da_fresh83]) | uint(c2da_mem[c2da_fresh83 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh83 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh83 + 3]) << 0x18) * 16
    let c2da_fresh84 : int = int(uint(c2da_mem[psp_0]) | uint(c2da_mem[psp_0 + 1]) << 0x8 | uint(c2da_mem[psp_0 + 2]) << 0x10 | uint(c2da_mem[psp_0 + 3]) << 0x18) + 4
    if ((int(uint(c2da_mem[c2da_fresh84]) | uint(c2da_mem[c2da_fresh84 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh84 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh84 + 3]) << 0x18) & 32767) >= int(uint(c2da_mem[sprdef_0]) | uint(c2da_mem[sprdef_0 + 1]) << 0x8 | uint(c2da_mem[sprdef_0 + 2]) << 0x10 | uint(c2da_mem[sprdef_0 + 3]) << 0x18)) {
        let c2da_fresh85 : int = int(uint(c2da_mem[psp_0]) | uint(c2da_mem[psp_0 + 1]) << 0x8 | uint(c2da_mem[psp_0 + 2]) << 0x10 | uint(c2da_mem[psp_0 + 3]) << 0x18)
        let c2da_fresh86 : int = int(uint(c2da_mem[psp_0]) | uint(c2da_mem[psp_0 + 1]) << 0x8 | uint(c2da_mem[psp_0 + 2]) << 0x10 | uint(c2da_mem[psp_0 + 3]) << 0x18) + 4
        I_Error(363995, [C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[c2da_fresh85]) | uint(c2da_mem[c2da_fresh85 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh85 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh85 + 3]) << 0x18), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[c2da_fresh86]) | uint(c2da_mem[c2da_fresh86 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh86 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh86 + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
    }
    let c2da_fresh87 : int = int(uint(c2da_mem[psp_0]) | uint(c2da_mem[psp_0 + 1]) << 0x8 | uint(c2da_mem[psp_0 + 2]) << 0x10 | uint(c2da_mem[psp_0 + 3]) << 0x18) + 4
    sprframe_0 = int(uint(c2da_mem[sprdef_0 + 8]) | uint(c2da_mem[sprdef_0 + 9]) << 0x8 | uint(c2da_mem[sprdef_0 + 10]) << 0x10 | uint(c2da_mem[sprdef_0 + 11]) << 0x18) + (int(uint(c2da_mem[c2da_fresh87]) | uint(c2da_mem[c2da_fresh87 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh87 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh87 + 3]) << 0x18) & 32767) * 28
    lump_1 = int(int16(uint(c2da_mem[sprframe_0 + 4 + 0 * 2]) | uint(c2da_mem[sprframe_0 + 4 + 0 * 2 + 1]) << 0x8))
    flip_0 = uint(c2da_mem[sprframe_0 + 20 + 0])
    tx_0 = int(uint(c2da_mem[psp_0 + 12]) | uint(c2da_mem[psp_0 + 13]) << 0x8 | uint(c2da_mem[psp_0 + 14]) << 0x10 | uint(c2da_mem[psp_0 + 15]) << 0x18) - 160 * (1 << 16)
    tx_0 -= int(uint(c2da_mem[spriteoffset + lump_1 * 4]) | uint(c2da_mem[spriteoffset + lump_1 * 4 + 1]) << 0x8 | uint(c2da_mem[spriteoffset + lump_1 * 4 + 2]) << 0x10 | uint(c2da_mem[spriteoffset + lump_1 * 4 + 3]) << 0x18)
    x1_0 = centerxfrac + FixedMul(tx_0, pspritescale) >> 16
    if (x1_0 > viewwidth) {
        return
    }
    tx_0 += int(uint(c2da_mem[spritewidth + lump_1 * 4]) | uint(c2da_mem[spritewidth + lump_1 * 4 + 1]) << 0x8 | uint(c2da_mem[spritewidth + lump_1 * 4 + 2]) << 0x10 | uint(c2da_mem[spritewidth + lump_1 * 4 + 3]) << 0x18)
    x2_0 = (centerxfrac + FixedMul(tx_0, pspritescale) >> 16) - 1
    if (x2_0 < 0) {
        return
    }
    vis_0 = c2da_fp
    let c2da_fresh88 : int = 0
    let c2da_fresh89 : uint = uint(c2da_fresh88)
    c2da_mem[vis_0 + 72] = uint8(c2da_fresh89)
    c2da_mem[vis_0 + 73] = uint8(c2da_fresh89 >> 0x8)
    c2da_mem[vis_0 + 74] = uint8(c2da_fresh89 >> 0x10)
    c2da_mem[vis_0 + 75] = uint8(c2da_fresh89 >> 0x18)
    let c2da_fresh90 : int = (100 << 16) + (1 << 16) / 2 - (int(uint(c2da_mem[psp_0 + 16]) | uint(c2da_mem[psp_0 + 17]) << 0x8 | uint(c2da_mem[psp_0 + 18]) << 0x10 | uint(c2da_mem[psp_0 + 19]) << 0x18) - int(uint(c2da_mem[spritetopoffset + lump_1 * 4]) | uint(c2da_mem[spritetopoffset + lump_1 * 4 + 1]) << 0x8 | uint(c2da_mem[spritetopoffset + lump_1 * 4 + 2]) << 0x10 | uint(c2da_mem[spritetopoffset + lump_1 * 4 + 3]) << 0x18))
    let c2da_fresh91 : uint = uint(c2da_fresh90)
    c2da_mem[vis_0 + 52] = uint8(c2da_fresh91)
    c2da_mem[vis_0 + 53] = uint8(c2da_fresh91 >> 0x8)
    c2da_mem[vis_0 + 54] = uint8(c2da_fresh91 >> 0x10)
    c2da_mem[vis_0 + 55] = uint8(c2da_fresh91 >> 0x18)
    let c2da_fresh92 : int = x1_0 < 0 ? 0 : x1_0
    let c2da_fresh93 : uint = uint(c2da_fresh92)
    c2da_mem[vis_0 + 16] = uint8(c2da_fresh93)
    c2da_mem[vis_0 + 17] = uint8(c2da_fresh93 >> 0x8)
    c2da_mem[vis_0 + 18] = uint8(c2da_fresh93 >> 0x10)
    c2da_mem[vis_0 + 19] = uint8(c2da_fresh93 >> 0x18)
    let c2da_fresh94 : int = x2_0 >= viewwidth ? viewwidth - 1 : x2_0
    let c2da_fresh95 : uint = uint(c2da_fresh94)
    c2da_mem[vis_0 + 20] = uint8(c2da_fresh95)
    c2da_mem[vis_0 + 21] = uint8(c2da_fresh95 >> 0x8)
    c2da_mem[vis_0 + 22] = uint8(c2da_fresh95 >> 0x10)
    c2da_mem[vis_0 + 23] = uint8(c2da_fresh95 >> 0x18)
    let c2da_fresh96 : int = pspritescale << detailshift
    let c2da_fresh97 : uint = uint(c2da_fresh96)
    c2da_mem[vis_0 + 44] = uint8(c2da_fresh97)
    c2da_mem[vis_0 + 45] = uint8(c2da_fresh97 >> 0x8)
    c2da_mem[vis_0 + 46] = uint8(c2da_fresh97 >> 0x10)
    c2da_mem[vis_0 + 47] = uint8(c2da_fresh97 >> 0x18)
    if (flip_0 != 0x0) {
        let c2da_fresh98 : int = -pspriteiscale
        let c2da_fresh99 : uint = uint(c2da_fresh98)
        c2da_mem[vis_0 + 48] = uint8(c2da_fresh99)
        c2da_mem[vis_0 + 49] = uint8(c2da_fresh99 >> 0x8)
        c2da_mem[vis_0 + 50] = uint8(c2da_fresh99 >> 0x10)
        c2da_mem[vis_0 + 51] = uint8(c2da_fresh99 >> 0x18)
        let c2da_fresh100 : int = int(uint(c2da_mem[spritewidth + lump_1 * 4]) | uint(c2da_mem[spritewidth + lump_1 * 4 + 1]) << 0x8 | uint(c2da_mem[spritewidth + lump_1 * 4 + 2]) << 0x10 | uint(c2da_mem[spritewidth + lump_1 * 4 + 3]) << 0x18) - 1
        let c2da_fresh101 : uint = uint(c2da_fresh100)
        c2da_mem[vis_0 + 40] = uint8(c2da_fresh101)
        c2da_mem[vis_0 + 41] = uint8(c2da_fresh101 >> 0x8)
        c2da_mem[vis_0 + 42] = uint8(c2da_fresh101 >> 0x10)
        c2da_mem[vis_0 + 43] = uint8(c2da_fresh101 >> 0x18)
    } else {
        let c2da_fresh102 : uint = uint(pspriteiscale)
        c2da_mem[vis_0 + 48] = uint8(c2da_fresh102)
        c2da_mem[vis_0 + 49] = uint8(c2da_fresh102 >> 0x8)
        c2da_mem[vis_0 + 50] = uint8(c2da_fresh102 >> 0x10)
        c2da_mem[vis_0 + 51] = uint8(c2da_fresh102 >> 0x18)
        let c2da_fresh103 : int = 0
        let c2da_fresh104 : uint = uint(c2da_fresh103)
        c2da_mem[vis_0 + 40] = uint8(c2da_fresh104)
        c2da_mem[vis_0 + 41] = uint8(c2da_fresh104 >> 0x8)
        c2da_mem[vis_0 + 42] = uint8(c2da_fresh104 >> 0x10)
        c2da_mem[vis_0 + 43] = uint8(c2da_fresh104 >> 0x18)
    }
    if (int(uint(c2da_mem[vis_0 + 16]) | uint(c2da_mem[vis_0 + 17]) << 0x8 | uint(c2da_mem[vis_0 + 18]) << 0x10 | uint(c2da_mem[vis_0 + 19]) << 0x18) > x1_0) {
        let c2da_fresh105 : int = int(uint(c2da_mem[vis_0 + 40]) | uint(c2da_mem[vis_0 + 41]) << 0x8 | uint(c2da_mem[vis_0 + 42]) << 0x10 | uint(c2da_mem[vis_0 + 43]) << 0x18) + int(uint(c2da_mem[vis_0 + 48]) | uint(c2da_mem[vis_0 + 49]) << 0x8 | uint(c2da_mem[vis_0 + 50]) << 0x10 | uint(c2da_mem[vis_0 + 51]) << 0x18) * (int(uint(c2da_mem[vis_0 + 16]) | uint(c2da_mem[vis_0 + 17]) << 0x8 | uint(c2da_mem[vis_0 + 18]) << 0x10 | uint(c2da_mem[vis_0 + 19]) << 0x18) - x1_0)
        let c2da_fresh106 : uint = uint(c2da_fresh105)
        c2da_mem[vis_0 + 40] = uint8(c2da_fresh106)
        c2da_mem[vis_0 + 41] = uint8(c2da_fresh106 >> 0x8)
        c2da_mem[vis_0 + 42] = uint8(c2da_fresh106 >> 0x10)
        c2da_mem[vis_0 + 43] = uint8(c2da_fresh106 >> 0x18)
    }
    let c2da_fresh107 : uint = uint(lump_1)
    c2da_mem[vis_0 + 56] = uint8(c2da_fresh107)
    c2da_mem[vis_0 + 57] = uint8(c2da_fresh107 >> 0x8)
    c2da_mem[vis_0 + 58] = uint8(c2da_fresh107 >> 0x10)
    c2da_mem[vis_0 + 59] = uint8(c2da_fresh107 >> 0x18)
    if (int(uint(c2da_mem[viewplayer + 56 + 2 * 4]) | uint(c2da_mem[viewplayer + 56 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[viewplayer + 56 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[viewplayer + 56 + 2 * 4 + 3]) << 0x18) > 4 * 32 || (int(uint(c2da_mem[viewplayer + 56 + 2 * 4]) | uint(c2da_mem[viewplayer + 56 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[viewplayer + 56 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[viewplayer + 56 + 2 * 4 + 3]) << 0x18) & 8) != 0) {
        let c2da_fresh108 : uint = 0u
        c2da_mem[vis_0 + 64] = uint8(c2da_fresh108)
        c2da_mem[vis_0 + 65] = uint8(c2da_fresh108 >> 0x8)
        c2da_mem[vis_0 + 66] = uint8(c2da_fresh108 >> 0x10)
        c2da_mem[vis_0 + 67] = uint8(c2da_fresh108 >> 0x18)
        c2da_mem[vis_0 + 68] = 0u8
        c2da_mem[vis_0 + 69] = 0u8
        c2da_mem[vis_0 + 70] = 0u8
        c2da_mem[vis_0 + 71] = 0u8
    } elif (fixedcolormap != 0) {
        let c2da_fresh109 : uint = uint(fixedcolormap)
        c2da_mem[vis_0 + 64] = uint8(c2da_fresh109)
        c2da_mem[vis_0 + 65] = uint8(c2da_fresh109 >> 0x8)
        c2da_mem[vis_0 + 66] = uint8(c2da_fresh109 >> 0x10)
        c2da_mem[vis_0 + 67] = uint8(c2da_fresh109 >> 0x18)
        c2da_mem[vis_0 + 68] = 0u8
        c2da_mem[vis_0 + 69] = 0u8
        c2da_mem[vis_0 + 70] = 0u8
        c2da_mem[vis_0 + 71] = 0u8
    } else {
        let c2da_fresh110 : int = int(uint(c2da_mem[psp_0]) | uint(c2da_mem[psp_0 + 1]) << 0x8 | uint(c2da_mem[psp_0 + 2]) << 0x10 | uint(c2da_mem[psp_0 + 3]) << 0x18) + 4
        if ((int(uint(c2da_mem[c2da_fresh110]) | uint(c2da_mem[c2da_fresh110 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh110 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh110 + 3]) << 0x18) & 32768) != 0) {
            let c2da_fresh111 : uint = uint(colormaps)
            c2da_mem[vis_0 + 64] = uint8(c2da_fresh111)
            c2da_mem[vis_0 + 65] = uint8(c2da_fresh111 >> 0x8)
            c2da_mem[vis_0 + 66] = uint8(c2da_fresh111 >> 0x10)
            c2da_mem[vis_0 + 67] = uint8(c2da_fresh111 >> 0x18)
            c2da_mem[vis_0 + 68] = 0u8
            c2da_mem[vis_0 + 69] = 0u8
            c2da_mem[vis_0 + 70] = 0u8
            c2da_mem[vis_0 + 71] = 0u8
        } else {
            let c2da_fresh112 : int = int(uint(c2da_mem[spritelights + (48 - 1) * 8]) | uint(c2da_mem[spritelights + (48 - 1) * 8 + 1]) << 0x8 | uint(c2da_mem[spritelights + (48 - 1) * 8 + 2]) << 0x10 | uint(c2da_mem[spritelights + (48 - 1) * 8 + 3]) << 0x18)
            let c2da_fresh113 : uint = uint(c2da_fresh112)
            c2da_mem[vis_0 + 64] = uint8(c2da_fresh113)
            c2da_mem[vis_0 + 65] = uint8(c2da_fresh113 >> 0x8)
            c2da_mem[vis_0 + 66] = uint8(c2da_fresh113 >> 0x10)
            c2da_mem[vis_0 + 67] = uint8(c2da_fresh113 >> 0x18)
            c2da_mem[vis_0 + 68] = 0u8
            c2da_mem[vis_0 + 69] = 0u8
            c2da_mem[vis_0 + 70] = 0u8
            c2da_mem[vis_0 + 71] = 0u8
        }
    }
    R_DrawVisSprite(vis_0, int(uint(c2da_mem[vis_0 + 16]) | uint(c2da_mem[vis_0 + 17]) << 0x8 | uint(c2da_mem[vis_0 + 18]) << 0x10 | uint(c2da_mem[vis_0 + 19]) << 0x18), int(uint(c2da_mem[vis_0 + 20]) | uint(c2da_mem[vis_0 + 21]) << 0x8 | uint(c2da_mem[vis_0 + 22]) << 0x10 | uint(c2da_mem[vis_0 + 23]) << 0x18))
    return
}

// This unit's static data, at heap offset 362672.
let private c2da_lin_static_r_things_seg = fixed_array<int>(363952, 465)
let private c2da_lin_static_r_things = fixed_array<uint64>(0x63656a6f72505f52ul, 0x3a65746972705374ul, 0x64696c61766e6920ul, 0x2065746972707320ul, 0x25207265626d756eul, 0x6f72505f52002069ul, 0x697270537463656aul, 0x61766e69203a6574ul, 0x697270732064696cul, 0x656d617266206574ul, 0x6925203a20692520ul, 0x74696e495f520020ul, 0x3a73657469727053ul, 0x63746170206f4e20ul, 0x6e756f6620736568ul, 0x732520726f662064ul, 0x2520656d61726620ul, 0x74696e495f520063ul, 0x3a73657469727053ul, 0x2065746972705320ul, 0x656d617266207325ul, 0x6d20736920632520ul, 0x7220676e69737369ul, 0x736e6f697461746ful, 0x6174736e495f5200ul, 0x6574697270536c6cul, 0x6142203a706d754cul, 0x20656d6172662064ul, 0x6574636172616863ul, 0x756c206e69207372ul, 0x5f5200692520706dul, 0x6972705374696e49ul, 0x727053203a736574ul, 0x6620732520657469ul, 0x20632520656d6172ul, 0x746c756d20736168ul, 0x303d746f72207069ul, 0x5f5200706d756c20ul, 0x6972705374696e49ul, 0x727053203a736574ul, 0x6620732520657469ul, 0x20632520656d6172ul, 0x61746f7220736168ul, 0x6e6120736e6f6974ul, 0x3d746f7220612064ul, 0x5200706d756c2030ul, 0x72705374696e495ful, 0x7053203a73657469ul, 0x2073252065746972ul, 0x25203a206325203aul, 0x7774207361682063ul, 0x2073706d756c206ful, 0x742064657070616dul, 0x445f52007469206ful, 0x7469727053776172ul, 0x203a65676e615265ul, 0x7478657420646162ul, 0x6d756c6f63657275ul, 0x6eul)

[init]
def private c2da_lin_init_static_r_things() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_r_things_seg[s * 2]
        for (k in range(c2da_lin_static_r_things_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_r_things[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
