#include <ultra64.h>
#include <global.h>

extern Gfx D_04076BC0[];
extern Gfx D_04075A40[];
extern Gfx D_04077480[];
extern Gfx D_04075B30[];
extern Gfx D_0407AE00[];
extern Gfx D_0401F0F0[];


void Actor_PrintLists(ActorContext *actCtxt) {
    s32 i;
    ActorListEntry* actorList;

    FaultDrawer_SetCharPad(-2, 0);
    FaultDrawer_Printf("actor\n", gMaxActorId);
    FaultDrawer_Printf("No. Actor Name Part SegName\n");

    for (i = 0, actorList = &actCtxt->actorList[i]; i < 12; i++, actorList++) {
        Actor* actor = actorList->first;

        while (actor != NULL) {
            FaultDrawer_Printf("%3d %08x %04x %3d %s\n", i, actor, actor->id, actor->type, "");
            actor = actor->next;
        }
    }
}

void ActorShape_Init(ActorShape* shape, f32 yDisplacement, actor_shadow_draw_func func, f32 scale) {
    shape->yDisplacement = yDisplacement;
    shape->shadowDrawFunc = func;
    shape->scale = scale;
    shape->alphaScale = 255;
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

// ActorShadow_DrawFunc_Circle?
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
void func_800B4088(Actor *actor, Lights* lights, GlobalContext *globalCtx) {
    static ColorRGBA8 D_801AEC80 = { 255, 255, 255, 255 };

    Actor_PostDraw(actor, lights, globalCtx, D_04076BC0, &D_801AEC80);
}

// ActorShadow_DrawFunc_Squiggly?
void func_800B40B8(Actor *actor, Lights* lights, GlobalContext *globalCtx) {
    Actor_PostDraw(actor, lights, globalCtx, D_04077480, NULL);
}

void func_800B40E0(GlobalContext* globalCtx, Light* light, MtxF* arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    s32 pad;
    s16 sp58;
    f32 temp1;
    f32 temp2;

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

void ActorShadow_DrawFunc_Teardrop(Player* player, Lights* lights, GlobalContext* globalCtx) {
    f32 phi_f2;
    f32 oldScale;
    u8 temp_14;
    s32 pad[1];
    f32 temp_f26;
    

    MtxF sp13C;
    MtxF spFC;
    CollisionPoly* spF8;
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

    temp_f26 = player->actor.posRot.pos.y - player->actor.groundY;
    
    if (temp_f26 > 0.0f) {
        temp_10 = player->actor.shape.scale;
        temp_14 = player->actor.shape.alphaScale;
        if ((player->actor.id == ACTOR_PLAYER) && (player->unkA74 & 0x8000)) {
            oldScale = player->actor.scale.z;
            if (1){};
            player->actor.scale.z += 0.03f * fabsf(Math_Coss(player->unkAAA));
            player->actor.shape.scale *= 0.2f;
            player->actor.shape.alphaScale = player->actor.shape.alphaScale * CLAMP_MAX(temp_f26 * 0.03f, 1.0f);
            Actor_PostDraw(&player->actor, lights, globalCtx, D_04076BC0, NULL);
            player->actor.scale.z = oldScale;
            player->actor.shape.scale = temp_10;
        } else {
            player->actor.shape.scale *= 0.3f;
            player->actor.shape.alphaScale = player->actor.shape.alphaScale * CLAMP_MAX((temp_f26 - 20.0f) * 0.02f, 1.0f);
            func_800B3FC0(&player->actor, lights, globalCtx);
            player->actor.shape.scale = temp_10;
        }

        player->actor.shape.alphaScale = temp_14;
    }

    if (temp_f26 < 200.0f) {
        temp_s6 = lights->numLights - 2;
        phi_s7 = &player->actor.unk_D4[0];
        spBC = &spEC[0];

        OPEN_DISPS(globalCtx->state.gfxCtx);

        oGfxCtx->polyOpa.p = Gfx_CallSetupDL(oGfxCtx->polyOpa.p, 0x2C);
        player->actor.shape.unk_15 = 0;
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
                    player->actor.shape.unk_15 |= spB8;
                    if ((player->actor.waterY < 0.0f) && (spF4 == 0x32) && (player->actor.shape.unk_17 & spB8)) {
                        if (func_800C9C24(&globalCtx->colCtx, spF8, spF4, 1) != 0) {
                            Matrix_Copy(&sp13C, &spFC);
                            Matrix_YRotation(&spFC, player->actor.shape.rot.y);
                            EffFootmark_Add(globalCtx, &spFC, &player->actor, i, phi_s7, player->actor.shape.scale * 0.3f, IREG(88) + 0x50, IREG(89) + 0x3C, IREG(90) + 0x28, 0x7530, 0xC8, 0x3C);
                        }
                        player->actor.shape.unk_17 &= ~spB8;
                    }
                }

                if (30.0f < temp_f26) {
                    temp_f26 = 30.0f;
                }

                temp_f24 = player->actor.shape.alphaScale * (1.0f - (temp_f26 * (1.0f / 30)));

                temp_f26_2 = 1.0f - (temp_f26 * (1.0f / 70));
                temp_f22_2 = (player->actor.shape.scale * temp_f26_2) * player->actor.scale.x;

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

        if (!(player->actor.bgCheckFlags & 1)) {
            player->actor.shape.unk_15 = 0;
        } else if (player->actor.shape.unk_15 == 3) {
            temp_f0 = player->actor.unk_D4[0].y - player->actor.unk_D4[1].y;

            if ((spEC[0] + temp_f0) < (spEC[1] - temp_f0)) {
                player->actor.shape.unk_15 = 2;
            } else {
                player->actor.shape.unk_15 = 1;
            }
        }

        CLOSE_DISPS(globalCtx->state.gfxCtx);
    }
}

void func_800B4A98(Actor* actor, s32 arg1, s32 arg2, Vec3f* arg3, s32 arg4, Vec3f* arg5) {
    if (arg1 == arg2) {
        SysMatrix_MultiplyVector3fByState(arg3, &actor->unk_D4[0]);
    } else if (arg1 == arg4) {
        SysMatrix_MultiplyVector3fByState(arg5, &actor->unk_D4[1]);
    }
}

void func_800B4AEC(GlobalContext *globalCtx, Actor *actor, f32 param_3) {
    s32 sp34;
    f32 backupY = actor->posRot.pos.y;

    actor->posRot.pos.y += param_3;
    actor->groundY = func_800C4188(globalCtx, &globalCtx->colCtx, &actor->floorPoly, &sp34, actor, &actor->posRot);
    actor->floorPolySource = sp34;
    actor->posRot.pos.y = backupY;
}

void func_800B4B50(Actor *actor, Lights *lights, GlobalContext *globalCtx) {
    if (actor->bgCheckFlags & 0x400) {
        func_800B4AEC(globalCtx, actor, 50.0f);
    }

    if (actor->floorPoly != NULL) {
        f32 temp_f2 = actor->posRot.pos.y - actor->groundY;

        if (temp_f2 > 20.0f) {
            u8 temp_alpha = actor->shape.alphaScale;
            f32 temp_f20 = actor->shape.scale;

            actor->shape.scale *= 0.3f;
            actor->shape.alphaScale = actor->shape.alphaScale * CLAMP_MAX((temp_f2 - 20.0f) * 0.02f, 1.0f);
            func_800B3FC0(actor, lights, globalCtx);
            actor->shape.scale = temp_f20;
            actor->shape.alphaScale = temp_alpha;
        } else if (temp_f2 >= -1.0f) {
            s32 temp_s5 = lights->numLights - 2;
            Light* phi_s0;
            s32 phi_s1;
            s32 phi_s2;
            MtxF sp94;
            f32 temp_f24;
            f32 temp_f26_2;
            f32 temp_f22_2;
            s32 temp_a3;
            s32 pad[1];

            OPEN_DISPS(globalCtx->state.gfxCtx);

            oGfxCtx->polyOpa.p = Gfx_CallSetupDL(oGfxCtx->polyOpa.p, 0x2C);
            func_800C0094(actor->floorPoly, actor->posRot.pos.x, actor->groundY, actor->posRot.pos.z, &sp94);
            
            temp_f24 = actor->shape.alphaScale * (1.0f - (temp_f2 * (1.0f / 30)));
            temp_f26_2 = 1.0f - (temp_f2 * (1.0f / 70));
            temp_f22_2 = (actor->shape.scale * temp_f26_2) * actor->scale.x;

            phi_s2 = 0;
            phi_s0 = &lights->l.l[0];

            for (phi_s1 = 0; phi_s1 < temp_s5; phi_s1++) {
                if (phi_s0->l.dir[1] > 0) {
                    temp_a3 = (phi_s0->l.col[0] + phi_s0->l.col[1] + phi_s0->l.col[2]) * ABS2(phi_s0->l.dir[1]);
                    if (temp_a3 > 0) {
                        phi_s2 += temp_a3;
                        func_800B40E0(globalCtx, phi_s0, &sp94, temp_a3, temp_f24, temp_f22_2, temp_f26_2);
                    }
                }
                phi_s0++;
            }

            for (phi_s1 = 0; phi_s1 < 2; phi_s1++) {
                if (phi_s0->l.dir[1] > 0) {
                    temp_a3 = (ABS2(phi_s0->l.dir[1]) * (phi_s0->l.col[0] + phi_s0->l.col[1] + phi_s0->l.col[2])) -
                              (0, (phi_s2 * 8));
                    if (temp_a3 > 0) {
                        func_800B40E0(globalCtx, phi_s0, &sp94, temp_a3, temp_f24, temp_f22_2, temp_f26_2);
                    }
                }
                phi_s0++;
            }

            CLOSE_DISPS(globalCtx->state.gfxCtx);
        }
    }
}

void func_800B4EDC(GlobalContext* globalCtx, Vec3f* arg1, Vec3f* arg2, f32* arg3) {
    Matrix_MultiplyByVectorXYZW(&globalCtx->mf_187B0, arg1, arg2, arg3);
    *arg3 = (*arg3 < 1.0f) ? 1.0f : (1.0f / *arg3);
}

void func_800B4F40(TargetContext *targetCtx, s32 index, f32 x, f32 y, f32 z) {
    targetCtx->arr_50[index].pos.x = x;
    targetCtx->arr_50[index].pos.y = y;
    targetCtx->arr_50[index].pos.z = z;
    targetCtx->arr_50[index].unk_0C = targetCtx->unk_44;
}

typedef struct {
    /* 0x00 */ ColorRGBA8 inner;
    /* 0x04 */ ColorRGBA8 outer;
} NaviColor; // size = 0x8

static NaviColor sNaviColorList[] = {
    { { 0, 255, 0, 255 }, { 0, 255, 0, 0 } },         { { 0, 255, 0, 255 }, { 0, 255, 0, 0 } },
    { { 255, 255, 255, 255 }, { 0, 0, 255, 0 } },     { { 0, 255, 0, 255 }, { 0, 255, 0, 0 } },
    { { 150, 150, 255, 255 }, { 150, 150, 255, 0 } }, { { 255, 255, 0, 255 }, { 200, 155, 0, 0 } },
    { { 0, 255, 0, 255 }, { 0, 255, 0, 0 } },         { { 0, 255, 0, 255 }, { 0, 255, 0, 0 } },
    { { 0, 255, 0, 255 }, { 0, 255, 0, 0 } },         { { 255, 255, 0, 255 }, { 200, 155, 0, 0 } },
    { { 0, 255, 0, 255 }, { 0, 255, 0, 0 } },         { { 0, 255, 0, 255 }, { 0, 255, 0, 0 } },
    { { 0, 255, 0, 255 }, { 0, 255, 0, 0 } },
};

void func_800B4F78(TargetContext* targetCtx, s32 actorType, GlobalContext* globalCtx) {
    TargetContextEntry* entry;
    NaviColor* naviColor;
    s32 i;

    Math_Vec3f_Copy(&targetCtx->targetCenterPos, &globalCtx->view.eye);
    targetCtx->unk_44 = 500.0f;
    targetCtx->unk_48 = 0x100;

    naviColor = &sNaviColorList[actorType];

    entry = &targetCtx->arr_50[0];
    for (i = 0; i < ARRAY_COUNT(targetCtx->arr_50); i++) {
        func_800B4F40(targetCtx, i, 0.0f, 0.0f, 0.0f);
        entry->color.red = naviColor->inner.red;
        entry->color.green = naviColor->inner.green;
        entry->color.blue = naviColor->inner.blue;
        entry++;
    }
}

void func_800B5040(TargetContext* targetCtx, Actor* actor, s32 actorType, GlobalContext* globalCtx) {
    NaviColor* naviColor = &sNaviColorList[actorType];
    
    targetCtx->naviRefPos.x = actor->topPosRot.pos.x;
    targetCtx->naviRefPos.y = actor->topPosRot.pos.y + (actor->unk54 * actor->scale.y);
    targetCtx->naviRefPos.z = actor->topPosRot.pos.z;
    targetCtx->naviInner.red = naviColor->inner.red;
    targetCtx->naviInner.green = naviColor->inner.green;
    targetCtx->naviInner.blue = naviColor->inner.blue;
    targetCtx->naviInner.alpha = naviColor->inner.alpha;
    targetCtx->naviOuter.red = naviColor->outer.red;
    targetCtx->naviOuter.green = naviColor->outer.green;
    targetCtx->naviOuter.blue = naviColor->outer.blue;
    targetCtx->naviOuter.alpha = naviColor->outer.alpha;
}

void Actor_TargetContextInit(TargetContext* targetCtx, Actor* actor, GlobalContext* globalCtx) {
    targetCtx->unk_90 = NULL;
    targetCtx->unk_8C = NULL;
    targetCtx->targetedActor = NULL;
    targetCtx->arrowPointedActor = NULL;
    targetCtx->unk_4B = 0;
    targetCtx->unk_4C = 0;
    targetCtx->unk_40 = 0;
    func_800B5040(targetCtx, actor, actor->type, globalCtx);
    func_800B4F78(targetCtx, actor->type, globalCtx);
}

void func_800B5208(TargetContext* targetCtx, GlobalContext* globalCtx) {
    Player* player = PLAYER;
    Actor* actor;

    if (player->stateFlags1 & 0x300006C2) {
        return;
    }

    actor = targetCtx->targetedActor;

    OPEN_DISPS(globalCtx->state.gfxCtx);

    if (targetCtx->unk_48 != 0) {
        s32 i;
        s16 spCE;
        f32 var1;
        Vec3f spBC;
        s32 spB8;
        f32 spB4;
        s32 spB0;
        s32 spAC;
        f32 var2;
        
        spCE = 0xFF;
        var1 = 1.0f;

        if (targetCtx->unk_4B != 0) {
            spB8 = 1;
        } else {
            spB8 = 3;
        }

        if (actor != NULL) {
            Math_Vec3f_Copy(&targetCtx->targetCenterPos, &actor->topPosRot.pos);
            var1 = (500.0f - targetCtx->unk_44) / 420.0f;
        } else {
            targetCtx->unk_48 -= 120;
            if (targetCtx->unk_48 < 0) {
                targetCtx->unk_48 = 0;
            }
            spCE = targetCtx->unk_48;
        }

        func_800B4EDC(globalCtx, &targetCtx->targetCenterPos, &spBC, &spB4);

        spBC.x = (160 * (spBC.x * spB4)) * var1;
        spBC.x = CLAMP(spBC.x, -320.0f, 320.0f);

        spBC.y = (120 * (spBC.y * spB4)) * var1;
        spBC.y = CLAMP(spBC.y, -240.0f, 240.0f);

        spBC.z = spBC.z * var1;

        targetCtx->unk_4C--;
        if (targetCtx->unk_4C < 0) {
            targetCtx->unk_4C = 2;
        }

        func_800B4F40(targetCtx, targetCtx->unk_4C, spBC.x, spBC.y, spBC.z);

        if ((!(player->stateFlags1 & 0x40)) || (actor != player->unk730)) {
            TargetContextEntry* entry;

            oGfxCtx->overlay.p = Gfx_CallSetupDL(oGfxCtx->overlay.p, 0x39);

            for (spB0 = 0, spAC = targetCtx->unk_4C; spB0 < spB8; spB0++, spAC = (spAC + 1) % 3) {
                entry = &targetCtx->arr_50[spAC];

                if (entry->unk_0C < 500.0f) {
                    if (entry->unk_0C <= 120.0f) {
                        var2 = 0.15f;
                    } else {
                        var2 = ((entry->unk_0C - 120.0f) * 0.001f) + 0.15f;
                    }

                    SysMatrix_InsertTranslation(entry->pos.x, entry->pos.y, 0.0f, MTXMODE_NEW);
                    SysMatrix_InsertScale(var2, 0.15f, 1.0f, MTXMODE_APPLY);

                    gDPSetPrimColor(oGfxCtx->overlay.p++, 0, 0, entry->color.red, entry->color.green, entry->color.blue,
                                    (u8)spCE);

                    SysMatrix_InsertZRotation_s(targetCtx->unk_4B * 512, MTXMODE_APPLY);

                    for (i = 0; i < 4; i++) {
                        SysMatrix_InsertZRotation_s(0x4000, MTXMODE_APPLY);
                        SysMatrix_StatePush();
                        SysMatrix_InsertTranslation(entry->unk_0C, entry->unk_0C, 0.0f, MTXMODE_APPLY);
                        gSPMatrix(oGfxCtx->overlay.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx),
                                  G_MTX_MODELVIEW | G_MTX_LOAD);
                        gSPDisplayList(oGfxCtx->overlay.p++, D_0407AE00);
                        SysMatrix_StatePop();
                    }
                }

                spCE -= 0xFF / 3;
                if (spCE < 0) {
                    spCE = 0;
                }
            }
        }
    }

    actor = targetCtx->unk_94;
    if ((actor != NULL) && !(actor->flags & 0x8000000)) {
        NaviColor* naviColor = &sNaviColorList[actor->type];

        oGfxCtx->polyXlu.p = Gfx_CallSetupDL(oGfxCtx->polyXlu.p, 0x7);

        SysMatrix_InsertTranslation(actor->topPosRot.pos.x, actor->topPosRot.pos.y + (actor->unk54 * actor->scale.y) + 17.0f,
                         actor->topPosRot.pos.z, MTXMODE_NEW);
        SysMatrix_InsertYRotation_s(globalCtx->gameplayFrames * 3000, MTXMODE_APPLY);
        SysMatrix_InsertScale((iREG(27) + 35) / 1000.0f, (iREG(28) + 60) / 1000.0f, (iREG(29) + 50) / 1000.0f, MTXMODE_APPLY);

        gDPSetPrimColor(oGfxCtx->polyXlu.p++, 0, 0, naviColor->inner.red, naviColor->inner.green, naviColor->inner.blue, 255);
        gSPMatrix(oGfxCtx->polyXlu.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx),
                  G_MTX_MODELVIEW | G_MTX_LOAD);
        gSPDisplayList(oGfxCtx->polyXlu.p++, D_0401F0F0);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx);
}

void func_800B5814(TargetContext* targetCtx, Player* player, Actor* actorArg, GlobalContext* globalCtx) {
    s32 pad;
    Actor* unkActor;
    s32 actorType;
    Vec3f sp50;
    f32 sp4C;
    

    unkActor = NULL;

    if ((player->unk730 != NULL) && (player->unkAE3[player->unkADE] == 2)) {
        targetCtx->unk_94 = NULL;
    } else {
        func_800BB8EC(globalCtx, &globalCtx->actorCtx, &unkActor, &D_801ED920, player);
        targetCtx->unk_94 = unkActor;
    }

    if (targetCtx->unk_8C != NULL) {
        unkActor = targetCtx->unk_8C;
        targetCtx->unk_8C = NULL;
    } else if (actorArg != NULL) {
        unkActor = actorArg;
    }

    if (unkActor != NULL) {
        actorType = unkActor->type;
    } else {
        actorType = player->actor.type;
    }

    if ((unkActor != targetCtx->arrowPointedActor) || (actorType != targetCtx->activeType)) {
        targetCtx->arrowPointedActor = unkActor;
        targetCtx->activeType = actorType;
        targetCtx->unk_40 = 1.0f;
    }

    if (unkActor == NULL) {
        unkActor = &player->actor;
    }

    if (Lib_StepTowardsCheck_f(&targetCtx->unk_40, 0.0f, 0.25f) == 0) {
        f32 temp1 = 0.25f / targetCtx->unk_40;
        f32 temp2 = unkActor->topPosRot.pos.x - targetCtx->naviRefPos.x;
        f32 temp3 = (unkActor->topPosRot.pos.y + (unkActor->unk54 * unkActor->scale.y)) - targetCtx->naviRefPos.y;
        f32 temp4 = unkActor->topPosRot.pos.z - targetCtx->naviRefPos.z;
        targetCtx->naviRefPos.x += temp2 * temp1;
        targetCtx->naviRefPos.y += temp3 * temp1;
        targetCtx->naviRefPos.z += temp4 * temp1;
    } else {
        func_800B5040(targetCtx, unkActor, actorType, globalCtx);
    }

    if ((actorArg != NULL) && (targetCtx->unk_4B == 0)) {
        func_800B4EDC(globalCtx, &actorArg->topPosRot.pos, &sp50, &sp4C);
        if (((sp50.z <= 0.0f) || (1.0f <= fabsf(sp50.x * sp4C))) || (1.0f <= fabsf(sp50.y * sp4C))) {
            actorArg = NULL;
        }
    }

    if (actorArg != NULL) {
        if (actorArg != targetCtx->targetedActor) {
            s32 lockOnSfxId;

            func_800B4F78(targetCtx, actorArg->type, globalCtx);
            targetCtx->targetedActor = actorArg;

            if (actorArg->id == ACTOR_EN_BOOM) {
                targetCtx->unk_48 = 0;
            }

            lockOnSfxId = ((actorArg->flags & 5) == 5) ? 0x4830 : 0x4810;
            play_sound(lockOnSfxId);
        }

        targetCtx->targetCenterPos.x = actorArg->posRot.pos.x;
        targetCtx->targetCenterPos.y = actorArg->posRot.pos.y - (actorArg->shape.yDisplacement * actorArg->scale.y);
        targetCtx->targetCenterPos.z = actorArg->posRot.pos.z;

        if (targetCtx->unk_4B == 0) {
            f32 temp5 = (500.0f - targetCtx->unk_44) * 3.0f;
            f32 temp6 = (temp5 < 30.0f) ? 30.0f : ((100.0f < temp5) ? 100.0f : temp5);

            if (Lib_StepTowardsCheck_f(&targetCtx->unk_44, 80.0f, temp6) != 0) {
                targetCtx->unk_4B++;
            }
        } else {
            targetCtx->unk_4B = (targetCtx->unk_4B + 3) | 0x80;
            targetCtx->unk_44 = 120.0f;
        }
    } else {
        targetCtx->targetedActor = NULL;
        Lib_StepTowardsCheck_f(&targetCtx->unk_44, 500.0f, 80.0f);
    }
}

/**
 * Tests if current scene switch flag is set.
 */
s32 Flags_GetSwitch(GlobalContext* globalCtx, s32 flag) {
    if (flag >= 0 && flag < 0x80) {
        return globalCtx->actorCtx.switchFlags[(flag & -0x20) >> 5] & (1 << (flag & 0x1F));
    }
    return 0;
}

/**
 * Sets current scene switch flag.
 */
void Flags_SetSwitch(GlobalContext* globalCtx, s32 flag){
    if (flag >= 0 && flag < 0x80) {
        globalCtx->actorCtx.switchFlags[(flag & -0x20) >> 5] |= 1 << (flag & 0x1F);
    }
}

/**
 * Unsets current scene switch flag.
 */
void Flags_UnsetSwitch(GlobalContext* globalCtx, s32 flag) {
    if (flag >= 0 && flag < 0x80) {
        globalCtx->actorCtx.switchFlags[(flag & -0x20) >> 5] &= ~(1 << (flag & 0x1F));
    }
}

/**
 * Tests if current scene chest flag is set.
 */
s32 Actor_GetChestFlag(GlobalContext* globalCtx, u32 flag) {
    return globalCtx->actorCtx.chestFlags & (1 << flag);
}

/**
 * Sets current scene chest flag.
 */
void Actor_SetChestFlag(GlobalContext* globalCtx, u32 flag) {
    globalCtx->actorCtx.chestFlags |= (1 << flag);
}

/**
 * Sets current scene all chests flag.
 */
void Actor_SetAllChestFlag(GlobalContext* globalCtx, u32 flag) {
    globalCtx->actorCtx.chestFlags = flag;
}

/**
 * Tests current scene all chests flag.
 */
s32 Actor_GetAllChestFlag(GlobalContext* globalCtx) {
    return globalCtx->actorCtx.chestFlags;
}

/**
 * Tests if current scene clear flag is set.
 */
s32 Actor_GetRoomCleared(GlobalContext* globalCtx, u32 roomNumber) {
    return globalCtx->actorCtx.clearedRooms & (1 << roomNumber);
}

/**
 * Sets current scene clear flag.
 */
void Actor_SetRoomCleared(GlobalContext* globalCtx, u32 roomNumber) {
    globalCtx->actorCtx.clearedRooms |= (1 << roomNumber);
}

/**
 * Unsets current scene clear flag.
 */
void Actor_UnsetRoomCleared(GlobalContext* globalCtx, u32 roomNumber) {
    globalCtx->actorCtx.clearedRooms &= ~(1 << roomNumber);
}

/**
 * Tests if current scene temp clear flag is set.
 */
s32 Actor_GetRoomClearedTemp(GlobalContext* globalCtx, u32 roomNumber) {
    return globalCtx->actorCtx.clearedRoomsTemp & (1 << roomNumber);
}

/**
 * Sets current scene temp clear flag.
 */
void Actor_SetRoomClearedTemp(GlobalContext* globalCtx, u32 roomNumber) {
    globalCtx->actorCtx.clearedRoomsTemp |= (1 << roomNumber);
}

/**
 * Unsets current scene temp clear flag.
 */
void Actor_UnsetRoomClearedTemp(GlobalContext* globalCtx, u32 roomNumber) {
    globalCtx->actorCtx.clearedRoomsTemp &= ~(1 << roomNumber);
}

/**
 * Tests if current scene collectible flag is set.
 */
s32 Actor_GetCollectibleFlag(GlobalContext* globalCtx, s32 index) {
    if (index > 0 && index < 0x80) {
        return globalCtx->actorCtx.collectibleFlags[(index & -0x20) >> 5] & (1 << (index & 0x1F));
    }
    return 0;
}

/**
 * Sets current scene collectible flag.
 */
void Actor_SetCollectibleFlag(GlobalContext* globalCtx, s32 index) {
    if (index > 0 && index < 0x80) {
        globalCtx->actorCtx.collectibleFlags[(index & -0x20) >> 5] |= 1 << (index & 0x1F);
    }
}

void Actor_TitleCardContextInit(GlobalContext* globalCtx, TitleCardContext* titleCtxt) {
    titleCtxt->fadeOutDelay = 0;
    titleCtxt->fadeInDelay = 0;
    titleCtxt->color = 0;
    titleCtxt->alpha = 0;
}

void Actor_TitleCardCreate(GlobalContext* globalCtx, TitleCardContext* titleCtxt, u32 texture, s16 param_4, s16 param_5, u8 param_6, u8 param_7) {
    titleCtxt->texture = texture;
    titleCtxt->unk_04 = param_4;
    titleCtxt->unk_06 = param_5;
    titleCtxt->unk_08 = param_6;
    titleCtxt->unk_09 = param_7;
    titleCtxt->fadeOutDelay = 80;
    titleCtxt->fadeInDelay = 0;
}

void TitleCard_InitPlaceName(s32 param_1, s32 param_2, s32 param_3, s32 param_4) {

}

void Actor_TitleCardUpdate(GlobalContext* globalCtx, TitleCardContext* titleCtxt) {
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

void Actor_TitleCardDraw(GlobalContext* globalCtx, TitleCardContext* titleCtx) {
    if (titleCtx->alpha != 0) {
        s32 spCC = titleCtx->unk_08;
        s32 spC8 = titleCtx->unk_09;
        s32 sp38 = spCC * 2;
        s32 spC0 = (titleCtx->unk_04 * 4) - sp38;
        s32 pad;
        s32 spB8 = (titleCtx->unk_06 * 4) - (spC8 * 2);
        s32 spB4;
        s32 pad2;

        OPEN_DISPS(globalCtx->state.gfxCtx);

        spC8 = (spCC * spC8 > 0x1000) ? 0x1000 / spCC : spC8;
        spB4 = spB8 + (spC8 * 4);

        if (1) {} // Necessary to match

        oGfxCtx->overlay.p = func_8012C014(oGfxCtx->overlay.p);

        gDPSetPrimColor(oGfxCtx->overlay.p++, 0, 0, (u8)titleCtx->color, (u8)titleCtx->color, (u8)titleCtx->color,
                        (u8)titleCtx->alpha);

        gDPLoadTextureBlock(oGfxCtx->overlay.p++, titleCtx->texture, G_IM_FMT_IA, G_IM_SIZ_8b, spCC, spC8, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(oGfxCtx->overlay.p++, spC0, spB8, ((sp38 * 2) + spC0) - 4, spB8 + (spC8 * 4) - 1,
                            G_TX_RENDERTILE, 0, 0, 1024, 1024);

        spC8 = titleCtx->unk_09 - spC8;

        if (spC8 > 0) {
            gDPLoadTextureBlock(oGfxCtx->overlay.p++, titleCtx->texture + 0x1000, G_IM_FMT_IA, G_IM_SIZ_8b, spCC,
                                spC8, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(oGfxCtx->overlay.p++, spC0, spB4, ((sp38 * 2) + spC0) - 4, spB4 + (spC8 * 4) - 1,
                                G_TX_RENDERTILE, 0, 0, 1024, 1024);
        }

        CLOSE_DISPS(globalCtx->state.gfxCtx);
    }
}

s32 func_800B6434(GlobalContext *globalCtx, TitleCardContext *titleCtxt) {
    if ((globalCtx->actorCtx.titleCtxt.fadeInDelay != 0) || (globalCtx->actorCtx.titleCtxt.alpha != 0)) {
        titleCtxt->fadeOutDelay = 0;
        titleCtxt->fadeInDelay = 0;
        return 0;
    }
    return 1;
}

void func_800B6468(GlobalContext *globalCtx) {
    globalCtx->actorCtx.unk1F5 = 0;
}

void func_800B6474(GlobalContext *globalCtx) {
    if (globalCtx->actorCtx.unk1F5 != 0) {
        globalCtx->actorCtx.unk1F5--;
    }
}

s32 func_800B648C(GlobalContext *globalCtx, s32 param_2, s32 param_3, f32 param_4, Vec3f *param_5) {
    if ((globalCtx->actorCtx.unk1F5 != 0) && (param_4 < globalCtx->actorCtx.unk1F8)) {
        return 0;
    }
    globalCtx->actorCtx.unk1F4 = param_2;
    globalCtx->actorCtx.unk1F5 = param_3;
    globalCtx->actorCtx.unk1F8 = param_4;
    Math_Vec3f_Copy(&globalCtx->actorCtx.unk1FC, param_5);
    return 1;
}

f32 func_800B64FC(GlobalContext *globalCtx, f32 arg1, Vec3f *arg2, u32 *arg3) {
    f32 dist;

    if ((globalCtx->actorCtx.unk1F5 == 0) || (arg1 == 0.0f)) {
        return -1.0f;
    }
    dist = Math_Vec3f_DistXYZ(&globalCtx->actorCtx.unk1FC, arg2) / arg1;
    *arg3 = globalCtx->actorCtx.unk1F4;
    return globalCtx->actorCtx.unk1F8 - dist;
}

void *func_800B6584(GlobalContext *globalCtx, s16 arg1, void *arg2, u32 arg3) {
    struct_actorCtx_20C* phi_v1 = &globalCtx->actorCtx.unk_20C[0];
    s32 i;
    
    for (i = 0; i < ARRAY_COUNT(globalCtx->actorCtx.unk_20C); i++, phi_v1++) {
        if (phi_v1->unk_00 != 0) {
            continue;
        }

        if (arg2 == NULL) {
            arg2 = zelda_malloc(arg3);
            if (arg2 == NULL) {
                return NULL;
            }
            phi_v1->unk_02 = 1;
        }
        phi_v1->unk_00 = arg1;
        phi_v1->unk_04 = arg2;
        return arg2;
    }
    return NULL;
}

void* func_800B6608(GlobalContext *globalCtx, s16 arg1) {
    struct_actorCtx_20C* phi_v1 = &globalCtx->actorCtx.unk_20C[0];
    s32 i;
    
    for (i = 0; i < ARRAY_COUNT(globalCtx->actorCtx.unk_20C); i++, phi_v1++) {
        if (phi_v1->unk_00 == arg1) {
            phi_v1->unk_00 = 0;
            if (phi_v1->unk_02 != 0) {
                zelda_free(phi_v1->unk_04);
                phi_v1->unk_02 = 0;
            }
            return phi_v1->unk_04;
        }
    }
    return 0;
}

void *func_800B6680(GlobalContext *globalCtx, s16 arg1) {
    struct_actorCtx_20C *phi_v1 = globalCtx->actorCtx.unk_20C;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(globalCtx->actorCtx.unk_20C); i++, phi_v1++) {
        if (arg1 == phi_v1->unk_00) {
            return phi_v1->unk_04;
        }
    }

    return NULL;
}

void Actor_Kill(Actor* actor) {
    actor->draw = NULL;
    actor->update = NULL;
    actor->flags &= ~0x1;
}

void Actor_InitPosRot(Actor* actor) {
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

void Actor_SetObjectSegment(GlobalContext* globalCtx, Actor* actor) {
    // TODO: Segment number enum
    gRspSegmentPhysAddrs[6] = PHYSICAL_TO_VIRTUAL(globalCtx->sceneContext.objects[actor->objBankIndex].vramAddr);
}

void Actor_Init(Actor* actor, GlobalContext* globalCtx) {
    Actor_InitPosRot(actor);
    Actor_InitDrawRotation(actor);
    Actor_SetHeight(actor, 0.0f);
    Math_Vec3f_Copy(&actor->lastPos, &actor->posRot.pos);
    Actor_SetScale(actor, 0.01f);
    actor->minVelocityY = -20.0f;
    actor->unk1F = 3;
    actor->sqrdDistanceFromLink = FLT_MAX;
    actor->naviEnemyId = 255;
    actor->uncullZoneForward = 1000.0f;
    actor->uncullZoneScale = 350.0f;
    actor->uncullZoneDownward = 700.0f;
    func_800E7494(&actor->colChkInfo);
    actor->floorPolySource = 0x32;
    ActorShape_Init(&actor->shape, 0, 0, 0);
    if (Scene_IsObjectLoaded(&globalCtx->sceneContext, actor->objBankIndex)) {
        Actor_SetObjectSegment(globalCtx, actor);
        actor->init(actor, globalCtx);
        actor->init = NULL;
    }
}

void Actor_Destroy(Actor* actor, GlobalContext* globalCtx) {
    if (actor->init == NULL) {
        if (actor->destroy != NULL) {
            actor->destroy(actor, globalCtx);
            actor->destroy = NULL;
        }
    }
}

f32 actorMovementScale = 1.0f;

void Actor_SetMovementScale(s32 scale) {
    actorMovementScale = scale * 0.5f;
}

void Actor_ApplyMovement(Actor* actor) {
    f32 speedRate = actorMovementScale;

    actor->posRot.pos.x += (actor->velocity.x * speedRate) + actor->colChkInfo.displacement.x;
    actor->posRot.pos.y += (actor->velocity.y * speedRate) + actor->colChkInfo.displacement.y;
    actor->posRot.pos.z += (actor->velocity.z * speedRate) + actor->colChkInfo.displacement.z;
}

void Actor_SetVelocityYRotationAndGravity(Actor* actor) {
    actor->velocity.x = actor->speedXZ * Math_Sins(actor->posRot.rot.y);
    actor->velocity.z = actor->speedXZ * Math_Coss(actor->posRot.rot.y);
    actor->velocity.y += actor->gravity;

    if (actor->velocity.y < actor->minVelocityY) {
        actor->velocity.y = actor->minVelocityY;
    }
}

void Actor_MoveForward(Actor* actor) {
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

void func_800B6C04(Actor *actor, f32 arg1) {
    actor->speedXZ = Math_Coss(actor->posRot.rot.x) * arg1;
    actor->velocity.y = -Math_Sins(actor->posRot.rot.x) * arg1;
}

void func_800B6C58(Actor *actor, SkelAnime *skelAnime) {
    Vec3f sp1C;

    func_80137748(skelAnime, &sp1C, actor->shape.rot.y);
    actor->posRot.pos.x += sp1C.x * actor->scale.x;
    actor->posRot.pos.y += sp1C.y * actor->scale.y;
    actor->posRot.pos.z += sp1C.z * actor->scale.z;
}

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

void func_800B6F20(GlobalContext *globalCtx, struct_actorCtx_26C *param_2, f32 param_3, s16 param_4) {
    s16 sp26 = param_4 - func_800DFC68(globalCtx->cameraPtrs[globalCtx->activeCamera]);

    param_2->unk_02 = -Math_Sins(sp26) * param_3;
    param_2->unk_14 = param_2->unk_02;
    param_2->unk_03 = Math_Coss(sp26) * param_3;
    param_2->unk_15 = param_2->unk_03;
}

f32 func_800B6FC8(Player *player) {
    f32 phi_f2 = (player->stateFlags1 & 0x800000) ? 32.0f : 0.0f;

    switch (player->unk14B) {
        default:
        case 0:
            return phi_f2 + 124.0f;
        case 1:
            return phi_f2 + ((player->unkA74 & 0x1000) ? 34.0f : 80.0f);
        case 2:
            return phi_f2 + 68.0f;
        case 3:
            return phi_f2 + 36.0f;
        case 4:
            return phi_f2 + 44.0f;
    }
}

f32 func_800B7090(Player* player) {
    if (player->stateFlags1 & 0x800000) {
        return 15.0f;
    } else if (player->stateFlags1 & 0x8000000) {
        return (REG(45) / 100.0f) * 0.6f;
    } else {
        return REG(45) / 100.0f;
    }
}

s32 func_800B7118(Player* player) {
    return player->stateFlags1 & 0x8;
}

s32 func_800B7128(Player* player) {
    return func_800B7118(player) && player->unkACC;
}

s32 func_800B715C(GlobalContext* globalCtx) {
    Player* player = PLAYER;

    return player->stateFlags2 & 0x8;
}

void func_800B7170(GlobalContext* globalCtx, Player* player) {
    #include "overlays/actors/ovl_En_Horse/z_en_horse.h"

    if ((globalCtx->roomContext.currRoom.unk3 != 4) && (player->actor.id == ACTOR_PLAYER)) {
        EnHorse* horse = (EnHorse*)player->rideActor;

        if ((horse != NULL) && !(horse->unk_1EC & 0x10)) {
            func_800DFAC8(Play_GetCamera(globalCtx, 0), 4);
        }
    }
}

void func_800B71DC(GlobalContext* globalCtx, Player* player, Actor* horse) {
    player->rideActor = horse;
    player->stateFlags1 |= 0x800000;
    horse->child = &player->actor;
}

s32 func_800B7200(Player* player) {
    return (player->stateFlags1 & 0x20000080) || (player->csMode != 0);
}

void func_800B722C(GlobalContext *globalCtx, Player *player) {
    func_800F40A0(globalCtx, player);
}

s32 func_800B724C(GlobalContext *globalCtx, Actor *actor, u8 csMode) {
    Player* player = PLAYER;

    if ((player->csMode == 5) || ((csMode == 6) && (player->csMode == 0))) {
        return 0;
    }

    player->csMode = csMode;
    player->unk398 = actor;
    player->unk3BA = 0;
    return 1;
}

s32 func_800B7298(GlobalContext* globalCtx, Actor* actor, u8 csMode) {
    Player* player = PLAYER;

    if (func_800B724C(globalCtx, actor, csMode)) {
        player->unk3BA = 1;
        return 1;
    }
    return 0;
}

void func_800B72E0(DynaPolyActor* dynaActor) {
    dynaActor->unk148 = dynaActor->unk14C = 0.0f;
}

void func_800B72F8(DynaPolyActor* dynaActor, f32 arg1, s16 arg2) {
    dynaActor->unk150 = arg2;
    dynaActor->unk148 += arg1;
}

s32 Actor_IsLinkFacingActor(Actor* actor, s16 tolerance, GlobalContext* globalCtx) {
    Player* player = PLAYER;
    s16 var = (s16)(actor->yawTowardsLink + 0x8000) - player->actor.shape.rot.y;

    if (ABS2(var) < tolerance) {
        return 1;
    }

    return 0;
}

s32 Actor_IsActorFacedByActor(Actor* actorA, Actor* actorB, s16 tolerance) {
    s16 angle;
    s16 dist;

    angle = Actor_YawBetweenActors(actorA, actorB) + 0x8000;
    dist = angle - actorB->shape.rot.y;
    if (ABS2(dist) < tolerance) {
        return 1;
    }
    return 0;
}

s32 Actor_IsActorFacingLink(Actor* actor, s16 angle) {
    s16 dist;

    dist = actor->yawTowardsLink - actor->shape.rot.y;
    if (ABS2(dist) < angle) {
        return 1;
    }
    return 0;
}

s32 Actor_IsActorFacingActor(Actor* actorA, Actor* actorB, s16 tolerance) {
    s16 dist;

    dist = Actor_YawBetweenActors(actorA, actorB) - actorA->shape.rot.y;
    if (ABS2(dist) < tolerance) {
        return 1;
    }
    return 0;
}

s32 Actor_IsActorFacingLinkAndWithinRange(Actor* actor, f32 range, s16 tolerance) {
    s16 var = actor->yawTowardsLink - actor->shape.rot.y;

    if (ABS2(var) < tolerance) {
        f32 xyzDistanceFromLink = sqrtf(SQ(actor->xzDistanceFromLink) + SQ(actor->yDistanceFromLink));

        if (xyzDistanceFromLink < range) {
            return 1;
        }
    }

    return 0;
}

s32 Actor_IsActorFacingActorAndWithinRange(Actor* actorA, Actor* actorB, f32 range, s16 tolerance) {
    s16 dist;

    if (Actor_DistanceBetweenActors(actorA, actorB) < range) {
        dist = Actor_YawBetweenActors(actorA, actorB) - actorA->shape.rot.y;
        if (ABS2(dist) < tolerance) {
            return 1;
        }
    }
    return 0;
}

void func_800B75A0(CollisionPoly *param_1, Vec3f *param_2, s16 *param_3) {
    param_2->x = param_1->normal.x * (1.0f / 32767);
    param_2->y = param_1->normal.y * (1.0f / 32767);
    param_2->z = param_1->normal.z * (1.0f / 32767);
    *param_3 = atans_flip(param_2->z, param_2->x);
}

s32 func_800B761C(Actor* actor, f32 arg1, s32 arg2) {
    if (actor->bgCheckFlags & 0x1) {
        actor->bgCheckFlags &= ~0x1;
        actor->bgCheckFlags |= 0x4;

        if ((actor->velocity.y < 0.0f) && (arg2 & 0x10)) {
            actor->velocity.y = 0.0f;
        }

        return 0;
    }

    return 1;
}

UNK_TYPE D_801ED8B0;
u32 D_801ED8B4;

s32 func_800B7678(GlobalContext* globalCtx, Actor* actor, Vec3f* arg2, s32 arg3) {
    f32 sp34;
    u32 sp30;

    arg2->y += (arg3 & 0x800) ? 10.0f : 50.0f;

    actor->groundY = func_800C4188(globalCtx, &globalCtx->colCtx, &actor->floorPoly, &sp30, actor, arg2);
    actor->bgCheckFlags &= ~0x0086;

    if (actor->groundY <= -32000.0f) {
        return func_800B761C(actor, -32000.0f, arg3);
    }

    sp34 = actor->groundY - actor->posRot.pos.y;
    actor->floorPolySource = sp30;

    if ((sp34 >= 0.0f) || ((actor->bgCheckFlags & 0x1) && !(actor->bgCheckFlags & 0x800) && 
        (sp34 >= -11.0f) && (actor->velocity.y < 0.0f))) {
        actor->bgCheckFlags |= 0x80;

        if (actor->bgCheckFlags & 0x10) {
            if (sp30 != D_801ED8B4) {
                if (sp34 > 15.0f) {
                    actor->bgCheckFlags |= 0x100;
                }
            } else {
                actor->posRot.pos.x = actor->lastPos.x;
                actor->posRot.pos.z = actor->lastPos.z;
            }
        }

        actor->posRot.pos.y = actor->groundY;

        if (actor->velocity.y <= 0.0f) {
            if (!(actor->bgCheckFlags & 0x1)) {
                actor->bgCheckFlags |= 0x2;
            } else if ((arg3 & 0x8) && (actor->gravity < 0.0f)) {
                actor->velocity.y = -4.0f;
            } else if (!(arg3 & 0x100)) {
                actor->velocity.y = 0.0f;
            }

            actor->bgCheckFlags |= 0x1;
            BgCheck2_AttachToMesh(&globalCtx->colCtx, actor, actor->floorPolySource);
        }
    } else {
        return func_800B761C(actor, sp34, arg3);
    }

    return 1;
}

void func_800B78B8(GlobalContext* globalCtx, Actor* actor, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    f32 sp74 = actor->posRot.pos.y - actor->lastPos.y;
    s32 pad;
    Vec3f sp64;
    u32 sp60;
    
    if ((actor->floorPolySource != 0x32) && (actor->bgCheckFlags & 1)) {
        BgCheck2_UpdateActorAttachedToMesh(&globalCtx->colCtx, actor->floorPolySource, actor);
    }

    if (arg5 & 1) {
        actor->bgCheckFlags &= ~0x1000;
        if ((!(arg5 & 0x80) && func_800C4D3C(&globalCtx->colCtx, &sp64, &actor->posRot.pos, &actor->lastPos, arg3,
                                             &actor->wallPoly, &sp60, actor, arg2)) ||
            ((arg5 & 0x80) && func_800C4DA4(&globalCtx->colCtx, &sp64, &actor->posRot.pos, &actor->lastPos, arg3,
                                            &actor->wallPoly, &sp60, actor, arg2))) {
            CollisionPoly* sp5C = actor->wallPoly;
            
            actor->bgCheckFlags |= 8;
            if ((arg5 & 0x200) && (actor->bgCheckFlags & 0x1000) && (sp5C->normal.y > 0) && 
                (sqrtf(SQ(actor->colChkInfo.displacement.x) + SQ(actor->colChkInfo.displacement.y) + SQ(actor->colChkInfo.displacement.z)) < 10.0f)) {
                actor->bgCheckFlags &= ~8;
            } else if (actor->bgCheckFlags & 8) {
                Math_Vec3f_Copy(&actor->posRot.pos, &sp64);
            }
            actor->wallPolyRot = atans_flip(sp5C->normal.z, sp5C->normal.x);
            actor->wallPolySource = sp60;
        } else {
            actor->bgCheckFlags &= ~8;
        }
    }

    sp64.x = actor->posRot.pos.x;
    sp64.z = actor->posRot.pos.z;

    if (arg5 & 2) {
        f32 sp58;

        sp64.y = actor->lastPos.y + 4.0f;
        if (func_800C4F84(&globalCtx->colCtx, &sp58, &sp64, (arg4 + sp74) - 4.0f, &D_801ED8B0, &D_801ED8B4, actor)) {
            actor->bgCheckFlags |= 0x10;
            actor->posRot.pos.y = (sp58 + sp74) - 4.0f;
        } else {
            actor->bgCheckFlags &= ~0x10;
        }
    }

    if (arg5 & 4) {
        UNK_TYPE sp54;
        f32 sp50;

        sp64.y = actor->lastPos.y;
        func_800B7678(globalCtx, actor, &sp64, arg5);
        sp50 = actor->posRot.pos.y;
        if (func_800CA1AC(globalCtx, &globalCtx->colCtx, actor->posRot.pos.x, actor->posRot.pos.z, &sp50, &sp54)) {
            actor->waterY = sp50 - actor->posRot.pos.y;
            if (actor->waterY <= 0.0f) {
                actor->bgCheckFlags &= ~0x60;
            } else {
                if (!(actor->bgCheckFlags & 0x20)) {
                    actor->bgCheckFlags |= 0x60;
                    if (!(arg5 & 0x40)) {
                        Vec3f ripplePos;
                        ripplePos.x = actor->posRot.pos.x;
                        ripplePos.y = sp50;
                        ripplePos.z = actor->posRot.pos.z;
                        EffectSS_SpawnGRipple(globalCtx, &ripplePos, 100, 500, 0);
                        EffectSS_SpawnGRipple(globalCtx, &ripplePos, 100, 500, 4);
                        EffectSS_SpawnGRipple(globalCtx, &ripplePos, 100, 500, 8);
                    }
                } else {
                    actor->bgCheckFlags &= ~0x40;
                }
            }
        } else {
            actor->bgCheckFlags &= ~0x60;
            actor->waterY = -32000.0f;
        }
    }

    if (arg5 & 0x400) {
        UNK_TYPE sp54;
        f32 sp50 = actor->posRot.pos.y;

        if (func_800CA1AC(globalCtx, &globalCtx->colCtx, actor->posRot.pos.x, actor->posRot.pos.z, &sp50, &sp54)) {
            actor->waterY = sp50 - actor->posRot.pos.y;
            if (actor->waterY < 0.0f) {
                actor->bgCheckFlags &= ~0x60;
                return;
            }
            
            if (!(actor->bgCheckFlags & 0x20)) {
                actor->bgCheckFlags |= 0x60;
                if (!(arg5 & 0x40)) {
                    Vec3f ripplePos;
                    ripplePos.x = actor->posRot.pos.x;
                    ripplePos.y = sp50;
                    ripplePos.z = actor->posRot.pos.z;
                    EffectSS_SpawnGRipple(globalCtx, &ripplePos, 100, 500, 0);
                    EffectSS_SpawnGRipple(globalCtx, &ripplePos, 100, 500, 4);
                    EffectSS_SpawnGRipple(globalCtx, &ripplePos, 100, 500, 8);
                }
            } else {
                actor->bgCheckFlags &= ~0x40;
            }
        } else {
            actor->bgCheckFlags &= ~0x60;
            actor->waterY = -32000.0f;
        }
    }
}

Mtx D_801ED8E0;

Gfx* func_800B7E04(Vec3f* object, Vec3f* eye, Vec3f* lightDir, GraphicsContext* gfxCtx, Gfx* gfx, Hilite** hilite) {
    Gfx* lookAt;
    f32 correctedEyeX;

    lookAt = (Gfx*)GRAPH_ALLOC(gfxCtx, 4 * sizeof(Gfx));

    correctedEyeX = (eye->x == object->x) && (eye->z == object->z) ? eye->x + 0.001f : eye->x;

    *hilite = (Hilite*)GRAPH_ALLOC(gfxCtx, sizeof(Hilite));

    guLookAtHilite(&D_801ED8E0, lookAt, *hilite, correctedEyeX, eye->y, eye->z, object->x, object->y, object->z, 0.0f,
                   1.0f, 0.0f, lightDir->x, lightDir->y, lightDir->z, lightDir->x, lightDir->y, lightDir->z, 0x10,
                   0x10);

    gSPLookAt(gfx++, lookAt);
    gDPSetHilite1Tile(gfx++, 1, *hilite, 0x10, 0x10);

    return gfx;
}

Hilite* func_800B7FE0(Vec3f* object, Vec3f* eye, Vec3f* lightDir, GraphicsContext* gfxCtx) {
    Hilite* hilite;

    OPEN_DISPS(gfxCtx);

    oGfxCtx->polyOpa.p = func_800B7E04(object, eye, lightDir, gfxCtx, oGfxCtx->polyOpa.p, &hilite);

    CLOSE_DISPS(gfxCtx);

    return hilite;
}

Hilite* func_800B8018(Vec3f* object, Vec3f* eye, Vec3f* lightDir, GraphicsContext* gfxCtx) {
    Hilite* hilite;

    OPEN_DISPS(gfxCtx);

    oGfxCtx->polyXlu.p = func_800B7E04(object, eye, lightDir, gfxCtx, oGfxCtx->polyXlu.p, &hilite);

    CLOSE_DISPS(gfxCtx);

    return hilite;
}

void func_800B8050(Actor* actor, GlobalContext* globalCtx, s32 flag) {
    Hilite* hilite;
    Gfx* displayListHead;
    Gfx* displayList;

    hilite = func_800BCBF4(&actor->posRot.pos, globalCtx);

    if (flag != 0) {
        displayList = GRAPH_ALLOC(globalCtx->state.gfxCtx, 2 * sizeof(Gfx));
        displayListHead = displayList;

        OPEN_DISPS(globalCtx->state.gfxCtx);

        gDPSetHilite1Tile(displayListHead++, 1, hilite, 0x10, 0x10);
        gSPEndDisplayList(displayListHead);
        gSPSegment(oGfxCtx->polyOpa.p++, 0x07, displayList);

        CLOSE_DISPS(globalCtx->state.gfxCtx);
    }
}

void func_800B8118(Actor* actor, GlobalContext* globalCtx, s32 flag) {
    Hilite* hilite;
    Gfx* displayListHead;
    Gfx* displayList;

    hilite = func_800BCC68(&actor->posRot.pos, globalCtx);

    if (flag != 0) {
        displayList = GRAPH_ALLOC(globalCtx->state.gfxCtx, 2 * sizeof(Gfx));
        displayListHead = displayList;

        OPEN_DISPS(globalCtx->state.gfxCtx);

        gDPSetHilite1Tile(displayListHead++, 1, hilite, 0x10, 0x10);
        gSPEndDisplayList(displayListHead);
        gSPSegment(oGfxCtx->polyXlu.p++, 0x07, displayList);

        CLOSE_DISPS(globalCtx->state.gfxCtx);
    }
}

PosRot* func_800B81E0(PosRot* posRot, Actor* actor) {
    *posRot = actor->topPosRot;

    return posRot;
}

PosRot* func_800B8214(PosRot* posRot, Actor* actor) {
    *posRot = actor->posRot;

    return posRot;
}

PosRot* func_800B8248(PosRot* arg0, Actor* actor) {
    PosRot sp1C;

    Math_Vec3f_Copy(&sp1C.pos, &actor->posRot.pos);
    if (actor->id == ACTOR_PLAYER) {
        Player* player = (Player*)actor;

        sp1C.pos.y += player->unkAC0 * player->actor.scale.y;
    }

    sp1C.rot = actor->shape.rot;
    *arg0 = sp1C;

    return arg0;
}

f32 func_800B82EC(Actor* actor, Player* player, s16 arg2) {
    s16 yawTemp;
    s16 yawTempAbs;
    f32 ret;

    yawTemp = (s16)(actor->yawTowardsLink - 0x8000) - arg2;
    yawTempAbs = ABS2(yawTemp);

    if (player->unk730 != NULL) {
        if ((yawTempAbs > 0x4000) || (actor->flags & 0x8000000)) {
            return FLT_MAX;
        } else {
            ret = actor->sqrdDistanceFromLink -
                  actor->sqrdDistanceFromLink * 0.8f * ((0x4000 - yawTempAbs) * 0.000030517578f);
            return ret;
        }
    }

    if (yawTempAbs > 0x2AAA) {
        return FLT_MAX;
    }

    return actor->sqrdDistanceFromLink;
}

typedef struct {
    f32 unk_0, unk_4;
} struct_801AECF0; // size = 0x8

struct_801AECF0 D_801AECF0[] = {
    { 4900.0f, 0.5f },         { 28900.0f, 0.6666667f },   { 78400.0f, 0.05f },       { 122500.0f, 0.6666667f },
    { 490000.0f, 0.6666667f }, { 1000000.0f, 0.6666667f }, { 10000.0f, 0.94905096f }, { 19600.0f, 0.85714287f },
    { 57600.0f, 0.41666666f }, { 78400.0f, 0.001f },
};

u32 func_800B83BC(Actor* actor, f32 arg1) {
    return arg1 < D_801AECF0[actor->unk1F].unk_0;
}

s32 func_800B83F8(Actor* actor, Player* player, s32 flag) {
    if ((actor->update == NULL) || !(actor->flags & 1) || (actor->flags & 0x8000000)) {
        return 1;
    }

    if (!flag) {
        s16 var = (s16)(actor->yawTowardsLink - 0x8000) - player->actor.shape.rot.y;
        s16 abs_var = ABS2(var);
        f32 dist;

        if ((player->unk730 == NULL) && (abs_var > 0x2AAA)) {
            dist = FLT_MAX;
        } else {
            dist = actor->sqrdDistanceFromLink;
        }

        return !func_800B83BC(actor, D_801AECF0[actor->unk1F].unk_4 * dist);
    }

    return 0;
}

u32 func_800B84D0(Actor* actor, GlobalContext* globalCtx) {
    if (actor->flags & 0x100) {
        actor->flags &= ~0x100;
        return 1;
    }

    return 0;
}

s32 func_800B8500(Actor* actor, GlobalContext* globalCtx, f32 arg2, f32 arg3, s32 exchangeItemId) {
    Player* player = PLAYER;

    // This is convoluted but it seems like it must be a single if statement to match
    if ((player->actor.flags & 0x100) || ((exchangeItemId > 0) && Player_InCsMode(globalCtx)) ||
        ((actor->unk114 == 0) &&
         ((fabsf(actor->yDistanceFromLink) > fabsf(arg3)) || (player->targetActorDistance < actor->xzDistanceFromLink) ||
          (arg2 < actor->xzDistanceFromLink)))) {
        return 0;
    }

    player->targetActor = actor;
    player->targetActorDistance = actor->xzDistanceFromLink;
    player->exchangeItemId = exchangeItemId;
    ActorCutscene_SetIntentToPlay(0x7C);
    return 1;
}

s32 func_800B85E0(Actor* actor, GlobalContext* globalCtx, f32 arg2, s32 exchangeItemId) {
    return func_800B8500(actor, globalCtx, arg2, arg2, exchangeItemId);
}

s32 func_800B8614(Actor* actor, GlobalContext* globalCtx, f32 arg2) {
    return func_800B85E0(actor, globalCtx, arg2, 0);
}

s32 func_800B863C(Actor *actor, GlobalContext *globalCtx) {
    f32 temp = actor->colChkInfo.unk10 + 50.0f;

    return func_800B8614(actor, globalCtx, temp);
}

s32 func_800B867C(Actor* actor, GlobalContext* globalCtx) {
    if (func_80152498(&globalCtx->msgCtx) == 2) {
        actor->flags &= ~0x100;
        return 1;
    } else {
        return 0;
    }
}

s32 func_800B86C8(s32 arg0, GlobalContext* globalCtx, Actor* actor) {
    Player* player = PLAYER;
    Actor* target = player->targetActor;

    if ((player->actor.flags & 0x100) && (target != NULL)) {
        player->targetActor = actor;
        player->unk730 = actor;
        return 1;
    }
    return 0;
}

s8 func_800B8708(GlobalContext* globalCtx) {
    Player* player = PLAYER;

    return player->exchangeItemId;
}

s32 func_800B8718(Actor *actor, GlobalContext* globalCtx) {
    if (actor->flags & 0x20000000) {
        actor->flags &= ~0x20000000;
        return 1;
    }
    return 0;
}

s32 func_800B874C(Actor *actor, GlobalContext *globalCtx, f32 arg2, f32 arg3) {
    Player* player = PLAYER;

    if ((player->actor.flags & 0x20000000) || Player_InCsMode(globalCtx) || 
        (arg3 < fabsf(actor->yDistanceFromLink)) || 
        (player->unkA94 < actor->xzDistanceFromLink) || (arg2 < actor->xzDistanceFromLink)) {
        return 0;
    }
    player->unkA90 = actor;
    player->unkA94 = actor->xzDistanceFromLink;
    return 1;
}

s32 func_800B8804(Actor *actor, GlobalContext *globalCtx, f32 arg2) {
    return func_800B874C(actor, globalCtx, arg2, 20.0f);
}

s32 func_800B882C(Actor *actor, GlobalContext *globalCtx) {
    f32 temp = actor->colChkInfo.unk10 + 50.0f;

    return func_800B8804(actor, globalCtx, temp);
}

s32 func_800B886C(Actor *actor, GlobalContext *globalCtx) {
    if (!(PLAYER->actor.flags & 0x20000000)) {
        return 1;
    }
    return 0;
}

void func_800B8898(GlobalContext* globalCtx, Actor* actor, s16* arg2, s16* arg3) {
    Vec3f sp1C;
    f32 sp18;

    func_800B4EDC(globalCtx, &actor->topPosRot.pos, &sp1C, &sp18);
    *arg2 = sp1C.x * sp18 * 160.0f + 160.0f;
    *arg3 = sp1C.y * sp18 * -120.0f + 120.0f;
}

s32 func_800B8934(GlobalContext *globalCtx, Actor *actor) {
    Vec3f sp2C;
    f32 sp28;
    f32 xTest;
    f32 yTest;

    func_800B4EDC(globalCtx, &actor->topPosRot, &sp2C, &sp28);
    xTest = sp2C.x * sp28;
    yTest = sp2C.y * sp28;
    return (xTest >= -1.0f) && (xTest <= 1.0f) && 
           (yTest >= -1.0f) && (yTest <= 1.0f);
}

u32 Actor_HasParent(Actor* actor, GlobalContext* globalCtx) {
    if (actor->parent != NULL) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_800B8A1C(Actor* actor, GlobalContext* globalCtx, s32 getItemId, f32 xzRange, f32 yRange) {
    Player* player = PLAYER;
    s16 yawDiff;
    s32 absYawDiff;

    if (!(player->stateFlags1 & 0x3C7080) && func_80124258(player) < 0) {
        if ((xzRange >= actor->xzDistanceFromLink) && (fabsf(actor->yDistanceFromLink) <= fabsf(yRange))) {
            if (((getItemId == 0x83) || (getItemId == 0xAB) || (getItemId == 0x97)) ||
                ((((player->heldActor != NULL) || (actor == player->targetActor)) && 
                  ((getItemId > 0) && (getItemId < 0xBA))) ||
                !(player->stateFlags1 & 0x20000800))) {
                yawDiff = actor->yawTowardsLink - player->actor.shape.rot.y;
                absYawDiff = ABS2(yawDiff);
                if ((getItemId != 0) || (player->getItemDirection < absYawDiff)) {
                    player->getItemId = getItemId;
                    player->interactRangeActor = actor;
                    player->getItemDirection = absYawDiff;
                    if ((getItemId > 0) && (getItemId < 0xBA)) {
                        ActorCutscene_SetIntentToPlay(globalCtx->unk1879E);
                    }
                    return 1;
                }
            }
        }
    }

    return 0;
}

void func_800B8B84(Actor* actor, GlobalContext* globalCtx, s32 getItemId) {
    func_800B8A1C(actor, globalCtx, getItemId, 50.0f, 10.0f);
}

void func_800B8BB0(Actor* actor, GlobalContext* globalCtx) {
    func_800B8B84(actor, globalCtx, 0);
}

void func_800B8BD0(Actor* actor, GlobalContext* globalCtx, s32 getItemId) {
    func_800B8A1C(actor, globalCtx, getItemId, 9999.9f, 9999.9f);
}

u32 Actor_HasNoParent(Actor* actor, GlobalContext* globalCtx) {
    if (actor->parent == NULL) {
        return true;
    } else {
        return false;
    }
}

void func_800B8C20(Actor* actorA, Actor* actorB, GlobalContext* globalCtx) {
    Actor* parent = actorA->parent;

    if (parent->id == ACTOR_PLAYER) {
        Player* player = (Player*)parent;
        player->heldActor = actorB;
        player->interactRangeActor = actorB;
    }

    parent->child = actorB;
    actorB->parent = parent;
    actorA->parent = NULL;
}

void func_800B8C50(Actor* actor, GlobalContext* globalCtx) {
    Player* player = PLAYER;

    if (actor->sqrdDistanceFromLink < player->unkAA0) {
        player->unkAA0 = actor->sqrdDistanceFromLink;
    }
}

u32 Actor_HasChild(GlobalContext* globalCtx, Actor* actor) {
    if (actor->child != NULL) {
        return true;
    } else {
        return false;
    }
}

u32 func_800B8C9C(GlobalContext* globalCtx, Actor* horse, s32 arg2) {
    Player* player = PLAYER;

    if (!(player->stateFlags1 & 0x003C7880)) {
        player->rideActor = horse;
        player->unk38C = arg2;
        ActorCutscene_SetIntentToPlay(0x7C);
        return 1;
    }

    return 0;
}

u32 Actor_HasNoChild(GlobalContext* globalCtx, Actor* actor) {
    if (actor->child == NULL) {
        return true;
    } else {
        return false;
    }
}

void func_800B8D10(GlobalContext* globalCtx, Actor* actor, f32 arg2, s16 arg3, f32 arg4, u32 arg5, u32 arg6) {
    Player* player = PLAYER;

    player->unkB74 = arg6;
    player->unkB75 = arg5;
    player->unkB78 = arg2;
    player->unkB76 = arg3;
    player->unkB7C = arg4;
}

void func_800B8D50(GlobalContext* globalCtx, Actor* actor, f32 arg2, s16 arg3, f32 arg4, u32 arg5) {
    func_800B8D10(globalCtx, actor, arg2, arg3, arg4, 3, arg5);
}

void func_800B8D98(GlobalContext* globalCtx, Actor* actor, f32 arg2, s16 arg3, f32 arg4) {
    func_800B8D50(globalCtx, actor, arg2, arg3, arg4, 0);
}

void func_800B8DD4(GlobalContext* globalCtx, Actor* actor, f32 arg2, s16 arg3, f32 arg4, u32 arg5) {
    func_800B8D10(globalCtx, actor, arg2, arg3, arg4, 2, arg5);
}

void func_800B8E1C(GlobalContext* globalCtx, Actor* actor, f32 arg2, s16 arg3, f32 arg4) {
    func_800B8DD4(globalCtx, actor, arg2, arg3, arg4, 0);
}

void func_800B8E58(Player *player, u16 sfxId) {
    if (player->unk153 == 20) {
        func_8019F170(&player->actor.projectedPos, sfxId);
    } else {
        func_801A5CFC(sfxId, &player->actor.projectedPos, 4, &D_801DB4B0, &D_801DB4B0, &D_801DB4B8);
    }
}

void func_800B8EC8(Actor *actor, u16 sfxId) {
    func_8019F1C0(&actor->projectedPos, sfxId);
}

void func_800B8EF4(GlobalContext* globalCtx, Actor* actor) {
    s32 sfxId;

    if (actor->bgCheckFlags & 0x20) {
        if (actor->waterY < 20.0f) {
            sfxId = 4;
        } else {
            sfxId = 5;
        }
    } else {
        sfxId = func_800C9BDC(&globalCtx->colCtx, actor->floorPoly, actor->floorPolySource);
    }

    func_8019F1C0(&actor->projectedPos, 0x282F);
    func_8019F1C0(&actor->projectedPos, sfxId + 0x800);
}

void func_800B8F98(Actor* actor, u16 sfxId) {
    actor->sfx = sfxId;
    actor->unk39 &= ~0x1F;
    actor->unk39 |= 2;
}

void func_800B8FC0(Actor* actor, u16 sfxId) {
    actor->sfx = sfxId;
    actor->unk39 &= ~0x1F;
    actor->unk39 |= 4;
}

void func_800B8FE8(Actor* actor, u16 sfxId) {
    actor->sfx = sfxId;
    actor->unk39 &= ~0x1F;
    actor->unk39 |= 8;
}

void func_800B9010(Actor* actor, u16 sfxId) {
    actor->sfx = sfxId;
    actor->unk39 &= ~0x1F;
    actor->unk39 |= 1;
}

void func_800B9038(Actor* actor, s32 arg1) {
    actor->unk39 &= ~0x1F;
    actor->unk39 |= 0x10;
    if (arg1 < 40) {
        actor->sfx = 3;
    } else if (arg1 < 100) {
        actor->sfx = 2;
    } else {
        actor->sfx = 1;
    }
}

void func_800B9084(Actor* actor) {
    actor->unk39 |= 0x20;
}

void func_800B9098(Actor* actor) {
    actor->unk39 |= 0x40;
}

s32 func_800B90AC(GlobalContext *globalCtx, Actor *actor, s32 arg2, s32 arg3, s32 arg4) {
    if (func_800C99D4(&globalCtx->colCtx, arg2, arg3) == 8) {
        return 1;
    }
    return 0;
}

void func_800B90F4(GlobalContext *globalCtx) {
    if (globalCtx->actorCtx.unk3 != 0) {
        globalCtx->actorCtx.unk3 = 0;
        func_80115D5C(globalCtx);
    }
}

void func_800B9120(ActorContext *actCtxt) {
    s32 temp_v0 = (gSaveContext.perm.day % 5) * 2;

    if ((gSaveContext.perm.time < 0x4000) || (gSaveContext.perm.time > 0xC000)) {
        temp_v0++;
    }
    actCtxt->unkC = 0x200 >> temp_v0;
}

FaultClient D_801ED8A0;

void func_800B9170(GlobalContext* globalCtx, ActorContext* actorCtx, ActorEntry* actorEntry) {
    s32 pad;
    CycleSceneFlags* savedSceneFlags;
    ActorOverlay* overlayEntry;
    s32 i;

    gSaveContext.perm.weekEventReg[92] |= 0x80;
    savedSceneFlags = &gSaveContext.extra.cycleSceneFlags[convert_scene_number_among_shared_scenes(globalCtx->sceneNum)];

    bzero(actorCtx, sizeof(ActorContext));

    ActorOverlayTable_Init();
    SysMatrix_Copy(&globalCtx->mf_187FC, &D_801D1E20);
    SysMatrix_Copy(&globalCtx->mf_187B0, &D_801D1E20);

    overlayEntry = &gActorOverlayTable[0];
    for (i = 0; i < ARRAY_COUNT(gActorOverlayTable); i++) {
        overlayEntry->loadedRamAddr = NULL;
        overlayEntry->nbLoaded = 0;
        overlayEntry++;
    }

    actorCtx->chestFlags = savedSceneFlags->chestFlags;
    actorCtx->switchFlags[0] = savedSceneFlags->switchFlags[0];
    actorCtx->switchFlags[1] = savedSceneFlags->switchFlags[1];
    if (globalCtx->sceneNum == 0x18) {
        savedSceneFlags = &gSaveContext.extra.cycleSceneFlags[globalCtx->sceneNum];
    }
    actorCtx->collectibleFlags[0] = savedSceneFlags->collectibleFlags;
    actorCtx->clearedRooms = savedSceneFlags->clearedRooms;

    Actor_TitleCardContextInit(globalCtx, &actorCtx->titleCtxt);
    func_800B6468(globalCtx);
    actorCtx->unk250 = NULL;
    func_800BB2D0(actorCtx, actorEntry, globalCtx);
    Actor_TargetContextInit(&actorCtx->targetContext, actorCtx->actorList[ACTORTYPE_PLAYER].first, globalCtx);
    func_800B9120(actorCtx);
    Fault_AddClient(&D_801ED8A0, Actor_PrintLists, actorCtx, NULL);
    func_800B722C(globalCtx, actorCtx->actorList[ACTORTYPE_PLAYER].first);
}

void func_800B9334(GlobalContext *globalCtx, ActorContext *actCtxt) {
    ActorEntry *entry;
    s32 i;
    s32 temp;
    s32 temp2;

    if (globalCtx->sceneNumActorsToLoad > 0) {
        entry = globalCtx->setupActorList;
        temp = actCtxt->unkC;

        func_800B9120(actCtxt);
        func_800BA8B8(globalCtx, &globalCtx->actorCtx);

        temp2 = (actCtxt->unkC * 2) & 0x2FF;
        for (i = 0; i < globalCtx->sceneNumActorsToLoad; i++, entry++) {
            s32 phi_v0 = ((entry->rot.x & 7) * 128) | (entry->rot.z & 0x7F);

            if (phi_v0 == 0) {
                phi_v0 = 0x3FF;
            }

            if (!(phi_v0 & temp) && (actCtxt->unkC & phi_v0) && 
                (!(gSaveContext.owl.unk1 & 0x80) || !(phi_v0 & temp2) || !(entry->id & 0x800))) {
                func_800BB2D0(&globalCtx->actorCtx, entry, globalCtx);
            }
        }
        globalCtx->sceneNumActorsToLoad = -globalCtx->sceneNumActorsToLoad;
    }
}

Actor *Actor_UpdateActor(s800B948C *state) {
    GlobalContext *globalCtx = state->globalCtx;
    Actor* actor = state->actor;
    Actor *phi_v1;
    s32 temp;

    if (actor->posRot.pos.y < -25000.0f) {
        actor->posRot.pos.y = -25000.0f;
    }

    actor->sfx = 0;
    actor->unk39 &= ~(temp = 0x7F);

    if (actor->init != NULL) {
        if (Scene_IsObjectLoaded(&globalCtx->sceneContext, actor->objBankIndex)) {
            Actor_SetObjectSegment(globalCtx, actor);
            actor->init(actor, globalCtx);
            actor->init = NULL;
        }
        phi_v1 = actor->next;
    } else if (actor->update == 0) {
        if (actor->hasBeenDrawn == 0) {
            phi_v1 = func_800BB498(&globalCtx->actorCtx, actor, globalCtx);
        } else {
            Actor_Destroy(actor, globalCtx);
            phi_v1 = actor->next;
        }
    } else if (!Scene_IsObjectLoaded(&globalCtx->sceneContext, actor->objBankIndex)) {
        Actor_Kill(actor);
        phi_v1 = actor->next;
    } else if 
        (((state->updateActorIfSet != 0) && !(actor->flags & state->updateActorIfSet)) ||
        ((!state->updateActorIfSet != 0) && (!(actor->flags & 0x100000) || ((actor->type == 3) && (state->player->stateFlags1 & 0x200))) &&
        ((state->unkC != 0) && (actor != state->unk10) && (actor != state->player->heldActor) && (actor->parent != &state->player->actor)))) {
        func_800E74DC(&actor->colChkInfo);
        phi_v1 = actor->next;
    } else {
        s32 phi_v0;

        Math_Vec3f_Copy(&actor->lastPos, &actor->posRot.pos);
        actor->xzDistanceFromLink = Actor_XZDistanceBetweenActors(actor, state->player);
        actor->yDistanceFromLink = Actor_YDistance(actor, state->player);
        actor->sqrdDistanceFromLink = SQ(actor->xzDistanceFromLink) + SQ(actor->yDistanceFromLink);
        actor->yawTowardsLink = Actor_YawBetweenActors(actor, state->player);
        actor->flags &= ~0x1000000;
        if (actor->freeze == 0) {
            phi_v0 = 0;
        } else {
            actor->freeze--;
            phi_v0 = actor->freeze;
        }
        if ((phi_v0 == 0) && (actor->flags & state->runMainIfSet)) {
            if (actor == state->player->unk730) {
                actor->unk114 = 1;
            } else {
                actor->unk114 = 0;
            }
            if ((actor->unk115 != 0) && (state->player->unk730 == NULL)) {
                actor->unk115 = 0;
            }
            Actor_SetObjectSegment(globalCtx, actor);
            if (actor->hitEffectIntensity != 0) {
                actor->hitEffectIntensity--;
            }
            actor->update(actor, globalCtx);
            BgCheck_ResetFlagsIfLoadedActor(globalCtx, &globalCtx->colCtx.dyna, actor);
        }
        func_800E74DC(&actor->colChkInfo);
        phi_v1 = actor->next;
    }
    return phi_v1;
}

u32 D_801AED58[] = {
    0x100002C2, 0x100002C2, 0x00000200, 0x100006C2, 
    0x00000282, 0x300002C2, 0x10000282, 0x00000002, 
    0x300002C2, 0x100006C2, 0x00000002, 0x100002C2, 
};

void Actor_UpdateAll(GlobalContext *globalCtx, ActorContext *actCtxt) {
    Player* player = PLAYER;
    s32 i;
    Actor* next;
    Actor* thisActor;
    s32 type;
    u32* flags;
    ActorListEntry* actorEntry;
    s800B948C state;

    state.globalCtx = globalCtx;
    state.player = player;

    if (globalCtx->unk18844 != 0) {
        state.runMainIfSet = 0x200000;
    } else {
        state.runMainIfSet = 0x200050;
    }

    func_800B9334(globalCtx, actCtxt);

    if (actCtxt->unk2 != 0) {
        actCtxt->unk2--;
    }

    flags = &D_801AED58[0];

    if (player->stateFlags2 & 0x8000000) {
        state.updateActorIfSet = 0x2000000;
    } else {
        state.updateActorIfSet = 0;
    }

    if ((player->stateFlags1 & 0x40) && ((player->actor.textId & 0xFF00) != 0x1900)) {
        state.unk10 = player->targetActor;
    } else {
        state.unk10 = NULL;
    }

    for (i = 0, actorEntry = &actCtxt->actorList[0]; i < 12; i++) {
        state.unkC = player->stateFlags1 & *flags;
        state.actor = actorEntry->first;
        while (state.actor != NULL) {
            state.actor = Actor_UpdateActor(&state);
        }

        if (i == ACTORTYPE_BG) {
            BgCheck_Update(globalCtx, &globalCtx->colCtx.dyna);
        }
        actorEntry++;
        flags++;
    }

    for (i = 0, actorEntry = &actCtxt->actorList[0]; i < 12; i++, actorEntry++) {
        if (actorEntry->unk8 != 0) {
            thisActor = actorEntry->first;

            while (thisActor != NULL) {
                if (thisActor->type == i) {
                    thisActor = thisActor->next;
                    continue;
                }

                next = thisActor->next;
                type = thisActor->type;
                thisActor->type = i;
                Actor_RemoveFromTypeList(globalCtx, actCtxt, thisActor);
                Actor_InsertIntoTypeList(actCtxt, thisActor, type);
                thisActor = next;
            }
            actorEntry->unk8 = 0;
        }
    }

    thisActor = player->unk730;
    if ((thisActor != NULL) && (thisActor->update == NULL)) {
        thisActor = NULL;
        func_80123DA4(player);
    }

    if ((thisActor == NULL) || (player->unk738 < 5)) {
        thisActor = NULL;
        if (actCtxt->targetContext.unk_4B != 0) {
            actCtxt->targetContext.unk_4B = 0;
            play_sound(0x480F);
        }
    }

    if (!(player->stateFlags1 & 2)) {
        func_800B5814(&actCtxt->targetContext, player, thisActor, globalCtx);
    }

    Actor_TitleCardUpdate(globalCtx, &actCtxt->titleCtxt);
    func_800B6474(globalCtx);
    BgCheck_UpdateAllActorMeshes(globalCtx, &globalCtx->colCtx.dyna);
}

void Actor_DrawActor(GlobalContext* globalCtx, Actor* actor) {
    Lights* lights;

    OPEN_DISPS(globalCtx->state.gfxCtx);

    lights = LightContext_NewLights(&globalCtx->lightCtx, globalCtx->state.gfxCtx);

    if ((actor->flags & 0x10000000) &&
       ((globalCtx->roomContext.currRoom.enablePosLights != 0) || (MREG(93) != 0))) {
        lights->enablePosLights = 1;
    }

    Lights_BindAll(lights, globalCtx->lightCtx.listHead, (actor->flags & 0x10400000) ? NULL : &actor->posRot.pos, globalCtx);
    Lights_Draw(lights, globalCtx->state.gfxCtx);

    if (actor->flags & 0x1000) {
        SysMatrix_SetStateRotationAndTranslation(
            actor->posRot.pos.x + globalCtx->mainCamera.unk80.x,
            actor->posRot.pos.y + ((actor->shape.yDisplacement * actor->scale.y) + globalCtx->mainCamera.unk80.y),
            actor->posRot.pos.z + globalCtx->mainCamera.unk80.z, &actor->shape.rot);
    } else {
        SysMatrix_SetStateRotationAndTranslation(
            actor->posRot.pos.x, 
            actor->posRot.pos.y + (actor->shape.yDisplacement * actor->scale.y),
            actor->posRot.pos.z, &actor->shape.rot);
    }

    SysMatrix_InsertScale(actor->scale.x, actor->scale.y, actor->scale.z, MTXMODE_APPLY);
    Actor_SetObjectSegment(globalCtx, actor);

    gSPSegment(oGfxCtx->polyOpa.p++, 0x06, globalCtx->sceneContext.objects[actor->objBankIndex].vramAddr);
    gSPSegment(oGfxCtx->polyXlu.p++, 0x06, globalCtx->sceneContext.objects[actor->objBankIndex].vramAddr);

    if (actor->hitEffectIntensity != 0) {
        s32 flag = actor->hitEffectParams;
        ColorRGBA8 sp2C = { 0, 0, 0, 255 };

        flag &= 0xC000;

        if (flag == 0x8000) {
            sp2C.red = sp2C.green = sp2C.blue = ((actor->hitEffectParams & 0x1F00) >> 5) | 7;
        } else if (flag == 0x4000) {
            sp2C.red = ((actor->hitEffectParams & 0x1F00) >> 5) | 7;
        } else if (flag == 0xC000) {
            sp2C.red = 0;
            sp2C.green = 0;
            sp2C.blue = 0;
        } else {
            sp2C.blue = ((actor->hitEffectParams & 0x1F00) >> 5) | 7;
        }

        if (actor->hitEffectParams & 0x2000) {
            func_800AE778(globalCtx, &sp2C, actor->hitEffectIntensity, actor->hitEffectParams & 0xFF);
        } else {
            func_800AE434(globalCtx, &sp2C, actor->hitEffectIntensity, actor->hitEffectParams & 0xFF);
        }
    }

    actor->draw(actor, globalCtx);

    if (actor->hitEffectIntensity != 0) {
        if (actor->hitEffectParams & 0x2000) {
            func_800AE8EC(globalCtx);
        } else {
            func_800AE5A0(globalCtx);
        }
    }

    if (actor->shape.shadowDrawFunc != NULL) {
        actor->shape.shadowDrawFunc(actor, lights, globalCtx);
    }

    actor->hasBeenDrawn = 1;

    CLOSE_DISPS(globalCtx->state.gfxCtx);
}

void func_800B9D1C(Actor *actor) {
    s32 sfx = actor->sfx;

    if (sfx != 0) {
        if (actor->unk39 & 2) {
            func_801A5CFC(sfx, &actor->projectedPos, 4, &D_801DB4B0, &D_801DB4B0, &D_801DB4B8);
        } else if (actor->unk39 & 4) {
            play_sound(sfx);
        } else if (actor->unk39 & 8) {
            func_8019F128(sfx);
        } else if (actor->unk39 & 0x10) {
            func_801A0810(&D_801DB4A4, 0x2021, sfx - 1);
        } else if (actor->unk39 & 1) {
            func_8019F1C0(&actor->projectedPos, sfx);
        }
    }

    if (actor->unk39 & 0x40) {
        func_801A1FB4(3, &actor->projectedPos, 0x27, 1500.0f);
    }

    if (sfx){};

    if (actor->unk39 & 0x20) {
        func_801A1FB4(0, &actor->projectedPos, 0x71, 900.0f);
    }
}

void Actor_DrawAllSetup(GlobalContext* globalCtx) {
    globalCtx->actorCtx.undrawnActorCount = 0;
    globalCtx->actorCtx.unkB = 0;
}

s32 Actor_RecordUndrawnActor(GlobalContext *globalCtx, Actor *actor) {
    if (globalCtx->actorCtx.undrawnActorCount >= 0x20) {
        return 0;
    }
    globalCtx->actorCtx.undrawnActors[globalCtx->actorCtx.undrawnActorCount] = actor;
    globalCtx->actorCtx.undrawnActorCount++;
    return 1;
}

void func_800B9E84(Gfx* gfx, s32 arg1) {
    func_80164C14(gfx, &D_801DE890, 4, 0, 6, 6, ((100 - arg1) * 0.003f) + 1.0f);
}

#ifdef NON_MATCHING
void func_800B9EF4(GlobalContext *globalCtx, s32 numActors, Actor **invisibleActors) {
    Actor** invisibleActor;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    s32 i;
    Gfx* polyXlu;

    OPEN_DISPS(gfxCtx);

    if ((numActors > 0) != 0) {
        void* zBuff = oGfxCtx->zbuffer;
        polyXlu = oGfxCtx->polyXlu.p;

        func_8016FD60(&globalCtx->unk18B4C, D_801FBBCC, D_801FBBCE, oGfxCtx->framebuffer, zBuff);
        func_80170200(&globalCtx->unk18B4C, &polyXlu, zBuff, globalCtx->unk18E68);
        
        gDPPipeSync(polyXlu++);
        gDPSetPrimDepth(polyXlu++, 0, 0);
        gDPSetOtherMode(polyXlu++, G_AD_DISABLE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE | G_PM_NPRIMITIVE, G_AC_THRESHOLD | G_ZS_PRIM | Z_UPD | IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c1(G_BL_CLR_BL, G_BL_0, G_BL_CLR_MEM, G_BL_1MA) | GBL_c2(G_BL_CLR_BL, G_BL_0, G_BL_CLR_MEM, G_BL_1MA));
        gDPSetPrimColor(polyXlu++, 0, 0, 0, 0, 0, 255);

        if (globalCtx->roomContext.currRoom.unk5 == 0) {
            gDPSetCombineLERP(polyXlu++, 1, TEXEL0, PRIMITIVE, 0, 1, TEXEL0, PRIMITIVE, 0, 1, TEXEL0, PRIMITIVE, 0, 1, TEXEL0, PRIMITIVE, 0);
        } else {
            gDPSetCombineMode(polyXlu++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        }

        func_800B9E84(&polyXlu, globalCtx->actorCtx.unk4);
        polyXlu = func_801660B8(globalCtx, polyXlu);

        invisibleActor = &invisibleActors[0];
        for (i = 0; i != numActors; i++) {
            oGfxCtx->polyXlu.p = polyXlu;
            Actor_DrawActor(globalCtx, *(invisibleActor++));
            polyXlu = oGfxCtx->polyXlu.p;
        }

        gDPPipeSync(polyXlu++);
        gDPSetOtherMode(polyXlu++, G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE | G_PM_NPRIMITIVE, G_AC_THRESHOLD | G_ZS_PRIM | AA_EN | IM_RD | CVG_DST_WRAP | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_MEM, G_BL_1) | GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_MEM, G_BL_1));
        gDPSetBlendColor(polyXlu++, 255, 255, 255, 0);
        gDPSetPrimColor(polyXlu++, 0, 0xFF, 0, 0, 0, 32);

        if (globalCtx->roomContext.currRoom.unk5 == 0) {
            gDPSetCombineMode(polyXlu++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        } else {
            gDPSetCombineLERP(polyXlu++, 1, TEXEL0, PRIMITIVE, 0, 1, TEXEL0, PRIMITIVE, 0, 1, TEXEL0, PRIMITIVE, 0, 1, TEXEL0, PRIMITIVE, 0);
        }

        gDPSetColorImage(polyXlu++, G_IM_FMT_RGBA, G_IM_SIZ_16b, globalCtx->unk18B4C.unk00, globalCtx->unk18E68);

        func_800B9E84(&polyXlu, globalCtx->actorCtx.unk4);

        gDPPipeSync(polyXlu++);
        gDPSetBlendColor(polyXlu++, 255, 255, 255, 8);
        gDPSetColorImage(polyXlu++, G_IM_FMT_RGBA, G_IM_SIZ_16b, globalCtx->unk18B4C.unk00, globalCtx->unk18B5C);

        func_8016FDB8(&globalCtx->unk18B4C, &polyXlu, globalCtx->unk18E68, zBuff, 1);
    }
        
    polyXlu = oGfxCtx->polyXlu.p;
    gDPPipeSync(polyXlu++);
    gDPSetOtherMode(polyXlu++, G_AD_DISABLE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_NONE | G_TL_TILE | G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE | G_PM_NPRIMITIVE, G_AC_THRESHOLD | G_ZS_PRIM | G_RM_CLD_SURF | G_RM_CLD_SURF2);
    gDPSetCombineLERP(polyXlu++, 1, TEXEL0, PRIMITIVE, 0, 1, TEXEL0, PRIMITIVE, 0, 1, TEXEL0, PRIMITIVE, 0, 1, TEXEL0, PRIMITIVE, 0);
    gDPSetPrimColor(polyXlu++, 0, 0, 74, 0, 0, 74);

    func_800B9E84(&polyXlu, globalCtx->actorCtx.unk4);

    CLOSE_DISPS(gfxCtx);
}
#else
GLOBAL_ASM("asm/non_matchings/z_actor//func_800B9EF4.asm")
#endif

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
