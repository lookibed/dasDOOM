var private D_Display__viewactivestate : uint = 0u

var private D_Display__menuactivestate : uint = 0u

var private D_Display__inhelpscreensstate : uint = 0u

var private D_Display__fullscreen : uint = 0u

var private D_Display__oldgamestate : uint = 4294967295u

var private D_Display__borderdrawcount : int = 0

[sideeffects]
def private c2da___bswap_16_0(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_0(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_0(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_0(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_0(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_0(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
var nomonsters : uint = default<uint>

var respawnparm : uint = default<uint>

var fastparm : uint = default<uint>

var devparm : uint = default<uint>

var bfgedition : uint = default<uint>

var startskill : int = default<int>

var startepisode : int = default<int>

var startmap : int = default<int>

var startloadgame : int = default<int>

var autostart : uint = default<uint>

var savegamedir : int = default<int>

var wipegamestate : uint = 3u

[export, sideeffects]
def D_ProcessEvents() {
    var ev : int
    if (storedemo != 0x0) {
        return
    }
    while (true) {
        ev = D_PopEvent()
        if (ev == 0) {
            break
        }
        if (M_Responder(ev) != 0x0) {
            continue
        }
        G_Responder(ev)
    }
    return
}
var storedemo : uint = default<uint>

[export, sideeffects]
def D_PageTicker() {
    pagetic--
    if (pagetic < 0) {
        D_AdvanceDemo()
    }
    return
}
[export, sideeffects]
def D_AdvanceDemo() {
    advancedemo = 1u
    return
}
var advancedemo : uint = default<uint>

var pagetic : int = default<int>

[export, sideeffects]
def D_PageDrawer() {
    V_DrawPatch(0, 0, W_CacheLumpName(pagename, 8))
    return
}
var pagename : int = default<int>

[export, sideeffects]
def D_DoAdvanceDemo() {
    let c2da_fresh0 : uint = 0u
    let c2da_fresh1 : uint = c2da_fresh0
    c2da_mem[96 + int(consoleplayer) * 328 + 8] = uint8(c2da_fresh1)
    c2da_mem[96 + int(consoleplayer) * 328 + 9] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[96 + int(consoleplayer) * 328 + 10] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[96 + int(consoleplayer) * 328 + 11] = uint8(c2da_fresh1 >> 0x18)
    advancedemo = 0u
    usergame = 0u
    paused = 0u
    gameaction = 0u
    if (uint(gameversion) == 6u || uint(gameversion) == 7u) {
        demosequence = (demosequence + 1) % 7
    } else {
        demosequence = (demosequence + 1) % 6
    }
    if (demosequence == 0) {
        if (uint(gamemode) == 2u) {
            pagetic = 35 * 11
        } else {
            pagetic = 170
        }
        gamestate = 3u
        pagename = 325376
        if (uint(gamemode) == 2u) {
            S_StartMusic(66)
        } else {
            S_StartMusic(29)
        }
    } elif (demosequence == 1) {
        G_DeferedPlayDemo(325385)
    } elif (demosequence == 2) {
        pagetic = 200
        gamestate = 3u
        pagename = 325391
    } elif (demosequence == 3) {
        G_DeferedPlayDemo(325398)
    } elif (demosequence == 4) {
        gamestate = 3u
        if (uint(gamemode) == 2u) {
            pagetic = 35 * 11
            pagename = 325376
            S_StartMusic(66)
        } else {
            pagetic = 200
            if (uint(gamemode) == 3u) {
                pagename = 325391
            } else {
                pagename = 325404
            }
        }
    } elif (demosequence == 5) {
        G_DeferedPlayDemo(325410)
    } elif (demosequence == 6) {
        G_DeferedPlayDemo(325416)
    }
    if (bfgedition != 0x0 && c2da_lin_strcasecmp(pagename, 325376) == 0 && W_CheckNumForName(325422) < 0) {
        pagename = 325431
    }
    return
}
var demosequence : int = default<int>

[export, sideeffects]
def D_StartTitle() {
    gameaction = 0u
    demosequence = -1
    D_AdvanceDemo()
    return
}
[export, sideeffects]
def D_DoomLoop() {
    if (bfgedition != 0x0 && (demorecording != 0x0 || uint(gameaction) == 5u || netgame != 0x0)) {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 325440, [])
    }
    if (demorecording != 0x0) {
        G_BeginRecording()
    }
    main_loop_started = 1u
    TryRunTics()
    I_SetWindowTitle(gamedescription)
    I_GraphicsCheckCommandLine()
    I_SetGrabMouseCallback(2)
    I_InitGraphics()
    I_EnableLoadingDisk()
    V_RestoreBuffer()
    R_ExecuteSetViewSize()
    D_StartGameLoop()
    if (testcontrols != 0x0) {
        wipegamestate = gamestate
    }
    doomgeneric_Tick()
    return
}
[export, sideeffects]
def doomgeneric_Tick() {
    I_StartFrame()
    TryRunTics()
    S_UpdateSounds(int(uint(c2da_mem[96 + int(consoleplayer) * 328]) | uint(c2da_mem[96 + int(consoleplayer) * 328 + 1]) << 0x8 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 2]) << 0x10 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 3]) << 0x18))
    if (screenvisible != 0x0) {
        D_Display()
    }
    return
}
[export, sideeffects]
def D_Display() {
    var c2da_fresh2 : uint
    var nowtime : int
    var tics : int
    var wipestart : int
    var y : int
    var done : uint
    var wipe : uint
    var redrawsbar : uint
    if (nodrawers != 0x0) {
        return
    }
    redrawsbar = 0u
    if (setsizeneeded != 0x0) {
        R_ExecuteSetViewSize()
        D_Display__oldgamestate = 4294967295u
        D_Display__borderdrawcount = 3
    }
    if (uint(gamestate) != wipegamestate) {
        wipe = 1u
        wipe_StartScreen(0, 0, 320, 200)
    } else {
        wipe = 0u
    }
    if (uint(gamestate) == 0u && gametic != 0) {
        HU_Erase()
    }
    c2da_fresh2 = uint(gamestate)
    if (c2da_fresh2 == 0x0u) {
        if (gametic != 0) {
            if (automapactive != 0x0) {
                AM_Drawer()
            }
            if (wipe != 0x0 || viewheight != 200 && D_Display__fullscreen != 0x0) {
                redrawsbar = 1u
            }
            if (D_Display__inhelpscreensstate != 0x0 && inhelpscreens == 0) {
                redrawsbar = 1u
            }
            ST_Drawer(uint(viewheight == 200 ? 1 : 0), redrawsbar)
            D_Display__fullscreen = uint(viewheight == 200 ? 1 : 0)
        }
    } elif (c2da_fresh2 == 0x1u) {
        WI_Drawer()
    } elif (c2da_fresh2 == 0x2u) {
        F_Drawer()
    } elif (c2da_fresh2 == 0x3u) {
        D_PageDrawer()
    }
    I_UpdateNoBlit()
    if (uint(gamestate) == 0u && automapactive == 0 && gametic != 0) {
        R_RenderPlayerView(96 + int(displayplayer) * 328)
    }
    if (uint(gamestate) == 0u && gametic != 0) {
        HU_Drawer()
    }
    if (uint(gamestate) != D_Display__oldgamestate && uint(gamestate) != 0u) {
        I_SetPalette(W_CacheLumpName(325670, 8))
    }
    if (uint(gamestate) == 0u && D_Display__oldgamestate != 0u) {
        D_Display__viewactivestate = 0u
        R_FillBackScreen()
    }
    if (uint(gamestate) == 0u && automapactive == 0 && scaledviewwidth != 320) {
        if (menuactive != 0x0 || D_Display__menuactivestate != 0x0 || D_Display__viewactivestate == 0) {
            D_Display__borderdrawcount = 3
        }
        if (D_Display__borderdrawcount != 0) {
            R_DrawViewBorder()
            D_Display__borderdrawcount--
        }
    }
    if (testcontrols != 0x0) {
        V_DrawMouseSpeedBox(testcontrols_mousespeed)
    }
    D_Display__menuactivestate = uint(menuactive)
    D_Display__viewactivestate = uint(viewactive)
    D_Display__inhelpscreensstate = uint(inhelpscreens)
    wipegamestate = gamestate
    D_Display__oldgamestate = uint(wipegamestate)  // nolint:PERF020
    if (paused != 0x0) {
        if (automapactive != 0x0) {
            y = 4
        } else {
            y = viewwindowy + 4
        }
        V_DrawPatchDirect(viewwindowx + (scaledviewwidth - 68) / 2, y, W_CacheLumpName(325678, 8))
    }
    M_Drawer()
    NetUpdate()
    if (wipe == 0) {
        I_FinishUpdate()
        return
    }
    wipe_EndScreen(0, 0, 320, 200)
    wipestart = I_GetTime() - 1
    while (true) {
        while (true) {
            nowtime = I_GetTime()
            tics = nowtime - wipestart
            I_Sleep(1)
            if (tics > 0) {
                break
            }
        }
        wipestart = nowtime
        done = uint(wipe_ScreenWipe(1, 0, 0, 320, 200, tics))
        I_UpdateNoBlit()
        M_Drawer()
        I_FinishUpdate()
        if (done != 0) {
            break
        }
    }
    return
}
[export, sideeffects]
def D_GrabMouseCallback() : uint {
    if (drone != 0x0) {
        return 0u
    }
    if (menuactive != 0x0 || paused != 0x0) {
        return 0u
    }
    return uint(uint(gamestate) == 0u && demoplayback == 0 && advancedemo == 0 ? 1 : 0)
}
var main_loop_started : uint = 0u

var iwadfile : int = default<int>

var wadfile : int8[1024]

var mapdir : int8[1024]

[export, sideeffects]
def D_BindVariables() {
    let c2da_saved_sp : int = c2da_lin_sp
    D_BindVariables_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private GetGameName(var gamename : int) : int {
    var i_0 : uint64
    var deh_sub : int
    var gamename_size : uint64
    var version : int
    i_0 = 0ul
    while (i_0 < 56ul / 8ul) {
        deh_sub = int(uint(c2da_mem[323760 + int(i_0) * 8]) | uint(c2da_mem[323760 + int(i_0) * 8 + 1]) << 0x8 | uint(c2da_mem[323760 + int(i_0) * 8 + 2]) << 0x10 | uint(c2da_mem[323760 + int(i_0) * 8 + 3]) << 0x18)
        if (deh_sub != int(uint(c2da_mem[323760 + int(i_0) * 8]) | uint(c2da_mem[323760 + int(i_0) * 8 + 1]) << 0x8 | uint(c2da_mem[323760 + int(i_0) * 8 + 2]) << 0x10 | uint(c2da_mem[323760 + int(i_0) * 8 + 3]) << 0x18)) {
            gamename_size = uint64(c2da_lin_strlen(deh_sub) + 10ul)
            gamename = Z_Malloc(int(gamename_size), 1, 0)
            version = G_VanillaVersionCode()
            M_snprintf(gamename, gamename_size, deh_sub, [C2daVaArg(tag = 1, i64 = int64(version / 100), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(version % 100), f64 = 0.0lf, raw = 0x0)])
            while (int(int8(c2da_mem[gamename + 0])) != 0 && c2da_std_isspace(int(int8(c2da_mem[gamename + 0]))) != 0) {
                c2da_lin_memmove(gamename, gamename + 1, gamename_size - 1ul)
            }
            while (true) {
                var c2da_fresh8 : int = 0
                if (int(int8(c2da_mem[gamename + 0])) != 0) {
                    let c2da_fresh7 : int = gamename + int(c2da_lin_strlen(gamename) - 1ul)
                    if (c2da_std_isspace(int(int8(c2da_mem[c2da_fresh7]))) != 0) {
                        c2da_fresh8 = 1
                    }
                }
                if (c2da_fresh8 == 0) {
                    break
                }
                let c2da_fresh9 : int = gamename + int(c2da_lin_strlen(gamename) - 1ul)
                let c2da_fresh10 : int8 = int8(0)
                c2da_mem[c2da_fresh9] = uint8(c2da_fresh10)
            }
            return gamename
        }
        i_0++
    }
    return gamename
}
[sideeffects]
def private SetMissionForPackName(var pack_name : int) {
    var i_1 : int = 0
    while (uint64(i_1) < 48ul / 16ul) {
        if (c2da_lin_strcasecmp(pack_name, int(uint(c2da_mem[323824 + i_1 * 16]) | uint(c2da_mem[323824 + i_1 * 16 + 1]) << 0x8 | uint(c2da_mem[323824 + i_1 * 16 + 2]) << 0x10 | uint(c2da_mem[323824 + i_1 * 16 + 3]) << 0x18)) == 0) {
            let c2da_fresh11 : uint = uint(int(uint(c2da_mem[323824 + i_1 * 16 + 8]) | uint(c2da_mem[323824 + i_1 * 16 + 9]) << 0x8 | uint(c2da_mem[323824 + i_1 * 16 + 10]) << 0x10 | uint(c2da_mem[323824 + i_1 * 16 + 11]) << 0x18))
            let c2da_fresh12 : uint = c2da_fresh11
            c2da_mem[2064] = uint8(c2da_fresh12)
            c2da_mem[2065] = uint8(c2da_fresh12 >> 0x8)
            c2da_mem[2066] = uint8(c2da_fresh12 >> 0x10)
            c2da_mem[2067] = uint8(c2da_fresh12 >> 0x18)
            return
        }
        i_1++
    }
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 325846, [])
    i_1 = 0
    while (uint64(i_1) < 48ul / 16ul) {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 325872, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[323824 + i_1 * 16]) | uint(c2da_mem[323824 + i_1 * 16 + 1]) << 0x8 | uint(c2da_mem[323824 + i_1 * 16 + 2]) << 0x10 | uint(c2da_mem[323824 + i_1 * 16 + 3]) << 0x18)))])
        i_1++
    }
    I_Error(325877, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(pack_name))])
    return
}
[export, sideeffects]
def D_IdentifyVersion() {
    var i_2 : uint
    var p : int
    if ((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 9u) {
        i_2 = 0u
        while (i_2 < numlumps) {
            if (c2da_lin_strncasecmp(int(lumpinfo + int(i_2) * 40), 325907, 8ul) == 0) {
                let c2da_fresh13 : uint = 1u
                let c2da_fresh14 : uint = c2da_fresh13
                c2da_mem[2064] = uint8(c2da_fresh14)
                c2da_mem[2065] = uint8(c2da_fresh14 >> 0x8)
                c2da_mem[2066] = uint8(c2da_fresh14 >> 0x10)
                c2da_mem[2067] = uint8(c2da_fresh14 >> 0x18)
                break
            } elif (c2da_lin_strncasecmp(int(lumpinfo + int(i_2) * 40), 325913, 8ul) == 0) {
                let c2da_fresh15 : uint = 0u
                let c2da_fresh16 : uint = c2da_fresh15
                c2da_mem[2064] = uint8(c2da_fresh16)
                c2da_mem[2065] = uint8(c2da_fresh16 >> 0x8)
                c2da_mem[2066] = uint8(c2da_fresh16 >> 0x10)
                c2da_mem[2067] = uint8(c2da_fresh16 >> 0x18)
                break
            }
            i_2++
        }
        if ((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 9u) {
            I_Error(325918, [])
        }
    }
    if (((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 4u ? 0u : (uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 5u ? 1u : uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 0u) {
        if (W_CheckNumForName(325948) > 0) {
            gamemode = 3u
        } elif (W_CheckNumForName(325953) > 0) {
            gamemode = 1u
        } else {
            gamemode = 0u
        }
    } else {
        gamemode = 2u
        p = M_CheckParmWithArgs(325958, 1)
        if (p > 0) {
            SetMissionForPackName(int(uint(c2da_mem[myargv + (p + 1) * 8]) | uint(c2da_mem[myargv + (p + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p + 1) * 8 + 3]) << 0x18))
        }
    }
    return
}
[export, sideeffects]
def D_SetGameDescription() {
    var is_freedoom : uint
    var is_freedm : uint
    is_freedoom = uint(W_CheckNumForName(325964) >= 0 ? 1 : 0)
    is_freedm = uint(W_CheckNumForName(325973) >= 0 ? 1 : 0)
    gamedescription = 325980
    if (((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 4u ? 0u : (uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 5u ? 1u : uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 0u) {
        if (is_freedoom != 0x0) {
            gamedescription = GetGameName(325988)
        } elif (uint(gamemode) == 3u) {
            gamedescription = GetGameName(326006)
        } elif (uint(gamemode) == 1u) {
            gamedescription = GetGameName(326024)
        } elif (uint(gamemode) == 0u) {
            gamedescription = GetGameName(326040)
        }
    } elif (is_freedoom != 0x0) {
        if (is_freedm != 0x0) {
            gamedescription = GetGameName(326055)
        } else {
            gamedescription = GetGameName(326062)
        }
    } elif (((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 4u ? 0u : (uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 5u ? 1u : uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 1u) {
        gamedescription = GetGameName(326080)
    } elif (((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 4u ? 0u : (uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 5u ? 1u : uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 3u) {
        gamedescription = GetGameName(326102)
    } elif (((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 4u ? 0u : (uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 5u ? 1u : uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 2u) {
        gamedescription = GetGameName(326130)
    }
    return
}
var title : int8[128]

[sideeffects]
def private D_AddFile(var filename : int) : uint {
    var handle : int
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 326154, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(filename))])
    handle = W_AddFile(filename)
    return uint(handle != 0 ? 1 : 0)
}
[export, sideeffects]
def PrintDehackedBanners() {
    var i_3 : uint64
    var deh_s : int
    i_3 = 0ul
    while (i_3 < 24ul / 8ul) {
        deh_s = int(uint(c2da_mem[323872 + int(i_3) * 8]) | uint(c2da_mem[323872 + int(i_3) * 8 + 1]) << 0x8 | uint(c2da_mem[323872 + int(i_3) * 8 + 2]) << 0x10 | uint(c2da_mem[323872 + int(i_3) * 8 + 3]) << 0x18)
        if (deh_s != int(uint(c2da_mem[323872 + int(i_3) * 8]) | uint(c2da_mem[323872 + int(i_3) * 8 + 1]) << 0x8 | uint(c2da_mem[323872 + int(i_3) * 8 + 2]) << 0x10 | uint(c2da_mem[323872 + int(i_3) * 8 + 3]) << 0x18)) {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 326166, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(deh_s))])
            let c2da_fresh17 : int = deh_s + int(c2da_lin_strlen(deh_s) - 1ul)
            if (int(int8(c2da_mem[c2da_fresh17])) != 10) {
                c2da_lin_printf(uint64(int(c2da_std_stderr())), 326169, [])
            }
        }
        i_3++
    }
    return
}
var private gameversions : Unnamed_d_main_928[10] = fixed_array<Unnamed_d_main_928>(Unnamed_d_main_928(description = 326171, cmdline = 326182, version = 1u), Unnamed_d_main_928(description = 326188, cmdline = 326202, version = 2u), Unnamed_d_main_928(description = 326206, cmdline = 326215, version = 3u), Unnamed_d_main_928(description = 326219, cmdline = 326228, version = 4u), Unnamed_d_main_928(description = 326232, cmdline = 326237, version = 5u), Unnamed_d_main_928(description = 326242, cmdline = 326256, version = 6u), Unnamed_d_main_928(description = 326265, cmdline = 326276, version = 7u), Unnamed_d_main_928(description = 326282, cmdline = 326299, version = 8u), Unnamed_d_main_928(description = 326306, cmdline = 326317, version = 9u), Unnamed_d_main_928(description = 0, cmdline = 0, version = 0u))

[sideeffects]
def private InitGameVersion() {
    var p_0 : int
    var i_4 : int
    p_0 = M_CheckParmWithArgs(326322, 1)
    if (p_0 != 0) {
        i_4 = 0
        while (gameversions[i_4].description != 0) {
            if (c2da_lin_strcmp(int(uint(c2da_mem[myargv + (p_0 + 1) * 8]) | uint(c2da_mem[myargv + (p_0 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_0 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_0 + 1) * 8 + 3]) << 0x18), gameversions[i_4].cmdline) == 0) {
                gameversion = gameversions[i_4].version
                break
            }
            i_4++
        }
        if (gameversions[i_4].description == 0) {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 326335, [])
            i_4 = 0
            while (gameversions[i_4].description != 0) {
                c2da_lin_printf(uint64(int(c2da_std_stderr())), 326361, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(gameversions[i_4].cmdline)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(gameversions[i_4].description))])
                i_4++
            }
            I_Error(326371, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[myargv + (p_0 + 1) * 8]) | uint(c2da_mem[myargv + (p_0 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_0 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_0 + 1) * 8 + 3]) << 0x18)))])
        }
    } elif ((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 4u) {
        gameversion = 9u
    } elif ((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 5u) {
        gameversion = 5u
    } elif (uint(gamemode) == 0u || uint(gamemode) == 1u) {
        gameversion = 4u
    } elif (uint(gamemode) == 3u) {
        gameversion = 6u
    } elif (uint(gamemode) == 2u) {
        if ((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 1u) {
            gameversion = 4u
        } else {
            gameversion = 7u
        }
    }
    if (uint(gameversion) < 6u && uint(gamemode) == 3u) {
        gamemode = 1u
    }
    if (uint(gameversion) < 7u && uint(gamemode) == 2u && ((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 2u || (uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 3u)) {
        let c2da_fresh18 : uint = 1u
        let c2da_fresh19 : uint = c2da_fresh18
        c2da_mem[2064] = uint8(c2da_fresh19)
        c2da_mem[2065] = uint8(c2da_fresh19 >> 0x8)
        c2da_mem[2066] = uint8(c2da_fresh19 >> 0x10)
        c2da_mem[2067] = uint8(c2da_fresh19 >> 0x18)
    }
    return
}
[export, sideeffects]
def PrintGameVersion() {
    var i_5 : int = 0
    while (gameversions[i_5].description != 0) {
        if (gameversions[i_5].version == uint(gameversion)) {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 326397, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(gameversions[i_5].description))])
            break
        }
        i_5++
    }
    return
}
[sideeffects]
def private D_Endoom() {
    var endoom : int
    if (int(uint(c2da_mem[1968]) | uint(c2da_mem[1969]) << 0x8 | uint(c2da_mem[1970]) << 0x10 | uint(c2da_mem[1971]) << 0x18) == 0 || main_loop_started == 0 || screensaver_mode != 0x0 || M_CheckParm(326445) > 0) {
        return
    }
    endoom = W_CacheLumpName(326459, 1)
    I_Endoom(endoom)
    c2da_std_exit(0)
    return
}
[export, sideeffects]
def D_DoomMain() {
    let c2da_saved_sp : int = c2da_lin_sp
    D_DoomMain_c2da_frame(c2da_lin_enter(464))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private D_BindVariables_c2da_frame(c2da_fp : int) {
    M_ApplyPlatformDefaults()
    I_BindVideoVariables()
    I_BindJoystickVariables()
    I_BindSoundVariables()
    M_BindBaseControls()
    M_BindWeaponControls()
    M_BindMapControls()
    M_BindMenuControls()
    M_BindChatControls(4u)
    let c2da_fresh3 : uint = 103u
    c2da_mem[43984 + 0 * 4] = uint8(c2da_fresh3)
    c2da_mem[43984 + 0 * 4 + 1] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[43984 + 0 * 4 + 2] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[43984 + 0 * 4 + 3] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : uint = 105u
    c2da_mem[43984 + 1 * 4] = uint8(c2da_fresh4)
    c2da_mem[43984 + 1 * 4 + 1] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[43984 + 1 * 4 + 2] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[43984 + 1 * 4 + 3] = uint8(c2da_fresh4 >> 0x18)
    let c2da_fresh5 : uint = 98u
    c2da_mem[43984 + 2 * 4] = uint8(c2da_fresh5)
    c2da_mem[43984 + 2 * 4 + 1] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[43984 + 2 * 4 + 2] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[43984 + 2 * 4 + 3] = uint8(c2da_fresh5 >> 0x18)
    let c2da_fresh6 : uint = 114u
    c2da_mem[43984 + 3 * 4] = uint8(c2da_fresh6)
    c2da_mem[43984 + 3 * 4 + 1] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[43984 + 3 * 4 + 2] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[43984 + 3 * 4 + 3] = uint8(c2da_fresh6 >> 0x18)
    M_BindVariable(325686, 1824)
    M_BindVariable(325704, 1840)
    M_BindVariable(325715, 1856)
    M_BindVariable(325728, 1872)
    M_BindVariable(325742, 1888)
    M_BindVariable(325755, 1904)
    M_BindVariable(325767, 1920)
    M_BindVariable(325780, 1936)
    M_BindVariable(325803, 1952)
    M_BindVariable(325822, 1968)
    for (i in range(0, 10)) {
        M_snprintf(c2da_fp, 12ul, 325834, [C2daVaArg(tag = 1, i64 = int64(i), f64 = 0.0lf, raw = 0x0)])
        M_BindVariable(c2da_fp, 1984 + i * 8)
    }
    return
}
[sideeffects]
def private D_DoomMain_c2da_frame(c2da_fp : int) {
    var p_1 : int
    var scale : int
    I_AtExit(154, 0u)
    I_PrintBanner(326466)
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 326483, [])
    Z_Init()
    nomonsters = uint(M_CheckParm(326529))
    respawnparm = uint(M_CheckParm(326541))
    fastparm = uint(M_CheckParm(326550))
    devparm = uint(M_CheckParm(326556))
    I_DisplayFPSDots(devparm)
    if (M_CheckParm(326565) != 0) {
        deathmatch = 1
    }
    if (M_CheckParm(326577) != 0) {
        deathmatch = 2
    }
    if (devparm != 0x0) {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 326587, [])
    }
    M_SetConfigDir(0)
    p_1 = M_CheckParm(326609)
    if (p_1 != 0) {
        scale = 200
        if (p_1 < myargc - 1) {
            scale = c2da_lin_atoi(int(uint(c2da_mem[myargv + (p_1 + 1) * 8]) | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 3]) << 0x18))
        }
        if (scale < 10) {
            scale = 10
        }
        if (scale > 400) {
            scale = 400
        }
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 326616, [C2daVaArg(tag = 1, i64 = int64(scale), f64 = 0.0lf, raw = 0x0)])
        forwardmove[0] = forwardmove[0] * scale / 100
        forwardmove[1] = forwardmove[1] * scale / 100
        sidemove[0] = sidemove[0] * scale / 100
        sidemove[1] = sidemove[1] * scale / 100
    }
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 326635, [])
    V_Init()
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 326662, [])
    M_SetConfigFilenames(326701, 326713)
    D_BindVariables()
    M_LoadDefaults()
    I_AtExit(3, 0u)
    iwadfile = D_FindIWAD(1 << 0 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5, 2064)
    if (iwadfile == 0) {
        I_Error(326733, [])
    }
    modifiedgame = 0u
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 326845, [])
    D_AddFile(iwadfile)
    W_CheckCorrectIWAD(0u)
    D_IdentifyVersion()
    InitGameVersion()
    if (W_CheckNumForName(326869) >= 0) {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 326878, [])
        bfgedition = 1u
    }
    modifiedgame = uint(W_ParseCommandLine())
    p_1 = M_CheckParmWithArgs(326921, 1)
    if (p_1 == 0) {
        p_1 = M_CheckParmWithArgs(326931, 1)
    }
    if (p_1 != 0) {
        if (M_StringEndsWith(int(uint(c2da_mem[myargv + (p_1 + 1) * 8]) | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 3]) << 0x18), 326941) != 0x0) {
            M_StringCopy(c2da_fp, int(uint(c2da_mem[myargv + (p_1 + 1) * 8]) | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 3]) << 0x18), 256ul)
        } else {
            c2da_lin_snprintf(c2da_fp, 256ul, 326946, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[myargv + (p_1 + 1) * 8]) | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 3]) << 0x18)))])
        }
        if (D_AddFile(c2da_fp) != 0x0) {
            M_StringCopy(c2da_fp + 256, lumpinfo + int(numlumps - 1u) * 40, 9ul)
        } else {
            M_StringCopy(c2da_fp + 256, int(uint(c2da_mem[myargv + (p_1 + 1) * 8]) | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 3]) << 0x18), 9ul)
        }
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 326953, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    }
    I_AtExit(4, 1u)
    W_GenerateHashTable()
    D_SetGameDescription()
    savegamedir = M_GetSaveGameDir(D_SaveGameIWADName(uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18))
    if (modifiedgame != 0x0) {
        c2da_mem[c2da_fp + 272] = 101u8
        c2da_mem[c2da_fp + 273] = 50u8
        c2da_mem[c2da_fp + 274] = 109u8
        c2da_mem[c2da_fp + 275] = 49u8
        c2da_mem[c2da_fp + 276] = 0u8
        c2da_mem[c2da_fp + 277] = 0u8
        c2da_mem[c2da_fp + 278] = 0u8
        c2da_mem[c2da_fp + 279] = 0u8
        c2da_mem[c2da_fp + 280] = 101u8
        c2da_mem[c2da_fp + 281] = 50u8
        c2da_mem[c2da_fp + 282] = 109u8
        c2da_mem[c2da_fp + 283] = 50u8
        c2da_mem[c2da_fp + 284] = 0u8
        c2da_mem[c2da_fp + 285] = 0u8
        c2da_mem[c2da_fp + 286] = 0u8
        c2da_mem[c2da_fp + 287] = 0u8
        c2da_mem[c2da_fp + 288] = 101u8
        c2da_mem[c2da_fp + 289] = 50u8
        c2da_mem[c2da_fp + 290] = 109u8
        c2da_mem[c2da_fp + 291] = 51u8
        c2da_mem[c2da_fp + 292] = 0u8
        c2da_mem[c2da_fp + 293] = 0u8
        c2da_mem[c2da_fp + 294] = 0u8
        c2da_mem[c2da_fp + 295] = 0u8
        c2da_mem[c2da_fp + 296] = 101u8
        c2da_mem[c2da_fp + 297] = 50u8
        c2da_mem[c2da_fp + 298] = 109u8
        c2da_mem[c2da_fp + 299] = 52u8
        c2da_mem[c2da_fp + 300] = 0u8
        c2da_mem[c2da_fp + 301] = 0u8
        c2da_mem[c2da_fp + 302] = 0u8
        c2da_mem[c2da_fp + 303] = 0u8
        c2da_mem[c2da_fp + 304] = 101u8
        c2da_mem[c2da_fp + 305] = 50u8
        c2da_mem[c2da_fp + 306] = 109u8
        c2da_mem[c2da_fp + 307] = 53u8
        c2da_mem[c2da_fp + 308] = 0u8
        c2da_mem[c2da_fp + 309] = 0u8
        c2da_mem[c2da_fp + 310] = 0u8
        c2da_mem[c2da_fp + 311] = 0u8
        c2da_mem[c2da_fp + 312] = 101u8
        c2da_mem[c2da_fp + 313] = 50u8
        c2da_mem[c2da_fp + 314] = 109u8
        c2da_mem[c2da_fp + 315] = 54u8
        c2da_mem[c2da_fp + 316] = 0u8
        c2da_mem[c2da_fp + 317] = 0u8
        c2da_mem[c2da_fp + 318] = 0u8
        c2da_mem[c2da_fp + 319] = 0u8
        c2da_mem[c2da_fp + 320] = 101u8
        c2da_mem[c2da_fp + 321] = 50u8
        c2da_mem[c2da_fp + 322] = 109u8
        c2da_mem[c2da_fp + 323] = 55u8
        c2da_mem[c2da_fp + 324] = 0u8
        c2da_mem[c2da_fp + 325] = 0u8
        c2da_mem[c2da_fp + 326] = 0u8
        c2da_mem[c2da_fp + 327] = 0u8
        c2da_mem[c2da_fp + 328] = 101u8
        c2da_mem[c2da_fp + 329] = 50u8
        c2da_mem[c2da_fp + 330] = 109u8
        c2da_mem[c2da_fp + 331] = 56u8
        c2da_mem[c2da_fp + 332] = 0u8
        c2da_mem[c2da_fp + 333] = 0u8
        c2da_mem[c2da_fp + 334] = 0u8
        c2da_mem[c2da_fp + 335] = 0u8
        c2da_mem[c2da_fp + 336] = 101u8
        c2da_mem[c2da_fp + 337] = 50u8
        c2da_mem[c2da_fp + 338] = 109u8
        c2da_mem[c2da_fp + 339] = 57u8
        c2da_mem[c2da_fp + 340] = 0u8
        c2da_mem[c2da_fp + 341] = 0u8
        c2da_mem[c2da_fp + 342] = 0u8
        c2da_mem[c2da_fp + 343] = 0u8
        c2da_mem[c2da_fp + 344] = 101u8
        c2da_mem[c2da_fp + 345] = 51u8
        c2da_mem[c2da_fp + 346] = 109u8
        c2da_mem[c2da_fp + 347] = 49u8
        c2da_mem[c2da_fp + 348] = 0u8
        c2da_mem[c2da_fp + 349] = 0u8
        c2da_mem[c2da_fp + 350] = 0u8
        c2da_mem[c2da_fp + 351] = 0u8
        c2da_mem[c2da_fp + 352] = 101u8
        c2da_mem[c2da_fp + 353] = 51u8
        c2da_mem[c2da_fp + 354] = 109u8
        c2da_mem[c2da_fp + 355] = 51u8
        c2da_mem[c2da_fp + 356] = 0u8
        c2da_mem[c2da_fp + 357] = 0u8
        c2da_mem[c2da_fp + 358] = 0u8
        c2da_mem[c2da_fp + 359] = 0u8
        c2da_mem[c2da_fp + 360] = 101u8
        c2da_mem[c2da_fp + 361] = 51u8
        c2da_mem[c2da_fp + 362] = 109u8
        c2da_mem[c2da_fp + 363] = 51u8
        c2da_mem[c2da_fp + 364] = 0u8
        c2da_mem[c2da_fp + 365] = 0u8
        c2da_mem[c2da_fp + 366] = 0u8
        c2da_mem[c2da_fp + 367] = 0u8
        c2da_mem[c2da_fp + 368] = 101u8
        c2da_mem[c2da_fp + 369] = 51u8
        c2da_mem[c2da_fp + 370] = 109u8
        c2da_mem[c2da_fp + 371] = 52u8
        c2da_mem[c2da_fp + 372] = 0u8
        c2da_mem[c2da_fp + 373] = 0u8
        c2da_mem[c2da_fp + 374] = 0u8
        c2da_mem[c2da_fp + 375] = 0u8
        c2da_mem[c2da_fp + 376] = 101u8
        c2da_mem[c2da_fp + 377] = 51u8
        c2da_mem[c2da_fp + 378] = 109u8
        c2da_mem[c2da_fp + 379] = 53u8
        c2da_mem[c2da_fp + 380] = 0u8
        c2da_mem[c2da_fp + 381] = 0u8
        c2da_mem[c2da_fp + 382] = 0u8
        c2da_mem[c2da_fp + 383] = 0u8
        c2da_mem[c2da_fp + 384] = 101u8
        c2da_mem[c2da_fp + 385] = 51u8
        c2da_mem[c2da_fp + 386] = 109u8
        c2da_mem[c2da_fp + 387] = 54u8
        c2da_mem[c2da_fp + 388] = 0u8
        c2da_mem[c2da_fp + 389] = 0u8
        c2da_mem[c2da_fp + 390] = 0u8
        c2da_mem[c2da_fp + 391] = 0u8
        c2da_mem[c2da_fp + 392] = 101u8
        c2da_mem[c2da_fp + 393] = 51u8
        c2da_mem[c2da_fp + 394] = 109u8
        c2da_mem[c2da_fp + 395] = 55u8
        c2da_mem[c2da_fp + 396] = 0u8
        c2da_mem[c2da_fp + 397] = 0u8
        c2da_mem[c2da_fp + 398] = 0u8
        c2da_mem[c2da_fp + 399] = 0u8
        c2da_mem[c2da_fp + 400] = 101u8
        c2da_mem[c2da_fp + 401] = 51u8
        c2da_mem[c2da_fp + 402] = 109u8
        c2da_mem[c2da_fp + 403] = 56u8
        c2da_mem[c2da_fp + 404] = 0u8
        c2da_mem[c2da_fp + 405] = 0u8
        c2da_mem[c2da_fp + 406] = 0u8
        c2da_mem[c2da_fp + 407] = 0u8
        c2da_mem[c2da_fp + 408] = 101u8
        c2da_mem[c2da_fp + 409] = 51u8
        c2da_mem[c2da_fp + 410] = 109u8
        c2da_mem[c2da_fp + 411] = 57u8
        c2da_mem[c2da_fp + 412] = 0u8
        c2da_mem[c2da_fp + 413] = 0u8
        c2da_mem[c2da_fp + 414] = 0u8
        c2da_mem[c2da_fp + 415] = 0u8
        c2da_mem[c2da_fp + 416] = 100u8
        c2da_mem[c2da_fp + 417] = 112u8
        c2da_mem[c2da_fp + 418] = 104u8
        c2da_mem[c2da_fp + 419] = 111u8
        c2da_mem[c2da_fp + 420] = 111u8
        c2da_mem[c2da_fp + 421] = 102u8
        c2da_mem[c2da_fp + 422] = 0u8
        c2da_mem[c2da_fp + 423] = 0u8
        c2da_mem[c2da_fp + 424] = 98u8
        c2da_mem[c2da_fp + 425] = 102u8
        c2da_mem[c2da_fp + 426] = 103u8
        c2da_mem[c2da_fp + 427] = 103u8
        c2da_mem[c2da_fp + 428] = 97u8
        c2da_mem[c2da_fp + 429] = 48u8
        c2da_mem[c2da_fp + 430] = 0u8
        c2da_mem[c2da_fp + 431] = 0u8
        c2da_mem[c2da_fp + 432] = 104u8
        c2da_mem[c2da_fp + 433] = 101u8
        c2da_mem[c2da_fp + 434] = 97u8
        c2da_mem[c2da_fp + 435] = 100u8
        c2da_mem[c2da_fp + 436] = 97u8
        c2da_mem[c2da_fp + 437] = 49u8
        c2da_mem[c2da_fp + 438] = 0u8
        c2da_mem[c2da_fp + 439] = 0u8
        c2da_mem[c2da_fp + 440] = 99u8
        c2da_mem[c2da_fp + 441] = 121u8
        c2da_mem[c2da_fp + 442] = 98u8
        c2da_mem[c2da_fp + 443] = 114u8
        c2da_mem[c2da_fp + 444] = 97u8
        c2da_mem[c2da_fp + 445] = 49u8
        c2da_mem[c2da_fp + 446] = 0u8
        c2da_mem[c2da_fp + 447] = 0u8
        c2da_mem[c2da_fp + 448] = 115u8
        c2da_mem[c2da_fp + 449] = 112u8
        c2da_mem[c2da_fp + 450] = 105u8
        c2da_mem[c2da_fp + 451] = 100u8
        c2da_mem[c2da_fp + 452] = 97u8
        c2da_mem[c2da_fp + 453] = 49u8
        c2da_mem[c2da_fp + 454] = 100u8
        c2da_mem[c2da_fp + 455] = 49u8
        if (uint(gamemode) == 0u) {
            I_Error(326971, [])
        }
        if (uint(gamemode) == 1u) {
            for (i_6 in range(0, 23)) {
                if (W_CheckNumForName(c2da_fp + 272 + i_6 * 8) < 0) {
                    I_Error(327027, [])
                }
            }
        }
    }
    if (W_CheckNumForName(327064) >= 0 || W_CheckNumForName(327073) >= 0) {
        I_PrintDivider()
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 327080, [])
    }
    I_PrintStartupBanner(gamedescription)
    PrintDehackedBanners()
    if (W_CheckNumForName(325964) >= 0 && W_CheckNumForName(325973) < 0) {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 327232, [])
        I_PrintDivider()
    }
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 327457, [])
    I_CheckIsScreensaver()
    I_InitTimer()
    I_InitJoystick()
    I_InitSound(1u)
    I_InitMusic()
    D_ConnectNetGame()
    startskill = 2
    startepisode = 1
    startmap = 1
    autostart = 0u
    p_1 = M_CheckParmWithArgs(327492, 1)
    if (p_1 != 0) {
        let c2da_fresh20 : int = int(uint(c2da_mem[myargv + (p_1 + 1) * 8]) | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 3]) << 0x18) + 0
        startskill = int(int8(c2da_mem[c2da_fresh20])) - 49
        autostart = 1u
    }
    p_1 = M_CheckParmWithArgs(327499, 1)
    if (p_1 != 0) {
        let c2da_fresh21 : int = int(uint(c2da_mem[myargv + (p_1 + 1) * 8]) | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 3]) << 0x18) + 0
        startepisode = int(int8(c2da_mem[c2da_fresh21])) - 48
        startmap = 1
        autostart = 1u
    }
    timelimit = 0
    p_1 = M_CheckParmWithArgs(327508, 1)
    if (p_1 != 0) {
        timelimit = c2da_lin_atoi(int(uint(c2da_mem[myargv + (p_1 + 1) * 8]) | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 3]) << 0x18))
    }
    p_1 = M_CheckParm(327515)
    if (p_1 != 0) {
        timelimit = 20
    }
    p_1 = M_CheckParmWithArgs(327520, 1)
    if (p_1 != 0) {
        if (uint(gamemode) == 2u) {
            startmap = c2da_lin_atoi(int(uint(c2da_mem[myargv + (p_1 + 1) * 8]) | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 3]) << 0x18))
        } else {
            let c2da_fresh22 : int = int(uint(c2da_mem[myargv + (p_1 + 1) * 8]) | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 3]) << 0x18) + 0
            startepisode = int(int8(c2da_mem[c2da_fresh22])) - 48
            if (p_1 + 2 < myargc) {
                let c2da_fresh23 : int = int(uint(c2da_mem[myargv + (p_1 + 2) * 8]) | uint(c2da_mem[myargv + (p_1 + 2) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_1 + 2) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_1 + 2) * 8 + 3]) << 0x18) + 0
                startmap = int(int8(c2da_mem[c2da_fresh23])) - 48
            } else {
                startmap = 1
            }
        }
        autostart = 1u
    }
    p_1 = M_CheckParm(326445)
    if (p_1 > 0) {
        startepisode = 1
        startmap = 1
        autostart = 1u
        testcontrols = 1u
    }
    p_1 = M_CheckParmWithArgs(327526, 1)
    if (p_1 != 0) {
        startloadgame = c2da_lin_atoi(int(uint(c2da_mem[myargv + (p_1 + 1) * 8]) | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 3]) << 0x18))
    } else {
        startloadgame = -1
    }
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 327536, [])
    M_Init()
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 327570, [])
    R_Init()
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 327606, [])
    P_Init()
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 327637, [])
    S_Init(int(uint(c2da_mem[1840]) | uint(c2da_mem[1841]) << 0x8 | uint(c2da_mem[1842]) << 0x10 | uint(c2da_mem[1843]) << 0x18) * 8, int(uint(c2da_mem[1856]) | uint(c2da_mem[1857]) << 0x8 | uint(c2da_mem[1858]) << 0x10 | uint(c2da_mem[1859]) << 0x18) * 8)
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 327664, [])
    D_CheckNetGame()
    PrintGameVersion()
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 327711, [])
    HU_Init()
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 327750, [])
    ST_Init()
    if (uint(gamemode) == 2u && W_CheckNumForName(327777) < 0) {
        storedemo = 1u
    }
    if (M_CheckParmWithArgs(327783, 1) != 0) {
        I_AtExit(5, 1u)
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 327793, [])
    }
    p_1 = M_CheckParmWithArgs(327826, 1)
    if (p_1 != 0) {
        G_RecordDemo(int(uint(c2da_mem[myargv + (p_1 + 1) * 8]) | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_1 + 1) * 8 + 3]) << 0x18))
        autostart = 1u
    }
    p_1 = M_CheckParmWithArgs(326921, 1)
    if (p_1 != 0) {
        singledemo = 1u
        G_DeferedPlayDemo(c2da_fp + 256)
        D_DoomLoop()
        return
    }
    p_1 = M_CheckParmWithArgs(326931, 1)
    if (p_1 != 0) {
        G_TimeDemo(c2da_fp + 256)
        D_DoomLoop()
        return
    }
    if (startloadgame >= 0) {
        M_StringCopy(c2da_fp, P_SaveGameFile(startloadgame), 256ul)
        G_LoadGame(c2da_fp)
    }
    if (uint(gameaction) != 3u) {
        if (autostart != 0x0 || netgame != 0x0) {
            G_InitNew(startskill, startepisode, startmap)
        } else {
            D_StartTitle()
        }
    }
    D_DoomLoop()
    return
}

// This unit's static data, at heap offset 323760.
let private c2da_lin_static_d_main_seg = fixed_array<int>(323760, 4073)
let private c2da_lin_static_d_main = fixed_array<uint64>(0x4f138ul, 0x4f189ul, 0x4f1deul, 0x4f234ul, 0x4f283ul, 0x4f2d5ul, 0x4f324ul, 0x0ul, 0x4f375ul, 0x1ul, 0x4f37bul, 0x2ul, 0x4f37ful, 0x3ul, 0x4f388ul, 0x4f528ul, 0x4f63cul, 0x2020202020202020ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x3a32204d4f4f4420ul, 0x6e6f206c6c654820ul, 0x7620687472614520ul, 0x20202069252e6925ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x2020202020202000ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x4f4f442020202020ul, 0x776572616853204dul, 0x7261745320657261ul, 0x2e69257620707574ul, 0x2020202020206925ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x2020002020202020ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x52204d4f4f442020ul, 0x6572657473696765ul, 0x7574726174532064ul, 0x69252e6925762070ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x2020202000202020ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x4f44202020202020ul, 0x6574737953204d4ful, 0x757472617453206dul, 0x69252e6925762070ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x2020202020002020ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x2065685420202020ul, 0x6574616d69746c55ul, 0x7453204d4f4f4420ul, 0x2576207075747261ul, 0x2020202069252e69ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x2020200020202020ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x32204d4f4f442020ul, 0x202d20544e54203aul, 0x6f6974756c697645ul, 0x69252e692576206eul, 0x2020202020202020ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x2020202000202020ul, 0x2020202020202020ul, 0x4420202020202020ul, 0x50203a32204d4f4ful, 0x2061696e6f74756cul, 0x656d697265707845ul, 0x252e69257620746eul, 0x2020202020202069ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x6f6f640020202020ul, 0x7000746e7400326dul, 0x61696e6f74756cul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x455454410a3d3d3dul, 0x20203a4e4f49544eul, 0x7265762073696854ul, 0x20666f206e6f6973ul, 0x736168204d4f4f44ul, 0x6f6d206e65656220ul, 0x202e646569666964ul, 0x20756f7920664920ul, 0x696c20646c756f77ul, 0x65670a6f7420656bul, 0x79706f6320612074ul, 0x2065687420666f20ul, 0x6c616e696769726ful, 0x63202c656d616720ul, 0x30382d31206c6c61ul, 0x454d414744492d30ul, 0x65657320726f2053ul, 0x6165722065687420ul, 0x656c696620656d64ul, 0x2020202020200a2eul, 0x697720756f592020ul, 0x7220746f6e206c6cul, 0x7420657669656365ul, 0x6c6163696e686365ul, 0x74726f7070757320ul, 0x646f6d20726f6620ul, 0x6167206465696669ul, 0x2020200a2e73656dul, 0x2020202020202020ul, 0x2020202020202020ul, 0x7373657270202020ul, 0x74207265746e6520ul, 0x6e69746e6f63206ful, 0x3d3d3d3d3d0a6575ul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0xa3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x202020200a3d3d3dul, 0x2020202020202020ul, 0x6d6f432020202020ul, 0x206c61696372656dul, 0x20746375646f7270ul, 0x746f6e206f64202dul, 0x6269727473696420ul, 0x2020200a21657475ul, 0x6c50202020202020ul, 0x7065722065736165ul, 0x74666f732074726ful, 0x7269702065726177ul, 0x74206f7420796361ul, 0x203a415053206568ul, 0x38332d3030382d31ul, 0x3d0a385249502d38ul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d000a3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0xa3d3d3d3d3d3d3dul, 0x2020202020202020ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x2020202020202020ul, 0x7261776572616853ul, 0x3d3d3d3d3d0a2165ul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0x3d3d3d3d3d3d3d3dul, 0xa3d3d3d3d3d3dul, 0x434950454c544954ul, 0x4300316f6d656400ul, 0x6564005449444552ul, 0x504c454800326f6dul, 0x336f6d65640032ul, 0x697400346f6d6564ul, 0x4900636970656c74ul, 0x4349505245544eul, 0x474e494e52415720ul, 0x726120756f59203aul, 0x6e6979616c702065ul, 0x20676e6973752067ul, 0x7420666f20656e6ful, 0x206d6f6f44206568ul, 0xa63697373616c43ul, 0x6966204441574920ul, 0x706968732073656cul, 0x6874697720646570ul, 0x6f6f442065687420ul, 0x474642203a33206dul, 0x6e6f697469644520ul, 0x206573656854202eul, 0x6f6e6b200a657261ul, 0x6562206f74206e77ul, 0x61706d6f636e6920ul, 0x697720656c626974ul, 0x7220656874206874ul, 0x492072616c756765ul, 0x656c696620444157ul, 0x6d200a646e612073ul, 0x6573756163207961ul, 0x6120736f6d656420ul, 0x6f7774656e20646eul, 0x73656d6167206b72ul, 0x20746567206f7420ul, 0x7320666f2074756ful, 0x4c50000a2e636e79ul, 0x5f4d004c41505941ul, 0x6f6d004553554150ul, 0x736e65735f657375ul, 0x79746976697469ul, 0x756c6f765f786673ul, 0x636973756d00656dul, 0x656d756c6f765ful, 0x73656d5f776f6873ul, 0x6373007365676173ul, 0x636f6c626e656572ul, 0x696174656400736bul, 0x73006c6576656c6cul, 0x6e6e6168635f646eul, 0x696e617600736c65ul, 0x657661735f616c6cul, 0x6d696c5f656d6167ul, 0x6c696e6176007469ul, 0x5f6f6d65645f616cul, 0x68730074696d696cul, 0x6f6f646e655f776ful, 0x616d74616863006dul, 0x61560069256f7263ul, 0x7373696d2064696cul, 0x6b636170206e6f69ul, 0xa3a6572612073ul, 0x6b6e55000a732509ul, 0x73696d206e776f6eul, 0x636170206e6f6973ul, 0x203a656d616e206bul, 0x313050414d007325ul, 0x6e5500314d314500ul, 0x726f206e776f6e6bul, 0x64696c61766e6920ul, 0x6966204441574920ul, 0x314d3445002e656cul, 0x702d00314d334500ul, 0x45455246006b6361ul, 0x455246004d4f4f44ul, 0x6e6b6e55004d4445ul, 0x65657246006e776ful, 0x6850203a6d6f6f64ul, 0x6854003120657361ul, 0x616d69746c552065ul, 0x4d4f4f44206574ul, 0x676552204d4f4f44ul, 0x64657265747369ul, 0x616853204d4f4f44ul, 0x4600657261776572ul, 0x7246004d44656572ul, 0x203a6d6f6f646565ul, 0x32206573616850ul, 0x203a32204d4f4f44ul, 0x206e6f206c6c6548ul, 0x4f44006874726145ul, 0x6c50203a32204d4ful, 0x452061696e6f7475ul, 0x6e656d6972657078ul, 0x32204d4f4f440074ul, 0x202d20544e54203aul, 0x6f6974756c697645ul, 0x6e6964646120006eul, 0x7325000a73252067ul, 0x206d6f6f44000a00ul, 0x2e31003636362e31ul, 0x6d6f6f4400363636ul, 0x372e312f372e3120ul, 0x6f4400372e310061ul, 0x3100382e31206d6ful, 0x206d6f6f4400382eul, 0x392e3100392e31ul, 0x6361680078636148ul, 0x616d69746c550078ul, 0x6d6f6f44206574ul, 0x6574616d69746c75ul, 0x44206c616e694600ul, 0x616e6966006d6f6ful, 0x206c616e6946006cul, 0x6c6128206d6f6f44ul, 0x6c616e6966002974ul, 0x5120786568430032ul, 0x6568630074736575ul, 0x76656d61672d0078ul, 0x53006e6f69737265ul, 0x646574726f707075ul, 0x657620656d616720ul, 0xa3a736e6f697372ul, 0x7325282073250900ul, 0x6f6e6b6e55000a29ul, 0x20656d6167206e77ul, 0x206e6f6973726576ul, 0x756d450027732527ul, 0x7420676e6974616cul, 0x7661686562206568ul, 0x7420666f20726f69ul, 0x2027732527206568ul, 0x6261747563657865ul, 0x65742d000a2e656cul, 0x6f72746e6f637473ul, 0x4f4f444e4500736cul, 0x47206d6f6f44004dul, 0x3020636972656e65ul, 0x696e495f5a00312eul, 0x2074696e49203a74ul, 0x6d656d20656e6f7aul, 0x6f6c6c612079726ful, 0x64206e6f69746163ul, 0xa202e6e6f6d6561ul, 0x736e6f6d6f6e2d00ul, 0x65722d0073726574ul, 0x662d006e77617073ul, 0x7665642d00747361ul, 0x65642d006d726170ul, 0x686374616d687461ul, 0x616564746c612d00ul, 0x6c65766544006874ul, 0x6d20746e656d706ful, 0xa2e4e4f2065646ful, 0x6f627275742d00ul, 0x6373206f62727574ul, 0x256925203a656c61ul, 0x696e495f56000a25ul, 0x636f6c6c61203a74ul, 0x6572637320657461ul, 0x5f4d000a2e736e65ul, 0x6166654464616f4cul, 0x6f4c203a73746c75ul, 0x6574737973206461ul, 0x6c7561666564206dul, 0x666564000a2e7374ul, 0x6766632e746c7561ul, 0x6e65676d6f6f6400ul, 0x6d6f6f6463697265ul, 0x6d6147006766632eul, 0x692065646f6d2065ul, 0x696d72657465646eul, 0x4e20202e6574616eul, 0x662044415749206ful, 0x2073617720656c69ul, 0x20202e646e756f66ul, 0x636570730a797254ul, 0x6f20676e69796669ul, 0x206874697720656eul, 0x77692d2720656874ul, 0x6d6d6f6320276461ul, 0x656e696c20646e61ul, 0x74656d6172617020ul, 0x495f57000a2e7265ul, 0x696e49203a74696eul, 0x6c69664441572074ul, 0x656d64000a2e7365ul, 0x464200636970756eul, 0x6f69746964452047ul, 0x676e697355203a6eul, 0x6f72616b726f7720ul, 0x2073612073646e75ul, 0xa2e64656465656eul, 0x656479616c702d00ul, 0x656d69742d006f6dul, 0x6d6c2e006f6d6564ul, 0x706d6c2e73250070ul, 0x676e6979616c5000ul, 0x7325206f6d656420ul, 0x20756f590a000a2eul, 0x2d20746f6e6e6163ul, 0x74697720656c6966ul, 0x6873206568742068ul, 0x2065726177657261ul, 0x2e6e6f6973726576ul, 0x6574736967655220ul, 0x736968540a002172ul, 0x20746f6e20736920ul, 0x6967657220656874ul, 0x7620646572657473ul, 0x2e6e6f69737265ul, 0x54524154535f5353ul, 0x444e455f464600ul, 0x474e494e52415720ul, 0x6f6c20656854203aul, 0x4441572064656461ul, 0x6f6320656c696620ul, 0x6d20736e6961746eul, 0x206465696669646ful, 0x2073657469727073ul, 0x6f6f6c66200a726ful, 0x7275747865742072ul, 0x756f5920202e7365ul, 0x6e61772079616d20ul, 0x657375206f742074ul, 0x6d2d272065687420ul, 0x6f63202765677265ul, 0x6c200a646e616d6dul, 0x6974706f20656e69ul, 0x6574736e69206e6ful, 0x2d2720666f206461ul, 0xa2e27656c6966ul, 0x474e494e52415720ul, 0x726120756f59203aul, 0x6e6979616c702065ul, 0x20676e6973752067ul, 0x7420666f20656e6ful, 0x6465657246206568ul, 0x44415749206d6f6ful, 0x2c73656c6966200aul, 0x6d20686369687720ul, 0x746f6e2074686769ul, 0x6e69206b726f7720ul, 0x6f70207369687420ul, 0x20656553202e7472ul, 0x6761702073696874ul, 0x6d20726f66200a65ul, 0x6f666e692065726ful, 0x206e6f6974616d72ul, 0x7420776f68206e6ful, 0x752079616c70206ful, 0x65724620676e6973ul, 0x200a3a6d6f6f6465ul, 0x2f3a707474682020ul, 0x6f68632e7777772ful, 0x642d6574616c6f63ul, 0x2f67726f2e6d6f6ful, 0x646e692f696b6977ul, 0x462f7068702e7865ul, 0xa6d6f6f64656572ul, 0x3a74696e495f4900ul, 0x676e697474655320ul, 0x6863616d20707520ul, 0x7461747320656e69ul, 0x696b732d000a2e65ul, 0x736970652d006c6cul, 0x6d69742d0065646ful, 0x6776612d007265ul, 0x6c2d00707261772dul, 0x656d616764616ful, 0x203a74696e495f4dul, 0x73696d2074696e49ul, 0x6f656e616c6c6563ul, 0x2e6f666e69207375ul, 0x74696e495f52000aul, 0x442074696e49203aul, 0x72666572204d4f4ful, 0x6d65616420687365ul, 0x500a00202d206e6ful, 0x49203a74696e495ful, 0x79616c502074696eul, 0x61747320706f6f6cul, 0x495f53000a2e6574ul, 0x746553203a74696eul, 0x20707520676e6974ul, 0xa2e646e756f73ul, 0x4e6b636568435f44ul, 0x203a656d61477465ul, 0x676e696b63656843ul, 0x6b726f7774656e20ul, 0x747320656d616720ul, 0x48000a2e73757461ul, 0x203a74696e495f55ul, 0x20676e6974746553ul, 0x7364616568207075ul, 0x7073696420707520ul, 0x5453000a2e79616cul, 0x49203a74696e495ful, 0x746174732074696eul, 0xa2e726162207375ul, 0x2d00313070616d00ul, 0x706d756474617473ul, 0x616e726574784500ul, 0x736974617473206cul, 0x6765722073636974ul, 0x2e64657265747369ul, 0x726f6365722d000aul, 0x64ul)

[init]
def private c2da_lin_init_static_d_main() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_d_main_seg[s * 2]
        for (k in range(c2da_lin_static_d_main_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_d_main[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_d_main_0 = fixed_array<uint8>(0x1, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_d_main() {
    c2da_lin_setup()
    for (i in range(4)) {
        c2da_mem[1968 + i] = c2da_lin_extern_d_main_0[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_d_main() {
    if (length(c2da_fn_table0) < 155) {
        resize(c2da_fn_table0, 155)
    }
    c2da_fn_table0[6] = @@D_ProcessEvents
    c2da_fn_table0[154] = @@D_Endoom
    if (length(c2da_fn_table2) < 155) {
        resize(c2da_fn_table2, 155)
    }
    c2da_fn_table2[2] = @@D_GrabMouseCallback
}

[init]
def private c2da_lin_relink_init_d_main() {
    c2da_relink_d_main()
}
