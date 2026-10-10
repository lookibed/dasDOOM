var private c2da_str_s_sound_0 : array<int8> = [int8(65), int8(116), int8(116), int8(101), int8(109), int8(112), int8(116), int8(32), int8(116), int8(111), int8(32), int8(115), int8(101), int8(116), int8(32), int8(109), int8(117), int8(115), int8(105), int8(99), int8(32), int8(118), int8(111), int8(108), int8(117), int8(109), int8(101), int8(32), int8(97), int8(116), int8(32), int8(37), int8(100), int8(0)]

var private c2da_str_s_sound_1 : array<int8> = [int8(65), int8(116), int8(116), int8(101), int8(109), int8(112), int8(116), int8(32), int8(116), int8(111), int8(32), int8(115), int8(101), int8(116), int8(32), int8(115), int8(102), int8(120), int8(32), int8(118), int8(111), int8(108), int8(117), int8(109), int8(101), int8(32), int8(97), int8(116), int8(32), int8(37), int8(100), int8(0)]

var private c2da_str_s_sound_2 : array<int8> = [int8(66), int8(97), int8(100), int8(32), int8(109), int8(117), int8(115), int8(105), int8(99), int8(32), int8(110), int8(117), int8(109), int8(98), int8(101), int8(114), int8(32), int8(37), int8(100), int8(0)]

var private c2da_str_s_sound_3 : array<int8> = [int8(100), int8(95), int8(37), int8(115), int8(0)]

var private c2da_str_s_sound_4 : array<int8> = [int8(66), int8(97), int8(100), int8(32), int8(115), int8(102), int8(120), int8(32), int8(35), int8(58), int8(32), int8(37), int8(100), int8(0)]

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
var sfxVolume : int = 8

var musicVolume : int = 8

[export, sideeffects]
def S_Init(var sfxVolume_0 : int; var musicVolume_0 : int) {
    var i : int
    I_PrecacheSounds(unsafe(addr<sfxinfo_struct?>(S_sfx[0])), 109)
    S_SetSfxVolume(sfxVolume_0)
    S_SetMusicVolume(musicVolume_0)
    channels = unsafe(reinterpret<channel_t?>(unsafe(reinterpret<channel_t?>(Z_Malloc(int(uint64(snd_channels) * 24ul), 1, null)))))
    i = 0
    while (i < snd_channels) {
        unsafe(channels[i]).sfxinfo = null
        i++
    }
    mus_paused = 0u
    i = 1
    for (c2da_i in range(i, 109)) {
        unsafe(unsafe(addr(S_sfx[0]))[c2da_i]).usefulness = -1
        unsafe(unsafe(addr(S_sfx[0]))[c2da_i]).lumpnum = unsafe(unsafe(addr(S_sfx[0]))[c2da_i]).usefulness
    }
    I_AtExit(@@S_Shutdown, 1u)
    return
}
[export, sideeffects]
def S_Shutdown() {
    I_ShutdownSound()
    I_ShutdownMusic()
    return
}
var private mus_paused : uint = default<uint>

var private channels : channel_t? = default<channel_t?>

var snd_channels : int = 8

[export, sideeffects]
def S_SetMusicVolume(var volume : int) {
    if (volume < 0 || volume > 127) {
        I_Error(unsafe(addr<int8?>(c2da_str_s_sound_0[0])), [C2daVaArg(tag = 1, i64 = int64(volume), f64 = 0.0lf, raw = 0x0)])
    }
    I_SetMusicVolume(volume)
    return
}
[export, sideeffects]
def S_SetSfxVolume(var volume_0 : int) {
    if (volume_0 < 0 || volume_0 > 127) {
        I_Error(unsafe(addr<int8?>(c2da_str_s_sound_1[0])), [C2daVaArg(tag = 1, i64 = int64(volume_0), f64 = 0.0lf, raw = 0x0)])
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
    while (cnum < snd_channels) {
        if (unsafe(channels[cnum]).sfxinfo != null) {
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
    var music : musicinfo_t?
    var namebuf : int8[9]
    var handle : uint8?
    music = null
    if (musicnum == 29 && (snd_musicdevice == 2 || snd_musicdevice == 3)) {
        musicnum = 32
    }
    if (musicnum <= 0 || musicnum >= 68) {
        I_Error(unsafe(addr<int8?>(c2da_str_s_sound_2[0])), [C2daVaArg(tag = 1, i64 = int64(musicnum), f64 = 0.0lf, raw = 0x0)])
    } else {
        music = unsafe(addr<musicinfo_t?>(unsafe(unsafe(addr(S_music[0]))[musicnum])))
    }
    if (mus_playing == music) {
        return
    }
    S_StopMusic()
    if (music.lumpnum == 0) {
        M_snprintf(unsafe(addr<int8?>(namebuf[0])), 9ul, unsafe(addr<int8 const?>(c2da_str_s_sound_3[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(music.name)))])
        music.lumpnum = W_GetNumForName(unsafe(addr<int8?>(namebuf[0])))
    }
    music.data = unsafe(reinterpret<uint8?>(W_CacheLumpNum(music.lumpnum, 1)))
    handle = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(I_RegisterSong(music.data, W_LumpLength(uint(music.lumpnum)))))))
    music.handle = handle
    I_PlaySong(handle, uint(looping))
    mus_playing = unsafe(reinterpret<musicinfo_t?>(music))
    return
}
var private mus_playing : musicinfo_t? = null

[export, sideeffects]
def S_StopMusic() {
    if (mus_playing != null) {
        if (mus_paused != 0x0) {
            I_ResumeSong()
        }
        I_StopSong()
        I_UnRegisterSong(mus_playing.handle)
        W_ReleaseLumpNum(mus_playing.lumpnum)
        mus_playing.data = null
        mus_playing = null
    }
    return
}
[sideeffects]
def private S_StopChannel(var cnum_0 : int) {
    var i_0 : int
    var c : channel_t? = unsafe(addr<channel_t?>(unsafe(channels[cnum_0])))
    if (c.sfxinfo != null) {
        if (I_SoundIsPlaying(c.handle) != 0x0) {
            I_StopSound(c.handle)
        }
        i_0 = 0
        while (i_0 < snd_channels) {
            if (cnum_0 != i_0 && c.sfxinfo == unsafe(channels[i_0]).sfxinfo) {
                break
            }
            i_0++
        }
        let c2da_postinc : int = c.sfxinfo.usefulness
        c.sfxinfo.usefulness = c2da_postinc - 1
        c.sfxinfo = null
    }
    return
}
[export, sideeffects]
def S_StartSound(var origin_p : uint8?; var sfx_id : int) {
    var sfx : sfxinfo_struct?
    var origin : mobj_s?
    var rc : int
    var sep : int
    var cnum_1 : int
    var volume_1 : int
    origin = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(origin_p))))
    volume_1 = snd_SfxVolume
    if (sfx_id < 1 || sfx_id > 109) {
        I_Error(unsafe(addr<int8?>(c2da_str_s_sound_4[0])), [C2daVaArg(tag = 1, i64 = int64(sfx_id), f64 = 0.0lf, raw = 0x0)])
    }
    sfx = unsafe(addr<sfxinfo_struct?>(unsafe(unsafe(addr(S_sfx[0]))[sfx_id])))
    if (sfx.link != null) {
        volume_1 += sfx.volume
        if (volume_1 < 1) {
            return
        }
        if (volume_1 > snd_SfxVolume) {
            volume_1 = snd_SfxVolume
        }
    }
    if (origin != null && origin != players[int(consoleplayer)].mo) {
        rc = S_AdjustSoundParams(players[int(consoleplayer)].mo, origin, unsafe(addr<int?>(volume_1)), unsafe(addr<int?>(sep)))
        if (origin.x == players[int(consoleplayer)].mo.x && origin.y == players[int(consoleplayer)].mo.y) {
            sep = 128
        }
        if (rc == 0) {
            return
        }
    } else {
        sep = 128
    }
    S_StopSound(origin)
    cnum_1 = S_GetChannel(origin, sfx)
    if (cnum_1 < 0) {
        return
    }
    let c2da_postinc_0 : int = sfx.usefulness
    sfx.usefulness = c2da_postinc_0 + 1
    if (c2da_postinc_0 < 0) {
        sfx.usefulness = 1
    }
    if (sfx.lumpnum < 0) {
        sfx.lumpnum = I_GetSfxLumpNum(sfx)
    }
    unsafe(channels[cnum_1]).handle = I_StartSound(sfx, cnum_1, volume_1, sep)
    return
}
[sideeffects]
def private S_GetChannel(var origin_0 : mobj_s?; var sfxinfo : sfxinfo_struct?) : int {
    var cnum_2 : int
    var c_0 : channel_t?
    cnum_2 = 0
    while (cnum_2 < snd_channels) {
        if (unsafe(channels[cnum_2]).sfxinfo == null) {
            break
        } elif (origin_0 != null && unsafe(channels[cnum_2]).origin == origin_0) {
            S_StopChannel(cnum_2)
            break
        }
        cnum_2++
    }
    if (cnum_2 == snd_channels) {
        cnum_2 = 0
        while (cnum_2 < snd_channels) {
            if (unsafe(channels[cnum_2]).sfxinfo.priority >= sfxinfo.priority) {
                break
            }
            cnum_2++
        }
        if (cnum_2 == snd_channels) {
            return -1
        } else {
            S_StopChannel(cnum_2)
        }
    }
    c_0 = unsafe(addr<channel_t?>(unsafe(channels[cnum_2])))
    c_0.sfxinfo = sfxinfo
    c_0.origin = origin_0
    return cnum_2
}
[export, sideeffects]
def S_StopSound(var origin_1 : mobj_s?) {
    var cnum_3 : int = 0
    while (cnum_3 < snd_channels) {
        if (unsafe(channels[cnum_3]).sfxinfo != null && unsafe(channels[cnum_3]).origin == origin_1) {
            S_StopChannel(cnum_3)
            break
        }
        cnum_3++
    }
    return
}
[sideeffects]
def private S_AdjustSoundParams(var listener : mobj_s?; var source : mobj_s?; var vol : int?; var sep_0 : int?) : int {
    var approx_dist : int
    var adx : int
    var ady : int
    var angle : uint
    adx = c2da_std_abs(listener.x - source.x)
    ady = c2da_std_abs(listener.y - source.y)
    approx_dist = adx + ady - ((adx < ady ? adx : ady) >> 1)
    if (gamemap != 8 && approx_dist > 1200 * (1 << 16)) {
        return 0
    }
    angle = uint(R_PointToAngle2(listener.x, listener.y, source.x, source.y))
    if (angle > listener.angle) {
        angle -= listener.angle
    } else {
        angle += 0xffffffffu - listener.angle
    }
    angle >>= 19u
    *sep_0 = 128 - (FixedMul(96 * (1 << 16), finesine[int(angle)]) >> 16)
    if (approx_dist < 200 * (1 << 16)) {
        *vol = int(snd_SfxVolume)  // nolint:PERF020
    } elif (gamemap == 8) {
        if (approx_dist > 1200 * (1 << 16)) {
            approx_dist = 1200 * (1 << 16)
        }
        *vol = 15 + (snd_SfxVolume - 15) * (1200 * (1 << 16) - approx_dist >> 16) / (1200 * (1 << 16) - 200 * (1 << 16) >> 16)
    } else {
        *vol = snd_SfxVolume * (1200 * (1 << 16) - approx_dist >> 16) / (1200 * (1 << 16) - 200 * (1 << 16) >> 16)
    }
    return *vol > 0 ? 1 : 0
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
    if (mus_playing != null && mus_paused == 0) {
        I_PauseSong()
        mus_paused = 1u
    }
    return
}
[export, sideeffects]
def S_ResumeSound() {
    if (mus_playing != null && mus_paused != 0x0) {
        I_ResumeSong()
        mus_paused = 0u
    }
    return
}
[export, sideeffects]
def S_UpdateSounds(var listener_0 : mobj_s?) {
    var audible : int
    var cnum_4 : int
    var volume_2 : int
    var sep_1 : int
    var sfx_0 : sfxinfo_struct?
    var c_1 : channel_t?
    I_UpdateSound()
    cnum_4 = 0
    while (cnum_4 < snd_channels) {
        c_1 = unsafe(addr<channel_t?>(unsafe(channels[cnum_4])))
        sfx_0 = unsafe(reinterpret<sfxinfo_struct?>(c_1.sfxinfo))
        if (c_1.sfxinfo != null) {
            if (I_SoundIsPlaying(c_1.handle) != 0x0) {
                volume_2 = snd_SfxVolume
                sep_1 = 128
                if (sfx_0.link != null) {
                    volume_2 += sfx_0.volume
                    if (volume_2 < 1) {
                        S_StopChannel(cnum_4)
                        cnum_4++
                        continue
                    } elif (volume_2 > snd_SfxVolume) {
                        volume_2 = snd_SfxVolume
                    }
                }
                if (c_1.origin != null && listener_0 != c_1.origin) {
                    audible = S_AdjustSoundParams(listener_0, c_1.origin, unsafe(addr<int?>(volume_2)), unsafe(addr<int?>(sep_1)))
                    if (audible == 0) {
                        S_StopChannel(cnum_4)
                    } else {
                        I_UpdateSoundParams(c_1.handle, volume_2, sep_1)
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
[sideeffects]
def private c2da_layout_proofs_37() {
    static_assert(typeinfo sizeof(type<sfxinfo_struct>) == 64, "C layout of sfxinfo_struct: sizeof")
    static_assert(typeinfo alignof(type<sfxinfo_struct>) == 8, "C layout of sfxinfo_struct: alignof")
    static_assert(typeinfo offsetof<tagname>(type<sfxinfo_struct>) == 0, "C layout of sfxinfo_struct: offsetof tagname")
    static_assert(typeinfo offsetof<name>(type<sfxinfo_struct>) == 8, "C layout of sfxinfo_struct: offsetof name")
    static_assert(typeinfo offsetof<priority>(type<sfxinfo_struct>) == 20, "C layout of sfxinfo_struct: offsetof priority")
    static_assert(typeinfo offsetof<link>(type<sfxinfo_struct>) == 24, "C layout of sfxinfo_struct: offsetof link")
    static_assert(typeinfo offsetof<pitch>(type<sfxinfo_struct>) == 32, "C layout of sfxinfo_struct: offsetof pitch")
    static_assert(typeinfo offsetof<volume>(type<sfxinfo_struct>) == 36, "C layout of sfxinfo_struct: offsetof volume")
    static_assert(typeinfo offsetof<usefulness>(type<sfxinfo_struct>) == 40, "C layout of sfxinfo_struct: offsetof usefulness")
    static_assert(typeinfo offsetof<lumpnum>(type<sfxinfo_struct>) == 44, "C layout of sfxinfo_struct: offsetof lumpnum")
    static_assert(typeinfo offsetof<numchannels>(type<sfxinfo_struct>) == 48, "C layout of sfxinfo_struct: offsetof numchannels")
    static_assert(typeinfo offsetof<driver_data>(type<sfxinfo_struct>) == 56, "C layout of sfxinfo_struct: offsetof driver_data")
    static_assert(typeinfo sizeof(type<sfxinfo_t>) == 64, "C layout of sfxinfo_t: sizeof")
    static_assert(typeinfo alignof(type<sfxinfo_t>) == 8, "C layout of sfxinfo_t: alignof")
    static_assert(typeinfo offsetof<tagname>(type<sfxinfo_t>) == 0, "C layout of sfxinfo_t: offsetof tagname")
    static_assert(typeinfo offsetof<name>(type<sfxinfo_t>) == 8, "C layout of sfxinfo_t: offsetof name")
    static_assert(typeinfo offsetof<priority>(type<sfxinfo_t>) == 20, "C layout of sfxinfo_t: offsetof priority")
    static_assert(typeinfo offsetof<link>(type<sfxinfo_t>) == 24, "C layout of sfxinfo_t: offsetof link")
    static_assert(typeinfo offsetof<pitch>(type<sfxinfo_t>) == 32, "C layout of sfxinfo_t: offsetof pitch")
    static_assert(typeinfo offsetof<volume>(type<sfxinfo_t>) == 36, "C layout of sfxinfo_t: offsetof volume")
    static_assert(typeinfo offsetof<usefulness>(type<sfxinfo_t>) == 40, "C layout of sfxinfo_t: offsetof usefulness")
    static_assert(typeinfo offsetof<lumpnum>(type<sfxinfo_t>) == 44, "C layout of sfxinfo_t: offsetof lumpnum")
    static_assert(typeinfo offsetof<numchannels>(type<sfxinfo_t>) == 48, "C layout of sfxinfo_t: offsetof numchannels")
    static_assert(typeinfo offsetof<driver_data>(type<sfxinfo_t>) == 56, "C layout of sfxinfo_t: offsetof driver_data")
    static_assert(typeinfo sizeof(type<musicinfo_t>) == 32, "C layout of musicinfo_t: sizeof")
    static_assert(typeinfo alignof(type<musicinfo_t>) == 8, "C layout of musicinfo_t: alignof")
    static_assert(typeinfo offsetof<name>(type<musicinfo_t>) == 0, "C layout of musicinfo_t: offsetof name")
    static_assert(typeinfo offsetof<lumpnum>(type<musicinfo_t>) == 8, "C layout of musicinfo_t: offsetof lumpnum")
    static_assert(typeinfo offsetof<data>(type<musicinfo_t>) == 16, "C layout of musicinfo_t: offsetof data")
    static_assert(typeinfo offsetof<handle>(type<musicinfo_t>) == 24, "C layout of musicinfo_t: offsetof handle")
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
    static_assert(typeinfo sizeof(type<thinker_s>) == 24, "C layout of thinker_s: sizeof")
    static_assert(typeinfo alignof(type<thinker_s>) == 8, "C layout of thinker_s: alignof")
    static_assert(typeinfo offsetof<prev>(type<thinker_s>) == 0, "C layout of thinker_s: offsetof prev")
    static_assert(typeinfo offsetof<next>(type<thinker_s>) == 8, "C layout of thinker_s: offsetof next")
    static_assert(typeinfo offsetof<function_0>(type<thinker_s>) == 16, "C layout of thinker_s: offsetof function_0")
    static_assert(typeinfo sizeof(type<thinker_t>) == 24, "C layout of thinker_t: sizeof")
    static_assert(typeinfo alignof(type<thinker_t>) == 8, "C layout of thinker_t: alignof")
    static_assert(typeinfo offsetof<prev>(type<thinker_t>) == 0, "C layout of thinker_t: offsetof prev")
    static_assert(typeinfo offsetof<next>(type<thinker_t>) == 8, "C layout of thinker_t: offsetof next")
    static_assert(typeinfo offsetof<function_0>(type<thinker_t>) == 16, "C layout of thinker_t: offsetof function_0")
    static_assert(typeinfo sizeof(type<state_t>) == 40, "C layout of state_t: sizeof")
    static_assert(typeinfo alignof(type<state_t>) == 8, "C layout of state_t: alignof")
    static_assert(typeinfo offsetof<sprite>(type<state_t>) == 0, "C layout of state_t: offsetof sprite")
    static_assert(typeinfo offsetof<frame>(type<state_t>) == 4, "C layout of state_t: offsetof frame")
    static_assert(typeinfo offsetof<tics>(type<state_t>) == 8, "C layout of state_t: offsetof tics")
    static_assert(typeinfo offsetof<action>(type<state_t>) == 16, "C layout of state_t: offsetof action")
    static_assert(typeinfo offsetof<nextstate>(type<state_t>) == 24, "C layout of state_t: offsetof nextstate")
    static_assert(typeinfo offsetof<misc1>(type<state_t>) == 28, "C layout of state_t: offsetof misc1")
    static_assert(typeinfo offsetof<misc2>(type<state_t>) == 32, "C layout of state_t: offsetof misc2")
    static_assert(typeinfo sizeof(type<mobjinfo_t>) == 92, "C layout of mobjinfo_t: sizeof")
    static_assert(typeinfo alignof(type<mobjinfo_t>) == 4, "C layout of mobjinfo_t: alignof")
    static_assert(typeinfo offsetof<doomednum>(type<mobjinfo_t>) == 0, "C layout of mobjinfo_t: offsetof doomednum")
    static_assert(typeinfo offsetof<spawnstate>(type<mobjinfo_t>) == 4, "C layout of mobjinfo_t: offsetof spawnstate")
    static_assert(typeinfo offsetof<spawnhealth>(type<mobjinfo_t>) == 8, "C layout of mobjinfo_t: offsetof spawnhealth")
    static_assert(typeinfo offsetof<seestate>(type<mobjinfo_t>) == 12, "C layout of mobjinfo_t: offsetof seestate")
    static_assert(typeinfo offsetof<seesound>(type<mobjinfo_t>) == 16, "C layout of mobjinfo_t: offsetof seesound")
    static_assert(typeinfo offsetof<reactiontime>(type<mobjinfo_t>) == 20, "C layout of mobjinfo_t: offsetof reactiontime")
    static_assert(typeinfo offsetof<attacksound>(type<mobjinfo_t>) == 24, "C layout of mobjinfo_t: offsetof attacksound")
    static_assert(typeinfo offsetof<painstate>(type<mobjinfo_t>) == 28, "C layout of mobjinfo_t: offsetof painstate")
    static_assert(typeinfo offsetof<painchance>(type<mobjinfo_t>) == 32, "C layout of mobjinfo_t: offsetof painchance")
    static_assert(typeinfo offsetof<painsound>(type<mobjinfo_t>) == 36, "C layout of mobjinfo_t: offsetof painsound")
    static_assert(typeinfo offsetof<meleestate>(type<mobjinfo_t>) == 40, "C layout of mobjinfo_t: offsetof meleestate")
    static_assert(typeinfo offsetof<missilestate>(type<mobjinfo_t>) == 44, "C layout of mobjinfo_t: offsetof missilestate")
    static_assert(typeinfo offsetof<deathstate>(type<mobjinfo_t>) == 48, "C layout of mobjinfo_t: offsetof deathstate")
    static_assert(typeinfo offsetof<xdeathstate>(type<mobjinfo_t>) == 52, "C layout of mobjinfo_t: offsetof xdeathstate")
    static_assert(typeinfo offsetof<deathsound>(type<mobjinfo_t>) == 56, "C layout of mobjinfo_t: offsetof deathsound")
    static_assert(typeinfo offsetof<speed>(type<mobjinfo_t>) == 60, "C layout of mobjinfo_t: offsetof speed")
    static_assert(typeinfo offsetof<radius>(type<mobjinfo_t>) == 64, "C layout of mobjinfo_t: offsetof radius")
    static_assert(typeinfo offsetof<height>(type<mobjinfo_t>) == 68, "C layout of mobjinfo_t: offsetof height")
    static_assert(typeinfo offsetof<mass>(type<mobjinfo_t>) == 72, "C layout of mobjinfo_t: offsetof mass")
    static_assert(typeinfo offsetof<damage>(type<mobjinfo_t>) == 76, "C layout of mobjinfo_t: offsetof damage")
    static_assert(typeinfo offsetof<activesound>(type<mobjinfo_t>) == 80, "C layout of mobjinfo_t: offsetof activesound")
    static_assert(typeinfo offsetof<flags>(type<mobjinfo_t>) == 84, "C layout of mobjinfo_t: offsetof flags")
    static_assert(typeinfo offsetof<raisestate>(type<mobjinfo_t>) == 88, "C layout of mobjinfo_t: offsetof raisestate")
    static_assert(typeinfo sizeof(type<pspdef_t>) == 24, "C layout of pspdef_t: sizeof")
    static_assert(typeinfo alignof(type<pspdef_t>) == 8, "C layout of pspdef_t: alignof")
    static_assert(typeinfo offsetof<state>(type<pspdef_t>) == 0, "C layout of pspdef_t: offsetof state")
    static_assert(typeinfo offsetof<tics>(type<pspdef_t>) == 8, "C layout of pspdef_t: offsetof tics")
    static_assert(typeinfo offsetof<sx>(type<pspdef_t>) == 12, "C layout of pspdef_t: offsetof sx")
    static_assert(typeinfo offsetof<sy>(type<pspdef_t>) == 16, "C layout of pspdef_t: offsetof sy")
    static_assert(typeinfo sizeof(type<mobj_s>) == 224, "C layout of mobj_s: sizeof")
    static_assert(typeinfo alignof(type<mobj_s>) == 8, "C layout of mobj_s: alignof")
    static_assert(typeinfo offsetof<thinker>(type<mobj_s>) == 0, "C layout of mobj_s: offsetof thinker")
    static_assert(typeinfo offsetof<x>(type<mobj_s>) == 24, "C layout of mobj_s: offsetof x")
    static_assert(typeinfo offsetof<y>(type<mobj_s>) == 28, "C layout of mobj_s: offsetof y")
    static_assert(typeinfo offsetof<z>(type<mobj_s>) == 32, "C layout of mobj_s: offsetof z")
    static_assert(typeinfo offsetof<snext>(type<mobj_s>) == 40, "C layout of mobj_s: offsetof snext")
    static_assert(typeinfo offsetof<sprev>(type<mobj_s>) == 48, "C layout of mobj_s: offsetof sprev")
    static_assert(typeinfo offsetof<angle>(type<mobj_s>) == 56, "C layout of mobj_s: offsetof angle")
    static_assert(typeinfo offsetof<sprite>(type<mobj_s>) == 60, "C layout of mobj_s: offsetof sprite")
    static_assert(typeinfo offsetof<frame>(type<mobj_s>) == 64, "C layout of mobj_s: offsetof frame")
    static_assert(typeinfo offsetof<bnext>(type<mobj_s>) == 72, "C layout of mobj_s: offsetof bnext")
    static_assert(typeinfo offsetof<bprev>(type<mobj_s>) == 80, "C layout of mobj_s: offsetof bprev")
    static_assert(typeinfo offsetof<subsector>(type<mobj_s>) == 88, "C layout of mobj_s: offsetof subsector")
    static_assert(typeinfo offsetof<floorz>(type<mobj_s>) == 96, "C layout of mobj_s: offsetof floorz")
    static_assert(typeinfo offsetof<ceilingz>(type<mobj_s>) == 100, "C layout of mobj_s: offsetof ceilingz")
    static_assert(typeinfo offsetof<radius>(type<mobj_s>) == 104, "C layout of mobj_s: offsetof radius")
    static_assert(typeinfo offsetof<height>(type<mobj_s>) == 108, "C layout of mobj_s: offsetof height")
    static_assert(typeinfo offsetof<momx>(type<mobj_s>) == 112, "C layout of mobj_s: offsetof momx")
    static_assert(typeinfo offsetof<momy>(type<mobj_s>) == 116, "C layout of mobj_s: offsetof momy")
    static_assert(typeinfo offsetof<momz>(type<mobj_s>) == 120, "C layout of mobj_s: offsetof momz")
    static_assert(typeinfo offsetof<validcount>(type<mobj_s>) == 124, "C layout of mobj_s: offsetof validcount")
    static_assert(typeinfo offsetof<type_0>(type<mobj_s>) == 128, "C layout of mobj_s: offsetof type_0")
    static_assert(typeinfo offsetof<info>(type<mobj_s>) == 136, "C layout of mobj_s: offsetof info")
    static_assert(typeinfo offsetof<tics>(type<mobj_s>) == 144, "C layout of mobj_s: offsetof tics")
    static_assert(typeinfo offsetof<state>(type<mobj_s>) == 152, "C layout of mobj_s: offsetof state")
    static_assert(typeinfo offsetof<flags>(type<mobj_s>) == 160, "C layout of mobj_s: offsetof flags")
    static_assert(typeinfo offsetof<health>(type<mobj_s>) == 164, "C layout of mobj_s: offsetof health")
    static_assert(typeinfo offsetof<movedir>(type<mobj_s>) == 168, "C layout of mobj_s: offsetof movedir")
    static_assert(typeinfo offsetof<movecount>(type<mobj_s>) == 172, "C layout of mobj_s: offsetof movecount")
    static_assert(typeinfo offsetof<target>(type<mobj_s>) == 176, "C layout of mobj_s: offsetof target")
    static_assert(typeinfo offsetof<reactiontime>(type<mobj_s>) == 184, "C layout of mobj_s: offsetof reactiontime")
    static_assert(typeinfo offsetof<threshold>(type<mobj_s>) == 188, "C layout of mobj_s: offsetof threshold")
    static_assert(typeinfo offsetof<player>(type<mobj_s>) == 192, "C layout of mobj_s: offsetof player")
    static_assert(typeinfo offsetof<lastlook>(type<mobj_s>) == 200, "C layout of mobj_s: offsetof lastlook")
    static_assert(typeinfo offsetof<spawnpoint>(type<mobj_s>) == 204, "C layout of mobj_s: offsetof spawnpoint")
    static_assert(typeinfo offsetof<tracer>(type<mobj_s>) == 216, "C layout of mobj_s: offsetof tracer")
    static_assert(typeinfo sizeof(type<player_s>) == 328, "C layout of player_s: sizeof")
    static_assert(typeinfo alignof(type<player_s>) == 8, "C layout of player_s: alignof")
    static_assert(typeinfo offsetof<mo>(type<player_s>) == 0, "C layout of player_s: offsetof mo")
    static_assert(typeinfo offsetof<playerstate>(type<player_s>) == 8, "C layout of player_s: offsetof playerstate")
    static_assert(typeinfo offsetof<cmd>(type<player_s>) == 12, "C layout of player_s: offsetof cmd")
    static_assert(typeinfo offsetof<viewz>(type<player_s>) == 28, "C layout of player_s: offsetof viewz")
    static_assert(typeinfo offsetof<viewheight>(type<player_s>) == 32, "C layout of player_s: offsetof viewheight")
    static_assert(typeinfo offsetof<deltaviewheight>(type<player_s>) == 36, "C layout of player_s: offsetof deltaviewheight")
    static_assert(typeinfo offsetof<bob>(type<player_s>) == 40, "C layout of player_s: offsetof bob")
    static_assert(typeinfo offsetof<health>(type<player_s>) == 44, "C layout of player_s: offsetof health")
    static_assert(typeinfo offsetof<armorpoints>(type<player_s>) == 48, "C layout of player_s: offsetof armorpoints")
    static_assert(typeinfo offsetof<armortype>(type<player_s>) == 52, "C layout of player_s: offsetof armortype")
    static_assert(typeinfo offsetof<powers>(type<player_s>) == 56, "C layout of player_s: offsetof powers")
    static_assert(typeinfo offsetof<cards>(type<player_s>) == 80, "C layout of player_s: offsetof cards")
    static_assert(typeinfo offsetof<backpack>(type<player_s>) == 104, "C layout of player_s: offsetof backpack")
    static_assert(typeinfo offsetof<frags>(type<player_s>) == 108, "C layout of player_s: offsetof frags")
    static_assert(typeinfo offsetof<readyweapon>(type<player_s>) == 124, "C layout of player_s: offsetof readyweapon")
    static_assert(typeinfo offsetof<pendingweapon>(type<player_s>) == 128, "C layout of player_s: offsetof pendingweapon")
    static_assert(typeinfo offsetof<weaponowned>(type<player_s>) == 132, "C layout of player_s: offsetof weaponowned")
    static_assert(typeinfo offsetof<ammo>(type<player_s>) == 168, "C layout of player_s: offsetof ammo")
    static_assert(typeinfo offsetof<maxammo>(type<player_s>) == 184, "C layout of player_s: offsetof maxammo")
    static_assert(typeinfo offsetof<attackdown>(type<player_s>) == 200, "C layout of player_s: offsetof attackdown")
    static_assert(typeinfo offsetof<usedown>(type<player_s>) == 204, "C layout of player_s: offsetof usedown")
    static_assert(typeinfo offsetof<cheats>(type<player_s>) == 208, "C layout of player_s: offsetof cheats")
    static_assert(typeinfo offsetof<refire>(type<player_s>) == 212, "C layout of player_s: offsetof refire")
    static_assert(typeinfo offsetof<killcount>(type<player_s>) == 216, "C layout of player_s: offsetof killcount")
    static_assert(typeinfo offsetof<itemcount>(type<player_s>) == 220, "C layout of player_s: offsetof itemcount")
    static_assert(typeinfo offsetof<secretcount>(type<player_s>) == 224, "C layout of player_s: offsetof secretcount")
    static_assert(typeinfo offsetof<message>(type<player_s>) == 232, "C layout of player_s: offsetof message")
    static_assert(typeinfo offsetof<damagecount>(type<player_s>) == 240, "C layout of player_s: offsetof damagecount")
    static_assert(typeinfo offsetof<bonuscount>(type<player_s>) == 244, "C layout of player_s: offsetof bonuscount")
    static_assert(typeinfo offsetof<attacker>(type<player_s>) == 248, "C layout of player_s: offsetof attacker")
    static_assert(typeinfo offsetof<extralight>(type<player_s>) == 256, "C layout of player_s: offsetof extralight")
    static_assert(typeinfo offsetof<fixedcolormap>(type<player_s>) == 260, "C layout of player_s: offsetof fixedcolormap")
    static_assert(typeinfo offsetof<colormap>(type<player_s>) == 264, "C layout of player_s: offsetof colormap")
    static_assert(typeinfo offsetof<psprites>(type<player_s>) == 272, "C layout of player_s: offsetof psprites")
    static_assert(typeinfo offsetof<didsecret>(type<player_s>) == 320, "C layout of player_s: offsetof didsecret")
    static_assert(typeinfo sizeof(type<mobj_t>) == 224, "C layout of mobj_t: sizeof")
    static_assert(typeinfo alignof(type<mobj_t>) == 8, "C layout of mobj_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<mobj_t>) == 0, "C layout of mobj_t: offsetof thinker")
    static_assert(typeinfo offsetof<x>(type<mobj_t>) == 24, "C layout of mobj_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<mobj_t>) == 28, "C layout of mobj_t: offsetof y")
    static_assert(typeinfo offsetof<z>(type<mobj_t>) == 32, "C layout of mobj_t: offsetof z")
    static_assert(typeinfo offsetof<snext>(type<mobj_t>) == 40, "C layout of mobj_t: offsetof snext")
    static_assert(typeinfo offsetof<sprev>(type<mobj_t>) == 48, "C layout of mobj_t: offsetof sprev")
    static_assert(typeinfo offsetof<angle>(type<mobj_t>) == 56, "C layout of mobj_t: offsetof angle")
    static_assert(typeinfo offsetof<sprite>(type<mobj_t>) == 60, "C layout of mobj_t: offsetof sprite")
    static_assert(typeinfo offsetof<frame>(type<mobj_t>) == 64, "C layout of mobj_t: offsetof frame")
    static_assert(typeinfo offsetof<bnext>(type<mobj_t>) == 72, "C layout of mobj_t: offsetof bnext")
    static_assert(typeinfo offsetof<bprev>(type<mobj_t>) == 80, "C layout of mobj_t: offsetof bprev")
    static_assert(typeinfo offsetof<subsector>(type<mobj_t>) == 88, "C layout of mobj_t: offsetof subsector")
    static_assert(typeinfo offsetof<floorz>(type<mobj_t>) == 96, "C layout of mobj_t: offsetof floorz")
    static_assert(typeinfo offsetof<ceilingz>(type<mobj_t>) == 100, "C layout of mobj_t: offsetof ceilingz")
    static_assert(typeinfo offsetof<radius>(type<mobj_t>) == 104, "C layout of mobj_t: offsetof radius")
    static_assert(typeinfo offsetof<height>(type<mobj_t>) == 108, "C layout of mobj_t: offsetof height")
    static_assert(typeinfo offsetof<momx>(type<mobj_t>) == 112, "C layout of mobj_t: offsetof momx")
    static_assert(typeinfo offsetof<momy>(type<mobj_t>) == 116, "C layout of mobj_t: offsetof momy")
    static_assert(typeinfo offsetof<momz>(type<mobj_t>) == 120, "C layout of mobj_t: offsetof momz")
    static_assert(typeinfo offsetof<validcount>(type<mobj_t>) == 124, "C layout of mobj_t: offsetof validcount")
    static_assert(typeinfo offsetof<type_0>(type<mobj_t>) == 128, "C layout of mobj_t: offsetof type_0")
    static_assert(typeinfo offsetof<info>(type<mobj_t>) == 136, "C layout of mobj_t: offsetof info")
    static_assert(typeinfo offsetof<tics>(type<mobj_t>) == 144, "C layout of mobj_t: offsetof tics")
    static_assert(typeinfo offsetof<state>(type<mobj_t>) == 152, "C layout of mobj_t: offsetof state")
    static_assert(typeinfo offsetof<flags>(type<mobj_t>) == 160, "C layout of mobj_t: offsetof flags")
    static_assert(typeinfo offsetof<health>(type<mobj_t>) == 164, "C layout of mobj_t: offsetof health")
    static_assert(typeinfo offsetof<movedir>(type<mobj_t>) == 168, "C layout of mobj_t: offsetof movedir")
    static_assert(typeinfo offsetof<movecount>(type<mobj_t>) == 172, "C layout of mobj_t: offsetof movecount")
    static_assert(typeinfo offsetof<target>(type<mobj_t>) == 176, "C layout of mobj_t: offsetof target")
    static_assert(typeinfo offsetof<reactiontime>(type<mobj_t>) == 184, "C layout of mobj_t: offsetof reactiontime")
    static_assert(typeinfo offsetof<threshold>(type<mobj_t>) == 188, "C layout of mobj_t: offsetof threshold")
    static_assert(typeinfo offsetof<player>(type<mobj_t>) == 192, "C layout of mobj_t: offsetof player")
    static_assert(typeinfo offsetof<lastlook>(type<mobj_t>) == 200, "C layout of mobj_t: offsetof lastlook")
    static_assert(typeinfo offsetof<spawnpoint>(type<mobj_t>) == 204, "C layout of mobj_t: offsetof spawnpoint")
    static_assert(typeinfo offsetof<tracer>(type<mobj_t>) == 216, "C layout of mobj_t: offsetof tracer")
    static_assert(typeinfo sizeof(type<subsector_s>) == 16, "C layout of subsector_s: sizeof")
    static_assert(typeinfo alignof(type<subsector_s>) == 8, "C layout of subsector_s: alignof")
    static_assert(typeinfo offsetof<sector>(type<subsector_s>) == 0, "C layout of subsector_s: offsetof sector")
    static_assert(typeinfo offsetof<numlines>(type<subsector_s>) == 8, "C layout of subsector_s: offsetof numlines")
    static_assert(typeinfo offsetof<firstline>(type<subsector_s>) == 10, "C layout of subsector_s: offsetof firstline")
    static_assert(typeinfo sizeof(type<sector_t>) == 128, "C layout of sector_t: sizeof")
    static_assert(typeinfo alignof(type<sector_t>) == 8, "C layout of sector_t: alignof")
    static_assert(typeinfo offsetof<floorheight>(type<sector_t>) == 0, "C layout of sector_t: offsetof floorheight")
    static_assert(typeinfo offsetof<ceilingheight>(type<sector_t>) == 4, "C layout of sector_t: offsetof ceilingheight")
    static_assert(typeinfo offsetof<floorpic>(type<sector_t>) == 8, "C layout of sector_t: offsetof floorpic")
    static_assert(typeinfo offsetof<ceilingpic>(type<sector_t>) == 10, "C layout of sector_t: offsetof ceilingpic")
    static_assert(typeinfo offsetof<lightlevel>(type<sector_t>) == 12, "C layout of sector_t: offsetof lightlevel")
    static_assert(typeinfo offsetof<special>(type<sector_t>) == 14, "C layout of sector_t: offsetof special")
    static_assert(typeinfo offsetof<tag>(type<sector_t>) == 16, "C layout of sector_t: offsetof tag")
    static_assert(typeinfo offsetof<soundtraversed>(type<sector_t>) == 20, "C layout of sector_t: offsetof soundtraversed")
    static_assert(typeinfo offsetof<soundtarget>(type<sector_t>) == 24, "C layout of sector_t: offsetof soundtarget")
    static_assert(typeinfo offsetof<blockbox>(type<sector_t>) == 32, "C layout of sector_t: offsetof blockbox")
    static_assert(typeinfo offsetof<soundorg>(type<sector_t>) == 48, "C layout of sector_t: offsetof soundorg")
    static_assert(typeinfo offsetof<validcount>(type<sector_t>) == 88, "C layout of sector_t: offsetof validcount")
    static_assert(typeinfo offsetof<thinglist>(type<sector_t>) == 96, "C layout of sector_t: offsetof thinglist")
    static_assert(typeinfo offsetof<specialdata>(type<sector_t>) == 104, "C layout of sector_t: offsetof specialdata")
    static_assert(typeinfo offsetof<linecount>(type<sector_t>) == 112, "C layout of sector_t: offsetof linecount")
    static_assert(typeinfo offsetof<lines>(type<sector_t>) == 120, "C layout of sector_t: offsetof lines")
    static_assert(typeinfo sizeof(type<line_s>) == 88, "C layout of line_s: sizeof")
    static_assert(typeinfo alignof(type<line_s>) == 8, "C layout of line_s: alignof")
    static_assert(typeinfo offsetof<v1>(type<line_s>) == 0, "C layout of line_s: offsetof v1")
    static_assert(typeinfo offsetof<v2>(type<line_s>) == 8, "C layout of line_s: offsetof v2")
    static_assert(typeinfo offsetof<dx>(type<line_s>) == 16, "C layout of line_s: offsetof dx")
    static_assert(typeinfo offsetof<dy>(type<line_s>) == 20, "C layout of line_s: offsetof dy")
    static_assert(typeinfo offsetof<flags>(type<line_s>) == 24, "C layout of line_s: offsetof flags")
    static_assert(typeinfo offsetof<special>(type<line_s>) == 26, "C layout of line_s: offsetof special")
    static_assert(typeinfo offsetof<tag>(type<line_s>) == 28, "C layout of line_s: offsetof tag")
    static_assert(typeinfo offsetof<sidenum>(type<line_s>) == 30, "C layout of line_s: offsetof sidenum")
    static_assert(typeinfo offsetof<bbox>(type<line_s>) == 36, "C layout of line_s: offsetof bbox")
    static_assert(typeinfo offsetof<slopetype>(type<line_s>) == 52, "C layout of line_s: offsetof slopetype")
    static_assert(typeinfo offsetof<frontsector>(type<line_s>) == 56, "C layout of line_s: offsetof frontsector")
    static_assert(typeinfo offsetof<backsector>(type<line_s>) == 64, "C layout of line_s: offsetof backsector")
    static_assert(typeinfo offsetof<validcount>(type<line_s>) == 72, "C layout of line_s: offsetof validcount")
    static_assert(typeinfo offsetof<specialdata>(type<line_s>) == 80, "C layout of line_s: offsetof specialdata")
    static_assert(typeinfo sizeof(type<vertex_t>) == 8, "C layout of vertex_t: sizeof")
    static_assert(typeinfo alignof(type<vertex_t>) == 4, "C layout of vertex_t: alignof")
    static_assert(typeinfo offsetof<x>(type<vertex_t>) == 0, "C layout of vertex_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<vertex_t>) == 4, "C layout of vertex_t: offsetof y")
    static_assert(typeinfo sizeof(type<degenmobj_t>) == 40, "C layout of degenmobj_t: sizeof")
    static_assert(typeinfo alignof(type<degenmobj_t>) == 8, "C layout of degenmobj_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<degenmobj_t>) == 0, "C layout of degenmobj_t: offsetof thinker")
    static_assert(typeinfo offsetof<x>(type<degenmobj_t>) == 24, "C layout of degenmobj_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<degenmobj_t>) == 28, "C layout of degenmobj_t: offsetof y")
    static_assert(typeinfo offsetof<z>(type<degenmobj_t>) == 32, "C layout of degenmobj_t: offsetof z")
    static_assert(typeinfo sizeof(type<player_t>) == 328, "C layout of player_t: sizeof")
    static_assert(typeinfo alignof(type<player_t>) == 8, "C layout of player_t: alignof")
    static_assert(typeinfo offsetof<mo>(type<player_t>) == 0, "C layout of player_t: offsetof mo")
    static_assert(typeinfo offsetof<playerstate>(type<player_t>) == 8, "C layout of player_t: offsetof playerstate")
    static_assert(typeinfo offsetof<cmd>(type<player_t>) == 12, "C layout of player_t: offsetof cmd")
    static_assert(typeinfo offsetof<viewz>(type<player_t>) == 28, "C layout of player_t: offsetof viewz")
    static_assert(typeinfo offsetof<viewheight>(type<player_t>) == 32, "C layout of player_t: offsetof viewheight")
    static_assert(typeinfo offsetof<deltaviewheight>(type<player_t>) == 36, "C layout of player_t: offsetof deltaviewheight")
    static_assert(typeinfo offsetof<bob>(type<player_t>) == 40, "C layout of player_t: offsetof bob")
    static_assert(typeinfo offsetof<health>(type<player_t>) == 44, "C layout of player_t: offsetof health")
    static_assert(typeinfo offsetof<armorpoints>(type<player_t>) == 48, "C layout of player_t: offsetof armorpoints")
    static_assert(typeinfo offsetof<armortype>(type<player_t>) == 52, "C layout of player_t: offsetof armortype")
    static_assert(typeinfo offsetof<powers>(type<player_t>) == 56, "C layout of player_t: offsetof powers")
    static_assert(typeinfo offsetof<cards>(type<player_t>) == 80, "C layout of player_t: offsetof cards")
    static_assert(typeinfo offsetof<backpack>(type<player_t>) == 104, "C layout of player_t: offsetof backpack")
    static_assert(typeinfo offsetof<frags>(type<player_t>) == 108, "C layout of player_t: offsetof frags")
    static_assert(typeinfo offsetof<readyweapon>(type<player_t>) == 124, "C layout of player_t: offsetof readyweapon")
    static_assert(typeinfo offsetof<pendingweapon>(type<player_t>) == 128, "C layout of player_t: offsetof pendingweapon")
    static_assert(typeinfo offsetof<weaponowned>(type<player_t>) == 132, "C layout of player_t: offsetof weaponowned")
    static_assert(typeinfo offsetof<ammo>(type<player_t>) == 168, "C layout of player_t: offsetof ammo")
    static_assert(typeinfo offsetof<maxammo>(type<player_t>) == 184, "C layout of player_t: offsetof maxammo")
    static_assert(typeinfo offsetof<attackdown>(type<player_t>) == 200, "C layout of player_t: offsetof attackdown")
    static_assert(typeinfo offsetof<usedown>(type<player_t>) == 204, "C layout of player_t: offsetof usedown")
    static_assert(typeinfo offsetof<cheats>(type<player_t>) == 208, "C layout of player_t: offsetof cheats")
    static_assert(typeinfo offsetof<refire>(type<player_t>) == 212, "C layout of player_t: offsetof refire")
    static_assert(typeinfo offsetof<killcount>(type<player_t>) == 216, "C layout of player_t: offsetof killcount")
    static_assert(typeinfo offsetof<itemcount>(type<player_t>) == 220, "C layout of player_t: offsetof itemcount")
    static_assert(typeinfo offsetof<secretcount>(type<player_t>) == 224, "C layout of player_t: offsetof secretcount")
    static_assert(typeinfo offsetof<message>(type<player_t>) == 232, "C layout of player_t: offsetof message")
    static_assert(typeinfo offsetof<damagecount>(type<player_t>) == 240, "C layout of player_t: offsetof damagecount")
    static_assert(typeinfo offsetof<bonuscount>(type<player_t>) == 244, "C layout of player_t: offsetof bonuscount")
    static_assert(typeinfo offsetof<attacker>(type<player_t>) == 248, "C layout of player_t: offsetof attacker")
    static_assert(typeinfo offsetof<extralight>(type<player_t>) == 256, "C layout of player_t: offsetof extralight")
    static_assert(typeinfo offsetof<fixedcolormap>(type<player_t>) == 260, "C layout of player_t: offsetof fixedcolormap")
    static_assert(typeinfo offsetof<colormap>(type<player_t>) == 264, "C layout of player_t: offsetof colormap")
    static_assert(typeinfo offsetof<psprites>(type<player_t>) == 272, "C layout of player_t: offsetof psprites")
    static_assert(typeinfo offsetof<didsecret>(type<player_t>) == 320, "C layout of player_t: offsetof didsecret")
    static_assert(typeinfo sizeof(type<channel_t>) == 24, "C layout of channel_t: sizeof")
    static_assert(typeinfo alignof(type<channel_t>) == 8, "C layout of channel_t: alignof")
    static_assert(typeinfo offsetof<sfxinfo>(type<channel_t>) == 0, "C layout of channel_t: offsetof sfxinfo")
    static_assert(typeinfo offsetof<origin>(type<channel_t>) == 8, "C layout of channel_t: offsetof origin")
    static_assert(typeinfo offsetof<handle>(type<channel_t>) == 16, "C layout of channel_t: offsetof handle")
}
