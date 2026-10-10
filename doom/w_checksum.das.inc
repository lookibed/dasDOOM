[sideeffects]
def private c2da___bswap_16_17(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_17(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_17(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_17(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_17(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_17(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
[export, sideeffects]
def W_Checksum(var digest : uint8?) {
    var sha1_context : sha1_context_s
    var i : uint
    SHA1_Init(unsafe(addr<sha1_context_s?>(sha1_context)))
    num_open_wadfiles = 0
    i = 0u
    while (i < numlumps) {
        ChecksumAddLump(unsafe(addr<sha1_context_s?>(sha1_context)), unsafe(addr<lumpinfo_s?>(unsafe(lumpinfo[int(i)]))))
        i++
    }
    SHA1_Final(digest, unsafe(addr<sha1_context_s?>(sha1_context)))
    return
}
[sideeffects]
def private ChecksumAddLump(var sha1_context_0 : sha1_context_s?; var lump : lumpinfo_s?) {
    var buf : int8[9]
    var c2da_fresh0 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<uint64>(lump))))
    M_StringCopy(unsafe(addr<int8?>(buf[0])), unsafe(reinterpret<int8 const?>(c2da_fresh0)), 9ul)
    SHA1_UpdateString(sha1_context_0, unsafe(addr<int8?>(buf[0])))
    SHA1_UpdateInt32(sha1_context_0, uint(GetFileNumber(lump.wad_file)))
    SHA1_UpdateInt32(sha1_context_0, uint(lump.position))
    SHA1_UpdateInt32(sha1_context_0, uint(lump.size))
    return
}
[sideeffects]
def private GetFileNumber(var handle : _wad_file_s?) : int {
    var i_0 : int
    var result_0 : int
    i_0 = 0
    while (i_0 < num_open_wadfiles) {
        if (unsafe(open_wadfiles[i_0]) == handle) {
            return i_0
        }
        i_0++
    }
    open_wadfiles = unsafe(reinterpret<_wad_file_s??>(unsafe(reinterpret<_wad_file_s??>(unsafe(reinterpret<uint8?>(c2da_rt_realloc(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(open_wadfiles)))), 8ul * uint64(num_open_wadfiles + 1))))))))
    unsafe(open_wadfiles[num_open_wadfiles]) = unsafe(reinterpret<_wad_file_s?>(handle))
    result_0 = num_open_wadfiles
    num_open_wadfiles++
    return result_0
}
var private num_open_wadfiles : int = 0

var private open_wadfiles : _wad_file_s?? = null

[sideeffects]
def private c2da_layout_proofs_39() {
    static_assert(typeinfo sizeof(type<sha1_context_s>) == 92, "C layout of sha1_context_s: sizeof")
    static_assert(typeinfo alignof(type<sha1_context_s>) == 4, "C layout of sha1_context_s: alignof")
    static_assert(typeinfo offsetof<h0>(type<sha1_context_s>) == 0, "C layout of sha1_context_s: offsetof h0")
    static_assert(typeinfo offsetof<h1>(type<sha1_context_s>) == 4, "C layout of sha1_context_s: offsetof h1")
    static_assert(typeinfo offsetof<h2>(type<sha1_context_s>) == 8, "C layout of sha1_context_s: offsetof h2")
    static_assert(typeinfo offsetof<h3>(type<sha1_context_s>) == 12, "C layout of sha1_context_s: offsetof h3")
    static_assert(typeinfo offsetof<h4>(type<sha1_context_s>) == 16, "C layout of sha1_context_s: offsetof h4")
    static_assert(typeinfo offsetof<nblocks>(type<sha1_context_s>) == 20, "C layout of sha1_context_s: offsetof nblocks")
    static_assert(typeinfo offsetof<buf>(type<sha1_context_s>) == 24, "C layout of sha1_context_s: offsetof buf")
    static_assert(typeinfo offsetof<count>(type<sha1_context_s>) == 88, "C layout of sha1_context_s: offsetof count")
    static_assert(typeinfo sizeof(type<sha1_context_t>) == 92, "C layout of sha1_context_t: sizeof")
    static_assert(typeinfo alignof(type<sha1_context_t>) == 4, "C layout of sha1_context_t: alignof")
    static_assert(typeinfo offsetof<h0>(type<sha1_context_t>) == 0, "C layout of sha1_context_t: offsetof h0")
    static_assert(typeinfo offsetof<h1>(type<sha1_context_t>) == 4, "C layout of sha1_context_t: offsetof h1")
    static_assert(typeinfo offsetof<h2>(type<sha1_context_t>) == 8, "C layout of sha1_context_t: offsetof h2")
    static_assert(typeinfo offsetof<h3>(type<sha1_context_t>) == 12, "C layout of sha1_context_t: offsetof h3")
    static_assert(typeinfo offsetof<h4>(type<sha1_context_t>) == 16, "C layout of sha1_context_t: offsetof h4")
    static_assert(typeinfo offsetof<nblocks>(type<sha1_context_t>) == 20, "C layout of sha1_context_t: offsetof nblocks")
    static_assert(typeinfo offsetof<buf>(type<sha1_context_t>) == 24, "C layout of sha1_context_t: offsetof buf")
    static_assert(typeinfo offsetof<count>(type<sha1_context_t>) == 88, "C layout of sha1_context_t: offsetof count")
    static_assert(typeinfo sizeof(type<lumpinfo_t>) == 40, "C layout of lumpinfo_t: sizeof")
    static_assert(typeinfo alignof(type<lumpinfo_t>) == 8, "C layout of lumpinfo_t: alignof")
    static_assert(typeinfo offsetof<name>(type<lumpinfo_t>) == 0, "C layout of lumpinfo_t: offsetof name")
    static_assert(typeinfo offsetof<wad_file>(type<lumpinfo_t>) == 8, "C layout of lumpinfo_t: offsetof wad_file")
    static_assert(typeinfo offsetof<position>(type<lumpinfo_t>) == 16, "C layout of lumpinfo_t: offsetof position")
    static_assert(typeinfo offsetof<size>(type<lumpinfo_t>) == 20, "C layout of lumpinfo_t: offsetof size")
    static_assert(typeinfo offsetof<cache>(type<lumpinfo_t>) == 24, "C layout of lumpinfo_t: offsetof cache")
    static_assert(typeinfo offsetof<next>(type<lumpinfo_t>) == 32, "C layout of lumpinfo_t: offsetof next")
    static_assert(typeinfo sizeof(type<lumpinfo_s>) == 40, "C layout of lumpinfo_s: sizeof")
    static_assert(typeinfo alignof(type<lumpinfo_s>) == 8, "C layout of lumpinfo_s: alignof")
    static_assert(typeinfo offsetof<name>(type<lumpinfo_s>) == 0, "C layout of lumpinfo_s: offsetof name")
    static_assert(typeinfo offsetof<wad_file>(type<lumpinfo_s>) == 8, "C layout of lumpinfo_s: offsetof wad_file")
    static_assert(typeinfo offsetof<position>(type<lumpinfo_s>) == 16, "C layout of lumpinfo_s: offsetof position")
    static_assert(typeinfo offsetof<size>(type<lumpinfo_s>) == 20, "C layout of lumpinfo_s: offsetof size")
    static_assert(typeinfo offsetof<cache>(type<lumpinfo_s>) == 24, "C layout of lumpinfo_s: offsetof cache")
    static_assert(typeinfo offsetof<next>(type<lumpinfo_s>) == 32, "C layout of lumpinfo_s: offsetof next")
    static_assert(typeinfo sizeof(type<wad_file_t>) == 24, "C layout of wad_file_t: sizeof")
    static_assert(typeinfo alignof(type<wad_file_t>) == 8, "C layout of wad_file_t: alignof")
    static_assert(typeinfo offsetof<file_class>(type<wad_file_t>) == 0, "C layout of wad_file_t: offsetof file_class")
    static_assert(typeinfo offsetof<mapped>(type<wad_file_t>) == 8, "C layout of wad_file_t: offsetof mapped")
    static_assert(typeinfo offsetof<length>(type<wad_file_t>) == 16, "C layout of wad_file_t: offsetof length")
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
}
