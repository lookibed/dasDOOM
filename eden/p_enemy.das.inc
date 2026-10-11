var private A_BrainSpit__easy : int = 0

[sideeffects]
def private c2da___bswap_16_7(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_7(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_7(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_7(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_7(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_7(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
[export, sideeffects]
def P_NoiseAlert(var target : int; var emmiter : int) {
    soundtarget = int(target)  // nolint:PERF020
    validcount = validcount + 1
    let c2da_fresh0 : int = int(uint(c2da_mem[emmiter + 88]) | uint(c2da_mem[emmiter + 89]) << 0x8 | uint(c2da_mem[emmiter + 90]) << 0x10 | uint(c2da_mem[emmiter + 91]) << 0x18)
    P_RecursiveSound(int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18), 0)
    return
}
[export, sideeffects]
def P_RecursiveSound(var sec : int; var soundblocks : int) {
    var i : int
    var check : int
    var other : int
    if (int(uint(c2da_mem[sec + 88]) | uint(c2da_mem[sec + 89]) << 0x8 | uint(c2da_mem[sec + 90]) << 0x10 | uint(c2da_mem[sec + 91]) << 0x18) == validcount && int(uint(c2da_mem[sec + 20]) | uint(c2da_mem[sec + 21]) << 0x8 | uint(c2da_mem[sec + 22]) << 0x10 | uint(c2da_mem[sec + 23]) << 0x18) <= soundblocks + 1) {
        return
    }
    let c2da_fresh1 : uint = uint(validcount)
    c2da_mem[sec + 88] = uint8(c2da_fresh1)
    c2da_mem[sec + 89] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[sec + 90] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[sec + 91] = uint8(c2da_fresh1 >> 0x18)
    let c2da_fresh2 : int = soundblocks + 1
    let c2da_fresh3 : uint = uint(c2da_fresh2)
    c2da_mem[sec + 20] = uint8(c2da_fresh3)
    c2da_mem[sec + 21] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[sec + 22] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[sec + 23] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : uint = uint(soundtarget)
    c2da_mem[sec + 24] = uint8(c2da_fresh4)
    c2da_mem[sec + 25] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[sec + 26] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[sec + 27] = uint8(c2da_fresh4 >> 0x18)
    c2da_mem[sec + 28] = 0u8
    c2da_mem[sec + 29] = 0u8
    c2da_mem[sec + 30] = 0u8
    c2da_mem[sec + 31] = 0u8
    i = 0
    while (i < int(uint(c2da_mem[sec + 112]) | uint(c2da_mem[sec + 113]) << 0x8 | uint(c2da_mem[sec + 114]) << 0x10 | uint(c2da_mem[sec + 115]) << 0x18)) {
        let c2da_fresh5 : int = int(uint(c2da_mem[sec + 120]) | uint(c2da_mem[sec + 121]) << 0x8 | uint(c2da_mem[sec + 122]) << 0x10 | uint(c2da_mem[sec + 123]) << 0x18) + i * 8
        check = int(uint(c2da_mem[c2da_fresh5]) | uint(c2da_mem[c2da_fresh5 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh5 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh5 + 3]) << 0x18)
        if ((int(int16(uint(c2da_mem[check + 24]) | uint(c2da_mem[check + 25]) << 0x8)) & 4) == 0) {
            i++
            continue
        }
        P_LineOpening(check)
        if (int(uint(c2da_mem[49680]) | uint(c2da_mem[49681]) << 0x8 | uint(c2da_mem[49682]) << 0x10 | uint(c2da_mem[49683]) << 0x18) <= 0) {
            i++
            continue
        }
        let c2da_fresh6 : int = sides + int(int16(uint(c2da_mem[check + 30 + 0 * 2]) | uint(c2da_mem[check + 30 + 0 * 2 + 1]) << 0x8)) * 24 + 16
        if (int(uint(c2da_mem[c2da_fresh6]) | uint(c2da_mem[c2da_fresh6 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh6 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh6 + 3]) << 0x18) == sec) {
            let c2da_fresh7 : int = sides + int(int16(uint(c2da_mem[check + 30 + 1 * 2]) | uint(c2da_mem[check + 30 + 1 * 2 + 1]) << 0x8)) * 24 + 16
            other = int(uint(c2da_mem[c2da_fresh7]) | uint(c2da_mem[c2da_fresh7 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh7 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh7 + 3]) << 0x18)
        } else {
            let c2da_fresh8 : int = sides + int(int16(uint(c2da_mem[check + 30 + 0 * 2]) | uint(c2da_mem[check + 30 + 0 * 2 + 1]) << 0x8)) * 24 + 16
            other = int(uint(c2da_mem[c2da_fresh8]) | uint(c2da_mem[c2da_fresh8 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh8 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh8 + 3]) << 0x18)
        }
        if ((int(int16(uint(c2da_mem[check + 24]) | uint(c2da_mem[check + 25]) << 0x8)) & 64) != 0) {
            if (soundblocks == 0) {
                P_RecursiveSound(other, 1)
            }
        } else {
            P_RecursiveSound(other, soundblocks)
        }
        i++
    }
    return
}
var soundtarget : int = default<int>

var opposite : uint[9] = fixed_array<uint>(4u, 5u, 6u, 7u, 0u, 1u, 2u, 3u, 8u)

var diags : uint[4] = fixed_array<uint>(3u, 1u, 5u, 7u)

[export, sideeffects]
def A_Fall(var actor : int) {
    let c2da_fresh9 : int = int(uint(c2da_mem[actor + 160]) | uint(c2da_mem[actor + 161]) << 0x8 | uint(c2da_mem[actor + 162]) << 0x10 | uint(c2da_mem[actor + 163]) << 0x18) & ~2
    let c2da_fresh10 : uint = uint(c2da_fresh9)
    c2da_mem[actor + 160] = uint8(c2da_fresh10)
    c2da_mem[actor + 161] = uint8(c2da_fresh10 >> 0x8)
    c2da_mem[actor + 162] = uint8(c2da_fresh10 >> 0x10)
    c2da_mem[actor + 163] = uint8(c2da_fresh10 >> 0x18)
    return
}
[export, sideeffects]
def P_CheckMeleeRange(var actor_0 : int) : uint {
    var pl : int
    var dist : int
    if (int(uint(c2da_mem[actor_0 + 176]) | uint(c2da_mem[actor_0 + 177]) << 0x8 | uint(c2da_mem[actor_0 + 178]) << 0x10 | uint(c2da_mem[actor_0 + 179]) << 0x18) == 0) {
        return 0u
    }
    pl = int(uint(c2da_mem[actor_0 + 176]) | uint(c2da_mem[actor_0 + 177]) << 0x8 | uint(c2da_mem[actor_0 + 178]) << 0x10 | uint(c2da_mem[actor_0 + 179]) << 0x18)
    dist = P_AproxDistance(int(uint(c2da_mem[pl + 24]) | uint(c2da_mem[pl + 25]) << 0x8 | uint(c2da_mem[pl + 26]) << 0x10 | uint(c2da_mem[pl + 27]) << 0x18) - int(uint(c2da_mem[actor_0 + 24]) | uint(c2da_mem[actor_0 + 25]) << 0x8 | uint(c2da_mem[actor_0 + 26]) << 0x10 | uint(c2da_mem[actor_0 + 27]) << 0x18), int(uint(c2da_mem[pl + 28]) | uint(c2da_mem[pl + 29]) << 0x8 | uint(c2da_mem[pl + 30]) << 0x10 | uint(c2da_mem[pl + 31]) << 0x18) - int(uint(c2da_mem[actor_0 + 28]) | uint(c2da_mem[actor_0 + 29]) << 0x8 | uint(c2da_mem[actor_0 + 30]) << 0x10 | uint(c2da_mem[actor_0 + 31]) << 0x18))
    let c2da_fresh11 : int = int(uint(c2da_mem[pl + 136]) | uint(c2da_mem[pl + 137]) << 0x8 | uint(c2da_mem[pl + 138]) << 0x10 | uint(c2da_mem[pl + 139]) << 0x18) + 64
    if (dist >= 64 * (1 << 16) - 20 * (1 << 16) + int(uint(c2da_mem[c2da_fresh11]) | uint(c2da_mem[c2da_fresh11 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh11 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh11 + 3]) << 0x18)) {
        return 0u
    }
    if (P_CheckSight(actor_0, int(uint(c2da_mem[actor_0 + 176]) | uint(c2da_mem[actor_0 + 177]) << 0x8 | uint(c2da_mem[actor_0 + 178]) << 0x10 | uint(c2da_mem[actor_0 + 179]) << 0x18)) == 0) {
        return 0u
    }
    return 1u
}
[export, sideeffects]
def P_CheckMissileRange(var actor_1 : int) : uint {
    var dist_0 : int
    if (P_CheckSight(actor_1, int(uint(c2da_mem[actor_1 + 176]) | uint(c2da_mem[actor_1 + 177]) << 0x8 | uint(c2da_mem[actor_1 + 178]) << 0x10 | uint(c2da_mem[actor_1 + 179]) << 0x18)) == 0) {
        return 0u
    }
    if ((int(uint(c2da_mem[actor_1 + 160]) | uint(c2da_mem[actor_1 + 161]) << 0x8 | uint(c2da_mem[actor_1 + 162]) << 0x10 | uint(c2da_mem[actor_1 + 163]) << 0x18) & 64) != 0) {
        let c2da_fresh12 : int = int(uint(c2da_mem[actor_1 + 160]) | uint(c2da_mem[actor_1 + 161]) << 0x8 | uint(c2da_mem[actor_1 + 162]) << 0x10 | uint(c2da_mem[actor_1 + 163]) << 0x18) & ~64
        let c2da_fresh13 : uint = uint(c2da_fresh12)
        c2da_mem[actor_1 + 160] = uint8(c2da_fresh13)
        c2da_mem[actor_1 + 161] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[actor_1 + 162] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[actor_1 + 163] = uint8(c2da_fresh13 >> 0x18)
        return 1u
    }
    if (int(uint(c2da_mem[actor_1 + 184]) | uint(c2da_mem[actor_1 + 185]) << 0x8 | uint(c2da_mem[actor_1 + 186]) << 0x10 | uint(c2da_mem[actor_1 + 187]) << 0x18) != 0) {
        return 0u
    }
    let c2da_fresh14 : int = int(uint(c2da_mem[actor_1 + 176]) | uint(c2da_mem[actor_1 + 177]) << 0x8 | uint(c2da_mem[actor_1 + 178]) << 0x10 | uint(c2da_mem[actor_1 + 179]) << 0x18) + 24
    let c2da_fresh15 : int = int(uint(c2da_mem[actor_1 + 176]) | uint(c2da_mem[actor_1 + 177]) << 0x8 | uint(c2da_mem[actor_1 + 178]) << 0x10 | uint(c2da_mem[actor_1 + 179]) << 0x18) + 28
    dist_0 = P_AproxDistance(int(uint(c2da_mem[actor_1 + 24]) | uint(c2da_mem[actor_1 + 25]) << 0x8 | uint(c2da_mem[actor_1 + 26]) << 0x10 | uint(c2da_mem[actor_1 + 27]) << 0x18) - int(uint(c2da_mem[c2da_fresh14]) | uint(c2da_mem[c2da_fresh14 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh14 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh14 + 3]) << 0x18), int(uint(c2da_mem[actor_1 + 28]) | uint(c2da_mem[actor_1 + 29]) << 0x8 | uint(c2da_mem[actor_1 + 30]) << 0x10 | uint(c2da_mem[actor_1 + 31]) << 0x18) - int(uint(c2da_mem[c2da_fresh15]) | uint(c2da_mem[c2da_fresh15 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh15 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh15 + 3]) << 0x18)) - 64 * (1 << 16)
    let c2da_fresh16 : int = int(uint(c2da_mem[actor_1 + 136]) | uint(c2da_mem[actor_1 + 137]) << 0x8 | uint(c2da_mem[actor_1 + 138]) << 0x10 | uint(c2da_mem[actor_1 + 139]) << 0x18) + 40
    if (int(uint(c2da_mem[c2da_fresh16]) | uint(c2da_mem[c2da_fresh16 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh16 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh16 + 3]) << 0x18) == 0) {
        dist_0 -= 128 * (1 << 16)
    }
    dist_0 >>= 16
    if ((uint(c2da_mem[actor_1 + 128]) | uint(c2da_mem[actor_1 + 129]) << 0x8 | uint(c2da_mem[actor_1 + 130]) << 0x10 | uint(c2da_mem[actor_1 + 131]) << 0x18) == 3u) {
        if (dist_0 > 14 * 64) {
            return 0u
        }
    }
    if ((uint(c2da_mem[actor_1 + 128]) | uint(c2da_mem[actor_1 + 129]) << 0x8 | uint(c2da_mem[actor_1 + 130]) << 0x10 | uint(c2da_mem[actor_1 + 131]) << 0x18) == 5u) {
        if (dist_0 < 196) {
            return 0u
        }
        dist_0 >>= 1
    }
    if ((uint(c2da_mem[actor_1 + 128]) | uint(c2da_mem[actor_1 + 129]) << 0x8 | uint(c2da_mem[actor_1 + 130]) << 0x10 | uint(c2da_mem[actor_1 + 131]) << 0x18) == 21u || (uint(c2da_mem[actor_1 + 128]) | uint(c2da_mem[actor_1 + 129]) << 0x8 | uint(c2da_mem[actor_1 + 130]) << 0x10 | uint(c2da_mem[actor_1 + 131]) << 0x18) == 19u || (uint(c2da_mem[actor_1 + 128]) | uint(c2da_mem[actor_1 + 129]) << 0x8 | uint(c2da_mem[actor_1 + 130]) << 0x10 | uint(c2da_mem[actor_1 + 131]) << 0x18) == 18u) {
        dist_0 >>= 1
    }
    if (dist_0 > 200) {
        dist_0 = 200
    }
    if ((uint(c2da_mem[actor_1 + 128]) | uint(c2da_mem[actor_1 + 129]) << 0x8 | uint(c2da_mem[actor_1 + 130]) << 0x10 | uint(c2da_mem[actor_1 + 131]) << 0x18) == 21u && dist_0 > 160) {
        dist_0 = 160
    }
    if (P_Random() < dist_0) {
        return 0u
    }
    return 1u
}
var xspeed : int[8] = fixed_array<int>(1 << 16, 47000, 0, -47000, -(1 << 16), -47000, 0, 47000)

var yspeed : int[8] = fixed_array<int>(0, 47000, 1 << 16, 47000, 0, -47000, -(1 << 16), -47000)

[export, sideeffects]
def P_Move(var actor_2 : int) : uint {
    var tryx : int
    var tryy : int
    var ld : int
    var try_ok : uint
    var good : uint
    if (int(uint(c2da_mem[actor_2 + 168]) | uint(c2da_mem[actor_2 + 169]) << 0x8 | uint(c2da_mem[actor_2 + 170]) << 0x10 | uint(c2da_mem[actor_2 + 171]) << 0x18) == 8) {
        return 0u
    }
    if (uint(int(uint(c2da_mem[actor_2 + 168]) | uint(c2da_mem[actor_2 + 169]) << 0x8 | uint(c2da_mem[actor_2 + 170]) << 0x10 | uint(c2da_mem[actor_2 + 171]) << 0x18)) >= 8u) {
        I_Error(359136, [])
    }
    let c2da_fresh17 : int = int(uint(c2da_mem[actor_2 + 136]) | uint(c2da_mem[actor_2 + 137]) << 0x8 | uint(c2da_mem[actor_2 + 138]) << 0x10 | uint(c2da_mem[actor_2 + 139]) << 0x18) + 60
    tryx = int(uint(c2da_mem[actor_2 + 24]) | uint(c2da_mem[actor_2 + 25]) << 0x8 | uint(c2da_mem[actor_2 + 26]) << 0x10 | uint(c2da_mem[actor_2 + 27]) << 0x18) + int(uint(c2da_mem[c2da_fresh17]) | uint(c2da_mem[c2da_fresh17 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh17 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh17 + 3]) << 0x18) * xspeed[int(uint(c2da_mem[actor_2 + 168]) | uint(c2da_mem[actor_2 + 169]) << 0x8 | uint(c2da_mem[actor_2 + 170]) << 0x10 | uint(c2da_mem[actor_2 + 171]) << 0x18)]
    let c2da_fresh18 : int = int(uint(c2da_mem[actor_2 + 136]) | uint(c2da_mem[actor_2 + 137]) << 0x8 | uint(c2da_mem[actor_2 + 138]) << 0x10 | uint(c2da_mem[actor_2 + 139]) << 0x18) + 60
    tryy = int(uint(c2da_mem[actor_2 + 28]) | uint(c2da_mem[actor_2 + 29]) << 0x8 | uint(c2da_mem[actor_2 + 30]) << 0x10 | uint(c2da_mem[actor_2 + 31]) << 0x18) + int(uint(c2da_mem[c2da_fresh18]) | uint(c2da_mem[c2da_fresh18 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh18 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh18 + 3]) << 0x18) * yspeed[int(uint(c2da_mem[actor_2 + 168]) | uint(c2da_mem[actor_2 + 169]) << 0x8 | uint(c2da_mem[actor_2 + 170]) << 0x10 | uint(c2da_mem[actor_2 + 171]) << 0x18)]
    try_ok = uint(P_TryMove(actor_2, tryx, tryy))
    if (try_ok == 0) {
        if ((int(uint(c2da_mem[actor_2 + 160]) | uint(c2da_mem[actor_2 + 161]) << 0x8 | uint(c2da_mem[actor_2 + 162]) << 0x10 | uint(c2da_mem[actor_2 + 163]) << 0x18) & 16384) != 0 && floatok != 0x0) {
            if (int(uint(c2da_mem[actor_2 + 32]) | uint(c2da_mem[actor_2 + 33]) << 0x8 | uint(c2da_mem[actor_2 + 34]) << 0x10 | uint(c2da_mem[actor_2 + 35]) << 0x18) < tmfloorz) {
                let c2da_fresh19 : int = int(uint(c2da_mem[actor_2 + 32]) | uint(c2da_mem[actor_2 + 33]) << 0x8 | uint(c2da_mem[actor_2 + 34]) << 0x10 | uint(c2da_mem[actor_2 + 35]) << 0x18) + (1 << 16) * 4
                let c2da_fresh20 : uint = uint(c2da_fresh19)
                c2da_mem[actor_2 + 32] = uint8(c2da_fresh20)
                c2da_mem[actor_2 + 33] = uint8(c2da_fresh20 >> 0x8)
                c2da_mem[actor_2 + 34] = uint8(c2da_fresh20 >> 0x10)
                c2da_mem[actor_2 + 35] = uint8(c2da_fresh20 >> 0x18)
            } else {
                let c2da_fresh21 : int = int(uint(c2da_mem[actor_2 + 32]) | uint(c2da_mem[actor_2 + 33]) << 0x8 | uint(c2da_mem[actor_2 + 34]) << 0x10 | uint(c2da_mem[actor_2 + 35]) << 0x18) - (1 << 16) * 4
                let c2da_fresh22 : uint = uint(c2da_fresh21)
                c2da_mem[actor_2 + 32] = uint8(c2da_fresh22)
                c2da_mem[actor_2 + 33] = uint8(c2da_fresh22 >> 0x8)
                c2da_mem[actor_2 + 34] = uint8(c2da_fresh22 >> 0x10)
                c2da_mem[actor_2 + 35] = uint8(c2da_fresh22 >> 0x18)
            }
            let c2da_fresh23 : int = int(uint(c2da_mem[actor_2 + 160]) | uint(c2da_mem[actor_2 + 161]) << 0x8 | uint(c2da_mem[actor_2 + 162]) << 0x10 | uint(c2da_mem[actor_2 + 163]) << 0x18) | 2097152
            let c2da_fresh24 : uint = uint(c2da_fresh23)
            c2da_mem[actor_2 + 160] = uint8(c2da_fresh24)
            c2da_mem[actor_2 + 161] = uint8(c2da_fresh24 >> 0x8)
            c2da_mem[actor_2 + 162] = uint8(c2da_fresh24 >> 0x10)
            c2da_mem[actor_2 + 163] = uint8(c2da_fresh24 >> 0x18)
            return 1u
        }
        if (numspechit == 0) {
            return 0u
        }
        let c2da_fresh25 : int = 8
        let c2da_fresh26 : uint = uint(c2da_fresh25)
        c2da_mem[actor_2 + 168] = uint8(c2da_fresh26)
        c2da_mem[actor_2 + 169] = uint8(c2da_fresh26 >> 0x8)
        c2da_mem[actor_2 + 170] = uint8(c2da_fresh26 >> 0x10)
        c2da_mem[actor_2 + 171] = uint8(c2da_fresh26 >> 0x18)
        good = 0u
        while (true) {
            let c2da_postinc : int = numspechit
            numspechit = numspechit - 1
            if (c2da_postinc == 0) {
                break
            }
            ld = spechit[int(numspechit)]
            if (P_UseSpecialLine(actor_2, ld, 0) != 0x0) {
                good = 1u
            }
        }
        return good
    } else {
        let c2da_fresh27 : int = int(uint(c2da_mem[actor_2 + 160]) | uint(c2da_mem[actor_2 + 161]) << 0x8 | uint(c2da_mem[actor_2 + 162]) << 0x10 | uint(c2da_mem[actor_2 + 163]) << 0x18) & ~2097152
        let c2da_fresh28 : uint = uint(c2da_fresh27)
        c2da_mem[actor_2 + 160] = uint8(c2da_fresh28)
        c2da_mem[actor_2 + 161] = uint8(c2da_fresh28 >> 0x8)
        c2da_mem[actor_2 + 162] = uint8(c2da_fresh28 >> 0x10)
        c2da_mem[actor_2 + 163] = uint8(c2da_fresh28 >> 0x18)
    }
    if ((int(uint(c2da_mem[actor_2 + 160]) | uint(c2da_mem[actor_2 + 161]) << 0x8 | uint(c2da_mem[actor_2 + 162]) << 0x10 | uint(c2da_mem[actor_2 + 163]) << 0x18) & 16384) == 0) {
        let c2da_fresh29 : int = int(uint(c2da_mem[actor_2 + 96]) | uint(c2da_mem[actor_2 + 97]) << 0x8 | uint(c2da_mem[actor_2 + 98]) << 0x10 | uint(c2da_mem[actor_2 + 99]) << 0x18)
        let c2da_fresh30 : uint = uint(c2da_fresh29)
        c2da_mem[actor_2 + 32] = uint8(c2da_fresh30)
        c2da_mem[actor_2 + 33] = uint8(c2da_fresh30 >> 0x8)
        c2da_mem[actor_2 + 34] = uint8(c2da_fresh30 >> 0x10)
        c2da_mem[actor_2 + 35] = uint8(c2da_fresh30 >> 0x18)
    }
    return 1u
}
[export, sideeffects]
def P_TryWalk(var actor_3 : int) : uint {
    if (P_Move(actor_3) == 0) {
        return 0u
    }
    let c2da_fresh31 : int = P_Random() & 15
    let c2da_fresh32 : uint = uint(c2da_fresh31)
    c2da_mem[actor_3 + 172] = uint8(c2da_fresh32)
    c2da_mem[actor_3 + 173] = uint8(c2da_fresh32 >> 0x8)
    c2da_mem[actor_3 + 174] = uint8(c2da_fresh32 >> 0x10)
    c2da_mem[actor_3 + 175] = uint8(c2da_fresh32 >> 0x18)
    return 1u
}
[export, sideeffects]
def P_NewChaseDir(var actor_4 : int) {
    var deltax : int
    var deltay : int
    var d : uint[3]
    var tdir : int
    var olddir : uint
    var turnaround : uint
    if (int(uint(c2da_mem[actor_4 + 176]) | uint(c2da_mem[actor_4 + 177]) << 0x8 | uint(c2da_mem[actor_4 + 178]) << 0x10 | uint(c2da_mem[actor_4 + 179]) << 0x18) == 0) {
        I_Error(359158, [])
    }
    olddir = uint(int(uint(c2da_mem[actor_4 + 168]) | uint(c2da_mem[actor_4 + 169]) << 0x8 | uint(c2da_mem[actor_4 + 170]) << 0x10 | uint(c2da_mem[actor_4 + 171]) << 0x18))
    turnaround = opposite[int(olddir)]
    let c2da_fresh33 : int = int(uint(c2da_mem[actor_4 + 176]) | uint(c2da_mem[actor_4 + 177]) << 0x8 | uint(c2da_mem[actor_4 + 178]) << 0x10 | uint(c2da_mem[actor_4 + 179]) << 0x18) + 24
    deltax = int(uint(c2da_mem[c2da_fresh33]) | uint(c2da_mem[c2da_fresh33 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh33 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh33 + 3]) << 0x18) - int(uint(c2da_mem[actor_4 + 24]) | uint(c2da_mem[actor_4 + 25]) << 0x8 | uint(c2da_mem[actor_4 + 26]) << 0x10 | uint(c2da_mem[actor_4 + 27]) << 0x18)
    let c2da_fresh34 : int = int(uint(c2da_mem[actor_4 + 176]) | uint(c2da_mem[actor_4 + 177]) << 0x8 | uint(c2da_mem[actor_4 + 178]) << 0x10 | uint(c2da_mem[actor_4 + 179]) << 0x18) + 28
    deltay = int(uint(c2da_mem[c2da_fresh34]) | uint(c2da_mem[c2da_fresh34 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh34 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh34 + 3]) << 0x18) - int(uint(c2da_mem[actor_4 + 28]) | uint(c2da_mem[actor_4 + 29]) << 0x8 | uint(c2da_mem[actor_4 + 30]) << 0x10 | uint(c2da_mem[actor_4 + 31]) << 0x18)
    if (deltax > 10 * (1 << 16)) {
        d[1] = 0u
    } elif (deltax < -10 * (1 << 16)) {
        d[1] = 4u
    } else {
        d[1] = 8u
    }
    if (deltay < -10 * (1 << 16)) {
        d[2] = 6u
    } elif (deltay > 10 * (1 << 16)) {
        d[2] = 2u
    } else {
        d[2] = 8u
    }
    if (d[1] != 8u && d[2] != 8u) {
        let c2da_fresh35 : int = int(diags[((deltay < 0 ? 1 : 0) << 1) + (deltax > 0 ? 1 : 0)])
        let c2da_fresh36 : uint = uint(c2da_fresh35)
        c2da_mem[actor_4 + 168] = uint8(c2da_fresh36)
        c2da_mem[actor_4 + 169] = uint8(c2da_fresh36 >> 0x8)
        c2da_mem[actor_4 + 170] = uint8(c2da_fresh36 >> 0x10)
        c2da_mem[actor_4 + 171] = uint8(c2da_fresh36 >> 0x18)
        if (int(uint(c2da_mem[actor_4 + 168]) | uint(c2da_mem[actor_4 + 169]) << 0x8 | uint(c2da_mem[actor_4 + 170]) << 0x10 | uint(c2da_mem[actor_4 + 171]) << 0x18) != int(turnaround) && P_TryWalk(actor_4) != 0x0) {
            return
        }
    }
    if (P_Random() > 200 || c2da_std_abs(deltay) > c2da_std_abs(deltax)) {
        tdir = int(d[1])
        d[1] = uint(d[2])  // nolint:PERF020
        d[2] = uint(tdir)
    }
    if (d[1] == turnaround) {
        d[1] = 8u
    }
    if (d[2] == turnaround) {
        d[2] = 8u
    }
    if (d[1] != 8u) {
        let c2da_fresh37 : int = int(d[1])
        let c2da_fresh38 : uint = uint(c2da_fresh37)
        c2da_mem[actor_4 + 168] = uint8(c2da_fresh38)
        c2da_mem[actor_4 + 169] = uint8(c2da_fresh38 >> 0x8)
        c2da_mem[actor_4 + 170] = uint8(c2da_fresh38 >> 0x10)
        c2da_mem[actor_4 + 171] = uint8(c2da_fresh38 >> 0x18)
        if (P_TryWalk(actor_4) != 0x0) {
            return
        }
    }
    if (d[2] != 8u) {
        let c2da_fresh39 : int = int(d[2])
        let c2da_fresh40 : uint = uint(c2da_fresh39)
        c2da_mem[actor_4 + 168] = uint8(c2da_fresh40)
        c2da_mem[actor_4 + 169] = uint8(c2da_fresh40 >> 0x8)
        c2da_mem[actor_4 + 170] = uint8(c2da_fresh40 >> 0x10)
        c2da_mem[actor_4 + 171] = uint8(c2da_fresh40 >> 0x18)
        if (P_TryWalk(actor_4) != 0x0) {
            return
        }
    }
    if (olddir != 8u) {
        let c2da_fresh41 : int = int(olddir)
        let c2da_fresh42 : uint = uint(c2da_fresh41)
        c2da_mem[actor_4 + 168] = uint8(c2da_fresh42)
        c2da_mem[actor_4 + 169] = uint8(c2da_fresh42 >> 0x8)
        c2da_mem[actor_4 + 170] = uint8(c2da_fresh42 >> 0x10)
        c2da_mem[actor_4 + 171] = uint8(c2da_fresh42 >> 0x18)
        if (P_TryWalk(actor_4) != 0x0) {
            return
        }
    }
    if ((P_Random() & 1) != 0) {
        tdir = 0
        while (tdir <= 7) {
            if (tdir != int(turnaround)) {
                let c2da_fresh43 : uint = uint(tdir)
                c2da_mem[actor_4 + 168] = uint8(c2da_fresh43)
                c2da_mem[actor_4 + 169] = uint8(c2da_fresh43 >> 0x8)
                c2da_mem[actor_4 + 170] = uint8(c2da_fresh43 >> 0x10)
                c2da_mem[actor_4 + 171] = uint8(c2da_fresh43 >> 0x18)
                if (P_TryWalk(actor_4) != 0x0) {
                    return
                }
            }
            tdir++
        }
    } else {
        tdir = 7
        while (tdir != 0 - 1) {
            if (tdir != int(turnaround)) {
                let c2da_fresh44 : uint = uint(tdir)
                c2da_mem[actor_4 + 168] = uint8(c2da_fresh44)
                c2da_mem[actor_4 + 169] = uint8(c2da_fresh44 >> 0x8)
                c2da_mem[actor_4 + 170] = uint8(c2da_fresh44 >> 0x10)
                c2da_mem[actor_4 + 171] = uint8(c2da_fresh44 >> 0x18)
                if (P_TryWalk(actor_4) != 0x0) {
                    return
                }
            }
            tdir--
        }
    }
    if (turnaround != 8u) {
        let c2da_fresh45 : int = int(turnaround)
        let c2da_fresh46 : uint = uint(c2da_fresh45)
        c2da_mem[actor_4 + 168] = uint8(c2da_fresh46)
        c2da_mem[actor_4 + 169] = uint8(c2da_fresh46 >> 0x8)
        c2da_mem[actor_4 + 170] = uint8(c2da_fresh46 >> 0x10)
        c2da_mem[actor_4 + 171] = uint8(c2da_fresh46 >> 0x18)
        if (P_TryWalk(actor_4) != 0x0) {
            return
        }
    }
    let c2da_fresh47 : int = 8
    let c2da_fresh48 : uint = uint(c2da_fresh47)
    c2da_mem[actor_4 + 168] = uint8(c2da_fresh48)
    c2da_mem[actor_4 + 169] = uint8(c2da_fresh48 >> 0x8)
    c2da_mem[actor_4 + 170] = uint8(c2da_fresh48 >> 0x10)
    c2da_mem[actor_4 + 171] = uint8(c2da_fresh48 >> 0x18)
    return
}
[export, sideeffects]
def P_LookForPlayers(var actor_5 : int; var allaround : uint) : uint {
    var c : int
    var stop : int
    var player : int
    var an : uint
    var dist_1 : int
    c = 0
    stop = int(uint(c2da_mem[actor_5 + 200]) | uint(c2da_mem[actor_5 + 201]) << 0x8 | uint(c2da_mem[actor_5 + 202]) << 0x10 | uint(c2da_mem[actor_5 + 203]) << 0x18) - 1 & 3
    while (true) {
        if (playeringame[int(uint(c2da_mem[actor_5 + 200]) | uint(c2da_mem[actor_5 + 201]) << 0x8 | uint(c2da_mem[actor_5 + 202]) << 0x10 | uint(c2da_mem[actor_5 + 203]) << 0x18)] == 0) {
            let c2da_fresh49 : int = int(uint(c2da_mem[actor_5 + 200]) | uint(c2da_mem[actor_5 + 201]) << 0x8 | uint(c2da_mem[actor_5 + 202]) << 0x10 | uint(c2da_mem[actor_5 + 203]) << 0x18) + 1 & 3
            let c2da_fresh50 : uint = uint(c2da_fresh49)
            c2da_mem[actor_5 + 200] = uint8(c2da_fresh50)
            c2da_mem[actor_5 + 201] = uint8(c2da_fresh50 >> 0x8)
            c2da_mem[actor_5 + 202] = uint8(c2da_fresh50 >> 0x10)
            c2da_mem[actor_5 + 203] = uint8(c2da_fresh50 >> 0x18)
            continue
        }
        let c2da_postinc_0 : int = c
        c++
        if (c2da_postinc_0 == 2 || int(uint(c2da_mem[actor_5 + 200]) | uint(c2da_mem[actor_5 + 201]) << 0x8 | uint(c2da_mem[actor_5 + 202]) << 0x10 | uint(c2da_mem[actor_5 + 203]) << 0x18) == stop) {
            return 0u
        }
        player = 96 + int(uint(c2da_mem[actor_5 + 200]) | uint(c2da_mem[actor_5 + 201]) << 0x8 | uint(c2da_mem[actor_5 + 202]) << 0x10 | uint(c2da_mem[actor_5 + 203]) << 0x18) * 328
        if (int(uint(c2da_mem[player + 44]) | uint(c2da_mem[player + 45]) << 0x8 | uint(c2da_mem[player + 46]) << 0x10 | uint(c2da_mem[player + 47]) << 0x18) <= 0) {
            let c2da_fresh51 : int = int(uint(c2da_mem[actor_5 + 200]) | uint(c2da_mem[actor_5 + 201]) << 0x8 | uint(c2da_mem[actor_5 + 202]) << 0x10 | uint(c2da_mem[actor_5 + 203]) << 0x18) + 1 & 3
            let c2da_fresh52 : uint = uint(c2da_fresh51)
            c2da_mem[actor_5 + 200] = uint8(c2da_fresh52)
            c2da_mem[actor_5 + 201] = uint8(c2da_fresh52 >> 0x8)
            c2da_mem[actor_5 + 202] = uint8(c2da_fresh52 >> 0x10)
            c2da_mem[actor_5 + 203] = uint8(c2da_fresh52 >> 0x18)
            continue
        }
        if (P_CheckSight(actor_5, int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18)) == 0) {
            let c2da_fresh53 : int = int(uint(c2da_mem[actor_5 + 200]) | uint(c2da_mem[actor_5 + 201]) << 0x8 | uint(c2da_mem[actor_5 + 202]) << 0x10 | uint(c2da_mem[actor_5 + 203]) << 0x18) + 1 & 3
            let c2da_fresh54 : uint = uint(c2da_fresh53)
            c2da_mem[actor_5 + 200] = uint8(c2da_fresh54)
            c2da_mem[actor_5 + 201] = uint8(c2da_fresh54 >> 0x8)
            c2da_mem[actor_5 + 202] = uint8(c2da_fresh54 >> 0x10)
            c2da_mem[actor_5 + 203] = uint8(c2da_fresh54 >> 0x18)
            continue
        }
        if (allaround == 0) {
            let c2da_fresh55 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 24
            let c2da_fresh56 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 28
            an = uint(R_PointToAngle2(int(uint(c2da_mem[actor_5 + 24]) | uint(c2da_mem[actor_5 + 25]) << 0x8 | uint(c2da_mem[actor_5 + 26]) << 0x10 | uint(c2da_mem[actor_5 + 27]) << 0x18), int(uint(c2da_mem[actor_5 + 28]) | uint(c2da_mem[actor_5 + 29]) << 0x8 | uint(c2da_mem[actor_5 + 30]) << 0x10 | uint(c2da_mem[actor_5 + 31]) << 0x18), int(uint(c2da_mem[c2da_fresh55]) | uint(c2da_mem[c2da_fresh55 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh55 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh55 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh56]) | uint(c2da_mem[c2da_fresh56 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh56 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh56 + 3]) << 0x18)) - (uint(c2da_mem[actor_5 + 56]) | uint(c2da_mem[actor_5 + 57]) << 0x8 | uint(c2da_mem[actor_5 + 58]) << 0x10 | uint(c2da_mem[actor_5 + 59]) << 0x18))
            if (an > 0x40000000u && an < 0xc0000000u) {
                let c2da_fresh57 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 24
                let c2da_fresh58 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 28
                dist_1 = P_AproxDistance(int(uint(c2da_mem[c2da_fresh57]) | uint(c2da_mem[c2da_fresh57 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh57 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh57 + 3]) << 0x18) - int(uint(c2da_mem[actor_5 + 24]) | uint(c2da_mem[actor_5 + 25]) << 0x8 | uint(c2da_mem[actor_5 + 26]) << 0x10 | uint(c2da_mem[actor_5 + 27]) << 0x18), int(uint(c2da_mem[c2da_fresh58]) | uint(c2da_mem[c2da_fresh58 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh58 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh58 + 3]) << 0x18) - int(uint(c2da_mem[actor_5 + 28]) | uint(c2da_mem[actor_5 + 29]) << 0x8 | uint(c2da_mem[actor_5 + 30]) << 0x10 | uint(c2da_mem[actor_5 + 31]) << 0x18))
                if (dist_1 > 64 * (1 << 16)) {
                    let c2da_fresh59 : int = int(uint(c2da_mem[actor_5 + 200]) | uint(c2da_mem[actor_5 + 201]) << 0x8 | uint(c2da_mem[actor_5 + 202]) << 0x10 | uint(c2da_mem[actor_5 + 203]) << 0x18) + 1 & 3
                    let c2da_fresh60 : uint = uint(c2da_fresh59)
                    c2da_mem[actor_5 + 200] = uint8(c2da_fresh60)
                    c2da_mem[actor_5 + 201] = uint8(c2da_fresh60 >> 0x8)
                    c2da_mem[actor_5 + 202] = uint8(c2da_fresh60 >> 0x10)
                    c2da_mem[actor_5 + 203] = uint8(c2da_fresh60 >> 0x18)
                    continue
                }
            }
        }
        let c2da_fresh61 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18)
        let c2da_fresh62 : uint = uint(c2da_fresh61)
        c2da_mem[actor_5 + 176] = uint8(c2da_fresh62)
        c2da_mem[actor_5 + 177] = uint8(c2da_fresh62 >> 0x8)
        c2da_mem[actor_5 + 178] = uint8(c2da_fresh62 >> 0x10)
        c2da_mem[actor_5 + 179] = uint8(c2da_fresh62 >> 0x18)
        c2da_mem[actor_5 + 180] = 0u8
        c2da_mem[actor_5 + 181] = 0u8
        c2da_mem[actor_5 + 182] = 0u8
        c2da_mem[actor_5 + 183] = 0u8
        return 1u
    }
}
[export, sideeffects]
def A_KeenDie(var mo : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    A_KeenDie_c2da_frame(mo, c2da_lin_enter(96))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def A_Look(var actor_6 : int) {
    var c2da_fresh74 : int
    var targ : int
    var sound : int
    let c2da_fresh67 : int = 0
    let c2da_fresh68 : uint = uint(c2da_fresh67)
    c2da_mem[actor_6 + 188] = uint8(c2da_fresh68)
    c2da_mem[actor_6 + 189] = uint8(c2da_fresh68 >> 0x8)
    c2da_mem[actor_6 + 190] = uint8(c2da_fresh68 >> 0x10)
    c2da_mem[actor_6 + 191] = uint8(c2da_fresh68 >> 0x18)
    let c2da_fresh69 : int = int(uint(c2da_mem[actor_6 + 88]) | uint(c2da_mem[actor_6 + 89]) << 0x8 | uint(c2da_mem[actor_6 + 90]) << 0x10 | uint(c2da_mem[actor_6 + 91]) << 0x18)
    let c2da_fresh70 : int = int(uint(c2da_mem[c2da_fresh69]) | uint(c2da_mem[c2da_fresh69 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh69 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh69 + 3]) << 0x18) + 24
    targ = int(uint(c2da_mem[c2da_fresh70]) | uint(c2da_mem[c2da_fresh70 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh70 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh70 + 3]) << 0x18)
    if (targ != 0 && (int(uint(c2da_mem[targ + 160]) | uint(c2da_mem[targ + 161]) << 0x8 | uint(c2da_mem[targ + 162]) << 0x10 | uint(c2da_mem[targ + 163]) << 0x18) & 4) != 0) {
        goto label 8
    }
    label 0:
    if (P_LookForPlayers(actor_6, 0u) == 0) {
        goto label 7
    }
    label 1:
    let c2da_fresh72 : int = int(uint(c2da_mem[actor_6 + 136]) | uint(c2da_mem[actor_6 + 137]) << 0x8 | uint(c2da_mem[actor_6 + 138]) << 0x10 | uint(c2da_mem[actor_6 + 139]) << 0x18) + 16
    if (int(uint(c2da_mem[c2da_fresh72]) | uint(c2da_mem[c2da_fresh72 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh72 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh72 + 3]) << 0x18) != 0) {
        goto label 3
    }
    label 2:
    let c2da_fresh76 : int = int(uint(c2da_mem[actor_6 + 136]) | uint(c2da_mem[actor_6 + 137]) << 0x8 | uint(c2da_mem[actor_6 + 138]) << 0x10 | uint(c2da_mem[actor_6 + 139]) << 0x18) + 12
    P_SetMobjState(actor_6, uint(int(uint(c2da_mem[c2da_fresh76]) | uint(c2da_mem[c2da_fresh76 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh76 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh76 + 3]) << 0x18)))
    return
    label 3:
    let c2da_fresh73 : int = int(uint(c2da_mem[actor_6 + 136]) | uint(c2da_mem[actor_6 + 137]) << 0x8 | uint(c2da_mem[actor_6 + 138]) << 0x10 | uint(c2da_mem[actor_6 + 139]) << 0x18) + 16
    c2da_fresh74 = int(uint(c2da_mem[c2da_fresh73]) | uint(c2da_mem[c2da_fresh73 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh73 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh73 + 3]) << 0x18)
    if (c2da_fresh74 >= 36 && c2da_fresh74 <= 40) {
        goto c2da_fresh74 - 25
    }
    let c2da_fresh75 : int = int(uint(c2da_mem[actor_6 + 136]) | uint(c2da_mem[actor_6 + 137]) << 0x8 | uint(c2da_mem[actor_6 + 138]) << 0x10 | uint(c2da_mem[actor_6 + 139]) << 0x18) + 16
    sound = int(uint(c2da_mem[c2da_fresh75]) | uint(c2da_mem[c2da_fresh75 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh75 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh75 + 3]) << 0x18)
    label 4:
    if ((uint(c2da_mem[actor_6 + 128]) | uint(c2da_mem[actor_6 + 129]) << 0x8 | uint(c2da_mem[actor_6 + 130]) << 0x10 | uint(c2da_mem[actor_6 + 131]) << 0x18) == 19u || (uint(c2da_mem[actor_6 + 128]) | uint(c2da_mem[actor_6 + 129]) << 0x8 | uint(c2da_mem[actor_6 + 130]) << 0x10 | uint(c2da_mem[actor_6 + 131]) << 0x18) == 21u) {
        goto label 6
    }
    S_StartSound(actor_6, sound)
    label 5:
    goto label 2
    label 6:
    S_StartSound(0, sound)
    goto label 5
    label 11:
    label 12:
    label 13:
    sound = 36 + P_Random() % 3
    goto label 4
    label 14:
    label 15:
    sound = 39 + P_Random() % 2
    goto label 4
    label 7:
    return
    label 8:
    let c2da_fresh71 : uint = uint(targ)
    c2da_mem[actor_6 + 176] = uint8(c2da_fresh71)
    c2da_mem[actor_6 + 177] = uint8(c2da_fresh71 >> 0x8)
    c2da_mem[actor_6 + 178] = uint8(c2da_fresh71 >> 0x10)
    c2da_mem[actor_6 + 179] = uint8(c2da_fresh71 >> 0x18)
    c2da_mem[actor_6 + 180] = 0u8
    c2da_mem[actor_6 + 181] = 0u8
    c2da_mem[actor_6 + 182] = 0u8
    c2da_mem[actor_6 + 183] = 0u8
    if ((int(uint(c2da_mem[actor_6 + 160]) | uint(c2da_mem[actor_6 + 161]) << 0x8 | uint(c2da_mem[actor_6 + 162]) << 0x10 | uint(c2da_mem[actor_6 + 163]) << 0x18) & 32) != 0) {
        goto label 9
    }
    goto label 1
    label 9:
    if (P_CheckSight(actor_6, int(uint(c2da_mem[actor_6 + 176]) | uint(c2da_mem[actor_6 + 177]) << 0x8 | uint(c2da_mem[actor_6 + 178]) << 0x10 | uint(c2da_mem[actor_6 + 179]) << 0x18)) != 0x0) {
        goto label 10
    }
    goto label 0
    label 10:
    goto label 1
    panic("unreachable: fell out of a translated control-flow graph")
}
[export, sideeffects]
def A_Chase(var actor_7 : int) {
    var delta : int
    var c2da_fresh94 : int
    if (int(uint(c2da_mem[actor_7 + 184]) | uint(c2da_mem[actor_7 + 185]) << 0x8 | uint(c2da_mem[actor_7 + 186]) << 0x10 | uint(c2da_mem[actor_7 + 187]) << 0x18) != 0) {
        goto label 30
    }
    label 0:
    if (int(uint(c2da_mem[actor_7 + 188]) | uint(c2da_mem[actor_7 + 189]) << 0x8 | uint(c2da_mem[actor_7 + 190]) << 0x10 | uint(c2da_mem[actor_7 + 191]) << 0x18) != 0) {
        goto label 27
    }
    label 1:
    if (int(uint(c2da_mem[actor_7 + 168]) | uint(c2da_mem[actor_7 + 169]) << 0x8 | uint(c2da_mem[actor_7 + 170]) << 0x10 | uint(c2da_mem[actor_7 + 171]) << 0x18) < 8) {
        goto label 22
    }
    label 2:
    c2da_fresh94 = 1
    if (!(int(uint(c2da_mem[actor_7 + 176]) | uint(c2da_mem[actor_7 + 177]) << 0x8 | uint(c2da_mem[actor_7 + 178]) << 0x10 | uint(c2da_mem[actor_7 + 179]) << 0x18) == 0)) {
        let c2da_fresh93 : int = int(uint(c2da_mem[actor_7 + 176]) | uint(c2da_mem[actor_7 + 177]) << 0x8 | uint(c2da_mem[actor_7 + 178]) << 0x10 | uint(c2da_mem[actor_7 + 179]) << 0x18) + 160
        if (!((int(uint(c2da_mem[c2da_fresh93]) | uint(c2da_mem[c2da_fresh93 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh93 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh93 + 3]) << 0x18) & 4) == 0)) {
            c2da_fresh94 = 0
        }
    }
    if (c2da_fresh94 != 0) {
        goto label 20
    }
    if ((int(uint(c2da_mem[actor_7 + 160]) | uint(c2da_mem[actor_7 + 161]) << 0x8 | uint(c2da_mem[actor_7 + 162]) << 0x10 | uint(c2da_mem[actor_7 + 163]) << 0x18) & 128) != 0) {
        goto label 17
    }
    let c2da_fresh98 : int = int(uint(c2da_mem[actor_7 + 136]) | uint(c2da_mem[actor_7 + 137]) << 0x8 | uint(c2da_mem[actor_7 + 138]) << 0x10 | uint(c2da_mem[actor_7 + 139]) << 0x18) + 40
    if (int(uint(c2da_mem[c2da_fresh98]) | uint(c2da_mem[c2da_fresh98 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh98 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh98 + 3]) << 0x18) != 0 && P_CheckMeleeRange(actor_7) != 0x0) {
        goto label 14
    }
    let c2da_fresh102 : int = int(uint(c2da_mem[actor_7 + 136]) | uint(c2da_mem[actor_7 + 137]) << 0x8 | uint(c2da_mem[actor_7 + 138]) << 0x10 | uint(c2da_mem[actor_7 + 139]) << 0x18) + 44
    if (int(uint(c2da_mem[c2da_fresh102]) | uint(c2da_mem[c2da_fresh102 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh102 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh102 + 3]) << 0x18) != 0) {
        goto label 11
    }
    label 3:
    if (netgame != 0x0 && int(uint(c2da_mem[actor_7 + 188]) | uint(c2da_mem[actor_7 + 189]) << 0x8 | uint(c2da_mem[actor_7 + 190]) << 0x10 | uint(c2da_mem[actor_7 + 191]) << 0x18) == 0 && P_CheckSight(actor_7, int(uint(c2da_mem[actor_7 + 176]) | uint(c2da_mem[actor_7 + 177]) << 0x8 | uint(c2da_mem[actor_7 + 178]) << 0x10 | uint(c2da_mem[actor_7 + 179]) << 0x18)) == 0) {
        goto label 9
    }
    label 4:
    let c2da_fresh106 : int = int(uint(c2da_mem[actor_7 + 172]) | uint(c2da_mem[actor_7 + 173]) << 0x8 | uint(c2da_mem[actor_7 + 174]) << 0x10 | uint(c2da_mem[actor_7 + 175]) << 0x18)
    let c2da_fresh107 : int = c2da_fresh106 - 1
    let c2da_fresh108 : uint = uint(c2da_fresh107)
    c2da_mem[actor_7 + 172] = uint8(c2da_fresh108)
    c2da_mem[actor_7 + 173] = uint8(c2da_fresh108 >> 0x8)
    c2da_mem[actor_7 + 174] = uint8(c2da_fresh108 >> 0x10)
    c2da_mem[actor_7 + 175] = uint8(c2da_fresh108 >> 0x18)
    if (c2da_fresh107 < 0 || P_Move(actor_7) == 0) {
        goto label 8
    }
    label 5:
    let c2da_fresh109 : int = int(uint(c2da_mem[actor_7 + 136]) | uint(c2da_mem[actor_7 + 137]) << 0x8 | uint(c2da_mem[actor_7 + 138]) << 0x10 | uint(c2da_mem[actor_7 + 139]) << 0x18) + 80
    if (int(uint(c2da_mem[c2da_fresh109]) | uint(c2da_mem[c2da_fresh109 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh109 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh109 + 3]) << 0x18) != 0 && P_Random() < 3) {
        goto label 7
    }
    label 6:
    return
    label 7:
    let c2da_fresh110 : int = int(uint(c2da_mem[actor_7 + 136]) | uint(c2da_mem[actor_7 + 137]) << 0x8 | uint(c2da_mem[actor_7 + 138]) << 0x10 | uint(c2da_mem[actor_7 + 139]) << 0x18) + 80
    S_StartSound(actor_7, int(uint(c2da_mem[c2da_fresh110]) | uint(c2da_mem[c2da_fresh110 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh110 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh110 + 3]) << 0x18))
    goto label 6
    label 8:
    P_NewChaseDir(actor_7)
    goto label 5
    label 9:
    if (P_LookForPlayers(actor_7, 1u) != 0x0) {
        goto label 10
    }
    goto label 4
    label 10:
    return
    label 11:
    if (int(gameskill) < 4 && fastparm == 0 && int(uint(c2da_mem[actor_7 + 172]) | uint(c2da_mem[actor_7 + 173]) << 0x8 | uint(c2da_mem[actor_7 + 174]) << 0x10 | uint(c2da_mem[actor_7 + 175]) << 0x18) != 0) {
        goto label 13
    }
    if (P_CheckMissileRange(actor_7) == 0) {
        goto label 12
    }
    let c2da_fresh103 : int = int(uint(c2da_mem[actor_7 + 136]) | uint(c2da_mem[actor_7 + 137]) << 0x8 | uint(c2da_mem[actor_7 + 138]) << 0x10 | uint(c2da_mem[actor_7 + 139]) << 0x18) + 44
    P_SetMobjState(actor_7, uint(int(uint(c2da_mem[c2da_fresh103]) | uint(c2da_mem[c2da_fresh103 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh103 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh103 + 3]) << 0x18)))
    let c2da_fresh104 : int = int(uint(c2da_mem[actor_7 + 160]) | uint(c2da_mem[actor_7 + 161]) << 0x8 | uint(c2da_mem[actor_7 + 162]) << 0x10 | uint(c2da_mem[actor_7 + 163]) << 0x18) | 128
    let c2da_fresh105 : uint = uint(c2da_fresh104)
    c2da_mem[actor_7 + 160] = uint8(c2da_fresh105)
    c2da_mem[actor_7 + 161] = uint8(c2da_fresh105 >> 0x8)
    c2da_mem[actor_7 + 162] = uint8(c2da_fresh105 >> 0x10)
    c2da_mem[actor_7 + 163] = uint8(c2da_fresh105 >> 0x18)
    return
    label 12:
    goto label 3
    label 13:
    goto label 3
    label 14:
    let c2da_fresh99 : int = int(uint(c2da_mem[actor_7 + 136]) | uint(c2da_mem[actor_7 + 137]) << 0x8 | uint(c2da_mem[actor_7 + 138]) << 0x10 | uint(c2da_mem[actor_7 + 139]) << 0x18) + 24
    if (int(uint(c2da_mem[c2da_fresh99]) | uint(c2da_mem[c2da_fresh99 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh99 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh99 + 3]) << 0x18) != 0) {
        goto label 16
    }
    label 15:
    let c2da_fresh101 : int = int(uint(c2da_mem[actor_7 + 136]) | uint(c2da_mem[actor_7 + 137]) << 0x8 | uint(c2da_mem[actor_7 + 138]) << 0x10 | uint(c2da_mem[actor_7 + 139]) << 0x18) + 40
    P_SetMobjState(actor_7, uint(int(uint(c2da_mem[c2da_fresh101]) | uint(c2da_mem[c2da_fresh101 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh101 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh101 + 3]) << 0x18)))
    return
    label 16:
    let c2da_fresh100 : int = int(uint(c2da_mem[actor_7 + 136]) | uint(c2da_mem[actor_7 + 137]) << 0x8 | uint(c2da_mem[actor_7 + 138]) << 0x10 | uint(c2da_mem[actor_7 + 139]) << 0x18) + 24
    S_StartSound(actor_7, int(uint(c2da_mem[c2da_fresh100]) | uint(c2da_mem[c2da_fresh100 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh100 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh100 + 3]) << 0x18))
    goto label 15
    label 17:
    let c2da_fresh96 : int = int(uint(c2da_mem[actor_7 + 160]) | uint(c2da_mem[actor_7 + 161]) << 0x8 | uint(c2da_mem[actor_7 + 162]) << 0x10 | uint(c2da_mem[actor_7 + 163]) << 0x18) & ~128
    let c2da_fresh97 : uint = uint(c2da_fresh96)
    c2da_mem[actor_7 + 160] = uint8(c2da_fresh97)
    c2da_mem[actor_7 + 161] = uint8(c2da_fresh97 >> 0x8)
    c2da_mem[actor_7 + 162] = uint8(c2da_fresh97 >> 0x10)
    c2da_mem[actor_7 + 163] = uint8(c2da_fresh97 >> 0x18)
    if (int(gameskill) != 4 && fastparm == 0) {
        goto label 19
    }
    label 18:
    return
    label 19:
    P_NewChaseDir(actor_7)
    goto label 18
    label 20:
    if (P_LookForPlayers(actor_7, 1u) != 0x0) {
        goto label 21
    }
    let c2da_fresh95 : int = int(uint(c2da_mem[actor_7 + 136]) | uint(c2da_mem[actor_7 + 137]) << 0x8 | uint(c2da_mem[actor_7 + 138]) << 0x10 | uint(c2da_mem[actor_7 + 139]) << 0x18) + 4
    P_SetMobjState(actor_7, uint(int(uint(c2da_mem[c2da_fresh95]) | uint(c2da_mem[c2da_fresh95 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh95 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh95 + 3]) << 0x18)))
    return
    label 21:
    return
    label 22:
    let c2da_fresh87 : uint = (uint(c2da_mem[actor_7 + 56]) | uint(c2da_mem[actor_7 + 57]) << 0x8 | uint(c2da_mem[actor_7 + 58]) << 0x10 | uint(c2da_mem[actor_7 + 59]) << 0x18) & uint(7 << 29)
    let c2da_fresh88 : uint = c2da_fresh87
    c2da_mem[actor_7 + 56] = uint8(c2da_fresh88)
    c2da_mem[actor_7 + 57] = uint8(c2da_fresh88 >> 0x8)
    c2da_mem[actor_7 + 58] = uint8(c2da_fresh88 >> 0x10)
    c2da_mem[actor_7 + 59] = uint8(c2da_fresh88 >> 0x18)
    delta = int((uint(c2da_mem[actor_7 + 56]) | uint(c2da_mem[actor_7 + 57]) << 0x8 | uint(c2da_mem[actor_7 + 58]) << 0x10 | uint(c2da_mem[actor_7 + 59]) << 0x18) - uint(int(uint(c2da_mem[actor_7 + 168]) | uint(c2da_mem[actor_7 + 169]) << 0x8 | uint(c2da_mem[actor_7 + 170]) << 0x10 | uint(c2da_mem[actor_7 + 171]) << 0x18) << 29))
    if (delta > 0) {
        goto label 26
    }
    if (delta < 0) {
        goto label 25
    }
    label 23:
    label 24:
    goto label 2
    label 25:
    let c2da_fresh91 : uint = (uint(c2da_mem[actor_7 + 56]) | uint(c2da_mem[actor_7 + 57]) << 0x8 | uint(c2da_mem[actor_7 + 58]) << 0x10 | uint(c2da_mem[actor_7 + 59]) << 0x18) + uint(1073741824 / 2)
    let c2da_fresh92 : uint = c2da_fresh91
    c2da_mem[actor_7 + 56] = uint8(c2da_fresh92)
    c2da_mem[actor_7 + 57] = uint8(c2da_fresh92 >> 0x8)
    c2da_mem[actor_7 + 58] = uint8(c2da_fresh92 >> 0x10)
    c2da_mem[actor_7 + 59] = uint8(c2da_fresh92 >> 0x18)
    goto label 23
    label 26:
    let c2da_fresh89 : uint = (uint(c2da_mem[actor_7 + 56]) | uint(c2da_mem[actor_7 + 57]) << 0x8 | uint(c2da_mem[actor_7 + 58]) << 0x10 | uint(c2da_mem[actor_7 + 59]) << 0x18) - uint(1073741824 / 2)
    let c2da_fresh90 : uint = c2da_fresh89
    c2da_mem[actor_7 + 56] = uint8(c2da_fresh90)
    c2da_mem[actor_7 + 57] = uint8(c2da_fresh90 >> 0x8)
    c2da_mem[actor_7 + 58] = uint8(c2da_fresh90 >> 0x10)
    c2da_mem[actor_7 + 59] = uint8(c2da_fresh90 >> 0x18)
    goto label 24
    label 27:
    c2da_fresh94 = 1
    if (!(int(uint(c2da_mem[actor_7 + 176]) | uint(c2da_mem[actor_7 + 177]) << 0x8 | uint(c2da_mem[actor_7 + 178]) << 0x10 | uint(c2da_mem[actor_7 + 179]) << 0x18) == 0)) {
        let c2da_fresh80 : int = int(uint(c2da_mem[actor_7 + 176]) | uint(c2da_mem[actor_7 + 177]) << 0x8 | uint(c2da_mem[actor_7 + 178]) << 0x10 | uint(c2da_mem[actor_7 + 179]) << 0x18) + 164
        if (!(int(uint(c2da_mem[c2da_fresh80]) | uint(c2da_mem[c2da_fresh80 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh80 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh80 + 3]) << 0x18) <= 0)) {
            c2da_fresh94 = 0
        }
    }
    if (c2da_fresh94 != 0) {
        goto label 29
    }
    let c2da_fresh84 : int = int(uint(c2da_mem[actor_7 + 188]) | uint(c2da_mem[actor_7 + 189]) << 0x8 | uint(c2da_mem[actor_7 + 190]) << 0x10 | uint(c2da_mem[actor_7 + 191]) << 0x18)
    let c2da_fresh85 : int = c2da_fresh84 - 1
    let c2da_fresh86 : uint = uint(c2da_fresh85)
    c2da_mem[actor_7 + 188] = uint8(c2da_fresh86)
    c2da_mem[actor_7 + 189] = uint8(c2da_fresh86 >> 0x8)
    c2da_mem[actor_7 + 190] = uint8(c2da_fresh86 >> 0x10)
    c2da_mem[actor_7 + 191] = uint8(c2da_fresh86 >> 0x18)
    label 28:
    goto label 1
    label 29:
    let c2da_fresh82 : int = 0
    let c2da_fresh83 : uint = uint(c2da_fresh82)
    c2da_mem[actor_7 + 188] = uint8(c2da_fresh83)
    c2da_mem[actor_7 + 189] = uint8(c2da_fresh83 >> 0x8)
    c2da_mem[actor_7 + 190] = uint8(c2da_fresh83 >> 0x10)
    c2da_mem[actor_7 + 191] = uint8(c2da_fresh83 >> 0x18)
    goto label 28
    label 30:
    let c2da_fresh77 : int = int(uint(c2da_mem[actor_7 + 184]) | uint(c2da_mem[actor_7 + 185]) << 0x8 | uint(c2da_mem[actor_7 + 186]) << 0x10 | uint(c2da_mem[actor_7 + 187]) << 0x18)
    let c2da_fresh78 : int = c2da_fresh77 - 1
    let c2da_fresh79 : uint = uint(c2da_fresh78)
    c2da_mem[actor_7 + 184] = uint8(c2da_fresh79)
    c2da_mem[actor_7 + 185] = uint8(c2da_fresh79 >> 0x8)
    c2da_mem[actor_7 + 186] = uint8(c2da_fresh79 >> 0x10)
    c2da_mem[actor_7 + 187] = uint8(c2da_fresh79 >> 0x18)
    goto label 0
    panic("unreachable: fell out of a translated control-flow graph")
}
[export, sideeffects]
def A_FaceTarget(var actor_8 : int) {
    if (int(uint(c2da_mem[actor_8 + 176]) | uint(c2da_mem[actor_8 + 177]) << 0x8 | uint(c2da_mem[actor_8 + 178]) << 0x10 | uint(c2da_mem[actor_8 + 179]) << 0x18) == 0) {
        return
    }
    let c2da_fresh111 : int = int(uint(c2da_mem[actor_8 + 160]) | uint(c2da_mem[actor_8 + 161]) << 0x8 | uint(c2da_mem[actor_8 + 162]) << 0x10 | uint(c2da_mem[actor_8 + 163]) << 0x18) & ~32
    let c2da_fresh112 : uint = uint(c2da_fresh111)
    c2da_mem[actor_8 + 160] = uint8(c2da_fresh112)
    c2da_mem[actor_8 + 161] = uint8(c2da_fresh112 >> 0x8)
    c2da_mem[actor_8 + 162] = uint8(c2da_fresh112 >> 0x10)
    c2da_mem[actor_8 + 163] = uint8(c2da_fresh112 >> 0x18)
    let c2da_fresh113 : int = int(uint(c2da_mem[actor_8 + 176]) | uint(c2da_mem[actor_8 + 177]) << 0x8 | uint(c2da_mem[actor_8 + 178]) << 0x10 | uint(c2da_mem[actor_8 + 179]) << 0x18) + 24
    let c2da_fresh114 : int = int(uint(c2da_mem[actor_8 + 176]) | uint(c2da_mem[actor_8 + 177]) << 0x8 | uint(c2da_mem[actor_8 + 178]) << 0x10 | uint(c2da_mem[actor_8 + 179]) << 0x18) + 28
    let c2da_fresh115 : uint = R_PointToAngle2(int(uint(c2da_mem[actor_8 + 24]) | uint(c2da_mem[actor_8 + 25]) << 0x8 | uint(c2da_mem[actor_8 + 26]) << 0x10 | uint(c2da_mem[actor_8 + 27]) << 0x18), int(uint(c2da_mem[actor_8 + 28]) | uint(c2da_mem[actor_8 + 29]) << 0x8 | uint(c2da_mem[actor_8 + 30]) << 0x10 | uint(c2da_mem[actor_8 + 31]) << 0x18), int(uint(c2da_mem[c2da_fresh113]) | uint(c2da_mem[c2da_fresh113 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh113 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh113 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh114]) | uint(c2da_mem[c2da_fresh114 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh114 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh114 + 3]) << 0x18))
    let c2da_fresh116 : uint = c2da_fresh115
    c2da_mem[actor_8 + 56] = uint8(c2da_fresh116)
    c2da_mem[actor_8 + 57] = uint8(c2da_fresh116 >> 0x8)
    c2da_mem[actor_8 + 58] = uint8(c2da_fresh116 >> 0x10)
    c2da_mem[actor_8 + 59] = uint8(c2da_fresh116 >> 0x18)
    let c2da_fresh117 : int = int(uint(c2da_mem[actor_8 + 176]) | uint(c2da_mem[actor_8 + 177]) << 0x8 | uint(c2da_mem[actor_8 + 178]) << 0x10 | uint(c2da_mem[actor_8 + 179]) << 0x18) + 160
    if ((int(uint(c2da_mem[c2da_fresh117]) | uint(c2da_mem[c2da_fresh117 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh117 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh117 + 3]) << 0x18) & 262144) != 0) {
        let c2da_fresh118 : uint = (uint(c2da_mem[actor_8 + 56]) | uint(c2da_mem[actor_8 + 57]) << 0x8 | uint(c2da_mem[actor_8 + 58]) << 0x10 | uint(c2da_mem[actor_8 + 59]) << 0x18) + uint(P_Random() - P_Random() << 21)
        let c2da_fresh119 : uint = c2da_fresh118
        c2da_mem[actor_8 + 56] = uint8(c2da_fresh119)
        c2da_mem[actor_8 + 57] = uint8(c2da_fresh119 >> 0x8)
        c2da_mem[actor_8 + 58] = uint8(c2da_fresh119 >> 0x10)
        c2da_mem[actor_8 + 59] = uint8(c2da_fresh119 >> 0x18)
    }
    return
}
[export, sideeffects]
def A_PosAttack(var actor_9 : int) {
    var angle : int
    var damage : int
    var slope : int
    if (int(uint(c2da_mem[actor_9 + 176]) | uint(c2da_mem[actor_9 + 177]) << 0x8 | uint(c2da_mem[actor_9 + 178]) << 0x10 | uint(c2da_mem[actor_9 + 179]) << 0x18) == 0) {
        return
    }
    A_FaceTarget(actor_9)
    angle = int(uint(c2da_mem[actor_9 + 56]) | uint(c2da_mem[actor_9 + 57]) << 0x8 | uint(c2da_mem[actor_9 + 58]) << 0x10 | uint(c2da_mem[actor_9 + 59]) << 0x18)
    slope = P_AimLineAttack(actor_9, uint(angle), 32 * 64 * (1 << 16))
    S_StartSound(actor_9, 1)
    angle = angle + (P_Random() - P_Random() << 20)
    damage = (P_Random() % 5 + 1) * 3
    P_LineAttack(actor_9, uint(angle), 32 * 64 * (1 << 16), slope, damage)
    return
}
[export, sideeffects]
def A_SPosAttack(var actor_10 : int) {
    var angle_0 : int
    var bangle : int
    var damage_0 : int
    var slope_0 : int
    if (int(uint(c2da_mem[actor_10 + 176]) | uint(c2da_mem[actor_10 + 177]) << 0x8 | uint(c2da_mem[actor_10 + 178]) << 0x10 | uint(c2da_mem[actor_10 + 179]) << 0x18) == 0) {
        return
    }
    S_StartSound(actor_10, 2)
    A_FaceTarget(actor_10)
    bangle = int(uint(c2da_mem[actor_10 + 56]) | uint(c2da_mem[actor_10 + 57]) << 0x8 | uint(c2da_mem[actor_10 + 58]) << 0x10 | uint(c2da_mem[actor_10 + 59]) << 0x18)
    slope_0 = P_AimLineAttack(actor_10, uint(bangle), 32 * 64 * (1 << 16))
    for (i_0 in range(0, 3)) {
        angle_0 = bangle + (P_Random() - P_Random() << 20)
        damage_0 = (P_Random() % 5 + 1) * 3
        P_LineAttack(actor_10, uint(angle_0), 32 * 64 * (1 << 16), slope_0, damage_0)
    }
    return
}
[export, sideeffects]
def A_CPosAttack(var actor_11 : int) {
    var angle_1 : int
    var bangle_0 : int
    var damage_1 : int
    var slope_1 : int
    if (int(uint(c2da_mem[actor_11 + 176]) | uint(c2da_mem[actor_11 + 177]) << 0x8 | uint(c2da_mem[actor_11 + 178]) << 0x10 | uint(c2da_mem[actor_11 + 179]) << 0x18) == 0) {
        return
    }
    S_StartSound(actor_11, 2)
    A_FaceTarget(actor_11)
    bangle_0 = int(uint(c2da_mem[actor_11 + 56]) | uint(c2da_mem[actor_11 + 57]) << 0x8 | uint(c2da_mem[actor_11 + 58]) << 0x10 | uint(c2da_mem[actor_11 + 59]) << 0x18)
    slope_1 = P_AimLineAttack(actor_11, uint(bangle_0), 32 * 64 * (1 << 16))
    angle_1 = bangle_0 + (P_Random() - P_Random() << 20)
    damage_1 = (P_Random() % 5 + 1) * 3
    P_LineAttack(actor_11, uint(angle_1), 32 * 64 * (1 << 16), slope_1, damage_1)
    return
}
[export, sideeffects]
def A_CPosRefire(var actor_12 : int) {
    A_FaceTarget(actor_12)
    if (P_Random() < 40) {
        return
    }
    var c2da_fresh121 : int = 1
    if (!(int(uint(c2da_mem[actor_12 + 176]) | uint(c2da_mem[actor_12 + 177]) << 0x8 | uint(c2da_mem[actor_12 + 178]) << 0x10 | uint(c2da_mem[actor_12 + 179]) << 0x18) == 0)) {
        let c2da_fresh120 : int = int(uint(c2da_mem[actor_12 + 176]) | uint(c2da_mem[actor_12 + 177]) << 0x8 | uint(c2da_mem[actor_12 + 178]) << 0x10 | uint(c2da_mem[actor_12 + 179]) << 0x18) + 164
        if (!(int(uint(c2da_mem[c2da_fresh120]) | uint(c2da_mem[c2da_fresh120 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh120 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh120 + 3]) << 0x18) <= 0)) {
            c2da_fresh121 = 0
        }
    }
    if (c2da_fresh121 != 0 || P_CheckSight(actor_12, int(uint(c2da_mem[actor_12 + 176]) | uint(c2da_mem[actor_12 + 177]) << 0x8 | uint(c2da_mem[actor_12 + 178]) << 0x10 | uint(c2da_mem[actor_12 + 179]) << 0x18)) == 0) {
        let c2da_fresh122 : int = int(uint(c2da_mem[actor_12 + 136]) | uint(c2da_mem[actor_12 + 137]) << 0x8 | uint(c2da_mem[actor_12 + 138]) << 0x10 | uint(c2da_mem[actor_12 + 139]) << 0x18) + 12
        P_SetMobjState(actor_12, uint(int(uint(c2da_mem[c2da_fresh122]) | uint(c2da_mem[c2da_fresh122 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh122 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh122 + 3]) << 0x18)))
    }
    return
}
[export, sideeffects]
def A_SpidRefire(var actor_13 : int) {
    A_FaceTarget(actor_13)
    if (P_Random() < 10) {
        return
    }
    var c2da_fresh124 : int = 1
    if (!(int(uint(c2da_mem[actor_13 + 176]) | uint(c2da_mem[actor_13 + 177]) << 0x8 | uint(c2da_mem[actor_13 + 178]) << 0x10 | uint(c2da_mem[actor_13 + 179]) << 0x18) == 0)) {
        let c2da_fresh123 : int = int(uint(c2da_mem[actor_13 + 176]) | uint(c2da_mem[actor_13 + 177]) << 0x8 | uint(c2da_mem[actor_13 + 178]) << 0x10 | uint(c2da_mem[actor_13 + 179]) << 0x18) + 164
        if (!(int(uint(c2da_mem[c2da_fresh123]) | uint(c2da_mem[c2da_fresh123 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh123 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh123 + 3]) << 0x18) <= 0)) {
            c2da_fresh124 = 0
        }
    }
    if (c2da_fresh124 != 0 || P_CheckSight(actor_13, int(uint(c2da_mem[actor_13 + 176]) | uint(c2da_mem[actor_13 + 177]) << 0x8 | uint(c2da_mem[actor_13 + 178]) << 0x10 | uint(c2da_mem[actor_13 + 179]) << 0x18)) == 0) {
        let c2da_fresh125 : int = int(uint(c2da_mem[actor_13 + 136]) | uint(c2da_mem[actor_13 + 137]) << 0x8 | uint(c2da_mem[actor_13 + 138]) << 0x10 | uint(c2da_mem[actor_13 + 139]) << 0x18) + 12
        P_SetMobjState(actor_13, uint(int(uint(c2da_mem[c2da_fresh125]) | uint(c2da_mem[c2da_fresh125 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh125 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh125 + 3]) << 0x18)))
    }
    return
}
[export, sideeffects]
def A_BspiAttack(var actor_14 : int) {
    if (int(uint(c2da_mem[actor_14 + 176]) | uint(c2da_mem[actor_14 + 177]) << 0x8 | uint(c2da_mem[actor_14 + 178]) << 0x10 | uint(c2da_mem[actor_14 + 179]) << 0x18) == 0) {
        return
    }
    A_FaceTarget(actor_14)
    P_SpawnMissile(actor_14, int(uint(c2da_mem[actor_14 + 176]) | uint(c2da_mem[actor_14 + 177]) << 0x8 | uint(c2da_mem[actor_14 + 178]) << 0x10 | uint(c2da_mem[actor_14 + 179]) << 0x18), 36u)
    return
}
[export, sideeffects]
def A_TroopAttack(var actor_15 : int) {
    var damage_2 : int
    if (int(uint(c2da_mem[actor_15 + 176]) | uint(c2da_mem[actor_15 + 177]) << 0x8 | uint(c2da_mem[actor_15 + 178]) << 0x10 | uint(c2da_mem[actor_15 + 179]) << 0x18) == 0) {
        return
    }
    A_FaceTarget(actor_15)
    if (P_CheckMeleeRange(actor_15) != 0x0) {
        S_StartSound(actor_15, 55)
        damage_2 = (P_Random() % 8 + 1) * 3
        P_DamageMobj(int(uint(c2da_mem[actor_15 + 176]) | uint(c2da_mem[actor_15 + 177]) << 0x8 | uint(c2da_mem[actor_15 + 178]) << 0x10 | uint(c2da_mem[actor_15 + 179]) << 0x18), actor_15, actor_15, damage_2)
        return
    }
    P_SpawnMissile(actor_15, int(uint(c2da_mem[actor_15 + 176]) | uint(c2da_mem[actor_15 + 177]) << 0x8 | uint(c2da_mem[actor_15 + 178]) << 0x10 | uint(c2da_mem[actor_15 + 179]) << 0x18), 31u)
    return
}
[export, sideeffects]
def A_SargAttack(var actor_16 : int) {
    var damage_3 : int
    if (int(uint(c2da_mem[actor_16 + 176]) | uint(c2da_mem[actor_16 + 177]) << 0x8 | uint(c2da_mem[actor_16 + 178]) << 0x10 | uint(c2da_mem[actor_16 + 179]) << 0x18) == 0) {
        return
    }
    A_FaceTarget(actor_16)
    if (P_CheckMeleeRange(actor_16) != 0x0) {
        damage_3 = (P_Random() % 10 + 1) * 4
        P_DamageMobj(int(uint(c2da_mem[actor_16 + 176]) | uint(c2da_mem[actor_16 + 177]) << 0x8 | uint(c2da_mem[actor_16 + 178]) << 0x10 | uint(c2da_mem[actor_16 + 179]) << 0x18), actor_16, actor_16, damage_3)
    }
    return
}
[export, sideeffects]
def A_HeadAttack(var actor_17 : int) {
    var damage_4 : int
    if (int(uint(c2da_mem[actor_17 + 176]) | uint(c2da_mem[actor_17 + 177]) << 0x8 | uint(c2da_mem[actor_17 + 178]) << 0x10 | uint(c2da_mem[actor_17 + 179]) << 0x18) == 0) {
        return
    }
    A_FaceTarget(actor_17)
    if (P_CheckMeleeRange(actor_17) != 0x0) {
        damage_4 = (P_Random() % 6 + 1) * 10
        P_DamageMobj(int(uint(c2da_mem[actor_17 + 176]) | uint(c2da_mem[actor_17 + 177]) << 0x8 | uint(c2da_mem[actor_17 + 178]) << 0x10 | uint(c2da_mem[actor_17 + 179]) << 0x18), actor_17, actor_17, damage_4)
        return
    }
    P_SpawnMissile(actor_17, int(uint(c2da_mem[actor_17 + 176]) | uint(c2da_mem[actor_17 + 177]) << 0x8 | uint(c2da_mem[actor_17 + 178]) << 0x10 | uint(c2da_mem[actor_17 + 179]) << 0x18), 32u)
    return
}
[export, sideeffects]
def A_CyberAttack(var actor_18 : int) {
    if (int(uint(c2da_mem[actor_18 + 176]) | uint(c2da_mem[actor_18 + 177]) << 0x8 | uint(c2da_mem[actor_18 + 178]) << 0x10 | uint(c2da_mem[actor_18 + 179]) << 0x18) == 0) {
        return
    }
    A_FaceTarget(actor_18)
    P_SpawnMissile(actor_18, int(uint(c2da_mem[actor_18 + 176]) | uint(c2da_mem[actor_18 + 177]) << 0x8 | uint(c2da_mem[actor_18 + 178]) << 0x10 | uint(c2da_mem[actor_18 + 179]) << 0x18), 33u)
    return
}
[export, sideeffects]
def A_BruisAttack(var actor_19 : int) {
    var damage_5 : int
    if (int(uint(c2da_mem[actor_19 + 176]) | uint(c2da_mem[actor_19 + 177]) << 0x8 | uint(c2da_mem[actor_19 + 178]) << 0x10 | uint(c2da_mem[actor_19 + 179]) << 0x18) == 0) {
        return
    }
    if (P_CheckMeleeRange(actor_19) != 0x0) {
        S_StartSound(actor_19, 55)
        damage_5 = (P_Random() % 8 + 1) * 10
        P_DamageMobj(int(uint(c2da_mem[actor_19 + 176]) | uint(c2da_mem[actor_19 + 177]) << 0x8 | uint(c2da_mem[actor_19 + 178]) << 0x10 | uint(c2da_mem[actor_19 + 179]) << 0x18), actor_19, actor_19, damage_5)
        return
    }
    P_SpawnMissile(actor_19, int(uint(c2da_mem[actor_19 + 176]) | uint(c2da_mem[actor_19 + 177]) << 0x8 | uint(c2da_mem[actor_19 + 178]) << 0x10 | uint(c2da_mem[actor_19 + 179]) << 0x18), 16u)
    return
}
[export, sideeffects]
def A_SkelMissile(var actor_20 : int) {
    var mo_0 : int
    if (int(uint(c2da_mem[actor_20 + 176]) | uint(c2da_mem[actor_20 + 177]) << 0x8 | uint(c2da_mem[actor_20 + 178]) << 0x10 | uint(c2da_mem[actor_20 + 179]) << 0x18) == 0) {
        return
    }
    A_FaceTarget(actor_20)
    let c2da_fresh126 : int = int(uint(c2da_mem[actor_20 + 32]) | uint(c2da_mem[actor_20 + 33]) << 0x8 | uint(c2da_mem[actor_20 + 34]) << 0x10 | uint(c2da_mem[actor_20 + 35]) << 0x18) + 16 * (1 << 16)
    let c2da_fresh127 : uint = uint(c2da_fresh126)
    c2da_mem[actor_20 + 32] = uint8(c2da_fresh127)
    c2da_mem[actor_20 + 33] = uint8(c2da_fresh127 >> 0x8)
    c2da_mem[actor_20 + 34] = uint8(c2da_fresh127 >> 0x10)
    c2da_mem[actor_20 + 35] = uint8(c2da_fresh127 >> 0x18)
    mo_0 = P_SpawnMissile(actor_20, int(uint(c2da_mem[actor_20 + 176]) | uint(c2da_mem[actor_20 + 177]) << 0x8 | uint(c2da_mem[actor_20 + 178]) << 0x10 | uint(c2da_mem[actor_20 + 179]) << 0x18), 6u)
    let c2da_fresh128 : int = int(uint(c2da_mem[actor_20 + 32]) | uint(c2da_mem[actor_20 + 33]) << 0x8 | uint(c2da_mem[actor_20 + 34]) << 0x10 | uint(c2da_mem[actor_20 + 35]) << 0x18) - 16 * (1 << 16)
    let c2da_fresh129 : uint = uint(c2da_fresh128)
    c2da_mem[actor_20 + 32] = uint8(c2da_fresh129)
    c2da_mem[actor_20 + 33] = uint8(c2da_fresh129 >> 0x8)
    c2da_mem[actor_20 + 34] = uint8(c2da_fresh129 >> 0x10)
    c2da_mem[actor_20 + 35] = uint8(c2da_fresh129 >> 0x18)
    let c2da_fresh130 : int = int(uint(c2da_mem[mo_0 + 24]) | uint(c2da_mem[mo_0 + 25]) << 0x8 | uint(c2da_mem[mo_0 + 26]) << 0x10 | uint(c2da_mem[mo_0 + 27]) << 0x18) + int(uint(c2da_mem[mo_0 + 112]) | uint(c2da_mem[mo_0 + 113]) << 0x8 | uint(c2da_mem[mo_0 + 114]) << 0x10 | uint(c2da_mem[mo_0 + 115]) << 0x18)
    let c2da_fresh131 : uint = uint(c2da_fresh130)
    c2da_mem[mo_0 + 24] = uint8(c2da_fresh131)
    c2da_mem[mo_0 + 25] = uint8(c2da_fresh131 >> 0x8)
    c2da_mem[mo_0 + 26] = uint8(c2da_fresh131 >> 0x10)
    c2da_mem[mo_0 + 27] = uint8(c2da_fresh131 >> 0x18)
    let c2da_fresh132 : int = int(uint(c2da_mem[mo_0 + 28]) | uint(c2da_mem[mo_0 + 29]) << 0x8 | uint(c2da_mem[mo_0 + 30]) << 0x10 | uint(c2da_mem[mo_0 + 31]) << 0x18) + int(uint(c2da_mem[mo_0 + 116]) | uint(c2da_mem[mo_0 + 117]) << 0x8 | uint(c2da_mem[mo_0 + 118]) << 0x10 | uint(c2da_mem[mo_0 + 119]) << 0x18)
    let c2da_fresh133 : uint = uint(c2da_fresh132)
    c2da_mem[mo_0 + 28] = uint8(c2da_fresh133)
    c2da_mem[mo_0 + 29] = uint8(c2da_fresh133 >> 0x8)
    c2da_mem[mo_0 + 30] = uint8(c2da_fresh133 >> 0x10)
    c2da_mem[mo_0 + 31] = uint8(c2da_fresh133 >> 0x18)
    let c2da_fresh134 : int = int(uint(c2da_mem[actor_20 + 176]) | uint(c2da_mem[actor_20 + 177]) << 0x8 | uint(c2da_mem[actor_20 + 178]) << 0x10 | uint(c2da_mem[actor_20 + 179]) << 0x18)
    let c2da_fresh135 : uint = uint(c2da_fresh134)
    c2da_mem[mo_0 + 216] = uint8(c2da_fresh135)
    c2da_mem[mo_0 + 217] = uint8(c2da_fresh135 >> 0x8)
    c2da_mem[mo_0 + 218] = uint8(c2da_fresh135 >> 0x10)
    c2da_mem[mo_0 + 219] = uint8(c2da_fresh135 >> 0x18)
    c2da_mem[mo_0 + 220] = 0u8
    c2da_mem[mo_0 + 221] = 0u8
    c2da_mem[mo_0 + 222] = 0u8
    c2da_mem[mo_0 + 223] = 0u8
    return
}
var TRACEANGLE : int = 201326592

[export, sideeffects]
def A_Tracer(var actor_21 : int) {
    var exact : uint
    var dist_2 : int
    var dest : int
    var th_0 : int
    if ((gametic & 3) != 0) {
        return
    }
    P_SpawnPuff(int(uint(c2da_mem[actor_21 + 24]) | uint(c2da_mem[actor_21 + 25]) << 0x8 | uint(c2da_mem[actor_21 + 26]) << 0x10 | uint(c2da_mem[actor_21 + 27]) << 0x18), int(uint(c2da_mem[actor_21 + 28]) | uint(c2da_mem[actor_21 + 29]) << 0x8 | uint(c2da_mem[actor_21 + 30]) << 0x10 | uint(c2da_mem[actor_21 + 31]) << 0x18), int(uint(c2da_mem[actor_21 + 32]) | uint(c2da_mem[actor_21 + 33]) << 0x8 | uint(c2da_mem[actor_21 + 34]) << 0x10 | uint(c2da_mem[actor_21 + 35]) << 0x18))
    th_0 = P_SpawnMobj(int(uint(c2da_mem[actor_21 + 24]) | uint(c2da_mem[actor_21 + 25]) << 0x8 | uint(c2da_mem[actor_21 + 26]) << 0x10 | uint(c2da_mem[actor_21 + 27]) << 0x18) - int(uint(c2da_mem[actor_21 + 112]) | uint(c2da_mem[actor_21 + 113]) << 0x8 | uint(c2da_mem[actor_21 + 114]) << 0x10 | uint(c2da_mem[actor_21 + 115]) << 0x18), int(uint(c2da_mem[actor_21 + 28]) | uint(c2da_mem[actor_21 + 29]) << 0x8 | uint(c2da_mem[actor_21 + 30]) << 0x10 | uint(c2da_mem[actor_21 + 31]) << 0x18) - int(uint(c2da_mem[actor_21 + 116]) | uint(c2da_mem[actor_21 + 117]) << 0x8 | uint(c2da_mem[actor_21 + 118]) << 0x10 | uint(c2da_mem[actor_21 + 119]) << 0x18), int(uint(c2da_mem[actor_21 + 32]) | uint(c2da_mem[actor_21 + 33]) << 0x8 | uint(c2da_mem[actor_21 + 34]) << 0x10 | uint(c2da_mem[actor_21 + 35]) << 0x18), 7u)
    let c2da_fresh136 : int = 1 << 16
    let c2da_fresh137 : uint = uint(c2da_fresh136)
    c2da_mem[th_0 + 120] = uint8(c2da_fresh137)
    c2da_mem[th_0 + 121] = uint8(c2da_fresh137 >> 0x8)
    c2da_mem[th_0 + 122] = uint8(c2da_fresh137 >> 0x10)
    c2da_mem[th_0 + 123] = uint8(c2da_fresh137 >> 0x18)
    let c2da_fresh138 : int = int(uint(c2da_mem[th_0 + 144]) | uint(c2da_mem[th_0 + 145]) << 0x8 | uint(c2da_mem[th_0 + 146]) << 0x10 | uint(c2da_mem[th_0 + 147]) << 0x18) - int(P_Random() & 3)
    let c2da_fresh139 : uint = uint(c2da_fresh138)
    c2da_mem[th_0 + 144] = uint8(c2da_fresh139)
    c2da_mem[th_0 + 145] = uint8(c2da_fresh139 >> 0x8)
    c2da_mem[th_0 + 146] = uint8(c2da_fresh139 >> 0x10)
    c2da_mem[th_0 + 147] = uint8(c2da_fresh139 >> 0x18)
    if (int(uint(c2da_mem[th_0 + 144]) | uint(c2da_mem[th_0 + 145]) << 0x8 | uint(c2da_mem[th_0 + 146]) << 0x10 | uint(c2da_mem[th_0 + 147]) << 0x18) < 1) {
        let c2da_fresh140 : int = 1
        let c2da_fresh141 : uint = uint(c2da_fresh140)
        c2da_mem[th_0 + 144] = uint8(c2da_fresh141)
        c2da_mem[th_0 + 145] = uint8(c2da_fresh141 >> 0x8)
        c2da_mem[th_0 + 146] = uint8(c2da_fresh141 >> 0x10)
        c2da_mem[th_0 + 147] = uint8(c2da_fresh141 >> 0x18)
    }
    dest = int(uint(c2da_mem[actor_21 + 216]) | uint(c2da_mem[actor_21 + 217]) << 0x8 | uint(c2da_mem[actor_21 + 218]) << 0x10 | uint(c2da_mem[actor_21 + 219]) << 0x18)
    if (dest == 0 || int(uint(c2da_mem[dest + 164]) | uint(c2da_mem[dest + 165]) << 0x8 | uint(c2da_mem[dest + 166]) << 0x10 | uint(c2da_mem[dest + 167]) << 0x18) <= 0) {
        return
    }
    exact = uint(R_PointToAngle2(int(uint(c2da_mem[actor_21 + 24]) | uint(c2da_mem[actor_21 + 25]) << 0x8 | uint(c2da_mem[actor_21 + 26]) << 0x10 | uint(c2da_mem[actor_21 + 27]) << 0x18), int(uint(c2da_mem[actor_21 + 28]) | uint(c2da_mem[actor_21 + 29]) << 0x8 | uint(c2da_mem[actor_21 + 30]) << 0x10 | uint(c2da_mem[actor_21 + 31]) << 0x18), int(uint(c2da_mem[dest + 24]) | uint(c2da_mem[dest + 25]) << 0x8 | uint(c2da_mem[dest + 26]) << 0x10 | uint(c2da_mem[dest + 27]) << 0x18), int(uint(c2da_mem[dest + 28]) | uint(c2da_mem[dest + 29]) << 0x8 | uint(c2da_mem[dest + 30]) << 0x10 | uint(c2da_mem[dest + 31]) << 0x18)))
    if (exact != (uint(c2da_mem[actor_21 + 56]) | uint(c2da_mem[actor_21 + 57]) << 0x8 | uint(c2da_mem[actor_21 + 58]) << 0x10 | uint(c2da_mem[actor_21 + 59]) << 0x18)) {
        if (exact - (uint(c2da_mem[actor_21 + 56]) | uint(c2da_mem[actor_21 + 57]) << 0x8 | uint(c2da_mem[actor_21 + 58]) << 0x10 | uint(c2da_mem[actor_21 + 59]) << 0x18) > 0x80000000u) {
            let c2da_fresh142 : uint = (uint(c2da_mem[actor_21 + 56]) | uint(c2da_mem[actor_21 + 57]) << 0x8 | uint(c2da_mem[actor_21 + 58]) << 0x10 | uint(c2da_mem[actor_21 + 59]) << 0x18) - uint(TRACEANGLE)
            let c2da_fresh143 : uint = c2da_fresh142
            c2da_mem[actor_21 + 56] = uint8(c2da_fresh143)
            c2da_mem[actor_21 + 57] = uint8(c2da_fresh143 >> 0x8)
            c2da_mem[actor_21 + 58] = uint8(c2da_fresh143 >> 0x10)
            c2da_mem[actor_21 + 59] = uint8(c2da_fresh143 >> 0x18)
            if (exact - (uint(c2da_mem[actor_21 + 56]) | uint(c2da_mem[actor_21 + 57]) << 0x8 | uint(c2da_mem[actor_21 + 58]) << 0x10 | uint(c2da_mem[actor_21 + 59]) << 0x18) < 0x80000000u) {
                let c2da_fresh144 : uint = exact
                c2da_mem[actor_21 + 56] = uint8(c2da_fresh144)
                c2da_mem[actor_21 + 57] = uint8(c2da_fresh144 >> 0x8)
                c2da_mem[actor_21 + 58] = uint8(c2da_fresh144 >> 0x10)
                c2da_mem[actor_21 + 59] = uint8(c2da_fresh144 >> 0x18)
            }
        } else {
            let c2da_fresh145 : uint = (uint(c2da_mem[actor_21 + 56]) | uint(c2da_mem[actor_21 + 57]) << 0x8 | uint(c2da_mem[actor_21 + 58]) << 0x10 | uint(c2da_mem[actor_21 + 59]) << 0x18) + uint(TRACEANGLE)
            let c2da_fresh146 : uint = c2da_fresh145
            c2da_mem[actor_21 + 56] = uint8(c2da_fresh146)
            c2da_mem[actor_21 + 57] = uint8(c2da_fresh146 >> 0x8)
            c2da_mem[actor_21 + 58] = uint8(c2da_fresh146 >> 0x10)
            c2da_mem[actor_21 + 59] = uint8(c2da_fresh146 >> 0x18)
            if (exact - (uint(c2da_mem[actor_21 + 56]) | uint(c2da_mem[actor_21 + 57]) << 0x8 | uint(c2da_mem[actor_21 + 58]) << 0x10 | uint(c2da_mem[actor_21 + 59]) << 0x18) > 0x80000000u) {
                let c2da_fresh147 : uint = exact
                c2da_mem[actor_21 + 56] = uint8(c2da_fresh147)
                c2da_mem[actor_21 + 57] = uint8(c2da_fresh147 >> 0x8)
                c2da_mem[actor_21 + 58] = uint8(c2da_fresh147 >> 0x10)
                c2da_mem[actor_21 + 59] = uint8(c2da_fresh147 >> 0x18)
            }
        }
    }
    exact = (uint(c2da_mem[actor_21 + 56]) | uint(c2da_mem[actor_21 + 57]) << 0x8 | uint(c2da_mem[actor_21 + 58]) << 0x10 | uint(c2da_mem[actor_21 + 59]) << 0x18) >> 19u
    let c2da_fresh148 : int = int(uint(c2da_mem[actor_21 + 136]) | uint(c2da_mem[actor_21 + 137]) << 0x8 | uint(c2da_mem[actor_21 + 138]) << 0x10 | uint(c2da_mem[actor_21 + 139]) << 0x18) + 60
    let c2da_fresh149 : int = FixedMul(int(uint(c2da_mem[c2da_fresh148]) | uint(c2da_mem[c2da_fresh148 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh148 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh148 + 3]) << 0x18), int(uint(c2da_mem[finecosine + int(exact) * 4]) | uint(c2da_mem[finecosine + int(exact) * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + int(exact) * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + int(exact) * 4 + 3]) << 0x18))
    let c2da_fresh150 : uint = uint(c2da_fresh149)
    c2da_mem[actor_21 + 112] = uint8(c2da_fresh150)
    c2da_mem[actor_21 + 113] = uint8(c2da_fresh150 >> 0x8)
    c2da_mem[actor_21 + 114] = uint8(c2da_fresh150 >> 0x10)
    c2da_mem[actor_21 + 115] = uint8(c2da_fresh150 >> 0x18)
    let c2da_fresh151 : int = int(uint(c2da_mem[actor_21 + 136]) | uint(c2da_mem[actor_21 + 137]) << 0x8 | uint(c2da_mem[actor_21 + 138]) << 0x10 | uint(c2da_mem[actor_21 + 139]) << 0x18) + 60
    let c2da_fresh152 : int = FixedMul(int(uint(c2da_mem[c2da_fresh151]) | uint(c2da_mem[c2da_fresh151 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh151 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh151 + 3]) << 0x18), int(uint(c2da_mem[257920 + int(exact) * 4]) | uint(c2da_mem[257920 + int(exact) * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + int(exact) * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + int(exact) * 4 + 3]) << 0x18))
    let c2da_fresh153 : uint = uint(c2da_fresh152)
    c2da_mem[actor_21 + 116] = uint8(c2da_fresh153)
    c2da_mem[actor_21 + 117] = uint8(c2da_fresh153 >> 0x8)
    c2da_mem[actor_21 + 118] = uint8(c2da_fresh153 >> 0x10)
    c2da_mem[actor_21 + 119] = uint8(c2da_fresh153 >> 0x18)
    dist_2 = P_AproxDistance(int(uint(c2da_mem[dest + 24]) | uint(c2da_mem[dest + 25]) << 0x8 | uint(c2da_mem[dest + 26]) << 0x10 | uint(c2da_mem[dest + 27]) << 0x18) - int(uint(c2da_mem[actor_21 + 24]) | uint(c2da_mem[actor_21 + 25]) << 0x8 | uint(c2da_mem[actor_21 + 26]) << 0x10 | uint(c2da_mem[actor_21 + 27]) << 0x18), int(uint(c2da_mem[dest + 28]) | uint(c2da_mem[dest + 29]) << 0x8 | uint(c2da_mem[dest + 30]) << 0x10 | uint(c2da_mem[dest + 31]) << 0x18) - int(uint(c2da_mem[actor_21 + 28]) | uint(c2da_mem[actor_21 + 29]) << 0x8 | uint(c2da_mem[actor_21 + 30]) << 0x10 | uint(c2da_mem[actor_21 + 31]) << 0x18))
    let c2da_fresh154 : int = int(uint(c2da_mem[actor_21 + 136]) | uint(c2da_mem[actor_21 + 137]) << 0x8 | uint(c2da_mem[actor_21 + 138]) << 0x10 | uint(c2da_mem[actor_21 + 139]) << 0x18) + 60
    dist_2 /= int(uint(c2da_mem[c2da_fresh154]) | uint(c2da_mem[c2da_fresh154 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh154 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh154 + 3]) << 0x18)
    if (dist_2 < 1) {
        dist_2 = 1
    }
    if ((int(uint(c2da_mem[dest + 32]) | uint(c2da_mem[dest + 33]) << 0x8 | uint(c2da_mem[dest + 34]) << 0x10 | uint(c2da_mem[dest + 35]) << 0x18) + 40 * (1 << 16) - int(uint(c2da_mem[actor_21 + 32]) | uint(c2da_mem[actor_21 + 33]) << 0x8 | uint(c2da_mem[actor_21 + 34]) << 0x10 | uint(c2da_mem[actor_21 + 35]) << 0x18)) / dist_2 < int(uint(c2da_mem[actor_21 + 120]) | uint(c2da_mem[actor_21 + 121]) << 0x8 | uint(c2da_mem[actor_21 + 122]) << 0x10 | uint(c2da_mem[actor_21 + 123]) << 0x18)) {
        let c2da_fresh155 : int = int(uint(c2da_mem[actor_21 + 120]) | uint(c2da_mem[actor_21 + 121]) << 0x8 | uint(c2da_mem[actor_21 + 122]) << 0x10 | uint(c2da_mem[actor_21 + 123]) << 0x18) - (1 << 16) / 8
        let c2da_fresh156 : uint = uint(c2da_fresh155)
        c2da_mem[actor_21 + 120] = uint8(c2da_fresh156)
        c2da_mem[actor_21 + 121] = uint8(c2da_fresh156 >> 0x8)
        c2da_mem[actor_21 + 122] = uint8(c2da_fresh156 >> 0x10)
        c2da_mem[actor_21 + 123] = uint8(c2da_fresh156 >> 0x18)
    } else {
        let c2da_fresh157 : int = int(uint(c2da_mem[actor_21 + 120]) | uint(c2da_mem[actor_21 + 121]) << 0x8 | uint(c2da_mem[actor_21 + 122]) << 0x10 | uint(c2da_mem[actor_21 + 123]) << 0x18) + (1 << 16) / 8
        let c2da_fresh158 : uint = uint(c2da_fresh157)
        c2da_mem[actor_21 + 120] = uint8(c2da_fresh158)
        c2da_mem[actor_21 + 121] = uint8(c2da_fresh158 >> 0x8)
        c2da_mem[actor_21 + 122] = uint8(c2da_fresh158 >> 0x10)
        c2da_mem[actor_21 + 123] = uint8(c2da_fresh158 >> 0x18)
    }
    return
}
[export, sideeffects]
def A_SkelWhoosh(var actor_22 : int) {
    if (int(uint(c2da_mem[actor_22 + 176]) | uint(c2da_mem[actor_22 + 177]) << 0x8 | uint(c2da_mem[actor_22 + 178]) << 0x10 | uint(c2da_mem[actor_22 + 179]) << 0x18) == 0) {
        return
    }
    A_FaceTarget(actor_22)
    S_StartSound(actor_22, 56)
    return
}
[export, sideeffects]
def A_SkelFist(var actor_23 : int) {
    var damage_6 : int
    if (int(uint(c2da_mem[actor_23 + 176]) | uint(c2da_mem[actor_23 + 177]) << 0x8 | uint(c2da_mem[actor_23 + 178]) << 0x10 | uint(c2da_mem[actor_23 + 179]) << 0x18) == 0) {
        return
    }
    A_FaceTarget(actor_23)
    if (P_CheckMeleeRange(actor_23) != 0x0) {
        damage_6 = (P_Random() % 10 + 1) * 6
        S_StartSound(actor_23, 53)
        P_DamageMobj(int(uint(c2da_mem[actor_23 + 176]) | uint(c2da_mem[actor_23 + 177]) << 0x8 | uint(c2da_mem[actor_23 + 178]) << 0x10 | uint(c2da_mem[actor_23 + 179]) << 0x18), actor_23, actor_23, damage_6)
    }
    return
}
var corpsehit : int = default<int>

var vileobj : int = default<int>

var viletryx : int = default<int>

var viletryy : int = default<int>

[export, sideeffects]
def PIT_VileCheck(var thing : int) : uint {
    var maxdist : int
    var check_0 : uint
    if ((int(uint(c2da_mem[thing + 160]) | uint(c2da_mem[thing + 161]) << 0x8 | uint(c2da_mem[thing + 162]) << 0x10 | uint(c2da_mem[thing + 163]) << 0x18) & 1048576) == 0) {
        return 1u
    }
    if (int(uint(c2da_mem[thing + 144]) | uint(c2da_mem[thing + 145]) << 0x8 | uint(c2da_mem[thing + 146]) << 0x10 | uint(c2da_mem[thing + 147]) << 0x18) != -1) {
        return 1u
    }
    let c2da_fresh159 : int = int(uint(c2da_mem[thing + 136]) | uint(c2da_mem[thing + 137]) << 0x8 | uint(c2da_mem[thing + 138]) << 0x10 | uint(c2da_mem[thing + 139]) << 0x18) + 88
    if (int(uint(c2da_mem[c2da_fresh159]) | uint(c2da_mem[c2da_fresh159 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh159 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh159 + 3]) << 0x18) == 0) {
        return 1u
    }
    let c2da_fresh160 : int = int(uint(c2da_mem[thing + 136]) | uint(c2da_mem[thing + 137]) << 0x8 | uint(c2da_mem[thing + 138]) << 0x10 | uint(c2da_mem[thing + 139]) << 0x18) + 64
    maxdist = int(uint(c2da_mem[c2da_fresh160]) | uint(c2da_mem[c2da_fresh160 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh160 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh160 + 3]) << 0x18) + int(uint(c2da_mem[51056 + 3 * 92 + 64]) | uint(c2da_mem[51056 + 3 * 92 + 65]) << 0x8 | uint(c2da_mem[51056 + 3 * 92 + 66]) << 0x10 | uint(c2da_mem[51056 + 3 * 92 + 67]) << 0x18)
    if (c2da_std_abs(int(uint(c2da_mem[thing + 24]) | uint(c2da_mem[thing + 25]) << 0x8 | uint(c2da_mem[thing + 26]) << 0x10 | uint(c2da_mem[thing + 27]) << 0x18) - viletryx) > maxdist || c2da_std_abs(int(uint(c2da_mem[thing + 28]) | uint(c2da_mem[thing + 29]) << 0x8 | uint(c2da_mem[thing + 30]) << 0x10 | uint(c2da_mem[thing + 31]) << 0x18) - viletryy) > maxdist) {
        return 1u
    }
    corpsehit = int(thing)  // nolint:PERF020
    let c2da_fresh161 : int = 0
    let c2da_fresh162 : uint = uint(c2da_fresh161)
    c2da_mem[corpsehit + 116] = uint8(c2da_fresh162)
    c2da_mem[corpsehit + 117] = uint8(c2da_fresh162 >> 0x8)
    c2da_mem[corpsehit + 118] = uint8(c2da_fresh162 >> 0x10)
    c2da_mem[corpsehit + 119] = uint8(c2da_fresh162 >> 0x18)
    let c2da_fresh163 : uint = uint(c2da_fresh161)
    c2da_mem[corpsehit + 112] = uint8(c2da_fresh163)
    c2da_mem[corpsehit + 113] = uint8(c2da_fresh163 >> 0x8)
    c2da_mem[corpsehit + 114] = uint8(c2da_fresh163 >> 0x10)
    c2da_mem[corpsehit + 115] = uint8(c2da_fresh163 >> 0x18)
    let c2da_fresh164 : int = int(uint(c2da_mem[corpsehit + 108]) | uint(c2da_mem[corpsehit + 109]) << 0x8 | uint(c2da_mem[corpsehit + 110]) << 0x10 | uint(c2da_mem[corpsehit + 111]) << 0x18) << 2
    let c2da_fresh165 : uint = uint(c2da_fresh164)
    c2da_mem[corpsehit + 108] = uint8(c2da_fresh165)
    c2da_mem[corpsehit + 109] = uint8(c2da_fresh165 >> 0x8)
    c2da_mem[corpsehit + 110] = uint8(c2da_fresh165 >> 0x10)
    c2da_mem[corpsehit + 111] = uint8(c2da_fresh165 >> 0x18)
    check_0 = uint(P_CheckPosition(corpsehit, int(uint(c2da_mem[corpsehit + 24]) | uint(c2da_mem[corpsehit + 25]) << 0x8 | uint(c2da_mem[corpsehit + 26]) << 0x10 | uint(c2da_mem[corpsehit + 27]) << 0x18), int(uint(c2da_mem[corpsehit + 28]) | uint(c2da_mem[corpsehit + 29]) << 0x8 | uint(c2da_mem[corpsehit + 30]) << 0x10 | uint(c2da_mem[corpsehit + 31]) << 0x18)))
    let c2da_fresh166 : int = int(uint(c2da_mem[corpsehit + 108]) | uint(c2da_mem[corpsehit + 109]) << 0x8 | uint(c2da_mem[corpsehit + 110]) << 0x10 | uint(c2da_mem[corpsehit + 111]) << 0x18) >> 2
    let c2da_fresh167 : uint = uint(c2da_fresh166)
    c2da_mem[corpsehit + 108] = uint8(c2da_fresh167)
    c2da_mem[corpsehit + 109] = uint8(c2da_fresh167 >> 0x8)
    c2da_mem[corpsehit + 110] = uint8(c2da_fresh167 >> 0x10)
    c2da_mem[corpsehit + 111] = uint8(c2da_fresh167 >> 0x18)
    if (check_0 == 0) {
        return 1u
    }
    return 0u
}
[export, sideeffects]
def A_VileChase(var actor_24 : int) {
    var xl : int
    var xh : int
    var yl : int
    var yh : int
    var bx : int
    var by : int
    var info : int
    var temp : int
    if (int(uint(c2da_mem[actor_24 + 168]) | uint(c2da_mem[actor_24 + 169]) << 0x8 | uint(c2da_mem[actor_24 + 170]) << 0x10 | uint(c2da_mem[actor_24 + 171]) << 0x18) != 8) {
        let c2da_fresh168 : int = int(uint(c2da_mem[actor_24 + 136]) | uint(c2da_mem[actor_24 + 137]) << 0x8 | uint(c2da_mem[actor_24 + 138]) << 0x10 | uint(c2da_mem[actor_24 + 139]) << 0x18) + 60
        viletryx = int(uint(c2da_mem[actor_24 + 24]) | uint(c2da_mem[actor_24 + 25]) << 0x8 | uint(c2da_mem[actor_24 + 26]) << 0x10 | uint(c2da_mem[actor_24 + 27]) << 0x18) + int(uint(c2da_mem[c2da_fresh168]) | uint(c2da_mem[c2da_fresh168 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh168 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh168 + 3]) << 0x18) * xspeed[int(uint(c2da_mem[actor_24 + 168]) | uint(c2da_mem[actor_24 + 169]) << 0x8 | uint(c2da_mem[actor_24 + 170]) << 0x10 | uint(c2da_mem[actor_24 + 171]) << 0x18)]
        let c2da_fresh169 : int = int(uint(c2da_mem[actor_24 + 136]) | uint(c2da_mem[actor_24 + 137]) << 0x8 | uint(c2da_mem[actor_24 + 138]) << 0x10 | uint(c2da_mem[actor_24 + 139]) << 0x18) + 60
        viletryy = int(uint(c2da_mem[actor_24 + 28]) | uint(c2da_mem[actor_24 + 29]) << 0x8 | uint(c2da_mem[actor_24 + 30]) << 0x10 | uint(c2da_mem[actor_24 + 31]) << 0x18) + int(uint(c2da_mem[c2da_fresh169]) | uint(c2da_mem[c2da_fresh169 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh169 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh169 + 3]) << 0x18) * yspeed[int(uint(c2da_mem[actor_24 + 168]) | uint(c2da_mem[actor_24 + 169]) << 0x8 | uint(c2da_mem[actor_24 + 170]) << 0x10 | uint(c2da_mem[actor_24 + 171]) << 0x18)]
        xl = viletryx - int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18) - 32 * (1 << 16) * 2 >> 16 + 7
        xh = viletryx - int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18) + 32 * (1 << 16) * 2 >> 16 + 7
        yl = viletryy - int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18) - 32 * (1 << 16) * 2 >> 16 + 7
        yh = viletryy - int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18) + 32 * (1 << 16) * 2 >> 16 + 7
        vileobj = int(actor_24)  // nolint:PERF020
        bx = xl
        while (bx <= xh) {
            by = yl
            while (by <= yh) {
                if (P_BlockThingsIterator(bx, by, 127) == 0) {
                    temp = int(uint(c2da_mem[actor_24 + 176]) | uint(c2da_mem[actor_24 + 177]) << 0x8 | uint(c2da_mem[actor_24 + 178]) << 0x10 | uint(c2da_mem[actor_24 + 179]) << 0x18)
                    let c2da_fresh170 : uint = uint(corpsehit)
                    c2da_mem[actor_24 + 176] = uint8(c2da_fresh170)
                    c2da_mem[actor_24 + 177] = uint8(c2da_fresh170 >> 0x8)
                    c2da_mem[actor_24 + 178] = uint8(c2da_fresh170 >> 0x10)
                    c2da_mem[actor_24 + 179] = uint8(c2da_fresh170 >> 0x18)
                    c2da_mem[actor_24 + 180] = 0u8
                    c2da_mem[actor_24 + 181] = 0u8
                    c2da_mem[actor_24 + 182] = 0u8
                    c2da_mem[actor_24 + 183] = 0u8
                    A_FaceTarget(actor_24)
                    let c2da_fresh171 : uint = uint(temp)
                    c2da_mem[actor_24 + 176] = uint8(c2da_fresh171)
                    c2da_mem[actor_24 + 177] = uint8(c2da_fresh171 >> 0x8)
                    c2da_mem[actor_24 + 178] = uint8(c2da_fresh171 >> 0x10)
                    c2da_mem[actor_24 + 179] = uint8(c2da_fresh171 >> 0x18)
                    c2da_mem[actor_24 + 180] = 0u8
                    c2da_mem[actor_24 + 181] = 0u8
                    c2da_mem[actor_24 + 182] = 0u8
                    c2da_mem[actor_24 + 183] = 0u8
                    P_SetMobjState(actor_24, 266u)
                    S_StartSound(corpsehit, 31)
                    info = int(uint(c2da_mem[corpsehit + 136]) | uint(c2da_mem[corpsehit + 137]) << 0x8 | uint(c2da_mem[corpsehit + 138]) << 0x10 | uint(c2da_mem[corpsehit + 139]) << 0x18)
                    P_SetMobjState(corpsehit, uint(int(uint(c2da_mem[info + 88]) | uint(c2da_mem[info + 89]) << 0x8 | uint(c2da_mem[info + 90]) << 0x10 | uint(c2da_mem[info + 91]) << 0x18)))
                    let c2da_fresh172 : int = int(uint(c2da_mem[corpsehit + 108]) | uint(c2da_mem[corpsehit + 109]) << 0x8 | uint(c2da_mem[corpsehit + 110]) << 0x10 | uint(c2da_mem[corpsehit + 111]) << 0x18) << 2
                    let c2da_fresh173 : uint = uint(c2da_fresh172)
                    c2da_mem[corpsehit + 108] = uint8(c2da_fresh173)
                    c2da_mem[corpsehit + 109] = uint8(c2da_fresh173 >> 0x8)
                    c2da_mem[corpsehit + 110] = uint8(c2da_fresh173 >> 0x10)
                    c2da_mem[corpsehit + 111] = uint8(c2da_fresh173 >> 0x18)
                    let c2da_fresh174 : int = int(uint(c2da_mem[info + 84]) | uint(c2da_mem[info + 85]) << 0x8 | uint(c2da_mem[info + 86]) << 0x10 | uint(c2da_mem[info + 87]) << 0x18)
                    let c2da_fresh175 : uint = uint(c2da_fresh174)
                    c2da_mem[corpsehit + 160] = uint8(c2da_fresh175)
                    c2da_mem[corpsehit + 161] = uint8(c2da_fresh175 >> 0x8)
                    c2da_mem[corpsehit + 162] = uint8(c2da_fresh175 >> 0x10)
                    c2da_mem[corpsehit + 163] = uint8(c2da_fresh175 >> 0x18)
                    let c2da_fresh176 : int = int(uint(c2da_mem[info + 8]) | uint(c2da_mem[info + 9]) << 0x8 | uint(c2da_mem[info + 10]) << 0x10 | uint(c2da_mem[info + 11]) << 0x18)
                    let c2da_fresh177 : uint = uint(c2da_fresh176)
                    c2da_mem[corpsehit + 164] = uint8(c2da_fresh177)
                    c2da_mem[corpsehit + 165] = uint8(c2da_fresh177 >> 0x8)
                    c2da_mem[corpsehit + 166] = uint8(c2da_fresh177 >> 0x10)
                    c2da_mem[corpsehit + 167] = uint8(c2da_fresh177 >> 0x18)
                    let c2da_fresh178 : uint = 0u
                    c2da_mem[corpsehit + 176] = uint8(c2da_fresh178)
                    c2da_mem[corpsehit + 177] = uint8(c2da_fresh178 >> 0x8)
                    c2da_mem[corpsehit + 178] = uint8(c2da_fresh178 >> 0x10)
                    c2da_mem[corpsehit + 179] = uint8(c2da_fresh178 >> 0x18)
                    c2da_mem[corpsehit + 180] = 0u8
                    c2da_mem[corpsehit + 181] = 0u8
                    c2da_mem[corpsehit + 182] = 0u8
                    c2da_mem[corpsehit + 183] = 0u8
                    return
                }
                by++
            }
            bx++
        }
    }
    A_Chase(actor_24)
    return
}
[export, sideeffects]
def A_VileStart(var actor_25 : int) {
    S_StartSound(actor_25, 54)
    return
}
[export, sideeffects]
def A_Fire(var actor_26 : int) {
    var dest_0 : int
    var target_0 : int
    var an_0 : uint
    dest_0 = int(uint(c2da_mem[actor_26 + 216]) | uint(c2da_mem[actor_26 + 217]) << 0x8 | uint(c2da_mem[actor_26 + 218]) << 0x10 | uint(c2da_mem[actor_26 + 219]) << 0x18)
    if (dest_0 == 0) {
        return
    }
    target_0 = P_SubstNullMobj(int(uint(c2da_mem[actor_26 + 176]) | uint(c2da_mem[actor_26 + 177]) << 0x8 | uint(c2da_mem[actor_26 + 178]) << 0x10 | uint(c2da_mem[actor_26 + 179]) << 0x18))
    if (P_CheckSight(target_0, dest_0) == 0) {
        return
    }
    an_0 = (uint(c2da_mem[dest_0 + 56]) | uint(c2da_mem[dest_0 + 57]) << 0x8 | uint(c2da_mem[dest_0 + 58]) << 0x10 | uint(c2da_mem[dest_0 + 59]) << 0x18) >> 19u
    P_UnsetThingPosition(actor_26)
    let c2da_fresh179 : int = int(uint(c2da_mem[dest_0 + 24]) | uint(c2da_mem[dest_0 + 25]) << 0x8 | uint(c2da_mem[dest_0 + 26]) << 0x10 | uint(c2da_mem[dest_0 + 27]) << 0x18) + FixedMul(24 * (1 << 16), int(uint(c2da_mem[finecosine + int(an_0) * 4]) | uint(c2da_mem[finecosine + int(an_0) * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + int(an_0) * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + int(an_0) * 4 + 3]) << 0x18))
    let c2da_fresh180 : uint = uint(c2da_fresh179)
    c2da_mem[actor_26 + 24] = uint8(c2da_fresh180)
    c2da_mem[actor_26 + 25] = uint8(c2da_fresh180 >> 0x8)
    c2da_mem[actor_26 + 26] = uint8(c2da_fresh180 >> 0x10)
    c2da_mem[actor_26 + 27] = uint8(c2da_fresh180 >> 0x18)
    let c2da_fresh181 : int = int(uint(c2da_mem[dest_0 + 28]) | uint(c2da_mem[dest_0 + 29]) << 0x8 | uint(c2da_mem[dest_0 + 30]) << 0x10 | uint(c2da_mem[dest_0 + 31]) << 0x18) + FixedMul(24 * (1 << 16), int(uint(c2da_mem[257920 + int(an_0) * 4]) | uint(c2da_mem[257920 + int(an_0) * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + int(an_0) * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + int(an_0) * 4 + 3]) << 0x18))
    let c2da_fresh182 : uint = uint(c2da_fresh181)
    c2da_mem[actor_26 + 28] = uint8(c2da_fresh182)
    c2da_mem[actor_26 + 29] = uint8(c2da_fresh182 >> 0x8)
    c2da_mem[actor_26 + 30] = uint8(c2da_fresh182 >> 0x10)
    c2da_mem[actor_26 + 31] = uint8(c2da_fresh182 >> 0x18)
    let c2da_fresh183 : int = int(uint(c2da_mem[dest_0 + 32]) | uint(c2da_mem[dest_0 + 33]) << 0x8 | uint(c2da_mem[dest_0 + 34]) << 0x10 | uint(c2da_mem[dest_0 + 35]) << 0x18)
    let c2da_fresh184 : uint = uint(c2da_fresh183)
    c2da_mem[actor_26 + 32] = uint8(c2da_fresh184)
    c2da_mem[actor_26 + 33] = uint8(c2da_fresh184 >> 0x8)
    c2da_mem[actor_26 + 34] = uint8(c2da_fresh184 >> 0x10)
    c2da_mem[actor_26 + 35] = uint8(c2da_fresh184 >> 0x18)
    P_SetThingPosition(actor_26)
    return
}
[export, sideeffects]
def A_StartFire(var actor_27 : int) {
    S_StartSound(actor_27, 92)
    A_Fire(actor_27)
    return
}
[export, sideeffects]
def A_FireCrackle(var actor_28 : int) {
    S_StartSound(actor_28, 91)
    A_Fire(actor_28)
    return
}
[export, sideeffects]
def A_VileTarget(var actor_29 : int) {
    var fog : int
    if (int(uint(c2da_mem[actor_29 + 176]) | uint(c2da_mem[actor_29 + 177]) << 0x8 | uint(c2da_mem[actor_29 + 178]) << 0x10 | uint(c2da_mem[actor_29 + 179]) << 0x18) == 0) {
        return
    }
    A_FaceTarget(actor_29)
    let c2da_fresh185 : int = int(uint(c2da_mem[actor_29 + 176]) | uint(c2da_mem[actor_29 + 177]) << 0x8 | uint(c2da_mem[actor_29 + 178]) << 0x10 | uint(c2da_mem[actor_29 + 179]) << 0x18) + 24
    let c2da_fresh186 : int = int(uint(c2da_mem[actor_29 + 176]) | uint(c2da_mem[actor_29 + 177]) << 0x8 | uint(c2da_mem[actor_29 + 178]) << 0x10 | uint(c2da_mem[actor_29 + 179]) << 0x18) + 24
    let c2da_fresh187 : int = int(uint(c2da_mem[actor_29 + 176]) | uint(c2da_mem[actor_29 + 177]) << 0x8 | uint(c2da_mem[actor_29 + 178]) << 0x10 | uint(c2da_mem[actor_29 + 179]) << 0x18) + 32
    fog = P_SpawnMobj(int(uint(c2da_mem[c2da_fresh185]) | uint(c2da_mem[c2da_fresh185 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh185 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh185 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh186]) | uint(c2da_mem[c2da_fresh186 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh186 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh186 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh187]) | uint(c2da_mem[c2da_fresh187 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh187 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh187 + 3]) << 0x18), 4u)
    let c2da_fresh188 : uint = uint(fog)
    c2da_mem[actor_29 + 216] = uint8(c2da_fresh188)
    c2da_mem[actor_29 + 217] = uint8(c2da_fresh188 >> 0x8)
    c2da_mem[actor_29 + 218] = uint8(c2da_fresh188 >> 0x10)
    c2da_mem[actor_29 + 219] = uint8(c2da_fresh188 >> 0x18)
    c2da_mem[actor_29 + 220] = 0u8
    c2da_mem[actor_29 + 221] = 0u8
    c2da_mem[actor_29 + 222] = 0u8
    c2da_mem[actor_29 + 223] = 0u8
    let c2da_fresh189 : uint = uint(actor_29)
    c2da_mem[fog + 176] = uint8(c2da_fresh189)
    c2da_mem[fog + 177] = uint8(c2da_fresh189 >> 0x8)
    c2da_mem[fog + 178] = uint8(c2da_fresh189 >> 0x10)
    c2da_mem[fog + 179] = uint8(c2da_fresh189 >> 0x18)
    c2da_mem[fog + 180] = 0u8
    c2da_mem[fog + 181] = 0u8
    c2da_mem[fog + 182] = 0u8
    c2da_mem[fog + 183] = 0u8
    let c2da_fresh190 : int = int(uint(c2da_mem[actor_29 + 176]) | uint(c2da_mem[actor_29 + 177]) << 0x8 | uint(c2da_mem[actor_29 + 178]) << 0x10 | uint(c2da_mem[actor_29 + 179]) << 0x18)
    let c2da_fresh191 : uint = uint(c2da_fresh190)
    c2da_mem[fog + 216] = uint8(c2da_fresh191)
    c2da_mem[fog + 217] = uint8(c2da_fresh191 >> 0x8)
    c2da_mem[fog + 218] = uint8(c2da_fresh191 >> 0x10)
    c2da_mem[fog + 219] = uint8(c2da_fresh191 >> 0x18)
    c2da_mem[fog + 220] = 0u8
    c2da_mem[fog + 221] = 0u8
    c2da_mem[fog + 222] = 0u8
    c2da_mem[fog + 223] = 0u8
    A_Fire(fog)
    return
}
[export, sideeffects]
def A_VileAttack(var actor_30 : int) {
    var fire : int
    var an_1 : int
    if (int(uint(c2da_mem[actor_30 + 176]) | uint(c2da_mem[actor_30 + 177]) << 0x8 | uint(c2da_mem[actor_30 + 178]) << 0x10 | uint(c2da_mem[actor_30 + 179]) << 0x18) == 0) {
        return
    }
    A_FaceTarget(actor_30)
    if (P_CheckSight(actor_30, int(uint(c2da_mem[actor_30 + 176]) | uint(c2da_mem[actor_30 + 177]) << 0x8 | uint(c2da_mem[actor_30 + 178]) << 0x10 | uint(c2da_mem[actor_30 + 179]) << 0x18)) == 0) {
        return
    }
    S_StartSound(actor_30, 82)
    P_DamageMobj(int(uint(c2da_mem[actor_30 + 176]) | uint(c2da_mem[actor_30 + 177]) << 0x8 | uint(c2da_mem[actor_30 + 178]) << 0x10 | uint(c2da_mem[actor_30 + 179]) << 0x18), actor_30, actor_30, 20)
    let c2da_fresh192 : int = int(uint(c2da_mem[actor_30 + 176]) | uint(c2da_mem[actor_30 + 177]) << 0x8 | uint(c2da_mem[actor_30 + 178]) << 0x10 | uint(c2da_mem[actor_30 + 179]) << 0x18) + 120
    let c2da_fresh193 : int = int(uint(c2da_mem[actor_30 + 176]) | uint(c2da_mem[actor_30 + 177]) << 0x8 | uint(c2da_mem[actor_30 + 178]) << 0x10 | uint(c2da_mem[actor_30 + 179]) << 0x18) + 136
    let c2da_fresh194 : int = int(uint(c2da_mem[c2da_fresh193]) | uint(c2da_mem[c2da_fresh193 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh193 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh193 + 3]) << 0x18) + 72
    let c2da_fresh195 : int = 1000 * (1 << 16) / int(uint(c2da_mem[c2da_fresh194]) | uint(c2da_mem[c2da_fresh194 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh194 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh194 + 3]) << 0x18)
    let c2da_fresh196 : uint = uint(c2da_fresh195)
    c2da_mem[c2da_fresh192] = uint8(c2da_fresh196)
    c2da_mem[c2da_fresh192 + 1] = uint8(c2da_fresh196 >> 0x8)
    c2da_mem[c2da_fresh192 + 2] = uint8(c2da_fresh196 >> 0x10)
    c2da_mem[c2da_fresh192 + 3] = uint8(c2da_fresh196 >> 0x18)
    an_1 = int((uint(c2da_mem[actor_30 + 56]) | uint(c2da_mem[actor_30 + 57]) << 0x8 | uint(c2da_mem[actor_30 + 58]) << 0x10 | uint(c2da_mem[actor_30 + 59]) << 0x18) >> 19u)
    fire = int(uint(c2da_mem[actor_30 + 216]) | uint(c2da_mem[actor_30 + 217]) << 0x8 | uint(c2da_mem[actor_30 + 218]) << 0x10 | uint(c2da_mem[actor_30 + 219]) << 0x18)
    if (fire == 0) {
        return
    }
    let c2da_fresh197 : int = int(uint(c2da_mem[actor_30 + 176]) | uint(c2da_mem[actor_30 + 177]) << 0x8 | uint(c2da_mem[actor_30 + 178]) << 0x10 | uint(c2da_mem[actor_30 + 179]) << 0x18) + 24
    let c2da_fresh198 : int = int(uint(c2da_mem[c2da_fresh197]) | uint(c2da_mem[c2da_fresh197 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh197 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh197 + 3]) << 0x18) - FixedMul(24 * (1 << 16), int(uint(c2da_mem[finecosine + an_1 * 4]) | uint(c2da_mem[finecosine + an_1 * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + an_1 * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + an_1 * 4 + 3]) << 0x18))
    let c2da_fresh199 : uint = uint(c2da_fresh198)
    c2da_mem[fire + 24] = uint8(c2da_fresh199)
    c2da_mem[fire + 25] = uint8(c2da_fresh199 >> 0x8)
    c2da_mem[fire + 26] = uint8(c2da_fresh199 >> 0x10)
    c2da_mem[fire + 27] = uint8(c2da_fresh199 >> 0x18)
    let c2da_fresh200 : int = int(uint(c2da_mem[actor_30 + 176]) | uint(c2da_mem[actor_30 + 177]) << 0x8 | uint(c2da_mem[actor_30 + 178]) << 0x10 | uint(c2da_mem[actor_30 + 179]) << 0x18) + 28
    let c2da_fresh201 : int = int(uint(c2da_mem[c2da_fresh200]) | uint(c2da_mem[c2da_fresh200 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh200 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh200 + 3]) << 0x18) - FixedMul(24 * (1 << 16), int(uint(c2da_mem[257920 + an_1 * 4]) | uint(c2da_mem[257920 + an_1 * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + an_1 * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + an_1 * 4 + 3]) << 0x18))
    let c2da_fresh202 : uint = uint(c2da_fresh201)
    c2da_mem[fire + 28] = uint8(c2da_fresh202)
    c2da_mem[fire + 29] = uint8(c2da_fresh202 >> 0x8)
    c2da_mem[fire + 30] = uint8(c2da_fresh202 >> 0x10)
    c2da_mem[fire + 31] = uint8(c2da_fresh202 >> 0x18)
    P_RadiusAttack(fire, actor_30, 70)
    return
}
[export, sideeffects]
def A_FatRaise(var actor_31 : int) {
    A_FaceTarget(actor_31)
    S_StartSound(actor_31, 99)
    return
}
[export, sideeffects]
def A_FatAttack1(var actor_32 : int) {
    var mo_1 : int
    var target_1 : int
    var an_2 : int
    A_FaceTarget(actor_32)
    let c2da_fresh203 : uint = (uint(c2da_mem[actor_32 + 56]) | uint(c2da_mem[actor_32 + 57]) << 0x8 | uint(c2da_mem[actor_32 + 58]) << 0x10 | uint(c2da_mem[actor_32 + 59]) << 0x18) + uint(1073741824 / 8)
    let c2da_fresh204 : uint = c2da_fresh203
    c2da_mem[actor_32 + 56] = uint8(c2da_fresh204)
    c2da_mem[actor_32 + 57] = uint8(c2da_fresh204 >> 0x8)
    c2da_mem[actor_32 + 58] = uint8(c2da_fresh204 >> 0x10)
    c2da_mem[actor_32 + 59] = uint8(c2da_fresh204 >> 0x18)
    target_1 = P_SubstNullMobj(int(uint(c2da_mem[actor_32 + 176]) | uint(c2da_mem[actor_32 + 177]) << 0x8 | uint(c2da_mem[actor_32 + 178]) << 0x10 | uint(c2da_mem[actor_32 + 179]) << 0x18))
    P_SpawnMissile(actor_32, target_1, 9u)
    mo_1 = P_SpawnMissile(actor_32, target_1, 9u)
    let c2da_fresh205 : uint = (uint(c2da_mem[mo_1 + 56]) | uint(c2da_mem[mo_1 + 57]) << 0x8 | uint(c2da_mem[mo_1 + 58]) << 0x10 | uint(c2da_mem[mo_1 + 59]) << 0x18) + uint(1073741824 / 8)
    let c2da_fresh206 : uint = c2da_fresh205
    c2da_mem[mo_1 + 56] = uint8(c2da_fresh206)
    c2da_mem[mo_1 + 57] = uint8(c2da_fresh206 >> 0x8)
    c2da_mem[mo_1 + 58] = uint8(c2da_fresh206 >> 0x10)
    c2da_mem[mo_1 + 59] = uint8(c2da_fresh206 >> 0x18)
    an_2 = int((uint(c2da_mem[mo_1 + 56]) | uint(c2da_mem[mo_1 + 57]) << 0x8 | uint(c2da_mem[mo_1 + 58]) << 0x10 | uint(c2da_mem[mo_1 + 59]) << 0x18) >> 19u)
    let c2da_fresh207 : int = int(uint(c2da_mem[mo_1 + 136]) | uint(c2da_mem[mo_1 + 137]) << 0x8 | uint(c2da_mem[mo_1 + 138]) << 0x10 | uint(c2da_mem[mo_1 + 139]) << 0x18) + 60
    let c2da_fresh208 : int = FixedMul(int(uint(c2da_mem[c2da_fresh207]) | uint(c2da_mem[c2da_fresh207 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh207 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh207 + 3]) << 0x18), int(uint(c2da_mem[finecosine + an_2 * 4]) | uint(c2da_mem[finecosine + an_2 * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + an_2 * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + an_2 * 4 + 3]) << 0x18))
    let c2da_fresh209 : uint = uint(c2da_fresh208)
    c2da_mem[mo_1 + 112] = uint8(c2da_fresh209)
    c2da_mem[mo_1 + 113] = uint8(c2da_fresh209 >> 0x8)
    c2da_mem[mo_1 + 114] = uint8(c2da_fresh209 >> 0x10)
    c2da_mem[mo_1 + 115] = uint8(c2da_fresh209 >> 0x18)
    let c2da_fresh210 : int = int(uint(c2da_mem[mo_1 + 136]) | uint(c2da_mem[mo_1 + 137]) << 0x8 | uint(c2da_mem[mo_1 + 138]) << 0x10 | uint(c2da_mem[mo_1 + 139]) << 0x18) + 60
    let c2da_fresh211 : int = FixedMul(int(uint(c2da_mem[c2da_fresh210]) | uint(c2da_mem[c2da_fresh210 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh210 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh210 + 3]) << 0x18), int(uint(c2da_mem[257920 + an_2 * 4]) | uint(c2da_mem[257920 + an_2 * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + an_2 * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + an_2 * 4 + 3]) << 0x18))
    let c2da_fresh212 : uint = uint(c2da_fresh211)
    c2da_mem[mo_1 + 116] = uint8(c2da_fresh212)
    c2da_mem[mo_1 + 117] = uint8(c2da_fresh212 >> 0x8)
    c2da_mem[mo_1 + 118] = uint8(c2da_fresh212 >> 0x10)
    c2da_mem[mo_1 + 119] = uint8(c2da_fresh212 >> 0x18)
    return
}
[export, sideeffects]
def A_FatAttack2(var actor_33 : int) {
    var mo_2 : int
    var target_2 : int
    var an_3 : int
    A_FaceTarget(actor_33)
    let c2da_fresh213 : uint = (uint(c2da_mem[actor_33 + 56]) | uint(c2da_mem[actor_33 + 57]) << 0x8 | uint(c2da_mem[actor_33 + 58]) << 0x10 | uint(c2da_mem[actor_33 + 59]) << 0x18) - uint(1073741824 / 8)
    let c2da_fresh214 : uint = c2da_fresh213
    c2da_mem[actor_33 + 56] = uint8(c2da_fresh214)
    c2da_mem[actor_33 + 57] = uint8(c2da_fresh214 >> 0x8)
    c2da_mem[actor_33 + 58] = uint8(c2da_fresh214 >> 0x10)
    c2da_mem[actor_33 + 59] = uint8(c2da_fresh214 >> 0x18)
    target_2 = P_SubstNullMobj(int(uint(c2da_mem[actor_33 + 176]) | uint(c2da_mem[actor_33 + 177]) << 0x8 | uint(c2da_mem[actor_33 + 178]) << 0x10 | uint(c2da_mem[actor_33 + 179]) << 0x18))
    P_SpawnMissile(actor_33, target_2, 9u)
    mo_2 = P_SpawnMissile(actor_33, target_2, 9u)
    let c2da_fresh215 : uint = (uint(c2da_mem[mo_2 + 56]) | uint(c2da_mem[mo_2 + 57]) << 0x8 | uint(c2da_mem[mo_2 + 58]) << 0x10 | uint(c2da_mem[mo_2 + 59]) << 0x18) - uint(1073741824 / 8 * 2)
    let c2da_fresh216 : uint = c2da_fresh215
    c2da_mem[mo_2 + 56] = uint8(c2da_fresh216)
    c2da_mem[mo_2 + 57] = uint8(c2da_fresh216 >> 0x8)
    c2da_mem[mo_2 + 58] = uint8(c2da_fresh216 >> 0x10)
    c2da_mem[mo_2 + 59] = uint8(c2da_fresh216 >> 0x18)
    an_3 = int((uint(c2da_mem[mo_2 + 56]) | uint(c2da_mem[mo_2 + 57]) << 0x8 | uint(c2da_mem[mo_2 + 58]) << 0x10 | uint(c2da_mem[mo_2 + 59]) << 0x18) >> 19u)
    let c2da_fresh217 : int = int(uint(c2da_mem[mo_2 + 136]) | uint(c2da_mem[mo_2 + 137]) << 0x8 | uint(c2da_mem[mo_2 + 138]) << 0x10 | uint(c2da_mem[mo_2 + 139]) << 0x18) + 60
    let c2da_fresh218 : int = FixedMul(int(uint(c2da_mem[c2da_fresh217]) | uint(c2da_mem[c2da_fresh217 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh217 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh217 + 3]) << 0x18), int(uint(c2da_mem[finecosine + an_3 * 4]) | uint(c2da_mem[finecosine + an_3 * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + an_3 * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + an_3 * 4 + 3]) << 0x18))
    let c2da_fresh219 : uint = uint(c2da_fresh218)
    c2da_mem[mo_2 + 112] = uint8(c2da_fresh219)
    c2da_mem[mo_2 + 113] = uint8(c2da_fresh219 >> 0x8)
    c2da_mem[mo_2 + 114] = uint8(c2da_fresh219 >> 0x10)
    c2da_mem[mo_2 + 115] = uint8(c2da_fresh219 >> 0x18)
    let c2da_fresh220 : int = int(uint(c2da_mem[mo_2 + 136]) | uint(c2da_mem[mo_2 + 137]) << 0x8 | uint(c2da_mem[mo_2 + 138]) << 0x10 | uint(c2da_mem[mo_2 + 139]) << 0x18) + 60
    let c2da_fresh221 : int = FixedMul(int(uint(c2da_mem[c2da_fresh220]) | uint(c2da_mem[c2da_fresh220 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh220 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh220 + 3]) << 0x18), int(uint(c2da_mem[257920 + an_3 * 4]) | uint(c2da_mem[257920 + an_3 * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + an_3 * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + an_3 * 4 + 3]) << 0x18))
    let c2da_fresh222 : uint = uint(c2da_fresh221)
    c2da_mem[mo_2 + 116] = uint8(c2da_fresh222)
    c2da_mem[mo_2 + 117] = uint8(c2da_fresh222 >> 0x8)
    c2da_mem[mo_2 + 118] = uint8(c2da_fresh222 >> 0x10)
    c2da_mem[mo_2 + 119] = uint8(c2da_fresh222 >> 0x18)
    return
}
[export, sideeffects]
def A_FatAttack3(var actor_34 : int) {
    var mo_3 : int
    var target_3 : int
    var an_4 : int
    A_FaceTarget(actor_34)
    target_3 = P_SubstNullMobj(int(uint(c2da_mem[actor_34 + 176]) | uint(c2da_mem[actor_34 + 177]) << 0x8 | uint(c2da_mem[actor_34 + 178]) << 0x10 | uint(c2da_mem[actor_34 + 179]) << 0x18))
    mo_3 = P_SpawnMissile(actor_34, target_3, 9u)
    let c2da_fresh223 : uint = (uint(c2da_mem[mo_3 + 56]) | uint(c2da_mem[mo_3 + 57]) << 0x8 | uint(c2da_mem[mo_3 + 58]) << 0x10 | uint(c2da_mem[mo_3 + 59]) << 0x18) - uint(1073741824 / 8 / 2)
    let c2da_fresh224 : uint = c2da_fresh223
    c2da_mem[mo_3 + 56] = uint8(c2da_fresh224)
    c2da_mem[mo_3 + 57] = uint8(c2da_fresh224 >> 0x8)
    c2da_mem[mo_3 + 58] = uint8(c2da_fresh224 >> 0x10)
    c2da_mem[mo_3 + 59] = uint8(c2da_fresh224 >> 0x18)
    an_4 = int((uint(c2da_mem[mo_3 + 56]) | uint(c2da_mem[mo_3 + 57]) << 0x8 | uint(c2da_mem[mo_3 + 58]) << 0x10 | uint(c2da_mem[mo_3 + 59]) << 0x18) >> 19u)
    let c2da_fresh225 : int = int(uint(c2da_mem[mo_3 + 136]) | uint(c2da_mem[mo_3 + 137]) << 0x8 | uint(c2da_mem[mo_3 + 138]) << 0x10 | uint(c2da_mem[mo_3 + 139]) << 0x18) + 60
    let c2da_fresh226 : int = FixedMul(int(uint(c2da_mem[c2da_fresh225]) | uint(c2da_mem[c2da_fresh225 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh225 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh225 + 3]) << 0x18), int(uint(c2da_mem[finecosine + an_4 * 4]) | uint(c2da_mem[finecosine + an_4 * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + an_4 * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + an_4 * 4 + 3]) << 0x18))
    let c2da_fresh227 : uint = uint(c2da_fresh226)
    c2da_mem[mo_3 + 112] = uint8(c2da_fresh227)
    c2da_mem[mo_3 + 113] = uint8(c2da_fresh227 >> 0x8)
    c2da_mem[mo_3 + 114] = uint8(c2da_fresh227 >> 0x10)
    c2da_mem[mo_3 + 115] = uint8(c2da_fresh227 >> 0x18)
    let c2da_fresh228 : int = int(uint(c2da_mem[mo_3 + 136]) | uint(c2da_mem[mo_3 + 137]) << 0x8 | uint(c2da_mem[mo_3 + 138]) << 0x10 | uint(c2da_mem[mo_3 + 139]) << 0x18) + 60
    let c2da_fresh229 : int = FixedMul(int(uint(c2da_mem[c2da_fresh228]) | uint(c2da_mem[c2da_fresh228 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh228 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh228 + 3]) << 0x18), int(uint(c2da_mem[257920 + an_4 * 4]) | uint(c2da_mem[257920 + an_4 * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + an_4 * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + an_4 * 4 + 3]) << 0x18))
    let c2da_fresh230 : uint = uint(c2da_fresh229)
    c2da_mem[mo_3 + 116] = uint8(c2da_fresh230)
    c2da_mem[mo_3 + 117] = uint8(c2da_fresh230 >> 0x8)
    c2da_mem[mo_3 + 118] = uint8(c2da_fresh230 >> 0x10)
    c2da_mem[mo_3 + 119] = uint8(c2da_fresh230 >> 0x18)
    mo_3 = P_SpawnMissile(actor_34, target_3, 9u)
    let c2da_fresh231 : uint = (uint(c2da_mem[mo_3 + 56]) | uint(c2da_mem[mo_3 + 57]) << 0x8 | uint(c2da_mem[mo_3 + 58]) << 0x10 | uint(c2da_mem[mo_3 + 59]) << 0x18) + uint(1073741824 / 8 / 2)
    let c2da_fresh232 : uint = c2da_fresh231
    c2da_mem[mo_3 + 56] = uint8(c2da_fresh232)
    c2da_mem[mo_3 + 57] = uint8(c2da_fresh232 >> 0x8)
    c2da_mem[mo_3 + 58] = uint8(c2da_fresh232 >> 0x10)
    c2da_mem[mo_3 + 59] = uint8(c2da_fresh232 >> 0x18)
    an_4 = int((uint(c2da_mem[mo_3 + 56]) | uint(c2da_mem[mo_3 + 57]) << 0x8 | uint(c2da_mem[mo_3 + 58]) << 0x10 | uint(c2da_mem[mo_3 + 59]) << 0x18) >> 19u)
    let c2da_fresh233 : int = int(uint(c2da_mem[mo_3 + 136]) | uint(c2da_mem[mo_3 + 137]) << 0x8 | uint(c2da_mem[mo_3 + 138]) << 0x10 | uint(c2da_mem[mo_3 + 139]) << 0x18) + 60
    let c2da_fresh234 : int = FixedMul(int(uint(c2da_mem[c2da_fresh233]) | uint(c2da_mem[c2da_fresh233 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh233 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh233 + 3]) << 0x18), int(uint(c2da_mem[finecosine + an_4 * 4]) | uint(c2da_mem[finecosine + an_4 * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + an_4 * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + an_4 * 4 + 3]) << 0x18))
    let c2da_fresh235 : uint = uint(c2da_fresh234)
    c2da_mem[mo_3 + 112] = uint8(c2da_fresh235)
    c2da_mem[mo_3 + 113] = uint8(c2da_fresh235 >> 0x8)
    c2da_mem[mo_3 + 114] = uint8(c2da_fresh235 >> 0x10)
    c2da_mem[mo_3 + 115] = uint8(c2da_fresh235 >> 0x18)
    let c2da_fresh236 : int = int(uint(c2da_mem[mo_3 + 136]) | uint(c2da_mem[mo_3 + 137]) << 0x8 | uint(c2da_mem[mo_3 + 138]) << 0x10 | uint(c2da_mem[mo_3 + 139]) << 0x18) + 60
    let c2da_fresh237 : int = FixedMul(int(uint(c2da_mem[c2da_fresh236]) | uint(c2da_mem[c2da_fresh236 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh236 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh236 + 3]) << 0x18), int(uint(c2da_mem[257920 + an_4 * 4]) | uint(c2da_mem[257920 + an_4 * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + an_4 * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + an_4 * 4 + 3]) << 0x18))
    let c2da_fresh238 : uint = uint(c2da_fresh237)
    c2da_mem[mo_3 + 116] = uint8(c2da_fresh238)
    c2da_mem[mo_3 + 117] = uint8(c2da_fresh238 >> 0x8)
    c2da_mem[mo_3 + 118] = uint8(c2da_fresh238 >> 0x10)
    c2da_mem[mo_3 + 119] = uint8(c2da_fresh238 >> 0x18)
    return
}
[export, sideeffects]
def A_SkullAttack(var actor_35 : int) {
    var dest_1 : int
    var an_5 : uint
    var dist_3 : int
    if (int(uint(c2da_mem[actor_35 + 176]) | uint(c2da_mem[actor_35 + 177]) << 0x8 | uint(c2da_mem[actor_35 + 178]) << 0x10 | uint(c2da_mem[actor_35 + 179]) << 0x18) == 0) {
        return
    }
    dest_1 = int(uint(c2da_mem[actor_35 + 176]) | uint(c2da_mem[actor_35 + 177]) << 0x8 | uint(c2da_mem[actor_35 + 178]) << 0x10 | uint(c2da_mem[actor_35 + 179]) << 0x18)
    let c2da_fresh239 : int = int(uint(c2da_mem[actor_35 + 160]) | uint(c2da_mem[actor_35 + 161]) << 0x8 | uint(c2da_mem[actor_35 + 162]) << 0x10 | uint(c2da_mem[actor_35 + 163]) << 0x18) | 16777216
    let c2da_fresh240 : uint = uint(c2da_fresh239)
    c2da_mem[actor_35 + 160] = uint8(c2da_fresh240)
    c2da_mem[actor_35 + 161] = uint8(c2da_fresh240 >> 0x8)
    c2da_mem[actor_35 + 162] = uint8(c2da_fresh240 >> 0x10)
    c2da_mem[actor_35 + 163] = uint8(c2da_fresh240 >> 0x18)
    let c2da_fresh241 : int = int(uint(c2da_mem[actor_35 + 136]) | uint(c2da_mem[actor_35 + 137]) << 0x8 | uint(c2da_mem[actor_35 + 138]) << 0x10 | uint(c2da_mem[actor_35 + 139]) << 0x18) + 24
    S_StartSound(actor_35, int(uint(c2da_mem[c2da_fresh241]) | uint(c2da_mem[c2da_fresh241 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh241 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh241 + 3]) << 0x18))
    A_FaceTarget(actor_35)
    an_5 = (uint(c2da_mem[actor_35 + 56]) | uint(c2da_mem[actor_35 + 57]) << 0x8 | uint(c2da_mem[actor_35 + 58]) << 0x10 | uint(c2da_mem[actor_35 + 59]) << 0x18) >> 19u
    let c2da_fresh242 : int = FixedMul(20 * (1 << 16), int(uint(c2da_mem[finecosine + int(an_5) * 4]) | uint(c2da_mem[finecosine + int(an_5) * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + int(an_5) * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + int(an_5) * 4 + 3]) << 0x18))
    let c2da_fresh243 : uint = uint(c2da_fresh242)
    c2da_mem[actor_35 + 112] = uint8(c2da_fresh243)
    c2da_mem[actor_35 + 113] = uint8(c2da_fresh243 >> 0x8)
    c2da_mem[actor_35 + 114] = uint8(c2da_fresh243 >> 0x10)
    c2da_mem[actor_35 + 115] = uint8(c2da_fresh243 >> 0x18)
    let c2da_fresh244 : int = FixedMul(20 * (1 << 16), int(uint(c2da_mem[257920 + int(an_5) * 4]) | uint(c2da_mem[257920 + int(an_5) * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + int(an_5) * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + int(an_5) * 4 + 3]) << 0x18))
    let c2da_fresh245 : uint = uint(c2da_fresh244)
    c2da_mem[actor_35 + 116] = uint8(c2da_fresh245)
    c2da_mem[actor_35 + 117] = uint8(c2da_fresh245 >> 0x8)
    c2da_mem[actor_35 + 118] = uint8(c2da_fresh245 >> 0x10)
    c2da_mem[actor_35 + 119] = uint8(c2da_fresh245 >> 0x18)
    dist_3 = P_AproxDistance(int(uint(c2da_mem[dest_1 + 24]) | uint(c2da_mem[dest_1 + 25]) << 0x8 | uint(c2da_mem[dest_1 + 26]) << 0x10 | uint(c2da_mem[dest_1 + 27]) << 0x18) - int(uint(c2da_mem[actor_35 + 24]) | uint(c2da_mem[actor_35 + 25]) << 0x8 | uint(c2da_mem[actor_35 + 26]) << 0x10 | uint(c2da_mem[actor_35 + 27]) << 0x18), int(uint(c2da_mem[dest_1 + 28]) | uint(c2da_mem[dest_1 + 29]) << 0x8 | uint(c2da_mem[dest_1 + 30]) << 0x10 | uint(c2da_mem[dest_1 + 31]) << 0x18) - int(uint(c2da_mem[actor_35 + 28]) | uint(c2da_mem[actor_35 + 29]) << 0x8 | uint(c2da_mem[actor_35 + 30]) << 0x10 | uint(c2da_mem[actor_35 + 31]) << 0x18))
    dist_3 /= 20 * (1 << 16)
    if (dist_3 < 1) {
        dist_3 = 1
    }
    let c2da_fresh246 : int = (int(uint(c2da_mem[dest_1 + 32]) | uint(c2da_mem[dest_1 + 33]) << 0x8 | uint(c2da_mem[dest_1 + 34]) << 0x10 | uint(c2da_mem[dest_1 + 35]) << 0x18) + (int(uint(c2da_mem[dest_1 + 108]) | uint(c2da_mem[dest_1 + 109]) << 0x8 | uint(c2da_mem[dest_1 + 110]) << 0x10 | uint(c2da_mem[dest_1 + 111]) << 0x18) >> 1) - int(uint(c2da_mem[actor_35 + 32]) | uint(c2da_mem[actor_35 + 33]) << 0x8 | uint(c2da_mem[actor_35 + 34]) << 0x10 | uint(c2da_mem[actor_35 + 35]) << 0x18)) / dist_3
    let c2da_fresh247 : uint = uint(c2da_fresh246)
    c2da_mem[actor_35 + 120] = uint8(c2da_fresh247)
    c2da_mem[actor_35 + 121] = uint8(c2da_fresh247 >> 0x8)
    c2da_mem[actor_35 + 122] = uint8(c2da_fresh247 >> 0x10)
    c2da_mem[actor_35 + 123] = uint8(c2da_fresh247 >> 0x18)
    return
}
[export, sideeffects]
def A_PainShootSkull(var actor_36 : int; var angle_2 : uint) {
    var x : int
    var y : int
    var z : int
    var newmobj : int
    var an_6 : uint
    var prestep : int
    var count : int
    var currentthinker : int
    count = 0
    currentthinker = int(uint(c2da_mem[46552]) | uint(c2da_mem[46553]) << 0x8 | uint(c2da_mem[46554]) << 0x10 | uint(c2da_mem[46555]) << 0x18)
    while (currentthinker != 46544) {
        if (int(uint(c2da_mem[currentthinker + 16]) | uint(c2da_mem[currentthinker + 17]) << 0x8 | uint(c2da_mem[currentthinker + 18]) << 0x10 | uint(c2da_mem[currentthinker + 19]) << 0x18) == 126 && (uint(c2da_mem[currentthinker + 128]) | uint(c2da_mem[currentthinker + 129]) << 0x8 | uint(c2da_mem[currentthinker + 130]) << 0x10 | uint(c2da_mem[currentthinker + 131]) << 0x18) == 18u) {
            count++
        }
        currentthinker = int(uint(c2da_mem[currentthinker + 8]) | uint(c2da_mem[currentthinker + 9]) << 0x8 | uint(c2da_mem[currentthinker + 10]) << 0x10 | uint(c2da_mem[currentthinker + 11]) << 0x18)
    }
    if (count > 20) {
        return
    }
    an_6 = angle_2 >> 19u
    let c2da_fresh248 : int = int(uint(c2da_mem[actor_36 + 136]) | uint(c2da_mem[actor_36 + 137]) << 0x8 | uint(c2da_mem[actor_36 + 138]) << 0x10 | uint(c2da_mem[actor_36 + 139]) << 0x18) + 64
    prestep = 4 * (1 << 16) + 3 * (int(uint(c2da_mem[c2da_fresh248]) | uint(c2da_mem[c2da_fresh248 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh248 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh248 + 3]) << 0x18) + int(uint(c2da_mem[51056 + 18 * 92 + 64]) | uint(c2da_mem[51056 + 18 * 92 + 65]) << 0x8 | uint(c2da_mem[51056 + 18 * 92 + 66]) << 0x10 | uint(c2da_mem[51056 + 18 * 92 + 67]) << 0x18)) / 2
    x = int(uint(c2da_mem[actor_36 + 24]) | uint(c2da_mem[actor_36 + 25]) << 0x8 | uint(c2da_mem[actor_36 + 26]) << 0x10 | uint(c2da_mem[actor_36 + 27]) << 0x18) + FixedMul(prestep, int(uint(c2da_mem[finecosine + int(an_6) * 4]) | uint(c2da_mem[finecosine + int(an_6) * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + int(an_6) * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + int(an_6) * 4 + 3]) << 0x18))
    y = int(uint(c2da_mem[actor_36 + 28]) | uint(c2da_mem[actor_36 + 29]) << 0x8 | uint(c2da_mem[actor_36 + 30]) << 0x10 | uint(c2da_mem[actor_36 + 31]) << 0x18) + FixedMul(prestep, int(uint(c2da_mem[257920 + int(an_6) * 4]) | uint(c2da_mem[257920 + int(an_6) * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + int(an_6) * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + int(an_6) * 4 + 3]) << 0x18))
    z = int(uint(c2da_mem[actor_36 + 32]) | uint(c2da_mem[actor_36 + 33]) << 0x8 | uint(c2da_mem[actor_36 + 34]) << 0x10 | uint(c2da_mem[actor_36 + 35]) << 0x18) + 8 * (1 << 16)
    newmobj = P_SpawnMobj(x, y, z, 18u)
    if (P_TryMove(newmobj, int(uint(c2da_mem[newmobj + 24]) | uint(c2da_mem[newmobj + 25]) << 0x8 | uint(c2da_mem[newmobj + 26]) << 0x10 | uint(c2da_mem[newmobj + 27]) << 0x18), int(uint(c2da_mem[newmobj + 28]) | uint(c2da_mem[newmobj + 29]) << 0x8 | uint(c2da_mem[newmobj + 30]) << 0x10 | uint(c2da_mem[newmobj + 31]) << 0x18)) == 0) {
        P_DamageMobj(newmobj, actor_36, actor_36, 10000)
        return
    }
    let c2da_fresh249 : int = int(uint(c2da_mem[actor_36 + 176]) | uint(c2da_mem[actor_36 + 177]) << 0x8 | uint(c2da_mem[actor_36 + 178]) << 0x10 | uint(c2da_mem[actor_36 + 179]) << 0x18)
    let c2da_fresh250 : uint = uint(c2da_fresh249)
    c2da_mem[newmobj + 176] = uint8(c2da_fresh250)
    c2da_mem[newmobj + 177] = uint8(c2da_fresh250 >> 0x8)
    c2da_mem[newmobj + 178] = uint8(c2da_fresh250 >> 0x10)
    c2da_mem[newmobj + 179] = uint8(c2da_fresh250 >> 0x18)
    c2da_mem[newmobj + 180] = 0u8
    c2da_mem[newmobj + 181] = 0u8
    c2da_mem[newmobj + 182] = 0u8
    c2da_mem[newmobj + 183] = 0u8
    A_SkullAttack(newmobj)
    return
}
[export, sideeffects]
def A_PainAttack(var actor_37 : int) {
    if (int(uint(c2da_mem[actor_37 + 176]) | uint(c2da_mem[actor_37 + 177]) << 0x8 | uint(c2da_mem[actor_37 + 178]) << 0x10 | uint(c2da_mem[actor_37 + 179]) << 0x18) == 0) {
        return
    }
    A_FaceTarget(actor_37)
    A_PainShootSkull(actor_37, uint(c2da_mem[actor_37 + 56]) | uint(c2da_mem[actor_37 + 57]) << 0x8 | uint(c2da_mem[actor_37 + 58]) << 0x10 | uint(c2da_mem[actor_37 + 59]) << 0x18)
    return
}
[export, sideeffects]
def A_PainDie(var actor_38 : int) {
    A_Fall(actor_38)
    A_PainShootSkull(actor_38, (uint(c2da_mem[actor_38 + 56]) | uint(c2da_mem[actor_38 + 57]) << 0x8 | uint(c2da_mem[actor_38 + 58]) << 0x10 | uint(c2da_mem[actor_38 + 59]) << 0x18) + 0x40000000u)
    A_PainShootSkull(actor_38, (uint(c2da_mem[actor_38 + 56]) | uint(c2da_mem[actor_38 + 57]) << 0x8 | uint(c2da_mem[actor_38 + 58]) << 0x10 | uint(c2da_mem[actor_38 + 59]) << 0x18) + 0x80000000u)
    A_PainShootSkull(actor_38, (uint(c2da_mem[actor_38 + 56]) | uint(c2da_mem[actor_38 + 57]) << 0x8 | uint(c2da_mem[actor_38 + 58]) << 0x10 | uint(c2da_mem[actor_38 + 59]) << 0x18) + 0xc0000000u)
    return
}
[export, sideeffects]
def A_Scream(var actor_39 : int) {
    var c2da_fresh252 : int
    var sound_0 : int
    let c2da_fresh251 : int = int(uint(c2da_mem[actor_39 + 136]) | uint(c2da_mem[actor_39 + 137]) << 0x8 | uint(c2da_mem[actor_39 + 138]) << 0x10 | uint(c2da_mem[actor_39 + 139]) << 0x18) + 56
    c2da_fresh252 = int(uint(c2da_mem[c2da_fresh251]) | uint(c2da_mem[c2da_fresh251 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh251 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh251 + 3]) << 0x18)
    if (c2da_fresh252 == 0) {
        return
    } elif (c2da_fresh252 == 59 || c2da_fresh252 == 60 || c2da_fresh252 == 61) {
        sound_0 = 59 + P_Random() % 3
    } elif (c2da_fresh252 == 62 || c2da_fresh252 == 63) {
        sound_0 = 62 + P_Random() % 2
    } else {
        let c2da_fresh253 : int = int(uint(c2da_mem[actor_39 + 136]) | uint(c2da_mem[actor_39 + 137]) << 0x8 | uint(c2da_mem[actor_39 + 138]) << 0x10 | uint(c2da_mem[actor_39 + 139]) << 0x18) + 56
        sound_0 = int(uint(c2da_mem[c2da_fresh253]) | uint(c2da_mem[c2da_fresh253 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh253 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh253 + 3]) << 0x18)
    }
    if ((uint(c2da_mem[actor_39 + 128]) | uint(c2da_mem[actor_39 + 129]) << 0x8 | uint(c2da_mem[actor_39 + 130]) << 0x10 | uint(c2da_mem[actor_39 + 131]) << 0x18) == 19u || (uint(c2da_mem[actor_39 + 128]) | uint(c2da_mem[actor_39 + 129]) << 0x8 | uint(c2da_mem[actor_39 + 130]) << 0x10 | uint(c2da_mem[actor_39 + 131]) << 0x18) == 21u) {
        S_StartSound(0, sound_0)
    } else {
        S_StartSound(actor_39, sound_0)
    }
    return
}
[export, sideeffects]
def A_XScream(var actor_40 : int) {
    S_StartSound(actor_40, 31)
    return
}
[export, sideeffects]
def A_Pain(var actor_41 : int) {
    let c2da_fresh254 : int = int(uint(c2da_mem[actor_41 + 136]) | uint(c2da_mem[actor_41 + 137]) << 0x8 | uint(c2da_mem[actor_41 + 138]) << 0x10 | uint(c2da_mem[actor_41 + 139]) << 0x18) + 36
    if (int(uint(c2da_mem[c2da_fresh254]) | uint(c2da_mem[c2da_fresh254 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh254 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh254 + 3]) << 0x18) != 0) {
        let c2da_fresh255 : int = int(uint(c2da_mem[actor_41 + 136]) | uint(c2da_mem[actor_41 + 137]) << 0x8 | uint(c2da_mem[actor_41 + 138]) << 0x10 | uint(c2da_mem[actor_41 + 139]) << 0x18) + 36
        S_StartSound(actor_41, int(uint(c2da_mem[c2da_fresh255]) | uint(c2da_mem[c2da_fresh255 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh255 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh255 + 3]) << 0x18))
    }
    return
}
[export, sideeffects]
def A_Explode(var thingy : int) {
    P_RadiusAttack(thingy, int(uint(c2da_mem[thingy + 176]) | uint(c2da_mem[thingy + 177]) << 0x8 | uint(c2da_mem[thingy + 178]) << 0x10 | uint(c2da_mem[thingy + 179]) << 0x18), 128)
    return
}
[sideeffects]
def private CheckBossEnd(var motype : uint) : uint {
    if (uint(gameversion) < 6u) {
        if (gamemap != 8) {
            return 0u
        }
        if (motype == 15u && gameepisode != 1) {
            return 0u
        }
        return 1u
    } elif (gameepisode == 1) {
        return uint(gamemap == 8 && motype == 15u ? 1 : 0)
    } elif (gameepisode == 2) {
        return uint(gamemap == 8 && motype == 21u ? 1 : 0)
    } elif (gameepisode == 3) {
        return uint(gamemap == 8 && motype == 19u ? 1 : 0)
    } elif (gameepisode == 4) {
        return uint(gamemap == 6 && motype == 21u || gamemap == 8 && motype == 19u ? 1 : 0)
    } else {
        return uint(gamemap == 8 ? 1 : 0)
    }
}
[export, sideeffects]
def A_BossDeath(var mo_4 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    A_BossDeath_c2da_frame(mo_4, c2da_lin_enter(96))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def A_Hoof(var mo_5 : int) {
    S_StartSound(mo_5, 84)
    A_Chase(mo_5)
    return
}
[export, sideeffects]
def A_Metal(var mo_6 : int) {
    S_StartSound(mo_6, 85)
    A_Chase(mo_6)
    return
}
[export, sideeffects]
def A_BabyMetal(var mo_7 : int) {
    S_StartSound(mo_7, 79)
    A_Chase(mo_7)
    return
}
[export, sideeffects]
def A_OpenShotgun2(var player_0 : int; var psp : int) {
    S_StartSound(int(uint(c2da_mem[player_0]) | uint(c2da_mem[player_0 + 1]) << 0x8 | uint(c2da_mem[player_0 + 2]) << 0x10 | uint(c2da_mem[player_0 + 3]) << 0x18), 5)
    return
}
[export, sideeffects]
def A_LoadShotgun2(var player_1 : int; var psp_0 : int) {
    S_StartSound(int(uint(c2da_mem[player_1]) | uint(c2da_mem[player_1 + 1]) << 0x8 | uint(c2da_mem[player_1 + 2]) << 0x10 | uint(c2da_mem[player_1 + 3]) << 0x18), 7)
    return
}
[export, sideeffects]
def A_CloseShotgun2(var player_2 : int; var psp_1 : int) {
    S_StartSound(int(uint(c2da_mem[player_2]) | uint(c2da_mem[player_2 + 1]) << 0x8 | uint(c2da_mem[player_2 + 2]) << 0x10 | uint(c2da_mem[player_2 + 3]) << 0x18), 6)
    A_ReFire(player_2, psp_1)
    return
}
var braintargets : int[32]

var numbraintargets : int = default<int>

var braintargeton : int = 0

[export, sideeffects]
def A_BrainAwake(var mo_8 : int) {
    var thinker : int
    var m : int
    numbraintargets = 0
    braintargeton = 0
    thinker = int(uint(c2da_mem[46552]) | uint(c2da_mem[46553]) << 0x8 | uint(c2da_mem[46554]) << 0x10 | uint(c2da_mem[46555]) << 0x18)
    thinker = int(uint(c2da_mem[46552]) | uint(c2da_mem[46553]) << 0x8 | uint(c2da_mem[46554]) << 0x10 | uint(c2da_mem[46555]) << 0x18)
    while (thinker != 46544) {
        if (int(uint(c2da_mem[thinker + 16]) | uint(c2da_mem[thinker + 17]) << 0x8 | uint(c2da_mem[thinker + 18]) << 0x10 | uint(c2da_mem[thinker + 19]) << 0x18) != 126) {
            thinker = int(uint(c2da_mem[thinker + 8]) | uint(c2da_mem[thinker + 9]) << 0x8 | uint(c2da_mem[thinker + 10]) << 0x10 | uint(c2da_mem[thinker + 11]) << 0x18)
            continue
        }
        m = thinker
        if ((uint(c2da_mem[m + 128]) | uint(c2da_mem[m + 129]) << 0x8 | uint(c2da_mem[m + 130]) << 0x10 | uint(c2da_mem[m + 131]) << 0x18) == 27u) {
            braintargets[numbraintargets] = m
            numbraintargets++
        }
        thinker = int(uint(c2da_mem[thinker + 8]) | uint(c2da_mem[thinker + 9]) << 0x8 | uint(c2da_mem[thinker + 10]) << 0x10 | uint(c2da_mem[thinker + 11]) << 0x18)
    }
    S_StartSound(0, 96)
    return
}
[export, sideeffects]
def A_BrainPain(var mo_9 : int) {
    S_StartSound(0, 97)
    return
}
[export, sideeffects]
def A_BrainScream(var mo_10 : int) {
    var x_0 : int
    var y_0 : int
    var z_0 : int
    var th_2 : int
    x_0 = int(uint(c2da_mem[mo_10 + 24]) | uint(c2da_mem[mo_10 + 25]) << 0x8 | uint(c2da_mem[mo_10 + 26]) << 0x10 | uint(c2da_mem[mo_10 + 27]) << 0x18) - 196 * (1 << 16)
    while (x_0 < int(uint(c2da_mem[mo_10 + 24]) | uint(c2da_mem[mo_10 + 25]) << 0x8 | uint(c2da_mem[mo_10 + 26]) << 0x10 | uint(c2da_mem[mo_10 + 27]) << 0x18) + 320 * (1 << 16)) {
        y_0 = int(uint(c2da_mem[mo_10 + 28]) | uint(c2da_mem[mo_10 + 29]) << 0x8 | uint(c2da_mem[mo_10 + 30]) << 0x10 | uint(c2da_mem[mo_10 + 31]) << 0x18) - 320 * (1 << 16)
        z_0 = 128 + P_Random() * 2 * (1 << 16)
        th_2 = P_SpawnMobj(x_0, y_0, z_0, 33u)
        let c2da_fresh266 : int = P_Random() * 512
        let c2da_fresh267 : uint = uint(c2da_fresh266)
        c2da_mem[th_2 + 120] = uint8(c2da_fresh267)
        c2da_mem[th_2 + 121] = uint8(c2da_fresh267 >> 0x8)
        c2da_mem[th_2 + 122] = uint8(c2da_fresh267 >> 0x10)
        c2da_mem[th_2 + 123] = uint8(c2da_fresh267 >> 0x18)
        P_SetMobjState(th_2, 799u)
        let c2da_fresh268 : int = int(uint(c2da_mem[th_2 + 144]) | uint(c2da_mem[th_2 + 145]) << 0x8 | uint(c2da_mem[th_2 + 146]) << 0x10 | uint(c2da_mem[th_2 + 147]) << 0x18) - int(P_Random() & 7)
        let c2da_fresh269 : uint = uint(c2da_fresh268)
        c2da_mem[th_2 + 144] = uint8(c2da_fresh269)
        c2da_mem[th_2 + 145] = uint8(c2da_fresh269 >> 0x8)
        c2da_mem[th_2 + 146] = uint8(c2da_fresh269 >> 0x10)
        c2da_mem[th_2 + 147] = uint8(c2da_fresh269 >> 0x18)
        if (int(uint(c2da_mem[th_2 + 144]) | uint(c2da_mem[th_2 + 145]) << 0x8 | uint(c2da_mem[th_2 + 146]) << 0x10 | uint(c2da_mem[th_2 + 147]) << 0x18) < 1) {
            let c2da_fresh270 : int = 1
            let c2da_fresh271 : uint = uint(c2da_fresh270)
            c2da_mem[th_2 + 144] = uint8(c2da_fresh271)
            c2da_mem[th_2 + 145] = uint8(c2da_fresh271 >> 0x8)
            c2da_mem[th_2 + 146] = uint8(c2da_fresh271 >> 0x10)
            c2da_mem[th_2 + 147] = uint8(c2da_fresh271 >> 0x18)
        }
        x_0 += (1 << 16) * 8
    }
    S_StartSound(0, 98)
    return
}
[export, sideeffects]
def A_BrainExplode(var mo_11 : int) {
    var x_1 : int
    var y_1 : int
    var z_1 : int
    var th_3 : int
    x_1 = int(uint(c2da_mem[mo_11 + 24]) | uint(c2da_mem[mo_11 + 25]) << 0x8 | uint(c2da_mem[mo_11 + 26]) << 0x10 | uint(c2da_mem[mo_11 + 27]) << 0x18) + (P_Random() - P_Random()) * 2048
    y_1 = int(uint(c2da_mem[mo_11 + 28]) | uint(c2da_mem[mo_11 + 29]) << 0x8 | uint(c2da_mem[mo_11 + 30]) << 0x10 | uint(c2da_mem[mo_11 + 31]) << 0x18)
    z_1 = 128 + P_Random() * 2 * (1 << 16)
    th_3 = P_SpawnMobj(x_1, y_1, z_1, 33u)
    let c2da_fresh272 : int = P_Random() * 512
    let c2da_fresh273 : uint = uint(c2da_fresh272)
    c2da_mem[th_3 + 120] = uint8(c2da_fresh273)
    c2da_mem[th_3 + 121] = uint8(c2da_fresh273 >> 0x8)
    c2da_mem[th_3 + 122] = uint8(c2da_fresh273 >> 0x10)
    c2da_mem[th_3 + 123] = uint8(c2da_fresh273 >> 0x18)
    P_SetMobjState(th_3, 799u)
    let c2da_fresh274 : int = int(uint(c2da_mem[th_3 + 144]) | uint(c2da_mem[th_3 + 145]) << 0x8 | uint(c2da_mem[th_3 + 146]) << 0x10 | uint(c2da_mem[th_3 + 147]) << 0x18) - int(P_Random() & 7)
    let c2da_fresh275 : uint = uint(c2da_fresh274)
    c2da_mem[th_3 + 144] = uint8(c2da_fresh275)
    c2da_mem[th_3 + 145] = uint8(c2da_fresh275 >> 0x8)
    c2da_mem[th_3 + 146] = uint8(c2da_fresh275 >> 0x10)
    c2da_mem[th_3 + 147] = uint8(c2da_fresh275 >> 0x18)
    if (int(uint(c2da_mem[th_3 + 144]) | uint(c2da_mem[th_3 + 145]) << 0x8 | uint(c2da_mem[th_3 + 146]) << 0x10 | uint(c2da_mem[th_3 + 147]) << 0x18) < 1) {
        let c2da_fresh276 : int = 1
        let c2da_fresh277 : uint = uint(c2da_fresh276)
        c2da_mem[th_3 + 144] = uint8(c2da_fresh277)
        c2da_mem[th_3 + 145] = uint8(c2da_fresh277 >> 0x8)
        c2da_mem[th_3 + 146] = uint8(c2da_fresh277 >> 0x10)
        c2da_mem[th_3 + 147] = uint8(c2da_fresh277 >> 0x18)
    }
    return
}
[export, sideeffects]
def A_BrainDie(var mo_12 : int) {
    G_ExitLevel()
    return
}
[export, sideeffects]
def A_BrainSpit(var mo_13 : int) {
    var targ_0 : int
    var newmobj_0 : int
    A_BrainSpit__easy ^= 1
    if (int(gameskill) <= 1 && A_BrainSpit__easy == 0) {
        return
    }
    targ_0 = braintargets[braintargeton]
    braintargeton = (braintargeton + 1) % numbraintargets
    newmobj_0 = P_SpawnMissile(mo_13, targ_0, 28u)
    let c2da_fresh278 : uint = uint(targ_0)
    c2da_mem[newmobj_0 + 176] = uint8(c2da_fresh278)
    c2da_mem[newmobj_0 + 177] = uint8(c2da_fresh278 >> 0x8)
    c2da_mem[newmobj_0 + 178] = uint8(c2da_fresh278 >> 0x10)
    c2da_mem[newmobj_0 + 179] = uint8(c2da_fresh278 >> 0x18)
    c2da_mem[newmobj_0 + 180] = 0u8
    c2da_mem[newmobj_0 + 181] = 0u8
    c2da_mem[newmobj_0 + 182] = 0u8
    c2da_mem[newmobj_0 + 183] = 0u8
    let c2da_fresh279 : int = int(uint(c2da_mem[newmobj_0 + 152]) | uint(c2da_mem[newmobj_0 + 153]) << 0x8 | uint(c2da_mem[newmobj_0 + 154]) << 0x10 | uint(c2da_mem[newmobj_0 + 155]) << 0x18) + 8
    let c2da_fresh280 : int = (int(uint(c2da_mem[targ_0 + 28]) | uint(c2da_mem[targ_0 + 29]) << 0x8 | uint(c2da_mem[targ_0 + 30]) << 0x10 | uint(c2da_mem[targ_0 + 31]) << 0x18) - int(uint(c2da_mem[mo_13 + 28]) | uint(c2da_mem[mo_13 + 29]) << 0x8 | uint(c2da_mem[mo_13 + 30]) << 0x10 | uint(c2da_mem[mo_13 + 31]) << 0x18)) / int(uint(c2da_mem[newmobj_0 + 116]) | uint(c2da_mem[newmobj_0 + 117]) << 0x8 | uint(c2da_mem[newmobj_0 + 118]) << 0x10 | uint(c2da_mem[newmobj_0 + 119]) << 0x18) / int(uint(c2da_mem[c2da_fresh279]) | uint(c2da_mem[c2da_fresh279 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh279 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh279 + 3]) << 0x18)
    let c2da_fresh281 : uint = uint(c2da_fresh280)
    c2da_mem[newmobj_0 + 184] = uint8(c2da_fresh281)
    c2da_mem[newmobj_0 + 185] = uint8(c2da_fresh281 >> 0x8)
    c2da_mem[newmobj_0 + 186] = uint8(c2da_fresh281 >> 0x10)
    c2da_mem[newmobj_0 + 187] = uint8(c2da_fresh281 >> 0x18)
    S_StartSound(0, 94)
    return
}
[export, sideeffects]
def A_SpawnFly(var mo_14 : int) {
    var newmobj_1 : int
    var fog_0 : int
    var targ_1 : int
    var r : int
    var type_0 : uint
    let c2da_fresh282 : int = int(uint(c2da_mem[mo_14 + 184]) | uint(c2da_mem[mo_14 + 185]) << 0x8 | uint(c2da_mem[mo_14 + 186]) << 0x10 | uint(c2da_mem[mo_14 + 187]) << 0x18)
    let c2da_fresh283 : int = c2da_fresh282 - 1
    let c2da_fresh284 : uint = uint(c2da_fresh283)
    c2da_mem[mo_14 + 184] = uint8(c2da_fresh284)
    c2da_mem[mo_14 + 185] = uint8(c2da_fresh284 >> 0x8)
    c2da_mem[mo_14 + 186] = uint8(c2da_fresh284 >> 0x10)
    c2da_mem[mo_14 + 187] = uint8(c2da_fresh284 >> 0x18)
    if (c2da_fresh283 != 0) {
        return
    }
    targ_1 = P_SubstNullMobj(int(uint(c2da_mem[mo_14 + 176]) | uint(c2da_mem[mo_14 + 177]) << 0x8 | uint(c2da_mem[mo_14 + 178]) << 0x10 | uint(c2da_mem[mo_14 + 179]) << 0x18))
    fog_0 = P_SpawnMobj(int(uint(c2da_mem[targ_1 + 24]) | uint(c2da_mem[targ_1 + 25]) << 0x8 | uint(c2da_mem[targ_1 + 26]) << 0x10 | uint(c2da_mem[targ_1 + 27]) << 0x18), int(uint(c2da_mem[targ_1 + 28]) | uint(c2da_mem[targ_1 + 29]) << 0x8 | uint(c2da_mem[targ_1 + 30]) << 0x10 | uint(c2da_mem[targ_1 + 31]) << 0x18), int(uint(c2da_mem[targ_1 + 32]) | uint(c2da_mem[targ_1 + 33]) << 0x8 | uint(c2da_mem[targ_1 + 34]) << 0x10 | uint(c2da_mem[targ_1 + 35]) << 0x18), 29u)
    S_StartSound(fog_0, 35)
    r = P_Random()
    if (r < 50) {
        type_0 = 11u
    } elif (r < 90) {
        type_0 = 12u
    } elif (r < 120) {
        type_0 = 13u
    } elif (r < 130) {
        type_0 = 22u
    } elif (r < 160) {
        type_0 = 14u
    } elif (r < 162) {
        type_0 = 3u
    } elif (r < 172) {
        type_0 = 5u
    } elif (r < 192) {
        type_0 = 20u
    } elif (r < 222) {
        type_0 = 8u
    } elif (r < 246) {
        type_0 = 17u
    } else {
        type_0 = 15u
    }
    newmobj_1 = P_SpawnMobj(int(uint(c2da_mem[targ_1 + 24]) | uint(c2da_mem[targ_1 + 25]) << 0x8 | uint(c2da_mem[targ_1 + 26]) << 0x10 | uint(c2da_mem[targ_1 + 27]) << 0x18), int(uint(c2da_mem[targ_1 + 28]) | uint(c2da_mem[targ_1 + 29]) << 0x8 | uint(c2da_mem[targ_1 + 30]) << 0x10 | uint(c2da_mem[targ_1 + 31]) << 0x18), int(uint(c2da_mem[targ_1 + 32]) | uint(c2da_mem[targ_1 + 33]) << 0x8 | uint(c2da_mem[targ_1 + 34]) << 0x10 | uint(c2da_mem[targ_1 + 35]) << 0x18), type_0)
    if (P_LookForPlayers(newmobj_1, 1u) != 0x0) {
        let c2da_fresh285 : int = int(uint(c2da_mem[newmobj_1 + 136]) | uint(c2da_mem[newmobj_1 + 137]) << 0x8 | uint(c2da_mem[newmobj_1 + 138]) << 0x10 | uint(c2da_mem[newmobj_1 + 139]) << 0x18) + 12
        P_SetMobjState(newmobj_1, uint(int(uint(c2da_mem[c2da_fresh285]) | uint(c2da_mem[c2da_fresh285 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh285 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh285 + 3]) << 0x18)))
    }
    P_TeleportMove(newmobj_1, int(uint(c2da_mem[newmobj_1 + 24]) | uint(c2da_mem[newmobj_1 + 25]) << 0x8 | uint(c2da_mem[newmobj_1 + 26]) << 0x10 | uint(c2da_mem[newmobj_1 + 27]) << 0x18), int(uint(c2da_mem[newmobj_1 + 28]) | uint(c2da_mem[newmobj_1 + 29]) << 0x8 | uint(c2da_mem[newmobj_1 + 30]) << 0x10 | uint(c2da_mem[newmobj_1 + 31]) << 0x18))
    P_RemoveMobj(mo_14)
    return
}
[export, sideeffects]
def A_SpawnSound(var mo_15 : int) {
    S_StartSound(mo_15, 95)
    A_SpawnFly(mo_15)
    return
}
[export, sideeffects]
def A_PlayerScream(var mo_16 : int) {
    var sound_1 : int = 57
    if (uint(gamemode) == 2u && int(uint(c2da_mem[mo_16 + 164]) | uint(c2da_mem[mo_16 + 165]) << 0x8 | uint(c2da_mem[mo_16 + 166]) << 0x10 | uint(c2da_mem[mo_16 + 167]) << 0x18) < -50) {
        sound_1 = 58
    }
    S_StartSound(mo_16, sound_1)
    return
}
[sideeffects]
def private A_KeenDie_c2da_frame(var mo : int; c2da_fp : int) {
    var th : int
    var mo2 : int
    A_Fall(mo)
    th = int(uint(c2da_mem[46552]) | uint(c2da_mem[46553]) << 0x8 | uint(c2da_mem[46554]) << 0x10 | uint(c2da_mem[46555]) << 0x18)
    while (th != 46544) {
        if (int(uint(c2da_mem[th + 16]) | uint(c2da_mem[th + 17]) << 0x8 | uint(c2da_mem[th + 18]) << 0x10 | uint(c2da_mem[th + 19]) << 0x18) != 126) {
            th = int(uint(c2da_mem[th + 8]) | uint(c2da_mem[th + 9]) << 0x8 | uint(c2da_mem[th + 10]) << 0x10 | uint(c2da_mem[th + 11]) << 0x18)
            continue
        }
        mo2 = th
        if (mo2 != mo && (uint(c2da_mem[mo2 + 128]) | uint(c2da_mem[mo2 + 129]) << 0x8 | uint(c2da_mem[mo2 + 130]) << 0x10 | uint(c2da_mem[mo2 + 131]) << 0x18) == (uint(c2da_mem[mo + 128]) | uint(c2da_mem[mo + 129]) << 0x8 | uint(c2da_mem[mo + 130]) << 0x10 | uint(c2da_mem[mo + 131]) << 0x18) && int(uint(c2da_mem[mo2 + 164]) | uint(c2da_mem[mo2 + 165]) << 0x8 | uint(c2da_mem[mo2 + 166]) << 0x10 | uint(c2da_mem[mo2 + 167]) << 0x18) > 0) {
            return
        }
        th = int(uint(c2da_mem[th + 8]) | uint(c2da_mem[th + 9]) << 0x8 | uint(c2da_mem[th + 10]) << 0x10 | uint(c2da_mem[th + 11]) << 0x18)
    }
    let c2da_fresh65 : int16 = int16(666)
    let c2da_fresh66 : uint = uint(c2da_fresh65)
    c2da_mem[c2da_fp + 28] = uint8(c2da_fresh66)
    c2da_mem[c2da_fp + 29] = uint8(c2da_fresh66 >> 0x8)
    EV_DoDoor(c2da_fp, 3u)
    return
}
[sideeffects]
def private A_BossDeath_c2da_frame(var mo_4 : int; c2da_fp : int) {
    var th_1 : int
    var mo2_0 : int
    var i_1 : int
    if (uint(gamemode) == 2u) {
        if (gamemap != 7) {
            return
        }
        if ((uint(c2da_mem[mo_4 + 128]) | uint(c2da_mem[mo_4 + 129]) << 0x8 | uint(c2da_mem[mo_4 + 130]) << 0x10 | uint(c2da_mem[mo_4 + 131]) << 0x18) != 8u && (uint(c2da_mem[mo_4 + 128]) | uint(c2da_mem[mo_4 + 129]) << 0x8 | uint(c2da_mem[mo_4 + 130]) << 0x10 | uint(c2da_mem[mo_4 + 131]) << 0x18) != 20u) {
            return
        }
    } elif (CheckBossEnd(uint(c2da_mem[mo_4 + 128]) | uint(c2da_mem[mo_4 + 129]) << 0x8 | uint(c2da_mem[mo_4 + 130]) << 0x10 | uint(c2da_mem[mo_4 + 131]) << 0x18) == 0) {
        return
    }
    i_1 = 0
    while (i_1 < 4) {
        if (playeringame[i_1] != 0x0 && int(uint(c2da_mem[96 + i_1 * 328 + 44]) | uint(c2da_mem[96 + i_1 * 328 + 45]) << 0x8 | uint(c2da_mem[96 + i_1 * 328 + 46]) << 0x10 | uint(c2da_mem[96 + i_1 * 328 + 47]) << 0x18) > 0) {
            break
        }
        i_1++
    }
    if (i_1 == 4) {
        return
    }
    th_1 = int(uint(c2da_mem[46552]) | uint(c2da_mem[46553]) << 0x8 | uint(c2da_mem[46554]) << 0x10 | uint(c2da_mem[46555]) << 0x18)
    while (th_1 != 46544) {
        if (int(uint(c2da_mem[th_1 + 16]) | uint(c2da_mem[th_1 + 17]) << 0x8 | uint(c2da_mem[th_1 + 18]) << 0x10 | uint(c2da_mem[th_1 + 19]) << 0x18) != 126) {
            th_1 = int(uint(c2da_mem[th_1 + 8]) | uint(c2da_mem[th_1 + 9]) << 0x8 | uint(c2da_mem[th_1 + 10]) << 0x10 | uint(c2da_mem[th_1 + 11]) << 0x18)
            continue
        }
        mo2_0 = th_1
        if (mo2_0 != mo_4 && (uint(c2da_mem[mo2_0 + 128]) | uint(c2da_mem[mo2_0 + 129]) << 0x8 | uint(c2da_mem[mo2_0 + 130]) << 0x10 | uint(c2da_mem[mo2_0 + 131]) << 0x18) == (uint(c2da_mem[mo_4 + 128]) | uint(c2da_mem[mo_4 + 129]) << 0x8 | uint(c2da_mem[mo_4 + 130]) << 0x10 | uint(c2da_mem[mo_4 + 131]) << 0x18) && int(uint(c2da_mem[mo2_0 + 164]) | uint(c2da_mem[mo2_0 + 165]) << 0x8 | uint(c2da_mem[mo2_0 + 166]) << 0x10 | uint(c2da_mem[mo2_0 + 167]) << 0x18) > 0) {
            return
        }
        th_1 = int(uint(c2da_mem[th_1 + 8]) | uint(c2da_mem[th_1 + 9]) << 0x8 | uint(c2da_mem[th_1 + 10]) << 0x10 | uint(c2da_mem[th_1 + 11]) << 0x18)
    }
    if (uint(gamemode) == 2u) {
        if (gamemap == 7) {
            if ((uint(c2da_mem[mo_4 + 128]) | uint(c2da_mem[mo_4 + 129]) << 0x8 | uint(c2da_mem[mo_4 + 130]) << 0x10 | uint(c2da_mem[mo_4 + 131]) << 0x18) == 8u) {
                let c2da_fresh256 : int16 = int16(666)
                let c2da_fresh257 : uint = uint(c2da_fresh256)
                c2da_mem[c2da_fp + 28] = uint8(c2da_fresh257)
                c2da_mem[c2da_fp + 29] = uint8(c2da_fresh257 >> 0x8)
                EV_DoFloor(c2da_fp, 1u)
                return
            }
            if ((uint(c2da_mem[mo_4 + 128]) | uint(c2da_mem[mo_4 + 129]) << 0x8 | uint(c2da_mem[mo_4 + 130]) << 0x10 | uint(c2da_mem[mo_4 + 131]) << 0x18) == 20u) {
                let c2da_fresh258 : int16 = int16(667)
                let c2da_fresh259 : uint = uint(c2da_fresh258)
                c2da_mem[c2da_fp + 28] = uint8(c2da_fresh259)
                c2da_mem[c2da_fp + 29] = uint8(c2da_fresh259 >> 0x8)
                EV_DoFloor(c2da_fp, 5u)
                return
            }
        }
    } elif (gameepisode == 1) {
        let c2da_fresh260 : int16 = int16(666)
        let c2da_fresh261 : uint = uint(c2da_fresh260)
        c2da_mem[c2da_fp + 28] = uint8(c2da_fresh261)
        c2da_mem[c2da_fp + 29] = uint8(c2da_fresh261 >> 0x8)
        EV_DoFloor(c2da_fp, 1u)
        return
    } elif (gameepisode == 4) {
        if (gamemap == 6) {
            let c2da_fresh262 : int16 = int16(666)
            let c2da_fresh263 : uint = uint(c2da_fresh262)
            c2da_mem[c2da_fp + 28] = uint8(c2da_fresh263)
            c2da_mem[c2da_fp + 29] = uint8(c2da_fresh263 >> 0x8)
            EV_DoDoor(c2da_fp, 6u)
            return
        } elif (gamemap == 8) {
            let c2da_fresh264 : int16 = int16(666)
            let c2da_fresh265 : uint = uint(c2da_fresh264)
            c2da_mem[c2da_fp + 28] = uint8(c2da_fresh265)
            c2da_mem[c2da_fp + 29] = uint8(c2da_fresh265 >> 0x8)
            EV_DoFloor(c2da_fp, 1u)
            return
        }
    }
    G_ExitLevel()
    return
}

// This unit's static data, at heap offset 359136.
let private c2da_lin_static_p_enemy_seg = fixed_array<int>(359136, 58)
let private c2da_lin_static_p_enemy = fixed_array<uint64>(0x6361206472696557ul, 0x766f6d3e2d726f74ul, 0x5f50002172696465ul, 0x657361684377654eul, 0x6c6163203a726944ul, 0x687469772064656cul, 0x67726174206f6e20ul, 0x7465ul)

[init]
def private c2da_lin_init_static_p_enemy() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_p_enemy_seg[s * 2]
        for (k in range(c2da_lin_static_p_enemy_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_p_enemy[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_p_enemy() {
    if (length(c2da_fn_table1) < 128) {
        resize(c2da_fn_table1, 128)
    }
    c2da_fn_table1[27] = @@A_OpenShotgun2
    c2da_fn_table1[28] = @@A_LoadShotgun2
    c2da_fn_table1[29] = @@A_CloseShotgun2
    if (length(c2da_fn_table5) < 128) {
        resize(c2da_fn_table5, 128)
    }
    c2da_fn_table5[41] = @@A_Fall
    c2da_fn_table5[80] = @@A_KeenDie
    c2da_fn_table5[43] = @@A_Look
    c2da_fn_table5[44] = @@A_Chase
    c2da_fn_table5[45] = @@A_FaceTarget
    c2da_fn_table5[46] = @@A_PosAttack
    c2da_fn_table5[48] = @@A_SPosAttack
    c2da_fn_table5[65] = @@A_CPosAttack
    c2da_fn_table5[66] = @@A_CPosRefire
    c2da_fn_table5[73] = @@A_SpidRefire
    c2da_fn_table5[75] = @@A_BspiAttack
    c2da_fn_table5[67] = @@A_TroopAttack
    c2da_fn_table5[68] = @@A_SargAttack
    c2da_fn_table5[69] = @@A_HeadAttack
    c2da_fn_table5[77] = @@A_CyberAttack
    c2da_fn_table5[70] = @@A_BruisAttack
    c2da_fn_table5[59] = @@A_SkelMissile
    c2da_fn_table5[56] = @@A_Tracer
    c2da_fn_table5[57] = @@A_SkelWhoosh
    c2da_fn_table5[58] = @@A_SkelFist
    c2da_fn_table5[49] = @@A_VileChase
    c2da_fn_table5[50] = @@A_VileStart
    c2da_fn_table5[54] = @@A_Fire
    c2da_fn_table5[53] = @@A_StartFire
    c2da_fn_table5[55] = @@A_FireCrackle
    c2da_fn_table5[51] = @@A_VileTarget
    c2da_fn_table5[52] = @@A_VileAttack
    c2da_fn_table5[60] = @@A_FatRaise
    c2da_fn_table5[61] = @@A_FatAttack1
    c2da_fn_table5[62] = @@A_FatAttack2
    c2da_fn_table5[63] = @@A_FatAttack3
    c2da_fn_table5[71] = @@A_SkullAttack
    c2da_fn_table5[78] = @@A_PainAttack
    c2da_fn_table5[79] = @@A_PainDie
    c2da_fn_table5[47] = @@A_Scream
    c2da_fn_table5[42] = @@A_XScream
    c2da_fn_table5[39] = @@A_Pain
    c2da_fn_table5[38] = @@A_Explode
    c2da_fn_table5[64] = @@A_BossDeath
    c2da_fn_table5[76] = @@A_Hoof
    c2da_fn_table5[72] = @@A_Metal
    c2da_fn_table5[74] = @@A_BabyMetal
    c2da_fn_table5[84] = @@A_BrainAwake
    c2da_fn_table5[81] = @@A_BrainPain
    c2da_fn_table5[82] = @@A_BrainScream
    c2da_fn_table5[88] = @@A_BrainExplode
    c2da_fn_table5[83] = @@A_BrainDie
    c2da_fn_table5[85] = @@A_BrainSpit
    c2da_fn_table5[87] = @@A_SpawnFly
    c2da_fn_table5[86] = @@A_SpawnSound
    c2da_fn_table5[40] = @@A_PlayerScream
    if (length(c2da_fn_table10) < 128) {
        resize(c2da_fn_table10, 128)
    }
    c2da_fn_table10[127] = @@PIT_VileCheck
}

[init]
def private c2da_lin_relink_init_p_enemy() {
    c2da_relink_p_enemy()
}
