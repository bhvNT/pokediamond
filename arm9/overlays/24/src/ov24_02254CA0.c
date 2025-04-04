#include "global.h"

#include "constants/sndseq.h"

#include "graphic/poketch.naix"

#include "SPI_pm.h"
#include "bg_window.h"
#include "gf_gfx_loader.h"
#include "overlay_24.h"
#include "unk_0200CA44.h"

extern BOOL sub_0208946C(u32 arg0, void *arg1, u32 arg2);
extern void sub_02089444(u32 arg0, void *arg1, u32 arg2);
extern void ov20_02252D7C(u32 arg0, u32 arg1);
extern void ov20_02253F28(u32 *arg0, u32 arg1);
extern void Poketch_PlaySoundEffect(u32 arg0);
extern void *ov20_022538A0(void *arg0);
extern void ov20_02253888(u32 *arg0, void *arg1);
extern BOOL ov20_022537B8(void *arg0);
extern BOOL ov20_02253794(void *arg0, u8 arg1);
extern void ov20_022537E0(const u32 *arg0, u32 arg1, void *arg2, void *arg3, void *arg4, u32 arg5, u32 arg6);
extern BOOL ov20_02253FBC(void *arg0, NarcId arg1, u32 arg2, u32 arg3, HeapID arg4);
extern u32 *ov20_02253E74(u32 arg0, void *arg1, void *arg2);
extern void ov20_02254014(void *arg0);
extern void ov20_02253F14(u32 arg0, void *arg1);
extern void ov20_022536F4(void *arg0, u32 arg1);
extern BgConfig *ov20_02252D34();
extern u32 ov20_02252D24();

BOOL ov24_02254CA0(MemoPadDisplayHandler **displayHandlerOut, MemoPadDrawState *drawState) {
    MemoPadDisplayHandler *displayHandler = AllocFromHeap(HEAP_ID_POKETCH_APP, sizeof(MemoPadDisplayHandler));
    if (displayHandler != NULL) {
        GF_ASSERT(GF_heap_c_dummy_return_true(HEAP_ID_POKETCH_MAIN));
        ov20_022536F4(&(displayHandler->unk8), 0x10);
        GF_ASSERT(GF_heap_c_dummy_return_true(HEAP_ID_POKETCH_MAIN));
        displayHandler->drawState = drawState;
        displayHandler->config = ov20_02252D34();
        displayHandler->unk50 = ov20_02252D24();
        GF_ASSERT(GF_heap_c_dummy_return_true(HEAP_ID_POKETCH_MAIN));
        *displayHandlerOut = displayHandler;
        return TRUE;
    }
    return FALSE;
}

BOOL ov24_02254D00(MemoPadDisplayHandler *displayHandler) {
    static const WindowTemplate template = {
        .bgId = GF_BG_LYR_SUB_3,
        .left = 2,
        .top = 2,
        .width = 20,
        .height = 19,
        .palette = 0,
        .baseTile = 12,
    };
    displayHandler->window = AllocWindows(HEAP_ID_POKETCH_APP, 1);
    if (displayHandler->window != NULL) {
        AddWindow(displayHandler->config, displayHandler->window, &template);
        if (sub_0208946C(displayHandler->drawState->unk16E8, displayHandler->window->pixelBuffer, 0x2f80) == 0) {
            FillWindowPixelBuffer(displayHandler->window, MEMO_PAD_PIXEL_TYPE_EMPTY);
        }
        return TRUE;
    }
    return FALSE;
}

void ov24_02254D48(MemoPadDisplayHandler *displayHandler) {
    if (displayHandler != NULL) {
        GF_ASSERT(GF_heap_c_dummy_return_true(HEAP_ID_POKETCH_MAIN));
        if (displayHandler->window != NULL) {
            sub_02089444(displayHandler->drawState->unk16E8, displayHandler->window->pixelBuffer, 0x2f80);
            RemoveWindow(displayHandler->window);
            FreeToHeap(displayHandler->window);
        }
        FreeToHeap(displayHandler);
    }
}

void ov24_02254D8C(MemoPadDisplayHandler *displayHandler, u32 arg1) {
    // TODO: types
    static const u32 ov24_0225516C[] = {
        0x00,
        (u32)ov24_02254DDC,
        0x00,
        0x01,
        (u32)ov24_02254EE0,
        0x00,
        0x02,
        (u32)ov24_02254F28,
        0x00,
        0x03,
        (u32)ov24_02254F40,
        0x00,
        0x04,
        (u32)ov24_02255038,
        0x00,
        0x05,
        (u32)ov24_02255050,
        0x00,
        0x00,
        0x00000000,
        0x00,
    };
    ov20_022537E0(ov24_0225516C, arg1, displayHandler, displayHandler->drawState, &(displayHandler->unk8), 2, 8);
}

BOOL ov24_02254DB0(MemoPadDisplayHandler *displayHandler, u8 arg1) {
    return ov20_02253794(&(displayHandler->unk8), arg1);
}

BOOL ov24_02254DBC(MemoPadDisplayHandler *displayHandler) {
    return ov20_022537B8(&(displayHandler->unk8));
}

void ov24_02254DC8(void *arg0) {
    ov20_02253888(&(((MemoPadDisplayHandler *)ov20_022538A0(arg0))->unk8), arg0);
}

void ov24_02254DDC(void *arg0, void *arg1) {
    static const BgTemplate template_7000 = {
        .x = 0,
        .y = 0,
        .bufferSize = 0,
        .baseTile = 0,
        .size = 1,
        .colorMode = 0,
        .screenBase = GX_BG_SCRBASE_0x7000,
        .charBase = GX_BG_CHARBASE_0x00000,
        .bgExtPltt = 0,
        .priority = 2,
        .areaOver = 0,
        .dummy = 0,
        .mosaic = 0,
    };
    static const BgTemplate template_7800 = {
        .x = 0,
        .y = 0,
        .bufferSize = 0x800,
        .baseTile = 0,
        .size = 1,
        .colorMode = 0,
        .screenBase = GX_BG_SCRBASE_0x7800,
        .charBase = GX_BG_CHARBASE_0x00000,
        .bgExtPltt = 0,
        .priority = 3,
        .areaOver = 0,
        .dummy = 0,
        .mosaic = 0,
    };
    GF_ASSERT(GF_heap_c_dummy_return_true(HEAP_ID_POKETCH_APP));
    GXSDispCnt dispcnt;
    MemoPadDisplayHandler *displayHandler = ov20_022538A0(arg1);
    InitBgFromTemplate(displayHandler->config, GF_BG_LYR_SUB_2, &template_7000, 0);
    InitBgFromTemplate(displayHandler->config, GF_BG_LYR_SUB_3, &template_7800, 0);
    GF_ASSERT(GF_heap_c_dummy_return_true(HEAP_ID_POKETCH_APP));
    GfGfxLoader_LoadCharData(NARC_GRAPHIC_POKETCH, NARC_poketch_narc_0030_bin, displayHandler->config, GF_BG_LYR_SUB_2, 0, 0, TRUE, HEAP_ID_POKETCH_APP);
    GfGfxLoader_LoadScrnData(NARC_GRAPHIC_POKETCH, NARC_poketch_narc_0031_NSCR, displayHandler->config, GF_BG_LYR_SUB_2, 0, 0, TRUE, HEAP_ID_POKETCH_APP);
    ov20_02252D7C(0, 0);
    GF_ASSERT(GF_heap_c_dummy_return_true(HEAP_ID_POKETCH_APP));
    ov24_02254D00(displayHandler);
    CopyWindowToVram(displayHandler->window);
    GF_ASSERT(GF_heap_c_dummy_return_true(HEAP_ID_POKETCH_APP));
    ov24_02255078(displayHandler);
    GF_ASSERT(GF_heap_c_dummy_return_true(HEAP_ID_POKETCH_APP));
    BgCommitTilemapBufferToVram(displayHandler->config, GF_BG_LYR_SUB_3);
    dispcnt.raw = reg_GXS_DB_DISPCNT;
    GXS_SetVisiblePlane(dispcnt.visiblePlane | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    ov24_02254DC8(arg1);
    GF_ASSERT(GF_heap_c_dummy_return_true(HEAP_ID_POKETCH_APP));
}

void ov24_02254EE0(u32 arg0, void *arg1) {
    MemoPadDisplayHandler *displayHandler = ov20_022538A0(arg1);
    if (displayHandler->drawState->touchType == TOUCH_TYPE_DRAW) {
        ov20_02253F28(displayHandler->unk68[0], 0);
        ov20_02253F28(displayHandler->unk68[1], 3);
    } else {
        ov20_02253F28(displayHandler->unk68[0], 1);
        ov20_02253F28(displayHandler->unk68[1], 2);
    }
    Poketch_PlaySoundEffect(SEQ_SE_DP_POKETCH_003);
    ov24_02254DC8(arg1);
}

void ov24_02254F28(s32 arg0, void *arg1) {
    MemoPadDisplayHandler *displayHandler = ov20_022538A0(arg1);
    CopyWindowPixelsToVram_TextMode(displayHandler->window);
    ov24_02254DC8(arg1);
}

void ov24_02254F40(u32 arg0, void *arg1) {
    MemoPadDisplayHandler *displayHandler = ov20_022538A0(arg1);
    MemoPadDrawState *drawState = displayHandler->drawState;
    if (drawState->touchType == TOUCH_TYPE_ERASE) {
        s32 width, height;
        width = height = 8;
        s32 x = drawState->lastModifiedX * 2 - 4;
        s32 y = drawState->lastModifiedY * 2 - 4;
        if (x < 0) {
            width += x;
            x = 0;
        }
        if (y < 0) {
            height += y;
            y = 0;
        }
        FillWindowPixelRect(displayHandler->window, MEMO_PAD_PIXEL_TYPE_EMPTY, x, y, width, height);
        s32 a = (x >> 3) + (y >> 3) * 0x14;
        s32 e = ((x + width - 1) >> 3) - (x >> 3) + 1;
        s32 b = ((y + height - 1) >> 3) - (y >> 3) + 1;
        while (b--) {
            GXS_LoadBG3Char((u8 *)(displayHandler->window->pixelBuffer) + (a * 0x20), (a + 0xc) * 0x20, e * 0x20);
            a += 0x14;
        }
    } else {
        s32 height = 2;
        s32 width = 2;
        s32 x = drawState->lastModifiedX * 2;
        s32 y = drawState->lastModifiedY * 2;
        s32 a = (x >> 3) + ((y >> 3) * 0x14);
        FillWindowPixelRect(displayHandler->window, MEMO_PAD_PIXEL_TYPE_FILLED, x, y, width, height);
        GXS_LoadBG3Char((u8 *)(displayHandler->window->pixelBuffer) + a * 0x20, (a + 0xc) * 0x20, 0x20);
    }
    ov24_02254DC8(arg1);
}

void ov24_02255038(u32 arg0, void *arg1) {
    MemoPadDisplayHandler *displayHandler = ov20_022538A0(arg1);
    CopyWindowPixelsToVram_TextMode(displayHandler->window);
    ov24_02254DC8(arg1);
}

void ov24_02255050(u32 arg0, void *arg1) {
    MemoPadDisplayHandler *displayHandler = ov20_022538A0(arg1);
    ov24_022550D4(displayHandler);
    FreeBgTilemapBuffer(displayHandler->config, GF_BG_LYR_SUB_2);
    FreeBgTilemapBuffer(displayHandler->config, GF_BG_LYR_SUB_3);
    ov24_02254DC8(arg1);
}

void ov24_02255078(MemoPadDisplayHandler *displayHandler) {
    // TODO: types
    static const u32 ov24_0225514C[2][4] = {
        { 0xC0000, 0x38000, 0x2000000, 0x0 },
        { 0xC0000, 0x88000, 0x2000003, 0x0 }
    };
    GfGfxLoader_LoadWholePalette(NARC_GRAPHIC_POKETCH, NARC_poketch_narc_0032_bin, PM_LCD_BOTTOM, 0, 0, TRUE, HEAP_ID_POKETCH_APP);
    if (ov20_02253FBC(&(displayHandler->unk54), NARC_GRAPHIC_POKETCH, NARC_poketch_narc_0033_NCER, NARC_poketch_narc_0034_NANR, HEAP_ID_POKETCH_APP)) {
        for (s32 i = 0; i < 2; i++) {
            displayHandler->unk68[i] = ov20_02253E74(displayHandler->unk50, &(ov24_0225514C[i]), &(displayHandler->unk54));
        }
    }
}

void ov24_022550D4(MemoPadDisplayHandler *displayHandler) {
    for (u32 i = 0; i < 2; i++) {
        ov20_02253F14(displayHandler->unk50, displayHandler->unk68[i]);
    }
    ov20_02254014(&(displayHandler->unk54));
}
