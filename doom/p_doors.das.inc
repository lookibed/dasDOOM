var private c2da_str_p_doors_0 : array<int8> = [int8(89), int8(111), int8(117), int8(32), int8(110), int8(101), int8(101), int8(100), int8(32), int8(97), int8(32), int8(98), int8(108), int8(117), int8(101), int8(32), int8(107), int8(101), int8(121), int8(32), int8(116), int8(111), int8(32), int8(111), int8(112), int8(101), int8(110), int8(32), int8(116), int8(104), int8(105), int8(115), int8(32), int8(100), int8(111), int8(111), int8(114), int8(0)]

var private c2da_str_p_doors_1 : array<int8> = [int8(89), int8(111), int8(117), int8(32), int8(110), int8(101), int8(101), int8(100), int8(32), int8(97), int8(32), int8(121), int8(101), int8(108), int8(108), int8(111), int8(119), int8(32), int8(107), int8(101), int8(121), int8(32), int8(116), int8(111), int8(32), int8(111), int8(112), int8(101), int8(110), int8(32), int8(116), int8(104), int8(105), int8(115), int8(32), int8(100), int8(111), int8(111), int8(114), int8(0)]

var private c2da_str_p_doors_2 : array<int8> = [int8(89), int8(111), int8(117), int8(32), int8(110), int8(101), int8(101), int8(100), int8(32), int8(97), int8(32), int8(114), int8(101), int8(100), int8(32), int8(107), int8(101), int8(121), int8(32), int8(116), int8(111), int8(32), int8(111), int8(112), int8(101), int8(110), int8(32), int8(116), int8(104), int8(105), int8(115), int8(32), int8(100), int8(111), int8(111), int8(114), int8(0)]

var private c2da_str_p_doors_3 : array<int8> = [int8(69), int8(86), int8(95), int8(86), int8(101), int8(114), int8(116), int8(105), int8(99), int8(97), int8(108), int8(68), int8(111), int8(111), int8(114), int8(58), int8(32), int8(84), int8(114), int8(105), int8(101), int8(100), int8(32), int8(116), int8(111), int8(32), int8(99), int8(108), int8(111), int8(115), int8(101), int8(32), int8(115), int8(111), int8(109), int8(101), int8(116), int8(104), int8(105), int8(110), int8(103), int8(32), int8(116), int8(104), int8(97), int8(116), int8(32), int8(119), int8(97), int8(115), int8(110), int8(39), int8(116), int8(32), int8(97), int8(32), int8(100), int8(111), int8(111), int8(114), int8(46), int8(10), int8(0)]

var private c2da_str_p_doors_4 : array<int8> = [int8(89), int8(111), int8(117), int8(32), int8(110), int8(101), int8(101), int8(100), int8(32), int8(97), int8(32), int8(98), int8(108), int8(117), int8(101), int8(32), int8(107), int8(101), int8(121), int8(32), int8(116), int8(111), int8(32), int8(97), int8(99), int8(116), int8(105), int8(118), int8(97), int8(116), int8(101), int8(32), int8(116), int8(104), int8(105), int8(115), int8(32), int8(111), int8(98), int8(106), int8(101), int8(99), int8(116), int8(0)]

var private c2da_str_p_doors_5 : array<int8> = [int8(89), int8(111), int8(117), int8(32), int8(110), int8(101), int8(101), int8(100), int8(32), int8(97), int8(32), int8(114), int8(101), int8(100), int8(32), int8(107), int8(101), int8(121), int8(32), int8(116), int8(111), int8(32), int8(97), int8(99), int8(116), int8(105), int8(118), int8(97), int8(116), int8(101), int8(32), int8(116), int8(104), int8(105), int8(115), int8(32), int8(111), int8(98), int8(106), int8(101), int8(99), int8(116), int8(0)]

var private c2da_str_p_doors_6 : array<int8> = [int8(89), int8(111), int8(117), int8(32), int8(110), int8(101), int8(101), int8(100), int8(32), int8(97), int8(32), int8(121), int8(101), int8(108), int8(108), int8(111), int8(119), int8(32), int8(107), int8(101), int8(121), int8(32), int8(116), int8(111), int8(32), int8(97), int8(99), int8(116), int8(105), int8(118), int8(97), int8(116), int8(101), int8(32), int8(116), int8(104), int8(105), int8(115), int8(32), int8(111), int8(98), int8(106), int8(101), int8(99), int8(116), int8(0)]

[export, sideeffects]
def EV_VerticalDoor(var line : line_s?; var thing : mobj_s?) {
    var c2da_fresh0 : int
    var c2da_fresh11 : int
    var c2da_fresh12 : int
    var c2da_fresh17 : int
    var player : player_s?
    var sec : sector_t?
    var door : vldoor_t?
    var side : int
    var c2da_fresh10 : int16?
    var c2da_fresh16 : thinker_s?
    side = 0
    player = unsafe(reinterpret<player_s?>(thing.player))
    c2da_fresh0 = int(line.special)
    if (c2da_fresh0 == 26 || c2da_fresh0 == 32) {
        if (player == null) {
            return
        }
        var c2da_fresh1 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(player)) + 80ul))
        var c2da_fresh3 : int = 0
        if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh1))[0]) == 0) {
            var c2da_fresh2 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(player)) + 80ul))
            if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh2))[3]) == 0) {
                c2da_fresh3 = 1
            }
        }
        if (c2da_fresh3 != 0) {
            player.message = unsafe(addr(c2da_str_p_doors_0[0]))
            S_StartSound(null, 34)
            return
        }
    } elif (c2da_fresh0 == 27 || c2da_fresh0 == 34) {
        if (player == null) {
            return
        }
        var c2da_fresh4 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(player)) + 80ul))
        var c2da_fresh6 : int = 0
        if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh4))[1]) == 0) {
            var c2da_fresh5 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(player)) + 80ul))
            if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh5))[4]) == 0) {
                c2da_fresh6 = 1
            }
        }
        if (c2da_fresh6 != 0) {
            player.message = unsafe(addr(c2da_str_p_doors_1[0]))
            S_StartSound(null, 34)
            return
        }
    } elif (c2da_fresh0 == 28 || c2da_fresh0 == 33) {
        if (player == null) {
            return
        }
        var c2da_fresh7 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(player)) + 80ul))
        var c2da_fresh9 : int = 0
        if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh7))[2]) == 0) {
            var c2da_fresh8 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(player)) + 80ul))
            if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh8))[5]) == 0) {
                c2da_fresh9 = 1
            }
        }
        if (c2da_fresh9 != 0) {
            player.message = unsafe(addr(c2da_str_p_doors_2[0]))
            S_StartSound(null, 34)
            return
        }
    }
    c2da_fresh10 = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(line)) + 30ul))
    sec = unsafe(reinterpret<sector_t?>(unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh10))[side ^ 1]))]).sector))
    if (sec.specialdata != null) {
        door = unsafe(reinterpret<vldoor_t?>(unsafe(reinterpret<vldoor_t?>(sec.specialdata))))
        c2da_fresh11 = int(line.special)
        if (c2da_fresh11 == 1 || c2da_fresh11 == 26 || c2da_fresh11 == 27 || c2da_fresh11 == 28 || c2da_fresh11 == 117) {
            if (door.direction == -1) {
                door.direction = 1
            } else {
                if (thing.player == null) {
                    return
                }
                if (unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(door))))[2]) == unsafe(reinterpret<actionf_p1>(@@T_VerticalDoor))) {
                    door.direction = -1
                } elif (unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(door))))[2]) == unsafe(reinterpret<actionf_p1>(@@T_PlatRaise))) {
                    unsafe(reinterpret<plat_t?>(unsafe(reinterpret<plat_t?>(door)))).wait = -1
                } else {
                    c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_p_doors_3[0])), [])
                    door.direction = -1
                }
            }
            return
        }
    }
    c2da_fresh12 = int(line.special)
    if (c2da_fresh12 == 117 || c2da_fresh12 == 118) {
        var c2da_fresh13 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(sec)) + 48ul))
        S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh13)), 88)
    } elif (c2da_fresh12 == 1 || c2da_fresh12 == 31) {
        var c2da_fresh14 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(sec)) + 48ul))
        S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh14)), 20)
    } else {
        var c2da_fresh15 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(sec)) + 48ul))
        S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh15)), 20)
    }
    door = unsafe(reinterpret<vldoor_t?>(unsafe(reinterpret<vldoor_t?>(Z_Malloc(64, 6, null)))))
    c2da_fresh16 = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(door))))
    P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh16)))
    sec.specialdata = unsafe(reinterpret<uint8?>(door))
    unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(door))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_VerticalDoor))
    door.sector = sec
    door.direction = 1
    door.speed = (1 << 16) * 2
    door.topwait = 150
    c2da_fresh17 = int(line.special)
    if (c2da_fresh17 < 32) {
        if (c2da_fresh17 < 27) {
            if (c2da_fresh17 == 1) {
                goto label 0
            } elif (c2da_fresh17 == 26) {
                goto label 0
            }
        } else {
            if (c2da_fresh17 == 27) {
                goto label 0
            } elif (c2da_fresh17 == 28) {
                goto label 0
            } elif (c2da_fresh17 == 31) {
                goto label 1
            }
        }
    } else {
        if (c2da_fresh17 < 34) {
            if (c2da_fresh17 == 32) {
                goto label 1
            } elif (c2da_fresh17 == 33) {
                goto label 1
            }
        } else {
            if (c2da_fresh17 == 34) {
                goto label 1
            } elif (c2da_fresh17 == 117) {
                goto label 2
            } elif (c2da_fresh17 == 118) {
                goto label 3
            }
        }
    }
    goto label 4
    label 0:
    door.type_0 = unsafe(reinterpret<vldoor_e>(0u))
    goto label 4
    label 1:
    door.type_0 = unsafe(reinterpret<vldoor_e>(3u))
    line.special = int16(0)
    goto label 4
    label 2:
    door.type_0 = unsafe(reinterpret<vldoor_e>(5u))
    door.speed = (1 << 16) * 2 * 4
    goto label 4
    label 3:
    door.type_0 = unsafe(reinterpret<vldoor_e>(6u))
    line.special = int16(0)
    door.speed = (1 << 16) * 2 * 4
    label 4:
    door.topheight = P_FindLowestCeilingSurrounding(sec)
    door.topheight -= 4 * (1 << 16)
    return
}
[export, sideeffects]
def T_VerticalDoor(var door_0 : vldoor_t?) {
    var c2da_fresh18 : int
    var c2da_fresh19 : uint
    var c2da_fresh23 : uint
    var c2da_fresh25 : uint
    var c2da_fresh29 : uint
    var c2da_fresh31 : uint
    var res : result_e = result_e()
    c2da_fresh18 = door_0.direction
    if (c2da_fresh18 == 0) {
        let c2da_postinc : int = door_0.topcountdown
        door_0.topcountdown = c2da_postinc - 1
        if (c2da_postinc - 1 == 0) {
            c2da_fresh19 = uint(door_0.type_0)
            if (c2da_fresh19 == 0x5u) {
                door_0.direction = -1
                var c2da_fresh20 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(door_0.sector)) + 48ul))
                S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh20)), 89)
            } elif (c2da_fresh19 == 0x0u) {
                door_0.direction = -1
                var c2da_fresh21 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(door_0.sector)) + 48ul))
                S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh21)), 21)
            } elif (c2da_fresh19 == 0x1u) {
                door_0.direction = 1
                var c2da_fresh22 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(door_0.sector)) + 48ul))
                S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh22)), 20)
            }
        }
    } elif (c2da_fresh18 == 2) {
        let c2da_postinc_0 : int = door_0.topcountdown
        door_0.topcountdown = c2da_postinc_0 - 1
        if (c2da_postinc_0 - 1 == 0) {
            c2da_fresh23 = uint(door_0.type_0)
            if (c2da_fresh23 == 0x4u) {
                door_0.direction = 1
                door_0.type_0 = unsafe(reinterpret<vldoor_e>(0u))
                var c2da_fresh24 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(door_0.sector)) + 48ul))
                S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh24)), 20)
            }
        }
    } elif (c2da_fresh18 == -1) {
        res = T_MovePlane(door_0.sector, door_0.speed, door_0.sector.floorheight, 0u, 1, door_0.direction)
        if (uint(res) == 2u) {
            c2da_fresh25 = uint(door_0.type_0)
            if (c2da_fresh25 == 0x5u || c2da_fresh25 == 0x7u) {
                door_0.sector.specialdata = null
                var c2da_fresh26 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(door_0))))
                P_RemoveThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh26)))
                var c2da_fresh27 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(door_0.sector)) + 48ul))
                S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh27)), 89)
            } elif (c2da_fresh25 == 0x0u || c2da_fresh25 == 0x2u) {
                door_0.sector.specialdata = null
                var c2da_fresh28 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(door_0))))
                P_RemoveThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh28)))
            } elif (c2da_fresh25 == 0x1u) {
                door_0.direction = 0
                door_0.topcountdown = 35 * 30
            }
        } elif (uint(res) == 1u) {
            c2da_fresh29 = uint(door_0.type_0)
            if (c2da_fresh29 == 0x7u || c2da_fresh29 == 0x2u) {
            } else {
                door_0.direction = 1
                var c2da_fresh30 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(door_0.sector)) + 48ul))
                S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh30)), 20)
            }
        }
    } elif (c2da_fresh18 == 1) {
        res = T_MovePlane(door_0.sector, door_0.speed, door_0.topheight, 0u, 1, door_0.direction)
        if (uint(res) == 2u) {
            c2da_fresh31 = uint(door_0.type_0)
            if (c2da_fresh31 == 0x5u || c2da_fresh31 == 0x0u) {
                door_0.direction = 0
                door_0.topcountdown = int(door_0.topwait)  // nolint:PERF020
            } elif (c2da_fresh31 == 0x1u || c2da_fresh31 == 0x6u || c2da_fresh31 == 0x3u) {
                door_0.sector.specialdata = null
                var c2da_fresh32 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(door_0))))
                P_RemoveThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh32)))
            }
        }
    }
    return
}
[export, sideeffects]
def EV_DoDoor(var line_0 : line_s?; var type_0 : vldoor_e) : int {
    var c2da_fresh34 : uint
    var secnum : int
    var rtn : int
    var sec_0 : sector_t?
    var door_1 : vldoor_t?
    secnum = -1
    rtn = 0
    while (true) {
        secnum = P_FindSectorFromLineTag(line_0, secnum)
        if (secnum < 0) {
            break
        }
        sec_0 = unsafe(addr<sector_t?>(unsafe(sectors[secnum])))
        if (sec_0.specialdata != null) {
            continue
        }
        rtn = 1
        door_1 = unsafe(reinterpret<vldoor_t?>(unsafe(reinterpret<vldoor_t?>(Z_Malloc(64, 6, null)))))
        var c2da_fresh33 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(door_1))))
        P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh33)))
        sec_0.specialdata = unsafe(reinterpret<uint8?>(door_1))
        unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(door_1))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_VerticalDoor))
        door_1.sector = sec_0
        door_1.type_0 = type_0
        door_1.topwait = 150
        door_1.speed = (1 << 16) * 2
        c2da_fresh34 = uint(type_0)
        if (c2da_fresh34 == 0x7u) {
            door_1.topheight = P_FindLowestCeilingSurrounding(sec_0)
            door_1.topheight -= 4 * (1 << 16)
            door_1.direction = -1
            door_1.speed = (1 << 16) * 2 * 4
            var c2da_fresh35 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(door_1.sector)) + 48ul))
            S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh35)), 89)
        } elif (c2da_fresh34 == 0x2u) {
            door_1.topheight = P_FindLowestCeilingSurrounding(sec_0)
            door_1.topheight -= 4 * (1 << 16)
            door_1.direction = -1
            var c2da_fresh36 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(door_1.sector)) + 48ul))
            S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh36)), 21)
        } elif (c2da_fresh34 == 0x1u) {
            door_1.topheight = int(sec_0.ceilingheight)  // nolint:PERF020
            door_1.direction = -1
            var c2da_fresh37 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(door_1.sector)) + 48ul))
            S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh37)), 21)
        } elif (c2da_fresh34 == 0x5u || c2da_fresh34 == 0x6u) {
            door_1.direction = 1
            door_1.topheight = P_FindLowestCeilingSurrounding(sec_0)
            door_1.topheight -= 4 * (1 << 16)
            door_1.speed = (1 << 16) * 2 * 4
            if (door_1.topheight != sec_0.ceilingheight) {
                var c2da_fresh38 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(door_1.sector)) + 48ul))
                S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh38)), 88)
            }
        } elif (c2da_fresh34 == 0x0u || c2da_fresh34 == 0x3u) {
            door_1.direction = 1
            door_1.topheight = P_FindLowestCeilingSurrounding(sec_0)
            door_1.topheight -= 4 * (1 << 16)
            if (door_1.topheight != sec_0.ceilingheight) {
                var c2da_fresh39 : degenmobj_t? = unsafe(reinterpret<degenmobj_t?>(unsafe(reinterpret<uint64>(door_1.sector)) + 48ul))
                S_StartSound(unsafe(reinterpret<uint8?>(c2da_fresh39)), 20)
            }
        }
    }
    return rtn
}
[export, sideeffects]
def EV_DoLockedDoor(var line_1 : line_s?; var type_1 : vldoor_e; var thing_0 : mobj_s?) : int {
    var c2da_fresh40 : int
    var p : player_s? = unsafe(reinterpret<player_s?>(thing_0.player))
    if (p == null) {
        return 0
    }
    c2da_fresh40 = int(line_1.special)
    if (c2da_fresh40 == 99 || c2da_fresh40 == 133) {
        if (p == null) {
            return 0
        }
        var c2da_fresh41 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(p)) + 80ul))
        var c2da_fresh43 : int = 0
        if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh41))[0]) == 0) {
            var c2da_fresh42 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(p)) + 80ul))
            if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh42))[3]) == 0) {
                c2da_fresh43 = 1
            }
        }
        if (c2da_fresh43 != 0) {
            p.message = unsafe(addr(c2da_str_p_doors_4[0]))
            S_StartSound(null, 34)
            return 0
        }
    } elif (c2da_fresh40 == 134 || c2da_fresh40 == 135) {
        if (p == null) {
            return 0
        }
        var c2da_fresh44 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(p)) + 80ul))
        var c2da_fresh46 : int = 0
        if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh44))[2]) == 0) {
            var c2da_fresh45 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(p)) + 80ul))
            if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh45))[5]) == 0) {
                c2da_fresh46 = 1
            }
        }
        if (c2da_fresh46 != 0) {
            p.message = unsafe(addr(c2da_str_p_doors_5[0]))
            S_StartSound(null, 34)
            return 0
        }
    } elif (c2da_fresh40 == 136 || c2da_fresh40 == 137) {
        if (p == null) {
            return 0
        }
        var c2da_fresh47 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(p)) + 80ul))
        var c2da_fresh49 : int = 0
        if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh47))[1]) == 0) {
            var c2da_fresh48 : uint? = unsafe(reinterpret<uint?>(unsafe(reinterpret<uint64>(p)) + 80ul))
            if (unsafe(unsafe(reinterpret<uint?>(c2da_fresh48))[4]) == 0) {
                c2da_fresh49 = 1
            }
        }
        if (c2da_fresh49 != 0) {
            p.message = unsafe(addr(c2da_str_p_doors_6[0]))
            S_StartSound(null, 34)
            return 0
        }
    }
    return EV_DoDoor(line_1, type_1)
}
[export, sideeffects]
def P_SpawnDoorCloseIn30(var sec_1 : sector_t?) {
    var door_2 : vldoor_t? = unsafe(reinterpret<vldoor_t?>(unsafe(reinterpret<vldoor_t?>(Z_Malloc(64, 6, null)))))
    var c2da_fresh50 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(door_2))))
    P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh50)))
    sec_1.specialdata = unsafe(reinterpret<uint8?>(door_2))
    sec_1.special = int16(0)
    unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(door_2))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_VerticalDoor))
    door_2.sector = sec_1
    door_2.direction = 0
    door_2.type_0 = unsafe(reinterpret<vldoor_e>(0u))
    door_2.speed = (1 << 16) * 2
    door_2.topcountdown = 30 * 35
    return
}
[export, sideeffects]
def P_SpawnDoorRaiseIn5Mins(var sec_2 : sector_t?; var secnum_0 : int) {
    var door_3 : vldoor_t? = unsafe(reinterpret<vldoor_t?>(unsafe(reinterpret<vldoor_t?>(Z_Malloc(64, 6, null)))))
    var c2da_fresh51 : thinker_s? = unsafe(reinterpret<thinker_s?>(unsafe(reinterpret<uint64>(door_3))))
    P_AddThinker(unsafe(reinterpret<thinker_s?>(c2da_fresh51)))
    sec_2.specialdata = unsafe(reinterpret<uint8?>(door_3))
    sec_2.special = int16(0)
    unsafe(unsafe(reinterpret<actionf_p1?>(unsafe(reinterpret<uint64>(door_3))))[2]) = unsafe(reinterpret<actionf_p1>(@@T_VerticalDoor))
    door_3.sector = sec_2
    door_3.direction = 2
    door_3.type_0 = unsafe(reinterpret<vldoor_e>(4u))
    door_3.speed = (1 << 16) * 2
    door_3.topheight = P_FindLowestCeilingSurrounding(sec_2)
    door_3.topheight -= 4 * (1 << 16)
    door_3.topwait = 150
    door_3.topcountdown = 5 * 60 * 35
    return
}
[sideeffects]
def private c2da_layout_proofs_11() {
    static_assert(typeinfo sizeof(type<_IO_FILE>) == 216, "C layout of _IO_FILE: sizeof")
    static_assert(typeinfo alignof(type<_IO_FILE>) == 8, "C layout of _IO_FILE: alignof")
    static_assert(typeinfo offsetof<_flags>(type<_IO_FILE>) == 0, "C layout of _IO_FILE: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<_IO_FILE>) == 8, "C layout of _IO_FILE: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<_IO_FILE>) == 16, "C layout of _IO_FILE: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<_IO_FILE>) == 24, "C layout of _IO_FILE: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<_IO_FILE>) == 32, "C layout of _IO_FILE: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<_IO_FILE>) == 40, "C layout of _IO_FILE: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<_IO_FILE>) == 48, "C layout of _IO_FILE: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<_IO_FILE>) == 56, "C layout of _IO_FILE: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<_IO_FILE>) == 64, "C layout of _IO_FILE: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<_IO_FILE>) == 72, "C layout of _IO_FILE: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<_IO_FILE>) == 80, "C layout of _IO_FILE: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<_IO_FILE>) == 88, "C layout of _IO_FILE: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<_IO_FILE>) == 96, "C layout of _IO_FILE: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<_IO_FILE>) == 104, "C layout of _IO_FILE: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<_IO_FILE>) == 112, "C layout of _IO_FILE: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<_IO_FILE>) == 116, "C layout of _IO_FILE: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<_IO_FILE>) == 120, "C layout of _IO_FILE: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<_IO_FILE>) == 128, "C layout of _IO_FILE: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<_IO_FILE>) == 130, "C layout of _IO_FILE: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<_IO_FILE>) == 131, "C layout of _IO_FILE: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<_IO_FILE>) == 136, "C layout of _IO_FILE: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<_IO_FILE>) == 144, "C layout of _IO_FILE: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<_IO_FILE>) == 152, "C layout of _IO_FILE: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<_IO_FILE>) == 160, "C layout of _IO_FILE: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<_IO_FILE>) == 168, "C layout of _IO_FILE: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<_IO_FILE>) == 176, "C layout of _IO_FILE: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<_IO_FILE>) == 184, "C layout of _IO_FILE: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<_IO_FILE>) == 192, "C layout of _IO_FILE: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<_IO_FILE>) == 196, "C layout of _IO_FILE: offsetof _unused2")
    static_assert(typeinfo sizeof(type<FILE_0>) == 216, "C layout of FILE_0: sizeof")
    static_assert(typeinfo alignof(type<FILE_0>) == 8, "C layout of FILE_0: alignof")
    static_assert(typeinfo offsetof<_flags>(type<FILE_0>) == 0, "C layout of FILE_0: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<FILE_0>) == 8, "C layout of FILE_0: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<FILE_0>) == 16, "C layout of FILE_0: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<FILE_0>) == 24, "C layout of FILE_0: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<FILE_0>) == 32, "C layout of FILE_0: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<FILE_0>) == 40, "C layout of FILE_0: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<FILE_0>) == 48, "C layout of FILE_0: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<FILE_0>) == 56, "C layout of FILE_0: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<FILE_0>) == 64, "C layout of FILE_0: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<FILE_0>) == 72, "C layout of FILE_0: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<FILE_0>) == 80, "C layout of FILE_0: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<FILE_0>) == 88, "C layout of FILE_0: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<FILE_0>) == 96, "C layout of FILE_0: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<FILE_0>) == 104, "C layout of FILE_0: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<FILE_0>) == 112, "C layout of FILE_0: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<FILE_0>) == 116, "C layout of FILE_0: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<FILE_0>) == 120, "C layout of FILE_0: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<FILE_0>) == 128, "C layout of FILE_0: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<FILE_0>) == 130, "C layout of FILE_0: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<FILE_0>) == 131, "C layout of FILE_0: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<FILE_0>) == 136, "C layout of FILE_0: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<FILE_0>) == 144, "C layout of FILE_0: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<FILE_0>) == 152, "C layout of FILE_0: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<FILE_0>) == 160, "C layout of FILE_0: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<FILE_0>) == 168, "C layout of FILE_0: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<FILE_0>) == 176, "C layout of FILE_0: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<FILE_0>) == 184, "C layout of FILE_0: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<FILE_0>) == 192, "C layout of FILE_0: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<FILE_0>) == 196, "C layout of FILE_0: offsetof _unused2")
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
    static_assert(typeinfo sizeof(type<vldoor_t>) == 64, "C layout of vldoor_t: sizeof")
    static_assert(typeinfo alignof(type<vldoor_t>) == 8, "C layout of vldoor_t: alignof")
    static_assert(typeinfo offsetof<thinker>(type<vldoor_t>) == 0, "C layout of vldoor_t: offsetof thinker")
    static_assert(typeinfo offsetof<type_0>(type<vldoor_t>) == 24, "C layout of vldoor_t: offsetof type_0")
    static_assert(typeinfo offsetof<sector>(type<vldoor_t>) == 32, "C layout of vldoor_t: offsetof sector")
    static_assert(typeinfo offsetof<topheight>(type<vldoor_t>) == 40, "C layout of vldoor_t: offsetof topheight")
    static_assert(typeinfo offsetof<speed>(type<vldoor_t>) == 44, "C layout of vldoor_t: offsetof speed")
    static_assert(typeinfo offsetof<direction>(type<vldoor_t>) == 48, "C layout of vldoor_t: offsetof direction")
    static_assert(typeinfo offsetof<topwait>(type<vldoor_t>) == 52, "C layout of vldoor_t: offsetof topwait")
    static_assert(typeinfo offsetof<topcountdown>(type<vldoor_t>) == 56, "C layout of vldoor_t: offsetof topcountdown")
}
