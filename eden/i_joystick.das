options gen2
options stack = 4194304
module i_joystick public

require c2da_runtime
require i_system_cluster
require m_config
require daslib/math_bits
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
    let c2da_saved_sp : int = c2da_lin_sp
    I_BindJoystickVariables_c2da_frame(c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private I_BindJoystickVariables_c2da_frame(c2da_fp : int) {
    M_BindVariable(345016, 344848)
    M_BindVariable(345029, 344864)
    M_BindVariable(345044, 344880)
    M_BindVariable(345060, 344896)
    M_BindVariable(345076, 344912)
    M_BindVariable(345097, 344928)
    M_BindVariable(345115, 344944)
    M_BindVariable(345133, 344960)
    for (i in range(0, 10)) {
        M_snprintf(c2da_fp, 32ul, 345156, [C2daVaArg(tag = 1, i64 = int64(i), f64 = 0.0lf, raw = 0x0)])
        M_BindVariable(c2da_fp, 344976 + i * 4)
    }
    return
}

// This unit's static data, at heap offset 344848.
let private c2da_lin_static_i_joystick_seg = fixed_array<int>(344864, 4, 344896, 20, 344980, 202)
let private c2da_lin_static_i_joystick = fixed_array<uint64>(0x1fffffffful, 0x0ul, 0xffffffff00000000ul, 0x200000001ul, 0x400000003ul, 0x600000005ul, 0x800000007ul, 0x5f65737500000009ul, 0x6b63697473796f6aul, 0x63697473796f6a00ul, 0x7865646e695f6bul, 0x6b63697473796f6aul, 0x736978615f785ful, 0x6b63697473796f6aul, 0x736978615f795ful, 0x6b63697473796f6aul, 0x5f6566617274735ful, 0x796f6a0073697861ul, 0x5f785f6b63697473ul, 0x6a00747265766e69ul, 0x5f6b63697473796ful, 0x747265766e695f79ul, 0x63697473796f6a00ul, 0x6566617274735f6bul, 0x747265766e695ful, 0x6b63697473796f6aul, 0x616369737968705ful, 0x6e6f747475625f6cul, 0x6925ul)

[init]
def private c2da_lin_init_static_i_joystick() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(3)) {
        let at = c2da_lin_static_i_joystick_seg[s * 2]
        for (k in range(c2da_lin_static_i_joystick_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_i_joystick[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
