var private c2da_str_p_switch_0 : array<int8> = [int8(80), int8(95), int8(83), int8(116), int8(97), int8(114), int8(116), int8(66), int8(117), int8(116), int8(116), int8(111), int8(110), int8(58), int8(32), int8(110), int8(111), int8(32), int8(98), int8(117), int8(116), int8(116), int8(111), int8(110), int8(32), int8(115), int8(108), int8(111), int8(116), int8(115), int8(32), int8(108), int8(101), int8(102), int8(116), int8(33), int8(0)]

[export, sideeffects]
def P_UseSpecialLine(var thing : mobj_s?; var line : line_s?; var side : int) : uint {
    var c2da_fresh0 : int
    var c2da_fresh1 : int
    var c2da_fresh2 : int
    if (side != 0) {
        c2da_fresh0 = int(line.special)
        if (c2da_fresh0 == 124) {
        } else {
            return 0u
        }
    }
    if (thing.player == null) {
        if ((int(line.flags) & 32) != 0) {
            return 0u
        }
        c2da_fresh1 = int(line.special)
        if (c2da_fresh1 == 1 || c2da_fresh1 == 32 || c2da_fresh1 == 33 || c2da_fresh1 == 34) {
        } else {
            return 0u
        }
    }
    c2da_fresh2 = int(line.special)
    if (c2da_fresh2 < 65) {
        if (c2da_fresh2 < 32) {
            if (c2da_fresh2 < 20) {
                if (c2da_fresh2 < 11) {
                    if (c2da_fresh2 == 1) {
                        goto label 0
                    } elif (c2da_fresh2 == 7) {
                        goto label 1
                    } elif (c2da_fresh2 == 9) {
                        goto label 2
                    }
                } else {
                    if (c2da_fresh2 == 11) {
                        goto label 3
                    } elif (c2da_fresh2 == 14) {
                        goto label 4
                    } elif (c2da_fresh2 == 15) {
                        goto label 5
                    } elif (c2da_fresh2 == 18) {
                        goto label 6
                    }
                }
            } else {
                if (c2da_fresh2 >= 20 && c2da_fresh2 <= 31) {
                    goto c2da_fresh2 + 1
                }
            }
        } else {
            if (c2da_fresh2 < 50) {
                if (c2da_fresh2 < 42) {
                    if (c2da_fresh2 == 32) {
                        goto label 0
                    } elif (c2da_fresh2 == 33) {
                        goto label 0
                    } elif (c2da_fresh2 == 34) {
                        goto label 0
                    } elif (c2da_fresh2 == 41) {
                        goto label 7
                    }
                } else {
                    if (c2da_fresh2 == 42) {
                        goto label 10
                    } elif (c2da_fresh2 == 43) {
                        goto label 11
                    } elif (c2da_fresh2 == 45) {
                        goto label 12
                    } elif (c2da_fresh2 == 49) {
                        goto label 9
                    }
                }
            } else {
                if (c2da_fresh2 >= 50 && c2da_fresh2 <= 64) {
                    goto c2da_fresh2 - 17
                }
            }
        }
    } else {
        if (c2da_fresh2 < 116) {
            if (c2da_fresh2 < 101) {
                if (c2da_fresh2 < 69) {
                    if (c2da_fresh2 == 65) {
                        goto label 15
                    } elif (c2da_fresh2 == 66) {
                        goto label 13
                    } elif (c2da_fresh2 == 67) {
                        goto label 14
                    } elif (c2da_fresh2 == 68) {
                        goto label 16
                    }
                } else {
                    if (c2da_fresh2 == 69) {
                        goto label 17
                    } elif (c2da_fresh2 == 70) {
                        goto label 18
                    } elif (c2da_fresh2 == 71) {
                        goto label 8
                    } elif (c2da_fresh2 == 99) {
                        goto label 19
                    }
                }
            } else {
                if (c2da_fresh2 >= 101 && c2da_fresh2 <= 115) {
                    goto c2da_fresh2 - 53
                }
            }
        } else {
            if (c2da_fresh2 >= 116 && c2da_fresh2 <= 140) {
                goto c2da_fresh2 - 53
            }
        }
    }
    goto label 20
    label 0:
    label 27:
    label 28:
    label 29:
    label 32:
    label 64:
    label 65:
    EV_VerticalDoor(line, thing)
    goto label 20
    label 1:
    if (EV_BuildStairs(line, unsafe(reinterpret<stair_e>(0u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 2:
    if (EV_DoDonut(line) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 3:
    P_ChangeSwitchTexture(line, 0)
    G_ExitLevel()
    goto label 20
    label 4:
    if (EV_DoPlat(line, unsafe(reinterpret<plattype_e>(2u)), 32) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 5:
    if (EV_DoPlat(line, unsafe(reinterpret<plattype_e>(2u)), 24) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 6:
    if (EV_DoFloor(line, unsafe(reinterpret<floor_e>(4u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 21:
    if (EV_DoPlat(line, unsafe(reinterpret<plattype_e>(3u)), 0) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 22:
    if (EV_DoPlat(line, unsafe(reinterpret<plattype_e>(1u)), 0) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 24:
    if (EV_DoFloor(line, unsafe(reinterpret<floor_e>(1u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 30:
    if (EV_DoDoor(line, unsafe(reinterpret<vldoor_e>(0u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 7:
    if (EV_DoCeiling(line, unsafe(reinterpret<ceiling_e>(0u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 8:
    if (EV_DoFloor(line, unsafe(reinterpret<floor_e>(2u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 9:
    if (EV_DoCeiling(line, unsafe(reinterpret<ceiling_e>(3u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 33:
    if (EV_DoDoor(line, unsafe(reinterpret<vldoor_e>(2u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 34:
    P_ChangeSwitchTexture(line, 0)
    G_SecretExitLevel()
    goto label 20
    label 38:
    if (EV_DoFloor(line, unsafe(reinterpret<floor_e>(9u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 48:
    if (EV_DoFloor(line, unsafe(reinterpret<floor_e>(3u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 49:
    if (EV_DoFloor(line, unsafe(reinterpret<floor_e>(0u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 50:
    if (EV_DoDoor(line, unsafe(reinterpret<vldoor_e>(3u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 58:
    if (EV_DoDoor(line, unsafe(reinterpret<vldoor_e>(5u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 59:
    if (EV_DoDoor(line, unsafe(reinterpret<vldoor_e>(6u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 60:
    if (EV_DoDoor(line, unsafe(reinterpret<vldoor_e>(7u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 69:
    if (EV_DoPlat(line, unsafe(reinterpret<plattype_e>(4u)), 0) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 74:
    if (EV_BuildStairs(line, unsafe(reinterpret<stair_e>(1u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 78:
    if (EV_DoFloor(line, unsafe(reinterpret<floor_e>(10u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 80:
    label 82:
    label 84:
    if (EV_DoLockedDoor(line, unsafe(reinterpret<vldoor_e>(6u)), thing) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 87:
    if (EV_DoFloor(line, unsafe(reinterpret<floor_e>(12u))) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 10:
    if (EV_DoDoor(line, unsafe(reinterpret<vldoor_e>(2u))) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 11:
    if (EV_DoCeiling(line, unsafe(reinterpret<ceiling_e>(0u))) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 12:
    if (EV_DoFloor(line, unsafe(reinterpret<floor_e>(0u))) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 43:
    if (EV_DoFloor(line, unsafe(reinterpret<floor_e>(1u))) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 44:
    if (EV_DoDoor(line, unsafe(reinterpret<vldoor_e>(3u))) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 45:
    if (EV_DoPlat(line, unsafe(reinterpret<plattype_e>(1u)), 1) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 46:
    if (EV_DoDoor(line, unsafe(reinterpret<vldoor_e>(0u))) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 47:
    if (EV_DoFloor(line, unsafe(reinterpret<floor_e>(3u))) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 13:
    if (EV_DoPlat(line, unsafe(reinterpret<plattype_e>(2u)), 24) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 14:
    if (EV_DoPlat(line, unsafe(reinterpret<plattype_e>(2u)), 32) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 15:
    if (EV_DoFloor(line, unsafe(reinterpret<floor_e>(9u))) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 16:
    if (EV_DoPlat(line, unsafe(reinterpret<plattype_e>(3u)), 0) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 17:
    if (EV_DoFloor(line, unsafe(reinterpret<floor_e>(4u))) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 18:
    if (EV_DoFloor(line, unsafe(reinterpret<floor_e>(2u))) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 61:
    if (EV_DoDoor(line, unsafe(reinterpret<vldoor_e>(5u))) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 62:
    if (EV_DoDoor(line, unsafe(reinterpret<vldoor_e>(6u))) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 63:
    if (EV_DoDoor(line, unsafe(reinterpret<vldoor_e>(7u))) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 70:
    if (EV_DoPlat(line, unsafe(reinterpret<plattype_e>(4u)), 0) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 79:
    if (EV_DoFloor(line, unsafe(reinterpret<floor_e>(10u))) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 19:
    label 81:
    label 83:
    if (EV_DoLockedDoor(line, unsafe(reinterpret<vldoor_e>(6u)), thing) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 85:
    EV_LightTurnOn(line, 255)
    P_ChangeSwitchTexture(line, 1)
    goto label 20
    label 86:
    EV_LightTurnOn(line, 35)
    P_ChangeSwitchTexture(line, 1)
    label 20:
    label 23:
    label 25:
    label 26:
    label 31:
    label 35:
    label 36:
    label 37:
    label 39:
    label 40:
    label 41:
    label 42:
    label 51:
    label 52:
    label 53:
    label 54:
    label 55:
    label 56:
    label 57:
    label 66:
    label 67:
    label 68:
    label 71:
    label 72:
    label 73:
    label 75:
    label 76:
    label 77:
    return 1u
}
[export, sideeffects]
def P_ChangeSwitchTexture(var line_0 : line_s?; var useAgain : int) {
    var texTop : int
    var texMid : int
    var texBot : int
    var i : int
    var sound : int
    if (useAgain == 0) {
        line_0.special = int16(0)
    }
    var c2da_fresh3 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(line_0)) + 30ul))
    texTop = int(unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh3))[0]))]).toptexture)
    var c2da_fresh4 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(line_0)) + 30ul))
    texMid = int(unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh4))[0]))]).midtexture)
    var c2da_fresh5 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(line_0)) + 30ul))
    texBot = int(unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh5))[0]))]).bottomtexture)
    sound = 23
    if (int(line_0.special) == 11) {
        sound = 24
    }
    i = 0
    while (i < numswitches * 2) {
        if (switchlist[i] == texTop) {
            S_StartSound(unsafe(reinterpret<uint8?>(unsafe(addr(buttonlist[0])).soundorg)), sound)
            var c2da_fresh6 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(line_0)) + 30ul))
            unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh6))[0]))]).toptexture = int16(switchlist[i ^ 1])
            if (useAgain != 0) {
                P_StartButton(line_0, unsafe(reinterpret<bwhere_e>(0u)), switchlist[i], 35)
            }
            return
        } elif (switchlist[i] == texMid) {
            S_StartSound(unsafe(reinterpret<uint8?>(unsafe(addr(buttonlist[0])).soundorg)), sound)
            var c2da_fresh7 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(line_0)) + 30ul))
            unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh7))[0]))]).midtexture = int16(switchlist[i ^ 1])
            if (useAgain != 0) {
                P_StartButton(line_0, unsafe(reinterpret<bwhere_e>(1u)), switchlist[i], 35)
            }
            return
        } elif (switchlist[i] == texBot) {
            S_StartSound(unsafe(reinterpret<uint8?>(unsafe(addr(buttonlist[0])).soundorg)), sound)
            var c2da_fresh8 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(line_0)) + 30ul))
            unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh8))[0]))]).bottomtexture = int16(switchlist[i ^ 1])
            if (useAgain != 0) {
                P_StartButton(line_0, unsafe(reinterpret<bwhere_e>(2u)), switchlist[i], 35)
            }
            return
        }
        i++
    }
    return
}
var switchlist : int[100]

[export, sideeffects]
def P_StartButton(var line_1 : line_s?; var w : bwhere_e; var texture : int; var time : int) {
    var i_0 : int = 0
    while (i_0 < 16) {
        if (buttonlist[i_0].btimer != 0 && buttonlist[i_0].line == line_1) {
            return
        }
        i_0++
    }
    i_0 = 0
    for (c2da_i_0 in range(i_0, 16)) {
        if (buttonlist[c2da_i_0].btimer == 0) {
            buttonlist[c2da_i_0].line = unsafe(reinterpret<line_s?>(line_1))
            buttonlist[c2da_i_0].where_0 = w
            buttonlist[c2da_i_0].btexture = int(texture)  // nolint:PERF020
            buttonlist[c2da_i_0].btimer = int(time)  // nolint:PERF020
            var c2da_fresh9 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(line_1.frontsector)) + 48ul))
            buttonlist[c2da_i_0].soundorg = unsafe(reinterpret<degenmobj_t?>(c2da_fresh9))
            return
        }
    }
    I_Error(unsafe(addr<int8?>(c2da_str_p_switch_0[0])), [])
    return
}
var buttonlist : button_t[16]

var numswitches : int = default<int>

[export, sideeffects]
def P_InitSwitchList() {
    var i_1 : int
    var index : int
    var episode : int = 1
    if (uint(gamemode) == 1u || uint(gamemode) == 3u) {
        episode = 2
    } elif (uint(gamemode) == 2u) {
        episode = 3
    }
    index = 0
    i_1 = 0
    while (i_1 < 50) {
        if (alphSwitchList[i_1].episode == 0) {
            numswitches = index / 2
            switchlist[index] = -1
            break
        }
        if (int(alphSwitchList[i_1].episode) <= episode) {
            let c2da_postinc : int = index
            index++
            switchlist[c2da_postinc] = R_TextureNumForName(unsafe(addr<int8?>(alphSwitchList[i_1].name1[0])))
            let c2da_postinc_0 : int = index
            index++
            switchlist[c2da_postinc_0] = R_TextureNumForName(unsafe(addr<int8?>(alphSwitchList[i_1].name2[0])))
        }
        i_1++
    }
    return
}
var alphSwitchList : switchlist_t[41] = fixed_array<switchlist_t>(switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(66), int8(82), int8(67), int8(79), int8(77), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(66), int8(82), int8(67), int8(79), int8(77), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(66), int8(82), int8(78), int8(49), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(66), int8(82), int8(78), int8(49), int8(0), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(66), int8(82), int8(78), int8(50), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(66), int8(82), int8(78), int8(50), int8(0), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(66), int8(82), int8(78), int8(71), int8(78), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(66), int8(82), int8(78), int8(71), int8(78), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(66), int8(82), int8(79), int8(87), int8(78), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(66), int8(82), int8(79), int8(87), int8(78), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(67), int8(79), int8(77), int8(77), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(67), int8(79), int8(77), int8(77), int8(0), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(67), int8(79), int8(77), int8(80), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(67), int8(79), int8(77), int8(80), int8(0), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(68), int8(73), int8(82), int8(84), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(68), int8(73), int8(82), int8(84), int8(0), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(69), int8(88), int8(73), int8(84), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(69), int8(88), int8(73), int8(84), int8(0), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(71), int8(82), int8(65), int8(89), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(71), int8(82), int8(65), int8(89), int8(0), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(71), int8(82), int8(65), int8(89), int8(49), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(71), int8(82), int8(65), int8(89), int8(49), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(77), int8(69), int8(84), int8(65), int8(76), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(77), int8(69), int8(84), int8(65), int8(76), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(80), int8(73), int8(80), int8(69), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(80), int8(73), int8(80), int8(69), int8(0), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(83), int8(76), int8(65), int8(68), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(83), int8(76), int8(65), int8(68), int8(0), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(83), int8(84), int8(65), int8(82), int8(71), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(83), int8(84), int8(65), int8(82), int8(71), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(83), int8(84), int8(79), int8(78), int8(49), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(83), int8(84), int8(79), int8(78), int8(49), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(83), int8(84), int8(79), int8(78), int8(50), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(83), int8(84), int8(79), int8(78), int8(50), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(83), int8(84), int8(79), int8(78), int8(69), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(83), int8(84), int8(79), int8(78), int8(69), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(83), int8(84), int8(82), int8(84), int8(78), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(83), int8(84), int8(82), int8(84), int8(78), int8(0)), episode = int16(1)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(66), int8(76), int8(85), int8(69), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(66), int8(76), int8(85), int8(69), int8(0), int8(0)), episode = int16(2)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(67), int8(77), int8(84), int8(0), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(67), int8(77), int8(84), int8(0), int8(0), int8(0)), episode = int16(2)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(71), int8(65), int8(82), int8(71), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(71), int8(65), int8(82), int8(71), int8(0), int8(0)), episode = int16(2)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(71), int8(83), int8(84), int8(79), int8(78), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(71), int8(83), int8(84), int8(79), int8(78), int8(0)), episode = int16(2)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(72), int8(79), int8(84), int8(0), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(72), int8(79), int8(84), int8(0), int8(0), int8(0)), episode = int16(2)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(76), int8(73), int8(79), int8(78), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(76), int8(73), int8(79), int8(78), int8(0), int8(0)), episode = int16(2)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(83), int8(65), int8(84), int8(89), int8(82), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(83), int8(65), int8(84), int8(89), int8(82), int8(0)), episode = int16(2)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(83), int8(75), int8(73), int8(78), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(83), int8(75), int8(73), int8(78), int8(0), int8(0)), episode = int16(2)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(86), int8(73), int8(78), int8(69), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(86), int8(73), int8(78), int8(69), int8(0), int8(0)), episode = int16(2)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(87), int8(79), int8(79), int8(68), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(87), int8(79), int8(79), int8(68), int8(0), int8(0)), episode = int16(2)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(80), int8(65), int8(78), int8(69), int8(76), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(80), int8(65), int8(78), int8(69), int8(76), int8(0)), episode = int16(3)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(82), int8(79), int8(67), int8(75), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(82), int8(79), int8(67), int8(75), int8(0), int8(0)), episode = int16(3)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(77), int8(69), int8(84), int8(50), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(77), int8(69), int8(84), int8(50), int8(0), int8(0)), episode = int16(3)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(87), int8(68), int8(77), int8(69), int8(84), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(87), int8(68), int8(77), int8(69), int8(84), int8(0)), episode = int16(3)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(66), int8(82), int8(73), int8(75), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(66), int8(82), int8(73), int8(75), int8(0), int8(0)), episode = int16(3)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(77), int8(79), int8(68), int8(49), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(77), int8(79), int8(68), int8(49), int8(0), int8(0)), episode = int16(3)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(90), int8(73), int8(77), int8(0), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(90), int8(73), int8(77), int8(0), int8(0), int8(0)), episode = int16(3)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(83), int8(84), int8(79), int8(78), int8(54), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(83), int8(84), int8(79), int8(78), int8(54), int8(0)), episode = int16(3)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(84), int8(69), int8(75), int8(0), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(84), int8(69), int8(75), int8(0), int8(0), int8(0)), episode = int16(3)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(77), int8(65), int8(82), int8(66), int8(0), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(77), int8(65), int8(82), int8(66), int8(0), int8(0)), episode = int16(3)), switchlist_t(name1 = fixed_array<int8>(int8(83), int8(87), int8(49), int8(83), int8(75), int8(85), int8(76), int8(76), int8(0)), name2 = fixed_array<int8>(int8(83), int8(87), int8(50), int8(83), int8(75), int8(85), int8(76), int8(76), int8(0)), episode = int16(3)), switchlist_t(name1 = fixed_array<int8>(int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0)), name2 = fixed_array<int8>(int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0)), episode = int16(0)))

[sideeffects]
def private c2da_layout_proofs_25() {
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
    static_assert(typeinfo sizeof(type<button_t>) == 32, "C layout of button_t: sizeof")
    static_assert(typeinfo alignof(type<button_t>) == 8, "C layout of button_t: alignof")
    static_assert(typeinfo offsetof<line>(type<button_t>) == 0, "C layout of button_t: offsetof line")
    static_assert(typeinfo offsetof<where_0>(type<button_t>) == 8, "C layout of button_t: offsetof where_0")
    static_assert(typeinfo offsetof<btexture>(type<button_t>) == 12, "C layout of button_t: offsetof btexture")
    static_assert(typeinfo offsetof<btimer>(type<button_t>) == 16, "C layout of button_t: offsetof btimer")
    static_assert(typeinfo offsetof<soundorg>(type<button_t>) == 24, "C layout of button_t: offsetof soundorg")
    static_assert(typeinfo sizeof(type<switchlist_t>) == 20, "C layout of switchlist_t: sizeof")
    static_assert(typeinfo alignof(type<switchlist_t>) == 2, "C layout of switchlist_t: alignof")
    static_assert(typeinfo offsetof<name1>(type<switchlist_t>) == 0, "C layout of switchlist_t: offsetof name1")
    static_assert(typeinfo offsetof<name2>(type<switchlist_t>) == 9, "C layout of switchlist_t: offsetof name2")
    static_assert(typeinfo offsetof<episode>(type<switchlist_t>) == 18, "C layout of switchlist_t: offsetof episode")
}
