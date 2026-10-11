[sideeffects]
def private c2da___bswap_16_17(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_17(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_17(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_17(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_17(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_17(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
[export, sideeffects]
def W_Checksum(var digest : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    W_Checksum_c2da_frame(digest, c2da_lin_enter(96))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private ChecksumAddLump(var sha1_context : int; var lump : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    ChecksumAddLump_c2da_frame(sha1_context, lump, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private GetFileNumber(var handle : int) : int {
    var i_0 : int
    var result_0 : int
    i_0 = 0
    while (i_0 < num_open_wadfiles) {
        if (int(uint(c2da_mem[open_wadfiles + i_0 * 8]) | uint(c2da_mem[open_wadfiles + i_0 * 8 + 1]) << 0x8 | uint(c2da_mem[open_wadfiles + i_0 * 8 + 2]) << 0x10 | uint(c2da_mem[open_wadfiles + i_0 * 8 + 3]) << 0x18) == handle) {
            return i_0
        }
        i_0++
    }
    open_wadfiles = c2da_lin_realloc(open_wadfiles, 8ul * uint64(num_open_wadfiles + 1))
    let c2da_fresh0 : uint = uint(handle)
    c2da_mem[open_wadfiles + num_open_wadfiles * 8] = uint8(c2da_fresh0)
    c2da_mem[open_wadfiles + num_open_wadfiles * 8 + 1] = uint8(c2da_fresh0 >> 0x8)
    c2da_mem[open_wadfiles + num_open_wadfiles * 8 + 2] = uint8(c2da_fresh0 >> 0x10)
    c2da_mem[open_wadfiles + num_open_wadfiles * 8 + 3] = uint8(c2da_fresh0 >> 0x18)
    c2da_mem[open_wadfiles + num_open_wadfiles * 8 + 4] = 0u8
    c2da_mem[open_wadfiles + num_open_wadfiles * 8 + 5] = 0u8
    c2da_mem[open_wadfiles + num_open_wadfiles * 8 + 6] = 0u8
    c2da_mem[open_wadfiles + num_open_wadfiles * 8 + 7] = 0u8
    result_0 = num_open_wadfiles
    num_open_wadfiles++
    return result_0
}
var private num_open_wadfiles : int = 0

var private open_wadfiles : int = 0

[sideeffects]
def private W_Checksum_c2da_frame(var digest : int; c2da_fp : int) {
    var i : uint
    SHA1_Init(c2da_fp)
    num_open_wadfiles = 0
    i = 0u
    while (i < numlumps) {
        ChecksumAddLump(c2da_fp, lumpinfo + int(i) * 40)
        i++
    }
    SHA1_Final(digest, c2da_fp)
    return
}
[sideeffects]
def private ChecksumAddLump_c2da_frame(var sha1_context : int; var lump : int; c2da_fp : int) {
    M_StringCopy(c2da_fp, lump, 9ul)
    SHA1_UpdateString(sha1_context, c2da_fp)
    SHA1_UpdateInt32(sha1_context, uint(GetFileNumber(int(uint(c2da_mem[lump + 8]) | uint(c2da_mem[lump + 9]) << 0x8 | uint(c2da_mem[lump + 10]) << 0x10 | uint(c2da_mem[lump + 11]) << 0x18))))
    SHA1_UpdateInt32(sha1_context, uint(int(uint(c2da_mem[lump + 16]) | uint(c2da_mem[lump + 17]) << 0x8 | uint(c2da_mem[lump + 18]) << 0x10 | uint(c2da_mem[lump + 19]) << 0x18)))
    SHA1_UpdateInt32(sha1_context, uint(int(uint(c2da_mem[lump + 20]) | uint(c2da_mem[lump + 21]) << 0x8 | uint(c2da_mem[lump + 22]) << 0x10 | uint(c2da_mem[lump + 23]) << 0x18)))
    return
}
