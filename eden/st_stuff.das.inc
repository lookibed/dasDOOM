var private ST_updateFaceWidget__lastattackdown : int = -1

var private ST_updateFaceWidget__priority : int = 0

var private ST_calcPainOffset__lastcalc : int = 0

var private ST_calcPainOffset__oldhealth : int = -1

[export, sideeffects]
def ST_Responder(var ev : int) : uint {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : uint = ST_Responder_c2da_frame(ev, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
var private plyr : int = default<int>

var private st_gamestate : uint = default<uint>

var private st_firsttime : uint = default<uint>

[export, sideeffects]
def ST_Ticker() {
    st_clock++
    st_randomnumber = M_Random()
    ST_updateWidgets()
    st_oldhealth = int(uint(c2da_mem[plyr + 44]) | uint(c2da_mem[plyr + 45]) << 0x8 | uint(c2da_mem[plyr + 46]) << 0x10 | uint(c2da_mem[plyr + 47]) << 0x18)
    return
}
var private st_oldhealth : int = -1

[export, sideeffects]
def ST_updateWidgets() {
    var i_0 : int
    if (uint(weaponinfo[int(uint(c2da_mem[plyr + 124]) | uint(c2da_mem[plyr + 125]) << 0x8 | uint(c2da_mem[plyr + 126]) << 0x10 | uint(c2da_mem[plyr + 127]) << 0x18)].ammo) == 5u) {
        let c2da_fresh53 : uint = 371424u
        c2da_mem[371456] = uint8(c2da_fresh53)
        c2da_mem[371457] = uint8(c2da_fresh53 >> 0x8)
        c2da_mem[371458] = uint8(c2da_fresh53 >> 0x10)
        c2da_mem[371459] = uint8(c2da_fresh53 >> 0x18)
        c2da_mem[371460] = 0u8
        c2da_mem[371461] = 0u8
        c2da_mem[371462] = 0u8
        c2da_mem[371463] = 0u8
    } else {
        let c2da_fresh54 : int = plyr + 168 + int(weaponinfo[int(uint(c2da_mem[plyr + 124]) | uint(c2da_mem[plyr + 125]) << 0x8 | uint(c2da_mem[plyr + 126]) << 0x10 | uint(c2da_mem[plyr + 127]) << 0x18)].ammo) * 4
        let c2da_fresh55 : uint = uint(c2da_fresh54)
        c2da_mem[371456] = uint8(c2da_fresh55)
        c2da_mem[371457] = uint8(c2da_fresh55 >> 0x8)
        c2da_mem[371458] = uint8(c2da_fresh55 >> 0x10)
        c2da_mem[371459] = uint8(c2da_fresh55 >> 0x18)
        c2da_mem[371460] = 0u8
        c2da_mem[371461] = 0u8
        c2da_mem[371462] = 0u8
        c2da_mem[371463] = 0u8
    }
    let c2da_fresh56 : int = int(uint(c2da_mem[plyr + 124]) | uint(c2da_mem[plyr + 125]) << 0x8 | uint(c2da_mem[plyr + 126]) << 0x10 | uint(c2da_mem[plyr + 127]) << 0x18)
    let c2da_fresh57 : uint = uint(c2da_fresh56)
    c2da_mem[371480] = uint8(c2da_fresh57)
    c2da_mem[371481] = uint8(c2da_fresh57 >> 0x8)
    c2da_mem[371482] = uint8(c2da_fresh57 >> 0x10)
    c2da_mem[371483] = uint8(c2da_fresh57 >> 0x18)
    i_0 = 0
    while (i_0 < 3) {
        let c2da_fresh58 : int = (uint(c2da_mem[plyr + 80 + i_0 * 4]) | uint(c2da_mem[plyr + 80 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[plyr + 80 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[plyr + 80 + i_0 * 4 + 3]) << 0x18) != 0x0 ? i_0 : -1
        let c2da_fresh59 : uint = uint(c2da_fresh58)
        c2da_mem[373232 + i_0 * 4] = uint8(c2da_fresh59)
        c2da_mem[373232 + i_0 * 4 + 1] = uint8(c2da_fresh59 >> 0x8)
        c2da_mem[373232 + i_0 * 4 + 2] = uint8(c2da_fresh59 >> 0x10)
        c2da_mem[373232 + i_0 * 4 + 3] = uint8(c2da_fresh59 >> 0x18)
        if ((uint(c2da_mem[plyr + 80 + (i_0 + 3) * 4]) | uint(c2da_mem[plyr + 80 + (i_0 + 3) * 4 + 1]) << 0x8 | uint(c2da_mem[plyr + 80 + (i_0 + 3) * 4 + 2]) << 0x10 | uint(c2da_mem[plyr + 80 + (i_0 + 3) * 4 + 3]) << 0x18) != 0x0) {
            let c2da_fresh60 : int = i_0 + 3
            let c2da_fresh61 : uint = uint(c2da_fresh60)
            c2da_mem[373232 + i_0 * 4] = uint8(c2da_fresh61)
            c2da_mem[373232 + i_0 * 4 + 1] = uint8(c2da_fresh61 >> 0x8)
            c2da_mem[373232 + i_0 * 4 + 2] = uint8(c2da_fresh61 >> 0x10)
            c2da_mem[373232 + i_0 * 4 + 3] = uint8(c2da_fresh61 >> 0x18)
        }
        i_0++
    }
    ST_updateFaceWidget()
    let c2da_fresh62 : uint = deathmatch == 0 ? 1u : 0u
    let c2da_fresh63 : uint = c2da_fresh62
    c2da_mem[372672] = uint8(c2da_fresh63)
    c2da_mem[372673] = uint8(c2da_fresh63 >> 0x8)
    c2da_mem[372674] = uint8(c2da_fresh63 >> 0x10)
    c2da_mem[372675] = uint8(c2da_fresh63 >> 0x18)
    let c2da_fresh64 : uint = uint((uint(c2da_mem[372656]) | uint(c2da_mem[372657]) << 0x8 | uint(c2da_mem[372658]) << 0x10 | uint(c2da_mem[372659]) << 0x18) != 0x0 && deathmatch == 0 ? 1 : 0)
    let c2da_fresh65 : uint = c2da_fresh64
    c2da_mem[372784] = uint8(c2da_fresh65)
    c2da_mem[372785] = uint8(c2da_fresh65 >> 0x8)
    c2da_mem[372786] = uint8(c2da_fresh65 >> 0x10)
    c2da_mem[372787] = uint8(c2da_fresh65 >> 0x18)
    let c2da_fresh66 : uint = uint(deathmatch != 0 && (uint(c2da_mem[372656]) | uint(c2da_mem[372657]) << 0x8 | uint(c2da_mem[372658]) << 0x10 | uint(c2da_mem[372659]) << 0x18) != 0x0 ? 1 : 0)
    let c2da_fresh67 : uint = c2da_fresh66
    c2da_mem[372816] = uint8(c2da_fresh67)
    c2da_mem[372817] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[372818] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[372819] = uint8(c2da_fresh67 >> 0x18)
    let c2da_fresh68 : int = 0
    let c2da_fresh69 : uint = uint(c2da_fresh68)
    c2da_mem[372800] = uint8(c2da_fresh69)
    c2da_mem[372801] = uint8(c2da_fresh69 >> 0x8)
    c2da_mem[372802] = uint8(c2da_fresh69 >> 0x10)
    c2da_mem[372803] = uint8(c2da_fresh69 >> 0x18)
    i_0 = 0
    for (c2da_i_0 in range(i_0, 4)) {
        if (c2da_i_0 != consoleplayer) {
            let c2da_fresh70 : int = int(uint(c2da_mem[372800]) | uint(c2da_mem[372801]) << 0x8 | uint(c2da_mem[372802]) << 0x10 | uint(c2da_mem[372803]) << 0x18) + int(uint(c2da_mem[plyr + 108 + c2da_i_0 * 4]) | uint(c2da_mem[plyr + 108 + c2da_i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[plyr + 108 + c2da_i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[plyr + 108 + c2da_i_0 * 4 + 3]) << 0x18)
            let c2da_fresh71 : uint = uint(c2da_fresh70)
            c2da_mem[372800] = uint8(c2da_fresh71)
            c2da_mem[372801] = uint8(c2da_fresh71 >> 0x8)
            c2da_mem[372802] = uint8(c2da_fresh71 >> 0x10)
            c2da_mem[372803] = uint8(c2da_fresh71 >> 0x18)
        } else {
            let c2da_fresh72 : int = int(uint(c2da_mem[372800]) | uint(c2da_mem[372801]) << 0x8 | uint(c2da_mem[372802]) << 0x10 | uint(c2da_mem[372803]) << 0x18) - int(uint(c2da_mem[plyr + 108 + c2da_i_0 * 4]) | uint(c2da_mem[plyr + 108 + c2da_i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[plyr + 108 + c2da_i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[plyr + 108 + c2da_i_0 * 4 + 3]) << 0x18)
            let c2da_fresh73 : uint = uint(c2da_fresh72)
            c2da_mem[372800] = uint8(c2da_fresh73)
            c2da_mem[372801] = uint8(c2da_fresh73 >> 0x8)
            c2da_mem[372802] = uint8(c2da_fresh73 >> 0x10)
            c2da_mem[372803] = uint8(c2da_fresh73 >> 0x18)
        }
    }
    st_msgcounter--
    if (st_msgcounter == 0) {
        st_chat = uint(st_oldchat)  // nolint:PERF020
    }
    return
}
var private st_oldchat : uint = default<uint>

var private st_chat : uint = default<uint>

var private st_msgcounter : int = 0

[export, sideeffects]
def ST_updateFaceWidget() {
    var i_1 : int
    var badguyangle : uint
    var diffang : uint
    var doevilgrin : uint
    if (ST_updateFaceWidget__priority < 10) {
        if (int(uint(c2da_mem[plyr + 44]) | uint(c2da_mem[plyr + 45]) << 0x8 | uint(c2da_mem[plyr + 46]) << 0x10 | uint(c2da_mem[plyr + 47]) << 0x18) == 0) {
            ST_updateFaceWidget__priority = 9
            let c2da_fresh74 : int = 5 * (3 + 2 + 3) + 1
            let c2da_fresh75 : uint = uint(c2da_fresh74)
            c2da_mem[373168] = uint8(c2da_fresh75)
            c2da_mem[373169] = uint8(c2da_fresh75 >> 0x8)
            c2da_mem[373170] = uint8(c2da_fresh75 >> 0x10)
            c2da_mem[373171] = uint8(c2da_fresh75 >> 0x18)
            st_facecount = 1
        }
    }
    if (ST_updateFaceWidget__priority < 9) {
        if (int(uint(c2da_mem[plyr + 244]) | uint(c2da_mem[plyr + 245]) << 0x8 | uint(c2da_mem[plyr + 246]) << 0x10 | uint(c2da_mem[plyr + 247]) << 0x18) != 0) {
            doevilgrin = 0u
            i_1 = 0
            while (i_1 < 9) {
                if (oldweaponsowned[i_1] != (uint(c2da_mem[plyr + 132 + i_1 * 4]) | uint(c2da_mem[plyr + 132 + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[plyr + 132 + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[plyr + 132 + i_1 * 4 + 3]) << 0x18)) {
                    doevilgrin = 1u
                    oldweaponsowned[i_1] = uint(c2da_mem[plyr + 132 + i_1 * 4]) | uint(c2da_mem[plyr + 132 + i_1 * 4 + 1]) << 0x8 | uint(c2da_mem[plyr + 132 + i_1 * 4 + 2]) << 0x10 | uint(c2da_mem[plyr + 132 + i_1 * 4 + 3]) << 0x18
                }
                i_1++
            }
            if (doevilgrin != 0x0) {
                ST_updateFaceWidget__priority = 8
                st_facecount = 2 * 35
                let c2da_fresh76 : int = ST_calcPainOffset() + (3 + 2 + 1)
                let c2da_fresh77 : uint = uint(c2da_fresh76)
                c2da_mem[373168] = uint8(c2da_fresh77)
                c2da_mem[373169] = uint8(c2da_fresh77 >> 0x8)
                c2da_mem[373170] = uint8(c2da_fresh77 >> 0x10)
                c2da_mem[373171] = uint8(c2da_fresh77 >> 0x18)
            }
        }
    }
    if (ST_updateFaceWidget__priority < 8) {
        if (int(uint(c2da_mem[plyr + 240]) | uint(c2da_mem[plyr + 241]) << 0x8 | uint(c2da_mem[plyr + 242]) << 0x10 | uint(c2da_mem[plyr + 243]) << 0x18) != 0 && int(uint(c2da_mem[plyr + 248]) | uint(c2da_mem[plyr + 249]) << 0x8 | uint(c2da_mem[plyr + 250]) << 0x10 | uint(c2da_mem[plyr + 251]) << 0x18) != 0 && int(uint(c2da_mem[plyr + 248]) | uint(c2da_mem[plyr + 249]) << 0x8 | uint(c2da_mem[plyr + 250]) << 0x10 | uint(c2da_mem[plyr + 251]) << 0x18) != int(uint(c2da_mem[plyr]) | uint(c2da_mem[plyr + 1]) << 0x8 | uint(c2da_mem[plyr + 2]) << 0x10 | uint(c2da_mem[plyr + 3]) << 0x18)) {
            ST_updateFaceWidget__priority = 7
            if (int(uint(c2da_mem[plyr + 44]) | uint(c2da_mem[plyr + 45]) << 0x8 | uint(c2da_mem[plyr + 46]) << 0x10 | uint(c2da_mem[plyr + 47]) << 0x18) - st_oldhealth > 20) {
                st_facecount = 1 * 35
                let c2da_fresh78 : int = ST_calcPainOffset() + (3 + 2)
                let c2da_fresh79 : uint = uint(c2da_fresh78)
                c2da_mem[373168] = uint8(c2da_fresh79)
                c2da_mem[373169] = uint8(c2da_fresh79 >> 0x8)
                c2da_mem[373170] = uint8(c2da_fresh79 >> 0x10)
                c2da_mem[373171] = uint8(c2da_fresh79 >> 0x18)
            } else {
                let c2da_fresh80 : int = int(uint(c2da_mem[plyr]) | uint(c2da_mem[plyr + 1]) << 0x8 | uint(c2da_mem[plyr + 2]) << 0x10 | uint(c2da_mem[plyr + 3]) << 0x18) + 24
                let c2da_fresh81 : int = int(uint(c2da_mem[plyr]) | uint(c2da_mem[plyr + 1]) << 0x8 | uint(c2da_mem[plyr + 2]) << 0x10 | uint(c2da_mem[plyr + 3]) << 0x18) + 28
                let c2da_fresh82 : int = int(uint(c2da_mem[plyr + 248]) | uint(c2da_mem[plyr + 249]) << 0x8 | uint(c2da_mem[plyr + 250]) << 0x10 | uint(c2da_mem[plyr + 251]) << 0x18) + 24
                let c2da_fresh83 : int = int(uint(c2da_mem[plyr + 248]) | uint(c2da_mem[plyr + 249]) << 0x8 | uint(c2da_mem[plyr + 250]) << 0x10 | uint(c2da_mem[plyr + 251]) << 0x18) + 28
                badguyangle = uint(R_PointToAngle2(int(uint(c2da_mem[c2da_fresh80]) | uint(c2da_mem[c2da_fresh80 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh80 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh80 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh81]) | uint(c2da_mem[c2da_fresh81 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh81 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh81 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh82]) | uint(c2da_mem[c2da_fresh82 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh82 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh82 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh83]) | uint(c2da_mem[c2da_fresh83 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh83 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh83 + 3]) << 0x18)))
                let c2da_fresh84 : int = int(uint(c2da_mem[plyr]) | uint(c2da_mem[plyr + 1]) << 0x8 | uint(c2da_mem[plyr + 2]) << 0x10 | uint(c2da_mem[plyr + 3]) << 0x18) + 56
                if (badguyangle > (uint(c2da_mem[c2da_fresh84]) | uint(c2da_mem[c2da_fresh84 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh84 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh84 + 3]) << 0x18)) {
                    let c2da_fresh85 : int = int(uint(c2da_mem[plyr]) | uint(c2da_mem[plyr + 1]) << 0x8 | uint(c2da_mem[plyr + 2]) << 0x10 | uint(c2da_mem[plyr + 3]) << 0x18) + 56
                    diffang = badguyangle - (uint(c2da_mem[c2da_fresh85]) | uint(c2da_mem[c2da_fresh85 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh85 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh85 + 3]) << 0x18)
                    i_1 = diffang > 0x80000000u ? 1 : 0
                } else {
                    let c2da_fresh86 : int = int(uint(c2da_mem[plyr]) | uint(c2da_mem[plyr + 1]) << 0x8 | uint(c2da_mem[plyr + 2]) << 0x10 | uint(c2da_mem[plyr + 3]) << 0x18) + 56
                    diffang = (uint(c2da_mem[c2da_fresh86]) | uint(c2da_mem[c2da_fresh86 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh86 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh86 + 3]) << 0x18) - badguyangle
                    i_1 = diffang <= 0x80000000u ? 1 : 0
                }
                st_facecount = 1 * 35
                let c2da_fresh87 : int = ST_calcPainOffset()
                let c2da_fresh88 : uint = uint(c2da_fresh87)
                c2da_mem[373168] = uint8(c2da_fresh88)
                c2da_mem[373169] = uint8(c2da_fresh88 >> 0x8)
                c2da_mem[373170] = uint8(c2da_fresh88 >> 0x10)
                c2da_mem[373171] = uint8(c2da_fresh88 >> 0x18)
                if (diffang < 0x20000000u) {
                    let c2da_fresh89 : int = int(uint(c2da_mem[373168]) | uint(c2da_mem[373169]) << 0x8 | uint(c2da_mem[373170]) << 0x10 | uint(c2da_mem[373171]) << 0x18) + (3 + 2 + 1 + 1)
                    let c2da_fresh90 : uint = uint(c2da_fresh89)
                    c2da_mem[373168] = uint8(c2da_fresh90)
                    c2da_mem[373169] = uint8(c2da_fresh90 >> 0x8)
                    c2da_mem[373170] = uint8(c2da_fresh90 >> 0x10)
                    c2da_mem[373171] = uint8(c2da_fresh90 >> 0x18)
                } elif (i_1 != 0) {
                    let c2da_fresh91 : int = int(uint(c2da_mem[373168]) | uint(c2da_mem[373169]) << 0x8 | uint(c2da_mem[373170]) << 0x10 | uint(c2da_mem[373171]) << 0x18) + 3
                    let c2da_fresh92 : uint = uint(c2da_fresh91)
                    c2da_mem[373168] = uint8(c2da_fresh92)
                    c2da_mem[373169] = uint8(c2da_fresh92 >> 0x8)
                    c2da_mem[373170] = uint8(c2da_fresh92 >> 0x10)
                    c2da_mem[373171] = uint8(c2da_fresh92 >> 0x18)
                } else {
                    let c2da_fresh93 : int = int(uint(c2da_mem[373168]) | uint(c2da_mem[373169]) << 0x8 | uint(c2da_mem[373170]) << 0x10 | uint(c2da_mem[373171]) << 0x18) + (3 + 1)
                    let c2da_fresh94 : uint = uint(c2da_fresh93)
                    c2da_mem[373168] = uint8(c2da_fresh94)
                    c2da_mem[373169] = uint8(c2da_fresh94 >> 0x8)
                    c2da_mem[373170] = uint8(c2da_fresh94 >> 0x10)
                    c2da_mem[373171] = uint8(c2da_fresh94 >> 0x18)
                }
            }
        }
    }
    if (ST_updateFaceWidget__priority < 7) {
        if (int(uint(c2da_mem[plyr + 240]) | uint(c2da_mem[plyr + 241]) << 0x8 | uint(c2da_mem[plyr + 242]) << 0x10 | uint(c2da_mem[plyr + 243]) << 0x18) != 0) {
            if (int(uint(c2da_mem[plyr + 44]) | uint(c2da_mem[plyr + 45]) << 0x8 | uint(c2da_mem[plyr + 46]) << 0x10 | uint(c2da_mem[plyr + 47]) << 0x18) - st_oldhealth > 20) {
                ST_updateFaceWidget__priority = 7
                st_facecount = 1 * 35
                let c2da_fresh95 : int = ST_calcPainOffset() + (3 + 2)
                let c2da_fresh96 : uint = uint(c2da_fresh95)
                c2da_mem[373168] = uint8(c2da_fresh96)
                c2da_mem[373169] = uint8(c2da_fresh96 >> 0x8)
                c2da_mem[373170] = uint8(c2da_fresh96 >> 0x10)
                c2da_mem[373171] = uint8(c2da_fresh96 >> 0x18)
            } else {
                ST_updateFaceWidget__priority = 6
                st_facecount = 1 * 35
                let c2da_fresh97 : int = ST_calcPainOffset() + (3 + 2 + 1 + 1)
                let c2da_fresh98 : uint = uint(c2da_fresh97)
                c2da_mem[373168] = uint8(c2da_fresh98)
                c2da_mem[373169] = uint8(c2da_fresh98 >> 0x8)
                c2da_mem[373170] = uint8(c2da_fresh98 >> 0x10)
                c2da_mem[373171] = uint8(c2da_fresh98 >> 0x18)
            }
        }
    }
    if (ST_updateFaceWidget__priority < 6) {
        if (int(uint(c2da_mem[plyr + 200]) | uint(c2da_mem[plyr + 201]) << 0x8 | uint(c2da_mem[plyr + 202]) << 0x10 | uint(c2da_mem[plyr + 203]) << 0x18) != 0) {
            if (ST_updateFaceWidget__lastattackdown == -1) {
                ST_updateFaceWidget__lastattackdown = 2 * 35
            } else {
                ST_updateFaceWidget__lastattackdown--
                if (ST_updateFaceWidget__lastattackdown == 0) {
                    ST_updateFaceWidget__priority = 5
                    let c2da_fresh99 : int = ST_calcPainOffset() + (3 + 2 + 1 + 1)
                    let c2da_fresh100 : uint = uint(c2da_fresh99)
                    c2da_mem[373168] = uint8(c2da_fresh100)
                    c2da_mem[373169] = uint8(c2da_fresh100 >> 0x8)
                    c2da_mem[373170] = uint8(c2da_fresh100 >> 0x10)
                    c2da_mem[373171] = uint8(c2da_fresh100 >> 0x18)
                    st_facecount = 1
                    ST_updateFaceWidget__lastattackdown = 1
                }
            }
        } else {
            ST_updateFaceWidget__lastattackdown = -1
        }
    }
    if (ST_updateFaceWidget__priority < 5) {
        if ((int(uint(c2da_mem[plyr + 208]) | uint(c2da_mem[plyr + 209]) << 0x8 | uint(c2da_mem[plyr + 210]) << 0x10 | uint(c2da_mem[plyr + 211]) << 0x18) & 2) != 0 || int(uint(c2da_mem[plyr + 56 + 0 * 4]) | uint(c2da_mem[plyr + 56 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[plyr + 56 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[plyr + 56 + 0 * 4 + 3]) << 0x18) != 0) {
            ST_updateFaceWidget__priority = 4
            let c2da_fresh101 : int = 5 * (3 + 2 + 3)
            let c2da_fresh102 : uint = uint(c2da_fresh101)
            c2da_mem[373168] = uint8(c2da_fresh102)
            c2da_mem[373169] = uint8(c2da_fresh102 >> 0x8)
            c2da_mem[373170] = uint8(c2da_fresh102 >> 0x10)
            c2da_mem[373171] = uint8(c2da_fresh102 >> 0x18)
            st_facecount = 1
        }
    }
    if (st_facecount == 0) {
        let c2da_fresh103 : int = ST_calcPainOffset() + st_randomnumber % 3
        let c2da_fresh104 : uint = uint(c2da_fresh103)
        c2da_mem[373168] = uint8(c2da_fresh104)
        c2da_mem[373169] = uint8(c2da_fresh104 >> 0x8)
        c2da_mem[373170] = uint8(c2da_fresh104 >> 0x10)
        c2da_mem[373171] = uint8(c2da_fresh104 >> 0x18)
        st_facecount = 35 / 2
        ST_updateFaceWidget__priority = 0
    }
    st_facecount--
    return
}
var private st_facecount : int = 0

var private st_randomnumber : int = default<int>

[export, sideeffects]
def ST_calcPainOffset() : int {
    var health : int = int(uint(c2da_mem[plyr + 44]) | uint(c2da_mem[plyr + 45]) << 0x8 | uint(c2da_mem[plyr + 46]) << 0x10 | uint(c2da_mem[plyr + 47]) << 0x18) > 100 ? 100 : int(uint(c2da_mem[plyr + 44]) | uint(c2da_mem[plyr + 45]) << 0x8 | uint(c2da_mem[plyr + 46]) << 0x10 | uint(c2da_mem[plyr + 47]) << 0x18)
    if (health != ST_calcPainOffset__oldhealth) {
        ST_calcPainOffset__lastcalc = (3 + 2 + 3) * ((100 - health) * 5 / 101)
        ST_calcPainOffset__oldhealth = health
    }
    return ST_calcPainOffset__lastcalc
}
var private oldweaponsowned : uint[9]

var private st_clock : uint = default<uint>

[export, sideeffects]
def ST_Drawer(var fullscreen : uint; var refresh : uint) {
    let c2da_fresh105 : uint = uint(fullscreen == 0 || automapactive != 0x0 ? 1 : 0)
    let c2da_fresh106 : uint = c2da_fresh105
    c2da_mem[372656] = uint8(c2da_fresh106)
    c2da_mem[372657] = uint8(c2da_fresh106 >> 0x8)
    c2da_mem[372658] = uint8(c2da_fresh106 >> 0x10)
    c2da_mem[372659] = uint8(c2da_fresh106 >> 0x18)
    st_firsttime = uint(st_firsttime != 0x0 || refresh != 0x0 ? 1 : 0)
    ST_doPaletteStuff()
    if (st_firsttime != 0x0) {
        ST_doRefresh()
    } else {
        ST_diffDraw()
    }
    return
}
[export, sideeffects]
def ST_diffDraw() {
    ST_drawWidgets(0u)
    return
}
[export, sideeffects]
def ST_drawWidgets(var refresh_0 : uint) {
    var i_2 : int
    let c2da_fresh107 : uint = uint((uint(c2da_mem[372656]) | uint(c2da_mem[372657]) << 0x8 | uint(c2da_mem[372658]) << 0x10 | uint(c2da_mem[372659]) << 0x18) != 0x0 && deathmatch == 0 ? 1 : 0)
    let c2da_fresh108 : uint = c2da_fresh107
    c2da_mem[372784] = uint8(c2da_fresh108)
    c2da_mem[372785] = uint8(c2da_fresh108 >> 0x8)
    c2da_mem[372786] = uint8(c2da_fresh108 >> 0x10)
    c2da_mem[372787] = uint8(c2da_fresh108 >> 0x18)
    let c2da_fresh109 : uint = uint(deathmatch != 0 && (uint(c2da_mem[372656]) | uint(c2da_mem[372657]) << 0x8 | uint(c2da_mem[372658]) << 0x10 | uint(c2da_mem[372659]) << 0x18) != 0x0 ? 1 : 0)
    let c2da_fresh110 : uint = c2da_fresh109
    c2da_mem[372816] = uint8(c2da_fresh110)
    c2da_mem[372817] = uint8(c2da_fresh110 >> 0x8)
    c2da_mem[372818] = uint8(c2da_fresh110 >> 0x10)
    c2da_mem[372819] = uint8(c2da_fresh110 >> 0x18)
    STlib_updateNum(371440, refresh_0)
    i_2 = 0
    while (i_2 < 4) {
        STlib_updateNum(371488 + i_2 * 48, refresh_0)
        STlib_updateNum(371680 + i_2 * 48, refresh_0)
        i_2++
    }
    STlib_updatePercent(371872, int(refresh_0))
    STlib_updatePercent(371936, int(refresh_0))
    STlib_updateBinIcon(372000, refresh_0)
    i_2 = 0
    while (i_2 < 6) {
        STlib_updateMultIcon(372048 + i_2 * 48, refresh_0)
        i_2++
    }
    STlib_updateMultIcon(372336, refresh_0)
    i_2 = 0
    for (c2da_i_2 in range(i_2, 3)) {
        STlib_updateMultIcon(372384 + c2da_i_2 * 48, refresh_0)
    }
    STlib_updateNum(372528, refresh_0)
    return
}
[export, sideeffects]
def ST_doRefresh() {
    st_firsttime = 0u
    ST_refreshBackground()
    ST_drawWidgets(1u)
    return
}
[export, sideeffects]
def ST_refreshBackground() {
    if ((uint(c2da_mem[372656]) | uint(c2da_mem[372657]) << 0x8 | uint(c2da_mem[372658]) << 0x10 | uint(c2da_mem[372659]) << 0x18) != 0x0) {
        V_UseBuffer(st_backing_screen)
        V_DrawPatch(0, 0, int(uint(c2da_mem[373376]) | uint(c2da_mem[373377]) << 0x8 | uint(c2da_mem[373378]) << 0x10 | uint(c2da_mem[373379]) << 0x18))
        if (netgame != 0x0) {
            V_DrawPatch(143, 0, int(uint(c2da_mem[373360]) | uint(c2da_mem[373361]) << 0x8 | uint(c2da_mem[373362]) << 0x10 | uint(c2da_mem[373363]) << 0x18))
        }
        V_RestoreBuffer()
        V_CopyRect(0, 0, st_backing_screen, 320, 32, 0, 200 - 32)
    }
    return
}
var st_backing_screen : int = default<int>

[export, sideeffects]
def ST_doPaletteStuff() {
    var palette : int
    var pal : int
    var cnt : int
    var bzc : int
    cnt = int(uint(c2da_mem[plyr + 240]) | uint(c2da_mem[plyr + 241]) << 0x8 | uint(c2da_mem[plyr + 242]) << 0x10 | uint(c2da_mem[plyr + 243]) << 0x18)
    if (int(uint(c2da_mem[plyr + 56 + 1 * 4]) | uint(c2da_mem[plyr + 56 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plyr + 56 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plyr + 56 + 1 * 4 + 3]) << 0x18) != 0) {
        bzc = 12 - (int(uint(c2da_mem[plyr + 56 + 1 * 4]) | uint(c2da_mem[plyr + 56 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[plyr + 56 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[plyr + 56 + 1 * 4 + 3]) << 0x18) >> 6)
        if (bzc > cnt) {
            cnt = bzc
        }
    }
    if (cnt != 0) {
        palette = cnt + 7 >> 3
        if (palette >= 8) {
            palette = 8 - 1
        }
        palette++
    } elif (int(uint(c2da_mem[plyr + 244]) | uint(c2da_mem[plyr + 245]) << 0x8 | uint(c2da_mem[plyr + 246]) << 0x10 | uint(c2da_mem[plyr + 247]) << 0x18) != 0) {
        palette = int(uint(c2da_mem[plyr + 244]) | uint(c2da_mem[plyr + 245]) << 0x8 | uint(c2da_mem[plyr + 246]) << 0x10 | uint(c2da_mem[plyr + 247]) << 0x18) + 7 >> 3
        if (palette >= 4) {
            palette = 4 - 1
        }
        palette += 9
    } elif (int(uint(c2da_mem[plyr + 56 + 3 * 4]) | uint(c2da_mem[plyr + 56 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[plyr + 56 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[plyr + 56 + 3 * 4 + 3]) << 0x18) > 4 * 32 || (int(uint(c2da_mem[plyr + 56 + 3 * 4]) | uint(c2da_mem[plyr + 56 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[plyr + 56 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[plyr + 56 + 3 * 4 + 3]) << 0x18) & 8) != 0) {
        palette = 13
    } else {
        palette = 0
    }
    if (uint(gameversion) == 9u && palette >= 1 && palette < 1 + 8) {
        palette = 13
    }
    if (palette != st_palette) {
        st_palette = palette
        pal = W_CacheLumpNum(lu_palette, 8) + palette * 768
        I_SetPalette(pal)
    }
    return
}
var private lu_palette : int = default<int>

var private st_palette : int = 0

[export, sideeffects]
def ST_Start() {
    if (st_stopped == 0) {
        ST_Stop()
    }
    ST_initData()
    ST_createWidgets()
    st_stopped = 0u
    return
}
var private st_stopped : uint = 1u

[export, sideeffects]
def ST_createWidgets() {
    STlib_initNum(371440, 44, 171, 372576, plyr + 168 + int(weaponinfo[int(uint(c2da_mem[plyr + 124]) | uint(c2da_mem[plyr + 125]) << 0x8 | uint(c2da_mem[plyr + 126]) << 0x10 | uint(c2da_mem[plyr + 127]) << 0x18)].ammo) * 4, 372656, 3)
    let c2da_fresh111 : int = int(uint(c2da_mem[plyr + 124]) | uint(c2da_mem[plyr + 125]) << 0x8 | uint(c2da_mem[plyr + 126]) << 0x10 | uint(c2da_mem[plyr + 127]) << 0x18)
    let c2da_fresh112 : uint = uint(c2da_fresh111)
    c2da_mem[371480] = uint8(c2da_fresh112)
    c2da_mem[371481] = uint8(c2da_fresh112 >> 0x8)
    c2da_mem[371482] = uint8(c2da_fresh112 >> 0x10)
    c2da_mem[371483] = uint8(c2da_fresh112 >> 0x18)
    STlib_initPercent(371872, 90, 171, 372576, plyr + 44, 372656, int(uint(c2da_mem[373328]) | uint(c2da_mem[373329]) << 0x8 | uint(c2da_mem[373330]) << 0x10 | uint(c2da_mem[373331]) << 0x18))
    STlib_initBinIcon(372000, 104, 168, int(uint(c2da_mem[373344]) | uint(c2da_mem[373345]) << 0x8 | uint(c2da_mem[373346]) << 0x10 | uint(c2da_mem[373347]) << 0x18), 372672, 372656)
    for (i_3 in range(0, 6)) {
        STlib_initMultIcon(372048 + i_3 * 48, 111 + i_3 % 3 * 12, 172 + i_3 / 3 * 10, 372688 + i_3 * 16, plyr + 132 + (i_3 + 1) * 4, 372784)
    }
    STlib_initNum(372528, 138, 171, 372576, 372800, 372816, 2)
    STlib_initMultIcon(372336, 143, 168, 372832, 373168, 372656)
    STlib_initPercent(371936, 221, 171, 372576, plyr + 48, 372656, int(uint(c2da_mem[373328]) | uint(c2da_mem[373329]) << 0x8 | uint(c2da_mem[373330]) << 0x10 | uint(c2da_mem[373331]) << 0x18))
    STlib_initMultIcon(372384 + 0 * 48, 239, 171, 373184, 373232 + 0 * 4, 372656)
    STlib_initMultIcon(372384 + 1 * 48, 239, 181, 373184, 373232 + 1 * 4, 372656)
    STlib_initMultIcon(372384 + 2 * 48, 239, 191, 373184, 373232 + 2 * 4, 372656)
    STlib_initNum(371488 + 0 * 48, 288, 173, 373248, plyr + 168 + 0 * 4, 372656, 3)
    STlib_initNum(371488 + 1 * 48, 288, 179, 373248, plyr + 168 + 1 * 4, 372656, 3)
    STlib_initNum(371488 + 2 * 48, 288, 191, 373248, plyr + 168 + 2 * 4, 372656, 3)
    STlib_initNum(371488 + 3 * 48, 288, 185, 373248, plyr + 168 + 3 * 4, 372656, 3)
    STlib_initNum(371680 + 0 * 48, 314, 173, 373248, plyr + 184 + 0 * 4, 372656, 3)
    STlib_initNum(371680 + 1 * 48, 314, 179, 373248, plyr + 184 + 1 * 4, 372656, 3)
    STlib_initNum(371680 + 2 * 48, 314, 191, 373248, plyr + 184 + 2 * 4, 372656, 3)
    STlib_initNum(371680 + 3 * 48, 314, 185, 373248, plyr + 184 + 3 * 4, 372656, 3)
    return
}
[export, sideeffects]
def ST_initData() {
    var i_4 : int
    st_firsttime = 1u
    plyr = 96 + int(consoleplayer) * 328
    st_clock = 0u
    st_chatstate = 0u
    st_gamestate = 1u
    let c2da_fresh113 : uint = 1u
    let c2da_fresh114 : uint = c2da_fresh113
    c2da_mem[372656] = uint8(c2da_fresh114)
    c2da_mem[372657] = uint8(c2da_fresh114 >> 0x8)
    c2da_mem[372658] = uint8(c2da_fresh114 >> 0x10)
    c2da_mem[372659] = uint8(c2da_fresh114 >> 0x18)
    st_chat = 0u
    st_oldchat = uint(st_chat)  // nolint:PERF020
    st_cursoron = 0u
    let c2da_fresh115 : int = 0
    let c2da_fresh116 : uint = uint(c2da_fresh115)
    c2da_mem[373168] = uint8(c2da_fresh116)
    c2da_mem[373169] = uint8(c2da_fresh116 >> 0x8)
    c2da_mem[373170] = uint8(c2da_fresh116 >> 0x10)
    c2da_mem[373171] = uint8(c2da_fresh116 >> 0x18)
    st_palette = -1
    st_oldhealth = -1
    i_4 = 0
    while (i_4 < 9) {
        oldweaponsowned[i_4] = uint(c2da_mem[plyr + 132 + i_4 * 4]) | uint(c2da_mem[plyr + 132 + i_4 * 4 + 1]) << 0x8 | uint(c2da_mem[plyr + 132 + i_4 * 4 + 2]) << 0x10 | uint(c2da_mem[plyr + 132 + i_4 * 4 + 3]) << 0x18
        i_4++
    }
    i_4 = 0
    for (c2da_i_4 in range(i_4, 3)) {
        let c2da_fresh117 : int = -1
        let c2da_fresh118 : uint = uint(c2da_fresh117)
        c2da_mem[373232 + c2da_i_4 * 4] = uint8(c2da_fresh118)
        c2da_mem[373232 + c2da_i_4 * 4 + 1] = uint8(c2da_fresh118 >> 0x8)
        c2da_mem[373232 + c2da_i_4 * 4 + 2] = uint8(c2da_fresh118 >> 0x10)
        c2da_mem[373232 + c2da_i_4 * 4 + 3] = uint8(c2da_fresh118 >> 0x18)
    }
    STlib_init()
    return
}
var private st_cursoron : uint = default<uint>

var private st_chatstate : uint = default<uint>

[export, sideeffects]
def ST_Stop() {
    if (st_stopped != 0x0) {
        return
    }
    I_SetPalette(W_CacheLumpNum(lu_palette, 8))
    st_stopped = 1u
    return
}
[export, sideeffects]
def ST_Init() {
    ST_loadData()
    st_backing_screen = Z_Malloc(320 * 32, 1, 0)
    return
}
[export, sideeffects]
def ST_loadData() {
    lu_palette = W_GetNumForName(373677)
    ST_loadGraphics()
    return
}
[export, sideeffects]
def ST_loadGraphics() {
    ST_loadUnloadGraphics(173)
    return
}
[sideeffects]
def private ST_loadCallback(var lumpname : int; var variable : int) {
    let c2da_fresh119 : int = W_CacheLumpName(lumpname, 1)
    let c2da_fresh120 : uint = uint(c2da_fresh119)
    c2da_mem[variable] = uint8(c2da_fresh120)
    c2da_mem[variable + 1] = uint8(c2da_fresh120 >> 0x8)
    c2da_mem[variable + 2] = uint8(c2da_fresh120 >> 0x10)
    c2da_mem[variable + 3] = uint8(c2da_fresh120 >> 0x18)
    c2da_mem[variable + 4] = 0u8
    c2da_mem[variable + 5] = 0u8
    c2da_mem[variable + 6] = 0u8
    c2da_mem[variable + 7] = 0u8
    return
}
[sideeffects]
def private ST_loadUnloadGraphics(var callback : load_callback_t) {
    let c2da_saved_sp : int = c2da_lin_sp
    ST_loadUnloadGraphics_c2da_frame(callback, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private ST_unloadCallback(var lumpname_0 : int; var variable_0 : int) {
    W_ReleaseLumpName(lumpname_0)
    let c2da_fresh123 : uint = 0u
    c2da_mem[variable_0] = uint8(c2da_fresh123)
    c2da_mem[variable_0 + 1] = uint8(c2da_fresh123 >> 0x8)
    c2da_mem[variable_0 + 2] = uint8(c2da_fresh123 >> 0x10)
    c2da_mem[variable_0 + 3] = uint8(c2da_fresh123 >> 0x18)
    c2da_mem[variable_0 + 4] = 0u8
    c2da_mem[variable_0 + 5] = 0u8
    c2da_mem[variable_0 + 6] = 0u8
    c2da_mem[variable_0 + 7] = 0u8
    return
}
[export, sideeffects]
def ST_unloadGraphics() {
    ST_loadUnloadGraphics(174)
    return
}
[export, sideeffects]
def ST_unloadData() {
    ST_unloadGraphics()
    return
}
[sideeffects]
def private ST_Responder_c2da_frame(var ev : int; c2da_fp : int) : uint {
    var c2da_fresh0 : int
    var i : int
    var musnum : int
    var epsd : int
    var map : int
    if ((uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 1u && (uint(int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18)) & 0xffff0000u) == uint((97 << 24) + (109 << 16))) {
        c2da_fresh0 = int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18)
        if (c2da_fresh0 == 1634559232) {
            st_gamestate = 0u
            st_firsttime = 1u
        } elif (c2da_fresh0 == 1634564096) {
            st_gamestate = 1u
        }
    } elif ((uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 0u) {
        if (netgame == 0 && int(gameskill) != 4) {
            if (cht_CheckCheat(254512, int8(int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18))) != 0) {
                let c2da_fresh1 : int = int(uint(c2da_mem[plyr + 208]) | uint(c2da_mem[plyr + 209]) << 0x8 | uint(c2da_mem[plyr + 210]) << 0x10 | uint(c2da_mem[plyr + 211]) << 0x18) ^ 2
                let c2da_fresh2 : uint = uint(c2da_fresh1)
                c2da_mem[plyr + 208] = uint8(c2da_fresh2)
                c2da_mem[plyr + 209] = uint8(c2da_fresh2 >> 0x8)
                c2da_mem[plyr + 210] = uint8(c2da_fresh2 >> 0x10)
                c2da_mem[plyr + 211] = uint8(c2da_fresh2 >> 0x18)
                if ((int(uint(c2da_mem[plyr + 208]) | uint(c2da_mem[plyr + 209]) << 0x8 | uint(c2da_mem[plyr + 210]) << 0x10 | uint(c2da_mem[plyr + 211]) << 0x18) & 2) != 0) {
                    if (int(uint(c2da_mem[plyr]) | uint(c2da_mem[plyr + 1]) << 0x8 | uint(c2da_mem[plyr + 2]) << 0x10 | uint(c2da_mem[plyr + 3]) << 0x18) != 0) {
                        let c2da_fresh3 : int = int(uint(c2da_mem[plyr]) | uint(c2da_mem[plyr + 1]) << 0x8 | uint(c2da_mem[plyr + 2]) << 0x10 | uint(c2da_mem[plyr + 3]) << 0x18) + 164
                        let c2da_fresh4 : int = 100
                        let c2da_fresh5 : uint = uint(c2da_fresh4)
                        c2da_mem[c2da_fresh3] = uint8(c2da_fresh5)
                        c2da_mem[c2da_fresh3 + 1] = uint8(c2da_fresh5 >> 0x8)
                        c2da_mem[c2da_fresh3 + 2] = uint8(c2da_fresh5 >> 0x10)
                        c2da_mem[c2da_fresh3 + 3] = uint8(c2da_fresh5 >> 0x18)
                    }
                    let c2da_fresh6 : int = 100
                    let c2da_fresh7 : uint = uint(c2da_fresh6)
                    c2da_mem[plyr + 44] = uint8(c2da_fresh7)
                    c2da_mem[plyr + 45] = uint8(c2da_fresh7 >> 0x8)
                    c2da_mem[plyr + 46] = uint8(c2da_fresh7 >> 0x10)
                    c2da_mem[plyr + 47] = uint8(c2da_fresh7 >> 0x18)
                    let c2da_fresh8 : uint = 373384u
                    c2da_mem[plyr + 232] = uint8(c2da_fresh8)
                    c2da_mem[plyr + 233] = uint8(c2da_fresh8 >> 0x8)
                    c2da_mem[plyr + 234] = uint8(c2da_fresh8 >> 0x10)
                    c2da_mem[plyr + 235] = uint8(c2da_fresh8 >> 0x18)
                    c2da_mem[plyr + 236] = 0u8
                    c2da_mem[plyr + 237] = 0u8
                    c2da_mem[plyr + 238] = 0u8
                    c2da_mem[plyr + 239] = 0u8
                } else {
                    let c2da_fresh9 : uint = 373407u
                    c2da_mem[plyr + 232] = uint8(c2da_fresh9)
                    c2da_mem[plyr + 233] = uint8(c2da_fresh9 >> 0x8)
                    c2da_mem[plyr + 234] = uint8(c2da_fresh9 >> 0x10)
                    c2da_mem[plyr + 235] = uint8(c2da_fresh9 >> 0x18)
                    c2da_mem[plyr + 236] = 0u8
                    c2da_mem[plyr + 237] = 0u8
                    c2da_mem[plyr + 238] = 0u8
                    c2da_mem[plyr + 239] = 0u8
                }
            } elif (cht_CheckCheat(254592, int8(int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18))) != 0) {
                let c2da_fresh10 : int = 200
                let c2da_fresh11 : uint = uint(c2da_fresh10)
                c2da_mem[plyr + 48] = uint8(c2da_fresh11)
                c2da_mem[plyr + 49] = uint8(c2da_fresh11 >> 0x8)
                c2da_mem[plyr + 50] = uint8(c2da_fresh11 >> 0x10)
                c2da_mem[plyr + 51] = uint8(c2da_fresh11 >> 0x18)
                let c2da_fresh12 : int = 2
                let c2da_fresh13 : uint = uint(c2da_fresh12)
                c2da_mem[plyr + 52] = uint8(c2da_fresh13)
                c2da_mem[plyr + 53] = uint8(c2da_fresh13 >> 0x8)
                c2da_mem[plyr + 54] = uint8(c2da_fresh13 >> 0x10)
                c2da_mem[plyr + 55] = uint8(c2da_fresh13 >> 0x18)
                i = 0
                while (i < 9) {
                    let c2da_fresh14 : uint = 1u
                    let c2da_fresh15 : uint = c2da_fresh14
                    c2da_mem[plyr + 132 + i * 4] = uint8(c2da_fresh15)
                    c2da_mem[plyr + 132 + i * 4 + 1] = uint8(c2da_fresh15 >> 0x8)
                    c2da_mem[plyr + 132 + i * 4 + 2] = uint8(c2da_fresh15 >> 0x10)
                    c2da_mem[plyr + 132 + i * 4 + 3] = uint8(c2da_fresh15 >> 0x18)
                    i++
                }
                i = 0
                while (i < 4) {
                    let c2da_fresh16 : int = int(uint(c2da_mem[plyr + 184 + i * 4]) | uint(c2da_mem[plyr + 184 + i * 4 + 1]) << 0x8 | uint(c2da_mem[plyr + 184 + i * 4 + 2]) << 0x10 | uint(c2da_mem[plyr + 184 + i * 4 + 3]) << 0x18)
                    let c2da_fresh17 : uint = uint(c2da_fresh16)
                    c2da_mem[plyr + 168 + i * 4] = uint8(c2da_fresh17)
                    c2da_mem[plyr + 168 + i * 4 + 1] = uint8(c2da_fresh17 >> 0x8)
                    c2da_mem[plyr + 168 + i * 4 + 2] = uint8(c2da_fresh17 >> 0x10)
                    c2da_mem[plyr + 168 + i * 4 + 3] = uint8(c2da_fresh17 >> 0x18)
                    i++
                }
                let c2da_fresh18 : uint = 373431u
                c2da_mem[plyr + 232] = uint8(c2da_fresh18)
                c2da_mem[plyr + 233] = uint8(c2da_fresh18 >> 0x8)
                c2da_mem[plyr + 234] = uint8(c2da_fresh18 >> 0x10)
                c2da_mem[plyr + 235] = uint8(c2da_fresh18 >> 0x18)
                c2da_mem[plyr + 236] = 0u8
                c2da_mem[plyr + 237] = 0u8
                c2da_mem[plyr + 238] = 0u8
                c2da_mem[plyr + 239] = 0u8
            } elif (cht_CheckCheat(254672, int8(int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18))) != 0) {
                let c2da_fresh19 : int = 200
                let c2da_fresh20 : uint = uint(c2da_fresh19)
                c2da_mem[plyr + 48] = uint8(c2da_fresh20)
                c2da_mem[plyr + 49] = uint8(c2da_fresh20 >> 0x8)
                c2da_mem[plyr + 50] = uint8(c2da_fresh20 >> 0x10)
                c2da_mem[plyr + 51] = uint8(c2da_fresh20 >> 0x18)
                let c2da_fresh21 : int = 2
                let c2da_fresh22 : uint = uint(c2da_fresh21)
                c2da_mem[plyr + 52] = uint8(c2da_fresh22)
                c2da_mem[plyr + 53] = uint8(c2da_fresh22 >> 0x8)
                c2da_mem[plyr + 54] = uint8(c2da_fresh22 >> 0x10)
                c2da_mem[plyr + 55] = uint8(c2da_fresh22 >> 0x18)
                i = 0
                while (i < 9) {
                    let c2da_fresh23 : uint = 1u
                    let c2da_fresh24 : uint = c2da_fresh23
                    c2da_mem[plyr + 132 + i * 4] = uint8(c2da_fresh24)
                    c2da_mem[plyr + 132 + i * 4 + 1] = uint8(c2da_fresh24 >> 0x8)
                    c2da_mem[plyr + 132 + i * 4 + 2] = uint8(c2da_fresh24 >> 0x10)
                    c2da_mem[plyr + 132 + i * 4 + 3] = uint8(c2da_fresh24 >> 0x18)
                    i++
                }
                i = 0
                while (i < 4) {
                    let c2da_fresh25 : int = int(uint(c2da_mem[plyr + 184 + i * 4]) | uint(c2da_mem[plyr + 184 + i * 4 + 1]) << 0x8 | uint(c2da_mem[plyr + 184 + i * 4 + 2]) << 0x10 | uint(c2da_mem[plyr + 184 + i * 4 + 3]) << 0x18)
                    let c2da_fresh26 : uint = uint(c2da_fresh25)
                    c2da_mem[plyr + 168 + i * 4] = uint8(c2da_fresh26)
                    c2da_mem[plyr + 168 + i * 4 + 1] = uint8(c2da_fresh26 >> 0x8)
                    c2da_mem[plyr + 168 + i * 4 + 2] = uint8(c2da_fresh26 >> 0x10)
                    c2da_mem[plyr + 168 + i * 4 + 3] = uint8(c2da_fresh26 >> 0x18)
                    i++
                }
                i = 0
                while (i < 6) {
                    let c2da_fresh27 : uint = 1u
                    let c2da_fresh28 : uint = c2da_fresh27
                    c2da_mem[plyr + 80 + i * 4] = uint8(c2da_fresh28)
                    c2da_mem[plyr + 80 + i * 4 + 1] = uint8(c2da_fresh28 >> 0x8)
                    c2da_mem[plyr + 80 + i * 4 + 2] = uint8(c2da_fresh28 >> 0x10)
                    c2da_mem[plyr + 80 + i * 4 + 3] = uint8(c2da_fresh28 >> 0x18)
                    i++
                }
                let c2da_fresh29 : uint = 373452u
                c2da_mem[plyr + 232] = uint8(c2da_fresh29)
                c2da_mem[plyr + 233] = uint8(c2da_fresh29 >> 0x8)
                c2da_mem[plyr + 234] = uint8(c2da_fresh29 >> 0x10)
                c2da_mem[plyr + 235] = uint8(c2da_fresh29 >> 0x18)
                c2da_mem[plyr + 236] = 0u8
                c2da_mem[plyr + 237] = 0u8
                c2da_mem[plyr + 238] = 0u8
                c2da_mem[plyr + 239] = 0u8
            } elif (cht_CheckCheat(254752, int8(int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18))) != 0) {
                let c2da_fresh30 : uint = 373474u
                c2da_mem[plyr + 232] = uint8(c2da_fresh30)
                c2da_mem[plyr + 233] = uint8(c2da_fresh30 >> 0x8)
                c2da_mem[plyr + 234] = uint8(c2da_fresh30 >> 0x10)
                c2da_mem[plyr + 235] = uint8(c2da_fresh30 >> 0x18)
                c2da_mem[plyr + 236] = 0u8
                c2da_mem[plyr + 237] = 0u8
                c2da_mem[plyr + 238] = 0u8
                c2da_mem[plyr + 239] = 0u8
                cht_GetParam(254752, c2da_fp)
                if (uint(gamemode) == 2u || uint(gameversion) < 6u) {
                    musnum = 33 + (int(int8(c2da_mem[c2da_fp + 0])) - 48) * 10 + int(int8(c2da_mem[c2da_fp + 1])) - 48 - 1
                    if ((int(int8(c2da_mem[c2da_fp + 0])) - 48) * 10 + int(int8(c2da_mem[c2da_fp + 1])) - 48 > 35) {
                        let c2da_fresh31 : uint = 373487u
                        c2da_mem[plyr + 232] = uint8(c2da_fresh31)
                        c2da_mem[plyr + 233] = uint8(c2da_fresh31 >> 0x8)
                        c2da_mem[plyr + 234] = uint8(c2da_fresh31 >> 0x10)
                        c2da_mem[plyr + 235] = uint8(c2da_fresh31 >> 0x18)
                        c2da_mem[plyr + 236] = 0u8
                        c2da_mem[plyr + 237] = 0u8
                        c2da_mem[plyr + 238] = 0u8
                        c2da_mem[plyr + 239] = 0u8
                    } else {
                        S_ChangeMusic(musnum, 1)
                    }
                } else {
                    musnum = 1 + (int(int8(c2da_mem[c2da_fp + 0])) - 49) * 9 + (int(int8(c2da_mem[c2da_fp + 1])) - 49)
                    if ((int(int8(c2da_mem[c2da_fp + 0])) - 49) * 9 + int(int8(c2da_mem[c2da_fp + 1])) - 49 > 31) {
                        let c2da_fresh32 : uint = 373487u
                        c2da_mem[plyr + 232] = uint8(c2da_fresh32)
                        c2da_mem[plyr + 233] = uint8(c2da_fresh32 >> 0x8)
                        c2da_mem[plyr + 234] = uint8(c2da_fresh32 >> 0x10)
                        c2da_mem[plyr + 235] = uint8(c2da_fresh32 >> 0x18)
                        c2da_mem[plyr + 236] = 0u8
                        c2da_mem[plyr + 237] = 0u8
                        c2da_mem[plyr + 238] = 0u8
                        c2da_mem[plyr + 239] = 0u8
                    } else {
                        S_ChangeMusic(musnum, 1)
                    }
                }
            } elif (((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 4u ? 0u : (uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 5u ? 1u : uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 0u && cht_CheckCheat(254832, int8(int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18))) != 0 || ((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 4u ? 0u : (uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 5u ? 1u : uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) != 0u && cht_CheckCheat(254912, int8(int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18))) != 0) {
                let c2da_fresh33 : int = int(uint(c2da_mem[plyr + 208]) | uint(c2da_mem[plyr + 209]) << 0x8 | uint(c2da_mem[plyr + 210]) << 0x10 | uint(c2da_mem[plyr + 211]) << 0x18) ^ 1
                let c2da_fresh34 : uint = uint(c2da_fresh33)
                c2da_mem[plyr + 208] = uint8(c2da_fresh34)
                c2da_mem[plyr + 209] = uint8(c2da_fresh34 >> 0x8)
                c2da_mem[plyr + 210] = uint8(c2da_fresh34 >> 0x10)
                c2da_mem[plyr + 211] = uint8(c2da_fresh34 >> 0x18)
                if ((int(uint(c2da_mem[plyr + 208]) | uint(c2da_mem[plyr + 209]) << 0x8 | uint(c2da_mem[plyr + 210]) << 0x10 | uint(c2da_mem[plyr + 211]) << 0x18) & 1) != 0) {
                    let c2da_fresh35 : uint = 373508u
                    c2da_mem[plyr + 232] = uint8(c2da_fresh35)
                    c2da_mem[plyr + 233] = uint8(c2da_fresh35 >> 0x8)
                    c2da_mem[plyr + 234] = uint8(c2da_fresh35 >> 0x10)
                    c2da_mem[plyr + 235] = uint8(c2da_fresh35 >> 0x18)
                    c2da_mem[plyr + 236] = 0u8
                    c2da_mem[plyr + 237] = 0u8
                    c2da_mem[plyr + 238] = 0u8
                    c2da_mem[plyr + 239] = 0u8
                } else {
                    let c2da_fresh36 : uint = 373528u
                    c2da_mem[plyr + 232] = uint8(c2da_fresh36)
                    c2da_mem[plyr + 233] = uint8(c2da_fresh36 >> 0x8)
                    c2da_mem[plyr + 234] = uint8(c2da_fresh36 >> 0x10)
                    c2da_mem[plyr + 235] = uint8(c2da_fresh36 >> 0x18)
                    c2da_mem[plyr + 236] = 0u8
                    c2da_mem[plyr + 237] = 0u8
                    c2da_mem[plyr + 238] = 0u8
                    c2da_mem[plyr + 239] = 0u8
                }
            }
            i = 0
            for (c2da_i in range(i, 6)) {
                if (cht_CheckCheat(254992 + c2da_i * 72, int8(int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18))) != 0) {
                    if (int(uint(c2da_mem[plyr + 56 + c2da_i * 4]) | uint(c2da_mem[plyr + 56 + c2da_i * 4 + 1]) << 0x8 | uint(c2da_mem[plyr + 56 + c2da_i * 4 + 2]) << 0x10 | uint(c2da_mem[plyr + 56 + c2da_i * 4 + 3]) << 0x18) == 0) {
                        P_GivePower(plyr, c2da_i)
                    } elif (c2da_i != 1) {
                        let c2da_fresh37 : int = 1
                        let c2da_fresh38 : uint = uint(c2da_fresh37)
                        c2da_mem[plyr + 56 + c2da_i * 4] = uint8(c2da_fresh38)
                        c2da_mem[plyr + 56 + c2da_i * 4 + 1] = uint8(c2da_fresh38 >> 0x8)
                        c2da_mem[plyr + 56 + c2da_i * 4 + 2] = uint8(c2da_fresh38 >> 0x10)
                        c2da_mem[plyr + 56 + c2da_i * 4 + 3] = uint8(c2da_fresh38 >> 0x18)
                    } else {
                        let c2da_fresh39 : int = 0
                        let c2da_fresh40 : uint = uint(c2da_fresh39)
                        c2da_mem[plyr + 56 + c2da_i * 4] = uint8(c2da_fresh40)
                        c2da_mem[plyr + 56 + c2da_i * 4 + 1] = uint8(c2da_fresh40 >> 0x8)
                        c2da_mem[plyr + 56 + c2da_i * 4 + 2] = uint8(c2da_fresh40 >> 0x10)
                        c2da_mem[plyr + 56 + c2da_i * 4 + 3] = uint8(c2da_fresh40 >> 0x18)
                    }
                    let c2da_fresh41 : uint = 373549u
                    c2da_mem[plyr + 232] = uint8(c2da_fresh41)
                    c2da_mem[plyr + 233] = uint8(c2da_fresh41 >> 0x8)
                    c2da_mem[plyr + 234] = uint8(c2da_fresh41 >> 0x10)
                    c2da_mem[plyr + 235] = uint8(c2da_fresh41 >> 0x18)
                    c2da_mem[plyr + 236] = 0u8
                    c2da_mem[plyr + 237] = 0u8
                    c2da_mem[plyr + 238] = 0u8
                    c2da_mem[plyr + 239] = 0u8
                }
            }
            if (cht_CheckCheat(254992 + 6 * 72, int8(int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18))) != 0) {
                let c2da_fresh42 : uint = 373566u
                c2da_mem[plyr + 232] = uint8(c2da_fresh42)
                c2da_mem[plyr + 233] = uint8(c2da_fresh42 >> 0x8)
                c2da_mem[plyr + 234] = uint8(c2da_fresh42 >> 0x10)
                c2da_mem[plyr + 235] = uint8(c2da_fresh42 >> 0x18)
                c2da_mem[plyr + 236] = 0u8
                c2da_mem[plyr + 237] = 0u8
                c2da_mem[plyr + 238] = 0u8
                c2da_mem[plyr + 239] = 0u8
            } elif (cht_CheckCheat(255504, int8(int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18))) != 0) {
                let c2da_fresh43 : uint = 1u
                let c2da_fresh44 : uint = c2da_fresh43
                c2da_mem[plyr + 132 + 7 * 4] = uint8(c2da_fresh44)
                c2da_mem[plyr + 132 + 7 * 4 + 1] = uint8(c2da_fresh44 >> 0x8)
                c2da_mem[plyr + 132 + 7 * 4 + 2] = uint8(c2da_fresh44 >> 0x10)
                c2da_mem[plyr + 132 + 7 * 4 + 3] = uint8(c2da_fresh44 >> 0x18)
                let c2da_fresh45 : int = 1
                let c2da_fresh46 : uint = uint(c2da_fresh45)
                c2da_mem[plyr + 56 + 0 * 4] = uint8(c2da_fresh46)
                c2da_mem[plyr + 56 + 0 * 4 + 1] = uint8(c2da_fresh46 >> 0x8)
                c2da_mem[plyr + 56 + 0 * 4 + 2] = uint8(c2da_fresh46 >> 0x10)
                c2da_mem[plyr + 56 + 0 * 4 + 3] = uint8(c2da_fresh46 >> 0x18)
                let c2da_fresh47 : uint = 373612u
                c2da_mem[plyr + 232] = uint8(c2da_fresh47)
                c2da_mem[plyr + 233] = uint8(c2da_fresh47 >> 0x8)
                c2da_mem[plyr + 234] = uint8(c2da_fresh47 >> 0x10)
                c2da_mem[plyr + 235] = uint8(c2da_fresh47 >> 0x18)
                c2da_mem[plyr + 236] = 0u8
                c2da_mem[plyr + 237] = 0u8
                c2da_mem[plyr + 238] = 0u8
                c2da_mem[plyr + 239] = 0u8
            } elif (cht_CheckCheat(255584, int8(int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18))) != 0) {
                let c2da_fresh48 : int = int(uint(c2da_mem[96 + int(consoleplayer) * 328]) | uint(c2da_mem[96 + int(consoleplayer) * 328 + 1]) << 0x8 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 2]) << 0x10 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 3]) << 0x18) + 56
                let c2da_fresh49 : int = int(uint(c2da_mem[96 + int(consoleplayer) * 328]) | uint(c2da_mem[96 + int(consoleplayer) * 328 + 1]) << 0x8 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 2]) << 0x10 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 3]) << 0x18) + 24
                let c2da_fresh50 : int = int(uint(c2da_mem[96 + int(consoleplayer) * 328]) | uint(c2da_mem[96 + int(consoleplayer) * 328 + 1]) << 0x8 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 2]) << 0x10 | uint(c2da_mem[96 + int(consoleplayer) * 328 + 3]) << 0x18) + 28
                M_snprintf(371360, 52ul, 373634, [C2daVaArg(tag = 1, i64 = int64(uint(c2da_mem[c2da_fresh48]) | uint(c2da_mem[c2da_fresh48 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh48 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh48 + 3]) << 0x18), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[c2da_fresh49]) | uint(c2da_mem[c2da_fresh49 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh49 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh49 + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[c2da_fresh50]) | uint(c2da_mem[c2da_fresh50 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh50 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh50 + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
                let c2da_fresh51 : uint = 371360u
                c2da_mem[plyr + 232] = uint8(c2da_fresh51)
                c2da_mem[plyr + 233] = uint8(c2da_fresh51 >> 0x8)
                c2da_mem[plyr + 234] = uint8(c2da_fresh51 >> 0x10)
                c2da_mem[plyr + 235] = uint8(c2da_fresh51 >> 0x18)
                c2da_mem[plyr + 236] = 0u8
                c2da_mem[plyr + 237] = 0u8
                c2da_mem[plyr + 238] = 0u8
                c2da_mem[plyr + 239] = 0u8
            }
        }
        if (netgame == 0 && cht_CheckCheat(255664, int8(int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18))) != 0) {
            cht_GetParam(255664, c2da_fp + 16)
            if (uint(gamemode) == 2u) {
                epsd = 1
                map = (int(int8(c2da_mem[c2da_fp + 16 + 0])) - 48) * 10 + int(int8(c2da_mem[c2da_fp + 16 + 1])) - 48
            } else {
                epsd = int(int8(c2da_mem[c2da_fp + 16 + 0])) - 48
                map = int(int8(c2da_mem[c2da_fp + 16 + 1])) - 48
            }
            if (uint(gameversion) == 9u) {
                epsd = 1
            }
            if (epsd < 1) {
                return 0u
            }
            if (map < 1) {
                return 0u
            }
            if (uint(gamemode) == 3u && (epsd > 4 || map > 9)) {
                return 0u
            }
            if (uint(gamemode) == 1u && (epsd > 3 || map > 9)) {
                return 0u
            }
            if (uint(gamemode) == 0u && (epsd > 1 || map > 9)) {
                return 0u
            }
            if (uint(gamemode) == 2u && (epsd > 1 || map > 40)) {
                return 0u
            }
            let c2da_fresh52 : uint = 373659u
            c2da_mem[plyr + 232] = uint8(c2da_fresh52)
            c2da_mem[plyr + 233] = uint8(c2da_fresh52 >> 0x8)
            c2da_mem[plyr + 234] = uint8(c2da_fresh52 >> 0x10)
            c2da_mem[plyr + 235] = uint8(c2da_fresh52 >> 0x18)
            c2da_mem[plyr + 236] = 0u8
            c2da_mem[plyr + 237] = 0u8
            c2da_mem[plyr + 238] = 0u8
            c2da_mem[plyr + 239] = 0u8
            G_DeferedInitNew(gameskill, epsd, map)
        }
    }
    return 0u
}
[sideeffects]
def private ST_loadUnloadGraphics_c2da_frame(var callback : load_callback_t; c2da_fp : int) {
    var i_5 : int
    var facenum : int
    i_5 = 0
    while (i_5 < 10) {
        c2da_lin_snprintf(c2da_fp, 9ul, 373685, [C2daVaArg(tag = 1, i64 = int64(i_5), f64 = 0.0lf, raw = 0x0)])
        invoke(c2da_fn_table1[callback], c2da_fp, 372576 + i_5 * 8)
        c2da_lin_snprintf(c2da_fp, 9ul, 373694, [C2daVaArg(tag = 1, i64 = int64(i_5), f64 = 0.0lf, raw = 0x0)])
        invoke(c2da_fn_table1[callback], c2da_fp, 373248 + i_5 * 8)
        i_5++
    }
    invoke(c2da_fn_table1[callback], 373704, 373328)
    i_5 = 0
    while (i_5 < 6) {
        c2da_lin_snprintf(c2da_fp, 9ul, 373713, [C2daVaArg(tag = 1, i64 = int64(i_5), f64 = 0.0lf, raw = 0x0)])
        invoke(c2da_fn_table1[callback], c2da_fp, 373184 + i_5 * 8)
        i_5++
    }
    invoke(c2da_fn_table1[callback], 373722, 373344)
    i_5 = 0
    while (i_5 < 6) {
        c2da_lin_snprintf(c2da_fp, 9ul, 373729, [C2daVaArg(tag = 1, i64 = int64(i_5 + 2), f64 = 0.0lf, raw = 0x0)])
        invoke(c2da_fn_table1[callback], c2da_fp, 372688 + i_5 * 16 + 0 * 8)
        let c2da_fresh121 : int = int(uint(c2da_mem[373248 + (i_5 + 2) * 8]) | uint(c2da_mem[373248 + (i_5 + 2) * 8 + 1]) << 0x8 | uint(c2da_mem[373248 + (i_5 + 2) * 8 + 2]) << 0x10 | uint(c2da_mem[373248 + (i_5 + 2) * 8 + 3]) << 0x18)
        let c2da_fresh122 : uint = uint(c2da_fresh121)
        c2da_mem[372688 + i_5 * 16 + 1 * 8] = uint8(c2da_fresh122)
        c2da_mem[372688 + i_5 * 16 + 1 * 8 + 1] = uint8(c2da_fresh122 >> 0x8)
        c2da_mem[372688 + i_5 * 16 + 1 * 8 + 2] = uint8(c2da_fresh122 >> 0x10)
        c2da_mem[372688 + i_5 * 16 + 1 * 8 + 3] = uint8(c2da_fresh122 >> 0x18)
        c2da_mem[372688 + i_5 * 16 + 1 * 8 + 4] = 0u8
        c2da_mem[372688 + i_5 * 16 + 1 * 8 + 5] = 0u8
        c2da_mem[372688 + i_5 * 16 + 1 * 8 + 6] = 0u8
        c2da_mem[372688 + i_5 * 16 + 1 * 8 + 7] = 0u8
        i_5++
    }
    c2da_lin_snprintf(c2da_fp, 9ul, 373738, [C2daVaArg(tag = 1, i64 = int64(consoleplayer), f64 = 0.0lf, raw = 0x0)])
    invoke(c2da_fn_table1[callback], c2da_fp, 373360)
    invoke(c2da_fn_table1[callback], 373745, 373376)
    facenum = 0
    i_5 = 0
    for (c2da_i_5 in range(i_5, 5)) {
        for (j in range(0, 3)) {
            c2da_lin_snprintf(c2da_fp, 9ul, 373751, [C2daVaArg(tag = 1, i64 = int64(c2da_i_5), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(j), f64 = 0.0lf, raw = 0x0)])
            invoke(c2da_fn_table1[callback], c2da_fp, 372832 + facenum * 8)
            facenum++
        }
        c2da_lin_snprintf(c2da_fp, 9ul, 373761, [C2daVaArg(tag = 1, i64 = int64(c2da_i_5), f64 = 0.0lf, raw = 0x0)])
        invoke(c2da_fn_table1[callback], c2da_fp, 372832 + facenum * 8)
        facenum++
        c2da_lin_snprintf(c2da_fp, 9ul, 373770, [C2daVaArg(tag = 1, i64 = int64(c2da_i_5), f64 = 0.0lf, raw = 0x0)])
        invoke(c2da_fn_table1[callback], c2da_fp, 372832 + facenum * 8)
        facenum++
        c2da_lin_snprintf(c2da_fp, 9ul, 373779, [C2daVaArg(tag = 1, i64 = int64(c2da_i_5), f64 = 0.0lf, raw = 0x0)])
        invoke(c2da_fn_table1[callback], c2da_fp, 372832 + facenum * 8)
        facenum++
        c2da_lin_snprintf(c2da_fp, 9ul, 373789, [C2daVaArg(tag = 1, i64 = int64(c2da_i_5), f64 = 0.0lf, raw = 0x0)])
        invoke(c2da_fn_table1[callback], c2da_fp, 372832 + facenum * 8)
        facenum++
        c2da_lin_snprintf(c2da_fp, 9ul, 373798, [C2daVaArg(tag = 1, i64 = int64(c2da_i_5), f64 = 0.0lf, raw = 0x0)])
        invoke(c2da_fn_table1[callback], c2da_fp, 372832 + facenum * 8)
        facenum++
    }
    invoke(c2da_fn_table1[callback], 373808, 372832 + facenum * 8)
    facenum++
    invoke(c2da_fn_table1[callback], 373816, 372832 + facenum * 8)
    facenum++
    return
}

// This unit's static data, at heap offset 371360.
let private c2da_lin_static_st_stuff_seg = fixed_array<int>(371424, 2, 373384, 440)
let private c2da_lin_static_st_stuff = fixed_array<uint64>(0x65657267654407caul, 0x7373656e7373656cul, 0x6e4f2065646f4d20ul, 0x6c65657267654400ul, 0x207373656e737365ul, 0x66664f2065646f4dul, 0x6e28206f6d6d4100ul, 0x20297379656b206ful, 0x6556006465646441ul, 0x7970706148207972ul, 0x6441206f6d6d4120ul, 0x6973754d00646564ul, 0x65676e6168432063ul, 0x4953534f504d4900ul, 0x454c455320454c42ul, 0x6f4e004e4f495443ul, 0x6e697070696c4320ul, 0x4f2065646f4d2067ul, 0x696c43206f4e004eul, 0x6f4d20676e697070ul, 0x500046464f206564ul, 0x2070752d7265776ful, 0x64656c67676f54ul, 0x202c6e6c75566e69ul, 0x766e49202c727453ul, 0x646152202c6f7369ul, 0x70616d6c6c41202cul, 0x74694c20726f202cul, 0x2e2e00706d612d65ul, 0x276e73656f64202eul, 0x2d206b6375732074ul, 0x3d676e61004d4720ul, 0x792c783b78257830ul, 0x302c78257830283dul, 0x6168430029782578ul, 0x654c20676e69676eul, 0x50002e2e2e6c6576ul, 0x53004c415059414cul, 0x64254d554e5454ul, 0x254d554e53595453ul, 0x4352505454530064ul, 0x59454b545300544eul, 0x5241545300642553ul, 0x554e47545300534dul, 0x424654530064254dul, 0x5241425453006425ul, 0x6425545346545300ul, 0x5254465453006425ul, 0x5446545300306425ul, 0x465453003064254cul, 0x530064254843554ful, 0x64254c56454654ul, 0x254c4c494b465453ul, 0x444f474654530064ul, 0x4145444654530030ul, 0x3044ul)

[init]
def private c2da_lin_init_static_st_stuff() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(2)) {
        let at = c2da_lin_static_st_stuff_seg[s * 2]
        for (k in range(c2da_lin_static_st_stuff_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_st_stuff[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_st_stuff_0 = fixed_array<uint8>(0x69, 0x64, 0x64, 0x71, 0x64, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_st_stuff_1 = fixed_array<uint8>(0x69, 0x64, 0x66, 0x61, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_st_stuff_2 = fixed_array<uint8>(0x69, 0x64, 0x6b, 0x66, 0x61, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_st_stuff_3 = fixed_array<uint8>(0x69, 0x64, 0x6d, 0x75, 0x73, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_st_stuff_4 = fixed_array<uint8>(0x69, 0x64, 0x73, 0x70, 0x69, 0x73, 0x70, 0x6f, 0x70, 0x64, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_st_stuff_5 = fixed_array<uint8>(0x69, 0x64, 0x63, 0x6c, 0x69, 0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_st_stuff_6 = fixed_array<uint8>(0x69, 0x64, 0x62, 0x65, 0x68, 0x6f, 0x6c, 0x64, 0x76, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x69, 0x64, 0x62, 0x65, 0x68, 0x6f, 0x6c, 0x64, 0x73, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x69, 0x64, 0x62, 0x65, 0x68, 0x6f, 0x6c, 0x64, 0x69, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x69, 0x64, 0x62, 0x65, 0x68, 0x6f, 0x6c, 0x64, 0x72, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x69, 0x64, 0x62, 0x65, 0x68, 0x6f, 0x6c, 0x64, 0x61, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x69, 0x64, 0x62, 0x65, 0x68, 0x6f, 0x6c, 0x64, 0x6c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x69, 0x64, 0x62, 0x65, 0x68, 0x6f, 0x6c, 0x64, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_st_stuff_7 = fixed_array<uint8>(0x69, 0x64, 0x63, 0x68, 0x6f, 0x70, 0x70, 0x65, 0x72, 0x73, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_st_stuff_8 = fixed_array<uint8>(0x69, 0x64, 0x6d, 0x79, 0x70, 0x6f, 0x73, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_st_stuff_9 = fixed_array<uint8>(0x69, 0x64, 0x63, 0x6c, 0x65, 0x76, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_st_stuff() {
    c2da_lin_setup()
    for (i in range(72)) {
        c2da_mem[254512 + i] = c2da_lin_extern_st_stuff_0[i]
    }
    for (i in range(72)) {
        c2da_mem[254592 + i] = c2da_lin_extern_st_stuff_1[i]
    }
    for (i in range(72)) {
        c2da_mem[254672 + i] = c2da_lin_extern_st_stuff_2[i]
    }
    for (i in range(72)) {
        c2da_mem[254752 + i] = c2da_lin_extern_st_stuff_3[i]
    }
    for (i in range(72)) {
        c2da_mem[254832 + i] = c2da_lin_extern_st_stuff_4[i]
    }
    for (i in range(72)) {
        c2da_mem[254912 + i] = c2da_lin_extern_st_stuff_5[i]
    }
    for (i in range(504)) {
        c2da_mem[254992 + i] = c2da_lin_extern_st_stuff_6[i]
    }
    for (i in range(72)) {
        c2da_mem[255504 + i] = c2da_lin_extern_st_stuff_7[i]
    }
    for (i in range(72)) {
        c2da_mem[255584 + i] = c2da_lin_extern_st_stuff_8[i]
    }
    for (i in range(72)) {
        c2da_mem[255664 + i] = c2da_lin_extern_st_stuff_9[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_st_stuff() {
    if (length(c2da_fn_table1) < 175) {
        resize(c2da_fn_table1, 175)
    }
    c2da_fn_table1[173] = @@ST_loadCallback
    c2da_fn_table1[174] = @@ST_unloadCallback
}

[init]
def private c2da_lin_relink_init_st_stuff() {
    c2da_relink_st_stuff()
}
