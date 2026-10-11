var private GetSectorAtNullAddress__null_sector_is_initialized : uint = 0u

var numvertexes : int = default<int>

var vertexes : int = default<int>

var numsegs : int = default<int>

var segs : int = default<int>

var numsectors : int = default<int>

var sectors : int = default<int>

var numsubsectors : int = default<int>

var subsectors : int = default<int>

var numnodes : int = default<int>

var nodes : int = default<int>

var numlines : int = default<int>

var lines : int = default<int>

var numsides : int = default<int>

var sides : int = default<int>

var blockmaplump : int = default<int>

var blockmap : int = default<int>

var blocklinks : int = default<int>

var deathmatch_p : int = default<int>

var private totallines : int = default<int>

[export, sideeffects]
def P_LoadVertexes(var lump : int) {
    var data : int
    var i : int
    var ml : int
    var li : int
    numvertexes = int(uint64(W_LumpLength(uint(lump))) / 4ul)
    vertexes = Z_Malloc(int(uint64(numvertexes) * 8ul), 5, 0)
    data = W_CacheLumpNum(lump, 1)
    ml = data
    li = vertexes
    i = 0
    while (i < numvertexes) {
        let c2da_fresh0 : int = int(int16(uint(c2da_mem[ml]) | uint(c2da_mem[ml + 1]) << 0x8)) << 16
        let c2da_fresh1 : uint = uint(c2da_fresh0)
        c2da_mem[li] = uint8(c2da_fresh1)
        c2da_mem[li + 1] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[li + 2] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[li + 3] = uint8(c2da_fresh1 >> 0x18)
        let c2da_fresh2 : int = int(int16(uint(c2da_mem[ml + 2]) | uint(c2da_mem[ml + 3]) << 0x8)) << 16
        let c2da_fresh3 : uint = uint(c2da_fresh2)
        c2da_mem[li + 4] = uint8(c2da_fresh3)
        c2da_mem[li + 5] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[li + 6] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[li + 7] = uint8(c2da_fresh3 >> 0x18)
        i++
        li += 8
        ml += 4
    }
    W_ReleaseLumpNum(lump)
    return
}
[export, sideeffects]
def GetSectorAtNullAddress() : int {
    if (GetSectorAtNullAddress__null_sector_is_initialized == 0) {
        c2da_lin_memset(360912, 0, 128ul)
        I_GetMemoryValue(0u, 360912, 4)
        I_GetMemoryValue(4u, 360916, 4)
        GetSectorAtNullAddress__null_sector_is_initialized = 1u
    }
    return 360912
}
[export, sideeffects]
def P_LoadSegs(var lump_0 : int) {
    var data_0 : int
    var i_0 : int
    var ml_0 : int
    var li_0 : int
    var ldef : int
    var linedef_0 : int
    var side : int
    var sidenum : int
    numsegs = int(uint64(W_LumpLength(uint(lump_0))) / 12ul)
    segs = Z_Malloc(int(uint64(numsegs) * 56ul), 5, 0)
    c2da_lin_memset(segs, 0, uint64(numsegs) * 56ul)
    data_0 = W_CacheLumpNum(lump_0, 1)
    ml_0 = data_0
    li_0 = segs
    i_0 = 0
    while (i_0 < numsegs) {
        let c2da_fresh4 : int = vertexes + int(int16(uint(c2da_mem[ml_0]) | uint(c2da_mem[ml_0 + 1]) << 0x8)) * 8
        let c2da_fresh5 : uint = uint(c2da_fresh4)
        c2da_mem[li_0] = uint8(c2da_fresh5)
        c2da_mem[li_0 + 1] = uint8(c2da_fresh5 >> 0x8)
        c2da_mem[li_0 + 2] = uint8(c2da_fresh5 >> 0x10)
        c2da_mem[li_0 + 3] = uint8(c2da_fresh5 >> 0x18)
        c2da_mem[li_0 + 4] = 0u8
        c2da_mem[li_0 + 5] = 0u8
        c2da_mem[li_0 + 6] = 0u8
        c2da_mem[li_0 + 7] = 0u8
        let c2da_fresh6 : int = vertexes + int(int16(uint(c2da_mem[ml_0 + 2]) | uint(c2da_mem[ml_0 + 3]) << 0x8)) * 8
        let c2da_fresh7 : uint = uint(c2da_fresh6)
        c2da_mem[li_0 + 8] = uint8(c2da_fresh7)
        c2da_mem[li_0 + 9] = uint8(c2da_fresh7 >> 0x8)
        c2da_mem[li_0 + 10] = uint8(c2da_fresh7 >> 0x10)
        c2da_mem[li_0 + 11] = uint8(c2da_fresh7 >> 0x18)
        c2da_mem[li_0 + 12] = 0u8
        c2da_mem[li_0 + 13] = 0u8
        c2da_mem[li_0 + 14] = 0u8
        c2da_mem[li_0 + 15] = 0u8
        let c2da_fresh8 : uint = uint(int(int16(uint(c2da_mem[ml_0 + 4]) | uint(c2da_mem[ml_0 + 5]) << 0x8)) << 16)
        let c2da_fresh9 : uint = c2da_fresh8
        c2da_mem[li_0 + 20] = uint8(c2da_fresh9)
        c2da_mem[li_0 + 21] = uint8(c2da_fresh9 >> 0x8)
        c2da_mem[li_0 + 22] = uint8(c2da_fresh9 >> 0x10)
        c2da_mem[li_0 + 23] = uint8(c2da_fresh9 >> 0x18)
        let c2da_fresh10 : int = int(int16(uint(c2da_mem[ml_0 + 10]) | uint(c2da_mem[ml_0 + 11]) << 0x8)) << 16
        let c2da_fresh11 : uint = uint(c2da_fresh10)
        c2da_mem[li_0 + 16] = uint8(c2da_fresh11)
        c2da_mem[li_0 + 17] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[li_0 + 18] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[li_0 + 19] = uint8(c2da_fresh11 >> 0x18)
        linedef_0 = int(int16(uint(c2da_mem[ml_0 + 6]) | uint(c2da_mem[ml_0 + 7]) << 0x8))
        ldef = lines + linedef_0 * 88
        let c2da_fresh12 : uint = uint(ldef)
        c2da_mem[li_0 + 32] = uint8(c2da_fresh12)
        c2da_mem[li_0 + 33] = uint8(c2da_fresh12 >> 0x8)
        c2da_mem[li_0 + 34] = uint8(c2da_fresh12 >> 0x10)
        c2da_mem[li_0 + 35] = uint8(c2da_fresh12 >> 0x18)
        c2da_mem[li_0 + 36] = 0u8
        c2da_mem[li_0 + 37] = 0u8
        c2da_mem[li_0 + 38] = 0u8
        c2da_mem[li_0 + 39] = 0u8
        side = int(int16(uint(c2da_mem[ml_0 + 8]) | uint(c2da_mem[ml_0 + 9]) << 0x8))
        let c2da_fresh13 : int = sides + int(int16(uint(c2da_mem[ldef + 30 + side * 2]) | uint(c2da_mem[ldef + 30 + side * 2 + 1]) << 0x8)) * 24
        let c2da_fresh14 : uint = uint(c2da_fresh13)
        c2da_mem[li_0 + 24] = uint8(c2da_fresh14)
        c2da_mem[li_0 + 25] = uint8(c2da_fresh14 >> 0x8)
        c2da_mem[li_0 + 26] = uint8(c2da_fresh14 >> 0x10)
        c2da_mem[li_0 + 27] = uint8(c2da_fresh14 >> 0x18)
        c2da_mem[li_0 + 28] = 0u8
        c2da_mem[li_0 + 29] = 0u8
        c2da_mem[li_0 + 30] = 0u8
        c2da_mem[li_0 + 31] = 0u8
        let c2da_fresh15 : int = sides + int(int16(uint(c2da_mem[ldef + 30 + side * 2]) | uint(c2da_mem[ldef + 30 + side * 2 + 1]) << 0x8)) * 24 + 16
        let c2da_fresh16 : int = int(uint(c2da_mem[c2da_fresh15]) | uint(c2da_mem[c2da_fresh15 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh15 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh15 + 3]) << 0x18)
        let c2da_fresh17 : uint = uint(c2da_fresh16)
        c2da_mem[li_0 + 40] = uint8(c2da_fresh17)
        c2da_mem[li_0 + 41] = uint8(c2da_fresh17 >> 0x8)
        c2da_mem[li_0 + 42] = uint8(c2da_fresh17 >> 0x10)
        c2da_mem[li_0 + 43] = uint8(c2da_fresh17 >> 0x18)
        c2da_mem[li_0 + 44] = 0u8
        c2da_mem[li_0 + 45] = 0u8
        c2da_mem[li_0 + 46] = 0u8
        c2da_mem[li_0 + 47] = 0u8
        if ((int(int16(uint(c2da_mem[ldef + 24]) | uint(c2da_mem[ldef + 25]) << 0x8)) & 4) != 0) {
            let c2da_fresh18 : int = ldef + 30 + (side ^ 1) * 2
            sidenum = int(int16(uint(c2da_mem[c2da_fresh18]) | uint(c2da_mem[c2da_fresh18 + 1]) << 0x8))
            if (sidenum < 0 || sidenum >= numsides) {
                let c2da_fresh19 : int = GetSectorAtNullAddress()
                let c2da_fresh20 : uint = uint(c2da_fresh19)
                c2da_mem[li_0 + 48] = uint8(c2da_fresh20)
                c2da_mem[li_0 + 49] = uint8(c2da_fresh20 >> 0x8)
                c2da_mem[li_0 + 50] = uint8(c2da_fresh20 >> 0x10)
                c2da_mem[li_0 + 51] = uint8(c2da_fresh20 >> 0x18)
                c2da_mem[li_0 + 52] = 0u8
                c2da_mem[li_0 + 53] = 0u8
                c2da_mem[li_0 + 54] = 0u8
                c2da_mem[li_0 + 55] = 0u8
            } else {
                let c2da_fresh21 : int = int(uint(c2da_mem[sides + sidenum * 24 + 16]) | uint(c2da_mem[sides + sidenum * 24 + 17]) << 0x8 | uint(c2da_mem[sides + sidenum * 24 + 18]) << 0x10 | uint(c2da_mem[sides + sidenum * 24 + 19]) << 0x18)
                let c2da_fresh22 : uint = uint(c2da_fresh21)
                c2da_mem[li_0 + 48] = uint8(c2da_fresh22)
                c2da_mem[li_0 + 49] = uint8(c2da_fresh22 >> 0x8)
                c2da_mem[li_0 + 50] = uint8(c2da_fresh22 >> 0x10)
                c2da_mem[li_0 + 51] = uint8(c2da_fresh22 >> 0x18)
                c2da_mem[li_0 + 52] = 0u8
                c2da_mem[li_0 + 53] = 0u8
                c2da_mem[li_0 + 54] = 0u8
                c2da_mem[li_0 + 55] = 0u8
            }
        } else {
            let c2da_fresh23 : uint = 0u
            c2da_mem[li_0 + 48] = uint8(c2da_fresh23)
            c2da_mem[li_0 + 49] = uint8(c2da_fresh23 >> 0x8)
            c2da_mem[li_0 + 50] = uint8(c2da_fresh23 >> 0x10)
            c2da_mem[li_0 + 51] = uint8(c2da_fresh23 >> 0x18)
            c2da_mem[li_0 + 52] = 0u8
            c2da_mem[li_0 + 53] = 0u8
            c2da_mem[li_0 + 54] = 0u8
            c2da_mem[li_0 + 55] = 0u8
        }
        i_0++
        li_0 += 56
        ml_0 += 12
    }
    W_ReleaseLumpNum(lump_0)
    return
}
[export, sideeffects]
def P_LoadSubsectors(var lump_1 : int) {
    var data_1 : int
    var i_1 : int
    var ms : int
    var ss : int
    numsubsectors = int(uint64(W_LumpLength(uint(lump_1))) / 4ul)
    subsectors = Z_Malloc(int(uint64(numsubsectors) * 16ul), 5, 0)
    data_1 = W_CacheLumpNum(lump_1, 1)
    ms = data_1
    c2da_lin_memset(subsectors, 0, uint64(numsubsectors) * 16ul)
    ss = subsectors
    i_1 = 0
    while (i_1 < numsubsectors) {
        let c2da_fresh24 : int16 = int16(uint(c2da_mem[ms]) | uint(c2da_mem[ms + 1]) << 0x8)
        let c2da_fresh25 : uint = uint(c2da_fresh24)
        c2da_mem[ss + 8] = uint8(c2da_fresh25)
        c2da_mem[ss + 9] = uint8(c2da_fresh25 >> 0x8)
        let c2da_fresh26 : int16 = int16(uint(c2da_mem[ms + 2]) | uint(c2da_mem[ms + 3]) << 0x8)
        let c2da_fresh27 : uint = uint(c2da_fresh26)
        c2da_mem[ss + 10] = uint8(c2da_fresh27)
        c2da_mem[ss + 11] = uint8(c2da_fresh27 >> 0x8)
        i_1++
        ss += 16
        ms += 4
    }
    W_ReleaseLumpNum(lump_1)
    return
}
[export, sideeffects]
def P_LoadSectors(var lump_2 : int) {
    var data_2 : int
    var i_2 : int
    var ms_0 : int
    var ss_0 : int
    numsectors = int(uint64(W_LumpLength(uint(lump_2))) / 26ul)
    sectors = Z_Malloc(int(uint64(numsectors) * 128ul), 5, 0)
    c2da_lin_memset(sectors, 0, uint64(numsectors) * 128ul)
    data_2 = W_CacheLumpNum(lump_2, 1)
    ms_0 = data_2
    ss_0 = sectors
    i_2 = 0
    while (i_2 < numsectors) {
        let c2da_fresh28 : int = int(int16(uint(c2da_mem[ms_0]) | uint(c2da_mem[ms_0 + 1]) << 0x8)) << 16
        let c2da_fresh29 : uint = uint(c2da_fresh28)
        c2da_mem[ss_0] = uint8(c2da_fresh29)
        c2da_mem[ss_0 + 1] = uint8(c2da_fresh29 >> 0x8)
        c2da_mem[ss_0 + 2] = uint8(c2da_fresh29 >> 0x10)
        c2da_mem[ss_0 + 3] = uint8(c2da_fresh29 >> 0x18)
        let c2da_fresh30 : int = int(int16(uint(c2da_mem[ms_0 + 2]) | uint(c2da_mem[ms_0 + 3]) << 0x8)) << 16
        let c2da_fresh31 : uint = uint(c2da_fresh30)
        c2da_mem[ss_0 + 4] = uint8(c2da_fresh31)
        c2da_mem[ss_0 + 5] = uint8(c2da_fresh31 >> 0x8)
        c2da_mem[ss_0 + 6] = uint8(c2da_fresh31 >> 0x10)
        c2da_mem[ss_0 + 7] = uint8(c2da_fresh31 >> 0x18)
        let c2da_fresh32 : int16 = int16(R_FlatNumForName(ms_0 + 4))
        let c2da_fresh33 : uint = uint(c2da_fresh32)
        c2da_mem[ss_0 + 8] = uint8(c2da_fresh33)
        c2da_mem[ss_0 + 9] = uint8(c2da_fresh33 >> 0x8)
        let c2da_fresh34 : int16 = int16(R_FlatNumForName(ms_0 + 12))
        let c2da_fresh35 : uint = uint(c2da_fresh34)
        c2da_mem[ss_0 + 10] = uint8(c2da_fresh35)
        c2da_mem[ss_0 + 11] = uint8(c2da_fresh35 >> 0x8)
        let c2da_fresh36 : int16 = int16(uint(c2da_mem[ms_0 + 20]) | uint(c2da_mem[ms_0 + 21]) << 0x8)
        let c2da_fresh37 : uint = uint(c2da_fresh36)
        c2da_mem[ss_0 + 12] = uint8(c2da_fresh37)
        c2da_mem[ss_0 + 13] = uint8(c2da_fresh37 >> 0x8)
        let c2da_fresh38 : int16 = int16(uint(c2da_mem[ms_0 + 22]) | uint(c2da_mem[ms_0 + 23]) << 0x8)
        let c2da_fresh39 : uint = uint(c2da_fresh38)
        c2da_mem[ss_0 + 14] = uint8(c2da_fresh39)
        c2da_mem[ss_0 + 15] = uint8(c2da_fresh39 >> 0x8)
        let c2da_fresh40 : int16 = int16(uint(c2da_mem[ms_0 + 24]) | uint(c2da_mem[ms_0 + 25]) << 0x8)
        let c2da_fresh41 : uint = uint(c2da_fresh40)
        c2da_mem[ss_0 + 16] = uint8(c2da_fresh41)
        c2da_mem[ss_0 + 17] = uint8(c2da_fresh41 >> 0x8)
        let c2da_fresh42 : uint = 0u
        c2da_mem[ss_0 + 96] = uint8(c2da_fresh42)
        c2da_mem[ss_0 + 97] = uint8(c2da_fresh42 >> 0x8)
        c2da_mem[ss_0 + 98] = uint8(c2da_fresh42 >> 0x10)
        c2da_mem[ss_0 + 99] = uint8(c2da_fresh42 >> 0x18)
        c2da_mem[ss_0 + 100] = 0u8
        c2da_mem[ss_0 + 101] = 0u8
        c2da_mem[ss_0 + 102] = 0u8
        c2da_mem[ss_0 + 103] = 0u8
        i_2++
        ss_0 += 128
        ms_0 += 26
    }
    W_ReleaseLumpNum(lump_2)
    return
}
[export, sideeffects]
def P_LoadNodes(var lump_3 : int) {
    var data_3 : int
    var i_3 : int
    var mn : int
    var no : int
    numnodes = int(uint64(W_LumpLength(uint(lump_3))) / 28ul)
    nodes = Z_Malloc(int(uint64(numnodes) * 52ul), 5, 0)
    data_3 = W_CacheLumpNum(lump_3, 1)
    mn = data_3
    no = nodes
    i_3 = 0
    while (i_3 < numnodes) {
        let c2da_fresh43 : int = int(int16(uint(c2da_mem[mn]) | uint(c2da_mem[mn + 1]) << 0x8)) << 16
        let c2da_fresh44 : uint = uint(c2da_fresh43)
        c2da_mem[no] = uint8(c2da_fresh44)
        c2da_mem[no + 1] = uint8(c2da_fresh44 >> 0x8)
        c2da_mem[no + 2] = uint8(c2da_fresh44 >> 0x10)
        c2da_mem[no + 3] = uint8(c2da_fresh44 >> 0x18)
        let c2da_fresh45 : int = int(int16(uint(c2da_mem[mn + 2]) | uint(c2da_mem[mn + 3]) << 0x8)) << 16
        let c2da_fresh46 : uint = uint(c2da_fresh45)
        c2da_mem[no + 4] = uint8(c2da_fresh46)
        c2da_mem[no + 5] = uint8(c2da_fresh46 >> 0x8)
        c2da_mem[no + 6] = uint8(c2da_fresh46 >> 0x10)
        c2da_mem[no + 7] = uint8(c2da_fresh46 >> 0x18)
        let c2da_fresh47 : int = int(int16(uint(c2da_mem[mn + 4]) | uint(c2da_mem[mn + 5]) << 0x8)) << 16
        let c2da_fresh48 : uint = uint(c2da_fresh47)
        c2da_mem[no + 8] = uint8(c2da_fresh48)
        c2da_mem[no + 9] = uint8(c2da_fresh48 >> 0x8)
        c2da_mem[no + 10] = uint8(c2da_fresh48 >> 0x10)
        c2da_mem[no + 11] = uint8(c2da_fresh48 >> 0x18)
        let c2da_fresh49 : int = int(int16(uint(c2da_mem[mn + 6]) | uint(c2da_mem[mn + 7]) << 0x8)) << 16
        let c2da_fresh50 : uint = uint(c2da_fresh49)
        c2da_mem[no + 12] = uint8(c2da_fresh50)
        c2da_mem[no + 13] = uint8(c2da_fresh50 >> 0x8)
        c2da_mem[no + 14] = uint8(c2da_fresh50 >> 0x10)
        c2da_mem[no + 15] = uint8(c2da_fresh50 >> 0x18)
        for (j in range(0, 2)) {
            let c2da_fresh51 : uint16 = uint16(int16(uint16(uint(c2da_mem[mn + 24 + j * 2]) | uint(c2da_mem[mn + 24 + j * 2 + 1]) << 0x8)))
            let c2da_fresh52 : uint = uint(c2da_fresh51)
            c2da_mem[no + 48 + j * 2] = uint8(c2da_fresh52)
            c2da_mem[no + 48 + j * 2 + 1] = uint8(c2da_fresh52 >> 0x8)
            for (k in range(0, 4)) {
                let c2da_fresh53 : int = int(int16(uint(c2da_mem[mn + 8 + j * 8 + k * 2]) | uint(c2da_mem[mn + 8 + j * 8 + k * 2 + 1]) << 0x8)) << 16
                let c2da_fresh54 : uint = uint(c2da_fresh53)
                c2da_mem[no + 16 + j * 16 + k * 4] = uint8(c2da_fresh54)
                c2da_mem[no + 16 + j * 16 + k * 4 + 1] = uint8(c2da_fresh54 >> 0x8)
                c2da_mem[no + 16 + j * 16 + k * 4 + 2] = uint8(c2da_fresh54 >> 0x10)
                c2da_mem[no + 16 + j * 16 + k * 4 + 3] = uint8(c2da_fresh54 >> 0x18)
            }
        }
        i_3++
        no += 52
        mn += 28
    }
    W_ReleaseLumpNum(lump_3)
    return
}
[export, sideeffects]
def P_LoadThings(var lump_4 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    P_LoadThings_c2da_frame(lump_4, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def P_LoadLineDefs(var lump_5 : int) {
    var data_5 : int
    var i_5 : int
    var mld : int
    var ld : int
    var v1 : int
    var v2 : int
    numlines = int(uint64(W_LumpLength(uint(lump_5))) / 14ul)
    lines = Z_Malloc(int(uint64(numlines) * 88ul), 5, 0)
    c2da_lin_memset(lines, 0, uint64(numlines) * 88ul)
    data_5 = W_CacheLumpNum(lump_5, 1)
    mld = data_5
    ld = lines
    i_5 = 0
    while (i_5 < numlines) {
        let c2da_fresh66 : int16 = int16(uint(c2da_mem[mld + 4]) | uint(c2da_mem[mld + 5]) << 0x8)
        let c2da_fresh67 : uint = uint(c2da_fresh66)
        c2da_mem[ld + 24] = uint8(c2da_fresh67)
        c2da_mem[ld + 25] = uint8(c2da_fresh67 >> 0x8)
        let c2da_fresh68 : int16 = int16(uint(c2da_mem[mld + 6]) | uint(c2da_mem[mld + 7]) << 0x8)
        let c2da_fresh69 : uint = uint(c2da_fresh68)
        c2da_mem[ld + 26] = uint8(c2da_fresh69)
        c2da_mem[ld + 27] = uint8(c2da_fresh69 >> 0x8)
        let c2da_fresh70 : int16 = int16(uint(c2da_mem[mld + 8]) | uint(c2da_mem[mld + 9]) << 0x8)
        let c2da_fresh71 : uint = uint(c2da_fresh70)
        c2da_mem[ld + 28] = uint8(c2da_fresh71)
        c2da_mem[ld + 29] = uint8(c2da_fresh71 >> 0x8)
        let c2da_fresh72 : int = vertexes + int(int16(uint(c2da_mem[mld]) | uint(c2da_mem[mld + 1]) << 0x8)) * 8
        let c2da_fresh73 : uint = uint(c2da_fresh72)
        c2da_mem[ld] = uint8(c2da_fresh73)
        c2da_mem[ld + 1] = uint8(c2da_fresh73 >> 0x8)
        c2da_mem[ld + 2] = uint8(c2da_fresh73 >> 0x10)
        c2da_mem[ld + 3] = uint8(c2da_fresh73 >> 0x18)
        c2da_mem[ld + 4] = 0u8
        c2da_mem[ld + 5] = 0u8
        c2da_mem[ld + 6] = 0u8
        c2da_mem[ld + 7] = 0u8
        v1 = c2da_fresh72
        let c2da_fresh74 : int = vertexes + int(int16(uint(c2da_mem[mld + 2]) | uint(c2da_mem[mld + 3]) << 0x8)) * 8
        let c2da_fresh75 : uint = uint(c2da_fresh74)
        c2da_mem[ld + 8] = uint8(c2da_fresh75)
        c2da_mem[ld + 9] = uint8(c2da_fresh75 >> 0x8)
        c2da_mem[ld + 10] = uint8(c2da_fresh75 >> 0x10)
        c2da_mem[ld + 11] = uint8(c2da_fresh75 >> 0x18)
        c2da_mem[ld + 12] = 0u8
        c2da_mem[ld + 13] = 0u8
        c2da_mem[ld + 14] = 0u8
        c2da_mem[ld + 15] = 0u8
        v2 = c2da_fresh74
        let c2da_fresh76 : int = int(uint(c2da_mem[v2]) | uint(c2da_mem[v2 + 1]) << 0x8 | uint(c2da_mem[v2 + 2]) << 0x10 | uint(c2da_mem[v2 + 3]) << 0x18) - int(uint(c2da_mem[v1]) | uint(c2da_mem[v1 + 1]) << 0x8 | uint(c2da_mem[v1 + 2]) << 0x10 | uint(c2da_mem[v1 + 3]) << 0x18)
        let c2da_fresh77 : uint = uint(c2da_fresh76)
        c2da_mem[ld + 16] = uint8(c2da_fresh77)
        c2da_mem[ld + 17] = uint8(c2da_fresh77 >> 0x8)
        c2da_mem[ld + 18] = uint8(c2da_fresh77 >> 0x10)
        c2da_mem[ld + 19] = uint8(c2da_fresh77 >> 0x18)
        let c2da_fresh78 : int = int(uint(c2da_mem[v2 + 4]) | uint(c2da_mem[v2 + 5]) << 0x8 | uint(c2da_mem[v2 + 6]) << 0x10 | uint(c2da_mem[v2 + 7]) << 0x18) - int(uint(c2da_mem[v1 + 4]) | uint(c2da_mem[v1 + 5]) << 0x8 | uint(c2da_mem[v1 + 6]) << 0x10 | uint(c2da_mem[v1 + 7]) << 0x18)
        let c2da_fresh79 : uint = uint(c2da_fresh78)
        c2da_mem[ld + 20] = uint8(c2da_fresh79)
        c2da_mem[ld + 21] = uint8(c2da_fresh79 >> 0x8)
        c2da_mem[ld + 22] = uint8(c2da_fresh79 >> 0x10)
        c2da_mem[ld + 23] = uint8(c2da_fresh79 >> 0x18)
        if (int(uint(c2da_mem[ld + 16]) | uint(c2da_mem[ld + 17]) << 0x8 | uint(c2da_mem[ld + 18]) << 0x10 | uint(c2da_mem[ld + 19]) << 0x18) == 0) {
            let c2da_fresh80 : uint = 1u
            let c2da_fresh81 : uint = c2da_fresh80
            c2da_mem[ld + 52] = uint8(c2da_fresh81)
            c2da_mem[ld + 53] = uint8(c2da_fresh81 >> 0x8)
            c2da_mem[ld + 54] = uint8(c2da_fresh81 >> 0x10)
            c2da_mem[ld + 55] = uint8(c2da_fresh81 >> 0x18)
        } elif (int(uint(c2da_mem[ld + 20]) | uint(c2da_mem[ld + 21]) << 0x8 | uint(c2da_mem[ld + 22]) << 0x10 | uint(c2da_mem[ld + 23]) << 0x18) == 0) {
            let c2da_fresh82 : uint = 0u
            let c2da_fresh83 : uint = c2da_fresh82
            c2da_mem[ld + 52] = uint8(c2da_fresh83)
            c2da_mem[ld + 53] = uint8(c2da_fresh83 >> 0x8)
            c2da_mem[ld + 54] = uint8(c2da_fresh83 >> 0x10)
            c2da_mem[ld + 55] = uint8(c2da_fresh83 >> 0x18)
        } elif (FixedDiv(int(uint(c2da_mem[ld + 20]) | uint(c2da_mem[ld + 21]) << 0x8 | uint(c2da_mem[ld + 22]) << 0x10 | uint(c2da_mem[ld + 23]) << 0x18), int(uint(c2da_mem[ld + 16]) | uint(c2da_mem[ld + 17]) << 0x8 | uint(c2da_mem[ld + 18]) << 0x10 | uint(c2da_mem[ld + 19]) << 0x18)) > 0) {
            let c2da_fresh84 : uint = 2u
            let c2da_fresh85 : uint = c2da_fresh84
            c2da_mem[ld + 52] = uint8(c2da_fresh85)
            c2da_mem[ld + 53] = uint8(c2da_fresh85 >> 0x8)
            c2da_mem[ld + 54] = uint8(c2da_fresh85 >> 0x10)
            c2da_mem[ld + 55] = uint8(c2da_fresh85 >> 0x18)
        } else {
            let c2da_fresh86 : uint = 3u
            let c2da_fresh87 : uint = c2da_fresh86
            c2da_mem[ld + 52] = uint8(c2da_fresh87)
            c2da_mem[ld + 53] = uint8(c2da_fresh87 >> 0x8)
            c2da_mem[ld + 54] = uint8(c2da_fresh87 >> 0x10)
            c2da_mem[ld + 55] = uint8(c2da_fresh87 >> 0x18)
        }
        if (int(uint(c2da_mem[v1]) | uint(c2da_mem[v1 + 1]) << 0x8 | uint(c2da_mem[v1 + 2]) << 0x10 | uint(c2da_mem[v1 + 3]) << 0x18) < int(uint(c2da_mem[v2]) | uint(c2da_mem[v2 + 1]) << 0x8 | uint(c2da_mem[v2 + 2]) << 0x10 | uint(c2da_mem[v2 + 3]) << 0x18)) {
            let c2da_fresh88 : int = int(uint(c2da_mem[v1]) | uint(c2da_mem[v1 + 1]) << 0x8 | uint(c2da_mem[v1 + 2]) << 0x10 | uint(c2da_mem[v1 + 3]) << 0x18)
            let c2da_fresh89 : uint = uint(c2da_fresh88)
            c2da_mem[ld + 36 + 2 * 4] = uint8(c2da_fresh89)
            c2da_mem[ld + 36 + 2 * 4 + 1] = uint8(c2da_fresh89 >> 0x8)
            c2da_mem[ld + 36 + 2 * 4 + 2] = uint8(c2da_fresh89 >> 0x10)
            c2da_mem[ld + 36 + 2 * 4 + 3] = uint8(c2da_fresh89 >> 0x18)
            let c2da_fresh90 : int = int(uint(c2da_mem[v2]) | uint(c2da_mem[v2 + 1]) << 0x8 | uint(c2da_mem[v2 + 2]) << 0x10 | uint(c2da_mem[v2 + 3]) << 0x18)
            let c2da_fresh91 : uint = uint(c2da_fresh90)
            c2da_mem[ld + 36 + 3 * 4] = uint8(c2da_fresh91)
            c2da_mem[ld + 36 + 3 * 4 + 1] = uint8(c2da_fresh91 >> 0x8)
            c2da_mem[ld + 36 + 3 * 4 + 2] = uint8(c2da_fresh91 >> 0x10)
            c2da_mem[ld + 36 + 3 * 4 + 3] = uint8(c2da_fresh91 >> 0x18)
        } else {
            let c2da_fresh92 : int = int(uint(c2da_mem[v2]) | uint(c2da_mem[v2 + 1]) << 0x8 | uint(c2da_mem[v2 + 2]) << 0x10 | uint(c2da_mem[v2 + 3]) << 0x18)
            let c2da_fresh93 : uint = uint(c2da_fresh92)
            c2da_mem[ld + 36 + 2 * 4] = uint8(c2da_fresh93)
            c2da_mem[ld + 36 + 2 * 4 + 1] = uint8(c2da_fresh93 >> 0x8)
            c2da_mem[ld + 36 + 2 * 4 + 2] = uint8(c2da_fresh93 >> 0x10)
            c2da_mem[ld + 36 + 2 * 4 + 3] = uint8(c2da_fresh93 >> 0x18)
            let c2da_fresh94 : int = int(uint(c2da_mem[v1]) | uint(c2da_mem[v1 + 1]) << 0x8 | uint(c2da_mem[v1 + 2]) << 0x10 | uint(c2da_mem[v1 + 3]) << 0x18)
            let c2da_fresh95 : uint = uint(c2da_fresh94)
            c2da_mem[ld + 36 + 3 * 4] = uint8(c2da_fresh95)
            c2da_mem[ld + 36 + 3 * 4 + 1] = uint8(c2da_fresh95 >> 0x8)
            c2da_mem[ld + 36 + 3 * 4 + 2] = uint8(c2da_fresh95 >> 0x10)
            c2da_mem[ld + 36 + 3 * 4 + 3] = uint8(c2da_fresh95 >> 0x18)
        }
        if (int(uint(c2da_mem[v1 + 4]) | uint(c2da_mem[v1 + 5]) << 0x8 | uint(c2da_mem[v1 + 6]) << 0x10 | uint(c2da_mem[v1 + 7]) << 0x18) < int(uint(c2da_mem[v2 + 4]) | uint(c2da_mem[v2 + 5]) << 0x8 | uint(c2da_mem[v2 + 6]) << 0x10 | uint(c2da_mem[v2 + 7]) << 0x18)) {
            let c2da_fresh96 : int = int(uint(c2da_mem[v1 + 4]) | uint(c2da_mem[v1 + 5]) << 0x8 | uint(c2da_mem[v1 + 6]) << 0x10 | uint(c2da_mem[v1 + 7]) << 0x18)
            let c2da_fresh97 : uint = uint(c2da_fresh96)
            c2da_mem[ld + 36 + 1 * 4] = uint8(c2da_fresh97)
            c2da_mem[ld + 36 + 1 * 4 + 1] = uint8(c2da_fresh97 >> 0x8)
            c2da_mem[ld + 36 + 1 * 4 + 2] = uint8(c2da_fresh97 >> 0x10)
            c2da_mem[ld + 36 + 1 * 4 + 3] = uint8(c2da_fresh97 >> 0x18)
            let c2da_fresh98 : int = int(uint(c2da_mem[v2 + 4]) | uint(c2da_mem[v2 + 5]) << 0x8 | uint(c2da_mem[v2 + 6]) << 0x10 | uint(c2da_mem[v2 + 7]) << 0x18)
            let c2da_fresh99 : uint = uint(c2da_fresh98)
            c2da_mem[ld + 36 + 0 * 4] = uint8(c2da_fresh99)
            c2da_mem[ld + 36 + 0 * 4 + 1] = uint8(c2da_fresh99 >> 0x8)
            c2da_mem[ld + 36 + 0 * 4 + 2] = uint8(c2da_fresh99 >> 0x10)
            c2da_mem[ld + 36 + 0 * 4 + 3] = uint8(c2da_fresh99 >> 0x18)
        } else {
            let c2da_fresh100 : int = int(uint(c2da_mem[v2 + 4]) | uint(c2da_mem[v2 + 5]) << 0x8 | uint(c2da_mem[v2 + 6]) << 0x10 | uint(c2da_mem[v2 + 7]) << 0x18)
            let c2da_fresh101 : uint = uint(c2da_fresh100)
            c2da_mem[ld + 36 + 1 * 4] = uint8(c2da_fresh101)
            c2da_mem[ld + 36 + 1 * 4 + 1] = uint8(c2da_fresh101 >> 0x8)
            c2da_mem[ld + 36 + 1 * 4 + 2] = uint8(c2da_fresh101 >> 0x10)
            c2da_mem[ld + 36 + 1 * 4 + 3] = uint8(c2da_fresh101 >> 0x18)
            let c2da_fresh102 : int = int(uint(c2da_mem[v1 + 4]) | uint(c2da_mem[v1 + 5]) << 0x8 | uint(c2da_mem[v1 + 6]) << 0x10 | uint(c2da_mem[v1 + 7]) << 0x18)
            let c2da_fresh103 : uint = uint(c2da_fresh102)
            c2da_mem[ld + 36 + 0 * 4] = uint8(c2da_fresh103)
            c2da_mem[ld + 36 + 0 * 4 + 1] = uint8(c2da_fresh103 >> 0x8)
            c2da_mem[ld + 36 + 0 * 4 + 2] = uint8(c2da_fresh103 >> 0x10)
            c2da_mem[ld + 36 + 0 * 4 + 3] = uint8(c2da_fresh103 >> 0x18)
        }
        let c2da_fresh104 : int16 = int16(uint(c2da_mem[mld + 10 + 0 * 2]) | uint(c2da_mem[mld + 10 + 0 * 2 + 1]) << 0x8)
        let c2da_fresh105 : uint = uint(c2da_fresh104)
        c2da_mem[ld + 30 + 0 * 2] = uint8(c2da_fresh105)
        c2da_mem[ld + 30 + 0 * 2 + 1] = uint8(c2da_fresh105 >> 0x8)
        let c2da_fresh106 : int16 = int16(uint(c2da_mem[mld + 10 + 1 * 2]) | uint(c2da_mem[mld + 10 + 1 * 2 + 1]) << 0x8)
        let c2da_fresh107 : uint = uint(c2da_fresh106)
        c2da_mem[ld + 30 + 1 * 2] = uint8(c2da_fresh107)
        c2da_mem[ld + 30 + 1 * 2 + 1] = uint8(c2da_fresh107 >> 0x8)
        if (int(int16(uint(c2da_mem[ld + 30 + 0 * 2]) | uint(c2da_mem[ld + 30 + 0 * 2 + 1]) << 0x8)) != -1) {
            let c2da_fresh108 : int = sides + int(int16(uint(c2da_mem[ld + 30 + 0 * 2]) | uint(c2da_mem[ld + 30 + 0 * 2 + 1]) << 0x8)) * 24 + 16
            let c2da_fresh109 : int = int(uint(c2da_mem[c2da_fresh108]) | uint(c2da_mem[c2da_fresh108 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh108 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh108 + 3]) << 0x18)
            let c2da_fresh110 : uint = uint(c2da_fresh109)
            c2da_mem[ld + 56] = uint8(c2da_fresh110)
            c2da_mem[ld + 57] = uint8(c2da_fresh110 >> 0x8)
            c2da_mem[ld + 58] = uint8(c2da_fresh110 >> 0x10)
            c2da_mem[ld + 59] = uint8(c2da_fresh110 >> 0x18)
            c2da_mem[ld + 60] = 0u8
            c2da_mem[ld + 61] = 0u8
            c2da_mem[ld + 62] = 0u8
            c2da_mem[ld + 63] = 0u8
        } else {
            let c2da_fresh111 : uint = 0u
            c2da_mem[ld + 56] = uint8(c2da_fresh111)
            c2da_mem[ld + 57] = uint8(c2da_fresh111 >> 0x8)
            c2da_mem[ld + 58] = uint8(c2da_fresh111 >> 0x10)
            c2da_mem[ld + 59] = uint8(c2da_fresh111 >> 0x18)
            c2da_mem[ld + 60] = 0u8
            c2da_mem[ld + 61] = 0u8
            c2da_mem[ld + 62] = 0u8
            c2da_mem[ld + 63] = 0u8
        }
        if (int(int16(uint(c2da_mem[ld + 30 + 1 * 2]) | uint(c2da_mem[ld + 30 + 1 * 2 + 1]) << 0x8)) != -1) {
            let c2da_fresh112 : int = sides + int(int16(uint(c2da_mem[ld + 30 + 1 * 2]) | uint(c2da_mem[ld + 30 + 1 * 2 + 1]) << 0x8)) * 24 + 16
            let c2da_fresh113 : int = int(uint(c2da_mem[c2da_fresh112]) | uint(c2da_mem[c2da_fresh112 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh112 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh112 + 3]) << 0x18)
            let c2da_fresh114 : uint = uint(c2da_fresh113)
            c2da_mem[ld + 64] = uint8(c2da_fresh114)
            c2da_mem[ld + 65] = uint8(c2da_fresh114 >> 0x8)
            c2da_mem[ld + 66] = uint8(c2da_fresh114 >> 0x10)
            c2da_mem[ld + 67] = uint8(c2da_fresh114 >> 0x18)
            c2da_mem[ld + 68] = 0u8
            c2da_mem[ld + 69] = 0u8
            c2da_mem[ld + 70] = 0u8
            c2da_mem[ld + 71] = 0u8
        } else {
            let c2da_fresh115 : uint = 0u
            c2da_mem[ld + 64] = uint8(c2da_fresh115)
            c2da_mem[ld + 65] = uint8(c2da_fresh115 >> 0x8)
            c2da_mem[ld + 66] = uint8(c2da_fresh115 >> 0x10)
            c2da_mem[ld + 67] = uint8(c2da_fresh115 >> 0x18)
            c2da_mem[ld + 68] = 0u8
            c2da_mem[ld + 69] = 0u8
            c2da_mem[ld + 70] = 0u8
            c2da_mem[ld + 71] = 0u8
        }
        i_5++
        mld += 14
        ld += 88
    }
    W_ReleaseLumpNum(lump_5)
    return
}
[export, sideeffects]
def P_LoadSideDefs(var lump_6 : int) {
    var data_6 : int
    var i_6 : int
    var msd : int
    var sd : int
    numsides = int(uint64(W_LumpLength(uint(lump_6))) / 30ul)
    sides = Z_Malloc(int(uint64(numsides) * 24ul), 5, 0)
    c2da_lin_memset(sides, 0, uint64(numsides) * 24ul)
    data_6 = W_CacheLumpNum(lump_6, 1)
    msd = data_6
    sd = sides
    i_6 = 0
    while (i_6 < numsides) {
        let c2da_fresh116 : int = int(int16(uint(c2da_mem[msd]) | uint(c2da_mem[msd + 1]) << 0x8)) << 16
        let c2da_fresh117 : uint = uint(c2da_fresh116)
        c2da_mem[sd] = uint8(c2da_fresh117)
        c2da_mem[sd + 1] = uint8(c2da_fresh117 >> 0x8)
        c2da_mem[sd + 2] = uint8(c2da_fresh117 >> 0x10)
        c2da_mem[sd + 3] = uint8(c2da_fresh117 >> 0x18)
        let c2da_fresh118 : int = int(int16(uint(c2da_mem[msd + 2]) | uint(c2da_mem[msd + 3]) << 0x8)) << 16
        let c2da_fresh119 : uint = uint(c2da_fresh118)
        c2da_mem[sd + 4] = uint8(c2da_fresh119)
        c2da_mem[sd + 5] = uint8(c2da_fresh119 >> 0x8)
        c2da_mem[sd + 6] = uint8(c2da_fresh119 >> 0x10)
        c2da_mem[sd + 7] = uint8(c2da_fresh119 >> 0x18)
        let c2da_fresh120 : int16 = int16(R_TextureNumForName(msd + 4))
        let c2da_fresh121 : uint = uint(c2da_fresh120)
        c2da_mem[sd + 8] = uint8(c2da_fresh121)
        c2da_mem[sd + 9] = uint8(c2da_fresh121 >> 0x8)
        let c2da_fresh122 : int16 = int16(R_TextureNumForName(msd + 12))
        let c2da_fresh123 : uint = uint(c2da_fresh122)
        c2da_mem[sd + 10] = uint8(c2da_fresh123)
        c2da_mem[sd + 11] = uint8(c2da_fresh123 >> 0x8)
        let c2da_fresh124 : int16 = int16(R_TextureNumForName(msd + 20))
        let c2da_fresh125 : uint = uint(c2da_fresh124)
        c2da_mem[sd + 12] = uint8(c2da_fresh125)
        c2da_mem[sd + 13] = uint8(c2da_fresh125 >> 0x8)
        let c2da_fresh126 : int = sectors + int(int16(uint(c2da_mem[msd + 28]) | uint(c2da_mem[msd + 29]) << 0x8)) * 128
        let c2da_fresh127 : uint = uint(c2da_fresh126)
        c2da_mem[sd + 16] = uint8(c2da_fresh127)
        c2da_mem[sd + 17] = uint8(c2da_fresh127 >> 0x8)
        c2da_mem[sd + 18] = uint8(c2da_fresh127 >> 0x10)
        c2da_mem[sd + 19] = uint8(c2da_fresh127 >> 0x18)
        c2da_mem[sd + 20] = 0u8
        c2da_mem[sd + 21] = 0u8
        c2da_mem[sd + 22] = 0u8
        c2da_mem[sd + 23] = 0u8
        i_6++
        msd += 30
        sd += 24
    }
    W_ReleaseLumpNum(lump_6)
    return
}
[export, sideeffects]
def P_LoadBlockMap(var lump_7 : int) {
    var count : int
    var lumplen : int = W_LumpLength(uint(lump_7))
    count = lumplen / 2
    blockmaplump = Z_Malloc(lumplen, 5, 0)
    W_ReadLump(uint(lump_7), blockmaplump)
    blockmap = blockmaplump + 4 * 2
    for (i_7 in range(0, count)) {
        let c2da_fresh128 : int16 = int16(uint(c2da_mem[blockmaplump + i_7 * 2]) | uint(c2da_mem[blockmaplump + i_7 * 2 + 1]) << 0x8)
        let c2da_fresh129 : uint = uint(c2da_fresh128)
        c2da_mem[blockmaplump + i_7 * 2] = uint8(c2da_fresh129)
        c2da_mem[blockmaplump + i_7 * 2 + 1] = uint8(c2da_fresh129 >> 0x8)
    }
    let c2da_fresh130 : int = int(int16(uint(c2da_mem[blockmaplump + 0 * 2]) | uint(c2da_mem[blockmaplump + 0 * 2 + 1]) << 0x8)) << 16
    let c2da_fresh131 : uint = uint(c2da_fresh130)
    c2da_mem[49728] = uint8(c2da_fresh131)
    c2da_mem[49729] = uint8(c2da_fresh131 >> 0x8)
    c2da_mem[49730] = uint8(c2da_fresh131 >> 0x10)
    c2da_mem[49731] = uint8(c2da_fresh131 >> 0x18)
    let c2da_fresh132 : int = int(int16(uint(c2da_mem[blockmaplump + 1 * 2]) | uint(c2da_mem[blockmaplump + 1 * 2 + 1]) << 0x8)) << 16
    let c2da_fresh133 : uint = uint(c2da_fresh132)
    c2da_mem[49744] = uint8(c2da_fresh133)
    c2da_mem[49745] = uint8(c2da_fresh133 >> 0x8)
    c2da_mem[49746] = uint8(c2da_fresh133 >> 0x10)
    c2da_mem[49747] = uint8(c2da_fresh133 >> 0x18)
    let c2da_fresh134 : int = int(int16(uint(c2da_mem[blockmaplump + 2 * 2]) | uint(c2da_mem[blockmaplump + 2 * 2 + 1]) << 0x8))
    let c2da_fresh135 : uint = uint(c2da_fresh134)
    c2da_mem[49712] = uint8(c2da_fresh135)
    c2da_mem[49713] = uint8(c2da_fresh135 >> 0x8)
    c2da_mem[49714] = uint8(c2da_fresh135 >> 0x10)
    c2da_mem[49715] = uint8(c2da_fresh135 >> 0x18)
    let c2da_fresh136 : int = int(int16(uint(c2da_mem[blockmaplump + 3 * 2]) | uint(c2da_mem[blockmaplump + 3 * 2 + 1]) << 0x8))
    let c2da_fresh137 : uint = uint(c2da_fresh136)
    c2da_mem[49760] = uint8(c2da_fresh137)
    c2da_mem[49761] = uint8(c2da_fresh137 >> 0x8)
    c2da_mem[49762] = uint8(c2da_fresh137 >> 0x10)
    c2da_mem[49763] = uint8(c2da_fresh137 >> 0x18)
    count = int(8ul * uint64(int(uint(c2da_mem[49712]) | uint(c2da_mem[49713]) << 0x8 | uint(c2da_mem[49714]) << 0x10 | uint(c2da_mem[49715]) << 0x18)) * uint64(int(uint(c2da_mem[49760]) | uint(c2da_mem[49761]) << 0x8 | uint(c2da_mem[49762]) << 0x10 | uint(c2da_mem[49763]) << 0x18)))
    blocklinks = Z_Malloc(count, 5, 0)
    c2da_lin_memset(blocklinks, 0, uint64(count))
    return
}
[export, sideeffects]
def P_GroupLines() {
    let c2da_saved_sp : int = c2da_lin_sp
    P_GroupLines_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private PadRejectArray(var array_0 : int; var len : uint) {
    var i_9 : uint
    var dest : int
    var padvalue : uint
    var rejectpad : uint[4] = fixed_array<uint>(uint((totallines * 4 + 3 & ~3) + 24), 0u, 50u, 0x1d4a11u)
    dest = array_0
    i_9 = 0u
    while (i_9 < len && uint64(i_9) < 16ul) {
        let c2da_fresh179 : uint8 = uint8(rejectpad[int(i_9 / 4u)] >> i_9 % 4u * 8u & 0xffu)
        c2da_mem[dest] = c2da_fresh179
        dest++
        i_9++
    }
    if (uint64(len) > 16ul) {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 361040, [C2daVaArg(tag = 1, i64 = int64(len), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = 16l, f64 = 0.0lf, raw = 0x0)])
        if (M_CheckParm(361097) != 0) {
            padvalue = 0xffu
        } else {
            padvalue = 0xf00u
        }
        c2da_lin_memset(array_0 + 16, int(padvalue), uint64(len) - 16ul)
    }
    return
}
[sideeffects]
def private P_LoadReject(var lumpnum : int) {
    var minlength : int
    var lumplen_0 : int
    minlength = (numsectors * numsectors + 7) / 8
    lumplen_0 = W_LumpLength(uint(lumpnum))
    if (lumplen_0 >= minlength) {
        let c2da_fresh180 : int = W_CacheLumpNum(lumpnum, 5)
        let c2da_fresh181 : uint = uint(c2da_fresh180)
        c2da_mem[63664] = uint8(c2da_fresh181)
        c2da_mem[63665] = uint8(c2da_fresh181 >> 0x8)
        c2da_mem[63666] = uint8(c2da_fresh181 >> 0x10)
        c2da_mem[63667] = uint8(c2da_fresh181 >> 0x18)
        c2da_mem[63668] = 0u8
        c2da_mem[63669] = 0u8
        c2da_mem[63670] = 0u8
        c2da_mem[63671] = 0u8
    } else {
        let c2da_fresh182 : int = Z_Malloc(minlength, 5, 63664)
        let c2da_fresh183 : uint = uint(c2da_fresh182)
        c2da_mem[63664] = uint8(c2da_fresh183)
        c2da_mem[63665] = uint8(c2da_fresh183 >> 0x8)
        c2da_mem[63666] = uint8(c2da_fresh183 >> 0x10)
        c2da_mem[63667] = uint8(c2da_fresh183 >> 0x18)
        c2da_mem[63668] = 0u8
        c2da_mem[63669] = 0u8
        c2da_mem[63670] = 0u8
        c2da_mem[63671] = 0u8
        W_ReadLump(uint(lumpnum), int(uint(c2da_mem[63664]) | uint(c2da_mem[63665]) << 0x8 | uint(c2da_mem[63666]) << 0x10 | uint(c2da_mem[63667]) << 0x18))
        PadRejectArray(int(uint(c2da_mem[63664]) | uint(c2da_mem[63665]) << 0x8 | uint(c2da_mem[63666]) << 0x10 | uint(c2da_mem[63667]) << 0x18) + lumplen_0, uint(minlength - lumplen_0))
    }
    return
}
[export, sideeffects]
def P_SetupLevel(var episode : int; var map : int; var playermask : int; var skill : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    P_SetupLevel_c2da_frame(episode, map, playermask, skill, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def P_Init() {
    P_InitSwitchList()
    P_InitPicAnims()
    R_InitSprites(63680)
    return
}
[sideeffects]
def private P_LoadThings_c2da_frame(var lump_4 : int; c2da_fp : int) {
    var c2da_fresh55 : int
    var data_4 : int
    var i_4 : int
    var mt : int
    var numthings : int
    var spawn : uint
    data_4 = W_CacheLumpNum(lump_4, 1)
    numthings = int(uint64(W_LumpLength(uint(lump_4))) / 10ul)
    mt = data_4
    i_4 = 0
    while (i_4 < numthings) {
        spawn = 1u
        if (uint(gamemode) == 2u) {
            goto label 2
        }
        c2da_fresh55 = int(int16(uint(c2da_mem[mt + 6]) | uint(c2da_mem[mt + 7]) << 0x8))
        if (c2da_fresh55 < 69) {
            if (c2da_fresh55 >= 64 && c2da_fresh55 <= 68) {
                goto c2da_fresh55 - 61
            }
        } else {
            if (c2da_fresh55 < 84) {
                if (c2da_fresh55 == 69) {
                    goto label 0
                } elif (c2da_fresh55 == 71) {
                    goto label 0
                }
            } else {
                if (c2da_fresh55 == 84) {
                    goto label 0
                } elif (c2da_fresh55 == 88) {
                    goto label 0
                } elif (c2da_fresh55 == 89) {
                    goto label 0
                }
            }
        }
        goto label 1
        label 0:
        label 3:
        label 4:
        label 5:
        label 6:
        label 7:
        spawn = 0u
        label 1:
        label 2:
        if (spawn == 0u) {
            break
        }
        let c2da_fresh56 : int16 = int16(uint(c2da_mem[mt]) | uint(c2da_mem[mt + 1]) << 0x8)
        let c2da_fresh57 : uint = uint(c2da_fresh56)
        c2da_mem[c2da_fp] = uint8(c2da_fresh57)
        c2da_mem[c2da_fp + 1] = uint8(c2da_fresh57 >> 0x8)
        let c2da_fresh58 : int16 = int16(uint(c2da_mem[mt + 2]) | uint(c2da_mem[mt + 3]) << 0x8)
        let c2da_fresh59 : uint = uint(c2da_fresh58)
        c2da_mem[c2da_fp + 2] = uint8(c2da_fresh59)
        c2da_mem[c2da_fp + 3] = uint8(c2da_fresh59 >> 0x8)
        let c2da_fresh60 : int16 = int16(uint(c2da_mem[mt + 4]) | uint(c2da_mem[mt + 5]) << 0x8)
        let c2da_fresh61 : uint = uint(c2da_fresh60)
        c2da_mem[c2da_fp + 4] = uint8(c2da_fresh61)
        c2da_mem[c2da_fp + 5] = uint8(c2da_fresh61 >> 0x8)
        let c2da_fresh62 : int16 = int16(uint(c2da_mem[mt + 6]) | uint(c2da_mem[mt + 7]) << 0x8)
        let c2da_fresh63 : uint = uint(c2da_fresh62)
        c2da_mem[c2da_fp + 6] = uint8(c2da_fresh63)
        c2da_mem[c2da_fp + 7] = uint8(c2da_fresh63 >> 0x8)
        let c2da_fresh64 : int16 = int16(uint(c2da_mem[mt + 8]) | uint(c2da_mem[mt + 9]) << 0x8)
        let c2da_fresh65 : uint = uint(c2da_fresh64)
        c2da_mem[c2da_fp + 8] = uint8(c2da_fresh65)
        c2da_mem[c2da_fp + 9] = uint8(c2da_fresh65 >> 0x8)
        P_SpawnMapThing(c2da_fp)
        i_4++
        mt += 10
    }
    W_ReleaseLumpNum(lump_4)
    return
}
[sideeffects]
def private P_GroupLines_c2da_frame(c2da_fp : int) {
    var linebuffer : int
    var i_8 : int
    var j_0 : int
    var li_1 : int
    var sector : int
    var ss_1 : int
    var seg : int
    var block_0 : int
    ss_1 = subsectors
    i_8 = 0
    while (i_8 < numsubsectors) {
        seg = segs + int(int16(uint(c2da_mem[ss_1 + 10]) | uint(c2da_mem[ss_1 + 11]) << 0x8)) * 56
        let c2da_fresh138 : int = int(uint(c2da_mem[seg + 24]) | uint(c2da_mem[seg + 25]) << 0x8 | uint(c2da_mem[seg + 26]) << 0x10 | uint(c2da_mem[seg + 27]) << 0x18) + 16
        let c2da_fresh139 : int = int(uint(c2da_mem[c2da_fresh138]) | uint(c2da_mem[c2da_fresh138 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh138 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh138 + 3]) << 0x18)
        let c2da_fresh140 : uint = uint(c2da_fresh139)
        c2da_mem[ss_1] = uint8(c2da_fresh140)
        c2da_mem[ss_1 + 1] = uint8(c2da_fresh140 >> 0x8)
        c2da_mem[ss_1 + 2] = uint8(c2da_fresh140 >> 0x10)
        c2da_mem[ss_1 + 3] = uint8(c2da_fresh140 >> 0x18)
        c2da_mem[ss_1 + 4] = 0u8
        c2da_mem[ss_1 + 5] = 0u8
        c2da_mem[ss_1 + 6] = 0u8
        c2da_mem[ss_1 + 7] = 0u8
        i_8++
        ss_1 += 16
    }
    li_1 = lines
    totallines = 0
    i_8 = 0
    while (i_8 < numlines) {
        totallines++
        let c2da_fresh141 : int = int(uint(c2da_mem[li_1 + 56]) | uint(c2da_mem[li_1 + 57]) << 0x8 | uint(c2da_mem[li_1 + 58]) << 0x10 | uint(c2da_mem[li_1 + 59]) << 0x18) + 112
        let c2da_fresh142 : int = int(uint(c2da_mem[c2da_fresh141]) | uint(c2da_mem[c2da_fresh141 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh141 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh141 + 3]) << 0x18)
        let c2da_fresh143 : int = c2da_fresh142 + 1
        let c2da_fresh144 : uint = uint(c2da_fresh143)
        c2da_mem[c2da_fresh141] = uint8(c2da_fresh144)
        c2da_mem[c2da_fresh141 + 1] = uint8(c2da_fresh144 >> 0x8)
        c2da_mem[c2da_fresh141 + 2] = uint8(c2da_fresh144 >> 0x10)
        c2da_mem[c2da_fresh141 + 3] = uint8(c2da_fresh144 >> 0x18)
        if (int(uint(c2da_mem[li_1 + 64]) | uint(c2da_mem[li_1 + 65]) << 0x8 | uint(c2da_mem[li_1 + 66]) << 0x10 | uint(c2da_mem[li_1 + 67]) << 0x18) != 0 && int(uint(c2da_mem[li_1 + 64]) | uint(c2da_mem[li_1 + 65]) << 0x8 | uint(c2da_mem[li_1 + 66]) << 0x10 | uint(c2da_mem[li_1 + 67]) << 0x18) != int(uint(c2da_mem[li_1 + 56]) | uint(c2da_mem[li_1 + 57]) << 0x8 | uint(c2da_mem[li_1 + 58]) << 0x10 | uint(c2da_mem[li_1 + 59]) << 0x18)) {
            let c2da_fresh145 : int = int(uint(c2da_mem[li_1 + 64]) | uint(c2da_mem[li_1 + 65]) << 0x8 | uint(c2da_mem[li_1 + 66]) << 0x10 | uint(c2da_mem[li_1 + 67]) << 0x18) + 112
            let c2da_fresh146 : int = int(uint(c2da_mem[c2da_fresh145]) | uint(c2da_mem[c2da_fresh145 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh145 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh145 + 3]) << 0x18)
            let c2da_fresh147 : int = c2da_fresh146 + 1
            let c2da_fresh148 : uint = uint(c2da_fresh147)
            c2da_mem[c2da_fresh145] = uint8(c2da_fresh148)
            c2da_mem[c2da_fresh145 + 1] = uint8(c2da_fresh148 >> 0x8)
            c2da_mem[c2da_fresh145 + 2] = uint8(c2da_fresh148 >> 0x10)
            c2da_mem[c2da_fresh145 + 3] = uint8(c2da_fresh148 >> 0x18)
            totallines++
        }
        i_8++
        li_1 += 88
    }
    linebuffer = Z_Malloc(int(uint64(totallines) * 8ul), 5, 0)
    i_8 = 0
    while (i_8 < numsectors) {
        let c2da_fresh149 : uint = uint(linebuffer)
        c2da_mem[sectors + i_8 * 128 + 120] = uint8(c2da_fresh149)
        c2da_mem[sectors + i_8 * 128 + 121] = uint8(c2da_fresh149 >> 0x8)
        c2da_mem[sectors + i_8 * 128 + 122] = uint8(c2da_fresh149 >> 0x10)
        c2da_mem[sectors + i_8 * 128 + 123] = uint8(c2da_fresh149 >> 0x18)
        c2da_mem[sectors + i_8 * 128 + 124] = 0u8
        c2da_mem[sectors + i_8 * 128 + 125] = 0u8
        c2da_mem[sectors + i_8 * 128 + 126] = 0u8
        c2da_mem[sectors + i_8 * 128 + 127] = 0u8
        linebuffer += int(uint(c2da_mem[sectors + i_8 * 128 + 112]) | uint(c2da_mem[sectors + i_8 * 128 + 113]) << 0x8 | uint(c2da_mem[sectors + i_8 * 128 + 114]) << 0x10 | uint(c2da_mem[sectors + i_8 * 128 + 115]) << 0x18) * 8
        let c2da_fresh150 : int = 0
        let c2da_fresh151 : uint = uint(c2da_fresh150)
        c2da_mem[sectors + i_8 * 128 + 112] = uint8(c2da_fresh151)
        c2da_mem[sectors + i_8 * 128 + 113] = uint8(c2da_fresh151 >> 0x8)
        c2da_mem[sectors + i_8 * 128 + 114] = uint8(c2da_fresh151 >> 0x10)
        c2da_mem[sectors + i_8 * 128 + 115] = uint8(c2da_fresh151 >> 0x18)
        i_8++
    }
    i_8 = 0
    while (i_8 < numlines) {
        li_1 = lines + i_8 * 88
        if (int(uint(c2da_mem[li_1 + 56]) | uint(c2da_mem[li_1 + 57]) << 0x8 | uint(c2da_mem[li_1 + 58]) << 0x10 | uint(c2da_mem[li_1 + 59]) << 0x18) != 0) {
            sector = int(uint(c2da_mem[li_1 + 56]) | uint(c2da_mem[li_1 + 57]) << 0x8 | uint(c2da_mem[li_1 + 58]) << 0x10 | uint(c2da_mem[li_1 + 59]) << 0x18)
            let c2da_fresh152 : int = int(uint(c2da_mem[sector + 120]) | uint(c2da_mem[sector + 121]) << 0x8 | uint(c2da_mem[sector + 122]) << 0x10 | uint(c2da_mem[sector + 123]) << 0x18) + int(uint(c2da_mem[sector + 112]) | uint(c2da_mem[sector + 113]) << 0x8 | uint(c2da_mem[sector + 114]) << 0x10 | uint(c2da_mem[sector + 115]) << 0x18) * 8
            let c2da_fresh153 : uint = uint(li_1)
            c2da_mem[c2da_fresh152] = uint8(c2da_fresh153)
            c2da_mem[c2da_fresh152 + 1] = uint8(c2da_fresh153 >> 0x8)
            c2da_mem[c2da_fresh152 + 2] = uint8(c2da_fresh153 >> 0x10)
            c2da_mem[c2da_fresh152 + 3] = uint8(c2da_fresh153 >> 0x18)
            c2da_mem[c2da_fresh152 + 4] = 0u8
            c2da_mem[c2da_fresh152 + 5] = 0u8
            c2da_mem[c2da_fresh152 + 6] = 0u8
            c2da_mem[c2da_fresh152 + 7] = 0u8
            let c2da_fresh154 : int = int(uint(c2da_mem[sector + 112]) | uint(c2da_mem[sector + 113]) << 0x8 | uint(c2da_mem[sector + 114]) << 0x10 | uint(c2da_mem[sector + 115]) << 0x18)
            let c2da_fresh155 : int = c2da_fresh154 + 1
            let c2da_fresh156 : uint = uint(c2da_fresh155)
            c2da_mem[sector + 112] = uint8(c2da_fresh156)
            c2da_mem[sector + 113] = uint8(c2da_fresh156 >> 0x8)
            c2da_mem[sector + 114] = uint8(c2da_fresh156 >> 0x10)
            c2da_mem[sector + 115] = uint8(c2da_fresh156 >> 0x18)
        }
        if (int(uint(c2da_mem[li_1 + 64]) | uint(c2da_mem[li_1 + 65]) << 0x8 | uint(c2da_mem[li_1 + 66]) << 0x10 | uint(c2da_mem[li_1 + 67]) << 0x18) != 0 && int(uint(c2da_mem[li_1 + 56]) | uint(c2da_mem[li_1 + 57]) << 0x8 | uint(c2da_mem[li_1 + 58]) << 0x10 | uint(c2da_mem[li_1 + 59]) << 0x18) != int(uint(c2da_mem[li_1 + 64]) | uint(c2da_mem[li_1 + 65]) << 0x8 | uint(c2da_mem[li_1 + 66]) << 0x10 | uint(c2da_mem[li_1 + 67]) << 0x18)) {
            sector = int(uint(c2da_mem[li_1 + 64]) | uint(c2da_mem[li_1 + 65]) << 0x8 | uint(c2da_mem[li_1 + 66]) << 0x10 | uint(c2da_mem[li_1 + 67]) << 0x18)
            let c2da_fresh157 : int = int(uint(c2da_mem[sector + 120]) | uint(c2da_mem[sector + 121]) << 0x8 | uint(c2da_mem[sector + 122]) << 0x10 | uint(c2da_mem[sector + 123]) << 0x18) + int(uint(c2da_mem[sector + 112]) | uint(c2da_mem[sector + 113]) << 0x8 | uint(c2da_mem[sector + 114]) << 0x10 | uint(c2da_mem[sector + 115]) << 0x18) * 8
            let c2da_fresh158 : uint = uint(li_1)
            c2da_mem[c2da_fresh157] = uint8(c2da_fresh158)
            c2da_mem[c2da_fresh157 + 1] = uint8(c2da_fresh158 >> 0x8)
            c2da_mem[c2da_fresh157 + 2] = uint8(c2da_fresh158 >> 0x10)
            c2da_mem[c2da_fresh157 + 3] = uint8(c2da_fresh158 >> 0x18)
            c2da_mem[c2da_fresh157 + 4] = 0u8
            c2da_mem[c2da_fresh157 + 5] = 0u8
            c2da_mem[c2da_fresh157 + 6] = 0u8
            c2da_mem[c2da_fresh157 + 7] = 0u8
            let c2da_fresh159 : int = int(uint(c2da_mem[sector + 112]) | uint(c2da_mem[sector + 113]) << 0x8 | uint(c2da_mem[sector + 114]) << 0x10 | uint(c2da_mem[sector + 115]) << 0x18)
            let c2da_fresh160 : int = c2da_fresh159 + 1
            let c2da_fresh161 : uint = uint(c2da_fresh160)
            c2da_mem[sector + 112] = uint8(c2da_fresh161)
            c2da_mem[sector + 113] = uint8(c2da_fresh161 >> 0x8)
            c2da_mem[sector + 114] = uint8(c2da_fresh161 >> 0x10)
            c2da_mem[sector + 115] = uint8(c2da_fresh161 >> 0x18)
        }
        i_8++
    }
    sector = sectors
    i_8 = 0
    while (i_8 < numsectors) {
        M_ClearBox(c2da_fp)
        j_0 = 0
        while (j_0 < int(uint(c2da_mem[sector + 112]) | uint(c2da_mem[sector + 113]) << 0x8 | uint(c2da_mem[sector + 114]) << 0x10 | uint(c2da_mem[sector + 115]) << 0x18)) {
            let c2da_fresh162 : int = int(uint(c2da_mem[sector + 120]) | uint(c2da_mem[sector + 121]) << 0x8 | uint(c2da_mem[sector + 122]) << 0x10 | uint(c2da_mem[sector + 123]) << 0x18) + j_0 * 8
            li_1 = int(uint(c2da_mem[c2da_fresh162]) | uint(c2da_mem[c2da_fresh162 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh162 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh162 + 3]) << 0x18)
            let c2da_fresh163 : int = int(uint(c2da_mem[li_1]) | uint(c2da_mem[li_1 + 1]) << 0x8 | uint(c2da_mem[li_1 + 2]) << 0x10 | uint(c2da_mem[li_1 + 3]) << 0x18)
            let c2da_fresh164 : int = int(uint(c2da_mem[li_1]) | uint(c2da_mem[li_1 + 1]) << 0x8 | uint(c2da_mem[li_1 + 2]) << 0x10 | uint(c2da_mem[li_1 + 3]) << 0x18) + 4
            M_AddToBox(c2da_fp, int(uint(c2da_mem[c2da_fresh163]) | uint(c2da_mem[c2da_fresh163 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh163 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh163 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh164]) | uint(c2da_mem[c2da_fresh164 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh164 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh164 + 3]) << 0x18))
            let c2da_fresh165 : int = int(uint(c2da_mem[li_1 + 8]) | uint(c2da_mem[li_1 + 9]) << 0x8 | uint(c2da_mem[li_1 + 10]) << 0x10 | uint(c2da_mem[li_1 + 11]) << 0x18)
            let c2da_fresh166 : int = int(uint(c2da_mem[li_1 + 8]) | uint(c2da_mem[li_1 + 9]) << 0x8 | uint(c2da_mem[li_1 + 10]) << 0x10 | uint(c2da_mem[li_1 + 11]) << 0x18) + 4
            M_AddToBox(c2da_fp, int(uint(c2da_mem[c2da_fresh165]) | uint(c2da_mem[c2da_fresh165 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh165 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh165 + 3]) << 0x18), int(uint(c2da_mem[c2da_fresh166]) | uint(c2da_mem[c2da_fresh166 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh166 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh166 + 3]) << 0x18))
            j_0++
        }
        let c2da_fresh167 : int = (int(uint(c2da_mem[c2da_fp + 3 * 4]) | uint(c2da_mem[c2da_fp + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3 * 4 + 3]) << 0x18) + int(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)) / 2
        let c2da_fresh168 : uint = uint(c2da_fresh167)
        c2da_mem[sector + 72] = uint8(c2da_fresh168)
        c2da_mem[sector + 73] = uint8(c2da_fresh168 >> 0x8)
        c2da_mem[sector + 74] = uint8(c2da_fresh168 >> 0x10)
        c2da_mem[sector + 75] = uint8(c2da_fresh168 >> 0x18)
        let c2da_fresh169 : int = (int(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18) + int(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)) / 2
        let c2da_fresh170 : uint = uint(c2da_fresh169)
        c2da_mem[sector + 76] = uint8(c2da_fresh170)
        c2da_mem[sector + 77] = uint8(c2da_fresh170 >> 0x8)
        c2da_mem[sector + 78] = uint8(c2da_fresh170 >> 0x10)
        c2da_mem[sector + 79] = uint8(c2da_fresh170 >> 0x18)
        block_0 = int(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18) - int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18) + 32 * (1 << 16) >> 16 + 7
        let c2da_fresh171 : int = block_0 >= int(uint(c2da_mem[49760]) | uint(c2da_mem[49761]) << 0x8 | uint(c2da_mem[49762]) << 0x10 | uint(c2da_mem[49763]) << 0x18) ? int(uint(c2da_mem[49760]) | uint(c2da_mem[49761]) << 0x8 | uint(c2da_mem[49762]) << 0x10 | uint(c2da_mem[49763]) << 0x18) - 1 : block_0
        let c2da_fresh172 : uint = uint(c2da_fresh171)
        c2da_mem[sector + 32 + 0 * 4] = uint8(c2da_fresh172)
        c2da_mem[sector + 32 + 0 * 4 + 1] = uint8(c2da_fresh172 >> 0x8)
        c2da_mem[sector + 32 + 0 * 4 + 2] = uint8(c2da_fresh172 >> 0x10)
        c2da_mem[sector + 32 + 0 * 4 + 3] = uint8(c2da_fresh172 >> 0x18)
        block_0 = int(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18) - int(uint(c2da_mem[49744]) | uint(c2da_mem[49745]) << 0x8 | uint(c2da_mem[49746]) << 0x10 | uint(c2da_mem[49747]) << 0x18) - 32 * (1 << 16) >> 16 + 7
        let c2da_fresh173 : int = block_0 < 0 ? 0 : block_0
        let c2da_fresh174 : uint = uint(c2da_fresh173)
        c2da_mem[sector + 32 + 1 * 4] = uint8(c2da_fresh174)
        c2da_mem[sector + 32 + 1 * 4 + 1] = uint8(c2da_fresh174 >> 0x8)
        c2da_mem[sector + 32 + 1 * 4 + 2] = uint8(c2da_fresh174 >> 0x10)
        c2da_mem[sector + 32 + 1 * 4 + 3] = uint8(c2da_fresh174 >> 0x18)
        block_0 = int(uint(c2da_mem[c2da_fp + 3 * 4]) | uint(c2da_mem[c2da_fp + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3 * 4 + 3]) << 0x18) - int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18) + 32 * (1 << 16) >> 16 + 7
        let c2da_fresh175 : int = block_0 >= int(uint(c2da_mem[49712]) | uint(c2da_mem[49713]) << 0x8 | uint(c2da_mem[49714]) << 0x10 | uint(c2da_mem[49715]) << 0x18) ? int(uint(c2da_mem[49712]) | uint(c2da_mem[49713]) << 0x8 | uint(c2da_mem[49714]) << 0x10 | uint(c2da_mem[49715]) << 0x18) - 1 : block_0
        let c2da_fresh176 : uint = uint(c2da_fresh175)
        c2da_mem[sector + 32 + 3 * 4] = uint8(c2da_fresh176)
        c2da_mem[sector + 32 + 3 * 4 + 1] = uint8(c2da_fresh176 >> 0x8)
        c2da_mem[sector + 32 + 3 * 4 + 2] = uint8(c2da_fresh176 >> 0x10)
        c2da_mem[sector + 32 + 3 * 4 + 3] = uint8(c2da_fresh176 >> 0x18)
        block_0 = int(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18) - int(uint(c2da_mem[49728]) | uint(c2da_mem[49729]) << 0x8 | uint(c2da_mem[49730]) << 0x10 | uint(c2da_mem[49731]) << 0x18) - 32 * (1 << 16) >> 16 + 7
        let c2da_fresh177 : int = block_0 < 0 ? 0 : block_0
        let c2da_fresh178 : uint = uint(c2da_fresh177)
        c2da_mem[sector + 32 + 2 * 4] = uint8(c2da_fresh178)
        c2da_mem[sector + 32 + 2 * 4 + 1] = uint8(c2da_fresh178 >> 0x8)
        c2da_mem[sector + 32 + 2 * 4 + 2] = uint8(c2da_fresh178 >> 0x10)
        c2da_mem[sector + 32 + 2 * 4 + 3] = uint8(c2da_fresh178 >> 0x18)
        i_8++
        sector += 128
    }
    return
}
[sideeffects]
def private P_SetupLevel_c2da_frame(var episode : int; var map : int; var playermask : int; var skill : int; c2da_fp : int) {
    var i_10 : int
    var lumpnum_0 : int
    let c2da_fresh184 : int = 0
    let c2da_fresh185 : uint = uint(c2da_fresh184)
    c2da_mem[41340] = uint8(c2da_fresh185)
    c2da_mem[41341] = uint8(c2da_fresh185 >> 0x8)
    c2da_mem[41342] = uint8(c2da_fresh185 >> 0x10)
    c2da_mem[41343] = uint8(c2da_fresh185 >> 0x18)
    totalsecret = c2da_fresh184
    totalitems = totalsecret
    totalkills = totalitems
    let c2da_fresh186 : int = 180
    let c2da_fresh187 : uint = uint(c2da_fresh186)
    c2da_mem[41344] = uint8(c2da_fresh187)
    c2da_mem[41345] = uint8(c2da_fresh187 >> 0x8)
    c2da_mem[41346] = uint8(c2da_fresh187 >> 0x10)
    c2da_mem[41347] = uint8(c2da_fresh187 >> 0x18)
    i_10 = 0
    while (i_10 < 4) {
        let c2da_fresh188 : int = 0
        let c2da_fresh189 : uint = uint(c2da_fresh188)
        c2da_mem[96 + i_10 * 328 + 220] = uint8(c2da_fresh189)
        c2da_mem[96 + i_10 * 328 + 221] = uint8(c2da_fresh189 >> 0x8)
        c2da_mem[96 + i_10 * 328 + 222] = uint8(c2da_fresh189 >> 0x10)
        c2da_mem[96 + i_10 * 328 + 223] = uint8(c2da_fresh189 >> 0x18)
        let c2da_fresh190 : uint = uint(c2da_fresh188)
        c2da_mem[96 + i_10 * 328 + 224] = uint8(c2da_fresh190)
        c2da_mem[96 + i_10 * 328 + 225] = uint8(c2da_fresh190 >> 0x8)
        c2da_mem[96 + i_10 * 328 + 226] = uint8(c2da_fresh190 >> 0x10)
        c2da_mem[96 + i_10 * 328 + 227] = uint8(c2da_fresh190 >> 0x18)
        let c2da_fresh191 : uint = uint(c2da_fresh188)
        c2da_mem[96 + i_10 * 328 + 216] = uint8(c2da_fresh191)
        c2da_mem[96 + i_10 * 328 + 217] = uint8(c2da_fresh191 >> 0x8)
        c2da_mem[96 + i_10 * 328 + 218] = uint8(c2da_fresh191 >> 0x10)
        c2da_mem[96 + i_10 * 328 + 219] = uint8(c2da_fresh191 >> 0x18)
        i_10++
    }
    let c2da_fresh192 : int = 1
    let c2da_fresh193 : uint = uint(c2da_fresh192)
    c2da_mem[96 + int(consoleplayer) * 328 + 28] = uint8(c2da_fresh193)
    c2da_mem[96 + int(consoleplayer) * 328 + 29] = uint8(c2da_fresh193 >> 0x8)
    c2da_mem[96 + int(consoleplayer) * 328 + 30] = uint8(c2da_fresh193 >> 0x10)
    c2da_mem[96 + int(consoleplayer) * 328 + 31] = uint8(c2da_fresh193 >> 0x18)
    S_Start()
    Z_FreeTags(5, 7 - 1)
    P_InitThinkers()
    if (uint(gamemode) == 2u) {
        if (map < 10) {
            c2da_lin_snprintf(c2da_fp, 9ul, 361117, [C2daVaArg(tag = 1, i64 = int64(map), f64 = 0.0lf, raw = 0x0)])
        } else {
            c2da_lin_snprintf(c2da_fp, 9ul, 361124, [C2daVaArg(tag = 1, i64 = int64(map), f64 = 0.0lf, raw = 0x0)])
        }
    } else {
        let c2da_fresh194 : int8 = int8(69)
        c2da_mem[c2da_fp + 0] = uint8(c2da_fresh194)
        let c2da_fresh195 : int8 = int8(48 + episode)
        c2da_mem[c2da_fp + 1] = uint8(c2da_fresh195)
        let c2da_fresh196 : int8 = int8(77)
        c2da_mem[c2da_fp + 2] = uint8(c2da_fresh196)
        let c2da_fresh197 : int8 = int8(48 + map)
        c2da_mem[c2da_fp + 3] = uint8(c2da_fresh197)
        let c2da_fresh198 : int8 = int8(0)
        c2da_mem[c2da_fp + 4] = uint8(c2da_fresh198)
    }
    lumpnum_0 = W_GetNumForName(c2da_fp)
    leveltime = 0
    P_LoadBlockMap(lumpnum_0 + 10)
    P_LoadVertexes(lumpnum_0 + 4)
    P_LoadSectors(lumpnum_0 + 8)
    P_LoadSideDefs(lumpnum_0 + 3)
    P_LoadLineDefs(lumpnum_0 + 2)
    P_LoadSubsectors(lumpnum_0 + 6)
    P_LoadNodes(lumpnum_0 + 7)
    P_LoadSegs(lumpnum_0 + 5)
    P_GroupLines()
    P_LoadReject(lumpnum_0 + 9)
    bodyqueslot = 0
    deathmatch_p = 40768
    P_LoadThings(lumpnum_0 + 1)
    if (deathmatch != 0) {
        i_10 = 0
        for (c2da_i_10 in range(i_10, 4)) {
            if (playeringame[c2da_i_10] != 0x0) {
                let c2da_fresh199 : uint = 0u
                c2da_mem[96 + c2da_i_10 * 328] = uint8(c2da_fresh199)
                c2da_mem[96 + c2da_i_10 * 328 + 1] = uint8(c2da_fresh199 >> 0x8)
                c2da_mem[96 + c2da_i_10 * 328 + 2] = uint8(c2da_fresh199 >> 0x10)
                c2da_mem[96 + c2da_i_10 * 328 + 3] = uint8(c2da_fresh199 >> 0x18)
                c2da_mem[96 + c2da_i_10 * 328 + 4] = 0u8
                c2da_mem[96 + c2da_i_10 * 328 + 5] = 0u8
                c2da_mem[96 + c2da_i_10 * 328 + 6] = 0u8
                c2da_mem[96 + c2da_i_10 * 328 + 7] = 0u8
                G_DeathMatchSpawnPlayer(c2da_i_10)
            }
        }
    }
    iquetail = 0
    iquehead = iquetail
    P_SpawnSpecials()
    if (precache != 0x0) {
        R_PrecacheLevel()
    }
    return
}

// This unit's static data, at heap offset 360912.
let private c2da_lin_static_p_setup_seg = fixed_array<int>(361040, 89)
let private c2da_lin_static_p_setup = fixed_array<uint64>(0x63656a6552646150ul, 0x203a796172724174ul, 0x6c205443454a4552ul, 0x206f6f7420706d75ul, 0x6f742074726f6873ul, 0x2528202164617020ul, 0xa296925203e2069ul, 0x7463656a65722d00ul, 0x7469775f6461705ful, 0x70616d0066665f68ul, 0x2570616d00692530ul, 0x69ul)

[init]
def private c2da_lin_init_static_p_setup() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_p_setup_seg[s * 2]
        for (k in range(c2da_lin_static_p_setup_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_p_setup[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
