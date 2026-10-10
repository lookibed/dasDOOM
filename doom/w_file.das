options gen2
options solid_context = true
options stack = 4194304
module w_file public

require c2da_runtime
require m_argv
require w_file_stdc
var private c2da_str_0 : array<int8> = [int8(45), int8(109), int8(109), int8(97), int8(112), int8(0)]

[export, sideeffects]
def W_OpenFile(var path : int8?) : _wad_file_s? {
    var result_0 : _wad_file_s?
    var i : int
    if (M_CheckParm(unsafe(addr<int8?>(c2da_str_0[0]))) == 0) {
        return unsafe(reinterpret<_wad_file_s?>(invoke(stdc_wad_file.OpenFile, path)))
    }
    result_0 = null
    i = 0
    while (uint64(i) < 8ul / 8ul) {
        result_0 = unsafe(reinterpret<_wad_file_s?>(unsafe(reinterpret<_wad_file_s?>(invoke(wad_file_classes[i].OpenFile, path)))))
        if (result_0 != null) {
            break
        }
        i++
    }
    return unsafe(reinterpret<_wad_file_s?>(result_0))
}
var private wad_file_classes : wad_file_class_t? [1] = fixed_array<wad_file_class_t?>(unsafe(addr(stdc_wad_file)))

[export, sideeffects]
def W_CloseFile(var wad : _wad_file_s?) {
    invoke(wad.file_class.CloseFile, wad)
    return
}
[export, sideeffects]
def W_Read(var wad_0 : _wad_file_s?; var offset : uint; var buffer : uint8?; var buffer_len : uint64) : uint64 {
    return invoke(wad_0.file_class.Read, wad_0, offset, buffer, buffer_len)
}
[sideeffects]
def private c2da_layout_proofs() {
    static_assert(typeinfo sizeof(type<_wad_file_s>) == 24, "C layout of _wad_file_s: sizeof")
    static_assert(typeinfo alignof(type<_wad_file_s>) == 8, "C layout of _wad_file_s: alignof")
    static_assert(typeinfo offsetof<file_class>(type<_wad_file_s>) == 0, "C layout of _wad_file_s: offsetof file_class")
    static_assert(typeinfo offsetof<mapped>(type<_wad_file_s>) == 8, "C layout of _wad_file_s: offsetof mapped")
    static_assert(typeinfo offsetof<length>(type<_wad_file_s>) == 16, "C layout of _wad_file_s: offsetof length")
    static_assert(typeinfo sizeof(type<wad_file_class_t>) == 24, "C layout of wad_file_class_t: sizeof")
    static_assert(typeinfo alignof(type<wad_file_class_t>) == 8, "C layout of wad_file_class_t: alignof")
    static_assert(typeinfo offsetof<OpenFile>(type<wad_file_class_t>) == 0, "C layout of wad_file_class_t: offsetof OpenFile")
    static_assert(typeinfo offsetof<CloseFile>(type<wad_file_class_t>) == 8, "C layout of wad_file_class_t: offsetof CloseFile")
    static_assert(typeinfo offsetof<Read>(type<wad_file_class_t>) == 16, "C layout of wad_file_class_t: offsetof Read")
    static_assert(typeinfo sizeof(type<wad_file_t>) == 24, "C layout of wad_file_t: sizeof")
    static_assert(typeinfo alignof(type<wad_file_t>) == 8, "C layout of wad_file_t: alignof")
    static_assert(typeinfo offsetof<file_class>(type<wad_file_t>) == 0, "C layout of wad_file_t: offsetof file_class")
    static_assert(typeinfo offsetof<mapped>(type<wad_file_t>) == 8, "C layout of wad_file_t: offsetof mapped")
    static_assert(typeinfo offsetof<length>(type<wad_file_t>) == 16, "C layout of wad_file_t: offsetof length")
}
