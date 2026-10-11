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
    nosound = uint(M_CheckParm(345461) > 0 ? 1 : 0)
    nosfx = uint(M_CheckParm(345470) > 0 ? 1 : 0)
    nomusic = uint(M_CheckParm(345477) > 0 ? 1 : 0)
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
    music_module = 42048
    return
}
var private music_module : int = 0

[sideeffects]
def private InitSfxModule(var use_sfx_prefix_0 : uint) {
    var i : int
    sound_module = 0
    i = 0
    while (sound_modules[i] != 0) {
        let c2da_fresh0 : int = sound_modules[i]
        let c2da_fresh1 : int = sound_modules[i] + 8
        if (SndDeviceInList(uint(int(uint(c2da_mem[42272]) | uint(c2da_mem[42273]) << 0x8 | uint(c2da_mem[42274]) << 0x10 | uint(c2da_mem[42275]) << 0x18)), int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh1]) | uint(c2da_mem[c2da_fresh1 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh1 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh1 + 3]) << 0x18)) != 0x0) {
            let c2da_fresh2 : int = sound_modules[i] + 16
            if (invoke(c2da_fn_table6[int(uint(c2da_mem[c2da_fresh2]) | uint(c2da_mem[c2da_fresh2 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh2 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh2 + 3]) << 0x18)], use_sfx_prefix_0) != 0x0) {
                sound_module = int(sound_modules[i])  // nolint:PERF020
                return
            }
        }
        i++
    }
    return
}
var private sound_modules : int[2] = fixed_array<int>(42160, 0)

var private sound_module : int = 0

[sideeffects]
def private SndDeviceInList(var device : uint; var list : int; var len : int) : uint {
    for (i_0 in range(0, len)) {
        if (device == (uint(c2da_mem[list + i_0 * 4]) | uint(c2da_mem[list + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[list + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[list + i_0 * 4 + 3]) << 0x18)) {
            return 1u
        }
    }
    return 0u
}
[export, sideeffects]
def I_ShutdownSound() {
    if (sound_module != 0) {
        invoke(c2da_fn_table0[int(uint(c2da_mem[sound_module + 24]) | uint(c2da_mem[sound_module + 25]) << 0x8 | uint(c2da_mem[sound_module + 26]) << 0x10 | uint(c2da_mem[sound_module + 27]) << 0x18)])
    }
    if (music_module != 0) {
        invoke(c2da_fn_table0[int(uint(c2da_mem[music_module + 24]) | uint(c2da_mem[music_module + 25]) << 0x8 | uint(c2da_mem[music_module + 26]) << 0x10 | uint(c2da_mem[music_module + 27]) << 0x18)])
    }
    return
}
[export, sideeffects]
def I_GetSfxLumpNum(var sfxinfo : int) : int {
    if (sound_module != 0) {
        return invoke(c2da_fn_table7[int(uint(c2da_mem[sound_module + 32]) | uint(c2da_mem[sound_module + 33]) << 0x8 | uint(c2da_mem[sound_module + 34]) << 0x10 | uint(c2da_mem[sound_module + 35]) << 0x18)], sfxinfo)
    } else {
        return 0
    }
}
[export, sideeffects]
def I_UpdateSound() {
    if (sound_module != 0) {
        invoke(c2da_fn_table0[int(uint(c2da_mem[sound_module + 40]) | uint(c2da_mem[sound_module + 41]) << 0x8 | uint(c2da_mem[sound_module + 42]) << 0x10 | uint(c2da_mem[sound_module + 43]) << 0x18)])
    }
    if (music_module != 0 && int(uint(c2da_mem[music_module + 96]) | uint(c2da_mem[music_module + 97]) << 0x8 | uint(c2da_mem[music_module + 98]) << 0x10 | uint(c2da_mem[music_module + 99]) << 0x18) != 0) {
        invoke(c2da_fn_table0[int(uint(c2da_mem[music_module + 96]) | uint(c2da_mem[music_module + 97]) << 0x8 | uint(c2da_mem[music_module + 98]) << 0x10 | uint(c2da_mem[music_module + 99]) << 0x18)])
    }
    return
}
[export, sideeffects]
def I_UpdateSoundParams(var channel : int; var vol : int; var sep : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    I_UpdateSoundParams_c2da_frame(channel, vol, sep, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private CheckVolumeSeparation(var vol_0 : int; var sep_0 : int) {
    if (int(uint(c2da_mem[sep_0]) | uint(c2da_mem[sep_0 + 1]) << 0x8 | uint(c2da_mem[sep_0 + 2]) << 0x10 | uint(c2da_mem[sep_0 + 3]) << 0x18) < 0) {
        let c2da_fresh5 : int = 0
        let c2da_fresh6 : uint = uint(c2da_fresh5)
        c2da_mem[sep_0] = uint8(c2da_fresh6)
        c2da_mem[sep_0 + 1] = uint8(c2da_fresh6 >> 0x8)
        c2da_mem[sep_0 + 2] = uint8(c2da_fresh6 >> 0x10)
        c2da_mem[sep_0 + 3] = uint8(c2da_fresh6 >> 0x18)
    } elif (int(uint(c2da_mem[sep_0]) | uint(c2da_mem[sep_0 + 1]) << 0x8 | uint(c2da_mem[sep_0 + 2]) << 0x10 | uint(c2da_mem[sep_0 + 3]) << 0x18) > 254) {
        let c2da_fresh7 : int = 254
        let c2da_fresh8 : uint = uint(c2da_fresh7)
        c2da_mem[sep_0] = uint8(c2da_fresh8)
        c2da_mem[sep_0 + 1] = uint8(c2da_fresh8 >> 0x8)
        c2da_mem[sep_0 + 2] = uint8(c2da_fresh8 >> 0x10)
        c2da_mem[sep_0 + 3] = uint8(c2da_fresh8 >> 0x18)
    }
    if (int(uint(c2da_mem[vol_0]) | uint(c2da_mem[vol_0 + 1]) << 0x8 | uint(c2da_mem[vol_0 + 2]) << 0x10 | uint(c2da_mem[vol_0 + 3]) << 0x18) < 0) {
        let c2da_fresh9 : int = 0
        let c2da_fresh10 : uint = uint(c2da_fresh9)
        c2da_mem[vol_0] = uint8(c2da_fresh10)
        c2da_mem[vol_0 + 1] = uint8(c2da_fresh10 >> 0x8)
        c2da_mem[vol_0 + 2] = uint8(c2da_fresh10 >> 0x10)
        c2da_mem[vol_0 + 3] = uint8(c2da_fresh10 >> 0x18)
    } elif (int(uint(c2da_mem[vol_0]) | uint(c2da_mem[vol_0 + 1]) << 0x8 | uint(c2da_mem[vol_0 + 2]) << 0x10 | uint(c2da_mem[vol_0 + 3]) << 0x18) > 127) {
        let c2da_fresh11 : int = 127
        let c2da_fresh12 : uint = uint(c2da_fresh11)
        c2da_mem[vol_0] = uint8(c2da_fresh12)
        c2da_mem[vol_0 + 1] = uint8(c2da_fresh12 >> 0x8)
        c2da_mem[vol_0 + 2] = uint8(c2da_fresh12 >> 0x10)
        c2da_mem[vol_0 + 3] = uint8(c2da_fresh12 >> 0x18)
    }
    return
}
[export, sideeffects]
def I_StartSound(var sfxinfo_0 : int; var channel_0 : int; var vol_1 : int; var sep_1 : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = I_StartSound_c2da_frame(sfxinfo_0, channel_0, vol_1, sep_1, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def I_StopSound(var channel_1 : int) {
    if (sound_module != 0) {
        invoke(c2da_fn_table5[int(uint(c2da_mem[sound_module + 64]) | uint(c2da_mem[sound_module + 65]) << 0x8 | uint(c2da_mem[sound_module + 66]) << 0x10 | uint(c2da_mem[sound_module + 67]) << 0x18)], channel_1)
    }
    return
}
[export, sideeffects]
def I_SoundIsPlaying(var channel_2 : int) : uint {
    if (sound_module != 0) {
        return invoke(c2da_fn_table10[int(uint(c2da_mem[sound_module + 72]) | uint(c2da_mem[sound_module + 73]) << 0x8 | uint(c2da_mem[sound_module + 74]) << 0x10 | uint(c2da_mem[sound_module + 75]) << 0x18)], channel_2)
    } else {
        return 0u
    }
}
[export, sideeffects]
def I_PrecacheSounds(var sounds : int; var num_sounds : int) {
    if (sound_module != 0 && int(uint(c2da_mem[sound_module + 80]) | uint(c2da_mem[sound_module + 81]) << 0x8 | uint(c2da_mem[sound_module + 82]) << 0x10 | uint(c2da_mem[sound_module + 83]) << 0x18) != 0) {
        invoke(c2da_fn_table1[int(uint(c2da_mem[sound_module + 80]) | uint(c2da_mem[sound_module + 81]) << 0x8 | uint(c2da_mem[sound_module + 82]) << 0x10 | uint(c2da_mem[sound_module + 83]) << 0x18)], sounds, num_sounds)
    }
    return
}
[export, sideeffects]
def I_InitMusic() {
    if (music_module != 0) {
        invoke(c2da_fn_table2[int(uint(c2da_mem[music_module + 16]) | uint(c2da_mem[music_module + 17]) << 0x8 | uint(c2da_mem[music_module + 18]) << 0x10 | uint(c2da_mem[music_module + 19]) << 0x18)])
    }
    return
}
[export, sideeffects]
def I_ShutdownMusic() {
    return
}
[export, sideeffects]
def I_SetMusicVolume(var volume : int) {
    if (music_module != 0) {
        invoke(c2da_fn_table5[int(uint(c2da_mem[music_module + 32]) | uint(c2da_mem[music_module + 33]) << 0x8 | uint(c2da_mem[music_module + 34]) << 0x10 | uint(c2da_mem[music_module + 35]) << 0x18)], volume)
    }
    return
}
[export, sideeffects]
def I_PauseSong() {
    if (music_module != 0) {
        invoke(c2da_fn_table0[int(uint(c2da_mem[music_module + 40]) | uint(c2da_mem[music_module + 41]) << 0x8 | uint(c2da_mem[music_module + 42]) << 0x10 | uint(c2da_mem[music_module + 43]) << 0x18)])
    }
    return
}
[export, sideeffects]
def I_ResumeSong() {
    if (music_module != 0) {
        invoke(c2da_fn_table0[int(uint(c2da_mem[music_module + 48]) | uint(c2da_mem[music_module + 49]) << 0x8 | uint(c2da_mem[music_module + 50]) << 0x10 | uint(c2da_mem[music_module + 51]) << 0x18)])
    }
    return
}
[export, sideeffects]
def I_RegisterSong(var data : int; var len_0 : int) : int {
    if (music_module != 0) {
        return invoke(c2da_fn_table11[int(uint(c2da_mem[music_module + 56]) | uint(c2da_mem[music_module + 57]) << 0x8 | uint(c2da_mem[music_module + 58]) << 0x10 | uint(c2da_mem[music_module + 59]) << 0x18)], data, len_0)
    } else {
        return 0
    }
}
[export, sideeffects]
def I_UnRegisterSong(var handle : int) {
    if (music_module != 0) {
        invoke(c2da_fn_table5[int(uint(c2da_mem[music_module + 64]) | uint(c2da_mem[music_module + 65]) << 0x8 | uint(c2da_mem[music_module + 66]) << 0x10 | uint(c2da_mem[music_module + 67]) << 0x18)], handle)
    }
    return
}
[export, sideeffects]
def I_PlaySong(var handle_0 : int; var looping : uint) {
    if (music_module != 0) {
        invoke(c2da_fn_table12[int(uint(c2da_mem[music_module + 72]) | uint(c2da_mem[music_module + 73]) << 0x8 | uint(c2da_mem[music_module + 74]) << 0x10 | uint(c2da_mem[music_module + 75]) << 0x18)], handle_0, looping)
    }
    return
}
[export, sideeffects]
def I_StopSong() {
    if (music_module != 0) {
        invoke(c2da_fn_table0[int(uint(c2da_mem[music_module + 80]) | uint(c2da_mem[music_module + 81]) << 0x8 | uint(c2da_mem[music_module + 82]) << 0x10 | uint(c2da_mem[music_module + 83]) << 0x18)])
    }
    return
}
[export, sideeffects]
def I_MusicIsPlaying() : uint {
    if (music_module != 0) {
        return invoke(c2da_fn_table2[int(uint(c2da_mem[music_module + 88]) | uint(c2da_mem[music_module + 89]) << 0x8 | uint(c2da_mem[music_module + 90]) << 0x10 | uint(c2da_mem[music_module + 91]) << 0x18)])
    } else {
        return 0u
    }
}
[export, sideeffects]
def I_BindSoundVariables() {
    M_BindVariable(345486, 42256)
    M_BindVariable(345502, 42272)
    M_BindVariable(345516, 345408)
    M_BindVariable(345527, 345424)
    M_BindVariable(345537, 345440)
    M_BindVariable(345547, 345456)
    M_BindVariable(345557, 42288)
    M_BindVariable(345577, 42304)
    M_BindVariable(345590, 42320)
    M_BindVariable(345605, 42336)
    M_BindVariable(345619, 42352)
    M_BindVariable(345637, 42368)
    return
}
[sideeffects]
def private I_UpdateSoundParams_c2da_frame(var channel : int; var vol : int; var sep : int; c2da_fp : int) {
    let c2da_fresh3 : uint = uint(vol)
    c2da_mem[c2da_fp] = uint8(c2da_fresh3)
    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : uint = uint(sep)
    c2da_mem[c2da_fp + 16] = uint8(c2da_fresh4)
    c2da_mem[c2da_fp + 17] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[c2da_fp + 18] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[c2da_fp + 19] = uint8(c2da_fresh4 >> 0x18)
    if (sound_module != 0) {
        CheckVolumeSeparation(c2da_fp, c2da_fp + 16)
        invoke(c2da_fn_table8[int(uint(c2da_mem[sound_module + 48]) | uint(c2da_mem[sound_module + 49]) << 0x8 | uint(c2da_mem[sound_module + 50]) << 0x10 | uint(c2da_mem[sound_module + 51]) << 0x18)], channel, int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18), int(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18))
    }
    return
}
[sideeffects]
def private I_StartSound_c2da_frame(var sfxinfo_0 : int; var channel_0 : int; var vol_1 : int; var sep_1 : int; c2da_fp : int) : int {
    let c2da_fresh13 : uint = uint(vol_1)
    c2da_mem[c2da_fp] = uint8(c2da_fresh13)
    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh13 >> 0x18)
    let c2da_fresh14 : uint = uint(sep_1)
    c2da_mem[c2da_fp + 16] = uint8(c2da_fresh14)
    c2da_mem[c2da_fp + 17] = uint8(c2da_fresh14 >> 0x8)
    c2da_mem[c2da_fp + 18] = uint8(c2da_fresh14 >> 0x10)
    c2da_mem[c2da_fp + 19] = uint8(c2da_fresh14 >> 0x18)
    if (sound_module != 0) {
        CheckVolumeSeparation(c2da_fp, c2da_fp + 16)
        return invoke(c2da_fn_table9[int(uint(c2da_mem[sound_module + 56]) | uint(c2da_mem[sound_module + 57]) << 0x8 | uint(c2da_mem[sound_module + 58]) << 0x10 | uint(c2da_mem[sound_module + 59]) << 0x18)], sfxinfo_0, channel_0, int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18), int(uint(c2da_mem[c2da_fp + 16]) | uint(c2da_mem[c2da_fp + 17]) << 0x8 | uint(c2da_mem[c2da_fp + 18]) << 0x10 | uint(c2da_mem[c2da_fp + 19]) << 0x18))
    } else {
        return 0
    }
}

// This unit's static data, at heap offset 345408.
let private c2da_lin_static_i_sound_seg = fixed_array<int>(345461, 195)
let private c2da_lin_static_i_sound = fixed_array<uint64>(0x646e756f736f6e2dul, 0x7866736f6e2d00ul, 0x636973756d6f6e2dul, 0x73756d5f646e7300ul, 0x6563697665646369ul, 0x7866735f646e7300ul, 0x7300656369766564ul, 0x726f7062735f646eul, 0x62735f646e730074ul, 0x5f646e7300717269ul, 0x6e7300616d646273ul, 0x74726f706d5f64ul, 0x7378616d5f646e73ul, 0x656d69746563696cul, 0x5f646e7300736d5ful, 0x646d63636973756dul, 0x6d61735f646e7300ul, 0x65746172656c70ul, 0x686361635f646e73ul, 0x737500657a697365ul, 0x6d617362696c5f65ul, 0x65746172656c70ul, 0x6c706d617362696cul, 0x63735f6574617265ul, 0x656c61ul)

[init]
def private c2da_lin_init_static_i_sound() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_i_sound_seg[s * 2]
        for (k in range(c2da_lin_static_i_sound_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_i_sound[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_i_sound_0 = fixed_array<uint8>(0x3, 0x0, 0x0, 0x0)
let private c2da_lin_extern_i_sound_1 = fixed_array<uint8>(0x3, 0x0, 0x0, 0x0)
let private c2da_lin_extern_i_sound_2 = fixed_array<uint8>(0x1c, 0x0, 0x0, 0x0)
let private c2da_lin_extern_i_sound_3 = fixed_array<uint8>(0x74, 0x45, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_i_sound_4 = fixed_array<uint8>(0x44, 0xac, 0x0, 0x0)
let private c2da_lin_extern_i_sound_5 = fixed_array<uint8>(0x0, 0x0, 0x0, 0x4)

[init]
def private c2da_lin_init_externs_i_sound() {
    c2da_lin_setup()
    for (i in range(4)) {
        c2da_mem[42256 + i] = c2da_lin_extern_i_sound_0[i]
    }
    for (i in range(4)) {
        c2da_mem[42272 + i] = c2da_lin_extern_i_sound_1[i]
    }
    for (i in range(4)) {
        c2da_mem[42288 + i] = c2da_lin_extern_i_sound_2[i]
    }
    for (i in range(8)) {
        c2da_mem[42304 + i] = c2da_lin_extern_i_sound_3[i]
    }
    for (i in range(4)) {
        c2da_mem[42320 + i] = c2da_lin_extern_i_sound_4[i]
    }
    for (i in range(4)) {
        c2da_mem[42336 + i] = c2da_lin_extern_i_sound_5[i]
    }
}
