options gen2
options solid_context = true
options stack = 4194304
module i_scale public

require dasdoom_runtime
require i_system_cluster
require m_argv
require strings
require daslib/fio
var private c2da_str_0 : array<int8> = [int8(73), int8(95), int8(73), int8(110), int8(105), int8(116), int8(83), int8(116), int8(114), int8(101), int8(116), int8(99), int8(104), int8(84), int8(97), int8(98), int8(108), int8(101), int8(115), int8(58), int8(32), int8(71), int8(101), int8(110), int8(101), int8(114), int8(97), int8(116), int8(105), int8(110), int8(103), int8(32), int8(108), int8(111), int8(111), int8(107), int8(117), int8(112), int8(32), int8(116), int8(97), int8(98), int8(108), int8(101), int8(115), int8(46), int8(46), int8(0)]

var private c2da_str_1 : array<int8> = [int8(46), int8(46), int8(0)]

var private c2da_str_2 : array<int8> = [int8(37), int8(115), int8(10), int8(0)]

var private c2da_str_3 : array<int8> = [int8(0)]

var private c2da_str_4 : array<int8> = [int8(73), int8(95), int8(73), int8(110), int8(105), int8(116), int8(83), int8(113), int8(117), int8(97), int8(115), int8(104), int8(84), int8(97), int8(98), int8(108), int8(101), int8(58), int8(32), int8(71), int8(101), int8(110), int8(101), int8(114), int8(97), int8(116), int8(105), int8(110), int8(103), int8(32), int8(108), int8(111), int8(111), int8(107), int8(117), int8(112), int8(32), int8(116), int8(97), int8(98), int8(108), int8(101), int8(46), int8(46), int8(0)]

var private c2da_str_5 : array<int8> = [int8(73), int8(95), int8(82), int8(101), int8(115), int8(101), int8(116), int8(83), int8(99), int8(97), int8(108), int8(101), int8(84), int8(97), int8(98), int8(108), int8(101), int8(115), int8(58), int8(32), int8(82), int8(101), int8(103), int8(101), int8(110), int8(101), int8(114), int8(97), int8(116), int8(105), int8(110), int8(103), int8(32), int8(108), int8(111), int8(111), int8(107), int8(117), int8(112), int8(32), int8(116), int8(97), int8(98), int8(108), int8(101), int8(115), int8(46), int8(46), int8(10), int8(0)]

var private c2da_str_6 : array<int8> = [int8(73), int8(95), int8(82), int8(101), int8(115), int8(101), int8(116), int8(83), int8(99), int8(97), int8(108), int8(101), int8(84), int8(97), int8(98), int8(108), int8(101), int8(115), int8(58), int8(32), int8(82), int8(101), int8(103), int8(101), int8(110), int8(101), int8(114), int8(97), int8(116), int8(105), int8(110), int8(103), int8(32), int8(108), int8(111), int8(111), int8(107), int8(117), int8(112), int8(32), int8(116), int8(97), int8(98), int8(108), int8(101), int8(46), int8(46), int8(10), int8(0)]

var private c2da_str_7 : array<int8> = [int8(45), int8(115), int8(99), int8(97), int8(110), int8(108), int8(105), int8(110), int8(101), int8(0)]

[sideeffects]
def private c2da___bswap_16(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
var private src_buffer : uint8? = default<uint8?>

var private dest_buffer : uint8? = default<uint8?>

var private dest_pitch : int = default<int>

var private stretch_tables : uint8? [2] = fixed_array<uint8?>(null, null)

var private half_stretch_table : uint8? = null

[export, sideeffects]
def I_InitScale(var _src_buffer : uint8?; var _dest_buffer : uint8?; var _dest_pitch : int) {
    src_buffer = unsafe(reinterpret<uint8?>(_src_buffer))
    dest_buffer = unsafe(reinterpret<uint8?>(_dest_buffer))
    dest_pitch = int(_dest_pitch)  // nolint:PERF020
    return
}
[sideeffects]
def private I_Scale1x(var x1 : int; var y1 : int; var x2 : int; var y2 : int) : uint {
    var bufp : uint8?
    var screenp : uint8?
    var w : int = x2 - x1
    bufp = unsafe(reinterpret<uint8?>(unsafe(unsafe(src_buffer + int64(y1 * 320)) + x1)))
    screenp = unsafe(reinterpret<uint8?>(unsafe(unsafe(dest_buffer + int64(y1 * dest_pitch)) + x1)))
    for (y in range(y1, y2)) {
        let c2da_fresh0 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(screenp))))
        let c2da_fresh1 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(bufp))))
        let c2da_fresh2 : uint64 = uint64(w)
        if (c2da_fresh2 != 0x0) {
            unsafe(memcpy(unsafe(reinterpret<void?>(c2da_fresh0)), unsafe(reinterpret<void?>(c2da_fresh1)), c2da_fresh2))
        }
        unsafe {  // nolint:STYLE025
            screenp += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp += 320
        }
    }
    return 1u
}
var mode_scale_1x : screen_mode_t = screen_mode_t(width = 320, height = 200, InitMode = default<function<(var _arg0:uint8?):void>>, DrawScreen = @@I_Scale1x, poor_quality = 0u)

[sideeffects]
def private I_Scale2x(var x1_0 : int; var y1_0 : int; var x2_0 : int; var y2_0 : int) : uint {
    var bufp_0 : uint8?
    var screenp_0 : uint8?
    var screenp2 : uint8?
    var multi_pitch : int
    var sp : uint8?
    var sp2 : uint8?
    var bp : uint8?
    multi_pitch = dest_pitch * 2
    bufp_0 = unsafe(reinterpret<uint8?>(unsafe(unsafe(src_buffer + int64(y1_0 * 320)) + x1_0)))
    screenp_0 = unsafe(reinterpret<uint8?>(unsafe(dest_buffer + int64((y1_0 * dest_pitch + x1_0) * 2))))
    screenp2 = unsafe(reinterpret<uint8?>(unsafe(screenp_0 + dest_pitch)))
    for (y_0 in range(y1_0, y2_0)) {
        sp = unsafe(reinterpret<uint8?>(screenp_0))
        sp2 = unsafe(reinterpret<uint8?>(screenp2))
        bp = unsafe(reinterpret<uint8?>(bufp_0))
        var c2da_sp_addr : uint64 = unsafe(reinterpret<uint64>(sp))
        var c2da_sp2_addr : uint64 = unsafe(reinterpret<uint64>(sp2))
        var c2da_bp_addr : uint64 = unsafe(reinterpret<uint64>(bp))
        for (x in range(x1_0, x2_0)) {
            *unsafe(reinterpret<uint8?>(c2da_sp_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_addr)))  // nolint:PERF020
            c2da_sp_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_addr)))  // nolint:PERF020
            c2da_sp_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp2_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_addr)))  // nolint:PERF020
            c2da_sp2_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp2_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_addr)))  // nolint:PERF020
            c2da_sp2_addr++
            c2da_bp_addr++
        }
        unsafe {  // nolint:STYLE025
            screenp_0 += int64(multi_pitch)
        }
        unsafe {  // nolint:STYLE025
            screenp2 += int64(multi_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_0 += 320
        }
    }
    return 1u
}
var mode_scale_2x : screen_mode_t = screen_mode_t(width = 320 * 2, height = 200 * 2, InitMode = default<function<(var _arg0:uint8?):void>>, DrawScreen = @@I_Scale2x, poor_quality = 0u)

[sideeffects]
def private I_Scale3x(var x1_1 : int; var y1_1 : int; var x2_1 : int; var y2_1 : int) : uint {
    var bufp_1 : uint8?
    var screenp_1 : uint8?
    var screenp2_0 : uint8?
    var screenp3 : uint8?
    var multi_pitch_0 : int
    var sp_0 : uint8?
    var sp2_0 : uint8?
    var sp3 : uint8?
    var bp_0 : uint8?
    multi_pitch_0 = dest_pitch * 3
    bufp_1 = unsafe(reinterpret<uint8?>(unsafe(unsafe(src_buffer + int64(y1_1 * 320)) + x1_1)))
    screenp_1 = unsafe(reinterpret<uint8?>(unsafe(dest_buffer + int64((y1_1 * dest_pitch + x1_1) * 3))))
    screenp2_0 = unsafe(reinterpret<uint8?>(unsafe(screenp_1 + dest_pitch)))
    screenp3 = unsafe(reinterpret<uint8?>(unsafe(screenp_1 + int64(dest_pitch * 2))))
    for (y_1 in range(y1_1, y2_1)) {
        sp_0 = unsafe(reinterpret<uint8?>(screenp_1))
        sp2_0 = unsafe(reinterpret<uint8?>(screenp2_0))
        sp3 = unsafe(reinterpret<uint8?>(screenp3))
        bp_0 = unsafe(reinterpret<uint8?>(bufp_1))
        var c2da_sp_0_addr : uint64 = unsafe(reinterpret<uint64>(sp_0))
        var c2da_sp2_0_addr : uint64 = unsafe(reinterpret<uint64>(sp2_0))
        var c2da_sp3_addr : uint64 = unsafe(reinterpret<uint64>(sp3))
        var c2da_bp_0_addr : uint64 = unsafe(reinterpret<uint64>(bp_0))
        for (x_0 in range(x1_1, x2_1)) {
            *unsafe(reinterpret<uint8?>(c2da_sp_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_0_addr)))  // nolint:PERF020
            c2da_sp_0_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_0_addr)))  // nolint:PERF020
            c2da_sp_0_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_0_addr)))  // nolint:PERF020
            c2da_sp_0_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp2_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_0_addr)))  // nolint:PERF020
            c2da_sp2_0_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp2_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_0_addr)))  // nolint:PERF020
            c2da_sp2_0_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp2_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_0_addr)))  // nolint:PERF020
            c2da_sp2_0_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp3_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_0_addr)))  // nolint:PERF020
            c2da_sp3_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp3_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_0_addr)))  // nolint:PERF020
            c2da_sp3_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp3_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_0_addr)))  // nolint:PERF020
            c2da_sp3_addr++
            c2da_bp_0_addr++
        }
        unsafe {  // nolint:STYLE025
            screenp_1 += int64(multi_pitch_0)
        }
        unsafe {  // nolint:STYLE025
            screenp2_0 += int64(multi_pitch_0)
        }
        unsafe {  // nolint:STYLE025
            screenp3 += int64(multi_pitch_0)
        }
        unsafe {  // nolint:STYLE025
            bufp_1 += 320
        }
    }
    return 1u
}
var mode_scale_3x : screen_mode_t = screen_mode_t(width = 320 * 3, height = 200 * 3, InitMode = default<function<(var _arg0:uint8?):void>>, DrawScreen = @@I_Scale3x, poor_quality = 0u)

[sideeffects]
def private I_Scale4x(var x1_2 : int; var y1_2 : int; var x2_2 : int; var y2_2 : int) : uint {
    var bufp_2 : uint8?
    var screenp_2 : uint8?
    var screenp2_1 : uint8?
    var screenp3_0 : uint8?
    var screenp4 : uint8?
    var multi_pitch_1 : int
    var sp_1 : uint8?
    var sp2_1 : uint8?
    var sp3_0 : uint8?
    var sp4 : uint8?
    var bp_1 : uint8?
    multi_pitch_1 = dest_pitch * 4
    bufp_2 = unsafe(reinterpret<uint8?>(unsafe(unsafe(src_buffer + int64(y1_2 * 320)) + x1_2)))
    screenp_2 = unsafe(reinterpret<uint8?>(unsafe(dest_buffer + int64((y1_2 * dest_pitch + x1_2) * 4))))
    screenp2_1 = unsafe(reinterpret<uint8?>(unsafe(screenp_2 + dest_pitch)))
    screenp3_0 = unsafe(reinterpret<uint8?>(unsafe(screenp_2 + int64(dest_pitch * 2))))
    screenp4 = unsafe(reinterpret<uint8?>(unsafe(screenp_2 + int64(dest_pitch * 3))))
    for (y_2 in range(y1_2, y2_2)) {
        sp_1 = unsafe(reinterpret<uint8?>(screenp_2))
        sp2_1 = unsafe(reinterpret<uint8?>(screenp2_1))
        sp3_0 = unsafe(reinterpret<uint8?>(screenp3_0))
        sp4 = unsafe(reinterpret<uint8?>(screenp4))
        bp_1 = unsafe(reinterpret<uint8?>(bufp_2))
        var c2da_sp_1_addr : uint64 = unsafe(reinterpret<uint64>(sp_1))
        var c2da_sp2_1_addr : uint64 = unsafe(reinterpret<uint64>(sp2_1))
        var c2da_sp3_0_addr : uint64 = unsafe(reinterpret<uint64>(sp3_0))
        var c2da_sp4_addr : uint64 = unsafe(reinterpret<uint64>(sp4))
        var c2da_bp_1_addr : uint64 = unsafe(reinterpret<uint64>(bp_1))
        for (x_1 in range(x1_2, x2_2)) {
            *unsafe(reinterpret<uint8?>(c2da_sp_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_1_addr)))  // nolint:PERF020
            c2da_sp_1_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_1_addr)))  // nolint:PERF020
            c2da_sp_1_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_1_addr)))  // nolint:PERF020
            c2da_sp_1_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_1_addr)))  // nolint:PERF020
            c2da_sp_1_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_1_addr)))  // nolint:PERF020
            c2da_sp2_1_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_1_addr)))  // nolint:PERF020
            c2da_sp2_1_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_1_addr)))  // nolint:PERF020
            c2da_sp2_1_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_1_addr)))  // nolint:PERF020
            c2da_sp2_1_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_1_addr)))  // nolint:PERF020
            c2da_sp3_0_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_1_addr)))  // nolint:PERF020
            c2da_sp3_0_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_1_addr)))  // nolint:PERF020
            c2da_sp3_0_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_1_addr)))  // nolint:PERF020
            c2da_sp3_0_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp4_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_1_addr)))  // nolint:PERF020
            c2da_sp4_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp4_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_1_addr)))  // nolint:PERF020
            c2da_sp4_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp4_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_1_addr)))  // nolint:PERF020
            c2da_sp4_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp4_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_1_addr)))  // nolint:PERF020
            c2da_sp4_addr++
            c2da_bp_1_addr++
        }
        unsafe {  // nolint:STYLE025
            screenp_2 += int64(multi_pitch_1)
        }
        unsafe {  // nolint:STYLE025
            screenp2_1 += int64(multi_pitch_1)
        }
        unsafe {  // nolint:STYLE025
            screenp3_0 += int64(multi_pitch_1)
        }
        unsafe {  // nolint:STYLE025
            screenp4 += int64(multi_pitch_1)
        }
        unsafe {  // nolint:STYLE025
            bufp_2 += 320
        }
    }
    return 1u
}
var mode_scale_4x : screen_mode_t = screen_mode_t(width = 320 * 4, height = 200 * 4, InitMode = default<function<(var _arg0:uint8?):void>>, DrawScreen = @@I_Scale4x, poor_quality = 0u)

[sideeffects]
def private I_Scale5x(var x1_3 : int; var y1_3 : int; var x2_3 : int; var y2_3 : int) : uint {
    var bufp_3 : uint8?
    var screenp_3 : uint8?
    var screenp2_2 : uint8?
    var screenp3_1 : uint8?
    var screenp4_0 : uint8?
    var screenp5 : uint8?
    var multi_pitch_2 : int
    var sp_2 : uint8?
    var sp2_2 : uint8?
    var sp3_1 : uint8?
    var sp4_0 : uint8?
    var sp5 : uint8?
    var bp_2 : uint8?
    multi_pitch_2 = dest_pitch * 5
    bufp_3 = unsafe(reinterpret<uint8?>(unsafe(unsafe(src_buffer + int64(y1_3 * 320)) + x1_3)))
    screenp_3 = unsafe(reinterpret<uint8?>(unsafe(dest_buffer + int64((y1_3 * dest_pitch + x1_3) * 5))))
    screenp2_2 = unsafe(reinterpret<uint8?>(unsafe(screenp_3 + dest_pitch)))
    screenp3_1 = unsafe(reinterpret<uint8?>(unsafe(screenp_3 + int64(dest_pitch * 2))))
    screenp4_0 = unsafe(reinterpret<uint8?>(unsafe(screenp_3 + int64(dest_pitch * 3))))
    screenp5 = unsafe(reinterpret<uint8?>(unsafe(screenp_3 + int64(dest_pitch * 4))))
    for (y_3 in range(y1_3, y2_3)) {
        sp_2 = unsafe(reinterpret<uint8?>(screenp_3))
        sp2_2 = unsafe(reinterpret<uint8?>(screenp2_2))
        sp3_1 = unsafe(reinterpret<uint8?>(screenp3_1))
        sp4_0 = unsafe(reinterpret<uint8?>(screenp4_0))
        sp5 = unsafe(reinterpret<uint8?>(screenp5))
        bp_2 = unsafe(reinterpret<uint8?>(bufp_3))
        var c2da_sp_2_addr : uint64 = unsafe(reinterpret<uint64>(sp_2))
        var c2da_sp2_2_addr : uint64 = unsafe(reinterpret<uint64>(sp2_2))
        var c2da_sp3_1_addr : uint64 = unsafe(reinterpret<uint64>(sp3_1))
        var c2da_sp4_0_addr : uint64 = unsafe(reinterpret<uint64>(sp4_0))
        var c2da_sp5_addr : uint64 = unsafe(reinterpret<uint64>(sp5))
        var c2da_bp_2_addr : uint64 = unsafe(reinterpret<uint64>(bp_2))
        for (x_2 in range(x1_3, x2_3)) {
            *unsafe(reinterpret<uint8?>(c2da_sp_2_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp_2_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp_2_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp_2_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp_2_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp_2_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp_2_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp_2_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp_2_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp_2_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp2_2_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp2_2_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp2_2_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp2_2_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp2_2_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp2_2_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp2_2_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp2_2_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp2_2_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp2_2_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp3_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp3_1_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp3_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp3_1_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp3_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp3_1_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp3_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp3_1_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp3_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp3_1_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp4_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp4_0_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp4_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp4_0_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp4_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp4_0_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp4_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp4_0_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp4_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp4_0_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp5_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp5_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp5_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp5_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp5_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp5_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp5_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp5_addr++
            *unsafe(reinterpret<uint8?>(c2da_sp5_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_bp_2_addr)))  // nolint:PERF020
            c2da_sp5_addr++
            c2da_bp_2_addr++
        }
        unsafe {  // nolint:STYLE025
            screenp_3 += int64(multi_pitch_2)
        }
        unsafe {  // nolint:STYLE025
            screenp2_2 += int64(multi_pitch_2)
        }
        unsafe {  // nolint:STYLE025
            screenp3_1 += int64(multi_pitch_2)
        }
        unsafe {  // nolint:STYLE025
            screenp4_0 += int64(multi_pitch_2)
        }
        unsafe {  // nolint:STYLE025
            screenp5 += int64(multi_pitch_2)
        }
        unsafe {  // nolint:STYLE025
            bufp_3 += 320
        }
    }
    return 1u
}
var mode_scale_5x : screen_mode_t = screen_mode_t(width = 320 * 5, height = 200 * 5, InitMode = default<function<(var _arg0:uint8?):void>>, DrawScreen = @@I_Scale5x, poor_quality = 0u)

[sideeffects]
def private FindNearestColor(var palette : uint8?; var r : int; var g : int; var b : int) : int {
    var col : uint8?
    var best : int
    var best_diff : int
    var diff : int
    best = 0
    best_diff = 2147483647
    for (i in range(0, 256)) {
        col = unsafe(reinterpret<uint8?>(unsafe(palette + int64(i * 3))))
        diff = (r - int(unsafe(col[0]))) * (r - int(unsafe(col[0]))) + (g - int(unsafe(col[1]))) * (g - int(unsafe(col[1]))) + (b - int(unsafe(col[2]))) * (b - int(unsafe(col[2])))
        if (diff == 0) {
            return i
        } elif (diff < best_diff) {
            best = i
            best_diff = diff
        }
    }
    return best
}
[sideeffects]
def private GenerateStretchTable(var palette_0 : uint8?; var pct : int) : uint8? {
    var result_0 : uint8?
    var r_0 : int
    var g_0 : int
    var b_0 : int
    var col1 : uint8?
    var col2 : uint8?
    result_0 = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(Z_Malloc(256 * 256, 1, null)))))
    for (x_3 in range(0, 256)) {
        for (y_4 in range(0, 256)) {
            col1 = unsafe(reinterpret<uint8?>(unsafe(palette_0 + int64(x_3 * 3))))
            col2 = unsafe(reinterpret<uint8?>(unsafe(palette_0 + int64(y_4 * 3))))
            r_0 = (int(unsafe(col1[0])) * pct + int(unsafe(col2[0])) * (100 - pct)) / 100
            g_0 = (int(unsafe(col1[1])) * pct + int(unsafe(col2[1])) * (100 - pct)) / 100
            b_0 = (int(unsafe(col1[2])) * pct + int(unsafe(col2[2])) * (100 - pct)) / 100
            unsafe(result_0[x_3 * 256 + y_4]) = uint8(FindNearestColor(palette_0, r_0, g_0, b_0))
        }
    }
    return unsafe(reinterpret<uint8?>(result_0))
}
[sideeffects]
def private I_InitStretchTables(var palette_1 : uint8?) {
    if (stretch_tables[0] != null) {
        return
    }
    c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_0[0])), [])
    c2da_std_fflush(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stdout())))))
    stretch_tables[0] = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(GenerateStretchTable(palette_1, 20)))))
    c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_1[0])), [])
    c2da_std_fflush(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stdout())))))
    stretch_tables[1] = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(GenerateStretchTable(palette_1, 40)))))
    c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_2[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_3[0])))))])
    return
}
[sideeffects]
def private I_InitSquashTable(var palette_2 : uint8?) {
    if (half_stretch_table != null) {
        return
    }
    c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_4[0])), [])
    c2da_std_fflush(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stdout())))))
    half_stretch_table = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(GenerateStretchTable(palette_2, 50)))))
    c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_2[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_3[0])))))])
    return
}
[export, sideeffects]
def I_ResetScaleTables(var palette_3 : uint8?) {
    if (stretch_tables[0] != null) {
        Z_Free(unsafe(reinterpret<uint8?>(stretch_tables[0])))
        Z_Free(unsafe(reinterpret<uint8?>(stretch_tables[1])))
        c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_5[0])), [])
        stretch_tables[0] = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(GenerateStretchTable(palette_3, 20)))))
        stretch_tables[1] = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(GenerateStretchTable(palette_3, 40)))))
    }
    if (half_stretch_table != null) {
        Z_Free(unsafe(reinterpret<uint8?>(half_stretch_table)))
        c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_6[0])), [])
        half_stretch_table = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(GenerateStretchTable(palette_3, 50)))))
    }
    return
}
[sideeffects]
def private WriteBlendedLine1x(var dest : uint8?; var src1 : uint8?; var src2 : uint8?; var stretch_table : uint8?) {
    var c2da_dest_addr : uint64 = unsafe(reinterpret<uint64>(dest))
    var c2da_src1_addr : uint64 = unsafe(reinterpret<uint64>(src1))
    var c2da_src2_addr : uint64 = unsafe(reinterpret<uint64>(src2))
    for (x_4 in range(0, 320)) {
        *unsafe(reinterpret<uint8?>(c2da_dest_addr)) = uint8(unsafe(stretch_table[int(*unsafe(reinterpret<uint8?>(c2da_src1_addr))) * 256 + int(*unsafe(reinterpret<uint8?>(c2da_src2_addr)))]))  // nolint:PERF020
        c2da_dest_addr++
        c2da_src1_addr++
        c2da_src2_addr++
    }
    return
}
[sideeffects]
def private I_Stretch1x(var x1_4 : int; var y1_4 : int; var x2_4 : int; var y2_4 : int) : uint {
    var bufp_4 : uint8?
    var screenp_4 : uint8?
    var y_5 : int
    if (x1_4 != 0 || y1_4 != 0 || x2_4 != 320 || y2_4 != 200) {
        return 0u
    }
    bufp_4 = unsafe(reinterpret<uint8?>(unsafe(unsafe(src_buffer + int64(y1_4 * 320)) + x1_4)))
    screenp_4 = unsafe(reinterpret<uint8?>(unsafe(unsafe(dest_buffer + int64(y1_4 * dest_pitch)) + x1_4)))
    y_5 = 0
    while (y_5 < 200) {
        unsafe(memcpy(unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(screenp_4)))))), unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(bufp_4)))))), 320ul))
        unsafe {  // nolint:STYLE025
            screenp_4 += int64(dest_pitch)
        }
        WriteBlendedLine1x(screenp_4, bufp_4, unsafe(reinterpret<uint8?>(unsafe(bufp_4 + 320))), unsafe(reinterpret<uint8?>(stretch_tables[0])))
        unsafe {  // nolint:STYLE025
            screenp_4 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_4 += 320
        }
        WriteBlendedLine1x(screenp_4, bufp_4, unsafe(reinterpret<uint8?>(unsafe(bufp_4 + 320))), unsafe(reinterpret<uint8?>(stretch_tables[1])))
        unsafe {  // nolint:STYLE025
            screenp_4 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_4 += 320
        }
        WriteBlendedLine1x(screenp_4, unsafe(reinterpret<uint8?>(unsafe(bufp_4 + 320))), bufp_4, unsafe(reinterpret<uint8?>(stretch_tables[1])))
        unsafe {  // nolint:STYLE025
            screenp_4 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_4 += 320
        }
        WriteBlendedLine1x(screenp_4, unsafe(reinterpret<uint8?>(unsafe(bufp_4 + 320))), bufp_4, unsafe(reinterpret<uint8?>(stretch_tables[0])))
        unsafe {  // nolint:STYLE025
            screenp_4 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_4 += 320
        }
        unsafe(memcpy(unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(screenp_4)))))), unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(bufp_4)))))), 320ul))
        unsafe {  // nolint:STYLE025
            screenp_4 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_4 += 320
        }
        y_5 += 5
    }
    return 1u
}
var mode_stretch_1x : screen_mode_t = screen_mode_t(width = 320, height = 240, InitMode = @@I_InitStretchTables, DrawScreen = @@I_Stretch1x, poor_quality = 1u)

[sideeffects]
def private WriteLine2x(var dest_0 : uint8?; var src : uint8?) {
    var c2da_dest_0_addr : uint64 = unsafe(reinterpret<uint64>(dest_0))
    var c2da_src_addr : uint64 = unsafe(reinterpret<uint64>(src))
    for (x_5 in range(0, 320)) {
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_0_addr))[0]) = uint8(*unsafe(reinterpret<uint8?>(c2da_src_addr)))  // nolint:PERF020
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_0_addr))[1]) = uint8(*unsafe(reinterpret<uint8?>(c2da_src_addr)))  // nolint:PERF020
        c2da_dest_0_addr += 2ul
        c2da_src_addr++
    }
    return
}
[sideeffects]
def private WriteBlendedLine2x(var dest_1 : uint8?; var src1_0 : uint8?; var src2_0 : uint8?; var stretch_table_0 : uint8?) {
    var val : int
    var c2da_dest_1_addr : uint64 = unsafe(reinterpret<uint64>(dest_1))
    var c2da_src1_0_addr : uint64 = unsafe(reinterpret<uint64>(src1_0))
    var c2da_src2_0_addr : uint64 = unsafe(reinterpret<uint64>(src2_0))
    for (x_6 in range(0, 320)) {
        val = int(unsafe(stretch_table_0[int(*unsafe(reinterpret<uint8?>(c2da_src1_0_addr))) * 256 + int(*unsafe(reinterpret<uint8?>(c2da_src2_0_addr)))]))
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_1_addr))[0]) = uint8(val)
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_1_addr))[1]) = uint8(val)
        c2da_dest_1_addr += 2ul
        c2da_src1_0_addr++
        c2da_src2_0_addr++
    }
    return
}
[sideeffects]
def private I_Stretch2x(var x1_5 : int; var y1_5 : int; var x2_5 : int; var y2_5 : int) : uint {
    var bufp_5 : uint8?
    var screenp_5 : uint8?
    var y_6 : int
    if (x1_5 != 0 || y1_5 != 0 || x2_5 != 320 || y2_5 != 200) {
        return 0u
    }
    bufp_5 = unsafe(reinterpret<uint8?>(unsafe(unsafe(src_buffer + int64(y1_5 * 320)) + x1_5)))
    screenp_5 = unsafe(reinterpret<uint8?>(unsafe(unsafe(dest_buffer + int64(y1_5 * dest_pitch)) + x1_5)))
    y_6 = 0
    while (y_6 < 200) {
        WriteLine2x(screenp_5, bufp_5)
        unsafe {  // nolint:STYLE025
            screenp_5 += int64(dest_pitch)
        }
        WriteLine2x(screenp_5, bufp_5)
        unsafe {  // nolint:STYLE025
            screenp_5 += int64(dest_pitch)
        }
        WriteBlendedLine2x(screenp_5, bufp_5, unsafe(reinterpret<uint8?>(unsafe(bufp_5 + 320))), unsafe(reinterpret<uint8?>(stretch_tables[1])))
        unsafe {  // nolint:STYLE025
            screenp_5 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_5 += 320
        }
        WriteLine2x(screenp_5, bufp_5)
        unsafe {  // nolint:STYLE025
            screenp_5 += int64(dest_pitch)
        }
        WriteBlendedLine2x(screenp_5, unsafe(reinterpret<uint8?>(unsafe(bufp_5 + 320))), bufp_5, unsafe(reinterpret<uint8?>(stretch_tables[0])))
        unsafe {  // nolint:STYLE025
            screenp_5 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_5 += 320
        }
        WriteLine2x(screenp_5, bufp_5)
        unsafe {  // nolint:STYLE025
            screenp_5 += int64(dest_pitch)
        }
        WriteLine2x(screenp_5, bufp_5)
        unsafe {  // nolint:STYLE025
            screenp_5 += int64(dest_pitch)
        }
        WriteBlendedLine2x(screenp_5, bufp_5, unsafe(reinterpret<uint8?>(unsafe(bufp_5 + 320))), unsafe(reinterpret<uint8?>(stretch_tables[0])))
        unsafe {  // nolint:STYLE025
            screenp_5 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_5 += 320
        }
        WriteLine2x(screenp_5, bufp_5)
        unsafe {  // nolint:STYLE025
            screenp_5 += int64(dest_pitch)
        }
        WriteBlendedLine2x(screenp_5, unsafe(reinterpret<uint8?>(unsafe(bufp_5 + 320))), bufp_5, unsafe(reinterpret<uint8?>(stretch_tables[1])))
        unsafe {  // nolint:STYLE025
            screenp_5 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_5 += 320
        }
        WriteLine2x(screenp_5, bufp_5)
        unsafe {  // nolint:STYLE025
            screenp_5 += int64(dest_pitch)
        }
        WriteLine2x(screenp_5, bufp_5)
        unsafe {  // nolint:STYLE025
            screenp_5 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_5 += 320
        }
        y_6 += 5
    }
    return 1u
}
var mode_stretch_2x : screen_mode_t = screen_mode_t(width = 320 * 2, height = 240 * 2, InitMode = @@I_InitStretchTables, DrawScreen = @@I_Stretch2x, poor_quality = 0u)

[sideeffects]
def private WriteLine3x(var dest_2 : uint8?; var src_0 : uint8?) {
    var c2da_dest_2_addr : uint64 = unsafe(reinterpret<uint64>(dest_2))
    var c2da_src_0_addr : uint64 = unsafe(reinterpret<uint64>(src_0))
    for (x_7 in range(0, 320)) {
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_2_addr))[0]) = uint8(*unsafe(reinterpret<uint8?>(c2da_src_0_addr)))  // nolint:PERF020
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_2_addr))[1]) = uint8(*unsafe(reinterpret<uint8?>(c2da_src_0_addr)))  // nolint:PERF020
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_2_addr))[2]) = uint8(*unsafe(reinterpret<uint8?>(c2da_src_0_addr)))  // nolint:PERF020
        c2da_dest_2_addr += 3ul
        c2da_src_0_addr++
    }
    return
}
[sideeffects]
def private WriteBlendedLine3x(var dest_3 : uint8?; var src1_1 : uint8?; var src2_1 : uint8?; var stretch_table_1 : uint8?) {
    var val_0 : int
    var c2da_dest_3_addr : uint64 = unsafe(reinterpret<uint64>(dest_3))
    var c2da_src1_1_addr : uint64 = unsafe(reinterpret<uint64>(src1_1))
    var c2da_src2_1_addr : uint64 = unsafe(reinterpret<uint64>(src2_1))
    for (x_8 in range(0, 320)) {
        val_0 = int(unsafe(stretch_table_1[int(*unsafe(reinterpret<uint8?>(c2da_src1_1_addr))) * 256 + int(*unsafe(reinterpret<uint8?>(c2da_src2_1_addr)))]))
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_3_addr))[0]) = uint8(val_0)
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_3_addr))[1]) = uint8(val_0)
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_3_addr))[2]) = uint8(val_0)
        c2da_dest_3_addr += 3ul
        c2da_src1_1_addr++
        c2da_src2_1_addr++
    }
    return
}
[sideeffects]
def private I_Stretch3x(var x1_6 : int; var y1_6 : int; var x2_6 : int; var y2_6 : int) : uint {
    var bufp_6 : uint8?
    var screenp_6 : uint8?
    var y_7 : int
    if (x1_6 != 0 || y1_6 != 0 || x2_6 != 320 || y2_6 != 200) {
        return 0u
    }
    bufp_6 = unsafe(reinterpret<uint8?>(unsafe(unsafe(src_buffer + int64(y1_6 * 320)) + x1_6)))
    screenp_6 = unsafe(reinterpret<uint8?>(unsafe(unsafe(dest_buffer + int64(y1_6 * dest_pitch)) + x1_6)))
    y_7 = 0
    while (y_7 < 200) {
        WriteLine3x(screenp_6, bufp_6)
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        WriteLine3x(screenp_6, bufp_6)
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        WriteLine3x(screenp_6, bufp_6)
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        WriteBlendedLine3x(screenp_6, unsafe(reinterpret<uint8?>(unsafe(bufp_6 + 320))), bufp_6, unsafe(reinterpret<uint8?>(stretch_tables[1])))
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_6 += 320
        }
        WriteLine3x(screenp_6, bufp_6)
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        WriteLine3x(screenp_6, bufp_6)
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        WriteLine3x(screenp_6, bufp_6)
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        WriteBlendedLine3x(screenp_6, bufp_6, unsafe(reinterpret<uint8?>(unsafe(bufp_6 + 320))), unsafe(reinterpret<uint8?>(stretch_tables[0])))
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_6 += 320
        }
        WriteLine3x(screenp_6, bufp_6)
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        WriteLine3x(screenp_6, bufp_6)
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        WriteBlendedLine3x(screenp_6, unsafe(reinterpret<uint8?>(unsafe(bufp_6 + 320))), bufp_6, unsafe(reinterpret<uint8?>(stretch_tables[0])))
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_6 += 320
        }
        WriteLine3x(screenp_6, bufp_6)
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        WriteLine3x(screenp_6, bufp_6)
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        WriteLine3x(screenp_6, bufp_6)
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        WriteBlendedLine3x(screenp_6, bufp_6, unsafe(reinterpret<uint8?>(unsafe(bufp_6 + 320))), unsafe(reinterpret<uint8?>(stretch_tables[1])))
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_6 += 320
        }
        WriteLine3x(screenp_6, bufp_6)
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        WriteLine3x(screenp_6, bufp_6)
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        WriteLine3x(screenp_6, bufp_6)
        unsafe {  // nolint:STYLE025
            screenp_6 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_6 += 320
        }
        y_7 += 5
    }
    return 1u
}
var mode_stretch_3x : screen_mode_t = screen_mode_t(width = 320 * 3, height = 240 * 3, InitMode = @@I_InitStretchTables, DrawScreen = @@I_Stretch3x, poor_quality = 0u)

[sideeffects]
def private WriteLine4x(var dest_4 : uint8?; var src_1 : uint8?) {
    var c2da_dest_4_addr : uint64 = unsafe(reinterpret<uint64>(dest_4))
    var c2da_src_1_addr : uint64 = unsafe(reinterpret<uint64>(src_1))
    for (x_9 in range(0, 320)) {
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_4_addr))[0]) = uint8(*unsafe(reinterpret<uint8?>(c2da_src_1_addr)))  // nolint:PERF020
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_4_addr))[1]) = uint8(*unsafe(reinterpret<uint8?>(c2da_src_1_addr)))  // nolint:PERF020
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_4_addr))[2]) = uint8(*unsafe(reinterpret<uint8?>(c2da_src_1_addr)))  // nolint:PERF020
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_4_addr))[3]) = uint8(*unsafe(reinterpret<uint8?>(c2da_src_1_addr)))  // nolint:PERF020
        c2da_dest_4_addr += 4ul
        c2da_src_1_addr++
    }
    return
}
[sideeffects]
def private WriteBlendedLine4x(var dest_5 : uint8?; var src1_2 : uint8?; var src2_2 : uint8?; var stretch_table_2 : uint8?) {
    var val_1 : int
    var c2da_dest_5_addr : uint64 = unsafe(reinterpret<uint64>(dest_5))
    var c2da_src1_2_addr : uint64 = unsafe(reinterpret<uint64>(src1_2))
    var c2da_src2_2_addr : uint64 = unsafe(reinterpret<uint64>(src2_2))
    for (x_10 in range(0, 320)) {
        val_1 = int(unsafe(stretch_table_2[int(*unsafe(reinterpret<uint8?>(c2da_src1_2_addr))) * 256 + int(*unsafe(reinterpret<uint8?>(c2da_src2_2_addr)))]))
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_5_addr))[0]) = uint8(val_1)
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_5_addr))[1]) = uint8(val_1)
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_5_addr))[2]) = uint8(val_1)
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_5_addr))[3]) = uint8(val_1)
        c2da_dest_5_addr += 4ul
        c2da_src1_2_addr++
        c2da_src2_2_addr++
    }
    return
}
[sideeffects]
def private I_Stretch4x(var x1_7 : int; var y1_7 : int; var x2_7 : int; var y2_7 : int) : uint {
    var bufp_7 : uint8?
    var screenp_7 : uint8?
    var y_8 : int
    if (x1_7 != 0 || y1_7 != 0 || x2_7 != 320 || y2_7 != 200) {
        return 0u
    }
    bufp_7 = unsafe(reinterpret<uint8?>(unsafe(unsafe(src_buffer + int64(y1_7 * 320)) + x1_7)))
    screenp_7 = unsafe(reinterpret<uint8?>(unsafe(unsafe(dest_buffer + int64(y1_7 * dest_pitch)) + x1_7)))
    y_8 = 0
    while (y_8 < 200) {
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteBlendedLine4x(screenp_7, unsafe(reinterpret<uint8?>(unsafe(bufp_7 + 320))), bufp_7, unsafe(reinterpret<uint8?>(stretch_tables[0])))
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_7 += 320
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteBlendedLine4x(screenp_7, unsafe(reinterpret<uint8?>(unsafe(bufp_7 + 320))), bufp_7, unsafe(reinterpret<uint8?>(stretch_tables[1])))
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_7 += 320
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteBlendedLine4x(screenp_7, bufp_7, unsafe(reinterpret<uint8?>(unsafe(bufp_7 + 320))), unsafe(reinterpret<uint8?>(stretch_tables[1])))
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_7 += 320
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteBlendedLine4x(screenp_7, bufp_7, unsafe(reinterpret<uint8?>(unsafe(bufp_7 + 320))), unsafe(reinterpret<uint8?>(stretch_tables[0])))
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_7 += 320
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        WriteLine4x(screenp_7, bufp_7)
        unsafe {  // nolint:STYLE025
            screenp_7 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_7 += 320
        }
        y_8 += 5
    }
    return 1u
}
var mode_stretch_4x : screen_mode_t = screen_mode_t(width = 320 * 4, height = 240 * 4, InitMode = @@I_InitStretchTables, DrawScreen = @@I_Stretch4x, poor_quality = 0u)

[sideeffects]
def private WriteLine5x(var dest_6 : uint8?; var src_2 : uint8?) {
    var c2da_dest_6_addr : uint64 = unsafe(reinterpret<uint64>(dest_6))
    var c2da_src_2_addr : uint64 = unsafe(reinterpret<uint64>(src_2))
    for (x_11 in range(0, 320)) {
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_6_addr))[0]) = uint8(*unsafe(reinterpret<uint8?>(c2da_src_2_addr)))  // nolint:PERF020
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_6_addr))[1]) = uint8(*unsafe(reinterpret<uint8?>(c2da_src_2_addr)))  // nolint:PERF020
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_6_addr))[2]) = uint8(*unsafe(reinterpret<uint8?>(c2da_src_2_addr)))  // nolint:PERF020
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_6_addr))[3]) = uint8(*unsafe(reinterpret<uint8?>(c2da_src_2_addr)))  // nolint:PERF020
        unsafe(unsafe(reinterpret<uint8?>(c2da_dest_6_addr))[4]) = uint8(*unsafe(reinterpret<uint8?>(c2da_src_2_addr)))  // nolint:PERF020
        c2da_dest_6_addr += 5ul
        c2da_src_2_addr++
    }
    return
}
[sideeffects]
def private I_Stretch5x(var x1_8 : int; var y1_8 : int; var x2_8 : int; var y2_8 : int) : uint {
    var bufp_8 : uint8?
    var screenp_8 : uint8?
    var y_9 : int
    if (x1_8 != 0 || y1_8 != 0 || x2_8 != 320 || y2_8 != 200) {
        return 0u
    }
    bufp_8 = unsafe(reinterpret<uint8?>(unsafe(unsafe(src_buffer + int64(y1_8 * 320)) + x1_8)))
    screenp_8 = unsafe(reinterpret<uint8?>(unsafe(unsafe(dest_buffer + int64(y1_8 * dest_pitch)) + x1_8)))
    y_9 = 0
    while (y_9 < 200) {
        WriteLine5x(screenp_8, bufp_8)
        unsafe {  // nolint:STYLE025
            screenp_8 += int64(dest_pitch)
        }
        WriteLine5x(screenp_8, bufp_8)
        unsafe {  // nolint:STYLE025
            screenp_8 += int64(dest_pitch)
        }
        WriteLine5x(screenp_8, bufp_8)
        unsafe {  // nolint:STYLE025
            screenp_8 += int64(dest_pitch)
        }
        WriteLine5x(screenp_8, bufp_8)
        unsafe {  // nolint:STYLE025
            screenp_8 += int64(dest_pitch)
        }
        WriteLine5x(screenp_8, bufp_8)
        unsafe {  // nolint:STYLE025
            screenp_8 += int64(dest_pitch)
        }
        WriteLine5x(screenp_8, bufp_8)
        unsafe {  // nolint:STYLE025
            screenp_8 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_8 += 320
        }
        y_9++
    }
    if (M_CheckParm(unsafe(addr<int8?>(c2da_str_7[0]))) > 0) {
        screenp_8 = unsafe(reinterpret<uint8?>(unsafe(dest_buffer + 2 * dest_pitch)))
        y_9 = 0
        while (y_9 < 1198) {
            unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(screenp_8)))), 0u8, 1600ul)))
            unsafe {  // nolint:STYLE025
                screenp_8 += int64(dest_pitch * 3)
            }
            y_9 += 3
        }
    }
    return 1u
}
var mode_stretch_5x : screen_mode_t = screen_mode_t(width = 320 * 5, height = 240 * 5, InitMode = @@I_InitStretchTables, DrawScreen = @@I_Stretch5x, poor_quality = 0u)

[sideeffects]
def private WriteSquashedLine1x(var dest_7 : uint8?; var src_3 : uint8?) {
    var x_12 : int
    var c2da_dest_7_addr : uint64 = unsafe(reinterpret<uint64>(dest_7))
    var c2da_src_3_addr : uint64 = unsafe(reinterpret<uint64>(src_3))
    x_12 = 0
    while (x_12 < 320) {
        *unsafe(reinterpret<uint8?>(c2da_dest_7_addr)) = uint8(unsafe(unsafe(reinterpret<uint8?>(stretch_tables[0]))[int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_3_addr))[1])) * 256 + int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_3_addr))[0]))]))  // nolint:PERF020
        c2da_dest_7_addr++
        *unsafe(reinterpret<uint8?>(c2da_dest_7_addr)) = uint8(unsafe(unsafe(reinterpret<uint8?>(stretch_tables[1]))[int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_3_addr))[2])) * 256 + int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_3_addr))[1]))]))  // nolint:PERF020
        c2da_dest_7_addr++
        *unsafe(reinterpret<uint8?>(c2da_dest_7_addr)) = uint8(unsafe(unsafe(reinterpret<uint8?>(stretch_tables[1]))[int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_3_addr))[2])) * 256 + int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_3_addr))[3]))]))  // nolint:PERF020
        c2da_dest_7_addr++
        *unsafe(reinterpret<uint8?>(c2da_dest_7_addr)) = uint8(unsafe(unsafe(reinterpret<uint8?>(stretch_tables[0]))[int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_3_addr))[3])) * 256 + int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_3_addr))[4]))]))  // nolint:PERF020
        c2da_dest_7_addr++
        x_12 += 5
        c2da_src_3_addr += 5ul
    }
    return
}
[sideeffects]
def private I_Squash1x(var x1_9 : int; var y1_9 : int; var x2_9 : int; var y2_9 : int) : uint {
    var bufp_9 : uint8?
    var screenp_9 : uint8?
    if (x1_9 != 0 || y1_9 != 0 || x2_9 != 320 || y2_9 != 200) {
        return 0u
    }
    bufp_9 = unsafe(reinterpret<uint8?>(src_buffer))
    screenp_9 = unsafe(reinterpret<uint8?>(dest_buffer))
    for (y_10 in range(0, 200)) {
        WriteSquashedLine1x(screenp_9, bufp_9)
        unsafe {  // nolint:STYLE025
            screenp_9 += int64(dest_pitch)
        }
        unsafe {  // nolint:STYLE025
            bufp_9 += 320
        }
    }
    return 1u
}
var mode_squash_1x : screen_mode_t = screen_mode_t(width = 256, height = 200, InitMode = @@I_InitStretchTables, DrawScreen = @@I_Squash1x, poor_quality = 1u)

[sideeffects]
def private WriteSquashedLine2x(var dest_8 : uint8?; var src_4 : uint8?) {
    var dest2 : uint8?
    var x_13 : int
    var c : int
    dest2 = unsafe(reinterpret<uint8?>(unsafe(dest_8 + dest_pitch)))
    var c2da_dest_8_addr : uint64 = unsafe(reinterpret<uint64>(dest_8))
    var c2da_dest2_addr : uint64 = unsafe(reinterpret<uint64>(dest2))
    var c2da_src_4_addr : uint64 = unsafe(reinterpret<uint64>(src_4))
    x_13 = 0
    while (x_13 < 320) {
        c = int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_4_addr))[0]))
        *unsafe(reinterpret<uint8?>(c2da_dest2_addr)) = uint8(c)
        *unsafe(reinterpret<uint8?>(c2da_dest_8_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_addr)))  // nolint:PERF020
        c2da_dest_8_addr++
        c2da_dest2_addr++
        c = int(unsafe(unsafe(reinterpret<uint8?>(stretch_tables[1]))[int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_4_addr))[1])) * 256 + int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_4_addr))[0]))]))
        *unsafe(reinterpret<uint8?>(c2da_dest2_addr)) = uint8(c)
        *unsafe(reinterpret<uint8?>(c2da_dest_8_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_addr)))  // nolint:PERF020
        c2da_dest_8_addr++
        c2da_dest2_addr++
        c = int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_4_addr))[1]))
        *unsafe(reinterpret<uint8?>(c2da_dest2_addr)) = uint8(c)
        *unsafe(reinterpret<uint8?>(c2da_dest_8_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_addr)))  // nolint:PERF020
        c2da_dest_8_addr++
        c2da_dest2_addr++
        c = int(unsafe(unsafe(reinterpret<uint8?>(stretch_tables[0]))[int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_4_addr))[1])) * 256 + int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_4_addr))[2]))]))
        *unsafe(reinterpret<uint8?>(c2da_dest2_addr)) = uint8(c)
        *unsafe(reinterpret<uint8?>(c2da_dest_8_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_addr)))  // nolint:PERF020
        c2da_dest_8_addr++
        c2da_dest2_addr++
        c = int(unsafe(unsafe(reinterpret<uint8?>(stretch_tables[0]))[int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_4_addr))[3])) * 256 + int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_4_addr))[2]))]))
        *unsafe(reinterpret<uint8?>(c2da_dest2_addr)) = uint8(c)
        *unsafe(reinterpret<uint8?>(c2da_dest_8_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_addr)))  // nolint:PERF020
        c2da_dest_8_addr++
        c2da_dest2_addr++
        c = int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_4_addr))[3]))
        *unsafe(reinterpret<uint8?>(c2da_dest2_addr)) = uint8(c)
        *unsafe(reinterpret<uint8?>(c2da_dest_8_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_addr)))  // nolint:PERF020
        c2da_dest_8_addr++
        c2da_dest2_addr++
        c = int(unsafe(unsafe(reinterpret<uint8?>(stretch_tables[1]))[int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_4_addr))[3])) * 256 + int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_4_addr))[4]))]))
        *unsafe(reinterpret<uint8?>(c2da_dest2_addr)) = uint8(c)
        *unsafe(reinterpret<uint8?>(c2da_dest_8_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_addr)))  // nolint:PERF020
        c2da_dest_8_addr++
        c2da_dest2_addr++
        c = int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_4_addr))[4]))
        *unsafe(reinterpret<uint8?>(c2da_dest2_addr)) = uint8(c)
        *unsafe(reinterpret<uint8?>(c2da_dest_8_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_addr)))  // nolint:PERF020
        c2da_dest_8_addr++
        c2da_dest2_addr++
        x_13 += 5
        c2da_src_4_addr += 5ul
    }
    return
}
[sideeffects]
def private I_Squash2x(var x1_10 : int; var y1_10 : int; var x2_10 : int; var y2_10 : int) : uint {
    var bufp_10 : uint8?
    var screenp_10 : uint8?
    if (x1_10 != 0 || y1_10 != 0 || x2_10 != 320 || y2_10 != 200) {
        return 0u
    }
    bufp_10 = unsafe(reinterpret<uint8?>(src_buffer))
    screenp_10 = unsafe(reinterpret<uint8?>(dest_buffer))
    for (y_11 in range(0, 200)) {
        WriteSquashedLine2x(screenp_10, bufp_10)
        unsafe {  // nolint:STYLE025
            screenp_10 += int64(dest_pitch * 2)
        }
        unsafe {  // nolint:STYLE025
            bufp_10 += 320
        }
    }
    return 1u
}
var mode_squash_2x : screen_mode_t = screen_mode_t(width = 256 * 2, height = 200 * 2, InitMode = @@I_InitStretchTables, DrawScreen = @@I_Squash2x, poor_quality = 0u)

[sideeffects]
def private WriteSquashedLine3x(var dest_9 : uint8?; var src_5 : uint8?) {
    var dest2_0 : uint8?
    var dest3 : uint8?
    var x_14 : int
    var c_0 : int
    dest2_0 = unsafe(reinterpret<uint8?>(unsafe(dest_9 + dest_pitch)))
    dest3 = unsafe(reinterpret<uint8?>(unsafe(dest_9 + int64(dest_pitch * 2))))
    var c2da_dest_9_addr : uint64 = unsafe(reinterpret<uint64>(dest_9))
    var c2da_dest2_0_addr : uint64 = unsafe(reinterpret<uint64>(dest2_0))
    var c2da_dest3_addr : uint64 = unsafe(reinterpret<uint64>(dest3))
    var c2da_src_5_addr : uint64 = unsafe(reinterpret<uint64>(src_5))
    x_14 = 0
    while (x_14 < 320) {
        c_0 = int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_5_addr))[0]))
        *unsafe(reinterpret<uint8?>(c2da_dest3_addr)) = uint8(c_0)
        *unsafe(reinterpret<uint8?>(c2da_dest2_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_9_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_0_addr)))  // nolint:PERF020
        c2da_dest_9_addr++
        c2da_dest2_0_addr++
        c2da_dest3_addr++
        *unsafe(reinterpret<uint8?>(c2da_dest3_addr)) = uint8(c_0)
        *unsafe(reinterpret<uint8?>(c2da_dest2_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_9_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_0_addr)))  // nolint:PERF020
        c2da_dest_9_addr++
        c2da_dest2_0_addr++
        c2da_dest3_addr++
        c_0 = int(unsafe(half_stretch_table[int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_5_addr))[0])) * 256 + int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_5_addr))[1]))]))
        *unsafe(reinterpret<uint8?>(c2da_dest3_addr)) = uint8(c_0)
        *unsafe(reinterpret<uint8?>(c2da_dest2_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_9_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_0_addr)))  // nolint:PERF020
        c2da_dest_9_addr++
        c2da_dest2_0_addr++
        c2da_dest3_addr++
        c_0 = int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_5_addr))[1]))
        *unsafe(reinterpret<uint8?>(c2da_dest3_addr)) = uint8(c_0)
        *unsafe(reinterpret<uint8?>(c2da_dest2_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_9_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_0_addr)))  // nolint:PERF020
        c2da_dest_9_addr++
        c2da_dest2_0_addr++
        c2da_dest3_addr++
        *unsafe(reinterpret<uint8?>(c2da_dest3_addr)) = uint8(c_0)
        *unsafe(reinterpret<uint8?>(c2da_dest2_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_9_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_0_addr)))  // nolint:PERF020
        c2da_dest_9_addr++
        c2da_dest2_0_addr++
        c2da_dest3_addr++
        x_14 += 2
        c2da_src_5_addr += 2ul
    }
    return
}
[sideeffects]
def private I_Squash3x(var x1_11 : int; var y1_11 : int; var x2_11 : int; var y2_11 : int) : uint {
    var bufp_11 : uint8?
    var screenp_11 : uint8?
    if (x1_11 != 0 || y1_11 != 0 || x2_11 != 320 || y2_11 != 200) {
        return 0u
    }
    bufp_11 = unsafe(reinterpret<uint8?>(src_buffer))
    screenp_11 = unsafe(reinterpret<uint8?>(dest_buffer))
    for (y_12 in range(0, 200)) {
        WriteSquashedLine3x(screenp_11, bufp_11)
        unsafe {  // nolint:STYLE025
            screenp_11 += int64(dest_pitch * 3)
        }
        unsafe {  // nolint:STYLE025
            bufp_11 += 320
        }
    }
    return 1u
}
var mode_squash_3x : screen_mode_t = screen_mode_t(width = 800, height = 600, InitMode = @@I_InitSquashTable, DrawScreen = @@I_Squash3x, poor_quality = 0u)

[sideeffects]
def private WriteSquashedLine4x(var dest_10 : uint8?; var src_6 : uint8?) {
    var x_15 : int
    var c_1 : int
    var dest2_1 : uint8?
    var dest3_0 : uint8?
    var dest4 : uint8?
    dest2_1 = unsafe(reinterpret<uint8?>(unsafe(dest_10 + dest_pitch)))
    dest3_0 = unsafe(reinterpret<uint8?>(unsafe(dest_10 + int64(dest_pitch * 2))))
    dest4 = unsafe(reinterpret<uint8?>(unsafe(dest_10 + int64(dest_pitch * 3))))
    var c2da_dest_10_addr : uint64 = unsafe(reinterpret<uint64>(dest_10))
    var c2da_dest2_1_addr : uint64 = unsafe(reinterpret<uint64>(dest2_1))
    var c2da_dest3_0_addr : uint64 = unsafe(reinterpret<uint64>(dest3_0))
    var c2da_dest4_addr : uint64 = unsafe(reinterpret<uint64>(dest4))
    var c2da_src_6_addr : uint64 = unsafe(reinterpret<uint64>(src_6))
    x_15 = 0
    while (x_15 < 320) {
        c_1 = int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_6_addr))[0]))
        *unsafe(reinterpret<uint8?>(c2da_dest4_addr)) = uint8(c_1)
        *unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_10_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)))  // nolint:PERF020
        c2da_dest_10_addr++
        c2da_dest2_1_addr++
        c2da_dest3_0_addr++
        c2da_dest4_addr++
        *unsafe(reinterpret<uint8?>(c2da_dest4_addr)) = uint8(c_1)
        *unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_10_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)))  // nolint:PERF020
        c2da_dest_10_addr++
        c2da_dest2_1_addr++
        c2da_dest3_0_addr++
        c2da_dest4_addr++
        *unsafe(reinterpret<uint8?>(c2da_dest4_addr)) = uint8(c_1)
        *unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_10_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)))  // nolint:PERF020
        c2da_dest_10_addr++
        c2da_dest2_1_addr++
        c2da_dest3_0_addr++
        c2da_dest4_addr++
        c_1 = int(unsafe(unsafe(reinterpret<uint8?>(stretch_tables[0]))[int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_6_addr))[0])) * 256 + int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_6_addr))[1]))]))
        *unsafe(reinterpret<uint8?>(c2da_dest4_addr)) = uint8(c_1)
        *unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_10_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)))  // nolint:PERF020
        c2da_dest_10_addr++
        c2da_dest2_1_addr++
        c2da_dest3_0_addr++
        c2da_dest4_addr++
        c_1 = int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_6_addr))[1]))
        *unsafe(reinterpret<uint8?>(c2da_dest4_addr)) = uint8(c_1)
        *unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_10_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)))  // nolint:PERF020
        c2da_dest_10_addr++
        c2da_dest2_1_addr++
        c2da_dest3_0_addr++
        c2da_dest4_addr++
        *unsafe(reinterpret<uint8?>(c2da_dest4_addr)) = uint8(c_1)
        *unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_10_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)))  // nolint:PERF020
        c2da_dest_10_addr++
        c2da_dest2_1_addr++
        c2da_dest3_0_addr++
        c2da_dest4_addr++
        c_1 = int(unsafe(unsafe(reinterpret<uint8?>(stretch_tables[1]))[int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_6_addr))[1])) * 256 + int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_6_addr))[2]))]))
        *unsafe(reinterpret<uint8?>(c2da_dest4_addr)) = uint8(c_1)
        *unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_10_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)))  // nolint:PERF020
        c2da_dest_10_addr++
        c2da_dest2_1_addr++
        c2da_dest3_0_addr++
        c2da_dest4_addr++
        c_1 = int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_6_addr))[2]))
        *unsafe(reinterpret<uint8?>(c2da_dest4_addr)) = uint8(c_1)
        *unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_10_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)))  // nolint:PERF020
        c2da_dest_10_addr++
        c2da_dest2_1_addr++
        c2da_dest3_0_addr++
        c2da_dest4_addr++
        *unsafe(reinterpret<uint8?>(c2da_dest4_addr)) = uint8(c_1)
        *unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_10_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)))  // nolint:PERF020
        c2da_dest_10_addr++
        c2da_dest2_1_addr++
        c2da_dest3_0_addr++
        c2da_dest4_addr++
        c_1 = int(unsafe(unsafe(reinterpret<uint8?>(stretch_tables[1]))[int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_6_addr))[3])) * 256 + int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_6_addr))[2]))]))
        *unsafe(reinterpret<uint8?>(c2da_dest4_addr)) = uint8(c_1)
        *unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_10_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)))  // nolint:PERF020
        c2da_dest_10_addr++
        c2da_dest2_1_addr++
        c2da_dest3_0_addr++
        c2da_dest4_addr++
        c_1 = int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_6_addr))[3]))
        *unsafe(reinterpret<uint8?>(c2da_dest4_addr)) = uint8(c_1)
        *unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_10_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)))  // nolint:PERF020
        c2da_dest_10_addr++
        c2da_dest2_1_addr++
        c2da_dest3_0_addr++
        c2da_dest4_addr++
        *unsafe(reinterpret<uint8?>(c2da_dest4_addr)) = uint8(c_1)
        *unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_10_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)))  // nolint:PERF020
        c2da_dest_10_addr++
        c2da_dest2_1_addr++
        c2da_dest3_0_addr++
        c2da_dest4_addr++
        c_1 = int(unsafe(unsafe(reinterpret<uint8?>(stretch_tables[0]))[int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_6_addr))[4])) * 256 + int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_6_addr))[3]))]))
        *unsafe(reinterpret<uint8?>(c2da_dest4_addr)) = uint8(c_1)
        *unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_10_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)))  // nolint:PERF020
        c2da_dest_10_addr++
        c2da_dest2_1_addr++
        c2da_dest3_0_addr++
        c2da_dest4_addr++
        c_1 = int(unsafe(unsafe(reinterpret<uint8?>(c2da_src_6_addr))[4]))
        *unsafe(reinterpret<uint8?>(c2da_dest4_addr)) = uint8(c_1)
        *unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_10_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)))  // nolint:PERF020
        c2da_dest_10_addr++
        c2da_dest2_1_addr++
        c2da_dest3_0_addr++
        c2da_dest4_addr++
        *unsafe(reinterpret<uint8?>(c2da_dest4_addr)) = uint8(c_1)
        *unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_10_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)))  // nolint:PERF020
        c2da_dest_10_addr++
        c2da_dest2_1_addr++
        c2da_dest3_0_addr++
        c2da_dest4_addr++
        *unsafe(reinterpret<uint8?>(c2da_dest4_addr)) = uint8(c_1)
        *unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_10_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_1_addr)))  // nolint:PERF020
        c2da_dest_10_addr++
        c2da_dest2_1_addr++
        c2da_dest3_0_addr++
        c2da_dest4_addr++
        x_15 += 5
        c2da_src_6_addr += 5ul
    }
    return
}
[sideeffects]
def private I_Squash4x(var x1_12 : int; var y1_12 : int; var x2_12 : int; var y2_12 : int) : uint {
    var bufp_12 : uint8?
    var screenp_12 : uint8?
    if (x1_12 != 0 || y1_12 != 0 || x2_12 != 320 || y2_12 != 200) {
        return 0u
    }
    bufp_12 = unsafe(reinterpret<uint8?>(src_buffer))
    screenp_12 = unsafe(reinterpret<uint8?>(dest_buffer))
    for (y_13 in range(0, 200)) {
        WriteSquashedLine4x(screenp_12, bufp_12)
        unsafe {  // nolint:STYLE025
            screenp_12 += int64(dest_pitch * 4)
        }
        unsafe {  // nolint:STYLE025
            bufp_12 += 320
        }
    }
    return 1u
}
var mode_squash_4x : screen_mode_t = screen_mode_t(width = 256 * 4, height = 200 * 4, InitMode = @@I_InitStretchTables, DrawScreen = @@I_Squash4x, poor_quality = 0u)

[sideeffects]
def private WriteSquashedLine5x(var dest_11 : uint8?; var src_7 : uint8?) {
    var c_2 : int
    var dest2_2 : uint8?
    var dest3_1 : uint8?
    var dest4_0 : uint8?
    var dest5 : uint8?
    dest2_2 = unsafe(reinterpret<uint8?>(unsafe(dest_11 + dest_pitch)))
    dest3_1 = unsafe(reinterpret<uint8?>(unsafe(dest_11 + int64(dest_pitch * 2))))
    dest4_0 = unsafe(reinterpret<uint8?>(unsafe(dest_11 + int64(dest_pitch * 3))))
    dest5 = unsafe(reinterpret<uint8?>(unsafe(dest_11 + int64(dest_pitch * 4))))
    var c2da_src_7_addr : uint64 = unsafe(reinterpret<uint64>(src_7))
    var c2da_dest_11_addr : uint64 = unsafe(reinterpret<uint64>(dest_11))
    var c2da_dest2_2_addr : uint64 = unsafe(reinterpret<uint64>(dest2_2))
    var c2da_dest3_1_addr : uint64 = unsafe(reinterpret<uint64>(dest3_1))
    var c2da_dest4_0_addr : uint64 = unsafe(reinterpret<uint64>(dest4_0))
    var c2da_dest5_addr : uint64 = unsafe(reinterpret<uint64>(dest5))
    for (x_16 in range(0, 320)) {
        c_2 = int(*unsafe(reinterpret<uint8?>(c2da_src_7_addr)))
        c2da_src_7_addr++
        *unsafe(reinterpret<uint8?>(c2da_dest5_addr)) = uint8(c_2)
        *unsafe(reinterpret<uint8?>(c2da_dest4_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest5_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest3_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_2_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_1_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_11_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_2_addr)))  // nolint:PERF020
        c2da_dest_11_addr++
        c2da_dest2_2_addr++
        c2da_dest3_1_addr++
        c2da_dest4_0_addr++
        c2da_dest5_addr++
        *unsafe(reinterpret<uint8?>(c2da_dest5_addr)) = uint8(c_2)
        *unsafe(reinterpret<uint8?>(c2da_dest4_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest5_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest3_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_2_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_1_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_11_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_2_addr)))  // nolint:PERF020
        c2da_dest_11_addr++
        c2da_dest2_2_addr++
        c2da_dest3_1_addr++
        c2da_dest4_0_addr++
        c2da_dest5_addr++
        *unsafe(reinterpret<uint8?>(c2da_dest5_addr)) = uint8(c_2)
        *unsafe(reinterpret<uint8?>(c2da_dest4_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest5_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest3_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_2_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_1_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_11_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_2_addr)))  // nolint:PERF020
        c2da_dest_11_addr++
        c2da_dest2_2_addr++
        c2da_dest3_1_addr++
        c2da_dest4_0_addr++
        c2da_dest5_addr++
        *unsafe(reinterpret<uint8?>(c2da_dest5_addr)) = uint8(c_2)
        *unsafe(reinterpret<uint8?>(c2da_dest4_0_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest5_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest3_1_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest4_0_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest2_2_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest3_1_addr)))  // nolint:PERF020
        *unsafe(reinterpret<uint8?>(c2da_dest_11_addr)) = uint8(*unsafe(reinterpret<uint8?>(c2da_dest2_2_addr)))  // nolint:PERF020
        c2da_dest_11_addr++
        c2da_dest2_2_addr++
        c2da_dest3_1_addr++
        c2da_dest4_0_addr++
        c2da_dest5_addr++
    }
    return
}
[sideeffects]
def private I_Squash5x(var x1_13 : int; var y1_13 : int; var x2_13 : int; var y2_13 : int) : uint {
    var bufp_13 : uint8?
    var screenp_13 : uint8?
    if (x1_13 != 0 || y1_13 != 0 || x2_13 != 320 || y2_13 != 200) {
        return 0u
    }
    bufp_13 = unsafe(reinterpret<uint8?>(src_buffer))
    screenp_13 = unsafe(reinterpret<uint8?>(dest_buffer))
    for (y_14 in range(0, 200)) {
        WriteSquashedLine5x(screenp_13, bufp_13)
        unsafe {  // nolint:STYLE025
            screenp_13 += int64(dest_pitch * 5)
        }
        unsafe {  // nolint:STYLE025
            bufp_13 += 320
        }
    }
    return 1u
}
var mode_squash_5x : screen_mode_t = screen_mode_t(width = 256 * 5, height = 200 * 5, InitMode = @@I_InitStretchTables, DrawScreen = @@I_Squash5x, poor_quality = 0u)

[sideeffects]
def private c2da_layout_proofs() {
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
    static_assert(typeinfo sizeof(type<screen_mode_t>) == 32, "C layout of screen_mode_t: sizeof")
    static_assert(typeinfo alignof(type<screen_mode_t>) == 8, "C layout of screen_mode_t: alignof")
    static_assert(typeinfo offsetof<width>(type<screen_mode_t>) == 0, "C layout of screen_mode_t: offsetof width")
    static_assert(typeinfo offsetof<height>(type<screen_mode_t>) == 4, "C layout of screen_mode_t: offsetof height")
    static_assert(typeinfo offsetof<InitMode>(type<screen_mode_t>) == 8, "C layout of screen_mode_t: offsetof InitMode")
    static_assert(typeinfo offsetof<DrawScreen>(type<screen_mode_t>) == 16, "C layout of screen_mode_t: offsetof DrawScreen")
    static_assert(typeinfo offsetof<poor_quality>(type<screen_mode_t>) == 24, "C layout of screen_mode_t: offsetof poor_quality")
}
