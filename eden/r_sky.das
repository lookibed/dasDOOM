options gen2
options stack = 4194304
module r_sky public

require c2da_runtime
require daslib/math_bits
var skytexture : int

var skytexturemid : int

[export, sideeffects]
def R_InitSkyMap() {
    skytexturemid = 100 * (1 << 16)
    return
}
var skyflatnum : int

