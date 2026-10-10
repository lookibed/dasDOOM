var private c2da_str_r_main_0 : array<int8> = [int8(46), int8(0)]

[sideeffects]
def private c2da___bswap_16_12(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_12(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_12(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_12(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_12(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_12(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
var viewx : int = default<int>

var viewy : int = default<int>

var viewz : int = default<int>

var viewangle : uint = default<uint>

var viewplayer : player_s? = default<player_s?>

var clipangle : uint = default<uint>

var viewangletox : int[4096]

var xtoviewangle : uint[321]

var sscount : int = default<int>

var viewcos : int = default<int>

var viewsin : int = default<int>

var centerx : int = default<int>

var centery : int = default<int>

var centerxfrac : int = default<int>

var centeryfrac : int = default<int>

var projection : int = default<int>

var validcount : int = 1

var linecount : int = default<int>

var loopcount : int = default<int>

var scalelight : uint8? [16][48]

var scalelightfixed : uint8? [48]

var zlight : uint8? [16][128]

var extralight : int = default<int>

var fixedcolormap : uint8? = default<uint8?>

var detailshift : int = default<int>

var colfunc : function<():void> = default<function<():void>>

var transcolfunc : function<():void> = default<function<():void>>

var basecolfunc : function<():void> = default<function<():void>>

var fuzzcolfunc : function<():void> = default<function<():void>>

var spanfunc : function<():void> = default<function<():void>>

[export, sideeffects]
def R_PointOnSide(var x : int; var y : int; var node : node_t?) : int {
    var dx : int
    var dy : int
    var left : int
    var right : int
    if (node.dx == 0) {
        if (x <= node.x) {
            return node.dy > 0 ? 1 : 0
        }
        return node.dy < 0 ? 1 : 0
    }
    if (node.dy == 0) {
        if (y <= node.y) {
            return node.dx < 0 ? 1 : 0
        }
        return node.dx > 0 ? 1 : 0
    }
    dx = x - node.x
    dy = y - node.y
    if ((uint(node.dy ^ node.dx ^ dx ^ dy) & 0x80000000u) != 0x0) {
        if ((uint(node.dy ^ dx) & 0x80000000u) != 0x0) {
            return 1
        }
        return 0
    }
    left = FixedMul(node.dy >> 16, dx)
    right = FixedMul(dy, node.dx >> 16)
    if (right < left) {
        return 0
    }
    return 1
}
[export, sideeffects]
def R_PointOnSegSide(var x_0 : int; var y_0 : int; var line : seg_t?) : int {
    var lx : int
    var ly : int
    var ldx : int
    var ldy : int
    var dx_0 : int
    var dy_0 : int
    var left_0 : int
    var right_0 : int
    lx = line.v1.x
    ly = line.v1.y
    ldx = line.v2.x - lx
    ldy = line.v2.y - ly
    if (ldx == 0) {
        if (x_0 <= lx) {
            return ldy > 0 ? 1 : 0
        }
        return ldy < 0 ? 1 : 0
    }
    if (ldy == 0) {
        if (y_0 <= ly) {
            return ldx < 0 ? 1 : 0
        }
        return ldx > 0 ? 1 : 0
    }
    dx_0 = x_0 - lx
    dy_0 = y_0 - ly
    if ((uint(ldy ^ ldx ^ dx_0 ^ dy_0) & 0x80000000u) != 0x0) {
        if ((uint(ldy ^ dx_0) & 0x80000000u) != 0x0) {
            return 1
        }
        return 0
    }
    left_0 = FixedMul(ldy >> 16, dx_0)
    right_0 = FixedMul(dy_0, ldx >> 16)
    if (right_0 < left_0) {
        return 0
    }
    return 1
}
[export, sideeffects]
def R_PointToAngle(var x_1 : int; var y_1 : int) : uint {
    x_1 -= viewx
    y_1 -= viewy
    if (x_1 == 0 && y_1 == 0) {
        return 0u
    }
    if (x_1 >= 0) {
        if (y_1 >= 0) {
            if (x_1 > y_1) {
                return tantoangle[int(SlopeDiv(uint(y_1), uint(x_1)))]
            } else {
                return uint(1073741824 - 1) - tantoangle[int(SlopeDiv(uint(x_1), uint(y_1)))]
            }
        } else {
            y_1 = -y_1
            if (x_1 > y_1) {
                return -tantoangle[int(SlopeDiv(uint(y_1), uint(x_1)))]
            } else {
                return 0xc0000000u + tantoangle[int(SlopeDiv(uint(x_1), uint(y_1)))]
            }
        }
    } else {
        x_1 = -x_1
        if (y_1 >= 0) {
            if (x_1 > y_1) {
                return 0x80000000u - 1u - tantoangle[int(SlopeDiv(uint(y_1), uint(x_1)))]
            } else {
                return 0x40000000u + tantoangle[int(SlopeDiv(uint(x_1), uint(y_1)))]
            }
        } else {
            y_1 = -y_1
            if (x_1 > y_1) {
                return 0x80000000u + tantoangle[int(SlopeDiv(uint(y_1), uint(x_1)))]
            } else {
                return 0xc0000000u - 1u - tantoangle[int(SlopeDiv(uint(x_1), uint(y_1)))]
            }
        }
    }
}
[export, sideeffects]
def R_PointToAngle2(var x1 : int; var y1 : int; var x2 : int; var y2 : int) : uint {
    viewx = int(x1)  // nolint:PERF020
    viewy = int(y1)  // nolint:PERF020
    return R_PointToAngle(x2, y2)
}
[export, sideeffects]
def R_PointToDist(var x_2 : int; var y_3 : int) : int {
    var angle : int
    var dx_1 : int
    var dy_1 : int
    var temp : int
    var dist : int
    var frac : int
    dx_1 = c2da_std_abs(x_2 - viewx)
    dy_1 = c2da_std_abs(y_3 - viewy)
    if (dy_1 > dx_1) {
        temp = dx_1
        dx_1 = dy_1
        dy_1 = temp
    }
    if (dx_1 != 0) {
        frac = FixedDiv(dy_1, dx_1)
    } else {
        frac = 0
    }
    angle = int(tantoangle[frac >> 16 - 11] + 0x40000000u >> 19u)
    dist = FixedDiv(dx_1, finesine[angle])
    return dist
}
[export, sideeffects]
def R_ScaleFromGlobalAngle(var visangle : uint) : int {
    var scale : int
    var sinea : int
    var sineb : int
    var num : int
    var den : int
    sinea = finesine[int(0x40000000u + (visangle - viewangle) >> 19u)]
    sineb = finesine[int(uint(0x40000000u + (visangle - rw_normalangle)) >> 19u)]
    num = FixedMul(projection, sineb) << detailshift
    den = FixedMul(rw_distance, sinea)
    if (den > num >> 16) {
        scale = FixedDiv(num, den)
        if (scale > 64 * (1 << 16)) {
            scale = 64 * (1 << 16)
        } elif (scale < 256) {
            scale = 256
        }
    } else {
        scale = 64 * (1 << 16)
    }
    return scale
}
[export, sideeffects]
def R_PointInSubsector(var x_3 : int; var y_4 : int) : subsector_s? {
    var node_0 : node_t?
    var side : int
    var nodenum : int
    if (numnodes == 0) {
        return unsafe(reinterpret<subsector_s?>(subsectors))
    }
    nodenum = numnodes - 1
    while ((nodenum & 32768) == 0) {
        node_0 = unsafe(addr<node_t?>(unsafe(nodes[nodenum])))
        side = R_PointOnSide(x_3, y_4, node_0)
        var c2da_fresh0 : uint16? = unsafe(reinterpret<uint16?>(unsafe(reinterpret<uint64>(node_0)) + 48ul))
        nodenum = int(unsafe(unsafe(reinterpret<uint16?>(c2da_fresh0))[side]))
    }
    return unsafe(addr<subsector_s?>(unsafe(subsectors[nodenum & ~32768])))
}
[export, sideeffects]
def R_AddPointToBox(var x_4 : int; var y_5 : int; var box : int?) {
    if (x_4 < unsafe(box[2])) {
        unsafe(box[2]) = int(x_4)  // nolint:PERF020
    }
    if (x_4 > unsafe(box[3])) {
        unsafe(box[3]) = int(x_4)  // nolint:PERF020
    }
    if (y_5 < unsafe(box[1])) {
        unsafe(box[1]) = int(y_5)  // nolint:PERF020
    }
    if (y_5 > unsafe(box[0])) {
        unsafe(box[0]) = int(y_5)  // nolint:PERF020
    }
    return
}
[export, sideeffects]
def R_RenderPlayerView(var player : player_s?) {
    R_SetupFrame(player)
    R_ClearClipSegs()
    R_ClearDrawSegs()
    R_ClearPlanes()
    R_ClearSprites()
    NetUpdate()
    R_RenderBSPNode(numnodes - 1)
    NetUpdate()
    R_DrawPlanes()
    NetUpdate()
    R_DrawMasked()
    NetUpdate()
    return
}
[export, sideeffects]
def R_SetupFrame(var player_0 : player_s?) {
    viewplayer = unsafe(reinterpret<player_s?>(player_0))
    viewx = int(player_0.mo.x)  // nolint:PERF020
    viewy = int(player_0.mo.y)  // nolint:PERF020
    viewangle = player_0.mo.angle + uint(viewangleoffset)
    extralight = int(player_0.extralight)  // nolint:PERF020
    viewz = int(player_0.viewz)  // nolint:PERF020
    viewsin = finesine[int(viewangle >> 19u)]
    viewcos = unsafe(finecosine[int(viewangle >> 19u)])
    sscount = 0
    if (player_0.fixedcolormap != 0) {
        fixedcolormap = unsafe(reinterpret<uint8?>(unsafe(colormaps + int64(uint64(player_0.fixedcolormap * 256) * 1ul))))
        walllights = unsafe(addr<uint8??>(scalelightfixed[0]))
        for (i in range(0, 48)) {
            scalelightfixed[i] = unsafe(reinterpret<uint8?>(fixedcolormap))
        }
    } else {
        fixedcolormap = null
    }
    framecount++
    validcount++
    return
}
var framecount : int = default<int>

var viewangleoffset : int = default<int>

[export, sideeffects]
def R_Init() {
    R_InitData()
    c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_r_main_0[0])), [])
    R_InitPointToAngle()
    c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_r_main_0[0])), [])
    R_InitTables()
    c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_r_main_0[0])), [])
    R_SetViewSize(screenblocks, detailLevel)
    R_InitPlanes()
    c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_r_main_0[0])), [])
    R_InitLightTables()
    c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_r_main_0[0])), [])
    R_InitSkyMap()
    R_InitTranslationTables()
    c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_r_main_0[0])), [])
    framecount = 0
    return
}
[export, sideeffects]
def R_InitLightTables() {
    var level : int
    var startmap_0 : int
    var scale_0 : int
    for (i_0 in range(0, 16)) {
        startmap_0 = (16 - 1 - i_0) * 2 * 32 / 16
        for (j in range(0, 128)) {
            scale_0 = FixedDiv(320 / 2 * (1 << 16), j + 1 << 20)
            scale_0 >>= 12
            level = startmap_0 - scale_0 / 2
            if (level < 0) {
                level = 0
            }
            if (level >= 32) {
                level = 32 - 1
            }
            zlight[i_0][j] = unsafe(reinterpret<uint8?>(unsafe(colormaps + int64(level * 256))))
        }
    }
    return
}
[export, sideeffects]
def R_SetViewSize(var blocks : int; var detail : int) {
    setsizeneeded = 1u
    setblocks = int(blocks)  // nolint:PERF020
    setdetail = int(detail)  // nolint:PERF020
    return
}
var setdetail : int = default<int>

var setblocks : int = default<int>

var setsizeneeded : uint = default<uint>

[export, sideeffects]
def R_InitTables() {
    return
}
[export, sideeffects]
def R_InitPointToAngle() {
    return
}
[export, sideeffects]
def R_InitTextureMapping() {
    var i_1 : int
    var x_5 : int
    var t : int
    var focallength : int = FixedDiv(centerxfrac, finetangent[8192 / 4 + 2048 / 2])
    i_1 = 0
    while (i_1 < 8192 / 2) {
        if (finetangent[i_1] > (1 << 16) * 2) {
            t = -1
        } elif (finetangent[i_1] < -(1 << 16) * 2) {
            t = viewwidth + 1
        } else {
            t = FixedMul(finetangent[i_1], focallength)
            t = centerxfrac - t + (1 << 16) - 1 >> 16
            if (t < -1) {
                t = -1
            } elif (t > viewwidth + 1) {
                t = viewwidth + 1
            }
        }
        viewangletox[i_1] = t
        i_1++
    }
    x_5 = 0
    while (x_5 <= viewwidth) {
        i_1 = 0
        while (viewangletox[i_1] > x_5) {
            i_1++
        }
        xtoviewangle[x_5] = uint((i_1 << 19) - 1073741824)
        x_5++
    }
    i_1 = 0
    for (c2da_i_1 in range(i_1, 8192 / 2)) {
        t = FixedMul(finetangent[c2da_i_1], focallength)
        t = centerx - t
        if (viewangletox[c2da_i_1] == -1) {
            viewangletox[c2da_i_1] = 0
        } elif (viewangletox[c2da_i_1] == viewwidth + 1) {
            viewangletox[c2da_i_1] = viewwidth
        }
    }
    clipangle = uint(xtoviewangle[0])  // nolint:PERF020
    return
}
[export, sideeffects]
def R_ExecuteSetViewSize() {
    var cosadj : int
    var dy_2 : int
    var i_2 : int
    var level_0 : int
    var startmap_1 : int
    setsizeneeded = 0u
    if (setblocks == 11) {
        scaledviewwidth = 320
        viewheight = 200
    } else {
        scaledviewwidth = setblocks * 32
        viewheight = setblocks * 168 / 10 & ~7
    }
    detailshift = int(setdetail)  // nolint:PERF020
    viewwidth = scaledviewwidth >> detailshift
    centery = viewheight / 2
    centerx = viewwidth / 2
    centerxfrac = centerx << 16
    centeryfrac = centery << 16
    projection = int(centerxfrac)  // nolint:PERF020
    if (detailshift == 0) {
        basecolfunc = @@R_DrawColumn
        colfunc = basecolfunc
        fuzzcolfunc = @@R_DrawFuzzColumn
        transcolfunc = @@R_DrawTranslatedColumn
        spanfunc = @@R_DrawSpan
    } else {
        basecolfunc = @@R_DrawColumnLow
        colfunc = basecolfunc
        fuzzcolfunc = @@R_DrawFuzzColumnLow
        transcolfunc = @@R_DrawTranslatedColumnLow
        spanfunc = @@R_DrawSpanLow
    }
    R_InitBuffer(scaledviewwidth, viewheight)
    R_InitTextureMapping()
    pspritescale = (1 << 16) * viewwidth / 320
    pspriteiscale = (1 << 16) * 320 / viewwidth
    i_2 = 0
    while (i_2 < viewwidth) {
        screenheightarray[i_2] = int16(viewheight)
        i_2++
    }
    i_2 = 0
    while (i_2 < viewheight) {
        dy_2 = (i_2 - viewheight / 2 << 16) + (1 << 16) / 2
        dy_2 = c2da_std_abs(dy_2)
        yslope[i_2] = FixedDiv((viewwidth << detailshift) / 2 * (1 << 16), dy_2)
        i_2++
    }
    i_2 = 0
    while (i_2 < viewwidth) {
        cosadj = c2da_std_abs(unsafe(finecosine[int(xtoviewangle[i_2] >> 19u)]))
        distscale[i_2] = FixedDiv(1 << 16, cosadj)
        i_2++
    }
    i_2 = 0
    for (c2da_i_2 in range(i_2, 16)) {
        startmap_1 = (16 - 1 - c2da_i_2) * 2 * 32 / 16
        for (j_0 in range(0, 48)) {
            level_0 = startmap_1 - j_0 * 320 / (viewwidth << detailshift) / 2
            if (level_0 < 0) {
                level_0 = 0
            }
            if (level_0 >= 32) {
                level_0 = 32 - 1
            }
            scalelight[c2da_i_2][j_0] = unsafe(reinterpret<uint8?>(unsafe(colormaps + int64(level_0 * 256))))
        }
    }
    return
}
[sideeffects]
def private c2da_layout_proofs_31() {
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
}
