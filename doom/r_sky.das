options gen2
options solid_context = true
options stack = 4194304
module r_sky public

require dasdoom_runtime
var skytexture : int

var skytexturemid : int

[export, sideeffects]
def R_InitSkyMap() {
    skytexturemid = 100 * (1 << 16)
    return
}
var skyflatnum : int

