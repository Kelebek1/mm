#include "z_bg_dblue_elevator.h"

#define FLAGS 0x00000010

#define THIS ((BgDblueElevator*)thisx)

void BgDblueElevator_Init(Actor* thisx, GlobalContext* globalCtx);
void BgDblueElevator_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgDblueElevator_Update(Actor* thisx, GlobalContext* globalCtx);
void BgDblueElevator_Draw(Actor* thisx, GlobalContext* globalCtx);

/*
const ActorInit Bg_Dblue_Elevator_InitVars = {
    ACTOR_BG_DBLUE_ELEVATOR,
    ACTORTYPE_BG,
    FLAGS,
    OBJECT_DBLUE_OBJECT,
    sizeof(BgDblueElevator),
    (ActorFunc)BgDblueElevator_Init,
    (ActorFunc)BgDblueElevator_Destroy,
    (ActorFunc)BgDblueElevator_Update,
    (ActorFunc)BgDblueElevator_Draw
};
*/

GLOBAL_ASM("asm/non_matchings/ovl_Bg_Dblue_Elevator_0x80B91F20/func_80B91F20.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Bg_Dblue_Elevator_0x80B91F20/func_80B91F74.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Bg_Dblue_Elevator_0x80B91F20/func_80B922C0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Bg_Dblue_Elevator_0x80B91F20/func_80B922FC.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Bg_Dblue_Elevator_0x80B91F20/BgDblueElevator_Init.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Bg_Dblue_Elevator_0x80B91F20/BgDblueElevator_Destroy.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Bg_Dblue_Elevator_0x80B91F20/func_80B924DC.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Bg_Dblue_Elevator_0x80B91F20/func_80B924F8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Bg_Dblue_Elevator_0x80B91F20/func_80B9257C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Bg_Dblue_Elevator_0x80B91F20/func_80B925B8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Bg_Dblue_Elevator_0x80B91F20/func_80B92644.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Bg_Dblue_Elevator_0x80B91F20/func_80B92660.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Bg_Dblue_Elevator_0x80B91F20/BgDblueElevator_Update.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Bg_Dblue_Elevator_0x80B91F20/BgDblueElevator_Draw.asm")
