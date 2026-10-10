options gen2
options solid_context = true
options stack = 4194304
module doomstat public

require c2da_runtime
var gamemode : GameMode_t = unsafe(reinterpret<GameMode_t>(4u))

var gamemission : GameMission_t = unsafe(reinterpret<GameMission_t>(0u))

var gameversion : GameVersion_t = unsafe(reinterpret<GameVersion_t>(8u))

var gamedescription : int8?

var modifiedgame : uint

