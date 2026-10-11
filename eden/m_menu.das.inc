var private M_Responder__joywait : int = 0

var private M_Responder__mousewait : int = 0

var private M_Responder__mousey : int = 0

var private M_Responder__lasty : int = 0

var private M_Responder__mousex : int = 0

var private M_Responder__lastx : int = 0

var private M_Drawer__x : int16 = int16(0)

var private M_Drawer__y : int16 = int16(0)

[sideeffects]
def private c2da___bswap_16_6(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32_6(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64_6(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity_6(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity_6(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity_6(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
var menuactive : uint = default<uint>

[export, sideeffects]
def M_Responder(var ev : int) : uint {
    var ch : int
    var key : int
    var i : int
    if (testcontrols != 0x0) {
        if ((uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 4u || (uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 0u && (int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) == int(uint(c2da_mem[43568]) | uint(c2da_mem[43569]) << 0x8 | uint(c2da_mem[43570]) << 0x10 | uint(c2da_mem[43571]) << 0x18) || int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) == int(uint(c2da_mem[43856]) | uint(c2da_mem[43857]) << 0x8 | uint(c2da_mem[43858]) << 0x10 | uint(c2da_mem[43859]) << 0x18))) {
            I_Quit()
            return 1u
        }
        return 0u
    }
    if ((uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 4u) {
        if (menuactive != 0x0 && messageToPrint != 0 && messageRoutine == 89) {
            M_QuitResponse(int(uint(c2da_mem[43680]) | uint(c2da_mem[43681]) << 0x8 | uint(c2da_mem[43682]) << 0x10 | uint(c2da_mem[43683]) << 0x18))
        } else {
            S_StartSound(0, 23)
            M_QuitDOOM(0)
        }
        return 1u
    }
    ch = 0
    key = -1
    if ((uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 3u && M_Responder__joywait < I_GetTime()) {
        if (int(uint(c2da_mem[ev + 12]) | uint(c2da_mem[ev + 13]) << 0x8 | uint(c2da_mem[ev + 14]) << 0x10 | uint(c2da_mem[ev + 15]) << 0x18) < 0) {
            key = int(uint(c2da_mem[43584]) | uint(c2da_mem[43585]) << 0x8 | uint(c2da_mem[43586]) << 0x10 | uint(c2da_mem[43587]) << 0x18)
            M_Responder__joywait = I_GetTime() + 5
        } elif (int(uint(c2da_mem[ev + 12]) | uint(c2da_mem[ev + 13]) << 0x8 | uint(c2da_mem[ev + 14]) << 0x10 | uint(c2da_mem[ev + 15]) << 0x18) > 0) {
            key = int(uint(c2da_mem[43600]) | uint(c2da_mem[43601]) << 0x8 | uint(c2da_mem[43602]) << 0x10 | uint(c2da_mem[43603]) << 0x18)
            M_Responder__joywait = I_GetTime() + 5
        }
        if (int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18) < 0) {
            key = int(uint(c2da_mem[43616]) | uint(c2da_mem[43617]) << 0x8 | uint(c2da_mem[43618]) << 0x10 | uint(c2da_mem[43619]) << 0x18)
            M_Responder__joywait = I_GetTime() + 2
        } elif (int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18) > 0) {
            key = int(uint(c2da_mem[43632]) | uint(c2da_mem[43633]) << 0x8 | uint(c2da_mem[43634]) << 0x10 | uint(c2da_mem[43635]) << 0x18)
            M_Responder__joywait = I_GetTime() + 2
        }
        if ((int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) & 1) != 0) {
            key = int(uint(c2da_mem[43664]) | uint(c2da_mem[43665]) << 0x8 | uint(c2da_mem[43666]) << 0x10 | uint(c2da_mem[43667]) << 0x18)
            M_Responder__joywait = I_GetTime() + 5
        }
        if ((int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) & 2) != 0) {
            key = int(uint(c2da_mem[43648]) | uint(c2da_mem[43649]) << 0x8 | uint(c2da_mem[43650]) << 0x10 | uint(c2da_mem[43651]) << 0x18)
            M_Responder__joywait = I_GetTime() + 5
        }
        if (int(uint(c2da_mem[42656]) | uint(c2da_mem[42657]) << 0x8 | uint(c2da_mem[42658]) << 0x10 | uint(c2da_mem[42659]) << 0x18) >= 0 && (int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) & 1 << int(uint(c2da_mem[42656]) | uint(c2da_mem[42657]) << 0x8 | uint(c2da_mem[42658]) << 0x10 | uint(c2da_mem[42659]) << 0x18)) != 0) {
            key = int(uint(c2da_mem[43568]) | uint(c2da_mem[43569]) << 0x8 | uint(c2da_mem[43570]) << 0x10 | uint(c2da_mem[43571]) << 0x18)
            M_Responder__joywait = I_GetTime() + 5
        }
    } elif ((uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 2u && M_Responder__mousewait < I_GetTime()) {
        M_Responder__mousey += int(uint(c2da_mem[ev + 12]) | uint(c2da_mem[ev + 13]) << 0x8 | uint(c2da_mem[ev + 14]) << 0x10 | uint(c2da_mem[ev + 15]) << 0x18)
        if (M_Responder__mousey < M_Responder__lasty - 30) {
            key = int(uint(c2da_mem[43600]) | uint(c2da_mem[43601]) << 0x8 | uint(c2da_mem[43602]) << 0x10 | uint(c2da_mem[43603]) << 0x18)
            M_Responder__mousewait = I_GetTime() + 5
            M_Responder__lasty -= 30
            M_Responder__mousey = int(M_Responder__lasty)  // nolint:PERF020
        } elif (M_Responder__mousey > M_Responder__lasty + 30) {
            key = int(uint(c2da_mem[43584]) | uint(c2da_mem[43585]) << 0x8 | uint(c2da_mem[43586]) << 0x10 | uint(c2da_mem[43587]) << 0x18)
            M_Responder__mousewait = I_GetTime() + 5
            M_Responder__lasty += 30
            M_Responder__mousey = int(M_Responder__lasty)  // nolint:PERF020
        }
        M_Responder__mousex += int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18)
        if (M_Responder__mousex < M_Responder__lastx - 30) {
            key = int(uint(c2da_mem[43616]) | uint(c2da_mem[43617]) << 0x8 | uint(c2da_mem[43618]) << 0x10 | uint(c2da_mem[43619]) << 0x18)
            M_Responder__mousewait = I_GetTime() + 5
            M_Responder__lastx -= 30
            M_Responder__mousex = int(M_Responder__lastx)  // nolint:PERF020
        } elif (M_Responder__mousex > M_Responder__lastx + 30) {
            key = int(uint(c2da_mem[43632]) | uint(c2da_mem[43633]) << 0x8 | uint(c2da_mem[43634]) << 0x10 | uint(c2da_mem[43635]) << 0x18)
            M_Responder__mousewait = I_GetTime() + 5
            M_Responder__lastx += 30
            M_Responder__mousex = int(M_Responder__lastx)  // nolint:PERF020
        }
        if ((int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) & 1) != 0) {
            key = int(uint(c2da_mem[43664]) | uint(c2da_mem[43665]) << 0x8 | uint(c2da_mem[43666]) << 0x10 | uint(c2da_mem[43667]) << 0x18)
            M_Responder__mousewait = I_GetTime() + 15
        }
        if ((int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18) & 2) != 0) {
            key = int(uint(c2da_mem[43648]) | uint(c2da_mem[43649]) << 0x8 | uint(c2da_mem[43650]) << 0x10 | uint(c2da_mem[43651]) << 0x18)
            M_Responder__mousewait = I_GetTime() + 15
        }
    } elif ((uint(c2da_mem[ev]) | uint(c2da_mem[ev + 1]) << 0x8 | uint(c2da_mem[ev + 2]) << 0x10 | uint(c2da_mem[ev + 3]) << 0x18) == 0u) {
        key = int(uint(c2da_mem[ev + 4]) | uint(c2da_mem[ev + 5]) << 0x8 | uint(c2da_mem[ev + 6]) << 0x10 | uint(c2da_mem[ev + 7]) << 0x18)
        ch = int(uint(c2da_mem[ev + 8]) | uint(c2da_mem[ev + 9]) << 0x8 | uint(c2da_mem[ev + 10]) << 0x10 | uint(c2da_mem[ev + 11]) << 0x18)
    }
    if (key == -1) {
        return 0u
    }
    if (saveStringEnter != 0) {
        if (key == 127) {
            if (saveCharIndex > 0) {
                saveCharIndex--
                let c2da_fresh0 : int8 = int8(0)
                c2da_mem[44016 + saveSlot * 24 + saveCharIndex] = uint8(c2da_fresh0)
            }
        } elif (key == 27) {
            saveStringEnter = 0
            M_StringCopy(44016 + saveSlot * 24, 44256, 24ul)
        } elif (key == 13) {
            saveStringEnter = 0
            if (int8(c2da_mem[44016 + saveSlot * 24 + 0]) != 0) {
                M_DoSave(saveSlot)
            }
        } else {
            if (vanilla_keyboard_mapping != 0) {
                ch = key
            }
            ch = c2da_std_toupper(ch)
            if (!(ch != 32 && (ch - 33 < 0 || ch - 33 >= 95 - 33 + 1))) {
                if (ch >= 32 && ch <= 127 && saveCharIndex < 24 - 1 && M_StringWidth(44016 + saveSlot * 24) < (24 - 2) * 8) {
                    let c2da_postinc : int = saveCharIndex
                    saveCharIndex++
                    let c2da_fresh1 : int8 = int8(ch)
                    c2da_mem[44016 + saveSlot * 24 + c2da_postinc] = uint8(c2da_fresh1)
                    let c2da_fresh2 : int8 = int8(0)
                    c2da_mem[44016 + saveSlot * 24 + saveCharIndex] = uint8(c2da_fresh2)
                }
            }
        }
        return 1u
    }
    if (messageToPrint != 0) {
        if (messageNeedsInput != 0x0) {
            if (key != 32 && key != 27 && key != int(uint(c2da_mem[43680]) | uint(c2da_mem[43681]) << 0x8 | uint(c2da_mem[43682]) << 0x10 | uint(c2da_mem[43683]) << 0x18) && key != int(uint(c2da_mem[43696]) | uint(c2da_mem[43697]) << 0x8 | uint(c2da_mem[43698]) << 0x10 | uint(c2da_mem[43699]) << 0x18)) {
                return 0u
            }
        }
        menuactive = uint(messageLastMenuActive)
        messageToPrint = 0
        if (messageRoutine != default<int>) {
            invoke(c2da_fn_table5[messageRoutine], key)
        }
        menuactive = 0u
        S_StartSound(0, 24)
        return 1u
    }
    if (devparm != 0x0 && key == int(uint(c2da_mem[43712]) | uint(c2da_mem[43713]) << 0x8 | uint(c2da_mem[43714]) << 0x10 | uint(c2da_mem[43715]) << 0x18) || key != 0 && key == int(uint(c2da_mem[43920]) | uint(c2da_mem[43921]) << 0x8 | uint(c2da_mem[43922]) << 0x10 | uint(c2da_mem[43923]) << 0x18)) {
        G_ScreenShot()
        return 1u
    }
    if (menuactive == 0) {
        if (key == int(uint(c2da_mem[43904]) | uint(c2da_mem[43905]) << 0x8 | uint(c2da_mem[43906]) << 0x10 | uint(c2da_mem[43907]) << 0x18)) {
            if (automapactive != 0x0 || (uint(c2da_mem[42032]) | uint(c2da_mem[42033]) << 0x8 | uint(c2da_mem[42034]) << 0x10 | uint(c2da_mem[42035]) << 0x18) != 0x0) {
                return 0u
            }
            M_SizeDisplay(0)
            S_StartSound(0, 22)
            return 1u
        } elif (key == int(uint(c2da_mem[43888]) | uint(c2da_mem[43889]) << 0x8 | uint(c2da_mem[43890]) << 0x10 | uint(c2da_mem[43891]) << 0x18)) {
            if (automapactive != 0x0 || (uint(c2da_mem[42032]) | uint(c2da_mem[42033]) << 0x8 | uint(c2da_mem[42034]) << 0x10 | uint(c2da_mem[42035]) << 0x18) != 0x0) {
                return 0u
            }
            M_SizeDisplay(1)
            S_StartSound(0, 22)
            return 1u
        } elif (key == int(uint(c2da_mem[43712]) | uint(c2da_mem[43713]) << 0x8 | uint(c2da_mem[43714]) << 0x10 | uint(c2da_mem[43715]) << 0x18)) {
            M_StartControlPanel()
            if (uint(gamemode) == 3u) {
                currentMenu = 44288
            } else {
                currentMenu = 44336
            }
            itemOn = int16(0)
            S_StartSound(0, 23)
            return 1u
        } elif (key == int(uint(c2da_mem[43728]) | uint(c2da_mem[43729]) << 0x8 | uint(c2da_mem[43730]) << 0x10 | uint(c2da_mem[43731]) << 0x18)) {
            M_StartControlPanel()
            S_StartSound(0, 23)
            M_SaveGame(0)
            return 1u
        } elif (key == int(uint(c2da_mem[43744]) | uint(c2da_mem[43745]) << 0x8 | uint(c2da_mem[43746]) << 0x10 | uint(c2da_mem[43747]) << 0x18)) {
            M_StartControlPanel()
            S_StartSound(0, 23)
            M_LoadGame(0)
            return 1u
        } elif (key == int(uint(c2da_mem[43760]) | uint(c2da_mem[43761]) << 0x8 | uint(c2da_mem[43762]) << 0x10 | uint(c2da_mem[43763]) << 0x18)) {
            M_StartControlPanel()
            currentMenu = 44384
            itemOn = int16(0)
            S_StartSound(0, 23)
            return 1u
        } elif (key == int(uint(c2da_mem[43776]) | uint(c2da_mem[43777]) << 0x8 | uint(c2da_mem[43778]) << 0x10 | uint(c2da_mem[43779]) << 0x18)) {
            M_ChangeDetail(0)
            S_StartSound(0, 23)
            return 1u
        } elif (key == int(uint(c2da_mem[43792]) | uint(c2da_mem[43793]) << 0x8 | uint(c2da_mem[43794]) << 0x10 | uint(c2da_mem[43795]) << 0x18)) {
            S_StartSound(0, 23)
            M_QuickSave()
            return 1u
        } elif (key == int(uint(c2da_mem[43808]) | uint(c2da_mem[43809]) << 0x8 | uint(c2da_mem[43810]) << 0x10 | uint(c2da_mem[43811]) << 0x18)) {
            S_StartSound(0, 23)
            M_EndGame(0)
            return 1u
        } elif (key == int(uint(c2da_mem[43824]) | uint(c2da_mem[43825]) << 0x8 | uint(c2da_mem[43826]) << 0x10 | uint(c2da_mem[43827]) << 0x18)) {
            M_ChangeMessages(0)
            S_StartSound(0, 23)
            return 1u
        } elif (key == int(uint(c2da_mem[43840]) | uint(c2da_mem[43841]) << 0x8 | uint(c2da_mem[43842]) << 0x10 | uint(c2da_mem[43843]) << 0x18)) {
            S_StartSound(0, 23)
            M_QuickLoad()
            return 1u
        } elif (key == int(uint(c2da_mem[43856]) | uint(c2da_mem[43857]) << 0x8 | uint(c2da_mem[43858]) << 0x10 | uint(c2da_mem[43859]) << 0x18)) {
            S_StartSound(0, 23)
            M_QuitDOOM(0)
            return 1u
        } elif (key == int(uint(c2da_mem[43872]) | uint(c2da_mem[43873]) << 0x8 | uint(c2da_mem[43874]) << 0x10 | uint(c2da_mem[43875]) << 0x18)) {
            usegamma = usegamma + 1
            if (usegamma > 4) {
                usegamma = 0
            }
            let c2da_fresh3 : int = 44432 + int(usegamma) * 26
            let c2da_fresh4 : uint = uint(c2da_fresh3)
            c2da_mem[96 + int(consoleplayer) * 328 + 232] = uint8(c2da_fresh4)
            c2da_mem[96 + int(consoleplayer) * 328 + 233] = uint8(c2da_fresh4 >> 0x8)
            c2da_mem[96 + int(consoleplayer) * 328 + 234] = uint8(c2da_fresh4 >> 0x10)
            c2da_mem[96 + int(consoleplayer) * 328 + 235] = uint8(c2da_fresh4 >> 0x18)
            c2da_mem[96 + int(consoleplayer) * 328 + 236] = 0u8
            c2da_mem[96 + int(consoleplayer) * 328 + 237] = 0u8
            c2da_mem[96 + int(consoleplayer) * 328 + 238] = 0u8
            c2da_mem[96 + int(consoleplayer) * 328 + 239] = 0u8
            I_SetPalette(W_CacheLumpName(357536, 8))
            return 1u
        }
    }
    if (menuactive == 0) {
        if (key == int(uint(c2da_mem[43568]) | uint(c2da_mem[43569]) << 0x8 | uint(c2da_mem[43570]) << 0x10 | uint(c2da_mem[43571]) << 0x18)) {
            M_StartControlPanel()
            S_StartSound(0, 23)
            return 1u
        }
        return 0u
    }
    if (key == int(uint(c2da_mem[43600]) | uint(c2da_mem[43601]) << 0x8 | uint(c2da_mem[43602]) << 0x10 | uint(c2da_mem[43603]) << 0x18)) {
        while (true) {
            if (int(itemOn) + 1 > int(int16(uint(c2da_mem[currentMenu]) | uint(c2da_mem[currentMenu + 1]) << 0x8)) - 1) {
                itemOn = int16(0)
            } else {
                itemOn = int16(int(itemOn) + 1)
            }
            S_StartSound(0, 19)
            let c2da_fresh5 : int = int(uint(c2da_mem[currentMenu + 16]) | uint(c2da_mem[currentMenu + 17]) << 0x8 | uint(c2da_mem[currentMenu + 18]) << 0x10 | uint(c2da_mem[currentMenu + 19]) << 0x18) + int(itemOn) * 32
            if (int(int16(uint(c2da_mem[c2da_fresh5]) | uint(c2da_mem[c2da_fresh5 + 1]) << 0x8)) != -1) {
                break
            }
        }
        return 1u
    } elif (key == int(uint(c2da_mem[43584]) | uint(c2da_mem[43585]) << 0x8 | uint(c2da_mem[43586]) << 0x10 | uint(c2da_mem[43587]) << 0x18)) {
        while (true) {
            if (itemOn == 0) {
                itemOn = int16(int(int16(uint(c2da_mem[currentMenu]) | uint(c2da_mem[currentMenu + 1]) << 0x8)) - 1)
            } else {
                itemOn = int16(int(itemOn) - 1)
            }
            S_StartSound(0, 19)
            let c2da_fresh6 : int = int(uint(c2da_mem[currentMenu + 16]) | uint(c2da_mem[currentMenu + 17]) << 0x8 | uint(c2da_mem[currentMenu + 18]) << 0x10 | uint(c2da_mem[currentMenu + 19]) << 0x18) + int(itemOn) * 32
            if (int(int16(uint(c2da_mem[c2da_fresh6]) | uint(c2da_mem[c2da_fresh6 + 1]) << 0x8)) != -1) {
                break
            }
        }
        return 1u
    } elif (key == int(uint(c2da_mem[43616]) | uint(c2da_mem[43617]) << 0x8 | uint(c2da_mem[43618]) << 0x10 | uint(c2da_mem[43619]) << 0x18)) {
        let c2da_fresh7 : int = int(uint(c2da_mem[currentMenu + 16]) | uint(c2da_mem[currentMenu + 17]) << 0x8 | uint(c2da_mem[currentMenu + 18]) << 0x10 | uint(c2da_mem[currentMenu + 19]) << 0x18) + int(itemOn) * 32 + 16
        var c2da_fresh9 : int = 0
        if (int(uint(c2da_mem[c2da_fresh7]) | uint(c2da_mem[c2da_fresh7 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh7 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh7 + 3]) << 0x18) != default<int>) {
            let c2da_fresh8 : int = int(uint(c2da_mem[currentMenu + 16]) | uint(c2da_mem[currentMenu + 17]) << 0x8 | uint(c2da_mem[currentMenu + 18]) << 0x10 | uint(c2da_mem[currentMenu + 19]) << 0x18) + int(itemOn) * 32
            if (int(int16(uint(c2da_mem[c2da_fresh8]) | uint(c2da_mem[c2da_fresh8 + 1]) << 0x8)) == 2) {
                c2da_fresh9 = 1
            }
        }
        if (c2da_fresh9 != 0) {
            S_StartSound(0, 22)
            let c2da_fresh10 : int = int(uint(c2da_mem[currentMenu + 16]) | uint(c2da_mem[currentMenu + 17]) << 0x8 | uint(c2da_mem[currentMenu + 18]) << 0x10 | uint(c2da_mem[currentMenu + 19]) << 0x18) + int(itemOn) * 32 + 16
            invoke(c2da_fn_table5[int(uint(c2da_mem[c2da_fresh10]) | uint(c2da_mem[c2da_fresh10 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh10 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh10 + 3]) << 0x18)], 0)
        }
        return 1u
    } elif (key == int(uint(c2da_mem[43632]) | uint(c2da_mem[43633]) << 0x8 | uint(c2da_mem[43634]) << 0x10 | uint(c2da_mem[43635]) << 0x18)) {
        let c2da_fresh11 : int = int(uint(c2da_mem[currentMenu + 16]) | uint(c2da_mem[currentMenu + 17]) << 0x8 | uint(c2da_mem[currentMenu + 18]) << 0x10 | uint(c2da_mem[currentMenu + 19]) << 0x18) + int(itemOn) * 32 + 16
        var c2da_fresh13 : int = 0
        if (int(uint(c2da_mem[c2da_fresh11]) | uint(c2da_mem[c2da_fresh11 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh11 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh11 + 3]) << 0x18) != default<int>) {
            let c2da_fresh12 : int = int(uint(c2da_mem[currentMenu + 16]) | uint(c2da_mem[currentMenu + 17]) << 0x8 | uint(c2da_mem[currentMenu + 18]) << 0x10 | uint(c2da_mem[currentMenu + 19]) << 0x18) + int(itemOn) * 32
            if (int(int16(uint(c2da_mem[c2da_fresh12]) | uint(c2da_mem[c2da_fresh12 + 1]) << 0x8)) == 2) {
                c2da_fresh13 = 1
            }
        }
        if (c2da_fresh13 != 0) {
            S_StartSound(0, 22)
            let c2da_fresh14 : int = int(uint(c2da_mem[currentMenu + 16]) | uint(c2da_mem[currentMenu + 17]) << 0x8 | uint(c2da_mem[currentMenu + 18]) << 0x10 | uint(c2da_mem[currentMenu + 19]) << 0x18) + int(itemOn) * 32 + 16
            invoke(c2da_fn_table5[int(uint(c2da_mem[c2da_fresh14]) | uint(c2da_mem[c2da_fresh14 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh14 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh14 + 3]) << 0x18)], 1)
        }
        return 1u
    } elif (key == int(uint(c2da_mem[43664]) | uint(c2da_mem[43665]) << 0x8 | uint(c2da_mem[43666]) << 0x10 | uint(c2da_mem[43667]) << 0x18)) {
        let c2da_fresh15 : int = int(uint(c2da_mem[currentMenu + 16]) | uint(c2da_mem[currentMenu + 17]) << 0x8 | uint(c2da_mem[currentMenu + 18]) << 0x10 | uint(c2da_mem[currentMenu + 19]) << 0x18) + int(itemOn) * 32 + 16
        var c2da_fresh17 : int = 0
        if (int(uint(c2da_mem[c2da_fresh15]) | uint(c2da_mem[c2da_fresh15 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh15 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh15 + 3]) << 0x18) != default<int>) {
            let c2da_fresh16 : int = int(uint(c2da_mem[currentMenu + 16]) | uint(c2da_mem[currentMenu + 17]) << 0x8 | uint(c2da_mem[currentMenu + 18]) << 0x10 | uint(c2da_mem[currentMenu + 19]) << 0x18) + int(itemOn) * 32
            if (int(int16(uint(c2da_mem[c2da_fresh16]) | uint(c2da_mem[c2da_fresh16 + 1]) << 0x8)) != 0) {
                c2da_fresh17 = 1
            }
        }
        if (c2da_fresh17 != 0) {
            let c2da_fresh18 : uint = uint(itemOn)
            c2da_mem[currentMenu + 36] = uint8(c2da_fresh18)
            c2da_mem[currentMenu + 37] = uint8(c2da_fresh18 >> 0x8)
            let c2da_fresh19 : int = int(uint(c2da_mem[currentMenu + 16]) | uint(c2da_mem[currentMenu + 17]) << 0x8 | uint(c2da_mem[currentMenu + 18]) << 0x10 | uint(c2da_mem[currentMenu + 19]) << 0x18) + int(itemOn) * 32
            if (int(int16(uint(c2da_mem[c2da_fresh19]) | uint(c2da_mem[c2da_fresh19 + 1]) << 0x8)) == 2) {
                let c2da_fresh20 : int = int(uint(c2da_mem[currentMenu + 16]) | uint(c2da_mem[currentMenu + 17]) << 0x8 | uint(c2da_mem[currentMenu + 18]) << 0x10 | uint(c2da_mem[currentMenu + 19]) << 0x18) + int(itemOn) * 32 + 16
                invoke(c2da_fn_table5[int(uint(c2da_mem[c2da_fresh20]) | uint(c2da_mem[c2da_fresh20 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh20 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh20 + 3]) << 0x18)], 1)
                S_StartSound(0, 22)
            } else {
                let c2da_fresh21 : int = int(uint(c2da_mem[currentMenu + 16]) | uint(c2da_mem[currentMenu + 17]) << 0x8 | uint(c2da_mem[currentMenu + 18]) << 0x10 | uint(c2da_mem[currentMenu + 19]) << 0x18) + int(itemOn) * 32 + 16
                invoke(c2da_fn_table5[int(uint(c2da_mem[c2da_fresh21]) | uint(c2da_mem[c2da_fresh21 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh21 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh21 + 3]) << 0x18)], int(itemOn))
                S_StartSound(0, 1)
            }
        }
        return 1u
    } elif (key == int(uint(c2da_mem[43568]) | uint(c2da_mem[43569]) << 0x8 | uint(c2da_mem[43570]) << 0x10 | uint(c2da_mem[43571]) << 0x18)) {
        let c2da_fresh22 : uint = uint(itemOn)
        c2da_mem[currentMenu + 36] = uint8(c2da_fresh22)
        c2da_mem[currentMenu + 37] = uint8(c2da_fresh22 >> 0x8)
        M_ClearMenus()
        S_StartSound(0, 24)
        return 1u
    } elif (key == int(uint(c2da_mem[43648]) | uint(c2da_mem[43649]) << 0x8 | uint(c2da_mem[43650]) << 0x10 | uint(c2da_mem[43651]) << 0x18)) {
        let c2da_fresh23 : uint = uint(itemOn)
        c2da_mem[currentMenu + 36] = uint8(c2da_fresh23)
        c2da_mem[currentMenu + 37] = uint8(c2da_fresh23 >> 0x8)
        if (int(uint(c2da_mem[currentMenu + 8]) | uint(c2da_mem[currentMenu + 9]) << 0x8 | uint(c2da_mem[currentMenu + 10]) << 0x10 | uint(c2da_mem[currentMenu + 11]) << 0x18) != 0) {
            currentMenu = int(uint(c2da_mem[currentMenu + 8]) | uint(c2da_mem[currentMenu + 9]) << 0x8 | uint(c2da_mem[currentMenu + 10]) << 0x10 | uint(c2da_mem[currentMenu + 11]) << 0x18)
            itemOn = int16(uint(c2da_mem[currentMenu + 36]) | uint(c2da_mem[currentMenu + 37]) << 0x8)
            S_StartSound(0, 23)
        }
        return 1u
    } elif (ch != 0 || uint(key == 255 || key == 128 + 58 || key == 128 + 70 || key == 128 + 69 ? 1 : 0) != 0x0) {
        i = int(itemOn) + 1
        while (i < int(int16(uint(c2da_mem[currentMenu]) | uint(c2da_mem[currentMenu + 1]) << 0x8))) {
            let c2da_fresh24 : int = int(uint(c2da_mem[currentMenu + 16]) | uint(c2da_mem[currentMenu + 17]) << 0x8 | uint(c2da_mem[currentMenu + 18]) << 0x10 | uint(c2da_mem[currentMenu + 19]) << 0x18) + i * 32 + 24
            if (int(int8(c2da_mem[c2da_fresh24])) == ch) {
                itemOn = int16(i)
                S_StartSound(0, 19)
                return 1u
            }
            i++
        }
        i = 0
        while (i <= int(itemOn)) {
            let c2da_fresh25 : int = int(uint(c2da_mem[currentMenu + 16]) | uint(c2da_mem[currentMenu + 17]) << 0x8 | uint(c2da_mem[currentMenu + 18]) << 0x10 | uint(c2da_mem[currentMenu + 19]) << 0x18) + i * 32 + 24
            if (int(int8(c2da_mem[c2da_fresh25])) == ch) {
                itemOn = int16(i)
                S_StartSound(0, 19)
                return 1u
            }
            i++
        }
    }
    return 0u
}
var itemOn : int16 = default<int16>

var currentMenu : int = default<int>

[sideeffects]
def private IsNullKey(var key_0 : int) : uint {
    return uint(key_0 == 255 || key_0 == 128 + 58 || key_0 == 128 + 70 || key_0 == 128 + 69 ? 1 : 0)
}
[export, sideeffects]
def M_ClearMenus() {
    menuactive = 0u
    return
}
[export, sideeffects]
def M_StartControlPanel() {
    if (menuactive != 0x0) {
        return
    }
    menuactive = 1u
    currentMenu = 44576
    itemOn = int16(uint(c2da_mem[currentMenu + 36]) | uint(c2da_mem[currentMenu + 37]) << 0x8)
    return
}
[export, sideeffects]
def M_DrawMainMenu() {
    V_DrawPatchDirect(94, 2, W_CacheLumpName(357544, 8))
    return
}
[export, sideeffects]
def M_QuitDOOM(var choice : int) {
    c2da_lin_snprintf(44816, 160ul, 357551, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(M_SelectEndMessage()))])
    M_StartMessage(44816, 89, 1u)
    return
}
[export, sideeffects]
def M_QuitResponse(var key_1 : int) {
    if (key_1 != int(uint(c2da_mem[43680]) | uint(c2da_mem[43681]) << 0x8 | uint(c2da_mem[43682]) << 0x10 | uint(c2da_mem[43683]) << 0x18)) {
        return
    }
    if (netgame == 0) {
        if (uint(gamemode) == 2u) {
            S_StartSound(0, quitsounds2[int(gametic >> 2 & 7)])
        } else {
            S_StartSound(0, quitsounds[int(gametic >> 2 & 7)])
        }
        I_WaitVBL(105)
    }
    I_Quit()
    return
}
var quitsounds : int[8] = fixed_array<int>(57, 26, 27, 31, 35, 36, 38, 52)

var quitsounds2 : int[8] = fixed_array<int>(80, 93, 95, 31, 56, 72, 78, 52)

[export, sideeffects]
def M_StartMessage(var string_0 : int; var routine : int; var input : uint) {
    messageLastMenuActive = int(menuactive)
    messageToPrint = 1
    messageString = int(string_0)  // nolint:PERF020
    messageRoutine = int(routine)  // nolint:PERF020
    messageNeedsInput = uint(input)  // nolint:PERF020
    menuactive = 1u
    return
}
var messageNeedsInput : uint = default<uint>

var messageRoutine : int = default<int>

var messageString : int = default<int>

var messageToPrint : int = default<int>

var messageLastMenuActive : int = default<int>

[sideeffects]
def private M_SelectEndMessage() : int {
    var endmsg : int
    if (((uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 4u ? 0u : (uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 5u ? 1u : uint(c2da_mem[2064]) | uint(c2da_mem[2065]) << 0x8 | uint(c2da_mem[2066]) << 0x10 | uint(c2da_mem[2067]) << 0x18) == 0u) {
        endmsg = 44976
    } else {
        endmsg = 45040
    }
    let c2da_fresh26 : int = endmsg + int(gametic % 8) * 8
    return int(uint(c2da_mem[c2da_fresh26]) | uint(c2da_mem[c2da_fresh26 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh26 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh26 + 3]) << 0x18)
}
[export, sideeffects]
def M_ReadThis(var choice_0 : int) {
    choice_0 = 0
    M_SetupNextMenu(44336)
    return
}
[export, sideeffects]
def M_DrawReadThis1() {
    var c2da_fresh27 : uint
    var lumpname : int
    var skullx : int
    var skully : int
    lumpname = 357581
    skullx = 330
    skully = 175
    inhelpscreens = 1u
    c2da_fresh27 = uint(gameversion)
    if (c2da_fresh27 >= 0x1u && c2da_fresh27 <= 0x9u) {
        goto int(c2da_fresh27 - 0x1u) + 2
    }
    goto label 0
    label 2:
    label 3:
    label 4:
    label 5:
    label 6:
    if (uint(gamemode) == 2u) {
        lumpname = 357588
        skullx = 330
        skully = 165
    } else {
        lumpname = 357593
        skullx = 280
        skully = 185
    }
    goto label 1
    label 7:
    label 10:
    lumpname = 357599
    goto label 1
    label 8:
    label 9:
    lumpname = 357588
    goto label 1
    label 0:
    I_Error(357605, [])
    label 1:
    V_DrawPatchDirect(0, 0, W_CacheLumpName(lumpname, 8))
    let c2da_fresh28 : int16 = int16(skullx)
    let c2da_fresh29 : uint = uint(c2da_fresh28)
    c2da_mem[44368] = uint8(c2da_fresh29)
    c2da_mem[44369] = uint8(c2da_fresh29 >> 0x8)
    let c2da_fresh30 : int16 = int16(skully)
    let c2da_fresh31 : uint = uint(c2da_fresh30)
    c2da_mem[44370] = uint8(c2da_fresh31)
    c2da_mem[44371] = uint8(c2da_fresh31 >> 0x8)
    return
}
var inhelpscreens : uint = default<uint>

[export, sideeffects]
def M_ReadThis2(var choice_1 : int) {
    if (uint(gameversion) <= 4u && uint(gamemode) != 2u) {
        choice_1 = 0
        M_SetupNextMenu(44288)
    } else {
        M_FinishReadThis(0)
    }
    return
}
[export, sideeffects]
def M_FinishReadThis(var choice_2 : int) {
    choice_2 = 0
    M_SetupNextMenu(44576)
    return
}
[export, sideeffects]
def M_SetupNextMenu(var menudef : int) {
    currentMenu = int(menudef)  // nolint:PERF020
    itemOn = int16(uint(c2da_mem[currentMenu + 36]) | uint(c2da_mem[currentMenu + 37]) << 0x8)
    return
}
[export, sideeffects]
def M_DrawReadThis2() {
    inhelpscreens = 1u
    V_DrawPatchDirect(0, 0, W_CacheLumpName(357599, 8))
    return
}
[export, sideeffects]
def M_SaveGame(var choice_3 : int) {
    if (usergame == 0) {
        M_StartMessage(357628, 0, 0u)
        return
    }
    if (uint(gamestate) != 0u) {
        return
    }
    M_SetupNextMenu(45168)
    M_ReadSaveStrings()
    return
}
[export, sideeffects]
def M_ReadSaveStrings() {
    let c2da_saved_sp : int = c2da_lin_sp
    M_ReadSaveStrings_c2da_frame(c2da_lin_enter(256))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def M_LoadSelect(var choice_4 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    M_LoadSelect_c2da_frame(choice_4, c2da_lin_enter(256))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def M_DrawSave() {
    var i_1 : int
    V_DrawPatchDirect(72, 28, W_CacheLumpName(357694, 8))
    i_1 = 0
    while (i_1 < 6) {
        M_DrawSaveLoadBorder(int(int16(uint(c2da_mem[45632]) | uint(c2da_mem[45633]) << 0x8)), int(int16(uint(c2da_mem[45634]) | uint(c2da_mem[45635]) << 0x8)) + 16 * i_1)
        M_WriteText(int(int16(uint(c2da_mem[45632]) | uint(c2da_mem[45633]) << 0x8)), int(int16(uint(c2da_mem[45634]) | uint(c2da_mem[45635]) << 0x8)) + 16 * i_1, 44016 + i_1 * 24)
        i_1++
    }
    if (saveStringEnter != 0) {
        i_1 = M_StringWidth(44016 + saveSlot * 24)
        M_WriteText(int(int16(uint(c2da_mem[45632]) | uint(c2da_mem[45633]) << 0x8)) + i_1, int(int16(uint(c2da_mem[45634]) | uint(c2da_mem[45635]) << 0x8)) + 16 * saveSlot, 357702)
    }
    return
}
var saveSlot : int = default<int>

[export, sideeffects]
def M_DrawLoad() {
    V_DrawPatchDirect(72, 28, W_CacheLumpName(357704, 8))
    for (i_2 in range(0, 6)) {
        M_DrawSaveLoadBorder(int(int16(uint(c2da_mem[45632]) | uint(c2da_mem[45633]) << 0x8)), int(int16(uint(c2da_mem[45634]) | uint(c2da_mem[45635]) << 0x8)) + 16 * i_2)
        M_WriteText(int(int16(uint(c2da_mem[45632]) | uint(c2da_mem[45633]) << 0x8)), int(int16(uint(c2da_mem[45634]) | uint(c2da_mem[45635]) << 0x8)) + 16 * i_2, 44016 + i_2 * 24)
    }
    return
}
[export, sideeffects]
def M_WriteText(var x : int; var y : int; var string_1 : int) {
    var w : int
    var ch_0 : int
    var c : int
    var cx : int
    var cy : int
    ch_0 = string_1
    cx = x
    cy = y
    while (true) {
        let c2da_fresh36 : int = ch_0
        ch_0++
        c = int(int8(c2da_mem[c2da_fresh36]))
        if (c == 0) {
            break
        }
        if (c == 10) {
            cx = x
            cy += 12
            continue
        }
        c = c2da_std_toupper(c) - 33
        if (c < 0 || c >= 95 - 33 + 1) {
            cx += 4
            continue
        }
        let c2da_fresh37 : int = int(uint(c2da_mem[41520 + c * 8]) | uint(c2da_mem[41520 + c * 8 + 1]) << 0x8 | uint(c2da_mem[41520 + c * 8 + 2]) << 0x10 | uint(c2da_mem[41520 + c * 8 + 3]) << 0x18)
        w = int(int16(uint(c2da_mem[c2da_fresh37]) | uint(c2da_mem[c2da_fresh37 + 1]) << 0x8))
        if (cx + w > 320) {
            break
        }
        V_DrawPatchDirect(cx, cy, int(uint(c2da_mem[41520 + c * 8]) | uint(c2da_mem[41520 + c * 8 + 1]) << 0x8 | uint(c2da_mem[41520 + c * 8 + 2]) << 0x10 | uint(c2da_mem[41520 + c * 8 + 3]) << 0x18))
        cx += w
    }
    return
}
[export, sideeffects]
def M_DrawSaveLoadBorder(var x_0 : int; var y_0 : int) {
    V_DrawPatchDirect(x_0 - 8, y_0 + 7, W_CacheLumpName(357712, 8))
    for (i_3 in range(0, 24)) {
        V_DrawPatchDirect(x_0, y_0 + 7, W_CacheLumpName(357721, 8))
        x_0 += 8
    }
    V_DrawPatchDirect(x_0, y_0 + 7, W_CacheLumpName(357730, 8))
    return
}
[export, sideeffects]
def M_StringWidth(var string_2 : int) : int {
    var i_4 : uint64
    var w_0 : int
    var c_0 : int
    w_0 = 0
    i_4 = 0ul
    while (i_4 < c2da_lin_strlen(string_2)) {
        c_0 = c2da_std_toupper(int(int8(c2da_mem[string_2 + int(i_4)]))) - 33
        if (c_0 < 0 || c_0 >= 95 - 33 + 1) {
            w_0 += 4
        } else {
            let c2da_fresh38 : int = int(uint(c2da_mem[41520 + c_0 * 8]) | uint(c2da_mem[41520 + c_0 * 8 + 1]) << 0x8 | uint(c2da_mem[41520 + c_0 * 8 + 2]) << 0x10 | uint(c2da_mem[41520 + c_0 * 8 + 3]) << 0x18)
            w_0 += int(int16(uint(c2da_mem[c2da_fresh38]) | uint(c2da_mem[c2da_fresh38 + 1]) << 0x8))
        }
        i_4++
    }
    return w_0
}
var saveStringEnter : int = default<int>

[export, sideeffects]
def M_SaveSelect(var choice_5 : int) {
    saveStringEnter = 1
    saveSlot = int(choice_5)  // nolint:PERF020
    M_StringCopy(44256, 44016 + choice_5 * 24, 24ul)
    if (c2da_lin_strcmp(44016 + choice_5 * 24, 357683) == 0) {
        let c2da_fresh39 : int8 = int8(0)
        c2da_mem[44016 + choice_5 * 24 + 0] = uint8(c2da_fresh39)
    }
    saveCharIndex = int(c2da_lin_strlen(44016 + choice_5 * 24))
    return
}
var saveCharIndex : int = default<int>

[export, sideeffects]
def M_LoadGame(var choice_6 : int) {
    if (netgame != 0x0) {
        M_StartMessage(357739, 0, 0u)
        return
    }
    M_SetupNextMenu(45600)
    M_ReadSaveStrings()
    return
}
[export, sideeffects]
def M_Options(var choice_7 : int) {
    M_SetupNextMenu(45648)
    return
}
[export, sideeffects]
def M_DrawOptions() {
    V_DrawPatchDirect(108, 15, W_CacheLumpName(357792, 8))
    V_DrawPatchDirect(int(int16(uint(c2da_mem[45680]) | uint(c2da_mem[45681]) << 0x8)) + 175, int(int16(uint(c2da_mem[45682]) | uint(c2da_mem[45683]) << 0x8)) + 16 * 2, W_CacheLumpName(detailNames[int(uint(c2da_mem[1904]) | uint(c2da_mem[1905]) << 0x8 | uint(c2da_mem[1906]) << 0x10 | uint(c2da_mem[1907]) << 0x18)], 8))
    V_DrawPatchDirect(int(int16(uint(c2da_mem[45680]) | uint(c2da_mem[45681]) << 0x8)) + 120, int(int16(uint(c2da_mem[45682]) | uint(c2da_mem[45683]) << 0x8)) + 16 * 1, W_CacheLumpName(msgNames[int(uint(c2da_mem[1872]) | uint(c2da_mem[1873]) << 0x8 | uint(c2da_mem[1874]) << 0x10 | uint(c2da_mem[1875]) << 0x18)], 8))
    M_DrawThermo(int(int16(uint(c2da_mem[45680]) | uint(c2da_mem[45681]) << 0x8)), int(int16(uint(c2da_mem[45682]) | uint(c2da_mem[45683]) << 0x8)) + 16 * (5 + 1), 10, int(uint(c2da_mem[1824]) | uint(c2da_mem[1825]) << 0x8 | uint(c2da_mem[1826]) << 0x10 | uint(c2da_mem[1827]) << 0x18))
    M_DrawThermo(int(int16(uint(c2da_mem[45680]) | uint(c2da_mem[45681]) << 0x8)), int(int16(uint(c2da_mem[45682]) | uint(c2da_mem[45683]) << 0x8)) + 16 * (3 + 1), 9, screenSize)
    return
}
var screenSize : int = default<int>

[export, sideeffects]
def M_DrawThermo(var x_1 : int; var y_1 : int; var thermWidth : int; var thermDot : int) {
    var xx : int = x_1
    V_DrawPatchDirect(xx, y_1, W_CacheLumpName(357801, 8))
    xx += 8
    for (i_5 in range(0, thermWidth)) {
        V_DrawPatchDirect(xx, y_1, W_CacheLumpName(357810, 8))
        xx += 8
    }
    V_DrawPatchDirect(xx, y_1, W_CacheLumpName(357819, 8))
    V_DrawPatchDirect(x_1 + 8 + thermDot * 8, y_1, W_CacheLumpName(357828, 8))
    return
}
var private msgNames : int[2] = fixed_array<int>(357837, 357846)

var private detailNames : int[2] = fixed_array<int>(357854, 357863)

[export, sideeffects]
def M_Sound(var choice_8 : int) {
    M_SetupNextMenu(44384)
    return
}
[export, sideeffects]
def M_DrawSound() {
    V_DrawPatchDirect(60, 38, W_CacheLumpName(357871, 8))
    M_DrawThermo(int(int16(uint(c2da_mem[44416]) | uint(c2da_mem[44417]) << 0x8)), int(int16(uint(c2da_mem[44418]) | uint(c2da_mem[44419]) << 0x8)) + 16 * (0 + 1), 16, int(uint(c2da_mem[1840]) | uint(c2da_mem[1841]) << 0x8 | uint(c2da_mem[1842]) << 0x10 | uint(c2da_mem[1843]) << 0x18))
    M_DrawThermo(int(int16(uint(c2da_mem[44416]) | uint(c2da_mem[44417]) << 0x8)), int(int16(uint(c2da_mem[44418]) | uint(c2da_mem[44419]) << 0x8)) + 16 * (2 + 1), 16, int(uint(c2da_mem[1856]) | uint(c2da_mem[1857]) << 0x8 | uint(c2da_mem[1858]) << 0x10 | uint(c2da_mem[1859]) << 0x18))
    return
}
[export, sideeffects]
def M_MusicVol(var choice_9 : int) {
    if (choice_9 == 0) {
        if (int(uint(c2da_mem[1856]) | uint(c2da_mem[1857]) << 0x8 | uint(c2da_mem[1858]) << 0x10 | uint(c2da_mem[1859]) << 0x18) != 0) {
            let c2da_fresh40 : int = int(uint(c2da_mem[1856]) | uint(c2da_mem[1857]) << 0x8 | uint(c2da_mem[1858]) << 0x10 | uint(c2da_mem[1859]) << 0x18)
            let c2da_fresh41 : int = c2da_fresh40 - 1
            let c2da_fresh42 : uint = uint(c2da_fresh41)
            c2da_mem[1856] = uint8(c2da_fresh42)
            c2da_mem[1857] = uint8(c2da_fresh42 >> 0x8)
            c2da_mem[1858] = uint8(c2da_fresh42 >> 0x10)
            c2da_mem[1859] = uint8(c2da_fresh42 >> 0x18)
        }
    } elif (choice_9 == 1) {
        if (int(uint(c2da_mem[1856]) | uint(c2da_mem[1857]) << 0x8 | uint(c2da_mem[1858]) << 0x10 | uint(c2da_mem[1859]) << 0x18) < 15) {
            let c2da_fresh43 : int = int(uint(c2da_mem[1856]) | uint(c2da_mem[1857]) << 0x8 | uint(c2da_mem[1858]) << 0x10 | uint(c2da_mem[1859]) << 0x18)
            let c2da_fresh44 : int = c2da_fresh43 + 1
            let c2da_fresh45 : uint = uint(c2da_fresh44)
            c2da_mem[1856] = uint8(c2da_fresh45)
            c2da_mem[1857] = uint8(c2da_fresh45 >> 0x8)
            c2da_mem[1858] = uint8(c2da_fresh45 >> 0x10)
            c2da_mem[1859] = uint8(c2da_fresh45 >> 0x18)
        }
    }
    S_SetMusicVolume(int(uint(c2da_mem[1856]) | uint(c2da_mem[1857]) << 0x8 | uint(c2da_mem[1858]) << 0x10 | uint(c2da_mem[1859]) << 0x18) * 8)
    return
}
[export, sideeffects]
def M_SfxVol(var choice_10 : int) {
    if (choice_10 == 0) {
        if (int(uint(c2da_mem[1840]) | uint(c2da_mem[1841]) << 0x8 | uint(c2da_mem[1842]) << 0x10 | uint(c2da_mem[1843]) << 0x18) != 0) {
            let c2da_fresh46 : int = int(uint(c2da_mem[1840]) | uint(c2da_mem[1841]) << 0x8 | uint(c2da_mem[1842]) << 0x10 | uint(c2da_mem[1843]) << 0x18)
            let c2da_fresh47 : int = c2da_fresh46 - 1
            let c2da_fresh48 : uint = uint(c2da_fresh47)
            c2da_mem[1840] = uint8(c2da_fresh48)
            c2da_mem[1841] = uint8(c2da_fresh48 >> 0x8)
            c2da_mem[1842] = uint8(c2da_fresh48 >> 0x10)
            c2da_mem[1843] = uint8(c2da_fresh48 >> 0x18)
        }
    } elif (choice_10 == 1) {
        if (int(uint(c2da_mem[1840]) | uint(c2da_mem[1841]) << 0x8 | uint(c2da_mem[1842]) << 0x10 | uint(c2da_mem[1843]) << 0x18) < 15) {
            let c2da_fresh49 : int = int(uint(c2da_mem[1840]) | uint(c2da_mem[1841]) << 0x8 | uint(c2da_mem[1842]) << 0x10 | uint(c2da_mem[1843]) << 0x18)
            let c2da_fresh50 : int = c2da_fresh49 + 1
            let c2da_fresh51 : uint = uint(c2da_fresh50)
            c2da_mem[1840] = uint8(c2da_fresh51)
            c2da_mem[1841] = uint8(c2da_fresh51 >> 0x8)
            c2da_mem[1842] = uint8(c2da_fresh51 >> 0x10)
            c2da_mem[1843] = uint8(c2da_fresh51 >> 0x18)
        }
    }
    S_SetSfxVolume(int(uint(c2da_mem[1840]) | uint(c2da_mem[1841]) << 0x8 | uint(c2da_mem[1842]) << 0x10 | uint(c2da_mem[1843]) << 0x18) * 8)
    return
}
[export, sideeffects]
def M_ChangeSensitivity(var choice_11 : int) {
    if (choice_11 == 0) {
        if (int(uint(c2da_mem[1824]) | uint(c2da_mem[1825]) << 0x8 | uint(c2da_mem[1826]) << 0x10 | uint(c2da_mem[1827]) << 0x18) != 0) {
            let c2da_fresh52 : int = int(uint(c2da_mem[1824]) | uint(c2da_mem[1825]) << 0x8 | uint(c2da_mem[1826]) << 0x10 | uint(c2da_mem[1827]) << 0x18)
            let c2da_fresh53 : int = c2da_fresh52 - 1
            let c2da_fresh54 : uint = uint(c2da_fresh53)
            c2da_mem[1824] = uint8(c2da_fresh54)
            c2da_mem[1825] = uint8(c2da_fresh54 >> 0x8)
            c2da_mem[1826] = uint8(c2da_fresh54 >> 0x10)
            c2da_mem[1827] = uint8(c2da_fresh54 >> 0x18)
        }
    } elif (choice_11 == 1) {
        if (int(uint(c2da_mem[1824]) | uint(c2da_mem[1825]) << 0x8 | uint(c2da_mem[1826]) << 0x10 | uint(c2da_mem[1827]) << 0x18) < 9) {
            let c2da_fresh55 : int = int(uint(c2da_mem[1824]) | uint(c2da_mem[1825]) << 0x8 | uint(c2da_mem[1826]) << 0x10 | uint(c2da_mem[1827]) << 0x18)
            let c2da_fresh56 : int = c2da_fresh55 + 1
            let c2da_fresh57 : uint = uint(c2da_fresh56)
            c2da_mem[1824] = uint8(c2da_fresh57)
            c2da_mem[1825] = uint8(c2da_fresh57 >> 0x8)
            c2da_mem[1826] = uint8(c2da_fresh57 >> 0x10)
            c2da_mem[1827] = uint8(c2da_fresh57 >> 0x18)
        }
    }
    return
}
[export, sideeffects]
def M_SizeDisplay(var choice_12 : int) {
    if (choice_12 == 0) {
        if (screenSize > 0) {
            let c2da_fresh58 : int = int(uint(c2da_mem[1888]) | uint(c2da_mem[1889]) << 0x8 | uint(c2da_mem[1890]) << 0x10 | uint(c2da_mem[1891]) << 0x18)
            let c2da_fresh59 : int = c2da_fresh58 - 1
            let c2da_fresh60 : uint = uint(c2da_fresh59)
            c2da_mem[1888] = uint8(c2da_fresh60)
            c2da_mem[1889] = uint8(c2da_fresh60 >> 0x8)
            c2da_mem[1890] = uint8(c2da_fresh60 >> 0x10)
            c2da_mem[1891] = uint8(c2da_fresh60 >> 0x18)
            screenSize--
        }
    } elif (choice_12 == 1) {
        if (screenSize < 8) {
            let c2da_fresh61 : int = int(uint(c2da_mem[1888]) | uint(c2da_mem[1889]) << 0x8 | uint(c2da_mem[1890]) << 0x10 | uint(c2da_mem[1891]) << 0x18)
            let c2da_fresh62 : int = c2da_fresh61 + 1
            let c2da_fresh63 : uint = uint(c2da_fresh62)
            c2da_mem[1888] = uint8(c2da_fresh63)
            c2da_mem[1889] = uint8(c2da_fresh63 >> 0x8)
            c2da_mem[1890] = uint8(c2da_fresh63 >> 0x10)
            c2da_mem[1891] = uint8(c2da_fresh63 >> 0x18)
            screenSize++
        }
    }
    R_SetViewSize(int(uint(c2da_mem[1888]) | uint(c2da_mem[1889]) << 0x8 | uint(c2da_mem[1890]) << 0x10 | uint(c2da_mem[1891]) << 0x18), int(uint(c2da_mem[1904]) | uint(c2da_mem[1905]) << 0x8 | uint(c2da_mem[1906]) << 0x10 | uint(c2da_mem[1907]) << 0x18))
    return
}
[export, sideeffects]
def M_ChangeDetail(var choice_13 : int) {
    choice_13 = 0
    let c2da_fresh64 : int = 1 - int(uint(c2da_mem[1904]) | uint(c2da_mem[1905]) << 0x8 | uint(c2da_mem[1906]) << 0x10 | uint(c2da_mem[1907]) << 0x18)
    let c2da_fresh65 : uint = uint(c2da_fresh64)
    c2da_mem[1904] = uint8(c2da_fresh65)
    c2da_mem[1905] = uint8(c2da_fresh65 >> 0x8)
    c2da_mem[1906] = uint8(c2da_fresh65 >> 0x10)
    c2da_mem[1907] = uint8(c2da_fresh65 >> 0x18)
    R_SetViewSize(int(uint(c2da_mem[1888]) | uint(c2da_mem[1889]) << 0x8 | uint(c2da_mem[1890]) << 0x10 | uint(c2da_mem[1891]) << 0x18), int(uint(c2da_mem[1904]) | uint(c2da_mem[1905]) << 0x8 | uint(c2da_mem[1906]) << 0x10 | uint(c2da_mem[1907]) << 0x18))
    if (int(uint(c2da_mem[1904]) | uint(c2da_mem[1905]) << 0x8 | uint(c2da_mem[1906]) << 0x10 | uint(c2da_mem[1907]) << 0x18) == 0) {
        let c2da_fresh66 : uint = 357878u
        c2da_mem[96 + int(consoleplayer) * 328 + 232] = uint8(c2da_fresh66)
        c2da_mem[96 + int(consoleplayer) * 328 + 233] = uint8(c2da_fresh66 >> 0x8)
        c2da_mem[96 + int(consoleplayer) * 328 + 234] = uint8(c2da_fresh66 >> 0x10)
        c2da_mem[96 + int(consoleplayer) * 328 + 235] = uint8(c2da_fresh66 >> 0x18)
        c2da_mem[96 + int(consoleplayer) * 328 + 236] = 0u8
        c2da_mem[96 + int(consoleplayer) * 328 + 237] = 0u8
        c2da_mem[96 + int(consoleplayer) * 328 + 238] = 0u8
        c2da_mem[96 + int(consoleplayer) * 328 + 239] = 0u8
    } else {
        let c2da_fresh67 : uint = 357890u
        c2da_mem[96 + int(consoleplayer) * 328 + 232] = uint8(c2da_fresh67)
        c2da_mem[96 + int(consoleplayer) * 328 + 233] = uint8(c2da_fresh67 >> 0x8)
        c2da_mem[96 + int(consoleplayer) * 328 + 234] = uint8(c2da_fresh67 >> 0x10)
        c2da_mem[96 + int(consoleplayer) * 328 + 235] = uint8(c2da_fresh67 >> 0x18)
        c2da_mem[96 + int(consoleplayer) * 328 + 236] = 0u8
        c2da_mem[96 + int(consoleplayer) * 328 + 237] = 0u8
        c2da_mem[96 + int(consoleplayer) * 328 + 238] = 0u8
        c2da_mem[96 + int(consoleplayer) * 328 + 239] = 0u8
    }
    return
}
[export, sideeffects]
def M_ChangeMessages(var choice_14 : int) {
    choice_14 = 0
    let c2da_fresh68 : int = 1 - int(uint(c2da_mem[1872]) | uint(c2da_mem[1873]) << 0x8 | uint(c2da_mem[1874]) << 0x10 | uint(c2da_mem[1875]) << 0x18)
    let c2da_fresh69 : uint = uint(c2da_fresh68)
    c2da_mem[1872] = uint8(c2da_fresh69)
    c2da_mem[1873] = uint8(c2da_fresh69 >> 0x8)
    c2da_mem[1874] = uint8(c2da_fresh69 >> 0x10)
    c2da_mem[1875] = uint8(c2da_fresh69 >> 0x18)
    if (int(uint(c2da_mem[1872]) | uint(c2da_mem[1873]) << 0x8 | uint(c2da_mem[1874]) << 0x10 | uint(c2da_mem[1875]) << 0x18) == 0) {
        let c2da_fresh70 : uint = 357901u
        c2da_mem[96 + int(consoleplayer) * 328 + 232] = uint8(c2da_fresh70)
        c2da_mem[96 + int(consoleplayer) * 328 + 233] = uint8(c2da_fresh70 >> 0x8)
        c2da_mem[96 + int(consoleplayer) * 328 + 234] = uint8(c2da_fresh70 >> 0x10)
        c2da_mem[96 + int(consoleplayer) * 328 + 235] = uint8(c2da_fresh70 >> 0x18)
        c2da_mem[96 + int(consoleplayer) * 328 + 236] = 0u8
        c2da_mem[96 + int(consoleplayer) * 328 + 237] = 0u8
        c2da_mem[96 + int(consoleplayer) * 328 + 238] = 0u8
        c2da_mem[96 + int(consoleplayer) * 328 + 239] = 0u8
    } else {
        let c2da_fresh71 : uint = 357914u
        c2da_mem[96 + int(consoleplayer) * 328 + 232] = uint8(c2da_fresh71)
        c2da_mem[96 + int(consoleplayer) * 328 + 233] = uint8(c2da_fresh71 >> 0x8)
        c2da_mem[96 + int(consoleplayer) * 328 + 234] = uint8(c2da_fresh71 >> 0x10)
        c2da_mem[96 + int(consoleplayer) * 328 + 235] = uint8(c2da_fresh71 >> 0x18)
        c2da_mem[96 + int(consoleplayer) * 328 + 236] = 0u8
        c2da_mem[96 + int(consoleplayer) * 328 + 237] = 0u8
        c2da_mem[96 + int(consoleplayer) * 328 + 238] = 0u8
        c2da_mem[96 + int(consoleplayer) * 328 + 239] = 0u8
    }
    message_dontfuckwithme = 1u
    return
}
[export, sideeffects]
def M_EndGame(var choice_15 : int) {
    choice_15 = 0
    if (usergame == 0) {
        S_StartSound(0, 34)
        return
    }
    if (netgame != 0x0) {
        M_StartMessage(357926, 0, 0u)
        return
    }
    M_StartMessage(357965, 115, 1u)
    return
}
[export, sideeffects]
def M_EndGameResponse(var key_2 : int) {
    if (key_2 != int(uint(c2da_mem[43680]) | uint(c2da_mem[43681]) << 0x8 | uint(c2da_mem[43682]) << 0x10 | uint(c2da_mem[43683]) << 0x18)) {
        return
    }
    let c2da_fresh72 : uint = uint(itemOn)
    c2da_mem[currentMenu + 36] = uint8(c2da_fresh72)
    c2da_mem[currentMenu + 37] = uint8(c2da_fresh72 >> 0x8)
    M_ClearMenus()
    D_StartTitle()
    return
}
[export, sideeffects]
def M_NewGame(var choice_16 : int) {
    if (netgame != 0x0 && demoplayback == 0) {
        M_StartMessage(358019, 0, 0u)
        return
    }
    if (uint(gamemode) == 2u || uint(gameversion) == 9u) {
        M_SetupNextMenu(46080)
    } else {
        M_SetupNextMenu(46128)
    }
    return
}
[export, sideeffects]
def M_DrawEpisode() {
    V_DrawPatchDirect(54, 38, W_CacheLumpName(358085, 8))
    return
}
[export, sideeffects]
def M_Episode(var choice_17 : int) {
    if (uint(gamemode) == 0u && choice_17 != 0) {
        M_StartMessage(358094, 0, 0u)
        M_SetupNextMenu(44336)
        return
    }
    if (uint(gamemode) == 1u && choice_17 > 2) {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 358186, [])
        choice_17 = 0
    }
    epi = int(choice_17)  // nolint:PERF020
    M_SetupNextMenu(46080)
    return
}
[export, sideeffects]
def M_DrawNewGame() {
    V_DrawPatchDirect(96, 14, W_CacheLumpName(358232, 8))
    V_DrawPatchDirect(54, 38, W_CacheLumpName(358239, 8))
    return
}
[export, sideeffects]
def M_ChooseSkill(var choice_18 : int) {
    if (choice_18 == 4) {
        M_StartMessage(358247, 120, 1u)
        return
    }
    G_DeferedInitNew(choice_18, epi + 1, 1)
    M_ClearMenus()
    return
}
var epi : int = default<int>

[export, sideeffects]
def M_VerifyNightmare(var key_3 : int) {
    if (key_3 != int(uint(c2da_mem[43680]) | uint(c2da_mem[43681]) << 0x8 | uint(c2da_mem[43682]) << 0x10 | uint(c2da_mem[43683]) << 0x18)) {
        return
    }
    G_DeferedInitNew(4, epi + 1, 1)
    M_ClearMenus()
    return
}
[export, sideeffects]
def M_QuickLoad() {
    if (netgame != 0x0) {
        M_StartMessage(358319, 0, 0u)
        return
    }
    if (quickSaveSlot < 0) {
        M_StartMessage(358371, 0, 0u)
        return
    }
    c2da_lin_snprintf(46464, 80ul, 358426, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(44016 + quickSaveSlot * 24))])
    M_StartMessage(46464, 121, 1u)
    return
}
[export, sideeffects]
def M_QuickLoadResponse(var key_4 : int) {
    if (key_4 == int(uint(c2da_mem[43680]) | uint(c2da_mem[43681]) << 0x8 | uint(c2da_mem[43682]) << 0x10 | uint(c2da_mem[43683]) << 0x18)) {
        M_LoadSelect(quickSaveSlot)
        S_StartSound(0, 24)
    }
    return
}
var quickSaveSlot : int = default<int>

[export, sideeffects]
def M_QuickSave() {
    if (usergame == 0) {
        S_StartSound(0, 34)
        return
    }
    if (uint(gamestate) != 0u) {
        return
    }
    if (quickSaveSlot < 0) {
        M_StartControlPanel()
        M_ReadSaveStrings()
        M_SetupNextMenu(45168)
        quickSaveSlot = -2
        return
    }
    c2da_lin_snprintf(46464, 80ul, 358488, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(44016 + quickSaveSlot * 24))])
    M_StartMessage(46464, 122, 1u)
    return
}
[export, sideeffects]
def M_QuickSaveResponse(var key_5 : int) {
    if (key_5 == int(uint(c2da_mem[43680]) | uint(c2da_mem[43681]) << 0x8 | uint(c2da_mem[43682]) << 0x10 | uint(c2da_mem[43683]) << 0x18)) {
        M_DoSave(quickSaveSlot)
        S_StartSound(0, 24)
    }
    return
}
[export, sideeffects]
def M_DoSave(var slot : int) {
    G_SaveGame(slot, 44016 + slot * 24)
    M_ClearMenus()
    if (quickSaveSlot == -2) {
        quickSaveSlot = int(slot)  // nolint:PERF020
    }
    return
}
[export, sideeffects]
def M_Ticker() {
    skullAnimCounter = int16(int(skullAnimCounter) - 1)
    if (int(skullAnimCounter) <= 0) {
        whichSkull = int16(int(whichSkull) ^ 1)
        skullAnimCounter = int16(8)
    }
    return
}
var skullAnimCounter : int16 = default<int16>

var whichSkull : int16 = default<int16>

[export, sideeffects]
def M_Drawer() {
    let c2da_saved_sp : int = c2da_lin_sp
    M_Drawer_c2da_frame(c2da_lin_enter(80))
    c2da_lin_sp = c2da_saved_sp
}
var skullName : int[2] = fixed_array<int>(358541, 358550)

[export, sideeffects]
def M_StringHeight(var string_3 : int) : int {
    var i_7 : uint64
    var h : int
    var height : int
    let c2da_fresh75 : int = int(uint(c2da_mem[41520 + 0 * 8]) | uint(c2da_mem[41520 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[41520 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[41520 + 0 * 8 + 3]) << 0x18) + 2
    height = int(int16(uint(c2da_mem[c2da_fresh75]) | uint(c2da_mem[c2da_fresh75 + 1]) << 0x8))
    h = height
    i_7 = 0ul
    while (i_7 < c2da_lin_strlen(string_3)) {
        if (int(int8(c2da_mem[string_3 + int(i_7)])) == 10) {
            h += height
        }
        i_7++
    }
    return h
}
[export, sideeffects]
def M_Init() {
    var c2da_fresh76 : uint
    currentMenu = 44576
    menuactive = 0u
    itemOn = int16(uint(c2da_mem[currentMenu + 36]) | uint(c2da_mem[currentMenu + 37]) << 0x8)
    whichSkull = int16(0)
    skullAnimCounter = int16(10)
    screenSize = int(uint(c2da_mem[1888]) | uint(c2da_mem[1889]) << 0x8 | uint(c2da_mem[1890]) << 0x10 | uint(c2da_mem[1891]) << 0x18) - 3
    messageToPrint = 0
    messageString = 0
    messageLastMenuActive = int(menuactive)
    quickSaveSlot = -1
    c2da_fresh76 = uint(gamemode)
    if (c2da_fresh76 == 0x2u) {
        c2da_lin_memmove(44624 + 4 * 32, 44624 + 5 * 32, 32ul)
        let c2da_fresh77 : int16 = int16(uint(c2da_mem[44576]) | uint(c2da_mem[44577]) << 0x8)
        let c2da_fresh78 : int16 = int16(int(c2da_fresh77) - 1)
        let c2da_fresh79 : uint = uint(c2da_fresh78)
        c2da_mem[44576] = uint8(c2da_fresh79)
        c2da_mem[44577] = uint8(c2da_fresh79 >> 0x8)
        let c2da_fresh80 : int16 = int16(int(int16(uint(c2da_mem[44610]) | uint(c2da_mem[44611]) << 0x8)) + 8)
        let c2da_fresh81 : uint = uint(c2da_fresh80)
        c2da_mem[44610] = uint8(c2da_fresh81)
        c2da_mem[44611] = uint8(c2da_fresh81 >> 0x8)
        let c2da_fresh82 : uint = 44576u
        c2da_mem[46088] = uint8(c2da_fresh82)
        c2da_mem[46089] = uint8(c2da_fresh82 >> 0x8)
        c2da_mem[46090] = uint8(c2da_fresh82 >> 0x10)
        c2da_mem[46091] = uint8(c2da_fresh82 >> 0x18)
        c2da_mem[46092] = 0u8
        c2da_mem[46093] = 0u8
        c2da_mem[46094] = 0u8
        c2da_mem[46095] = 0u8
    } elif (c2da_fresh76 == 0x0u || c2da_fresh76 == 0x1u) {
    }
    if (uint(gameversion) < 6u) {
        let c2da_fresh83 : int16 = int16(uint(c2da_mem[46128]) | uint(c2da_mem[46129]) << 0x8)
        let c2da_fresh84 : int16 = int16(int(c2da_fresh83) - 1)
        let c2da_fresh85 : uint = uint(c2da_fresh84)
        c2da_mem[46128] = uint8(c2da_fresh85)
        c2da_mem[46129] = uint8(c2da_fresh85 >> 0x8)
    }
    return
}
var messx : int = default<int>

var messy : int = default<int>

[export, sideeffects]
def M_DrawEmptyCell(var menu : int; var item : int) {
    V_DrawPatchDirect(int(int16(uint(c2da_mem[menu + 32]) | uint(c2da_mem[menu + 33]) << 0x8)) - 10, int(int16(uint(c2da_mem[menu + 34]) | uint(c2da_mem[menu + 35]) << 0x8)) + item * 16 - 1, W_CacheLumpName(358559, 8))
    return
}
[export, sideeffects]
def M_DrawSelCell(var menu_0 : int; var item_0 : int) {
    V_DrawPatchDirect(int(int16(uint(c2da_mem[menu_0 + 32]) | uint(c2da_mem[menu_0 + 33]) << 0x8)) - 10, int(int16(uint(c2da_mem[menu_0 + 34]) | uint(c2da_mem[menu_0 + 35]) << 0x8)) + item_0 * 16 - 1, W_CacheLumpName(358567, 8))
    return
}
[export, sideeffects]
def M_StopMessage() {
    menuactive = uint(messageLastMenuActive)
    messageToPrint = 0
    return
}
var main_e : uint = default<uint>

var episodes_e : uint = default<uint>

var newgame_e : uint = default<uint>

var options_e : uint = default<uint>

var read_e : uint = default<uint>

var read_e2 : uint = default<uint>

var sound_e : uint = default<uint>

var load_e : uint = default<uint>

[sideeffects]
def private M_ReadSaveStrings_c2da_frame(c2da_fp : int) {
    var handle : int
    for (i_0 in range(0, 6)) {
        M_StringCopy(c2da_fp, P_SaveGameFile(i_0), 256ul)
        handle = c2da_lin_fopen(c2da_fp, 357680)
        if (handle == 0) {
            M_StringCopy(44016 + i_0 * 24, 357683, 24ul)
            let c2da_fresh32 : int16 = int16(0)
            let c2da_fresh33 : uint = uint(c2da_fresh32)
            c2da_mem[45408 + i_0 * 32] = uint8(c2da_fresh33)
            c2da_mem[45408 + i_0 * 32 + 1] = uint8(c2da_fresh33 >> 0x8)
            continue
        }
        c2da_lin_fread(44016 + i_0 * 24, 1ul, 24ul, uint64(handle))
        c2da_std_fclose(uint64(handle))
        let c2da_fresh34 : int16 = int16(1)
        let c2da_fresh35 : uint = uint(c2da_fresh34)
        c2da_mem[45408 + i_0 * 32] = uint8(c2da_fresh35)
        c2da_mem[45408 + i_0 * 32 + 1] = uint8(c2da_fresh35 >> 0x8)
    }
    return
}
[sideeffects]
def private M_LoadSelect_c2da_frame(var choice_4 : int; c2da_fp : int) {
    M_StringCopy(c2da_fp, P_SaveGameFile(choice_4), 256ul)
    G_LoadGame(c2da_fp)
    M_ClearMenus()
    return
}
[sideeffects]
def private M_Drawer_c2da_frame(c2da_fp : int) {
    var i_6 : uint
    var max : uint
    var name : int
    var start : int
    var foundnewline : int
    inhelpscreens = 0u
    if (messageToPrint != 0) {
        start = 0
        M_Drawer__y = int16(200 / 2 - M_StringHeight(messageString) / 2)
        while (int(int8(c2da_mem[messageString + start])) != 0) {
            foundnewline = 0
            i_6 = 0u
            while (uint64(i_6) < c2da_lin_strlen(messageString + start)) {
                if (int(int8(c2da_mem[messageString + int(uint(start) + i_6)])) == 10) {
                    M_StringCopy(c2da_fp, messageString + start, 80ul)
                    if (uint64(i_6) < 80ul) {
                        let c2da_fresh73 : int8 = int8(0)
                        c2da_mem[c2da_fp + int(i_6)] = uint8(c2da_fresh73)
                    }
                    foundnewline = 1
                    start = int(uint(start) + (i_6 + 1u))
                    break
                }
                i_6++
            }
            if (foundnewline == 0) {
                M_StringCopy(c2da_fp, messageString + start, 80ul)
                start = int(uint64(start) + c2da_lin_strlen(c2da_fp))
            }
            M_Drawer__x = int16(320 / 2 - M_StringWidth(c2da_fp) / 2)
            M_WriteText(int(M_Drawer__x), int(M_Drawer__y), c2da_fp)
            let c2da_fresh74 : int = int(uint(c2da_mem[41520 + 0 * 8]) | uint(c2da_mem[41520 + 0 * 8 + 1]) << 0x8 | uint(c2da_mem[41520 + 0 * 8 + 2]) << 0x10 | uint(c2da_mem[41520 + 0 * 8 + 3]) << 0x18) + 2
            M_Drawer__y = int16(int(M_Drawer__y) + int(int16(uint(c2da_mem[c2da_fresh74]) | uint(c2da_mem[c2da_fresh74 + 1]) << 0x8)))
        }
        return
    }
    if (menuactive == 0) {
        return
    }
    if (int(uint(c2da_mem[currentMenu + 24]) | uint(c2da_mem[currentMenu + 25]) << 0x8 | uint(c2da_mem[currentMenu + 26]) << 0x10 | uint(c2da_mem[currentMenu + 27]) << 0x18) != default<int>) {
        invoke(c2da_fn_table0[int(uint(c2da_mem[currentMenu + 24]) | uint(c2da_mem[currentMenu + 25]) << 0x8 | uint(c2da_mem[currentMenu + 26]) << 0x10 | uint(c2da_mem[currentMenu + 27]) << 0x18)])
    }
    M_Drawer__x = int16(uint(c2da_mem[currentMenu + 32]) | uint(c2da_mem[currentMenu + 33]) << 0x8)
    M_Drawer__y = int16(uint(c2da_mem[currentMenu + 34]) | uint(c2da_mem[currentMenu + 35]) << 0x8)
    max = uint(int16(uint(c2da_mem[currentMenu]) | uint(c2da_mem[currentMenu + 1]) << 0x8))
    i_6 = 0u
    for (c2da_i_6 in urange(i_6, max)) {
        name = int(uint(c2da_mem[currentMenu + 16]) | uint(c2da_mem[currentMenu + 17]) << 0x8 | uint(c2da_mem[currentMenu + 18]) << 0x10 | uint(c2da_mem[currentMenu + 19]) << 0x18) + int(c2da_i_6) * 32 + 2
        if (int8(c2da_mem[name + 0]) != 0) {
            V_DrawPatchDirect(int(M_Drawer__x), int(M_Drawer__y), W_CacheLumpName(name, 8))
        }
        M_Drawer__y = int16(int(M_Drawer__y) + 16)
    }
    V_DrawPatchDirect(int(M_Drawer__x) + -32, int(int16(uint(c2da_mem[currentMenu + 34]) | uint(c2da_mem[currentMenu + 35]) << 0x8)) - 5 + int(itemOn) * 16, W_CacheLumpName(skullName[int(whichSkull)], 8))
    return
}

// This unit's static data, at heap offset 357536.
let private c2da_lin_static_m_menu_seg = fixed_array<int>(357536, 1038)
let private c2da_lin_static_m_menu = fixed_array<uint64>(0x4c415059414c50ul, 0x25004d4f4f445f4dul, 0x73657270280a0a73ul, 0x71206f7420792073ul, 0x64206f7420746975ul, 0x45524300292e736ful, 0x504c454800544944ul, 0x480032504c454800ul, 0x686e550031504c45ul, 0x672064656c646e61ul, 0x7372657620656d61ul, 0x20756f79006e6f69ul, 0x61732074276e6163ul, 0x6f79206669206576ul, 0x74276e6572612075ul, 0x676e6979616c7020ul, 0x73736572700a0a21ul, 0x2e79656b206120ul, 0x7974706d65006272ul, 0x5f4d00746f6c7320ul, 0x5f004745564153ul, 0x4744414f4c5f4dul, 0x5446454c534c5f4dul, 0x544e43534c5f4d00ul, 0x4752534c5f4d0052ul, 0x6320756f79005448ul, 0x206f642074276e61ul, 0x6968772064616f6cul, 0x2061206e6920656cul, 0x656d61672074656eul, 0x73736572700a0a21ul, 0x2e79656b206120ul, 0x4c545454504f5f4dul, 0x4d524548545f4d00ul, 0x524548545f4d004cul, 0x4548545f4d004d4dul, 0x48545f4d00524d52ul, 0x4d5f4d004f4d5245ul, 0x5f4d0046464f4753ul, 0x5f4d004e4f47534dul, 0x4d00484749484447ul, 0x4d00574f4c44475ful, 0x6948004c4f56535ful, 0x6961746564206867ul, 0x656420776f4c006cul, 0x73654d006c696174ul, 0x464f207365676173ul, 0x67617373654d0046ul, 0x6f79004e4f207365ul, 0x2074276e61632075ul, 0x656e206120646e65ul, 0xa0a21656d616774ul, 0x2061207373657270ul, 0x657261002e79656bul, 0x72757320756f7920ul, 0x617720756f792065ul, 0x6e65206f7420746eul, 0x6167206568742064ul, 0x6572700a0a3f656dul, 0x20726f2079207373ul, 0x6320756f79002e6eul, 0x6174732074276e61ul, 0x77656e2061207472ul, 0x68770a656d616720ul, 0x61206e6920656c69ul, 0x6b726f7774656e20ul, 0xa0a2e656d616720ul, 0x2061207373657270ul, 0x455f4d002e79656bul, 0x687400444f534950ul, 0x6874207369207369ul, 0x7765726168732065ul, 0x7372657620657261ul, 0x6420666f206e6f69ul, 0x6f790a0a2e6d6f6ful, 0x74206465656e2075ul, 0x20726564726f206ful, 0x69746e6520656874ul, 0x6f6c697274206572ul, 0x6572700a0a2e7967ul, 0x79656b2061207373ul, 0x736970455f4d002eul, 0x687434203a65646ful, 0x65646f7369706520ul, 0x6572697571657220ul, 0x616d69746c552073ul, 0xa4d4f4f446574ul, 0x4d004757454e5f4dul, 0x61004c4c494b535ful, 0x7320756f79206572ul, 0x696874203f657275ul, 0x206c6c696b732073ul, 0x73690a6c6576656cul, 0x6e6576652074276eul, 0x6c65746f6d657220ul, 0xa2e726961662079ul, 0x792073736572700aul, 0x79002e6e20726f20ul, 0x74276e616320756ful, 0x6f6c6b6369757120ul, 0x6e69727564206461ul, 0x6774656e20612067ul, 0x72700a0a21656d61ul, 0x656b206120737365ul, 0x6820756f79002e79ul, 0x702074276e657661ul, 0x20612064656b6369ul, 0x7661736b63697571ul, 0x7920746f6c732065ul, 0x6572700a0a217465ul, 0x79656b2061207373ul, 0x756f79206f64002eul, 0x6f7420746e617720ul, 0x6f6c6b6369757120ul, 0x6720656874206461ul, 0x656d616e20656d61ul, 0x3f277325270a0a64ul, 0x2073736572700a0aul, 0x2e6e20726f2079ul, 0x7661736b63697571ul, 0x79207265766f2065ul, 0x656d61672072756ful, 0xa0a64656d616e20ul, 0x700a0a3f27732527ul, 0x6f20792073736572ul, 0x535f4d002e6e2072ul, 0x5f4d00314c4c554bul, 0x4d00324c4c554b53ul, 0x4d00314c4c45435ful, 0x324c4c45435ful)

[init]
def private c2da_lin_init_static_m_menu() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_m_menu_seg[s * 2]
        for (k in range(c2da_lin_static_m_menu_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_m_menu[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}

// The initial bytes of this unit's shared external objects.
let private c2da_lin_extern_m_menu_0 = fixed_array<uint8>(0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30, 0xad, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x50, 0xb0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x63, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4a, 0x1, 0xaf, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_1 = fixed_array<uint8>(0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0xae, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30, 0xb0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x61, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x18, 0x1, 0xb9, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_2 = fixed_array<uint8>(0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x50, 0xb2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xb3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x50, 0x0, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_3 = fixed_array<uint8>(0x47, 0x61, 0x6d, 0x6d, 0x61, 0x20, 0x63, 0x6f, 0x72, 0x72, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x4f, 0x46, 0x46, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x47, 0x61, 0x6d, 0x6d, 0x61, 0x20, 0x63, 0x6f, 0x72, 0x72, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x6c, 0x65, 0x76, 0x65, 0x6c, 0x20, 0x31, 0x0, 0x0, 0x47, 0x61, 0x6d, 0x6d, 0x61, 0x20, 0x63, 0x6f, 0x72, 0x72, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x6c, 0x65, 0x76, 0x65, 0x6c, 0x20, 0x32, 0x0, 0x0, 0x47, 0x61, 0x6d, 0x6d, 0x61, 0x20, 0x63, 0x6f, 0x72, 0x72, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x6c, 0x65, 0x76, 0x65, 0x6c, 0x20, 0x33, 0x0, 0x0, 0x47, 0x61, 0x6d, 0x6d, 0x61, 0x20, 0x63, 0x6f, 0x72, 0x72, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x6c, 0x65, 0x76, 0x65, 0x6c, 0x20, 0x34, 0x0, 0x0)
let private c2da_lin_extern_m_menu_4 = fixed_array<uint8>(0x6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x50, 0xae, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5a, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x61, 0x0, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_5 = fixed_array<uint8>(0x1, 0x0, 0x4d, 0x5f, 0x4e, 0x47, 0x41, 0x4d, 0x45, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5b, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x4d, 0x5f, 0x4f, 0x50, 0x54, 0x49, 0x4f, 0x4e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x4d, 0x5f, 0x4c, 0x4f, 0x41, 0x44, 0x47, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x4d, 0x5f, 0x53, 0x41, 0x56, 0x45, 0x47, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x73, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x4d, 0x5f, 0x52, 0x44, 0x54, 0x48, 0x49, 0x53, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x72, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x4d, 0x5f, 0x51, 0x55, 0x49, 0x54, 0x47, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x60, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x71, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_6 = fixed_array<uint8>(0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x62, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_7 = fixed_array<uint8>(0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x64, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_8 = fixed_array<uint8>(0x6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0xae, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0xb0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x66, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x50, 0x0, 0x36, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_9 = fixed_array<uint8>(0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x68, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x31, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x68, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x32, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x68, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x68, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x34, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x68, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x35, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x68, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x36, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_10 = fixed_array<uint8>(0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x65, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x31, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x65, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x32, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x65, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x65, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x34, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x65, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x35, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x65, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x36, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_11 = fixed_array<uint8>(0x6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0xae, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x60, 0xb1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x67, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x50, 0x0, 0x36, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_12 = fixed_array<uint8>(0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0xae, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xb2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x69, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3c, 0x0, 0x25, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_13 = fixed_array<uint8>(0x1, 0x0, 0x4d, 0x5f, 0x45, 0x4e, 0x44, 0x47, 0x41, 0x4d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6a, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x65, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x4d, 0x5f, 0x4d, 0x45, 0x53, 0x53, 0x47, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6b, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x4d, 0x5f, 0x44, 0x45, 0x54, 0x41, 0x49, 0x4c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x67, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x4d, 0x5f, 0x53, 0x43, 0x52, 0x4e, 0x53, 0x5a, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x73, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x4d, 0x5f, 0x4d, 0x53, 0x45, 0x4e, 0x53, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x4d, 0x5f, 0x53, 0x56, 0x4f, 0x4c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x73, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_14 = fixed_array<uint8>(0x2, 0x0, 0x4d, 0x5f, 0x53, 0x46, 0x58, 0x56, 0x4f, 0x4c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x71, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x73, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x4d, 0x5f, 0x4d, 0x55, 0x53, 0x56, 0x4f, 0x4c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x72, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_15 = fixed_array<uint8>(0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30, 0xb4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0xb4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x76, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30, 0x0, 0x3f, 0x0, 0x2, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_16 = fixed_array<uint8>(0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0xae, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x60, 0xb4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x74, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30, 0x0, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_17 = fixed_array<uint8>(0x1, 0x0, 0x4d, 0x5f, 0x45, 0x50, 0x49, 0x31, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x75, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6b, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x4d, 0x5f, 0x45, 0x50, 0x49, 0x32, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x75, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x74, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x4d, 0x5f, 0x45, 0x50, 0x49, 0x33, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x75, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x69, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x4d, 0x5f, 0x45, 0x50, 0x49, 0x34, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x75, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x74, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_18 = fixed_array<uint8>(0x1, 0x0, 0x4d, 0x5f, 0x4a, 0x4b, 0x49, 0x4c, 0x4c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x77, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x69, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x4d, 0x5f, 0x52, 0x4f, 0x55, 0x47, 0x48, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x77, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x68, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x4d, 0x5f, 0x48, 0x55, 0x52, 0x54, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x77, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x68, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x4d, 0x5f, 0x55, 0x4c, 0x54, 0x52, 0x41, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x77, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x75, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x4d, 0x5f, 0x4e, 0x4d, 0x41, 0x52, 0x45, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x77, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_19 = fixed_array<uint8>(0x5, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_20 = fixed_array<uint8>(0x1, 0x0, 0x0, 0x0)
let private c2da_lin_extern_m_menu_22 = fixed_array<uint8>(0xa, 0x0, 0x0, 0x0)

[init]
def private c2da_lin_init_externs_m_menu() {
    c2da_lin_setup()
    for (i in range(40)) {
        c2da_mem[44288 + i] = c2da_lin_extern_m_menu_0[i]
    }
    for (i in range(40)) {
        c2da_mem[44336 + i] = c2da_lin_extern_m_menu_1[i]
    }
    for (i in range(40)) {
        c2da_mem[44384 + i] = c2da_lin_extern_m_menu_2[i]
    }
    for (i in range(130)) {
        c2da_mem[44432 + i] = c2da_lin_extern_m_menu_3[i]
    }
    for (i in range(40)) {
        c2da_mem[44576 + i] = c2da_lin_extern_m_menu_4[i]
    }
    for (i in range(192)) {
        c2da_mem[44624 + i] = c2da_lin_extern_m_menu_5[i]
    }
    for (i in range(32)) {
        c2da_mem[45104 + i] = c2da_lin_extern_m_menu_6[i]
    }
    for (i in range(32)) {
        c2da_mem[45136 + i] = c2da_lin_extern_m_menu_7[i]
    }
    for (i in range(40)) {
        c2da_mem[45168 + i] = c2da_lin_extern_m_menu_8[i]
    }
    for (i in range(192)) {
        c2da_mem[45216 + i] = c2da_lin_extern_m_menu_9[i]
    }
    for (i in range(192)) {
        c2da_mem[45408 + i] = c2da_lin_extern_m_menu_10[i]
    }
    for (i in range(40)) {
        c2da_mem[45600 + i] = c2da_lin_extern_m_menu_11[i]
    }
    for (i in range(40)) {
        c2da_mem[45648 + i] = c2da_lin_extern_m_menu_12[i]
    }
    for (i in range(256)) {
        c2da_mem[45696 + i] = c2da_lin_extern_m_menu_13[i]
    }
    for (i in range(128)) {
        c2da_mem[45952 + i] = c2da_lin_extern_m_menu_14[i]
    }
    for (i in range(40)) {
        c2da_mem[46080 + i] = c2da_lin_extern_m_menu_15[i]
    }
    for (i in range(40)) {
        c2da_mem[46128 + i] = c2da_lin_extern_m_menu_16[i]
    }
    for (i in range(128)) {
        c2da_mem[46176 + i] = c2da_lin_extern_m_menu_17[i]
    }
    for (i in range(160)) {
        c2da_mem[46304 + i] = c2da_lin_extern_m_menu_18[i]
    }
    for (i in range(4)) {
        c2da_mem[1824 + i] = c2da_lin_extern_m_menu_19[i]
    }
    for (i in range(4)) {
        c2da_mem[1872 + i] = c2da_lin_extern_m_menu_20[i]
    }
    for (i in range(4)) {
        c2da_mem[1888 + i] = c2da_lin_extern_m_menu_22[i]
    }
}

// Fills this module's slots of the shared function tables (at start, and after a hot reload).
def c2da_relink_m_menu() {
    if (length(c2da_fn_table0) < 123) {
        resize(c2da_fn_table0, 123)
    }
    c2da_fn_table0[90] = @@M_DrawMainMenu
    c2da_fn_table0[97] = @@M_DrawReadThis1
    c2da_fn_table0[99] = @@M_DrawReadThis2
    c2da_fn_table0[102] = @@M_DrawSave
    c2da_fn_table0[103] = @@M_DrawLoad
    c2da_fn_table0[105] = @@M_DrawOptions
    c2da_fn_table0[112] = @@M_DrawSound
    c2da_fn_table0[116] = @@M_DrawEpisode
    c2da_fn_table0[118] = @@M_DrawNewGame
    c2da_fn_table0[8] = @@M_Ticker
    if (length(c2da_fn_table5) < 123) {
        resize(c2da_fn_table5, 123)
    }
    c2da_fn_table5[96] = @@M_QuitDOOM
    c2da_fn_table5[89] = @@M_QuitResponse
    c2da_fn_table5[95] = @@M_ReadThis
    c2da_fn_table5[98] = @@M_ReadThis2
    c2da_fn_table5[100] = @@M_FinishReadThis
    c2da_fn_table5[94] = @@M_SaveGame
    c2da_fn_table5[101] = @@M_LoadSelect
    c2da_fn_table5[104] = @@M_SaveSelect
    c2da_fn_table5[93] = @@M_LoadGame
    c2da_fn_table5[92] = @@M_Options
    c2da_fn_table5[111] = @@M_Sound
    c2da_fn_table5[114] = @@M_MusicVol
    c2da_fn_table5[113] = @@M_SfxVol
    c2da_fn_table5[110] = @@M_ChangeSensitivity
    c2da_fn_table5[109] = @@M_SizeDisplay
    c2da_fn_table5[108] = @@M_ChangeDetail
    c2da_fn_table5[107] = @@M_ChangeMessages
    c2da_fn_table5[106] = @@M_EndGame
    c2da_fn_table5[115] = @@M_EndGameResponse
    c2da_fn_table5[91] = @@M_NewGame
    c2da_fn_table5[117] = @@M_Episode
    c2da_fn_table5[119] = @@M_ChooseSkill
    c2da_fn_table5[120] = @@M_VerifyNightmare
    c2da_fn_table5[121] = @@M_QuickLoadResponse
    c2da_fn_table5[122] = @@M_QuickSaveResponse
}

[init]
def private c2da_lin_relink_init_m_menu() {
    c2da_relink_m_menu()
}
