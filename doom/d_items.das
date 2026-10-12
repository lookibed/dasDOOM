options gen2
options solid_context = true
options stack = 4194304
module d_items public

require dasdoom_runtime
var weaponinfo : weaponinfo_t[9] = fixed_array<weaponinfo_t>(weaponinfo_t(ammo = unsafe(reinterpret<ammotype_t>(5u)), upstate = 4, downstate = 3, readystate = 2, atkstate = 5, flashstate = 0), weaponinfo_t(ammo = unsafe(reinterpret<ammotype_t>(0u)), upstate = 12, downstate = 11, readystate = 10, atkstate = 13, flashstate = 17), weaponinfo_t(ammo = unsafe(reinterpret<ammotype_t>(1u)), upstate = 20, downstate = 19, readystate = 18, atkstate = 21, flashstate = 30), weaponinfo_t(ammo = unsafe(reinterpret<ammotype_t>(0u)), upstate = 51, downstate = 50, readystate = 49, atkstate = 52, flashstate = 55), weaponinfo_t(ammo = unsafe(reinterpret<ammotype_t>(3u)), upstate = 59, downstate = 58, readystate = 57, atkstate = 60, flashstate = 63), weaponinfo_t(ammo = unsafe(reinterpret<ammotype_t>(2u)), upstate = 76, downstate = 75, readystate = 74, atkstate = 77, flashstate = 79), weaponinfo_t(ammo = unsafe(reinterpret<ammotype_t>(2u)), upstate = 83, downstate = 82, readystate = 81, atkstate = 84, flashstate = 88), weaponinfo_t(ammo = unsafe(reinterpret<ammotype_t>(5u)), upstate = 70, downstate = 69, readystate = 67, atkstate = 71, flashstate = 0), weaponinfo_t(ammo = unsafe(reinterpret<ammotype_t>(1u)), upstate = 34, downstate = 33, readystate = 32, atkstate = 35, flashstate = 47))

[sideeffects]
def private c2da_layout_proofs() {
    static_assert(typeinfo sizeof(type<weaponinfo_t>) == 24, "C layout of weaponinfo_t: sizeof")
    static_assert(typeinfo alignof(type<weaponinfo_t>) == 4, "C layout of weaponinfo_t: alignof")
    static_assert(typeinfo offsetof<ammo>(type<weaponinfo_t>) == 0, "C layout of weaponinfo_t: offsetof ammo")
    static_assert(typeinfo offsetof<upstate>(type<weaponinfo_t>) == 4, "C layout of weaponinfo_t: offsetof upstate")
    static_assert(typeinfo offsetof<downstate>(type<weaponinfo_t>) == 8, "C layout of weaponinfo_t: offsetof downstate")
    static_assert(typeinfo offsetof<readystate>(type<weaponinfo_t>) == 12, "C layout of weaponinfo_t: offsetof readystate")
    static_assert(typeinfo offsetof<atkstate>(type<weaponinfo_t>) == 16, "C layout of weaponinfo_t: offsetof atkstate")
    static_assert(typeinfo offsetof<flashstate>(type<weaponinfo_t>) == 20, "C layout of weaponinfo_t: offsetof flashstate")
}
