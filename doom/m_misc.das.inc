var private c2da_str_m_misc_0 : array<int8> = [int8(119), int8(98), int8(0)]

var private c2da_str_m_misc_1 : array<int8> = [int8(114), int8(98), int8(0)]

var private c2da_str_m_misc_2 : array<int8> = [int8(67), int8(111), int8(117), int8(108), int8(100), int8(110), int8(39), int8(116), int8(32), int8(114), int8(101), int8(97), int8(100), int8(32), int8(102), int8(105), int8(108), int8(101), int8(32), int8(37), int8(115), int8(0)]

var private c2da_str_m_misc_3 : array<int8> = [int8(47), int8(116), int8(109), int8(112), int8(0)]

var private c2da_str_m_misc_4 : array<int8> = [int8(47), int8(0)]

var private c2da_str_m_misc_5 : array<int8> = [int8(77), int8(95), int8(83), int8(116), int8(114), int8(105), int8(110), int8(103), int8(74), int8(111), int8(105), int8(110), int8(58), int8(32), int8(70), int8(97), int8(105), int8(108), int8(101), int8(100), int8(32), int8(116), int8(111), int8(32), int8(97), int8(108), int8(108), int8(111), int8(99), int8(97), int8(116), int8(101), int8(32), int8(110), int8(101), int8(119), int8(32), int8(115), int8(116), int8(114), int8(105), int8(110), int8(103), int8(46), int8(0)]

var private c2da_str_m_misc_6 : array<int8> = [int8(114), int8(0)]

var private c2da_str_m_misc_7 : array<int8> = [int8(32), int8(48), int8(120), int8(37), int8(120), int8(0)]

var private c2da_str_m_misc_8 : array<int8> = [int8(32), int8(48), int8(88), int8(37), int8(120), int8(0)]

var private c2da_str_m_misc_9 : array<int8> = [int8(32), int8(48), int8(37), int8(111), int8(0)]

var private c2da_str_m_misc_10 : array<int8> = [int8(32), int8(37), int8(100), int8(0)]

var private c2da_str_m_misc_11 : array<int8> = [int8(87), int8(97), int8(114), int8(110), int8(105), int8(110), int8(103), int8(58), int8(32), int8(84), int8(114), int8(117), int8(110), int8(99), int8(97), int8(116), int8(101), int8(100), int8(32), int8(39), int8(37), int8(115), int8(39), int8(32), int8(108), int8(117), int8(109), int8(112), int8(32), int8(110), int8(97), int8(109), int8(101), int8(32), int8(116), int8(111), int8(32), int8(39), int8(37), int8(46), int8(56), int8(115), int8(39), int8(46), int8(10), int8(0)]

var private c2da_str_m_misc_12 : array<int8> = [int8(70), int8(97), int8(105), int8(108), int8(101), int8(100), int8(32), int8(116), int8(111), int8(32), int8(100), int8(117), int8(112), int8(108), int8(105), int8(99), int8(97), int8(116), int8(101), int8(32), int8(115), int8(116), int8(114), int8(105), int8(110), int8(103), int8(32), int8(40), int8(108), int8(101), int8(110), int8(103), int8(116), int8(104), int8(32), int8(37), int8(105), int8(41), int8(10), int8(0)]

var private c2da_str_m_misc_13 : array<int8> = [int8(77), int8(95), int8(83), int8(116), int8(114), int8(105), int8(110), int8(103), int8(82), int8(101), int8(112), int8(108), int8(97), int8(99), int8(101), int8(58), int8(32), int8(70), int8(97), int8(105), int8(108), int8(101), int8(100), int8(32), int8(116), int8(111), int8(32), int8(97), int8(108), int8(108), int8(111), int8(99), int8(97), int8(116), int8(101), int8(32), int8(110), int8(101), int8(119), int8(32), int8(115), int8(116), int8(114), int8(105), int8(110), int8(103), int8(0)]

[sideeffects]
def private c2da___bswap_16_0(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_0(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_0(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_0(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_0(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_0(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
[export, sideeffects]
def M_WriteFile(var name : int8?; var source : uint8?; var length_0 : int) : uint {
    var handle : _IO_FILE?
    var count : int
    handle = unsafe(reinterpret<_IO_FILE?>(unsafe(reinterpret<_IO_FILE?>(c2da_std_fopen(unsafe(reinterpret<int8 const?>(name)), unsafe(addr<int8 const?>(c2da_str_m_misc_0[0])))))))
    if (handle == null) {
        return 0u
    }
    count = int(c2da_std_fwrite(unsafe(reinterpret<uint64>(source)), 1ul, uint64(length_0), unsafe(reinterpret<uint64>(handle))))
    c2da_std_fclose(unsafe(reinterpret<uint64>(handle)))
    if (count < length_0) {
        return 0u
    }
    return 1u
}
[export, sideeffects]
def M_ReadFile(var name_0 : int8?; var buffer : uint8??) : int {
    var handle_0 : _IO_FILE?
    var count_0 : int
    var length_1 : int
    var buf : uint8?
    handle_0 = unsafe(reinterpret<_IO_FILE?>(unsafe(reinterpret<_IO_FILE?>(c2da_std_fopen(unsafe(reinterpret<int8 const?>(name_0)), unsafe(addr<int8 const?>(c2da_str_m_misc_1[0])))))))
    if (handle_0 == null) {
        I_Error(unsafe(addr<int8?>(c2da_str_m_misc_2[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(name_0)))])
    }
    length_1 = int(M_FileLength(handle_0))
    buf = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint8?>(Z_Malloc(length_1, 1, null)))))
    count_0 = int(c2da_std_fread(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(buf)))), 1ul, uint64(length_1), unsafe(reinterpret<uint64>(handle_0))))
    c2da_std_fclose(unsafe(reinterpret<uint64>(handle_0)))
    if (count_0 < length_1) {
        I_Error(unsafe(addr<int8?>(c2da_str_m_misc_2[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(name_0)))])
    }
    *buffer = unsafe(reinterpret<uint8?>(buf))
    return length_1
}
[export, sideeffects]
def M_FileLength(var handle_1 : _IO_FILE?) : int64 {
    var savedpos : int64
    var length_2 : int64
    savedpos = c2da_std_ftell(unsafe(reinterpret<uint64>(handle_1)))
    c2da_std_fseek(unsafe(reinterpret<uint64>(handle_1)), 0l, 2)
    length_2 = c2da_std_ftell(unsafe(reinterpret<uint64>(handle_1)))
    c2da_std_fseek(unsafe(reinterpret<uint64>(handle_1)), savedpos, 0)
    return length_2
}
[export, sideeffects]
def M_MakeDirectory(var path : int8?) {
    c2da_std_mkdir(unsafe(reinterpret<uint64>(path)), 0x1edu)
    return
}
[export, sideeffects]
def M_TempFile(var s : int8?) : int8? {
    return unsafe(reinterpret<int8?>(M_StringJoin(unsafe(reinterpret<int8 const?>(unsafe(addr<int8?>(c2da_str_m_misc_3[0])))), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_m_misc_4[0]))))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(s))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(null)))])))
}
[export, sideeffects]
def M_StringJoin(var s_0 : int8 const?; c2da_va_args : array<C2daVaArg>) : int8? {
    var result_0 : int8?
    var v : int8 const?
    var args : C2daVaCursor = C2daVaCursor(index = 0)
    var result_len : uint64 = c2da_std_strlen(unsafe(reinterpret<uint64>(s_0))) + 1ul
    args.index = 0
    while (true) {
        var c2da_va_item : C2daVaArg = c2da_va_args[args.index]
        args.index++
        v = unsafe(reinterpret<int8 const?>(unsafe(reinterpret<int8 const?>(c2da_va_item.raw))))
        if (v == null) {
            break
        }
        result_len = result_len + c2da_std_strlen(unsafe(reinterpret<uint64>(v)))
    }
    args.index = -1
    result_0 = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(unsafe(reinterpret<uint8?>(c2da_rt_malloc(result_len)))))))
    if (result_0 == null) {
        I_Error(unsafe(addr<int8?>(c2da_str_m_misc_5[0])), [])
        return unsafe(reinterpret<int8?>(null))
    }
    M_StringCopy(result_0, s_0, result_len)
    args.index = 0
    while (true) {
        var c2da_va_item_0 : C2daVaArg = c2da_va_args[args.index]
        args.index++
        v = unsafe(reinterpret<int8 const?>(unsafe(reinterpret<int8 const?>(c2da_va_item_0.raw))))
        if (v == null) {
            break
        }
        M_StringConcat(result_0, v, result_len)
    }
    args.index = -1
    return unsafe(reinterpret<int8?>(result_0))
}
[export, sideeffects]
def M_StringConcat(var dest : int8?; var src : int8 const?; var dest_size : uint64) : uint {
    var offset : uint64 = c2da_std_strlen(unsafe(reinterpret<uint64>(dest)))
    if (offset > dest_size) {
        offset = dest_size
    }
    return M_StringCopy(unsafe(reinterpret<int8?>(unsafe(dest + int64(offset)))), src, dest_size - offset)
}
[export, sideeffects]
def M_StringCopy(var dest_0 : int8?; var src_0 : int8 const?; var dest_size_0 : uint64) : uint {
    var len : uint64
    if (dest_size_0 >= 1ul) {
        unsafe(dest_0[int(dest_size_0 - 1ul)]) = int8(0)
        unsafe(reinterpret<int8?>(c2da_std_strncpy(unsafe(reinterpret<uint64>(dest_0)), unsafe(reinterpret<uint64>(src_0)), dest_size_0 - 1ul)))
    } else {
        return 0u
    }
    len = c2da_std_strlen(unsafe(reinterpret<uint64>(dest_0)))
    return uint(int(unsafe(src_0[int(len)])) == 0 ? 1 : 0)
}
[export, sideeffects]
def M_FileExists(var filename : int8?) : uint {
    var fstream : _IO_FILE? = unsafe(reinterpret<_IO_FILE?>(unsafe(reinterpret<_IO_FILE?>(c2da_std_fopen(unsafe(reinterpret<int8 const?>(filename)), unsafe(addr<int8 const?>(c2da_str_m_misc_6[0])))))))
    if (fstream != null) {
        c2da_std_fclose(unsafe(reinterpret<uint64>(fstream)))
        return 1u
    } else {
        return uint(*unsafe(reinterpret<int?>(c2da_std_errno_location())) == 21 ? 1 : 0)
    }
}
[export, sideeffects]
def M_StrToInt(var str : int8 const?; var result_1 : int?) : uint {
    return uint(c2da_std_sscanf(unsafe(reinterpret<uint64>(str)), unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_m_misc_7[0])))), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(result_1)))]) == 1 || c2da_std_sscanf(unsafe(reinterpret<uint64>(str)), unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_m_misc_8[0])))), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(result_1)))]) == 1 || c2da_std_sscanf(unsafe(reinterpret<uint64>(str)), unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_m_misc_9[0])))), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(result_1)))]) == 1 || c2da_std_sscanf(unsafe(reinterpret<uint64>(str)), unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_m_misc_10[0])))), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(result_1)))]) == 1 ? 1 : 0)
}
[export, sideeffects]
def M_ExtractFileBase(var path_0 : int8?; var dest_1 : int8?) {
    var src_1 : int8?
    var filename_0 : int8?
    var length_3 : int
    src_1 = unsafe(reinterpret<int8?>(unsafe(unsafe(path_0 + int64(c2da_std_strlen(unsafe(reinterpret<uint64>(path_0))))) + -1)))
    while (src_1 != path_0 && int(*unsafe(src_1 + -1)) != 47) {
        unsafe {  // nolint:STYLE025
            src_1 -= 1
        }
    }
    filename_0 = unsafe(reinterpret<int8?>(src_1))
    length_3 = 0
    unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(dest_1)))), 0u8, 8ul)))
    var c2da_src_1_addr : uint64 = unsafe(reinterpret<uint64>(src_1))
    while (int(*unsafe(reinterpret<int8?>(c2da_src_1_addr))) != 0 && int(*unsafe(reinterpret<int8?>(c2da_src_1_addr))) != 46) {
        if (length_3 >= 8) {
            c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_m_misc_11[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(filename_0))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(dest_1)))])
            break
        }
        let c2da_postinc : int = length_3
        length_3++
        unsafe(dest_1[c2da_postinc]) = int8(c2da_std_toupper(int(*unsafe(reinterpret<int8?>(c2da_src_1_addr)))))
        c2da_src_1_addr++
    }
    return
}
[export, sideeffects]
def M_ForceUppercase(var text : int8?) {
    var p : int8? = unsafe(reinterpret<int8?>(text))
    while (int(*p) != 0) {
        *p = int8(c2da_std_toupper(int(*p)))
        unsafe {  // nolint:STYLE025
            p += 1
        }
    }
    return
}
[export, sideeffects]
def M_StrCaseStr(var haystack : int8?; var needle : int8?) : int8? {
    var haystack_len : uint
    var needle_len : uint
    var len_0 : uint
    var i : uint
    haystack_len = uint(c2da_std_strlen(unsafe(reinterpret<uint64>(haystack))))
    needle_len = uint(c2da_std_strlen(unsafe(reinterpret<uint64>(needle))))
    if (haystack_len < needle_len) {
        return unsafe(reinterpret<int8?>(null))
    }
    len_0 = haystack_len - needle_len
    i = 0u
    while (i <= len_0) {
        if (c2da_std_strncasecmp(unsafe(reinterpret<uint64>(unsafe(haystack + int64(i)))), unsafe(reinterpret<uint64>(needle)), uint64(needle_len)) == 0) {
            return unsafe(reinterpret<int8?>(unsafe(haystack + int64(i))))
        }
        i++
    }
    return unsafe(reinterpret<int8?>(null))
}
[export, sideeffects]
def M_StringDuplicate(var orig : int8 const?) : int8? {
    var result_2 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(c2da_std_strdup(unsafe(reinterpret<uint64>(orig)))))))
    if (result_2 == null) {
        I_Error(unsafe(addr<int8?>(c2da_str_m_misc_12[0])), [C2daVaArg(tag = 1, i64 = int64(c2da_std_strlen(unsafe(reinterpret<uint64>(orig)))), f64 = 0.0lf, raw = 0x0)])
    }
    return unsafe(reinterpret<int8?>(result_2))
}
[export, sideeffects]
def M_StringReplace(var haystack_0 : int8 const?; var needle_0 : int8 const?; var replacement : int8 const?) : int8? {
    var result_3 : int8?
    var dst : int8?
    var p_0 : int8 const?
    var needle_len_0 : uint64
    var result_len_0 : uint64
    var dst_len : uint64
    needle_len_0 = c2da_std_strlen(unsafe(reinterpret<uint64>(needle_0)))
    result_len_0 = c2da_std_strlen(unsafe(reinterpret<uint64>(haystack_0))) + 1ul
    p_0 = unsafe(reinterpret<int8 const?>(haystack_0))
    while (true) {
        p_0 = unsafe(reinterpret<int8 const?>(unsafe(reinterpret<int8 const?>(c2da_std_strstr(unsafe(reinterpret<uint64>(p_0)), unsafe(reinterpret<uint64>(needle_0)))))))
        if (p_0 == null) {
            break
        }
        unsafe {  // nolint:STYLE025
            p_0 += int64(needle_len_0)
        }
        result_len_0 = result_len_0 + (c2da_std_strlen(unsafe(reinterpret<uint64>(replacement))) - needle_len_0)
    }
    result_3 = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(unsafe(reinterpret<uint8?>(c2da_rt_malloc(result_len_0)))))))
    if (result_3 == null) {
        I_Error(unsafe(addr<int8?>(c2da_str_m_misc_13[0])), [])
        return unsafe(reinterpret<int8?>(null))
    }
    dst = unsafe(reinterpret<int8?>(result_3))
    dst_len = result_len_0
    p_0 = unsafe(reinterpret<int8 const?>(haystack_0))
    while (int(*p_0) != 0) {
        if (c2da_std_strncmp(unsafe(reinterpret<uint64>(p_0)), unsafe(reinterpret<uint64>(needle_0)), needle_len_0) == 0) {
            M_StringCopy(dst, replacement, dst_len)
            unsafe {  // nolint:STYLE025
                p_0 += int64(needle_len_0)
            }
            dst = unsafe(dst + int64(c2da_std_strlen(unsafe(reinterpret<uint64>(replacement)))))
            dst_len = dst_len - c2da_std_strlen(unsafe(reinterpret<uint64>(replacement)))
        } else {
            *dst = int8(*p_0)  // nolint:PERF020
            unsafe {  // nolint:STYLE025
                dst += 1
            }
            dst_len--
            unsafe {  // nolint:STYLE025
                p_0 += 1
            }
        }
    }
    *dst = int8(0)
    return unsafe(reinterpret<int8?>(result_3))
}
[export, sideeffects]
def M_StringStartsWith(var s_1 : int8 const?; var prefix : int8 const?) : uint {
    return uint(c2da_std_strlen(unsafe(reinterpret<uint64>(s_1))) > c2da_std_strlen(unsafe(reinterpret<uint64>(prefix))) && c2da_std_strncmp(unsafe(reinterpret<uint64>(s_1)), unsafe(reinterpret<uint64>(prefix)), c2da_std_strlen(unsafe(reinterpret<uint64>(prefix)))) == 0 ? 1 : 0)
}
[export, sideeffects]
def M_StringEndsWith(var s_2 : int8 const?; var suffix : int8 const?) : uint {
    return uint(c2da_std_strlen(unsafe(reinterpret<uint64>(s_2))) >= c2da_std_strlen(unsafe(reinterpret<uint64>(suffix))) && c2da_std_strcmp(unsafe(reinterpret<uint64>(unsafe(unsafe(s_2 + int64(c2da_std_strlen(unsafe(reinterpret<uint64>(s_2))))) + -int64(c2da_std_strlen(unsafe(reinterpret<uint64>(suffix))))))), unsafe(reinterpret<uint64>(suffix))) == 0 ? 1 : 0)
}
[export, sideeffects]
def M_vsnprintf(var buf_0 : int8?; var buf_len : uint64; var s_3 : int8 const?; var args_0 : C2daVaCursor; c2da_va_args : array<C2daVaArg>) : int {
    var result_4 : int
    if (buf_len < 1ul) {
        return 0
    }
    result_4 = c2da_std_vsnprintf(unsafe(reinterpret<uint64>(buf_0)), buf_len, s_3, args_0, c2da_va_args)
    if (result_4 < 0 || uint64(result_4) >= buf_len) {
        unsafe(buf_0[int(buf_len - 1ul)]) = int8(0)
        result_4 = int(buf_len - 1ul)
    }
    return result_4
}
[export, sideeffects]
def M_snprintf(var buf_1 : int8?; var buf_len_0 : uint64; var s_4 : int8 const?; c2da_va_args : array<C2daVaArg>) : int {
    var args_1 : C2daVaCursor = C2daVaCursor(index = 0)
    var result_5 : int
    args_1.index = 0
    result_5 = M_vsnprintf(buf_1, buf_len_0, s_4, args_1, c2da_va_args)
    args_1.index = -1
    return result_5
}
[sideeffects]
def private c2da_layout_proofs_0() {
    static_assert(typeinfo sizeof(type<c2da___va_list_tag>) == 24, "C layout of c2da___va_list_tag: sizeof")
    static_assert(typeinfo alignof(type<c2da___va_list_tag>) == 8, "C layout of c2da___va_list_tag: alignof")
    static_assert(typeinfo offsetof<gp_offset>(type<c2da___va_list_tag>) == 0, "C layout of c2da___va_list_tag: offsetof gp_offset")
    static_assert(typeinfo offsetof<fp_offset>(type<c2da___va_list_tag>) == 4, "C layout of c2da___va_list_tag: offsetof fp_offset")
    static_assert(typeinfo offsetof<overflow_arg_area>(type<c2da___va_list_tag>) == 8, "C layout of c2da___va_list_tag: offsetof overflow_arg_area")
    static_assert(typeinfo offsetof<reg_save_area>(type<c2da___va_list_tag>) == 16, "C layout of c2da___va_list_tag: offsetof reg_save_area")
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
}
