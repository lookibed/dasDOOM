var activeceilings : int[30]

[export, sideeffects]
def EV_DoCeiling(var line : int; var type_0 : uint) : int {
    var c2da_fresh0 : uint
    var c2da_fresh6 : uint
    var secnum : int
    var rtn : int
    var sec : int
    var ceiling : int
    secnum = -1
    rtn = 0
    c2da_fresh0 = type_0
    if (c2da_fresh0 == 0x3u) {
        goto label 0
    } elif (c2da_fresh0 == 0x4u) {
        goto label 0
    } elif (c2da_fresh0 == 0x5u) {
        goto label 0
    } else {
        goto label 1
    }
    label 0:
    P_ActivateInStasisCeiling(line)
    label 1:
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
        ceiling = Z_Malloc(72, 6, 0)
        P_AddThinker(ceiling)
        let c2da_fresh1 : uint = uint(ceiling)
        c2da_mem[sec + 104] = uint8(c2da_fresh1)
        c2da_mem[sec + 105] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[sec + 106] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[sec + 107] = uint8(c2da_fresh1 >> 0x18)
        c2da_mem[sec + 108] = 0u8
        c2da_mem[sec + 109] = 0u8
        c2da_mem[sec + 110] = 0u8
        c2da_mem[sec + 111] = 0u8
        let c2da_fresh2 : uint = 123u
        c2da_mem[ceiling + 16] = uint8(c2da_fresh2)
        c2da_mem[ceiling + 17] = uint8(c2da_fresh2 >> 0x8)
        c2da_mem[ceiling + 18] = uint8(c2da_fresh2 >> 0x10)
        c2da_mem[ceiling + 19] = uint8(c2da_fresh2 >> 0x18)
        c2da_mem[ceiling + 20] = 0u8
        c2da_mem[ceiling + 21] = 0u8
        c2da_mem[ceiling + 22] = 0u8
        c2da_mem[ceiling + 23] = 0u8
        let c2da_fresh3 : uint = uint(sec)
        c2da_mem[ceiling + 32] = uint8(c2da_fresh3)
        c2da_mem[ceiling + 33] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[ceiling + 34] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[ceiling + 35] = uint8(c2da_fresh3 >> 0x18)
        c2da_mem[ceiling + 36] = 0u8
        c2da_mem[ceiling + 37] = 0u8
        c2da_mem[ceiling + 38] = 0u8
        c2da_mem[ceiling + 39] = 0u8
        let c2da_fresh4 : uint = 0u
        let c2da_fresh5 : uint = c2da_fresh4
        c2da_mem[ceiling + 52] = uint8(c2da_fresh5)
        c2da_mem[ceiling + 53] = uint8(c2da_fresh5 >> 0x8)
        c2da_mem[ceiling + 54] = uint8(c2da_fresh5 >> 0x10)
        c2da_mem[ceiling + 55] = uint8(c2da_fresh5 >> 0x18)
        c2da_fresh6 = type_0
        if (c2da_fresh6 <= 0x5u) {
            goto int(c2da_fresh6) + 3
        }
        goto label 2
        label 7:
        let c2da_fresh7 : uint = 1u
        let c2da_fresh8 : uint = c2da_fresh7
        c2da_mem[ceiling + 52] = uint8(c2da_fresh8)
        c2da_mem[ceiling + 53] = uint8(c2da_fresh8 >> 0x8)
        c2da_mem[ceiling + 54] = uint8(c2da_fresh8 >> 0x10)
        c2da_mem[ceiling + 55] = uint8(c2da_fresh8 >> 0x18)
        let c2da_fresh9 : int = int(uint(c2da_mem[sec + 4]) | uint(c2da_mem[sec + 5]) << 0x8 | uint(c2da_mem[sec + 6]) << 0x10 | uint(c2da_mem[sec + 7]) << 0x18)
        let c2da_fresh10 : uint = uint(c2da_fresh9)
        c2da_mem[ceiling + 44] = uint8(c2da_fresh10)
        c2da_mem[ceiling + 45] = uint8(c2da_fresh10 >> 0x8)
        c2da_mem[ceiling + 46] = uint8(c2da_fresh10 >> 0x10)
        c2da_mem[ceiling + 47] = uint8(c2da_fresh10 >> 0x18)
        let c2da_fresh11 : int = int(uint(c2da_mem[sec]) | uint(c2da_mem[sec + 1]) << 0x8 | uint(c2da_mem[sec + 2]) << 0x10 | uint(c2da_mem[sec + 3]) << 0x18) + 8 * (1 << 16)
        let c2da_fresh12 : uint = uint(c2da_fresh11)
        c2da_mem[ceiling + 40] = uint8(c2da_fresh12)
        c2da_mem[ceiling + 41] = uint8(c2da_fresh12 >> 0x8)
        c2da_mem[ceiling + 42] = uint8(c2da_fresh12 >> 0x10)
        c2da_mem[ceiling + 43] = uint8(c2da_fresh12 >> 0x18)
        let c2da_fresh13 : int = -1
        let c2da_fresh14 : uint = uint(c2da_fresh13)
        c2da_mem[ceiling + 56] = uint8(c2da_fresh14)
        c2da_mem[ceiling + 57] = uint8(c2da_fresh14 >> 0x8)
        c2da_mem[ceiling + 58] = uint8(c2da_fresh14 >> 0x10)
        c2da_mem[ceiling + 59] = uint8(c2da_fresh14 >> 0x18)
        let c2da_fresh15 : int = (1 << 16) * 2
        let c2da_fresh16 : uint = uint(c2da_fresh15)
        c2da_mem[ceiling + 48] = uint8(c2da_fresh16)
        c2da_mem[ceiling + 49] = uint8(c2da_fresh16 >> 0x8)
        c2da_mem[ceiling + 50] = uint8(c2da_fresh16 >> 0x10)
        c2da_mem[ceiling + 51] = uint8(c2da_fresh16 >> 0x18)
        goto label 2
        label 6:
        label 8:
        let c2da_fresh17 : uint = 1u
        let c2da_fresh18 : uint = c2da_fresh17
        c2da_mem[ceiling + 52] = uint8(c2da_fresh18)
        c2da_mem[ceiling + 53] = uint8(c2da_fresh18 >> 0x8)
        c2da_mem[ceiling + 54] = uint8(c2da_fresh18 >> 0x10)
        c2da_mem[ceiling + 55] = uint8(c2da_fresh18 >> 0x18)
        let c2da_fresh19 : int = int(uint(c2da_mem[sec + 4]) | uint(c2da_mem[sec + 5]) << 0x8 | uint(c2da_mem[sec + 6]) << 0x10 | uint(c2da_mem[sec + 7]) << 0x18)
        let c2da_fresh20 : uint = uint(c2da_fresh19)
        c2da_mem[ceiling + 44] = uint8(c2da_fresh20)
        c2da_mem[ceiling + 45] = uint8(c2da_fresh20 >> 0x8)
        c2da_mem[ceiling + 46] = uint8(c2da_fresh20 >> 0x10)
        c2da_mem[ceiling + 47] = uint8(c2da_fresh20 >> 0x18)
        label 3:
        label 5:
        let c2da_fresh21 : int = int(uint(c2da_mem[sec]) | uint(c2da_mem[sec + 1]) << 0x8 | uint(c2da_mem[sec + 2]) << 0x10 | uint(c2da_mem[sec + 3]) << 0x18)
        let c2da_fresh22 : uint = uint(c2da_fresh21)
        c2da_mem[ceiling + 40] = uint8(c2da_fresh22)
        c2da_mem[ceiling + 41] = uint8(c2da_fresh22 >> 0x8)
        c2da_mem[ceiling + 42] = uint8(c2da_fresh22 >> 0x10)
        c2da_mem[ceiling + 43] = uint8(c2da_fresh22 >> 0x18)
        if (type_0 != 0u) {
            let c2da_fresh23 : int = int(uint(c2da_mem[ceiling + 40]) | uint(c2da_mem[ceiling + 41]) << 0x8 | uint(c2da_mem[ceiling + 42]) << 0x10 | uint(c2da_mem[ceiling + 43]) << 0x18) + 8 * (1 << 16)
            let c2da_fresh24 : uint = uint(c2da_fresh23)
            c2da_mem[ceiling + 40] = uint8(c2da_fresh24)
            c2da_mem[ceiling + 41] = uint8(c2da_fresh24 >> 0x8)
            c2da_mem[ceiling + 42] = uint8(c2da_fresh24 >> 0x10)
            c2da_mem[ceiling + 43] = uint8(c2da_fresh24 >> 0x18)
        }
        let c2da_fresh25 : int = -1
        let c2da_fresh26 : uint = uint(c2da_fresh25)
        c2da_mem[ceiling + 56] = uint8(c2da_fresh26)
        c2da_mem[ceiling + 57] = uint8(c2da_fresh26 >> 0x8)
        c2da_mem[ceiling + 58] = uint8(c2da_fresh26 >> 0x10)
        c2da_mem[ceiling + 59] = uint8(c2da_fresh26 >> 0x18)
        let c2da_fresh27 : int = 1 << 16
        let c2da_fresh28 : uint = uint(c2da_fresh27)
        c2da_mem[ceiling + 48] = uint8(c2da_fresh28)
        c2da_mem[ceiling + 49] = uint8(c2da_fresh28 >> 0x8)
        c2da_mem[ceiling + 50] = uint8(c2da_fresh28 >> 0x10)
        c2da_mem[ceiling + 51] = uint8(c2da_fresh28 >> 0x18)
        goto label 2
        label 4:
        let c2da_fresh29 : int = P_FindHighestCeilingSurrounding(sec)
        let c2da_fresh30 : uint = uint(c2da_fresh29)
        c2da_mem[ceiling + 44] = uint8(c2da_fresh30)
        c2da_mem[ceiling + 45] = uint8(c2da_fresh30 >> 0x8)
        c2da_mem[ceiling + 46] = uint8(c2da_fresh30 >> 0x10)
        c2da_mem[ceiling + 47] = uint8(c2da_fresh30 >> 0x18)
        let c2da_fresh31 : int = 1
        let c2da_fresh32 : uint = uint(c2da_fresh31)
        c2da_mem[ceiling + 56] = uint8(c2da_fresh32)
        c2da_mem[ceiling + 57] = uint8(c2da_fresh32 >> 0x8)
        c2da_mem[ceiling + 58] = uint8(c2da_fresh32 >> 0x10)
        c2da_mem[ceiling + 59] = uint8(c2da_fresh32 >> 0x18)
        let c2da_fresh33 : int = 1 << 16
        let c2da_fresh34 : uint = uint(c2da_fresh33)
        c2da_mem[ceiling + 48] = uint8(c2da_fresh34)
        c2da_mem[ceiling + 49] = uint8(c2da_fresh34 >> 0x8)
        c2da_mem[ceiling + 50] = uint8(c2da_fresh34 >> 0x10)
        c2da_mem[ceiling + 51] = uint8(c2da_fresh34 >> 0x18)
        label 2:
        let c2da_fresh35 : int = int(int16(uint(c2da_mem[sec + 16]) | uint(c2da_mem[sec + 17]) << 0x8))
        let c2da_fresh36 : uint = uint(c2da_fresh35)
        c2da_mem[ceiling + 60] = uint8(c2da_fresh36)
        c2da_mem[ceiling + 61] = uint8(c2da_fresh36 >> 0x8)
        c2da_mem[ceiling + 62] = uint8(c2da_fresh36 >> 0x10)
        c2da_mem[ceiling + 63] = uint8(c2da_fresh36 >> 0x18)
        let c2da_fresh37 : uint = type_0
        c2da_mem[ceiling + 24] = uint8(c2da_fresh37)
        c2da_mem[ceiling + 25] = uint8(c2da_fresh37 >> 0x8)
        c2da_mem[ceiling + 26] = uint8(c2da_fresh37 >> 0x10)
        c2da_mem[ceiling + 27] = uint8(c2da_fresh37 >> 0x18)
        P_AddActiveCeiling(ceiling)
    }
    return rtn
}
[export, sideeffects]
def P_AddActiveCeiling(var c : int) {
    for (i in range(0, 30)) {
        if (activeceilings[i] == 0) {
            activeceilings[i] = int(c)  // nolint:PERF020
            return
        }
    }
    return
}
[export, sideeffects]
def T_MoveCeiling(var ceiling_0 : int) {
    var c2da_fresh38 : int
    var c2da_fresh39 : uint
    var c2da_fresh40 : uint
    var c2da_fresh43 : uint
    var c2da_fresh44 : uint
    var c2da_fresh49 : uint
    var res : uint
    c2da_fresh38 = int(uint(c2da_mem[ceiling_0 + 56]) | uint(c2da_mem[ceiling_0 + 57]) << 0x8 | uint(c2da_mem[ceiling_0 + 58]) << 0x10 | uint(c2da_mem[ceiling_0 + 59]) << 0x18)
    if (c2da_fresh38 == -1) {
        goto label 8
    } elif (c2da_fresh38 == 0) {
        goto label 0
    } elif (c2da_fresh38 == 1) {
        goto label 1
    } else {
        return
    }
    label 0:
    return
    label 1:
    res = T_MovePlane(int(uint(c2da_mem[ceiling_0 + 32]) | uint(c2da_mem[ceiling_0 + 33]) << 0x8 | uint(c2da_mem[ceiling_0 + 34]) << 0x10 | uint(c2da_mem[ceiling_0 + 35]) << 0x18), int(uint(c2da_mem[ceiling_0 + 48]) | uint(c2da_mem[ceiling_0 + 49]) << 0x8 | uint(c2da_mem[ceiling_0 + 50]) << 0x10 | uint(c2da_mem[ceiling_0 + 51]) << 0x18), int(uint(c2da_mem[ceiling_0 + 44]) | uint(c2da_mem[ceiling_0 + 45]) << 0x8 | uint(c2da_mem[ceiling_0 + 46]) << 0x10 | uint(c2da_mem[ceiling_0 + 47]) << 0x18), 0u, 1, int(uint(c2da_mem[ceiling_0 + 56]) | uint(c2da_mem[ceiling_0 + 57]) << 0x8 | uint(c2da_mem[ceiling_0 + 58]) << 0x10 | uint(c2da_mem[ceiling_0 + 59]) << 0x18))
    if ((leveltime & 7) == 0) {
        c2da_fresh39 = uint(c2da_mem[ceiling_0 + 24]) | uint(c2da_mem[ceiling_0 + 25]) << 0x8 | uint(c2da_mem[ceiling_0 + 26]) << 0x10 | uint(c2da_mem[ceiling_0 + 27]) << 0x18
        if (c2da_fresh39 == 0x5u) {
        } else {
            S_StartSound(int(uint(c2da_mem[ceiling_0 + 32]) | uint(c2da_mem[ceiling_0 + 33]) << 0x8 | uint(c2da_mem[ceiling_0 + 34]) << 0x10 | uint(c2da_mem[ceiling_0 + 35]) << 0x18) + 48, 22)
        }
    }
    if (res != 2u) {
        goto label 7
    }
    c2da_fresh40 = uint(c2da_mem[ceiling_0 + 24]) | uint(c2da_mem[ceiling_0 + 25]) << 0x8 | uint(c2da_mem[ceiling_0 + 26]) << 0x10 | uint(c2da_mem[ceiling_0 + 27]) << 0x18
    if (c2da_fresh40 == 0x1u) {
        goto label 2
    } elif (c2da_fresh40 == 0x3u) {
        goto label 4
    } elif (c2da_fresh40 == 0x4u) {
        goto label 4
    } elif (c2da_fresh40 == 0x5u) {
        goto label 3
    } else {
        goto label 5
    }
    label 2:
    P_RemoveActiveCeiling(ceiling_0)
    goto label 6
    label 3:
    S_StartSound(int(uint(c2da_mem[ceiling_0 + 32]) | uint(c2da_mem[ceiling_0 + 33]) << 0x8 | uint(c2da_mem[ceiling_0 + 34]) << 0x10 | uint(c2da_mem[ceiling_0 + 35]) << 0x18) + 48, 19)
    label 4:
    let c2da_fresh41 : int = -1
    let c2da_fresh42 : uint = uint(c2da_fresh41)
    c2da_mem[ceiling_0 + 56] = uint8(c2da_fresh42)
    c2da_mem[ceiling_0 + 57] = uint8(c2da_fresh42 >> 0x8)
    c2da_mem[ceiling_0 + 58] = uint8(c2da_fresh42 >> 0x10)
    c2da_mem[ceiling_0 + 59] = uint8(c2da_fresh42 >> 0x18)
    label 5:
    label 6:
    label 7:
    return
    label 8:
    res = T_MovePlane(int(uint(c2da_mem[ceiling_0 + 32]) | uint(c2da_mem[ceiling_0 + 33]) << 0x8 | uint(c2da_mem[ceiling_0 + 34]) << 0x10 | uint(c2da_mem[ceiling_0 + 35]) << 0x18), int(uint(c2da_mem[ceiling_0 + 48]) | uint(c2da_mem[ceiling_0 + 49]) << 0x8 | uint(c2da_mem[ceiling_0 + 50]) << 0x10 | uint(c2da_mem[ceiling_0 + 51]) << 0x18), int(uint(c2da_mem[ceiling_0 + 40]) | uint(c2da_mem[ceiling_0 + 41]) << 0x8 | uint(c2da_mem[ceiling_0 + 42]) << 0x10 | uint(c2da_mem[ceiling_0 + 43]) << 0x18), uint(c2da_mem[ceiling_0 + 52]) | uint(c2da_mem[ceiling_0 + 53]) << 0x8 | uint(c2da_mem[ceiling_0 + 54]) << 0x10 | uint(c2da_mem[ceiling_0 + 55]) << 0x18, 1, int(uint(c2da_mem[ceiling_0 + 56]) | uint(c2da_mem[ceiling_0 + 57]) << 0x8 | uint(c2da_mem[ceiling_0 + 58]) << 0x10 | uint(c2da_mem[ceiling_0 + 59]) << 0x18))
    if ((leveltime & 7) == 0) {
        c2da_fresh43 = uint(c2da_mem[ceiling_0 + 24]) | uint(c2da_mem[ceiling_0 + 25]) << 0x8 | uint(c2da_mem[ceiling_0 + 26]) << 0x10 | uint(c2da_mem[ceiling_0 + 27]) << 0x18
        if (c2da_fresh43 == 0x5u) {
        } else {
            S_StartSound(int(uint(c2da_mem[ceiling_0 + 32]) | uint(c2da_mem[ceiling_0 + 33]) << 0x8 | uint(c2da_mem[ceiling_0 + 34]) << 0x10 | uint(c2da_mem[ceiling_0 + 35]) << 0x18) + 48, 22)
        }
    }
    if (res != 2u) {
        goto label 11
    }
    c2da_fresh44 = uint(c2da_mem[ceiling_0 + 24]) | uint(c2da_mem[ceiling_0 + 25]) << 0x8 | uint(c2da_mem[ceiling_0 + 26]) << 0x10 | uint(c2da_mem[ceiling_0 + 27]) << 0x18
    if (c2da_fresh44 <= 0x5u) {
        goto int(c2da_fresh44) + 12
    }
    goto label 9
    label 17:
    S_StartSound(int(uint(c2da_mem[ceiling_0 + 32]) | uint(c2da_mem[ceiling_0 + 33]) << 0x8 | uint(c2da_mem[ceiling_0 + 34]) << 0x10 | uint(c2da_mem[ceiling_0 + 35]) << 0x18) + 48, 19)
    label 15:
    let c2da_fresh45 : int = 1 << 16
    let c2da_fresh46 : uint = uint(c2da_fresh45)
    c2da_mem[ceiling_0 + 48] = uint8(c2da_fresh46)
    c2da_mem[ceiling_0 + 49] = uint8(c2da_fresh46 >> 0x8)
    c2da_mem[ceiling_0 + 50] = uint8(c2da_fresh46 >> 0x10)
    c2da_mem[ceiling_0 + 51] = uint8(c2da_fresh46 >> 0x18)
    label 16:
    let c2da_fresh47 : int = 1
    let c2da_fresh48 : uint = uint(c2da_fresh47)
    c2da_mem[ceiling_0 + 56] = uint8(c2da_fresh48)
    c2da_mem[ceiling_0 + 57] = uint8(c2da_fresh48 >> 0x8)
    c2da_mem[ceiling_0 + 58] = uint8(c2da_fresh48 >> 0x10)
    c2da_mem[ceiling_0 + 59] = uint8(c2da_fresh48 >> 0x18)
    goto label 10
    label 12:
    label 14:
    P_RemoveActiveCeiling(ceiling_0)
    label 9:
    label 13:
    label 10:
    return
    label 11:
    if (res == 1u) {
        c2da_fresh49 = uint(c2da_mem[ceiling_0 + 24]) | uint(c2da_mem[ceiling_0 + 25]) << 0x8 | uint(c2da_mem[ceiling_0 + 26]) << 0x10 | uint(c2da_mem[ceiling_0 + 27]) << 0x18
        if (c2da_fresh49 == 0x5u || c2da_fresh49 == 0x3u || c2da_fresh49 == 0x2u) {
            let c2da_fresh50 : int = (1 << 16) / 8
            let c2da_fresh51 : uint = uint(c2da_fresh50)
            c2da_mem[ceiling_0 + 48] = uint8(c2da_fresh51)
            c2da_mem[ceiling_0 + 49] = uint8(c2da_fresh51 >> 0x8)
            c2da_mem[ceiling_0 + 50] = uint8(c2da_fresh51 >> 0x10)
            c2da_mem[ceiling_0 + 51] = uint8(c2da_fresh51 >> 0x18)
        }
    }
    return
}
[export, sideeffects]
def P_RemoveActiveCeiling(var c_0 : int) {
    for (i_0 in range(0, 30)) {
        if (activeceilings[i_0] == c_0) {
            let c2da_fresh52 : int = activeceilings[i_0] + 32
            let c2da_fresh53 : int = int(uint(c2da_mem[c2da_fresh52]) | uint(c2da_mem[c2da_fresh52 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh52 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh52 + 3]) << 0x18) + 104
            let c2da_fresh54 : uint = 0u
            c2da_mem[c2da_fresh53] = uint8(c2da_fresh54)
            c2da_mem[c2da_fresh53 + 1] = uint8(c2da_fresh54 >> 0x8)
            c2da_mem[c2da_fresh53 + 2] = uint8(c2da_fresh54 >> 0x10)
            c2da_mem[c2da_fresh53 + 3] = uint8(c2da_fresh54 >> 0x18)
            c2da_mem[c2da_fresh53 + 4] = 0u8
            c2da_mem[c2da_fresh53 + 5] = 0u8
            c2da_mem[c2da_fresh53 + 6] = 0u8
            c2da_mem[c2da_fresh53 + 7] = 0u8
            P_RemoveThinker(activeceilings[i_0])
            activeceilings[i_0] = 0
            break
        }
    }
    return
}
[export, sideeffects]
def P_ActivateInStasisCeiling(var line_0 : int) {
    for (i_1 in range(0, 30)) {
        var c2da_fresh56 : int = 0
        if (activeceilings[i_1] != 0) {
            let c2da_fresh55 : int = activeceilings[i_1] + 60
            if (int(uint(c2da_mem[c2da_fresh55]) | uint(c2da_mem[c2da_fresh55 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh55 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh55 + 3]) << 0x18) == int(int16(uint(c2da_mem[line_0 + 28]) | uint(c2da_mem[line_0 + 29]) << 0x8))) {
                c2da_fresh56 = 1
            }
        }
        var c2da_fresh58 : int = 0
        if (c2da_fresh56 != 0) {
            let c2da_fresh57 : int = activeceilings[i_1] + 56
            if (int(uint(c2da_mem[c2da_fresh57]) | uint(c2da_mem[c2da_fresh57 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh57 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh57 + 3]) << 0x18) == 0) {
                c2da_fresh58 = 1
            }
        }
        if (c2da_fresh58 != 0) {
            let c2da_fresh59 : int = activeceilings[i_1] + 56
            let c2da_fresh60 : int = activeceilings[i_1] + 64
            let c2da_fresh61 : int = int(uint(c2da_mem[c2da_fresh60]) | uint(c2da_mem[c2da_fresh60 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh60 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh60 + 3]) << 0x18)
            let c2da_fresh62 : uint = uint(c2da_fresh61)
            c2da_mem[c2da_fresh59] = uint8(c2da_fresh62)
            c2da_mem[c2da_fresh59 + 1] = uint8(c2da_fresh62 >> 0x8)
            c2da_mem[c2da_fresh59 + 2] = uint8(c2da_fresh62 >> 0x10)
            c2da_mem[c2da_fresh59 + 3] = uint8(c2da_fresh62 >> 0x18)
            let c2da_fresh63 : int = activeceilings[i_1] + 16
            let c2da_fresh64 : uint = 123u
            c2da_mem[c2da_fresh63] = uint8(c2da_fresh64)
            c2da_mem[c2da_fresh63 + 1] = uint8(c2da_fresh64 >> 0x8)
            c2da_mem[c2da_fresh63 + 2] = uint8(c2da_fresh64 >> 0x10)
            c2da_mem[c2da_fresh63 + 3] = uint8(c2da_fresh64 >> 0x18)
            c2da_mem[c2da_fresh63 + 4] = 0u8
            c2da_mem[c2da_fresh63 + 5] = 0u8
            c2da_mem[c2da_fresh63 + 6] = 0u8
            c2da_mem[c2da_fresh63 + 7] = 0u8
        }
    }
    return
}
[export, sideeffects]
def EV_CeilingCrushStop(var line_1 : int) : int {
    var rtn_0 : int = 0
    for (i_2 in range(0, 30)) {
        var c2da_fresh66 : int = 0
        if (activeceilings[i_2] != 0) {
            let c2da_fresh65 : int = activeceilings[i_2] + 60
            if (int(uint(c2da_mem[c2da_fresh65]) | uint(c2da_mem[c2da_fresh65 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh65 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh65 + 3]) << 0x18) == int(int16(uint(c2da_mem[line_1 + 28]) | uint(c2da_mem[line_1 + 29]) << 0x8))) {
                c2da_fresh66 = 1
            }
        }
        var c2da_fresh68 : int = 0
        if (c2da_fresh66 != 0) {
            let c2da_fresh67 : int = activeceilings[i_2] + 56
            if (int(uint(c2da_mem[c2da_fresh67]) | uint(c2da_mem[c2da_fresh67 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh67 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh67 + 3]) << 0x18) != 0) {
                c2da_fresh68 = 1
            }
        }
        if (c2da_fresh68 != 0) {
            let c2da_fresh69 : int = activeceilings[i_2] + 64
            let c2da_fresh70 : int = activeceilings[i_2] + 56
            let c2da_fresh71 : int = int(uint(c2da_mem[c2da_fresh70]) | uint(c2da_mem[c2da_fresh70 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh70 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh70 + 3]) << 0x18)
            let c2da_fresh72 : uint = uint(c2da_fresh71)
            c2da_mem[c2da_fresh69] = uint8(c2da_fresh72)
            c2da_mem[c2da_fresh69 + 1] = uint8(c2da_fresh72 >> 0x8)
            c2da_mem[c2da_fresh69 + 2] = uint8(c2da_fresh72 >> 0x10)
            c2da_mem[c2da_fresh69 + 3] = uint8(c2da_fresh72 >> 0x18)
            let c2da_fresh73 : int = activeceilings[i_2] + 16
            let c2da_fresh74 : uint = 0u
            c2da_mem[c2da_fresh73] = uint8(c2da_fresh74)
            c2da_mem[c2da_fresh73 + 1] = uint8(c2da_fresh74 >> 0x8)
            c2da_mem[c2da_fresh73 + 2] = uint8(c2da_fresh74 >> 0x10)
            c2da_mem[c2da_fresh73 + 3] = uint8(c2da_fresh74 >> 0x18)
            c2da_mem[c2da_fresh73 + 4] = 0u8
            c2da_mem[c2da_fresh73 + 5] = 0u8
            c2da_mem[c2da_fresh73 + 6] = 0u8
            c2da_mem[c2da_fresh73 + 7] = 0u8
            let c2da_fresh75 : int = activeceilings[i_2] + 56
            let c2da_fresh76 : int = 0
            let c2da_fresh77 : uint = uint(c2da_fresh76)
            c2da_mem[c2da_fresh75] = uint8(c2da_fresh77)
            c2da_mem[c2da_fresh75 + 1] = uint8(c2da_fresh77 >> 0x8)
            c2da_mem[c2da_fresh75 + 2] = uint8(c2da_fresh77 >> 0x10)
            c2da_mem[c2da_fresh75 + 3] = uint8(c2da_fresh77 >> 0x18)
            rtn_0 = 1
        }
    }
    return rtn_0
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_p_ceilng() {
    if (length(c2da_fn_table5) < 124) {
        resize(c2da_fn_table5, 124)
    }
    c2da_fn_table5[123] = @@T_MoveCeiling
}

[init]
def private c2da_lin_relink_init_p_ceilng() {
    c2da_relink_p_ceilng()
}
