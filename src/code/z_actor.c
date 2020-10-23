#include <ultra64.h>
#include <global.h>

extern Gfx D_04076BC0[];
extern Gfx D_04075A40[];
extern Gfx D_04077480[];
extern Gfx D_04075B30[];

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_PrintLists.asm")

void Actor_SetDrawParams(ActorShape* iParm1, f32 yDisplacement, actor_shadow_draw_func func, f32 scale) {
    iParm1->yDisplacement = yDisplacement;
    iParm1->shadowDrawFunc = func;
    iParm1->scale = scale;
    iParm1->alphaScale = 255;
}

void Actor_PostDraw(Actor* actor, Lights* lights, GlobalContext* globalCtx, Gfx* dlist, ColorRGBA8* color) {
    f32 temp1;
    f32 temp2;
    MtxF sp60;

    if (actor->floorPoly != NULL) {
        temp1 = actor->posRot.pos.y - actor->groundY;

        if (temp1 >= -50.0f && temp1 < 500.0f) {
            OPEN_DISPS(globalCtx->state.gfxCtx);

            oGfxCtx->polyOpa.p = Gfx_CallSetupDL(oGfxCtx->polyOpa.p, 0x2C);

            gDPSetCombineLERP(oGfxCtx->polyOpa.p++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0,
                              0, 0, COMBINED);

            temp1 = (temp1 < 0.0f) ? 0.0f : ((temp1 > 150.0f) ? 150.0f : temp1);
            temp2 = 1.0f - (temp1 * (1.f / 350));
            if ((temp1 * (1.f / 350)) > 1.0f) {
                temp2 = 0.0f;
            }

            if (color != NULL) {
                gDPSetPrimColor(oGfxCtx->polyOpa.p++, 0, 0, color->red, color->green, color->blue,
                                (u8)(actor->shape.alphaScale * temp2));
            } else {
                gDPSetPrimColor(oGfxCtx->polyOpa.p++, 0, 0, 0, 0, 0, (u8)(actor->shape.alphaScale * temp2));
            }

            func_800C0094(actor->floorPoly, actor->posRot.pos.x, actor->groundY, actor->posRot.pos.z, &sp60);
            SysMatrix_SetCurrentState(&sp60);

            if ((dlist != D_04076BC0) || (actor->scale.x != actor->scale.z)) {
                SysMatrix_InsertYRotation_s(actor->shape.rot.y, MTXMODE_APPLY);
            }

            temp2 *= actor->shape.scale;
            SysMatrix_InsertScale(actor->scale.x * temp2, 1.0f, actor->scale.z * temp2, MTXMODE_APPLY);

            gSPMatrix(oGfxCtx->polyOpa.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx),
                      G_MTX_MODELVIEW | G_MTX_LOAD);
            gSPDisplayList(oGfxCtx->polyOpa.p++, dlist);

            CLOSE_DISPS(globalCtx->state.gfxCtx);
        }
    }
}

// ActorShadow_DrawFunc_Circle
void func_800B3FC0(Actor *actor, Lights* lights, GlobalContext *globalCtx) {
    if (actor->bgCheckFlags & 0x400) {
        func_800B4AEC(globalCtx, actor, 50.0f);
    }
    Actor_PostDraw(actor, lights, globalCtx, D_04076BC0, NULL);
}

void func_800B4024(Actor *actor, Lights* lights, GlobalContext *globalCtx) {
    if (actor->bgCheckFlags & 0x400) {
        func_800B4AEC(globalCtx, actor, 50.0f);
    }
    Actor_PostDraw(actor, lights, globalCtx, D_04075A40, NULL);
}

// ActorShadow_DrawFunc_WhiteCircle
void func_800B4088(Actor *actor, Lights* lights, GlobalContext *ctxt) {
    static ColorRGBA8 D_801AEC80 = { 255, 255, 255, 255 };

    Actor_PostDraw(actor, lights, ctxt, D_04076BC0, &D_801AEC80);
}

// ActorShadow_DrawFunc_Squiggly
void func_800B40B8(Actor *actor, Lights* lights, GlobalContext *ctxt) {
    Actor_PostDraw(actor, lights, ctxt, D_04077480, NULL);
}

void func_800B40E0(GlobalContext* globalCtx, Light* light, MtxF* arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    s32 pad;
    s16 sp58;
    f32 temp1;
    f32 temp2;

    s32 pad2; // macro temp?
    OPEN_DISPS(globalCtx->state.gfxCtx);

    gDPSetPrimColor(oGfxCtx->polyOpa.p++, 0, 0, 0, 0, 0,
                    (u8)(((arg3 * 0.00005f) > 1.0f ? 1.0f : (arg3 * 0.00005f)) * arg4));

    temp2 = light->l.dir[0];
    temp1 = light->l.dir[2];
    sp58 = atans_flip(temp1, temp2);
    arg6 *= (4.5f - (light->l.dir[1] * 0.035f));
    arg6 = (arg6 < 1.0f) ? 1.0f : arg6;
    SysMatrix_SetCurrentState(arg2);
    SysMatrix_InsertYRotation_s(sp58, MTXMODE_APPLY);
    SysMatrix_InsertScale(arg5, 1.0f, arg5 * arg6, MTXMODE_APPLY);

    gSPMatrix(oGfxCtx->polyOpa.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(oGfxCtx->polyOpa.p++, D_04075B30);

    CLOSE_DISPS(globalCtx->state.gfxCtx);
}

// ActorShadow_DrawFunc_Teardrop
void func_800B42F8(ActorPlayer* player, Lights* lights, GlobalContext* globalCtx) {
    f32 phi_f2;
    f32 oldScale;
    u8 temp_14;
    s32 pad[1];
    f32 temp_f26;
    

    MtxF sp13C;
    MtxF spFC;
    BgPolygon* spF8;
    s32 spF4;
    f32 spEC[2];

    f32 temp_10;
    f32 temp_f24;
    s32 temp_a3;
    s32 phi_s1;
    f32 temp_f26_2;
    f32 temp_f22_2;
    s32 i;

    Vec3f* phi_s7;
    s32 temp_s6;
    f32 temp_f0;
    s32 pad2;
    f32* spBC;
    s32 spB8;

    temp_f26 = player->base.posRot.pos.y - player->base.groundY;
    
    if (temp_f26 > 0.0f) {
        temp_10 = player->base.shape.scale;
        temp_14 = player->base.shape.alphaScale;
        if ((player->base.id == ACTOR_PLAYER) && (player->unkA74 & 0x8000)) {
            oldScale = player->base.scale.z;
            if (1){};
            player->base.scale.z += 0.03f * fabsf(Math_Coss(player->unk_AAA));
            player->base.shape.scale *= 0.2f;
            player->base.shape.alphaScale = player->base.shape.alphaScale * CLAMP_MAX(temp_f26 * 0.03f, 1.0f);
            Actor_PostDraw(&player->base, lights, globalCtx, D_04076BC0, NULL);
            player->base.scale.z = oldScale;
            player->base.shape.scale = temp_10;
        } else {
            player->base.shape.scale *= 0.3f;
            player->base.shape.alphaScale = player->base.shape.alphaScale * CLAMP_MAX((temp_f26 - 20.0f) * 0.02f, 1.0f);
            func_800B3FC0(&player->base, lights, globalCtx);
            player->base.shape.scale = temp_10;
        }

        player->base.shape.alphaScale = temp_14;
    }

    if (temp_f26 < 200.0f) {
        temp_s6 = lights->numLights - 2;
        phi_s7 = &player->base.unk_D4[0];
        spBC = &spEC[0];

        OPEN_DISPS(globalCtx->state.gfxCtx);

        oGfxCtx->polyOpa.p = Gfx_CallSetupDL(oGfxCtx->polyOpa.p, 0x2C);
        player->base.shape.unk_15 = 0;
        spB8 = 2;

        for (i = 0; i < 2; i++, spB8 >>= 1) {
            phi_s7->y += 50.0f;
            *spBC = func_80169100(globalCtx, &sp13C, &spF8, &spF4, phi_s7);
            phi_s7->y -= 50.0f;
            temp_f26 = phi_s7->y - *spBC;

            if ((temp_f26 >= -1.0f) && (temp_f26 < 500.0f)) {
                Light* phi_s0 = &lights->l.l[0];
                s32 phi_s2 = 0;

                if (temp_f26 <= 10.0f) {
                    player->base.shape.unk_15 |= spB8;
                    if ((player->base.waterY < 0.0f) && (spF4 == 0x32) && (player->base.shape.unk_17 & spB8)) {
                        if (func_800C9C24(&globalCtx->colCtx, spF8, spF4, 1) != 0) {
                            Matrix_Copy(&sp13C, &spFC);
                            Matrix_YRotation(&spFC, player->base.shape.rot.y);
                            EffFootmark_Add(globalCtx, &spFC, &player->base, i, phi_s7, player->base.shape.scale * 0.3f, IREG(88) + 0x50, IREG(89) + 0x3C, IREG(90) + 0x28, 0x7530, 0xC8, 0x3C);
                        }
                        player->base.shape.unk_17 &= ~spB8;
                    }
                }

                if (30.0f < temp_f26) {
                    temp_f26 = 30.0f;
                }

                temp_f24 = player->base.shape.alphaScale * (1.0f - (temp_f26 * (1.0f / 30)));

                temp_f26_2 = 1.0f - (temp_f26 * (1.0f / 70));
                temp_f22_2 = (player->base.shape.scale * temp_f26_2) * player->base.scale.x;

                phi_s2 = 0;
                phi_s0 = &lights->l.l[0];

                for (phi_s1 = 0; phi_s1 < temp_s6; phi_s1++) {
                    if (phi_s0->l.dir[1] > 0) {
                        temp_a3 = (phi_s0->l.col[0] + phi_s0->l.col[1] + phi_s0->l.col[2]) * ABS2(phi_s0->l.dir[1]);
                        if (temp_a3 > 0) {
                            phi_s2 += temp_a3;
                            func_800B40E0(globalCtx, phi_s0, &sp13C, temp_a3, temp_f24, temp_f22_2, temp_f26_2);
                        }
                    }
                    phi_s0++;
                }

                for (phi_s1 = 0; phi_s1 < 2; phi_s1++) {
                    if (phi_s0->l.dir[1] > 0) {
                        temp_a3 = (ABS2(phi_s0->l.dir[1]) * (phi_s0->l.col[0] + phi_s0->l.col[1] + phi_s0->l.col[2])) -
                                  (0, (phi_s2 * 8));
                        if (temp_a3 > 0) {
                            func_800B40E0(globalCtx, phi_s0, &sp13C, temp_a3, temp_f24, temp_f22_2, temp_f26_2);
                        }
                    }
                    phi_s0++;
                }
            }

            phi_s7++; 
            spBC++; 
        }

        if (!(player->base.bgCheckFlags & 1)) {
            player->base.shape.unk_15 = 0;
        } else if (player->base.shape.unk_15 == 3) {
            temp_f0 = player->base.unk_D4[0].y - player->base.unk_D4[1].y;

            if ((spEC[0] + temp_f0) < (spEC[1] - temp_f0)) {
                player->base.shape.unk_15 = 2;
            } else {
                player->base.shape.unk_15 = 1;
            }
        }

        CLOSE_DISPS(globalCtx->state.gfxCtx);
    }
}

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B4A98.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B4AEC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B4B50.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B4EDC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B4F40.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B4F78.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B5040.asm")

void Actor_TargetContextInit(TargetContext* targetCtxt, Actor* actor, GlobalContext* ctxt) {
    targetCtxt->unk90 = NULL;
    targetCtxt->unk8C = NULL;
    targetCtxt->unk3C = NULL;
    targetCtxt->unk38 = NULL;
    targetCtxt->unk4B = 0;
    targetCtxt->unk4C = 0;
    targetCtxt->unk40 = 0;
    func_800B5040(targetCtxt, actor, actor->type, ctxt);
    func_800B4F78(targetCtxt, actor->type, ctxt);
}

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B5208.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B5814.asm")

u32 Actor_GetSwitchFlag(GlobalContext* ctxt, s32 flag) {
    if (flag >= 0 && flag < 0x80) {
        return ctxt->actorCtx.switchFlags[(flag & -0x20) >> 5] & (1 << (flag & 0x1F));
    }
    return 0;
}

void Actor_SetSwitchFlag(GlobalContext* ctxt, s32 flag){
    if (flag >= 0 && flag < 0x80) {
        ctxt->actorCtx.switchFlags[(flag & -0x20) >> 5] |= 1 << (flag & 0x1F);
    }
}

void Actor_UnsetSwitchFlag(GlobalContext* ctxt, s32 flag) {
    if (flag >= 0 && flag < 0x80) {
        ctxt->actorCtx.switchFlags[(flag & -0x20) >> 5] &= ~(1 << (flag & 0x1F));
    }
}

u32 Actor_GetChestFlag(GlobalContext* ctxt, u32 flag) {
    return ctxt->actorCtx.chestFlags & (1 << flag);
}

void Actor_SetChestFlag(GlobalContext* ctxt, u32 flag) {
    ctxt->actorCtx.chestFlags |= (1 << flag);
}

void Actor_SetAllChestFlag(GlobalContext* ctxt, u32 flag) {
    ctxt->actorCtx.chestFlags = flag;
}

u32 Actor_GetAllChestFlag(GlobalContext* ctxt) {
    return ctxt->actorCtx.chestFlags;
}

u32 Actor_GetRoomCleared(GlobalContext* ctxt, u32 roomNumber) {
    return ctxt->actorCtx.clearedRooms & (1 << roomNumber);
}

void Actor_SetRoomCleared(GlobalContext* ctxt, u32 roomNumber) {
    ctxt->actorCtx.clearedRooms |= (1 << roomNumber);
}

void Actor_UnsetRoomCleared(GlobalContext* ctxt, u32 roomNumber) {
    ctxt->actorCtx.clearedRooms &= ~(1 << roomNumber);
}

u32 Actor_GetRoomClearedTemp(GlobalContext* ctxt, u32 roomNumber) {
    return ctxt->actorCtx.clearedRoomsTemp & (1 << roomNumber);
}

void Actor_SetRoomClearedTemp(GlobalContext* ctxt, u32 roomNumber) {
    ctxt->actorCtx.clearedRoomsTemp |= (1 << roomNumber);
}

void Actor_UnsetRoomClearedTemp(GlobalContext* ctxt, u32 roomNumber) {
    ctxt->actorCtx.clearedRoomsTemp &= ~(1 << roomNumber);
}

u32 Actor_GetCollectibleFlag(GlobalContext* ctxt, s32 index) {
    if (index > 0 && index < 0x80) {
        return ctxt->actorCtx.collectibleFlags[(index & -0x20) >> 5] & (1 << (index & 0x1F));
    }
    return 0;
}

void Actor_SetCollectibleFlag(GlobalContext* ctxt, s32 index) {
    if (index > 0 && index < 0x80) {
        ctxt->actorCtx.collectibleFlags[(index & -0x20) >> 5] |= 1 << (index & 0x1F);
    }
}

void Actor_TitleCardContextInit(GlobalContext* ctxt, TitleCardContext* titleCtxt) {
    titleCtxt->fadeOutDelay = 0;
    titleCtxt->fadeInDelay = 0;
    titleCtxt->color = 0;
    titleCtxt->alpha = 0;
}

void Actor_TitleCardCreate(GlobalContext* ctxt, TitleCardContext* titleCtxt, u32 texture, s16 param_4, s16 param_5, u8 param_6, u8 param_7) {
    titleCtxt->texture = texture;
    titleCtxt->unk4 = param_4;
    titleCtxt->unk6 = param_5;
    titleCtxt->unk8 = param_6;
    titleCtxt->unk9 = param_7;
    titleCtxt->fadeOutDelay = 80;
    titleCtxt->fadeInDelay = 0;
}

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_Nop800B5E50.asm")

void Actor_TitleCardUpdate(GlobalContext* ctxt, TitleCardContext* titleCtxt) {
    if (DECR(titleCtxt->fadeInDelay) == 0) {
        if (DECR(titleCtxt->fadeOutDelay) == 0) {
            Lib_StepTowardsCheck_s(&titleCtxt->alpha, 0, 30);
            Lib_StepTowardsCheck_s(&titleCtxt->color, 0, 70);
        } else {
            Lib_StepTowardsCheck_s(&titleCtxt->alpha, 255, 10);
            Lib_StepTowardsCheck_s(&titleCtxt->color, 255, 20);
        }
    }
}

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_TitleCardDraw.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B6434.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B6468.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B6474.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B648C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B64FC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B6584.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B6608.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B6680.asm")

void Actor_MarkForDeath(Actor* actor) {
    actor->draw = NULL;
    actor->update = NULL;
    actor->flags &= ~0x1;
}

void Actor_InitCurrPosition(Actor* actor) {
    actor->posRot = actor->initPosRot;
}

void Actor_SetHeight(Actor* actor, f32 height) {
    actor->topPosRot.pos.x = actor->posRot.pos.x;
    actor->topPosRot.pos.y = actor->posRot.pos.y + height;
    actor->topPosRot.pos.z = actor->posRot.pos.z;
    actor->topPosRot.rot.x = actor->posRot.rot.x;
    actor->topPosRot.rot.y = actor->posRot.rot.y;
    actor->topPosRot.rot.z = actor->posRot.rot.z;
}

void Actor_SetRotationFromDrawRotation(Actor* actor) {
    actor->posRot.rot = actor->shape.rot;
}

void Actor_InitDrawRotation(Actor* actor) {
    actor->shape.rot = actor->posRot.rot;
}

void Actor_SetScale(Actor* actor, f32 scale) {
    actor->scale.z = scale;
    actor->scale.y = scale;
    actor->scale.x = scale;
}

void Actor_SetObjectSegment(GlobalContext* ctxt, Actor* actor) {
    // TODO: Segment number enum
    gRspSegmentPhysAddrs[6] = PHYSICAL_TO_VIRTUAL(ctxt->sceneContext.objects[actor->objBankIndex].vramAddr);
}

#ifdef NON_MATCHING
void Actor_InitToDefaultValues(Actor* actor, GlobalContext* ctxt) {
    Actor_InitCurrPosition(actor);
    Actor_InitDrawRotation(actor);
    Actor_SetHeight(actor, 0);
    Math_Vec3f_Copy(&actor->lastPos, &actor->posRot.pos);
    Actor_SetScale(actor, 0.01);
    actor->unk1F = 3;
    actor->minYVelocity = -20.0f;

    actor->meshAttachedTo = 0x32;

    actor->sqrdDistToLink = D_801DCA54;
    func_800E7494(&actor->unkA0);
    actor->unkFC = 1000.0f;
    actor->unk100 = 350.0f;
    actor->unk104 = 700.0f;

    actor->naviMsgId = 255;

    Actor_Setshape(&actor->shape, 0, 0, 0);
    if (Scene_IsObjectLoaded(&ctxt->sceneContext, actor->objBankIndex) != 0) {
        Actor_SetObjectSegment(ctxt, actor);
        actor->init(actor, ctxt);
        actor->init = NULL;
    }
}
#else
GLOBAL_ASM("asm/non_matchings/z_actor//Actor_InitToDefaultValues.asm")
#endif

void Actor_FiniActor(Actor* actor, GlobalContext* ctxt) {
    if (actor->init == NULL) {
        if (actor->destroy != NULL) {
            actor->destroy(actor, ctxt);
            actor->destroy = NULL;
        }
    }
}

void Actor_SetMovementScale(s32 scale) {
    actorMovementScale = scale * 0.5f;
}

#ifdef NON_MATCHING
void Actor_ApplyMovement(Actor* actor) {
    actor->posRot.pos.x += ((actor->velocity.x * actorMovementScale) + actor->unkA0.displacement.x);
    actor->posRot.pos.y += ((actor->velocity.y * actorMovementScale) + actor->unkA0.displacement.y);
    actor->posRot.pos.z += ((actor->velocity.z * actorMovementScale) + actor->unkA0.displacement.z);
}
#else
GLOBAL_ASM("asm/non_matchings/z_actor//Actor_ApplyMovement.asm")
#endif

#ifdef NON_MATCHING
void Actor_SetVelocityYRotationAndGravity(Actor* actor) {
    actor->velocity.x = actor->speedXZ * Math_Sins(actor->posRot.rot.x);
    actor->velocity.y = actor->velocity.y + actor->gravity;
    actor->velocity.z = actor->speedXZ * Math_Coss(actor->posRot.rot.x);

    if (actor->velocity.y < actor->minYVelocity) {
        actor->velocity.y = actor->minYVelocity;
    }
}
#else
GLOBAL_ASM("asm/non_matchings/z_actor//Actor_SetVelocityYRotationAndGravity.asm")
#endif

void Actor_SetVelocityAndMoveYRotationAndGravity(Actor* actor) {
    Actor_SetVelocityYRotationAndGravity(actor);
    Actor_ApplyMovement(actor);
}

void Actor_SetVelocityXYRotation(Actor* actor) {
    f32 velX =  Math_Coss(actor->posRot.rot.x) * actor->speedXZ;
    actor->velocity.x = Math_Sins(actor->posRot.rot.y) * velX;
    actor->velocity.y = Math_Sins(actor->posRot.rot.x) * actor->speedXZ;
    actor->velocity.z = Math_Coss(actor->posRot.rot.y) * velX;
}

void Actor_SetVelocityAndMoveXYRotation(Actor* actor) {
    Actor_SetVelocityXYRotation(actor);
    Actor_ApplyMovement(actor);
}

void Actor_SetVelocityXYRotationReverse(Actor* actor) {
    f32 velX =  Math_Coss(-actor->posRot.rot.x) * actor->speedXZ;
    actor->velocity.x = Math_Sins(actor->posRot.rot.y) * velX;
    actor->velocity.y = Math_Sins(-actor->posRot.rot.x) * actor->speedXZ;
    actor->velocity.z = Math_Coss(actor->posRot.rot.y) * velX;
}

void Actor_SetVelocityAndMoveXYRotationReverse(Actor* actor) {
    Actor_SetVelocityXYRotationReverse(actor);
    Actor_ApplyMovement(actor);
}

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B6C04.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B6C58.asm")

s16 Actor_YawBetweenActors(Actor* from, Actor* to) {
    return Math_Vec3f_Yaw(&from->posRot.pos, &to->posRot.pos);
}

s16 Actor_YawBetweenActorsTop(Actor* from, Actor* to) {
    return Math_Vec3f_Yaw(&from->topPosRot.pos, &to->topPosRot.pos);
}

s16 Actor_YawToPoint(Actor* actor, Vec3f* point) {
    return Math_Vec3f_Yaw(&actor->posRot.pos, point);
}

s16 Actor_PitchBetweenActors(Actor* from, Actor* to) {
    return Math_Vec3f_Pitch(&from->posRot.pos, &to->posRot.pos);
}

s16 Actor_PitchBetweenActorsTop(Actor* from, Actor* to) {
    return Math_Vec3f_Pitch(&from->topPosRot.pos, &to->topPosRot.pos);
}

s16 Actor_PitchToPoint(Actor* actor, Vec3f* point) {
    return Math_Vec3f_Pitch(&actor->posRot.pos, point);
}

f32 Actor_DistanceBetweenActors(Actor* actor1, Actor* actor2) {
    return Math_Vec3f_DistXYZ(&actor1->posRot.pos, &actor2->posRot.pos);
}

f32 Actor_DistanceToPoint(Actor* actor, Vec3f* point) {
    return Math_Vec3f_DistXYZ(&actor->posRot.pos, point);
}

f32 Actor_XZDistanceBetweenActors(Actor* actor1, Actor* actor2) {
    return Math_Vec3f_DistXZ(&actor1->posRot.pos, &actor2->posRot.pos);
}

f32 Actor_XZDistanceToPoint(Actor* actor, Vec3f* point) {
    return Math_Vec3f_DistXZ(&actor->posRot.pos, point);
}

void Actor_CalcOffsetOrientedToDrawRotation(Actor* actor, Vec3f* offset, Vec3f* point) {
    f32 cos_rot_y;
    f32 sin_rot_y;
    f32 imm_x;
    f32 imm_z;

    cos_rot_y = Math_Coss(actor->shape.rot.y);
    sin_rot_y = Math_Sins(actor->shape.rot.y);
    imm_x = point->x - actor->posRot.pos.x;
    imm_z = point->z - actor->posRot.pos.z;
    offset->x = ((imm_x * cos_rot_y) - (imm_z * sin_rot_y));
    offset->z = ((imm_z * cos_rot_y) + (imm_x * sin_rot_y));
    offset->y = point->y - actor->posRot.pos.y;
}

f32 Actor_YDistance(Actor* actor1, Actor* actor2) {
    return actor2->posRot.pos.y - actor1->posRot.pos.y;
}

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B6F20.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B6FC8.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B7090.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B7118.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B7128.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B715C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B7170.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B71DC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B7200.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B722C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B724C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B7298.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B72E0.asm")

void func_800B72F8(DynaPolyActor* dpactor, f32 a1, s16 a2) {
    dpactor->unk150 = a2;
    dpactor->unk148 += a1;
}

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_IsLinkFacingActor.asm")

s32 Actor_IsActorFacedByActor(Actor* actor, Actor* other, s16 tolerance) {
    s16 angle;
    s16 dist;

    angle = Actor_YawBetweenActors(actor, other) + 0x8000;
    dist = angle - other->shape.rot.y;
    if (ABS2(dist) < tolerance) {
        return 1;
    }
    return 0;
}

s32 Actor_IsActorFacingLink(Actor* actor, s16 angle) {
    s16 dist;

    dist = actor->rotTowardsLinkY - actor->shape.rot.y;
    if (ABS2(dist) < angle) {
        return 1;
    }
    return 0;
}

s32 Actor_IsActorFacingActor(Actor* actor, Actor* other, s16 tolerance) {
    s16 dist;

    dist = Actor_YawBetweenActors(actor, other) - actor->shape.rot.y;
    if (ABS2(dist) < tolerance) {
        return 1;
    }
    return 0;
}

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_IsActorFacingLinkAndWithinRange.asm")

s32 Actor_IsActorFacingActorAndWithinRange(Actor* actor, Actor* other, f32 range, s16 tolerance) {
    s16 dist;

    if (Actor_DistanceBetweenActors(actor, other) < range) {
        dist = Actor_YawBetweenActors(actor, other) - actor->shape.rot.y;
        if (ABS2(dist) < tolerance) {
            return 1;
        }
    }
    return 0;
}

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B75A0.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B761C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B7678.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B78B8.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B7E04.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B7FE0.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8018.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8050.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8118.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B81E0.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8214.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8248.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B82EC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B83BC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B83F8.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B84D0.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8500.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B85E0.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8614.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B863C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B867C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B86C8.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8708.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8718.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B874C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8804.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B882C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B886C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8898.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8934.asm")

u32 Actor_HasParent(Actor* actor, GlobalContext* ctxt) {
    if (actor->parent != NULL) {
        return 1;
    } else {
        return 0;
    }
}

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8A1C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8B84.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8BB0.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8BD0.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8BFC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8C20.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8C50.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8C78.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8C9C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8CEC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8D10.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8D50.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8D98.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8DD4.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8E1C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8E58.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8EC8.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8EF4.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8F98.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8FC0.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B8FE8.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B9010.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B9038.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B9084.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B9098.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B90AC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B90F4.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B9120.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_Init.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B9334.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_UpdateActor.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_UpdateAll.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_DrawActor.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B9D1C.asm")

void Actor_DrawAllSetup(GlobalContext* ctxt) {
    ctxt->actorCtx.undrawnActorCount = 0;
    ctxt->actorCtx.unkB = 0;
}

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_RecordUndrawnActor.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B9E84.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800B9EF4.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BA2D8.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BA2FC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_DrawAll.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BA6FC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BA798.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BA8B8.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BA9B4.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_InsertIntoTypeList.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_RemoveFromTypeList.asm")

void Actor_FreeOverlay(ActorOverlay* entry) {
    void* ramAddr;

    if (entry->nbLoaded == 0) {
        ramAddr = entry->loadedRamAddr;
        if (ramAddr != NULL) {
            //Bit 1 - always loaded
            if ((entry->allocType & 2) == 0) {
                //Bit 0 - don't alloc memory
                if ((entry->allocType & 1) != 0) {
                    entry->loadedRamAddr = NULL;
                } else {
                    zelda_free(ramAddr);
                    entry->loadedRamAddr = NULL;
                }
            }
        }
    }
}

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_Spawn.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_LoadOverlay.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_SpawnWithParentAndCutscene.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_SpawnWithParent.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//Actor_SpawnTransitionActors.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BB2D0.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BB498.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BB59C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BB604.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BB8EC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BBA88.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BBAC0.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BBB74.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BBC20.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BBCEC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BBDAC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BBFB0.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BC154.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BC188.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BC1B4.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BC270.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BC444.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BC4EC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BC5B8.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BC5EC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BC620.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BC770.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BC7D8.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BC848.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BC8B8.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BCB50.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BCB70.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BCBF4.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BCC68.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BCCDC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BD2B4.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BD384.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BD6B8.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BD6E4.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BD888.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BD9A0.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BD9E0.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BDAA0.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BDB6C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BDC5C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BDCF4.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BDFB0.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BDFC0.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BE03C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BE0B8.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BE184.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BE22C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BE258.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BE2B8.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BE33C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BE3D0.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BE504.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BE568.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BE5CC.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BE63C.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BE680.asm")

GLOBAL_ASM("asm/non_matchings/z_actor//func_800BF7CC.asm")
