[export, sideeffects]
def P_SpawnFireFlicker(var sector : sector_t?) {
    var flick : fireflicker_t?
    sector.special = int16(0)
    flick = unsafe(reinterpret<fireflicker_t?>(unsafe(reinterpret<fireflicker_t?>(Z_Malloc(48, 6, null)))))
    var c2da_fresh0 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(flick))))
    P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh0)))
    unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(flick))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_FireFlicker))
    flick.sector = sector
    flick.maxlight = int(sector.lightlevel)
    flick.minlight = P_FindMinSurroundingLight(sector, int(sector.lightlevel)) + 16
    flick.count = 4
    return
}
[export, sideeffects]
def T_FireFlicker(var flick_0 : fireflicker_t?) {
    var amount : int
    let c2da_postinc : int = flick_0.count
    flick_0.count = c2da_postinc - 1
    if (c2da_postinc - 1 != 0) {
        return
    }
    amount = (P_Random() & 3) * 16
    if (int(flick_0.sector.lightlevel) - amount < flick_0.minlight) {
        flick_0.sector.lightlevel = int16(flick_0.minlight)
    } else {
        flick_0.sector.lightlevel = int16(flick_0.maxlight - amount)
    }
    flick_0.count = 4
    return
}
[export, sideeffects]
def T_LightFlash(var flash : lightflash_t?) {
    let c2da_postinc_0 : int = flash.count
    flash.count = c2da_postinc_0 - 1
    if (c2da_postinc_0 - 1 != 0) {
        return
    }
    if (int(flash.sector.lightlevel) == flash.maxlight) {
        flash.sector.lightlevel = int16(flash.minlight)
        flash.count = (P_Random() & flash.mintime) + 1
    } else {
        flash.sector.lightlevel = int16(flash.maxlight)
        flash.count = (P_Random() & flash.maxtime) + 1
    }
    return
}
[export, sideeffects]
def P_SpawnLightFlash(var sector_0 : sector_t?) {
    var flash_0 : lightflash_t?
    sector_0.special = int16(0)
    flash_0 = unsafe(reinterpret<lightflash_t?>(unsafe(reinterpret<lightflash_t?>(Z_Malloc(56, 6, null)))))
    var c2da_fresh1 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(flash_0))))
    P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh1)))
    unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(flash_0))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_LightFlash))
    flash_0.sector = sector_0
    flash_0.maxlight = int(sector_0.lightlevel)
    flash_0.minlight = P_FindMinSurroundingLight(sector_0, int(sector_0.lightlevel))
    flash_0.maxtime = 64
    flash_0.mintime = 7
    flash_0.count = (P_Random() & flash_0.maxtime) + 1
    return
}
[export, sideeffects]
def T_StrobeFlash(var flash_1 : strobe_t?) {
    let c2da_postinc_1 : int = flash_1.count
    flash_1.count = c2da_postinc_1 - 1
    if (c2da_postinc_1 - 1 != 0) {
        return
    }
    if (int(flash_1.sector.lightlevel) == flash_1.minlight) {
        flash_1.sector.lightlevel = int16(flash_1.maxlight)
        flash_1.count = int(flash_1.brighttime)  // nolint:PERF020
    } else {
        flash_1.sector.lightlevel = int16(flash_1.minlight)
        flash_1.count = int(flash_1.darktime)  // nolint:PERF020
    }
    return
}
[export, sideeffects]
def P_SpawnStrobeFlash(var sector_1 : sector_t?; var fastOrSlow : int; var inSync : int) {
    var flash_2 : strobe_t? = unsafe(reinterpret<strobe_t?>(unsafe(reinterpret<strobe_t?>(Z_Malloc(56, 6, null)))))
    var c2da_fresh2 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(flash_2))))
    P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh2)))
    flash_2.sector = sector_1
    flash_2.darktime = int(fastOrSlow)  // nolint:PERF020
    flash_2.brighttime = 5
    unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(flash_2))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_StrobeFlash))
    flash_2.maxlight = int(sector_1.lightlevel)
    flash_2.minlight = P_FindMinSurroundingLight(sector_1, int(sector_1.lightlevel))
    if (flash_2.minlight == flash_2.maxlight) {
        flash_2.minlight = 0
    }
    sector_1.special = int16(0)
    if (inSync == 0) {
        flash_2.count = (P_Random() & 7) + 1
    } else {
        flash_2.count = 1
    }
    return
}
[export, sideeffects]
def EV_StartLightStrobing(var line : line_s?) {
    var secnum : int
    var sec : sector_t?
    secnum = -1
    while (true) {
        secnum = P_FindSectorFromLineTag(line, secnum)
        if (secnum < 0) {
            break
        }
        sec = unsafe(addr<sector_t?>(unsafe(sectors[secnum])))
        if (sec.specialdata != null) {
            continue
        }
        P_SpawnStrobeFlash(sec, 35, 0)
    }
    return
}
[export, sideeffects]
def EV_TurnTagLightsOff(var line_0 : line_s?) {
    var i : int
    var j : int
    var min : int
    var sector_2 : sector_t?
    var tsec : sector_t?
    var templine : line_s?
    sector_2 = unsafe(reinterpret<sector_t?>(sectors))
    j = 0
    while (j < numsectors) {
        if (int(sector_2.tag) == int(line_0.tag)) {
            min = int(sector_2.lightlevel)
            i = 0
            while (i < sector_2.linecount) {
                templine = unsafe(reinterpret<line_s?>(unsafe(sector_2.lines[i])))
                tsec = unsafe(reinterpret<sector_t?>(unsafe(reinterpret<sector_t?>(getNextSector(templine, sector_2)))))
                if (tsec == null) {
                    i++
                    continue
                }
                if (int(tsec.lightlevel) < min) {
                    min = int(tsec.lightlevel)
                }
                i++
            }
            sector_2.lightlevel = int16(min)
        }
        j++
        unsafe {  // nolint:STYLE025
            sector_2 += 1
        }
    }
    return
}
[export, sideeffects]
def EV_LightTurnOn(var line_1 : line_s?; var bright : int) {
    var i_0 : int
    var j_0 : int
    var sector_3 : sector_t?
    var temp : sector_t?
    var templine_0 : line_s?
    sector_3 = unsafe(reinterpret<sector_t?>(sectors))
    i_0 = 0
    while (i_0 < numsectors) {
        if (int(sector_3.tag) == int(line_1.tag)) {
            if (bright == 0) {
                j_0 = 0
                while (j_0 < sector_3.linecount) {
                    templine_0 = unsafe(reinterpret<line_s?>(unsafe(sector_3.lines[j_0])))
                    temp = unsafe(reinterpret<sector_t?>(unsafe(reinterpret<sector_t?>(getNextSector(templine_0, sector_3)))))
                    if (temp == null) {
                        j_0++
                        continue
                    }
                    if (int(temp.lightlevel) > bright) {
                        bright = int(temp.lightlevel)
                    }
                    j_0++
                }
            }
            sector_3.lightlevel = int16(bright)
        }
        i_0++
        unsafe {  // nolint:STYLE025
            sector_3 += 1
        }
    }
    return
}
[export, sideeffects]
def T_Glow(var g : glow_t?) {
    let c2da_fresh3 : int = g.direction
    if (c2da_fresh3 == -1) {
        g.sector.lightlevel = int16(int(g.sector.lightlevel) - 8)
        if (int(g.sector.lightlevel) <= g.minlight) {
            g.sector.lightlevel = int16(int(g.sector.lightlevel) + 8)
            g.direction = 1
        }
    } elif (c2da_fresh3 == 1) {
        g.sector.lightlevel = int16(int(g.sector.lightlevel) + 8)
        if (int(g.sector.lightlevel) >= g.maxlight) {
            g.sector.lightlevel = int16(int(g.sector.lightlevel) - 8)
            g.direction = -1
        }
    }
    return
}
[export, sideeffects]
def P_SpawnGlowingLight(var sector_4 : sector_t?) {
    var g_0 : glow_t? = unsafe(reinterpret<glow_t?>(unsafe(reinterpret<glow_t?>(Z_Malloc(48, 6, null)))))
    var c2da_fresh4 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(g_0))))
    P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh4)))
    g_0.sector = sector_4
    g_0.minlight = P_FindMinSurroundingLight(sector_4, int(sector_4.lightlevel))
    g_0.maxlight = int(sector_4.lightlevel)
    unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(g_0))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_Glow))
    g_0.direction = -1
    sector_4.special = int16(0)
    return
}
[sideeffects]
def private c2da_layout_proofs_15() {
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
    static_assert(typeinfo sizeof(type<fireflicker_t>) == 48, "C layout of fireflicker_t: sizeof")
    static_assert(typeinfo alignof(type<fireflicker_t>) == 8, "C layout of fireflicker_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<fireflicker_t>) == 0, "C layout of fireflicker_t: offsetof thinker")
    static_assert(typeinfo offsetof<sector>(type<fireflicker_t>) == 24, "C layout of fireflicker_t: offsetof sector")
    static_assert(typeinfo offsetof<count>(type<fireflicker_t>) == 32, "C layout of fireflicker_t: offsetof count")
    static_assert(typeinfo offsetof<maxlight>(type<fireflicker_t>) == 36, "C layout of fireflicker_t: offsetof maxlight")
    static_assert(typeinfo offsetof<minlight>(type<fireflicker_t>) == 40, "C layout of fireflicker_t: offsetof minlight")
    static_assert(typeinfo sizeof(type<lightflash_t>) == 56, "C layout of lightflash_t: sizeof")
    static_assert(typeinfo alignof(type<lightflash_t>) == 8, "C layout of lightflash_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<lightflash_t>) == 0, "C layout of lightflash_t: offsetof thinker")
    static_assert(typeinfo offsetof<sector>(type<lightflash_t>) == 24, "C layout of lightflash_t: offsetof sector")
    static_assert(typeinfo offsetof<count>(type<lightflash_t>) == 32, "C layout of lightflash_t: offsetof count")
    static_assert(typeinfo offsetof<maxlight>(type<lightflash_t>) == 36, "C layout of lightflash_t: offsetof maxlight")
    static_assert(typeinfo offsetof<minlight>(type<lightflash_t>) == 40, "C layout of lightflash_t: offsetof minlight")
    static_assert(typeinfo offsetof<maxtime>(type<lightflash_t>) == 44, "C layout of lightflash_t: offsetof maxtime")
    static_assert(typeinfo offsetof<mintime>(type<lightflash_t>) == 48, "C layout of lightflash_t: offsetof mintime")
    static_assert(typeinfo sizeof(type<strobe_t>) == 56, "C layout of strobe_t: sizeof")
    static_assert(typeinfo alignof(type<strobe_t>) == 8, "C layout of strobe_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<strobe_t>) == 0, "C layout of strobe_t: offsetof thinker")
    static_assert(typeinfo offsetof<sector>(type<strobe_t>) == 24, "C layout of strobe_t: offsetof sector")
    static_assert(typeinfo offsetof<count>(type<strobe_t>) == 32, "C layout of strobe_t: offsetof count")
    static_assert(typeinfo offsetof<minlight>(type<strobe_t>) == 36, "C layout of strobe_t: offsetof minlight")
    static_assert(typeinfo offsetof<maxlight>(type<strobe_t>) == 40, "C layout of strobe_t: offsetof maxlight")
    static_assert(typeinfo offsetof<darktime>(type<strobe_t>) == 44, "C layout of strobe_t: offsetof darktime")
    static_assert(typeinfo offsetof<brighttime>(type<strobe_t>) == 48, "C layout of strobe_t: offsetof brighttime")
    static_assert(typeinfo sizeof(type<glow_t>) == 48, "C layout of glow_t: sizeof")
    static_assert(typeinfo alignof(type<glow_t>) == 8, "C layout of glow_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<glow_t>) == 0, "C layout of glow_t: offsetof thinker")
    static_assert(typeinfo offsetof<sector>(type<glow_t>) == 24, "C layout of glow_t: offsetof sector")
    static_assert(typeinfo offsetof<minlight>(type<glow_t>) == 32, "C layout of glow_t: offsetof minlight")
    static_assert(typeinfo offsetof<maxlight>(type<glow_t>) == 36, "C layout of glow_t: offsetof maxlight")
    static_assert(typeinfo offsetof<direction>(type<glow_t>) == 40, "C layout of glow_t: offsetof direction")
}
