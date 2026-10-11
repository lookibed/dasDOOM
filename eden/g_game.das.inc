var private G_BuildTiccmd__carry : int16 = int16(0)

[sideeffects]
def private c2da___bswap_16_2(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_2(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_2(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_2(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_2(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_2(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
var gameskill : int = default<int>

var gameepisode : int = default<int>

var gamemap : int = default<int>

var timelimit : int = default<int>

var respawnmonsters : uint = default<uint>

var netgame : uint = default<uint>

var deathmatch : int = default<int>

var paused : uint = default<uint>

var viewactive : uint = default<uint>

var nodrawers : uint = default<uint>

var testcontrols : uint = 0u

var testcontrols_mousespeed : int = default<int>

var consoleplayer : int = default<int>

var displayplayer : int = default<int>

var totalkills : int = default<int>

var totalitems : int = default<int>

var totalsecret : int = default<int>

var levelstarttic : int = default<int>

var usergame : uint = default<uint>

var demoplayback : uint = default<uint>

var demorecording : uint = default<uint>

var lowres_turn : uint = default<uint>

var singledemo : uint = default<uint>

var gamestate : uint = default<uint>

var playeringame : uint[4]

var precache : uint = 1u

var bodyqueslot : int = default<int>

var gameaction : uint = default<uint>

[export, sideeffects]
def G_DeathMatchSpawnPlayer(var playernum : int) {
    var i : int
    var selections : int = int(int64((deathmatch_p - 40768) / 10))
    if (selections < 4) {
        I_Error(338784, [C2daVaArg(tag = 1, i64 = int64(selections), f64 = 0.0lf, raw = 0x0)])
    }
    for (j in range(0, 20)) {
        i = P_Random() % selections
        if (G_CheckSpot(playernum, 40768 + i * 10) != 0x0) {
            let c2da_fresh0 : int16 = int16(playernum + 1)
            let c2da_fresh1 : uint = uint(c2da_fresh0)
            c2da_mem[40768 + i * 10 + 6] = uint8(c2da_fresh1)
            c2da_mem[40768 + i * 10 + 7] = uint8(c2da_fresh1 >> 0x8)
            P_SpawnPlayer(40768 + i * 10)
            return
        }
    }
    P_SpawnPlayer(40880 + playernum * 10)
    return
}
[export, sideeffects]
def G_CheckSpot(var playernum_0 : int; var mthing : int) : uint {
    var x : int
    var y : int
    var ss : int
    var mo : int
    var xa : int
    var ya : int
    var an : int
    if (int(uint(c2da_mem[96 + playernum_0 * 328]) | uint(c2da_mem[96 + playernum_0 * 328 + 1]) << 0x8 | uint(c2da_mem[96 + playernum_0 * 328 + 2]) << 0x10 | uint(c2da_mem[96 + playernum_0 * 328 + 3]) << 0x18) == 0) {
        for (i_0 in range(0, playernum_0)) {
            let c2da_fresh2 : int = int(uint(c2da_mem[96 + i_0 * 328]) | uint(c2da_mem[96 + i_0 * 328 + 1]) << 0x8 | uint(c2da_mem[96 + i_0 * 328 + 2]) << 0x10 | uint(c2da_mem[96 + i_0 * 328 + 3]) << 0x18) + 24
            var c2da_fresh4 : int = 0
            if (int(uint(c2da_mem[c2da_fresh2]) | uint(c2da_mem[c2da_fresh2 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh2 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh2 + 3]) << 0x18) == int(int16(uint(c2da_mem[mthing]) | uint(c2da_mem[mthing + 1]) << 0x8)) << 16) {
                let c2da_fresh3 : int = int(uint(c2da_mem[96 + i_0 * 328]) | uint(c2da_mem[96 + i_0 * 328 + 1]) << 0x8 | uint(c2da_mem[96 + i_0 * 328 + 2]) << 0x10 | uint(c2da_mem[96 + i_0 * 328 + 3]) << 0x18) + 28
                if (int(uint(c2da_mem[c2da_fresh3]) | uint(c2da_mem[c2da_fresh3 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh3 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh3 + 3]) << 0x18) == int(int16(uint(c2da_mem[mthing + 2]) | uint(c2da_mem[mthing + 3]) << 0x8)) << 16) {
                    c2da_fresh4 = 1
                }
            }
            if (c2da_fresh4 != 0) {
                return 0u
            }
        }
        return 1u
    }
    x = int(int16(uint(c2da_mem[mthing]) | uint(c2da_mem[mthing + 1]) << 0x8)) << 16
    y = int(int16(uint(c2da_mem[mthing + 2]) | uint(c2da_mem[mthing + 3]) << 0x8)) << 16
    if (P_CheckPosition(int(uint(c2da_mem[96 + playernum_0 * 328]) | uint(c2da_mem[96 + playernum_0 * 328 + 1]) << 0x8 | uint(c2da_mem[96 + playernum_0 * 328 + 2]) << 0x10 | uint(c2da_mem[96 + playernum_0 * 328 + 3]) << 0x18), x, y) == 0) {
        return 0u
    }
    if (bodyqueslot >= 32) {
        P_RemoveMobj(bodyque[bodyqueslot % 32])
    }
    bodyque[bodyqueslot % 32] = int(uint(c2da_mem[96 + playernum_0 * 328]) | uint(c2da_mem[96 + playernum_0 * 328 + 1]) << 0x8 | uint(c2da_mem[96 + playernum_0 * 328 + 2]) << 0x10 | uint(c2da_mem[96 + playernum_0 * 328 + 3]) << 0x18)
    bodyqueslot++
    ss = R_PointInSubsector(x, y)
    an = (536870912 >> 19) * (int(int16(uint(c2da_mem[mthing + 4]) | uint(c2da_mem[mthing + 5]) << 0x8)) / 45)
    if (an == 4096) {
        xa = finetangent[2048]
        ya = finetangent[0]
    } elif (an == 5120) {
        xa = finetangent[3072]
        ya = finetangent[1024]
    } elif (an == 6144) {
        xa = int(uint(c2da_mem[257920 + 0 * 4]) | uint(c2da_mem[257920 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + 0 * 4 + 3]) << 0x18)
        ya = finetangent[2048]
    } elif (an == 7168) {
        xa = int(uint(c2da_mem[257920 + 1024 * 4]) | uint(c2da_mem[257920 + 1024 * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + 1024 * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + 1024 * 4 + 3]) << 0x18)
        ya = finetangent[3072]
    } elif (an == 0 || an == 1024 || an == 2048 || an == 3072) {
        xa = int(uint(c2da_mem[finecosine + an * 4]) | uint(c2da_mem[finecosine + an * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + an * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + an * 4 + 3]) << 0x18)
        ya = int(uint(c2da_mem[257920 + an * 4]) | uint(c2da_mem[257920 + an * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + an * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + an * 4 + 3]) << 0x18)
    } else {
        I_Error(338821, [C2daVaArg(tag = 1, i64 = int64(an), f64 = 0.0lf, raw = 0x0)])
        ya = 0
        xa = ya
    }
    let c2da_fresh5 : int = int(uint(c2da_mem[ss]) | uint(c2da_mem[ss + 1]) << 0x8 | uint(c2da_mem[ss + 2]) << 0x10 | uint(c2da_mem[ss + 3]) << 0x18)
    mo = P_SpawnMobj(x + 20 * xa, y + 20 * ya, int(uint(c2da_mem[c2da_fresh5]) | uint(c2da_mem[c2da_fresh5 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh5 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh5 + 3]) << 0x18), 39u)
    if (int(uint(c2da_mem[96 + consoleplayer * 328 + 28]) | uint(c2da_mem[96 + consoleplayer * 328 + 29]) << 0x8 | uint(c2da_mem[96 + consoleplayer * 328 + 30]) << 0x10 | uint(c2da_mem[96 + consoleplayer * 328 + 31]) << 0x18) != 1) {
        S_StartSound(mo, 35)
    }
    return 1u
}
var bodyque : int[32]

[export, sideeffects]
def G_InitNew(var skill : int; var episode : int; var map : int) {
    var skytexturename : int
    var i_1 : int
    if (paused != 0x0) {
        paused = 0u
        S_ResumeSound()
    }
    if (skill > 4) {
        skill = 4
    }
    if (uint(gameversion) >= 6u) {
        if (episode == 0) {
            episode = 4
        }
    } else {
        if (episode < 1) {
            episode = 1
        }
        if (episode > 3) {
            episode = 3
        }
    }
    if (episode > 1 && uint(gamemode) == 0u) {
        episode = 1
    }
    if (map < 1) {
        map = 1
    }
    if (map > 9 && uint(gamemode) != 2u) {
        map = 9
    }
    M_ClearRandom()
    if (skill == 4 || respawnparm != 0x0) {
        respawnmonsters = 1u
    } else {
        respawnmonsters = 0u
    }
    if (fastparm != 0x0 || skill == 4 && gameskill != 4) {
        i_1 = 477
        while (i_1 <= 489) {
            let c2da_fresh6 : int = int(uint(c2da_mem[2080 + i_1 * 40 + 8]) | uint(c2da_mem[2080 + i_1 * 40 + 9]) << 0x8 | uint(c2da_mem[2080 + i_1 * 40 + 10]) << 0x10 | uint(c2da_mem[2080 + i_1 * 40 + 11]) << 0x18) >> 1
            let c2da_fresh7 : uint = uint(c2da_fresh6)
            c2da_mem[2080 + i_1 * 40 + 8] = uint8(c2da_fresh7)
            c2da_mem[2080 + i_1 * 40 + 9] = uint8(c2da_fresh7 >> 0x8)
            c2da_mem[2080 + i_1 * 40 + 10] = uint8(c2da_fresh7 >> 0x10)
            c2da_mem[2080 + i_1 * 40 + 11] = uint8(c2da_fresh7 >> 0x18)
            i_1++
        }
        let c2da_fresh8 : int = 20 * (1 << 16)
        let c2da_fresh9 : uint = uint(c2da_fresh8)
        c2da_mem[51056 + 16 * 92 + 60] = uint8(c2da_fresh9)
        c2da_mem[51056 + 16 * 92 + 61] = uint8(c2da_fresh9 >> 0x8)
        c2da_mem[51056 + 16 * 92 + 62] = uint8(c2da_fresh9 >> 0x10)
        c2da_mem[51056 + 16 * 92 + 63] = uint8(c2da_fresh9 >> 0x18)
        let c2da_fresh10 : int = 20 * (1 << 16)
        let c2da_fresh11 : uint = uint(c2da_fresh10)
        c2da_mem[51056 + 32 * 92 + 60] = uint8(c2da_fresh11)
        c2da_mem[51056 + 32 * 92 + 61] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[51056 + 32 * 92 + 62] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[51056 + 32 * 92 + 63] = uint8(c2da_fresh11 >> 0x18)
        let c2da_fresh12 : int = 20 * (1 << 16)
        let c2da_fresh13 : uint = uint(c2da_fresh12)
        c2da_mem[51056 + 31 * 92 + 60] = uint8(c2da_fresh13)
        c2da_mem[51056 + 31 * 92 + 61] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[51056 + 31 * 92 + 62] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[51056 + 31 * 92 + 63] = uint8(c2da_fresh13 >> 0x18)
    } elif (skill != 4 && gameskill == 4) {
        i_1 = 477
        while (i_1 <= 489) {
            let c2da_fresh14 : int = int(uint(c2da_mem[2080 + i_1 * 40 + 8]) | uint(c2da_mem[2080 + i_1 * 40 + 9]) << 0x8 | uint(c2da_mem[2080 + i_1 * 40 + 10]) << 0x10 | uint(c2da_mem[2080 + i_1 * 40 + 11]) << 0x18) << 1
            let c2da_fresh15 : uint = uint(c2da_fresh14)
            c2da_mem[2080 + i_1 * 40 + 8] = uint8(c2da_fresh15)
            c2da_mem[2080 + i_1 * 40 + 9] = uint8(c2da_fresh15 >> 0x8)
            c2da_mem[2080 + i_1 * 40 + 10] = uint8(c2da_fresh15 >> 0x10)
            c2da_mem[2080 + i_1 * 40 + 11] = uint8(c2da_fresh15 >> 0x18)
            i_1++
        }
        let c2da_fresh16 : int = 15 * (1 << 16)
        let c2da_fresh17 : uint = uint(c2da_fresh16)
        c2da_mem[51056 + 16 * 92 + 60] = uint8(c2da_fresh17)
        c2da_mem[51056 + 16 * 92 + 61] = uint8(c2da_fresh17 >> 0x8)
        c2da_mem[51056 + 16 * 92 + 62] = uint8(c2da_fresh17 >> 0x10)
        c2da_mem[51056 + 16 * 92 + 63] = uint8(c2da_fresh17 >> 0x18)
        let c2da_fresh18 : int = 10 * (1 << 16)
        let c2da_fresh19 : uint = uint(c2da_fresh18)
        c2da_mem[51056 + 32 * 92 + 60] = uint8(c2da_fresh19)
        c2da_mem[51056 + 32 * 92 + 61] = uint8(c2da_fresh19 >> 0x8)
        c2da_mem[51056 + 32 * 92 + 62] = uint8(c2da_fresh19 >> 0x10)
        c2da_mem[51056 + 32 * 92 + 63] = uint8(c2da_fresh19 >> 0x18)
        let c2da_fresh20 : int = 10 * (1 << 16)
        let c2da_fresh21 : uint = uint(c2da_fresh20)
        c2da_mem[51056 + 31 * 92 + 60] = uint8(c2da_fresh21)
        c2da_mem[51056 + 31 * 92 + 61] = uint8(c2da_fresh21 >> 0x8)
        c2da_mem[51056 + 31 * 92 + 62] = uint8(c2da_fresh21 >> 0x10)
        c2da_mem[51056 + 31 * 92 + 63] = uint8(c2da_fresh21 >> 0x18)
    }
    i_1 = 0
    while (i_1 < 4) {
        let c2da_fresh22 : uint = 2u
        let c2da_fresh23 : uint = c2da_fresh22
        c2da_mem[96 + i_1 * 328 + 8] = uint8(c2da_fresh23)
        c2da_mem[96 + i_1 * 328 + 9] = uint8(c2da_fresh23 >> 0x8)
        c2da_mem[96 + i_1 * 328 + 10] = uint8(c2da_fresh23 >> 0x10)
        c2da_mem[96 + i_1 * 328 + 11] = uint8(c2da_fresh23 >> 0x18)
        i_1++
    }
    usergame = 1u
    paused = 0u
    demoplayback = 0u
    automapactive = 0u
    viewactive = 1u
    gameepisode = int(episode)  // nolint:PERF020
    gamemap = int(map)  // nolint:PERF020
    gameskill = int(skill)  // nolint:PERF020
    viewactive = 1u
    if (uint(gamemode) == 2u) {
        if (gamemap < 12) {
            skytexturename = 338855
        } elif (gamemap < 21) {
            skytexturename = 338860
        } else {
            skytexturename = 338865
        }
    } elif (gameepisode == 2) {
        skytexturename = 338860
    } elif (gameepisode == 3) {
        skytexturename = 338865
    } elif (gameepisode == 4) {
        skytexturename = 338870
    } else {
        skytexturename = 338855
    }
    skytexture = R_TextureNumForName(skytexturename)
    G_DoLoadLevel()
    return
}
[export, sideeffects]
def G_DoLoadLevel() {
    var skytexturename_0 : int
    skyflatnum = R_FlatNumForName(338875)
    if (uint(gamemode) == 2u && (uint(gameversion) == 8u || uint(gameversion) == 9u)) {
        if (gamemap < 12) {
            skytexturename_0 = 338855
        } elif (gamemap < 21) {
            skytexturename_0 = 338860
        } else {
            skytexturename_0 = 338865
        }
        skytexture = R_TextureNumForName(skytexturename_0)
    }
    levelstarttic = gametic
    if (uint(wipegamestate) == 0u) {
        wipegamestate = 4294967295u
    }
    gamestate = 0u
    for (i_2 in range(0, 4)) {
        turbodetected[i_2] = 0u
        if (playeringame[i_2] != 0x0 && (uint(c2da_mem[96 + i_2 * 328 + 8]) | uint(c2da_mem[96 + i_2 * 328 + 9]) << 0x8 | uint(c2da_mem[96 + i_2 * 328 + 10]) << 0x10 | uint(c2da_mem[96 + i_2 * 328 + 11]) << 0x18) == 1u) {
            let c2da_fresh24 : uint = 2u
            let c2da_fresh25 : uint = c2da_fresh24
            c2da_mem[96 + i_2 * 328 + 8] = uint8(c2da_fresh25)
            c2da_mem[96 + i_2 * 328 + 9] = uint8(c2da_fresh25 >> 0x8)
            c2da_mem[96 + i_2 * 328 + 10] = uint8(c2da_fresh25 >> 0x10)
            c2da_mem[96 + i_2 * 328 + 11] = uint8(c2da_fresh25 >> 0x18)
        }
        c2da_lin_memset(96 + i_2 * 328 + 108, 0, 16ul)
    }
    P_SetupLevel(gameepisode, gamemap, 0, gameskill)
    displayplayer = int(consoleplayer)  // nolint:PERF020
    gameaction = 0u
    Z_CheckHeap()
    c2da_lin_memset(337344, 0, 1024ul)
    joystrafemove = 0
    joyymove = int(joystrafemove)  // nolint:PERF020
    joyxmove = int(joyymove)  // nolint:PERF020
    mousey = 0
    mousex = int(mousey)  // nolint:PERF020
    paused = 0u
    sendsave = uint(paused)  // nolint:PERF020
    sendpause = uint(sendsave)  // nolint:PERF020
    c2da_lin_memset(338368, 0, 36ul)
    c2da_lin_memset(338416, 0, 84ul)
    if (testcontrols != 0x0) {
        let c2da_fresh26 : uint = 338882u
        c2da_mem[96 + consoleplayer * 328 + 232] = uint8(c2da_fresh26)
        c2da_mem[96 + consoleplayer * 328 + 233] = uint8(c2da_fresh26 >> 0x8)
        c2da_mem[96 + consoleplayer * 328 + 234] = uint8(c2da_fresh26 >> 0x10)
        c2da_mem[96 + consoleplayer * 328 + 235] = uint8(c2da_fresh26 >> 0x18)
        c2da_mem[96 + consoleplayer * 328 + 236] = 0u8
        c2da_mem[96 + consoleplayer * 328 + 237] = 0u8
        c2da_mem[96 + consoleplayer * 328 + 238] = 0u8
        c2da_mem[96 + consoleplayer * 328 + 239] = 0u8
    }
    return
}
var sendsave : uint = default<uint>

var sendpause : uint = default<uint>

var mousey : int = default<int>

var mousex : int = default<int>

var private joystrafemove : int = default<int>

var private joyymove : int = default<int>

var private joyxmove : int = default<int>

var turbodetected : uint[4]

[export, sideeffects]
def G_DeferedInitNew(var skill_0 : int; var episode_0 : int; var map_0 : int) {
    d_skill = int(skill_0)  // nolint:PERF020
    d_episode = int(episode_0)  // nolint:PERF020
    d_map = int(map_0)  // nolint:PERF020
    gameaction = 2u
    return
}
var d_map : int = default<int>

var d_episode : int = default<int>

var d_skill : int = default<int>

[export, sideeffects]
def G_DeferedPlayDemo(var name : int) {
    defdemoname = int(name)  // nolint:PERF020
    gameaction = 5u
    return
}
var defdemoname : int = default<int>

[export, sideeffects]
def G_LoadGame(var name_0 : int) {
    M_StringCopy(40928, name_0, 256ul)
    gameaction = 3u
    return
}
[export, sideeffects]
def G_DoLoadGame() {
    var savedleveltime : int
    gameaction = 0u
    save_stream = c2da_lin_fopen(40928, 338904)
    if (save_stream == 0) {
        return
    }
    savegame_error = 0u
    if (P_ReadSaveGameHeader() == 0) {
        c2da_std_fclose(uint64(save_stream))
        return
    }
    savedleveltime = leveltime
    G_InitNew(gameskill, gameepisode, gamemap)
    leveltime = savedleveltime
    P_UnArchivePlayers()
    P_UnArchiveWorld()
    P_UnArchiveThinkers()
    P_UnArchiveSpecials()
    if (P_ReadSaveGameEOF() == 0) {
        I_Error(338907, [])
    }
    c2da_std_fclose(uint64(save_stream))
    if (setsizeneeded != 0x0) {
        R_ExecuteSetViewSize()
    }
    R_FillBackScreen()
    return
}
[export, sideeffects]
def G_SaveGame(var slot : int; var description : int) {
    savegameslot = int(slot)  // nolint:PERF020
    M_StringCopy(338512, description, 32ul)
    sendsave = 1u
    return
}
var private savegameslot : int = default<int>

[export, sideeffects]
def G_RecordDemo(var name_1 : int) {
    var demoname_size : uint64
    var i_3 : int
    var maxsize : int
    usergame = 0u
    demoname_size = uint64(c2da_lin_strlen(name_1) + 5ul)
    demoname = Z_Malloc(int(demoname_size), 1, 0)
    M_snprintf(demoname, demoname_size, 338920, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(name_1))])
    maxsize = 131072
    i_3 = M_CheckParmWithArgs(338927, 1)
    if (i_3 != 0) {
        maxsize = c2da_lin_atoi(int(uint(c2da_mem[myargv + (i_3 + 1) * 8]) | uint(c2da_mem[myargv + (i_3 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (i_3 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (i_3 + 1) * 8 + 3]) << 0x18)) * 1024
    }
    demobuffer = Z_Malloc(maxsize, 1, 0)
    demoend = demobuffer + maxsize
    demorecording = 1u
    return
}
var demobuffer : int = default<int>

var demoend : int = default<int>

var demoname : int = default<int>

[export, sideeffects]
def G_BeginRecording() {
    longtics = uint(M_CheckParm(338936) != 0 ? 1 : 0)
    lowres_turn = longtics == 0 ? 1u : 0u
    demo_p = int(demobuffer)  // nolint:PERF020
    if (longtics != 0x0) {
        let c2da_fresh27 : int = demo_p
        demo_p++
        let c2da_fresh28 : uint8 = 111u8
        c2da_mem[c2da_fresh27] = c2da_fresh28
    } else {
        let c2da_fresh29 : int = demo_p
        demo_p++
        let c2da_fresh30 : uint8 = uint8(G_VanillaVersionCode())
        c2da_mem[c2da_fresh29] = c2da_fresh30
    }
    let c2da_fresh31 : int = demo_p
    demo_p++
    let c2da_fresh32 : uint8 = uint8(gameskill)
    c2da_mem[c2da_fresh31] = c2da_fresh32
    let c2da_fresh33 : int = demo_p
    demo_p++
    let c2da_fresh34 : uint8 = uint8(gameepisode)
    c2da_mem[c2da_fresh33] = c2da_fresh34
    let c2da_fresh35 : int = demo_p
    demo_p++
    let c2da_fresh36 : uint8 = uint8(gamemap)
    c2da_mem[c2da_fresh35] = c2da_fresh36
    let c2da_fresh37 : int = demo_p
    demo_p++
    let c2da_fresh38 : uint8 = uint8(deathmatch)
    c2da_mem[c2da_fresh37] = c2da_fresh38
    let c2da_fresh39 : int = demo_p
    demo_p++
    let c2da_fresh40 : uint8 = uint8(respawnparm)
    c2da_mem[c2da_fresh39] = c2da_fresh40
    let c2da_fresh41 : int = demo_p
    demo_p++
    let c2da_fresh42 : uint8 = uint8(fastparm)
    c2da_mem[c2da_fresh41] = c2da_fresh42
    let c2da_fresh43 : int = demo_p
    demo_p++
    let c2da_fresh44 : uint8 = uint8(nomonsters)
    c2da_mem[c2da_fresh43] = c2da_fresh44
    let c2da_fresh45 : int = demo_p
    demo_p++
    let c2da_fresh46 : uint8 = uint8(consoleplayer)
    c2da_mem[c2da_fresh45] = c2da_fresh46
    for (i_4 in range(0, 4)) {
        let c2da_fresh47 : int = demo_p
        demo_p++
        let c2da_fresh48 : uint8 = uint8(playeringame[i_4])
        c2da_mem[c2da_fresh47] = c2da_fresh48
    }
    return
}
var demo_p : int = default<int>

[export, sideeffects]
def G_VanillaVersionCode() : int {
    let c2da_fresh49 : uint = uint(gameversion)
    if (c2da_fresh49 <= 0x4u) {
        goto int(c2da_fresh49) + 1
    }
    goto label 0
    label 1:
    I_Error(338946, [])
    label 2:
    return 106
    label 3:
    return 107
    label 4:
    return 108
    label 0:
    label 5:
    return 109
}
var longtics : uint = default<uint>

[export, sideeffects]
def G_TimeDemo(var name_2 : int) {
    nodrawers = uint(M_CheckParm(338985))
    timingdemo = 1u
    singletics = 1u
    defdemoname = int(name_2)  // nolint:PERF020
    gameaction = 5u
    return
}
var timingdemo : uint = default<uint>

[export, sideeffects]
def G_CheckDemoStatus() : uint {
    var endtime : int
    var fps : float
    var realtics : int
    if (timingdemo != 0x0) {
        endtime = I_GetTime()
        realtics = endtime - starttime
        fps = float(gametic) * 35.0 / float(realtics)
        timingdemo = 0u
        demoplayback = 0u
        I_Error(338993, [C2daVaArg(tag = 1, i64 = int64(gametic), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(realtics), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 2, i64 = 0, f64 = double(fps), raw = 0x0)])
    }
    if (demoplayback != 0x0) {
        W_ReleaseLumpName(defdemoname)
        demoplayback = 0u
        netdemo = 0u
        netgame = 0u
        deathmatch = 0
        playeringame[3] = 0u
        playeringame[2] = uint(playeringame[3])  // nolint:PERF020
        playeringame[1] = uint(playeringame[2])  // nolint:PERF020
        respawnparm = 0u
        fastparm = 0u
        nomonsters = 0u
        consoleplayer = 0
        if (singledemo != 0x0) {
            I_Quit()
        } else {
            D_AdvanceDemo()
        }
        return 1u
    }
    if (demorecording != 0x0) {
        let c2da_fresh50 : int = demo_p
        demo_p++
        let c2da_fresh51 : uint8 = 0x80u8
        c2da_mem[c2da_fresh50] = c2da_fresh51
        M_WriteFile(demoname, demobuffer, demo_p - demobuffer)
        Z_Free(demobuffer)
        demorecording = 0u
        I_Error(339035, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(demoname))])
    }
    return 0u
}
var netdemo : uint = default<uint>

var starttime : int = default<int>

[export, sideeffects]
def G_ExitLevel() {
    secretexit = 0u
    gameaction = 6u
    return
}
var secretexit : uint = default<uint>

[export, sideeffects]
def G_SecretExitLevel() {
    if (uint(gamemode) == 2u && W_CheckNumForName(339052) < 0) {
        secretexit = 0u
    } else {
        secretexit = 1u
    }
    gameaction = 6u
    return
}
[export, sideeffects]
def G_WorldDone() {
    gameaction = 8u
    if (secretexit != 0x0) {
        let c2da_fresh52 : uint = 1u
        let c2da_fresh53 : uint = c2da_fresh52
        c2da_mem[96 + consoleplayer * 328 + 320] = uint8(c2da_fresh53)
        c2da_mem[96 + consoleplayer * 328 + 321] = uint8(c2da_fresh53 >> 0x8)
        c2da_mem[96 + consoleplayer * 328 + 322] = uint8(c2da_fresh53 >> 0x10)
        c2da_mem[96 + consoleplayer * 328 + 323] = uint8(c2da_fresh53 >> 0x18)
    }
    if (uint(gamemode) == 2u) {
        if (gamemap < 20) {
            if (gamemap == 6) {
                goto label 2
            } elif (gamemap == 11) {
                goto label 2
            } elif (gamemap == 15) {
                goto label 1
            }
        } else {
            if (gamemap == 20) {
                goto label 2
            } elif (gamemap == 30) {
                goto label 2
            } elif (gamemap == 31) {
                goto label 1
            }
        }
        return
        label 0:
        return
        label 1:
        if (secretexit == 0) {
            goto label 0
        }
        label 2:
        F_StartFinale()
    }
    return
}
[export, sideeffects]
def G_BuildTiccmd(var cmd : int; var maketic_0 : int) {
    var i_5 : int
    var strafe : uint
    var bstrafe : uint
    var speed : int
    var tspeed : int
    var forward : int
    var side : int
    var key : int
    var desired_angleturn : int16
    c2da_lin_memset(cmd, 0, 16ul)
    let c2da_fresh54 : uint8 = consistancy[consoleplayer][maketic_0 % 128]
    c2da_mem[cmd + 6] = c2da_fresh54
    let c2da_fresh55 : int = 337344 + int(uint(c2da_mem[42512]) | uint(c2da_mem[42513]) << 0x8 | uint(c2da_mem[42514]) << 0x10 | uint(c2da_mem[42515]) << 0x18) * 4
    var c2da_fresh57 : int = 1
    if (!((uint(c2da_mem[c2da_fresh55]) | uint(c2da_mem[c2da_fresh55 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh55 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh55 + 3]) << 0x18) != 0x0)) {
        let c2da_fresh56 : int = mousebuttons + int(uint(c2da_mem[42560]) | uint(c2da_mem[42561]) << 0x8 | uint(c2da_mem[42562]) << 0x10 | uint(c2da_mem[42563]) << 0x18) * 4
        if (!((uint(c2da_mem[c2da_fresh56]) | uint(c2da_mem[c2da_fresh56 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh56 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh56 + 3]) << 0x18) != 0x0)) {
            c2da_fresh57 = 0
        }
    }
    var c2da_fresh59 : int = 1
    if (!(c2da_fresh57 != 0)) {
        let c2da_fresh58 : int = joybuttons + int(uint(c2da_mem[42608]) | uint(c2da_mem[42609]) << 0x8 | uint(c2da_mem[42610]) << 0x10 | uint(c2da_mem[42611]) << 0x18) * 4
        if (!((uint(c2da_mem[c2da_fresh58]) | uint(c2da_mem[c2da_fresh58 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh58 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh58 + 3]) << 0x18) != 0x0)) {
            c2da_fresh59 = 0
        }
    }
    strafe = uint(c2da_fresh59)
    var c2da_fresh61 : int = 1
    if (!(int(uint(c2da_mem[42528]) | uint(c2da_mem[42529]) << 0x8 | uint(c2da_mem[42530]) << 0x10 | uint(c2da_mem[42531]) << 0x18) >= 256 || int(uint(c2da_mem[42640]) | uint(c2da_mem[42641]) << 0x8 | uint(c2da_mem[42642]) << 0x10 | uint(c2da_mem[42643]) << 0x18) >= 20)) {
        let c2da_fresh60 : int = 337344 + int(uint(c2da_mem[42528]) | uint(c2da_mem[42529]) << 0x8 | uint(c2da_mem[42530]) << 0x10 | uint(c2da_mem[42531]) << 0x18) * 4
        if (!((uint(c2da_mem[c2da_fresh60]) | uint(c2da_mem[c2da_fresh60 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh60 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh60 + 3]) << 0x18) != 0x0)) {
            c2da_fresh61 = 0
        }
    }
    var c2da_fresh63 : int = 1
    if (!(c2da_fresh61 != 0)) {
        let c2da_fresh62 : int = joybuttons + int(uint(c2da_mem[42640]) | uint(c2da_mem[42641]) << 0x8 | uint(c2da_mem[42642]) << 0x10 | uint(c2da_mem[42643]) << 0x18) * 4
        if (!((uint(c2da_mem[c2da_fresh62]) | uint(c2da_mem[c2da_fresh62 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh62 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh62 + 3]) << 0x18) != 0x0)) {
            c2da_fresh63 = 0
        }
    }
    speed = c2da_fresh63
    side = 0
    forward = side
    var c2da_fresh65 : int = 1
    if (!(joyxmove < 0 || joyxmove > 0)) {
        let c2da_fresh64 : int = 337344 + int(uint(c2da_mem[42384]) | uint(c2da_mem[42385]) << 0x8 | uint(c2da_mem[42386]) << 0x10 | uint(c2da_mem[42387]) << 0x18) * 4
        if (!((uint(c2da_mem[c2da_fresh64]) | uint(c2da_mem[c2da_fresh64 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh64 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh64 + 3]) << 0x18) != 0x0)) {
            c2da_fresh65 = 0
        }
    }
    var c2da_fresh67 : int = 1
    if (!(c2da_fresh65 != 0)) {
        let c2da_fresh66 : int = 337344 + int(uint(c2da_mem[42400]) | uint(c2da_mem[42401]) << 0x8 | uint(c2da_mem[42402]) << 0x10 | uint(c2da_mem[42403]) << 0x18) * 4
        if (!((uint(c2da_mem[c2da_fresh66]) | uint(c2da_mem[c2da_fresh66 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh66 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh66 + 3]) << 0x18) != 0x0)) {
            c2da_fresh67 = 0
        }
    }
    if (c2da_fresh67 != 0) {
        turnheld = turnheld + ticdup
    } else {
        turnheld = 0
    }
    if (turnheld < 6) {
        tspeed = 2
    } else {
        tspeed = speed
    }
    if (strafe != 0x0) {
        let c2da_fresh68 : int = 337344 + int(uint(c2da_mem[42384]) | uint(c2da_mem[42385]) << 0x8 | uint(c2da_mem[42386]) << 0x10 | uint(c2da_mem[42387]) << 0x18) * 4
        if ((uint(c2da_mem[c2da_fresh68]) | uint(c2da_mem[c2da_fresh68 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh68 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh68 + 3]) << 0x18) != 0x0) {
            side += sidemove[speed]
        }
        let c2da_fresh69 : int = 337344 + int(uint(c2da_mem[42400]) | uint(c2da_mem[42401]) << 0x8 | uint(c2da_mem[42402]) << 0x10 | uint(c2da_mem[42403]) << 0x18) * 4
        if ((uint(c2da_mem[c2da_fresh69]) | uint(c2da_mem[c2da_fresh69 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh69 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh69 + 3]) << 0x18) != 0x0) {
            side -= sidemove[speed]
        }
        if (joyxmove > 0) {
            side += sidemove[speed]
        }
        if (joyxmove < 0) {
            side -= sidemove[speed]
        }
    } else {
        let c2da_fresh70 : int = 337344 + int(uint(c2da_mem[42384]) | uint(c2da_mem[42385]) << 0x8 | uint(c2da_mem[42386]) << 0x10 | uint(c2da_mem[42387]) << 0x18) * 4
        if ((uint(c2da_mem[c2da_fresh70]) | uint(c2da_mem[c2da_fresh70 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh70 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh70 + 3]) << 0x18) != 0x0) {
            let c2da_fresh71 : int16 = int16(int(int16(uint(c2da_mem[cmd + 2]) | uint(c2da_mem[cmd + 3]) << 0x8)) - angleturn[tspeed])
            let c2da_fresh72 : uint = uint(c2da_fresh71)
            c2da_mem[cmd + 2] = uint8(c2da_fresh72)
            c2da_mem[cmd + 3] = uint8(c2da_fresh72 >> 0x8)
        }
        let c2da_fresh73 : int = 337344 + int(uint(c2da_mem[42400]) | uint(c2da_mem[42401]) << 0x8 | uint(c2da_mem[42402]) << 0x10 | uint(c2da_mem[42403]) << 0x18) * 4
        if ((uint(c2da_mem[c2da_fresh73]) | uint(c2da_mem[c2da_fresh73 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh73 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh73 + 3]) << 0x18) != 0x0) {
            let c2da_fresh74 : int16 = int16(int(int16(uint(c2da_mem[cmd + 2]) | uint(c2da_mem[cmd + 3]) << 0x8)) + angleturn[tspeed])
            let c2da_fresh75 : uint = uint(c2da_fresh74)
            c2da_mem[cmd + 2] = uint8(c2da_fresh75)
            c2da_mem[cmd + 3] = uint8(c2da_fresh75 >> 0x8)
        }
        if (joyxmove > 0) {
            let c2da_fresh76 : int16 = int16(int(int16(uint(c2da_mem[cmd + 2]) | uint(c2da_mem[cmd + 3]) << 0x8)) - angleturn[tspeed])
            let c2da_fresh77 : uint = uint(c2da_fresh76)
            c2da_mem[cmd + 2] = uint8(c2da_fresh77)
            c2da_mem[cmd + 3] = uint8(c2da_fresh77 >> 0x8)
        }
        if (joyxmove < 0) {
            let c2da_fresh78 : int16 = int16(int(int16(uint(c2da_mem[cmd + 2]) | uint(c2da_mem[cmd + 3]) << 0x8)) + angleturn[tspeed])
            let c2da_fresh79 : uint = uint(c2da_fresh78)
            c2da_mem[cmd + 2] = uint8(c2da_fresh79)
            c2da_mem[cmd + 3] = uint8(c2da_fresh79 >> 0x8)
        }
    }
    let c2da_fresh80 : int = 337344 + int(uint(c2da_mem[42416]) | uint(c2da_mem[42417]) << 0x8 | uint(c2da_mem[42418]) << 0x10 | uint(c2da_mem[42419]) << 0x18) * 4
    if ((uint(c2da_mem[c2da_fresh80]) | uint(c2da_mem[c2da_fresh80 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh80 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh80 + 3]) << 0x18) != 0x0) {
        forward += forwardmove[speed]
    }
    let c2da_fresh81 : int = 337344 + int(uint(c2da_mem[42432]) | uint(c2da_mem[42433]) << 0x8 | uint(c2da_mem[42434]) << 0x10 | uint(c2da_mem[42435]) << 0x18) * 4
    if ((uint(c2da_mem[c2da_fresh81]) | uint(c2da_mem[c2da_fresh81 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh81 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh81 + 3]) << 0x18) != 0x0) {
        forward -= forwardmove[speed]
    }
    if (joyymove < 0) {
        forward += forwardmove[speed]
    }
    if (joyymove > 0) {
        forward -= forwardmove[speed]
    }
    let c2da_fresh82 : int = 337344 + int(uint(c2da_mem[42448]) | uint(c2da_mem[42449]) << 0x8 | uint(c2da_mem[42450]) << 0x10 | uint(c2da_mem[42451]) << 0x18) * 4
    var c2da_fresh84 : int = 1
    if (!((uint(c2da_mem[c2da_fresh82]) | uint(c2da_mem[c2da_fresh82 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh82 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh82 + 3]) << 0x18) != 0x0)) {
        let c2da_fresh83 : int = joybuttons + int(uint(c2da_mem[42672]) | uint(c2da_mem[42673]) << 0x8 | uint(c2da_mem[42674]) << 0x10 | uint(c2da_mem[42675]) << 0x18) * 4
        if (!((uint(c2da_mem[c2da_fresh83]) | uint(c2da_mem[c2da_fresh83 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh83 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh83 + 3]) << 0x18) != 0x0)) {
            c2da_fresh84 = 0
        }
    }
    var c2da_fresh86 : int = 1
    if (!(c2da_fresh84 != 0)) {
        let c2da_fresh85 : int = mousebuttons + int(uint(c2da_mem[42704]) | uint(c2da_mem[42705]) << 0x8 | uint(c2da_mem[42706]) << 0x10 | uint(c2da_mem[42707]) << 0x18) * 4
        if (!((uint(c2da_mem[c2da_fresh85]) | uint(c2da_mem[c2da_fresh85 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh85 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh85 + 3]) << 0x18) != 0x0)) {
            c2da_fresh86 = 0
        }
    }
    if (c2da_fresh86 != 0 || joystrafemove < 0) {
        side -= sidemove[speed]
    }
    let c2da_fresh87 : int = 337344 + int(uint(c2da_mem[42464]) | uint(c2da_mem[42465]) << 0x8 | uint(c2da_mem[42466]) << 0x10 | uint(c2da_mem[42467]) << 0x18) * 4
    var c2da_fresh89 : int = 1
    if (!((uint(c2da_mem[c2da_fresh87]) | uint(c2da_mem[c2da_fresh87 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh87 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh87 + 3]) << 0x18) != 0x0)) {
        let c2da_fresh88 : int = joybuttons + int(uint(c2da_mem[42688]) | uint(c2da_mem[42689]) << 0x8 | uint(c2da_mem[42690]) << 0x10 | uint(c2da_mem[42691]) << 0x18) * 4
        if (!((uint(c2da_mem[c2da_fresh88]) | uint(c2da_mem[c2da_fresh88 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh88 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh88 + 3]) << 0x18) != 0x0)) {
            c2da_fresh89 = 0
        }
    }
    var c2da_fresh91 : int = 1
    if (!(c2da_fresh89 != 0)) {
        let c2da_fresh90 : int = mousebuttons + int(uint(c2da_mem[42720]) | uint(c2da_mem[42721]) << 0x8 | uint(c2da_mem[42722]) << 0x10 | uint(c2da_mem[42723]) << 0x18) * 4
        if (!((uint(c2da_mem[c2da_fresh90]) | uint(c2da_mem[c2da_fresh90 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh90 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh90 + 3]) << 0x18) != 0x0)) {
            c2da_fresh91 = 0
        }
    }
    if (c2da_fresh91 != 0 || joystrafemove > 0) {
        side += sidemove[speed]
    }
    let c2da_fresh92 : uint8 = uint8(HU_dequeueChatChar())
    c2da_mem[cmd + 4] = c2da_fresh92
    let c2da_fresh93 : int = 337344 + int(uint(c2da_mem[42480]) | uint(c2da_mem[42481]) << 0x8 | uint(c2da_mem[42482]) << 0x10 | uint(c2da_mem[42483]) << 0x18) * 4
    var c2da_fresh95 : int = 1
    if (!((uint(c2da_mem[c2da_fresh93]) | uint(c2da_mem[c2da_fresh93 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh93 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh93 + 3]) << 0x18) != 0x0)) {
        let c2da_fresh94 : int = mousebuttons + int(uint(c2da_mem[42544]) | uint(c2da_mem[42545]) << 0x8 | uint(c2da_mem[42546]) << 0x10 | uint(c2da_mem[42547]) << 0x18) * 4
        if (!((uint(c2da_mem[c2da_fresh94]) | uint(c2da_mem[c2da_fresh94 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh94 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh94 + 3]) << 0x18) != 0x0)) {
            c2da_fresh95 = 0
        }
    }
    var c2da_fresh97 : int = 1
    if (!(c2da_fresh95 != 0)) {
        let c2da_fresh96 : int = joybuttons + int(uint(c2da_mem[42592]) | uint(c2da_mem[42593]) << 0x8 | uint(c2da_mem[42594]) << 0x10 | uint(c2da_mem[42595]) << 0x18) * 4
        if (!((uint(c2da_mem[c2da_fresh96]) | uint(c2da_mem[c2da_fresh96 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh96 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh96 + 3]) << 0x18) != 0x0)) {
            c2da_fresh97 = 0
        }
    }
    if (c2da_fresh97 != 0) {
        let c2da_fresh98 : uint8 = uint8(int(c2da_mem[cmd + 5]) | 1)
        c2da_mem[cmd + 5] = c2da_fresh98
    }
    let c2da_fresh99 : int = 337344 + int(uint(c2da_mem[42496]) | uint(c2da_mem[42497]) << 0x8 | uint(c2da_mem[42498]) << 0x10 | uint(c2da_mem[42499]) << 0x18) * 4
    var c2da_fresh101 : int = 1
    if (!((uint(c2da_mem[c2da_fresh99]) | uint(c2da_mem[c2da_fresh99 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh99 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh99 + 3]) << 0x18) != 0x0)) {
        let c2da_fresh100 : int = joybuttons + int(uint(c2da_mem[42624]) | uint(c2da_mem[42625]) << 0x8 | uint(c2da_mem[42626]) << 0x10 | uint(c2da_mem[42627]) << 0x18) * 4
        if (!((uint(c2da_mem[c2da_fresh100]) | uint(c2da_mem[c2da_fresh100 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh100 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh100 + 3]) << 0x18) != 0x0)) {
            c2da_fresh101 = 0
        }
    }
    var c2da_fresh103 : int = 1
    if (!(c2da_fresh101 != 0)) {
        let c2da_fresh102 : int = mousebuttons + int(uint(c2da_mem[42736]) | uint(c2da_mem[42737]) << 0x8 | uint(c2da_mem[42738]) << 0x10 | uint(c2da_mem[42739]) << 0x18) * 4
        if (!((uint(c2da_mem[c2da_fresh102]) | uint(c2da_mem[c2da_fresh102 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh102 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh102 + 3]) << 0x18) != 0x0)) {
            c2da_fresh103 = 0
        }
    }
    if (c2da_fresh103 != 0) {
        let c2da_fresh104 : uint8 = uint8(int(c2da_mem[cmd + 5]) | 2)
        c2da_mem[cmd + 5] = c2da_fresh104
        dclicks = 0
    }
    if (gamestate == 0u && next_weapon != 0) {
        i_5 = G_NextWeapon(next_weapon)
        let c2da_fresh105 : uint8 = uint8(int(c2da_mem[cmd + 5]) | 4)
        c2da_mem[cmd + 5] = c2da_fresh105
        let c2da_fresh106 : uint8 = uint8(int(c2da_mem[cmd + 5]) | i_5 << 3)
        c2da_mem[cmd + 5] = c2da_fresh106
    } else {
        i_5 = 0
        while (uint64(i_5) < 64ul / 8ul) {
            let c2da_fresh107 : int = int(uint(c2da_mem[338544 + i_5 * 8]) | uint(c2da_mem[338544 + i_5 * 8 + 1]) << 0x8 | uint(c2da_mem[338544 + i_5 * 8 + 2]) << 0x10 | uint(c2da_mem[338544 + i_5 * 8 + 3]) << 0x18)
            key = int(uint(c2da_mem[c2da_fresh107]) | uint(c2da_mem[c2da_fresh107 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh107 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh107 + 3]) << 0x18)
            if ((uint(c2da_mem[337344 + key * 4]) | uint(c2da_mem[337344 + key * 4 + 1]) << 0x8 | uint(c2da_mem[337344 + key * 4 + 2]) << 0x10 | uint(c2da_mem[337344 + key * 4 + 3]) << 0x18) != 0x0) {
                let c2da_fresh108 : uint8 = uint8(int(c2da_mem[cmd + 5]) | 4)
                c2da_mem[cmd + 5] = c2da_fresh108
                let c2da_fresh109 : uint8 = uint8(int(c2da_mem[cmd + 5]) | i_5 << 3)
                c2da_mem[cmd + 5] = c2da_fresh109
                break
            }
            i_5++
        }
    }
    next_weapon = 0
    let c2da_fresh110 : int = mousebuttons + int(uint(c2da_mem[42576]) | uint(c2da_mem[42577]) << 0x8 | uint(c2da_mem[42578]) << 0x10 | uint(c2da_mem[42579]) << 0x18) * 4
    if ((uint(c2da_mem[c2da_fresh110]) | uint(c2da_mem[c2da_fresh110 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh110 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh110 + 3]) << 0x18) != 0x0) {
        forward += forwardmove[speed]
    }
    let c2da_fresh111 : int = mousebuttons + int(uint(c2da_mem[42752]) | uint(c2da_mem[42753]) << 0x8 | uint(c2da_mem[42754]) << 0x10 | uint(c2da_mem[42755]) << 0x18) * 4
    if ((uint(c2da_mem[c2da_fresh111]) | uint(c2da_mem[c2da_fresh111 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh111 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh111 + 3]) << 0x18) != 0x0) {
        forward -= forwardmove[speed]
    }
    if (int(uint(c2da_mem[42768]) | uint(c2da_mem[42769]) << 0x8 | uint(c2da_mem[42770]) << 0x10 | uint(c2da_mem[42771]) << 0x18) != 0) {
        let c2da_fresh112 : int = mousebuttons + int(uint(c2da_mem[42576]) | uint(c2da_mem[42577]) << 0x8 | uint(c2da_mem[42578]) << 0x10 | uint(c2da_mem[42579]) << 0x18) * 4
        if ((uint(c2da_mem[c2da_fresh112]) | uint(c2da_mem[c2da_fresh112 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh112 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh112 + 3]) << 0x18) != dclickstate && dclicktime > 1) {
            let c2da_fresh113 : int = mousebuttons + int(uint(c2da_mem[42576]) | uint(c2da_mem[42577]) << 0x8 | uint(c2da_mem[42578]) << 0x10 | uint(c2da_mem[42579]) << 0x18) * 4
            dclickstate = uint(c2da_mem[c2da_fresh113]) | uint(c2da_mem[c2da_fresh113 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh113 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh113 + 3]) << 0x18
            if (dclickstate != 0x0) {
                dclicks++
            }
            if (dclicks == 2) {
                let c2da_fresh114 : uint8 = uint8(int(c2da_mem[cmd + 5]) | 2)
                c2da_mem[cmd + 5] = c2da_fresh114
                dclicks = 0
            } else {
                dclicktime = 0
            }
        } else {
            dclicktime = dclicktime + ticdup
            if (dclicktime > 20) {
                dclicks = 0
                dclickstate = 0u
            }
        }
        let c2da_fresh115 : int = mousebuttons + int(uint(c2da_mem[42560]) | uint(c2da_mem[42561]) << 0x8 | uint(c2da_mem[42562]) << 0x10 | uint(c2da_mem[42563]) << 0x18) * 4
        var c2da_fresh117 : int = 1
        if (!((uint(c2da_mem[c2da_fresh115]) | uint(c2da_mem[c2da_fresh115 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh115 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh115 + 3]) << 0x18) != 0x0)) {
            let c2da_fresh116 : int = joybuttons + int(uint(c2da_mem[42608]) | uint(c2da_mem[42609]) << 0x8 | uint(c2da_mem[42610]) << 0x10 | uint(c2da_mem[42611]) << 0x18) * 4
            if (!((uint(c2da_mem[c2da_fresh116]) | uint(c2da_mem[c2da_fresh116 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh116 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh116 + 3]) << 0x18) != 0x0)) {
                c2da_fresh117 = 0
            }
        }
        bstrafe = uint(c2da_fresh117)
        if (bstrafe != dclickstate2 && dclicktime2 > 1) {
            dclickstate2 = bstrafe
            if (dclickstate2 != 0x0) {
                dclicks2++
            }
            if (dclicks2 == 2) {
                let c2da_fresh118 : uint8 = uint8(int(c2da_mem[cmd + 5]) | 2)
                c2da_mem[cmd + 5] = c2da_fresh118
                dclicks2 = 0
            } else {
                dclicktime2 = 0
            }
        } else {
            dclicktime2 = dclicktime2 + ticdup
            if (dclicktime2 > 20) {
                dclicks2 = 0
                dclickstate2 = 0u
            }
        }
    }
    forward += mousey
    if (strafe != 0x0) {
        side += mousex * 2
    } else {
        let c2da_fresh119 : int16 = int16(int(int16(uint(c2da_mem[cmd + 2]) | uint(c2da_mem[cmd + 3]) << 0x8)) - mousex * 8)
        let c2da_fresh120 : uint = uint(c2da_fresh119)
        c2da_mem[cmd + 2] = uint8(c2da_fresh120)
        c2da_mem[cmd + 3] = uint8(c2da_fresh120 >> 0x8)
    }
    if (mousex == 0) {
        testcontrols_mousespeed = 0
    }
    mousey = 0
    mousex = int(mousey)  // nolint:PERF020
    if (forward > forwardmove[1]) {
        forward = forwardmove[1]
    } elif (forward < -forwardmove[1]) {
        forward = -forwardmove[1]
    }
    if (side > forwardmove[1]) {
        side = forwardmove[1]
    } elif (side < -forwardmove[1]) {
        side = -forwardmove[1]
    }
    let c2da_fresh121 : int8 = int8(int(int8(c2da_mem[cmd])) + forward)
    c2da_mem[cmd] = uint8(c2da_fresh121)
    let c2da_fresh122 : int8 = int8(int(int8(c2da_mem[cmd + 1])) + side)
    c2da_mem[cmd + 1] = uint8(c2da_fresh122)
    if (sendpause != 0x0) {
        sendpause = 0u
        let c2da_fresh123 : uint8 = uint8(128 | 1)
        c2da_mem[cmd + 5] = c2da_fresh123
    }
    if (sendsave != 0x0) {
        sendsave = 0u
        let c2da_fresh124 : uint8 = uint8(128 | 2 | savegameslot << 2)
        c2da_mem[cmd + 5] = c2da_fresh124
    }
    if (lowres_turn != 0x0) {
        desired_angleturn = int16(int(int16(uint(c2da_mem[cmd + 2]) | uint(c2da_mem[cmd + 3]) << 0x8)) + int(G_BuildTiccmd__carry))
        let c2da_fresh125 : int16 = int16(int(desired_angleturn) + 128 & 65280)
        let c2da_fresh126 : uint = uint(c2da_fresh125)
        c2da_mem[cmd + 2] = uint8(c2da_fresh126)
        c2da_mem[cmd + 3] = uint8(c2da_fresh126 >> 0x8)
        G_BuildTiccmd__carry = int16(int(desired_angleturn) - int(int16(uint(c2da_mem[cmd + 2]) | uint(c2da_mem[cmd + 3]) << 0x8)))
    }
    return
}
var forwardmove : int[2] = fixed_array<int>(25, 50)

var private dclickstate2 : uint = default<uint>

var private dclicks2 : int = default<int>

var private dclicktime2 : int = default<int>

var private joybuttons : int = 338416 + 1 * 4

var private mousebuttons : int = 338368 + 1 * 4

var private dclickstate : uint = default<uint>

var private dclicks : int = default<int>

var private dclicktime : int = default<int>

var private next_weapon : int = 0

[sideeffects]
def private G_NextWeapon(var direction : int) : int {
    var weapon : uint
    var start_i : int
    var i_6 : int
    if ((uint(c2da_mem[96 + consoleplayer * 328 + 128]) | uint(c2da_mem[96 + consoleplayer * 328 + 129]) << 0x8 | uint(c2da_mem[96 + consoleplayer * 328 + 130]) << 0x10 | uint(c2da_mem[96 + consoleplayer * 328 + 131]) << 0x18) == 10u) {
        weapon = uint(c2da_mem[96 + consoleplayer * 328 + 124]) | uint(c2da_mem[96 + consoleplayer * 328 + 125]) << 0x8 | uint(c2da_mem[96 + consoleplayer * 328 + 126]) << 0x10 | uint(c2da_mem[96 + consoleplayer * 328 + 127]) << 0x18
    } else {
        weapon = uint(c2da_mem[96 + consoleplayer * 328 + 128]) | uint(c2da_mem[96 + consoleplayer * 328 + 129]) << 0x8 | uint(c2da_mem[96 + consoleplayer * 328 + 130]) << 0x10 | uint(c2da_mem[96 + consoleplayer * 328 + 131]) << 0x18
    }
    i_6 = 0
    while (uint64(i_6) < 72ul / 8ul) {
        if ((uint(c2da_mem[338608 + i_6 * 8]) | uint(c2da_mem[338608 + i_6 * 8 + 1]) << 0x8 | uint(c2da_mem[338608 + i_6 * 8 + 2]) << 0x10 | uint(c2da_mem[338608 + i_6 * 8 + 3]) << 0x18) == weapon) {
            break
        }
        i_6++
    }
    start_i = i_6
    while (true) {
        i_6 += direction
        i_6 = int((uint64(i_6) + 72ul / 8ul) % (72ul / 8ul))
        if (!(i_6 != start_i && WeaponSelectable(uint(c2da_mem[338608 + i_6 * 8]) | uint(c2da_mem[338608 + i_6 * 8 + 1]) << 0x8 | uint(c2da_mem[338608 + i_6 * 8 + 2]) << 0x10 | uint(c2da_mem[338608 + i_6 * 8 + 3]) << 0x18) == 0)) {
            break
        }
    }
    return int(uint(c2da_mem[338608 + i_6 * 8 + 4]) | uint(c2da_mem[338608 + i_6 * 8 + 5]) << 0x8 | uint(c2da_mem[338608 + i_6 * 8 + 6]) << 0x10 | uint(c2da_mem[338608 + i_6 * 8 + 7]) << 0x18)
}
[sideeffects]
def private WeaponSelectable(var weapon_0 : uint) : uint {
    if (weapon_0 == 8u && ((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 4u ? 0u : (uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 5u ? 1u : uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 0u) {
        return 0u
    }
    if ((weapon_0 == 5u || weapon_0 == 6u) && (uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 0u && uint(gamemode) == 0u) {
        return 0u
    }
    if ((uint(c2da_mem[96 + consoleplayer * 328 + 132 + int(weapon_0) * 4]) | uint(c2da_mem[96 + consoleplayer * 328 + 132 + int(weapon_0) * 4 + 1]) << 0x8 | uint(c2da_mem[96 + consoleplayer * 328 + 132 + int(weapon_0) * 4 + 2]) << 0x10 | uint(c2da_mem[96 + consoleplayer * 328 + 132 + int(weapon_0) * 4 + 3]) << 0x18) == 0) {
        return 0u
    }
    if (weapon_0 == 0u && (uint(c2da_mem[96 + consoleplayer * 328 + 132 + 7 * 4]) | uint(c2da_mem[96 + consoleplayer * 328 + 132 + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[96 + consoleplayer * 328 + 132 + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[96 + consoleplayer * 328 + 132 + 7 * 4 + 3]) << 0x18) != 0x0 && int(uint(c2da_mem[96 + consoleplayer * 328 + 56 + 1 * 4]) | uint(c2da_mem[96 + consoleplayer * 328 + 56 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[96 + consoleplayer * 328 + 56 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[96 + consoleplayer * 328 + 56 + 1 * 4 + 3]) << 0x18) == 0) {
        return 0u
    }
    return 1u
}
var sidemove : int[2] = fixed_array<int>(24, 40)

var angleturn : int[3] = fixed_array<int>(640, 1280, 320)

var private turnheld : int = default<int>

var consistancy : uint8[4][128]

[export, sideeffects]
def G_Ticker() {
    var c2da_fresh127 : uint
    var c2da_fresh131 : int
    var c2da_fresh132 : uint
    var i_7 : int
    var buf : int
    var cmd_0 : int
    i_7 = 0
    while (i_7 < 4) {
        if (playeringame[i_7] != 0x0 && (uint(c2da_mem[96 + i_7 * 328 + 8]) | uint(c2da_mem[96 + i_7 * 328 + 9]) << 0x8 | uint(c2da_mem[96 + i_7 * 328 + 10]) << 0x10 | uint(c2da_mem[96 + i_7 * 328 + 11]) << 0x18) == 2u) {
            G_DoReborn(i_7)
        }
        i_7++
    }
    while (gameaction != 0u) {
        c2da_fresh127 = gameaction
        if (c2da_fresh127 <= 0x9u) {
            goto int(c2da_fresh127)
        }
        continue
        label 0:
        continue
        label 1:
        G_DoLoadLevel()
        continue
        label 2:
        G_DoNewGame()
        continue
        label 3:
        G_DoLoadGame()
        continue
        label 4:
        G_DoSaveGame()
        continue
        label 5:
        G_DoPlayDemo()
        continue
        label 6:
        G_DoCompleted()
        continue
        label 7:
        F_StartFinale()
        continue
        label 8:
        G_DoWorldDone()
        continue
        label 9:
        V_ScreenShot(339058)
        let c2da_fresh128 : uint = 339070u
        c2da_mem[96 + consoleplayer * 328 + 232] = uint8(c2da_fresh128)
        c2da_mem[96 + consoleplayer * 328 + 233] = uint8(c2da_fresh128 >> 0x8)
        c2da_mem[96 + consoleplayer * 328 + 234] = uint8(c2da_fresh128 >> 0x10)
        c2da_mem[96 + consoleplayer * 328 + 235] = uint8(c2da_fresh128 >> 0x18)
        c2da_mem[96 + consoleplayer * 328 + 236] = 0u8
        c2da_mem[96 + consoleplayer * 328 + 237] = 0u8
        c2da_mem[96 + consoleplayer * 328 + 238] = 0u8
        c2da_mem[96 + consoleplayer * 328 + 239] = 0u8
        gameaction = 0u
        continue
    }
    buf = gametic / ticdup % 128
    i_7 = 0
    while (i_7 < 4) {
        if (playeringame[i_7] != 0x0) {
            cmd_0 = 96 + i_7 * 328 + 12
            c2da_lin_memcpy(cmd_0, int(netcmds + i_7 * 16), 16ul)
            if (demoplayback != 0x0) {
                G_ReadDemoTiccmd(cmd_0)
            }
            if (demorecording != 0x0) {
                G_WriteDemoTiccmd(cmd_0)
            }
            if (int(int8(c2da_mem[cmd_0])) > 50) {
                turbodetected[i_7] = 1u
            }
            if ((gametic & 31) == 0 && (gametic >> 5) % 4 == i_7 && turbodetected[i_7] != 0x0) {
                M_snprintf(338688, 80ul, 339082, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(player_names[i_7]))])
                let c2da_fresh129 : uint = 338688u
                c2da_mem[96 + consoleplayer * 328 + 232] = uint8(c2da_fresh129)
                c2da_mem[96 + consoleplayer * 328 + 233] = uint8(c2da_fresh129 >> 0x8)
                c2da_mem[96 + consoleplayer * 328 + 234] = uint8(c2da_fresh129 >> 0x10)
                c2da_mem[96 + consoleplayer * 328 + 235] = uint8(c2da_fresh129 >> 0x18)
                c2da_mem[96 + consoleplayer * 328 + 236] = 0u8
                c2da_mem[96 + consoleplayer * 328 + 237] = 0u8
                c2da_mem[96 + consoleplayer * 328 + 238] = 0u8
                c2da_mem[96 + consoleplayer * 328 + 239] = 0u8
                turbodetected[i_7] = 0u
            }
            if (netgame != 0x0 && netdemo == 0 && gametic % ticdup == 0) {
                if (gametic > 128 && int(consistancy[i_7][buf]) != int(c2da_mem[cmd_0 + 6])) {
                    I_Error(339095, [C2daVaArg(tag = 1, i64 = int64(int(c2da_mem[cmd_0 + 6])), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(consistancy[i_7][buf]), f64 = 0.0lf, raw = 0x0)])
                }
                if (int(uint(c2da_mem[96 + i_7 * 328]) | uint(c2da_mem[96 + i_7 * 328 + 1]) << 0x8 | uint(c2da_mem[96 + i_7 * 328 + 2]) << 0x10 | uint(c2da_mem[96 + i_7 * 328 + 3]) << 0x18) != 0) {
                    let c2da_fresh130 : int = int(uint(c2da_mem[96 + i_7 * 328]) | uint(c2da_mem[96 + i_7 * 328 + 1]) << 0x8 | uint(c2da_mem[96 + i_7 * 328 + 2]) << 0x10 | uint(c2da_mem[96 + i_7 * 328 + 3]) << 0x18) + 24
                    consistancy[i_7][buf] = uint8(int(uint(c2da_mem[c2da_fresh130]) | uint(c2da_mem[c2da_fresh130 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh130 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh130 + 3]) << 0x18))
                } else {
                    consistancy[i_7][buf] = uint8(rndindex)
                }
            }
        }
        i_7++
    }
    i_7 = 0
    while (i_7 < 4) {
        if (playeringame[i_7] != 0x0) {
            if ((int(c2da_mem[96 + i_7 * 328 + 17]) & 128) != 0) {
                c2da_fresh131 = int(c2da_mem[96 + i_7 * 328 + 17]) & 3
                if (c2da_fresh131 == 1) {
                    paused ^= 1u
                    if (paused != 0x0) {
                        S_PauseSound()
                    } else {
                        S_ResumeSound()
                    }
                } elif (c2da_fresh131 == 2) {
                    if (int8(c2da_mem[338512 + 0]) == 0) {
                        M_StringCopy(338512, 339133, 32ul)
                    }
                    savegameslot = (int(c2da_mem[96 + i_7 * 328 + 17]) & 28) >> 2
                    gameaction = 4u
                }
            }
        }
        i_7++
    }
    if (oldgamestate == 1u && gamestate != 1u) {
        WI_End()
    }
    oldgamestate = uint(gamestate)  // nolint:PERF020
    c2da_fresh132 = gamestate
    if (c2da_fresh132 == 0x0u) {
        P_Ticker()
        ST_Ticker()
        AM_Ticker()
        HU_Ticker()
    } elif (c2da_fresh132 == 0x1u) {
        WI_Ticker()
    } elif (c2da_fresh132 == 0x2u) {
        F_Ticker()
    } elif (c2da_fresh132 == 0x3u) {
        D_PageTicker()
    }
    return
}
var oldgamestate : uint = default<uint>

[export, sideeffects]
def G_WriteDemoTiccmd(var cmd_1 : int) {
    var demo_start : int
    let c2da_fresh133 : int = 337344 + int(uint(c2da_mem[43936]) | uint(c2da_mem[43937]) << 0x8 | uint(c2da_mem[43938]) << 0x10 | uint(c2da_mem[43939]) << 0x18) * 4
    if ((uint(c2da_mem[c2da_fresh133]) | uint(c2da_mem[c2da_fresh133 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh133 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh133 + 3]) << 0x18) != 0x0) {
        G_CheckDemoStatus()
    }
    demo_start = demo_p
    let c2da_fresh134 : int = demo_p
    demo_p++
    let c2da_fresh135 : uint8 = uint8(int8(c2da_mem[cmd_1]))
    c2da_mem[c2da_fresh134] = c2da_fresh135
    let c2da_fresh136 : int = demo_p
    demo_p++
    let c2da_fresh137 : uint8 = uint8(int8(c2da_mem[cmd_1 + 1]))
    c2da_mem[c2da_fresh136] = c2da_fresh137
    if (longtics != 0x0) {
        let c2da_fresh138 : int = demo_p
        demo_p++
        let c2da_fresh139 : uint8 = uint8(int(int16(uint(c2da_mem[cmd_1 + 2]) | uint(c2da_mem[cmd_1 + 3]) << 0x8)) & 255)
        c2da_mem[c2da_fresh138] = c2da_fresh139
        let c2da_fresh140 : int = demo_p
        demo_p++
        let c2da_fresh141 : uint8 = uint8(int(int16(uint(c2da_mem[cmd_1 + 2]) | uint(c2da_mem[cmd_1 + 3]) << 0x8)) >> 8 & 255)
        c2da_mem[c2da_fresh140] = c2da_fresh141
    } else {
        let c2da_fresh142 : int = demo_p
        demo_p++
        let c2da_fresh143 : uint8 = uint8(int(int16(uint(c2da_mem[cmd_1 + 2]) | uint(c2da_mem[cmd_1 + 3]) << 0x8)) >> 8)
        c2da_mem[c2da_fresh142] = c2da_fresh143
    }
    let c2da_fresh144 : int = demo_p
    demo_p++
    let c2da_fresh145 : uint8 = c2da_mem[cmd_1 + 5]
    c2da_mem[c2da_fresh144] = c2da_fresh145
    demo_p = demo_start
    if (demo_p > demoend - 16) {
        if (int(uint(c2da_mem[1952]) | uint(c2da_mem[1953]) << 0x8 | uint(c2da_mem[1954]) << 0x10 | uint(c2da_mem[1955]) << 0x18) != 0) {
            G_CheckDemoStatus()
            return
        } else {
            IncreaseDemoBuffer()
        }
    }
    G_ReadDemoTiccmd(cmd_1)
    return
}
[export, sideeffects]
def G_ReadDemoTiccmd(var cmd_2 : int) {
    if (int(c2da_mem[demo_p]) == 128) {
        G_CheckDemoStatus()
        return
    }
    let c2da_fresh146 : int = demo_p
    demo_p++
    let c2da_fresh147 : int8 = int8(c2da_mem[c2da_fresh146])
    c2da_mem[cmd_2] = uint8(c2da_fresh147)
    let c2da_fresh148 : int = demo_p
    demo_p++
    let c2da_fresh149 : int8 = int8(c2da_mem[c2da_fresh148])
    c2da_mem[cmd_2 + 1] = uint8(c2da_fresh149)
    if (longtics != 0x0) {
        let c2da_fresh150 : int = demo_p
        demo_p++
        let c2da_fresh151 : int16 = int16(c2da_mem[c2da_fresh150])
        let c2da_fresh152 : uint = uint(c2da_fresh151)
        c2da_mem[cmd_2 + 2] = uint8(c2da_fresh152)
        c2da_mem[cmd_2 + 3] = uint8(c2da_fresh152 >> 0x8)
        let c2da_fresh153 : int = demo_p
        demo_p++
        let c2da_fresh154 : int16 = int16(int(int16(uint(c2da_mem[cmd_2 + 2]) | uint(c2da_mem[cmd_2 + 3]) << 0x8)) | int(c2da_mem[c2da_fresh153]) << 8)
        let c2da_fresh155 : uint = uint(c2da_fresh154)
        c2da_mem[cmd_2 + 2] = uint8(c2da_fresh155)
        c2da_mem[cmd_2 + 3] = uint8(c2da_fresh155 >> 0x8)
    } else {
        let c2da_fresh156 : int = demo_p
        demo_p++
        let c2da_fresh157 : int16 = int16(int(c2da_mem[c2da_fresh156]) << 8)
        let c2da_fresh158 : uint = uint(c2da_fresh157)
        c2da_mem[cmd_2 + 2] = uint8(c2da_fresh158)
        c2da_mem[cmd_2 + 3] = uint8(c2da_fresh158 >> 0x8)
    }
    let c2da_fresh159 : int = demo_p
    demo_p++
    let c2da_fresh160 : uint8 = c2da_mem[c2da_fresh159]
    c2da_mem[cmd_2 + 5] = c2da_fresh160
    return
}
[sideeffects]
def private IncreaseDemoBuffer() {
    var current_length : int
    var new_demobuffer : int
    var new_demop : int
    var new_length : int
    current_length = demoend - demobuffer
    new_length = current_length * 2
    new_demobuffer = Z_Malloc(new_length, 1, 0)
    new_demop = new_demobuffer + (demo_p - demobuffer)
    c2da_lin_memcpy(new_demobuffer, demobuffer, uint64(current_length))
    Z_Free(demobuffer)
    demobuffer = new_demobuffer
    demo_p = new_demop
    demoend = demobuffer + new_length
    return
}
[export, sideeffects]
def G_DoWorldDone() {
    gamestate = 0u
    gamemap = int(uint(c2da_mem[41324]) | uint(c2da_mem[41325]) << 0x8 | uint(c2da_mem[41326]) << 0x10 | uint(c2da_mem[41327]) << 0x18) + 1
    G_DoLoadLevel()
    gameaction = 0u
    viewactive = 1u
    return
}
[export, sideeffects]
def G_DoCompleted() {
    var i_8 : int
    gameaction = 0u
    i_8 = 0
    while (i_8 < 4) {
        if (playeringame[i_8] != 0x0) {
            G_PlayerFinishLevel(i_8)
        }
        i_8++
    }
    if (automapactive != 0x0) {
        AM_Stop()
    }
    if (uint(gamemode) != 2u) {
        if (uint(gameversion) == 9u) {
            if (gamemap == 5) {
                gameaction = 7u
                return
            }
        } elif (gamemap == 8) {
            gameaction = 7u
            return
        } elif (gamemap == 9) {
            i_8 = 0
            while (i_8 < 4) {
                let c2da_fresh161 : uint = 1u
                let c2da_fresh162 : uint = c2da_fresh161
                c2da_mem[96 + i_8 * 328 + 320] = uint8(c2da_fresh162)
                c2da_mem[96 + i_8 * 328 + 321] = uint8(c2da_fresh162 >> 0x8)
                c2da_mem[96 + i_8 * 328 + 322] = uint8(c2da_fresh162 >> 0x10)
                c2da_mem[96 + i_8 * 328 + 323] = uint8(c2da_fresh162 >> 0x18)
                i_8++
            }
        }
    }
    if (gamemap == 8 && uint(gamemode) != 2u) {
        gameaction = 7u
        return
    }
    if (gamemap == 9 && uint(gamemode) != 2u) {
        i_8 = 0
        while (i_8 < 4) {
            let c2da_fresh163 : uint = 1u
            let c2da_fresh164 : uint = c2da_fresh163
            c2da_mem[96 + i_8 * 328 + 320] = uint8(c2da_fresh164)
            c2da_mem[96 + i_8 * 328 + 321] = uint8(c2da_fresh164 >> 0x8)
            c2da_mem[96 + i_8 * 328 + 322] = uint8(c2da_fresh164 >> 0x10)
            c2da_mem[96 + i_8 * 328 + 323] = uint8(c2da_fresh164 >> 0x18)
            i_8++
        }
    }
    let c2da_fresh165 : uint = uint(c2da_mem[96 + consoleplayer * 328 + 320]) | uint(c2da_mem[96 + consoleplayer * 328 + 321]) << 0x8 | uint(c2da_mem[96 + consoleplayer * 328 + 322]) << 0x10 | uint(c2da_mem[96 + consoleplayer * 328 + 323]) << 0x18
    let c2da_fresh166 : uint = c2da_fresh165
    c2da_mem[41316] = uint8(c2da_fresh166)
    c2da_mem[41317] = uint8(c2da_fresh166 >> 0x8)
    c2da_mem[41318] = uint8(c2da_fresh166 >> 0x10)
    c2da_mem[41319] = uint8(c2da_fresh166 >> 0x18)
    let c2da_fresh167 : int = gameepisode - 1
    let c2da_fresh168 : uint = uint(c2da_fresh167)
    c2da_mem[41312] = uint8(c2da_fresh168)
    c2da_mem[41313] = uint8(c2da_fresh168 >> 0x8)
    c2da_mem[41314] = uint8(c2da_fresh168 >> 0x10)
    c2da_mem[41315] = uint8(c2da_fresh168 >> 0x18)
    let c2da_fresh169 : int = gamemap - 1
    let c2da_fresh170 : uint = uint(c2da_fresh169)
    c2da_mem[41320] = uint8(c2da_fresh170)
    c2da_mem[41321] = uint8(c2da_fresh170 >> 0x8)
    c2da_mem[41322] = uint8(c2da_fresh170 >> 0x10)
    c2da_mem[41323] = uint8(c2da_fresh170 >> 0x18)
    if (uint(gamemode) == 2u) {
        if (secretexit != 0x0) {
            if (gamemap == 15) {
                let c2da_fresh171 : int = 30
                let c2da_fresh172 : uint = uint(c2da_fresh171)
                c2da_mem[41324] = uint8(c2da_fresh172)
                c2da_mem[41325] = uint8(c2da_fresh172 >> 0x8)
                c2da_mem[41326] = uint8(c2da_fresh172 >> 0x10)
                c2da_mem[41327] = uint8(c2da_fresh172 >> 0x18)
            } elif (gamemap == 31) {
                let c2da_fresh173 : int = 31
                let c2da_fresh174 : uint = uint(c2da_fresh173)
                c2da_mem[41324] = uint8(c2da_fresh174)
                c2da_mem[41325] = uint8(c2da_fresh174 >> 0x8)
                c2da_mem[41326] = uint8(c2da_fresh174 >> 0x10)
                c2da_mem[41327] = uint8(c2da_fresh174 >> 0x18)
            }
        } elif (gamemap == 31 || gamemap == 32) {
            let c2da_fresh175 : int = 15
            let c2da_fresh176 : uint = uint(c2da_fresh175)
            c2da_mem[41324] = uint8(c2da_fresh176)
            c2da_mem[41325] = uint8(c2da_fresh176 >> 0x8)
            c2da_mem[41326] = uint8(c2da_fresh176 >> 0x10)
            c2da_mem[41327] = uint8(c2da_fresh176 >> 0x18)
        } else {
            let c2da_fresh177 : uint = uint(gamemap)
            c2da_mem[41324] = uint8(c2da_fresh177)
            c2da_mem[41325] = uint8(c2da_fresh177 >> 0x8)
            c2da_mem[41326] = uint8(c2da_fresh177 >> 0x10)
            c2da_mem[41327] = uint8(c2da_fresh177 >> 0x18)
        }
    } elif (secretexit != 0x0) {
        let c2da_fresh178 : int = 8
        let c2da_fresh179 : uint = uint(c2da_fresh178)
        c2da_mem[41324] = uint8(c2da_fresh179)
        c2da_mem[41325] = uint8(c2da_fresh179 >> 0x8)
        c2da_mem[41326] = uint8(c2da_fresh179 >> 0x10)
        c2da_mem[41327] = uint8(c2da_fresh179 >> 0x18)
    } elif (gamemap == 9) {
        if (gameepisode == 1) {
            let c2da_fresh180 : int = 3
            let c2da_fresh181 : uint = uint(c2da_fresh180)
            c2da_mem[41324] = uint8(c2da_fresh181)
            c2da_mem[41325] = uint8(c2da_fresh181 >> 0x8)
            c2da_mem[41326] = uint8(c2da_fresh181 >> 0x10)
            c2da_mem[41327] = uint8(c2da_fresh181 >> 0x18)
        } elif (gameepisode == 2) {
            let c2da_fresh182 : int = 5
            let c2da_fresh183 : uint = uint(c2da_fresh182)
            c2da_mem[41324] = uint8(c2da_fresh183)
            c2da_mem[41325] = uint8(c2da_fresh183 >> 0x8)
            c2da_mem[41326] = uint8(c2da_fresh183 >> 0x10)
            c2da_mem[41327] = uint8(c2da_fresh183 >> 0x18)
        } elif (gameepisode == 3) {
            let c2da_fresh184 : int = 6
            let c2da_fresh185 : uint = uint(c2da_fresh184)
            c2da_mem[41324] = uint8(c2da_fresh185)
            c2da_mem[41325] = uint8(c2da_fresh185 >> 0x8)
            c2da_mem[41326] = uint8(c2da_fresh185 >> 0x10)
            c2da_mem[41327] = uint8(c2da_fresh185 >> 0x18)
        } elif (gameepisode == 4) {
            let c2da_fresh186 : int = 2
            let c2da_fresh187 : uint = uint(c2da_fresh186)
            c2da_mem[41324] = uint8(c2da_fresh187)
            c2da_mem[41325] = uint8(c2da_fresh187 >> 0x8)
            c2da_mem[41326] = uint8(c2da_fresh187 >> 0x10)
            c2da_mem[41327] = uint8(c2da_fresh187 >> 0x18)
        }
    } else {
        let c2da_fresh188 : uint = uint(gamemap)
        c2da_mem[41324] = uint8(c2da_fresh188)
        c2da_mem[41325] = uint8(c2da_fresh188 >> 0x8)
        c2da_mem[41326] = uint8(c2da_fresh188 >> 0x10)
        c2da_mem[41327] = uint8(c2da_fresh188 >> 0x18)
    }
    let c2da_fresh189 : uint = uint(totalkills)
    c2da_mem[41328] = uint8(c2da_fresh189)
    c2da_mem[41329] = uint8(c2da_fresh189 >> 0x8)
    c2da_mem[41330] = uint8(c2da_fresh189 >> 0x10)
    c2da_mem[41331] = uint8(c2da_fresh189 >> 0x18)
    let c2da_fresh190 : uint = uint(totalitems)
    c2da_mem[41332] = uint8(c2da_fresh190)
    c2da_mem[41333] = uint8(c2da_fresh190 >> 0x8)
    c2da_mem[41334] = uint8(c2da_fresh190 >> 0x10)
    c2da_mem[41335] = uint8(c2da_fresh190 >> 0x18)
    let c2da_fresh191 : uint = uint(totalsecret)
    c2da_mem[41336] = uint8(c2da_fresh191)
    c2da_mem[41337] = uint8(c2da_fresh191 >> 0x8)
    c2da_mem[41338] = uint8(c2da_fresh191 >> 0x10)
    c2da_mem[41339] = uint8(c2da_fresh191 >> 0x18)
    let c2da_fresh192 : int = 0
    let c2da_fresh193 : uint = uint(c2da_fresh192)
    c2da_mem[41340] = uint8(c2da_fresh193)
    c2da_mem[41341] = uint8(c2da_fresh193 >> 0x8)
    c2da_mem[41342] = uint8(c2da_fresh193 >> 0x10)
    c2da_mem[41343] = uint8(c2da_fresh193 >> 0x18)
    if (uint(gamemode) == 2u) {
        let c2da_fresh194 : int = 35 * cpars[gamemap - 1]
        let c2da_fresh195 : uint = uint(c2da_fresh194)
        c2da_mem[41344] = uint8(c2da_fresh195)
        c2da_mem[41345] = uint8(c2da_fresh195 >> 0x8)
        c2da_mem[41346] = uint8(c2da_fresh195 >> 0x10)
        c2da_mem[41347] = uint8(c2da_fresh195 >> 0x18)
    } elif (gameepisode < 4) {
        let c2da_fresh196 : int = 35 * pars[gameepisode][gamemap]
        let c2da_fresh197 : uint = uint(c2da_fresh196)
        c2da_mem[41344] = uint8(c2da_fresh197)
        c2da_mem[41345] = uint8(c2da_fresh197 >> 0x8)
        c2da_mem[41346] = uint8(c2da_fresh197 >> 0x10)
        c2da_mem[41347] = uint8(c2da_fresh197 >> 0x18)
    } else {
        let c2da_fresh198 : int = 35 * cpars[gamemap]
        let c2da_fresh199 : uint = uint(c2da_fresh198)
        c2da_mem[41344] = uint8(c2da_fresh199)
        c2da_mem[41345] = uint8(c2da_fresh199 >> 0x8)
        c2da_mem[41346] = uint8(c2da_fresh199 >> 0x10)
        c2da_mem[41347] = uint8(c2da_fresh199 >> 0x18)
    }
    let c2da_fresh200 : uint = uint(consoleplayer)
    c2da_mem[41348] = uint8(c2da_fresh200)
    c2da_mem[41349] = uint8(c2da_fresh200 >> 0x8)
    c2da_mem[41350] = uint8(c2da_fresh200 >> 0x10)
    c2da_mem[41351] = uint8(c2da_fresh200 >> 0x18)
    i_8 = 0
    for (c2da_i_8 in range(i_8, 4)) {
        let c2da_fresh201 : uint = playeringame[c2da_i_8]
        let c2da_fresh202 : uint = c2da_fresh201
        c2da_mem[41352 + c2da_i_8 * 40] = uint8(c2da_fresh202)
        c2da_mem[41352 + c2da_i_8 * 40 + 1] = uint8(c2da_fresh202 >> 0x8)
        c2da_mem[41352 + c2da_i_8 * 40 + 2] = uint8(c2da_fresh202 >> 0x10)
        c2da_mem[41352 + c2da_i_8 * 40 + 3] = uint8(c2da_fresh202 >> 0x18)
        let c2da_fresh203 : int = int(uint(c2da_mem[96 + c2da_i_8 * 328 + 216]) | uint(c2da_mem[96 + c2da_i_8 * 328 + 217]) << 0x8 | uint(c2da_mem[96 + c2da_i_8 * 328 + 218]) << 0x10 | uint(c2da_mem[96 + c2da_i_8 * 328 + 219]) << 0x18)
        let c2da_fresh204 : uint = uint(c2da_fresh203)
        c2da_mem[41352 + c2da_i_8 * 40 + 4] = uint8(c2da_fresh204)
        c2da_mem[41352 + c2da_i_8 * 40 + 5] = uint8(c2da_fresh204 >> 0x8)
        c2da_mem[41352 + c2da_i_8 * 40 + 6] = uint8(c2da_fresh204 >> 0x10)
        c2da_mem[41352 + c2da_i_8 * 40 + 7] = uint8(c2da_fresh204 >> 0x18)
        let c2da_fresh205 : int = int(uint(c2da_mem[96 + c2da_i_8 * 328 + 220]) | uint(c2da_mem[96 + c2da_i_8 * 328 + 221]) << 0x8 | uint(c2da_mem[96 + c2da_i_8 * 328 + 222]) << 0x10 | uint(c2da_mem[96 + c2da_i_8 * 328 + 223]) << 0x18)
        let c2da_fresh206 : uint = uint(c2da_fresh205)
        c2da_mem[41352 + c2da_i_8 * 40 + 8] = uint8(c2da_fresh206)
        c2da_mem[41352 + c2da_i_8 * 40 + 9] = uint8(c2da_fresh206 >> 0x8)
        c2da_mem[41352 + c2da_i_8 * 40 + 10] = uint8(c2da_fresh206 >> 0x10)
        c2da_mem[41352 + c2da_i_8 * 40 + 11] = uint8(c2da_fresh206 >> 0x18)
        let c2da_fresh207 : int = int(uint(c2da_mem[96 + c2da_i_8 * 328 + 224]) | uint(c2da_mem[96 + c2da_i_8 * 328 + 225]) << 0x8 | uint(c2da_mem[96 + c2da_i_8 * 328 + 226]) << 0x10 | uint(c2da_mem[96 + c2da_i_8 * 328 + 227]) << 0x18)
        let c2da_fresh208 : uint = uint(c2da_fresh207)
        c2da_mem[41352 + c2da_i_8 * 40 + 12] = uint8(c2da_fresh208)
        c2da_mem[41352 + c2da_i_8 * 40 + 13] = uint8(c2da_fresh208 >> 0x8)
        c2da_mem[41352 + c2da_i_8 * 40 + 14] = uint8(c2da_fresh208 >> 0x10)
        c2da_mem[41352 + c2da_i_8 * 40 + 15] = uint8(c2da_fresh208 >> 0x18)
        let c2da_fresh209 : uint = uint(leveltime)
        c2da_mem[41352 + c2da_i_8 * 40 + 16] = uint8(c2da_fresh209)
        c2da_mem[41352 + c2da_i_8 * 40 + 17] = uint8(c2da_fresh209 >> 0x8)
        c2da_mem[41352 + c2da_i_8 * 40 + 18] = uint8(c2da_fresh209 >> 0x10)
        c2da_mem[41352 + c2da_i_8 * 40 + 19] = uint8(c2da_fresh209 >> 0x18)
        c2da_lin_memcpy(41352 + c2da_i_8 * 40 + 20, 96 + c2da_i_8 * 328 + 108, 16ul)
    }
    gamestate = 1u
    viewactive = 0u
    automapactive = 0u
    StatCopy(41312)
    WI_Start(41312)
    return
}
var cpars : int[32] = fixed_array<int>(30, 90, 120, 120, 90, 150, 120, 120, 270, 90, 210, 150, 150, 150, 210, 150, 420, 150, 210, 150, 240, 150, 180, 150, 150, 300, 330, 420, 300, 180, 120, 30)

var pars : int[4][10] = fixed_array<int[10]>(fixed_array<int>(0, 0, 0, 0, 0, 0, 0, 0, 0, 0), fixed_array<int>(0, 30, 75, 120, 90, 165, 180, 180, 30, 165), fixed_array<int>(0, 90, 90, 90, 120, 90, 360, 240, 30, 170), fixed_array<int>(0, 90, 45, 90, 150, 90, 90, 165, 30, 135))

[export, sideeffects]
def G_PlayerFinishLevel(var player : int) {
    var p : int = 96 + player * 328
    c2da_lin_memset(p + 56, 0, 24ul)
    c2da_lin_memset(p + 80, 0, 24ul)
    let c2da_fresh210 : int = int(uint(c2da_mem[p]) | uint(c2da_mem[p + 1]) << 0x8 | uint(c2da_mem[p + 2]) << 0x10 | uint(c2da_mem[p + 3]) << 0x18) + 160
    let c2da_fresh211 : int = int(uint(c2da_mem[c2da_fresh210]) | uint(c2da_mem[c2da_fresh210 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh210 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh210 + 3]) << 0x18) & ~262144
    let c2da_fresh212 : uint = uint(c2da_fresh211)
    c2da_mem[c2da_fresh210] = uint8(c2da_fresh212)
    c2da_mem[c2da_fresh210 + 1] = uint8(c2da_fresh212 >> 0x8)
    c2da_mem[c2da_fresh210 + 2] = uint8(c2da_fresh212 >> 0x10)
    c2da_mem[c2da_fresh210 + 3] = uint8(c2da_fresh212 >> 0x18)
    let c2da_fresh213 : int = 0
    let c2da_fresh214 : uint = uint(c2da_fresh213)
    c2da_mem[p + 256] = uint8(c2da_fresh214)
    c2da_mem[p + 257] = uint8(c2da_fresh214 >> 0x8)
    c2da_mem[p + 258] = uint8(c2da_fresh214 >> 0x10)
    c2da_mem[p + 259] = uint8(c2da_fresh214 >> 0x18)
    let c2da_fresh215 : int = 0
    let c2da_fresh216 : uint = uint(c2da_fresh215)
    c2da_mem[p + 260] = uint8(c2da_fresh216)
    c2da_mem[p + 261] = uint8(c2da_fresh216 >> 0x8)
    c2da_mem[p + 262] = uint8(c2da_fresh216 >> 0x10)
    c2da_mem[p + 263] = uint8(c2da_fresh216 >> 0x18)
    let c2da_fresh217 : int = 0
    let c2da_fresh218 : uint = uint(c2da_fresh217)
    c2da_mem[p + 240] = uint8(c2da_fresh218)
    c2da_mem[p + 241] = uint8(c2da_fresh218 >> 0x8)
    c2da_mem[p + 242] = uint8(c2da_fresh218 >> 0x10)
    c2da_mem[p + 243] = uint8(c2da_fresh218 >> 0x18)
    let c2da_fresh219 : int = 0
    let c2da_fresh220 : uint = uint(c2da_fresh219)
    c2da_mem[p + 244] = uint8(c2da_fresh220)
    c2da_mem[p + 245] = uint8(c2da_fresh220 >> 0x8)
    c2da_mem[p + 246] = uint8(c2da_fresh220 >> 0x10)
    c2da_mem[p + 247] = uint8(c2da_fresh220 >> 0x18)
    return
}
[export, sideeffects]
def G_DoPlayDemo() {
    var skill_1 : int
    var episode_1 : int
    var map_1 : int
    var demoversion : int
    gameaction = 0u
    demo_p = W_CacheLumpName(defdemoname, 1)
    demobuffer = int(demo_p)  // nolint:PERF020
    let c2da_fresh221 : int = demo_p
    demo_p++
    demoversion = int(c2da_mem[c2da_fresh221])
    if (demoversion == G_VanillaVersionCode()) {
        longtics = 0u
    } elif (demoversion == 111) {
        longtics = 1u
    } else {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 339142, [C2daVaArg(tag = 1, i64 = int64(demoversion), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(G_VanillaVersionCode()), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(DemoVersionDescription(demoversion)))])
    }
    let c2da_fresh222 : int = demo_p
    demo_p++
    skill_1 = int(c2da_mem[c2da_fresh222])
    let c2da_fresh223 : int = demo_p
    demo_p++
    episode_1 = int(c2da_mem[c2da_fresh223])
    let c2da_fresh224 : int = demo_p
    demo_p++
    map_1 = int(c2da_mem[c2da_fresh224])
    let c2da_fresh225 : int = demo_p
    demo_p++
    deathmatch = int(c2da_mem[c2da_fresh225])
    let c2da_fresh226 : int = demo_p
    demo_p++
    respawnparm = uint(c2da_mem[c2da_fresh226])
    let c2da_fresh227 : int = demo_p
    demo_p++
    fastparm = uint(c2da_mem[c2da_fresh227])
    let c2da_fresh228 : int = demo_p
    demo_p++
    nomonsters = uint(c2da_mem[c2da_fresh228])
    let c2da_fresh229 : int = demo_p
    demo_p++
    consoleplayer = int(c2da_mem[c2da_fresh229])
    for (i_9 in range(0, 4)) {
        let c2da_fresh230 : int = demo_p
        demo_p++
        playeringame[i_9] = uint(c2da_mem[c2da_fresh230])
    }
    if (playeringame[1] != 0x0 || M_CheckParm(339359) > 0 || M_CheckParm(339369) > 0) {
        netgame = 1u
        netdemo = 1u
    }
    precache = 0u
    G_InitNew(skill_1, episode_1, map_1)
    precache = 1u
    starttime = I_GetTime()
    usergame = 0u
    demoplayback = 1u
    return
}
[sideeffects]
def private DemoVersionDescription(var version : int) : int {
    if (version == 104) {
        return 339378
    } elif (version == 105) {
        return 339383
    } elif (version == 106) {
        return 339388
    } elif (version == 107) {
        return 339400
    } elif (version == 108) {
        return 339411
    } elif (version == 109) {
        return 339416
    }
    if (version >= 0 && version <= 4) {
        return 339421
    } else {
        M_snprintf(338768, 16ul, 339436, [C2daVaArg(tag = 1, i64 = int64(version / 100), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(version % 100), f64 = 0.0lf, raw = 0x0)])
        return 338768
    }
}
[export, sideeffects]
def G_DoSaveGame() {
    var savegame_file : int
    var temp_savegame_file : int
    var recovery_savegame_file : int = 0
    temp_savegame_file = P_TempSaveGameFile()
    savegame_file = P_SaveGameFile(savegameslot)
    save_stream = c2da_lin_fopen(temp_savegame_file, 339452)
    if (save_stream == 0) {
        recovery_savegame_file = M_TempFile(339455)
        save_stream = c2da_lin_fopen(recovery_savegame_file, 339452)
        if (save_stream == 0) {
            I_Error(339468, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(temp_savegame_file)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(recovery_savegame_file))])
        }
    }
    savegame_error = 0u
    P_WriteSaveGameHeader(338512)
    P_ArchivePlayers()
    P_ArchiveWorld()
    P_ArchiveThinkers()
    P_ArchiveSpecials()
    P_WriteSaveGameEOF()
    if (int(uint(c2da_mem[1936]) | uint(c2da_mem[1937]) << 0x8 | uint(c2da_mem[1938]) << 0x10 | uint(c2da_mem[1939]) << 0x18) != 0 && c2da_std_ftell(uint64(save_stream)) > 180224l) {
        I_Error(339522, [])
    }
    c2da_std_fclose(uint64(save_stream))
    if (recovery_savegame_file != 0) {
        I_Error(339546, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(temp_savegame_file)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(recovery_savegame_file))])
    }
    c2da_lin_remove(savegame_file)
    c2da_lin_rename(temp_savegame_file, savegame_file)
    gameaction = 0u
    M_StringCopy(338512, 339644, 32ul)
    let c2da_fresh231 : uint = 339645u
    c2da_mem[96 + consoleplayer * 328 + 232] = uint8(c2da_fresh231)
    c2da_mem[96 + consoleplayer * 328 + 233] = uint8(c2da_fresh231 >> 0x8)
    c2da_mem[96 + consoleplayer * 328 + 234] = uint8(c2da_fresh231 >> 0x10)
    c2da_mem[96 + consoleplayer * 328 + 235] = uint8(c2da_fresh231 >> 0x18)
    c2da_mem[96 + consoleplayer * 328 + 236] = 0u8
    c2da_mem[96 + consoleplayer * 328 + 237] = 0u8
    c2da_mem[96 + consoleplayer * 328 + 238] = 0u8
    c2da_mem[96 + consoleplayer * 328 + 239] = 0u8
    R_FillBackScreen()
    return
}
[export, sideeffects]
def G_DoNewGame() {
    demoplayback = 0u
    netdemo = 0u
    netgame = 0u
    deathmatch = 0
    playeringame[3] = 0u
    playeringame[2] = uint(playeringame[3])  // nolint:PERF020
    playeringame[1] = uint(playeringame[2])  // nolint:PERF020
    respawnparm = 0u
    fastparm = 0u
    nomonsters = 0u
    consoleplayer = 0
    G_InitNew(d_skill, d_episode, d_map)
    gameaction = 0u
    return
}
[export, sideeffects]
def G_DoReborn(var playernum_1 : int) {
    if (netgame == 0) {
        gameaction = 1u
    } else {
        let c2da_fresh232 : int = int(uint(c2da_mem[96 + playernum_1 * 328]) | uint(c2da_mem[96 + playernum_1 * 328 + 1]) << 0x8 | uint(c2da_mem[96 + playernum_1 * 328 + 2]) << 0x10 | uint(c2da_mem[96 + playernum_1 * 328 + 3]) << 0x18) + 192
        let c2da_fresh233 : uint = 0u
        c2da_mem[c2da_fresh232] = uint8(c2da_fresh233)
        c2da_mem[c2da_fresh232 + 1] = uint8(c2da_fresh233 >> 0x8)
        c2da_mem[c2da_fresh232 + 2] = uint8(c2da_fresh233 >> 0x10)
        c2da_mem[c2da_fresh232 + 3] = uint8(c2da_fresh233 >> 0x18)
        c2da_mem[c2da_fresh232 + 4] = 0u8
        c2da_mem[c2da_fresh232 + 5] = 0u8
        c2da_mem[c2da_fresh232 + 6] = 0u8
        c2da_mem[c2da_fresh232 + 7] = 0u8
        if (deathmatch != 0) {
            G_DeathMatchSpawnPlayer(playernum_1)
            return
        }
        if (G_CheckSpot(playernum_1, 40880 + playernum_1 * 10) != 0x0) {
            P_SpawnPlayer(40880 + playernum_1 * 10)
            return
        }
        for (i_10 in range(0, 4)) {
            if (G_CheckSpot(playernum_1, 40880 + i_10 * 10) != 0x0) {
                let c2da_fresh234 : int16 = int16(playernum_1 + 1)
                let c2da_fresh235 : uint = uint(c2da_fresh234)
                c2da_mem[40880 + i_10 * 10 + 6] = uint8(c2da_fresh235)
                c2da_mem[40880 + i_10 * 10 + 7] = uint8(c2da_fresh235 >> 0x8)
                P_SpawnPlayer(40880 + i_10 * 10)
                let c2da_fresh236 : int16 = int16(i_10 + 1)
                let c2da_fresh237 : uint = uint(c2da_fresh236)
                c2da_mem[40880 + i_10 * 10 + 6] = uint8(c2da_fresh237)
                c2da_mem[40880 + i_10 * 10 + 7] = uint8(c2da_fresh237 >> 0x8)
                return
            }
        }
        P_SpawnPlayer(40880 + playernum_1 * 10)
    }
    return
}
[export, sideeffects]
def G_Responder(var ev : int) : uint {
    var c2da_fresh238 : uint
    if (gamestate == 0u && (uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 0u && int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) == int(uint(c2da_mem[43952]) | uint(c2da_mem[43953]) << 0x8 | uint(c2da_mem[43954]) << 0x10 | uint(c2da_mem[43955]) << 0x18) && (singledemo != 0x0 || deathmatch == 0)) {
        while (true) {
            displayplayer++
            if (displayplayer == 4) {
                displayplayer = 0
            }
            if (!(playeringame[displayplayer] == 0 && displayplayer != consoleplayer)) {
                break
            }
        }
        return 1u
    }
    if (gameaction == 0u && singledemo == 0 && (demoplayback != 0x0 || gamestate == 3u)) {
        if ((uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 0u || (uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 2u && int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) != 0 || (uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 3u && int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) != 0) {
            M_StartControlPanel()
            return 1u
        }
        return 0u
    }
    if (gamestate == 0u) {
        if (HU_Responder(ev) != 0x0) {
            return 1u
        }
        if (ST_Responder(ev) != 0x0) {
            return 1u
        }
        if (AM_Responder(ev) != 0x0) {
            return 1u
        }
    }
    if (gamestate == 2u) {
        if (F_Responder(ev) != 0x0) {
            return 1u
        }
    }
    if (testcontrols != 0x0 && (uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 2u) {
        testcontrols_mousespeed = c2da_std_abs(int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18))
    }
    if ((uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 0u && int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) == int(uint(c2da_mem[43280]) | uint(c2da_mem[43281]) << 0x8 | uint(c2da_mem[43282]) << 0x10 | uint(c2da_mem[43283]) << 0x18)) {
        next_weapon = -1
    } elif ((uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 0u && int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) == int(uint(c2da_mem[43296]) | uint(c2da_mem[43297]) << 0x8 | uint(c2da_mem[43298]) << 0x10 | uint(c2da_mem[43299]) << 0x18)) {
        next_weapon = 1
    }
    c2da_fresh238 = uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18
    if (c2da_fresh238 == 0x0u) {
        if (int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) == int(uint(c2da_mem[42784]) | uint(c2da_mem[42785]) << 0x8 | uint(c2da_mem[42786]) << 0x10 | uint(c2da_mem[42787]) << 0x18)) {
            sendpause = 1u
        } elif (int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) < 256) {
            let c2da_fresh239 : int = 337344 + int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) * 4
            let c2da_fresh240 : uint = 1u
            let c2da_fresh241 : uint = c2da_fresh240
            c2da_mem[c2da_fresh239] = uint8(c2da_fresh241)
            c2da_mem[c2da_fresh239 + 1] = uint8(c2da_fresh241 >> 0x8)
            c2da_mem[c2da_fresh239 + 2] = uint8(c2da_fresh241 >> 0x10)
            c2da_mem[c2da_fresh239 + 3] = uint8(c2da_fresh241 >> 0x18)
        }
        return 1u
    } elif (c2da_fresh238 == 0x1u) {
        if (int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) < 256) {
            let c2da_fresh242 : int = 337344 + int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) * 4
            let c2da_fresh243 : uint = 0u
            let c2da_fresh244 : uint = c2da_fresh243
            c2da_mem[c2da_fresh242] = uint8(c2da_fresh244)
            c2da_mem[c2da_fresh242 + 1] = uint8(c2da_fresh244 >> 0x8)
            c2da_mem[c2da_fresh242 + 2] = uint8(c2da_fresh244 >> 0x10)
            c2da_mem[c2da_fresh242 + 3] = uint8(c2da_fresh244 >> 0x18)
        }
        return 0u
    } elif (c2da_fresh238 == 0x2u) {
        SetMouseButtons(uint(int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18)))
        mousex = int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18) * (int(uint(c2da_mem[1824]) | uint(c2da_mem[1825]) << 0x8 | uint(c2da_mem[1826]) << 0x10 | uint(c2da_mem[1827]) << 0x18) + 5) / 10
        mousey = int(uint(c2da_mem[ev + 12]) | uint(c2da_mem[ev + 13]) << 0x8 | uint(c2da_mem[ev + 14]) << 0x10 | uint(c2da_mem[ev + 15]) << 0x18) * (int(uint(c2da_mem[1824]) | uint(c2da_mem[1825]) << 0x8 | uint(c2da_mem[1826]) << 0x10 | uint(c2da_mem[1827]) << 0x18) + 5) / 10
        return 1u
    } elif (c2da_fresh238 == 0x3u) {
        SetJoyButtons(uint(int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18)))
        joyxmove = int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18)
        joyymove = int(uint(c2da_mem[ev + 12]) | uint(c2da_mem[ev + 13]) << 0x8 | uint(c2da_mem[ev + 14]) << 0x10 | uint(c2da_mem[ev + 15]) << 0x18)
        joystrafemove = int(uint(c2da_mem[ev + 16]) | uint(c2da_mem[ev + 17]) << 0x8 | uint(c2da_mem[ev + 18]) << 0x10 | uint(c2da_mem[ev + 19]) << 0x18)
        return 1u
    }
    return 0u
}
[sideeffects]
def private SetJoyButtons(var buttons_mask : uint) {
    var button_on : int
    for (i_11 in range(0, 20)) {
        button_on = (buttons_mask & uint(1 << i_11)) != 0u ? 1 : 0
        if ((uint(c2da_mem[joybuttons + i_11 * 4]) | uint(c2da_mem[joybuttons + i_11 * 4 + 1]) << 0x8 | uint(c2da_mem[joybuttons + i_11 * 4 + 2]) << 0x10 | uint(c2da_mem[joybuttons + i_11 * 4 + 3]) << 0x18) == 0 && button_on != 0) {
            if (i_11 == int(uint(c2da_mem[43312]) | uint(c2da_mem[43313]) << 0x8 | uint(c2da_mem[43314]) << 0x10 | uint(c2da_mem[43315]) << 0x18)) {
                next_weapon = -1
            } elif (i_11 == int(uint(c2da_mem[43328]) | uint(c2da_mem[43329]) << 0x8 | uint(c2da_mem[43330]) << 0x10 | uint(c2da_mem[43331]) << 0x18)) {
                next_weapon = 1
            }
        }
        let c2da_fresh245 : uint = uint(button_on)
        let c2da_fresh246 : uint = c2da_fresh245
        c2da_mem[joybuttons + i_11 * 4] = uint8(c2da_fresh246)
        c2da_mem[joybuttons + i_11 * 4 + 1] = uint8(c2da_fresh246 >> 0x8)
        c2da_mem[joybuttons + i_11 * 4 + 2] = uint8(c2da_fresh246 >> 0x10)
        c2da_mem[joybuttons + i_11 * 4 + 3] = uint8(c2da_fresh246 >> 0x18)
    }
    return
}
[sideeffects]
def private SetMouseButtons(var buttons_mask_0 : uint) {
    var button_on_0 : uint
    for (i_12 in range(0, 8)) {
        button_on_0 = uint((buttons_mask_0 & uint(1 << i_12)) != 0u ? 1 : 0)
        if ((uint(c2da_mem[mousebuttons + i_12 * 4]) | uint(c2da_mem[mousebuttons + i_12 * 4 + 1]) << 0x8 | uint(c2da_mem[mousebuttons + i_12 * 4 + 2]) << 0x10 | uint(c2da_mem[mousebuttons + i_12 * 4 + 3]) << 0x18) == 0 && button_on_0 != 0x0) {
            if (i_12 == int(uint(c2da_mem[43344]) | uint(c2da_mem[43345]) << 0x8 | uint(c2da_mem[43346]) << 0x10 | uint(c2da_mem[43347]) << 0x18)) {
                next_weapon = -1
            } elif (i_12 == int(uint(c2da_mem[43360]) | uint(c2da_mem[43361]) << 0x8 | uint(c2da_mem[43362]) << 0x10 | uint(c2da_mem[43363]) << 0x18)) {
                next_weapon = 1
            }
        }
        let c2da_fresh247 : uint = button_on_0
        c2da_mem[mousebuttons + i_12 * 4] = uint8(c2da_fresh247)
        c2da_mem[mousebuttons + i_12 * 4 + 1] = uint8(c2da_fresh247 >> 0x8)
        c2da_mem[mousebuttons + i_12 * 4 + 2] = uint8(c2da_fresh247 >> 0x10)
        c2da_mem[mousebuttons + i_12 * 4 + 3] = uint8(c2da_fresh247 >> 0x18)
    }
    return
}
[export, sideeffects]
def G_ScreenShot() {
    gameaction = 9u
    return
}
[export, sideeffects]
def G_PlayerReborn(var player_0 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    G_PlayerReborn_c2da_frame(player_0, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def G_CmdChecksum(var cmd_3 : int) : int {
    var i_14 : uint64
    var sum : int = 0
    i_14 = 0ul
    while (i_14 < 16ul / 4ul - 1ul) {
        sum += int(uint(c2da_mem[cmd_3 + int(i_14) * 4]) | uint(c2da_mem[cmd_3 + int(i_14) * 4 + 1]) << 0x8 | uint(c2da_mem[cmd_3 + int(i_14) * 4 + 2]) << 0x10 | uint(c2da_mem[cmd_3 + int(i_14) * 4 + 3]) << 0x18)
        i_14++
    }
    return sum
}
[export, sideeffects]
def G_InitPlayer(var player_1 : int) {
    G_PlayerReborn(player_1)
    return
}
[sideeffects]
def private G_PlayerReborn_c2da_frame(var player_0 : int; c2da_fp : int) {
    var p_0 : int
    var killcount : int
    var itemcount : int
    var secretcount : int
    c2da_lin_memcpy(c2da_fp, 96 + player_0 * 328 + 108, 16ul)
    killcount = int(uint(c2da_mem[96 + player_0 * 328 + 216]) | uint(c2da_mem[96 + player_0 * 328 + 217]) << 0x8 | uint(c2da_mem[96 + player_0 * 328 + 218]) << 0x10 | uint(c2da_mem[96 + player_0 * 328 + 219]) << 0x18)
    itemcount = int(uint(c2da_mem[96 + player_0 * 328 + 220]) | uint(c2da_mem[96 + player_0 * 328 + 221]) << 0x8 | uint(c2da_mem[96 + player_0 * 328 + 222]) << 0x10 | uint(c2da_mem[96 + player_0 * 328 + 223]) << 0x18)
    secretcount = int(uint(c2da_mem[96 + player_0 * 328 + 224]) | uint(c2da_mem[96 + player_0 * 328 + 225]) << 0x8 | uint(c2da_mem[96 + player_0 * 328 + 226]) << 0x10 | uint(c2da_mem[96 + player_0 * 328 + 227]) << 0x18)
    p_0 = 96 + player_0 * 328
    c2da_lin_memset(p_0, 0, 328ul)
    c2da_lin_memcpy(96 + player_0 * 328 + 108, c2da_fp, 16ul)
    let c2da_fresh248 : uint = uint(killcount)
    c2da_mem[96 + player_0 * 328 + 216] = uint8(c2da_fresh248)
    c2da_mem[96 + player_0 * 328 + 217] = uint8(c2da_fresh248 >> 0x8)
    c2da_mem[96 + player_0 * 328 + 218] = uint8(c2da_fresh248 >> 0x10)
    c2da_mem[96 + player_0 * 328 + 219] = uint8(c2da_fresh248 >> 0x18)
    let c2da_fresh249 : uint = uint(itemcount)
    c2da_mem[96 + player_0 * 328 + 220] = uint8(c2da_fresh249)
    c2da_mem[96 + player_0 * 328 + 221] = uint8(c2da_fresh249 >> 0x8)
    c2da_mem[96 + player_0 * 328 + 222] = uint8(c2da_fresh249 >> 0x10)
    c2da_mem[96 + player_0 * 328 + 223] = uint8(c2da_fresh249 >> 0x18)
    let c2da_fresh250 : uint = uint(secretcount)
    c2da_mem[96 + player_0 * 328 + 224] = uint8(c2da_fresh250)
    c2da_mem[96 + player_0 * 328 + 225] = uint8(c2da_fresh250 >> 0x8)
    c2da_mem[96 + player_0 * 328 + 226] = uint8(c2da_fresh250 >> 0x10)
    c2da_mem[96 + player_0 * 328 + 227] = uint8(c2da_fresh250 >> 0x18)
    let c2da_fresh251 : int = 1
    let c2da_fresh252 : uint = uint(c2da_fresh251)
    c2da_mem[p_0 + 200] = uint8(c2da_fresh252)
    c2da_mem[p_0 + 201] = uint8(c2da_fresh252 >> 0x8)
    c2da_mem[p_0 + 202] = uint8(c2da_fresh252 >> 0x10)
    c2da_mem[p_0 + 203] = uint8(c2da_fresh252 >> 0x18)
    let c2da_fresh253 : uint = uint(c2da_fresh251)
    c2da_mem[p_0 + 204] = uint8(c2da_fresh253)
    c2da_mem[p_0 + 205] = uint8(c2da_fresh253 >> 0x8)
    c2da_mem[p_0 + 206] = uint8(c2da_fresh253 >> 0x10)
    c2da_mem[p_0 + 207] = uint8(c2da_fresh253 >> 0x18)
    let c2da_fresh254 : uint = 0u
    let c2da_fresh255 : uint = c2da_fresh254
    c2da_mem[p_0 + 8] = uint8(c2da_fresh255)
    c2da_mem[p_0 + 9] = uint8(c2da_fresh255 >> 0x8)
    c2da_mem[p_0 + 10] = uint8(c2da_fresh255 >> 0x10)
    c2da_mem[p_0 + 11] = uint8(c2da_fresh255 >> 0x18)
    let c2da_fresh256 : int = 100
    let c2da_fresh257 : uint = uint(c2da_fresh256)
    c2da_mem[p_0 + 44] = uint8(c2da_fresh257)
    c2da_mem[p_0 + 45] = uint8(c2da_fresh257 >> 0x8)
    c2da_mem[p_0 + 46] = uint8(c2da_fresh257 >> 0x10)
    c2da_mem[p_0 + 47] = uint8(c2da_fresh257 >> 0x18)
    let c2da_fresh258 : uint = 1u
    let c2da_fresh259 : uint = c2da_fresh258
    c2da_mem[p_0 + 128] = uint8(c2da_fresh259)
    c2da_mem[p_0 + 129] = uint8(c2da_fresh259 >> 0x8)
    c2da_mem[p_0 + 130] = uint8(c2da_fresh259 >> 0x10)
    c2da_mem[p_0 + 131] = uint8(c2da_fresh259 >> 0x18)
    let c2da_fresh260 : uint = c2da_fresh258
    c2da_mem[p_0 + 124] = uint8(c2da_fresh260)
    c2da_mem[p_0 + 125] = uint8(c2da_fresh260 >> 0x8)
    c2da_mem[p_0 + 126] = uint8(c2da_fresh260 >> 0x10)
    c2da_mem[p_0 + 127] = uint8(c2da_fresh260 >> 0x18)
    let c2da_fresh261 : uint = 1u
    let c2da_fresh262 : uint = c2da_fresh261
    c2da_mem[p_0 + 132 + 0 * 4] = uint8(c2da_fresh262)
    c2da_mem[p_0 + 132 + 0 * 4 + 1] = uint8(c2da_fresh262 >> 0x8)
    c2da_mem[p_0 + 132 + 0 * 4 + 2] = uint8(c2da_fresh262 >> 0x10)
    c2da_mem[p_0 + 132 + 0 * 4 + 3] = uint8(c2da_fresh262 >> 0x18)
    let c2da_fresh263 : uint = 1u
    let c2da_fresh264 : uint = c2da_fresh263
    c2da_mem[p_0 + 132 + 1 * 4] = uint8(c2da_fresh264)
    c2da_mem[p_0 + 132 + 1 * 4 + 1] = uint8(c2da_fresh264 >> 0x8)
    c2da_mem[p_0 + 132 + 1 * 4 + 2] = uint8(c2da_fresh264 >> 0x10)
    c2da_mem[p_0 + 132 + 1 * 4 + 3] = uint8(c2da_fresh264 >> 0x18)
    let c2da_fresh265 : int = 50
    let c2da_fresh266 : uint = uint(c2da_fresh265)
    c2da_mem[p_0 + 168 + 0 * 4] = uint8(c2da_fresh266)
    c2da_mem[p_0 + 168 + 0 * 4 + 1] = uint8(c2da_fresh266 >> 0x8)
    c2da_mem[p_0 + 168 + 0 * 4 + 2] = uint8(c2da_fresh266 >> 0x10)
    c2da_mem[p_0 + 168 + 0 * 4 + 3] = uint8(c2da_fresh266 >> 0x18)
    for (i_13 in range(0, 4)) {
        let c2da_fresh267 : int = maxammo[i_13]
        let c2da_fresh268 : uint = uint(c2da_fresh267)
        c2da_mem[p_0 + 184 + i_13 * 4] = uint8(c2da_fresh268)
        c2da_mem[p_0 + 184 + i_13 * 4 + 1] = uint8(c2da_fresh268 >> 0x8)
        c2da_mem[p_0 + 184 + i_13 * 4 + 2] = uint8(c2da_fresh268 >> 0x10)
        c2da_mem[p_0 + 184 + i_13 * 4 + 3] = uint8(c2da_fresh268 >> 0x18)
    }
    return
}

// This unit's static data, at heap offset 337344.
let private c2da_lin_static_g_game_seg = fixed_array<int>(338544, 133, 338784, 872)
let private c2da_lin_static_g_game = fixed_array<uint64>(0xa0e0ul, 0xa0f0ul, 0xa100ul, 0xa110ul, 0xa120ul, 0xa130ul, 0xa140ul, 0xa150ul, 0x0ul, 0x7ul, 0x100000001ul, 0x200000002ul, 0x200000008ul, 0x300000003ul, 0x400000004ul, 0x500000005ul, 0x6c6e4f0600000006ul, 0x6165642069252079ul, 0x20686374616d6874ul, 0x34202c73746f7073ul, 0x6572697571657220ul, 0x636568435f470064ul, 0x75203a746f70536bul, 0x657463657078656eul, 0x20656c676e612064ul, 0x31594b53000a6425ul, 0x4b530032594b5300ul, 0x34594b53003359ul, 0x500031594b535f46ul, 0x6373652073736572ul, 0x71206f7420657061ul, 0x6272002e746975ul, 0x6576617320646142ul, 0x2e732500656d6167ul, 0x78616d2d00706d6cul, 0x6f6c2d006f6d6564ul, 0x440073636974676eul, 0x20322e31206d6f6ful, 0x746f6e2073656f64ul, 0x2061206576616820ul, 0x206e6f6973726576ul, 0x6e2d002165646f63ul, 0x697400776172646ful, 0x672069252064656dul, 0x2073636974656d61ul, 0x6572206925206e69ul, 0x2820736369746c61ul, 0x29737066206625ul, 0x207325206f6d6544ul, 0x646564726f636572ul, 0x4400313370616d00ul, 0x2e693230254d4f4ful, 0x6565726373007325ul, 0x2500746f6873206eul, 0x7275742073692073ul, 0x736e6f6300216f62ul, 0x2079636e65747369ul, 0x206572756c696166ul, 0x756f687320692528ul, 0x692520656220646cul, 0x41472054454e0029ul, 0x206f6d654400454dul, 0x206d6f7266207369ul, 0x7265666669642061ul, 0x656d616720746e65ul, 0x6e6f697372657620ul, 0x2064616572280a21ul, 0x756f6873202c6925ul, 0x692520656220646cul, 0x59202a2a2a0a0a29ul, 0x6e2079616d20756ful, 0x75206f7420646565ul, 0x7920656461726770ul, 0x737265762072756ful, 0x4420666f206e6f69ul, 0x76206f74206d6f6ful, 0x2a2a2a202e392e31ul, 0x656553202020200aul, 0x3a7370747468203aul, 0x6f642e7777772f2ful, 0x2e646c726f776d6ful, 0x73616c632f6d6f63ul, 0x2f6d6f6f64636973ul, 0x7461702f6f666e69ul, 0x7068702e73656863ul, 0x696854202020200aul, 0x7261657070612073ul, 0x206562206f742073ul, 0x6c6f732d002e7325ul, 0x6e2d0074656e2d6ful, 0x76006f6d65647465ul, 0x352e317600342e31ul, 0x31762f362e317600ul, 0x2e3176003636362eul, 0x61372e31762f37ul, 0x2e317600382e3176ul, 0x762f302e31760039ul, 0x322e31762f312e31ul, 0x282069252e692500ul, 0x296e776f6e6b6e75ul, 0x6f63657200627700ul, 0x6773642e79726576ul, 0x2064656c69614600ul, 0x206e65706f206f74ul, 0x2720726568746965ul, 0x2720726f20277325ul, 0x77206f7420277325ul, 0x7661732065746972ul, 0x53002e656d616765ul, 0x20656d6167657661ul, 0x6f20726566667562ul, 0x46006e7572726576ul, 0x6f742064656c6961ul, 0x6173206e65706f20ul, 0x6620656d61676576ul, 0x2773252720656c69ul, 0x69727720726f6620ul, 0x75420a2e676e6974ul, 0x672072756f792074ul, 0x2073616820656d61ul, 0x766173206e656562ul, 0x2527206f74206465ul, 0x7220726f66202773ul, 0x2e797265766f6365ul, 0x7320656d61670000ul, 0x2e64657661ul)

[init]
def private c2da_lin_init_static_g_game() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(2)) {
        let at = c2da_lin_static_g_game_seg[s * 2]
        for (k in range(c2da_lin_static_g_game_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_g_game[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_g_game_0 = fixed_array<uint8>(0x1, 0x0, 0x0, 0x0)
let private c2da_lin_extern_g_game_1 = fixed_array<uint8>(0x1, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_g_game() {
    c2da_lin_setup()
    for (i in range(4)) {
        c2da_mem[1952 + i] = c2da_lin_extern_g_game_0[i]
    }
    for (i in range(4)) {
        c2da_mem[1936 + i] = c2da_lin_extern_g_game_1[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_g_game() {
    if (length(c2da_fn_table1) < 8) {
        resize(c2da_fn_table1, 8)
    }
    c2da_fn_table1[7] = @@G_BuildTiccmd
    if (length(c2da_fn_table2) < 8) {
        resize(c2da_fn_table2, 8)
    }
    c2da_fn_table2[4] = @@G_CheckDemoStatus
}

[init]
def private c2da_lin_relink_init_g_game() {
    c2da_relink_g_game()
}
