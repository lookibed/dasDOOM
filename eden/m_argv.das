options gen2
options stack = 4194304
module m_argv public

require dasdoom_runtime
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
var myargc : int

var myargv : int

[export, sideeffects]
def M_CheckParm(var check : int) : int {
    return M_CheckParmWithArgs(check, 0)
}
[export, sideeffects]
def M_CheckParmWithArgs(var check_0 : int; var num_args : int) : int {
    var i : int = 1
    while (i < myargc - num_args) {
        if (c2da_lin_strcasecmp(check_0, int(uint(c2da_mem[myargv + i * 8]) | uint(c2da_mem[myargv + i * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + i * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + i * 8 + 3]) << 0x18)) == 0) {
            return i
        }
        i++
    }
    return 0
}
[export, sideeffects]
def M_FindResponseFile() {
    var i_0 : int = 1
    while (i_0 < myargc) {
        let c2da_fresh0 : int = int(uint(c2da_mem[myargv + i_0 * 8]) | uint(c2da_mem[myargv + i_0 * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + i_0 * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + i_0 * 8 + 3]) << 0x18) + 0
        if (int(int8(c2da_mem[c2da_fresh0])) == 64) {
            LoadResponseFile(i_0)
        }
        i_0++
    }
    return
}
[sideeffects]
def private LoadResponseFile(var argv_index : int) {
    return
}
[export, sideeffects]
def M_ParmExists(var check_1 : int) : uint {
    return uint(M_CheckParm(check_1) != 0 ? 1 : 0)
}
[export, sideeffects]
def M_GetExecutableName() : int {
    var sep : int = c2da_lin_strrchr(int(uint(c2da_mem[myargv + 0 * 8]) | uint(c2da_mem[myargv + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + 0 * 8 + 3]) << 0x18), 47)
    if (sep == 0) {
        return int(uint(c2da_mem[myargv + 0 * 8]) | uint(c2da_mem[myargv + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + 0 * 8 + 3]) << 0x18)
    } else {
        return sep + 1
    }
}
