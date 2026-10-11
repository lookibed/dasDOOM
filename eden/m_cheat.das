options gen2
options stack = 4194304
module m_cheat public

require c2da_runtime
require daslib/math_bits
[export, sideeffects]
def cht_CheckCheat(var cht : int; var key : int8) : int {
    if (int(uint(c2da_mem[cht + 40]) | uint(c2da_mem[cht + 41]) << 0x8 | uint(c2da_mem[cht + 42]) << 0x10 | uint(c2da_mem[cht + 43]) << 0x18) > 0 && c2da_lin_strlen(cht) < (uint64(uint(c2da_mem[cht + 32]) | uint(c2da_mem[cht + 33]) << 0x8 | uint(c2da_mem[cht + 34]) << 0x10 | uint(c2da_mem[cht + 35]) << 0x18) | uint64(uint(c2da_mem[cht + 36]) | uint(c2da_mem[cht + 37]) << 0x8 | uint(c2da_mem[cht + 38]) << 0x10 | uint(c2da_mem[cht + 39]) << 0x18) << 0x20)) {
        return 0
    }
    if ((uint64(uint(c2da_mem[cht + 48]) | uint(c2da_mem[cht + 49]) << 0x8 | uint(c2da_mem[cht + 50]) << 0x10 | uint(c2da_mem[cht + 51]) << 0x18) | uint64(uint(c2da_mem[cht + 52]) | uint(c2da_mem[cht + 53]) << 0x8 | uint(c2da_mem[cht + 54]) << 0x10 | uint(c2da_mem[cht + 55]) << 0x18) << 0x20) < c2da_lin_strlen(cht)) {
        let c2da_fresh0 : int = cht + int(uint64(uint(c2da_mem[cht + 48]) | uint(c2da_mem[cht + 49]) << 0x8 | uint(c2da_mem[cht + 50]) << 0x10 | uint(c2da_mem[cht + 51]) << 0x18) | uint64(uint(c2da_mem[cht + 52]) | uint(c2da_mem[cht + 53]) << 0x8 | uint(c2da_mem[cht + 54]) << 0x10 | uint(c2da_mem[cht + 55]) << 0x18) << 0x20)
        if (int(key) == int(int8(c2da_mem[c2da_fresh0]))) {
            let c2da_fresh1 : uint64 = uint64(uint(c2da_mem[cht + 48]) | uint(c2da_mem[cht + 49]) << 0x8 | uint(c2da_mem[cht + 50]) << 0x10 | uint(c2da_mem[cht + 51]) << 0x18) | uint64(uint(c2da_mem[cht + 52]) | uint(c2da_mem[cht + 53]) << 0x8 | uint(c2da_mem[cht + 54]) << 0x10 | uint(c2da_mem[cht + 55]) << 0x18) << 0x20
            let c2da_fresh2 : uint64 = c2da_fresh1 + 1ul
            let c2da_fresh3 : uint64 = c2da_fresh2
            c2da_mem[cht + 48] = uint8(c2da_fresh3)
            c2da_mem[cht + 49] = uint8(c2da_fresh3 >> 0x8)
            c2da_mem[cht + 50] = uint8(c2da_fresh3 >> 0x10)
            c2da_mem[cht + 51] = uint8(c2da_fresh3 >> 0x18)
            c2da_mem[cht + 52] = uint8(c2da_fresh3 >> 0x20)
            c2da_mem[cht + 53] = uint8(c2da_fresh3 >> 0x28)
            c2da_mem[cht + 54] = uint8(c2da_fresh3 >> 0x30)
            c2da_mem[cht + 55] = uint8(c2da_fresh3 >> 0x38)
        } else {
            let c2da_fresh4 : uint64 = 0ul
            let c2da_fresh5 : uint64 = c2da_fresh4
            c2da_mem[cht + 48] = uint8(c2da_fresh5)
            c2da_mem[cht + 49] = uint8(c2da_fresh5 >> 0x8)
            c2da_mem[cht + 50] = uint8(c2da_fresh5 >> 0x10)
            c2da_mem[cht + 51] = uint8(c2da_fresh5 >> 0x18)
            c2da_mem[cht + 52] = uint8(c2da_fresh5 >> 0x20)
            c2da_mem[cht + 53] = uint8(c2da_fresh5 >> 0x28)
            c2da_mem[cht + 54] = uint8(c2da_fresh5 >> 0x30)
            c2da_mem[cht + 55] = uint8(c2da_fresh5 >> 0x38)
        }
        let c2da_fresh6 : int = 0
        let c2da_fresh7 : uint = uint(c2da_fresh6)
        c2da_mem[cht + 56] = uint8(c2da_fresh7)
        c2da_mem[cht + 57] = uint8(c2da_fresh7 >> 0x8)
        c2da_mem[cht + 58] = uint8(c2da_fresh7 >> 0x10)
        c2da_mem[cht + 59] = uint8(c2da_fresh7 >> 0x18)
    } elif (int(uint(c2da_mem[cht + 56]) | uint(c2da_mem[cht + 57]) << 0x8 | uint(c2da_mem[cht + 58]) << 0x10 | uint(c2da_mem[cht + 59]) << 0x18) < int(uint(c2da_mem[cht + 40]) | uint(c2da_mem[cht + 41]) << 0x8 | uint(c2da_mem[cht + 42]) << 0x10 | uint(c2da_mem[cht + 43]) << 0x18)) {
        let c2da_fresh8 : int = cht + 60 + int(uint(c2da_mem[cht + 56]) | uint(c2da_mem[cht + 57]) << 0x8 | uint(c2da_mem[cht + 58]) << 0x10 | uint(c2da_mem[cht + 59]) << 0x18)
        c2da_mem[c2da_fresh8] = uint8(key)
        let c2da_fresh9 : int = int(uint(c2da_mem[cht + 56]) | uint(c2da_mem[cht + 57]) << 0x8 | uint(c2da_mem[cht + 58]) << 0x10 | uint(c2da_mem[cht + 59]) << 0x18)
        let c2da_fresh10 : int = c2da_fresh9 + 1
        let c2da_fresh11 : uint = uint(c2da_fresh10)
        c2da_mem[cht + 56] = uint8(c2da_fresh11)
        c2da_mem[cht + 57] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[cht + 58] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[cht + 59] = uint8(c2da_fresh11 >> 0x18)
    }
    if ((uint64(uint(c2da_mem[cht + 48]) | uint(c2da_mem[cht + 49]) << 0x8 | uint(c2da_mem[cht + 50]) << 0x10 | uint(c2da_mem[cht + 51]) << 0x18) | uint64(uint(c2da_mem[cht + 52]) | uint(c2da_mem[cht + 53]) << 0x8 | uint(c2da_mem[cht + 54]) << 0x10 | uint(c2da_mem[cht + 55]) << 0x18) << 0x20) >= c2da_lin_strlen(cht) && int(uint(c2da_mem[cht + 56]) | uint(c2da_mem[cht + 57]) << 0x8 | uint(c2da_mem[cht + 58]) << 0x10 | uint(c2da_mem[cht + 59]) << 0x18) >= int(uint(c2da_mem[cht + 40]) | uint(c2da_mem[cht + 41]) << 0x8 | uint(c2da_mem[cht + 42]) << 0x10 | uint(c2da_mem[cht + 43]) << 0x18)) {
        let c2da_fresh12 : int = 0
        let c2da_fresh13 : uint = uint(c2da_fresh12)
        c2da_mem[cht + 56] = uint8(c2da_fresh13)
        c2da_mem[cht + 57] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[cht + 58] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[cht + 59] = uint8(c2da_fresh13 >> 0x18)
        let c2da_fresh14 : uint64 = uint64(c2da_fresh12)
        let c2da_fresh15 : uint64 = c2da_fresh14
        c2da_mem[cht + 48] = uint8(c2da_fresh15)
        c2da_mem[cht + 49] = uint8(c2da_fresh15 >> 0x8)
        c2da_mem[cht + 50] = uint8(c2da_fresh15 >> 0x10)
        c2da_mem[cht + 51] = uint8(c2da_fresh15 >> 0x18)
        c2da_mem[cht + 52] = uint8(c2da_fresh15 >> 0x20)
        c2da_mem[cht + 53] = uint8(c2da_fresh15 >> 0x28)
        c2da_mem[cht + 54] = uint8(c2da_fresh15 >> 0x30)
        c2da_mem[cht + 55] = uint8(c2da_fresh15 >> 0x38)
        return 1
    }
    return 0
}
[export, sideeffects]
def cht_GetParam(var cht_0 : int; var buffer : int) {
    c2da_lin_memcpy(buffer, cht_0 + 60, uint64(int(uint(c2da_mem[cht_0 + 40]) | uint(c2da_mem[cht_0 + 41]) << 0x8 | uint(c2da_mem[cht_0 + 42]) << 0x10 | uint(c2da_mem[cht_0 + 43]) << 0x18)))
    return
}
