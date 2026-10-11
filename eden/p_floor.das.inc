[export, sideeffects]
def T_MovePlane(var sector : int; var speed : int; var dest : int; var crush : uint; var floorOrCeiling : int; var direction : int) : uint {
    var flag : uint
    var lastpos : int
    if (floorOrCeiling == 0) {
        if (direction == -1) {
            if (int(uint(c2da_mem[sector]) | uint(c2da_mem[sector + 1]) << 0x8 | uint(c2da_mem[sector + 2]) << 0x10 | uint(c2da_mem[sector + 3]) << 0x18) - speed < dest) {
                lastpos = int(uint(c2da_mem[sector]) | uint(c2da_mem[sector + 1]) << 0x8 | uint(c2da_mem[sector + 2]) << 0x10 | uint(c2da_mem[sector + 3]) << 0x18)
                let c2da_fresh0 : uint = uint(dest)
                c2da_mem[sector] = uint8(c2da_fresh0)
                c2da_mem[sector + 1] = uint8(c2da_fresh0 >> 0x8)
                c2da_mem[sector + 2] = uint8(c2da_fresh0 >> 0x10)
                c2da_mem[sector + 3] = uint8(c2da_fresh0 >> 0x18)
                flag = uint(P_ChangeSector(sector, crush))
                if (flag == 1u) {
                    let c2da_fresh1 : uint = uint(lastpos)
                    c2da_mem[sector] = uint8(c2da_fresh1)
                    c2da_mem[sector + 1] = uint8(c2da_fresh1 >> 0x8)
                    c2da_mem[sector + 2] = uint8(c2da_fresh1 >> 0x10)
                    c2da_mem[sector + 3] = uint8(c2da_fresh1 >> 0x18)
                    P_ChangeSector(sector, crush)
                }
                return 2u
            } else {
                lastpos = int(uint(c2da_mem[sector]) | uint(c2da_mem[sector + 1]) << 0x8 | uint(c2da_mem[sector + 2]) << 0x10 | uint(c2da_mem[sector + 3]) << 0x18)
                let c2da_fresh2 : int = int(uint(c2da_mem[sector]) | uint(c2da_mem[sector + 1]) << 0x8 | uint(c2da_mem[sector + 2]) << 0x10 | uint(c2da_mem[sector + 3]) << 0x18) - speed
                let c2da_fresh3 : uint = uint(c2da_fresh2)
                c2da_mem[sector] = uint8(c2da_fresh3)
                c2da_mem[sector + 1] = uint8(c2da_fresh3 >> 0x8)
                c2da_mem[sector + 2] = uint8(c2da_fresh3 >> 0x10)
                c2da_mem[sector + 3] = uint8(c2da_fresh3 >> 0x18)
                flag = uint(P_ChangeSector(sector, crush))
                if (flag == 1u) {
                    let c2da_fresh4 : uint = uint(lastpos)
                    c2da_mem[sector] = uint8(c2da_fresh4)
                    c2da_mem[sector + 1] = uint8(c2da_fresh4 >> 0x8)
                    c2da_mem[sector + 2] = uint8(c2da_fresh4 >> 0x10)
                    c2da_mem[sector + 3] = uint8(c2da_fresh4 >> 0x18)
                    P_ChangeSector(sector, crush)
                    return 1u
                }
            }
        } elif (direction == 1) {
            if (int(uint(c2da_mem[sector]) | uint(c2da_mem[sector + 1]) << 0x8 | uint(c2da_mem[sector + 2]) << 0x10 | uint(c2da_mem[sector + 3]) << 0x18) + speed > dest) {
                lastpos = int(uint(c2da_mem[sector]) | uint(c2da_mem[sector + 1]) << 0x8 | uint(c2da_mem[sector + 2]) << 0x10 | uint(c2da_mem[sector + 3]) << 0x18)
                let c2da_fresh5 : uint = uint(dest)
                c2da_mem[sector] = uint8(c2da_fresh5)
                c2da_mem[sector + 1] = uint8(c2da_fresh5 >> 0x8)
                c2da_mem[sector + 2] = uint8(c2da_fresh5 >> 0x10)
                c2da_mem[sector + 3] = uint8(c2da_fresh5 >> 0x18)
                flag = uint(P_ChangeSector(sector, crush))
                if (flag == 1u) {
                    let c2da_fresh6 : uint = uint(lastpos)
                    c2da_mem[sector] = uint8(c2da_fresh6)
                    c2da_mem[sector + 1] = uint8(c2da_fresh6 >> 0x8)
                    c2da_mem[sector + 2] = uint8(c2da_fresh6 >> 0x10)
                    c2da_mem[sector + 3] = uint8(c2da_fresh6 >> 0x18)
                    P_ChangeSector(sector, crush)
                }
                return 2u
            } else {
                lastpos = int(uint(c2da_mem[sector]) | uint(c2da_mem[sector + 1]) << 0x8 | uint(c2da_mem[sector + 2]) << 0x10 | uint(c2da_mem[sector + 3]) << 0x18)
                let c2da_fresh7 : int = int(uint(c2da_mem[sector]) | uint(c2da_mem[sector + 1]) << 0x8 | uint(c2da_mem[sector + 2]) << 0x10 | uint(c2da_mem[sector + 3]) << 0x18) + speed
                let c2da_fresh8 : uint = uint(c2da_fresh7)
                c2da_mem[sector] = uint8(c2da_fresh8)
                c2da_mem[sector + 1] = uint8(c2da_fresh8 >> 0x8)
                c2da_mem[sector + 2] = uint8(c2da_fresh8 >> 0x10)
                c2da_mem[sector + 3] = uint8(c2da_fresh8 >> 0x18)
                flag = uint(P_ChangeSector(sector, crush))
                if (flag == 1u) {
                    if (crush == 1u) {
                        return 1u
                    }
                    let c2da_fresh9 : uint = uint(lastpos)
                    c2da_mem[sector] = uint8(c2da_fresh9)
                    c2da_mem[sector + 1] = uint8(c2da_fresh9 >> 0x8)
                    c2da_mem[sector + 2] = uint8(c2da_fresh9 >> 0x10)
                    c2da_mem[sector + 3] = uint8(c2da_fresh9 >> 0x18)
                    P_ChangeSector(sector, crush)
                    return 1u
                }
            }
        }
    } elif (floorOrCeiling == 1) {
        if (direction == -1) {
            if (int(uint(c2da_mem[sector + 4]) | uint(c2da_mem[sector + 5]) << 0x8 | uint(c2da_mem[sector + 6]) << 0x10 | uint(c2da_mem[sector + 7]) << 0x18) - speed < dest) {
                lastpos = int(uint(c2da_mem[sector + 4]) | uint(c2da_mem[sector + 5]) << 0x8 | uint(c2da_mem[sector + 6]) << 0x10 | uint(c2da_mem[sector + 7]) << 0x18)
                let c2da_fresh10 : uint = uint(dest)
                c2da_mem[sector + 4] = uint8(c2da_fresh10)
                c2da_mem[sector + 5] = uint8(c2da_fresh10 >> 0x8)
                c2da_mem[sector + 6] = uint8(c2da_fresh10 >> 0x10)
                c2da_mem[sector + 7] = uint8(c2da_fresh10 >> 0x18)
                flag = uint(P_ChangeSector(sector, crush))
                if (flag == 1u) {
                    let c2da_fresh11 : uint = uint(lastpos)
                    c2da_mem[sector + 4] = uint8(c2da_fresh11)
                    c2da_mem[sector + 5] = uint8(c2da_fresh11 >> 0x8)
                    c2da_mem[sector + 6] = uint8(c2da_fresh11 >> 0x10)
                    c2da_mem[sector + 7] = uint8(c2da_fresh11 >> 0x18)
                    P_ChangeSector(sector, crush)
                }
                return 2u
            } else {
                lastpos = int(uint(c2da_mem[sector + 4]) | uint(c2da_mem[sector + 5]) << 0x8 | uint(c2da_mem[sector + 6]) << 0x10 | uint(c2da_mem[sector + 7]) << 0x18)
                let c2da_fresh12 : int = int(uint(c2da_mem[sector + 4]) | uint(c2da_mem[sector + 5]) << 0x8 | uint(c2da_mem[sector + 6]) << 0x10 | uint(c2da_mem[sector + 7]) << 0x18) - speed
                let c2da_fresh13 : uint = uint(c2da_fresh12)
                c2da_mem[sector + 4] = uint8(c2da_fresh13)
                c2da_mem[sector + 5] = uint8(c2da_fresh13 >> 0x8)
                c2da_mem[sector + 6] = uint8(c2da_fresh13 >> 0x10)
                c2da_mem[sector + 7] = uint8(c2da_fresh13 >> 0x18)
                flag = uint(P_ChangeSector(sector, crush))
                if (flag == 1u) {
                    if (crush == 1u) {
                        return 1u
                    }
                    let c2da_fresh14 : uint = uint(lastpos)
                    c2da_mem[sector + 4] = uint8(c2da_fresh14)
                    c2da_mem[sector + 5] = uint8(c2da_fresh14 >> 0x8)
                    c2da_mem[sector + 6] = uint8(c2da_fresh14 >> 0x10)
                    c2da_mem[sector + 7] = uint8(c2da_fresh14 >> 0x18)
                    P_ChangeSector(sector, crush)
                    return 1u
                }
            }
        } elif (direction == 1) {
            if (int(uint(c2da_mem[sector + 4]) | uint(c2da_mem[sector + 5]) << 0x8 | uint(c2da_mem[sector + 6]) << 0x10 | uint(c2da_mem[sector + 7]) << 0x18) + speed > dest) {
                lastpos = int(uint(c2da_mem[sector + 4]) | uint(c2da_mem[sector + 5]) << 0x8 | uint(c2da_mem[sector + 6]) << 0x10 | uint(c2da_mem[sector + 7]) << 0x18)
                let c2da_fresh15 : uint = uint(dest)
                c2da_mem[sector + 4] = uint8(c2da_fresh15)
                c2da_mem[sector + 5] = uint8(c2da_fresh15 >> 0x8)
                c2da_mem[sector + 6] = uint8(c2da_fresh15 >> 0x10)
                c2da_mem[sector + 7] = uint8(c2da_fresh15 >> 0x18)
                flag = uint(P_ChangeSector(sector, crush))
                if (flag == 1u) {
                    let c2da_fresh16 : uint = uint(lastpos)
                    c2da_mem[sector + 4] = uint8(c2da_fresh16)
                    c2da_mem[sector + 5] = uint8(c2da_fresh16 >> 0x8)
                    c2da_mem[sector + 6] = uint8(c2da_fresh16 >> 0x10)
                    c2da_mem[sector + 7] = uint8(c2da_fresh16 >> 0x18)
                    P_ChangeSector(sector, crush)
                }
                return 2u
            } else {
                lastpos = int(uint(c2da_mem[sector + 4]) | uint(c2da_mem[sector + 5]) << 0x8 | uint(c2da_mem[sector + 6]) << 0x10 | uint(c2da_mem[sector + 7]) << 0x18)
                let c2da_fresh17 : int = int(uint(c2da_mem[sector + 4]) | uint(c2da_mem[sector + 5]) << 0x8 | uint(c2da_mem[sector + 6]) << 0x10 | uint(c2da_mem[sector + 7]) << 0x18) + speed
                let c2da_fresh18 : uint = uint(c2da_fresh17)
                c2da_mem[sector + 4] = uint8(c2da_fresh18)
                c2da_mem[sector + 5] = uint8(c2da_fresh18 >> 0x8)
                c2da_mem[sector + 6] = uint8(c2da_fresh18 >> 0x10)
                c2da_mem[sector + 7] = uint8(c2da_fresh18 >> 0x18)
                flag = uint(P_ChangeSector(sector, crush))
            }
        }
    }
    return 0u
}
[export, sideeffects]
def EV_BuildStairs(var line : int; var type_0 : uint) : int {
    var c2da_fresh24 : uint
    var secnum : int
    var height : int
    var i : int
    var newsecnum : int
    var texture : int
    var ok_0 : int
    var rtn : int
    var sec : int
    var tsec : int
    var floor : int
    var stairsize : int
    var speed_0 : int
    stairsize = 0
    speed_0 = 0
    secnum = -1
    rtn = 0
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
        floor = Z_Malloc(64, 6, 0)
        P_AddThinker(floor)
        let c2da_fresh19 : uint = uint(floor)
        c2da_mem[sec + 104] = uint8(c2da_fresh19)
        c2da_mem[sec + 105] = uint8(c2da_fresh19 >> 0x8)
        c2da_mem[sec + 106] = uint8(c2da_fresh19 >> 0x10)
        c2da_mem[sec + 107] = uint8(c2da_fresh19 >> 0x18)
        c2da_mem[sec + 108] = 0u8
        c2da_mem[sec + 109] = 0u8
        c2da_mem[sec + 110] = 0u8
        c2da_mem[sec + 111] = 0u8
        let c2da_fresh20 : uint = 128u
        c2da_mem[floor + 16] = uint8(c2da_fresh20)
        c2da_mem[floor + 17] = uint8(c2da_fresh20 >> 0x8)
        c2da_mem[floor + 18] = uint8(c2da_fresh20 >> 0x10)
        c2da_mem[floor + 19] = uint8(c2da_fresh20 >> 0x18)
        c2da_mem[floor + 20] = 0u8
        c2da_mem[floor + 21] = 0u8
        c2da_mem[floor + 22] = 0u8
        c2da_mem[floor + 23] = 0u8
        let c2da_fresh21 : int = 1
        let c2da_fresh22 : uint = uint(c2da_fresh21)
        c2da_mem[floor + 40] = uint8(c2da_fresh22)
        c2da_mem[floor + 41] = uint8(c2da_fresh22 >> 0x8)
        c2da_mem[floor + 42] = uint8(c2da_fresh22 >> 0x10)
        c2da_mem[floor + 43] = uint8(c2da_fresh22 >> 0x18)
        let c2da_fresh23 : uint = uint(sec)
        c2da_mem[floor + 32] = uint8(c2da_fresh23)
        c2da_mem[floor + 33] = uint8(c2da_fresh23 >> 0x8)
        c2da_mem[floor + 34] = uint8(c2da_fresh23 >> 0x10)
        c2da_mem[floor + 35] = uint8(c2da_fresh23 >> 0x18)
        c2da_mem[floor + 36] = 0u8
        c2da_mem[floor + 37] = 0u8
        c2da_mem[floor + 38] = 0u8
        c2da_mem[floor + 39] = 0u8
        c2da_fresh24 = type_0
        if (c2da_fresh24 == 0x0u) {
            speed_0 = (1 << 16) / 4
            stairsize = 8 * (1 << 16)
        } elif (c2da_fresh24 == 0x1u) {
            speed_0 = (1 << 16) * 4
            stairsize = 16 * (1 << 16)
        }
        let c2da_fresh25 : uint = uint(speed_0)
        c2da_mem[floor + 56] = uint8(c2da_fresh25)
        c2da_mem[floor + 57] = uint8(c2da_fresh25 >> 0x8)
        c2da_mem[floor + 58] = uint8(c2da_fresh25 >> 0x10)
        c2da_mem[floor + 59] = uint8(c2da_fresh25 >> 0x18)
        height = int(uint(c2da_mem[sec]) | uint(c2da_mem[sec + 1]) << 0x8 | uint(c2da_mem[sec + 2]) << 0x10 | uint(c2da_mem[sec + 3]) << 0x18) + stairsize
        let c2da_fresh26 : uint = uint(height)
        c2da_mem[floor + 52] = uint8(c2da_fresh26)
        c2da_mem[floor + 53] = uint8(c2da_fresh26 >> 0x8)
        c2da_mem[floor + 54] = uint8(c2da_fresh26 >> 0x10)
        c2da_mem[floor + 55] = uint8(c2da_fresh26 >> 0x18)
        texture = int(int16(uint(c2da_mem[sec + 8]) | uint(c2da_mem[sec + 9]) << 0x8))
        while (true) {
            ok_0 = 0
            i = 0
            while (i < int(uint(c2da_mem[sec + 112]) | uint(c2da_mem[sec + 113]) << 0x8 | uint(c2da_mem[sec + 114]) << 0x10 | uint(c2da_mem[sec + 115]) << 0x18)) {
                let c2da_fresh27 : int = int(uint(c2da_mem[sec + 120]) | uint(c2da_mem[sec + 121]) << 0x8 | uint(c2da_mem[sec + 122]) << 0x10 | uint(c2da_mem[sec + 123]) << 0x18) + i * 8
                let c2da_fresh28 : int = int(uint(c2da_mem[c2da_fresh27]) | uint(c2da_mem[c2da_fresh27 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh27 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh27 + 3]) << 0x18) + 24
                if ((int(int16(uint(c2da_mem[c2da_fresh28]) | uint(c2da_mem[c2da_fresh28 + 1]) << 0x8)) & 4) == 0) {
                    i++
                    continue
                }
                let c2da_fresh29 : int = int(uint(c2da_mem[sec + 120]) | uint(c2da_mem[sec + 121]) << 0x8 | uint(c2da_mem[sec + 122]) << 0x10 | uint(c2da_mem[sec + 123]) << 0x18) + i * 8
                let c2da_fresh30 : int = int(uint(c2da_mem[c2da_fresh29]) | uint(c2da_mem[c2da_fresh29 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh29 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh29 + 3]) << 0x18) + 56
                tsec = int(uint(c2da_mem[c2da_fresh30]) | uint(c2da_mem[c2da_fresh30 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh30 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh30 + 3]) << 0x18)
                if (secnum != int(int64((tsec - sectors) / 128))) {
                    i++
                    continue
                }
                let c2da_fresh31 : int = int(uint(c2da_mem[sec + 120]) | uint(c2da_mem[sec + 121]) << 0x8 | uint(c2da_mem[sec + 122]) << 0x10 | uint(c2da_mem[sec + 123]) << 0x18) + i * 8
                let c2da_fresh32 : int = int(uint(c2da_mem[c2da_fresh31]) | uint(c2da_mem[c2da_fresh31 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh31 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh31 + 3]) << 0x18) + 64
                tsec = int(uint(c2da_mem[c2da_fresh32]) | uint(c2da_mem[c2da_fresh32 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh32 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh32 + 3]) << 0x18)
                newsecnum = int(int64((tsec - sectors) / 128))
                if (int(int16(uint(c2da_mem[tsec + 8]) | uint(c2da_mem[tsec + 9]) << 0x8)) != texture) {
                    i++
                    continue
                }
                height += stairsize
                if (int(uint(c2da_mem[tsec + 104]) | uint(c2da_mem[tsec + 105]) << 0x8 | uint(c2da_mem[tsec + 106]) << 0x10 | uint(c2da_mem[tsec + 107]) << 0x18) != 0) {
                    i++
                    continue
                }
                sec = tsec
                secnum = newsecnum
                floor = Z_Malloc(64, 6, 0)
                P_AddThinker(floor)
                let c2da_fresh33 : uint = uint(floor)
                c2da_mem[sec + 104] = uint8(c2da_fresh33)
                c2da_mem[sec + 105] = uint8(c2da_fresh33 >> 0x8)
                c2da_mem[sec + 106] = uint8(c2da_fresh33 >> 0x10)
                c2da_mem[sec + 107] = uint8(c2da_fresh33 >> 0x18)
                c2da_mem[sec + 108] = 0u8
                c2da_mem[sec + 109] = 0u8
                c2da_mem[sec + 110] = 0u8
                c2da_mem[sec + 111] = 0u8
                let c2da_fresh34 : uint = 128u
                c2da_mem[floor + 16] = uint8(c2da_fresh34)
                c2da_mem[floor + 17] = uint8(c2da_fresh34 >> 0x8)
                c2da_mem[floor + 18] = uint8(c2da_fresh34 >> 0x10)
                c2da_mem[floor + 19] = uint8(c2da_fresh34 >> 0x18)
                c2da_mem[floor + 20] = 0u8
                c2da_mem[floor + 21] = 0u8
                c2da_mem[floor + 22] = 0u8
                c2da_mem[floor + 23] = 0u8
                let c2da_fresh35 : int = 1
                let c2da_fresh36 : uint = uint(c2da_fresh35)
                c2da_mem[floor + 40] = uint8(c2da_fresh36)
                c2da_mem[floor + 41] = uint8(c2da_fresh36 >> 0x8)
                c2da_mem[floor + 42] = uint8(c2da_fresh36 >> 0x10)
                c2da_mem[floor + 43] = uint8(c2da_fresh36 >> 0x18)
                let c2da_fresh37 : uint = uint(sec)
                c2da_mem[floor + 32] = uint8(c2da_fresh37)
                c2da_mem[floor + 33] = uint8(c2da_fresh37 >> 0x8)
                c2da_mem[floor + 34] = uint8(c2da_fresh37 >> 0x10)
                c2da_mem[floor + 35] = uint8(c2da_fresh37 >> 0x18)
                c2da_mem[floor + 36] = 0u8
                c2da_mem[floor + 37] = 0u8
                c2da_mem[floor + 38] = 0u8
                c2da_mem[floor + 39] = 0u8
                let c2da_fresh38 : uint = uint(speed_0)
                c2da_mem[floor + 56] = uint8(c2da_fresh38)
                c2da_mem[floor + 57] = uint8(c2da_fresh38 >> 0x8)
                c2da_mem[floor + 58] = uint8(c2da_fresh38 >> 0x10)
                c2da_mem[floor + 59] = uint8(c2da_fresh38 >> 0x18)
                let c2da_fresh39 : uint = uint(height)
                c2da_mem[floor + 52] = uint8(c2da_fresh39)
                c2da_mem[floor + 53] = uint8(c2da_fresh39 >> 0x8)
                c2da_mem[floor + 54] = uint8(c2da_fresh39 >> 0x10)
                c2da_mem[floor + 55] = uint8(c2da_fresh39 >> 0x18)
                ok_0 = 1
                break
            }
            if (ok_0 == 0) {
                break
            }
        }
    }
    return rtn
}
[export, sideeffects]
def T_MoveFloor(var floor_0 : int) {
    var c2da_fresh42 : uint
    var c2da_fresh49 : uint
    var res : uint = T_MovePlane(int(uint(c2da_mem[floor_0 + 32]) | uint(c2da_mem[floor_0 + 33]) << 0x8 | uint(c2da_mem[floor_0 + 34]) << 0x10 | uint(c2da_mem[floor_0 + 35]) << 0x18), int(uint(c2da_mem[floor_0 + 56]) | uint(c2da_mem[floor_0 + 57]) << 0x8 | uint(c2da_mem[floor_0 + 58]) << 0x10 | uint(c2da_mem[floor_0 + 59]) << 0x18), int(uint(c2da_mem[floor_0 + 52]) | uint(c2da_mem[floor_0 + 53]) << 0x8 | uint(c2da_mem[floor_0 + 54]) << 0x10 | uint(c2da_mem[floor_0 + 55]) << 0x18), uint(c2da_mem[floor_0 + 28]) | uint(c2da_mem[floor_0 + 29]) << 0x8 | uint(c2da_mem[floor_0 + 30]) << 0x10 | uint(c2da_mem[floor_0 + 31]) << 0x18, 0, int(uint(c2da_mem[floor_0 + 40]) | uint(c2da_mem[floor_0 + 41]) << 0x8 | uint(c2da_mem[floor_0 + 42]) << 0x10 | uint(c2da_mem[floor_0 + 43]) << 0x18))
    if ((leveltime & 7) == 0) {
        S_StartSound(int(uint(c2da_mem[floor_0 + 32]) | uint(c2da_mem[floor_0 + 33]) << 0x8 | uint(c2da_mem[floor_0 + 34]) << 0x10 | uint(c2da_mem[floor_0 + 35]) << 0x18) + 48, 22)
    }
    if (res == 2u) {
        let c2da_fresh40 : int = int(uint(c2da_mem[floor_0 + 32]) | uint(c2da_mem[floor_0 + 33]) << 0x8 | uint(c2da_mem[floor_0 + 34]) << 0x10 | uint(c2da_mem[floor_0 + 35]) << 0x18) + 104
        let c2da_fresh41 : uint = 0u
        c2da_mem[c2da_fresh40] = uint8(c2da_fresh41)
        c2da_mem[c2da_fresh40 + 1] = uint8(c2da_fresh41 >> 0x8)
        c2da_mem[c2da_fresh40 + 2] = uint8(c2da_fresh41 >> 0x10)
        c2da_mem[c2da_fresh40 + 3] = uint8(c2da_fresh41 >> 0x18)
        c2da_mem[c2da_fresh40 + 4] = 0u8
        c2da_mem[c2da_fresh40 + 5] = 0u8
        c2da_mem[c2da_fresh40 + 6] = 0u8
        c2da_mem[c2da_fresh40 + 7] = 0u8
        if (int(uint(c2da_mem[floor_0 + 40]) | uint(c2da_mem[floor_0 + 41]) << 0x8 | uint(c2da_mem[floor_0 + 42]) << 0x10 | uint(c2da_mem[floor_0 + 43]) << 0x18) != 1) {
            goto label 2
        }
        c2da_fresh42 = uint(c2da_mem[floor_0 + 24]) | uint(c2da_mem[floor_0 + 25]) << 0x8 | uint(c2da_mem[floor_0 + 26]) << 0x10 | uint(c2da_mem[floor_0 + 27]) << 0x18
        if (c2da_fresh42 == 0xbu) {
            goto label 0
        } else {
            goto label 1
        }
        label 0:
        let c2da_fresh43 : int = int(uint(c2da_mem[floor_0 + 32]) | uint(c2da_mem[floor_0 + 33]) << 0x8 | uint(c2da_mem[floor_0 + 34]) << 0x10 | uint(c2da_mem[floor_0 + 35]) << 0x18) + 14
        let c2da_fresh44 : int16 = int16(int(uint(c2da_mem[floor_0 + 44]) | uint(c2da_mem[floor_0 + 45]) << 0x8 | uint(c2da_mem[floor_0 + 46]) << 0x10 | uint(c2da_mem[floor_0 + 47]) << 0x18))
        let c2da_fresh45 : uint = uint(c2da_fresh44)
        c2da_mem[c2da_fresh43] = uint8(c2da_fresh45)
        c2da_mem[c2da_fresh43 + 1] = uint8(c2da_fresh45 >> 0x8)
        let c2da_fresh46 : int = int(uint(c2da_mem[floor_0 + 32]) | uint(c2da_mem[floor_0 + 33]) << 0x8 | uint(c2da_mem[floor_0 + 34]) << 0x10 | uint(c2da_mem[floor_0 + 35]) << 0x18) + 8
        let c2da_fresh47 : int16 = int16(uint(c2da_mem[floor_0 + 48]) | uint(c2da_mem[floor_0 + 49]) << 0x8)
        let c2da_fresh48 : uint = uint(c2da_fresh47)
        c2da_mem[c2da_fresh46] = uint8(c2da_fresh48)
        c2da_mem[c2da_fresh46 + 1] = uint8(c2da_fresh48 >> 0x8)
        label 1:
        goto label 6
        label 2:
        if (int(uint(c2da_mem[floor_0 + 40]) | uint(c2da_mem[floor_0 + 41]) << 0x8 | uint(c2da_mem[floor_0 + 42]) << 0x10 | uint(c2da_mem[floor_0 + 43]) << 0x18) != -1) {
            goto label 5
        }
        c2da_fresh49 = uint(c2da_mem[floor_0 + 24]) | uint(c2da_mem[floor_0 + 25]) << 0x8 | uint(c2da_mem[floor_0 + 26]) << 0x10 | uint(c2da_mem[floor_0 + 27]) << 0x18
        if (c2da_fresh49 == 0x6u) {
            goto label 3
        } else {
            goto label 4
        }
        label 3:
        let c2da_fresh50 : int = int(uint(c2da_mem[floor_0 + 32]) | uint(c2da_mem[floor_0 + 33]) << 0x8 | uint(c2da_mem[floor_0 + 34]) << 0x10 | uint(c2da_mem[floor_0 + 35]) << 0x18) + 14
        let c2da_fresh51 : int16 = int16(int(uint(c2da_mem[floor_0 + 44]) | uint(c2da_mem[floor_0 + 45]) << 0x8 | uint(c2da_mem[floor_0 + 46]) << 0x10 | uint(c2da_mem[floor_0 + 47]) << 0x18))
        let c2da_fresh52 : uint = uint(c2da_fresh51)
        c2da_mem[c2da_fresh50] = uint8(c2da_fresh52)
        c2da_mem[c2da_fresh50 + 1] = uint8(c2da_fresh52 >> 0x8)
        let c2da_fresh53 : int = int(uint(c2da_mem[floor_0 + 32]) | uint(c2da_mem[floor_0 + 33]) << 0x8 | uint(c2da_mem[floor_0 + 34]) << 0x10 | uint(c2da_mem[floor_0 + 35]) << 0x18) + 8
        let c2da_fresh54 : int16 = int16(uint(c2da_mem[floor_0 + 48]) | uint(c2da_mem[floor_0 + 49]) << 0x8)
        let c2da_fresh55 : uint = uint(c2da_fresh54)
        c2da_mem[c2da_fresh53] = uint8(c2da_fresh55)
        c2da_mem[c2da_fresh53 + 1] = uint8(c2da_fresh55 >> 0x8)
        label 4:
        label 5:
        label 6:
        P_RemoveThinker(floor_0)
        S_StartSound(int(uint(c2da_mem[floor_0 + 32]) | uint(c2da_mem[floor_0 + 33]) << 0x8 | uint(c2da_mem[floor_0 + 34]) << 0x10 | uint(c2da_mem[floor_0 + 35]) << 0x18) + 48, 19)
    }
    return
}
[export, sideeffects]
def EV_DoFloor(var line_0 : int; var floortype : uint) : int {
    var c2da_fresh61 : uint
    var secnum_0 : int
    var rtn_0 : int
    var i_0 : int
    var sec_0 : int
    var floor_1 : int
    var minsize : int
    var side : int
    secnum_0 = -1
    rtn_0 = 0
    while (true) {
        secnum_0 = P_FindSectorFromLineTag(line_0, secnum_0)
        if (secnum_0 < 0) {
            break
        }
        sec_0 = sectors + secnum_0 * 128
        if (int(uint(c2da_mem[sec_0 + 104]) | uint(c2da_mem[sec_0 + 105]) << 0x8 | uint(c2da_mem[sec_0 + 106]) << 0x10 | uint(c2da_mem[sec_0 + 107]) << 0x18) != 0) {
            continue
        }
        rtn_0 = 1
        floor_1 = Z_Malloc(64, 6, 0)
        P_AddThinker(floor_1)
        let c2da_fresh56 : uint = uint(floor_1)
        c2da_mem[sec_0 + 104] = uint8(c2da_fresh56)
        c2da_mem[sec_0 + 105] = uint8(c2da_fresh56 >> 0x8)
        c2da_mem[sec_0 + 106] = uint8(c2da_fresh56 >> 0x10)
        c2da_mem[sec_0 + 107] = uint8(c2da_fresh56 >> 0x18)
        c2da_mem[sec_0 + 108] = 0u8
        c2da_mem[sec_0 + 109] = 0u8
        c2da_mem[sec_0 + 110] = 0u8
        c2da_mem[sec_0 + 111] = 0u8
        let c2da_fresh57 : uint = 128u
        c2da_mem[floor_1 + 16] = uint8(c2da_fresh57)
        c2da_mem[floor_1 + 17] = uint8(c2da_fresh57 >> 0x8)
        c2da_mem[floor_1 + 18] = uint8(c2da_fresh57 >> 0x10)
        c2da_mem[floor_1 + 19] = uint8(c2da_fresh57 >> 0x18)
        c2da_mem[floor_1 + 20] = 0u8
        c2da_mem[floor_1 + 21] = 0u8
        c2da_mem[floor_1 + 22] = 0u8
        c2da_mem[floor_1 + 23] = 0u8
        let c2da_fresh58 : uint = floortype
        c2da_mem[floor_1 + 24] = uint8(c2da_fresh58)
        c2da_mem[floor_1 + 25] = uint8(c2da_fresh58 >> 0x8)
        c2da_mem[floor_1 + 26] = uint8(c2da_fresh58 >> 0x10)
        c2da_mem[floor_1 + 27] = uint8(c2da_fresh58 >> 0x18)
        let c2da_fresh59 : uint = 0u
        let c2da_fresh60 : uint = c2da_fresh59
        c2da_mem[floor_1 + 28] = uint8(c2da_fresh60)
        c2da_mem[floor_1 + 29] = uint8(c2da_fresh60 >> 0x8)
        c2da_mem[floor_1 + 30] = uint8(c2da_fresh60 >> 0x10)
        c2da_mem[floor_1 + 31] = uint8(c2da_fresh60 >> 0x18)
        c2da_fresh61 = floortype
        if (c2da_fresh61 <= 0xcu) {
            goto int(c2da_fresh61)
        }
        continue
        label 11:
        continue
        label 0:
        let c2da_fresh62 : int = -1
        let c2da_fresh63 : uint = uint(c2da_fresh62)
        c2da_mem[floor_1 + 40] = uint8(c2da_fresh63)
        c2da_mem[floor_1 + 41] = uint8(c2da_fresh63 >> 0x8)
        c2da_mem[floor_1 + 42] = uint8(c2da_fresh63 >> 0x10)
        c2da_mem[floor_1 + 43] = uint8(c2da_fresh63 >> 0x18)
        let c2da_fresh64 : uint = uint(sec_0)
        c2da_mem[floor_1 + 32] = uint8(c2da_fresh64)
        c2da_mem[floor_1 + 33] = uint8(c2da_fresh64 >> 0x8)
        c2da_mem[floor_1 + 34] = uint8(c2da_fresh64 >> 0x10)
        c2da_mem[floor_1 + 35] = uint8(c2da_fresh64 >> 0x18)
        c2da_mem[floor_1 + 36] = 0u8
        c2da_mem[floor_1 + 37] = 0u8
        c2da_mem[floor_1 + 38] = 0u8
        c2da_mem[floor_1 + 39] = 0u8
        let c2da_fresh65 : int = 1 << 16
        let c2da_fresh66 : uint = uint(c2da_fresh65)
        c2da_mem[floor_1 + 56] = uint8(c2da_fresh66)
        c2da_mem[floor_1 + 57] = uint8(c2da_fresh66 >> 0x8)
        c2da_mem[floor_1 + 58] = uint8(c2da_fresh66 >> 0x10)
        c2da_mem[floor_1 + 59] = uint8(c2da_fresh66 >> 0x18)
        let c2da_fresh67 : int = P_FindHighestFloorSurrounding(sec_0)
        let c2da_fresh68 : uint = uint(c2da_fresh67)
        c2da_mem[floor_1 + 52] = uint8(c2da_fresh68)
        c2da_mem[floor_1 + 53] = uint8(c2da_fresh68 >> 0x8)
        c2da_mem[floor_1 + 54] = uint8(c2da_fresh68 >> 0x10)
        c2da_mem[floor_1 + 55] = uint8(c2da_fresh68 >> 0x18)
        continue
        label 1:
        let c2da_fresh69 : int = -1
        let c2da_fresh70 : uint = uint(c2da_fresh69)
        c2da_mem[floor_1 + 40] = uint8(c2da_fresh70)
        c2da_mem[floor_1 + 41] = uint8(c2da_fresh70 >> 0x8)
        c2da_mem[floor_1 + 42] = uint8(c2da_fresh70 >> 0x10)
        c2da_mem[floor_1 + 43] = uint8(c2da_fresh70 >> 0x18)
        let c2da_fresh71 : uint = uint(sec_0)
        c2da_mem[floor_1 + 32] = uint8(c2da_fresh71)
        c2da_mem[floor_1 + 33] = uint8(c2da_fresh71 >> 0x8)
        c2da_mem[floor_1 + 34] = uint8(c2da_fresh71 >> 0x10)
        c2da_mem[floor_1 + 35] = uint8(c2da_fresh71 >> 0x18)
        c2da_mem[floor_1 + 36] = 0u8
        c2da_mem[floor_1 + 37] = 0u8
        c2da_mem[floor_1 + 38] = 0u8
        c2da_mem[floor_1 + 39] = 0u8
        let c2da_fresh72 : int = 1 << 16
        let c2da_fresh73 : uint = uint(c2da_fresh72)
        c2da_mem[floor_1 + 56] = uint8(c2da_fresh73)
        c2da_mem[floor_1 + 57] = uint8(c2da_fresh73 >> 0x8)
        c2da_mem[floor_1 + 58] = uint8(c2da_fresh73 >> 0x10)
        c2da_mem[floor_1 + 59] = uint8(c2da_fresh73 >> 0x18)
        let c2da_fresh74 : int = P_FindLowestFloorSurrounding(sec_0)
        let c2da_fresh75 : uint = uint(c2da_fresh74)
        c2da_mem[floor_1 + 52] = uint8(c2da_fresh75)
        c2da_mem[floor_1 + 53] = uint8(c2da_fresh75 >> 0x8)
        c2da_mem[floor_1 + 54] = uint8(c2da_fresh75 >> 0x10)
        c2da_mem[floor_1 + 55] = uint8(c2da_fresh75 >> 0x18)
        continue
        label 2:
        let c2da_fresh76 : int = -1
        let c2da_fresh77 : uint = uint(c2da_fresh76)
        c2da_mem[floor_1 + 40] = uint8(c2da_fresh77)
        c2da_mem[floor_1 + 41] = uint8(c2da_fresh77 >> 0x8)
        c2da_mem[floor_1 + 42] = uint8(c2da_fresh77 >> 0x10)
        c2da_mem[floor_1 + 43] = uint8(c2da_fresh77 >> 0x18)
        let c2da_fresh78 : uint = uint(sec_0)
        c2da_mem[floor_1 + 32] = uint8(c2da_fresh78)
        c2da_mem[floor_1 + 33] = uint8(c2da_fresh78 >> 0x8)
        c2da_mem[floor_1 + 34] = uint8(c2da_fresh78 >> 0x10)
        c2da_mem[floor_1 + 35] = uint8(c2da_fresh78 >> 0x18)
        c2da_mem[floor_1 + 36] = 0u8
        c2da_mem[floor_1 + 37] = 0u8
        c2da_mem[floor_1 + 38] = 0u8
        c2da_mem[floor_1 + 39] = 0u8
        let c2da_fresh79 : int = (1 << 16) * 4
        let c2da_fresh80 : uint = uint(c2da_fresh79)
        c2da_mem[floor_1 + 56] = uint8(c2da_fresh80)
        c2da_mem[floor_1 + 57] = uint8(c2da_fresh80 >> 0x8)
        c2da_mem[floor_1 + 58] = uint8(c2da_fresh80 >> 0x10)
        c2da_mem[floor_1 + 59] = uint8(c2da_fresh80 >> 0x18)
        let c2da_fresh81 : int = P_FindHighestFloorSurrounding(sec_0)
        let c2da_fresh82 : uint = uint(c2da_fresh81)
        c2da_mem[floor_1 + 52] = uint8(c2da_fresh82)
        c2da_mem[floor_1 + 53] = uint8(c2da_fresh82 >> 0x8)
        c2da_mem[floor_1 + 54] = uint8(c2da_fresh82 >> 0x10)
        c2da_mem[floor_1 + 55] = uint8(c2da_fresh82 >> 0x18)
        if (int(uint(c2da_mem[floor_1 + 52]) | uint(c2da_mem[floor_1 + 53]) << 0x8 | uint(c2da_mem[floor_1 + 54]) << 0x10 | uint(c2da_mem[floor_1 + 55]) << 0x18) != int(uint(c2da_mem[sec_0]) | uint(c2da_mem[sec_0 + 1]) << 0x8 | uint(c2da_mem[sec_0 + 2]) << 0x10 | uint(c2da_mem[sec_0 + 3]) << 0x18)) {
            let c2da_fresh83 : int = int(uint(c2da_mem[floor_1 + 52]) | uint(c2da_mem[floor_1 + 53]) << 0x8 | uint(c2da_mem[floor_1 + 54]) << 0x10 | uint(c2da_mem[floor_1 + 55]) << 0x18) + 8 * (1 << 16)
            let c2da_fresh84 : uint = uint(c2da_fresh83)
            c2da_mem[floor_1 + 52] = uint8(c2da_fresh84)
            c2da_mem[floor_1 + 53] = uint8(c2da_fresh84 >> 0x8)
            c2da_mem[floor_1 + 54] = uint8(c2da_fresh84 >> 0x10)
            c2da_mem[floor_1 + 55] = uint8(c2da_fresh84 >> 0x18)
        }
        continue
        label 9:
        let c2da_fresh85 : uint = 1u
        let c2da_fresh86 : uint = c2da_fresh85
        c2da_mem[floor_1 + 28] = uint8(c2da_fresh86)
        c2da_mem[floor_1 + 29] = uint8(c2da_fresh86 >> 0x8)
        c2da_mem[floor_1 + 30] = uint8(c2da_fresh86 >> 0x10)
        c2da_mem[floor_1 + 31] = uint8(c2da_fresh86 >> 0x18)
        label 3:
        let c2da_fresh87 : int = 1
        let c2da_fresh88 : uint = uint(c2da_fresh87)
        c2da_mem[floor_1 + 40] = uint8(c2da_fresh88)
        c2da_mem[floor_1 + 41] = uint8(c2da_fresh88 >> 0x8)
        c2da_mem[floor_1 + 42] = uint8(c2da_fresh88 >> 0x10)
        c2da_mem[floor_1 + 43] = uint8(c2da_fresh88 >> 0x18)
        let c2da_fresh89 : uint = uint(sec_0)
        c2da_mem[floor_1 + 32] = uint8(c2da_fresh89)
        c2da_mem[floor_1 + 33] = uint8(c2da_fresh89 >> 0x8)
        c2da_mem[floor_1 + 34] = uint8(c2da_fresh89 >> 0x10)
        c2da_mem[floor_1 + 35] = uint8(c2da_fresh89 >> 0x18)
        c2da_mem[floor_1 + 36] = 0u8
        c2da_mem[floor_1 + 37] = 0u8
        c2da_mem[floor_1 + 38] = 0u8
        c2da_mem[floor_1 + 39] = 0u8
        let c2da_fresh90 : int = 1 << 16
        let c2da_fresh91 : uint = uint(c2da_fresh90)
        c2da_mem[floor_1 + 56] = uint8(c2da_fresh91)
        c2da_mem[floor_1 + 57] = uint8(c2da_fresh91 >> 0x8)
        c2da_mem[floor_1 + 58] = uint8(c2da_fresh91 >> 0x10)
        c2da_mem[floor_1 + 59] = uint8(c2da_fresh91 >> 0x18)
        let c2da_fresh92 : int = P_FindLowestCeilingSurrounding(sec_0)
        let c2da_fresh93 : uint = uint(c2da_fresh92)
        c2da_mem[floor_1 + 52] = uint8(c2da_fresh93)
        c2da_mem[floor_1 + 53] = uint8(c2da_fresh93 >> 0x8)
        c2da_mem[floor_1 + 54] = uint8(c2da_fresh93 >> 0x10)
        c2da_mem[floor_1 + 55] = uint8(c2da_fresh93 >> 0x18)
        if (int(uint(c2da_mem[floor_1 + 52]) | uint(c2da_mem[floor_1 + 53]) << 0x8 | uint(c2da_mem[floor_1 + 54]) << 0x10 | uint(c2da_mem[floor_1 + 55]) << 0x18) > int(uint(c2da_mem[sec_0 + 4]) | uint(c2da_mem[sec_0 + 5]) << 0x8 | uint(c2da_mem[sec_0 + 6]) << 0x10 | uint(c2da_mem[sec_0 + 7]) << 0x18)) {
            let c2da_fresh94 : int = int(uint(c2da_mem[sec_0 + 4]) | uint(c2da_mem[sec_0 + 5]) << 0x8 | uint(c2da_mem[sec_0 + 6]) << 0x10 | uint(c2da_mem[sec_0 + 7]) << 0x18)
            let c2da_fresh95 : uint = uint(c2da_fresh94)
            c2da_mem[floor_1 + 52] = uint8(c2da_fresh95)
            c2da_mem[floor_1 + 53] = uint8(c2da_fresh95 >> 0x8)
            c2da_mem[floor_1 + 54] = uint8(c2da_fresh95 >> 0x10)
            c2da_mem[floor_1 + 55] = uint8(c2da_fresh95 >> 0x18)
        }
        let c2da_fresh96 : int = int(uint(c2da_mem[floor_1 + 52]) | uint(c2da_mem[floor_1 + 53]) << 0x8 | uint(c2da_mem[floor_1 + 54]) << 0x10 | uint(c2da_mem[floor_1 + 55]) << 0x18) - 8 * (1 << 16) * (floortype == 9u ? 1 : 0)
        let c2da_fresh97 : uint = uint(c2da_fresh96)
        c2da_mem[floor_1 + 52] = uint8(c2da_fresh97)
        c2da_mem[floor_1 + 53] = uint8(c2da_fresh97 >> 0x8)
        c2da_mem[floor_1 + 54] = uint8(c2da_fresh97 >> 0x10)
        c2da_mem[floor_1 + 55] = uint8(c2da_fresh97 >> 0x18)
        continue
        label 10:
        let c2da_fresh98 : int = 1
        let c2da_fresh99 : uint = uint(c2da_fresh98)
        c2da_mem[floor_1 + 40] = uint8(c2da_fresh99)
        c2da_mem[floor_1 + 41] = uint8(c2da_fresh99 >> 0x8)
        c2da_mem[floor_1 + 42] = uint8(c2da_fresh99 >> 0x10)
        c2da_mem[floor_1 + 43] = uint8(c2da_fresh99 >> 0x18)
        let c2da_fresh100 : uint = uint(sec_0)
        c2da_mem[floor_1 + 32] = uint8(c2da_fresh100)
        c2da_mem[floor_1 + 33] = uint8(c2da_fresh100 >> 0x8)
        c2da_mem[floor_1 + 34] = uint8(c2da_fresh100 >> 0x10)
        c2da_mem[floor_1 + 35] = uint8(c2da_fresh100 >> 0x18)
        c2da_mem[floor_1 + 36] = 0u8
        c2da_mem[floor_1 + 37] = 0u8
        c2da_mem[floor_1 + 38] = 0u8
        c2da_mem[floor_1 + 39] = 0u8
        let c2da_fresh101 : int = (1 << 16) * 4
        let c2da_fresh102 : uint = uint(c2da_fresh101)
        c2da_mem[floor_1 + 56] = uint8(c2da_fresh102)
        c2da_mem[floor_1 + 57] = uint8(c2da_fresh102 >> 0x8)
        c2da_mem[floor_1 + 58] = uint8(c2da_fresh102 >> 0x10)
        c2da_mem[floor_1 + 59] = uint8(c2da_fresh102 >> 0x18)
        let c2da_fresh103 : int = P_FindNextHighestFloor(sec_0, int(uint(c2da_mem[sec_0]) | uint(c2da_mem[sec_0 + 1]) << 0x8 | uint(c2da_mem[sec_0 + 2]) << 0x10 | uint(c2da_mem[sec_0 + 3]) << 0x18))
        let c2da_fresh104 : uint = uint(c2da_fresh103)
        c2da_mem[floor_1 + 52] = uint8(c2da_fresh104)
        c2da_mem[floor_1 + 53] = uint8(c2da_fresh104 >> 0x8)
        c2da_mem[floor_1 + 54] = uint8(c2da_fresh104 >> 0x10)
        c2da_mem[floor_1 + 55] = uint8(c2da_fresh104 >> 0x18)
        continue
        label 4:
        let c2da_fresh105 : int = 1
        let c2da_fresh106 : uint = uint(c2da_fresh105)
        c2da_mem[floor_1 + 40] = uint8(c2da_fresh106)
        c2da_mem[floor_1 + 41] = uint8(c2da_fresh106 >> 0x8)
        c2da_mem[floor_1 + 42] = uint8(c2da_fresh106 >> 0x10)
        c2da_mem[floor_1 + 43] = uint8(c2da_fresh106 >> 0x18)
        let c2da_fresh107 : uint = uint(sec_0)
        c2da_mem[floor_1 + 32] = uint8(c2da_fresh107)
        c2da_mem[floor_1 + 33] = uint8(c2da_fresh107 >> 0x8)
        c2da_mem[floor_1 + 34] = uint8(c2da_fresh107 >> 0x10)
        c2da_mem[floor_1 + 35] = uint8(c2da_fresh107 >> 0x18)
        c2da_mem[floor_1 + 36] = 0u8
        c2da_mem[floor_1 + 37] = 0u8
        c2da_mem[floor_1 + 38] = 0u8
        c2da_mem[floor_1 + 39] = 0u8
        let c2da_fresh108 : int = 1 << 16
        let c2da_fresh109 : uint = uint(c2da_fresh108)
        c2da_mem[floor_1 + 56] = uint8(c2da_fresh109)
        c2da_mem[floor_1 + 57] = uint8(c2da_fresh109 >> 0x8)
        c2da_mem[floor_1 + 58] = uint8(c2da_fresh109 >> 0x10)
        c2da_mem[floor_1 + 59] = uint8(c2da_fresh109 >> 0x18)
        let c2da_fresh110 : int = P_FindNextHighestFloor(sec_0, int(uint(c2da_mem[sec_0]) | uint(c2da_mem[sec_0 + 1]) << 0x8 | uint(c2da_mem[sec_0 + 2]) << 0x10 | uint(c2da_mem[sec_0 + 3]) << 0x18))
        let c2da_fresh111 : uint = uint(c2da_fresh110)
        c2da_mem[floor_1 + 52] = uint8(c2da_fresh111)
        c2da_mem[floor_1 + 53] = uint8(c2da_fresh111 >> 0x8)
        c2da_mem[floor_1 + 54] = uint8(c2da_fresh111 >> 0x10)
        c2da_mem[floor_1 + 55] = uint8(c2da_fresh111 >> 0x18)
        continue
        label 7:
        let c2da_fresh112 : int = 1
        let c2da_fresh113 : uint = uint(c2da_fresh112)
        c2da_mem[floor_1 + 40] = uint8(c2da_fresh113)
        c2da_mem[floor_1 + 41] = uint8(c2da_fresh113 >> 0x8)
        c2da_mem[floor_1 + 42] = uint8(c2da_fresh113 >> 0x10)
        c2da_mem[floor_1 + 43] = uint8(c2da_fresh113 >> 0x18)
        let c2da_fresh114 : uint = uint(sec_0)
        c2da_mem[floor_1 + 32] = uint8(c2da_fresh114)
        c2da_mem[floor_1 + 33] = uint8(c2da_fresh114 >> 0x8)
        c2da_mem[floor_1 + 34] = uint8(c2da_fresh114 >> 0x10)
        c2da_mem[floor_1 + 35] = uint8(c2da_fresh114 >> 0x18)
        c2da_mem[floor_1 + 36] = 0u8
        c2da_mem[floor_1 + 37] = 0u8
        c2da_mem[floor_1 + 38] = 0u8
        c2da_mem[floor_1 + 39] = 0u8
        let c2da_fresh115 : int = 1 << 16
        let c2da_fresh116 : uint = uint(c2da_fresh115)
        c2da_mem[floor_1 + 56] = uint8(c2da_fresh116)
        c2da_mem[floor_1 + 57] = uint8(c2da_fresh116 >> 0x8)
        c2da_mem[floor_1 + 58] = uint8(c2da_fresh116 >> 0x10)
        c2da_mem[floor_1 + 59] = uint8(c2da_fresh116 >> 0x18)
        let c2da_fresh117 : int = int(uint(c2da_mem[floor_1 + 32]) | uint(c2da_mem[floor_1 + 33]) << 0x8 | uint(c2da_mem[floor_1 + 34]) << 0x10 | uint(c2da_mem[floor_1 + 35]) << 0x18)
        let c2da_fresh118 : int = int(uint(c2da_mem[c2da_fresh117]) | uint(c2da_mem[c2da_fresh117 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh117 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh117 + 3]) << 0x18) + 24 * (1 << 16)
        let c2da_fresh119 : uint = uint(c2da_fresh118)
        c2da_mem[floor_1 + 52] = uint8(c2da_fresh119)
        c2da_mem[floor_1 + 53] = uint8(c2da_fresh119 >> 0x8)
        c2da_mem[floor_1 + 54] = uint8(c2da_fresh119 >> 0x10)
        c2da_mem[floor_1 + 55] = uint8(c2da_fresh119 >> 0x18)
        continue
        label 12:
        let c2da_fresh120 : int = 1
        let c2da_fresh121 : uint = uint(c2da_fresh120)
        c2da_mem[floor_1 + 40] = uint8(c2da_fresh121)
        c2da_mem[floor_1 + 41] = uint8(c2da_fresh121 >> 0x8)
        c2da_mem[floor_1 + 42] = uint8(c2da_fresh121 >> 0x10)
        c2da_mem[floor_1 + 43] = uint8(c2da_fresh121 >> 0x18)
        let c2da_fresh122 : uint = uint(sec_0)
        c2da_mem[floor_1 + 32] = uint8(c2da_fresh122)
        c2da_mem[floor_1 + 33] = uint8(c2da_fresh122 >> 0x8)
        c2da_mem[floor_1 + 34] = uint8(c2da_fresh122 >> 0x10)
        c2da_mem[floor_1 + 35] = uint8(c2da_fresh122 >> 0x18)
        c2da_mem[floor_1 + 36] = 0u8
        c2da_mem[floor_1 + 37] = 0u8
        c2da_mem[floor_1 + 38] = 0u8
        c2da_mem[floor_1 + 39] = 0u8
        let c2da_fresh123 : int = 1 << 16
        let c2da_fresh124 : uint = uint(c2da_fresh123)
        c2da_mem[floor_1 + 56] = uint8(c2da_fresh124)
        c2da_mem[floor_1 + 57] = uint8(c2da_fresh124 >> 0x8)
        c2da_mem[floor_1 + 58] = uint8(c2da_fresh124 >> 0x10)
        c2da_mem[floor_1 + 59] = uint8(c2da_fresh124 >> 0x18)
        let c2da_fresh125 : int = int(uint(c2da_mem[floor_1 + 32]) | uint(c2da_mem[floor_1 + 33]) << 0x8 | uint(c2da_mem[floor_1 + 34]) << 0x10 | uint(c2da_mem[floor_1 + 35]) << 0x18)
        let c2da_fresh126 : int = int(uint(c2da_mem[c2da_fresh125]) | uint(c2da_mem[c2da_fresh125 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh125 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh125 + 3]) << 0x18) + 512 * (1 << 16)
        let c2da_fresh127 : uint = uint(c2da_fresh126)
        c2da_mem[floor_1 + 52] = uint8(c2da_fresh127)
        c2da_mem[floor_1 + 53] = uint8(c2da_fresh127 >> 0x8)
        c2da_mem[floor_1 + 54] = uint8(c2da_fresh127 >> 0x10)
        c2da_mem[floor_1 + 55] = uint8(c2da_fresh127 >> 0x18)
        continue
        label 8:
        let c2da_fresh128 : int = 1
        let c2da_fresh129 : uint = uint(c2da_fresh128)
        c2da_mem[floor_1 + 40] = uint8(c2da_fresh129)
        c2da_mem[floor_1 + 41] = uint8(c2da_fresh129 >> 0x8)
        c2da_mem[floor_1 + 42] = uint8(c2da_fresh129 >> 0x10)
        c2da_mem[floor_1 + 43] = uint8(c2da_fresh129 >> 0x18)
        let c2da_fresh130 : uint = uint(sec_0)
        c2da_mem[floor_1 + 32] = uint8(c2da_fresh130)
        c2da_mem[floor_1 + 33] = uint8(c2da_fresh130 >> 0x8)
        c2da_mem[floor_1 + 34] = uint8(c2da_fresh130 >> 0x10)
        c2da_mem[floor_1 + 35] = uint8(c2da_fresh130 >> 0x18)
        c2da_mem[floor_1 + 36] = 0u8
        c2da_mem[floor_1 + 37] = 0u8
        c2da_mem[floor_1 + 38] = 0u8
        c2da_mem[floor_1 + 39] = 0u8
        let c2da_fresh131 : int = 1 << 16
        let c2da_fresh132 : uint = uint(c2da_fresh131)
        c2da_mem[floor_1 + 56] = uint8(c2da_fresh132)
        c2da_mem[floor_1 + 57] = uint8(c2da_fresh132 >> 0x8)
        c2da_mem[floor_1 + 58] = uint8(c2da_fresh132 >> 0x10)
        c2da_mem[floor_1 + 59] = uint8(c2da_fresh132 >> 0x18)
        let c2da_fresh133 : int = int(uint(c2da_mem[floor_1 + 32]) | uint(c2da_mem[floor_1 + 33]) << 0x8 | uint(c2da_mem[floor_1 + 34]) << 0x10 | uint(c2da_mem[floor_1 + 35]) << 0x18)
        let c2da_fresh134 : int = int(uint(c2da_mem[c2da_fresh133]) | uint(c2da_mem[c2da_fresh133 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh133 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh133 + 3]) << 0x18) + 24 * (1 << 16)
        let c2da_fresh135 : uint = uint(c2da_fresh134)
        c2da_mem[floor_1 + 52] = uint8(c2da_fresh135)
        c2da_mem[floor_1 + 53] = uint8(c2da_fresh135 >> 0x8)
        c2da_mem[floor_1 + 54] = uint8(c2da_fresh135 >> 0x10)
        c2da_mem[floor_1 + 55] = uint8(c2da_fresh135 >> 0x18)
        let c2da_fresh136 : int = int(uint(c2da_mem[line_0 + 56]) | uint(c2da_mem[line_0 + 57]) << 0x8 | uint(c2da_mem[line_0 + 58]) << 0x10 | uint(c2da_mem[line_0 + 59]) << 0x18) + 8
        let c2da_fresh137 : int16 = int16(uint(c2da_mem[c2da_fresh136]) | uint(c2da_mem[c2da_fresh136 + 1]) << 0x8)
        let c2da_fresh138 : uint = uint(c2da_fresh137)
        c2da_mem[sec_0 + 8] = uint8(c2da_fresh138)
        c2da_mem[sec_0 + 9] = uint8(c2da_fresh138 >> 0x8)
        let c2da_fresh139 : int = int(uint(c2da_mem[line_0 + 56]) | uint(c2da_mem[line_0 + 57]) << 0x8 | uint(c2da_mem[line_0 + 58]) << 0x10 | uint(c2da_mem[line_0 + 59]) << 0x18) + 14
        let c2da_fresh140 : int16 = int16(uint(c2da_mem[c2da_fresh139]) | uint(c2da_mem[c2da_fresh139 + 1]) << 0x8)
        let c2da_fresh141 : uint = uint(c2da_fresh140)
        c2da_mem[sec_0 + 14] = uint8(c2da_fresh141)
        c2da_mem[sec_0 + 15] = uint8(c2da_fresh141 >> 0x8)
        continue
        label 5:
        minsize = 2147483647
        let c2da_fresh142 : int = 1
        let c2da_fresh143 : uint = uint(c2da_fresh142)
        c2da_mem[floor_1 + 40] = uint8(c2da_fresh143)
        c2da_mem[floor_1 + 41] = uint8(c2da_fresh143 >> 0x8)
        c2da_mem[floor_1 + 42] = uint8(c2da_fresh143 >> 0x10)
        c2da_mem[floor_1 + 43] = uint8(c2da_fresh143 >> 0x18)
        let c2da_fresh144 : uint = uint(sec_0)
        c2da_mem[floor_1 + 32] = uint8(c2da_fresh144)
        c2da_mem[floor_1 + 33] = uint8(c2da_fresh144 >> 0x8)
        c2da_mem[floor_1 + 34] = uint8(c2da_fresh144 >> 0x10)
        c2da_mem[floor_1 + 35] = uint8(c2da_fresh144 >> 0x18)
        c2da_mem[floor_1 + 36] = 0u8
        c2da_mem[floor_1 + 37] = 0u8
        c2da_mem[floor_1 + 38] = 0u8
        c2da_mem[floor_1 + 39] = 0u8
        let c2da_fresh145 : int = 1 << 16
        let c2da_fresh146 : uint = uint(c2da_fresh145)
        c2da_mem[floor_1 + 56] = uint8(c2da_fresh146)
        c2da_mem[floor_1 + 57] = uint8(c2da_fresh146 >> 0x8)
        c2da_mem[floor_1 + 58] = uint8(c2da_fresh146 >> 0x10)
        c2da_mem[floor_1 + 59] = uint8(c2da_fresh146 >> 0x18)
        i_0 = 0
        while (i_0 < int(uint(c2da_mem[sec_0 + 112]) | uint(c2da_mem[sec_0 + 113]) << 0x8 | uint(c2da_mem[sec_0 + 114]) << 0x10 | uint(c2da_mem[sec_0 + 115]) << 0x18)) {
            if (twoSided(secnum_0, i_0) != 0) {
                side = getSide(secnum_0, i_0, 0)
                if (int(int16(uint(c2da_mem[side + 10]) | uint(c2da_mem[side + 11]) << 0x8)) >= 0) {
                    let c2da_fresh147 : int = textureheight + int(int16(uint(c2da_mem[side + 10]) | uint(c2da_mem[side + 11]) << 0x8)) * 4
                    if (int(uint(c2da_mem[c2da_fresh147]) | uint(c2da_mem[c2da_fresh147 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh147 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh147 + 3]) << 0x18) < minsize) {
                        let c2da_fresh148 : int = textureheight + int(int16(uint(c2da_mem[side + 10]) | uint(c2da_mem[side + 11]) << 0x8)) * 4
                        minsize = int(uint(c2da_mem[c2da_fresh148]) | uint(c2da_mem[c2da_fresh148 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh148 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh148 + 3]) << 0x18)
                    }
                }
                side = getSide(secnum_0, i_0, 1)
                if (int(int16(uint(c2da_mem[side + 10]) | uint(c2da_mem[side + 11]) << 0x8)) >= 0) {
                    let c2da_fresh149 : int = textureheight + int(int16(uint(c2da_mem[side + 10]) | uint(c2da_mem[side + 11]) << 0x8)) * 4
                    if (int(uint(c2da_mem[c2da_fresh149]) | uint(c2da_mem[c2da_fresh149 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh149 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh149 + 3]) << 0x18) < minsize) {
                        let c2da_fresh150 : int = textureheight + int(int16(uint(c2da_mem[side + 10]) | uint(c2da_mem[side + 11]) << 0x8)) * 4
                        minsize = int(uint(c2da_mem[c2da_fresh150]) | uint(c2da_mem[c2da_fresh150 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh150 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh150 + 3]) << 0x18)
                    }
                }
            }
            i_0++
        }
        let c2da_fresh151 : int = int(uint(c2da_mem[floor_1 + 32]) | uint(c2da_mem[floor_1 + 33]) << 0x8 | uint(c2da_mem[floor_1 + 34]) << 0x10 | uint(c2da_mem[floor_1 + 35]) << 0x18)
        let c2da_fresh152 : int = int(uint(c2da_mem[c2da_fresh151]) | uint(c2da_mem[c2da_fresh151 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh151 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh151 + 3]) << 0x18) + minsize
        let c2da_fresh153 : uint = uint(c2da_fresh152)
        c2da_mem[floor_1 + 52] = uint8(c2da_fresh153)
        c2da_mem[floor_1 + 53] = uint8(c2da_fresh153 >> 0x8)
        c2da_mem[floor_1 + 54] = uint8(c2da_fresh153 >> 0x10)
        c2da_mem[floor_1 + 55] = uint8(c2da_fresh153 >> 0x18)
        continue
        label 6:
        let c2da_fresh154 : int = -1
        let c2da_fresh155 : uint = uint(c2da_fresh154)
        c2da_mem[floor_1 + 40] = uint8(c2da_fresh155)
        c2da_mem[floor_1 + 41] = uint8(c2da_fresh155 >> 0x8)
        c2da_mem[floor_1 + 42] = uint8(c2da_fresh155 >> 0x10)
        c2da_mem[floor_1 + 43] = uint8(c2da_fresh155 >> 0x18)
        let c2da_fresh156 : uint = uint(sec_0)
        c2da_mem[floor_1 + 32] = uint8(c2da_fresh156)
        c2da_mem[floor_1 + 33] = uint8(c2da_fresh156 >> 0x8)
        c2da_mem[floor_1 + 34] = uint8(c2da_fresh156 >> 0x10)
        c2da_mem[floor_1 + 35] = uint8(c2da_fresh156 >> 0x18)
        c2da_mem[floor_1 + 36] = 0u8
        c2da_mem[floor_1 + 37] = 0u8
        c2da_mem[floor_1 + 38] = 0u8
        c2da_mem[floor_1 + 39] = 0u8
        let c2da_fresh157 : int = 1 << 16
        let c2da_fresh158 : uint = uint(c2da_fresh157)
        c2da_mem[floor_1 + 56] = uint8(c2da_fresh158)
        c2da_mem[floor_1 + 57] = uint8(c2da_fresh158 >> 0x8)
        c2da_mem[floor_1 + 58] = uint8(c2da_fresh158 >> 0x10)
        c2da_mem[floor_1 + 59] = uint8(c2da_fresh158 >> 0x18)
        let c2da_fresh159 : int = P_FindLowestFloorSurrounding(sec_0)
        let c2da_fresh160 : uint = uint(c2da_fresh159)
        c2da_mem[floor_1 + 52] = uint8(c2da_fresh160)
        c2da_mem[floor_1 + 53] = uint8(c2da_fresh160 >> 0x8)
        c2da_mem[floor_1 + 54] = uint8(c2da_fresh160 >> 0x10)
        c2da_mem[floor_1 + 55] = uint8(c2da_fresh160 >> 0x18)
        let c2da_fresh161 : int16 = int16(uint(c2da_mem[sec_0 + 8]) | uint(c2da_mem[sec_0 + 9]) << 0x8)
        let c2da_fresh162 : uint = uint(c2da_fresh161)
        c2da_mem[floor_1 + 48] = uint8(c2da_fresh162)
        c2da_mem[floor_1 + 49] = uint8(c2da_fresh162 >> 0x8)
        i_0 = 0
        while (i_0 < int(uint(c2da_mem[sec_0 + 112]) | uint(c2da_mem[sec_0 + 113]) << 0x8 | uint(c2da_mem[sec_0 + 114]) << 0x10 | uint(c2da_mem[sec_0 + 115]) << 0x18)) {
            if (twoSided(secnum_0, i_0) != 0) {
                let c2da_fresh163 : int = getSide(secnum_0, i_0, 0) + 16
                if (int64((int(uint(c2da_mem[c2da_fresh163]) | uint(c2da_mem[c2da_fresh163 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh163 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh163 + 3]) << 0x18) - sectors) / 128) == int64(secnum_0)) {
                    sec_0 = getSector(secnum_0, i_0, 1)
                    if (int(uint(c2da_mem[sec_0]) | uint(c2da_mem[sec_0 + 1]) << 0x8 | uint(c2da_mem[sec_0 + 2]) << 0x10 | uint(c2da_mem[sec_0 + 3]) << 0x18) == int(uint(c2da_mem[floor_1 + 52]) | uint(c2da_mem[floor_1 + 53]) << 0x8 | uint(c2da_mem[floor_1 + 54]) << 0x10 | uint(c2da_mem[floor_1 + 55]) << 0x18)) {
                        let c2da_fresh164 : int16 = int16(uint(c2da_mem[sec_0 + 8]) | uint(c2da_mem[sec_0 + 9]) << 0x8)
                        let c2da_fresh165 : uint = uint(c2da_fresh164)
                        c2da_mem[floor_1 + 48] = uint8(c2da_fresh165)
                        c2da_mem[floor_1 + 49] = uint8(c2da_fresh165 >> 0x8)
                        let c2da_fresh166 : int = int(int16(uint(c2da_mem[sec_0 + 14]) | uint(c2da_mem[sec_0 + 15]) << 0x8))
                        let c2da_fresh167 : uint = uint(c2da_fresh166)
                        c2da_mem[floor_1 + 44] = uint8(c2da_fresh167)
                        c2da_mem[floor_1 + 45] = uint8(c2da_fresh167 >> 0x8)
                        c2da_mem[floor_1 + 46] = uint8(c2da_fresh167 >> 0x10)
                        c2da_mem[floor_1 + 47] = uint8(c2da_fresh167 >> 0x18)
                        break
                    }
                } else {
                    sec_0 = getSector(secnum_0, i_0, 0)
                    if (int(uint(c2da_mem[sec_0]) | uint(c2da_mem[sec_0 + 1]) << 0x8 | uint(c2da_mem[sec_0 + 2]) << 0x10 | uint(c2da_mem[sec_0 + 3]) << 0x18) == int(uint(c2da_mem[floor_1 + 52]) | uint(c2da_mem[floor_1 + 53]) << 0x8 | uint(c2da_mem[floor_1 + 54]) << 0x10 | uint(c2da_mem[floor_1 + 55]) << 0x18)) {
                        let c2da_fresh168 : int16 = int16(uint(c2da_mem[sec_0 + 8]) | uint(c2da_mem[sec_0 + 9]) << 0x8)
                        let c2da_fresh169 : uint = uint(c2da_fresh168)
                        c2da_mem[floor_1 + 48] = uint8(c2da_fresh169)
                        c2da_mem[floor_1 + 49] = uint8(c2da_fresh169 >> 0x8)
                        let c2da_fresh170 : int = int(int16(uint(c2da_mem[sec_0 + 14]) | uint(c2da_mem[sec_0 + 15]) << 0x8))
                        let c2da_fresh171 : uint = uint(c2da_fresh170)
                        c2da_mem[floor_1 + 44] = uint8(c2da_fresh171)
                        c2da_mem[floor_1 + 45] = uint8(c2da_fresh171 >> 0x8)
                        c2da_mem[floor_1 + 46] = uint8(c2da_fresh171 >> 0x10)
                        c2da_mem[floor_1 + 47] = uint8(c2da_fresh171 >> 0x18)
                        break
                    }
                }
            }
            i_0++
        }
    }
    return rtn_0
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_p_floor() {
    if (length(c2da_fn_table5) < 129) {
        resize(c2da_fn_table5, 129)
    }
    c2da_fn_table5[128] = @@T_MoveFloor
}

[init]
def private c2da_lin_relink_init_p_floor() {
    c2da_relink_p_floor()
}
