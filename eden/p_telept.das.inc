[export, sideeffects]
def EV_Teleport(var line : int; var side : int; var thing : int) : int {
    var i : int
    var tag : int
    var m : int
    var fog : int
    var an : uint
    var thinker : int
    var sector : int
    var oldx : int
    var oldy : int
    var oldz : int
    if ((int(uint(c2da_mem[thing + 160]) | uint(c2da_mem[thing + 161]) << 0x8 | uint(c2da_mem[thing + 162]) << 0x10 | uint(c2da_mem[thing + 163]) << 0x18) & 65536) != 0) {
        return 0
    }
    if (side == 1) {
        return 0
    }
    tag = int(int16(uint(c2da_mem[line + 28]) | uint(c2da_mem[line + 29]) << 0x8))
    i = 0
    while (i < numsectors) {
        if (int(int16(uint(c2da_mem[sectors + i * 128 + 16]) | uint(c2da_mem[sectors + i * 128 + 17]) << 0x8)) == tag) {
            thinker = int(uint(c2da_mem[46552]) | uint(c2da_mem[46553]) << 0x8 | uint(c2da_mem[46554]) << 0x10 | uint(c2da_mem[46555]) << 0x18)
            thinker = int(uint(c2da_mem[46552]) | uint(c2da_mem[46553]) << 0x8 | uint(c2da_mem[46554]) << 0x10 | uint(c2da_mem[46555]) << 0x18)
            while (thinker != 46544) {
                if (int(uint(c2da_mem[thinker + 16]) | uint(c2da_mem[thinker + 17]) << 0x8 | uint(c2da_mem[thinker + 18]) << 0x10 | uint(c2da_mem[thinker + 19]) << 0x18) != 126) {
                    thinker = int(uint(c2da_mem[thinker + 8]) | uint(c2da_mem[thinker + 9]) << 0x8 | uint(c2da_mem[thinker + 10]) << 0x10 | uint(c2da_mem[thinker + 11]) << 0x18)
                    continue
                }
                m = thinker
                if ((uint(c2da_mem[m + 128]) | uint(c2da_mem[m + 129]) << 0x8 | uint(c2da_mem[m + 130]) << 0x10 | uint(c2da_mem[m + 131]) << 0x18) != 41u) {
                    thinker = int(uint(c2da_mem[thinker + 8]) | uint(c2da_mem[thinker + 9]) << 0x8 | uint(c2da_mem[thinker + 10]) << 0x10 | uint(c2da_mem[thinker + 11]) << 0x18)
                    continue
                }
                let c2da_fresh0 : int = int(uint(c2da_mem[m + 88]) | uint(c2da_mem[m + 89]) << 0x8 | uint(c2da_mem[m + 90]) << 0x10 | uint(c2da_mem[m + 91]) << 0x18)
                sector = int(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh0 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh0 + 3]) << 0x18)
                let c2da_fresh1 : int = int(uint(c2da_mem[m + 88]) | uint(c2da_mem[m + 89]) << 0x8 | uint(c2da_mem[m + 90]) << 0x10 | uint(c2da_mem[m + 91]) << 0x18)
                sector = int(uint(c2da_mem[c2da_fresh1]) | uint(c2da_mem[c2da_fresh1 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh1 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh1 + 3]) << 0x18)
                if (int64((sector - sectors) / 128) != int64(i)) {
                    thinker = int(uint(c2da_mem[thinker + 8]) | uint(c2da_mem[thinker + 9]) << 0x8 | uint(c2da_mem[thinker + 10]) << 0x10 | uint(c2da_mem[thinker + 11]) << 0x18)
                    continue
                }
                oldx = int(uint(c2da_mem[thing + 24]) | uint(c2da_mem[thing + 25]) << 0x8 | uint(c2da_mem[thing + 26]) << 0x10 | uint(c2da_mem[thing + 27]) << 0x18)
                oldy = int(uint(c2da_mem[thing + 28]) | uint(c2da_mem[thing + 29]) << 0x8 | uint(c2da_mem[thing + 30]) << 0x10 | uint(c2da_mem[thing + 31]) << 0x18)
                oldz = int(uint(c2da_mem[thing + 32]) | uint(c2da_mem[thing + 33]) << 0x8 | uint(c2da_mem[thing + 34]) << 0x10 | uint(c2da_mem[thing + 35]) << 0x18)
                if (P_TeleportMove(thing, int(uint(c2da_mem[m + 24]) | uint(c2da_mem[m + 25]) << 0x8 | uint(c2da_mem[m + 26]) << 0x10 | uint(c2da_mem[m + 27]) << 0x18), int(uint(c2da_mem[m + 28]) | uint(c2da_mem[m + 29]) << 0x8 | uint(c2da_mem[m + 30]) << 0x10 | uint(c2da_mem[m + 31]) << 0x18)) == 0) {
                    return 0
                }
                if (uint(gameversion) != 7u) {
                    let c2da_fresh2 : int = int(uint(c2da_mem[thing + 96]) | uint(c2da_mem[thing + 97]) << 0x8 | uint(c2da_mem[thing + 98]) << 0x10 | uint(c2da_mem[thing + 99]) << 0x18)
                    let c2da_fresh3 : uint = uint(c2da_fresh2)
                    c2da_mem[thing + 32] = uint8(c2da_fresh3)
                    c2da_mem[thing + 33] = uint8(c2da_fresh3 >> 0x8)
                    c2da_mem[thing + 34] = uint8(c2da_fresh3 >> 0x10)
                    c2da_mem[thing + 35] = uint8(c2da_fresh3 >> 0x18)
                }
                if (int(uint(c2da_mem[thing + 192]) | uint(c2da_mem[thing + 193]) << 0x8 | uint(c2da_mem[thing + 194]) << 0x10 | uint(c2da_mem[thing + 195]) << 0x18) != 0) {
                    let c2da_fresh4 : int = int(uint(c2da_mem[thing + 192]) | uint(c2da_mem[thing + 193]) << 0x8 | uint(c2da_mem[thing + 194]) << 0x10 | uint(c2da_mem[thing + 195]) << 0x18) + 28
                    let c2da_fresh5 : int = int(uint(c2da_mem[thing + 192]) | uint(c2da_mem[thing + 193]) << 0x8 | uint(c2da_mem[thing + 194]) << 0x10 | uint(c2da_mem[thing + 195]) << 0x18) + 32
                    let c2da_fresh6 : int = int(uint(c2da_mem[thing + 32]) | uint(c2da_mem[thing + 33]) << 0x8 | uint(c2da_mem[thing + 34]) << 0x10 | uint(c2da_mem[thing + 35]) << 0x18) + int(uint(c2da_mem[c2da_fresh5]) | uint(c2da_mem[c2da_fresh5 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh5 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh5 + 3]) << 0x18)
                    let c2da_fresh7 : uint = uint(c2da_fresh6)
                    c2da_mem[c2da_fresh4] = uint8(c2da_fresh7)
                    c2da_mem[c2da_fresh4 + 1] = uint8(c2da_fresh7 >> 0x8)
                    c2da_mem[c2da_fresh4 + 2] = uint8(c2da_fresh7 >> 0x10)
                    c2da_mem[c2da_fresh4 + 3] = uint8(c2da_fresh7 >> 0x18)
                }
                fog = P_SpawnMobj(oldx, oldy, oldz, 39u)
                S_StartSound(fog, 35)
                an = (uint(c2da_mem[m + 56]) | uint(c2da_mem[m + 57]) << 0x8 | uint(c2da_mem[m + 58]) << 0x10 | uint(c2da_mem[m + 59]) << 0x18) >> 19u
                fog = P_SpawnMobj(int(uint(c2da_mem[m + 24]) | uint(c2da_mem[m + 25]) << 0x8 | uint(c2da_mem[m + 26]) << 0x10 | uint(c2da_mem[m + 27]) << 0x18) + 20 * int(uint(c2da_mem[finecosine + int(an) * 4]) | uint(c2da_mem[finecosine + int(an) * 4 + 1]) << 0x8 | uint(c2da_mem[finecosine + int(an) * 4 + 2]) << 0x10 | uint(c2da_mem[finecosine + int(an) * 4 + 3]) << 0x18), int(uint(c2da_mem[m + 28]) | uint(c2da_mem[m + 29]) << 0x8 | uint(c2da_mem[m + 30]) << 0x10 | uint(c2da_mem[m + 31]) << 0x18) + 20 * int(uint(c2da_mem[257920 + int(an) * 4]) | uint(c2da_mem[257920 + int(an) * 4 + 1]) << 0x8 | uint(c2da_mem[257920 + int(an) * 4 + 2]) << 0x10 | uint(c2da_mem[257920 + int(an) * 4 + 3]) << 0x18), int(uint(c2da_mem[thing + 32]) | uint(c2da_mem[thing + 33]) << 0x8 | uint(c2da_mem[thing + 34]) << 0x10 | uint(c2da_mem[thing + 35]) << 0x18), 39u)
                S_StartSound(fog, 35)
                if (int(uint(c2da_mem[thing + 192]) | uint(c2da_mem[thing + 193]) << 0x8 | uint(c2da_mem[thing + 194]) << 0x10 | uint(c2da_mem[thing + 195]) << 0x18) != 0) {
                    let c2da_fresh8 : int = 18
                    let c2da_fresh9 : uint = uint(c2da_fresh8)
                    c2da_mem[thing + 184] = uint8(c2da_fresh9)
                    c2da_mem[thing + 185] = uint8(c2da_fresh9 >> 0x8)
                    c2da_mem[thing + 186] = uint8(c2da_fresh9 >> 0x10)
                    c2da_mem[thing + 187] = uint8(c2da_fresh9 >> 0x18)
                }
                let c2da_fresh10 : uint = uint(c2da_mem[m + 56]) | uint(c2da_mem[m + 57]) << 0x8 | uint(c2da_mem[m + 58]) << 0x10 | uint(c2da_mem[m + 59]) << 0x18
                let c2da_fresh11 : uint = c2da_fresh10
                c2da_mem[thing + 56] = uint8(c2da_fresh11)
                c2da_mem[thing + 57] = uint8(c2da_fresh11 >> 0x8)
                c2da_mem[thing + 58] = uint8(c2da_fresh11 >> 0x10)
                c2da_mem[thing + 59] = uint8(c2da_fresh11 >> 0x18)
                let c2da_fresh12 : int = 0
                let c2da_fresh13 : uint = uint(c2da_fresh12)
                c2da_mem[thing + 120] = uint8(c2da_fresh13)
                c2da_mem[thing + 121] = uint8(c2da_fresh13 >> 0x8)
                c2da_mem[thing + 122] = uint8(c2da_fresh13 >> 0x10)
                c2da_mem[thing + 123] = uint8(c2da_fresh13 >> 0x18)
                let c2da_fresh14 : uint = uint(c2da_fresh12)
                c2da_mem[thing + 116] = uint8(c2da_fresh14)
                c2da_mem[thing + 117] = uint8(c2da_fresh14 >> 0x8)
                c2da_mem[thing + 118] = uint8(c2da_fresh14 >> 0x10)
                c2da_mem[thing + 119] = uint8(c2da_fresh14 >> 0x18)
                let c2da_fresh15 : uint = uint(c2da_fresh12)
                c2da_mem[thing + 112] = uint8(c2da_fresh15)
                c2da_mem[thing + 113] = uint8(c2da_fresh15 >> 0x8)
                c2da_mem[thing + 114] = uint8(c2da_fresh15 >> 0x10)
                c2da_mem[thing + 115] = uint8(c2da_fresh15 >> 0x18)
                return 1
            }
        }
        i++
    }
    return 0
}
