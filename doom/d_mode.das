options gen2
options solid_context = true
options stack = 4194304
module d_mode public

require dasdoom_runtime
var private c2da_str_0 : array<int8> = [int8(110), int8(111), int8(110), int8(101), int8(0)]

var private c2da_str_1 : array<int8> = [int8(100), int8(111), int8(111), int8(109), int8(0)]

var private c2da_str_2 : array<int8> = [int8(100), int8(111), int8(111), int8(109), int8(50), int8(0)]

var private c2da_str_3 : array<int8> = [int8(116), int8(110), int8(116), int8(0)]

var private c2da_str_4 : array<int8> = [int8(112), int8(108), int8(117), int8(116), int8(111), int8(110), int8(105), int8(97), int8(0)]

var private c2da_str_5 : array<int8> = [int8(104), int8(97), int8(99), int8(120), int8(0)]

var private c2da_str_6 : array<int8> = [int8(99), int8(104), int8(101), int8(120), int8(0)]

var private c2da_str_7 : array<int8> = [int8(104), int8(101), int8(114), int8(101), int8(116), int8(105), int8(99), int8(0)]

var private c2da_str_8 : array<int8> = [int8(104), int8(101), int8(120), int8(101), int8(110), int8(0)]

var private c2da_str_9 : array<int8> = [int8(115), int8(116), int8(114), int8(105), int8(102), int8(101), int8(0)]

[export, sideeffects]
def D_ValidGameMode(var mission : GameMission_t; var mode : GameMode_t) : uint {
    var i : int = 0
    while (uint64(i) < 208ul / 16ul) {
        if (uint(valid_modes[i].mode) == uint(mode) && uint(valid_modes[i].mission) == uint(mission)) {
            return 1u
        }
        i++
    }
    return 0u
}
var private valid_modes : Unnamed_d_mode_26[13] = fixed_array<Unnamed_d_mode_26>(Unnamed_d_mode_26(mission = unsafe(reinterpret<GameMission_t>(4u)), mode = unsafe(reinterpret<GameMode_t>(0u)), episode = 1, map = 5), Unnamed_d_mode_26(mission = unsafe(reinterpret<GameMission_t>(0u)), mode = unsafe(reinterpret<GameMode_t>(0u)), episode = 1, map = 9), Unnamed_d_mode_26(mission = unsafe(reinterpret<GameMission_t>(0u)), mode = unsafe(reinterpret<GameMode_t>(1u)), episode = 3, map = 9), Unnamed_d_mode_26(mission = unsafe(reinterpret<GameMission_t>(0u)), mode = unsafe(reinterpret<GameMode_t>(3u)), episode = 4, map = 9), Unnamed_d_mode_26(mission = unsafe(reinterpret<GameMission_t>(1u)), mode = unsafe(reinterpret<GameMode_t>(2u)), episode = 1, map = 32), Unnamed_d_mode_26(mission = unsafe(reinterpret<GameMission_t>(2u)), mode = unsafe(reinterpret<GameMode_t>(2u)), episode = 1, map = 32), Unnamed_d_mode_26(mission = unsafe(reinterpret<GameMission_t>(3u)), mode = unsafe(reinterpret<GameMode_t>(2u)), episode = 1, map = 32), Unnamed_d_mode_26(mission = unsafe(reinterpret<GameMission_t>(5u)), mode = unsafe(reinterpret<GameMode_t>(2u)), episode = 1, map = 32), Unnamed_d_mode_26(mission = unsafe(reinterpret<GameMission_t>(6u)), mode = unsafe(reinterpret<GameMode_t>(0u)), episode = 1, map = 9), Unnamed_d_mode_26(mission = unsafe(reinterpret<GameMission_t>(6u)), mode = unsafe(reinterpret<GameMode_t>(1u)), episode = 3, map = 9), Unnamed_d_mode_26(mission = unsafe(reinterpret<GameMission_t>(6u)), mode = unsafe(reinterpret<GameMode_t>(3u)), episode = 5, map = 9), Unnamed_d_mode_26(mission = unsafe(reinterpret<GameMission_t>(7u)), mode = unsafe(reinterpret<GameMode_t>(2u)), episode = 1, map = 60), Unnamed_d_mode_26(mission = unsafe(reinterpret<GameMission_t>(8u)), mode = unsafe(reinterpret<GameMode_t>(2u)), episode = 1, map = 34))

[export, sideeffects]
def D_ValidGameVersion(var mission_0 : GameMission_t; var version : GameVersion_t) : uint {
    var i_0 : int
    if (uint(mission_0) == 1u || uint(mission_0) == 3u || uint(mission_0) == 2u || uint(mission_0) == 5u || uint(mission_0) == 4u) {
        mission_0 = unsafe(reinterpret<GameMission_t>(0u))
    }
    i_0 = 0
    while (uint64(i_0) < 80ul / 8ul) {
        if (uint(valid_versions[i_0].mission) == uint(mission_0) && uint(valid_versions[i_0].version) == uint(version)) {
            return 1u
        }
        i_0++
    }
    return 0u
}
var private valid_versions : Unnamed_d_mode_119[10] = fixed_array<Unnamed_d_mode_119>(Unnamed_d_mode_119(mission = unsafe(reinterpret<GameMission_t>(0u)), version = unsafe(reinterpret<GameVersion_t>(4u))), Unnamed_d_mode_119(mission = unsafe(reinterpret<GameMission_t>(0u)), version = unsafe(reinterpret<GameVersion_t>(5u))), Unnamed_d_mode_119(mission = unsafe(reinterpret<GameMission_t>(0u)), version = unsafe(reinterpret<GameVersion_t>(6u))), Unnamed_d_mode_119(mission = unsafe(reinterpret<GameMission_t>(0u)), version = unsafe(reinterpret<GameVersion_t>(7u))), Unnamed_d_mode_119(mission = unsafe(reinterpret<GameMission_t>(0u)), version = unsafe(reinterpret<GameVersion_t>(8u))), Unnamed_d_mode_119(mission = unsafe(reinterpret<GameMission_t>(0u)), version = unsafe(reinterpret<GameVersion_t>(9u))), Unnamed_d_mode_119(mission = unsafe(reinterpret<GameMission_t>(6u)), version = unsafe(reinterpret<GameVersion_t>(10u))), Unnamed_d_mode_119(mission = unsafe(reinterpret<GameMission_t>(7u)), version = unsafe(reinterpret<GameVersion_t>(11u))), Unnamed_d_mode_119(mission = unsafe(reinterpret<GameMission_t>(8u)), version = unsafe(reinterpret<GameVersion_t>(12u))), Unnamed_d_mode_119(mission = unsafe(reinterpret<GameMission_t>(8u)), version = unsafe(reinterpret<GameVersion_t>(13u))))

[export, sideeffects]
def D_ValidEpisodeMap(var mission_1 : GameMission_t; var mode_0 : GameMode_t; var episode : int; var map : int) : uint {
    var i_1 : int
    if (uint(mission_1) == 6u) {
        if (uint(mode_0) == 3u && episode == 6) {
            return uint(map >= 1 && map <= 3 ? 1 : 0)
        } elif (uint(mode_0) == 1u && episode == 4) {
            return uint(map == 1 ? 1 : 0)
        }
    }
    i_1 = 0
    while (uint64(i_1) < 208ul / 16ul) {
        if (uint(mission_1) == uint(valid_modes[i_1].mission) && uint(mode_0) == uint(valid_modes[i_1].mode)) {
            return uint(episode >= 1 && episode <= valid_modes[i_1].episode && map >= 1 && map <= valid_modes[i_1].map ? 1 : 0)
        }
        i_1++
    }
    return 0u
}
[export, sideeffects]
def D_GetNumEpisodes(var mission_2 : GameMission_t; var mode_1 : GameMode_t) : int {
    var episode_0 : int = 1
    while (D_ValidEpisodeMap(mission_2, mode_1, episode_0, 1) != 0x0) {
        episode_0++
    }
    return episode_0 - 1
}
[export, sideeffects]
def D_IsEpisodeMap(var mission_3 : GameMission_t) : uint {
    let c2da_fresh0 : uint = uint(mission_3)
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
def D_GameMissionString(var mission_4 : GameMission_t) : int8? {
    let c2da_fresh1 : uint = uint(mission_4)
    if (c2da_fresh1 <= 0x9u) {
        goto int(c2da_fresh1) + 1
    }
    goto label 0
    label 0:
    label 10:
    return unsafe(addr<int8?>(c2da_str_0[0]))
    label 1:
    return unsafe(addr<int8?>(c2da_str_1[0]))
    label 2:
    return unsafe(addr<int8?>(c2da_str_2[0]))
    label 3:
    return unsafe(addr<int8?>(c2da_str_3[0]))
    label 4:
    return unsafe(addr<int8?>(c2da_str_4[0]))
    label 6:
    return unsafe(addr<int8?>(c2da_str_5[0]))
    label 5:
    return unsafe(addr<int8?>(c2da_str_6[0]))
    label 7:
    return unsafe(addr<int8?>(c2da_str_7[0]))
    label 8:
    return unsafe(addr<int8?>(c2da_str_8[0]))
    label 9:
    return unsafe(addr<int8?>(c2da_str_9[0]))
}
[sideeffects]
def private c2da_layout_proofs() {
    static_assert(typeinfo sizeof(type<Unnamed_d_mode_26>) == 16, "C layout of Unnamed_d_mode_26: sizeof")
    static_assert(typeinfo alignof(type<Unnamed_d_mode_26>) == 4, "C layout of Unnamed_d_mode_26: alignof")
    static_assert(typeinfo offsetof<mission>(type<Unnamed_d_mode_26>) == 0, "C layout of Unnamed_d_mode_26: offsetof mission")
    static_assert(typeinfo offsetof<mode>(type<Unnamed_d_mode_26>) == 4, "C layout of Unnamed_d_mode_26: offsetof mode")
    static_assert(typeinfo offsetof<episode>(type<Unnamed_d_mode_26>) == 8, "C layout of Unnamed_d_mode_26: offsetof episode")
    static_assert(typeinfo offsetof<map>(type<Unnamed_d_mode_26>) == 12, "C layout of Unnamed_d_mode_26: offsetof map")
    static_assert(typeinfo sizeof(type<Unnamed_d_mode_119>) == 8, "C layout of Unnamed_d_mode_119: sizeof")
    static_assert(typeinfo alignof(type<Unnamed_d_mode_119>) == 4, "C layout of Unnamed_d_mode_119: alignof")
    static_assert(typeinfo offsetof<mission>(type<Unnamed_d_mode_119>) == 0, "C layout of Unnamed_d_mode_119: offsetof mission")
    static_assert(typeinfo offsetof<version>(type<Unnamed_d_mode_119>) == 4, "C layout of Unnamed_d_mode_119: offsetof version")
}
