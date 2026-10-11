options gen2
options stack = 4194304
module m_controls public

require c2da_runtime
require i_system_cluster
require m_config
require daslib/math_bits
[export, sideeffects]
def M_BindBaseControls() {
    M_BindVariable(355952, 42384)
    M_BindVariable(355962, 42400)
    M_BindVariable(355971, 42416)
    M_BindVariable(355978, 42432)
    M_BindVariable(355987, 42448)
    M_BindVariable(356002, 42464)
    M_BindVariable(356018, 42480)
    M_BindVariable(356027, 42496)
    M_BindVariable(356035, 42512)
    M_BindVariable(356046, 42528)
    M_BindVariable(356056, 42544)
    M_BindVariable(356068, 42560)
    M_BindVariable(356082, 42576)
    M_BindVariable(356097, 42592)
    M_BindVariable(356107, 42608)
    M_BindVariable(356119, 42624)
    M_BindVariable(356128, 42640)
    M_BindVariable(356139, 42656)
    M_BindVariable(356158, 42672)
    M_BindVariable(356174, 42688)
    M_BindVariable(356191, 42704)
    M_BindVariable(356209, 42720)
    M_BindVariable(356228, 42736)
    M_BindVariable(356239, 42752)
    M_BindVariable(356255, 42768)
    M_BindVariable(356266, 42784)
    M_BindVariable(356276, 42800)
    return
}
[export, sideeffects]
def M_BindHereticControls() {
    M_BindVariable(356296, 42816)
    M_BindVariable(356306, 42832)
    M_BindVariable(356318, 42848)
    M_BindVariable(356332, 42864)
    M_BindVariable(356343, 42880)
    M_BindVariable(356356, 42896)
    M_BindVariable(356371, 42912)
    M_BindVariable(356383, 42928)
    M_BindVariable(356396, 42944)
    return
}
[export, sideeffects]
def M_BindHexenControls() {
    M_BindVariable(356412, 42960)
    M_BindVariable(356421, 42976)
    M_BindVariable(356433, 42992)
    M_BindVariable(356443, 43008)
    M_BindVariable(356456, 43024)
    M_BindVariable(356472, 43040)
    M_BindVariable(356491, 43056)
    M_BindVariable(356512, 43072)
    M_BindVariable(356530, 43088)
    M_BindVariable(356553, 43104)
    M_BindVariable(356566, 43120)
    return
}
[export, sideeffects]
def M_BindStrifeControls() {
    let c2da_fresh0 : uint = 47u
    c2da_mem[42800] = uint8(c2da_fresh0)
    c2da_mem[42801] = uint8(c2da_fresh0 >> 0x8)
    c2da_mem[42802] = uint8(c2da_fresh0 >> 0x10)
    c2da_mem[42803] = uint8(c2da_fresh0 >> 0x18)
    let c2da_fresh1 : uint = 97u
    c2da_mem[42960] = uint8(c2da_fresh1)
    c2da_mem[42961] = uint8(c2da_fresh1 >> 0x8)
    c2da_mem[42962] = uint8(c2da_fresh1 >> 0x10)
    c2da_mem[42963] = uint8(c2da_fresh1 >> 0x18)
    let c2da_fresh2 : int = 128 + 73
    let c2da_fresh3 : uint = uint(c2da_fresh2)
    c2da_mem[42864] = uint8(c2da_fresh3)
    c2da_mem[42865] = uint8(c2da_fresh3 >> 0x8)
    c2da_mem[42866] = uint8(c2da_fresh3 >> 0x10)
    c2da_mem[42867] = uint8(c2da_fresh3 >> 0x18)
    let c2da_fresh4 : int = 128 + 81
    let c2da_fresh5 : uint = uint(c2da_fresh4)
    c2da_mem[42880] = uint8(c2da_fresh5)
    c2da_mem[42881] = uint8(c2da_fresh5 >> 0x8)
    c2da_mem[42882] = uint8(c2da_fresh5 >> 0x10)
    c2da_mem[42883] = uint8(c2da_fresh5 >> 0x18)
    let c2da_fresh6 : int = 128 + 82
    let c2da_fresh7 : uint = uint(c2da_fresh6)
    c2da_mem[42912] = uint8(c2da_fresh7)
    c2da_mem[42913] = uint8(c2da_fresh7 >> 0x8)
    c2da_mem[42914] = uint8(c2da_fresh7 >> 0x10)
    c2da_mem[42915] = uint8(c2da_fresh7 >> 0x18)
    let c2da_fresh8 : int = 128 + 83
    let c2da_fresh9 : uint = uint(c2da_fresh8)
    c2da_mem[42928] = uint8(c2da_fresh9)
    c2da_mem[42929] = uint8(c2da_fresh9 >> 0x8)
    c2da_mem[42930] = uint8(c2da_fresh9 >> 0x10)
    c2da_mem[42931] = uint8(c2da_fresh9 >> 0x18)
    M_BindVariable(356412, 42960)
    M_BindVariable(356591, 42864)
    M_BindVariable(356602, 42880)
    M_BindVariable(356615, 42912)
    M_BindVariable(356627, 42928)
    M_BindVariable(356640, 43136)
    M_BindVariable(356654, 43152)
    M_BindVariable(356667, 43168)
    M_BindVariable(356679, 43184)
    M_BindVariable(356690, 43200)
    M_BindVariable(356701, 43216)
    M_BindVariable(356713, 43232)
    M_BindVariable(356724, 43248)
    M_BindVariable(356735, 43264)
    M_BindVariable(356421, 42976)
    M_BindVariable(356433, 42992)
    return
}
[export, sideeffects]
def M_BindWeaponControls() {
    M_BindVariable(356747, 41184)
    M_BindVariable(356759, 41200)
    M_BindVariable(356771, 41216)
    M_BindVariable(356783, 41232)
    M_BindVariable(356795, 41248)
    M_BindVariable(356807, 41264)
    M_BindVariable(356819, 41280)
    M_BindVariable(356831, 41296)
    M_BindVariable(356843, 43280)
    M_BindVariable(356858, 43296)
    M_BindVariable(356873, 43312)
    M_BindVariable(356889, 43328)
    M_BindVariable(356905, 43344)
    M_BindVariable(356923, 43360)
    return
}
[export, sideeffects]
def M_BindMapControls() {
    M_BindVariable(356941, 43376)
    M_BindVariable(356955, 43392)
    M_BindVariable(356969, 43408)
    M_BindVariable(356982, 43424)
    M_BindVariable(356995, 43440)
    M_BindVariable(357010, 43456)
    M_BindVariable(357026, 43472)
    M_BindVariable(357041, 43488)
    M_BindVariable(357057, 43504)
    M_BindVariable(357072, 43520)
    M_BindVariable(357085, 43536)
    M_BindVariable(357098, 43552)
    return
}
[export, sideeffects]
def M_BindMenuControls() {
    M_BindVariable(357116, 43568)
    M_BindVariable(357134, 43584)
    M_BindVariable(357146, 43600)
    M_BindVariable(357160, 43616)
    M_BindVariable(357174, 43632)
    M_BindVariable(357189, 43648)
    M_BindVariable(357203, 43664)
    M_BindVariable(357220, 43680)
    M_BindVariable(357237, 43696)
    M_BindVariable(357252, 43712)
    M_BindVariable(357266, 43728)
    M_BindVariable(357280, 43744)
    M_BindVariable(357294, 43760)
    M_BindVariable(357310, 43776)
    M_BindVariable(357326, 43792)
    M_BindVariable(357341, 43808)
    M_BindVariable(357358, 43824)
    M_BindVariable(357376, 43840)
    M_BindVariable(357391, 43856)
    M_BindVariable(357405, 43872)
    M_BindVariable(357420, 43888)
    M_BindVariable(357439, 43904)
    M_BindVariable(357458, 43920)
    M_BindVariable(357478, 43936)
    M_BindVariable(357492, 43952)
    return
}
[export, sideeffects]
def M_BindChatControls(var num_players : uint) {
    let c2da_saved_sp : int = c2da_lin_sp
    M_BindChatControls_c2da_frame(num_players, c2da_lin_enter(32))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def M_ApplyPlatformDefaults() {
    return
}
[sideeffects]
def private M_BindChatControls_c2da_frame(var num_players : uint; c2da_fp : int) {
    M_BindVariable(357500, 43968)
    for (i in urange(0u, num_players)) {
        M_snprintf(c2da_fp, 32ul, 357514, [C2daVaArg(tag = 1, i64 = int64(i + 1u), f64 = 0.0lf, raw = 0x0)])
        M_BindVariable(c2da_fp, 43984 + int(i) * 4)
    }
    return
}

// This unit's static data, at heap offset 355952.
let private c2da_lin_static_m_controls_seg = fixed_array<int>(355952, 1583)
let private c2da_lin_static_m_controls = fixed_array<uint64>(0x686769725f79656bul, 0x656c5f79656b0074ul, 0x755f79656b007466ul, 0x6f645f79656b0070ul, 0x735f79656b006e77ul, 0x66656c6566617274ul, 0x74735f79656b0074ul, 0x6867697265666172ul, 0x69665f79656b0074ul, 0x755f79656b006572ul, 0x735f79656b006573ul, 0x656b006566617274ul, 0x64656570735f79ul, 0x665f626573756f6dul, 0x73756f6d00657269ul, 0x66617274735f6265ul, 0x626573756f6d0065ul, 0x64726177726f665ful, 0x69665f62796f6a00ul, 0x5f62796f6a006572ul, 0x6a00656661727473ul, 0x6573755f62796ful, 0x6570735f62796f6aul, 0x5f62796f6a006465ul, 0x7463615f756e656dul, 0x6f6a006574617669ul, 0x66617274735f6279ul, 0x6f6a007466656c65ul, 0x66617274735f6279ul, 0x6d00746867697265ul, 0x74735f626573756ful, 0x7466656c65666172ul, 0x5f626573756f6d00ul, 0x6972656661727473ul, 0x73756f6d00746867ul, 0x6d006573755f6265ul, 0x61625f626573756ful, 0x6400647261776b63ul, 0x73755f6b63696c63ul, 0x61705f79656b0065ul, 0x5f79656b00657375ul, 0x5f6567617373656dul, 0x68736572666572ul, 0x75796c665f79656bul, 0x6c665f79656b0070ul, 0x656b006e776f6479ul, 0x6e6563796c665f79ul, 0x5f79656b00726574ul, 0x6b0070756b6f6f6cul, 0x646b6f6f6c5f7965ul, 0x5f79656b006e776ful, 0x746e65636b6f6f6cul, 0x695f79656b007265ul, 0x6b007466656c766eul, 0x6972766e695f7965ul, 0x5f79656b00746867ul, 0x6669747261657375ul, 0x5f79656b00746361ul, 0x756f6d00706d756aul, 0x706d756a5f626573ul, 0x756a5f62796f6a00ul, 0x615f79656b00706dul, 0x6c6c615f697472ul, 0x697472615f79656bul, 0x68746c6165685ful, 0x697472615f79656bul, 0x626e6f73696f705ful, 0x615f79656b006761ul, 0x73616c625f697472ul, 0x73756964617274ul, 0x697472615f79656bul, 0x726f70656c65745ful, 0x72615f79656b0074ul, 0x70656c65745f6974ul, 0x726568746f74726ful, 0x7472615f79656b00ul, 0x656b006767655f69ul, 0x695f697472615f79ul, 0x6172656e6c75766eul, 0x6b007974696c6962ul, 0x556b6f6f6c5f7965ul, 0x6f6c5f79656b0070ul, 0x6b006e776f446b6ful, 0x654c766e695f7965ul, 0x695f79656b007466ul, 0x7468676952766eul, 0x486573755f79656bul, 0x656b0068746c6165ul, 0x657571766e695f79ul, 0x6d5f79656b007972ul, 0x6b006e6f69737369ul, 0x6f50766e695f7965ul, 0x6e695f79656b0070ul, 0x79656b0079654b76ul, 0x656d6f48766e695ful, 0x766e695f79656b00ul, 0x5f79656b00646e45ul, 0x6b00657355766e69ul, 0x7244766e695f7965ul, 0x775f79656b00706ful, 0x6b00316e6f706165ul, 0x6f706165775f7965ul, 0x775f79656b00326eul, 0x6b00336e6f706165ul, 0x6f706165775f7965ul, 0x775f79656b00346eul, 0x6b00356e6f706165ul, 0x6f706165775f7965ul, 0x775f79656b00366eul, 0x6b00376e6f706165ul, 0x6f706165775f7965ul, 0x705f79656b00386eul, 0x6f70616577766572ul, 0x656e5f79656b006eul, 0x6e6f706165777478ul, 0x72705f62796f6a00ul, 0x6e6f706165777665ul, 0x656e5f62796f6a00ul, 0x6e6f706165777478ul, 0x5f626573756f6d00ul, 0x7061657776657270ul, 0x6573756f6d006e6ful, 0x65777478656e5f62ul, 0x79656b006e6f7061ul, 0x726f6e5f70616d5ful, 0x6d5f79656b006874ul, 0x6874756f735f7061ul, 0x70616d5f79656b00ul, 0x656b00747361655ful, 0x65775f70616d5f79ul, 0x6d5f79656b007473ul, 0x696d6f6f7a5f7061ul, 0x616d5f79656b006eul, 0x756f6d6f6f7a5f70ul, 0x616d5f79656b0074ul, 0x656c67676f745f70ul, 0x70616d5f79656b00ul, 0x6d6f6f7a78616d5ful, 0x70616d5f79656b00ul, 0x776f6c6c6f665ful, 0x5f70616d5f79656bul, 0x79656b0064697267ul, 0x72616d5f70616d5ful, 0x616d5f79656b006bul, 0x6d7261656c635f70ul, 0x5f79656b006b7261ul, 0x7463615f756e656dul, 0x656b006574617669ul, 0x755f756e656d5f79ul, 0x656d5f79656b0070ul, 0x6e776f645f756eul, 0x756e656d5f79656bul, 0x656b007466656c5ful, 0x725f756e656d5f79ul, 0x79656b0074686769ul, 0x61625f756e656d5ful, 0x6d5f79656b006b63ul, 0x77726f665f756e65ul, 0x5f79656b00647261ul, 0x6e6f635f756e656dul, 0x79656b006d726966ul, 0x62615f756e656d5ful, 0x5f79656b0074726ful, 0x6c65685f756e656dul, 0x656d5f79656b0070ul, 0x657661735f756eul, 0x756e656d5f79656bul, 0x656b0064616f6c5ful, 0x765f756e656d5f79ul, 0x656b00656d756c6ful, 0x645f756e656d5f79ul, 0x656b006c69617465ul, 0x715f756e656d5f79ul, 0x79656b0065766173ul, 0x6e655f756e656d5ful, 0x656b00656d616764ul, 0x6d5f756e656d5f79ul, 0x73656761737365ul, 0x756e656d5f79656bul, 0x6b0064616f6c715ful, 0x5f756e656d5f7965ul, 0x79656b0074697571ul, 0x61675f756e656d5ful, 0x5f79656b00616d6dul, 0x636e695f756e656dul, 0x6b006e6565726373ul, 0x5f756e656d5f7965ul, 0x6565726373636564ul, 0x656d5f79656b006eul, 0x65657263735f756eul, 0x656b00746f68736eul, 0x715f6f6d65645f79ul, 0x5f79656b00746975ul, 0x5f79656b00797073ul, 0x736d5f69746c756dul, 0x756d5f79656b0067ul, 0x7067736d5f69746cul, 0x6925726579616cul)

[init]
def private c2da_lin_init_static_m_controls() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_m_controls_seg[s * 2]
        for (k in range(c2da_lin_static_m_controls_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_m_controls[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_m_controls_0 = fixed_array<uint8>(0xae, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_1 = fixed_array<uint8>(0xac, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_2 = fixed_array<uint8>(0xad, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_3 = fixed_array<uint8>(0xaf, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_4 = fixed_array<uint8>(0xa0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_5 = fixed_array<uint8>(0xa1, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_6 = fixed_array<uint8>(0xa3, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_7 = fixed_array<uint8>(0xa2, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_8 = fixed_array<uint8>(0xb8, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_9 = fixed_array<uint8>(0xb6, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_11 = fixed_array<uint8>(0x1, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_12 = fixed_array<uint8>(0x2, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_14 = fixed_array<uint8>(0x1, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_15 = fixed_array<uint8>(0x3, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_16 = fixed_array<uint8>(0x2, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_17 = fixed_array<uint8>(0xff, 0xff, 0xff, 0xff)
let private c2da_lin_extern_m_controls_18 = fixed_array<uint8>(0xff, 0xff, 0xff, 0xff)
let private c2da_lin_extern_m_controls_19 = fixed_array<uint8>(0xff, 0xff, 0xff, 0xff)
let private c2da_lin_extern_m_controls_20 = fixed_array<uint8>(0xff, 0xff, 0xff, 0xff)
let private c2da_lin_extern_m_controls_21 = fixed_array<uint8>(0xff, 0xff, 0xff, 0xff)
let private c2da_lin_extern_m_controls_22 = fixed_array<uint8>(0xff, 0xff, 0xff, 0xff)
let private c2da_lin_extern_m_controls_23 = fixed_array<uint8>(0xff, 0xff, 0xff, 0xff)
let private c2da_lin_extern_m_controls_24 = fixed_array<uint8>(0x1, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_25 = fixed_array<uint8>(0xff, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_26 = fixed_array<uint8>(0xd, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_27 = fixed_array<uint8>(0xc9, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_28 = fixed_array<uint8>(0xd2, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_29 = fixed_array<uint8>(0xc7, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_30 = fixed_array<uint8>(0xd1, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_31 = fixed_array<uint8>(0xd3, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_32 = fixed_array<uint8>(0xcf, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_33 = fixed_array<uint8>(0x5b, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_34 = fixed_array<uint8>(0x5d, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_35 = fixed_array<uint8>(0xd, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_36 = fixed_array<uint8>(0x2f, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_37 = fixed_array<uint8>(0xff, 0xff, 0xff, 0xff)
let private c2da_lin_extern_m_controls_38 = fixed_array<uint8>(0xff, 0xff, 0xff, 0xff)
let private c2da_lin_extern_m_controls_39 = fixed_array<uint8>(0x7f, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_40 = fixed_array<uint8>(0x5c, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_41 = fixed_array<uint8>(0x30, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_42 = fixed_array<uint8>(0x39, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_43 = fixed_array<uint8>(0x38, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_44 = fixed_array<uint8>(0x37, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_45 = fixed_array<uint8>(0x36, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_46 = fixed_array<uint8>(0x35, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_47 = fixed_array<uint8>(0x68, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_48 = fixed_array<uint8>(0x71, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_49 = fixed_array<uint8>(0x77, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_50 = fixed_array<uint8>(0x7a, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_51 = fixed_array<uint8>(0x6b, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_52 = fixed_array<uint8>(0xc7, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_53 = fixed_array<uint8>(0xcf, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_54 = fixed_array<uint8>(0xd, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_55 = fixed_array<uint8>(0x7f, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_56 = fixed_array<uint8>(0x31, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_57 = fixed_array<uint8>(0x32, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_58 = fixed_array<uint8>(0x33, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_59 = fixed_array<uint8>(0x34, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_60 = fixed_array<uint8>(0x35, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_61 = fixed_array<uint8>(0x36, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_62 = fixed_array<uint8>(0x37, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_63 = fixed_array<uint8>(0x38, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_66 = fixed_array<uint8>(0xff, 0xff, 0xff, 0xff)
let private c2da_lin_extern_m_controls_67 = fixed_array<uint8>(0xff, 0xff, 0xff, 0xff)
let private c2da_lin_extern_m_controls_68 = fixed_array<uint8>(0xff, 0xff, 0xff, 0xff)
let private c2da_lin_extern_m_controls_69 = fixed_array<uint8>(0xff, 0xff, 0xff, 0xff)
let private c2da_lin_extern_m_controls_70 = fixed_array<uint8>(0xad, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_71 = fixed_array<uint8>(0xaf, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_72 = fixed_array<uint8>(0xae, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_73 = fixed_array<uint8>(0xac, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_74 = fixed_array<uint8>(0x3d, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_75 = fixed_array<uint8>(0x2d, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_76 = fixed_array<uint8>(0x9, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_77 = fixed_array<uint8>(0x30, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_78 = fixed_array<uint8>(0x66, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_79 = fixed_array<uint8>(0x67, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_80 = fixed_array<uint8>(0x6d, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_81 = fixed_array<uint8>(0x63, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_82 = fixed_array<uint8>(0x1b, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_83 = fixed_array<uint8>(0xad, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_84 = fixed_array<uint8>(0xaf, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_85 = fixed_array<uint8>(0xac, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_86 = fixed_array<uint8>(0xae, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_87 = fixed_array<uint8>(0x7f, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_88 = fixed_array<uint8>(0xd, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_89 = fixed_array<uint8>(0x79, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_90 = fixed_array<uint8>(0x6e, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_91 = fixed_array<uint8>(0xbb, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_92 = fixed_array<uint8>(0xbc, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_93 = fixed_array<uint8>(0xbd, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_94 = fixed_array<uint8>(0xbe, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_95 = fixed_array<uint8>(0xbf, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_96 = fixed_array<uint8>(0xc0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_97 = fixed_array<uint8>(0xc1, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_98 = fixed_array<uint8>(0xc2, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_99 = fixed_array<uint8>(0xc3, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_100 = fixed_array<uint8>(0xc4, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_101 = fixed_array<uint8>(0xd7, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_102 = fixed_array<uint8>(0x3d, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_103 = fixed_array<uint8>(0x2d, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_105 = fixed_array<uint8>(0x71, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_106 = fixed_array<uint8>(0xd8, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_controls_107 = fixed_array<uint8>(0x74, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_m_controls() {
    c2da_lin_setup()
    for (i in range(4)) {
        c2da_mem[42384 + i] = c2da_lin_extern_m_controls_0[i]
    }
    for (i in range(4)) {
        c2da_mem[42400 + i] = c2da_lin_extern_m_controls_1[i]
    }
    for (i in range(4)) {
        c2da_mem[42416 + i] = c2da_lin_extern_m_controls_2[i]
    }
    for (i in range(4)) {
        c2da_mem[42432 + i] = c2da_lin_extern_m_controls_3[i]
    }
    for (i in range(4)) {
        c2da_mem[42448 + i] = c2da_lin_extern_m_controls_4[i]
    }
    for (i in range(4)) {
        c2da_mem[42464 + i] = c2da_lin_extern_m_controls_5[i]
    }
    for (i in range(4)) {
        c2da_mem[42480 + i] = c2da_lin_extern_m_controls_6[i]
    }
    for (i in range(4)) {
        c2da_mem[42496 + i] = c2da_lin_extern_m_controls_7[i]
    }
    for (i in range(4)) {
        c2da_mem[42512 + i] = c2da_lin_extern_m_controls_8[i]
    }
    for (i in range(4)) {
        c2da_mem[42528 + i] = c2da_lin_extern_m_controls_9[i]
    }
    for (i in range(4)) {
        c2da_mem[42560 + i] = c2da_lin_extern_m_controls_11[i]
    }
    for (i in range(4)) {
        c2da_mem[42576 + i] = c2da_lin_extern_m_controls_12[i]
    }
    for (i in range(4)) {
        c2da_mem[42608 + i] = c2da_lin_extern_m_controls_14[i]
    }
    for (i in range(4)) {
        c2da_mem[42624 + i] = c2da_lin_extern_m_controls_15[i]
    }
    for (i in range(4)) {
        c2da_mem[42640 + i] = c2da_lin_extern_m_controls_16[i]
    }
    for (i in range(4)) {
        c2da_mem[42656 + i] = c2da_lin_extern_m_controls_17[i]
    }
    for (i in range(4)) {
        c2da_mem[42672 + i] = c2da_lin_extern_m_controls_18[i]
    }
    for (i in range(4)) {
        c2da_mem[42688 + i] = c2da_lin_extern_m_controls_19[i]
    }
    for (i in range(4)) {
        c2da_mem[42704 + i] = c2da_lin_extern_m_controls_20[i]
    }
    for (i in range(4)) {
        c2da_mem[42720 + i] = c2da_lin_extern_m_controls_21[i]
    }
    for (i in range(4)) {
        c2da_mem[42736 + i] = c2da_lin_extern_m_controls_22[i]
    }
    for (i in range(4)) {
        c2da_mem[42752 + i] = c2da_lin_extern_m_controls_23[i]
    }
    for (i in range(4)) {
        c2da_mem[42768 + i] = c2da_lin_extern_m_controls_24[i]
    }
    for (i in range(4)) {
        c2da_mem[42784 + i] = c2da_lin_extern_m_controls_25[i]
    }
    for (i in range(4)) {
        c2da_mem[42800 + i] = c2da_lin_extern_m_controls_26[i]
    }
    for (i in range(4)) {
        c2da_mem[42816 + i] = c2da_lin_extern_m_controls_27[i]
    }
    for (i in range(4)) {
        c2da_mem[42832 + i] = c2da_lin_extern_m_controls_28[i]
    }
    for (i in range(4)) {
        c2da_mem[42848 + i] = c2da_lin_extern_m_controls_29[i]
    }
    for (i in range(4)) {
        c2da_mem[42864 + i] = c2da_lin_extern_m_controls_30[i]
    }
    for (i in range(4)) {
        c2da_mem[42880 + i] = c2da_lin_extern_m_controls_31[i]
    }
    for (i in range(4)) {
        c2da_mem[42896 + i] = c2da_lin_extern_m_controls_32[i]
    }
    for (i in range(4)) {
        c2da_mem[42912 + i] = c2da_lin_extern_m_controls_33[i]
    }
    for (i in range(4)) {
        c2da_mem[42928 + i] = c2da_lin_extern_m_controls_34[i]
    }
    for (i in range(4)) {
        c2da_mem[42944 + i] = c2da_lin_extern_m_controls_35[i]
    }
    for (i in range(4)) {
        c2da_mem[42960 + i] = c2da_lin_extern_m_controls_36[i]
    }
    for (i in range(4)) {
        c2da_mem[42976 + i] = c2da_lin_extern_m_controls_37[i]
    }
    for (i in range(4)) {
        c2da_mem[42992 + i] = c2da_lin_extern_m_controls_38[i]
    }
    for (i in range(4)) {
        c2da_mem[43008 + i] = c2da_lin_extern_m_controls_39[i]
    }
    for (i in range(4)) {
        c2da_mem[43024 + i] = c2da_lin_extern_m_controls_40[i]
    }
    for (i in range(4)) {
        c2da_mem[43040 + i] = c2da_lin_extern_m_controls_41[i]
    }
    for (i in range(4)) {
        c2da_mem[43056 + i] = c2da_lin_extern_m_controls_42[i]
    }
    for (i in range(4)) {
        c2da_mem[43072 + i] = c2da_lin_extern_m_controls_43[i]
    }
    for (i in range(4)) {
        c2da_mem[43088 + i] = c2da_lin_extern_m_controls_44[i]
    }
    for (i in range(4)) {
        c2da_mem[43104 + i] = c2da_lin_extern_m_controls_45[i]
    }
    for (i in range(4)) {
        c2da_mem[43120 + i] = c2da_lin_extern_m_controls_46[i]
    }
    for (i in range(4)) {
        c2da_mem[43136 + i] = c2da_lin_extern_m_controls_47[i]
    }
    for (i in range(4)) {
        c2da_mem[43152 + i] = c2da_lin_extern_m_controls_48[i]
    }
    for (i in range(4)) {
        c2da_mem[43168 + i] = c2da_lin_extern_m_controls_49[i]
    }
    for (i in range(4)) {
        c2da_mem[43184 + i] = c2da_lin_extern_m_controls_50[i]
    }
    for (i in range(4)) {
        c2da_mem[43200 + i] = c2da_lin_extern_m_controls_51[i]
    }
    for (i in range(4)) {
        c2da_mem[43216 + i] = c2da_lin_extern_m_controls_52[i]
    }
    for (i in range(4)) {
        c2da_mem[43232 + i] = c2da_lin_extern_m_controls_53[i]
    }
    for (i in range(4)) {
        c2da_mem[43248 + i] = c2da_lin_extern_m_controls_54[i]
    }
    for (i in range(4)) {
        c2da_mem[43264 + i] = c2da_lin_extern_m_controls_55[i]
    }
    for (i in range(4)) {
        c2da_mem[41184 + i] = c2da_lin_extern_m_controls_56[i]
    }
    for (i in range(4)) {
        c2da_mem[41200 + i] = c2da_lin_extern_m_controls_57[i]
    }
    for (i in range(4)) {
        c2da_mem[41216 + i] = c2da_lin_extern_m_controls_58[i]
    }
    for (i in range(4)) {
        c2da_mem[41232 + i] = c2da_lin_extern_m_controls_59[i]
    }
    for (i in range(4)) {
        c2da_mem[41248 + i] = c2da_lin_extern_m_controls_60[i]
    }
    for (i in range(4)) {
        c2da_mem[41264 + i] = c2da_lin_extern_m_controls_61[i]
    }
    for (i in range(4)) {
        c2da_mem[41280 + i] = c2da_lin_extern_m_controls_62[i]
    }
    for (i in range(4)) {
        c2da_mem[41296 + i] = c2da_lin_extern_m_controls_63[i]
    }
    for (i in range(4)) {
        c2da_mem[43312 + i] = c2da_lin_extern_m_controls_66[i]
    }
    for (i in range(4)) {
        c2da_mem[43328 + i] = c2da_lin_extern_m_controls_67[i]
    }
    for (i in range(4)) {
        c2da_mem[43344 + i] = c2da_lin_extern_m_controls_68[i]
    }
    for (i in range(4)) {
        c2da_mem[43360 + i] = c2da_lin_extern_m_controls_69[i]
    }
    for (i in range(4)) {
        c2da_mem[43376 + i] = c2da_lin_extern_m_controls_70[i]
    }
    for (i in range(4)) {
        c2da_mem[43392 + i] = c2da_lin_extern_m_controls_71[i]
    }
    for (i in range(4)) {
        c2da_mem[43408 + i] = c2da_lin_extern_m_controls_72[i]
    }
    for (i in range(4)) {
        c2da_mem[43424 + i] = c2da_lin_extern_m_controls_73[i]
    }
    for (i in range(4)) {
        c2da_mem[43440 + i] = c2da_lin_extern_m_controls_74[i]
    }
    for (i in range(4)) {
        c2da_mem[43456 + i] = c2da_lin_extern_m_controls_75[i]
    }
    for (i in range(4)) {
        c2da_mem[43472 + i] = c2da_lin_extern_m_controls_76[i]
    }
    for (i in range(4)) {
        c2da_mem[43488 + i] = c2da_lin_extern_m_controls_77[i]
    }
    for (i in range(4)) {
        c2da_mem[43504 + i] = c2da_lin_extern_m_controls_78[i]
    }
    for (i in range(4)) {
        c2da_mem[43520 + i] = c2da_lin_extern_m_controls_79[i]
    }
    for (i in range(4)) {
        c2da_mem[43536 + i] = c2da_lin_extern_m_controls_80[i]
    }
    for (i in range(4)) {
        c2da_mem[43552 + i] = c2da_lin_extern_m_controls_81[i]
    }
    for (i in range(4)) {
        c2da_mem[43568 + i] = c2da_lin_extern_m_controls_82[i]
    }
    for (i in range(4)) {
        c2da_mem[43584 + i] = c2da_lin_extern_m_controls_83[i]
    }
    for (i in range(4)) {
        c2da_mem[43600 + i] = c2da_lin_extern_m_controls_84[i]
    }
    for (i in range(4)) {
        c2da_mem[43616 + i] = c2da_lin_extern_m_controls_85[i]
    }
    for (i in range(4)) {
        c2da_mem[43632 + i] = c2da_lin_extern_m_controls_86[i]
    }
    for (i in range(4)) {
        c2da_mem[43648 + i] = c2da_lin_extern_m_controls_87[i]
    }
    for (i in range(4)) {
        c2da_mem[43664 + i] = c2da_lin_extern_m_controls_88[i]
    }
    for (i in range(4)) {
        c2da_mem[43680 + i] = c2da_lin_extern_m_controls_89[i]
    }
    for (i in range(4)) {
        c2da_mem[43696 + i] = c2da_lin_extern_m_controls_90[i]
    }
    for (i in range(4)) {
        c2da_mem[43712 + i] = c2da_lin_extern_m_controls_91[i]
    }
    for (i in range(4)) {
        c2da_mem[43728 + i] = c2da_lin_extern_m_controls_92[i]
    }
    for (i in range(4)) {
        c2da_mem[43744 + i] = c2da_lin_extern_m_controls_93[i]
    }
    for (i in range(4)) {
        c2da_mem[43760 + i] = c2da_lin_extern_m_controls_94[i]
    }
    for (i in range(4)) {
        c2da_mem[43776 + i] = c2da_lin_extern_m_controls_95[i]
    }
    for (i in range(4)) {
        c2da_mem[43792 + i] = c2da_lin_extern_m_controls_96[i]
    }
    for (i in range(4)) {
        c2da_mem[43808 + i] = c2da_lin_extern_m_controls_97[i]
    }
    for (i in range(4)) {
        c2da_mem[43824 + i] = c2da_lin_extern_m_controls_98[i]
    }
    for (i in range(4)) {
        c2da_mem[43840 + i] = c2da_lin_extern_m_controls_99[i]
    }
    for (i in range(4)) {
        c2da_mem[43856 + i] = c2da_lin_extern_m_controls_100[i]
    }
    for (i in range(4)) {
        c2da_mem[43872 + i] = c2da_lin_extern_m_controls_101[i]
    }
    for (i in range(4)) {
        c2da_mem[43888 + i] = c2da_lin_extern_m_controls_102[i]
    }
    for (i in range(4)) {
        c2da_mem[43904 + i] = c2da_lin_extern_m_controls_103[i]
    }
    for (i in range(4)) {
        c2da_mem[43936 + i] = c2da_lin_extern_m_controls_105[i]
    }
    for (i in range(4)) {
        c2da_mem[43952 + i] = c2da_lin_extern_m_controls_106[i]
    }
    for (i in range(4)) {
        c2da_mem[43968 + i] = c2da_lin_extern_m_controls_107[i]
    }
}
