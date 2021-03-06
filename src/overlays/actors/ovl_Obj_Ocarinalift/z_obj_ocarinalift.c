#include "z_obj_ocarinalift.h"

#define FLAGS 0x00000010

#define THIS ((ObjOcarinalift*)thisx)

void ObjOcarinalift_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjOcarinalift_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjOcarinalift_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjOcarinalift_Draw(Actor* thisx, GlobalContext* globalCtx);

/*
const ActorInit Obj_Ocarinalift_InitVars = {
    ACTOR_OBJ_OCARINALIFT,
    ACTORTYPE_BG,
    FLAGS,
    OBJECT_RAILLIFT,
    sizeof(ObjOcarinalift),
    (ActorFunc)ObjOcarinalift_Init,
    (ActorFunc)ObjOcarinalift_Destroy,
    (ActorFunc)ObjOcarinalift_Update,
    (ActorFunc)ObjOcarinalift_Draw
};
*/

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/func_80AC94C0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/ObjOcarinalift_Init.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/ObjOcarinalift_Destroy.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/func_80AC9680.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/func_80AC96A4.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/func_80AC96B4.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/func_80AC96D0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/func_80AC99C0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/func_80AC99D4.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/func_80AC9A68.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/func_80AC9A7C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/func_80AC9AB8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/func_80AC9AE0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/func_80AC9B48.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/func_80AC9B5C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/func_80AC9C20.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/func_80AC9C48.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/ObjOcarinalift_Update.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Ocarinalift_0x80AC94C0/ObjOcarinalift_Draw.asm")
