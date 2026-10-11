[sideeffects]
def private c2da___bswap_16_19(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_19(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_19(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_19(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_19(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_19(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
var vanilla_keyboard_mapping : int = 1

var private shiftdown : int = 0

[sideeffects]
def private TranslateKey(var key : uint8) : uint8 {
    return key
}
[sideeffects]
def private GetTypedChar(var key_0 : uint8) : uint8 {
    key_0 = uint8(key_0)  // nolint:PERF020
    if (shiftdown > 0) {
        if (int(key_0) >= 0 && uint64(key_0) < 128ul / 1ul) {
            key_0 = uint8(int8(c2da_mem[378112 + int(key_0)]))
        } else {
            key_0 = 0u8
        }
    }
    return key_0
}
[sideeffects]
def private UpdateShiftStatus(var pressed : int; var key_1 : uint8) {
    var change : int
    if (pressed != 0) {
        change = 1
    } else {
        change = -1
    }
    if (int(key_1) == 128 + 54) {
        shiftdown += change
    }
    return
}
[export, sideeffects]
def I_GetEvent() {
    let c2da_saved_sp : int = c2da_lin_sp
    I_GetEvent_c2da_frame(c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def I_InitInput() {
    return
}
[sideeffects]
def private I_GetEvent_c2da_frame(c2da_fp : int) {
    while (DG_GetKey(c2da_fp, c2da_fp + 16) != 0) {
        UpdateShiftStatus(int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18), c2da_mem[c2da_fp + 16])
        if (int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) != 0) {
            let c2da_fresh0 : uint = 0u
            let c2da_fresh1 : uint = c2da_fresh0
            c2da_mem[c2da_fp + 32] = uint8(c2da_fresh1)
            c2da_mem[c2da_fp + 33] = uint8(c2da_fresh1 >> 0x8)
            c2da_mem[c2da_fp + 34] = uint8(c2da_fresh1 >> 0x10)
            c2da_mem[c2da_fp + 35] = uint8(c2da_fresh1 >> 0x18)
            let c2da_fresh2 : uint8 = c2da_mem[c2da_fp + 16]
            let c2da_fresh3 : int = int(c2da_fresh2)
            let c2da_fresh4 : uint = uint(c2da_fresh3)
            c2da_mem[c2da_fp + 36] = uint8(c2da_fresh4)
            c2da_mem[c2da_fp + 37] = uint8(c2da_fresh4 >> 0x8)
            c2da_mem[c2da_fp + 38] = uint8(c2da_fresh4 >> 0x10)
            c2da_mem[c2da_fp + 39] = uint8(c2da_fresh4 >> 0x18)
            let c2da_fresh5 : int = int(GetTypedChar(c2da_mem[c2da_fp + 16]))
            let c2da_fresh6 : uint = uint(c2da_fresh5)
            c2da_mem[c2da_fp + 40] = uint8(c2da_fresh6)
            c2da_mem[c2da_fp + 41] = uint8(c2da_fresh6 >> 0x8)
            c2da_mem[c2da_fp + 42] = uint8(c2da_fresh6 >> 0x10)
            c2da_mem[c2da_fp + 43] = uint8(c2da_fresh6 >> 0x18)
            if (int(uint(c2da_mem[c2da_fp + 36]) | uint(c2da_mem[c2da_fp + 37]) << 0x8 | uint(c2da_mem[c2da_fp + 38]) << 0x10 | uint(c2da_mem[c2da_fp + 39]) << 0x18) != 0) {
                D_PostEvent(c2da_fp + 32)
            }
        } else {
            let c2da_fresh7 : uint = 1u
            let c2da_fresh8 : uint = c2da_fresh7
            c2da_mem[c2da_fp + 32] = uint8(c2da_fresh8)
            c2da_mem[c2da_fp + 33] = uint8(c2da_fresh8 >> 0x8)
            c2da_mem[c2da_fp + 34] = uint8(c2da_fresh8 >> 0x10)
            c2da_mem[c2da_fp + 35] = uint8(c2da_fresh8 >> 0x18)
            let c2da_fresh9 : uint8 = c2da_mem[c2da_fp + 16]
            let c2da_fresh10 : int = int(c2da_fresh9)
            let c2da_fresh11 : uint = uint(c2da_fresh10)
            c2da_mem[c2da_fp + 36] = uint8(c2da_fresh11)
            c2da_mem[c2da_fp + 37] = uint8(c2da_fresh11 >> 0x8)
            c2da_mem[c2da_fp + 38] = uint8(c2da_fresh11 >> 0x10)
            c2da_mem[c2da_fp + 39] = uint8(c2da_fresh11 >> 0x18)
            let c2da_fresh12 : int = 0
            let c2da_fresh13 : uint = uint(c2da_fresh12)
            c2da_mem[c2da_fp + 40] = uint8(c2da_fresh13)
            c2da_mem[c2da_fp + 41] = uint8(c2da_fresh13 >> 0x8)
            c2da_mem[c2da_fp + 42] = uint8(c2da_fresh13 >> 0x10)
            c2da_mem[c2da_fp + 43] = uint8(c2da_fresh13 >> 0x18)
            if (int(uint(c2da_mem[c2da_fp + 36]) | uint(c2da_mem[c2da_fp + 37]) << 0x8 | uint(c2da_mem[c2da_fp + 38]) << 0x10 | uint(c2da_mem[c2da_fp + 39]) << 0x18) != 0) {
                D_PostEvent(c2da_fp + 32)
            }
            break
        }
    }
    return
}

// This unit's static data, at heap offset 378112.
let private c2da_lin_static_i_input_seg = fixed_array<int>(378113, 127)
let private c2da_lin_static_i_input = fixed_array<uint64>(0x807060504030201ul, 0x100f0e0d0c0b0a09ul, 0x1817161514131211ul, 0x201f1e1d1c1b1a19ul, 0x2822262524232221ul, 0x293f3e5f3c2b2a29ul, 0x2a265e2524234021ul, 0x403f3e2b3c3a3a28ul, 0x4847464544434241ul, 0x504f4e4d4c4b4a49ul, 0x5857565554535251ul, 0x275f225d215b5a59ul, 0x4847464544434241ul, 0x504f4e4d4c4b4a49ul, 0x5857565554535251ul, 0x7f7e7d7c7b5a59ul)

[init]
def private c2da_lin_init_static_i_input() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_i_input_seg[s * 2]
        for (k in range(c2da_lin_static_i_input_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_i_input[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
