options gen2
options stack = 4194304
module statdump public

require c2da_runtime
require m_argv
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
def StatCopy(var stats : int) {
    if (M_ParmExists(371248) != 0x0 && num_captured_stats < 32) {
        c2da_lin_memcpy(364848 + num_captured_stats * 200, stats, 200ul)
        num_captured_stats++
    }
    return
}
var private num_captured_stats : int = 0

[export, sideeffects]
def StatDump() {
    return
}

// This unit's static data, at heap offset 364848.
let private c2da_lin_static_statdump_seg = fixed_array<int>(371248, 9)
let private c2da_lin_static_statdump = fixed_array<uint64>(0x6d7564746174732dul, 0x70ul)

[init]
def private c2da_lin_init_static_statdump() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_statdump_seg[s * 2]
        for (k in range(c2da_lin_static_statdump_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_statdump[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_statdump() {
    if (length(c2da_fn_table0) < 6) {
        resize(c2da_fn_table0, 6)
    }
    c2da_fn_table0[5] = @@StatDump
}

[init]
def private c2da_lin_relink_init_statdump() {
    c2da_relink_statdump()
}
