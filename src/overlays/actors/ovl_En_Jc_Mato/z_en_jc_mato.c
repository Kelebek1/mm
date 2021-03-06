#include "z_en_jc_mato.h"

#define FLAGS 0x00004030

#define THIS ((EnJcMato*)thisx)

void EnJcMato_Init(Actor* thisx, GlobalContext* globalCtx);
void EnJcMato_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnJcMato_Update(Actor* thisx, GlobalContext* globalCtx);
void EnJcMato_Draw(Actor* thisx, GlobalContext* globalCtx);

/*
const ActorInit En_Jc_Mato_InitVars = {
    ACTOR_EN_JC_MATO,
    ACTORTYPE_PROP,
    FLAGS,
    OBJECT_TRU,
    sizeof(EnJcMato),
    (ActorFunc)EnJcMato_Init,
    (ActorFunc)EnJcMato_Destroy,
    (ActorFunc)EnJcMato_Update,
    (ActorFunc)EnJcMato_Draw
};
*/

GLOBAL_ASM("asm/non_matchings/ovl_En_Jc_Mato_0x80B9DEE0/func_80B9DEE0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Jc_Mato_0x80B9DEE0/func_80B9DFC8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Jc_Mato_0x80B9DEE0/func_80B9DFDC.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Jc_Mato_0x80B9DEE0/EnJcMato_Init.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Jc_Mato_0x80B9DEE0/EnJcMato_Destroy.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Jc_Mato_0x80B9DEE0/EnJcMato_Update.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Jc_Mato_0x80B9DEE0/EnJcMato_Draw.asm")
