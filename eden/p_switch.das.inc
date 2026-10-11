[export, sideeffects]
def P_UseSpecialLine(var thing : int; var line : int; var side : int) : uint {
    var c2da_fresh0 : int
    var c2da_fresh1 : int
    var c2da_fresh2 : int
    if (side != 0) {
        c2da_fresh0 = int(int16(uint(c2da_mem[line + 26]) | uint(c2da_mem[line + 27]) << 0x8))
        if (c2da_fresh0 == 124) {
        } else {
            return 0u
        }
    }
    if (int(uint(c2da_mem[thing + 192]) | uint(c2da_mem[thing + 193]) << 0x8 | uint(c2da_mem[thing + 194]) << 0x10 | uint(c2da_mem[thing + 195]) << 0x18) == 0) {
        if ((int(int16(uint(c2da_mem[line + 24]) | uint(c2da_mem[line + 25]) << 0x8)) & 32) != 0) {
            return 0u
        }
        c2da_fresh1 = int(int16(uint(c2da_mem[line + 26]) | uint(c2da_mem[line + 27]) << 0x8))
        if (c2da_fresh1 == 1 || c2da_fresh1 == 32 || c2da_fresh1 == 33 || c2da_fresh1 == 34) {
        } else {
            return 0u
        }
    }
    c2da_fresh2 = int(int16(uint(c2da_mem[line + 26]) | uint(c2da_mem[line + 27]) << 0x8))
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
    if (EV_BuildStairs(line, 0u) != 0) {
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
    if (EV_DoPlat(line, 2u, 32) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 5:
    if (EV_DoPlat(line, 2u, 24) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 6:
    if (EV_DoFloor(line, 4u) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 21:
    if (EV_DoPlat(line, 3u, 0) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 22:
    if (EV_DoPlat(line, 1u, 0) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 24:
    if (EV_DoFloor(line, 1u) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 30:
    if (EV_DoDoor(line, 0u) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 7:
    if (EV_DoCeiling(line, 0u) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 8:
    if (EV_DoFloor(line, 2u) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 9:
    if (EV_DoCeiling(line, 3u) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 33:
    if (EV_DoDoor(line, 2u) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 34:
    P_ChangeSwitchTexture(line, 0)
    G_SecretExitLevel()
    goto label 20
    label 38:
    if (EV_DoFloor(line, 9u) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 48:
    if (EV_DoFloor(line, 3u) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 49:
    if (EV_DoFloor(line, 0u) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 50:
    if (EV_DoDoor(line, 3u) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 58:
    if (EV_DoDoor(line, 5u) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 59:
    if (EV_DoDoor(line, 6u) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 60:
    if (EV_DoDoor(line, 7u) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 69:
    if (EV_DoPlat(line, 4u, 0) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 74:
    if (EV_BuildStairs(line, 1u) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 78:
    if (EV_DoFloor(line, 10u) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 80:
    label 82:
    label 84:
    if (EV_DoLockedDoor(line, 6u, thing) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 87:
    if (EV_DoFloor(line, 12u) != 0) {
        P_ChangeSwitchTexture(line, 0)
    }
    goto label 20
    label 10:
    if (EV_DoDoor(line, 2u) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 11:
    if (EV_DoCeiling(line, 0u) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 12:
    if (EV_DoFloor(line, 0u) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 43:
    if (EV_DoFloor(line, 1u) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 44:
    if (EV_DoDoor(line, 3u) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 45:
    if (EV_DoPlat(line, 1u, 1) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 46:
    if (EV_DoDoor(line, 0u) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 47:
    if (EV_DoFloor(line, 3u) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 13:
    if (EV_DoPlat(line, 2u, 24) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 14:
    if (EV_DoPlat(line, 2u, 32) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 15:
    if (EV_DoFloor(line, 9u) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 16:
    if (EV_DoPlat(line, 3u, 0) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 17:
    if (EV_DoFloor(line, 4u) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 18:
    if (EV_DoFloor(line, 2u) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 61:
    if (EV_DoDoor(line, 5u) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 62:
    if (EV_DoDoor(line, 6u) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 63:
    if (EV_DoDoor(line, 7u) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 70:
    if (EV_DoPlat(line, 4u, 0) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 79:
    if (EV_DoFloor(line, 10u) != 0) {
        P_ChangeSwitchTexture(line, 1)
    }
    goto label 20
    label 19:
    label 81:
    label 83:
    if (EV_DoLockedDoor(line, 6u, thing) != 0) {
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
def P_ChangeSwitchTexture(var line_0 : int; var useAgain : int) {
    var texTop : int
    var texMid : int
    var texBot : int
    var i : int
    var sound : int
    if (useAgain == 0) {
        let c2da_fresh3 : int16 = int16(0)
        let c2da_fresh4 : uint = uint(c2da_fresh3)
        c2da_mem[line_0 + 26] = uint8(c2da_fresh4)
        c2da_mem[line_0 + 27] = uint8(c2da_fresh4 >> 0x8)
    }
    let c2da_fresh5 : int = sides + int(int16(uint(c2da_mem[line_0 + 30 + 0 * 2]) | uint(c2da_mem[line_0 + 30 + 0 * 2 + 1]) << 0x8)) * 24 + 8
    texTop = int(int16(uint(c2da_mem[c2da_fresh5]) | uint(c2da_mem[c2da_fresh5 + 1]) << 0x8))
    let c2da_fresh6 : int = sides + int(int16(uint(c2da_mem[line_0 + 30 + 0 * 2]) | uint(c2da_mem[line_0 + 30 + 0 * 2 + 1]) << 0x8)) * 24 + 12
    texMid = int(int16(uint(c2da_mem[c2da_fresh6]) | uint(c2da_mem[c2da_fresh6 + 1]) << 0x8))
    let c2da_fresh7 : int = sides + int(int16(uint(c2da_mem[line_0 + 30 + 0 * 2]) | uint(c2da_mem[line_0 + 30 + 0 * 2 + 1]) << 0x8)) * 24 + 10
    texBot = int(int16(uint(c2da_mem[c2da_fresh7]) | uint(c2da_mem[c2da_fresh7 + 1]) << 0x8))
    sound = 23
    if (int(int16(uint(c2da_mem[line_0 + 26]) | uint(c2da_mem[line_0 + 27]) << 0x8)) == 11) {
        sound = 24
    }
    i = 0
    while (i < numswitches * 2) {
        if (switchlist[i] == texTop) {
            S_StartSound(int(uint(c2da_mem[66136]) | uint(c2da_mem[66137]) << 0x8 | uint(c2da_mem[66138]) << 0x10 | uint(c2da_mem[66139]) << 0x18), sound)
            let c2da_fresh8 : int = sides + int(int16(uint(c2da_mem[line_0 + 30 + 0 * 2]) | uint(c2da_mem[line_0 + 30 + 0 * 2 + 1]) << 0x8)) * 24 + 8
            let c2da_fresh9 : int16 = int16(switchlist[i ^ 1])
            let c2da_fresh10 : uint = uint(c2da_fresh9)
            c2da_mem[c2da_fresh8] = uint8(c2da_fresh10)
            c2da_mem[c2da_fresh8 + 1] = uint8(c2da_fresh10 >> 0x8)
            if (useAgain != 0) {
                P_StartButton(line_0, 0u, switchlist[i], 35)
            }
            return
        } elif (switchlist[i] == texMid) {
            S_StartSound(int(uint(c2da_mem[66136]) | uint(c2da_mem[66137]) << 0x8 | uint(c2da_mem[66138]) << 0x10 | uint(c2da_mem[66139]) << 0x18), sound)
            let c2da_fresh11 : int = sides + int(int16(uint(c2da_mem[line_0 + 30 + 0 * 2]) | uint(c2da_mem[line_0 + 30 + 0 * 2 + 1]) << 0x8)) * 24 + 12
            let c2da_fresh12 : int16 = int16(switchlist[i ^ 1])
            let c2da_fresh13 : uint = uint(c2da_fresh12)
            c2da_mem[c2da_fresh11] = uint8(c2da_fresh13)
            c2da_mem[c2da_fresh11 + 1] = uint8(c2da_fresh13 >> 0x8)
            if (useAgain != 0) {
                P_StartButton(line_0, 1u, switchlist[i], 35)
            }
            return
        } elif (switchlist[i] == texBot) {
            S_StartSound(int(uint(c2da_mem[66136]) | uint(c2da_mem[66137]) << 0x8 | uint(c2da_mem[66138]) << 0x10 | uint(c2da_mem[66139]) << 0x18), sound)
            let c2da_fresh14 : int = sides + int(int16(uint(c2da_mem[line_0 + 30 + 0 * 2]) | uint(c2da_mem[line_0 + 30 + 0 * 2 + 1]) << 0x8)) * 24 + 10
            let c2da_fresh15 : int16 = int16(switchlist[i ^ 1])
            let c2da_fresh16 : uint = uint(c2da_fresh15)
            c2da_mem[c2da_fresh14] = uint8(c2da_fresh16)
            c2da_mem[c2da_fresh14 + 1] = uint8(c2da_fresh16 >> 0x8)
            if (useAgain != 0) {
                P_StartButton(line_0, 2u, switchlist[i], 35)
            }
            return
        }
        i++
    }
    return
}
var switchlist : int[100]

[export, sideeffects]
def P_StartButton(var line_1 : int; var w : uint; var texture : int; var time : int) {
    var i_0 : int = 0
    while (i_0 < 16) {
        if (int(uint(c2da_mem[66112 + i_0 * 32 + 16]) | uint(c2da_mem[66112 + i_0 * 32 + 17]) << 0x8 | uint(c2da_mem[66112 + i_0 * 32 + 18]) << 0x10 | uint(c2da_mem[66112 + i_0 * 32 + 19]) << 0x18) != 0 && int(uint(c2da_mem[66112 + i_0 * 32]) | uint(c2da_mem[66112 + i_0 * 32 + 1]) << 0x8 | uint(c2da_mem[66112 + i_0 * 32 + 2]) << 0x10 | uint(c2da_mem[66112 + i_0 * 32 + 3]) << 0x18) == line_1) {
            return
        }
        i_0++
    }
    i_0 = 0
    for (c2da_i_0 in range(i_0, 16)) {
        if (int(uint(c2da_mem[66112 + c2da_i_0 * 32 + 16]) | uint(c2da_mem[66112 + c2da_i_0 * 32 + 17]) << 0x8 | uint(c2da_mem[66112 + c2da_i_0 * 32 + 18]) << 0x10 | uint(c2da_mem[66112 + c2da_i_0 * 32 + 19]) << 0x18) == 0) {
            let c2da_fresh17 : uint = uint(line_1)
            c2da_mem[66112 + c2da_i_0 * 32] = uint8(c2da_fresh17)
            c2da_mem[66112 + c2da_i_0 * 32 + 1] = uint8(c2da_fresh17 >> 0x8)
            c2da_mem[66112 + c2da_i_0 * 32 + 2] = uint8(c2da_fresh17 >> 0x10)
            c2da_mem[66112 + c2da_i_0 * 32 + 3] = uint8(c2da_fresh17 >> 0x18)
            c2da_mem[66112 + c2da_i_0 * 32 + 4] = 0u8
            c2da_mem[66112 + c2da_i_0 * 32 + 5] = 0u8
            c2da_mem[66112 + c2da_i_0 * 32 + 6] = 0u8
            c2da_mem[66112 + c2da_i_0 * 32 + 7] = 0u8
            let c2da_fresh18 : uint = w
            c2da_mem[66112 + c2da_i_0 * 32 + 8] = uint8(c2da_fresh18)
            c2da_mem[66112 + c2da_i_0 * 32 + 9] = uint8(c2da_fresh18 >> 0x8)
            c2da_mem[66112 + c2da_i_0 * 32 + 10] = uint8(c2da_fresh18 >> 0x10)
            c2da_mem[66112 + c2da_i_0 * 32 + 11] = uint8(c2da_fresh18 >> 0x18)
            let c2da_fresh19 : uint = uint(texture)
            c2da_mem[66112 + c2da_i_0 * 32 + 12] = uint8(c2da_fresh19)
            c2da_mem[66112 + c2da_i_0 * 32 + 13] = uint8(c2da_fresh19 >> 0x8)
            c2da_mem[66112 + c2da_i_0 * 32 + 14] = uint8(c2da_fresh19 >> 0x10)
            c2da_mem[66112 + c2da_i_0 * 32 + 15] = uint8(c2da_fresh19 >> 0x18)
            let c2da_fresh20 : uint = uint(time)
            c2da_mem[66112 + c2da_i_0 * 32 + 16] = uint8(c2da_fresh20)
            c2da_mem[66112 + c2da_i_0 * 32 + 17] = uint8(c2da_fresh20 >> 0x8)
            c2da_mem[66112 + c2da_i_0 * 32 + 18] = uint8(c2da_fresh20 >> 0x10)
            c2da_mem[66112 + c2da_i_0 * 32 + 19] = uint8(c2da_fresh20 >> 0x18)
            let c2da_fresh21 : int = int(uint(c2da_mem[line_1 + 56]) | uint(c2da_mem[line_1 + 57]) << 0x8 | uint(c2da_mem[line_1 + 58]) << 0x10 | uint(c2da_mem[line_1 + 59]) << 0x18) + 48
            let c2da_fresh22 : uint = uint(c2da_fresh21)
            c2da_mem[66112 + c2da_i_0 * 32 + 24] = uint8(c2da_fresh22)
            c2da_mem[66112 + c2da_i_0 * 32 + 25] = uint8(c2da_fresh22 >> 0x8)
            c2da_mem[66112 + c2da_i_0 * 32 + 26] = uint8(c2da_fresh22 >> 0x10)
            c2da_mem[66112 + c2da_i_0 * 32 + 27] = uint8(c2da_fresh22 >> 0x18)
            c2da_mem[66112 + c2da_i_0 * 32 + 28] = 0u8
            c2da_mem[66112 + c2da_i_0 * 32 + 29] = 0u8
            c2da_mem[66112 + c2da_i_0 * 32 + 30] = 0u8
            c2da_mem[66112 + c2da_i_0 * 32 + 31] = 0u8
            return
        }
    }
    I_Error(361792, [])
    return
}
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
        if (int16(uint(c2da_mem[66624 + i_1 * 20 + 18]) | uint(c2da_mem[66624 + i_1 * 20 + 19]) << 0x8) == 0) {
            numswitches = index / 2
            switchlist[index] = -1
            break
        }
        if (int(int16(uint(c2da_mem[66624 + i_1 * 20 + 18]) | uint(c2da_mem[66624 + i_1 * 20 + 19]) << 0x8)) <= episode) {
            let c2da_postinc : int = index
            index++
            switchlist[c2da_postinc] = R_TextureNumForName(66624 + i_1 * 20)
            let c2da_postinc_0 : int = index
            index++
            switchlist[c2da_postinc_0] = R_TextureNumForName(66624 + i_1 * 20 + 9)
        }
        i_1++
    }
    return
}

// This unit's static data, at heap offset 361792.
let private c2da_lin_static_p_switch_seg = fixed_array<int>(361792, 36)
let private c2da_lin_static_p_switch = fixed_array<uint64>(0x4274726174535f50ul, 0x6e203a6e6f747475ul, 0x6e6f74747562206ful, 0x6c2073746f6c7320ul, 0x21746665ul)

[init]
def private c2da_lin_init_static_p_switch() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_p_switch_seg[s * 2]
        for (k in range(c2da_lin_static_p_switch_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_p_switch[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_p_switch_0 = fixed_array<uint8>(0x53, 0x57, 0x31, 0x42, 0x52, 0x43, 0x4f, 0x4d, 0x0, 0x53, 0x57, 0x32, 0x42, 0x52, 0x43, 0x4f, 0x4d, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x42, 0x52, 0x4e, 0x31, 0x0, 0x0, 0x53, 0x57, 0x32, 0x42, 0x52, 0x4e, 0x31, 0x0, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x42, 0x52, 0x4e, 0x32, 0x0, 0x0, 0x53, 0x57, 0x32, 0x42, 0x52, 0x4e, 0x32, 0x0, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x42, 0x52, 0x4e, 0x47, 0x4e, 0x0, 0x53, 0x57, 0x32, 0x42, 0x52, 0x4e, 0x47, 0x4e, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x42, 0x52, 0x4f, 0x57, 0x4e, 0x0, 0x53, 0x57, 0x32, 0x42, 0x52, 0x4f, 0x57, 0x4e, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x43, 0x4f, 0x4d, 0x4d, 0x0, 0x0, 0x53, 0x57, 0x32, 0x43, 0x4f, 0x4d, 0x4d, 0x0, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x43, 0x4f, 0x4d, 0x50, 0x0, 0x0, 0x53, 0x57, 0x32, 0x43, 0x4f, 0x4d, 0x50, 0x0, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x44, 0x49, 0x52, 0x54, 0x0, 0x0, 0x53, 0x57, 0x32, 0x44, 0x49, 0x52, 0x54, 0x0, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x45, 0x58, 0x49, 0x54, 0x0, 0x0, 0x53, 0x57, 0x32, 0x45, 0x58, 0x49, 0x54, 0x0, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x47, 0x52, 0x41, 0x59, 0x0, 0x0, 0x53, 0x57, 0x32, 0x47, 0x52, 0x41, 0x59, 0x0, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x47, 0x52, 0x41, 0x59, 0x31, 0x0, 0x53, 0x57, 0x32, 0x47, 0x52, 0x41, 0x59, 0x31, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x4d, 0x45, 0x54, 0x41, 0x4c, 0x0, 0x53, 0x57, 0x32, 0x4d, 0x45, 0x54, 0x41, 0x4c, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x50, 0x49, 0x50, 0x45, 0x0, 0x0, 0x53, 0x57, 0x32, 0x50, 0x49, 0x50, 0x45, 0x0, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x53, 0x4c, 0x41, 0x44, 0x0, 0x0, 0x53, 0x57, 0x32, 0x53, 0x4c, 0x41, 0x44, 0x0, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x53, 0x54, 0x41, 0x52, 0x47, 0x0, 0x53, 0x57, 0x32, 0x53, 0x54, 0x41, 0x52, 0x47, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x53, 0x54, 0x4f, 0x4e, 0x31, 0x0, 0x53, 0x57, 0x32, 0x53, 0x54, 0x4f, 0x4e, 0x31, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x53, 0x54, 0x4f, 0x4e, 0x32, 0x0, 0x53, 0x57, 0x32, 0x53, 0x54, 0x4f, 0x4e, 0x32, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x53, 0x54, 0x4f, 0x4e, 0x45, 0x0, 0x53, 0x57, 0x32, 0x53, 0x54, 0x4f, 0x4e, 0x45, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x53, 0x54, 0x52, 0x54, 0x4e, 0x0, 0x53, 0x57, 0x32, 0x53, 0x54, 0x52, 0x54, 0x4e, 0x0, 0x1, 0x0, 0x53, 0x57, 0x31, 0x42, 0x4c, 0x55, 0x45, 0x0, 0x0, 0x53, 0x57, 0x32, 0x42, 0x4c, 0x55, 0x45, 0x0, 0x0, 0x2, 0x0, 0x53, 0x57, 0x31, 0x43, 0x4d, 0x54, 0x0, 0x0, 0x0, 0x53, 0x57, 0x32, 0x43, 0x4d, 0x54, 0x0, 0x0, 0x0, 0x2, 0x0, 0x53, 0x57, 0x31, 0x47, 0x41, 0x52, 0x47, 0x0, 0x0, 0x53, 0x57, 0x32, 0x47, 0x41, 0x52, 0x47, 0x0, 0x0, 0x2, 0x0, 0x53, 0x57, 0x31, 0x47, 0x53, 0x54, 0x4f, 0x4e, 0x0, 0x53, 0x57, 0x32, 0x47, 0x53, 0x54, 0x4f, 0x4e, 0x0, 0x2, 0x0, 0x53, 0x57, 0x31, 0x48, 0x4f, 0x54, 0x0, 0x0, 0x0, 0x53, 0x57, 0x32, 0x48, 0x4f, 0x54, 0x0, 0x0, 0x0, 0x2, 0x0, 0x53, 0x57, 0x31, 0x4c, 0x49, 0x4f, 0x4e, 0x0, 0x0, 0x53, 0x57, 0x32, 0x4c, 0x49, 0x4f, 0x4e, 0x0, 0x0, 0x2, 0x0, 0x53, 0x57, 0x31, 0x53, 0x41, 0x54, 0x59, 0x52, 0x0, 0x53, 0x57, 0x32, 0x53, 0x41, 0x54, 0x59, 0x52, 0x0, 0x2, 0x0, 0x53, 0x57, 0x31, 0x53, 0x4b, 0x49, 0x4e, 0x0, 0x0, 0x53, 0x57, 0x32, 0x53, 0x4b, 0x49, 0x4e, 0x0, 0x0, 0x2, 0x0, 0x53, 0x57, 0x31, 0x56, 0x49, 0x4e, 0x45, 0x0, 0x0, 0x53, 0x57, 0x32, 0x56, 0x49, 0x4e, 0x45, 0x0, 0x0, 0x2, 0x0, 0x53, 0x57, 0x31, 0x57, 0x4f, 0x4f, 0x44, 0x0, 0x0, 0x53, 0x57, 0x32, 0x57, 0x4f, 0x4f, 0x44, 0x0, 0x0, 0x2, 0x0, 0x53, 0x57, 0x31, 0x50, 0x41, 0x4e, 0x45, 0x4c, 0x0, 0x53, 0x57, 0x32, 0x50, 0x41, 0x4e, 0x45, 0x4c, 0x0, 0x3, 0x0, 0x53, 0x57, 0x31, 0x52, 0x4f, 0x43, 0x4b, 0x0, 0x0, 0x53, 0x57, 0x32, 0x52, 0x4f, 0x43, 0x4b, 0x0, 0x0, 0x3, 0x0, 0x53, 0x57, 0x31, 0x4d, 0x45, 0x54, 0x32, 0x0, 0x0, 0x53, 0x57, 0x32, 0x4d, 0x45, 0x54, 0x32, 0x0, 0x0, 0x3, 0x0, 0x53, 0x57, 0x31, 0x57, 0x44, 0x4d, 0x45, 0x54, 0x0, 0x53, 0x57, 0x32, 0x57, 0x44, 0x4d, 0x45, 0x54, 0x0, 0x3, 0x0, 0x53, 0x57, 0x31, 0x42, 0x52, 0x49, 0x4b, 0x0, 0x0, 0x53, 0x57, 0x32, 0x42, 0x52, 0x49, 0x4b, 0x0, 0x0, 0x3, 0x0, 0x53, 0x57, 0x31, 0x4d, 0x4f, 0x44, 0x31, 0x0, 0x0, 0x53, 0x57, 0x32, 0x4d, 0x4f, 0x44, 0x31, 0x0, 0x0, 0x3, 0x0, 0x53, 0x57, 0x31, 0x5a, 0x49, 0x4d, 0x0, 0x0, 0x0, 0x53, 0x57, 0x32, 0x5a, 0x49, 0x4d, 0x0, 0x0, 0x0, 0x3, 0x0, 0x53, 0x57, 0x31, 0x53, 0x54, 0x4f, 0x4e, 0x36, 0x0, 0x53, 0x57, 0x32, 0x53, 0x54, 0x4f, 0x4e, 0x36, 0x0, 0x3, 0x0, 0x53, 0x57, 0x31, 0x54, 0x45, 0x4b, 0x0, 0x0, 0x0, 0x53, 0x57, 0x32, 0x54, 0x45, 0x4b, 0x0, 0x0, 0x0, 0x3, 0x0, 0x53, 0x57, 0x31, 0x4d, 0x41, 0x52, 0x42, 0x0, 0x0, 0x53, 0x57, 0x32, 0x4d, 0x41, 0x52, 0x42, 0x0, 0x0, 0x3, 0x0, 0x53, 0x57, 0x31, 0x53, 0x4b, 0x55, 0x4c, 0x4c, 0x0, 0x53, 0x57, 0x32, 0x53, 0x4b, 0x55, 0x4c, 0x4c, 0x0, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_p_switch() {
    c2da_lin_setup()
    for (i in range(820)) {
        c2da_mem[66624 + i] = c2da_lin_extern_p_switch_0[i]
    }
}
