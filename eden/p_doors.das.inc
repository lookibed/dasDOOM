[export, sideeffects]
def EV_VerticalDoor(var line : int; var thing : int) {
    var c2da_fresh0 : int
    var c2da_fresh6 : int
    var c2da_fresh15 : int
    var c2da_fresh25 : int
    var player : int
    var sec : int
    var door : int
    var side : int = 0
    player = int(uint(c2da_mem[thing + 192]) | uint(c2da_mem[thing + 193]) << 0x8 | uint(c2da_mem[thing + 194]) << 0x10 | uint(c2da_mem[thing + 195]) << 0x18)
    c2da_fresh0 = int(int16(uint(c2da_mem[line + 26]) | uint(c2da_mem[line + 27]) << 0x8))
    if (c2da_fresh0 == 26 || c2da_fresh0 == 32) {
        if (player == 0) {
            return
        }
        if ((uint(c2da_mem[player + 80 + 0 * 4]) | uint(c2da_mem[player + 80 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 80 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 80 + 0 * 4 + 3]) << 0x18) == 0 && (uint(c2da_mem[player + 80 + 3 * 4]) | uint(c2da_mem[player + 80 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 80 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 80 + 3 * 4 + 3]) << 0x18) == 0) {
            let c2da_fresh1 : uint = 358816u
            c2da_mem[player + 232] = uint8(c2da_fresh1)
            c2da_mem[player + 233] = uint8(c2da_fresh1 >> 0x8)
            c2da_mem[player + 234] = uint8(c2da_fresh1 >> 0x10)
            c2da_mem[player + 235] = uint8(c2da_fresh1 >> 0x18)
            c2da_mem[player + 236] = 0u8
            c2da_mem[player + 237] = 0u8
            c2da_mem[player + 238] = 0u8
            c2da_mem[player + 239] = 0u8
            S_StartSound(0, 34)
            return
        }
    } elif (c2da_fresh0 == 27 || c2da_fresh0 == 34) {
        if (player == 0) {
            return
        }
        if ((uint(c2da_mem[player + 80 + 1 * 4]) | uint(c2da_mem[player + 80 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 80 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 80 + 1 * 4 + 3]) << 0x18) == 0 && (uint(c2da_mem[player + 80 + 4 * 4]) | uint(c2da_mem[player + 80 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 80 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 80 + 4 * 4 + 3]) << 0x18) == 0) {
            let c2da_fresh2 : uint = 358854u
            c2da_mem[player + 232] = uint8(c2da_fresh2)
            c2da_mem[player + 233] = uint8(c2da_fresh2 >> 0x8)
            c2da_mem[player + 234] = uint8(c2da_fresh2 >> 0x10)
            c2da_mem[player + 235] = uint8(c2da_fresh2 >> 0x18)
            c2da_mem[player + 236] = 0u8
            c2da_mem[player + 237] = 0u8
            c2da_mem[player + 238] = 0u8
            c2da_mem[player + 239] = 0u8
            S_StartSound(0, 34)
            return
        }
    } elif (c2da_fresh0 == 28 || c2da_fresh0 == 33) {
        if (player == 0) {
            return
        }
        if ((uint(c2da_mem[player + 80 + 2 * 4]) | uint(c2da_mem[player + 80 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 80 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 80 + 2 * 4 + 3]) << 0x18) == 0 && (uint(c2da_mem[player + 80 + 5 * 4]) | uint(c2da_mem[player + 80 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 80 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 80 + 5 * 4 + 3]) << 0x18) == 0) {
            let c2da_fresh3 : uint = 358894u
            c2da_mem[player + 232] = uint8(c2da_fresh3)
            c2da_mem[player + 233] = uint8(c2da_fresh3 >> 0x8)
            c2da_mem[player + 234] = uint8(c2da_fresh3 >> 0x10)
            c2da_mem[player + 235] = uint8(c2da_fresh3 >> 0x18)
            c2da_mem[player + 236] = 0u8
            c2da_mem[player + 237] = 0u8
            c2da_mem[player + 238] = 0u8
            c2da_mem[player + 239] = 0u8
            S_StartSound(0, 34)
            return
        }
    }
    let c2da_fresh4 : int = line + 30 + (side ^ 1) * 2
    let c2da_fresh5 : int = sides + int(int16(uint(c2da_mem[c2da_fresh4]) | uint(c2da_mem[c2da_fresh4 + 1]) << 0x8)) * 24 + 16
    sec = int(uint(c2da_mem[c2da_fresh5]) | uint(c2da_mem[c2da_fresh5 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh5 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh5 + 3]) << 0x18)
    if (int(uint(c2da_mem[sec + 104]) | uint(c2da_mem[sec + 105]) << 0x8 | uint(c2da_mem[sec + 106]) << 0x10 | uint(c2da_mem[sec + 107]) << 0x18) != 0) {
        door = int(uint(c2da_mem[sec + 104]) | uint(c2da_mem[sec + 105]) << 0x8 | uint(c2da_mem[sec + 106]) << 0x10 | uint(c2da_mem[sec + 107]) << 0x18)
        c2da_fresh6 = int(int16(uint(c2da_mem[line + 26]) | uint(c2da_mem[line + 27]) << 0x8))
        if (c2da_fresh6 == 1 || c2da_fresh6 == 26 || c2da_fresh6 == 27 || c2da_fresh6 == 28 || c2da_fresh6 == 117) {
            if (int(uint(c2da_mem[door + 48]) | uint(c2da_mem[door + 49]) << 0x8 | uint(c2da_mem[door + 50]) << 0x10 | uint(c2da_mem[door + 51]) << 0x18) == -1) {
                let c2da_fresh7 : int = 1
                let c2da_fresh8 : uint = uint(c2da_fresh7)
                c2da_mem[door + 48] = uint8(c2da_fresh8)
                c2da_mem[door + 49] = uint8(c2da_fresh8 >> 0x8)
                c2da_mem[door + 50] = uint8(c2da_fresh8 >> 0x10)
                c2da_mem[door + 51] = uint8(c2da_fresh8 >> 0x18)
            } else {
                if (int(uint(c2da_mem[thing + 192]) | uint(c2da_mem[thing + 193]) << 0x8 | uint(c2da_mem[thing + 194]) << 0x10 | uint(c2da_mem[thing + 195]) << 0x18) == 0) {
                    return
                }
                if (int(uint(c2da_mem[door + 16]) | uint(c2da_mem[door + 17]) << 0x8 | uint(c2da_mem[door + 18]) << 0x10 | uint(c2da_mem[door + 19]) << 0x18) == 124) {
                    let c2da_fresh9 : int = -1
                    let c2da_fresh10 : uint = uint(c2da_fresh9)
                    c2da_mem[door + 48] = uint8(c2da_fresh10)
                    c2da_mem[door + 49] = uint8(c2da_fresh10 >> 0x8)
                    c2da_mem[door + 50] = uint8(c2da_fresh10 >> 0x10)
                    c2da_mem[door + 51] = uint8(c2da_fresh10 >> 0x18)
                } elif (int(uint(c2da_mem[door + 16]) | uint(c2da_mem[door + 17]) << 0x8 | uint(c2da_mem[door + 18]) << 0x10 | uint(c2da_mem[door + 19]) << 0x18) == 125) {
                    let c2da_fresh11 : int = -1
                    let c2da_fresh12 : uint = uint(c2da_fresh11)
                    c2da_mem[door + 44] = uint8(c2da_fresh12)
                    c2da_mem[door + 45] = uint8(c2da_fresh12 >> 0x8)
                    c2da_mem[door + 46] = uint8(c2da_fresh12 >> 0x10)
                    c2da_mem[door + 47] = uint8(c2da_fresh12 >> 0x18)
                } else {
                    c2da_lin_printf(uint64(int(c2da_std_stderr())), 358931, [])
                    let c2da_fresh13 : int = -1
                    let c2da_fresh14 : uint = uint(c2da_fresh13)
                    c2da_mem[door + 48] = uint8(c2da_fresh14)
                    c2da_mem[door + 49] = uint8(c2da_fresh14 >> 0x8)
                    c2da_mem[door + 50] = uint8(c2da_fresh14 >> 0x10)
                    c2da_mem[door + 51] = uint8(c2da_fresh14 >> 0x18)
                }
            }
            return
        }
    }
    c2da_fresh15 = int(int16(uint(c2da_mem[line + 26]) | uint(c2da_mem[line + 27]) << 0x8))
    if (c2da_fresh15 == 117 || c2da_fresh15 == 118) {
        S_StartSound(sec + 48, 88)
    } elif (c2da_fresh15 == 1 || c2da_fresh15 == 31) {
        S_StartSound(sec + 48, 20)
    } else {
        S_StartSound(sec + 48, 20)
    }
    door = Z_Malloc(64, 6, 0)
    P_AddThinker(door)
    let c2da_fresh16 : uint = uint(door)
    c2da_mem[sec + 104] = uint8(c2da_fresh16)
    c2da_mem[sec + 105] = uint8(c2da_fresh16 >> 0x8)
    c2da_mem[sec + 106] = uint8(c2da_fresh16 >> 0x10)
    c2da_mem[sec + 107] = uint8(c2da_fresh16 >> 0x18)
    c2da_mem[sec + 108] = 0u8
    c2da_mem[sec + 109] = 0u8
    c2da_mem[sec + 110] = 0u8
    c2da_mem[sec + 111] = 0u8
    let c2da_fresh17 : uint = 124u
    c2da_mem[door + 16] = uint8(c2da_fresh17)
    c2da_mem[door + 17] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[door + 18] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[door + 19] = uint8(c2da_fresh17 >> 0x18)
    c2da_mem[door + 20] = 0u8
    c2da_mem[door + 21] = 0u8
    c2da_mem[door + 22] = 0u8
    c2da_mem[door + 23] = 0u8
    let c2da_fresh18 : uint = uint(sec)
    c2da_mem[door + 32] = uint8(c2da_fresh18)
    c2da_mem[door + 33] = uint8(c2da_fresh18 >> 0x8)
    c2da_mem[door + 34] = uint8(c2da_fresh18 >> 0x10)
    c2da_mem[door + 35] = uint8(c2da_fresh18 >> 0x18)
    c2da_mem[door + 36] = 0u8
    c2da_mem[door + 37] = 0u8
    c2da_mem[door + 38] = 0u8
    c2da_mem[door + 39] = 0u8
    let c2da_fresh19 : int = 1
    let c2da_fresh20 : uint = uint(c2da_fresh19)
    c2da_mem[door + 48] = uint8(c2da_fresh20)
    c2da_mem[door + 49] = uint8(c2da_fresh20 >> 0x8)
    c2da_mem[door + 50] = uint8(c2da_fresh20 >> 0x10)
    c2da_mem[door + 51] = uint8(c2da_fresh20 >> 0x18)
    let c2da_fresh21 : int = (1 << 16) * 2
    let c2da_fresh22 : uint = uint(c2da_fresh21)
    c2da_mem[door + 44] = uint8(c2da_fresh22)
    c2da_mem[door + 45] = uint8(c2da_fresh22 >> 0x8)
    c2da_mem[door + 46] = uint8(c2da_fresh22 >> 0x10)
    c2da_mem[door + 47] = uint8(c2da_fresh22 >> 0x18)
    let c2da_fresh23 : int = 150
    let c2da_fresh24 : uint = uint(c2da_fresh23)
    c2da_mem[door + 52] = uint8(c2da_fresh24)
    c2da_mem[door + 53] = uint8(c2da_fresh24 >> 0x8)
    c2da_mem[door + 54] = uint8(c2da_fresh24 >> 0x10)
    c2da_mem[door + 55] = uint8(c2da_fresh24 >> 0x18)
    c2da_fresh25 = int(int16(uint(c2da_mem[line + 26]) | uint(c2da_mem[line + 27]) << 0x8))
    if (c2da_fresh25 < 32) {
        if (c2da_fresh25 < 27) {
            if (c2da_fresh25 == 1) {
                goto label 0
            } elif (c2da_fresh25 == 26) {
                goto label 0
            }
        } else {
            if (c2da_fresh25 == 27) {
                goto label 0
            } elif (c2da_fresh25 == 28) {
                goto label 0
            } elif (c2da_fresh25 == 31) {
                goto label 1
            }
        }
    } else {
        if (c2da_fresh25 < 34) {
            if (c2da_fresh25 == 32) {
                goto label 1
            } elif (c2da_fresh25 == 33) {
                goto label 1
            }
        } else {
            if (c2da_fresh25 == 34) {
                goto label 1
            } elif (c2da_fresh25 == 117) {
                goto label 2
            } elif (c2da_fresh25 == 118) {
                goto label 3
            }
        }
    }
    goto label 4
    label 0:
    let c2da_fresh26 : uint = 0u
    let c2da_fresh27 : uint = c2da_fresh26
    c2da_mem[door + 24] = uint8(c2da_fresh27)
    c2da_mem[door + 25] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[door + 26] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[door + 27] = uint8(c2da_fresh27 >> 0x18)
    goto label 4
    label 1:
    let c2da_fresh28 : uint = 3u
    let c2da_fresh29 : uint = c2da_fresh28
    c2da_mem[door + 24] = uint8(c2da_fresh29)
    c2da_mem[door + 25] = uint8(c2da_fresh29 >> 0x8)
    c2da_mem[door + 26] = uint8(c2da_fresh29 >> 0x10)
    c2da_mem[door + 27] = uint8(c2da_fresh29 >> 0x18)
    let c2da_fresh30 : int16 = int16(0)
    let c2da_fresh31 : uint = uint(c2da_fresh30)
    c2da_mem[line + 26] = uint8(c2da_fresh31)
    c2da_mem[line + 27] = uint8(c2da_fresh31 >> 0x8)
    goto label 4
    label 2:
    let c2da_fresh32 : uint = 5u
    let c2da_fresh33 : uint = c2da_fresh32
    c2da_mem[door + 24] = uint8(c2da_fresh33)
    c2da_mem[door + 25] = uint8(c2da_fresh33 >> 0x8)
    c2da_mem[door + 26] = uint8(c2da_fresh33 >> 0x10)
    c2da_mem[door + 27] = uint8(c2da_fresh33 >> 0x18)
    let c2da_fresh34 : int = (1 << 16) * 2 * 4
    let c2da_fresh35 : uint = uint(c2da_fresh34)
    c2da_mem[door + 44] = uint8(c2da_fresh35)
    c2da_mem[door + 45] = uint8(c2da_fresh35 >> 0x8)
    c2da_mem[door + 46] = uint8(c2da_fresh35 >> 0x10)
    c2da_mem[door + 47] = uint8(c2da_fresh35 >> 0x18)
    goto label 4
    label 3:
    let c2da_fresh36 : uint = 6u
    let c2da_fresh37 : uint = c2da_fresh36
    c2da_mem[door + 24] = uint8(c2da_fresh37)
    c2da_mem[door + 25] = uint8(c2da_fresh37 >> 0x8)
    c2da_mem[door + 26] = uint8(c2da_fresh37 >> 0x10)
    c2da_mem[door + 27] = uint8(c2da_fresh37 >> 0x18)
    let c2da_fresh38 : int16 = int16(0)
    let c2da_fresh39 : uint = uint(c2da_fresh38)
    c2da_mem[line + 26] = uint8(c2da_fresh39)
    c2da_mem[line + 27] = uint8(c2da_fresh39 >> 0x8)
    let c2da_fresh40 : int = (1 << 16) * 2 * 4
    let c2da_fresh41 : uint = uint(c2da_fresh40)
    c2da_mem[door + 44] = uint8(c2da_fresh41)
    c2da_mem[door + 45] = uint8(c2da_fresh41 >> 0x8)
    c2da_mem[door + 46] = uint8(c2da_fresh41 >> 0x10)
    c2da_mem[door + 47] = uint8(c2da_fresh41 >> 0x18)
    label 4:
    let c2da_fresh42 : int = P_FindLowestCeilingSurrounding(sec)
    let c2da_fresh43 : uint = uint(c2da_fresh42)
    c2da_mem[door + 40] = uint8(c2da_fresh43)
    c2da_mem[door + 41] = uint8(c2da_fresh43 >> 0x8)
    c2da_mem[door + 42] = uint8(c2da_fresh43 >> 0x10)
    c2da_mem[door + 43] = uint8(c2da_fresh43 >> 0x18)
    let c2da_fresh44 : int = int(uint(c2da_mem[door + 40]) | uint(c2da_mem[door + 41]) << 0x8 | uint(c2da_mem[door + 42]) << 0x10 | uint(c2da_mem[door + 43]) << 0x18) - 4 * (1 << 16)
    let c2da_fresh45 : uint = uint(c2da_fresh44)
    c2da_mem[door + 40] = uint8(c2da_fresh45)
    c2da_mem[door + 41] = uint8(c2da_fresh45 >> 0x8)
    c2da_mem[door + 42] = uint8(c2da_fresh45 >> 0x10)
    c2da_mem[door + 43] = uint8(c2da_fresh45 >> 0x18)
    return
}
[export, sideeffects]
def T_VerticalDoor(var door_0 : int) {
    var c2da_fresh46 : int
    var c2da_fresh50 : uint
    var c2da_fresh60 : uint
    var c2da_fresh66 : uint
    var c2da_fresh75 : uint
    var c2da_fresh78 : uint
    var res : uint
    c2da_fresh46 = int(uint(c2da_mem[door_0 + 48]) | uint(c2da_mem[door_0 + 49]) << 0x8 | uint(c2da_mem[door_0 + 50]) << 0x10 | uint(c2da_mem[door_0 + 51]) << 0x18)
    if (c2da_fresh46 == 0) {
        let c2da_fresh47 : int = int(uint(c2da_mem[door_0 + 56]) | uint(c2da_mem[door_0 + 57]) << 0x8 | uint(c2da_mem[door_0 + 58]) << 0x10 | uint(c2da_mem[door_0 + 59]) << 0x18)
        let c2da_fresh48 : int = c2da_fresh47 - 1
        let c2da_fresh49 : uint = uint(c2da_fresh48)
        c2da_mem[door_0 + 56] = uint8(c2da_fresh49)
        c2da_mem[door_0 + 57] = uint8(c2da_fresh49 >> 0x8)
        c2da_mem[door_0 + 58] = uint8(c2da_fresh49 >> 0x10)
        c2da_mem[door_0 + 59] = uint8(c2da_fresh49 >> 0x18)
        if (c2da_fresh48 == 0) {
            c2da_fresh50 = uint(c2da_mem[door_0 + 24]) | uint(c2da_mem[door_0 + 25]) << 0x8 | uint(c2da_mem[door_0 + 26]) << 0x10 | uint(c2da_mem[door_0 + 27]) << 0x18
            if (c2da_fresh50 == 0x5u) {
                let c2da_fresh51 : int = -1
                let c2da_fresh52 : uint = uint(c2da_fresh51)
                c2da_mem[door_0 + 48] = uint8(c2da_fresh52)
                c2da_mem[door_0 + 49] = uint8(c2da_fresh52 >> 0x8)
                c2da_mem[door_0 + 50] = uint8(c2da_fresh52 >> 0x10)
                c2da_mem[door_0 + 51] = uint8(c2da_fresh52 >> 0x18)
                S_StartSound(int(uint(c2da_mem[door_0 + 32]) | uint(c2da_mem[door_0 + 33]) << 0x8 | uint(c2da_mem[door_0 + 34]) << 0x10 | uint(c2da_mem[door_0 + 35]) << 0x18) + 48, 89)
            } elif (c2da_fresh50 == 0x0u) {
                let c2da_fresh53 : int = -1
                let c2da_fresh54 : uint = uint(c2da_fresh53)
                c2da_mem[door_0 + 48] = uint8(c2da_fresh54)
                c2da_mem[door_0 + 49] = uint8(c2da_fresh54 >> 0x8)
                c2da_mem[door_0 + 50] = uint8(c2da_fresh54 >> 0x10)
                c2da_mem[door_0 + 51] = uint8(c2da_fresh54 >> 0x18)
                S_StartSound(int(uint(c2da_mem[door_0 + 32]) | uint(c2da_mem[door_0 + 33]) << 0x8 | uint(c2da_mem[door_0 + 34]) << 0x10 | uint(c2da_mem[door_0 + 35]) << 0x18) + 48, 21)
            } elif (c2da_fresh50 == 0x1u) {
                let c2da_fresh55 : int = 1
                let c2da_fresh56 : uint = uint(c2da_fresh55)
                c2da_mem[door_0 + 48] = uint8(c2da_fresh56)
                c2da_mem[door_0 + 49] = uint8(c2da_fresh56 >> 0x8)
                c2da_mem[door_0 + 50] = uint8(c2da_fresh56 >> 0x10)
                c2da_mem[door_0 + 51] = uint8(c2da_fresh56 >> 0x18)
                S_StartSound(int(uint(c2da_mem[door_0 + 32]) | uint(c2da_mem[door_0 + 33]) << 0x8 | uint(c2da_mem[door_0 + 34]) << 0x10 | uint(c2da_mem[door_0 + 35]) << 0x18) + 48, 20)
            }
        }
    } elif (c2da_fresh46 == 2) {
        let c2da_fresh57 : int = int(uint(c2da_mem[door_0 + 56]) | uint(c2da_mem[door_0 + 57]) << 0x8 | uint(c2da_mem[door_0 + 58]) << 0x10 | uint(c2da_mem[door_0 + 59]) << 0x18)
        let c2da_fresh58 : int = c2da_fresh57 - 1
        let c2da_fresh59 : uint = uint(c2da_fresh58)
        c2da_mem[door_0 + 56] = uint8(c2da_fresh59)
        c2da_mem[door_0 + 57] = uint8(c2da_fresh59 >> 0x8)
        c2da_mem[door_0 + 58] = uint8(c2da_fresh59 >> 0x10)
        c2da_mem[door_0 + 59] = uint8(c2da_fresh59 >> 0x18)
        if (c2da_fresh58 == 0) {
            c2da_fresh60 = uint(c2da_mem[door_0 + 24]) | uint(c2da_mem[door_0 + 25]) << 0x8 | uint(c2da_mem[door_0 + 26]) << 0x10 | uint(c2da_mem[door_0 + 27]) << 0x18
            if (c2da_fresh60 == 0x4u) {
                let c2da_fresh61 : int = 1
                let c2da_fresh62 : uint = uint(c2da_fresh61)
                c2da_mem[door_0 + 48] = uint8(c2da_fresh62)
                c2da_mem[door_0 + 49] = uint8(c2da_fresh62 >> 0x8)
                c2da_mem[door_0 + 50] = uint8(c2da_fresh62 >> 0x10)
                c2da_mem[door_0 + 51] = uint8(c2da_fresh62 >> 0x18)
                let c2da_fresh63 : uint = 0u
                let c2da_fresh64 : uint = c2da_fresh63
                c2da_mem[door_0 + 24] = uint8(c2da_fresh64)
                c2da_mem[door_0 + 25] = uint8(c2da_fresh64 >> 0x8)
                c2da_mem[door_0 + 26] = uint8(c2da_fresh64 >> 0x10)
                c2da_mem[door_0 + 27] = uint8(c2da_fresh64 >> 0x18)
                S_StartSound(int(uint(c2da_mem[door_0 + 32]) | uint(c2da_mem[door_0 + 33]) << 0x8 | uint(c2da_mem[door_0 + 34]) << 0x10 | uint(c2da_mem[door_0 + 35]) << 0x18) + 48, 20)
            }
        }
    } elif (c2da_fresh46 == -1) {
        let c2da_fresh65 : int = int(uint(c2da_mem[door_0 + 32]) | uint(c2da_mem[door_0 + 33]) << 0x8 | uint(c2da_mem[door_0 + 34]) << 0x10 | uint(c2da_mem[door_0 + 35]) << 0x18)
        res = T_MovePlane(int(uint(c2da_mem[door_0 + 32]) | uint(c2da_mem[door_0 + 33]) << 0x8 | uint(c2da_mem[door_0 + 34]) << 0x10 | uint(c2da_mem[door_0 + 35]) << 0x18), int(uint(c2da_mem[door_0 + 44]) | uint(c2da_mem[door_0 + 45]) << 0x8 | uint(c2da_mem[door_0 + 46]) << 0x10 | uint(c2da_mem[door_0 + 47]) << 0x18), int(uint(c2da_mem[c2da_fresh65]) | uint(c2da_mem[c2da_fresh65 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh65 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh65 + 3]) << 0x18), 0u, 1, int(uint(c2da_mem[door_0 + 48]) | uint(c2da_mem[door_0 + 49]) << 0x8 | uint(c2da_mem[door_0 + 50]) << 0x10 | uint(c2da_mem[door_0 + 51]) << 0x18))
        if (res == 2u) {
            c2da_fresh66 = uint(c2da_mem[door_0 + 24]) | uint(c2da_mem[door_0 + 25]) << 0x8 | uint(c2da_mem[door_0 + 26]) << 0x10 | uint(c2da_mem[door_0 + 27]) << 0x18
            if (c2da_fresh66 == 0x5u || c2da_fresh66 == 0x7u) {
                let c2da_fresh67 : int = int(uint(c2da_mem[door_0 + 32]) | uint(c2da_mem[door_0 + 33]) << 0x8 | uint(c2da_mem[door_0 + 34]) << 0x10 | uint(c2da_mem[door_0 + 35]) << 0x18) + 104
                let c2da_fresh68 : uint = 0u
                c2da_mem[c2da_fresh67] = uint8(c2da_fresh68)
                c2da_mem[c2da_fresh67 + 1] = uint8(c2da_fresh68 >> 0x8)
                c2da_mem[c2da_fresh67 + 2] = uint8(c2da_fresh68 >> 0x10)
                c2da_mem[c2da_fresh67 + 3] = uint8(c2da_fresh68 >> 0x18)
                c2da_mem[c2da_fresh67 + 4] = 0u8
                c2da_mem[c2da_fresh67 + 5] = 0u8
                c2da_mem[c2da_fresh67 + 6] = 0u8
                c2da_mem[c2da_fresh67 + 7] = 0u8
                P_RemoveThinker(door_0)
                S_StartSound(int(uint(c2da_mem[door_0 + 32]) | uint(c2da_mem[door_0 + 33]) << 0x8 | uint(c2da_mem[door_0 + 34]) << 0x10 | uint(c2da_mem[door_0 + 35]) << 0x18) + 48, 89)
            } elif (c2da_fresh66 == 0x0u || c2da_fresh66 == 0x2u) {
                let c2da_fresh69 : int = int(uint(c2da_mem[door_0 + 32]) | uint(c2da_mem[door_0 + 33]) << 0x8 | uint(c2da_mem[door_0 + 34]) << 0x10 | uint(c2da_mem[door_0 + 35]) << 0x18) + 104
                let c2da_fresh70 : uint = 0u
                c2da_mem[c2da_fresh69] = uint8(c2da_fresh70)
                c2da_mem[c2da_fresh69 + 1] = uint8(c2da_fresh70 >> 0x8)
                c2da_mem[c2da_fresh69 + 2] = uint8(c2da_fresh70 >> 0x10)
                c2da_mem[c2da_fresh69 + 3] = uint8(c2da_fresh70 >> 0x18)
                c2da_mem[c2da_fresh69 + 4] = 0u8
                c2da_mem[c2da_fresh69 + 5] = 0u8
                c2da_mem[c2da_fresh69 + 6] = 0u8
                c2da_mem[c2da_fresh69 + 7] = 0u8
                P_RemoveThinker(door_0)
            } elif (c2da_fresh66 == 0x1u) {
                let c2da_fresh71 : int = 0
                let c2da_fresh72 : uint = uint(c2da_fresh71)
                c2da_mem[door_0 + 48] = uint8(c2da_fresh72)
                c2da_mem[door_0 + 49] = uint8(c2da_fresh72 >> 0x8)
                c2da_mem[door_0 + 50] = uint8(c2da_fresh72 >> 0x10)
                c2da_mem[door_0 + 51] = uint8(c2da_fresh72 >> 0x18)
                let c2da_fresh73 : int = 35 * 30
                let c2da_fresh74 : uint = uint(c2da_fresh73)
                c2da_mem[door_0 + 56] = uint8(c2da_fresh74)
                c2da_mem[door_0 + 57] = uint8(c2da_fresh74 >> 0x8)
                c2da_mem[door_0 + 58] = uint8(c2da_fresh74 >> 0x10)
                c2da_mem[door_0 + 59] = uint8(c2da_fresh74 >> 0x18)
            }
        } elif (res == 1u) {
            c2da_fresh75 = uint(c2da_mem[door_0 + 24]) | uint(c2da_mem[door_0 + 25]) << 0x8 | uint(c2da_mem[door_0 + 26]) << 0x10 | uint(c2da_mem[door_0 + 27]) << 0x18
            if (c2da_fresh75 == 0x7u || c2da_fresh75 == 0x2u) {
            } else {
                let c2da_fresh76 : int = 1
                let c2da_fresh77 : uint = uint(c2da_fresh76)
                c2da_mem[door_0 + 48] = uint8(c2da_fresh77)
                c2da_mem[door_0 + 49] = uint8(c2da_fresh77 >> 0x8)
                c2da_mem[door_0 + 50] = uint8(c2da_fresh77 >> 0x10)
                c2da_mem[door_0 + 51] = uint8(c2da_fresh77 >> 0x18)
                S_StartSound(int(uint(c2da_mem[door_0 + 32]) | uint(c2da_mem[door_0 + 33]) << 0x8 | uint(c2da_mem[door_0 + 34]) << 0x10 | uint(c2da_mem[door_0 + 35]) << 0x18) + 48, 20)
            }
        }
    } elif (c2da_fresh46 == 1) {
        res = T_MovePlane(int(uint(c2da_mem[door_0 + 32]) | uint(c2da_mem[door_0 + 33]) << 0x8 | uint(c2da_mem[door_0 + 34]) << 0x10 | uint(c2da_mem[door_0 + 35]) << 0x18), int(uint(c2da_mem[door_0 + 44]) | uint(c2da_mem[door_0 + 45]) << 0x8 | uint(c2da_mem[door_0 + 46]) << 0x10 | uint(c2da_mem[door_0 + 47]) << 0x18), int(uint(c2da_mem[door_0 + 40]) | uint(c2da_mem[door_0 + 41]) << 0x8 | uint(c2da_mem[door_0 + 42]) << 0x10 | uint(c2da_mem[door_0 + 43]) << 0x18), 0u, 1, int(uint(c2da_mem[door_0 + 48]) | uint(c2da_mem[door_0 + 49]) << 0x8 | uint(c2da_mem[door_0 + 50]) << 0x10 | uint(c2da_mem[door_0 + 51]) << 0x18))
        if (res == 2u) {
            c2da_fresh78 = uint(c2da_mem[door_0 + 24]) | uint(c2da_mem[door_0 + 25]) << 0x8 | uint(c2da_mem[door_0 + 26]) << 0x10 | uint(c2da_mem[door_0 + 27]) << 0x18
            if (c2da_fresh78 == 0x5u || c2da_fresh78 == 0x0u) {
                let c2da_fresh79 : int = 0
                let c2da_fresh80 : uint = uint(c2da_fresh79)
                c2da_mem[door_0 + 48] = uint8(c2da_fresh80)
                c2da_mem[door_0 + 49] = uint8(c2da_fresh80 >> 0x8)
                c2da_mem[door_0 + 50] = uint8(c2da_fresh80 >> 0x10)
                c2da_mem[door_0 + 51] = uint8(c2da_fresh80 >> 0x18)
                let c2da_fresh81 : int = int(uint(c2da_mem[door_0 + 52]) | uint(c2da_mem[door_0 + 53]) << 0x8 | uint(c2da_mem[door_0 + 54]) << 0x10 | uint(c2da_mem[door_0 + 55]) << 0x18)
                let c2da_fresh82 : uint = uint(c2da_fresh81)
                c2da_mem[door_0 + 56] = uint8(c2da_fresh82)
                c2da_mem[door_0 + 57] = uint8(c2da_fresh82 >> 0x8)
                c2da_mem[door_0 + 58] = uint8(c2da_fresh82 >> 0x10)
                c2da_mem[door_0 + 59] = uint8(c2da_fresh82 >> 0x18)
            } elif (c2da_fresh78 == 0x1u || c2da_fresh78 == 0x6u || c2da_fresh78 == 0x3u) {
                let c2da_fresh83 : int = int(uint(c2da_mem[door_0 + 32]) | uint(c2da_mem[door_0 + 33]) << 0x8 | uint(c2da_mem[door_0 + 34]) << 0x10 | uint(c2da_mem[door_0 + 35]) << 0x18) + 104
                let c2da_fresh84 : uint = 0u
                c2da_mem[c2da_fresh83] = uint8(c2da_fresh84)
                c2da_mem[c2da_fresh83 + 1] = uint8(c2da_fresh84 >> 0x8)
                c2da_mem[c2da_fresh83 + 2] = uint8(c2da_fresh84 >> 0x10)
                c2da_mem[c2da_fresh83 + 3] = uint8(c2da_fresh84 >> 0x18)
                c2da_mem[c2da_fresh83 + 4] = 0u8
                c2da_mem[c2da_fresh83 + 5] = 0u8
                c2da_mem[c2da_fresh83 + 6] = 0u8
                c2da_mem[c2da_fresh83 + 7] = 0u8
                P_RemoveThinker(door_0)
            }
        }
    }
    return
}
[export, sideeffects]
def EV_DoDoor(var line_0 : int; var type_0 : uint) : int {
    var c2da_fresh93 : uint
    var secnum : int
    var rtn : int
    var sec_0 : int
    var door_1 : int
    secnum = -1
    rtn = 0
    while (true) {
        secnum = P_FindSectorFromLineTag(line_0, secnum)
        if (secnum < 0) {
            break
        }
        sec_0 = sectors + secnum * 128
        if (int(uint(c2da_mem[sec_0 + 104]) | uint(c2da_mem[sec_0 + 105]) << 0x8 | uint(c2da_mem[sec_0 + 106]) << 0x10 | uint(c2da_mem[sec_0 + 107]) << 0x18) != 0) {
            continue
        }
        rtn = 1
        door_1 = Z_Malloc(64, 6, 0)
        P_AddThinker(door_1)
        let c2da_fresh85 : uint = uint(door_1)
        c2da_mem[sec_0 + 104] = uint8(c2da_fresh85)
        c2da_mem[sec_0 + 105] = uint8(c2da_fresh85 >> 0x8)
        c2da_mem[sec_0 + 106] = uint8(c2da_fresh85 >> 0x10)
        c2da_mem[sec_0 + 107] = uint8(c2da_fresh85 >> 0x18)
        c2da_mem[sec_0 + 108] = 0u8
        c2da_mem[sec_0 + 109] = 0u8
        c2da_mem[sec_0 + 110] = 0u8
        c2da_mem[sec_0 + 111] = 0u8
        let c2da_fresh86 : uint = 124u
        c2da_mem[door_1 + 16] = uint8(c2da_fresh86)
        c2da_mem[door_1 + 17] = uint8(c2da_fresh86 >> 0x8)
        c2da_mem[door_1 + 18] = uint8(c2da_fresh86 >> 0x10)
        c2da_mem[door_1 + 19] = uint8(c2da_fresh86 >> 0x18)
        c2da_mem[door_1 + 20] = 0u8
        c2da_mem[door_1 + 21] = 0u8
        c2da_mem[door_1 + 22] = 0u8
        c2da_mem[door_1 + 23] = 0u8
        let c2da_fresh87 : uint = uint(sec_0)
        c2da_mem[door_1 + 32] = uint8(c2da_fresh87)
        c2da_mem[door_1 + 33] = uint8(c2da_fresh87 >> 0x8)
        c2da_mem[door_1 + 34] = uint8(c2da_fresh87 >> 0x10)
        c2da_mem[door_1 + 35] = uint8(c2da_fresh87 >> 0x18)
        c2da_mem[door_1 + 36] = 0u8
        c2da_mem[door_1 + 37] = 0u8
        c2da_mem[door_1 + 38] = 0u8
        c2da_mem[door_1 + 39] = 0u8
        let c2da_fresh88 : uint = type_0
        c2da_mem[door_1 + 24] = uint8(c2da_fresh88)
        c2da_mem[door_1 + 25] = uint8(c2da_fresh88 >> 0x8)
        c2da_mem[door_1 + 26] = uint8(c2da_fresh88 >> 0x10)
        c2da_mem[door_1 + 27] = uint8(c2da_fresh88 >> 0x18)
        let c2da_fresh89 : int = 150
        let c2da_fresh90 : uint = uint(c2da_fresh89)
        c2da_mem[door_1 + 52] = uint8(c2da_fresh90)
        c2da_mem[door_1 + 53] = uint8(c2da_fresh90 >> 0x8)
        c2da_mem[door_1 + 54] = uint8(c2da_fresh90 >> 0x10)
        c2da_mem[door_1 + 55] = uint8(c2da_fresh90 >> 0x18)
        let c2da_fresh91 : int = (1 << 16) * 2
        let c2da_fresh92 : uint = uint(c2da_fresh91)
        c2da_mem[door_1 + 44] = uint8(c2da_fresh92)
        c2da_mem[door_1 + 45] = uint8(c2da_fresh92 >> 0x8)
        c2da_mem[door_1 + 46] = uint8(c2da_fresh92 >> 0x10)
        c2da_mem[door_1 + 47] = uint8(c2da_fresh92 >> 0x18)
        c2da_fresh93 = type_0
        if (c2da_fresh93 == 0x7u) {
            let c2da_fresh94 : int = P_FindLowestCeilingSurrounding(sec_0)
            let c2da_fresh95 : uint = uint(c2da_fresh94)
            c2da_mem[door_1 + 40] = uint8(c2da_fresh95)
            c2da_mem[door_1 + 41] = uint8(c2da_fresh95 >> 0x8)
            c2da_mem[door_1 + 42] = uint8(c2da_fresh95 >> 0x10)
            c2da_mem[door_1 + 43] = uint8(c2da_fresh95 >> 0x18)
            let c2da_fresh96 : int = int(uint(c2da_mem[door_1 + 40]) | uint(c2da_mem[door_1 + 41]) << 0x8 | uint(c2da_mem[door_1 + 42]) << 0x10 | uint(c2da_mem[door_1 + 43]) << 0x18) - 4 * (1 << 16)
            let c2da_fresh97 : uint = uint(c2da_fresh96)
            c2da_mem[door_1 + 40] = uint8(c2da_fresh97)
            c2da_mem[door_1 + 41] = uint8(c2da_fresh97 >> 0x8)
            c2da_mem[door_1 + 42] = uint8(c2da_fresh97 >> 0x10)
            c2da_mem[door_1 + 43] = uint8(c2da_fresh97 >> 0x18)
            let c2da_fresh98 : int = -1
            let c2da_fresh99 : uint = uint(c2da_fresh98)
            c2da_mem[door_1 + 48] = uint8(c2da_fresh99)
            c2da_mem[door_1 + 49] = uint8(c2da_fresh99 >> 0x8)
            c2da_mem[door_1 + 50] = uint8(c2da_fresh99 >> 0x10)
            c2da_mem[door_1 + 51] = uint8(c2da_fresh99 >> 0x18)
            let c2da_fresh100 : int = (1 << 16) * 2 * 4
            let c2da_fresh101 : uint = uint(c2da_fresh100)
            c2da_mem[door_1 + 44] = uint8(c2da_fresh101)
            c2da_mem[door_1 + 45] = uint8(c2da_fresh101 >> 0x8)
            c2da_mem[door_1 + 46] = uint8(c2da_fresh101 >> 0x10)
            c2da_mem[door_1 + 47] = uint8(c2da_fresh101 >> 0x18)
            S_StartSound(int(uint(c2da_mem[door_1 + 32]) | uint(c2da_mem[door_1 + 33]) << 0x8 | uint(c2da_mem[door_1 + 34]) << 0x10 | uint(c2da_mem[door_1 + 35]) << 0x18) + 48, 89)
        } elif (c2da_fresh93 == 0x2u) {
            let c2da_fresh102 : int = P_FindLowestCeilingSurrounding(sec_0)
            let c2da_fresh103 : uint = uint(c2da_fresh102)
            c2da_mem[door_1 + 40] = uint8(c2da_fresh103)
            c2da_mem[door_1 + 41] = uint8(c2da_fresh103 >> 0x8)
            c2da_mem[door_1 + 42] = uint8(c2da_fresh103 >> 0x10)
            c2da_mem[door_1 + 43] = uint8(c2da_fresh103 >> 0x18)
            let c2da_fresh104 : int = int(uint(c2da_mem[door_1 + 40]) | uint(c2da_mem[door_1 + 41]) << 0x8 | uint(c2da_mem[door_1 + 42]) << 0x10 | uint(c2da_mem[door_1 + 43]) << 0x18) - 4 * (1 << 16)
            let c2da_fresh105 : uint = uint(c2da_fresh104)
            c2da_mem[door_1 + 40] = uint8(c2da_fresh105)
            c2da_mem[door_1 + 41] = uint8(c2da_fresh105 >> 0x8)
            c2da_mem[door_1 + 42] = uint8(c2da_fresh105 >> 0x10)
            c2da_mem[door_1 + 43] = uint8(c2da_fresh105 >> 0x18)
            let c2da_fresh106 : int = -1
            let c2da_fresh107 : uint = uint(c2da_fresh106)
            c2da_mem[door_1 + 48] = uint8(c2da_fresh107)
            c2da_mem[door_1 + 49] = uint8(c2da_fresh107 >> 0x8)
            c2da_mem[door_1 + 50] = uint8(c2da_fresh107 >> 0x10)
            c2da_mem[door_1 + 51] = uint8(c2da_fresh107 >> 0x18)
            S_StartSound(int(uint(c2da_mem[door_1 + 32]) | uint(c2da_mem[door_1 + 33]) << 0x8 | uint(c2da_mem[door_1 + 34]) << 0x10 | uint(c2da_mem[door_1 + 35]) << 0x18) + 48, 21)
        } elif (c2da_fresh93 == 0x1u) {
            let c2da_fresh108 : int = int(uint(c2da_mem[sec_0 + 4]) | uint(c2da_mem[sec_0 + 5]) << 0x8 | uint(c2da_mem[sec_0 + 6]) << 0x10 | uint(c2da_mem[sec_0 + 7]) << 0x18)
            let c2da_fresh109 : uint = uint(c2da_fresh108)
            c2da_mem[door_1 + 40] = uint8(c2da_fresh109)
            c2da_mem[door_1 + 41] = uint8(c2da_fresh109 >> 0x8)
            c2da_mem[door_1 + 42] = uint8(c2da_fresh109 >> 0x10)
            c2da_mem[door_1 + 43] = uint8(c2da_fresh109 >> 0x18)
            let c2da_fresh110 : int = -1
            let c2da_fresh111 : uint = uint(c2da_fresh110)
            c2da_mem[door_1 + 48] = uint8(c2da_fresh111)
            c2da_mem[door_1 + 49] = uint8(c2da_fresh111 >> 0x8)
            c2da_mem[door_1 + 50] = uint8(c2da_fresh111 >> 0x10)
            c2da_mem[door_1 + 51] = uint8(c2da_fresh111 >> 0x18)
            S_StartSound(int(uint(c2da_mem[door_1 + 32]) | uint(c2da_mem[door_1 + 33]) << 0x8 | uint(c2da_mem[door_1 + 34]) << 0x10 | uint(c2da_mem[door_1 + 35]) << 0x18) + 48, 21)
        } elif (c2da_fresh93 == 0x5u || c2da_fresh93 == 0x6u) {
            let c2da_fresh112 : int = 1
            let c2da_fresh113 : uint = uint(c2da_fresh112)
            c2da_mem[door_1 + 48] = uint8(c2da_fresh113)
            c2da_mem[door_1 + 49] = uint8(c2da_fresh113 >> 0x8)
            c2da_mem[door_1 + 50] = uint8(c2da_fresh113 >> 0x10)
            c2da_mem[door_1 + 51] = uint8(c2da_fresh113 >> 0x18)
            let c2da_fresh114 : int = P_FindLowestCeilingSurrounding(sec_0)
            let c2da_fresh115 : uint = uint(c2da_fresh114)
            c2da_mem[door_1 + 40] = uint8(c2da_fresh115)
            c2da_mem[door_1 + 41] = uint8(c2da_fresh115 >> 0x8)
            c2da_mem[door_1 + 42] = uint8(c2da_fresh115 >> 0x10)
            c2da_mem[door_1 + 43] = uint8(c2da_fresh115 >> 0x18)
            let c2da_fresh116 : int = int(uint(c2da_mem[door_1 + 40]) | uint(c2da_mem[door_1 + 41]) << 0x8 | uint(c2da_mem[door_1 + 42]) << 0x10 | uint(c2da_mem[door_1 + 43]) << 0x18) - 4 * (1 << 16)
            let c2da_fresh117 : uint = uint(c2da_fresh116)
            c2da_mem[door_1 + 40] = uint8(c2da_fresh117)
            c2da_mem[door_1 + 41] = uint8(c2da_fresh117 >> 0x8)
            c2da_mem[door_1 + 42] = uint8(c2da_fresh117 >> 0x10)
            c2da_mem[door_1 + 43] = uint8(c2da_fresh117 >> 0x18)
            let c2da_fresh118 : int = (1 << 16) * 2 * 4
            let c2da_fresh119 : uint = uint(c2da_fresh118)
            c2da_mem[door_1 + 44] = uint8(c2da_fresh119)
            c2da_mem[door_1 + 45] = uint8(c2da_fresh119 >> 0x8)
            c2da_mem[door_1 + 46] = uint8(c2da_fresh119 >> 0x10)
            c2da_mem[door_1 + 47] = uint8(c2da_fresh119 >> 0x18)
            if (int(uint(c2da_mem[door_1 + 40]) | uint(c2da_mem[door_1 + 41]) << 0x8 | uint(c2da_mem[door_1 + 42]) << 0x10 | uint(c2da_mem[door_1 + 43]) << 0x18) != int(uint(c2da_mem[sec_0 + 4]) | uint(c2da_mem[sec_0 + 5]) << 0x8 | uint(c2da_mem[sec_0 + 6]) << 0x10 | uint(c2da_mem[sec_0 + 7]) << 0x18)) {
                S_StartSound(int(uint(c2da_mem[door_1 + 32]) | uint(c2da_mem[door_1 + 33]) << 0x8 | uint(c2da_mem[door_1 + 34]) << 0x10 | uint(c2da_mem[door_1 + 35]) << 0x18) + 48, 88)
            }
        } elif (c2da_fresh93 == 0x0u || c2da_fresh93 == 0x3u) {
            let c2da_fresh120 : int = 1
            let c2da_fresh121 : uint = uint(c2da_fresh120)
            c2da_mem[door_1 + 48] = uint8(c2da_fresh121)
            c2da_mem[door_1 + 49] = uint8(c2da_fresh121 >> 0x8)
            c2da_mem[door_1 + 50] = uint8(c2da_fresh121 >> 0x10)
            c2da_mem[door_1 + 51] = uint8(c2da_fresh121 >> 0x18)
            let c2da_fresh122 : int = P_FindLowestCeilingSurrounding(sec_0)
            let c2da_fresh123 : uint = uint(c2da_fresh122)
            c2da_mem[door_1 + 40] = uint8(c2da_fresh123)
            c2da_mem[door_1 + 41] = uint8(c2da_fresh123 >> 0x8)
            c2da_mem[door_1 + 42] = uint8(c2da_fresh123 >> 0x10)
            c2da_mem[door_1 + 43] = uint8(c2da_fresh123 >> 0x18)
            let c2da_fresh124 : int = int(uint(c2da_mem[door_1 + 40]) | uint(c2da_mem[door_1 + 41]) << 0x8 | uint(c2da_mem[door_1 + 42]) << 0x10 | uint(c2da_mem[door_1 + 43]) << 0x18) - 4 * (1 << 16)
            let c2da_fresh125 : uint = uint(c2da_fresh124)
            c2da_mem[door_1 + 40] = uint8(c2da_fresh125)
            c2da_mem[door_1 + 41] = uint8(c2da_fresh125 >> 0x8)
            c2da_mem[door_1 + 42] = uint8(c2da_fresh125 >> 0x10)
            c2da_mem[door_1 + 43] = uint8(c2da_fresh125 >> 0x18)
            if (int(uint(c2da_mem[door_1 + 40]) | uint(c2da_mem[door_1 + 41]) << 0x8 | uint(c2da_mem[door_1 + 42]) << 0x10 | uint(c2da_mem[door_1 + 43]) << 0x18) != int(uint(c2da_mem[sec_0 + 4]) | uint(c2da_mem[sec_0 + 5]) << 0x8 | uint(c2da_mem[sec_0 + 6]) << 0x10 | uint(c2da_mem[sec_0 + 7]) << 0x18)) {
                S_StartSound(int(uint(c2da_mem[door_1 + 32]) | uint(c2da_mem[door_1 + 33]) << 0x8 | uint(c2da_mem[door_1 + 34]) << 0x10 | uint(c2da_mem[door_1 + 35]) << 0x18) + 48, 20)
            }
        }
    }
    return rtn
}
[export, sideeffects]
def EV_DoLockedDoor(var line_1 : int; var type_1 : uint; var thing_0 : int) : int {
    var c2da_fresh126 : int
    var p : int = int(uint(c2da_mem[thing_0 + 192]) | uint(c2da_mem[thing_0 + 193]) << 0x8 | uint(c2da_mem[thing_0 + 194]) << 0x10 | uint(c2da_mem[thing_0 + 195]) << 0x18)
    if (p == 0) {
        return 0
    }
    c2da_fresh126 = int(int16(uint(c2da_mem[line_1 + 26]) | uint(c2da_mem[line_1 + 27]) << 0x8))
    if (c2da_fresh126 == 99 || c2da_fresh126 == 133) {
        if (p == 0) {
            return 0
        }
        if ((uint(c2da_mem[p + 80 + 0 * 4]) | uint(c2da_mem[p + 80 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 80 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 80 + 0 * 4 + 3]) << 0x18) == 0 && (uint(c2da_mem[p + 80 + 3 * 4]) | uint(c2da_mem[p + 80 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 80 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 80 + 3 * 4 + 3]) << 0x18) == 0) {
            let c2da_fresh127 : uint = 358994u
            c2da_mem[p + 232] = uint8(c2da_fresh127)
            c2da_mem[p + 233] = uint8(c2da_fresh127 >> 0x8)
            c2da_mem[p + 234] = uint8(c2da_fresh127 >> 0x10)
            c2da_mem[p + 235] = uint8(c2da_fresh127 >> 0x18)
            c2da_mem[p + 236] = 0u8
            c2da_mem[p + 237] = 0u8
            c2da_mem[p + 238] = 0u8
            c2da_mem[p + 239] = 0u8
            S_StartSound(0, 34)
            return 0
        }
    } elif (c2da_fresh126 == 134 || c2da_fresh126 == 135) {
        if (p == 0) {
            return 0
        }
        if ((uint(c2da_mem[p + 80 + 2 * 4]) | uint(c2da_mem[p + 80 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 80 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 80 + 2 * 4 + 3]) << 0x18) == 0 && (uint(c2da_mem[p + 80 + 5 * 4]) | uint(c2da_mem[p + 80 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 80 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 80 + 5 * 4 + 3]) << 0x18) == 0) {
            let c2da_fresh128 : uint = 359038u
            c2da_mem[p + 232] = uint8(c2da_fresh128)
            c2da_mem[p + 233] = uint8(c2da_fresh128 >> 0x8)
            c2da_mem[p + 234] = uint8(c2da_fresh128 >> 0x10)
            c2da_mem[p + 235] = uint8(c2da_fresh128 >> 0x18)
            c2da_mem[p + 236] = 0u8
            c2da_mem[p + 237] = 0u8
            c2da_mem[p + 238] = 0u8
            c2da_mem[p + 239] = 0u8
            S_StartSound(0, 34)
            return 0
        }
    } elif (c2da_fresh126 == 136 || c2da_fresh126 == 137) {
        if (p == 0) {
            return 0
        }
        if ((uint(c2da_mem[p + 80 + 1 * 4]) | uint(c2da_mem[p + 80 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 80 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 80 + 1 * 4 + 3]) << 0x18) == 0 && (uint(c2da_mem[p + 80 + 4 * 4]) | uint(c2da_mem[p + 80 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 80 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 80 + 4 * 4 + 3]) << 0x18) == 0) {
            let c2da_fresh129 : uint = 359081u
            c2da_mem[p + 232] = uint8(c2da_fresh129)
            c2da_mem[p + 233] = uint8(c2da_fresh129 >> 0x8)
            c2da_mem[p + 234] = uint8(c2da_fresh129 >> 0x10)
            c2da_mem[p + 235] = uint8(c2da_fresh129 >> 0x18)
            c2da_mem[p + 236] = 0u8
            c2da_mem[p + 237] = 0u8
            c2da_mem[p + 238] = 0u8
            c2da_mem[p + 239] = 0u8
            S_StartSound(0, 34)
            return 0
        }
    }
    return EV_DoDoor(line_1, type_1)
}
[export, sideeffects]
def P_SpawnDoorCloseIn30(var sec_1 : int) {
    var door_2 : int = Z_Malloc(64, 6, 0)
    P_AddThinker(door_2)
    let c2da_fresh130 : uint = uint(door_2)
    c2da_mem[sec_1 + 104] = uint8(c2da_fresh130)
    c2da_mem[sec_1 + 105] = uint8(c2da_fresh130 >> 0x8)
    c2da_mem[sec_1 + 106] = uint8(c2da_fresh130 >> 0x10)
    c2da_mem[sec_1 + 107] = uint8(c2da_fresh130 >> 0x18)
    c2da_mem[sec_1 + 108] = 0u8
    c2da_mem[sec_1 + 109] = 0u8
    c2da_mem[sec_1 + 110] = 0u8
    c2da_mem[sec_1 + 111] = 0u8
    let c2da_fresh131 : int16 = int16(0)
    let c2da_fresh132 : uint = uint(c2da_fresh131)
    c2da_mem[sec_1 + 14] = uint8(c2da_fresh132)
    c2da_mem[sec_1 + 15] = uint8(c2da_fresh132 >> 0x8)
    let c2da_fresh133 : uint = 124u
    c2da_mem[door_2 + 16] = uint8(c2da_fresh133)
    c2da_mem[door_2 + 17] = uint8(c2da_fresh133 >> 0x8)
    c2da_mem[door_2 + 18] = uint8(c2da_fresh133 >> 0x10)
    c2da_mem[door_2 + 19] = uint8(c2da_fresh133 >> 0x18)
    c2da_mem[door_2 + 20] = 0u8
    c2da_mem[door_2 + 21] = 0u8
    c2da_mem[door_2 + 22] = 0u8
    c2da_mem[door_2 + 23] = 0u8
    let c2da_fresh134 : uint = uint(sec_1)
    c2da_mem[door_2 + 32] = uint8(c2da_fresh134)
    c2da_mem[door_2 + 33] = uint8(c2da_fresh134 >> 0x8)
    c2da_mem[door_2 + 34] = uint8(c2da_fresh134 >> 0x10)
    c2da_mem[door_2 + 35] = uint8(c2da_fresh134 >> 0x18)
    c2da_mem[door_2 + 36] = 0u8
    c2da_mem[door_2 + 37] = 0u8
    c2da_mem[door_2 + 38] = 0u8
    c2da_mem[door_2 + 39] = 0u8
    let c2da_fresh135 : int = 0
    let c2da_fresh136 : uint = uint(c2da_fresh135)
    c2da_mem[door_2 + 48] = uint8(c2da_fresh136)
    c2da_mem[door_2 + 49] = uint8(c2da_fresh136 >> 0x8)
    c2da_mem[door_2 + 50] = uint8(c2da_fresh136 >> 0x10)
    c2da_mem[door_2 + 51] = uint8(c2da_fresh136 >> 0x18)
    let c2da_fresh137 : uint = 0u
    let c2da_fresh138 : uint = c2da_fresh137
    c2da_mem[door_2 + 24] = uint8(c2da_fresh138)
    c2da_mem[door_2 + 25] = uint8(c2da_fresh138 >> 0x8)
    c2da_mem[door_2 + 26] = uint8(c2da_fresh138 >> 0x10)
    c2da_mem[door_2 + 27] = uint8(c2da_fresh138 >> 0x18)
    let c2da_fresh139 : int = (1 << 16) * 2
    let c2da_fresh140 : uint = uint(c2da_fresh139)
    c2da_mem[door_2 + 44] = uint8(c2da_fresh140)
    c2da_mem[door_2 + 45] = uint8(c2da_fresh140 >> 0x8)
    c2da_mem[door_2 + 46] = uint8(c2da_fresh140 >> 0x10)
    c2da_mem[door_2 + 47] = uint8(c2da_fresh140 >> 0x18)
    let c2da_fresh141 : int = 30 * 35
    let c2da_fresh142 : uint = uint(c2da_fresh141)
    c2da_mem[door_2 + 56] = uint8(c2da_fresh142)
    c2da_mem[door_2 + 57] = uint8(c2da_fresh142 >> 0x8)
    c2da_mem[door_2 + 58] = uint8(c2da_fresh142 >> 0x10)
    c2da_mem[door_2 + 59] = uint8(c2da_fresh142 >> 0x18)
    return
}
[export, sideeffects]
def P_SpawnDoorRaiseIn5Mins(var sec_2 : int; var secnum_0 : int) {
    var door_3 : int = Z_Malloc(64, 6, 0)
    P_AddThinker(door_3)
    let c2da_fresh143 : uint = uint(door_3)
    c2da_mem[sec_2 + 104] = uint8(c2da_fresh143)
    c2da_mem[sec_2 + 105] = uint8(c2da_fresh143 >> 0x8)
    c2da_mem[sec_2 + 106] = uint8(c2da_fresh143 >> 0x10)
    c2da_mem[sec_2 + 107] = uint8(c2da_fresh143 >> 0x18)
    c2da_mem[sec_2 + 108] = 0u8
    c2da_mem[sec_2 + 109] = 0u8
    c2da_mem[sec_2 + 110] = 0u8
    c2da_mem[sec_2 + 111] = 0u8
    let c2da_fresh144 : int16 = int16(0)
    let c2da_fresh145 : uint = uint(c2da_fresh144)
    c2da_mem[sec_2 + 14] = uint8(c2da_fresh145)
    c2da_mem[sec_2 + 15] = uint8(c2da_fresh145 >> 0x8)
    let c2da_fresh146 : uint = 124u
    c2da_mem[door_3 + 16] = uint8(c2da_fresh146)
    c2da_mem[door_3 + 17] = uint8(c2da_fresh146 >> 0x8)
    c2da_mem[door_3 + 18] = uint8(c2da_fresh146 >> 0x10)
    c2da_mem[door_3 + 19] = uint8(c2da_fresh146 >> 0x18)
    c2da_mem[door_3 + 20] = 0u8
    c2da_mem[door_3 + 21] = 0u8
    c2da_mem[door_3 + 22] = 0u8
    c2da_mem[door_3 + 23] = 0u8
    let c2da_fresh147 : uint = uint(sec_2)
    c2da_mem[door_3 + 32] = uint8(c2da_fresh147)
    c2da_mem[door_3 + 33] = uint8(c2da_fresh147 >> 0x8)
    c2da_mem[door_3 + 34] = uint8(c2da_fresh147 >> 0x10)
    c2da_mem[door_3 + 35] = uint8(c2da_fresh147 >> 0x18)
    c2da_mem[door_3 + 36] = 0u8
    c2da_mem[door_3 + 37] = 0u8
    c2da_mem[door_3 + 38] = 0u8
    c2da_mem[door_3 + 39] = 0u8
    let c2da_fresh148 : int = 2
    let c2da_fresh149 : uint = uint(c2da_fresh148)
    c2da_mem[door_3 + 48] = uint8(c2da_fresh149)
    c2da_mem[door_3 + 49] = uint8(c2da_fresh149 >> 0x8)
    c2da_mem[door_3 + 50] = uint8(c2da_fresh149 >> 0x10)
    c2da_mem[door_3 + 51] = uint8(c2da_fresh149 >> 0x18)
    let c2da_fresh150 : uint = 4u
    let c2da_fresh151 : uint = c2da_fresh150
    c2da_mem[door_3 + 24] = uint8(c2da_fresh151)
    c2da_mem[door_3 + 25] = uint8(c2da_fresh151 >> 0x8)
    c2da_mem[door_3 + 26] = uint8(c2da_fresh151 >> 0x10)
    c2da_mem[door_3 + 27] = uint8(c2da_fresh151 >> 0x18)
    let c2da_fresh152 : int = (1 << 16) * 2
    let c2da_fresh153 : uint = uint(c2da_fresh152)
    c2da_mem[door_3 + 44] = uint8(c2da_fresh153)
    c2da_mem[door_3 + 45] = uint8(c2da_fresh153 >> 0x8)
    c2da_mem[door_3 + 46] = uint8(c2da_fresh153 >> 0x10)
    c2da_mem[door_3 + 47] = uint8(c2da_fresh153 >> 0x18)
    let c2da_fresh154 : int = P_FindLowestCeilingSurrounding(sec_2)
    let c2da_fresh155 : uint = uint(c2da_fresh154)
    c2da_mem[door_3 + 40] = uint8(c2da_fresh155)
    c2da_mem[door_3 + 41] = uint8(c2da_fresh155 >> 0x8)
    c2da_mem[door_3 + 42] = uint8(c2da_fresh155 >> 0x10)
    c2da_mem[door_3 + 43] = uint8(c2da_fresh155 >> 0x18)
    let c2da_fresh156 : int = int(uint(c2da_mem[door_3 + 40]) | uint(c2da_mem[door_3 + 41]) << 0x8 | uint(c2da_mem[door_3 + 42]) << 0x10 | uint(c2da_mem[door_3 + 43]) << 0x18) - 4 * (1 << 16)
    let c2da_fresh157 : uint = uint(c2da_fresh156)
    c2da_mem[door_3 + 40] = uint8(c2da_fresh157)
    c2da_mem[door_3 + 41] = uint8(c2da_fresh157 >> 0x8)
    c2da_mem[door_3 + 42] = uint8(c2da_fresh157 >> 0x10)
    c2da_mem[door_3 + 43] = uint8(c2da_fresh157 >> 0x18)
    let c2da_fresh158 : int = 150
    let c2da_fresh159 : uint = uint(c2da_fresh158)
    c2da_mem[door_3 + 52] = uint8(c2da_fresh159)
    c2da_mem[door_3 + 53] = uint8(c2da_fresh159 >> 0x8)
    c2da_mem[door_3 + 54] = uint8(c2da_fresh159 >> 0x10)
    c2da_mem[door_3 + 55] = uint8(c2da_fresh159 >> 0x18)
    let c2da_fresh160 : int = 5 * 60 * 35
    let c2da_fresh161 : uint = uint(c2da_fresh160)
    c2da_mem[door_3 + 56] = uint8(c2da_fresh161)
    c2da_mem[door_3 + 57] = uint8(c2da_fresh161 >> 0x8)
    c2da_mem[door_3 + 58] = uint8(c2da_fresh161 >> 0x10)
    c2da_mem[door_3 + 59] = uint8(c2da_fresh161 >> 0x18)
    return
}

// This unit's static data, at heap offset 358816.
let private c2da_lin_static_p_doors_seg = fixed_array<int>(358816, 310)
let private c2da_lin_static_p_doors = fixed_array<uint64>(0x6465656e20756f59ul, 0x2065756c62206120ul, 0x6f206f742079656bul, 0x73696874206e6570ul, 0x6f5900726f6f6420ul, 0x61206465656e2075ul, 0x20776f6c6c657920ul, 0x6f206f742079656bul, 0x73696874206e6570ul, 0x6f5900726f6f6420ul, 0x61206465656e2075ul, 0x79656b2064657220ul, 0x6e65706f206f7420ul, 0x6f64207369687420ul, 0x65565f564500726ful, 0x6f446c6163697472ul, 0x65697254203a726ful, 0x6f6c63206f742064ul, 0x74656d6f73206573ul, 0x61687420676e6968ul, 0x74276e7361772074ul, 0x2e726f6f64206120ul, 0x656e20756f59000aul, 0x756c622061206465ul, 0x6f742079656b2065ul, 0x7461766974636120ul, 0x6f20736968742065ul, 0x6f59007463656a62ul, 0x61206465656e2075ul, 0x79656b2064657220ul, 0x69746361206f7420ul, 0x6968742065746176ul, 0x7463656a626f2073ul, 0x65656e20756f5900ul, 0x6c6c657920612064ul, 0x742079656b20776ful, 0x617669746361206ful, 0x2073696874206574ul, 0x7463656a626ful)

[init]
def private c2da_lin_init_static_p_doors() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_p_doors_seg[s * 2]
        for (k in range(c2da_lin_static_p_doors_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_p_doors[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_p_doors() {
    if (length(c2da_fn_table5) < 125) {
        resize(c2da_fn_table5, 125)
    }
    c2da_fn_table5[124] = @@T_VerticalDoor
}

[init]
def private c2da_lin_relink_init_p_doors() {
    c2da_relink_p_doors()
}
