options gen2
options stack = 4194304
module m_bbox public

require dasdoom_runtime
require daslib/math_bits
[export, sideeffects]
def M_ClearBox(var box : int) {
    let c2da_fresh0 : int = -2147483647 - 1
    let c2da_fresh1 : uint = uint(c2da_fresh0)
    c2da_mem[box + 3 * 4] = uint8(c2da_fresh1)
    c2da_mem[box + 3 * 4 + 1] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[box + 3 * 4 + 2] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[box + 3 * 4 + 3] = uint8(c2da_fresh1 >> 0x18)
    let c2da_fresh2 : uint = uint(c2da_fresh0)
    c2da_mem[box + 0 * 4] = uint8(c2da_fresh2)
    c2da_mem[box + 0 * 4 + 1] = uint8(c2da_fresh2 >> 0x8)
    c2da_mem[box + 0 * 4 + 2] = uint8(c2da_fresh2 >> 0x10)
    c2da_mem[box + 0 * 4 + 3] = uint8(c2da_fresh2 >> 0x18)
    let c2da_fresh3 : int = 2147483647
    let c2da_fresh4 : uint = uint(c2da_fresh3)
    c2da_mem[box + 2 * 4] = uint8(c2da_fresh4)
    c2da_mem[box + 2 * 4 + 1] = uint8(c2da_fresh4 >> 0x8)
    c2da_mem[box + 2 * 4 + 2] = uint8(c2da_fresh4 >> 0x10)
    c2da_mem[box + 2 * 4 + 3] = uint8(c2da_fresh4 >> 0x18)
    let c2da_fresh5 : uint = uint(c2da_fresh3)
    c2da_mem[box + 1 * 4] = uint8(c2da_fresh5)
    c2da_mem[box + 1 * 4 + 1] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[box + 1 * 4 + 2] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[box + 1 * 4 + 3] = uint8(c2da_fresh5 >> 0x18)
    return
}
[export, sideeffects]
def M_AddToBox(var box_0 : int; var x : int; var y : int) {
    if (x < int(uint(c2da_mem[box_0 + 2 * 4]) | uint(c2da_mem[box_0 + 2 * 4 + 1]) << 0x8 | uint(c2da_mem[box_0 + 2 * 4 + 2]) << 0x10 | uint(c2da_mem[box_0 + 2 * 4 + 3]) << 0x18)) {
        let c2da_fresh6 : uint = uint(x)
        c2da_mem[box_0 + 2 * 4] = uint8(c2da_fresh6)
        c2da_mem[box_0 + 2 * 4 + 1] = uint8(c2da_fresh6 >> 0x8)
        c2da_mem[box_0 + 2 * 4 + 2] = uint8(c2da_fresh6 >> 0x10)
        c2da_mem[box_0 + 2 * 4 + 3] = uint8(c2da_fresh6 >> 0x18)
    } elif (x > int(uint(c2da_mem[box_0 + 3 * 4]) | uint(c2da_mem[box_0 + 3 * 4 + 1]) << 0x8 | uint(c2da_mem[box_0 + 3 * 4 + 2]) << 0x10 | uint(c2da_mem[box_0 + 3 * 4 + 3]) << 0x18)) {
        let c2da_fresh7 : uint = uint(x)
        c2da_mem[box_0 + 3 * 4] = uint8(c2da_fresh7)
        c2da_mem[box_0 + 3 * 4 + 1] = uint8(c2da_fresh7 >> 0x8)
        c2da_mem[box_0 + 3 * 4 + 2] = uint8(c2da_fresh7 >> 0x10)
        c2da_mem[box_0 + 3 * 4 + 3] = uint8(c2da_fresh7 >> 0x18)
    }
    if (y < int(uint(c2da_mem[box_0 + 1 * 4]) | uint(c2da_mem[box_0 + 1 * 4 + 1]) << 0x8 | uint(c2da_mem[box_0 + 1 * 4 + 2]) << 0x10 | uint(c2da_mem[box_0 + 1 * 4 + 3]) << 0x18)) {
        let c2da_fresh8 : uint = uint(y)
        c2da_mem[box_0 + 1 * 4] = uint8(c2da_fresh8)
        c2da_mem[box_0 + 1 * 4 + 1] = uint8(c2da_fresh8 >> 0x8)
        c2da_mem[box_0 + 1 * 4 + 2] = uint8(c2da_fresh8 >> 0x10)
        c2da_mem[box_0 + 1 * 4 + 3] = uint8(c2da_fresh8 >> 0x18)
    } elif (y > int(uint(c2da_mem[box_0 + 0 * 4]) | uint(c2da_mem[box_0 + 0 * 4 + 1]) << 0x8 | uint(c2da_mem[box_0 + 0 * 4 + 2]) << 0x10 | uint(c2da_mem[box_0 + 0 * 4 + 3]) << 0x18)) {
        let c2da_fresh9 : uint = uint(y)
        c2da_mem[box_0 + 0 * 4] = uint8(c2da_fresh9)
        c2da_mem[box_0 + 0 * 4 + 1] = uint8(c2da_fresh9 >> 0x8)
        c2da_mem[box_0 + 0 * 4 + 2] = uint8(c2da_fresh9 >> 0x10)
        c2da_mem[box_0 + 0 * 4 + 3] = uint8(c2da_fresh9 >> 0x18)
    }
    return
}
