options gen2
options stack = 4194304
module sha1 public

require c2da_runtime
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
def SHA1_Init(var hd : int) {
    let c2da_fresh0 : uint = 0x67452301u
    let c2da_fresh1 : uint = c2da_fresh0
    c2da_mem[hd] = uint8(c2da_fresh1)
    c2da_mem[hd + 1] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[hd + 2] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[hd + 3] = uint8(c2da_fresh1 >> 0x18)
    let c2da_fresh2 : uint = 0xefcdab89u
    let c2da_fresh3 : uint = c2da_fresh2
    c2da_mem[hd + 4] = uint8(c2da_fresh3)
    c2da_mem[hd + 5] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[hd + 6] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[hd + 7] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : uint = 0x98badcfeu
    let c2da_fresh5 : uint = c2da_fresh4
    c2da_mem[hd + 8] = uint8(c2da_fresh5)
    c2da_mem[hd + 9] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[hd + 10] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[hd + 11] = uint8(c2da_fresh5 >> 0x18)
    let c2da_fresh6 : uint = 0x10325476u
    let c2da_fresh7 : uint = c2da_fresh6
    c2da_mem[hd + 12] = uint8(c2da_fresh7)
    c2da_mem[hd + 13] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[hd + 14] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[hd + 15] = uint8(c2da_fresh7 >> 0x18)
    let c2da_fresh8 : uint = 0xc3d2e1f0u
    let c2da_fresh9 : uint = c2da_fresh8
    c2da_mem[hd + 16] = uint8(c2da_fresh9)
    c2da_mem[hd + 17] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[hd + 18] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[hd + 19] = uint8(c2da_fresh9 >> 0x18)
    let c2da_fresh10 : uint = 0u
    let c2da_fresh11 : uint = c2da_fresh10
    c2da_mem[hd + 20] = uint8(c2da_fresh11)
    c2da_mem[hd + 21] = uint8(c2da_fresh11 >> 0x8)
    c2da_mem[hd + 22] = uint8(c2da_fresh11 >> 0x10)
    c2da_mem[hd + 23] = uint8(c2da_fresh11 >> 0x18)
    let c2da_fresh12 : int = 0
    let c2da_fresh13 : uint = uint(c2da_fresh12)
    c2da_mem[hd + 88] = uint8(c2da_fresh13)
    c2da_mem[hd + 89] = uint8(c2da_fresh13 >> 0x8)
    c2da_mem[hd + 90] = uint8(c2da_fresh13 >> 0x10)
    c2da_mem[hd + 91] = uint8(c2da_fresh13 >> 0x18)
    return
}
[export, sideeffects]
def SHA1_Update(var hd_0 : int; var inbuf : int; var inlen : uint64) {
    if (int(uint(c2da_mem[hd_0 + 88]) | uint(c2da_mem[hd_0 + 89]) << 0x8 | uint(c2da_mem[hd_0 + 90]) << 0x10 | uint(c2da_mem[hd_0 + 91]) << 0x18) == 64) {
        Transform(hd_0, hd_0 + 24)
        let c2da_fresh14 : int = 0
        let c2da_fresh15 : uint = uint(c2da_fresh14)
        c2da_mem[hd_0 + 88] = uint8(c2da_fresh15)
        c2da_mem[hd_0 + 89] = uint8(c2da_fresh15 >> 0x8)
        c2da_mem[hd_0 + 90] = uint8(c2da_fresh15 >> 0x10)
        c2da_mem[hd_0 + 91] = uint8(c2da_fresh15 >> 0x18)
        let c2da_fresh16 : uint = uint(c2da_mem[hd_0 + 20]) | uint(c2da_mem[hd_0 + 21]) << 0x8 | uint(c2da_mem[hd_0 + 22]) << 0x10 | uint(c2da_mem[hd_0 + 23]) << 0x18
        let c2da_fresh17 : uint = c2da_fresh16 + 1u
        let c2da_fresh18 : uint = c2da_fresh17
        c2da_mem[hd_0 + 20] = uint8(c2da_fresh18)
        c2da_mem[hd_0 + 21] = uint8(c2da_fresh18 >> 0x8)
        c2da_mem[hd_0 + 22] = uint8(c2da_fresh18 >> 0x10)
        c2da_mem[hd_0 + 23] = uint8(c2da_fresh18 >> 0x18)
    }
    if (inbuf == 0) {
        return
    }
    if (int(uint(c2da_mem[hd_0 + 88]) | uint(c2da_mem[hd_0 + 89]) << 0x8 | uint(c2da_mem[hd_0 + 90]) << 0x10 | uint(c2da_mem[hd_0 + 91]) << 0x18) != 0) {
        while (inlen != 0x0 && int(uint(c2da_mem[hd_0 + 88]) | uint(c2da_mem[hd_0 + 89]) << 0x8 | uint(c2da_mem[hd_0 + 90]) << 0x10 | uint(c2da_mem[hd_0 + 91]) << 0x18) < 64) {
            let c2da_fresh19 : int = int(uint(c2da_mem[hd_0 + 88]) | uint(c2da_mem[hd_0 + 89]) << 0x8 | uint(c2da_mem[hd_0 + 90]) << 0x10 | uint(c2da_mem[hd_0 + 91]) << 0x18)
            let c2da_fresh20 : int = c2da_fresh19 + 1
            let c2da_fresh21 : uint = uint(c2da_fresh20)
            c2da_mem[hd_0 + 88] = uint8(c2da_fresh21)
            c2da_mem[hd_0 + 89] = uint8(c2da_fresh21 >> 0x8)
            c2da_mem[hd_0 + 90] = uint8(c2da_fresh21 >> 0x10)
            c2da_mem[hd_0 + 91] = uint8(c2da_fresh21 >> 0x18)
            let c2da_fresh22 : int = inbuf
            inbuf++
            let c2da_fresh23 : uint8 = c2da_mem[c2da_fresh22]
            c2da_mem[hd_0 + 24 + c2da_fresh19] = c2da_fresh23
            inlen--
        }
        SHA1_Update(hd_0, 0, 0ul)
        if (inlen == 0) {
            return
        }
    }
    while (inlen >= 64ul) {
        Transform(hd_0, inbuf)
        let c2da_fresh24 : int = 0
        let c2da_fresh25 : uint = uint(c2da_fresh24)
        c2da_mem[hd_0 + 88] = uint8(c2da_fresh25)
        c2da_mem[hd_0 + 89] = uint8(c2da_fresh25 >> 0x8)
        c2da_mem[hd_0 + 90] = uint8(c2da_fresh25 >> 0x10)
        c2da_mem[hd_0 + 91] = uint8(c2da_fresh25 >> 0x18)
        let c2da_fresh26 : uint = uint(c2da_mem[hd_0 + 20]) | uint(c2da_mem[hd_0 + 21]) << 0x8 | uint(c2da_mem[hd_0 + 22]) << 0x10 | uint(c2da_mem[hd_0 + 23]) << 0x18
        let c2da_fresh27 : uint = c2da_fresh26 + 1u
        let c2da_fresh28 : uint = c2da_fresh27
        c2da_mem[hd_0 + 20] = uint8(c2da_fresh28)
        c2da_mem[hd_0 + 21] = uint8(c2da_fresh28 >> 0x8)
        c2da_mem[hd_0 + 22] = uint8(c2da_fresh28 >> 0x10)
        c2da_mem[hd_0 + 23] = uint8(c2da_fresh28 >> 0x18)
        inlen -= 64ul
        inbuf += 64
    }
    while (inlen != 0x0 && int(uint(c2da_mem[hd_0 + 88]) | uint(c2da_mem[hd_0 + 89]) << 0x8 | uint(c2da_mem[hd_0 + 90]) << 0x10 | uint(c2da_mem[hd_0 + 91]) << 0x18) < 64) {
        let c2da_fresh29 : int = int(uint(c2da_mem[hd_0 + 88]) | uint(c2da_mem[hd_0 + 89]) << 0x8 | uint(c2da_mem[hd_0 + 90]) << 0x10 | uint(c2da_mem[hd_0 + 91]) << 0x18)
        let c2da_fresh30 : int = c2da_fresh29 + 1
        let c2da_fresh31 : uint = uint(c2da_fresh30)
        c2da_mem[hd_0 + 88] = uint8(c2da_fresh31)
        c2da_mem[hd_0 + 89] = uint8(c2da_fresh31 >> 0x8)
        c2da_mem[hd_0 + 90] = uint8(c2da_fresh31 >> 0x10)
        c2da_mem[hd_0 + 91] = uint8(c2da_fresh31 >> 0x18)
        let c2da_fresh32 : int = inbuf
        inbuf++
        let c2da_fresh33 : uint8 = c2da_mem[c2da_fresh32]
        c2da_mem[hd_0 + 24 + c2da_fresh29] = c2da_fresh33
        inlen--
    }
    return
}
[sideeffects]
def private Transform(var hd_1 : int; var data : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    Transform_c2da_frame(hd_1, data, c2da_lin_enter(64))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def SHA1_Final(var digest : int; var hd_2 : int) {
    var t : uint
    var msb : uint
    var lsb : uint
    var p : int
    SHA1_Update(hd_2, 0, 0ul)
    t = uint(c2da_mem[hd_2 + 20]) | uint(c2da_mem[hd_2 + 21]) << 0x8 | uint(c2da_mem[hd_2 + 22]) << 0x10 | uint(c2da_mem[hd_2 + 23]) << 0x18
    lsb = t << 6u
    msb = t >> 26u
    t = lsb
    lsb += uint(int(uint(c2da_mem[hd_2 + 88]) | uint(c2da_mem[hd_2 + 89]) << 0x8 | uint(c2da_mem[hd_2 + 90]) << 0x10 | uint(c2da_mem[hd_2 + 91]) << 0x18))
    if (lsb < t) {
        msb++
    }
    t = lsb
    lsb <<= 3u
    msb <<= 3u
    msb |= t >> 29u
    if (int(uint(c2da_mem[hd_2 + 88]) | uint(c2da_mem[hd_2 + 89]) << 0x8 | uint(c2da_mem[hd_2 + 90]) << 0x10 | uint(c2da_mem[hd_2 + 91]) << 0x18) < 56) {
        let c2da_fresh500 : int = int(uint(c2da_mem[hd_2 + 88]) | uint(c2da_mem[hd_2 + 89]) << 0x8 | uint(c2da_mem[hd_2 + 90]) << 0x10 | uint(c2da_mem[hd_2 + 91]) << 0x18)
        let c2da_fresh501 : int = c2da_fresh500 + 1
        let c2da_fresh502 : uint = uint(c2da_fresh501)
        c2da_mem[hd_2 + 88] = uint8(c2da_fresh502)
        c2da_mem[hd_2 + 89] = uint8(c2da_fresh502 >> 0x8)
        c2da_mem[hd_2 + 90] = uint8(c2da_fresh502 >> 0x10)
        c2da_mem[hd_2 + 91] = uint8(c2da_fresh502 >> 0x18)
        let c2da_fresh503 : uint8 = 0x80u8
        c2da_mem[hd_2 + 24 + c2da_fresh500] = c2da_fresh503
        while (int(uint(c2da_mem[hd_2 + 88]) | uint(c2da_mem[hd_2 + 89]) << 0x8 | uint(c2da_mem[hd_2 + 90]) << 0x10 | uint(c2da_mem[hd_2 + 91]) << 0x18) < 56) {
            let c2da_fresh504 : int = int(uint(c2da_mem[hd_2 + 88]) | uint(c2da_mem[hd_2 + 89]) << 0x8 | uint(c2da_mem[hd_2 + 90]) << 0x10 | uint(c2da_mem[hd_2 + 91]) << 0x18)
            let c2da_fresh505 : int = c2da_fresh504 + 1
            let c2da_fresh506 : uint = uint(c2da_fresh505)
            c2da_mem[hd_2 + 88] = uint8(c2da_fresh506)
            c2da_mem[hd_2 + 89] = uint8(c2da_fresh506 >> 0x8)
            c2da_mem[hd_2 + 90] = uint8(c2da_fresh506 >> 0x10)
            c2da_mem[hd_2 + 91] = uint8(c2da_fresh506 >> 0x18)
            let c2da_fresh507 : uint8 = 0u8
            c2da_mem[hd_2 + 24 + c2da_fresh504] = c2da_fresh507
        }
    } else {
        let c2da_fresh508 : int = int(uint(c2da_mem[hd_2 + 88]) | uint(c2da_mem[hd_2 + 89]) << 0x8 | uint(c2da_mem[hd_2 + 90]) << 0x10 | uint(c2da_mem[hd_2 + 91]) << 0x18)
        let c2da_fresh509 : int = c2da_fresh508 + 1
        let c2da_fresh510 : uint = uint(c2da_fresh509)
        c2da_mem[hd_2 + 88] = uint8(c2da_fresh510)
        c2da_mem[hd_2 + 89] = uint8(c2da_fresh510 >> 0x8)
        c2da_mem[hd_2 + 90] = uint8(c2da_fresh510 >> 0x10)
        c2da_mem[hd_2 + 91] = uint8(c2da_fresh510 >> 0x18)
        let c2da_fresh511 : uint8 = 0x80u8
        c2da_mem[hd_2 + 24 + c2da_fresh508] = c2da_fresh511
        while (int(uint(c2da_mem[hd_2 + 88]) | uint(c2da_mem[hd_2 + 89]) << 0x8 | uint(c2da_mem[hd_2 + 90]) << 0x10 | uint(c2da_mem[hd_2 + 91]) << 0x18) < 64) {
            let c2da_fresh512 : int = int(uint(c2da_mem[hd_2 + 88]) | uint(c2da_mem[hd_2 + 89]) << 0x8 | uint(c2da_mem[hd_2 + 90]) << 0x10 | uint(c2da_mem[hd_2 + 91]) << 0x18)
            let c2da_fresh513 : int = c2da_fresh512 + 1
            let c2da_fresh514 : uint = uint(c2da_fresh513)
            c2da_mem[hd_2 + 88] = uint8(c2da_fresh514)
            c2da_mem[hd_2 + 89] = uint8(c2da_fresh514 >> 0x8)
            c2da_mem[hd_2 + 90] = uint8(c2da_fresh514 >> 0x10)
            c2da_mem[hd_2 + 91] = uint8(c2da_fresh514 >> 0x18)
            let c2da_fresh515 : uint8 = 0u8
            c2da_mem[hd_2 + 24 + c2da_fresh512] = c2da_fresh515
        }
        SHA1_Update(hd_2, 0, 0ul)
        c2da_lin_memset(hd_2 + 24, 0, 56ul)
    }
    let c2da_fresh516 : uint8 = uint8(msb >> 24u)
    c2da_mem[hd_2 + 24 + 56] = c2da_fresh516
    let c2da_fresh517 : uint8 = uint8(msb >> 16u)
    c2da_mem[hd_2 + 24 + 57] = c2da_fresh517
    let c2da_fresh518 : uint8 = uint8(msb >> 8u)
    c2da_mem[hd_2 + 24 + 58] = c2da_fresh518
    let c2da_fresh519 : uint8 = uint8(msb)
    c2da_mem[hd_2 + 24 + 59] = c2da_fresh519
    let c2da_fresh520 : uint8 = uint8(lsb >> 24u)
    c2da_mem[hd_2 + 24 + 60] = c2da_fresh520
    let c2da_fresh521 : uint8 = uint8(lsb >> 16u)
    c2da_mem[hd_2 + 24 + 61] = c2da_fresh521
    let c2da_fresh522 : uint8 = uint8(lsb >> 8u)
    c2da_mem[hd_2 + 24 + 62] = c2da_fresh522
    let c2da_fresh523 : uint8 = uint8(lsb)
    c2da_mem[hd_2 + 24 + 63] = c2da_fresh523
    Transform(hd_2, hd_2 + 24)
    p = hd_2 + 24
    let c2da_fresh524 : int = p
    p++
    let c2da_fresh525 : uint8 = uint8((uint(c2da_mem[hd_2]) | uint(c2da_mem[hd_2 + 1]) << 0x8 | uint(c2da_mem[hd_2 + 2]) << 0x10 | uint(c2da_mem[hd_2 + 3]) << 0x18) >> 24u)
    c2da_mem[c2da_fresh524] = c2da_fresh525
    let c2da_fresh526 : int = p
    p++
    let c2da_fresh527 : uint8 = uint8((uint(c2da_mem[hd_2]) | uint(c2da_mem[hd_2 + 1]) << 0x8 | uint(c2da_mem[hd_2 + 2]) << 0x10 | uint(c2da_mem[hd_2 + 3]) << 0x18) >> 16u)
    c2da_mem[c2da_fresh526] = c2da_fresh527
    let c2da_fresh528 : int = p
    p++
    let c2da_fresh529 : uint8 = uint8((uint(c2da_mem[hd_2]) | uint(c2da_mem[hd_2 + 1]) << 0x8 | uint(c2da_mem[hd_2 + 2]) << 0x10 | uint(c2da_mem[hd_2 + 3]) << 0x18) >> 8u)
    c2da_mem[c2da_fresh528] = c2da_fresh529
    let c2da_fresh530 : int = p
    p++
    let c2da_fresh531 : uint8 = uint8(uint(c2da_mem[hd_2]) | uint(c2da_mem[hd_2 + 1]) << 0x8 | uint(c2da_mem[hd_2 + 2]) << 0x10 | uint(c2da_mem[hd_2 + 3]) << 0x18)
    c2da_mem[c2da_fresh530] = c2da_fresh531
    let c2da_fresh532 : int = p
    p++
    let c2da_fresh533 : uint8 = uint8((uint(c2da_mem[hd_2 + 4]) | uint(c2da_mem[hd_2 + 5]) << 0x8 | uint(c2da_mem[hd_2 + 6]) << 0x10 | uint(c2da_mem[hd_2 + 7]) << 0x18) >> 24u)
    c2da_mem[c2da_fresh532] = c2da_fresh533
    let c2da_fresh534 : int = p
    p++
    let c2da_fresh535 : uint8 = uint8((uint(c2da_mem[hd_2 + 4]) | uint(c2da_mem[hd_2 + 5]) << 0x8 | uint(c2da_mem[hd_2 + 6]) << 0x10 | uint(c2da_mem[hd_2 + 7]) << 0x18) >> 16u)
    c2da_mem[c2da_fresh534] = c2da_fresh535
    let c2da_fresh536 : int = p
    p++
    let c2da_fresh537 : uint8 = uint8((uint(c2da_mem[hd_2 + 4]) | uint(c2da_mem[hd_2 + 5]) << 0x8 | uint(c2da_mem[hd_2 + 6]) << 0x10 | uint(c2da_mem[hd_2 + 7]) << 0x18) >> 8u)
    c2da_mem[c2da_fresh536] = c2da_fresh537
    let c2da_fresh538 : int = p
    p++
    let c2da_fresh539 : uint8 = uint8(uint(c2da_mem[hd_2 + 4]) | uint(c2da_mem[hd_2 + 5]) << 0x8 | uint(c2da_mem[hd_2 + 6]) << 0x10 | uint(c2da_mem[hd_2 + 7]) << 0x18)
    c2da_mem[c2da_fresh538] = c2da_fresh539
    let c2da_fresh540 : int = p
    p++
    let c2da_fresh541 : uint8 = uint8((uint(c2da_mem[hd_2 + 8]) | uint(c2da_mem[hd_2 + 9]) << 0x8 | uint(c2da_mem[hd_2 + 10]) << 0x10 | uint(c2da_mem[hd_2 + 11]) << 0x18) >> 24u)
    c2da_mem[c2da_fresh540] = c2da_fresh541
    let c2da_fresh542 : int = p
    p++
    let c2da_fresh543 : uint8 = uint8((uint(c2da_mem[hd_2 + 8]) | uint(c2da_mem[hd_2 + 9]) << 0x8 | uint(c2da_mem[hd_2 + 10]) << 0x10 | uint(c2da_mem[hd_2 + 11]) << 0x18) >> 16u)
    c2da_mem[c2da_fresh542] = c2da_fresh543
    let c2da_fresh544 : int = p
    p++
    let c2da_fresh545 : uint8 = uint8((uint(c2da_mem[hd_2 + 8]) | uint(c2da_mem[hd_2 + 9]) << 0x8 | uint(c2da_mem[hd_2 + 10]) << 0x10 | uint(c2da_mem[hd_2 + 11]) << 0x18) >> 8u)
    c2da_mem[c2da_fresh544] = c2da_fresh545
    let c2da_fresh546 : int = p
    p++
    let c2da_fresh547 : uint8 = uint8(uint(c2da_mem[hd_2 + 8]) | uint(c2da_mem[hd_2 + 9]) << 0x8 | uint(c2da_mem[hd_2 + 10]) << 0x10 | uint(c2da_mem[hd_2 + 11]) << 0x18)
    c2da_mem[c2da_fresh546] = c2da_fresh547
    let c2da_fresh548 : int = p
    p++
    let c2da_fresh549 : uint8 = uint8((uint(c2da_mem[hd_2 + 12]) | uint(c2da_mem[hd_2 + 13]) << 0x8 | uint(c2da_mem[hd_2 + 14]) << 0x10 | uint(c2da_mem[hd_2 + 15]) << 0x18) >> 24u)
    c2da_mem[c2da_fresh548] = c2da_fresh549
    let c2da_fresh550 : int = p
    p++
    let c2da_fresh551 : uint8 = uint8((uint(c2da_mem[hd_2 + 12]) | uint(c2da_mem[hd_2 + 13]) << 0x8 | uint(c2da_mem[hd_2 + 14]) << 0x10 | uint(c2da_mem[hd_2 + 15]) << 0x18) >> 16u)
    c2da_mem[c2da_fresh550] = c2da_fresh551
    let c2da_fresh552 : int = p
    p++
    let c2da_fresh553 : uint8 = uint8((uint(c2da_mem[hd_2 + 12]) | uint(c2da_mem[hd_2 + 13]) << 0x8 | uint(c2da_mem[hd_2 + 14]) << 0x10 | uint(c2da_mem[hd_2 + 15]) << 0x18) >> 8u)
    c2da_mem[c2da_fresh552] = c2da_fresh553
    let c2da_fresh554 : int = p
    p++
    let c2da_fresh555 : uint8 = uint8(uint(c2da_mem[hd_2 + 12]) | uint(c2da_mem[hd_2 + 13]) << 0x8 | uint(c2da_mem[hd_2 + 14]) << 0x10 | uint(c2da_mem[hd_2 + 15]) << 0x18)
    c2da_mem[c2da_fresh554] = c2da_fresh555
    let c2da_fresh556 : int = p
    p++
    let c2da_fresh557 : uint8 = uint8((uint(c2da_mem[hd_2 + 16]) | uint(c2da_mem[hd_2 + 17]) << 0x8 | uint(c2da_mem[hd_2 + 18]) << 0x10 | uint(c2da_mem[hd_2 + 19]) << 0x18) >> 24u)
    c2da_mem[c2da_fresh556] = c2da_fresh557
    let c2da_fresh558 : int = p
    p++
    let c2da_fresh559 : uint8 = uint8((uint(c2da_mem[hd_2 + 16]) | uint(c2da_mem[hd_2 + 17]) << 0x8 | uint(c2da_mem[hd_2 + 18]) << 0x10 | uint(c2da_mem[hd_2 + 19]) << 0x18) >> 16u)
    c2da_mem[c2da_fresh558] = c2da_fresh559
    let c2da_fresh560 : int = p
    p++
    let c2da_fresh561 : uint8 = uint8((uint(c2da_mem[hd_2 + 16]) | uint(c2da_mem[hd_2 + 17]) << 0x8 | uint(c2da_mem[hd_2 + 18]) << 0x10 | uint(c2da_mem[hd_2 + 19]) << 0x18) >> 8u)
    c2da_mem[c2da_fresh560] = c2da_fresh561
    let c2da_fresh562 : int = p
    p++
    let c2da_fresh563 : uint8 = uint8(uint(c2da_mem[hd_2 + 16]) | uint(c2da_mem[hd_2 + 17]) << 0x8 | uint(c2da_mem[hd_2 + 18]) << 0x10 | uint(c2da_mem[hd_2 + 19]) << 0x18)
    c2da_mem[c2da_fresh562] = c2da_fresh563
    c2da_lin_memcpy(digest, hd_2 + 24, 20ul)
    return
}
[export, sideeffects]
def SHA1_UpdateInt32(var context : int; var val : uint) {
    let c2da_saved_sp : int = c2da_lin_sp
    SHA1_UpdateInt32_c2da_frame(context, val, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def SHA1_UpdateString(var context_0 : int; var str : int) {
    SHA1_Update(context_0, str, c2da_lin_strlen(str) + 1ul)
    return
}
[sideeffects]
def private Transform_c2da_frame(var hd_1 : int; var data : int; c2da_fp : int) {
    var a : uint
    var b : uint
    var c : uint
    var d : uint
    var e : uint
    var tm : uint
    var i : int
    var p2 : int
    a = uint(c2da_mem[hd_1]) | uint(c2da_mem[hd_1 + 1]) << 0x8 | uint(c2da_mem[hd_1 + 2]) << 0x10 | uint(c2da_mem[hd_1 + 3]) << 0x18
    b = uint(c2da_mem[hd_1 + 4]) | uint(c2da_mem[hd_1 + 5]) << 0x8 | uint(c2da_mem[hd_1 + 6]) << 0x10 | uint(c2da_mem[hd_1 + 7]) << 0x18
    c = uint(c2da_mem[hd_1 + 8]) | uint(c2da_mem[hd_1 + 9]) << 0x8 | uint(c2da_mem[hd_1 + 10]) << 0x10 | uint(c2da_mem[hd_1 + 11]) << 0x18
    d = uint(c2da_mem[hd_1 + 12]) | uint(c2da_mem[hd_1 + 13]) << 0x8 | uint(c2da_mem[hd_1 + 14]) << 0x10 | uint(c2da_mem[hd_1 + 15]) << 0x18
    e = uint(c2da_mem[hd_1 + 16]) | uint(c2da_mem[hd_1 + 17]) << 0x8 | uint(c2da_mem[hd_1 + 18]) << 0x10 | uint(c2da_mem[hd_1 + 19]) << 0x18
    i = 0
    p2 = c2da_fp
    while (i < 16) {
        let c2da_fresh34 : int = data
        data++
        let c2da_fresh35 : uint8 = c2da_mem[c2da_fresh34]
        c2da_mem[p2 + 3] = c2da_fresh35
        let c2da_fresh36 : int = data
        data++
        let c2da_fresh37 : uint8 = c2da_mem[c2da_fresh36]
        c2da_mem[p2 + 2] = c2da_fresh37
        let c2da_fresh38 : int = data
        data++
        let c2da_fresh39 : uint8 = c2da_mem[c2da_fresh38]
        c2da_mem[p2 + 1] = c2da_fresh39
        let c2da_fresh40 : int = data
        data++
        let c2da_fresh41 : uint8 = c2da_mem[c2da_fresh40]
        c2da_mem[p2 + 0] = c2da_fresh41
        i++
        p2 += 4
    }
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (d ^ b & (c ^ d))) + 1518500249l + int64(uint(c2da_mem[c2da_fp + 0 * 4]) | uint(c2da_mem[c2da_fp + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 0 * 4 + 3]) << 0x18)))
    b = b << 30u | b >> uint(32 - 30)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (c ^ a & (b ^ c))) + 1518500249l + int64(uint(c2da_mem[c2da_fp + 1 * 4]) | uint(c2da_mem[c2da_fp + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 1 * 4 + 3]) << 0x18)))
    a = a << 30u | a >> uint(32 - 30)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (b ^ e & (a ^ b))) + 1518500249l + int64(uint(c2da_mem[c2da_fp + 2 * 4]) | uint(c2da_mem[c2da_fp + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 2 * 4 + 3]) << 0x18)))
    e = e << 30u | e >> uint(32 - 30)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (a ^ d & (e ^ a))) + 1518500249l + int64(uint(c2da_mem[c2da_fp + 3 * 4]) | uint(c2da_mem[c2da_fp + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3 * 4 + 3]) << 0x18)))
    d = d << 30u | d >> uint(32 - 30)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (e ^ c & (d ^ e))) + 1518500249l + int64(uint(c2da_mem[c2da_fp + 4 * 4]) | uint(c2da_mem[c2da_fp + 4 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 4 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 4 * 4 + 3]) << 0x18)))
    c = c << 30u | c >> uint(32 - 30)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (d ^ b & (c ^ d))) + 1518500249l + int64(uint(c2da_mem[c2da_fp + 5 * 4]) | uint(c2da_mem[c2da_fp + 5 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 5 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 5 * 4 + 3]) << 0x18)))
    b = b << 30u | b >> uint(32 - 30)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (c ^ a & (b ^ c))) + 1518500249l + int64(uint(c2da_mem[c2da_fp + 6 * 4]) | uint(c2da_mem[c2da_fp + 6 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 6 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 6 * 4 + 3]) << 0x18)))
    a = a << 30u | a >> uint(32 - 30)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (b ^ e & (a ^ b))) + 1518500249l + int64(uint(c2da_mem[c2da_fp + 7 * 4]) | uint(c2da_mem[c2da_fp + 7 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 7 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 7 * 4 + 3]) << 0x18)))
    e = e << 30u | e >> uint(32 - 30)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (a ^ d & (e ^ a))) + 1518500249l + int64(uint(c2da_mem[c2da_fp + 8 * 4]) | uint(c2da_mem[c2da_fp + 8 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 8 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 8 * 4 + 3]) << 0x18)))
    d = d << 30u | d >> uint(32 - 30)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (e ^ c & (d ^ e))) + 1518500249l + int64(uint(c2da_mem[c2da_fp + 9 * 4]) | uint(c2da_mem[c2da_fp + 9 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 9 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 9 * 4 + 3]) << 0x18)))
    c = c << 30u | c >> uint(32 - 30)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (d ^ b & (c ^ d))) + 1518500249l + int64(uint(c2da_mem[c2da_fp + 10 * 4]) | uint(c2da_mem[c2da_fp + 10 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 10 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 10 * 4 + 3]) << 0x18)))
    b = b << 30u | b >> uint(32 - 30)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (c ^ a & (b ^ c))) + 1518500249l + int64(uint(c2da_mem[c2da_fp + 11 * 4]) | uint(c2da_mem[c2da_fp + 11 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 11 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 11 * 4 + 3]) << 0x18)))
    a = a << 30u | a >> uint(32 - 30)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (b ^ e & (a ^ b))) + 1518500249l + int64(uint(c2da_mem[c2da_fp + 12 * 4]) | uint(c2da_mem[c2da_fp + 12 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 12 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 12 * 4 + 3]) << 0x18)))
    e = e << 30u | e >> uint(32 - 30)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (a ^ d & (e ^ a))) + 1518500249l + int64(uint(c2da_mem[c2da_fp + 13 * 4]) | uint(c2da_mem[c2da_fp + 13 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 13 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 13 * 4 + 3]) << 0x18)))
    d = d << 30u | d >> uint(32 - 30)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (e ^ c & (d ^ e))) + 1518500249l + int64(uint(c2da_mem[c2da_fp + 14 * 4]) | uint(c2da_mem[c2da_fp + 14 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 14 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 14 * 4 + 3]) << 0x18)))
    c = c << 30u | c >> uint(32 - 30)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (d ^ b & (c ^ d))) + 1518500249l + int64(uint(c2da_mem[c2da_fp + 15 * 4]) | uint(c2da_mem[c2da_fp + 15 * 4 + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 15 * 4 + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 15 * 4 + 3]) << 0x18)))
    b = b << 30u | b >> uint(32 - 30)
    let c2da_fresh42 : int = c2da_fp + (16 & 15) * 4
    let c2da_fresh43 : int = c2da_fp + (16 - 14 & 15) * 4
    let c2da_fresh44 : int = c2da_fp + (16 - 8 & 15) * 4
    let c2da_fresh45 : int = c2da_fp + (16 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh42]) | uint(c2da_mem[c2da_fresh42 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh42 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh42 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh43]) | uint(c2da_mem[c2da_fresh43 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh43 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh43 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh44]) | uint(c2da_mem[c2da_fresh44 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh44 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh44 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh45]) | uint(c2da_mem[c2da_fresh45 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh45 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh45 + 3]) << 0x18)
    let c2da_fresh46 : int = c2da_fp + (16 & 15) * 4
    let c2da_fresh47 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh48 : uint = c2da_fresh47
    c2da_mem[c2da_fresh46] = uint8(c2da_fresh48)
    c2da_mem[c2da_fresh46 + 1] = uint8(c2da_fresh48 >> 0x8)
    c2da_mem[c2da_fresh46 + 2] = uint8(c2da_fresh48 >> 0x10)
    c2da_mem[c2da_fresh46 + 3] = uint8(c2da_fresh48 >> 0x18)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (c ^ a & (b ^ c))) + 1518500249l + int64(c2da_fresh47)))
    a = a << 30u | a >> uint(32 - 30)
    let c2da_fresh49 : int = c2da_fp + (17 & 15) * 4
    let c2da_fresh50 : int = c2da_fp + (17 - 14 & 15) * 4
    let c2da_fresh51 : int = c2da_fp + (17 - 8 & 15) * 4
    let c2da_fresh52 : int = c2da_fp + (17 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh49]) | uint(c2da_mem[c2da_fresh49 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh49 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh49 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh50]) | uint(c2da_mem[c2da_fresh50 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh50 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh50 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh51]) | uint(c2da_mem[c2da_fresh51 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh51 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh51 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh52]) | uint(c2da_mem[c2da_fresh52 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh52 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh52 + 3]) << 0x18)
    let c2da_fresh53 : int = c2da_fp + (17 & 15) * 4
    let c2da_fresh54 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh55 : uint = c2da_fresh54
    c2da_mem[c2da_fresh53] = uint8(c2da_fresh55)
    c2da_mem[c2da_fresh53 + 1] = uint8(c2da_fresh55 >> 0x8)
    c2da_mem[c2da_fresh53 + 2] = uint8(c2da_fresh55 >> 0x10)
    c2da_mem[c2da_fresh53 + 3] = uint8(c2da_fresh55 >> 0x18)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (b ^ e & (a ^ b))) + 1518500249l + int64(c2da_fresh54)))
    e = e << 30u | e >> uint(32 - 30)
    let c2da_fresh56 : int = c2da_fp + (18 & 15) * 4
    let c2da_fresh57 : int = c2da_fp + (18 - 14 & 15) * 4
    let c2da_fresh58 : int = c2da_fp + (18 - 8 & 15) * 4
    let c2da_fresh59 : int = c2da_fp + (18 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh56]) | uint(c2da_mem[c2da_fresh56 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh56 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh56 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh57]) | uint(c2da_mem[c2da_fresh57 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh57 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh57 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh58]) | uint(c2da_mem[c2da_fresh58 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh58 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh58 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh59]) | uint(c2da_mem[c2da_fresh59 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh59 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh59 + 3]) << 0x18)
    let c2da_fresh60 : int = c2da_fp + (18 & 15) * 4
    let c2da_fresh61 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh62 : uint = c2da_fresh61
    c2da_mem[c2da_fresh60] = uint8(c2da_fresh62)
    c2da_mem[c2da_fresh60 + 1] = uint8(c2da_fresh62 >> 0x8)
    c2da_mem[c2da_fresh60 + 2] = uint8(c2da_fresh62 >> 0x10)
    c2da_mem[c2da_fresh60 + 3] = uint8(c2da_fresh62 >> 0x18)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (a ^ d & (e ^ a))) + 1518500249l + int64(c2da_fresh61)))
    d = d << 30u | d >> uint(32 - 30)
    let c2da_fresh63 : int = c2da_fp + (19 & 15) * 4
    let c2da_fresh64 : int = c2da_fp + (19 - 14 & 15) * 4
    let c2da_fresh65 : int = c2da_fp + (19 - 8 & 15) * 4
    let c2da_fresh66 : int = c2da_fp + (19 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh63]) | uint(c2da_mem[c2da_fresh63 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh63 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh63 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh64]) | uint(c2da_mem[c2da_fresh64 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh64 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh64 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh65]) | uint(c2da_mem[c2da_fresh65 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh65 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh65 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh66]) | uint(c2da_mem[c2da_fresh66 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh66 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh66 + 3]) << 0x18)
    let c2da_fresh67 : int = c2da_fp + (19 & 15) * 4
    let c2da_fresh68 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh69 : uint = c2da_fresh68
    c2da_mem[c2da_fresh67] = uint8(c2da_fresh69)
    c2da_mem[c2da_fresh67 + 1] = uint8(c2da_fresh69 >> 0x8)
    c2da_mem[c2da_fresh67 + 2] = uint8(c2da_fresh69 >> 0x10)
    c2da_mem[c2da_fresh67 + 3] = uint8(c2da_fresh69 >> 0x18)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (e ^ c & (d ^ e))) + 1518500249l + int64(c2da_fresh68)))
    c = c << 30u | c >> uint(32 - 30)
    let c2da_fresh70 : int = c2da_fp + (20 & 15) * 4
    let c2da_fresh71 : int = c2da_fp + (20 - 14 & 15) * 4
    let c2da_fresh72 : int = c2da_fp + (20 - 8 & 15) * 4
    let c2da_fresh73 : int = c2da_fp + (20 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh70]) | uint(c2da_mem[c2da_fresh70 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh70 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh70 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh71]) | uint(c2da_mem[c2da_fresh71 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh71 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh71 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh72]) | uint(c2da_mem[c2da_fresh72 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh72 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh72 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh73]) | uint(c2da_mem[c2da_fresh73 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh73 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh73 + 3]) << 0x18)
    let c2da_fresh74 : int = c2da_fp + (20 & 15) * 4
    let c2da_fresh75 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh76 : uint = c2da_fresh75
    c2da_mem[c2da_fresh74] = uint8(c2da_fresh76)
    c2da_mem[c2da_fresh74 + 1] = uint8(c2da_fresh76 >> 0x8)
    c2da_mem[c2da_fresh74 + 2] = uint8(c2da_fresh76 >> 0x10)
    c2da_mem[c2da_fresh74 + 3] = uint8(c2da_fresh76 >> 0x18)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b ^ c ^ d)) + 1859775393l + int64(c2da_fresh75)))
    b = b << 30u | b >> uint(32 - 30)
    let c2da_fresh77 : int = c2da_fp + (21 & 15) * 4
    let c2da_fresh78 : int = c2da_fp + (21 - 14 & 15) * 4
    let c2da_fresh79 : int = c2da_fp + (21 - 8 & 15) * 4
    let c2da_fresh80 : int = c2da_fp + (21 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh77]) | uint(c2da_mem[c2da_fresh77 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh77 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh77 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh78]) | uint(c2da_mem[c2da_fresh78 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh78 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh78 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh79]) | uint(c2da_mem[c2da_fresh79 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh79 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh79 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh80]) | uint(c2da_mem[c2da_fresh80 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh80 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh80 + 3]) << 0x18)
    let c2da_fresh81 : int = c2da_fp + (21 & 15) * 4
    let c2da_fresh82 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh83 : uint = c2da_fresh82
    c2da_mem[c2da_fresh81] = uint8(c2da_fresh83)
    c2da_mem[c2da_fresh81 + 1] = uint8(c2da_fresh83 >> 0x8)
    c2da_mem[c2da_fresh81 + 2] = uint8(c2da_fresh83 >> 0x10)
    c2da_mem[c2da_fresh81 + 3] = uint8(c2da_fresh83 >> 0x18)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a ^ b ^ c)) + 1859775393l + int64(c2da_fresh82)))
    a = a << 30u | a >> uint(32 - 30)
    let c2da_fresh84 : int = c2da_fp + (22 & 15) * 4
    let c2da_fresh85 : int = c2da_fp + (22 - 14 & 15) * 4
    let c2da_fresh86 : int = c2da_fp + (22 - 8 & 15) * 4
    let c2da_fresh87 : int = c2da_fp + (22 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh84]) | uint(c2da_mem[c2da_fresh84 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh84 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh84 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh85]) | uint(c2da_mem[c2da_fresh85 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh85 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh85 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh86]) | uint(c2da_mem[c2da_fresh86 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh86 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh86 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh87]) | uint(c2da_mem[c2da_fresh87 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh87 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh87 + 3]) << 0x18)
    let c2da_fresh88 : int = c2da_fp + (22 & 15) * 4
    let c2da_fresh89 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh90 : uint = c2da_fresh89
    c2da_mem[c2da_fresh88] = uint8(c2da_fresh90)
    c2da_mem[c2da_fresh88 + 1] = uint8(c2da_fresh90 >> 0x8)
    c2da_mem[c2da_fresh88 + 2] = uint8(c2da_fresh90 >> 0x10)
    c2da_mem[c2da_fresh88 + 3] = uint8(c2da_fresh90 >> 0x18)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e ^ a ^ b)) + 1859775393l + int64(c2da_fresh89)))
    e = e << 30u | e >> uint(32 - 30)
    let c2da_fresh91 : int = c2da_fp + (23 & 15) * 4
    let c2da_fresh92 : int = c2da_fp + (23 - 14 & 15) * 4
    let c2da_fresh93 : int = c2da_fp + (23 - 8 & 15) * 4
    let c2da_fresh94 : int = c2da_fp + (23 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh91]) | uint(c2da_mem[c2da_fresh91 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh91 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh91 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh92]) | uint(c2da_mem[c2da_fresh92 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh92 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh92 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh93]) | uint(c2da_mem[c2da_fresh93 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh93 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh93 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh94]) | uint(c2da_mem[c2da_fresh94 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh94 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh94 + 3]) << 0x18)
    let c2da_fresh95 : int = c2da_fp + (23 & 15) * 4
    let c2da_fresh96 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh97 : uint = c2da_fresh96
    c2da_mem[c2da_fresh95] = uint8(c2da_fresh97)
    c2da_mem[c2da_fresh95 + 1] = uint8(c2da_fresh97 >> 0x8)
    c2da_mem[c2da_fresh95 + 2] = uint8(c2da_fresh97 >> 0x10)
    c2da_mem[c2da_fresh95 + 3] = uint8(c2da_fresh97 >> 0x18)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d ^ e ^ a)) + 1859775393l + int64(c2da_fresh96)))
    d = d << 30u | d >> uint(32 - 30)
    let c2da_fresh98 : int = c2da_fp + (24 & 15) * 4
    let c2da_fresh99 : int = c2da_fp + (24 - 14 & 15) * 4
    let c2da_fresh100 : int = c2da_fp + (24 - 8 & 15) * 4
    let c2da_fresh101 : int = c2da_fp + (24 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh98]) | uint(c2da_mem[c2da_fresh98 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh98 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh98 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh99]) | uint(c2da_mem[c2da_fresh99 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh99 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh99 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh100]) | uint(c2da_mem[c2da_fresh100 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh100 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh100 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh101]) | uint(c2da_mem[c2da_fresh101 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh101 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh101 + 3]) << 0x18)
    let c2da_fresh102 : int = c2da_fp + (24 & 15) * 4
    let c2da_fresh103 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh104 : uint = c2da_fresh103
    c2da_mem[c2da_fresh102] = uint8(c2da_fresh104)
    c2da_mem[c2da_fresh102 + 1] = uint8(c2da_fresh104 >> 0x8)
    c2da_mem[c2da_fresh102 + 2] = uint8(c2da_fresh104 >> 0x10)
    c2da_mem[c2da_fresh102 + 3] = uint8(c2da_fresh104 >> 0x18)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c ^ d ^ e)) + 1859775393l + int64(c2da_fresh103)))
    c = c << 30u | c >> uint(32 - 30)
    let c2da_fresh105 : int = c2da_fp + (25 & 15) * 4
    let c2da_fresh106 : int = c2da_fp + (25 - 14 & 15) * 4
    let c2da_fresh107 : int = c2da_fp + (25 - 8 & 15) * 4
    let c2da_fresh108 : int = c2da_fp + (25 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh105]) | uint(c2da_mem[c2da_fresh105 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh105 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh105 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh106]) | uint(c2da_mem[c2da_fresh106 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh106 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh106 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh107]) | uint(c2da_mem[c2da_fresh107 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh107 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh107 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh108]) | uint(c2da_mem[c2da_fresh108 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh108 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh108 + 3]) << 0x18)
    let c2da_fresh109 : int = c2da_fp + (25 & 15) * 4
    let c2da_fresh110 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh111 : uint = c2da_fresh110
    c2da_mem[c2da_fresh109] = uint8(c2da_fresh111)
    c2da_mem[c2da_fresh109 + 1] = uint8(c2da_fresh111 >> 0x8)
    c2da_mem[c2da_fresh109 + 2] = uint8(c2da_fresh111 >> 0x10)
    c2da_mem[c2da_fresh109 + 3] = uint8(c2da_fresh111 >> 0x18)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b ^ c ^ d)) + 1859775393l + int64(c2da_fresh110)))
    b = b << 30u | b >> uint(32 - 30)
    let c2da_fresh112 : int = c2da_fp + (26 & 15) * 4
    let c2da_fresh113 : int = c2da_fp + (26 - 14 & 15) * 4
    let c2da_fresh114 : int = c2da_fp + (26 - 8 & 15) * 4
    let c2da_fresh115 : int = c2da_fp + (26 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh112]) | uint(c2da_mem[c2da_fresh112 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh112 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh112 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh113]) | uint(c2da_mem[c2da_fresh113 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh113 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh113 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh114]) | uint(c2da_mem[c2da_fresh114 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh114 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh114 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh115]) | uint(c2da_mem[c2da_fresh115 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh115 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh115 + 3]) << 0x18)
    let c2da_fresh116 : int = c2da_fp + (26 & 15) * 4
    let c2da_fresh117 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh118 : uint = c2da_fresh117
    c2da_mem[c2da_fresh116] = uint8(c2da_fresh118)
    c2da_mem[c2da_fresh116 + 1] = uint8(c2da_fresh118 >> 0x8)
    c2da_mem[c2da_fresh116 + 2] = uint8(c2da_fresh118 >> 0x10)
    c2da_mem[c2da_fresh116 + 3] = uint8(c2da_fresh118 >> 0x18)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a ^ b ^ c)) + 1859775393l + int64(c2da_fresh117)))
    a = a << 30u | a >> uint(32 - 30)
    let c2da_fresh119 : int = c2da_fp + (27 & 15) * 4
    let c2da_fresh120 : int = c2da_fp + (27 - 14 & 15) * 4
    let c2da_fresh121 : int = c2da_fp + (27 - 8 & 15) * 4
    let c2da_fresh122 : int = c2da_fp + (27 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh119]) | uint(c2da_mem[c2da_fresh119 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh119 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh119 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh120]) | uint(c2da_mem[c2da_fresh120 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh120 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh120 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh121]) | uint(c2da_mem[c2da_fresh121 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh121 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh121 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh122]) | uint(c2da_mem[c2da_fresh122 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh122 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh122 + 3]) << 0x18)
    let c2da_fresh123 : int = c2da_fp + (27 & 15) * 4
    let c2da_fresh124 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh125 : uint = c2da_fresh124
    c2da_mem[c2da_fresh123] = uint8(c2da_fresh125)
    c2da_mem[c2da_fresh123 + 1] = uint8(c2da_fresh125 >> 0x8)
    c2da_mem[c2da_fresh123 + 2] = uint8(c2da_fresh125 >> 0x10)
    c2da_mem[c2da_fresh123 + 3] = uint8(c2da_fresh125 >> 0x18)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e ^ a ^ b)) + 1859775393l + int64(c2da_fresh124)))
    e = e << 30u | e >> uint(32 - 30)
    let c2da_fresh126 : int = c2da_fp + (28 & 15) * 4
    let c2da_fresh127 : int = c2da_fp + (28 - 14 & 15) * 4
    let c2da_fresh128 : int = c2da_fp + (28 - 8 & 15) * 4
    let c2da_fresh129 : int = c2da_fp + (28 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh126]) | uint(c2da_mem[c2da_fresh126 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh126 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh126 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh127]) | uint(c2da_mem[c2da_fresh127 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh127 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh127 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh128]) | uint(c2da_mem[c2da_fresh128 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh128 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh128 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh129]) | uint(c2da_mem[c2da_fresh129 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh129 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh129 + 3]) << 0x18)
    let c2da_fresh130 : int = c2da_fp + (28 & 15) * 4
    let c2da_fresh131 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh132 : uint = c2da_fresh131
    c2da_mem[c2da_fresh130] = uint8(c2da_fresh132)
    c2da_mem[c2da_fresh130 + 1] = uint8(c2da_fresh132 >> 0x8)
    c2da_mem[c2da_fresh130 + 2] = uint8(c2da_fresh132 >> 0x10)
    c2da_mem[c2da_fresh130 + 3] = uint8(c2da_fresh132 >> 0x18)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d ^ e ^ a)) + 1859775393l + int64(c2da_fresh131)))
    d = d << 30u | d >> uint(32 - 30)
    let c2da_fresh133 : int = c2da_fp + (29 & 15) * 4
    let c2da_fresh134 : int = c2da_fp + (29 - 14 & 15) * 4
    let c2da_fresh135 : int = c2da_fp + (29 - 8 & 15) * 4
    let c2da_fresh136 : int = c2da_fp + (29 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh133]) | uint(c2da_mem[c2da_fresh133 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh133 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh133 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh134]) | uint(c2da_mem[c2da_fresh134 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh134 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh134 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh135]) | uint(c2da_mem[c2da_fresh135 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh135 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh135 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh136]) | uint(c2da_mem[c2da_fresh136 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh136 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh136 + 3]) << 0x18)
    let c2da_fresh137 : int = c2da_fp + (29 & 15) * 4
    let c2da_fresh138 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh139 : uint = c2da_fresh138
    c2da_mem[c2da_fresh137] = uint8(c2da_fresh139)
    c2da_mem[c2da_fresh137 + 1] = uint8(c2da_fresh139 >> 0x8)
    c2da_mem[c2da_fresh137 + 2] = uint8(c2da_fresh139 >> 0x10)
    c2da_mem[c2da_fresh137 + 3] = uint8(c2da_fresh139 >> 0x18)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c ^ d ^ e)) + 1859775393l + int64(c2da_fresh138)))
    c = c << 30u | c >> uint(32 - 30)
    let c2da_fresh140 : int = c2da_fp + (30 & 15) * 4
    let c2da_fresh141 : int = c2da_fp + (30 - 14 & 15) * 4
    let c2da_fresh142 : int = c2da_fp + (30 - 8 & 15) * 4
    let c2da_fresh143 : int = c2da_fp + (30 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh140]) | uint(c2da_mem[c2da_fresh140 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh140 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh140 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh141]) | uint(c2da_mem[c2da_fresh141 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh141 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh141 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh142]) | uint(c2da_mem[c2da_fresh142 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh142 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh142 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh143]) | uint(c2da_mem[c2da_fresh143 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh143 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh143 + 3]) << 0x18)
    let c2da_fresh144 : int = c2da_fp + (30 & 15) * 4
    let c2da_fresh145 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh146 : uint = c2da_fresh145
    c2da_mem[c2da_fresh144] = uint8(c2da_fresh146)
    c2da_mem[c2da_fresh144 + 1] = uint8(c2da_fresh146 >> 0x8)
    c2da_mem[c2da_fresh144 + 2] = uint8(c2da_fresh146 >> 0x10)
    c2da_mem[c2da_fresh144 + 3] = uint8(c2da_fresh146 >> 0x18)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b ^ c ^ d)) + 1859775393l + int64(c2da_fresh145)))
    b = b << 30u | b >> uint(32 - 30)
    let c2da_fresh147 : int = c2da_fp + (31 & 15) * 4
    let c2da_fresh148 : int = c2da_fp + (31 - 14 & 15) * 4
    let c2da_fresh149 : int = c2da_fp + (31 - 8 & 15) * 4
    let c2da_fresh150 : int = c2da_fp + (31 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh147]) | uint(c2da_mem[c2da_fresh147 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh147 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh147 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh148]) | uint(c2da_mem[c2da_fresh148 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh148 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh148 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh149]) | uint(c2da_mem[c2da_fresh149 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh149 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh149 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh150]) | uint(c2da_mem[c2da_fresh150 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh150 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh150 + 3]) << 0x18)
    let c2da_fresh151 : int = c2da_fp + (31 & 15) * 4
    let c2da_fresh152 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh153 : uint = c2da_fresh152
    c2da_mem[c2da_fresh151] = uint8(c2da_fresh153)
    c2da_mem[c2da_fresh151 + 1] = uint8(c2da_fresh153 >> 0x8)
    c2da_mem[c2da_fresh151 + 2] = uint8(c2da_fresh153 >> 0x10)
    c2da_mem[c2da_fresh151 + 3] = uint8(c2da_fresh153 >> 0x18)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a ^ b ^ c)) + 1859775393l + int64(c2da_fresh152)))
    a = a << 30u | a >> uint(32 - 30)
    let c2da_fresh154 : int = c2da_fp + (32 & 15) * 4
    let c2da_fresh155 : int = c2da_fp + (32 - 14 & 15) * 4
    let c2da_fresh156 : int = c2da_fp + (32 - 8 & 15) * 4
    let c2da_fresh157 : int = c2da_fp + (32 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh154]) | uint(c2da_mem[c2da_fresh154 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh154 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh154 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh155]) | uint(c2da_mem[c2da_fresh155 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh155 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh155 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh156]) | uint(c2da_mem[c2da_fresh156 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh156 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh156 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh157]) | uint(c2da_mem[c2da_fresh157 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh157 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh157 + 3]) << 0x18)
    let c2da_fresh158 : int = c2da_fp + (32 & 15) * 4
    let c2da_fresh159 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh160 : uint = c2da_fresh159
    c2da_mem[c2da_fresh158] = uint8(c2da_fresh160)
    c2da_mem[c2da_fresh158 + 1] = uint8(c2da_fresh160 >> 0x8)
    c2da_mem[c2da_fresh158 + 2] = uint8(c2da_fresh160 >> 0x10)
    c2da_mem[c2da_fresh158 + 3] = uint8(c2da_fresh160 >> 0x18)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e ^ a ^ b)) + 1859775393l + int64(c2da_fresh159)))
    e = e << 30u | e >> uint(32 - 30)
    let c2da_fresh161 : int = c2da_fp + (33 & 15) * 4
    let c2da_fresh162 : int = c2da_fp + (33 - 14 & 15) * 4
    let c2da_fresh163 : int = c2da_fp + (33 - 8 & 15) * 4
    let c2da_fresh164 : int = c2da_fp + (33 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh161]) | uint(c2da_mem[c2da_fresh161 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh161 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh161 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh162]) | uint(c2da_mem[c2da_fresh162 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh162 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh162 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh163]) | uint(c2da_mem[c2da_fresh163 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh163 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh163 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh164]) | uint(c2da_mem[c2da_fresh164 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh164 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh164 + 3]) << 0x18)
    let c2da_fresh165 : int = c2da_fp + (33 & 15) * 4
    let c2da_fresh166 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh167 : uint = c2da_fresh166
    c2da_mem[c2da_fresh165] = uint8(c2da_fresh167)
    c2da_mem[c2da_fresh165 + 1] = uint8(c2da_fresh167 >> 0x8)
    c2da_mem[c2da_fresh165 + 2] = uint8(c2da_fresh167 >> 0x10)
    c2da_mem[c2da_fresh165 + 3] = uint8(c2da_fresh167 >> 0x18)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d ^ e ^ a)) + 1859775393l + int64(c2da_fresh166)))
    d = d << 30u | d >> uint(32 - 30)
    let c2da_fresh168 : int = c2da_fp + (34 & 15) * 4
    let c2da_fresh169 : int = c2da_fp + (34 - 14 & 15) * 4
    let c2da_fresh170 : int = c2da_fp + (34 - 8 & 15) * 4
    let c2da_fresh171 : int = c2da_fp + (34 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh168]) | uint(c2da_mem[c2da_fresh168 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh168 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh168 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh169]) | uint(c2da_mem[c2da_fresh169 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh169 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh169 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh170]) | uint(c2da_mem[c2da_fresh170 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh170 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh170 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh171]) | uint(c2da_mem[c2da_fresh171 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh171 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh171 + 3]) << 0x18)
    let c2da_fresh172 : int = c2da_fp + (34 & 15) * 4
    let c2da_fresh173 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh174 : uint = c2da_fresh173
    c2da_mem[c2da_fresh172] = uint8(c2da_fresh174)
    c2da_mem[c2da_fresh172 + 1] = uint8(c2da_fresh174 >> 0x8)
    c2da_mem[c2da_fresh172 + 2] = uint8(c2da_fresh174 >> 0x10)
    c2da_mem[c2da_fresh172 + 3] = uint8(c2da_fresh174 >> 0x18)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c ^ d ^ e)) + 1859775393l + int64(c2da_fresh173)))
    c = c << 30u | c >> uint(32 - 30)
    let c2da_fresh175 : int = c2da_fp + (35 & 15) * 4
    let c2da_fresh176 : int = c2da_fp + (35 - 14 & 15) * 4
    let c2da_fresh177 : int = c2da_fp + (35 - 8 & 15) * 4
    let c2da_fresh178 : int = c2da_fp + (35 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh175]) | uint(c2da_mem[c2da_fresh175 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh175 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh175 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh176]) | uint(c2da_mem[c2da_fresh176 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh176 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh176 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh177]) | uint(c2da_mem[c2da_fresh177 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh177 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh177 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh178]) | uint(c2da_mem[c2da_fresh178 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh178 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh178 + 3]) << 0x18)
    let c2da_fresh179 : int = c2da_fp + (35 & 15) * 4
    let c2da_fresh180 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh181 : uint = c2da_fresh180
    c2da_mem[c2da_fresh179] = uint8(c2da_fresh181)
    c2da_mem[c2da_fresh179 + 1] = uint8(c2da_fresh181 >> 0x8)
    c2da_mem[c2da_fresh179 + 2] = uint8(c2da_fresh181 >> 0x10)
    c2da_mem[c2da_fresh179 + 3] = uint8(c2da_fresh181 >> 0x18)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b ^ c ^ d)) + 1859775393l + int64(c2da_fresh180)))
    b = b << 30u | b >> uint(32 - 30)
    let c2da_fresh182 : int = c2da_fp + (36 & 15) * 4
    let c2da_fresh183 : int = c2da_fp + (36 - 14 & 15) * 4
    let c2da_fresh184 : int = c2da_fp + (36 - 8 & 15) * 4
    let c2da_fresh185 : int = c2da_fp + (36 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh182]) | uint(c2da_mem[c2da_fresh182 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh182 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh182 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh183]) | uint(c2da_mem[c2da_fresh183 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh183 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh183 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh184]) | uint(c2da_mem[c2da_fresh184 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh184 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh184 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh185]) | uint(c2da_mem[c2da_fresh185 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh185 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh185 + 3]) << 0x18)
    let c2da_fresh186 : int = c2da_fp + (36 & 15) * 4
    let c2da_fresh187 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh188 : uint = c2da_fresh187
    c2da_mem[c2da_fresh186] = uint8(c2da_fresh188)
    c2da_mem[c2da_fresh186 + 1] = uint8(c2da_fresh188 >> 0x8)
    c2da_mem[c2da_fresh186 + 2] = uint8(c2da_fresh188 >> 0x10)
    c2da_mem[c2da_fresh186 + 3] = uint8(c2da_fresh188 >> 0x18)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a ^ b ^ c)) + 1859775393l + int64(c2da_fresh187)))
    a = a << 30u | a >> uint(32 - 30)
    let c2da_fresh189 : int = c2da_fp + (37 & 15) * 4
    let c2da_fresh190 : int = c2da_fp + (37 - 14 & 15) * 4
    let c2da_fresh191 : int = c2da_fp + (37 - 8 & 15) * 4
    let c2da_fresh192 : int = c2da_fp + (37 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh189]) | uint(c2da_mem[c2da_fresh189 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh189 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh189 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh190]) | uint(c2da_mem[c2da_fresh190 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh190 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh190 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh191]) | uint(c2da_mem[c2da_fresh191 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh191 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh191 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh192]) | uint(c2da_mem[c2da_fresh192 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh192 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh192 + 3]) << 0x18)
    let c2da_fresh193 : int = c2da_fp + (37 & 15) * 4
    let c2da_fresh194 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh195 : uint = c2da_fresh194
    c2da_mem[c2da_fresh193] = uint8(c2da_fresh195)
    c2da_mem[c2da_fresh193 + 1] = uint8(c2da_fresh195 >> 0x8)
    c2da_mem[c2da_fresh193 + 2] = uint8(c2da_fresh195 >> 0x10)
    c2da_mem[c2da_fresh193 + 3] = uint8(c2da_fresh195 >> 0x18)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e ^ a ^ b)) + 1859775393l + int64(c2da_fresh194)))
    e = e << 30u | e >> uint(32 - 30)
    let c2da_fresh196 : int = c2da_fp + (38 & 15) * 4
    let c2da_fresh197 : int = c2da_fp + (38 - 14 & 15) * 4
    let c2da_fresh198 : int = c2da_fp + (38 - 8 & 15) * 4
    let c2da_fresh199 : int = c2da_fp + (38 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh196]) | uint(c2da_mem[c2da_fresh196 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh196 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh196 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh197]) | uint(c2da_mem[c2da_fresh197 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh197 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh197 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh198]) | uint(c2da_mem[c2da_fresh198 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh198 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh198 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh199]) | uint(c2da_mem[c2da_fresh199 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh199 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh199 + 3]) << 0x18)
    let c2da_fresh200 : int = c2da_fp + (38 & 15) * 4
    let c2da_fresh201 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh202 : uint = c2da_fresh201
    c2da_mem[c2da_fresh200] = uint8(c2da_fresh202)
    c2da_mem[c2da_fresh200 + 1] = uint8(c2da_fresh202 >> 0x8)
    c2da_mem[c2da_fresh200 + 2] = uint8(c2da_fresh202 >> 0x10)
    c2da_mem[c2da_fresh200 + 3] = uint8(c2da_fresh202 >> 0x18)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d ^ e ^ a)) + 1859775393l + int64(c2da_fresh201)))
    d = d << 30u | d >> uint(32 - 30)
    let c2da_fresh203 : int = c2da_fp + (39 & 15) * 4
    let c2da_fresh204 : int = c2da_fp + (39 - 14 & 15) * 4
    let c2da_fresh205 : int = c2da_fp + (39 - 8 & 15) * 4
    let c2da_fresh206 : int = c2da_fp + (39 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh203]) | uint(c2da_mem[c2da_fresh203 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh203 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh203 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh204]) | uint(c2da_mem[c2da_fresh204 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh204 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh204 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh205]) | uint(c2da_mem[c2da_fresh205 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh205 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh205 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh206]) | uint(c2da_mem[c2da_fresh206 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh206 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh206 + 3]) << 0x18)
    let c2da_fresh207 : int = c2da_fp + (39 & 15) * 4
    let c2da_fresh208 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh209 : uint = c2da_fresh208
    c2da_mem[c2da_fresh207] = uint8(c2da_fresh209)
    c2da_mem[c2da_fresh207 + 1] = uint8(c2da_fresh209 >> 0x8)
    c2da_mem[c2da_fresh207 + 2] = uint8(c2da_fresh209 >> 0x10)
    c2da_mem[c2da_fresh207 + 3] = uint8(c2da_fresh209 >> 0x18)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c ^ d ^ e)) + 1859775393l + int64(c2da_fresh208)))
    c = c << 30u | c >> uint(32 - 30)
    let c2da_fresh210 : int = c2da_fp + (40 & 15) * 4
    let c2da_fresh211 : int = c2da_fp + (40 - 14 & 15) * 4
    let c2da_fresh212 : int = c2da_fp + (40 - 8 & 15) * 4
    let c2da_fresh213 : int = c2da_fp + (40 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh210]) | uint(c2da_mem[c2da_fresh210 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh210 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh210 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh211]) | uint(c2da_mem[c2da_fresh211 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh211 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh211 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh212]) | uint(c2da_mem[c2da_fresh212 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh212 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh212 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh213]) | uint(c2da_mem[c2da_fresh213 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh213 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh213 + 3]) << 0x18)
    let c2da_fresh214 : int = c2da_fp + (40 & 15) * 4
    let c2da_fresh215 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh216 : uint = c2da_fresh215
    c2da_mem[c2da_fresh214] = uint8(c2da_fresh216)
    c2da_mem[c2da_fresh214 + 1] = uint8(c2da_fresh216 >> 0x8)
    c2da_mem[c2da_fresh214 + 2] = uint8(c2da_fresh216 >> 0x10)
    c2da_mem[c2da_fresh214 + 3] = uint8(c2da_fresh216 >> 0x18)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b & c | d & (b | c))) + 2400959708l + int64(c2da_fresh215)))
    b = b << 30u | b >> uint(32 - 30)
    let c2da_fresh217 : int = c2da_fp + (41 & 15) * 4
    let c2da_fresh218 : int = c2da_fp + (41 - 14 & 15) * 4
    let c2da_fresh219 : int = c2da_fp + (41 - 8 & 15) * 4
    let c2da_fresh220 : int = c2da_fp + (41 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh217]) | uint(c2da_mem[c2da_fresh217 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh217 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh217 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh218]) | uint(c2da_mem[c2da_fresh218 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh218 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh218 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh219]) | uint(c2da_mem[c2da_fresh219 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh219 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh219 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh220]) | uint(c2da_mem[c2da_fresh220 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh220 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh220 + 3]) << 0x18)
    let c2da_fresh221 : int = c2da_fp + (41 & 15) * 4
    let c2da_fresh222 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh223 : uint = c2da_fresh222
    c2da_mem[c2da_fresh221] = uint8(c2da_fresh223)
    c2da_mem[c2da_fresh221 + 1] = uint8(c2da_fresh223 >> 0x8)
    c2da_mem[c2da_fresh221 + 2] = uint8(c2da_fresh223 >> 0x10)
    c2da_mem[c2da_fresh221 + 3] = uint8(c2da_fresh223 >> 0x18)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a & b | c & (a | b))) + 2400959708l + int64(c2da_fresh222)))
    a = a << 30u | a >> uint(32 - 30)
    let c2da_fresh224 : int = c2da_fp + (42 & 15) * 4
    let c2da_fresh225 : int = c2da_fp + (42 - 14 & 15) * 4
    let c2da_fresh226 : int = c2da_fp + (42 - 8 & 15) * 4
    let c2da_fresh227 : int = c2da_fp + (42 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh224]) | uint(c2da_mem[c2da_fresh224 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh224 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh224 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh225]) | uint(c2da_mem[c2da_fresh225 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh225 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh225 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh226]) | uint(c2da_mem[c2da_fresh226 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh226 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh226 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh227]) | uint(c2da_mem[c2da_fresh227 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh227 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh227 + 3]) << 0x18)
    let c2da_fresh228 : int = c2da_fp + (42 & 15) * 4
    let c2da_fresh229 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh230 : uint = c2da_fresh229
    c2da_mem[c2da_fresh228] = uint8(c2da_fresh230)
    c2da_mem[c2da_fresh228 + 1] = uint8(c2da_fresh230 >> 0x8)
    c2da_mem[c2da_fresh228 + 2] = uint8(c2da_fresh230 >> 0x10)
    c2da_mem[c2da_fresh228 + 3] = uint8(c2da_fresh230 >> 0x18)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e & a | b & (e | a))) + 2400959708l + int64(c2da_fresh229)))
    e = e << 30u | e >> uint(32 - 30)
    let c2da_fresh231 : int = c2da_fp + (43 & 15) * 4
    let c2da_fresh232 : int = c2da_fp + (43 - 14 & 15) * 4
    let c2da_fresh233 : int = c2da_fp + (43 - 8 & 15) * 4
    let c2da_fresh234 : int = c2da_fp + (43 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh231]) | uint(c2da_mem[c2da_fresh231 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh231 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh231 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh232]) | uint(c2da_mem[c2da_fresh232 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh232 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh232 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh233]) | uint(c2da_mem[c2da_fresh233 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh233 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh233 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh234]) | uint(c2da_mem[c2da_fresh234 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh234 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh234 + 3]) << 0x18)
    let c2da_fresh235 : int = c2da_fp + (43 & 15) * 4
    let c2da_fresh236 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh237 : uint = c2da_fresh236
    c2da_mem[c2da_fresh235] = uint8(c2da_fresh237)
    c2da_mem[c2da_fresh235 + 1] = uint8(c2da_fresh237 >> 0x8)
    c2da_mem[c2da_fresh235 + 2] = uint8(c2da_fresh237 >> 0x10)
    c2da_mem[c2da_fresh235 + 3] = uint8(c2da_fresh237 >> 0x18)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d & e | a & (d | e))) + 2400959708l + int64(c2da_fresh236)))
    d = d << 30u | d >> uint(32 - 30)
    let c2da_fresh238 : int = c2da_fp + (44 & 15) * 4
    let c2da_fresh239 : int = c2da_fp + (44 - 14 & 15) * 4
    let c2da_fresh240 : int = c2da_fp + (44 - 8 & 15) * 4
    let c2da_fresh241 : int = c2da_fp + (44 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh238]) | uint(c2da_mem[c2da_fresh238 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh238 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh238 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh239]) | uint(c2da_mem[c2da_fresh239 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh239 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh239 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh240]) | uint(c2da_mem[c2da_fresh240 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh240 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh240 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh241]) | uint(c2da_mem[c2da_fresh241 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh241 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh241 + 3]) << 0x18)
    let c2da_fresh242 : int = c2da_fp + (44 & 15) * 4
    let c2da_fresh243 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh244 : uint = c2da_fresh243
    c2da_mem[c2da_fresh242] = uint8(c2da_fresh244)
    c2da_mem[c2da_fresh242 + 1] = uint8(c2da_fresh244 >> 0x8)
    c2da_mem[c2da_fresh242 + 2] = uint8(c2da_fresh244 >> 0x10)
    c2da_mem[c2da_fresh242 + 3] = uint8(c2da_fresh244 >> 0x18)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c & d | e & (c | d))) + 2400959708l + int64(c2da_fresh243)))
    c = c << 30u | c >> uint(32 - 30)
    let c2da_fresh245 : int = c2da_fp + (45 & 15) * 4
    let c2da_fresh246 : int = c2da_fp + (45 - 14 & 15) * 4
    let c2da_fresh247 : int = c2da_fp + (45 - 8 & 15) * 4
    let c2da_fresh248 : int = c2da_fp + (45 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh245]) | uint(c2da_mem[c2da_fresh245 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh245 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh245 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh246]) | uint(c2da_mem[c2da_fresh246 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh246 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh246 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh247]) | uint(c2da_mem[c2da_fresh247 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh247 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh247 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh248]) | uint(c2da_mem[c2da_fresh248 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh248 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh248 + 3]) << 0x18)
    let c2da_fresh249 : int = c2da_fp + (45 & 15) * 4
    let c2da_fresh250 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh251 : uint = c2da_fresh250
    c2da_mem[c2da_fresh249] = uint8(c2da_fresh251)
    c2da_mem[c2da_fresh249 + 1] = uint8(c2da_fresh251 >> 0x8)
    c2da_mem[c2da_fresh249 + 2] = uint8(c2da_fresh251 >> 0x10)
    c2da_mem[c2da_fresh249 + 3] = uint8(c2da_fresh251 >> 0x18)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b & c | d & (b | c))) + 2400959708l + int64(c2da_fresh250)))
    b = b << 30u | b >> uint(32 - 30)
    let c2da_fresh252 : int = c2da_fp + (46 & 15) * 4
    let c2da_fresh253 : int = c2da_fp + (46 - 14 & 15) * 4
    let c2da_fresh254 : int = c2da_fp + (46 - 8 & 15) * 4
    let c2da_fresh255 : int = c2da_fp + (46 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh252]) | uint(c2da_mem[c2da_fresh252 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh252 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh252 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh253]) | uint(c2da_mem[c2da_fresh253 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh253 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh253 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh254]) | uint(c2da_mem[c2da_fresh254 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh254 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh254 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh255]) | uint(c2da_mem[c2da_fresh255 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh255 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh255 + 3]) << 0x18)
    let c2da_fresh256 : int = c2da_fp + (46 & 15) * 4
    let c2da_fresh257 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh258 : uint = c2da_fresh257
    c2da_mem[c2da_fresh256] = uint8(c2da_fresh258)
    c2da_mem[c2da_fresh256 + 1] = uint8(c2da_fresh258 >> 0x8)
    c2da_mem[c2da_fresh256 + 2] = uint8(c2da_fresh258 >> 0x10)
    c2da_mem[c2da_fresh256 + 3] = uint8(c2da_fresh258 >> 0x18)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a & b | c & (a | b))) + 2400959708l + int64(c2da_fresh257)))
    a = a << 30u | a >> uint(32 - 30)
    let c2da_fresh259 : int = c2da_fp + (47 & 15) * 4
    let c2da_fresh260 : int = c2da_fp + (47 - 14 & 15) * 4
    let c2da_fresh261 : int = c2da_fp + (47 - 8 & 15) * 4
    let c2da_fresh262 : int = c2da_fp + (47 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh259]) | uint(c2da_mem[c2da_fresh259 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh259 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh259 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh260]) | uint(c2da_mem[c2da_fresh260 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh260 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh260 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh261]) | uint(c2da_mem[c2da_fresh261 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh261 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh261 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh262]) | uint(c2da_mem[c2da_fresh262 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh262 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh262 + 3]) << 0x18)
    let c2da_fresh263 : int = c2da_fp + (47 & 15) * 4
    let c2da_fresh264 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh265 : uint = c2da_fresh264
    c2da_mem[c2da_fresh263] = uint8(c2da_fresh265)
    c2da_mem[c2da_fresh263 + 1] = uint8(c2da_fresh265 >> 0x8)
    c2da_mem[c2da_fresh263 + 2] = uint8(c2da_fresh265 >> 0x10)
    c2da_mem[c2da_fresh263 + 3] = uint8(c2da_fresh265 >> 0x18)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e & a | b & (e | a))) + 2400959708l + int64(c2da_fresh264)))
    e = e << 30u | e >> uint(32 - 30)
    let c2da_fresh266 : int = c2da_fp + (48 & 15) * 4
    let c2da_fresh267 : int = c2da_fp + (48 - 14 & 15) * 4
    let c2da_fresh268 : int = c2da_fp + (48 - 8 & 15) * 4
    let c2da_fresh269 : int = c2da_fp + (48 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh266]) | uint(c2da_mem[c2da_fresh266 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh266 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh266 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh267]) | uint(c2da_mem[c2da_fresh267 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh267 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh267 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh268]) | uint(c2da_mem[c2da_fresh268 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh268 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh268 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh269]) | uint(c2da_mem[c2da_fresh269 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh269 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh269 + 3]) << 0x18)
    let c2da_fresh270 : int = c2da_fp + (48 & 15) * 4
    let c2da_fresh271 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh272 : uint = c2da_fresh271
    c2da_mem[c2da_fresh270] = uint8(c2da_fresh272)
    c2da_mem[c2da_fresh270 + 1] = uint8(c2da_fresh272 >> 0x8)
    c2da_mem[c2da_fresh270 + 2] = uint8(c2da_fresh272 >> 0x10)
    c2da_mem[c2da_fresh270 + 3] = uint8(c2da_fresh272 >> 0x18)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d & e | a & (d | e))) + 2400959708l + int64(c2da_fresh271)))
    d = d << 30u | d >> uint(32 - 30)
    let c2da_fresh273 : int = c2da_fp + (49 & 15) * 4
    let c2da_fresh274 : int = c2da_fp + (49 - 14 & 15) * 4
    let c2da_fresh275 : int = c2da_fp + (49 - 8 & 15) * 4
    let c2da_fresh276 : int = c2da_fp + (49 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh273]) | uint(c2da_mem[c2da_fresh273 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh273 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh273 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh274]) | uint(c2da_mem[c2da_fresh274 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh274 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh274 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh275]) | uint(c2da_mem[c2da_fresh275 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh275 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh275 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh276]) | uint(c2da_mem[c2da_fresh276 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh276 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh276 + 3]) << 0x18)
    let c2da_fresh277 : int = c2da_fp + (49 & 15) * 4
    let c2da_fresh278 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh279 : uint = c2da_fresh278
    c2da_mem[c2da_fresh277] = uint8(c2da_fresh279)
    c2da_mem[c2da_fresh277 + 1] = uint8(c2da_fresh279 >> 0x8)
    c2da_mem[c2da_fresh277 + 2] = uint8(c2da_fresh279 >> 0x10)
    c2da_mem[c2da_fresh277 + 3] = uint8(c2da_fresh279 >> 0x18)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c & d | e & (c | d))) + 2400959708l + int64(c2da_fresh278)))
    c = c << 30u | c >> uint(32 - 30)
    let c2da_fresh280 : int = c2da_fp + (50 & 15) * 4
    let c2da_fresh281 : int = c2da_fp + (50 - 14 & 15) * 4
    let c2da_fresh282 : int = c2da_fp + (50 - 8 & 15) * 4
    let c2da_fresh283 : int = c2da_fp + (50 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh280]) | uint(c2da_mem[c2da_fresh280 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh280 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh280 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh281]) | uint(c2da_mem[c2da_fresh281 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh281 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh281 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh282]) | uint(c2da_mem[c2da_fresh282 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh282 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh282 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh283]) | uint(c2da_mem[c2da_fresh283 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh283 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh283 + 3]) << 0x18)
    let c2da_fresh284 : int = c2da_fp + (50 & 15) * 4
    let c2da_fresh285 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh286 : uint = c2da_fresh285
    c2da_mem[c2da_fresh284] = uint8(c2da_fresh286)
    c2da_mem[c2da_fresh284 + 1] = uint8(c2da_fresh286 >> 0x8)
    c2da_mem[c2da_fresh284 + 2] = uint8(c2da_fresh286 >> 0x10)
    c2da_mem[c2da_fresh284 + 3] = uint8(c2da_fresh286 >> 0x18)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b & c | d & (b | c))) + 2400959708l + int64(c2da_fresh285)))
    b = b << 30u | b >> uint(32 - 30)
    let c2da_fresh287 : int = c2da_fp + (51 & 15) * 4
    let c2da_fresh288 : int = c2da_fp + (51 - 14 & 15) * 4
    let c2da_fresh289 : int = c2da_fp + (51 - 8 & 15) * 4
    let c2da_fresh290 : int = c2da_fp + (51 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh287]) | uint(c2da_mem[c2da_fresh287 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh287 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh287 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh288]) | uint(c2da_mem[c2da_fresh288 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh288 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh288 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh289]) | uint(c2da_mem[c2da_fresh289 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh289 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh289 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh290]) | uint(c2da_mem[c2da_fresh290 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh290 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh290 + 3]) << 0x18)
    let c2da_fresh291 : int = c2da_fp + (51 & 15) * 4
    let c2da_fresh292 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh293 : uint = c2da_fresh292
    c2da_mem[c2da_fresh291] = uint8(c2da_fresh293)
    c2da_mem[c2da_fresh291 + 1] = uint8(c2da_fresh293 >> 0x8)
    c2da_mem[c2da_fresh291 + 2] = uint8(c2da_fresh293 >> 0x10)
    c2da_mem[c2da_fresh291 + 3] = uint8(c2da_fresh293 >> 0x18)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a & b | c & (a | b))) + 2400959708l + int64(c2da_fresh292)))
    a = a << 30u | a >> uint(32 - 30)
    let c2da_fresh294 : int = c2da_fp + (52 & 15) * 4
    let c2da_fresh295 : int = c2da_fp + (52 - 14 & 15) * 4
    let c2da_fresh296 : int = c2da_fp + (52 - 8 & 15) * 4
    let c2da_fresh297 : int = c2da_fp + (52 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh294]) | uint(c2da_mem[c2da_fresh294 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh294 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh294 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh295]) | uint(c2da_mem[c2da_fresh295 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh295 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh295 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh296]) | uint(c2da_mem[c2da_fresh296 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh296 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh296 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh297]) | uint(c2da_mem[c2da_fresh297 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh297 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh297 + 3]) << 0x18)
    let c2da_fresh298 : int = c2da_fp + (52 & 15) * 4
    let c2da_fresh299 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh300 : uint = c2da_fresh299
    c2da_mem[c2da_fresh298] = uint8(c2da_fresh300)
    c2da_mem[c2da_fresh298 + 1] = uint8(c2da_fresh300 >> 0x8)
    c2da_mem[c2da_fresh298 + 2] = uint8(c2da_fresh300 >> 0x10)
    c2da_mem[c2da_fresh298 + 3] = uint8(c2da_fresh300 >> 0x18)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e & a | b & (e | a))) + 2400959708l + int64(c2da_fresh299)))
    e = e << 30u | e >> uint(32 - 30)
    let c2da_fresh301 : int = c2da_fp + (53 & 15) * 4
    let c2da_fresh302 : int = c2da_fp + (53 - 14 & 15) * 4
    let c2da_fresh303 : int = c2da_fp + (53 - 8 & 15) * 4
    let c2da_fresh304 : int = c2da_fp + (53 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh301]) | uint(c2da_mem[c2da_fresh301 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh301 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh301 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh302]) | uint(c2da_mem[c2da_fresh302 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh302 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh302 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh303]) | uint(c2da_mem[c2da_fresh303 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh303 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh303 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh304]) | uint(c2da_mem[c2da_fresh304 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh304 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh304 + 3]) << 0x18)
    let c2da_fresh305 : int = c2da_fp + (53 & 15) * 4
    let c2da_fresh306 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh307 : uint = c2da_fresh306
    c2da_mem[c2da_fresh305] = uint8(c2da_fresh307)
    c2da_mem[c2da_fresh305 + 1] = uint8(c2da_fresh307 >> 0x8)
    c2da_mem[c2da_fresh305 + 2] = uint8(c2da_fresh307 >> 0x10)
    c2da_mem[c2da_fresh305 + 3] = uint8(c2da_fresh307 >> 0x18)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d & e | a & (d | e))) + 2400959708l + int64(c2da_fresh306)))
    d = d << 30u | d >> uint(32 - 30)
    let c2da_fresh308 : int = c2da_fp + (54 & 15) * 4
    let c2da_fresh309 : int = c2da_fp + (54 - 14 & 15) * 4
    let c2da_fresh310 : int = c2da_fp + (54 - 8 & 15) * 4
    let c2da_fresh311 : int = c2da_fp + (54 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh308]) | uint(c2da_mem[c2da_fresh308 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh308 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh308 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh309]) | uint(c2da_mem[c2da_fresh309 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh309 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh309 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh310]) | uint(c2da_mem[c2da_fresh310 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh310 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh310 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh311]) | uint(c2da_mem[c2da_fresh311 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh311 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh311 + 3]) << 0x18)
    let c2da_fresh312 : int = c2da_fp + (54 & 15) * 4
    let c2da_fresh313 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh314 : uint = c2da_fresh313
    c2da_mem[c2da_fresh312] = uint8(c2da_fresh314)
    c2da_mem[c2da_fresh312 + 1] = uint8(c2da_fresh314 >> 0x8)
    c2da_mem[c2da_fresh312 + 2] = uint8(c2da_fresh314 >> 0x10)
    c2da_mem[c2da_fresh312 + 3] = uint8(c2da_fresh314 >> 0x18)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c & d | e & (c | d))) + 2400959708l + int64(c2da_fresh313)))
    c = c << 30u | c >> uint(32 - 30)
    let c2da_fresh315 : int = c2da_fp + (55 & 15) * 4
    let c2da_fresh316 : int = c2da_fp + (55 - 14 & 15) * 4
    let c2da_fresh317 : int = c2da_fp + (55 - 8 & 15) * 4
    let c2da_fresh318 : int = c2da_fp + (55 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh315]) | uint(c2da_mem[c2da_fresh315 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh315 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh315 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh316]) | uint(c2da_mem[c2da_fresh316 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh316 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh316 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh317]) | uint(c2da_mem[c2da_fresh317 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh317 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh317 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh318]) | uint(c2da_mem[c2da_fresh318 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh318 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh318 + 3]) << 0x18)
    let c2da_fresh319 : int = c2da_fp + (55 & 15) * 4
    let c2da_fresh320 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh321 : uint = c2da_fresh320
    c2da_mem[c2da_fresh319] = uint8(c2da_fresh321)
    c2da_mem[c2da_fresh319 + 1] = uint8(c2da_fresh321 >> 0x8)
    c2da_mem[c2da_fresh319 + 2] = uint8(c2da_fresh321 >> 0x10)
    c2da_mem[c2da_fresh319 + 3] = uint8(c2da_fresh321 >> 0x18)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b & c | d & (b | c))) + 2400959708l + int64(c2da_fresh320)))
    b = b << 30u | b >> uint(32 - 30)
    let c2da_fresh322 : int = c2da_fp + (56 & 15) * 4
    let c2da_fresh323 : int = c2da_fp + (56 - 14 & 15) * 4
    let c2da_fresh324 : int = c2da_fp + (56 - 8 & 15) * 4
    let c2da_fresh325 : int = c2da_fp + (56 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh322]) | uint(c2da_mem[c2da_fresh322 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh322 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh322 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh323]) | uint(c2da_mem[c2da_fresh323 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh323 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh323 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh324]) | uint(c2da_mem[c2da_fresh324 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh324 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh324 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh325]) | uint(c2da_mem[c2da_fresh325 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh325 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh325 + 3]) << 0x18)
    let c2da_fresh326 : int = c2da_fp + (56 & 15) * 4
    let c2da_fresh327 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh328 : uint = c2da_fresh327
    c2da_mem[c2da_fresh326] = uint8(c2da_fresh328)
    c2da_mem[c2da_fresh326 + 1] = uint8(c2da_fresh328 >> 0x8)
    c2da_mem[c2da_fresh326 + 2] = uint8(c2da_fresh328 >> 0x10)
    c2da_mem[c2da_fresh326 + 3] = uint8(c2da_fresh328 >> 0x18)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a & b | c & (a | b))) + 2400959708l + int64(c2da_fresh327)))
    a = a << 30u | a >> uint(32 - 30)
    let c2da_fresh329 : int = c2da_fp + (57 & 15) * 4
    let c2da_fresh330 : int = c2da_fp + (57 - 14 & 15) * 4
    let c2da_fresh331 : int = c2da_fp + (57 - 8 & 15) * 4
    let c2da_fresh332 : int = c2da_fp + (57 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh329]) | uint(c2da_mem[c2da_fresh329 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh329 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh329 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh330]) | uint(c2da_mem[c2da_fresh330 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh330 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh330 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh331]) | uint(c2da_mem[c2da_fresh331 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh331 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh331 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh332]) | uint(c2da_mem[c2da_fresh332 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh332 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh332 + 3]) << 0x18)
    let c2da_fresh333 : int = c2da_fp + (57 & 15) * 4
    let c2da_fresh334 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh335 : uint = c2da_fresh334
    c2da_mem[c2da_fresh333] = uint8(c2da_fresh335)
    c2da_mem[c2da_fresh333 + 1] = uint8(c2da_fresh335 >> 0x8)
    c2da_mem[c2da_fresh333 + 2] = uint8(c2da_fresh335 >> 0x10)
    c2da_mem[c2da_fresh333 + 3] = uint8(c2da_fresh335 >> 0x18)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e & a | b & (e | a))) + 2400959708l + int64(c2da_fresh334)))
    e = e << 30u | e >> uint(32 - 30)
    let c2da_fresh336 : int = c2da_fp + (58 & 15) * 4
    let c2da_fresh337 : int = c2da_fp + (58 - 14 & 15) * 4
    let c2da_fresh338 : int = c2da_fp + (58 - 8 & 15) * 4
    let c2da_fresh339 : int = c2da_fp + (58 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh336]) | uint(c2da_mem[c2da_fresh336 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh336 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh336 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh337]) | uint(c2da_mem[c2da_fresh337 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh337 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh337 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh338]) | uint(c2da_mem[c2da_fresh338 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh338 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh338 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh339]) | uint(c2da_mem[c2da_fresh339 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh339 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh339 + 3]) << 0x18)
    let c2da_fresh340 : int = c2da_fp + (58 & 15) * 4
    let c2da_fresh341 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh342 : uint = c2da_fresh341
    c2da_mem[c2da_fresh340] = uint8(c2da_fresh342)
    c2da_mem[c2da_fresh340 + 1] = uint8(c2da_fresh342 >> 0x8)
    c2da_mem[c2da_fresh340 + 2] = uint8(c2da_fresh342 >> 0x10)
    c2da_mem[c2da_fresh340 + 3] = uint8(c2da_fresh342 >> 0x18)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d & e | a & (d | e))) + 2400959708l + int64(c2da_fresh341)))
    d = d << 30u | d >> uint(32 - 30)
    let c2da_fresh343 : int = c2da_fp + (59 & 15) * 4
    let c2da_fresh344 : int = c2da_fp + (59 - 14 & 15) * 4
    let c2da_fresh345 : int = c2da_fp + (59 - 8 & 15) * 4
    let c2da_fresh346 : int = c2da_fp + (59 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh343]) | uint(c2da_mem[c2da_fresh343 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh343 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh343 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh344]) | uint(c2da_mem[c2da_fresh344 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh344 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh344 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh345]) | uint(c2da_mem[c2da_fresh345 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh345 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh345 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh346]) | uint(c2da_mem[c2da_fresh346 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh346 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh346 + 3]) << 0x18)
    let c2da_fresh347 : int = c2da_fp + (59 & 15) * 4
    let c2da_fresh348 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh349 : uint = c2da_fresh348
    c2da_mem[c2da_fresh347] = uint8(c2da_fresh349)
    c2da_mem[c2da_fresh347 + 1] = uint8(c2da_fresh349 >> 0x8)
    c2da_mem[c2da_fresh347 + 2] = uint8(c2da_fresh349 >> 0x10)
    c2da_mem[c2da_fresh347 + 3] = uint8(c2da_fresh349 >> 0x18)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c & d | e & (c | d))) + 2400959708l + int64(c2da_fresh348)))
    c = c << 30u | c >> uint(32 - 30)
    let c2da_fresh350 : int = c2da_fp + (60 & 15) * 4
    let c2da_fresh351 : int = c2da_fp + (60 - 14 & 15) * 4
    let c2da_fresh352 : int = c2da_fp + (60 - 8 & 15) * 4
    let c2da_fresh353 : int = c2da_fp + (60 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh350]) | uint(c2da_mem[c2da_fresh350 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh350 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh350 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh351]) | uint(c2da_mem[c2da_fresh351 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh351 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh351 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh352]) | uint(c2da_mem[c2da_fresh352 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh352 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh352 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh353]) | uint(c2da_mem[c2da_fresh353 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh353 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh353 + 3]) << 0x18)
    let c2da_fresh354 : int = c2da_fp + (60 & 15) * 4
    let c2da_fresh355 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh356 : uint = c2da_fresh355
    c2da_mem[c2da_fresh354] = uint8(c2da_fresh356)
    c2da_mem[c2da_fresh354 + 1] = uint8(c2da_fresh356 >> 0x8)
    c2da_mem[c2da_fresh354 + 2] = uint8(c2da_fresh356 >> 0x10)
    c2da_mem[c2da_fresh354 + 3] = uint8(c2da_fresh356 >> 0x18)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b ^ c ^ d)) + 3395469782l + int64(c2da_fresh355)))
    b = b << 30u | b >> uint(32 - 30)
    let c2da_fresh357 : int = c2da_fp + (61 & 15) * 4
    let c2da_fresh358 : int = c2da_fp + (61 - 14 & 15) * 4
    let c2da_fresh359 : int = c2da_fp + (61 - 8 & 15) * 4
    let c2da_fresh360 : int = c2da_fp + (61 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh357]) | uint(c2da_mem[c2da_fresh357 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh357 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh357 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh358]) | uint(c2da_mem[c2da_fresh358 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh358 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh358 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh359]) | uint(c2da_mem[c2da_fresh359 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh359 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh359 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh360]) | uint(c2da_mem[c2da_fresh360 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh360 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh360 + 3]) << 0x18)
    let c2da_fresh361 : int = c2da_fp + (61 & 15) * 4
    let c2da_fresh362 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh363 : uint = c2da_fresh362
    c2da_mem[c2da_fresh361] = uint8(c2da_fresh363)
    c2da_mem[c2da_fresh361 + 1] = uint8(c2da_fresh363 >> 0x8)
    c2da_mem[c2da_fresh361 + 2] = uint8(c2da_fresh363 >> 0x10)
    c2da_mem[c2da_fresh361 + 3] = uint8(c2da_fresh363 >> 0x18)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a ^ b ^ c)) + 3395469782l + int64(c2da_fresh362)))
    a = a << 30u | a >> uint(32 - 30)
    let c2da_fresh364 : int = c2da_fp + (62 & 15) * 4
    let c2da_fresh365 : int = c2da_fp + (62 - 14 & 15) * 4
    let c2da_fresh366 : int = c2da_fp + (62 - 8 & 15) * 4
    let c2da_fresh367 : int = c2da_fp + (62 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh364]) | uint(c2da_mem[c2da_fresh364 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh364 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh364 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh365]) | uint(c2da_mem[c2da_fresh365 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh365 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh365 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh366]) | uint(c2da_mem[c2da_fresh366 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh366 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh366 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh367]) | uint(c2da_mem[c2da_fresh367 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh367 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh367 + 3]) << 0x18)
    let c2da_fresh368 : int = c2da_fp + (62 & 15) * 4
    let c2da_fresh369 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh370 : uint = c2da_fresh369
    c2da_mem[c2da_fresh368] = uint8(c2da_fresh370)
    c2da_mem[c2da_fresh368 + 1] = uint8(c2da_fresh370 >> 0x8)
    c2da_mem[c2da_fresh368 + 2] = uint8(c2da_fresh370 >> 0x10)
    c2da_mem[c2da_fresh368 + 3] = uint8(c2da_fresh370 >> 0x18)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e ^ a ^ b)) + 3395469782l + int64(c2da_fresh369)))
    e = e << 30u | e >> uint(32 - 30)
    let c2da_fresh371 : int = c2da_fp + (63 & 15) * 4
    let c2da_fresh372 : int = c2da_fp + (63 - 14 & 15) * 4
    let c2da_fresh373 : int = c2da_fp + (63 - 8 & 15) * 4
    let c2da_fresh374 : int = c2da_fp + (63 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh371]) | uint(c2da_mem[c2da_fresh371 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh371 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh371 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh372]) | uint(c2da_mem[c2da_fresh372 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh372 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh372 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh373]) | uint(c2da_mem[c2da_fresh373 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh373 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh373 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh374]) | uint(c2da_mem[c2da_fresh374 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh374 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh374 + 3]) << 0x18)
    let c2da_fresh375 : int = c2da_fp + (63 & 15) * 4
    let c2da_fresh376 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh377 : uint = c2da_fresh376
    c2da_mem[c2da_fresh375] = uint8(c2da_fresh377)
    c2da_mem[c2da_fresh375 + 1] = uint8(c2da_fresh377 >> 0x8)
    c2da_mem[c2da_fresh375 + 2] = uint8(c2da_fresh377 >> 0x10)
    c2da_mem[c2da_fresh375 + 3] = uint8(c2da_fresh377 >> 0x18)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d ^ e ^ a)) + 3395469782l + int64(c2da_fresh376)))
    d = d << 30u | d >> uint(32 - 30)
    let c2da_fresh378 : int = c2da_fp + (64 & 15) * 4
    let c2da_fresh379 : int = c2da_fp + (64 - 14 & 15) * 4
    let c2da_fresh380 : int = c2da_fp + (64 - 8 & 15) * 4
    let c2da_fresh381 : int = c2da_fp + (64 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh378]) | uint(c2da_mem[c2da_fresh378 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh378 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh378 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh379]) | uint(c2da_mem[c2da_fresh379 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh379 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh379 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh380]) | uint(c2da_mem[c2da_fresh380 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh380 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh380 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh381]) | uint(c2da_mem[c2da_fresh381 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh381 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh381 + 3]) << 0x18)
    let c2da_fresh382 : int = c2da_fp + (64 & 15) * 4
    let c2da_fresh383 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh384 : uint = c2da_fresh383
    c2da_mem[c2da_fresh382] = uint8(c2da_fresh384)
    c2da_mem[c2da_fresh382 + 1] = uint8(c2da_fresh384 >> 0x8)
    c2da_mem[c2da_fresh382 + 2] = uint8(c2da_fresh384 >> 0x10)
    c2da_mem[c2da_fresh382 + 3] = uint8(c2da_fresh384 >> 0x18)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c ^ d ^ e)) + 3395469782l + int64(c2da_fresh383)))
    c = c << 30u | c >> uint(32 - 30)
    let c2da_fresh385 : int = c2da_fp + (65 & 15) * 4
    let c2da_fresh386 : int = c2da_fp + (65 - 14 & 15) * 4
    let c2da_fresh387 : int = c2da_fp + (65 - 8 & 15) * 4
    let c2da_fresh388 : int = c2da_fp + (65 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh385]) | uint(c2da_mem[c2da_fresh385 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh385 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh385 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh386]) | uint(c2da_mem[c2da_fresh386 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh386 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh386 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh387]) | uint(c2da_mem[c2da_fresh387 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh387 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh387 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh388]) | uint(c2da_mem[c2da_fresh388 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh388 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh388 + 3]) << 0x18)
    let c2da_fresh389 : int = c2da_fp + (65 & 15) * 4
    let c2da_fresh390 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh391 : uint = c2da_fresh390
    c2da_mem[c2da_fresh389] = uint8(c2da_fresh391)
    c2da_mem[c2da_fresh389 + 1] = uint8(c2da_fresh391 >> 0x8)
    c2da_mem[c2da_fresh389 + 2] = uint8(c2da_fresh391 >> 0x10)
    c2da_mem[c2da_fresh389 + 3] = uint8(c2da_fresh391 >> 0x18)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b ^ c ^ d)) + 3395469782l + int64(c2da_fresh390)))
    b = b << 30u | b >> uint(32 - 30)
    let c2da_fresh392 : int = c2da_fp + (66 & 15) * 4
    let c2da_fresh393 : int = c2da_fp + (66 - 14 & 15) * 4
    let c2da_fresh394 : int = c2da_fp + (66 - 8 & 15) * 4
    let c2da_fresh395 : int = c2da_fp + (66 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh392]) | uint(c2da_mem[c2da_fresh392 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh392 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh392 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh393]) | uint(c2da_mem[c2da_fresh393 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh393 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh393 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh394]) | uint(c2da_mem[c2da_fresh394 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh394 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh394 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh395]) | uint(c2da_mem[c2da_fresh395 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh395 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh395 + 3]) << 0x18)
    let c2da_fresh396 : int = c2da_fp + (66 & 15) * 4
    let c2da_fresh397 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh398 : uint = c2da_fresh397
    c2da_mem[c2da_fresh396] = uint8(c2da_fresh398)
    c2da_mem[c2da_fresh396 + 1] = uint8(c2da_fresh398 >> 0x8)
    c2da_mem[c2da_fresh396 + 2] = uint8(c2da_fresh398 >> 0x10)
    c2da_mem[c2da_fresh396 + 3] = uint8(c2da_fresh398 >> 0x18)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a ^ b ^ c)) + 3395469782l + int64(c2da_fresh397)))
    a = a << 30u | a >> uint(32 - 30)
    let c2da_fresh399 : int = c2da_fp + (67 & 15) * 4
    let c2da_fresh400 : int = c2da_fp + (67 - 14 & 15) * 4
    let c2da_fresh401 : int = c2da_fp + (67 - 8 & 15) * 4
    let c2da_fresh402 : int = c2da_fp + (67 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh399]) | uint(c2da_mem[c2da_fresh399 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh399 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh399 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh400]) | uint(c2da_mem[c2da_fresh400 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh400 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh400 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh401]) | uint(c2da_mem[c2da_fresh401 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh401 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh401 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh402]) | uint(c2da_mem[c2da_fresh402 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh402 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh402 + 3]) << 0x18)
    let c2da_fresh403 : int = c2da_fp + (67 & 15) * 4
    let c2da_fresh404 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh405 : uint = c2da_fresh404
    c2da_mem[c2da_fresh403] = uint8(c2da_fresh405)
    c2da_mem[c2da_fresh403 + 1] = uint8(c2da_fresh405 >> 0x8)
    c2da_mem[c2da_fresh403 + 2] = uint8(c2da_fresh405 >> 0x10)
    c2da_mem[c2da_fresh403 + 3] = uint8(c2da_fresh405 >> 0x18)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e ^ a ^ b)) + 3395469782l + int64(c2da_fresh404)))
    e = e << 30u | e >> uint(32 - 30)
    let c2da_fresh406 : int = c2da_fp + (68 & 15) * 4
    let c2da_fresh407 : int = c2da_fp + (68 - 14 & 15) * 4
    let c2da_fresh408 : int = c2da_fp + (68 - 8 & 15) * 4
    let c2da_fresh409 : int = c2da_fp + (68 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh406]) | uint(c2da_mem[c2da_fresh406 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh406 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh406 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh407]) | uint(c2da_mem[c2da_fresh407 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh407 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh407 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh408]) | uint(c2da_mem[c2da_fresh408 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh408 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh408 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh409]) | uint(c2da_mem[c2da_fresh409 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh409 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh409 + 3]) << 0x18)
    let c2da_fresh410 : int = c2da_fp + (68 & 15) * 4
    let c2da_fresh411 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh412 : uint = c2da_fresh411
    c2da_mem[c2da_fresh410] = uint8(c2da_fresh412)
    c2da_mem[c2da_fresh410 + 1] = uint8(c2da_fresh412 >> 0x8)
    c2da_mem[c2da_fresh410 + 2] = uint8(c2da_fresh412 >> 0x10)
    c2da_mem[c2da_fresh410 + 3] = uint8(c2da_fresh412 >> 0x18)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d ^ e ^ a)) + 3395469782l + int64(c2da_fresh411)))
    d = d << 30u | d >> uint(32 - 30)
    let c2da_fresh413 : int = c2da_fp + (69 & 15) * 4
    let c2da_fresh414 : int = c2da_fp + (69 - 14 & 15) * 4
    let c2da_fresh415 : int = c2da_fp + (69 - 8 & 15) * 4
    let c2da_fresh416 : int = c2da_fp + (69 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh413]) | uint(c2da_mem[c2da_fresh413 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh413 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh413 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh414]) | uint(c2da_mem[c2da_fresh414 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh414 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh414 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh415]) | uint(c2da_mem[c2da_fresh415 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh415 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh415 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh416]) | uint(c2da_mem[c2da_fresh416 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh416 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh416 + 3]) << 0x18)
    let c2da_fresh417 : int = c2da_fp + (69 & 15) * 4
    let c2da_fresh418 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh419 : uint = c2da_fresh418
    c2da_mem[c2da_fresh417] = uint8(c2da_fresh419)
    c2da_mem[c2da_fresh417 + 1] = uint8(c2da_fresh419 >> 0x8)
    c2da_mem[c2da_fresh417 + 2] = uint8(c2da_fresh419 >> 0x10)
    c2da_mem[c2da_fresh417 + 3] = uint8(c2da_fresh419 >> 0x18)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c ^ d ^ e)) + 3395469782l + int64(c2da_fresh418)))
    c = c << 30u | c >> uint(32 - 30)
    let c2da_fresh420 : int = c2da_fp + (70 & 15) * 4
    let c2da_fresh421 : int = c2da_fp + (70 - 14 & 15) * 4
    let c2da_fresh422 : int = c2da_fp + (70 - 8 & 15) * 4
    let c2da_fresh423 : int = c2da_fp + (70 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh420]) | uint(c2da_mem[c2da_fresh420 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh420 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh420 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh421]) | uint(c2da_mem[c2da_fresh421 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh421 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh421 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh422]) | uint(c2da_mem[c2da_fresh422 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh422 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh422 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh423]) | uint(c2da_mem[c2da_fresh423 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh423 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh423 + 3]) << 0x18)
    let c2da_fresh424 : int = c2da_fp + (70 & 15) * 4
    let c2da_fresh425 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh426 : uint = c2da_fresh425
    c2da_mem[c2da_fresh424] = uint8(c2da_fresh426)
    c2da_mem[c2da_fresh424 + 1] = uint8(c2da_fresh426 >> 0x8)
    c2da_mem[c2da_fresh424 + 2] = uint8(c2da_fresh426 >> 0x10)
    c2da_mem[c2da_fresh424 + 3] = uint8(c2da_fresh426 >> 0x18)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b ^ c ^ d)) + 3395469782l + int64(c2da_fresh425)))
    b = b << 30u | b >> uint(32 - 30)
    let c2da_fresh427 : int = c2da_fp + (71 & 15) * 4
    let c2da_fresh428 : int = c2da_fp + (71 - 14 & 15) * 4
    let c2da_fresh429 : int = c2da_fp + (71 - 8 & 15) * 4
    let c2da_fresh430 : int = c2da_fp + (71 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh427]) | uint(c2da_mem[c2da_fresh427 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh427 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh427 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh428]) | uint(c2da_mem[c2da_fresh428 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh428 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh428 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh429]) | uint(c2da_mem[c2da_fresh429 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh429 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh429 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh430]) | uint(c2da_mem[c2da_fresh430 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh430 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh430 + 3]) << 0x18)
    let c2da_fresh431 : int = c2da_fp + (71 & 15) * 4
    let c2da_fresh432 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh433 : uint = c2da_fresh432
    c2da_mem[c2da_fresh431] = uint8(c2da_fresh433)
    c2da_mem[c2da_fresh431 + 1] = uint8(c2da_fresh433 >> 0x8)
    c2da_mem[c2da_fresh431 + 2] = uint8(c2da_fresh433 >> 0x10)
    c2da_mem[c2da_fresh431 + 3] = uint8(c2da_fresh433 >> 0x18)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a ^ b ^ c)) + 3395469782l + int64(c2da_fresh432)))
    a = a << 30u | a >> uint(32 - 30)
    let c2da_fresh434 : int = c2da_fp + (72 & 15) * 4
    let c2da_fresh435 : int = c2da_fp + (72 - 14 & 15) * 4
    let c2da_fresh436 : int = c2da_fp + (72 - 8 & 15) * 4
    let c2da_fresh437 : int = c2da_fp + (72 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh434]) | uint(c2da_mem[c2da_fresh434 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh434 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh434 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh435]) | uint(c2da_mem[c2da_fresh435 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh435 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh435 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh436]) | uint(c2da_mem[c2da_fresh436 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh436 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh436 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh437]) | uint(c2da_mem[c2da_fresh437 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh437 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh437 + 3]) << 0x18)
    let c2da_fresh438 : int = c2da_fp + (72 & 15) * 4
    let c2da_fresh439 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh440 : uint = c2da_fresh439
    c2da_mem[c2da_fresh438] = uint8(c2da_fresh440)
    c2da_mem[c2da_fresh438 + 1] = uint8(c2da_fresh440 >> 0x8)
    c2da_mem[c2da_fresh438 + 2] = uint8(c2da_fresh440 >> 0x10)
    c2da_mem[c2da_fresh438 + 3] = uint8(c2da_fresh440 >> 0x18)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e ^ a ^ b)) + 3395469782l + int64(c2da_fresh439)))
    e = e << 30u | e >> uint(32 - 30)
    let c2da_fresh441 : int = c2da_fp + (73 & 15) * 4
    let c2da_fresh442 : int = c2da_fp + (73 - 14 & 15) * 4
    let c2da_fresh443 : int = c2da_fp + (73 - 8 & 15) * 4
    let c2da_fresh444 : int = c2da_fp + (73 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh441]) | uint(c2da_mem[c2da_fresh441 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh441 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh441 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh442]) | uint(c2da_mem[c2da_fresh442 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh442 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh442 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh443]) | uint(c2da_mem[c2da_fresh443 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh443 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh443 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh444]) | uint(c2da_mem[c2da_fresh444 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh444 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh444 + 3]) << 0x18)
    let c2da_fresh445 : int = c2da_fp + (73 & 15) * 4
    let c2da_fresh446 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh447 : uint = c2da_fresh446
    c2da_mem[c2da_fresh445] = uint8(c2da_fresh447)
    c2da_mem[c2da_fresh445 + 1] = uint8(c2da_fresh447 >> 0x8)
    c2da_mem[c2da_fresh445 + 2] = uint8(c2da_fresh447 >> 0x10)
    c2da_mem[c2da_fresh445 + 3] = uint8(c2da_fresh447 >> 0x18)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d ^ e ^ a)) + 3395469782l + int64(c2da_fresh446)))
    d = d << 30u | d >> uint(32 - 30)
    let c2da_fresh448 : int = c2da_fp + (74 & 15) * 4
    let c2da_fresh449 : int = c2da_fp + (74 - 14 & 15) * 4
    let c2da_fresh450 : int = c2da_fp + (74 - 8 & 15) * 4
    let c2da_fresh451 : int = c2da_fp + (74 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh448]) | uint(c2da_mem[c2da_fresh448 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh448 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh448 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh449]) | uint(c2da_mem[c2da_fresh449 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh449 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh449 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh450]) | uint(c2da_mem[c2da_fresh450 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh450 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh450 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh451]) | uint(c2da_mem[c2da_fresh451 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh451 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh451 + 3]) << 0x18)
    let c2da_fresh452 : int = c2da_fp + (74 & 15) * 4
    let c2da_fresh453 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh454 : uint = c2da_fresh453
    c2da_mem[c2da_fresh452] = uint8(c2da_fresh454)
    c2da_mem[c2da_fresh452 + 1] = uint8(c2da_fresh454 >> 0x8)
    c2da_mem[c2da_fresh452 + 2] = uint8(c2da_fresh454 >> 0x10)
    c2da_mem[c2da_fresh452 + 3] = uint8(c2da_fresh454 >> 0x18)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c ^ d ^ e)) + 3395469782l + int64(c2da_fresh453)))
    c = c << 30u | c >> uint(32 - 30)
    let c2da_fresh455 : int = c2da_fp + (75 & 15) * 4
    let c2da_fresh456 : int = c2da_fp + (75 - 14 & 15) * 4
    let c2da_fresh457 : int = c2da_fp + (75 - 8 & 15) * 4
    let c2da_fresh458 : int = c2da_fp + (75 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh455]) | uint(c2da_mem[c2da_fresh455 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh455 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh455 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh456]) | uint(c2da_mem[c2da_fresh456 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh456 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh456 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh457]) | uint(c2da_mem[c2da_fresh457 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh457 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh457 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh458]) | uint(c2da_mem[c2da_fresh458 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh458 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh458 + 3]) << 0x18)
    let c2da_fresh459 : int = c2da_fp + (75 & 15) * 4
    let c2da_fresh460 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh461 : uint = c2da_fresh460
    c2da_mem[c2da_fresh459] = uint8(c2da_fresh461)
    c2da_mem[c2da_fresh459 + 1] = uint8(c2da_fresh461 >> 0x8)
    c2da_mem[c2da_fresh459 + 2] = uint8(c2da_fresh461 >> 0x10)
    c2da_mem[c2da_fresh459 + 3] = uint8(c2da_fresh461 >> 0x18)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b ^ c ^ d)) + 3395469782l + int64(c2da_fresh460)))
    b = b << 30u | b >> uint(32 - 30)
    let c2da_fresh462 : int = c2da_fp + (76 & 15) * 4
    let c2da_fresh463 : int = c2da_fp + (76 - 14 & 15) * 4
    let c2da_fresh464 : int = c2da_fp + (76 - 8 & 15) * 4
    let c2da_fresh465 : int = c2da_fp + (76 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh462]) | uint(c2da_mem[c2da_fresh462 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh462 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh462 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh463]) | uint(c2da_mem[c2da_fresh463 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh463 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh463 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh464]) | uint(c2da_mem[c2da_fresh464 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh464 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh464 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh465]) | uint(c2da_mem[c2da_fresh465 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh465 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh465 + 3]) << 0x18)
    let c2da_fresh466 : int = c2da_fp + (76 & 15) * 4
    let c2da_fresh467 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh468 : uint = c2da_fresh467
    c2da_mem[c2da_fresh466] = uint8(c2da_fresh468)
    c2da_mem[c2da_fresh466 + 1] = uint8(c2da_fresh468 >> 0x8)
    c2da_mem[c2da_fresh466 + 2] = uint8(c2da_fresh468 >> 0x10)
    c2da_mem[c2da_fresh466 + 3] = uint8(c2da_fresh468 >> 0x18)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a ^ b ^ c)) + 3395469782l + int64(c2da_fresh467)))
    a = a << 30u | a >> uint(32 - 30)
    let c2da_fresh469 : int = c2da_fp + (77 & 15) * 4
    let c2da_fresh470 : int = c2da_fp + (77 - 14 & 15) * 4
    let c2da_fresh471 : int = c2da_fp + (77 - 8 & 15) * 4
    let c2da_fresh472 : int = c2da_fp + (77 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh469]) | uint(c2da_mem[c2da_fresh469 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh469 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh469 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh470]) | uint(c2da_mem[c2da_fresh470 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh470 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh470 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh471]) | uint(c2da_mem[c2da_fresh471 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh471 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh471 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh472]) | uint(c2da_mem[c2da_fresh472 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh472 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh472 + 3]) << 0x18)
    let c2da_fresh473 : int = c2da_fp + (77 & 15) * 4
    let c2da_fresh474 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh475 : uint = c2da_fresh474
    c2da_mem[c2da_fresh473] = uint8(c2da_fresh475)
    c2da_mem[c2da_fresh473 + 1] = uint8(c2da_fresh475 >> 0x8)
    c2da_mem[c2da_fresh473 + 2] = uint8(c2da_fresh475 >> 0x10)
    c2da_mem[c2da_fresh473 + 3] = uint8(c2da_fresh475 >> 0x18)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e ^ a ^ b)) + 3395469782l + int64(c2da_fresh474)))
    e = e << 30u | e >> uint(32 - 30)
    let c2da_fresh476 : int = c2da_fp + (78 & 15) * 4
    let c2da_fresh477 : int = c2da_fp + (78 - 14 & 15) * 4
    let c2da_fresh478 : int = c2da_fp + (78 - 8 & 15) * 4
    let c2da_fresh479 : int = c2da_fp + (78 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh476]) | uint(c2da_mem[c2da_fresh476 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh476 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh476 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh477]) | uint(c2da_mem[c2da_fresh477 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh477 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh477 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh478]) | uint(c2da_mem[c2da_fresh478 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh478 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh478 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh479]) | uint(c2da_mem[c2da_fresh479 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh479 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh479 + 3]) << 0x18)
    let c2da_fresh480 : int = c2da_fp + (78 & 15) * 4
    let c2da_fresh481 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh482 : uint = c2da_fresh481
    c2da_mem[c2da_fresh480] = uint8(c2da_fresh482)
    c2da_mem[c2da_fresh480 + 1] = uint8(c2da_fresh482 >> 0x8)
    c2da_mem[c2da_fresh480 + 2] = uint8(c2da_fresh482 >> 0x10)
    c2da_mem[c2da_fresh480 + 3] = uint8(c2da_fresh482 >> 0x18)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d ^ e ^ a)) + 3395469782l + int64(c2da_fresh481)))
    d = d << 30u | d >> uint(32 - 30)
    let c2da_fresh483 : int = c2da_fp + (79 & 15) * 4
    let c2da_fresh484 : int = c2da_fp + (79 - 14 & 15) * 4
    let c2da_fresh485 : int = c2da_fp + (79 - 8 & 15) * 4
    let c2da_fresh486 : int = c2da_fp + (79 - 3 & 15) * 4
    tm = (uint(c2da_mem[c2da_fresh483]) | uint(c2da_mem[c2da_fresh483 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh483 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh483 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh484]) | uint(c2da_mem[c2da_fresh484 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh484 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh484 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh485]) | uint(c2da_mem[c2da_fresh485 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh485 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh485 + 3]) << 0x18) ^ (uint(c2da_mem[c2da_fresh486]) | uint(c2da_mem[c2da_fresh486 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh486 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh486 + 3]) << 0x18)
    let c2da_fresh487 : int = c2da_fp + (79 & 15) * 4
    let c2da_fresh488 : uint = tm << 1u | tm >> uint(32 - 1)
    let c2da_fresh489 : uint = c2da_fresh488
    c2da_mem[c2da_fresh487] = uint8(c2da_fresh489)
    c2da_mem[c2da_fresh487 + 1] = uint8(c2da_fresh489 >> 0x8)
    c2da_mem[c2da_fresh487 + 2] = uint8(c2da_fresh489 >> 0x10)
    c2da_mem[c2da_fresh487 + 3] = uint8(c2da_fresh489 >> 0x18)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c ^ d ^ e)) + 3395469782l + int64(c2da_fresh488)))
    c = c << 30u | c >> uint(32 - 30)
    let c2da_fresh490 : uint = (uint(c2da_mem[hd_1]) | uint(c2da_mem[hd_1 + 1]) << 0x8 | uint(c2da_mem[hd_1 + 2]) << 0x10 | uint(c2da_mem[hd_1 + 3]) << 0x18) + a
    let c2da_fresh491 : uint = c2da_fresh490
    c2da_mem[hd_1] = uint8(c2da_fresh491)
    c2da_mem[hd_1 + 1] = uint8(c2da_fresh491 >> 0x8)
    c2da_mem[hd_1 + 2] = uint8(c2da_fresh491 >> 0x10)
    c2da_mem[hd_1 + 3] = uint8(c2da_fresh491 >> 0x18)
    let c2da_fresh492 : uint = (uint(c2da_mem[hd_1 + 4]) | uint(c2da_mem[hd_1 + 5]) << 0x8 | uint(c2da_mem[hd_1 + 6]) << 0x10 | uint(c2da_mem[hd_1 + 7]) << 0x18) + b
    let c2da_fresh493 : uint = c2da_fresh492
    c2da_mem[hd_1 + 4] = uint8(c2da_fresh493)
    c2da_mem[hd_1 + 5] = uint8(c2da_fresh493 >> 0x8)
    c2da_mem[hd_1 + 6] = uint8(c2da_fresh493 >> 0x10)
    c2da_mem[hd_1 + 7] = uint8(c2da_fresh493 >> 0x18)
    let c2da_fresh494 : uint = (uint(c2da_mem[hd_1 + 8]) | uint(c2da_mem[hd_1 + 9]) << 0x8 | uint(c2da_mem[hd_1 + 10]) << 0x10 | uint(c2da_mem[hd_1 + 11]) << 0x18) + c
    let c2da_fresh495 : uint = c2da_fresh494
    c2da_mem[hd_1 + 8] = uint8(c2da_fresh495)
    c2da_mem[hd_1 + 9] = uint8(c2da_fresh495 >> 0x8)
    c2da_mem[hd_1 + 10] = uint8(c2da_fresh495 >> 0x10)
    c2da_mem[hd_1 + 11] = uint8(c2da_fresh495 >> 0x18)
    let c2da_fresh496 : uint = (uint(c2da_mem[hd_1 + 12]) | uint(c2da_mem[hd_1 + 13]) << 0x8 | uint(c2da_mem[hd_1 + 14]) << 0x10 | uint(c2da_mem[hd_1 + 15]) << 0x18) + d
    let c2da_fresh497 : uint = c2da_fresh496
    c2da_mem[hd_1 + 12] = uint8(c2da_fresh497)
    c2da_mem[hd_1 + 13] = uint8(c2da_fresh497 >> 0x8)
    c2da_mem[hd_1 + 14] = uint8(c2da_fresh497 >> 0x10)
    c2da_mem[hd_1 + 15] = uint8(c2da_fresh497 >> 0x18)
    let c2da_fresh498 : uint = (uint(c2da_mem[hd_1 + 16]) | uint(c2da_mem[hd_1 + 17]) << 0x8 | uint(c2da_mem[hd_1 + 18]) << 0x10 | uint(c2da_mem[hd_1 + 19]) << 0x18) + e
    let c2da_fresh499 : uint = c2da_fresh498
    c2da_mem[hd_1 + 16] = uint8(c2da_fresh499)
    c2da_mem[hd_1 + 17] = uint8(c2da_fresh499 >> 0x8)
    c2da_mem[hd_1 + 18] = uint8(c2da_fresh499 >> 0x10)
    c2da_mem[hd_1 + 19] = uint8(c2da_fresh499 >> 0x18)
    return
}
[sideeffects]
def private SHA1_UpdateInt32_c2da_frame(var context : int; var val : uint; c2da_fp : int) {
    let c2da_fresh564 : uint8 = uint8(val >> 24u & 0xffu)
    c2da_mem[c2da_fp + 0] = c2da_fresh564
    let c2da_fresh565 : uint8 = uint8(val >> 16u & 0xffu)
    c2da_mem[c2da_fp + 1] = c2da_fresh565
    let c2da_fresh566 : uint8 = uint8(val >> 8u & 0xffu)
    c2da_mem[c2da_fp + 2] = c2da_fresh566
    let c2da_fresh567 : uint8 = uint8(val & 0xffu)
    c2da_mem[c2da_fp + 3] = c2da_fresh567
    SHA1_Update(context, c2da_fp, 4ul)
    return
}
