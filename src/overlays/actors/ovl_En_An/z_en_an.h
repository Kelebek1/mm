#ifndef Z_EN_AN_H
#define Z_EN_AN_H

#include <global.h>

struct EnAn;

typedef void (*EnAnActionFunc)(struct EnAn*, GlobalContext*);
typedef s32 (*EnAnFunc)(struct EnAn*, GlobalContext*);
//typedef void (*EnAnFunc)(GlobalContext*);

typedef struct {
    /* 0x00 */ u8 unk_00;
    /* 0x04 */ void* unk_04;
} EnAn_struct_1DC;

typedef struct EnAn {
    /* 0x000 */ Actor actor;
    /* 0x144 */ SkelAnime skelAnime;
    /* 0x188 */ EnAnActionFunc actionFunc;
    /* 0x18C */ EnAnActionFunc unk_18C;
    /* 0x190 */ ColCylinder collider;
    /* 0x1DC */ EnAn_struct_1DC* unk_1DC;
    /* 0x1E0 */ Vec3f unk_1E0;
    /* 0x1EC */ f32 unk_1EC;
    /* 0x1F0 */ s32 unk_1F0;
    /* 0x1F4 */ s32 unk_1F4;
    /* 0x1F8 */ s32 unk_1F8;
    /* 0x1FC */ s32 unk_1FC;
    /* 0x200 */ u8 unk_200;
    /* 0x204 */ s32* unk_204; // a struct of some kind
    /* 0x208 */ s8 unk_208;
    /* 0x209 */ s8 unk_209;
    /* 0x20A */ s8 unk_20A;
    /* 0x20B */ s8 unk_20B;
    /* 0x20C */ s8 unk_20C;
    /* 0x210 */ s32 unk_210;
    /* 0x214 */ s8 unk_214;
    /* 0x215 */ s8 unk_215;
    /* 0x218 */ Actor* unk_218;
    /* 0x21C */ char unk21C[0xC];
    /* 0x228 */ Vec3f unk_228;
    /* 0x234 */ Vec3f unk_234;
    /* 0x240 */ Vec3f unk_240;
    /* 0x24C */ char unk24C[0xC];
    /* 0x258 */ Vec3s unk_258;
    /* 0x25E */ char unk25E[0x6];
    /* 0x264 */ Vec3s limbDrawTable[21];
    /* 0x2E2 */ Vec3s transitionDrawTable[21];
    /* 0x360 */ u16 unk_360;
    /* 0x362 */ u16 unk_362;
    /* 0x364 */ u8 unk_364;
    /* 0x368 */ f32 unk_368;
    /* 0x36C */ char unk36C[0x8];
    /* 0x374 */ f32 unk_374;
    /* 0x378 */ s16 unk_378;
    /* 0x37A */ s16 unk_37A;
    /* 0x37C */ s16 unk_37C;
    /* 0x37E */ s16 unk_37E;
    /* 0x380 */ char unk380[0x4];
    /* 0x384 */ s16 unk_384;
    /* 0x386 */ s16 unk_386;
    /* 0x388 */ s16 unk_388;
    /* 0x38A */ s16 unk_38A;
    /* 0x38C */ s16 unk_38C;
    /* 0x38E */ s16 unk_38E;
    /* 0x390 */ s16 unk_390;
    /* 0x392 */ s16 unk_392;
    /* 0x394 */ s16 unk_394;
    /* 0x396 */ s16 unk_396;
    /* 0x398 */ EnAnFunc unk_398;
    /* 0x39C */ s32 unk_39C;
    /* 0x3A0 */ char unk3A0[0x8];
    /* 0x3A8 */ s32 unk_3A8;
    /* 0x3AC */ s32 unk_3AC;
    /* 0x3B0 */ s32 unk_3B0;
    /* 0x3B4 */ s32 unk_3B4;
    /* 0x3B8 */ s32 unk_3B8;
    /* 0x3BC */ s32 unk_3BC;
    /* 0x3C0 */ s32 unk_3C0;
    /* 0x3C4 */ s32 unk_3C4;
} EnAn; // size = 0x3C8

extern const ActorInit En_An_InitVars;

#endif // Z_EN_AN_H
