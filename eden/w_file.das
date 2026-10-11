options gen2
options stack = 4194304
module w_file public

require c2da_runtime
require m_argv
require w_file_stdc
require daslib/math_bits
[export, sideeffects]
def W_OpenFile(var path : int) : int {
    var result_0 : int
    var i : int
    if (M_CheckParm(376776) == 0) {
        return invoke(c2da_fn_table7[int(uint(c2da_mem[298896]) | uint(c2da_mem[298897]) << 0x8 | uint(c2da_mem[298898]) << 0x10 | uint(c2da_mem[298899]) << 0x18)], path)
    }
    result_0 = 0
    i = 0
    while (uint64(i) < 8ul / 8ul) {
        let c2da_fresh0 : int = int(uint(c2da_mem[376768 + i * 8]) | uint(c2da_mem[376768 + i * 8 + 1]) << 0x8 | uint(c2da_mem[376768 + i * 8 + 2]) << 0x10 | uint(c2da_mem[376768 + i * 8 + 3]) << 0x18)
        result_0 = invoke(c2da_fn_table7[int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18)], path)
        if (result_0 != 0) {
            break
        }
        i++
    }
    return result_0
}
[export, sideeffects]
def W_CloseFile(var wad : int) {
    let c2da_fresh1 : int = int(uint(c2da_mem[wad]) | uint(c2da_mem[wad + 1]) << 0x8 | uint(c2da_mem[wad + 2]) << 0x10 | uint(c2da_mem[wad + 3]) << 0x18) + 8
    invoke(c2da_fn_table5[int(uint(c2da_mem[c2da_fresh1]) | uint(c2da_mem[c2da_fresh1 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh1 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh1 + 3]) << 0x18)], wad)
    return
}
[export, sideeffects]
def W_Read(var wad_0 : int; var offset : uint; var buffer : int; var buffer_len : uint64) : uint64 {
    let c2da_fresh2 : int = int(uint(c2da_mem[wad_0]) | uint(c2da_mem[wad_0 + 1]) << 0x8 | uint(c2da_mem[wad_0 + 2]) << 0x10 | uint(c2da_mem[wad_0 + 3]) << 0x18) + 16
    return invoke(c2da_fn_table14[int(uint(c2da_mem[c2da_fresh2]) | uint(c2da_mem[c2da_fresh2 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh2 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh2 + 3]) << 0x18)], wad_0, offset, buffer, buffer_len)
}

// This unit's static data, at heap offset 376768.
let private c2da_lin_static_w_file_seg = fixed_array<int>(376768, 13)
let private c2da_lin_static_w_file = fixed_array<uint64>(0x48f90ul, 0x70616d6d2dul)

[init]
def private c2da_lin_init_static_w_file() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_w_file_seg[s * 2]
        for (k in range(c2da_lin_static_w_file_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_w_file[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
