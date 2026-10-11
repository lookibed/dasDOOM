var private AM_Responder__bigstate : int = 0

var private AM_Start__lastlevel : int = -1

var private AM_Start__lastepisode : int = -1

var private AM_drawFline__fuck : int = 0

var private AM_drawPlayers__their_colors : int[4] = fixed_array<int>(7 * 16, 6 * 16, 4 * 16, 256 - 5 * 16)

var private AM_updateLightLev__nexttic : int = 0

var private AM_updateLightLev__litelevelscnt : int = 0

var automapactive : uint = 0u

[export, sideeffects]
def AM_Responder(var ev : int) : uint {
    var rc : int
    var key : int
    rc = 0
    if (automapactive == 0) {
        if ((uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 0u && int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) == int(uint(c2da_mem[43472]) | uint(c2da_mem[43473]) << 0x8 | uint(c2da_mem[43474]) << 0x10 | uint(c2da_mem[43475]) << 0x18)) {
            AM_Start()
            viewactive = 0u
            rc = 1
        }
    } elif ((uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 0u) {
        rc = 1
        key = int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18)
        if (key == int(uint(c2da_mem[43408]) | uint(c2da_mem[43409]) << 0x8 | uint(c2da_mem[43410]) << 0x10 | uint(c2da_mem[43411]) << 0x18)) {
            if (followplayer == 0) {
                m_paninc.x = FixedMul(4 << 16, scale_ftom)
            } else {
                rc = 0
            }
        } elif (key == int(uint(c2da_mem[43424]) | uint(c2da_mem[43425]) << 0x8 | uint(c2da_mem[43426]) << 0x10 | uint(c2da_mem[43427]) << 0x18)) {
            if (followplayer == 0) {
                m_paninc.x = -FixedMul(4 << 16, scale_ftom)
            } else {
                rc = 0
            }
        } elif (key == int(uint(c2da_mem[43376]) | uint(c2da_mem[43377]) << 0x8 | uint(c2da_mem[43378]) << 0x10 | uint(c2da_mem[43379]) << 0x18)) {
            if (followplayer == 0) {
                m_paninc.y = FixedMul(4 << 16, scale_ftom)
            } else {
                rc = 0
            }
        } elif (key == int(uint(c2da_mem[43392]) | uint(c2da_mem[43393]) << 0x8 | uint(c2da_mem[43394]) << 0x10 | uint(c2da_mem[43395]) << 0x18)) {
            if (followplayer == 0) {
                m_paninc.y = -FixedMul(4 << 16, scale_ftom)
            } else {
                rc = 0
            }
        } elif (key == int(uint(c2da_mem[43456]) | uint(c2da_mem[43457]) << 0x8 | uint(c2da_mem[43458]) << 0x10 | uint(c2da_mem[43459]) << 0x18)) {
            mtof_zoommul = int(double(1 << 16) / 1.02lf)
            ftom_zoommul = int(1.02lf * double(1 << 16))
        } elif (key == int(uint(c2da_mem[43440]) | uint(c2da_mem[43441]) << 0x8 | uint(c2da_mem[43442]) << 0x10 | uint(c2da_mem[43443]) << 0x18)) {
            mtof_zoommul = int(1.02lf * double(1 << 16))
            ftom_zoommul = int(double(1 << 16) / 1.02lf)
        } elif (key == int(uint(c2da_mem[43472]) | uint(c2da_mem[43473]) << 0x8 | uint(c2da_mem[43474]) << 0x10 | uint(c2da_mem[43475]) << 0x18)) {
            AM_Responder__bigstate = 0
            viewactive = 1u
            AM_Stop()
        } elif (key == int(uint(c2da_mem[43488]) | uint(c2da_mem[43489]) << 0x8 | uint(c2da_mem[43490]) << 0x10 | uint(c2da_mem[43491]) << 0x18)) {
            AM_Responder__bigstate = AM_Responder__bigstate == 0 ? 1 : 0
            if (AM_Responder__bigstate != 0) {
                AM_saveScaleAndLoc()
                AM_minOutWindowScale()
            } else {
                AM_restoreScaleAndLoc()
            }
        } elif (key == int(uint(c2da_mem[43504]) | uint(c2da_mem[43505]) << 0x8 | uint(c2da_mem[43506]) << 0x10 | uint(c2da_mem[43507]) << 0x18)) {
            followplayer = followplayer == 0 ? 1 : 0
            f_oldloc.x = 2147483647
            if (followplayer != 0) {
                let c2da_fresh0 : uint = 300112u
                c2da_mem[plr + 232] = uint8(c2da_fresh0)
                c2da_mem[plr + 233] = uint8(c2da_fresh0 >> 0x8)
                c2da_mem[plr + 234] = uint8(c2da_fresh0 >> 0x10)
                c2da_mem[plr + 235] = uint8(c2da_fresh0 >> 0x18)
                c2da_mem[plr + 236] = 0u8
                c2da_mem[plr + 237] = 0u8
                c2da_mem[plr + 238] = 0u8
                c2da_mem[plr + 239] = 0u8
            } else {
                let c2da_fresh1 : uint = 300127u
                c2da_mem[plr + 232] = uint8(c2da_fresh1)
                c2da_mem[plr + 233] = uint8(c2da_fresh1 >> 0x8)
                c2da_mem[plr + 234] = uint8(c2da_fresh1 >> 0x10)
                c2da_mem[plr + 235] = uint8(c2da_fresh1 >> 0x18)
                c2da_mem[plr + 236] = 0u8
                c2da_mem[plr + 237] = 0u8
                c2da_mem[plr + 238] = 0u8
                c2da_mem[plr + 239] = 0u8
            }
        } elif (key == int(uint(c2da_mem[43520]) | uint(c2da_mem[43521]) << 0x8 | uint(c2da_mem[43522]) << 0x10 | uint(c2da_mem[43523]) << 0x18)) {
            grid = grid == 0 ? 1 : 0
            if (grid != 0) {
                let c2da_fresh2 : uint = 300143u
                c2da_mem[plr + 232] = uint8(c2da_fresh2)
                c2da_mem[plr + 233] = uint8(c2da_fresh2 >> 0x8)
                c2da_mem[plr + 234] = uint8(c2da_fresh2 >> 0x10)
                c2da_mem[plr + 235] = uint8(c2da_fresh2 >> 0x18)
                c2da_mem[plr + 236] = 0u8
                c2da_mem[plr + 237] = 0u8
                c2da_mem[plr + 238] = 0u8
                c2da_mem[plr + 239] = 0u8
            } else {
                let c2da_fresh3 : uint = 300151u
                c2da_mem[plr + 232] = uint8(c2da_fresh3)
                c2da_mem[plr + 233] = uint8(c2da_fresh3 >> 0x8)
                c2da_mem[plr + 234] = uint8(c2da_fresh3 >> 0x10)
                c2da_mem[plr + 235] = uint8(c2da_fresh3 >> 0x18)
                c2da_mem[plr + 236] = 0u8
                c2da_mem[plr + 237] = 0u8
                c2da_mem[plr + 238] = 0u8
                c2da_mem[plr + 239] = 0u8
            }
        } elif (key == int(uint(c2da_mem[43536]) | uint(c2da_mem[43537]) << 0x8 | uint(c2da_mem[43538]) << 0x10 | uint(c2da_mem[43539]) << 0x18)) {
            M_snprintf(299952, 20ul, 300160, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 300166ul), C2daVaArg(tag = 1, i64 = int64(markpointnum), f64 = 0.0lf, raw = 0x0)])
            let c2da_fresh4 : uint = 299952u
            c2da_mem[plr + 232] = uint8(c2da_fresh4)
            c2da_mem[plr + 233] = uint8(c2da_fresh4 >> 0x8)
            c2da_mem[plr + 234] = uint8(c2da_fresh4 >> 0x10)
            c2da_mem[plr + 235] = uint8(c2da_fresh4 >> 0x18)
            c2da_mem[plr + 236] = 0u8
            c2da_mem[plr + 237] = 0u8
            c2da_mem[plr + 238] = 0u8
            c2da_mem[plr + 239] = 0u8
            AM_addMark()
        } elif (key == int(uint(c2da_mem[43552]) | uint(c2da_mem[43553]) << 0x8 | uint(c2da_mem[43554]) << 0x10 | uint(c2da_mem[43555]) << 0x18)) {
            AM_clearMarks()
            let c2da_fresh5 : uint = 300178u
            c2da_mem[plr + 232] = uint8(c2da_fresh5)
            c2da_mem[plr + 233] = uint8(c2da_fresh5 >> 0x8)
            c2da_mem[plr + 234] = uint8(c2da_fresh5 >> 0x10)
            c2da_mem[plr + 235] = uint8(c2da_fresh5 >> 0x18)
            c2da_mem[plr + 236] = 0u8
            c2da_mem[plr + 237] = 0u8
            c2da_mem[plr + 238] = 0u8
            c2da_mem[plr + 239] = 0u8
        } else {
            rc = 0
        }
        if (deathmatch == 0 && cht_CheckCheat(16, int8(int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18))) != 0) {
            rc = 0
            cheating = (cheating + 1) % 3
        }
    } elif ((uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 1u) {
        rc = 0
        key = int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18)
        if (key == int(uint(c2da_mem[43408]) | uint(c2da_mem[43409]) << 0x8 | uint(c2da_mem[43410]) << 0x10 | uint(c2da_mem[43411]) << 0x18)) {
            if (followplayer == 0) {
                m_paninc.x = 0
            }
        } elif (key == int(uint(c2da_mem[43424]) | uint(c2da_mem[43425]) << 0x8 | uint(c2da_mem[43426]) << 0x10 | uint(c2da_mem[43427]) << 0x18)) {
            if (followplayer == 0) {
                m_paninc.x = 0
            }
        } elif (key == int(uint(c2da_mem[43376]) | uint(c2da_mem[43377]) << 0x8 | uint(c2da_mem[43378]) << 0x10 | uint(c2da_mem[43379]) << 0x18)) {
            if (followplayer == 0) {
                m_paninc.y = 0
            }
        } elif (key == int(uint(c2da_mem[43392]) | uint(c2da_mem[43393]) << 0x8 | uint(c2da_mem[43394]) << 0x10 | uint(c2da_mem[43395]) << 0x18)) {
            if (followplayer == 0) {
                m_paninc.y = 0
            }
        } elif (key == int(uint(c2da_mem[43456]) | uint(c2da_mem[43457]) << 0x8 | uint(c2da_mem[43458]) << 0x10 | uint(c2da_mem[43459]) << 0x18) || key == int(uint(c2da_mem[43440]) | uint(c2da_mem[43441]) << 0x8 | uint(c2da_mem[43442]) << 0x10 | uint(c2da_mem[43443]) << 0x18)) {
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

var private plr : int = default<int>

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
        let c2da_fresh6 : int = int(uint(c2da_mem[plr]) | uint(c2da_mem[plr + 1]) << 0x8 | uint(c2da_mem[plr + 2]) << 0x10 | uint(c2da_mem[plr + 3]) << 0x18) + 24
        m_x = int(uint(c2da_mem[c2da_fresh6]) | uint(c2da_mem[c2da_fresh6 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh6 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh6 + 3]) << 0x18) - m_w / 2
        let c2da_fresh7 : int = int(uint(c2da_mem[plr]) | uint(c2da_mem[plr + 1]) << 0x8 | uint(c2da_mem[plr + 2]) << 0x10 | uint(c2da_mem[plr + 3]) << 0x18) + 28
        m_y = int(uint(c2da_mem[c2da_fresh7]) | uint(c2da_mem[c2da_fresh7 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh7 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh7 + 3]) << 0x18) - m_h / 2
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
    ST_Responder(299984)
    stopped = 1u
    return
}
var private stopped : uint = 1u

[export, sideeffects]
def AM_unloadPics() {
    let c2da_saved_sp : int = c2da_lin_sp
    AM_unloadPics_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
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
    let c2da_saved_sp : int = c2da_lin_sp
    AM_loadPics_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
var private marknums : int[10]

[export, sideeffects]
def AM_initVariables() {
    automapactive = 1u
    fb = I_VideoBuffer
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
        plr = 96 + int(consoleplayer) * 328
    } else {
        plr = 96 + 0 * 328
        for (pnum in range(0, 4)) {
            if (playeringame[pnum] != 0x0) {
                plr = 96 + pnum * 328
                break
            }
        }
    }
    let c2da_fresh8 : int = int(uint(c2da_mem[plr]) | uint(c2da_mem[plr + 1]) << 0x8 | uint(c2da_mem[plr + 2]) << 0x10 | uint(c2da_mem[plr + 3]) << 0x18) + 24
    m_x = int(uint(c2da_mem[c2da_fresh8]) | uint(c2da_mem[c2da_fresh8 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh8 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh8 + 3]) << 0x18) - m_w / 2
    let c2da_fresh9 : int = int(uint(c2da_mem[plr]) | uint(c2da_mem[plr + 1]) << 0x8 | uint(c2da_mem[plr + 2]) << 0x10 | uint(c2da_mem[plr + 3]) << 0x18) + 28
    m_y = int(uint(c2da_mem[c2da_fresh9]) | uint(c2da_mem[c2da_fresh9 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh9 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh9 + 3]) << 0x18) - m_h / 2
    AM_changeWindowLoc()
    old_m_x = int(m_x)  // nolint:PERF020
    old_m_y = int(m_y)  // nolint:PERF020
    old_m_w = int(m_w)  // nolint:PERF020
    old_m_h = int(m_h)  // nolint:PERF020
    ST_Responder(300016)
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

var private fb : int = default<int>

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
        if (int(uint(c2da_mem[vertexes + i_2 * 8]) | uint(c2da_mem[vertexes + i_2 * 8 + 1]) << 0x8 | uint(c2da_mem[vertexes + i_2 * 8 + 2]) << 0x10 | uint(c2da_mem[vertexes + i_2 * 8 + 3]) << 0x18) < min_x) {
            min_x = int(uint(c2da_mem[vertexes + i_2 * 8]) | uint(c2da_mem[vertexes + i_2 * 8 + 1]) << 0x8 | uint(c2da_mem[vertexes + i_2 * 8 + 2]) << 0x10 | uint(c2da_mem[vertexes + i_2 * 8 + 3]) << 0x18)
        } elif (int(uint(c2da_mem[vertexes + i_2 * 8]) | uint(c2da_mem[vertexes + i_2 * 8 + 1]) << 0x8 | uint(c2da_mem[vertexes + i_2 * 8 + 2]) << 0x10 | uint(c2da_mem[vertexes + i_2 * 8 + 3]) << 0x18) > max_x) {
            max_x = int(uint(c2da_mem[vertexes + i_2 * 8]) | uint(c2da_mem[vertexes + i_2 * 8 + 1]) << 0x8 | uint(c2da_mem[vertexes + i_2 * 8 + 2]) << 0x10 | uint(c2da_mem[vertexes + i_2 * 8 + 3]) << 0x18)
        }
        if (int(uint(c2da_mem[vertexes + i_2 * 8 + 4]) | uint(c2da_mem[vertexes + i_2 * 8 + 5]) << 0x8 | uint(c2da_mem[vertexes + i_2 * 8 + 6]) << 0x10 | uint(c2da_mem[vertexes + i_2 * 8 + 7]) << 0x18) < min_y) {
            min_y = int(uint(c2da_mem[vertexes + i_2 * 8 + 4]) | uint(c2da_mem[vertexes + i_2 * 8 + 5]) << 0x8 | uint(c2da_mem[vertexes + i_2 * 8 + 6]) << 0x10 | uint(c2da_mem[vertexes + i_2 * 8 + 7]) << 0x18)
        } elif (int(uint(c2da_mem[vertexes + i_2 * 8 + 4]) | uint(c2da_mem[vertexes + i_2 * 8 + 5]) << 0x8 | uint(c2da_mem[vertexes + i_2 * 8 + 6]) << 0x10 | uint(c2da_mem[vertexes + i_2 * 8 + 7]) << 0x18) > max_y) {
            max_y = int(uint(c2da_mem[vertexes + i_2 * 8 + 4]) | uint(c2da_mem[vertexes + i_2 * 8 + 5]) << 0x8 | uint(c2da_mem[vertexes + i_2 * 8 + 6]) << 0x10 | uint(c2da_mem[vertexes + i_2 * 8 + 7]) << 0x18)
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
    let c2da_fresh10 : int = int(uint(c2da_mem[plr]) | uint(c2da_mem[plr + 1]) << 0x8 | uint(c2da_mem[plr + 2]) << 0x10 | uint(c2da_mem[plr + 3]) << 0x18) + 24
    var c2da_fresh12 : int = 1
    if (!(f_oldloc.x != int(uint(c2da_mem[c2da_fresh10]) | uint(c2da_mem[c2da_fresh10 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh10 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh10 + 3]) << 0x18))) {
        let c2da_fresh11 : int = int(uint(c2da_mem[plr]) | uint(c2da_mem[plr + 1]) << 0x8 | uint(c2da_mem[plr + 2]) << 0x10 | uint(c2da_mem[plr + 3]) << 0x18) + 28
        if (!(f_oldloc.y != int(uint(c2da_mem[c2da_fresh11]) | uint(c2da_mem[c2da_fresh11 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh11 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh11 + 3]) << 0x18))) {
            c2da_fresh12 = 0
        }
    }
    if (c2da_fresh12 != 0) {
        let c2da_fresh13 : int = int(uint(c2da_mem[plr]) | uint(c2da_mem[plr + 1]) << 0x8 | uint(c2da_mem[plr + 2]) << 0x10 | uint(c2da_mem[plr + 3]) << 0x18) + 24
        m_x = FixedMul(FixedMul(int(uint(c2da_mem[c2da_fresh13]) | uint(c2da_mem[c2da_fresh13 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh13 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh13 + 3]) << 0x18), scale_mtof) >> 16 << 16, scale_ftom) - m_w / 2
        let c2da_fresh14 : int = int(uint(c2da_mem[plr]) | uint(c2da_mem[plr + 1]) << 0x8 | uint(c2da_mem[plr + 2]) << 0x10 | uint(c2da_mem[plr + 3]) << 0x18) + 28
        m_y = FixedMul(FixedMul(int(uint(c2da_mem[c2da_fresh14]) | uint(c2da_mem[c2da_fresh14 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh14 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh14 + 3]) << 0x18), scale_mtof) >> 16 << 16, scale_ftom) - m_h / 2
        m_x2 = m_x + m_w
        m_y2 = m_y + m_h
        let c2da_fresh15 : int = int(uint(c2da_mem[plr]) | uint(c2da_mem[plr + 1]) << 0x8 | uint(c2da_mem[plr + 2]) << 0x10 | uint(c2da_mem[plr + 3]) << 0x18) + 24
        f_oldloc.x = int(uint(c2da_mem[c2da_fresh15]) | uint(c2da_mem[c2da_fresh15 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh15 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh15 + 3]) << 0x18)
        let c2da_fresh16 : int = int(uint(c2da_mem[plr]) | uint(c2da_mem[plr + 1]) << 0x8 | uint(c2da_mem[plr + 2]) << 0x10 | uint(c2da_mem[plr + 3]) << 0x18) + 28
        f_oldloc.y = int(uint(c2da_mem[c2da_fresh16]) | uint(c2da_mem[c2da_fresh16 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh16 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh16 + 3]) << 0x18)
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
                V_DrawPatch(fx, fy, marknums[i_3])
            }
        }
    }
    return
}
[export, sideeffects]
def AM_drawCrosshair(var color : int) {
    let c2da_fresh17 : int = fb + f_w * (f_h + 1) / 2
    let c2da_fresh18 : uint8 = uint8(color)
    c2da_mem[c2da_fresh17] = c2da_fresh18
    return
}
[export, sideeffects]
def AM_drawThings(var colors_0 : int; var colorrange : int) {
    var i_4 : int
    var t : int
    i_4 = 0
    while (i_4 < numsectors) {
        t = int(uint(c2da_mem[sectors + i_4 * 128 + 96]) | uint(c2da_mem[sectors + i_4 * 128 + 97]) << 0x8 | uint(c2da_mem[sectors + i_4 * 128 + 98]) << 0x10 | uint(c2da_mem[sectors + i_4 * 128 + 99]) << 0x18)
        while (t != 0) {
            AM_drawLineCharacter(1408, int(48ul / 16ul), 16 << 16, uint(c2da_mem[t + 56]) | uint(c2da_mem[t + 57]) << 0x8 | uint(c2da_mem[t + 58]) << 0x10 | uint(c2da_mem[t + 59]) << 0x18, colors_0 + lightlev, int(uint(c2da_mem[t + 24]) | uint(c2da_mem[t + 25]) << 0x8 | uint(c2da_mem[t + 26]) << 0x10 | uint(c2da_mem[t + 27]) << 0x18), int(uint(c2da_mem[t + 28]) | uint(c2da_mem[t + 29]) << 0x8 | uint(c2da_mem[t + 30]) << 0x10 | uint(c2da_mem[t + 31]) << 0x18))
            t = int(uint(c2da_mem[t + 40]) | uint(c2da_mem[t + 41]) << 0x8 | uint(c2da_mem[t + 42]) << 0x10 | uint(c2da_mem[t + 43]) << 0x18)
        }
        i_4++
    }
    return
}
[export, sideeffects]
def AM_drawLineCharacter(var lineguy : int; var lineguylines : int; var scale : int; var angle : uint; var color_0 : int; var x : int; var y : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    AM_drawLineCharacter_c2da_frame(lineguy, lineguylines, scale, angle, color_0, x, y, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def AM_drawMline(var ml : int; var color_1 : int) {
    if (AM_clipMline(ml, 300048) != 0x0) {
        AM_drawFline(300048, color_1)
    }
    return
}
[export, sideeffects]
def AM_drawFline(var fl : int; var color_2 : int) {
    var x_0 : int
    var y_0 : int
    var dx : int
    var dy : int
    var sx : int
    var sy : int
    var ax : int
    var ay : int
    var d : int
    if (int(uint(c2da_mem[fl]) | uint(c2da_mem[fl + 1]) << 0x8 | uint(c2da_mem[fl + 2]) << 0x10 | uint(c2da_mem[fl + 3]) << 0x18) < 0 || int(uint(c2da_mem[fl]) | uint(c2da_mem[fl + 1]) << 0x8 | uint(c2da_mem[fl + 2]) << 0x10 | uint(c2da_mem[fl + 3]) << 0x18) >= f_w || int(uint(c2da_mem[fl + 4]) | uint(c2da_mem[fl + 5]) << 0x8 | uint(c2da_mem[fl + 6]) << 0x10 | uint(c2da_mem[fl + 7]) << 0x18) < 0 || int(uint(c2da_mem[fl + 4]) | uint(c2da_mem[fl + 5]) << 0x8 | uint(c2da_mem[fl + 6]) << 0x10 | uint(c2da_mem[fl + 7]) << 0x18) >= f_h || int(uint(c2da_mem[fl + 8]) | uint(c2da_mem[fl + 9]) << 0x8 | uint(c2da_mem[fl + 10]) << 0x10 | uint(c2da_mem[fl + 11]) << 0x18) < 0 || int(uint(c2da_mem[fl + 8]) | uint(c2da_mem[fl + 9]) << 0x8 | uint(c2da_mem[fl + 10]) << 0x10 | uint(c2da_mem[fl + 11]) << 0x18) >= f_w || int(uint(c2da_mem[fl + 12]) | uint(c2da_mem[fl + 13]) << 0x8 | uint(c2da_mem[fl + 14]) << 0x10 | uint(c2da_mem[fl + 15]) << 0x18) < 0 || int(uint(c2da_mem[fl + 12]) | uint(c2da_mem[fl + 13]) << 0x8 | uint(c2da_mem[fl + 14]) << 0x10 | uint(c2da_mem[fl + 15]) << 0x18) >= f_h) {
        let c2da_postinc : int = AM_drawFline__fuck
        AM_drawFline__fuck++
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 300205, [C2daVaArg(tag = 1, i64 = int64(c2da_postinc), f64 = 0.0lf, raw = 0x0)])
        return
    }
    dx = int(uint(c2da_mem[fl + 8]) | uint(c2da_mem[fl + 9]) << 0x8 | uint(c2da_mem[fl + 10]) << 0x10 | uint(c2da_mem[fl + 11]) << 0x18) - int(uint(c2da_mem[fl]) | uint(c2da_mem[fl + 1]) << 0x8 | uint(c2da_mem[fl + 2]) << 0x10 | uint(c2da_mem[fl + 3]) << 0x18)
    ax = 2 * (dx < 0 ? -dx : dx)
    sx = dx < 0 ? -1 : 1
    dy = int(uint(c2da_mem[fl + 12]) | uint(c2da_mem[fl + 13]) << 0x8 | uint(c2da_mem[fl + 14]) << 0x10 | uint(c2da_mem[fl + 15]) << 0x18) - int(uint(c2da_mem[fl + 4]) | uint(c2da_mem[fl + 5]) << 0x8 | uint(c2da_mem[fl + 6]) << 0x10 | uint(c2da_mem[fl + 7]) << 0x18)
    ay = 2 * (dy < 0 ? -dy : dy)
    sy = dy < 0 ? -1 : 1
    x_0 = int(uint(c2da_mem[fl]) | uint(c2da_mem[fl + 1]) << 0x8 | uint(c2da_mem[fl + 2]) << 0x10 | uint(c2da_mem[fl + 3]) << 0x18)
    y_0 = int(uint(c2da_mem[fl + 4]) | uint(c2da_mem[fl + 5]) << 0x8 | uint(c2da_mem[fl + 6]) << 0x10 | uint(c2da_mem[fl + 7]) << 0x18)
    if (ax > ay) {
        d = ay - ax / 2
        while (true) {
            let c2da_fresh43 : uint8 = uint8(color_2)
            c2da_mem[fb + (y_0 * f_w + x_0)] = c2da_fresh43
            if (x_0 == int(uint(c2da_mem[fl + 8]) | uint(c2da_mem[fl + 9]) << 0x8 | uint(c2da_mem[fl + 10]) << 0x10 | uint(c2da_mem[fl + 11]) << 0x18)) {
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
            let c2da_fresh44 : uint8 = uint8(color_2)
            c2da_mem[fb + (y_0 * f_w + x_0)] = c2da_fresh44
            if (y_0 == int(uint(c2da_mem[fl + 12]) | uint(c2da_mem[fl + 13]) << 0x8 | uint(c2da_mem[fl + 14]) << 0x10 | uint(c2da_mem[fl + 15]) << 0x18)) {
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
def AM_clipMline(var ml_0 : int; var fl_0 : int) : uint {
    var outcode1 : int
    var outcode2 : int
    var outside : int
    var tmp : fpoint_t
    var dx_0 : int
    var dy_0 : int
    outcode1 = 0
    outcode2 = 0
    if (int(uint(c2da_mem[ml_0 + 4]) | uint(c2da_mem[ml_0 + 5]) << 0x8 | uint(c2da_mem[ml_0 + 6]) << 0x10 | uint(c2da_mem[ml_0 + 7]) << 0x18) > m_y2) {
        outcode1 = 8
    } elif (int(uint(c2da_mem[ml_0 + 4]) | uint(c2da_mem[ml_0 + 5]) << 0x8 | uint(c2da_mem[ml_0 + 6]) << 0x10 | uint(c2da_mem[ml_0 + 7]) << 0x18) < m_y) {
        outcode1 = 4
    }
    if (int(uint(c2da_mem[ml_0 + 12]) | uint(c2da_mem[ml_0 + 13]) << 0x8 | uint(c2da_mem[ml_0 + 14]) << 0x10 | uint(c2da_mem[ml_0 + 15]) << 0x18) > m_y2) {
        outcode2 = 8
    } elif (int(uint(c2da_mem[ml_0 + 12]) | uint(c2da_mem[ml_0 + 13]) << 0x8 | uint(c2da_mem[ml_0 + 14]) << 0x10 | uint(c2da_mem[ml_0 + 15]) << 0x18) < m_y) {
        outcode2 = 4
    }
    if ((outcode1 & outcode2) != 0) {
        return 0u
    }
    if (int(uint(c2da_mem[ml_0]) | uint(c2da_mem[ml_0 + 1]) << 0x8 | uint(c2da_mem[ml_0 + 2]) << 0x10 | uint(c2da_mem[ml_0 + 3]) << 0x18) < m_x) {
        outcode1 |= 1
    } elif (int(uint(c2da_mem[ml_0]) | uint(c2da_mem[ml_0 + 1]) << 0x8 | uint(c2da_mem[ml_0 + 2]) << 0x10 | uint(c2da_mem[ml_0 + 3]) << 0x18) > m_x2) {
        outcode1 |= 2
    }
    if (int(uint(c2da_mem[ml_0 + 8]) | uint(c2da_mem[ml_0 + 9]) << 0x8 | uint(c2da_mem[ml_0 + 10]) << 0x10 | uint(c2da_mem[ml_0 + 11]) << 0x18) < m_x) {
        outcode2 |= 1
    } elif (int(uint(c2da_mem[ml_0 + 8]) | uint(c2da_mem[ml_0 + 9]) << 0x8 | uint(c2da_mem[ml_0 + 10]) << 0x10 | uint(c2da_mem[ml_0 + 11]) << 0x18) > m_x2) {
        outcode2 |= 2
    }
    if ((outcode1 & outcode2) != 0) {
        return 0u
    }
    let c2da_fresh45 : int = f_x + (FixedMul(int(uint(c2da_mem[ml_0]) | uint(c2da_mem[ml_0 + 1]) << 0x8 | uint(c2da_mem[ml_0 + 2]) << 0x10 | uint(c2da_mem[ml_0 + 3]) << 0x18) - m_x, scale_mtof) >> 16)
    let c2da_fresh46 : uint = uint(c2da_fresh45)
    c2da_mem[fl_0] = uint8(c2da_fresh46)
    c2da_mem[fl_0 + 1] = uint8(c2da_fresh46 >> 0x8)
    c2da_mem[fl_0 + 2] = uint8(c2da_fresh46 >> 0x10)
    c2da_mem[fl_0 + 3] = uint8(c2da_fresh46 >> 0x18)
    let c2da_fresh47 : int = f_y + (f_h - (FixedMul(int(uint(c2da_mem[ml_0 + 4]) | uint(c2da_mem[ml_0 + 5]) << 0x8 | uint(c2da_mem[ml_0 + 6]) << 0x10 | uint(c2da_mem[ml_0 + 7]) << 0x18) - m_y, scale_mtof) >> 16))
    let c2da_fresh48 : uint = uint(c2da_fresh47)
    c2da_mem[fl_0 + 4] = uint8(c2da_fresh48)
    c2da_mem[fl_0 + 5] = uint8(c2da_fresh48 >> 0x8)
    c2da_mem[fl_0 + 6] = uint8(c2da_fresh48 >> 0x10)
    c2da_mem[fl_0 + 7] = uint8(c2da_fresh48 >> 0x18)
    let c2da_fresh49 : int = f_x + (FixedMul(int(uint(c2da_mem[ml_0 + 8]) | uint(c2da_mem[ml_0 + 9]) << 0x8 | uint(c2da_mem[ml_0 + 10]) << 0x10 | uint(c2da_mem[ml_0 + 11]) << 0x18) - m_x, scale_mtof) >> 16)
    let c2da_fresh50 : uint = uint(c2da_fresh49)
    c2da_mem[fl_0 + 8] = uint8(c2da_fresh50)
    c2da_mem[fl_0 + 9] = uint8(c2da_fresh50 >> 0x8)
    c2da_mem[fl_0 + 10] = uint8(c2da_fresh50 >> 0x10)
    c2da_mem[fl_0 + 11] = uint8(c2da_fresh50 >> 0x18)
    let c2da_fresh51 : int = f_y + (f_h - (FixedMul(int(uint(c2da_mem[ml_0 + 12]) | uint(c2da_mem[ml_0 + 13]) << 0x8 | uint(c2da_mem[ml_0 + 14]) << 0x10 | uint(c2da_mem[ml_0 + 15]) << 0x18) - m_y, scale_mtof) >> 16))
    let c2da_fresh52 : uint = uint(c2da_fresh51)
    c2da_mem[fl_0 + 12] = uint8(c2da_fresh52)
    c2da_mem[fl_0 + 13] = uint8(c2da_fresh52 >> 0x8)
    c2da_mem[fl_0 + 14] = uint8(c2da_fresh52 >> 0x10)
    c2da_mem[fl_0 + 15] = uint8(c2da_fresh52 >> 0x18)
    outcode1 = 0
    if (int(uint(c2da_mem[fl_0 + 4]) | uint(c2da_mem[fl_0 + 5]) << 0x8 | uint(c2da_mem[fl_0 + 6]) << 0x10 | uint(c2da_mem[fl_0 + 7]) << 0x18) < 0) {
        outcode1 |= 8
    } elif (int(uint(c2da_mem[fl_0 + 4]) | uint(c2da_mem[fl_0 + 5]) << 0x8 | uint(c2da_mem[fl_0 + 6]) << 0x10 | uint(c2da_mem[fl_0 + 7]) << 0x18) >= f_h) {
        outcode1 |= 4
    }
    if (int(uint(c2da_mem[fl_0]) | uint(c2da_mem[fl_0 + 1]) << 0x8 | uint(c2da_mem[fl_0 + 2]) << 0x10 | uint(c2da_mem[fl_0 + 3]) << 0x18) < 0) {
        outcode1 |= 1
    } elif (int(uint(c2da_mem[fl_0]) | uint(c2da_mem[fl_0 + 1]) << 0x8 | uint(c2da_mem[fl_0 + 2]) << 0x10 | uint(c2da_mem[fl_0 + 3]) << 0x18) >= f_w) {
        outcode1 |= 2
    }
    outcode2 = 0
    if (int(uint(c2da_mem[fl_0 + 12]) | uint(c2da_mem[fl_0 + 13]) << 0x8 | uint(c2da_mem[fl_0 + 14]) << 0x10 | uint(c2da_mem[fl_0 + 15]) << 0x18) < 0) {
        outcode2 |= 8
    } elif (int(uint(c2da_mem[fl_0 + 12]) | uint(c2da_mem[fl_0 + 13]) << 0x8 | uint(c2da_mem[fl_0 + 14]) << 0x10 | uint(c2da_mem[fl_0 + 15]) << 0x18) >= f_h) {
        outcode2 |= 4
    }
    if (int(uint(c2da_mem[fl_0 + 8]) | uint(c2da_mem[fl_0 + 9]) << 0x8 | uint(c2da_mem[fl_0 + 10]) << 0x10 | uint(c2da_mem[fl_0 + 11]) << 0x18) < 0) {
        outcode2 |= 1
    } elif (int(uint(c2da_mem[fl_0 + 8]) | uint(c2da_mem[fl_0 + 9]) << 0x8 | uint(c2da_mem[fl_0 + 10]) << 0x10 | uint(c2da_mem[fl_0 + 11]) << 0x18) >= f_w) {
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
            dy_0 = int(uint(c2da_mem[fl_0 + 4]) | uint(c2da_mem[fl_0 + 5]) << 0x8 | uint(c2da_mem[fl_0 + 6]) << 0x10 | uint(c2da_mem[fl_0 + 7]) << 0x18) - int(uint(c2da_mem[fl_0 + 12]) | uint(c2da_mem[fl_0 + 13]) << 0x8 | uint(c2da_mem[fl_0 + 14]) << 0x10 | uint(c2da_mem[fl_0 + 15]) << 0x18)
            dx_0 = int(uint(c2da_mem[fl_0 + 8]) | uint(c2da_mem[fl_0 + 9]) << 0x8 | uint(c2da_mem[fl_0 + 10]) << 0x10 | uint(c2da_mem[fl_0 + 11]) << 0x18) - int(uint(c2da_mem[fl_0]) | uint(c2da_mem[fl_0 + 1]) << 0x8 | uint(c2da_mem[fl_0 + 2]) << 0x10 | uint(c2da_mem[fl_0 + 3]) << 0x18)
            tmp.x = int(uint(c2da_mem[fl_0]) | uint(c2da_mem[fl_0 + 1]) << 0x8 | uint(c2da_mem[fl_0 + 2]) << 0x10 | uint(c2da_mem[fl_0 + 3]) << 0x18) + dx_0 * int(uint(c2da_mem[fl_0 + 4]) | uint(c2da_mem[fl_0 + 5]) << 0x8 | uint(c2da_mem[fl_0 + 6]) << 0x10 | uint(c2da_mem[fl_0 + 7]) << 0x18) / dy_0
            tmp.y = 0
        } elif ((outside & 4) != 0) {
            dy_0 = int(uint(c2da_mem[fl_0 + 4]) | uint(c2da_mem[fl_0 + 5]) << 0x8 | uint(c2da_mem[fl_0 + 6]) << 0x10 | uint(c2da_mem[fl_0 + 7]) << 0x18) - int(uint(c2da_mem[fl_0 + 12]) | uint(c2da_mem[fl_0 + 13]) << 0x8 | uint(c2da_mem[fl_0 + 14]) << 0x10 | uint(c2da_mem[fl_0 + 15]) << 0x18)
            dx_0 = int(uint(c2da_mem[fl_0 + 8]) | uint(c2da_mem[fl_0 + 9]) << 0x8 | uint(c2da_mem[fl_0 + 10]) << 0x10 | uint(c2da_mem[fl_0 + 11]) << 0x18) - int(uint(c2da_mem[fl_0]) | uint(c2da_mem[fl_0 + 1]) << 0x8 | uint(c2da_mem[fl_0 + 2]) << 0x10 | uint(c2da_mem[fl_0 + 3]) << 0x18)
            tmp.x = int(uint(c2da_mem[fl_0]) | uint(c2da_mem[fl_0 + 1]) << 0x8 | uint(c2da_mem[fl_0 + 2]) << 0x10 | uint(c2da_mem[fl_0 + 3]) << 0x18) + dx_0 * (int(uint(c2da_mem[fl_0 + 4]) | uint(c2da_mem[fl_0 + 5]) << 0x8 | uint(c2da_mem[fl_0 + 6]) << 0x10 | uint(c2da_mem[fl_0 + 7]) << 0x18) - f_h) / dy_0
            tmp.y = f_h - 1
        } elif ((outside & 2) != 0) {
            dy_0 = int(uint(c2da_mem[fl_0 + 12]) | uint(c2da_mem[fl_0 + 13]) << 0x8 | uint(c2da_mem[fl_0 + 14]) << 0x10 | uint(c2da_mem[fl_0 + 15]) << 0x18) - int(uint(c2da_mem[fl_0 + 4]) | uint(c2da_mem[fl_0 + 5]) << 0x8 | uint(c2da_mem[fl_0 + 6]) << 0x10 | uint(c2da_mem[fl_0 + 7]) << 0x18)
            dx_0 = int(uint(c2da_mem[fl_0 + 8]) | uint(c2da_mem[fl_0 + 9]) << 0x8 | uint(c2da_mem[fl_0 + 10]) << 0x10 | uint(c2da_mem[fl_0 + 11]) << 0x18) - int(uint(c2da_mem[fl_0]) | uint(c2da_mem[fl_0 + 1]) << 0x8 | uint(c2da_mem[fl_0 + 2]) << 0x10 | uint(c2da_mem[fl_0 + 3]) << 0x18)
            tmp.y = int(uint(c2da_mem[fl_0 + 4]) | uint(c2da_mem[fl_0 + 5]) << 0x8 | uint(c2da_mem[fl_0 + 6]) << 0x10 | uint(c2da_mem[fl_0 + 7]) << 0x18) + dy_0 * (f_w - 1 - int(uint(c2da_mem[fl_0]) | uint(c2da_mem[fl_0 + 1]) << 0x8 | uint(c2da_mem[fl_0 + 2]) << 0x10 | uint(c2da_mem[fl_0 + 3]) << 0x18)) / dx_0
            tmp.x = f_w - 1
        } elif ((outside & 1) != 0) {
            dy_0 = int(uint(c2da_mem[fl_0 + 12]) | uint(c2da_mem[fl_0 + 13]) << 0x8 | uint(c2da_mem[fl_0 + 14]) << 0x10 | uint(c2da_mem[fl_0 + 15]) << 0x18) - int(uint(c2da_mem[fl_0 + 4]) | uint(c2da_mem[fl_0 + 5]) << 0x8 | uint(c2da_mem[fl_0 + 6]) << 0x10 | uint(c2da_mem[fl_0 + 7]) << 0x18)
            dx_0 = int(uint(c2da_mem[fl_0 + 8]) | uint(c2da_mem[fl_0 + 9]) << 0x8 | uint(c2da_mem[fl_0 + 10]) << 0x10 | uint(c2da_mem[fl_0 + 11]) << 0x18) - int(uint(c2da_mem[fl_0]) | uint(c2da_mem[fl_0 + 1]) << 0x8 | uint(c2da_mem[fl_0 + 2]) << 0x10 | uint(c2da_mem[fl_0 + 3]) << 0x18)
            tmp.y = int(uint(c2da_mem[fl_0 + 4]) | uint(c2da_mem[fl_0 + 5]) << 0x8 | uint(c2da_mem[fl_0 + 6]) << 0x10 | uint(c2da_mem[fl_0 + 7]) << 0x18) + dy_0 * -int(uint(c2da_mem[fl_0]) | uint(c2da_mem[fl_0 + 1]) << 0x8 | uint(c2da_mem[fl_0 + 2]) << 0x10 | uint(c2da_mem[fl_0 + 3]) << 0x18) / dx_0
            tmp.x = 0
        } else {
            tmp.x = 0
            tmp.y = 0
        }
        if (outside == outcode1) {
            let c2da_fresh53 : uint = uint(tmp.x)
            c2da_mem[fl_0] = uint8(c2da_fresh53)
            c2da_mem[fl_0 + 1] = uint8(c2da_fresh53 >> 0x8)
            c2da_mem[fl_0 + 2] = uint8(c2da_fresh53 >> 0x10)
            c2da_mem[fl_0 + 3] = uint8(c2da_fresh53 >> 0x18)
            let c2da_fresh54 : uint = uint(tmp.y)
            c2da_mem[fl_0 + 4] = uint8(c2da_fresh54)
            c2da_mem[fl_0 + 5] = uint8(c2da_fresh54 >> 0x8)
            c2da_mem[fl_0 + 6] = uint8(c2da_fresh54 >> 0x10)
            c2da_mem[fl_0 + 7] = uint8(c2da_fresh54 >> 0x18)
            outcode1 = 0
            if (int(uint(c2da_mem[fl_0 + 4]) | uint(c2da_mem[fl_0 + 5]) << 0x8 | uint(c2da_mem[fl_0 + 6]) << 0x10 | uint(c2da_mem[fl_0 + 7]) << 0x18) < 0) {
                outcode1 |= 8
            } elif (int(uint(c2da_mem[fl_0 + 4]) | uint(c2da_mem[fl_0 + 5]) << 0x8 | uint(c2da_mem[fl_0 + 6]) << 0x10 | uint(c2da_mem[fl_0 + 7]) << 0x18) >= f_h) {
                outcode1 |= 4
            }
            if (int(uint(c2da_mem[fl_0]) | uint(c2da_mem[fl_0 + 1]) << 0x8 | uint(c2da_mem[fl_0 + 2]) << 0x10 | uint(c2da_mem[fl_0 + 3]) << 0x18) < 0) {
                outcode1 |= 1
            } elif (int(uint(c2da_mem[fl_0]) | uint(c2da_mem[fl_0 + 1]) << 0x8 | uint(c2da_mem[fl_0 + 2]) << 0x10 | uint(c2da_mem[fl_0 + 3]) << 0x18) >= f_w) {
                outcode1 |= 2
            }
        } else {
            let c2da_fresh55 : uint = uint(tmp.x)
            c2da_mem[fl_0 + 8] = uint8(c2da_fresh55)
            c2da_mem[fl_0 + 9] = uint8(c2da_fresh55 >> 0x8)
            c2da_mem[fl_0 + 10] = uint8(c2da_fresh55 >> 0x10)
            c2da_mem[fl_0 + 11] = uint8(c2da_fresh55 >> 0x18)
            let c2da_fresh56 : uint = uint(tmp.y)
            c2da_mem[fl_0 + 12] = uint8(c2da_fresh56)
            c2da_mem[fl_0 + 13] = uint8(c2da_fresh56 >> 0x8)
            c2da_mem[fl_0 + 14] = uint8(c2da_fresh56 >> 0x10)
            c2da_mem[fl_0 + 15] = uint8(c2da_fresh56 >> 0x18)
            outcode2 = 0
            if (int(uint(c2da_mem[fl_0 + 12]) | uint(c2da_mem[fl_0 + 13]) << 0x8 | uint(c2da_mem[fl_0 + 14]) << 0x10 | uint(c2da_mem[fl_0 + 15]) << 0x18) < 0) {
                outcode2 |= 8
            } elif (int(uint(c2da_mem[fl_0 + 12]) | uint(c2da_mem[fl_0 + 13]) << 0x8 | uint(c2da_mem[fl_0 + 14]) << 0x10 | uint(c2da_mem[fl_0 + 15]) << 0x18) >= f_h) {
                outcode2 |= 4
            }
            if (int(uint(c2da_mem[fl_0 + 8]) | uint(c2da_mem[fl_0 + 9]) << 0x8 | uint(c2da_mem[fl_0 + 10]) << 0x10 | uint(c2da_mem[fl_0 + 11]) << 0x18) < 0) {
                outcode2 |= 1
            } elif (int(uint(c2da_mem[fl_0 + 8]) | uint(c2da_mem[fl_0 + 9]) << 0x8 | uint(c2da_mem[fl_0 + 10]) << 0x10 | uint(c2da_mem[fl_0 + 11]) << 0x18) >= f_w) {
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
def AM_rotate(var x_1 : int; var y_1 : int; var a_0 : uint) {
    var tmpx : int
    let c2da_fresh57 : int = finecosine + int(a_0 >> 19u) * 4
    let c2da_fresh58 : int = 257920 + int(a_0 >> 19u) * 4
    tmpx = FixedMul(int(uint(c2da_mem[x_1]) | uint(c2da_mem[x_1 + 1]) << 0x8 | uint(c2da_mem[x_1 + 2]) << 0x10 | uint(c2da_mem[x_1 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh57]) | uint(c2da_mem[c2da_fresh57 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh57 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh57 + 3]) << 0x18)) - FixedMul(int(uint(c2da_mem[y_1]) | uint(c2da_mem[y_1 + 1]) << 0x8 | uint(c2da_mem[y_1 + 2]) << 0x10 | uint(c2da_mem[y_1 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh58]) | uint(c2da_mem[c2da_fresh58 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh58 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh58 + 3]) << 0x18))
    let c2da_fresh59 : int = 257920 + int(a_0 >> 19u) * 4
    let c2da_fresh60 : int = finecosine + int(a_0 >> 19u) * 4
    let c2da_fresh61 : int = FixedMul(int(uint(c2da_mem[x_1]) | uint(c2da_mem[x_1 + 1]) << 0x8 | uint(c2da_mem[x_1 + 2]) << 0x10 | uint(c2da_mem[x_1 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh59]) | uint(c2da_mem[c2da_fresh59 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh59 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh59 + 3]) << 0x18)) + FixedMul(int(uint(c2da_mem[y_1]) | uint(c2da_mem[y_1 + 1]) << 0x8 | uint(c2da_mem[y_1 + 2]) << 0x10 | uint(c2da_mem[y_1 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh60]) | uint(c2da_mem[c2da_fresh60 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh60 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh60 + 3]) << 0x18))
    let c2da_fresh62 : uint = uint(c2da_fresh61)
    c2da_mem[y_1] = uint8(c2da_fresh62)
    c2da_mem[y_1 + 1] = uint8(c2da_fresh62 >> 0x8)
    c2da_mem[y_1 + 2] = uint8(c2da_fresh62 >> 0x10)
    c2da_mem[y_1 + 3] = uint8(c2da_fresh62 >> 0x18)
    let c2da_fresh63 : uint = uint(tmpx)
    c2da_mem[x_1] = uint8(c2da_fresh63)
    c2da_mem[x_1 + 1] = uint8(c2da_fresh63 >> 0x8)
    c2da_mem[x_1 + 2] = uint8(c2da_fresh63 >> 0x10)
    c2da_mem[x_1 + 3] = uint8(c2da_fresh63 >> 0x18)
    return
}
[export, sideeffects]
def AM_drawPlayers() {
    var p : int
    var their_color : int
    var color_3 : int
    their_color = -1
    if (netgame == 0) {
        if (cheating != 0) {
            let c2da_fresh64 : int = int(uint(c2da_mem[plr]) | uint(c2da_mem[plr + 1]) << 0x8 | uint(c2da_mem[plr + 2]) << 0x10 | uint(c2da_mem[plr + 3]) << 0x18) + 56
            let c2da_fresh65 : int = int(uint(c2da_mem[plr]) | uint(c2da_mem[plr + 1]) << 0x8 | uint(c2da_mem[plr + 2]) << 0x10 | uint(c2da_mem[plr + 3]) << 0x18) + 24
            let c2da_fresh66 : int = int(uint(c2da_mem[plr]) | uint(c2da_mem[plr + 1]) << 0x8 | uint(c2da_mem[plr + 2]) << 0x10 | uint(c2da_mem[plr + 3]) << 0x18) + 28
            AM_drawLineCharacter(1456, int(256ul / 16ul), 0, uint(c2da_mem[c2da_fresh64]) | uint(c2da_mem[c2da_fresh64 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh64 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh64 + 3]) << 0x18, 256 - 47, int(uint(c2da_mem[c2da_fresh65]) | uint(c2da_mem[c2da_fresh65 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh65 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh65 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh66]) | uint(c2da_mem[c2da_fresh66 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh66 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh66 + 3]) << 0x18))
        } else {
            let c2da_fresh67 : int = int(uint(c2da_mem[plr]) | uint(c2da_mem[plr + 1]) << 0x8 | uint(c2da_mem[plr + 2]) << 0x10 | uint(c2da_mem[plr + 3]) << 0x18) + 56
            let c2da_fresh68 : int = int(uint(c2da_mem[plr]) | uint(c2da_mem[plr + 1]) << 0x8 | uint(c2da_mem[plr + 2]) << 0x10 | uint(c2da_mem[plr + 3]) << 0x18) + 24
            let c2da_fresh69 : int = int(uint(c2da_mem[plr]) | uint(c2da_mem[plr + 1]) << 0x8 | uint(c2da_mem[plr + 2]) << 0x10 | uint(c2da_mem[plr + 3]) << 0x18) + 28
            AM_drawLineCharacter(1712, int(112ul / 16ul), 0, uint(c2da_mem[c2da_fresh67]) | uint(c2da_mem[c2da_fresh67 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh67 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh67 + 3]) << 0x18, 256 - 47, int(uint(c2da_mem[c2da_fresh68]) | uint(c2da_mem[c2da_fresh68 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh68 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh68 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh69]) | uint(c2da_mem[c2da_fresh69 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh69 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh69 + 3]) << 0x18))
        }
        return
    }
    for (i_6 in range(0, 4)) {
        their_color++
        p = 96 + i_6 * 328
        if (deathmatch != 0 && singledemo == 0 && p != plr) {
            continue
        }
        if (playeringame[i_6] == 0) {
            continue
        }
        if (int(uint(c2da_mem[p + 56 + 2 * 4]) | uint(c2da_mem[p + 56 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[p + 56 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[p + 56 + 2 * 4 + 3]) << 0x18) != 0) {
            color_3 = 246
        } else {
            color_3 = AM_drawPlayers__their_colors[their_color]
        }
        let c2da_fresh70 : int = int(uint(c2da_mem[p]) | uint(c2da_mem[p + 1]) << 0x8 | uint(c2da_mem[p + 2]) << 0x10 | uint(c2da_mem[p + 3]) << 0x18) + 56
        let c2da_fresh71 : int = int(uint(c2da_mem[p]) | uint(c2da_mem[p + 1]) << 0x8 | uint(c2da_mem[p + 2]) << 0x10 | uint(c2da_mem[p + 3]) << 0x18) + 24
        let c2da_fresh72 : int = int(uint(c2da_mem[p]) | uint(c2da_mem[p + 1]) << 0x8 | uint(c2da_mem[p + 2]) << 0x10 | uint(c2da_mem[p + 3]) << 0x18) + 28
        AM_drawLineCharacter(1712, int(112ul / 16ul), 0, uint(c2da_mem[c2da_fresh70]) | uint(c2da_mem[c2da_fresh70 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh70 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh70 + 3]) << 0x18, color_3, int(uint(c2da_mem[c2da_fresh71]) | uint(c2da_mem[c2da_fresh71 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh71 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh71 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh72]) | uint(c2da_mem[c2da_fresh72 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh72 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh72 + 3]) << 0x18))
    }
    return
}
[export, sideeffects]
def AM_drawWalls() {
    var i_7 : int = 0
    while (i_7 < numlines) {
        let c2da_fresh73 : int = int(uint(c2da_mem[lines + i_7 * 88]) | uint(c2da_mem[lines + i_7 * 88 + 1]) << 0x8 | uint(c2da_mem[lines + i_7 * 88 + 2]) << 0x10 | uint(c2da_mem[lines + i_7 * 88 + 3]) << 0x18)
        let c2da_fresh74 : int = int(uint(c2da_mem[c2da_fresh73]) | uint(c2da_mem[c2da_fresh73 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh73 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh73 + 3]) << 0x18)
        let c2da_fresh75 : uint = uint(c2da_fresh74)
        c2da_mem[300064] = uint8(c2da_fresh75)
        c2da_mem[300065] = uint8(c2da_fresh75 >> 0x8)
        c2da_mem[300066] = uint8(c2da_fresh75 >> 0x10)
        c2da_mem[300067] = uint8(c2da_fresh75 >> 0x18)
        let c2da_fresh76 : int = int(uint(c2da_mem[lines + i_7 * 88]) | uint(c2da_mem[lines + i_7 * 88 + 1]) << 0x8 | uint(c2da_mem[lines + i_7 * 88 + 2]) << 0x10 | uint(c2da_mem[lines + i_7 * 88 + 3]) << 0x18) + 4
        let c2da_fresh77 : int = int(uint(c2da_mem[c2da_fresh76]) | uint(c2da_mem[c2da_fresh76 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh76 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh76 + 3]) << 0x18)
        let c2da_fresh78 : uint = uint(c2da_fresh77)
        c2da_mem[300068] = uint8(c2da_fresh78)
        c2da_mem[300069] = uint8(c2da_fresh78 >> 0x8)
        c2da_mem[300070] = uint8(c2da_fresh78 >> 0x10)
        c2da_mem[300071] = uint8(c2da_fresh78 >> 0x18)
        let c2da_fresh79 : int = int(uint(c2da_mem[lines + i_7 * 88 + 8]) | uint(c2da_mem[lines + i_7 * 88 + 9]) << 0x8 | uint(c2da_mem[lines + i_7 * 88 + 10]) << 0x10 | uint(c2da_mem[lines + i_7 * 88 + 11]) << 0x18)
        let c2da_fresh80 : int = int(uint(c2da_mem[c2da_fresh79]) | uint(c2da_mem[c2da_fresh79 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh79 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh79 + 3]) << 0x18)
        let c2da_fresh81 : uint = uint(c2da_fresh80)
        c2da_mem[300072] = uint8(c2da_fresh81)
        c2da_mem[300073] = uint8(c2da_fresh81 >> 0x8)
        c2da_mem[300074] = uint8(c2da_fresh81 >> 0x10)
        c2da_mem[300075] = uint8(c2da_fresh81 >> 0x18)
        let c2da_fresh82 : int = int(uint(c2da_mem[lines + i_7 * 88 + 8]) | uint(c2da_mem[lines + i_7 * 88 + 9]) << 0x8 | uint(c2da_mem[lines + i_7 * 88 + 10]) << 0x10 | uint(c2da_mem[lines + i_7 * 88 + 11]) << 0x18) + 4
        let c2da_fresh83 : int = int(uint(c2da_mem[c2da_fresh82]) | uint(c2da_mem[c2da_fresh82 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh82 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh82 + 3]) << 0x18)
        let c2da_fresh84 : uint = uint(c2da_fresh83)
        c2da_mem[300076] = uint8(c2da_fresh84)
        c2da_mem[300077] = uint8(c2da_fresh84 >> 0x8)
        c2da_mem[300078] = uint8(c2da_fresh84 >> 0x10)
        c2da_mem[300079] = uint8(c2da_fresh84 >> 0x18)
        if (cheating != 0 || (int(int16(uint(c2da_mem[lines + i_7 * 88 + 24]) | uint(c2da_mem[lines + i_7 * 88 + 25]) << 0x8)) & 256) != 0) {
            if ((int(int16(uint(c2da_mem[lines + i_7 * 88 + 24]) | uint(c2da_mem[lines + i_7 * 88 + 25]) << 0x8)) & 128) != 0 && cheating == 0) {
                i_7++
                continue
            }
            if (int(uint(c2da_mem[lines + i_7 * 88 + 64]) | uint(c2da_mem[lines + i_7 * 88 + 65]) << 0x8 | uint(c2da_mem[lines + i_7 * 88 + 66]) << 0x10 | uint(c2da_mem[lines + i_7 * 88 + 67]) << 0x18) == 0) {
                AM_drawMline(300064, 256 - 5 * 16 + lightlev)
            } elif (int(int16(uint(c2da_mem[lines + i_7 * 88 + 26]) | uint(c2da_mem[lines + i_7 * 88 + 27]) << 0x8)) == 39) {
                AM_drawMline(300064, 256 - 5 * 16 + 16 / 2)
            } elif ((int(int16(uint(c2da_mem[lines + i_7 * 88 + 24]) | uint(c2da_mem[lines + i_7 * 88 + 25]) << 0x8)) & 32) != 0) {
                if (cheating != 0) {
                    AM_drawMline(300064, 256 - 5 * 16 + lightlev)
                } else {
                    AM_drawMline(300064, 256 - 5 * 16 + lightlev)
                }
            } else {
                let c2da_fresh85 : int = int(uint(c2da_mem[lines + i_7 * 88 + 64]) | uint(c2da_mem[lines + i_7 * 88 + 65]) << 0x8 | uint(c2da_mem[lines + i_7 * 88 + 66]) << 0x10 | uint(c2da_mem[lines + i_7 * 88 + 67]) << 0x18)
                let c2da_fresh86 : int = int(uint(c2da_mem[lines + i_7 * 88 + 56]) | uint(c2da_mem[lines + i_7 * 88 + 57]) << 0x8 | uint(c2da_mem[lines + i_7 * 88 + 58]) << 0x10 | uint(c2da_mem[lines + i_7 * 88 + 59]) << 0x18)
                if (int(uint(c2da_mem[c2da_fresh85]) | uint(c2da_mem[c2da_fresh85 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh85 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh85 + 3]) << 0x18) != int(uint(c2da_mem[c2da_fresh86]) | uint(c2da_mem[c2da_fresh86 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh86 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh86 + 3]) << 0x18)) {
                    AM_drawMline(300064, 4 * 16 + lightlev)
                } else {
                    let c2da_fresh87 : int = int(uint(c2da_mem[lines + i_7 * 88 + 64]) | uint(c2da_mem[lines + i_7 * 88 + 65]) << 0x8 | uint(c2da_mem[lines + i_7 * 88 + 66]) << 0x10 | uint(c2da_mem[lines + i_7 * 88 + 67]) << 0x18) + 4
                    let c2da_fresh88 : int = int(uint(c2da_mem[lines + i_7 * 88 + 56]) | uint(c2da_mem[lines + i_7 * 88 + 57]) << 0x8 | uint(c2da_mem[lines + i_7 * 88 + 58]) << 0x10 | uint(c2da_mem[lines + i_7 * 88 + 59]) << 0x18) + 4
                    if (int(uint(c2da_mem[c2da_fresh87]) | uint(c2da_mem[c2da_fresh87 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh87 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh87 + 3]) << 0x18) != int(uint(c2da_mem[c2da_fresh88]) | uint(c2da_mem[c2da_fresh88 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh88 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh88 + 3]) << 0x18)) {
                        AM_drawMline(300064, 256 - 32 + 7 + lightlev)
                    } elif (cheating != 0) {
                        AM_drawMline(300064, 6 * 16 + lightlev)
                    }
                }
            }
        } elif (int(uint(c2da_mem[plr + 56 + 4 * 4]) | uint(c2da_mem[plr + 56 + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[plr + 56 + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[plr + 56 + 4 * 4 + 3]) << 0x18) != 0) {
            if ((int(int16(uint(c2da_mem[lines + i_7 * 88 + 24]) | uint(c2da_mem[lines + i_7 * 88 + 25]) << 0x8)) & 128) == 0) {
                AM_drawMline(300064, 6 * 16 + 3)
            }
        }
        i_7++
    }
    return
}
[export, sideeffects]
def AM_drawGrid(var color_4 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    AM_drawGrid_c2da_frame(color_4, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def AM_clearFB(var color_5 : int) {
    c2da_lin_memset(fb, color_5, uint64(f_w * f_h))
    return
}
var triangle_guy : mline_t[3] = fixed_array<mline_t>(mline_t(a = mpoint_t(x = int(-0.867lf * double(1 << 16)), y = int(-0.5lf * double(1 << 16))), b = mpoint_t(x = int(0.867lf * double(1 << 16)), y = int(-0.5lf * double(1 << 16)))), mline_t(a = mpoint_t(x = int(0.867lf * double(1 << 16)), y = int(-0.5lf * double(1 << 16))), b = mpoint_t(x = 0, y = 1 << 16)), mline_t(a = mpoint_t(x = 0, y = 1 << 16), b = mpoint_t(x = int(-0.867lf * double(1 << 16)), y = int(-0.5lf * double(1 << 16)))))

[export, sideeffects]
def AM_getIslope(var ml_1 : int; var is_0 : islope_t?) {
    var dx_1 : int
    var dy_1 : int = int(uint(c2da_mem[ml_1 + 4]) | uint(c2da_mem[ml_1 + 5]) << 0x8 | uint(c2da_mem[ml_1 + 6]) << 0x10 | uint(c2da_mem[ml_1 + 7]) << 0x18) - int(uint(c2da_mem[ml_1 + 12]) | uint(c2da_mem[ml_1 + 13]) << 0x8 | uint(c2da_mem[ml_1 + 14]) << 0x10 | uint(c2da_mem[ml_1 + 15]) << 0x18)
    dx_1 = int(uint(c2da_mem[ml_1 + 8]) | uint(c2da_mem[ml_1 + 9]) << 0x8 | uint(c2da_mem[ml_1 + 10]) << 0x10 | uint(c2da_mem[ml_1 + 11]) << 0x18) - int(uint(c2da_mem[ml_1]) | uint(c2da_mem[ml_1 + 1]) << 0x8 | uint(c2da_mem[ml_1 + 2]) << 0x10 | uint(c2da_mem[ml_1 + 3]) << 0x18)
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
        lightlev = int(uint(c2da_mem[300080 + c2da_postinc_0 * 4]) | uint(c2da_mem[300080 + c2da_postinc_0 * 4 + 1]) << 0x8 | uint(c2da_mem[300080 + c2da_postinc_0 * 4 + 2]) << 0x10 | uint(c2da_mem[300080 + c2da_postinc_0 * 4 + 3]) << 0x18)
        if (uint64(AM_updateLightLev__litelevelscnt) == 32ul / 4ul) {
            AM_updateLightLev__litelevelscnt = 0
        }
        AM_updateLightLev__nexttic = amclock + 6 - amclock % 6
    }
    return
}
[sideeffects]
def private AM_unloadPics_c2da_frame(c2da_fp : int) {
    for (i_0 in range(0, 10)) {
        c2da_lin_snprintf(c2da_fp, 9ul, 300196, [C2daVaArg(tag = 1, i64 = int64(i_0), f64 = 0.0lf, raw = 0x0)])
        W_ReleaseLumpName(c2da_fp)
    }
    return
}
[sideeffects]
def private AM_loadPics_c2da_frame(c2da_fp : int) {
    for (i_1 in range(0, 10)) {
        c2da_lin_snprintf(c2da_fp, 9ul, 300196, [C2daVaArg(tag = 1, i64 = int64(i_1), f64 = 0.0lf, raw = 0x0)])
        marknums[i_1] = W_CacheLumpName(c2da_fp, 1)
    }
    return
}
[sideeffects]
def private AM_drawLineCharacter_c2da_frame(var lineguy : int; var lineguylines : int; var scale : int; var angle : uint; var color_0 : int; var x : int; var y : int; c2da_fp : int) {
    for (i_5 in range(0, lineguylines)) {
        let c2da_fresh19 : int = int(uint(c2da_mem[lineguy + i_5 * 16]) | uint(c2da_mem[lineguy + i_5 * 16 + 1]) << 0x8 | uint(c2da_mem[lineguy + i_5 * 16 + 2]) << 0x10 | uint(c2da_mem[lineguy + i_5 * 16 + 3]) << 0x18)
        let c2da_fresh20 : uint = uint(c2da_fresh19)
        c2da_mem[c2da_fp] = uint8(c2da_fresh20)
        c2da_mem[c2da_fp + 1] = uint8(c2da_fresh20 >> 0x8)
        c2da_mem[c2da_fp + 2] = uint8(c2da_fresh20 >> 0x10)
        c2da_mem[c2da_fp + 3] = uint8(c2da_fresh20 >> 0x18)
        let c2da_fresh21 : int = int(uint(c2da_mem[lineguy + i_5 * 16 + 4]) | uint(c2da_mem[lineguy + i_5 * 16 + 5]) << 0x8 | uint(c2da_mem[lineguy + i_5 * 16 + 6]) << 0x10 | uint(c2da_mem[lineguy + i_5 * 16 + 7]) << 0x18)
        let c2da_fresh22 : uint = uint(c2da_fresh21)
        c2da_mem[c2da_fp + 4] = uint8(c2da_fresh22)
        c2da_mem[c2da_fp + 5] = uint8(c2da_fresh22 >> 0x8)
        c2da_mem[c2da_fp + 6] = uint8(c2da_fresh22 >> 0x10)
        c2da_mem[c2da_fp + 7] = uint8(c2da_fresh22 >> 0x18)
        if (scale != 0) {
            let c2da_fresh23 : int = FixedMul(scale, int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18))
            let c2da_fresh24 : uint = uint(c2da_fresh23)
            c2da_mem[c2da_fp] = uint8(c2da_fresh24)
            c2da_mem[c2da_fp + 1] = uint8(c2da_fresh24 >> 0x8)
            c2da_mem[c2da_fp + 2] = uint8(c2da_fresh24 >> 0x10)
            c2da_mem[c2da_fp + 3] = uint8(c2da_fresh24 >> 0x18)
            let c2da_fresh25 : int = FixedMul(scale, int(uint(c2da_mem[c2da_fp + 4]) | uint(c2da_mem[c2da_fp + 5]) << 0x8 | uint(c2da_mem[c2da_fp + 6]) << 0x10 | uint(c2da_mem[c2da_fp + 7]) << 0x18))
            let c2da_fresh26 : uint = uint(c2da_fresh25)
            c2da_mem[c2da_fp + 4] = uint8(c2da_fresh26)
            c2da_mem[c2da_fp + 5] = uint8(c2da_fresh26 >> 0x8)
            c2da_mem[c2da_fp + 6] = uint8(c2da_fresh26 >> 0x10)
            c2da_mem[c2da_fp + 7] = uint8(c2da_fresh26 >> 0x18)
        }
        if (angle != 0x0) {
            AM_rotate(c2da_fp, c2da_fp + 4, angle)
        }
        let c2da_fresh27 : int = int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) + x
        let c2da_fresh28 : uint = uint(c2da_fresh27)
        c2da_mem[c2da_fp] = uint8(c2da_fresh28)
        c2da_mem[c2da_fp + 1] = uint8(c2da_fresh28 >> 0x8)
        c2da_mem[c2da_fp + 2] = uint8(c2da_fresh28 >> 0x10)
        c2da_mem[c2da_fp + 3] = uint8(c2da_fresh28 >> 0x18)
        let c2da_fresh29 : int = int(uint(c2da_mem[c2da_fp + 4]) | uint(c2da_mem[c2da_fp + 5]) << 0x8 | uint(c2da_mem[c2da_fp + 6]) << 0x10 | uint(c2da_mem[c2da_fp + 7]) << 0x18) + y
        let c2da_fresh30 : uint = uint(c2da_fresh29)
        c2da_mem[c2da_fp + 4] = uint8(c2da_fresh30)
        c2da_mem[c2da_fp + 5] = uint8(c2da_fresh30 >> 0x8)
        c2da_mem[c2da_fp + 6] = uint8(c2da_fresh30 >> 0x10)
        c2da_mem[c2da_fp + 7] = uint8(c2da_fresh30 >> 0x18)
        let c2da_fresh31 : int = int(uint(c2da_mem[lineguy + i_5 * 16 + 8]) | uint(c2da_mem[lineguy + i_5 * 16 + 9]) << 0x8 | uint(c2da_mem[lineguy + i_5 * 16 + 10]) << 0x10 | uint(c2da_mem[lineguy + i_5 * 16 + 11]) << 0x18)
        let c2da_fresh32 : uint = uint(c2da_fresh31)
        c2da_mem[c2da_fp + 8] = uint8(c2da_fresh32)
        c2da_mem[c2da_fp + 9] = uint8(c2da_fresh32 >> 0x8)
        c2da_mem[c2da_fp + 10] = uint8(c2da_fresh32 >> 0x10)
        c2da_mem[c2da_fp + 11] = uint8(c2da_fresh32 >> 0x18)
        let c2da_fresh33 : int = int(uint(c2da_mem[lineguy + i_5 * 16 + 12]) | uint(c2da_mem[lineguy + i_5 * 16 + 13]) << 0x8 | uint(c2da_mem[lineguy + i_5 * 16 + 14]) << 0x10 | uint(c2da_mem[lineguy + i_5 * 16 + 15]) << 0x18)
        let c2da_fresh34 : uint = uint(c2da_fresh33)
        c2da_mem[c2da_fp + 12] = uint8(c2da_fresh34)
        c2da_mem[c2da_fp + 13] = uint8(c2da_fresh34 >> 0x8)
        c2da_mem[c2da_fp + 14] = uint8(c2da_fresh34 >> 0x10)
        c2da_mem[c2da_fp + 15] = uint8(c2da_fresh34 >> 0x18)
        if (scale != 0) {
            let c2da_fresh35 : int = FixedMul(scale, int(uint(c2da_mem[c2da_fp + 8]) | uint(c2da_mem[c2da_fp + 9]) << 0x8 | uint(c2da_mem[c2da_fp + 10]) << 0x10 | uint(c2da_mem[c2da_fp + 11]) << 0x18))
            let c2da_fresh36 : uint = uint(c2da_fresh35)
            c2da_mem[c2da_fp + 8] = uint8(c2da_fresh36)
            c2da_mem[c2da_fp + 9] = uint8(c2da_fresh36 >> 0x8)
            c2da_mem[c2da_fp + 10] = uint8(c2da_fresh36 >> 0x10)
            c2da_mem[c2da_fp + 11] = uint8(c2da_fresh36 >> 0x18)
            let c2da_fresh37 : int = FixedMul(scale, int(uint(c2da_mem[c2da_fp + 12]) | uint(c2da_mem[c2da_fp + 13]) << 0x8 | uint(c2da_mem[c2da_fp + 14]) << 0x10 | uint(c2da_mem[c2da_fp + 15]) << 0x18))
            let c2da_fresh38 : uint = uint(c2da_fresh37)
            c2da_mem[c2da_fp + 12] = uint8(c2da_fresh38)
            c2da_mem[c2da_fp + 13] = uint8(c2da_fresh38 >> 0x8)
            c2da_mem[c2da_fp + 14] = uint8(c2da_fresh38 >> 0x10)
            c2da_mem[c2da_fp + 15] = uint8(c2da_fresh38 >> 0x18)
        }
        if (angle != 0x0) {
            AM_rotate(c2da_fp + 8, c2da_fp + 12, angle)
        }
        let c2da_fresh39 : int = int(uint(c2da_mem[c2da_fp + 8]) | uint(c2da_mem[c2da_fp + 9]) << 0x8 | uint(c2da_mem[c2da_fp + 10]) << 0x10 | uint(c2da_mem[c2da_fp + 11]) << 0x18) + x
        let c2da_fresh40 : uint = uint(c2da_fresh39)
        c2da_mem[c2da_fp + 8] = uint8(c2da_fresh40)
        c2da_mem[c2da_fp + 9] = uint8(c2da_fresh40 >> 0x8)
        c2da_mem[c2da_fp + 10] = uint8(c2da_fresh40 >> 0x10)
        c2da_mem[c2da_fp + 11] = uint8(c2da_fresh40 >> 0x18)
        let c2da_fresh41 : int = int(uint(c2da_mem[c2da_fp + 12]) | uint(c2da_mem[c2da_fp + 13]) << 0x8 | uint(c2da_mem[c2da_fp + 14]) << 0x10 | uint(c2da_mem[c2da_fp + 15]) << 0x18) + y
        let c2da_fresh42 : uint = uint(c2da_fresh41)
        c2da_mem[c2da_fp + 12] = uint8(c2da_fresh42)
        c2da_mem[c2da_fp + 13] = uint8(c2da_fresh42 >> 0x8)
        c2da_mem[c2da_fp + 14] = uint8(c2da_fresh42 >> 0x10)
        c2da_mem[c2da_fp + 15] = uint8(c2da_fresh42 >> 0x18)
        AM_drawMline(c2da_fp, color_0)
    }
    return
}
[sideeffects]
def private AM_drawGrid_c2da_frame(var color_4 : int; c2da_fp : int) {
    var x_2 : int
    var y_2 : int
    var start : int
    var end : int
    start = m_x
    if ((start - int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18)) % (128 << 16) != 0) {
        start += (128 << 16) - (start - int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18)) % (128 << 16)
    }
    end = m_x + m_w
    let c2da_fresh89 : uint = uint(m_y)
    c2da_mem[c2da_fp + 4] = uint8(c2da_fresh89)
    c2da_mem[c2da_fp + 5] = uint8(c2da_fresh89 >> 0x8)
    c2da_mem[c2da_fp + 6] = uint8(c2da_fresh89 >> 0x10)
    c2da_mem[c2da_fp + 7] = uint8(c2da_fresh89 >> 0x18)
    let c2da_fresh90 : int = m_y + m_h
    let c2da_fresh91 : uint = uint(c2da_fresh90)
    c2da_mem[c2da_fp + 12] = uint8(c2da_fresh91)
    c2da_mem[c2da_fp + 13] = uint8(c2da_fresh91 >> 0x8)
    c2da_mem[c2da_fp + 14] = uint8(c2da_fresh91 >> 0x10)
    c2da_mem[c2da_fp + 15] = uint8(c2da_fresh91 >> 0x18)
    x_2 = start
    while (x_2 < end) {
        let c2da_fresh92 : uint = uint(x_2)
        c2da_mem[c2da_fp] = uint8(c2da_fresh92)
        c2da_mem[c2da_fp + 1] = uint8(c2da_fresh92 >> 0x8)
        c2da_mem[c2da_fp + 2] = uint8(c2da_fresh92 >> 0x10)
        c2da_mem[c2da_fp + 3] = uint8(c2da_fresh92 >> 0x18)
        let c2da_fresh93 : uint = uint(x_2)
        c2da_mem[c2da_fp + 8] = uint8(c2da_fresh93)
        c2da_mem[c2da_fp + 9] = uint8(c2da_fresh93 >> 0x8)
        c2da_mem[c2da_fp + 10] = uint8(c2da_fresh93 >> 0x10)
        c2da_mem[c2da_fp + 11] = uint8(c2da_fresh93 >> 0x18)
        AM_drawMline(c2da_fp, color_4)
        x_2 += 128 << 16
    }
    start = m_y
    if ((start - int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18)) % (128 << 16) != 0) {
        start += (128 << 16) - (start - int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18)) % (128 << 16)
    }
    end = m_y + m_h
    let c2da_fresh94 : uint = uint(m_x)
    c2da_mem[c2da_fp] = uint8(c2da_fresh94)
    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh94 >> 0x8)
    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh94 >> 0x10)
    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh94 >> 0x18)
    let c2da_fresh95 : int = m_x + m_w
    let c2da_fresh96 : uint = uint(c2da_fresh95)
    c2da_mem[c2da_fp + 8] = uint8(c2da_fresh96)
    c2da_mem[c2da_fp + 9] = uint8(c2da_fresh96 >> 0x8)
    c2da_mem[c2da_fp + 10] = uint8(c2da_fresh96 >> 0x10)
    c2da_mem[c2da_fp + 11] = uint8(c2da_fresh96 >> 0x18)
    y_2 = start
    while (y_2 < end) {
        let c2da_fresh97 : uint = uint(y_2)
        c2da_mem[c2da_fp + 4] = uint8(c2da_fresh97)
        c2da_mem[c2da_fp + 5] = uint8(c2da_fresh97 >> 0x8)
        c2da_mem[c2da_fp + 6] = uint8(c2da_fresh97 >> 0x10)
        c2da_mem[c2da_fp + 7] = uint8(c2da_fresh97 >> 0x18)
        let c2da_fresh98 : uint = uint(y_2)
        c2da_mem[c2da_fp + 12] = uint8(c2da_fresh98)
        c2da_mem[c2da_fp + 13] = uint8(c2da_fresh98 >> 0x8)
        c2da_mem[c2da_fp + 14] = uint8(c2da_fresh98 >> 0x10)
        c2da_mem[c2da_fp + 15] = uint8(c2da_fresh98 >> 0x18)
        AM_drawMline(c2da_fp, color_4)
        y_2 += 128 << 16
    }
    return
}

// This unit's static data, at heap offset 299952.
let private c2da_lin_static_am_map_seg = fixed_array<int>(299988, 8, 300016, 8, 300084, 130)
let private c2da_lin_static_am_map = fixed_array<uint64>(0x616d780000000001ul, 0x616d650000000001ul, 0x700000004ul, 0xc0000000aul, 0xf0000000eul, 0x6c6c6f460000000ful, 0x2065646f4d20776ful, 0x6f6c6c6f46004e4ful, 0x4f2065646f4d2077ul, 0x2064697247004646ul, 0x2064697247004e4ful, 0x252073250046464ful, 0x64656b72614d0064ul, 0x6c4100746f705320ul, 0x20736b72614d206cul, 0x64657261656c43ul, 0x64254d554e4d4d41ul, 0x6425206b63756600ul, 0xd20ul)

[init]
def private c2da_lin_init_static_am_map() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(3)) {
        let at = c2da_lin_static_am_map_seg[s * 2]
        for (k in range(c2da_lin_static_am_map_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_am_map[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_am_map_0 = fixed_array<uint8>(0x69, 0x64, 0x64, 0x74, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_am_map_1 = fixed_array<uint8>(0x0, 0x80, 0xff, 0xff, 0xcd, 0x4c, 0xff, 0xff, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xff, 0xff, 0x33, 0xb3, 0x0, 0x0, 0x0, 0x80, 0xff, 0xff, 0x33, 0xb3, 0x0, 0x0, 0x0, 0x80, 0xff, 0xff, 0xcd, 0x4c, 0xff, 0xff)
let private c2da_lin_extern_am_map_2 = fixed_array<uint8>(0x0, 0x0, 0xf0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x24, 0x49, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x24, 0x49, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x92, 0x24, 0x9, 0x0, 0x30, 0xc, 0x3, 0x0, 0x24, 0x49, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x92, 0x24, 0x9, 0x0, 0xd0, 0xf3, 0xfc, 0xff, 0x0, 0x0, 0xf0, 0xff, 0x0, 0x0, 0x0, 0x0, 0xb8, 0x6d, 0xeb, 0xff, 0x30, 0xc, 0x3, 0x0, 0x0, 0x0, 0xf0, 0xff, 0x0, 0x0, 0x0, 0x0, 0xb8, 0x6d, 0xeb, 0xff, 0xd0, 0xf3, 0xfc, 0xff, 0x49, 0x92, 0xf4, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf0, 0xff, 0x30, 0xc, 0x3, 0x0, 0x49, 0x92, 0xf4, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf0, 0xff, 0xd0, 0xf3, 0xfc, 0xff, 0x6e, 0xdb, 0xf6, 0xff, 0x0, 0x0, 0x0, 0x0, 0x6e, 0xdb, 0xf6, 0xff, 0xd0, 0xf3, 0xfc, 0xff, 0x6e, 0xdb, 0xf6, 0xff, 0xd0, 0xf3, 0xfc, 0xff, 0x9e, 0xe7, 0xf9, 0xff, 0xd0, 0xf3, 0xfc, 0xff, 0x9e, 0xe7, 0xf9, 0xff, 0xd0, 0xf3, 0xfc, 0xff, 0x9e, 0xe7, 0xf9, 0xff, 0x49, 0x92, 0x4, 0x0, 0xd0, 0xf3, 0xfc, 0xff, 0x0, 0x0, 0x0, 0x0, 0xd0, 0xf3, 0xfc, 0xff, 0xd0, 0xf3, 0xfc, 0xff, 0xd0, 0xf3, 0xfc, 0xff, 0xd0, 0xf3, 0xfc, 0xff, 0x0, 0x0, 0x0, 0x0, 0xd0, 0xf3, 0xfc, 0xff, 0x0, 0x0, 0x0, 0x0, 0xd0, 0xf3, 0xfc, 0xff, 0x0, 0x0, 0x0, 0x0, 0x49, 0x92, 0x4, 0x0, 0x30, 0xc, 0x3, 0x0, 0x49, 0x92, 0x4, 0x0, 0x30, 0xc, 0x3, 0x0, 0x44, 0x63, 0xfd, 0xff, 0x30, 0xc, 0x3, 0x0, 0x44, 0x63, 0xfd, 0xff, 0x79, 0x9e, 0x3, 0x0, 0xfb, 0xd0, 0xfc, 0xff, 0x79, 0x9e, 0x3, 0x0, 0xfb, 0xd0, 0xfc, 0xff, 0x4d, 0xe0, 0x4, 0x0, 0x44, 0x63, 0xfd, 0xff)
let private c2da_lin_extern_am_map_3 = fixed_array<uint8>(0x0, 0x0, 0xf0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x24, 0x49, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x24, 0x49, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x92, 0x24, 0x9, 0x0, 0x49, 0x92, 0x4, 0x0, 0x24, 0x49, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x92, 0x24, 0x9, 0x0, 0xb7, 0x6d, 0xfb, 0xff, 0x0, 0x0, 0xf0, 0xff, 0x0, 0x0, 0x0, 0x0, 0xb8, 0x6d, 0xeb, 0xff, 0x49, 0x92, 0x4, 0x0, 0x0, 0x0, 0xf0, 0xff, 0x0, 0x0, 0x0, 0x0, 0xb8, 0x6d, 0xeb, 0xff, 0xb7, 0x6d, 0xfb, 0xff, 0x49, 0x92, 0xf4, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf0, 0xff, 0x49, 0x92, 0x4, 0x0, 0x49, 0x92, 0xf4, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf0, 0xff, 0xb7, 0x6d, 0xfb, 0xff)

[init]
def private c2da_lin_init_externs_am_map() {
    c2da_lin_setup()
    for (i in range(72)) {
        c2da_mem[16 + i] = c2da_lin_extern_am_map_0[i]
    }
    for (i in range(48)) {
        c2da_mem[1408 + i] = c2da_lin_extern_am_map_1[i]
    }
    for (i in range(256)) {
        c2da_mem[1456 + i] = c2da_lin_extern_am_map_2[i]
    }
    for (i in range(112)) {
        c2da_mem[1712 + i] = c2da_lin_extern_am_map_3[i]
    }
}
