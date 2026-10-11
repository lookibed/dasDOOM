var maxammo : int[4] = fixed_array<int>(200, 50, 300, 50)

var clipammo : int[4] = fixed_array<int>(10, 4, 20, 1)

[export, sideeffects]
def P_TouchSpecialThing(var special : int; var toucher : int) {
    var c2da_fresh0 : uint
    var player : int
    var i : int
    var delta : int
    var sound : int
    delta = int(uint(c2da_mem[special + 32]) | uint(c2da_mem[special + 33]) << 0x8 | uint(c2da_mem[special + 34]) << 0x10 | uint(c2da_mem[special + 35]) << 0x18) - int(uint(c2da_mem[toucher + 32]) | uint(c2da_mem[toucher + 33]) << 0x8 | uint(c2da_mem[toucher + 34]) << 0x10 | uint(c2da_mem[toucher + 35]) << 0x18)
    if (delta > int(uint(c2da_mem[toucher + 108]) | uint(c2da_mem[toucher + 109]) << 0x8 | uint(c2da_mem[toucher + 110]) << 0x10 | uint(c2da_mem[toucher + 111]) << 0x18) || delta < -8 * (1 << 16)) {
        return
    }
    sound = 32
    player = int(uint(c2da_mem[toucher + 192]) | uint(c2da_mem[toucher + 193]) << 0x8 | uint(c2da_mem[toucher + 194]) << 0x10 | uint(c2da_mem[toucher + 195]) << 0x18)
    if (int(uint(c2da_mem[toucher + 164]) | uint(c2da_mem[toucher + 165]) << 0x8 | uint(c2da_mem[toucher + 166]) << 0x10 | uint(c2da_mem[toucher + 167]) << 0x18) <= 0) {
        return
    }
    c2da_fresh0 = uint(c2da_mem[special + 60]) | uint(c2da_mem[special + 61]) << 0x8 | uint(c2da_mem[special + 62]) << 0x10 | uint(c2da_mem[special + 63]) << 0x18
    if (c2da_fresh0 >= 0x37u && c2da_fresh0 <= 0x5du) {
        goto int(c2da_fresh0 - 0x37u) + 27
    }
    goto label 25
    label 27:
    if (P_GiveArmor(player, 1) == 0) {
        goto label 0
    }
    let c2da_fresh1 : uint = 359200u
    c2da_mem[player + 232] = uint8(c2da_fresh1)
    c2da_mem[player + 233] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh1 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    goto label 26
    label 0:
    return
    label 28:
    if (P_GiveArmor(player, 2) == 0) {
        goto label 1
    }
    let c2da_fresh2 : uint = 359221u
    c2da_mem[player + 232] = uint8(c2da_fresh2)
    c2da_mem[player + 233] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh2 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    goto label 26
    label 1:
    return
    label 32:
    let c2da_fresh3 : int = int(uint(c2da_mem[player + 44]) | uint(c2da_mem[player + 45]) << 0x8 | uint(c2da_mem[player + 46]) << 0x10 | uint(c2da_mem[player + 47]) << 0x18)
    let c2da_fresh4 : int = c2da_fresh3 + 1
    let c2da_fresh5 : uint = uint(c2da_fresh4)
    c2da_mem[player + 44] = uint8(c2da_fresh5)
    c2da_mem[player + 45] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[player + 46] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[player + 47] = uint8(c2da_fresh5 >> 0x18)
    if (int(uint(c2da_mem[player + 44]) | uint(c2da_mem[player + 45]) << 0x8 | uint(c2da_mem[player + 46]) << 0x10 | uint(c2da_mem[player + 47]) << 0x18) > 200) {
        let c2da_fresh6 : int = 200
        let c2da_fresh7 : uint = uint(c2da_fresh6)
        c2da_mem[player + 44] = uint8(c2da_fresh7)
        c2da_mem[player + 45] = uint8(c2da_fresh7 >> 0x8)
        c2da_mem[player + 46] = uint8(c2da_fresh7 >> 0x10)
        c2da_mem[player + 47] = uint8(c2da_fresh7 >> 0x18)
    }
    let c2da_fresh8 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 164
    let c2da_fresh9 : int = int(uint(c2da_mem[player + 44]) | uint(c2da_mem[player + 45]) << 0x8 | uint(c2da_mem[player + 46]) << 0x10 | uint(c2da_mem[player + 47]) << 0x18)
    let c2da_fresh10 : uint = uint(c2da_fresh9)
    c2da_mem[c2da_fresh8] = uint8(c2da_fresh10)
    c2da_mem[c2da_fresh8 + 1] = uint8(c2da_fresh10 >> 0x8)
    c2da_mem[c2da_fresh8 + 2] = uint8(c2da_fresh10 >> 0x10)
    c2da_mem[c2da_fresh8 + 3] = uint8(c2da_fresh10 >> 0x18)
    let c2da_fresh11 : uint = 359246u
    c2da_mem[player + 232] = uint8(c2da_fresh11)
    c2da_mem[player + 233] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh11 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    goto label 26
    label 33:
    let c2da_fresh12 : int = int(uint(c2da_mem[player + 48]) | uint(c2da_mem[player + 49]) << 0x8 | uint(c2da_mem[player + 50]) << 0x10 | uint(c2da_mem[player + 51]) << 0x18)
    let c2da_fresh13 : int = c2da_fresh12 + 1
    let c2da_fresh14 : uint = uint(c2da_fresh13)
    c2da_mem[player + 48] = uint8(c2da_fresh14)
    c2da_mem[player + 49] = uint8(c2da_fresh14 >> 0x8)
    c2da_mem[player + 50] = uint8(c2da_fresh14 >> 0x10)
    c2da_mem[player + 51] = uint8(c2da_fresh14 >> 0x18)
    if (int(uint(c2da_mem[player + 48]) | uint(c2da_mem[player + 49]) << 0x8 | uint(c2da_mem[player + 50]) << 0x10 | uint(c2da_mem[player + 51]) << 0x18) > 200) {
        let c2da_fresh15 : int = 200
        let c2da_fresh16 : uint = uint(c2da_fresh15)
        c2da_mem[player + 48] = uint8(c2da_fresh16)
        c2da_mem[player + 49] = uint8(c2da_fresh16 >> 0x8)
        c2da_mem[player + 50] = uint8(c2da_fresh16 >> 0x10)
        c2da_mem[player + 51] = uint8(c2da_fresh16 >> 0x18)
    }
    if (int(uint(c2da_mem[player + 52]) | uint(c2da_mem[player + 53]) << 0x8 | uint(c2da_mem[player + 54]) << 0x10 | uint(c2da_mem[player + 55]) << 0x18) == 0) {
        let c2da_fresh17 : int = 1
        let c2da_fresh18 : uint = uint(c2da_fresh17)
        c2da_mem[player + 52] = uint8(c2da_fresh18)
        c2da_mem[player + 53] = uint8(c2da_fresh18 >> 0x8)
        c2da_mem[player + 54] = uint8(c2da_fresh18 >> 0x10)
        c2da_mem[player + 55] = uint8(c2da_fresh18 >> 0x18)
    }
    let c2da_fresh19 : uint = 359272u
    c2da_mem[player + 232] = uint8(c2da_fresh19)
    c2da_mem[player + 233] = uint8(c2da_fresh19 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh19 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh19 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    goto label 26
    label 42:
    let c2da_fresh20 : int = int(uint(c2da_mem[player + 44]) | uint(c2da_mem[player + 45]) << 0x8 | uint(c2da_mem[player + 46]) << 0x10 | uint(c2da_mem[player + 47]) << 0x18) + 100
    let c2da_fresh21 : uint = uint(c2da_fresh20)
    c2da_mem[player + 44] = uint8(c2da_fresh21)
    c2da_mem[player + 45] = uint8(c2da_fresh21 >> 0x8)
    c2da_mem[player + 46] = uint8(c2da_fresh21 >> 0x10)
    c2da_mem[player + 47] = uint8(c2da_fresh21 >> 0x18)
    if (int(uint(c2da_mem[player + 44]) | uint(c2da_mem[player + 45]) << 0x8 | uint(c2da_mem[player + 46]) << 0x10 | uint(c2da_mem[player + 47]) << 0x18) > 200) {
        let c2da_fresh22 : int = 200
        let c2da_fresh23 : uint = uint(c2da_fresh22)
        c2da_mem[player + 44] = uint8(c2da_fresh23)
        c2da_mem[player + 45] = uint8(c2da_fresh23 >> 0x8)
        c2da_mem[player + 46] = uint8(c2da_fresh23 >> 0x10)
        c2da_mem[player + 47] = uint8(c2da_fresh23 >> 0x18)
    }
    let c2da_fresh24 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 164
    let c2da_fresh25 : int = int(uint(c2da_mem[player + 44]) | uint(c2da_mem[player + 45]) << 0x8 | uint(c2da_mem[player + 46]) << 0x10 | uint(c2da_mem[player + 47]) << 0x18)
    let c2da_fresh26 : uint = uint(c2da_fresh25)
    c2da_mem[c2da_fresh24] = uint8(c2da_fresh26)
    c2da_mem[c2da_fresh24 + 1] = uint8(c2da_fresh26 >> 0x8)
    c2da_mem[c2da_fresh24 + 2] = uint8(c2da_fresh26 >> 0x10)
    c2da_mem[c2da_fresh24 + 3] = uint8(c2da_fresh26 >> 0x18)
    let c2da_fresh27 : uint = 359298u
    c2da_mem[player + 232] = uint8(c2da_fresh27)
    c2da_mem[player + 233] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh27 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    sound = 93
    goto label 26
    label 46:
    if (uint(gamemode) != 2u) {
        goto label 2
    }
    let c2da_fresh28 : int = 200
    let c2da_fresh29 : uint = uint(c2da_fresh28)
    c2da_mem[player + 44] = uint8(c2da_fresh29)
    c2da_mem[player + 45] = uint8(c2da_fresh29 >> 0x8)
    c2da_mem[player + 46] = uint8(c2da_fresh29 >> 0x10)
    c2da_mem[player + 47] = uint8(c2da_fresh29 >> 0x18)
    let c2da_fresh30 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 164
    let c2da_fresh31 : int = int(uint(c2da_mem[player + 44]) | uint(c2da_mem[player + 45]) << 0x8 | uint(c2da_mem[player + 46]) << 0x10 | uint(c2da_mem[player + 47]) << 0x18)
    let c2da_fresh32 : uint = uint(c2da_fresh31)
    c2da_mem[c2da_fresh30] = uint8(c2da_fresh32)
    c2da_mem[c2da_fresh30 + 1] = uint8(c2da_fresh32 >> 0x8)
    c2da_mem[c2da_fresh30 + 2] = uint8(c2da_fresh32 >> 0x10)
    c2da_mem[c2da_fresh30 + 3] = uint8(c2da_fresh32 >> 0x18)
    P_GiveArmor(player, 2)
    let c2da_fresh33 : uint = 359311u
    c2da_mem[player + 232] = uint8(c2da_fresh33)
    c2da_mem[player + 233] = uint8(c2da_fresh33 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh33 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh33 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    sound = 93
    goto label 26
    label 2:
    return
    label 34:
    if ((uint(c2da_mem[player + 80 + 0 * 4]) | uint(c2da_mem[player + 80 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 80 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 80 + 0 * 4 + 3]) << 0x18) == 0) {
        let c2da_fresh34 : uint = 359323u
        c2da_mem[player + 232] = uint8(c2da_fresh34)
        c2da_mem[player + 233] = uint8(c2da_fresh34 >> 0x8)
        c2da_mem[player + 234] = uint8(c2da_fresh34 >> 0x10)
        c2da_mem[player + 235] = uint8(c2da_fresh34 >> 0x18)
        c2da_mem[player + 236] = 0u8
        c2da_mem[player + 237] = 0u8
        c2da_mem[player + 238] = 0u8
        c2da_mem[player + 239] = 0u8
    }
    P_GiveCard(player, 0u)
    if (netgame == 0) {
        goto label 26
    }
    return
    label 36:
    if ((uint(c2da_mem[player + 80 + 1 * 4]) | uint(c2da_mem[player + 80 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 80 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 80 + 1 * 4 + 3]) << 0x18) == 0) {
        let c2da_fresh35 : uint = 359349u
        c2da_mem[player + 232] = uint8(c2da_fresh35)
        c2da_mem[player + 233] = uint8(c2da_fresh35 >> 0x8)
        c2da_mem[player + 234] = uint8(c2da_fresh35 >> 0x10)
        c2da_mem[player + 235] = uint8(c2da_fresh35 >> 0x18)
        c2da_mem[player + 236] = 0u8
        c2da_mem[player + 237] = 0u8
        c2da_mem[player + 238] = 0u8
        c2da_mem[player + 239] = 0u8
    }
    P_GiveCard(player, 1u)
    if (netgame == 0) {
        goto label 26
    }
    return
    label 35:
    if ((uint(c2da_mem[player + 80 + 2 * 4]) | uint(c2da_mem[player + 80 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 80 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 80 + 2 * 4 + 3]) << 0x18) == 0) {
        let c2da_fresh36 : uint = 359377u
        c2da_mem[player + 232] = uint8(c2da_fresh36)
        c2da_mem[player + 233] = uint8(c2da_fresh36 >> 0x8)
        c2da_mem[player + 234] = uint8(c2da_fresh36 >> 0x10)
        c2da_mem[player + 235] = uint8(c2da_fresh36 >> 0x18)
        c2da_mem[player + 236] = 0u8
        c2da_mem[player + 237] = 0u8
        c2da_mem[player + 238] = 0u8
        c2da_mem[player + 239] = 0u8
    }
    P_GiveCard(player, 2u)
    if (netgame == 0) {
        goto label 26
    }
    return
    label 37:
    if ((uint(c2da_mem[player + 80 + 3 * 4]) | uint(c2da_mem[player + 80 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 80 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 80 + 3 * 4 + 3]) << 0x18) == 0) {
        let c2da_fresh37 : uint = 359402u
        c2da_mem[player + 232] = uint8(c2da_fresh37)
        c2da_mem[player + 233] = uint8(c2da_fresh37 >> 0x8)
        c2da_mem[player + 234] = uint8(c2da_fresh37 >> 0x10)
        c2da_mem[player + 235] = uint8(c2da_fresh37 >> 0x18)
        c2da_mem[player + 236] = 0u8
        c2da_mem[player + 237] = 0u8
        c2da_mem[player + 238] = 0u8
        c2da_mem[player + 239] = 0u8
    }
    P_GiveCard(player, 3u)
    if (netgame == 0) {
        goto label 26
    }
    return
    label 39:
    if ((uint(c2da_mem[player + 80 + 4 * 4]) | uint(c2da_mem[player + 80 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 80 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 80 + 4 * 4 + 3]) << 0x18) == 0) {
        let c2da_fresh38 : uint = 359430u
        c2da_mem[player + 232] = uint8(c2da_fresh38)
        c2da_mem[player + 233] = uint8(c2da_fresh38 >> 0x8)
        c2da_mem[player + 234] = uint8(c2da_fresh38 >> 0x10)
        c2da_mem[player + 235] = uint8(c2da_fresh38 >> 0x18)
        c2da_mem[player + 236] = 0u8
        c2da_mem[player + 237] = 0u8
        c2da_mem[player + 238] = 0u8
        c2da_mem[player + 239] = 0u8
    }
    P_GiveCard(player, 4u)
    if (netgame == 0) {
        goto label 26
    }
    return
    label 38:
    if ((uint(c2da_mem[player + 80 + 5 * 4]) | uint(c2da_mem[player + 80 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[player + 80 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[player + 80 + 5 * 4 + 3]) << 0x18) == 0) {
        let c2da_fresh39 : uint = 359460u
        c2da_mem[player + 232] = uint8(c2da_fresh39)
        c2da_mem[player + 233] = uint8(c2da_fresh39 >> 0x8)
        c2da_mem[player + 234] = uint8(c2da_fresh39 >> 0x10)
        c2da_mem[player + 235] = uint8(c2da_fresh39 >> 0x18)
        c2da_mem[player + 236] = 0u8
        c2da_mem[player + 237] = 0u8
        c2da_mem[player + 238] = 0u8
        c2da_mem[player + 239] = 0u8
    }
    P_GiveCard(player, 5u)
    if (netgame == 0) {
        goto label 26
    }
    return
    label 40:
    if (P_GiveBody(player, 10) == 0) {
        goto label 3
    }
    let c2da_fresh40 : uint = 359487u
    c2da_mem[player + 232] = uint8(c2da_fresh40)
    c2da_mem[player + 233] = uint8(c2da_fresh40 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh40 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh40 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    goto label 26
    label 3:
    return
    label 41:
    if (P_GiveBody(player, 25) == 0) {
        goto label 4
    }
    if (int(uint(c2da_mem[player + 44]) | uint(c2da_mem[player + 45]) << 0x8 | uint(c2da_mem[player + 46]) << 0x10 | uint(c2da_mem[player + 47]) << 0x18) < 25) {
        let c2da_fresh41 : uint = 359509u
        c2da_mem[player + 232] = uint8(c2da_fresh41)
        c2da_mem[player + 233] = uint8(c2da_fresh41 >> 0x8)
        c2da_mem[player + 234] = uint8(c2da_fresh41 >> 0x10)
        c2da_mem[player + 235] = uint8(c2da_fresh41 >> 0x18)
        c2da_mem[player + 236] = 0u8
        c2da_mem[player + 237] = 0u8
        c2da_mem[player + 238] = 0u8
        c2da_mem[player + 239] = 0u8
    } else {
        let c2da_fresh42 : uint = 359551u
        c2da_mem[player + 232] = uint8(c2da_fresh42)
        c2da_mem[player + 233] = uint8(c2da_fresh42 >> 0x8)
        c2da_mem[player + 234] = uint8(c2da_fresh42 >> 0x10)
        c2da_mem[player + 235] = uint8(c2da_fresh42 >> 0x18)
        c2da_mem[player + 236] = 0u8
        c2da_mem[player + 237] = 0u8
        c2da_mem[player + 238] = 0u8
        c2da_mem[player + 239] = 0u8
    }
    goto label 26
    label 4:
    return
    label 43:
    if (P_GivePower(player, 0) == 0) {
        goto label 5
    }
    let c2da_fresh43 : uint = 359572u
    c2da_mem[player + 232] = uint8(c2da_fresh43)
    c2da_mem[player + 233] = uint8(c2da_fresh43 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh43 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh43 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    sound = 93
    goto label 26
    label 5:
    return
    label 44:
    if (P_GivePower(player, 1) == 0) {
        goto label 6
    }
    let c2da_fresh44 : uint = 359589u
    c2da_mem[player + 232] = uint8(c2da_fresh44)
    c2da_mem[player + 233] = uint8(c2da_fresh44 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh44 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh44 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    if ((uint(c2da_mem[player + 124]) | uint(c2da_mem[player + 125]) << 0x8 | uint(c2da_mem[player + 126]) << 0x10 | uint(c2da_mem[player + 127]) << 0x18) != 0u) {
        let c2da_fresh45 : uint = 0u
        let c2da_fresh46 : uint = c2da_fresh45
        c2da_mem[player + 128] = uint8(c2da_fresh46)
        c2da_mem[player + 129] = uint8(c2da_fresh46 >> 0x8)
        c2da_mem[player + 130] = uint8(c2da_fresh46 >> 0x10)
        c2da_mem[player + 131] = uint8(c2da_fresh46 >> 0x18)
    }
    sound = 93
    goto label 26
    label 6:
    return
    label 45:
    if (P_GivePower(player, 2) == 0) {
        goto label 7
    }
    let c2da_fresh47 : uint = 359598u
    c2da_mem[player + 232] = uint8(c2da_fresh47)
    c2da_mem[player + 233] = uint8(c2da_fresh47 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh47 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh47 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    sound = 93
    goto label 26
    label 7:
    return
    label 47:
    if (P_GivePower(player, 3) == 0) {
        goto label 8
    }
    let c2da_fresh48 : uint = 359619u
    c2da_mem[player + 232] = uint8(c2da_fresh48)
    c2da_mem[player + 233] = uint8(c2da_fresh48 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh48 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh48 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    sound = 93
    goto label 26
    label 8:
    return
    label 48:
    if (P_GivePower(player, 4) == 0) {
        goto label 9
    }
    let c2da_fresh49 : uint = 359644u
    c2da_mem[player + 232] = uint8(c2da_fresh49)
    c2da_mem[player + 233] = uint8(c2da_fresh49 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh49 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh49 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    sound = 93
    goto label 26
    label 9:
    return
    label 49:
    if (P_GivePower(player, 5) == 0) {
        goto label 10
    }
    let c2da_fresh50 : uint = 359662u
    c2da_mem[player + 232] = uint8(c2da_fresh50)
    c2da_mem[player + 233] = uint8(c2da_fresh50 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh50 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh50 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    sound = 93
    goto label 26
    label 10:
    return
    label 50:
    if ((int(uint(c2da_mem[special + 160]) | uint(c2da_mem[special + 161]) << 0x8 | uint(c2da_mem[special + 162]) << 0x10 | uint(c2da_mem[special + 163]) << 0x18) & 131072) != 0) {
        if (P_GiveAmmo(player, 0u, 0) == 0) {
            return
        }
    } elif (P_GiveAmmo(player, 0u, 1) == 0) {
        return
    }
    let c2da_fresh51 : uint = 359688u
    c2da_mem[player + 232] = uint8(c2da_fresh51)
    c2da_mem[player + 233] = uint8(c2da_fresh51 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh51 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh51 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    goto label 26
    label 51:
    if (P_GiveAmmo(player, 0u, 5) == 0) {
        goto label 11
    }
    let c2da_fresh52 : uint = 359706u
    c2da_mem[player + 232] = uint8(c2da_fresh52)
    c2da_mem[player + 233] = uint8(c2da_fresh52 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh52 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh52 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    goto label 26
    label 11:
    return
    label 52:
    if (P_GiveAmmo(player, 3u, 1) == 0) {
        goto label 12
    }
    let c2da_fresh53 : uint = 359734u
    c2da_mem[player + 232] = uint8(c2da_fresh53)
    c2da_mem[player + 233] = uint8(c2da_fresh53 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh53 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh53 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    goto label 26
    label 12:
    return
    label 53:
    if (P_GiveAmmo(player, 3u, 5) == 0) {
        goto label 13
    }
    let c2da_fresh54 : uint = 359754u
    c2da_mem[player + 232] = uint8(c2da_fresh54)
    c2da_mem[player + 233] = uint8(c2da_fresh54 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh54 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh54 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    goto label 26
    label 13:
    return
    label 54:
    if (P_GiveAmmo(player, 2u, 1) == 0) {
        goto label 14
    }
    let c2da_fresh55 : uint = 359782u
    c2da_mem[player + 232] = uint8(c2da_fresh55)
    c2da_mem[player + 233] = uint8(c2da_fresh55 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh55 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh55 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    goto label 26
    label 14:
    return
    label 55:
    if (P_GiveAmmo(player, 2u, 5) == 0) {
        goto label 15
    }
    let c2da_fresh56 : uint = 359808u
    c2da_mem[player + 232] = uint8(c2da_fresh56)
    c2da_mem[player + 233] = uint8(c2da_fresh56 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh56 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh56 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    goto label 26
    label 15:
    return
    label 56:
    if (P_GiveAmmo(player, 1u, 1) == 0) {
        goto label 16
    }
    let c2da_fresh57 : uint = 359839u
    c2da_mem[player + 232] = uint8(c2da_fresh57)
    c2da_mem[player + 233] = uint8(c2da_fresh57 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh57 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh57 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    goto label 26
    label 16:
    return
    label 57:
    if (P_GiveAmmo(player, 1u, 5) == 0) {
        goto label 17
    }
    let c2da_fresh58 : uint = 359867u
    c2da_mem[player + 232] = uint8(c2da_fresh58)
    c2da_mem[player + 233] = uint8(c2da_fresh58 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh58 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh58 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    goto label 26
    label 17:
    return
    label 58:
    if ((uint(c2da_mem[player + 104]) | uint(c2da_mem[player + 105]) << 0x8 | uint(c2da_mem[player + 106]) << 0x10 | uint(c2da_mem[player + 107]) << 0x18) == 0) {
        i = 0
        while (i < 4) {
            let c2da_fresh59 : int = int(uint(c2da_mem[player + 184 + i * 4]) | uint(c2da_mem[player + 184 + i * 4 + 1]) << 0x8 | uint(c2da_mem[player + 184 + i * 4 + 2]) << 0x10 | uint(c2da_mem[player + 184 + i * 4 + 3]) << 0x18) * 2
            let c2da_fresh60 : uint = uint(c2da_fresh59)
            c2da_mem[player + 184 + i * 4] = uint8(c2da_fresh60)
            c2da_mem[player + 184 + i * 4 + 1] = uint8(c2da_fresh60 >> 0x8)
            c2da_mem[player + 184 + i * 4 + 2] = uint8(c2da_fresh60 >> 0x10)
            c2da_mem[player + 184 + i * 4 + 3] = uint8(c2da_fresh60 >> 0x18)
            i++
        }
        let c2da_fresh61 : uint = 1u
        let c2da_fresh62 : uint = c2da_fresh61
        c2da_mem[player + 104] = uint8(c2da_fresh62)
        c2da_mem[player + 105] = uint8(c2da_fresh62 >> 0x8)
        c2da_mem[player + 106] = uint8(c2da_fresh62 >> 0x10)
        c2da_mem[player + 107] = uint8(c2da_fresh62 >> 0x18)
    }
    i = 0
    while (i < 4) {
        P_GiveAmmo(player, uint(i), 1)
        i++
    }
    let c2da_fresh63 : uint = 359902u
    c2da_mem[player + 232] = uint8(c2da_fresh63)
    c2da_mem[player + 233] = uint8(c2da_fresh63 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh63 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh63 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    goto label 26
    label 59:
    if (P_GiveWeapon(player, 6u, 0u) == 0) {
        goto label 18
    }
    let c2da_fresh64 : uint = 359937u
    c2da_mem[player + 232] = uint8(c2da_fresh64)
    c2da_mem[player + 233] = uint8(c2da_fresh64 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh64 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh64 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    sound = 33
    goto label 26
    label 18:
    return
    label 60:
    if (P_GiveWeapon(player, 3u, uint((int(uint(c2da_mem[special + 160]) | uint(c2da_mem[special + 161]) << 0x8 | uint(c2da_mem[special + 162]) << 0x10 | uint(c2da_mem[special + 163]) << 0x18) & 131072) != 0 ? 1 : 0)) == 0) {
        goto label 19
    }
    let c2da_fresh65 : uint = 359968u
    c2da_mem[player + 232] = uint8(c2da_fresh65)
    c2da_mem[player + 233] = uint8(c2da_fresh65 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh65 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh65 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    sound = 33
    goto label 26
    label 19:
    return
    label 61:
    if (P_GiveWeapon(player, 7u, 0u) == 0) {
        goto label 20
    }
    let c2da_fresh66 : uint = 359990u
    c2da_mem[player + 232] = uint8(c2da_fresh66)
    c2da_mem[player + 233] = uint8(c2da_fresh66 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh66 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh66 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    sound = 33
    goto label 26
    label 20:
    return
    label 62:
    if (P_GiveWeapon(player, 4u, 0u) == 0) {
        goto label 21
    }
    let c2da_fresh67 : uint = 360019u
    c2da_mem[player + 232] = uint8(c2da_fresh67)
    c2da_mem[player + 233] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh67 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    sound = 33
    goto label 26
    label 21:
    return
    label 63:
    if (P_GiveWeapon(player, 5u, 0u) == 0) {
        goto label 22
    }
    let c2da_fresh68 : uint = 360048u
    c2da_mem[player + 232] = uint8(c2da_fresh68)
    c2da_mem[player + 233] = uint8(c2da_fresh68 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh68 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh68 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    sound = 33
    goto label 26
    label 22:
    return
    label 64:
    if (P_GiveWeapon(player, 2u, uint((int(uint(c2da_mem[special + 160]) | uint(c2da_mem[special + 161]) << 0x8 | uint(c2da_mem[special + 162]) << 0x10 | uint(c2da_mem[special + 163]) << 0x18) & 131072) != 0 ? 1 : 0)) == 0) {
        goto label 23
    }
    let c2da_fresh69 : uint = 360072u
    c2da_mem[player + 232] = uint8(c2da_fresh69)
    c2da_mem[player + 233] = uint8(c2da_fresh69 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh69 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh69 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    sound = 33
    goto label 26
    label 23:
    return
    label 65:
    if (P_GiveWeapon(player, 8u, uint((int(uint(c2da_mem[special + 160]) | uint(c2da_mem[special + 161]) << 0x8 | uint(c2da_mem[special + 162]) << 0x10 | uint(c2da_mem[special + 163]) << 0x18) & 131072) != 0 ? 1 : 0)) == 0) {
        goto label 24
    }
    let c2da_fresh70 : uint = 360093u
    c2da_mem[player + 232] = uint8(c2da_fresh70)
    c2da_mem[player + 233] = uint8(c2da_fresh70 >> 0x8)
    c2da_mem[player + 234] = uint8(c2da_fresh70 >> 0x10)
    c2da_mem[player + 235] = uint8(c2da_fresh70 >> 0x18)
    c2da_mem[player + 236] = 0u8
    c2da_mem[player + 237] = 0u8
    c2da_mem[player + 238] = 0u8
    c2da_mem[player + 239] = 0u8
    sound = 33
    goto label 26
    label 24:
    return
    label 25:
    label 29:
    label 30:
    label 31:
    I_Error(360120, [])
    label 26:
    if ((int(uint(c2da_mem[special + 160]) | uint(c2da_mem[special + 161]) << 0x8 | uint(c2da_mem[special + 162]) << 0x10 | uint(c2da_mem[special + 163]) << 0x18) & 8388608) != 0) {
        let c2da_fresh71 : int = int(uint(c2da_mem[player + 220]) | uint(c2da_mem[player + 221]) << 0x8 | uint(c2da_mem[player + 222]) << 0x10 | uint(c2da_mem[player + 223]) << 0x18)
        let c2da_fresh72 : int = c2da_fresh71 + 1
        let c2da_fresh73 : uint = uint(c2da_fresh72)
        c2da_mem[player + 220] = uint8(c2da_fresh73)
        c2da_mem[player + 221] = uint8(c2da_fresh73 >> 0x8)
        c2da_mem[player + 222] = uint8(c2da_fresh73 >> 0x10)
        c2da_mem[player + 223] = uint8(c2da_fresh73 >> 0x18)
    }
    P_RemoveMobj(special)
    let c2da_fresh74 : int = int(uint(c2da_mem[player + 244]) | uint(c2da_mem[player + 245]) << 0x8 | uint(c2da_mem[player + 246]) << 0x10 | uint(c2da_mem[player + 247]) << 0x18) + 6
    let c2da_fresh75 : uint = uint(c2da_fresh74)
    c2da_mem[player + 244] = uint8(c2da_fresh75)
    c2da_mem[player + 245] = uint8(c2da_fresh75 >> 0x8)
    c2da_mem[player + 246] = uint8(c2da_fresh75 >> 0x10)
    c2da_mem[player + 247] = uint8(c2da_fresh75 >> 0x18)
    if (player == 96 + int(consoleplayer) * 328) {
        S_StartSound(0, sound)
    }
    return
}
[export, sideeffects]
def P_GiveWeapon(var player_0 : int; var weapon : uint; var dropped : uint) : uint {
    var gaveammo : uint
    var gaveweapon : uint
    if (netgame != 0x0 && deathmatch != 2 && dropped == 0) {
        if ((uint(c2da_mem[player_0 + 132 + int(weapon) * 4]) | uint(c2da_mem[player_0 + 132 + int(weapon) * 4 + 1]) << 0x8 | uint(c2da_mem[player_0 + 132 + int(weapon) * 4 + 2]) << 0x10 | uint(c2da_mem[player_0 + 132 + int(weapon) * 4 + 3]) << 0x18) != 0x0) {
            return 0u
        }
        let c2da_fresh76 : int = int(uint(c2da_mem[player_0 + 244]) | uint(c2da_mem[player_0 + 245]) << 0x8 | uint(c2da_mem[player_0 + 246]) << 0x10 | uint(c2da_mem[player_0 + 247]) << 0x18) + 6
        let c2da_fresh77 : uint = uint(c2da_fresh76)
        c2da_mem[player_0 + 244] = uint8(c2da_fresh77)
        c2da_mem[player_0 + 245] = uint8(c2da_fresh77 >> 0x8)
        c2da_mem[player_0 + 246] = uint8(c2da_fresh77 >> 0x10)
        c2da_mem[player_0 + 247] = uint8(c2da_fresh77 >> 0x18)
        let c2da_fresh78 : uint = 1u
        let c2da_fresh79 : uint = c2da_fresh78
        c2da_mem[player_0 + 132 + int(weapon) * 4] = uint8(c2da_fresh79)
        c2da_mem[player_0 + 132 + int(weapon) * 4 + 1] = uint8(c2da_fresh79 >> 0x8)
        c2da_mem[player_0 + 132 + int(weapon) * 4 + 2] = uint8(c2da_fresh79 >> 0x10)
        c2da_mem[player_0 + 132 + int(weapon) * 4 + 3] = uint8(c2da_fresh79 >> 0x18)
        if (deathmatch != 0) {
            P_GiveAmmo(player_0, weaponinfo[int(weapon)].ammo, 5)
        } else {
            P_GiveAmmo(player_0, weaponinfo[int(weapon)].ammo, 2)
        }
        let c2da_fresh80 : uint = weapon
        c2da_mem[player_0 + 128] = uint8(c2da_fresh80)
        c2da_mem[player_0 + 129] = uint8(c2da_fresh80 >> 0x8)
        c2da_mem[player_0 + 130] = uint8(c2da_fresh80 >> 0x10)
        c2da_mem[player_0 + 131] = uint8(c2da_fresh80 >> 0x18)
        if (player_0 == 96 + int(consoleplayer) * 328) {
            S_StartSound(0, 33)
        }
        return 0u
    }
    if (uint(weaponinfo[int(weapon)].ammo) != 5u) {
        if (dropped != 0x0) {
            gaveammo = uint(P_GiveAmmo(player_0, weaponinfo[int(weapon)].ammo, 1))
        } else {
            gaveammo = uint(P_GiveAmmo(player_0, weaponinfo[int(weapon)].ammo, 2))
        }
    } else {
        gaveammo = 0u
    }
    if ((uint(c2da_mem[player_0 + 132 + int(weapon) * 4]) | uint(c2da_mem[player_0 + 132 + int(weapon) * 4 + 1]) << 0x8 | uint(c2da_mem[player_0 + 132 + int(weapon) * 4 + 2]) << 0x10 | uint(c2da_mem[player_0 + 132 + int(weapon) * 4 + 3]) << 0x18) != 0x0) {
        gaveweapon = 0u
    } else {
        gaveweapon = 1u
        let c2da_fresh81 : uint = 1u
        let c2da_fresh82 : uint = c2da_fresh81
        c2da_mem[player_0 + 132 + int(weapon) * 4] = uint8(c2da_fresh82)
        c2da_mem[player_0 + 132 + int(weapon) * 4 + 1] = uint8(c2da_fresh82 >> 0x8)
        c2da_mem[player_0 + 132 + int(weapon) * 4 + 2] = uint8(c2da_fresh82 >> 0x10)
        c2da_mem[player_0 + 132 + int(weapon) * 4 + 3] = uint8(c2da_fresh82 >> 0x18)
        let c2da_fresh83 : uint = weapon
        c2da_mem[player_0 + 128] = uint8(c2da_fresh83)
        c2da_mem[player_0 + 129] = uint8(c2da_fresh83 >> 0x8)
        c2da_mem[player_0 + 130] = uint8(c2da_fresh83 >> 0x10)
        c2da_mem[player_0 + 131] = uint8(c2da_fresh83 >> 0x18)
    }
    return uint(gaveweapon != 0x0 || gaveammo != 0x0 ? 1 : 0)
}
[export, sideeffects]
def P_GiveAmmo(var player_1 : int; var ammo : uint; var num : int) : uint {
    var c2da_fresh88 : uint
    var oldammo : int
    if (ammo == 5u) {
        return 0u
    }
    if (ammo > 4u) {
        I_Error(360159, [C2daVaArg(tag = 1, i64 = int64(ammo), f64 = 0.0lf, raw = 0x0)])
    }
    if (int(uint(c2da_mem[player_1 + 168 + int(ammo) * 4]) | uint(c2da_mem[player_1 + 168 + int(ammo) * 4 + 1]) << 0x8 | uint(c2da_mem[player_1 + 168 + int(ammo) * 4 + 2]) << 0x10 | uint(c2da_mem[player_1 + 168 + int(ammo) * 4 + 3]) << 0x18) == int(uint(c2da_mem[player_1 + 184 + int(ammo) * 4]) | uint(c2da_mem[player_1 + 184 + int(ammo) * 4 + 1]) << 0x8 | uint(c2da_mem[player_1 + 184 + int(ammo) * 4 + 2]) << 0x10 | uint(c2da_mem[player_1 + 184 + int(ammo) * 4 + 3]) << 0x18)) {
        return 0u
    }
    if (num != 0) {
        num *= clipammo[int(ammo)]
    } else {
        num = clipammo[int(ammo)] / 2
    }
    if (int(gameskill) == 0 || int(gameskill) == 4) {
        num <<= 1
    }
    oldammo = int(uint(c2da_mem[player_1 + 168 + int(ammo) * 4]) | uint(c2da_mem[player_1 + 168 + int(ammo) * 4 + 1]) << 0x8 | uint(c2da_mem[player_1 + 168 + int(ammo) * 4 + 2]) << 0x10 | uint(c2da_mem[player_1 + 168 + int(ammo) * 4 + 3]) << 0x18)
    let c2da_fresh84 : int = int(uint(c2da_mem[player_1 + 168 + int(ammo) * 4]) | uint(c2da_mem[player_1 + 168 + int(ammo) * 4 + 1]) << 0x8 | uint(c2da_mem[player_1 + 168 + int(ammo) * 4 + 2]) << 0x10 | uint(c2da_mem[player_1 + 168 + int(ammo) * 4 + 3]) << 0x18) + num
    let c2da_fresh85 : uint = uint(c2da_fresh84)
    c2da_mem[player_1 + 168 + int(ammo) * 4] = uint8(c2da_fresh85)
    c2da_mem[player_1 + 168 + int(ammo) * 4 + 1] = uint8(c2da_fresh85 >> 0x8)
    c2da_mem[player_1 + 168 + int(ammo) * 4 + 2] = uint8(c2da_fresh85 >> 0x10)
    c2da_mem[player_1 + 168 + int(ammo) * 4 + 3] = uint8(c2da_fresh85 >> 0x18)
    if (int(uint(c2da_mem[player_1 + 168 + int(ammo) * 4]) | uint(c2da_mem[player_1 + 168 + int(ammo) * 4 + 1]) << 0x8 | uint(c2da_mem[player_1 + 168 + int(ammo) * 4 + 2]) << 0x10 | uint(c2da_mem[player_1 + 168 + int(ammo) * 4 + 3]) << 0x18) > int(uint(c2da_mem[player_1 + 184 + int(ammo) * 4]) | uint(c2da_mem[player_1 + 184 + int(ammo) * 4 + 1]) << 0x8 | uint(c2da_mem[player_1 + 184 + int(ammo) * 4 + 2]) << 0x10 | uint(c2da_mem[player_1 + 184 + int(ammo) * 4 + 3]) << 0x18)) {
        let c2da_fresh86 : int = int(uint(c2da_mem[player_1 + 184 + int(ammo) * 4]) | uint(c2da_mem[player_1 + 184 + int(ammo) * 4 + 1]) << 0x8 | uint(c2da_mem[player_1 + 184 + int(ammo) * 4 + 2]) << 0x10 | uint(c2da_mem[player_1 + 184 + int(ammo) * 4 + 3]) << 0x18)
        let c2da_fresh87 : uint = uint(c2da_fresh86)
        c2da_mem[player_1 + 168 + int(ammo) * 4] = uint8(c2da_fresh87)
        c2da_mem[player_1 + 168 + int(ammo) * 4 + 1] = uint8(c2da_fresh87 >> 0x8)
        c2da_mem[player_1 + 168 + int(ammo) * 4 + 2] = uint8(c2da_fresh87 >> 0x10)
        c2da_mem[player_1 + 168 + int(ammo) * 4 + 3] = uint8(c2da_fresh87 >> 0x18)
    }
    if (oldammo != 0) {
        return 1u
    }
    c2da_fresh88 = ammo
    if (c2da_fresh88 == 0x0u) {
        goto label 0
    } elif (c2da_fresh88 == 0x1u) {
        goto label 1
    } elif (c2da_fresh88 == 0x2u) {
        goto label 2
    } elif (c2da_fresh88 == 0x3u) {
        goto label 3
    } else {
        goto label 4
    }
    label 0:
    if ((uint(c2da_mem[player_1 + 124]) | uint(c2da_mem[player_1 + 125]) << 0x8 | uint(c2da_mem[player_1 + 126]) << 0x10 | uint(c2da_mem[player_1 + 127]) << 0x18) == 0u) {
        if ((uint(c2da_mem[player_1 + 132 + 3 * 4]) | uint(c2da_mem[player_1 + 132 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[player_1 + 132 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[player_1 + 132 + 3 * 4 + 3]) << 0x18) != 0x0) {
            let c2da_fresh89 : uint = 3u
            let c2da_fresh90 : uint = c2da_fresh89
            c2da_mem[player_1 + 128] = uint8(c2da_fresh90)
            c2da_mem[player_1 + 129] = uint8(c2da_fresh90 >> 0x8)
            c2da_mem[player_1 + 130] = uint8(c2da_fresh90 >> 0x10)
            c2da_mem[player_1 + 131] = uint8(c2da_fresh90 >> 0x18)
        } else {
            let c2da_fresh91 : uint = 1u
            let c2da_fresh92 : uint = c2da_fresh91
            c2da_mem[player_1 + 128] = uint8(c2da_fresh92)
            c2da_mem[player_1 + 129] = uint8(c2da_fresh92 >> 0x8)
            c2da_mem[player_1 + 130] = uint8(c2da_fresh92 >> 0x10)
            c2da_mem[player_1 + 131] = uint8(c2da_fresh92 >> 0x18)
        }
    }
    goto label 5
    label 1:
    if ((uint(c2da_mem[player_1 + 124]) | uint(c2da_mem[player_1 + 125]) << 0x8 | uint(c2da_mem[player_1 + 126]) << 0x10 | uint(c2da_mem[player_1 + 127]) << 0x18) == 0u || (uint(c2da_mem[player_1 + 124]) | uint(c2da_mem[player_1 + 125]) << 0x8 | uint(c2da_mem[player_1 + 126]) << 0x10 | uint(c2da_mem[player_1 + 127]) << 0x18) == 1u) {
        if ((uint(c2da_mem[player_1 + 132 + 2 * 4]) | uint(c2da_mem[player_1 + 132 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[player_1 + 132 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[player_1 + 132 + 2 * 4 + 3]) << 0x18) != 0x0) {
            let c2da_fresh93 : uint = 2u
            let c2da_fresh94 : uint = c2da_fresh93
            c2da_mem[player_1 + 128] = uint8(c2da_fresh94)
            c2da_mem[player_1 + 129] = uint8(c2da_fresh94 >> 0x8)
            c2da_mem[player_1 + 130] = uint8(c2da_fresh94 >> 0x10)
            c2da_mem[player_1 + 131] = uint8(c2da_fresh94 >> 0x18)
        }
    }
    goto label 5
    label 2:
    if ((uint(c2da_mem[player_1 + 124]) | uint(c2da_mem[player_1 + 125]) << 0x8 | uint(c2da_mem[player_1 + 126]) << 0x10 | uint(c2da_mem[player_1 + 127]) << 0x18) == 0u || (uint(c2da_mem[player_1 + 124]) | uint(c2da_mem[player_1 + 125]) << 0x8 | uint(c2da_mem[player_1 + 126]) << 0x10 | uint(c2da_mem[player_1 + 127]) << 0x18) == 1u) {
        if ((uint(c2da_mem[player_1 + 132 + 5 * 4]) | uint(c2da_mem[player_1 + 132 + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[player_1 + 132 + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[player_1 + 132 + 5 * 4 + 3]) << 0x18) != 0x0) {
            let c2da_fresh95 : uint = 5u
            let c2da_fresh96 : uint = c2da_fresh95
            c2da_mem[player_1 + 128] = uint8(c2da_fresh96)
            c2da_mem[player_1 + 129] = uint8(c2da_fresh96 >> 0x8)
            c2da_mem[player_1 + 130] = uint8(c2da_fresh96 >> 0x10)
            c2da_mem[player_1 + 131] = uint8(c2da_fresh96 >> 0x18)
        }
    }
    goto label 5
    label 3:
    if ((uint(c2da_mem[player_1 + 124]) | uint(c2da_mem[player_1 + 125]) << 0x8 | uint(c2da_mem[player_1 + 126]) << 0x10 | uint(c2da_mem[player_1 + 127]) << 0x18) == 0u) {
        if ((uint(c2da_mem[player_1 + 132 + 4 * 4]) | uint(c2da_mem[player_1 + 132 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[player_1 + 132 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[player_1 + 132 + 4 * 4 + 3]) << 0x18) != 0x0) {
            let c2da_fresh97 : uint = 4u
            let c2da_fresh98 : uint = c2da_fresh97
            c2da_mem[player_1 + 128] = uint8(c2da_fresh98)
            c2da_mem[player_1 + 129] = uint8(c2da_fresh98 >> 0x8)
            c2da_mem[player_1 + 130] = uint8(c2da_fresh98 >> 0x10)
            c2da_mem[player_1 + 131] = uint8(c2da_fresh98 >> 0x18)
        }
    }
    label 4:
    label 5:
    return 1u
}
[export, sideeffects]
def P_GivePower(var player_2 : int; var power : int) : uint {
    if (power == 0) {
        let c2da_fresh99 : int = 1050
        let c2da_fresh100 : uint = uint(c2da_fresh99)
        c2da_mem[player_2 + 56 + power * 4] = uint8(c2da_fresh100)
        c2da_mem[player_2 + 56 + power * 4 + 1] = uint8(c2da_fresh100 >> 0x8)
        c2da_mem[player_2 + 56 + power * 4 + 2] = uint8(c2da_fresh100 >> 0x10)
        c2da_mem[player_2 + 56 + power * 4 + 3] = uint8(c2da_fresh100 >> 0x18)
        return 1u
    }
    if (power == 2) {
        let c2da_fresh101 : int = 2100
        let c2da_fresh102 : uint = uint(c2da_fresh101)
        c2da_mem[player_2 + 56 + power * 4] = uint8(c2da_fresh102)
        c2da_mem[player_2 + 56 + power * 4 + 1] = uint8(c2da_fresh102 >> 0x8)
        c2da_mem[player_2 + 56 + power * 4 + 2] = uint8(c2da_fresh102 >> 0x10)
        c2da_mem[player_2 + 56 + power * 4 + 3] = uint8(c2da_fresh102 >> 0x18)
        let c2da_fresh103 : int = int(uint(c2da_mem[player_2]) | uint(c2da_mem[player_2 + 1]) << 0x8 | uint(c2da_mem[player_2 + 2]) << 0x10 | uint(c2da_mem[player_2 + 3]) << 0x18) + 160
        let c2da_fresh104 : int = int(uint(c2da_mem[c2da_fresh103]) | uint(c2da_mem[c2da_fresh103 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh103 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh103 + 3]) << 0x18) | 262144
        let c2da_fresh105 : uint = uint(c2da_fresh104)
        c2da_mem[c2da_fresh103] = uint8(c2da_fresh105)
        c2da_mem[c2da_fresh103 + 1] = uint8(c2da_fresh105 >> 0x8)
        c2da_mem[c2da_fresh103 + 2] = uint8(c2da_fresh105 >> 0x10)
        c2da_mem[c2da_fresh103 + 3] = uint8(c2da_fresh105 >> 0x18)
        return 1u
    }
    if (power == 5) {
        let c2da_fresh106 : int = 4200
        let c2da_fresh107 : uint = uint(c2da_fresh106)
        c2da_mem[player_2 + 56 + power * 4] = uint8(c2da_fresh107)
        c2da_mem[player_2 + 56 + power * 4 + 1] = uint8(c2da_fresh107 >> 0x8)
        c2da_mem[player_2 + 56 + power * 4 + 2] = uint8(c2da_fresh107 >> 0x10)
        c2da_mem[player_2 + 56 + power * 4 + 3] = uint8(c2da_fresh107 >> 0x18)
        return 1u
    }
    if (power == 3) {
        let c2da_fresh108 : int = 2100
        let c2da_fresh109 : uint = uint(c2da_fresh108)
        c2da_mem[player_2 + 56 + power * 4] = uint8(c2da_fresh109)
        c2da_mem[player_2 + 56 + power * 4 + 1] = uint8(c2da_fresh109 >> 0x8)
        c2da_mem[player_2 + 56 + power * 4 + 2] = uint8(c2da_fresh109 >> 0x10)
        c2da_mem[player_2 + 56 + power * 4 + 3] = uint8(c2da_fresh109 >> 0x18)
        return 1u
    }
    if (power == 1) {
        P_GiveBody(player_2, 100)
        let c2da_fresh110 : int = 1
        let c2da_fresh111 : uint = uint(c2da_fresh110)
        c2da_mem[player_2 + 56 + power * 4] = uint8(c2da_fresh111)
        c2da_mem[player_2 + 56 + power * 4 + 1] = uint8(c2da_fresh111 >> 0x8)
        c2da_mem[player_2 + 56 + power * 4 + 2] = uint8(c2da_fresh111 >> 0x10)
        c2da_mem[player_2 + 56 + power * 4 + 3] = uint8(c2da_fresh111 >> 0x18)
        return 1u
    }
    if (int(uint(c2da_mem[player_2 + 56 + power * 4]) | uint(c2da_mem[player_2 + 56 + power * 4 + 1]) << 0x8 | uint(c2da_mem[player_2 + 56 + power * 4 + 2]) << 0x10 | uint(c2da_mem[player_2 + 56 + power * 4 + 3]) << 0x18) != 0) {
        return 0u
    }
    let c2da_fresh112 : int = 1
    let c2da_fresh113 : uint = uint(c2da_fresh112)
    c2da_mem[player_2 + 56 + power * 4] = uint8(c2da_fresh113)
    c2da_mem[player_2 + 56 + power * 4 + 1] = uint8(c2da_fresh113 >> 0x8)
    c2da_mem[player_2 + 56 + power * 4 + 2] = uint8(c2da_fresh113 >> 0x10)
    c2da_mem[player_2 + 56 + power * 4 + 3] = uint8(c2da_fresh113 >> 0x18)
    return 1u
}
[export, sideeffects]
def P_GiveBody(var player_3 : int; var num_0 : int) : uint {
    if (int(uint(c2da_mem[player_3 + 44]) | uint(c2da_mem[player_3 + 45]) << 0x8 | uint(c2da_mem[player_3 + 46]) << 0x10 | uint(c2da_mem[player_3 + 47]) << 0x18) >= 100) {
        return 0u
    }
    let c2da_fresh114 : int = int(uint(c2da_mem[player_3 + 44]) | uint(c2da_mem[player_3 + 45]) << 0x8 | uint(c2da_mem[player_3 + 46]) << 0x10 | uint(c2da_mem[player_3 + 47]) << 0x18) + num_0
    let c2da_fresh115 : uint = uint(c2da_fresh114)
    c2da_mem[player_3 + 44] = uint8(c2da_fresh115)
    c2da_mem[player_3 + 45] = uint8(c2da_fresh115 >> 0x8)
    c2da_mem[player_3 + 46] = uint8(c2da_fresh115 >> 0x10)
    c2da_mem[player_3 + 47] = uint8(c2da_fresh115 >> 0x18)
    if (int(uint(c2da_mem[player_3 + 44]) | uint(c2da_mem[player_3 + 45]) << 0x8 | uint(c2da_mem[player_3 + 46]) << 0x10 | uint(c2da_mem[player_3 + 47]) << 0x18) > 100) {
        let c2da_fresh116 : int = 100
        let c2da_fresh117 : uint = uint(c2da_fresh116)
        c2da_mem[player_3 + 44] = uint8(c2da_fresh117)
        c2da_mem[player_3 + 45] = uint8(c2da_fresh117 >> 0x8)
        c2da_mem[player_3 + 46] = uint8(c2da_fresh117 >> 0x10)
        c2da_mem[player_3 + 47] = uint8(c2da_fresh117 >> 0x18)
    }
    let c2da_fresh118 : int = int(uint(c2da_mem[player_3]) | uint(c2da_mem[player_3 + 1]) << 0x8 | uint(c2da_mem[player_3 + 2]) << 0x10 | uint(c2da_mem[player_3 + 3]) << 0x18) + 164
    let c2da_fresh119 : int = int(uint(c2da_mem[player_3 + 44]) | uint(c2da_mem[player_3 + 45]) << 0x8 | uint(c2da_mem[player_3 + 46]) << 0x10 | uint(c2da_mem[player_3 + 47]) << 0x18)
    let c2da_fresh120 : uint = uint(c2da_fresh119)
    c2da_mem[c2da_fresh118] = uint8(c2da_fresh120)
    c2da_mem[c2da_fresh118 + 1] = uint8(c2da_fresh120 >> 0x8)
    c2da_mem[c2da_fresh118 + 2] = uint8(c2da_fresh120 >> 0x10)
    c2da_mem[c2da_fresh118 + 3] = uint8(c2da_fresh120 >> 0x18)
    return 1u
}
[export, sideeffects]
def P_GiveCard(var player_4 : int; var card : uint) {
    if ((uint(c2da_mem[player_4 + 80 + int(card) * 4]) | uint(c2da_mem[player_4 + 80 + int(card) * 4 + 1]) << 0x8 | uint(c2da_mem[player_4 + 80 + int(card) * 4 + 2]) << 0x10 | uint(c2da_mem[player_4 + 80 + int(card) * 4 + 3]) << 0x18) != 0x0) {
        return
    }
    let c2da_fresh121 : int = 6
    let c2da_fresh122 : uint = uint(c2da_fresh121)
    c2da_mem[player_4 + 244] = uint8(c2da_fresh122)
    c2da_mem[player_4 + 245] = uint8(c2da_fresh122 >> 0x8)
    c2da_mem[player_4 + 246] = uint8(c2da_fresh122 >> 0x10)
    c2da_mem[player_4 + 247] = uint8(c2da_fresh122 >> 0x18)
    let c2da_fresh123 : uint = 1u
    let c2da_fresh124 : uint = c2da_fresh123
    c2da_mem[player_4 + 80 + int(card) * 4] = uint8(c2da_fresh124)
    c2da_mem[player_4 + 80 + int(card) * 4 + 1] = uint8(c2da_fresh124 >> 0x8)
    c2da_mem[player_4 + 80 + int(card) * 4 + 2] = uint8(c2da_fresh124 >> 0x10)
    c2da_mem[player_4 + 80 + int(card) * 4 + 3] = uint8(c2da_fresh124 >> 0x18)
    return
}
[export, sideeffects]
def P_GiveArmor(var player_5 : int; var armortype : int) : uint {
    var hits : int = armortype * 100
    if (int(uint(c2da_mem[player_5 + 48]) | uint(c2da_mem[player_5 + 49]) << 0x8 | uint(c2da_mem[player_5 + 50]) << 0x10 | uint(c2da_mem[player_5 + 51]) << 0x18) >= hits) {
        return 0u
    }
    let c2da_fresh125 : uint = uint(armortype)
    c2da_mem[player_5 + 52] = uint8(c2da_fresh125)
    c2da_mem[player_5 + 53] = uint8(c2da_fresh125 >> 0x8)
    c2da_mem[player_5 + 54] = uint8(c2da_fresh125 >> 0x10)
    c2da_mem[player_5 + 55] = uint8(c2da_fresh125 >> 0x18)
    let c2da_fresh126 : uint = uint(hits)
    c2da_mem[player_5 + 48] = uint8(c2da_fresh126)
    c2da_mem[player_5 + 49] = uint8(c2da_fresh126 >> 0x8)
    c2da_mem[player_5 + 50] = uint8(c2da_fresh126 >> 0x10)
    c2da_mem[player_5 + 51] = uint8(c2da_fresh126 >> 0x18)
    return 1u
}
[export, sideeffects]
def P_DamageMobj(var target : int; var inflictor : int; var source : int; var damage : int) {
    var ang : uint
    var saved : int
    var player_6 : int
    var thrust : int
    var temp : int
    if ((int(uint(c2da_mem[target + 160]) | uint(c2da_mem[target + 161]) << 0x8 | uint(c2da_mem[target + 162]) << 0x10 | uint(c2da_mem[target + 163]) << 0x18) & 4) == 0) {
        return
    }
    if (int(uint(c2da_mem[target + 164]) | uint(c2da_mem[target + 165]) << 0x8 | uint(c2da_mem[target + 166]) << 0x10 | uint(c2da_mem[target + 167]) << 0x18) <= 0) {
        return
    }
    if ((int(uint(c2da_mem[target + 160]) | uint(c2da_mem[target + 161]) << 0x8 | uint(c2da_mem[target + 162]) << 0x10 | uint(c2da_mem[target + 163]) << 0x18) & 16777216) != 0) {
        let c2da_fresh127 : int = 0
        let c2da_fresh128 : uint = uint(c2da_fresh127)
        c2da_mem[target + 120] = uint8(c2da_fresh128)
        c2da_mem[target + 121] = uint8(c2da_fresh128 >> 0x8)
        c2da_mem[target + 122] = uint8(c2da_fresh128 >> 0x10)
        c2da_mem[target + 123] = uint8(c2da_fresh128 >> 0x18)
        let c2da_fresh129 : uint = uint(c2da_fresh127)
        c2da_mem[target + 116] = uint8(c2da_fresh129)
        c2da_mem[target + 117] = uint8(c2da_fresh129 >> 0x8)
        c2da_mem[target + 118] = uint8(c2da_fresh129 >> 0x10)
        c2da_mem[target + 119] = uint8(c2da_fresh129 >> 0x18)
        let c2da_fresh130 : uint = uint(c2da_fresh127)
        c2da_mem[target + 112] = uint8(c2da_fresh130)
        c2da_mem[target + 113] = uint8(c2da_fresh130 >> 0x8)
        c2da_mem[target + 114] = uint8(c2da_fresh130 >> 0x10)
        c2da_mem[target + 115] = uint8(c2da_fresh130 >> 0x18)
    }
    player_6 = int(uint(c2da_mem[target + 192]) | uint(c2da_mem[target + 193]) << 0x8 | uint(c2da_mem[target + 194]) << 0x10 | uint(c2da_mem[target + 195]) << 0x18)
    if (player_6 != 0 && int(gameskill) == 0) {
        damage >>= 1
    }
    var c2da_fresh133 : int = 0
    if (inflictor != 0 && (int(uint(c2da_mem[target + 160]) | uint(c2da_mem[target + 161]) << 0x8 | uint(c2da_mem[target + 162]) << 0x10 | uint(c2da_mem[target + 163]) << 0x18) & 4096) == 0) {
        var c2da_fresh132 : int = 1
        if (!(source == 0 || int(uint(c2da_mem[source + 192]) | uint(c2da_mem[source + 193]) << 0x8 | uint(c2da_mem[source + 194]) << 0x10 | uint(c2da_mem[source + 195]) << 0x18) == 0)) {
            let c2da_fresh131 : int = int(uint(c2da_mem[source + 192]) | uint(c2da_mem[source + 193]) << 0x8 | uint(c2da_mem[source + 194]) << 0x10 | uint(c2da_mem[source + 195]) << 0x18) + 124
            if (!((uint(c2da_mem[c2da_fresh131]) | uint(c2da_mem[c2da_fresh131 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh131 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh131 + 3]) << 0x18) != 7u)) {
                c2da_fresh132 = 0
            }
        }
        if (c2da_fresh132 != 0) {
            c2da_fresh133 = 1
        }
    }
    if (c2da_fresh133 != 0) {
        ang = uint(R_PointToAngle2(int(uint(c2da_mem[inflictor + 24]) | uint(c2da_mem[inflictor + 25]) << 0x8 | uint(c2da_mem[inflictor + 26]) << 0x10 | uint(c2da_mem[inflictor + 27]) << 0x18), int(uint(c2da_mem[inflictor + 28]) | uint(c2da_mem[inflictor + 29]) << 0x8 | uint(c2da_mem[inflictor + 30]) << 0x10 | uint(c2da_mem[inflictor + 31]) << 0x18), int(uint(c2da_mem[target + 24]) | uint(c2da_mem[target + 25]) << 0x8 | uint(c2da_mem[target + 26]) << 0x10 | uint(c2da_mem[target + 27]) << 0x18), int(uint(c2da_mem[target + 28]) | uint(c2da_mem[target + 29]) << 0x8 | uint(c2da_mem[target + 30]) << 0x10 | uint(c2da_mem[target + 31]) << 0x18)))
        let c2da_fresh134 : int = int(uint(c2da_mem[target + 136]) | uint(c2da_mem[target + 137]) << 0x8 | uint(c2da_mem[target + 138]) << 0x10 | uint(c2da_mem[target + 139]) << 0x18) + 72
        thrust = damage * (1 << 16 >> 3) * 100 / int(uint(c2da_mem[c2da_fresh134]) | uint(c2da_mem[c2da_fresh134 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh134 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh134 + 3]) << 0x18)
        if (damage < 40 && damage > int(uint(c2da_mem[target + 164]) | uint(c2da_mem[target + 165]) << 0x8 | uint(c2da_mem[target + 166]) << 0x10 | uint(c2da_mem[target + 167]) << 0x18) && int(uint(c2da_mem[target + 32]) | uint(c2da_mem[target + 33]) << 0x8 | uint(c2da_mem[target + 34]) << 0x10 | uint(c2da_mem[target + 35]) << 0x18) - int(uint(c2da_mem[inflictor + 32]) | uint(c2da_mem[inflictor + 33]) << 0x8 | uint(c2da_mem[inflictor + 34]) << 0x10 | uint(c2da_mem[inflictor + 35]) << 0x18) > 64 * (1 << 16) && (P_Random() & 1) != 0) {
            ang += 0x80000000u
            thrust *= 4
        }
        ang >>= 19u
        let c2da_fresh135 : int = int(uint(c2da_mem[target + 112]) | uint(c2da_mem[target + 113]) << 0x8 | uint(c2da_mem[target + 114]) << 0x10 | uint(c2da_mem[target + 115]) << 0x18) + int(FixedMul(thrust, int(uint(c2da_mem[finecosine + int(ang) * 4]) | uint(c2da_mem[finecosine + int(ang) * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + int(ang) * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + int(ang) * 4 + 3]) << 0x18)))
        let c2da_fresh136 : uint = uint(c2da_fresh135)
        c2da_mem[target + 112] = uint8(c2da_fresh136)
        c2da_mem[target + 113] = uint8(c2da_fresh136 >> 0x8)
        c2da_mem[target + 114] = uint8(c2da_fresh136 >> 0x10)
        c2da_mem[target + 115] = uint8(c2da_fresh136 >> 0x18)
        let c2da_fresh137 : int = int(uint(c2da_mem[target + 116]) | uint(c2da_mem[target + 117]) << 0x8 | uint(c2da_mem[target + 118]) << 0x10 | uint(c2da_mem[target + 119]) << 0x18) + int(FixedMul(thrust, int(uint(c2da_mem[257920 + int(ang) * 4]) | uint(c2da_mem[257920 + int(ang) * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + int(ang) * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + int(ang) * 4 + 3]) << 0x18)))
        let c2da_fresh138 : uint = uint(c2da_fresh137)
        c2da_mem[target + 116] = uint8(c2da_fresh138)
        c2da_mem[target + 117] = uint8(c2da_fresh138 >> 0x8)
        c2da_mem[target + 118] = uint8(c2da_fresh138 >> 0x10)
        c2da_mem[target + 119] = uint8(c2da_fresh138 >> 0x18)
    }
    if (player_6 != 0) {
        let c2da_fresh139 : int = int(uint(c2da_mem[target + 88]) | uint(c2da_mem[target + 89]) << 0x8 | uint(c2da_mem[target + 90]) << 0x10 | uint(c2da_mem[target + 91]) << 0x18)
        let c2da_fresh140 : int = int(uint(c2da_mem[c2da_fresh139]) | uint(c2da_mem[c2da_fresh139 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh139 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh139 + 3]) << 0x18) + 14
        if (int(int16(uint(c2da_mem[c2da_fresh140]) | uint(c2da_mem[c2da_fresh140 + 1]) << 0x8)) == 11 && damage >= int(uint(c2da_mem[target + 164]) | uint(c2da_mem[target + 165]) << 0x8 | uint(c2da_mem[target + 166]) << 0x10 | uint(c2da_mem[target + 167]) << 0x18)) {
            damage = int(uint(c2da_mem[target + 164]) | uint(c2da_mem[target + 165]) << 0x8 | uint(c2da_mem[target + 166]) << 0x10 | uint(c2da_mem[target + 167]) << 0x18) - 1
        }
        if (damage < 1000 && ((int(uint(c2da_mem[player_6 + 208]) | uint(c2da_mem[player_6 + 209]) << 0x8 | uint(c2da_mem[player_6 + 210]) << 0x10 | uint(c2da_mem[player_6 + 211]) << 0x18) & 2) != 0 || int(uint(c2da_mem[player_6 + 56 + 0 * 4]) | uint(c2da_mem[player_6 + 56 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[player_6 + 56 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[player_6 + 56 + 0 * 4 + 3]) << 0x18) != 0)) {
            return
        }
        if (int(uint(c2da_mem[player_6 + 52]) | uint(c2da_mem[player_6 + 53]) << 0x8 | uint(c2da_mem[player_6 + 54]) << 0x10 | uint(c2da_mem[player_6 + 55]) << 0x18) != 0) {
            if (int(uint(c2da_mem[player_6 + 52]) | uint(c2da_mem[player_6 + 53]) << 0x8 | uint(c2da_mem[player_6 + 54]) << 0x10 | uint(c2da_mem[player_6 + 55]) << 0x18) == 1) {
                saved = damage / 3
            } else {
                saved = damage / 2
            }
            if (int(uint(c2da_mem[player_6 + 48]) | uint(c2da_mem[player_6 + 49]) << 0x8 | uint(c2da_mem[player_6 + 50]) << 0x10 | uint(c2da_mem[player_6 + 51]) << 0x18) <= saved) {
                saved = int(uint(c2da_mem[player_6 + 48]) | uint(c2da_mem[player_6 + 49]) << 0x8 | uint(c2da_mem[player_6 + 50]) << 0x10 | uint(c2da_mem[player_6 + 51]) << 0x18)
                let c2da_fresh141 : int = 0
                let c2da_fresh142 : uint = uint(c2da_fresh141)
                c2da_mem[player_6 + 52] = uint8(c2da_fresh142)
                c2da_mem[player_6 + 53] = uint8(c2da_fresh142 >> 0x8)
                c2da_mem[player_6 + 54] = uint8(c2da_fresh142 >> 0x10)
                c2da_mem[player_6 + 55] = uint8(c2da_fresh142 >> 0x18)
            }
            let c2da_fresh143 : int = int(uint(c2da_mem[player_6 + 48]) | uint(c2da_mem[player_6 + 49]) << 0x8 | uint(c2da_mem[player_6 + 50]) << 0x10 | uint(c2da_mem[player_6 + 51]) << 0x18) - saved
            let c2da_fresh144 : uint = uint(c2da_fresh143)
            c2da_mem[player_6 + 48] = uint8(c2da_fresh144)
            c2da_mem[player_6 + 49] = uint8(c2da_fresh144 >> 0x8)
            c2da_mem[player_6 + 50] = uint8(c2da_fresh144 >> 0x10)
            c2da_mem[player_6 + 51] = uint8(c2da_fresh144 >> 0x18)
            damage -= saved
        }
        let c2da_fresh145 : int = int(uint(c2da_mem[player_6 + 44]) | uint(c2da_mem[player_6 + 45]) << 0x8 | uint(c2da_mem[player_6 + 46]) << 0x10 | uint(c2da_mem[player_6 + 47]) << 0x18) - damage
        let c2da_fresh146 : uint = uint(c2da_fresh145)
        c2da_mem[player_6 + 44] = uint8(c2da_fresh146)
        c2da_mem[player_6 + 45] = uint8(c2da_fresh146 >> 0x8)
        c2da_mem[player_6 + 46] = uint8(c2da_fresh146 >> 0x10)
        c2da_mem[player_6 + 47] = uint8(c2da_fresh146 >> 0x18)
        if (int(uint(c2da_mem[player_6 + 44]) | uint(c2da_mem[player_6 + 45]) << 0x8 | uint(c2da_mem[player_6 + 46]) << 0x10 | uint(c2da_mem[player_6 + 47]) << 0x18) < 0) {
            let c2da_fresh147 : int = 0
            let c2da_fresh148 : uint = uint(c2da_fresh147)
            c2da_mem[player_6 + 44] = uint8(c2da_fresh148)
            c2da_mem[player_6 + 45] = uint8(c2da_fresh148 >> 0x8)
            c2da_mem[player_6 + 46] = uint8(c2da_fresh148 >> 0x10)
            c2da_mem[player_6 + 47] = uint8(c2da_fresh148 >> 0x18)
        }
        let c2da_fresh149 : uint = uint(source)
        c2da_mem[player_6 + 248] = uint8(c2da_fresh149)
        c2da_mem[player_6 + 249] = uint8(c2da_fresh149 >> 0x8)
        c2da_mem[player_6 + 250] = uint8(c2da_fresh149 >> 0x10)
        c2da_mem[player_6 + 251] = uint8(c2da_fresh149 >> 0x18)
        c2da_mem[player_6 + 252] = 0u8
        c2da_mem[player_6 + 253] = 0u8
        c2da_mem[player_6 + 254] = 0u8
        c2da_mem[player_6 + 255] = 0u8
        let c2da_fresh150 : int = int(uint(c2da_mem[player_6 + 240]) | uint(c2da_mem[player_6 + 241]) << 0x8 | uint(c2da_mem[player_6 + 242]) << 0x10 | uint(c2da_mem[player_6 + 243]) << 0x18) + damage
        let c2da_fresh151 : uint = uint(c2da_fresh150)
        c2da_mem[player_6 + 240] = uint8(c2da_fresh151)
        c2da_mem[player_6 + 241] = uint8(c2da_fresh151 >> 0x8)
        c2da_mem[player_6 + 242] = uint8(c2da_fresh151 >> 0x10)
        c2da_mem[player_6 + 243] = uint8(c2da_fresh151 >> 0x18)
        if (int(uint(c2da_mem[player_6 + 240]) | uint(c2da_mem[player_6 + 241]) << 0x8 | uint(c2da_mem[player_6 + 242]) << 0x10 | uint(c2da_mem[player_6 + 243]) << 0x18) > 100) {
            let c2da_fresh152 : int = 100
            let c2da_fresh153 : uint = uint(c2da_fresh152)
            c2da_mem[player_6 + 240] = uint8(c2da_fresh153)
            c2da_mem[player_6 + 241] = uint8(c2da_fresh153 >> 0x8)
            c2da_mem[player_6 + 242] = uint8(c2da_fresh153 >> 0x10)
            c2da_mem[player_6 + 243] = uint8(c2da_fresh153 >> 0x18)
        }
        temp = damage < 100 ? damage : 100
        if (player_6 == 96 + int(consoleplayer) * 328) {
            I_Tactile(40, 10, 40 + temp * 2)
        }
    }
    let c2da_fresh154 : int = int(uint(c2da_mem[target + 164]) | uint(c2da_mem[target + 165]) << 0x8 | uint(c2da_mem[target + 166]) << 0x10 | uint(c2da_mem[target + 167]) << 0x18) - damage
    let c2da_fresh155 : uint = uint(c2da_fresh154)
    c2da_mem[target + 164] = uint8(c2da_fresh155)
    c2da_mem[target + 165] = uint8(c2da_fresh155 >> 0x8)
    c2da_mem[target + 166] = uint8(c2da_fresh155 >> 0x10)
    c2da_mem[target + 167] = uint8(c2da_fresh155 >> 0x18)
    if (int(uint(c2da_mem[target + 164]) | uint(c2da_mem[target + 165]) << 0x8 | uint(c2da_mem[target + 166]) << 0x10 | uint(c2da_mem[target + 167]) << 0x18) <= 0) {
        P_KillMobj(source, target)
        return
    }
    let c2da_fresh156 : int = int(uint(c2da_mem[target + 136]) | uint(c2da_mem[target + 137]) << 0x8 | uint(c2da_mem[target + 138]) << 0x10 | uint(c2da_mem[target + 139]) << 0x18) + 32
    if (P_Random() < int(uint(c2da_mem[c2da_fresh156]) | uint(c2da_mem[c2da_fresh156 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh156 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh156 + 3]) << 0x18) && (int(uint(c2da_mem[target + 160]) | uint(c2da_mem[target + 161]) << 0x8 | uint(c2da_mem[target + 162]) << 0x10 | uint(c2da_mem[target + 163]) << 0x18) & 16777216) == 0) {
        let c2da_fresh157 : int = int(uint(c2da_mem[target + 160]) | uint(c2da_mem[target + 161]) << 0x8 | uint(c2da_mem[target + 162]) << 0x10 | uint(c2da_mem[target + 163]) << 0x18) | 64
        let c2da_fresh158 : uint = uint(c2da_fresh157)
        c2da_mem[target + 160] = uint8(c2da_fresh158)
        c2da_mem[target + 161] = uint8(c2da_fresh158 >> 0x8)
        c2da_mem[target + 162] = uint8(c2da_fresh158 >> 0x10)
        c2da_mem[target + 163] = uint8(c2da_fresh158 >> 0x18)
        let c2da_fresh159 : int = int(uint(c2da_mem[target + 136]) | uint(c2da_mem[target + 137]) << 0x8 | uint(c2da_mem[target + 138]) << 0x10 | uint(c2da_mem[target + 139]) << 0x18) + 28
        P_SetMobjState(target, uint(int(uint(c2da_mem[c2da_fresh159]) | uint(c2da_mem[c2da_fresh159 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh159 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh159 + 3]) << 0x18)))
    }
    let c2da_fresh160 : int = 0
    let c2da_fresh161 : uint = uint(c2da_fresh160)
    c2da_mem[target + 184] = uint8(c2da_fresh161)
    c2da_mem[target + 185] = uint8(c2da_fresh161 >> 0x8)
    c2da_mem[target + 186] = uint8(c2da_fresh161 >> 0x10)
    c2da_mem[target + 187] = uint8(c2da_fresh161 >> 0x18)
    if ((int(uint(c2da_mem[target + 188]) | uint(c2da_mem[target + 189]) << 0x8 | uint(c2da_mem[target + 190]) << 0x10 | uint(c2da_mem[target + 191]) << 0x18) == 0 || (uint(c2da_mem[target + 128]) | uint(c2da_mem[target + 129]) << 0x8 | uint(c2da_mem[target + 130]) << 0x10 | uint(c2da_mem[target + 131]) << 0x18) == 3u) && source != 0 && source != target && (uint(c2da_mem[source + 128]) | uint(c2da_mem[source + 129]) << 0x8 | uint(c2da_mem[source + 130]) << 0x10 | uint(c2da_mem[source + 131]) << 0x18) != 3u) {
        let c2da_fresh162 : uint = uint(source)
        c2da_mem[target + 176] = uint8(c2da_fresh162)
        c2da_mem[target + 177] = uint8(c2da_fresh162 >> 0x8)
        c2da_mem[target + 178] = uint8(c2da_fresh162 >> 0x10)
        c2da_mem[target + 179] = uint8(c2da_fresh162 >> 0x18)
        c2da_mem[target + 180] = 0u8
        c2da_mem[target + 181] = 0u8
        c2da_mem[target + 182] = 0u8
        c2da_mem[target + 183] = 0u8
        let c2da_fresh163 : int = 100
        let c2da_fresh164 : uint = uint(c2da_fresh163)
        c2da_mem[target + 188] = uint8(c2da_fresh164)
        c2da_mem[target + 189] = uint8(c2da_fresh164 >> 0x8)
        c2da_mem[target + 190] = uint8(c2da_fresh164 >> 0x10)
        c2da_mem[target + 191] = uint8(c2da_fresh164 >> 0x18)
        let c2da_fresh165 : int = int(uint(c2da_mem[target + 136]) | uint(c2da_mem[target + 137]) << 0x8 | uint(c2da_mem[target + 138]) << 0x10 | uint(c2da_mem[target + 139]) << 0x18) + 4
        var c2da_fresh167 : int = 0
        if (int(uint(c2da_mem[target + 152]) | uint(c2da_mem[target + 153]) << 0x8 | uint(c2da_mem[target + 154]) << 0x10 | uint(c2da_mem[target + 155]) << 0x18) == 2080 + int(uint(c2da_mem[c2da_fresh165]) | uint(c2da_mem[c2da_fresh165 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh165 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh165 + 3]) << 0x18) * 40) {
            let c2da_fresh166 : int = int(uint(c2da_mem[target + 136]) | uint(c2da_mem[target + 137]) << 0x8 | uint(c2da_mem[target + 138]) << 0x10 | uint(c2da_mem[target + 139]) << 0x18) + 12
            if (int(uint(c2da_mem[c2da_fresh166]) | uint(c2da_mem[c2da_fresh166 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh166 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh166 + 3]) << 0x18) != 0) {
                c2da_fresh167 = 1
            }
        }
        if (c2da_fresh167 != 0) {
            let c2da_fresh168 : int = int(uint(c2da_mem[target + 136]) | uint(c2da_mem[target + 137]) << 0x8 | uint(c2da_mem[target + 138]) << 0x10 | uint(c2da_mem[target + 139]) << 0x18) + 12
            P_SetMobjState(target, uint(int(uint(c2da_mem[c2da_fresh168]) | uint(c2da_mem[c2da_fresh168 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh168 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh168 + 3]) << 0x18)))
        }
    }
    return
}
[export, sideeffects]
def P_KillMobj(var source_0 : int; var target_0 : int) {
    var c2da_fresh206 : uint
    var item : uint
    var mo : int
    let c2da_fresh169 : int = int(uint(c2da_mem[target_0 + 160]) | uint(c2da_mem[target_0 + 161]) << 0x8 | uint(c2da_mem[target_0 + 162]) << 0x10 | uint(c2da_mem[target_0 + 163]) << 0x18) & ~(4 | 16384 | 16777216)
    let c2da_fresh170 : uint = uint(c2da_fresh169)
    c2da_mem[target_0 + 160] = uint8(c2da_fresh170)
    c2da_mem[target_0 + 161] = uint8(c2da_fresh170 >> 0x8)
    c2da_mem[target_0 + 162] = uint8(c2da_fresh170 >> 0x10)
    c2da_mem[target_0 + 163] = uint8(c2da_fresh170 >> 0x18)
    if ((uint(c2da_mem[target_0 + 128]) | uint(c2da_mem[target_0 + 129]) << 0x8 | uint(c2da_mem[target_0 + 130]) << 0x10 | uint(c2da_mem[target_0 + 131]) << 0x18) != 18u) {
        let c2da_fresh171 : int = int(uint(c2da_mem[target_0 + 160]) | uint(c2da_mem[target_0 + 161]) << 0x8 | uint(c2da_mem[target_0 + 162]) << 0x10 | uint(c2da_mem[target_0 + 163]) << 0x18) & ~512
        let c2da_fresh172 : uint = uint(c2da_fresh171)
        c2da_mem[target_0 + 160] = uint8(c2da_fresh172)
        c2da_mem[target_0 + 161] = uint8(c2da_fresh172 >> 0x8)
        c2da_mem[target_0 + 162] = uint8(c2da_fresh172 >> 0x10)
        c2da_mem[target_0 + 163] = uint8(c2da_fresh172 >> 0x18)
    }
    let c2da_fresh173 : int = int(uint(c2da_mem[target_0 + 160]) | uint(c2da_mem[target_0 + 161]) << 0x8 | uint(c2da_mem[target_0 + 162]) << 0x10 | uint(c2da_mem[target_0 + 163]) << 0x18) | (1048576 | 1024)
    let c2da_fresh174 : uint = uint(c2da_fresh173)
    c2da_mem[target_0 + 160] = uint8(c2da_fresh174)
    c2da_mem[target_0 + 161] = uint8(c2da_fresh174 >> 0x8)
    c2da_mem[target_0 + 162] = uint8(c2da_fresh174 >> 0x10)
    c2da_mem[target_0 + 163] = uint8(c2da_fresh174 >> 0x18)
    let c2da_fresh175 : int = int(uint(c2da_mem[target_0 + 108]) | uint(c2da_mem[target_0 + 109]) << 0x8 | uint(c2da_mem[target_0 + 110]) << 0x10 | uint(c2da_mem[target_0 + 111]) << 0x18) >> 2
    let c2da_fresh176 : uint = uint(c2da_fresh175)
    c2da_mem[target_0 + 108] = uint8(c2da_fresh176)
    c2da_mem[target_0 + 109] = uint8(c2da_fresh176 >> 0x8)
    c2da_mem[target_0 + 110] = uint8(c2da_fresh176 >> 0x10)
    c2da_mem[target_0 + 111] = uint8(c2da_fresh176 >> 0x18)
    if (source_0 != 0 && int(uint(c2da_mem[source_0 + 192]) | uint(c2da_mem[source_0 + 193]) << 0x8 | uint(c2da_mem[source_0 + 194]) << 0x10 | uint(c2da_mem[source_0 + 195]) << 0x18) != 0) {
        if ((int(uint(c2da_mem[target_0 + 160]) | uint(c2da_mem[target_0 + 161]) << 0x8 | uint(c2da_mem[target_0 + 162]) << 0x10 | uint(c2da_mem[target_0 + 163]) << 0x18) & 4194304) != 0) {
            let c2da_fresh177 : int = int(uint(c2da_mem[source_0 + 192]) | uint(c2da_mem[source_0 + 193]) << 0x8 | uint(c2da_mem[source_0 + 194]) << 0x10 | uint(c2da_mem[source_0 + 195]) << 0x18) + 216
            let c2da_fresh178 : int = int(uint(c2da_mem[c2da_fresh177]) | uint(c2da_mem[c2da_fresh177 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh177 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh177 + 3]) << 0x18)
            let c2da_fresh179 : int = c2da_fresh178 + 1
            let c2da_fresh180 : uint = uint(c2da_fresh179)
            c2da_mem[c2da_fresh177] = uint8(c2da_fresh180)
            c2da_mem[c2da_fresh177 + 1] = uint8(c2da_fresh180 >> 0x8)
            c2da_mem[c2da_fresh177 + 2] = uint8(c2da_fresh180 >> 0x10)
            c2da_mem[c2da_fresh177 + 3] = uint8(c2da_fresh180 >> 0x18)
        }
        if (int(uint(c2da_mem[target_0 + 192]) | uint(c2da_mem[target_0 + 193]) << 0x8 | uint(c2da_mem[target_0 + 194]) << 0x10 | uint(c2da_mem[target_0 + 195]) << 0x18) != 0) {
            let c2da_fresh181 : int = int(uint(c2da_mem[source_0 + 192]) | uint(c2da_mem[source_0 + 193]) << 0x8 | uint(c2da_mem[source_0 + 194]) << 0x10 | uint(c2da_mem[source_0 + 195]) << 0x18) + 108 + (int(uint(c2da_mem[target_0 + 192]) | uint(c2da_mem[target_0 + 193]) << 0x8 | uint(c2da_mem[target_0 + 194]) << 0x10 | uint(c2da_mem[target_0 + 195]) << 0x18) - 96) / 328 * 4
            let c2da_fresh182 : int = int(uint(c2da_mem[c2da_fresh181]) | uint(c2da_mem[c2da_fresh181 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh181 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh181 + 3]) << 0x18)
            let c2da_fresh183 : int = c2da_fresh182 + 1
            let c2da_fresh184 : uint = uint(c2da_fresh183)
            c2da_mem[c2da_fresh181] = uint8(c2da_fresh184)
            c2da_mem[c2da_fresh181 + 1] = uint8(c2da_fresh184 >> 0x8)
            c2da_mem[c2da_fresh181 + 2] = uint8(c2da_fresh184 >> 0x10)
            c2da_mem[c2da_fresh181 + 3] = uint8(c2da_fresh184 >> 0x18)
        }
    } elif (netgame == 0 && (int(uint(c2da_mem[target_0 + 160]) | uint(c2da_mem[target_0 + 161]) << 0x8 | uint(c2da_mem[target_0 + 162]) << 0x10 | uint(c2da_mem[target_0 + 163]) << 0x18) & 4194304) != 0) {
        let c2da_fresh185 : int = int(uint(c2da_mem[96 + 0 * 328 + 216]) | uint(c2da_mem[96 + 0 * 328 + 217]) << 0x8 | uint(c2da_mem[96 + 0 * 328 + 218]) << 0x10 | uint(c2da_mem[96 + 0 * 328 + 219]) << 0x18)
        let c2da_fresh186 : int = c2da_fresh185 + 1
        let c2da_fresh187 : uint = uint(c2da_fresh186)
        c2da_mem[96 + 0 * 328 + 216] = uint8(c2da_fresh187)
        c2da_mem[96 + 0 * 328 + 217] = uint8(c2da_fresh187 >> 0x8)
        c2da_mem[96 + 0 * 328 + 218] = uint8(c2da_fresh187 >> 0x10)
        c2da_mem[96 + 0 * 328 + 219] = uint8(c2da_fresh187 >> 0x18)
    }
    if (int(uint(c2da_mem[target_0 + 192]) | uint(c2da_mem[target_0 + 193]) << 0x8 | uint(c2da_mem[target_0 + 194]) << 0x10 | uint(c2da_mem[target_0 + 195]) << 0x18) != 0) {
        if (source_0 == 0) {
            let c2da_fresh188 : int = int(uint(c2da_mem[target_0 + 192]) | uint(c2da_mem[target_0 + 193]) << 0x8 | uint(c2da_mem[target_0 + 194]) << 0x10 | uint(c2da_mem[target_0 + 195]) << 0x18) + 108 + (int(uint(c2da_mem[target_0 + 192]) | uint(c2da_mem[target_0 + 193]) << 0x8 | uint(c2da_mem[target_0 + 194]) << 0x10 | uint(c2da_mem[target_0 + 195]) << 0x18) - 96) / 328 * 4
            let c2da_fresh189 : int = int(uint(c2da_mem[c2da_fresh188]) | uint(c2da_mem[c2da_fresh188 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh188 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh188 + 3]) << 0x18)
            let c2da_fresh190 : int = c2da_fresh189 + 1
            let c2da_fresh191 : uint = uint(c2da_fresh190)
            c2da_mem[c2da_fresh188] = uint8(c2da_fresh191)
            c2da_mem[c2da_fresh188 + 1] = uint8(c2da_fresh191 >> 0x8)
            c2da_mem[c2da_fresh188 + 2] = uint8(c2da_fresh191 >> 0x10)
            c2da_mem[c2da_fresh188 + 3] = uint8(c2da_fresh191 >> 0x18)
        }
        let c2da_fresh192 : int = int(uint(c2da_mem[target_0 + 160]) | uint(c2da_mem[target_0 + 161]) << 0x8 | uint(c2da_mem[target_0 + 162]) << 0x10 | uint(c2da_mem[target_0 + 163]) << 0x18) & ~2
        let c2da_fresh193 : uint = uint(c2da_fresh192)
        c2da_mem[target_0 + 160] = uint8(c2da_fresh193)
        c2da_mem[target_0 + 161] = uint8(c2da_fresh193 >> 0x8)
        c2da_mem[target_0 + 162] = uint8(c2da_fresh193 >> 0x10)
        c2da_mem[target_0 + 163] = uint8(c2da_fresh193 >> 0x18)
        let c2da_fresh194 : int = int(uint(c2da_mem[target_0 + 192]) | uint(c2da_mem[target_0 + 193]) << 0x8 | uint(c2da_mem[target_0 + 194]) << 0x10 | uint(c2da_mem[target_0 + 195]) << 0x18) + 8
        let c2da_fresh195 : uint = 1u
        let c2da_fresh196 : uint = c2da_fresh195
        c2da_mem[c2da_fresh194] = uint8(c2da_fresh196)
        c2da_mem[c2da_fresh194 + 1] = uint8(c2da_fresh196 >> 0x8)
        c2da_mem[c2da_fresh194 + 2] = uint8(c2da_fresh196 >> 0x10)
        c2da_mem[c2da_fresh194 + 3] = uint8(c2da_fresh196 >> 0x18)
        P_DropWeapon(int(uint(c2da_mem[target_0 + 192]) | uint(c2da_mem[target_0 + 193]) << 0x8 | uint(c2da_mem[target_0 + 194]) << 0x10 | uint(c2da_mem[target_0 + 195]) << 0x18))
        if (int(uint(c2da_mem[target_0 + 192]) | uint(c2da_mem[target_0 + 193]) << 0x8 | uint(c2da_mem[target_0 + 194]) << 0x10 | uint(c2da_mem[target_0 + 195]) << 0x18) == 96 + int(consoleplayer) * 328 && automapactive != 0x0) {
            AM_Stop()
        }
    }
    let c2da_fresh197 : int = int(uint(c2da_mem[target_0 + 136]) | uint(c2da_mem[target_0 + 137]) << 0x8 | uint(c2da_mem[target_0 + 138]) << 0x10 | uint(c2da_mem[target_0 + 139]) << 0x18) + 8
    var c2da_fresh199 : int = 0
    if (int(uint(c2da_mem[target_0 + 164]) | uint(c2da_mem[target_0 + 165]) << 0x8 | uint(c2da_mem[target_0 + 166]) << 0x10 | uint(c2da_mem[target_0 + 167]) << 0x18) < -int(uint(c2da_mem[c2da_fresh197]) | uint(c2da_mem[c2da_fresh197 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh197 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh197 + 3]) << 0x18)) {
        let c2da_fresh198 : int = int(uint(c2da_mem[target_0 + 136]) | uint(c2da_mem[target_0 + 137]) << 0x8 | uint(c2da_mem[target_0 + 138]) << 0x10 | uint(c2da_mem[target_0 + 139]) << 0x18) + 52
        if (int(uint(c2da_mem[c2da_fresh198]) | uint(c2da_mem[c2da_fresh198 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh198 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh198 + 3]) << 0x18) != 0) {
            c2da_fresh199 = 1
        }
    }
    if (c2da_fresh199 != 0) {
        let c2da_fresh200 : int = int(uint(c2da_mem[target_0 + 136]) | uint(c2da_mem[target_0 + 137]) << 0x8 | uint(c2da_mem[target_0 + 138]) << 0x10 | uint(c2da_mem[target_0 + 139]) << 0x18) + 52
        P_SetMobjState(target_0, uint(int(uint(c2da_mem[c2da_fresh200]) | uint(c2da_mem[c2da_fresh200 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh200 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh200 + 3]) << 0x18)))
    } else {
        let c2da_fresh201 : int = int(uint(c2da_mem[target_0 + 136]) | uint(c2da_mem[target_0 + 137]) << 0x8 | uint(c2da_mem[target_0 + 138]) << 0x10 | uint(c2da_mem[target_0 + 139]) << 0x18) + 48
        P_SetMobjState(target_0, uint(int(uint(c2da_mem[c2da_fresh201]) | uint(c2da_mem[c2da_fresh201 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh201 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh201 + 3]) << 0x18)))
    }
    let c2da_fresh202 : int = int(uint(c2da_mem[target_0 + 144]) | uint(c2da_mem[target_0 + 145]) << 0x8 | uint(c2da_mem[target_0 + 146]) << 0x10 | uint(c2da_mem[target_0 + 147]) << 0x18) - int(P_Random() & 3)
    let c2da_fresh203 : uint = uint(c2da_fresh202)
    c2da_mem[target_0 + 144] = uint8(c2da_fresh203)
    c2da_mem[target_0 + 145] = uint8(c2da_fresh203 >> 0x8)
    c2da_mem[target_0 + 146] = uint8(c2da_fresh203 >> 0x10)
    c2da_mem[target_0 + 147] = uint8(c2da_fresh203 >> 0x18)
    if (int(uint(c2da_mem[target_0 + 144]) | uint(c2da_mem[target_0 + 145]) << 0x8 | uint(c2da_mem[target_0 + 146]) << 0x10 | uint(c2da_mem[target_0 + 147]) << 0x18) < 1) {
        let c2da_fresh204 : int = 1
        let c2da_fresh205 : uint = uint(c2da_fresh204)
        c2da_mem[target_0 + 144] = uint8(c2da_fresh205)
        c2da_mem[target_0 + 145] = uint8(c2da_fresh205 >> 0x8)
        c2da_mem[target_0 + 146] = uint8(c2da_fresh205 >> 0x10)
        c2da_mem[target_0 + 147] = uint8(c2da_fresh205 >> 0x18)
    }
    if (uint(gameversion) == 9u) {
        return
    }
    c2da_fresh206 = uint(c2da_mem[target_0 + 128]) | uint(c2da_mem[target_0 + 129]) << 0x8 | uint(c2da_mem[target_0 + 130]) << 0x10 | uint(c2da_mem[target_0 + 131]) << 0x18
    if (c2da_fresh206 == 0x17u || c2da_fresh206 == 0x1u) {
        item = 63u
    } elif (c2da_fresh206 == 0x2u) {
        item = 77u
    } elif (c2da_fresh206 == 0xau) {
        item = 73u
    } else {
        return
    }
    mo = P_SpawnMobj(int(uint(c2da_mem[target_0 + 24]) | uint(c2da_mem[target_0 + 25]) << 0x8 | uint(c2da_mem[target_0 + 26]) << 0x10 | uint(c2da_mem[target_0 + 27]) << 0x18), int(uint(c2da_mem[target_0 + 28]) | uint(c2da_mem[target_0 + 29]) << 0x8 | uint(c2da_mem[target_0 + 30]) << 0x10 | uint(c2da_mem[target_0 + 31]) << 0x18), -2147483647 - 1, item)
    let c2da_fresh207 : int = int(uint(c2da_mem[mo + 160]) | uint(c2da_mem[mo + 161]) << 0x8 | uint(c2da_mem[mo + 162]) << 0x10 | uint(c2da_mem[mo + 163]) << 0x18) | 131072
    let c2da_fresh208 : uint = uint(c2da_fresh207)
    c2da_mem[mo + 160] = uint8(c2da_fresh208)
    c2da_mem[mo + 161] = uint8(c2da_fresh208 >> 0x8)
    c2da_mem[mo + 162] = uint8(c2da_fresh208 >> 0x10)
    c2da_mem[mo + 163] = uint8(c2da_fresh208 >> 0x18)
    return
}

// This unit's static data, at heap offset 359200.
let private c2da_lin_static_p_inter_seg = fixed_array<int>(359200, 982)
let private c2da_lin_static_p_inter = fixed_array<uint64>(0x752064656b636950ul, 0x7261206568742070ul, 0x636950002e726f6dul, 0x742070752064656bul, 0x416167654d206568ul, 0x69500021726f6d72ul, 0x2070752064656b63ul, 0x68746c6165682061ul, 0x2e73756e6f6220ul, 0x752064656b636950ul, 0x6d7261206e612070ul, 0x73756e6f6220726ful, 0x637265707553002eul, 0x4d00216567726168ul, 0x7265687053616765ul, 0x656b636950002165ul, 0x6220612070752064ul, 0x6379656b2065756cul, 0x636950002e647261ul, 0x612070752064656bul, 0x20776f6c6c657920ul, 0x2e6472616379656bul, 0x2064656b63695000ul, 0x6465722061207075ul, 0x6472616379656b20ul, 0x64656b636950002eul, 0x6c62206120707520ul, 0x6c6c756b73206575ul, 0x6950002e79656b20ul, 0x2070752064656b63ul, 0x776f6c6c65792061ul, 0x6b206c6c756b7320ul, 0x6b636950002e7965ul, 0x2061207075206465ul, 0x6c756b7320646572ul, 0x50002e79656b206cul, 0x70752064656b6369ul, 0x706d697473206120ul, 0x636950002e6b6361ul, 0x612070752064656bul, 0x74696b6964656d20ul, 0x6f79207461687420ul, 0x594c4c4145522075ul, 0x5000216465656e20ul, 0x70752064656b6369ul, 0x6b6964656d206120ul, 0x75766e49002e7469ul, 0x6c69626172656e6cul, 0x7265420021797469ul, 0x615000216b726573ul, 0x6e49206c61697472ul, 0x696c696269736976ul, 0x6169646152007974ul, 0x696853206e6f6974ul, 0x5320676e69646c65ul, 0x706d6f4300746975ul, 0x6572412072657475ul, 0x694c0070614d2061ul, 0x6c706d4120746867ul, 0x6f69746163696669ul, 0x726f736956206eul, 0x752064656b636950ul, 0x70696c6320612070ul, 0x64656b636950002eul, 0x6f62206120707520ul, 0x6c756220666f2078ul, 0x6950002e7374656cul, 0x2070752064656b63ul, 0x74656b636f722061ul, 0x64656b636950002eul, 0x6f62206120707520ul, 0x636f7220666f2078ul, 0x6950002e7374656bul, 0x2070752064656b63ul, 0x6772656e65206e61ul, 0x2e6c6c65632079ul, 0x752064656b636950ul, 0x656e65206e612070ul, 0x6c6c656320796772ul, 0x50002e6b63617020ul, 0x70752064656b6369ul, 0x67746f6873203420ul, 0x6c6c656873206e75ul, 0x656b636950002e73ul, 0x6220612070752064ul, 0x687320666f20786ful, 0x6873206e7567746ful, 0x6950002e736c6c65ul, 0x2070752064656b63ul, 0x61706b6361622061ul, 0x206c6c7566206b63ul, 0x216f6d6d6120666ful, 0x746f6720756f5900ul, 0x4746422065687420ul, 0x4f20202130303039ul, 0x2e736579202c68ul, 0x20746f6720756f59ul, 0x6961686320656874ul, 0x204100216e75676eul, 0x7761736e69616863ul, 0x20646e6946202021ul, 0x61656d20656d6f73ul, 0x6720756f59002174ul, 0x722065687420746ful, 0x616c2074656b636ful, 0x21726568636e75ul, 0x20746f6720756f59ul, 0x73616c7020656874ul, 0x216e756720616dul, 0x20746f6720756f59ul, 0x746f687320656874ul, 0x756f5900216e7567ul, 0x65687420746f6720ul, 0x7320726570757320ul, 0x216e7567746f68ul, 0x6169636570535f50ul, 0x203a676e6968546cul, 0x206e776f6e6b6e55ul, 0x656c626174746567ul, 0x5000676e69687420ul, 0x6d6d41657669475ful, 0x7420646162203a6ful, 0x692520657079ul)

[init]
def private c2da_lin_init_static_p_inter() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_p_inter_seg[s * 2]
        for (k in range(c2da_lin_static_p_inter_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_p_inter[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
