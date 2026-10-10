var private wipe_scr_end : uint8? = default<uint8?>

var private wipe_scr_start : uint8? = default<uint8?>

var private y_2 : int? = default<int?>

var private wipe_scr : uint8? = default<uint8?>

var private wipe_ScreenWipe__wipes : function<(var _arg0:int;var _arg1:int;var _arg2:int):int>[6] = fixed_array<function<(var _arg0:int;var _arg1:int;var _arg2:int):int>>(@@wipe_initColorXForm, @@wipe_doColorXForm, @@wipe_exitColorXForm, @@wipe_initMelt, @@wipe_doMelt, @@wipe_exitMelt)

[export, sideeffects]
def wipe_StartScreen(var x : int; var y : int; var width : int; var height : int) : int {
    wipe_scr_start = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(Z_Malloc(320 * 200, 1, null)))))
    I_ReadScreen(wipe_scr_start)
    return 0
}
[export, sideeffects]
def wipe_EndScreen(var x_0 : int; var y_0 : int; var width_0 : int; var height_0 : int) : int {
    wipe_scr_end = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(Z_Malloc(320 * 200, 1, null)))))
    I_ReadScreen(wipe_scr_end)
    V_DrawBlock(x_0, y_0, width_0, height_0, wipe_scr_start)
    return 0
}
[export, sideeffects]
def wipe_ScreenWipe(var wipeno : int; var x_1 : int; var y_1 : int; var width_1 : int; var height_1 : int; var ticks : int) : int {
    var rc : int
    if (go == 0) {
        go = 1u
        wipe_scr = unsafe(reinterpret<uint8?>(I_VideoBuffer))
        invoke(wipe_ScreenWipe__wipes[wipeno * 3], width_1, height_1, ticks)
    }
    V_MarkRect(0, 0, width_1, height_1)
    rc = invoke(wipe_ScreenWipe__wipes[wipeno * 3 + 1], width_1, height_1, ticks)
    if (rc != 0) {
        go = 0u
        invoke(wipe_ScreenWipe__wipes[wipeno * 3 + 2], width_1, height_1, ticks)
    }
    return go == 0 ? 1 : 0
}
var private go : uint = 0u

[export, sideeffects]
def wipe_exitMelt(var width_2 : int; var height_2 : int; var ticks_0 : int) : int {
    Z_Free(unsafe(reinterpret<uint8?>(y_2)))
    Z_Free(unsafe(reinterpret<uint8?>(wipe_scr_start)))
    Z_Free(unsafe(reinterpret<uint8?>(wipe_scr_end)))
    return 0
}
[export, sideeffects]
def wipe_doMelt(var width_3 : int; var height_3 : int; var ticks_1 : int) : int {
    var j : int
    var dy : int
    var idx : int
    var s : int16?
    var d : int16?
    var done : uint = 1u
    width_3 /= 2
    while (true) {
        let c2da_postinc : int = ticks_1
        ticks_1--
        if (c2da_postinc == 0) {
            break
        }
        for (i in range(0, width_3)) {
            if (unsafe(y_2[i]) < 0) {
                unsafe(y_2[i])++
                done = 0u
            } elif (unsafe(y_2[i]) < height_3) {
                dy = unsafe(y_2[i]) < 16 ? unsafe(y_2[i]) + 1 : 8
                if (unsafe(y_2[i]) + dy >= height_3) {
                    dy = height_3 - unsafe(y_2[i])
                }
                s = unsafe(addr<int16?>(unsafe(unsafe(reinterpret<int16?>(wipe_scr_end))[i * height_3 + unsafe(y_2[i])])))
                d = unsafe(addr<int16?>(unsafe(unsafe(reinterpret<int16?>(wipe_scr))[unsafe(y_2[i]) * width_3 + i])))
                idx = 0
                var c2da_s_addr : uint64 = unsafe(reinterpret<uint64>(s))
                j = dy
                while (j != 0) {
                    unsafe(d[idx]) = int16(*unsafe(reinterpret<int16?>(c2da_s_addr)))  // nolint:PERF020
                    c2da_s_addr += 2ul
                    idx += width_3
                    j--
                }
                unsafe(y_2[i]) += dy
                s = unsafe(addr<int16?>(unsafe(unsafe(reinterpret<int16?>(wipe_scr_start))[i * height_3])))
                d = unsafe(addr<int16?>(unsafe(unsafe(reinterpret<int16?>(wipe_scr))[unsafe(y_2[i]) * width_3 + i])))
                idx = 0
                var c2da_s_addr_0 : uint64 = unsafe(reinterpret<uint64>(s))
                j = height_3 - unsafe(y_2[i])
                while (j != 0) {
                    unsafe(d[idx]) = int16(*unsafe(reinterpret<int16?>(c2da_s_addr_0)))  // nolint:PERF020
                    c2da_s_addr_0 += 2ul
                    idx += width_3
                    j--
                }
                s = unsafe(reinterpret<int16?>(c2da_s_addr_0))
                done = 0u
            }
        }
    }
    return int(done)
}
[export, sideeffects]
def wipe_initMelt(var width_4 : int; var height_4 : int; var ticks_2 : int) : int {
    var r : int
    let c2da_fresh0 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(wipe_scr))))
    let c2da_fresh1 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(wipe_scr_start))))
    let c2da_fresh2 : uint64 = uint64(width_4 * height_4)
    if (c2da_fresh2 != 0x0) {
        unsafe(memcpy(unsafe(reinterpret<void?>(c2da_fresh0)), unsafe(reinterpret<void?>(c2da_fresh1)), c2da_fresh2))
    }
    wipe_shittyColMajorXform(unsafe(reinterpret<int16?>(wipe_scr_start)), width_4 / 2, height_4)
    wipe_shittyColMajorXform(unsafe(reinterpret<int16?>(wipe_scr_end)), width_4 / 2, height_4)
    y_2 = unsafe(reinterpret<int?>(unsafe(reinterpret<int?>(unsafe(reinterpret<int?>(Z_Malloc(int(uint64(width_4) * 4ul), 1, null)))))))
    unsafe(y_2[0]) = -(M_Random() % 16)
    for (i_0 in range(1, width_4)) {
        r = M_Random() % 3 - 1
        unsafe(y_2[i_0]) = unsafe(y_2[i_0 - 1]) + r
        if (unsafe(y_2[i_0]) > 0) {
            unsafe(y_2[i_0]) = 0
        } elif (unsafe(y_2[i_0]) == -16) {
            unsafe(y_2[i_0]) = -15
        }
    }
    return 0
}
[export, sideeffects]
def wipe_shittyColMajorXform(var array_0 : int16?; var width_5 : int; var height_5 : int) {
    var dest : int16? = unsafe(reinterpret<int16?>(unsafe(reinterpret<int16?>(unsafe(reinterpret<int16?>(Z_Malloc(width_5 * height_5 * 2, 1, null)))))))
    for (y_3 in range(0, height_5)) {
        for (x_2 in range(0, width_5)) {
            unsafe(dest[x_2 * height_5 + y_3]) = int16(unsafe(array_0[y_3 * width_5 + x_2]))  // nolint:PERF020
        }
    }
    let c2da_fresh3 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(array_0))))
    let c2da_fresh4 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(dest))))
    let c2da_fresh5 : uint64 = uint64(width_5 * height_5 * 2)
    if (c2da_fresh5 != 0x0) {
        unsafe(memcpy(unsafe(reinterpret<void?>(c2da_fresh3)), unsafe(reinterpret<void?>(c2da_fresh4)), c2da_fresh5))
    }
    Z_Free(unsafe(reinterpret<uint8?>(dest)))
    return
}
[export, sideeffects]
def wipe_exitColorXForm(var width_6 : int; var height_6 : int; var ticks_3 : int) : int {
    return 0
}
[export, sideeffects]
def wipe_doColorXForm(var width_7 : int; var height_7 : int; var ticks_4 : int) : int {
    var changed : uint
    var w : uint8?
    var e : uint8?
    var newval : int
    changed = 0u
    w = unsafe(reinterpret<uint8?>(wipe_scr))
    e = unsafe(reinterpret<uint8?>(wipe_scr_end))
    var c2da_e_addr : uint64 = unsafe(reinterpret<uint64>(e))
    while (w != unsafe(wipe_scr + int64(width_7 * height_7))) {
        if (int(*w) != int(*unsafe(reinterpret<uint8?>(c2da_e_addr)))) {
            if (int(*w) > int(*unsafe(reinterpret<uint8?>(c2da_e_addr)))) {
                newval = int(*w) - ticks_4
                if (newval < int(*unsafe(reinterpret<uint8?>(c2da_e_addr)))) {
                    *w = uint8(*unsafe(reinterpret<uint8?>(c2da_e_addr)))  // nolint:PERF020
                } else {
                    *w = uint8(newval)
                }
                changed = 1u
            } elif (int(*w) < int(*unsafe(reinterpret<uint8?>(c2da_e_addr)))) {
                newval = int(*w) + ticks_4
                if (newval > int(*unsafe(reinterpret<uint8?>(c2da_e_addr)))) {
                    *w = uint8(*unsafe(reinterpret<uint8?>(c2da_e_addr)))  // nolint:PERF020
                } else {
                    *w = uint8(newval)
                }
                changed = 1u
            }
        }
        unsafe {  // nolint:STYLE025
            w += 1
        }
        c2da_e_addr++
    }
    return changed == 0 ? 1 : 0
}
[export, sideeffects]
def wipe_initColorXForm(var width_8 : int; var height_8 : int; var ticks_5 : int) : int {
    let c2da_fresh6 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(wipe_scr))))
    let c2da_fresh7 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(wipe_scr_start))))
    let c2da_fresh8 : uint64 = uint64(width_8 * height_8)
    if (c2da_fresh8 != 0x0) {
        unsafe(memcpy(unsafe(reinterpret<void?>(c2da_fresh6)), unsafe(reinterpret<void?>(c2da_fresh7)), c2da_fresh8))
    }
    return 0
}
