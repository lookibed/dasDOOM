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
def M_WriteFile(var name : int; var source : int; var length_0 : int) : uint {
    var handle : int
    var count : int
    handle = c2da_lin_fopen(name, 358576)
    if (handle == 0) {
        return 0u
    }
    count = int(c2da_lin_fwrite(source, 1ul, uint64(length_0), uint64(handle)))
    c2da_std_fclose(uint64(handle))
    if (count < length_0) {
        return 0u
    }
    return 1u
}
[export, sideeffects]
def M_ReadFile(var name_0 : int; var buffer : int) : int {
    var handle_0 : int
    var count_0 : int
    var length_1 : int
    var buf : int
    handle_0 = c2da_lin_fopen(name_0, 358579)
    if (handle_0 == 0) {
        I_Error(358582, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(name_0))])
    }
    length_1 = int(M_FileLength(handle_0))
    buf = Z_Malloc(length_1, 1, 0)
    count_0 = int(c2da_lin_fread(buf, 1ul, uint64(length_1), uint64(handle_0)))
    c2da_std_fclose(uint64(handle_0))
    if (count_0 < length_1) {
        I_Error(358582, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(name_0))])
    }
    let c2da_fresh0 : uint = uint(buf)
    c2da_mem[buffer] = uint8(c2da_fresh0)
    c2da_mem[buffer + 1] = uint8(c2da_fresh0 >> 0x8)
    c2da_mem[buffer + 2] = uint8(c2da_fresh0 >> 0x10)
    c2da_mem[buffer + 3] = uint8(c2da_fresh0 >> 0x18)
    c2da_mem[buffer + 4] = 0u8
    c2da_mem[buffer + 5] = 0u8
    c2da_mem[buffer + 6] = 0u8
    c2da_mem[buffer + 7] = 0u8
    return length_1
}
[export, sideeffects]
def M_FileLength(var handle_1 : int) : int64 {
    var savedpos : int64
    var length_2 : int64
    savedpos = c2da_std_ftell(uint64(handle_1))
    c2da_std_fseek(uint64(handle_1), 0l, 2)
    length_2 = c2da_std_ftell(uint64(handle_1))
    c2da_std_fseek(uint64(handle_1), savedpos, 0)
    return length_2
}
[export, sideeffects]
def M_MakeDirectory(var path : int) {
    c2da_lin_mkdir(path, 0x1edul)
    return
}
[export, sideeffects]
def M_TempFile(var s : int) : int {
    return M_StringJoin(358604, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 358609ul), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(s)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 0ul)])
}
[export, sideeffects]
def M_StringJoin(var s_0 : int; c2da_va_args : array<C2daVaArg>) : int {
    var result_0 : int
    var v : int
    var args : C2daVaCursor = C2daVaCursor(index = 0)
    var result_len : uint64 = uint64(c2da_lin_strlen(s_0) + 1ul)
    args.index = 0
    while (true) {
        var c2da_va_item : C2daVaArg = c2da_va_args[args.index]
        args.index++
        v = int(c2da_va_item.raw)
        if (v == 0) {
            break
        }
        result_len = result_len + c2da_lin_strlen(v)
    }
    args.index = -1
    result_0 = c2da_lin_malloc(result_len)
    if (result_0 == 0) {
        I_Error(358611, [])
        return 0
    }
    M_StringCopy(result_0, s_0, result_len)
    args.index = 0
    while (true) {
        var c2da_va_item_0 : C2daVaArg = c2da_va_args[args.index]
        args.index++
        v = int(c2da_va_item_0.raw)
        if (v == 0) {
            break
        }
        M_StringConcat(result_0, v, result_len)
    }
    args.index = -1
    return result_0
}
[export, sideeffects]
def M_StringConcat(var dest : int; var src : int; var dest_size : uint64) : uint {
    var offset : uint64 = uint64(c2da_lin_strlen(dest))
    if (offset > dest_size) {
        offset = dest_size
    }
    return M_StringCopy(dest + int(offset), src, dest_size - offset)
}
[export, sideeffects]
def M_StringCopy(var dest_0 : int; var src_0 : int; var dest_size_0 : uint64) : uint {
    var len : uint64
    if (dest_size_0 >= 1ul) {
        let c2da_fresh1 : int8 = int8(0)
        c2da_mem[dest_0 + int(dest_size_0 - 1ul)] = uint8(c2da_fresh1)
        c2da_lin_strncpy(dest_0, src_0, dest_size_0 - 1ul)
    } else {
        return 0u
    }
    len = uint64(c2da_lin_strlen(dest_0))
    return uint(int(int8(c2da_mem[src_0 + int(len)])) == 0 ? 1 : 0)
}
[export, sideeffects]
def M_FileExists(var filename : int) : uint {
    var fstream : int = c2da_lin_fopen(filename, 358656)
    if (fstream != 0) {
        c2da_std_fclose(uint64(fstream))
        return 1u
    } else {
        return uint(int(uint(c2da_mem[8]) | uint(c2da_mem[9]) << 0x8 | uint(c2da_mem[10]) << 0x10 | uint(c2da_mem[11]) << 0x18) == 21 ? 1 : 0)
    }
}
[export, sideeffects]
def M_StrToInt(var str : int; var result_1 : int) : uint {
    return uint(c2da_lin_sscanf(str, 358658, result_1, 0, 0, 0) == 1 || c2da_lin_sscanf(str, 358664, result_1, 0, 0, 0) == 1 || c2da_lin_sscanf(str, 358670, result_1, 0, 0, 0) == 1 || c2da_lin_sscanf(str, 358675, result_1, 0, 0, 0) == 1 ? 1 : 0)
}
[export, sideeffects]
def M_ExtractFileBase(var path_0 : int; var dest_1 : int) {
    var src_1 : int
    var filename_0 : int
    var length_3 : int
    src_1 = path_0 + int(c2da_lin_strlen(path_0)) - 1
    while (src_1 != path_0 && int(int8(c2da_mem[src_1 - 1])) != 47) {
        src_1--
    }
    filename_0 = src_1
    length_3 = 0
    c2da_lin_memset(dest_1, 0, 8ul)
    while (int(int8(c2da_mem[src_1])) != 0 && int(int8(c2da_mem[src_1])) != 46) {
        if (length_3 >= 8) {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 358679, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(filename_0)), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(dest_1))])
            break
        }
        let c2da_postinc : int = length_3
        length_3++
        let c2da_fresh2 : int = src_1
        src_1++
        let c2da_fresh3 : int8 = int8(c2da_std_toupper(int(int8(c2da_mem[c2da_fresh2]))))
        c2da_mem[dest_1 + c2da_postinc] = uint8(c2da_fresh3)
    }
    return
}
[export, sideeffects]
def M_ForceUppercase(var text : int) {
    var p : int = text
    while (int(int8(c2da_mem[p])) != 0) {
        let c2da_fresh4 : int8 = int8(c2da_std_toupper(int(int8(c2da_mem[p]))))
        c2da_mem[p] = uint8(c2da_fresh4)
        p++
    }
    return
}
[export, sideeffects]
def M_StrCaseStr(var haystack : int; var needle : int) : int {
    var haystack_len : uint
    var needle_len : uint
    var len_0 : uint
    var i : uint
    haystack_len = uint(c2da_lin_strlen(haystack))
    needle_len = uint(c2da_lin_strlen(needle))
    if (haystack_len < needle_len) {
        return 0
    }
    len_0 = haystack_len - needle_len
    i = 0u
    while (i <= len_0) {
        if (c2da_lin_strncasecmp(haystack + int(i), needle, uint64(needle_len)) == 0) {
            return haystack + int(i)
        }
        i++
    }
    return 0
}
[export, sideeffects]
def M_StringDuplicate(var orig : int) : int {
    var result_2 : int = c2da_lin_strdup(orig)
    if (result_2 == 0) {
        I_Error(358725, [C2daVaArg(tag = 1, i64 = int64(c2da_lin_strlen(orig)), f64 = 0.0lf, raw = 0x0)])
    }
    return result_2
}
[export, sideeffects]
def M_StringReplace(var haystack_0 : int; var needle_0 : int; var replacement : int) : int {
    var result_3 : int
    var dst : int
    var p_0 : int
    var needle_len_0 : uint64
    var result_len_0 : uint64
    var dst_len : uint64
    needle_len_0 = c2da_lin_strlen(needle_0)
    result_len_0 = uint64(c2da_lin_strlen(haystack_0) + 1ul)
    p_0 = haystack_0
    while (true) {
        p_0 = c2da_lin_strstr(p_0, needle_0)
        if (p_0 == 0) {
            break
        }
        p_0 += int(needle_len_0)
        result_len_0 = result_len_0 + (c2da_lin_strlen(replacement) - needle_len_0)
    }
    result_3 = c2da_lin_malloc(result_len_0)
    if (result_3 == 0) {
        I_Error(358765, [])
        return 0
    }
    dst = result_3
    dst_len = result_len_0
    p_0 = haystack_0
    while (int(int8(c2da_mem[p_0])) != 0) {
        if (c2da_lin_strncmp(p_0, needle_0, needle_len_0) == 0) {
            M_StringCopy(dst, replacement, dst_len)
            p_0 += int(needle_len_0)
            dst = dst + int(c2da_lin_strlen(replacement))
            dst_len = dst_len - c2da_lin_strlen(replacement)
        } else {
            let c2da_fresh5 : int8 = int8(c2da_mem[p_0])
            c2da_mem[dst] = uint8(c2da_fresh5)
            dst++
            dst_len--
            p_0++
        }
    }
    let c2da_fresh6 : int8 = int8(0)
    c2da_mem[dst] = uint8(c2da_fresh6)
    return result_3
}
[export, sideeffects]
def M_StringStartsWith(var s_1 : int; var prefix : int) : uint {
    return uint(c2da_lin_strlen(s_1) > c2da_lin_strlen(prefix) && c2da_lin_strncmp(s_1, prefix, uint64(c2da_lin_strlen(prefix))) == 0 ? 1 : 0)
}
[export, sideeffects]
def M_StringEndsWith(var s_2 : int; var suffix : int) : uint {
    return uint(c2da_lin_strlen(s_2) >= c2da_lin_strlen(suffix) && c2da_lin_strcmp(s_2 + int(c2da_lin_strlen(s_2)) - int(c2da_lin_strlen(suffix)), suffix) == 0 ? 1 : 0)
}
[export, sideeffects]
def M_vsnprintf(var buf_0 : int; var buf_len : uint64; var s_3 : int; var args_0 : C2daVaCursor; c2da_va_args : array<C2daVaArg>) : int {
    var result_4 : int
    if (buf_len < 1ul) {
        return 0
    }
    result_4 = c2da_lin_vsnprintf(buf_0, buf_len, s_3, args_0, c2da_va_args)
    if (result_4 < 0 || uint64(result_4) >= buf_len) {
        let c2da_fresh7 : int8 = int8(0)
        c2da_mem[buf_0 + int(buf_len - 1ul)] = uint8(c2da_fresh7)
        result_4 = int(buf_len - 1ul)
    }
    return result_4
}
[export, sideeffects]
def M_snprintf(var buf_1 : int; var buf_len_0 : uint64; var s_4 : int; c2da_va_args : array<C2daVaArg>) : int {
    var args_1 : C2daVaCursor = C2daVaCursor(index = 0)
    var result_5 : int
    args_1.index = 0
    result_5 = M_vsnprintf(buf_1, buf_len_0, s_4, args_1, c2da_va_args)
    args_1.index = -1
    return result_5
}

// This unit's static data, at heap offset 358576.
let private c2da_lin_static_m_misc_seg = fixed_array<int>(358576, 235)
let private c2da_lin_static_m_misc = fixed_array<uint64>(0x6f43006272006277ul, 0x722074276e646c75ul, 0x656c696620646165ul, 0x706d742f00732520ul, 0x7274535f4d002f00ul, 0x3a6e696f4a676e69ul, 0x2064656c69614620ul, 0x636f6c6c61206f74ul, 0x2077656e20657461ul, 0x2e676e69727473ul, 0x78257830200072ul, 0x3020007825583020ul, 0x5700642520006f25ul, 0x203a676e696e7261ul, 0x657461636e757254ul, 0x6c20277325272064ul, 0x656d616e20706d75ul, 0x382e2527206f7420ul, 0x696146000a2e2773ul, 0x64206f742064656cul, 0x65746163696c7075ul, 0x20676e6972747320ul, 0x206874676e656c28ul, 0x535f4d000a296925ul, 0x706552676e697274ul, 0x6146203a6563616cul, 0x206f742064656c69ul, 0x657461636f6c6c61ul, 0x7274732077656e20ul, 0x676e69ul)

[init]
def private c2da_lin_init_static_m_misc() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_m_misc_seg[s * 2]
        for (k in range(c2da_lin_static_m_misc_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_m_misc[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
