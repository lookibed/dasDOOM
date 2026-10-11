[sideeffects]
def private c2da___bswap_16_16(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_16(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_16(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_16(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_16(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_16(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
[export, sideeffects]
def S_Init(var sfxVolume_0 : int; var musicVolume_0 : int) {
    var i : int
    I_PrecacheSounds(247536, 109)
    S_SetSfxVolume(sfxVolume_0)
    S_SetMusicVolume(musicVolume_0)
    channels = Z_Malloc(int(uint64(int(uint(c2da_mem[1920]) | uint(c2da_mem[1921]) << 0x8 | uint(c2da_mem[1922]) << 0x10 | uint(c2da_mem[1923]) << 0x18)) * 24ul), 1, 0)
    i = 0
    while (i < int(uint(c2da_mem[1920]) | uint(c2da_mem[1921]) << 0x8 | uint(c2da_mem[1922]) << 0x10 | uint(c2da_mem[1923]) << 0x18)) {
        let c2da_fresh0 : uint = 0u
        c2da_mem[channels + i * 24] = uint8(c2da_fresh0)
        c2da_mem[channels + i * 24 + 1] = uint8(c2da_fresh0 >> 0x8)
        c2da_mem[channels + i * 24 + 2] = uint8(c2da_fresh0 >> 0x10)
        c2da_mem[channels + i * 24 + 3] = uint8(c2da_fresh0 >> 0x18)
        c2da_mem[channels + i * 24 + 4] = 0u8
        c2da_mem[channels + i * 24 + 5] = 0u8
        c2da_mem[channels + i * 24 + 6] = 0u8
        c2da_mem[channels + i * 24 + 7] = 0u8
        i++
    }
    mus_paused = 0u
    i = 1
    for (c2da_i in range(i, 109)) {
        let c2da_fresh1 : int = -1
        let c2da_fresh2 : uint = uint(c2da_fresh1)
        c2da_mem[247536 + c2da_i * 64 + 40] = uint8(c2da_fresh2)
        c2da_mem[247536 + c2da_i * 64 + 41] = uint8(c2da_fresh2 >> 0x8)
        c2da_mem[247536 + c2da_i * 64 + 42] = uint8(c2da_fresh2 >> 0x10)
        c2da_mem[247536 + c2da_i * 64 + 43] = uint8(c2da_fresh2 >> 0x18)
        let c2da_fresh3 : uint = uint(c2da_fresh1)
        c2da_mem[247536 + c2da_i * 64 + 44] = uint8(c2da_fresh3)
        c2da_mem[247536 + c2da_i * 64 + 45] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[247536 + c2da_i * 64 + 46] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[247536 + c2da_i * 64 + 47] = uint8(c2da_fresh3 >> 0x18)
    }
    I_AtExit(152, 1u)
    return
}
[export, sideeffects]
def S_Shutdown() {
    I_ShutdownSound()
    I_ShutdownMusic()
    return
}
var private mus_paused : uint = default<uint>

var private channels : int = default<int>

[export, sideeffects]
def S_SetMusicVolume(var volume : int) {
    if (volume < 0 || volume > 127) {
        I_Error(373840, [C2daVaArg(tag = 1, i64 = int64(volume), f64 = 0.0lf, raw = 0x0)])
    }
    I_SetMusicVolume(volume)
    return
}
[export, sideeffects]
def S_SetSfxVolume(var volume_0 : int) {
    if (volume_0 < 0 || volume_0 > 127) {
        I_Error(373874, [C2daVaArg(tag = 1, i64 = int64(volume_0), f64 = 0.0lf, raw = 0x0)])
    }
    snd_SfxVolume = int(volume_0)  // nolint:PERF020
    return
}
var private snd_SfxVolume : int = default<int>

[export, sideeffects]
def S_Start() {
    var cnum : int
    var mnum : int
    var spmus : int[9]
    cnum = 0
    while (cnum < int(uint(c2da_mem[1920]) | uint(c2da_mem[1921]) << 0x8 | uint(c2da_mem[1922]) << 0x10 | uint(c2da_mem[1923]) << 0x18)) {
        if (int(uint(c2da_mem[channels + cnum * 24]) | uint(c2da_mem[channels + cnum * 24 + 1]) << 0x8 | uint(c2da_mem[channels + cnum * 24 + 2]) << 0x10 | uint(c2da_mem[channels + cnum * 24 + 3]) << 0x18) != 0) {
            S_StopChannel(cnum)
        }
        cnum++
    }
    mus_paused = 0u
    if (uint(gamemode) == 2u) {
        mnum = 33 + gamemap - 1
    } else {
        spmus = fixed_array<int>(22, 20, 21, 5, 16, 13, 15, 14, 9)
        if (gameepisode < 4) {
            mnum = 1 + (gameepisode - 1) * 9 + gamemap - 1
        } else {
            mnum = spmus[int(gamemap - 1)]
        }
    }
    S_ChangeMusic(mnum, 1)
    return
}
[export, sideeffects]
def S_ChangeMusic(var musicnum : int; var looping : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    S_ChangeMusic_c2da_frame(musicnum, looping, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
var private mus_playing : int = 0

[export, sideeffects]
def S_StopMusic() {
    if (mus_playing != 0) {
        if (mus_paused != 0x0) {
            I_ResumeSong()
        }
        I_StopSong()
        I_UnRegisterSong(int(uint(c2da_mem[mus_playing + 24]) | uint(c2da_mem[mus_playing + 25]) << 0x8 | uint(c2da_mem[mus_playing + 26]) << 0x10 | uint(c2da_mem[mus_playing + 27]) << 0x18))
        W_ReleaseLumpNum(int(uint(c2da_mem[mus_playing + 8]) | uint(c2da_mem[mus_playing + 9]) << 0x8 | uint(c2da_mem[mus_playing + 10]) << 0x10 | uint(c2da_mem[mus_playing + 11]) << 0x18))
        let c2da_fresh9 : uint = 0u
        c2da_mem[mus_playing + 16] = uint8(c2da_fresh9)
        c2da_mem[mus_playing + 17] = uint8(c2da_fresh9 >> 0x8)
        c2da_mem[mus_playing + 18] = uint8(c2da_fresh9 >> 0x10)
        c2da_mem[mus_playing + 19] = uint8(c2da_fresh9 >> 0x18)
        c2da_mem[mus_playing + 20] = 0u8
        c2da_mem[mus_playing + 21] = 0u8
        c2da_mem[mus_playing + 22] = 0u8
        c2da_mem[mus_playing + 23] = 0u8
        mus_playing = 0
    }
    return
}
[sideeffects]
def private S_StopChannel(var cnum_0 : int) {
    var i_0 : int
    var c : int = channels + cnum_0 * 24
    if (int(uint(c2da_mem[c]) | uint(c2da_mem[c + 1]) << 0x8 | uint(c2da_mem[c + 2]) << 0x10 | uint(c2da_mem[c + 3]) << 0x18) != 0) {
        if (I_SoundIsPlaying(int(uint(c2da_mem[c + 16]) | uint(c2da_mem[c + 17]) << 0x8 | uint(c2da_mem[c + 18]) << 0x10 | uint(c2da_mem[c + 19]) << 0x18)) != 0x0) {
            I_StopSound(int(uint(c2da_mem[c + 16]) | uint(c2da_mem[c + 17]) << 0x8 | uint(c2da_mem[c + 18]) << 0x10 | uint(c2da_mem[c + 19]) << 0x18))
        }
        i_0 = 0
        while (i_0 < int(uint(c2da_mem[1920]) | uint(c2da_mem[1921]) << 0x8 | uint(c2da_mem[1922]) << 0x10 | uint(c2da_mem[1923]) << 0x18)) {
            if (cnum_0 != i_0 && int(uint(c2da_mem[c]) | uint(c2da_mem[c + 1]) << 0x8 | uint(c2da_mem[c + 2]) << 0x10 | uint(c2da_mem[c + 3]) << 0x18) == int(uint(c2da_mem[channels + i_0 * 24]) | uint(c2da_mem[channels + i_0 * 24 + 1]) << 0x8 | uint(c2da_mem[channels + i_0 * 24 + 2]) << 0x10 | uint(c2da_mem[channels + i_0 * 24 + 3]) << 0x18)) {
                break
            }
            i_0++
        }
        let c2da_fresh10 : int = int(uint(c2da_mem[c]) | uint(c2da_mem[c + 1]) << 0x8 | uint(c2da_mem[c + 2]) << 0x10 | uint(c2da_mem[c + 3]) << 0x18) + 40
        let c2da_fresh11 : int = int(uint(c2da_mem[c2da_fresh10]) | uint(c2da_mem[c2da_fresh10 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh10 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh10 + 3]) << 0x18)
        let c2da_fresh12 : int = c2da_fresh11 - 1
        let c2da_fresh13 : uint = uint(c2da_fresh12)
        c2da_mem[c2da_fresh10] = uint8(c2da_fresh13)
        c2da_mem[c2da_fresh10 + 1] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[c2da_fresh10 + 2] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[c2da_fresh10 + 3] = uint8(c2da_fresh13 >> 0x18)
        let c2da_fresh14 : uint = 0u
        c2da_mem[c] = uint8(c2da_fresh14)
        c2da_mem[c + 1] = uint8(c2da_fresh14 >> 0x8)
        c2da_mem[c + 2] = uint8(c2da_fresh14 >> 0x10)
        c2da_mem[c + 3] = uint8(c2da_fresh14 >> 0x18)
        c2da_mem[c + 4] = 0u8
        c2da_mem[c + 5] = 0u8
        c2da_mem[c + 6] = 0u8
        c2da_mem[c + 7] = 0u8
    }
    return
}
[export, sideeffects]
def S_StartSound(var origin_p : int; var sfx_id : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    S_StartSound_c2da_frame(origin_p, sfx_id, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private S_GetChannel(var origin_0 : int; var sfxinfo : int) : int {
    var cnum_2 : int
    var c_0 : int
    cnum_2 = 0
    while (cnum_2 < int(uint(c2da_mem[1920]) | uint(c2da_mem[1921]) << 0x8 | uint(c2da_mem[1922]) << 0x10 | uint(c2da_mem[1923]) << 0x18)) {
        if (int(uint(c2da_mem[channels + cnum_2 * 24]) | uint(c2da_mem[channels + cnum_2 * 24 + 1]) << 0x8 | uint(c2da_mem[channels + cnum_2 * 24 + 2]) << 0x10 | uint(c2da_mem[channels + cnum_2 * 24 + 3]) << 0x18) == 0) {
            break
        } elif (origin_0 != 0 && int(uint(c2da_mem[channels + cnum_2 * 24 + 8]) | uint(c2da_mem[channels + cnum_2 * 24 + 9]) << 0x8 | uint(c2da_mem[channels + cnum_2 * 24 + 10]) << 0x10 | uint(c2da_mem[channels + cnum_2 * 24 + 11]) << 0x18) == origin_0) {
            S_StopChannel(cnum_2)
            break
        }
        cnum_2++
    }
    if (cnum_2 == int(uint(c2da_mem[1920]) | uint(c2da_mem[1921]) << 0x8 | uint(c2da_mem[1922]) << 0x10 | uint(c2da_mem[1923]) << 0x18)) {
        cnum_2 = 0
        while (cnum_2 < int(uint(c2da_mem[1920]) | uint(c2da_mem[1921]) << 0x8 | uint(c2da_mem[1922]) << 0x10 | uint(c2da_mem[1923]) << 0x18)) {
            let c2da_fresh35 : int = int(uint(c2da_mem[channels + cnum_2 * 24]) | uint(c2da_mem[channels + cnum_2 * 24 + 1]) << 0x8 | uint(c2da_mem[channels + cnum_2 * 24 + 2]) << 0x10 | uint(c2da_mem[channels + cnum_2 * 24 + 3]) << 0x18) + 20
            if (int(uint(c2da_mem[c2da_fresh35]) | uint(c2da_mem[c2da_fresh35 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh35 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh35 + 3]) << 0x18) >= int(uint(c2da_mem[sfxinfo + 20]) | uint(c2da_mem[sfxinfo + 21]) << 0x8 | uint(c2da_mem[sfxinfo + 22]) << 0x10 | uint(c2da_mem[sfxinfo + 23]) << 0x18)) {
                break
            }
            cnum_2++
        }
        if (cnum_2 == int(uint(c2da_mem[1920]) | uint(c2da_mem[1921]) << 0x8 | uint(c2da_mem[1922]) << 0x10 | uint(c2da_mem[1923]) << 0x18)) {
            return -1
        } else {
            S_StopChannel(cnum_2)
        }
    }
    c_0 = channels + cnum_2 * 24
    let c2da_fresh36 : uint = uint(sfxinfo)
    c2da_mem[c_0] = uint8(c2da_fresh36)
    c2da_mem[c_0 + 1] = uint8(c2da_fresh36 >> 0x8)
    c2da_mem[c_0 + 2] = uint8(c2da_fresh36 >> 0x10)
    c2da_mem[c_0 + 3] = uint8(c2da_fresh36 >> 0x18)
    c2da_mem[c_0 + 4] = 0u8
    c2da_mem[c_0 + 5] = 0u8
    c2da_mem[c_0 + 6] = 0u8
    c2da_mem[c_0 + 7] = 0u8
    let c2da_fresh37 : uint = uint(origin_0)
    c2da_mem[c_0 + 8] = uint8(c2da_fresh37)
    c2da_mem[c_0 + 9] = uint8(c2da_fresh37 >> 0x8)
    c2da_mem[c_0 + 10] = uint8(c2da_fresh37 >> 0x10)
    c2da_mem[c_0 + 11] = uint8(c2da_fresh37 >> 0x18)
    c2da_mem[c_0 + 12] = 0u8
    c2da_mem[c_0 + 13] = 0u8
    c2da_mem[c_0 + 14] = 0u8
    c2da_mem[c_0 + 15] = 0u8
    return cnum_2
}
[export, sideeffects]
def S_StopSound(var origin_1 : int) {
    var cnum_3 : int = 0
    while (cnum_3 < int(uint(c2da_mem[1920]) | uint(c2da_mem[1921]) << 0x8 | uint(c2da_mem[1922]) << 0x10 | uint(c2da_mem[1923]) << 0x18)) {
        if (int(uint(c2da_mem[channels + cnum_3 * 24]) | uint(c2da_mem[channels + cnum_3 * 24 + 1]) << 0x8 | uint(c2da_mem[channels + cnum_3 * 24 + 2]) << 0x10 | uint(c2da_mem[channels + cnum_3 * 24 + 3]) << 0x18) != 0 && int(uint(c2da_mem[channels + cnum_3 * 24 + 8]) | uint(c2da_mem[channels + cnum_3 * 24 + 9]) << 0x8 | uint(c2da_mem[channels + cnum_3 * 24 + 10]) << 0x10 | uint(c2da_mem[channels + cnum_3 * 24 + 11]) << 0x18) == origin_1) {
            S_StopChannel(cnum_3)
            break
        }
        cnum_3++
    }
    return
}
[sideeffects]
def private S_AdjustSoundParams(var listener : int; var source : int; var vol : int; var sep : int) : int {
    var approx_dist : int
    var adx : int
    var ady : int
    var angle : uint
    adx = c2da_std_abs(int(uint(c2da_mem[listener + 24]) | uint(c2da_mem[listener + 25]) << 0x8 | uint(c2da_mem[listener + 26]) << 0x10 | uint(c2da_mem[listener + 27]) << 0x18) - int(uint(c2da_mem[source + 24]) | uint(c2da_mem[source + 25]) << 0x8 | uint(c2da_mem[source + 26]) << 0x10 | uint(c2da_mem[source + 27]) << 0x18))
    ady = c2da_std_abs(int(uint(c2da_mem[listener + 28]) | uint(c2da_mem[listener + 29]) << 0x8 | uint(c2da_mem[listener + 30]) << 0x10 | uint(c2da_mem[listener + 31]) << 0x18) - int(uint(c2da_mem[source + 28]) | uint(c2da_mem[source + 29]) << 0x8 | uint(c2da_mem[source + 30]) << 0x10 | uint(c2da_mem[source + 31]) << 0x18))
    approx_dist = adx + ady - ((adx < ady ? adx : ady) >> 1)
    if (gamemap != 8 && approx_dist > 1200 * (1 << 16)) {
        return 0
    }
    angle = uint(R_PointToAngle2(int(uint(c2da_mem[listener + 24]) | uint(c2da_mem[listener + 25]) << 0x8 | uint(c2da_mem[listener + 26]) << 0x10 | uint(c2da_mem[listener + 27]) << 0x18), int(uint(c2da_mem[listener + 28]) | uint(c2da_mem[listener + 29]) << 0x8 | uint(c2da_mem[listener + 30]) << 0x10 | uint(c2da_mem[listener + 31]) << 0x18), int(uint(c2da_mem[source + 24]) | uint(c2da_mem[source + 25]) << 0x8 | uint(c2da_mem[source + 26]) << 0x10 | uint(c2da_mem[source + 27]) << 0x18), int(uint(c2da_mem[source + 28]) | uint(c2da_mem[source + 29]) << 0x8 | uint(c2da_mem[source + 30]) << 0x10 | uint(c2da_mem[source + 31]) << 0x18)))
    if (angle > (uint(c2da_mem[listener + 56]) | uint(c2da_mem[listener + 57]) << 0x8 | uint(c2da_mem[listener + 58]) << 0x10 | uint(c2da_mem[listener + 59]) << 0x18)) {
        angle -= uint(c2da_mem[listener + 56]) | uint(c2da_mem[listener + 57]) << 0x8 | uint(c2da_mem[listener + 58]) << 0x10 | uint(c2da_mem[listener + 59]) << 0x18
    } else {
        angle += 0xffffffffu - (uint(c2da_mem[listener + 56]) | uint(c2da_mem[listener + 57]) << 0x8 | uint(c2da_mem[listener + 58]) << 0x10 | uint(c2da_mem[listener + 59]) << 0x18)
    }
    angle >>= 19u
    let c2da_fresh38 : int = 128 - (FixedMul(96 * (1 << 16), int(uint(c2da_mem[257920 + int(angle) * 4]) | uint(c2da_mem[257920 + int(angle) * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + int(angle) * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + int(angle) * 4 + 3]) << 0x18)) >> 16)
    let c2da_fresh39 : uint = uint(c2da_fresh38)
    c2da_mem[sep] = uint8(c2da_fresh39)
    c2da_mem[sep + 1] = uint8(c2da_fresh39 >> 0x8)
    c2da_mem[sep + 2] = uint8(c2da_fresh39 >> 0x10)
    c2da_mem[sep + 3] = uint8(c2da_fresh39 >> 0x18)
    if (approx_dist < 200 * (1 << 16)) {
        let c2da_fresh40 : uint = uint(snd_SfxVolume)
        c2da_mem[vol] = uint8(c2da_fresh40)
        c2da_mem[vol + 1] = uint8(c2da_fresh40 >> 0x8)
        c2da_mem[vol + 2] = uint8(c2da_fresh40 >> 0x10)
        c2da_mem[vol + 3] = uint8(c2da_fresh40 >> 0x18)
    } elif (gamemap == 8) {
        if (approx_dist > 1200 * (1 << 16)) {
            approx_dist = 1200 * (1 << 16)
        }
        let c2da_fresh41 : int = 15 + (snd_SfxVolume - 15) * (1200 * (1 << 16) - approx_dist >> 16) / (1200 * (1 << 16) - 200 * (1 << 16) >> 16)
        let c2da_fresh42 : uint = uint(c2da_fresh41)
        c2da_mem[vol] = uint8(c2da_fresh42)
        c2da_mem[vol + 1] = uint8(c2da_fresh42 >> 0x8)
        c2da_mem[vol + 2] = uint8(c2da_fresh42 >> 0x10)
        c2da_mem[vol + 3] = uint8(c2da_fresh42 >> 0x18)
    } else {
        let c2da_fresh43 : int = snd_SfxVolume * (1200 * (1 << 16) - approx_dist >> 16) / (1200 * (1 << 16) - 200 * (1 << 16) >> 16)
        let c2da_fresh44 : uint = uint(c2da_fresh43)
        c2da_mem[vol] = uint8(c2da_fresh44)
        c2da_mem[vol + 1] = uint8(c2da_fresh44 >> 0x8)
        c2da_mem[vol + 2] = uint8(c2da_fresh44 >> 0x10)
        c2da_mem[vol + 3] = uint8(c2da_fresh44 >> 0x18)
    }
    return int(uint(c2da_mem[vol]) | uint(c2da_mem[vol + 1]) << 0x8 | uint(c2da_mem[vol + 2]) << 0x10 | uint(c2da_mem[vol + 3]) << 0x18) > 0 ? 1 : 0
}
[export, sideeffects]
def S_StartMusic(var m_id : int) {
    S_ChangeMusic(m_id, 0)
    return
}
[export, sideeffects]
def S_MusicPlaying() : uint {
    return I_MusicIsPlaying()
}
[export, sideeffects]
def S_PauseSound() {
    if (mus_playing != 0 && mus_paused == 0) {
        I_PauseSong()
        mus_paused = 1u
    }
    return
}
[export, sideeffects]
def S_ResumeSound() {
    if (mus_playing != 0 && mus_paused != 0x0) {
        I_ResumeSong()
        mus_paused = 0u
    }
    return
}
[export, sideeffects]
def S_UpdateSounds(var listener_0 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    S_UpdateSounds_c2da_frame(listener_0, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private S_ChangeMusic_c2da_frame(var musicnum : int; var looping : int; c2da_fp : int) {
    var music : int
    var handle : int
    music = 0
    if (musicnum == 29 && (int(uint(c2da_mem[42256]) | uint(c2da_mem[42257]) << 0x8 | uint(c2da_mem[42258]) << 0x10 | uint(c2da_mem[42259]) << 0x18) == 2 || int(uint(c2da_mem[42256]) | uint(c2da_mem[42257]) << 0x8 | uint(c2da_mem[42258]) << 0x10 | uint(c2da_mem[42259]) << 0x18) == 3)) {
        musicnum = 32
    }
    if (musicnum <= 0 || musicnum >= 68) {
        I_Error(373906, [C2daVaArg(tag = 1, i64 = int64(musicnum), f64 = 0.0lf, raw = 0x0)])
    } else {
        music = 255744 + musicnum * 32
    }
    if (mus_playing == music) {
        return
    }
    S_StopMusic()
    if (int(uint(c2da_mem[music + 8]) | uint(c2da_mem[music + 9]) << 0x8 | uint(c2da_mem[music + 10]) << 0x10 | uint(c2da_mem[music + 11]) << 0x18) == 0) {
        M_snprintf(c2da_fp, 9ul, 373926, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[music]) | uint(c2da_mem[music + 1]) << 0x8 | uint(c2da_mem[music + 2]) << 0x10 | uint(c2da_mem[music + 3]) << 0x18)))])
        let c2da_fresh4 : int = W_GetNumForName(c2da_fp)
        let c2da_fresh5 : uint = uint(c2da_fresh4)
        c2da_mem[music + 8] = uint8(c2da_fresh5)
        c2da_mem[music + 9] = uint8(c2da_fresh5 >> 0x8)
        c2da_mem[music + 10] = uint8(c2da_fresh5 >> 0x10)
        c2da_mem[music + 11] = uint8(c2da_fresh5 >> 0x18)
    }
    let c2da_fresh6 : int = W_CacheLumpNum(int(uint(c2da_mem[music + 8]) | uint(c2da_mem[music + 9]) << 0x8 | uint(c2da_mem[music + 10]) << 0x10 | uint(c2da_mem[music + 11]) << 0x18), 1)
    let c2da_fresh7 : uint = uint(c2da_fresh6)
    c2da_mem[music + 16] = uint8(c2da_fresh7)
    c2da_mem[music + 17] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[music + 18] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[music + 19] = uint8(c2da_fresh7 >> 0x18)
    c2da_mem[music + 20] = 0u8
    c2da_mem[music + 21] = 0u8
    c2da_mem[music + 22] = 0u8
    c2da_mem[music + 23] = 0u8
    handle = I_RegisterSong(int(uint(c2da_mem[music + 16]) | uint(c2da_mem[music + 17]) << 0x8 | uint(c2da_mem[music + 18]) << 0x10 | uint(c2da_mem[music + 19]) << 0x18), W_LumpLength(uint(int(uint(c2da_mem[music + 8]) | uint(c2da_mem[music + 9]) << 0x8 | uint(c2da_mem[music + 10]) << 0x10 | uint(c2da_mem[music + 11]) << 0x18))))
    let c2da_fresh8 : uint = uint(handle)
    c2da_mem[music + 24] = uint8(c2da_fresh8)
    c2da_mem[music + 25] = uint8(c2da_fresh8 >> 0x8)
    c2da_mem[music + 26] = uint8(c2da_fresh8 >> 0x10)
    c2da_mem[music + 27] = uint8(c2da_fresh8 >> 0x18)
    c2da_mem[music + 28] = 0u8
    c2da_mem[music + 29] = 0u8
    c2da_mem[music + 30] = 0u8
    c2da_mem[music + 31] = 0u8
    I_PlaySong(handle, uint(looping))
    mus_playing = music
    return
}
[sideeffects]
def private S_StartSound_c2da_frame(var origin_p : int; var sfx_id : int; c2da_fp : int) {
    var sfx : int
    var origin : int
    var rc : int
    var cnum_1 : int
    origin = origin_p
    let c2da_fresh15 : uint = uint(snd_SfxVolume)
    c2da_mem[c2da_fp] = uint8(c2da_fresh15)
    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh15 >> 0x18)
    if (sfx_id < 1 || sfx_id > 109) {
        I_Error(373931, [C2daVaArg(tag = 1, i64 = int64(sfx_id), f64 = 0.0lf, raw = 0x0)])
    }
    sfx = 247536 + sfx_id * 64
    if (int(uint(c2da_mem[sfx + 24]) | uint(c2da_mem[sfx + 25]) << 0x8 | uint(c2da_mem[sfx + 26]) << 0x10 | uint(c2da_mem[sfx + 27]) << 0x18) != 0) {
        let c2da_fresh16 : int = int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) + int(uint(c2da_mem[sfx + 36]) | uint(c2da_mem[sfx + 37]) << 0x8 | uint(c2da_mem[sfx + 38]) << 0x10 | uint(c2da_mem[sfx + 39]) << 0x18)
        let c2da_fresh17 : uint = uint(c2da_fresh16)
        c2da_mem[c2da_fp] = uint8(c2da_fresh17)
        c2da_mem[c2da_fp + 1] = uint8(c2da_fresh17 >> 0x8)
        c2da_mem[c2da_fp + 2] = uint8(c2da_fresh17 >> 0x10)
        c2da_mem[c2da_fp + 3] = uint8(c2da_fresh17 >> 0x18)
        if (int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) < 1) {
            return
        }
        if (int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) > snd_SfxVolume) {
            let c2da_fresh18 : uint = uint(snd_SfxVolume)
            c2da_mem[c2da_fp] = uint8(c2da_fresh18)
            c2da_mem[c2da_fp + 1] = uint8(c2da_fresh18 >> 0x8)
            c2da_mem[c2da_fp + 2] = uint8(c2da_fresh18 >> 0x10)
            c2da_mem[c2da_fp + 3] = uint8(c2da_fresh18 >> 0x18)
        }
    }
    if (origin != 0 && origin != int(uint(c2da_mem[96 + int(consoleplayer) * 328]) | uint(c2da_mem[96 + int(consoleplayer) * 328 + 1]) << 0x8 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 2]) << 0x10 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 3]) << 0x18)) {
        rc = S_AdjustSoundParams(int(uint(c2da_mem[96 + int(consoleplayer) * 328]) | uint(c2da_mem[96 + int(consoleplayer) * 328 + 1]) << 0x8 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 2]) << 0x10 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 3]) << 0x18), origin, c2da_fp, c2da_fp + 16)
        let c2da_fresh19 : int = int(uint(c2da_mem[96 + int(consoleplayer) * 328]) | uint(c2da_mem[96 + int(consoleplayer) * 328 + 1]) << 0x8 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 2]) << 0x10 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 3]) << 0x18) + 24
        var c2da_fresh21 : int = 0
        if (int(uint(c2da_mem[origin + 24]) | uint(c2da_mem[origin + 25]) << 0x8 | uint(c2da_mem[origin + 26]) << 0x10 | uint(c2da_mem[origin + 27]) << 0x18) == int(uint(c2da_mem[c2da_fresh19]) | uint(c2da_mem[c2da_fresh19 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh19 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh19 + 3]) << 0x18)) {
            let c2da_fresh20 : int = int(uint(c2da_mem[96 + int(consoleplayer) * 328]) | uint(c2da_mem[96 + int(consoleplayer) * 328 + 1]) << 0x8 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 2]) << 0x10 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 3]) << 0x18) + 28
            if (int(uint(c2da_mem[origin + 28]) | uint(c2da_mem[origin + 29]) << 0x8 | uint(c2da_mem[origin + 30]) << 0x10 | uint(c2da_mem[origin + 31]) << 0x18) == int(uint(c2da_mem[c2da_fresh20]) | uint(c2da_mem[c2da_fresh20 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh20 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh20 + 3]) << 0x18)) {
                c2da_fresh21 = 1
            }
        }
        if (c2da_fresh21 != 0) {
            let c2da_fresh22 : int = 128
            let c2da_fresh23 : uint = uint(c2da_fresh22)
            c2da_mem[c2da_fp + 16] = uint8(c2da_fresh23)
            c2da_mem[c2da_fp + 17] = uint8(c2da_fresh23 >> 0x8)
            c2da_mem[c2da_fp + 18] = uint8(c2da_fresh23 >> 0x10)
            c2da_mem[c2da_fp + 19] = uint8(c2da_fresh23 >> 0x18)
        }
        if (rc == 0) {
            return
        }
    } else {
        let c2da_fresh24 : int = 128
        let c2da_fresh25 : uint = uint(c2da_fresh24)
        c2da_mem[c2da_fp + 16] = uint8(c2da_fresh25)
        c2da_mem[c2da_fp + 17] = uint8(c2da_fresh25 >> 0x8)
        c2da_mem[c2da_fp + 18] = uint8(c2da_fresh25 >> 0x10)
        c2da_mem[c2da_fp + 19] = uint8(c2da_fresh25 >> 0x18)
    }
    S_StopSound(origin)
    cnum_1 = S_GetChannel(origin, sfx)
    if (cnum_1 < 0) {
        return
    }
    let c2da_fresh26 : int = int(uint(c2da_mem[sfx + 40]) | uint(c2da_mem[sfx + 41]) << 0x8 | uint(c2da_mem[sfx + 42]) << 0x10 | uint(c2da_mem[sfx + 43]) << 0x18)
    let c2da_fresh27 : int = c2da_fresh26 + 1
    let c2da_fresh28 : uint = uint(c2da_fresh27)
    c2da_mem[sfx + 40] = uint8(c2da_fresh28)
    c2da_mem[sfx + 41] = uint8(c2da_fresh28 >> 0x8)
    c2da_mem[sfx + 42] = uint8(c2da_fresh28 >> 0x10)
    c2da_mem[sfx + 43] = uint8(c2da_fresh28 >> 0x18)
    if (c2da_fresh26 < 0) {
        let c2da_fresh29 : int = 1
        let c2da_fresh30 : uint = uint(c2da_fresh29)
        c2da_mem[sfx + 40] = uint8(c2da_fresh30)
        c2da_mem[sfx + 41] = uint8(c2da_fresh30 >> 0x8)
        c2da_mem[sfx + 42] = uint8(c2da_fresh30 >> 0x10)
        c2da_mem[sfx + 43] = uint8(c2da_fresh30 >> 0x18)
    }
    if (int(uint(c2da_mem[sfx + 44]) | uint(c2da_mem[sfx + 45]) << 0x8 | uint(c2da_mem[sfx + 46]) << 0x10 | uint(c2da_mem[sfx + 47]) << 0x18) < 0) {
        let c2da_fresh31 : int = I_GetSfxLumpNum(sfx)
        let c2da_fresh32 : uint = uint(c2da_fresh31)
        c2da_mem[sfx + 44] = uint8(c2da_fresh32)
        c2da_mem[sfx + 45] = uint8(c2da_fresh32 >> 0x8)
        c2da_mem[sfx + 46] = uint8(c2da_fresh32 >> 0x10)
        c2da_mem[sfx + 47] = uint8(c2da_fresh32 >> 0x18)
    }
    let c2da_fresh33 : int = I_StartSound(sfx, cnum_1, int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18), int(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18))
    let c2da_fresh34 : uint = uint(c2da_fresh33)
    c2da_mem[channels + cnum_1 * 24 + 16] = uint8(c2da_fresh34)
    c2da_mem[channels + cnum_1 * 24 + 17] = uint8(c2da_fresh34 >> 0x8)
    c2da_mem[channels + cnum_1 * 24 + 18] = uint8(c2da_fresh34 >> 0x10)
    c2da_mem[channels + cnum_1 * 24 + 19] = uint8(c2da_fresh34 >> 0x18)
    return
}
[sideeffects]
def private S_UpdateSounds_c2da_frame(var listener_0 : int; c2da_fp : int) {
    var audible : int
    var cnum_4 : int
    var sfx_0 : int
    var c_1 : int
    I_UpdateSound()
    cnum_4 = 0
    while (cnum_4 < int(uint(c2da_mem[1920]) | uint(c2da_mem[1921]) << 0x8 | uint(c2da_mem[1922]) << 0x10 | uint(c2da_mem[1923]) << 0x18)) {
        c_1 = channels + cnum_4 * 24
        sfx_0 = int(uint(c2da_mem[c_1]) | uint(c2da_mem[c_1 + 1]) << 0x8 | uint(c2da_mem[c_1 + 2]) << 0x10 | uint(c2da_mem[c_1 + 3]) << 0x18)
        if (int(uint(c2da_mem[c_1]) | uint(c2da_mem[c_1 + 1]) << 0x8 | uint(c2da_mem[c_1 + 2]) << 0x10 | uint(c2da_mem[c_1 + 3]) << 0x18) != 0) {
            if (I_SoundIsPlaying(int(uint(c2da_mem[c_1 + 16]) | uint(c2da_mem[c_1 + 17]) << 0x8 | uint(c2da_mem[c_1 + 18]) << 0x10 | uint(c2da_mem[c_1 + 19]) << 0x18)) != 0x0) {
                let c2da_fresh45 : uint = uint(snd_SfxVolume)
                c2da_mem[c2da_fp] = uint8(c2da_fresh45)
                c2da_mem[c2da_fp + 1] = uint8(c2da_fresh45 >> 0x8)
                c2da_mem[c2da_fp + 2] = uint8(c2da_fresh45 >> 0x10)
                c2da_mem[c2da_fp + 3] = uint8(c2da_fresh45 >> 0x18)
                let c2da_fresh46 : int = 128
                let c2da_fresh47 : uint = uint(c2da_fresh46)
                c2da_mem[c2da_fp + 16] = uint8(c2da_fresh47)
                c2da_mem[c2da_fp + 17] = uint8(c2da_fresh47 >> 0x8)
                c2da_mem[c2da_fp + 18] = uint8(c2da_fresh47 >> 0x10)
                c2da_mem[c2da_fp + 19] = uint8(c2da_fresh47 >> 0x18)
                if (int(uint(c2da_mem[sfx_0 + 24]) | uint(c2da_mem[sfx_0 + 25]) << 0x8 | uint(c2da_mem[sfx_0 + 26]) << 0x10 | uint(c2da_mem[sfx_0 + 27]) << 0x18) != 0) {
                    let c2da_fresh48 : int = int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) + int(uint(c2da_mem[sfx_0 + 36]) | uint(c2da_mem[sfx_0 + 37]) << 0x8 | uint(c2da_mem[sfx_0 + 38]) << 0x10 | uint(c2da_mem[sfx_0 + 39]) << 0x18)
                    let c2da_fresh49 : uint = uint(c2da_fresh48)
                    c2da_mem[c2da_fp] = uint8(c2da_fresh49)
                    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh49 >> 0x8)
                    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh49 >> 0x10)
                    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh49 >> 0x18)
                    if (int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) < 1) {
                        S_StopChannel(cnum_4)
                        cnum_4++
                        continue
                    } elif (int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) > snd_SfxVolume) {
                        let c2da_fresh50 : uint = uint(snd_SfxVolume)
                        c2da_mem[c2da_fp] = uint8(c2da_fresh50)
                        c2da_mem[c2da_fp + 1] = uint8(c2da_fresh50 >> 0x8)
                        c2da_mem[c2da_fp + 2] = uint8(c2da_fresh50 >> 0x10)
                        c2da_mem[c2da_fp + 3] = uint8(c2da_fresh50 >> 0x18)
                    }
                }
                if (int(uint(c2da_mem[c_1 + 8]) | uint(c2da_mem[c_1 + 9]) << 0x8 | uint(c2da_mem[c_1 + 10]) << 0x10 | uint(c2da_mem[c_1 + 11]) << 0x18) != 0 && listener_0 != int(uint(c2da_mem[c_1 + 8]) | uint(c2da_mem[c_1 + 9]) << 0x8 | uint(c2da_mem[c_1 + 10]) << 0x10 | uint(c2da_mem[c_1 + 11]) << 0x18)) {
                    audible = S_AdjustSoundParams(listener_0, int(uint(c2da_mem[c_1 + 8]) | uint(c2da_mem[c_1 + 9]) << 0x8 | uint(c2da_mem[c_1 + 10]) << 0x10 | uint(c2da_mem[c_1 + 11]) << 0x18), c2da_fp, c2da_fp + 16)
                    if (audible == 0) {
                        S_StopChannel(cnum_4)
                    } else {
                        I_UpdateSoundParams(int(uint(c2da_mem[c_1 + 16]) | uint(c2da_mem[c_1 + 17]) << 0x8 | uint(c2da_mem[c_1 + 18]) << 0x10 | uint(c2da_mem[c_1 + 19]) << 0x18), int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18), int(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18))
                    }
                }
            } else {
                S_StopChannel(cnum_4)
            }
        }
        cnum_4++
    }
    return
}

// This unit's static data, at heap offset 373840.
let private c2da_lin_static_s_sound_seg = fixed_array<int>(373840, 104)
let private c2da_lin_static_s_sound = fixed_array<uint64>(0x2074706d65747441ul, 0x6d20746573206f74ul, 0x6c6f762063697375ul, 0x2520746120656d75ul, 0x706d657474410064ul, 0x746573206f742074ul, 0x6c6f762078667320ul, 0x2520746120656d75ul, 0x756d206461420064ul, 0x626d756e20636973ul, 0x5f64006425207265ul, 0x7320646142007325ul, 0x6425203a23207866ul)

[init]
def private c2da_lin_init_static_s_sound() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_s_sound_seg[s * 2]
        for (k in range(c2da_lin_static_s_sound_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_s_sound[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_s_sound_0 = fixed_array<uint8>(0x8, 0x0, 0x0, 0x0)
let private c2da_lin_extern_s_sound_1 = fixed_array<uint8>(0x8, 0x0, 0x0, 0x0)
let private c2da_lin_extern_s_sound_2 = fixed_array<uint8>(0x8, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_s_sound() {
    c2da_lin_setup()
    for (i in range(4)) {
        c2da_mem[1840 + i] = c2da_lin_extern_s_sound_0[i]
    }
    for (i in range(4)) {
        c2da_mem[1856 + i] = c2da_lin_extern_s_sound_1[i]
    }
    for (i in range(4)) {
        c2da_mem[1920 + i] = c2da_lin_extern_s_sound_2[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_s_sound() {
    if (length(c2da_fn_table0) < 153) {
        resize(c2da_fn_table0, 153)
    }
    c2da_fn_table0[152] = @@S_Shutdown
}

[init]
def private c2da_lin_relink_init_s_sound() {
    c2da_relink_s_sound()
}
