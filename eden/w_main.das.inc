[export, sideeffects]
def W_ParseCommandLine() : uint {
    var modifiedgame : uint
    var p : int
    var filename : int
    modifiedgame = 0u
    p = M_CheckParmWithArgs(376784, 1)
    if (p != 0) {
        modifiedgame = 1u
        while (true) {
            p++
            var c2da_fresh1 : int = 0
            if (p != myargc) {
                let c2da_fresh0 : int = int(uint(c2da_mem[myargv + p * 8]) | uint(c2da_mem[myargv + p * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + p * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + p * 8 + 3]) << 0x18) + 0
                if (int(int8(c2da_mem[c2da_fresh0])) != 45) {
                    c2da_fresh1 = 1
                }
            }
            if (c2da_fresh1 == 0) {
                break
            }
            filename = D_TryFindWADByName(int(uint(c2da_mem[myargv + p * 8]) | uint(c2da_mem[myargv + p * 8 + 1]) << 0x8 | uint(c2da_mem[myargv + p * 8 + 2]) << 0x10 | uint(c2da_mem[myargv + p * 8 + 3]) << 0x18))
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 376790, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(filename))])
            W_AddFile(filename)
        }
    }
    return modifiedgame
}

// This unit's static data, at heap offset 376784.
let private c2da_lin_static_w_main_seg = fixed_array<int>(376784, 17)
let private c2da_lin_static_w_main = fixed_array<uint64>(0x612000656c69662dul, 0x732520676e696464ul, 0xaul)

[init]
def private c2da_lin_init_static_w_main() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_w_main_seg[s * 2]
        for (k in range(c2da_lin_static_w_main_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_w_main[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
