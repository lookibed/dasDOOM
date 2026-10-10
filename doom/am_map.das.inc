var private c2da_str_am_map_0 : array<int8> = [int8(70), int8(111), int8(108), int8(108), int8(111), int8(119), int8(32), int8(77), int8(111), int8(100), int8(101), int8(32), int8(79), int8(78), int8(0)]

var private c2da_str_am_map_1 : array<int8> = [int8(70), int8(111), int8(108), int8(108), int8(111), int8(119), int8(32), int8(77), int8(111), int8(100), int8(101), int8(32), int8(79), int8(70), int8(70), int8(0)]

var private c2da_str_am_map_2 : array<int8> = [int8(71), int8(114), int8(105), int8(100), int8(32), int8(79), int8(78), int8(0)]

var private c2da_str_am_map_3 : array<int8> = [int8(71), int8(114), int8(105), int8(100), int8(32), int8(79), int8(70), int8(70), int8(0)]

var private c2da_str_am_map_4 : array<int8> = [int8(37), int8(115), int8(32), int8(37), int8(100), int8(0)]

var private c2da_str_am_map_5 : array<int8> = [int8(77), int8(97), int8(114), int8(107), int8(101), int8(100), int8(32), int8(83), int8(112), int8(111), int8(116), int8(0)]

var private c2da_str_am_map_6 : array<int8> = [int8(65), int8(108), int8(108), int8(32), int8(77), int8(97), int8(114), int8(107), int8(115), int8(32), int8(67), int8(108), int8(101), int8(97), int8(114), int8(101), int8(100), int8(0)]

var private c2da_str_am_map_7 : array<int8> = [int8(65), int8(77), int8(77), int8(78), int8(85), int8(77), int8(37), int8(100), int8(0)]

var private c2da_str_am_map_8 : array<int8> = [int8(102), int8(117), int8(99), int8(107), int8(32), int8(37), int8(100), int8(32), int8(13), int8(0)]

var private AM_Responder__bigstate : int = 0

var private AM_Responder__buffer : int8[20] = fixed_array<int8>(int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0))

var private AM_Stop__st_notify : event_t = event_t(type_0 = unsafe(reinterpret<evtype_t>(0u)), data1 = 1, data2 = (97 << 24) + (109 << 16) | 120 << 8, data3 = 0, data4 = 0)

var private AM_Start__lastlevel : int = -1

var private AM_Start__lastepisode : int = -1

var private AM_initVariables__st_notify : event_t = event_t(type_0 = unsafe(reinterpret<evtype_t>(1u)), data1 = (97 << 24) + (109 << 16) | 101 << 8, data2 = 0, data3 = 0, data4 = 0)

var private AM_drawMline__fl : fline_t = fline_t()

var private AM_drawFline__fuck : int = 0

var private AM_drawPlayers__their_colors : int[4] = fixed_array<int>(7 * 16, 6 * 16, 4 * 16, 256 - 5 * 16)

var private AM_drawWalls__l : mline_t = mline_t()

var private AM_updateLightLev__nexttic : int = 0

var private AM_updateLightLev__litelevels : int[8] = fixed_array<int>(0, 4, 7, 10, 12, 14, 15, 15)

var private AM_updateLightLev__litelevelscnt : int = 0

var automapactive : uint = 0u

[export, sideeffects]
def AM_Responder(var ev : event_t?) : uint {
    var rc : int
    var key : int
    rc = 0
    if (automapactive == 0) {
        if (uint(ev.type_0) == 0u && ev.data1 == key_map_toggle) {
            AM_Start()
            viewactive = 0u
            rc = 1
        }
    } elif (uint(ev.type_0) == 0u) {
        rc = 1
        key = ev.data1
        if (key == key_map_east) {
            if (followplayer == 0) {
                m_paninc.x = FixedMul(4 << 16, scale_ftom)
            } else {
                rc = 0
            }
        } elif (key == key_map_west) {
            if (followplayer == 0) {
                m_paninc.x = -FixedMul(4 << 16, scale_ftom)
            } else {
                rc = 0
            }
        } elif (key == key_map_north) {
            if (followplayer == 0) {
                m_paninc.y = FixedMul(4 << 16, scale_ftom)
            } else {
                rc = 0
            }
        } elif (key == key_map_south) {
            if (followplayer == 0) {
                m_paninc.y = -FixedMul(4 << 16, scale_ftom)
            } else {
                rc = 0
            }
        } elif (key == key_map_zoomout) {
            mtof_zoommul = int(double(1 << 16) / 1.02lf)
            ftom_zoommul = int(1.02lf * double(1 << 16))
        } elif (key == key_map_zoomin) {
            mtof_zoommul = int(1.02lf * double(1 << 16))
            ftom_zoommul = int(double(1 << 16) / 1.02lf)
        } elif (key == key_map_toggle) {
            AM_Responder__bigstate = 0
            viewactive = 1u
            AM_Stop()
        } elif (key == key_map_maxzoom) {
            AM_Responder__bigstate = AM_Responder__bigstate == 0 ? 1 : 0
            if (AM_Responder__bigstate != 0) {
                AM_saveScaleAndLoc()
                AM_minOutWindowScale()
            } else {
                AM_restoreScaleAndLoc()
            }
        } elif (key == key_map_follow) {
            followplayer = followplayer == 0 ? 1 : 0
            f_oldloc.x = 2147483647
            if (followplayer != 0) {
                plr.message = unsafe(addr(c2da_str_am_map_0[0]))
            } else {
                plr.message = unsafe(addr(c2da_str_am_map_1[0]))
            }
        } elif (key == key_map_grid) {
            grid = grid == 0 ? 1 : 0
            if (grid != 0) {
                plr.message = unsafe(addr(c2da_str_am_map_2[0]))
            } else {
                plr.message = unsafe(addr(c2da_str_am_map_3[0]))
            }
        } elif (key == key_map_mark) {
            M_snprintf(unsafe(addr<int8?>(AM_Responder__buffer[0])), 20ul, unsafe(addr<int8 const?>(c2da_str_am_map_4[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_am_map_5[0]))))), C2daVaArg(tag = 1, i64 = int64(markpointnum), f64 = 0.0lf, raw = 0x0)])
            plr.message = unsafe(addr(AM_Responder__buffer[0]))
            AM_addMark()
        } elif (key == key_map_clearmark) {
            AM_clearMarks()
            plr.message = unsafe(addr(c2da_str_am_map_6[0]))
        } else {
            rc = 0
        }
        if (deathmatch == 0 && cht_CheckCheat(unsafe(addr<cheatseq_t?>(cheat_amap)), int8(ev.data2)) != 0) {
            rc = 0
            cheating = (cheating + 1) % 3
        }
    } elif (uint(ev.type_0) == 1u) {
        rc = 0
        key = ev.data1
        if (key == key_map_east) {
            if (followplayer == 0) {
                m_paninc.x = 0
            }
        } elif (key == key_map_west) {
            if (followplayer == 0) {
                m_paninc.x = 0
            }
        } elif (key == key_map_north) {
            if (followplayer == 0) {
                m_paninc.y = 0
            }
        } elif (key == key_map_south) {
            if (followplayer == 0) {
                m_paninc.y = 0
            }
        } elif (key == key_map_zoomout || key == key_map_zoomin) {
            mtof_zoommul = 1 << 16
            ftom_zoommul = 1 << 16
        }
    }
    return uint(rc)
}
var private ftom_zoommul : int = default<int>

var private mtof_zoommul : int = default<int>

var private m_paninc : mpoint_t = default<mpoint_t>

var private followplayer : int = 1

var private cheating : int = 0

var cheat_amap : cheatseq_t = cheatseq_t(sequence = fixed_array<int8>(int8(105), int8(100), int8(100), int8(116), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0), int8(0)), sequence_len = 5ul - 1ul, parameter_chars = 0, chars_read = 0ul, param_chars_read = 0, parameter_buf = fixed_array<int8>(int8(0), int8(0), int8(0), int8(0), int8(0)))

var private plr : player_s? = default<player_s?>

[export, sideeffects]
def AM_clearMarks() {
    for (i in range(0, 10)) {
        markpoints[i].x = -1
    }
    markpointnum = 0
    return
}
var private markpointnum : int = 0

var private markpoints : mpoint_t[10]

[export, sideeffects]
def AM_addMark() {
    markpoints[markpointnum].x = m_x + m_w / 2
    markpoints[markpointnum].y = m_y + m_h / 2
    markpointnum = (markpointnum + 1) % 10
    return
}
var private m_h : int = default<int>

var private m_y : int = default<int>

var private m_w : int = default<int>

var private m_x : int = default<int>

var private grid : int = 0

var private f_oldloc : mpoint_t = default<mpoint_t>

[export, sideeffects]
def AM_restoreScaleAndLoc() {
    m_w = int(old_m_w)  // nolint:PERF020
    m_h = int(old_m_h)  // nolint:PERF020
    if (followplayer == 0) {
        m_x = int(old_m_x)  // nolint:PERF020
        m_y = int(old_m_y)  // nolint:PERF020
    } else {
        m_x = plr.mo.x - m_w / 2
        m_y = plr.mo.y - m_h / 2
    }
    m_x2 = m_x + m_w
    m_y2 = m_y + m_h
    scale_mtof = FixedDiv(f_w << 16, m_w)
    scale_ftom = FixedDiv(1 << 16, scale_mtof)
    return
}
var private scale_mtof : int = int(0.2lf * double(1 << 16))

var private scale_ftom : int = default<int>

var private f_w : int = default<int>

var private m_y2 : int = default<int>

var private m_x2 : int = default<int>

var private old_m_y : int = default<int>

var private old_m_x : int = default<int>

var private old_m_h : int = default<int>

var private old_m_w : int = default<int>

[export, sideeffects]
def AM_minOutWindowScale() {
    scale_mtof = int(min_scale_mtof)  // nolint:PERF020
    scale_ftom = FixedDiv(1 << 16, scale_mtof)
    AM_activateNewScale()
    return
}
[export, sideeffects]
def AM_activateNewScale() {
    m_x += m_w / 2
    m_y += m_h / 2
    m_w = FixedMul(f_w << 16, scale_ftom)
    m_h = FixedMul(f_h << 16, scale_ftom)
    m_x -= m_w / 2
    m_y -= m_h / 2
    m_x2 = m_x + m_w
    m_y2 = m_y + m_h
    return
}
var private f_h : int = default<int>

var private min_scale_mtof : int = default<int>

[export, sideeffects]
def AM_saveScaleAndLoc() {
    old_m_x = int(m_x)  // nolint:PERF020
    old_m_y = int(m_y)  // nolint:PERF020
    old_m_w = int(m_w)  // nolint:PERF020
    old_m_h = int(m_h)  // nolint:PERF020
    return
}
[export, sideeffects]
def AM_Stop() {
    AM_unloadPics()
    automapactive = 0u
    ST_Responder(unsafe(addr<event_t?>(AM_Stop__st_notify)))
    stopped = 1u
    return
}
var private stopped : uint = 1u

[export, sideeffects]
def AM_unloadPics() {
    var namebuf : int8[9]
    for (i_0 in range(0, 10)) {
        c2da_std_snprintf(unsafe(reinterpret<uint64>(unsafe(addr(namebuf[0])))), 9ul, unsafe(addr<int8 const?>(c2da_str_am_map_7[0])), [C2daVaArg(tag = 1, i64 = int64(i_0), f64 = 0.0lf, raw = 0x0)])
        W_ReleaseLumpName(unsafe(addr<int8?>(namebuf[0])))
    }
    return
}
[export, sideeffects]
def AM_Start() {
    if (stopped == 0) {
        AM_Stop()
    }
    stopped = 0u
    if (AM_Start__lastlevel != gamemap || AM_Start__lastepisode != gameepisode) {
        AM_LevelInit()
        AM_Start__lastlevel = gamemap
        AM_Start__lastepisode = gameepisode
    }
    AM_initVariables()
    AM_loadPics()
    return
}
[export, sideeffects]
def AM_loadPics() {
    var namebuf_0 : int8[9]
    for (i_1 in range(0, 10)) {
        c2da_std_snprintf(unsafe(reinterpret<uint64>(unsafe(addr(namebuf_0[0])))), 9ul, unsafe(addr<int8 const?>(c2da_str_am_map_7[0])), [C2daVaArg(tag = 1, i64 = int64(i_1), f64 = 0.0lf, raw = 0x0)])
        marknums[i_1] = unsafe(reinterpret<patch_t?>(unsafe(reinterpret<patch_t?>(W_CacheLumpName(unsafe(addr<int8?>(namebuf_0[0])), 1)))))
    }
    return
}
var private marknums : patch_t? [10]

[export, sideeffects]
def AM_initVariables() {
    automapactive = 1u
    fb = unsafe(reinterpret<uint8?>(I_VideoBuffer))
    f_oldloc.x = 2147483647
    amclock = 0
    lightlev = 0
    m_paninc.y = 0
    m_paninc.x = int(m_paninc.y)  // nolint:PERF020
    ftom_zoommul = 1 << 16
    mtof_zoommul = 1 << 16
    m_w = FixedMul(f_w << 16, scale_ftom)
    m_h = FixedMul(f_h << 16, scale_ftom)
    if (playeringame[int(consoleplayer)] != 0x0) {
        plr = unsafe(addr<player_s?>(unsafe(unsafe(addr(players[0]))[int(consoleplayer)])))
    } else {
        plr = unsafe(addr<player_s?>(unsafe(unsafe(addr(players[0]))[0])))
        for (pnum in range(0, 4)) {
            if (playeringame[pnum] != 0x0) {
                plr = unsafe(addr<player_s?>(unsafe(unsafe(addr(players[0]))[pnum])))
                break
            }
        }
    }
    m_x = plr.mo.x - m_w / 2
    m_y = plr.mo.y - m_h / 2
    AM_changeWindowLoc()
    old_m_x = int(m_x)  // nolint:PERF020
    old_m_y = int(m_y)  // nolint:PERF020
    old_m_w = int(m_w)  // nolint:PERF020
    old_m_h = int(m_h)  // nolint:PERF020
    ST_Responder(unsafe(addr<event_t?>(AM_initVariables__st_notify)))
    return
}
[export, sideeffects]
def AM_changeWindowLoc() {
    if (m_paninc.x != 0 || m_paninc.y != 0) {
        followplayer = 0
        f_oldloc.x = 2147483647
    }
    m_x += m_paninc.x
    m_y += m_paninc.y
    if (m_x + m_w / 2 > max_x) {
        m_x = max_x - m_w / 2
    } elif (m_x + m_w / 2 < min_x) {
        m_x = min_x - m_w / 2
    }
    if (m_y + m_h / 2 > max_y) {
        m_y = max_y - m_h / 2
    } elif (m_y + m_h / 2 < min_y) {
        m_y = min_y - m_h / 2
    }
    m_x2 = m_x + m_w
    m_y2 = m_y + m_h
    return
}
var private min_y : int = default<int>

var private max_y : int = default<int>

var private min_x : int = default<int>

var private max_x : int = default<int>

var private lightlev : int = default<int>

var private amclock : int = default<int>

var private fb : uint8? = default<uint8?>

[export, sideeffects]
def AM_LevelInit() {
    leveljuststarted = 0
    f_y = 0
    f_x = int(f_y)  // nolint:PERF020
    f_w = int(finit_width)  // nolint:PERF020
    f_h = int(finit_height)  // nolint:PERF020
    AM_clearMarks()
    AM_findMinMaxBoundaries()
    scale_mtof = FixedDiv(min_scale_mtof, int(0.7lf * double(1 << 16)))
    if (scale_mtof > max_scale_mtof) {
        scale_mtof = int(min_scale_mtof)  // nolint:PERF020
    }
    scale_ftom = FixedDiv(1 << 16, scale_mtof)
    return
}
var private max_scale_mtof : int = default<int>

[export, sideeffects]
def AM_findMinMaxBoundaries() {
    var i_2 : int
    var a : int
    var b : int
    min_y = 2147483647
    min_x = int(min_y)  // nolint:PERF020
    max_y = -2147483647
    max_x = int(max_y)  // nolint:PERF020
    i_2 = 0
    while (i_2 < numvertexes) {
        if (unsafe(vertexes[i_2]).x < min_x) {
            min_x = unsafe(vertexes[i_2]).x
        } elif (unsafe(vertexes[i_2]).x > max_x) {
            max_x = unsafe(vertexes[i_2]).x
        }
        if (unsafe(vertexes[i_2]).y < min_y) {
            min_y = unsafe(vertexes[i_2]).y
        } elif (unsafe(vertexes[i_2]).y > max_y) {
            max_y = unsafe(vertexes[i_2]).y
        }
        i_2++
    }
    max_w = max_x - min_x
    max_h = max_y - min_y
    min_w = 2 * 16 * (1 << 16)
    min_h = 2 * 16 * (1 << 16)
    a = FixedDiv(f_w << 16, max_w)
    b = FixedDiv(f_h << 16, max_h)
    min_scale_mtof = a < b ? a : b
    max_scale_mtof = FixedDiv(f_h << 16, 2 * 16 * (1 << 16))
    return
}
var private max_h : int = default<int>

var private max_w : int = default<int>

var private min_h : int = default<int>

var private min_w : int = default<int>

var private finit_height : int = 200 - 32

var private finit_width : int = 320

var private f_y : int = default<int>

var private f_x : int = default<int>

var private leveljuststarted : int = 1

[export, sideeffects]
def AM_Ticker() {
    if (automapactive == 0) {
        return
    }
    amclock++
    if (followplayer != 0) {
        AM_doFollowPlayer()
    }
    if (ftom_zoommul != 1 << 16) {
        AM_changeWindowScale()
    }
    if (m_paninc.x != 0 || m_paninc.y != 0) {
        AM_changeWindowLoc()
    }
    return
}
[export, sideeffects]
def AM_changeWindowScale() {
    scale_mtof = FixedMul(scale_mtof, mtof_zoommul)
    scale_ftom = FixedDiv(1 << 16, scale_mtof)
    if (scale_mtof < min_scale_mtof) {
        AM_minOutWindowScale()
    } elif (scale_mtof > max_scale_mtof) {
        AM_maxOutWindowScale()
    } else {
        AM_activateNewScale()
    }
    return
}
[export, sideeffects]
def AM_maxOutWindowScale() {
    scale_mtof = int(max_scale_mtof)  // nolint:PERF020
    scale_ftom = FixedDiv(1 << 16, scale_mtof)
    AM_activateNewScale()
    return
}
[export, sideeffects]
def AM_doFollowPlayer() {
    if (f_oldloc.x != plr.mo.x || f_oldloc.y != plr.mo.y) {
        m_x = FixedMul(FixedMul(plr.mo.x, scale_mtof) >> 16 << 16, scale_ftom) - m_w / 2
        m_y = FixedMul(FixedMul(plr.mo.y, scale_mtof) >> 16 << 16, scale_ftom) - m_h / 2
        m_x2 = m_x + m_w
        m_y2 = m_y + m_h
        f_oldloc.x = int(plr.mo.x)  // nolint:PERF020
        f_oldloc.y = int(plr.mo.y)  // nolint:PERF020
    }
    return
}
[export, sideeffects]
def AM_Drawer() {
    if (automapactive == 0) {
        return
    }
    AM_clearFB(0)
    if (grid != 0) {
        AM_drawGrid(6 * 16 + 16 / 2)
    }
    AM_drawWalls()
    AM_drawPlayers()
    if (cheating == 2) {
        AM_drawThings(7 * 16, 16)
    }
    AM_drawCrosshair(6 * 16)
    AM_drawMarks()
    V_MarkRect(f_x, f_y, f_w, f_h)
    return
}
[export, sideeffects]
def AM_drawMarks() {
    var fx : int
    var fy : int
    var w : int
    var h : int
    for (i_3 in range(0, 10)) {
        if (markpoints[i_3].x != -1) {
            w = 5
            h = 6
            fx = f_x + (FixedMul(markpoints[i_3].x - m_x, scale_mtof) >> 16)
            fy = f_y + (f_h - (FixedMul(markpoints[i_3].y - m_y, scale_mtof) >> 16))
            if (fx >= f_x && fx <= f_w - w && fy >= f_y && fy <= f_h - h) {
                V_DrawPatch(fx, fy, unsafe(reinterpret<patch_t?>(marknums[i_3])))
            }
        }
    }
    return
}
[export, sideeffects]
def AM_drawCrosshair(var color : int) {
    unsafe(fb[f_w * (f_h + 1) / 2]) = uint8(color)
    return
}
[export, sideeffects]
def AM_drawThings(var colors_0 : int; var colorrange : int) {
    var i_4 : int
    var t : mobj_s?
    i_4 = 0
    while (i_4 < numsectors) {
        t = unsafe(reinterpret<mobj_s?>(unsafe(sectors[i_4]).thinglist))
        while (t != null) {
            AM_drawLineCharacter(unsafe(addr<mline_t?>(thintriangle_guy[0])), int(48ul / 16ul), 16 << 16, t.angle, colors_0 + lightlev, t.x, t.y)
            t = unsafe(reinterpret<mobj_s?>(t.snext))
        }
        i_4++
    }
    return
}
var thintriangle_guy : mline_t[3] = fixed_array<mline_t>(mline_t(a = mpoint_t(x = int(-0.5lf * double(1 << 16)), y = int(-0.7lf * double(1 << 16))), b = mpoint_t(x = 1 << 16, y = 0)), mline_t(a = mpoint_t(x = 1 << 16, y = 0), b = mpoint_t(x = int(-0.5lf * double(1 << 16)), y = int(0.7lf * double(1 << 16)))), mline_t(a = mpoint_t(x = int(-0.5lf * double(1 << 16)), y = int(0.7lf * double(1 << 16))), b = mpoint_t(x = int(-0.5lf * double(1 << 16)), y = int(-0.7lf * double(1 << 16)))))

[export, sideeffects]
def AM_drawLineCharacter(var lineguy : mline_t?; var lineguylines : int; var scale : int; var angle : uint; var color_0 : int; var x : int; var y : int) {
    var l : mline_t
    for (i_5 in range(0, lineguylines)) {
        l.a.x = unsafe(lineguy[i_5]).a.x
        l.a.y = unsafe(lineguy[i_5]).a.y
        if (scale != 0) {
            l.a.x = FixedMul(scale, l.a.x)
            l.a.y = FixedMul(scale, l.a.y)
        }
        if (angle != 0x0) {
            AM_rotate(unsafe(addr<int?>(l.a.x)), unsafe(addr<int?>(l.a.y)), angle)
        }
        l.a.x += x
        l.a.y += y
        l.b.x = unsafe(lineguy[i_5]).b.x
        l.b.y = unsafe(lineguy[i_5]).b.y
        if (scale != 0) {
            l.b.x = FixedMul(scale, l.b.x)
            l.b.y = FixedMul(scale, l.b.y)
        }
        if (angle != 0x0) {
            AM_rotate(unsafe(addr<int?>(l.b.x)), unsafe(addr<int?>(l.b.y)), angle)
        }
        l.b.x += x
        l.b.y += y
        AM_drawMline(unsafe(addr<mline_t?>(l)), color_0)
    }
    return
}
[export, sideeffects]
def AM_drawMline(var ml : mline_t?; var color_1 : int) {
    if (AM_clipMline(ml, unsafe(addr<fline_t?>(AM_drawMline__fl))) != 0x0) {
        AM_drawFline(unsafe(addr<fline_t?>(AM_drawMline__fl)), color_1)
    }
    return
}
[export, sideeffects]
def AM_drawFline(var fl : fline_t?; var color_2 : int) {
    var x_0 : int
    var y_0 : int
    var dx : int
    var dy : int
    var sx : int
    var sy : int
    var ax : int
    var ay : int
    var d : int
    if (fl.a.x < 0 || fl.a.x >= f_w || fl.a.y < 0 || fl.a.y >= f_h || fl.b.x < 0 || fl.b.x >= f_w || fl.b.y < 0 || fl.b.y >= f_h) {
        let c2da_postinc : int = AM_drawFline__fuck
        AM_drawFline__fuck++
        c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_am_map_8[0])), [C2daVaArg(tag = 1, i64 = int64(c2da_postinc), f64 = 0.0lf, raw = 0x0)])
        return
    }
    dx = fl.b.x - fl.a.x
    ax = 2 * (dx < 0 ? -dx : dx)
    sx = dx < 0 ? -1 : 1
    dy = fl.b.y - fl.a.y
    ay = 2 * (dy < 0 ? -dy : dy)
    sy = dy < 0 ? -1 : 1
    x_0 = fl.a.x
    y_0 = fl.a.y
    if (ax > ay) {
        d = ay - ax / 2
        while (true) {
            unsafe(fb[y_0 * f_w + x_0]) = uint8(color_2)
            if (x_0 == fl.b.x) {
                return
            }
            if (d >= 0) {
                y_0 += sy
                d -= ax
            }
            x_0 += sx
            d += ay
        }
    } else {
        d = ax - ay / 2
        while (true) {
            unsafe(fb[y_0 * f_w + x_0]) = uint8(color_2)
            if (y_0 == fl.b.y) {
                return
            }
            if (d >= 0) {
                x_0 += sx
                d -= ay
            }
            y_0 += sy
            d += ax
        }
    }
}
[export, sideeffects]
def AM_clipMline(var ml_0 : mline_t?; var fl_0 : fline_t?) : uint {
    var outcode1 : int
    var outcode2 : int
    var outside : int
    var tmp : fpoint_t
    var dx_0 : int
    var dy_0 : int
    outcode1 = 0
    outcode2 = 0
    if (ml_0.a.y > m_y2) {
        outcode1 = 8
    } elif (ml_0.a.y < m_y) {
        outcode1 = 4
    }
    if (ml_0.b.y > m_y2) {
        outcode2 = 8
    } elif (ml_0.b.y < m_y) {
        outcode2 = 4
    }
    if ((outcode1 & outcode2) != 0) {
        return 0u
    }
    if (ml_0.a.x < m_x) {
        outcode1 |= 1
    } elif (ml_0.a.x > m_x2) {
        outcode1 |= 2
    }
    if (ml_0.b.x < m_x) {
        outcode2 |= 1
    } elif (ml_0.b.x > m_x2) {
        outcode2 |= 2
    }
    if ((outcode1 & outcode2) != 0) {
        return 0u
    }
    fl_0.a.x = f_x + (FixedMul(ml_0.a.x - m_x, scale_mtof) >> 16)
    fl_0.a.y = f_y + (f_h - (FixedMul(ml_0.a.y - m_y, scale_mtof) >> 16))
    fl_0.b.x = f_x + (FixedMul(ml_0.b.x - m_x, scale_mtof) >> 16)
    fl_0.b.y = f_y + (f_h - (FixedMul(ml_0.b.y - m_y, scale_mtof) >> 16))
    outcode1 = 0
    if (fl_0.a.y < 0) {
        outcode1 |= 8
    } elif (fl_0.a.y >= f_h) {
        outcode1 |= 4
    }
    if (fl_0.a.x < 0) {
        outcode1 |= 1
    } elif (fl_0.a.x >= f_w) {
        outcode1 |= 2
    }
    outcode2 = 0
    if (fl_0.b.y < 0) {
        outcode2 |= 8
    } elif (fl_0.b.y >= f_h) {
        outcode2 |= 4
    }
    if (fl_0.b.x < 0) {
        outcode2 |= 1
    } elif (fl_0.b.x >= f_w) {
        outcode2 |= 2
    }
    if ((outcode1 & outcode2) != 0) {
        return 0u
    }
    while ((outcode1 | outcode2) != 0) {
        if (outcode1 != 0) {
            outside = outcode1
        } else {
            outside = outcode2
        }
        if ((outside & 8) != 0) {
            dy_0 = fl_0.a.y - fl_0.b.y
            dx_0 = fl_0.b.x - fl_0.a.x
            tmp.x = fl_0.a.x + dx_0 * fl_0.a.y / dy_0
            tmp.y = 0
        } elif ((outside & 4) != 0) {
            dy_0 = fl_0.a.y - fl_0.b.y
            dx_0 = fl_0.b.x - fl_0.a.x
            tmp.x = fl_0.a.x + dx_0 * (fl_0.a.y - f_h) / dy_0
            tmp.y = f_h - 1
        } elif ((outside & 2) != 0) {
            dy_0 = fl_0.b.y - fl_0.a.y
            dx_0 = fl_0.b.x - fl_0.a.x
            tmp.y = fl_0.a.y + dy_0 * (f_w - 1 - fl_0.a.x) / dx_0
            tmp.x = f_w - 1
        } elif ((outside & 1) != 0) {
            dy_0 = fl_0.b.y - fl_0.a.y
            dx_0 = fl_0.b.x - fl_0.a.x
            tmp.y = fl_0.a.y + dy_0 * -fl_0.a.x / dx_0
            tmp.x = 0
        } else {
            tmp.x = 0
            tmp.y = 0
        }
        if (outside == outcode1) {
            var c2da_fresh0 : fpoint_t = tmp
            unsafe(memcpy(unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(fl_0)))), unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(unsafe(addr(c2da_fresh0)))))), 8ul))
            outcode1 = 0
            if (fl_0.a.y < 0) {
                outcode1 |= 8
            } elif (fl_0.a.y >= f_h) {
                outcode1 |= 4
            }
            if (fl_0.a.x < 0) {
                outcode1 |= 1
            } elif (fl_0.a.x >= f_w) {
                outcode1 |= 2
            }
        } else {
            var c2da_fresh1 : fpoint_t = tmp
            unsafe(memcpy(unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(fl_0)) + 8ul)), unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(unsafe(addr(c2da_fresh1)))))), 8ul))
            outcode2 = 0
            if (fl_0.b.y < 0) {
                outcode2 |= 8
            } elif (fl_0.b.y >= f_h) {
                outcode2 |= 4
            }
            if (fl_0.b.x < 0) {
                outcode2 |= 1
            } elif (fl_0.b.x >= f_w) {
                outcode2 |= 2
            }
        }
        if ((outcode1 & outcode2) != 0) {
            return 0u
        }
    }
    return 1u
}
[export, sideeffects]
def AM_rotate(var x_1 : int?; var y_1 : int?; var a_0 : uint) {
    var tmpx : int = FixedMul(*x_1, unsafe(finecosine[int(a_0 >> 19u)])) - FixedMul(*y_1, finesine[int(a_0 >> 19u)])
    *y_1 = FixedMul(*x_1, finesine[int(a_0 >> 19u)]) + FixedMul(*y_1, unsafe(finecosine[int(a_0 >> 19u)]))
    *x_1 = tmpx
    return
}
[export, sideeffects]
def AM_drawPlayers() {
    var p : player_s?
    var their_color : int
    var color_3 : int
    their_color = -1
    if (netgame == 0) {
        if (cheating != 0) {
            AM_drawLineCharacter(unsafe(addr<mline_t?>(cheat_player_arrow[0])), int(256ul / 16ul), 0, plr.mo.angle, 256 - 47, plr.mo.x, plr.mo.y)
        } else {
            AM_drawLineCharacter(unsafe(addr<mline_t?>(player_arrow[0])), int(112ul / 16ul), 0, plr.mo.angle, 256 - 47, plr.mo.x, plr.mo.y)
        }
        return
    }
    for (i_6 in range(0, 4)) {
        their_color++
        p = unsafe(addr<player_s?>(unsafe(unsafe(addr(players[0]))[i_6])))
        if (deathmatch != 0 && singledemo == 0 && p != plr) {
            continue
        }
        if (playeringame[i_6] == 0) {
            continue
        }
        var c2da_fresh2 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(p)) + 56ul))
        if (unsafe(unsafe(reinterpret<int?>(c2da_fresh2))[2]) != 0) {
            color_3 = 246
        } else {
            color_3 = AM_drawPlayers__their_colors[their_color]
        }
        AM_drawLineCharacter(unsafe(addr<mline_t?>(player_arrow[0])), int(112ul / 16ul), 0, p.mo.angle, color_3, p.mo.x, p.mo.y)
    }
    return
}
var player_arrow : mline_t[7] = fixed_array<mline_t>(mline_t(a = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) + 8 * 16 * (1 << 16) / 7 / 8, y = 0), b = mpoint_t(x = 8 * 16 * (1 << 16) / 7, y = 0)), mline_t(a = mpoint_t(x = 8 * 16 * (1 << 16) / 7, y = 0), b = mpoint_t(x = 8 * 16 * (1 << 16) / 7 - 8 * 16 * (1 << 16) / 7 / 2, y = 8 * 16 * (1 << 16) / 7 / 4)), mline_t(a = mpoint_t(x = 8 * 16 * (1 << 16) / 7, y = 0), b = mpoint_t(x = 8 * 16 * (1 << 16) / 7 - 8 * 16 * (1 << 16) / 7 / 2, y = -(8 * 16 * (1 << 16) / 7) / 4)), mline_t(a = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) + 8 * 16 * (1 << 16) / 7 / 8, y = 0), b = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) - 8 * 16 * (1 << 16) / 7 / 8, y = 8 * 16 * (1 << 16) / 7 / 4)), mline_t(a = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) + 8 * 16 * (1 << 16) / 7 / 8, y = 0), b = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) - 8 * 16 * (1 << 16) / 7 / 8, y = -(8 * 16 * (1 << 16) / 7) / 4)), mline_t(a = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) + 3 * (8 * 16 * (1 << 16) / 7) / 8, y = 0), b = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) + 8 * 16 * (1 << 16) / 7 / 8, y = 8 * 16 * (1 << 16) / 7 / 4)), mline_t(a = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) + 3 * (8 * 16 * (1 << 16) / 7) / 8, y = 0), b = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) + 8 * 16 * (1 << 16) / 7 / 8, y = -(8 * 16 * (1 << 16) / 7) / 4)))

var cheat_player_arrow : mline_t[16] = fixed_array<mline_t>(mline_t(a = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) + 8 * 16 * (1 << 16) / 7 / 8, y = 0), b = mpoint_t(x = 8 * 16 * (1 << 16) / 7, y = 0)), mline_t(a = mpoint_t(x = 8 * 16 * (1 << 16) / 7, y = 0), b = mpoint_t(x = 8 * 16 * (1 << 16) / 7 - 8 * 16 * (1 << 16) / 7 / 2, y = 8 * 16 * (1 << 16) / 7 / 6)), mline_t(a = mpoint_t(x = 8 * 16 * (1 << 16) / 7, y = 0), b = mpoint_t(x = 8 * 16 * (1 << 16) / 7 - 8 * 16 * (1 << 16) / 7 / 2, y = -(8 * 16 * (1 << 16) / 7) / 6)), mline_t(a = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) + 8 * 16 * (1 << 16) / 7 / 8, y = 0), b = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) - 8 * 16 * (1 << 16) / 7 / 8, y = 8 * 16 * (1 << 16) / 7 / 6)), mline_t(a = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) + 8 * 16 * (1 << 16) / 7 / 8, y = 0), b = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) - 8 * 16 * (1 << 16) / 7 / 8, y = -(8 * 16 * (1 << 16) / 7) / 6)), mline_t(a = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) + 3 * (8 * 16 * (1 << 16) / 7) / 8, y = 0), b = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) + 8 * 16 * (1 << 16) / 7 / 8, y = 8 * 16 * (1 << 16) / 7 / 6)), mline_t(a = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) + 3 * (8 * 16 * (1 << 16) / 7) / 8, y = 0), b = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) + 8 * 16 * (1 << 16) / 7 / 8, y = -(8 * 16 * (1 << 16) / 7) / 6)), mline_t(a = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) / 2, y = 0), b = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) / 2, y = -(8 * 16 * (1 << 16) / 7) / 6)), mline_t(a = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) / 2, y = -(8 * 16 * (1 << 16) / 7) / 6), b = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) / 2 + 8 * 16 * (1 << 16) / 7 / 6, y = -(8 * 16 * (1 << 16) / 7) / 6)), mline_t(a = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) / 2 + 8 * 16 * (1 << 16) / 7 / 6, y = -(8 * 16 * (1 << 16) / 7) / 6), b = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) / 2 + 8 * 16 * (1 << 16) / 7 / 6, y = 8 * 16 * (1 << 16) / 7 / 4)), mline_t(a = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) / 6, y = 0), b = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) / 6, y = -(8 * 16 * (1 << 16) / 7) / 6)), mline_t(a = mpoint_t(x = -(8 * 16 * (1 << 16) / 7) / 6, y = -(8 * 16 * (1 << 16) / 7) / 6), b = mpoint_t(x = 0, y = -(8 * 16 * (1 << 16) / 7) / 6)), mline_t(a = mpoint_t(x = 0, y = -(8 * 16 * (1 << 16) / 7) / 6), b = mpoint_t(x = 0, y = 8 * 16 * (1 << 16) / 7 / 4)), mline_t(a = mpoint_t(x = 8 * 16 * (1 << 16) / 7 / 6, y = 8 * 16 * (1 << 16) / 7 / 4), b = mpoint_t(x = 8 * 16 * (1 << 16) / 7 / 6, y = -(8 * 16 * (1 << 16) / 7) / 7)), mline_t(a = mpoint_t(x = 8 * 16 * (1 << 16) / 7 / 6, y = -(8 * 16 * (1 << 16) / 7) / 7), b = mpoint_t(x = 8 * 16 * (1 << 16) / 7 / 6 + 8 * 16 * (1 << 16) / 7 / 32, y = -(8 * 16 * (1 << 16) / 7) / 7 - 8 * 16 * (1 << 16) / 7 / 32)), mline_t(a = mpoint_t(x = 8 * 16 * (1 << 16) / 7 / 6 + 8 * 16 * (1 << 16) / 7 / 32, y = -(8 * 16 * (1 << 16) / 7) / 7 - 8 * 16 * (1 << 16) / 7 / 32), b = mpoint_t(x = 8 * 16 * (1 << 16) / 7 / 6 + 8 * 16 * (1 << 16) / 7 / 10, y = -(8 * 16 * (1 << 16) / 7) / 7)))

[export, sideeffects]
def AM_drawWalls() {
    var i_7 : int = 0
    while (i_7 < numlines) {
        AM_drawWalls__l.a.x = unsafe(lines[i_7]).v1.x
        AM_drawWalls__l.a.y = unsafe(lines[i_7]).v1.y
        AM_drawWalls__l.b.x = unsafe(lines[i_7]).v2.x
        AM_drawWalls__l.b.y = unsafe(lines[i_7]).v2.y
        if (cheating != 0 || (int(unsafe(lines[i_7]).flags) & 256) != 0) {
            if ((int(unsafe(lines[i_7]).flags) & 128) != 0 && cheating == 0) {
                i_7++
                continue
            }
            if (unsafe(lines[i_7]).backsector == null) {
                AM_drawMline(unsafe(addr<mline_t?>(AM_drawWalls__l)), 256 - 5 * 16 + lightlev)
            } elif (int(unsafe(lines[i_7]).special) == 39) {
                AM_drawMline(unsafe(addr<mline_t?>(AM_drawWalls__l)), 256 - 5 * 16 + 16 / 2)
            } elif ((int(unsafe(lines[i_7]).flags) & 32) != 0) {
                if (cheating != 0) {
                    AM_drawMline(unsafe(addr<mline_t?>(AM_drawWalls__l)), 256 - 5 * 16 + lightlev)
                } else {
                    AM_drawMline(unsafe(addr<mline_t?>(AM_drawWalls__l)), 256 - 5 * 16 + lightlev)
                }
            } elif (unsafe(lines[i_7]).backsector.floorheight != unsafe(lines[i_7]).frontsector.floorheight) {
                AM_drawMline(unsafe(addr<mline_t?>(AM_drawWalls__l)), 4 * 16 + lightlev)
            } elif (unsafe(lines[i_7]).backsector.ceilingheight != unsafe(lines[i_7]).frontsector.ceilingheight) {
                AM_drawMline(unsafe(addr<mline_t?>(AM_drawWalls__l)), 256 - 32 + 7 + lightlev)
            } elif (cheating != 0) {
                AM_drawMline(unsafe(addr<mline_t?>(AM_drawWalls__l)), 6 * 16 + lightlev)
            }
        } else {
            var c2da_fresh3 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(plr)) + 56ul))
            if (unsafe(unsafe(reinterpret<int?>(c2da_fresh3))[4]) != 0) {
                if ((int(unsafe(lines[i_7]).flags) & 128) == 0) {
                    AM_drawMline(unsafe(addr<mline_t?>(AM_drawWalls__l)), 6 * 16 + 3)
                }
            }
        }
        i_7++
    }
    return
}
[export, sideeffects]
def AM_drawGrid(var color_4 : int) {
    var x_2 : int
    var y_2 : int
    var start : int
    var end : int
    var ml_1 : mline_t
    start = m_x
    if ((start - bmaporgx) % (128 << 16) != 0) {
        start = start + ((128 << 16) - (start - bmaporgx) % (128 << 16))
    }
    end = m_x + m_w
    ml_1.a.y = m_y
    ml_1.b.y = m_y + m_h
    x_2 = start
    while (x_2 < end) {
        ml_1.a.x = x_2
        ml_1.b.x = x_2
        AM_drawMline(unsafe(addr<mline_t?>(ml_1)), color_4)
        x_2 += 128 << 16
    }
    start = m_y
    if ((start - bmaporgy) % (128 << 16) != 0) {
        start = start + ((128 << 16) - (start - bmaporgy) % (128 << 16))
    }
    end = m_y + m_h
    ml_1.a.x = m_x
    ml_1.b.x = m_x + m_w
    y_2 = start
    while (y_2 < end) {
        ml_1.a.y = y_2
        ml_1.b.y = y_2
        AM_drawMline(unsafe(addr<mline_t?>(ml_1)), color_4)
        y_2 += 128 << 16
    }
    return
}
[export, sideeffects]
def AM_clearFB(var color_5 : int) {
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(fb)))), uint8(color_5), uint64(f_w * f_h))))
    return
}
var triangle_guy : mline_t[3] = fixed_array<mline_t>(mline_t(a = mpoint_t(x = int(-0.867lf * double(1 << 16)), y = int(-0.5lf * double(1 << 16))), b = mpoint_t(x = int(0.867lf * double(1 << 16)), y = int(-0.5lf * double(1 << 16)))), mline_t(a = mpoint_t(x = int(0.867lf * double(1 << 16)), y = int(-0.5lf * double(1 << 16))), b = mpoint_t(x = 0, y = 1 << 16)), mline_t(a = mpoint_t(x = 0, y = 1 << 16), b = mpoint_t(x = int(-0.867lf * double(1 << 16)), y = int(-0.5lf * double(1 << 16)))))

[export, sideeffects]
def AM_getIslope(var ml_2 : mline_t?; var is_0 : islope_t?) {
    var dx_1 : int
    var dy_1 : int = ml_2.a.y - ml_2.b.y
    dx_1 = ml_2.b.x - ml_2.a.x
    if (dy_1 == 0) {
        is_0.islp = dx_1 < 0 ? -2147483647 : 2147483647
    } else {
        is_0.islp = FixedDiv(dx_1, dy_1)
    }
    if (dx_1 == 0) {
        is_0.slp = dy_1 < 0 ? -2147483647 : 2147483647
    } else {
        is_0.slp = FixedDiv(dy_1, dx_1)
    }
    return
}
[export, sideeffects]
def AM_updateLightLev() {
    if (amclock > AM_updateLightLev__nexttic) {
        let c2da_postinc_0 : int = AM_updateLightLev__litelevelscnt
        AM_updateLightLev__litelevelscnt++
        lightlev = int(AM_updateLightLev__litelevels[c2da_postinc_0])  // nolint:PERF020
        if (uint64(AM_updateLightLev__litelevelscnt) == 32ul / 4ul) {
            AM_updateLightLev__litelevelscnt = 0
        }
        AM_updateLightLev__nexttic = amclock + 6 - amclock % 6
    }
    return
}
[sideeffects]
def private c2da_layout_proofs() {
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
    static_assert(typeinfo sizeof(type<event_t>) == 20, "C layout of event_t: sizeof")
    static_assert(typeinfo alignof(type<event_t>) == 4, "C layout of event_t: alignof")
    static_assert(typeinfo offsetof<type_0>(type<event_t>) == 0, "C layout of event_t: offsetof type_0")
    static_assert(typeinfo offsetof<data1>(type<event_t>) == 4, "C layout of event_t: offsetof data1")
    static_assert(typeinfo offsetof<data2>(type<event_t>) == 8, "C layout of event_t: offsetof data2")
    static_assert(typeinfo offsetof<data3>(type<event_t>) == 12, "C layout of event_t: offsetof data3")
    static_assert(typeinfo offsetof<data4>(type<event_t>) == 16, "C layout of event_t: offsetof data4")
    static_assert(typeinfo sizeof(type<cheatseq_t>) == 72, "C layout of cheatseq_t: sizeof")
    static_assert(typeinfo alignof(type<cheatseq_t>) == 8, "C layout of cheatseq_t: alignof")
    static_assert(typeinfo offsetof<sequence>(type<cheatseq_t>) == 0, "C layout of cheatseq_t: offsetof sequence")
    static_assert(typeinfo offsetof<sequence_len>(type<cheatseq_t>) == 32, "C layout of cheatseq_t: offsetof sequence_len")
    static_assert(typeinfo offsetof<parameter_chars>(type<cheatseq_t>) == 40, "C layout of cheatseq_t: offsetof parameter_chars")
    static_assert(typeinfo offsetof<chars_read>(type<cheatseq_t>) == 48, "C layout of cheatseq_t: offsetof chars_read")
    static_assert(typeinfo offsetof<param_chars_read>(type<cheatseq_t>) == 56, "C layout of cheatseq_t: offsetof param_chars_read")
    static_assert(typeinfo offsetof<parameter_buf>(type<cheatseq_t>) == 60, "C layout of cheatseq_t: offsetof parameter_buf")
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
    static_assert(typeinfo sizeof(type<mpoint_t>) == 8, "C layout of mpoint_t: sizeof")
    static_assert(typeinfo alignof(type<mpoint_t>) == 4, "C layout of mpoint_t: alignof")
    static_assert(typeinfo offsetof<x>(type<mpoint_t>) == 0, "C layout of mpoint_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<mpoint_t>) == 4, "C layout of mpoint_t: offsetof y")
    static_assert(typeinfo sizeof(type<mline_t>) == 16, "C layout of mline_t: sizeof")
    static_assert(typeinfo alignof(type<mline_t>) == 4, "C layout of mline_t: alignof")
    static_assert(typeinfo offsetof<a>(type<mline_t>) == 0, "C layout of mline_t: offsetof a")
    static_assert(typeinfo offsetof<b>(type<mline_t>) == 8, "C layout of mline_t: offsetof b")
    static_assert(typeinfo sizeof(type<fline_t>) == 16, "C layout of fline_t: sizeof")
    static_assert(typeinfo alignof(type<fline_t>) == 4, "C layout of fline_t: alignof")
    static_assert(typeinfo offsetof<a>(type<fline_t>) == 0, "C layout of fline_t: offsetof a")
    static_assert(typeinfo offsetof<b>(type<fline_t>) == 8, "C layout of fline_t: offsetof b")
    static_assert(typeinfo sizeof(type<fpoint_t>) == 8, "C layout of fpoint_t: sizeof")
    static_assert(typeinfo alignof(type<fpoint_t>) == 4, "C layout of fpoint_t: alignof")
    static_assert(typeinfo offsetof<x>(type<fpoint_t>) == 0, "C layout of fpoint_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<fpoint_t>) == 4, "C layout of fpoint_t: offsetof y")
    static_assert(typeinfo sizeof(type<islope_t>) == 8, "C layout of islope_t: sizeof")
    static_assert(typeinfo alignof(type<islope_t>) == 4, "C layout of islope_t: alignof")
    static_assert(typeinfo offsetof<slp>(type<islope_t>) == 0, "C layout of islope_t: offsetof slp")
    static_assert(typeinfo offsetof<islp>(type<islope_t>) == 4, "C layout of islope_t: offsetof islp")
}
