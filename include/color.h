#ifndef _COLOR_H_
#define _COLOR_H_

#include <PR/ultratypes.h>

typedef struct {
    /* 0x0 */ u8 red;
    /* 0x1 */ u8 green;
    /* 0x2 */ u8 blue;
    /* 0x3 */ u8 alpha;
} ColorRGBA8; // size = 0x4

typedef struct {
    /* 0x0 */ f32 red;
    /* 0x4 */ f32 green;
    /* 0x8 */ f32 blue;
    /* 0xC */ f32 alpha;
} Color_RGBAf; // size = 0x4

typedef struct {
    /* 0x0 */ u8 red;
    /* 0x1 */ u8 green;
    /* 0x2 */ u8 blue;
} RGB; // size = 0x3

typedef struct {
    /* 0x0 */ u8 red;
    /* 0x1 */ u8 green;
    /* 0x2 */ u8 blue;
    /* 0x3 */ u8 alpha;
} RGBA8; // size = 0x4

#endif
