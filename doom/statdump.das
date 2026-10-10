options gen2
options solid_context = true
options stack = 4194304
module statdump public

require c2da_runtime
require m_argv
var private c2da_str_0 : array<int8> = [int8(45), int8(115), int8(116), int8(97), int8(116), int8(100), int8(117), int8(109), int8(112), int8(0)]

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
def StatCopy(var stats : wbstartstruct_t?) {
    if (M_ParmExists(unsafe(addr<int8?>(c2da_str_0[0]))) != 0x0 && num_captured_stats < 32) {
        unsafe(memcpy(unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(unsafe(addr<uint8?>(unsafe(unsafe(addr(captured_stats[0]))[num_captured_stats]))))))), unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(stats)))))), 200ul))
        num_captured_stats++
    }
    return
}
var private num_captured_stats : int = 0

var private captured_stats : wbstartstruct_t[32]

[export, sideeffects]
def StatDump() {
    return
}
[sideeffects]
def private c2da_layout_proofs() {
    static_assert(typeinfo sizeof(type<wbplayerstruct_t>) == 40, "C layout of wbplayerstruct_t: sizeof")
    static_assert(typeinfo alignof(type<wbplayerstruct_t>) == 4, "C layout of wbplayerstruct_t: alignof")
    static_assert(typeinfo offsetof<in_0>(type<wbplayerstruct_t>) == 0, "C layout of wbplayerstruct_t: offsetof in_0")
    static_assert(typeinfo offsetof<skills>(type<wbplayerstruct_t>) == 4, "C layout of wbplayerstruct_t: offsetof skills")
    static_assert(typeinfo offsetof<sitems>(type<wbplayerstruct_t>) == 8, "C layout of wbplayerstruct_t: offsetof sitems")
    static_assert(typeinfo offsetof<ssecret>(type<wbplayerstruct_t>) == 12, "C layout of wbplayerstruct_t: offsetof ssecret")
    static_assert(typeinfo offsetof<stime>(type<wbplayerstruct_t>) == 16, "C layout of wbplayerstruct_t: offsetof stime")
    static_assert(typeinfo offsetof<frags>(type<wbplayerstruct_t>) == 20, "C layout of wbplayerstruct_t: offsetof frags")
    static_assert(typeinfo offsetof<score>(type<wbplayerstruct_t>) == 36, "C layout of wbplayerstruct_t: offsetof score")
    static_assert(typeinfo sizeof(type<wbstartstruct_t>) == 200, "C layout of wbstartstruct_t: sizeof")
    static_assert(typeinfo alignof(type<wbstartstruct_t>) == 4, "C layout of wbstartstruct_t: alignof")
    static_assert(typeinfo offsetof<epsd>(type<wbstartstruct_t>) == 0, "C layout of wbstartstruct_t: offsetof epsd")
    static_assert(typeinfo offsetof<didsecret>(type<wbstartstruct_t>) == 4, "C layout of wbstartstruct_t: offsetof didsecret")
    static_assert(typeinfo offsetof<last>(type<wbstartstruct_t>) == 8, "C layout of wbstartstruct_t: offsetof last")
    static_assert(typeinfo offsetof<next>(type<wbstartstruct_t>) == 12, "C layout of wbstartstruct_t: offsetof next")
    static_assert(typeinfo offsetof<maxkills>(type<wbstartstruct_t>) == 16, "C layout of wbstartstruct_t: offsetof maxkills")
    static_assert(typeinfo offsetof<maxitems>(type<wbstartstruct_t>) == 20, "C layout of wbstartstruct_t: offsetof maxitems")
    static_assert(typeinfo offsetof<maxsecret>(type<wbstartstruct_t>) == 24, "C layout of wbstartstruct_t: offsetof maxsecret")
    static_assert(typeinfo offsetof<maxfrags>(type<wbstartstruct_t>) == 28, "C layout of wbstartstruct_t: offsetof maxfrags")
    static_assert(typeinfo offsetof<partime>(type<wbstartstruct_t>) == 32, "C layout of wbstartstruct_t: offsetof partime")
    static_assert(typeinfo offsetof<pnum>(type<wbstartstruct_t>) == 36, "C layout of wbstartstruct_t: offsetof pnum")
    static_assert(typeinfo offsetof<plyr>(type<wbstartstruct_t>) == 40, "C layout of wbstartstruct_t: offsetof plyr")
}
