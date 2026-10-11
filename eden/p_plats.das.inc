var activeplats : int[30]

[export, sideeffects]
def T_PlatRaise(var plat : int) {
    var c2da_fresh0 : uint
    var c2da_fresh9 : uint
    var res : uint
    c2da_fresh0 = uint(c2da_mem[plat + 52]) | uint(c2da_mem[plat + 53]) << 0x8 | uint(c2da_mem[plat + 54]) << 0x10 | uint(c2da_mem[plat + 55]) << 0x18
    if (c2da_fresh0 == 0x0u) {
        goto label 0
    } elif (c2da_fresh0 == 0x1u) {
        goto label 1
    } elif (c2da_fresh0 == 0x2u) {
        goto label 2
    } elif (c2da_fresh0 == 0x3u) {
        return
    } else {
        return
    }
    label 0:
    res = T_MovePlane(int(uint(c2da_mem[plat + 24]) | uint(c2da_mem[plat + 25]) << 0x8 | uint(c2da_mem[plat + 26]) << 0x10 | uint(c2da_mem[plat + 27]) << 0x18), int(uint(c2da_mem[plat + 32]) | uint(c2da_mem[plat + 33]) << 0x8 | uint(c2da_mem[plat + 34]) << 0x10 | uint(c2da_mem[plat + 35]) << 0x18), int(uint(c2da_mem[plat + 40]) | uint(c2da_mem[plat + 41]) << 0x8 | uint(c2da_mem[plat + 42]) << 0x10 | uint(c2da_mem[plat + 43]) << 0x18), uint(c2da_mem[plat + 60]) | uint(c2da_mem[plat + 61]) << 0x8 | uint(c2da_mem[plat + 62]) << 0x10 | uint(c2da_mem[plat + 63]) << 0x18, 0, 1)
    if ((uint(c2da_mem[plat + 68]) | uint(c2da_mem[plat + 69]) << 0x8 | uint(c2da_mem[plat + 70]) << 0x10 | uint(c2da_mem[plat + 71]) << 0x18) == 2u || (uint(c2da_mem[plat + 68]) | uint(c2da_mem[plat + 69]) << 0x8 | uint(c2da_mem[plat + 70]) << 0x10 | uint(c2da_mem[plat + 71]) << 0x18) == 3u) {
        if ((leveltime & 7) == 0) {
            S_StartSound(int(uint(c2da_mem[plat + 24]) | uint(c2da_mem[plat + 25]) << 0x8 | uint(c2da_mem[plat + 26]) << 0x10 | uint(c2da_mem[plat + 27]) << 0x18) + 48, 22)
        }
    }
    if (res == 1u && (uint(c2da_mem[plat + 60]) | uint(c2da_mem[plat + 61]) << 0x8 | uint(c2da_mem[plat + 62]) << 0x10 | uint(c2da_mem[plat + 63]) << 0x18) == 0) {
        let c2da_fresh1 : int = int(uint(c2da_mem[plat + 44]) | uint(c2da_mem[plat + 45]) << 0x8 | uint(c2da_mem[plat + 46]) << 0x10 | uint(c2da_mem[plat + 47]) << 0x18)
        let c2da_fresh2 : uint = uint(c2da_fresh1)
        c2da_mem[plat + 48] = uint8(c2da_fresh2)
        c2da_mem[plat + 49] = uint8(c2da_fresh2 >> 0x8)
        c2da_mem[plat + 50] = uint8(c2da_fresh2 >> 0x10)
        c2da_mem[plat + 51] = uint8(c2da_fresh2 >> 0x18)
        let c2da_fresh3 : uint = 1u
        let c2da_fresh4 : uint = c2da_fresh3
        c2da_mem[plat + 52] = uint8(c2da_fresh4)
        c2da_mem[plat + 53] = uint8(c2da_fresh4 >> 0x8)
        c2da_mem[plat + 54] = uint8(c2da_fresh4 >> 0x10)
        c2da_mem[plat + 55] = uint8(c2da_fresh4 >> 0x18)
        S_StartSound(int(uint(c2da_mem[plat + 24]) | uint(c2da_mem[plat + 25]) << 0x8 | uint(c2da_mem[plat + 26]) << 0x10 | uint(c2da_mem[plat + 27]) << 0x18) + 48, 18)
    } elif (res == 2u) {
        let c2da_fresh5 : int = int(uint(c2da_mem[plat + 44]) | uint(c2da_mem[plat + 45]) << 0x8 | uint(c2da_mem[plat + 46]) << 0x10 | uint(c2da_mem[plat + 47]) << 0x18)
        let c2da_fresh6 : uint = uint(c2da_fresh5)
        c2da_mem[plat + 48] = uint8(c2da_fresh6)
        c2da_mem[plat + 49] = uint8(c2da_fresh6 >> 0x8)
        c2da_mem[plat + 50] = uint8(c2da_fresh6 >> 0x10)
        c2da_mem[plat + 51] = uint8(c2da_fresh6 >> 0x18)
        let c2da_fresh7 : uint = 2u
        let c2da_fresh8 : uint = c2da_fresh7
        c2da_mem[plat + 52] = uint8(c2da_fresh8)
        c2da_mem[plat + 53] = uint8(c2da_fresh8 >> 0x8)
        c2da_mem[plat + 54] = uint8(c2da_fresh8 >> 0x10)
        c2da_mem[plat + 55] = uint8(c2da_fresh8 >> 0x18)
        S_StartSound(int(uint(c2da_mem[plat + 24]) | uint(c2da_mem[plat + 25]) << 0x8 | uint(c2da_mem[plat + 26]) << 0x10 | uint(c2da_mem[plat + 27]) << 0x18) + 48, 19)
        c2da_fresh9 = uint(c2da_mem[plat + 68]) | uint(c2da_mem[plat + 69]) << 0x8 | uint(c2da_mem[plat + 70]) << 0x10 | uint(c2da_mem[plat + 71]) << 0x18
        if (c2da_fresh9 == 0x4u || c2da_fresh9 == 0x1u) {
            P_RemoveActivePlat(plat)
        } elif (c2da_fresh9 == 0x2u || c2da_fresh9 == 0x3u) {
            P_RemoveActivePlat(plat)
        }
    }
    return
    label 1:
    res = T_MovePlane(int(uint(c2da_mem[plat + 24]) | uint(c2da_mem[plat + 25]) << 0x8 | uint(c2da_mem[plat + 26]) << 0x10 | uint(c2da_mem[plat + 27]) << 0x18), int(uint(c2da_mem[plat + 32]) | uint(c2da_mem[plat + 33]) << 0x8 | uint(c2da_mem[plat + 34]) << 0x10 | uint(c2da_mem[plat + 35]) << 0x18), int(uint(c2da_mem[plat + 36]) | uint(c2da_mem[plat + 37]) << 0x8 | uint(c2da_mem[plat + 38]) << 0x10 | uint(c2da_mem[plat + 39]) << 0x18), 0u, 0, -1)
    if (res == 2u) {
        let c2da_fresh10 : int = int(uint(c2da_mem[plat + 44]) | uint(c2da_mem[plat + 45]) << 0x8 | uint(c2da_mem[plat + 46]) << 0x10 | uint(c2da_mem[plat + 47]) << 0x18)
        let c2da_fresh11 : uint = uint(c2da_fresh10)
        c2da_mem[plat + 48] = uint8(c2da_fresh11)
        c2da_mem[plat + 49] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[plat + 50] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[plat + 51] = uint8(c2da_fresh11 >> 0x18)
        let c2da_fresh12 : uint = 2u
        let c2da_fresh13 : uint = c2da_fresh12
        c2da_mem[plat + 52] = uint8(c2da_fresh13)
        c2da_mem[plat + 53] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[plat + 54] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[plat + 55] = uint8(c2da_fresh13 >> 0x18)
        S_StartSound(int(uint(c2da_mem[plat + 24]) | uint(c2da_mem[plat + 25]) << 0x8 | uint(c2da_mem[plat + 26]) << 0x10 | uint(c2da_mem[plat + 27]) << 0x18) + 48, 19)
    }
    return
    label 2:
    let c2da_fresh14 : int = int(uint(c2da_mem[plat + 48]) | uint(c2da_mem[plat + 49]) << 0x8 | uint(c2da_mem[plat + 50]) << 0x10 | uint(c2da_mem[plat + 51]) << 0x18)
    let c2da_fresh15 : int = c2da_fresh14 - 1
    let c2da_fresh16 : uint = uint(c2da_fresh15)
    c2da_mem[plat + 48] = uint8(c2da_fresh16)
    c2da_mem[plat + 49] = uint8(c2da_fresh16 >> 0x8)
    c2da_mem[plat + 50] = uint8(c2da_fresh16 >> 0x10)
    c2da_mem[plat + 51] = uint8(c2da_fresh16 >> 0x18)
    if (c2da_fresh15 == 0) {
        let c2da_fresh17 : int = int(uint(c2da_mem[plat + 24]) | uint(c2da_mem[plat + 25]) << 0x8 | uint(c2da_mem[plat + 26]) << 0x10 | uint(c2da_mem[plat + 27]) << 0x18)
        if (int(uint(c2da_mem[c2da_fresh17]) | uint(c2da_mem[c2da_fresh17 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh17 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh17 + 3]) << 0x18) == int(uint(c2da_mem[plat + 36]) | uint(c2da_mem[plat + 37]) << 0x8 | uint(c2da_mem[plat + 38]) << 0x10 | uint(c2da_mem[plat + 39]) << 0x18)) {
            let c2da_fresh18 : uint = 0u
            let c2da_fresh19 : uint = c2da_fresh18
            c2da_mem[plat + 52] = uint8(c2da_fresh19)
            c2da_mem[plat + 53] = uint8(c2da_fresh19 >> 0x8)
            c2da_mem[plat + 54] = uint8(c2da_fresh19 >> 0x10)
            c2da_mem[plat + 55] = uint8(c2da_fresh19 >> 0x18)
        } else {
            let c2da_fresh20 : uint = 1u
            let c2da_fresh21 : uint = c2da_fresh20
            c2da_mem[plat + 52] = uint8(c2da_fresh21)
            c2da_mem[plat + 53] = uint8(c2da_fresh21 >> 0x8)
            c2da_mem[plat + 54] = uint8(c2da_fresh21 >> 0x10)
            c2da_mem[plat + 55] = uint8(c2da_fresh21 >> 0x18)
        }
        S_StartSound(int(uint(c2da_mem[plat + 24]) | uint(c2da_mem[plat + 25]) << 0x8 | uint(c2da_mem[plat + 26]) << 0x10 | uint(c2da_mem[plat + 27]) << 0x18) + 48, 18)
    }
    return
}
[export, sideeffects]
def P_RemoveActivePlat(var plat_0 : int) {
    for (i in range(0, 30)) {
        if (plat_0 == activeplats[i]) {
            let c2da_fresh22 : int = activeplats[i] + 24
            let c2da_fresh23 : int = int(uint(c2da_mem[c2da_fresh22]) | uint(c2da_mem[c2da_fresh22 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh22 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh22 + 3]) << 0x18) + 104
            let c2da_fresh24 : uint = 0u
            c2da_mem[c2da_fresh23] = uint8(c2da_fresh24)
            c2da_mem[c2da_fresh23 + 1] = uint8(c2da_fresh24 >> 0x8)
            c2da_mem[c2da_fresh23 + 2] = uint8(c2da_fresh24 >> 0x10)
            c2da_mem[c2da_fresh23 + 3] = uint8(c2da_fresh24 >> 0x18)
            c2da_mem[c2da_fresh23 + 4] = 0u8
            c2da_mem[c2da_fresh23 + 5] = 0u8
            c2da_mem[c2da_fresh23 + 6] = 0u8
            c2da_mem[c2da_fresh23 + 7] = 0u8
            P_RemoveThinker(activeplats[i])
            activeplats[i] = 0
            return
        }
    }
    I_Error(360592, [])
    return
}
[export, sideeffects]
def EV_DoPlat(var line : int; var type_0 : uint; var amount : int) : int {
    var c2da_fresh25 : uint
    var c2da_fresh35 : uint
    var plat_1 : int
    var secnum : int
    var rtn : int
    var sec : int
    secnum = -1
    rtn = 0
    c2da_fresh25 = type_0
    if (c2da_fresh25 == 0x0u) {
        P_ActivateInStasis(int(int16(uint(c2da_mem[line + 28]) | uint(c2da_mem[line + 29]) << 0x8)))
    }
    while (true) {
        secnum = P_FindSectorFromLineTag(line, secnum)
        if (secnum < 0) {
            break
        }
        sec = sectors + secnum * 128
        if (int(uint(c2da_mem[sec + 104]) | uint(c2da_mem[sec + 105]) << 0x8 | uint(c2da_mem[sec + 106]) << 0x10 | uint(c2da_mem[sec + 107]) << 0x18) != 0) {
            continue
        }
        rtn = 1
        plat_1 = Z_Malloc(72, 6, 0)
        P_AddThinker(plat_1)
        let c2da_fresh26 : uint = type_0
        c2da_mem[plat_1 + 68] = uint8(c2da_fresh26)
        c2da_mem[plat_1 + 69] = uint8(c2da_fresh26 >> 0x8)
        c2da_mem[plat_1 + 70] = uint8(c2da_fresh26 >> 0x10)
        c2da_mem[plat_1 + 71] = uint8(c2da_fresh26 >> 0x18)
        let c2da_fresh27 : uint = uint(sec)
        c2da_mem[plat_1 + 24] = uint8(c2da_fresh27)
        c2da_mem[plat_1 + 25] = uint8(c2da_fresh27 >> 0x8)
        c2da_mem[plat_1 + 26] = uint8(c2da_fresh27 >> 0x10)
        c2da_mem[plat_1 + 27] = uint8(c2da_fresh27 >> 0x18)
        c2da_mem[plat_1 + 28] = 0u8
        c2da_mem[plat_1 + 29] = 0u8
        c2da_mem[plat_1 + 30] = 0u8
        c2da_mem[plat_1 + 31] = 0u8
        let c2da_fresh28 : int = int(uint(c2da_mem[plat_1 + 24]) | uint(c2da_mem[plat_1 + 25]) << 0x8 | uint(c2da_mem[plat_1 + 26]) << 0x10 | uint(c2da_mem[plat_1 + 27]) << 0x18) + 104
        let c2da_fresh29 : uint = uint(plat_1)
        c2da_mem[c2da_fresh28] = uint8(c2da_fresh29)
        c2da_mem[c2da_fresh28 + 1] = uint8(c2da_fresh29 >> 0x8)
        c2da_mem[c2da_fresh28 + 2] = uint8(c2da_fresh29 >> 0x10)
        c2da_mem[c2da_fresh28 + 3] = uint8(c2da_fresh29 >> 0x18)
        c2da_mem[c2da_fresh28 + 4] = 0u8
        c2da_mem[c2da_fresh28 + 5] = 0u8
        c2da_mem[c2da_fresh28 + 6] = 0u8
        c2da_mem[c2da_fresh28 + 7] = 0u8
        let c2da_fresh30 : uint = 125u
        c2da_mem[plat_1 + 16] = uint8(c2da_fresh30)
        c2da_mem[plat_1 + 17] = uint8(c2da_fresh30 >> 0x8)
        c2da_mem[plat_1 + 18] = uint8(c2da_fresh30 >> 0x10)
        c2da_mem[plat_1 + 19] = uint8(c2da_fresh30 >> 0x18)
        c2da_mem[plat_1 + 20] = 0u8
        c2da_mem[plat_1 + 21] = 0u8
        c2da_mem[plat_1 + 22] = 0u8
        c2da_mem[plat_1 + 23] = 0u8
        let c2da_fresh31 : uint = 0u
        let c2da_fresh32 : uint = c2da_fresh31
        c2da_mem[plat_1 + 60] = uint8(c2da_fresh32)
        c2da_mem[plat_1 + 61] = uint8(c2da_fresh32 >> 0x8)
        c2da_mem[plat_1 + 62] = uint8(c2da_fresh32 >> 0x10)
        c2da_mem[plat_1 + 63] = uint8(c2da_fresh32 >> 0x18)
        let c2da_fresh33 : int = int(int16(uint(c2da_mem[line + 28]) | uint(c2da_mem[line + 29]) << 0x8))
        let c2da_fresh34 : uint = uint(c2da_fresh33)
        c2da_mem[plat_1 + 64] = uint8(c2da_fresh34)
        c2da_mem[plat_1 + 65] = uint8(c2da_fresh34 >> 0x8)
        c2da_mem[plat_1 + 66] = uint8(c2da_fresh34 >> 0x10)
        c2da_mem[plat_1 + 67] = uint8(c2da_fresh34 >> 0x18)
        c2da_fresh35 = type_0
        if (c2da_fresh35 == 0x3u) {
            let c2da_fresh36 : int = (1 << 16) / 2
            let c2da_fresh37 : uint = uint(c2da_fresh36)
            c2da_mem[plat_1 + 32] = uint8(c2da_fresh37)
            c2da_mem[plat_1 + 33] = uint8(c2da_fresh37 >> 0x8)
            c2da_mem[plat_1 + 34] = uint8(c2da_fresh37 >> 0x10)
            c2da_mem[plat_1 + 35] = uint8(c2da_fresh37 >> 0x18)
            let c2da_fresh38 : int = sides + int(int16(uint(c2da_mem[line + 30 + 0 * 2]) | uint(c2da_mem[line + 30 + 0 * 2 + 1]) << 0x8)) * 24 + 16
            let c2da_fresh39 : int = int(uint(c2da_mem[c2da_fresh38]) | uint(c2da_mem[c2da_fresh38 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh38 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh38 + 3]) << 0x18) + 8
            let c2da_fresh40 : int16 = int16(uint(c2da_mem[c2da_fresh39]) | uint(c2da_mem[c2da_fresh39 + 1]) << 0x8)
            let c2da_fresh41 : uint = uint(c2da_fresh40)
            c2da_mem[sec + 8] = uint8(c2da_fresh41)
            c2da_mem[sec + 9] = uint8(c2da_fresh41 >> 0x8)
            let c2da_fresh42 : int = P_FindNextHighestFloor(sec, int(uint(c2da_mem[sec]) | uint(c2da_mem[sec + 1]) << 0x8 | uint(c2da_mem[sec + 2]) << 0x10 | uint(c2da_mem[sec + 3]) << 0x18))
            let c2da_fresh43 : uint = uint(c2da_fresh42)
            c2da_mem[plat_1 + 40] = uint8(c2da_fresh43)
            c2da_mem[plat_1 + 41] = uint8(c2da_fresh43 >> 0x8)
            c2da_mem[plat_1 + 42] = uint8(c2da_fresh43 >> 0x10)
            c2da_mem[plat_1 + 43] = uint8(c2da_fresh43 >> 0x18)
            let c2da_fresh44 : int = 0
            let c2da_fresh45 : uint = uint(c2da_fresh44)
            c2da_mem[plat_1 + 44] = uint8(c2da_fresh45)
            c2da_mem[plat_1 + 45] = uint8(c2da_fresh45 >> 0x8)
            c2da_mem[plat_1 + 46] = uint8(c2da_fresh45 >> 0x10)
            c2da_mem[plat_1 + 47] = uint8(c2da_fresh45 >> 0x18)
            let c2da_fresh46 : uint = 0u
            let c2da_fresh47 : uint = c2da_fresh46
            c2da_mem[plat_1 + 52] = uint8(c2da_fresh47)
            c2da_mem[plat_1 + 53] = uint8(c2da_fresh47 >> 0x8)
            c2da_mem[plat_1 + 54] = uint8(c2da_fresh47 >> 0x10)
            c2da_mem[plat_1 + 55] = uint8(c2da_fresh47 >> 0x18)
            let c2da_fresh48 : int16 = int16(0)
            let c2da_fresh49 : uint = uint(c2da_fresh48)
            c2da_mem[sec + 14] = uint8(c2da_fresh49)
            c2da_mem[sec + 15] = uint8(c2da_fresh49 >> 0x8)
            S_StartSound(sec + 48, 22)
        } elif (c2da_fresh35 == 0x2u) {
            let c2da_fresh50 : int = (1 << 16) / 2
            let c2da_fresh51 : uint = uint(c2da_fresh50)
            c2da_mem[plat_1 + 32] = uint8(c2da_fresh51)
            c2da_mem[plat_1 + 33] = uint8(c2da_fresh51 >> 0x8)
            c2da_mem[plat_1 + 34] = uint8(c2da_fresh51 >> 0x10)
            c2da_mem[plat_1 + 35] = uint8(c2da_fresh51 >> 0x18)
            let c2da_fresh52 : int = sides + int(int16(uint(c2da_mem[line + 30 + 0 * 2]) | uint(c2da_mem[line + 30 + 0 * 2 + 1]) << 0x8)) * 24 + 16
            let c2da_fresh53 : int = int(uint(c2da_mem[c2da_fresh52]) | uint(c2da_mem[c2da_fresh52 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh52 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh52 + 3]) << 0x18) + 8
            let c2da_fresh54 : int16 = int16(uint(c2da_mem[c2da_fresh53]) | uint(c2da_mem[c2da_fresh53 + 1]) << 0x8)
            let c2da_fresh55 : uint = uint(c2da_fresh54)
            c2da_mem[sec + 8] = uint8(c2da_fresh55)
            c2da_mem[sec + 9] = uint8(c2da_fresh55 >> 0x8)
            let c2da_fresh56 : int = int(uint(c2da_mem[sec]) | uint(c2da_mem[sec + 1]) << 0x8 | uint(c2da_mem[sec + 2]) << 0x10 | uint(c2da_mem[sec + 3]) << 0x18) + amount * (1 << 16)
            let c2da_fresh57 : uint = uint(c2da_fresh56)
            c2da_mem[plat_1 + 40] = uint8(c2da_fresh57)
            c2da_mem[plat_1 + 41] = uint8(c2da_fresh57 >> 0x8)
            c2da_mem[plat_1 + 42] = uint8(c2da_fresh57 >> 0x10)
            c2da_mem[plat_1 + 43] = uint8(c2da_fresh57 >> 0x18)
            let c2da_fresh58 : int = 0
            let c2da_fresh59 : uint = uint(c2da_fresh58)
            c2da_mem[plat_1 + 44] = uint8(c2da_fresh59)
            c2da_mem[plat_1 + 45] = uint8(c2da_fresh59 >> 0x8)
            c2da_mem[plat_1 + 46] = uint8(c2da_fresh59 >> 0x10)
            c2da_mem[plat_1 + 47] = uint8(c2da_fresh59 >> 0x18)
            let c2da_fresh60 : uint = 0u
            let c2da_fresh61 : uint = c2da_fresh60
            c2da_mem[plat_1 + 52] = uint8(c2da_fresh61)
            c2da_mem[plat_1 + 53] = uint8(c2da_fresh61 >> 0x8)
            c2da_mem[plat_1 + 54] = uint8(c2da_fresh61 >> 0x10)
            c2da_mem[plat_1 + 55] = uint8(c2da_fresh61 >> 0x18)
            S_StartSound(sec + 48, 22)
        } elif (c2da_fresh35 == 0x1u) {
            let c2da_fresh62 : int = (1 << 16) * 4
            let c2da_fresh63 : uint = uint(c2da_fresh62)
            c2da_mem[plat_1 + 32] = uint8(c2da_fresh63)
            c2da_mem[plat_1 + 33] = uint8(c2da_fresh63 >> 0x8)
            c2da_mem[plat_1 + 34] = uint8(c2da_fresh63 >> 0x10)
            c2da_mem[plat_1 + 35] = uint8(c2da_fresh63 >> 0x18)
            let c2da_fresh64 : int = P_FindLowestFloorSurrounding(sec)
            let c2da_fresh65 : uint = uint(c2da_fresh64)
            c2da_mem[plat_1 + 36] = uint8(c2da_fresh65)
            c2da_mem[plat_1 + 37] = uint8(c2da_fresh65 >> 0x8)
            c2da_mem[plat_1 + 38] = uint8(c2da_fresh65 >> 0x10)
            c2da_mem[plat_1 + 39] = uint8(c2da_fresh65 >> 0x18)
            if (int(uint(c2da_mem[plat_1 + 36]) | uint(c2da_mem[plat_1 + 37]) << 0x8 | uint(c2da_mem[plat_1 + 38]) << 0x10 | uint(c2da_mem[plat_1 + 39]) << 0x18) > int(uint(c2da_mem[sec]) | uint(c2da_mem[sec + 1]) << 0x8 | uint(c2da_mem[sec + 2]) << 0x10 | uint(c2da_mem[sec + 3]) << 0x18)) {
                let c2da_fresh66 : int = int(uint(c2da_mem[sec]) | uint(c2da_mem[sec + 1]) << 0x8 | uint(c2da_mem[sec + 2]) << 0x10 | uint(c2da_mem[sec + 3]) << 0x18)
                let c2da_fresh67 : uint = uint(c2da_fresh66)
                c2da_mem[plat_1 + 36] = uint8(c2da_fresh67)
                c2da_mem[plat_1 + 37] = uint8(c2da_fresh67 >> 0x8)
                c2da_mem[plat_1 + 38] = uint8(c2da_fresh67 >> 0x10)
                c2da_mem[plat_1 + 39] = uint8(c2da_fresh67 >> 0x18)
            }
            let c2da_fresh68 : int = int(uint(c2da_mem[sec]) | uint(c2da_mem[sec + 1]) << 0x8 | uint(c2da_mem[sec + 2]) << 0x10 | uint(c2da_mem[sec + 3]) << 0x18)
            let c2da_fresh69 : uint = uint(c2da_fresh68)
            c2da_mem[plat_1 + 40] = uint8(c2da_fresh69)
            c2da_mem[plat_1 + 41] = uint8(c2da_fresh69 >> 0x8)
            c2da_mem[plat_1 + 42] = uint8(c2da_fresh69 >> 0x10)
            c2da_mem[plat_1 + 43] = uint8(c2da_fresh69 >> 0x18)
            let c2da_fresh70 : int = 35 * 3
            let c2da_fresh71 : uint = uint(c2da_fresh70)
            c2da_mem[plat_1 + 44] = uint8(c2da_fresh71)
            c2da_mem[plat_1 + 45] = uint8(c2da_fresh71 >> 0x8)
            c2da_mem[plat_1 + 46] = uint8(c2da_fresh71 >> 0x10)
            c2da_mem[plat_1 + 47] = uint8(c2da_fresh71 >> 0x18)
            let c2da_fresh72 : uint = 1u
            let c2da_fresh73 : uint = c2da_fresh72
            c2da_mem[plat_1 + 52] = uint8(c2da_fresh73)
            c2da_mem[plat_1 + 53] = uint8(c2da_fresh73 >> 0x8)
            c2da_mem[plat_1 + 54] = uint8(c2da_fresh73 >> 0x10)
            c2da_mem[plat_1 + 55] = uint8(c2da_fresh73 >> 0x18)
            S_StartSound(sec + 48, 18)
        } elif (c2da_fresh35 == 0x4u) {
            let c2da_fresh74 : int = (1 << 16) * 8
            let c2da_fresh75 : uint = uint(c2da_fresh74)
            c2da_mem[plat_1 + 32] = uint8(c2da_fresh75)
            c2da_mem[plat_1 + 33] = uint8(c2da_fresh75 >> 0x8)
            c2da_mem[plat_1 + 34] = uint8(c2da_fresh75 >> 0x10)
            c2da_mem[plat_1 + 35] = uint8(c2da_fresh75 >> 0x18)
            let c2da_fresh76 : int = P_FindLowestFloorSurrounding(sec)
            let c2da_fresh77 : uint = uint(c2da_fresh76)
            c2da_mem[plat_1 + 36] = uint8(c2da_fresh77)
            c2da_mem[plat_1 + 37] = uint8(c2da_fresh77 >> 0x8)
            c2da_mem[plat_1 + 38] = uint8(c2da_fresh77 >> 0x10)
            c2da_mem[plat_1 + 39] = uint8(c2da_fresh77 >> 0x18)
            if (int(uint(c2da_mem[plat_1 + 36]) | uint(c2da_mem[plat_1 + 37]) << 0x8 | uint(c2da_mem[plat_1 + 38]) << 0x10 | uint(c2da_mem[plat_1 + 39]) << 0x18) > int(uint(c2da_mem[sec]) | uint(c2da_mem[sec + 1]) << 0x8 | uint(c2da_mem[sec + 2]) << 0x10 | uint(c2da_mem[sec + 3]) << 0x18)) {
                let c2da_fresh78 : int = int(uint(c2da_mem[sec]) | uint(c2da_mem[sec + 1]) << 0x8 | uint(c2da_mem[sec + 2]) << 0x10 | uint(c2da_mem[sec + 3]) << 0x18)
                let c2da_fresh79 : uint = uint(c2da_fresh78)
                c2da_mem[plat_1 + 36] = uint8(c2da_fresh79)
                c2da_mem[plat_1 + 37] = uint8(c2da_fresh79 >> 0x8)
                c2da_mem[plat_1 + 38] = uint8(c2da_fresh79 >> 0x10)
                c2da_mem[plat_1 + 39] = uint8(c2da_fresh79 >> 0x18)
            }
            let c2da_fresh80 : int = int(uint(c2da_mem[sec]) | uint(c2da_mem[sec + 1]) << 0x8 | uint(c2da_mem[sec + 2]) << 0x10 | uint(c2da_mem[sec + 3]) << 0x18)
            let c2da_fresh81 : uint = uint(c2da_fresh80)
            c2da_mem[plat_1 + 40] = uint8(c2da_fresh81)
            c2da_mem[plat_1 + 41] = uint8(c2da_fresh81 >> 0x8)
            c2da_mem[plat_1 + 42] = uint8(c2da_fresh81 >> 0x10)
            c2da_mem[plat_1 + 43] = uint8(c2da_fresh81 >> 0x18)
            let c2da_fresh82 : int = 35 * 3
            let c2da_fresh83 : uint = uint(c2da_fresh82)
            c2da_mem[plat_1 + 44] = uint8(c2da_fresh83)
            c2da_mem[plat_1 + 45] = uint8(c2da_fresh83 >> 0x8)
            c2da_mem[plat_1 + 46] = uint8(c2da_fresh83 >> 0x10)
            c2da_mem[plat_1 + 47] = uint8(c2da_fresh83 >> 0x18)
            let c2da_fresh84 : uint = 1u
            let c2da_fresh85 : uint = c2da_fresh84
            c2da_mem[plat_1 + 52] = uint8(c2da_fresh85)
            c2da_mem[plat_1 + 53] = uint8(c2da_fresh85 >> 0x8)
            c2da_mem[plat_1 + 54] = uint8(c2da_fresh85 >> 0x10)
            c2da_mem[plat_1 + 55] = uint8(c2da_fresh85 >> 0x18)
            S_StartSound(sec + 48, 18)
        } elif (c2da_fresh35 == 0x0u) {
            let c2da_fresh86 : int = 1 << 16
            let c2da_fresh87 : uint = uint(c2da_fresh86)
            c2da_mem[plat_1 + 32] = uint8(c2da_fresh87)
            c2da_mem[plat_1 + 33] = uint8(c2da_fresh87 >> 0x8)
            c2da_mem[plat_1 + 34] = uint8(c2da_fresh87 >> 0x10)
            c2da_mem[plat_1 + 35] = uint8(c2da_fresh87 >> 0x18)
            let c2da_fresh88 : int = P_FindLowestFloorSurrounding(sec)
            let c2da_fresh89 : uint = uint(c2da_fresh88)
            c2da_mem[plat_1 + 36] = uint8(c2da_fresh89)
            c2da_mem[plat_1 + 37] = uint8(c2da_fresh89 >> 0x8)
            c2da_mem[plat_1 + 38] = uint8(c2da_fresh89 >> 0x10)
            c2da_mem[plat_1 + 39] = uint8(c2da_fresh89 >> 0x18)
            if (int(uint(c2da_mem[plat_1 + 36]) | uint(c2da_mem[plat_1 + 37]) << 0x8 | uint(c2da_mem[plat_1 + 38]) << 0x10 | uint(c2da_mem[plat_1 + 39]) << 0x18) > int(uint(c2da_mem[sec]) | uint(c2da_mem[sec + 1]) << 0x8 | uint(c2da_mem[sec + 2]) << 0x10 | uint(c2da_mem[sec + 3]) << 0x18)) {
                let c2da_fresh90 : int = int(uint(c2da_mem[sec]) | uint(c2da_mem[sec + 1]) << 0x8 | uint(c2da_mem[sec + 2]) << 0x10 | uint(c2da_mem[sec + 3]) << 0x18)
                let c2da_fresh91 : uint = uint(c2da_fresh90)
                c2da_mem[plat_1 + 36] = uint8(c2da_fresh91)
                c2da_mem[plat_1 + 37] = uint8(c2da_fresh91 >> 0x8)
                c2da_mem[plat_1 + 38] = uint8(c2da_fresh91 >> 0x10)
                c2da_mem[plat_1 + 39] = uint8(c2da_fresh91 >> 0x18)
            }
            let c2da_fresh92 : int = P_FindHighestFloorSurrounding(sec)
            let c2da_fresh93 : uint = uint(c2da_fresh92)
            c2da_mem[plat_1 + 40] = uint8(c2da_fresh93)
            c2da_mem[plat_1 + 41] = uint8(c2da_fresh93 >> 0x8)
            c2da_mem[plat_1 + 42] = uint8(c2da_fresh93 >> 0x10)
            c2da_mem[plat_1 + 43] = uint8(c2da_fresh93 >> 0x18)
            if (int(uint(c2da_mem[plat_1 + 40]) | uint(c2da_mem[plat_1 + 41]) << 0x8 | uint(c2da_mem[plat_1 + 42]) << 0x10 | uint(c2da_mem[plat_1 + 43]) << 0x18) < int(uint(c2da_mem[sec]) | uint(c2da_mem[sec + 1]) << 0x8 | uint(c2da_mem[sec + 2]) << 0x10 | uint(c2da_mem[sec + 3]) << 0x18)) {
                let c2da_fresh94 : int = int(uint(c2da_mem[sec]) | uint(c2da_mem[sec + 1]) << 0x8 | uint(c2da_mem[sec + 2]) << 0x10 | uint(c2da_mem[sec + 3]) << 0x18)
                let c2da_fresh95 : uint = uint(c2da_fresh94)
                c2da_mem[plat_1 + 40] = uint8(c2da_fresh95)
                c2da_mem[plat_1 + 41] = uint8(c2da_fresh95 >> 0x8)
                c2da_mem[plat_1 + 42] = uint8(c2da_fresh95 >> 0x10)
                c2da_mem[plat_1 + 43] = uint8(c2da_fresh95 >> 0x18)
            }
            let c2da_fresh96 : int = 35 * 3
            let c2da_fresh97 : uint = uint(c2da_fresh96)
            c2da_mem[plat_1 + 44] = uint8(c2da_fresh97)
            c2da_mem[plat_1 + 45] = uint8(c2da_fresh97 >> 0x8)
            c2da_mem[plat_1 + 46] = uint8(c2da_fresh97 >> 0x10)
            c2da_mem[plat_1 + 47] = uint8(c2da_fresh97 >> 0x18)
            let c2da_fresh98 : uint = uint(P_Random() & 1)
            let c2da_fresh99 : uint = c2da_fresh98
            c2da_mem[plat_1 + 52] = uint8(c2da_fresh99)
            c2da_mem[plat_1 + 53] = uint8(c2da_fresh99 >> 0x8)
            c2da_mem[plat_1 + 54] = uint8(c2da_fresh99 >> 0x10)
            c2da_mem[plat_1 + 55] = uint8(c2da_fresh99 >> 0x18)
            S_StartSound(sec + 48, 18)
        }
        P_AddActivePlat(plat_1)
    }
    return rtn
}
[export, sideeffects]
def P_AddActivePlat(var plat_2 : int) {
    for (i_0 in range(0, 30)) {
        if (activeplats[i_0] == 0) {
            activeplats[i_0] = int(plat_2)  // nolint:PERF020
            return
        }
    }
    I_Error(360629, [])
    return
}
[export, sideeffects]
def P_ActivateInStasis(var tag : int) {
    for (i_1 in range(0, 30)) {
        var c2da_fresh101 : int = 0
        if (activeplats[i_1] != 0) {
            let c2da_fresh100 : int = activeplats[i_1] + 64
            if (int(uint(c2da_mem[c2da_fresh100]) | uint(c2da_mem[c2da_fresh100 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh100 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh100 + 3]) << 0x18) == tag) {
                c2da_fresh101 = 1
            }
        }
        var c2da_fresh103 : int = 0
        if (c2da_fresh101 != 0) {
            let c2da_fresh102 : int = activeplats[i_1] + 52
            if ((uint(c2da_mem[c2da_fresh102]) | uint(c2da_mem[c2da_fresh102 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh102 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh102 + 3]) << 0x18) == 3u) {
                c2da_fresh103 = 1
            }
        }
        if (c2da_fresh103 != 0) {
            let c2da_fresh104 : int = activeplats[i_1] + 52
            let c2da_fresh105 : int = activeplats[i_1] + 56
            let c2da_fresh106 : uint = uint(c2da_mem[c2da_fresh105]) | uint(c2da_mem[c2da_fresh105 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh105 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh105 + 3]) << 0x18
            let c2da_fresh107 : uint = c2da_fresh106
            c2da_mem[c2da_fresh104] = uint8(c2da_fresh107)
            c2da_mem[c2da_fresh104 + 1] = uint8(c2da_fresh107 >> 0x8)
            c2da_mem[c2da_fresh104 + 2] = uint8(c2da_fresh107 >> 0x10)
            c2da_mem[c2da_fresh104 + 3] = uint8(c2da_fresh107 >> 0x18)
            let c2da_fresh108 : int = activeplats[i_1] + 16
            let c2da_fresh109 : uint = 125u
            c2da_mem[c2da_fresh108] = uint8(c2da_fresh109)
            c2da_mem[c2da_fresh108 + 1] = uint8(c2da_fresh109 >> 0x8)
            c2da_mem[c2da_fresh108 + 2] = uint8(c2da_fresh109 >> 0x10)
            c2da_mem[c2da_fresh108 + 3] = uint8(c2da_fresh109 >> 0x18)
            c2da_mem[c2da_fresh108 + 4] = 0u8
            c2da_mem[c2da_fresh108 + 5] = 0u8
            c2da_mem[c2da_fresh108 + 6] = 0u8
            c2da_mem[c2da_fresh108 + 7] = 0u8
        }
    }
    return
}
[export, sideeffects]
def EV_StopPlat(var line_0 : int) {
    for (j in range(0, 30)) {
        var c2da_fresh111 : int = 0
        if (activeplats[j] != 0) {
            let c2da_fresh110 : int = activeplats[j] + 52
            if ((uint(c2da_mem[c2da_fresh110]) | uint(c2da_mem[c2da_fresh110 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh110 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh110 + 3]) << 0x18) != 3u) {
                c2da_fresh111 = 1
            }
        }
        var c2da_fresh113 : int = 0
        if (c2da_fresh111 != 0) {
            let c2da_fresh112 : int = activeplats[j] + 64
            if (int(uint(c2da_mem[c2da_fresh112]) | uint(c2da_mem[c2da_fresh112 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh112 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh112 + 3]) << 0x18) == int(int16(uint(c2da_mem[line_0 + 28]) | uint(c2da_mem[line_0 + 29]) << 0x8))) {
                c2da_fresh113 = 1
            }
        }
        if (c2da_fresh113 != 0) {
            let c2da_fresh114 : int = activeplats[j] + 56
            let c2da_fresh115 : int = activeplats[j] + 52
            let c2da_fresh116 : uint = uint(c2da_mem[c2da_fresh115]) | uint(c2da_mem[c2da_fresh115 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh115 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh115 + 3]) << 0x18
            let c2da_fresh117 : uint = c2da_fresh116
            c2da_mem[c2da_fresh114] = uint8(c2da_fresh117)
            c2da_mem[c2da_fresh114 + 1] = uint8(c2da_fresh117 >> 0x8)
            c2da_mem[c2da_fresh114 + 2] = uint8(c2da_fresh117 >> 0x10)
            c2da_mem[c2da_fresh114 + 3] = uint8(c2da_fresh117 >> 0x18)
            let c2da_fresh118 : int = activeplats[j] + 52
            let c2da_fresh119 : uint = 3u
            let c2da_fresh120 : uint = c2da_fresh119
            c2da_mem[c2da_fresh118] = uint8(c2da_fresh120)
            c2da_mem[c2da_fresh118 + 1] = uint8(c2da_fresh120 >> 0x8)
            c2da_mem[c2da_fresh118 + 2] = uint8(c2da_fresh120 >> 0x10)
            c2da_mem[c2da_fresh118 + 3] = uint8(c2da_fresh120 >> 0x18)
            let c2da_fresh121 : int = activeplats[j] + 16
            let c2da_fresh122 : uint = 0u
            c2da_mem[c2da_fresh121] = uint8(c2da_fresh122)
            c2da_mem[c2da_fresh121 + 1] = uint8(c2da_fresh122 >> 0x8)
            c2da_mem[c2da_fresh121 + 2] = uint8(c2da_fresh122 >> 0x10)
            c2da_mem[c2da_fresh121 + 3] = uint8(c2da_fresh122 >> 0x18)
            c2da_mem[c2da_fresh121 + 4] = 0u8
            c2da_mem[c2da_fresh121 + 5] = 0u8
            c2da_mem[c2da_fresh121 + 6] = 0u8
            c2da_mem[c2da_fresh121 + 7] = 0u8
        }
    }
    return
}

// This unit's static data, at heap offset 360592.
let private c2da_lin_static_p_plats_seg = fixed_array<int>(360592, 68)
let private c2da_lin_static_p_plats = fixed_array<uint64>(0x65766f6d65525f50ul, 0x6c50657669746341ul, 0x276e6163203a7461ul, 0x7020646e69662074ul, 0x415f50002174616cul, 0x6576697463416464ul, 0x6f6e203a74616c50ul, 0x6c702065726f6d20ul, 0x21737461ul)

[init]
def private c2da_lin_init_static_p_plats() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_p_plats_seg[s * 2]
        for (k in range(c2da_lin_static_p_plats_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_p_plats[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_p_plats() {
    if (length(c2da_fn_table5) < 126) {
        resize(c2da_fn_table5, 126)
    }
    c2da_fn_table5[125] = @@T_PlatRaise
}

[init]
def private c2da_lin_relink_init_p_plats() {
    c2da_relink_p_plats()
}
