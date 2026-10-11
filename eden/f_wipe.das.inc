var private wipe_ScreenWipe__wipes : int[6] = fixed_array<int>(9, 10, 11, 12, 13, 14)

[export, sideeffects]
def wipe_StartScreen(var x : int; var y : int; var width : int; var height : int) : int {
    wipe_scr_start = Z_Malloc(320 * 200, 1, 0)
    I_ReadScreen(wipe_scr_start)
    return 0
}
var private wipe_scr_start : int = default<int>

[export, sideeffects]
def wipe_EndScreen(var x_0 : int; var y_0 : int; var width_0 : int; var height_0 : int) : int {
    wipe_scr_end = Z_Malloc(320 * 200, 1, 0)
    I_ReadScreen(wipe_scr_end)
    V_DrawBlock(x_0, y_0, width_0, height_0, wipe_scr_start)
    return 0
}
var private wipe_scr_end : int = default<int>

[export, sideeffects]
def wipe_ScreenWipe(var wipeno : int; var x_1 : int; var y_1 : int; var width_1 : int; var height_1 : int; var ticks : int) : int {
    var rc : int
    if (go == 0) {
        go = 1u
        wipe_scr = I_VideoBuffer
        invoke(c2da_fn_table3[wipe_ScreenWipe__wipes[wipeno * 3]], width_1, height_1, ticks)
    }
    V_MarkRect(0, 0, width_1, height_1)
    rc = invoke(c2da_fn_table3[wipe_ScreenWipe__wipes[wipeno * 3 + 1]], width_1, height_1, ticks)
    if (rc != 0) {
        go = 0u
        invoke(c2da_fn_table3[wipe_ScreenWipe__wipes[wipeno * 3 + 2]], width_1, height_1, ticks)
    }
    return go == 0 ? 1 : 0
}
var private go : uint = 0u

[export, sideeffects]
def wipe_exitMelt(var width_2 : int; var height_2 : int; var ticks_0 : int) : int {
    Z_Free(y_2)
    Z_Free(wipe_scr_start)
    Z_Free(wipe_scr_end)
    return 0
}
var private y_2 : int = default<int>

[export, sideeffects]
def wipe_doMelt(var width_3 : int; var height_3 : int; var ticks_1 : int) : int {
    var j : int
    var dy : int
    var idx : int
    var s : int
    var d : int
    var done : uint = 1u
    width_3 /= 2
    while (true) {
        let c2da_postinc : int = ticks_1
        ticks_1--
        if (c2da_postinc == 0) {
            break
        }
        for (i in range(0, width_3)) {
            if (int(uint(c2da_mem[y_2 + i * 4]) | uint(c2da_mem[y_2 + i * 4 + 1]) << 0x8 | uint(c2da_mem[y_2 + i * 4 + 2]) << 0x10 | uint(c2da_mem[y_2 + i * 4 + 3]) << 0x18) < 0) {
                let c2da_fresh0 : int = int(uint(c2da_mem[y_2 + i * 4]) | uint(c2da_mem[y_2 + i * 4 + 1]) << 0x8 | uint(c2da_mem[y_2 + i * 4 + 2]) << 0x10 | uint(c2da_mem[y_2 + i * 4 + 3]) << 0x18)
                let c2da_fresh1 : int = c2da_fresh0 + 1
                let c2da_fresh2 : uint = uint(c2da_fresh1)
                c2da_mem[y_2 + i * 4] = uint8(c2da_fresh2)
                c2da_mem[y_2 + i * 4 + 1] = uint8(c2da_fresh2 >> 0x8)
                c2da_mem[y_2 + i * 4 + 2] = uint8(c2da_fresh2 >> 0x10)
                c2da_mem[y_2 + i * 4 + 3] = uint8(c2da_fresh2 >> 0x18)
                done = 0u
            } elif (int(uint(c2da_mem[y_2 + i * 4]) | uint(c2da_mem[y_2 + i * 4 + 1]) << 0x8 | uint(c2da_mem[y_2 + i * 4 + 2]) << 0x10 | uint(c2da_mem[y_2 + i * 4 + 3]) << 0x18) < height_3) {
                dy = int(uint(c2da_mem[y_2 + i * 4]) | uint(c2da_mem[y_2 + i * 4 + 1]) << 0x8 | uint(c2da_mem[y_2 + i * 4 + 2]) << 0x10 | uint(c2da_mem[y_2 + i * 4 + 3]) << 0x18) < 16 ? int(uint(c2da_mem[y_2 + i * 4]) | uint(c2da_mem[y_2 + i * 4 + 1]) << 0x8 | uint(c2da_mem[y_2 + i * 4 + 2]) << 0x10 | uint(c2da_mem[y_2 + i * 4 + 3]) << 0x18) + 1 : 8
                if (int(uint(c2da_mem[y_2 + i * 4]) | uint(c2da_mem[y_2 + i * 4 + 1]) << 0x8 | uint(c2da_mem[y_2 + i * 4 + 2]) << 0x10 | uint(c2da_mem[y_2 + i * 4 + 3]) << 0x18) + dy >= height_3) {
                    dy = height_3 - int(uint(c2da_mem[y_2 + i * 4]) | uint(c2da_mem[y_2 + i * 4 + 1]) << 0x8 | uint(c2da_mem[y_2 + i * 4 + 2]) << 0x10 | uint(c2da_mem[y_2 + i * 4 + 3]) << 0x18)
                }
                s = wipe_scr_end + (i * height_3 + int(uint(c2da_mem[y_2 + i * 4]) | uint(c2da_mem[y_2 + i * 4 + 1]) << 0x8 | uint(c2da_mem[y_2 + i * 4 + 2]) << 0x10 | uint(c2da_mem[y_2 + i * 4 + 3]) << 0x18)) * 2
                d = wipe_scr + (int(uint(c2da_mem[y_2 + i * 4]) | uint(c2da_mem[y_2 + i * 4 + 1]) << 0x8 | uint(c2da_mem[y_2 + i * 4 + 2]) << 0x10 | uint(c2da_mem[y_2 + i * 4 + 3]) << 0x18) * width_3 + i) * 2
                idx = 0
                j = dy
                while (j != 0) {
                    let c2da_fresh3 : int = s
                    s += 2
                    let c2da_fresh4 : int16 = int16(uint(c2da_mem[c2da_fresh3]) | uint(c2da_mem[c2da_fresh3 + 1]) << 0x8)
                    let c2da_fresh5 : uint = uint(c2da_fresh4)
                    c2da_mem[d + idx * 2] = uint8(c2da_fresh5)
                    c2da_mem[d + idx * 2 + 1] = uint8(c2da_fresh5 >> 0x8)
                    idx += width_3
                    j--
                }
                let c2da_fresh6 : int = int(uint(c2da_mem[y_2 + i * 4]) | uint(c2da_mem[y_2 + i * 4 + 1]) << 0x8 | uint(c2da_mem[y_2 + i * 4 + 2]) << 0x10 | uint(c2da_mem[y_2 + i * 4 + 3]) << 0x18) + dy
                let c2da_fresh7 : uint = uint(c2da_fresh6)
                c2da_mem[y_2 + i * 4] = uint8(c2da_fresh7)
                c2da_mem[y_2 + i * 4 + 1] = uint8(c2da_fresh7 >> 0x8)
                c2da_mem[y_2 + i * 4 + 2] = uint8(c2da_fresh7 >> 0x10)
                c2da_mem[y_2 + i * 4 + 3] = uint8(c2da_fresh7 >> 0x18)
                s = wipe_scr_start + i * height_3 * 2
                d = wipe_scr + (int(uint(c2da_mem[y_2 + i * 4]) | uint(c2da_mem[y_2 + i * 4 + 1]) << 0x8 | uint(c2da_mem[y_2 + i * 4 + 2]) << 0x10 | uint(c2da_mem[y_2 + i * 4 + 3]) << 0x18) * width_3 + i) * 2
                idx = 0
                j = height_3 - int(uint(c2da_mem[y_2 + i * 4]) | uint(c2da_mem[y_2 + i * 4 + 1]) << 0x8 | uint(c2da_mem[y_2 + i * 4 + 2]) << 0x10 | uint(c2da_mem[y_2 + i * 4 + 3]) << 0x18)
                while (j != 0) {
                    let c2da_fresh8 : int = s
                    s += 2
                    let c2da_fresh9 : int16 = int16(uint(c2da_mem[c2da_fresh8]) | uint(c2da_mem[c2da_fresh8 + 1]) << 0x8)
                    let c2da_fresh10 : uint = uint(c2da_fresh9)
                    c2da_mem[d + idx * 2] = uint8(c2da_fresh10)
                    c2da_mem[d + idx * 2 + 1] = uint8(c2da_fresh10 >> 0x8)
                    idx += width_3
                    j--
                }
                done = 0u
            }
        }
    }
    return int(done)
}
var private wipe_scr : int = default<int>

[export, sideeffects]
def wipe_initMelt(var width_4 : int; var height_4 : int; var ticks_2 : int) : int {
    var r : int
    c2da_lin_memcpy(wipe_scr, wipe_scr_start, uint64(width_4 * height_4))
    wipe_shittyColMajorXform(wipe_scr_start, width_4 / 2, height_4)
    wipe_shittyColMajorXform(wipe_scr_end, width_4 / 2, height_4)
    y_2 = Z_Malloc(int(uint64(width_4) * 4ul), 1, 0)
    let c2da_fresh11 : int = -(M_Random() % 16)
    let c2da_fresh12 : uint = uint(c2da_fresh11)
    c2da_mem[y_2 + 0 * 4] = uint8(c2da_fresh12)
    c2da_mem[y_2 + 0 * 4 + 1] = uint8(c2da_fresh12 >> 0x8)
    c2da_mem[y_2 + 0 * 4 + 2] = uint8(c2da_fresh12 >> 0x10)
    c2da_mem[y_2 + 0 * 4 + 3] = uint8(c2da_fresh12 >> 0x18)
    for (i_0 in range(1, width_4)) {
        r = M_Random() % 3 - 1
        let c2da_fresh13 : int = int(uint(c2da_mem[y_2 + (i_0 - 1) * 4]) | uint(c2da_mem[y_2 + (i_0 - 1) * 4 + 1]) << 0x8 | uint(c2da_mem[y_2 + (i_0 - 1) * 4 + 2]) << 0x10 | uint(c2da_mem[y_2 + (i_0 - 1) * 4 + 3]) << 0x18) + r
        let c2da_fresh14 : uint = uint(c2da_fresh13)
        c2da_mem[y_2 + i_0 * 4] = uint8(c2da_fresh14)
        c2da_mem[y_2 + i_0 * 4 + 1] = uint8(c2da_fresh14 >> 0x8)
        c2da_mem[y_2 + i_0 * 4 + 2] = uint8(c2da_fresh14 >> 0x10)
        c2da_mem[y_2 + i_0 * 4 + 3] = uint8(c2da_fresh14 >> 0x18)
        if (int(uint(c2da_mem[y_2 + i_0 * 4]) | uint(c2da_mem[y_2 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[y_2 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[y_2 + i_0 * 4 + 3]) << 0x18) > 0) {
            let c2da_fresh15 : int = 0
            let c2da_fresh16 : uint = uint(c2da_fresh15)
            c2da_mem[y_2 + i_0 * 4] = uint8(c2da_fresh16)
            c2da_mem[y_2 + i_0 * 4 + 1] = uint8(c2da_fresh16 >> 0x8)
            c2da_mem[y_2 + i_0 * 4 + 2] = uint8(c2da_fresh16 >> 0x10)
            c2da_mem[y_2 + i_0 * 4 + 3] = uint8(c2da_fresh16 >> 0x18)
        } elif (int(uint(c2da_mem[y_2 + i_0 * 4]) | uint(c2da_mem[y_2 + i_0 * 4 + 1]) << 0x8 | uint(c2da_mem[y_2 + i_0 * 4 + 2]) << 0x10 | uint(c2da_mem[y_2 + i_0 * 4 + 3]) << 0x18) == -16) {
            let c2da_fresh17 : int = -15
            let c2da_fresh18 : uint = uint(c2da_fresh17)
            c2da_mem[y_2 + i_0 * 4] = uint8(c2da_fresh18)
            c2da_mem[y_2 + i_0 * 4 + 1] = uint8(c2da_fresh18 >> 0x8)
            c2da_mem[y_2 + i_0 * 4 + 2] = uint8(c2da_fresh18 >> 0x10)
            c2da_mem[y_2 + i_0 * 4 + 3] = uint8(c2da_fresh18 >> 0x18)
        }
    }
    return 0
}
[export, sideeffects]
def wipe_shittyColMajorXform(var array_0 : int; var width_5 : int; var height_5 : int) {
    var dest : int = Z_Malloc(width_5 * height_5 * 2, 1, 0)
    for (y_3 in range(0, height_5)) {
        for (x_2 in range(0, width_5)) {
            let c2da_fresh19 : int16 = int16(uint(c2da_mem[array_0 + (y_3 * width_5 + x_2) * 2]) | uint(c2da_mem[array_0 + (y_3 * width_5 + x_2) * 2 + 1]) << 0x8)
            let c2da_fresh20 : uint = uint(c2da_fresh19)
            c2da_mem[dest + (x_2 * height_5 + y_3) * 2] = uint8(c2da_fresh20)
            c2da_mem[dest + (x_2 * height_5 + y_3) * 2 + 1] = uint8(c2da_fresh20 >> 0x8)
        }
    }
    c2da_lin_memcpy(array_0, dest, uint64(width_5 * height_5 * 2))
    Z_Free(dest)
    return
}
[export, sideeffects]
def wipe_exitColorXForm(var width_6 : int; var height_6 : int; var ticks_3 : int) : int {
    return 0
}
[export, sideeffects]
def wipe_doColorXForm(var width_7 : int; var height_7 : int; var ticks_4 : int) : int {
    var changed : uint
    var w : int
    var e : int
    var newval : int
    changed = 0u
    w = wipe_scr
    e = wipe_scr_end
    while (w != wipe_scr + width_7 * height_7) {
        if (int(c2da_mem[w]) != int(c2da_mem[e])) {
            if (int(c2da_mem[w]) > int(c2da_mem[e])) {
                newval = int(c2da_mem[w]) - ticks_4
                if (newval < int(c2da_mem[e])) {
                    let c2da_fresh21 : uint8 = c2da_mem[e]
                    c2da_mem[w] = c2da_fresh21
                } else {
                    let c2da_fresh22 : uint8 = uint8(newval)
                    c2da_mem[w] = c2da_fresh22
                }
                changed = 1u
            } elif (int(c2da_mem[w]) < int(c2da_mem[e])) {
                newval = int(c2da_mem[w]) + ticks_4
                if (newval > int(c2da_mem[e])) {
                    let c2da_fresh23 : uint8 = c2da_mem[e]
                    c2da_mem[w] = c2da_fresh23
                } else {
                    let c2da_fresh24 : uint8 = uint8(newval)
                    c2da_mem[w] = c2da_fresh24
                }
                changed = 1u
            }
        }
        w++
        e++
    }
    return changed == 0 ? 1 : 0
}
[export, sideeffects]
def wipe_initColorXForm(var width_8 : int; var height_8 : int; var ticks_5 : int) : int {
    c2da_lin_memcpy(wipe_scr, wipe_scr_start, uint64(width_8 * height_8))
    return 0
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_f_wipe() {
    if (length(c2da_fn_table3) < 15) {
        resize(c2da_fn_table3, 15)
    }
    c2da_fn_table3[14] = @@wipe_exitMelt
    c2da_fn_table3[13] = @@wipe_doMelt
    c2da_fn_table3[12] = @@wipe_initMelt
    c2da_fn_table3[11] = @@wipe_exitColorXForm
    c2da_fn_table3[10] = @@wipe_doColorXForm
    c2da_fn_table3[9] = @@wipe_initColorXForm
}

[init]
def private c2da_lin_relink_init_f_wipe() {
    c2da_relink_f_wipe()
}
