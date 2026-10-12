options gen2
options solid_context = true
options stack = 4194304
module dummy public

require dasdoom_runtime
var net_client_connected : uint = 0u

var drone : uint = 0u

[export, sideeffects]
def I_InitTimidityConfig() {
    return
}
