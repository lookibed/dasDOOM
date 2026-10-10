var private c2da_str_d_loop_0 : array<int8> = [int8(84), int8(114), int8(121), int8(82), int8(117), int8(110), int8(84), int8(105), int8(99), int8(115), int8(58), int8(32), int8(108), int8(111), int8(119), int8(116), int8(105), int8(99), int8(32), int8(60), int8(32), int8(103), int8(97), int8(109), int8(101), int8(116), int8(105), int8(99), int8(0)]

var private c2da_str_d_loop_1 : array<int8> = [int8(103), int8(97), int8(109), int8(101), int8(116), int8(105), int8(99), int8(62), int8(108), int8(111), int8(119), int8(116), int8(105), int8(99), int8(0)]

var private c2da_str_d_loop_2 : array<int8> = [int8(68), int8(105), int8(115), int8(99), int8(111), int8(110), int8(110), int8(101), int8(99), int8(116), int8(101), int8(100), int8(32), int8(102), int8(114), int8(111), int8(109), int8(32), int8(115), int8(101), int8(114), int8(118), int8(101), int8(114), int8(32), int8(105), int8(110), int8(32), int8(100), int8(114), int8(111), int8(110), int8(101), int8(32), int8(109), int8(111), int8(100), int8(101), int8(46), int8(0)]

var private c2da_str_d_loop_3 : array<int8> = [int8(68), int8(105), int8(115), int8(99), int8(111), int8(110), int8(110), int8(101), int8(99), int8(116), int8(101), int8(100), int8(32), int8(102), int8(114), int8(111), int8(109), int8(32), int8(115), int8(101), int8(114), int8(118), int8(101), int8(114), int8(46), int8(10), int8(0)]

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
def D_RegisterLoopCallbacks(var i : loop_interface_t?) {
    loop_interface = unsafe(reinterpret<loop_interface_t?>(i))
    return
}
var private loop_interface : loop_interface_t? = null

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
    var gameticdiv : int
    var cmd : ticcmd_t
    gameticdiv = gametic / ticdup
    I_StartTic()
    invoke(loop_interface.ProcessEvents)
    invoke(loop_interface.RunMenu)
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
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(addr<uint8?>(cmd)))), 0u8, 16ul)))
    invoke(loop_interface.BuildTiccmd, unsafe(addr(cmd)), maketic)
    unsafe(unsafe(addr(ticdata[maketic % 128].cmds[0]))[localplayer]) = cmd
    unsafe(unsafe(addr(ticdata[maketic % 128].ingame[0]))[localplayer]) = 1u
    maketic++
    return 1u
}
var private maketic : int = default<int>

var private localplayer : int = default<int>

var private ticdata : ticcmd_set_t[128]

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
    var set : ticcmd_set_t?
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
            I_Error(unsafe(addr<int8?>(c2da_str_d_loop_0[0])), [])
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
        set = unsafe(addr<ticcmd_set_t?>(unsafe(unsafe(addr(ticdata[0]))[gametic / ticdup % 128])))
        if (net_client_connected == 0) {
            SinglePlayerClear(set)
        }
        i_1 = 0
        while (i_1 < ticdup) {
            if (gametic / ticdup > lowtic) {
                I_Error(unsafe(addr<int8?>(c2da_str_d_loop_1[0])), [])
            }
            var c2da_fresh0 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(set)) + 128ul))
            unsafe(memcpy(unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(unsafe(addr<uint8?>(local_playeringame[0])))))), unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(c2da_fresh0)))))), 32ul))
            var c2da_fresh1 : ticcmd_t? = unsafe(reinterpret<ticcmd_t?>(unsafe(reinterpret<uint64>(set))))
            var c2da_fresh2 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(set)) + 128ul))
            invoke(loop_interface.RunTic, c2da_fresh1, c2da_fresh2)
            gametic++
            TicdupSquash(set)
            i_1++
        }
        NetUpdate()
    }
    return
}
[sideeffects]
def private TicdupSquash(var set_0 : ticcmd_set_t?) {
    var cmd_0 : ticcmd_t?
    for (i_2 in urange(0u, 8u)) {
        var c2da_fresh3 : ticcmd_t? = unsafe(reinterpret<ticcmd_t?>(unsafe(reinterpret<uint64>(set_0))))
        cmd_0 = unsafe(addr<ticcmd_t?>(unsafe(unsafe(reinterpret<ticcmd_t?>(c2da_fresh3))[int(i_2)])))
        cmd_0.chatchar = 0u8
        if ((int(cmd_0.buttons) & 128) != 0) {
            cmd_0.buttons = 0u8
        }
    }
    return
}
var private local_playeringame : uint[8]

[sideeffects]
def private SinglePlayerClear(var set_1 : ticcmd_set_t?) {
    for (i_3 in urange(0u, 8u)) {
        if (i_3 != uint(localplayer)) {
            var c2da_fresh4 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(set_1)) + 128ul))
            unsafe(unsafe(reinterpret<uint?>(c2da_fresh4))[int(i_3)]) = 0u
        }
    }
    return
}
[sideeffects]
def private PlayersInGame() : uint {
    var result_0 : uint = 0u
    if (net_client_connected != 0x0) {
        for (i_4 in urange(0u, 8u)) {
            result_0 = uint(result_0 != 0x0 || local_playeringame[int(i_4)] != 0x0 ? 1 : 0)
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
        if (local_playeringame[int(i_5)] != 0x0) {
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
def D_InitNetGame(var connect_data : net_connect_data_t?) : uint {
    I_AtExit(@@D_QuitNetGame, 1u)
    player_class = int(connect_data.player_class)  // nolint:PERF020
    return 0u
}
var private player_class : int = default<int>

[export, sideeffects]
def D_StartNetGame(var settings : net_gamesettings_t?; var callback : netgame_startup_callback_t) {
    settings.consoleplayer = 0
    settings.num_players = 1
    var c2da_fresh5 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(settings)) + 68ul))
    unsafe(unsafe(reinterpret<int?>(c2da_fresh5))[0]) = int(player_class)  // nolint:PERF020
    settings.new_sync = 0
    settings.extratics = 1
    settings.ticdup = 1
    ticdup = int(settings.ticdup)  // nolint:PERF020
    new_sync = uint(settings.new_sync)
    return
}
[sideeffects]
def private D_Disconnected() {
    if (drone != 0x0) {
        I_Error(unsafe(addr<int8?>(c2da_str_d_loop_2[0])), [])
    }
    c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_d_loop_3[0])), [])
    return
}
[export, sideeffects]
def D_ReceiveTic(var ticcmds : ticcmd_t?; var players_mask : uint?) {
    if (ticcmds == null && players_mask == null) {
        D_Disconnected()
        return
    }
    for (i_6 in range(0, 8)) {
        if (!(drone == 0 && i_6 == localplayer)) {
            unsafe(unsafe(addr(ticdata[recvtic % 128].cmds[0]))[i_6]) = unsafe(ticcmds[i_6])
            unsafe(unsafe(addr(ticdata[recvtic % 128].ingame[0]))[i_6]) = uint(unsafe(players_mask[i_6]))  // nolint:PERF020
        }
    }
    recvtic++
    return
}
[sideeffects]
def private c2da_layout_proofs_0() {
    static_assert(typeinfo sizeof(type<_IO_FILE>) == 216, "C layout of _IO_FILE: sizeof")
    static_assert(typeinfo alignof(type<_IO_FILE>) == 8, "C layout of _IO_FILE: alignof")
    static_assert(typeinfo offsetof<_flags>(type<_IO_FILE>) == 0, "C layout of _IO_FILE: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<_IO_FILE>) == 8, "C layout of _IO_FILE: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<_IO_FILE>) == 16, "C layout of _IO_FILE: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<_IO_FILE>) == 24, "C layout of _IO_FILE: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<_IO_FILE>) == 32, "C layout of _IO_FILE: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<_IO_FILE>) == 40, "C layout of _IO_FILE: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<_IO_FILE>) == 48, "C layout of _IO_FILE: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<_IO_FILE>) == 56, "C layout of _IO_FILE: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<_IO_FILE>) == 64, "C layout of _IO_FILE: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<_IO_FILE>) == 72, "C layout of _IO_FILE: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<_IO_FILE>) == 80, "C layout of _IO_FILE: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<_IO_FILE>) == 88, "C layout of _IO_FILE: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<_IO_FILE>) == 96, "C layout of _IO_FILE: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<_IO_FILE>) == 104, "C layout of _IO_FILE: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<_IO_FILE>) == 112, "C layout of _IO_FILE: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<_IO_FILE>) == 116, "C layout of _IO_FILE: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<_IO_FILE>) == 120, "C layout of _IO_FILE: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<_IO_FILE>) == 128, "C layout of _IO_FILE: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<_IO_FILE>) == 130, "C layout of _IO_FILE: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<_IO_FILE>) == 131, "C layout of _IO_FILE: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<_IO_FILE>) == 136, "C layout of _IO_FILE: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<_IO_FILE>) == 144, "C layout of _IO_FILE: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<_IO_FILE>) == 152, "C layout of _IO_FILE: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<_IO_FILE>) == 160, "C layout of _IO_FILE: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<_IO_FILE>) == 168, "C layout of _IO_FILE: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<_IO_FILE>) == 176, "C layout of _IO_FILE: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<_IO_FILE>) == 184, "C layout of _IO_FILE: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<_IO_FILE>) == 192, "C layout of _IO_FILE: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<_IO_FILE>) == 196, "C layout of _IO_FILE: offsetof _unused2")
    static_assert(typeinfo sizeof(type<FILE_0>) == 216, "C layout of FILE_0: sizeof")
    static_assert(typeinfo alignof(type<FILE_0>) == 8, "C layout of FILE_0: alignof")
    static_assert(typeinfo offsetof<_flags>(type<FILE_0>) == 0, "C layout of FILE_0: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<FILE_0>) == 8, "C layout of FILE_0: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<FILE_0>) == 16, "C layout of FILE_0: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<FILE_0>) == 24, "C layout of FILE_0: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<FILE_0>) == 32, "C layout of FILE_0: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<FILE_0>) == 40, "C layout of FILE_0: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<FILE_0>) == 48, "C layout of FILE_0: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<FILE_0>) == 56, "C layout of FILE_0: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<FILE_0>) == 64, "C layout of FILE_0: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<FILE_0>) == 72, "C layout of FILE_0: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<FILE_0>) == 80, "C layout of FILE_0: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<FILE_0>) == 88, "C layout of FILE_0: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<FILE_0>) == 96, "C layout of FILE_0: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<FILE_0>) == 104, "C layout of FILE_0: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<FILE_0>) == 112, "C layout of FILE_0: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<FILE_0>) == 116, "C layout of FILE_0: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<FILE_0>) == 120, "C layout of FILE_0: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<FILE_0>) == 128, "C layout of FILE_0: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<FILE_0>) == 130, "C layout of FILE_0: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<FILE_0>) == 131, "C layout of FILE_0: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<FILE_0>) == 136, "C layout of FILE_0: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<FILE_0>) == 144, "C layout of FILE_0: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<FILE_0>) == 152, "C layout of FILE_0: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<FILE_0>) == 160, "C layout of FILE_0: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<FILE_0>) == 168, "C layout of FILE_0: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<FILE_0>) == 176, "C layout of FILE_0: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<FILE_0>) == 184, "C layout of FILE_0: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<FILE_0>) == 192, "C layout of FILE_0: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<FILE_0>) == 196, "C layout of FILE_0: offsetof _unused2")
    static_assert(typeinfo sizeof(type<ticcmd_t>) == 16, "C layout of ticcmd_t: sizeof")
    static_assert(typeinfo alignof(type<ticcmd_t>) == 4, "C layout of ticcmd_t: alignof")
    static_assert(typeinfo offsetof<forwardmove>(type<ticcmd_t>) == 0, "C layout of ticcmd_t: offsetof forwardmove")
    static_assert(typeinfo offsetof<sidemove>(type<ticcmd_t>) == 1, "C layout of ticcmd_t: offsetof sidemove")
    static_assert(typeinfo offsetof<angleturn>(type<ticcmd_t>) == 2, "C layout of ticcmd_t: offsetof angleturn")
    static_assert(typeinfo offsetof<chatchar>(type<ticcmd_t>) == 4, "C layout of ticcmd_t: offsetof chatchar")
    static_assert(typeinfo offsetof<buttons>(type<ticcmd_t>) == 5, "C layout of ticcmd_t: offsetof buttons")
    static_assert(typeinfo offsetof<consistancy>(type<ticcmd_t>) == 6, "C layout of ticcmd_t: offsetof consistancy")
    static_assert(typeinfo offsetof<buttons2>(type<ticcmd_t>) == 7, "C layout of ticcmd_t: offsetof buttons2")
    static_assert(typeinfo offsetof<inventory>(type<ticcmd_t>) == 8, "C layout of ticcmd_t: offsetof inventory")
    static_assert(typeinfo offsetof<lookfly>(type<ticcmd_t>) == 12, "C layout of ticcmd_t: offsetof lookfly")
    static_assert(typeinfo offsetof<arti>(type<ticcmd_t>) == 13, "C layout of ticcmd_t: offsetof arti")
    static_assert(typeinfo sizeof(type<net_connect_data_t>) == 68, "C layout of net_connect_data_t: sizeof")
    static_assert(typeinfo alignof(type<net_connect_data_t>) == 4, "C layout of net_connect_data_t: alignof")
    static_assert(typeinfo offsetof<gamemode>(type<net_connect_data_t>) == 0, "C layout of net_connect_data_t: offsetof gamemode")
    static_assert(typeinfo offsetof<gamemission>(type<net_connect_data_t>) == 4, "C layout of net_connect_data_t: offsetof gamemission")
    static_assert(typeinfo offsetof<lowres_turn>(type<net_connect_data_t>) == 8, "C layout of net_connect_data_t: offsetof lowres_turn")
    static_assert(typeinfo offsetof<drone>(type<net_connect_data_t>) == 12, "C layout of net_connect_data_t: offsetof drone")
    static_assert(typeinfo offsetof<max_players>(type<net_connect_data_t>) == 16, "C layout of net_connect_data_t: offsetof max_players")
    static_assert(typeinfo offsetof<is_freedoom>(type<net_connect_data_t>) == 20, "C layout of net_connect_data_t: offsetof is_freedoom")
    static_assert(typeinfo offsetof<wad_sha1sum>(type<net_connect_data_t>) == 24, "C layout of net_connect_data_t: offsetof wad_sha1sum")
    static_assert(typeinfo offsetof<deh_sha1sum>(type<net_connect_data_t>) == 44, "C layout of net_connect_data_t: offsetof deh_sha1sum")
    static_assert(typeinfo offsetof<player_class>(type<net_connect_data_t>) == 64, "C layout of net_connect_data_t: offsetof player_class")
    static_assert(typeinfo sizeof(type<net_gamesettings_t>) == 100, "C layout of net_gamesettings_t: sizeof")
    static_assert(typeinfo alignof(type<net_gamesettings_t>) == 4, "C layout of net_gamesettings_t: alignof")
    static_assert(typeinfo offsetof<ticdup>(type<net_gamesettings_t>) == 0, "C layout of net_gamesettings_t: offsetof ticdup")
    static_assert(typeinfo offsetof<extratics>(type<net_gamesettings_t>) == 4, "C layout of net_gamesettings_t: offsetof extratics")
    static_assert(typeinfo offsetof<deathmatch>(type<net_gamesettings_t>) == 8, "C layout of net_gamesettings_t: offsetof deathmatch")
    static_assert(typeinfo offsetof<episode>(type<net_gamesettings_t>) == 12, "C layout of net_gamesettings_t: offsetof episode")
    static_assert(typeinfo offsetof<nomonsters>(type<net_gamesettings_t>) == 16, "C layout of net_gamesettings_t: offsetof nomonsters")
    static_assert(typeinfo offsetof<fast_monsters>(type<net_gamesettings_t>) == 20, "C layout of net_gamesettings_t: offsetof fast_monsters")
    static_assert(typeinfo offsetof<respawn_monsters>(type<net_gamesettings_t>) == 24, "C layout of net_gamesettings_t: offsetof respawn_monsters")
    static_assert(typeinfo offsetof<map>(type<net_gamesettings_t>) == 28, "C layout of net_gamesettings_t: offsetof map")
    static_assert(typeinfo offsetof<skill>(type<net_gamesettings_t>) == 32, "C layout of net_gamesettings_t: offsetof skill")
    static_assert(typeinfo offsetof<gameversion>(type<net_gamesettings_t>) == 36, "C layout of net_gamesettings_t: offsetof gameversion")
    static_assert(typeinfo offsetof<lowres_turn>(type<net_gamesettings_t>) == 40, "C layout of net_gamesettings_t: offsetof lowres_turn")
    static_assert(typeinfo offsetof<new_sync>(type<net_gamesettings_t>) == 44, "C layout of net_gamesettings_t: offsetof new_sync")
    static_assert(typeinfo offsetof<timelimit>(type<net_gamesettings_t>) == 48, "C layout of net_gamesettings_t: offsetof timelimit")
    static_assert(typeinfo offsetof<loadgame>(type<net_gamesettings_t>) == 52, "C layout of net_gamesettings_t: offsetof loadgame")
    static_assert(typeinfo offsetof<random>(type<net_gamesettings_t>) == 56, "C layout of net_gamesettings_t: offsetof random")
    static_assert(typeinfo offsetof<num_players>(type<net_gamesettings_t>) == 60, "C layout of net_gamesettings_t: offsetof num_players")
    static_assert(typeinfo offsetof<consoleplayer>(type<net_gamesettings_t>) == 64, "C layout of net_gamesettings_t: offsetof consoleplayer")
    static_assert(typeinfo offsetof<player_classes>(type<net_gamesettings_t>) == 68, "C layout of net_gamesettings_t: offsetof player_classes")
    static_assert(typeinfo sizeof(type<loop_interface_t>) == 32, "C layout of loop_interface_t: sizeof")
    static_assert(typeinfo alignof(type<loop_interface_t>) == 8, "C layout of loop_interface_t: alignof")
    static_assert(typeinfo offsetof<ProcessEvents>(type<loop_interface_t>) == 0, "C layout of loop_interface_t: offsetof ProcessEvents")
    static_assert(typeinfo offsetof<BuildTiccmd>(type<loop_interface_t>) == 8, "C layout of loop_interface_t: offsetof BuildTiccmd")
    static_assert(typeinfo offsetof<RunTic>(type<loop_interface_t>) == 16, "C layout of loop_interface_t: offsetof RunTic")
    static_assert(typeinfo offsetof<RunMenu>(type<loop_interface_t>) == 24, "C layout of loop_interface_t: offsetof RunMenu")
    static_assert(typeinfo sizeof(type<ticcmd_set_t>) == 160, "C layout of ticcmd_set_t: sizeof")
    static_assert(typeinfo alignof(type<ticcmd_set_t>) == 4, "C layout of ticcmd_set_t: alignof")
    static_assert(typeinfo offsetof<cmds>(type<ticcmd_set_t>) == 0, "C layout of ticcmd_set_t: offsetof cmds")
    static_assert(typeinfo offsetof<ingame>(type<ticcmd_set_t>) == 128, "C layout of ticcmd_set_t: offsetof ingame")
}
