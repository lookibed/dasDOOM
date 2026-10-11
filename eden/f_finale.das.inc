var private F_BunnyScroll__laststage : int = 0

var finalestage : uint = default<uint>

var finalecount : uint = default<uint>

var finaletext : int = default<int>

var finaleflat : int = default<int>

[export, sideeffects]
def F_StartCast() {
    wipegamestate = 4294967295u
    castnum = 0
    let c2da_fresh0 : int = 51056 + int(castorder[castnum].type_0) * 92 + 12
    caststate = 2080 + int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18) * 40
    casttics = int(uint(c2da_mem[caststate + 8]) | uint(c2da_mem[caststate + 9]) << 0x8 | uint(c2da_mem[caststate + 10]) << 0x10 | uint(c2da_mem[caststate + 11]) << 0x18)
    castdeath = 0u
    finalestage = 2u
    castframes = 0
    castonmelee = 0
    castattacking = 0u
    S_ChangeMusic(63, 1)
    return
}
var castattacking : uint = default<uint>

var castonmelee : int = default<int>

var castframes : int = default<int>

var castdeath : uint = default<uint>

var caststate : int = default<int>

var casttics : int = default<int>

var castnum : int = default<int>

var castorder : castinfo_t[18] = fixed_array<castinfo_t>(castinfo_t(name = 337078, type_0 = 1u), castinfo_t(name = 337088, type_0 = 2u), castinfo_t(name = 337100, type_0 = 10u), castinfo_t(name = 337118, type_0 = 11u), castinfo_t(name = 337122, type_0 = 12u), castinfo_t(name = 337128, type_0 = 18u), castinfo_t(name = 337138, type_0 = 14u), castinfo_t(name = 337148, type_0 = 17u), castinfo_t(name = 337160, type_0 = 15u), castinfo_t(name = 337174, type_0 = 20u), castinfo_t(name = 337186, type_0 = 22u), castinfo_t(name = 337201, type_0 = 5u), castinfo_t(name = 337210, type_0 = 8u), castinfo_t(name = 337219, type_0 = 3u), castinfo_t(name = 337229, type_0 = 19u), castinfo_t(name = 337251, type_0 = 21u), castinfo_t(name = 337266, type_0 = 0u), castinfo_t(name = 0, type_0 = 0u))

[export, sideeffects]
def F_CastTicker() {
    var st : int
    var sfx : int
    var c2da_fresh9 : int
    casttics--
    if (casttics > 0) {
        return
    }
    if (int(uint(c2da_mem[caststate + 8]) | uint(c2da_mem[caststate + 9]) << 0x8 | uint(c2da_mem[caststate + 10]) << 0x10 | uint(c2da_mem[caststate + 11]) << 0x18) == -1 || (uint(c2da_mem[caststate + 24]) | uint(c2da_mem[caststate + 25]) << 0x8 | uint(c2da_mem[caststate + 26]) << 0x10 | uint(c2da_mem[caststate + 27]) << 0x18) == 0u) {
        goto label 46
    }
    if (caststate == 2080 + 154 * 40) {
        goto label 45
    }
    st = int(uint(c2da_mem[caststate + 24]) | uint(c2da_mem[caststate + 25]) << 0x8 | uint(c2da_mem[caststate + 26]) << 0x10 | uint(c2da_mem[caststate + 27]) << 0x18)
    caststate = 2080 + st * 40
    castframes++
    if (st < 454) {
        if (st < 340) {
            if (st < 256) {
                if (st == 154) {
                    goto label 19
                } elif (st == 185) {
                    goto label 20
                } elif (st == 218) {
                    goto label 21
                }
            } else {
                if (st == 256) {
                    goto label 22
                } elif (st == 336) {
                    goto label 23
                } elif (st == 338) {
                    goto label 24
                }
            }
        } else {
            if (st < 383) {
                if (st == 340) {
                    goto label 25
                } elif (st == 377) {
                    goto label 28
                } elif (st == 380) {
                    goto label 27
                }
            } else {
                if (st == 383) {
                    goto label 26
                } elif (st == 417) {
                    goto label 29
                } elif (st == 418) {
                    goto label 30
                } elif (st == 419) {
                    goto label 31
                }
            }
        }
    } else {
        if (st < 616) {
            if (st < 538) {
                if (st == 454) {
                    goto label 32
                } elif (st == 486) {
                    goto label 33
                } elif (st == 505) {
                    goto label 36
                }
            } else {
                if (st == 538) {
                    goto label 34
                } elif (st == 567) {
                    goto label 35
                } elif (st == 590) {
                    goto label 37
                }
            }
        } else {
            if (st < 685) {
                if (st == 616) {
                    goto label 38
                } elif (st == 617) {
                    goto label 39
                } elif (st == 648) {
                    goto label 40
                }
            } else {
                if (st == 685) {
                    goto label 41
                } elif (st == 687) {
                    goto label 42
                } elif (st == 689) {
                    goto label 43
                } elif (st == 710) {
                    goto label 44
                }
            }
        }
    }
    sfx = 0
    label 0:
    if (sfx != 0) {
        goto label 18
    }
    label 1:
    label 2:
    if (castframes == 12) {
        goto label 11
    }
    label 3:
    if (castattacking != 0x0) {
        goto label 7
    }
    label 4:
    casttics = int(uint(c2da_mem[caststate + 8]) | uint(c2da_mem[caststate + 9]) << 0x8 | uint(c2da_mem[caststate + 10]) << 0x10 | uint(c2da_mem[caststate + 11]) << 0x18)
    if (casttics == -1) {
        goto label 6
    }
    label 5:
    return
    label 6:
    casttics = 15
    goto label 5
    label 7:
    c2da_fresh9 = 1
    if (!(castframes == 24)) {
        let c2da_fresh8 : int = 51056 + int(castorder[castnum].type_0) * 92 + 12
        if (!(caststate == 2080 + int(uint(c2da_mem[c2da_fresh8]) | uint(c2da_mem[c2da_fresh8 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh8 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh8 + 3]) << 0x18) * 40)) {
            c2da_fresh9 = 0
        }
    }
    if (c2da_fresh9 != 0) {
        goto label 9
    }
    label 8:
    goto label 4
    label 9:
    label 10:
    castattacking = 0u
    castframes = 0
    let c2da_fresh10 : int = 51056 + int(castorder[castnum].type_0) * 92 + 12
    caststate = 2080 + int(uint(c2da_mem[c2da_fresh10]) | uint(c2da_mem[c2da_fresh10 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh10 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh10 + 3]) << 0x18) * 40
    goto label 8
    label 11:
    castattacking = 1u
    if (castonmelee != 0) {
        goto label 17
    }
    let c2da_fresh5 : int = 51056 + int(castorder[castnum].type_0) * 92 + 44
    caststate = 2080 + int(uint(c2da_mem[c2da_fresh5]) | uint(c2da_mem[c2da_fresh5 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh5 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh5 + 3]) << 0x18) * 40
    label 12:
    castonmelee ^= 1
    if (caststate == 2080 + 0 * 40) {
        goto label 14
    }
    label 13:
    goto label 3
    label 14:
    if (castonmelee != 0) {
        goto label 16
    }
    let c2da_fresh7 : int = 51056 + int(castorder[castnum].type_0) * 92 + 44
    caststate = 2080 + int(uint(c2da_mem[c2da_fresh7]) | uint(c2da_mem[c2da_fresh7 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh7 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh7 + 3]) << 0x18) * 40
    label 15:
    goto label 13
    label 16:
    let c2da_fresh6 : int = 51056 + int(castorder[castnum].type_0) * 92 + 40
    caststate = 2080 + int(uint(c2da_mem[c2da_fresh6]) | uint(c2da_mem[c2da_fresh6 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh6 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh6 + 3]) << 0x18) * 40
    goto label 15
    label 17:
    let c2da_fresh4 : int = 51056 + int(castorder[castnum].type_0) * 92 + 40
    caststate = 2080 + int(uint(c2da_mem[c2da_fresh4]) | uint(c2da_mem[c2da_fresh4 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh4 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh4 + 3]) << 0x18) * 40
    goto label 12
    label 18:
    S_StartSound(0, sfx)
    goto label 1
    label 19:
    sfx = 4
    goto label 0
    label 20:
    sfx = 1
    goto label 0
    label 21:
    sfx = 2
    goto label 0
    label 22:
    sfx = 54
    goto label 0
    label 23:
    sfx = 56
    goto label 0
    label 24:
    sfx = 53
    goto label 0
    label 25:
    sfx = 107
    goto label 0
    label 26:
    label 27:
    label 28:
    sfx = 16
    goto label 0
    label 29:
    label 30:
    label 31:
    sfx = 2
    goto label 0
    label 32:
    sfx = 55
    goto label 0
    label 33:
    sfx = 52
    goto label 0
    label 34:
    label 35:
    label 36:
    sfx = 16
    goto label 0
    label 37:
    sfx = 51
    goto label 0
    label 38:
    label 39:
    sfx = 2
    goto label 0
    label 40:
    sfx = 8
    goto label 0
    label 41:
    label 42:
    label 43:
    sfx = 14
    goto label 0
    label 44:
    sfx = 51
    goto label 0
    label 45:
    goto label 10
    label 46:
    castnum++
    castdeath = 0u
    if (castorder[castnum].name == 0) {
        goto label 50
    }
    label 47:
    let c2da_fresh1 : int = 51056 + int(castorder[castnum].type_0) * 92 + 16
    if (int(uint(c2da_mem[c2da_fresh1]) | uint(c2da_mem[c2da_fresh1 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh1 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh1 + 3]) << 0x18) != 0) {
        goto label 49
    }
    label 48:
    let c2da_fresh3 : int = 51056 + int(castorder[castnum].type_0) * 92 + 12
    caststate = 2080 + int(uint(c2da_mem[c2da_fresh3]) | uint(c2da_mem[c2da_fresh3 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh3 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh3 + 3]) << 0x18) * 40
    castframes = 0
    goto label 2
    label 49:
    let c2da_fresh2 : int = 51056 + int(castorder[castnum].type_0) * 92 + 16
    S_StartSound(0, int(uint(c2da_mem[c2da_fresh2]) | uint(c2da_mem[c2da_fresh2 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh2 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh2 + 3]) << 0x18))
    goto label 48
    label 50:
    castnum = 0
    goto label 47
    return
}
[export, sideeffects]
def F_CastResponder(var ev : int) : uint {
    if ((uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) != 0u) {
        return 0u
    }
    if (castdeath != 0x0) {
        return 1u
    }
    castdeath = 1u
    let c2da_fresh11 : int = 51056 + int(castorder[castnum].type_0) * 92 + 48
    caststate = 2080 + int(uint(c2da_mem[c2da_fresh11]) | uint(c2da_mem[c2da_fresh11 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh11 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh11 + 3]) << 0x18) * 40
    casttics = int(uint(c2da_mem[caststate + 8]) | uint(c2da_mem[caststate + 9]) << 0x8 | uint(c2da_mem[caststate + 10]) << 0x10 | uint(c2da_mem[caststate + 11]) << 0x18)
    castframes = 0
    castattacking = 0u
    let c2da_fresh12 : int = 51056 + int(castorder[castnum].type_0) * 92 + 56
    if (int(uint(c2da_mem[c2da_fresh12]) | uint(c2da_mem[c2da_fresh12 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh12 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh12 + 3]) << 0x18) != 0) {
        let c2da_fresh13 : int = 51056 + int(castorder[castnum].type_0) * 92 + 56
        S_StartSound(0, int(uint(c2da_mem[c2da_fresh13]) | uint(c2da_mem[c2da_fresh13 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh13 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh13 + 3]) << 0x18))
    }
    return 1u
}
[export, sideeffects]
def F_CastDrawer() {
    var sprdef : int
    var sprframe : int
    var lump : int
    var flip : uint
    var patch : int
    V_DrawPatch(0, 0, W_CacheLumpName(337275, 8))
    F_CastPrint(castorder[castnum].name)
    sprdef = sprites + int(uint(c2da_mem[caststate]) | uint(c2da_mem[caststate + 1]) << 0x8 | uint(c2da_mem[caststate + 2]) << 0x10 | uint(c2da_mem[caststate + 3]) << 0x18) * 16
    sprframe = int(uint(c2da_mem[sprdef + 8]) | uint(c2da_mem[sprdef + 9]) << 0x8 | uint(c2da_mem[sprdef + 10]) << 0x10 | uint(c2da_mem[sprdef + 11]) << 0x18) + (int(uint(c2da_mem[caststate + 4]) | uint(c2da_mem[caststate + 5]) << 0x8 | uint(c2da_mem[caststate + 6]) << 0x10 | uint(c2da_mem[caststate + 7]) << 0x18) & 32767) * 28
    lump = int(int16(uint(c2da_mem[sprframe + 4 + 0 * 2]) | uint(c2da_mem[sprframe + 4 + 0 * 2 + 1]) << 0x8))
    flip = uint(c2da_mem[sprframe + 20 + 0])
    patch = W_CacheLumpNum(lump + firstspritelump, 8)
    if (flip != 0x0) {
        V_DrawPatchFlipped(160, 170, patch)
    } else {
        V_DrawPatch(160, 170, patch)
    }
    return
}
[export, sideeffects]
def F_CastPrint(var text : int) {
    var ch : int
    var c : int
    var cx : int
    var w : int
    var width : int
    ch = text
    width = 0
    while (ch != 0) {
        let c2da_fresh14 : int = ch
        ch++
        c = int(int8(c2da_mem[c2da_fresh14]))
        if (c == 0) {
            break
        }
        c = c2da_std_toupper(c) - 33
        if (c < 0 || c > 95 - 33 + 1) {
            width += 4
            continue
        }
        let c2da_fresh15 : int = int(uint(c2da_mem[41520 + c * 8]) | uint(c2da_mem[41520 + c * 8 + 1]) << 0x8 | uint(c2da_mem[41520 + c * 8 + 2]) << 0x10 | uint(c2da_mem[41520 + c * 8 + 3]) << 0x18)
        w = int(int16(uint(c2da_mem[c2da_fresh15]) | uint(c2da_mem[c2da_fresh15 + 1]) << 0x8))
        width += w
    }
    cx = 160 - width / 2
    ch = text
    while (ch != 0) {
        let c2da_fresh16 : int = ch
        ch++
        c = int(int8(c2da_mem[c2da_fresh16]))
        if (c == 0) {
            break
        }
        c = c2da_std_toupper(c) - 33
        if (c < 0 || c > 95 - 33 + 1) {
            cx += 4
            continue
        }
        let c2da_fresh17 : int = int(uint(c2da_mem[41520 + c * 8]) | uint(c2da_mem[41520 + c * 8 + 1]) << 0x8 | uint(c2da_mem[41520 + c * 8 + 2]) << 0x10 | uint(c2da_mem[41520 + c * 8 + 3]) << 0x18)
        w = int(int16(uint(c2da_mem[c2da_fresh17]) | uint(c2da_mem[c2da_fresh17 + 1]) << 0x8))
        V_DrawPatch(cx, 180, int(uint(c2da_mem[41520 + c * 8]) | uint(c2da_mem[41520 + c * 8 + 1]) << 0x8 | uint(c2da_mem[41520 + c * 8 + 2]) << 0x10 | uint(c2da_mem[41520 + c * 8 + 3]) << 0x18))
        cx += w
    }
    return
}
[export, sideeffects]
def F_StartFinale() {
    var i : uint64
    var screen : int
    gameaction = 0u
    gamestate = 2u
    viewactive = 0u
    automapactive = 0u
    if (((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 4u ? 0u : (uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 5u ? 1u : uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 0u) {
        S_ChangeMusic(31, 1)
    } else {
        S_ChangeMusic(65, 1)
    }
    i = 0ul
    while (i < 704ul / 32ul) {
        screen = 328688 + int(i) * 32
        if (uint(gameversion) == 9u && (uint(c2da_mem[screen]) | uint(c2da_mem[screen + 1]) << 0x8 | uint(c2da_mem[screen + 2]) << 0x10 | uint(c2da_mem[screen + 3]) << 0x18) == 0u) {
            let c2da_fresh18 : int = 5
            let c2da_fresh19 : uint = uint(c2da_fresh18)
            c2da_mem[screen + 8] = uint8(c2da_fresh19)
            c2da_mem[screen + 9] = uint8(c2da_fresh19 >> 0x8)
            c2da_mem[screen + 10] = uint8(c2da_fresh19 >> 0x10)
            c2da_mem[screen + 11] = uint8(c2da_fresh19 >> 0x18)
        }
        if (((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 4u ? 0u : (uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 5u ? 1u : uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == (uint(c2da_mem[screen]) | uint(c2da_mem[screen + 1]) << 0x8 | uint(c2da_mem[screen + 2]) << 0x10 | uint(c2da_mem[screen + 3]) << 0x18) && (((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 4u ? 0u : (uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 5u ? 1u : uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) != 0u || gameepisode == int(uint(c2da_mem[screen + 4]) | uint(c2da_mem[screen + 5]) << 0x8 | uint(c2da_mem[screen + 6]) << 0x10 | uint(c2da_mem[screen + 7]) << 0x18)) && gamemap == int(uint(c2da_mem[screen + 8]) | uint(c2da_mem[screen + 9]) << 0x8 | uint(c2da_mem[screen + 10]) << 0x10 | uint(c2da_mem[screen + 11]) << 0x18)) {
            finaletext = int(uint(c2da_mem[screen + 24]) | uint(c2da_mem[screen + 25]) << 0x8 | uint(c2da_mem[screen + 26]) << 0x10 | uint(c2da_mem[screen + 27]) << 0x18)
            finaleflat = int(uint(c2da_mem[screen + 16]) | uint(c2da_mem[screen + 17]) << 0x8 | uint(c2da_mem[screen + 18]) << 0x10 | uint(c2da_mem[screen + 19]) << 0x18)
        }
        i++
    }
    finaletext = int(finaletext)  // nolint:PERF020
    finaleflat = int(finaleflat)  // nolint:PERF020
    finalestage = 0u
    finalecount = 0u
    return
}
[export, sideeffects]
def F_Responder(var event : int) : uint {
    if (finalestage == 2u) {
        return F_CastResponder(event)
    }
    return 0u
}
[export, sideeffects]
def F_Ticker() {
    var i_0 : uint64
    if (uint(gamemode) == 2u && finalecount > 50u) {
        i_0 = 0ul
        while (i_0 < 4ul) {
            if (c2da_mem[96 + int(i_0) * 328 + 17] != 0x0) {
                break
            }
            i_0++
        }
        if (i_0 < 4ul) {
            if (gamemap == 30) {
                F_StartCast()
            } else {
                gameaction = 8u
            }
        }
    }
    finalecount++
    if (finalestage == 2u) {
        F_CastTicker()
        return
    }
    if (uint(gamemode) == 2u) {
        return
    }
    if (finalestage == 0u && uint64(finalecount) > c2da_lin_strlen(finaletext) * 3ul + 250ul) {
        finalecount = 0u
        finalestage = 1u
        wipegamestate = 4294967295u
        if (gameepisode == 3) {
            S_StartMusic(30)
        }
    }
    return
}
[export, sideeffects]
def F_TextWrite() {
    var src : int
    var dest : int
    var w_0 : int
    var count : int
    var ch_0 : int
    var c_0 : int
    var cx_0 : int
    var cy : int
    src = W_CacheLumpName(finaleflat, 8)
    dest = I_VideoBuffer
    for (y in range(0, 200)) {
        for (x in range(0, 320 / 64)) {
            c2da_lin_memcpy(dest, src + ((y & 63) << 6), 64ul)
            dest += 64
        }
        if ((320 & 63) != 0) {
            c2da_lin_memcpy(dest, src + ((y & 63) << 6), uint64(320 & 63))
            dest += 320 & 63
        }
    }
    V_MarkRect(0, 0, 320, 200)
    cx_0 = 10
    cy = 10
    ch_0 = finaletext
    count = (int(finalecount) - 10) / 3
    if (count < 0) {
        count = 0
    }
    while (count != 0) {
        let c2da_fresh20 : int = ch_0
        ch_0++
        c_0 = int(int8(c2da_mem[c2da_fresh20]))
        if (c_0 == 0) {
            break
        }
        if (c_0 == 10) {
            cx_0 = 10
            cy += 11
            count--
            continue
        }
        c_0 = c2da_std_toupper(c_0) - 33
        if (c_0 < 0 || c_0 > 95 - 33 + 1) {
            cx_0 += 4
            count--
            continue
        }
        let c2da_fresh21 : int = int(uint(c2da_mem[41520 + c_0 * 8]) | uint(c2da_mem[41520 + c_0 * 8 + 1]) << 0x8 | uint(c2da_mem[41520 + c_0 * 8 + 2]) << 0x10 | uint(c2da_mem[41520 + c_0 * 8 + 3]) << 0x18)
        w_0 = int(int16(uint(c2da_mem[c2da_fresh21]) | uint(c2da_mem[c2da_fresh21 + 1]) << 0x8))
        if (cx_0 + w_0 > 320) {
            break
        }
        V_DrawPatch(cx_0, cy, int(uint(c2da_mem[41520 + c_0 * 8]) | uint(c2da_mem[41520 + c_0 * 8 + 1]) << 0x8 | uint(c2da_mem[41520 + c_0 * 8 + 2]) << 0x10 | uint(c2da_mem[41520 + c_0 * 8 + 3]) << 0x18))
        cx_0 += w_0
        count--
    }
    return
}
[export, sideeffects]
def F_DrawPatchCol(var x_0 : int; var patch_0 : int; var col : int) {
    var column : int
    var source : int
    var dest_0 : int
    var desttop : int
    var count_0 : int
    column = patch_0 + int(uint(c2da_mem[patch_0 + 8 + col * 4]) | uint(c2da_mem[patch_0 + 8 + col * 4 + 1]) << 0x8 | uint(c2da_mem[patch_0 + 8 + col * 4 + 2]) << 0x10 | uint(c2da_mem[patch_0 + 8 + col * 4 + 3]) << 0x18)
    desttop = I_VideoBuffer + x_0
    while (int(c2da_mem[column]) != 255) {
        source = column + 3
        dest_0 = desttop + int(c2da_mem[column]) * 320
        count_0 = int(c2da_mem[column + 1])
        while (true) {
            let c2da_postinc : int = count_0
            count_0--
            if (c2da_postinc == 0) {
                break
            }
            let c2da_fresh22 : int = source
            source++
            let c2da_fresh23 : uint8 = c2da_mem[c2da_fresh22]
            c2da_mem[dest_0] = c2da_fresh23
            dest_0 += 320
        }
        column = column + int(c2da_mem[column + 1]) + 4
    }
    return
}
[export, sideeffects]
def F_BunnyScroll() {
    let c2da_saved_sp : int = c2da_lin_sp
    F_BunnyScroll_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private F_ArtScreenDrawer() {
    var lumpname : int
    if (gameepisode == 3) {
        F_BunnyScroll()
    } else {
        if (gameepisode == 1) {
            if (uint(gamemode) == 3u) {
                lumpname = 337307
            } else {
                lumpname = 337314
            }
        } elif (gameepisode == 2) {
            lumpname = 337320
        } elif (gameepisode == 4) {
            lumpname = 337329
        } else {
            return
        }
        V_DrawPatch(0, 0, W_CacheLumpName(lumpname, 8))
    }
    return
}
[export, sideeffects]
def F_Drawer() {
    let c2da_fresh24 : uint = finalestage
    if (c2da_fresh24 == 0x2u) {
        F_CastDrawer()
    } elif (c2da_fresh24 == 0x0u) {
        F_TextWrite()
    } elif (c2da_fresh24 == 0x1u) {
        F_ArtScreenDrawer()
    }
    return
}
[sideeffects]
def private F_BunnyScroll_c2da_frame(c2da_fp : int) {
    var scrolled : int
    var p1 : int
    var p2 : int
    var stage : int
    p1 = W_CacheLumpName(337284, 5)
    p2 = W_CacheLumpName(337290, 5)
    V_MarkRect(0, 0, 320, 200)
    scrolled = 320 - (int(finalecount) - 230) / 2
    if (scrolled > 320) {
        scrolled = 320
    }
    if (scrolled < 0) {
        scrolled = 0
    }
    for (x_1 in range(0, 320)) {
        if (x_1 + scrolled < 320) {
            F_DrawPatchCol(x_1, p1, x_1 + scrolled)
        } else {
            F_DrawPatchCol(x_1, p2, x_1 + scrolled - 320)
        }
    }
    if (finalecount < 1130u) {
        return
    }
    if (finalecount < 1180u) {
        V_DrawPatch((320 - 13 * 8) / 2, (200 - 8 * 8) / 2, W_CacheLumpName(337296, 8))
        F_BunnyScroll__laststage = 0
        return
    }
    stage = int((finalecount - 1180u) / 5u)
    if (stage > 6) {
        stage = 6
    }
    if (stage > F_BunnyScroll__laststage) {
        S_StartSound(0, 1)
        F_BunnyScroll__laststage = stage
    }
    c2da_lin_snprintf(c2da_fp, 10ul, 337301, [C2daVaArg(tag = 1, i64 = int64(stage), f64 = 0.0lf, raw = 0x0)])
    V_DrawPatch((320 - 13 * 8) / 2, (200 - 8 * 8) / 2, W_CacheLumpName(c2da_fp, 8))
    return
}

// This unit's static data, at heap offset 328688.
let private c2da_lin_static_f_finale_seg = fixed_array<int>(328692, 8643)
let private c2da_lin_static_f_finale = fixed_array<uint64>(0x800000001ul, 0x506b000000000ul, 0x506b900000000ul, 0x0ul, 0x800000002ul, 0x5087200000000ul, 0x5087a00000000ul, 0x0ul, 0x800000003ul, 0x50a4d00000000ul, 0x50a5500000000ul, 0x0ul, 0x800000004ul, 0x50c4200000000ul, 0x50c4a00000000ul, 0x100000000ul, 0x600000001ul, 0x50e4200000000ul, 0x50e4a00000000ul, 0x100000000ul, 0xb00000001ul, 0x50fe000000000ul, 0x50fe800000000ul, 0x100000000ul, 0x1400000001ul, 0x5125200000000ul, 0x5125a00000000ul, 0x100000000ul, 0x1e00000001ul, 0x5139300000000ul, 0x5139b00000000ul, 0x100000000ul, 0xf00000001ul, 0x5158a00000000ul, 0x5159200000000ul, 0x100000000ul, 0x1f00000001ul, 0x5163700000000ul, 0x5163f00000000ul, 0x200000000ul, 0x600000001ul, 0x50e4200000000ul, 0x5169c00000000ul, 0x200000000ul, 0xb00000001ul, 0x50fe000000000ul, 0x5182200000000ul, 0x200000000ul, 0x1400000001ul, 0x5125200000000ul, 0x5195900000000ul, 0x200000000ul, 0x1e00000001ul, 0x5139300000000ul, 0x51a8f00000000ul, 0x200000000ul, 0xf00000001ul, 0x5158a00000000ul, 0x51c1100000000ul, 0x200000000ul, 0x1f00000001ul, 0x5163700000000ul, 0x51cbf00000000ul, 0x300000000ul, 0x600000001ul, 0x50e4200000000ul, 0x51e2100000000ul, 0x300000000ul, 0xb00000001ul, 0x50fe000000000ul, 0x51fd300000000ul, 0x300000000ul, 0x1400000001ul, 0x5125200000000ul, 0x5209500000000ul, 0x300000000ul, 0x1e00000001ul, 0x5139300000000ul, 0x521de00000000ul, 0x300000000ul, 0xf00000001ul, 0x5158a00000000ul, 0x523ab00000000ul, 0x300000000ul, 0x1f00000001ul, 0x5163700000000ul, 0x5244b00000000ul, 0x4f4f4c4600000000ul, 0x636e4f00385f3452ul, 0x656220756f792065ul, 0x6220656874207461ul, 0x7361646162206769ul, 0xa646e6120736573ul, 0x756f206e61656c63ul, 0x6f6d206568742074ul, 0x2065736162206e6ful, 0x7320657227756f79ul, 0xa6465736f707075ul, 0x202c6e6977206f74ul, 0x792074276e657261ul, 0x6e657241203f756ful, 0x203f756f79207427ul, 0xa73276572656857ul, 0x7461662072756f79ul, 0x2064726177657220ul, 0x6b63697420646e61ul, 0x3f656d6f68207465ul, 0x68740a7461685720ul, 0x69206c6c65682065ul, 0x203f736968742073ul, 0x746f6e2073277449ul, 0x65736f7070757320ul, 0x646e650a6f742064ul, 0x6177207369687420ul, 0x732074490a0a2179ul, 0x696c20736b6e6974ul, 0x6574746f7220656bul, 0x202c7461656d206eul, 0x6b6f6f6c20747562ul, 0x7420656b696c0a73ul, 0x2074736f6c206568ul, 0x6220736f6d696544ul, 0x6f4c20202e657361ul, 0x656b696c20736b6ful, 0x20657227756f790aul, 0x6e6f206b63757473ul, 0x6f68532065685420ul, 0x4820666f20736572ul, 0x6568540a2e6c6c65ul, 0x617720796c6e6f20ul, 0x73692074756f2079ul, 0x6867756f72687420ul, 0x6f63206f540a0a2eul, 0x742065756e69746eul, 0x204d4f4f44206568ul, 0x6e65697265707865ul, 0x79616c70202c6563ul, 0x6f6853206568540aul, 0x4820666f20736572ul, 0x20646e61206c6c65ul, 0x7a616d6120737469ul, 0x757165730a676e69ul, 0x65666e49202c6c65ul, 0x4653000a216f6e72ul, 0x6f5900315f36524cul, 0x6e6f642065762775ul, 0x6854202174692065ul, 0x756f656469682065ul, 0x2d72656279632073ul, 0x6c206e6f6d65640aul, 0x746168742064726ful, 0x742064656c757220ul, 0x2074736f6c206568ul, 0x6d0a736f6d696544ul, 0x65736162206e6f6ful, 0x6565622073616820ul, 0x206e69616c73206eul, 0xa756f7920646e61ul, 0x7569727420657261ul, 0x2021746e6168706dul, 0x202e2e2e20747542ul, 0x7261206572656877ul, 0x59203f756f790a65ul, 0x626d616c6320756ful, 0x6874206f74207265ul, 0x6f20656764652065ul, 0x6f6d0a6568742066ul, 0x6c20646e61206e6ful, 0x6e776f64206b6f6ful, 0x20656573206f7420ul, 0x7566776120656874ul, 0x2e68747572740a6cul, 0x736f6d6965440a0aul, 0x207374616f6c6620ul, 0x65482065766f6261ul, 0x6c65737469206c6cul, 0x7627756f590a2166ul, 0x20726576656e2065ul, 0x666f206472616568ul, 0x20656e6f796e6120ul, 0x676e697061637365ul, 0x6548206d6f72660aul, 0x20747562202c6c6cul, 0x6d206c6c27756f79ul, 0x2065687420656b61ul, 0x7364726174736162ul, 0x74207972726f730aul, 0x7265766520796568ul, 0x6f20647261656820ul, 0x512021756f792066ul, 0xa2c796c6b636975ul, 0x7070617220756f79ul, 0x206e776f64206c65ul, 0x2065687420206f74ul, 0x2065636166727573ul, 0x2e6c6c65480a666ful, 0x69202c776f4e0a0aul, 0x74206e6f20732774ul, 0x696620656874206ful, 0x70616863206c616eul, 0x440a666f20726574ul, 0x202d2d20214d4f4ful, 0x2e6f6e7265666e49ul, 0x345f38524c464d00ul, 0x616f6c2065685400ul, 0x7320656d6f736874ul, 0x6d65647265646970ul, 0xa74616874206e6ful, 0x696d72657473616dul, 0x656874206465646eul, 0x6f697361766e6920ul, 0x65687420666f206eul, 0x61620a6e6f6f6d20ul, 0x20646e6120736573ul, 0x7320646573756163ul, 0x64206863756d206ful, 0x7361682068746165ul, 0x7374690a64616820ul, 0x63696b2073736120ul, 0x20726f662064656bul, 0x656d6974206c6c61ul, 0x64696820410a0a2eul, 0x726f6f64206e6564ul, 0x6e65706f20796177ul, 0x6f7920646e612073ul, 0x2e7265746e652075ul, 0x20657627756f590aul, 0x74206e65766f7270ul, 0x6867756f74206f6ful, 0x6c654820726f6620ul, 0x6e6f630a6f74206cul, 0x6e61202c6e696174ul, 0x654820776f6e2064ul, 0x616c207461206c6cul, 0x7379616c70207473ul, 0x2d2d20726961660aul, 0x756f7920726f6620ul, 0x20656772656d6520ul, 0x656874206d6f7266ul, 0x6f740a726f6f6420ul, 0x6568742065657320ul, 0x66206e6565726720ul, 0x666f2073646c6569ul, 0xa21687472614520ul, 0x20746120656d6f48ul, 0x590a0a2e7473616cul, 0x65646e6f7720756ful, 0x7327746168772072ul, 0x6168206e65656220ul, 0x20676e696e657070ul, 0x68747261450a6e6ful, 0x7920656c69687720ul, 0x206572657720756ful, 0x676e696c74746162ul, 0x6e750a6c69766520ul, 0x2e6465687361656cul, 0x6f67207327744920ul, 0x207461687420646ful, 0x2d6c6c6548206f6eul, 0x63206e776170730aul, 0x76616820646c756ful, 0x7420656d6f632065ul, 0x74206867756f7268ul, 0x726f6f640a746168ul, 0x6f79206874697720ul, 0x464d002e2e2e2075ul, 0x687400335f38524cul, 0x7265646970732065ul, 0x6d72657473616d20ul, 0x7473756d20646e69ul, 0x6573206576616820ul, 0x6874726f6620746eul, 0x67656c207374690aul, 0x20666f20736e6f69ul, 0x776170736c6c6568ul, 0x65726f666562206eul, 0x69660a72756f7920ul, 0x666e6f63206c616eul, 0x6f697461746e6f72ul, 0x742068746977206eul, 0x7272657420746168ul, 0x6165620a656c6269ul, 0x206d6f7266207473ul, 0x6220202e6c6c6568ul, 0x7320756f79207475ul, 0x6620646570706574ul, 0x610a64726177726ful, 0x67756f726220646eul, 0x6874726f66207468ul, 0x6c616e7265746520ul, 0x6974616e6d616420ul, 0x730a646e61206e6ful, 0x676e697265666675ul, 0x6874206e6f707520ul, 0x206564726f682065ul, 0x7572742061207361ul, 0x770a6f7265682065ul, 0x206e6920646c756ful, 0x6563616620656874ul, 0x656d6f7320666f20ul, 0x6f7320676e696874ul, 0xa0a2e6c69766520ul, 0x2c73656469736562ul, 0x656e6f656d6f7320ul, 0x6e6f672073617720ul, 0x662079617020616eul, 0xa7461687720726ful, 0x64656e6570706168ul, 0x73696164206f7420ul, 0x2072756f79202c79ul, 0x6262617220746570ul, 0x7475620a0a2e7469ul, 0x6f79202c776f6e20ul, 0x7073206565732075ul, 0x6665622064616572ul, 0x20756f792065726ful, 0x746f700a65726f6dul, 0x70206c6169746e65ul, 0x20646e61206e6961ul, 0x6475746962626967ul, 0x6e20612073612065ul, 0x666f0a6e6f697461ul, 0x20736e6f6d656420ul, 0x6b6f6d61206e7572ul, 0x6f20676e6f6d6120ul, 0x6569746963207275ul, 0x7478656e0a0a2e73ul, 0x68202c706f747320ul, 0x65206e6f206c6c65ul, 0x4c53002168747261ul, 0x4f59003631454d49ul, 0x4520455641482055ul, 0x442044455245544eul, 0x4e4920594c504545ul, 0x4920454854204f54ul, 0xa4445545345464eul, 0x54524f5052415453ul, 0x4f5320545542202eul, 0x20474e494854454dul, 0x474e4f5257205349ul, 0x4f4d0a454854202eul, 0x482053524554534eul, 0x554f524220455641ul, 0x4945485420544847ul, 0x4552204e574f2052ul, 0x49570a5954494c41ul, 0x2c4d454854204854ul, 0x45485420444e4120ul, 0x524f505241545320ul, 0x4843455420532754ul, 0x490a59474f4c4f4eul, 0x20474e4945422053ul, 0x4554524556425553ul, 0x4548542059422044ul, 0x4553455250205249ul, 0x48410a0a2e45434eul, 0x554f59202c444145ul, 0x204e412045455320ul, 0x2054534f5054554ful, 0x2c4c4c454820464ful, 0x4954524f460a4120ul, 0x4e4f5a2044454946ul, 0x4f59204649202e45ul, 0x4547204e41432055ul, 0x4920545341502054ul, 0x4320554f590a2c54ul, 0x54454e4550204e41ul, 0x544e492045544152ul, 0x414820454854204ful, 0x4548204445544e55ul, 0x5420464f0a545241ul, 0x4252415453204548ul, 0x20444e4120455341ul, 0x45485420444e4946ul, 0x4c4f52544e4f4320ul, 0x4957530a474e494cul, 0x4349485720484354ul, 0x2053444c4f482048ul, 0x2053274854524145ul, 0x4954414c55504f50ul, 0x4154534f480a4e4ful, 0x434f5252002e4547ul, 0x20554f590034314bul, 0x4e4f572045564148ul, 0x562052554f592021ul, 0x482059524f544349ul, 0x4c42414e45205341ul, 0x4e414d55480a4445ul, 0x204f5420444e494bul, 0x4554415543415645ul, 0x4120485452414520ul, 0x504143534520444eul, 0x494e204548540a45ul, 0x2e4552414d544847ul, 0x4f5920574f4e2020ul, 0x4854204552412055ul, 0x480a594c4e4f2045ul, 0x46454c204e414d55ul, 0x454854204e4f2054ul, 0x464f204543414620ul, 0x414c502045485420ul, 0x4e41430a2e54454eul, 0x554d204c4142494eul, 0x2c534e4f49544154ul, 0x4f56494e52414320ul, 0x494c412053554f52ul, 0x444e410a2c534e45ul, 0x5053204c49564520ul, 0x5241205354495249ul, 0x4f2052554f592045ul, 0x4749454e20594c4eul, 0x590a2e53524f4248ul, 0x422054495320554ful, 0x20444e41204b4341ul, 0x524f462054494157ul, 0x202c485441454420ul, 0xa544e45544e4f43ul, 0x554f592054414854ul, 0x4153204556414820ul, 0x52554f5920444556ul, 0x5345494345505320ul, 0x54205455420a0a2eul, 0x524145202c4e4548ul, 0x52544e4f43204854ul, 0x534d414542204c4ful, 0xa41204e574f4420ul, 0x204547415353454dul, 0x415053204d4f5246ul, 0x4e455322203a4543ul, 0x5641482053524f53ul, 0x455441434f4c2045ul, 0x4f53204548540a44ul, 0x20464f2045435255ul, 0x45494c4120454854ul, 0x495341564e49204eul, 0x59204649202e4e4ful, 0x4854204f470a554ful, 0x554f59202c455245ul, 0x2045422059414d20ul, 0x204f5420454c4241ul, 0x4854204b434f4c42ul, 0x52544e450a524945ul, 0x2045485420202e59ul, 0x4142204e45494c41ul, 0x4e49205349204553ul, 0x4145482045485420ul, 0x4f590a464f205452ul, 0x48204e574f205255ul, 0x5954494320454d4ful, 0x414620544f4e202cul, 0x54204d4f52462052ul, 0x50524154530a4548ul, 0x4c5320222e54524ful, 0x444e4120594c574ful, 0x4c55464e49415020ul, 0x4720554f5920594cul, 0x4e412050550a5445ul, 0x4e52555445522044ul, 0x20454854204f5420ul, 0x5252002e59415246ul, 0x4f590037304b434ful, 0x5441204552412055ul, 0x524f432045485420ul, 0x4145482054505552ul, 0x485420464f205452ul, 0xa2c595449432045ul, 0x444e554f52525553ul, 0x4854205942204445ul, 0x455350524f432045ul, 0x554f5920464f2053ul, 0x45494d454e452052ul, 0x5320554f590a2e53ul, 0x4157204f4e204545ul, 0x534544204f542059ul, 0x45485420594f5254ul, 0x5255544145524320ul, 0x52544e450a275345ul, 0x204e4f2059415759ul, 0x4449532053494854ul, 0x4f59204f53202c45ul, 0x48434e454c432055ul, 0x45540a52554f5920ul, 0x20444e4120485445ul, 0x542045474e554c50ul, 0x49204847554f5248ul, 0x524548540a0a2e54ul, 0x42205453554d2045ul, 0x2059415720412045ul, 0x45534f4c43204f54ul, 0x54204e4f20544920ul, 0x524548544f0a4548ul, 0x57202e4544495320ul, 0x59204f4420544148ul, 0x204552414320554ful, 0x5627554f59204649ul, 0x4f5420544f470a45ul, 0x4f524854204f4720ul, 0x4c4c454820484755ul, 0x20544547204f5420ul, 0x52003f5449204f54ul, 0x540037314b434f52ul, 0x4552524f48204548ul, 0x49562053554f444eul, 0x20464f2045474153ul, 0x4747494220454854ul, 0x4f4d45440a545345ul, 0x455627554f59204eul, 0x4553205245564520ul, 0x424d555243204e45ul, 0x4f4645422053454cul, 0x202c554f590a4552ul, 0x4f59205245544641ul, 0x5920504d55502055ul, 0x4b434f522052554ful, 0x4f544e4920535445ul, 0x505845205349480aul, 0x415242204445534ful, 0x20454854202e4e49ul, 0x20524554534e4f4dul, 0x534c455649524853ul, 0x20444e412050550aul, 0x5449202c53454944ul, 0x4853415248542053ul, 0x424d494c20474e49ul, 0x5453415645440a53ul, 0x4e5520474e495441ul, 0x4c494d20444c4f54ul, 0x454820464f205345ul, 0x5255530a53274c4cul, 0x590a0a2e45434146ul, 0x4f4420455627554ful, 0x54202e544920454eul, 0x5341564e49204548ul, 0x4f205349204e4f49ul, 0x5241450a2e524556ul, 0x4153205349204854ul, 0x4c4548202e444556ul, 0x572041205349204cul, 0x4f59202e4b434552ul, 0x5245444e4f570a55ul, 0x4220455245485720ul, 0x534b4c4f46204441ul, 0x4f47204c4c495720ul, 0x4854204e45485720ul, 0x202c4549440a5945ul, 0x504957202e574f4eul, 0x2045485420474e49ul, 0x5246205441455753ul, 0xa52554f59204d4ful, 0x4441454845524f46ul, 0x47454220554f5920ul, 0x4c20454854204e49ul, 0x4b45525420474e4ful, 0x4f480a4b43414220ul, 0x55424552202e454dul, 0x4520474e49444c49ul, 0x47554f2048545241ul, 0x4542204f54205448ul, 0x4d20544f4c0a4120ul, 0x204e55462045524ful, 0x495552204e414854ul, 0x20544920474e494eul, 0x5252000a2e534157ul, 0x4f430033314b434ful, 0x414c55544152474eul, 0x59202c534e4f4954ul, 0x4f4620455627554ful, 0x2045485420444e55ul, 0x4c0a544552434553ul, 0x4f4c20214c455645ul, 0x454b494c20534b4ful, 0x4542205327544920ul, 0x544c495542204e45ul, 0x414d55480a594220ul, 0x48544152202c534eul, 0x204e414854205245ul, 0x202e534e4f4d4544ul, 0x444e4f5720554f59ul, 0x54204f48570a5245ul, 0x54414d4e49204548ul, 0x485420464f205345ul, 0x454e524f43205349ul, 0x4c454820464f2052ul, 0x42204c4c49570a4cul, 0x4b434f5252002e45ul, 0x52474e4f43003931ul, 0x4f4954414c555441ul, 0x27554f59202c534eul, 0x444e554f46204556ul, 0x5055530a45485420ul, 0x4552434553205245ul, 0x214c4556454c2054ul, 0x204427554f592020ul, 0x420a524554544542ul, 0x52485420455a414cul, 0x494854204847554ful, 0xa21454e4f2053ul, 0x6620657627756f59ul, 0x6f7920746867756ful, 0x6f20796177207275ul, 0x687420666f207475ul, 0x747365666e692065ul, 0x72657078650a6465ul, 0x206c61746e656d69ul, 0x2020202e7362616cul, 0x736d656573207449ul, 0x4155207461687420ul, 0x6e6f0a7361682043ul, 0x6e69616761206563ul, 0x206465706c756720ul, 0x2e6e776f64207469ul, 0x7420687469572020ul, 0x6769680a72696568ul, 0x766f6e7275742068ul, 0x6d207469202c7265ul, 0x6820656220747375ul, 0x20726f6620647261ul, 0x646c6f0a726f6f70ul, 0x206f742043415520ul, 0x70726f6320797562ul, 0x656820657461726ful, 0x736e692068746c61ul, 0x6e0a65636e617275ul, 0x2e7379616461776ful, 0x64616568410a0a2eul, 0x6874207365696c20ul, 0x6174696c696d2065ul, 0x6c706d6f63207972ul, 0xa776f6e202c7865ul, 0x676e696d72617773ul, 0x6964206874697720ul, 0x6820646573616573ul, 0x682073726f72726ful, 0x6567206f7420746ful, 0x2072696568740a74ul, 0x6e69206874656574ul, 0x202e756f79206f74ul, 0x63756c2068746957ul, 0x630a656874202c6bul, 0x732078656c706d6ful, 0x736168206c6c6974ul, 0x617720656d6f7320ul, 0x726f20656b696c72ul, 0x6c0a65636e616e64ul, 0x726120676e697961ul, 0x6f59002e646e756ful, 0x7420726165682075ul, 0x646e697267206568ul, 0x6820666f20676e69ul, 0x63616d2079766165ul, 0x610a7972656e6968ul, 0x5920202e64616568ul, 0x206572757320756ful, 0x6568742065706f68ul, 0x746f6e2065722779ul, 0x6e69706d61747320ul, 0x656e2074756f0a67ul, 0x70736c6c65682077ul, 0x747562202c6e7761ul, 0x20657227756f7920ul, 0x6f74207964616572ul, 0x756f206d6165720aul, 0x6c6f687720612074ul, 0x6920647265682065ul, 0x616820756f792066ul, 0x540a2e6f74206576ul, 0x6867696d20796568ul, 0x616c702065622074ul, 0x206120676e696e6eul, 0x656620646f6f6c62ul, 0x747562202c747361ul, 0x65656620756f790aul, 0x2074756f6261206cul, 0x206e61656d207361ul, 0x74206f7774207361ul, 0xa646e6173756f68ul, 0x20736361696e616dul, 0x692064656b636170ul, 0x20656e6f206f746eul, 0x6c6c696b2064616dul, 0x756f590a0a2e7265ul, 0x702074276e6f6420ul, 0x67206f74206e616cul, 0x65206e776f64206ful, 0x656854002e797361ul, 0x6f20617473697620ul, 0x6120676e696e6570ul, 0x6f6f6c2064616568ul, 0x206c61657220736bul, 0x6d61660a6e6d6164ul, 0x53202e7261696c69ul, 0x616620736c6c656dul, 0x202c7261696c696dul, 0x6c202d2d206f6f74ul, 0x656972660a656b69ul, 0x6d65726378652064ul, 0x756f59202e746e65ul, 0x2074276e64696420ul, 0x69687420656b696cul, 0x206563616c700a73ul, 0x202c65726f666562ul, 0x20756f7920646e61ul, 0x2073612065727573ul, 0x6e6961206c6c6568ul, 0x6e6e616c700a7427ul, 0x6c206f7420676e69ul, 0x6e20746920656b69ul, 0x20656854202e776ful, 0x756f792065726f6dul, 0x6f20646f6f72620aul, 0x6874202c7469206eul, 0x72656464616d2065ul, 0x74656720756f7920ul, 0x6e69746665480a2eul, 0x672072756f792067ul, 0x65206e61202c6e75ul, 0x6e697267206c6976ul, 0x656c6b6369727420ul, 0x79206f746e6f0a73ul, 0x656361662072756ful, 0x7420656d6954202eul, 0x7320656b6174206ful, 0x656d616e20656d6ful, 0x6564647553002e73ul, 0x6c6c61202c796c6eul, 0x656c697320736920ul, 0x6d6f7266202c746eul, 0x726f6820656e6f20ul, 0x206f740a6e6f7a69ul, 0x6568746f20656874ul, 0x6120656854202e72ul, 0x676e697a696e6f67ul, 0x666f206f68636520ul, 0x61660a6c6c654820ul, 0x7961776120736564ul, 0x696e20656874202cul, 0x206572616d746867ul, 0x6e72757420796b73ul, 0x756c620a6f742073ul, 0x6820656874202c65ul, 0x20666f2073706165ul, 0x20726574736e6f6dul, 0x2073657370726f63ul, 0x740a207472617473ul, 0x726f70617665206ful, 0x6e6f6c6120657461ul, 0x7420687469772067ul, 0x206c697665206568ul, 0xa2068636e657473ul, 0x6c69662074616874ul, 0x206568742064656cul, 0x65654a202e726961ul, 0x6279616d202c657aul, 0x657627756f792065ul, 0x746920656e6f640aul, 0x792065766148202eul, 0x6c6c61657220756ful, 0xa0a3f6e6f772079ul, 0x6e696874656d6f53ul, 0x656c626d75722067ul, 0x656874206e692073ul, 0x636e617473696420ul, 0x756c6220410a2e65ul, 0x20746867696c2065ul, 0x7420736e69676562ul, 0x6920776f6c67206ful, 0x687420656469736eul, 0x64656e6975720a65ul, 0x6f206c6c756b7320ul, 0x6564206568742066ul, 0x746970732d6e6f6dul, 0x616857002e726574ul, 0x4c203f776f6e2074ul, 0x746f7420736b6f6ful, 0x66696420796c6c61ul, 0x202e746e65726566ul, 0x20666f0a646e694bul, 0x6e694b20656b696cul, 0x2073277475542067ul, 0x57202e6f646e6f63ul, 0x6168770a2c6c6c65ul, 0x2073277265766574ul, 0x6e61632065726568ul, 0x6e61206562207427ul, 0xa6573726f772079ul, 0x757375206e616874ul, 0x206e6143202e6c61ul, 0x20724f20203f7469ul, 0x746920656279616dul, 0xa74736562207327ul, 0x732074656c206f74ul, 0x20676e697065656cul, 0x65696c2073646f67ul, 0x20656d6954002e2eul, 0x6176206120726f66ul, 0x202e6e6f69746163ul, 0x6220657627756f59ul, 0x6568742074737275ul, 0x20736c65776f620aul, 0x206c6c656820666ful, 0x6720796220646e61ul, 0x756f7920796c6c6ful, 0x6461657220657227ul, 0x206120726f660a79ul, 0x59202e6b61657262ul, 0x657474756d20756ful, 0x756f79206f742072ul, 0x4d0a2c666c657372ul, 0x6d6f732065627961ul, 0x736c6520656e6f65ul, 0x696b206e61632065ul, 0x276c6c6548206b63ul, 0x656e0a7373612073ul, 0x20656d6974207478ul, 0x202e646e756f7261ul, 0x696c206461656841ul, 0x6975712061207365ul, 0x2c6e776f74207465ul, 0x657020687469770aul, 0x66206c7566656361ul, 0x7720676e69776f6cul, 0x7571202c72657461ul, 0x6975620a746e6961ul, 0x202c73676e69646cul, 0x7365727020646e61ul, 0x6e20796c62616d75ul, 0x70736c6c6548206ful, 0x73410a0a2e6e7761ul, 0x65747320756f7920ul, 0x68742066666f2070ul, 0x70736e6172742065ul, 0x756f79202c74726ful, 0x68740a7261656820ul, 0x20706d6f74732065ul, 0x627963206120666ful, 0x276e6f6d65647265ul, 0x73206e6f72692073ul, 0x756f59002e656f68ul, 0x6f2074616f6c6720ul, 0x2065687420726576ul, 0x676e696d61657473ul, 0x7373616372616320ul, 0xa65687420666f20ul, 0x6e61696472617547ul, 0x206874695720202eul, 0x7461656420737469ul, 0x7627756f79202c68ul, 0x6574736572772065ul, 0x6341206568740a64ul, 0x6f746172656c6563ul, 0x74206d6f72662072ul, 0x6b6e697473206568ul, 0x77616c6320676e69ul, 0x6c654820666f0a73ul, 0x20756f5920202e6cul, 0x6e612078616c6572ul, 0x65636e616c672064ul, 0x20646e756f726120ul, 0x6d6f6f720a656874ul, 0x216e6d614420202eul, 0x2065726568542020ul, 0x7070757320736177ul, 0x206f74206465736ful, 0x656c0a7461206562ul, 0x20656e6f20747361ul, 0x20676e696b726f77ul, 0x7079746f746f7270ul, 0x7920747562202c65ul, 0x74276e616320756ful, 0x2e7469206565730aul, 0x6d65642065685420ul, 0x7473756d20736e6ful, 0x6174206576616820ul, 0xa2e7469206e656bul, 0x73756d20756f590aul, 0x7420646e69662074ul, 0x6f746f7270206568ul, 0x726f202c65707974ul, 0x756f79206c6c6120ul, 0x6767757274730a72ul, 0x6c6c69772073656cul, 0x6562206576616820ul, 0x6574736177206e65ul, 0xa7065654b202e64ul, 0x202c676e69766f6dul, 0x676966207065656bul, 0x6b202c676e697468ul, 0x6c6c696b20706565ul, 0x20684f0a2e676e69ul, 0x65656b202c736579ul, 0x676e6976696c2070ul, 0x45002e6f6f74202cul, 0x20656874206e6576ul, 0x4120796c64616564ul, 0x656c69562d686372ul, 0x6e69727962616c20ul, 0x646c756f63206874ul, 0x6f747320746f6e0aul, 0x61202c756f792070ul, 0x7627756f7920646eul, 0x6e6574746f672065ul, 0xa656874206f7420ul, 0x7079746f746f7270ul, 0x656c656363412065ul, 0x687720726f746172ul, 0x7320736920686369ul, 0x696666650a6e6f6ful, 0x20796c746e656963ul, 0x6d72657020646e61ul, 0x20796c746e656e61ul, 0x6176697463616564ul, 0x6f590a0a2e646574ul, 0x6f6f672065722775ul, 0x6168742074612064ul, 0x6f20646e696b2074ul, 0x2e676e6968742066ul, 0x20657627756f5900ul, 0x6120646568736162ul, 0x657474616220646eul, 0x72756f7920646572ul, 0x746e692079617720ul, 0x6568206568740a6ful, 0x7420666f20747261ul, 0x6c69766564206568ul, 0x20202e657669682dul, 0x726f6620656d6954ul, 0x63726165530a6120ul, 0x65442d646e612d68ul, 0x696d20796f727473ul, 0x61202c6e6f697373ul, 0x2074612064656d69ul, 0x657461470a656874ul, 0x202c72657065656bul, 0x6f662065736f6877ul, 0x707366666f206c75ul, 0xa736920676e6972ul, 0x6e69646163736163ul, 0x726145206f742067ul, 0x61655920202e6874ul, 0x2073276568202c68ul, 0x747542202e646162ul, 0x6f6e6b20756f790aul, 0x2073276f68772077ul, 0xa0a216573726f77ul, 0x676e696e6e697247ul, 0x2c796c6c69766520ul, 0x65686320756f7920ul, 0x2072756f79206b63ul, 0x6e61202c72616567ul, 0x6572207465670a64ul, 0x67206f7420796461ul, 0x2065687420657669ul, 0x2064726174736162ul, 0x656c7474696c2061ul, 0x666f0a6c6c654820ul, 0x776f2072756f7920ul, 0x676e696b616d206eul, 0x6147206568540021ul, 0x72657065656b6574ul, 0x206c697665207327ul, 0x2073692065636166ul, 0x72657474616c7073ul, 0x6f206c6c610a6465ul, 0x2065687420726576ul, 0x20202e6563616c70ul, 0x7420737469207341ul, 0x2064657265747461ul, 0x630a657370726f63ul, 0x73657370616c6c6ful, 0x766e69206e61202cul, 0x6147206465747265ul, 0x736d726f66206574ul, 0x6375730a646e6120ul, 0x206e776f6420736bul, 0x7261687320656874ul, 0x687420666f207364ul, 0x700a7473616c2065ul, 0x657079746f746f72ul, 0x72656c6563634120ul, 0x6f6e202c726f7461ul, 0x6e656d206f742074ul, 0x656874206e6f6974ul, 0x6d6572207765660aul, 0x6420676e696e6961ul, 0x20202e736e6f6d65ul, 0x6420657227756f59ul, 0x6c6548202e656e6ful, 0x6f67207361680a6cul, 0x206b63616220656eul, 0x646e756f70206f74ul, 0x2064616220676e69ul, 0x6c6f662064616564ul, 0x74736e690a20736bul, 0x6720666f20646165ul, 0x6576696c20646f6ful, 0x20202e73656e6f20ul, 0x7265626d656d6552ul, 0x6c6c65740a6f7420ul, 0x72672072756f7920ul, 0x207364696b646e61ul, 0x6120747570206f74ul, 0xa74656b636f7220ul, 0x726568636e75616cul, 0x72756f79206e6920ul, 0x2e6e6966666f6320ul, 0x20756f7920664920ul, 0x6548206f74206f67ul, 0x206e6568770a6c6cul, 0x2c65696420756f79ul, 0x206c6c27756f7920ul, 0x207469206465656eul, 0x656d6f7320726f66ul, 0x63206c616e69660aul, 0x2d676e696e61656cul, 0x59002e2e2e207075ul, 0x6f6620657627756ful, 0x2065687420646e75ul, 0x682d646e6f636573ul, 0x6c20747365647261ul, 0xa6577206c657665ul, 0x706f48202e746f67ul, 0x616820756f792065ul, 0x7661732061206576ul, 0x20656d6167206465ul, 0x206c6576656c2061ul, 0x70206f77740a726ful, 0x2e73756f69766572ul, 0x746f6e2066492020ul, 0x657270206562202cul, 0x6f74206465726170ul, 0x6c70610a65696420ul, 0x6f46202e79746e65ul, 0x72657473616d2072ul, 0x73656e6972616d20ul, 0x42002e796c6e6f20ul, 0x6f77206168637465ul, 0x6a2064657265646eul, 0x7461687720747375ul, 0x6568742053415720ul, 0x7473656472616820ul, 0x77206c6576656c0aul, 0x6572206461682065ul, 0x20726f6620796461ul, 0x776f4e20203f6179ul, 0x6f6e6b20756f7920ul, 0x6e6f206f4e0a2e77ul, 0x6f20737465672065ul, 0x6576696c61207475ul, 0x4549424d4f5a002eul, 0x544f4853004e414dul, 0x595547204e5547ul, 0x4557205956414548ul, 0x445544204e4f5041ul, 0x454400504d490045ul, 0x54534f4c004e4f4dul, 0x4143004c554f5320ul, 0x4e4f4d45444f43ul, 0x494e4b204c4c4548ul, 0x4f52414200544847ul, 0x4c454820464f204eul, 0x4e4843415241004cul, 0x4150004e4f52544ful, 0x454d454c45204e49ul, 0x564552004c41544eul, 0x414d00544e414e45ul, 0x410053554255434eul, 0x454c49562d484352ul, 0x4950532045485400ul, 0x5453414d20524544ul, 0x5400444e494d5245ul, 0x5245425943204548ul, 0x554f004e4f4d4544ul, 0x42004f5245482052ul, 0x4b43414253534ful, 0x4650003242554650ul, 0x30444e4500314255ul, 0x43006925444e4500ul, 0x4548005449444552ul, 0x544349560032504cul, 0x444e45003259524ful, 0x434950ul)

[init]
def private c2da_lin_init_static_f_finale() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_f_finale_seg[s * 2]
        for (k in range(c2da_lin_static_f_finale_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_f_finale[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
