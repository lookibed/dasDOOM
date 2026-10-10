[sideeffects]
def private c2da___bswap_16_22(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_22(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_22(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_22(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_22(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_22(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
[export, sideeffects]
def DG_Init() {
    return
}
[export, sideeffects]
def DG_DrawFrame() {
    if (dg_frame_count < 4096) {
        dg_frame_hash[dg_frame_count] = int(dg_hash_frame())
    }
    dg_frame_count++
    return
}
var dg_frame_count : int = 0

[sideeffects]
def private dg_hash_frame() : uint {
    var hash : uint
    var i : int
    var c : color
    var rgb : uint
    hash = 2166136261u
    i = 0
    i = 0
    for (c2da_i in range(i, 320 * 200)) {
        c = colors[int(unsafe(DG_ScreenBuffer[c2da_i]))]
        rgb = (c.c2da_bits_0 >> 16 & 0xff) << 16u | (c.c2da_bits_0 >> 8 & 0xff) << 8u | c.c2da_bits_0 & 0xff
        hash = (hash ^ rgb) * 16777619u
    }
    return hash
}
var dg_frame_hash : int[4096]

[export, sideeffects]
def DG_SleepMs(var ms : uint) {
    dg_virtual_ms += ms
    return
}
var private dg_virtual_ms : uint = 1000u

[export, sideeffects]
def DG_GetTicksMs() : uint {
    return dg_virtual_ms
}
[export, sideeffects]
def DG_GetKey(var pressed : int?; var key : uint8?) : int {
    return 0
}
[export, sideeffects]
def DG_SetWindowTitle(var title_0 : int8 const?) {
    return
}
[export, sideeffects]
def dg_advance_clock() {
    dg_virtual_ms += 28u
    return
}
[sideeffects]
def private c2da_layout_proofs_44() {
    static_assert(typeinfo sizeof(type<color>) == 4, "C layout of color: sizeof")
    static_assert(typeinfo alignof(type<color>) == 4, "C layout of color: alignof")
    static_assert(typeinfo offsetof<c2da_bits_0>(type<color>) == 0, "C layout of color: offsetof c2da_bits_0")
}
