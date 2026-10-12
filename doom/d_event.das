options gen2
options solid_context = true
options stack = 4194304
module d_event public

require dasdoom_runtime
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
def D_PostEvent(var ev : event_t?) {
    events[eventhead] = *ev
    eventhead = (eventhead + 1) % 64
    return
}
var private eventhead : int

var private events : event_t[64]

[export, sideeffects]
def D_PopEvent() : event_t? {
    var result_0 : event_t?
    if (eventtail == eventhead) {
        return unsafe(reinterpret<event_t?>(null))
    }
    result_0 = unsafe(addr<event_t?>(unsafe(unsafe(addr(events[0]))[eventtail])))
    eventtail = (eventtail + 1) % 64
    return unsafe(reinterpret<event_t?>(result_0))
}
var private eventtail : int

[sideeffects]
def private c2da_layout_proofs() {
    static_assert(typeinfo sizeof(type<event_t>) == 20, "C layout of event_t: sizeof")
    static_assert(typeinfo alignof(type<event_t>) == 4, "C layout of event_t: alignof")
    static_assert(typeinfo offsetof<type_0>(type<event_t>) == 0, "C layout of event_t: offsetof type_0")
    static_assert(typeinfo offsetof<data1>(type<event_t>) == 4, "C layout of event_t: offsetof data1")
    static_assert(typeinfo offsetof<data2>(type<event_t>) == 8, "C layout of event_t: offsetof data2")
    static_assert(typeinfo offsetof<data3>(type<event_t>) == 12, "C layout of event_t: offsetof data3")
    static_assert(typeinfo offsetof<data4>(type<event_t>) == 16, "C layout of event_t: offsetof data4")
}
