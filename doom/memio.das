options gen2
options solid_context = true
options stack = 4194304
module memio public

require dasdoom_runtime
require i_system_cluster
require strings
require daslib/fio
var private c2da_str_0 : array<int8> = [int8(110), int8(111), int8(116), int8(32), int8(97), int8(32), int8(114), int8(101), int8(97), int8(100), int8(32), int8(115), int8(116), int8(114), int8(101), int8(97), int8(109), int8(10), int8(0)]

var private c2da_str_1 : array<int8> = [int8(69), int8(114), int8(114), int8(111), int8(114), int8(32), int8(115), int8(101), int8(101), int8(107), int8(105), int8(110), int8(103), int8(32), int8(116), int8(111), int8(32), int8(37), int8(105), int8(10), int8(0)]

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
def mem_fopen_read(var buf : uint8?; var buflen : uint64) : _MEMFILE? {
    var file : _MEMFILE? = unsafe(reinterpret<_MEMFILE?>(unsafe(reinterpret<_MEMFILE?>(Z_Malloc(32, 1, null)))))
    file.buf = buf
    file.buflen = uint64(buflen)  // nolint:PERF020
    file.position = 0u
    file.mode = unsafe(reinterpret<memfile_mode_t>(0u))
    return unsafe(reinterpret<_MEMFILE?>(file))
}
[export, sideeffects]
def mem_fread(var buf_0 : uint8?; var size : uint64; var nmemb : uint64; var stream : _MEMFILE?) : uint64 {
    var items : uint64
    if (uint(stream.mode) != 0u) {
        c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_0[0])), [])
        return 0xfffffffffffffffful
    }
    items = nmemb
    if (items * size > stream.buflen - uint64(stream.position)) {
        items = (stream.buflen - uint64(stream.position)) / size
    }
    var c2da_fresh0 : uint8? = unsafe(reinterpret<uint8?>(unsafe(stream.buf + int64(stream.position))))
    let c2da_fresh1 : uint64 = unsafe(reinterpret<uint64>(buf_0))
    let c2da_fresh2 : uint64 = unsafe(reinterpret<uint64>(c2da_fresh0))
    let c2da_fresh3 : uint64 = items * size
    if (c2da_fresh3 != 0x0) {
        unsafe(memcpy(unsafe(reinterpret<void?>(c2da_fresh1)), unsafe(reinterpret<void?>(c2da_fresh2)), c2da_fresh3))
    }
    stream.position = uint(uint64(stream.position) + items * size)
    return items
}
[export, sideeffects]
def mem_fopen_write() : _MEMFILE? {
    var file_0 : _MEMFILE? = unsafe(reinterpret<_MEMFILE?>(unsafe(reinterpret<_MEMFILE?>(Z_Malloc(32, 1, null)))))
    file_0.alloced = 1024ul
    file_0.buf = unsafe(reinterpret<uint8?>(Z_Malloc(int(file_0.alloced), 1, null)))
    file_0.buflen = 0ul
    file_0.position = 0u
    file_0.mode = unsafe(reinterpret<memfile_mode_t>(1u))
    return unsafe(reinterpret<_MEMFILE?>(file_0))
}
[export, sideeffects]
def mem_fwrite(var ptr : uint8?; var size_0 : uint64; var nmemb_0 : uint64; var stream_0 : _MEMFILE?) : uint64 {
    var bytes : uint64
    var newbuf : uint8?
    if (uint(stream_0.mode) != 1u) {
        return 0xfffffffffffffffful
    }
    bytes = size_0 * nmemb_0
    while (bytes > stream_0.alloced - uint64(stream_0.position)) {
        newbuf = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(Z_Malloc(int(stream_0.alloced * 2ul), 1, null)))))
        let c2da_fresh4 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(newbuf))))
        let c2da_fresh5 : uint64 = unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(stream_0.buf))))
        let c2da_fresh6 : uint64 = stream_0.alloced
        if (c2da_fresh6 != 0x0) {
            unsafe(memcpy(unsafe(reinterpret<void?>(c2da_fresh4)), unsafe(reinterpret<void?>(c2da_fresh5)), c2da_fresh6))
        }
        Z_Free(unsafe(reinterpret<uint8?>(stream_0.buf)))
        stream_0.buf = newbuf
        stream_0.alloced *= 2ul
    }
    var c2da_fresh7 : uint8? = unsafe(reinterpret<uint8?>(unsafe(stream_0.buf + int64(stream_0.position))))
    let c2da_fresh8 : uint64 = unsafe(reinterpret<uint64>(c2da_fresh7))
    let c2da_fresh9 : uint64 = unsafe(reinterpret<uint64>(ptr))
    let c2da_fresh10 : uint64 = bytes
    if (c2da_fresh10 != 0x0) {
        unsafe(memcpy(unsafe(reinterpret<void?>(c2da_fresh8)), unsafe(reinterpret<void?>(c2da_fresh9)), c2da_fresh10))
    }
    stream_0.position = uint(uint64(stream_0.position) + bytes)
    if (uint64(stream_0.position) > stream_0.buflen) {
        stream_0.buflen = uint64(stream_0.position)
    }
    return nmemb_0
}
[export, sideeffects]
def mem_get_buf(var stream_1 : _MEMFILE?; var buf_1 : uint8??; var buflen_0 : uint64?) {
    *buf_1 = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(stream_1.buf))))
    *buflen_0 = uint64(stream_1.buflen)  // nolint:PERF020
    return
}
[export, sideeffects]
def mem_fclose(var stream_2 : _MEMFILE?) {
    if (uint(stream_2.mode) == 1u) {
        Z_Free(unsafe(reinterpret<uint8?>(stream_2.buf)))
    }
    Z_Free(unsafe(reinterpret<uint8?>(stream_2)))
    return
}
[export, sideeffects]
def mem_ftell(var stream_3 : _MEMFILE?) : int64 {
    return int64(stream_3.position)
}
[export, sideeffects]
def mem_fseek(var stream_4 : _MEMFILE?; var position : int64; var whence : mem_rel_t) : int {
    var c2da_fresh11 : uint
    var newpos : uint
    c2da_fresh11 = uint(whence)
    if (c2da_fresh11 == 0x0u) {
        newpos = uint(int(position))
    } elif (c2da_fresh11 == 0x1u) {
        newpos = uint(int(int64(stream_4.position) + position))
    } elif (c2da_fresh11 == 0x2u) {
        newpos = uint(int(stream_4.buflen + uint64(position)))
    } else {
        return -1
    }
    if (uint64(newpos) < stream_4.buflen) {
        stream_4.position = newpos
        return 0
    } else {
        c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_1[0])), [C2daVaArg(tag = 1, i64 = int64(newpos), f64 = 0.0lf, raw = 0x0)])
        return -1
    }
}
[sideeffects]
def private c2da_layout_proofs() {
    static_assert(typeinfo sizeof(type<_IO_FILE>) == 216, "C layout of _IO_FILE: sizeof")
    static_assert(typeinfo alignof(type<_IO_FILE>) == 8, "C layout of _IO_FILE: alignof")
    static_assert(typeinfo offsetof<_flags>(type<_IO_FILE>) == 0, "C layout of _IO_FILE: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<_IO_FILE>) == 8, "C layout of _IO_FILE: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<_IO_FILE>) == 16, "C layout of _IO_FILE: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<_IO_FILE>) == 24, "C layout of _IO_FILE: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<_IO_FILE>) == 32, "C layout of _IO_FILE: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<_IO_FILE>) == 40, "C layout of _IO_FILE: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<_IO_FILE>) == 48, "C layout of _IO_FILE: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<_IO_FILE>) == 56, "C layout of _IO_FILE: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<_IO_FILE>) == 64, "C layout of _IO_FILE: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<_IO_FILE>) == 72, "C layout of _IO_FILE: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<_IO_FILE>) == 80, "C layout of _IO_FILE: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<_IO_FILE>) == 88, "C layout of _IO_FILE: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<_IO_FILE>) == 96, "C layout of _IO_FILE: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<_IO_FILE>) == 104, "C layout of _IO_FILE: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<_IO_FILE>) == 112, "C layout of _IO_FILE: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<_IO_FILE>) == 116, "C layout of _IO_FILE: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<_IO_FILE>) == 120, "C layout of _IO_FILE: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<_IO_FILE>) == 128, "C layout of _IO_FILE: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<_IO_FILE>) == 130, "C layout of _IO_FILE: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<_IO_FILE>) == 131, "C layout of _IO_FILE: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<_IO_FILE>) == 136, "C layout of _IO_FILE: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<_IO_FILE>) == 144, "C layout of _IO_FILE: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<_IO_FILE>) == 152, "C layout of _IO_FILE: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<_IO_FILE>) == 160, "C layout of _IO_FILE: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<_IO_FILE>) == 168, "C layout of _IO_FILE: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<_IO_FILE>) == 176, "C layout of _IO_FILE: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<_IO_FILE>) == 184, "C layout of _IO_FILE: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<_IO_FILE>) == 192, "C layout of _IO_FILE: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<_IO_FILE>) == 196, "C layout of _IO_FILE: offsetof _unused2")
    static_assert(typeinfo sizeof(type<FILE_0>) == 216, "C layout of FILE_0: sizeof")
    static_assert(typeinfo alignof(type<FILE_0>) == 8, "C layout of FILE_0: alignof")
    static_assert(typeinfo offsetof<_flags>(type<FILE_0>) == 0, "C layout of FILE_0: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<FILE_0>) == 8, "C layout of FILE_0: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<FILE_0>) == 16, "C layout of FILE_0: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<FILE_0>) == 24, "C layout of FILE_0: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<FILE_0>) == 32, "C layout of FILE_0: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<FILE_0>) == 40, "C layout of FILE_0: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<FILE_0>) == 48, "C layout of FILE_0: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<FILE_0>) == 56, "C layout of FILE_0: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<FILE_0>) == 64, "C layout of FILE_0: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<FILE_0>) == 72, "C layout of FILE_0: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<FILE_0>) == 80, "C layout of FILE_0: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<FILE_0>) == 88, "C layout of FILE_0: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<FILE_0>) == 96, "C layout of FILE_0: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<FILE_0>) == 104, "C layout of FILE_0: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<FILE_0>) == 112, "C layout of FILE_0: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<FILE_0>) == 116, "C layout of FILE_0: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<FILE_0>) == 120, "C layout of FILE_0: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<FILE_0>) == 128, "C layout of FILE_0: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<FILE_0>) == 130, "C layout of FILE_0: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<FILE_0>) == 131, "C layout of FILE_0: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<FILE_0>) == 136, "C layout of FILE_0: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<FILE_0>) == 144, "C layout of FILE_0: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<FILE_0>) == 152, "C layout of FILE_0: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<FILE_0>) == 160, "C layout of FILE_0: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<FILE_0>) == 168, "C layout of FILE_0: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<FILE_0>) == 176, "C layout of FILE_0: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<FILE_0>) == 184, "C layout of FILE_0: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<FILE_0>) == 192, "C layout of FILE_0: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<FILE_0>) == 196, "C layout of FILE_0: offsetof _unused2")
    static_assert(typeinfo sizeof(type<_MEMFILE>) == 32, "C layout of _MEMFILE: sizeof")
    static_assert(typeinfo alignof(type<_MEMFILE>) == 8, "C layout of _MEMFILE: alignof")
    static_assert(typeinfo offsetof<buf>(type<_MEMFILE>) == 0, "C layout of _MEMFILE: offsetof buf")
    static_assert(typeinfo offsetof<buflen>(type<_MEMFILE>) == 8, "C layout of _MEMFILE: offsetof buflen")
    static_assert(typeinfo offsetof<alloced>(type<_MEMFILE>) == 16, "C layout of _MEMFILE: offsetof alloced")
    static_assert(typeinfo offsetof<position>(type<_MEMFILE>) == 24, "C layout of _MEMFILE: offsetof position")
    static_assert(typeinfo offsetof<mode>(type<_MEMFILE>) == 28, "C layout of _MEMFILE: offsetof mode")
    static_assert(typeinfo sizeof(type<MEMFILE>) == 32, "C layout of MEMFILE: sizeof")
    static_assert(typeinfo alignof(type<MEMFILE>) == 8, "C layout of MEMFILE: alignof")
    static_assert(typeinfo offsetof<buf>(type<MEMFILE>) == 0, "C layout of MEMFILE: offsetof buf")
    static_assert(typeinfo offsetof<buflen>(type<MEMFILE>) == 8, "C layout of MEMFILE: offsetof buflen")
    static_assert(typeinfo offsetof<alloced>(type<MEMFILE>) == 16, "C layout of MEMFILE: offsetof alloced")
    static_assert(typeinfo offsetof<position>(type<MEMFILE>) == 24, "C layout of MEMFILE: offsetof position")
    static_assert(typeinfo offsetof<mode>(type<MEMFILE>) == 28, "C layout of MEMFILE: offsetof mode")
}
