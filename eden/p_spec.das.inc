var private DonutOverrun__first : int = 1

[sideeffects]
def private c2da___bswap_16_11(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_11(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_11(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_11(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_11(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_11(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
var levelTimer : uint = default<uint>

var levelTimeCount : int = default<int>

[export, sideeffects]
def P_InitPicAnims() {
    var i : int
    var startname : int
    var endname : int
    lastanim = 64816
    i = 0
    while (int(uint(c2da_mem[65456 + i * 28]) | uint(c2da_mem[65456 + i * 28 + 1]) << 0x8 | uint(c2da_mem[65456 + i * 28 + 2]) << 0x10 | uint(c2da_mem[65456 + i * 28 + 3]) << 0x18) != -1) {
        startname = 65456 + i * 28 + 13
        endname = 65456 + i * 28 + 4
        if (int(uint(c2da_mem[65456 + i * 28]) | uint(c2da_mem[65456 + i * 28 + 1]) << 0x8 | uint(c2da_mem[65456 + i * 28 + 2]) << 0x10 | uint(c2da_mem[65456 + i * 28 + 3]) << 0x18) != 0) {
            if (R_CheckTextureNumForName(startname) == -1) {
                i++
                continue
            }
            let c2da_fresh0 : int = R_TextureNumForName(endname)
            let c2da_fresh1 : uint = uint(c2da_fresh0)
            c2da_mem[lastanim + 4] = uint8(c2da_fresh1)
            c2da_mem[lastanim + 5] = uint8(c2da_fresh1 >> 0x8)
            c2da_mem[lastanim + 6] = uint8(c2da_fresh1 >> 0x10)
            c2da_mem[lastanim + 7] = uint8(c2da_fresh1 >> 0x18)
            let c2da_fresh2 : int = R_TextureNumForName(startname)
            let c2da_fresh3 : uint = uint(c2da_fresh2)
            c2da_mem[lastanim + 8] = uint8(c2da_fresh3)
            c2da_mem[lastanim + 9] = uint8(c2da_fresh3 >> 0x8)
            c2da_mem[lastanim + 10] = uint8(c2da_fresh3 >> 0x10)
            c2da_mem[lastanim + 11] = uint8(c2da_fresh3 >> 0x18)
        } else {
            if (W_CheckNumForName(startname) == -1) {
                i++
                continue
            }
            let c2da_fresh4 : int = R_FlatNumForName(endname)
            let c2da_fresh5 : uint = uint(c2da_fresh4)
            c2da_mem[lastanim + 4] = uint8(c2da_fresh5)
            c2da_mem[lastanim + 5] = uint8(c2da_fresh5 >> 0x8)
            c2da_mem[lastanim + 6] = uint8(c2da_fresh5 >> 0x10)
            c2da_mem[lastanim + 7] = uint8(c2da_fresh5 >> 0x18)
            let c2da_fresh6 : int = R_FlatNumForName(startname)
            let c2da_fresh7 : uint = uint(c2da_fresh6)
            c2da_mem[lastanim + 8] = uint8(c2da_fresh7)
            c2da_mem[lastanim + 9] = uint8(c2da_fresh7 >> 0x8)
            c2da_mem[lastanim + 10] = uint8(c2da_fresh7 >> 0x10)
            c2da_mem[lastanim + 11] = uint8(c2da_fresh7 >> 0x18)
        }
        let c2da_fresh8 : uint = uint(int(uint(c2da_mem[65456 + i * 28]) | uint(c2da_mem[65456 + i * 28 + 1]) << 0x8 | uint(c2da_mem[65456 + i * 28 + 2]) << 0x10 | uint(c2da_mem[65456 + i * 28 + 3]) << 0x18))
        let c2da_fresh9 : uint = c2da_fresh8
        c2da_mem[lastanim] = uint8(c2da_fresh9)
        c2da_mem[lastanim + 1] = uint8(c2da_fresh9 >> 0x8)
        c2da_mem[lastanim + 2] = uint8(c2da_fresh9 >> 0x10)
        c2da_mem[lastanim + 3] = uint8(c2da_fresh9 >> 0x18)
        let c2da_fresh10 : int = int(uint(c2da_mem[lastanim + 4]) | uint(c2da_mem[lastanim + 5]) << 0x8 | uint(c2da_mem[lastanim + 6]) << 0x10 | uint(c2da_mem[lastanim + 7]) << 0x18) - int(uint(c2da_mem[lastanim + 8]) | uint(c2da_mem[lastanim + 9]) << 0x8 | uint(c2da_mem[lastanim + 10]) << 0x10 | uint(c2da_mem[lastanim + 11]) << 0x18) + 1
        let c2da_fresh11 : uint = uint(c2da_fresh10)
        c2da_mem[lastanim + 12] = uint8(c2da_fresh11)
        c2da_mem[lastanim + 13] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[lastanim + 14] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[lastanim + 15] = uint8(c2da_fresh11 >> 0x18)
        if (int(uint(c2da_mem[lastanim + 12]) | uint(c2da_mem[lastanim + 13]) << 0x8 | uint(c2da_mem[lastanim + 14]) << 0x10 | uint(c2da_mem[lastanim + 15]) << 0x18) < 2) {
            I_Error(361204, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(startname)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(endname))])
        }
        let c2da_fresh12 : int = int(uint(c2da_mem[65456 + i * 28 + 24]) | uint(c2da_mem[65456 + i * 28 + 25]) << 0x8 | uint(c2da_mem[65456 + i * 28 + 26]) << 0x10 | uint(c2da_mem[65456 + i * 28 + 27]) << 0x18)
        let c2da_fresh13 : uint = uint(c2da_fresh12)
        c2da_mem[lastanim + 16] = uint8(c2da_fresh13)
        c2da_mem[lastanim + 17] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[lastanim + 18] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[lastanim + 19] = uint8(c2da_fresh13 >> 0x18)
        lastanim += 20
        i++
    }
    return
}
var lastanim : int = default<int>

[export, sideeffects]
def P_SpawnSpecials() {
    var c2da_fresh14 : int
    var c2da_fresh17 : int
    var sector : int
    var i_0 : int
    if (timelimit > 0 && deathmatch != 0) {
        levelTimer = 1u
        levelTimeCount = timelimit * 60 * 35
    } else {
        levelTimer = 0u
    }
    sector = sectors
    i_0 = 0
    while (i_0 < numsectors) {
        if (int16(uint(c2da_mem[sector + 14]) | uint(c2da_mem[sector + 15]) << 0x8) == 0) {
            i_0++
            sector += 128
            continue
        }
        c2da_fresh14 = int(int16(uint(c2da_mem[sector + 14]) | uint(c2da_mem[sector + 15]) << 0x8))
        if (c2da_fresh14 >= 1 && c2da_fresh14 <= 17) {
            goto c2da_fresh14
        }
        goto label 0
        label 1:
        P_SpawnLightFlash(sector)
        goto label 0
        label 2:
        P_SpawnStrobeFlash(sector, 15, 0)
        goto label 0
        label 3:
        P_SpawnStrobeFlash(sector, 35, 0)
        goto label 0
        label 4:
        P_SpawnStrobeFlash(sector, 15, 0)
        let c2da_fresh15 : int16 = int16(4)
        let c2da_fresh16 : uint = uint(c2da_fresh15)
        c2da_mem[sector + 14] = uint8(c2da_fresh16)
        c2da_mem[sector + 15] = uint8(c2da_fresh16 >> 0x8)
        goto label 0
        label 8:
        P_SpawnGlowingLight(sector)
        goto label 0
        label 9:
        totalsecret = totalsecret + 1
        goto label 0
        label 10:
        P_SpawnDoorCloseIn30(sector)
        goto label 0
        label 12:
        P_SpawnStrobeFlash(sector, 35, 1)
        goto label 0
        label 13:
        P_SpawnStrobeFlash(sector, 15, 1)
        goto label 0
        label 14:
        P_SpawnDoorRaiseIn5Mins(sector, i_0)
        goto label 0
        label 17:
        P_SpawnFireFlicker(sector)
        label 0:
        label 5:
        label 6:
        label 7:
        label 11:
        label 15:
        label 16:
        i_0++
        sector += 128
    }
    numlinespecials = int16(0)
    i_0 = 0
    while (i_0 < numlines) {
        c2da_fresh17 = int(int16(uint(c2da_mem[lines + i_0 * 88 + 26]) | uint(c2da_mem[lines + i_0 * 88 + 27]) << 0x8))
        if (c2da_fresh17 == 48) {
            if (int(numlinespecials) >= 64) {
                I_Error(361244, [])
            }
            linespeciallist[int(numlinespecials)] = lines + i_0 * 88
            numlinespecials = int16(int(numlinespecials) + 1)
        }
        i_0++
    }
    i_0 = 0
    while (i_0 < 30) {
        activeceilings[i_0] = 0
        i_0++
    }
    i_0 = 0
    while (i_0 < 30) {
        activeplats[i_0] = 0
        i_0++
    }
    i_0 = 0
    for (c2da_i_0 in range(i_0, 16)) {
        c2da_lin_memset(66112 + c2da_i_0 * 32, 0, 32ul)
    }
    return
}
var numlinespecials : int16 = default<int16>

var linespeciallist : int[64]

[export, sideeffects]
def P_UpdateSpecials() {
    var c2da_fresh20 : int
    var c2da_fresh27 : uint
    var anim : int
    var pic : int
    var i_1 : int
    var line : int
    if (levelTimer == 1u) {
        levelTimeCount--
        if (levelTimeCount == 0) {
            G_ExitLevel()
        }
    }
    anim = 64816
    while (anim < lastanim) {
        i_1 = int(uint(c2da_mem[anim + 8]) | uint(c2da_mem[anim + 9]) << 0x8 | uint(c2da_mem[anim + 10]) << 0x10 | uint(c2da_mem[anim + 11]) << 0x18)
        while (i_1 < int(uint(c2da_mem[anim + 8]) | uint(c2da_mem[anim + 9]) << 0x8 | uint(c2da_mem[anim + 10]) << 0x10 | uint(c2da_mem[anim + 11]) << 0x18) + int(uint(c2da_mem[anim + 12]) | uint(c2da_mem[anim + 13]) << 0x8 | uint(c2da_mem[anim + 14]) << 0x10 | uint(c2da_mem[anim + 15]) << 0x18)) {
            pic = int(uint(c2da_mem[anim + 8]) | uint(c2da_mem[anim + 9]) << 0x8 | uint(c2da_mem[anim + 10]) << 0x10 | uint(c2da_mem[anim + 11]) << 0x18) + (leveltime / int(uint(c2da_mem[anim + 16]) | uint(c2da_mem[anim + 17]) << 0x8 | uint(c2da_mem[anim + 18]) << 0x10 | uint(c2da_mem[anim + 19]) << 0x18) + i_1) % int(uint(c2da_mem[anim + 12]) | uint(c2da_mem[anim + 13]) << 0x8 | uint(c2da_mem[anim + 14]) << 0x10 | uint(c2da_mem[anim + 15]) << 0x18)
            if ((uint(c2da_mem[anim]) | uint(c2da_mem[anim + 1]) << 0x8 | uint(c2da_mem[anim + 2]) << 0x10 | uint(c2da_mem[anim + 3]) << 0x18) != 0x0) {
                let c2da_fresh18 : uint = uint(pic)
                c2da_mem[texturetranslation + i_1 * 4] = uint8(c2da_fresh18)
                c2da_mem[texturetranslation + i_1 * 4 + 1] = uint8(c2da_fresh18 >> 0x8)
                c2da_mem[texturetranslation + i_1 * 4 + 2] = uint8(c2da_fresh18 >> 0x10)
                c2da_mem[texturetranslation + i_1 * 4 + 3] = uint8(c2da_fresh18 >> 0x18)
            } else {
                let c2da_fresh19 : uint = uint(pic)
                c2da_mem[flattranslation + i_1 * 4] = uint8(c2da_fresh19)
                c2da_mem[flattranslation + i_1 * 4 + 1] = uint8(c2da_fresh19 >> 0x8)
                c2da_mem[flattranslation + i_1 * 4 + 2] = uint8(c2da_fresh19 >> 0x10)
                c2da_mem[flattranslation + i_1 * 4 + 3] = uint8(c2da_fresh19 >> 0x18)
            }
            i_1++
        }
        anim += 20
    }
    i_1 = 0
    while (i_1 < int(numlinespecials)) {
        line = linespeciallist[i_1]
        c2da_fresh20 = int(int16(uint(c2da_mem[line + 26]) | uint(c2da_mem[line + 27]) << 0x8))
        if (c2da_fresh20 == 48) {
            let c2da_fresh21 : int = sides + int(int16(uint(c2da_mem[line + 30 + 0 * 2]) | uint(c2da_mem[line + 30 + 0 * 2 + 1]) << 0x8)) * 24
            let c2da_fresh22 : int = int(uint(c2da_mem[c2da_fresh21]) | uint(c2da_mem[c2da_fresh21 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh21 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh21 + 3]) << 0x18) + (1 << 16)
            let c2da_fresh23 : uint = uint(c2da_fresh22)
            c2da_mem[c2da_fresh21] = uint8(c2da_fresh23)
            c2da_mem[c2da_fresh21 + 1] = uint8(c2da_fresh23 >> 0x8)
            c2da_mem[c2da_fresh21 + 2] = uint8(c2da_fresh23 >> 0x10)
            c2da_mem[c2da_fresh21 + 3] = uint8(c2da_fresh23 >> 0x18)
        }
        i_1++
    }
    i_1 = 0
    for (c2da_i_1 in range(i_1, 16)) {
        if (int(uint(c2da_mem[66112 + c2da_i_1 * 32 + 16]) | uint(c2da_mem[66112 + c2da_i_1 * 32 + 17]) << 0x8 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 18]) << 0x10 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 19]) << 0x18) != 0) {
            let c2da_fresh24 : int = int(uint(c2da_mem[66112 + c2da_i_1 * 32 + 16]) | uint(c2da_mem[66112 + c2da_i_1 * 32 + 17]) << 0x8 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 18]) << 0x10 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 19]) << 0x18)
            let c2da_fresh25 : int = c2da_fresh24 - 1
            let c2da_fresh26 : uint = uint(c2da_fresh25)
            c2da_mem[66112 + c2da_i_1 * 32 + 16] = uint8(c2da_fresh26)
            c2da_mem[66112 + c2da_i_1 * 32 + 17] = uint8(c2da_fresh26 >> 0x8)
            c2da_mem[66112 + c2da_i_1 * 32 + 18] = uint8(c2da_fresh26 >> 0x10)
            c2da_mem[66112 + c2da_i_1 * 32 + 19] = uint8(c2da_fresh26 >> 0x18)
            if (int(uint(c2da_mem[66112 + c2da_i_1 * 32 + 16]) | uint(c2da_mem[66112 + c2da_i_1 * 32 + 17]) << 0x8 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 18]) << 0x10 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 19]) << 0x18) == 0) {
                c2da_fresh27 = uint(c2da_mem[66112 + c2da_i_1 * 32 + 8]) | uint(c2da_mem[66112 + c2da_i_1 * 32 + 9]) << 0x8 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 10]) << 0x10 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 11]) << 0x18
                if (c2da_fresh27 == 0x0u) {
                    let c2da_fresh28 : int = int(uint(c2da_mem[66112 + c2da_i_1 * 32]) | uint(c2da_mem[66112 + c2da_i_1 * 32 + 1]) << 0x8 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 2]) << 0x10 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 3]) << 0x18) + 30 + 0 * 2
                    let c2da_fresh29 : int = sides + int(int16(uint(c2da_mem[c2da_fresh28]) | uint(c2da_mem[c2da_fresh28 + 1]) << 0x8)) * 24 + 8
                    let c2da_fresh30 : int16 = int16(int(uint(c2da_mem[66112 + c2da_i_1 * 32 + 12]) | uint(c2da_mem[66112 + c2da_i_1 * 32 + 13]) << 0x8 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 14]) << 0x10 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 15]) << 0x18))
                    let c2da_fresh31 : uint = uint(c2da_fresh30)
                    c2da_mem[c2da_fresh29] = uint8(c2da_fresh31)
                    c2da_mem[c2da_fresh29 + 1] = uint8(c2da_fresh31 >> 0x8)
                } elif (c2da_fresh27 == 0x1u) {
                    let c2da_fresh32 : int = int(uint(c2da_mem[66112 + c2da_i_1 * 32]) | uint(c2da_mem[66112 + c2da_i_1 * 32 + 1]) << 0x8 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 2]) << 0x10 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 3]) << 0x18) + 30 + 0 * 2
                    let c2da_fresh33 : int = sides + int(int16(uint(c2da_mem[c2da_fresh32]) | uint(c2da_mem[c2da_fresh32 + 1]) << 0x8)) * 24 + 12
                    let c2da_fresh34 : int16 = int16(int(uint(c2da_mem[66112 + c2da_i_1 * 32 + 12]) | uint(c2da_mem[66112 + c2da_i_1 * 32 + 13]) << 0x8 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 14]) << 0x10 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 15]) << 0x18))
                    let c2da_fresh35 : uint = uint(c2da_fresh34)
                    c2da_mem[c2da_fresh33] = uint8(c2da_fresh35)
                    c2da_mem[c2da_fresh33 + 1] = uint8(c2da_fresh35 >> 0x8)
                } elif (c2da_fresh27 == 0x2u) {
                    let c2da_fresh36 : int = int(uint(c2da_mem[66112 + c2da_i_1 * 32]) | uint(c2da_mem[66112 + c2da_i_1 * 32 + 1]) << 0x8 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 2]) << 0x10 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 3]) << 0x18) + 30 + 0 * 2
                    let c2da_fresh37 : int = sides + int(int16(uint(c2da_mem[c2da_fresh36]) | uint(c2da_mem[c2da_fresh36 + 1]) << 0x8)) * 24 + 10
                    let c2da_fresh38 : int16 = int16(int(uint(c2da_mem[66112 + c2da_i_1 * 32 + 12]) | uint(c2da_mem[66112 + c2da_i_1 * 32 + 13]) << 0x8 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 14]) << 0x10 | uint(c2da_mem[66112 + c2da_i_1 * 32 + 15]) << 0x18))
                    let c2da_fresh39 : uint = uint(c2da_fresh38)
                    c2da_mem[c2da_fresh37] = uint8(c2da_fresh39)
                    c2da_mem[c2da_fresh37 + 1] = uint8(c2da_fresh39 >> 0x8)
                }
                S_StartSound(66112 + c2da_i_1 * 32 + 24, 23)
                c2da_lin_memset(66112 + c2da_i_1 * 32, 0, 32ul)
            }
        }
    }
    return
}
[export, sideeffects]
def P_ShootSpecialLine(var thing : int; var line_0 : int) {
    var c2da_fresh40 : int
    var c2da_fresh41 : int
    var ok : int
    if (int(uint(c2da_mem[thing + 192]) | uint(c2da_mem[thing + 193]) << 0x8 | uint(c2da_mem[thing + 194]) << 0x10 | uint(c2da_mem[thing + 195]) << 0x18) == 0) {
        ok = 0
        c2da_fresh40 = int(int16(uint(c2da_mem[line_0 + 26]) | uint(c2da_mem[line_0 + 27]) << 0x8))
        if (c2da_fresh40 == 46) {
            ok = 1
        }
        if (ok == 0) {
            return
        }
    }
    c2da_fresh41 = int(int16(uint(c2da_mem[line_0 + 26]) | uint(c2da_mem[line_0 + 27]) << 0x8))
    if (c2da_fresh41 == 24) {
        EV_DoFloor(line_0, 3u)
        P_ChangeSwitchTexture(line_0, 0)
    } elif (c2da_fresh41 == 46) {
        EV_DoDoor(line_0, 3u)
        P_ChangeSwitchTexture(line_0, 1)
    } elif (c2da_fresh41 == 47) {
        EV_DoPlat(line_0, 3u, 0)
        P_ChangeSwitchTexture(line_0, 0)
    }
    return
}
[export, sideeffects]
def P_CrossSpecialLine(var linenum : int; var side : int; var thing_0 : int) {
    var c2da_fresh42 : uint
    var c2da_fresh43 : int
    var c2da_fresh44 : int
    var line_1 : int
    var ok_0 : int
    line_1 = lines + linenum * 88
    if (int(uint(c2da_mem[thing_0 + 192]) | uint(c2da_mem[thing_0 + 193]) << 0x8 | uint(c2da_mem[thing_0 + 194]) << 0x10 | uint(c2da_mem[thing_0 + 195]) << 0x18) == 0) {
        c2da_fresh42 = uint(c2da_mem[thing_0 + 128]) | uint(c2da_mem[thing_0 + 129]) << 0x8 | uint(c2da_mem[thing_0 + 130]) << 0x10 | uint(c2da_mem[thing_0 + 131]) << 0x18
        if (c2da_fresh42 == 0x21u || c2da_fresh42 == 0x22u || c2da_fresh42 == 0x23u || c2da_fresh42 == 0x1fu || c2da_fresh42 == 0x20u || c2da_fresh42 == 0x10u) {
            return
        }
        ok_0 = 0
        c2da_fresh43 = int(int16(uint(c2da_mem[line_1 + 26]) | uint(c2da_mem[line_1 + 27]) << 0x8))
        if (c2da_fresh43 == 39 || c2da_fresh43 == 97 || c2da_fresh43 == 125 || c2da_fresh43 == 126 || c2da_fresh43 == 4 || c2da_fresh43 == 10 || c2da_fresh43 == 88) {
            ok_0 = 1
        }
        if (ok_0 == 0) {
            return
        }
    }
    c2da_fresh44 = int(int16(uint(c2da_mem[line_1 + 26]) | uint(c2da_mem[line_1 + 27]) << 0x8))
    if (c2da_fresh44 >= 2 && c2da_fresh44 <= 141) {
        goto c2da_fresh44 - 2
    }
    return
    label 5:
    label 7:
    label 9:
    label 12:
    label 13:
    label 16:
    label 18:
    label 19:
    label 21:
    label 22:
    label 24:
    label 25:
    label 26:
    label 27:
    label 29:
    label 30:
    label 31:
    label 32:
    label 39:
    label 40:
    label 41:
    label 43:
    label 44:
    label 45:
    label 46:
    label 47:
    label 48:
    label 49:
    label 53:
    label 58:
    label 59:
    label 60:
    label 61:
    label 62:
    label 63:
    label 64:
    label 65:
    label 66:
    label 67:
    label 68:
    label 69:
    label 76:
    label 83:
    label 97:
    label 99:
    label 100:
    label 101:
    label 109:
    label 110:
    label 111:
    label 112:
    label 113:
    label 114:
    label 115:
    label 116:
    label 120:
    label 121:
    label 125:
    label 129:
    label 130:
    label 131:
    label 132:
    label 133:
    label 134:
    label 135:
    label 136:
    label 137:
    label 138:
    return
    label 0:
    EV_DoDoor(line_1, 3u)
    let c2da_fresh45 : int16 = int16(0)
    let c2da_fresh46 : uint = uint(c2da_fresh45)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh46)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh46 >> 0x8)
    return
    label 1:
    EV_DoDoor(line_1, 2u)
    let c2da_fresh47 : int16 = int16(0)
    let c2da_fresh48 : uint = uint(c2da_fresh47)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh48)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh48 >> 0x8)
    return
    label 2:
    EV_DoDoor(line_1, 0u)
    let c2da_fresh49 : int16 = int16(0)
    let c2da_fresh50 : uint = uint(c2da_fresh49)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh50)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh50 >> 0x8)
    return
    label 3:
    EV_DoFloor(line_1, 3u)
    let c2da_fresh51 : int16 = int16(0)
    let c2da_fresh52 : uint = uint(c2da_fresh51)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh52)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh52 >> 0x8)
    return
    label 4:
    EV_DoCeiling(line_1, 4u)
    let c2da_fresh53 : int16 = int16(0)
    let c2da_fresh54 : uint = uint(c2da_fresh53)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh54)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh54 >> 0x8)
    return
    label 6:
    EV_BuildStairs(line_1, 0u)
    let c2da_fresh55 : int16 = int16(0)
    let c2da_fresh56 : uint = uint(c2da_fresh55)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh56)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh56 >> 0x8)
    return
    label 8:
    EV_DoPlat(line_1, 1u, 0)
    let c2da_fresh57 : int16 = int16(0)
    let c2da_fresh58 : uint = uint(c2da_fresh57)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh58)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh58 >> 0x8)
    return
    label 10:
    EV_LightTurnOn(line_1, 0)
    let c2da_fresh59 : int16 = int16(0)
    let c2da_fresh60 : uint = uint(c2da_fresh59)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh60)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh60 >> 0x8)
    return
    label 11:
    EV_LightTurnOn(line_1, 255)
    let c2da_fresh61 : int16 = int16(0)
    let c2da_fresh62 : uint = uint(c2da_fresh61)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh62)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh62 >> 0x8)
    return
    label 14:
    EV_DoDoor(line_1, 1u)
    let c2da_fresh63 : int16 = int16(0)
    let c2da_fresh64 : uint = uint(c2da_fresh63)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh64)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh64 >> 0x8)
    return
    label 15:
    EV_StartLightStrobing(line_1)
    let c2da_fresh65 : int16 = int16(0)
    let c2da_fresh66 : uint = uint(c2da_fresh65)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh66)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh66 >> 0x8)
    return
    label 17:
    EV_DoFloor(line_1, 0u)
    let c2da_fresh67 : int16 = int16(0)
    let c2da_fresh68 : uint = uint(c2da_fresh67)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh68)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh68 >> 0x8)
    return
    label 20:
    EV_DoPlat(line_1, 3u, 0)
    let c2da_fresh69 : int16 = int16(0)
    let c2da_fresh70 : uint = uint(c2da_fresh69)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh70)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh70 >> 0x8)
    return
    label 23:
    EV_DoCeiling(line_1, 3u)
    let c2da_fresh71 : int16 = int16(0)
    let c2da_fresh72 : uint = uint(c2da_fresh71)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh72)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh72 >> 0x8)
    return
    label 28:
    EV_DoFloor(line_1, 5u)
    let c2da_fresh73 : int16 = int16(0)
    let c2da_fresh74 : uint = uint(c2da_fresh73)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh74)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh74 >> 0x8)
    return
    label 33:
    EV_LightTurnOn(line_1, 35)
    let c2da_fresh75 : int16 = int16(0)
    let c2da_fresh76 : uint = uint(c2da_fresh75)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh76)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh76 >> 0x8)
    return
    label 34:
    EV_DoFloor(line_1, 2u)
    let c2da_fresh77 : int16 = int16(0)
    let c2da_fresh78 : uint = uint(c2da_fresh77)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh78)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh78 >> 0x8)
    return
    label 35:
    EV_DoFloor(line_1, 6u)
    let c2da_fresh79 : int16 = int16(0)
    let c2da_fresh80 : uint = uint(c2da_fresh79)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh80)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh80 >> 0x8)
    return
    label 36:
    EV_DoFloor(line_1, 1u)
    let c2da_fresh81 : int16 = int16(0)
    let c2da_fresh82 : uint = uint(c2da_fresh81)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh82)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh82 >> 0x8)
    return
    label 37:
    EV_Teleport(line_1, side, thing_0)
    let c2da_fresh83 : int16 = int16(0)
    let c2da_fresh84 : uint = uint(c2da_fresh83)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh84)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh84 >> 0x8)
    return
    label 38:
    EV_DoCeiling(line_1, 1u)
    EV_DoFloor(line_1, 1u)
    let c2da_fresh85 : int16 = int16(0)
    let c2da_fresh86 : uint = uint(c2da_fresh85)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh86)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh86 >> 0x8)
    return
    label 42:
    EV_DoCeiling(line_1, 2u)
    let c2da_fresh87 : int16 = int16(0)
    let c2da_fresh88 : uint = uint(c2da_fresh87)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh88)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh88 >> 0x8)
    return
    label 50:
    G_ExitLevel()
    return
    label 51:
    EV_DoPlat(line_1, 0u, 0)
    let c2da_fresh89 : int16 = int16(0)
    let c2da_fresh90 : uint = uint(c2da_fresh89)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh90)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh90 >> 0x8)
    return
    label 52:
    EV_StopPlat(line_1)
    let c2da_fresh91 : int16 = int16(0)
    let c2da_fresh92 : uint = uint(c2da_fresh91)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh92)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh92 >> 0x8)
    return
    label 54:
    EV_DoFloor(line_1, 9u)
    let c2da_fresh93 : int16 = int16(0)
    let c2da_fresh94 : uint = uint(c2da_fresh93)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh94)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh94 >> 0x8)
    return
    label 55:
    EV_CeilingCrushStop(line_1)
    let c2da_fresh95 : int16 = int16(0)
    let c2da_fresh96 : uint = uint(c2da_fresh95)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh96)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh96 >> 0x8)
    return
    label 56:
    EV_DoFloor(line_1, 7u)
    let c2da_fresh97 : int16 = int16(0)
    let c2da_fresh98 : uint = uint(c2da_fresh97)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh98)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh98 >> 0x8)
    return
    label 57:
    EV_DoFloor(line_1, 8u)
    let c2da_fresh99 : int16 = int16(0)
    let c2da_fresh100 : uint = uint(c2da_fresh99)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh100)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh100 >> 0x8)
    return
    label 102:
    EV_TurnTagLightsOff(line_1)
    let c2da_fresh101 : int16 = int16(0)
    let c2da_fresh102 : uint = uint(c2da_fresh101)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh102)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh102 >> 0x8)
    return
    label 106:
    EV_DoDoor(line_1, 5u)
    let c2da_fresh103 : int16 = int16(0)
    let c2da_fresh104 : uint = uint(c2da_fresh103)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh104)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh104 >> 0x8)
    return
    label 107:
    EV_DoDoor(line_1, 6u)
    let c2da_fresh105 : int16 = int16(0)
    let c2da_fresh106 : uint = uint(c2da_fresh105)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh106)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh106 >> 0x8)
    return
    label 98:
    EV_BuildStairs(line_1, 1u)
    let c2da_fresh107 : int16 = int16(0)
    let c2da_fresh108 : uint = uint(c2da_fresh107)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh108)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh108 >> 0x8)
    return
    label 108:
    EV_DoDoor(line_1, 7u)
    let c2da_fresh109 : int16 = int16(0)
    let c2da_fresh110 : uint = uint(c2da_fresh109)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh110)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh110 >> 0x8)
    return
    label 117:
    EV_DoFloor(line_1, 4u)
    let c2da_fresh111 : int16 = int16(0)
    let c2da_fresh112 : uint = uint(c2da_fresh111)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh112)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh112 >> 0x8)
    return
    label 119:
    EV_DoPlat(line_1, 4u, 0)
    let c2da_fresh113 : int16 = int16(0)
    let c2da_fresh114 : uint = uint(c2da_fresh113)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh114)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh114 >> 0x8)
    return
    label 122:
    G_SecretExitLevel()
    return
    label 123:
    if (int(uint(c2da_mem[thing_0 + 192]) | uint(c2da_mem[thing_0 + 193]) << 0x8 | uint(c2da_mem[thing_0 + 194]) << 0x10 | uint(c2da_mem[thing_0 + 195]) << 0x18) == 0) {
        EV_Teleport(line_1, side, thing_0)
        let c2da_fresh115 : int16 = int16(0)
        let c2da_fresh116 : uint = uint(c2da_fresh115)
        c2da_mem[line_1 + 26] = uint8(c2da_fresh116)
        c2da_mem[line_1 + 27] = uint8(c2da_fresh116 >> 0x8)
    }
    return
    label 128:
    EV_DoFloor(line_1, 10u)
    let c2da_fresh117 : int16 = int16(0)
    let c2da_fresh118 : uint = uint(c2da_fresh117)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh118)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh118 >> 0x8)
    return
    label 139:
    EV_DoCeiling(line_1, 5u)
    let c2da_fresh119 : int16 = int16(0)
    let c2da_fresh120 : uint = uint(c2da_fresh119)
    c2da_mem[line_1 + 26] = uint8(c2da_fresh120)
    c2da_mem[line_1 + 27] = uint8(c2da_fresh120 >> 0x8)
    return
    label 70:
    EV_DoCeiling(line_1, 2u)
    return
    label 71:
    EV_DoCeiling(line_1, 3u)
    return
    label 72:
    EV_CeilingCrushStop(line_1)
    return
    label 73:
    EV_DoDoor(line_1, 2u)
    return
    label 74:
    EV_DoDoor(line_1, 1u)
    return
    label 75:
    EV_DoCeiling(line_1, 4u)
    return
    label 77:
    EV_LightTurnOn(line_1, 35)
    return
    label 78:
    EV_LightTurnOn(line_1, 0)
    return
    label 79:
    EV_LightTurnOn(line_1, 255)
    return
    label 80:
    EV_DoFloor(line_1, 1u)
    return
    label 81:
    EV_DoFloor(line_1, 0u)
    return
    label 82:
    EV_DoFloor(line_1, 6u)
    return
    label 84:
    EV_DoDoor(line_1, 3u)
    return
    label 85:
    EV_DoPlat(line_1, 0u, 0)
    return
    label 86:
    EV_DoPlat(line_1, 1u, 0)
    return
    label 87:
    EV_StopPlat(line_1)
    return
    label 88:
    EV_DoDoor(line_1, 0u)
    return
    label 89:
    EV_DoFloor(line_1, 3u)
    return
    label 90:
    EV_DoFloor(line_1, 7u)
    return
    label 91:
    EV_DoFloor(line_1, 8u)
    return
    label 92:
    EV_DoFloor(line_1, 9u)
    return
    label 93:
    EV_DoPlat(line_1, 3u, 0)
    return
    label 94:
    EV_DoFloor(line_1, 5u)
    return
    label 95:
    EV_Teleport(line_1, side, thing_0)
    return
    label 96:
    EV_DoFloor(line_1, 2u)
    return
    label 103:
    EV_DoDoor(line_1, 5u)
    return
    label 104:
    EV_DoDoor(line_1, 6u)
    return
    label 105:
    EV_DoDoor(line_1, 7u)
    return
    label 118:
    EV_DoPlat(line_1, 4u, 0)
    return
    label 124:
    if (int(uint(c2da_mem[thing_0 + 192]) | uint(c2da_mem[thing_0 + 193]) << 0x8 | uint(c2da_mem[thing_0 + 194]) << 0x10 | uint(c2da_mem[thing_0 + 195]) << 0x18) == 0) {
        EV_Teleport(line_1, side, thing_0)
    }
    return
    label 126:
    EV_DoFloor(line_1, 4u)
    return
    label 127:
    EV_DoFloor(line_1, 10u)
    return
}
[export, sideeffects]
def P_PlayerInSpecialSector(var player : int) {
    var c2da_fresh124 : int
    var sector_0 : int
    let c2da_fresh121 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 88
    let c2da_fresh122 : int = int(uint(c2da_mem[c2da_fresh121]) | uint(c2da_mem[c2da_fresh121 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh121 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh121 + 3]) << 0x18)
    sector_0 = int(uint(c2da_mem[c2da_fresh122]) | uint(c2da_mem[c2da_fresh122 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh122 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh122 + 3]) << 0x18)
    let c2da_fresh123 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 32
    if (int(uint(c2da_mem[c2da_fresh123]) | uint(c2da_mem[c2da_fresh123 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh123 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh123 + 3]) << 0x18) != int(uint(c2da_mem[sector_0]) | uint(c2da_mem[sector_0 + 1]) << 0x8 | uint(c2da_mem[sector_0 + 2]) << 0x10 | uint(c2da_mem[sector_0 + 3]) << 0x18)) {
        return
    }
    c2da_fresh124 = int(int16(uint(c2da_mem[sector_0 + 14]) | uint(c2da_mem[sector_0 + 15]) << 0x8))
    if (c2da_fresh124 == 5) {
        if (int(uint(c2da_mem[player + 56 + 3 * 4]) | uint(c2da_mem[player + 56 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 3 * 4 + 3]) << 0x18) == 0) {
            if ((leveltime & 31) == 0) {
                P_DamageMobj(int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18), 0, 0, 10)
            }
        }
    } elif (c2da_fresh124 == 7) {
        if (int(uint(c2da_mem[player + 56 + 3 * 4]) | uint(c2da_mem[player + 56 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 3 * 4 + 3]) << 0x18) == 0) {
            if ((leveltime & 31) == 0) {
                P_DamageMobj(int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18), 0, 0, 5)
            }
        }
    } elif (c2da_fresh124 == 16 || c2da_fresh124 == 4) {
        if (int(uint(c2da_mem[player + 56 + 3 * 4]) | uint(c2da_mem[player + 56 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 3 * 4 + 3]) << 0x18) == 0 || P_Random() < 5) {
            if ((leveltime & 31) == 0) {
                P_DamageMobj(int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18), 0, 0, 20)
            }
        }
    } elif (c2da_fresh124 == 9) {
        let c2da_fresh125 : int = int(uint(c2da_mem[player + 224]) | uint(c2da_mem[player + 225]) << 0x8 | uint(c2da_mem[player + 226]) << 0x10 | uint(c2da_mem[player + 227]) << 0x18)
        let c2da_fresh126 : int = c2da_fresh125 + 1
        let c2da_fresh127 : uint = uint(c2da_fresh126)
        c2da_mem[player + 224] = uint8(c2da_fresh127)
        c2da_mem[player + 225] = uint8(c2da_fresh127 >> 0x8)
        c2da_mem[player + 226] = uint8(c2da_fresh127 >> 0x10)
        c2da_mem[player + 227] = uint8(c2da_fresh127 >> 0x18)
        let c2da_fresh128 : int16 = int16(0)
        let c2da_fresh129 : uint = uint(c2da_fresh128)
        c2da_mem[sector_0 + 14] = uint8(c2da_fresh129)
        c2da_mem[sector_0 + 15] = uint8(c2da_fresh129 >> 0x8)
    } elif (c2da_fresh124 == 11) {
        let c2da_fresh130 : int = int(uint(c2da_mem[player + 208]) | uint(c2da_mem[player + 209]) << 0x8 | uint(c2da_mem[player + 210]) << 0x10 | uint(c2da_mem[player + 211]) << 0x18) & ~2
        let c2da_fresh131 : uint = uint(c2da_fresh130)
        c2da_mem[player + 208] = uint8(c2da_fresh131)
        c2da_mem[player + 209] = uint8(c2da_fresh131 >> 0x8)
        c2da_mem[player + 210] = uint8(c2da_fresh131 >> 0x10)
        c2da_mem[player + 211] = uint8(c2da_fresh131 >> 0x18)
        if ((leveltime & 31) == 0) {
            P_DamageMobj(int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18), 0, 0, 20)
        }
        if (int(uint(c2da_mem[player + 44]) | uint(c2da_mem[player + 45]) << 0x8 | uint(c2da_mem[player + 46]) << 0x10 | uint(c2da_mem[player + 47]) << 0x18) <= 10) {
            G_ExitLevel()
        }
    } else {
        I_Error(361300, [C2daVaArg(tag = 1, i64 = int64(int16(uint(c2da_mem[sector_0 + 14]) | uint(c2da_mem[sector_0 + 15]) << 0x8)), f64 = 0.0lf, raw = 0x0)])
    }
    return
}
[export, sideeffects]
def twoSided(var sector_1 : int; var line_2 : int) : int {
    let c2da_fresh132 : int = int(uint(c2da_mem[sectors + sector_1 * 128 + 120]) | uint(c2da_mem[sectors + sector_1 * 128 + 121]) << 0x8 | uint(c2da_mem[sectors + sector_1 * 128 + 122]) << 0x10 | uint(c2da_mem[sectors + sector_1 * 128 + 123]) << 0x18) + line_2 * 8
    let c2da_fresh133 : int = int(uint(c2da_mem[c2da_fresh132]) | uint(c2da_mem[c2da_fresh132 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh132 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh132 + 3]) << 0x18) + 24
    return int(int16(uint(c2da_mem[c2da_fresh133]) | uint(c2da_mem[c2da_fresh133 + 1]) << 0x8)) & 4
}
[export, sideeffects]
def getSector(var currentSector : int; var line_3 : int; var side_0 : int) : int {
    let c2da_fresh134 : int = int(uint(c2da_mem[sectors + currentSector * 128 + 120]) | uint(c2da_mem[sectors + currentSector * 128 + 121]) << 0x8 | uint(c2da_mem[sectors + currentSector * 128 + 122]) << 0x10 | uint(c2da_mem[sectors + currentSector * 128 + 123]) << 0x18) + line_3 * 8
    let c2da_fresh135 : int = int(uint(c2da_mem[c2da_fresh134]) | uint(c2da_mem[c2da_fresh134 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh134 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh134 + 3]) << 0x18) + 30 + side_0 * 2
    let c2da_fresh136 : int = sides + int(int16(uint(c2da_mem[c2da_fresh135]) | uint(c2da_mem[c2da_fresh135 + 1]) << 0x8)) * 24 + 16
    return int(uint(c2da_mem[c2da_fresh136]) | uint(c2da_mem[c2da_fresh136 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh136 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh136 + 3]) << 0x18)
}
[export, sideeffects]
def getSide(var currentSector_0 : int; var line_4 : int; var side_1 : int) : int {
    let c2da_fresh137 : int = int(uint(c2da_mem[sectors + currentSector_0 * 128 + 120]) | uint(c2da_mem[sectors + currentSector_0 * 128 + 121]) << 0x8 | uint(c2da_mem[sectors + currentSector_0 * 128 + 122]) << 0x10 | uint(c2da_mem[sectors + currentSector_0 * 128 + 123]) << 0x18) + line_4 * 8
    let c2da_fresh138 : int = int(uint(c2da_mem[c2da_fresh137]) | uint(c2da_mem[c2da_fresh137 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh137 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh137 + 3]) << 0x18) + 30 + side_1 * 2
    return sides + int(int16(uint(c2da_mem[c2da_fresh138]) | uint(c2da_mem[c2da_fresh138 + 1]) << 0x8)) * 24
}
[export, sideeffects]
def P_FindLowestFloorSurrounding(var sec : int) : int {
    var i_2 : int
    var check : int
    var other : int
    var floor : int = int(uint(c2da_mem[sec]) | uint(c2da_mem[sec + 1]) << 0x8 | uint(c2da_mem[sec + 2]) << 0x10 | uint(c2da_mem[sec + 3]) << 0x18)
    i_2 = 0
    while (i_2 < int(uint(c2da_mem[sec + 112]) | uint(c2da_mem[sec + 113]) << 0x8 | uint(c2da_mem[sec + 114]) << 0x10 | uint(c2da_mem[sec + 115]) << 0x18)) {
        let c2da_fresh139 : int = int(uint(c2da_mem[sec + 120]) | uint(c2da_mem[sec + 121]) << 0x8 | uint(c2da_mem[sec + 122]) << 0x10 | uint(c2da_mem[sec + 123]) << 0x18) + i_2 * 8
        check = int(uint(c2da_mem[c2da_fresh139]) | uint(c2da_mem[c2da_fresh139 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh139 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh139 + 3]) << 0x18)
        other = getNextSector(check, sec)
        if (other == 0) {
            i_2++
            continue
        }
        if (int(uint(c2da_mem[other]) | uint(c2da_mem[other + 1]) << 0x8 | uint(c2da_mem[other + 2]) << 0x10 | uint(c2da_mem[other + 3]) << 0x18) < floor) {
            floor = int(uint(c2da_mem[other]) | uint(c2da_mem[other + 1]) << 0x8 | uint(c2da_mem[other + 2]) << 0x10 | uint(c2da_mem[other + 3]) << 0x18)
        }
        i_2++
    }
    return floor
}
[export, sideeffects]
def getNextSector(var line_5 : int; var sec_0 : int) : int {
    if ((int(int16(uint(c2da_mem[line_5 + 24]) | uint(c2da_mem[line_5 + 25]) << 0x8)) & 4) == 0) {
        return 0
    }
    if (int(uint(c2da_mem[line_5 + 56]) | uint(c2da_mem[line_5 + 57]) << 0x8 | uint(c2da_mem[line_5 + 58]) << 0x10 | uint(c2da_mem[line_5 + 59]) << 0x18) == sec_0) {
        return int(uint(c2da_mem[line_5 + 64]) | uint(c2da_mem[line_5 + 65]) << 0x8 | uint(c2da_mem[line_5 + 66]) << 0x10 | uint(c2da_mem[line_5 + 67]) << 0x18)
    }
    return int(uint(c2da_mem[line_5 + 56]) | uint(c2da_mem[line_5 + 57]) << 0x8 | uint(c2da_mem[line_5 + 58]) << 0x10 | uint(c2da_mem[line_5 + 59]) << 0x18)
}
[export, sideeffects]
def P_FindHighestFloorSurrounding(var sec_1 : int) : int {
    var i_3 : int
    var check_0 : int
    var other_0 : int
    var floor_0 : int = -500 * (1 << 16)
    i_3 = 0
    while (i_3 < int(uint(c2da_mem[sec_1 + 112]) | uint(c2da_mem[sec_1 + 113]) << 0x8 | uint(c2da_mem[sec_1 + 114]) << 0x10 | uint(c2da_mem[sec_1 + 115]) << 0x18)) {
        let c2da_fresh140 : int = int(uint(c2da_mem[sec_1 + 120]) | uint(c2da_mem[sec_1 + 121]) << 0x8 | uint(c2da_mem[sec_1 + 122]) << 0x10 | uint(c2da_mem[sec_1 + 123]) << 0x18) + i_3 * 8
        check_0 = int(uint(c2da_mem[c2da_fresh140]) | uint(c2da_mem[c2da_fresh140 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh140 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh140 + 3]) << 0x18)
        other_0 = getNextSector(check_0, sec_1)
        if (other_0 == 0) {
            i_3++
            continue
        }
        if (int(uint(c2da_mem[other_0]) | uint(c2da_mem[other_0 + 1]) << 0x8 | uint(c2da_mem[other_0 + 2]) << 0x10 | uint(c2da_mem[other_0 + 3]) << 0x18) > floor_0) {
            floor_0 = int(uint(c2da_mem[other_0]) | uint(c2da_mem[other_0 + 1]) << 0x8 | uint(c2da_mem[other_0 + 2]) << 0x10 | uint(c2da_mem[other_0 + 3]) << 0x18)
        }
        i_3++
    }
    return floor_0
}
[export, sideeffects]
def P_FindNextHighestFloor(var sec_2 : int; var currentheight : int) : int {
    var i_4 : int
    var h : int
    var min : int
    var check_1 : int
    var other_1 : int
    var height : int
    var heightlist : int[22]
    height = currentheight
    i_4 = 0
    h = 0
    while (i_4 < int(uint(c2da_mem[sec_2 + 112]) | uint(c2da_mem[sec_2 + 113]) << 0x8 | uint(c2da_mem[sec_2 + 114]) << 0x10 | uint(c2da_mem[sec_2 + 115]) << 0x18)) {
        let c2da_fresh141 : int = int(uint(c2da_mem[sec_2 + 120]) | uint(c2da_mem[sec_2 + 121]) << 0x8 | uint(c2da_mem[sec_2 + 122]) << 0x10 | uint(c2da_mem[sec_2 + 123]) << 0x18) + i_4 * 8
        check_1 = int(uint(c2da_mem[c2da_fresh141]) | uint(c2da_mem[c2da_fresh141 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh141 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh141 + 3]) << 0x18)
        other_1 = getNextSector(check_1, sec_2)
        if (other_1 == 0) {
            i_4++
            continue
        }
        if (int(uint(c2da_mem[other_1]) | uint(c2da_mem[other_1 + 1]) << 0x8 | uint(c2da_mem[other_1 + 2]) << 0x10 | uint(c2da_mem[other_1 + 3]) << 0x18) > height) {
            if (h == 20 + 1) {
                height = int(uint(c2da_mem[other_1]) | uint(c2da_mem[other_1 + 1]) << 0x8 | uint(c2da_mem[other_1 + 2]) << 0x10 | uint(c2da_mem[other_1 + 3]) << 0x18)
            } elif (h == 20 + 2) {
                I_Error(361344, [])
            }
            let c2da_postinc : int = h
            h++
            heightlist[c2da_postinc] = int(uint(c2da_mem[other_1]) | uint(c2da_mem[other_1 + 1]) << 0x8 | uint(c2da_mem[other_1 + 2]) << 0x10 | uint(c2da_mem[other_1 + 3]) << 0x18)
        }
        i_4++
    }
    if (h == 0) {
        return currentheight
    }
    min = heightlist[0]
    i_4 = 1
    for (c2da_i_4 in range(i_4, h)) {
        if (heightlist[c2da_i_4] < min) {
            min = heightlist[c2da_i_4]
        }
    }
    return min
}
[export, sideeffects]
def P_FindLowestCeilingSurrounding(var sec_3 : int) : int {
    var i_5 : int
    var check_2 : int
    var other_2 : int
    var height_0 : int = 2147483647
    i_5 = 0
    while (i_5 < int(uint(c2da_mem[sec_3 + 112]) | uint(c2da_mem[sec_3 + 113]) << 0x8 | uint(c2da_mem[sec_3 + 114]) << 0x10 | uint(c2da_mem[sec_3 + 115]) << 0x18)) {
        let c2da_fresh142 : int = int(uint(c2da_mem[sec_3 + 120]) | uint(c2da_mem[sec_3 + 121]) << 0x8 | uint(c2da_mem[sec_3 + 122]) << 0x10 | uint(c2da_mem[sec_3 + 123]) << 0x18) + i_5 * 8
        check_2 = int(uint(c2da_mem[c2da_fresh142]) | uint(c2da_mem[c2da_fresh142 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh142 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh142 + 3]) << 0x18)
        other_2 = getNextSector(check_2, sec_3)
        if (other_2 == 0) {
            i_5++
            continue
        }
        if (int(uint(c2da_mem[other_2 + 4]) | uint(c2da_mem[other_2 + 5]) << 0x8 | uint(c2da_mem[other_2 + 6]) << 0x10 | uint(c2da_mem[other_2 + 7]) << 0x18) < height_0) {
            height_0 = int(uint(c2da_mem[other_2 + 4]) | uint(c2da_mem[other_2 + 5]) << 0x8 | uint(c2da_mem[other_2 + 6]) << 0x10 | uint(c2da_mem[other_2 + 7]) << 0x18)
        }
        i_5++
    }
    return height_0
}
[export, sideeffects]
def P_FindHighestCeilingSurrounding(var sec_4 : int) : int {
    var i_6 : int
    var check_3 : int
    var other_3 : int
    var height_1 : int = 0
    i_6 = 0
    while (i_6 < int(uint(c2da_mem[sec_4 + 112]) | uint(c2da_mem[sec_4 + 113]) << 0x8 | uint(c2da_mem[sec_4 + 114]) << 0x10 | uint(c2da_mem[sec_4 + 115]) << 0x18)) {
        let c2da_fresh143 : int = int(uint(c2da_mem[sec_4 + 120]) | uint(c2da_mem[sec_4 + 121]) << 0x8 | uint(c2da_mem[sec_4 + 122]) << 0x10 | uint(c2da_mem[sec_4 + 123]) << 0x18) + i_6 * 8
        check_3 = int(uint(c2da_mem[c2da_fresh143]) | uint(c2da_mem[c2da_fresh143 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh143 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh143 + 3]) << 0x18)
        other_3 = getNextSector(check_3, sec_4)
        if (other_3 == 0) {
            i_6++
            continue
        }
        if (int(uint(c2da_mem[other_3 + 4]) | uint(c2da_mem[other_3 + 5]) << 0x8 | uint(c2da_mem[other_3 + 6]) << 0x10 | uint(c2da_mem[other_3 + 7]) << 0x18) > height_1) {
            height_1 = int(uint(c2da_mem[other_3 + 4]) | uint(c2da_mem[other_3 + 5]) << 0x8 | uint(c2da_mem[other_3 + 6]) << 0x10 | uint(c2da_mem[other_3 + 7]) << 0x18)
        }
        i_6++
    }
    return height_1
}
[export, sideeffects]
def P_FindSectorFromLineTag(var line_6 : int; var start : int) : int {
    var i_7 : int = start + 1
    while (i_7 < numsectors) {
        if (int(int16(uint(c2da_mem[sectors + i_7 * 128 + 16]) | uint(c2da_mem[sectors + i_7 * 128 + 17]) << 0x8)) == int(int16(uint(c2da_mem[line_6 + 28]) | uint(c2da_mem[line_6 + 29]) << 0x8))) {
            return i_7
        }
        i_7++
    }
    return -1
}
[export, sideeffects]
def P_FindMinSurroundingLight(var sector_2 : int; var max : int) : int {
    var i_8 : int
    var min_0 : int
    var line_7 : int
    var check_4 : int
    min_0 = max
    i_8 = 0
    while (i_8 < int(uint(c2da_mem[sector_2 + 112]) | uint(c2da_mem[sector_2 + 113]) << 0x8 | uint(c2da_mem[sector_2 + 114]) << 0x10 | uint(c2da_mem[sector_2 + 115]) << 0x18)) {
        let c2da_fresh144 : int = int(uint(c2da_mem[sector_2 + 120]) | uint(c2da_mem[sector_2 + 121]) << 0x8 | uint(c2da_mem[sector_2 + 122]) << 0x10 | uint(c2da_mem[sector_2 + 123]) << 0x18) + i_8 * 8
        line_7 = int(uint(c2da_mem[c2da_fresh144]) | uint(c2da_mem[c2da_fresh144 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh144 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh144 + 3]) << 0x18)
        check_4 = getNextSector(line_7, sector_2)
        if (check_4 == 0) {
            i_8++
            continue
        }
        if (int(int16(uint(c2da_mem[check_4 + 12]) | uint(c2da_mem[check_4 + 13]) << 0x8)) < min_0) {
            min_0 = int(int16(uint(c2da_mem[check_4 + 12]) | uint(c2da_mem[check_4 + 13]) << 0x8))
        }
        i_8++
    }
    return min_0
}
[export, sideeffects]
def EV_DoDonut(var line_8 : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = EV_DoDonut_c2da_frame(line_8, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[sideeffects]
def private DonutOverrun(var s3_floorheight : int; var s3_floorpic : int; var line_9 : int; var pillar_sector : int) {
    var p : int
    if (DonutOverrun__first != 0) {
        DonutOverrun__first = 0
        let c2da_fresh182 : int = 0
        let c2da_fresh183 : uint = uint(c2da_fresh182)
        c2da_mem[361184] = uint8(c2da_fresh183)
        c2da_mem[361185] = uint8(c2da_fresh183 >> 0x8)
        c2da_mem[361186] = uint8(c2da_fresh183 >> 0x10)
        c2da_mem[361187] = uint8(c2da_fresh183 >> 0x18)
        let c2da_fresh184 : int = 22
        let c2da_fresh185 : uint = uint(c2da_fresh184)
        c2da_mem[361200] = uint8(c2da_fresh185)
        c2da_mem[361201] = uint8(c2da_fresh185 >> 0x8)
        c2da_mem[361202] = uint8(c2da_fresh185 >> 0x10)
        c2da_mem[361203] = uint8(c2da_fresh185 >> 0x18)
        p = M_CheckParmWithArgs(361623, 2)
        if (p > 0) {
            M_StrToInt(int(uint(c2da_mem[myargv + (p + 1) * 8]) | uint(c2da_mem[myargv + (p + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p + 1) * 8 + 3]) << 0x18), 361184)
            M_StrToInt(int(uint(c2da_mem[myargv + (p + 2) * 8]) | uint(c2da_mem[myargv + (p + 2) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p + 2) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p + 2) * 8 + 3]) << 0x18), 361200)
            if (int(uint(c2da_mem[361200]) | uint(c2da_mem[361201]) << 0x8 | uint(c2da_mem[361202]) << 0x10 | uint(c2da_mem[361203]) << 0x18) >= numflats) {
                c2da_lin_printf(uint64(int(c2da_std_stderr())), 361630, [C2daVaArg(tag = 1, i64 = int64(numflats), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = 22l, f64 = 0.0lf, raw = 0x0)])
                let c2da_fresh186 : int = 22
                let c2da_fresh187 : uint = uint(c2da_fresh186)
                c2da_mem[361200] = uint8(c2da_fresh187)
                c2da_mem[361201] = uint8(c2da_fresh187 >> 0x8)
                c2da_mem[361202] = uint8(c2da_fresh187 >> 0x10)
                c2da_mem[361203] = uint8(c2da_fresh187 >> 0x18)
            }
        }
    }
    let c2da_fresh188 : int = int(uint(c2da_mem[361184]) | uint(c2da_mem[361185]) << 0x8 | uint(c2da_mem[361186]) << 0x10 | uint(c2da_mem[361187]) << 0x18)
    let c2da_fresh189 : uint = uint(c2da_fresh188)
    c2da_mem[s3_floorheight] = uint8(c2da_fresh189)
    c2da_mem[s3_floorheight + 1] = uint8(c2da_fresh189 >> 0x8)
    c2da_mem[s3_floorheight + 2] = uint8(c2da_fresh189 >> 0x10)
    c2da_mem[s3_floorheight + 3] = uint8(c2da_fresh189 >> 0x18)
    let c2da_fresh190 : int16 = int16(int(uint(c2da_mem[361200]) | uint(c2da_mem[361201]) << 0x8 | uint(c2da_mem[361202]) << 0x10 | uint(c2da_mem[361203]) << 0x18))
    let c2da_fresh191 : uint = uint(c2da_fresh190)
    c2da_mem[s3_floorpic] = uint8(c2da_fresh191)
    c2da_mem[s3_floorpic + 1] = uint8(c2da_fresh191 >> 0x8)
    return
}
[sideeffects]
def private EV_DoDonut_c2da_frame(var line_8 : int; c2da_fp : int) : int {
    var s1 : int
    var s2 : int
    var s3 : int
    var secnum : int
    var rtn : int
    var i_9 : int
    var floor_1 : int
    secnum = -1
    rtn = 0
    while (true) {
        secnum = P_FindSectorFromLineTag(line_8, secnum)
        if (secnum < 0) {
            break
        }
        s1 = sectors + secnum * 128
        if (int(uint(c2da_mem[s1 + 104]) | uint(c2da_mem[s1 + 105]) << 0x8 | uint(c2da_mem[s1 + 106]) << 0x10 | uint(c2da_mem[s1 + 107]) << 0x18) != 0) {
            continue
        }
        rtn = 1
        let c2da_fresh145 : int = int(uint(c2da_mem[s1 + 120]) | uint(c2da_mem[s1 + 121]) << 0x8 | uint(c2da_mem[s1 + 122]) << 0x10 | uint(c2da_mem[s1 + 123]) << 0x18) + 0 * 8
        s2 = getNextSector(int(uint(c2da_mem[c2da_fresh145]) | uint(c2da_mem[c2da_fresh145 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh145 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh145 + 3]) << 0x18), s1)
        if (s2 == 0) {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 361412, [])
            break
        }
        i_9 = 0
        while (i_9 < int(uint(c2da_mem[s2 + 112]) | uint(c2da_mem[s2 + 113]) << 0x8 | uint(c2da_mem[s2 + 114]) << 0x10 | uint(c2da_mem[s2 + 115]) << 0x18)) {
            let c2da_fresh146 : int = int(uint(c2da_mem[s2 + 120]) | uint(c2da_mem[s2 + 121]) << 0x8 | uint(c2da_mem[s2 + 122]) << 0x10 | uint(c2da_mem[s2 + 123]) << 0x18) + i_9 * 8
            let c2da_fresh147 : int = int(uint(c2da_mem[c2da_fresh146]) | uint(c2da_mem[c2da_fresh146 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh146 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh146 + 3]) << 0x18) + 64
            s3 = int(uint(c2da_mem[c2da_fresh147]) | uint(c2da_mem[c2da_fresh147 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh147 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh147 + 3]) << 0x18)
            if (s3 == s1) {
                i_9++
                continue
            }
            if (s3 == 0) {
                c2da_lin_printf(uint64(int(c2da_std_stderr())), 361504, [])
                DonutOverrun(c2da_fp, c2da_fp + 16, line_8, s1)
            } else {
                let c2da_fresh148 : int = int(uint(c2da_mem[s3]) | uint(c2da_mem[s3 + 1]) << 0x8 | uint(c2da_mem[s3 + 2]) << 0x10 | uint(c2da_mem[s3 + 3]) << 0x18)
                let c2da_fresh149 : uint = uint(c2da_fresh148)
                c2da_mem[c2da_fp] = uint8(c2da_fresh149)
                c2da_mem[c2da_fp + 1] = uint8(c2da_fresh149 >> 0x8)
                c2da_mem[c2da_fp + 2] = uint8(c2da_fresh149 >> 0x10)
                c2da_mem[c2da_fp + 3] = uint8(c2da_fresh149 >> 0x18)
                let c2da_fresh150 : int16 = int16(uint(c2da_mem[s3 + 8]) | uint(c2da_mem[s3 + 9]) << 0x8)
                let c2da_fresh151 : uint = uint(c2da_fresh150)
                c2da_mem[c2da_fp + 16] = uint8(c2da_fresh151)
                c2da_mem[c2da_fp + 17] = uint8(c2da_fresh151 >> 0x8)
            }
            floor_1 = Z_Malloc(64, 6, 0)
            P_AddThinker(floor_1)
            let c2da_fresh152 : uint = uint(floor_1)
            c2da_mem[s2 + 104] = uint8(c2da_fresh152)
            c2da_mem[s2 + 105] = uint8(c2da_fresh152 >> 0x8)
            c2da_mem[s2 + 106] = uint8(c2da_fresh152 >> 0x10)
            c2da_mem[s2 + 107] = uint8(c2da_fresh152 >> 0x18)
            c2da_mem[s2 + 108] = 0u8
            c2da_mem[s2 + 109] = 0u8
            c2da_mem[s2 + 110] = 0u8
            c2da_mem[s2 + 111] = 0u8
            let c2da_fresh153 : uint = 128u
            c2da_mem[floor_1 + 16] = uint8(c2da_fresh153)
            c2da_mem[floor_1 + 17] = uint8(c2da_fresh153 >> 0x8)
            c2da_mem[floor_1 + 18] = uint8(c2da_fresh153 >> 0x10)
            c2da_mem[floor_1 + 19] = uint8(c2da_fresh153 >> 0x18)
            c2da_mem[floor_1 + 20] = 0u8
            c2da_mem[floor_1 + 21] = 0u8
            c2da_mem[floor_1 + 22] = 0u8
            c2da_mem[floor_1 + 23] = 0u8
            let c2da_fresh154 : uint = 11u
            let c2da_fresh155 : uint = c2da_fresh154
            c2da_mem[floor_1 + 24] = uint8(c2da_fresh155)
            c2da_mem[floor_1 + 25] = uint8(c2da_fresh155 >> 0x8)
            c2da_mem[floor_1 + 26] = uint8(c2da_fresh155 >> 0x10)
            c2da_mem[floor_1 + 27] = uint8(c2da_fresh155 >> 0x18)
            let c2da_fresh156 : uint = 0u
            let c2da_fresh157 : uint = c2da_fresh156
            c2da_mem[floor_1 + 28] = uint8(c2da_fresh157)
            c2da_mem[floor_1 + 29] = uint8(c2da_fresh157 >> 0x8)
            c2da_mem[floor_1 + 30] = uint8(c2da_fresh157 >> 0x10)
            c2da_mem[floor_1 + 31] = uint8(c2da_fresh157 >> 0x18)
            let c2da_fresh158 : int = 1
            let c2da_fresh159 : uint = uint(c2da_fresh158)
            c2da_mem[floor_1 + 40] = uint8(c2da_fresh159)
            c2da_mem[floor_1 + 41] = uint8(c2da_fresh159 >> 0x8)
            c2da_mem[floor_1 + 42] = uint8(c2da_fresh159 >> 0x10)
            c2da_mem[floor_1 + 43] = uint8(c2da_fresh159 >> 0x18)
            let c2da_fresh160 : uint = uint(s2)
            c2da_mem[floor_1 + 32] = uint8(c2da_fresh160)
            c2da_mem[floor_1 + 33] = uint8(c2da_fresh160 >> 0x8)
            c2da_mem[floor_1 + 34] = uint8(c2da_fresh160 >> 0x10)
            c2da_mem[floor_1 + 35] = uint8(c2da_fresh160 >> 0x18)
            c2da_mem[floor_1 + 36] = 0u8
            c2da_mem[floor_1 + 37] = 0u8
            c2da_mem[floor_1 + 38] = 0u8
            c2da_mem[floor_1 + 39] = 0u8
            let c2da_fresh161 : int = (1 << 16) / 2
            let c2da_fresh162 : uint = uint(c2da_fresh161)
            c2da_mem[floor_1 + 56] = uint8(c2da_fresh162)
            c2da_mem[floor_1 + 57] = uint8(c2da_fresh162 >> 0x8)
            c2da_mem[floor_1 + 58] = uint8(c2da_fresh162 >> 0x10)
            c2da_mem[floor_1 + 59] = uint8(c2da_fresh162 >> 0x18)
            let c2da_fresh163 : int16 = int16(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8)
            let c2da_fresh164 : uint = uint(c2da_fresh163)
            c2da_mem[floor_1 + 48] = uint8(c2da_fresh164)
            c2da_mem[floor_1 + 49] = uint8(c2da_fresh164 >> 0x8)
            let c2da_fresh165 : int = 0
            let c2da_fresh166 : uint = uint(c2da_fresh165)
            c2da_mem[floor_1 + 44] = uint8(c2da_fresh166)
            c2da_mem[floor_1 + 45] = uint8(c2da_fresh166 >> 0x8)
            c2da_mem[floor_1 + 46] = uint8(c2da_fresh166 >> 0x10)
            c2da_mem[floor_1 + 47] = uint8(c2da_fresh166 >> 0x18)
            let c2da_fresh167 : int = int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18)
            let c2da_fresh168 : uint = uint(c2da_fresh167)
            c2da_mem[floor_1 + 52] = uint8(c2da_fresh168)
            c2da_mem[floor_1 + 53] = uint8(c2da_fresh168 >> 0x8)
            c2da_mem[floor_1 + 54] = uint8(c2da_fresh168 >> 0x10)
            c2da_mem[floor_1 + 55] = uint8(c2da_fresh168 >> 0x18)
            floor_1 = Z_Malloc(64, 6, 0)
            P_AddThinker(floor_1)
            let c2da_fresh169 : uint = uint(floor_1)
            c2da_mem[s1 + 104] = uint8(c2da_fresh169)
            c2da_mem[s1 + 105] = uint8(c2da_fresh169 >> 0x8)
            c2da_mem[s1 + 106] = uint8(c2da_fresh169 >> 0x10)
            c2da_mem[s1 + 107] = uint8(c2da_fresh169 >> 0x18)
            c2da_mem[s1 + 108] = 0u8
            c2da_mem[s1 + 109] = 0u8
            c2da_mem[s1 + 110] = 0u8
            c2da_mem[s1 + 111] = 0u8
            let c2da_fresh170 : uint = 128u
            c2da_mem[floor_1 + 16] = uint8(c2da_fresh170)
            c2da_mem[floor_1 + 17] = uint8(c2da_fresh170 >> 0x8)
            c2da_mem[floor_1 + 18] = uint8(c2da_fresh170 >> 0x10)
            c2da_mem[floor_1 + 19] = uint8(c2da_fresh170 >> 0x18)
            c2da_mem[floor_1 + 20] = 0u8
            c2da_mem[floor_1 + 21] = 0u8
            c2da_mem[floor_1 + 22] = 0u8
            c2da_mem[floor_1 + 23] = 0u8
            let c2da_fresh171 : uint = 0u
            let c2da_fresh172 : uint = c2da_fresh171
            c2da_mem[floor_1 + 24] = uint8(c2da_fresh172)
            c2da_mem[floor_1 + 25] = uint8(c2da_fresh172 >> 0x8)
            c2da_mem[floor_1 + 26] = uint8(c2da_fresh172 >> 0x10)
            c2da_mem[floor_1 + 27] = uint8(c2da_fresh172 >> 0x18)
            let c2da_fresh173 : uint = 0u
            let c2da_fresh174 : uint = c2da_fresh173
            c2da_mem[floor_1 + 28] = uint8(c2da_fresh174)
            c2da_mem[floor_1 + 29] = uint8(c2da_fresh174 >> 0x8)
            c2da_mem[floor_1 + 30] = uint8(c2da_fresh174 >> 0x10)
            c2da_mem[floor_1 + 31] = uint8(c2da_fresh174 >> 0x18)
            let c2da_fresh175 : int = -1
            let c2da_fresh176 : uint = uint(c2da_fresh175)
            c2da_mem[floor_1 + 40] = uint8(c2da_fresh176)
            c2da_mem[floor_1 + 41] = uint8(c2da_fresh176 >> 0x8)
            c2da_mem[floor_1 + 42] = uint8(c2da_fresh176 >> 0x10)
            c2da_mem[floor_1 + 43] = uint8(c2da_fresh176 >> 0x18)
            let c2da_fresh177 : uint = uint(s1)
            c2da_mem[floor_1 + 32] = uint8(c2da_fresh177)
            c2da_mem[floor_1 + 33] = uint8(c2da_fresh177 >> 0x8)
            c2da_mem[floor_1 + 34] = uint8(c2da_fresh177 >> 0x10)
            c2da_mem[floor_1 + 35] = uint8(c2da_fresh177 >> 0x18)
            c2da_mem[floor_1 + 36] = 0u8
            c2da_mem[floor_1 + 37] = 0u8
            c2da_mem[floor_1 + 38] = 0u8
            c2da_mem[floor_1 + 39] = 0u8
            let c2da_fresh178 : int = (1 << 16) / 2
            let c2da_fresh179 : uint = uint(c2da_fresh178)
            c2da_mem[floor_1 + 56] = uint8(c2da_fresh179)
            c2da_mem[floor_1 + 57] = uint8(c2da_fresh179 >> 0x8)
            c2da_mem[floor_1 + 58] = uint8(c2da_fresh179 >> 0x10)
            c2da_mem[floor_1 + 59] = uint8(c2da_fresh179 >> 0x18)
            let c2da_fresh180 : int = int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18)
            let c2da_fresh181 : uint = uint(c2da_fresh180)
            c2da_mem[floor_1 + 52] = uint8(c2da_fresh181)
            c2da_mem[floor_1 + 53] = uint8(c2da_fresh181 >> 0x8)
            c2da_mem[floor_1 + 54] = uint8(c2da_fresh181 >> 0x10)
            c2da_mem[floor_1 + 55] = uint8(c2da_fresh181 >> 0x18)
            break
        }
    }
    return rtn
}

// This unit's static data, at heap offset 361184.
let private c2da_lin_static_p_spec_seg = fixed_array<int>(361204, 577)
let private c2da_lin_static_p_spec = fixed_array<uint64>(0x695074696e495f50ul, 0x203a736d696e4163ul, 0x6c63796320646162ul, 0x25206d6f72662065ul, 0x7325206f742073ul, 0x796e616d206f6f54ul, 0x696c6c6f72637320ul, 0x206c6c617720676eul, 0x73666564656e696cul, 0x6c696e6156282021ul, 0x74696d696c20616cul, 0x29343620736920ul, 0x726579616c505f50ul, 0x6169636570536e49ul, 0x3a726f746365536cul, 0x6e776f6e6b6e7520ul, 0x6c61696365707320ul, 0x7463655300692520ul, 0x206874697720726ful, 0x6168742065726f6dul, 0x6a6461203232206eul, 0x7320676e696e696ful, 0x202e73726f746365ul, 0x20616c6c696e6156ul, 0x617263206c6c6977ul, 0x65726568206873ul, 0x6e6f446f445f5645ul, 0x656e696c203a7475ul, 0x2064616820666564ul, 0x6e6f636573206f6eul, 0x6564656469732064ul, 0x7078656e55202166ul, 0x6562206465746365ul, 0x6d20726f69766168ul, 0x727563636f207961ul, 0x696e6156206e6920ul, 0x6d6f6f4420616c6cul, 0x445f5645000a202eul, 0x203a74756e6f446ful, 0x3a474e494e524157ul, 0x6974616c756d6520ul, 0x656666756220676eul, 0x75727265766f2072ul, 0x6f7420657564206eul, 0x6162204c4c554e20ul, 0x6f74636573206b63ul, 0x7078656e55202e72ul, 0x6562206465746365ul, 0x6d20726f69766168ul, 0x727563636f207961ul, 0x696e6156206e6920ul, 0x6d6f6f4420616c6cul, 0x756e6f642d000a2eul, 0x4f74756e6f440074ul, 0x203a6e7572726576ul, 0x6f63657320656854ul, 0x6d6172617020646eul, 0x726f662072657465ul, 0x74756e6f642d2220ul, 0x6863746977732022ul, 0x20646c756f687320ul, 0x7461657267206562ul, 0x206e616874207265ul, 0x656c20646e612030ul, 0x206e616874207373ul, 0x6f207265626d756eul, 0x207374616c662066ul, 0x7355202e29642528ul, 0x6166656420676e69ul, 0x756c617620746c75ul, 0x6920296425282065ul, 0x202e64616574736eul, 0xaul)

[init]
def private c2da_lin_init_static_p_spec() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_p_spec_seg[s * 2]
        for (k in range(c2da_lin_static_p_spec_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_p_spec[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_p_spec_0 = fixed_array<uint8>(0x0, 0x0, 0x0, 0x0, 0x4e, 0x55, 0x4b, 0x41, 0x47, 0x45, 0x33, 0x0, 0x0, 0x4e, 0x55, 0x4b, 0x41, 0x47, 0x45, 0x31, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x46, 0x57, 0x41, 0x54, 0x45, 0x52, 0x34, 0x0, 0x0, 0x46, 0x57, 0x41, 0x54, 0x45, 0x52, 0x31, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x53, 0x57, 0x41, 0x54, 0x45, 0x52, 0x34, 0x0, 0x0, 0x53, 0x57, 0x41, 0x54, 0x45, 0x52, 0x31, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x41, 0x56, 0x41, 0x34, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x41, 0x56, 0x41, 0x31, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x42, 0x4c, 0x4f, 0x4f, 0x44, 0x33, 0x0, 0x0, 0x0, 0x42, 0x4c, 0x4f, 0x4f, 0x44, 0x31, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x52, 0x52, 0x4f, 0x43, 0x4b, 0x30, 0x38, 0x0, 0x0, 0x52, 0x52, 0x4f, 0x43, 0x4b, 0x30, 0x35, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x53, 0x4c, 0x49, 0x4d, 0x45, 0x30, 0x34, 0x0, 0x0, 0x53, 0x4c, 0x49, 0x4d, 0x45, 0x30, 0x31, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x53, 0x4c, 0x49, 0x4d, 0x45, 0x30, 0x38, 0x0, 0x0, 0x53, 0x4c, 0x49, 0x4d, 0x45, 0x30, 0x35, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x53, 0x4c, 0x49, 0x4d, 0x45, 0x31, 0x32, 0x0, 0x0, 0x53, 0x4c, 0x49, 0x4d, 0x45, 0x30, 0x39, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x42, 0x4c, 0x4f, 0x44, 0x47, 0x52, 0x34, 0x0, 0x0, 0x42, 0x4c, 0x4f, 0x44, 0x47, 0x52, 0x31, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x53, 0x4c, 0x41, 0x44, 0x52, 0x49, 0x50, 0x33, 0x0, 0x53, 0x4c, 0x41, 0x44, 0x52, 0x49, 0x50, 0x31, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x42, 0x4c, 0x4f, 0x44, 0x52, 0x49, 0x50, 0x34, 0x0, 0x42, 0x4c, 0x4f, 0x44, 0x52, 0x49, 0x50, 0x31, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x46, 0x49, 0x52, 0x45, 0x57, 0x41, 0x4c, 0x4c, 0x0, 0x46, 0x49, 0x52, 0x45, 0x57, 0x41, 0x4c, 0x41, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x47, 0x53, 0x54, 0x46, 0x4f, 0x4e, 0x54, 0x33, 0x0, 0x47, 0x53, 0x54, 0x46, 0x4f, 0x4e, 0x54, 0x31, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x46, 0x49, 0x52, 0x45, 0x4c, 0x41, 0x56, 0x41, 0x0, 0x46, 0x49, 0x52, 0x45, 0x4c, 0x41, 0x56, 0x33, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x46, 0x49, 0x52, 0x45, 0x4d, 0x41, 0x47, 0x33, 0x0, 0x46, 0x49, 0x52, 0x45, 0x4d, 0x41, 0x47, 0x31, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x46, 0x49, 0x52, 0x45, 0x42, 0x4c, 0x55, 0x32, 0x0, 0x46, 0x49, 0x52, 0x45, 0x42, 0x4c, 0x55, 0x31, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x52, 0x4f, 0x43, 0x4b, 0x52, 0x45, 0x44, 0x33, 0x0, 0x52, 0x4f, 0x43, 0x4b, 0x52, 0x45, 0x44, 0x31, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x42, 0x46, 0x41, 0x4c, 0x4c, 0x34, 0x0, 0x0, 0x0, 0x42, 0x46, 0x41, 0x4c, 0x4c, 0x31, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x53, 0x46, 0x41, 0x4c, 0x4c, 0x34, 0x0, 0x0, 0x0, 0x53, 0x46, 0x41, 0x4c, 0x4c, 0x31, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x57, 0x46, 0x41, 0x4c, 0x4c, 0x34, 0x0, 0x0, 0x0, 0x57, 0x46, 0x41, 0x4c, 0x4c, 0x31, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x44, 0x42, 0x52, 0x41, 0x49, 0x4e, 0x34, 0x0, 0x0, 0x44, 0x42, 0x52, 0x41, 0x49, 0x4e, 0x31, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_p_spec() {
    c2da_lin_setup()
    for (i in range(644)) {
        c2da_mem[65456 + i] = c2da_lin_extern_p_spec_0[i]
    }
}
