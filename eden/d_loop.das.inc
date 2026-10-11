var private TryRunTics__oldentertics : int = 0

[sideeffects]
def private c2da___bswap_16(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
[export, sideeffects]
def D_RegisterLoopCallbacks(var i : int) {
    loop_interface = int(i)  // nolint:PERF020
    return
}
var private loop_interface : int = 0

[export, sideeffects]
def NetUpdate() {
    var nowtime : int
    var newtics : int
    if (singletics != 0x0) {
        return
    }
    nowtime = GetAdjustedTime() / ticdup
    newtics = nowtime - lasttime
    lasttime = nowtime
    if (skiptics <= newtics) {
        newtics -= skiptics
        skiptics = 0
    } else {
        skiptics -= newtics
        newtics = 0
    }
    for (i_0 in range(0, newtics)) {
        if (BuildNewTic() == 0) {
            break
        }
    }
    return
}
[sideeffects]
def private BuildNewTic() : uint {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : uint = BuildNewTic_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
var private maketic : int = default<int>

var private localplayer : int = default<int>

var private new_sync : uint = 1u

var ticdup : int = default<int>

var gametic : int = default<int>

var private skiptics : int = 0

var lasttime : int = default<int>

[sideeffects]
def private GetAdjustedTime() : int {
    var time_ms : int = I_GetTimeMS()
    if (new_sync != 0x0) {
        time_ms += offsetms / (1 << 16)
    }
    return time_ms * 35 / 1000
}
var offsetms : int = default<int>

var singletics : uint = 0u

[export, sideeffects]
def D_QuitNetGame() {
    return
}
[export, sideeffects]
def TryRunTics() {
    var i_1 : int
    var lowtic : int
    var entertic : int
    var realtics : int
    var availabletics : int
    var counts : int
    var set : int
    entertic = I_GetTime() / ticdup
    realtics = entertic - TryRunTics__oldentertics
    TryRunTics__oldentertics = entertic
    if (singletics != 0x0) {
        BuildNewTic()
    } else {
        NetUpdate()
    }
    lowtic = GetLowTic()
    availabletics = lowtic - gametic / ticdup
    if (new_sync != 0x0) {
        counts = availabletics
    } else {
        if (realtics < availabletics - 1) {
            counts = realtics + 1
        } elif (realtics < availabletics) {
            counts = realtics
        } else {
            counts = availabletics
        }
        if (counts < 1) {
            counts = 1
        }
        if (net_client_connected != 0x0) {
            OldNetSync()
        }
    }
    if (counts < 1) {
        counts = 1
    }
    while (PlayersInGame() == 0 || lowtic < gametic / ticdup + counts) {
        NetUpdate()
        lowtic = GetLowTic()
        if (lowtic < gametic / ticdup) {
            I_Error(323648, [])
        }
        if (I_GetTime() / ticdup - entertic > 0) {
            return
        }
        I_Sleep(1)
    }
    while (true) {
        let c2da_postinc : int = counts
        counts--
        if (c2da_postinc == 0) {
            break
        }
        if (PlayersInGame() == 0) {
            return
        }
        set = 303136 + gametic / ticdup % 128 * 160
        if (net_client_connected == 0) {
            SinglePlayerClear(set)
        }
        i_1 = 0
        while (i_1 < ticdup) {
            if (gametic / ticdup > lowtic) {
                I_Error(323677, [])
            }
            c2da_lin_memcpy(323616, set + 128, 32ul)
            invoke(c2da_fn_table1[int(uint(c2da_mem[loop_interface + 16]) | uint(c2da_mem[loop_interface + 17]) << 0x8 | uint(c2da_mem[loop_interface + 18]) << 0x10 | uint(c2da_mem[loop_interface + 19]) << 0x18)], set, set + 128)
            gametic++
            TicdupSquash(set)
            i_1++
        }
        NetUpdate()
    }
    return
}
[sideeffects]
def private TicdupSquash(var set_0 : int) {
    var cmd : int
    for (i_2 in urange(0u, 8u)) {
        cmd = set_0 + int(i_2) * 16
        let c2da_fresh4 : uint8 = 0u8
        c2da_mem[cmd + 4] = c2da_fresh4
        if ((int(c2da_mem[cmd + 5]) & 128) != 0) {
            let c2da_fresh5 : uint8 = 0u8
            c2da_mem[cmd + 5] = c2da_fresh5
        }
    }
    return
}
[sideeffects]
def private SinglePlayerClear(var set_1 : int) {
    for (i_3 in urange(0u, 8u)) {
        if (i_3 != uint(localplayer)) {
            let c2da_fresh6 : uint = 0u
            let c2da_fresh7 : uint = c2da_fresh6
            c2da_mem[set_1 + 128 + int(i_3) * 4] = uint8(c2da_fresh7)
            c2da_mem[set_1 + 128 + int(i_3) * 4 + 1] = uint8(c2da_fresh7 >> 0x8)
            c2da_mem[set_1 + 128 + int(i_3) * 4 + 2] = uint8(c2da_fresh7 >> 0x10)
            c2da_mem[set_1 + 128 + int(i_3) * 4 + 3] = uint8(c2da_fresh7 >> 0x18)
        }
    }
    return
}
[sideeffects]
def private PlayersInGame() : uint {
    var result_0 : uint = 0u
    if (net_client_connected != 0x0) {
        for (i_4 in urange(0u, 8u)) {
            result_0 = uint(result_0 != 0x0 || (uint(c2da_mem[323616 + int(i_4) * 4]) | uint(c2da_mem[323616 + int(i_4) * 4 + 1]) << 0x8 | uint(c2da_mem[323616 + int(i_4) * 4 + 2]) << 0x10 | uint(c2da_mem[323616 + int(i_4) * 4 + 3]) << 0x18) != 0x0 ? 1 : 0)
        }
    }
    if (drone == 0) {
        result_0 = 1u
    }
    return result_0
}
[sideeffects]
def private GetLowTic() : int {
    return maketic
}
[sideeffects]
def private OldNetSync() {
    var keyplayer : int = -1
    frameon++
    for (i_5 in urange(0u, 8u)) {
        if ((uint(c2da_mem[323616 + int(i_5) * 4]) | uint(c2da_mem[323616 + int(i_5) * 4 + 1]) << 0x8 | uint(c2da_mem[323616 + int(i_5) * 4 + 2]) << 0x10 | uint(c2da_mem[323616 + int(i_5) * 4 + 3]) << 0x18) != 0x0) {
            keyplayer = int(i_5)
            break
        }
    }
    if (keyplayer < 0) {
        return
    }
    if (localplayer != keyplayer) {
        if (maketic <= recvtic) {
            lasttime--
        }
        frameskip[frameon & 3] = oldnettics > recvtic ? 1 : 0
        oldnettics = int(maketic)  // nolint:PERF020
        if (frameskip[0] != 0 && frameskip[1] != 0 && frameskip[2] != 0 && frameskip[3] != 0) {
            skiptics = 1
        }
    }
    return
}
var private frameskip : int[4]

var private oldnettics : int = default<int>

var private recvtic : int = default<int>

var private frameon : int = default<int>

[export, sideeffects]
def D_StartGameLoop() {
    lasttime = GetAdjustedTime() / ticdup
    return
}
[export, sideeffects]
def D_InitNetGame(var connect_data : int) : uint {
    I_AtExit(1, 1u)
    player_class = int(uint(c2da_mem[connect_data + 64]) | uint(c2da_mem[connect_data + 65]) << 0x8 | uint(c2da_mem[connect_data + 66]) << 0x10 | uint(c2da_mem[connect_data + 67]) << 0x18)
    return 0u
}
var private player_class : int = default<int>

[export, sideeffects]
def D_StartNetGame(var settings : int; var callback : netgame_startup_callback_t) {
    let c2da_fresh8 : int = 0
    let c2da_fresh9 : uint = uint(c2da_fresh8)
    c2da_mem[settings + 64] = uint8(c2da_fresh9)
    c2da_mem[settings + 65] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[settings + 66] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[settings + 67] = uint8(c2da_fresh9 >> 0x18)
    let c2da_fresh10 : int = 1
    let c2da_fresh11 : uint = uint(c2da_fresh10)
    c2da_mem[settings + 60] = uint8(c2da_fresh11)
    c2da_mem[settings + 61] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[settings + 62] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[settings + 63] = uint8(c2da_fresh11 >> 0x18)
    let c2da_fresh12 : uint = uint(player_class)
    c2da_mem[settings + 68 + 0 * 4] = uint8(c2da_fresh12)
    c2da_mem[settings + 68 + 0 * 4 + 1] = uint8(c2da_fresh12 >> 0x8)
    c2da_mem[settings + 68 + 0 * 4 + 2] = uint8(c2da_fresh12 >> 0x10)
    c2da_mem[settings + 68 + 0 * 4 + 3] = uint8(c2da_fresh12 >> 0x18)
    let c2da_fresh13 : int = 0
    let c2da_fresh14 : uint = uint(c2da_fresh13)
    c2da_mem[settings + 44] = uint8(c2da_fresh14)
    c2da_mem[settings + 45] = uint8(c2da_fresh14 >> 0x8)
    c2da_mem[settings + 46] = uint8(c2da_fresh14 >> 0x10)
    c2da_mem[settings + 47] = uint8(c2da_fresh14 >> 0x18)
    let c2da_fresh15 : int = 1
    let c2da_fresh16 : uint = uint(c2da_fresh15)
    c2da_mem[settings + 4] = uint8(c2da_fresh16)
    c2da_mem[settings + 5] = uint8(c2da_fresh16 >> 0x8)
    c2da_mem[settings + 6] = uint8(c2da_fresh16 >> 0x10)
    c2da_mem[settings + 7] = uint8(c2da_fresh16 >> 0x18)
    let c2da_fresh17 : int = 1
    let c2da_fresh18 : uint = uint(c2da_fresh17)
    c2da_mem[settings] = uint8(c2da_fresh18)
    c2da_mem[settings + 1] = uint8(c2da_fresh18 >> 0x8)
    c2da_mem[settings + 2] = uint8(c2da_fresh18 >> 0x10)
    c2da_mem[settings + 3] = uint8(c2da_fresh18 >> 0x18)
    ticdup = int(uint(c2da_mem[settings]) | uint(c2da_mem[settings + 1]) << 0x8 | uint(c2da_mem[settings + 2]) << 0x10 | uint(c2da_mem[settings + 3]) << 0x18)
    new_sync = uint(int(uint(c2da_mem[settings + 44]) | uint(c2da_mem[settings + 45]) << 0x8 | uint(c2da_mem[settings + 46]) << 0x10 | uint(c2da_mem[settings + 47]) << 0x18))
    return
}
[sideeffects]
def private D_Disconnected() {
    if (drone != 0x0) {
        I_Error(323692, [])
    }
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 323732, [])
    return
}
[export, sideeffects]
def D_ReceiveTic(var ticcmds : int; var players_mask : int) {
    if (ticcmds == 0 && players_mask == 0) {
        D_Disconnected()
        return
    }
    for (i_6 in range(0, 8)) {
        if (!(drone == 0 && i_6 == localplayer)) {
            let c2da_fresh19 : int = 303136 + recvtic % 128 * 160 + i_6 * 16
            c2da_lin_memmove(c2da_fresh19, ticcmds + i_6 * 16, 16ul)
            let c2da_fresh20 : int = 303136 + recvtic % 128 * 160 + 128 + i_6 * 4
            let c2da_fresh21 : uint = uint(c2da_mem[players_mask + i_6 * 4]) | uint(c2da_mem[players_mask + i_6 * 4 + 1]) << 0x8 | uint(c2da_mem[players_mask + i_6 * 4 + 2]) << 0x10 | uint(c2da_mem[players_mask + i_6 * 4 + 3]) << 0x18
            let c2da_fresh22 : uint = c2da_fresh21
            c2da_mem[c2da_fresh20] = uint8(c2da_fresh22)
            c2da_mem[c2da_fresh20 + 1] = uint8(c2da_fresh22 >> 0x8)
            c2da_mem[c2da_fresh20 + 2] = uint8(c2da_fresh22 >> 0x10)
            c2da_mem[c2da_fresh20 + 3] = uint8(c2da_fresh22 >> 0x18)
        }
    }
    recvtic++
    return
}
[sideeffects]
def private BuildNewTic_c2da_frame(c2da_fp : int) : uint {
    var gameticdiv : int = gametic / ticdup
    I_StartTic()
    invoke(c2da_fn_table0[int(uint(c2da_mem[loop_interface]) | uint(c2da_mem[loop_interface + 1]) << 0x8 | uint(c2da_mem[loop_interface + 2]) << 0x10 | uint(c2da_mem[loop_interface + 3]) << 0x18)])
    invoke(c2da_fn_table0[int(uint(c2da_mem[loop_interface + 24]) | uint(c2da_mem[loop_interface + 25]) << 0x8 | uint(c2da_mem[loop_interface + 26]) << 0x10 | uint(c2da_mem[loop_interface + 27]) << 0x18)])
    if (drone != 0x0) {
        return 0u
    }
    if (new_sync != 0x0) {
        if (net_client_connected == 0 && maketic - gameticdiv > 2) {
            return 0u
        }
        if (maketic - gameticdiv > 8) {
            return 0u
        }
    } elif (maketic - gameticdiv >= 5) {
        return 0u
    }
    c2da_lin_memset(c2da_fp, 0, 16ul)
    invoke(c2da_fn_table1[int(uint(c2da_mem[loop_interface + 8]) | uint(c2da_mem[loop_interface + 9]) << 0x8 | uint(c2da_mem[loop_interface + 10]) << 0x10 | uint(c2da_mem[loop_interface + 11]) << 0x18)], c2da_fp, maketic)
    let c2da_fresh0 : int = 303136 + maketic % 128 * 160 + localplayer * 16
    c2da_lin_memmove(c2da_fresh0, c2da_fp, 16ul)
    let c2da_fresh1 : int = 303136 + maketic % 128 * 160 + 128 + localplayer * 4
    let c2da_fresh2 : uint = 1u
    let c2da_fresh3 : uint = c2da_fresh2
    c2da_mem[c2da_fresh1] = uint8(c2da_fresh3)
    c2da_mem[c2da_fresh1 + 1] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[c2da_fresh1 + 2] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[c2da_fresh1 + 3] = uint8(c2da_fresh3 >> 0x18)
    maketic++
    return 1u
}

// This unit's static data, at heap offset 303136.
let private c2da_lin_static_d_loop_seg = fixed_array<int>(323648, 110)
let private c2da_lin_static_d_loop = fixed_array<uint64>(0x69546e7552797254ul, 0x74776f6c203a7363ul, 0x6d6167203c206369ul, 0x6d61670063697465ul, 0x776f6c3e63697465ul, 0x6373694400636974ul, 0x64657463656e6e6ful, 0x6573206d6f726620ul, 0x206e692072657672ul, 0x6f6d20656e6f7264ul, 0x63736944002e6564ul, 0x64657463656e6e6ful, 0x6573206d6f726620ul, 0xa2e72657672ul)

[init]
def private c2da_lin_init_static_d_loop() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_d_loop_seg[s * 2]
        for (k in range(c2da_lin_static_d_loop_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_d_loop[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_d_loop() {
    if (length(c2da_fn_table0) < 2) {
        resize(c2da_fn_table0, 2)
    }
    c2da_fn_table0[1] = @@D_QuitNetGame
}

[init]
def private c2da_lin_relink_init_d_loop() {
    c2da_relink_d_loop()
}
