var private ZenityErrorBox__errorboxpath_size : uint64 = 0ul

var private I_GetMemoryValue__firsttime : uint = 1u

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
def I_ZoneBase(var size : int) : int {
    var zonemem : int
    var min_ram : int
    var default_ram : int
    var p : int = M_CheckParmWithArgs(345722, 1)
    if (p > 0) {
        default_ram = c2da_lin_atoi(int(uint(c2da_mem[myargv + (p + 1) * 8]) | uint(c2da_mem[myargv + (p + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p + 1) * 8 + 3]) << 0x18))
        min_ram = default_ram
    } else {
        default_ram = 6
        min_ram = 6
    }
    zonemem = AutoAllocMemory(size, default_ram, min_ram)
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 345726, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(zonemem)), C2daVaArg(tag = 1, i64 = int64(int(uint(c2da_mem[size]) | uint(c2da_mem[size + 1]) << 0x8 | uint(c2da_mem[size + 2]) << 0x10 | uint(c2da_mem[size + 3]) << 0x18)), f64 = 0.0lf, raw = 0x0)])
    return zonemem
}
[sideeffects]
def private AutoAllocMemory(var size_0 : int; var default_ram_0 : int; var min_ram_0 : int) : int {
    var zonemem_0 : int = 0
    while (zonemem_0 == 0) {
        if (default_ram_0 < min_ram_0) {
            I_Error(345766, [C2daVaArg(tag = 1, i64 = int64(default_ram_0), f64 = 0.0lf, raw = 0x0)])
        }
        let c2da_fresh0 : int = default_ram_0 * 1024 * 1024
        let c2da_fresh1 : uint = uint(c2da_fresh0)
        c2da_mem[size_0] = uint8(c2da_fresh1)
        c2da_mem[size_0 + 1] = uint8(c2da_fresh1 >> 0x8)
        c2da_mem[size_0 + 2] = uint8(c2da_fresh1 >> 0x10)
        c2da_mem[size_0 + 3] = uint8(c2da_fresh1 >> 0x18)
        zonemem_0 = c2da_lin_malloc(uint64(int(uint(c2da_mem[size_0]) | uint(c2da_mem[size_0 + 1]) << 0x8 | uint(c2da_mem[size_0 + 2]) << 0x10 | uint(c2da_mem[size_0 + 3]) << 0x18)))
        if (zonemem_0 == 0) {
            default_ram_0--
        }
    }
    return zonemem_0
}
[export, sideeffects]
def I_Error(var error : int; c2da_va_args : array<C2daVaArg>) {
    let c2da_saved_sp : int = c2da_lin_sp
    I_Error_c2da_frame(error, c2da_va_args, c2da_lin_enter(512))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private ZenityErrorBox(var message : int) : int {
    var result_0 : int
    var escaped_message : int
    var errorboxpath : int
    if (ZenityAvailable() == 0) {
        return 0
    }
    escaped_message = EscapeShellString(message)
    ZenityErrorBox__errorboxpath_size = uint64(c2da_lin_strlen(345864) + c2da_lin_strlen(escaped_message) + 19ul)
    errorboxpath = c2da_lin_malloc(ZenityErrorBox__errorboxpath_size)
    M_snprintf(errorboxpath, ZenityErrorBox__errorboxpath_size, 345880, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = 345864ul), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(escaped_message))])
    result_0 = c2da_lin_system(errorboxpath)
    c2da_lin_free(errorboxpath)
    c2da_lin_free(escaped_message)
    return result_0
}
[sideeffects]
def private EscapeShellString(var string_0 : int) : int {
    var result_1 : int
    var r : int
    var s : int
    result_1 = c2da_lin_malloc(uint64(c2da_lin_strlen(string_0) * 2ul + 3ul))
    r = result_1
    let c2da_fresh2 : int8 = int8(34)
    c2da_mem[r] = uint8(c2da_fresh2)
    r++
    s = string_0
    while (int(int8(c2da_mem[s])) != 0) {
        if (c2da_lin_strchr(345901, int(int8(c2da_mem[s]))) != 0) {
            let c2da_fresh3 : int8 = int8(92)
            c2da_mem[r] = uint8(c2da_fresh3)
            r++
        }
        let c2da_fresh4 : int8 = int8(c2da_mem[s])
        c2da_mem[r] = uint8(c2da_fresh4)
        r++
        s++
    }
    let c2da_fresh5 : int8 = int8(34)
    c2da_mem[r] = uint8(c2da_fresh5)
    r++
    let c2da_fresh6 : int8 = int8(0)
    c2da_mem[r] = uint8(c2da_fresh6)
    return result_1
}
[sideeffects]
def private ZenityAvailable() : int {
    return c2da_lin_system(345906) == 0 ? 1 : 0
}
[export, sideeffects]
def I_ConsoleStdout() : uint {
    return 0u
}
var private exit_funcs : int = 0

var private already_quitting : uint = 0u

[export, sideeffects]
def I_Quit() {
    var entry_0 : int = exit_funcs
    while (entry_0 != 0) {
        invoke(c2da_fn_table0[int(uint(c2da_mem[entry_0]) | uint(c2da_mem[entry_0 + 1]) << 0x8 | uint(c2da_mem[entry_0 + 2]) << 0x10 | uint(c2da_mem[entry_0 + 3]) << 0x18)])
        entry_0 = int(uint(c2da_mem[entry_0 + 16]) | uint(c2da_mem[entry_0 + 17]) << 0x8 | uint(c2da_mem[entry_0 + 18]) << 0x10 | uint(c2da_mem[entry_0 + 19]) << 0x18)
    }
    return
}
[export, sideeffects]
def I_Tactile(var on : int; var off : int; var total : int) {
    return
}
[export, sideeffects]
def I_GetMemoryValue(var offset : uint; var value : int; var size_1 : int) : uint {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : uint = I_GetMemoryValue_c2da_frame(offset, value, size_1, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
var private dos_mem_dump : int = 345664

[export, sideeffects]
def I_AtExit(var func : atexit_func_t; var run_on_error : uint) {
    var entry_1 : int = c2da_lin_malloc(24ul)
    let c2da_fresh15 : uint = uint(func)
    c2da_mem[entry_1] = uint8(c2da_fresh15)
    c2da_mem[entry_1 + 1] = uint8(c2da_fresh15 >> 0x8)
    c2da_mem[entry_1 + 2] = uint8(c2da_fresh15 >> 0x10)
    c2da_mem[entry_1 + 3] = uint8(c2da_fresh15 >> 0x18)
    c2da_mem[entry_1 + 4] = 0u8
    c2da_mem[entry_1 + 5] = 0u8
    c2da_mem[entry_1 + 6] = 0u8
    c2da_mem[entry_1 + 7] = 0u8
    let c2da_fresh16 : uint = run_on_error
    c2da_mem[entry_1 + 8] = uint8(c2da_fresh16)
    c2da_mem[entry_1 + 9] = uint8(c2da_fresh16 >> 0x8)
    c2da_mem[entry_1 + 10] = uint8(c2da_fresh16 >> 0x10)
    c2da_mem[entry_1 + 11] = uint8(c2da_fresh16 >> 0x18)
    let c2da_fresh17 : uint = uint(exit_funcs)
    c2da_mem[entry_1 + 16] = uint8(c2da_fresh17)
    c2da_mem[entry_1 + 17] = uint8(c2da_fresh17 >> 0x8)
    c2da_mem[entry_1 + 18] = uint8(c2da_fresh17 >> 0x10)
    c2da_mem[entry_1 + 19] = uint8(c2da_fresh17 >> 0x18)
    c2da_mem[entry_1 + 20] = 0u8
    c2da_mem[entry_1 + 21] = 0u8
    c2da_mem[entry_1 + 22] = 0u8
    c2da_mem[entry_1 + 23] = 0u8
    exit_funcs = entry_1
    return
}
[export, sideeffects]
def I_PrintStartupBanner(var gamedescription : int) {
    I_PrintDivider()
    I_PrintBanner(gamedescription)
    I_PrintDivider()
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 345973, [])
    I_PrintDivider()
    return
}
[export, sideeffects]
def I_PrintDivider() {
    for (i_0 in range(0, 75)) {
        c2da_lin_fputc(61, uint64(int(c2da_std_stderr())))
    }
    c2da_lin_fputc(10, uint64(int(c2da_std_stderr())))
    return
}
[export, sideeffects]
def I_PrintBanner(var msg : int) {
    var spaces : int = int(35ul - c2da_lin_strlen(msg) / 2ul)
    for (i_1 in range(0, spaces)) {
        c2da_lin_fputc(32, uint64(int(c2da_std_stderr())))
    }
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 346252, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(msg))])
    return
}
[sideeffects]
def private I_Error_c2da_frame(var error : int; c2da_va_args : array<C2daVaArg>; c2da_fp : int) {
    var argptr : C2daVaCursor = C2daVaCursor(index = 0)
    var entry : int
    var exit_gui_popup : uint
    if (already_quitting != 0x0) {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 345808, [])
    } else {
        already_quitting = 1u
    }
    argptr.index = 0
    c2da_lin_vprintf(uint64(int(c2da_std_stderr())), error, argptr, c2da_va_args)
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 345854, [])
    argptr.index = -1
    c2da_std_fflush(uint64(int(c2da_std_stderr())))
    argptr.index = 0
    c2da_lin_memset(c2da_fp, 0, 512ul)
    M_vsnprintf(c2da_fp, 512ul, error, argptr, c2da_va_args)
    argptr.index = -1
    entry = exit_funcs
    while (entry != 0) {
        if ((uint(c2da_mem[entry + 8]) | uint(c2da_mem[entry + 9]) << 0x8 | uint(c2da_mem[entry + 10]) << 0x10 | uint(c2da_mem[entry + 11]) << 0x18) != 0x0) {
            invoke(c2da_fn_table0[int(uint(c2da_mem[entry]) | uint(c2da_mem[entry + 1]) << 0x8 | uint(c2da_mem[entry + 2]) << 0x10 | uint(c2da_mem[entry + 3]) << 0x18)])
        }
        entry = int(uint(c2da_mem[entry + 16]) | uint(c2da_mem[entry + 17]) << 0x8 | uint(c2da_mem[entry + 18]) << 0x10 | uint(c2da_mem[entry + 19]) << 0x18)
    }
    exit_gui_popup = M_ParmExists(345857) == 0 ? 1u : 0u
    if (exit_gui_popup != 0x0 && I_ConsoleStdout() == 0) {
        ZenityErrorBox(c2da_fp)
    }
    c2da_std_exit(-1)
    return
}
[sideeffects]
def private I_GetMemoryValue_c2da_frame(var offset : uint; var value : int; var size_1 : int; c2da_fp : int) : uint {
    var p_0 : int
    var i : int
    if (I_GetMemoryValue__firsttime != 0x0) {
        I_GetMemoryValue__firsttime = 0u
        i = 0
        p_0 = M_CheckParmWithArgs(345945, 1)
        if (p_0 > 0) {
            if (c2da_lin_strcasecmp(int(uint(c2da_mem[myargv + (p_0 + 1) * 8]) | uint(c2da_mem[myargv + (p_0 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_0 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_0 + 1) * 8 + 3]) << 0x18), 345953) == 0) {
                dos_mem_dump = 345664
            }
            if (c2da_lin_strcasecmp(int(uint(c2da_mem[myargv + (p_0 + 1) * 8]) | uint(c2da_mem[myargv + (p_0 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_0 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_0 + 1) * 8 + 3]) << 0x18), 345960) == 0) {
                dos_mem_dump = 345680
            } elif (c2da_lin_strcasecmp(int(uint(c2da_mem[myargv + (p_0 + 1) * 8]) | uint(c2da_mem[myargv + (p_0 + 1) * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + (p_0 + 1) * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + (p_0 + 1) * 8 + 3]) << 0x18), 345966) == 0) {
                dos_mem_dump = 345696
            } else {
                i = 0
                while (i < 10) {
                    p_0++
                    var c2da_fresh8 : int = 1
                    if (!(p_0 >= myargc)) {
                        let c2da_fresh7 : int = int(uint(c2da_mem[myargv + p_0 * 8]) | uint(c2da_mem[myargv + p_0 * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + p_0 * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + p_0 * 8 + 3]) << 0x18) + 0
                        if (!(int(int8(c2da_mem[c2da_fresh7])) == 45)) {
                            c2da_fresh8 = 0
                        }
                    }
                    if (c2da_fresh8 != 0) {
                        break
                    }
                    M_StrToInt(int(uint(c2da_mem[myargv + p_0 * 8]) | uint(c2da_mem[myargv + p_0 * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + p_0 * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + p_0 * 8 + 3]) << 0x18), c2da_fp)
                    let c2da_postinc : int = i
                    i++
                    let c2da_fresh9 : uint8 = uint8(int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18))
                    c2da_mem[345712 + c2da_postinc] = c2da_fresh9
                    i++
                }
                dos_mem_dump = 345712
            }
        }
    }
    if (size_1 == 1) {
        let c2da_fresh10 : uint8 = c2da_mem[dos_mem_dump + int(offset)]
        c2da_mem[value] = c2da_fresh10
        return 1u
    } elif (size_1 == 2) {
        let c2da_fresh11 : uint16 = uint16(int(c2da_mem[dos_mem_dump + int(offset)]) | int(c2da_mem[dos_mem_dump + int(offset + 1u)]) << 8)
        let c2da_fresh12 : uint = uint(c2da_fresh11)
        c2da_mem[value] = uint8(c2da_fresh12)
        c2da_mem[value + 1] = uint8(c2da_fresh12 >> 0x8)
        return 1u
    } elif (size_1 == 4) {
        let c2da_fresh13 : uint = uint(int(c2da_mem[dos_mem_dump + int(offset)]) | int(c2da_mem[dos_mem_dump + int(offset + 1u)]) << 8 | int(c2da_mem[dos_mem_dump + int(offset + 2u)]) << 16 | int(c2da_mem[dos_mem_dump + int(offset + 3u)]) << 24)
        let c2da_fresh14 : uint = c2da_fresh13
        c2da_mem[value] = uint8(c2da_fresh14)
        c2da_mem[value + 1] = uint8(c2da_fresh14 >> 0x8)
        c2da_mem[value + 2] = uint8(c2da_fresh14 >> 0x10)
        c2da_mem[value + 3] = uint8(c2da_fresh14 >> 0x18)
        return 1u
    }
    return 0u
}

// This unit's static data, at heap offset 345664.
let private c2da_lin_static_i_system_seg = fixed_array<int>(345664, 41, 345722, 533)
let private c2da_lin_static_i_system = fixed_array<uint64>(0x7006f400199257ul, 0x16ul, 0x70046500c90f9eul, 0x16ul, 0xf1000000ul, 0x6e6f7a00626d2d07ul, 0x79726f6d656d2065ul, 0x7825202c7025203aul, 0x7461636f6c6c6120ul, 0x7a20726f66206465ul, 0x616e55000a656e6ful, 0x61206f7420656c62ul, 0x20657461636f6c6cul, 0x6f2042694d206925ul, 0x6f66204d41522066ul, 0x5700656e6f7a2072ul, 0x203a676e696e7261ul, 0x7669737275636572ul, 0x74206c6c61632065ul, 0x6f7272455f49206ful, 0x7463657465642072ul, 0xa0a000a2e6465ul, 0x2f006975676f6e2dul, 0x2f6e69622f727375ul, 0x25007974696e657aul, 0x6f7272652d2d2073ul, 0x747865742d2d2072ul, 0x215c60240073253dul, 0x69622f7273752f00ul, 0x7974696e657a2f6eul, 0x20706c65682d2d20ul, 0x756e2f7665642f3eul, 0x31263e32206c6cul, 0x6d656d7465732dul, 0x6400323236736f64ul, 0x736f64003137736ful, 0x6f6f442000786f62ul, 0x6972656e6547206dul, 0x6572662073692063ul, 0x617774666f732065ul, 0x65766f63202c6572ul, 0x7420796220646572ul, 0x4720554e47206568ul, 0x50206c6172656e65ul, 0x4c200a63696c6275ul, 0x202e65736e656369ul, 0x6920657265685420ul, 0x726177204f4e2073ul, 0x6e203b79746e6172ul, 0x206e65766520746ful, 0x4352454d20726f66ul, 0x4c494241544e4148ul, 0x4620726f20595449ul, 0x200a5353454e5449ul, 0x4150204120524f46ul, 0x52414c5543495452ul, 0x45534f5052555020ul, 0x726120756f59202eul, 0x6d6f636c65772065ul, 0x616863206f742065ul, 0x20646e612065676eul, 0x7562697274736964ul, 0x69706f63200a6574ul, 0x7265646e75207365ul, 0x6e69617472656320ul, 0x697469646e6f6320ul, 0x656553202e736e6ful, 0x756f732065687420ul, 0x20726f6620656372ul, 0x666e692065726f6dul, 0x6e6f6974616d726ful, 0xa7325000a2eul)

[init]
def private c2da_lin_init_static_i_system() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(2)) {
        let at = c2da_lin_static_i_system_seg[s * 2]
        for (k in range(c2da_lin_static_i_system_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_i_system[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
