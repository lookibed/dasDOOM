options gen2
options stack = 4194304
module w_file_stdc public

require c2da_runtime
require i_system_cluster
require strings
require daslib/math_bits
[export, sideeffects]
def W_StdC_Read(var wad : int; var offset : uint; var buffer : int; var buffer_len : uint64) : uint64 {
    var stdc_wad : int
    var result_0 : uint64
    stdc_wad = wad
    c2da_std_fseek(uint64(int(uint(c2da_mem[stdc_wad + 24]) | uint(c2da_mem[stdc_wad + 25]) << 0x8 | uint(c2da_mem[stdc_wad + 26]) << 0x10 | uint(c2da_mem[stdc_wad + 27]) << 0x18)), int64(offset), 0)
    result_0 = uint64(c2da_lin_fread(buffer, 1ul, buffer_len, uint64(int(uint(c2da_mem[stdc_wad + 24]) | uint(c2da_mem[stdc_wad + 25]) << 0x8 | uint(c2da_mem[stdc_wad + 26]) << 0x10 | uint(c2da_mem[stdc_wad + 27]) << 0x18))))
    return result_0
}
[sideeffects]
def private W_StdC_CloseFile(var wad_0 : int) {
    var stdc_wad_0 : int = wad_0
    c2da_std_fclose(uint64(int(uint(c2da_mem[stdc_wad_0 + 24]) | uint(c2da_mem[stdc_wad_0 + 25]) << 0x8 | uint(c2da_mem[stdc_wad_0 + 26]) << 0x10 | uint(c2da_mem[stdc_wad_0 + 27]) << 0x18)))
    Z_Free(stdc_wad_0)
    return
}
[sideeffects]
def private W_StdC_OpenFile(var path : int) : int {
    var result_1 : int
    var fstream : int = c2da_lin_fopen(path, 378096)
    if (fstream == 0) {
        return 0
    }
    result_1 = Z_Malloc(32, 1, 0)
    let c2da_fresh0 : uint = 298896u
    c2da_mem[result_1] = uint8(c2da_fresh0)
    c2da_mem[result_1 + 1] = uint8(c2da_fresh0 >> 0x8)
    c2da_mem[result_1 + 2] = uint8(c2da_fresh0 >> 0x10)
    c2da_mem[result_1 + 3] = uint8(c2da_fresh0 >> 0x18)
    c2da_mem[result_1 + 4] = 0u8
    c2da_mem[result_1 + 5] = 0u8
    c2da_mem[result_1 + 6] = 0u8
    c2da_mem[result_1 + 7] = 0u8
    let c2da_fresh1 : uint = 0u
    c2da_mem[result_1 + 8] = uint8(c2da_fresh1)
    c2da_mem[result_1 + 9] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[result_1 + 10] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[result_1 + 11] = uint8(c2da_fresh1 >> 0x18)
    c2da_mem[result_1 + 12] = 0u8
    c2da_mem[result_1 + 13] = 0u8
    c2da_mem[result_1 + 14] = 0u8
    c2da_mem[result_1 + 15] = 0u8
    let c2da_fresh2 : uint = uint(M_FileLength(fstream))
    let c2da_fresh3 : uint = c2da_fresh2
    c2da_mem[result_1 + 16] = uint8(c2da_fresh3)
    c2da_mem[result_1 + 17] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[result_1 + 18] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[result_1 + 19] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : uint = uint(fstream)
    c2da_mem[result_1 + 24] = uint8(c2da_fresh4)
    c2da_mem[result_1 + 25] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[result_1 + 26] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[result_1 + 27] = uint8(c2da_fresh4 >> 0x18)
    c2da_mem[result_1 + 28] = 0u8
    c2da_mem[result_1 + 29] = 0u8
    c2da_mem[result_1 + 30] = 0u8
    c2da_mem[result_1 + 31] = 0u8
    return result_1
}

// This unit's static data, at heap offset 378096.
let private c2da_lin_static_w_file_stdc_seg = fixed_array<int>(378096, 2)
let private c2da_lin_static_w_file_stdc = fixed_array<uint64>(0x6272ul)

[init]
def private c2da_lin_init_static_w_file_stdc() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_w_file_stdc_seg[s * 2]
        for (k in range(c2da_lin_static_w_file_stdc_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_w_file_stdc[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_w_file_stdc_0 = fixed_array<uint8>(0xb1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x99, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_w_file_stdc() {
    c2da_lin_setup()
    for (i in range(24)) {
        c2da_mem[298896 + i] = c2da_lin_extern_w_file_stdc_0[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_w_file_stdc() {
    if (length(c2da_fn_table5) < 179) {
        resize(c2da_fn_table5, 179)
    }
    c2da_fn_table5[178] = @@W_StdC_CloseFile
    if (length(c2da_fn_table7) < 179) {
        resize(c2da_fn_table7, 179)
    }
    c2da_fn_table7[177] = @@W_StdC_OpenFile
    if (length(c2da_fn_table14) < 179) {
        resize(c2da_fn_table14, 179)
    }
    c2da_fn_table14[153] = @@W_StdC_Read
}

[init]
def private c2da_lin_relink_init_w_file_stdc() {
    c2da_relink_w_file_stdc()
}
