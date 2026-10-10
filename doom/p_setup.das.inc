var private c2da_str_p_setup_0 : array<int8> = [int8(80), int8(97), int8(100), int8(82), int8(101), int8(106), int8(101), int8(99), int8(116), int8(65), int8(114), int8(114), int8(97), int8(121), int8(58), int8(32), int8(82), int8(69), int8(74), int8(69), int8(67), int8(84), int8(32), int8(108), int8(117), int8(109), int8(112), int8(32), int8(116), int8(111), int8(111), int8(32), int8(115), int8(104), int8(111), int8(114), int8(116), int8(32), int8(116), int8(111), int8(32), int8(112), int8(97), int8(100), int8(33), int8(32), int8(40), int8(37), int8(105), int8(32), int8(62), int8(32), int8(37), int8(105), int8(41), int8(10), int8(0)]

var private c2da_str_p_setup_1 : array<int8> = [int8(45), int8(114), int8(101), int8(106), int8(101), int8(99), int8(116), int8(95), int8(112), int8(97), int8(100), int8(95), int8(119), int8(105), int8(116), int8(104), int8(95), int8(102), int8(102), int8(0)]

var private c2da_str_p_setup_2 : array<int8> = [int8(109), int8(97), int8(112), int8(48), int8(37), int8(105), int8(0)]

var private c2da_str_p_setup_3 : array<int8> = [int8(109), int8(97), int8(112), int8(37), int8(105), int8(0)]

[sideeffects]
def private c2da_records_mapthing_t_10(base : uint64) : mapthing_t[10] {
    return fixed_array<mapthing_t>(mapthing_t(c2da_storage = base), mapthing_t(c2da_storage = base + 10ul), mapthing_t(c2da_storage = base + 20ul), mapthing_t(c2da_storage = base + 30ul), mapthing_t(c2da_storage = base + 40ul), mapthing_t(c2da_storage = base + 50ul), mapthing_t(c2da_storage = base + 60ul), mapthing_t(c2da_storage = base + 70ul), mapthing_t(c2da_storage = base + 80ul), mapthing_t(c2da_storage = base + 90ul))
}
[sideeffects]
def private c2da_records_mapthing_t_4(base : uint64) : mapthing_t[4] {
    return fixed_array<mapthing_t>(mapthing_t(c2da_storage = base), mapthing_t(c2da_storage = base + 10ul), mapthing_t(c2da_storage = base + 20ul), mapthing_t(c2da_storage = base + 30ul))
}
var private GetSectorAtNullAddress__null_sector_is_initialized : uint = 0u

var private GetSectorAtNullAddress__null_sector : sector_t = sector_t()

var numvertexes : int = default<int>

var vertexes : vertex_t? = default<vertex_t?>

var numsegs : int = default<int>

var segs : seg_t? = default<seg_t?>

var numsectors : int = default<int>

var sectors : sector_t? = default<sector_t?>

var numsubsectors : int = default<int>

var subsectors : subsector_s? = default<subsector_s?>

var numnodes : int = default<int>

var nodes : node_t? = default<node_t?>

var numlines : int = default<int>

var lines : line_s? = default<line_s?>

var numsides : int = default<int>

var sides : side_t? = default<side_t?>

var rejectmatrix : uint8? = default<uint8?>

var blockmaplump : int16? = default<int16?>

var blockmap : int16? = default<int16?>

var bmapwidth : int = default<int>

var bmapheight : int = default<int>

var bmaporgx : int = default<int>

var bmaporgy : int = default<int>

var blocklinks : mobj_s?? = default<mobj_s??>

var deathmatchstarts : mapthing_t[10] = c2da_records_mapthing_t_10(c2da_rt_calloc(1ul, 100ul))

var deathmatch_p : mapthing_t? = default<mapthing_t?>

var playerstarts : mapthing_t[4] = c2da_records_mapthing_t_4(c2da_rt_calloc(1ul, 40ul))

var private totallines : int = default<int>

[export, sideeffects]
def P_LoadVertexes(var lump : int) {
    var data : uint8?
    var i : int
    var ml : mapvertex_t?
    var li : vertex_t?
    numvertexes = int(uint64(W_LumpLength(uint(lump))) / 4ul)
    vertexes = unsafe(reinterpret<vertex_t?>(unsafe(reinterpret<vertex_t?>(Z_Malloc(int(uint64(numvertexes) * 8ul), 5, null)))))
    data = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(W_CacheLumpNum(lump, 1)))))
    ml = unsafe(reinterpret<mapvertex_t?>(unsafe(reinterpret<mapvertex_t?>(data))))
    li = unsafe(reinterpret<vertex_t?>(vertexes))
    var c2da_li_addr : uint64 = unsafe(reinterpret<uint64>(li))
    i = 0
    while (i < numvertexes) {
        unsafe(reinterpret<vertex_t?>(c2da_li_addr)).x = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ml))))[0])) << 16
        unsafe(reinterpret<vertex_t?>(c2da_li_addr)).y = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ml))))[1])) << 16
        i++
        c2da_li_addr += 8ul
        ml = unsafe(reinterpret<mapvertex_t?>(unsafe(reinterpret<uint64>(ml)) + 4ul))
    }
    W_ReleaseLumpNum(lump)
    return
}
[export, sideeffects]
def GetSectorAtNullAddress() : sector_t? {
    if (GetSectorAtNullAddress__null_sector_is_initialized == 0) {
        unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(addr<uint8?>(GetSectorAtNullAddress__null_sector)))), 0u8, 128ul)))
        I_GetMemoryValue(0u, unsafe(addr<uint8?>(GetSectorAtNullAddress__null_sector.floorheight)), 4)
        I_GetMemoryValue(4u, unsafe(addr<uint8?>(GetSectorAtNullAddress__null_sector.ceilingheight)), 4)
        GetSectorAtNullAddress__null_sector_is_initialized = 1u
    }
    return unsafe(addr<sector_t?>(GetSectorAtNullAddress__null_sector))
}
[export, sideeffects]
def P_LoadSegs(var lump_0 : int) {
    var data_0 : uint8?
    var i_0 : int
    var ml_0 : mapseg_t?
    var li_0 : seg_t?
    var ldef : line_s?
    var linedef_0 : int
    var side : int
    var sidenum : int
    numsegs = int(uint64(W_LumpLength(uint(lump_0))) / 12ul)
    segs = unsafe(reinterpret<seg_t?>(unsafe(reinterpret<seg_t?>(Z_Malloc(int(uint64(numsegs) * 56ul), 5, null)))))
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(segs)))), 0u8, uint64(numsegs) * 56ul)))
    data_0 = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(W_CacheLumpNum(lump_0, 1)))))
    ml_0 = unsafe(reinterpret<mapseg_t?>(unsafe(reinterpret<mapseg_t?>(data_0))))
    li_0 = unsafe(reinterpret<seg_t?>(segs))
    var c2da_li_0_addr : uint64 = unsafe(reinterpret<uint64>(li_0))
    i_0 = 0
    while (i_0 < numsegs) {
        unsafe(reinterpret<seg_t?>(c2da_li_0_addr)).v1 = unsafe(addr(unsafe(vertexes[int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ml_0))))[0]))])))
        unsafe(reinterpret<seg_t?>(c2da_li_0_addr)).v2 = unsafe(addr(unsafe(vertexes[int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ml_0))))[1]))])))
        unsafe(reinterpret<seg_t?>(c2da_li_0_addr)).angle = uint(int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ml_0))))[2])) << 16)
        unsafe(reinterpret<seg_t?>(c2da_li_0_addr)).offset = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ml_0))))[5])) << 16
        linedef_0 = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ml_0))))[3]))
        ldef = unsafe(addr<line_s?>(unsafe(lines[linedef_0])))
        unsafe(reinterpret<seg_t?>(c2da_li_0_addr)).linedef = ldef
        side = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ml_0))))[4]))
        var c2da_fresh6 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ldef)) + 30ul))
        unsafe(reinterpret<seg_t?>(c2da_li_0_addr)).sidedef = unsafe(addr(unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh6))[side]))])))
        var c2da_fresh7 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ldef)) + 30ul))
        unsafe(reinterpret<seg_t?>(c2da_li_0_addr)).frontsector = unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh7))[side]))]).sector
        if ((int(ldef.flags) & 4) != 0) {
            var c2da_fresh8 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ldef)) + 30ul))
            sidenum = int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh8))[side ^ 1]))
            if (sidenum < 0 || sidenum >= numsides) {
                unsafe(reinterpret<seg_t?>(c2da_li_0_addr)).backsector = unsafe(reinterpret<sector_t?>(GetSectorAtNullAddress()))
            } else {
                unsafe(reinterpret<seg_t?>(c2da_li_0_addr)).backsector = unsafe(sides[sidenum]).sector
            }
        } else {
            unsafe(reinterpret<seg_t?>(c2da_li_0_addr)).backsector = null
        }
        i_0++
        c2da_li_0_addr += 56ul
        ml_0 = unsafe(reinterpret<mapseg_t?>(unsafe(reinterpret<uint64>(ml_0)) + 12ul))
    }
    W_ReleaseLumpNum(lump_0)
    return
}
[export, sideeffects]
def P_LoadSubsectors(var lump_1 : int) {
    var data_1 : uint8?
    var i_1 : int
    var ms : mapsubsector_t?
    var ss : subsector_s?
    numsubsectors = int(uint64(W_LumpLength(uint(lump_1))) / 4ul)
    subsectors = unsafe(reinterpret<subsector_s?>(unsafe(reinterpret<subsector_s?>(Z_Malloc(int(uint64(numsubsectors) * 16ul), 5, null)))))
    data_1 = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(W_CacheLumpNum(lump_1, 1)))))
    ms = unsafe(reinterpret<mapsubsector_t?>(unsafe(reinterpret<mapsubsector_t?>(data_1))))
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(subsectors)))), 0u8, uint64(numsubsectors) * 16ul)))
    ss = unsafe(reinterpret<subsector_s?>(subsectors))
    var c2da_ss_addr : uint64 = unsafe(reinterpret<uint64>(ss))
    i_1 = 0
    while (i_1 < numsubsectors) {
        unsafe(reinterpret<subsector_s?>(c2da_ss_addr)).numlines = int16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ms))))[0]))  // nolint:PERF020
        unsafe(reinterpret<subsector_s?>(c2da_ss_addr)).firstline = int16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ms))))[1]))  // nolint:PERF020
        i_1++
        c2da_ss_addr += 16ul
        ms = unsafe(reinterpret<mapsubsector_t?>(unsafe(reinterpret<uint64>(ms)) + 4ul))
    }
    W_ReleaseLumpNum(lump_1)
    return
}
[export, sideeffects]
def P_LoadSectors(var lump_2 : int) {
    var data_2 : uint8?
    var i_2 : int
    var ms_0 : mapsector_t?
    var ss_0 : sector_t?
    numsectors = int(uint64(W_LumpLength(uint(lump_2))) / 26ul)
    sectors = unsafe(reinterpret<sector_t?>(unsafe(reinterpret<sector_t?>(Z_Malloc(int(uint64(numsectors) * 128ul), 5, null)))))
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(sectors)))), 0u8, uint64(numsectors) * 128ul)))
    data_2 = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(W_CacheLumpNum(lump_2, 1)))))
    ms_0 = unsafe(reinterpret<mapsector_t?>(unsafe(reinterpret<mapsector_t?>(data_2))))
    ss_0 = unsafe(reinterpret<sector_t?>(sectors))
    var c2da_ss_0_addr : uint64 = unsafe(reinterpret<uint64>(ss_0))
    i_2 = 0
    while (i_2 < numsectors) {
        unsafe(reinterpret<sector_t?>(c2da_ss_0_addr)).floorheight = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ms_0))))[0])) << 16
        unsafe(reinterpret<sector_t?>(c2da_ss_0_addr)).ceilingheight = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ms_0))))[1])) << 16
        var c2da_fresh9 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(ms_0)) + 4ul))
        unsafe(reinterpret<sector_t?>(c2da_ss_0_addr)).floorpic = int16(R_FlatNumForName(unsafe(reinterpret<int8?>(c2da_fresh9))))
        var c2da_fresh10 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(ms_0)) + 12ul))
        unsafe(reinterpret<sector_t?>(c2da_ss_0_addr)).ceilingpic = int16(R_FlatNumForName(unsafe(reinterpret<int8?>(c2da_fresh10))))
        unsafe(reinterpret<sector_t?>(c2da_ss_0_addr)).lightlevel = int16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ms_0))))[10]))  // nolint:PERF020
        unsafe(reinterpret<sector_t?>(c2da_ss_0_addr)).special = int16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ms_0))))[11]))  // nolint:PERF020
        unsafe(reinterpret<sector_t?>(c2da_ss_0_addr)).tag = int16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(ms_0))))[12]))  // nolint:PERF020
        unsafe(reinterpret<sector_t?>(c2da_ss_0_addr)).thinglist = null
        i_2++
        c2da_ss_0_addr += 128ul
        ms_0 = unsafe(reinterpret<mapsector_t?>(unsafe(reinterpret<uint64>(ms_0)) + 26ul))
    }
    W_ReleaseLumpNum(lump_2)
    return
}
[export, sideeffects]
def P_LoadNodes(var lump_3 : int) {
    var data_3 : uint8?
    var i_3 : int
    var mn : mapnode_t?
    var no : node_t?
    numnodes = int(uint64(W_LumpLength(uint(lump_3))) / 28ul)
    nodes = unsafe(reinterpret<node_t?>(unsafe(reinterpret<node_t?>(Z_Malloc(int(uint64(numnodes) * 52ul), 5, null)))))
    data_3 = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(W_CacheLumpNum(lump_3, 1)))))
    mn = unsafe(reinterpret<mapnode_t?>(unsafe(reinterpret<mapnode_t?>(data_3))))
    no = unsafe(reinterpret<node_t?>(nodes))
    var c2da_no_addr : uint64 = unsafe(reinterpret<uint64>(no))
    i_3 = 0
    while (i_3 < numnodes) {
        unsafe(reinterpret<node_t?>(c2da_no_addr)).x = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(mn))))[0])) << 16
        unsafe(reinterpret<node_t?>(c2da_no_addr)).y = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(mn))))[1])) << 16
        unsafe(reinterpret<node_t?>(c2da_no_addr)).dx = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(mn))))[2])) << 16
        unsafe(reinterpret<node_t?>(c2da_no_addr)).dy = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(mn))))[3])) << 16
        for (j in range(0, 2)) {
            var c2da_fresh11 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<node_t?>(c2da_no_addr)))) + 48ul))
            var c2da_fresh12 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(mn)) + 24ul))
            unsafe(unsafe(reinterpret<uint16?>(c2da_fresh11))[j]) = uint16(int16(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh12))[j])))
            for (k in range(0, 4)) {
                var c2da_fresh13 : int[4]? = unsafe(reinterpret<int[4]?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<node_t?>(c2da_no_addr)))) + 16ul))
                var c2da_fresh14 : int16[4]? = unsafe(reinterpret<int16[4]?>(unsafe(reinterpret<uint64>(mn)) + 8ul))
                unsafe(unsafe(addr(unsafe(unsafe(reinterpret<int[4]?>(c2da_fresh13))[j])[0]))[k]) = int(unsafe(unsafe(addr(unsafe(unsafe(reinterpret<int16[4]?>(c2da_fresh14))[j])[0]))[k])) << 16
            }
        }
        i_3++
        c2da_no_addr += 52ul
        mn = unsafe(reinterpret<mapnode_t?>(unsafe(reinterpret<uint64>(mn)) + 28ul))
    }
    W_ReleaseLumpNum(lump_3)
    return
}
[export, sideeffects]
def P_LoadThings(var lump_4 : int) {
    var c2da_fresh15 : int
    var data_4 : uint8?
    var i_4 : int
    var mt : mapthing_t?
    var spawnthing : mapthing_t = mapthing_t(c2da_storage = c2da_rt_calloc(1ul, 10ul))
    var numthings : int
    var spawn : uint
    var c2da_fresh16 : mapthing_t?
    data_4 = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(W_CacheLumpNum(lump_4, 1)))))
    numthings = int(uint64(W_LumpLength(uint(lump_4))) / 10ul)
    mt = unsafe(reinterpret<mapthing_t?>(unsafe(reinterpret<mapthing_t?>(data_4))))
    i_4 = 0
    while (i_4 < numthings) {
        spawn = 1u
        if (uint(gamemode) == 2u) {
            goto label 2
        }
        c2da_fresh15 = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(mt))))[3]))
        if (c2da_fresh15 < 69) {
            if (c2da_fresh15 >= 64 && c2da_fresh15 <= 68) {
                goto c2da_fresh15 - 61
            }
        } else {
            if (c2da_fresh15 < 84) {
                if (c2da_fresh15 == 69) {
                    goto label 0
                } elif (c2da_fresh15 == 71) {
                    goto label 0
                }
            } else {
                if (c2da_fresh15 == 84) {
                    goto label 0
                } elif (c2da_fresh15 == 88) {
                    goto label 0
                } elif (c2da_fresh15 == 89) {
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
        unsafe(unsafe(reinterpret<int16?>(spawnthing.c2da_storage))[0]) = int16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(mt))))[0]))  // nolint:PERF020
        unsafe(unsafe(reinterpret<int16?>(spawnthing.c2da_storage))[1]) = int16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(mt))))[1]))  // nolint:PERF020
        unsafe(unsafe(reinterpret<int16?>(spawnthing.c2da_storage))[2]) = int16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(mt))))[2]))  // nolint:PERF020
        unsafe(unsafe(reinterpret<int16?>(spawnthing.c2da_storage))[3]) = int16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(mt))))[3]))  // nolint:PERF020
        unsafe(unsafe(reinterpret<int16?>(spawnthing.c2da_storage))[4]) = int16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(mt))))[4]))  // nolint:PERF020
        c2da_fresh16 = unsafe(reinterpret<mapthing_t?>(spawnthing.c2da_storage))
        P_SpawnMapThing(unsafe(reinterpret<mapthing_t?>(c2da_fresh16)))
        i_4++
        mt = unsafe(reinterpret<mapthing_t?>(unsafe(reinterpret<uint64>(mt)) + 10ul))
    }
    W_ReleaseLumpNum(lump_4)
    return
}
[export, sideeffects]
def P_LoadLineDefs(var lump_5 : int) {
    var data_5 : uint8?
    var i_5 : int
    var mld : maplinedef_t?
    var ld : line_s?
    var v1 : vertex_t?
    var v2 : vertex_t?
    numlines = int(uint64(W_LumpLength(uint(lump_5))) / 14ul)
    lines = unsafe(reinterpret<line_s?>(unsafe(reinterpret<line_s?>(Z_Malloc(int(uint64(numlines) * 88ul), 5, null)))))
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(lines)))), 0u8, uint64(numlines) * 88ul)))
    data_5 = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(W_CacheLumpNum(lump_5, 1)))))
    mld = unsafe(reinterpret<maplinedef_t?>(unsafe(reinterpret<maplinedef_t?>(data_5))))
    ld = unsafe(reinterpret<line_s?>(lines))
    var c2da_ld_addr : uint64 = unsafe(reinterpret<uint64>(ld))
    i_5 = 0
    while (i_5 < numlines) {
        unsafe(reinterpret<line_s?>(c2da_ld_addr)).flags = int16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(mld))))[2]))  // nolint:PERF020
        unsafe(reinterpret<line_s?>(c2da_ld_addr)).special = int16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(mld))))[3]))  // nolint:PERF020
        unsafe(reinterpret<line_s?>(c2da_ld_addr)).tag = int16(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(mld))))[4]))  // nolint:PERF020
        var c2da_fresh17 : vertex_t? = unsafe(addr(unsafe(vertexes[int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(mld))))[0]))])))
        unsafe(reinterpret<line_s?>(c2da_ld_addr)).v1 = c2da_fresh17
        v1 = unsafe(reinterpret<vertex_t?>(c2da_fresh17))
        var c2da_fresh18 : vertex_t? = unsafe(addr(unsafe(vertexes[int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(mld))))[1]))])))
        unsafe(reinterpret<line_s?>(c2da_ld_addr)).v2 = c2da_fresh18
        v2 = unsafe(reinterpret<vertex_t?>(c2da_fresh18))
        unsafe(reinterpret<line_s?>(c2da_ld_addr)).dx = v2.x - v1.x
        unsafe(reinterpret<line_s?>(c2da_ld_addr)).dy = v2.y - v1.y
        if (unsafe(reinterpret<line_s?>(c2da_ld_addr)).dx == 0) {
            unsafe(reinterpret<line_s?>(c2da_ld_addr)).slopetype = unsafe(reinterpret<slopetype_t>(1u))
        } elif (unsafe(reinterpret<line_s?>(c2da_ld_addr)).dy == 0) {
            unsafe(reinterpret<line_s?>(c2da_ld_addr)).slopetype = unsafe(reinterpret<slopetype_t>(0u))
        } elif (FixedDiv(unsafe(reinterpret<line_s?>(c2da_ld_addr)).dy, unsafe(reinterpret<line_s?>(c2da_ld_addr)).dx) > 0) {
            unsafe(reinterpret<line_s?>(c2da_ld_addr)).slopetype = unsafe(reinterpret<slopetype_t>(2u))
        } else {
            unsafe(reinterpret<line_s?>(c2da_ld_addr)).slopetype = unsafe(reinterpret<slopetype_t>(3u))
        }
        if (v1.x < v2.x) {
            var c2da_fresh19 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<line_s?>(c2da_ld_addr)))) + 36ul))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh19))[2]) = int(v1.x)  // nolint:PERF020
            var c2da_fresh20 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<line_s?>(c2da_ld_addr)))) + 36ul))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh20))[3]) = int(v2.x)  // nolint:PERF020
        } else {
            var c2da_fresh21 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<line_s?>(c2da_ld_addr)))) + 36ul))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh21))[2]) = int(v2.x)  // nolint:PERF020
            var c2da_fresh22 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<line_s?>(c2da_ld_addr)))) + 36ul))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh22))[3]) = int(v1.x)  // nolint:PERF020
        }
        if (v1.y < v2.y) {
            var c2da_fresh23 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<line_s?>(c2da_ld_addr)))) + 36ul))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh23))[1]) = int(v1.y)  // nolint:PERF020
            var c2da_fresh24 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<line_s?>(c2da_ld_addr)))) + 36ul))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh24))[0]) = int(v2.y)  // nolint:PERF020
        } else {
            var c2da_fresh25 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<line_s?>(c2da_ld_addr)))) + 36ul))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh25))[1]) = int(v2.y)  // nolint:PERF020
            var c2da_fresh26 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<line_s?>(c2da_ld_addr)))) + 36ul))
            unsafe(unsafe(reinterpret<int?>(c2da_fresh26))[0]) = int(v1.y)  // nolint:PERF020
        }
        var c2da_fresh27 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<line_s?>(c2da_ld_addr)))) + 30ul))
        var c2da_fresh28 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(mld)) + 10ul))
        unsafe(unsafe(reinterpret<int16?>(c2da_fresh27))[0]) = int16(unsafe(unsafe(reinterpret<int16?>(c2da_fresh28))[0]))  // nolint:PERF020
        var c2da_fresh29 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<line_s?>(c2da_ld_addr)))) + 30ul))
        var c2da_fresh30 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(mld)) + 10ul))
        unsafe(unsafe(reinterpret<int16?>(c2da_fresh29))[1]) = int16(unsafe(unsafe(reinterpret<int16?>(c2da_fresh30))[1]))  // nolint:PERF020
        var c2da_fresh31 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<line_s?>(c2da_ld_addr)))) + 30ul))
        if (int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh31))[0])) != -1) {
            var c2da_fresh32 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<line_s?>(c2da_ld_addr)))) + 30ul))
            unsafe(reinterpret<line_s?>(c2da_ld_addr)).frontsector = unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh32))[0]))]).sector
        } else {
            unsafe(reinterpret<line_s?>(c2da_ld_addr)).frontsector = null
        }
        var c2da_fresh33 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<line_s?>(c2da_ld_addr)))) + 30ul))
        if (int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh33))[1])) != -1) {
            var c2da_fresh34 : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<line_s?>(c2da_ld_addr)))) + 30ul))
            unsafe(reinterpret<line_s?>(c2da_ld_addr)).backsector = unsafe(sides[int(unsafe(unsafe(reinterpret<int16?>(c2da_fresh34))[1]))]).sector
        } else {
            unsafe(reinterpret<line_s?>(c2da_ld_addr)).backsector = null
        }
        i_5++
        mld = unsafe(reinterpret<maplinedef_t?>(unsafe(reinterpret<uint64>(mld)) + 14ul))
        c2da_ld_addr += 88ul
    }
    W_ReleaseLumpNum(lump_5)
    return
}
[export, sideeffects]
def P_LoadSideDefs(var lump_6 : int) {
    var data_6 : uint8?
    var i_6 : int
    var msd : mapsidedef_t?
    var sd : side_t?
    numsides = int(uint64(W_LumpLength(uint(lump_6))) / 30ul)
    sides = unsafe(reinterpret<side_t?>(unsafe(reinterpret<side_t?>(Z_Malloc(int(uint64(numsides) * 24ul), 5, null)))))
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(sides)))), 0u8, uint64(numsides) * 24ul)))
    data_6 = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(W_CacheLumpNum(lump_6, 1)))))
    msd = unsafe(reinterpret<mapsidedef_t?>(unsafe(reinterpret<mapsidedef_t?>(data_6))))
    sd = unsafe(reinterpret<side_t?>(sides))
    var c2da_sd_addr : uint64 = unsafe(reinterpret<uint64>(sd))
    i_6 = 0
    while (i_6 < numsides) {
        unsafe(reinterpret<side_t?>(c2da_sd_addr)).textureoffset = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(msd))))[0])) << 16
        unsafe(reinterpret<side_t?>(c2da_sd_addr)).rowoffset = int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(msd))))[1])) << 16
        var c2da_fresh35 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(msd)) + 4ul))
        unsafe(reinterpret<side_t?>(c2da_sd_addr)).toptexture = int16(R_TextureNumForName(unsafe(reinterpret<int8?>(c2da_fresh35))))
        var c2da_fresh36 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(msd)) + 12ul))
        unsafe(reinterpret<side_t?>(c2da_sd_addr)).bottomtexture = int16(R_TextureNumForName(unsafe(reinterpret<int8?>(c2da_fresh36))))
        var c2da_fresh37 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(msd)) + 20ul))
        unsafe(reinterpret<side_t?>(c2da_sd_addr)).midtexture = int16(R_TextureNumForName(unsafe(reinterpret<int8?>(c2da_fresh37))))
        unsafe(reinterpret<side_t?>(c2da_sd_addr)).sector = unsafe(addr(unsafe(sectors[int(unsafe(unsafe(reinterpret<int16?>(unsafe(reinterpret<uint64>(msd))))[14]))])))
        i_6++
        msd = unsafe(reinterpret<mapsidedef_t?>(unsafe(reinterpret<uint64>(msd)) + 30ul))
        c2da_sd_addr += 24ul
    }
    W_ReleaseLumpNum(lump_6)
    return
}
[export, sideeffects]
def P_LoadBlockMap(var lump_7 : int) {
    var count : int
    var lumplen : int = W_LumpLength(uint(lump_7))
    count = lumplen / 2
    blockmaplump = unsafe(reinterpret<int16?>(unsafe(reinterpret<int16?>(Z_Malloc(lumplen, 5, null)))))
    W_ReadLump(uint(lump_7), unsafe(reinterpret<uint8?>(blockmaplump)))
    blockmap = unsafe(reinterpret<int16?>(unsafe(blockmaplump + 4)))
    for (i_7 in range(0, count)) {
        unsafe(blockmaplump[i_7]) = int16(unsafe(blockmaplump[i_7]))  // nolint:PERF020
    }
    bmaporgx = int(unsafe(blockmaplump[0])) << 16
    bmaporgy = int(unsafe(blockmaplump[1])) << 16
    bmapwidth = int(unsafe(blockmaplump[2]))
    bmapheight = int(unsafe(blockmaplump[3]))
    count = int(8ul * uint64(bmapwidth) * uint64(bmapheight))
    blocklinks = unsafe(reinterpret<mobj_s??>(unsafe(reinterpret<mobj_s??>(Z_Malloc(count, 5, null)))))
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(blocklinks)))), 0u8, uint64(count))))
    return
}
[export, sideeffects]
def P_GroupLines() {
    var linebuffer : line_s??
    var i_8 : int
    var j_0 : int
    var li_1 : line_s?
    var sector : sector_t?
    var ss_1 : subsector_s?
    var seg : seg_t?
    var bbox : int[4]
    var block_0 : int
    ss_1 = unsafe(reinterpret<subsector_s?>(subsectors))
    var c2da_ss_1_addr : uint64 = unsafe(reinterpret<uint64>(ss_1))
    i_8 = 0
    while (i_8 < numsubsectors) {
        seg = unsafe(addr<seg_t?>(unsafe(segs[int(unsafe(reinterpret<subsector_s?>(c2da_ss_1_addr)).firstline)])))
        unsafe(reinterpret<subsector_s?>(c2da_ss_1_addr)).sector = seg.sidedef.sector
        i_8++
        c2da_ss_1_addr += 16ul
    }
    li_1 = unsafe(reinterpret<line_s?>(lines))
    totallines = 0
    var c2da_li_1_addr : uint64 = unsafe(reinterpret<uint64>(li_1))
    i_8 = 0
    while (i_8 < numlines) {
        totallines++
        let c2da_postinc : int = unsafe(reinterpret<line_s?>(c2da_li_1_addr)).frontsector.linecount
        unsafe(reinterpret<line_s?>(c2da_li_1_addr)).frontsector.linecount = c2da_postinc + 1
        if (unsafe(reinterpret<line_s?>(c2da_li_1_addr)).backsector != null && unsafe(reinterpret<line_s?>(c2da_li_1_addr)).backsector != unsafe(reinterpret<line_s?>(c2da_li_1_addr)).frontsector) {
            let c2da_postinc_0 : int = unsafe(reinterpret<line_s?>(c2da_li_1_addr)).backsector.linecount
            unsafe(reinterpret<line_s?>(c2da_li_1_addr)).backsector.linecount = c2da_postinc_0 + 1
            totallines++
        }
        i_8++
        c2da_li_1_addr += 88ul
    }
    li_1 = unsafe(reinterpret<line_s?>(c2da_li_1_addr))
    linebuffer = unsafe(reinterpret<line_s??>(unsafe(reinterpret<line_s??>(Z_Malloc(int(uint64(totallines) * 8ul), 5, null)))))
    i_8 = 0
    while (i_8 < numsectors) {
        unsafe(sectors[i_8]).lines = unsafe(reinterpret<line_s??>(linebuffer))
        unsafe {
            linebuffer += int64(unsafe(sectors[i_8]).linecount)
        }
        unsafe(sectors[i_8]).linecount = 0
        i_8++
    }
    i_8 = 0
    while (i_8 < numlines) {
        li_1 = unsafe(addr<line_s?>(unsafe(lines[i_8])))
        if (li_1.frontsector != null) {
            sector = unsafe(reinterpret<sector_t?>(li_1.frontsector))
            unsafe(sector.lines[sector.linecount]) = unsafe(reinterpret<line_s?>(li_1))
            let c2da_postinc_1 : int = sector.linecount
            sector.linecount = c2da_postinc_1 + 1
        }
        if (li_1.backsector != null && li_1.frontsector != li_1.backsector) {
            sector = unsafe(reinterpret<sector_t?>(li_1.backsector))
            unsafe(sector.lines[sector.linecount]) = unsafe(reinterpret<line_s?>(li_1))
            let c2da_postinc_2 : int = sector.linecount
            sector.linecount = c2da_postinc_2 + 1
        }
        i_8++
    }
    sector = unsafe(reinterpret<sector_t?>(sectors))
    var c2da_sector_addr : uint64 = unsafe(reinterpret<uint64>(sector))
    i_8 = 0
    while (i_8 < numsectors) {
        M_ClearBox(unsafe(addr<int?>(bbox[0])))
        j_0 = 0
        while (j_0 < unsafe(reinterpret<sector_t?>(c2da_sector_addr)).linecount) {
            li_1 = unsafe(reinterpret<line_s?>(unsafe(unsafe(reinterpret<sector_t?>(c2da_sector_addr)).lines[j_0])))
            M_AddToBox(unsafe(addr<int?>(bbox[0])), li_1.v1.x, li_1.v1.y)
            M_AddToBox(unsafe(addr<int?>(bbox[0])), li_1.v2.x, li_1.v2.y)
            j_0++
        }
        unsafe(reinterpret<sector_t?>(c2da_sector_addr)).soundorg.x = (bbox[3] + bbox[2]) / 2
        unsafe(reinterpret<sector_t?>(c2da_sector_addr)).soundorg.y = (bbox[0] + bbox[1]) / 2
        block_0 = bbox[0] - bmaporgy + 32 * (1 << 16) >> 16 + 7
        var c2da_fresh38 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<sector_t?>(c2da_sector_addr)))) + 32ul))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh38))[0]) = block_0 >= bmapheight ? bmapheight - 1 : block_0
        block_0 = bbox[1] - bmaporgy - 32 * (1 << 16) >> 16 + 7
        var c2da_fresh39 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<sector_t?>(c2da_sector_addr)))) + 32ul))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh39))[1]) = block_0 < 0 ? 0 : block_0
        block_0 = bbox[3] - bmaporgx + 32 * (1 << 16) >> 16 + 7
        var c2da_fresh40 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<sector_t?>(c2da_sector_addr)))) + 32ul))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh40))[3]) = block_0 >= bmapwidth ? bmapwidth - 1 : block_0
        block_0 = bbox[2] - bmaporgx - 32 * (1 << 16) >> 16 + 7
        var c2da_fresh41 : int? = unsafe(reinterpret<int?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<sector_t?>(c2da_sector_addr)))) + 32ul))
        unsafe(unsafe(reinterpret<int?>(c2da_fresh41))[2]) = block_0 < 0 ? 0 : block_0
        i_8++
        c2da_sector_addr += 128ul
    }
    return
}
[sideeffects]
def private PadRejectArray(var array_0 : uint8?; var len : uint) {
    var i_9 : uint
    var dest : uint8?
    var padvalue : uint
    var rejectpad : uint[4] = fixed_array<uint>(uint((totallines * 4 + 3 & ~3) + 24), 0u, 50u, 0x1d4a11u)
    dest = unsafe(reinterpret<uint8?>(array_0))
    var c2da_dest_addr : uint64 = unsafe(reinterpret<uint64>(dest))
    i_9 = 0u
    while (i_9 < len && uint64(i_9) < 16ul) {
        *unsafe(reinterpret<uint8?>(c2da_dest_addr)) = uint8(rejectpad[int(i_9 / 4u)] >> i_9 % 4u * 8u & 0xffu)
        c2da_dest_addr++
        i_9++
    }
    if (uint64(len) > 16ul) {
        c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_p_setup_0[0])), [C2daVaArg(tag = 1, i64 = int64(len), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = 16l, f64 = 0.0lf, raw = 0x0)])
        if (M_CheckParm(unsafe(addr<int8?>(c2da_str_p_setup_1[0]))) != 0) {
            padvalue = 0xffu
        } else {
            padvalue = 0xf00u
        }
        var c2da_fresh42 : uint8? = unsafe(reinterpret<uint8?>(unsafe(array_0 + 16l)))
        unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(c2da_fresh42)), uint8(int(padvalue)), uint64(len) - 16ul)))
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
        rejectmatrix = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(W_CacheLumpNum(lumpnum, 5)))))
    } else {
        rejectmatrix = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(Z_Malloc(minlength, 5, unsafe(addr<uint8?>(rejectmatrix)))))))
        W_ReadLump(uint(lumpnum), unsafe(reinterpret<uint8?>(rejectmatrix)))
        PadRejectArray(unsafe(reinterpret<uint8?>(unsafe(rejectmatrix + lumplen_0))), uint(minlength - lumplen_0))
    }
    return
}
[export, sideeffects]
def P_SetupLevel(var episode : int; var map : int; var playermask : int; var skill : skill_t) {
    var i_10 : int
    var lumpname : int8[9]
    var lumpnum_0 : int
    wminfo.maxfrags = 0
    totalsecret = wminfo.maxfrags
    totalitems = totalsecret
    totalkills = totalitems
    wminfo.partime = 180
    i_10 = 0
    while (i_10 < 4) {
        players[i_10].itemcount = 0
        players[i_10].secretcount = players[i_10].itemcount
        players[i_10].killcount = players[i_10].secretcount
        i_10++
    }
    players[int(consoleplayer)].viewz = 1
    S_Start()
    Z_FreeTags(5, 7 - 1)
    P_InitThinkers()
    if (uint(gamemode) == 2u) {
        if (map < 10) {
            c2da_std_snprintf(unsafe(reinterpret<uint64>(unsafe(addr(lumpname[0])))), 9ul, unsafe(addr<int8 const?>(c2da_str_p_setup_2[0])), [C2daVaArg(tag = 1, i64 = int64(map), f64 = 0.0lf, raw = 0x0)])
        } else {
            c2da_std_snprintf(unsafe(reinterpret<uint64>(unsafe(addr(lumpname[0])))), 9ul, unsafe(addr<int8 const?>(c2da_str_p_setup_3[0])), [C2daVaArg(tag = 1, i64 = int64(map), f64 = 0.0lf, raw = 0x0)])
        }
    } else {
        lumpname[0] = int8(69)
        lumpname[1] = int8(48 + episode)
        lumpname[2] = int8(77)
        lumpname[3] = int8(48 + map)
        lumpname[4] = int8(0)
    }
    lumpnum_0 = W_GetNumForName(unsafe(addr<int8?>(lumpname[0])))
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
    deathmatch_p = unsafe(reinterpret<mapthing_t?>(unsafe(reinterpret<mapthing_t?>(deathmatchstarts[0].c2da_storage))))
    P_LoadThings(lumpnum_0 + 1)
    if (deathmatch != 0) {
        i_10 = 0
        for (c2da_i_10 in range(i_10, 4)) {
            if (playeringame[c2da_i_10] != 0x0) {
                players[c2da_i_10].mo = null
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
[export, sideeffects]
def P_Init() {
    P_InitSwitchList()
    P_InitPicAnims()
    R_InitSprites(unsafe(addr<int8??>(sprnames[0])))
    return
}
[sideeffects]
def private c2da_layout_proofs_22() {
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
    static_assert(typeinfo sizeof(type<subsector_t>) == 16, "C layout of subsector_t: sizeof")
    static_assert(typeinfo alignof(type<subsector_t>) == 8, "C layout of subsector_t: alignof")
    static_assert(typeinfo offsetof<sector>(type<subsector_t>) == 0, "C layout of subsector_t: offsetof sector")
    static_assert(typeinfo offsetof<numlines>(type<subsector_t>) == 8, "C layout of subsector_t: offsetof numlines")
    static_assert(typeinfo offsetof<firstline>(type<subsector_t>) == 10, "C layout of subsector_t: offsetof firstline")
    static_assert(typeinfo sizeof(type<seg_t>) == 56, "C layout of seg_t: sizeof")
    static_assert(typeinfo alignof(type<seg_t>) == 8, "C layout of seg_t: alignof")
    static_assert(typeinfo offsetof<v1>(type<seg_t>) == 0, "C layout of seg_t: offsetof v1")
    static_assert(typeinfo offsetof<v2>(type<seg_t>) == 8, "C layout of seg_t: offsetof v2")
    static_assert(typeinfo offsetof<offset>(type<seg_t>) == 16, "C layout of seg_t: offsetof offset")
    static_assert(typeinfo offsetof<angle>(type<seg_t>) == 20, "C layout of seg_t: offsetof angle")
    static_assert(typeinfo offsetof<sidedef>(type<seg_t>) == 24, "C layout of seg_t: offsetof sidedef")
    static_assert(typeinfo offsetof<linedef>(type<seg_t>) == 32, "C layout of seg_t: offsetof linedef")
    static_assert(typeinfo offsetof<frontsector>(type<seg_t>) == 40, "C layout of seg_t: offsetof frontsector")
    static_assert(typeinfo offsetof<backsector>(type<seg_t>) == 48, "C layout of seg_t: offsetof backsector")
    static_assert(typeinfo sizeof(type<node_t>) == 52, "C layout of node_t: sizeof")
    static_assert(typeinfo alignof(type<node_t>) == 4, "C layout of node_t: alignof")
    static_assert(typeinfo offsetof<x>(type<node_t>) == 0, "C layout of node_t: offsetof x")
    static_assert(typeinfo offsetof<y>(type<node_t>) == 4, "C layout of node_t: offsetof y")
    static_assert(typeinfo offsetof<dx>(type<node_t>) == 8, "C layout of node_t: offsetof dx")
    static_assert(typeinfo offsetof<dy>(type<node_t>) == 12, "C layout of node_t: offsetof dy")
    static_assert(typeinfo offsetof<bbox>(type<node_t>) == 16, "C layout of node_t: offsetof bbox")
    static_assert(typeinfo offsetof<children>(type<node_t>) == 48, "C layout of node_t: offsetof children")
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
    static_assert(typeinfo sizeof(type<wbplayerstruct_t>) == 40, "C layout of wbplayerstruct_t: sizeof")
    static_assert(typeinfo alignof(type<wbplayerstruct_t>) == 4, "C layout of wbplayerstruct_t: alignof")
    static_assert(typeinfo offsetof<in_0>(type<wbplayerstruct_t>) == 0, "C layout of wbplayerstruct_t: offsetof in_0")
    static_assert(typeinfo offsetof<skills>(type<wbplayerstruct_t>) == 4, "C layout of wbplayerstruct_t: offsetof skills")
    static_assert(typeinfo offsetof<sitems>(type<wbplayerstruct_t>) == 8, "C layout of wbplayerstruct_t: offsetof sitems")
    static_assert(typeinfo offsetof<ssecret>(type<wbplayerstruct_t>) == 12, "C layout of wbplayerstruct_t: offsetof ssecret")
    static_assert(typeinfo offsetof<stime>(type<wbplayerstruct_t>) == 16, "C layout of wbplayerstruct_t: offsetof stime")
    static_assert(typeinfo offsetof<frags>(type<wbplayerstruct_t>) == 20, "C layout of wbplayerstruct_t: offsetof frags")
    static_assert(typeinfo offsetof<score>(type<wbplayerstruct_t>) == 36, "C layout of wbplayerstruct_t: offsetof score")
    static_assert(typeinfo sizeof(type<wbstartstruct_t>) == 200, "C layout of wbstartstruct_t: sizeof")
    static_assert(typeinfo alignof(type<wbstartstruct_t>) == 4, "C layout of wbstartstruct_t: alignof")
    static_assert(typeinfo offsetof<epsd>(type<wbstartstruct_t>) == 0, "C layout of wbstartstruct_t: offsetof epsd")
    static_assert(typeinfo offsetof<didsecret>(type<wbstartstruct_t>) == 4, "C layout of wbstartstruct_t: offsetof didsecret")
    static_assert(typeinfo offsetof<last>(type<wbstartstruct_t>) == 8, "C layout of wbstartstruct_t: offsetof last")
    static_assert(typeinfo offsetof<next>(type<wbstartstruct_t>) == 12, "C layout of wbstartstruct_t: offsetof next")
    static_assert(typeinfo offsetof<maxkills>(type<wbstartstruct_t>) == 16, "C layout of wbstartstruct_t: offsetof maxkills")
    static_assert(typeinfo offsetof<maxitems>(type<wbstartstruct_t>) == 20, "C layout of wbstartstruct_t: offsetof maxitems")
    static_assert(typeinfo offsetof<maxsecret>(type<wbstartstruct_t>) == 24, "C layout of wbstartstruct_t: offsetof maxsecret")
    static_assert(typeinfo offsetof<maxfrags>(type<wbstartstruct_t>) == 28, "C layout of wbstartstruct_t: offsetof maxfrags")
    static_assert(typeinfo offsetof<partime>(type<wbstartstruct_t>) == 32, "C layout of wbstartstruct_t: offsetof partime")
    static_assert(typeinfo offsetof<pnum>(type<wbstartstruct_t>) == 36, "C layout of wbstartstruct_t: offsetof pnum")
    static_assert(typeinfo offsetof<plyr>(type<wbstartstruct_t>) == 40, "C layout of wbstartstruct_t: offsetof plyr")
}
