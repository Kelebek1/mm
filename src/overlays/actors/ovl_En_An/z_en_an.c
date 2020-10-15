#include "z_en_an.h"
#include "overlays/actors/ovl_En_Door/z_en_door.h"

#define FLAGS 0x00000039

#define THIS ((EnAn*)thisx)

void EnAn_Init(Actor* thisx, GameState *gameState);
void EnAn_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnAn_Update(Actor* thisx, GlobalContext* globalCtx);

void func_80B580C0(EnAn* this, GlobalContext* globalCtx);
void func_80B578F8(EnAn* this, GlobalContext* globalCtx);
void func_80B57A44(EnAn* this, GlobalContext* globalCtx);

typedef struct {
    u8 unk_00;
    s16 unk_02;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} struct_80B578F8; // size = 0x8 or 0xC

extern SkeletonHeader D_06012618;
extern Gfx D_060111E8[];
extern Gfx D_06000378[];
extern Gfx D_06000308[];
extern Gfx D_06012478[];
extern Gfx D_06000E70[];
extern Gfx D_0A000D40[];

s32 D_80B581D0[] = {
    0x0D000101, 
    0x4C0B0061, 
    0x01460306, 
    0x000A3701, 
    0x39030A37, 
    0x0B0A012C, 
    0x030B0A0B, 
    0x1E011F03, 
    0x0B1E0B32, 
    0x0112030B, 
    0x320B3701, 
    0x05030B37, 
    0x0C0000F8, 
    0x030C000C, 
    0x0F00EB03, 
    0x0C0F0C14, 
    0x00DE030C, 
    0x140C1900, 
    0xD1030C19, 
    0x0C3700C4, 
    0x030C370D, 
    0x0000B703, 
    0x0D0F0D14, 
    0x00AA030D, 
    0x140D3200, 
    0x9D030D32, 
    0x0E080090, 
    0x030E080E, 
    0x12008302, 
    0x0E12100A, 
    0x7702100A, 
    0x101E6B02, 
    0x101E1332, 
    0x5F021332, 
    0x14145302, 
    0x1414141E, 
    0x4702141E, 
    0x15053B02, 
    0x1505150A, 
    0x2F003208, 
    0x01050217, 
    0x0A170F1E, 
    0x02170F00, 
    0x00120200, 
    0x00060001, 
    0x05003220, 
    0x060E0000, 
    0x06001705, 
    0x0E170F00, 
    0x00310E17, 
    0x0A170F1F, 
    0x0E150515, 
    0x0A1E0E14, 
    0x1E150530, 
    0x0E141414, 
    0x1E130E13, 
    0x3214142F, 
    0x0E101E13, 
    0x32120E10, 
    0x0A101E11, 
    0x0E0E1210, 
    0x0A120E0E, 
    0x080E1210, 
    0x0E0D320E, 
    0x08120E0D, 
    0x140D322E, 
    0x0E0D0F0D, 
    0x141D0E0C, 
    0x370D001C, 
    0x0E0C190C, 
    0x372D0E0C, 
    0x140C191B, 
    0x0E0C0F0C, 
    0x142C0E0C, 
    0x000C0F15, 
    0x0E0B370C, 
    0x002B0E0B, 
    0x320B371A, 
    0x0E0B1E0B, 
    0x322A0E0B, 
    0x0A0B1E0E, 
    0x0E0A370B, 
    0x0A280E06, 
    0x000A3712, 
    0x050D0002, 
    0x023B0132, 
    0x2001430B, 
    0x00610092, 
    0x030B030B, 
    0x09008502, 
    0x0B090B1D, 
    0x79020B1D, 
    0x0B276D02, 
    0x1118111E, 
    0x6102111E, 
    0x11375502, 
    0x11371200, 
    0x49021200, 
    0x13323D02, 
    0x13321414, 
    0x31021414, 
    0x141E2502, 
    0x141E1500, 
    0x19021500, 
    0x15050D02, 
    0x151E1700, 
    0x01050E15, 
    0x1E170018, 
    0x0E150015, 
    0x051E0E14, 
    0x1E150030, 
    0x0E141414, 
    0x1E130E13, 
    0x3214142F, 
    0x0E120013, 
    0x32120E11, 
    0x37120023, 
    0x0E111E11, 
    0x37330E11, 
    0x18111E22, 
    0x0E0B1D0B, 
    0x27210E0B, 
    0x090B1D32, 
    0x0E0B030B, 
    0x09200A00, 
    0x6C49020B, 
    0x1D0B273D, 
    0x020B270C, 
    0x1931020C, 
    0x190D0F25, 
    0x020F3710, 
    0x2D190210, 
    0x2D11180D, 
    0x02111811, 
    0x1E01050E, 
    0x1118111E, 
    0x260E102D, 
    0x11183B0E, 
    0x0F37102D, 
    0x3A0E0C19, 
    0x0D0F370E, 
    0x0B270C19, 
    0x360E0B1D, 
    0x0B27250A, 
    0x006F3102, 
    0x0B270C19, 
    0x25020C19, 
    0x0D0F1902, 
    0x0F37102D, 
    0x0D02102D, 
    0x11180105, 
    0x0E102D11, 
    0x183F0E0F, 
    0x37102D3E, 
    0x0E0C190D, 
    0x0F3D0E0B, 
    0x270C193C, 
    0x0A007025, 
    0x020D0F0D, 
    0x2D19020D, 
    0x2D0F190D, 
    0x020F190F, 
    0x3701050E, 
    0x0F190F37, 
    0x390E0D2D, 
    0x0F19030E, 
    0x0D0F0D2D, 
    0x38050B00, 
    0x6100ED03, 
    0x06000A37, 
    0x00E0030A, 
    0x370B0A00, 
    0xD3030B0A, 
    0x0B1E00C6, 
    0x030B1E0B, 
    0x3200B903, 
    0x0B320B37, 
    0x00AC030B, 
    0x370C0000, 
    0x9F030C00, 
    0x0C0F0092, 
    0x030C0F0C, 
    0x14008502, 
    0x0C140C19, 
    0x79020C19, 
    0x0C376D02, 
    0x0C370D00, 
    0x61020D0F, 
    0x0D145502, 
    0x0D140D32, 
    0x49020D32, 
    0x13323D02, 
    0x13321414, 
    0x31021414, 
    0x141E2502, 
    0x141E1505, 
    0x19021505, 
    0x150A0D02, 
    0x151E1700, 
    0x01050E15, 
    0x1E170018, 
    0x0E150515, 
    0x0A1E0E14, 
    0x1E150530, 
    0x0E141414, 
    0x1E130E13, 
    0x3214142F, 
    0x0E0D3213, 
    0x32120E0D, 
    0x140D322E, 
    0x0E0D0F0D, 
    0x141D0E0C, 
    0x370D001C, 
    0x0E0C190C, 
    0x372D0E0C, 
    0x140C191B, 
    0x0E0C0F0C, 
    0x142C0E0C, 
    0x000C0F15, 
    0x0E0B370C, 
    0x002B0E0B, 
    0x320B371A, 
    0x0E0B1E0B, 
    0x322A0E0B, 
    0x0A0B1E0E, 
    0x0E0A370B, 
    0x0A280E06, 
    0x000A3712, 
    0x050D0003, 
    0x00B10033, 
    0x01530A00, 
    0x613D0206, 
    0x000B0031, 
    0x020B000B, 
    0x1925020B, 
    0x190B1E19, 
    0x020B1E0B, 
    0x320D020B, 
    0x320C0001, 
    0x050E0B32, 
    0x0C00270E, 
    0x0B1E0B32, 
    0x350E0B19, 
    0x0B1E240E, 
    0x0B000B19, 
    0x340E0600, 
    0x0B00160A, 
    0x00100D02, 
    0x12000600, 
    0x01050E12, 
    0x0006000C, 
    0x050A0061, 
    0x55020600, 
    0x0B004902, 
    0x0B000B19, 
    0x3D020B19, 
    0x0B1E3102, 
    0x0B1E0B32, 
    0x25020B32, 
    0x0C001902, 
    0x12000500, 
    0x0D020500, 
    0x06000105, 
    0x0E050006, 
    0x00010E12, 
    0x00050001, 
    0x0E0B320C, 
    0x00270E0B, 
    0x1E0B3235, 
    0x0E0B190B, 
    0x1E240E0B, 
    0x000B1934, 
    0x0E06000B, 
    0x00160505, 
};

s32 D_80B58618[] = {
    0xFFFFFFFF, 
    0x0000000A, 
    0xFFFFFFFF, 
    0x00000000, 
    0xFFFFFFFF, 
    0xFFFFFFFF, 
    0xFFFFFFFF, 
    0xFFFFFFFF, 
    0xFFFFFFFF, 
    0xFFFFFFFF, 
    0xFFFFFFFF, 
    0xFFFFFFFF, 
    0xFFFFFFFF, 
    0xFFFFFFFF, 
    0x00000000, 
    0xFFFFFFFF, 
    0x0000000A, 
    0x0000000A, 
    0x0000000A, 
    0x0000000B, 
    0xFFFFFFFF, 
    0x00000004, 
    0x00000016, 
    0x0000000F, 
    0xFFFFFFFF, 
    0xFFFFFFFF, 
    0x00000003, 
    0x00000006, 
    0x00000008, 
    0x00000009, 
    0x0000000D, 
    0x0000000E, 
    0x00000010, 
    0x00000012, 
    0x00000013, 
    0x00000015, 
    0x00000017, 
    0x00000000, 
    0x00000005, 
    0x00000019, 
    0x00000000, 
    0x00000001, 
    0x00000002, 
    0x00000004, 
    0x00000005, 
    0x00000007, 
    0x0000000A, 
    0x0000000B, 
    0x0000000C, 
    0x0000000F, 
    0x00000011, 
    0x00000014, 
    0x00000016, 
    0x00000018, 
    0x00000001, 
    0x00000002, 
    0x00000000, 
    0x00000001, 
    0x00000003, 
    0x00000004, 
    0x00000000, 
    0x00000001, 
    0x00000002, 
    0x00000003, 
};

s32 D_80B58718[] = {
    0x00560800, 
    0x44090000, 
    0x0E28BA0C, 
    0x09000017, 
    0x0E28BB0C, 
    0x09000018, 
    0x0E28BC0C, 
    0x09000017, 
    0x0E28BD0C, 
    0x09000018, 
    0x0E28BE0C, 
    0x09000017, 
    0x0E28BF0C, 
    0x09000018, 
    0x0E28C02D, 
    0x00012D00, 
    0x0B0C0900, 
    0x00115608, 
    0x10090000, 
    0x0E295C0C, 
    0x09000017, 
    0x0E295D0C, 
    0x09000018, 
    0x0E295E2D, 
    0x00012D00, 
    0x0B0C0900, 
    0x00100000, 
};

s32 D_80B58784[] = {
    0x09000000,
    0x4B10001E,
    0x0E28B10C,
    0x09000017,
    0x0E28B20C,
    0x09000018,
    0x0E28B32D,
    0x00011137,
    0x020C0900,
    0x00100056,
    0x10002E0E,
    0x28B10C09,
    0x0000170E,
    0x28B50C09,
    0x0000180E,
    0x28B60C09,
    0x0000170E,
    0x28B70C09,
    0x0000180E,
    0x28B82D00,
    0x010C0900,
    0x00115610,
    0x10090000,
    0x170E2956,
    0x0C090000,
    0x180E2957,
    0x0C090000,
    0x170E2958,
    0x0C090000,
    0x180E2959,
    0x2D00010C,
    0x09000012,
    0x10000000,
};

s32 D_80B58808[] = {
    0x09000017,
    0x0E28C70C,
    0x09000018,
    0x0E28C80C,
    0x09000017,
    0x0E28C90C,
    0x09000018,
    0x0E28CA0C,
    0x09000017,
    0x0E28CB0C,
    0x09000018,
    0x0E28CC0C,
    0x09000017,
    0x0E28CD0C,
    0x09000018,
    0x0E28CE0C,
    0x09000017,
    0x0E28CF2D,
    0x00012D00,
    0x0E0C0900,
    0x00100000,
};

s32 D_80B5885C[] = {
    0x220B0000,
    0x69002020,
    0x0064004B,
    0x1000B700,
    0x370100AA,
    0x00370200,
    0x550E28A0,
    0x0C090000,
    0x0F28A80C,
    0x05000000,
    0x30000030,
    0x0E28A90C,
    0x0F28AA0C,
    0x0F28AB0C,
    0x120600A0,
    0x00001300,
    0xA02F0000,
    0x2E2D0014,
    0x0C114B10,
    0x0700000E,
    0x28AD2D00,
    0x010C2400,
    0x41161031,
    0x0E28A30C,
    0x0900000F,
    0x28A52D00,
    0x010C1137,
    0x01100020,
    0x2000340E,
    0x28A00C09,
    0x00000F28,
    0xA10C0500,
    0x00000F00,
    0x00300E28,
    0xA20C0900,
    0x000F28A3,
    0x0C190008,
    0x310E28A4,
    0x0C090000,
    0x0F28A52D,
    0x00010C11,
    0x20201023,
    0x00400012,
    0x0E28A00C,
    0x0900000F,
    0x28A62D00,
    0x010C2400,
    0x40100E28,
    0xA72D0001,
    0x0C102300,
    0x41000B0E,
    0x28AC2D00,
    0x010C2400,
    0x41100E28,
    0xAD0C1000,
};

s32 D_80B58938[] = {
    0x0E18852D,
    0x00010C12,
    0x10000000,
};

s32 D_80B58944[] = {
    0x0E28AF2D,
    0x00010C10,
};

s32 D_80B5894C[] = {
    0x0E28C12D,
    0x00010C10,
};

s32 D_80B58954[] = {
    0x00350100,
    0x1C0E28C3,
    0x0C0F28C4,
    0x0C150900,
    0x000E28C5,
    0x2D00010C,
    0x15090000,
    0x11350112,
    0x100E28C2,
    0x2D00010C,
    0x10000000,
};

s32 D_80B58980[] = {
    0x0E28C62D,
    0x00010C10,
};

s32 D_80B58988[] = {
    0x0E28F70C,
    0x0F28F82D,
    0x00010C10,
};

s32 D_80B58994[] = {
    0x0E28F82D,
    0x00010C10,
};

s32 D_80B5899C[] = {
    0x0E28F90C,
    0x0F28FA0C,
    0x0F28FB2D,
    0x00010C10,
};

s32 D_80B589AC[] = {
    0x0E28D70C,
    0x0F28D80C,
    0x0F28D90C,
    0x0F28DA0C,
    0x0F28DB0C,
    0x05000700,
    0x00000731,
    0x0E28D919,
    0xFFE9300E,
    0x28DC0C11,
    0x32201132,
    0x10120600,
    0xAA000013,
    0x00AA2F00,
    0x002E2D00,
    0x012D0017,
    0x2D00160C,
    0x0700000E,
    0x28DE0C15,
    0x09000010,
};

s32 D_80B589FC[] = {
    0x0E28D62D,
    0x00010C10,
};

s32 D_80B58A04[] = {
    0x00522000,
    0x100E294F,
    0x0C0F2950,
    0x2D00010C,
    0x12115220,
    0x100E2951,
    0x2D00010C,
    0x12100000,
};

s32 D_80B58A24[] = {
    0x00524000,
    0x0B0E2952,
    0x2D00010C,
    0x11524010,
    0x0E29532D,
    0x00010C10,
};

s32 D_80B58A3C[] = {
    0x0E28E02D,
    0x00010C10,
};

s32 D_80B58A44[] = {
    0x00320800,
    0x080E28D5,
    0x2D00010C,
    0x10003220,
    0x00080E28,
    0xD42D0001,
    0x0C100033,
    0x01001A25,
    0x0030001D,
    0x27000300,
    0x080E28E3,
    0x2D00010C,
    0x100E28E2,
    0x2D00010C,
    0x100E28E1,
    0x2D00010C,
    0x100E28E4,
    0x0C0E00FF,
    0x1E003600,
    0x0E000000,
    0x0C2C28E7,
    0x0C2F0000,
    0x2D00010C,
    0x1012102C,
    0x28E50C2F,
    0x00000C2A,
    0x00300F28,
    0xE62D0001,
    0x2D001A0C,
    0x11330110,
};

s32 D_80B58ABC[] = {
    0x0E28D02D,
    0x00010C10,
};

s32 D_80B58AC4[] = {
    0x00320800,
    0x160E28D1,
    0x0C0F28D2,
    0x0C0F28D3,
    0x2D00152D,
    0x00010C11,
    0x3208100E,
    0x28D32D00,
    0x010C1000,
};

s32 D_80B58AE8[] = {
    0x0E28DF2D,
    0x00010C12,
    0x10000000,
};

s32 D_80B58AF4[] = {
    0x00372000,
    0x29003208,
    0x002A0E28,
    0xE80C1509,
    0x00000E28,
    0xE90C0F28,
    0xEA0C1509,
    0x00000E28,
    0xEB0C0F28,
    0xEC2D0001,
    0x0C121137,
    0x20100E28,
    0xEC0C1210,
    0x0E28EE0C,
    0x0F28EB0C,
    0x0F28EC2D,
    0x00010C12,
    0x11372010,
};

s32 D_80B58B3C[] = {
    0x00372000,
    0x21003208,
    0x00220E28,
    0xE80C0F28,
    0xED0C1509,
    0x00000E28,
    0xEB0C0F28,
    0xEC2D0001,
    0x0C121137,
    0x20100E28,
    0xEC0C1210,
    0x0E28EE0C,
    0x0F28EB0C,
    0x0F28EC2D,
    0x00010C12,
    0x11372010,
};

s32 D_80B58B7C[] = {
    0x0E29512D,
    0x00010C12,
    0x10000000,
};

s32 D_80B58B88[] = {
    0x0E29612D,
    0x00010C10,
};

s32 D_80B58B90[] = {
    0x0E291B2D,
    0x00010C12,
    0x10000000,
};

// D_80B58B9C
const ActorInit En_An_InitVars = {
    ACTOR_EN_AN,
    ACTORTYPE_NPC,
    FLAGS,
    OBJECT_AN1,
    sizeof(EnAn),
    (ActorFunc)EnAn_Init,
    (ActorFunc)EnAn_Destroy,
    (ActorFunc)EnAn_Update,
    (ActorFunc)NULL
};

// D_80B58BBC
static ColCylinderInit sCylinderInit =
{
    { COLTYPE_UNK1, 0x00, 0x00, 0x39, 0x10, COLSHAPE_CYLINDER },
    { 0x01, { 0x00000000, 0x00, 0x00 }, { 0x00000000, 0x00, 0x00 }, 0x00, 0x00, 0x01 },
    { 14, 62, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 D_80B58BE8 = {
    0x00, 0x0000, 0x0000, 0x0000, 0xFF,
};

struct_8013BC6C D_80B58BF4[] = {
    { 0x06013E1C,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x06008B6C,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x06008B6C,  1.0f, 0x0000, 0xFFFF, 0x00, 0xFFFA }, 
    { 0x0600544C,  1.0f, 0x0000, 0xFFFF, 0x02, 0x0000 }, 
    { 0x0600544C,  1.0f, 0x0000, 0xFFFF, 0x02, 0xFFFA }, 
    { 0x060026B4,  1.0f, 0x0000, 0xFFFF, 0x02, 0x0000 }, 
    { 0x06001E74,  1.0f, 0x0000, 0xFFFF, 0x02, 0x0000 }, 
    { 0x06013048,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x06013048,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x060071E8,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x060071E8,  1.0f, 0x0000, 0xFFFF, 0x00, 0xFFFA }, 
    { 0x06007E08,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x060065C8,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x06001090,  1.0f, 0x0000, 0xFFFF, 0x02, 0x0000 }, 
    { 0x0600144C,  1.0f, 0x0000, 0xFFFF, 0x02, 0x0000 }, 
    { 0x0600341C,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x06003EA8,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x060028DC,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x060042CC,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x060038A0,  1.0f, 0x0000, 0xFFFF, 0x02, 0x0000 }, 
    { 0x06001B80,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x0600201C,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x06002A4C,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x060012C0,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x060038A0, -1.0f, 0x0000, 0xFFFF, 0x02, 0x0000 }, 
    { 0x06006CC0,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x06007E3C,  1.0f, 0x0000, 0xFFFF, 0x02, 0x0000 }, 
    { 0x060088C0,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x060013C8,  1.0f, 0x0000, 0xFFFF, 0x02, 0x0000 }, 
    { 0x06002550,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x0600353C,  1.0f, 0x0000, 0xFFFF, 0x02, 0x0000 }, 
    { 0x06004498,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
    { 0x060060B4,  1.0f, 0x0000, 0xFFFF, 0x02, 0x0000 }, 
    { 0x0600041C,  1.0f, 0x0000, 0xFFFF, 0x02, 0x0000 }, 
    { 0x06004A78,  1.0f, 0x0000, 0xFFFF, 0x02, 0x0000 }, 
    { 0x0600506C,  1.0f, 0x0000, 0xFFFF, 0x00, 0x0000 }, 
};

Vec3f D_80B58E34 = { 0.0f, 0.0f, 8.0f };

s16 D_80B58E40[] = {
    0x0000, 0x0002, 
    0x0000, 0x0001, 
    0x0002, 0x0000, 
    0x0001, 0x0002, 
    0x0001, 0x0001, 
};

Vec3f D_80B58E54 = { 190.0f, -130.0f, 0.0f };
Vec3s D_80B58E60 = { 0x0000, 0x0000, 0x4168 };
Vec3f D_80B58E68 = { 450.0f, 700.0f, -760.0f };
Vec3s D_80B58E74 = { 0x238C, 0x0000, 0xC004 };

Vec3f D_80B58E7C = { 905.0f, 260.0f, -64.0f };
Vec3s D_80B58E88 = { 0x0000, 0x0000, 0x0000 };

Vec3f D_80B58E90 = { -508.0f, 210.0f, -162.0f };
Vec3s D_80B58E9C = { 0x0000, 0x3FFC, 0x0000 };
Vec3s D_80B58EA4 = { 0x0000, 0xD553, 0x0000 };





s32 func_80B53840(EnAn *this, GlobalContext *globalCtx) {
    s32 sp24 = 0;

    if ((this->unk_214 != globalCtx->roomContext.currRoom.num) && (globalCtx->roomContext.unk31 == 0) && (this->unk_3B8 == 0)) {
        this->unk_20C = func_8013D924(0x16, globalCtx);
        this->unk_20B = func_8013D924(0x1A, globalCtx);
        this->unk_20A = func_8013D924(0x1FF, globalCtx);
        this->unk_209 = func_8013D924(0xDD, globalCtx);
        this->unk_208 = func_8013D924(0xE0, globalCtx);
        this->actor.draw = NULL;
        this->unk_214 = globalCtx->roomContext.currRoom.num;
        this->unk_3B8 = 1;
    }

    if (this->unk_3B8 == 0) {
        return 0;
    }

    if (((this->unk_208 >= 0) && (func_8013D8DC(this->unk_208, globalCtx) == 0)) ||
        ((this->unk_209 >= 0) && (func_8013D8DC(this->unk_209, globalCtx) == 0)) ||
        ((this->unk_20A >= 0) && (func_8013D8DC(this->unk_20A, globalCtx) == 0)) ||
        ((this->unk_20B >= 0) && (func_8013D8DC(this->unk_20B, globalCtx) == 0)) ||
        ((this->unk_20C >= 0) && (func_8013D8DC(this->unk_20C, globalCtx) == 0))) {
        sp24 = 1;
    } else {
        this->actor.draw = func_80B580C0;
        this->unk_3B8 = 0;
    }

    return sp24;
}

Actor *func_80B539CC(EnAn *this, GlobalContext *globalCtx, u8 actorType, s16 actorId) {
    Actor *foundActor;
    Actor *retActor = NULL;
    Actor* myActor;

    while (1) {
        foundActor = func_8013D960(globalCtx, retActor, actorType, actorId);
        retActor = foundActor;
        
        if (retActor == NULL) {
            break;
        }

        myActor = &this->actor;
        if ((retActor != myActor) && (retActor->update != NULL)) {
            break;
        }

        foundActor = foundActor->next;
        if (foundActor == NULL) {
            retActor = NULL;
            break;
        }

        retActor = foundActor;
    };

    return retActor;
}

Actor* func_80B53A7C(EnAn *this, GlobalContext *globalCtx, u8 actorType, s16 actorId) {
    Actor* retActor = NULL;
    Actor *foundActor;
    Actor* myActor;
    
    while (1) {
        foundActor = func_8013D960(globalCtx, retActor, actorType, actorId);
        retActor = foundActor;

        if (foundActor == NULL) {
            break;
        }

        myActor = &this->actor;
        if ((retActor != myActor) && (retActor->update != NULL) && !(retActor->params & 0x8000)) {
            break;
        }

        foundActor = foundActor->next;
        if (foundActor == NULL) {
            retActor = NULL;
            break;
        }

        retActor = foundActor;
    };

    return retActor;
}

Actor *func_80B53B3C(GlobalContext *globalCtx, s32 arg1) {
    u8 param;

    switch (arg1) {
        case 26:
        case 27:
            param = 0xD;
            break;

        case 33:
        case 34:
        case 37:
        case 38:
            param = 0xB;
            break;

        case 36:
            param = 0x10;
            break;

        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 35:
        case 39:
            param = 0xE;
            break;

        default:
            return NULL;
    }

    return func_8013A7C0(globalCtx, param);
}

s32 func_80B53BA8(EnAn *this, GlobalContext *globalCtx) {
    s8 bank = this->actor.objBankIndex;
    s8 phi_v1 = -1;
    s32 ret = 0;

    if ((this->unk_39C >= 0x19) && (this->unk_20B >= 0)) {
        phi_v1 = this->unk_20B;
    } else if ((this->unk_39C >= 0x15) && (this->unk_209 >= 0)) {
        phi_v1 = this->unk_209;
    } else if ((this->unk_39C >= 0x11) && (this->unk_208 >= 0)) {
        phi_v1 = this->unk_208;
    } else if (this->unk_39C < 0x11) {
        phi_v1 = bank;
    }

    if (phi_v1 < 0) {
        return ret;
    }

    if (phi_v1 >= 0) {
        gRspSegmentPhysAddrs[6] = PHYSICAL_TO_VIRTUAL2(globalCtx->sceneContext.objects[phi_v1].vramAddr);
        this->skelAnime.animPlaybackSpeed = this->unk_368;
        ret = SkelAnime_FrameUpdateMatrix(&this->skelAnime);
        gRspSegmentPhysAddrs[6] = PHYSICAL_TO_VIRTUAL2(globalCtx->sceneContext.objects[bank].vramAddr);
    }

    return ret;
}

s32 func_80B53CE8(EnAn *this, GlobalContext *globalCtx, s32 index) {
    s8 bank = this->actor.objBankIndex;
    s8 phi_v1 = -1;
    s32 phi_t0 = 0;
    s32 ret = 0;

    if ((index >= 25) && (this->unk_20B >= 0)) {
        phi_v1 = this->unk_20B;
    } else if ((index >= 21) && (this->unk_209 >= 0)) {
        phi_v1 = this->unk_209;
    } else if ((index >= 17) && (this->unk_208 >= 0)) {
        phi_v1 = this->unk_208;
    } else if (index < 17) {
        phi_v1 = bank;
    }

    if (phi_v1 < 0) {
        return ret;
    }

    switch (index) {
        case 1:
        case 2:
            if ((this->unk_39C != 1) && (this->unk_39C != 2)) {
                phi_t0 = 1;
            }
            break;

        case 7:
        case 8:
            if ((this->unk_39C != 7) && (this->unk_39C != 8)) {
                phi_t0 = 1;
            }
            break;

        case 9:
        case 10:
            if ((this->unk_39C != 9) && (this->unk_39C != 0xA)) {
                phi_t0 = 1;
            }
            break;

        default:
            if (index != this->unk_39C) {
                phi_t0 = 1;
            }
            break;
    }

    if ((phi_t0 != 0) && (phi_v1 >= 0)) {
        gRspSegmentPhysAddrs[6] = PHYSICAL_TO_VIRTUAL2(globalCtx->sceneContext.objects[phi_v1].vramAddr);
        this->unk_39C = index;
        ret = func_8013BC6C(&this->skelAnime, &D_80B58BF4[0], this->unk_39C);
        this->unk_368 = this->skelAnime.animPlaybackSpeed;
        gRspSegmentPhysAddrs[6] = PHYSICAL_TO_VIRTUAL2(globalCtx->sceneContext.objects[bank].vramAddr);
    }

    return ret;
}

void func_80B53ED4(EnAn *this, GlobalContext *globalCtx) {
    s32 pad;
    f32 temp;
    Vec3f sp24;

    if (this->unk_200 == 0x19) {
        Lib_TranslateAndRotateYVec3f(&this->actor.currPosRot.pos, this->actor.shape.rot.y, &D_80B58E34, &sp24);
        this->collider.params.radius = 0x14;
        Math_Vec3f_ToVec3s(&this->collider.params.loc, &sp24);
    } else {
        Collision_CylinderMoveToActor(&this->actor, &this->collider);
    }
    temp = this->actor.topPosRot.pos.y - this->actor.currPosRot.pos.y;
    this->collider.params.height = temp;
    Collision_AddOT(globalCtx, &globalCtx->colCheckCtx, &this->collider);
}

void func_80B53F84(EnAn *this) {
    s32 phi_v1;
    s32 phi_a1 = 0;

    if ((this->unk_360 & 0x100) != 0) {
        if (this->unk_38E == 0) {
            phi_v1 = 0;
        } else {
            this->unk_38E--;
            phi_v1 = this->unk_38E;
        }

        if (phi_v1 == 0) {
            switch (this->unk_38C) {
                case 2:
                case 4:
                case 6:
                    if ((this->unk_390 == 5) || (this->unk_390 == 2)) {
                        phi_a1 = 1;
                        this->unk_390 = 5;
                    }
                    break;

                case 5:
                case 7:
                    if ((this->unk_390 == 6) || (this->unk_390 == 1)) {
                        phi_a1 = 1;
                        this->unk_390 = 6;
                    }
                    break;

                case 8:
                    if ((this->unk_390 == 4) || (this->unk_390 == 2)) {
                        phi_a1 = 1;
                        this->unk_390 = 4;
                    }
                    break;

                case 3:
                    break;
            }

            if (phi_a1 == 0) {
                if ((this->unk_390 == 4) || (this->unk_390 == 5)) {
                    this->unk_390 = 0;
                } else if (this->unk_390 == 6) {
                    this->unk_390 = 1;
                }
            }

            if (phi_a1 == 0) {
                this->unk_390++;
                if (this->unk_390 >= 4) {
                    if ((this->unk_38C == 0) || (this->unk_38C == 1) || (this->unk_38C == 3)) {
                        this->unk_38E = Math_Rand_S16Offset(0x1E, 0x1E);
                    } else {
                        this->unk_38E = 8;
                    }
                    this->unk_390 = 0;
                }
            }
        }
    }

    this->unk_392 = D_80B58E40[this->unk_38C];
}

void func_80B54124(EnAn *this, GlobalContext *globalCtx, s32 arg2) {
    s32 pad;
    s8 sp53 = this->actor.objBankIndex;
    s8 sp52;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s32 pad2[1];

    SysMatrix_StatePush();

    switch (arg2) {
        case 0:
            if ((this->unk_360 & 0x800) && (this->unk_3B0 == 0)) {
                this->unk_3A8 += 1;
                this->unk_3AC -= 2;
                func_8012C2DC(globalCtx->state.gfxCtx);

                gSPMatrix(gfxCtx->polyXlu.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPSegment(gfxCtx->polyXlu.p++, 0x08, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, this->unk_3A8, 0, 0x10, 0x10, 1, 0, this->unk_3AC, 0x10, 0x10));
                gSPDisplayList(gfxCtx->polyXlu.p++, D_060111E8);

                func_8012C28C(globalCtx->state.gfxCtx);
            }
            break;

        case 1:
            sp52 = this->unk_20A;
            if ((this->unk_360 & 0x4000) && (this->unk_3B0 == 0) && (sp52 >= 0)) {
                gSPSegment(gfxCtx->polyOpa.p++, 0x0A, globalCtx->sceneContext.objects[sp52].vramAddr);

                SysMatrix_RotateAndTranslateState(&D_80B58E54, &D_80B58E60);

                gSPMatrix(gfxCtx->polyOpa.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(gfxCtx->polyOpa.p++, D_0A000D40);
                gSPSegment(gfxCtx->polyOpa.p++, 0x06, globalCtx->sceneContext.objects[sp53].vramAddr);

            }
            break;
        
        case 2:
            sp52 = this->unk_208;
            if ((this->unk_360 & 0x1000) && (this->unk_3B0 == 0) && (sp52 >= 0)) {
                gSPSegment(gfxCtx->polyOpa.p++, 0x06, globalCtx->sceneContext.objects[sp52].vramAddr);
                gSPDisplayList(gfxCtx->polyOpa.p++, D_06000378);
                gSPSegment(gfxCtx->polyOpa.p++, 0x06, globalCtx->sceneContext.objects[sp53].vramAddr);
            }
            break;

        case 3:
            sp52 = this->unk_209;
            if ((this->unk_360 & 0x2000) && (this->unk_3B0 == 0) && (sp52 >= 0)) {
                gSPSegment(gfxCtx->polyOpa.p++, 0x06, globalCtx->sceneContext.objects[sp52].vramAddr);
                gSPDisplayList(gfxCtx->polyOpa.p++, D_06000308);
                gSPSegment(gfxCtx->polyOpa.p++, 0x06, globalCtx->sceneContext.objects[sp53].vramAddr);
            }
            break;

        case 4:
            if ((this->unk_360 & 0x8000) && (this->unk_3B0 == 0)) {
                gSPDisplayList(gfxCtx->polyOpa.p++, D_06012478);
            }
            break;

        case 5:
            sp52 = this->unk_20C;
            if ((this->unk_3B4 != 0) && (sp52 >= 0)) {
                SysMatrix_RotateAndTranslateState(&D_80B58E68, &D_80B58E74);

                gSPMatrix(gfxCtx->polyOpa.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPSegment(gfxCtx->polyOpa.p++, 0x06, globalCtx->sceneContext.objects[sp52].vramAddr);
                gSPDisplayList(gfxCtx->polyOpa.p++, D_06000E70);
                gSPSegment(gfxCtx->polyOpa.p++, 0x06, globalCtx->sceneContext.objects[sp53].vramAddr);
            }
            break;

    }

    SysMatrix_StatePop();
}

s32 func_80B54678(EnAn *this, s16 arg1) {
    s32 sp1C = 0;

    if (ActorCutscene_GetCurrentIndex() == 0x7C) {
        ActorCutscene_Stop(0x7C);
        ActorCutscene_SetIntentToPlay(arg1);
    } else if (ActorCutscene_GetCanPlayNext(arg1) != 0) {
        ActorCutscene_StartAndSetUnkLinkFields(arg1, this);
        sp1C = 1;
    } else {
        ActorCutscene_SetIntentToPlay(arg1);
    }
    return sp1C;
}

s16 func_80B546F4(EnAn *this, s32 arg1) {
    s32 i;
    s16 ret = this->actor.cutscene;

    for (i = 0; i < arg1; i++) {
        ret = ActorCutscene_GetAdditionalCutscene(ret);
    }

    return ret;
}

s32 func_80B54750(EnAn *this, s32 arg1) {
    s32 i;
    s16 ret = -1;

    if (this->actor.child != 0) {
        if (this->actor.child->update != 0) {
            ret = this->actor.child->cutscene;
            for (i = 0; i < arg1; i++) {
                ret = ActorCutscene_GetAdditionalCutscene(ret);
            }
        }
    }
    return ret;
}

s32 func_80B547C8(EnAn *this, GlobalContext *globalCtx) {
    s32 pad;
    s16 sp2A = func_80B546F4(this, 0);
    s32 sp24 = 0;

    switch (this->unk_394) {
        case 0:
            if (func_80B54678(this, sp2A) == 0) {
                break;
            }
        case 2:
        case 4:
        case 6:
            func_800E0308(Play_GetCamera(globalCtx, ActorCutscene_GetCurrentCamera(sp2A)), this);
            this->unk_394++;
            sp24 = 1;
            break;

        case 1:
        case 3:
        case 5:
            if ((gSaveContext.perm.weekEventReg[86] & 8) && (this->unk_394 == 3)) {
                ActorCutscene_Stop(sp2A);
            } else if ((this->actor.child != NULL) && (this->actor.child->update != NULL)) {
                func_800E0308(Play_GetCamera(globalCtx, ActorCutscene_GetCurrentCamera(sp2A)), this->actor.child);
            }
            this->unk_394++;
            sp24 = 1;
            break;

        case 7:
            ActorCutscene_Stop(sp2A);
            this->unk_394++;
            sp24 = 1;
            break;
    }

    return sp24;
}

s32 func_80B5492C(EnAn *this, GlobalContext *globalCtx) {
    s32 pad;
    s16 sp2A = func_80B546F4(this, 0);
    s32 sp24 = 0;

    switch (this->unk_394) {
        case 0:
            if (func_80B54678(this, sp2A) == 0) {
                break;
            }
        case 2:
        case 4:
            func_800E0308(Play_GetCamera(globalCtx, ActorCutscene_GetCurrentCamera(sp2A)), this);
            this->unk_394++;
            sp24 = 1;
            break;
        case 1:
        case 3:
            if (!(gSaveContext.perm.weekEventReg[75] & 0x10) && (this->unk_394 == 3)) {
                ActorCutscene_Stop(sp2A);
                this->unk_394 = 5;
            } else if ((this->actor.child != NULL) && (this->actor.child->update != NULL)) {
                func_800E0308(Play_GetCamera(globalCtx, ActorCutscene_GetCurrentCamera(sp2A)), this->actor.child);
            }
            this->unk_394++;
            sp24 = 1;
            break;
        case 5:
            ActorCutscene_Stop(sp2A);
            this->unk_394++;
            sp24 = 1;
            break;
    }
    return sp24;
}

s32 func_80B54A94(EnAn *this, GlobalContext *globalCtx) {
    s32 pad;
    s16 sp2A = func_80B54750(this, 0);
    s32 sp24 = 0;

    switch (this->unk_394) {
        case 0:
            if (func_80B54678(this, sp2A) == 0) {
                break;
            }
        case 2:
        case 4:
        case 6:
        case 8:
            if ((this->actor.child != NULL) && (this->actor.child->update != NULL)) {
                func_800E0308(Play_GetCamera(globalCtx, ActorCutscene_GetCurrentCamera(sp2A)), this->actor.child);
            }
            this->unk_394++;
            sp24 = 1;
            break;

        case 1:
        case 3:
        case 5:
        case 7:
            func_800E0308(Play_GetCamera(globalCtx, ActorCutscene_GetCurrentCamera(sp2A)), this);
            this->unk_394++;
            sp24 = 1;
            break;

        case 9:
            ActorCutscene_Stop(sp2A);
            this->unk_394++;
            sp24 = 1;
            break;
    }

    return sp24;
}

s32 func_80B54BC4(EnAn *this, GlobalContext *globalCtx) {
    if (this->unk_394 == 0) {
        func_800B7298(globalCtx, this, 7);
        globalCtx->unk1887A = 0xBC30;
        gSaveContext.extra.unk2AA = 0;
        globalCtx->unk18875 = 0x14;
        globalCtx->unk1887F = 2;
        gSaveContext.extra.unk2B5 = 6;
        this->unk_394++;
    }
    return 0;
}

s32 func_80B54C5C(EnAn *this, GlobalContext *globalCtx) {
    s32 pad;
    s32 sp20 = 0;

    switch (this->unk_394) {
        case 0:
            func_80B53CE8(this, globalCtx, 0xD);
            this->unk_394++;
            break;

        case 1:
        case 3:
            if (func_801378B8(&this->skelAnime, this->skelAnime.animFrameCount) != 0) {
                this->unk_394++;
                sp20 = 1;
            }
            break;

        case 2:
            func_80B53CE8(this, globalCtx, 0xE);
            this->unk_394++;
            break;
    }

    return sp20;
}

s32 func_80B54D18(EnAn *this, GlobalContext *globalCtx) {
    s32 phi_v1 = 0;

    switch (this->unk_394) {
        case 0:
            if ((func_8012403C(globalCtx) == 2) || (gSaveContext.perm.weekEventReg[55] & 0x20)) {
                this->unk_394++;
            } else {
                this->unk_360 |= 0x4000;
                this->unk_394++;
                phi_v1 = 1;
                break;
            }

        case 1:
            this->unk_360 &= ~0x4020;
            this->unk_360 |= 0x200;
            func_80B53CE8(this, globalCtx, 0x14);
            this->unk_394++;
            phi_v1 = 1;
            break;
    }

    return phi_v1;
}

s32* func_80B54DF4(EnAn *this, GlobalContext *globalCtx) {
    ActorPlayer* player = PLAYER;

    switch (this->unk_200) {
        case 21:
            this->unk_398 = func_80B54A94;
            return D_80B58808;
        case 16:
            this->unk_398 = func_80B547C8;
            return D_80B58718;
        case 17:
            this->unk_398 = func_80B5492C;
            return D_80B58784;
        case 14:
            this->unk_398 = func_80B54C5C;
            return D_80B58954;
        case 12:
            return D_80B5899C;
        case 25:
            return D_80B58B90;
    }

    if (player->unk14B == 3) {
        switch (this->unk_200) {
            case 1:
                return D_80B58AE8;
            case 40:
            case 42:
            case 43:
            case 44:
            case 45:
            case 47:
                return D_80B58B7C;

            case 3:
                return D_80B58A24;

            case 49:
                return D_80B589FC;

            case 41:
            case 46:
            case 48:
            default:
                return D_80B58A04;
        }
    }

    if (func_8012403C(globalCtx) == 2) {
        if (this->unk_200 == 0x31) {
            return D_80B58B88;
        } else if (this->unk_200 == 0x17) {
            this->unk_398 = func_80B54BC4;
            return D_80B589AC;
        } else if (this->unk_200 == 0x3) {
            this->unk_398 = func_80B54D18;
            return D_80B58B3C;
        } else {
            if (gSaveContext.perm.day >= 2) {
                return D_80B58A44;
            } else if ((gSaveContext.perm.time - 0x3FFC) < 0x5883) {
                return D_80B58ABC;
            }
            return D_80B58AC4;
        }
    }

    if ((player->unk14B == 4) && (gSaveContext.perm.weekEventReg[50] & 8)) {
        if (this->unk_200 == 0x17) {
            this->unk_398 = func_80B54BC4;
            return D_80B589AC;
        }

        if (this->unk_200 == 3) {
            this->unk_398 = func_80B54D18;
            return D_80B58AF4;
        }

        if (gSaveContext.perm.day >= 2) {
            return D_80B58A44;
        }
    }

    switch (this->unk_200) {
        case 1:
            return D_80B58AE8;
        case 40:
            return D_80B5894C;
        case 42:
        case 43:
        case 44:
        case 45:
            return D_80B58980;
        case 3:
            this->unk_398 = func_80B54D18;
            return D_80B58AF4;
        case 18:
            if (gSaveContext.perm.day >= 2) {
                return D_80B58A3C;
            } else {
                return D_80B5885C;
            }
        case 19:
        case 47:
            return D_80B58938;
        case 22:
            return D_80B58988;
        case 23:
            return D_80B589FC;
        case 48:
            return D_80B58944;
        case 49:
            if (player->unk14B == 4) {
                return D_80B58B88;
            } else {
                return D_80B589FC;
            }
        case 52:
        case 53:
            return D_80B58994;
        default:
            return NULL;
    }

    return NULL;
}

s32 func_80B55180(EnAn *this, GlobalContext *globalCtx) {
    s32 sp1C = 0;

    if ((this->unk_360 & 7) != 0) {
        if (func_800B84D0(&this->actor, globalCtx) != 0) {
            func_8013AED4(&this->unk_360, 0, 7);
            this->unk_3C4 = 0;
            this->unk_394 = 0;
            this->unk_398 = NULL;
            this->actor.child = this->unk_218;
            this->unk_204 = func_80B54DF4(this, globalCtx);
            if ((this->unk_200 == 1) || (this->unk_200 == 3) || (this->unk_200 == 0x12) || 
                (this->unk_200 == 0x13) || (this->unk_200 == 0x17) || (this->unk_200 == 0x16) || 
                (this->unk_200 == 0x28) || (this->unk_200 == 0x2A) || (this->unk_200 == 0x2B) || 
                (this->unk_200 == 0x2C) || (this->unk_200 == 0x2D) || (this->unk_200 == 0x2F) || 
                (this->unk_200 == 0x30) || (this->unk_200 == 0x31) || (this->unk_200 == 0x34) || 
                (this->unk_200 == 0x35)) {
                this->unk_360 |= 0x20;
            }
            if ((this->unk_200 == 3) && (gSaveContext.perm.weekEventReg[55] & 0x20)) {
                this->unk_360 &= ~0x20;
            }
            this->actionFunc = func_80B57A44;
            sp1C = 1;
        }
    }
    return sp1C;
}

s32 func_80B552E4(EnAn *this, GlobalContext *globalCtx) {
    u16 temp = globalCtx->csCtx.unk12;
    s32 phi_v1 = 0;

    if (((globalCtx->csCtx.state != 0) && (globalCtx->sceneNum == 0x61) && (gSaveContext.extra.sceneSetupIndex == 0)) &&
        ((temp == 0) || (temp == 1))) {
        if (this->unk_3B0 == 0) {
            this->unk_38A = 0;
            this->unk_38C = 0;
            this->unk_360 |= 0x300;
            this->unk_38E = 8;
            this->unk_364 = 0xFF;
            this->unk_3B0 = 1;
            this->unk_3B4 = 0;
        }
        phi_v1 = 1;
    } else if (this->unk_3B0 != 0) {
        this->unk_3B0 = 0;
        this->unk_3B4 = 0;
        this->unk_3C0 = 1;
        this->actor.room = globalCtx->roomContext.currRoom.num;
        this->actionFunc = func_80B578F8;
    }
    return phi_v1;
}

void func_80B553AC(EnAn *this) {
    s32 pad;
    Vec3f sp40;
    Vec3f sp34;
    s32 pad2;

    Math_Vec3f_Copy(&sp40, &this->unk_218->currPosRot.pos);
    Math_Vec3f_Copy(&sp34, &this->actor.currPosRot.pos);
    Math_SmoothScaleMaxS(&this->unk_37E, Math_Vec3f_Yaw(&sp34, &sp40) - this->actor.shape.rot.y, 4, 0x2AA8);
    this->unk_37E = CLAMP(this->unk_37E, -0x1FFE, 0x1FFE);
    Math_Vec3f_Copy(&sp34, &this->actor.topPosRot.pos);
    if (this->unk_218->id == 0) {
        // unk_218 can be multiple actors, assuming player for now
        sp40.y = ((ActorPlayer*)this->unk_218)->unkC44 + 3.0f;
    } else {
        Math_Vec3f_Copy(&sp40, &this->unk_218->topPosRot.pos);
    }
    Math_SmoothScaleMaxS(&this->unk_37C, Math_Vec3f_Pitch(&sp34, &sp40), 4, 0x2AA8);
    this->unk_37C = CLAMP(this->unk_37C, -0x1554, 0x1554);
}

void func_80B554E8(EnAn *this) {
    s32 phi_v1;

    if ((this->unk_360 & 0x20) != 0) {
        if ((this->unk_218 != NULL) && (this->unk_218->update != NULL)) {
            if (this->unk_388 == 0) {
                phi_v1 = 0;
            } else {
                this->unk_388--;
                phi_v1 = this->unk_388;
            }
            if (phi_v1 == 0) {
                func_80B553AC(this);
                this->unk_360 &= ~0x200;
                this->unk_360 |= 0x80;
                return;
            }
        }
    }

    if ((this->unk_360 & 0x80) != 0) {
        this->unk_360 &= ~0x80;
        this->unk_37C = 0;
        this->unk_37E = 0;
        this->unk_388 = 0x14;
        return;
    }

    if (this->unk_388 == 0) {
        phi_v1 = 0;
    } else {
        this->unk_388--;
        phi_v1 = this->unk_388;
    }

    if (phi_v1 == 0) {
        this->unk_360 |= 0x200;
    }
}

s32 func_80B555C8(EnAn *this, GlobalContext *globalCtx) {
    switch (this->unk_200) {
        case 16:
        case 17:
        case 18:
        case 19:
        case 23:
            func_80B53CE8(this, globalCtx, 1);
            break;
        case 22:
            func_80B53CE8(this, globalCtx, 0x17);
            this->unk_360 |= 0x2000;
            break;
        case 14:
            func_80B53CE8(this, globalCtx, 0xC);
            break;
        case 21:
            func_80B53CE8(this, globalCtx, 0xF);
            break;
        case 47:
        case 49:
            func_80B53CE8(this, globalCtx, 7);
            break;
        case 52:
        case 53:
            func_80B53CE8(this, globalCtx, 0x16);
            this->unk_360 |= 0x2000;
            break;
        default:
            if (this->unk_39C == 0xF) {
                func_80B53CE8(this, globalCtx, 0x10);
            }
            if (this->unk_39C == 0x11) {
                func_80B53CE8(this, globalCtx, 0x12);
            }
            if ((this->unk_39C == 1) || (this->unk_39C == 2)) {
                func_80B53CE8(this, globalCtx, 8);
            }
            break;
    }
    return 0;
}

void func_80B556F8(EnAn *this, GlobalContext *globalCtx) {
    if (this->unk_396 == 0) {
        func_80B53CE8(this, globalCtx, 6);
        this->unk_360 &= ~0x20;
        this->unk_360 |= 0x200;
        this->unk_396++;
    } else if ((this->unk_396 == 1) && (func_801378B8(&this->skelAnime, this->skelAnime.animFrameCount) != 0)) {
        func_80B53CE8(this, globalCtx, 2);
        this->unk_360 &= ~0x200;
        this->unk_360 |= 0x20;
        this->unk_396++;
    }
}

void func_80B557AC(EnAn *this, GlobalContext *globalCtx) {
    if (this->unk_396 == 0) {
        func_80B53CE8(this, globalCtx, 3);
        this->unk_360 &= ~0x20;
        this->unk_360 |= 0x200;
        this->unk_396++;
    } else if ((this->unk_396 == 1) && (func_801378B8(&this->skelAnime, this->skelAnime.animFrameCount) != 0)) {
        func_80B53CE8(this, globalCtx, 2);
        this->unk_360 &= ~0x200;
        this->unk_360 |= 0x20;
        this->unk_396++;
    }
}

void func_80B55860(EnAn *this, GlobalContext *globalCtx) {
    if (this->unk_396 == 0) {
        func_80B53CE8(this, globalCtx, 4);
        this->unk_360 |= 0x200;
        this->unk_360 &= ~0x20;
        this->unk_396++;
    } else if ((this->unk_396 == 1) && (func_801378B8(&this->skelAnime, this->skelAnime.animFrameCount) != 0)) {
        func_80B53CE8(this, globalCtx, 2);
        this->unk_360 &= ~0x200;
        this->unk_360 |= 0x20;
        this->unk_396++;
    }
}

s32 func_80B55914(EnAn *this, GlobalContext *globalCtx) {
    ActorPlayer* player = PLAYER;
    u16 sp22 = globalCtx->msgCtx.unk11F04;

    if (player->stateFlags1 & 0x40) {
        this->unk_360 |= 0x400;
        if (this->unk_362 != sp22) {
            switch (sp22) {
                case 10469:
                    func_80B53CE8(this, globalCtx, 5);
                    this->unk_360 &= ~0x2000;
                    break;
                case 10426:
                case 10449:
                    func_80B53CE8(this, globalCtx, 5);
                    break;
                case 10415:
                case 10433:
                    func_80B53CE8(this, globalCtx, 1);
                    break;
                case 10428:
                    func_80B53CE8(this, globalCtx, 2);
                    break;
                case 10438:
                    func_80B53CE8(this, globalCtx, 0xF);
                    break;
                case 10485:
                    func_80B53CE8(this, globalCtx, 0xA);
                    break;
                case 10487:
                case 10488:
                    func_80B53CE8(this, globalCtx, 0x15);
                    break;
                case 10475:
                    if (this->unk_39C != 0x14) {
                        this->unk_360 &= ~0x4020;
                        this->unk_360 |= 0x200;
                        func_80B53CE8(this, globalCtx, 0x14);
                    }
                    break;

                case 10404:
                case 10409:
                case 10430:
                case 10432:
                case 10590:
                    this->unk_18C = func_80B556F8;
                    this->unk_396 = 0;
                    break;

                case 10470:
                    this->unk_360 &= ~0x2000;
                    this->unk_18C = func_80B55860;
                    this->unk_396 = 0;
                    break;

                case 10400:
                case 10403:
                case 10405:
                case 10417:
                case 10450:
                case 10457:
                case 10460:
                case 10462:
                case 6277:
                    this->unk_18C = func_80B557AC;
                    this->unk_396 = 0;
                    break;

                default:
                    if (this->unk_39C == 0x10) {
                        func_80B53CE8(this, globalCtx, 0xF);
                    }
                    if (this->unk_39C == 0x12) {
                        func_80B53CE8(this, globalCtx, 0x11);
                    }
                    if ((this->unk_39C == 0x16) || (this->unk_39C == 0x17)) {
                        func_80B53CE8(this, globalCtx, 0x15);
                    }
                    if ((this->unk_39C == 7) || (this->unk_39C == 8)) {
                        func_80B53CE8(this, globalCtx, 2);
                    }
                    break;
            }

            switch (sp22) {
                case 10485:
                    this->unk_38A = 0;
                case 10405:
                case 10410:
                case 10488:
                    this->unk_38C = 0;
                    this->unk_38E = 8;
                    break;

                case 10400:
                case 10406:
                case 10415:
                case 10433:
                case 6277:
                    this->unk_38C = 3;
                    this->unk_38E = 8;
                    break;

                case 10402:
                case 10419:
                case 10422:
                case 10426:
                case 10430:
                case 10446:
                case 10448:
                case 10454:
                case 10469:
                case 10471:
                case 10477:
                    this->unk_38C = 1;
                    this->unk_38E = 8;
                    break;

                case 10413:
                    this->unk_38C = 8;
                    this->unk_38E = 8;
                    break;

                case 10432:
                case 10455:
                case 10462:
                    this->unk_38C = 2;
                    this->unk_38E = 8;
                    break;

                case 10470:
                case 10487:
                    this->unk_38C = 6;
                    this->unk_38E = 8;
                    break;

                case 10403:
                case 10417:
                case 10424:
                case 10438:
                case 10442:
                case 10444:
                case 10453:
                case 10466:
                case 10467:
                case 10468:
                    this->unk_38C = 4;
                    this->unk_38E = 8;
                    break;

                case 10476:
                    this->unk_38A = 5;
                case 10460:
                case 10475:
                case 10482:
                case 10489:
                    this->unk_38C = 5;
                    this->unk_38E = 8;
                    break;

                case 10486:
                    this->unk_38C = 9;
                    this->unk_38E = 8;
                    break;

                case 10404:
                case 10409:
                    this->unk_38C = 7;
                    this->unk_38E = 8;
                    break;

            }
        }

        this->unk_362 = sp22;
    } else if ((this->unk_360 & 0x400) != 0) {
        this->unk_18C = NULL;
        this->unk_362 = 0;
        this->unk_360 &= ~0x400;
        this->unk_38C = this->unk_38A;
        this->unk_38E = 4;
        func_80B555C8(this, globalCtx);
    }
    if (this->unk_18C != NULL) {
        this->unk_18C(this, globalCtx);
    }

    return 0;
}

Actor* func_80B55D20(EnAn *this, GlobalContext *globalCtx) {
    Actor* phi_v1;

    switch (this->unk_200) {
        case 0x15:
            phi_v1 = func_80B539CC(this, globalCtx, ACTORTYPE_NPC, ACTOR_EN_NB);
            break;

        case 0x10:
            phi_v1 = func_80B539CC(this, globalCtx, ACTORTYPE_NPC, ACTOR_EN_PM);
            break;
        
        case 0x11:
            phi_v1 = func_80B539CC(this, globalCtx, ACTORTYPE_NPC, ACTOR_EN_IG);
            break;

        default:
            phi_v1 = &PLAYER->base;
            break;
    }

    return phi_v1;
}

s32 func_80B55D98(EnAn *this, GlobalContext *globalCtx, struct_80B578F8 *arg2, u8 arg3, s16 arg4) {
    u8 sp4F = this->actor.params & 0xFF;
    Vec3s* sp48;
    Vec3f sp3C;
    Vec3f sp30;
    Actor* sp2C;
    s32 pad;
    s32 sp24 = 0;

    sp2C = func_80B539CC(this, globalCtx, arg3, arg4);
    this->unk_1DC = NULL;
    if (D_80B58618[arg2->unk_00] >= 0) {
        this->unk_1DC = func_8013BB34(globalCtx, sp4F, D_80B58618[arg2->unk_00]);
    }

    if ((sp2C != NULL) && (sp2C->update != NULL)) {
        if (this->unk_1DC != NULL) {
            sp48 = (Vec3s*)Lib_PtrSegToVirt(this->unk_1DC->unk_04);
            Math_Vec3s_ToVec3f(&sp3C, &sp48[this->unk_1DC->unk_00 - 2]);
            Math_Vec3s_ToVec3f(&sp30, &sp48[this->unk_1DC->unk_00 - 1]);
            this->actor.shape.shadowDrawFunc = NULL;
            this->actor.currPosRot.rot.y = Math_Vec3f_Yaw(&sp3C, &sp30);
            Math_Vec3f_Copy(&this->actor.currPosRot, &sp30);
            sp24 = 1;
        }
    }

    return sp24;
}

s32 func_80B55ECC(EnAn *this) {
    s32 sp1C = 0;
    s32 phi_v1;
    f32 phi_f0;

    if (this->unk_3BC != 0) {
        phi_f0 = 150.0f;
    } else {
        phi_f0 = 100.0f;
    }

    if (Actor_IsActorFacingLinkAndWithinRange(this, phi_f0, 0x2800) != 0) {
        sp1C = 1;
    }

    if (this->unk_386 == 0) {
        phi_v1 = 0;
    } else {
        this->unk_386--;
        phi_v1 = this->unk_386;
    }

    if (phi_v1 == 0) {
        this->unk_3BC ^= 1;
        this->unk_386 = Math_Rand_S16Offset(0x3C, 0x3C);
    }

    return sp1C;
}

s32 func_80B55F8C(GlobalContext *globalCtx) {
    ActorPlayer *sp1C = PLAYER;
    s32 sp18 = 0;

    if ((func_8012403C(globalCtx) == 2) && (gSaveContext.perm.weekEventReg[50] & 8)) {
        sp18 = 1;
    } else if ((sp1C->unk14B == 4) && (gSaveContext.perm.weekEventReg[50] & 8)) {
        sp18 = 1;
    }
    return sp18;
}

s32 func_80B5600C(EnAn *this, GlobalContext *globalCtx, s32 arg2) {
    s32 sp2C = 0;

    if (func_80B55D98(this, globalCtx, arg2, ACTORTYPE_NPC, ACTOR_EN_PM) != 0) {
        func_80B53CE8(this, globalCtx, 1);
        func_8013AED4(&this->unk_360, 3, 7);
        this->unk_360 |= 0x120;
        this->unk_360 |= 0x200;
        sp2C = 1;
    }
    return sp2C;
}

s32 func_80B56094(EnAn *this, GlobalContext *globalCtx, struct_80B578F8 *arg2) {
    s32 sp2C = 0;

    if (func_80B55D98(this, globalCtx, arg2, ACTORTYPE_NPC, ACTOR_EN_IG) != 0) {
        func_80B53CE8(this, globalCtx, 1);
        func_8013AED4(&this->unk_360, 3, 7);
        this->unk_360 |= 0x120;
        this->unk_360 |= 0x200;
        sp2C = 1;
    }
    return sp2C;
}

s32 func_80B5611C(EnAn *this, GlobalContext *globalCtx, struct_80B578F8 *arg2) {
    s32 sp2C = 0;

    if (func_80B55D98(this, globalCtx, arg2, ACTORTYPE_NPC, ACTOR_EN_NB) != 0) {
        func_80B53CE8(this, globalCtx, 0xF);
        func_8013AED4(&this->unk_360, 3, 7);
        this->unk_360 |= 0x120;
        this->unk_360 |= 0xA00;
        sp2C = 1;
    }
    return sp2C;
}

s32 func_80B561A4(EnAn *this, GlobalContext *globalCtx, struct_80B578F8 *arg2) {
    u16 sp56 = gSaveContext.perm.time - 0x3FFC;
    u8 sp55 = this->actor.params & 0xFF;
    Actor *sp50;
    Vec3s *sp4C;
    Vec3f sp40;
    Vec3f sp34;
    s32 pad;
    s32 sp2C = 0;

    this->unk_1DC = NULL;
    sp50 = func_80B53B3C(globalCtx, arg2->unk_00);
    if (D_80B58618[arg2->unk_00] >= 0) {
        this->unk_1DC = func_8013BB34(globalCtx, sp55, D_80B58618[arg2->unk_00]);
    }

    if ((sp50 != NULL) && (sp50->update != NULL)) {
        if (this->unk_1DC != 0) {
            sp4C = (Vec3s*)Lib_PtrSegToVirt(this->unk_1DC->unk_04);
            Math_Vec3s_ToVec3f(&sp40, &sp4C[0]);
            Math_Vec3s_ToVec3f(&sp34, &sp4C[1]);
            Math_Vec3f_Copy(&this->unk_228, &sp40);
            Math_Vec3f_Copy(&this->unk_234, &sp34);
            this->actor.currPosRot.rot.y = Math_Vec3f_Yaw(&sp40, &sp34);
            Math_Vec3f_Copy(&this->actor.currPosRot, &sp40);
            if (ABS2((s16)(this->actor.currPosRot.rot.y - sp50->shape.rot.y)) < 0x4001) {
                this->unk_215 = -0x4B;
            } else {
                this->unk_215 = 0x4B;
            }
            this->unk_378 = arg2->unk_08 - arg2->unk_04;
            this->unk_37A = sp56 - arg2->unk_04;

            switch (arg2->unk_00) {
                case 27:
                case 28:
                case 32:
                case 33:
                case 34:
                case 35:
                case 37:
                case 38:
                    this->unk_38A = 2;
                    this->unk_38C = 2;
                    this->unk_38E = 8;

                default:
                    switch (arg2->unk_00) {
                        case 26:
                        case 27:
                        case 28:
                            this->unk_360 |= 0x900;
                            func_80B53CE8(this, globalCtx, 0x10);
                            break;

                        case 36:
                        case 39:
                            this->unk_360 |= 0x2100;
                            func_80B53CE8(this, globalCtx, 0x16);
                            break;

                        default:
                            this->unk_360 |= 0x100;
                            func_80B53CE8(this, globalCtx, 7);
                            break;
                    }
                    break;
            }

            this->actor.flags &= ~1;
            this->unk_360 |= 0x200;
            this->actor.gravity = 0.0f;
            sp2C = 1;
        }
    }
    return sp2C;
}

s32 func_80B56418(EnAn *this, GlobalContext *globalCtx, struct_80B578F8 *arg2) {
    u16 sp2E = gSaveContext.perm.time - 0x3FFC;
    u16 temp;
    u8 sp2B = this->actor.params & 0xFF;
    s32 pad;
    s32 sp20 = 0;

    this->unk_1DC = NULL;
    if (D_80B58618[arg2->unk_00] >= 0) {
        this->unk_1DC = func_8013BB34(globalCtx, sp2B, D_80B58618[arg2->unk_00]);
    }

    if ((this->unk_1DC != NULL) && (this->unk_1DC->unk_00 < 3)) {
        this->unk_1DC = NULL;
    }

    if (this->unk_1DC != NULL) {
        if ((this->unk_200 < 0x28) && (this->unk_200 != 0) && (this->unk_384 >= 0)) {
            temp = sp2E;
        } else {
            temp = arg2->unk_04;
        }
        if (arg2->unk_08 < temp) {
            this->unk_1F0 = (temp - arg2->unk_08) + 0xFFFF;
        } else {
            this->unk_1F0 = arg2->unk_08 - temp;
        }

        this->unk_1FC = sp2E - temp;
        temp = (this->unk_1DC->unk_00 - 2);
        this->unk_1F4 = this->unk_1F0 / temp;
        this->unk_1F8 = (this->unk_1FC / this->unk_1F4) + 2;
        this->unk_360 &= ~8;
        this->unk_360 &= ~0x10;

        switch (arg2->unk_00) {
            case 44:
            case 45:
            case 50:
            case 51:
            case 54:
            case 55:
            case 56:
            case 57:
            case 58:
            case 59:
            case 60:
            case 61:
            case 62:
            case 63:
                this->unk_38A = 2;
                this->unk_38C = 2;
                this->unk_38E = 8;

            default:
                switch (arg2->unk_00) {
                    case 42:
                    case 43:
                        func_8013AED4(&this->unk_360, 3, 7);

                    case 44:
                    case 45:
                        func_80B53CE8(this, globalCtx, 0x10);
                        this->unk_360 |= 0x300;
                        this->unk_360 |= 0x800;
                        break;

                    case 52:
                    case 53:
                        func_80B53CE8(this, globalCtx, 0x16);
                        func_8013AED4(&this->unk_360, 3, 7);
                        this->unk_360 |= 0x300;
                        this->unk_360 |= 0x2000;
                        break;

                    case 50:
                    case 51:
                        func_80B53CE8(this, globalCtx, 7);
                        this->unk_360 |= 0x300;
                        break;

                    case 54:
                    case 55:
                    case 56:
                    case 57:
                    case 58:
                    case 59:
                    case 60:
                    case 61:
                    case 62:
                    case 63:
                        func_80B53CE8(this, globalCtx, 0x12);
                        this->unk_360 |= 0x300;
                        this->unk_360 |= 0x1000;
                        break;

                    case 40:
                    case 47:
                    case 48:
                    case 49:
                        func_8013AED4(&this->unk_360, 3, 7);
                        this->unk_360 |= 0x300;

                    default:
                        func_80B53CE8(this, globalCtx, 7);
                }
        }

        this->actor.gravity = -1.0f;
        sp20 = 1;
    }
    return sp20;
}

s32 func_80B56744(EnAn *this, GlobalContext *globalCtx, struct_80B578F8 *arg2) {
    u8 sp4F = this->actor.params & 0xFF;
    Vec3f sp40;
    Vec3f sp34;
    Vec3s *sp30;
    s32 pad;
    s32 sp28;

    this->unk_1DC = NULL;
    sp28 = 0;
    if (D_80B58618[arg2->unk_00] >= 0) {
        this->unk_1DC = func_8013BB34(globalCtx, sp4F, D_80B58618[arg2->unk_00]);
    }

    if ((this->unk_1DC != NULL) && (this->unk_1DC->unk_00 >= 2)) {
        sp30 = (Vec3s*)Lib_PtrSegToVirt(this->unk_1DC->unk_04);
        Math_Vec3s_ToVec3f(&sp40, &sp30[0]);
        Math_Vec3s_ToVec3f(&sp34, &sp30[1]);
        this->actor.currPosRot.rot.y = Math_Vec3f_Yaw(&sp40, &sp34);
        Math_Vec3s_Copy(&this->actor.shape, &this->actor.currPosRot.rot);
        Math_Vec3f_Copy(&this->actor.currPosRot, &sp40);
        Math_Vec3f_Copy(&this->actor.lastPos, &sp40);
        if (arg2->unk_00 == 0x16) {
            func_80B53CE8(this, globalCtx, 0x17);
            func_8013AED4(&this->unk_360, 3, 7);
            this->unk_360 |= 0x300;
            this->unk_360 |= 0x2000;
        }
        sp28 = 1;
    }
    return sp28;
}

s32 func_80B56880(EnAn *this, GlobalContext *globalCtx, struct_80B578F8 *arg2) {
    u8 sp4F = this->actor.params & 0xFF;
    Vec3f sp40;
    Vec3f sp34;
    Vec3s *sp30;
    s32 pad;
    s32 sp28;

    this->unk_1DC = NULL;
    sp28 = 0;
    if (D_80B58618[arg2->unk_00] >= 0) {
        this->unk_1DC = func_8013BB34(globalCtx, sp4F, D_80B58618[arg2->unk_00]);
    }

    if ((this->unk_1DC != NULL) && (this->unk_1DC->unk_00 >= 2)) {
        sp30 = (Vec3s*)Lib_PtrSegToVirt(this->unk_1DC->unk_04);
        Math_Vec3s_ToVec3f(&sp40, &sp30[this->unk_1DC->unk_00 - 1]);
        Math_Vec3s_ToVec3f(&sp34, &sp30[this->unk_1DC->unk_00 - 2]);
        this->actor.currPosRot.rot.y = Math_Vec3f_Yaw(&sp34, &sp40);
        Math_Vec3s_Copy(&this->actor.shape, &this->actor.currPosRot.rot);
        Math_Vec3s_Copy(&this->actor.initPosRot.rot, &this->actor.currPosRot.rot);
        Math_Vec3f_Copy(&this->actor.currPosRot, &sp40);
        Math_Vec3f_Copy(&this->actor.lastPos, &sp40);

        switch (arg2->unk_00) {
            case 19:
                this->actor.currPosRot.rot.y += 0x7FF8;
            case 18:
            case 23:
                func_80B53CE8(this, globalCtx, 1);
                func_8013AED4(&this->unk_360, 3, 7);
                this->unk_37A = 0;
                this->unk_360 |= 0x300;
                if (arg2->unk_00 == 0x12) {
                    this->unk_374 = 70.0f;
                }
                break;

            case 3:
                this->unk_360 |= 0x300;
                this->unk_360 |= 0x1000;
                if (gSaveContext.perm.weekEventReg[55] & 0x20) {
                    func_80B53CE8(this, globalCtx, 0x14);
                    this->unk_360 |= 0x40;
                    this->actor.currPosRot.rot.y += 0x7FF8;
                    this->actor.shape.rot.y = this->actor.currPosRot.rot.y;
                    this->unk_37A = 4;
                } else {
                    func_80B53CE8(this, globalCtx, 0x12);
                    this->unk_37A = 0;
                }
                this->unk_38A = 2;
                this->unk_38C = 2;
                this->unk_38E = 8;
                break;

            case 14:
                func_80B53CE8(this, globalCtx, 0xC);
                func_8013AED4(&this->unk_360, 3, 7);
                this->unk_360 |= 0x300;
                this->unk_360 |= 0x8000;
                break;
        }
        sp28 = 1;
    }

    return sp28;
}

s32 func_80B56B00(EnAn *this, GlobalContext *globalCtx, struct_80B578F8 *arg2) {
    s32 pad;

    Math_Vec3f_Copy(&this->actor.currPosRot, &D_80B58E7C);
    Math_Vec3s_Copy(&this->actor.shape, &D_80B58E88);
    Math_Vec3s_Copy(&this->actor.currPosRot.rot, &this->actor.shape);
    if (arg2->unk_00 == 0xC) {
        func_80B53CE8(this, globalCtx, 0xB);
        func_8013AED4(&this->unk_360, 3, 7);
        this->unk_360 |= 0x300;
        this->unk_360 |= 0x40;
        this->unk_38A = 5;
        this->unk_38C = 5;
        this->unk_38E = 8;
    }
    return 1;
}

s32 func_80B56BC0(EnAn *this, GlobalContext *globalCtx, struct_80B578F8 *arg2) {
    s32 pad;

    Math_Vec3f_Copy(&this->actor.currPosRot, &D_80B58E90);
    Math_Vec3s_Copy(&this->actor.shape, &D_80B58E9C);
    Math_Vec3s_Copy(&this->actor.currPosRot.rot, &this->actor.shape);

    switch (arg2->unk_00) {
        case 1:
            func_8013AED4(&this->unk_360, 3, 7);
            func_80B53CE8(this, globalCtx, 9);
            break;

        case 0x18:
            func_80B53CE8(this, globalCtx, 0xB);
            this->unk_38A = 5;
            this->unk_38C = 5;
            this->unk_38E = 8;
            break;
    }

    this->unk_360 |= 0x300;
    this->unk_360 |= 0x40;
    this->actor.gravity = 0.0f;
    return 1;
}

s32 func_80B56CAC(EnAn *this, GlobalContext *globalCtx, struct_80B578F8 *arg2) {
    s32 pad;

    Math_Vec3s_Copy(&this->actor.shape, &D_80B58EA4);
    Math_Vec3s_Copy(&this->actor.currPosRot.rot, &this->actor.shape);
    func_80B53CE8(this, globalCtx, 0);
    func_8013AED4(&this->unk_360, 3, 7);
    this->unk_360 |= 0x300;
    return 1;
}

s32 func_80B56D28(EnAn *this, GlobalContext *globalCtx, struct_80B578F8 *arg2) {
    s32 phi_v1;

    this->actor.flags |= 1;
    this->actor.unk1F = 6;
    this->unk_360 = 0;
    this->unk_38A = 0;
    this->unk_38C = 0;
    this->unk_38E = 8;
    this->unk_374 = 40.0f;

    switch (arg2->unk_00) {
        case 16:
            phi_v1 = func_80B5600C(this, globalCtx, arg2);
            break;

        case 17:
            phi_v1 = func_80B56094(this, globalCtx, arg2);
            break;

        case 21:
            phi_v1 = func_80B5611C(this, globalCtx, arg2);
            break;

        case 12:
            phi_v1 = func_80B56B00(this, globalCtx, arg2);
            break;

        case 1:
        case 24:
            phi_v1 = func_80B56BC0(this, globalCtx, arg2);
            break;

        case 3:
        case 14:
        case 18:
        case 19:
        case 23:
            phi_v1 = func_80B56880(this, globalCtx, arg2);
            break;

        case 22:
            phi_v1 = func_80B56744(this, globalCtx, arg2);
            break;

        case 25:
            phi_v1 = func_80B56CAC(this, globalCtx, arg2);
            break;

        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
            phi_v1 = func_80B561A4(this, globalCtx, arg2);
            break;

        case 40:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
            phi_v1 = func_80B56418(this, globalCtx, arg2);
            break;

        default:
            phi_v1 = 0;
            break;
    }

    return phi_v1;
}

s32 func_80B56E44(EnAn *this, GlobalContext *globalCtx) {
    Vec3f sp2C;
    Vec3f sp20;

    if ((this->unk_218 != NULL) && (this->unk_218->update != NULL)) {
        Math_Vec3f_Copy(&sp2C, &this->unk_218->currPosRot.pos);
        Math_Vec3f_Copy(&sp20, &this->actor.currPosRot.pos);
        this->actor.currPosRot.rot.y = Math_Vec3f_Yaw(&sp20, &sp2C);
    }

    return 1;
}

s32 func_80B56EB4(EnAn *this, GlobalContext *globalCtx) {
    EnDoor *sp44 = (EnDoor*)func_80B53B3C(globalCtx, this->unk_200);
    Vec3f sp38;
    s32 pad;
    f32 temp;

    if ((func_8013AD6C(globalCtx) == 0) && (this->unk_384 != 0)) {
        if ((sp44 != NULL) && (sp44->actor.update != NULL)) {
            if (((f32)this->unk_37A / this->unk_378) <= 0.9f) {
                sp44->unk_1A7 = this->unk_215;
            } else {
                sp44->unk_1A7 = 0;
            }
        }
        if (this->unk_37A < 0) {
            this->unk_37A = 0;
        } else {
            s32 val;
            if (this->unk_378 < this->unk_37A) {
                val = this->unk_378;
            } else {
                val = this->unk_37A;
            }
            this->unk_37A = val;
        }

        temp = Math_Vec3f_DistXZ(&this->unk_228, &this->unk_234) / this->unk_378;
        sp38.x = 0.0f;
        sp38.y = 0.0f;
        sp38.z = this->unk_37A * temp;

        Lib_TranslateAndRotateYVec3f(&this->unk_228, this->actor.currPosRot.rot.y, &sp38, &this->actor.currPosRot.pos);
        this->unk_37A += this->unk_384;
        if ((func_801378B8(&this->skelAnime, 3.0f) != 0) || (func_801378B8(&this->skelAnime, 15.0f) != 0)) {
            func_800B8EC8(&this->actor, 0x2971);
        }
    }

    return 0;
}

s32 func_80B5702C(EnAn *this, GlobalContext *globalCtx) {
    s32 pad;
    s32 sp7C[0x108]; // some kind of struct array, sizes unknown
    Vec3f sp70;
    Vec3f sp64;
    Vec3f sp58;
    s32 sp54;
    s32 sp50;
    s32 pad2;

    sp50 = 0;
    sp54 = 0;

    func_8013AF00(sp7C, 3, this->unk_1DC->unk_00 + 3);
    if ((this->unk_360 & 8) == 0) {
        sp58 = D_801D15B0;
        func_8013B6B0(this->unk_1DC, &this->unk_1EC, &this->unk_1FC, this->unk_1F4, this->unk_1F0, &this->unk_1F8, sp7C, &sp58, this->unk_384);
        func_8013B878(globalCtx, this->unk_1DC, this->unk_1F8, &sp58);
        this->actor.currPosRot.pos.y = sp58.y;
        this->unk_360 |= 8;
    } else {
        sp58 = this->unk_1E0;
    }
    this->actor.currPosRot.pos.x = sp58.x;
    this->actor.currPosRot.pos.z = sp58.z;

    if (func_8013AD6C(globalCtx) != 0) {
        sp54 = this->unk_1FC;
        sp50 = this->unk_1F8;
        sp58 = this->actor.currPosRot.pos;
    }

    this->unk_1E0 = D_801D15B0;
    if (func_8013B6B0(this->unk_1DC, &this->unk_1EC, &this->unk_1FC, this->unk_1F4, this->unk_1F0, &this->unk_1F8, sp7C, &this->unk_1E0, this->unk_384) != 0) {
        this->unk_360 |= 0x10;
    } else {
        sp70 = this->actor.currPosRot.pos;
        sp64 = this->unk_1E0;
        this->actor.currPosRot.rot.y = Math_Vec3f_Yaw(&sp70, &sp64);
    }

    if (func_8013AD6C(globalCtx) != 0) {
        this->unk_1FC = sp54;
        this->unk_1F8 = sp50;
        this->unk_1E0 = sp58;
    } else if ((func_801378B8(&this->skelAnime, 3.0f) != 0) || (func_801378B8(&this->skelAnime, 15.0f) != 0)) {
        func_800B8EC8(this, 0x2971);
    }

    return 0;
}

s32 func_80B572D4(EnAn *this, GlobalContext *globalCtx) {
    switch (this->unk_200) {
        case 23:
            if ((func_80B55F8C(globalCtx) != 0) && (func_80B55ECC(this) != 0)) {
                this->unk_360 |= 0x20;
            } else {
                this->unk_360 &= ~0x20;
            }
            break;

        case 1:
            if (func_80B55ECC(this) != 0) {
                this->unk_360 |= 0x20;
            } else {
                this->unk_360 &= ~0x20;
            }
            break;

        case 18:
        case 19:
            if (func_80B55ECC(this) != 0) {
                this->unk_360 |= 0x20;
            } else {
                this->unk_360 &= ~0x20;
            }
            break;

        case 22:
            if ((func_801378B8(&this->skelAnime, 6.0f) != 0) && (this->unk_39C == 0x17)) {
                func_800B8EC8(&this->actor, 0x2899);
            }
            break;
    }

    return 0;
}

s32 func_80B573F4(EnAn *this, GlobalContext *globalCtx) {
    s16 temp1;
    s16 temp2;

    switch (this->unk_37A) {
        case 0:
            this->actor.currPosRot.rot.y += 0x7FF8;
            this->unk_37A++;
            break;

        case 1:
            temp1 = (this->actor.currPosRot.rot.y / 0xB6) * 0xB6;
            temp2 = (this->actor.shape.rot.y / 0xB6) * 0xB6;
            if (temp1 == temp2) {
                Math_Vec3s_Copy(&this->actor.shape, &this->actor.currPosRot.rot);
                func_80B53CE8(this, globalCtx, 0x13);
                this->unk_360 |= 0x40;
                this->unk_37A++;
            }
            break;

        case 2:
            if (func_801378B8(&this->skelAnime, this->skelAnime.animFrameCount) != 0) {
                this->unk_37A++;
            }
            break;

        case 3:
            if (ABS2((s16)(this->actor.rotTowardsLinkY - this->actor.shape.rot.y)) < 0x3000) {
                func_8013AED4(&this->unk_360, 3, 7);
            } else {
                func_8013AED4(&this->unk_360, 0, 7);
            }
            break;

        case 4:
            func_8013AED4(&this->unk_360, 3, 7);
            this->unk_37A++;
            break;
    }
    return 0;
}

s32 func_80B575BC(EnAn *this, GlobalContext *globalCtx) {
    s16 rot = this->actor.shape.rot.y;
    s16 absRot = ABS2((s16)(this->actor.rotTowardsLinkY - rot));

    if (absRot < 0x4000) {
        func_8013AED4(&this->unk_360, 3, 7);
    } else {
        func_8013AED4(&this->unk_360, 0, 7);
    }

    if (func_80B55ECC(this) != 0) {
        this->unk_360 |= 0x20;
    } else {
        this->unk_360 &= ~0x20;
    }

    return 1;
}

s32 func_80B57674(EnAn *this, GlobalContext *globalCtx) {
    s16 rot = this->actor.shape.rot.y + 0x3000;
    s16 absRot = ABS2((s16)(this->actor.rotTowardsLinkY - rot));

    if (absRot < 0x3000) {
        func_8013AED4(&this->unk_360, 3, 7);
    } else {
        func_8013AED4(&this->unk_360, 0, 7);
    }

    this->unk_360 &= ~0x20;
    return 1;
}

void func_80B57718(EnAn *this, GlobalContext *globalCtx) {
    switch (this->unk_200) {
        case 16:
        case 17:
        case 21:
            func_80B56E44(this, globalCtx);
            break;

        case 3:
            func_80B573F4(this, globalCtx);
            break;

        case 1:
            func_80B575BC(this, globalCtx);
            break;

        case 25:
            func_80B57674(this, globalCtx);
            break;

        case 12:
        case 14:
        case 18:
        case 19:
        case 22:
        case 24:
            func_80B572D4(this, globalCtx);
            break;

        case 23:
            func_80B572D4(this, globalCtx);
            break;

        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
            func_80B56EB4(this, globalCtx);
            break;

        case 40:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
            func_80B5702C(this, globalCtx);
            break;

        case 2:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 13:
        case 15:
        case 20:
        case 41:
            break;
    }

    Math_SmoothScaleMaxS(&this->actor.shape.rot.y, this->actor.currPosRot.rot.y, 3, 0x2AA8);
}

void func_80B577F0(EnAn *this, GlobalContext *globalCtx) {
    Actor_SetDrawParams(&this->actor.shape, 0.0f, NULL, 14.0f);
    SkelAnime_InitSV(globalCtx, &this->skelAnime, &D_06012618, NULL, this->limbDrawTable, this->transitionDrawTable, 21);
    this->unk_39C = -1;
    func_80B53CE8(this, globalCtx, 1);
    Collision_InitCylinder(globalCtx, &this->collider, &this->actor, &sCylinderInit);
    func_800E755C(&this->actor.unkA0, func_800E03A0(0x16), &D_80B58BE8);
    if (this->actor.params & 0x8000) {
        this->unk_3C0 = 1;
    }
    this->actor.draw = func_80B580C0;
    Actor_SetScale(&this->actor, 0.01f);
    this->unk_360 = 0;
    this->unk_200 = 0;
    this->actionFunc = func_80B578F8;
    this->actionFunc(this, globalCtx);
}

void func_80B578F8(EnAn *this, GlobalContext *globalCtx) {
    struct_80B578F8 sp20;

    this->unk_384 = REG(15) + ((void)0, gSaveContext.perm.unk14);
    if (!(this->actor.params & 0x8000) && (this->unk_3C0 == 0) && (gSaveContext.perm.weekEventReg[51] & 0x40)) {
        Actor_MarkForDeath(&this->actor);
        return;
    }

    if (this->unk_3C0 != 0) {
        sp20.unk_00 = 0x19;
        if (this->unk_200 != 0x19) {
            func_80B56D28(this, globalCtx, &sp20);
        }
    } else if ((func_80133038(globalCtx, D_80B581D0, &sp20) == 0) || ((this->unk_200 != sp20.unk_00) && (func_80B56D28(this, globalCtx, &sp20) == 0))) {
        this->actor.shape.shadowDrawFunc = NULL;
        this->actor.flags &= ~1;
        sp20.unk_00 = 0;
    } else {
        this->actor.shape.shadowDrawFunc = func_800B3FC0;
        this->actor.flags |= 1;
    }

    this->unk_200 = sp20.unk_00;
    this->unk_218 = func_80B55D20(this, globalCtx);
    func_80B57718(this, globalCtx);
}

void func_80B57A44(EnAn *this, GlobalContext *globalCtx) {
    if (func_8010BF58(this, globalCtx, this->unk_204, this->unk_398, &this->unk_210) != 0) {
        func_8013AED4(&this->unk_360, 3, 7);
        this->unk_360 &= ~0x20;
        this->unk_360 |= 0x200;
        this->unk_388 = 0x14;
        this->unk_210 = 0;
        this->actionFunc = func_80B578F8;
        return;
    }

    if ((this->unk_200 != 1) && (this->unk_200 != 3) && 
        (this->unk_200 != 0xC) && (this->unk_200 != 0xE) && 
        (this->unk_200 != 0x19)) {
        if ((this->unk_218 != 0) && (this->unk_218->update != 0)) {
            s16 temp;
            Vec3f sp38;
            Vec3f sp2C;

            Math_Vec3f_Copy(&sp38, &this->unk_218->currPosRot.pos);
            Math_Vec3f_Copy(&sp2C, &this->actor.currPosRot.pos);
            temp = Math_Vec3f_Yaw(&sp2C, &sp38);
            Math_SmoothScaleMaxS(&this->actor.shape.rot.y, temp, 4, 0x2AA8);
        }
    }
}

void func_80B57B48(EnAn *this, GlobalContext *globalCtx) {
    // D_80B58EAC
    s32 sp30[] = {
        0x00000000, 0x0000000B, 0x00000022, 
        0x00000019, 0x0000001A, 0x0000001C, 
        0x0000001E, 0x00000020, 0x00000021,
        0x00000000,
    };
    s32 pad;

    if (func_800EE29C(globalCtx, 0x22D) != 0) {
        s32 idx = func_800EE200(globalCtx, 0x22D);
        u16 temp_v1 = globalCtx->csCtx.actorActions[idx]->unk0;
        
        if (this->unk_364 != (temp_v1 & 0xFF)) {
            this->unk_364 = temp_v1;
            if (this->unk_364 == 3) {
                gSaveContext.perm.weekEventReg[87] |= 2;
                this->unk_3B4 = 1;
            }
            if (this->unk_364 == 9) {
                this->unk_3B4 = 0;
                if (0){};
            }
            func_80B53CE8(this, globalCtx, sp30[temp_v1]);
        }

        if ((this->unk_39C == 0x1A) || (this->unk_39C == 0x1C) || (this->unk_39C == 0x1E) || (this->unk_39C == 0x22)) {
            if (func_801378B8(&this->skelAnime, this->skelAnime.animFrameCount) != 0) {
                func_80B53CE8(this, globalCtx, this->unk_39C + 1);
            }
        }

        func_800EDF24(&this->actor, globalCtx, idx);
    }
}

void EnAn_Init(Actor* thisx, GameState *gameState) {
    EnAn *this = THIS;
    GlobalContext* globalCtx = (GlobalContext*)gameState;
    s32 param;
    s32 eventReg;

    if (globalCtx->sceneNum != 0x61) {
        this->actor.params &= 0x7FFF;
    }

    param = (this->actor.params & 0x8000) >> 0xF;
    eventReg = gSaveContext.perm.weekEventReg[51] & 0x40;
    if ((!eventReg && (param == 1)) || 
         (eventReg && (param == 0))) {
        Actor_MarkForDeath(&this->actor);
        return;
    }

    if ((param == 0) && (func_80B53A7C(this, globalCtx, ACTORTYPE_NPC, ACTOR_EN_AN) != NULL)) {
        Actor_MarkForDeath(&this->actor);
        return;
    }

    this->unk_214 = -0x80;
    this->unk_3B8 = 0;
    if (param == 0) {
        this->actor.room = -1;
    }
    this->actionFunc = func_80B577F0;
}

void EnAn_Destroy(Actor* thisx, GlobalContext *globalCtx) {
    EnAn *this = THIS;

    Collision_FiniCylinder(globalCtx, &this->collider);
}

void EnAn_Update(Actor* thisx, GlobalContext *globalCtx) {
    EnAn *this = THIS;

    if (func_80B53840(this, globalCtx) == 0) {
        if ((this->actionFunc != func_80B577F0) && (func_80B55180(this, globalCtx) == 0) && (func_80B552E4(this, globalCtx) != 0)) {
            func_80B57B48(this, globalCtx);
            func_80B53BA8(this, globalCtx);
            func_80B53F84(this);
            return;
        }

        this->actionFunc(this, globalCtx);
        if (this->unk_200 != 0) {
            func_80B55914(this, globalCtx);
            func_80B53BA8(this, globalCtx);
            func_80B53F84(this);
            func_80B554E8(this);
            func_8013C964(&this->actor, globalCtx, this->unk_374, 30.0f, 0, this->unk_360 & 7);
            if (!(this->unk_360 & 0x40)) {
                Actor_SetVelocityAndMoveYRotationAndGravity(&this->actor);
                func_800B78B8(globalCtx, &this->actor, 30.0f, 12.0f, 0.0f, 4);
            }
            func_80B53ED4(this, globalCtx);
        }
    }
}

void func_80B57EE8(GlobalContext *globalCtx, s32 limbIndex, Gfx **dList, Vec3s *rot, Actor* thisx) {
    static Vec3f D_80B58ED4 = { 1000.0f, 0.0f, 0.0f };

    EnAn *this = THIS;

    if (limbIndex == 9) {
        SysMatrix_MultiplyVector3fByState(&D_80B58ED4, &this->actor.topPosRot.pos);
        Math_Vec3s_Copy(&this->actor.topPosRot.rot, &this->actor.currPosRot.rot);
        func_80B54124(this, globalCtx, 1);
    } else if (limbIndex == 8) {
        func_80B54124(this, globalCtx, 0);
        func_80B54124(this, globalCtx, 4);
        func_80B54124(this, globalCtx, 2);
        func_80B54124(this, globalCtx, 3);
    } else if (limbIndex == 5) {
        func_80B54124(this, globalCtx, 5);
    }
}

void func_80B57FC4(GlobalContext *globalCtx, s32 limbIndex, Actor* thisx) {
    EnAn *this = THIS;
    s32 phi_v0 = 0;
    s32 phi_v1 = 0;

    if (!(this->unk_360 & 0x200)) {
        if (this->unk_360 & 0x80) {
            phi_v1 = 1;
            phi_v0 = 1;
        } else {
            phi_v1 = 0;
            phi_v0 = 1;
        }
    } else {
        phi_v0 = 0;
        phi_v1 = 0;
    }

    if (limbIndex == 9) {
        func_8013AD9C(this->unk_37C + 0x4000, this->unk_37E + this->actor.shape.rot.y + 0x4000, &this->unk_240, &this->unk_258, phi_v0, phi_v1);
        SysMatrix_StatePop();
        SysMatrix_InsertTranslation(this->unk_240.x, this->unk_240.y, this->unk_240.z, 0);
        SysMatrix_InsertScale(this->actor.scale.x, this->actor.scale.y, this->actor.scale.z, 1);
        SysMatrix_InsertYRotation_s(this->unk_258.y, 1);
        SysMatrix_InsertXRotation_s(this->unk_258.x, 1);
        SysMatrix_InsertZRotation_s(this->unk_258.z, 1);
        SysMatrix_StatePush();
    }
}

void func_80B580C0(EnAn *this, GlobalContext *globalCtx) {
    static Gfx* D_80B58EE0[] = {
        0x0600E6E0, 
        0x0600F7A0, 
        0x060101A0, 
    };

    static Gfx* D_80B58EEC[] = {
        0x0600E1E0, 
        0x0600EFA0, 
        0x0600F3A0, 
        0x0600EFA0, 
        0x0600FDA0, 
        0x0600F9A0, 
        0x060103A0, 
    };

    s32 pad[1];

    if ((this->unk_200 != 0) || (this->unk_3B0 != 0)) {
        GraphicsContext* oGfxCtx = globalCtx->state.gfxCtx;
        s32 pad2[1];

        func_8012C28C(globalCtx->state.gfxCtx);

        gSPSegment(oGfxCtx->polyOpa.p++, 0x08, Lib_PtrSegToVirt(D_80B58EEC[this->unk_390]));
        gSPSegment(oGfxCtx->polyOpa.p++, 0x09, Lib_PtrSegToVirt(D_80B58EE0[this->unk_392]));

        func_801343C0(globalCtx, this->skelAnime.skeleton, this->skelAnime.limbDrawTbl, this->skelAnime.dListCount, NULL, func_80B57EE8, func_80B57FC4, &this->actor);
    }
}
