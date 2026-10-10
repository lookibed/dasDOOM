options gen2
options solid_context = true
options stack = 4194304
module m_cheat public

require c2da_runtime
require strings
require daslib/fio
[export, sideeffects]
def cht_CheckCheat(var cht : cheatseq_t?; var key : int8) : int {
    var c2da_fresh1 : int = 0
    if (cht.parameter_chars > 0) {
        var c2da_fresh0 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(cht))))
        if (c2da_std_strlen(unsafe(reinterpret<uint64>(c2da_fresh0))) < cht.sequence_len) {
            c2da_fresh1 = 1
        }
    }
    if (c2da_fresh1 != 0) {
        return 0
    }
    var c2da_fresh2 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(cht))))
    if (cht.chars_read < c2da_std_strlen(unsafe(reinterpret<uint64>(c2da_fresh2)))) {
        var c2da_fresh3 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(cht))))
        if (int(key) == int(unsafe(unsafe(reinterpret<int8?>(c2da_fresh3))[int(cht.chars_read)]))) {
            let c2da_postinc : uint64 = cht.chars_read
            cht.chars_read = c2da_postinc + 1ul
        } else {
            cht.chars_read = 0ul
        }
        cht.param_chars_read = 0
    } elif (cht.param_chars_read < cht.parameter_chars) {
        var c2da_fresh4 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(cht)) + 60ul))
        unsafe(unsafe(reinterpret<int8?>(c2da_fresh4))[cht.param_chars_read]) = int8(key)  // nolint:PERF020
        let c2da_postinc_0 : int = cht.param_chars_read
        cht.param_chars_read = c2da_postinc_0 + 1
    }
    var c2da_fresh5 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(cht))))
    if (cht.chars_read >= c2da_std_strlen(unsafe(reinterpret<uint64>(c2da_fresh5))) && cht.param_chars_read >= cht.parameter_chars) {
        let c2da_fresh6 : int = 0
        cht.param_chars_read = c2da_fresh6
        cht.chars_read = uint64(c2da_fresh6)
        return 1
    }
    return 0
}
[export, sideeffects]
def cht_GetParam(var cht_0 : cheatseq_t?; var buffer : int8?) {
    var c2da_fresh7 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(cht_0)) + 60ul))
    let c2da_fresh8 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(buffer))))
    let c2da_fresh9 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(c2da_fresh7))))
    let c2da_fresh10 : uint64 = uint64(cht_0.parameter_chars)
    if (c2da_fresh10 != 0x0) {
        unsafe(memcpy(unsafe(reinterpret<void?>(c2da_fresh8)), unsafe(reinterpret<void?>(c2da_fresh9)), c2da_fresh10))
    }
    return
}
[sideeffects]
def private c2da_layout_proofs() {
    static_assert(typeinfo sizeof(type<cheatseq_t>) == 72, "C layout of cheatseq_t: sizeof")
    static_assert(typeinfo alignof(type<cheatseq_t>) == 8, "C layout of cheatseq_t: alignof")
    static_assert(typeinfo offsetof<sequence>(type<cheatseq_t>) == 0, "C layout of cheatseq_t: offsetof sequence")
    static_assert(typeinfo offsetof<sequence_len>(type<cheatseq_t>) == 32, "C layout of cheatseq_t: offsetof sequence_len")
    static_assert(typeinfo offsetof<parameter_chars>(type<cheatseq_t>) == 40, "C layout of cheatseq_t: offsetof parameter_chars")
    static_assert(typeinfo offsetof<chars_read>(type<cheatseq_t>) == 48, "C layout of cheatseq_t: offsetof chars_read")
    static_assert(typeinfo offsetof<param_chars_read>(type<cheatseq_t>) == 56, "C layout of cheatseq_t: offsetof param_chars_read")
    static_assert(typeinfo offsetof<parameter_buf>(type<cheatseq_t>) == 60, "C layout of cheatseq_t: offsetof parameter_buf")
}
