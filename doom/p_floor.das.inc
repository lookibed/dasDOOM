[export, sideeffects]
def T_MovePlane(var sector : sector_t?; var speed : int; var dest : int; var crush : uint; var floorOrCeiling : int; var direction : int) : result_e {
    var flag : uint
    var lastpos : int
    if (floorOrCeiling == 0) {
        if (direction == -1) {
            if (sector.floorheight - speed < dest) {
                lastpos = sector.floorheight
                sector.floorheight = int(dest)  // nolint:PERF020
                flag = uint(P_ChangeSector(sector, crush))
                if (flag == 1u) {
                    sector.floorheight = lastpos
                    P_ChangeSector(sector, crush)
                }
                return unsafe(reinterpret<result_e>(2u))
            } else {
                lastpos = sector.floorheight
                sector.floorheight -= speed
                flag = uint(P_ChangeSector(sector, crush))
                if (flag == 1u) {
                    sector.floorheight = lastpos
                    P_ChangeSector(sector, crush)
                    return unsafe(reinterpret<result_e>(1u))
                }
            }
        } elif (direction == 1) {
            if (sector.floorheight + speed > dest) {
                lastpos = sector.floorheight
                sector.floorheight = int(dest)  // nolint:PERF020
                flag = uint(P_ChangeSector(sector, crush))
                if (flag == 1u) {
                    sector.floorheight = lastpos
                    P_ChangeSector(sector, crush)
                }
                return unsafe(reinterpret<result_e>(2u))
            } else {
                lastpos = sector.floorheight
                sector.floorheight += speed
                flag = uint(P_ChangeSector(sector, crush))
                if (flag == 1u) {
                    if (crush == 1u) {
                        return unsafe(reinterpret<result_e>(1u))
                    }
                    sector.floorheight = lastpos
                    P_ChangeSector(sector, crush)
                    return unsafe(reinterpret<result_e>(1u))
                }
            }
        }
    } elif (floorOrCeiling == 1) {
        if (direction == -1) {
            if (sector.ceilingheight - speed < dest) {
                lastpos = sector.ceilingheight
                sector.ceilingheight = int(dest)  // nolint:PERF020
                flag = uint(P_ChangeSector(sector, crush))
                if (flag == 1u) {
                    sector.ceilingheight = lastpos
                    P_ChangeSector(sector, crush)
                }
                return unsafe(reinterpret<result_e>(2u))
            } else {
                lastpos = sector.ceilingheight
                sector.ceilingheight -= speed
                flag = uint(P_ChangeSector(sector, crush))
                if (flag == 1u) {
                    if (crush == 1u) {
                        return unsafe(reinterpret<result_e>(1u))
                    }
                    sector.ceilingheight = lastpos
                    P_ChangeSector(sector, crush)
                    return unsafe(reinterpret<result_e>(1u))
                }
            }
        } elif (direction == 1) {
            if (sector.ceilingheight + speed > dest) {
                lastpos = sector.ceilingheight
                sector.ceilingheight = int(dest)  // nolint:PERF020
                flag = uint(P_ChangeSector(sector, crush))
                if (flag == 1u) {
                    sector.ceilingheight = lastpos
                    P_ChangeSector(sector, crush)
                }
                return unsafe(reinterpret<result_e>(2u))
            } else {
                lastpos = sector.ceilingheight
                sector.ceilingheight += speed
                flag = uint(P_ChangeSector(sector, crush))
            }
        }
    }
    return unsafe(reinterpret<result_e>(0u))
}
[export, sideeffects]
def EV_BuildStairs(var line : line_s?; var type_0 : stair_e) : int {
    var c2da_fresh1 : uint
    var secnum : int
    var height : int
    var i : int
    var newsecnum : int
    var texture : int
    var ok_0 : int
    var rtn : int
    var sec : sector_t?
    var tsec : sector_t?
    var floor : floormove_t?
    var stairsize : int
    var speed_0 : int
    stairsize = 0
    speed_0 = 0
    secnum = -1
    rtn = 0
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
        floor = unsafe(reinterpret<floormove_t?>(unsafe(reinterpret<floormove_t?>(Z_Malloc(64, 6, null)))))
        var c2da_fresh0 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(floor))))
        P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh0)))
        sec.specialdata = unsafe(reinterpret<uint8?>(floor))
        unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(floor))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_MoveFloor))
        floor.direction = 1
        floor.sector = sec
        c2da_fresh1 = uint(type_0)
        if (c2da_fresh1 == 0x0u) {
            speed_0 = (1 << 16) / 4
            stairsize = 8 * (1 << 16)
        } elif (c2da_fresh1 == 0x1u) {
            speed_0 = (1 << 16) * 4
            stairsize = 16 * (1 << 16)
        }
        floor.speed = speed_0
        height = sec.floorheight + stairsize
        floor.floordestheight = height
        texture = int(sec.floorpic)
        while (true) {
            ok_0 = 0
            i = 0
            while (i < sec.linecount) {
                if ((int(unsafe(sec.lines[i]).flags) & 4) == 0) {
                    i++
                    continue
                }
                tsec = unsafe(reinterpret<sector_t?>(unsafe(sec.lines[i]).frontsector))
                if (secnum != int(unsafe(tsec - sectors))) {
                    i++
                    continue
                }
                tsec = unsafe(reinterpret<sector_t?>(unsafe(sec.lines[i]).backsector))
                newsecnum = int(unsafe(tsec - sectors))
                if (int(tsec.floorpic) != texture) {
                    i++
                    continue
                }
                height += stairsize
                if (tsec.specialdata != null) {
                    i++
                    continue
                }
                sec = unsafe(reinterpret<sector_t?>(tsec))
                secnum = newsecnum
                floor = unsafe(reinterpret<floormove_t?>(unsafe(reinterpret<floormove_t?>(Z_Malloc(64, 6, null)))))
                var c2da_fresh2 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(floor))))
                P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh2)))
                sec.specialdata = unsafe(reinterpret<uint8?>(floor))
                unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(floor))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_MoveFloor))
                floor.direction = 1
                floor.sector = sec
                floor.speed = speed_0
                floor.floordestheight = height
                ok_0 = 1
                break
            }
            if (ok_0 == 0) {
                break
            }
        }
    }
    return rtn
}
[export, sideeffects]
def T_MoveFloor(var floor_0 : floormove_t?) {
    var c2da_fresh4 : uint
    var c2da_fresh5 : uint
    var res : result_e = result_e()
    var c2da_fresh6 : thinker_s?
    var c2da_fresh7 : degenmobj_t?
    res = T_MovePlane(floor_0.sector, floor_0.speed, floor_0.floordestheight, floor_0.crush, 0, floor_0.direction)
    if ((leveltime & 7) == 0) {
        var c2da_fresh3 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(floor_0.sector)) + 48ul))
        S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh3)), 22)
    }
    if (uint(res) == 2u) {
        floor_0.sector.specialdata = null
        if (floor_0.direction != 1) {
            goto label 2
        }
        c2da_fresh4 = uint(floor_0.type_0)
        if (c2da_fresh4 == 0xbu) {
            goto label 0
        } else {
            goto label 1
        }
        label 0:
        floor_0.sector.special = int16(floor_0.newspecial)
        floor_0.sector.floorpic = int16(floor_0.texture)  // nolint:PERF020
        label 1:
        goto label 6
        label 2:
        if (floor_0.direction != -1) {
            goto label 5
        }
        c2da_fresh5 = uint(floor_0.type_0)
        if (c2da_fresh5 == 0x6u) {
            goto label 3
        } else {
            goto label 4
        }
        label 3:
        floor_0.sector.special = int16(floor_0.newspecial)
        floor_0.sector.floorpic = int16(floor_0.texture)  // nolint:PERF020
        label 4:
        label 5:
        label 6:
        c2da_fresh6 = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(floor_0))))
        P_RemoveThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh6)))
        c2da_fresh7 = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(floor_0.sector)) + 48ul))
        S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh7)), 19)
    }
    return
}
[export, sideeffects]
def EV_DoFloor(var line_0 : line_s?; var floortype : floor_e) : int {
    var c2da_fresh9 : uint
    var secnum_0 : int
    var rtn_0 : int
    var i_0 : int
    var sec_0 : sector_t?
    var floor_1 : floormove_t?
    var minsize : int
    var side : side_t?
    var c2da_fresh8 : thinker_s?
    secnum_0 = -1
    rtn_0 = 0
    while (true) {
        secnum_0 = P_FindSectorFromLineTag(line_0, secnum_0)
        if (secnum_0 < 0) {
            break
        }
        sec_0 = unsafe(addr<sector_t?>(unsafe(sectors[secnum_0])))
        if (sec_0.specialdata != null) {
            continue
        }
        rtn_0 = 1
        floor_1 = unsafe(reinterpret<floormove_t?>(unsafe(reinterpret<floormove_t?>(Z_Malloc(64, 6, null)))))
        c2da_fresh8 = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(floor_1))))
        P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh8)))
        sec_0.specialdata = unsafe(reinterpret<uint8?>(floor_1))
        unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(floor_1))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_MoveFloor))
        floor_1.type_0 = floortype
        floor_1.crush = 0u
        c2da_fresh9 = uint(floortype)
        if (c2da_fresh9 <= 0xcu) {
            goto int(c2da_fresh9)
        }
        continue
        label 11:
        continue
        label 0:
        floor_1.direction = -1
        floor_1.sector = sec_0
        floor_1.speed = 1 << 16
        floor_1.floordestheight = P_FindHighestFloorSurrounding(sec_0)
        continue
        label 1:
        floor_1.direction = -1
        floor_1.sector = sec_0
        floor_1.speed = 1 << 16
        floor_1.floordestheight = P_FindLowestFloorSurrounding(sec_0)
        continue
        label 2:
        floor_1.direction = -1
        floor_1.sector = sec_0
        floor_1.speed = (1 << 16) * 4
        floor_1.floordestheight = P_FindHighestFloorSurrounding(sec_0)
        if (floor_1.floordestheight != sec_0.floorheight) {
            floor_1.floordestheight += 8 * (1 << 16)
        }
        continue
        label 9:
        floor_1.crush = 1u
        label 3:
        floor_1.direction = 1
        floor_1.sector = sec_0
        floor_1.speed = 1 << 16
        floor_1.floordestheight = P_FindLowestCeilingSurrounding(sec_0)
        if (floor_1.floordestheight > sec_0.ceilingheight) {
            floor_1.floordestheight = int(sec_0.ceilingheight)  // nolint:PERF020
        }
        floor_1.floordestheight -= 8 * (1 << 16) * (uint(floortype) == 9u ? 1 : 0)
        continue
        label 10:
        floor_1.direction = 1
        floor_1.sector = sec_0
        floor_1.speed = (1 << 16) * 4
        floor_1.floordestheight = P_FindNextHighestFloor(sec_0, sec_0.floorheight)
        continue
        label 4:
        floor_1.direction = 1
        floor_1.sector = sec_0
        floor_1.speed = 1 << 16
        floor_1.floordestheight = P_FindNextHighestFloor(sec_0, sec_0.floorheight)
        continue
        label 7:
        floor_1.direction = 1
        floor_1.sector = sec_0
        floor_1.speed = 1 << 16
        floor_1.floordestheight = floor_1.sector.floorheight + 24 * (1 << 16)
        continue
        label 12:
        floor_1.direction = 1
        floor_1.sector = sec_0
        floor_1.speed = 1 << 16
        floor_1.floordestheight = floor_1.sector.floorheight + 512 * (1 << 16)
        continue
        label 8:
        floor_1.direction = 1
        floor_1.sector = sec_0
        floor_1.speed = 1 << 16
        floor_1.floordestheight = floor_1.sector.floorheight + 24 * (1 << 16)
        sec_0.floorpic = int16(line_0.frontsector.floorpic)  // nolint:PERF020
        sec_0.special = int16(line_0.frontsector.special)  // nolint:PERF020
        continue
        label 5:
        minsize = 2147483647
        floor_1.direction = 1
        floor_1.sector = sec_0
        floor_1.speed = 1 << 16
        i_0 = 0
        while (i_0 < sec_0.linecount) {
            if (twoSided(secnum_0, i_0) != 0) {
                side = unsafe(reinterpret<side_t?>(unsafe(reinterpret<side_t?>(getSide(secnum_0, i_0, 0)))))
                if (int(side.bottomtexture) >= 0) {
                    if (unsafe(textureheight[int(side.bottomtexture)]) < minsize) {
                        minsize = unsafe(textureheight[int(side.bottomtexture)])
                    }
                }
                side = unsafe(reinterpret<side_t?>(unsafe(reinterpret<side_t?>(getSide(secnum_0, i_0, 1)))))
                if (int(side.bottomtexture) >= 0) {
                    if (unsafe(textureheight[int(side.bottomtexture)]) < minsize) {
                        minsize = unsafe(textureheight[int(side.bottomtexture)])
                    }
                }
            }
            i_0++
        }
        floor_1.floordestheight = floor_1.sector.floorheight + minsize
        continue
        label 6:
        floor_1.direction = -1
        floor_1.sector = sec_0
        floor_1.speed = 1 << 16
        floor_1.floordestheight = P_FindLowestFloorSurrounding(sec_0)
        floor_1.texture = int16(sec_0.floorpic)  // nolint:PERF020
        i_0 = 0
        while (i_0 < sec_0.linecount) {
            if (twoSided(secnum_0, i_0) != 0) {
                if (unsafe(unsafe(reinterpret<side_t?>(getSide(secnum_0, i_0, 0))).sector - sectors) == int64(secnum_0)) {
                    sec_0 = unsafe(reinterpret<sector_t?>(unsafe(reinterpret<sector_t?>(getSector(secnum_0, i_0, 1)))))
                    if (sec_0.floorheight == floor_1.floordestheight) {
                        floor_1.texture = int16(sec_0.floorpic)  // nolint:PERF020
                        floor_1.newspecial = int(sec_0.special)
                        break
                    }
                } else {
                    sec_0 = unsafe(reinterpret<sector_t?>(unsafe(reinterpret<sector_t?>(getSector(secnum_0, i_0, 0)))))
                    if (sec_0.floorheight == floor_1.floordestheight) {
                        floor_1.texture = int16(sec_0.floorpic)  // nolint:PERF020
                        floor_1.newspecial = int(sec_0.special)
                        break
                    }
                }
            }
            i_0++
        }
    }
    return rtn_0
}
[sideeffects]
def private c2da_layout_proofs_13() {
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
    static_assert(typeinfo sizeof(type<floormove_t>) == 64, "C layout of floormove_t: sizeof")
    static_assert(typeinfo alignof(type<floormove_t>) == 8, "C layout of floormove_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<floormove_t>) == 0, "C layout of floormove_t: offsetof thinker")
    static_assert(typeinfo offsetof<type_0>(type<floormove_t>) == 24, "C layout of floormove_t: offsetof type_0")
    static_assert(typeinfo offsetof<crush>(type<floormove_t>) == 28, "C layout of floormove_t: offsetof crush")
    static_assert(typeinfo offsetof<sector>(type<floormove_t>) == 32, "C layout of floormove_t: offsetof sector")
    static_assert(typeinfo offsetof<direction>(type<floormove_t>) == 40, "C layout of floormove_t: offsetof direction")
    static_assert(typeinfo offsetof<newspecial>(type<floormove_t>) == 44, "C layout of floormove_t: offsetof newspecial")
    static_assert(typeinfo offsetof<texture>(type<floormove_t>) == 48, "C layout of floormove_t: offsetof texture")
    static_assert(typeinfo offsetof<floordestheight>(type<floormove_t>) == 52, "C layout of floormove_t: offsetof floordestheight")
    static_assert(typeinfo offsetof<speed>(type<floormove_t>) == 56, "C layout of floormove_t: offsetof speed")
}
