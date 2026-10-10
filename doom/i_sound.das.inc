var private c2da_str_i_sound_0 : array<int8> = [int8(45), int8(110), int8(111), int8(115), int8(111), int8(117), int8(110), int8(100), int8(0)]

var private c2da_str_i_sound_1 : array<int8> = [int8(45), int8(110), int8(111), int8(115), int8(102), int8(120), int8(0)]

var private c2da_str_i_sound_2 : array<int8> = [int8(45), int8(110), int8(111), int8(109), int8(117), int8(115), int8(105), int8(99), int8(0)]

var private c2da_str_i_sound_3 : array<int8> = [int8(0)]

var private c2da_str_i_sound_4 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(109), int8(117), int8(115), int8(105), int8(99), int8(100), int8(101), int8(118), int8(105), int8(99), int8(101), int8(0)]

var private c2da_str_i_sound_5 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(115), int8(102), int8(120), int8(100), int8(101), int8(118), int8(105), int8(99), int8(101), int8(0)]

var private c2da_str_i_sound_6 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(115), int8(98), int8(112), int8(111), int8(114), int8(116), int8(0)]

var private c2da_str_i_sound_7 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(115), int8(98), int8(105), int8(114), int8(113), int8(0)]

var private c2da_str_i_sound_8 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(115), int8(98), int8(100), int8(109), int8(97), int8(0)]

var private c2da_str_i_sound_9 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(109), int8(112), int8(111), int8(114), int8(116), int8(0)]

var private c2da_str_i_sound_10 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(109), int8(97), int8(120), int8(115), int8(108), int8(105), int8(99), int8(101), int8(116), int8(105), int8(109), int8(101), int8(95), int8(109), int8(115), int8(0)]

var private c2da_str_i_sound_11 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(109), int8(117), int8(115), int8(105), int8(99), int8(99), int8(109), int8(100), int8(0)]

var private c2da_str_i_sound_12 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(115), int8(97), int8(109), int8(112), int8(108), int8(101), int8(114), int8(97), int8(116), int8(101), int8(0)]

var private c2da_str_i_sound_13 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(99), int8(97), int8(99), int8(104), int8(101), int8(115), int8(105), int8(122), int8(101), int8(0)]

[sideeffects]
def private c2da___bswap_16_4(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_4(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_4(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_4(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_4(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_4(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
[export, sideeffects]
def I_InitSound(var use_sfx_prefix : uint) {
    var nosound : uint
    var nosfx : uint
    var nomusic : uint
    nosound = uint(M_CheckParm(unsafe(addr<int8?>(c2da_str_i_sound_0[0]))) > 0 ? 1 : 0)
    nosfx = uint(M_CheckParm(unsafe(addr<int8?>(c2da_str_i_sound_1[0]))) > 0 ? 1 : 0)
    nomusic = uint(M_CheckParm(unsafe(addr<int8?>(c2da_str_i_sound_2[0]))) > 0 ? 1 : 0)
    if (nosound == 0 && screensaver_mode == 0) {
        if (nosfx == 0) {
            InitSfxModule(use_sfx_prefix)
        }
        if (nomusic == 0) {
            InitMusicModule()
        }
    }
    return
}
[sideeffects]
def private InitMusicModule() {
    return
}
[sideeffects]
def private InitSfxModule(var use_sfx_prefix_0 : uint) {
    var i : int
    sound_module = null
    i = 0
    while (sound_modules[i] != null) {
        if (SndDeviceInList(unsafe(reinterpret<snddevice_t>(uint(snd_sfxdevice))), sound_modules[i].sound_devices, sound_modules[i].num_sound_devices) != 0x0) {
            if (invoke(sound_modules[i].Init, use_sfx_prefix_0) != 0x0) {
                sound_module = unsafe(reinterpret<sound_module_t?>(sound_modules[i]))
                return
            }
        }
        i++
    }
    return
}
var private sound_modules : sound_module_t? [1] = fixed_array<sound_module_t?>(null)

var private sound_module : sound_module_t? = null

var snd_sfxdevice : int = 3

[sideeffects]
def private SndDeviceInList(var device : snddevice_t; var list : snddevice_t?; var len : int) : uint {
    for (i_0 in range(0, len)) {
        if (uint(device) == uint(unsafe(list[i_0]))) {
            return 1u
        }
    }
    return 0u
}
var snd_musicdevice : int = 3

[export, sideeffects]
def I_ShutdownSound() {
    if (sound_module != null) {
        invoke(sound_module.Shutdown)
    }
    if (music_module != null) {
        invoke(music_module.Shutdown)
    }
    return
}
var private music_module : music_module_t? = null

[export, sideeffects]
def I_GetSfxLumpNum(var sfxinfo : sfxinfo_struct?) : int {
    if (sound_module != null) {
        return invoke(sound_module.GetSfxLumpNum, sfxinfo)
    } else {
        return 0
    }
}
[export, sideeffects]
def I_UpdateSound() {
    if (sound_module != null) {
        invoke(sound_module.Update)
    }
    if (music_module != null && music_module.Poll != unsafe(reinterpret<function<():void>>(null))) {
        invoke(music_module.Poll)
    }
    return
}
[export, sideeffects]
def I_UpdateSoundParams(var channel : int; var vol : int; var sep : int) {
    if (sound_module != null) {
        CheckVolumeSeparation(unsafe(addr<int?>(vol)), unsafe(addr<int?>(sep)))
        invoke(sound_module.UpdateSoundParams, channel, vol, sep)
    }
    return
}
[sideeffects]
def private CheckVolumeSeparation(var vol_0 : int?; var sep_0 : int?) {
    if (*sep_0 < 0) {
        *sep_0 = 0
    } elif (*sep_0 > 254) {
        *sep_0 = 254
    }
    if (*vol_0 < 0) {
        *vol_0 = 0
    } elif (*vol_0 > 127) {
        *vol_0 = 127
    }
    return
}
[export, sideeffects]
def I_StartSound(var sfxinfo_0 : sfxinfo_struct?; var channel_0 : int; var vol_1 : int; var sep_1 : int) : int {
    if (sound_module != null) {
        CheckVolumeSeparation(unsafe(addr<int?>(vol_1)), unsafe(addr<int?>(sep_1)))
        return invoke(sound_module.StartSound, sfxinfo_0, channel_0, vol_1, sep_1)
    } else {
        return 0
    }
}
[export, sideeffects]
def I_StopSound(var channel_1 : int) {
    if (sound_module != null) {
        invoke(sound_module.StopSound, channel_1)
    }
    return
}
[export, sideeffects]
def I_SoundIsPlaying(var channel_2 : int) : uint {
    if (sound_module != null) {
        return invoke(sound_module.SoundIsPlaying, channel_2)
    } else {
        return 0u
    }
}
[export, sideeffects]
def I_PrecacheSounds(var sounds : sfxinfo_struct?; var num_sounds : int) {
    if (sound_module != null && sound_module.CacheSounds != unsafe(reinterpret<function<(var _arg0:sfxinfo_struct?;var _arg1:int):void>>(null))) {
        invoke(sound_module.CacheSounds, sounds, num_sounds)
    }
    return
}
[export, sideeffects]
def I_InitMusic() {
    if (music_module != null) {
        invoke(music_module.Init)
    }
    return
}
[export, sideeffects]
def I_ShutdownMusic() {
    return
}
[export, sideeffects]
def I_SetMusicVolume(var volume : int) {
    if (music_module != null) {
        invoke(music_module.SetMusicVolume, volume)
    }
    return
}
[export, sideeffects]
def I_PauseSong() {
    if (music_module != null) {
        invoke(music_module.PauseMusic)
    }
    return
}
[export, sideeffects]
def I_ResumeSong() {
    if (music_module != null) {
        invoke(music_module.ResumeMusic)
    }
    return
}
[export, sideeffects]
def I_RegisterSong(var data : uint8?; var len_0 : int) : uint8? {
    if (music_module != null) {
        return unsafe(reinterpret<uint8?>(invoke(music_module.RegisterSong, data, len_0)))
    } else {
        return unsafe(reinterpret<uint8?>(null))
    }
}
[export, sideeffects]
def I_UnRegisterSong(var handle : uint8?) {
    if (music_module != null) {
        invoke(music_module.UnRegisterSong, handle)
    }
    return
}
[export, sideeffects]
def I_PlaySong(var handle_0 : uint8?; var looping : uint) {
    if (music_module != null) {
        invoke(music_module.PlaySong, handle_0, looping)
    }
    return
}
[export, sideeffects]
def I_StopSong() {
    if (music_module != null) {
        invoke(music_module.StopSong)
    }
    return
}
[export, sideeffects]
def I_MusicIsPlaying() : uint {
    if (music_module != null) {
        return invoke(music_module.MusicIsPlaying)
    } else {
        return 0u
    }
}
var snd_samplerate : int = 44100

var snd_cachesize : int = 64 * 1024 * 1024

var snd_maxslicetime_ms : int = 28

var snd_musiccmd : int8? = unsafe(addr<int8?>(c2da_str_i_sound_3[0]))

[export, sideeffects]
def I_BindSoundVariables() {
    M_BindVariable(unsafe(addr<int8?>(c2da_str_i_sound_4[0])), unsafe(addr<uint8?>(snd_musicdevice)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_i_sound_5[0])), unsafe(addr<uint8?>(snd_sfxdevice)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_i_sound_6[0])), unsafe(addr<uint8?>(snd_sbport)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_i_sound_7[0])), unsafe(addr<uint8?>(snd_sbirq)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_i_sound_8[0])), unsafe(addr<uint8?>(snd_sbdma)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_i_sound_9[0])), unsafe(addr<uint8?>(snd_mport)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_i_sound_10[0])), unsafe(addr<uint8?>(snd_maxslicetime_ms)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_i_sound_11[0])), unsafe(addr<uint8?>(snd_musiccmd)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_i_sound_12[0])), unsafe(addr<uint8?>(snd_samplerate)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_i_sound_13[0])), unsafe(addr<uint8?>(snd_cachesize)))
    return
}
var private snd_mport : int = 0

var private snd_sbdma : int = 0

var private snd_sbirq : int = 0

var private snd_sbport : int = 0

[sideeffects]
def private c2da_layout_proofs_8() {
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
    static_assert(typeinfo sizeof(type<sound_module_t>) == 88, "C layout of sound_module_t: sizeof")
    static_assert(typeinfo alignof(type<sound_module_t>) == 8, "C layout of sound_module_t: alignof")
    static_assert(typeinfo offsetof<sound_devices>(type<sound_module_t>) == 0, "C layout of sound_module_t: offsetof sound_devices")
    static_assert(typeinfo offsetof<num_sound_devices>(type<sound_module_t>) == 8, "C layout of sound_module_t: offsetof num_sound_devices")
    static_assert(typeinfo offsetof<Init>(type<sound_module_t>) == 16, "C layout of sound_module_t: offsetof Init")
    static_assert(typeinfo offsetof<Shutdown>(type<sound_module_t>) == 24, "C layout of sound_module_t: offsetof Shutdown")
    static_assert(typeinfo offsetof<GetSfxLumpNum>(type<sound_module_t>) == 32, "C layout of sound_module_t: offsetof GetSfxLumpNum")
    static_assert(typeinfo offsetof<Update>(type<sound_module_t>) == 40, "C layout of sound_module_t: offsetof Update")
    static_assert(typeinfo offsetof<UpdateSoundParams>(type<sound_module_t>) == 48, "C layout of sound_module_t: offsetof UpdateSoundParams")
    static_assert(typeinfo offsetof<StartSound>(type<sound_module_t>) == 56, "C layout of sound_module_t: offsetof StartSound")
    static_assert(typeinfo offsetof<StopSound>(type<sound_module_t>) == 64, "C layout of sound_module_t: offsetof StopSound")
    static_assert(typeinfo offsetof<SoundIsPlaying>(type<sound_module_t>) == 72, "C layout of sound_module_t: offsetof SoundIsPlaying")
    static_assert(typeinfo offsetof<CacheSounds>(type<sound_module_t>) == 80, "C layout of sound_module_t: offsetof CacheSounds")
    static_assert(typeinfo sizeof(type<music_module_t>) == 104, "C layout of music_module_t: sizeof")
    static_assert(typeinfo alignof(type<music_module_t>) == 8, "C layout of music_module_t: alignof")
    static_assert(typeinfo offsetof<sound_devices>(type<music_module_t>) == 0, "C layout of music_module_t: offsetof sound_devices")
    static_assert(typeinfo offsetof<num_sound_devices>(type<music_module_t>) == 8, "C layout of music_module_t: offsetof num_sound_devices")
    static_assert(typeinfo offsetof<Init>(type<music_module_t>) == 16, "C layout of music_module_t: offsetof Init")
    static_assert(typeinfo offsetof<Shutdown>(type<music_module_t>) == 24, "C layout of music_module_t: offsetof Shutdown")
    static_assert(typeinfo offsetof<SetMusicVolume>(type<music_module_t>) == 32, "C layout of music_module_t: offsetof SetMusicVolume")
    static_assert(typeinfo offsetof<PauseMusic>(type<music_module_t>) == 40, "C layout of music_module_t: offsetof PauseMusic")
    static_assert(typeinfo offsetof<ResumeMusic>(type<music_module_t>) == 48, "C layout of music_module_t: offsetof ResumeMusic")
    static_assert(typeinfo offsetof<RegisterSong>(type<music_module_t>) == 56, "C layout of music_module_t: offsetof RegisterSong")
    static_assert(typeinfo offsetof<UnRegisterSong>(type<music_module_t>) == 64, "C layout of music_module_t: offsetof UnRegisterSong")
    static_assert(typeinfo offsetof<PlaySong>(type<music_module_t>) == 72, "C layout of music_module_t: offsetof PlaySong")
    static_assert(typeinfo offsetof<StopSong>(type<music_module_t>) == 80, "C layout of music_module_t: offsetof StopSong")
    static_assert(typeinfo offsetof<MusicIsPlaying>(type<music_module_t>) == 88, "C layout of music_module_t: offsetof MusicIsPlaying")
    static_assert(typeinfo offsetof<Poll>(type<music_module_t>) == 96, "C layout of music_module_t: offsetof Poll")
}
