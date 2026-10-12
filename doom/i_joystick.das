options gen2
options solid_context = true
options stack = 4194304
module i_joystick public

require dasdoom_runtime
require i_system_cluster
require m_config
var private c2da_str_0 : array<int8> = [int8(117), int8(115), int8(101), int8(95), int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(0)]

var private c2da_str_1 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(105), int8(110), int8(100), int8(101), int8(120), int8(0)]

var private c2da_str_2 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(120), int8(95), int8(97), int8(120), int8(105), int8(115), int8(0)]

var private c2da_str_3 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(121), int8(95), int8(97), int8(120), int8(105), int8(115), int8(0)]

var private c2da_str_4 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(95), int8(97), int8(120), int8(105), int8(115), int8(0)]

var private c2da_str_5 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(120), int8(95), int8(105), int8(110), int8(118), int8(101), int8(114), int8(116), int8(0)]

var private c2da_str_6 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(121), int8(95), int8(105), int8(110), int8(118), int8(101), int8(114), int8(116), int8(0)]

var private c2da_str_7 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(95), int8(105), int8(110), int8(118), int8(101), int8(114), int8(116), int8(0)]

var private c2da_str_8 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(112), int8(104), int8(121), int8(115), int8(105), int8(99), int8(97), int8(108), int8(95), int8(98), int8(117), int8(116), int8(116), int8(111), int8(110), int8(37), int8(105), int8(0)]

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
[export, sideeffects]
def I_InitJoystick() {
    return
}
[export, sideeffects]
def I_ShutdownJoystick() {
    return
}
[export, sideeffects]
def I_UpdateJoystick() {
    return
}
[export, sideeffects]
def I_BindJoystickVariables() {
    var name : int8[32]
    M_BindVariable(unsafe(addr<int8?>(c2da_str_0[0])), unsafe(addr<uint8?>(usejoystick)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_1[0])), unsafe(addr<uint8?>(joystick_index)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_2[0])), unsafe(addr<uint8?>(joystick_x_axis)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_3[0])), unsafe(addr<uint8?>(joystick_y_axis)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_4[0])), unsafe(addr<uint8?>(joystick_strafe_axis)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_5[0])), unsafe(addr<uint8?>(joystick_x_invert)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_6[0])), unsafe(addr<uint8?>(joystick_y_invert)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_7[0])), unsafe(addr<uint8?>(joystick_strafe_invert)))
    for (i in range(0, 10)) {
        M_snprintf(unsafe(addr<int8?>(name[0])), 32ul, unsafe(addr<int8 const?>(c2da_str_8[0])), [C2daVaArg(tag = 1, i64 = int64(i), f64 = 0.0lf, raw = 0x0)])
        M_BindVariable(unsafe(addr<int8?>(name[0])), unsafe(addr<uint8?>(unsafe(unsafe(addr(joystick_physical_buttons[0]))[i]))))
    }
    return
}
var private joystick_physical_buttons : int[10] = fixed_array<int>(0, 1, 2, 3, 4, 5, 6, 7, 8, 9)

var private joystick_strafe_invert : int = 0

var private joystick_y_invert : int = 0

var private joystick_x_invert : int = 0

var private joystick_strafe_axis : int = -1

var private joystick_y_axis : int = 1

var private joystick_x_axis : int = 0

var private joystick_index : int = -1

var private usejoystick : int = 0

