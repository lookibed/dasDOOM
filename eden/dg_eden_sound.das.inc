[export, sideeffects]
def dge_audio_mix(var ms : uint) {
    var frames : int
    var kept : int
    var active : int
    var f : int
    var data : int
    var length_0 : uint
    var pos : uint
    var frac : uint
    var step : uint
    var left : int
    var right : int
    var sample : int
    var value : int
    var magnitude : int
    active = 0
    if (ms > 1000u) {
        ms = 1000u
    }
    dge_audio_acc += ms * 11025u
    frames = int(dge_audio_acc / 1000u)
    dge_audio_acc %= 1000u
    kept = 4096 - dge_audio_count
    if (kept > frames) {
        kept = frames
    }
    for (i in range(0, 16)) {
        data = dge_voices[i].data
        if (data == 0) {
            continue
        }
        if (active == 0) {
            f = 0
            while (f < kept * 2) {
                dge_audio_sum[f] = 0
                f++
            }
            active = 1
        }
        length_0 = dge_voices[i].length
        pos = dge_voices[i].pos
        frac = dge_voices[i].frac
        step = dge_voices[i].step
        left = dge_voices[i].left
        right = dge_voices[i].right
        f = 0
        while (f < frames) {
            sample = int(c2da_mem[data + int(pos)]) - 128
            if (f < kept) {
                dge_audio_sum[f * 2] += sample * left
                dge_audio_sum[f * 2 + 1] += sample * right
            }
            frac += step
            pos += frac >> 16u
            frac &= 0xffffu
            if (pos >= length_0) {
                data = 0
                break
            }
            f++
        }
        dge_voices[i].data = data
        dge_voices[i].pos = pos
        dge_voices[i].frac = frac
    }
    f = 0
    for (c2da_f in range(f, kept * 2)) {
        value = 0
        if (active != 0) {
            value = dge_audio_sum[c2da_f]
            value = value < -32768 ? -32768 : value > 32767 ? 32767 : value
        }
        let c2da_fresh0 : int16 = int16(value)
        let c2da_fresh1 : uint = uint(c2da_fresh0)
        c2da_mem[378720 + (dge_audio_count * 2 + c2da_f) * 2] = uint8(c2da_fresh1)
        c2da_mem[378720 + (dge_audio_count * 2 + c2da_f) * 2 + 1] = uint8(c2da_fresh1 >> 0x8)
        magnitude = value < 0 ? -value : value
        if (magnitude > dge_audio_peak_abs) {
            dge_audio_peak_abs = magnitude
        }
    }
    dge_audio_count += kept
    dge_audio_drop += uint(frames - kept)
    dge_audio_total += uint(frames)
    return
}
var private dge_audio_total : uint = 0u

var private dge_audio_drop : uint = 0u

var private dge_audio_count : int = 0

var private dge_audio_peak_abs : int = 0

var private dge_audio_sum : int[8192]

var private dge_voices : dge_voice_t[16]

var private dge_audio_acc : uint = 0u

[sideeffects]
def private dge_sound_playing(var channel : int) : uint {
    if (channel < 0 || channel >= 16) {
        return 0u
    }
    return uint(dge_voices[channel].data != 0 ? 1 : 0)
}
[sideeffects]
def private dge_sound_stop(var channel_0 : int) {
    if (channel_0 >= 0 && channel_0 < 16) {
        dge_voices[channel_0].data = 0
    }
    return
}
[sideeffects]
def private dge_sound_start(var sfxinfo : int; var channel_1 : int; var vol : int; var sep : int) : int {
    var data_0 : int
    var lumplen : uint
    var rate : uint
    var length_1 : uint
    if (channel_1 < 0 || channel_1 >= 16) {
        return -1
    }
    dge_voices[channel_1].data = 0
    if (int(uint(c2da_mem[sfxinfo + 44]) | uint(c2da_mem[sfxinfo + 45]) << 0x8 | uint(c2da_mem[sfxinfo + 46]) << 0x10 | uint(c2da_mem[sfxinfo + 47]) << 0x18) < 0) {
        return -1
    }
    lumplen = uint(W_LumpLength(uint(int(uint(c2da_mem[sfxinfo + 44]) | uint(c2da_mem[sfxinfo + 45]) << 0x8 | uint(c2da_mem[sfxinfo + 46]) << 0x10 | uint(c2da_mem[sfxinfo + 47]) << 0x18))))
    data_0 = W_CacheLumpNum(int(uint(c2da_mem[sfxinfo + 44]) | uint(c2da_mem[sfxinfo + 45]) << 0x8 | uint(c2da_mem[sfxinfo + 46]) << 0x10 | uint(c2da_mem[sfxinfo + 47]) << 0x18), 1)
    if (lumplen < 8u || int(c2da_mem[data_0 + 0]) != 3 || int(c2da_mem[data_0 + 1]) != 0) {
        return -1
    }
    rate = uint(c2da_mem[data_0 + 2]) | uint(c2da_mem[data_0 + 3]) << 8u
    length_1 = uint(c2da_mem[data_0 + 4]) | uint(c2da_mem[data_0 + 5]) << 8u | uint(c2da_mem[data_0 + 6]) << 16u | uint(c2da_mem[data_0 + 7]) << 24u
    if (length_1 > lumplen - 8u || length_1 <= 48u || rate == 0u) {
        return -1
    }
    dge_voices[channel_1].data = data_0 + 8 + 16
    dge_voices[channel_1].length = length_1 - 32u
    dge_voices[channel_1].pos = 0u
    dge_voices[channel_1].frac = 0u
    dge_voices[channel_1].step = (rate << 16u) / 11025u
    dge_sound_params(channel_1, vol, sep)
    dge_sound_starts++
    return channel_1
}
var private dge_sound_starts : int = 0

[sideeffects]
def private dge_sound_params(var channel_2 : int; var vol_0 : int; var sep_0 : int) {
    var left_0 : int
    var right_0 : int
    if (channel_2 < 0 || channel_2 >= 16) {
        return
    }
    left_0 = (254 - sep_0) * vol_0 / 127
    right_0 = sep_0 * vol_0 / 127
    dge_voices[channel_2].left = left_0 < 0 ? 0 : left_0 > 255 ? 255 : left_0
    dge_voices[channel_2].right = right_0 < 0 ? 0 : right_0 > 255 ? 255 : right_0
    return
}
[sideeffects]
def private dge_sound_update() {
    return
}
[sideeffects]
def private dge_sound_lump(var sfx : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = dge_sound_lump_c2da_frame(sfx, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
var private dge_sfx_prefix : uint = 1u

[sideeffects]
def private dge_sound_shutdown() {
    return
}
[sideeffects]
def private dge_sound_init(var use_sfx_prefix : uint) : uint {
    dge_sfx_prefix = uint(use_sfx_prefix)  // nolint:PERF020
    for (i_1 in range(0, 16)) {
        dge_voices[i_1].data = 0
    }
    return 1u
}
[sideeffects]
def private dge_music_void() {
    return
}
[sideeffects]
def private dge_music_playing() : uint {
    return 0u
}
[sideeffects]
def private dge_music_play(var handle : int; var looping : uint) {
    return
}
[sideeffects]
def private dge_music_unregister(var handle_0 : int) {
    return
}
[sideeffects]
def private dge_music_register(var data_1 : int; var len : int) : int {
    return 0
}
[sideeffects]
def private dge_music_volume(var volume : int) {
    return
}
[sideeffects]
def private dge_music_init() : uint {
    return 0u
}
[export, sideeffects]
def dge_audio_rate() : int {
    return 11025
}
[export, sideeffects]
def dge_audio_buffer() : uint {
    return 378720u
}
[export, sideeffects]
def dge_audio_frames() : int {
    return dge_audio_count
}
[export, sideeffects]
def dge_audio_consume() {
    dge_audio_count = 0
    return
}
[export, sideeffects]
def dge_audio_peak() : int {
    return dge_audio_peak_abs
}
[export, sideeffects]
def dge_audio_mixed() : uint {
    return dge_audio_total
}
[export, sideeffects]
def dge_audio_dropped() : uint {
    return dge_audio_drop
}
[export, sideeffects]
def dge_audio_starts() : int {
    return dge_sound_starts
}
[sideeffects]
def private dge_sound_lump_c2da_frame(var sfx : int; c2da_fp : int) : int {
    var at : int
    var i_0 : int
    at = 0
    if (int(uint(c2da_mem[sfx + 24]) | uint(c2da_mem[sfx + 25]) << 0x8 | uint(c2da_mem[sfx + 26]) << 0x10 | uint(c2da_mem[sfx + 27]) << 0x18) != 0) {
        sfx = int(uint(c2da_mem[sfx + 24]) | uint(c2da_mem[sfx + 25]) << 0x8 | uint(c2da_mem[sfx + 26]) << 0x10 | uint(c2da_mem[sfx + 27]) << 0x18)
    }
    if (dge_sfx_prefix != 0x0) {
        let c2da_postinc : int = at
        at++
        let c2da_fresh2 : int8 = int8(100)
        c2da_mem[c2da_fp + c2da_postinc] = uint8(c2da_fresh2)
        let c2da_postinc_0 : int = at
        at++
        let c2da_fresh3 : int8 = int8(115)
        c2da_mem[c2da_fp + c2da_postinc_0] = uint8(c2da_fresh3)
    }
    i_0 = 0
    while (int(int8(c2da_mem[sfx + 8 + i_0])) != 0 && at < 8) {
        let c2da_postinc_1 : int = at
        at++
        let c2da_fresh4 : int8 = int8(c2da_mem[sfx + 8 + i_0])
        c2da_mem[c2da_fp + c2da_postinc_1] = uint8(c2da_fresh4)
        i_0++
    }
    let c2da_fresh5 : int8 = int8(0)
    c2da_mem[c2da_fp + at] = uint8(c2da_fresh5)
    return W_CheckNumForName(c2da_fp)
}

// This unit's static data, at heap offset 378688.
let private c2da_lin_static_dg_eden_sound_seg = fixed_array<int>(378688, 21)
let private c2da_lin_static_dg_eden_sound = fixed_array<uint64>(0x400000003ul, 0x600000005ul, 0x900000007ul)

[init]
def private c2da_lin_init_static_dg_eden_sound() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_dg_eden_sound_seg[s * 2]
        for (k in range(c2da_lin_static_dg_eden_sound_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_dg_eden_sound[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_dg_eden_sound_0 = fixed_array<uint8>(0x40, 0xc7, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xba, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_dg_eden_sound_1 = fixed_array<uint8>(0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbd, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_dg_eden_sound_3 = fixed_array<uint8>(0x66, 0x66, 0x26, 0x3f)

[init]
def private c2da_lin_init_externs_dg_eden_sound() {
    c2da_lin_setup()
    for (i in range(88)) {
        c2da_mem[42160 + i] = c2da_lin_extern_dg_eden_sound_0[i]
    }
    for (i in range(104)) {
        c2da_mem[42048 + i] = c2da_lin_extern_dg_eden_sound_1[i]
    }
    for (i in range(4)) {
        c2da_mem[42368 + i] = c2da_lin_extern_dg_eden_sound_3[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_dg_eden_sound() {
    if (length(c2da_fn_table0) < 194) {
        resize(c2da_fn_table0, 194)
    }
    c2da_fn_table0[180] = @@dge_sound_shutdown
    c2da_fn_table0[182] = @@dge_sound_update
    c2da_fn_table0[188] = @@dge_music_void
    if (length(c2da_fn_table2) < 194) {
        resize(c2da_fn_table2, 194)
    }
    c2da_fn_table2[187] = @@dge_music_init
    c2da_fn_table2[193] = @@dge_music_playing
    if (length(c2da_fn_table5) < 194) {
        resize(c2da_fn_table5, 194)
    }
    c2da_fn_table5[185] = @@dge_sound_stop
    c2da_fn_table5[189] = @@dge_music_volume
    c2da_fn_table5[191] = @@dge_music_unregister
    if (length(c2da_fn_table6) < 194) {
        resize(c2da_fn_table6, 194)
    }
    c2da_fn_table6[179] = @@dge_sound_init
    if (length(c2da_fn_table7) < 194) {
        resize(c2da_fn_table7, 194)
    }
    c2da_fn_table7[181] = @@dge_sound_lump
    if (length(c2da_fn_table8) < 194) {
        resize(c2da_fn_table8, 194)
    }
    c2da_fn_table8[183] = @@dge_sound_params
    if (length(c2da_fn_table9) < 194) {
        resize(c2da_fn_table9, 194)
    }
    c2da_fn_table9[184] = @@dge_sound_start
    if (length(c2da_fn_table10) < 194) {
        resize(c2da_fn_table10, 194)
    }
    c2da_fn_table10[186] = @@dge_sound_playing
    if (length(c2da_fn_table11) < 194) {
        resize(c2da_fn_table11, 194)
    }
    c2da_fn_table11[190] = @@dge_music_register
    if (length(c2da_fn_table12) < 194) {
        resize(c2da_fn_table12, 194)
    }
    c2da_fn_table12[192] = @@dge_music_play
}

[init]
def private c2da_lin_relink_init_dg_eden_sound() {
    c2da_relink_dg_eden_sound()
}
