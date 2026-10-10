var private c2da_str_p_plats_0 : array<int8> = [int8(80), int8(95), int8(82), int8(101), int8(109), int8(111), int8(118), int8(101), int8(65), int8(99), int8(116), int8(105), int8(118), int8(101), int8(80), int8(108), int8(97), int8(116), int8(58), int8(32), int8(99), int8(97), int8(110), int8(39), int8(116), int8(32), int8(102), int8(105), int8(110), int8(100), int8(32), int8(112), int8(108), int8(97), int8(116), int8(33), int8(0)]

var private c2da_str_p_plats_1 : array<int8> = [int8(80), int8(95), int8(65), int8(100), int8(100), int8(65), int8(99), int8(116), int8(105), int8(118), int8(101), int8(80), int8(108), int8(97), int8(116), int8(58), int8(32), int8(110), int8(111), int8(32), int8(109), int8(111), int8(114), int8(101), int8(32), int8(112), int8(108), int8(97), int8(116), int8(115), int8(33), int8(0)]

var activeplats : plat_t? [30]

[export, sideeffects]
def T_PlatRaise(var plat : plat_t?) {
    var c2da_fresh0 : uint
    var c2da_fresh4 : uint
    var res : result_e = result_e()
    var c2da_postinc : int
    c2da_fresh0 = uint(plat.status)
    if (c2da_fresh0 == 0x0u) {
        goto label 0
    } elif (c2da_fresh0 == 0x1u) {
        goto label 1
    } elif (c2da_fresh0 == 0x2u) {
        goto label 2
    } elif (c2da_fresh0 == 0x3u) {
        return
    } else {
        return
    }
    label 0:
    res = T_MovePlane(plat.sector, plat.speed, plat.high, plat.crush, 0, 1)
    if (uint(plat.type_0) == 2u || uint(plat.type_0) == 3u) {
        if ((leveltime & 7) == 0) {
            var c2da_fresh1 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(plat.sector)) + 48ul))
            S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh1)), 22)
        }
    }
    if (uint(res) == 1u && plat.crush == 0) {
        plat.count = int(plat.wait)  // nolint:PERF020
        plat.status = unsafe(reinterpret<plat_e>(1u))
        var c2da_fresh2 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(plat.sector)) + 48ul))
        S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh2)), 18)
    } elif (uint(res) == 2u) {
        plat.count = int(plat.wait)  // nolint:PERF020
        plat.status = unsafe(reinterpret<plat_e>(2u))
        var c2da_fresh3 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(plat.sector)) + 48ul))
        S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh3)), 19)
        c2da_fresh4 = uint(plat.type_0)
        if (c2da_fresh4 == 0x4u || c2da_fresh4 == 0x1u) {
            P_RemoveActivePlat(plat)
        } elif (c2da_fresh4 == 0x2u || c2da_fresh4 == 0x3u) {
            P_RemoveActivePlat(plat)
        }
    }
    return
    label 1:
    res = T_MovePlane(plat.sector, plat.speed, plat.low, 0u, 0, -1)
    if (uint(res) == 2u) {
        plat.count = int(plat.wait)  // nolint:PERF020
        plat.status = unsafe(reinterpret<plat_e>(2u))
        var c2da_fresh5 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(plat.sector)) + 48ul))
        S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh5)), 19)
    }
    return
    label 2:
    c2da_postinc = plat.count
    plat.count = c2da_postinc - 1
    if (c2da_postinc - 1 == 0) {
        if (plat.sector.floorheight == plat.low) {
            plat.status = unsafe(reinterpret<plat_e>(0u))
        } else {
            plat.status = unsafe(reinterpret<plat_e>(1u))
        }
        var c2da_fresh6 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(plat.sector)) + 48ul))
        S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh6)), 18)
    }
    return
}
[export, sideeffects]
def P_RemoveActivePlat(var plat_0 : plat_t?) {
    for (i in range(0, 30)) {
        if (plat_0 == activeplats[i]) {
            activeplats[i].sector.specialdata = null
            var c2da_fresh7 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(activeplats[i]))))
            P_RemoveThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh7)))
            activeplats[i] = null
            return
        }
    }
    I_Error(unsafe(addr<int8?>(c2da_str_p_plats_0[0])), [])
    return
}
[export, sideeffects]
def EV_DoPlat(var line : line_s?; var type_0 : plattype_e; var amount : int) : int {
    var c2da_fresh8 : uint
    var c2da_fresh10 : uint
    var plat_1 : plat_t?
    var secnum : int
    var rtn : int
    var sec : sector_t?
    secnum = -1
    rtn = 0
    c2da_fresh8 = uint(type_0)
    if (c2da_fresh8 == 0x0u) {
        P_ActivateInStasis(int(line.tag))
    }
    while (true) {
        secnum = P_FindSectorFromLineTag(line, secnum)
        if (secnum < 0) {
            break
        }
        sec = unsafe(addr<sector_t?>(unsafe(sectors[secnum])))
        if (sec.specialdata != null) {
            continue
        }
        rtn = 1
        plat_1 = unsafe(reinterpret<plat_t?>(unsafe(reinterpret<plat_t?>(Z_Malloc(72, 6, null)))))
        var c2da_fresh9 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(plat_1))))
        P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh9)))
        plat_1.type_0 = type_0
        plat_1.sector = sec
        plat_1.sector.specialdata = unsafe(reinterpret<uint8?>(plat_1))
        unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(plat_1))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_PlatRaise))
        plat_1.crush = 0u
        plat_1.tag = int(line.tag)
        c2da_fresh10 = uint(type_0)
        if (c2da_fresh10 == 0x3u) {
            plat_1.speed = (1 << 16) / 2
            var c2da_fresh11 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(line)) + 30ul))
            sec.floorpic = unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh11))[0]))]).sector.floorpic
            plat_1.high = P_FindNextHighestFloor(sec, sec.floorheight)
            plat_1.wait = 0
            plat_1.status = unsafe(reinterpret<plat_e>(0u))
            sec.special = int16(0)
            var c2da_fresh12 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(sec)) + 48ul))
            S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh12)), 22)
        } elif (c2da_fresh10 == 0x2u) {
            plat_1.speed = (1 << 16) / 2
            var c2da_fresh13 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(line)) + 30ul))
            sec.floorpic = unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh13))[0]))]).sector.floorpic
            plat_1.high = sec.floorheight + amount * (1 << 16)
            plat_1.wait = 0
            plat_1.status = unsafe(reinterpret<plat_e>(0u))
            var c2da_fresh14 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(sec)) + 48ul))
            S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh14)), 22)
        } elif (c2da_fresh10 == 0x1u) {
            plat_1.speed = (1 << 16) * 4
            plat_1.low = P_FindLowestFloorSurrounding(sec)
            if (plat_1.low > sec.floorheight) {
                plat_1.low = int(sec.floorheight)  // nolint:PERF020
            }
            plat_1.high = int(sec.floorheight)  // nolint:PERF020
            plat_1.wait = 35 * 3
            plat_1.status = unsafe(reinterpret<plat_e>(1u))
            var c2da_fresh15 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(sec)) + 48ul))
            S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh15)), 18)
        } elif (c2da_fresh10 == 0x4u) {
            plat_1.speed = (1 << 16) * 8
            plat_1.low = P_FindLowestFloorSurrounding(sec)
            if (plat_1.low > sec.floorheight) {
                plat_1.low = int(sec.floorheight)  // nolint:PERF020
            }
            plat_1.high = int(sec.floorheight)  // nolint:PERF020
            plat_1.wait = 35 * 3
            plat_1.status = unsafe(reinterpret<plat_e>(1u))
            var c2da_fresh16 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(sec)) + 48ul))
            S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh16)), 18)
        } elif (c2da_fresh10 == 0x0u) {
            plat_1.speed = 1 << 16
            plat_1.low = P_FindLowestFloorSurrounding(sec)
            if (plat_1.low > sec.floorheight) {
                plat_1.low = int(sec.floorheight)  // nolint:PERF020
            }
            plat_1.high = P_FindHighestFloorSurrounding(sec)
            if (plat_1.high < sec.floorheight) {
                plat_1.high = int(sec.floorheight)  // nolint:PERF020
            }
            plat_1.wait = 35 * 3
            plat_1.status = unsafe(reinterpret<plat_e>(uint(P_Random() & 1)))
            var c2da_fresh17 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(sec)) + 48ul))
            S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh17)), 18)
        }
        P_AddActivePlat(plat_1)
    }
    return rtn
}
[export, sideeffects]
def P_AddActivePlat(var plat_2 : plat_t?) {
    for (i_0 in range(0, 30)) {
        if (activeplats[i_0] == null) {
            activeplats[i_0] = unsafe(reinterpret<plat_t?>(plat_2))
            return
        }
    }
    I_Error(unsafe(addr<int8?>(c2da_str_p_plats_1[0])), [])
    return
}
[export, sideeffects]
def P_ActivateInStasis(var tag : int) {
    for (i_1 in range(0, 30)) {
        if (activeplats[i_1] != null && activeplats[i_1].tag == tag && uint(activeplats[i_1].status) == 3u) {
            activeplats[i_1].status = activeplats[i_1].oldstatus
            unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(activeplats[i_1]))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_PlatRaise))
        }
    }
    return
}
[export, sideeffects]
def EV_StopPlat(var line_0 : line_s?) {
    for (j in range(0, 30)) {
        if (activeplats[j] != null && uint(activeplats[j].status) != 3u && activeplats[j].tag == int(line_0.tag)) {
            activeplats[j].oldstatus = activeplats[j].status
            activeplats[j].status = unsafe(reinterpret<plat_e>(3u))
            unsafe(unsafe(reinterpret<actionf_v?>(unsafe(reinterpret<uint64>(activeplats[j]))))[2]) = unsafe(reinterpret<actionf_v>(null))
        }
    }
    return
}
[sideeffects]
def private c2da_layout_proofs_19() {
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
    static_assert(typeinfo sizeof(type<pspdef_t>) == 24, "C layout of pspdef_t: sizeof")
    static_assert(typeinfo alignof(type<pspdef_t>) == 8, "C layout of pspdef_t: alignof")
    static_assert(typeinfo offsetof<state>(type<pspdef_t>) == 0, "C layout of pspdef_t: offsetof state")
    static_assert(typeinfo offsetof<tics>(type<pspdef_t>) == 8, "C layout of pspdef_t: offsetof tics")
    static_assert(typeinfo offsetof<sx>(type<pspdef_t>) == 12, "C layout of pspdef_t: offsetof sx")
    static_assert(typeinfo offsetof<sy>(type<pspdef_t>) == 16, "C layout of pspdef_t: offsetof sy")
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
    static_assert(typeinfo sizeof(type<side_t>) == 24, "C layout of side_t: sizeof")
    static_assert(typeinfo alignof(type<side_t>) == 8, "C layout of side_t: alignof")
    static_assert(typeinfo offsetof<textureoffset>(type<side_t>) == 0, "C layout of side_t: offsetof textureoffset")
    static_assert(typeinfo offsetof<rowoffset>(type<side_t>) == 4, "C layout of side_t: offsetof rowoffset")
    static_assert(typeinfo offsetof<toptexture>(type<side_t>) == 8, "C layout of side_t: offsetof toptexture")
    static_assert(typeinfo offsetof<bottomtexture>(type<side_t>) == 10, "C layout of side_t: offsetof bottomtexture")
    static_assert(typeinfo offsetof<midtexture>(type<side_t>) == 12, "C layout of side_t: offsetof midtexture")
    static_assert(typeinfo offsetof<sector>(type<side_t>) == 16, "C layout of side_t: offsetof sector")
    static_assert(typeinfo sizeof(type<line_t>) == 88, "C layout of line_t: sizeof")
    static_assert(typeinfo alignof(type<line_t>) == 8, "C layout of line_t: alignof")
    static_assert(typeinfo offsetof<v1>(type<line_t>) == 0, "C layout of line_t: offsetof v1")
    static_assert(typeinfo offsetof<v2>(type<line_t>) == 8, "C layout of line_t: offsetof v2")
    static_assert(typeinfo offsetof<dx>(type<line_t>) == 16, "C layout of line_t: offsetof dx")
    static_assert(typeinfo offsetof<dy>(type<line_t>) == 20, "C layout of line_t: offsetof dy")
    static_assert(typeinfo offsetof<flags>(type<line_t>) == 24, "C layout of line_t: offsetof flags")
    static_assert(typeinfo offsetof<special>(type<line_t>) == 26, "C layout of line_t: offsetof special")
    static_assert(typeinfo offsetof<tag>(type<line_t>) == 28, "C layout of line_t: offsetof tag")
    static_assert(typeinfo offsetof<sidenum>(type<line_t>) == 30, "C layout of line_t: offsetof sidenum")
    static_assert(typeinfo offsetof<bbox>(type<line_t>) == 36, "C layout of line_t: offsetof bbox")
    static_assert(typeinfo offsetof<slopetype>(type<line_t>) == 52, "C layout of line_t: offsetof slopetype")
    static_assert(typeinfo offsetof<frontsector>(type<line_t>) == 56, "C layout of line_t: offsetof frontsector")
    static_assert(typeinfo offsetof<backsector>(type<line_t>) == 64, "C layout of line_t: offsetof backsector")
    static_assert(typeinfo offsetof<validcount>(type<line_t>) == 72, "C layout of line_t: offsetof validcount")
    static_assert(typeinfo offsetof<specialdata>(type<line_t>) == 80, "C layout of line_t: offsetof specialdata")
    static_assert(typeinfo sizeof(type<plat_t>) == 72, "C layout of plat_t: sizeof")
    static_assert(typeinfo alignof(type<plat_t>) == 8, "C layout of plat_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<plat_t>) == 0, "C layout of plat_t: offsetof thinker")
    static_assert(typeinfo offsetof<sector>(type<plat_t>) == 24, "C layout of plat_t: offsetof sector")
    static_assert(typeinfo offsetof<speed>(type<plat_t>) == 32, "C layout of plat_t: offsetof speed")
    static_assert(typeinfo offsetof<low>(type<plat_t>) == 36, "C layout of plat_t: offsetof low")
    static_assert(typeinfo offsetof<high>(type<plat_t>) == 40, "C layout of plat_t: offsetof high")
    static_assert(typeinfo offsetof<wait>(type<plat_t>) == 44, "C layout of plat_t: offsetof wait")
    static_assert(typeinfo offsetof<count>(type<plat_t>) == 48, "C layout of plat_t: offsetof count")
    static_assert(typeinfo offsetof<status>(type<plat_t>) == 52, "C layout of plat_t: offsetof status")
    static_assert(typeinfo offsetof<oldstatus>(type<plat_t>) == 56, "C layout of plat_t: offsetof oldstatus")
    static_assert(typeinfo offsetof<crush>(type<plat_t>) == 60, "C layout of plat_t: offsetof crush")
    static_assert(typeinfo offsetof<tag>(type<plat_t>) == 64, "C layout of plat_t: offsetof tag")
    static_assert(typeinfo offsetof<type_0>(type<plat_t>) == 68, "C layout of plat_t: offsetof type_0")
}
