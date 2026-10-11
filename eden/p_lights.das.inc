[export, sideeffects]
def P_SpawnFireFlicker(var sector : int) {
    var flick : int
    let c2da_fresh0 : int16 = int16(0)
    let c2da_fresh1 : uint = uint(c2da_fresh0)
    c2da_mem[sector + 14] = uint8(c2da_fresh1)
    c2da_mem[sector + 15] = uint8(c2da_fresh1 >> 0x8)
    flick = Z_Malloc(48, 6, 0)
    P_AddThinker(flick)
    let c2da_fresh2 : uint = 129u
    c2da_mem[flick + 16] = uint8(c2da_fresh2)
    c2da_mem[flick + 17] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[flick + 18] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[flick + 19] = uint8(c2da_fresh2 >> 0x18)
    c2da_mem[flick + 20] = 0u8
    c2da_mem[flick + 21] = 0u8
    c2da_mem[flick + 22] = 0u8
    c2da_mem[flick + 23] = 0u8
    let c2da_fresh3 : uint = uint(sector)
    c2da_mem[flick + 24] = uint8(c2da_fresh3)
    c2da_mem[flick + 25] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[flick + 26] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[flick + 27] = uint8(c2da_fresh3 >> 0x18)
    c2da_mem[flick + 28] = 0u8
    c2da_mem[flick + 29] = 0u8
    c2da_mem[flick + 30] = 0u8
    c2da_mem[flick + 31] = 0u8
    let c2da_fresh4 : int = int(int16(uint(c2da_mem[sector + 12]) | uint(c2da_mem[sector + 13]) << 0x8))
    let c2da_fresh5 : uint = uint(c2da_fresh4)
    c2da_mem[flick + 36] = uint8(c2da_fresh5)
    c2da_mem[flick + 37] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[flick + 38] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[flick + 39] = uint8(c2da_fresh5 >> 0x18)
    let c2da_fresh6 : int = P_FindMinSurroundingLight(sector, int(int16(uint(c2da_mem[sector + 12]) | uint(c2da_mem[sector + 13]) << 0x8))) + 16
    let c2da_fresh7 : uint = uint(c2da_fresh6)
    c2da_mem[flick + 40] = uint8(c2da_fresh7)
    c2da_mem[flick + 41] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[flick + 42] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[flick + 43] = uint8(c2da_fresh7 >> 0x18)
    let c2da_fresh8 : int = 4
    let c2da_fresh9 : uint = uint(c2da_fresh8)
    c2da_mem[flick + 32] = uint8(c2da_fresh9)
    c2da_mem[flick + 33] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[flick + 34] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[flick + 35] = uint8(c2da_fresh9 >> 0x18)
    return
}
[export, sideeffects]
def T_FireFlicker(var flick_0 : int) {
    var amount : int
    let c2da_fresh10 : int = int(uint(c2da_mem[flick_0 + 32]) | uint(c2da_mem[flick_0 + 33]) << 0x8 | uint(c2da_mem[flick_0 + 34]) << 0x10 | uint(c2da_mem[flick_0 + 35]) << 0x18)
    let c2da_fresh11 : int = c2da_fresh10 - 1
    let c2da_fresh12 : uint = uint(c2da_fresh11)
    c2da_mem[flick_0 + 32] = uint8(c2da_fresh12)
    c2da_mem[flick_0 + 33] = uint8(c2da_fresh12 >> 0x8)
    c2da_mem[flick_0 + 34] = uint8(c2da_fresh12 >> 0x10)
    c2da_mem[flick_0 + 35] = uint8(c2da_fresh12 >> 0x18)
    if (c2da_fresh11 != 0) {
        return
    }
    amount = (P_Random() & 3) * 16
    let c2da_fresh13 : int = int(uint(c2da_mem[flick_0 + 24]) | uint(c2da_mem[flick_0 + 25]) << 0x8 | uint(c2da_mem[flick_0 + 26]) << 0x10 | uint(c2da_mem[flick_0 + 27]) << 0x18) + 12
    if (int(int16(uint(c2da_mem[c2da_fresh13]) | uint(c2da_mem[c2da_fresh13 + 1]) << 0x8)) - amount < int(uint(c2da_mem[flick_0 + 40]) | uint(c2da_mem[flick_0 + 41]) << 0x8 | uint(c2da_mem[flick_0 + 42]) << 0x10 | uint(c2da_mem[flick_0 + 43]) << 0x18)) {
        let c2da_fresh14 : int = int(uint(c2da_mem[flick_0 + 24]) | uint(c2da_mem[flick_0 + 25]) << 0x8 | uint(c2da_mem[flick_0 + 26]) << 0x10 | uint(c2da_mem[flick_0 + 27]) << 0x18) + 12
        let c2da_fresh15 : int16 = int16(int(uint(c2da_mem[flick_0 + 40]) | uint(c2da_mem[flick_0 + 41]) << 0x8 | uint(c2da_mem[flick_0 + 42]) << 0x10 | uint(c2da_mem[flick_0 + 43]) << 0x18))
        let c2da_fresh16 : uint = uint(c2da_fresh15)
        c2da_mem[c2da_fresh14] = uint8(c2da_fresh16)
        c2da_mem[c2da_fresh14 + 1] = uint8(c2da_fresh16 >> 0x8)
    } else {
        let c2da_fresh17 : int = int(uint(c2da_mem[flick_0 + 24]) | uint(c2da_mem[flick_0 + 25]) << 0x8 | uint(c2da_mem[flick_0 + 26]) << 0x10 | uint(c2da_mem[flick_0 + 27]) << 0x18) + 12
        let c2da_fresh18 : int16 = int16(int(uint(c2da_mem[flick_0 + 36]) | uint(c2da_mem[flick_0 + 37]) << 0x8 | uint(c2da_mem[flick_0 + 38]) << 0x10 | uint(c2da_mem[flick_0 + 39]) << 0x18) - amount)
        let c2da_fresh19 : uint = uint(c2da_fresh18)
        c2da_mem[c2da_fresh17] = uint8(c2da_fresh19)
        c2da_mem[c2da_fresh17 + 1] = uint8(c2da_fresh19 >> 0x8)
    }
    let c2da_fresh20 : int = 4
    let c2da_fresh21 : uint = uint(c2da_fresh20)
    c2da_mem[flick_0 + 32] = uint8(c2da_fresh21)
    c2da_mem[flick_0 + 33] = uint8(c2da_fresh21 >> 0x8)
    c2da_mem[flick_0 + 34] = uint8(c2da_fresh21 >> 0x10)
    c2da_mem[flick_0 + 35] = uint8(c2da_fresh21 >> 0x18)
    return
}
[export, sideeffects]
def T_LightFlash(var flash : int) {
    let c2da_fresh22 : int = int(uint(c2da_mem[flash + 32]) | uint(c2da_mem[flash + 33]) << 0x8 | uint(c2da_mem[flash + 34]) << 0x10 | uint(c2da_mem[flash + 35]) << 0x18)
    let c2da_fresh23 : int = c2da_fresh22 - 1
    let c2da_fresh24 : uint = uint(c2da_fresh23)
    c2da_mem[flash + 32] = uint8(c2da_fresh24)
    c2da_mem[flash + 33] = uint8(c2da_fresh24 >> 0x8)
    c2da_mem[flash + 34] = uint8(c2da_fresh24 >> 0x10)
    c2da_mem[flash + 35] = uint8(c2da_fresh24 >> 0x18)
    if (c2da_fresh23 != 0) {
        return
    }
    let c2da_fresh25 : int = int(uint(c2da_mem[flash + 24]) | uint(c2da_mem[flash + 25]) << 0x8 | uint(c2da_mem[flash + 26]) << 0x10 | uint(c2da_mem[flash + 27]) << 0x18) + 12
    if (int(int16(uint(c2da_mem[c2da_fresh25]) | uint(c2da_mem[c2da_fresh25 + 1]) << 0x8)) == int(uint(c2da_mem[flash + 36]) | uint(c2da_mem[flash + 37]) << 0x8 | uint(c2da_mem[flash + 38]) << 0x10 | uint(c2da_mem[flash + 39]) << 0x18)) {
        let c2da_fresh26 : int = int(uint(c2da_mem[flash + 24]) | uint(c2da_mem[flash + 25]) << 0x8 | uint(c2da_mem[flash + 26]) << 0x10 | uint(c2da_mem[flash + 27]) << 0x18) + 12
        let c2da_fresh27 : int16 = int16(int(uint(c2da_mem[flash + 40]) | uint(c2da_mem[flash + 41]) << 0x8 | uint(c2da_mem[flash + 42]) << 0x10 | uint(c2da_mem[flash + 43]) << 0x18))
        let c2da_fresh28 : uint = uint(c2da_fresh27)
        c2da_mem[c2da_fresh26] = uint8(c2da_fresh28)
        c2da_mem[c2da_fresh26 + 1] = uint8(c2da_fresh28 >> 0x8)
        let c2da_fresh29 : int = (P_Random() & int(uint(c2da_mem[flash + 48]) | uint(c2da_mem[flash + 49]) << 0x8 | uint(c2da_mem[flash + 50]) << 0x10 | uint(c2da_mem[flash + 51]) << 0x18)) + 1
        let c2da_fresh30 : uint = uint(c2da_fresh29)
        c2da_mem[flash + 32] = uint8(c2da_fresh30)
        c2da_mem[flash + 33] = uint8(c2da_fresh30 >> 0x8)
        c2da_mem[flash + 34] = uint8(c2da_fresh30 >> 0x10)
        c2da_mem[flash + 35] = uint8(c2da_fresh30 >> 0x18)
    } else {
        let c2da_fresh31 : int = int(uint(c2da_mem[flash + 24]) | uint(c2da_mem[flash + 25]) << 0x8 | uint(c2da_mem[flash + 26]) << 0x10 | uint(c2da_mem[flash + 27]) << 0x18) + 12
        let c2da_fresh32 : int16 = int16(int(uint(c2da_mem[flash + 36]) | uint(c2da_mem[flash + 37]) << 0x8 | uint(c2da_mem[flash + 38]) << 0x10 | uint(c2da_mem[flash + 39]) << 0x18))
        let c2da_fresh33 : uint = uint(c2da_fresh32)
        c2da_mem[c2da_fresh31] = uint8(c2da_fresh33)
        c2da_mem[c2da_fresh31 + 1] = uint8(c2da_fresh33 >> 0x8)
        let c2da_fresh34 : int = (P_Random() & int(uint(c2da_mem[flash + 44]) | uint(c2da_mem[flash + 45]) << 0x8 | uint(c2da_mem[flash + 46]) << 0x10 | uint(c2da_mem[flash + 47]) << 0x18)) + 1
        let c2da_fresh35 : uint = uint(c2da_fresh34)
        c2da_mem[flash + 32] = uint8(c2da_fresh35)
        c2da_mem[flash + 33] = uint8(c2da_fresh35 >> 0x8)
        c2da_mem[flash + 34] = uint8(c2da_fresh35 >> 0x10)
        c2da_mem[flash + 35] = uint8(c2da_fresh35 >> 0x18)
    }
    return
}
[export, sideeffects]
def P_SpawnLightFlash(var sector_0 : int) {
    var flash_0 : int
    let c2da_fresh36 : int16 = int16(0)
    let c2da_fresh37 : uint = uint(c2da_fresh36)
    c2da_mem[sector_0 + 14] = uint8(c2da_fresh37)
    c2da_mem[sector_0 + 15] = uint8(c2da_fresh37 >> 0x8)
    flash_0 = Z_Malloc(56, 6, 0)
    P_AddThinker(flash_0)
    let c2da_fresh38 : uint = 130u
    c2da_mem[flash_0 + 16] = uint8(c2da_fresh38)
    c2da_mem[flash_0 + 17] = uint8(c2da_fresh38 >> 0x8)
    c2da_mem[flash_0 + 18] = uint8(c2da_fresh38 >> 0x10)
    c2da_mem[flash_0 + 19] = uint8(c2da_fresh38 >> 0x18)
    c2da_mem[flash_0 + 20] = 0u8
    c2da_mem[flash_0 + 21] = 0u8
    c2da_mem[flash_0 + 22] = 0u8
    c2da_mem[flash_0 + 23] = 0u8
    let c2da_fresh39 : uint = uint(sector_0)
    c2da_mem[flash_0 + 24] = uint8(c2da_fresh39)
    c2da_mem[flash_0 + 25] = uint8(c2da_fresh39 >> 0x8)
    c2da_mem[flash_0 + 26] = uint8(c2da_fresh39 >> 0x10)
    c2da_mem[flash_0 + 27] = uint8(c2da_fresh39 >> 0x18)
    c2da_mem[flash_0 + 28] = 0u8
    c2da_mem[flash_0 + 29] = 0u8
    c2da_mem[flash_0 + 30] = 0u8
    c2da_mem[flash_0 + 31] = 0u8
    let c2da_fresh40 : int = int(int16(uint(c2da_mem[sector_0 + 12]) | uint(c2da_mem[sector_0 + 13]) << 0x8))
    let c2da_fresh41 : uint = uint(c2da_fresh40)
    c2da_mem[flash_0 + 36] = uint8(c2da_fresh41)
    c2da_mem[flash_0 + 37] = uint8(c2da_fresh41 >> 0x8)
    c2da_mem[flash_0 + 38] = uint8(c2da_fresh41 >> 0x10)
    c2da_mem[flash_0 + 39] = uint8(c2da_fresh41 >> 0x18)
    let c2da_fresh42 : int = P_FindMinSurroundingLight(sector_0, int(int16(uint(c2da_mem[sector_0 + 12]) | uint(c2da_mem[sector_0 + 13]) << 0x8)))
    let c2da_fresh43 : uint = uint(c2da_fresh42)
    c2da_mem[flash_0 + 40] = uint8(c2da_fresh43)
    c2da_mem[flash_0 + 41] = uint8(c2da_fresh43 >> 0x8)
    c2da_mem[flash_0 + 42] = uint8(c2da_fresh43 >> 0x10)
    c2da_mem[flash_0 + 43] = uint8(c2da_fresh43 >> 0x18)
    let c2da_fresh44 : int = 64
    let c2da_fresh45 : uint = uint(c2da_fresh44)
    c2da_mem[flash_0 + 44] = uint8(c2da_fresh45)
    c2da_mem[flash_0 + 45] = uint8(c2da_fresh45 >> 0x8)
    c2da_mem[flash_0 + 46] = uint8(c2da_fresh45 >> 0x10)
    c2da_mem[flash_0 + 47] = uint8(c2da_fresh45 >> 0x18)
    let c2da_fresh46 : int = 7
    let c2da_fresh47 : uint = uint(c2da_fresh46)
    c2da_mem[flash_0 + 48] = uint8(c2da_fresh47)
    c2da_mem[flash_0 + 49] = uint8(c2da_fresh47 >> 0x8)
    c2da_mem[flash_0 + 50] = uint8(c2da_fresh47 >> 0x10)
    c2da_mem[flash_0 + 51] = uint8(c2da_fresh47 >> 0x18)
    let c2da_fresh48 : int = (P_Random() & int(uint(c2da_mem[flash_0 + 44]) | uint(c2da_mem[flash_0 + 45]) << 0x8 | uint(c2da_mem[flash_0 + 46]) << 0x10 | uint(c2da_mem[flash_0 + 47]) << 0x18)) + 1
    let c2da_fresh49 : uint = uint(c2da_fresh48)
    c2da_mem[flash_0 + 32] = uint8(c2da_fresh49)
    c2da_mem[flash_0 + 33] = uint8(c2da_fresh49 >> 0x8)
    c2da_mem[flash_0 + 34] = uint8(c2da_fresh49 >> 0x10)
    c2da_mem[flash_0 + 35] = uint8(c2da_fresh49 >> 0x18)
    return
}
[export, sideeffects]
def T_StrobeFlash(var flash_1 : int) {
    let c2da_fresh50 : int = int(uint(c2da_mem[flash_1 + 32]) | uint(c2da_mem[flash_1 + 33]) << 0x8 | uint(c2da_mem[flash_1 + 34]) << 0x10 | uint(c2da_mem[flash_1 + 35]) << 0x18)
    let c2da_fresh51 : int = c2da_fresh50 - 1
    let c2da_fresh52 : uint = uint(c2da_fresh51)
    c2da_mem[flash_1 + 32] = uint8(c2da_fresh52)
    c2da_mem[flash_1 + 33] = uint8(c2da_fresh52 >> 0x8)
    c2da_mem[flash_1 + 34] = uint8(c2da_fresh52 >> 0x10)
    c2da_mem[flash_1 + 35] = uint8(c2da_fresh52 >> 0x18)
    if (c2da_fresh51 != 0) {
        return
    }
    let c2da_fresh53 : int = int(uint(c2da_mem[flash_1 + 24]) | uint(c2da_mem[flash_1 + 25]) << 0x8 | uint(c2da_mem[flash_1 + 26]) << 0x10 | uint(c2da_mem[flash_1 + 27]) << 0x18) + 12
    if (int(int16(uint(c2da_mem[c2da_fresh53]) | uint(c2da_mem[c2da_fresh53 + 1]) << 0x8)) == int(uint(c2da_mem[flash_1 + 36]) | uint(c2da_mem[flash_1 + 37]) << 0x8 | uint(c2da_mem[flash_1 + 38]) << 0x10 | uint(c2da_mem[flash_1 + 39]) << 0x18)) {
        let c2da_fresh54 : int = int(uint(c2da_mem[flash_1 + 24]) | uint(c2da_mem[flash_1 + 25]) << 0x8 | uint(c2da_mem[flash_1 + 26]) << 0x10 | uint(c2da_mem[flash_1 + 27]) << 0x18) + 12
        let c2da_fresh55 : int16 = int16(int(uint(c2da_mem[flash_1 + 40]) | uint(c2da_mem[flash_1 + 41]) << 0x8 | uint(c2da_mem[flash_1 + 42]) << 0x10 | uint(c2da_mem[flash_1 + 43]) << 0x18))
        let c2da_fresh56 : uint = uint(c2da_fresh55)
        c2da_mem[c2da_fresh54] = uint8(c2da_fresh56)
        c2da_mem[c2da_fresh54 + 1] = uint8(c2da_fresh56 >> 0x8)
        let c2da_fresh57 : int = int(uint(c2da_mem[flash_1 + 48]) | uint(c2da_mem[flash_1 + 49]) << 0x8 | uint(c2da_mem[flash_1 + 50]) << 0x10 | uint(c2da_mem[flash_1 + 51]) << 0x18)
        let c2da_fresh58 : uint = uint(c2da_fresh57)
        c2da_mem[flash_1 + 32] = uint8(c2da_fresh58)
        c2da_mem[flash_1 + 33] = uint8(c2da_fresh58 >> 0x8)
        c2da_mem[flash_1 + 34] = uint8(c2da_fresh58 >> 0x10)
        c2da_mem[flash_1 + 35] = uint8(c2da_fresh58 >> 0x18)
    } else {
        let c2da_fresh59 : int = int(uint(c2da_mem[flash_1 + 24]) | uint(c2da_mem[flash_1 + 25]) << 0x8 | uint(c2da_mem[flash_1 + 26]) << 0x10 | uint(c2da_mem[flash_1 + 27]) << 0x18) + 12
        let c2da_fresh60 : int16 = int16(int(uint(c2da_mem[flash_1 + 36]) | uint(c2da_mem[flash_1 + 37]) << 0x8 | uint(c2da_mem[flash_1 + 38]) << 0x10 | uint(c2da_mem[flash_1 + 39]) << 0x18))
        let c2da_fresh61 : uint = uint(c2da_fresh60)
        c2da_mem[c2da_fresh59] = uint8(c2da_fresh61)
        c2da_mem[c2da_fresh59 + 1] = uint8(c2da_fresh61 >> 0x8)
        let c2da_fresh62 : int = int(uint(c2da_mem[flash_1 + 44]) | uint(c2da_mem[flash_1 + 45]) << 0x8 | uint(c2da_mem[flash_1 + 46]) << 0x10 | uint(c2da_mem[flash_1 + 47]) << 0x18)
        let c2da_fresh63 : uint = uint(c2da_fresh62)
        c2da_mem[flash_1 + 32] = uint8(c2da_fresh63)
        c2da_mem[flash_1 + 33] = uint8(c2da_fresh63 >> 0x8)
        c2da_mem[flash_1 + 34] = uint8(c2da_fresh63 >> 0x10)
        c2da_mem[flash_1 + 35] = uint8(c2da_fresh63 >> 0x18)
    }
    return
}
[export, sideeffects]
def P_SpawnStrobeFlash(var sector_1 : int; var fastOrSlow : int; var inSync : int) {
    var flash_2 : int = Z_Malloc(56, 6, 0)
    P_AddThinker(flash_2)
    let c2da_fresh64 : uint = uint(sector_1)
    c2da_mem[flash_2 + 24] = uint8(c2da_fresh64)
    c2da_mem[flash_2 + 25] = uint8(c2da_fresh64 >> 0x8)
    c2da_mem[flash_2 + 26] = uint8(c2da_fresh64 >> 0x10)
    c2da_mem[flash_2 + 27] = uint8(c2da_fresh64 >> 0x18)
    c2da_mem[flash_2 + 28] = 0u8
    c2da_mem[flash_2 + 29] = 0u8
    c2da_mem[flash_2 + 30] = 0u8
    c2da_mem[flash_2 + 31] = 0u8
    let c2da_fresh65 : uint = uint(fastOrSlow)
    c2da_mem[flash_2 + 44] = uint8(c2da_fresh65)
    c2da_mem[flash_2 + 45] = uint8(c2da_fresh65 >> 0x8)
    c2da_mem[flash_2 + 46] = uint8(c2da_fresh65 >> 0x10)
    c2da_mem[flash_2 + 47] = uint8(c2da_fresh65 >> 0x18)
    let c2da_fresh66 : int = 5
    let c2da_fresh67 : uint = uint(c2da_fresh66)
    c2da_mem[flash_2 + 48] = uint8(c2da_fresh67)
    c2da_mem[flash_2 + 49] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[flash_2 + 50] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[flash_2 + 51] = uint8(c2da_fresh67 >> 0x18)
    let c2da_fresh68 : uint = 131u
    c2da_mem[flash_2 + 16] = uint8(c2da_fresh68)
    c2da_mem[flash_2 + 17] = uint8(c2da_fresh68 >> 0x8)
    c2da_mem[flash_2 + 18] = uint8(c2da_fresh68 >> 0x10)
    c2da_mem[flash_2 + 19] = uint8(c2da_fresh68 >> 0x18)
    c2da_mem[flash_2 + 20] = 0u8
    c2da_mem[flash_2 + 21] = 0u8
    c2da_mem[flash_2 + 22] = 0u8
    c2da_mem[flash_2 + 23] = 0u8
    let c2da_fresh69 : int = int(int16(uint(c2da_mem[sector_1 + 12]) | uint(c2da_mem[sector_1 + 13]) << 0x8))
    let c2da_fresh70 : uint = uint(c2da_fresh69)
    c2da_mem[flash_2 + 40] = uint8(c2da_fresh70)
    c2da_mem[flash_2 + 41] = uint8(c2da_fresh70 >> 0x8)
    c2da_mem[flash_2 + 42] = uint8(c2da_fresh70 >> 0x10)
    c2da_mem[flash_2 + 43] = uint8(c2da_fresh70 >> 0x18)
    let c2da_fresh71 : int = P_FindMinSurroundingLight(sector_1, int(int16(uint(c2da_mem[sector_1 + 12]) | uint(c2da_mem[sector_1 + 13]) << 0x8)))
    let c2da_fresh72 : uint = uint(c2da_fresh71)
    c2da_mem[flash_2 + 36] = uint8(c2da_fresh72)
    c2da_mem[flash_2 + 37] = uint8(c2da_fresh72 >> 0x8)
    c2da_mem[flash_2 + 38] = uint8(c2da_fresh72 >> 0x10)
    c2da_mem[flash_2 + 39] = uint8(c2da_fresh72 >> 0x18)
    if (int(uint(c2da_mem[flash_2 + 36]) | uint(c2da_mem[flash_2 + 37]) << 0x8 | uint(c2da_mem[flash_2 + 38]) << 0x10 | uint(c2da_mem[flash_2 + 39]) << 0x18) == int(uint(c2da_mem[flash_2 + 40]) | uint(c2da_mem[flash_2 + 41]) << 0x8 | uint(c2da_mem[flash_2 + 42]) << 0x10 | uint(c2da_mem[flash_2 + 43]) << 0x18)) {
        let c2da_fresh73 : int = 0
        let c2da_fresh74 : uint = uint(c2da_fresh73)
        c2da_mem[flash_2 + 36] = uint8(c2da_fresh74)
        c2da_mem[flash_2 + 37] = uint8(c2da_fresh74 >> 0x8)
        c2da_mem[flash_2 + 38] = uint8(c2da_fresh74 >> 0x10)
        c2da_mem[flash_2 + 39] = uint8(c2da_fresh74 >> 0x18)
    }
    let c2da_fresh75 : int16 = int16(0)
    let c2da_fresh76 : uint = uint(c2da_fresh75)
    c2da_mem[sector_1 + 14] = uint8(c2da_fresh76)
    c2da_mem[sector_1 + 15] = uint8(c2da_fresh76 >> 0x8)
    if (inSync == 0) {
        let c2da_fresh77 : int = (P_Random() & 7) + 1
        let c2da_fresh78 : uint = uint(c2da_fresh77)
        c2da_mem[flash_2 + 32] = uint8(c2da_fresh78)
        c2da_mem[flash_2 + 33] = uint8(c2da_fresh78 >> 0x8)
        c2da_mem[flash_2 + 34] = uint8(c2da_fresh78 >> 0x10)
        c2da_mem[flash_2 + 35] = uint8(c2da_fresh78 >> 0x18)
    } else {
        let c2da_fresh79 : int = 1
        let c2da_fresh80 : uint = uint(c2da_fresh79)
        c2da_mem[flash_2 + 32] = uint8(c2da_fresh80)
        c2da_mem[flash_2 + 33] = uint8(c2da_fresh80 >> 0x8)
        c2da_mem[flash_2 + 34] = uint8(c2da_fresh80 >> 0x10)
        c2da_mem[flash_2 + 35] = uint8(c2da_fresh80 >> 0x18)
    }
    return
}
[export, sideeffects]
def EV_StartLightStrobing(var line : int) {
    var secnum : int
    var sec : int
    secnum = -1
    while (true) {
        secnum = P_FindSectorFromLineTag(line, secnum)
        if (secnum < 0) {
            break
        }
        sec = sectors + secnum * 128
        if (int(uint(c2da_mem[sec + 104]) | uint(c2da_mem[sec + 105]) << 0x8 | uint(c2da_mem[sec + 106]) << 0x10 | uint(c2da_mem[sec + 107]) << 0x18) != 0) {
            continue
        }
        P_SpawnStrobeFlash(sec, 35, 0)
    }
    return
}
[export, sideeffects]
def EV_TurnTagLightsOff(var line_0 : int) {
    var i : int
    var j : int
    var min : int
    var sector_2 : int
    var tsec : int
    var templine : int
    sector_2 = sectors
    j = 0
    while (j < numsectors) {
        if (int(int16(uint(c2da_mem[sector_2 + 16]) | uint(c2da_mem[sector_2 + 17]) << 0x8)) == int(int16(uint(c2da_mem[line_0 + 28]) | uint(c2da_mem[line_0 + 29]) << 0x8))) {
            min = int(int16(uint(c2da_mem[sector_2 + 12]) | uint(c2da_mem[sector_2 + 13]) << 0x8))
            i = 0
            while (i < int(uint(c2da_mem[sector_2 + 112]) | uint(c2da_mem[sector_2 + 113]) << 0x8 | uint(c2da_mem[sector_2 + 114]) << 0x10 | uint(c2da_mem[sector_2 + 115]) << 0x18)) {
                let c2da_fresh81 : int = int(uint(c2da_mem[sector_2 + 120]) | uint(c2da_mem[sector_2 + 121]) << 0x8 | uint(c2da_mem[sector_2 + 122]) << 0x10 | uint(c2da_mem[sector_2 + 123]) << 0x18) + i * 8
                templine = int(uint(c2da_mem[c2da_fresh81]) | uint(c2da_mem[c2da_fresh81 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh81 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh81 + 3]) << 0x18)
                tsec = getNextSector(templine, sector_2)
                if (tsec == 0) {
                    i++
                    continue
                }
                if (int(int16(uint(c2da_mem[tsec + 12]) | uint(c2da_mem[tsec + 13]) << 0x8)) < min) {
                    min = int(int16(uint(c2da_mem[tsec + 12]) | uint(c2da_mem[tsec + 13]) << 0x8))
                }
                i++
            }
            let c2da_fresh82 : int16 = int16(min)
            let c2da_fresh83 : uint = uint(c2da_fresh82)
            c2da_mem[sector_2 + 12] = uint8(c2da_fresh83)
            c2da_mem[sector_2 + 13] = uint8(c2da_fresh83 >> 0x8)
        }
        j++
        sector_2 += 128
    }
    return
}
[export, sideeffects]
def EV_LightTurnOn(var line_1 : int; var bright : int) {
    var i_0 : int
    var j_0 : int
    var sector_3 : int
    var temp : int
    var templine_0 : int
    sector_3 = sectors
    i_0 = 0
    while (i_0 < numsectors) {
        if (int(int16(uint(c2da_mem[sector_3 + 16]) | uint(c2da_mem[sector_3 + 17]) << 0x8)) == int(int16(uint(c2da_mem[line_1 + 28]) | uint(c2da_mem[line_1 + 29]) << 0x8))) {
            if (bright == 0) {
                j_0 = 0
                while (j_0 < int(uint(c2da_mem[sector_3 + 112]) | uint(c2da_mem[sector_3 + 113]) << 0x8 | uint(c2da_mem[sector_3 + 114]) << 0x10 | uint(c2da_mem[sector_3 + 115]) << 0x18)) {
                    let c2da_fresh84 : int = int(uint(c2da_mem[sector_3 + 120]) | uint(c2da_mem[sector_3 + 121]) << 0x8 | uint(c2da_mem[sector_3 + 122]) << 0x10 | uint(c2da_mem[sector_3 + 123]) << 0x18) + j_0 * 8
                    templine_0 = int(uint(c2da_mem[c2da_fresh84]) | uint(c2da_mem[c2da_fresh84 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh84 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh84 + 3]) << 0x18)
                    temp = getNextSector(templine_0, sector_3)
                    if (temp == 0) {
                        j_0++
                        continue
                    }
                    if (int(int16(uint(c2da_mem[temp + 12]) | uint(c2da_mem[temp + 13]) << 0x8)) > bright) {
                        bright = int(int16(uint(c2da_mem[temp + 12]) | uint(c2da_mem[temp + 13]) << 0x8))
                    }
                    j_0++
                }
            }
            let c2da_fresh85 : int16 = int16(bright)
            let c2da_fresh86 : uint = uint(c2da_fresh85)
            c2da_mem[sector_3 + 12] = uint8(c2da_fresh86)
            c2da_mem[sector_3 + 13] = uint8(c2da_fresh86 >> 0x8)
        }
        i_0++
        sector_3 += 128
    }
    return
}
[export, sideeffects]
def T_Glow(var g : int) {
    let c2da_fresh87 : int = int(uint(c2da_mem[g + 40]) | uint(c2da_mem[g + 41]) << 0x8 | uint(c2da_mem[g + 42]) << 0x10 | uint(c2da_mem[g + 43]) << 0x18)
    if (c2da_fresh87 == -1) {
        let c2da_fresh88 : int = int(uint(c2da_mem[g + 24]) | uint(c2da_mem[g + 25]) << 0x8 | uint(c2da_mem[g + 26]) << 0x10 | uint(c2da_mem[g + 27]) << 0x18) + 12
        let c2da_fresh89 : int16 = int16(int(int16(uint(c2da_mem[c2da_fresh88]) | uint(c2da_mem[c2da_fresh88 + 1]) << 0x8)) - 8)
        let c2da_fresh90 : uint = uint(c2da_fresh89)
        c2da_mem[c2da_fresh88] = uint8(c2da_fresh90)
        c2da_mem[c2da_fresh88 + 1] = uint8(c2da_fresh90 >> 0x8)
        let c2da_fresh91 : int = int(uint(c2da_mem[g + 24]) | uint(c2da_mem[g + 25]) << 0x8 | uint(c2da_mem[g + 26]) << 0x10 | uint(c2da_mem[g + 27]) << 0x18) + 12
        if (int(int16(uint(c2da_mem[c2da_fresh91]) | uint(c2da_mem[c2da_fresh91 + 1]) << 0x8)) <= int(uint(c2da_mem[g + 32]) | uint(c2da_mem[g + 33]) << 0x8 | uint(c2da_mem[g + 34]) << 0x10 | uint(c2da_mem[g + 35]) << 0x18)) {
            let c2da_fresh92 : int = int(uint(c2da_mem[g + 24]) | uint(c2da_mem[g + 25]) << 0x8 | uint(c2da_mem[g + 26]) << 0x10 | uint(c2da_mem[g + 27]) << 0x18) + 12
            let c2da_fresh93 : int16 = int16(int(int16(uint(c2da_mem[c2da_fresh92]) | uint(c2da_mem[c2da_fresh92 + 1]) << 0x8)) + 8)
            let c2da_fresh94 : uint = uint(c2da_fresh93)
            c2da_mem[c2da_fresh92] = uint8(c2da_fresh94)
            c2da_mem[c2da_fresh92 + 1] = uint8(c2da_fresh94 >> 0x8)
            let c2da_fresh95 : int = 1
            let c2da_fresh96 : uint = uint(c2da_fresh95)
            c2da_mem[g + 40] = uint8(c2da_fresh96)
            c2da_mem[g + 41] = uint8(c2da_fresh96 >> 0x8)
            c2da_mem[g + 42] = uint8(c2da_fresh96 >> 0x10)
            c2da_mem[g + 43] = uint8(c2da_fresh96 >> 0x18)
        }
    } elif (c2da_fresh87 == 1) {
        let c2da_fresh97 : int = int(uint(c2da_mem[g + 24]) | uint(c2da_mem[g + 25]) << 0x8 | uint(c2da_mem[g + 26]) << 0x10 | uint(c2da_mem[g + 27]) << 0x18) + 12
        let c2da_fresh98 : int16 = int16(int(int16(uint(c2da_mem[c2da_fresh97]) | uint(c2da_mem[c2da_fresh97 + 1]) << 0x8)) + 8)
        let c2da_fresh99 : uint = uint(c2da_fresh98)
        c2da_mem[c2da_fresh97] = uint8(c2da_fresh99)
        c2da_mem[c2da_fresh97 + 1] = uint8(c2da_fresh99 >> 0x8)
        let c2da_fresh100 : int = int(uint(c2da_mem[g + 24]) | uint(c2da_mem[g + 25]) << 0x8 | uint(c2da_mem[g + 26]) << 0x10 | uint(c2da_mem[g + 27]) << 0x18) + 12
        if (int(int16(uint(c2da_mem[c2da_fresh100]) | uint(c2da_mem[c2da_fresh100 + 1]) << 0x8)) >= int(uint(c2da_mem[g + 36]) | uint(c2da_mem[g + 37]) << 0x8 | uint(c2da_mem[g + 38]) << 0x10 | uint(c2da_mem[g + 39]) << 0x18)) {
            let c2da_fresh101 : int = int(uint(c2da_mem[g + 24]) | uint(c2da_mem[g + 25]) << 0x8 | uint(c2da_mem[g + 26]) << 0x10 | uint(c2da_mem[g + 27]) << 0x18) + 12
            let c2da_fresh102 : int16 = int16(int(int16(uint(c2da_mem[c2da_fresh101]) | uint(c2da_mem[c2da_fresh101 + 1]) << 0x8)) - 8)
            let c2da_fresh103 : uint = uint(c2da_fresh102)
            c2da_mem[c2da_fresh101] = uint8(c2da_fresh103)
            c2da_mem[c2da_fresh101 + 1] = uint8(c2da_fresh103 >> 0x8)
            let c2da_fresh104 : int = -1
            let c2da_fresh105 : uint = uint(c2da_fresh104)
            c2da_mem[g + 40] = uint8(c2da_fresh105)
            c2da_mem[g + 41] = uint8(c2da_fresh105 >> 0x8)
            c2da_mem[g + 42] = uint8(c2da_fresh105 >> 0x10)
            c2da_mem[g + 43] = uint8(c2da_fresh105 >> 0x18)
        }
    }
    return
}
[export, sideeffects]
def P_SpawnGlowingLight(var sector_4 : int) {
    var g_0 : int = Z_Malloc(48, 6, 0)
    P_AddThinker(g_0)
    let c2da_fresh106 : uint = uint(sector_4)
    c2da_mem[g_0 + 24] = uint8(c2da_fresh106)
    c2da_mem[g_0 + 25] = uint8(c2da_fresh106 >> 0x8)
    c2da_mem[g_0 + 26] = uint8(c2da_fresh106 >> 0x10)
    c2da_mem[g_0 + 27] = uint8(c2da_fresh106 >> 0x18)
    c2da_mem[g_0 + 28] = 0u8
    c2da_mem[g_0 + 29] = 0u8
    c2da_mem[g_0 + 30] = 0u8
    c2da_mem[g_0 + 31] = 0u8
    let c2da_fresh107 : int = P_FindMinSurroundingLight(sector_4, int(int16(uint(c2da_mem[sector_4 + 12]) | uint(c2da_mem[sector_4 + 13]) << 0x8)))
    let c2da_fresh108 : uint = uint(c2da_fresh107)
    c2da_mem[g_0 + 32] = uint8(c2da_fresh108)
    c2da_mem[g_0 + 33] = uint8(c2da_fresh108 >> 0x8)
    c2da_mem[g_0 + 34] = uint8(c2da_fresh108 >> 0x10)
    c2da_mem[g_0 + 35] = uint8(c2da_fresh108 >> 0x18)
    let c2da_fresh109 : int = int(int16(uint(c2da_mem[sector_4 + 12]) | uint(c2da_mem[sector_4 + 13]) << 0x8))
    let c2da_fresh110 : uint = uint(c2da_fresh109)
    c2da_mem[g_0 + 36] = uint8(c2da_fresh110)
    c2da_mem[g_0 + 37] = uint8(c2da_fresh110 >> 0x8)
    c2da_mem[g_0 + 38] = uint8(c2da_fresh110 >> 0x10)
    c2da_mem[g_0 + 39] = uint8(c2da_fresh110 >> 0x18)
    let c2da_fresh111 : uint = 132u
    c2da_mem[g_0 + 16] = uint8(c2da_fresh111)
    c2da_mem[g_0 + 17] = uint8(c2da_fresh111 >> 0x8)
    c2da_mem[g_0 + 18] = uint8(c2da_fresh111 >> 0x10)
    c2da_mem[g_0 + 19] = uint8(c2da_fresh111 >> 0x18)
    c2da_mem[g_0 + 20] = 0u8
    c2da_mem[g_0 + 21] = 0u8
    c2da_mem[g_0 + 22] = 0u8
    c2da_mem[g_0 + 23] = 0u8
    let c2da_fresh112 : int = -1
    let c2da_fresh113 : uint = uint(c2da_fresh112)
    c2da_mem[g_0 + 40] = uint8(c2da_fresh113)
    c2da_mem[g_0 + 41] = uint8(c2da_fresh113 >> 0x8)
    c2da_mem[g_0 + 42] = uint8(c2da_fresh113 >> 0x10)
    c2da_mem[g_0 + 43] = uint8(c2da_fresh113 >> 0x18)
    let c2da_fresh114 : int16 = int16(0)
    let c2da_fresh115 : uint = uint(c2da_fresh114)
    c2da_mem[sector_4 + 14] = uint8(c2da_fresh115)
    c2da_mem[sector_4 + 15] = uint8(c2da_fresh115 >> 0x8)
    return
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_p_lights() {
    if (length(c2da_fn_table5) < 133) {
        resize(c2da_fn_table5, 133)
    }
    c2da_fn_table5[129] = @@T_FireFlicker
    c2da_fn_table5[130] = @@T_LightFlash
    c2da_fn_table5[131] = @@T_StrobeFlash
    c2da_fn_table5[132] = @@T_Glow
}

[init]
def private c2da_lin_relink_init_p_lights() {
    c2da_relink_p_lights()
}
