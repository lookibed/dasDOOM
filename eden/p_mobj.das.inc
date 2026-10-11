var itemrespawntime : int[128]

var iquehead : int = default<int>

var iquetail : int = default<int>

[export, sideeffects]
def P_RespawnSpecials() {
    var x : int
    var y : int
    var z : int
    var ss : int
    var mo : int
    var mthing : int
    var i : int
    if (deathmatch != 2) {
        return
    }
    if (iquehead == iquetail) {
        return
    }
    if (leveltime - itemrespawntime[iquetail] < 30 * 35) {
        return
    }
    mthing = 49776 + iquetail * 10
    x = int(int16(uint(c2da_mem[mthing]) | uint(c2da_mem[mthing + 1]) << 0x8)) << 16
    y = int(int16(uint(c2da_mem[mthing + 2]) | uint(c2da_mem[mthing + 3]) << 0x8)) << 16
    ss = R_PointInSubsector(x, y)
    let c2da_fresh0 : int = int(uint(c2da_mem[ss]) | uint(c2da_mem[ss + 1]) << 0x8 | uint(c2da_mem[ss + 2]) << 0x10 | uint(c2da_mem[ss + 3]) << 0x18)
    mo = P_SpawnMobj(x, y, int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18), 40u)
    S_StartSound(mo, 90)
    i = 0
    while (i < 137) {
        if (int(int16(uint(c2da_mem[mthing + 6]) | uint(c2da_mem[mthing + 7]) << 0x8)) == int(uint(c2da_mem[51056 + i * 92]) | uint(c2da_mem[51056 + i * 92 + 1]) << 0x8 | uint(c2da_mem[51056 + i * 92 + 2]) << 0x10 | uint(c2da_mem[51056 + i * 92 + 3]) << 0x18)) {
            break
        }
        i++
    }
    if ((int(uint(c2da_mem[51056 + i * 92 + 84]) | uint(c2da_mem[51056 + i * 92 + 85]) << 0x8 | uint(c2da_mem[51056 + i * 92 + 86]) << 0x10 | uint(c2da_mem[51056 + i * 92 + 87]) << 0x18) & 256) != 0) {
        z = 2147483647
    } else {
        z = -2147483647 - 1
    }
    mo = P_SpawnMobj(x, y, z, uint(i))
    c2da_lin_memmove(mo + 204, mthing, 10ul)
    let c2da_fresh1 : uint = uint(536870912 * (int(int16(uint(c2da_mem[mthing + 4]) | uint(c2da_mem[mthing + 5]) << 0x8)) / 45))
    let c2da_fresh2 : uint = c2da_fresh1
    c2da_mem[mo + 56] = uint8(c2da_fresh2)
    c2da_mem[mo + 57] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[mo + 58] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[mo + 59] = uint8(c2da_fresh2 >> 0x18)
    iquetail = iquetail + 1 & 128 - 1
    return
}
[export, sideeffects]
def P_SpawnMobj(var x_0 : int; var y_0 : int; var z_0 : int; var type_0 : uint) : int {
    var mobj : int
    var st : int
    var info : int
    mobj = Z_Malloc(224, 5, 0)
    c2da_lin_memset(mobj, 0, 224ul)
    info = 51056 + int(type_0) * 92
    let c2da_fresh3 : uint = type_0
    c2da_mem[mobj + 128] = uint8(c2da_fresh3)
    c2da_mem[mobj + 129] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[mobj + 130] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[mobj + 131] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : uint = uint(info)
    c2da_mem[mobj + 136] = uint8(c2da_fresh4)
    c2da_mem[mobj + 137] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[mobj + 138] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[mobj + 139] = uint8(c2da_fresh4 >> 0x18)
    c2da_mem[mobj + 140] = 0u8
    c2da_mem[mobj + 141] = 0u8
    c2da_mem[mobj + 142] = 0u8
    c2da_mem[mobj + 143] = 0u8
    let c2da_fresh5 : uint = uint(x_0)
    c2da_mem[mobj + 24] = uint8(c2da_fresh5)
    c2da_mem[mobj + 25] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[mobj + 26] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[mobj + 27] = uint8(c2da_fresh5 >> 0x18)
    let c2da_fresh6 : uint = uint(y_0)
    c2da_mem[mobj + 28] = uint8(c2da_fresh6)
    c2da_mem[mobj + 29] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[mobj + 30] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[mobj + 31] = uint8(c2da_fresh6 >> 0x18)
    let c2da_fresh7 : int = int(uint(c2da_mem[info + 64]) | uint(c2da_mem[info + 65]) << 0x8 | uint(c2da_mem[info + 66]) << 0x10 | uint(c2da_mem[info + 67]) << 0x18)
    let c2da_fresh8 : uint = uint(c2da_fresh7)
    c2da_mem[mobj + 104] = uint8(c2da_fresh8)
    c2da_mem[mobj + 105] = uint8(c2da_fresh8 >> 0x8)
    c2da_mem[mobj + 106] = uint8(c2da_fresh8 >> 0x10)
    c2da_mem[mobj + 107] = uint8(c2da_fresh8 >> 0x18)
    let c2da_fresh9 : int = int(uint(c2da_mem[info + 68]) | uint(c2da_mem[info + 69]) << 0x8 | uint(c2da_mem[info + 70]) << 0x10 | uint(c2da_mem[info + 71]) << 0x18)
    let c2da_fresh10 : uint = uint(c2da_fresh9)
    c2da_mem[mobj + 108] = uint8(c2da_fresh10)
    c2da_mem[mobj + 109] = uint8(c2da_fresh10 >> 0x8)
    c2da_mem[mobj + 110] = uint8(c2da_fresh10 >> 0x10)
    c2da_mem[mobj + 111] = uint8(c2da_fresh10 >> 0x18)
    let c2da_fresh11 : int = int(uint(c2da_mem[info + 84]) | uint(c2da_mem[info + 85]) << 0x8 | uint(c2da_mem[info + 86]) << 0x10 | uint(c2da_mem[info + 87]) << 0x18)
    let c2da_fresh12 : uint = uint(c2da_fresh11)
    c2da_mem[mobj + 160] = uint8(c2da_fresh12)
    c2da_mem[mobj + 161] = uint8(c2da_fresh12 >> 0x8)
    c2da_mem[mobj + 162] = uint8(c2da_fresh12 >> 0x10)
    c2da_mem[mobj + 163] = uint8(c2da_fresh12 >> 0x18)
    let c2da_fresh13 : int = int(uint(c2da_mem[info + 8]) | uint(c2da_mem[info + 9]) << 0x8 | uint(c2da_mem[info + 10]) << 0x10 | uint(c2da_mem[info + 11]) << 0x18)
    let c2da_fresh14 : uint = uint(c2da_fresh13)
    c2da_mem[mobj + 164] = uint8(c2da_fresh14)
    c2da_mem[mobj + 165] = uint8(c2da_fresh14 >> 0x8)
    c2da_mem[mobj + 166] = uint8(c2da_fresh14 >> 0x10)
    c2da_mem[mobj + 167] = uint8(c2da_fresh14 >> 0x18)
    if (int(gameskill) != 4) {
        let c2da_fresh15 : int = int(uint(c2da_mem[info + 20]) | uint(c2da_mem[info + 21]) << 0x8 | uint(c2da_mem[info + 22]) << 0x10 | uint(c2da_mem[info + 23]) << 0x18)
        let c2da_fresh16 : uint = uint(c2da_fresh15)
        c2da_mem[mobj + 184] = uint8(c2da_fresh16)
        c2da_mem[mobj + 185] = uint8(c2da_fresh16 >> 0x8)
        c2da_mem[mobj + 186] = uint8(c2da_fresh16 >> 0x10)
        c2da_mem[mobj + 187] = uint8(c2da_fresh16 >> 0x18)
    }
    let c2da_fresh17 : int = P_Random() % 4
    let c2da_fresh18 : uint = uint(c2da_fresh17)
    c2da_mem[mobj + 200] = uint8(c2da_fresh18)
    c2da_mem[mobj + 201] = uint8(c2da_fresh18 >> 0x8)
    c2da_mem[mobj + 202] = uint8(c2da_fresh18 >> 0x10)
    c2da_mem[mobj + 203] = uint8(c2da_fresh18 >> 0x18)
    st = 2080 + int(uint(c2da_mem[info + 4]) | uint(c2da_mem[info + 5]) << 0x8 | uint(c2da_mem[info + 6]) << 0x10 | uint(c2da_mem[info + 7]) << 0x18) * 40
    let c2da_fresh19 : uint = uint(st)
    c2da_mem[mobj + 152] = uint8(c2da_fresh19)
    c2da_mem[mobj + 153] = uint8(c2da_fresh19 >> 0x8)
    c2da_mem[mobj + 154] = uint8(c2da_fresh19 >> 0x10)
    c2da_mem[mobj + 155] = uint8(c2da_fresh19 >> 0x18)
    c2da_mem[mobj + 156] = 0u8
    c2da_mem[mobj + 157] = 0u8
    c2da_mem[mobj + 158] = 0u8
    c2da_mem[mobj + 159] = 0u8
    let c2da_fresh20 : int = int(uint(c2da_mem[st + 8]) | uint(c2da_mem[st + 9]) << 0x8 | uint(c2da_mem[st + 10]) << 0x10 | uint(c2da_mem[st + 11]) << 0x18)
    let c2da_fresh21 : uint = uint(c2da_fresh20)
    c2da_mem[mobj + 144] = uint8(c2da_fresh21)
    c2da_mem[mobj + 145] = uint8(c2da_fresh21 >> 0x8)
    c2da_mem[mobj + 146] = uint8(c2da_fresh21 >> 0x10)
    c2da_mem[mobj + 147] = uint8(c2da_fresh21 >> 0x18)
    let c2da_fresh22 : uint = uint(c2da_mem[st]) | uint(c2da_mem[st + 1]) << 0x8 | uint(c2da_mem[st + 2]) << 0x10 | uint(c2da_mem[st + 3]) << 0x18
    let c2da_fresh23 : uint = c2da_fresh22
    c2da_mem[mobj + 60] = uint8(c2da_fresh23)
    c2da_mem[mobj + 61] = uint8(c2da_fresh23 >> 0x8)
    c2da_mem[mobj + 62] = uint8(c2da_fresh23 >> 0x10)
    c2da_mem[mobj + 63] = uint8(c2da_fresh23 >> 0x18)
    let c2da_fresh24 : int = int(uint(c2da_mem[st + 4]) | uint(c2da_mem[st + 5]) << 0x8 | uint(c2da_mem[st + 6]) << 0x10 | uint(c2da_mem[st + 7]) << 0x18)
    let c2da_fresh25 : uint = uint(c2da_fresh24)
    c2da_mem[mobj + 64] = uint8(c2da_fresh25)
    c2da_mem[mobj + 65] = uint8(c2da_fresh25 >> 0x8)
    c2da_mem[mobj + 66] = uint8(c2da_fresh25 >> 0x10)
    c2da_mem[mobj + 67] = uint8(c2da_fresh25 >> 0x18)
    P_SetThingPosition(mobj)
    let c2da_fresh26 : int = int(uint(c2da_mem[mobj + 88]) | uint(c2da_mem[mobj + 89]) << 0x8 | uint(c2da_mem[mobj + 90]) << 0x10 | uint(c2da_mem[mobj + 91]) << 0x18)
    let c2da_fresh27 : int = int(uint(c2da_mem[c2da_fresh26]) | uint(c2da_mem[c2da_fresh26 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh26 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh26 + 3]) << 0x18)
    let c2da_fresh28 : int = int(uint(c2da_mem[c2da_fresh27]) | uint(c2da_mem[c2da_fresh27 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh27 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh27 + 3]) << 0x18)
    let c2da_fresh29 : uint = uint(c2da_fresh28)
    c2da_mem[mobj + 96] = uint8(c2da_fresh29)
    c2da_mem[mobj + 97] = uint8(c2da_fresh29 >> 0x8)
    c2da_mem[mobj + 98] = uint8(c2da_fresh29 >> 0x10)
    c2da_mem[mobj + 99] = uint8(c2da_fresh29 >> 0x18)
    let c2da_fresh30 : int = int(uint(c2da_mem[mobj + 88]) | uint(c2da_mem[mobj + 89]) << 0x8 | uint(c2da_mem[mobj + 90]) << 0x10 | uint(c2da_mem[mobj + 91]) << 0x18)
    let c2da_fresh31 : int = int(uint(c2da_mem[c2da_fresh30]) | uint(c2da_mem[c2da_fresh30 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh30 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh30 + 3]) << 0x18) + 4
    let c2da_fresh32 : int = int(uint(c2da_mem[c2da_fresh31]) | uint(c2da_mem[c2da_fresh31 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh31 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh31 + 3]) << 0x18)
    let c2da_fresh33 : uint = uint(c2da_fresh32)
    c2da_mem[mobj + 100] = uint8(c2da_fresh33)
    c2da_mem[mobj + 101] = uint8(c2da_fresh33 >> 0x8)
    c2da_mem[mobj + 102] = uint8(c2da_fresh33 >> 0x10)
    c2da_mem[mobj + 103] = uint8(c2da_fresh33 >> 0x18)
    if (z_0 == -2147483647 - 1) {
        let c2da_fresh34 : int = int(uint(c2da_mem[mobj + 96]) | uint(c2da_mem[mobj + 97]) << 0x8 | uint(c2da_mem[mobj + 98]) << 0x10 | uint(c2da_mem[mobj + 99]) << 0x18)
        let c2da_fresh35 : uint = uint(c2da_fresh34)
        c2da_mem[mobj + 32] = uint8(c2da_fresh35)
        c2da_mem[mobj + 33] = uint8(c2da_fresh35 >> 0x8)
        c2da_mem[mobj + 34] = uint8(c2da_fresh35 >> 0x10)
        c2da_mem[mobj + 35] = uint8(c2da_fresh35 >> 0x18)
    } elif (z_0 == 2147483647) {
        let c2da_fresh36 : int = int(uint(c2da_mem[mobj + 136]) | uint(c2da_mem[mobj + 137]) << 0x8 | uint(c2da_mem[mobj + 138]) << 0x10 | uint(c2da_mem[mobj + 139]) << 0x18) + 68
        let c2da_fresh37 : int = int(uint(c2da_mem[mobj + 100]) | uint(c2da_mem[mobj + 101]) << 0x8 | uint(c2da_mem[mobj + 102]) << 0x10 | uint(c2da_mem[mobj + 103]) << 0x18) - int(uint(c2da_mem[c2da_fresh36]) | uint(c2da_mem[c2da_fresh36 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh36 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh36 + 3]) << 0x18)
        let c2da_fresh38 : uint = uint(c2da_fresh37)
        c2da_mem[mobj + 32] = uint8(c2da_fresh38)
        c2da_mem[mobj + 33] = uint8(c2da_fresh38 >> 0x8)
        c2da_mem[mobj + 34] = uint8(c2da_fresh38 >> 0x10)
        c2da_mem[mobj + 35] = uint8(c2da_fresh38 >> 0x18)
    } else {
        let c2da_fresh39 : uint = uint(z_0)
        c2da_mem[mobj + 32] = uint8(c2da_fresh39)
        c2da_mem[mobj + 33] = uint8(c2da_fresh39 >> 0x8)
        c2da_mem[mobj + 34] = uint8(c2da_fresh39 >> 0x10)
        c2da_mem[mobj + 35] = uint8(c2da_fresh39 >> 0x18)
    }
    let c2da_fresh40 : uint = 126u
    c2da_mem[mobj + 16] = uint8(c2da_fresh40)
    c2da_mem[mobj + 17] = uint8(c2da_fresh40 >> 0x8)
    c2da_mem[mobj + 18] = uint8(c2da_fresh40 >> 0x10)
    c2da_mem[mobj + 19] = uint8(c2da_fresh40 >> 0x18)
    c2da_mem[mobj + 20] = 0u8
    c2da_mem[mobj + 21] = 0u8
    c2da_mem[mobj + 22] = 0u8
    c2da_mem[mobj + 23] = 0u8
    P_AddThinker(mobj)
    return mobj
}
[export, sideeffects]
def P_MobjThinker(var mobj_0 : int) {
    if (int(uint(c2da_mem[mobj_0 + 112]) | uint(c2da_mem[mobj_0 + 113]) << 0x8 | uint(c2da_mem[mobj_0 + 114]) << 0x10 | uint(c2da_mem[mobj_0 + 115]) << 0x18) != 0 || int(uint(c2da_mem[mobj_0 + 116]) | uint(c2da_mem[mobj_0 + 117]) << 0x8 | uint(c2da_mem[mobj_0 + 118]) << 0x10 | uint(c2da_mem[mobj_0 + 119]) << 0x18) != 0 || (int(uint(c2da_mem[mobj_0 + 160]) | uint(c2da_mem[mobj_0 + 161]) << 0x8 | uint(c2da_mem[mobj_0 + 162]) << 0x10 | uint(c2da_mem[mobj_0 + 163]) << 0x18) & 16777216) != 0) {
        P_XYMovement(mobj_0)
        if (int(uint(c2da_mem[mobj_0 + 16]) | uint(c2da_mem[mobj_0 + 17]) << 0x8 | uint(c2da_mem[mobj_0 + 18]) << 0x10 | uint(c2da_mem[mobj_0 + 19]) << 0x18) == -1) {
            return
        }
    }
    if (int(uint(c2da_mem[mobj_0 + 32]) | uint(c2da_mem[mobj_0 + 33]) << 0x8 | uint(c2da_mem[mobj_0 + 34]) << 0x10 | uint(c2da_mem[mobj_0 + 35]) << 0x18) != int(uint(c2da_mem[mobj_0 + 96]) | uint(c2da_mem[mobj_0 + 97]) << 0x8 | uint(c2da_mem[mobj_0 + 98]) << 0x10 | uint(c2da_mem[mobj_0 + 99]) << 0x18) || int(uint(c2da_mem[mobj_0 + 120]) | uint(c2da_mem[mobj_0 + 121]) << 0x8 | uint(c2da_mem[mobj_0 + 122]) << 0x10 | uint(c2da_mem[mobj_0 + 123]) << 0x18) != 0) {
        P_ZMovement(mobj_0)
        if (int(uint(c2da_mem[mobj_0 + 16]) | uint(c2da_mem[mobj_0 + 17]) << 0x8 | uint(c2da_mem[mobj_0 + 18]) << 0x10 | uint(c2da_mem[mobj_0 + 19]) << 0x18) == -1) {
            return
        }
    }
    if (int(uint(c2da_mem[mobj_0 + 144]) | uint(c2da_mem[mobj_0 + 145]) << 0x8 | uint(c2da_mem[mobj_0 + 146]) << 0x10 | uint(c2da_mem[mobj_0 + 147]) << 0x18) != -1) {
        let c2da_fresh41 : int = int(uint(c2da_mem[mobj_0 + 144]) | uint(c2da_mem[mobj_0 + 145]) << 0x8 | uint(c2da_mem[mobj_0 + 146]) << 0x10 | uint(c2da_mem[mobj_0 + 147]) << 0x18)
        let c2da_fresh42 : int = c2da_fresh41 - 1
        let c2da_fresh43 : uint = uint(c2da_fresh42)
        c2da_mem[mobj_0 + 144] = uint8(c2da_fresh43)
        c2da_mem[mobj_0 + 145] = uint8(c2da_fresh43 >> 0x8)
        c2da_mem[mobj_0 + 146] = uint8(c2da_fresh43 >> 0x10)
        c2da_mem[mobj_0 + 147] = uint8(c2da_fresh43 >> 0x18)
        if (int(uint(c2da_mem[mobj_0 + 144]) | uint(c2da_mem[mobj_0 + 145]) << 0x8 | uint(c2da_mem[mobj_0 + 146]) << 0x10 | uint(c2da_mem[mobj_0 + 147]) << 0x18) == 0) {
            let c2da_fresh44 : int = int(uint(c2da_mem[mobj_0 + 152]) | uint(c2da_mem[mobj_0 + 153]) << 0x8 | uint(c2da_mem[mobj_0 + 154]) << 0x10 | uint(c2da_mem[mobj_0 + 155]) << 0x18) + 24
            if (P_SetMobjState(mobj_0, uint(c2da_mem[c2da_fresh44]) | uint(c2da_mem[c2da_fresh44 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh44 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh44 + 3]) << 0x18) == 0) {
                return
            }
        }
    } else {
        if ((int(uint(c2da_mem[mobj_0 + 160]) | uint(c2da_mem[mobj_0 + 161]) << 0x8 | uint(c2da_mem[mobj_0 + 162]) << 0x10 | uint(c2da_mem[mobj_0 + 163]) << 0x18) & 4194304) == 0) {
            return
        }
        if (respawnmonsters == 0) {
            return
        }
        let c2da_fresh45 : int = int(uint(c2da_mem[mobj_0 + 172]) | uint(c2da_mem[mobj_0 + 173]) << 0x8 | uint(c2da_mem[mobj_0 + 174]) << 0x10 | uint(c2da_mem[mobj_0 + 175]) << 0x18)
        let c2da_fresh46 : int = c2da_fresh45 + 1
        let c2da_fresh47 : uint = uint(c2da_fresh46)
        c2da_mem[mobj_0 + 172] = uint8(c2da_fresh47)
        c2da_mem[mobj_0 + 173] = uint8(c2da_fresh47 >> 0x8)
        c2da_mem[mobj_0 + 174] = uint8(c2da_fresh47 >> 0x10)
        c2da_mem[mobj_0 + 175] = uint8(c2da_fresh47 >> 0x18)
        if (int(uint(c2da_mem[mobj_0 + 172]) | uint(c2da_mem[mobj_0 + 173]) << 0x8 | uint(c2da_mem[mobj_0 + 174]) << 0x10 | uint(c2da_mem[mobj_0 + 175]) << 0x18) < 12 * 35) {
            return
        }
        if ((leveltime & 31) != 0) {
            return
        }
        if (P_Random() > 4) {
            return
        }
        P_NightmareRespawn(mobj_0)
    }
    return
}
[export, sideeffects]
def P_NightmareRespawn(var mobj_1 : int) {
    var x_1 : int
    var y_1 : int
    var z_1 : int
    var ss_0 : int
    var mo_0 : int
    var mthing_0 : int
    x_1 = int(int16(uint(c2da_mem[mobj_1 + 204]) | uint(c2da_mem[mobj_1 + 205]) << 0x8)) << 16
    y_1 = int(int16(uint(c2da_mem[mobj_1 + 206]) | uint(c2da_mem[mobj_1 + 207]) << 0x8)) << 16
    if (P_CheckPosition(mobj_1, x_1, y_1) == 0) {
        return
    }
    let c2da_fresh48 : int = int(uint(c2da_mem[mobj_1 + 88]) | uint(c2da_mem[mobj_1 + 89]) << 0x8 | uint(c2da_mem[mobj_1 + 90]) << 0x10 | uint(c2da_mem[mobj_1 + 91]) << 0x18)
    let c2da_fresh49 : int = int(uint(c2da_mem[c2da_fresh48]) | uint(c2da_mem[c2da_fresh48 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh48 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh48 + 3]) << 0x18)
    mo_0 = P_SpawnMobj(int(uint(c2da_mem[mobj_1 + 24]) | uint(c2da_mem[mobj_1 + 25]) << 0x8 | uint(c2da_mem[mobj_1 + 26]) << 0x10 | uint(c2da_mem[mobj_1 + 27]) << 0x18), int(uint(c2da_mem[mobj_1 + 28]) | uint(c2da_mem[mobj_1 + 29]) << 0x8 | uint(c2da_mem[mobj_1 + 30]) << 0x10 | uint(c2da_mem[mobj_1 + 31]) << 0x18), int(uint(c2da_mem[c2da_fresh49]) | uint(c2da_mem[c2da_fresh49 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh49 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh49 + 3]) << 0x18), 39u)
    S_StartSound(mo_0, 35)
    ss_0 = R_PointInSubsector(x_1, y_1)
    let c2da_fresh50 : int = int(uint(c2da_mem[ss_0]) | uint(c2da_mem[ss_0 + 1]) << 0x8 | uint(c2da_mem[ss_0 + 2]) << 0x10 | uint(c2da_mem[ss_0 + 3]) << 0x18)
    mo_0 = P_SpawnMobj(x_1, y_1, int(uint(c2da_mem[c2da_fresh50]) | uint(c2da_mem[c2da_fresh50 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh50 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh50 + 3]) << 0x18), 39u)
    S_StartSound(mo_0, 35)
    mthing_0 = mobj_1 + 204
    let c2da_fresh51 : int = int(uint(c2da_mem[mobj_1 + 136]) | uint(c2da_mem[mobj_1 + 137]) << 0x8 | uint(c2da_mem[mobj_1 + 138]) << 0x10 | uint(c2da_mem[mobj_1 + 139]) << 0x18) + 84
    if ((int(uint(c2da_mem[c2da_fresh51]) | uint(c2da_mem[c2da_fresh51 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh51 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh51 + 3]) << 0x18) & 256) != 0) {
        z_1 = 2147483647
    } else {
        z_1 = -2147483647 - 1
    }
    mo_0 = P_SpawnMobj(x_1, y_1, z_1, uint(c2da_mem[mobj_1 + 128]) | uint(c2da_mem[mobj_1 + 129]) << 0x8 | uint(c2da_mem[mobj_1 + 130]) << 0x10 | uint(c2da_mem[mobj_1 + 131]) << 0x18)
    c2da_lin_memmove(mo_0 + 204, mobj_1 + 204, 10ul)
    let c2da_fresh52 : uint = uint(536870912 * (int(int16(uint(c2da_mem[mthing_0 + 4]) | uint(c2da_mem[mthing_0 + 5]) << 0x8)) / 45))
    let c2da_fresh53 : uint = c2da_fresh52
    c2da_mem[mo_0 + 56] = uint8(c2da_fresh53)
    c2da_mem[mo_0 + 57] = uint8(c2da_fresh53 >> 0x8)
    c2da_mem[mo_0 + 58] = uint8(c2da_fresh53 >> 0x10)
    c2da_mem[mo_0 + 59] = uint8(c2da_fresh53 >> 0x18)
    if ((int(int16(uint(c2da_mem[mthing_0 + 8]) | uint(c2da_mem[mthing_0 + 9]) << 0x8)) & 8) != 0) {
        let c2da_fresh54 : int = int(uint(c2da_mem[mo_0 + 160]) | uint(c2da_mem[mo_0 + 161]) << 0x8 | uint(c2da_mem[mo_0 + 162]) << 0x10 | uint(c2da_mem[mo_0 + 163]) << 0x18) | 32
        let c2da_fresh55 : uint = uint(c2da_fresh54)
        c2da_mem[mo_0 + 160] = uint8(c2da_fresh55)
        c2da_mem[mo_0 + 161] = uint8(c2da_fresh55 >> 0x8)
        c2da_mem[mo_0 + 162] = uint8(c2da_fresh55 >> 0x10)
        c2da_mem[mo_0 + 163] = uint8(c2da_fresh55 >> 0x18)
    }
    let c2da_fresh56 : int = 18
    let c2da_fresh57 : uint = uint(c2da_fresh56)
    c2da_mem[mo_0 + 184] = uint8(c2da_fresh57)
    c2da_mem[mo_0 + 185] = uint8(c2da_fresh57 >> 0x8)
    c2da_mem[mo_0 + 186] = uint8(c2da_fresh57 >> 0x10)
    c2da_mem[mo_0 + 187] = uint8(c2da_fresh57 >> 0x18)
    P_RemoveMobj(mobj_1)
    return
}
[export, sideeffects]
def P_RemoveMobj(var mobj_2 : int) {
    if ((int(uint(c2da_mem[mobj_2 + 160]) | uint(c2da_mem[mobj_2 + 161]) << 0x8 | uint(c2da_mem[mobj_2 + 162]) << 0x10 | uint(c2da_mem[mobj_2 + 163]) << 0x18) & 1) != 0 && (int(uint(c2da_mem[mobj_2 + 160]) | uint(c2da_mem[mobj_2 + 161]) << 0x8 | uint(c2da_mem[mobj_2 + 162]) << 0x10 | uint(c2da_mem[mobj_2 + 163]) << 0x18) & 131072) == 0 && (uint(c2da_mem[mobj_2 + 128]) | uint(c2da_mem[mobj_2 + 129]) << 0x8 | uint(c2da_mem[mobj_2 + 130]) << 0x10 | uint(c2da_mem[mobj_2 + 131]) << 0x18) != 56u && (uint(c2da_mem[mobj_2 + 128]) | uint(c2da_mem[mobj_2 + 129]) << 0x8 | uint(c2da_mem[mobj_2 + 130]) << 0x10 | uint(c2da_mem[mobj_2 + 131]) << 0x18) != 58u) {
        c2da_lin_memmove(49776 + iquehead * 10, mobj_2 + 204, 10ul)
        itemrespawntime[iquehead] = leveltime
        iquehead = iquehead + 1 & 128 - 1
        if (iquehead == iquetail) {
            iquetail = iquetail + 1 & 128 - 1
        }
    }
    P_UnsetThingPosition(mobj_2)
    S_StopSound(mobj_2)
    P_RemoveThinker(mobj_2)
    return
}
[export, sideeffects]
def P_SetMobjState(var mobj_3 : int; var state : uint) : uint {
    var st_0 : int
    while (true) {
        if (state == 0u) {
            let c2da_fresh58 : uint = 0u
            c2da_mem[mobj_3 + 152] = uint8(c2da_fresh58)
            c2da_mem[mobj_3 + 153] = uint8(c2da_fresh58 >> 0x8)
            c2da_mem[mobj_3 + 154] = uint8(c2da_fresh58 >> 0x10)
            c2da_mem[mobj_3 + 155] = uint8(c2da_fresh58 >> 0x18)
            c2da_mem[mobj_3 + 156] = 0u8
            c2da_mem[mobj_3 + 157] = 0u8
            c2da_mem[mobj_3 + 158] = 0u8
            c2da_mem[mobj_3 + 159] = 0u8
            P_RemoveMobj(mobj_3)
            return 0u
        }
        st_0 = 2080 + int(state) * 40
        let c2da_fresh59 : uint = uint(st_0)
        c2da_mem[mobj_3 + 152] = uint8(c2da_fresh59)
        c2da_mem[mobj_3 + 153] = uint8(c2da_fresh59 >> 0x8)
        c2da_mem[mobj_3 + 154] = uint8(c2da_fresh59 >> 0x10)
        c2da_mem[mobj_3 + 155] = uint8(c2da_fresh59 >> 0x18)
        c2da_mem[mobj_3 + 156] = 0u8
        c2da_mem[mobj_3 + 157] = 0u8
        c2da_mem[mobj_3 + 158] = 0u8
        c2da_mem[mobj_3 + 159] = 0u8
        let c2da_fresh60 : int = int(uint(c2da_mem[st_0 + 8]) | uint(c2da_mem[st_0 + 9]) << 0x8 | uint(c2da_mem[st_0 + 10]) << 0x10 | uint(c2da_mem[st_0 + 11]) << 0x18)
        let c2da_fresh61 : uint = uint(c2da_fresh60)
        c2da_mem[mobj_3 + 144] = uint8(c2da_fresh61)
        c2da_mem[mobj_3 + 145] = uint8(c2da_fresh61 >> 0x8)
        c2da_mem[mobj_3 + 146] = uint8(c2da_fresh61 >> 0x10)
        c2da_mem[mobj_3 + 147] = uint8(c2da_fresh61 >> 0x18)
        let c2da_fresh62 : uint = uint(c2da_mem[st_0]) | uint(c2da_mem[st_0 + 1]) << 0x8 | uint(c2da_mem[st_0 + 2]) << 0x10 | uint(c2da_mem[st_0 + 3]) << 0x18
        let c2da_fresh63 : uint = c2da_fresh62
        c2da_mem[mobj_3 + 60] = uint8(c2da_fresh63)
        c2da_mem[mobj_3 + 61] = uint8(c2da_fresh63 >> 0x8)
        c2da_mem[mobj_3 + 62] = uint8(c2da_fresh63 >> 0x10)
        c2da_mem[mobj_3 + 63] = uint8(c2da_fresh63 >> 0x18)
        let c2da_fresh64 : int = int(uint(c2da_mem[st_0 + 4]) | uint(c2da_mem[st_0 + 5]) << 0x8 | uint(c2da_mem[st_0 + 6]) << 0x10 | uint(c2da_mem[st_0 + 7]) << 0x18)
        let c2da_fresh65 : uint = uint(c2da_fresh64)
        c2da_mem[mobj_3 + 64] = uint8(c2da_fresh65)
        c2da_mem[mobj_3 + 65] = uint8(c2da_fresh65 >> 0x8)
        c2da_mem[mobj_3 + 66] = uint8(c2da_fresh65 >> 0x10)
        c2da_mem[mobj_3 + 67] = uint8(c2da_fresh65 >> 0x18)
        if (int(uint(c2da_mem[st_0 + 16]) | uint(c2da_mem[st_0 + 17]) << 0x8 | uint(c2da_mem[st_0 + 18]) << 0x10 | uint(c2da_mem[st_0 + 19]) << 0x18) != default<actionf_p1>) {
            invoke(c2da_fn_table5[int(uint(c2da_mem[st_0 + 16]) | uint(c2da_mem[st_0 + 17]) << 0x8 | uint(c2da_mem[st_0 + 18]) << 0x10 | uint(c2da_mem[st_0 + 19]) << 0x18)], mobj_3)
        }
        state = uint(c2da_mem[st_0 + 24]) | uint(c2da_mem[st_0 + 25]) << 0x8 | uint(c2da_mem[st_0 + 26]) << 0x10 | uint(c2da_mem[st_0 + 27]) << 0x18
        if (int(uint(c2da_mem[mobj_3 + 144]) | uint(c2da_mem[mobj_3 + 145]) << 0x8 | uint(c2da_mem[mobj_3 + 146]) << 0x10 | uint(c2da_mem[mobj_3 + 147]) << 0x18) != 0) {
            break
        }
    }
    return 1u
}
[export, sideeffects]
def P_ZMovement(var mo_1 : int) {
    var dist : int
    var delta : int
    var correct_lost_soul_bounce : int
    if (int(uint(c2da_mem[mo_1 + 192]) | uint(c2da_mem[mo_1 + 193]) << 0x8 | uint(c2da_mem[mo_1 + 194]) << 0x10 | uint(c2da_mem[mo_1 + 195]) << 0x18) != 0 && int(uint(c2da_mem[mo_1 + 32]) | uint(c2da_mem[mo_1 + 33]) << 0x8 | uint(c2da_mem[mo_1 + 34]) << 0x10 | uint(c2da_mem[mo_1 + 35]) << 0x18) < int(uint(c2da_mem[mo_1 + 96]) | uint(c2da_mem[mo_1 + 97]) << 0x8 | uint(c2da_mem[mo_1 + 98]) << 0x10 | uint(c2da_mem[mo_1 + 99]) << 0x18)) {
        let c2da_fresh66 : int = int(uint(c2da_mem[mo_1 + 192]) | uint(c2da_mem[mo_1 + 193]) << 0x8 | uint(c2da_mem[mo_1 + 194]) << 0x10 | uint(c2da_mem[mo_1 + 195]) << 0x18) + 32
        let c2da_fresh67 : int = int(uint(c2da_mem[c2da_fresh66]) | uint(c2da_mem[c2da_fresh66 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh66 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh66 + 3]) << 0x18) - (int(uint(c2da_mem[mo_1 + 96]) | uint(c2da_mem[mo_1 + 97]) << 0x8 | uint(c2da_mem[mo_1 + 98]) << 0x10 | uint(c2da_mem[mo_1 + 99]) << 0x18) - int(uint(c2da_mem[mo_1 + 32]) | uint(c2da_mem[mo_1 + 33]) << 0x8 | uint(c2da_mem[mo_1 + 34]) << 0x10 | uint(c2da_mem[mo_1 + 35]) << 0x18))
        let c2da_fresh68 : uint = uint(c2da_fresh67)
        c2da_mem[c2da_fresh66] = uint8(c2da_fresh68)
        c2da_mem[c2da_fresh66 + 1] = uint8(c2da_fresh68 >> 0x8)
        c2da_mem[c2da_fresh66 + 2] = uint8(c2da_fresh68 >> 0x10)
        c2da_mem[c2da_fresh66 + 3] = uint8(c2da_fresh68 >> 0x18)
        let c2da_fresh69 : int = int(uint(c2da_mem[mo_1 + 192]) | uint(c2da_mem[mo_1 + 193]) << 0x8 | uint(c2da_mem[mo_1 + 194]) << 0x10 | uint(c2da_mem[mo_1 + 195]) << 0x18) + 36
        let c2da_fresh70 : int = int(uint(c2da_mem[mo_1 + 192]) | uint(c2da_mem[mo_1 + 193]) << 0x8 | uint(c2da_mem[mo_1 + 194]) << 0x10 | uint(c2da_mem[mo_1 + 195]) << 0x18) + 32
        let c2da_fresh71 : int = 41 * (1 << 16) - int(uint(c2da_mem[c2da_fresh70]) | uint(c2da_mem[c2da_fresh70 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh70 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh70 + 3]) << 0x18) >> 3
        let c2da_fresh72 : uint = uint(c2da_fresh71)
        c2da_mem[c2da_fresh69] = uint8(c2da_fresh72)
        c2da_mem[c2da_fresh69 + 1] = uint8(c2da_fresh72 >> 0x8)
        c2da_mem[c2da_fresh69 + 2] = uint8(c2da_fresh72 >> 0x10)
        c2da_mem[c2da_fresh69 + 3] = uint8(c2da_fresh72 >> 0x18)
    }
    let c2da_fresh73 : int = int(uint(c2da_mem[mo_1 + 32]) | uint(c2da_mem[mo_1 + 33]) << 0x8 | uint(c2da_mem[mo_1 + 34]) << 0x10 | uint(c2da_mem[mo_1 + 35]) << 0x18) + int(uint(c2da_mem[mo_1 + 120]) | uint(c2da_mem[mo_1 + 121]) << 0x8 | uint(c2da_mem[mo_1 + 122]) << 0x10 | uint(c2da_mem[mo_1 + 123]) << 0x18)
    let c2da_fresh74 : uint = uint(c2da_fresh73)
    c2da_mem[mo_1 + 32] = uint8(c2da_fresh74)
    c2da_mem[mo_1 + 33] = uint8(c2da_fresh74 >> 0x8)
    c2da_mem[mo_1 + 34] = uint8(c2da_fresh74 >> 0x10)
    c2da_mem[mo_1 + 35] = uint8(c2da_fresh74 >> 0x18)
    if ((int(uint(c2da_mem[mo_1 + 160]) | uint(c2da_mem[mo_1 + 161]) << 0x8 | uint(c2da_mem[mo_1 + 162]) << 0x10 | uint(c2da_mem[mo_1 + 163]) << 0x18) & 16384) != 0 && int(uint(c2da_mem[mo_1 + 176]) | uint(c2da_mem[mo_1 + 177]) << 0x8 | uint(c2da_mem[mo_1 + 178]) << 0x10 | uint(c2da_mem[mo_1 + 179]) << 0x18) != 0) {
        if ((int(uint(c2da_mem[mo_1 + 160]) | uint(c2da_mem[mo_1 + 161]) << 0x8 | uint(c2da_mem[mo_1 + 162]) << 0x10 | uint(c2da_mem[mo_1 + 163]) << 0x18) & 16777216) == 0 && (int(uint(c2da_mem[mo_1 + 160]) | uint(c2da_mem[mo_1 + 161]) << 0x8 | uint(c2da_mem[mo_1 + 162]) << 0x10 | uint(c2da_mem[mo_1 + 163]) << 0x18) & 2097152) == 0) {
            let c2da_fresh75 : int = int(uint(c2da_mem[mo_1 + 176]) | uint(c2da_mem[mo_1 + 177]) << 0x8 | uint(c2da_mem[mo_1 + 178]) << 0x10 | uint(c2da_mem[mo_1 + 179]) << 0x18) + 24
            let c2da_fresh76 : int = int(uint(c2da_mem[mo_1 + 176]) | uint(c2da_mem[mo_1 + 177]) << 0x8 | uint(c2da_mem[mo_1 + 178]) << 0x10 | uint(c2da_mem[mo_1 + 179]) << 0x18) + 28
            dist = P_AproxDistance(int(uint(c2da_mem[mo_1 + 24]) | uint(c2da_mem[mo_1 + 25]) << 0x8 | uint(c2da_mem[mo_1 + 26]) << 0x10 | uint(c2da_mem[mo_1 + 27]) << 0x18) - int(uint(c2da_mem[c2da_fresh75]) | uint(c2da_mem[c2da_fresh75 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh75 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh75 + 3]) << 0x18), int(uint(c2da_mem[mo_1 + 28]) | uint(c2da_mem[mo_1 + 29]) << 0x8 | uint(c2da_mem[mo_1 + 30]) << 0x10 | uint(c2da_mem[mo_1 + 31]) << 0x18) - int(uint(c2da_mem[c2da_fresh76]) | uint(c2da_mem[c2da_fresh76 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh76 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh76 + 3]) << 0x18))
            let c2da_fresh77 : int = int(uint(c2da_mem[mo_1 + 176]) | uint(c2da_mem[mo_1 + 177]) << 0x8 | uint(c2da_mem[mo_1 + 178]) << 0x10 | uint(c2da_mem[mo_1 + 179]) << 0x18) + 32
            delta = int(uint(c2da_mem[c2da_fresh77]) | uint(c2da_mem[c2da_fresh77 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh77 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh77 + 3]) << 0x18) + (int(uint(c2da_mem[mo_1 + 108]) | uint(c2da_mem[mo_1 + 109]) << 0x8 | uint(c2da_mem[mo_1 + 110]) << 0x10 | uint(c2da_mem[mo_1 + 111]) << 0x18) >> 1) - int(uint(c2da_mem[mo_1 + 32]) | uint(c2da_mem[mo_1 + 33]) << 0x8 | uint(c2da_mem[mo_1 + 34]) << 0x10 | uint(c2da_mem[mo_1 + 35]) << 0x18)
            if (delta < 0 && dist < -(delta * 3)) {
                let c2da_fresh78 : int = int(uint(c2da_mem[mo_1 + 32]) | uint(c2da_mem[mo_1 + 33]) << 0x8 | uint(c2da_mem[mo_1 + 34]) << 0x10 | uint(c2da_mem[mo_1 + 35]) << 0x18) - (1 << 16) * 4
                let c2da_fresh79 : uint = uint(c2da_fresh78)
                c2da_mem[mo_1 + 32] = uint8(c2da_fresh79)
                c2da_mem[mo_1 + 33] = uint8(c2da_fresh79 >> 0x8)
                c2da_mem[mo_1 + 34] = uint8(c2da_fresh79 >> 0x10)
                c2da_mem[mo_1 + 35] = uint8(c2da_fresh79 >> 0x18)
            } elif (delta > 0 && dist < delta * 3) {
                let c2da_fresh80 : int = int(uint(c2da_mem[mo_1 + 32]) | uint(c2da_mem[mo_1 + 33]) << 0x8 | uint(c2da_mem[mo_1 + 34]) << 0x10 | uint(c2da_mem[mo_1 + 35]) << 0x18) + (1 << 16) * 4
                let c2da_fresh81 : uint = uint(c2da_fresh80)
                c2da_mem[mo_1 + 32] = uint8(c2da_fresh81)
                c2da_mem[mo_1 + 33] = uint8(c2da_fresh81 >> 0x8)
                c2da_mem[mo_1 + 34] = uint8(c2da_fresh81 >> 0x10)
                c2da_mem[mo_1 + 35] = uint8(c2da_fresh81 >> 0x18)
            }
        }
    }
    if (int(uint(c2da_mem[mo_1 + 32]) | uint(c2da_mem[mo_1 + 33]) << 0x8 | uint(c2da_mem[mo_1 + 34]) << 0x10 | uint(c2da_mem[mo_1 + 35]) << 0x18) <= int(uint(c2da_mem[mo_1 + 96]) | uint(c2da_mem[mo_1 + 97]) << 0x8 | uint(c2da_mem[mo_1 + 98]) << 0x10 | uint(c2da_mem[mo_1 + 99]) << 0x18)) {
        correct_lost_soul_bounce = uint(gameversion) >= 6u ? 1 : 0
        if (correct_lost_soul_bounce != 0 && (int(uint(c2da_mem[mo_1 + 160]) | uint(c2da_mem[mo_1 + 161]) << 0x8 | uint(c2da_mem[mo_1 + 162]) << 0x10 | uint(c2da_mem[mo_1 + 163]) << 0x18) & 16777216) != 0) {
            let c2da_fresh82 : int = -int(uint(c2da_mem[mo_1 + 120]) | uint(c2da_mem[mo_1 + 121]) << 0x8 | uint(c2da_mem[mo_1 + 122]) << 0x10 | uint(c2da_mem[mo_1 + 123]) << 0x18)
            let c2da_fresh83 : uint = uint(c2da_fresh82)
            c2da_mem[mo_1 + 120] = uint8(c2da_fresh83)
            c2da_mem[mo_1 + 121] = uint8(c2da_fresh83 >> 0x8)
            c2da_mem[mo_1 + 122] = uint8(c2da_fresh83 >> 0x10)
            c2da_mem[mo_1 + 123] = uint8(c2da_fresh83 >> 0x18)
        }
        if (int(uint(c2da_mem[mo_1 + 120]) | uint(c2da_mem[mo_1 + 121]) << 0x8 | uint(c2da_mem[mo_1 + 122]) << 0x10 | uint(c2da_mem[mo_1 + 123]) << 0x18) < 0) {
            if (int(uint(c2da_mem[mo_1 + 192]) | uint(c2da_mem[mo_1 + 193]) << 0x8 | uint(c2da_mem[mo_1 + 194]) << 0x10 | uint(c2da_mem[mo_1 + 195]) << 0x18) != 0 && int(uint(c2da_mem[mo_1 + 120]) | uint(c2da_mem[mo_1 + 121]) << 0x8 | uint(c2da_mem[mo_1 + 122]) << 0x10 | uint(c2da_mem[mo_1 + 123]) << 0x18) < -(1 << 16) * 8) {
                let c2da_fresh84 : int = int(uint(c2da_mem[mo_1 + 192]) | uint(c2da_mem[mo_1 + 193]) << 0x8 | uint(c2da_mem[mo_1 + 194]) << 0x10 | uint(c2da_mem[mo_1 + 195]) << 0x18) + 36
                let c2da_fresh85 : int = int(uint(c2da_mem[mo_1 + 120]) | uint(c2da_mem[mo_1 + 121]) << 0x8 | uint(c2da_mem[mo_1 + 122]) << 0x10 | uint(c2da_mem[mo_1 + 123]) << 0x18) >> 3
                let c2da_fresh86 : uint = uint(c2da_fresh85)
                c2da_mem[c2da_fresh84] = uint8(c2da_fresh86)
                c2da_mem[c2da_fresh84 + 1] = uint8(c2da_fresh86 >> 0x8)
                c2da_mem[c2da_fresh84 + 2] = uint8(c2da_fresh86 >> 0x10)
                c2da_mem[c2da_fresh84 + 3] = uint8(c2da_fresh86 >> 0x18)
                S_StartSound(mo_1, 34)
            }
            let c2da_fresh87 : int = 0
            let c2da_fresh88 : uint = uint(c2da_fresh87)
            c2da_mem[mo_1 + 120] = uint8(c2da_fresh88)
            c2da_mem[mo_1 + 121] = uint8(c2da_fresh88 >> 0x8)
            c2da_mem[mo_1 + 122] = uint8(c2da_fresh88 >> 0x10)
            c2da_mem[mo_1 + 123] = uint8(c2da_fresh88 >> 0x18)
        }
        let c2da_fresh89 : int = int(uint(c2da_mem[mo_1 + 96]) | uint(c2da_mem[mo_1 + 97]) << 0x8 | uint(c2da_mem[mo_1 + 98]) << 0x10 | uint(c2da_mem[mo_1 + 99]) << 0x18)
        let c2da_fresh90 : uint = uint(c2da_fresh89)
        c2da_mem[mo_1 + 32] = uint8(c2da_fresh90)
        c2da_mem[mo_1 + 33] = uint8(c2da_fresh90 >> 0x8)
        c2da_mem[mo_1 + 34] = uint8(c2da_fresh90 >> 0x10)
        c2da_mem[mo_1 + 35] = uint8(c2da_fresh90 >> 0x18)
        if (correct_lost_soul_bounce == 0 && (int(uint(c2da_mem[mo_1 + 160]) | uint(c2da_mem[mo_1 + 161]) << 0x8 | uint(c2da_mem[mo_1 + 162]) << 0x10 | uint(c2da_mem[mo_1 + 163]) << 0x18) & 16777216) != 0) {
            let c2da_fresh91 : int = -int(uint(c2da_mem[mo_1 + 120]) | uint(c2da_mem[mo_1 + 121]) << 0x8 | uint(c2da_mem[mo_1 + 122]) << 0x10 | uint(c2da_mem[mo_1 + 123]) << 0x18)
            let c2da_fresh92 : uint = uint(c2da_fresh91)
            c2da_mem[mo_1 + 120] = uint8(c2da_fresh92)
            c2da_mem[mo_1 + 121] = uint8(c2da_fresh92 >> 0x8)
            c2da_mem[mo_1 + 122] = uint8(c2da_fresh92 >> 0x10)
            c2da_mem[mo_1 + 123] = uint8(c2da_fresh92 >> 0x18)
        }
        if ((int(uint(c2da_mem[mo_1 + 160]) | uint(c2da_mem[mo_1 + 161]) << 0x8 | uint(c2da_mem[mo_1 + 162]) << 0x10 | uint(c2da_mem[mo_1 + 163]) << 0x18) & 65536) != 0 && (int(uint(c2da_mem[mo_1 + 160]) | uint(c2da_mem[mo_1 + 161]) << 0x8 | uint(c2da_mem[mo_1 + 162]) << 0x10 | uint(c2da_mem[mo_1 + 163]) << 0x18) & 4096) == 0) {
            P_ExplodeMissile(mo_1)
            return
        }
    } elif ((int(uint(c2da_mem[mo_1 + 160]) | uint(c2da_mem[mo_1 + 161]) << 0x8 | uint(c2da_mem[mo_1 + 162]) << 0x10 | uint(c2da_mem[mo_1 + 163]) << 0x18) & 512) == 0) {
        if (int(uint(c2da_mem[mo_1 + 120]) | uint(c2da_mem[mo_1 + 121]) << 0x8 | uint(c2da_mem[mo_1 + 122]) << 0x10 | uint(c2da_mem[mo_1 + 123]) << 0x18) == 0) {
            let c2da_fresh93 : int = -(1 << 16) * 2
            let c2da_fresh94 : uint = uint(c2da_fresh93)
            c2da_mem[mo_1 + 120] = uint8(c2da_fresh94)
            c2da_mem[mo_1 + 121] = uint8(c2da_fresh94 >> 0x8)
            c2da_mem[mo_1 + 122] = uint8(c2da_fresh94 >> 0x10)
            c2da_mem[mo_1 + 123] = uint8(c2da_fresh94 >> 0x18)
        } else {
            let c2da_fresh95 : int = int(uint(c2da_mem[mo_1 + 120]) | uint(c2da_mem[mo_1 + 121]) << 0x8 | uint(c2da_mem[mo_1 + 122]) << 0x10 | uint(c2da_mem[mo_1 + 123]) << 0x18) - (1 << 16)
            let c2da_fresh96 : uint = uint(c2da_fresh95)
            c2da_mem[mo_1 + 120] = uint8(c2da_fresh96)
            c2da_mem[mo_1 + 121] = uint8(c2da_fresh96 >> 0x8)
            c2da_mem[mo_1 + 122] = uint8(c2da_fresh96 >> 0x10)
            c2da_mem[mo_1 + 123] = uint8(c2da_fresh96 >> 0x18)
        }
    }
    if (int(uint(c2da_mem[mo_1 + 32]) | uint(c2da_mem[mo_1 + 33]) << 0x8 | uint(c2da_mem[mo_1 + 34]) << 0x10 | uint(c2da_mem[mo_1 + 35]) << 0x18) + int(uint(c2da_mem[mo_1 + 108]) | uint(c2da_mem[mo_1 + 109]) << 0x8 | uint(c2da_mem[mo_1 + 110]) << 0x10 | uint(c2da_mem[mo_1 + 111]) << 0x18) > int(uint(c2da_mem[mo_1 + 100]) | uint(c2da_mem[mo_1 + 101]) << 0x8 | uint(c2da_mem[mo_1 + 102]) << 0x10 | uint(c2da_mem[mo_1 + 103]) << 0x18)) {
        if (int(uint(c2da_mem[mo_1 + 120]) | uint(c2da_mem[mo_1 + 121]) << 0x8 | uint(c2da_mem[mo_1 + 122]) << 0x10 | uint(c2da_mem[mo_1 + 123]) << 0x18) > 0) {
            let c2da_fresh97 : int = 0
            let c2da_fresh98 : uint = uint(c2da_fresh97)
            c2da_mem[mo_1 + 120] = uint8(c2da_fresh98)
            c2da_mem[mo_1 + 121] = uint8(c2da_fresh98 >> 0x8)
            c2da_mem[mo_1 + 122] = uint8(c2da_fresh98 >> 0x10)
            c2da_mem[mo_1 + 123] = uint8(c2da_fresh98 >> 0x18)
        }
        let c2da_fresh99 : int = int(uint(c2da_mem[mo_1 + 100]) | uint(c2da_mem[mo_1 + 101]) << 0x8 | uint(c2da_mem[mo_1 + 102]) << 0x10 | uint(c2da_mem[mo_1 + 103]) << 0x18) - int(uint(c2da_mem[mo_1 + 108]) | uint(c2da_mem[mo_1 + 109]) << 0x8 | uint(c2da_mem[mo_1 + 110]) << 0x10 | uint(c2da_mem[mo_1 + 111]) << 0x18)
        let c2da_fresh100 : uint = uint(c2da_fresh99)
        c2da_mem[mo_1 + 32] = uint8(c2da_fresh100)
        c2da_mem[mo_1 + 33] = uint8(c2da_fresh100 >> 0x8)
        c2da_mem[mo_1 + 34] = uint8(c2da_fresh100 >> 0x10)
        c2da_mem[mo_1 + 35] = uint8(c2da_fresh100 >> 0x18)
        if ((int(uint(c2da_mem[mo_1 + 160]) | uint(c2da_mem[mo_1 + 161]) << 0x8 | uint(c2da_mem[mo_1 + 162]) << 0x10 | uint(c2da_mem[mo_1 + 163]) << 0x18) & 16777216) != 0) {
            let c2da_fresh101 : int = -int(uint(c2da_mem[mo_1 + 120]) | uint(c2da_mem[mo_1 + 121]) << 0x8 | uint(c2da_mem[mo_1 + 122]) << 0x10 | uint(c2da_mem[mo_1 + 123]) << 0x18)
            let c2da_fresh102 : uint = uint(c2da_fresh101)
            c2da_mem[mo_1 + 120] = uint8(c2da_fresh102)
            c2da_mem[mo_1 + 121] = uint8(c2da_fresh102 >> 0x8)
            c2da_mem[mo_1 + 122] = uint8(c2da_fresh102 >> 0x10)
            c2da_mem[mo_1 + 123] = uint8(c2da_fresh102 >> 0x18)
        }
        if ((int(uint(c2da_mem[mo_1 + 160]) | uint(c2da_mem[mo_1 + 161]) << 0x8 | uint(c2da_mem[mo_1 + 162]) << 0x10 | uint(c2da_mem[mo_1 + 163]) << 0x18) & 65536) != 0 && (int(uint(c2da_mem[mo_1 + 160]) | uint(c2da_mem[mo_1 + 161]) << 0x8 | uint(c2da_mem[mo_1 + 162]) << 0x10 | uint(c2da_mem[mo_1 + 163]) << 0x18) & 4096) == 0) {
            P_ExplodeMissile(mo_1)
            return
        }
    }
    return
}
[export, sideeffects]
def P_ExplodeMissile(var mo_2 : int) {
    let c2da_fresh103 : int = 0
    let c2da_fresh104 : uint = uint(c2da_fresh103)
    c2da_mem[mo_2 + 120] = uint8(c2da_fresh104)
    c2da_mem[mo_2 + 121] = uint8(c2da_fresh104 >> 0x8)
    c2da_mem[mo_2 + 122] = uint8(c2da_fresh104 >> 0x10)
    c2da_mem[mo_2 + 123] = uint8(c2da_fresh104 >> 0x18)
    let c2da_fresh105 : uint = uint(c2da_fresh103)
    c2da_mem[mo_2 + 116] = uint8(c2da_fresh105)
    c2da_mem[mo_2 + 117] = uint8(c2da_fresh105 >> 0x8)
    c2da_mem[mo_2 + 118] = uint8(c2da_fresh105 >> 0x10)
    c2da_mem[mo_2 + 119] = uint8(c2da_fresh105 >> 0x18)
    let c2da_fresh106 : uint = uint(c2da_fresh103)
    c2da_mem[mo_2 + 112] = uint8(c2da_fresh106)
    c2da_mem[mo_2 + 113] = uint8(c2da_fresh106 >> 0x8)
    c2da_mem[mo_2 + 114] = uint8(c2da_fresh106 >> 0x10)
    c2da_mem[mo_2 + 115] = uint8(c2da_fresh106 >> 0x18)
    let c2da_fresh107 : int = 51056 + int(uint(c2da_mem[mo_2 + 128]) | uint(c2da_mem[mo_2 + 129]) << 0x8 | uint(c2da_mem[mo_2 + 130]) << 0x10 | uint(c2da_mem[mo_2 + 131]) << 0x18) * 92 + 48
    P_SetMobjState(mo_2, uint(int(uint(c2da_mem[c2da_fresh107]) | uint(c2da_mem[c2da_fresh107 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh107 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh107 + 3]) << 0x18)))
    let c2da_fresh108 : int = int(uint(c2da_mem[mo_2 + 144]) | uint(c2da_mem[mo_2 + 145]) << 0x8 | uint(c2da_mem[mo_2 + 146]) << 0x10 | uint(c2da_mem[mo_2 + 147]) << 0x18) - int(P_Random() & 3)
    let c2da_fresh109 : uint = uint(c2da_fresh108)
    c2da_mem[mo_2 + 144] = uint8(c2da_fresh109)
    c2da_mem[mo_2 + 145] = uint8(c2da_fresh109 >> 0x8)
    c2da_mem[mo_2 + 146] = uint8(c2da_fresh109 >> 0x10)
    c2da_mem[mo_2 + 147] = uint8(c2da_fresh109 >> 0x18)
    if (int(uint(c2da_mem[mo_2 + 144]) | uint(c2da_mem[mo_2 + 145]) << 0x8 | uint(c2da_mem[mo_2 + 146]) << 0x10 | uint(c2da_mem[mo_2 + 147]) << 0x18) < 1) {
        let c2da_fresh110 : int = 1
        let c2da_fresh111 : uint = uint(c2da_fresh110)
        c2da_mem[mo_2 + 144] = uint8(c2da_fresh111)
        c2da_mem[mo_2 + 145] = uint8(c2da_fresh111 >> 0x8)
        c2da_mem[mo_2 + 146] = uint8(c2da_fresh111 >> 0x10)
        c2da_mem[mo_2 + 147] = uint8(c2da_fresh111 >> 0x18)
    }
    let c2da_fresh112 : int = int(uint(c2da_mem[mo_2 + 160]) | uint(c2da_mem[mo_2 + 161]) << 0x8 | uint(c2da_mem[mo_2 + 162]) << 0x10 | uint(c2da_mem[mo_2 + 163]) << 0x18) & ~65536
    let c2da_fresh113 : uint = uint(c2da_fresh112)
    c2da_mem[mo_2 + 160] = uint8(c2da_fresh113)
    c2da_mem[mo_2 + 161] = uint8(c2da_fresh113 >> 0x8)
    c2da_mem[mo_2 + 162] = uint8(c2da_fresh113 >> 0x10)
    c2da_mem[mo_2 + 163] = uint8(c2da_fresh113 >> 0x18)
    let c2da_fresh114 : int = int(uint(c2da_mem[mo_2 + 136]) | uint(c2da_mem[mo_2 + 137]) << 0x8 | uint(c2da_mem[mo_2 + 138]) << 0x10 | uint(c2da_mem[mo_2 + 139]) << 0x18) + 56
    if (int(uint(c2da_mem[c2da_fresh114]) | uint(c2da_mem[c2da_fresh114 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh114 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh114 + 3]) << 0x18) != 0) {
        let c2da_fresh115 : int = int(uint(c2da_mem[mo_2 + 136]) | uint(c2da_mem[mo_2 + 137]) << 0x8 | uint(c2da_mem[mo_2 + 138]) << 0x10 | uint(c2da_mem[mo_2 + 139]) << 0x18) + 56
        S_StartSound(mo_2, int(uint(c2da_mem[c2da_fresh115]) | uint(c2da_mem[c2da_fresh115 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh115 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh115 + 3]) << 0x18))
    }
    return
}
[export, sideeffects]
def P_XYMovement(var mo_3 : int) {
    var ptryx : int
    var ptryy : int
    var player : int
    var xmove : int
    var ymove : int
    if (int(uint(c2da_mem[mo_3 + 112]) | uint(c2da_mem[mo_3 + 113]) << 0x8 | uint(c2da_mem[mo_3 + 114]) << 0x10 | uint(c2da_mem[mo_3 + 115]) << 0x18) == 0 && int(uint(c2da_mem[mo_3 + 116]) | uint(c2da_mem[mo_3 + 117]) << 0x8 | uint(c2da_mem[mo_3 + 118]) << 0x10 | uint(c2da_mem[mo_3 + 119]) << 0x18) == 0) {
        if ((int(uint(c2da_mem[mo_3 + 160]) | uint(c2da_mem[mo_3 + 161]) << 0x8 | uint(c2da_mem[mo_3 + 162]) << 0x10 | uint(c2da_mem[mo_3 + 163]) << 0x18) & 16777216) != 0) {
            let c2da_fresh116 : int = int(uint(c2da_mem[mo_3 + 160]) | uint(c2da_mem[mo_3 + 161]) << 0x8 | uint(c2da_mem[mo_3 + 162]) << 0x10 | uint(c2da_mem[mo_3 + 163]) << 0x18) & ~16777216
            let c2da_fresh117 : uint = uint(c2da_fresh116)
            c2da_mem[mo_3 + 160] = uint8(c2da_fresh117)
            c2da_mem[mo_3 + 161] = uint8(c2da_fresh117 >> 0x8)
            c2da_mem[mo_3 + 162] = uint8(c2da_fresh117 >> 0x10)
            c2da_mem[mo_3 + 163] = uint8(c2da_fresh117 >> 0x18)
            let c2da_fresh118 : int = 0
            let c2da_fresh119 : uint = uint(c2da_fresh118)
            c2da_mem[mo_3 + 120] = uint8(c2da_fresh119)
            c2da_mem[mo_3 + 121] = uint8(c2da_fresh119 >> 0x8)
            c2da_mem[mo_3 + 122] = uint8(c2da_fresh119 >> 0x10)
            c2da_mem[mo_3 + 123] = uint8(c2da_fresh119 >> 0x18)
            let c2da_fresh120 : uint = uint(c2da_fresh118)
            c2da_mem[mo_3 + 116] = uint8(c2da_fresh120)
            c2da_mem[mo_3 + 117] = uint8(c2da_fresh120 >> 0x8)
            c2da_mem[mo_3 + 118] = uint8(c2da_fresh120 >> 0x10)
            c2da_mem[mo_3 + 119] = uint8(c2da_fresh120 >> 0x18)
            let c2da_fresh121 : uint = uint(c2da_fresh118)
            c2da_mem[mo_3 + 112] = uint8(c2da_fresh121)
            c2da_mem[mo_3 + 113] = uint8(c2da_fresh121 >> 0x8)
            c2da_mem[mo_3 + 114] = uint8(c2da_fresh121 >> 0x10)
            c2da_mem[mo_3 + 115] = uint8(c2da_fresh121 >> 0x18)
            let c2da_fresh122 : int = int(uint(c2da_mem[mo_3 + 136]) | uint(c2da_mem[mo_3 + 137]) << 0x8 | uint(c2da_mem[mo_3 + 138]) << 0x10 | uint(c2da_mem[mo_3 + 139]) << 0x18) + 4
            P_SetMobjState(mo_3, uint(int(uint(c2da_mem[c2da_fresh122]) | uint(c2da_mem[c2da_fresh122 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh122 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh122 + 3]) << 0x18)))
        }
        return
    }
    player = int(uint(c2da_mem[mo_3 + 192]) | uint(c2da_mem[mo_3 + 193]) << 0x8 | uint(c2da_mem[mo_3 + 194]) << 0x10 | uint(c2da_mem[mo_3 + 195]) << 0x18)
    if (int(uint(c2da_mem[mo_3 + 112]) | uint(c2da_mem[mo_3 + 113]) << 0x8 | uint(c2da_mem[mo_3 + 114]) << 0x10 | uint(c2da_mem[mo_3 + 115]) << 0x18) > 30 * (1 << 16)) {
        let c2da_fresh123 : int = 30 * (1 << 16)
        let c2da_fresh124 : uint = uint(c2da_fresh123)
        c2da_mem[mo_3 + 112] = uint8(c2da_fresh124)
        c2da_mem[mo_3 + 113] = uint8(c2da_fresh124 >> 0x8)
        c2da_mem[mo_3 + 114] = uint8(c2da_fresh124 >> 0x10)
        c2da_mem[mo_3 + 115] = uint8(c2da_fresh124 >> 0x18)
    } elif (int(uint(c2da_mem[mo_3 + 112]) | uint(c2da_mem[mo_3 + 113]) << 0x8 | uint(c2da_mem[mo_3 + 114]) << 0x10 | uint(c2da_mem[mo_3 + 115]) << 0x18) < -(30 * (1 << 16))) {
        let c2da_fresh125 : int = -(30 * (1 << 16))
        let c2da_fresh126 : uint = uint(c2da_fresh125)
        c2da_mem[mo_3 + 112] = uint8(c2da_fresh126)
        c2da_mem[mo_3 + 113] = uint8(c2da_fresh126 >> 0x8)
        c2da_mem[mo_3 + 114] = uint8(c2da_fresh126 >> 0x10)
        c2da_mem[mo_3 + 115] = uint8(c2da_fresh126 >> 0x18)
    }
    if (int(uint(c2da_mem[mo_3 + 116]) | uint(c2da_mem[mo_3 + 117]) << 0x8 | uint(c2da_mem[mo_3 + 118]) << 0x10 | uint(c2da_mem[mo_3 + 119]) << 0x18) > 30 * (1 << 16)) {
        let c2da_fresh127 : int = 30 * (1 << 16)
        let c2da_fresh128 : uint = uint(c2da_fresh127)
        c2da_mem[mo_3 + 116] = uint8(c2da_fresh128)
        c2da_mem[mo_3 + 117] = uint8(c2da_fresh128 >> 0x8)
        c2da_mem[mo_3 + 118] = uint8(c2da_fresh128 >> 0x10)
        c2da_mem[mo_3 + 119] = uint8(c2da_fresh128 >> 0x18)
    } elif (int(uint(c2da_mem[mo_3 + 116]) | uint(c2da_mem[mo_3 + 117]) << 0x8 | uint(c2da_mem[mo_3 + 118]) << 0x10 | uint(c2da_mem[mo_3 + 119]) << 0x18) < -(30 * (1 << 16))) {
        let c2da_fresh129 : int = -(30 * (1 << 16))
        let c2da_fresh130 : uint = uint(c2da_fresh129)
        c2da_mem[mo_3 + 116] = uint8(c2da_fresh130)
        c2da_mem[mo_3 + 117] = uint8(c2da_fresh130 >> 0x8)
        c2da_mem[mo_3 + 118] = uint8(c2da_fresh130 >> 0x10)
        c2da_mem[mo_3 + 119] = uint8(c2da_fresh130 >> 0x18)
    }
    xmove = int(uint(c2da_mem[mo_3 + 112]) | uint(c2da_mem[mo_3 + 113]) << 0x8 | uint(c2da_mem[mo_3 + 114]) << 0x10 | uint(c2da_mem[mo_3 + 115]) << 0x18)
    ymove = int(uint(c2da_mem[mo_3 + 116]) | uint(c2da_mem[mo_3 + 117]) << 0x8 | uint(c2da_mem[mo_3 + 118]) << 0x10 | uint(c2da_mem[mo_3 + 119]) << 0x18)
    while (true) {
        if (xmove > 30 * (1 << 16) / 2 || ymove > 30 * (1 << 16) / 2) {
            ptryx = int(uint(c2da_mem[mo_3 + 24]) | uint(c2da_mem[mo_3 + 25]) << 0x8 | uint(c2da_mem[mo_3 + 26]) << 0x10 | uint(c2da_mem[mo_3 + 27]) << 0x18) + xmove / 2
            ptryy = int(uint(c2da_mem[mo_3 + 28]) | uint(c2da_mem[mo_3 + 29]) << 0x8 | uint(c2da_mem[mo_3 + 30]) << 0x10 | uint(c2da_mem[mo_3 + 31]) << 0x18) + ymove / 2
            xmove >>= 1
            ymove >>= 1
        } else {
            ptryx = int(uint(c2da_mem[mo_3 + 24]) | uint(c2da_mem[mo_3 + 25]) << 0x8 | uint(c2da_mem[mo_3 + 26]) << 0x10 | uint(c2da_mem[mo_3 + 27]) << 0x18) + xmove
            ptryy = int(uint(c2da_mem[mo_3 + 28]) | uint(c2da_mem[mo_3 + 29]) << 0x8 | uint(c2da_mem[mo_3 + 30]) << 0x10 | uint(c2da_mem[mo_3 + 31]) << 0x18) + ymove
            ymove = 0
            xmove = ymove
        }
        if (P_TryMove(mo_3, ptryx, ptryy) == 0) {
            if (int(uint(c2da_mem[mo_3 + 192]) | uint(c2da_mem[mo_3 + 193]) << 0x8 | uint(c2da_mem[mo_3 + 194]) << 0x10 | uint(c2da_mem[mo_3 + 195]) << 0x18) != 0) {
                P_SlideMove(mo_3)
            } elif ((int(uint(c2da_mem[mo_3 + 160]) | uint(c2da_mem[mo_3 + 161]) << 0x8 | uint(c2da_mem[mo_3 + 162]) << 0x10 | uint(c2da_mem[mo_3 + 163]) << 0x18) & 65536) != 0) {
                var c2da_fresh132 : int = 0
                if (ceilingline != 0 && int(uint(c2da_mem[ceilingline + 64]) | uint(c2da_mem[ceilingline + 65]) << 0x8 | uint(c2da_mem[ceilingline + 66]) << 0x10 | uint(c2da_mem[ceilingline + 67]) << 0x18) != 0) {
                    let c2da_fresh131 : int = int(uint(c2da_mem[ceilingline + 64]) | uint(c2da_mem[ceilingline + 65]) << 0x8 | uint(c2da_mem[ceilingline + 66]) << 0x10 | uint(c2da_mem[ceilingline + 67]) << 0x18) + 10
                    if (int(int16(uint(c2da_mem[c2da_fresh131]) | uint(c2da_mem[c2da_fresh131 + 1]) << 0x8)) == skyflatnum) {
                        c2da_fresh132 = 1
                    }
                }
                if (c2da_fresh132 != 0) {
                    P_RemoveMobj(mo_3)
                    return
                }
                P_ExplodeMissile(mo_3)
            } else {
                let c2da_fresh133 : int = 0
                let c2da_fresh134 : uint = uint(c2da_fresh133)
                c2da_mem[mo_3 + 116] = uint8(c2da_fresh134)
                c2da_mem[mo_3 + 117] = uint8(c2da_fresh134 >> 0x8)
                c2da_mem[mo_3 + 118] = uint8(c2da_fresh134 >> 0x10)
                c2da_mem[mo_3 + 119] = uint8(c2da_fresh134 >> 0x18)
                let c2da_fresh135 : uint = uint(c2da_fresh133)
                c2da_mem[mo_3 + 112] = uint8(c2da_fresh135)
                c2da_mem[mo_3 + 113] = uint8(c2da_fresh135 >> 0x8)
                c2da_mem[mo_3 + 114] = uint8(c2da_fresh135 >> 0x10)
                c2da_mem[mo_3 + 115] = uint8(c2da_fresh135 >> 0x18)
            }
        }
        if (!(xmove != 0 || ymove != 0)) {
            break
        }
    }
    if (player != 0 && (int(uint(c2da_mem[player + 208]) | uint(c2da_mem[player + 209]) << 0x8 | uint(c2da_mem[player + 210]) << 0x10 | uint(c2da_mem[player + 211]) << 0x18) & 4) != 0) {
        let c2da_fresh136 : int = 0
        let c2da_fresh137 : uint = uint(c2da_fresh136)
        c2da_mem[mo_3 + 116] = uint8(c2da_fresh137)
        c2da_mem[mo_3 + 117] = uint8(c2da_fresh137 >> 0x8)
        c2da_mem[mo_3 + 118] = uint8(c2da_fresh137 >> 0x10)
        c2da_mem[mo_3 + 119] = uint8(c2da_fresh137 >> 0x18)
        let c2da_fresh138 : uint = uint(c2da_fresh136)
        c2da_mem[mo_3 + 112] = uint8(c2da_fresh138)
        c2da_mem[mo_3 + 113] = uint8(c2da_fresh138 >> 0x8)
        c2da_mem[mo_3 + 114] = uint8(c2da_fresh138 >> 0x10)
        c2da_mem[mo_3 + 115] = uint8(c2da_fresh138 >> 0x18)
        return
    }
    if ((int(uint(c2da_mem[mo_3 + 160]) | uint(c2da_mem[mo_3 + 161]) << 0x8 | uint(c2da_mem[mo_3 + 162]) << 0x10 | uint(c2da_mem[mo_3 + 163]) << 0x18) & (65536 | 16777216)) != 0) {
        return
    }
    if (int(uint(c2da_mem[mo_3 + 32]) | uint(c2da_mem[mo_3 + 33]) << 0x8 | uint(c2da_mem[mo_3 + 34]) << 0x10 | uint(c2da_mem[mo_3 + 35]) << 0x18) > int(uint(c2da_mem[mo_3 + 96]) | uint(c2da_mem[mo_3 + 97]) << 0x8 | uint(c2da_mem[mo_3 + 98]) << 0x10 | uint(c2da_mem[mo_3 + 99]) << 0x18)) {
        return
    }
    if ((int(uint(c2da_mem[mo_3 + 160]) | uint(c2da_mem[mo_3 + 161]) << 0x8 | uint(c2da_mem[mo_3 + 162]) << 0x10 | uint(c2da_mem[mo_3 + 163]) << 0x18) & 1048576) != 0) {
        if (int(uint(c2da_mem[mo_3 + 112]) | uint(c2da_mem[mo_3 + 113]) << 0x8 | uint(c2da_mem[mo_3 + 114]) << 0x10 | uint(c2da_mem[mo_3 + 115]) << 0x18) > (1 << 16) / 4 || int(uint(c2da_mem[mo_3 + 112]) | uint(c2da_mem[mo_3 + 113]) << 0x8 | uint(c2da_mem[mo_3 + 114]) << 0x10 | uint(c2da_mem[mo_3 + 115]) << 0x18) < -(1 << 16) / 4 || int(uint(c2da_mem[mo_3 + 116]) | uint(c2da_mem[mo_3 + 117]) << 0x8 | uint(c2da_mem[mo_3 + 118]) << 0x10 | uint(c2da_mem[mo_3 + 119]) << 0x18) > (1 << 16) / 4 || int(uint(c2da_mem[mo_3 + 116]) | uint(c2da_mem[mo_3 + 117]) << 0x8 | uint(c2da_mem[mo_3 + 118]) << 0x10 | uint(c2da_mem[mo_3 + 119]) << 0x18) < -(1 << 16) / 4) {
            let c2da_fresh139 : int = int(uint(c2da_mem[mo_3 + 88]) | uint(c2da_mem[mo_3 + 89]) << 0x8 | uint(c2da_mem[mo_3 + 90]) << 0x10 | uint(c2da_mem[mo_3 + 91]) << 0x18)
            let c2da_fresh140 : int = int(uint(c2da_mem[c2da_fresh139]) | uint(c2da_mem[c2da_fresh139 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh139 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh139 + 3]) << 0x18)
            if (int(uint(c2da_mem[mo_3 + 96]) | uint(c2da_mem[mo_3 + 97]) << 0x8 | uint(c2da_mem[mo_3 + 98]) << 0x10 | uint(c2da_mem[mo_3 + 99]) << 0x18) != int(uint(c2da_mem[c2da_fresh140]) | uint(c2da_mem[c2da_fresh140 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh140 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh140 + 3]) << 0x18)) {
                return
            }
        }
    }
    if (int(uint(c2da_mem[mo_3 + 112]) | uint(c2da_mem[mo_3 + 113]) << 0x8 | uint(c2da_mem[mo_3 + 114]) << 0x10 | uint(c2da_mem[mo_3 + 115]) << 0x18) > -4096 && int(uint(c2da_mem[mo_3 + 112]) | uint(c2da_mem[mo_3 + 113]) << 0x8 | uint(c2da_mem[mo_3 + 114]) << 0x10 | uint(c2da_mem[mo_3 + 115]) << 0x18) < 4096 && int(uint(c2da_mem[mo_3 + 116]) | uint(c2da_mem[mo_3 + 117]) << 0x8 | uint(c2da_mem[mo_3 + 118]) << 0x10 | uint(c2da_mem[mo_3 + 119]) << 0x18) > -4096 && int(uint(c2da_mem[mo_3 + 116]) | uint(c2da_mem[mo_3 + 117]) << 0x8 | uint(c2da_mem[mo_3 + 118]) << 0x10 | uint(c2da_mem[mo_3 + 119]) << 0x18) < 4096 && (player == 0 || int(int8(c2da_mem[player + 12])) == 0 && int(int8(c2da_mem[player + 13])) == 0)) {
        var c2da_fresh142 : int = 0
        if (player != 0) {
            let c2da_fresh141 : int = int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18) + 152
            if (uint(int64((int(uint(c2da_mem[c2da_fresh141]) | uint(c2da_mem[c2da_fresh141 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh141 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh141 + 3]) << 0x18) - 2080) / 40) - 150l) < 4u) {
                c2da_fresh142 = 1
            }
        }
        if (c2da_fresh142 != 0) {
            P_SetMobjState(int(uint(c2da_mem[player]) | uint(c2da_mem[player + 1]) << 0x8 | uint(c2da_mem[player + 2]) << 0x10 | uint(c2da_mem[player + 3]) << 0x18), 149u)
        }
        let c2da_fresh143 : int = 0
        let c2da_fresh144 : uint = uint(c2da_fresh143)
        c2da_mem[mo_3 + 112] = uint8(c2da_fresh144)
        c2da_mem[mo_3 + 113] = uint8(c2da_fresh144 >> 0x8)
        c2da_mem[mo_3 + 114] = uint8(c2da_fresh144 >> 0x10)
        c2da_mem[mo_3 + 115] = uint8(c2da_fresh144 >> 0x18)
        let c2da_fresh145 : int = 0
        let c2da_fresh146 : uint = uint(c2da_fresh145)
        c2da_mem[mo_3 + 116] = uint8(c2da_fresh146)
        c2da_mem[mo_3 + 117] = uint8(c2da_fresh146 >> 0x8)
        c2da_mem[mo_3 + 118] = uint8(c2da_fresh146 >> 0x10)
        c2da_mem[mo_3 + 119] = uint8(c2da_fresh146 >> 0x18)
    } else {
        let c2da_fresh147 : int = FixedMul(int(uint(c2da_mem[mo_3 + 112]) | uint(c2da_mem[mo_3 + 113]) << 0x8 | uint(c2da_mem[mo_3 + 114]) << 0x10 | uint(c2da_mem[mo_3 + 115]) << 0x18), 59392)
        let c2da_fresh148 : uint = uint(c2da_fresh147)
        c2da_mem[mo_3 + 112] = uint8(c2da_fresh148)
        c2da_mem[mo_3 + 113] = uint8(c2da_fresh148 >> 0x8)
        c2da_mem[mo_3 + 114] = uint8(c2da_fresh148 >> 0x10)
        c2da_mem[mo_3 + 115] = uint8(c2da_fresh148 >> 0x18)
        let c2da_fresh149 : int = FixedMul(int(uint(c2da_mem[mo_3 + 116]) | uint(c2da_mem[mo_3 + 117]) << 0x8 | uint(c2da_mem[mo_3 + 118]) << 0x10 | uint(c2da_mem[mo_3 + 119]) << 0x18), 59392)
        let c2da_fresh150 : uint = uint(c2da_fresh149)
        c2da_mem[mo_3 + 116] = uint8(c2da_fresh150)
        c2da_mem[mo_3 + 117] = uint8(c2da_fresh150 >> 0x8)
        c2da_mem[mo_3 + 118] = uint8(c2da_fresh150 >> 0x10)
        c2da_mem[mo_3 + 119] = uint8(c2da_fresh150 >> 0x18)
    }
    return
}
[export, sideeffects]
def P_SubstNullMobj(var mobj_4 : int) : int {
    if (mobj_4 == 0) {
        let c2da_fresh151 : int = 0
        let c2da_fresh152 : uint = uint(c2da_fresh151)
        c2da_mem[360344] = uint8(c2da_fresh152)
        c2da_mem[360345] = uint8(c2da_fresh152 >> 0x8)
        c2da_mem[360346] = uint8(c2da_fresh152 >> 0x10)
        c2da_mem[360347] = uint8(c2da_fresh152 >> 0x18)
        let c2da_fresh153 : int = 0
        let c2da_fresh154 : uint = uint(c2da_fresh153)
        c2da_mem[360348] = uint8(c2da_fresh154)
        c2da_mem[360349] = uint8(c2da_fresh154 >> 0x8)
        c2da_mem[360350] = uint8(c2da_fresh154 >> 0x10)
        c2da_mem[360351] = uint8(c2da_fresh154 >> 0x18)
        let c2da_fresh155 : int = 0
        let c2da_fresh156 : uint = uint(c2da_fresh155)
        c2da_mem[360352] = uint8(c2da_fresh156)
        c2da_mem[360353] = uint8(c2da_fresh156 >> 0x8)
        c2da_mem[360354] = uint8(c2da_fresh156 >> 0x10)
        c2da_mem[360355] = uint8(c2da_fresh156 >> 0x18)
        let c2da_fresh157 : int = 0
        let c2da_fresh158 : uint = uint(c2da_fresh157)
        c2da_mem[360480] = uint8(c2da_fresh158)
        c2da_mem[360481] = uint8(c2da_fresh158 >> 0x8)
        c2da_mem[360482] = uint8(c2da_fresh158 >> 0x10)
        c2da_mem[360483] = uint8(c2da_fresh158 >> 0x18)
        mobj_4 = 360320
    }
    return mobj_4
}
[export, sideeffects]
def P_SpawnPuff(var x_2 : int; var y_3 : int; var z_2 : int) {
    var th : int
    z_2 = z_2 + (P_Random() - P_Random() << 10)
    th = P_SpawnMobj(x_2, y_3, z_2, 37u)
    let c2da_fresh159 : int = 1 << 16
    let c2da_fresh160 : uint = uint(c2da_fresh159)
    c2da_mem[th + 120] = uint8(c2da_fresh160)
    c2da_mem[th + 121] = uint8(c2da_fresh160 >> 0x8)
    c2da_mem[th + 122] = uint8(c2da_fresh160 >> 0x10)
    c2da_mem[th + 123] = uint8(c2da_fresh160 >> 0x18)
    let c2da_fresh161 : int = int(uint(c2da_mem[th + 144]) | uint(c2da_mem[th + 145]) << 0x8 | uint(c2da_mem[th + 146]) << 0x10 | uint(c2da_mem[th + 147]) << 0x18) - int(P_Random() & 3)
    let c2da_fresh162 : uint = uint(c2da_fresh161)
    c2da_mem[th + 144] = uint8(c2da_fresh162)
    c2da_mem[th + 145] = uint8(c2da_fresh162 >> 0x8)
    c2da_mem[th + 146] = uint8(c2da_fresh162 >> 0x10)
    c2da_mem[th + 147] = uint8(c2da_fresh162 >> 0x18)
    if (int(uint(c2da_mem[th + 144]) | uint(c2da_mem[th + 145]) << 0x8 | uint(c2da_mem[th + 146]) << 0x10 | uint(c2da_mem[th + 147]) << 0x18) < 1) {
        let c2da_fresh163 : int = 1
        let c2da_fresh164 : uint = uint(c2da_fresh163)
        c2da_mem[th + 144] = uint8(c2da_fresh164)
        c2da_mem[th + 145] = uint8(c2da_fresh164 >> 0x8)
        c2da_mem[th + 146] = uint8(c2da_fresh164 >> 0x10)
        c2da_mem[th + 147] = uint8(c2da_fresh164 >> 0x18)
    }
    if (attackrange == 64 * (1 << 16)) {
        P_SetMobjState(th, 95u)
    }
    return
}
[export, sideeffects]
def P_SpawnBlood(var x_3 : int; var y_4 : int; var z_3 : int; var damage : int) {
    var th_0 : int
    z_3 = z_3 + (P_Random() - P_Random() << 10)
    th_0 = P_SpawnMobj(x_3, y_4, z_3, 38u)
    let c2da_fresh165 : int = (1 << 16) * 2
    let c2da_fresh166 : uint = uint(c2da_fresh165)
    c2da_mem[th_0 + 120] = uint8(c2da_fresh166)
    c2da_mem[th_0 + 121] = uint8(c2da_fresh166 >> 0x8)
    c2da_mem[th_0 + 122] = uint8(c2da_fresh166 >> 0x10)
    c2da_mem[th_0 + 123] = uint8(c2da_fresh166 >> 0x18)
    let c2da_fresh167 : int = int(uint(c2da_mem[th_0 + 144]) | uint(c2da_mem[th_0 + 145]) << 0x8 | uint(c2da_mem[th_0 + 146]) << 0x10 | uint(c2da_mem[th_0 + 147]) << 0x18) - int(P_Random() & 3)
    let c2da_fresh168 : uint = uint(c2da_fresh167)
    c2da_mem[th_0 + 144] = uint8(c2da_fresh168)
    c2da_mem[th_0 + 145] = uint8(c2da_fresh168 >> 0x8)
    c2da_mem[th_0 + 146] = uint8(c2da_fresh168 >> 0x10)
    c2da_mem[th_0 + 147] = uint8(c2da_fresh168 >> 0x18)
    if (int(uint(c2da_mem[th_0 + 144]) | uint(c2da_mem[th_0 + 145]) << 0x8 | uint(c2da_mem[th_0 + 146]) << 0x10 | uint(c2da_mem[th_0 + 147]) << 0x18) < 1) {
        let c2da_fresh169 : int = 1
        let c2da_fresh170 : uint = uint(c2da_fresh169)
        c2da_mem[th_0 + 144] = uint8(c2da_fresh170)
        c2da_mem[th_0 + 145] = uint8(c2da_fresh170 >> 0x8)
        c2da_mem[th_0 + 146] = uint8(c2da_fresh170 >> 0x10)
        c2da_mem[th_0 + 147] = uint8(c2da_fresh170 >> 0x18)
    }
    if (damage <= 12 && damage >= 9) {
        P_SetMobjState(th_0, 91u)
    } elif (damage < 9) {
        P_SetMobjState(th_0, 92u)
    }
    return
}
[export, sideeffects]
def P_SpawnMissile(var source : int; var dest : int; var type_1 : uint) : int {
    var th_1 : int
    var an : uint
    var dist_0 : int
    th_1 = P_SpawnMobj(int(uint(c2da_mem[source + 24]) | uint(c2da_mem[source + 25]) << 0x8 | uint(c2da_mem[source + 26]) << 0x10 | uint(c2da_mem[source + 27]) << 0x18), int(uint(c2da_mem[source + 28]) | uint(c2da_mem[source + 29]) << 0x8 | uint(c2da_mem[source + 30]) << 0x10 | uint(c2da_mem[source + 31]) << 0x18), int(uint(c2da_mem[source + 32]) | uint(c2da_mem[source + 33]) << 0x8 | uint(c2da_mem[source + 34]) << 0x10 | uint(c2da_mem[source + 35]) << 0x18) + 4 * 8 * (1 << 16), type_1)
    let c2da_fresh171 : int = int(uint(c2da_mem[th_1 + 136]) | uint(c2da_mem[th_1 + 137]) << 0x8 | uint(c2da_mem[th_1 + 138]) << 0x10 | uint(c2da_mem[th_1 + 139]) << 0x18) + 16
    if (int(uint(c2da_mem[c2da_fresh171]) | uint(c2da_mem[c2da_fresh171 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh171 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh171 + 3]) << 0x18) != 0) {
        let c2da_fresh172 : int = int(uint(c2da_mem[th_1 + 136]) | uint(c2da_mem[th_1 + 137]) << 0x8 | uint(c2da_mem[th_1 + 138]) << 0x10 | uint(c2da_mem[th_1 + 139]) << 0x18) + 16
        S_StartSound(th_1, int(uint(c2da_mem[c2da_fresh172]) | uint(c2da_mem[c2da_fresh172 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh172 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh172 + 3]) << 0x18))
    }
    let c2da_fresh173 : uint = uint(source)
    c2da_mem[th_1 + 176] = uint8(c2da_fresh173)
    c2da_mem[th_1 + 177] = uint8(c2da_fresh173 >> 0x8)
    c2da_mem[th_1 + 178] = uint8(c2da_fresh173 >> 0x10)
    c2da_mem[th_1 + 179] = uint8(c2da_fresh173 >> 0x18)
    c2da_mem[th_1 + 180] = 0u8
    c2da_mem[th_1 + 181] = 0u8
    c2da_mem[th_1 + 182] = 0u8
    c2da_mem[th_1 + 183] = 0u8
    an = uint(R_PointToAngle2(int(uint(c2da_mem[source + 24]) | uint(c2da_mem[source + 25]) << 0x8 | uint(c2da_mem[source + 26]) << 0x10 | uint(c2da_mem[source + 27]) << 0x18), int(uint(c2da_mem[source + 28]) | uint(c2da_mem[source + 29]) << 0x8 | uint(c2da_mem[source + 30]) << 0x10 | uint(c2da_mem[source + 31]) << 0x18), int(uint(c2da_mem[dest + 24]) | uint(c2da_mem[dest + 25]) << 0x8 | uint(c2da_mem[dest + 26]) << 0x10 | uint(c2da_mem[dest + 27]) << 0x18), int(uint(c2da_mem[dest + 28]) | uint(c2da_mem[dest + 29]) << 0x8 | uint(c2da_mem[dest + 30]) << 0x10 | uint(c2da_mem[dest + 31]) << 0x18)))
    if ((int(uint(c2da_mem[dest + 160]) | uint(c2da_mem[dest + 161]) << 0x8 | uint(c2da_mem[dest + 162]) << 0x10 | uint(c2da_mem[dest + 163]) << 0x18) & 262144) != 0) {
        an = an + uint(P_Random() - P_Random() << 20)
    }
    let c2da_fresh174 : uint = an
    c2da_mem[th_1 + 56] = uint8(c2da_fresh174)
    c2da_mem[th_1 + 57] = uint8(c2da_fresh174 >> 0x8)
    c2da_mem[th_1 + 58] = uint8(c2da_fresh174 >> 0x10)
    c2da_mem[th_1 + 59] = uint8(c2da_fresh174 >> 0x18)
    an >>= 19u
    let c2da_fresh175 : int = int(uint(c2da_mem[th_1 + 136]) | uint(c2da_mem[th_1 + 137]) << 0x8 | uint(c2da_mem[th_1 + 138]) << 0x10 | uint(c2da_mem[th_1 + 139]) << 0x18) + 60
    let c2da_fresh176 : int = FixedMul(int(uint(c2da_mem[c2da_fresh175]) | uint(c2da_mem[c2da_fresh175 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh175 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh175 + 3]) << 0x18), int(uint(c2da_mem[finecosine + int(an) * 4]) | uint(c2da_mem[finecosine + int(an) * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + int(an) * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + int(an) * 4 + 3]) << 0x18))
    let c2da_fresh177 : uint = uint(c2da_fresh176)
    c2da_mem[th_1 + 112] = uint8(c2da_fresh177)
    c2da_mem[th_1 + 113] = uint8(c2da_fresh177 >> 0x8)
    c2da_mem[th_1 + 114] = uint8(c2da_fresh177 >> 0x10)
    c2da_mem[th_1 + 115] = uint8(c2da_fresh177 >> 0x18)
    let c2da_fresh178 : int = int(uint(c2da_mem[th_1 + 136]) | uint(c2da_mem[th_1 + 137]) << 0x8 | uint(c2da_mem[th_1 + 138]) << 0x10 | uint(c2da_mem[th_1 + 139]) << 0x18) + 60
    let c2da_fresh179 : int = FixedMul(int(uint(c2da_mem[c2da_fresh178]) | uint(c2da_mem[c2da_fresh178 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh178 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh178 + 3]) << 0x18), int(uint(c2da_mem[257920 + int(an) * 4]) | uint(c2da_mem[257920 + int(an) * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + int(an) * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + int(an) * 4 + 3]) << 0x18))
    let c2da_fresh180 : uint = uint(c2da_fresh179)
    c2da_mem[th_1 + 116] = uint8(c2da_fresh180)
    c2da_mem[th_1 + 117] = uint8(c2da_fresh180 >> 0x8)
    c2da_mem[th_1 + 118] = uint8(c2da_fresh180 >> 0x10)
    c2da_mem[th_1 + 119] = uint8(c2da_fresh180 >> 0x18)
    dist_0 = P_AproxDistance(int(uint(c2da_mem[dest + 24]) | uint(c2da_mem[dest + 25]) << 0x8 | uint(c2da_mem[dest + 26]) << 0x10 | uint(c2da_mem[dest + 27]) << 0x18) - int(uint(c2da_mem[source + 24]) | uint(c2da_mem[source + 25]) << 0x8 | uint(c2da_mem[source + 26]) << 0x10 | uint(c2da_mem[source + 27]) << 0x18), int(uint(c2da_mem[dest + 28]) | uint(c2da_mem[dest + 29]) << 0x8 | uint(c2da_mem[dest + 30]) << 0x10 | uint(c2da_mem[dest + 31]) << 0x18) - int(uint(c2da_mem[source + 28]) | uint(c2da_mem[source + 29]) << 0x8 | uint(c2da_mem[source + 30]) << 0x10 | uint(c2da_mem[source + 31]) << 0x18))
    let c2da_fresh181 : int = int(uint(c2da_mem[th_1 + 136]) | uint(c2da_mem[th_1 + 137]) << 0x8 | uint(c2da_mem[th_1 + 138]) << 0x10 | uint(c2da_mem[th_1 + 139]) << 0x18) + 60
    dist_0 /= int(uint(c2da_mem[c2da_fresh181]) | uint(c2da_mem[c2da_fresh181 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh181 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh181 + 3]) << 0x18)
    if (dist_0 < 1) {
        dist_0 = 1
    }
    let c2da_fresh182 : int = (int(uint(c2da_mem[dest + 32]) | uint(c2da_mem[dest + 33]) << 0x8 | uint(c2da_mem[dest + 34]) << 0x10 | uint(c2da_mem[dest + 35]) << 0x18) - int(uint(c2da_mem[source + 32]) | uint(c2da_mem[source + 33]) << 0x8 | uint(c2da_mem[source + 34]) << 0x10 | uint(c2da_mem[source + 35]) << 0x18)) / dist_0
    let c2da_fresh183 : uint = uint(c2da_fresh182)
    c2da_mem[th_1 + 120] = uint8(c2da_fresh183)
    c2da_mem[th_1 + 121] = uint8(c2da_fresh183 >> 0x8)
    c2da_mem[th_1 + 122] = uint8(c2da_fresh183 >> 0x10)
    c2da_mem[th_1 + 123] = uint8(c2da_fresh183 >> 0x18)
    P_CheckMissileSpawn(th_1)
    return th_1
}
[export, sideeffects]
def P_CheckMissileSpawn(var th_2 : int) {
    let c2da_fresh184 : int = int(uint(c2da_mem[th_2 + 144]) | uint(c2da_mem[th_2 + 145]) << 0x8 | uint(c2da_mem[th_2 + 146]) << 0x10 | uint(c2da_mem[th_2 + 147]) << 0x18) - int(P_Random() & 3)
    let c2da_fresh185 : uint = uint(c2da_fresh184)
    c2da_mem[th_2 + 144] = uint8(c2da_fresh185)
    c2da_mem[th_2 + 145] = uint8(c2da_fresh185 >> 0x8)
    c2da_mem[th_2 + 146] = uint8(c2da_fresh185 >> 0x10)
    c2da_mem[th_2 + 147] = uint8(c2da_fresh185 >> 0x18)
    if (int(uint(c2da_mem[th_2 + 144]) | uint(c2da_mem[th_2 + 145]) << 0x8 | uint(c2da_mem[th_2 + 146]) << 0x10 | uint(c2da_mem[th_2 + 147]) << 0x18) < 1) {
        let c2da_fresh186 : int = 1
        let c2da_fresh187 : uint = uint(c2da_fresh186)
        c2da_mem[th_2 + 144] = uint8(c2da_fresh187)
        c2da_mem[th_2 + 145] = uint8(c2da_fresh187 >> 0x8)
        c2da_mem[th_2 + 146] = uint8(c2da_fresh187 >> 0x10)
        c2da_mem[th_2 + 147] = uint8(c2da_fresh187 >> 0x18)
    }
    let c2da_fresh188 : int = int(uint(c2da_mem[th_2 + 24]) | uint(c2da_mem[th_2 + 25]) << 0x8 | uint(c2da_mem[th_2 + 26]) << 0x10 | uint(c2da_mem[th_2 + 27]) << 0x18) + (int(uint(c2da_mem[th_2 + 112]) | uint(c2da_mem[th_2 + 113]) << 0x8 | uint(c2da_mem[th_2 + 114]) << 0x10 | uint(c2da_mem[th_2 + 115]) << 0x18) >> 1)
    let c2da_fresh189 : uint = uint(c2da_fresh188)
    c2da_mem[th_2 + 24] = uint8(c2da_fresh189)
    c2da_mem[th_2 + 25] = uint8(c2da_fresh189 >> 0x8)
    c2da_mem[th_2 + 26] = uint8(c2da_fresh189 >> 0x10)
    c2da_mem[th_2 + 27] = uint8(c2da_fresh189 >> 0x18)
    let c2da_fresh190 : int = int(uint(c2da_mem[th_2 + 28]) | uint(c2da_mem[th_2 + 29]) << 0x8 | uint(c2da_mem[th_2 + 30]) << 0x10 | uint(c2da_mem[th_2 + 31]) << 0x18) + (int(uint(c2da_mem[th_2 + 116]) | uint(c2da_mem[th_2 + 117]) << 0x8 | uint(c2da_mem[th_2 + 118]) << 0x10 | uint(c2da_mem[th_2 + 119]) << 0x18) >> 1)
    let c2da_fresh191 : uint = uint(c2da_fresh190)
    c2da_mem[th_2 + 28] = uint8(c2da_fresh191)
    c2da_mem[th_2 + 29] = uint8(c2da_fresh191 >> 0x8)
    c2da_mem[th_2 + 30] = uint8(c2da_fresh191 >> 0x10)
    c2da_mem[th_2 + 31] = uint8(c2da_fresh191 >> 0x18)
    let c2da_fresh192 : int = int(uint(c2da_mem[th_2 + 32]) | uint(c2da_mem[th_2 + 33]) << 0x8 | uint(c2da_mem[th_2 + 34]) << 0x10 | uint(c2da_mem[th_2 + 35]) << 0x18) + (int(uint(c2da_mem[th_2 + 120]) | uint(c2da_mem[th_2 + 121]) << 0x8 | uint(c2da_mem[th_2 + 122]) << 0x10 | uint(c2da_mem[th_2 + 123]) << 0x18) >> 1)
    let c2da_fresh193 : uint = uint(c2da_fresh192)
    c2da_mem[th_2 + 32] = uint8(c2da_fresh193)
    c2da_mem[th_2 + 33] = uint8(c2da_fresh193 >> 0x8)
    c2da_mem[th_2 + 34] = uint8(c2da_fresh193 >> 0x10)
    c2da_mem[th_2 + 35] = uint8(c2da_fresh193 >> 0x18)
    if (P_TryMove(th_2, int(uint(c2da_mem[th_2 + 24]) | uint(c2da_mem[th_2 + 25]) << 0x8 | uint(c2da_mem[th_2 + 26]) << 0x10 | uint(c2da_mem[th_2 + 27]) << 0x18), int(uint(c2da_mem[th_2 + 28]) | uint(c2da_mem[th_2 + 29]) << 0x8 | uint(c2da_mem[th_2 + 30]) << 0x10 | uint(c2da_mem[th_2 + 31]) << 0x18)) == 0) {
        P_ExplodeMissile(th_2)
    }
    return
}
[export, sideeffects]
def P_SpawnPlayerMissile(var source_0 : int; var type_2 : uint) {
    var th_3 : int
    var an_0 : uint
    var x_4 : int
    var y_5 : int
    var z_4 : int
    var slope : int
    an_0 = uint(c2da_mem[source_0 + 56]) | uint(c2da_mem[source_0 + 57]) << 0x8 | uint(c2da_mem[source_0 + 58]) << 0x10 | uint(c2da_mem[source_0 + 59]) << 0x18
    slope = P_AimLineAttack(source_0, an_0, 16 * 64 * (1 << 16))
    if (linetarget == 0) {
        an_0 += uint(1 << 26)
        slope = P_AimLineAttack(source_0, an_0, 16 * 64 * (1 << 16))
        if (linetarget == 0) {
            an_0 -= uint(2 << 26)
            slope = P_AimLineAttack(source_0, an_0, 16 * 64 * (1 << 16))
        }
        if (linetarget == 0) {
            an_0 = uint(c2da_mem[source_0 + 56]) | uint(c2da_mem[source_0 + 57]) << 0x8 | uint(c2da_mem[source_0 + 58]) << 0x10 | uint(c2da_mem[source_0 + 59]) << 0x18
            slope = 0
        }
    }
    x_4 = int(uint(c2da_mem[source_0 + 24]) | uint(c2da_mem[source_0 + 25]) << 0x8 | uint(c2da_mem[source_0 + 26]) << 0x10 | uint(c2da_mem[source_0 + 27]) << 0x18)
    y_5 = int(uint(c2da_mem[source_0 + 28]) | uint(c2da_mem[source_0 + 29]) << 0x8 | uint(c2da_mem[source_0 + 30]) << 0x10 | uint(c2da_mem[source_0 + 31]) << 0x18)
    z_4 = int(uint(c2da_mem[source_0 + 32]) | uint(c2da_mem[source_0 + 33]) << 0x8 | uint(c2da_mem[source_0 + 34]) << 0x10 | uint(c2da_mem[source_0 + 35]) << 0x18) + 4 * 8 * (1 << 16)
    th_3 = P_SpawnMobj(x_4, y_5, z_4, type_2)
    let c2da_fresh194 : int = int(uint(c2da_mem[th_3 + 136]) | uint(c2da_mem[th_3 + 137]) << 0x8 | uint(c2da_mem[th_3 + 138]) << 0x10 | uint(c2da_mem[th_3 + 139]) << 0x18) + 16
    if (int(uint(c2da_mem[c2da_fresh194]) | uint(c2da_mem[c2da_fresh194 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh194 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh194 + 3]) << 0x18) != 0) {
        let c2da_fresh195 : int = int(uint(c2da_mem[th_3 + 136]) | uint(c2da_mem[th_3 + 137]) << 0x8 | uint(c2da_mem[th_3 + 138]) << 0x10 | uint(c2da_mem[th_3 + 139]) << 0x18) + 16
        S_StartSound(th_3, int(uint(c2da_mem[c2da_fresh195]) | uint(c2da_mem[c2da_fresh195 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh195 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh195 + 3]) << 0x18))
    }
    let c2da_fresh196 : uint = uint(source_0)
    c2da_mem[th_3 + 176] = uint8(c2da_fresh196)
    c2da_mem[th_3 + 177] = uint8(c2da_fresh196 >> 0x8)
    c2da_mem[th_3 + 178] = uint8(c2da_fresh196 >> 0x10)
    c2da_mem[th_3 + 179] = uint8(c2da_fresh196 >> 0x18)
    c2da_mem[th_3 + 180] = 0u8
    c2da_mem[th_3 + 181] = 0u8
    c2da_mem[th_3 + 182] = 0u8
    c2da_mem[th_3 + 183] = 0u8
    let c2da_fresh197 : uint = an_0
    c2da_mem[th_3 + 56] = uint8(c2da_fresh197)
    c2da_mem[th_3 + 57] = uint8(c2da_fresh197 >> 0x8)
    c2da_mem[th_3 + 58] = uint8(c2da_fresh197 >> 0x10)
    c2da_mem[th_3 + 59] = uint8(c2da_fresh197 >> 0x18)
    let c2da_fresh198 : int = int(uint(c2da_mem[th_3 + 136]) | uint(c2da_mem[th_3 + 137]) << 0x8 | uint(c2da_mem[th_3 + 138]) << 0x10 | uint(c2da_mem[th_3 + 139]) << 0x18) + 60
    let c2da_fresh199 : int = finecosine + int(an_0 >> 19u) * 4
    let c2da_fresh200 : int = FixedMul(int(uint(c2da_mem[c2da_fresh198]) | uint(c2da_mem[c2da_fresh198 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh198 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh198 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh199]) | uint(c2da_mem[c2da_fresh199 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh199 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh199 + 3]) << 0x18))
    let c2da_fresh201 : uint = uint(c2da_fresh200)
    c2da_mem[th_3 + 112] = uint8(c2da_fresh201)
    c2da_mem[th_3 + 113] = uint8(c2da_fresh201 >> 0x8)
    c2da_mem[th_3 + 114] = uint8(c2da_fresh201 >> 0x10)
    c2da_mem[th_3 + 115] = uint8(c2da_fresh201 >> 0x18)
    let c2da_fresh202 : int = int(uint(c2da_mem[th_3 + 136]) | uint(c2da_mem[th_3 + 137]) << 0x8 | uint(c2da_mem[th_3 + 138]) << 0x10 | uint(c2da_mem[th_3 + 139]) << 0x18) + 60
    let c2da_fresh203 : int = 257920 + int(an_0 >> 19u) * 4
    let c2da_fresh204 : int = FixedMul(int(uint(c2da_mem[c2da_fresh202]) | uint(c2da_mem[c2da_fresh202 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh202 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh202 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh203]) | uint(c2da_mem[c2da_fresh203 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh203 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh203 + 3]) << 0x18))
    let c2da_fresh205 : uint = uint(c2da_fresh204)
    c2da_mem[th_3 + 116] = uint8(c2da_fresh205)
    c2da_mem[th_3 + 117] = uint8(c2da_fresh205 >> 0x8)
    c2da_mem[th_3 + 118] = uint8(c2da_fresh205 >> 0x10)
    c2da_mem[th_3 + 119] = uint8(c2da_fresh205 >> 0x18)
    let c2da_fresh206 : int = int(uint(c2da_mem[th_3 + 136]) | uint(c2da_mem[th_3 + 137]) << 0x8 | uint(c2da_mem[th_3 + 138]) << 0x10 | uint(c2da_mem[th_3 + 139]) << 0x18) + 60
    let c2da_fresh207 : int = FixedMul(int(uint(c2da_mem[c2da_fresh206]) | uint(c2da_mem[c2da_fresh206 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh206 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh206 + 3]) << 0x18), slope)
    let c2da_fresh208 : uint = uint(c2da_fresh207)
    c2da_mem[th_3 + 120] = uint8(c2da_fresh208)
    c2da_mem[th_3 + 121] = uint8(c2da_fresh208 >> 0x8)
    c2da_mem[th_3 + 122] = uint8(c2da_fresh208 >> 0x10)
    c2da_mem[th_3 + 123] = uint8(c2da_fresh208 >> 0x18)
    P_CheckMissileSpawn(th_3)
    return
}
[export, sideeffects]
def P_SpawnMapThing(var mthing_1 : int) {
    var i_0 : int
    var bit : int
    var mobj_5 : int
    var x_5 : int
    var y_6 : int
    var z_5 : int
    if (int(int16(uint(c2da_mem[mthing_1 + 6]) | uint(c2da_mem[mthing_1 + 7]) << 0x8)) == 11) {
        if (deathmatch_p < 40768 + 10 * 10) {
            c2da_lin_memcpy(int(deathmatch_p), mthing_1, 10ul)
            deathmatch_p = deathmatch_p + 10
        }
        return
    }
    if (int(int16(uint(c2da_mem[mthing_1 + 6]) | uint(c2da_mem[mthing_1 + 7]) << 0x8)) <= 0) {
        return
    }
    if (int(int16(uint(c2da_mem[mthing_1 + 6]) | uint(c2da_mem[mthing_1 + 7]) << 0x8)) <= 4) {
        let c2da_fresh209 : int = 40880 + (int(int16(uint(c2da_mem[mthing_1 + 6]) | uint(c2da_mem[mthing_1 + 7]) << 0x8)) - 1) * 10
        c2da_lin_memmove(c2da_fresh209, mthing_1, 10ul)
        if (deathmatch == 0) {
            P_SpawnPlayer(mthing_1)
        }
        return
    }
    if (netgame == 0 && (int(int16(uint(c2da_mem[mthing_1 + 8]) | uint(c2da_mem[mthing_1 + 9]) << 0x8)) & 16) != 0) {
        return
    }
    if (int(gameskill) == 0) {
        bit = 1
    } elif (int(gameskill) == 4) {
        bit = 4
    } else {
        bit = 1 << int(gameskill) - 1
    }
    if ((int(int16(uint(c2da_mem[mthing_1 + 8]) | uint(c2da_mem[mthing_1 + 9]) << 0x8)) & bit) == 0) {
        return
    }
    i_0 = 0
    while (i_0 < 137) {
        if (int(int16(uint(c2da_mem[mthing_1 + 6]) | uint(c2da_mem[mthing_1 + 7]) << 0x8)) == int(uint(c2da_mem[51056 + i_0 * 92]) | uint(c2da_mem[51056 + i_0 * 92 + 1]) << 0x8 | uint(c2da_mem[51056 + i_0 * 92 + 2]) << 0x10 | uint(c2da_mem[51056 + i_0 * 92 + 3]) << 0x18)) {
            break
        }
        i_0++
    }
    if (i_0 == 137) {
        I_Error(360544, [C2daVaArg(tag = 1, i64 = int64(int16(uint(c2da_mem[mthing_1 + 6]) | uint(c2da_mem[mthing_1 + 7]) << 0x8)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int16(uint(c2da_mem[mthing_1]) | uint(c2da_mem[mthing_1 + 1]) << 0x8)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(int16(uint(c2da_mem[mthing_1 + 2]) | uint(c2da_mem[mthing_1 + 3]) << 0x8)), f64 = 0.0lf, raw = 0x0)])
    }
    if (deathmatch != 0 && (int(uint(c2da_mem[51056 + i_0 * 92 + 84]) | uint(c2da_mem[51056 + i_0 * 92 + 85]) << 0x8 | uint(c2da_mem[51056 + i_0 * 92 + 86]) << 0x10 | uint(c2da_mem[51056 + i_0 * 92 + 87]) << 0x18) & 33554432) != 0) {
        return
    }
    if (nomonsters != 0x0 && (i_0 == 18 || (int(uint(c2da_mem[51056 + i_0 * 92 + 84]) | uint(c2da_mem[51056 + i_0 * 92 + 85]) << 0x8 | uint(c2da_mem[51056 + i_0 * 92 + 86]) << 0x10 | uint(c2da_mem[51056 + i_0 * 92 + 87]) << 0x18) & 4194304) != 0)) {
        return
    }
    x_5 = int(int16(uint(c2da_mem[mthing_1]) | uint(c2da_mem[mthing_1 + 1]) << 0x8)) << 16
    y_6 = int(int16(uint(c2da_mem[mthing_1 + 2]) | uint(c2da_mem[mthing_1 + 3]) << 0x8)) << 16
    if ((int(uint(c2da_mem[51056 + i_0 * 92 + 84]) | uint(c2da_mem[51056 + i_0 * 92 + 85]) << 0x8 | uint(c2da_mem[51056 + i_0 * 92 + 86]) << 0x10 | uint(c2da_mem[51056 + i_0 * 92 + 87]) << 0x18) & 256) != 0) {
        z_5 = 2147483647
    } else {
        z_5 = -2147483647 - 1
    }
    mobj_5 = P_SpawnMobj(x_5, y_6, z_5, uint(i_0))
    c2da_lin_memmove(mobj_5 + 204, mthing_1, 10ul)
    if (int(uint(c2da_mem[mobj_5 + 144]) | uint(c2da_mem[mobj_5 + 145]) << 0x8 | uint(c2da_mem[mobj_5 + 146]) << 0x10 | uint(c2da_mem[mobj_5 + 147]) << 0x18) > 0) {
        let c2da_fresh210 : int = 1 + P_Random() % int(uint(c2da_mem[mobj_5 + 144]) | uint(c2da_mem[mobj_5 + 145]) << 0x8 | uint(c2da_mem[mobj_5 + 146]) << 0x10 | uint(c2da_mem[mobj_5 + 147]) << 0x18)
        let c2da_fresh211 : uint = uint(c2da_fresh210)
        c2da_mem[mobj_5 + 144] = uint8(c2da_fresh211)
        c2da_mem[mobj_5 + 145] = uint8(c2da_fresh211 >> 0x8)
        c2da_mem[mobj_5 + 146] = uint8(c2da_fresh211 >> 0x10)
        c2da_mem[mobj_5 + 147] = uint8(c2da_fresh211 >> 0x18)
    }
    if ((int(uint(c2da_mem[mobj_5 + 160]) | uint(c2da_mem[mobj_5 + 161]) << 0x8 | uint(c2da_mem[mobj_5 + 162]) << 0x10 | uint(c2da_mem[mobj_5 + 163]) << 0x18) & 4194304) != 0) {
        totalkills = totalkills + 1
    }
    if ((int(uint(c2da_mem[mobj_5 + 160]) | uint(c2da_mem[mobj_5 + 161]) << 0x8 | uint(c2da_mem[mobj_5 + 162]) << 0x10 | uint(c2da_mem[mobj_5 + 163]) << 0x18) & 8388608) != 0) {
        totalitems = totalitems + 1
    }
    let c2da_fresh212 : uint = uint(536870912 * (int(int16(uint(c2da_mem[mthing_1 + 4]) | uint(c2da_mem[mthing_1 + 5]) << 0x8)) / 45))
    let c2da_fresh213 : uint = c2da_fresh212
    c2da_mem[mobj_5 + 56] = uint8(c2da_fresh213)
    c2da_mem[mobj_5 + 57] = uint8(c2da_fresh213 >> 0x8)
    c2da_mem[mobj_5 + 58] = uint8(c2da_fresh213 >> 0x10)
    c2da_mem[mobj_5 + 59] = uint8(c2da_fresh213 >> 0x18)
    if ((int(int16(uint(c2da_mem[mthing_1 + 8]) | uint(c2da_mem[mthing_1 + 9]) << 0x8)) & 8) != 0) {
        let c2da_fresh214 : int = int(uint(c2da_mem[mobj_5 + 160]) | uint(c2da_mem[mobj_5 + 161]) << 0x8 | uint(c2da_mem[mobj_5 + 162]) << 0x10 | uint(c2da_mem[mobj_5 + 163]) << 0x18) | 32
        let c2da_fresh215 : uint = uint(c2da_fresh214)
        c2da_mem[mobj_5 + 160] = uint8(c2da_fresh215)
        c2da_mem[mobj_5 + 161] = uint8(c2da_fresh215 >> 0x8)
        c2da_mem[mobj_5 + 162] = uint8(c2da_fresh215 >> 0x10)
        c2da_mem[mobj_5 + 163] = uint8(c2da_fresh215 >> 0x18)
    }
    return
}
[export, sideeffects]
def P_SpawnPlayer(var mthing_2 : int) {
    var p : int
    var x_6 : int
    var y_7 : int
    var mobj_6 : int
    if (int(int16(uint(c2da_mem[mthing_2 + 6]) | uint(c2da_mem[mthing_2 + 7]) << 0x8)) == 0) {
        return
    }
    if (playeringame[int(int16(uint(c2da_mem[mthing_2 + 6]) | uint(c2da_mem[mthing_2 + 7]) << 0x8)) - 1] == 0) {
        return
    }
    p = 96 + (int(int16(uint(c2da_mem[mthing_2 + 6]) | uint(c2da_mem[mthing_2 + 7]) << 0x8)) - 1) * 328
    if ((uint(c2da_mem[p + 8]) | uint(c2da_mem[p + 9]) << 0x8 | uint(c2da_mem[p + 10]) << 0x10 | uint(c2da_mem[p + 11]) << 0x18) == 2u) {
        G_PlayerReborn(int(int16(uint(c2da_mem[mthing_2 + 6]) | uint(c2da_mem[mthing_2 + 7]) << 0x8)) - 1)
    }
    x_6 = int(int16(uint(c2da_mem[mthing_2]) | uint(c2da_mem[mthing_2 + 1]) << 0x8)) << 16
    y_7 = int(int16(uint(c2da_mem[mthing_2 + 2]) | uint(c2da_mem[mthing_2 + 3]) << 0x8)) << 16
    mobj_6 = P_SpawnMobj(x_6, y_7, -2147483647 - 1, 0u)
    if (int(int16(uint(c2da_mem[mthing_2 + 6]) | uint(c2da_mem[mthing_2 + 7]) << 0x8)) > 1) {
        let c2da_fresh216 : int = int(uint(c2da_mem[mobj_6 + 160]) | uint(c2da_mem[mobj_6 + 161]) << 0x8 | uint(c2da_mem[mobj_6 + 162]) << 0x10 | uint(c2da_mem[mobj_6 + 163]) << 0x18) | int(int16(uint(c2da_mem[mthing_2 + 6]) | uint(c2da_mem[mthing_2 + 7]) << 0x8)) - 1 << 26
        let c2da_fresh217 : uint = uint(c2da_fresh216)
        c2da_mem[mobj_6 + 160] = uint8(c2da_fresh217)
        c2da_mem[mobj_6 + 161] = uint8(c2da_fresh217 >> 0x8)
        c2da_mem[mobj_6 + 162] = uint8(c2da_fresh217 >> 0x10)
        c2da_mem[mobj_6 + 163] = uint8(c2da_fresh217 >> 0x18)
    }
    let c2da_fresh218 : uint = uint(536870912 * (int(int16(uint(c2da_mem[mthing_2 + 4]) | uint(c2da_mem[mthing_2 + 5]) << 0x8)) / 45))
    let c2da_fresh219 : uint = c2da_fresh218
    c2da_mem[mobj_6 + 56] = uint8(c2da_fresh219)
    c2da_mem[mobj_6 + 57] = uint8(c2da_fresh219 >> 0x8)
    c2da_mem[mobj_6 + 58] = uint8(c2da_fresh219 >> 0x10)
    c2da_mem[mobj_6 + 59] = uint8(c2da_fresh219 >> 0x18)
    let c2da_fresh220 : uint = uint(p)
    c2da_mem[mobj_6 + 192] = uint8(c2da_fresh220)
    c2da_mem[mobj_6 + 193] = uint8(c2da_fresh220 >> 0x8)
    c2da_mem[mobj_6 + 194] = uint8(c2da_fresh220 >> 0x10)
    c2da_mem[mobj_6 + 195] = uint8(c2da_fresh220 >> 0x18)
    c2da_mem[mobj_6 + 196] = 0u8
    c2da_mem[mobj_6 + 197] = 0u8
    c2da_mem[mobj_6 + 198] = 0u8
    c2da_mem[mobj_6 + 199] = 0u8
    let c2da_fresh221 : int = int(uint(c2da_mem[p + 44]) | uint(c2da_mem[p + 45]) << 0x8 | uint(c2da_mem[p + 46]) << 0x10 | uint(c2da_mem[p + 47]) << 0x18)
    let c2da_fresh222 : uint = uint(c2da_fresh221)
    c2da_mem[mobj_6 + 164] = uint8(c2da_fresh222)
    c2da_mem[mobj_6 + 165] = uint8(c2da_fresh222 >> 0x8)
    c2da_mem[mobj_6 + 166] = uint8(c2da_fresh222 >> 0x10)
    c2da_mem[mobj_6 + 167] = uint8(c2da_fresh222 >> 0x18)
    let c2da_fresh223 : uint = uint(mobj_6)
    c2da_mem[p] = uint8(c2da_fresh223)
    c2da_mem[p + 1] = uint8(c2da_fresh223 >> 0x8)
    c2da_mem[p + 2] = uint8(c2da_fresh223 >> 0x10)
    c2da_mem[p + 3] = uint8(c2da_fresh223 >> 0x18)
    c2da_mem[p + 4] = 0u8
    c2da_mem[p + 5] = 0u8
    c2da_mem[p + 6] = 0u8
    c2da_mem[p + 7] = 0u8
    let c2da_fresh224 : uint = 0u
    let c2da_fresh225 : uint = c2da_fresh224
    c2da_mem[p + 8] = uint8(c2da_fresh225)
    c2da_mem[p + 9] = uint8(c2da_fresh225 >> 0x8)
    c2da_mem[p + 10] = uint8(c2da_fresh225 >> 0x10)
    c2da_mem[p + 11] = uint8(c2da_fresh225 >> 0x18)
    let c2da_fresh226 : int = 0
    let c2da_fresh227 : uint = uint(c2da_fresh226)
    c2da_mem[p + 212] = uint8(c2da_fresh227)
    c2da_mem[p + 213] = uint8(c2da_fresh227 >> 0x8)
    c2da_mem[p + 214] = uint8(c2da_fresh227 >> 0x10)
    c2da_mem[p + 215] = uint8(c2da_fresh227 >> 0x18)
    let c2da_fresh228 : uint = 0u
    c2da_mem[p + 232] = uint8(c2da_fresh228)
    c2da_mem[p + 233] = uint8(c2da_fresh228 >> 0x8)
    c2da_mem[p + 234] = uint8(c2da_fresh228 >> 0x10)
    c2da_mem[p + 235] = uint8(c2da_fresh228 >> 0x18)
    c2da_mem[p + 236] = 0u8
    c2da_mem[p + 237] = 0u8
    c2da_mem[p + 238] = 0u8
    c2da_mem[p + 239] = 0u8
    let c2da_fresh229 : int = 0
    let c2da_fresh230 : uint = uint(c2da_fresh229)
    c2da_mem[p + 240] = uint8(c2da_fresh230)
    c2da_mem[p + 241] = uint8(c2da_fresh230 >> 0x8)
    c2da_mem[p + 242] = uint8(c2da_fresh230 >> 0x10)
    c2da_mem[p + 243] = uint8(c2da_fresh230 >> 0x18)
    let c2da_fresh231 : int = 0
    let c2da_fresh232 : uint = uint(c2da_fresh231)
    c2da_mem[p + 244] = uint8(c2da_fresh232)
    c2da_mem[p + 245] = uint8(c2da_fresh232 >> 0x8)
    c2da_mem[p + 246] = uint8(c2da_fresh232 >> 0x10)
    c2da_mem[p + 247] = uint8(c2da_fresh232 >> 0x18)
    let c2da_fresh233 : int = 0
    let c2da_fresh234 : uint = uint(c2da_fresh233)
    c2da_mem[p + 256] = uint8(c2da_fresh234)
    c2da_mem[p + 257] = uint8(c2da_fresh234 >> 0x8)
    c2da_mem[p + 258] = uint8(c2da_fresh234 >> 0x10)
    c2da_mem[p + 259] = uint8(c2da_fresh234 >> 0x18)
    let c2da_fresh235 : int = 0
    let c2da_fresh236 : uint = uint(c2da_fresh235)
    c2da_mem[p + 260] = uint8(c2da_fresh236)
    c2da_mem[p + 261] = uint8(c2da_fresh236 >> 0x8)
    c2da_mem[p + 262] = uint8(c2da_fresh236 >> 0x10)
    c2da_mem[p + 263] = uint8(c2da_fresh236 >> 0x18)
    let c2da_fresh237 : int = 41 * (1 << 16)
    let c2da_fresh238 : uint = uint(c2da_fresh237)
    c2da_mem[p + 32] = uint8(c2da_fresh238)
    c2da_mem[p + 33] = uint8(c2da_fresh238 >> 0x8)
    c2da_mem[p + 34] = uint8(c2da_fresh238 >> 0x10)
    c2da_mem[p + 35] = uint8(c2da_fresh238 >> 0x18)
    P_SetupPsprites(p)
    if (deathmatch != 0) {
        for (i_1 in range(0, 6)) {
            let c2da_fresh239 : uint = 1u
            let c2da_fresh240 : uint = c2da_fresh239
            c2da_mem[p + 80 + i_1 * 4] = uint8(c2da_fresh240)
            c2da_mem[p + 80 + i_1 * 4 + 1] = uint8(c2da_fresh240 >> 0x8)
            c2da_mem[p + 80 + i_1 * 4 + 2] = uint8(c2da_fresh240 >> 0x10)
            c2da_mem[p + 80 + i_1 * 4 + 3] = uint8(c2da_fresh240 >> 0x18)
        }
    }
    if (int(int16(uint(c2da_mem[mthing_2 + 6]) | uint(c2da_mem[mthing_2 + 7]) << 0x8)) - 1 == consoleplayer) {
        ST_Start()
        HU_Start()
    }
    return
}
var test : int = default<int>


// This unit's static data, at heap offset 360320.
let private c2da_lin_static_p_mobj_seg = fixed_array<int>(360544, 44)
let private c2da_lin_static_p_mobj = fixed_array<uint64>(0x4d6e776170535f50ul, 0x3a676e6968547061ul, 0x6e776f6e6b6e5520ul, 0x6925206570797420ul, 0x2c69252820746120ul, 0x29692520ul)

[init]
def private c2da_lin_init_static_p_mobj() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_p_mobj_seg[s * 2]
        for (k in range(c2da_lin_static_p_mobj_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_p_mobj[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_p_mobj() {
    if (length(c2da_fn_table5) < 127) {
        resize(c2da_fn_table5, 127)
    }
    c2da_fn_table5[126] = @@P_MobjThinker
}

[init]
def private c2da_lin_relink_init_p_mobj() {
    c2da_relink_p_mobj()
}
