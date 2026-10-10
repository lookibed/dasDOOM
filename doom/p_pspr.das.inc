[export, sideeffects]
def P_SetupPsprites(var player : player_s?) {
    for (i in range(0, 2)) {
        var c2da_fresh0 : pspdef_t? = unsafe(reinterpret<pspdef_t?>(unsafe(reinterpret<uint64>(player)) + 272ul))
        unsafe(unsafe(reinterpret<pspdef_t?>(c2da_fresh0))[i]).state = null
    }
    player.pendingweapon = player.readyweapon
    P_BringUpWeapon(player)
    return
}
[export, sideeffects]
def P_BringUpWeapon(var player_0 : player_s?) {
    var newstate : statenum_t = statenum_t()
    if (uint(player_0.pendingweapon) == 10u) {
        player_0.pendingweapon = player_0.readyweapon
    }
    if (uint(player_0.pendingweapon) == 7u) {
        S_StartSound(unsafe(reinterpret<uint8?>(player_0.mo)), 10)
    }
    newstate = unsafe(reinterpret<statenum_t>(uint(weaponinfo[int(player_0.pendingweapon)].upstate)))
    player_0.pendingweapon = unsafe(reinterpret<weapontype_t>(10u))
    var c2da_fresh1 : pspdef_t? = unsafe(reinterpret<pspdef_t?>(unsafe(reinterpret<uint64>(player_0)) + 272ul))
    unsafe(unsafe(reinterpret<pspdef_t?>(c2da_fresh1))[0]).sy = 128 * (1 << 16)
    P_SetPsprite(player_0, 0, newstate)
    return
}
[export, sideeffects]
def P_SetPsprite(var player_1 : player_s?; var position : int; var stnum : statenum_t) {
    var psp : pspdef_t?
    var state : state_t?
    var c2da_fresh2 : pspdef_t? = unsafe(reinterpret<pspdef_t?>(unsafe(reinterpret<uint64>(player_1)) + 272ul))
    psp = unsafe(addr<pspdef_t?>(unsafe(unsafe(reinterpret<pspdef_t?>(c2da_fresh2))[position])))
    while (true) {
        if (uint(stnum) == 0u) {
            psp.state = null
            break
        }
        state = unsafe(addr<state_t?>(unsafe(unsafe(addr(states[0]))[int(stnum)])))
        psp.state = state
        psp.tics = int(state.tics)  // nolint:PERF020
        if (state.misc1 != 0) {
            psp.sx = state.misc1 << 16
            psp.sy = state.misc2 << 16
        }
        if (unsafe(unsafe(reinterpret<actionf_p2?>(unsafe(reinterpret<uint64>(state))))[2]) != default<actionf_p2>) {
            invoke(unsafe(unsafe(reinterpret<actionf_p2?>(unsafe(reinterpret<uint64>(state))))[2]), unsafe(reinterpret<uint8?>(player_1)), unsafe(reinterpret<uint8?>(psp)))
            if (psp.state == null) {
                break
            }
        }
        stnum = psp.state.nextstate
        if (psp.tics != 0) {
            break
        }
    }
    return
}
[export, sideeffects]
def P_MovePsprites(var player_2 : player_s?) {
    var i_0 : int
    var psp_0 : pspdef_t?
    var state_0 : state_t?
    var c2da_fresh3 : pspdef_t? = unsafe(reinterpret<pspdef_t?>(unsafe(reinterpret<uint64>(player_2)) + 272ul))
    psp_0 = unsafe(addr<pspdef_t?>(unsafe(unsafe(reinterpret<pspdef_t?>(c2da_fresh3))[0])))
    var c2da_psp_0_addr : uint64 = unsafe(reinterpret<uint64>(psp_0))
    i_0 = 0
    while (i_0 < 2) {
        state_0 = unsafe(reinterpret<state_t?>(unsafe(reinterpret<pspdef_t?>(c2da_psp_0_addr)).state))
        if (state_0 != null) {
            if (unsafe(reinterpret<pspdef_t?>(c2da_psp_0_addr)).tics != -1) {
                let c2da_postinc : int = unsafe(reinterpret<pspdef_t?>(c2da_psp_0_addr)).tics
                unsafe(reinterpret<pspdef_t?>(c2da_psp_0_addr)).tics = c2da_postinc - 1
                if (unsafe(reinterpret<pspdef_t?>(c2da_psp_0_addr)).tics == 0) {
                    P_SetPsprite(player_2, i_0, unsafe(reinterpret<pspdef_t?>(c2da_psp_0_addr)).state.nextstate)
                }
            }
        }
        i_0++
        c2da_psp_0_addr += 24ul
    }
    var c2da_fresh4 : pspdef_t? = unsafe(reinterpret<pspdef_t?>(unsafe(reinterpret<uint64>(player_2)) + 272ul))
    var c2da_fresh5 : pspdef_t? = unsafe(reinterpret<pspdef_t?>(unsafe(reinterpret<uint64>(player_2)) + 272ul))
    unsafe(unsafe(reinterpret<pspdef_t?>(c2da_fresh4))[1]).sx = int(unsafe(unsafe(reinterpret<pspdef_t?>(c2da_fresh5))[0]).sx)  // nolint:PERF020
    var c2da_fresh6 : pspdef_t? = unsafe(reinterpret<pspdef_t?>(unsafe(reinterpret<uint64>(player_2)) + 272ul))
    var c2da_fresh7 : pspdef_t? = unsafe(reinterpret<pspdef_t?>(unsafe(reinterpret<uint64>(player_2)) + 272ul))
    unsafe(unsafe(reinterpret<pspdef_t?>(c2da_fresh6))[1]).sy = int(unsafe(unsafe(reinterpret<pspdef_t?>(c2da_fresh7))[0]).sy)  // nolint:PERF020
    return
}
[export, sideeffects]
def P_DropWeapon(var player_3 : player_s?) {
    P_SetPsprite(player_3, 0, unsafe(reinterpret<statenum_t>(uint(weaponinfo[int(player_3.readyweapon)].downstate))))
    return
}
var swingx : int = default<int>

var swingy : int = default<int>

[export, sideeffects]
def P_CalcSwing(var player_4 : player_s?) {
    var swing : int
    var angle : int
    swing = player_4.bob
    angle = 8192 / 70 * leveltime & 8192 - 1
    swingx = FixedMul(swing, finesine[angle])
    angle = 8192 / 70 * leveltime + 8192 / 2 & 8192 - 1
    swingy = -FixedMul(swingx, finesine[angle])
    return
}
[export, sideeffects]
def P_CheckAmmo(var player_5 : player_s?) : uint {
    var ammo : ammotype_t = ammotype_t()
    var count : int
    ammo = weaponinfo[int(player_5.readyweapon)].ammo
    if (uint(player_5.readyweapon) == 6u) {
        count = 40
    } elif (uint(player_5.readyweapon) == 8u) {
        count = 2
    } else {
        count = 1
    }
    var c2da_fresh9 : int = 1
    if (!(uint(ammo) == 5u)) {
        var c2da_fresh8 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(player_5)) + 168ul))
        if (!(unsafe(unsafe(reinterpret<int?>(c2da_fresh8))[int(ammo)]) >= count)) {
            c2da_fresh9 = 0
        }
    }
    if (c2da_fresh9 != 0) {
        return 1u
    }
    while (true) {
        var c2da_fresh10 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(player_5)) + 132ul))
        var c2da_fresh12 : int = 0
        if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh10))[5]) != 0x0) {
            var c2da_fresh11 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(player_5)) + 168ul))
            if (unsafe(unsafe(reinterpret<int?>(c2da_fresh11))[2]) != 0) {
                c2da_fresh12 = 1
            }
        }
        if (c2da_fresh12 != 0 && uint(gamemode) != 0u) {
            player_5.pendingweapon = unsafe(reinterpret<weapontype_t>(5u))
        } else {
            var c2da_fresh13 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(player_5)) + 132ul))
            var c2da_fresh15 : int = 0
            if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh13))[8]) != 0x0) {
                var c2da_fresh14 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(player_5)) + 168ul))
                if (unsafe(unsafe(reinterpret<int?>(c2da_fresh14))[1]) > 2) {
                    c2da_fresh15 = 1
                }
            }
            if (c2da_fresh15 != 0 && uint(gamemode) == 2u) {
                player_5.pendingweapon = unsafe(reinterpret<weapontype_t>(8u))
            } else {
                var c2da_fresh16 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(player_5)) + 132ul))
                var c2da_fresh18 : int = 0
                if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh16))[3]) != 0x0) {
                    var c2da_fresh17 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(player_5)) + 168ul))
                    if (unsafe(unsafe(reinterpret<int?>(c2da_fresh17))[0]) != 0) {
                        c2da_fresh18 = 1
                    }
                }
                if (c2da_fresh18 != 0) {
                    player_5.pendingweapon = unsafe(reinterpret<weapontype_t>(3u))
                } else {
                    var c2da_fresh19 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(player_5)) + 132ul))
                    var c2da_fresh21 : int = 0
                    if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh19))[2]) != 0x0) {
                        var c2da_fresh20 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(player_5)) + 168ul))
                        if (unsafe(unsafe(reinterpret<int?>(c2da_fresh20))[1]) != 0) {
                            c2da_fresh21 = 1
                        }
                    }
                    if (c2da_fresh21 != 0) {
                        player_5.pendingweapon = unsafe(reinterpret<weapontype_t>(2u))
                    } else {
                        var c2da_fresh22 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(player_5)) + 168ul))
                        if (unsafe(unsafe(reinterpret<int?>(c2da_fresh22))[0]) != 0) {
                            player_5.pendingweapon = unsafe(reinterpret<weapontype_t>(1u))
                        } else {
                            var c2da_fresh23 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(player_5)) + 132ul))
                            if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh23))[7]) != 0x0) {
                                player_5.pendingweapon = unsafe(reinterpret<weapontype_t>(7u))
                            } else {
                                var c2da_fresh24 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(player_5)) + 132ul))
                                var c2da_fresh26 : int = 0
                                if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh24))[4]) != 0x0) {
                                    var c2da_fresh25 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(player_5)) + 168ul))
                                    if (unsafe(unsafe(reinterpret<int?>(c2da_fresh25))[3]) != 0) {
                                        c2da_fresh26 = 1
                                    }
                                }
                                if (c2da_fresh26 != 0) {
                                    player_5.pendingweapon = unsafe(reinterpret<weapontype_t>(4u))
                                } else {
                                    var c2da_fresh27 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(player_5)) + 132ul))
                                    var c2da_fresh29 : int = 0
                                    if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh27))[6]) != 0x0) {
                                        var c2da_fresh28 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(player_5)) + 168ul))
                                        if (unsafe(unsafe(reinterpret<int?>(c2da_fresh28))[2]) > 40) {
                                            c2da_fresh29 = 1
                                        }
                                    }
                                    if (c2da_fresh29 != 0 && uint(gamemode) != 0u) {
                                        player_5.pendingweapon = unsafe(reinterpret<weapontype_t>(6u))
                                    } else {
                                        player_5.pendingweapon = unsafe(reinterpret<weapontype_t>(0u))
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (uint(player_5.pendingweapon) != 10u) {
            break
        }
    }
    P_SetPsprite(player_5, 0, unsafe(reinterpret<statenum_t>(uint(weaponinfo[int(player_5.readyweapon)].downstate))))
    return 0u
}
[export, sideeffects]
def P_FireWeapon(var player_6 : player_s?) {
    var newstate_0 : statenum_t = statenum_t()
    if (P_CheckAmmo(player_6) == 0) {
        return
    }
    P_SetMobjState(player_6.mo, unsafe(reinterpret<statenum_t>(154u)))
    newstate_0 = unsafe(reinterpret<statenum_t>(uint(weaponinfo[int(player_6.readyweapon)].atkstate)))
    P_SetPsprite(player_6, 0, newstate_0)
    P_NoiseAlert(player_6.mo, player_6.mo)
    return
}
[export, sideeffects]
def A_WeaponReady(var player_7 : player_s?; var psp_1 : pspdef_t?) {
    var newstate_1 : statenum_t = statenum_t()
    var angle_0 : int
    if (player_7.mo.state == unsafe(addr(unsafe(unsafe(addr(states[0]))[154]))) || player_7.mo.state == unsafe(addr(unsafe(unsafe(addr(states[0]))[155])))) {
        P_SetMobjState(player_7.mo, unsafe(reinterpret<statenum_t>(149u)))
    }
    if (uint(player_7.readyweapon) == 7u && psp_1.state == unsafe(addr(unsafe(unsafe(addr(states[0]))[67])))) {
        S_StartSound(unsafe(reinterpret<uint8?>(player_7.mo)), 11)
    }
    if (uint(player_7.pendingweapon) != 10u || player_7.health == 0) {
        newstate_1 = unsafe(reinterpret<statenum_t>(uint(weaponinfo[int(player_7.readyweapon)].downstate)))
        P_SetPsprite(player_7, 0, newstate_1)
        return
    }
    if ((int(player_7.cmd.buttons) & 1) != 0) {
        if (player_7.attackdown == 0 || uint(player_7.readyweapon) != 4u && uint(player_7.readyweapon) != 6u) {
            player_7.attackdown = 1
            P_FireWeapon(player_7)
            return
        }
    } else {
        player_7.attackdown = 0
    }
    angle_0 = 128 * leveltime & 8192 - 1
    psp_1.sx = (1 << 16) + FixedMul(player_7.bob, unsafe(finecosine[angle_0]))
    angle_0 &= 8192 / 2 - 1
    psp_1.sy = 32 * (1 << 16) + FixedMul(player_7.bob, finesine[angle_0])
    return
}
[export, sideeffects]
def A_ReFire(var player_8 : player_s?; var psp_2 : pspdef_t?) {
    if ((int(player_8.cmd.buttons) & 1) != 0 && uint(player_8.pendingweapon) == 10u && player_8.health != 0) {
        let c2da_postinc_0 : int = player_8.refire
        player_8.refire = c2da_postinc_0 + 1
        P_FireWeapon(player_8)
    } else {
        player_8.refire = 0
        P_CheckAmmo(player_8)
    }
    return
}
[export, sideeffects]
def A_CheckReload(var player_9 : player_s?; var psp_3 : pspdef_t?) {
    P_CheckAmmo(player_9)
    return
}
[export, sideeffects]
def A_Lower(var player_10 : player_s?; var psp_4 : pspdef_t?) {
    psp_4.sy += (1 << 16) * 6
    if (psp_4.sy < 128 * (1 << 16)) {
        return
    }
    if (uint(player_10.playerstate) == 1u) {
        psp_4.sy = 128 * (1 << 16)
        return
    }
    if (player_10.health == 0) {
        P_SetPsprite(player_10, 0, unsafe(reinterpret<statenum_t>(0u)))
        return
    }
    player_10.readyweapon = player_10.pendingweapon
    P_BringUpWeapon(player_10)
    return
}
[export, sideeffects]
def A_Raise(var player_11 : player_s?; var psp_5 : pspdef_t?) {
    var newstate_2 : statenum_t = statenum_t()
    psp_5.sy -= (1 << 16) * 6
    if (psp_5.sy > 32 * (1 << 16)) {
        return
    }
    psp_5.sy = 32 * (1 << 16)
    newstate_2 = unsafe(reinterpret<statenum_t>(uint(weaponinfo[int(player_11.readyweapon)].readystate)))
    P_SetPsprite(player_11, 0, newstate_2)
    return
}
[export, sideeffects]
def A_GunFlash(var player_12 : player_s?; var psp_6 : pspdef_t?) {
    P_SetMobjState(player_12.mo, unsafe(reinterpret<statenum_t>(155u)))
    P_SetPsprite(player_12, 1, unsafe(reinterpret<statenum_t>(uint(weaponinfo[int(player_12.readyweapon)].flashstate))))
    return
}
[export, sideeffects]
def A_Punch(var player_13 : player_s?; var psp_7 : pspdef_t?) {
    var angle_1 : uint
    var damage : int
    var slope : int
    damage = P_Random() % 10 + 1 << 1
    var c2da_fresh30 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(player_13)) + 56ul))
    if (unsafe(unsafe(reinterpret<int?>(c2da_fresh30))[1]) != 0) {
        damage *= 10
    }
    angle_1 = player_13.mo.angle
    angle_1 = angle_1 + uint(P_Random() - P_Random() << 18)
    slope = P_AimLineAttack(player_13.mo, angle_1, 64 * (1 << 16))
    P_LineAttack(player_13.mo, angle_1, 64 * (1 << 16), slope, damage)
    if (linetarget != null) {
        S_StartSound(unsafe(reinterpret<uint8?>(player_13.mo)), 83)
        player_13.mo.angle = R_PointToAngle2(player_13.mo.x, player_13.mo.y, linetarget.x, linetarget.y)
    }
    return
}
[export, sideeffects]
def A_Saw(var player_14 : player_s?; var psp_8 : pspdef_t?) {
    var angle_2 : uint
    var damage_0 : int
    var slope_0 : int
    damage_0 = 2 * (P_Random() % 10 + 1)
    angle_2 = player_14.mo.angle
    angle_2 = angle_2 + uint(P_Random() - P_Random() << 18)
    slope_0 = P_AimLineAttack(player_14.mo, angle_2, 64 * (1 << 16) + 1)
    P_LineAttack(player_14.mo, angle_2, 64 * (1 << 16) + 1, slope_0, damage_0)
    if (linetarget == null) {
        S_StartSound(unsafe(reinterpret<uint8?>(player_14.mo)), 12)
        return
    }
    S_StartSound(unsafe(reinterpret<uint8?>(player_14.mo)), 13)
    angle_2 = uint(R_PointToAngle2(player_14.mo.x, player_14.mo.y, linetarget.x, linetarget.y))
    if (angle_2 - player_14.mo.angle > 0x80000000u) {
        if (int(angle_2 - player_14.mo.angle) < -1073741824 / 20) {
            player_14.mo.angle = angle_2 + uint(1073741824 / 21)
        } else {
            player_14.mo.angle -= uint(1073741824 / 20)
        }
    } elif (angle_2 - player_14.mo.angle > uint(1073741824 / 20)) {
        player_14.mo.angle = angle_2 - uint(1073741824 / 21)
    } else {
        player_14.mo.angle += uint(1073741824 / 20)
    }
    player_14.mo.flags |= 128
    return
}
[sideeffects]
def private DecreaseAmmo(var player_15 : player_s?; var ammonum : int; var amount : int) {
    if (ammonum < 4) {
        var c2da_fresh31 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(player_15)) + 168ul))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh31))[ammonum]) -= amount
    } else {
        var c2da_fresh32 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(player_15)) + 184ul))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh32))[ammonum - 4]) -= amount
    }
    return
}
[export, sideeffects]
def A_FireMissile(var player_16 : player_s?; var psp_9 : pspdef_t?) {
    DecreaseAmmo(player_16, int(weaponinfo[int(player_16.readyweapon)].ammo), 1)
    P_SpawnPlayerMissile(player_16.mo, unsafe(reinterpret<mobjtype_t>(33u)))
    return
}
[export, sideeffects]
def A_FireBFG(var player_17 : player_s?; var psp_10 : pspdef_t?) {
    DecreaseAmmo(player_17, int(weaponinfo[int(player_17.readyweapon)].ammo), 40)
    P_SpawnPlayerMissile(player_17.mo, unsafe(reinterpret<mobjtype_t>(35u)))
    return
}
[export, sideeffects]
def A_FirePlasma(var player_18 : player_s?; var psp_11 : pspdef_t?) {
    DecreaseAmmo(player_18, int(weaponinfo[int(player_18.readyweapon)].ammo), 1)
    P_SetPsprite(player_18, 1, unsafe(reinterpret<statenum_t>(uint(weaponinfo[int(player_18.readyweapon)].flashstate + (P_Random() & 1)))))
    P_SpawnPlayerMissile(player_18.mo, unsafe(reinterpret<mobjtype_t>(34u)))
    return
}
var bulletslope : int = default<int>

[export, sideeffects]
def P_BulletSlope(var mo : mobj_s?) {
    var an : uint = mo.angle
    bulletslope = P_AimLineAttack(mo, an, 16 * 64 * (1 << 16))
    if (linetarget == null) {
        an += uint(1 << 26)
        bulletslope = P_AimLineAttack(mo, an, 16 * 64 * (1 << 16))
        if (linetarget == null) {
            an -= uint(2 << 26)
            bulletslope = P_AimLineAttack(mo, an, 16 * 64 * (1 << 16))
        }
    }
    return
}
[export, sideeffects]
def P_GunShot(var mo_0 : mobj_s?; var accurate : uint) {
    var angle_3 : uint
    var damage_1 : int = 5 * (P_Random() % 3 + 1)
    angle_3 = mo_0.angle
    if (accurate == 0) {
        angle_3 = angle_3 + uint(P_Random() - P_Random() << 18)
    }
    P_LineAttack(mo_0, angle_3, 32 * 64 * (1 << 16), bulletslope, damage_1)
    return
}
[export, sideeffects]
def A_FirePistol(var player_19 : player_s?; var psp_12 : pspdef_t?) {
    S_StartSound(unsafe(reinterpret<uint8?>(player_19.mo)), 1)
    P_SetMobjState(player_19.mo, unsafe(reinterpret<statenum_t>(155u)))
    DecreaseAmmo(player_19, int(weaponinfo[int(player_19.readyweapon)].ammo), 1)
    P_SetPsprite(player_19, 1, unsafe(reinterpret<statenum_t>(uint(weaponinfo[int(player_19.readyweapon)].flashstate))))
    P_BulletSlope(player_19.mo)
    P_GunShot(player_19.mo, player_19.refire == 0 ? 1u : 0u)
    return
}
[export, sideeffects]
def A_FireShotgun(var player_20 : player_s?; var psp_13 : pspdef_t?) {
    S_StartSound(unsafe(reinterpret<uint8?>(player_20.mo)), 2)
    P_SetMobjState(player_20.mo, unsafe(reinterpret<statenum_t>(155u)))
    DecreaseAmmo(player_20, int(weaponinfo[int(player_20.readyweapon)].ammo), 1)
    P_SetPsprite(player_20, 1, unsafe(reinterpret<statenum_t>(uint(weaponinfo[int(player_20.readyweapon)].flashstate))))
    P_BulletSlope(player_20.mo)
    for (i_1 in range(0, 7)) {
        P_GunShot(player_20.mo, 0u)
    }
    return
}
[export, sideeffects]
def A_FireShotgun2(var player_21 : player_s?; var psp_14 : pspdef_t?) {
    var angle_4 : uint
    var damage_2 : int
    S_StartSound(unsafe(reinterpret<uint8?>(player_21.mo)), 4)
    P_SetMobjState(player_21.mo, unsafe(reinterpret<statenum_t>(155u)))
    DecreaseAmmo(player_21, int(weaponinfo[int(player_21.readyweapon)].ammo), 2)
    P_SetPsprite(player_21, 1, unsafe(reinterpret<statenum_t>(uint(weaponinfo[int(player_21.readyweapon)].flashstate))))
    P_BulletSlope(player_21.mo)
    for (i_2 in range(0, 20)) {
        damage_2 = 5 * (P_Random() % 3 + 1)
        angle_4 = player_21.mo.angle
        angle_4 = angle_4 + uint(P_Random() - P_Random() << 19)
        P_LineAttack(player_21.mo, angle_4, 32 * 64 * (1 << 16), bulletslope + (P_Random() - P_Random() << 5), damage_2)
    }
    return
}
[export, sideeffects]
def A_FireCGun(var player_22 : player_s?; var psp_15 : pspdef_t?) {
    S_StartSound(unsafe(reinterpret<uint8?>(player_22.mo)), 1)
    var c2da_fresh33 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(player_22)) + 168ul))
    if (unsafe(unsafe(reinterpret<int?>(c2da_fresh33))[int(weaponinfo[int(player_22.readyweapon)].ammo)]) == 0) {
        return
    }
    P_SetMobjState(player_22.mo, unsafe(reinterpret<statenum_t>(155u)))
    DecreaseAmmo(player_22, int(weaponinfo[int(player_22.readyweapon)].ammo), 1)
    P_SetPsprite(player_22, 1, unsafe(reinterpret<statenum_t>(uint(unsafe(unsafe(psp_15.state + int(weaponinfo[int(player_22.readyweapon)].flashstate)) - unsafe(addr(unsafe(unsafe(addr(states[0]))[52]))))))))
    P_BulletSlope(player_22.mo)
    P_GunShot(player_22.mo, player_22.refire == 0 ? 1u : 0u)
    return
}
[export, sideeffects]
def A_Light0(var player_23 : player_s?; var psp_16 : pspdef_t?) {
    player_23.extralight = 0
    return
}
[export, sideeffects]
def A_Light1(var player_24 : player_s?; var psp_17 : pspdef_t?) {
    player_24.extralight = 1
    return
}
[export, sideeffects]
def A_Light2(var player_25 : player_s?; var psp_18 : pspdef_t?) {
    player_25.extralight = 2
    return
}
[export, sideeffects]
def A_BFGSpray(var mo_1 : mobj_s?) {
    var damage_3 : int
    var an_0 : uint
    for (i_3 in range(0, 40)) {
        an_0 = mo_1.angle - uint(1073741824 / 2) + uint(1073741824 / 40 * i_3)
        P_AimLineAttack(mo_1.target, an_0, 16 * 64 * (1 << 16))
        if (linetarget == null) {
            continue
        }
        P_SpawnMobj(linetarget.x, linetarget.y, linetarget.z + (linetarget.height >> 2), unsafe(reinterpret<mobjtype_t>(42u)))
        damage_3 = 0
        for (j in range(0, 15)) {
            damage_3 = damage_3 + ((P_Random() & 7) + 1)
        }
        P_DamageMobj(linetarget, mo_1.target, mo_1.target, damage_3)
    }
    return
}
[export, sideeffects]
def A_BFGsound(var player_26 : player_s?; var psp_19 : pspdef_t?) {
    S_StartSound(unsafe(reinterpret<uint8?>(player_26.mo)), 9)
    return
}
[sideeffects]
def private c2da_layout_proofs_20() {
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
    static_assert(typeinfo sizeof(type<weaponinfo_t>) == 24, "C layout of weaponinfo_t: sizeof")
    static_assert(typeinfo alignof(type<weaponinfo_t>) == 4, "C layout of weaponinfo_t: alignof")
    static_assert(typeinfo offsetof<ammo>(type<weaponinfo_t>) == 0, "C layout of weaponinfo_t: offsetof ammo")
    static_assert(typeinfo offsetof<upstate>(type<weaponinfo_t>) == 4, "C layout of weaponinfo_t: offsetof upstate")
    static_assert(typeinfo offsetof<downstate>(type<weaponinfo_t>) == 8, "C layout of weaponinfo_t: offsetof downstate")
    static_assert(typeinfo offsetof<readystate>(type<weaponinfo_t>) == 12, "C layout of weaponinfo_t: offsetof readystate")
    static_assert(typeinfo offsetof<atkstate>(type<weaponinfo_t>) == 16, "C layout of weaponinfo_t: offsetof atkstate")
    static_assert(typeinfo offsetof<flashstate>(type<weaponinfo_t>) == 20, "C layout of weaponinfo_t: offsetof flashstate")
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
