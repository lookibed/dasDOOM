[export, sideeffects]
def P_CheckSight(var t1 : int; var t2 : int) : uint {
    var s1 : int
    var s2 : int
    var pnum : int
    let c2da_fresh0 : int = int(uint(c2da_mem[t1 + 88]) | uint(c2da_mem[t1 + 89]) << 0x8 | uint(c2da_mem[t1 + 90]) << 0x10 | uint(c2da_mem[t1 + 91]) << 0x18)
    s1 = int(int64((int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18) - sectors) / 128))
    let c2da_fresh1 : int = int(uint(c2da_mem[t1 + 88]) | uint(c2da_mem[t1 + 89]) << 0x8 | uint(c2da_mem[t1 + 90]) << 0x10 | uint(c2da_mem[t1 + 91]) << 0x18)
    s1 = int(int64((int(uint(c2da_mem[c2da_fresh1]) | uint(c2da_mem[c2da_fresh1 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh1 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh1 + 3]) << 0x18) - sectors) / 128))
    let c2da_fresh2 : int = int(uint(c2da_mem[t2 + 88]) | uint(c2da_mem[t2 + 89]) << 0x8 | uint(c2da_mem[t2 + 90]) << 0x10 | uint(c2da_mem[t2 + 91]) << 0x18)
    s2 = int(int64((int(uint(c2da_mem[c2da_fresh2]) | uint(c2da_mem[c2da_fresh2 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh2 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh2 + 3]) << 0x18) - sectors) / 128))
    let c2da_fresh3 : int = int(uint(c2da_mem[t2 + 88]) | uint(c2da_mem[t2 + 89]) << 0x8 | uint(c2da_mem[t2 + 90]) << 0x10 | uint(c2da_mem[t2 + 91]) << 0x18)
    s2 = int(int64((int(uint(c2da_mem[c2da_fresh3]) | uint(c2da_mem[c2da_fresh3 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh3 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh3 + 3]) << 0x18) - sectors) / 128))
    pnum = s1 * numsectors + s2
    let c2da_fresh4 : int = int(uint(c2da_mem[63664]) | uint(c2da_mem[63665]) << 0x8 | uint(c2da_mem[63666]) << 0x10 | uint(c2da_mem[63667]) << 0x18) + (pnum >> 3)
    if ((int(c2da_mem[c2da_fresh4]) & 1 << (pnum & 7)) != 0) {
        sightcounts[0]++
        return 0u
    }
    sightcounts[1]++
    validcount = validcount + 1
    sightzstart = int(uint(c2da_mem[t1 + 32]) | uint(c2da_mem[t1 + 33]) << 0x8 | uint(c2da_mem[t1 + 34]) << 0x10 | uint(c2da_mem[t1 + 35]) << 0x18) + int(uint(c2da_mem[t1 + 108]) | uint(c2da_mem[t1 + 109]) << 0x8 | uint(c2da_mem[t1 + 110]) << 0x10 | uint(c2da_mem[t1 + 111]) << 0x18) - (int(uint(c2da_mem[t1 + 108]) | uint(c2da_mem[t1 + 109]) << 0x8 | uint(c2da_mem[t1 + 110]) << 0x10 | uint(c2da_mem[t1 + 111]) << 0x18) >> 2)
    topslope = int(uint(c2da_mem[t2 + 32]) | uint(c2da_mem[t2 + 33]) << 0x8 | uint(c2da_mem[t2 + 34]) << 0x10 | uint(c2da_mem[t2 + 35]) << 0x18) + int(uint(c2da_mem[t2 + 108]) | uint(c2da_mem[t2 + 109]) << 0x8 | uint(c2da_mem[t2 + 110]) << 0x10 | uint(c2da_mem[t2 + 111]) << 0x18) - sightzstart
    bottomslope = int(uint(c2da_mem[t2 + 32]) | uint(c2da_mem[t2 + 33]) << 0x8 | uint(c2da_mem[t2 + 34]) << 0x10 | uint(c2da_mem[t2 + 35]) << 0x18) - sightzstart
    let c2da_fresh5 : int = int(uint(c2da_mem[t1 + 24]) | uint(c2da_mem[t1 + 25]) << 0x8 | uint(c2da_mem[t1 + 26]) << 0x10 | uint(c2da_mem[t1 + 27]) << 0x18)
    let c2da_fresh6 : uint = uint(c2da_fresh5)
    c2da_mem[64800] = uint8(c2da_fresh6)
    c2da_mem[64801] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[64802] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[64803] = uint8(c2da_fresh6 >> 0x18)
    let c2da_fresh7 : int = int(uint(c2da_mem[t1 + 28]) | uint(c2da_mem[t1 + 29]) << 0x8 | uint(c2da_mem[t1 + 30]) << 0x10 | uint(c2da_mem[t1 + 31]) << 0x18)
    let c2da_fresh8 : uint = uint(c2da_fresh7)
    c2da_mem[64804] = uint8(c2da_fresh8)
    c2da_mem[64805] = uint8(c2da_fresh8 >> 0x8)
    c2da_mem[64806] = uint8(c2da_fresh8 >> 0x10)
    c2da_mem[64807] = uint8(c2da_fresh8 >> 0x18)
    t2x = int(uint(c2da_mem[t2 + 24]) | uint(c2da_mem[t2 + 25]) << 0x8 | uint(c2da_mem[t2 + 26]) << 0x10 | uint(c2da_mem[t2 + 27]) << 0x18)
    t2y = int(uint(c2da_mem[t2 + 28]) | uint(c2da_mem[t2 + 29]) << 0x8 | uint(c2da_mem[t2 + 30]) << 0x10 | uint(c2da_mem[t2 + 31]) << 0x18)
    let c2da_fresh9 : int = int(uint(c2da_mem[t2 + 24]) | uint(c2da_mem[t2 + 25]) << 0x8 | uint(c2da_mem[t2 + 26]) << 0x10 | uint(c2da_mem[t2 + 27]) << 0x18) - int(uint(c2da_mem[t1 + 24]) | uint(c2da_mem[t1 + 25]) << 0x8 | uint(c2da_mem[t1 + 26]) << 0x10 | uint(c2da_mem[t1 + 27]) << 0x18)
    let c2da_fresh10 : uint = uint(c2da_fresh9)
    c2da_mem[64808] = uint8(c2da_fresh10)
    c2da_mem[64809] = uint8(c2da_fresh10 >> 0x8)
    c2da_mem[64810] = uint8(c2da_fresh10 >> 0x10)
    c2da_mem[64811] = uint8(c2da_fresh10 >> 0x18)
    let c2da_fresh11 : int = int(uint(c2da_mem[t2 + 28]) | uint(c2da_mem[t2 + 29]) << 0x8 | uint(c2da_mem[t2 + 30]) << 0x10 | uint(c2da_mem[t2 + 31]) << 0x18) - int(uint(c2da_mem[t1 + 28]) | uint(c2da_mem[t1 + 29]) << 0x8 | uint(c2da_mem[t1 + 30]) << 0x10 | uint(c2da_mem[t1 + 31]) << 0x18)
    let c2da_fresh12 : uint = uint(c2da_fresh11)
    c2da_mem[64812] = uint8(c2da_fresh12)
    c2da_mem[64813] = uint8(c2da_fresh12 >> 0x8)
    c2da_mem[64814] = uint8(c2da_fresh12 >> 0x10)
    c2da_mem[64815] = uint8(c2da_fresh12 >> 0x18)
    return P_CrossBSPNode(numnodes - 1)
}
[export, sideeffects]
def P_CrossBSPNode(var bspnum : int) : uint {
    var bsp : int
    var side : int
    if ((bspnum & 32768) != 0) {
        if (bspnum == -1) {
            return P_CrossSubsector(0)
        } else {
            return P_CrossSubsector(bspnum & ~32768)
        }
    }
    bsp = nodes + bspnum * 52
    side = P_DivlineSide(int(uint(c2da_mem[64800]) | uint(c2da_mem[64801]) << 0x8 | uint(c2da_mem[64802]) << 0x10 | uint(c2da_mem[64803]) << 0x18), int(uint(c2da_mem[64804]) | uint(c2da_mem[64805]) << 0x8 | uint(c2da_mem[64806]) << 0x10 | uint(c2da_mem[64807]) << 0x18), bsp)
    if (side == 2) {
        side = 0
    }
    if (P_CrossBSPNode(int(uint16(uint(c2da_mem[bsp + 48 + side * 2]) | uint(c2da_mem[bsp + 48 + side * 2 + 1]) << 0x8))) == 0) {
        return 0u
    }
    if (side == P_DivlineSide(t2x, t2y, bsp)) {
        return 1u
    }
    let c2da_fresh13 : int = bsp + 48 + (side ^ 1) * 2
    return P_CrossBSPNode(int(uint16(uint(c2da_mem[c2da_fresh13]) | uint(c2da_mem[c2da_fresh13 + 1]) << 0x8)))
}
var t2y : int = default<int>

var t2x : int = default<int>

[export, sideeffects]
def P_DivlineSide(var x : int; var y : int; var node : int) : int {
    var left : int
    var right : int
    if (int(uint(c2da_mem[node + 8]) | uint(c2da_mem[node + 9]) << 0x8 | uint(c2da_mem[node + 10]) << 0x10 | uint(c2da_mem[node + 11]) << 0x18) == 0) {
        if (x == int(uint(c2da_mem[node]) | uint(c2da_mem[node + 1]) << 0x8 | uint(c2da_mem[node + 2]) << 0x10 | uint(c2da_mem[node + 3]) << 0x18)) {
            return 2
        }
        if (x <= int(uint(c2da_mem[node]) | uint(c2da_mem[node + 1]) << 0x8 | uint(c2da_mem[node + 2]) << 0x10 | uint(c2da_mem[node + 3]) << 0x18)) {
            return int(uint(c2da_mem[node + 12]) | uint(c2da_mem[node + 13]) << 0x8 | uint(c2da_mem[node + 14]) << 0x10 | uint(c2da_mem[node + 15]) << 0x18) > 0 ? 1 : 0
        }
        return int(uint(c2da_mem[node + 12]) | uint(c2da_mem[node + 13]) << 0x8 | uint(c2da_mem[node + 14]) << 0x10 | uint(c2da_mem[node + 15]) << 0x18) < 0 ? 1 : 0
    }
    if (int(uint(c2da_mem[node + 12]) | uint(c2da_mem[node + 13]) << 0x8 | uint(c2da_mem[node + 14]) << 0x10 | uint(c2da_mem[node + 15]) << 0x18) == 0) {
        if (x == int(uint(c2da_mem[node + 4]) | uint(c2da_mem[node + 5]) << 0x8 | uint(c2da_mem[node + 6]) << 0x10 | uint(c2da_mem[node + 7]) << 0x18)) {
            return 2
        }
        if (y <= int(uint(c2da_mem[node + 4]) | uint(c2da_mem[node + 5]) << 0x8 | uint(c2da_mem[node + 6]) << 0x10 | uint(c2da_mem[node + 7]) << 0x18)) {
            return int(uint(c2da_mem[node + 8]) | uint(c2da_mem[node + 9]) << 0x8 | uint(c2da_mem[node + 10]) << 0x10 | uint(c2da_mem[node + 11]) << 0x18) < 0 ? 1 : 0
        }
        return int(uint(c2da_mem[node + 8]) | uint(c2da_mem[node + 9]) << 0x8 | uint(c2da_mem[node + 10]) << 0x10 | uint(c2da_mem[node + 11]) << 0x18) > 0 ? 1 : 0
    }
    left = (int(uint(c2da_mem[node + 12]) | uint(c2da_mem[node + 13]) << 0x8 | uint(c2da_mem[node + 14]) << 0x10 | uint(c2da_mem[node + 15]) << 0x18) >> 16) * (x - int(uint(c2da_mem[node]) | uint(c2da_mem[node + 1]) << 0x8 | uint(c2da_mem[node + 2]) << 0x10 | uint(c2da_mem[node + 3]) << 0x18) >> 16)
    right = (y - int(uint(c2da_mem[node + 4]) | uint(c2da_mem[node + 5]) << 0x8 | uint(c2da_mem[node + 6]) << 0x10 | uint(c2da_mem[node + 7]) << 0x18) >> 16) * (int(uint(c2da_mem[node + 8]) | uint(c2da_mem[node + 9]) << 0x8 | uint(c2da_mem[node + 10]) << 0x10 | uint(c2da_mem[node + 11]) << 0x18) >> 16)
    if (right < left) {
        return 0
    }
    if (left == right) {
        return 2
    }
    return 1
}
[export, sideeffects]
def P_CrossSubsector(var num : int) : uint {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : uint = P_CrossSubsector_c2da_frame(num, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
var bottomslope : int = default<int>

var topslope : int = default<int>

var sightzstart : int = default<int>

[export, sideeffects]
def P_InterceptVector2(var v2_0 : int; var v1_0 : int) : int {
    var frac_0 : int
    var num_0 : int
    var den : int = FixedMul(int(uint(c2da_mem[v1_0 + 12]) | uint(c2da_mem[v1_0 + 13]) << 0x8 | uint(c2da_mem[v1_0 + 14]) << 0x10 | uint(c2da_mem[v1_0 + 15]) << 0x18) >> 8, int(uint(c2da_mem[v2_0 + 8]) | uint(c2da_mem[v2_0 + 9]) << 0x8 | uint(c2da_mem[v2_0 + 10]) << 0x10 | uint(c2da_mem[v2_0 + 11]) << 0x18)) - FixedMul(int(uint(c2da_mem[v1_0 + 8]) | uint(c2da_mem[v1_0 + 9]) << 0x8 | uint(c2da_mem[v1_0 + 10]) << 0x10 | uint(c2da_mem[v1_0 + 11]) << 0x18) >> 8, int(uint(c2da_mem[v2_0 + 12]) | uint(c2da_mem[v2_0 + 13]) << 0x8 | uint(c2da_mem[v2_0 + 14]) << 0x10 | uint(c2da_mem[v2_0 + 15]) << 0x18))
    if (den == 0) {
        return 0
    }
    num_0 = FixedMul(int(uint(c2da_mem[v1_0]) | uint(c2da_mem[v1_0 + 1]) << 0x8 | uint(c2da_mem[v1_0 + 2]) << 0x10 | uint(c2da_mem[v1_0 + 3]) << 0x18) - int(uint(c2da_mem[v2_0]) | uint(c2da_mem[v2_0 + 1]) << 0x8 | uint(c2da_mem[v2_0 + 2]) << 0x10 | uint(c2da_mem[v2_0 + 3]) << 0x18) >> 8, int(uint(c2da_mem[v1_0 + 12]) | uint(c2da_mem[v1_0 + 13]) << 0x8 | uint(c2da_mem[v1_0 + 14]) << 0x10 | uint(c2da_mem[v1_0 + 15]) << 0x18)) + FixedMul(int(uint(c2da_mem[v2_0 + 4]) | uint(c2da_mem[v2_0 + 5]) << 0x8 | uint(c2da_mem[v2_0 + 6]) << 0x10 | uint(c2da_mem[v2_0 + 7]) << 0x18) - int(uint(c2da_mem[v1_0 + 4]) | uint(c2da_mem[v1_0 + 5]) << 0x8 | uint(c2da_mem[v1_0 + 6]) << 0x10 | uint(c2da_mem[v1_0 + 7]) << 0x18) >> 8, int(uint(c2da_mem[v1_0 + 8]) | uint(c2da_mem[v1_0 + 9]) << 0x8 | uint(c2da_mem[v1_0 + 10]) << 0x10 | uint(c2da_mem[v1_0 + 11]) << 0x18))
    frac_0 = FixedDiv(num_0, den)
    return frac_0
}
var sightcounts : int[2]

[sideeffects]
def private P_CrossSubsector_c2da_frame(var num : int; c2da_fp : int) : uint {
    var seg : int
    var line : int
    var s1_0 : int
    var s2_0 : int
    var count : int
    var sub : int
    var front : int
    var back : int
    var opentop_0 : int
    var openbottom_0 : int
    var v1 : int
    var v2 : int
    var frac : int
    var slope : int
    if (num >= numsubsectors) {
        I_Error(361136, [C2daVaArg(tag = 1, i64 = int64(num), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(numsubsectors), f64 = 0.0lf, raw = 0x0)])
    }
    sub = subsectors + num * 16
    count = int(int16(uint(c2da_mem[sub + 8]) | uint(c2da_mem[sub + 9]) << 0x8))
    seg = segs + int(int16(uint(c2da_mem[sub + 10]) | uint(c2da_mem[sub + 11]) << 0x8)) * 56
    while (count != 0) {
        line = int(uint(c2da_mem[seg + 32]) | uint(c2da_mem[seg + 33]) << 0x8 | uint(c2da_mem[seg + 34]) << 0x10 | uint(c2da_mem[seg + 35]) << 0x18)
        if (int(uint(c2da_mem[line + 72]) | uint(c2da_mem[line + 73]) << 0x8 | uint(c2da_mem[line + 74]) << 0x10 | uint(c2da_mem[line + 75]) << 0x18) == validcount) {
            seg += 56
            count--
            continue
        }
        let c2da_fresh14 : uint = uint(validcount)
        c2da_mem[line + 72] = uint8(c2da_fresh14)
        c2da_mem[line + 73] = uint8(c2da_fresh14 >> 0x8)
        c2da_mem[line + 74] = uint8(c2da_fresh14 >> 0x10)
        c2da_mem[line + 75] = uint8(c2da_fresh14 >> 0x18)
        v1 = int(uint(c2da_mem[line]) | uint(c2da_mem[line + 1]) << 0x8 | uint(c2da_mem[line + 2]) << 0x10 | uint(c2da_mem[line + 3]) << 0x18)
        v2 = int(uint(c2da_mem[line + 8]) | uint(c2da_mem[line + 9]) << 0x8 | uint(c2da_mem[line + 10]) << 0x10 | uint(c2da_mem[line + 11]) << 0x18)
        s1_0 = P_DivlineSide(int(uint(c2da_mem[v1]) | uint(c2da_mem[v1 + 1]) << 0x8 | uint(c2da_mem[v1 + 2]) << 0x10 | uint(c2da_mem[v1 + 3]) << 0x18), int(uint(c2da_mem[v1 + 4]) | uint(c2da_mem[v1 + 5]) << 0x8 | uint(c2da_mem[v1 + 6]) << 0x10 | uint(c2da_mem[v1 + 7]) << 0x18), 64800)
        s2_0 = P_DivlineSide(int(uint(c2da_mem[v2]) | uint(c2da_mem[v2 + 1]) << 0x8 | uint(c2da_mem[v2 + 2]) << 0x10 | uint(c2da_mem[v2 + 3]) << 0x18), int(uint(c2da_mem[v2 + 4]) | uint(c2da_mem[v2 + 5]) << 0x8 | uint(c2da_mem[v2 + 6]) << 0x10 | uint(c2da_mem[v2 + 7]) << 0x18), 64800)
        if (s1_0 == s2_0) {
            seg += 56
            count--
            continue
        }
        let c2da_fresh15 : int = int(uint(c2da_mem[v1]) | uint(c2da_mem[v1 + 1]) << 0x8 | uint(c2da_mem[v1 + 2]) << 0x10 | uint(c2da_mem[v1 + 3]) << 0x18)
        let c2da_fresh16 : uint = uint(c2da_fresh15)
        c2da_mem[c2da_fp] = uint8(c2da_fresh16)
        c2da_mem[c2da_fp + 1] = uint8(c2da_fresh16 >> 0x8)
        c2da_mem[c2da_fp + 2] = uint8(c2da_fresh16 >> 0x10)
        c2da_mem[c2da_fp + 3] = uint8(c2da_fresh16 >> 0x18)
        let c2da_fresh17 : int = int(uint(c2da_mem[v1 + 4]) | uint(c2da_mem[v1 + 5]) << 0x8 | uint(c2da_mem[v1 + 6]) << 0x10 | uint(c2da_mem[v1 + 7]) << 0x18)
        let c2da_fresh18 : uint = uint(c2da_fresh17)
        c2da_mem[c2da_fp + 4] = uint8(c2da_fresh18)
        c2da_mem[c2da_fp + 5] = uint8(c2da_fresh18 >> 0x8)
        c2da_mem[c2da_fp + 6] = uint8(c2da_fresh18 >> 0x10)
        c2da_mem[c2da_fp + 7] = uint8(c2da_fresh18 >> 0x18)
        let c2da_fresh19 : int = int(uint(c2da_mem[v2]) | uint(c2da_mem[v2 + 1]) << 0x8 | uint(c2da_mem[v2 + 2]) << 0x10 | uint(c2da_mem[v2 + 3]) << 0x18) - int(uint(c2da_mem[v1]) | uint(c2da_mem[v1 + 1]) << 0x8 | uint(c2da_mem[v1 + 2]) << 0x10 | uint(c2da_mem[v1 + 3]) << 0x18)
        let c2da_fresh20 : uint = uint(c2da_fresh19)
        c2da_mem[c2da_fp + 8] = uint8(c2da_fresh20)
        c2da_mem[c2da_fp + 9] = uint8(c2da_fresh20 >> 0x8)
        c2da_mem[c2da_fp + 10] = uint8(c2da_fresh20 >> 0x10)
        c2da_mem[c2da_fp + 11] = uint8(c2da_fresh20 >> 0x18)
        let c2da_fresh21 : int = int(uint(c2da_mem[v2 + 4]) | uint(c2da_mem[v2 + 5]) << 0x8 | uint(c2da_mem[v2 + 6]) << 0x10 | uint(c2da_mem[v2 + 7]) << 0x18) - int(uint(c2da_mem[v1 + 4]) | uint(c2da_mem[v1 + 5]) << 0x8 | uint(c2da_mem[v1 + 6]) << 0x10 | uint(c2da_mem[v1 + 7]) << 0x18)
        let c2da_fresh22 : uint = uint(c2da_fresh21)
        c2da_mem[c2da_fp + 12] = uint8(c2da_fresh22)
        c2da_mem[c2da_fp + 13] = uint8(c2da_fresh22 >> 0x8)
        c2da_mem[c2da_fp + 14] = uint8(c2da_fresh22 >> 0x10)
        c2da_mem[c2da_fp + 15] = uint8(c2da_fresh22 >> 0x18)
        s1_0 = P_DivlineSide(int(uint(c2da_mem[64800]) | uint(c2da_mem[64801]) << 0x8 | uint(c2da_mem[64802]) << 0x10 | uint(c2da_mem[64803]) << 0x18), int(uint(c2da_mem[64804]) | uint(c2da_mem[64805]) << 0x8 | uint(c2da_mem[64806]) << 0x10 | uint(c2da_mem[64807]) << 0x18), c2da_fp)
        s2_0 = P_DivlineSide(t2x, t2y, c2da_fp)
        if (s1_0 == s2_0) {
            seg += 56
            count--
            continue
        }
        if (int(uint(c2da_mem[line + 64]) | uint(c2da_mem[line + 65]) << 0x8 | uint(c2da_mem[line + 66]) << 0x10 | uint(c2da_mem[line + 67]) << 0x18) == 0) {
            return 0u
        }
        if ((int(int16(uint(c2da_mem[line + 24]) | uint(c2da_mem[line + 25]) << 0x8)) & 4) == 0) {
            return 0u
        }
        front = int(uint(c2da_mem[seg + 40]) | uint(c2da_mem[seg + 41]) << 0x8 | uint(c2da_mem[seg + 42]) << 0x10 | uint(c2da_mem[seg + 43]) << 0x18)
        back = int(uint(c2da_mem[seg + 48]) | uint(c2da_mem[seg + 49]) << 0x8 | uint(c2da_mem[seg + 50]) << 0x10 | uint(c2da_mem[seg + 51]) << 0x18)
        if (int(uint(c2da_mem[front]) | uint(c2da_mem[front + 1]) << 0x8 | uint(c2da_mem[front + 2]) << 0x10 | uint(c2da_mem[front + 3]) << 0x18) == int(uint(c2da_mem[back]) | uint(c2da_mem[back + 1]) << 0x8 | uint(c2da_mem[back + 2]) << 0x10 | uint(c2da_mem[back + 3]) << 0x18) && int(uint(c2da_mem[front + 4]) | uint(c2da_mem[front + 5]) << 0x8 | uint(c2da_mem[front + 6]) << 0x10 | uint(c2da_mem[front + 7]) << 0x18) == int(uint(c2da_mem[back + 4]) | uint(c2da_mem[back + 5]) << 0x8 | uint(c2da_mem[back + 6]) << 0x10 | uint(c2da_mem[back + 7]) << 0x18)) {
            seg += 56
            count--
            continue
        }
        if (int(uint(c2da_mem[front + 4]) | uint(c2da_mem[front + 5]) << 0x8 | uint(c2da_mem[front + 6]) << 0x10 | uint(c2da_mem[front + 7]) << 0x18) < int(uint(c2da_mem[back + 4]) | uint(c2da_mem[back + 5]) << 0x8 | uint(c2da_mem[back + 6]) << 0x10 | uint(c2da_mem[back + 7]) << 0x18)) {
            opentop_0 = int(uint(c2da_mem[front + 4]) | uint(c2da_mem[front + 5]) << 0x8 | uint(c2da_mem[front + 6]) << 0x10 | uint(c2da_mem[front + 7]) << 0x18)
        } else {
            opentop_0 = int(uint(c2da_mem[back + 4]) | uint(c2da_mem[back + 5]) << 0x8 | uint(c2da_mem[back + 6]) << 0x10 | uint(c2da_mem[back + 7]) << 0x18)
        }
        if (int(uint(c2da_mem[front]) | uint(c2da_mem[front + 1]) << 0x8 | uint(c2da_mem[front + 2]) << 0x10 | uint(c2da_mem[front + 3]) << 0x18) > int(uint(c2da_mem[back]) | uint(c2da_mem[back + 1]) << 0x8 | uint(c2da_mem[back + 2]) << 0x10 | uint(c2da_mem[back + 3]) << 0x18)) {
            openbottom_0 = int(uint(c2da_mem[front]) | uint(c2da_mem[front + 1]) << 0x8 | uint(c2da_mem[front + 2]) << 0x10 | uint(c2da_mem[front + 3]) << 0x18)
        } else {
            openbottom_0 = int(uint(c2da_mem[back]) | uint(c2da_mem[back + 1]) << 0x8 | uint(c2da_mem[back + 2]) << 0x10 | uint(c2da_mem[back + 3]) << 0x18)
        }
        if (openbottom_0 >= opentop_0) {
            return 0u
        }
        frac = P_InterceptVector2(64800, c2da_fp)
        if (int(uint(c2da_mem[front]) | uint(c2da_mem[front + 1]) << 0x8 | uint(c2da_mem[front + 2]) << 0x10 | uint(c2da_mem[front + 3]) << 0x18) != int(uint(c2da_mem[back]) | uint(c2da_mem[back + 1]) << 0x8 | uint(c2da_mem[back + 2]) << 0x10 | uint(c2da_mem[back + 3]) << 0x18)) {
            slope = FixedDiv(openbottom_0 - sightzstart, frac)
            if (slope > bottomslope) {
                bottomslope = slope
            }
        }
        if (int(uint(c2da_mem[front + 4]) | uint(c2da_mem[front + 5]) << 0x8 | uint(c2da_mem[front + 6]) << 0x10 | uint(c2da_mem[front + 7]) << 0x18) != int(uint(c2da_mem[back + 4]) | uint(c2da_mem[back + 5]) << 0x8 | uint(c2da_mem[back + 6]) << 0x10 | uint(c2da_mem[back + 7]) << 0x18)) {
            slope = FixedDiv(opentop_0 - sightzstart, frac)
            if (slope < topslope) {
                topslope = slope
            }
        }
        if (topslope <= bottomslope) {
            return 0u
        }
        seg += 56
        count--
    }
    return 1u
}

// This unit's static data, at heap offset 361136.
let private c2da_lin_static_p_sight_seg = fixed_array<int>(361136, 39)
let private c2da_lin_static_p_sight = fixed_array<uint64>(0x5373736f72435f50ul, 0x726f746365736275ul, 0x206925207373203aul, 0x6d756e2068746977ul, 0x6925203d207373ul)

[init]
def private c2da_lin_init_static_p_sight() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_p_sight_seg[s * 2]
        for (k in range(c2da_lin_static_p_sight_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_p_sight[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
