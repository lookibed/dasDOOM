[export, sideeffects]
def P_PlayerThink(var player : int) {
    var cmd : int
    var newweapon : uint
    if ((int(uint(c2da_mem[player + 208]) | uint(c2da_mem[player + 209]) << 0x8 | uint(c2da_mem[player + 210]) << 0x10 | uint(c2da_mem[player + 211]) << 0x18) & 1) != 0) {
        let c2da_fresh0 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 160
        let c2da_fresh1 : int = int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18) | 4096
        let c2da_fresh2 : uint = uint(c2da_fresh1)
        c2da_mem[c2da_fresh0] = uint8(c2da_fresh2)
        c2da_mem[c2da_fresh0 + 1] = uint8(c2da_fresh2 >> 0x8)
        c2da_mem[c2da_fresh0 + 2] = uint8(c2da_fresh2 >> 0x10)
        c2da_mem[c2da_fresh0 + 3] = uint8(c2da_fresh2 >> 0x18)
    } else {
        let c2da_fresh3 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 160
        let c2da_fresh4 : int = int(uint(c2da_mem[c2da_fresh3]) | uint(c2da_mem[c2da_fresh3 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh3 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh3 + 3]) << 0x18) & ~4096
        let c2da_fresh5 : uint = uint(c2da_fresh4)
        c2da_mem[c2da_fresh3] = uint8(c2da_fresh5)
        c2da_mem[c2da_fresh3 + 1] = uint8(c2da_fresh5 >> 0x8)
        c2da_mem[c2da_fresh3 + 2] = uint8(c2da_fresh5 >> 0x10)
        c2da_mem[c2da_fresh3 + 3] = uint8(c2da_fresh5 >> 0x18)
    }
    cmd = player + 12
    let c2da_fresh6 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 160
    if ((int(uint(c2da_mem[c2da_fresh6]) | uint(c2da_mem[c2da_fresh6 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh6 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh6 + 3]) << 0x18) & 128) != 0) {
        let c2da_fresh7 : int16 = int16(0)
        let c2da_fresh8 : uint = uint(c2da_fresh7)
        c2da_mem[cmd + 2] = uint8(c2da_fresh8)
        c2da_mem[cmd + 3] = uint8(c2da_fresh8 >> 0x8)
        let c2da_fresh9 : int8 = int8(51200 / 512)
        c2da_mem[cmd] = uint8(c2da_fresh9)
        let c2da_fresh10 : int8 = int8(0)
        c2da_mem[cmd + 1] = uint8(c2da_fresh10)
        let c2da_fresh11 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 160
        let c2da_fresh12 : int = int(uint(c2da_mem[c2da_fresh11]) | uint(c2da_mem[c2da_fresh11 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh11 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh11 + 3]) << 0x18) & ~128
        let c2da_fresh13 : uint = uint(c2da_fresh12)
        c2da_mem[c2da_fresh11] = uint8(c2da_fresh13)
        c2da_mem[c2da_fresh11 + 1] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[c2da_fresh11 + 2] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[c2da_fresh11 + 3] = uint8(c2da_fresh13 >> 0x18)
    }
    if ((uint(c2da_mem[player + 8]) | uint(c2da_mem[player + 9]) << 0x8 | uint(c2da_mem[player + 10]) << 0x10 | uint(c2da_mem[player + 11]) << 0x18) == 1u) {
        P_DeathThink(player)
        return
    }
    let c2da_fresh14 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 184
    if (int(uint(c2da_mem[c2da_fresh14]) | uint(c2da_mem[c2da_fresh14 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh14 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh14 + 3]) << 0x18) != 0) {
        let c2da_fresh15 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 184
        let c2da_fresh16 : int = int(uint(c2da_mem[c2da_fresh15]) | uint(c2da_mem[c2da_fresh15 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh15 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh15 + 3]) << 0x18)
        let c2da_fresh17 : int = c2da_fresh16 - 1
        let c2da_fresh18 : uint = uint(c2da_fresh17)
        c2da_mem[c2da_fresh15] = uint8(c2da_fresh18)
        c2da_mem[c2da_fresh15 + 1] = uint8(c2da_fresh18 >> 0x8)
        c2da_mem[c2da_fresh15 + 2] = uint8(c2da_fresh18 >> 0x10)
        c2da_mem[c2da_fresh15 + 3] = uint8(c2da_fresh18 >> 0x18)
    } else {
        P_MovePlayer(player)
    }
    P_CalcHeight(player)
    let c2da_fresh19 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 88
    let c2da_fresh20 : int = int(uint(c2da_mem[c2da_fresh19]) | uint(c2da_mem[c2da_fresh19 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh19 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh19 + 3]) << 0x18)
    let c2da_fresh21 : int = int(uint(c2da_mem[c2da_fresh20]) | uint(c2da_mem[c2da_fresh20 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh20 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh20 + 3]) << 0x18) + 14
    if (int16(uint(c2da_mem[c2da_fresh21]) | uint(c2da_mem[c2da_fresh21 + 1]) << 0x8) != 0) {
        P_PlayerInSpecialSector(player)
    }
    if ((int(c2da_mem[cmd + 5]) & 128) != 0) {
        let c2da_fresh22 : uint8 = 0u8
        c2da_mem[cmd + 5] = c2da_fresh22
    }
    if ((int(c2da_mem[cmd + 5]) & 4) != 0) {
        newweapon = uint((int(c2da_mem[cmd + 5]) & 56) >> 3)
        if (newweapon == 0u && (uint(c2da_mem[player + 132 + 7 * 4]) | uint(c2da_mem[player + 132 + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 132 + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 132 + 7 * 4 + 3]) << 0x18) != 0x0 && !((uint(c2da_mem[player + 124]) | uint(c2da_mem[player + 125]) << 0x8 | uint(c2da_mem[player + 126]) << 0x10 | uint(c2da_mem[player + 127]) << 0x18) == 7u && int(uint(c2da_mem[player + 56 + 1 * 4]) | uint(c2da_mem[player + 56 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 1 * 4 + 3]) << 0x18) != 0)) {
            newweapon = 7u
        }
        if (uint(gamemode) == 2u && newweapon == 2u && (uint(c2da_mem[player + 132 + 8 * 4]) | uint(c2da_mem[player + 132 + 8 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 132 + 8 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 132 + 8 * 4 + 3]) << 0x18) != 0x0 && (uint(c2da_mem[player + 124]) | uint(c2da_mem[player + 125]) << 0x8 | uint(c2da_mem[player + 126]) << 0x10 | uint(c2da_mem[player + 127]) << 0x18) != 8u) {
            newweapon = 8u
        }
        if ((uint(c2da_mem[player + 132 + int(newweapon) * 4]) | uint(c2da_mem[player + 132 + int(newweapon) * 4 + 1]) << 0x8 | uint(c2da_mem[player + 132 + int(newweapon) * 4 + 2]) << 0x10 | uint(c2da_mem[player + 132 + int(newweapon) * 4 + 3]) << 0x18) != 0x0 && newweapon != (uint(c2da_mem[player + 124]) | uint(c2da_mem[player + 125]) << 0x8 | uint(c2da_mem[player + 126]) << 0x10 | uint(c2da_mem[player + 127]) << 0x18)) {
            if (newweapon != 5u && newweapon != 6u || uint(gamemode) != 0u) {
                let c2da_fresh23 : uint = newweapon
                c2da_mem[player + 128] = uint8(c2da_fresh23)
                c2da_mem[player + 129] = uint8(c2da_fresh23 >> 0x8)
                c2da_mem[player + 130] = uint8(c2da_fresh23 >> 0x10)
                c2da_mem[player + 131] = uint8(c2da_fresh23 >> 0x18)
            }
        }
    }
    if ((int(c2da_mem[cmd + 5]) & 2) != 0) {
        if (int(uint(c2da_mem[player + 204]) | uint(c2da_mem[player + 205]) << 0x8 | uint(c2da_mem[player + 206]) << 0x10 | uint(c2da_mem[player + 207]) << 0x18) == 0) {
            P_UseLines(player)
            let c2da_fresh24 : int = 1
            let c2da_fresh25 : uint = uint(c2da_fresh24)
            c2da_mem[player + 204] = uint8(c2da_fresh25)
            c2da_mem[player + 205] = uint8(c2da_fresh25 >> 0x8)
            c2da_mem[player + 206] = uint8(c2da_fresh25 >> 0x10)
            c2da_mem[player + 207] = uint8(c2da_fresh25 >> 0x18)
        }
    } else {
        let c2da_fresh26 : int = 0
        let c2da_fresh27 : uint = uint(c2da_fresh26)
        c2da_mem[player + 204] = uint8(c2da_fresh27)
        c2da_mem[player + 205] = uint8(c2da_fresh27 >> 0x8)
        c2da_mem[player + 206] = uint8(c2da_fresh27 >> 0x10)
        c2da_mem[player + 207] = uint8(c2da_fresh27 >> 0x18)
    }
    P_MovePsprites(player)
    if (int(uint(c2da_mem[player + 56 + 1 * 4]) | uint(c2da_mem[player + 56 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 1 * 4 + 3]) << 0x18) != 0) {
        let c2da_fresh28 : int = int(uint(c2da_mem[player + 56 + 1 * 4]) | uint(c2da_mem[player + 56 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 1 * 4 + 3]) << 0x18)
        let c2da_fresh29 : int = c2da_fresh28 + 1
        let c2da_fresh30 : uint = uint(c2da_fresh29)
        c2da_mem[player + 56 + 1 * 4] = uint8(c2da_fresh30)
        c2da_mem[player + 56 + 1 * 4 + 1] = uint8(c2da_fresh30 >> 0x8)
        c2da_mem[player + 56 + 1 * 4 + 2] = uint8(c2da_fresh30 >> 0x10)
        c2da_mem[player + 56 + 1 * 4 + 3] = uint8(c2da_fresh30 >> 0x18)
    }
    if (int(uint(c2da_mem[player + 56 + 0 * 4]) | uint(c2da_mem[player + 56 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 0 * 4 + 3]) << 0x18) != 0) {
        let c2da_fresh31 : int = int(uint(c2da_mem[player + 56 + 0 * 4]) | uint(c2da_mem[player + 56 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 0 * 4 + 3]) << 0x18)
        let c2da_fresh32 : int = c2da_fresh31 - 1
        let c2da_fresh33 : uint = uint(c2da_fresh32)
        c2da_mem[player + 56 + 0 * 4] = uint8(c2da_fresh33)
        c2da_mem[player + 56 + 0 * 4 + 1] = uint8(c2da_fresh33 >> 0x8)
        c2da_mem[player + 56 + 0 * 4 + 2] = uint8(c2da_fresh33 >> 0x10)
        c2da_mem[player + 56 + 0 * 4 + 3] = uint8(c2da_fresh33 >> 0x18)
    }
    if (int(uint(c2da_mem[player + 56 + 2 * 4]) | uint(c2da_mem[player + 56 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 2 * 4 + 3]) << 0x18) != 0) {
        let c2da_fresh34 : int = int(uint(c2da_mem[player + 56 + 2 * 4]) | uint(c2da_mem[player + 56 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 2 * 4 + 3]) << 0x18)
        let c2da_fresh35 : int = c2da_fresh34 - 1
        let c2da_fresh36 : uint = uint(c2da_fresh35)
        c2da_mem[player + 56 + 2 * 4] = uint8(c2da_fresh36)
        c2da_mem[player + 56 + 2 * 4 + 1] = uint8(c2da_fresh36 >> 0x8)
        c2da_mem[player + 56 + 2 * 4 + 2] = uint8(c2da_fresh36 >> 0x10)
        c2da_mem[player + 56 + 2 * 4 + 3] = uint8(c2da_fresh36 >> 0x18)
        if (c2da_fresh35 == 0) {
            let c2da_fresh37 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 160
            let c2da_fresh38 : int = int(uint(c2da_mem[c2da_fresh37]) | uint(c2da_mem[c2da_fresh37 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh37 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh37 + 3]) << 0x18) & ~262144
            let c2da_fresh39 : uint = uint(c2da_fresh38)
            c2da_mem[c2da_fresh37] = uint8(c2da_fresh39)
            c2da_mem[c2da_fresh37 + 1] = uint8(c2da_fresh39 >> 0x8)
            c2da_mem[c2da_fresh37 + 2] = uint8(c2da_fresh39 >> 0x10)
            c2da_mem[c2da_fresh37 + 3] = uint8(c2da_fresh39 >> 0x18)
        }
    }
    if (int(uint(c2da_mem[player + 56 + 5 * 4]) | uint(c2da_mem[player + 56 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 5 * 4 + 3]) << 0x18) != 0) {
        let c2da_fresh40 : int = int(uint(c2da_mem[player + 56 + 5 * 4]) | uint(c2da_mem[player + 56 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 5 * 4 + 3]) << 0x18)
        let c2da_fresh41 : int = c2da_fresh40 - 1
        let c2da_fresh42 : uint = uint(c2da_fresh41)
        c2da_mem[player + 56 + 5 * 4] = uint8(c2da_fresh42)
        c2da_mem[player + 56 + 5 * 4 + 1] = uint8(c2da_fresh42 >> 0x8)
        c2da_mem[player + 56 + 5 * 4 + 2] = uint8(c2da_fresh42 >> 0x10)
        c2da_mem[player + 56 + 5 * 4 + 3] = uint8(c2da_fresh42 >> 0x18)
    }
    if (int(uint(c2da_mem[player + 56 + 3 * 4]) | uint(c2da_mem[player + 56 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 3 * 4 + 3]) << 0x18) != 0) {
        let c2da_fresh43 : int = int(uint(c2da_mem[player + 56 + 3 * 4]) | uint(c2da_mem[player + 56 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 3 * 4 + 3]) << 0x18)
        let c2da_fresh44 : int = c2da_fresh43 - 1
        let c2da_fresh45 : uint = uint(c2da_fresh44)
        c2da_mem[player + 56 + 3 * 4] = uint8(c2da_fresh45)
        c2da_mem[player + 56 + 3 * 4 + 1] = uint8(c2da_fresh45 >> 0x8)
        c2da_mem[player + 56 + 3 * 4 + 2] = uint8(c2da_fresh45 >> 0x10)
        c2da_mem[player + 56 + 3 * 4 + 3] = uint8(c2da_fresh45 >> 0x18)
    }
    if (int(uint(c2da_mem[player + 240]) | uint(c2da_mem[player + 241]) << 0x8 | uint(c2da_mem[player + 242]) << 0x10 | uint(c2da_mem[player + 243]) << 0x18) != 0) {
        let c2da_fresh46 : int = int(uint(c2da_mem[player + 240]) | uint(c2da_mem[player + 241]) << 0x8 | uint(c2da_mem[player + 242]) << 0x10 | uint(c2da_mem[player + 243]) << 0x18)
        let c2da_fresh47 : int = c2da_fresh46 - 1
        let c2da_fresh48 : uint = uint(c2da_fresh47)
        c2da_mem[player + 240] = uint8(c2da_fresh48)
        c2da_mem[player + 241] = uint8(c2da_fresh48 >> 0x8)
        c2da_mem[player + 242] = uint8(c2da_fresh48 >> 0x10)
        c2da_mem[player + 243] = uint8(c2da_fresh48 >> 0x18)
    }
    if (int(uint(c2da_mem[player + 244]) | uint(c2da_mem[player + 245]) << 0x8 | uint(c2da_mem[player + 246]) << 0x10 | uint(c2da_mem[player + 247]) << 0x18) != 0) {
        let c2da_fresh49 : int = int(uint(c2da_mem[player + 244]) | uint(c2da_mem[player + 245]) << 0x8 | uint(c2da_mem[player + 246]) << 0x10 | uint(c2da_mem[player + 247]) << 0x18)
        let c2da_fresh50 : int = c2da_fresh49 - 1
        let c2da_fresh51 : uint = uint(c2da_fresh50)
        c2da_mem[player + 244] = uint8(c2da_fresh51)
        c2da_mem[player + 245] = uint8(c2da_fresh51 >> 0x8)
        c2da_mem[player + 246] = uint8(c2da_fresh51 >> 0x10)
        c2da_mem[player + 247] = uint8(c2da_fresh51 >> 0x18)
    }
    if (int(uint(c2da_mem[player + 56 + 0 * 4]) | uint(c2da_mem[player + 56 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 0 * 4 + 3]) << 0x18) != 0) {
        if (int(uint(c2da_mem[player + 56 + 0 * 4]) | uint(c2da_mem[player + 56 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 0 * 4 + 3]) << 0x18) > 4 * 32 || (int(uint(c2da_mem[player + 56 + 0 * 4]) | uint(c2da_mem[player + 56 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 0 * 4 + 3]) << 0x18) & 8) != 0) {
            let c2da_fresh52 : int = 32
            let c2da_fresh53 : uint = uint(c2da_fresh52)
            c2da_mem[player + 260] = uint8(c2da_fresh53)
            c2da_mem[player + 261] = uint8(c2da_fresh53 >> 0x8)
            c2da_mem[player + 262] = uint8(c2da_fresh53 >> 0x10)
            c2da_mem[player + 263] = uint8(c2da_fresh53 >> 0x18)
        } else {
            let c2da_fresh54 : int = 0
            let c2da_fresh55 : uint = uint(c2da_fresh54)
            c2da_mem[player + 260] = uint8(c2da_fresh55)
            c2da_mem[player + 261] = uint8(c2da_fresh55 >> 0x8)
            c2da_mem[player + 262] = uint8(c2da_fresh55 >> 0x10)
            c2da_mem[player + 263] = uint8(c2da_fresh55 >> 0x18)
        }
    } elif (int(uint(c2da_mem[player + 56 + 5 * 4]) | uint(c2da_mem[player + 56 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 5 * 4 + 3]) << 0x18) != 0) {
        if (int(uint(c2da_mem[player + 56 + 5 * 4]) | uint(c2da_mem[player + 56 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 5 * 4 + 3]) << 0x18) > 4 * 32 || (int(uint(c2da_mem[player + 56 + 5 * 4]) | uint(c2da_mem[player + 56 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 56 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 56 + 5 * 4 + 3]) << 0x18) & 8) != 0) {
            let c2da_fresh56 : int = 1
            let c2da_fresh57 : uint = uint(c2da_fresh56)
            c2da_mem[player + 260] = uint8(c2da_fresh57)
            c2da_mem[player + 261] = uint8(c2da_fresh57 >> 0x8)
            c2da_mem[player + 262] = uint8(c2da_fresh57 >> 0x10)
            c2da_mem[player + 263] = uint8(c2da_fresh57 >> 0x18)
        } else {
            let c2da_fresh58 : int = 0
            let c2da_fresh59 : uint = uint(c2da_fresh58)
            c2da_mem[player + 260] = uint8(c2da_fresh59)
            c2da_mem[player + 261] = uint8(c2da_fresh59 >> 0x8)
            c2da_mem[player + 262] = uint8(c2da_fresh59 >> 0x10)
            c2da_mem[player + 263] = uint8(c2da_fresh59 >> 0x18)
        }
    } else {
        let c2da_fresh60 : int = 0
        let c2da_fresh61 : uint = uint(c2da_fresh60)
        c2da_mem[player + 260] = uint8(c2da_fresh61)
        c2da_mem[player + 261] = uint8(c2da_fresh61 >> 0x8)
        c2da_mem[player + 262] = uint8(c2da_fresh61 >> 0x10)
        c2da_mem[player + 263] = uint8(c2da_fresh61 >> 0x18)
    }
    return
}
[export, sideeffects]
def P_CalcHeight(var player_0 : int) {
    var angle : int
    var bob : int
    let c2da_fresh62 : int = int(uint(c2da_mem[player_0]) | uint(c2da_mem[player_0 + 1]) << 0x8 | uint(c2da_mem[player_0 + 2]) << 0x10 | uint(c2da_mem[player_0 + 3]) << 0x18) + 112
    let c2da_fresh63 : int = int(uint(c2da_mem[player_0]) | uint(c2da_mem[player_0 + 1]) << 0x8 | uint(c2da_mem[player_0 + 2]) << 0x10 | uint(c2da_mem[player_0 + 3]) << 0x18) + 112
    let c2da_fresh64 : int = int(uint(c2da_mem[player_0]) | uint(c2da_mem[player_0 + 1]) << 0x8 | uint(c2da_mem[player_0 + 2]) << 0x10 | uint(c2da_mem[player_0 + 3]) << 0x18) + 116
    let c2da_fresh65 : int = int(uint(c2da_mem[player_0]) | uint(c2da_mem[player_0 + 1]) << 0x8 | uint(c2da_mem[player_0 + 2]) << 0x10 | uint(c2da_mem[player_0 + 3]) << 0x18) + 116
    let c2da_fresh66 : int = FixedMul(int(uint(c2da_mem[c2da_fresh62]) | uint(c2da_mem[c2da_fresh62 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh62 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh62 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh63]) | uint(c2da_mem[c2da_fresh63 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh63 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh63 + 3]) << 0x18)) + FixedMul(int(uint(c2da_mem[c2da_fresh64]) | uint(c2da_mem[c2da_fresh64 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh64 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh64 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh65]) | uint(c2da_mem[c2da_fresh65 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh65 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh65 + 3]) << 0x18))
    let c2da_fresh67 : uint = uint(c2da_fresh66)
    c2da_mem[player_0 + 40] = uint8(c2da_fresh67)
    c2da_mem[player_0 + 41] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[player_0 + 42] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[player_0 + 43] = uint8(c2da_fresh67 >> 0x18)
    let c2da_fresh68 : int = int(uint(c2da_mem[player_0 + 40]) | uint(c2da_mem[player_0 + 41]) << 0x8 | uint(c2da_mem[player_0 + 42]) << 0x10 | uint(c2da_mem[player_0 + 43]) << 0x18) >> 2
    let c2da_fresh69 : uint = uint(c2da_fresh68)
    c2da_mem[player_0 + 40] = uint8(c2da_fresh69)
    c2da_mem[player_0 + 41] = uint8(c2da_fresh69 >> 0x8)
    c2da_mem[player_0 + 42] = uint8(c2da_fresh69 >> 0x10)
    c2da_mem[player_0 + 43] = uint8(c2da_fresh69 >> 0x18)
    if (int(uint(c2da_mem[player_0 + 40]) | uint(c2da_mem[player_0 + 41]) << 0x8 | uint(c2da_mem[player_0 + 42]) << 0x10 | uint(c2da_mem[player_0 + 43]) << 0x18) > 1048576) {
        let c2da_fresh70 : int = 1048576
        let c2da_fresh71 : uint = uint(c2da_fresh70)
        c2da_mem[player_0 + 40] = uint8(c2da_fresh71)
        c2da_mem[player_0 + 41] = uint8(c2da_fresh71 >> 0x8)
        c2da_mem[player_0 + 42] = uint8(c2da_fresh71 >> 0x10)
        c2da_mem[player_0 + 43] = uint8(c2da_fresh71 >> 0x18)
    }
    if ((int(uint(c2da_mem[player_0 + 208]) | uint(c2da_mem[player_0 + 209]) << 0x8 | uint(c2da_mem[player_0 + 210]) << 0x10 | uint(c2da_mem[player_0 + 211]) << 0x18) & 4) != 0 || onground == 0) {
        let c2da_fresh72 : int = int(uint(c2da_mem[player_0]) | uint(c2da_mem[player_0 + 1]) << 0x8 | uint(c2da_mem[player_0 + 2]) << 0x10 | uint(c2da_mem[player_0 + 3]) << 0x18) + 32
        let c2da_fresh73 : int = int(uint(c2da_mem[c2da_fresh72]) | uint(c2da_mem[c2da_fresh72 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh72 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh72 + 3]) << 0x18) + 41 * (1 << 16)
        let c2da_fresh74 : uint = uint(c2da_fresh73)
        c2da_mem[player_0 + 28] = uint8(c2da_fresh74)
        c2da_mem[player_0 + 29] = uint8(c2da_fresh74 >> 0x8)
        c2da_mem[player_0 + 30] = uint8(c2da_fresh74 >> 0x10)
        c2da_mem[player_0 + 31] = uint8(c2da_fresh74 >> 0x18)
        let c2da_fresh75 : int = int(uint(c2da_mem[player_0]) | uint(c2da_mem[player_0 + 1]) << 0x8 | uint(c2da_mem[player_0 + 2]) << 0x10 | uint(c2da_mem[player_0 + 3]) << 0x18) + 100
        if (int(uint(c2da_mem[player_0 + 28]) | uint(c2da_mem[player_0 + 29]) << 0x8 | uint(c2da_mem[player_0 + 30]) << 0x10 | uint(c2da_mem[player_0 + 31]) << 0x18) > int(uint(c2da_mem[c2da_fresh75]) | uint(c2da_mem[c2da_fresh75 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh75 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh75 + 3]) << 0x18) - 4 * (1 << 16)) {
            let c2da_fresh76 : int = int(uint(c2da_mem[player_0]) | uint(c2da_mem[player_0 + 1]) << 0x8 | uint(c2da_mem[player_0 + 2]) << 0x10 | uint(c2da_mem[player_0 + 3]) << 0x18) + 100
            let c2da_fresh77 : int = int(uint(c2da_mem[c2da_fresh76]) | uint(c2da_mem[c2da_fresh76 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh76 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh76 + 3]) << 0x18) - 4 * (1 << 16)
            let c2da_fresh78 : uint = uint(c2da_fresh77)
            c2da_mem[player_0 + 28] = uint8(c2da_fresh78)
            c2da_mem[player_0 + 29] = uint8(c2da_fresh78 >> 0x8)
            c2da_mem[player_0 + 30] = uint8(c2da_fresh78 >> 0x10)
            c2da_mem[player_0 + 31] = uint8(c2da_fresh78 >> 0x18)
        }
        let c2da_fresh79 : int = int(uint(c2da_mem[player_0]) | uint(c2da_mem[player_0 + 1]) << 0x8 | uint(c2da_mem[player_0 + 2]) << 0x10 | uint(c2da_mem[player_0 + 3]) << 0x18) + 32
        let c2da_fresh80 : int = int(uint(c2da_mem[c2da_fresh79]) | uint(c2da_mem[c2da_fresh79 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh79 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh79 + 3]) << 0x18) + int(uint(c2da_mem[player_0 + 32]) | uint(c2da_mem[player_0 + 33]) << 0x8 | uint(c2da_mem[player_0 + 34]) << 0x10 | uint(c2da_mem[player_0 + 35]) << 0x18)
        let c2da_fresh81 : uint = uint(c2da_fresh80)
        c2da_mem[player_0 + 28] = uint8(c2da_fresh81)
        c2da_mem[player_0 + 29] = uint8(c2da_fresh81 >> 0x8)
        c2da_mem[player_0 + 30] = uint8(c2da_fresh81 >> 0x10)
        c2da_mem[player_0 + 31] = uint8(c2da_fresh81 >> 0x18)
        return
    }
    angle = 8192 / 20 * leveltime & 8192 - 1
    bob = FixedMul(int(uint(c2da_mem[player_0 + 40]) | uint(c2da_mem[player_0 + 41]) << 0x8 | uint(c2da_mem[player_0 + 42]) << 0x10 | uint(c2da_mem[player_0 + 43]) << 0x18) / 2, int(uint(c2da_mem[257920 + angle * 4]) | uint(c2da_mem[257920 + angle * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + angle * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + angle * 4 + 3]) << 0x18))
    if ((uint(c2da_mem[player_0 + 8]) | uint(c2da_mem[player_0 + 9]) << 0x8 | uint(c2da_mem[player_0 + 10]) << 0x10 | uint(c2da_mem[player_0 + 11]) << 0x18) == 0u) {
        let c2da_fresh82 : int = int(uint(c2da_mem[player_0 + 32]) | uint(c2da_mem[player_0 + 33]) << 0x8 | uint(c2da_mem[player_0 + 34]) << 0x10 | uint(c2da_mem[player_0 + 35]) << 0x18) + int(uint(c2da_mem[player_0 + 36]) | uint(c2da_mem[player_0 + 37]) << 0x8 | uint(c2da_mem[player_0 + 38]) << 0x10 | uint(c2da_mem[player_0 + 39]) << 0x18)
        let c2da_fresh83 : uint = uint(c2da_fresh82)
        c2da_mem[player_0 + 32] = uint8(c2da_fresh83)
        c2da_mem[player_0 + 33] = uint8(c2da_fresh83 >> 0x8)
        c2da_mem[player_0 + 34] = uint8(c2da_fresh83 >> 0x10)
        c2da_mem[player_0 + 35] = uint8(c2da_fresh83 >> 0x18)
        if (int(uint(c2da_mem[player_0 + 32]) | uint(c2da_mem[player_0 + 33]) << 0x8 | uint(c2da_mem[player_0 + 34]) << 0x10 | uint(c2da_mem[player_0 + 35]) << 0x18) > 41 * (1 << 16)) {
            let c2da_fresh84 : int = 41 * (1 << 16)
            let c2da_fresh85 : uint = uint(c2da_fresh84)
            c2da_mem[player_0 + 32] = uint8(c2da_fresh85)
            c2da_mem[player_0 + 33] = uint8(c2da_fresh85 >> 0x8)
            c2da_mem[player_0 + 34] = uint8(c2da_fresh85 >> 0x10)
            c2da_mem[player_0 + 35] = uint8(c2da_fresh85 >> 0x18)
            let c2da_fresh86 : int = 0
            let c2da_fresh87 : uint = uint(c2da_fresh86)
            c2da_mem[player_0 + 36] = uint8(c2da_fresh87)
            c2da_mem[player_0 + 37] = uint8(c2da_fresh87 >> 0x8)
            c2da_mem[player_0 + 38] = uint8(c2da_fresh87 >> 0x10)
            c2da_mem[player_0 + 39] = uint8(c2da_fresh87 >> 0x18)
        }
        if (int(uint(c2da_mem[player_0 + 32]) | uint(c2da_mem[player_0 + 33]) << 0x8 | uint(c2da_mem[player_0 + 34]) << 0x10 | uint(c2da_mem[player_0 + 35]) << 0x18) < 41 * (1 << 16) / 2) {
            let c2da_fresh88 : int = 41 * (1 << 16) / 2
            let c2da_fresh89 : uint = uint(c2da_fresh88)
            c2da_mem[player_0 + 32] = uint8(c2da_fresh89)
            c2da_mem[player_0 + 33] = uint8(c2da_fresh89 >> 0x8)
            c2da_mem[player_0 + 34] = uint8(c2da_fresh89 >> 0x10)
            c2da_mem[player_0 + 35] = uint8(c2da_fresh89 >> 0x18)
            if (int(uint(c2da_mem[player_0 + 36]) | uint(c2da_mem[player_0 + 37]) << 0x8 | uint(c2da_mem[player_0 + 38]) << 0x10 | uint(c2da_mem[player_0 + 39]) << 0x18) <= 0) {
                let c2da_fresh90 : int = 1
                let c2da_fresh91 : uint = uint(c2da_fresh90)
                c2da_mem[player_0 + 36] = uint8(c2da_fresh91)
                c2da_mem[player_0 + 37] = uint8(c2da_fresh91 >> 0x8)
                c2da_mem[player_0 + 38] = uint8(c2da_fresh91 >> 0x10)
                c2da_mem[player_0 + 39] = uint8(c2da_fresh91 >> 0x18)
            }
        }
        if (int(uint(c2da_mem[player_0 + 36]) | uint(c2da_mem[player_0 + 37]) << 0x8 | uint(c2da_mem[player_0 + 38]) << 0x10 | uint(c2da_mem[player_0 + 39]) << 0x18) != 0) {
            let c2da_fresh92 : int = int(uint(c2da_mem[player_0 + 36]) | uint(c2da_mem[player_0 + 37]) << 0x8 | uint(c2da_mem[player_0 + 38]) << 0x10 | uint(c2da_mem[player_0 + 39]) << 0x18) + (1 << 16) / 4
            let c2da_fresh93 : uint = uint(c2da_fresh92)
            c2da_mem[player_0 + 36] = uint8(c2da_fresh93)
            c2da_mem[player_0 + 37] = uint8(c2da_fresh93 >> 0x8)
            c2da_mem[player_0 + 38] = uint8(c2da_fresh93 >> 0x10)
            c2da_mem[player_0 + 39] = uint8(c2da_fresh93 >> 0x18)
            if (int(uint(c2da_mem[player_0 + 36]) | uint(c2da_mem[player_0 + 37]) << 0x8 | uint(c2da_mem[player_0 + 38]) << 0x10 | uint(c2da_mem[player_0 + 39]) << 0x18) == 0) {
                let c2da_fresh94 : int = 1
                let c2da_fresh95 : uint = uint(c2da_fresh94)
                c2da_mem[player_0 + 36] = uint8(c2da_fresh95)
                c2da_mem[player_0 + 37] = uint8(c2da_fresh95 >> 0x8)
                c2da_mem[player_0 + 38] = uint8(c2da_fresh95 >> 0x10)
                c2da_mem[player_0 + 39] = uint8(c2da_fresh95 >> 0x18)
            }
        }
    }
    let c2da_fresh96 : int = int(uint(c2da_mem[player_0]) | uint(c2da_mem[player_0 + 1]) << 0x8 | uint(c2da_mem[player_0 + 2]) << 0x10 | uint(c2da_mem[player_0 + 3]) << 0x18) + 32
    let c2da_fresh97 : int = int(uint(c2da_mem[c2da_fresh96]) | uint(c2da_mem[c2da_fresh96 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh96 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh96 + 3]) << 0x18) + int(uint(c2da_mem[player_0 + 32]) | uint(c2da_mem[player_0 + 33]) << 0x8 | uint(c2da_mem[player_0 + 34]) << 0x10 | uint(c2da_mem[player_0 + 35]) << 0x18) + bob
    let c2da_fresh98 : uint = uint(c2da_fresh97)
    c2da_mem[player_0 + 28] = uint8(c2da_fresh98)
    c2da_mem[player_0 + 29] = uint8(c2da_fresh98 >> 0x8)
    c2da_mem[player_0 + 30] = uint8(c2da_fresh98 >> 0x10)
    c2da_mem[player_0 + 31] = uint8(c2da_fresh98 >> 0x18)
    let c2da_fresh99 : int = int(uint(c2da_mem[player_0]) | uint(c2da_mem[player_0 + 1]) << 0x8 | uint(c2da_mem[player_0 + 2]) << 0x10 | uint(c2da_mem[player_0 + 3]) << 0x18) + 100
    if (int(uint(c2da_mem[player_0 + 28]) | uint(c2da_mem[player_0 + 29]) << 0x8 | uint(c2da_mem[player_0 + 30]) << 0x10 | uint(c2da_mem[player_0 + 31]) << 0x18) > int(uint(c2da_mem[c2da_fresh99]) | uint(c2da_mem[c2da_fresh99 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh99 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh99 + 3]) << 0x18) - 4 * (1 << 16)) {
        let c2da_fresh100 : int = int(uint(c2da_mem[player_0]) | uint(c2da_mem[player_0 + 1]) << 0x8 | uint(c2da_mem[player_0 + 2]) << 0x10 | uint(c2da_mem[player_0 + 3]) << 0x18) + 100
        let c2da_fresh101 : int = int(uint(c2da_mem[c2da_fresh100]) | uint(c2da_mem[c2da_fresh100 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh100 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh100 + 3]) << 0x18) - 4 * (1 << 16)
        let c2da_fresh102 : uint = uint(c2da_fresh101)
        c2da_mem[player_0 + 28] = uint8(c2da_fresh102)
        c2da_mem[player_0 + 29] = uint8(c2da_fresh102 >> 0x8)
        c2da_mem[player_0 + 30] = uint8(c2da_fresh102 >> 0x10)
        c2da_mem[player_0 + 31] = uint8(c2da_fresh102 >> 0x18)
    }
    return
}
var onground : uint = default<uint>

[export, sideeffects]
def P_MovePlayer(var player_1 : int) {
    var cmd_0 : int = player_1 + 12
    let c2da_fresh103 : int = int(uint(c2da_mem[player_1]) | uint(c2da_mem[player_1 + 1]) << 0x8 | uint(c2da_mem[player_1 + 2]) << 0x10 | uint(c2da_mem[player_1 + 3]) << 0x18) + 56
    let c2da_fresh104 : uint = (uint(c2da_mem[c2da_fresh103]) | uint(c2da_mem[c2da_fresh103 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh103 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh103 + 3]) << 0x18) + uint(int(int16(uint(c2da_mem[cmd_0 + 2]) | uint(c2da_mem[cmd_0 + 3]) << 0x8)) << 16)
    let c2da_fresh105 : uint = c2da_fresh104
    c2da_mem[c2da_fresh103] = uint8(c2da_fresh105)
    c2da_mem[c2da_fresh103 + 1] = uint8(c2da_fresh105 >> 0x8)
    c2da_mem[c2da_fresh103 + 2] = uint8(c2da_fresh105 >> 0x10)
    c2da_mem[c2da_fresh103 + 3] = uint8(c2da_fresh105 >> 0x18)
    let c2da_fresh106 : int = int(uint(c2da_mem[player_1]) | uint(c2da_mem[player_1 + 1]) << 0x8 | uint(c2da_mem[player_1 + 2]) << 0x10 | uint(c2da_mem[player_1 + 3]) << 0x18) + 32
    let c2da_fresh107 : int = int(uint(c2da_mem[player_1]) | uint(c2da_mem[player_1 + 1]) << 0x8 | uint(c2da_mem[player_1 + 2]) << 0x10 | uint(c2da_mem[player_1 + 3]) << 0x18) + 96
    onground = uint(int(uint(c2da_mem[c2da_fresh106]) | uint(c2da_mem[c2da_fresh106 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh106 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh106 + 3]) << 0x18) <= int(uint(c2da_mem[c2da_fresh107]) | uint(c2da_mem[c2da_fresh107 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh107 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh107 + 3]) << 0x18) ? 1 : 0)
    if (int(int8(c2da_mem[cmd_0])) != 0 && onground != 0x0) {
        let c2da_fresh108 : int = int(uint(c2da_mem[player_1]) | uint(c2da_mem[player_1 + 1]) << 0x8 | uint(c2da_mem[player_1 + 2]) << 0x10 | uint(c2da_mem[player_1 + 3]) << 0x18) + 56
        P_Thrust(player_1, uint(c2da_mem[c2da_fresh108]) | uint(c2da_mem[c2da_fresh108 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh108 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh108 + 3]) << 0x18, int(int8(c2da_mem[cmd_0])) * 2048)
    }
    if (int(int8(c2da_mem[cmd_0 + 1])) != 0 && onground != 0x0) {
        let c2da_fresh109 : int = int(uint(c2da_mem[player_1]) | uint(c2da_mem[player_1 + 1]) << 0x8 | uint(c2da_mem[player_1 + 2]) << 0x10 | uint(c2da_mem[player_1 + 3]) << 0x18) + 56
        P_Thrust(player_1, (uint(c2da_mem[c2da_fresh109]) | uint(c2da_mem[c2da_fresh109 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh109 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh109 + 3]) << 0x18) - 0x40000000u, int(int8(c2da_mem[cmd_0 + 1])) * 2048)
    }
    var c2da_fresh111 : int = 0
    if (int(int8(c2da_mem[cmd_0])) != 0 || int(int8(c2da_mem[cmd_0 + 1])) != 0) {
        let c2da_fresh110 : int = int(uint(c2da_mem[player_1]) | uint(c2da_mem[player_1 + 1]) << 0x8 | uint(c2da_mem[player_1 + 2]) << 0x10 | uint(c2da_mem[player_1 + 3]) << 0x18) + 152
        if (int(uint(c2da_mem[c2da_fresh110]) | uint(c2da_mem[c2da_fresh110 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh110 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh110 + 3]) << 0x18) == 2080 + 149 * 40) {
            c2da_fresh111 = 1
        }
    }
    if (c2da_fresh111 != 0) {
        P_SetMobjState(int(uint(c2da_mem[player_1]) | uint(c2da_mem[player_1 + 1]) << 0x8 | uint(c2da_mem[player_1 + 2]) << 0x10 | uint(c2da_mem[player_1 + 3]) << 0x18), 150u)
    }
    return
}
[export, sideeffects]
def P_Thrust(var player_2 : int; var angle_0 : uint; var move : int) {
    angle_0 >>= 19u
    let c2da_fresh112 : int = int(uint(c2da_mem[player_2]) | uint(c2da_mem[player_2 + 1]) << 0x8 | uint(c2da_mem[player_2 + 2]) << 0x10 | uint(c2da_mem[player_2 + 3]) << 0x18) + 112
    let c2da_fresh113 : int = int(uint(c2da_mem[c2da_fresh112]) | uint(c2da_mem[c2da_fresh112 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh112 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh112 + 3]) << 0x18) + int(FixedMul(move, int(uint(c2da_mem[finecosine + int(angle_0) * 4]) | uint(c2da_mem[finecosine + int(angle_0) * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + int(angle_0) * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + int(angle_0) * 4 + 3]) << 0x18)))
    let c2da_fresh114 : uint = uint(c2da_fresh113)
    c2da_mem[c2da_fresh112] = uint8(c2da_fresh114)
    c2da_mem[c2da_fresh112 + 1] = uint8(c2da_fresh114 >> 0x8)
    c2da_mem[c2da_fresh112 + 2] = uint8(c2da_fresh114 >> 0x10)
    c2da_mem[c2da_fresh112 + 3] = uint8(c2da_fresh114 >> 0x18)
    let c2da_fresh115 : int = int(uint(c2da_mem[player_2]) | uint(c2da_mem[player_2 + 1]) << 0x8 | uint(c2da_mem[player_2 + 2]) << 0x10 | uint(c2da_mem[player_2 + 3]) << 0x18) + 116
    let c2da_fresh116 : int = int(uint(c2da_mem[c2da_fresh115]) | uint(c2da_mem[c2da_fresh115 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh115 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh115 + 3]) << 0x18) + int(FixedMul(move, int(uint(c2da_mem[257920 + int(angle_0) * 4]) | uint(c2da_mem[257920 + int(angle_0) * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + int(angle_0) * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + int(angle_0) * 4 + 3]) << 0x18)))
    let c2da_fresh117 : uint = uint(c2da_fresh116)
    c2da_mem[c2da_fresh115] = uint8(c2da_fresh117)
    c2da_mem[c2da_fresh115 + 1] = uint8(c2da_fresh117 >> 0x8)
    c2da_mem[c2da_fresh115 + 2] = uint8(c2da_fresh117 >> 0x10)
    c2da_mem[c2da_fresh115 + 3] = uint8(c2da_fresh117 >> 0x18)
    return
}
[export, sideeffects]
def P_DeathThink(var player_3 : int) {
    var angle_1 : uint
    var delta : uint
    P_MovePsprites(player_3)
    if (int(uint(c2da_mem[player_3 + 32]) | uint(c2da_mem[player_3 + 33]) << 0x8 | uint(c2da_mem[player_3 + 34]) << 0x10 | uint(c2da_mem[player_3 + 35]) << 0x18) > 6 * (1 << 16)) {
        let c2da_fresh118 : int = int(uint(c2da_mem[player_3 + 32]) | uint(c2da_mem[player_3 + 33]) << 0x8 | uint(c2da_mem[player_3 + 34]) << 0x10 | uint(c2da_mem[player_3 + 35]) << 0x18) - (1 << 16)
        let c2da_fresh119 : uint = uint(c2da_fresh118)
        c2da_mem[player_3 + 32] = uint8(c2da_fresh119)
        c2da_mem[player_3 + 33] = uint8(c2da_fresh119 >> 0x8)
        c2da_mem[player_3 + 34] = uint8(c2da_fresh119 >> 0x10)
        c2da_mem[player_3 + 35] = uint8(c2da_fresh119 >> 0x18)
    }
    if (int(uint(c2da_mem[player_3 + 32]) | uint(c2da_mem[player_3 + 33]) << 0x8 | uint(c2da_mem[player_3 + 34]) << 0x10 | uint(c2da_mem[player_3 + 35]) << 0x18) < 6 * (1 << 16)) {
        let c2da_fresh120 : int = 6 * (1 << 16)
        let c2da_fresh121 : uint = uint(c2da_fresh120)
        c2da_mem[player_3 + 32] = uint8(c2da_fresh121)
        c2da_mem[player_3 + 33] = uint8(c2da_fresh121 >> 0x8)
        c2da_mem[player_3 + 34] = uint8(c2da_fresh121 >> 0x10)
        c2da_mem[player_3 + 35] = uint8(c2da_fresh121 >> 0x18)
    }
    let c2da_fresh122 : int = 0
    let c2da_fresh123 : uint = uint(c2da_fresh122)
    c2da_mem[player_3 + 36] = uint8(c2da_fresh123)
    c2da_mem[player_3 + 37] = uint8(c2da_fresh123 >> 0x8)
    c2da_mem[player_3 + 38] = uint8(c2da_fresh123 >> 0x10)
    c2da_mem[player_3 + 39] = uint8(c2da_fresh123 >> 0x18)
    let c2da_fresh124 : int = int(uint(c2da_mem[player_3]) | uint(c2da_mem[player_3 + 1]) << 0x8 | uint(c2da_mem[player_3 + 2]) << 0x10 | uint(c2da_mem[player_3 + 3]) << 0x18) + 32
    let c2da_fresh125 : int = int(uint(c2da_mem[player_3]) | uint(c2da_mem[player_3 + 1]) << 0x8 | uint(c2da_mem[player_3 + 2]) << 0x10 | uint(c2da_mem[player_3 + 3]) << 0x18) + 96
    onground = uint(int(uint(c2da_mem[c2da_fresh124]) | uint(c2da_mem[c2da_fresh124 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh124 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh124 + 3]) << 0x18) <= int(uint(c2da_mem[c2da_fresh125]) | uint(c2da_mem[c2da_fresh125 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh125 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh125 + 3]) << 0x18) ? 1 : 0)
    P_CalcHeight(player_3)
    if (int(uint(c2da_mem[player_3 + 248]) | uint(c2da_mem[player_3 + 249]) << 0x8 | uint(c2da_mem[player_3 + 250]) << 0x10 | uint(c2da_mem[player_3 + 251]) << 0x18) != 0 && int(uint(c2da_mem[player_3 + 248]) | uint(c2da_mem[player_3 + 249]) << 0x8 | uint(c2da_mem[player_3 + 250]) << 0x10 | uint(c2da_mem[player_3 + 251]) << 0x18) != int(uint(c2da_mem[player_3]) | uint(c2da_mem[player_3 + 1]) << 0x8 | uint(c2da_mem[player_3 + 2]) << 0x10 | uint(c2da_mem[player_3 + 3]) << 0x18)) {
        let c2da_fresh126 : int = int(uint(c2da_mem[player_3]) | uint(c2da_mem[player_3 + 1]) << 0x8 | uint(c2da_mem[player_3 + 2]) << 0x10 | uint(c2da_mem[player_3 + 3]) << 0x18) + 24
        let c2da_fresh127 : int = int(uint(c2da_mem[player_3]) | uint(c2da_mem[player_3 + 1]) << 0x8 | uint(c2da_mem[player_3 + 2]) << 0x10 | uint(c2da_mem[player_3 + 3]) << 0x18) + 28
        let c2da_fresh128 : int = int(uint(c2da_mem[player_3 + 248]) | uint(c2da_mem[player_3 + 249]) << 0x8 | uint(c2da_mem[player_3 + 250]) << 0x10 | uint(c2da_mem[player_3 + 251]) << 0x18) + 24
        let c2da_fresh129 : int = int(uint(c2da_mem[player_3 + 248]) | uint(c2da_mem[player_3 + 249]) << 0x8 | uint(c2da_mem[player_3 + 250]) << 0x10 | uint(c2da_mem[player_3 + 251]) << 0x18) + 28
        angle_1 = uint(R_PointToAngle2(int(uint(c2da_mem[c2da_fresh126]) | uint(c2da_mem[c2da_fresh126 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh126 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh126 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh127]) | uint(c2da_mem[c2da_fresh127 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh127 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh127 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh128]) | uint(c2da_mem[c2da_fresh128 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh128 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh128 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh129]) | uint(c2da_mem[c2da_fresh129 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh129 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh129 + 3]) << 0x18)))
        let c2da_fresh130 : int = int(uint(c2da_mem[player_3]) | uint(c2da_mem[player_3 + 1]) << 0x8 | uint(c2da_mem[player_3 + 2]) << 0x10 | uint(c2da_mem[player_3 + 3]) << 0x18) + 56
        delta = angle_1 - (uint(c2da_mem[c2da_fresh130]) | uint(c2da_mem[c2da_fresh130 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh130 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh130 + 3]) << 0x18)
        if (delta < uint(1073741824 / 18) || delta > uint(-(1073741824 / 18))) {
            let c2da_fresh131 : int = int(uint(c2da_mem[player_3]) | uint(c2da_mem[player_3 + 1]) << 0x8 | uint(c2da_mem[player_3 + 2]) << 0x10 | uint(c2da_mem[player_3 + 3]) << 0x18) + 56
            let c2da_fresh132 : uint = angle_1
            c2da_mem[c2da_fresh131] = uint8(c2da_fresh132)
            c2da_mem[c2da_fresh131 + 1] = uint8(c2da_fresh132 >> 0x8)
            c2da_mem[c2da_fresh131 + 2] = uint8(c2da_fresh132 >> 0x10)
            c2da_mem[c2da_fresh131 + 3] = uint8(c2da_fresh132 >> 0x18)
            if (int(uint(c2da_mem[player_3 + 240]) | uint(c2da_mem[player_3 + 241]) << 0x8 | uint(c2da_mem[player_3 + 242]) << 0x10 | uint(c2da_mem[player_3 + 243]) << 0x18) != 0) {
                let c2da_fresh133 : int = int(uint(c2da_mem[player_3 + 240]) | uint(c2da_mem[player_3 + 241]) << 0x8 | uint(c2da_mem[player_3 + 242]) << 0x10 | uint(c2da_mem[player_3 + 243]) << 0x18)
                let c2da_fresh134 : int = c2da_fresh133 - 1
                let c2da_fresh135 : uint = uint(c2da_fresh134)
                c2da_mem[player_3 + 240] = uint8(c2da_fresh135)
                c2da_mem[player_3 + 241] = uint8(c2da_fresh135 >> 0x8)
                c2da_mem[player_3 + 242] = uint8(c2da_fresh135 >> 0x10)
                c2da_mem[player_3 + 243] = uint8(c2da_fresh135 >> 0x18)
            }
        } elif (delta < 0x80000000u) {
            let c2da_fresh136 : int = int(uint(c2da_mem[player_3]) | uint(c2da_mem[player_3 + 1]) << 0x8 | uint(c2da_mem[player_3 + 2]) << 0x10 | uint(c2da_mem[player_3 + 3]) << 0x18) + 56
            let c2da_fresh137 : uint = (uint(c2da_mem[c2da_fresh136]) | uint(c2da_mem[c2da_fresh136 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh136 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh136 + 3]) << 0x18) + uint(1073741824 / 18)
            let c2da_fresh138 : uint = c2da_fresh137
            c2da_mem[c2da_fresh136] = uint8(c2da_fresh138)
            c2da_mem[c2da_fresh136 + 1] = uint8(c2da_fresh138 >> 0x8)
            c2da_mem[c2da_fresh136 + 2] = uint8(c2da_fresh138 >> 0x10)
            c2da_mem[c2da_fresh136 + 3] = uint8(c2da_fresh138 >> 0x18)
        } else {
            let c2da_fresh139 : int = int(uint(c2da_mem[player_3]) | uint(c2da_mem[player_3 + 1]) << 0x8 | uint(c2da_mem[player_3 + 2]) << 0x10 | uint(c2da_mem[player_3 + 3]) << 0x18) + 56
            let c2da_fresh140 : uint = (uint(c2da_mem[c2da_fresh139]) | uint(c2da_mem[c2da_fresh139 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh139 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh139 + 3]) << 0x18) - uint(1073741824 / 18)
            let c2da_fresh141 : uint = c2da_fresh140
            c2da_mem[c2da_fresh139] = uint8(c2da_fresh141)
            c2da_mem[c2da_fresh139 + 1] = uint8(c2da_fresh141 >> 0x8)
            c2da_mem[c2da_fresh139 + 2] = uint8(c2da_fresh141 >> 0x10)
            c2da_mem[c2da_fresh139 + 3] = uint8(c2da_fresh141 >> 0x18)
        }
    } elif (int(uint(c2da_mem[player_3 + 240]) | uint(c2da_mem[player_3 + 241]) << 0x8 | uint(c2da_mem[player_3 + 242]) << 0x10 | uint(c2da_mem[player_3 + 243]) << 0x18) != 0) {
        let c2da_fresh142 : int = int(uint(c2da_mem[player_3 + 240]) | uint(c2da_mem[player_3 + 241]) << 0x8 | uint(c2da_mem[player_3 + 242]) << 0x10 | uint(c2da_mem[player_3 + 243]) << 0x18)
        let c2da_fresh143 : int = c2da_fresh142 - 1
        let c2da_fresh144 : uint = uint(c2da_fresh143)
        c2da_mem[player_3 + 240] = uint8(c2da_fresh144)
        c2da_mem[player_3 + 241] = uint8(c2da_fresh144 >> 0x8)
        c2da_mem[player_3 + 242] = uint8(c2da_fresh144 >> 0x10)
        c2da_mem[player_3 + 243] = uint8(c2da_fresh144 >> 0x18)
    }
    if ((int(c2da_mem[player_3 + 17]) & 2) != 0) {
        let c2da_fresh145 : uint = 2u
        let c2da_fresh146 : uint = c2da_fresh145
        c2da_mem[player_3 + 8] = uint8(c2da_fresh146)
        c2da_mem[player_3 + 9] = uint8(c2da_fresh146 >> 0x8)
        c2da_mem[player_3 + 10] = uint8(c2da_fresh146 >> 0x10)
        c2da_mem[player_3 + 11] = uint8(c2da_fresh146 >> 0x18)
    }
    return
}
