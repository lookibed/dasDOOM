[export, sideeffects]
def I_GetTime() : int {
    var ticks : uint = uint(I_GetTicks())
    if (basetime == 0u) {
        basetime = ticks
    }
    ticks -= basetime
    return int(ticks * 35u / 1000u)
}
var private basetime : uint = 0u

[export, sideeffects]
def I_GetTicks() : int {
    return int(DG_GetTicksMs())
}
[export, sideeffects]
def I_GetTimeMS() : int {
    var ticks_0 : uint = uint(I_GetTicks())
    if (basetime == 0u) {
        basetime = ticks_0
    }
    return int(ticks_0 - basetime)
}
[export, sideeffects]
def I_Sleep(var ms : int) {
    DG_SleepMs(uint(ms))
    return
}
[export, sideeffects]
def I_InitTimer() {
    return
}
[export, sideeffects]
def I_WaitVBL(var count : int) {
    return
}
[sideeffects]
def private c2da___bswap_16_5(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_5(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_5(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_5(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_5(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_5(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
