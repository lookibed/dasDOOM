options gen2
options solid_context = true
options stack = 4194304
module sha1 public

require c2da_runtime
require strings
require daslib/fio
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
def SHA1_Init(var hd : sha1_context_s?) {
    hd.h0 = 0x67452301u
    hd.h1 = 0xefcdab89u
    hd.h2 = 0x98badcfeu
    hd.h3 = 0x10325476u
    hd.h4 = 0xc3d2e1f0u
    hd.nblocks = 0u
    hd.count = 0
    return
}
[export, sideeffects]
def SHA1_Update(var hd_0 : sha1_context_s?; var inbuf : uint8?; var inlen : uint64) {
    if (hd_0.count == 64) {
        var c2da_fresh0 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_0)) + 24ul))
        Transform(hd_0, unsafe(reinterpret<uint8?>(c2da_fresh0)))
        hd_0.count = 0
        let c2da_postinc : uint = hd_0.nblocks
        hd_0.nblocks = c2da_postinc + 1u
    }
    if (inbuf == null) {
        return
    }
    if (hd_0.count != 0) {
        var c2da_inbuf_addr : uint64 = unsafe(reinterpret<uint64>(inbuf))
        while (inlen != 0x0 && hd_0.count < 64) {
            var c2da_fresh1 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_0)) + 24ul))
            let c2da_postinc_0 : int = hd_0.count
            hd_0.count = c2da_postinc_0 + 1
            unsafe(unsafe(reinterpret<uint8?>(c2da_fresh1))[c2da_postinc_0]) = uint8(*unsafe(reinterpret<uint8?>(c2da_inbuf_addr)))  // nolint:PERF020
            c2da_inbuf_addr++
            inlen--
        }
        inbuf = unsafe(reinterpret<uint8?>(c2da_inbuf_addr))
        SHA1_Update(hd_0, null, 0ul)
        if (inlen == 0) {
            return
        }
    }
    while (inlen >= 64ul) {
        Transform(hd_0, inbuf)
        hd_0.count = 0
        let c2da_postinc_1 : uint = hd_0.nblocks
        hd_0.nblocks = c2da_postinc_1 + 1u
        inlen -= 64ul
        unsafe {  // nolint:STYLE025
            inbuf += 64
        }
    }
    var c2da_inbuf_addr_0 : uint64 = unsafe(reinterpret<uint64>(inbuf))
    while (inlen != 0x0 && hd_0.count < 64) {
        var c2da_fresh2 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_0)) + 24ul))
        let c2da_postinc_2 : int = hd_0.count
        hd_0.count = c2da_postinc_2 + 1
        unsafe(unsafe(reinterpret<uint8?>(c2da_fresh2))[c2da_postinc_2]) = uint8(*unsafe(reinterpret<uint8?>(c2da_inbuf_addr_0)))  // nolint:PERF020
        c2da_inbuf_addr_0++
        inlen--
    }
    return
}
[sideeffects]
def private Transform(var hd_1 : sha1_context_s?; var data : uint8?) {
    var a : uint
    var b : uint
    var c : uint
    var d : uint
    var e : uint
    var tm : uint
    var x : uint[16]
    var i : int
    var p2 : uint8?
    a = hd_1.h0
    b = hd_1.h1
    c = hd_1.h2
    d = hd_1.h3
    e = hd_1.h4
    var c2da_data_addr : uint64 = unsafe(reinterpret<uint64>(data))
    i = 0
    p2 = unsafe(reinterpret<uint8?>(unsafe(addr<uint8?>(x[0]))))
    while (i < 16) {
        unsafe(p2[3]) = uint8(*unsafe(reinterpret<uint8?>(c2da_data_addr)))  // nolint:PERF020
        c2da_data_addr++
        unsafe(p2[2]) = uint8(*unsafe(reinterpret<uint8?>(c2da_data_addr)))  // nolint:PERF020
        c2da_data_addr++
        unsafe(p2[1]) = uint8(*unsafe(reinterpret<uint8?>(c2da_data_addr)))  // nolint:PERF020
        c2da_data_addr++
        unsafe(p2[0]) = uint8(*unsafe(reinterpret<uint8?>(c2da_data_addr)))  // nolint:PERF020
        c2da_data_addr++
        i++
        unsafe {  // nolint:STYLE025
            p2 += 4
        }
    }
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (d ^ b & (c ^ d))) + 1518500249l + int64(x[0])))
    b = b << 30u | b >> uint(32 - 30)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (c ^ a & (b ^ c))) + 1518500249l + int64(x[1])))
    a = a << 30u | a >> uint(32 - 30)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (b ^ e & (a ^ b))) + 1518500249l + int64(x[2])))
    e = e << 30u | e >> uint(32 - 30)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (a ^ d & (e ^ a))) + 1518500249l + int64(x[3])))
    d = d << 30u | d >> uint(32 - 30)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (e ^ c & (d ^ e))) + 1518500249l + int64(x[4])))
    c = c << 30u | c >> uint(32 - 30)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (d ^ b & (c ^ d))) + 1518500249l + int64(x[5])))
    b = b << 30u | b >> uint(32 - 30)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (c ^ a & (b ^ c))) + 1518500249l + int64(x[6])))
    a = a << 30u | a >> uint(32 - 30)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (b ^ e & (a ^ b))) + 1518500249l + int64(x[7])))
    e = e << 30u | e >> uint(32 - 30)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (a ^ d & (e ^ a))) + 1518500249l + int64(x[8])))
    d = d << 30u | d >> uint(32 - 30)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (e ^ c & (d ^ e))) + 1518500249l + int64(x[9])))
    c = c << 30u | c >> uint(32 - 30)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (d ^ b & (c ^ d))) + 1518500249l + int64(x[10])))
    b = b << 30u | b >> uint(32 - 30)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (c ^ a & (b ^ c))) + 1518500249l + int64(x[11])))
    a = a << 30u | a >> uint(32 - 30)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (b ^ e & (a ^ b))) + 1518500249l + int64(x[12])))
    e = e << 30u | e >> uint(32 - 30)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (a ^ d & (e ^ a))) + 1518500249l + int64(x[13])))
    d = d << 30u | d >> uint(32 - 30)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (e ^ c & (d ^ e))) + 1518500249l + int64(x[14])))
    c = c << 30u | c >> uint(32 - 30)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (d ^ b & (c ^ d))) + 1518500249l + int64(x[15])))
    b = b << 30u | b >> uint(32 - 30)
    tm = x[16 & 15] ^ x[16 - 14 & 15] ^ x[16 - 8 & 15] ^ x[16 - 3 & 15]
    x[16 & 15] = tm << 1u | tm >> uint(32 - 1)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (c ^ a & (b ^ c))) + 1518500249l + int64(x[16 & 15])))
    a = a << 30u | a >> uint(32 - 30)
    tm = x[17 & 15] ^ x[17 - 14 & 15] ^ x[17 - 8 & 15] ^ x[17 - 3 & 15]
    x[17 & 15] = tm << 1u | tm >> uint(32 - 1)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (b ^ e & (a ^ b))) + 1518500249l + int64(x[17 & 15])))
    e = e << 30u | e >> uint(32 - 30)
    tm = x[18 & 15] ^ x[18 - 14 & 15] ^ x[18 - 8 & 15] ^ x[18 - 3 & 15]
    x[18 & 15] = tm << 1u | tm >> uint(32 - 1)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (a ^ d & (e ^ a))) + 1518500249l + int64(x[18 & 15])))
    d = d << 30u | d >> uint(32 - 30)
    tm = x[19 & 15] ^ x[19 - 14 & 15] ^ x[19 - 8 & 15] ^ x[19 - 3 & 15]
    x[19 & 15] = tm << 1u | tm >> uint(32 - 1)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (e ^ c & (d ^ e))) + 1518500249l + int64(x[19 & 15])))
    c = c << 30u | c >> uint(32 - 30)
    tm = x[20 & 15] ^ x[20 - 14 & 15] ^ x[20 - 8 & 15] ^ x[20 - 3 & 15]
    x[20 & 15] = tm << 1u | tm >> uint(32 - 1)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b ^ c ^ d)) + 1859775393l + int64(x[20 & 15])))
    b = b << 30u | b >> uint(32 - 30)
    tm = x[21 & 15] ^ x[21 - 14 & 15] ^ x[21 - 8 & 15] ^ x[21 - 3 & 15]
    x[21 & 15] = tm << 1u | tm >> uint(32 - 1)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a ^ b ^ c)) + 1859775393l + int64(x[21 & 15])))
    a = a << 30u | a >> uint(32 - 30)
    tm = x[22 & 15] ^ x[22 - 14 & 15] ^ x[22 - 8 & 15] ^ x[22 - 3 & 15]
    x[22 & 15] = tm << 1u | tm >> uint(32 - 1)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e ^ a ^ b)) + 1859775393l + int64(x[22 & 15])))
    e = e << 30u | e >> uint(32 - 30)
    tm = x[23 & 15] ^ x[23 - 14 & 15] ^ x[23 - 8 & 15] ^ x[23 - 3 & 15]
    x[23 & 15] = tm << 1u | tm >> uint(32 - 1)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d ^ e ^ a)) + 1859775393l + int64(x[23 & 15])))
    d = d << 30u | d >> uint(32 - 30)
    tm = x[24 & 15] ^ x[24 - 14 & 15] ^ x[24 - 8 & 15] ^ x[24 - 3 & 15]
    x[24 & 15] = tm << 1u | tm >> uint(32 - 1)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c ^ d ^ e)) + 1859775393l + int64(x[24 & 15])))
    c = c << 30u | c >> uint(32 - 30)
    tm = x[25 & 15] ^ x[25 - 14 & 15] ^ x[25 - 8 & 15] ^ x[25 - 3 & 15]
    x[25 & 15] = tm << 1u | tm >> uint(32 - 1)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b ^ c ^ d)) + 1859775393l + int64(x[25 & 15])))
    b = b << 30u | b >> uint(32 - 30)
    tm = x[26 & 15] ^ x[26 - 14 & 15] ^ x[26 - 8 & 15] ^ x[26 - 3 & 15]
    x[26 & 15] = tm << 1u | tm >> uint(32 - 1)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a ^ b ^ c)) + 1859775393l + int64(x[26 & 15])))
    a = a << 30u | a >> uint(32 - 30)
    tm = x[27 & 15] ^ x[27 - 14 & 15] ^ x[27 - 8 & 15] ^ x[27 - 3 & 15]
    x[27 & 15] = tm << 1u | tm >> uint(32 - 1)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e ^ a ^ b)) + 1859775393l + int64(x[27 & 15])))
    e = e << 30u | e >> uint(32 - 30)
    tm = x[28 & 15] ^ x[28 - 14 & 15] ^ x[28 - 8 & 15] ^ x[28 - 3 & 15]
    x[28 & 15] = tm << 1u | tm >> uint(32 - 1)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d ^ e ^ a)) + 1859775393l + int64(x[28 & 15])))
    d = d << 30u | d >> uint(32 - 30)
    tm = x[29 & 15] ^ x[29 - 14 & 15] ^ x[29 - 8 & 15] ^ x[29 - 3 & 15]
    x[29 & 15] = tm << 1u | tm >> uint(32 - 1)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c ^ d ^ e)) + 1859775393l + int64(x[29 & 15])))
    c = c << 30u | c >> uint(32 - 30)
    tm = x[30 & 15] ^ x[30 - 14 & 15] ^ x[30 - 8 & 15] ^ x[30 - 3 & 15]
    x[30 & 15] = tm << 1u | tm >> uint(32 - 1)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b ^ c ^ d)) + 1859775393l + int64(x[30 & 15])))
    b = b << 30u | b >> uint(32 - 30)
    tm = x[31 & 15] ^ x[31 - 14 & 15] ^ x[31 - 8 & 15] ^ x[31 - 3 & 15]
    x[31 & 15] = tm << 1u | tm >> uint(32 - 1)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a ^ b ^ c)) + 1859775393l + int64(x[31 & 15])))
    a = a << 30u | a >> uint(32 - 30)
    tm = x[32 & 15] ^ x[32 - 14 & 15] ^ x[32 - 8 & 15] ^ x[32 - 3 & 15]
    x[32 & 15] = tm << 1u | tm >> uint(32 - 1)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e ^ a ^ b)) + 1859775393l + int64(x[32 & 15])))
    e = e << 30u | e >> uint(32 - 30)
    tm = x[33 & 15] ^ x[33 - 14 & 15] ^ x[33 - 8 & 15] ^ x[33 - 3 & 15]
    x[33 & 15] = tm << 1u | tm >> uint(32 - 1)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d ^ e ^ a)) + 1859775393l + int64(x[33 & 15])))
    d = d << 30u | d >> uint(32 - 30)
    tm = x[34 & 15] ^ x[34 - 14 & 15] ^ x[34 - 8 & 15] ^ x[34 - 3 & 15]
    x[34 & 15] = tm << 1u | tm >> uint(32 - 1)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c ^ d ^ e)) + 1859775393l + int64(x[34 & 15])))
    c = c << 30u | c >> uint(32 - 30)
    tm = x[35 & 15] ^ x[35 - 14 & 15] ^ x[35 - 8 & 15] ^ x[35 - 3 & 15]
    x[35 & 15] = tm << 1u | tm >> uint(32 - 1)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b ^ c ^ d)) + 1859775393l + int64(x[35 & 15])))
    b = b << 30u | b >> uint(32 - 30)
    tm = x[36 & 15] ^ x[36 - 14 & 15] ^ x[36 - 8 & 15] ^ x[36 - 3 & 15]
    x[36 & 15] = tm << 1u | tm >> uint(32 - 1)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a ^ b ^ c)) + 1859775393l + int64(x[36 & 15])))
    a = a << 30u | a >> uint(32 - 30)
    tm = x[37 & 15] ^ x[37 - 14 & 15] ^ x[37 - 8 & 15] ^ x[37 - 3 & 15]
    x[37 & 15] = tm << 1u | tm >> uint(32 - 1)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e ^ a ^ b)) + 1859775393l + int64(x[37 & 15])))
    e = e << 30u | e >> uint(32 - 30)
    tm = x[38 & 15] ^ x[38 - 14 & 15] ^ x[38 - 8 & 15] ^ x[38 - 3 & 15]
    x[38 & 15] = tm << 1u | tm >> uint(32 - 1)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d ^ e ^ a)) + 1859775393l + int64(x[38 & 15])))
    d = d << 30u | d >> uint(32 - 30)
    tm = x[39 & 15] ^ x[39 - 14 & 15] ^ x[39 - 8 & 15] ^ x[39 - 3 & 15]
    x[39 & 15] = tm << 1u | tm >> uint(32 - 1)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c ^ d ^ e)) + 1859775393l + int64(x[39 & 15])))
    c = c << 30u | c >> uint(32 - 30)
    tm = x[40 & 15] ^ x[40 - 14 & 15] ^ x[40 - 8 & 15] ^ x[40 - 3 & 15]
    x[40 & 15] = tm << 1u | tm >> uint(32 - 1)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b & c | d & (b | c))) + 2400959708l + int64(x[40 & 15])))
    b = b << 30u | b >> uint(32 - 30)
    tm = x[41 & 15] ^ x[41 - 14 & 15] ^ x[41 - 8 & 15] ^ x[41 - 3 & 15]
    x[41 & 15] = tm << 1u | tm >> uint(32 - 1)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a & b | c & (a | b))) + 2400959708l + int64(x[41 & 15])))
    a = a << 30u | a >> uint(32 - 30)
    tm = x[42 & 15] ^ x[42 - 14 & 15] ^ x[42 - 8 & 15] ^ x[42 - 3 & 15]
    x[42 & 15] = tm << 1u | tm >> uint(32 - 1)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e & a | b & (e | a))) + 2400959708l + int64(x[42 & 15])))
    e = e << 30u | e >> uint(32 - 30)
    tm = x[43 & 15] ^ x[43 - 14 & 15] ^ x[43 - 8 & 15] ^ x[43 - 3 & 15]
    x[43 & 15] = tm << 1u | tm >> uint(32 - 1)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d & e | a & (d | e))) + 2400959708l + int64(x[43 & 15])))
    d = d << 30u | d >> uint(32 - 30)
    tm = x[44 & 15] ^ x[44 - 14 & 15] ^ x[44 - 8 & 15] ^ x[44 - 3 & 15]
    x[44 & 15] = tm << 1u | tm >> uint(32 - 1)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c & d | e & (c | d))) + 2400959708l + int64(x[44 & 15])))
    c = c << 30u | c >> uint(32 - 30)
    tm = x[45 & 15] ^ x[45 - 14 & 15] ^ x[45 - 8 & 15] ^ x[45 - 3 & 15]
    x[45 & 15] = tm << 1u | tm >> uint(32 - 1)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b & c | d & (b | c))) + 2400959708l + int64(x[45 & 15])))
    b = b << 30u | b >> uint(32 - 30)
    tm = x[46 & 15] ^ x[46 - 14 & 15] ^ x[46 - 8 & 15] ^ x[46 - 3 & 15]
    x[46 & 15] = tm << 1u | tm >> uint(32 - 1)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a & b | c & (a | b))) + 2400959708l + int64(x[46 & 15])))
    a = a << 30u | a >> uint(32 - 30)
    tm = x[47 & 15] ^ x[47 - 14 & 15] ^ x[47 - 8 & 15] ^ x[47 - 3 & 15]
    x[47 & 15] = tm << 1u | tm >> uint(32 - 1)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e & a | b & (e | a))) + 2400959708l + int64(x[47 & 15])))
    e = e << 30u | e >> uint(32 - 30)
    tm = x[48 & 15] ^ x[48 - 14 & 15] ^ x[48 - 8 & 15] ^ x[48 - 3 & 15]
    x[48 & 15] = tm << 1u | tm >> uint(32 - 1)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d & e | a & (d | e))) + 2400959708l + int64(x[48 & 15])))
    d = d << 30u | d >> uint(32 - 30)
    tm = x[49 & 15] ^ x[49 - 14 & 15] ^ x[49 - 8 & 15] ^ x[49 - 3 & 15]
    x[49 & 15] = tm << 1u | tm >> uint(32 - 1)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c & d | e & (c | d))) + 2400959708l + int64(x[49 & 15])))
    c = c << 30u | c >> uint(32 - 30)
    tm = x[50 & 15] ^ x[50 - 14 & 15] ^ x[50 - 8 & 15] ^ x[50 - 3 & 15]
    x[50 & 15] = tm << 1u | tm >> uint(32 - 1)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b & c | d & (b | c))) + 2400959708l + int64(x[50 & 15])))
    b = b << 30u | b >> uint(32 - 30)
    tm = x[51 & 15] ^ x[51 - 14 & 15] ^ x[51 - 8 & 15] ^ x[51 - 3 & 15]
    x[51 & 15] = tm << 1u | tm >> uint(32 - 1)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a & b | c & (a | b))) + 2400959708l + int64(x[51 & 15])))
    a = a << 30u | a >> uint(32 - 30)
    tm = x[52 & 15] ^ x[52 - 14 & 15] ^ x[52 - 8 & 15] ^ x[52 - 3 & 15]
    x[52 & 15] = tm << 1u | tm >> uint(32 - 1)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e & a | b & (e | a))) + 2400959708l + int64(x[52 & 15])))
    e = e << 30u | e >> uint(32 - 30)
    tm = x[53 & 15] ^ x[53 - 14 & 15] ^ x[53 - 8 & 15] ^ x[53 - 3 & 15]
    x[53 & 15] = tm << 1u | tm >> uint(32 - 1)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d & e | a & (d | e))) + 2400959708l + int64(x[53 & 15])))
    d = d << 30u | d >> uint(32 - 30)
    tm = x[54 & 15] ^ x[54 - 14 & 15] ^ x[54 - 8 & 15] ^ x[54 - 3 & 15]
    x[54 & 15] = tm << 1u | tm >> uint(32 - 1)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c & d | e & (c | d))) + 2400959708l + int64(x[54 & 15])))
    c = c << 30u | c >> uint(32 - 30)
    tm = x[55 & 15] ^ x[55 - 14 & 15] ^ x[55 - 8 & 15] ^ x[55 - 3 & 15]
    x[55 & 15] = tm << 1u | tm >> uint(32 - 1)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b & c | d & (b | c))) + 2400959708l + int64(x[55 & 15])))
    b = b << 30u | b >> uint(32 - 30)
    tm = x[56 & 15] ^ x[56 - 14 & 15] ^ x[56 - 8 & 15] ^ x[56 - 3 & 15]
    x[56 & 15] = tm << 1u | tm >> uint(32 - 1)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a & b | c & (a | b))) + 2400959708l + int64(x[56 & 15])))
    a = a << 30u | a >> uint(32 - 30)
    tm = x[57 & 15] ^ x[57 - 14 & 15] ^ x[57 - 8 & 15] ^ x[57 - 3 & 15]
    x[57 & 15] = tm << 1u | tm >> uint(32 - 1)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e & a | b & (e | a))) + 2400959708l + int64(x[57 & 15])))
    e = e << 30u | e >> uint(32 - 30)
    tm = x[58 & 15] ^ x[58 - 14 & 15] ^ x[58 - 8 & 15] ^ x[58 - 3 & 15]
    x[58 & 15] = tm << 1u | tm >> uint(32 - 1)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d & e | a & (d | e))) + 2400959708l + int64(x[58 & 15])))
    d = d << 30u | d >> uint(32 - 30)
    tm = x[59 & 15] ^ x[59 - 14 & 15] ^ x[59 - 8 & 15] ^ x[59 - 3 & 15]
    x[59 & 15] = tm << 1u | tm >> uint(32 - 1)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c & d | e & (c | d))) + 2400959708l + int64(x[59 & 15])))
    c = c << 30u | c >> uint(32 - 30)
    tm = x[60 & 15] ^ x[60 - 14 & 15] ^ x[60 - 8 & 15] ^ x[60 - 3 & 15]
    x[60 & 15] = tm << 1u | tm >> uint(32 - 1)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b ^ c ^ d)) + 3395469782l + int64(x[60 & 15])))
    b = b << 30u | b >> uint(32 - 30)
    tm = x[61 & 15] ^ x[61 - 14 & 15] ^ x[61 - 8 & 15] ^ x[61 - 3 & 15]
    x[61 & 15] = tm << 1u | tm >> uint(32 - 1)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a ^ b ^ c)) + 3395469782l + int64(x[61 & 15])))
    a = a << 30u | a >> uint(32 - 30)
    tm = x[62 & 15] ^ x[62 - 14 & 15] ^ x[62 - 8 & 15] ^ x[62 - 3 & 15]
    x[62 & 15] = tm << 1u | tm >> uint(32 - 1)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e ^ a ^ b)) + 3395469782l + int64(x[62 & 15])))
    e = e << 30u | e >> uint(32 - 30)
    tm = x[63 & 15] ^ x[63 - 14 & 15] ^ x[63 - 8 & 15] ^ x[63 - 3 & 15]
    x[63 & 15] = tm << 1u | tm >> uint(32 - 1)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d ^ e ^ a)) + 3395469782l + int64(x[63 & 15])))
    d = d << 30u | d >> uint(32 - 30)
    tm = x[64 & 15] ^ x[64 - 14 & 15] ^ x[64 - 8 & 15] ^ x[64 - 3 & 15]
    x[64 & 15] = tm << 1u | tm >> uint(32 - 1)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c ^ d ^ e)) + 3395469782l + int64(x[64 & 15])))
    c = c << 30u | c >> uint(32 - 30)
    tm = x[65 & 15] ^ x[65 - 14 & 15] ^ x[65 - 8 & 15] ^ x[65 - 3 & 15]
    x[65 & 15] = tm << 1u | tm >> uint(32 - 1)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b ^ c ^ d)) + 3395469782l + int64(x[65 & 15])))
    b = b << 30u | b >> uint(32 - 30)
    tm = x[66 & 15] ^ x[66 - 14 & 15] ^ x[66 - 8 & 15] ^ x[66 - 3 & 15]
    x[66 & 15] = tm << 1u | tm >> uint(32 - 1)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a ^ b ^ c)) + 3395469782l + int64(x[66 & 15])))
    a = a << 30u | a >> uint(32 - 30)
    tm = x[67 & 15] ^ x[67 - 14 & 15] ^ x[67 - 8 & 15] ^ x[67 - 3 & 15]
    x[67 & 15] = tm << 1u | tm >> uint(32 - 1)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e ^ a ^ b)) + 3395469782l + int64(x[67 & 15])))
    e = e << 30u | e >> uint(32 - 30)
    tm = x[68 & 15] ^ x[68 - 14 & 15] ^ x[68 - 8 & 15] ^ x[68 - 3 & 15]
    x[68 & 15] = tm << 1u | tm >> uint(32 - 1)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d ^ e ^ a)) + 3395469782l + int64(x[68 & 15])))
    d = d << 30u | d >> uint(32 - 30)
    tm = x[69 & 15] ^ x[69 - 14 & 15] ^ x[69 - 8 & 15] ^ x[69 - 3 & 15]
    x[69 & 15] = tm << 1u | tm >> uint(32 - 1)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c ^ d ^ e)) + 3395469782l + int64(x[69 & 15])))
    c = c << 30u | c >> uint(32 - 30)
    tm = x[70 & 15] ^ x[70 - 14 & 15] ^ x[70 - 8 & 15] ^ x[70 - 3 & 15]
    x[70 & 15] = tm << 1u | tm >> uint(32 - 1)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b ^ c ^ d)) + 3395469782l + int64(x[70 & 15])))
    b = b << 30u | b >> uint(32 - 30)
    tm = x[71 & 15] ^ x[71 - 14 & 15] ^ x[71 - 8 & 15] ^ x[71 - 3 & 15]
    x[71 & 15] = tm << 1u | tm >> uint(32 - 1)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a ^ b ^ c)) + 3395469782l + int64(x[71 & 15])))
    a = a << 30u | a >> uint(32 - 30)
    tm = x[72 & 15] ^ x[72 - 14 & 15] ^ x[72 - 8 & 15] ^ x[72 - 3 & 15]
    x[72 & 15] = tm << 1u | tm >> uint(32 - 1)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e ^ a ^ b)) + 3395469782l + int64(x[72 & 15])))
    e = e << 30u | e >> uint(32 - 30)
    tm = x[73 & 15] ^ x[73 - 14 & 15] ^ x[73 - 8 & 15] ^ x[73 - 3 & 15]
    x[73 & 15] = tm << 1u | tm >> uint(32 - 1)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d ^ e ^ a)) + 3395469782l + int64(x[73 & 15])))
    d = d << 30u | d >> uint(32 - 30)
    tm = x[74 & 15] ^ x[74 - 14 & 15] ^ x[74 - 8 & 15] ^ x[74 - 3 & 15]
    x[74 & 15] = tm << 1u | tm >> uint(32 - 1)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c ^ d ^ e)) + 3395469782l + int64(x[74 & 15])))
    c = c << 30u | c >> uint(32 - 30)
    tm = x[75 & 15] ^ x[75 - 14 & 15] ^ x[75 - 8 & 15] ^ x[75 - 3 & 15]
    x[75 & 15] = tm << 1u | tm >> uint(32 - 1)
    e = uint(int64(e) + (int64((a << 5u | a >> uint(32 - 5)) + (b ^ c ^ d)) + 3395469782l + int64(x[75 & 15])))
    b = b << 30u | b >> uint(32 - 30)
    tm = x[76 & 15] ^ x[76 - 14 & 15] ^ x[76 - 8 & 15] ^ x[76 - 3 & 15]
    x[76 & 15] = tm << 1u | tm >> uint(32 - 1)
    d = uint(int64(d) + (int64((e << 5u | e >> uint(32 - 5)) + (a ^ b ^ c)) + 3395469782l + int64(x[76 & 15])))
    a = a << 30u | a >> uint(32 - 30)
    tm = x[77 & 15] ^ x[77 - 14 & 15] ^ x[77 - 8 & 15] ^ x[77 - 3 & 15]
    x[77 & 15] = tm << 1u | tm >> uint(32 - 1)
    c = uint(int64(c) + (int64((d << 5u | d >> uint(32 - 5)) + (e ^ a ^ b)) + 3395469782l + int64(x[77 & 15])))
    e = e << 30u | e >> uint(32 - 30)
    tm = x[78 & 15] ^ x[78 - 14 & 15] ^ x[78 - 8 & 15] ^ x[78 - 3 & 15]
    x[78 & 15] = tm << 1u | tm >> uint(32 - 1)
    b = uint(int64(b) + (int64((c << 5u | c >> uint(32 - 5)) + (d ^ e ^ a)) + 3395469782l + int64(x[78 & 15])))
    d = d << 30u | d >> uint(32 - 30)
    tm = x[79 & 15] ^ x[79 - 14 & 15] ^ x[79 - 8 & 15] ^ x[79 - 3 & 15]
    x[79 & 15] = tm << 1u | tm >> uint(32 - 1)
    a = uint(int64(a) + (int64((b << 5u | b >> uint(32 - 5)) + (c ^ d ^ e)) + 3395469782l + int64(x[79 & 15])))
    c = c << 30u | c >> uint(32 - 30)
    hd_1.h0 += a
    hd_1.h1 += b
    hd_1.h2 += c
    hd_1.h3 += d
    hd_1.h4 += e
    return
}
[export, sideeffects]
def SHA1_Final(var digest : uint8?; var hd_2 : sha1_context_s?) {
    var t : uint
    var msb : uint
    var lsb : uint
    var p : uint8?
    SHA1_Update(hd_2, null, 0ul)
    t = hd_2.nblocks
    lsb = t << 6u
    msb = t >> 26u
    t = lsb
    lsb += uint(hd_2.count)
    if (lsb < t) {
        msb++
    }
    t = lsb
    lsb <<= 3u
    msb <<= 3u
    msb |= t >> 29u
    if (hd_2.count < 56) {
        var c2da_fresh3 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_2)) + 24ul))
        let c2da_postinc_3 : int = hd_2.count
        hd_2.count = c2da_postinc_3 + 1
        unsafe(unsafe(reinterpret<uint8?>(c2da_fresh3))[c2da_postinc_3]) = 0x80u8
        while (hd_2.count < 56) {
            var c2da_fresh4 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_2)) + 24ul))
            let c2da_postinc_4 : int = hd_2.count
            hd_2.count = c2da_postinc_4 + 1
            unsafe(unsafe(reinterpret<uint8?>(c2da_fresh4))[c2da_postinc_4]) = 0u8
        }
    } else {
        var c2da_fresh5 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_2)) + 24ul))
        let c2da_postinc_5 : int = hd_2.count
        hd_2.count = c2da_postinc_5 + 1
        unsafe(unsafe(reinterpret<uint8?>(c2da_fresh5))[c2da_postinc_5]) = 0x80u8
        while (hd_2.count < 64) {
            var c2da_fresh6 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_2)) + 24ul))
            let c2da_postinc_6 : int = hd_2.count
            hd_2.count = c2da_postinc_6 + 1
            unsafe(unsafe(reinterpret<uint8?>(c2da_fresh6))[c2da_postinc_6]) = 0u8
        }
        SHA1_Update(hd_2, null, 0ul)
        var c2da_fresh7 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_2)) + 24ul))
        unsafe(reinterpret<uint8?>(c2da_rt_memset(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(c2da_fresh7)))), 0u8, 56ul)))
    }
    var c2da_fresh8 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_2)) + 24ul))
    unsafe(unsafe(reinterpret<uint8?>(c2da_fresh8))[56]) = uint8(msb >> 24u)
    var c2da_fresh9 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_2)) + 24ul))
    unsafe(unsafe(reinterpret<uint8?>(c2da_fresh9))[57]) = uint8(msb >> 16u)
    var c2da_fresh10 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_2)) + 24ul))
    unsafe(unsafe(reinterpret<uint8?>(c2da_fresh10))[58]) = uint8(msb >> 8u)
    var c2da_fresh11 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_2)) + 24ul))
    unsafe(unsafe(reinterpret<uint8?>(c2da_fresh11))[59]) = uint8(msb)
    var c2da_fresh12 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_2)) + 24ul))
    unsafe(unsafe(reinterpret<uint8?>(c2da_fresh12))[60]) = uint8(lsb >> 24u)
    var c2da_fresh13 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_2)) + 24ul))
    unsafe(unsafe(reinterpret<uint8?>(c2da_fresh13))[61]) = uint8(lsb >> 16u)
    var c2da_fresh14 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_2)) + 24ul))
    unsafe(unsafe(reinterpret<uint8?>(c2da_fresh14))[62]) = uint8(lsb >> 8u)
    var c2da_fresh15 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_2)) + 24ul))
    unsafe(unsafe(reinterpret<uint8?>(c2da_fresh15))[63]) = uint8(lsb)
    var c2da_fresh16 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_2)) + 24ul))
    Transform(hd_2, unsafe(reinterpret<uint8?>(c2da_fresh16)))
    var c2da_fresh17 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_2)) + 24ul))
    p = unsafe(reinterpret<uint8?>(c2da_fresh17))
    var c2da_p_addr : uint64 = unsafe(reinterpret<uint64>(p))
    *unsafe(reinterpret<uint8?>(c2da_p_addr)) = uint8(hd_2.h0 >> 24u)
    c2da_p_addr++
    *unsafe(reinterpret<uint8?>(c2da_p_addr)) = uint8(hd_2.h0 >> 16u)
    c2da_p_addr++
    *unsafe(reinterpret<uint8?>(c2da_p_addr)) = uint8(hd_2.h0 >> 8u)
    c2da_p_addr++
    *unsafe(reinterpret<uint8?>(c2da_p_addr)) = uint8(hd_2.h0)
    c2da_p_addr++
    p = unsafe(reinterpret<uint8?>(c2da_p_addr))
    var c2da_p_addr_0 : uint64 = unsafe(reinterpret<uint64>(p))
    *unsafe(reinterpret<uint8?>(c2da_p_addr_0)) = uint8(hd_2.h1 >> 24u)
    c2da_p_addr_0++
    *unsafe(reinterpret<uint8?>(c2da_p_addr_0)) = uint8(hd_2.h1 >> 16u)
    c2da_p_addr_0++
    *unsafe(reinterpret<uint8?>(c2da_p_addr_0)) = uint8(hd_2.h1 >> 8u)
    c2da_p_addr_0++
    *unsafe(reinterpret<uint8?>(c2da_p_addr_0)) = uint8(hd_2.h1)
    c2da_p_addr_0++
    p = unsafe(reinterpret<uint8?>(c2da_p_addr_0))
    var c2da_p_addr_1 : uint64 = unsafe(reinterpret<uint64>(p))
    *unsafe(reinterpret<uint8?>(c2da_p_addr_1)) = uint8(hd_2.h2 >> 24u)
    c2da_p_addr_1++
    *unsafe(reinterpret<uint8?>(c2da_p_addr_1)) = uint8(hd_2.h2 >> 16u)
    c2da_p_addr_1++
    *unsafe(reinterpret<uint8?>(c2da_p_addr_1)) = uint8(hd_2.h2 >> 8u)
    c2da_p_addr_1++
    *unsafe(reinterpret<uint8?>(c2da_p_addr_1)) = uint8(hd_2.h2)
    c2da_p_addr_1++
    p = unsafe(reinterpret<uint8?>(c2da_p_addr_1))
    var c2da_p_addr_2 : uint64 = unsafe(reinterpret<uint64>(p))
    *unsafe(reinterpret<uint8?>(c2da_p_addr_2)) = uint8(hd_2.h3 >> 24u)
    c2da_p_addr_2++
    *unsafe(reinterpret<uint8?>(c2da_p_addr_2)) = uint8(hd_2.h3 >> 16u)
    c2da_p_addr_2++
    *unsafe(reinterpret<uint8?>(c2da_p_addr_2)) = uint8(hd_2.h3 >> 8u)
    c2da_p_addr_2++
    *unsafe(reinterpret<uint8?>(c2da_p_addr_2)) = uint8(hd_2.h3)
    c2da_p_addr_2++
    p = unsafe(reinterpret<uint8?>(c2da_p_addr_2))
    var c2da_p_addr_3 : uint64 = unsafe(reinterpret<uint64>(p))
    *unsafe(reinterpret<uint8?>(c2da_p_addr_3)) = uint8(hd_2.h4 >> 24u)
    c2da_p_addr_3++
    *unsafe(reinterpret<uint8?>(c2da_p_addr_3)) = uint8(hd_2.h4 >> 16u)
    c2da_p_addr_3++
    *unsafe(reinterpret<uint8?>(c2da_p_addr_3)) = uint8(hd_2.h4 >> 8u)
    c2da_p_addr_3++
    *unsafe(reinterpret<uint8?>(c2da_p_addr_3)) = uint8(hd_2.h4)
    c2da_p_addr_3++
    var c2da_fresh18 : uint8? = unsafe(reinterpret<uint8?>(unsafe(reinterpret<uint64>(hd_2)) + 24ul))
    unsafe(memcpy(unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(digest)))))), unsafe(reinterpret<void?>(unsafe(reinterpret<uint64>(unsafe(reinterpret<uint8?>(c2da_fresh18)))))), 20ul))
    return
}
[export, sideeffects]
def SHA1_UpdateInt32(var context : sha1_context_s?; var val : uint) {
    var buf : uint8[4]
    buf[0] = uint8(val >> 24u & 0xffu)
    buf[1] = uint8(val >> 16u & 0xffu)
    buf[2] = uint8(val >> 8u & 0xffu)
    buf[3] = uint8(val & 0xffu)
    SHA1_Update(context, unsafe(addr<uint8?>(buf[0])), 4ul)
    return
}
[export, sideeffects]
def SHA1_UpdateString(var context_0 : sha1_context_s?; var str : int8?) {
    SHA1_Update(context_0, unsafe(reinterpret<uint8?>(str)), c2da_std_strlen(unsafe(reinterpret<uint64>(str))) + 1ul)
    return
}
[sideeffects]
def private c2da_layout_proofs() {
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
}
