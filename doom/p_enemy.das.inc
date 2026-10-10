var private c2da_str_p_enemy_0 : array<int8> = [int8(87), int8(101), int8(105), int8(114), int8(100), int8(32), int8(97), int8(99), int8(116), int8(111), int8(114), int8(45), int8(62), int8(109), int8(111), int8(118), int8(101), int8(100), int8(105), int8(114), int8(33), int8(0)]

var private c2da_str_p_enemy_1 : array<int8> = [int8(80), int8(95), int8(78), int8(101), int8(119), int8(67), int8(104), int8(97), int8(115), int8(101), int8(68), int8(105), int8(114), int8(58), int8(32), int8(99), int8(97), int8(108), int8(108), int8(101), int8(100), int8(32), int8(119), int8(105), int8(116), int8(104), int8(32), int8(110), int8(111), int8(32), int8(116), int8(97), int8(114), int8(103), int8(101), int8(116), int8(0)]

var private A_BrainSpit__easy : int = 0

[sideeffects]
def private c2da___bswap_16_7(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_7(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_7(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_7(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_7(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_7(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
[export, sideeffects]
def P_NoiseAlert(var target : mobj_s?; var emmiter : mobj_s?) {
    soundtarget = unsafe(reinterpret<mobj_s?>(target))
    validcount = validcount + 1
    P_RecursiveSound(emmiter.subsector.sector, 0)
    return
}
[export, sideeffects]
def P_RecursiveSound(var sec : sector_t?; var soundblocks : int) {
    var i : int
    var check : line_s?
    var other : sector_t?
    if (sec.validcount == validcount && sec.soundtraversed <= soundblocks + 1) {
        return
    }
    sec.validcount = validcount
    sec.soundtraversed = soundblocks + 1
    sec.soundtarget = soundtarget
    i = 0
    while (i < sec.linecount) {
        check = unsafe(reinterpret<line_s?>(unsafe(sec.lines[i])))
        if ((int(check.flags) & 4) == 0) {
            i++
            continue
        }
        P_LineOpening(check)
        if (openrange <= 0) {
            i++
            continue
        }
        var c2da_fresh0 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(check)) + 30ul))
        if (unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh0))[0]))]).sector == sec) {
            var c2da_fresh1 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(check)) + 30ul))
            other = unsafe(reinterpret<sector_t?>(unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh1))[1]))]).sector))
        } else {
            var c2da_fresh2 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(check)) + 30ul))
            other = unsafe(reinterpret<sector_t?>(unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh2))[0]))]).sector))
        }
        if ((int(check.flags) & 64) != 0) {
            if (soundblocks == 0) {
                P_RecursiveSound(other, 1)
            }
        } else {
            P_RecursiveSound(other, soundblocks)
        }
        i++
    }
    return
}
var soundtarget : mobj_s? = default<mobj_s?>

var opposite : dirtype_t[9] = fixed_array<dirtype_t>(unsafe(reinterpret<dirtype_t>(4u)), unsafe(reinterpret<dirtype_t>(5u)), unsafe(reinterpret<dirtype_t>(6u)), unsafe(reinterpret<dirtype_t>(7u)), unsafe(reinterpret<dirtype_t>(0u)), unsafe(reinterpret<dirtype_t>(1u)), unsafe(reinterpret<dirtype_t>(2u)), unsafe(reinterpret<dirtype_t>(3u)), unsafe(reinterpret<dirtype_t>(8u)))

var diags : dirtype_t[4] = fixed_array<dirtype_t>(unsafe(reinterpret<dirtype_t>(3u)), unsafe(reinterpret<dirtype_t>(1u)), unsafe(reinterpret<dirtype_t>(5u)), unsafe(reinterpret<dirtype_t>(7u)))

[export, sideeffects]
def A_Fall(var actor : mobj_s?) {
    actor.flags &= ~2
    return
}
[export, sideeffects]
def P_CheckMeleeRange(var actor_0 : mobj_s?) : uint {
    var pl : mobj_s?
    var dist : int
    if (actor_0.target == null) {
        return 0u
    }
    pl = unsafe(reinterpret<mobj_s?>(actor_0.target))
    dist = P_AproxDistance(pl.x - actor_0.x, pl.y - actor_0.y)
    if (dist >= 64 * (1 << 16) - 20 * (1 << 16) + pl.info.radius) {
        return 0u
    }
    if (P_CheckSight(actor_0, actor_0.target) == 0) {
        return 0u
    }
    return 1u
}
[export, sideeffects]
def P_CheckMissileRange(var actor_1 : mobj_s?) : uint {
    var dist_0 : int
    if (P_CheckSight(actor_1, actor_1.target) == 0) {
        return 0u
    }
    if ((actor_1.flags & 64) != 0) {
        actor_1.flags &= ~64
        return 1u
    }
    if (actor_1.reactiontime != 0) {
        return 0u
    }
    dist_0 = P_AproxDistance(actor_1.x - actor_1.target.x, actor_1.y - actor_1.target.y) - 64 * (1 << 16)
    if (actor_1.info.meleestate == 0) {
        dist_0 -= 128 * (1 << 16)
    }
    dist_0 >>= 16
    if (uint(actor_1.type_0) == 3u) {
        if (dist_0 > 14 * 64) {
            return 0u
        }
    }
    if (uint(actor_1.type_0) == 5u) {
        if (dist_0 < 196) {
            return 0u
        }
        dist_0 >>= 1
    }
    if (uint(actor_1.type_0) == 21u || uint(actor_1.type_0) == 19u || uint(actor_1.type_0) == 18u) {
        dist_0 >>= 1
    }
    if (dist_0 > 200) {
        dist_0 = 200
    }
    if (uint(actor_1.type_0) == 21u && dist_0 > 160) {
        dist_0 = 160
    }
    if (P_Random() < dist_0) {
        return 0u
    }
    return 1u
}
var xspeed : int[8] = fixed_array<int>(1 << 16, 47000, 0, -47000, -(1 << 16), -47000, 0, 47000)

var yspeed : int[8] = fixed_array<int>(0, 47000, 1 << 16, 47000, 0, -47000, -(1 << 16), -47000)

[export, sideeffects]
def P_Move(var actor_2 : mobj_s?) : uint {
    var tryx : int
    var tryy : int
    var ld : line_s?
    var try_ok : uint
    var good : uint
    if (actor_2.movedir == 8) {
        return 0u
    }
    if (uint(actor_2.movedir) >= 8u) {
        I_Error(unsafe(addr<int8?>(c2da_str_p_enemy_0[0])), [])
    }
    tryx = actor_2.x + actor_2.info.speed * xspeed[actor_2.movedir]
    tryy = actor_2.y + actor_2.info.speed * yspeed[actor_2.movedir]
    try_ok = uint(P_TryMove(actor_2, tryx, tryy))
    if (try_ok == 0) {
        if ((actor_2.flags & 16384) != 0 && floatok != 0x0) {
            if (actor_2.z < tmfloorz) {
                actor_2.z += (1 << 16) * 4
            } else {
                actor_2.z -= (1 << 16) * 4
            }
            actor_2.flags |= 2097152
            return 1u
        }
        if (numspechit == 0) {
            return 0u
        }
        actor_2.movedir = 8
        good = 0u
        while (true) {
            let c2da_postinc : int = numspechit
            numspechit = numspechit - 1
            if (c2da_postinc == 0) {
                break
            }
            ld = unsafe(reinterpret<line_s?>(spechit[int(numspechit)]))
            if (P_UseSpecialLine(actor_2, ld, 0) != 0x0) {
                good = 1u
            }
        }
        return good
    } else {
        actor_2.flags &= ~2097152
    }
    if ((actor_2.flags & 16384) == 0) {
        actor_2.z = int(actor_2.floorz)  // nolint:PERF020
    }
    return 1u
}
[export, sideeffects]
def P_TryWalk(var actor_3 : mobj_s?) : uint {
    if (P_Move(actor_3) == 0) {
        return 0u
    }
    actor_3.movecount = P_Random() & 15
    return 1u
}
[export, sideeffects]
def P_NewChaseDir(var actor_4 : mobj_s?) {
    var deltax : int
    var deltay : int
    var d : dirtype_t[3] = fixed_array<dirtype_t>(dirtype_t(), dirtype_t(), dirtype_t())
    var tdir : int
    var olddir : dirtype_t = dirtype_t()
    var turnaround : dirtype_t = dirtype_t()
    if (actor_4.target == null) {
        I_Error(unsafe(addr<int8?>(c2da_str_p_enemy_1[0])), [])
    }
    olddir = unsafe(reinterpret<dirtype_t>(uint(actor_4.movedir)))
    turnaround = opposite[int(olddir)]
    deltax = actor_4.target.x - actor_4.x
    deltay = actor_4.target.y - actor_4.y
    if (deltax > 10 * (1 << 16)) {
        d[1] = unsafe(reinterpret<dirtype_t>(0u))
    } elif (deltax < -10 * (1 << 16)) {
        d[1] = unsafe(reinterpret<dirtype_t>(4u))
    } else {
        d[1] = unsafe(reinterpret<dirtype_t>(8u))
    }
    if (deltay < -10 * (1 << 16)) {
        d[2] = unsafe(reinterpret<dirtype_t>(6u))
    } elif (deltay > 10 * (1 << 16)) {
        d[2] = unsafe(reinterpret<dirtype_t>(2u))
    } else {
        d[2] = unsafe(reinterpret<dirtype_t>(8u))
    }
    if (uint(d[1]) != 8u && uint(d[2]) != 8u) {
        actor_4.movedir = int(diags[((deltay < 0 ? 1 : 0) << 1) + (deltax > 0 ? 1 : 0)])
        if (actor_4.movedir != int(turnaround) && P_TryWalk(actor_4) != 0x0) {
            return
        }
    }
    if (P_Random() > 200 || c2da_std_abs(deltay) > c2da_std_abs(deltax)) {
        tdir = int(d[1])
        d[1] = d[2]
        d[2] = unsafe(reinterpret<dirtype_t>(uint(tdir)))
    }
    if (uint(d[1]) == uint(turnaround)) {
        d[1] = unsafe(reinterpret<dirtype_t>(8u))
    }
    if (uint(d[2]) == uint(turnaround)) {
        d[2] = unsafe(reinterpret<dirtype_t>(8u))
    }
    if (uint(d[1]) != 8u) {
        actor_4.movedir = int(d[1])
        if (P_TryWalk(actor_4) != 0x0) {
            return
        }
    }
    if (uint(d[2]) != 8u) {
        actor_4.movedir = int(d[2])
        if (P_TryWalk(actor_4) != 0x0) {
            return
        }
    }
    if (uint(olddir) != 8u) {
        actor_4.movedir = int(olddir)
        if (P_TryWalk(actor_4) != 0x0) {
            return
        }
    }
    if ((P_Random() & 1) != 0) {
        tdir = 0
        while (tdir <= 7) {
            if (tdir != int(turnaround)) {
                actor_4.movedir = tdir
                if (P_TryWalk(actor_4) != 0x0) {
                    return
                }
            }
            tdir++
        }
    } else {
        tdir = 7
        while (tdir != 0 - 1) {
            if (tdir != int(turnaround)) {
                actor_4.movedir = tdir
                if (P_TryWalk(actor_4) != 0x0) {
                    return
                }
            }
            tdir--
        }
    }
    if (uint(turnaround) != 8u) {
        actor_4.movedir = int(turnaround)
        if (P_TryWalk(actor_4) != 0x0) {
            return
        }
    }
    actor_4.movedir = 8
    return
}
[export, sideeffects]
def P_LookForPlayers(var actor_5 : mobj_s?; var allaround : uint) : uint {
    var c : int
    var stop : int
    var player : player_s?
    var an : uint
    var dist_1 : int
    c = 0
    stop = actor_5.lastlook - 1 & 3
    while (true) {
        if (playeringame[actor_5.lastlook] == 0) {
            actor_5.lastlook = actor_5.lastlook + 1 & 3
            continue
        }
        let c2da_postinc_0 : int = c
        c++
        if (c2da_postinc_0 == 2 || actor_5.lastlook == stop) {
            return 0u
        }
        player = unsafe(addr<player_s?>(unsafe(unsafe(addr(players[0]))[actor_5.lastlook])))
        if (player.health <= 0) {
            actor_5.lastlook = actor_5.lastlook + 1 & 3
            continue
        }
        if (P_CheckSight(actor_5, player.mo) == 0) {
            actor_5.lastlook = actor_5.lastlook + 1 & 3
            continue
        }
        if (allaround == 0) {
            an = uint(R_PointToAngle2(actor_5.x, actor_5.y, player.mo.x, player.mo.y) - actor_5.angle)
            if (an > 0x40000000u && an < 0xc0000000u) {
                dist_1 = P_AproxDistance(player.mo.x - actor_5.x, player.mo.y - actor_5.y)
                if (dist_1 > 64 * (1 << 16)) {
                    actor_5.lastlook = actor_5.lastlook + 1 & 3
                    continue
                }
            }
        }
        actor_5.target = player.mo
        return 1u
    }
}
[export, sideeffects]
def A_KeenDie(var mo : mobj_s?) {
    var th : thinker_s?
    var mo2 : mobj_s?
    var junk : line_s = line_s()
    A_Fall(mo)
    th = unsafe(reinterpret<thinker_s?>(thinkercap.next))
    while (th != unsafe(addr(thinkercap))) {
        if (unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(th))))[2]) != unsafe(reinterpret<actionf_p1>(@@P_MobjThinker))) {
            th = unsafe(reinterpret<thinker_s?>(th.next))
            continue
        }
        mo2 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(th))))
        if (mo2 != mo && uint(mo2.type_0) == uint(mo.type_0) && mo2.health > 0) {
            return
        }
        th = unsafe(reinterpret<thinker_s?>(th.next))
    }
    junk.tag = int16(666)
    EV_DoDoor(unsafe(addr<line_s?>(junk)), unsafe(reinterpret<vldoor_e>(3u)))
    return
}
[export, sideeffects]
def A_Look(var actor_6 : mobj_s?) {
    var c2da_fresh3 : int
    var targ : mobj_s?
    var sound : int
    actor_6.threshold = 0
    targ = unsafe(reinterpret<mobj_s?>(actor_6.subsector.sector.soundtarget))
    if (targ != null && (targ.flags & 4) != 0) {
        goto label 8
    }
    label 0:
    if (P_LookForPlayers(actor_6, 0u) == 0) {
        goto label 7
    }
    label 1:
    if (actor_6.info.seesound != 0) {
        goto label 3
    }
    label 2:
    P_SetMobjState(actor_6, unsafe(reinterpret<statenum_t>(uint(actor_6.info.seestate))))
    return
    label 3:
    c2da_fresh3 = actor_6.info.seesound
    if (c2da_fresh3 >= 36 && c2da_fresh3 <= 40) {
        goto c2da_fresh3 - 25
    }
    sound = actor_6.info.seesound
    label 4:
    if (uint(actor_6.type_0) == 19u || uint(actor_6.type_0) == 21u) {
        goto label 6
    }
    S_StartSound(unsafe(reinterpret<uint8?>(actor_6)), sound)
    label 5:
    goto label 2
    label 6:
    S_StartSound(null, sound)
    goto label 5
    label 11:
    label 12:
    label 13:
    sound = 36 + P_Random() % 3
    goto label 4
    label 14:
    label 15:
    sound = 39 + P_Random() % 2
    goto label 4
    label 7:
    return
    label 8:
    actor_6.target = targ
    if ((actor_6.flags & 32) != 0) {
        goto label 9
    }
    goto label 1
    label 9:
    if (P_CheckSight(actor_6, actor_6.target) != 0x0) {
        goto label 10
    }
    goto label 0
    label 10:
    goto label 1
    panic("unreachable: fell out of a translated control-flow graph")
}
[export, sideeffects]
def A_Chase(var actor_7 : mobj_s?) {
    var delta : int
    var c2da_postinc_3 : int
    if (actor_7.reactiontime != 0) {
        goto label 30
    }
    label 0:
    if (actor_7.threshold != 0) {
        goto label 27
    }
    label 1:
    if (actor_7.movedir < 8) {
        goto label 22
    }
    label 2:
    if (actor_7.target == null || (actor_7.target.flags & 4) == 0) {
        goto label 20
    }
    if ((actor_7.flags & 128) != 0) {
        goto label 17
    }
    if (actor_7.info.meleestate != 0 && P_CheckMeleeRange(actor_7) != 0x0) {
        goto label 14
    }
    if (actor_7.info.missilestate != 0) {
        goto label 11
    }
    label 3:
    if (netgame != 0x0 && actor_7.threshold == 0 && P_CheckSight(actor_7, actor_7.target) == 0) {
        goto label 9
    }
    label 4:
    c2da_postinc_3 = actor_7.movecount
    actor_7.movecount = c2da_postinc_3 - 1
    if (c2da_postinc_3 - 1 < 0 || P_Move(actor_7) == 0) {
        goto label 8
    }
    label 5:
    if (actor_7.info.activesound != 0 && P_Random() < 3) {
        goto label 7
    }
    label 6:
    return
    label 7:
    S_StartSound(unsafe(reinterpret<uint8?>(actor_7)), actor_7.info.activesound)
    goto label 6
    label 8:
    P_NewChaseDir(actor_7)
    goto label 5
    label 9:
    if (P_LookForPlayers(actor_7, 1u) != 0x0) {
        goto label 10
    }
    goto label 4
    label 10:
    return
    label 11:
    if (int(gameskill) < 4 && fastparm == 0 && actor_7.movecount != 0) {
        goto label 13
    }
    if (P_CheckMissileRange(actor_7) == 0) {
        goto label 12
    }
    P_SetMobjState(actor_7, unsafe(reinterpret<statenum_t>(uint(actor_7.info.missilestate))))
    actor_7.flags |= 128
    return
    label 12:
    goto label 3
    label 13:
    goto label 3
    label 14:
    if (actor_7.info.attacksound != 0) {
        goto label 16
    }
    label 15:
    P_SetMobjState(actor_7, unsafe(reinterpret<statenum_t>(uint(actor_7.info.meleestate))))
    return
    label 16:
    S_StartSound(unsafe(reinterpret<uint8?>(actor_7)), actor_7.info.attacksound)
    goto label 15
    label 17:
    actor_7.flags &= ~128
    if (int(gameskill) != 4 && fastparm == 0) {
        goto label 19
    }
    label 18:
    return
    label 19:
    P_NewChaseDir(actor_7)
    goto label 18
    label 20:
    if (P_LookForPlayers(actor_7, 1u) != 0x0) {
        goto label 21
    }
    P_SetMobjState(actor_7, unsafe(reinterpret<statenum_t>(uint(actor_7.info.spawnstate))))
    return
    label 21:
    return
    label 22:
    actor_7.angle &= uint(7 << 29)
    delta = int(actor_7.angle - uint(actor_7.movedir << 29))
    if (delta > 0) {
        goto label 26
    }
    if (delta < 0) {
        goto label 25
    }
    label 23:
    label 24:
    goto label 2
    label 25:
    actor_7.angle += uint(1073741824 / 2)
    goto label 23
    label 26:
    actor_7.angle -= uint(1073741824 / 2)
    goto label 24
    label 27:
    if (actor_7.target == null || actor_7.target.health <= 0) {
        goto label 29
    }
    c2da_postinc_3 = actor_7.threshold
    actor_7.threshold = c2da_postinc_3 - 1
    label 28:
    goto label 1
    label 29:
    actor_7.threshold = 0
    goto label 28
    label 30:
    c2da_postinc_3 = actor_7.reactiontime
    actor_7.reactiontime = c2da_postinc_3 - 1
    goto label 0
    panic("unreachable: fell out of a translated control-flow graph")
}
[export, sideeffects]
def A_FaceTarget(var actor_8 : mobj_s?) {
    if (actor_8.target == null) {
        return
    }
    actor_8.flags &= ~32
    actor_8.angle = R_PointToAngle2(actor_8.x, actor_8.y, actor_8.target.x, actor_8.target.y)
    if ((actor_8.target.flags & 262144) != 0) {
        actor_8.angle = actor_8.angle + uint(P_Random() - P_Random() << 21)
    }
    return
}
[export, sideeffects]
def A_PosAttack(var actor_9 : mobj_s?) {
    var angle : int
    var damage : int
    var slope : int
    if (actor_9.target == null) {
        return
    }
    A_FaceTarget(actor_9)
    angle = int(actor_9.angle)
    slope = P_AimLineAttack(actor_9, uint(angle), 32 * 64 * (1 << 16))
    S_StartSound(unsafe(reinterpret<uint8?>(actor_9)), 1)
    angle = angle + (P_Random() - P_Random() << 20)
    damage = (P_Random() % 5 + 1) * 3
    P_LineAttack(actor_9, uint(angle), 32 * 64 * (1 << 16), slope, damage)
    return
}
[export, sideeffects]
def A_SPosAttack(var actor_10 : mobj_s?) {
    var angle_0 : int
    var bangle : int
    var damage_0 : int
    var slope_0 : int
    if (actor_10.target == null) {
        return
    }
    S_StartSound(unsafe(reinterpret<uint8?>(actor_10)), 2)
    A_FaceTarget(actor_10)
    bangle = int(actor_10.angle)
    slope_0 = P_AimLineAttack(actor_10, uint(bangle), 32 * 64 * (1 << 16))
    for (i_0 in range(0, 3)) {
        angle_0 = bangle + (P_Random() - P_Random() << 20)
        damage_0 = (P_Random() % 5 + 1) * 3
        P_LineAttack(actor_10, uint(angle_0), 32 * 64 * (1 << 16), slope_0, damage_0)
    }
    return
}
[export, sideeffects]
def A_CPosAttack(var actor_11 : mobj_s?) {
    var angle_1 : int
    var bangle_0 : int
    var damage_1 : int
    var slope_1 : int
    if (actor_11.target == null) {
        return
    }
    S_StartSound(unsafe(reinterpret<uint8?>(actor_11)), 2)
    A_FaceTarget(actor_11)
    bangle_0 = int(actor_11.angle)
    slope_1 = P_AimLineAttack(actor_11, uint(bangle_0), 32 * 64 * (1 << 16))
    angle_1 = bangle_0 + (P_Random() - P_Random() << 20)
    damage_1 = (P_Random() % 5 + 1) * 3
    P_LineAttack(actor_11, uint(angle_1), 32 * 64 * (1 << 16), slope_1, damage_1)
    return
}
[export, sideeffects]
def A_CPosRefire(var actor_12 : mobj_s?) {
    A_FaceTarget(actor_12)
    if (P_Random() < 40) {
        return
    }
    if (actor_12.target == null || actor_12.target.health <= 0 || P_CheckSight(actor_12, actor_12.target) == 0) {
        P_SetMobjState(actor_12, unsafe(reinterpret<statenum_t>(uint(actor_12.info.seestate))))
    }
    return
}
[export, sideeffects]
def A_SpidRefire(var actor_13 : mobj_s?) {
    A_FaceTarget(actor_13)
    if (P_Random() < 10) {
        return
    }
    if (actor_13.target == null || actor_13.target.health <= 0 || P_CheckSight(actor_13, actor_13.target) == 0) {
        P_SetMobjState(actor_13, unsafe(reinterpret<statenum_t>(uint(actor_13.info.seestate))))
    }
    return
}
[export, sideeffects]
def A_BspiAttack(var actor_14 : mobj_s?) {
    if (actor_14.target == null) {
        return
    }
    A_FaceTarget(actor_14)
    P_SpawnMissile(actor_14, actor_14.target, unsafe(reinterpret<mobjtype_t>(36u)))
    return
}
[export, sideeffects]
def A_TroopAttack(var actor_15 : mobj_s?) {
    var damage_2 : int
    if (actor_15.target == null) {
        return
    }
    A_FaceTarget(actor_15)
    if (P_CheckMeleeRange(actor_15) != 0x0) {
        S_StartSound(unsafe(reinterpret<uint8?>(actor_15)), 55)
        damage_2 = (P_Random() % 8 + 1) * 3
        P_DamageMobj(actor_15.target, actor_15, actor_15, damage_2)
        return
    }
    P_SpawnMissile(actor_15, actor_15.target, unsafe(reinterpret<mobjtype_t>(31u)))
    return
}
[export, sideeffects]
def A_SargAttack(var actor_16 : mobj_s?) {
    var damage_3 : int
    if (actor_16.target == null) {
        return
    }
    A_FaceTarget(actor_16)
    if (P_CheckMeleeRange(actor_16) != 0x0) {
        damage_3 = (P_Random() % 10 + 1) * 4
        P_DamageMobj(actor_16.target, actor_16, actor_16, damage_3)
    }
    return
}
[export, sideeffects]
def A_HeadAttack(var actor_17 : mobj_s?) {
    var damage_4 : int
    if (actor_17.target == null) {
        return
    }
    A_FaceTarget(actor_17)
    if (P_CheckMeleeRange(actor_17) != 0x0) {
        damage_4 = (P_Random() % 6 + 1) * 10
        P_DamageMobj(actor_17.target, actor_17, actor_17, damage_4)
        return
    }
    P_SpawnMissile(actor_17, actor_17.target, unsafe(reinterpret<mobjtype_t>(32u)))
    return
}
[export, sideeffects]
def A_CyberAttack(var actor_18 : mobj_s?) {
    if (actor_18.target == null) {
        return
    }
    A_FaceTarget(actor_18)
    P_SpawnMissile(actor_18, actor_18.target, unsafe(reinterpret<mobjtype_t>(33u)))
    return
}
[export, sideeffects]
def A_BruisAttack(var actor_19 : mobj_s?) {
    var damage_5 : int
    if (actor_19.target == null) {
        return
    }
    if (P_CheckMeleeRange(actor_19) != 0x0) {
        S_StartSound(unsafe(reinterpret<uint8?>(actor_19)), 55)
        damage_5 = (P_Random() % 8 + 1) * 10
        P_DamageMobj(actor_19.target, actor_19, actor_19, damage_5)
        return
    }
    P_SpawnMissile(actor_19, actor_19.target, unsafe(reinterpret<mobjtype_t>(16u)))
    return
}
[export, sideeffects]
def A_SkelMissile(var actor_20 : mobj_s?) {
    var mo_0 : mobj_s?
    if (actor_20.target == null) {
        return
    }
    A_FaceTarget(actor_20)
    actor_20.z += 16 * (1 << 16)
    mo_0 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SpawnMissile(actor_20, actor_20.target, unsafe(reinterpret<mobjtype_t>(6u)))))))
    actor_20.z -= 16 * (1 << 16)
    mo_0.x += mo_0.momx
    mo_0.y += mo_0.momy
    mo_0.tracer = actor_20.target
    return
}
var TRACEANGLE : int = 201326592

[export, sideeffects]
def A_Tracer(var actor_21 : mobj_s?) {
    var exact : uint
    var dist_2 : int
    var dest : mobj_s?
    var th_0 : mobj_s?
    if ((gametic & 3) != 0) {
        return
    }
    P_SpawnPuff(actor_21.x, actor_21.y, actor_21.z)
    th_0 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SpawnMobj(actor_21.x - actor_21.momx, actor_21.y - actor_21.momy, actor_21.z, unsafe(reinterpret<mobjtype_t>(7u)))))))
    th_0.momz = 1 << 16
    th_0.tics = th_0.tics - (P_Random() & 3)
    if (th_0.tics < 1) {
        th_0.tics = 1
    }
    dest = unsafe(reinterpret<mobj_s?>(actor_21.tracer))
    if (dest == null || dest.health <= 0) {
        return
    }
    exact = uint(R_PointToAngle2(actor_21.x, actor_21.y, dest.x, dest.y))
    if (exact != actor_21.angle) {
        if (exact - actor_21.angle > 0x80000000u) {
            actor_21.angle -= uint(TRACEANGLE)
            if (exact - actor_21.angle < 0x80000000u) {
                actor_21.angle = exact
            }
        } else {
            actor_21.angle += uint(TRACEANGLE)
            if (exact - actor_21.angle > 0x80000000u) {
                actor_21.angle = exact
            }
        }
    }
    exact = actor_21.angle >> 19u
    actor_21.momx = FixedMul(actor_21.info.speed, unsafe(finecosine[int(exact)]))
    actor_21.momy = FixedMul(actor_21.info.speed, finesine[int(exact)])
    dist_2 = P_AproxDistance(dest.x - actor_21.x, dest.y - actor_21.y)
    dist_2 /= actor_21.info.speed
    if (dist_2 < 1) {
        dist_2 = 1
    }
    if ((dest.z + 40 * (1 << 16) - actor_21.z) / dist_2 < actor_21.momz) {
        actor_21.momz -= (1 << 16) / 8
    } else {
        actor_21.momz += (1 << 16) / 8
    }
    return
}
[export, sideeffects]
def A_SkelWhoosh(var actor_22 : mobj_s?) {
    if (actor_22.target == null) {
        return
    }
    A_FaceTarget(actor_22)
    S_StartSound(unsafe(reinterpret<uint8?>(actor_22)), 56)
    return
}
[export, sideeffects]
def A_SkelFist(var actor_23 : mobj_s?) {
    var damage_6 : int
    if (actor_23.target == null) {
        return
    }
    A_FaceTarget(actor_23)
    if (P_CheckMeleeRange(actor_23) != 0x0) {
        damage_6 = (P_Random() % 10 + 1) * 6
        S_StartSound(unsafe(reinterpret<uint8?>(actor_23)), 53)
        P_DamageMobj(actor_23.target, actor_23, actor_23, damage_6)
    }
    return
}
var corpsehit : mobj_s? = default<mobj_s?>

var vileobj : mobj_s? = default<mobj_s?>

var viletryx : int = default<int>

var viletryy : int = default<int>

[export, sideeffects]
def PIT_VileCheck(var thing : mobj_s?) : uint {
    var maxdist : int
    var check_0 : uint
    if ((thing.flags & 1048576) == 0) {
        return 1u
    }
    if (thing.tics != -1) {
        return 1u
    }
    if (thing.info.raisestate == 0) {
        return 1u
    }
    maxdist = thing.info.radius + mobjinfo[3].radius
    if (c2da_std_abs(thing.x - viletryx) > maxdist || c2da_std_abs(thing.y - viletryy) > maxdist) {
        return 1u
    }
    corpsehit = unsafe(reinterpret<mobj_s?>(thing))
    let c2da_fresh4 : int = 0
    corpsehit.momy = c2da_fresh4
    corpsehit.momx = c2da_fresh4
    corpsehit.height <<= 2
    check_0 = uint(P_CheckPosition(corpsehit, corpsehit.x, corpsehit.y))
    corpsehit.height >>= 2
    if (check_0 == 0) {
        return 1u
    }
    return 0u
}
[export, sideeffects]
def A_VileChase(var actor_24 : mobj_s?) {
    var xl : int
    var xh : int
    var yl : int
    var yh : int
    var bx : int
    var by : int
    var info : mobjinfo_t?
    var temp : mobj_s?
    if (actor_24.movedir != 8) {
        viletryx = actor_24.x + actor_24.info.speed * xspeed[actor_24.movedir]
        viletryy = actor_24.y + actor_24.info.speed * yspeed[actor_24.movedir]
        xl = viletryx - bmaporgx - 32 * (1 << 16) * 2 >> 16 + 7
        xh = viletryx - bmaporgx + 32 * (1 << 16) * 2 >> 16 + 7
        yl = viletryy - bmaporgy - 32 * (1 << 16) * 2 >> 16 + 7
        yh = viletryy - bmaporgy + 32 * (1 << 16) * 2 >> 16 + 7
        vileobj = unsafe(reinterpret<mobj_s?>(actor_24))
        bx = xl
        while (bx <= xh) {
            by = yl
            while (by <= yh) {
                if (P_BlockThingsIterator(bx, by, @@PIT_VileCheck) == 0) {
                    temp = unsafe(reinterpret<mobj_s?>(actor_24.target))
                    actor_24.target = corpsehit
                    A_FaceTarget(actor_24)
                    actor_24.target = temp
                    P_SetMobjState(actor_24, unsafe(reinterpret<statenum_t>(266u)))
                    S_StartSound(unsafe(reinterpret<uint8?>(corpsehit)), 31)
                    info = unsafe(reinterpret<mobjinfo_t?>(corpsehit.info))
                    P_SetMobjState(corpsehit, unsafe(reinterpret<statenum_t>(uint(info.raisestate))))
                    corpsehit.height <<= 2
                    corpsehit.flags = int(info.flags)  // nolint:PERF020
                    corpsehit.health = int(info.spawnhealth)  // nolint:PERF020
                    corpsehit.target = null
                    return
                }
                by++
            }
            bx++
        }
    }
    A_Chase(actor_24)
    return
}
[export, sideeffects]
def A_VileStart(var actor_25 : mobj_s?) {
    S_StartSound(unsafe(reinterpret<uint8?>(actor_25)), 54)
    return
}
[export, sideeffects]
def A_Fire(var actor_26 : mobj_s?) {
    var dest_0 : mobj_s?
    var target_0 : mobj_s?
    var an_0 : uint
    dest_0 = unsafe(reinterpret<mobj_s?>(actor_26.tracer))
    if (dest_0 == null) {
        return
    }
    target_0 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SubstNullMobj(actor_26.target)))))
    if (P_CheckSight(target_0, dest_0) == 0) {
        return
    }
    an_0 = dest_0.angle >> 19u
    P_UnsetThingPosition(actor_26)
    actor_26.x = dest_0.x + FixedMul(24 * (1 << 16), unsafe(finecosine[int(an_0)]))
    actor_26.y = dest_0.y + FixedMul(24 * (1 << 16), finesine[int(an_0)])
    actor_26.z = int(dest_0.z)  // nolint:PERF020
    P_SetThingPosition(actor_26)
    return
}
[export, sideeffects]
def A_StartFire(var actor_27 : mobj_s?) {
    S_StartSound(unsafe(reinterpret<uint8?>(actor_27)), 92)
    A_Fire(actor_27)
    return
}
[export, sideeffects]
def A_FireCrackle(var actor_28 : mobj_s?) {
    S_StartSound(unsafe(reinterpret<uint8?>(actor_28)), 91)
    A_Fire(actor_28)
    return
}
[export, sideeffects]
def A_VileTarget(var actor_29 : mobj_s?) {
    var fog : mobj_s?
    if (actor_29.target == null) {
        return
    }
    A_FaceTarget(actor_29)
    fog = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SpawnMobj(actor_29.target.x, actor_29.target.x, actor_29.target.z, unsafe(reinterpret<mobjtype_t>(4u)))))))
    actor_29.tracer = fog
    fog.target = actor_29
    fog.tracer = actor_29.target
    A_Fire(fog)
    return
}
[export, sideeffects]
def A_VileAttack(var actor_30 : mobj_s?) {
    var fire : mobj_s?
    var an_1 : int
    if (actor_30.target == null) {
        return
    }
    A_FaceTarget(actor_30)
    if (P_CheckSight(actor_30, actor_30.target) == 0) {
        return
    }
    S_StartSound(unsafe(reinterpret<uint8?>(actor_30)), 82)
    P_DamageMobj(actor_30.target, actor_30, actor_30, 20)
    actor_30.target.momz = 1000 * (1 << 16) / actor_30.target.info.mass
    an_1 = int(actor_30.angle >> 19u)
    fire = unsafe(reinterpret<mobj_s?>(actor_30.tracer))
    if (fire == null) {
        return
    }
    fire.x = actor_30.target.x - FixedMul(24 * (1 << 16), unsafe(finecosine[an_1]))
    fire.y = actor_30.target.y - FixedMul(24 * (1 << 16), finesine[an_1])
    P_RadiusAttack(fire, actor_30, 70)
    return
}
[export, sideeffects]
def A_FatRaise(var actor_31 : mobj_s?) {
    A_FaceTarget(actor_31)
    S_StartSound(unsafe(reinterpret<uint8?>(actor_31)), 99)
    return
}
[export, sideeffects]
def A_FatAttack1(var actor_32 : mobj_s?) {
    var mo_1 : mobj_s?
    var target_1 : mobj_s?
    var an_2 : int
    A_FaceTarget(actor_32)
    actor_32.angle += uint(1073741824 / 8)
    target_1 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SubstNullMobj(actor_32.target)))))
    P_SpawnMissile(actor_32, target_1, unsafe(reinterpret<mobjtype_t>(9u)))
    mo_1 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SpawnMissile(actor_32, target_1, unsafe(reinterpret<mobjtype_t>(9u)))))))
    mo_1.angle += uint(1073741824 / 8)
    an_2 = int(mo_1.angle >> 19u)
    mo_1.momx = FixedMul(mo_1.info.speed, unsafe(finecosine[an_2]))
    mo_1.momy = FixedMul(mo_1.info.speed, finesine[an_2])
    return
}
[export, sideeffects]
def A_FatAttack2(var actor_33 : mobj_s?) {
    var mo_2 : mobj_s?
    var target_2 : mobj_s?
    var an_3 : int
    A_FaceTarget(actor_33)
    actor_33.angle -= uint(1073741824 / 8)
    target_2 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SubstNullMobj(actor_33.target)))))
    P_SpawnMissile(actor_33, target_2, unsafe(reinterpret<mobjtype_t>(9u)))
    mo_2 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SpawnMissile(actor_33, target_2, unsafe(reinterpret<mobjtype_t>(9u)))))))
    mo_2.angle -= uint(1073741824 / 8 * 2)
    an_3 = int(mo_2.angle >> 19u)
    mo_2.momx = FixedMul(mo_2.info.speed, unsafe(finecosine[an_3]))
    mo_2.momy = FixedMul(mo_2.info.speed, finesine[an_3])
    return
}
[export, sideeffects]
def A_FatAttack3(var actor_34 : mobj_s?) {
    var mo_3 : mobj_s?
    var target_3 : mobj_s?
    var an_4 : int
    A_FaceTarget(actor_34)
    target_3 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SubstNullMobj(actor_34.target)))))
    mo_3 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SpawnMissile(actor_34, target_3, unsafe(reinterpret<mobjtype_t>(9u)))))))
    mo_3.angle -= uint(1073741824 / 8 / 2)
    an_4 = int(mo_3.angle >> 19u)
    mo_3.momx = FixedMul(mo_3.info.speed, unsafe(finecosine[an_4]))
    mo_3.momy = FixedMul(mo_3.info.speed, finesine[an_4])
    mo_3 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SpawnMissile(actor_34, target_3, unsafe(reinterpret<mobjtype_t>(9u)))))))
    mo_3.angle += uint(1073741824 / 8 / 2)
    an_4 = int(mo_3.angle >> 19u)
    mo_3.momx = FixedMul(mo_3.info.speed, unsafe(finecosine[an_4]))
    mo_3.momy = FixedMul(mo_3.info.speed, finesine[an_4])
    return
}
[export, sideeffects]
def A_SkullAttack(var actor_35 : mobj_s?) {
    var dest_1 : mobj_s?
    var an_5 : uint
    var dist_3 : int
    if (actor_35.target == null) {
        return
    }
    dest_1 = unsafe(reinterpret<mobj_s?>(actor_35.target))
    actor_35.flags |= 16777216
    S_StartSound(unsafe(reinterpret<uint8?>(actor_35)), actor_35.info.attacksound)
    A_FaceTarget(actor_35)
    an_5 = actor_35.angle >> 19u
    actor_35.momx = FixedMul(20 * (1 << 16), unsafe(finecosine[int(an_5)]))
    actor_35.momy = FixedMul(20 * (1 << 16), finesine[int(an_5)])
    dist_3 = P_AproxDistance(dest_1.x - actor_35.x, dest_1.y - actor_35.y)
    dist_3 /= 20 * (1 << 16)
    if (dist_3 < 1) {
        dist_3 = 1
    }
    actor_35.momz = (dest_1.z + (dest_1.height >> 1) - actor_35.z) / dist_3
    return
}
[export, sideeffects]
def A_PainShootSkull(var actor_36 : mobj_s?; var angle_2 : uint) {
    var x : int
    var y : int
    var z : int
    var newmobj : mobj_s?
    var an_6 : uint
    var prestep : int
    var count : int
    var currentthinker : thinker_s?
    count = 0
    currentthinker = unsafe(reinterpret<thinker_s?>(thinkercap.next))
    while (currentthinker != unsafe(addr(thinkercap))) {
        if (unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(currentthinker))))[2]) == unsafe(reinterpret<actionf_p1>(@@P_MobjThinker)) && uint(unsafe(reinterpret<mobj_s?>(currentthinker)).type_0) == 18u) {
            count++
        }
        currentthinker = unsafe(reinterpret<thinker_s?>(currentthinker.next))
    }
    if (count > 20) {
        return
    }
    an_6 = angle_2 >> 19u
    prestep = 4 * (1 << 16) + 3 * (actor_36.info.radius + mobjinfo[18].radius) / 2
    x = actor_36.x + FixedMul(prestep, unsafe(finecosine[int(an_6)]))
    y = actor_36.y + FixedMul(prestep, finesine[int(an_6)])
    z = actor_36.z + 8 * (1 << 16)
    newmobj = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SpawnMobj(x, y, z, unsafe(reinterpret<mobjtype_t>(18u)))))))
    if (P_TryMove(newmobj, newmobj.x, newmobj.y) == 0) {
        P_DamageMobj(newmobj, actor_36, actor_36, 10000)
        return
    }
    newmobj.target = actor_36.target
    A_SkullAttack(newmobj)
    return
}
[export, sideeffects]
def A_PainAttack(var actor_37 : mobj_s?) {
    if (actor_37.target == null) {
        return
    }
    A_FaceTarget(actor_37)
    A_PainShootSkull(actor_37, actor_37.angle)
    return
}
[export, sideeffects]
def A_PainDie(var actor_38 : mobj_s?) {
    A_Fall(actor_38)
    A_PainShootSkull(actor_38, actor_38.angle + 0x40000000u)
    A_PainShootSkull(actor_38, actor_38.angle + 0x80000000u)
    A_PainShootSkull(actor_38, actor_38.angle + 0xc0000000u)
    return
}
[export, sideeffects]
def A_Scream(var actor_39 : mobj_s?) {
    var c2da_fresh5 : int
    var sound_0 : int
    c2da_fresh5 = actor_39.info.deathsound
    if (c2da_fresh5 == 0) {
        return
    } elif (c2da_fresh5 == 59 || c2da_fresh5 == 60 || c2da_fresh5 == 61) {
        sound_0 = 59 + P_Random() % 3
    } elif (c2da_fresh5 == 62 || c2da_fresh5 == 63) {
        sound_0 = 62 + P_Random() % 2
    } else {
        sound_0 = actor_39.info.deathsound
    }
    if (uint(actor_39.type_0) == 19u || uint(actor_39.type_0) == 21u) {
        S_StartSound(null, sound_0)
    } else {
        S_StartSound(unsafe(reinterpret<uint8?>(actor_39)), sound_0)
    }
    return
}
[export, sideeffects]
def A_XScream(var actor_40 : mobj_s?) {
    S_StartSound(unsafe(reinterpret<uint8?>(actor_40)), 31)
    return
}
[export, sideeffects]
def A_Pain(var actor_41 : mobj_s?) {
    if (actor_41.info.painsound != 0) {
        S_StartSound(unsafe(reinterpret<uint8?>(actor_41)), actor_41.info.painsound)
    }
    return
}
[export, sideeffects]
def A_Explode(var thingy : mobj_s?) {
    P_RadiusAttack(thingy, thingy.target, 128)
    return
}
[sideeffects]
def private CheckBossEnd(var motype : mobjtype_t) : uint {
    if (uint(gameversion) < 6u) {
        if (gamemap != 8) {
            return 0u
        }
        if (uint(motype) == 15u && gameepisode != 1) {
            return 0u
        }
        return 1u
    } elif (gameepisode == 1) {
        return uint(gamemap == 8 && uint(motype) == 15u ? 1 : 0)
    } elif (gameepisode == 2) {
        return uint(gamemap == 8 && uint(motype) == 21u ? 1 : 0)
    } elif (gameepisode == 3) {
        return uint(gamemap == 8 && uint(motype) == 19u ? 1 : 0)
    } elif (gameepisode == 4) {
        return uint(gamemap == 6 && uint(motype) == 21u || gamemap == 8 && uint(motype) == 19u ? 1 : 0)
    } else {
        return uint(gamemap == 8 ? 1 : 0)
    }
}
[export, sideeffects]
def A_BossDeath(var mo_4 : mobj_s?) {
    var th_1 : thinker_s?
    var mo2_0 : mobj_s?
    var junk_0 : line_s = line_s()
    var i_1 : int
    if (uint(gamemode) == 2u) {
        if (gamemap != 7) {
            return
        }
        if (uint(mo_4.type_0) != 8u && uint(mo_4.type_0) != 20u) {
            return
        }
    } elif (CheckBossEnd(mo_4.type_0) == 0) {
        return
    }
    i_1 = 0
    while (i_1 < 4) {
        if (playeringame[i_1] != 0x0 && players[i_1].health > 0) {
            break
        }
        i_1++
    }
    if (i_1 == 4) {
        return
    }
    th_1 = unsafe(reinterpret<thinker_s?>(thinkercap.next))
    while (th_1 != unsafe(addr(thinkercap))) {
        if (unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(th_1))))[2]) != unsafe(reinterpret<actionf_p1>(@@P_MobjThinker))) {
            th_1 = unsafe(reinterpret<thinker_s?>(th_1.next))
            continue
        }
        mo2_0 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(th_1))))
        if (mo2_0 != mo_4 && uint(mo2_0.type_0) == uint(mo_4.type_0) && mo2_0.health > 0) {
            return
        }
        th_1 = unsafe(reinterpret<thinker_s?>(th_1.next))
    }
    if (uint(gamemode) == 2u) {
        if (gamemap == 7) {
            if (uint(mo_4.type_0) == 8u) {
                junk_0.tag = int16(666)
                EV_DoFloor(unsafe(addr<line_s?>(junk_0)), unsafe(reinterpret<floor_e>(1u)))
                return
            }
            if (uint(mo_4.type_0) == 20u) {
                junk_0.tag = int16(667)
                EV_DoFloor(unsafe(addr<line_s?>(junk_0)), unsafe(reinterpret<floor_e>(5u)))
                return
            }
        }
    } elif (gameepisode == 1) {
        junk_0.tag = int16(666)
        EV_DoFloor(unsafe(addr<line_s?>(junk_0)), unsafe(reinterpret<floor_e>(1u)))
        return
    } elif (gameepisode == 4) {
        if (gamemap == 6) {
            junk_0.tag = int16(666)
            EV_DoDoor(unsafe(addr<line_s?>(junk_0)), unsafe(reinterpret<vldoor_e>(6u)))
            return
        } elif (gamemap == 8) {
            junk_0.tag = int16(666)
            EV_DoFloor(unsafe(addr<line_s?>(junk_0)), unsafe(reinterpret<floor_e>(1u)))
            return
        }
    }
    G_ExitLevel()
    return
}
[export, sideeffects]
def A_Hoof(var mo_5 : mobj_s?) {
    S_StartSound(unsafe(reinterpret<uint8?>(mo_5)), 84)
    A_Chase(mo_5)
    return
}
[export, sideeffects]
def A_Metal(var mo_6 : mobj_s?) {
    S_StartSound(unsafe(reinterpret<uint8?>(mo_6)), 85)
    A_Chase(mo_6)
    return
}
[export, sideeffects]
def A_BabyMetal(var mo_7 : mobj_s?) {
    S_StartSound(unsafe(reinterpret<uint8?>(mo_7)), 79)
    A_Chase(mo_7)
    return
}
[export, sideeffects]
def A_OpenShotgun2(var player_0 : player_s?; var psp : pspdef_t?) {
    S_StartSound(unsafe(reinterpret<uint8?>(player_0.mo)), 5)
    return
}
[export, sideeffects]
def A_LoadShotgun2(var player_1 : player_s?; var psp_0 : pspdef_t?) {
    S_StartSound(unsafe(reinterpret<uint8?>(player_1.mo)), 7)
    return
}
[export, sideeffects]
def A_CloseShotgun2(var player_2 : player_s?; var psp_1 : pspdef_t?) {
    S_StartSound(unsafe(reinterpret<uint8?>(player_2.mo)), 6)
    A_ReFire(player_2, psp_1)
    return
}
var braintargets : mobj_s? [32]

var numbraintargets : int = default<int>

var braintargeton : int = 0

[export, sideeffects]
def A_BrainAwake(var mo_8 : mobj_s?) {
    var thinker : thinker_s?
    var m : mobj_s?
    numbraintargets = 0
    braintargeton = 0
    thinker = unsafe(reinterpret<thinker_s?>(thinkercap.next))
    thinker = unsafe(reinterpret<thinker_s?>(thinkercap.next))
    while (thinker != unsafe(addr(thinkercap))) {
        if (unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(thinker))))[2]) != unsafe(reinterpret<actionf_p1>(@@P_MobjThinker))) {
            thinker = unsafe(reinterpret<thinker_s?>(thinker.next))
            continue
        }
        m = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(thinker))))
        if (uint(m.type_0) == 27u) {
            braintargets[numbraintargets] = unsafe(reinterpret<mobj_s?>(m))
            numbraintargets++
        }
        thinker = unsafe(reinterpret<thinker_s?>(thinker.next))
    }
    S_StartSound(null, 96)
    return
}
[export, sideeffects]
def A_BrainPain(var mo_9 : mobj_s?) {
    S_StartSound(null, 97)
    return
}
[export, sideeffects]
def A_BrainScream(var mo_10 : mobj_s?) {
    var x_0 : int
    var y_0 : int
    var z_0 : int
    var th_2 : mobj_s?
    x_0 = mo_10.x - 196 * (1 << 16)
    while (x_0 < mo_10.x + 320 * (1 << 16)) {
        y_0 = mo_10.y - 320 * (1 << 16)
        z_0 = 128 + P_Random() * 2 * (1 << 16)
        th_2 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SpawnMobj(x_0, y_0, z_0, unsafe(reinterpret<mobjtype_t>(33u)))))))
        th_2.momz = P_Random() * 512
        P_SetMobjState(th_2, unsafe(reinterpret<statenum_t>(799u)))
        th_2.tics = th_2.tics - (P_Random() & 7)
        if (th_2.tics < 1) {
            th_2.tics = 1
        }
        x_0 += (1 << 16) * 8
    }
    S_StartSound(null, 98)
    return
}
[export, sideeffects]
def A_BrainExplode(var mo_11 : mobj_s?) {
    var x_1 : int
    var y_1 : int
    var z_1 : int
    var th_3 : mobj_s?
    x_1 = mo_11.x + (P_Random() - P_Random()) * 2048
    y_1 = mo_11.y
    z_1 = 128 + P_Random() * 2 * (1 << 16)
    th_3 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SpawnMobj(x_1, y_1, z_1, unsafe(reinterpret<mobjtype_t>(33u)))))))
    th_3.momz = P_Random() * 512
    P_SetMobjState(th_3, unsafe(reinterpret<statenum_t>(799u)))
    th_3.tics = th_3.tics - (P_Random() & 7)
    if (th_3.tics < 1) {
        th_3.tics = 1
    }
    return
}
[export, sideeffects]
def A_BrainDie(var mo_12 : mobj_s?) {
    G_ExitLevel()
    return
}
[export, sideeffects]
def A_BrainSpit(var mo_13 : mobj_s?) {
    var targ_0 : mobj_s?
    var newmobj_0 : mobj_s?
    A_BrainSpit__easy ^= 1
    if (int(gameskill) <= 1 && A_BrainSpit__easy == 0) {
        return
    }
    targ_0 = unsafe(reinterpret<mobj_s?>(braintargets[braintargeton]))
    braintargeton = (braintargeton + 1) % numbraintargets
    newmobj_0 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SpawnMissile(mo_13, targ_0, unsafe(reinterpret<mobjtype_t>(28u)))))))
    newmobj_0.target = targ_0
    newmobj_0.reactiontime = (targ_0.y - mo_13.y) / newmobj_0.momy / newmobj_0.state.tics
    S_StartSound(null, 94)
    return
}
[export, sideeffects]
def A_SpawnFly(var mo_14 : mobj_s?) {
    var newmobj_1 : mobj_s?
    var fog_0 : mobj_s?
    var targ_1 : mobj_s?
    var r : int
    var type_0 : mobjtype_t = mobjtype_t()
    let c2da_postinc_4 : int = mo_14.reactiontime
    mo_14.reactiontime = c2da_postinc_4 - 1
    if (c2da_postinc_4 - 1 != 0) {
        return
    }
    targ_1 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SubstNullMobj(mo_14.target)))))
    fog_0 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SpawnMobj(targ_1.x, targ_1.y, targ_1.z, unsafe(reinterpret<mobjtype_t>(29u)))))))
    S_StartSound(unsafe(reinterpret<uint8?>(fog_0)), 35)
    r = P_Random()
    if (r < 50) {
        type_0 = unsafe(reinterpret<mobjtype_t>(11u))
    } elif (r < 90) {
        type_0 = unsafe(reinterpret<mobjtype_t>(12u))
    } elif (r < 120) {
        type_0 = unsafe(reinterpret<mobjtype_t>(13u))
    } elif (r < 130) {
        type_0 = unsafe(reinterpret<mobjtype_t>(22u))
    } elif (r < 160) {
        type_0 = unsafe(reinterpret<mobjtype_t>(14u))
    } elif (r < 162) {
        type_0 = unsafe(reinterpret<mobjtype_t>(3u))
    } elif (r < 172) {
        type_0 = unsafe(reinterpret<mobjtype_t>(5u))
    } elif (r < 192) {
        type_0 = unsafe(reinterpret<mobjtype_t>(20u))
    } elif (r < 222) {
        type_0 = unsafe(reinterpret<mobjtype_t>(8u))
    } elif (r < 246) {
        type_0 = unsafe(reinterpret<mobjtype_t>(17u))
    } else {
        type_0 = unsafe(reinterpret<mobjtype_t>(15u))
    }
    newmobj_1 = unsafe(reinterpret<mobj_s?>(unsafe(reinterpret<mobj_s?>(P_SpawnMobj(targ_1.x, targ_1.y, targ_1.z, type_0)))))
    if (P_LookForPlayers(newmobj_1, 1u) != 0x0) {
        P_SetMobjState(newmobj_1, unsafe(reinterpret<statenum_t>(uint(newmobj_1.info.seestate))))
    }
    P_TeleportMove(newmobj_1, newmobj_1.x, newmobj_1.y)
    P_RemoveMobj(mo_14)
    return
}
[export, sideeffects]
def A_SpawnSound(var mo_15 : mobj_s?) {
    S_StartSound(unsafe(reinterpret<uint8?>(mo_15)), 95)
    A_SpawnFly(mo_15)
    return
}
[export, sideeffects]
def A_PlayerScream(var mo_16 : mobj_s?) {
    var sound_1 : int = 57
    if (uint(gamemode) == 2u && mo_16.health < -50) {
        sound_1 = 58
    }
    S_StartSound(unsafe(reinterpret<uint8?>(mo_16)), sound_1)
    return
}
[sideeffects]
def private c2da_layout_proofs_12() {
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
}
