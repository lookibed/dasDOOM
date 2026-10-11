[export, sideeffects]
def WI_Ticker() {
    var c2da_fresh0 : int
    bcnt++
    if (bcnt == 1) {
        if (uint(gamemode) == 2u) {
            S_ChangeMusic(67, 1)
        } else {
            S_ChangeMusic(28, 1)
        }
    }
    WI_checkForAccelerate()
    c2da_fresh0 = state
    if (c2da_fresh0 == 0) {
        if (deathmatch != 0) {
            WI_updateDeathmatchStats()
        } elif (netgame != 0x0) {
            WI_updateNetgameStats()
        } else {
            WI_updateStats()
        }
    } elif (c2da_fresh0 == 1) {
        WI_updateShowNextLoc()
    } elif (c2da_fresh0 == -1) {
        WI_updateNoState()
    }
    return
}
[export, sideeffects]
def WI_updateNoState() {
    WI_updateAnimatedBack()
    cnt--
    if (cnt == 0) {
        G_WorldDone()
    }
    return
}
var private cnt : int = default<int>

[export, sideeffects]
def WI_updateAnimatedBack() {
    var c2da_fresh1 : uint
    var i : int
    var a : int
    if (uint(gamemode) == 2u) {
        return
    }
    if (int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18) > 2) {
        return
    }
    i = 0
    while (i < NUMANIMS[int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18)]) {
        a = anims_0[int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18)] + i * 72
        if (bcnt == int(uint(c2da_mem[a + 56]) | uint(c2da_mem[a + 57]) << 0x8 | uint(c2da_mem[a + 58]) << 0x10 | uint(c2da_mem[a + 59]) << 0x18)) {
            c2da_fresh1 = uint(c2da_mem[a]) | uint(c2da_mem[a + 1]) << 0x8 | uint(c2da_mem[a + 2]) << 0x10 | uint(c2da_mem[a + 3]) << 0x18
            if (c2da_fresh1 == 0x0u) {
                let c2da_fresh2 : int = int(uint(c2da_mem[a + 64]) | uint(c2da_mem[a + 65]) << 0x8 | uint(c2da_mem[a + 66]) << 0x10 | uint(c2da_mem[a + 67]) << 0x18)
                let c2da_fresh3 : int = c2da_fresh2 + 1
                let c2da_fresh4 : uint = uint(c2da_fresh3)
                c2da_mem[a + 64] = uint8(c2da_fresh4)
                c2da_mem[a + 65] = uint8(c2da_fresh4 >> 0x8)
                c2da_mem[a + 66] = uint8(c2da_fresh4 >> 0x10)
                c2da_mem[a + 67] = uint8(c2da_fresh4 >> 0x18)
                if (c2da_fresh3 >= int(uint(c2da_mem[a + 8]) | uint(c2da_mem[a + 9]) << 0x8 | uint(c2da_mem[a + 10]) << 0x10 | uint(c2da_mem[a + 11]) << 0x18)) {
                    let c2da_fresh5 : int = 0
                    let c2da_fresh6 : uint = uint(c2da_fresh5)
                    c2da_mem[a + 64] = uint8(c2da_fresh6)
                    c2da_mem[a + 65] = uint8(c2da_fresh6 >> 0x8)
                    c2da_mem[a + 66] = uint8(c2da_fresh6 >> 0x10)
                    c2da_mem[a + 67] = uint8(c2da_fresh6 >> 0x18)
                }
                let c2da_fresh7 : int = bcnt + int(uint(c2da_mem[a + 4]) | uint(c2da_mem[a + 5]) << 0x8 | uint(c2da_mem[a + 6]) << 0x10 | uint(c2da_mem[a + 7]) << 0x18)
                let c2da_fresh8 : uint = uint(c2da_fresh7)
                c2da_mem[a + 56] = uint8(c2da_fresh8)
                c2da_mem[a + 57] = uint8(c2da_fresh8 >> 0x8)
                c2da_mem[a + 58] = uint8(c2da_fresh8 >> 0x10)
                c2da_mem[a + 59] = uint8(c2da_fresh8 >> 0x18)
            } elif (c2da_fresh1 == 0x1u) {
                let c2da_fresh9 : int = int(uint(c2da_mem[a + 64]) | uint(c2da_mem[a + 65]) << 0x8 | uint(c2da_mem[a + 66]) << 0x10 | uint(c2da_mem[a + 67]) << 0x18)
                let c2da_fresh10 : int = c2da_fresh9 + 1
                let c2da_fresh11 : uint = uint(c2da_fresh10)
                c2da_mem[a + 64] = uint8(c2da_fresh11)
                c2da_mem[a + 65] = uint8(c2da_fresh11 >> 0x8)
                c2da_mem[a + 66] = uint8(c2da_fresh11 >> 0x10)
                c2da_mem[a + 67] = uint8(c2da_fresh11 >> 0x18)
                if (int(uint(c2da_mem[a + 64]) | uint(c2da_mem[a + 65]) << 0x8 | uint(c2da_mem[a + 66]) << 0x10 | uint(c2da_mem[a + 67]) << 0x18) == int(uint(c2da_mem[a + 8]) | uint(c2da_mem[a + 9]) << 0x8 | uint(c2da_mem[a + 10]) << 0x10 | uint(c2da_mem[a + 11]) << 0x18)) {
                    let c2da_fresh12 : int = -1
                    let c2da_fresh13 : uint = uint(c2da_fresh12)
                    c2da_mem[a + 64] = uint8(c2da_fresh13)
                    c2da_mem[a + 65] = uint8(c2da_fresh13 >> 0x8)
                    c2da_mem[a + 66] = uint8(c2da_fresh13 >> 0x10)
                    c2da_mem[a + 67] = uint8(c2da_fresh13 >> 0x18)
                    let c2da_fresh14 : int = bcnt + int(uint(c2da_mem[a + 24]) | uint(c2da_mem[a + 25]) << 0x8 | uint(c2da_mem[a + 26]) << 0x10 | uint(c2da_mem[a + 27]) << 0x18) + M_Random() % int(uint(c2da_mem[a + 20]) | uint(c2da_mem[a + 21]) << 0x8 | uint(c2da_mem[a + 22]) << 0x10 | uint(c2da_mem[a + 23]) << 0x18)
                    let c2da_fresh15 : uint = uint(c2da_fresh14)
                    c2da_mem[a + 56] = uint8(c2da_fresh15)
                    c2da_mem[a + 57] = uint8(c2da_fresh15 >> 0x8)
                    c2da_mem[a + 58] = uint8(c2da_fresh15 >> 0x10)
                    c2da_mem[a + 59] = uint8(c2da_fresh15 >> 0x18)
                } else {
                    let c2da_fresh16 : int = bcnt + int(uint(c2da_mem[a + 4]) | uint(c2da_mem[a + 5]) << 0x8 | uint(c2da_mem[a + 6]) << 0x10 | uint(c2da_mem[a + 7]) << 0x18)
                    let c2da_fresh17 : uint = uint(c2da_fresh16)
                    c2da_mem[a + 56] = uint8(c2da_fresh17)
                    c2da_mem[a + 57] = uint8(c2da_fresh17 >> 0x8)
                    c2da_mem[a + 58] = uint8(c2da_fresh17 >> 0x10)
                    c2da_mem[a + 59] = uint8(c2da_fresh17 >> 0x18)
                }
            } elif (c2da_fresh1 == 0x2u) {
                if (!(state == 0 && i == 7) && int(uint(c2da_mem[wbs + 12]) | uint(c2da_mem[wbs + 13]) << 0x8 | uint(c2da_mem[wbs + 14]) << 0x10 | uint(c2da_mem[wbs + 15]) << 0x18) == int(uint(c2da_mem[a + 20]) | uint(c2da_mem[a + 21]) << 0x8 | uint(c2da_mem[a + 22]) << 0x10 | uint(c2da_mem[a + 23]) << 0x18)) {
                    let c2da_fresh18 : int = int(uint(c2da_mem[a + 64]) | uint(c2da_mem[a + 65]) << 0x8 | uint(c2da_mem[a + 66]) << 0x10 | uint(c2da_mem[a + 67]) << 0x18)
                    let c2da_fresh19 : int = c2da_fresh18 + 1
                    let c2da_fresh20 : uint = uint(c2da_fresh19)
                    c2da_mem[a + 64] = uint8(c2da_fresh20)
                    c2da_mem[a + 65] = uint8(c2da_fresh20 >> 0x8)
                    c2da_mem[a + 66] = uint8(c2da_fresh20 >> 0x10)
                    c2da_mem[a + 67] = uint8(c2da_fresh20 >> 0x18)
                    if (int(uint(c2da_mem[a + 64]) | uint(c2da_mem[a + 65]) << 0x8 | uint(c2da_mem[a + 66]) << 0x10 | uint(c2da_mem[a + 67]) << 0x18) == int(uint(c2da_mem[a + 8]) | uint(c2da_mem[a + 9]) << 0x8 | uint(c2da_mem[a + 10]) << 0x10 | uint(c2da_mem[a + 11]) << 0x18)) {
                        let c2da_fresh21 : int = int(uint(c2da_mem[a + 64]) | uint(c2da_mem[a + 65]) << 0x8 | uint(c2da_mem[a + 66]) << 0x10 | uint(c2da_mem[a + 67]) << 0x18)
                        let c2da_fresh22 : int = c2da_fresh21 - 1
                        let c2da_fresh23 : uint = uint(c2da_fresh22)
                        c2da_mem[a + 64] = uint8(c2da_fresh23)
                        c2da_mem[a + 65] = uint8(c2da_fresh23 >> 0x8)
                        c2da_mem[a + 66] = uint8(c2da_fresh23 >> 0x10)
                        c2da_mem[a + 67] = uint8(c2da_fresh23 >> 0x18)
                    }
                    let c2da_fresh24 : int = bcnt + int(uint(c2da_mem[a + 4]) | uint(c2da_mem[a + 5]) << 0x8 | uint(c2da_mem[a + 6]) << 0x10 | uint(c2da_mem[a + 7]) << 0x18)
                    let c2da_fresh25 : uint = uint(c2da_fresh24)
                    c2da_mem[a + 56] = uint8(c2da_fresh25)
                    c2da_mem[a + 57] = uint8(c2da_fresh25 >> 0x8)
                    c2da_mem[a + 58] = uint8(c2da_fresh25 >> 0x10)
                    c2da_mem[a + 59] = uint8(c2da_fresh25 >> 0x18)
                }
            }
        }
        i++
    }
    return
}
var private bcnt : int = default<int>

var private wbs : int = default<int>

var private state : int = default<int>

var private anims_0 : int[4] = fixed_array<int>(374224, 374944, 375600, 0)

var private NUMANIMS : int[4] = fixed_array<int>(int(720ul / 72ul), int(648ul / 72ul), int(432ul / 72ul), 0)

[export, sideeffects]
def WI_updateShowNextLoc() {
    WI_updateAnimatedBack()
    cnt--
    if (cnt == 0 || acceleratestage != 0) {
        WI_initNoState()
    } else {
        snl_pointeron = uint((cnt & 31) < 20 ? 1 : 0)
    }
    return
}
var private snl_pointeron : uint = 0u

[export, sideeffects]
def WI_initNoState() {
    state = -1
    acceleratestage = 0
    cnt = 10
    return
}
var private acceleratestage : int = default<int>

[export, sideeffects]
def WI_updateStats() {
    WI_updateAnimatedBack()
    if (acceleratestage != 0 && sp_state != 10) {
        acceleratestage = 0
        cnt_kills[0] = int(uint(c2da_mem[plrs + me * 40 + 4]) | uint(c2da_mem[plrs + me * 40 + 5]) << 0x8 | uint(c2da_mem[plrs + me * 40 + 6]) << 0x10 | uint(c2da_mem[plrs + me * 40 + 7]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 16]) | uint(c2da_mem[wbs + 17]) << 0x8 | uint(c2da_mem[wbs + 18]) << 0x10 | uint(c2da_mem[wbs + 19]) << 0x18)
        cnt_items[0] = int(uint(c2da_mem[plrs + me * 40 + 8]) | uint(c2da_mem[plrs + me * 40 + 9]) << 0x8 | uint(c2da_mem[plrs + me * 40 + 10]) << 0x10 | uint(c2da_mem[plrs + me * 40 + 11]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 20]) | uint(c2da_mem[wbs + 21]) << 0x8 | uint(c2da_mem[wbs + 22]) << 0x10 | uint(c2da_mem[wbs + 23]) << 0x18)
        cnt_secret[0] = int(uint(c2da_mem[plrs + me * 40 + 12]) | uint(c2da_mem[plrs + me * 40 + 13]) << 0x8 | uint(c2da_mem[plrs + me * 40 + 14]) << 0x10 | uint(c2da_mem[plrs + me * 40 + 15]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 24]) | uint(c2da_mem[wbs + 25]) << 0x8 | uint(c2da_mem[wbs + 26]) << 0x10 | uint(c2da_mem[wbs + 27]) << 0x18)
        cnt_time = int(uint(c2da_mem[plrs + me * 40 + 16]) | uint(c2da_mem[plrs + me * 40 + 17]) << 0x8 | uint(c2da_mem[plrs + me * 40 + 18]) << 0x10 | uint(c2da_mem[plrs + me * 40 + 19]) << 0x18) / 35
        cnt_par = int(uint(c2da_mem[wbs + 32]) | uint(c2da_mem[wbs + 33]) << 0x8 | uint(c2da_mem[wbs + 34]) << 0x10 | uint(c2da_mem[wbs + 35]) << 0x18) / 35
        S_StartSound(0, 82)
        sp_state = 10
    }
    if (sp_state == 2) {
        cnt_kills[0] += 2
        if ((bcnt & 3) == 0) {
            S_StartSound(0, 1)
        }
        if (cnt_kills[0] >= int(uint(c2da_mem[plrs + me * 40 + 4]) | uint(c2da_mem[plrs + me * 40 + 5]) << 0x8 | uint(c2da_mem[plrs + me * 40 + 6]) << 0x10 | uint(c2da_mem[plrs + me * 40 + 7]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 16]) | uint(c2da_mem[wbs + 17]) << 0x8 | uint(c2da_mem[wbs + 18]) << 0x10 | uint(c2da_mem[wbs + 19]) << 0x18)) {
            cnt_kills[0] = int(uint(c2da_mem[plrs + me * 40 + 4]) | uint(c2da_mem[plrs + me * 40 + 5]) << 0x8 | uint(c2da_mem[plrs + me * 40 + 6]) << 0x10 | uint(c2da_mem[plrs + me * 40 + 7]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 16]) | uint(c2da_mem[wbs + 17]) << 0x8 | uint(c2da_mem[wbs + 18]) << 0x10 | uint(c2da_mem[wbs + 19]) << 0x18)
            S_StartSound(0, 82)
            sp_state++
        }
    } elif (sp_state == 4) {
        cnt_items[0] += 2
        if ((bcnt & 3) == 0) {
            S_StartSound(0, 1)
        }
        if (cnt_items[0] >= int(uint(c2da_mem[plrs + me * 40 + 8]) | uint(c2da_mem[plrs + me * 40 + 9]) << 0x8 | uint(c2da_mem[plrs + me * 40 + 10]) << 0x10 | uint(c2da_mem[plrs + me * 40 + 11]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 20]) | uint(c2da_mem[wbs + 21]) << 0x8 | uint(c2da_mem[wbs + 22]) << 0x10 | uint(c2da_mem[wbs + 23]) << 0x18)) {
            cnt_items[0] = int(uint(c2da_mem[plrs + me * 40 + 8]) | uint(c2da_mem[plrs + me * 40 + 9]) << 0x8 | uint(c2da_mem[plrs + me * 40 + 10]) << 0x10 | uint(c2da_mem[plrs + me * 40 + 11]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 20]) | uint(c2da_mem[wbs + 21]) << 0x8 | uint(c2da_mem[wbs + 22]) << 0x10 | uint(c2da_mem[wbs + 23]) << 0x18)
            S_StartSound(0, 82)
            sp_state++
        }
    } elif (sp_state == 6) {
        cnt_secret[0] += 2
        if ((bcnt & 3) == 0) {
            S_StartSound(0, 1)
        }
        if (cnt_secret[0] >= int(uint(c2da_mem[plrs + me * 40 + 12]) | uint(c2da_mem[plrs + me * 40 + 13]) << 0x8 | uint(c2da_mem[plrs + me * 40 + 14]) << 0x10 | uint(c2da_mem[plrs + me * 40 + 15]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 24]) | uint(c2da_mem[wbs + 25]) << 0x8 | uint(c2da_mem[wbs + 26]) << 0x10 | uint(c2da_mem[wbs + 27]) << 0x18)) {
            cnt_secret[0] = int(uint(c2da_mem[plrs + me * 40 + 12]) | uint(c2da_mem[plrs + me * 40 + 13]) << 0x8 | uint(c2da_mem[plrs + me * 40 + 14]) << 0x10 | uint(c2da_mem[plrs + me * 40 + 15]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 24]) | uint(c2da_mem[wbs + 25]) << 0x8 | uint(c2da_mem[wbs + 26]) << 0x10 | uint(c2da_mem[wbs + 27]) << 0x18)
            S_StartSound(0, 82)
            sp_state++
        }
    } elif (sp_state == 8) {
        if ((bcnt & 3) == 0) {
            S_StartSound(0, 1)
        }
        cnt_time += 3
        if (cnt_time >= int(uint(c2da_mem[plrs + me * 40 + 16]) | uint(c2da_mem[plrs + me * 40 + 17]) << 0x8 | uint(c2da_mem[plrs + me * 40 + 18]) << 0x10 | uint(c2da_mem[plrs + me * 40 + 19]) << 0x18) / 35) {
            cnt_time = int(uint(c2da_mem[plrs + me * 40 + 16]) | uint(c2da_mem[plrs + me * 40 + 17]) << 0x8 | uint(c2da_mem[plrs + me * 40 + 18]) << 0x10 | uint(c2da_mem[plrs + me * 40 + 19]) << 0x18) / 35
        }
        cnt_par += 3
        if (cnt_par >= int(uint(c2da_mem[wbs + 32]) | uint(c2da_mem[wbs + 33]) << 0x8 | uint(c2da_mem[wbs + 34]) << 0x10 | uint(c2da_mem[wbs + 35]) << 0x18) / 35) {
            cnt_par = int(uint(c2da_mem[wbs + 32]) | uint(c2da_mem[wbs + 33]) << 0x8 | uint(c2da_mem[wbs + 34]) << 0x10 | uint(c2da_mem[wbs + 35]) << 0x18) / 35
            if (cnt_time >= int(uint(c2da_mem[plrs + me * 40 + 16]) | uint(c2da_mem[plrs + me * 40 + 17]) << 0x8 | uint(c2da_mem[plrs + me * 40 + 18]) << 0x10 | uint(c2da_mem[plrs + me * 40 + 19]) << 0x18) / 35) {
                S_StartSound(0, 82)
                sp_state++
            }
        }
    } elif (sp_state == 10) {
        if (acceleratestage != 0) {
            S_StartSound(0, 3)
            if (uint(gamemode) == 2u) {
                WI_initNoState()
            } else {
                WI_initShowNextLoc()
            }
        }
    } elif ((sp_state & 1) != 0) {
        cnt_pause--
        if (cnt_pause == 0) {
            sp_state++
            cnt_pause = 35
        }
    }
    return
}
var private cnt_pause : int = default<int>

var private sp_state : int = default<int>

[export, sideeffects]
def WI_initShowNextLoc() {
    state = 1
    acceleratestage = 0
    cnt = 4 * 35
    WI_initAnimatedBack()
    return
}
[export, sideeffects]
def WI_initAnimatedBack() {
    var i_0 : int
    var a_0 : int
    if (uint(gamemode) == 2u) {
        return
    }
    if (int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18) > 2) {
        return
    }
    i_0 = 0
    while (i_0 < NUMANIMS[int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18)]) {
        a_0 = anims_0[int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18)] + i_0 * 72
        let c2da_fresh26 : int = -1
        let c2da_fresh27 : uint = uint(c2da_fresh26)
        c2da_mem[a_0 + 64] = uint8(c2da_fresh27)
        c2da_mem[a_0 + 65] = uint8(c2da_fresh27 >> 0x8)
        c2da_mem[a_0 + 66] = uint8(c2da_fresh27 >> 0x10)
        c2da_mem[a_0 + 67] = uint8(c2da_fresh27 >> 0x18)
        if ((uint(c2da_mem[a_0]) | uint(c2da_mem[a_0 + 1]) << 0x8 | uint(c2da_mem[a_0 + 2]) << 0x10 | uint(c2da_mem[a_0 + 3]) << 0x18) == 0u) {
            let c2da_fresh28 : int = bcnt + 1 + M_Random() % int(uint(c2da_mem[a_0 + 4]) | uint(c2da_mem[a_0 + 5]) << 0x8 | uint(c2da_mem[a_0 + 6]) << 0x10 | uint(c2da_mem[a_0 + 7]) << 0x18)
            let c2da_fresh29 : uint = uint(c2da_fresh28)
            c2da_mem[a_0 + 56] = uint8(c2da_fresh29)
            c2da_mem[a_0 + 57] = uint8(c2da_fresh29 >> 0x8)
            c2da_mem[a_0 + 58] = uint8(c2da_fresh29 >> 0x10)
            c2da_mem[a_0 + 59] = uint8(c2da_fresh29 >> 0x18)
        } elif ((uint(c2da_mem[a_0]) | uint(c2da_mem[a_0 + 1]) << 0x8 | uint(c2da_mem[a_0 + 2]) << 0x10 | uint(c2da_mem[a_0 + 3]) << 0x18) == 1u) {
            let c2da_fresh30 : int = bcnt + 1 + int(uint(c2da_mem[a_0 + 24]) | uint(c2da_mem[a_0 + 25]) << 0x8 | uint(c2da_mem[a_0 + 26]) << 0x10 | uint(c2da_mem[a_0 + 27]) << 0x18) + M_Random() % int(uint(c2da_mem[a_0 + 20]) | uint(c2da_mem[a_0 + 21]) << 0x8 | uint(c2da_mem[a_0 + 22]) << 0x10 | uint(c2da_mem[a_0 + 23]) << 0x18)
            let c2da_fresh31 : uint = uint(c2da_fresh30)
            c2da_mem[a_0 + 56] = uint8(c2da_fresh31)
            c2da_mem[a_0 + 57] = uint8(c2da_fresh31 >> 0x8)
            c2da_mem[a_0 + 58] = uint8(c2da_fresh31 >> 0x10)
            c2da_mem[a_0 + 59] = uint8(c2da_fresh31 >> 0x18)
        } elif ((uint(c2da_mem[a_0]) | uint(c2da_mem[a_0 + 1]) << 0x8 | uint(c2da_mem[a_0 + 2]) << 0x10 | uint(c2da_mem[a_0 + 3]) << 0x18) == 2u) {
            let c2da_fresh32 : int = bcnt + 1
            let c2da_fresh33 : uint = uint(c2da_fresh32)
            c2da_mem[a_0 + 56] = uint8(c2da_fresh33)
            c2da_mem[a_0 + 57] = uint8(c2da_fresh33 >> 0x8)
            c2da_mem[a_0 + 58] = uint8(c2da_fresh33 >> 0x10)
            c2da_mem[a_0 + 59] = uint8(c2da_fresh33 >> 0x18)
        }
        i_0++
    }
    return
}
var private me : int = default<int>

var private plrs : int = default<int>

var private cnt_time : int = default<int>

var private cnt_par : int = default<int>

var private cnt_secret : int[4]

var private cnt_items : int[4]

var private cnt_kills : int[4]

[export, sideeffects]
def WI_updateNetgameStats() {
    var i_1 : int
    var fsum : int
    var stillticking : uint
    WI_updateAnimatedBack()
    if (acceleratestage != 0 && ng_state != 10) {
        acceleratestage = 0
        i_1 = 0
        while (i_1 < 4) {
            if (playeringame[i_1] == 0) {
                i_1++
                continue
            }
            cnt_kills[i_1] = int(uint(c2da_mem[plrs + i_1 * 40 + 4]) | uint(c2da_mem[plrs + i_1 * 40 + 5]) << 0x8 | uint(c2da_mem[plrs + i_1 * 40 + 6]) << 0x10 | uint(c2da_mem[plrs + i_1 * 40 + 7]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 16]) | uint(c2da_mem[wbs + 17]) << 0x8 | uint(c2da_mem[wbs + 18]) << 0x10 | uint(c2da_mem[wbs + 19]) << 0x18)
            cnt_items[i_1] = int(uint(c2da_mem[plrs + i_1 * 40 + 8]) | uint(c2da_mem[plrs + i_1 * 40 + 9]) << 0x8 | uint(c2da_mem[plrs + i_1 * 40 + 10]) << 0x10 | uint(c2da_mem[plrs + i_1 * 40 + 11]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 20]) | uint(c2da_mem[wbs + 21]) << 0x8 | uint(c2da_mem[wbs + 22]) << 0x10 | uint(c2da_mem[wbs + 23]) << 0x18)
            cnt_secret[i_1] = int(uint(c2da_mem[plrs + i_1 * 40 + 12]) | uint(c2da_mem[plrs + i_1 * 40 + 13]) << 0x8 | uint(c2da_mem[plrs + i_1 * 40 + 14]) << 0x10 | uint(c2da_mem[plrs + i_1 * 40 + 15]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 24]) | uint(c2da_mem[wbs + 25]) << 0x8 | uint(c2da_mem[wbs + 26]) << 0x10 | uint(c2da_mem[wbs + 27]) << 0x18)
            if (dofrags != 0) {
                cnt_frags[i_1] = WI_fragSum(i_1)
            }
            i_1++
        }
        S_StartSound(0, 82)
        ng_state = 10
    }
    if (ng_state == 2) {
        if ((bcnt & 3) == 0) {
            S_StartSound(0, 1)
        }
        stillticking = 0u
        i_1 = 0
        for (c2da_i_1 in range(i_1, 4)) {
            if (playeringame[c2da_i_1] == 0) {
                continue
            }
            cnt_kills[c2da_i_1] += 2
            if (cnt_kills[c2da_i_1] >= int(uint(c2da_mem[plrs + c2da_i_1 * 40 + 4]) | uint(c2da_mem[plrs + c2da_i_1 * 40 + 5]) << 0x8 | uint(c2da_mem[plrs + c2da_i_1 * 40 + 6]) << 0x10 | uint(c2da_mem[plrs + c2da_i_1 * 40 + 7]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 16]) | uint(c2da_mem[wbs + 17]) << 0x8 | uint(c2da_mem[wbs + 18]) << 0x10 | uint(c2da_mem[wbs + 19]) << 0x18)) {
                cnt_kills[c2da_i_1] = int(uint(c2da_mem[plrs + c2da_i_1 * 40 + 4]) | uint(c2da_mem[plrs + c2da_i_1 * 40 + 5]) << 0x8 | uint(c2da_mem[plrs + c2da_i_1 * 40 + 6]) << 0x10 | uint(c2da_mem[plrs + c2da_i_1 * 40 + 7]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 16]) | uint(c2da_mem[wbs + 17]) << 0x8 | uint(c2da_mem[wbs + 18]) << 0x10 | uint(c2da_mem[wbs + 19]) << 0x18)
            } else {
                stillticking = 1u
            }
        }
        if (stillticking == 0) {
            S_StartSound(0, 82)
            ng_state++
        }
    } elif (ng_state == 4) {
        if ((bcnt & 3) == 0) {
            S_StartSound(0, 1)
        }
        stillticking = 0u
        i_1 = 0
        for (c2da_i_1_0 in range(i_1, 4)) {
            if (playeringame[c2da_i_1_0] == 0) {
                continue
            }
            cnt_items[c2da_i_1_0] += 2
            if (cnt_items[c2da_i_1_0] >= int(uint(c2da_mem[plrs + c2da_i_1_0 * 40 + 8]) | uint(c2da_mem[plrs + c2da_i_1_0 * 40 + 9]) << 0x8 | uint(c2da_mem[plrs + c2da_i_1_0 * 40 + 10]) << 0x10 | uint(c2da_mem[plrs + c2da_i_1_0 * 40 + 11]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 20]) | uint(c2da_mem[wbs + 21]) << 0x8 | uint(c2da_mem[wbs + 22]) << 0x10 | uint(c2da_mem[wbs + 23]) << 0x18)) {
                cnt_items[c2da_i_1_0] = int(uint(c2da_mem[plrs + c2da_i_1_0 * 40 + 8]) | uint(c2da_mem[plrs + c2da_i_1_0 * 40 + 9]) << 0x8 | uint(c2da_mem[plrs + c2da_i_1_0 * 40 + 10]) << 0x10 | uint(c2da_mem[plrs + c2da_i_1_0 * 40 + 11]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 20]) | uint(c2da_mem[wbs + 21]) << 0x8 | uint(c2da_mem[wbs + 22]) << 0x10 | uint(c2da_mem[wbs + 23]) << 0x18)
            } else {
                stillticking = 1u
            }
        }
        if (stillticking == 0) {
            S_StartSound(0, 82)
            ng_state++
        }
    } elif (ng_state == 6) {
        if ((bcnt & 3) == 0) {
            S_StartSound(0, 1)
        }
        stillticking = 0u
        i_1 = 0
        for (c2da_i_1_1 in range(i_1, 4)) {
            if (playeringame[c2da_i_1_1] == 0) {
                continue
            }
            cnt_secret[c2da_i_1_1] += 2
            if (cnt_secret[c2da_i_1_1] >= int(uint(c2da_mem[plrs + c2da_i_1_1 * 40 + 12]) | uint(c2da_mem[plrs + c2da_i_1_1 * 40 + 13]) << 0x8 | uint(c2da_mem[plrs + c2da_i_1_1 * 40 + 14]) << 0x10 | uint(c2da_mem[plrs + c2da_i_1_1 * 40 + 15]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 24]) | uint(c2da_mem[wbs + 25]) << 0x8 | uint(c2da_mem[wbs + 26]) << 0x10 | uint(c2da_mem[wbs + 27]) << 0x18)) {
                cnt_secret[c2da_i_1_1] = int(uint(c2da_mem[plrs + c2da_i_1_1 * 40 + 12]) | uint(c2da_mem[plrs + c2da_i_1_1 * 40 + 13]) << 0x8 | uint(c2da_mem[plrs + c2da_i_1_1 * 40 + 14]) << 0x10 | uint(c2da_mem[plrs + c2da_i_1_1 * 40 + 15]) << 0x18) * 100 / int(uint(c2da_mem[wbs + 24]) | uint(c2da_mem[wbs + 25]) << 0x8 | uint(c2da_mem[wbs + 26]) << 0x10 | uint(c2da_mem[wbs + 27]) << 0x18)
            } else {
                stillticking = 1u
            }
        }
        if (stillticking == 0) {
            S_StartSound(0, 82)
            ng_state += 1 + 2 * (dofrags == 0 ? 1 : 0)
        }
    } elif (ng_state == 8) {
        if ((bcnt & 3) == 0) {
            S_StartSound(0, 1)
        }
        stillticking = 0u
        i_1 = 0
        for (c2da_i_1_2 in range(i_1, 4)) {
            if (playeringame[c2da_i_1_2] == 0) {
                continue
            }
            cnt_frags[c2da_i_1_2]++
            fsum = WI_fragSum(c2da_i_1_2)
            if (cnt_frags[c2da_i_1_2] >= fsum) {
                cnt_frags[c2da_i_1_2] = fsum
            } else {
                stillticking = 1u
            }
        }
        if (stillticking == 0) {
            S_StartSound(0, 57)
            ng_state++
        }
    } elif (ng_state == 10) {
        if (acceleratestage != 0) {
            S_StartSound(0, 3)
            if (uint(gamemode) == 2u) {
                WI_initNoState()
            } else {
                WI_initShowNextLoc()
            }
        }
    } elif ((ng_state & 1) != 0) {
        cnt_pause--
        if (cnt_pause == 0) {
            ng_state++
            cnt_pause = 35
        }
    }
    return
}
var private ng_state : int = default<int>

var private cnt_frags : int[4]

[export, sideeffects]
def WI_fragSum(var playernum : int) : int {
    var frags : int = 0
    for (i_2 in range(0, 4)) {
        if (playeringame[i_2] != 0x0 && i_2 != playernum) {
            frags += int(uint(c2da_mem[plrs + playernum * 40 + 20 + i_2 * 4]) | uint(c2da_mem[plrs + playernum * 40 + 20 + i_2 * 4 + 1]) << 0x8 | uint(c2da_mem[plrs + playernum * 40 + 20 + i_2 * 4 + 2]) << 0x10 | uint(c2da_mem[plrs + playernum * 40 + 20 + i_2 * 4 + 3]) << 0x18)
        }
    }
    frags -= int(uint(c2da_mem[plrs + playernum * 40 + 20 + playernum * 4]) | uint(c2da_mem[plrs + playernum * 40 + 20 + playernum * 4 + 1]) << 0x8 | uint(c2da_mem[plrs + playernum * 40 + 20 + playernum * 4 + 2]) << 0x10 | uint(c2da_mem[plrs + playernum * 40 + 20 + playernum * 4 + 3]) << 0x18)
    return frags
}
var private dofrags : int = default<int>

[export, sideeffects]
def WI_updateDeathmatchStats() {
    var i_3 : int
    var j : int
    var stillticking_0 : uint
    WI_updateAnimatedBack()
    if (acceleratestage != 0 && dm_state != 4) {
        acceleratestage = 0
        i_3 = 0
        while (i_3 < 4) {
            if (playeringame[i_3] != 0x0) {
                j = 0
                while (j < 4) {
                    if (playeringame[j] != 0x0) {
                        dm_frags[i_3][j] = int(uint(c2da_mem[plrs + i_3 * 40 + 20 + j * 4]) | uint(c2da_mem[plrs + i_3 * 40 + 20 + j * 4 + 1]) << 0x8 | uint(c2da_mem[plrs + i_3 * 40 + 20 + j * 4 + 2]) << 0x10 | uint(c2da_mem[plrs + i_3 * 40 + 20 + j * 4 + 3]) << 0x18)
                    }
                    j++
                }
                dm_totals[i_3] = WI_fragSum(i_3)
            }
            i_3++
        }
        S_StartSound(0, 82)
        dm_state = 4
    }
    if (dm_state == 2) {
        if ((bcnt & 3) == 0) {
            S_StartSound(0, 1)
        }
        stillticking_0 = 0u
        i_3 = 0
        for (c2da_i_3 in range(i_3, 4)) {
            if (playeringame[c2da_i_3] != 0x0) {
                j = 0
                while (j < 4) {
                    if (playeringame[j] != 0x0 && dm_frags[c2da_i_3][j] != int(uint(c2da_mem[plrs + c2da_i_3 * 40 + 20 + j * 4]) | uint(c2da_mem[plrs + c2da_i_3 * 40 + 20 + j * 4 + 1]) << 0x8 | uint(c2da_mem[plrs + c2da_i_3 * 40 + 20 + j * 4 + 2]) << 0x10 | uint(c2da_mem[plrs + c2da_i_3 * 40 + 20 + j * 4 + 3]) << 0x18)) {
                        if (int(uint(c2da_mem[plrs + c2da_i_3 * 40 + 20 + j * 4]) | uint(c2da_mem[plrs + c2da_i_3 * 40 + 20 + j * 4 + 1]) << 0x8 | uint(c2da_mem[plrs + c2da_i_3 * 40 + 20 + j * 4 + 2]) << 0x10 | uint(c2da_mem[plrs + c2da_i_3 * 40 + 20 + j * 4 + 3]) << 0x18) < 0) {
                            dm_frags[c2da_i_3][j]--
                        } else {
                            dm_frags[c2da_i_3][j]++
                        }
                        if (dm_frags[c2da_i_3][j] > 99) {
                            dm_frags[c2da_i_3][j] = 99
                        }
                        if (dm_frags[c2da_i_3][j] < -99) {
                            dm_frags[c2da_i_3][j] = -99
                        }
                        stillticking_0 = 1u
                    }
                    j++
                }
                dm_totals[c2da_i_3] = WI_fragSum(c2da_i_3)
                if (dm_totals[c2da_i_3] > 99) {
                    dm_totals[c2da_i_3] = 99
                }
                if (dm_totals[c2da_i_3] < -99) {
                    dm_totals[c2da_i_3] = -99
                }
            }
        }
        if (stillticking_0 == 0) {
            S_StartSound(0, 82)
            dm_state++
        }
    } elif (dm_state == 4) {
        if (acceleratestage != 0) {
            S_StartSound(0, 31)
            if (uint(gamemode) == 2u) {
                WI_initNoState()
            } else {
                WI_initShowNextLoc()
            }
        }
    } elif ((dm_state & 1) != 0) {
        cnt_pause--
        if (cnt_pause == 0) {
            dm_state++
            cnt_pause = 35
        }
    }
    return
}
var private dm_state : int = default<int>

var private dm_totals : int[4]

var private dm_frags : int[4][4]

[export, sideeffects]
def WI_checkForAccelerate() {
    var i_4 : int
    var player : int
    i_4 = 0
    player = 96
    while (i_4 < 4) {
        if (playeringame[i_4] != 0x0) {
            if ((int(c2da_mem[player + 17]) & 1) != 0) {
                if (int(uint(c2da_mem[player + 200]) | uint(c2da_mem[player + 201]) << 0x8 | uint(c2da_mem[player + 202]) << 0x10 | uint(c2da_mem[player + 203]) << 0x18) == 0) {
                    acceleratestage = 1
                }
                let c2da_fresh34 : int = 1
                let c2da_fresh35 : uint = uint(c2da_fresh34)
                c2da_mem[player + 200] = uint8(c2da_fresh35)
                c2da_mem[player + 201] = uint8(c2da_fresh35 >> 0x8)
                c2da_mem[player + 202] = uint8(c2da_fresh35 >> 0x10)
                c2da_mem[player + 203] = uint8(c2da_fresh35 >> 0x18)
            } else {
                let c2da_fresh36 : int = 0
                let c2da_fresh37 : uint = uint(c2da_fresh36)
                c2da_mem[player + 200] = uint8(c2da_fresh37)
                c2da_mem[player + 201] = uint8(c2da_fresh37 >> 0x8)
                c2da_mem[player + 202] = uint8(c2da_fresh37 >> 0x10)
                c2da_mem[player + 203] = uint8(c2da_fresh37 >> 0x18)
            }
            if ((int(c2da_mem[player + 17]) & 2) != 0) {
                if (int(uint(c2da_mem[player + 204]) | uint(c2da_mem[player + 205]) << 0x8 | uint(c2da_mem[player + 206]) << 0x10 | uint(c2da_mem[player + 207]) << 0x18) == 0) {
                    acceleratestage = 1
                }
                let c2da_fresh38 : int = 1
                let c2da_fresh39 : uint = uint(c2da_fresh38)
                c2da_mem[player + 204] = uint8(c2da_fresh39)
                c2da_mem[player + 205] = uint8(c2da_fresh39 >> 0x8)
                c2da_mem[player + 206] = uint8(c2da_fresh39 >> 0x10)
                c2da_mem[player + 207] = uint8(c2da_fresh39 >> 0x18)
            } else {
                let c2da_fresh40 : int = 0
                let c2da_fresh41 : uint = uint(c2da_fresh40)
                c2da_mem[player + 204] = uint8(c2da_fresh41)
                c2da_mem[player + 205] = uint8(c2da_fresh41 >> 0x8)
                c2da_mem[player + 206] = uint8(c2da_fresh41 >> 0x10)
                c2da_mem[player + 207] = uint8(c2da_fresh41 >> 0x18)
            }
        }
        i_4++
        player += 328
    }
    return
}
[export, sideeffects]
def WI_Drawer() {
    let c2da_fresh42 : int = state
    if (c2da_fresh42 == 0) {
        if (deathmatch != 0) {
            WI_drawDeathmatchStats()
        } elif (netgame != 0x0) {
            WI_drawNetgameStats()
        } else {
            WI_drawStats()
        }
    } elif (c2da_fresh42 == 1) {
        WI_drawShowNextLoc()
    } elif (c2da_fresh42 == -1) {
        WI_drawNoState()
    }
    return
}
[export, sideeffects]
def WI_drawNoState() {
    snl_pointeron = 1u
    WI_drawShowNextLoc()
    return
}
[export, sideeffects]
def WI_drawShowNextLoc() {
    var i_5 : int
    var last : int
    WI_slamBackground()
    WI_drawAnimatedBack()
    if (uint(gamemode) != 2u) {
        if (int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18) > 2) {
            WI_drawEL()
            return
        }
        last = int(uint(c2da_mem[wbs + 8]) | uint(c2da_mem[wbs + 9]) << 0x8 | uint(c2da_mem[wbs + 10]) << 0x10 | uint(c2da_mem[wbs + 11]) << 0x18) == 8 ? int(uint(c2da_mem[wbs + 12]) | uint(c2da_mem[wbs + 13]) << 0x8 | uint(c2da_mem[wbs + 14]) << 0x10 | uint(c2da_mem[wbs + 15]) << 0x18) - 1 : int(uint(c2da_mem[wbs + 8]) | uint(c2da_mem[wbs + 9]) << 0x8 | uint(c2da_mem[wbs + 10]) << 0x10 | uint(c2da_mem[wbs + 11]) << 0x18)
        i_5 = 0
        while (i_5 <= last) {
            WI_drawOnLnode(i_5, 376032)
            i_5++
        }
        if ((uint(c2da_mem[wbs + 4]) | uint(c2da_mem[wbs + 5]) << 0x8 | uint(c2da_mem[wbs + 6]) << 0x10 | uint(c2da_mem[wbs + 7]) << 0x18) != 0x0) {
            WI_drawOnLnode(8, 376032)
        }
        if (snl_pointeron != 0x0) {
            WI_drawOnLnode(int(uint(c2da_mem[wbs + 12]) | uint(c2da_mem[wbs + 13]) << 0x8 | uint(c2da_mem[wbs + 14]) << 0x10 | uint(c2da_mem[wbs + 15]) << 0x18), 376048)
        }
    }
    if (uint(gamemode) != 2u || int(uint(c2da_mem[wbs + 12]) | uint(c2da_mem[wbs + 13]) << 0x8 | uint(c2da_mem[wbs + 14]) << 0x10 | uint(c2da_mem[wbs + 15]) << 0x18) != 30) {
        WI_drawEL()
    }
    return
}
[export, sideeffects]
def WI_drawEL() {
    var y : int = 2
    let c2da_fresh43 : int = int(uint(c2da_mem[376208]) | uint(c2da_mem[376209]) << 0x8 | uint(c2da_mem[376210]) << 0x10 | uint(c2da_mem[376211]) << 0x18)
    V_DrawPatch((320 - int(int16(uint(c2da_mem[c2da_fresh43]) | uint(c2da_mem[c2da_fresh43 + 1]) << 0x8))) / 2, y, int(uint(c2da_mem[376208]) | uint(c2da_mem[376209]) << 0x8 | uint(c2da_mem[376210]) << 0x10 | uint(c2da_mem[376211]) << 0x18))
    let c2da_fresh44 : int = lnames + int(uint(c2da_mem[wbs + 12]) | uint(c2da_mem[wbs + 13]) << 0x8 | uint(c2da_mem[wbs + 14]) << 0x10 | uint(c2da_mem[wbs + 15]) << 0x18) * 8
    let c2da_fresh45 : int = int(uint(c2da_mem[c2da_fresh44]) | uint(c2da_mem[c2da_fresh44 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh44 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh44 + 3]) << 0x18) + 2
    y += 5 * int(int16(uint(c2da_mem[c2da_fresh45]) | uint(c2da_mem[c2da_fresh45 + 1]) << 0x8)) / 4
    let c2da_fresh46 : int = lnames + int(uint(c2da_mem[wbs + 12]) | uint(c2da_mem[wbs + 13]) << 0x8 | uint(c2da_mem[wbs + 14]) << 0x10 | uint(c2da_mem[wbs + 15]) << 0x18) * 8
    let c2da_fresh47 : int = int(uint(c2da_mem[c2da_fresh46]) | uint(c2da_mem[c2da_fresh46 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh46 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh46 + 3]) << 0x18)
    let c2da_fresh48 : int = lnames + int(uint(c2da_mem[wbs + 12]) | uint(c2da_mem[wbs + 13]) << 0x8 | uint(c2da_mem[wbs + 14]) << 0x10 | uint(c2da_mem[wbs + 15]) << 0x18) * 8
    V_DrawPatch((320 - int(int16(uint(c2da_mem[c2da_fresh47]) | uint(c2da_mem[c2da_fresh47 + 1]) << 0x8))) / 2, y, int(uint(c2da_mem[c2da_fresh48]) | uint(c2da_mem[c2da_fresh48 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh48 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh48 + 3]) << 0x18))
    return
}
var private lnames : int = default<int>

[export, sideeffects]
def WI_drawOnLnode(var n : int; var c : int) {
    var i_6 : int
    var left : int
    var top : int
    var right : int
    var bottom : int
    var fits : uint = 0u
    i_6 = 0
    while (true) {
        let c2da_fresh49 : int = int(uint(c2da_mem[c + i_6 * 8]) | uint(c2da_mem[c + i_6 * 8 + 1]) << 0x8 | uint(c2da_mem[c + i_6 * 8 + 2]) << 0x10 | uint(c2da_mem[c + i_6 * 8 + 3]) << 0x18) + 4
        left = lnodes[int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18)][n].x - int(int16(uint(c2da_mem[c2da_fresh49]) | uint(c2da_mem[c2da_fresh49 + 1]) << 0x8))
        let c2da_fresh50 : int = int(uint(c2da_mem[c + i_6 * 8]) | uint(c2da_mem[c + i_6 * 8 + 1]) << 0x8 | uint(c2da_mem[c + i_6 * 8 + 2]) << 0x10 | uint(c2da_mem[c + i_6 * 8 + 3]) << 0x18) + 6
        top = lnodes[int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18)][n].y - int(int16(uint(c2da_mem[c2da_fresh50]) | uint(c2da_mem[c2da_fresh50 + 1]) << 0x8))
        let c2da_fresh51 : int = int(uint(c2da_mem[c + i_6 * 8]) | uint(c2da_mem[c + i_6 * 8 + 1]) << 0x8 | uint(c2da_mem[c + i_6 * 8 + 2]) << 0x10 | uint(c2da_mem[c + i_6 * 8 + 3]) << 0x18)
        right = left + int(int16(uint(c2da_mem[c2da_fresh51]) | uint(c2da_mem[c2da_fresh51 + 1]) << 0x8))
        let c2da_fresh52 : int = int(uint(c2da_mem[c + i_6 * 8]) | uint(c2da_mem[c + i_6 * 8 + 1]) << 0x8 | uint(c2da_mem[c + i_6 * 8 + 2]) << 0x10 | uint(c2da_mem[c + i_6 * 8 + 3]) << 0x18) + 2
        bottom = top + int(int16(uint(c2da_mem[c2da_fresh52]) | uint(c2da_mem[c2da_fresh52 + 1]) << 0x8))
        if (left >= 0 && right < 320 && top >= 0 && bottom < 200) {
            fits = 1u
        } else {
            i_6++
        }
        if (!(fits == 0 && i_6 != 2 && int(uint(c2da_mem[c + i_6 * 8]) | uint(c2da_mem[c + i_6 * 8 + 1]) << 0x8 | uint(c2da_mem[c + i_6 * 8 + 2]) << 0x10 | uint(c2da_mem[c + i_6 * 8 + 3]) << 0x18) != 0)) {
            break
        }
    }
    if (fits != 0x0 && i_6 < 2) {
        V_DrawPatch(lnodes[int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18)][n].x, lnodes[int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18)][n].y, int(uint(c2da_mem[c + i_6 * 8]) | uint(c2da_mem[c + i_6 * 8 + 1]) << 0x8 | uint(c2da_mem[c + i_6 * 8 + 2]) << 0x10 | uint(c2da_mem[c + i_6 * 8 + 3]) << 0x18))
    } else {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 376488, [C2daVaArg(tag = 1, i64 = int64(n + 1), f64 = 0.0lf, raw = 0x0)])
    }
    return
}
var private lnodes : point_t[4][9] = fixed_array<point_t[9]>(fixed_array<point_t>(point_t(x = 185, y = 164), point_t(x = 148, y = 143), point_t(x = 69, y = 122), point_t(x = 209, y = 102), point_t(x = 116, y = 89), point_t(x = 166, y = 55), point_t(x = 71, y = 56), point_t(x = 135, y = 29), point_t(x = 71, y = 24)), fixed_array<point_t>(point_t(x = 254, y = 25), point_t(x = 97, y = 50), point_t(x = 188, y = 64), point_t(x = 128, y = 78), point_t(x = 214, y = 92), point_t(x = 133, y = 130), point_t(x = 208, y = 136), point_t(x = 148, y = 140), point_t(x = 235, y = 158)), fixed_array<point_t>(point_t(x = 156, y = 168), point_t(x = 48, y = 154), point_t(x = 174, y = 95), point_t(x = 265, y = 75), point_t(x = 130, y = 48), point_t(x = 279, y = 23), point_t(x = 198, y = 48), point_t(x = 140, y = 25), point_t(x = 281, y = 136)), fixed_array<point_t>(point_t(), point_t(), point_t(), point_t(), point_t(), point_t(), point_t(), point_t(), point_t()))

[export, sideeffects]
def WI_drawAnimatedBack() {
    var i_7 : int
    var a_1 : int
    if (uint(gamemode) == 2u) {
        return
    }
    if (int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18) > 2) {
        return
    }
    i_7 = 0
    while (i_7 < NUMANIMS[int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18)]) {
        a_1 = anims_0[int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18)] + i_7 * 72
        if (int(uint(c2da_mem[a_1 + 64]) | uint(c2da_mem[a_1 + 65]) << 0x8 | uint(c2da_mem[a_1 + 66]) << 0x10 | uint(c2da_mem[a_1 + 67]) << 0x18) >= 0) {
            let c2da_fresh53 : int = a_1 + 32 + int(uint(c2da_mem[a_1 + 64]) | uint(c2da_mem[a_1 + 65]) << 0x8 | uint(c2da_mem[a_1 + 66]) << 0x10 | uint(c2da_mem[a_1 + 67]) << 0x18) * 8
            V_DrawPatch(int(uint(c2da_mem[a_1 + 12]) | uint(c2da_mem[a_1 + 13]) << 0x8 | uint(c2da_mem[a_1 + 14]) << 0x10 | uint(c2da_mem[a_1 + 15]) << 0x18), int(uint(c2da_mem[a_1 + 16]) | uint(c2da_mem[a_1 + 17]) << 0x8 | uint(c2da_mem[a_1 + 18]) << 0x10 | uint(c2da_mem[a_1 + 19]) << 0x18), int(uint(c2da_mem[c2da_fresh53]) | uint(c2da_mem[c2da_fresh53 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh53 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh53 + 3]) << 0x18))
        }
        i_7++
    }
    return
}
[export, sideeffects]
def WI_slamBackground() {
    V_DrawPatch(0, 0, int(uint(c2da_mem[376480]) | uint(c2da_mem[376481]) << 0x8 | uint(c2da_mem[376482]) << 0x10 | uint(c2da_mem[376483]) << 0x18))
    return
}
[export, sideeffects]
def WI_drawStats() {
    var lh : int
    let c2da_fresh54 : int = int(uint(c2da_mem[376096 + 0 * 8]) | uint(c2da_mem[376096 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[376096 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[376096 + 0 * 8 + 3]) << 0x18) + 2
    lh = 3 * int(int16(uint(c2da_mem[c2da_fresh54]) | uint(c2da_mem[c2da_fresh54 + 1]) << 0x8)) / 2
    WI_slamBackground()
    WI_drawAnimatedBack()
    WI_drawLF()
    V_DrawPatch(50, 50, int(uint(c2da_mem[376224]) | uint(c2da_mem[376225]) << 0x8 | uint(c2da_mem[376226]) << 0x10 | uint(c2da_mem[376227]) << 0x18))
    WI_drawPercent(320 - 50, 50, cnt_kills[0])
    V_DrawPatch(50, 50 + lh, int(uint(c2da_mem[376272]) | uint(c2da_mem[376273]) << 0x8 | uint(c2da_mem[376274]) << 0x10 | uint(c2da_mem[376275]) << 0x18))
    WI_drawPercent(320 - 50, 50 + lh, cnt_items[0])
    V_DrawPatch(50, 50 + 2 * lh, int(uint(c2da_mem[376256]) | uint(c2da_mem[376257]) << 0x8 | uint(c2da_mem[376258]) << 0x10 | uint(c2da_mem[376259]) << 0x18))
    WI_drawPercent(320 - 50, 50 + 2 * lh, cnt_secret[0])
    V_DrawPatch(16, 200 - 32, int(uint(c2da_mem[376320]) | uint(c2da_mem[376321]) << 0x8 | uint(c2da_mem[376322]) << 0x10 | uint(c2da_mem[376323]) << 0x18))
    WI_drawTime(320 / 2 - 16, 200 - 32, cnt_time)
    if (int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18) < 3) {
        V_DrawPatch(320 / 2 + 16, 200 - 32, int(uint(c2da_mem[376352]) | uint(c2da_mem[376353]) << 0x8 | uint(c2da_mem[376354]) << 0x10 | uint(c2da_mem[376355]) << 0x18))
        WI_drawTime(320 - 16, 200 - 32, cnt_par)
    }
    return
}
[export, sideeffects]
def WI_drawTime(var x : int; var y_0 : int; var t : int) {
    var div : int
    if (t < 0) {
        return
    }
    if (t <= 61 * 59) {
        div = 1
        while (true) {
            let c2da_fresh55 : int = int(uint(c2da_mem[376304]) | uint(c2da_mem[376305]) << 0x8 | uint(c2da_mem[376306]) << 0x10 | uint(c2da_mem[376307]) << 0x18)
            x = WI_drawNum(x, y_0, t / div % 60, 2) - int(int16(uint(c2da_mem[c2da_fresh55]) | uint(c2da_mem[c2da_fresh55 + 1]) << 0x8))
            div *= 60
            if (div == 60 || t / div != 0) {
                V_DrawPatch(x, y_0, int(uint(c2da_mem[376304]) | uint(c2da_mem[376305]) << 0x8 | uint(c2da_mem[376306]) << 0x10 | uint(c2da_mem[376307]) << 0x18))
            }
            if (t / div == 0) {
                break
            }
        }
    } else {
        let c2da_fresh56 : int = int(uint(c2da_mem[376336]) | uint(c2da_mem[376337]) << 0x8 | uint(c2da_mem[376338]) << 0x10 | uint(c2da_mem[376339]) << 0x18)
        V_DrawPatch(x - int(int16(uint(c2da_mem[c2da_fresh56]) | uint(c2da_mem[c2da_fresh56 + 1]) << 0x8)), y_0, int(uint(c2da_mem[376336]) | uint(c2da_mem[376337]) << 0x8 | uint(c2da_mem[376338]) << 0x10 | uint(c2da_mem[376339]) << 0x18))
    }
    return
}
[export, sideeffects]
def WI_drawNum(var x_0 : int; var y_1 : int; var n_1 : int; var digits : int) : int {
    var fontwidth : int
    var neg : int
    var temp : int
    let c2da_fresh57 : int = int(uint(c2da_mem[376096 + 0 * 8]) | uint(c2da_mem[376096 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[376096 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[376096 + 0 * 8 + 3]) << 0x18)
    fontwidth = int(int16(uint(c2da_mem[c2da_fresh57]) | uint(c2da_mem[c2da_fresh57 + 1]) << 0x8))
    if (digits < 0) {
        if (n_1 == 0) {
            digits = 1
        } else {
            digits = 0
            temp = n_1
            while (temp != 0) {
                temp /= 10
                digits++
            }
        }
    }
    neg = n_1 < 0 ? 1 : 0
    if (neg != 0) {
        n_1 = -n_1
    }
    if (n_1 == 1994) {
        return 0
    }
    while (true) {
        let c2da_postinc : int = digits
        digits--
        if (c2da_postinc == 0) {
            break
        }
        x_0 -= fontwidth
        let c2da_fresh58 : int = 376096 + n_1 % 10 * 8
        V_DrawPatch(x_0, y_1, int(uint(c2da_mem[c2da_fresh58]) | uint(c2da_mem[c2da_fresh58 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh58 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh58 + 3]) << 0x18))
        n_1 /= 10
    }
    if (neg != 0) {
        x_0 -= 8
        V_DrawPatch(x_0, y_1, int(uint(c2da_mem[376080]) | uint(c2da_mem[376081]) << 0x8 | uint(c2da_mem[376082]) << 0x10 | uint(c2da_mem[376083]) << 0x18))
    }
    return x_0
}
[export, sideeffects]
def WI_drawPercent(var x_1 : int; var y_3 : int; var p : int) {
    if (p < 0) {
        return
    }
    V_DrawPatch(x_1, y_3, int(uint(c2da_mem[376176]) | uint(c2da_mem[376177]) << 0x8 | uint(c2da_mem[376178]) << 0x10 | uint(c2da_mem[376179]) << 0x18))
    WI_drawNum(x_1, y_3, p, -1)
    return
}
[export, sideeffects]
def WI_drawLF() {
    let c2da_saved_sp : int = c2da_lin_sp
    WI_drawLF_c2da_frame(c2da_lin_enter(48))
    c2da_lin_sp = c2da_saved_sp
}
var private NUMCMAPS : int = default<int>

[export, sideeffects]
def WI_drawNetgameStats() {
    var x_2 : int
    var y_5 : int
    var pwidth : int
    let c2da_fresh65 : int = int(uint(c2da_mem[376176]) | uint(c2da_mem[376177]) << 0x8 | uint(c2da_mem[376178]) << 0x10 | uint(c2da_mem[376179]) << 0x18)
    pwidth = int(int16(uint(c2da_mem[c2da_fresh65]) | uint(c2da_mem[c2da_fresh65 + 1]) << 0x8))
    WI_slamBackground()
    WI_drawAnimatedBack()
    WI_drawLF()
    let c2da_fresh66 : int = int(uint(c2da_mem[376224]) | uint(c2da_mem[376225]) << 0x8 | uint(c2da_mem[376226]) << 0x10 | uint(c2da_mem[376227]) << 0x18)
    V_DrawPatch(32 + int(int16(uint(c2da_mem[star]) | uint(c2da_mem[star + 1]) << 0x8)) / 2 + 32 * (dofrags == 0 ? 1 : 0) + 64 - int(int16(uint(c2da_mem[c2da_fresh66]) | uint(c2da_mem[c2da_fresh66 + 1]) << 0x8)), 50, int(uint(c2da_mem[376224]) | uint(c2da_mem[376225]) << 0x8 | uint(c2da_mem[376226]) << 0x10 | uint(c2da_mem[376227]) << 0x18))
    let c2da_fresh67 : int = int(uint(c2da_mem[376272]) | uint(c2da_mem[376273]) << 0x8 | uint(c2da_mem[376274]) << 0x10 | uint(c2da_mem[376275]) << 0x18)
    V_DrawPatch(32 + int(int16(uint(c2da_mem[star]) | uint(c2da_mem[star + 1]) << 0x8)) / 2 + 32 * (dofrags == 0 ? 1 : 0) + 2 * 64 - int(int16(uint(c2da_mem[c2da_fresh67]) | uint(c2da_mem[c2da_fresh67 + 1]) << 0x8)), 50, int(uint(c2da_mem[376272]) | uint(c2da_mem[376273]) << 0x8 | uint(c2da_mem[376274]) << 0x10 | uint(c2da_mem[376275]) << 0x18))
    let c2da_fresh68 : int = int(uint(c2da_mem[376240]) | uint(c2da_mem[376241]) << 0x8 | uint(c2da_mem[376242]) << 0x10 | uint(c2da_mem[376243]) << 0x18)
    V_DrawPatch(32 + int(int16(uint(c2da_mem[star]) | uint(c2da_mem[star + 1]) << 0x8)) / 2 + 32 * (dofrags == 0 ? 1 : 0) + 3 * 64 - int(int16(uint(c2da_mem[c2da_fresh68]) | uint(c2da_mem[c2da_fresh68 + 1]) << 0x8)), 50, int(uint(c2da_mem[376240]) | uint(c2da_mem[376241]) << 0x8 | uint(c2da_mem[376242]) << 0x10 | uint(c2da_mem[376243]) << 0x18))
    if (dofrags != 0) {
        let c2da_fresh69 : int = int(uint(c2da_mem[376288]) | uint(c2da_mem[376289]) << 0x8 | uint(c2da_mem[376290]) << 0x10 | uint(c2da_mem[376291]) << 0x18)
        V_DrawPatch(32 + int(int16(uint(c2da_mem[star]) | uint(c2da_mem[star + 1]) << 0x8)) / 2 + 32 * (dofrags == 0 ? 1 : 0) + 4 * 64 - int(int16(uint(c2da_mem[c2da_fresh69]) | uint(c2da_mem[c2da_fresh69 + 1]) << 0x8)), 50, int(uint(c2da_mem[376288]) | uint(c2da_mem[376289]) << 0x8 | uint(c2da_mem[376290]) << 0x10 | uint(c2da_mem[376291]) << 0x18))
    }
    let c2da_fresh70 : int = int(uint(c2da_mem[376224]) | uint(c2da_mem[376225]) << 0x8 | uint(c2da_mem[376226]) << 0x10 | uint(c2da_mem[376227]) << 0x18) + 2
    y_5 = 50 + int(int16(uint(c2da_mem[c2da_fresh70]) | uint(c2da_mem[c2da_fresh70 + 1]) << 0x8))
    for (i_8 in range(0, 4)) {
        if (playeringame[i_8] == 0) {
            continue
        }
        x_2 = 32 + int(int16(uint(c2da_mem[star]) | uint(c2da_mem[star + 1]) << 0x8)) / 2 + 32 * (dofrags == 0 ? 1 : 0)
        let c2da_fresh71 : int = int(uint(c2da_mem[376416 + i_8 * 8]) | uint(c2da_mem[376416 + i_8 * 8 + 1]) << 0x8 | uint(c2da_mem[376416 + i_8 * 8 + 2]) << 0x10 | uint(c2da_mem[376416 + i_8 * 8 + 3]) << 0x18)
        V_DrawPatch(x_2 - int(int16(uint(c2da_mem[c2da_fresh71]) | uint(c2da_mem[c2da_fresh71 + 1]) << 0x8)), y_5, int(uint(c2da_mem[376416 + i_8 * 8]) | uint(c2da_mem[376416 + i_8 * 8 + 1]) << 0x8 | uint(c2da_mem[376416 + i_8 * 8 + 2]) << 0x10 | uint(c2da_mem[376416 + i_8 * 8 + 3]) << 0x18))
        if (i_8 == me) {
            let c2da_fresh72 : int = int(uint(c2da_mem[376416 + i_8 * 8]) | uint(c2da_mem[376416 + i_8 * 8 + 1]) << 0x8 | uint(c2da_mem[376416 + i_8 * 8 + 2]) << 0x10 | uint(c2da_mem[376416 + i_8 * 8 + 3]) << 0x18)
            V_DrawPatch(x_2 - int(int16(uint(c2da_mem[c2da_fresh72]) | uint(c2da_mem[c2da_fresh72 + 1]) << 0x8)), y_5, star)
        }
        x_2 += 64
        WI_drawPercent(x_2 - pwidth, y_5 + 10, cnt_kills[i_8])
        x_2 += 64
        WI_drawPercent(x_2 - pwidth, y_5 + 10, cnt_items[i_8])
        x_2 += 64
        WI_drawPercent(x_2 - pwidth, y_5 + 10, cnt_secret[i_8])
        x_2 += 64
        if (dofrags != 0) {
            WI_drawNum(x_2, y_5 + 10, cnt_frags[i_8], -1)
        }
        y_5 += 33
    }
    return
}
var private star : int = default<int>

[export, sideeffects]
def WI_drawDeathmatchStats() {
    var i_9 : int
    var x_3 : int
    var y_6 : int
    var w : int
    WI_slamBackground()
    WI_drawAnimatedBack()
    WI_drawLF()
    let c2da_fresh73 : int = int(uint(c2da_mem[376400]) | uint(c2da_mem[376401]) << 0x8 | uint(c2da_mem[376402]) << 0x10 | uint(c2da_mem[376403]) << 0x18)
    V_DrawPatch(269 - int(int16(uint(c2da_mem[c2da_fresh73]) | uint(c2da_mem[c2da_fresh73 + 1]) << 0x8)) / 2, 68 - 33 + 10, int(uint(c2da_mem[376400]) | uint(c2da_mem[376401]) << 0x8 | uint(c2da_mem[376402]) << 0x10 | uint(c2da_mem[376403]) << 0x18))
    V_DrawPatch(10, 100, int(uint(c2da_mem[376368]) | uint(c2da_mem[376369]) << 0x8 | uint(c2da_mem[376370]) << 0x10 | uint(c2da_mem[376371]) << 0x18))
    V_DrawPatch(5, 50, int(uint(c2da_mem[376384]) | uint(c2da_mem[376385]) << 0x8 | uint(c2da_mem[376386]) << 0x10 | uint(c2da_mem[376387]) << 0x18))
    x_3 = 42 + 40
    y_6 = 68
    i_9 = 0
    while (i_9 < 4) {
        if (playeringame[i_9] != 0x0) {
            let c2da_fresh74 : int = int(uint(c2da_mem[376416 + i_9 * 8]) | uint(c2da_mem[376416 + i_9 * 8 + 1]) << 0x8 | uint(c2da_mem[376416 + i_9 * 8 + 2]) << 0x10 | uint(c2da_mem[376416 + i_9 * 8 + 3]) << 0x18)
            V_DrawPatch(x_3 - int(int16(uint(c2da_mem[c2da_fresh74]) | uint(c2da_mem[c2da_fresh74 + 1]) << 0x8)) / 2, 68 - 33, int(uint(c2da_mem[376416 + i_9 * 8]) | uint(c2da_mem[376416 + i_9 * 8 + 1]) << 0x8 | uint(c2da_mem[376416 + i_9 * 8 + 2]) << 0x10 | uint(c2da_mem[376416 + i_9 * 8 + 3]) << 0x18))
            let c2da_fresh75 : int = int(uint(c2da_mem[376416 + i_9 * 8]) | uint(c2da_mem[376416 + i_9 * 8 + 1]) << 0x8 | uint(c2da_mem[376416 + i_9 * 8 + 2]) << 0x10 | uint(c2da_mem[376416 + i_9 * 8 + 3]) << 0x18)
            V_DrawPatch(42 - int(int16(uint(c2da_mem[c2da_fresh75]) | uint(c2da_mem[c2da_fresh75 + 1]) << 0x8)) / 2, y_6, int(uint(c2da_mem[376416 + i_9 * 8]) | uint(c2da_mem[376416 + i_9 * 8 + 1]) << 0x8 | uint(c2da_mem[376416 + i_9 * 8 + 2]) << 0x10 | uint(c2da_mem[376416 + i_9 * 8 + 3]) << 0x18))
            if (i_9 == me) {
                let c2da_fresh76 : int = int(uint(c2da_mem[376416 + i_9 * 8]) | uint(c2da_mem[376416 + i_9 * 8 + 1]) << 0x8 | uint(c2da_mem[376416 + i_9 * 8 + 2]) << 0x10 | uint(c2da_mem[376416 + i_9 * 8 + 3]) << 0x18)
                V_DrawPatch(x_3 - int(int16(uint(c2da_mem[c2da_fresh76]) | uint(c2da_mem[c2da_fresh76 + 1]) << 0x8)) / 2, 68 - 33, bstar)
                let c2da_fresh77 : int = int(uint(c2da_mem[376416 + i_9 * 8]) | uint(c2da_mem[376416 + i_9 * 8 + 1]) << 0x8 | uint(c2da_mem[376416 + i_9 * 8 + 2]) << 0x10 | uint(c2da_mem[376416 + i_9 * 8 + 3]) << 0x18)
                V_DrawPatch(42 - int(int16(uint(c2da_mem[c2da_fresh77]) | uint(c2da_mem[c2da_fresh77 + 1]) << 0x8)) / 2, y_6, star)
            }
        }
        x_3 += 40
        y_6 += 33
        i_9++
    }
    y_6 = 68 + 10
    let c2da_fresh78 : int = int(uint(c2da_mem[376096 + 0 * 8]) | uint(c2da_mem[376096 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[376096 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[376096 + 0 * 8 + 3]) << 0x18)
    w = int(int16(uint(c2da_mem[c2da_fresh78]) | uint(c2da_mem[c2da_fresh78 + 1]) << 0x8))
    i_9 = 0
    for (c2da_i_9 in range(i_9, 4)) {
        x_3 = 42 + 40
        if (playeringame[c2da_i_9] != 0x0) {
            for (j_0 in range(0, 4)) {
                if (playeringame[j_0] != 0x0) {
                    WI_drawNum(x_3 + w, y_6, dm_frags[c2da_i_9][j_0], 2)
                }
                x_3 += 40
            }
            WI_drawNum(269 + w, y_6, dm_totals[c2da_i_9], 2)
        }
        y_6 += 33
    }
    return
}
var private bstar : int = default<int>

[export, sideeffects]
def WI_Start(var wbstartstruct : int) {
    WI_initVariables(wbstartstruct)
    WI_loadData()
    if (deathmatch != 0) {
        WI_initDeathmatchStats()
    } elif (netgame != 0x0) {
        WI_initNetgameStats()
    } else {
        WI_initStats()
    }
    return
}
[export, sideeffects]
def WI_initStats() {
    state = 0
    acceleratestage = 0
    sp_state = 1
    cnt_secret[0] = -1
    cnt_items[0] = int(cnt_secret[0])  // nolint:PERF020
    cnt_kills[0] = int(cnt_items[0])  // nolint:PERF020
    cnt_par = -1
    cnt_time = int(cnt_par)  // nolint:PERF020
    cnt_pause = 35
    WI_initAnimatedBack()
    return
}
[export, sideeffects]
def WI_initNetgameStats() {
    state = 0
    acceleratestage = 0
    ng_state = 1
    cnt_pause = 35
    for (i_10 in range(0, 4)) {
        if (playeringame[i_10] == 0) {
            continue
        }
        cnt_frags[i_10] = 0
        cnt_secret[i_10] = int(cnt_frags[i_10])  // nolint:PERF020
        cnt_items[i_10] = int(cnt_secret[i_10])  // nolint:PERF020
        cnt_kills[i_10] = int(cnt_items[i_10])  // nolint:PERF020
        dofrags = dofrags + WI_fragSum(i_10)
    }
    dofrags = !(dofrags == 0) ? 1 : 0
    WI_initAnimatedBack()
    return
}
[export, sideeffects]
def WI_initDeathmatchStats() {
    state = 0
    acceleratestage = 0
    dm_state = 1
    cnt_pause = 35
    for (i_11 in range(0, 4)) {
        if (playeringame[i_11] != 0x0) {
            for (j_1 in range(0, 4)) {
                if (playeringame[j_1] != 0x0) {
                    dm_frags[i_11][j_1] = 0
                }
            }
            dm_totals[i_11] = 0
        }
    }
    WI_initAnimatedBack()
    return
}
[export, sideeffects]
def WI_loadData() {
    if (uint(gamemode) == 2u) {
        NUMCMAPS = 32
        lnames = Z_Malloc(int(8ul * uint64(NUMCMAPS)), 1, 0)
    } else {
        lnames = Z_Malloc(int(8ul * 9ul), 1, 0)
    }
    WI_loadUnloadData(175)
    star = W_CacheLumpName(376522, 1)
    bstar = W_CacheLumpName(376530, 1)
    return
}
[sideeffects]
def private WI_loadCallback(var name : int; var variable : int) {
    let c2da_fresh79 : int = W_CacheLumpName(name, 1)
    let c2da_fresh80 : uint = uint(c2da_fresh79)
    c2da_mem[variable] = uint8(c2da_fresh80)
    c2da_mem[variable + 1] = uint8(c2da_fresh80 >> 0x8)
    c2da_mem[variable + 2] = uint8(c2da_fresh80 >> 0x10)
    c2da_mem[variable + 3] = uint8(c2da_fresh80 >> 0x18)
    c2da_mem[variable + 4] = 0u8
    c2da_mem[variable + 5] = 0u8
    c2da_mem[variable + 6] = 0u8
    c2da_mem[variable + 7] = 0u8
    return
}
[sideeffects]
def private WI_loadUnloadData(var callback : load_callback_t_0) {
    let c2da_saved_sp : int = c2da_lin_sp
    WI_loadUnloadData_c2da_frame(callback, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def WI_initVariables(var wbstartstruct_0 : int) {
    wbs = int(wbstartstruct_0)  // nolint:PERF020
    acceleratestage = 0
    bcnt = 0
    cnt = int(bcnt)  // nolint:PERF020
    firstrefresh = 1
    me = int(uint(c2da_mem[wbs + 36]) | uint(c2da_mem[wbs + 37]) << 0x8 | uint(c2da_mem[wbs + 38]) << 0x10 | uint(c2da_mem[wbs + 39]) << 0x18)
    plrs = wbs + 40
    if (int(uint(c2da_mem[wbs + 16]) | uint(c2da_mem[wbs + 17]) << 0x8 | uint(c2da_mem[wbs + 18]) << 0x10 | uint(c2da_mem[wbs + 19]) << 0x18) == 0) {
        let c2da_fresh84 : int = 1
        let c2da_fresh85 : uint = uint(c2da_fresh84)
        c2da_mem[wbs + 16] = uint8(c2da_fresh85)
        c2da_mem[wbs + 17] = uint8(c2da_fresh85 >> 0x8)
        c2da_mem[wbs + 18] = uint8(c2da_fresh85 >> 0x10)
        c2da_mem[wbs + 19] = uint8(c2da_fresh85 >> 0x18)
    }
    if (int(uint(c2da_mem[wbs + 20]) | uint(c2da_mem[wbs + 21]) << 0x8 | uint(c2da_mem[wbs + 22]) << 0x10 | uint(c2da_mem[wbs + 23]) << 0x18) == 0) {
        let c2da_fresh86 : int = 1
        let c2da_fresh87 : uint = uint(c2da_fresh86)
        c2da_mem[wbs + 20] = uint8(c2da_fresh87)
        c2da_mem[wbs + 21] = uint8(c2da_fresh87 >> 0x8)
        c2da_mem[wbs + 22] = uint8(c2da_fresh87 >> 0x10)
        c2da_mem[wbs + 23] = uint8(c2da_fresh87 >> 0x18)
    }
    if (int(uint(c2da_mem[wbs + 24]) | uint(c2da_mem[wbs + 25]) << 0x8 | uint(c2da_mem[wbs + 26]) << 0x10 | uint(c2da_mem[wbs + 27]) << 0x18) == 0) {
        let c2da_fresh88 : int = 1
        let c2da_fresh89 : uint = uint(c2da_fresh88)
        c2da_mem[wbs + 24] = uint8(c2da_fresh89)
        c2da_mem[wbs + 25] = uint8(c2da_fresh89 >> 0x8)
        c2da_mem[wbs + 26] = uint8(c2da_fresh89 >> 0x10)
        c2da_mem[wbs + 27] = uint8(c2da_fresh89 >> 0x18)
    }
    if (uint(gamemode) != 3u) {
        if (int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18) > 2) {
            let c2da_fresh90 : int = int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18) - 3
            let c2da_fresh91 : uint = uint(c2da_fresh90)
            c2da_mem[wbs] = uint8(c2da_fresh91)
            c2da_mem[wbs + 1] = uint8(c2da_fresh91 >> 0x8)
            c2da_mem[wbs + 2] = uint8(c2da_fresh91 >> 0x10)
            c2da_mem[wbs + 3] = uint8(c2da_fresh91 >> 0x18)
        }
    }
    return
}
var private firstrefresh : int = default<int>

[export, sideeffects]
def WI_End() {
    WI_unloadData()
    return
}
[sideeffects]
def private WI_unloadCallback(var name_0 : int; var variable_0 : int) {
    W_ReleaseLumpName(name_0)
    let c2da_fresh92 : uint = 0u
    c2da_mem[variable_0] = uint8(c2da_fresh92)
    c2da_mem[variable_0 + 1] = uint8(c2da_fresh92 >> 0x8)
    c2da_mem[variable_0 + 2] = uint8(c2da_fresh92 >> 0x10)
    c2da_mem[variable_0 + 3] = uint8(c2da_fresh92 >> 0x18)
    c2da_mem[variable_0 + 4] = 0u8
    c2da_mem[variable_0 + 5] = 0u8
    c2da_mem[variable_0 + 6] = 0u8
    c2da_mem[variable_0 + 7] = 0u8
    return
}
[export, sideeffects]
def WI_Responder(var ev : int) : uint {
    return 0u
}
[export, sideeffects]
def WI_unloadData() {
    WI_loadUnloadData(176)
    return
}
[sideeffects]
def private WI_drawLF_c2da_frame(c2da_fp : int) {
    var y_4 : int = 2
    if (uint(gamemode) != 2u || int(uint(c2da_mem[wbs + 8]) | uint(c2da_mem[wbs + 9]) << 0x8 | uint(c2da_mem[wbs + 10]) << 0x10 | uint(c2da_mem[wbs + 11]) << 0x18) < NUMCMAPS) {
        let c2da_fresh59 : int = lnames + int(uint(c2da_mem[wbs + 8]) | uint(c2da_mem[wbs + 9]) << 0x8 | uint(c2da_mem[wbs + 10]) << 0x10 | uint(c2da_mem[wbs + 11]) << 0x18) * 8
        let c2da_fresh60 : int = int(uint(c2da_mem[c2da_fresh59]) | uint(c2da_mem[c2da_fresh59 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh59 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh59 + 3]) << 0x18)
        let c2da_fresh61 : int = lnames + int(uint(c2da_mem[wbs + 8]) | uint(c2da_mem[wbs + 9]) << 0x8 | uint(c2da_mem[wbs + 10]) << 0x10 | uint(c2da_mem[wbs + 11]) << 0x18) * 8
        V_DrawPatch((320 - int(int16(uint(c2da_mem[c2da_fresh60]) | uint(c2da_mem[c2da_fresh60 + 1]) << 0x8))) / 2, y_4, int(uint(c2da_mem[c2da_fresh61]) | uint(c2da_mem[c2da_fresh61 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh61 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh61 + 3]) << 0x18))
        let c2da_fresh62 : int = lnames + int(uint(c2da_mem[wbs + 8]) | uint(c2da_mem[wbs + 9]) << 0x8 | uint(c2da_mem[wbs + 10]) << 0x10 | uint(c2da_mem[wbs + 11]) << 0x18) * 8
        let c2da_fresh63 : int = int(uint(c2da_mem[c2da_fresh62]) | uint(c2da_mem[c2da_fresh62 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh62 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh62 + 3]) << 0x18) + 2
        y_4 += 5 * int(int16(uint(c2da_mem[c2da_fresh63]) | uint(c2da_mem[c2da_fresh63 + 1]) << 0x8)) / 4
        let c2da_fresh64 : int = int(uint(c2da_mem[376192]) | uint(c2da_mem[376193]) << 0x8 | uint(c2da_mem[376194]) << 0x10 | uint(c2da_mem[376195]) << 0x18)
        V_DrawPatch((320 - int(int16(uint(c2da_mem[c2da_fresh64]) | uint(c2da_mem[c2da_fresh64 + 1]) << 0x8))) / 2, y_4, int(uint(c2da_mem[376192]) | uint(c2da_mem[376193]) << 0x8 | uint(c2da_mem[376194]) << 0x10 | uint(c2da_mem[376195]) << 0x18))
    } elif (int(uint(c2da_mem[wbs + 8]) | uint(c2da_mem[wbs + 9]) << 0x8 | uint(c2da_mem[wbs + 10]) << 0x10 | uint(c2da_mem[wbs + 11]) << 0x18) != NUMCMAPS) {
        if (int(uint(c2da_mem[wbs + 8]) | uint(c2da_mem[wbs + 9]) << 0x8 | uint(c2da_mem[wbs + 10]) << 0x10 | uint(c2da_mem[wbs + 11]) << 0x18) > NUMCMAPS) {
            c2da_mem[c2da_fp] = 64u8
            c2da_mem[c2da_fp + 1] = 1u8
            c2da_mem[c2da_fp + 2] = 200u8
            c2da_mem[c2da_fp + 3] = 0u8
            c2da_mem[c2da_fp + 4] = 1u8
            c2da_mem[c2da_fp + 5] = 0u8
            c2da_mem[c2da_fp + 6] = 1u8
            c2da_mem[c2da_fp + 7] = 0u8
            c2da_mem[c2da_fp + 8] = 0u8
            c2da_mem[c2da_fp + 9] = 0u8
            c2da_mem[c2da_fp + 10] = 0u8
            c2da_mem[c2da_fp + 11] = 0u8
            c2da_mem[c2da_fp + 12] = 0u8
            c2da_mem[c2da_fp + 13] = 0u8
            c2da_mem[c2da_fp + 14] = 0u8
            c2da_mem[c2da_fp + 15] = 0u8
            c2da_mem[c2da_fp + 16] = 0u8
            c2da_mem[c2da_fp + 17] = 0u8
            c2da_mem[c2da_fp + 18] = 0u8
            c2da_mem[c2da_fp + 19] = 0u8
            c2da_mem[c2da_fp + 20] = 0u8
            c2da_mem[c2da_fp + 21] = 0u8
            c2da_mem[c2da_fp + 22] = 0u8
            c2da_mem[c2da_fp + 23] = 0u8
            c2da_mem[c2da_fp + 24] = 0u8
            c2da_mem[c2da_fp + 25] = 0u8
            c2da_mem[c2da_fp + 26] = 0u8
            c2da_mem[c2da_fp + 27] = 0u8
            c2da_mem[c2da_fp + 28] = 0u8
            c2da_mem[c2da_fp + 29] = 0u8
            c2da_mem[c2da_fp + 30] = 0u8
            c2da_mem[c2da_fp + 31] = 0u8
            c2da_mem[c2da_fp + 32] = 0u8
            c2da_mem[c2da_fp + 33] = 0u8
            c2da_mem[c2da_fp + 34] = 0u8
            c2da_mem[c2da_fp + 35] = 0u8
            c2da_mem[c2da_fp + 36] = 0u8
            c2da_mem[c2da_fp + 37] = 0u8
            c2da_mem[c2da_fp + 38] = 0u8
            c2da_mem[c2da_fp + 39] = 0u8
            V_DrawPatch(0, y_4, c2da_fp)
        }
    }
    return
}
[sideeffects]
def private WI_loadUnloadData_c2da_frame(var callback : load_callback_t_0; c2da_fp : int) {
    var i_12 : int
    var j_2 : int
    var a_2 : int
    if (uint(gamemode) == 2u) {
        i_12 = 0
        while (i_12 < NUMCMAPS) {
            c2da_lin_snprintf(c2da_fp, 9ul, 376539, [C2daVaArg(tag = 1, i64 = int64(i_12), f64 = 0.0lf, raw = 0x0)])
            invoke(c2da_fn_table1[callback], c2da_fp, lnames + i_12 * 8)
            i_12++
        }
    } else {
        i_12 = 0
        while (i_12 < 9) {
            c2da_lin_snprintf(c2da_fp, 9ul, 376550, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(i_12), f64 = 0.0lf, raw = 0x0)])
            invoke(c2da_fn_table1[callback], c2da_fp, lnames + i_12 * 8)
            i_12++
        }
        invoke(c2da_fn_table1[callback], 376559, 376048 + 0 * 8)
        invoke(c2da_fn_table1[callback], 376566, 376048 + 1 * 8)
        invoke(c2da_fn_table1[callback], 376573, 376032 + 0 * 8)
        if (int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18) < 3) {
            j_2 = 0
            while (j_2 < NUMANIMS[int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18)]) {
                a_2 = anims_0[int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18)] + j_2 * 72
                i_12 = 0
                while (i_12 < int(uint(c2da_mem[a_2 + 8]) | uint(c2da_mem[a_2 + 9]) << 0x8 | uint(c2da_mem[a_2 + 10]) << 0x10 | uint(c2da_mem[a_2 + 11]) << 0x18)) {
                    if (int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18) != 1 || j_2 != 8) {
                        c2da_lin_snprintf(c2da_fp, 9ul, 376581, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(j_2), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(i_12), f64 = 0.0lf, raw = 0x0)])
                        invoke(c2da_fn_table1[callback], c2da_fp, a_2 + 32 + i_12 * 8)
                    } else {
                        let c2da_fresh81 : int = anims_0[1] + 4 * 72 + 32 + i_12 * 8
                        let c2da_fresh82 : int = int(uint(c2da_mem[c2da_fresh81]) | uint(c2da_mem[c2da_fresh81 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh81 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh81 + 3]) << 0x18)
                        let c2da_fresh83 : uint = uint(c2da_fresh82)
                        c2da_mem[a_2 + 32 + i_12 * 8] = uint8(c2da_fresh83)
                        c2da_mem[a_2 + 32 + i_12 * 8 + 1] = uint8(c2da_fresh83 >> 0x8)
                        c2da_mem[a_2 + 32 + i_12 * 8 + 2] = uint8(c2da_fresh83 >> 0x10)
                        c2da_mem[a_2 + 32 + i_12 * 8 + 3] = uint8(c2da_fresh83 >> 0x18)
                        c2da_mem[a_2 + 32 + i_12 * 8 + 4] = 0u8
                        c2da_mem[a_2 + 32 + i_12 * 8 + 5] = 0u8
                        c2da_mem[a_2 + 32 + i_12 * 8 + 6] = 0u8
                        c2da_mem[a_2 + 32 + i_12 * 8 + 7] = 0u8
                    }
                    i_12++
                }
                j_2++
            }
        }
    }
    invoke(c2da_fn_table1[callback], 376595, 376080)
    i_12 = 0
    while (i_12 < 10) {
        c2da_lin_snprintf(c2da_fp, 9ul, 376603, [C2daVaArg(tag = 1, i64 = int64(i_12), f64 = 0.0lf, raw = 0x0)])
        invoke(c2da_fn_table1[callback], c2da_fp, 376096 + i_12 * 8)
        i_12++
    }
    invoke(c2da_fn_table1[callback], 376611, 376176)
    invoke(c2da_fn_table1[callback], 376618, 376192)
    invoke(c2da_fn_table1[callback], 376622, 376208)
    invoke(c2da_fn_table1[callback], 376630, 376224)
    invoke(c2da_fn_table1[callback], 376637, 376240)
    invoke(c2da_fn_table1[callback], 376644, 376256)
    if (W_CheckNumForName(376652) >= 0) {
        if (netgame != 0x0 && deathmatch == 0) {
            invoke(c2da_fn_table1[callback], 376652, 376272)
        } else {
            invoke(c2da_fn_table1[callback], 376658, 376272)
        }
    } else {
        invoke(c2da_fn_table1[callback], 376658, 376272)
    }
    invoke(c2da_fn_table1[callback], 376665, 376288)
    invoke(c2da_fn_table1[callback], 376672, 376304)
    invoke(c2da_fn_table1[callback], 376680, 376320)
    invoke(c2da_fn_table1[callback], 376687, 376336)
    invoke(c2da_fn_table1[callback], 376695, 376352)
    invoke(c2da_fn_table1[callback], 376701, 376368)
    invoke(c2da_fn_table1[callback], 376709, 376384)
    invoke(c2da_fn_table1[callback], 376717, 376400)
    i_12 = 0
    for (c2da_i_12 in range(i_12, 4)) {
        c2da_lin_snprintf(c2da_fp, 9ul, 376724, [C2daVaArg(tag = 1, i64 = int64(c2da_i_12), f64 = 0.0lf, raw = 0x0)])
        invoke(c2da_fn_table1[callback], c2da_fp, 376416 + c2da_i_12 * 8)
        c2da_lin_snprintf(c2da_fp, 9ul, 376731, [C2daVaArg(tag = 1, i64 = int64(c2da_i_12 + 1), f64 = 0.0lf, raw = 0x0)])
        invoke(c2da_fn_table1[callback], c2da_fp, 376448 + c2da_i_12 * 8)
    }
    if (uint(gamemode) == 2u) {
        M_StringCopy(c2da_fp, 376738, 9ul)
    } elif (uint(gamemode) == 3u && int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18) == 3) {
        M_StringCopy(c2da_fp, 376738, 9ul)
    } else {
        c2da_lin_snprintf(c2da_fp, 9ul, 376747, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[wbs]) | uint(c2da_mem[wbs + 1]) << 0x8 | uint(c2da_mem[wbs + 2]) << 0x10 | uint(c2da_mem[wbs + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
    }
    invoke(c2da_fn_table1[callback], c2da_fp, 376480)
    return
}

// This unit's static data, at heap offset 374224.
let private c2da_lin_static_wi_stuff_seg = fixed_array<int>(374228, 13, 374300, 13, 374372, 13, 374444, 13, 374516, 13, 374588, 13, 374660, 13, 374732, 13, 374804, 13, 374876, 13, 374944, 21, 375016, 21, 375088, 21, 375160, 21, 375232, 21, 375304, 21, 375376, 21, 375448, 21, 375520, 21, 375604, 13, 375676, 13, 375748, 13, 375820, 13, 375892, 13, 375964, 9, 376488, 266)
let private c2da_lin_static_wi_stuff = fixed_array<uint64>(0x30000000bul, 0xb68000000e0ul, 0xb80000000300ul, 0x30000000ba000ul, 0xb88000000700000ul, 0x4800000003000000ul, 0xb70000000ul, 0x5800000003ul, 0x30000000b60ul, 0xb300000004000ul, 0xc0000000030000ul, 0x30000000b280000ul, 0x1000000088000000ul, 0x30000000bul, 0xb1000000050ul, 0x400000000300ul, 0xb000000021800ul, 0x80000000010000ul, 0x201000000880000ul, 0x10000000b000000ul, 0x8800000080000000ul, 0x202000000ul, 0x10000000bul, 0x8800000080ul, 0xb0000000203ul, 0x800000000100ul, 0x2040000008800ul, 0x10000000b0000ul, 0x88000000800000ul, 0xb00000002050000ul, 0x8000000001000000ul, 0x600000088000000ul, 0xb00000002ul, 0x8000000001ul, 0x20700000088ul, 0x30000000b00ul, 0x90000000c000ul, 0xb000000020800ul, 0x80000000010000ul, 0xb08000000880000ul, 0x6800000003000000ul, 0xba8000000ul, 0x2800000003ul, 0x30000000b88ul, 0xb60000000a000ul, 0x68000000030000ul, 0x30000000b500000ul, 0x2000000078000000ul, 0x300000008ul, 0x6e20646c756f4328ul, 0x6563616c7020746ful, 0x6f20686374617020ul, 0x206c6576656c206eul, 0x5453465453006425ul, 0x4544465453003130ul, 0x4c49574300304441ul, 0x570064322e322556ul, 0x64256425564c49ul, 0x5700304852554957ul, 0x4957003148525549ul, 0x49570054414c5053ul, 0x2564322e25642541ul, 0x494d49570064322eul, 0x554e49570053554eul, 0x435049570064254dul, 0x570046495700544eul, 0x57005245544e4549ul, 0x4957004b54534f49ul, 0x534957005354534ful, 0x4f49570032545243ul, 0x54534f4957004a42ul, 0x5347524649570049ul, 0x4e4f4c4f43495700ul, 0x454d4954495700ul, 0x534b4355534957ul, 0x4957005241504957ul, 0x49570053524c494bul, 0x495700534d544356ul, 0x505453005454534dul, 0x5042495700642542ul, 0x5245544e49006425ul, 0x414d495700434950ul, 0x642550ul)

[init]
def private c2da_lin_init_static_wi_stuff() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(26)) {
        let at = c2da_lin_static_wi_stuff_seg[s * 2]
        for (k in range(c2da_lin_static_wi_stuff_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_wi_stuff[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_wi_stuff() {
    if (length(c2da_fn_table1) < 177) {
        resize(c2da_fn_table1, 177)
    }
    c2da_fn_table1[175] = @@WI_loadCallback
    c2da_fn_table1[176] = @@WI_unloadCallback
}

[init]
def private c2da_lin_relink_init_wi_stuff() {
    c2da_relink_wi_stuff()
}
