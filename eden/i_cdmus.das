options gen2
options stack = 4194304
module i_cdmus public

require c2da_runtime
require daslib/math_bits
var cd_Error : int

[export, sideeffects]
def I_CDMusInit() : int {
    return 0
}
[export, sideeffects]
def I_CDMusPrintStartup() {
    return
}
[export, sideeffects]
def I_CDMusPlay(var track : int) : int {
    return 0
}
[export, sideeffects]
def I_CDMusStop() : int {
    return 0
}
[export, sideeffects]
def I_CDMusResume() : int {
    return 0
}
[export, sideeffects]
def I_CDMusSetVolume(var volume : int) : int {
    cd_Error = 0
    return 0
}
[export, sideeffects]
def I_CDMusFirstTrack() : int {
    return 0
}
[export, sideeffects]
def I_CDMusLastTrack() : int {
    return 0
}
[export, sideeffects]
def I_CDMusTrackLength(var track_num : int) : int {
    return 0
}
