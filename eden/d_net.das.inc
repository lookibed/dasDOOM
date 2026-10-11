[sideeffects]
def private c2da___bswap_16_1(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_1(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_1(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_1(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_1(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_1(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
var netcmds : int = default<int>

[sideeffects]
def private PlayerQuitGame(var player : int) {
    var player_num : uint = uint((player - 96) / 328)
    M_StringCopy(328192, 328304, 80ul)
    let c2da_fresh0 : int8 = int8(uint(int8(c2da_mem[328192 + 7])) + player_num)
    c2da_mem[328192 + 7] = uint8(c2da_fresh0)
    playeringame[int(player_num)] = 0u
    let c2da_fresh1 : uint = 328192u
    c2da_mem[96 + int(consoleplayer) * 328 + 232] = uint8(c2da_fresh1)
    c2da_mem[96 + int(consoleplayer) * 328 + 233] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[96 + int(consoleplayer) * 328 + 234] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[96 + int(consoleplayer) * 328 + 235] = uint8(c2da_fresh1 >> 0x18)
    c2da_mem[96 + int(consoleplayer) * 328 + 236] = 0u8
    c2da_mem[96 + int(consoleplayer) * 328 + 237] = 0u8
    c2da_mem[96 + int(consoleplayer) * 328 + 238] = 0u8
    c2da_mem[96 + int(consoleplayer) * 328 + 239] = 0u8
    if (demorecording != 0x0) {
        G_CheckDemoStatus()
    }
    return
}
[sideeffects]
def private RunTic(var cmds : int; var ingame : int) {
    for (i in urange(0u, 4u)) {
        if (demoplayback == 0 && playeringame[int(i)] != 0x0 && (uint(c2da_mem[ingame + int(i) * 4]) | uint(c2da_mem[ingame + int(i) * 4 + 1]) << 0x8 | uint(c2da_mem[ingame + int(i) * 4 + 2]) << 0x10 | uint(c2da_mem[ingame + int(i) * 4 + 3]) << 0x18) == 0) {
            PlayerQuitGame(96 + int(i) * 328)
        }
    }
    netcmds = int(cmds)  // nolint:PERF020
    if (advancedemo != 0x0) {
        D_DoAdvanceDemo()
    }
    G_Ticker()
    return
}
[sideeffects]
def private LoadGameSettings(var settings : int) {
    deathmatch = int(uint(c2da_mem[settings + 8]) | uint(c2da_mem[settings + 9]) << 0x8 | uint(c2da_mem[settings + 10]) << 0x10 | uint(c2da_mem[settings + 11]) << 0x18)
    startepisode = int(uint(c2da_mem[settings + 12]) | uint(c2da_mem[settings + 13]) << 0x8 | uint(c2da_mem[settings + 14]) << 0x10 | uint(c2da_mem[settings + 15]) << 0x18)
    startmap = int(uint(c2da_mem[settings + 28]) | uint(c2da_mem[settings + 29]) << 0x8 | uint(c2da_mem[settings + 30]) << 0x10 | uint(c2da_mem[settings + 31]) << 0x18)
    startskill = int(uint(c2da_mem[settings + 32]) | uint(c2da_mem[settings + 33]) << 0x8 | uint(c2da_mem[settings + 34]) << 0x10 | uint(c2da_mem[settings + 35]) << 0x18)
    startloadgame = int(uint(c2da_mem[settings + 52]) | uint(c2da_mem[settings + 53]) << 0x8 | uint(c2da_mem[settings + 54]) << 0x10 | uint(c2da_mem[settings + 55]) << 0x18)
    lowres_turn = uint(int(uint(c2da_mem[settings + 40]) | uint(c2da_mem[settings + 41]) << 0x8 | uint(c2da_mem[settings + 42]) << 0x10 | uint(c2da_mem[settings + 43]) << 0x18))
    nomonsters = uint(int(uint(c2da_mem[settings + 16]) | uint(c2da_mem[settings + 17]) << 0x8 | uint(c2da_mem[settings + 18]) << 0x10 | uint(c2da_mem[settings + 19]) << 0x18))
    fastparm = uint(int(uint(c2da_mem[settings + 20]) | uint(c2da_mem[settings + 21]) << 0x8 | uint(c2da_mem[settings + 22]) << 0x10 | uint(c2da_mem[settings + 23]) << 0x18))
    respawnparm = uint(int(uint(c2da_mem[settings + 24]) | uint(c2da_mem[settings + 25]) << 0x8 | uint(c2da_mem[settings + 26]) << 0x10 | uint(c2da_mem[settings + 27]) << 0x18))
    timelimit = int(uint(c2da_mem[settings + 48]) | uint(c2da_mem[settings + 49]) << 0x8 | uint(c2da_mem[settings + 50]) << 0x10 | uint(c2da_mem[settings + 51]) << 0x18)
    consoleplayer = int(uint(c2da_mem[settings + 64]) | uint(c2da_mem[settings + 65]) << 0x8 | uint(c2da_mem[settings + 66]) << 0x10 | uint(c2da_mem[settings + 67]) << 0x18)
    if (lowres_turn != 0x0) {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 328327, [])
    }
    for (i_0 in urange(0u, 4u)) {
        playeringame[int(i_0)] = uint(i_0 < uint(int(uint(c2da_mem[settings + 60]) | uint(c2da_mem[settings + 61]) << 0x8 | uint(c2da_mem[settings + 62]) << 0x10 | uint(c2da_mem[settings + 63]) << 0x18)) ? 1 : 0)
    }
    return
}
[sideeffects]
def private SaveGameSettings(var settings_0 : int) {
    let c2da_fresh2 : uint = uint(deathmatch)
    c2da_mem[settings_0 + 8] = uint8(c2da_fresh2)
    c2da_mem[settings_0 + 9] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[settings_0 + 10] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[settings_0 + 11] = uint8(c2da_fresh2 >> 0x18)
    let c2da_fresh3 : uint = uint(startepisode)
    c2da_mem[settings_0 + 12] = uint8(c2da_fresh3)
    c2da_mem[settings_0 + 13] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[settings_0 + 14] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[settings_0 + 15] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : uint = uint(startmap)
    c2da_mem[settings_0 + 28] = uint8(c2da_fresh4)
    c2da_mem[settings_0 + 29] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[settings_0 + 30] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[settings_0 + 31] = uint8(c2da_fresh4 >> 0x18)
    let c2da_fresh5 : int = int(startskill)
    let c2da_fresh6 : uint = uint(c2da_fresh5)
    c2da_mem[settings_0 + 32] = uint8(c2da_fresh6)
    c2da_mem[settings_0 + 33] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[settings_0 + 34] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[settings_0 + 35] = uint8(c2da_fresh6 >> 0x18)
    let c2da_fresh7 : uint = uint(startloadgame)
    c2da_mem[settings_0 + 52] = uint8(c2da_fresh7)
    c2da_mem[settings_0 + 53] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[settings_0 + 54] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[settings_0 + 55] = uint8(c2da_fresh7 >> 0x18)
    let c2da_fresh8 : int = int(gameversion)
    let c2da_fresh9 : uint = uint(c2da_fresh8)
    c2da_mem[settings_0 + 36] = uint8(c2da_fresh9)
    c2da_mem[settings_0 + 37] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[settings_0 + 38] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[settings_0 + 39] = uint8(c2da_fresh9 >> 0x18)
    let c2da_fresh10 : int = int(nomonsters)
    let c2da_fresh11 : uint = uint(c2da_fresh10)
    c2da_mem[settings_0 + 16] = uint8(c2da_fresh11)
    c2da_mem[settings_0 + 17] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[settings_0 + 18] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[settings_0 + 19] = uint8(c2da_fresh11 >> 0x18)
    let c2da_fresh12 : int = int(fastparm)
    let c2da_fresh13 : uint = uint(c2da_fresh12)
    c2da_mem[settings_0 + 20] = uint8(c2da_fresh13)
    c2da_mem[settings_0 + 21] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[settings_0 + 22] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[settings_0 + 23] = uint8(c2da_fresh13 >> 0x18)
    let c2da_fresh14 : int = int(respawnparm)
    let c2da_fresh15 : uint = uint(c2da_fresh14)
    c2da_mem[settings_0 + 24] = uint8(c2da_fresh15)
    c2da_mem[settings_0 + 25] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[settings_0 + 26] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[settings_0 + 27] = uint8(c2da_fresh15 >> 0x18)
    let c2da_fresh16 : uint = uint(timelimit)
    c2da_mem[settings_0 + 48] = uint8(c2da_fresh16)
    c2da_mem[settings_0 + 49] = uint8(c2da_fresh16 >> 0x8)
    c2da_mem[settings_0 + 50] = uint8(c2da_fresh16 >> 0x10)
    c2da_mem[settings_0 + 51] = uint8(c2da_fresh16 >> 0x18)
    let c2da_fresh17 : int = M_CheckParm(328434) > 0 && M_CheckParm(328442) == 0 ? 1 : 0
    let c2da_fresh18 : uint = uint(c2da_fresh17)
    c2da_mem[settings_0 + 40] = uint8(c2da_fresh18)
    c2da_mem[settings_0 + 41] = uint8(c2da_fresh18 >> 0x8)
    c2da_mem[settings_0 + 42] = uint8(c2da_fresh18 >> 0x10)
    c2da_mem[settings_0 + 43] = uint8(c2da_fresh18 >> 0x18)
    return
}
[sideeffects]
def private InitConnectData(var connect_data : int) {
    let c2da_fresh19 : int = 4
    let c2da_fresh20 : uint = uint(c2da_fresh19)
    c2da_mem[connect_data + 16] = uint8(c2da_fresh20)
    c2da_mem[connect_data + 17] = uint8(c2da_fresh20 >> 0x8)
    c2da_mem[connect_data + 18] = uint8(c2da_fresh20 >> 0x10)
    c2da_mem[connect_data + 19] = uint8(c2da_fresh20 >> 0x18)
    let c2da_fresh21 : int = 0
    let c2da_fresh22 : uint = uint(c2da_fresh21)
    c2da_mem[connect_data + 12] = uint8(c2da_fresh22)
    c2da_mem[connect_data + 13] = uint8(c2da_fresh22 >> 0x8)
    c2da_mem[connect_data + 14] = uint8(c2da_fresh22 >> 0x10)
    c2da_mem[connect_data + 15] = uint8(c2da_fresh22 >> 0x18)
    if (M_CheckParm(328452) > 0) {
        viewangleoffset = 1073741824
        let c2da_fresh23 : int = 1
        let c2da_fresh24 : uint = uint(c2da_fresh23)
        c2da_mem[connect_data + 12] = uint8(c2da_fresh24)
        c2da_mem[connect_data + 13] = uint8(c2da_fresh24 >> 0x8)
        c2da_mem[connect_data + 14] = uint8(c2da_fresh24 >> 0x10)
        c2da_mem[connect_data + 15] = uint8(c2da_fresh24 >> 0x18)
    }
    if (M_CheckParm(328458) > 0) {
        viewangleoffset = -1073741824
        let c2da_fresh25 : int = 1
        let c2da_fresh26 : uint = uint(c2da_fresh25)
        c2da_mem[connect_data + 12] = uint8(c2da_fresh26)
        c2da_mem[connect_data + 13] = uint8(c2da_fresh26 >> 0x8)
        c2da_mem[connect_data + 14] = uint8(c2da_fresh26 >> 0x10)
        c2da_mem[connect_data + 15] = uint8(c2da_fresh26 >> 0x18)
    }
    let c2da_fresh27 : int = int(gamemode)
    let c2da_fresh28 : uint = uint(c2da_fresh27)
    c2da_mem[connect_data] = uint8(c2da_fresh28)
    c2da_mem[connect_data + 1] = uint8(c2da_fresh28 >> 0x8)
    c2da_mem[connect_data + 2] = uint8(c2da_fresh28 >> 0x10)
    c2da_mem[connect_data + 3] = uint8(c2da_fresh28 >> 0x18)
    let c2da_fresh29 : int = int(uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18)
    let c2da_fresh30 : uint = uint(c2da_fresh29)
    c2da_mem[connect_data + 4] = uint8(c2da_fresh30)
    c2da_mem[connect_data + 5] = uint8(c2da_fresh30 >> 0x8)
    c2da_mem[connect_data + 6] = uint8(c2da_fresh30 >> 0x10)
    c2da_mem[connect_data + 7] = uint8(c2da_fresh30 >> 0x18)
    let c2da_fresh31 : int = M_CheckParm(328434) > 0 && M_CheckParm(328442) == 0 ? 1 : 0
    let c2da_fresh32 : uint = uint(c2da_fresh31)
    c2da_mem[connect_data + 8] = uint8(c2da_fresh32)
    c2da_mem[connect_data + 9] = uint8(c2da_fresh32 >> 0x8)
    c2da_mem[connect_data + 10] = uint8(c2da_fresh32 >> 0x10)
    c2da_mem[connect_data + 11] = uint8(c2da_fresh32 >> 0x18)
    W_Checksum(connect_data + 24)
    let c2da_fresh33 : int = W_CheckNumForName(328465) >= 0 ? 1 : 0
    let c2da_fresh34 : uint = uint(c2da_fresh33)
    c2da_mem[connect_data + 20] = uint8(c2da_fresh34)
    c2da_mem[connect_data + 21] = uint8(c2da_fresh34 >> 0x8)
    c2da_mem[connect_data + 22] = uint8(c2da_fresh34 >> 0x10)
    c2da_mem[connect_data + 23] = uint8(c2da_fresh34 >> 0x18)
    return
}
[export, sideeffects]
def D_ConnectNetGame() {
    let c2da_saved_sp : int = c2da_lin_sp
    D_ConnectNetGame_c2da_frame(c2da_lin_enter(80))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def D_CheckNetGame() {
    let c2da_saved_sp : int = c2da_lin_sp
    D_CheckNetGame_c2da_frame(c2da_lin_enter(112))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private D_ConnectNetGame_c2da_frame(c2da_fp : int) {
    InitConnectData(c2da_fp)
    netgame = uint(D_InitNetGame(c2da_fp))
    if (M_CheckParm(328474) > 0) {
        netgame = 1u
    }
    return
}
[sideeffects]
def private D_CheckNetGame_c2da_frame(c2da_fp : int) {
    if (netgame != 0x0) {
        autostart = 1u
    }
    D_RegisterLoopCallbacks(328272)
    SaveGameSettings(c2da_fp)
    D_StartNetGame(c2da_fp, 0)
    LoadGameSettings(c2da_fp)
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 328484, [C2daVaArg(tag = 1, i64 = int64(int(startskill)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(deathmatch), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(startmap), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(startepisode), f64 = 0.0lf, raw = 0x0)])
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 328547, [C2daVaArg(tag = 1, i64 = int64(consoleplayer + 1), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[c2da_fp + 60]) | uint(c2da_mem[c2da_fp + 61]) << 0x8 | uint(c2da_mem[c2da_fp + 62]) << 0x10 | uint(c2da_mem[c2da_fp + 63]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[c2da_fp + 60]) | uint(c2da_mem[c2da_fp + 61]) << 0x8 | uint(c2da_mem[c2da_fp + 62]) << 0x10 | uint(c2da_mem[c2da_fp + 63]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
    if (timelimit > 0 && deathmatch != 0) {
        if (timelimit == 20 && M_CheckParm(328575) != 0) {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 328580, [])
        } else {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 328637, [C2daVaArg(tag = 1, i64 = int64(timelimit), f64 = 0.0lf, raw = 0x0)])
            if (timelimit > 1) {
                c2da_lin_printf(uint64(int(c2da_std_stderr())), 328669, [])
            }
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 328671, [])
        }
    }
    return
}

// This unit's static data, at heap offset 328192.
let private c2da_lin_static_d_net_seg = fixed_array<int>(328272, 401)
let private c2da_lin_static_d_net = fixed_array<uint64>(0x6ul, 0x7ul, 0x9bul, 0x8ul, 0x3120726579616c50ul, 0x6874207466656c20ul, 0x4e00656d61672065ul, 0x727554203a45544ful, 0x73657220676e696eul, 0x206e6f6974756c6ful, 0x6375646572207369ul, 0x73696874203b6465ul, 0x626f727020736920ul, 0x63656220796c6261ul, 0x6568742065737561ul, 0x2061207369206572ul, 0x7220746e65696c63ul, 0x676e6964726f6365ul, 0x6c696e6156206120ul, 0x2e6f6d656420616cul, 0x726f6365722d000aul, 0x74676e6f6c2d0064ul, 0x66656c2d00736369ul, 0x74686769722d0074ul, 0x4f4f444545524600ul, 0x2d6f6c6f732d004dul, 0x726174730074656eul, 0x25206c6c696b7374ul, 0x6874616564202069ul, 0x25203a686374616dul, 0x7472617473202069ul, 0x206925203a70616dul, 0x7065747261747320ul, 0x25203a65646f7369ul, 0x6579616c70000a69ul, 0x20666f2069252072ul, 0x6e20692528206925ul, 0x2d000a297365646ful, 0x7473754100677661ul, 0x7574726956206e69ul, 0x6e696d6147206c61ul, 0x6c6576654c203a67ul, 0x65206c6c69772073ul, 0x726574666120646eul, 0x756e696d20303220ul, 0x76654c000a736574ul, 0x6c6c697720736c65ul, 0x74666120646e6520ul, 0x696d206425207265ul, 0x2e0073006574756eul, 0xaul)

[init]
def private c2da_lin_init_static_d_net() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_d_net_seg[s * 2]
        for (k in range(c2da_lin_static_d_net_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_d_net[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_d_net() {
    if (length(c2da_fn_table1) < 156) {
        resize(c2da_fn_table1, 156)
    }
    c2da_fn_table1[155] = @@RunTic
}

[init]
def private c2da_lin_relink_init_d_net() {
    c2da_relink_d_net()
}
