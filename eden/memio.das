options gen2
options stack = 4194304
module memio public

require c2da_runtime
require i_system_cluster
require strings
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
def mem_fopen_read(var buf : int; var buflen : uint64) : int {
    var file : int = Z_Malloc(32, 1, 0)
    let c2da_fresh0 : uint = uint(buf)
    c2da_mem[file] = uint8(c2da_fresh0)
    c2da_mem[file + 1] = uint8(c2da_fresh0 >> 0x8)
    c2da_mem[file + 2] = uint8(c2da_fresh0 >> 0x10)
    c2da_mem[file + 3] = uint8(c2da_fresh0 >> 0x18)
    c2da_mem[file + 4] = 0u8
    c2da_mem[file + 5] = 0u8
    c2da_mem[file + 6] = 0u8
    c2da_mem[file + 7] = 0u8
    let c2da_fresh1 : uint64 = buflen
    c2da_mem[file + 8] = uint8(c2da_fresh1)
    c2da_mem[file + 9] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[file + 10] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[file + 11] = uint8(c2da_fresh1 >> 0x18)
    c2da_mem[file + 12] = uint8(c2da_fresh1 >> 0x20)
    c2da_mem[file + 13] = uint8(c2da_fresh1 >> 0x28)
    c2da_mem[file + 14] = uint8(c2da_fresh1 >> 0x30)
    c2da_mem[file + 15] = uint8(c2da_fresh1 >> 0x38)
    let c2da_fresh2 : uint = 0u
    let c2da_fresh3 : uint = c2da_fresh2
    c2da_mem[file + 24] = uint8(c2da_fresh3)
    c2da_mem[file + 25] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[file + 26] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[file + 27] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : uint = 0u
    let c2da_fresh5 : uint = c2da_fresh4
    c2da_mem[file + 28] = uint8(c2da_fresh5)
    c2da_mem[file + 29] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[file + 30] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[file + 31] = uint8(c2da_fresh5 >> 0x18)
    return file
}
[export, sideeffects]
def mem_fread(var buf_0 : int; var size : uint64; var nmemb : uint64; var stream : int) : uint64 {
    var items : uint64
    if ((uint(c2da_mem[stream + 28]) | uint(c2da_mem[stream + 29]) << 0x8 | uint(c2da_mem[stream + 30]) << 0x10 | uint(c2da_mem[stream + 31]) << 0x18) != 0u) {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 346256, [])
        return 0xfffffffffffffffful
    }
    items = nmemb
    if (items * size > (uint64(uint(c2da_mem[stream + 8]) | uint(c2da_mem[stream + 9]) << 0x8 | uint(c2da_mem[stream + 10]) << 0x10 | uint(c2da_mem[stream + 11]) << 0x18) | uint64(uint(c2da_mem[stream + 12]) | uint(c2da_mem[stream + 13]) << 0x8 | uint(c2da_mem[stream + 14]) << 0x10 | uint(c2da_mem[stream + 15]) << 0x18) << 0x20) - uint64(uint(c2da_mem[stream + 24]) | uint(c2da_mem[stream + 25]) << 0x8 | uint(c2da_mem[stream + 26]) << 0x10 | uint(c2da_mem[stream + 27]) << 0x18)) {
        items = uint64(((uint64(uint(c2da_mem[stream + 8]) | uint(c2da_mem[stream + 9]) << 0x8 | uint(c2da_mem[stream + 10]) << 0x10 | uint(c2da_mem[stream + 11]) << 0x18) | uint64(uint(c2da_mem[stream + 12]) | uint(c2da_mem[stream + 13]) << 0x8 | uint(c2da_mem[stream + 14]) << 0x10 | uint(c2da_mem[stream + 15]) << 0x18) << 0x20) - uint64(uint(c2da_mem[stream + 24]) | uint(c2da_mem[stream + 25]) << 0x8 | uint(c2da_mem[stream + 26]) << 0x10 | uint(c2da_mem[stream + 27]) << 0x18)) / size)
    }
    c2da_lin_memcpy(buf_0, int(uint(c2da_mem[stream]) | uint(c2da_mem[stream + 1]) << 0x8 | uint(c2da_mem[stream + 2]) << 0x10 | uint(c2da_mem[stream + 3]) << 0x18) + int(uint(c2da_mem[stream + 24]) | uint(c2da_mem[stream + 25]) << 0x8 | uint(c2da_mem[stream + 26]) << 0x10 | uint(c2da_mem[stream + 27]) << 0x18), items * size)
    let c2da_fresh6 : uint = uint(uint64(uint(c2da_mem[stream + 24]) | uint(c2da_mem[stream + 25]) << 0x8 | uint(c2da_mem[stream + 26]) << 0x10 | uint(c2da_mem[stream + 27]) << 0x18) + items * size)
    let c2da_fresh7 : uint = c2da_fresh6
    c2da_mem[stream + 24] = uint8(c2da_fresh7)
    c2da_mem[stream + 25] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[stream + 26] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[stream + 27] = uint8(c2da_fresh7 >> 0x18)
    return items
}
[export, sideeffects]
def mem_fopen_write() : int {
    var file_0 : int = Z_Malloc(32, 1, 0)
    let c2da_fresh8 : uint64 = 1024ul
    let c2da_fresh9 : uint64 = c2da_fresh8
    c2da_mem[file_0 + 16] = uint8(c2da_fresh9)
    c2da_mem[file_0 + 17] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[file_0 + 18] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[file_0 + 19] = uint8(c2da_fresh9 >> 0x18)
    c2da_mem[file_0 + 20] = uint8(c2da_fresh9 >> 0x20)
    c2da_mem[file_0 + 21] = uint8(c2da_fresh9 >> 0x28)
    c2da_mem[file_0 + 22] = uint8(c2da_fresh9 >> 0x30)
    c2da_mem[file_0 + 23] = uint8(c2da_fresh9 >> 0x38)
    let c2da_fresh10 : int = Z_Malloc(int(uint64(uint(c2da_mem[file_0 + 16]) | uint(c2da_mem[file_0 + 17]) << 0x8 | uint(c2da_mem[file_0 + 18]) << 0x10 | uint(c2da_mem[file_0 + 19]) << 0x18) | uint64(uint(c2da_mem[file_0 + 20]) | uint(c2da_mem[file_0 + 21]) << 0x8 | uint(c2da_mem[file_0 + 22]) << 0x10 | uint(c2da_mem[file_0 + 23]) << 0x18) << 0x20), 1, 0)
    let c2da_fresh11 : uint = uint(c2da_fresh10)
    c2da_mem[file_0] = uint8(c2da_fresh11)
    c2da_mem[file_0 + 1] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[file_0 + 2] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[file_0 + 3] = uint8(c2da_fresh11 >> 0x18)
    c2da_mem[file_0 + 4] = 0u8
    c2da_mem[file_0 + 5] = 0u8
    c2da_mem[file_0 + 6] = 0u8
    c2da_mem[file_0 + 7] = 0u8
    let c2da_fresh12 : uint64 = 0ul
    let c2da_fresh13 : uint64 = c2da_fresh12
    c2da_mem[file_0 + 8] = uint8(c2da_fresh13)
    c2da_mem[file_0 + 9] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[file_0 + 10] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[file_0 + 11] = uint8(c2da_fresh13 >> 0x18)
    c2da_mem[file_0 + 12] = uint8(c2da_fresh13 >> 0x20)
    c2da_mem[file_0 + 13] = uint8(c2da_fresh13 >> 0x28)
    c2da_mem[file_0 + 14] = uint8(c2da_fresh13 >> 0x30)
    c2da_mem[file_0 + 15] = uint8(c2da_fresh13 >> 0x38)
    let c2da_fresh14 : uint = 0u
    let c2da_fresh15 : uint = c2da_fresh14
    c2da_mem[file_0 + 24] = uint8(c2da_fresh15)
    c2da_mem[file_0 + 25] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[file_0 + 26] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[file_0 + 27] = uint8(c2da_fresh15 >> 0x18)
    let c2da_fresh16 : uint = 1u
    let c2da_fresh17 : uint = c2da_fresh16
    c2da_mem[file_0 + 28] = uint8(c2da_fresh17)
    c2da_mem[file_0 + 29] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[file_0 + 30] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[file_0 + 31] = uint8(c2da_fresh17 >> 0x18)
    return file_0
}
[export, sideeffects]
def mem_fwrite(var ptr : int; var size_0 : uint64; var nmemb_0 : uint64; var stream_0 : int) : uint64 {
    var bytes : uint64
    var newbuf : int
    if ((uint(c2da_mem[stream_0 + 28]) | uint(c2da_mem[stream_0 + 29]) << 0x8 | uint(c2da_mem[stream_0 + 30]) << 0x10 | uint(c2da_mem[stream_0 + 31]) << 0x18) != 1u) {
        return 0xfffffffffffffffful
    }
    bytes = size_0 * nmemb_0
    while (bytes > (uint64(uint(c2da_mem[stream_0 + 16]) | uint(c2da_mem[stream_0 + 17]) << 0x8 | uint(c2da_mem[stream_0 + 18]) << 0x10 | uint(c2da_mem[stream_0 + 19]) << 0x18) | uint64(uint(c2da_mem[stream_0 + 20]) | uint(c2da_mem[stream_0 + 21]) << 0x8 | uint(c2da_mem[stream_0 + 22]) << 0x10 | uint(c2da_mem[stream_0 + 23]) << 0x18) << 0x20) - uint64(uint(c2da_mem[stream_0 + 24]) | uint(c2da_mem[stream_0 + 25]) << 0x8 | uint(c2da_mem[stream_0 + 26]) << 0x10 | uint(c2da_mem[stream_0 + 27]) << 0x18)) {
        newbuf = Z_Malloc(int((uint64(uint(c2da_mem[stream_0 + 16]) | uint(c2da_mem[stream_0 + 17]) << 0x8 | uint(c2da_mem[stream_0 + 18]) << 0x10 | uint(c2da_mem[stream_0 + 19]) << 0x18) | uint64(uint(c2da_mem[stream_0 + 20]) | uint(c2da_mem[stream_0 + 21]) << 0x8 | uint(c2da_mem[stream_0 + 22]) << 0x10 | uint(c2da_mem[stream_0 + 23]) << 0x18) << 0x20) * 2ul), 1, 0)
        c2da_lin_memcpy(newbuf, int(uint(c2da_mem[stream_0]) | uint(c2da_mem[stream_0 + 1]) << 0x8 | uint(c2da_mem[stream_0 + 2]) << 0x10 | uint(c2da_mem[stream_0 + 3]) << 0x18), uint64(uint(c2da_mem[stream_0 + 16]) | uint(c2da_mem[stream_0 + 17]) << 0x8 | uint(c2da_mem[stream_0 + 18]) << 0x10 | uint(c2da_mem[stream_0 + 19]) << 0x18) | uint64(uint(c2da_mem[stream_0 + 20]) | uint(c2da_mem[stream_0 + 21]) << 0x8 | uint(c2da_mem[stream_0 + 22]) << 0x10 | uint(c2da_mem[stream_0 + 23]) << 0x18) << 0x20)
        Z_Free(int(uint(c2da_mem[stream_0]) | uint(c2da_mem[stream_0 + 1]) << 0x8 | uint(c2da_mem[stream_0 + 2]) << 0x10 | uint(c2da_mem[stream_0 + 3]) << 0x18))
        let c2da_fresh18 : uint = uint(newbuf)
        c2da_mem[stream_0] = uint8(c2da_fresh18)
        c2da_mem[stream_0 + 1] = uint8(c2da_fresh18 >> 0x8)
        c2da_mem[stream_0 + 2] = uint8(c2da_fresh18 >> 0x10)
        c2da_mem[stream_0 + 3] = uint8(c2da_fresh18 >> 0x18)
        c2da_mem[stream_0 + 4] = 0u8
        c2da_mem[stream_0 + 5] = 0u8
        c2da_mem[stream_0 + 6] = 0u8
        c2da_mem[stream_0 + 7] = 0u8
        let c2da_fresh19 : uint64 = (uint64(uint(c2da_mem[stream_0 + 16]) | uint(c2da_mem[stream_0 + 17]) << 0x8 | uint(c2da_mem[stream_0 + 18]) << 0x10 | uint(c2da_mem[stream_0 + 19]) << 0x18) | uint64(uint(c2da_mem[stream_0 + 20]) | uint(c2da_mem[stream_0 + 21]) << 0x8 | uint(c2da_mem[stream_0 + 22]) << 0x10 | uint(c2da_mem[stream_0 + 23]) << 0x18) << 0x20) * 2ul
        let c2da_fresh20 : uint64 = c2da_fresh19
        c2da_mem[stream_0 + 16] = uint8(c2da_fresh20)
        c2da_mem[stream_0 + 17] = uint8(c2da_fresh20 >> 0x8)
        c2da_mem[stream_0 + 18] = uint8(c2da_fresh20 >> 0x10)
        c2da_mem[stream_0 + 19] = uint8(c2da_fresh20 >> 0x18)
        c2da_mem[stream_0 + 20] = uint8(c2da_fresh20 >> 0x20)
        c2da_mem[stream_0 + 21] = uint8(c2da_fresh20 >> 0x28)
        c2da_mem[stream_0 + 22] = uint8(c2da_fresh20 >> 0x30)
        c2da_mem[stream_0 + 23] = uint8(c2da_fresh20 >> 0x38)
    }
    c2da_lin_memcpy(int(uint(c2da_mem[stream_0]) | uint(c2da_mem[stream_0 + 1]) << 0x8 | uint(c2da_mem[stream_0 + 2]) << 0x10 | uint(c2da_mem[stream_0 + 3]) << 0x18) + int(uint(c2da_mem[stream_0 + 24]) | uint(c2da_mem[stream_0 + 25]) << 0x8 | uint(c2da_mem[stream_0 + 26]) << 0x10 | uint(c2da_mem[stream_0 + 27]) << 0x18), ptr, bytes)
    let c2da_fresh21 : uint = uint(uint64(uint(c2da_mem[stream_0 + 24]) | uint(c2da_mem[stream_0 + 25]) << 0x8 | uint(c2da_mem[stream_0 + 26]) << 0x10 | uint(c2da_mem[stream_0 + 27]) << 0x18) + bytes)
    let c2da_fresh22 : uint = c2da_fresh21
    c2da_mem[stream_0 + 24] = uint8(c2da_fresh22)
    c2da_mem[stream_0 + 25] = uint8(c2da_fresh22 >> 0x8)
    c2da_mem[stream_0 + 26] = uint8(c2da_fresh22 >> 0x10)
    c2da_mem[stream_0 + 27] = uint8(c2da_fresh22 >> 0x18)
    if (uint64(uint(c2da_mem[stream_0 + 24]) | uint(c2da_mem[stream_0 + 25]) << 0x8 | uint(c2da_mem[stream_0 + 26]) << 0x10 | uint(c2da_mem[stream_0 + 27]) << 0x18) > (uint64(uint(c2da_mem[stream_0 + 8]) | uint(c2da_mem[stream_0 + 9]) << 0x8 | uint(c2da_mem[stream_0 + 10]) << 0x10 | uint(c2da_mem[stream_0 + 11]) << 0x18) | uint64(uint(c2da_mem[stream_0 + 12]) | uint(c2da_mem[stream_0 + 13]) << 0x8 | uint(c2da_mem[stream_0 + 14]) << 0x10 | uint(c2da_mem[stream_0 + 15]) << 0x18) << 0x20)) {
        let c2da_fresh23 : uint64 = uint64(uint(c2da_mem[stream_0 + 24]) | uint(c2da_mem[stream_0 + 25]) << 0x8 | uint(c2da_mem[stream_0 + 26]) << 0x10 | uint(c2da_mem[stream_0 + 27]) << 0x18)
        let c2da_fresh24 : uint64 = c2da_fresh23
        c2da_mem[stream_0 + 8] = uint8(c2da_fresh24)
        c2da_mem[stream_0 + 9] = uint8(c2da_fresh24 >> 0x8)
        c2da_mem[stream_0 + 10] = uint8(c2da_fresh24 >> 0x10)
        c2da_mem[stream_0 + 11] = uint8(c2da_fresh24 >> 0x18)
        c2da_mem[stream_0 + 12] = uint8(c2da_fresh24 >> 0x20)
        c2da_mem[stream_0 + 13] = uint8(c2da_fresh24 >> 0x28)
        c2da_mem[stream_0 + 14] = uint8(c2da_fresh24 >> 0x30)
        c2da_mem[stream_0 + 15] = uint8(c2da_fresh24 >> 0x38)
    }
    return nmemb_0
}
[export, sideeffects]
def mem_get_buf(var stream_1 : int; var buf_1 : int; var buflen_0 : int) {
    let c2da_fresh25 : int = int(uint(c2da_mem[stream_1]) | uint(c2da_mem[stream_1 + 1]) << 0x8 | uint(c2da_mem[stream_1 + 2]) << 0x10 | uint(c2da_mem[stream_1 + 3]) << 0x18)
    let c2da_fresh26 : uint = uint(c2da_fresh25)
    c2da_mem[buf_1] = uint8(c2da_fresh26)
    c2da_mem[buf_1 + 1] = uint8(c2da_fresh26 >> 0x8)
    c2da_mem[buf_1 + 2] = uint8(c2da_fresh26 >> 0x10)
    c2da_mem[buf_1 + 3] = uint8(c2da_fresh26 >> 0x18)
    c2da_mem[buf_1 + 4] = 0u8
    c2da_mem[buf_1 + 5] = 0u8
    c2da_mem[buf_1 + 6] = 0u8
    c2da_mem[buf_1 + 7] = 0u8
    let c2da_fresh27 : uint64 = uint64(uint(c2da_mem[stream_1 + 8]) | uint(c2da_mem[stream_1 + 9]) << 0x8 | uint(c2da_mem[stream_1 + 10]) << 0x10 | uint(c2da_mem[stream_1 + 11]) << 0x18) | uint64(uint(c2da_mem[stream_1 + 12]) | uint(c2da_mem[stream_1 + 13]) << 0x8 | uint(c2da_mem[stream_1 + 14]) << 0x10 | uint(c2da_mem[stream_1 + 15]) << 0x18) << 0x20
    let c2da_fresh28 : uint64 = c2da_fresh27
    c2da_mem[buflen_0] = uint8(c2da_fresh28)
    c2da_mem[buflen_0 + 1] = uint8(c2da_fresh28 >> 0x8)
    c2da_mem[buflen_0 + 2] = uint8(c2da_fresh28 >> 0x10)
    c2da_mem[buflen_0 + 3] = uint8(c2da_fresh28 >> 0x18)
    c2da_mem[buflen_0 + 4] = uint8(c2da_fresh28 >> 0x20)
    c2da_mem[buflen_0 + 5] = uint8(c2da_fresh28 >> 0x28)
    c2da_mem[buflen_0 + 6] = uint8(c2da_fresh28 >> 0x30)
    c2da_mem[buflen_0 + 7] = uint8(c2da_fresh28 >> 0x38)
    return
}
[export, sideeffects]
def mem_fclose(var stream_2 : int) {
    if ((uint(c2da_mem[stream_2 + 28]) | uint(c2da_mem[stream_2 + 29]) << 0x8 | uint(c2da_mem[stream_2 + 30]) << 0x10 | uint(c2da_mem[stream_2 + 31]) << 0x18) == 1u) {
        Z_Free(int(uint(c2da_mem[stream_2]) | uint(c2da_mem[stream_2 + 1]) << 0x8 | uint(c2da_mem[stream_2 + 2]) << 0x10 | uint(c2da_mem[stream_2 + 3]) << 0x18))
    }
    Z_Free(stream_2)
    return
}
[export, sideeffects]
def mem_ftell(var stream_3 : int) : int64 {
    return int64(uint(c2da_mem[stream_3 + 24]) | uint(c2da_mem[stream_3 + 25]) << 0x8 | uint(c2da_mem[stream_3 + 26]) << 0x10 | uint(c2da_mem[stream_3 + 27]) << 0x18)
}
[export, sideeffects]
def mem_fseek(var stream_4 : int; var position : int64; var whence : uint) : int {
    var c2da_fresh29 : uint
    var newpos : uint
    c2da_fresh29 = whence
    if (c2da_fresh29 == 0x0u) {
        newpos = uint(int(position))
    } elif (c2da_fresh29 == 0x1u) {
        newpos = uint(int(int64(uint(c2da_mem[stream_4 + 24]) | uint(c2da_mem[stream_4 + 25]) << 0x8 | uint(c2da_mem[stream_4 + 26]) << 0x10 | uint(c2da_mem[stream_4 + 27]) << 0x18) + position))
    } elif (c2da_fresh29 == 0x2u) {
        newpos = uint(int((uint64(uint(c2da_mem[stream_4 + 8]) | uint(c2da_mem[stream_4 + 9]) << 0x8 | uint(c2da_mem[stream_4 + 10]) << 0x10 | uint(c2da_mem[stream_4 + 11]) << 0x18) | uint64(uint(c2da_mem[stream_4 + 12]) | uint(c2da_mem[stream_4 + 13]) << 0x8 | uint(c2da_mem[stream_4 + 14]) << 0x10 | uint(c2da_mem[stream_4 + 15]) << 0x18) << 0x20) + uint64(position)))
    } else {
        return -1
    }
    if (uint64(newpos) < (uint64(uint(c2da_mem[stream_4 + 8]) | uint(c2da_mem[stream_4 + 9]) << 0x8 | uint(c2da_mem[stream_4 + 10]) << 0x10 | uint(c2da_mem[stream_4 + 11]) << 0x18) | uint64(uint(c2da_mem[stream_4 + 12]) | uint(c2da_mem[stream_4 + 13]) << 0x8 | uint(c2da_mem[stream_4 + 14]) << 0x10 | uint(c2da_mem[stream_4 + 15]) << 0x18) << 0x20)) {
        let c2da_fresh30 : uint = newpos
        c2da_mem[stream_4 + 24] = uint8(c2da_fresh30)
        c2da_mem[stream_4 + 25] = uint8(c2da_fresh30 >> 0x8)
        c2da_mem[stream_4 + 26] = uint8(c2da_fresh30 >> 0x10)
        c2da_mem[stream_4 + 27] = uint8(c2da_fresh30 >> 0x18)
        return 0
    } else {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 346275, [C2daVaArg(tag = 1, i64 = int64(newpos), f64 = 0.0lf, raw = 0x0)])
        return -1
    }
}

// This unit's static data, at heap offset 346256.
let private c2da_lin_static_memio_seg = fixed_array<int>(346256, 39)
let private c2da_lin_static_memio = fixed_array<uint64>(0x6572206120746f6eul, 0x6165727473206461ul, 0x726f727245000a6dul, 0x676e696b65657320ul, 0xa6925206f7420ul)

[init]
def private c2da_lin_init_static_memio() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_memio_seg[s * 2]
        for (k in range(c2da_lin_static_memio_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_memio[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
