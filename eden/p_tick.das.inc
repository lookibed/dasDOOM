[export, sideeffects]
def P_InitThinkers() {
    let c2da_fresh0 : uint = 46544u
    c2da_mem[46552] = uint8(c2da_fresh0)
    c2da_mem[46553] = uint8(c2da_fresh0 >> 0x8)
    c2da_mem[46554] = uint8(c2da_fresh0 >> 0x10)
    c2da_mem[46555] = uint8(c2da_fresh0 >> 0x18)
    c2da_mem[46556] = 0u8
    c2da_mem[46557] = 0u8
    c2da_mem[46558] = 0u8
    c2da_mem[46559] = 0u8
    let c2da_fresh1 : uint = 46544u
    c2da_mem[46544] = uint8(c2da_fresh1)
    c2da_mem[46545] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[46546] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[46547] = uint8(c2da_fresh1 >> 0x18)
    c2da_mem[46548] = 0u8
    c2da_mem[46549] = 0u8
    c2da_mem[46550] = 0u8
    c2da_mem[46551] = 0u8
    return
}
[export, sideeffects]
def P_AddThinker(var thinker : int) {
    let c2da_fresh2 : int = int(uint(c2da_mem[46544]) | uint(c2da_mem[46545]) << 0x8 | uint(c2da_mem[46546]) << 0x10 | uint(c2da_mem[46547]) << 0x18) + 8
    let c2da_fresh3 : uint = uint(thinker)
    c2da_mem[c2da_fresh2] = uint8(c2da_fresh3)
    c2da_mem[c2da_fresh2 + 1] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[c2da_fresh2 + 2] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[c2da_fresh2 + 3] = uint8(c2da_fresh3 >> 0x18)
    c2da_mem[c2da_fresh2 + 4] = 0u8
    c2da_mem[c2da_fresh2 + 5] = 0u8
    c2da_mem[c2da_fresh2 + 6] = 0u8
    c2da_mem[c2da_fresh2 + 7] = 0u8
    let c2da_fresh4 : uint = 46544u
    c2da_mem[thinker + 8] = uint8(c2da_fresh4)
    c2da_mem[thinker + 9] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[thinker + 10] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[thinker + 11] = uint8(c2da_fresh4 >> 0x18)
    c2da_mem[thinker + 12] = 0u8
    c2da_mem[thinker + 13] = 0u8
    c2da_mem[thinker + 14] = 0u8
    c2da_mem[thinker + 15] = 0u8
    let c2da_fresh5 : int = int(uint(c2da_mem[46544]) | uint(c2da_mem[46545]) << 0x8 | uint(c2da_mem[46546]) << 0x10 | uint(c2da_mem[46547]) << 0x18)
    let c2da_fresh6 : uint = uint(c2da_fresh5)
    c2da_mem[thinker] = uint8(c2da_fresh6)
    c2da_mem[thinker + 1] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[thinker + 2] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[thinker + 3] = uint8(c2da_fresh6 >> 0x18)
    c2da_mem[thinker + 4] = 0u8
    c2da_mem[thinker + 5] = 0u8
    c2da_mem[thinker + 6] = 0u8
    c2da_mem[thinker + 7] = 0u8
    let c2da_fresh7 : uint = uint(thinker)
    c2da_mem[46544] = uint8(c2da_fresh7)
    c2da_mem[46545] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[46546] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[46547] = uint8(c2da_fresh7 >> 0x18)
    c2da_mem[46548] = 0u8
    c2da_mem[46549] = 0u8
    c2da_mem[46550] = 0u8
    c2da_mem[46551] = 0u8
    return
}
[export, sideeffects]
def P_RemoveThinker(var thinker_0 : int) {
    let c2da_fresh8 : int = -1
    let c2da_fresh9 : uint = uint(c2da_fresh8)
    c2da_mem[thinker_0 + 16] = uint8(c2da_fresh9)
    c2da_mem[thinker_0 + 17] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[thinker_0 + 18] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[thinker_0 + 19] = uint8(c2da_fresh9 >> 0x18)
    c2da_mem[thinker_0 + 20] = 0u8
    c2da_mem[thinker_0 + 21] = 0u8
    c2da_mem[thinker_0 + 22] = 0u8
    c2da_mem[thinker_0 + 23] = 0u8
    return
}
var leveltime : int = default<int>

[export, sideeffects]
def P_AllocateThinker(var thinker_1 : int) {
    return
}
[export, sideeffects]
def P_RunThinkers() {
    var currentthinker : int = int(uint(c2da_mem[46552]) | uint(c2da_mem[46553]) << 0x8 | uint(c2da_mem[46554]) << 0x10 | uint(c2da_mem[46555]) << 0x18)
    while (currentthinker != 46544) {
        if (int(uint(c2da_mem[currentthinker + 16]) | uint(c2da_mem[currentthinker + 17]) << 0x8 | uint(c2da_mem[currentthinker + 18]) << 0x10 | uint(c2da_mem[currentthinker + 19]) << 0x18) == -1) {
            let c2da_fresh10 : int = int(uint(c2da_mem[currentthinker + 8]) | uint(c2da_mem[currentthinker + 9]) << 0x8 | uint(c2da_mem[currentthinker + 10]) << 0x10 | uint(c2da_mem[currentthinker + 11]) << 0x18)
            let c2da_fresh11 : int = int(uint(c2da_mem[currentthinker]) | uint(c2da_mem[currentthinker + 1]) << 0x8 | uint(c2da_mem[currentthinker + 2]) << 0x10 | uint(c2da_mem[currentthinker + 3]) << 0x18)
            let c2da_fresh12 : uint = uint(c2da_fresh11)
            c2da_mem[c2da_fresh10] = uint8(c2da_fresh12)
            c2da_mem[c2da_fresh10 + 1] = uint8(c2da_fresh12 >> 0x8)
            c2da_mem[c2da_fresh10 + 2] = uint8(c2da_fresh12 >> 0x10)
            c2da_mem[c2da_fresh10 + 3] = uint8(c2da_fresh12 >> 0x18)
            c2da_mem[c2da_fresh10 + 4] = 0u8
            c2da_mem[c2da_fresh10 + 5] = 0u8
            c2da_mem[c2da_fresh10 + 6] = 0u8
            c2da_mem[c2da_fresh10 + 7] = 0u8
            let c2da_fresh13 : int = int(uint(c2da_mem[currentthinker]) | uint(c2da_mem[currentthinker + 1]) << 0x8 | uint(c2da_mem[currentthinker + 2]) << 0x10 | uint(c2da_mem[currentthinker + 3]) << 0x18) + 8
            let c2da_fresh14 : int = int(uint(c2da_mem[currentthinker + 8]) | uint(c2da_mem[currentthinker + 9]) << 0x8 | uint(c2da_mem[currentthinker + 10]) << 0x10 | uint(c2da_mem[currentthinker + 11]) << 0x18)
            let c2da_fresh15 : uint = uint(c2da_fresh14)
            c2da_mem[c2da_fresh13] = uint8(c2da_fresh15)
            c2da_mem[c2da_fresh13 + 1] = uint8(c2da_fresh15 >> 0x8)
            c2da_mem[c2da_fresh13 + 2] = uint8(c2da_fresh15 >> 0x10)
            c2da_mem[c2da_fresh13 + 3] = uint8(c2da_fresh15 >> 0x18)
            c2da_mem[c2da_fresh13 + 4] = 0u8
            c2da_mem[c2da_fresh13 + 5] = 0u8
            c2da_mem[c2da_fresh13 + 6] = 0u8
            c2da_mem[c2da_fresh13 + 7] = 0u8
            Z_Free(currentthinker)
        } elif (int(uint(c2da_mem[currentthinker + 16]) | uint(c2da_mem[currentthinker + 17]) << 0x8 | uint(c2da_mem[currentthinker + 18]) << 0x10 | uint(c2da_mem[currentthinker + 19]) << 0x18) != default<actionf_p1>) {
            invoke(c2da_fn_table5[int(uint(c2da_mem[currentthinker + 16]) | uint(c2da_mem[currentthinker + 17]) << 0x8 | uint(c2da_mem[currentthinker + 18]) << 0x10 | uint(c2da_mem[currentthinker + 19]) << 0x18)], currentthinker)
        }
        currentthinker = int(uint(c2da_mem[currentthinker + 8]) | uint(c2da_mem[currentthinker + 9]) << 0x8 | uint(c2da_mem[currentthinker + 10]) << 0x10 | uint(c2da_mem[currentthinker + 11]) << 0x18)
    }
    return
}
[export, sideeffects]
def P_Ticker() {
    if (paused != 0x0) {
        return
    }
    if (netgame == 0 && menuactive != 0x0 && demoplayback == 0 && int(uint(c2da_mem[96 + int(consoleplayer) * 328 + 28]) | uint(c2da_mem[96 + int(consoleplayer) * 328 + 29]) << 0x8 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 30]) << 0x10 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 31]) << 0x18) != 1) {
        return
    }
    for (i in range(0, 4)) {
        if (playeringame[i] != 0x0) {
            P_PlayerThink(96 + i * 328)
        }
    }
    P_RunThinkers()
    P_UpdateSpecials()
    P_RespawnSpecials()
    leveltime++
    return
}
