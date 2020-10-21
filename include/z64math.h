#ifndef _Z64MATH_H_
#define _Z64MATH_H_

#include <ultra64.h>

#define SHT_MAX 32767.0f

typedef struct {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} Vec3f; // size = 0xC

typedef struct {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
} Vec3s; // size = 0x6

typedef struct {
    /* 0x0000 */ Vec3s center;
    /* 0x000C */ s16 radius;
} Sphere16; // size = 0x08

typedef struct {
    /* 0x0000 */ Vec3f center;
    /* 0x000C */ f32 radius;
} Spheref; // size = 0x10

typedef struct {
    /* 0x0000 */ s16 radius;
    /* 0x0002 */ s16 height;
    /* 0x0004 */ s16 yShift;
    /* 0x0006 */ Vec3s pos;
} Cylinder16; // size = 0x0C

typedef struct {
    /* 0x00 */ f32 radius;
    /* 0x04 */ f32 height;
    /* 0x08 */ f32 yShift;
    /* 0x0C */ Vec3f pos;
} Cylinderf; // size = 0x18

typedef struct {
    /* 0x0000 */ Vec3f a;
    /* 0x000C */ Vec3f b;
} Linef; // size = 0x18

typedef struct {
    /* 0x0000 */ Vec3f normal;
    /* 0x000C */ f32 originDist;
} Plane; // size = 0x10

typedef struct {
    /* 0x0000 */ Vec3f vtx[3];
    /* 0x0024 */ Plane plane;
} TriNorm; // size = 0x34

#endif
