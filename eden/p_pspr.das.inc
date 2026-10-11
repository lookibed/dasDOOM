[export, sideeffects]
def P_SetupPsprites(var player : int) {
    for (i in range(0, 2)) {
        let c2da_fresh0 : uint = 0u
        c2da_mem[player + 272 + i * 24] = uint8(c2da_fresh0)
        c2da_mem[player + 272 + i * 24 + 1] = uint8(c2da_fresh0 >> 0x8)
        c2da_mem[player + 272 + i * 24 + 2] = uint8(c2da_fresh0 >> 0x10)
        c2da_mem[player + 272 + i * 24 + 3] = uint8(c2da_fresh0 >> 0x18)
        c2da_mem[player + 272 + i * 24 + 4] = 0u8
        c2da_mem[player + 272 + i * 24 + 5] = 0u8
        c2da_mem[player + 272 + i * 24 + 6] = 0u8
        c2da_mem[player + 272 + i * 24 + 7] = 0u8
    }
    let c2da_fresh1 : uint = uint(c2da_mem[player + 124]) | uint(c2da_mem[player + 125]) << 0x8 | uint(c2da_mem[player + 126]) << 0x10 | uint(c2da_mem[player + 127]) << 0x18
    let c2da_fresh2 : uint = c2da_fresh1
    c2da_mem[player + 128] = uint8(c2da_fresh2)
    c2da_mem[player + 129] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[player + 130] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[player + 131] = uint8(c2da_fresh2 >> 0x18)
    P_BringUpWeapon(player)
    return
}
[export, sideeffects]
def P_BringUpWeapon(var player_0 : int) {
    var newstate : uint
    if ((uint(c2da_mem[player_0 + 128]) | uint(c2da_mem[player_0 + 129]) << 0x8 | uint(c2da_mem[player_0 + 130]) << 0x10 | uint(c2da_mem[player_0 + 131]) << 0x18) == 10u) {
        let c2da_fresh3 : uint = uint(c2da_mem[player_0 + 124]) | uint(c2da_mem[player_0 + 125]) << 0x8 | uint(c2da_mem[player_0 + 126]) << 0x10 | uint(c2da_mem[player_0 + 127]) << 0x18
        let c2da_fresh4 : uint = c2da_fresh3
        c2da_mem[player_0 + 128] = uint8(c2da_fresh4)
        c2da_mem[player_0 + 129] = uint8(c2da_fresh4 >> 0x8)
        c2da_mem[player_0 + 130] = uint8(c2da_fresh4 >> 0x10)
        c2da_mem[player_0 + 131] = uint8(c2da_fresh4 >> 0x18)
    }
    if ((uint(c2da_mem[player_0 + 128]) | uint(c2da_mem[player_0 + 129]) << 0x8 | uint(c2da_mem[player_0 + 130]) << 0x10 | uint(c2da_mem[player_0 + 131]) << 0x18) == 7u) {
        S_StartSound(int(uint(c2da_mem[player_0]) | uint(c2da_mem[player_0 + 1]) << 0x8 | uint(c2da_mem[player_0 + 2]) << 0x10 | uint(c2da_mem[player_0 + 3]) << 0x18), 10)
    }
    newstate = uint(weaponinfo[int(uint(c2da_mem[player_0 + 128]) | uint(c2da_mem[player_0 + 129]) << 0x8 | uint(c2da_mem[player_0 + 130]) << 0x10 | uint(c2da_mem[player_0 + 131]) << 0x18)].upstate)
    let c2da_fresh5 : uint = 10u
    let c2da_fresh6 : uint = c2da_fresh5
    c2da_mem[player_0 + 128] = uint8(c2da_fresh6)
    c2da_mem[player_0 + 129] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[player_0 + 130] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[player_0 + 131] = uint8(c2da_fresh6 >> 0x18)
    let c2da_fresh7 : int = 128 * (1 << 16)
    let c2da_fresh8 : uint = uint(c2da_fresh7)
    c2da_mem[player_0 + 272 + 0 * 24 + 16] = uint8(c2da_fresh8)
    c2da_mem[player_0 + 272 + 0 * 24 + 17] = uint8(c2da_fresh8 >> 0x8)
    c2da_mem[player_0 + 272 + 0 * 24 + 18] = uint8(c2da_fresh8 >> 0x10)
    c2da_mem[player_0 + 272 + 0 * 24 + 19] = uint8(c2da_fresh8 >> 0x18)
    P_SetPsprite(player_0, 0, newstate)
    return
}
[export, sideeffects]
def P_SetPsprite(var player_1 : int; var position : int; var stnum : uint) {
    var psp : int
    var state : int
    psp = player_1 + 272 + position * 24
    while (true) {
        if (stnum == 0u) {
            let c2da_fresh9 : uint = 0u
            c2da_mem[psp] = uint8(c2da_fresh9)
            c2da_mem[psp + 1] = uint8(c2da_fresh9 >> 0x8)
            c2da_mem[psp + 2] = uint8(c2da_fresh9 >> 0x10)
            c2da_mem[psp + 3] = uint8(c2da_fresh9 >> 0x18)
            c2da_mem[psp + 4] = 0u8
            c2da_mem[psp + 5] = 0u8
            c2da_mem[psp + 6] = 0u8
            c2da_mem[psp + 7] = 0u8
            break
        }
        state = 2080 + int(stnum) * 40
        let c2da_fresh10 : uint = uint(state)
        c2da_mem[psp] = uint8(c2da_fresh10)
        c2da_mem[psp + 1] = uint8(c2da_fresh10 >> 0x8)
        c2da_mem[psp + 2] = uint8(c2da_fresh10 >> 0x10)
        c2da_mem[psp + 3] = uint8(c2da_fresh10 >> 0x18)
        c2da_mem[psp + 4] = 0u8
        c2da_mem[psp + 5] = 0u8
        c2da_mem[psp + 6] = 0u8
        c2da_mem[psp + 7] = 0u8
        let c2da_fresh11 : int = int(uint(c2da_mem[state + 8]) | uint(c2da_mem[state + 9]) << 0x8 | uint(c2da_mem[state + 10]) << 0x10 | uint(c2da_mem[state + 11]) << 0x18)
        let c2da_fresh12 : uint = uint(c2da_fresh11)
        c2da_mem[psp + 8] = uint8(c2da_fresh12)
        c2da_mem[psp + 9] = uint8(c2da_fresh12 >> 0x8)
        c2da_mem[psp + 10] = uint8(c2da_fresh12 >> 0x10)
        c2da_mem[psp + 11] = uint8(c2da_fresh12 >> 0x18)
        if (int(uint(c2da_mem[state + 28]) | uint(c2da_mem[state + 29]) << 0x8 | uint(c2da_mem[state + 30]) << 0x10 | uint(c2da_mem[state + 31]) << 0x18) != 0) {
            let c2da_fresh13 : int = int(uint(c2da_mem[state + 28]) | uint(c2da_mem[state + 29]) << 0x8 | uint(c2da_mem[state + 30]) << 0x10 | uint(c2da_mem[state + 31]) << 0x18) << 16
            let c2da_fresh14 : uint = uint(c2da_fresh13)
            c2da_mem[psp + 12] = uint8(c2da_fresh14)
            c2da_mem[psp + 13] = uint8(c2da_fresh14 >> 0x8)
            c2da_mem[psp + 14] = uint8(c2da_fresh14 >> 0x10)
            c2da_mem[psp + 15] = uint8(c2da_fresh14 >> 0x18)
            let c2da_fresh15 : int = int(uint(c2da_mem[state + 32]) | uint(c2da_mem[state + 33]) << 0x8 | uint(c2da_mem[state + 34]) << 0x10 | uint(c2da_mem[state + 35]) << 0x18) << 16
            let c2da_fresh16 : uint = uint(c2da_fresh15)
            c2da_mem[psp + 16] = uint8(c2da_fresh16)
            c2da_mem[psp + 17] = uint8(c2da_fresh16 >> 0x8)
            c2da_mem[psp + 18] = uint8(c2da_fresh16 >> 0x10)
            c2da_mem[psp + 19] = uint8(c2da_fresh16 >> 0x18)
        }
        if (int(uint(c2da_mem[state + 16]) | uint(c2da_mem[state + 17]) << 0x8 | uint(c2da_mem[state + 18]) << 0x10 | uint(c2da_mem[state + 19]) << 0x18) != default<actionf_p2>) {
            invoke(c2da_fn_table1[int(uint(c2da_mem[state + 16]) | uint(c2da_mem[state + 17]) << 0x8 | uint(c2da_mem[state + 18]) << 0x10 | uint(c2da_mem[state + 19]) << 0x18)], player_1, psp)
            if (int(uint(c2da_mem[psp]) | uint(c2da_mem[psp + 1]) << 0x8 | uint(c2da_mem[psp + 2]) << 0x10 | uint(c2da_mem[psp + 3]) << 0x18) == 0) {
                break
            }
        }
        let c2da_fresh17 : int = int(uint(c2da_mem[psp]) | uint(c2da_mem[psp + 1]) << 0x8 | uint(c2da_mem[psp + 2]) << 0x10 | uint(c2da_mem[psp + 3]) << 0x18) + 24
        stnum = uint(c2da_mem[c2da_fresh17]) | uint(c2da_mem[c2da_fresh17 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh17 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh17 + 3]) << 0x18
        if (int(uint(c2da_mem[psp + 8]) | uint(c2da_mem[psp + 9]) << 0x8 | uint(c2da_mem[psp + 10]) << 0x10 | uint(c2da_mem[psp + 11]) << 0x18) != 0) {
            break
        }
    }
    return
}
[export, sideeffects]
def P_MovePsprites(var player_2 : int) {
    var i_0 : int
    var psp_0 : int
    var state_0 : int
    psp_0 = player_2 + 272 + 0 * 24
    i_0 = 0
    while (i_0 < 2) {
        state_0 = int(uint(c2da_mem[psp_0]) | uint(c2da_mem[psp_0 + 1]) << 0x8 | uint(c2da_mem[psp_0 + 2]) << 0x10 | uint(c2da_mem[psp_0 + 3]) << 0x18)
        if (state_0 != 0) {
            if (int(uint(c2da_mem[psp_0 + 8]) | uint(c2da_mem[psp_0 + 9]) << 0x8 | uint(c2da_mem[psp_0 + 10]) << 0x10 | uint(c2da_mem[psp_0 + 11]) << 0x18) != -1) {
                let c2da_fresh18 : int = int(uint(c2da_mem[psp_0 + 8]) | uint(c2da_mem[psp_0 + 9]) << 0x8 | uint(c2da_mem[psp_0 + 10]) << 0x10 | uint(c2da_mem[psp_0 + 11]) << 0x18)
                let c2da_fresh19 : int = c2da_fresh18 - 1
                let c2da_fresh20 : uint = uint(c2da_fresh19)
                c2da_mem[psp_0 + 8] = uint8(c2da_fresh20)
                c2da_mem[psp_0 + 9] = uint8(c2da_fresh20 >> 0x8)
                c2da_mem[psp_0 + 10] = uint8(c2da_fresh20 >> 0x10)
                c2da_mem[psp_0 + 11] = uint8(c2da_fresh20 >> 0x18)
                if (int(uint(c2da_mem[psp_0 + 8]) | uint(c2da_mem[psp_0 + 9]) << 0x8 | uint(c2da_mem[psp_0 + 10]) << 0x10 | uint(c2da_mem[psp_0 + 11]) << 0x18) == 0) {
                    let c2da_fresh21 : int = int(uint(c2da_mem[psp_0]) | uint(c2da_mem[psp_0 + 1]) << 0x8 | uint(c2da_mem[psp_0 + 2]) << 0x10 | uint(c2da_mem[psp_0 + 3]) << 0x18) + 24
                    P_SetPsprite(player_2, i_0, uint(c2da_mem[c2da_fresh21]) | uint(c2da_mem[c2da_fresh21 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh21 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh21 + 3]) << 0x18)
                }
            }
        }
        i_0++
        psp_0 += 24
    }
    let c2da_fresh22 : int = int(uint(c2da_mem[player_2 + 272 + 0 * 24 + 12]) | uint(c2da_mem[player_2 + 272 + 0 * 24 + 13]) << 0x8 | uint(c2da_mem[player_2 + 272 + 0 * 24 + 14]) << 0x10 | uint(c2da_mem[player_2 + 272 + 0 * 24 + 15]) << 0x18)
    let c2da_fresh23 : uint = uint(c2da_fresh22)
    c2da_mem[player_2 + 272 + 1 * 24 + 12] = uint8(c2da_fresh23)
    c2da_mem[player_2 + 272 + 1 * 24 + 13] = uint8(c2da_fresh23 >> 0x8)
    c2da_mem[player_2 + 272 + 1 * 24 + 14] = uint8(c2da_fresh23 >> 0x10)
    c2da_mem[player_2 + 272 + 1 * 24 + 15] = uint8(c2da_fresh23 >> 0x18)
    let c2da_fresh24 : int = int(uint(c2da_mem[player_2 + 272 + 0 * 24 + 16]) | uint(c2da_mem[player_2 + 272 + 0 * 24 + 17]) << 0x8 | uint(c2da_mem[player_2 + 272 + 0 * 24 + 18]) << 0x10 | uint(c2da_mem[player_2 + 272 + 0 * 24 + 19]) << 0x18)
    let c2da_fresh25 : uint = uint(c2da_fresh24)
    c2da_mem[player_2 + 272 + 1 * 24 + 16] = uint8(c2da_fresh25)
    c2da_mem[player_2 + 272 + 1 * 24 + 17] = uint8(c2da_fresh25 >> 0x8)
    c2da_mem[player_2 + 272 + 1 * 24 + 18] = uint8(c2da_fresh25 >> 0x10)
    c2da_mem[player_2 + 272 + 1 * 24 + 19] = uint8(c2da_fresh25 >> 0x18)
    return
}
[export, sideeffects]
def P_DropWeapon(var player_3 : int) {
    P_SetPsprite(player_3, 0, uint(weaponinfo[int(uint(c2da_mem[player_3 + 124]) | uint(c2da_mem[player_3 + 125]) << 0x8 | uint(c2da_mem[player_3 + 126]) << 0x10 | uint(c2da_mem[player_3 + 127]) << 0x18)].downstate))
    return
}
var swingx : int = default<int>

var swingy : int = default<int>

[export, sideeffects]
def P_CalcSwing(var player_4 : int) {
    var swing : int
    var angle : int
    swing = int(uint(c2da_mem[player_4 + 40]) | uint(c2da_mem[player_4 + 41]) << 0x8 | uint(c2da_mem[player_4 + 42]) << 0x10 | uint(c2da_mem[player_4 + 43]) << 0x18)
    angle = 8192 / 70 * leveltime & 8192 - 1
    swingx = FixedMul(swing, int(uint(c2da_mem[257920 + angle * 4]) | uint(c2da_mem[257920 + angle * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + angle * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + angle * 4 + 3]) << 0x18))
    angle = 8192 / 70 * leveltime + 8192 / 2 & 8192 - 1
    swingy = -FixedMul(swingx, int(uint(c2da_mem[257920 + angle * 4]) | uint(c2da_mem[257920 + angle * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + angle * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + angle * 4 + 3]) << 0x18))
    return
}
[export, sideeffects]
def P_CheckAmmo(var player_5 : int) : uint {
    var ammo : uint
    var count : int
    ammo = weaponinfo[int(uint(c2da_mem[player_5 + 124]) | uint(c2da_mem[player_5 + 125]) << 0x8 | uint(c2da_mem[player_5 + 126]) << 0x10 | uint(c2da_mem[player_5 + 127]) << 0x18)].ammo
    if ((uint(c2da_mem[player_5 + 124]) | uint(c2da_mem[player_5 + 125]) << 0x8 | uint(c2da_mem[player_5 + 126]) << 0x10 | uint(c2da_mem[player_5 + 127]) << 0x18) == 6u) {
        count = 40
    } elif ((uint(c2da_mem[player_5 + 124]) | uint(c2da_mem[player_5 + 125]) << 0x8 | uint(c2da_mem[player_5 + 126]) << 0x10 | uint(c2da_mem[player_5 + 127]) << 0x18) == 8u) {
        count = 2
    } else {
        count = 1
    }
    if (ammo == 5u || int(uint(c2da_mem[player_5 + 168 + int(ammo) * 4]) | uint(c2da_mem[player_5 + 168 + int(ammo) * 4 + 1]) << 0x8 | uint(c2da_mem[player_5 + 168 + int(ammo) * 4 + 2]) << 0x10 | uint(c2da_mem[player_5 + 168 + int(ammo) * 4 + 3]) << 0x18) >= count) {
        return 1u
    }
    while (true) {
        if ((uint(c2da_mem[player_5 + 132 + 5 * 4]) | uint(c2da_mem[player_5 + 132 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[player_5 + 132 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[player_5 + 132 + 5 * 4 + 3]) << 0x18) != 0x0 && int(uint(c2da_mem[player_5 + 168 + 2 * 4]) | uint(c2da_mem[player_5 + 168 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[player_5 + 168 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[player_5 + 168 + 2 * 4 + 3]) << 0x18) != 0 && uint(gamemode) != 0u) {
            let c2da_fresh26 : uint = 5u
            let c2da_fresh27 : uint = c2da_fresh26
            c2da_mem[player_5 + 128] = uint8(c2da_fresh27)
            c2da_mem[player_5 + 129] = uint8(c2da_fresh27 >> 0x8)
            c2da_mem[player_5 + 130] = uint8(c2da_fresh27 >> 0x10)
            c2da_mem[player_5 + 131] = uint8(c2da_fresh27 >> 0x18)
        } elif ((uint(c2da_mem[player_5 + 132 + 8 * 4]) | uint(c2da_mem[player_5 + 132 + 8 * 4 + 1]) << 0x8 | uint(c2da_mem[player_5 + 132 + 8 * 4 + 2]) << 0x10 | uint(c2da_mem[player_5 + 132 + 8 * 4 + 3]) << 0x18) != 0x0 && int(uint(c2da_mem[player_5 + 168 + 1 * 4]) | uint(c2da_mem[player_5 + 168 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[player_5 + 168 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[player_5 + 168 + 1 * 4 + 3]) << 0x18) > 2 && uint(gamemode) == 2u) {
            let c2da_fresh28 : uint = 8u
            let c2da_fresh29 : uint = c2da_fresh28
            c2da_mem[player_5 + 128] = uint8(c2da_fresh29)
            c2da_mem[player_5 + 129] = uint8(c2da_fresh29 >> 0x8)
            c2da_mem[player_5 + 130] = uint8(c2da_fresh29 >> 0x10)
            c2da_mem[player_5 + 131] = uint8(c2da_fresh29 >> 0x18)
        } elif ((uint(c2da_mem[player_5 + 132 + 3 * 4]) | uint(c2da_mem[player_5 + 132 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[player_5 + 132 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[player_5 + 132 + 3 * 4 + 3]) << 0x18) != 0x0 && int(uint(c2da_mem[player_5 + 168 + 0 * 4]) | uint(c2da_mem[player_5 + 168 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[player_5 + 168 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[player_5 + 168 + 0 * 4 + 3]) << 0x18) != 0) {
            let c2da_fresh30 : uint = 3u
            let c2da_fresh31 : uint = c2da_fresh30
            c2da_mem[player_5 + 128] = uint8(c2da_fresh31)
            c2da_mem[player_5 + 129] = uint8(c2da_fresh31 >> 0x8)
            c2da_mem[player_5 + 130] = uint8(c2da_fresh31 >> 0x10)
            c2da_mem[player_5 + 131] = uint8(c2da_fresh31 >> 0x18)
        } elif ((uint(c2da_mem[player_5 + 132 + 2 * 4]) | uint(c2da_mem[player_5 + 132 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[player_5 + 132 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[player_5 + 132 + 2 * 4 + 3]) << 0x18) != 0x0 && int(uint(c2da_mem[player_5 + 168 + 1 * 4]) | uint(c2da_mem[player_5 + 168 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[player_5 + 168 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[player_5 + 168 + 1 * 4 + 3]) << 0x18) != 0) {
            let c2da_fresh32 : uint = 2u
            let c2da_fresh33 : uint = c2da_fresh32
            c2da_mem[player_5 + 128] = uint8(c2da_fresh33)
            c2da_mem[player_5 + 129] = uint8(c2da_fresh33 >> 0x8)
            c2da_mem[player_5 + 130] = uint8(c2da_fresh33 >> 0x10)
            c2da_mem[player_5 + 131] = uint8(c2da_fresh33 >> 0x18)
        } elif (int(uint(c2da_mem[player_5 + 168 + 0 * 4]) | uint(c2da_mem[player_5 + 168 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[player_5 + 168 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[player_5 + 168 + 0 * 4 + 3]) << 0x18) != 0) {
            let c2da_fresh34 : uint = 1u
            let c2da_fresh35 : uint = c2da_fresh34
            c2da_mem[player_5 + 128] = uint8(c2da_fresh35)
            c2da_mem[player_5 + 129] = uint8(c2da_fresh35 >> 0x8)
            c2da_mem[player_5 + 130] = uint8(c2da_fresh35 >> 0x10)
            c2da_mem[player_5 + 131] = uint8(c2da_fresh35 >> 0x18)
        } elif ((uint(c2da_mem[player_5 + 132 + 7 * 4]) | uint(c2da_mem[player_5 + 132 + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[player_5 + 132 + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[player_5 + 132 + 7 * 4 + 3]) << 0x18) != 0x0) {
            let c2da_fresh36 : uint = 7u
            let c2da_fresh37 : uint = c2da_fresh36
            c2da_mem[player_5 + 128] = uint8(c2da_fresh37)
            c2da_mem[player_5 + 129] = uint8(c2da_fresh37 >> 0x8)
            c2da_mem[player_5 + 130] = uint8(c2da_fresh37 >> 0x10)
            c2da_mem[player_5 + 131] = uint8(c2da_fresh37 >> 0x18)
        } elif ((uint(c2da_mem[player_5 + 132 + 4 * 4]) | uint(c2da_mem[player_5 + 132 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[player_5 + 132 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[player_5 + 132 + 4 * 4 + 3]) << 0x18) != 0x0 && int(uint(c2da_mem[player_5 + 168 + 3 * 4]) | uint(c2da_mem[player_5 + 168 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[player_5 + 168 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[player_5 + 168 + 3 * 4 + 3]) << 0x18) != 0) {
            let c2da_fresh38 : uint = 4u
            let c2da_fresh39 : uint = c2da_fresh38
            c2da_mem[player_5 + 128] = uint8(c2da_fresh39)
            c2da_mem[player_5 + 129] = uint8(c2da_fresh39 >> 0x8)
            c2da_mem[player_5 + 130] = uint8(c2da_fresh39 >> 0x10)
            c2da_mem[player_5 + 131] = uint8(c2da_fresh39 >> 0x18)
        } elif ((uint(c2da_mem[player_5 + 132 + 6 * 4]) | uint(c2da_mem[player_5 + 132 + 6 * 4 + 1]) << 0x8 | uint(c2da_mem[player_5 + 132 + 6 * 4 + 2]) << 0x10 | uint(c2da_mem[player_5 + 132 + 6 * 4 + 3]) << 0x18) != 0x0 && int(uint(c2da_mem[player_5 + 168 + 2 * 4]) | uint(c2da_mem[player_5 + 168 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[player_5 + 168 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[player_5 + 168 + 2 * 4 + 3]) << 0x18) > 40 && uint(gamemode) != 0u) {
            let c2da_fresh40 : uint = 6u
            let c2da_fresh41 : uint = c2da_fresh40
            c2da_mem[player_5 + 128] = uint8(c2da_fresh41)
            c2da_mem[player_5 + 129] = uint8(c2da_fresh41 >> 0x8)
            c2da_mem[player_5 + 130] = uint8(c2da_fresh41 >> 0x10)
            c2da_mem[player_5 + 131] = uint8(c2da_fresh41 >> 0x18)
        } else {
            let c2da_fresh42 : uint = 0u
            let c2da_fresh43 : uint = c2da_fresh42
            c2da_mem[player_5 + 128] = uint8(c2da_fresh43)
            c2da_mem[player_5 + 129] = uint8(c2da_fresh43 >> 0x8)
            c2da_mem[player_5 + 130] = uint8(c2da_fresh43 >> 0x10)
            c2da_mem[player_5 + 131] = uint8(c2da_fresh43 >> 0x18)
        }
        if ((uint(c2da_mem[player_5 + 128]) | uint(c2da_mem[player_5 + 129]) << 0x8 | uint(c2da_mem[player_5 + 130]) << 0x10 | uint(c2da_mem[player_5 + 131]) << 0x18) != 10u) {
            break
        }
    }
    P_SetPsprite(player_5, 0, uint(weaponinfo[int(uint(c2da_mem[player_5 + 124]) | uint(c2da_mem[player_5 + 125]) << 0x8 | uint(c2da_mem[player_5 + 126]) << 0x10 | uint(c2da_mem[player_5 + 127]) << 0x18)].downstate))
    return 0u
}
[export, sideeffects]
def P_FireWeapon(var player_6 : int) {
    var newstate_0 : uint
    if (P_CheckAmmo(player_6) == 0) {
        return
    }
    P_SetMobjState(int(uint(c2da_mem[player_6]) | uint(c2da_mem[player_6 + 1]) << 0x8 | uint(c2da_mem[player_6 + 2]) << 0x10 | uint(c2da_mem[player_6 + 3]) << 0x18), 154u)
    newstate_0 = uint(weaponinfo[int(uint(c2da_mem[player_6 + 124]) | uint(c2da_mem[player_6 + 125]) << 0x8 | uint(c2da_mem[player_6 + 126]) << 0x10 | uint(c2da_mem[player_6 + 127]) << 0x18)].atkstate)
    P_SetPsprite(player_6, 0, newstate_0)
    P_NoiseAlert(int(uint(c2da_mem[player_6]) | uint(c2da_mem[player_6 + 1]) << 0x8 | uint(c2da_mem[player_6 + 2]) << 0x10 | uint(c2da_mem[player_6 + 3]) << 0x18), int(uint(c2da_mem[player_6]) | uint(c2da_mem[player_6 + 1]) << 0x8 | uint(c2da_mem[player_6 + 2]) << 0x10 | uint(c2da_mem[player_6 + 3]) << 0x18))
    return
}
[export, sideeffects]
def A_WeaponReady(var player_7 : int; var psp_1 : int) {
    var newstate_1 : uint
    var angle_0 : int
    let c2da_fresh44 : int = int(uint(c2da_mem[player_7]) | uint(c2da_mem[player_7 + 1]) << 0x8 | uint(c2da_mem[player_7 + 2]) << 0x10 | uint(c2da_mem[player_7 + 3]) << 0x18) + 152
    var c2da_fresh46 : int = 1
    if (!(int(uint(c2da_mem[c2da_fresh44]) | uint(c2da_mem[c2da_fresh44 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh44 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh44 + 3]) << 0x18) == 2080 + 154 * 40)) {
        let c2da_fresh45 : int = int(uint(c2da_mem[player_7]) | uint(c2da_mem[player_7 + 1]) << 0x8 | uint(c2da_mem[player_7 + 2]) << 0x10 | uint(c2da_mem[player_7 + 3]) << 0x18) + 152
        if (!(int(uint(c2da_mem[c2da_fresh45]) | uint(c2da_mem[c2da_fresh45 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh45 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh45 + 3]) << 0x18) == 2080 + 155 * 40)) {
            c2da_fresh46 = 0
        }
    }
    if (c2da_fresh46 != 0) {
        P_SetMobjState(int(uint(c2da_mem[player_7]) | uint(c2da_mem[player_7 + 1]) << 0x8 | uint(c2da_mem[player_7 + 2]) << 0x10 | uint(c2da_mem[player_7 + 3]) << 0x18), 149u)
    }
    if ((uint(c2da_mem[player_7 + 124]) | uint(c2da_mem[player_7 + 125]) << 0x8 | uint(c2da_mem[player_7 + 126]) << 0x10 | uint(c2da_mem[player_7 + 127]) << 0x18) == 7u && int(uint(c2da_mem[psp_1]) | uint(c2da_mem[psp_1 + 1]) << 0x8 | uint(c2da_mem[psp_1 + 2]) << 0x10 | uint(c2da_mem[psp_1 + 3]) << 0x18) == 2080 + 67 * 40) {
        S_StartSound(int(uint(c2da_mem[player_7]) | uint(c2da_mem[player_7 + 1]) << 0x8 | uint(c2da_mem[player_7 + 2]) << 0x10 | uint(c2da_mem[player_7 + 3]) << 0x18), 11)
    }
    if ((uint(c2da_mem[player_7 + 128]) | uint(c2da_mem[player_7 + 129]) << 0x8 | uint(c2da_mem[player_7 + 130]) << 0x10 | uint(c2da_mem[player_7 + 131]) << 0x18) != 10u || int(uint(c2da_mem[player_7 + 44]) | uint(c2da_mem[player_7 + 45]) << 0x8 | uint(c2da_mem[player_7 + 46]) << 0x10 | uint(c2da_mem[player_7 + 47]) << 0x18) == 0) {
        newstate_1 = uint(weaponinfo[int(uint(c2da_mem[player_7 + 124]) | uint(c2da_mem[player_7 + 125]) << 0x8 | uint(c2da_mem[player_7 + 126]) << 0x10 | uint(c2da_mem[player_7 + 127]) << 0x18)].downstate)
        P_SetPsprite(player_7, 0, newstate_1)
        return
    }
    if ((int(c2da_mem[player_7 + 17]) & 1) != 0) {
        if (int(uint(c2da_mem[player_7 + 200]) | uint(c2da_mem[player_7 + 201]) << 0x8 | uint(c2da_mem[player_7 + 202]) << 0x10 | uint(c2da_mem[player_7 + 203]) << 0x18) == 0 || (uint(c2da_mem[player_7 + 124]) | uint(c2da_mem[player_7 + 125]) << 0x8 | uint(c2da_mem[player_7 + 126]) << 0x10 | uint(c2da_mem[player_7 + 127]) << 0x18) != 4u && (uint(c2da_mem[player_7 + 124]) | uint(c2da_mem[player_7 + 125]) << 0x8 | uint(c2da_mem[player_7 + 126]) << 0x10 | uint(c2da_mem[player_7 + 127]) << 0x18) != 6u) {
            let c2da_fresh47 : int = 1
            let c2da_fresh48 : uint = uint(c2da_fresh47)
            c2da_mem[player_7 + 200] = uint8(c2da_fresh48)
            c2da_mem[player_7 + 201] = uint8(c2da_fresh48 >> 0x8)
            c2da_mem[player_7 + 202] = uint8(c2da_fresh48 >> 0x10)
            c2da_mem[player_7 + 203] = uint8(c2da_fresh48 >> 0x18)
            P_FireWeapon(player_7)
            return
        }
    } else {
        let c2da_fresh49 : int = 0
        let c2da_fresh50 : uint = uint(c2da_fresh49)
        c2da_mem[player_7 + 200] = uint8(c2da_fresh50)
        c2da_mem[player_7 + 201] = uint8(c2da_fresh50 >> 0x8)
        c2da_mem[player_7 + 202] = uint8(c2da_fresh50 >> 0x10)
        c2da_mem[player_7 + 203] = uint8(c2da_fresh50 >> 0x18)
    }
    angle_0 = 128 * leveltime & 8192 - 1
    let c2da_fresh51 : int = (1 << 16) + FixedMul(int(uint(c2da_mem[player_7 + 40]) | uint(c2da_mem[player_7 + 41]) << 0x8 | uint(c2da_mem[player_7 + 42]) << 0x10 | uint(c2da_mem[player_7 + 43]) << 0x18), int(uint(c2da_mem[finecosine + angle_0 * 4]) | uint(c2da_mem[finecosine + angle_0 * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + angle_0 * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + angle_0 * 4 + 3]) << 0x18))
    let c2da_fresh52 : uint = uint(c2da_fresh51)
    c2da_mem[psp_1 + 12] = uint8(c2da_fresh52)
    c2da_mem[psp_1 + 13] = uint8(c2da_fresh52 >> 0x8)
    c2da_mem[psp_1 + 14] = uint8(c2da_fresh52 >> 0x10)
    c2da_mem[psp_1 + 15] = uint8(c2da_fresh52 >> 0x18)
    angle_0 &= 8192 / 2 - 1
    let c2da_fresh53 : int = 32 * (1 << 16) + FixedMul(int(uint(c2da_mem[player_7 + 40]) | uint(c2da_mem[player_7 + 41]) << 0x8 | uint(c2da_mem[player_7 + 42]) << 0x10 | uint(c2da_mem[player_7 + 43]) << 0x18), int(uint(c2da_mem[257920 + angle_0 * 4]) | uint(c2da_mem[257920 + angle_0 * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + angle_0 * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + angle_0 * 4 + 3]) << 0x18))
    let c2da_fresh54 : uint = uint(c2da_fresh53)
    c2da_mem[psp_1 + 16] = uint8(c2da_fresh54)
    c2da_mem[psp_1 + 17] = uint8(c2da_fresh54 >> 0x8)
    c2da_mem[psp_1 + 18] = uint8(c2da_fresh54 >> 0x10)
    c2da_mem[psp_1 + 19] = uint8(c2da_fresh54 >> 0x18)
    return
}
[export, sideeffects]
def A_ReFire(var player_8 : int; var psp_2 : int) {
    if ((int(c2da_mem[player_8 + 17]) & 1) != 0 && (uint(c2da_mem[player_8 + 128]) | uint(c2da_mem[player_8 + 129]) << 0x8 | uint(c2da_mem[player_8 + 130]) << 0x10 | uint(c2da_mem[player_8 + 131]) << 0x18) == 10u && int(uint(c2da_mem[player_8 + 44]) | uint(c2da_mem[player_8 + 45]) << 0x8 | uint(c2da_mem[player_8 + 46]) << 0x10 | uint(c2da_mem[player_8 + 47]) << 0x18) != 0) {
        let c2da_fresh55 : int = int(uint(c2da_mem[player_8 + 212]) | uint(c2da_mem[player_8 + 213]) << 0x8 | uint(c2da_mem[player_8 + 214]) << 0x10 | uint(c2da_mem[player_8 + 215]) << 0x18)
        let c2da_fresh56 : int = c2da_fresh55 + 1
        let c2da_fresh57 : uint = uint(c2da_fresh56)
        c2da_mem[player_8 + 212] = uint8(c2da_fresh57)
        c2da_mem[player_8 + 213] = uint8(c2da_fresh57 >> 0x8)
        c2da_mem[player_8 + 214] = uint8(c2da_fresh57 >> 0x10)
        c2da_mem[player_8 + 215] = uint8(c2da_fresh57 >> 0x18)
        P_FireWeapon(player_8)
    } else {
        let c2da_fresh58 : int = 0
        let c2da_fresh59 : uint = uint(c2da_fresh58)
        c2da_mem[player_8 + 212] = uint8(c2da_fresh59)
        c2da_mem[player_8 + 213] = uint8(c2da_fresh59 >> 0x8)
        c2da_mem[player_8 + 214] = uint8(c2da_fresh59 >> 0x10)
        c2da_mem[player_8 + 215] = uint8(c2da_fresh59 >> 0x18)
        P_CheckAmmo(player_8)
    }
    return
}
[export, sideeffects]
def A_CheckReload(var player_9 : int; var psp_3 : int) {
    P_CheckAmmo(player_9)
    return
}
[export, sideeffects]
def A_Lower(var player_10 : int; var psp_4 : int) {
    let c2da_fresh60 : int = int(uint(c2da_mem[psp_4 + 16]) | uint(c2da_mem[psp_4 + 17]) << 0x8 | uint(c2da_mem[psp_4 + 18]) << 0x10 | uint(c2da_mem[psp_4 + 19]) << 0x18) + (1 << 16) * 6
    let c2da_fresh61 : uint = uint(c2da_fresh60)
    c2da_mem[psp_4 + 16] = uint8(c2da_fresh61)
    c2da_mem[psp_4 + 17] = uint8(c2da_fresh61 >> 0x8)
    c2da_mem[psp_4 + 18] = uint8(c2da_fresh61 >> 0x10)
    c2da_mem[psp_4 + 19] = uint8(c2da_fresh61 >> 0x18)
    if (int(uint(c2da_mem[psp_4 + 16]) | uint(c2da_mem[psp_4 + 17]) << 0x8 | uint(c2da_mem[psp_4 + 18]) << 0x10 | uint(c2da_mem[psp_4 + 19]) << 0x18) < 128 * (1 << 16)) {
        return
    }
    if ((uint(c2da_mem[player_10 + 8]) | uint(c2da_mem[player_10 + 9]) << 0x8 | uint(c2da_mem[player_10 + 10]) << 0x10 | uint(c2da_mem[player_10 + 11]) << 0x18) == 1u) {
        let c2da_fresh62 : int = 128 * (1 << 16)
        let c2da_fresh63 : uint = uint(c2da_fresh62)
        c2da_mem[psp_4 + 16] = uint8(c2da_fresh63)
        c2da_mem[psp_4 + 17] = uint8(c2da_fresh63 >> 0x8)
        c2da_mem[psp_4 + 18] = uint8(c2da_fresh63 >> 0x10)
        c2da_mem[psp_4 + 19] = uint8(c2da_fresh63 >> 0x18)
        return
    }
    if (int(uint(c2da_mem[player_10 + 44]) | uint(c2da_mem[player_10 + 45]) << 0x8 | uint(c2da_mem[player_10 + 46]) << 0x10 | uint(c2da_mem[player_10 + 47]) << 0x18) == 0) {
        P_SetPsprite(player_10, 0, 0u)
        return
    }
    let c2da_fresh64 : uint = uint(c2da_mem[player_10 + 128]) | uint(c2da_mem[player_10 + 129]) << 0x8 | uint(c2da_mem[player_10 + 130]) << 0x10 | uint(c2da_mem[player_10 + 131]) << 0x18
    let c2da_fresh65 : uint = c2da_fresh64
    c2da_mem[player_10 + 124] = uint8(c2da_fresh65)
    c2da_mem[player_10 + 125] = uint8(c2da_fresh65 >> 0x8)
    c2da_mem[player_10 + 126] = uint8(c2da_fresh65 >> 0x10)
    c2da_mem[player_10 + 127] = uint8(c2da_fresh65 >> 0x18)
    P_BringUpWeapon(player_10)
    return
}
[export, sideeffects]
def A_Raise(var player_11 : int; var psp_5 : int) {
    var newstate_2 : uint
    let c2da_fresh66 : int = int(uint(c2da_mem[psp_5 + 16]) | uint(c2da_mem[psp_5 + 17]) << 0x8 | uint(c2da_mem[psp_5 + 18]) << 0x10 | uint(c2da_mem[psp_5 + 19]) << 0x18) - (1 << 16) * 6
    let c2da_fresh67 : uint = uint(c2da_fresh66)
    c2da_mem[psp_5 + 16] = uint8(c2da_fresh67)
    c2da_mem[psp_5 + 17] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[psp_5 + 18] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[psp_5 + 19] = uint8(c2da_fresh67 >> 0x18)
    if (int(uint(c2da_mem[psp_5 + 16]) | uint(c2da_mem[psp_5 + 17]) << 0x8 | uint(c2da_mem[psp_5 + 18]) << 0x10 | uint(c2da_mem[psp_5 + 19]) << 0x18) > 32 * (1 << 16)) {
        return
    }
    let c2da_fresh68 : int = 32 * (1 << 16)
    let c2da_fresh69 : uint = uint(c2da_fresh68)
    c2da_mem[psp_5 + 16] = uint8(c2da_fresh69)
    c2da_mem[psp_5 + 17] = uint8(c2da_fresh69 >> 0x8)
    c2da_mem[psp_5 + 18] = uint8(c2da_fresh69 >> 0x10)
    c2da_mem[psp_5 + 19] = uint8(c2da_fresh69 >> 0x18)
    newstate_2 = uint(weaponinfo[int(uint(c2da_mem[player_11 + 124]) | uint(c2da_mem[player_11 + 125]) << 0x8 | uint(c2da_mem[player_11 + 126]) << 0x10 | uint(c2da_mem[player_11 + 127]) << 0x18)].readystate)
    P_SetPsprite(player_11, 0, newstate_2)
    return
}
[export, sideeffects]
def A_GunFlash(var player_12 : int; var psp_6 : int) {
    P_SetMobjState(int(uint(c2da_mem[player_12]) | uint(c2da_mem[player_12 + 1]) << 0x8 | uint(c2da_mem[player_12 + 2]) << 0x10 | uint(c2da_mem[player_12 + 3]) << 0x18), 155u)
    P_SetPsprite(player_12, 1, uint(weaponinfo[int(uint(c2da_mem[player_12 + 124]) | uint(c2da_mem[player_12 + 125]) << 0x8 | uint(c2da_mem[player_12 + 126]) << 0x10 | uint(c2da_mem[player_12 + 127]) << 0x18)].flashstate))
    return
}
[export, sideeffects]
def A_Punch(var player_13 : int; var psp_7 : int) {
    var angle_1 : uint
    var damage : int
    var slope : int
    damage = P_Random() % 10 + 1 << 1
    if (int(uint(c2da_mem[player_13 + 56 + 1 * 4]) | uint(c2da_mem[player_13 + 56 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[player_13 + 56 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[player_13 + 56 + 1 * 4 + 3]) << 0x18) != 0) {
        damage *= 10
    }
    let c2da_fresh70 : int = int(uint(c2da_mem[player_13]) | uint(c2da_mem[player_13 + 1]) << 0x8 | uint(c2da_mem[player_13 + 2]) << 0x10 | uint(c2da_mem[player_13 + 3]) << 0x18) + 56
    angle_1 = uint(c2da_mem[c2da_fresh70]) | uint(c2da_mem[c2da_fresh70 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh70 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh70 + 3]) << 0x18
    angle_1 = angle_1 + uint(P_Random() - P_Random() << 18)
    slope = P_AimLineAttack(int(uint(c2da_mem[player_13]) | uint(c2da_mem[player_13 + 1]) << 0x8 | uint(c2da_mem[player_13 + 2]) << 0x10 | uint(c2da_mem[player_13 + 3]) << 0x18), angle_1, 64 * (1 << 16))
    P_LineAttack(int(uint(c2da_mem[player_13]) | uint(c2da_mem[player_13 + 1]) << 0x8 | uint(c2da_mem[player_13 + 2]) << 0x10 | uint(c2da_mem[player_13 + 3]) << 0x18), angle_1, 64 * (1 << 16), slope, damage)
    if (linetarget != 0) {
        S_StartSound(int(uint(c2da_mem[player_13]) | uint(c2da_mem[player_13 + 1]) << 0x8 | uint(c2da_mem[player_13 + 2]) << 0x10 | uint(c2da_mem[player_13 + 3]) << 0x18), 83)
        let c2da_fresh71 : int = int(uint(c2da_mem[player_13]) | uint(c2da_mem[player_13 + 1]) << 0x8 | uint(c2da_mem[player_13 + 2]) << 0x10 | uint(c2da_mem[player_13 + 3]) << 0x18) + 56
        let c2da_fresh72 : int = int(uint(c2da_mem[player_13]) | uint(c2da_mem[player_13 + 1]) << 0x8 | uint(c2da_mem[player_13 + 2]) << 0x10 | uint(c2da_mem[player_13 + 3]) << 0x18) + 24
        let c2da_fresh73 : int = int(uint(c2da_mem[player_13]) | uint(c2da_mem[player_13 + 1]) << 0x8 | uint(c2da_mem[player_13 + 2]) << 0x10 | uint(c2da_mem[player_13 + 3]) << 0x18) + 28
        let c2da_fresh74 : uint = R_PointToAngle2(int(uint(c2da_mem[c2da_fresh72]) | uint(c2da_mem[c2da_fresh72 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh72 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh72 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh73]) | uint(c2da_mem[c2da_fresh73 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh73 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh73 + 3]) << 0x18), int(uint(c2da_mem[linetarget + 24]) | uint(c2da_mem[linetarget + 25]) << 0x8 | uint(c2da_mem[linetarget + 26]) << 0x10 | uint(c2da_mem[linetarget + 27]) << 0x18), int(uint(c2da_mem[linetarget + 28]) | uint(c2da_mem[linetarget + 29]) << 0x8 | uint(c2da_mem[linetarget + 30]) << 0x10 | uint(c2da_mem[linetarget + 31]) << 0x18))
        let c2da_fresh75 : uint = c2da_fresh74
        c2da_mem[c2da_fresh71] = uint8(c2da_fresh75)
        c2da_mem[c2da_fresh71 + 1] = uint8(c2da_fresh75 >> 0x8)
        c2da_mem[c2da_fresh71 + 2] = uint8(c2da_fresh75 >> 0x10)
        c2da_mem[c2da_fresh71 + 3] = uint8(c2da_fresh75 >> 0x18)
    }
    return
}
[export, sideeffects]
def A_Saw(var player_14 : int; var psp_8 : int) {
    var angle_2 : uint
    var damage_0 : int
    var slope_0 : int
    damage_0 = 2 * (P_Random() % 10 + 1)
    let c2da_fresh76 : int = int(uint(c2da_mem[player_14]) | uint(c2da_mem[player_14 + 1]) << 0x8 | uint(c2da_mem[player_14 + 2]) << 0x10 | uint(c2da_mem[player_14 + 3]) << 0x18) + 56
    angle_2 = uint(c2da_mem[c2da_fresh76]) | uint(c2da_mem[c2da_fresh76 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh76 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh76 + 3]) << 0x18
    angle_2 = angle_2 + uint(P_Random() - P_Random() << 18)
    slope_0 = P_AimLineAttack(int(uint(c2da_mem[player_14]) | uint(c2da_mem[player_14 + 1]) << 0x8 | uint(c2da_mem[player_14 + 2]) << 0x10 | uint(c2da_mem[player_14 + 3]) << 0x18), angle_2, 64 * (1 << 16) + 1)
    P_LineAttack(int(uint(c2da_mem[player_14]) | uint(c2da_mem[player_14 + 1]) << 0x8 | uint(c2da_mem[player_14 + 2]) << 0x10 | uint(c2da_mem[player_14 + 3]) << 0x18), angle_2, 64 * (1 << 16) + 1, slope_0, damage_0)
    if (linetarget == 0) {
        S_StartSound(int(uint(c2da_mem[player_14]) | uint(c2da_mem[player_14 + 1]) << 0x8 | uint(c2da_mem[player_14 + 2]) << 0x10 | uint(c2da_mem[player_14 + 3]) << 0x18), 12)
        return
    }
    S_StartSound(int(uint(c2da_mem[player_14]) | uint(c2da_mem[player_14 + 1]) << 0x8 | uint(c2da_mem[player_14 + 2]) << 0x10 | uint(c2da_mem[player_14 + 3]) << 0x18), 13)
    let c2da_fresh77 : int = int(uint(c2da_mem[player_14]) | uint(c2da_mem[player_14 + 1]) << 0x8 | uint(c2da_mem[player_14 + 2]) << 0x10 | uint(c2da_mem[player_14 + 3]) << 0x18) + 24
    let c2da_fresh78 : int = int(uint(c2da_mem[player_14]) | uint(c2da_mem[player_14 + 1]) << 0x8 | uint(c2da_mem[player_14 + 2]) << 0x10 | uint(c2da_mem[player_14 + 3]) << 0x18) + 28
    angle_2 = uint(R_PointToAngle2(int(uint(c2da_mem[c2da_fresh77]) | uint(c2da_mem[c2da_fresh77 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh77 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh77 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh78]) | uint(c2da_mem[c2da_fresh78 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh78 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh78 + 3]) << 0x18), int(uint(c2da_mem[linetarget + 24]) | uint(c2da_mem[linetarget + 25]) << 0x8 | uint(c2da_mem[linetarget + 26]) << 0x10 | uint(c2da_mem[linetarget + 27]) << 0x18), int(uint(c2da_mem[linetarget + 28]) | uint(c2da_mem[linetarget + 29]) << 0x8 | uint(c2da_mem[linetarget + 30]) << 0x10 | uint(c2da_mem[linetarget + 31]) << 0x18)))
    let c2da_fresh79 : int = int(uint(c2da_mem[player_14]) | uint(c2da_mem[player_14 + 1]) << 0x8 | uint(c2da_mem[player_14 + 2]) << 0x10 | uint(c2da_mem[player_14 + 3]) << 0x18) + 56
    if (angle_2 - (uint(c2da_mem[c2da_fresh79]) | uint(c2da_mem[c2da_fresh79 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh79 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh79 + 3]) << 0x18) > 0x80000000u) {
        let c2da_fresh80 : int = int(uint(c2da_mem[player_14]) | uint(c2da_mem[player_14 + 1]) << 0x8 | uint(c2da_mem[player_14 + 2]) << 0x10 | uint(c2da_mem[player_14 + 3]) << 0x18) + 56
        if (int(angle_2 - (uint(c2da_mem[c2da_fresh80]) | uint(c2da_mem[c2da_fresh80 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh80 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh80 + 3]) << 0x18)) < -1073741824 / 20) {
            let c2da_fresh81 : int = int(uint(c2da_mem[player_14]) | uint(c2da_mem[player_14 + 1]) << 0x8 | uint(c2da_mem[player_14 + 2]) << 0x10 | uint(c2da_mem[player_14 + 3]) << 0x18) + 56
            let c2da_fresh82 : uint = angle_2 + uint(1073741824 / 21)
            let c2da_fresh83 : uint = c2da_fresh82
            c2da_mem[c2da_fresh81] = uint8(c2da_fresh83)
            c2da_mem[c2da_fresh81 + 1] = uint8(c2da_fresh83 >> 0x8)
            c2da_mem[c2da_fresh81 + 2] = uint8(c2da_fresh83 >> 0x10)
            c2da_mem[c2da_fresh81 + 3] = uint8(c2da_fresh83 >> 0x18)
        } else {
            let c2da_fresh84 : int = int(uint(c2da_mem[player_14]) | uint(c2da_mem[player_14 + 1]) << 0x8 | uint(c2da_mem[player_14 + 2]) << 0x10 | uint(c2da_mem[player_14 + 3]) << 0x18) + 56
            let c2da_fresh85 : uint = (uint(c2da_mem[c2da_fresh84]) | uint(c2da_mem[c2da_fresh84 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh84 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh84 + 3]) << 0x18) - uint(1073741824 / 20)
            let c2da_fresh86 : uint = c2da_fresh85
            c2da_mem[c2da_fresh84] = uint8(c2da_fresh86)
            c2da_mem[c2da_fresh84 + 1] = uint8(c2da_fresh86 >> 0x8)
            c2da_mem[c2da_fresh84 + 2] = uint8(c2da_fresh86 >> 0x10)
            c2da_mem[c2da_fresh84 + 3] = uint8(c2da_fresh86 >> 0x18)
        }
    } else {
        let c2da_fresh87 : int = int(uint(c2da_mem[player_14]) | uint(c2da_mem[player_14 + 1]) << 0x8 | uint(c2da_mem[player_14 + 2]) << 0x10 | uint(c2da_mem[player_14 + 3]) << 0x18) + 56
        if (angle_2 - (uint(c2da_mem[c2da_fresh87]) | uint(c2da_mem[c2da_fresh87 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh87 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh87 + 3]) << 0x18) > uint(1073741824 / 20)) {
            let c2da_fresh88 : int = int(uint(c2da_mem[player_14]) | uint(c2da_mem[player_14 + 1]) << 0x8 | uint(c2da_mem[player_14 + 2]) << 0x10 | uint(c2da_mem[player_14 + 3]) << 0x18) + 56
            let c2da_fresh89 : uint = angle_2 - uint(1073741824 / 21)
            let c2da_fresh90 : uint = c2da_fresh89
            c2da_mem[c2da_fresh88] = uint8(c2da_fresh90)
            c2da_mem[c2da_fresh88 + 1] = uint8(c2da_fresh90 >> 0x8)
            c2da_mem[c2da_fresh88 + 2] = uint8(c2da_fresh90 >> 0x10)
            c2da_mem[c2da_fresh88 + 3] = uint8(c2da_fresh90 >> 0x18)
        } else {
            let c2da_fresh91 : int = int(uint(c2da_mem[player_14]) | uint(c2da_mem[player_14 + 1]) << 0x8 | uint(c2da_mem[player_14 + 2]) << 0x10 | uint(c2da_mem[player_14 + 3]) << 0x18) + 56
            let c2da_fresh92 : uint = (uint(c2da_mem[c2da_fresh91]) | uint(c2da_mem[c2da_fresh91 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh91 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh91 + 3]) << 0x18) + uint(1073741824 / 20)
            let c2da_fresh93 : uint = c2da_fresh92
            c2da_mem[c2da_fresh91] = uint8(c2da_fresh93)
            c2da_mem[c2da_fresh91 + 1] = uint8(c2da_fresh93 >> 0x8)
            c2da_mem[c2da_fresh91 + 2] = uint8(c2da_fresh93 >> 0x10)
            c2da_mem[c2da_fresh91 + 3] = uint8(c2da_fresh93 >> 0x18)
        }
    }
    let c2da_fresh94 : int = int(uint(c2da_mem[player_14]) | uint(c2da_mem[player_14 + 1]) << 0x8 | uint(c2da_mem[player_14 + 2]) << 0x10 | uint(c2da_mem[player_14 + 3]) << 0x18) + 160
    let c2da_fresh95 : int = int(uint(c2da_mem[c2da_fresh94]) | uint(c2da_mem[c2da_fresh94 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh94 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh94 + 3]) << 0x18) | 128
    let c2da_fresh96 : uint = uint(c2da_fresh95)
    c2da_mem[c2da_fresh94] = uint8(c2da_fresh96)
    c2da_mem[c2da_fresh94 + 1] = uint8(c2da_fresh96 >> 0x8)
    c2da_mem[c2da_fresh94 + 2] = uint8(c2da_fresh96 >> 0x10)
    c2da_mem[c2da_fresh94 + 3] = uint8(c2da_fresh96 >> 0x18)
    return
}
[sideeffects]
def private DecreaseAmmo(var player_15 : int; var ammonum : int; var amount : int) {
    if (ammonum < 4) {
        let c2da_fresh97 : int = int(uint(c2da_mem[player_15 + 168 + ammonum * 4]) | uint(c2da_mem[player_15 + 168 + ammonum * 4 + 1]) << 0x8 | uint(c2da_mem[player_15 + 168 + ammonum * 4 + 2]) << 0x10 | uint(c2da_mem[player_15 + 168 + ammonum * 4 + 3]) << 0x18) - amount
        let c2da_fresh98 : uint = uint(c2da_fresh97)
        c2da_mem[player_15 + 168 + ammonum * 4] = uint8(c2da_fresh98)
        c2da_mem[player_15 + 168 + ammonum * 4 + 1] = uint8(c2da_fresh98 >> 0x8)
        c2da_mem[player_15 + 168 + ammonum * 4 + 2] = uint8(c2da_fresh98 >> 0x10)
        c2da_mem[player_15 + 168 + ammonum * 4 + 3] = uint8(c2da_fresh98 >> 0x18)
    } else {
        let c2da_fresh99 : int = int(uint(c2da_mem[player_15 + 184 + (ammonum - 4) * 4]) | uint(c2da_mem[player_15 + 184 + (ammonum - 4) * 4 + 1]) << 0x8 | uint(c2da_mem[player_15 + 184 + (ammonum - 4) * 4 + 2]) << 0x10 | uint(c2da_mem[player_15 + 184 + (ammonum - 4) * 4 + 3]) << 0x18) - amount
        let c2da_fresh100 : uint = uint(c2da_fresh99)
        c2da_mem[player_15 + 184 + (ammonum - 4) * 4] = uint8(c2da_fresh100)
        c2da_mem[player_15 + 184 + (ammonum - 4) * 4 + 1] = uint8(c2da_fresh100 >> 0x8)
        c2da_mem[player_15 + 184 + (ammonum - 4) * 4 + 2] = uint8(c2da_fresh100 >> 0x10)
        c2da_mem[player_15 + 184 + (ammonum - 4) * 4 + 3] = uint8(c2da_fresh100 >> 0x18)
    }
    return
}
[export, sideeffects]
def A_FireMissile(var player_16 : int; var psp_9 : int) {
    DecreaseAmmo(player_16, int(weaponinfo[int(uint(c2da_mem[player_16 + 124]) | uint(c2da_mem[player_16 + 125]) << 0x8 | uint(c2da_mem[player_16 + 126]) << 0x10 | uint(c2da_mem[player_16 + 127]) << 0x18)].ammo), 1)
    P_SpawnPlayerMissile(int(uint(c2da_mem[player_16]) | uint(c2da_mem[player_16 + 1]) << 0x8 | uint(c2da_mem[player_16 + 2]) << 0x10 | uint(c2da_mem[player_16 + 3]) << 0x18), 33u)
    return
}
[export, sideeffects]
def A_FireBFG(var player_17 : int; var psp_10 : int) {
    DecreaseAmmo(player_17, int(weaponinfo[int(uint(c2da_mem[player_17 + 124]) | uint(c2da_mem[player_17 + 125]) << 0x8 | uint(c2da_mem[player_17 + 126]) << 0x10 | uint(c2da_mem[player_17 + 127]) << 0x18)].ammo), 40)
    P_SpawnPlayerMissile(int(uint(c2da_mem[player_17]) | uint(c2da_mem[player_17 + 1]) << 0x8 | uint(c2da_mem[player_17 + 2]) << 0x10 | uint(c2da_mem[player_17 + 3]) << 0x18), 35u)
    return
}
[export, sideeffects]
def A_FirePlasma(var player_18 : int; var psp_11 : int) {
    DecreaseAmmo(player_18, int(weaponinfo[int(uint(c2da_mem[player_18 + 124]) | uint(c2da_mem[player_18 + 125]) << 0x8 | uint(c2da_mem[player_18 + 126]) << 0x10 | uint(c2da_mem[player_18 + 127]) << 0x18)].ammo), 1)
    P_SetPsprite(player_18, 1, uint(weaponinfo[int(uint(c2da_mem[player_18 + 124]) | uint(c2da_mem[player_18 + 125]) << 0x8 | uint(c2da_mem[player_18 + 126]) << 0x10 | uint(c2da_mem[player_18 + 127]) << 0x18)].flashstate + (P_Random() & 1)))
    P_SpawnPlayerMissile(int(uint(c2da_mem[player_18]) | uint(c2da_mem[player_18 + 1]) << 0x8 | uint(c2da_mem[player_18 + 2]) << 0x10 | uint(c2da_mem[player_18 + 3]) << 0x18), 34u)
    return
}
[export, sideeffects]
def P_BulletSlope(var mo : int) {
    var an : uint = uint(c2da_mem[mo + 56]) | uint(c2da_mem[mo + 57]) << 0x8 | uint(c2da_mem[mo + 58]) << 0x10 | uint(c2da_mem[mo + 59]) << 0x18
    let c2da_fresh101 : int = P_AimLineAttack(mo, an, 16 * 64 * (1 << 16))
    let c2da_fresh102 : uint = uint(c2da_fresh101)
    c2da_mem[49696] = uint8(c2da_fresh102)
    c2da_mem[49697] = uint8(c2da_fresh102 >> 0x8)
    c2da_mem[49698] = uint8(c2da_fresh102 >> 0x10)
    c2da_mem[49699] = uint8(c2da_fresh102 >> 0x18)
    if (linetarget == 0) {
        an += uint(1 << 26)
        let c2da_fresh103 : int = P_AimLineAttack(mo, an, 16 * 64 * (1 << 16))
        let c2da_fresh104 : uint = uint(c2da_fresh103)
        c2da_mem[49696] = uint8(c2da_fresh104)
        c2da_mem[49697] = uint8(c2da_fresh104 >> 0x8)
        c2da_mem[49698] = uint8(c2da_fresh104 >> 0x10)
        c2da_mem[49699] = uint8(c2da_fresh104 >> 0x18)
        if (linetarget == 0) {
            an -= uint(2 << 26)
            let c2da_fresh105 : int = P_AimLineAttack(mo, an, 16 * 64 * (1 << 16))
            let c2da_fresh106 : uint = uint(c2da_fresh105)
            c2da_mem[49696] = uint8(c2da_fresh106)
            c2da_mem[49697] = uint8(c2da_fresh106 >> 0x8)
            c2da_mem[49698] = uint8(c2da_fresh106 >> 0x10)
            c2da_mem[49699] = uint8(c2da_fresh106 >> 0x18)
        }
    }
    return
}
[export, sideeffects]
def P_GunShot(var mo_0 : int; var accurate : uint) {
    var angle_3 : uint
    var damage_1 : int = 5 * (P_Random() % 3 + 1)
    angle_3 = uint(c2da_mem[mo_0 + 56]) | uint(c2da_mem[mo_0 + 57]) << 0x8 | uint(c2da_mem[mo_0 + 58]) << 0x10 | uint(c2da_mem[mo_0 + 59]) << 0x18
    if (accurate == 0) {
        angle_3 = angle_3 + uint(P_Random() - P_Random() << 18)
    }
    P_LineAttack(mo_0, angle_3, 32 * 64 * (1 << 16), int(uint(c2da_mem[49696]) | uint(c2da_mem[49697]) << 0x8 | uint(c2da_mem[49698]) << 0x10 | uint(c2da_mem[49699]) << 0x18), damage_1)
    return
}
[export, sideeffects]
def A_FirePistol(var player_19 : int; var psp_12 : int) {
    S_StartSound(int(uint(c2da_mem[player_19]) | uint(c2da_mem[player_19 + 1]) << 0x8 | uint(c2da_mem[player_19 + 2]) << 0x10 | uint(c2da_mem[player_19 + 3]) << 0x18), 1)
    P_SetMobjState(int(uint(c2da_mem[player_19]) | uint(c2da_mem[player_19 + 1]) << 0x8 | uint(c2da_mem[player_19 + 2]) << 0x10 | uint(c2da_mem[player_19 + 3]) << 0x18), 155u)
    DecreaseAmmo(player_19, int(weaponinfo[int(uint(c2da_mem[player_19 + 124]) | uint(c2da_mem[player_19 + 125]) << 0x8 | uint(c2da_mem[player_19 + 126]) << 0x10 | uint(c2da_mem[player_19 + 127]) << 0x18)].ammo), 1)
    P_SetPsprite(player_19, 1, uint(weaponinfo[int(uint(c2da_mem[player_19 + 124]) | uint(c2da_mem[player_19 + 125]) << 0x8 | uint(c2da_mem[player_19 + 126]) << 0x10 | uint(c2da_mem[player_19 + 127]) << 0x18)].flashstate))
    P_BulletSlope(int(uint(c2da_mem[player_19]) | uint(c2da_mem[player_19 + 1]) << 0x8 | uint(c2da_mem[player_19 + 2]) << 0x10 | uint(c2da_mem[player_19 + 3]) << 0x18))
    P_GunShot(int(uint(c2da_mem[player_19]) | uint(c2da_mem[player_19 + 1]) << 0x8 | uint(c2da_mem[player_19 + 2]) << 0x10 | uint(c2da_mem[player_19 + 3]) << 0x18), int(uint(c2da_mem[player_19 + 212]) | uint(c2da_mem[player_19 + 213]) << 0x8 | uint(c2da_mem[player_19 + 214]) << 0x10 | uint(c2da_mem[player_19 + 215]) << 0x18) == 0 ? 1u : 0u)
    return
}
[export, sideeffects]
def A_FireShotgun(var player_20 : int; var psp_13 : int) {
    S_StartSound(int(uint(c2da_mem[player_20]) | uint(c2da_mem[player_20 + 1]) << 0x8 | uint(c2da_mem[player_20 + 2]) << 0x10 | uint(c2da_mem[player_20 + 3]) << 0x18), 2)
    P_SetMobjState(int(uint(c2da_mem[player_20]) | uint(c2da_mem[player_20 + 1]) << 0x8 | uint(c2da_mem[player_20 + 2]) << 0x10 | uint(c2da_mem[player_20 + 3]) << 0x18), 155u)
    DecreaseAmmo(player_20, int(weaponinfo[int(uint(c2da_mem[player_20 + 124]) | uint(c2da_mem[player_20 + 125]) << 0x8 | uint(c2da_mem[player_20 + 126]) << 0x10 | uint(c2da_mem[player_20 + 127]) << 0x18)].ammo), 1)
    P_SetPsprite(player_20, 1, uint(weaponinfo[int(uint(c2da_mem[player_20 + 124]) | uint(c2da_mem[player_20 + 125]) << 0x8 | uint(c2da_mem[player_20 + 126]) << 0x10 | uint(c2da_mem[player_20 + 127]) << 0x18)].flashstate))
    P_BulletSlope(int(uint(c2da_mem[player_20]) | uint(c2da_mem[player_20 + 1]) << 0x8 | uint(c2da_mem[player_20 + 2]) << 0x10 | uint(c2da_mem[player_20 + 3]) << 0x18))
    for (i_1 in range(0, 7)) {
        P_GunShot(int(uint(c2da_mem[player_20]) | uint(c2da_mem[player_20 + 1]) << 0x8 | uint(c2da_mem[player_20 + 2]) << 0x10 | uint(c2da_mem[player_20 + 3]) << 0x18), 0u)
    }
    return
}
[export, sideeffects]
def A_FireShotgun2(var player_21 : int; var psp_14 : int) {
    var angle_4 : uint
    var damage_2 : int
    S_StartSound(int(uint(c2da_mem[player_21]) | uint(c2da_mem[player_21 + 1]) << 0x8 | uint(c2da_mem[player_21 + 2]) << 0x10 | uint(c2da_mem[player_21 + 3]) << 0x18), 4)
    P_SetMobjState(int(uint(c2da_mem[player_21]) | uint(c2da_mem[player_21 + 1]) << 0x8 | uint(c2da_mem[player_21 + 2]) << 0x10 | uint(c2da_mem[player_21 + 3]) << 0x18), 155u)
    DecreaseAmmo(player_21, int(weaponinfo[int(uint(c2da_mem[player_21 + 124]) | uint(c2da_mem[player_21 + 125]) << 0x8 | uint(c2da_mem[player_21 + 126]) << 0x10 | uint(c2da_mem[player_21 + 127]) << 0x18)].ammo), 2)
    P_SetPsprite(player_21, 1, uint(weaponinfo[int(uint(c2da_mem[player_21 + 124]) | uint(c2da_mem[player_21 + 125]) << 0x8 | uint(c2da_mem[player_21 + 126]) << 0x10 | uint(c2da_mem[player_21 + 127]) << 0x18)].flashstate))
    P_BulletSlope(int(uint(c2da_mem[player_21]) | uint(c2da_mem[player_21 + 1]) << 0x8 | uint(c2da_mem[player_21 + 2]) << 0x10 | uint(c2da_mem[player_21 + 3]) << 0x18))
    for (i_2 in range(0, 20)) {
        damage_2 = 5 * (P_Random() % 3 + 1)
        let c2da_fresh107 : int = int(uint(c2da_mem[player_21]) | uint(c2da_mem[player_21 + 1]) << 0x8 | uint(c2da_mem[player_21 + 2]) << 0x10 | uint(c2da_mem[player_21 + 3]) << 0x18) + 56
        angle_4 = uint(c2da_mem[c2da_fresh107]) | uint(c2da_mem[c2da_fresh107 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh107 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh107 + 3]) << 0x18
        angle_4 = angle_4 + uint(P_Random() - P_Random() << 19)
        P_LineAttack(int(uint(c2da_mem[player_21]) | uint(c2da_mem[player_21 + 1]) << 0x8 | uint(c2da_mem[player_21 + 2]) << 0x10 | uint(c2da_mem[player_21 + 3]) << 0x18), angle_4, 32 * 64 * (1 << 16), int(uint(c2da_mem[49696]) | uint(c2da_mem[49697]) << 0x8 | uint(c2da_mem[49698]) << 0x10 | uint(c2da_mem[49699]) << 0x18) + (P_Random() - P_Random() << 5), damage_2)
    }
    return
}
[export, sideeffects]
def A_FireCGun(var player_22 : int; var psp_15 : int) {
    S_StartSound(int(uint(c2da_mem[player_22]) | uint(c2da_mem[player_22 + 1]) << 0x8 | uint(c2da_mem[player_22 + 2]) << 0x10 | uint(c2da_mem[player_22 + 3]) << 0x18), 1)
    let c2da_fresh108 : int = player_22 + 168 + int(weaponinfo[int(uint(c2da_mem[player_22 + 124]) | uint(c2da_mem[player_22 + 125]) << 0x8 | uint(c2da_mem[player_22 + 126]) << 0x10 | uint(c2da_mem[player_22 + 127]) << 0x18)].ammo) * 4
    if (int(uint(c2da_mem[c2da_fresh108]) | uint(c2da_mem[c2da_fresh108 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh108 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh108 + 3]) << 0x18) == 0) {
        return
    }
    P_SetMobjState(int(uint(c2da_mem[player_22]) | uint(c2da_mem[player_22 + 1]) << 0x8 | uint(c2da_mem[player_22 + 2]) << 0x10 | uint(c2da_mem[player_22 + 3]) << 0x18), 155u)
    DecreaseAmmo(player_22, int(weaponinfo[int(uint(c2da_mem[player_22 + 124]) | uint(c2da_mem[player_22 + 125]) << 0x8 | uint(c2da_mem[player_22 + 126]) << 0x10 | uint(c2da_mem[player_22 + 127]) << 0x18)].ammo), 1)
    P_SetPsprite(player_22, 1, uint((int(uint(c2da_mem[psp_15]) | uint(c2da_mem[psp_15 + 1]) << 0x8 | uint(c2da_mem[psp_15 + 2]) << 0x10 | uint(c2da_mem[psp_15 + 3]) << 0x18) + int(weaponinfo[int(uint(c2da_mem[player_22 + 124]) | uint(c2da_mem[player_22 + 125]) << 0x8 | uint(c2da_mem[player_22 + 126]) << 0x10 | uint(c2da_mem[player_22 + 127]) << 0x18)].flashstate) * 40 - (2080 + 52 * 40)) / 40))
    P_BulletSlope(int(uint(c2da_mem[player_22]) | uint(c2da_mem[player_22 + 1]) << 0x8 | uint(c2da_mem[player_22 + 2]) << 0x10 | uint(c2da_mem[player_22 + 3]) << 0x18))
    P_GunShot(int(uint(c2da_mem[player_22]) | uint(c2da_mem[player_22 + 1]) << 0x8 | uint(c2da_mem[player_22 + 2]) << 0x10 | uint(c2da_mem[player_22 + 3]) << 0x18), int(uint(c2da_mem[player_22 + 212]) | uint(c2da_mem[player_22 + 213]) << 0x8 | uint(c2da_mem[player_22 + 214]) << 0x10 | uint(c2da_mem[player_22 + 215]) << 0x18) == 0 ? 1u : 0u)
    return
}
[export, sideeffects]
def A_Light0(var player_23 : int; var psp_16 : int) {
    let c2da_fresh109 : int = 0
    let c2da_fresh110 : uint = uint(c2da_fresh109)
    c2da_mem[player_23 + 256] = uint8(c2da_fresh110)
    c2da_mem[player_23 + 257] = uint8(c2da_fresh110 >> 0x8)
    c2da_mem[player_23 + 258] = uint8(c2da_fresh110 >> 0x10)
    c2da_mem[player_23 + 259] = uint8(c2da_fresh110 >> 0x18)
    return
}
[export, sideeffects]
def A_Light1(var player_24 : int; var psp_17 : int) {
    let c2da_fresh111 : int = 1
    let c2da_fresh112 : uint = uint(c2da_fresh111)
    c2da_mem[player_24 + 256] = uint8(c2da_fresh112)
    c2da_mem[player_24 + 257] = uint8(c2da_fresh112 >> 0x8)
    c2da_mem[player_24 + 258] = uint8(c2da_fresh112 >> 0x10)
    c2da_mem[player_24 + 259] = uint8(c2da_fresh112 >> 0x18)
    return
}
[export, sideeffects]
def A_Light2(var player_25 : int; var psp_18 : int) {
    let c2da_fresh113 : int = 2
    let c2da_fresh114 : uint = uint(c2da_fresh113)
    c2da_mem[player_25 + 256] = uint8(c2da_fresh114)
    c2da_mem[player_25 + 257] = uint8(c2da_fresh114 >> 0x8)
    c2da_mem[player_25 + 258] = uint8(c2da_fresh114 >> 0x10)
    c2da_mem[player_25 + 259] = uint8(c2da_fresh114 >> 0x18)
    return
}
[export, sideeffects]
def A_BFGSpray(var mo_1 : int) {
    var damage_3 : int
    var an_0 : uint
    for (i_3 in range(0, 40)) {
        an_0 = (uint(c2da_mem[mo_1 + 56]) | uint(c2da_mem[mo_1 + 57]) << 0x8 | uint(c2da_mem[mo_1 + 58]) << 0x10 | uint(c2da_mem[mo_1 + 59]) << 0x18) - uint(1073741824 / 2) + uint(1073741824 / 40 * i_3)
        P_AimLineAttack(int(uint(c2da_mem[mo_1 + 176]) | uint(c2da_mem[mo_1 + 177]) << 0x8 | uint(c2da_mem[mo_1 + 178]) << 0x10 | uint(c2da_mem[mo_1 + 179]) << 0x18), an_0, 16 * 64 * (1 << 16))
        if (linetarget == 0) {
            continue
        }
        P_SpawnMobj(int(uint(c2da_mem[linetarget + 24]) | uint(c2da_mem[linetarget + 25]) << 0x8 | uint(c2da_mem[linetarget + 26]) << 0x10 | uint(c2da_mem[linetarget + 27]) << 0x18), int(uint(c2da_mem[linetarget + 28]) | uint(c2da_mem[linetarget + 29]) << 0x8 | uint(c2da_mem[linetarget + 30]) << 0x10 | uint(c2da_mem[linetarget + 31]) << 0x18), int(uint(c2da_mem[linetarget + 32]) | uint(c2da_mem[linetarget + 33]) << 0x8 | uint(c2da_mem[linetarget + 34]) << 0x10 | uint(c2da_mem[linetarget + 35]) << 0x18) + (int(uint(c2da_mem[linetarget + 108]) | uint(c2da_mem[linetarget + 109]) << 0x8 | uint(c2da_mem[linetarget + 110]) << 0x10 | uint(c2da_mem[linetarget + 111]) << 0x18) >> 2), 42u)
        damage_3 = 0
        for (j in range(0, 15)) {
            damage_3 = damage_3 + ((P_Random() & 7) + 1)
        }
        P_DamageMobj(linetarget, int(uint(c2da_mem[mo_1 + 176]) | uint(c2da_mem[mo_1 + 177]) << 0x8 | uint(c2da_mem[mo_1 + 178]) << 0x10 | uint(c2da_mem[mo_1 + 179]) << 0x18), int(uint(c2da_mem[mo_1 + 176]) | uint(c2da_mem[mo_1 + 177]) << 0x8 | uint(c2da_mem[mo_1 + 178]) << 0x10 | uint(c2da_mem[mo_1 + 179]) << 0x18), damage_3)
    }
    return
}
[export, sideeffects]
def A_BFGsound(var player_26 : int; var psp_19 : int) {
    S_StartSound(int(uint(c2da_mem[player_26]) | uint(c2da_mem[player_26 + 1]) << 0x8 | uint(c2da_mem[player_26 + 2]) << 0x10 | uint(c2da_mem[player_26 + 3]) << 0x18), 9)
    return
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_p_pspr() {
    if (length(c2da_fn_table1) < 38) {
        resize(c2da_fn_table1, 38)
    }
    c2da_fn_table1[16] = @@A_WeaponReady
    c2da_fn_table1[20] = @@A_ReFire
    c2da_fn_table1[26] = @@A_CheckReload
    c2da_fn_table1[17] = @@A_Lower
    c2da_fn_table1[18] = @@A_Raise
    c2da_fn_table1[31] = @@A_GunFlash
    c2da_fn_table1[19] = @@A_Punch
    c2da_fn_table1[33] = @@A_Saw
    c2da_fn_table1[32] = @@A_FireMissile
    c2da_fn_table1[36] = @@A_FireBFG
    c2da_fn_table1[34] = @@A_FirePlasma
    c2da_fn_table1[21] = @@A_FirePistol
    c2da_fn_table1[23] = @@A_FireShotgun
    c2da_fn_table1[25] = @@A_FireShotgun2
    c2da_fn_table1[30] = @@A_FireCGun
    c2da_fn_table1[15] = @@A_Light0
    c2da_fn_table1[22] = @@A_Light1
    c2da_fn_table1[24] = @@A_Light2
    c2da_fn_table1[35] = @@A_BFGsound
    if (length(c2da_fn_table5) < 38) {
        resize(c2da_fn_table5, 38)
    }
    c2da_fn_table5[37] = @@A_BFGSpray
}

[init]
def private c2da_lin_relink_init_p_pspr() {
    c2da_relink_p_pspr()
}
