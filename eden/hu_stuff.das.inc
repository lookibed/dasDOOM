var private HU_Responder__altdown : uint = 0u

var private HU_Responder__num_nobrainers : int = 0

[export, sideeffects]
def HU_Init() {
    let c2da_saved_sp : int = c2da_lin_sp
    HU_Init_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def HU_Start() {
    var c2da_fresh7 : uint
    var s : int
    if (headsupactive != 0x0) {
        HU_Stop()
    }
    plr_0 = 96 + int(consoleplayer) * 328
    let c2da_fresh2 : uint = 0u
    let c2da_fresh3 : uint = c2da_fresh2
    c2da_mem[340144] = uint8(c2da_fresh3)
    c2da_mem[340145] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[340146] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[340147] = uint8(c2da_fresh3 >> 0x18)
    message_dontfuckwithme = 0u
    message_nottobefuckedwith = 0u
    let c2da_fresh4 : uint = 0u
    let c2da_fresh5 : uint = c2da_fresh4
    c2da_mem[42032] = uint8(c2da_fresh5)
    c2da_mem[42033] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[42034] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[42035] = uint8(c2da_fresh5 >> 0x18)
    HUlib_initSText(339664, 0, 0, 1, 41520, 33, 340144)
    let c2da_fresh6 : int = int(uint(c2da_mem[41520 + 0 * 8]) | uint(c2da_mem[41520 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[41520 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[41520 + 0 * 8 + 3]) << 0x18) + 2
    HUlib_initTextLine(340160, 0, 167 - int(int16(uint(c2da_mem[c2da_fresh6]) | uint(c2da_mem[c2da_fresh6 + 1]) << 0x8)), 41520, 33)
    c2da_fresh7 = (uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 4u ? 0u : (uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 5u ? 1u : uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18
    if (c2da_fresh7 == 0x0u) {
        s = mapnames[int((gameepisode - 1) * 9 + gamemap - 1)]
    } elif (c2da_fresh7 == 0x1u) {
        s = mapnames_commercial[int(gamemap - 1)]
    } elif (c2da_fresh7 == 0x3u) {
        s = mapnames_commercial[int(gamemap - 1 + 32)]
    } elif (c2da_fresh7 == 0x2u) {
        s = mapnames_commercial[int(gamemap - 1 + 64)]
    } else {
        s = 341203
    }
    if (uint(gameversion) == 9u) {
        s = mapnames[int(gamemap - 1)]
    }
    s = s
    while (int8(c2da_mem[s]) != 0) {
        let c2da_fresh8 : int = s
        s++
        HUlib_addCharToTextLine(340160, int8(c2da_mem[c2da_fresh8]))
    }
    let c2da_fresh9 : int = int(uint(c2da_mem[41520 + 0 * 8]) | uint(c2da_mem[41520 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[41520 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[41520 + 0 * 8 + 3]) << 0x18) + 2
    HUlib_initIText(340272, 0, 0 + 1 * (int(int16(uint(c2da_mem[c2da_fresh9]) | uint(c2da_mem[c2da_fresh9 + 1]) << 0x8)) + 1), 41520, 33, 42032)
    for (i_0 in range(0, 4)) {
        HUlib_initIText(340416 + i_0 * 136, 0, 0, 0, 0, 340960)
    }
    headsupactive = 1u
    return
}
var private headsupactive : uint = 0u

var mapnames : int[45] = fixed_array<int>(341217, 341230, 341250, 341271, 341293, 341310, 341335, 341358, 341379, 341399, 341420, 341443, 341458, 341475, 341496, 341522, 341542, 341563, 341589, 341605, 341629, 341647, 341667, 341690, 341707, 341719, 341729, 341743, 341762, 341783, 341806, 341824, 341847, 341875, 341899, 341920, 341931, 341931, 341931, 341931, 341931, 341931, 341931, 341931, 341931)

var mapnames_commercial : int[96] = fixed_array<int>(341940, 341958, 341978, 341999, 342018, 342045, 342066, 342087, 342113, 342130, 342155, 342185, 342207, 342226, 342252, 342278, 342296, 342316, 342340, 342362, 342380, 342398, 342422, 342447, 342467, 342488, 342518, 342542, 342569, 342594, 342616, 342638, 342655, 342670, 342693, 342708, 342723, 342743, 342765, 342785, 342800, 342819, 342839, 342856, 342872, 342892, 342910, 342933, 342952, 342971, 342993, 343007, 343034, 343051, 343080, 343100, 343129, 343162, 343179, 343201, 343222, 343250, 343280, 343299, 343317, 343341, 343360, 343383, 343401, 343417, 343438, 343454, 343469, 343489, 343510, 343537, 343554, 343582, 343604, 343624, 343650, 343676, 343691, 343721, 343750, 343782, 343800, 343831, 343848, 343870, 343890, 343911, 343926, 343947, 343967, 343985)

var private message_nottobefuckedwith : uint = default<uint>

var message_dontfuckwithme : uint = default<uint>

var private plr_0 : int = default<int>

[export, sideeffects]
def HU_Stop() {
    headsupactive = 0u
    return
}
[export, sideeffects]
def HU_Responder(var ev : int) : uint {
    var macromessage : int
    var eatkey : uint
    var c : uint8
    var i_1 : int
    var numplayers : int
    eatkey = 0u
    numplayers = 0
    i_1 = 0
    while (i_1 < 4) {
        numplayers = int(uint(numplayers) + playeringame[i_1])
        i_1++
    }
    if (int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) == 128 + 54) {
        return 0u
    } elif (int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) == 128 + 56 || int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) == 128 + 56) {
        HU_Responder__altdown = uint((uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 0u ? 1 : 0)
        return 0u
    }
    if ((uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) != 0u) {
        return 0u
    }
    if ((uint(c2da_mem[42032]) | uint(c2da_mem[42033]) << 0x8 | uint(c2da_mem[42034]) << 0x10 | uint(c2da_mem[42035]) << 0x18) == 0) {
        if (int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) == int(uint(c2da_mem[42800]) | uint(c2da_mem[42801]) << 0x8 | uint(c2da_mem[42802]) << 0x10 | uint(c2da_mem[42803]) << 0x18)) {
            let c2da_fresh10 : uint = 1u
            let c2da_fresh11 : uint = c2da_fresh10
            c2da_mem[340144] = uint8(c2da_fresh11)
            c2da_mem[340145] = uint8(c2da_fresh11 >> 0x8)
            c2da_mem[340146] = uint8(c2da_fresh11 >> 0x10)
            c2da_mem[340147] = uint8(c2da_fresh11 >> 0x18)
            message_counter = 4 * 35
            eatkey = 1u
        } elif (netgame != 0x0 && int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18) == int(uint(c2da_mem[43968]) | uint(c2da_mem[43969]) << 0x8 | uint(c2da_mem[43970]) << 0x10 | uint(c2da_mem[43971]) << 0x18)) {
            let c2da_fresh12 : uint = 1u
            let c2da_fresh13 : uint = c2da_fresh12
            c2da_mem[42032] = uint8(c2da_fresh13)
            c2da_mem[42033] = uint8(c2da_fresh13 >> 0x8)
            c2da_mem[42034] = uint8(c2da_fresh13 >> 0x10)
            c2da_mem[42035] = uint8(c2da_fresh13 >> 0x18)
            eatkey = c2da_fresh12
            HUlib_resetIText(340272)
            HU_queueChatChar(int8(5))
        } elif (netgame != 0x0 && numplayers > 2) {
            i_1 = 0
            for (c2da_i_1 in range(i_1, 4)) {
                if (int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18) == int(uint(c2da_mem[43984 + c2da_i_1 * 4]) | uint(c2da_mem[43984 + c2da_i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[43984 + c2da_i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[43984 + c2da_i_1 * 4 + 3]) << 0x18)) {
                    if (playeringame[c2da_i_1] != 0x0 && c2da_i_1 != consoleplayer) {
                        let c2da_fresh14 : uint = 1u
                        let c2da_fresh15 : uint = c2da_fresh14
                        c2da_mem[42032] = uint8(c2da_fresh15)
                        c2da_mem[42033] = uint8(c2da_fresh15 >> 0x8)
                        c2da_mem[42034] = uint8(c2da_fresh15 >> 0x10)
                        c2da_mem[42035] = uint8(c2da_fresh15 >> 0x18)
                        eatkey = c2da_fresh14
                        HUlib_resetIText(340272)
                        HU_queueChatChar(int8(c2da_i_1 + 1))
                        break
                    } elif (c2da_i_1 == consoleplayer) {
                        HU_Responder__num_nobrainers++
                        if (HU_Responder__num_nobrainers < 3) {
                            let c2da_fresh16 : uint = 344005u
                            c2da_mem[plr_0 + 232] = uint8(c2da_fresh16)
                            c2da_mem[plr_0 + 233] = uint8(c2da_fresh16 >> 0x8)
                            c2da_mem[plr_0 + 234] = uint8(c2da_fresh16 >> 0x10)
                            c2da_mem[plr_0 + 235] = uint8(c2da_fresh16 >> 0x18)
                            c2da_mem[plr_0 + 236] = 0u8
                            c2da_mem[plr_0 + 237] = 0u8
                            c2da_mem[plr_0 + 238] = 0u8
                            c2da_mem[plr_0 + 239] = 0u8
                        } elif (HU_Responder__num_nobrainers < 6) {
                            let c2da_fresh17 : uint = 344028u
                            c2da_mem[plr_0 + 232] = uint8(c2da_fresh17)
                            c2da_mem[plr_0 + 233] = uint8(c2da_fresh17 >> 0x8)
                            c2da_mem[plr_0 + 234] = uint8(c2da_fresh17 >> 0x10)
                            c2da_mem[plr_0 + 235] = uint8(c2da_fresh17 >> 0x18)
                            c2da_mem[plr_0 + 236] = 0u8
                            c2da_mem[plr_0 + 237] = 0u8
                            c2da_mem[plr_0 + 238] = 0u8
                            c2da_mem[plr_0 + 239] = 0u8
                        } elif (HU_Responder__num_nobrainers < 9) {
                            let c2da_fresh18 : uint = 344041u
                            c2da_mem[plr_0 + 232] = uint8(c2da_fresh18)
                            c2da_mem[plr_0 + 233] = uint8(c2da_fresh18 >> 0x8)
                            c2da_mem[plr_0 + 234] = uint8(c2da_fresh18 >> 0x10)
                            c2da_mem[plr_0 + 235] = uint8(c2da_fresh18 >> 0x18)
                            c2da_mem[plr_0 + 236] = 0u8
                            c2da_mem[plr_0 + 237] = 0u8
                            c2da_mem[plr_0 + 238] = 0u8
                            c2da_mem[plr_0 + 239] = 0u8
                        } elif (HU_Responder__num_nobrainers < 32) {
                            let c2da_fresh19 : uint = 344060u
                            c2da_mem[plr_0 + 232] = uint8(c2da_fresh19)
                            c2da_mem[plr_0 + 233] = uint8(c2da_fresh19 >> 0x8)
                            c2da_mem[plr_0 + 234] = uint8(c2da_fresh19 >> 0x10)
                            c2da_mem[plr_0 + 235] = uint8(c2da_fresh19 >> 0x18)
                            c2da_mem[plr_0 + 236] = 0u8
                            c2da_mem[plr_0 + 237] = 0u8
                            c2da_mem[plr_0 + 238] = 0u8
                            c2da_mem[plr_0 + 239] = 0u8
                        } else {
                            let c2da_fresh20 : uint = 344078u
                            c2da_mem[plr_0 + 232] = uint8(c2da_fresh20)
                            c2da_mem[plr_0 + 233] = uint8(c2da_fresh20 >> 0x8)
                            c2da_mem[plr_0 + 234] = uint8(c2da_fresh20 >> 0x10)
                            c2da_mem[plr_0 + 235] = uint8(c2da_fresh20 >> 0x18)
                            c2da_mem[plr_0 + 236] = 0u8
                            c2da_mem[plr_0 + 237] = 0u8
                            c2da_mem[plr_0 + 238] = 0u8
                            c2da_mem[plr_0 + 239] = 0u8
                        }
                    }
                }
            }
        }
    } elif (HU_Responder__altdown != 0x0) {
        c = uint8(int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) - 48)
        if (int(c) > 9) {
            return 0u
        }
        macromessage = int(uint(c2da_mem[1984 + int(c) * 8]) | uint(c2da_mem[1984 + int(c) * 8 + 1]) << 0x8 | uint(c2da_mem[1984 + int(c) * 8 + 2]) << 0x10 | uint(c2da_mem[1984 + int(c) * 8 + 3]) << 0x18)
        HU_queueChatChar(int8(13))
        while (int8(c2da_mem[macromessage]) != 0) {
            let c2da_fresh21 : int = macromessage
            macromessage++
            HU_queueChatChar(int8(c2da_mem[c2da_fresh21]))
        }
        HU_queueChatChar(int8(13))
        let c2da_fresh22 : uint = 0u
        let c2da_fresh23 : uint = c2da_fresh22
        c2da_mem[42032] = uint8(c2da_fresh23)
        c2da_mem[42033] = uint8(c2da_fresh23 >> 0x8)
        c2da_mem[42034] = uint8(c2da_fresh23 >> 0x10)
        c2da_mem[42035] = uint8(c2da_fresh23 >> 0x18)
        M_StringCopy(340976, int(uint(c2da_mem[1984 + int(c) * 8]) | uint(c2da_mem[1984 + int(c) * 8 + 1]) << 0x8 | uint(c2da_mem[1984 + int(c) * 8 + 2]) << 0x10 | uint(c2da_mem[1984 + int(c) * 8 + 3]) << 0x18), 81ul)
        let c2da_fresh24 : uint = 340976u
        c2da_mem[plr_0 + 232] = uint8(c2da_fresh24)
        c2da_mem[plr_0 + 233] = uint8(c2da_fresh24 >> 0x8)
        c2da_mem[plr_0 + 234] = uint8(c2da_fresh24 >> 0x10)
        c2da_mem[plr_0 + 235] = uint8(c2da_fresh24 >> 0x18)
        c2da_mem[plr_0 + 236] = 0u8
        c2da_mem[plr_0 + 237] = 0u8
        c2da_mem[plr_0 + 238] = 0u8
        c2da_mem[plr_0 + 239] = 0u8
        eatkey = 1u
    } else {
        c = uint8(int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18))
        eatkey = uint(HUlib_keyInIText(340272, c))
        if (eatkey != 0x0) {
            HU_queueChatChar(int8(c))
        }
        if (int(c) == 13) {
            let c2da_fresh25 : uint = 0u
            let c2da_fresh26 : uint = c2da_fresh25
            c2da_mem[42032] = uint8(c2da_fresh26)
            c2da_mem[42033] = uint8(c2da_fresh26 >> 0x8)
            c2da_mem[42034] = uint8(c2da_fresh26 >> 0x10)
            c2da_mem[42035] = uint8(c2da_fresh26 >> 0x18)
            if (int(uint(c2da_mem[340376]) | uint(c2da_mem[340377]) << 0x8 | uint(c2da_mem[340378]) << 0x10 | uint(c2da_mem[340379]) << 0x18) != 0) {
                M_StringCopy(340976, 340292, 81ul)
                let c2da_fresh27 : uint = 340976u
                c2da_mem[plr_0 + 232] = uint8(c2da_fresh27)
                c2da_mem[plr_0 + 233] = uint8(c2da_fresh27 >> 0x8)
                c2da_mem[plr_0 + 234] = uint8(c2da_fresh27 >> 0x10)
                c2da_mem[plr_0 + 235] = uint8(c2da_fresh27 >> 0x18)
                c2da_mem[plr_0 + 236] = 0u8
                c2da_mem[plr_0 + 237] = 0u8
                c2da_mem[plr_0 + 238] = 0u8
                c2da_mem[plr_0 + 239] = 0u8
            }
        } elif (int(c) == 27) {
            let c2da_fresh28 : uint = 0u
            let c2da_fresh29 : uint = c2da_fresh28
            c2da_mem[42032] = uint8(c2da_fresh29)
            c2da_mem[42033] = uint8(c2da_fresh29 >> 0x8)
            c2da_mem[42034] = uint8(c2da_fresh29 >> 0x10)
            c2da_mem[42035] = uint8(c2da_fresh29 >> 0x18)
        }
    }
    return eatkey
}
[export, sideeffects]
def HU_queueChatChar(var c_0 : int8) {
    if ((head + 1 & 128 - 1) == tail) {
        let c2da_fresh30 : uint = 344096u
        c2da_mem[plr_0 + 232] = uint8(c2da_fresh30)
        c2da_mem[plr_0 + 233] = uint8(c2da_fresh30 >> 0x8)
        c2da_mem[plr_0 + 234] = uint8(c2da_fresh30 >> 0x10)
        c2da_mem[plr_0 + 235] = uint8(c2da_fresh30 >> 0x18)
        c2da_mem[plr_0 + 236] = 0u8
        c2da_mem[plr_0 + 237] = 0u8
        c2da_mem[plr_0 + 238] = 0u8
        c2da_mem[plr_0 + 239] = 0u8
    } else {
        chatchars[head] = int8(c_0)  // nolint:PERF020
        head = head + 1 & 128 - 1
    }
    return
}
var private head : int = 0

var private chatchars : int8[128]

var private tail : int = 0

var private message_counter : int = default<int>

[export, sideeffects]
def HU_Ticker() {
    var rc : int
    var c_1 : int8
    var c2da_fresh31 : int = 0
    if (message_counter != 0) {
        message_counter--
        if (message_counter == 0) {
            c2da_fresh31 = 1
        }
    }
    if (c2da_fresh31 != 0) {
        let c2da_fresh32 : uint = 0u
        let c2da_fresh33 : uint = c2da_fresh32
        c2da_mem[340144] = uint8(c2da_fresh33)
        c2da_mem[340145] = uint8(c2da_fresh33 >> 0x8)
        c2da_mem[340146] = uint8(c2da_fresh33 >> 0x10)
        c2da_mem[340147] = uint8(c2da_fresh33 >> 0x18)
        message_nottobefuckedwith = 0u
    }
    if (int(uint(c2da_mem[1872]) | uint(c2da_mem[1873]) << 0x8 | uint(c2da_mem[1874]) << 0x10 | uint(c2da_mem[1875]) << 0x18) != 0 || message_dontfuckwithme != 0x0) {
        if (int(uint(c2da_mem[plr_0 + 232]) | uint(c2da_mem[plr_0 + 233]) << 0x8 | uint(c2da_mem[plr_0 + 234]) << 0x10 | uint(c2da_mem[plr_0 + 235]) << 0x18) != 0 && message_nottobefuckedwith == 0 || int(uint(c2da_mem[plr_0 + 232]) | uint(c2da_mem[plr_0 + 233]) << 0x8 | uint(c2da_mem[plr_0 + 234]) << 0x10 | uint(c2da_mem[plr_0 + 235]) << 0x18) != 0 && message_dontfuckwithme != 0x0) {
            HUlib_addMessageToSText(339664, 0, int(uint(c2da_mem[plr_0 + 232]) | uint(c2da_mem[plr_0 + 233]) << 0x8 | uint(c2da_mem[plr_0 + 234]) << 0x10 | uint(c2da_mem[plr_0 + 235]) << 0x18))
            let c2da_fresh34 : uint = 0u
            c2da_mem[plr_0 + 232] = uint8(c2da_fresh34)
            c2da_mem[plr_0 + 233] = uint8(c2da_fresh34 >> 0x8)
            c2da_mem[plr_0 + 234] = uint8(c2da_fresh34 >> 0x10)
            c2da_mem[plr_0 + 235] = uint8(c2da_fresh34 >> 0x18)
            c2da_mem[plr_0 + 236] = 0u8
            c2da_mem[plr_0 + 237] = 0u8
            c2da_mem[plr_0 + 238] = 0u8
            c2da_mem[plr_0 + 239] = 0u8
            let c2da_fresh35 : uint = 1u
            let c2da_fresh36 : uint = c2da_fresh35
            c2da_mem[340144] = uint8(c2da_fresh36)
            c2da_mem[340145] = uint8(c2da_fresh36 >> 0x8)
            c2da_mem[340146] = uint8(c2da_fresh36 >> 0x10)
            c2da_mem[340147] = uint8(c2da_fresh36 >> 0x18)
            message_counter = 4 * 35
            message_nottobefuckedwith = uint(message_dontfuckwithme)  // nolint:PERF020
            message_dontfuckwithme = 0u
        }
    }
    if (netgame != 0x0) {
        for (i_2 in range(0, 4)) {
            if (playeringame[i_2] == 0) {
                continue
            }
            var c2da_fresh37 : int = 0
            if (i_2 != consoleplayer) {
                c_1 = int8(c2da_mem[96 + i_2 * 328 + 16])
                if (int(c_1) != 0) {
                    c2da_fresh37 = 1
                }
            }
            if (c2da_fresh37 != 0) {
                if (int(c_1) <= 5) {
                    chat_dest[i_2] = c_1
                } else {
                    rc = int(HUlib_keyInIText(340416 + i_2 * 136, uint8(c_1)))
                    if (rc != 0 && int(c_1) == 13) {
                        if (int(uint(c2da_mem[340416 + i_2 * 136 + 104]) | uint(c2da_mem[340416 + i_2 * 136 + 105]) << 0x8 | uint(c2da_mem[340416 + i_2 * 136 + 106]) << 0x10 | uint(c2da_mem[340416 + i_2 * 136 + 107]) << 0x18) != 0 && (int(chat_dest[i_2]) == consoleplayer + 1 || int(chat_dest[i_2]) == 5)) {
                            HUlib_addMessageToSText(339664, player_names[i_2], 340416 + i_2 * 136 + 20)
                            message_nottobefuckedwith = 1u
                            let c2da_fresh38 : uint = 1u
                            let c2da_fresh39 : uint = c2da_fresh38
                            c2da_mem[340144] = uint8(c2da_fresh39)
                            c2da_mem[340145] = uint8(c2da_fresh39 >> 0x8)
                            c2da_mem[340146] = uint8(c2da_fresh39 >> 0x10)
                            c2da_mem[340147] = uint8(c2da_fresh39 >> 0x18)
                            message_counter = 4 * 35
                            if (uint(gamemode) == 2u) {
                                S_StartSound(0, 108)
                            } else {
                                S_StartSound(0, 87)
                            }
                        }
                        HUlib_resetIText(340416 + i_2 * 136)
                    }
                }
                let c2da_fresh40 : uint8 = 0u8
                c2da_mem[96 + i_2 * 328 + 16] = c2da_fresh40
            }
        }
    }
    return
}
var player_names : int[4] = fixed_array<int>(344113, 344121, 344130, 344138)

var private chat_dest : int8[4]

[export, sideeffects]
def HU_Drawer() {
    HUlib_drawSText(339664)
    HUlib_drawIText(340272)
    if (automapactive != 0x0) {
        HUlib_drawTextLine(340160, 0u)
    }
    return
}
[export, sideeffects]
def HU_dequeueChatChar() : int8 {
    var c_2 : int8
    if (head != tail) {
        c_2 = chatchars[tail]
        tail = tail + 1 & 128 - 1
    } else {
        c_2 = int8(0)
    }
    return c_2
}
[export, sideeffects]
def HU_Erase() {
    HUlib_eraseSText(339664)
    HUlib_eraseIText(340272)
    HUlib_eraseTextLine(340160)
    return
}
var chat_char : int8 = default<int8>

[sideeffects]
def private HU_Init_c2da_frame(c2da_fp : int) {
    var j : int = 33
    for (i in range(0, 95 - 33 + 1)) {
        let c2da_postinc : int = j
        j++
        c2da_lin_snprintf(c2da_fp, 9ul, 341193, [C2daVaArg(tag = 1, i64 = int64(c2da_postinc), f64 = 0.0lf, raw = 0x0)])
        let c2da_fresh0 : int = W_CacheLumpName(c2da_fp, 1)
        let c2da_fresh1 : uint = uint(c2da_fresh0)
        c2da_mem[41520 + i * 8] = uint8(c2da_fresh1)
        c2da_mem[41520 + i * 8 + 1] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[41520 + i * 8 + 2] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[41520 + i * 8 + 3] = uint8(c2da_fresh1 >> 0x18)
        c2da_mem[41520 + i * 8 + 4] = 0u8
        c2da_mem[41520 + i * 8 + 5] = 0u8
        c2da_mem[41520 + i * 8 + 6] = 0u8
        c2da_mem[41520 + i * 8 + 7] = 0u8
    }
    return
}

// This unit's static data, at heap offset 339664.
let private c2da_lin_static_hu_stuff_seg = fixed_array<int>(341057, 3086)
let private c2da_lin_static_hu_stuff = fixed_array<uint64>(0x72206d2749006f4eul, 0x206f742079646165ul, 0x747562206b63696bul, 0x4f206d2749002174ul, 0x6e206d2749002e4bul, 0x696b6f6f6c20746ful, 0x67206f6f7420676eul, 0x6c65480021646f6ful, 0x7320756f59002170ul, 0x78654e00216b6375ul, 0x202c656d69742074ul, 0x2e6761626d756373ul, 0x20656d6f43002e2eul, 0x2749002165726568ul, 0x20656b6174206c6cul, 0x20666f2065726163ul, 0x736559002e7469ul, 0x332e254e46435453ul, 0x776f6e6b6e550064ul, 0x6c6576656c206eul, 0x6148203a314d3145ul, 0x4d3145007261676eul, 0x656c63754e203a32ul, 0x746e616c50207261ul, 0x54203a334d314500ul, 0x666552206e69786ful, 0x3145007972656e69ul, 0x6d6d6f43203a344dul, 0x746e6f4320646e61ul, 0x354d3145006c6f72ul, 0x736f626f6850203aul, 0x4d31450062614c20ul, 0x72746e6543203a36ul, 0x65636f7250206c61ul, 0x314500676e697373ul, 0x706d6f43203a374dul, 0x6174532072657475ul, 0x4d3145006e6f6974ul, 0x6f626f6850203a38ul, 0x6c616d6f6e412073ul, 0x203a394d31450079ul, 0x79726174696c694dul, 0x3245006573614220ul, 0x6d696544203a314dul, 0x616d6f6e4120736ful, 0x3a324d324500796cul, 0x6e6961746e6f4320ul, 0x65724120746e656dul, 0x203a334d32450061ul, 0x7972656e69666552ul, 0x44203a344d324500ul, 0x614c20736f6d6965ul, 0x203a354d32450062ul, 0x20646e616d6d6f43ul, 0x45007265746e6543ul, 0x6c6148203a364d32ul, 0x687420666f20736cul, 0x64656e6d61442065ul, 0x53203a374d324500ul, 0x20676e696e776170ul, 0x4d32450073746156ul, 0x7265776f54203a38ul, 0x6562614220666f20ul, 0x203a394d3245006cul, 0x7373657274726f46ul, 0x7473794d20666f20ul, 0x314d334500797265ul, 0x4b206c6c6548203aul, 0x324d334500706565ul, 0x6867756f6c53203aul, 0x7073654420666f20ul, 0x334d334500726961ul, 0x6d65646e6150203aul, 0x3345006d75696e6ful, 0x73756f48203a344dul, 0x69615020666f2065ul, 0x203a354d3345006eul, 0x4320796c6f686e55ul, 0x6c61726465687461ul, 0x4d203a364d334500ul, 0x7562657245202e74ul, 0x203a374d33450073ul, 0x3345006f626d694cul, 0x736944203a384dul, 0x6157203a394d3345ul, 0x344500736e657272ul, 0x6c6c6548203a314dul, 0x687461656e654220ul, 0x50203a324d344500ul, 0x4820746365667265ul, 0x3445006465727461ul, 0x65766553203a334dul, 0x6957206568542072ul, 0x4d34450064656b63ul, 0x6c75726e55203a34ul, 0x45006c6976452079ul, 0x656854203a354d34ul, 0x52206c6c69572079ul, 0x344500746e657065ul, 0x69616741203a364dul, 0x656568542074736eul, 0x6c64656b63695720ul, 0x203a374d34450079ul, 0x6c6c654820646e41ul, 0x65776f6c6c6f4620ul, 0x203a384d34450064ul, 0x656854206f746e55ul, 0x45006c6575724320ul, 0x616546203a394d34ul, 0x56454c57454e0072ul, 0x6c6576656c004c45ul, 0x72746e65203a3120ul, 0x76656c0079617779ul, 0x6e75203a32206c65ul, 0x736c6c6168726564ul, 0x33206c6576656c00ul, 0x616720656874203aul, 0x656c0074656c746eul, 0x74203a34206c6576ul, 0x7375636f66206568ul, 0x35206c6576656c00ul, 0x617720656874203aul, 0x6e6e757420657473ul, 0x6576656c00736c65ul, 0x656874203a36206cul, 0x7265687375726320ul, 0x37206c6576656c00ul, 0x732064616564203aul, 0x656c00656c706d69ul, 0x74203a38206c6576ul, 0x6e6120736b636972ul, 0x73706172742064ul, 0x3a39206c6576656cul, 0x7469702065687420ul, 0x31206c6576656c00ul, 0x6575666572203a30ul, 0x73616220676e696cul, 0x206c6576656c0065ul, 0x20276f27203a3131ul, 0x727473656420666ful, 0x216e6f69746375ul, 0x3231206c6576656cul, 0x616620656874203aul, 0x656c0079726f7463ul, 0x203a3331206c6576ul, 0x6e776f746e776f64ul, 0x31206c6576656c00ul, 0x6920656874203a34ul, 0x65642074736f6d6eul, 0x6c6576656c00736eul, 0x646e69203a353120ul, 0x206c616972747375ul, 0x76656c00656e6f7aul, 0x73203a3631206c65ul, 0x6c00736272756275ul, 0x3a3731206c657665ul, 0x6e656d656e657420ul, 0x6c6576656c007374ul, 0x656874203a383120ul, 0x61797472756f6320ul, 0x6c6576656c006472ul, 0x656874203a393120ul, 0x6c65646174696320ul, 0x32206c6576656c00ul, 0x6863746f67203a30ul, 0x6c6576656c002161ul, 0x72696e203a313220ul, 0x76656c00616e6176ul, 0x74203a3232206c65ul, 0x6361746163206568ul, 0x76656c0073626d6ful, 0x62203a3332206c65ul, 0x6f20736c65727261ul, 0x656c006e75662027ul, 0x203a3432206c6576ul, 0x7361686320656874ul, 0x206c6576656c006dul, 0x6f6f6c62203a3532ul, 0x6c00736c6c616664ul, 0x3a3632206c657665ul, 0x6162612065687420ul, 0x6d2064656e6f646eul, 0x76656c0073656e69ul, 0x6d203a3732206c65ul, 0x6320726574736e6ful, 0x76656c006f646e6ful, 0x74203a3832206c65ul, 0x6972697073206568ul, 0x646c726f772074ul, 0x3932206c6576656cul, 0x696c20656874203aul, 0x646e6520676e6976ul, 0x33206c6576656c00ul, 0x206e6f6369203a30ul, 0x6c006e697320666ful, 0x3a3133206c657665ul, 0x736e65666c6f7720ul, 0x76656c006e696574ul, 0x67203a3233206c65ul, 0x656c006573736f72ul, 0x63203a31206c6576ul, 0x76656c006f676e6ful, 0x6577203a32206c65ul, 0x6f7320666f206c6cul, 0x6576656c00736c75ul, 0x747a61203a33206cul, 0x6c6576656c006365ul, 0x65676163203a3420ul, 0x206c6576656c0064ul, 0x74736f6867203a35ul, 0x656c006e776f7420ul, 0x62203a36206c6576ul, 0x6c2073276e6f7261ul, 0x6576656c00726961ul, 0x756163203a37206cul, 0x64726179746867ul, 0x3a38206c6576656cul, 0x6c006d6c61657220ul, 0x203a39206c657665ul, 0x72696f7474616261ul, 0x206c6576656c0065ul, 0x6c736e6f203a3031ul, 0x656c007468677561ul, 0x203a3131206c6576ul, 0x6c006465746e7568ul, 0x3a3231206c657665ul, 0x6c00646565707320ul, 0x3a3331206c657665ul, 0x7972632065687420ul, 0x6c6576656c007470ul, 0x6e6567203a343120ul, 0x76656c0073697365ul, 0x74203a3531206c65ul, 0x696c697774206568ul, 0x6576656c00746867ul, 0x6874203a3631206cul, 0x6c006e656d6f2065ul, 0x3a3731206c657665ul, 0x6e756f706d6f6320ul, 0x206c6576656c0064ul, 0x7275656e203a3831ul, 0x6572656870736ful, 0x3931206c6576656cul, 0x656c00656d6e203aul, 0x203a3032206c6576ul, 0x7461656420656874ul, 0x6e69616d6f642068ul, 0x32206c6576656c00ul, 0x6579616c73203a31ul, 0x206c6576656c0072ul, 0x6f706d69203a3232ul, 0x6d20656c62697373ul, 0x6c006e6f69737369ul, 0x3a3332206c657665ul, 0x6f7473626d6f7420ul, 0x6c6576656c00656eul, 0x656874203a343220ul, 0x66206c616e696620ul, 0x726569746e6f72ul, 0x3532206c6576656cul, 0x657420656874203aul, 0x20666f20656c706dul, 0x7373656e6b726164ul, 0x32206c6576656c00ul, 0x656b6e7562203a36ul, 0x206c6576656c0072ul, 0x69746e61203a3732ul, 0x7473697268632dul, 0x3832206c6576656cul, 0x657320656874203aul, 0x76656c0073726577ul, 0x6f203a3932206c65ul, 0x6f20796573737964ul, 0x736573696f6e2066ul, 0x33206c6576656c00ul, 0x6720656874203a30ul, 0x6f20796177657461ul, 0x6c006c6c65682066ul, 0x3a3133206c657665ul, 0x6564726562796320ul, 0x206c6576656c006eul, 0x32206f67203a3233ul, 0x6576656c00746920ul, 0x737973203a31206cul, 0x746e6f63206d6574ul, 0x6576656c006c6f72ul, 0x6d7568203a32206cul, 0x6c00716262206e61ul, 0x203a33206c657665ul, 0x6f63207265776f70ul, 0x656c006c6f72746eul, 0x77203a34206c6576ul, 0x656c6f686d726ful, 0x3a35206c6576656cul, 0x7265676e616820ul, 0x3a36206c6576656cul, 0x6573206e65706f20ul, 0x76656c006e6f7361ul, 0x7270203a37206c65ul, 0x76656c006e6f7369ul, 0x656d203a38206c65ul, 0x6576656c006c6174ul, 0x727473203a39206cul, 0x646c6f68676e6ful, 0x3031206c6576656cul, 0x706d65646572203aul, 0x76656c006e6f6974ul, 0x73203a3131206c65ul, 0x6620656761726f74ul, 0x7974696c696361ul, 0x3231206c6576656cul, 0x726574617263203aul, 0x31206c6576656c00ul, 0x67616b756e203a33ul, 0x7365636f72702065ul, 0x76656c00676e6973ul, 0x73203a3431206c65ul, 0x726f77206c656574ul, 0x6c6576656c00736bul, 0x616564203a353120ul, 0x6c00656e6f7a2064ul, 0x3a3631206c657665ul, 0x7473657065656420ul, 0x7365686361657220ul, 0x31206c6576656c00ul, 0x65636f7270203a37ul, 0x726120676e697373ul, 0x6c6576656c006165ul, 0x6c696d203a383120ul, 0x206c6576656c006cul, 0x70696873203a3931ul, 0x7365722f676e6970ul, 0x676e696e776170ul, 0x3032206c6576656cul, 0x6172746e6563203aul, 0x7365636f7270206cul, 0x76656c00676e6973ul, 0x61203a3132206c65ul, 0x727473696e696d64ul, 0x6563206e6f697461ul, 0x76656c007265746eul, 0x68203a3232206c65ul, 0x6c00746174696261ul, 0x3a3332206c657665ul, 0x6d2072616e756c20ul, 0x727020676e696e69ul, 0x656c007463656a6ful, 0x203a3432206c6576ul, 0x6c00797272617571ul, 0x3a3532206c657665ul, 0x73276e6f72616220ul, 0x76656c006e656420ul, 0x62203a3632206c65ul, 0x78797473696c6c61ul, 0x32206c6576656c00ul, 0x746e756f6d203a37ul, 0x656c006e69617020ul, 0x203a3832206c6576ul, 0x76656c006b636568ul, 0x72203a3932206c65ul, 0x7974732072657669ul, 0x206c6576656c0078ul, 0x7473616c203a3033ul, 0x656c006c6c616320ul, 0x203a3133206c6576ul, 0x686f6172616870ul, 0x3233206c6576656cul, 0x626269726163203aul, 0x20756f59006e6165ul, 0x7420656c626d756dul, 0x657372756f79206ful, 0x73276f685700666cul, 0x3f657265687420ul, 0x7261637320756f59ul, 0x657372756f792065ul, 0x7320756f5900666cul, 0x206f742074726174ul, 0x756f590065766172ul, 0x74736f6c20657627ul, 0x5b002e2e2e746920ul, 0x206567617373654dul, 0x5d746e65736e75ul, 0x203a6e65657247ul, 0x203a6f6769646e49ul, 0x203a6e776f724200ul, 0x203a64655200ul)

[init]
def private c2da_lin_init_static_hu_stuff() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_hu_stuff_seg[s * 2]
        for (k in range(c2da_lin_static_hu_stuff_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_hu_stuff[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_hu_stuff_0 = fixed_array<uint8>(0x41, 0x34, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x44, 0x34, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5c, 0x34, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x64, 0x34, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7e, 0x34, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x84, 0x34, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8e, 0x34, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa4, 0x34, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0xaf, 0x34, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc5, 0x34, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_hu_stuff() {
    c2da_lin_setup()
    for (i in range(80)) {
        c2da_mem[1984 + i] = c2da_lin_extern_hu_stuff_0[i]
    }
}
