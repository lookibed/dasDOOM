options gen2
options solid_context = true
options stack = 4194304
module w_file_stdc public

require c2da_runtime
require i_system_cluster
require strings
require daslib/fio
var private c2da_str_0 : array<int8> = [int8(114), int8(98), int8(0)]

var stdc_wad_file : wad_file_class_t

[init, sideeffects]
def private c2da_gset_stdc_wad_file() {
    unsafe {
        stdc_wad_file = wad_file_class_t(OpenFile = @@W_StdC_OpenFile, CloseFile = @@W_StdC_CloseFile, Read = @@W_StdC_Read)
    }
}
[export, sideeffects]
def W_StdC_Read(var wad : _wad_file_s?; var offset : uint; var buffer : uint8?; var buffer_len : uint64) : uint64 {
    var stdc_wad : stdc_wad_file_t?
    var result_0 : uint64
    stdc_wad = unsafe(reinterpret<stdc_wad_file_t?>(unsafe(reinterpret<stdc_wad_file_t?>(wad))))
    c2da_std_fseek(unsafe(reinterpret<uint64>(stdc_wad.fstream)), int64(offset), 0)
    result_0 = c2da_std_fread(unsafe(reinterpret<uint64>(buffer)), 1ul, buffer_len, unsafe(reinterpret<uint64>(stdc_wad.fstream)))
    return result_0
}
[sideeffects]
def private W_StdC_CloseFile(var wad_0 : _wad_file_s?) {
    var stdc_wad_0 : stdc_wad_file_t? = unsafe(reinterpret<stdc_wad_file_t?>(unsafe(reinterpret<stdc_wad_file_t?>(wad_0))))
    c2da_std_fclose(unsafe(reinterpret<uint64>(stdc_wad_0.fstream)))
    Z_Free(unsafe(reinterpret<uint8?>(stdc_wad_0)))
    return
}
[sideeffects]
def private W_StdC_OpenFile(var path : int8?) : _wad_file_s? {
    var result_1 : stdc_wad_file_t?
    var fstream : _IO_FILE? = unsafe(reinterpret<_IO_FILE?>(unsafe(reinterpret<_IO_FILE?>(c2da_std_fopen(unsafe(reinterpret<int8 const?>(path)), unsafe(addr<int8 const?>(c2da_str_0[0])))))))
    if (fstream == null) {
        return unsafe(reinterpret<_wad_file_s?>(null))
    }
    result_1 = unsafe(reinterpret<stdc_wad_file_t?>(unsafe(reinterpret<stdc_wad_file_t?>(Z_Malloc(32, 1, null)))))
    result_1.wad.file_class = unsafe(addr(stdc_wad_file))
    result_1.wad.mapped = null
    result_1.wad.length = uint(M_FileLength(fstream))
    result_1.fstream = fstream
    var c2da_fresh0 : _wad_file_s? = unsafe(reinterpret<_wad_file_s?>(unsafe(reinterpret<uint64>(result_1))))
    return unsafe(reinterpret<_wad_file_s?>(c2da_fresh0))
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
    static_assert(typeinfo sizeof(type<stdc_wad_file_t>) == 32, "C layout of stdc_wad_file_t: sizeof")
    static_assert(typeinfo alignof(type<stdc_wad_file_t>) == 8, "C layout of stdc_wad_file_t: alignof")
    static_assert(typeinfo offsetof<wad>(type<stdc_wad_file_t>) == 0, "C layout of stdc_wad_file_t: offsetof wad")
    static_assert(typeinfo offsetof<fstream>(type<stdc_wad_file_t>) == 24, "C layout of stdc_wad_file_t: offsetof fstream")
}
