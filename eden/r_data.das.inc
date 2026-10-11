var textureheight : int = default<int>

var spritewidth : int = default<int>

var spriteoffset : int = default<int>

var spritetopoffset : int = default<int>

var colormaps : int = default<int>

var firstflat : int = default<int>

var flattranslation : int = default<int>

var texturetranslation : int = default<int>

var firstspritelump : int = default<int>

var lastspritelump : int = default<int>

var numspritelumps : int = default<int>

[export, sideeffects]
def R_GetColumn(var tex : int; var col : int) : int {
    var lump : int
    var ofs : int
    col &= int(uint(c2da_mem[texturewidthmask + tex * 4]) | uint(c2da_mem[texturewidthmask + tex * 4 + 1]) << 0x8 | uint(c2da_mem[texturewidthmask + tex * 4 + 2]) << 0x10 | uint(c2da_mem[texturewidthmask + tex * 4 + 3]) << 0x18)
    let c2da_fresh0 : int = int(uint(c2da_mem[texturecolumnlump + tex * 8]) | uint(c2da_mem[texturecolumnlump + tex * 8 + 1]) << 0x8 | uint(c2da_mem[texturecolumnlump + tex * 8 + 2]) << 0x10 | uint(c2da_mem[texturecolumnlump + tex * 8 + 3]) << 0x18) + col * 2
    lump = int(int16(uint(c2da_mem[c2da_fresh0]) | uint(c2da_mem[c2da_fresh0 + 1]) << 0x8))
    let c2da_fresh1 : int = int(uint(c2da_mem[texturecolumnofs + tex * 8]) | uint(c2da_mem[texturecolumnofs + tex * 8 + 1]) << 0x8 | uint(c2da_mem[texturecolumnofs + tex * 8 + 2]) << 0x10 | uint(c2da_mem[texturecolumnofs + tex * 8 + 3]) << 0x18) + col * 2
    ofs = int(uint16(uint(c2da_mem[c2da_fresh1]) | uint(c2da_mem[c2da_fresh1 + 1]) << 0x8))
    if (lump > 0) {
        return W_CacheLumpNum(lump, 8) + ofs
    }
    if (int(uint(c2da_mem[texturecomposite + tex * 8]) | uint(c2da_mem[texturecomposite + tex * 8 + 1]) << 0x8 | uint(c2da_mem[texturecomposite + tex * 8 + 2]) << 0x10 | uint(c2da_mem[texturecomposite + tex * 8 + 3]) << 0x18) == 0) {
        R_GenerateComposite(tex)
    }
    return int(uint(c2da_mem[texturecomposite + tex * 8]) | uint(c2da_mem[texturecomposite + tex * 8 + 1]) << 0x8 | uint(c2da_mem[texturecomposite + tex * 8 + 2]) << 0x10 | uint(c2da_mem[texturecomposite + tex * 8 + 3]) << 0x18) + ofs
}
var texturecomposite : int = default<int>

[export, sideeffects]
def R_GenerateComposite(var texnum : int) {
    var block_0 : int
    var texture : int
    var patch : int
    var realpatch : int
    var x : int
    var x1 : int
    var x2 : int
    var i : int
    var patchcol : int
    var collump : int
    var colofs : int
    texture = int(uint(c2da_mem[textures + texnum * 8]) | uint(c2da_mem[textures + texnum * 8 + 1]) << 0x8 | uint(c2da_mem[textures + texnum * 8 + 2]) << 0x10 | uint(c2da_mem[textures + texnum * 8 + 3]) << 0x18)
    block_0 = Z_Malloc(int(uint(c2da_mem[texturecompositesize + texnum * 4]) | uint(c2da_mem[texturecompositesize + texnum * 4 + 1]) << 0x8 | uint(c2da_mem[texturecompositesize + texnum * 4 + 2]) << 0x10 | uint(c2da_mem[texturecompositesize + texnum * 4 + 3]) << 0x18), 1, texturecomposite + texnum * 8)
    collump = int(uint(c2da_mem[texturecolumnlump + texnum * 8]) | uint(c2da_mem[texturecolumnlump + texnum * 8 + 1]) << 0x8 | uint(c2da_mem[texturecolumnlump + texnum * 8 + 2]) << 0x10 | uint(c2da_mem[texturecolumnlump + texnum * 8 + 3]) << 0x18)
    colofs = int(uint(c2da_mem[texturecolumnofs + texnum * 8]) | uint(c2da_mem[texturecolumnofs + texnum * 8 + 1]) << 0x8 | uint(c2da_mem[texturecolumnofs + texnum * 8 + 2]) << 0x10 | uint(c2da_mem[texturecolumnofs + texnum * 8 + 3]) << 0x18)
    patch = texture + 28
    i = 0
    patch = texture + 28
    while (i < int(int16(uint(c2da_mem[texture + 24]) | uint(c2da_mem[texture + 25]) << 0x8))) {
        realpatch = W_CacheLumpNum(int(uint(c2da_mem[patch + 4]) | uint(c2da_mem[patch + 5]) << 0x8 | uint(c2da_mem[patch + 6]) << 0x10 | uint(c2da_mem[patch + 7]) << 0x18), 8)
        x1 = int(int16(uint(c2da_mem[patch]) | uint(c2da_mem[patch + 1]) << 0x8))
        x2 = x1 + int(int16(uint(c2da_mem[realpatch]) | uint(c2da_mem[realpatch + 1]) << 0x8))
        if (x1 < 0) {
            x = 0
        } else {
            x = x1
        }
        if (x2 > int(int16(uint(c2da_mem[texture + 8]) | uint(c2da_mem[texture + 9]) << 0x8))) {
            x2 = int(int16(uint(c2da_mem[texture + 8]) | uint(c2da_mem[texture + 9]) << 0x8))
        }
        while (x < x2) {
            if (int(int16(uint(c2da_mem[collump + x * 2]) | uint(c2da_mem[collump + x * 2 + 1]) << 0x8)) >= 0) {
                x++
                continue
            }
            patchcol = realpatch + int(uint(c2da_mem[realpatch + 8 + (x - x1) * 4]) | uint(c2da_mem[realpatch + 8 + (x - x1) * 4 + 1]) << 0x8 | uint(c2da_mem[realpatch + 8 + (x - x1) * 4 + 2]) << 0x10 | uint(c2da_mem[realpatch + 8 + (x - x1) * 4 + 3]) << 0x18)
            R_DrawColumnInCache(patchcol, block_0 + int(uint16(uint(c2da_mem[colofs + x * 2]) | uint(c2da_mem[colofs + x * 2 + 1]) << 0x8)), int(int16(uint(c2da_mem[patch + 2]) | uint(c2da_mem[patch + 3]) << 0x8)), int(int16(uint(c2da_mem[texture + 10]) | uint(c2da_mem[texture + 11]) << 0x8)))
            x++
        }
        i++
        patch += 8
    }
    Z_ChangeTag2(block_0, 8, 361888, 286)
    return
}
[export, sideeffects]
def R_DrawColumnInCache(var patch_0 : int; var cache : int; var originy : int; var cacheheight : int) {
    var count : int
    var position : int
    var source : int
    while (int(c2da_mem[patch_0]) != 255) {
        source = patch_0 + 3
        count = int(c2da_mem[patch_0 + 1])
        position = originy + int(c2da_mem[patch_0])
        if (position < 0) {
            count += position
            position = 0
        }
        if (position + count > cacheheight) {
            count = cacheheight - position
        }
        if (count > 0) {
            c2da_lin_memcpy(cache + position, source, uint64(count))
        }
        patch_0 = patch_0 + int(c2da_mem[patch_0 + 1]) + 4
    }
    return
}
var texturecolumnofs : int = default<int>

var texturecolumnlump : int = default<int>

var texturecompositesize : int = default<int>

var textures : int = default<int>

var texturewidthmask : int = default<int>

[export, sideeffects]
def R_InitData() {
    R_InitTextures()
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 361967, [])
    R_InitFlats()
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 361967, [])
    R_InitSpriteLumps()
    c2da_lin_printf(uint64(int(c2da_std_stderr())), 361967, [])
    R_InitColormaps()
    return
}
[export, sideeffects]
def R_InitColormaps() {
    var lump_0 : int = W_GetNumForName(361969)
    colormaps = W_CacheLumpNum(lump_0, 1)
    return
}
[export, sideeffects]
def R_InitSpriteLumps() {
    var i_0 : int
    var patch_1 : int
    firstspritelump = W_GetNumForName(361978) + 1
    lastspritelump = W_GetNumForName(361986) - 1
    numspritelumps = lastspritelump - firstspritelump + 1
    spritewidth = Z_Malloc(int(uint64(numspritelumps) * 4ul), 1, 0)
    spriteoffset = Z_Malloc(int(uint64(numspritelumps) * 4ul), 1, 0)
    spritetopoffset = Z_Malloc(int(uint64(numspritelumps) * 4ul), 1, 0)
    i_0 = 0
    while (i_0 < numspritelumps) {
        if ((i_0 & 63) == 0) {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 361967, [])
        }
        patch_1 = W_CacheLumpNum(firstspritelump + i_0, 8)
        let c2da_fresh2 : int = int(int16(uint(c2da_mem[patch_1]) | uint(c2da_mem[patch_1 + 1]) << 0x8)) << 16
        let c2da_fresh3 : uint = uint(c2da_fresh2)
        c2da_mem[spritewidth + i_0 * 4] = uint8(c2da_fresh3)
        c2da_mem[spritewidth + i_0 * 4 + 1] = uint8(c2da_fresh3 >> 0x8)
        c2da_mem[spritewidth + i_0 * 4 + 2] = uint8(c2da_fresh3 >> 0x10)
        c2da_mem[spritewidth + i_0 * 4 + 3] = uint8(c2da_fresh3 >> 0x18)
        let c2da_fresh4 : int = int(int16(uint(c2da_mem[patch_1 + 4]) | uint(c2da_mem[patch_1 + 5]) << 0x8)) << 16
        let c2da_fresh5 : uint = uint(c2da_fresh4)
        c2da_mem[spriteoffset + i_0 * 4] = uint8(c2da_fresh5)
        c2da_mem[spriteoffset + i_0 * 4 + 1] = uint8(c2da_fresh5 >> 0x8)
        c2da_mem[spriteoffset + i_0 * 4 + 2] = uint8(c2da_fresh5 >> 0x10)
        c2da_mem[spriteoffset + i_0 * 4 + 3] = uint8(c2da_fresh5 >> 0x18)
        let c2da_fresh6 : int = int(int16(uint(c2da_mem[patch_1 + 6]) | uint(c2da_mem[patch_1 + 7]) << 0x8)) << 16
        let c2da_fresh7 : uint = uint(c2da_fresh6)
        c2da_mem[spritetopoffset + i_0 * 4] = uint8(c2da_fresh7)
        c2da_mem[spritetopoffset + i_0 * 4 + 1] = uint8(c2da_fresh7 >> 0x8)
        c2da_mem[spritetopoffset + i_0 * 4 + 2] = uint8(c2da_fresh7 >> 0x10)
        c2da_mem[spritetopoffset + i_0 * 4 + 3] = uint8(c2da_fresh7 >> 0x18)
        i_0++
    }
    return
}
[export, sideeffects]
def R_InitFlats() {
    var i_1 : int
    firstflat = W_GetNumForName(361992) + 1
    lastflat = W_GetNumForName(362000) - 1
    numflats = lastflat - firstflat + 1
    flattranslation = Z_Malloc(int(uint64(numflats + 1) * 4ul), 1, 0)
    i_1 = 0
    while (i_1 < numflats) {
        let c2da_fresh8 : uint = uint(i_1)
        c2da_mem[flattranslation + i_1 * 4] = uint8(c2da_fresh8)
        c2da_mem[flattranslation + i_1 * 4 + 1] = uint8(c2da_fresh8 >> 0x8)
        c2da_mem[flattranslation + i_1 * 4 + 2] = uint8(c2da_fresh8 >> 0x10)
        c2da_mem[flattranslation + i_1 * 4 + 3] = uint8(c2da_fresh8 >> 0x18)
        i_1++
    }
    return
}
var numflats : int = default<int>

var lastflat : int = default<int>

[export, sideeffects]
def R_InitTextures() {
    let c2da_saved_sp : int = c2da_lin_sp
    R_InitTextures_c2da_frame(c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[sideeffects]
def private GenerateTextureHashTable() {
    var rover : int
    var i_3 : int
    var key : int
    textures_hashtable = Z_Malloc(int(8ul * uint64(numtextures)), 1, 0)
    c2da_lin_memset(textures_hashtable, 0, 8ul * uint64(numtextures))
    i_3 = 0
    while (i_3 < numtextures) {
        let c2da_fresh36 : int = int(uint(c2da_mem[textures + i_3 * 8]) | uint(c2da_mem[textures + i_3 * 8 + 1]) << 0x8 | uint(c2da_mem[textures + i_3 * 8 + 2]) << 0x10 | uint(c2da_mem[textures + i_3 * 8 + 3]) << 0x18) + 12
        let c2da_fresh37 : uint = uint(i_3)
        c2da_mem[c2da_fresh36] = uint8(c2da_fresh37)
        c2da_mem[c2da_fresh36 + 1] = uint8(c2da_fresh37 >> 0x8)
        c2da_mem[c2da_fresh36 + 2] = uint8(c2da_fresh37 >> 0x10)
        c2da_mem[c2da_fresh36 + 3] = uint8(c2da_fresh37 >> 0x18)
        key = int(W_LumpNameHash(int(uint(c2da_mem[textures + i_3 * 8]) | uint(c2da_mem[textures + i_3 * 8 + 1]) << 0x8 | uint(c2da_mem[textures + i_3 * 8 + 2]) << 0x10 | uint(c2da_mem[textures + i_3 * 8 + 3]) << 0x18)) % uint(numtextures))
        rover = textures_hashtable + key * 8
        while (int(uint(c2da_mem[rover]) | uint(c2da_mem[rover + 1]) << 0x8 | uint(c2da_mem[rover + 2]) << 0x10 | uint(c2da_mem[rover + 3]) << 0x18) != 0) {
            rover = int(uint(c2da_mem[rover]) | uint(c2da_mem[rover + 1]) << 0x8 | uint(c2da_mem[rover + 2]) << 0x10 | uint(c2da_mem[rover + 3]) << 0x18) + 16
        }
        let c2da_fresh38 : int = int(uint(c2da_mem[textures + i_3 * 8]) | uint(c2da_mem[textures + i_3 * 8 + 1]) << 0x8 | uint(c2da_mem[textures + i_3 * 8 + 2]) << 0x10 | uint(c2da_mem[textures + i_3 * 8 + 3]) << 0x18) + 16
        let c2da_fresh39 : uint = 0u
        c2da_mem[c2da_fresh38] = uint8(c2da_fresh39)
        c2da_mem[c2da_fresh38 + 1] = uint8(c2da_fresh39 >> 0x8)
        c2da_mem[c2da_fresh38 + 2] = uint8(c2da_fresh39 >> 0x10)
        c2da_mem[c2da_fresh38 + 3] = uint8(c2da_fresh39 >> 0x18)
        c2da_mem[c2da_fresh38 + 4] = 0u8
        c2da_mem[c2da_fresh38 + 5] = 0u8
        c2da_mem[c2da_fresh38 + 6] = 0u8
        c2da_mem[c2da_fresh38 + 7] = 0u8
        let c2da_fresh40 : int = int(uint(c2da_mem[textures + i_3 * 8]) | uint(c2da_mem[textures + i_3 * 8 + 1]) << 0x8 | uint(c2da_mem[textures + i_3 * 8 + 2]) << 0x10 | uint(c2da_mem[textures + i_3 * 8 + 3]) << 0x18)
        let c2da_fresh41 : uint = uint(c2da_fresh40)
        c2da_mem[rover] = uint8(c2da_fresh41)
        c2da_mem[rover + 1] = uint8(c2da_fresh41 >> 0x8)
        c2da_mem[rover + 2] = uint8(c2da_fresh41 >> 0x10)
        c2da_mem[rover + 3] = uint8(c2da_fresh41 >> 0x18)
        c2da_mem[rover + 4] = 0u8
        c2da_mem[rover + 5] = 0u8
        c2da_mem[rover + 6] = 0u8
        c2da_mem[rover + 7] = 0u8
        i_3++
    }
    return
}
var textures_hashtable : int = default<int>

var numtextures : int = default<int>

[export, sideeffects]
def R_GenerateLookup(var texnum_0 : int) {
    let c2da_saved_sp : int = c2da_lin_sp
    R_GenerateLookup_c2da_frame(texnum_0, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
}
[export, sideeffects]
def R_PrecacheLevel() {
    var flatpresent : int
    var texturepresent : int
    var spritepresent : int
    var i_5 : int
    var j_0 : int
    var lump_1 : int
    var texture_2 : int
    var th : int
    var sf : int
    if (demoplayback != 0x0) {
        return
    }
    flatpresent = Z_Malloc(numflats, 1, 0)
    c2da_lin_memset(flatpresent, 0, uint64(numflats))
    i_5 = 0
    while (i_5 < numsectors) {
        let c2da_fresh62 : int = flatpresent + int(int16(uint(c2da_mem[sectors + i_5 * 128 + 8]) | uint(c2da_mem[sectors + i_5 * 128 + 9]) << 0x8))
        let c2da_fresh63 : int8 = int8(1)
        c2da_mem[c2da_fresh62] = uint8(c2da_fresh63)
        let c2da_fresh64 : int = flatpresent + int(int16(uint(c2da_mem[sectors + i_5 * 128 + 10]) | uint(c2da_mem[sectors + i_5 * 128 + 11]) << 0x8))
        let c2da_fresh65 : int8 = int8(1)
        c2da_mem[c2da_fresh64] = uint8(c2da_fresh65)
        i_5++
    }
    flatmemory = 0
    i_5 = 0
    while (i_5 < numflats) {
        if (int8(c2da_mem[flatpresent + i_5]) != 0) {
            lump_1 = firstflat + i_5
            flatmemory += int(uint(c2da_mem[lumpinfo + lump_1 * 40 + 20]) | uint(c2da_mem[lumpinfo + lump_1 * 40 + 21]) << 0x8 | uint(c2da_mem[lumpinfo + lump_1 * 40 + 22]) << 0x10 | uint(c2da_mem[lumpinfo + lump_1 * 40 + 23]) << 0x18)
            W_CacheLumpNum(lump_1, 8)
        }
        i_5++
    }
    Z_Free(flatpresent)
    texturepresent = Z_Malloc(numtextures, 1, 0)
    c2da_lin_memset(texturepresent, 0, uint64(numtextures))
    i_5 = 0
    while (i_5 < numsides) {
        let c2da_fresh66 : int = texturepresent + int(int16(uint(c2da_mem[sides + i_5 * 24 + 8]) | uint(c2da_mem[sides + i_5 * 24 + 9]) << 0x8))
        let c2da_fresh67 : int8 = int8(1)
        c2da_mem[c2da_fresh66] = uint8(c2da_fresh67)
        let c2da_fresh68 : int = texturepresent + int(int16(uint(c2da_mem[sides + i_5 * 24 + 12]) | uint(c2da_mem[sides + i_5 * 24 + 13]) << 0x8))
        let c2da_fresh69 : int8 = int8(1)
        c2da_mem[c2da_fresh68] = uint8(c2da_fresh69)
        let c2da_fresh70 : int = texturepresent + int(int16(uint(c2da_mem[sides + i_5 * 24 + 10]) | uint(c2da_mem[sides + i_5 * 24 + 11]) << 0x8))
        let c2da_fresh71 : int8 = int8(1)
        c2da_mem[c2da_fresh70] = uint8(c2da_fresh71)
        i_5++
    }
    let c2da_fresh72 : int8 = int8(1)
    c2da_mem[texturepresent + int(skytexture)] = uint8(c2da_fresh72)
    texturememory = 0
    i_5 = 0
    while (i_5 < numtextures) {
        if (int8(c2da_mem[texturepresent + i_5]) == 0) {
            i_5++
            continue
        }
        texture_2 = int(uint(c2da_mem[textures + i_5 * 8]) | uint(c2da_mem[textures + i_5 * 8 + 1]) << 0x8 | uint(c2da_mem[textures + i_5 * 8 + 2]) << 0x10 | uint(c2da_mem[textures + i_5 * 8 + 3]) << 0x18)
        j_0 = 0
        while (j_0 < int(int16(uint(c2da_mem[texture_2 + 24]) | uint(c2da_mem[texture_2 + 25]) << 0x8))) {
            lump_1 = int(uint(c2da_mem[texture_2 + 28 + j_0 * 8 + 4]) | uint(c2da_mem[texture_2 + 28 + j_0 * 8 + 5]) << 0x8 | uint(c2da_mem[texture_2 + 28 + j_0 * 8 + 6]) << 0x10 | uint(c2da_mem[texture_2 + 28 + j_0 * 8 + 7]) << 0x18)
            texturememory += int(uint(c2da_mem[lumpinfo + lump_1 * 40 + 20]) | uint(c2da_mem[lumpinfo + lump_1 * 40 + 21]) << 0x8 | uint(c2da_mem[lumpinfo + lump_1 * 40 + 22]) << 0x10 | uint(c2da_mem[lumpinfo + lump_1 * 40 + 23]) << 0x18)
            W_CacheLumpNum(lump_1, 8)
            j_0++
        }
        i_5++
    }
    Z_Free(texturepresent)
    spritepresent = Z_Malloc(numsprites, 1, 0)
    c2da_lin_memset(spritepresent, 0, uint64(numsprites))
    th = int(uint(c2da_mem[46552]) | uint(c2da_mem[46553]) << 0x8 | uint(c2da_mem[46554]) << 0x10 | uint(c2da_mem[46555]) << 0x18)
    while (th != 46544) {
        if (int(uint(c2da_mem[th + 16]) | uint(c2da_mem[th + 17]) << 0x8 | uint(c2da_mem[th + 18]) << 0x10 | uint(c2da_mem[th + 19]) << 0x18) == 126) {
            let c2da_fresh73 : int = spritepresent + int(uint(c2da_mem[th + 60]) | uint(c2da_mem[th + 61]) << 0x8 | uint(c2da_mem[th + 62]) << 0x10 | uint(c2da_mem[th + 63]) << 0x18)
            let c2da_fresh74 : int8 = int8(1)
            c2da_mem[c2da_fresh73] = uint8(c2da_fresh74)
        }
        th = int(uint(c2da_mem[th + 8]) | uint(c2da_mem[th + 9]) << 0x8 | uint(c2da_mem[th + 10]) << 0x10 | uint(c2da_mem[th + 11]) << 0x18)
    }
    spritememory = 0
    i_5 = 0
    while (i_5 < numsprites) {
        if (int8(c2da_mem[spritepresent + i_5]) == 0) {
            i_5++
            continue
        }
        j_0 = 0
        while (j_0 < int(uint(c2da_mem[sprites + i_5 * 16]) | uint(c2da_mem[sprites + i_5 * 16 + 1]) << 0x8 | uint(c2da_mem[sprites + i_5 * 16 + 2]) << 0x10 | uint(c2da_mem[sprites + i_5 * 16 + 3]) << 0x18)) {
            sf = int(uint(c2da_mem[sprites + i_5 * 16 + 8]) | uint(c2da_mem[sprites + i_5 * 16 + 9]) << 0x8 | uint(c2da_mem[sprites + i_5 * 16 + 10]) << 0x10 | uint(c2da_mem[sprites + i_5 * 16 + 11]) << 0x18) + j_0 * 28
            for (k in range(0, 8)) {
                lump_1 = firstspritelump + int(int16(uint(c2da_mem[sf + 4 + k * 2]) | uint(c2da_mem[sf + 4 + k * 2 + 1]) << 0x8))
                spritememory += int(uint(c2da_mem[lumpinfo + lump_1 * 40 + 20]) | uint(c2da_mem[lumpinfo + lump_1 * 40 + 21]) << 0x8 | uint(c2da_mem[lumpinfo + lump_1 * 40 + 22]) << 0x10 | uint(c2da_mem[lumpinfo + lump_1 * 40 + 23]) << 0x18)
                W_CacheLumpNum(lump_1, 8)
            }
            j_0++
        }
        i_5++
    }
    Z_Free(spritepresent)
    return
}
var spritememory : int = default<int>

var texturememory : int = default<int>

var flatmemory : int = default<int>

[export, sideeffects]
def R_FlatNumForName(var name : int) : int {
    let c2da_saved_sp : int = c2da_lin_sp
    let c2da_result : int = R_FlatNumForName_c2da_frame(name, c2da_lin_enter(16))
    c2da_lin_sp = c2da_saved_sp
    return c2da_result
}
[export, sideeffects]
def R_TextureNumForName(var name_0 : int) : int {
    var i_7 : int = R_CheckTextureNumForName(name_0)
    if (i_7 == -1) {
        I_Error(362236, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(name_0))])
    }
    return i_7
}
[export, sideeffects]
def R_CheckTextureNumForName(var name_1 : int) : int {
    var texture_3 : int
    var key_0 : int
    if (int(int8(c2da_mem[name_1 + 0])) == 45) {
        return 0
    }
    key_0 = int(W_LumpNameHash(name_1) % uint(numtextures))
    texture_3 = int(uint(c2da_mem[textures_hashtable + key_0 * 8]) | uint(c2da_mem[textures_hashtable + key_0 * 8 + 1]) << 0x8 | uint(c2da_mem[textures_hashtable + key_0 * 8 + 2]) << 0x10 | uint(c2da_mem[textures_hashtable + key_0 * 8 + 3]) << 0x18)
    while (texture_3 != 0) {
        if (c2da_lin_strncasecmp(texture_3, name_1, 8ul) == 0) {
            return int(uint(c2da_mem[texture_3 + 12]) | uint(c2da_mem[texture_3 + 13]) << 0x8 | uint(c2da_mem[texture_3 + 14]) << 0x10 | uint(c2da_mem[texture_3 + 15]) << 0x18)
        }
        texture_3 = int(uint(c2da_mem[texture_3 + 16]) | uint(c2da_mem[texture_3 + 17]) << 0x8 | uint(c2da_mem[texture_3 + 18]) << 0x10 | uint(c2da_mem[texture_3 + 19]) << 0x18)
    }
    return -1
}
var firstpatch : int = default<int>

var lastpatch : int = default<int>

var numpatches : int = default<int>

[sideeffects]
def private R_InitTextures_c2da_frame(c2da_fp : int) {
    var mtexture : int
    var texture_0 : int
    var mpatch : int
    var patch_2 : int
    var i_2 : int
    var j : int
    var maptex : int
    var maptex2 : int
    var maptex1 : int
    var names : int
    var name_p : int
    var patchlookup : int
    var totalwidth : int
    var nummappatches : int
    var offset : int
    var maxoff : int
    var maxoff2 : int
    var numtextures1 : int
    var numtextures2 : int
    var directory : int
    var temp1 : int
    var temp2 : int
    var temp3 : int
    let c2da_fresh9 : int8 = int8(0)
    c2da_mem[c2da_fp + 8] = uint8(c2da_fresh9)
    names = W_CacheLumpName(362006, 1)
    nummappatches = int(uint(c2da_mem[names]) | uint(c2da_mem[names + 1]) << 0x8 | uint(c2da_mem[names + 2]) << 0x10 | uint(c2da_mem[names + 3]) << 0x18)
    name_p = names + 4
    patchlookup = Z_Malloc(int(uint64(nummappatches) * 4ul), 1, 0)
    i_2 = 0
    while (i_2 < nummappatches) {
        M_StringCopy(c2da_fp, name_p + i_2 * 8, 9ul)
        let c2da_fresh10 : int = W_CheckNumForName(c2da_fp)
        let c2da_fresh11 : uint = uint(c2da_fresh10)
        c2da_mem[patchlookup + i_2 * 4] = uint8(c2da_fresh11)
        c2da_mem[patchlookup + i_2 * 4 + 1] = uint8(c2da_fresh11 >> 0x8)
        c2da_mem[patchlookup + i_2 * 4 + 2] = uint8(c2da_fresh11 >> 0x10)
        c2da_mem[patchlookup + i_2 * 4 + 3] = uint8(c2da_fresh11 >> 0x18)
        i_2++
    }
    W_ReleaseLumpName(362006)
    maptex1 = W_CacheLumpName(362013, 1)
    maptex = maptex1
    numtextures1 = int(uint(c2da_mem[maptex]) | uint(c2da_mem[maptex + 1]) << 0x8 | uint(c2da_mem[maptex + 2]) << 0x10 | uint(c2da_mem[maptex + 3]) << 0x18)
    maxoff = W_LumpLength(uint(W_GetNumForName(362013)))
    directory = maptex + 1 * 4
    if (W_CheckNumForName(362022) != -1) {
        maptex2 = W_CacheLumpName(362022, 1)
        numtextures2 = int(uint(c2da_mem[maptex2]) | uint(c2da_mem[maptex2 + 1]) << 0x8 | uint(c2da_mem[maptex2 + 2]) << 0x10 | uint(c2da_mem[maptex2 + 3]) << 0x18)
        maxoff2 = W_LumpLength(uint(W_GetNumForName(362022)))
    } else {
        maptex2 = 0
        numtextures2 = 0
        maxoff2 = 0
    }
    numtextures = numtextures1 + numtextures2
    textures = Z_Malloc(int(uint64(numtextures) * 8ul), 1, 0)
    texturecolumnlump = Z_Malloc(int(uint64(numtextures) * 8ul), 1, 0)
    texturecolumnofs = Z_Malloc(int(uint64(numtextures) * 8ul), 1, 0)
    texturecomposite = Z_Malloc(int(uint64(numtextures) * 8ul), 1, 0)
    texturecompositesize = Z_Malloc(int(uint64(numtextures) * 4ul), 1, 0)
    texturewidthmask = Z_Malloc(int(uint64(numtextures) * 4ul), 1, 0)
    textureheight = Z_Malloc(int(uint64(numtextures) * 4ul), 1, 0)
    totalwidth = 0
    temp1 = W_GetNumForName(361978)
    temp2 = W_GetNumForName(361986) - 1
    temp3 = (temp2 - temp1 + 63) / 64 + (numtextures + 63) / 64
    if (I_ConsoleStdout() != 0x0) {
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 362031, [])
        i_2 = 0
        while (i_2 < temp3 + 9) {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 362033, [])
            i_2++
        }
        c2da_lin_printf(uint64(int(c2da_std_stderr())), 362035, [])
        i_2 = 0
        while (i_2 < temp3 + 10) {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 362037, [])
            i_2++
        }
    }
    i_2 = 0
    while (i_2 < numtextures) {
        if ((i_2 & 63) == 0) {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 361967, [])
        }
        if (i_2 == numtextures1) {
            maptex = maptex2
            maxoff = maxoff2
            directory = maptex + 1 * 4
        }
        offset = int(uint(c2da_mem[directory]) | uint(c2da_mem[directory + 1]) << 0x8 | uint(c2da_mem[directory + 2]) << 0x10 | uint(c2da_mem[directory + 3]) << 0x18)
        if (offset > maxoff) {
            I_Error(362039, [])
        }
        mtexture = maptex + offset
        let c2da_fresh12 : int = Z_Malloc(int(40ul + 8ul * uint64(int(int16(uint(c2da_mem[mtexture + 20]) | uint(c2da_mem[mtexture + 21]) << 0x8)) - 1)), 1, 0)
        let c2da_fresh13 : uint = uint(c2da_fresh12)
        c2da_mem[textures + i_2 * 8] = uint8(c2da_fresh13)
        c2da_mem[textures + i_2 * 8 + 1] = uint8(c2da_fresh13 >> 0x8)
        c2da_mem[textures + i_2 * 8 + 2] = uint8(c2da_fresh13 >> 0x10)
        c2da_mem[textures + i_2 * 8 + 3] = uint8(c2da_fresh13 >> 0x18)
        c2da_mem[textures + i_2 * 8 + 4] = 0u8
        c2da_mem[textures + i_2 * 8 + 5] = 0u8
        c2da_mem[textures + i_2 * 8 + 6] = 0u8
        c2da_mem[textures + i_2 * 8 + 7] = 0u8
        texture_0 = c2da_fresh12
        let c2da_fresh14 : int16 = int16(uint(c2da_mem[mtexture + 12]) | uint(c2da_mem[mtexture + 13]) << 0x8)
        let c2da_fresh15 : uint = uint(c2da_fresh14)
        c2da_mem[texture_0 + 8] = uint8(c2da_fresh15)
        c2da_mem[texture_0 + 9] = uint8(c2da_fresh15 >> 0x8)
        let c2da_fresh16 : int16 = int16(uint(c2da_mem[mtexture + 14]) | uint(c2da_mem[mtexture + 15]) << 0x8)
        let c2da_fresh17 : uint = uint(c2da_fresh16)
        c2da_mem[texture_0 + 10] = uint8(c2da_fresh17)
        c2da_mem[texture_0 + 11] = uint8(c2da_fresh17 >> 0x8)
        let c2da_fresh18 : int16 = int16(uint(c2da_mem[mtexture + 20]) | uint(c2da_mem[mtexture + 21]) << 0x8)
        let c2da_fresh19 : uint = uint(c2da_fresh18)
        c2da_mem[texture_0 + 24] = uint8(c2da_fresh19)
        c2da_mem[texture_0 + 25] = uint8(c2da_fresh19 >> 0x8)
        c2da_lin_memcpy(texture_0, mtexture, 8ul)
        mpatch = mtexture + 22 + 0 * 10
        patch_2 = texture_0 + 28 + 0 * 8
        j = 0
        while (j < int(int16(uint(c2da_mem[texture_0 + 24]) | uint(c2da_mem[texture_0 + 25]) << 0x8))) {
            let c2da_fresh20 : int16 = int16(uint(c2da_mem[mpatch]) | uint(c2da_mem[mpatch + 1]) << 0x8)
            let c2da_fresh21 : uint = uint(c2da_fresh20)
            c2da_mem[patch_2] = uint8(c2da_fresh21)
            c2da_mem[patch_2 + 1] = uint8(c2da_fresh21 >> 0x8)
            let c2da_fresh22 : int16 = int16(uint(c2da_mem[mpatch + 2]) | uint(c2da_mem[mpatch + 3]) << 0x8)
            let c2da_fresh23 : uint = uint(c2da_fresh22)
            c2da_mem[patch_2 + 2] = uint8(c2da_fresh23)
            c2da_mem[patch_2 + 3] = uint8(c2da_fresh23 >> 0x8)
            let c2da_fresh24 : int = patchlookup + int(int16(uint(c2da_mem[mpatch + 4]) | uint(c2da_mem[mpatch + 5]) << 0x8)) * 4
            let c2da_fresh25 : int = int(uint(c2da_mem[c2da_fresh24]) | uint(c2da_mem[c2da_fresh24 + 1]) << 0x8 | uint(c2da_mem[c2da_fresh24 + 2]) << 0x10 | uint(c2da_mem[c2da_fresh24 + 3]) << 0x18)
            let c2da_fresh26 : uint = uint(c2da_fresh25)
            c2da_mem[patch_2 + 4] = uint8(c2da_fresh26)
            c2da_mem[patch_2 + 5] = uint8(c2da_fresh26 >> 0x8)
            c2da_mem[patch_2 + 6] = uint8(c2da_fresh26 >> 0x10)
            c2da_mem[patch_2 + 7] = uint8(c2da_fresh26 >> 0x18)
            if (int(uint(c2da_mem[patch_2 + 4]) | uint(c2da_mem[patch_2 + 5]) << 0x8 | uint(c2da_mem[patch_2 + 6]) << 0x10 | uint(c2da_mem[patch_2 + 7]) << 0x18) == -1) {
                I_Error(362077, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(texture_0))])
            }
            j++
            mpatch += 10
            patch_2 += 8
        }
        let c2da_fresh27 : int = Z_Malloc(int(uint64(int16(uint(c2da_mem[texture_0 + 8]) | uint(c2da_mem[texture_0 + 9]) << 0x8)) * 2ul), 1, 0)
        let c2da_fresh28 : uint = uint(c2da_fresh27)
        c2da_mem[texturecolumnlump + i_2 * 8] = uint8(c2da_fresh28)
        c2da_mem[texturecolumnlump + i_2 * 8 + 1] = uint8(c2da_fresh28 >> 0x8)
        c2da_mem[texturecolumnlump + i_2 * 8 + 2] = uint8(c2da_fresh28 >> 0x10)
        c2da_mem[texturecolumnlump + i_2 * 8 + 3] = uint8(c2da_fresh28 >> 0x18)
        c2da_mem[texturecolumnlump + i_2 * 8 + 4] = 0u8
        c2da_mem[texturecolumnlump + i_2 * 8 + 5] = 0u8
        c2da_mem[texturecolumnlump + i_2 * 8 + 6] = 0u8
        c2da_mem[texturecolumnlump + i_2 * 8 + 7] = 0u8
        let c2da_fresh29 : int = Z_Malloc(int(uint64(int16(uint(c2da_mem[texture_0 + 8]) | uint(c2da_mem[texture_0 + 9]) << 0x8)) * 2ul), 1, 0)
        let c2da_fresh30 : uint = uint(c2da_fresh29)
        c2da_mem[texturecolumnofs + i_2 * 8] = uint8(c2da_fresh30)
        c2da_mem[texturecolumnofs + i_2 * 8 + 1] = uint8(c2da_fresh30 >> 0x8)
        c2da_mem[texturecolumnofs + i_2 * 8 + 2] = uint8(c2da_fresh30 >> 0x10)
        c2da_mem[texturecolumnofs + i_2 * 8 + 3] = uint8(c2da_fresh30 >> 0x18)
        c2da_mem[texturecolumnofs + i_2 * 8 + 4] = 0u8
        c2da_mem[texturecolumnofs + i_2 * 8 + 5] = 0u8
        c2da_mem[texturecolumnofs + i_2 * 8 + 6] = 0u8
        c2da_mem[texturecolumnofs + i_2 * 8 + 7] = 0u8
        j = 1
        while (j * 2 <= int(int16(uint(c2da_mem[texture_0 + 8]) | uint(c2da_mem[texture_0 + 9]) << 0x8))) {
            j <<= 1
        }
        let c2da_fresh31 : int = j - 1
        let c2da_fresh32 : uint = uint(c2da_fresh31)
        c2da_mem[texturewidthmask + i_2 * 4] = uint8(c2da_fresh32)
        c2da_mem[texturewidthmask + i_2 * 4 + 1] = uint8(c2da_fresh32 >> 0x8)
        c2da_mem[texturewidthmask + i_2 * 4 + 2] = uint8(c2da_fresh32 >> 0x10)
        c2da_mem[texturewidthmask + i_2 * 4 + 3] = uint8(c2da_fresh32 >> 0x18)
        let c2da_fresh33 : int = int(int16(uint(c2da_mem[texture_0 + 10]) | uint(c2da_mem[texture_0 + 11]) << 0x8)) << 16
        let c2da_fresh34 : uint = uint(c2da_fresh33)
        c2da_mem[textureheight + i_2 * 4] = uint8(c2da_fresh34)
        c2da_mem[textureheight + i_2 * 4 + 1] = uint8(c2da_fresh34 >> 0x8)
        c2da_mem[textureheight + i_2 * 4 + 2] = uint8(c2da_fresh34 >> 0x10)
        c2da_mem[textureheight + i_2 * 4 + 3] = uint8(c2da_fresh34 >> 0x18)
        totalwidth += int(int16(uint(c2da_mem[texture_0 + 8]) | uint(c2da_mem[texture_0 + 9]) << 0x8))
        i_2++
        directory += 4
    }
    Z_Free(patchlookup)
    W_ReleaseLumpName(362013)
    if (maptex2 != 0) {
        W_ReleaseLumpName(362022)
    }
    i_2 = 0
    while (i_2 < numtextures) {
        R_GenerateLookup(i_2)
        i_2++
    }
    texturetranslation = Z_Malloc(int(uint64(numtextures + 1) * 4ul), 1, 0)
    i_2 = 0
    while (i_2 < numtextures) {
        let c2da_fresh35 : uint = uint(i_2)
        c2da_mem[texturetranslation + i_2 * 4] = uint8(c2da_fresh35)
        c2da_mem[texturetranslation + i_2 * 4 + 1] = uint8(c2da_fresh35 >> 0x8)
        c2da_mem[texturetranslation + i_2 * 4 + 2] = uint8(c2da_fresh35 >> 0x10)
        c2da_mem[texturetranslation + i_2 * 4 + 3] = uint8(c2da_fresh35 >> 0x18)
        i_2++
    }
    GenerateTextureHashTable()
    return
}
[sideeffects]
def private R_GenerateLookup_c2da_frame(var texnum_0 : int; c2da_fp : int) {
    var texture_1 : int
    var patch_3 : int
    var realpatch_0 : int
    var x_0 : int
    var x1_0 : int
    var x2_0 : int
    var i_4 : int
    var collump_0 : int
    var colofs_0 : int
    texture_1 = int(uint(c2da_mem[textures + texnum_0 * 8]) | uint(c2da_mem[textures + texnum_0 * 8 + 1]) << 0x8 | uint(c2da_mem[textures + texnum_0 * 8 + 2]) << 0x10 | uint(c2da_mem[textures + texnum_0 * 8 + 3]) << 0x18)
    let c2da_fresh42 : uint = 0u
    c2da_mem[texturecomposite + texnum_0 * 8] = uint8(c2da_fresh42)
    c2da_mem[texturecomposite + texnum_0 * 8 + 1] = uint8(c2da_fresh42 >> 0x8)
    c2da_mem[texturecomposite + texnum_0 * 8 + 2] = uint8(c2da_fresh42 >> 0x10)
    c2da_mem[texturecomposite + texnum_0 * 8 + 3] = uint8(c2da_fresh42 >> 0x18)
    c2da_mem[texturecomposite + texnum_0 * 8 + 4] = 0u8
    c2da_mem[texturecomposite + texnum_0 * 8 + 5] = 0u8
    c2da_mem[texturecomposite + texnum_0 * 8 + 6] = 0u8
    c2da_mem[texturecomposite + texnum_0 * 8 + 7] = 0u8
    let c2da_fresh43 : int = 0
    let c2da_fresh44 : uint = uint(c2da_fresh43)
    c2da_mem[texturecompositesize + texnum_0 * 4] = uint8(c2da_fresh44)
    c2da_mem[texturecompositesize + texnum_0 * 4 + 1] = uint8(c2da_fresh44 >> 0x8)
    c2da_mem[texturecompositesize + texnum_0 * 4 + 2] = uint8(c2da_fresh44 >> 0x10)
    c2da_mem[texturecompositesize + texnum_0 * 4 + 3] = uint8(c2da_fresh44 >> 0x18)
    collump_0 = int(uint(c2da_mem[texturecolumnlump + texnum_0 * 8]) | uint(c2da_mem[texturecolumnlump + texnum_0 * 8 + 1]) << 0x8 | uint(c2da_mem[texturecolumnlump + texnum_0 * 8 + 2]) << 0x10 | uint(c2da_mem[texturecolumnlump + texnum_0 * 8 + 3]) << 0x18)
    colofs_0 = int(uint(c2da_mem[texturecolumnofs + texnum_0 * 8]) | uint(c2da_mem[texturecolumnofs + texnum_0 * 8 + 1]) << 0x8 | uint(c2da_mem[texturecolumnofs + texnum_0 * 8 + 2]) << 0x10 | uint(c2da_mem[texturecolumnofs + texnum_0 * 8 + 3]) << 0x18)
    let c2da_fresh45 : int = Z_Malloc(int(int16(uint(c2da_mem[texture_1 + 8]) | uint(c2da_mem[texture_1 + 9]) << 0x8)), 1, c2da_fp)
    let c2da_fresh46 : uint = uint(c2da_fresh45)
    c2da_mem[c2da_fp] = uint8(c2da_fresh46)
    c2da_mem[c2da_fp + 1] = uint8(c2da_fresh46 >> 0x8)
    c2da_mem[c2da_fp + 2] = uint8(c2da_fresh46 >> 0x10)
    c2da_mem[c2da_fp + 3] = uint8(c2da_fresh46 >> 0x18)
    c2da_mem[c2da_fp + 4] = 0u8
    c2da_mem[c2da_fp + 5] = 0u8
    c2da_mem[c2da_fp + 6] = 0u8
    c2da_mem[c2da_fp + 7] = 0u8
    c2da_lin_memset(int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18), 0, uint64(int16(uint(c2da_mem[texture_1 + 8]) | uint(c2da_mem[texture_1 + 9]) << 0x8)))
    patch_3 = texture_1 + 28
    i_4 = 0
    patch_3 = texture_1 + 28
    while (i_4 < int(int16(uint(c2da_mem[texture_1 + 24]) | uint(c2da_mem[texture_1 + 25]) << 0x8))) {
        realpatch_0 = W_CacheLumpNum(int(uint(c2da_mem[patch_3 + 4]) | uint(c2da_mem[patch_3 + 5]) << 0x8 | uint(c2da_mem[patch_3 + 6]) << 0x10 | uint(c2da_mem[patch_3 + 7]) << 0x18), 8)
        x1_0 = int(int16(uint(c2da_mem[patch_3]) | uint(c2da_mem[patch_3 + 1]) << 0x8))
        x2_0 = x1_0 + int(int16(uint(c2da_mem[realpatch_0]) | uint(c2da_mem[realpatch_0 + 1]) << 0x8))
        if (x1_0 < 0) {
            x_0 = 0
        } else {
            x_0 = x1_0
        }
        if (x2_0 > int(int16(uint(c2da_mem[texture_1 + 8]) | uint(c2da_mem[texture_1 + 9]) << 0x8))) {
            x2_0 = int(int16(uint(c2da_mem[texture_1 + 8]) | uint(c2da_mem[texture_1 + 9]) << 0x8))
        }
        while (x_0 < x2_0) {
            let c2da_fresh47 : int = int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) + x_0
            let c2da_fresh48 : uint8 = c2da_mem[c2da_fresh47]
            let c2da_fresh49 : uint8 = uint8(int(c2da_fresh48) + 1)
            c2da_mem[c2da_fresh47] = c2da_fresh49
            let c2da_fresh50 : int16 = int16(int(uint(c2da_mem[patch_3 + 4]) | uint(c2da_mem[patch_3 + 5]) << 0x8 | uint(c2da_mem[patch_3 + 6]) << 0x10 | uint(c2da_mem[patch_3 + 7]) << 0x18))
            let c2da_fresh51 : uint = uint(c2da_fresh50)
            c2da_mem[collump_0 + x_0 * 2] = uint8(c2da_fresh51)
            c2da_mem[collump_0 + x_0 * 2 + 1] = uint8(c2da_fresh51 >> 0x8)
            let c2da_fresh52 : uint16 = uint16(int(uint(c2da_mem[realpatch_0 + 8 + (x_0 - x1_0) * 4]) | uint(c2da_mem[realpatch_0 + 8 + (x_0 - x1_0) * 4 + 1]) << 0x8 | uint(c2da_mem[realpatch_0 + 8 + (x_0 - x1_0) * 4 + 2]) << 0x10 | uint(c2da_mem[realpatch_0 + 8 + (x_0 - x1_0) * 4 + 3]) << 0x18) + 3)
            let c2da_fresh53 : uint = uint(c2da_fresh52)
            c2da_mem[colofs_0 + x_0 * 2] = uint8(c2da_fresh53)
            c2da_mem[colofs_0 + x_0 * 2 + 1] = uint8(c2da_fresh53 >> 0x8)
            x_0++
        }
        i_4++
        patch_3 += 8
    }
    x_0 = 0
    while (x_0 < int(int16(uint(c2da_mem[texture_1 + 8]) | uint(c2da_mem[texture_1 + 9]) << 0x8))) {
        let c2da_fresh54 : int = int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) + x_0
        if (c2da_mem[c2da_fresh54] == 0) {
            c2da_lin_printf(uint64(int(c2da_std_stderr())), 362121, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(texture_1))])
            return
        }
        let c2da_fresh55 : int = int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18) + x_0
        if (int(c2da_mem[c2da_fresh55]) > 1) {
            let c2da_fresh56 : int16 = int16(-1)
            let c2da_fresh57 : uint = uint(c2da_fresh56)
            c2da_mem[collump_0 + x_0 * 2] = uint8(c2da_fresh57)
            c2da_mem[collump_0 + x_0 * 2 + 1] = uint8(c2da_fresh57 >> 0x8)
            let c2da_fresh58 : uint16 = uint16(int(uint(c2da_mem[texturecompositesize + texnum_0 * 4]) | uint(c2da_mem[texturecompositesize + texnum_0 * 4 + 1]) << 0x8 | uint(c2da_mem[texturecompositesize + texnum_0 * 4 + 2]) << 0x10 | uint(c2da_mem[texturecompositesize + texnum_0 * 4 + 3]) << 0x18))
            let c2da_fresh59 : uint = uint(c2da_fresh58)
            c2da_mem[colofs_0 + x_0 * 2] = uint8(c2da_fresh59)
            c2da_mem[colofs_0 + x_0 * 2 + 1] = uint8(c2da_fresh59 >> 0x8)
            if (int(uint(c2da_mem[texturecompositesize + texnum_0 * 4]) | uint(c2da_mem[texturecompositesize + texnum_0 * 4 + 1]) << 0x8 | uint(c2da_mem[texturecompositesize + texnum_0 * 4 + 2]) << 0x10 | uint(c2da_mem[texturecompositesize + texnum_0 * 4 + 3]) << 0x18) > 65536 - int(int16(uint(c2da_mem[texture_1 + 10]) | uint(c2da_mem[texture_1 + 11]) << 0x8))) {
                I_Error(362168, [C2daVaArg(tag = 1, i64 = int64(texnum_0), f64 = 0.0lf, raw = 0x0)])
            }
            let c2da_fresh60 : int = int(uint(c2da_mem[texturecompositesize + texnum_0 * 4]) | uint(c2da_mem[texturecompositesize + texnum_0 * 4 + 1]) << 0x8 | uint(c2da_mem[texturecompositesize + texnum_0 * 4 + 2]) << 0x10 | uint(c2da_mem[texturecompositesize + texnum_0 * 4 + 3]) << 0x18) + int(int16(uint(c2da_mem[texture_1 + 10]) | uint(c2da_mem[texture_1 + 11]) << 0x8))
            let c2da_fresh61 : uint = uint(c2da_fresh60)
            c2da_mem[texturecompositesize + texnum_0 * 4] = uint8(c2da_fresh61)
            c2da_mem[texturecompositesize + texnum_0 * 4 + 1] = uint8(c2da_fresh61 >> 0x8)
            c2da_mem[texturecompositesize + texnum_0 * 4 + 2] = uint8(c2da_fresh61 >> 0x10)
            c2da_mem[texturecompositesize + texnum_0 * 4 + 3] = uint8(c2da_fresh61 >> 0x18)
        }
        x_0++
    }
    Z_Free(int(uint(c2da_mem[c2da_fp]) | uint(c2da_mem[c2da_fp + 1]) << 0x8 | uint(c2da_mem[c2da_fp + 2]) << 0x10 | uint(c2da_mem[c2da_fp + 3]) << 0x18))
    return
}
[sideeffects]
def private R_FlatNumForName_c2da_frame(var name : int; c2da_fp : int) : int {
    var i_6 : int = W_CheckNumForName(name)
    if (i_6 == -1) {
        let c2da_fresh75 : int8 = int8(0)
        c2da_mem[c2da_fp + 8] = uint8(c2da_fresh75)
        c2da_lin_memcpy(c2da_fp, name, 8ul)
        I_Error(362205, [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = uint64(c2da_fp))])
    }
    return i_6 - firstflat
}

// This unit's static data, at heap offset 361888.
let private c2da_lin_static_r_data_seg = fixed_array<int>(361888, 381)
let private c2da_lin_static_r_data = fixed_array<uint64>(0x32632f746f6f722ful, 0x747365742f736164ul, 0x6c61756e616d2f73ul, 0x6e65676d6f6f642ful, 0x7370752f63697265ul, 0x6f642f6d61657274ul, 0x6972656e65676d6ful, 0x65676d6f6f642f63ul, 0x5f722f636972656eul, 0x2e00632e61746164ul, 0x414d524f4c4f4300ul, 0x524154535f530050ul, 0x444e455f530054ul, 0x54524154535f46ul, 0x4e5000444e455f46ul, 0x5845540053454d41ul, 0x4554003145525554ul, 0x5b00324552555458ul, 0x520008005d002000ul, 0x78655474696e495ful, 0x62203a7365727574ul, 0x7574786574206461ul, 0x6365726964206572ul, 0x495f520079726f74ul, 0x757478655474696eul, 0x73694d203a736572ul, 0x74617020676e6973ul, 0x6574206e69206863ul, 0x7325206572757478ul, 0x72656e65475f5200ul, 0x756b6f6f4c657461ul, 0x6d756c6f63203a70ul, 0x756f68746977206eul, 0x6374617020612074ul, 0xa297325282068ul, 0x6172656e65475f52ul, 0x70756b6f6f4c6574ul, 0x727574786574203aul, 0x2073692069252065ul, 0x465f52006b34363eul, 0x6f466d754e74616cul, 0x25203a656d614e72ul, 0x6f6620746f6e2073ul, 0x65545f5200646e75ul, 0x6d754e6572757478ul, 0x3a656d614e726f46ul, 0x20746f6e20732520ul, 0x646e756f66ul)

[init]
def private c2da_lin_init_static_r_data() {
    c2da_lin_setup()
    var c2da_lin_p = 0
    for (s in range(1)) {
        let at = c2da_lin_static_r_data_seg[s * 2]
        for (k in range(c2da_lin_static_r_data_seg[s * 2 + 1])) {
            c2da_mem[at + k] = uint8(c2da_lin_static_r_data[c2da_lin_p >> 3] >> uint64((c2da_lin_p & 7) * 8))
            c2da_lin_p++
        }
    }
}
