options gen2
options stack = 4194304
module d_mode public

require dasdoom_runtime
require daslib/math_bits
[export, sideeffects]
def D_ValidGameMode(var mission : uint; var mode : uint) : uint {
    var i : int = 0
    while (uint64(i) < 208ul / 16ul) {
        if ((uint(c2da_mem[327840 + i * 16 + 4]) | uint(c2da_mem[327840 + i * 16 + 5]) << 0x8 | uint(c2da_mem[327840 + i * 16 + 6]) << 0x10 | uint(c2da_mem[327840 + i * 16 + 7]) << 0x18) == mode && (uint(c2da_mem[327840 + i * 16]) | uint(c2da_mem[327840 + i * 16 + 1]) << 0x8 | uint(c2da_mem[327840 + i * 16 + 2]) << 0x10 | uint(c2da_mem[327840 + i * 16 + 3]) << 0x18) == mission) {
            return 1u
        }
        i++
    }
    return 0u
}
[export, sideeffects]
def D_ValidGameVersion(var mission_0 : uint; var version : uint) : uint {
    var i_0 : int
    if (mission_0 == 1u || mission_0 == 3u || mission_0 == 2u || mission_0 == 5u || mission_0 == 4u) {
        mission_0 = 0u
    }
    i_0 = 0
    while (uint64(i_0) < 80ul / 8ul) {
        if ((uint(c2da_mem[328048 + i_0 * 8]) | uint(c2da_mem[328048 + i_0 * 8 + 1]) << 0x8 | uint(c2da_mem[328048 + i_0 * 8 + 2]) << 0x10 | uint(c2da_mem[328048 + i_0 * 8 + 3]) << 0x18) == mission_0 && (uint(c2da_mem[328048 + i_0 * 8 + 4]) | uint(c2da_mem[328048 + i_0 * 8 + 5]) << 0x8 | uint(c2da_mem[328048 + i_0 * 8 + 6]) << 0x10 | uint(c2da_mem[328048 + i_0 * 8 + 7]) << 0x18) == version) {
            return 1u
        }
        i_0++
    }
    return 0u
}
[export, sideeffects]
def D_ValidEpisodeMap(var mission_1 : uint; var mode_0 : uint; var episode : int; var map : int) : uint {
    var i_1 : int
    if (mission_1 == 6u) {
        if (mode_0 == 3u && episode == 6) {
            return uint(map >= 1 && map <= 3 ? 1 : 0)
        } elif (mode_0 == 1u && episode == 4) {
            return uint(map == 1 ? 1 : 0)
        }
    }
    i_1 = 0
    while (uint64(i_1) < 208ul / 16ul) {
        if (mission_1 == (uint(c2da_mem[327840 + i_1 * 16]) | uint(c2da_mem[327840 + i_1 * 16 + 1]) << 0x8 | uint(c2da_mem[327840 + i_1 * 16 + 2]) << 0x10 | uint(c2da_mem[327840 + i_1 * 16 + 3]) << 0x18) && mode_0 == (uint(c2da_mem[327840 + i_1 * 16 + 4]) | uint(c2da_mem[327840 + i_1 * 16 + 5]) << 0x8 | uint(c2da_mem[327840 + i_1 * 16 + 6]) << 0x10 | uint(c2da_mem[327840 + i_1 * 16 + 7]) << 0x18)) {
            return uint(episode >= 1 && episode <= int(uint(c2da_mem[327840 + i_1 * 16 + 8]) | uint(c2da_mem[327840 + i_1 * 16 + 9]) << 0x8 | uint(c2da_mem[327840 + i_1 * 16 + 10]) << 0x10 | uint(c2da_mem[327840 + i_1 * 16 + 11]) << 0x18) && map >= 1 && map <= int(uint(c2da_mem[327840 + i_1 * 16 + 12]) | uint(c2da_mem[327840 + i_1 * 16 + 13]) << 0x8 | uint(c2da_mem[327840 + i_1 * 16 + 14]) << 0x10 | uint(c2da_mem[327840 + i_1 * 16 + 15]) << 0x18) ? 1 : 0)
        }
        i_1++
    }
    return 0u
}
[export, sideeffects]
def D_GetNumEpisodes(var mission_2 : uint; var mode_1 : uint) : int {
    var episode_0 : int = 1
    while (D_ValidEpisodeMap(mission_2, mode_1, episode_0, 1) != 0x0) {
        episode_0++
    }
    return episode_0 - 1
}
[export, sideeffects]
def D_IsEpisodeMap(var mission_3 : uint) : uint {
    let c2da_fresh0 : uint = mission_3
    if (c2da_fresh0 <= 0x9u) {
        goto int(c2da_fresh0) + 1
    }
    goto label 0
    label 1:
    label 5:
    label 7:
    return 1u
    label 0:
    label 2:
    label 3:
    label 4:
    label 6:
    label 8:
    label 9:
    label 10:
    return 0u
}
[export, sideeffects]
def D_GameMissionString(var mission_4 : uint) : int {
    let c2da_fresh1 : uint = mission_4
    if (c2da_fresh1 <= 0x9u) {
        goto int(c2da_fresh1) + 1
    }
    goto label 0
    label 0:
    label 10:
    return 328128
    label 1:
    return 328133
    label 2:
    return 328138
    label 3:
    return 328144
    label 4:
    return 328148
    label 6:
    return 328157
    label 5:
    return 328162
    label 7:
    return 328167
    label 8:
    return 328175
    label 9:
    return 328181
}

// This unit's static data, at heap offset 327840.
let private c2da_lin_static_d_mode_seg = fixed_array<int>(327840, 347)
let private c2da_lin_static_d_mode = fixed_array<uint64>(0x4ul, 0x500000001ul, 0x0ul, 0x900000001ul, 0x100000000ul, 0x900000003ul, 0x300000000ul, 0x900000004ul, 0x200000001ul, 0x2000000001ul, 0x200000002ul, 0x2000000001ul, 0x200000003ul, 0x2000000001ul, 0x200000005ul, 0x2000000001ul, 0x6ul, 0x900000001ul, 0x100000006ul, 0x900000003ul, 0x300000006ul, 0x900000005ul, 0x200000007ul, 0x3c00000001ul, 0x200000008ul, 0x2200000001ul, 0x400000000ul, 0x500000000ul, 0x600000000ul, 0x700000000ul, 0x800000000ul, 0x900000000ul, 0xa00000006ul, 0xb00000007ul, 0xc00000008ul, 0xd00000008ul, 0x6f6f6400656e6f6eul, 0x326d6f6f64006dul, 0x74756c7000746e74ul, 0x6361680061696e6ful, 0x6800786568630078ul, 0x6800636974657265ul, 0x727473006e657865ul, 0x656669ul)

[init]
def private c2da_lin_init_static_d_mode() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_d_mode_seg[s * 2]
        for (k in range(c2da_lin_static_d_mode_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_d_mode[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
