[export, sideeffects]
def Z_Init() {
    let c2da_saved_sp : int = c2da_lin_sp
    Z_Init_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
var mainzone : int = default<int>

[export, sideeffects]
def Z_Malloc(var size : int; var tag : int; var user : int) : int {
    var extra : int
    var start : int
    var rover : int
    var newblock : int
    var base : int
    var result_0 : int
    size = int(uint64(size) + 8ul - 1ul & ~(8ul - 1ul))
    size = int(uint64(size) + 40ul)
    base = int(uint(c2da_mem[mainzone + 48]) | uint(c2da_mem[mainzone + 49]) << 0x8 | uint(c2da_mem[mainzone + 50]) << 0x10 | uint(c2da_mem[mainzone + 51]) << 0x18)
    let c2da_fresh15 : int = int(uint(c2da_mem[base + 32]) | uint(c2da_mem[base + 33]) << 0x8 | uint(c2da_mem[base + 34]) << 0x10 | uint(c2da_mem[base + 35]) << 0x18) + 16
    if (int(uint(c2da_mem[c2da_fresh15]) | uint(c2da_mem[c2da_fresh15 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh15 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh15 + 3]) << 0x18) == 4) {
        base = int(uint(c2da_mem[base + 32]) | uint(c2da_mem[base + 33]) << 0x8 | uint(c2da_mem[base + 34]) << 0x10 | uint(c2da_mem[base + 35]) << 0x18)
    }
    rover = base
    start = int(uint(c2da_mem[base + 32]) | uint(c2da_mem[base + 33]) << 0x8 | uint(c2da_mem[base + 34]) << 0x10 | uint(c2da_mem[base + 35]) << 0x18)
    while (true) {
        if (rover == start) {
            I_Error(377424, [C2daVaArg(tag = 1, i64 = int64(size), f64 = 0.0lf, raw = 0x0)])
        }
        if (int(uint(c2da_mem[rover + 16]) | uint(c2da_mem[rover + 17]) << 0x8 | uint(c2da_mem[rover + 18]) << 0x10 | uint(c2da_mem[rover + 19]) << 0x18) != 4) {
            if (int(uint(c2da_mem[rover + 16]) | uint(c2da_mem[rover + 17]) << 0x8 | uint(c2da_mem[rover + 18]) << 0x10 | uint(c2da_mem[rover + 19]) << 0x18) < 7) {
                rover = int(uint(c2da_mem[rover + 24]) | uint(c2da_mem[rover + 25]) << 0x8 | uint(c2da_mem[rover + 26]) << 0x10 | uint(c2da_mem[rover + 27]) << 0x18)
                base = rover
            } else {
                base = int(uint(c2da_mem[base + 32]) | uint(c2da_mem[base + 33]) << 0x8 | uint(c2da_mem[base + 34]) << 0x10 | uint(c2da_mem[base + 35]) << 0x18)
                Z_Free(rover + 40)
                base = int(uint(c2da_mem[base + 24]) | uint(c2da_mem[base + 25]) << 0x8 | uint(c2da_mem[base + 26]) << 0x10 | uint(c2da_mem[base + 27]) << 0x18)
                rover = int(uint(c2da_mem[base + 24]) | uint(c2da_mem[base + 25]) << 0x8 | uint(c2da_mem[base + 26]) << 0x10 | uint(c2da_mem[base + 27]) << 0x18)
            }
        } else {
            rover = int(uint(c2da_mem[rover + 24]) | uint(c2da_mem[rover + 25]) << 0x8 | uint(c2da_mem[rover + 26]) << 0x10 | uint(c2da_mem[rover + 27]) << 0x18)
        }
        if (!(int(uint(c2da_mem[base + 16]) | uint(c2da_mem[base + 17]) << 0x8 | uint(c2da_mem[base + 18]) << 0x10 | uint(c2da_mem[base + 19]) << 0x18) != 4 || int(uint(c2da_mem[base]) | uint(c2da_mem[base + 1]) << 0x8 | uint(c2da_mem[base + 2]) << 0x10 | uint(c2da_mem[base + 3]) << 0x18) < size)) {
            break
        }
    }
    extra = int(uint(c2da_mem[base]) | uint(c2da_mem[base + 1]) << 0x8 | uint(c2da_mem[base + 2]) << 0x10 | uint(c2da_mem[base + 3]) << 0x18) - size
    if (extra > 64) {
        newblock = base + size
        let c2da_fresh16 : uint = uint(extra)
        c2da_mem[newblock] = uint8(c2da_fresh16)
        c2da_mem[newblock + 1] = uint8(c2da_fresh16 >> 0x8)
        c2da_mem[newblock + 2] = uint8(c2da_fresh16 >> 0x10)
        c2da_mem[newblock + 3] = uint8(c2da_fresh16 >> 0x18)
        let c2da_fresh17 : int = 4
        let c2da_fresh18 : uint = uint(c2da_fresh17)
        c2da_mem[newblock + 16] = uint8(c2da_fresh18)
        c2da_mem[newblock + 17] = uint8(c2da_fresh18 >> 0x8)
        c2da_mem[newblock + 18] = uint8(c2da_fresh18 >> 0x10)
        c2da_mem[newblock + 19] = uint8(c2da_fresh18 >> 0x18)
        let c2da_fresh19 : uint = 0u
        c2da_mem[newblock + 8] = uint8(c2da_fresh19)
        c2da_mem[newblock + 9] = uint8(c2da_fresh19 >> 0x8)
        c2da_mem[newblock + 10] = uint8(c2da_fresh19 >> 0x10)
        c2da_mem[newblock + 11] = uint8(c2da_fresh19 >> 0x18)
        c2da_mem[newblock + 12] = 0u8
        c2da_mem[newblock + 13] = 0u8
        c2da_mem[newblock + 14] = 0u8
        c2da_mem[newblock + 15] = 0u8
        let c2da_fresh20 : uint = uint(base)
        c2da_mem[newblock + 32] = uint8(c2da_fresh20)
        c2da_mem[newblock + 33] = uint8(c2da_fresh20 >> 0x8)
        c2da_mem[newblock + 34] = uint8(c2da_fresh20 >> 0x10)
        c2da_mem[newblock + 35] = uint8(c2da_fresh20 >> 0x18)
        c2da_mem[newblock + 36] = 0u8
        c2da_mem[newblock + 37] = 0u8
        c2da_mem[newblock + 38] = 0u8
        c2da_mem[newblock + 39] = 0u8
        let c2da_fresh21 : int = int(uint(c2da_mem[base + 24]) | uint(c2da_mem[base + 25]) << 0x8 | uint(c2da_mem[base + 26]) << 0x10 | uint(c2da_mem[base + 27]) << 0x18)
        let c2da_fresh22 : uint = uint(c2da_fresh21)
        c2da_mem[newblock + 24] = uint8(c2da_fresh22)
        c2da_mem[newblock + 25] = uint8(c2da_fresh22 >> 0x8)
        c2da_mem[newblock + 26] = uint8(c2da_fresh22 >> 0x10)
        c2da_mem[newblock + 27] = uint8(c2da_fresh22 >> 0x18)
        c2da_mem[newblock + 28] = 0u8
        c2da_mem[newblock + 29] = 0u8
        c2da_mem[newblock + 30] = 0u8
        c2da_mem[newblock + 31] = 0u8
        let c2da_fresh23 : int = int(uint(c2da_mem[newblock + 24]) | uint(c2da_mem[newblock + 25]) << 0x8 | uint(c2da_mem[newblock + 26]) << 0x10 | uint(c2da_mem[newblock + 27]) << 0x18) + 32
        let c2da_fresh24 : uint = uint(newblock)
        c2da_mem[c2da_fresh23] = uint8(c2da_fresh24)
        c2da_mem[c2da_fresh23 + 1] = uint8(c2da_fresh24 >> 0x8)
        c2da_mem[c2da_fresh23 + 2] = uint8(c2da_fresh24 >> 0x10)
        c2da_mem[c2da_fresh23 + 3] = uint8(c2da_fresh24 >> 0x18)
        c2da_mem[c2da_fresh23 + 4] = 0u8
        c2da_mem[c2da_fresh23 + 5] = 0u8
        c2da_mem[c2da_fresh23 + 6] = 0u8
        c2da_mem[c2da_fresh23 + 7] = 0u8
        let c2da_fresh25 : uint = uint(newblock)
        c2da_mem[base + 24] = uint8(c2da_fresh25)
        c2da_mem[base + 25] = uint8(c2da_fresh25 >> 0x8)
        c2da_mem[base + 26] = uint8(c2da_fresh25 >> 0x10)
        c2da_mem[base + 27] = uint8(c2da_fresh25 >> 0x18)
        c2da_mem[base + 28] = 0u8
        c2da_mem[base + 29] = 0u8
        c2da_mem[base + 30] = 0u8
        c2da_mem[base + 31] = 0u8
        let c2da_fresh26 : uint = uint(size)
        c2da_mem[base] = uint8(c2da_fresh26)
        c2da_mem[base + 1] = uint8(c2da_fresh26 >> 0x8)
        c2da_mem[base + 2] = uint8(c2da_fresh26 >> 0x10)
        c2da_mem[base + 3] = uint8(c2da_fresh26 >> 0x18)
    }
    if (user == 0 && tag >= 7) {
        I_Error(377467, [])
    }
    let c2da_fresh27 : uint = uint(user)
    c2da_mem[base + 8] = uint8(c2da_fresh27)
    c2da_mem[base + 9] = uint8(c2da_fresh27 >> 0x8)
    c2da_mem[base + 10] = uint8(c2da_fresh27 >> 0x10)
    c2da_mem[base + 11] = uint8(c2da_fresh27 >> 0x18)
    c2da_mem[base + 12] = 0u8
    c2da_mem[base + 13] = 0u8
    c2da_mem[base + 14] = 0u8
    c2da_mem[base + 15] = 0u8
    let c2da_fresh28 : uint = uint(tag)
    c2da_mem[base + 16] = uint8(c2da_fresh28)
    c2da_mem[base + 17] = uint8(c2da_fresh28 >> 0x8)
    c2da_mem[base + 18] = uint8(c2da_fresh28 >> 0x10)
    c2da_mem[base + 19] = uint8(c2da_fresh28 >> 0x18)
    result_0 = base + 40
    if (int(uint(c2da_mem[base + 8]) | uint(c2da_mem[base + 9]) << 0x8 | uint(c2da_mem[base + 10]) << 0x10 | uint(c2da_mem[base + 11]) << 0x18) != 0) {
        let c2da_fresh29 : int = int(uint(c2da_mem[base + 8]) | uint(c2da_mem[base + 9]) << 0x8 | uint(c2da_mem[base + 10]) << 0x10 | uint(c2da_mem[base + 11]) << 0x18)
        let c2da_fresh30 : uint = uint(result_0)
        c2da_mem[c2da_fresh29] = uint8(c2da_fresh30)
        c2da_mem[c2da_fresh29 + 1] = uint8(c2da_fresh30 >> 0x8)
        c2da_mem[c2da_fresh29 + 2] = uint8(c2da_fresh30 >> 0x10)
        c2da_mem[c2da_fresh29 + 3] = uint8(c2da_fresh30 >> 0x18)
        c2da_mem[c2da_fresh29 + 4] = 0u8
        c2da_mem[c2da_fresh29 + 5] = 0u8
        c2da_mem[c2da_fresh29 + 6] = 0u8
        c2da_mem[c2da_fresh29 + 7] = 0u8
    }
    let c2da_fresh31 : int = int(uint(c2da_mem[base + 24]) | uint(c2da_mem[base + 25]) << 0x8 | uint(c2da_mem[base + 26]) << 0x10 | uint(c2da_mem[base + 27]) << 0x18)
    let c2da_fresh32 : uint = uint(c2da_fresh31)
    c2da_mem[mainzone + 48] = uint8(c2da_fresh32)
    c2da_mem[mainzone + 49] = uint8(c2da_fresh32 >> 0x8)
    c2da_mem[mainzone + 50] = uint8(c2da_fresh32 >> 0x10)
    c2da_mem[mainzone + 51] = uint8(c2da_fresh32 >> 0x18)
    c2da_mem[mainzone + 52] = 0u8
    c2da_mem[mainzone + 53] = 0u8
    c2da_mem[mainzone + 54] = 0u8
    c2da_mem[mainzone + 55] = 0u8
    let c2da_fresh33 : int = 1919505
    let c2da_fresh34 : uint = uint(c2da_fresh33)
    c2da_mem[base + 20] = uint8(c2da_fresh34)
    c2da_mem[base + 21] = uint8(c2da_fresh34 >> 0x8)
    c2da_mem[base + 22] = uint8(c2da_fresh34 >> 0x10)
    c2da_mem[base + 23] = uint8(c2da_fresh34 >> 0x18)
    return result_0
}
[export, sideeffects]
def Z_Free(var ptr : int) {
    var block_1 : int
    var other : int
    block_1 = ptr - 40
    if (int(uint(c2da_mem[block_1 + 20]) | uint(c2da_mem[block_1 + 21]) << 0x8 | uint(c2da_mem[block_1 + 22]) << 0x10 | uint(c2da_mem[block_1 + 23]) << 0x18) != 1919505) {
        I_Error(377518, [])
    }
    if (int(uint(c2da_mem[block_1 + 16]) | uint(c2da_mem[block_1 + 17]) << 0x8 | uint(c2da_mem[block_1 + 18]) << 0x10 | uint(c2da_mem[block_1 + 19]) << 0x18) != 4 && int(uint(c2da_mem[block_1 + 8]) | uint(c2da_mem[block_1 + 9]) << 0x8 | uint(c2da_mem[block_1 + 10]) << 0x10 | uint(c2da_mem[block_1 + 11]) << 0x18) != 0) {
        let c2da_fresh35 : int = int(uint(c2da_mem[block_1 + 8]) | uint(c2da_mem[block_1 + 9]) << 0x8 | uint(c2da_mem[block_1 + 10]) << 0x10 | uint(c2da_mem[block_1 + 11]) << 0x18)
        let c2da_fresh36 : uint = 0u
        c2da_mem[c2da_fresh35] = uint8(c2da_fresh36)
        c2da_mem[c2da_fresh35 + 1] = uint8(c2da_fresh36 >> 0x8)
        c2da_mem[c2da_fresh35 + 2] = uint8(c2da_fresh36 >> 0x10)
        c2da_mem[c2da_fresh35 + 3] = uint8(c2da_fresh36 >> 0x18)
        c2da_mem[c2da_fresh35 + 4] = 0u8
        c2da_mem[c2da_fresh35 + 5] = 0u8
        c2da_mem[c2da_fresh35 + 6] = 0u8
        c2da_mem[c2da_fresh35 + 7] = 0u8
    }
    let c2da_fresh37 : int = 4
    let c2da_fresh38 : uint = uint(c2da_fresh37)
    c2da_mem[block_1 + 16] = uint8(c2da_fresh38)
    c2da_mem[block_1 + 17] = uint8(c2da_fresh38 >> 0x8)
    c2da_mem[block_1 + 18] = uint8(c2da_fresh38 >> 0x10)
    c2da_mem[block_1 + 19] = uint8(c2da_fresh38 >> 0x18)
    let c2da_fresh39 : uint = 0u
    c2da_mem[block_1 + 8] = uint8(c2da_fresh39)
    c2da_mem[block_1 + 9] = uint8(c2da_fresh39 >> 0x8)
    c2da_mem[block_1 + 10] = uint8(c2da_fresh39 >> 0x10)
    c2da_mem[block_1 + 11] = uint8(c2da_fresh39 >> 0x18)
    c2da_mem[block_1 + 12] = 0u8
    c2da_mem[block_1 + 13] = 0u8
    c2da_mem[block_1 + 14] = 0u8
    c2da_mem[block_1 + 15] = 0u8
    let c2da_fresh40 : int = 0
    let c2da_fresh41 : uint = uint(c2da_fresh40)
    c2da_mem[block_1 + 20] = uint8(c2da_fresh41)
    c2da_mem[block_1 + 21] = uint8(c2da_fresh41 >> 0x8)
    c2da_mem[block_1 + 22] = uint8(c2da_fresh41 >> 0x10)
    c2da_mem[block_1 + 23] = uint8(c2da_fresh41 >> 0x18)
    other = int(uint(c2da_mem[block_1 + 32]) | uint(c2da_mem[block_1 + 33]) << 0x8 | uint(c2da_mem[block_1 + 34]) << 0x10 | uint(c2da_mem[block_1 + 35]) << 0x18)
    if (int(uint(c2da_mem[other + 16]) | uint(c2da_mem[other + 17]) << 0x8 | uint(c2da_mem[other + 18]) << 0x10 | uint(c2da_mem[other + 19]) << 0x18) == 4) {
        let c2da_fresh42 : int = int(uint(c2da_mem[other]) | uint(c2da_mem[other + 1]) << 0x8 | uint(c2da_mem[other + 2]) << 0x10 | uint(c2da_mem[other + 3]) << 0x18) + int(uint(c2da_mem[block_1]) | uint(c2da_mem[block_1 + 1]) << 0x8 | uint(c2da_mem[block_1 + 2]) << 0x10 | uint(c2da_mem[block_1 + 3]) << 0x18)
        let c2da_fresh43 : uint = uint(c2da_fresh42)
        c2da_mem[other] = uint8(c2da_fresh43)
        c2da_mem[other + 1] = uint8(c2da_fresh43 >> 0x8)
        c2da_mem[other + 2] = uint8(c2da_fresh43 >> 0x10)
        c2da_mem[other + 3] = uint8(c2da_fresh43 >> 0x18)
        let c2da_fresh44 : int = int(uint(c2da_mem[block_1 + 24]) | uint(c2da_mem[block_1 + 25]) << 0x8 | uint(c2da_mem[block_1 + 26]) << 0x10 | uint(c2da_mem[block_1 + 27]) << 0x18)
        let c2da_fresh45 : uint = uint(c2da_fresh44)
        c2da_mem[other + 24] = uint8(c2da_fresh45)
        c2da_mem[other + 25] = uint8(c2da_fresh45 >> 0x8)
        c2da_mem[other + 26] = uint8(c2da_fresh45 >> 0x10)
        c2da_mem[other + 27] = uint8(c2da_fresh45 >> 0x18)
        c2da_mem[other + 28] = 0u8
        c2da_mem[other + 29] = 0u8
        c2da_mem[other + 30] = 0u8
        c2da_mem[other + 31] = 0u8
        let c2da_fresh46 : int = int(uint(c2da_mem[other + 24]) | uint(c2da_mem[other + 25]) << 0x8 | uint(c2da_mem[other + 26]) << 0x10 | uint(c2da_mem[other + 27]) << 0x18) + 32
        let c2da_fresh47 : uint = uint(other)
        c2da_mem[c2da_fresh46] = uint8(c2da_fresh47)
        c2da_mem[c2da_fresh46 + 1] = uint8(c2da_fresh47 >> 0x8)
        c2da_mem[c2da_fresh46 + 2] = uint8(c2da_fresh47 >> 0x10)
        c2da_mem[c2da_fresh46 + 3] = uint8(c2da_fresh47 >> 0x18)
        c2da_mem[c2da_fresh46 + 4] = 0u8
        c2da_mem[c2da_fresh46 + 5] = 0u8
        c2da_mem[c2da_fresh46 + 6] = 0u8
        c2da_mem[c2da_fresh46 + 7] = 0u8
        if (block_1 == int(uint(c2da_mem[mainzone + 48]) | uint(c2da_mem[mainzone + 49]) << 0x8 | uint(c2da_mem[mainzone + 50]) << 0x10 | uint(c2da_mem[mainzone + 51]) << 0x18)) {
            let c2da_fresh48 : uint = uint(other)
            c2da_mem[mainzone + 48] = uint8(c2da_fresh48)
            c2da_mem[mainzone + 49] = uint8(c2da_fresh48 >> 0x8)
            c2da_mem[mainzone + 50] = uint8(c2da_fresh48 >> 0x10)
            c2da_mem[mainzone + 51] = uint8(c2da_fresh48 >> 0x18)
            c2da_mem[mainzone + 52] = 0u8
            c2da_mem[mainzone + 53] = 0u8
            c2da_mem[mainzone + 54] = 0u8
            c2da_mem[mainzone + 55] = 0u8
        }
        block_1 = other
    }
    other = int(uint(c2da_mem[block_1 + 24]) | uint(c2da_mem[block_1 + 25]) << 0x8 | uint(c2da_mem[block_1 + 26]) << 0x10 | uint(c2da_mem[block_1 + 27]) << 0x18)
    if (int(uint(c2da_mem[other + 16]) | uint(c2da_mem[other + 17]) << 0x8 | uint(c2da_mem[other + 18]) << 0x10 | uint(c2da_mem[other + 19]) << 0x18) == 4) {
        let c2da_fresh49 : int = int(uint(c2da_mem[block_1]) | uint(c2da_mem[block_1 + 1]) << 0x8 | uint(c2da_mem[block_1 + 2]) << 0x10 | uint(c2da_mem[block_1 + 3]) << 0x18) + int(uint(c2da_mem[other]) | uint(c2da_mem[other + 1]) << 0x8 | uint(c2da_mem[other + 2]) << 0x10 | uint(c2da_mem[other + 3]) << 0x18)
        let c2da_fresh50 : uint = uint(c2da_fresh49)
        c2da_mem[block_1] = uint8(c2da_fresh50)
        c2da_mem[block_1 + 1] = uint8(c2da_fresh50 >> 0x8)
        c2da_mem[block_1 + 2] = uint8(c2da_fresh50 >> 0x10)
        c2da_mem[block_1 + 3] = uint8(c2da_fresh50 >> 0x18)
        let c2da_fresh51 : int = int(uint(c2da_mem[other + 24]) | uint(c2da_mem[other + 25]) << 0x8 | uint(c2da_mem[other + 26]) << 0x10 | uint(c2da_mem[other + 27]) << 0x18)
        let c2da_fresh52 : uint = uint(c2da_fresh51)
        c2da_mem[block_1 + 24] = uint8(c2da_fresh52)
        c2da_mem[block_1 + 25] = uint8(c2da_fresh52 >> 0x8)
        c2da_mem[block_1 + 26] = uint8(c2da_fresh52 >> 0x10)
        c2da_mem[block_1 + 27] = uint8(c2da_fresh52 >> 0x18)
        c2da_mem[block_1 + 28] = 0u8
        c2da_mem[block_1 + 29] = 0u8
        c2da_mem[block_1 + 30] = 0u8
        c2da_mem[block_1 + 31] = 0u8
        let c2da_fresh53 : int = int(uint(c2da_mem[block_1 + 24]) | uint(c2da_mem[block_1 + 25]) << 0x8 | uint(c2da_mem[block_1 + 26]) << 0x10 | uint(c2da_mem[block_1 + 27]) << 0x18) + 32
        let c2da_fresh54 : uint = uint(block_1)
        c2da_mem[c2da_fresh53] = uint8(c2da_fresh54)
        c2da_mem[c2da_fresh53 + 1] = uint8(c2da_fresh54 >> 0x8)
        c2da_mem[c2da_fresh53 + 2] = uint8(c2da_fresh54 >> 0x10)
        c2da_mem[c2da_fresh53 + 3] = uint8(c2da_fresh54 >> 0x18)
        c2da_mem[c2da_fresh53 + 4] = 0u8
        c2da_mem[c2da_fresh53 + 5] = 0u8
        c2da_mem[c2da_fresh53 + 6] = 0u8
        c2da_mem[c2da_fresh53 + 7] = 0u8
        if (other == int(uint(c2da_mem[mainzone + 48]) | uint(c2da_mem[mainzone + 49]) << 0x8 | uint(c2da_mem[mainzone + 50]) << 0x10 | uint(c2da_mem[mainzone + 51]) << 0x18)) {
            let c2da_fresh55 : uint = uint(block_1)
            c2da_mem[mainzone + 48] = uint8(c2da_fresh55)
            c2da_mem[mainzone + 49] = uint8(c2da_fresh55 >> 0x8)
            c2da_mem[mainzone + 50] = uint8(c2da_fresh55 >> 0x10)
            c2da_mem[mainzone + 51] = uint8(c2da_fresh55 >> 0x18)
            c2da_mem[mainzone + 52] = 0u8
            c2da_mem[mainzone + 53] = 0u8
            c2da_mem[mainzone + 54] = 0u8
            c2da_mem[mainzone + 55] = 0u8
        }
    }
    return
}
[export, sideeffects]
def Z_FreeTags(var lowtag : int; var hightag : int) {
    var block_2 : int
    var next : int
    block_2 = int(uint(c2da_mem[mainzone + 32]) | uint(c2da_mem[mainzone + 33]) << 0x8 | uint(c2da_mem[mainzone + 34]) << 0x10 | uint(c2da_mem[mainzone + 35]) << 0x18)
    while (block_2 != mainzone + 8) {
        next = int(uint(c2da_mem[block_2 + 24]) | uint(c2da_mem[block_2 + 25]) << 0x8 | uint(c2da_mem[block_2 + 26]) << 0x10 | uint(c2da_mem[block_2 + 27]) << 0x18)
        if (int(uint(c2da_mem[block_2 + 16]) | uint(c2da_mem[block_2 + 17]) << 0x8 | uint(c2da_mem[block_2 + 18]) << 0x10 | uint(c2da_mem[block_2 + 19]) << 0x18) == 4) {
            block_2 = next
            continue
        }
        if (int(uint(c2da_mem[block_2 + 16]) | uint(c2da_mem[block_2 + 17]) << 0x8 | uint(c2da_mem[block_2 + 18]) << 0x10 | uint(c2da_mem[block_2 + 19]) << 0x18) >= lowtag && int(uint(c2da_mem[block_2 + 16]) | uint(c2da_mem[block_2 + 17]) << 0x8 | uint(c2da_mem[block_2 + 18]) << 0x10 | uint(c2da_mem[block_2 + 19]) << 0x18) <= hightag) {
            Z_Free(block_2 + 40)
        }
        block_2 = next
    }
    return
}
[export, sideeffects]
def Z_DumpHeap(var lowtag_0 : int; var hightag_0 : int) {
    var block_3 : int
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 377557, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[mainzone]) | uint(c2da_mem[mainzone + 1]) << 0x8 | uint(c2da_mem[mainzone + 2]) << 0x10 | uint(c2da_mem[mainzone + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(mainzone))])
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 377586, [C2daVaArg(tag = 1, i64 = int64(lowtag_0), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 1, i64 = int64(hightag_0), f64 = 0.0lf, raw = 0x0)])
    block_3 = int(uint(c2da_mem[mainzone + 32]) | uint(c2da_mem[mainzone + 33]) << 0x8 | uint(c2da_mem[mainzone + 34]) << 0x10 | uint(c2da_mem[mainzone + 35]) << 0x18)
    while (true) {
        if (int(uint(c2da_mem[block_3 + 16]) | uint(c2da_mem[block_3 + 17]) << 0x8 | uint(c2da_mem[block_3 + 18]) << 0x10 | uint(c2da_mem[block_3 + 19]) << 0x18) >= lowtag_0 && int(uint(c2da_mem[block_3 + 16]) | uint(c2da_mem[block_3 + 17]) << 0x8 | uint(c2da_mem[block_3 + 18]) << 0x10 | uint(c2da_mem[block_3 + 19]) << 0x18) <= hightag_0) {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 377607, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(block_3)), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[block_3]) | uint(c2da_mem[block_3 + 1]) << 0x8 | uint(c2da_mem[block_3 + 2]) << 0x10 | uint(c2da_mem[block_3 + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[block_3 + 8]) | uint(c2da_mem[block_3 + 9]) << 0x8 | uint(c2da_mem[block_3 + 10]) << 0x10 | uint(c2da_mem[block_3 + 11]) << 0x18))), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[block_3 + 16]) | uint(c2da_mem[block_3 + 17]) << 0x8 | uint(c2da_mem[block_3 + 18]) << 0x10 | uint(c2da_mem[block_3 + 19]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
        }
        if (int(uint(c2da_mem[block_3 + 24]) | uint(c2da_mem[block_3 + 25]) << 0x8 | uint(c2da_mem[block_3 + 26]) << 0x10 | uint(c2da_mem[block_3 + 27]) << 0x18) == mainzone + 8) {
            break
        }
        if (block_3 + int(uint(c2da_mem[block_3]) | uint(c2da_mem[block_3 + 1]) << 0x8 | uint(c2da_mem[block_3 + 2]) << 0x10 | uint(c2da_mem[block_3 + 3]) << 0x18) != int(uint(c2da_mem[block_3 + 24]) | uint(c2da_mem[block_3 + 25]) << 0x8 | uint(c2da_mem[block_3 + 26]) << 0x10 | uint(c2da_mem[block_3 + 27]) << 0x18)) {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 377651, [])
        }
        let c2da_fresh56 : int = int(uint(c2da_mem[block_3 + 24]) | uint(c2da_mem[block_3 + 25]) << 0x8 | uint(c2da_mem[block_3 + 26]) << 0x10 | uint(c2da_mem[block_3 + 27]) << 0x18) + 32
        if (int(uint(c2da_mem[c2da_fresh56]) | uint(c2da_mem[c2da_fresh56 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh56 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh56 + 3]) << 0x18) != block_3) {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 377700, [])
        }
        var c2da_fresh58 : int = 0
        if (int(uint(c2da_mem[block_3 + 16]) | uint(c2da_mem[block_3 + 17]) << 0x8 | uint(c2da_mem[block_3 + 18]) << 0x10 | uint(c2da_mem[block_3 + 19]) << 0x18) == 4) {
            let c2da_fresh57 : int = int(uint(c2da_mem[block_3 + 24]) | uint(c2da_mem[block_3 + 25]) << 0x8 | uint(c2da_mem[block_3 + 26]) << 0x10 | uint(c2da_mem[block_3 + 27]) << 0x18) + 16
            if (int(uint(c2da_mem[c2da_fresh57]) | uint(c2da_mem[c2da_fresh57 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh57 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh57 + 3]) << 0x18) == 4) {
                c2da_fresh58 = 1
            }
        }
        if (c2da_fresh58 != 0) {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 377749, [])
        }
        block_3 = int(uint(c2da_mem[block_3 + 24]) | uint(c2da_mem[block_3 + 25]) << 0x8 | uint(c2da_mem[block_3 + 26]) << 0x10 | uint(c2da_mem[block_3 + 27]) << 0x18)
    }
    return
}
[export, sideeffects]
def Z_FileDumpHeap(var f : int) {
    var block_4 : int
    c2da_lin_printf(uint64(f), 377557, [C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[mainzone]) | uint(c2da_mem[mainzone + 1]) << 0x8 | uint(c2da_mem[mainzone + 2]) << 0x10 | uint(c2da_mem[mainzone + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(mainzone))])
    block_4 = int(uint(c2da_mem[mainzone + 32]) | uint(c2da_mem[mainzone + 33]) << 0x8 | uint(c2da_mem[mainzone + 34]) << 0x10 | uint(c2da_mem[mainzone + 35]) << 0x18)
    while (true) {
        c2da_lin_printf(uint64(f), 377607, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(block_4)), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[block_4]) | uint(c2da_mem[block_4 + 1]) << 0x8 | uint(c2da_mem[block_4 + 2]) << 0x10 | uint(c2da_mem[block_4 + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(int(uint(c2da_mem[block_4 + 8]) | uint(c2da_mem[block_4 + 9]) << 0x8 | uint(c2da_mem[block_4 + 10]) << 0x10 | uint(c2da_mem[block_4 + 11]) << 0x18))), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[block_4 + 16]) | uint(c2da_mem[block_4 + 17]) << 0x8 | uint(c2da_mem[block_4 + 18]) << 0x10 | uint(c2da_mem[block_4 + 19]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
        if (int(uint(c2da_mem[block_4 + 24]) | uint(c2da_mem[block_4 + 25]) << 0x8 | uint(c2da_mem[block_4 + 26]) << 0x10 | uint(c2da_mem[block_4 + 27]) << 0x18) == mainzone + 8) {
            break
        }
        if (block_4 + int(uint(c2da_mem[block_4]) | uint(c2da_mem[block_4 + 1]) << 0x8 | uint(c2da_mem[block_4 + 2]) << 0x10 | uint(c2da_mem[block_4 + 3]) << 0x18) != int(uint(c2da_mem[block_4 + 24]) | uint(c2da_mem[block_4 + 25]) << 0x8 | uint(c2da_mem[block_4 + 26]) << 0x10 | uint(c2da_mem[block_4 + 27]) << 0x18)) {
            c2da_lin_printf(uint64(f), 377651, [])
        }
        let c2da_fresh59 : int = int(uint(c2da_mem[block_4 + 24]) | uint(c2da_mem[block_4 + 25]) << 0x8 | uint(c2da_mem[block_4 + 26]) << 0x10 | uint(c2da_mem[block_4 + 27]) << 0x18) + 32
        if (int(uint(c2da_mem[c2da_fresh59]) | uint(c2da_mem[c2da_fresh59 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh59 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh59 + 3]) << 0x18) != block_4) {
            c2da_lin_printf(uint64(f), 377700, [])
        }
        var c2da_fresh61 : int = 0
        if (int(uint(c2da_mem[block_4 + 16]) | uint(c2da_mem[block_4 + 17]) << 0x8 | uint(c2da_mem[block_4 + 18]) << 0x10 | uint(c2da_mem[block_4 + 19]) << 0x18) == 4) {
            let c2da_fresh60 : int = int(uint(c2da_mem[block_4 + 24]) | uint(c2da_mem[block_4 + 25]) << 0x8 | uint(c2da_mem[block_4 + 26]) << 0x10 | uint(c2da_mem[block_4 + 27]) << 0x18) + 16
            if (int(uint(c2da_mem[c2da_fresh60]) | uint(c2da_mem[c2da_fresh60 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh60 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh60 + 3]) << 0x18) == 4) {
                c2da_fresh61 = 1
            }
        }
        if (c2da_fresh61 != 0) {
            c2da_lin_printf(uint64(f), 377749, [])
        }
        block_4 = int(uint(c2da_mem[block_4 + 24]) | uint(c2da_mem[block_4 + 25]) << 0x8 | uint(c2da_mem[block_4 + 26]) << 0x10 | uint(c2da_mem[block_4 + 27]) << 0x18)
    }
    return
}
[export, sideeffects]
def Z_CheckHeap() {
    var block_5 : int = int(uint(c2da_mem[mainzone + 32]) | uint(c2da_mem[mainzone + 33]) << 0x8 | uint(c2da_mem[mainzone + 34]) << 0x10 | uint(c2da_mem[mainzone + 35]) << 0x18)
    while (true) {
        if (int(uint(c2da_mem[block_5 + 24]) | uint(c2da_mem[block_5 + 25]) << 0x8 | uint(c2da_mem[block_5 + 26]) << 0x10 | uint(c2da_mem[block_5 + 27]) << 0x18) == mainzone + 8) {
            break
        }
        if (block_5 + int(uint(c2da_mem[block_5]) | uint(c2da_mem[block_5 + 1]) << 0x8 | uint(c2da_mem[block_5 + 2]) << 0x10 | uint(c2da_mem[block_5 + 3]) << 0x18) != int(uint(c2da_mem[block_5 + 24]) | uint(c2da_mem[block_5 + 25]) << 0x8 | uint(c2da_mem[block_5 + 26]) << 0x10 | uint(c2da_mem[block_5 + 27]) << 0x18)) {
            I_Error(377785, [])
        }
        let c2da_fresh62 : int = int(uint(c2da_mem[block_5 + 24]) | uint(c2da_mem[block_5 + 25]) << 0x8 | uint(c2da_mem[block_5 + 26]) << 0x10 | uint(c2da_mem[block_5 + 27]) << 0x18) + 32
        if (int(uint(c2da_mem[c2da_fresh62]) | uint(c2da_mem[c2da_fresh62 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh62 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh62 + 3]) << 0x18) != block_5) {
            I_Error(377840, [])
        }
        var c2da_fresh64 : int = 0
        if (int(uint(c2da_mem[block_5 + 16]) | uint(c2da_mem[block_5 + 17]) << 0x8 | uint(c2da_mem[block_5 + 18]) << 0x10 | uint(c2da_mem[block_5 + 19]) << 0x18) == 4) {
            let c2da_fresh63 : int = int(uint(c2da_mem[block_5 + 24]) | uint(c2da_mem[block_5 + 25]) << 0x8 | uint(c2da_mem[block_5 + 26]) << 0x10 | uint(c2da_mem[block_5 + 27]) << 0x18) + 16
            if (int(uint(c2da_mem[c2da_fresh63]) | uint(c2da_mem[c2da_fresh63 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh63 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh63 + 3]) << 0x18) == 4) {
                c2da_fresh64 = 1
            }
        }
        if (c2da_fresh64 != 0) {
            I_Error(377895, [])
        }
        block_5 = int(uint(c2da_mem[block_5 + 24]) | uint(c2da_mem[block_5 + 25]) << 0x8 | uint(c2da_mem[block_5 + 26]) << 0x10 | uint(c2da_mem[block_5 + 27]) << 0x18)
    }
    return
}
[export, sideeffects]
def Z_ChangeTag2(var ptr_0 : int; var tag_0 : int; var file : int; var line : int) {
    var block_6 : int = ptr_0 - 40
    if (int(uint(c2da_mem[block_6 + 20]) | uint(c2da_mem[block_6 + 21]) << 0x8 | uint(c2da_mem[block_6 + 22]) << 0x10 | uint(c2da_mem[block_6 + 23]) << 0x18) != 1919505) {
        I_Error(377937, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(file)), C2daVaArg(tag = 1, i64 = int64(line), f64 = 0.0lf, raw = 0x0)])
    }
    if (tag_0 >= 7 && int(uint(c2da_mem[block_6 + 8]) | uint(c2da_mem[block_6 + 9]) << 0x8 | uint(c2da_mem[block_6 + 10]) << 0x10 | uint(c2da_mem[block_6 + 11]) << 0x18) == 0) {
        I_Error(377981, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(file)), C2daVaArg(tag = 1, i64 = int64(line), f64 = 0.0lf, raw = 0x0)])
    }
    let c2da_fresh65 : uint = uint(tag_0)
    c2da_mem[block_6 + 16] = uint8(c2da_fresh65)
    c2da_mem[block_6 + 17] = uint8(c2da_fresh65 >> 0x8)
    c2da_mem[block_6 + 18] = uint8(c2da_fresh65 >> 0x10)
    c2da_mem[block_6 + 19] = uint8(c2da_fresh65 >> 0x18)
    return
}
[export, sideeffects]
def Z_ChangeUser(var ptr_1 : int; var user_0 : int) {
    var block_7 : int = ptr_1 - 40
    if (int(uint(c2da_mem[block_7 + 20]) | uint(c2da_mem[block_7 + 21]) << 0x8 | uint(c2da_mem[block_7 + 22]) << 0x10 | uint(c2da_mem[block_7 + 23]) << 0x18) != 1919505) {
        I_Error(378042, [])
    }
    let c2da_fresh66 : uint = uint(user_0)
    c2da_mem[block_7 + 8] = uint8(c2da_fresh66)
    c2da_mem[block_7 + 9] = uint8(c2da_fresh66 >> 0x8)
    c2da_mem[block_7 + 10] = uint8(c2da_fresh66 >> 0x10)
    c2da_mem[block_7 + 11] = uint8(c2da_fresh66 >> 0x18)
    c2da_mem[block_7 + 12] = 0u8
    c2da_mem[block_7 + 13] = 0u8
    c2da_mem[block_7 + 14] = 0u8
    c2da_mem[block_7 + 15] = 0u8
    let c2da_fresh67 : uint = uint(ptr_1)
    c2da_mem[user_0] = uint8(c2da_fresh67)
    c2da_mem[user_0 + 1] = uint8(c2da_fresh67 >> 0x8)
    c2da_mem[user_0 + 2] = uint8(c2da_fresh67 >> 0x10)
    c2da_mem[user_0 + 3] = uint8(c2da_fresh67 >> 0x18)
    c2da_mem[user_0 + 4] = 0u8
    c2da_mem[user_0 + 5] = 0u8
    c2da_mem[user_0 + 6] = 0u8
    c2da_mem[user_0 + 7] = 0u8
    return
}
[export, sideeffects]
def Z_FreeMemory() : int {
    var block_8 : int
    var free : int = 0
    block_8 = int(uint(c2da_mem[mainzone + 32]) | uint(c2da_mem[mainzone + 33]) << 0x8 | uint(c2da_mem[mainzone + 34]) << 0x10 | uint(c2da_mem[mainzone + 35]) << 0x18)
    while (block_8 != mainzone + 8) {
        if (int(uint(c2da_mem[block_8 + 16]) | uint(c2da_mem[block_8 + 17]) << 0x8 | uint(c2da_mem[block_8 + 18]) << 0x10 | uint(c2da_mem[block_8 + 19]) << 0x18) == 4 || int(uint(c2da_mem[block_8 + 16]) | uint(c2da_mem[block_8 + 17]) << 0x8 | uint(c2da_mem[block_8 + 18]) << 0x10 | uint(c2da_mem[block_8 + 19]) << 0x18) >= 7) {
            free += int(uint(c2da_mem[block_8]) | uint(c2da_mem[block_8 + 1]) << 0x8 | uint(c2da_mem[block_8 + 2]) << 0x10 | uint(c2da_mem[block_8 + 3]) << 0x18)
        }
        block_8 = int(uint(c2da_mem[block_8 + 24]) | uint(c2da_mem[block_8 + 25]) << 0x8 | uint(c2da_mem[block_8 + 26]) << 0x10 | uint(c2da_mem[block_8 + 27]) << 0x18)
    }
    return free
}
[export, sideeffects]
def Z_ZoneSize() : uint {
    return uint(int(uint(c2da_mem[mainzone]) | uint(c2da_mem[mainzone + 1]) << 0x8 | uint(c2da_mem[mainzone + 2]) << 0x10 | uint(c2da_mem[mainzone + 3]) << 0x18))
}
[export, sideeffects]
def Z_ClearZone(var zone : int) {
    var block_9 : int = zone + 56
    let c2da_fresh68 : uint = uint(block_9)
    c2da_mem[zone + 40] = uint8(c2da_fresh68)
    c2da_mem[zone + 41] = uint8(c2da_fresh68 >> 0x8)
    c2da_mem[zone + 42] = uint8(c2da_fresh68 >> 0x10)
    c2da_mem[zone + 43] = uint8(c2da_fresh68 >> 0x18)
    c2da_mem[zone + 44] = 0u8
    c2da_mem[zone + 45] = 0u8
    c2da_mem[zone + 46] = 0u8
    c2da_mem[zone + 47] = 0u8
    let c2da_fresh69 : uint = uint(block_9)
    c2da_mem[zone + 32] = uint8(c2da_fresh69)
    c2da_mem[zone + 33] = uint8(c2da_fresh69 >> 0x8)
    c2da_mem[zone + 34] = uint8(c2da_fresh69 >> 0x10)
    c2da_mem[zone + 35] = uint8(c2da_fresh69 >> 0x18)
    c2da_mem[zone + 36] = 0u8
    c2da_mem[zone + 37] = 0u8
    c2da_mem[zone + 38] = 0u8
    c2da_mem[zone + 39] = 0u8
    let c2da_fresh70 : uint = uint(zone)
    c2da_mem[zone + 16] = uint8(c2da_fresh70)
    c2da_mem[zone + 17] = uint8(c2da_fresh70 >> 0x8)
    c2da_mem[zone + 18] = uint8(c2da_fresh70 >> 0x10)
    c2da_mem[zone + 19] = uint8(c2da_fresh70 >> 0x18)
    c2da_mem[zone + 20] = 0u8
    c2da_mem[zone + 21] = 0u8
    c2da_mem[zone + 22] = 0u8
    c2da_mem[zone + 23] = 0u8
    let c2da_fresh71 : int = 1
    let c2da_fresh72 : uint = uint(c2da_fresh71)
    c2da_mem[zone + 24] = uint8(c2da_fresh72)
    c2da_mem[zone + 25] = uint8(c2da_fresh72 >> 0x8)
    c2da_mem[zone + 26] = uint8(c2da_fresh72 >> 0x10)
    c2da_mem[zone + 27] = uint8(c2da_fresh72 >> 0x18)
    let c2da_fresh73 : uint = uint(block_9)
    c2da_mem[zone + 48] = uint8(c2da_fresh73)
    c2da_mem[zone + 49] = uint8(c2da_fresh73 >> 0x8)
    c2da_mem[zone + 50] = uint8(c2da_fresh73 >> 0x10)
    c2da_mem[zone + 51] = uint8(c2da_fresh73 >> 0x18)
    c2da_mem[zone + 52] = 0u8
    c2da_mem[zone + 53] = 0u8
    c2da_mem[zone + 54] = 0u8
    c2da_mem[zone + 55] = 0u8
    let c2da_fresh74 : int = zone + 8
    let c2da_fresh75 : uint = uint(c2da_fresh74)
    c2da_mem[block_9 + 24] = uint8(c2da_fresh75)
    c2da_mem[block_9 + 25] = uint8(c2da_fresh75 >> 0x8)
    c2da_mem[block_9 + 26] = uint8(c2da_fresh75 >> 0x10)
    c2da_mem[block_9 + 27] = uint8(c2da_fresh75 >> 0x18)
    c2da_mem[block_9 + 28] = 0u8
    c2da_mem[block_9 + 29] = 0u8
    c2da_mem[block_9 + 30] = 0u8
    c2da_mem[block_9 + 31] = 0u8
    let c2da_fresh76 : uint = uint(c2da_fresh74)
    c2da_mem[block_9 + 32] = uint8(c2da_fresh76)
    c2da_mem[block_9 + 33] = uint8(c2da_fresh76 >> 0x8)
    c2da_mem[block_9 + 34] = uint8(c2da_fresh76 >> 0x10)
    c2da_mem[block_9 + 35] = uint8(c2da_fresh76 >> 0x18)
    c2da_mem[block_9 + 36] = 0u8
    c2da_mem[block_9 + 37] = 0u8
    c2da_mem[block_9 + 38] = 0u8
    c2da_mem[block_9 + 39] = 0u8
    let c2da_fresh77 : int = 4
    let c2da_fresh78 : uint = uint(c2da_fresh77)
    c2da_mem[block_9 + 16] = uint8(c2da_fresh78)
    c2da_mem[block_9 + 17] = uint8(c2da_fresh78 >> 0x8)
    c2da_mem[block_9 + 18] = uint8(c2da_fresh78 >> 0x10)
    c2da_mem[block_9 + 19] = uint8(c2da_fresh78 >> 0x18)
    let c2da_fresh79 : int = int(uint64(int(uint(c2da_mem[zone]) | uint(c2da_mem[zone + 1]) << 0x8 | uint(c2da_mem[zone + 2]) << 0x10 | uint(c2da_mem[zone + 3]) << 0x18)) - 56ul)
    let c2da_fresh80 : uint = uint(c2da_fresh79)
    c2da_mem[block_9] = uint8(c2da_fresh80)
    c2da_mem[block_9 + 1] = uint8(c2da_fresh80 >> 0x8)
    c2da_mem[block_9 + 2] = uint8(c2da_fresh80 >> 0x10)
    c2da_mem[block_9 + 3] = uint8(c2da_fresh80 >> 0x18)
    return
}
[sideeffects]
def private Z_Init_c2da_frame(c2da_fp : int) {
    var block_0 : int
    mainzone = I_ZoneBase(c2da_fp)
    let c2da_fresh0 : int = int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18)
    let c2da_fresh1 : uint = uint(c2da_fresh0)
    c2da_mem[mainzone] = uint8(c2da_fresh1)
    c2da_mem[mainzone + 1] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[mainzone + 2] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[mainzone + 3] = uint8(c2da_fresh1 >> 0x18)
    block_0 = mainzone + 56
    let c2da_fresh2 : uint = uint(block_0)
    c2da_mem[mainzone + 40] = uint8(c2da_fresh2)
    c2da_mem[mainzone + 41] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[mainzone + 42] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[mainzone + 43] = uint8(c2da_fresh2 >> 0x18)
    c2da_mem[mainzone + 44] = 0u8
    c2da_mem[mainzone + 45] = 0u8
    c2da_mem[mainzone + 46] = 0u8
    c2da_mem[mainzone + 47] = 0u8
    let c2da_fresh3 : uint = uint(block_0)
    c2da_mem[mainzone + 32] = uint8(c2da_fresh3)
    c2da_mem[mainzone + 33] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[mainzone + 34] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[mainzone + 35] = uint8(c2da_fresh3 >> 0x18)
    c2da_mem[mainzone + 36] = 0u8
    c2da_mem[mainzone + 37] = 0u8
    c2da_mem[mainzone + 38] = 0u8
    c2da_mem[mainzone + 39] = 0u8
    let c2da_fresh4 : uint = uint(mainzone)
    c2da_mem[mainzone + 16] = uint8(c2da_fresh4)
    c2da_mem[mainzone + 17] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[mainzone + 18] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[mainzone + 19] = uint8(c2da_fresh4 >> 0x18)
    c2da_mem[mainzone + 20] = 0u8
    c2da_mem[mainzone + 21] = 0u8
    c2da_mem[mainzone + 22] = 0u8
    c2da_mem[mainzone + 23] = 0u8
    let c2da_fresh5 : int = 1
    let c2da_fresh6 : uint = uint(c2da_fresh5)
    c2da_mem[mainzone + 24] = uint8(c2da_fresh6)
    c2da_mem[mainzone + 25] = uint8(c2da_fresh6 >> 0x8)
    c2da_mem[mainzone + 26] = uint8(c2da_fresh6 >> 0x10)
    c2da_mem[mainzone + 27] = uint8(c2da_fresh6 >> 0x18)
    let c2da_fresh7 : uint = uint(block_0)
    c2da_mem[mainzone + 48] = uint8(c2da_fresh7)
    c2da_mem[mainzone + 49] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[mainzone + 50] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[mainzone + 51] = uint8(c2da_fresh7 >> 0x18)
    c2da_mem[mainzone + 52] = 0u8
    c2da_mem[mainzone + 53] = 0u8
    c2da_mem[mainzone + 54] = 0u8
    c2da_mem[mainzone + 55] = 0u8
    let c2da_fresh8 : int = mainzone + 8
    let c2da_fresh9 : uint = uint(c2da_fresh8)
    c2da_mem[block_0 + 24] = uint8(c2da_fresh9)
    c2da_mem[block_0 + 25] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[block_0 + 26] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[block_0 + 27] = uint8(c2da_fresh9 >> 0x18)
    c2da_mem[block_0 + 28] = 0u8
    c2da_mem[block_0 + 29] = 0u8
    c2da_mem[block_0 + 30] = 0u8
    c2da_mem[block_0 + 31] = 0u8
    let c2da_fresh10 : uint = uint(c2da_fresh8)
    c2da_mem[block_0 + 32] = uint8(c2da_fresh10)
    c2da_mem[block_0 + 33] = uint8(c2da_fresh10 >> 0x8)
    c2da_mem[block_0 + 34] = uint8(c2da_fresh10 >> 0x10)
    c2da_mem[block_0 + 35] = uint8(c2da_fresh10 >> 0x18)
    c2da_mem[block_0 + 36] = 0u8
    c2da_mem[block_0 + 37] = 0u8
    c2da_mem[block_0 + 38] = 0u8
    c2da_mem[block_0 + 39] = 0u8
    let c2da_fresh11 : int = 4
    let c2da_fresh12 : uint = uint(c2da_fresh11)
    c2da_mem[block_0 + 16] = uint8(c2da_fresh12)
    c2da_mem[block_0 + 17] = uint8(c2da_fresh12 >> 0x8)
    c2da_mem[block_0 + 18] = uint8(c2da_fresh12 >> 0x10)
    c2da_mem[block_0 + 19] = uint8(c2da_fresh12 >> 0x18)
    let c2da_fresh13 : int = int(uint64(int(uint(c2da_mem[mainzone]) | uint(c2da_mem[mainzone + 1]) << 0x8 | uint(c2da_mem[mainzone + 2]) << 0x10 | uint(c2da_mem[mainzone + 3]) << 0x18)) - 56ul)
    let c2da_fresh14 : uint = uint(c2da_fresh13)
    c2da_mem[block_0] = uint8(c2da_fresh14)
    c2da_mem[block_0 + 1] = uint8(c2da_fresh14 >> 0x8)
    c2da_mem[block_0 + 2] = uint8(c2da_fresh14 >> 0x10)
    c2da_mem[block_0 + 3] = uint8(c2da_fresh14 >> 0x18)
    return
}

// This unit's static data, at heap offset 377424.
let private c2da_lin_static_z_zone_seg = fixed_array<int>(377424, 671)
let private c2da_lin_static_z_zone = fixed_array<uint64>(0x636f6c6c614d5f5aul, 0x64656c696166203aul, 0x6f6c6c61206e6f20ul, 0x6f206e6f69746163ul, 0x7479622069252066ul, 0x6c614d5f5a007365ul, 0x206e61203a636f6cul, 0x73692072656e776ful, 0x6572697571657220ul, 0x757020726f662064ul, 0x6220656c62616772ul, 0x5f5a00736b636f6cul, 0x7266203a65657246ul, 0x6f70206120646565ul, 0x6977207265746e69ul, 0x4f5a2074756f6874ul, 0x6e6f7a004449454eul, 0x203a657a69732065ul, 0x61636f6c20206925ul, 0x7025203a6e6f6974ul, 0x617220676174000aul, 0x206925203a65676eul, 0x62000a6925206f74ul, 0x2070253a6b636f6cul, 0x3a657a6973202020ul, 0x7520202020693725ul, 0x202070253a726573ul, 0x33253a6761742020ul, 0x524f525245000a69ul, 0x206b636f6c62203aul, 0x656f6420657a6973ul, 0x6f7420746f6e2073ul, 0x2065687420686375ul, 0x6f6c62207478656eul, 0x4f525245000a6b63ul, 0x207478656e203a52ul, 0x6f64206b636f6c62ul, 0x61682074276e7365ul, 0x65706f7270206576ul, 0x6c206b6361622072ul, 0x525245000a6b6e69ul, 0x206f7774203a524ful, 0x74756365736e6f63ul, 0x6565726620657669ul, 0xa736b636f6c6220ul, 0x6b636568435f5a00ul, 0x6c62203a70616548ul, 0x657a6973206b636ful, 0x6f6e2073656f6420ul, 0x206863756f742074ul, 0x7478656e20656874ul, 0xa6b636f6c6220ul, 0x486b636568435f5aul, 0x78656e203a706165ul, 0x206b636f6c622074ul, 0x2074276e73656f64ul, 0x6f72702065766168ul, 0x6b63616220726570ul, 0x5a000a6b6e696c20ul, 0x65486b636568435ful, 0x206f7774203a7061ul, 0x74756365736e6f63ul, 0x6565726620657669ul, 0xa736b636f6c6220ul, 0x203a69253a732500ul, 0x65676e6168435f5aul, 0x6f6c62203a676154ul, 0x6f68746977206b63ul, 0x4e4f5a2061207475ul, 0x3a73250021444945ul, 0x68435f5a203a6925ul, 0x3a67615465676e61ul, 0x656e776f206e6120ul, 0x7165722073692072ul, 0x6f66206465726975ul, 0x6261677275702072ul, 0x6b636f6c6220656cul, 0x6e6168435f5a0073ul, 0x203a726573556567ul, 0x6f74206465697254ul, 0x2065676e61686320ul, 0x726f662072657375ul, 0x64696c61766e6920ul, 0x216b636f6c6220ul)

[init]
def private c2da_lin_init_static_z_zone() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_z_zone_seg[s * 2]
        for (k in range(c2da_lin_static_z_zone_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_z_zone[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
