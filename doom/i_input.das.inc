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

var private shiftxform : int8[128] const = fixed_array<int8>(int8(0), int8(1), int8(2), int8(3), int8(4), int8(5), int8(6), int8(7), int8(8), int8(9), int8(10), int8(11), int8(12), int8(13), int8(14), int8(15), int8(16), int8(17), int8(18), int8(19), int8(20), int8(21), int8(22), int8(23), int8(24), int8(25), int8(26), int8(27), int8(28), int8(29), int8(30), int8(31), int8(32), int8(33), int8(34), int8(35), int8(36), int8(37), int8(38), int8(34), int8(40), int8(41), int8(42), int8(43), int8(60), int8(95), int8(62), int8(63), int8(41), int8(33), int8(64), int8(35), int8(36), int8(37), int8(94), int8(38), int8(42), int8(40), int8(58), int8(58), int8(60), int8(43), int8(62), int8(63), int8(64), int8(65), int8(66), int8(67), int8(68), int8(69), int8(70), int8(71), int8(72), int8(73), int8(74), int8(75), int8(76), int8(77), int8(78), int8(79), int8(80), int8(81), int8(82), int8(83), int8(84), int8(85), int8(86), int8(87), int8(88), int8(89), int8(90), int8(91), int8(33), int8(93), int8(34), int8(95), int8(39), int8(65), int8(66), int8(67), int8(68), int8(69), int8(70), int8(71), int8(72), int8(73), int8(74), int8(75), int8(76), int8(77), int8(78), int8(79), int8(80), int8(81), int8(82), int8(83), int8(84), int8(85), int8(86), int8(87), int8(88), int8(89), int8(90), int8(123), int8(124), int8(125), int8(126), int8(127))

[sideeffects]
def private TranslateKey(var key : uint8) : uint8 {
    return key
}
[sideeffects]
def private GetTypedChar(var key_0 : uint8) : uint8 {
    key_0 = uint8(key_0)  // nolint:PERF020
    if (shiftdown > 0) {
        if (int(key_0) >= 0 && uint64(key_0) < 128ul / 1ul) {
            key_0 = uint8(shiftxform[int(key_0)])
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
    var event : event_t = event_t()
    var pressed_0 : int
    var key_2 : uint8
    while (DG_GetKey(unsafe(addr<int?>(pressed_0)), unsafe(addr<uint8?>(key_2))) != 0) {
        UpdateShiftStatus(pressed_0, key_2)
        if (pressed_0 != 0) {
            event.type_0 = unsafe(reinterpret<evtype_t>(0u))
            event.data1 = int(key_2)
            event.data2 = int(GetTypedChar(key_2))
            if (event.data1 != 0) {
                D_PostEvent(unsafe(addr<event_t?>(event)))
            }
        } else {
            event.type_0 = unsafe(reinterpret<evtype_t>(1u))
            event.data1 = int(key_2)
            event.data2 = 0
            if (event.data1 != 0) {
                D_PostEvent(unsafe(addr<event_t?>(event)))
            }
            break
        }
    }
    return
}
[export, sideeffects]
def I_InitInput() {
    return
}
[sideeffects]
def private c2da_layout_proofs_42() {
    static_assert(typeinfo sizeof(type<event_t>) == 20, "C layout of event_t: sizeof")
    static_assert(typeinfo alignof(type<event_t>) == 4, "C layout of event_t: alignof")
    static_assert(typeinfo offsetof<type_0>(type<event_t>) == 0, "C layout of event_t: offsetof type_0")
    static_assert(typeinfo offsetof<data1>(type<event_t>) == 4, "C layout of event_t: offsetof data1")
    static_assert(typeinfo offsetof<data2>(type<event_t>) == 8, "C layout of event_t: offsetof data2")
    static_assert(typeinfo offsetof<data3>(type<event_t>) == 12, "C layout of event_t: offsetof data3")
    static_assert(typeinfo offsetof<data4>(type<event_t>) == 16, "C layout of event_t: offsetof data4")
}
