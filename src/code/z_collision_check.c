#include "ultra64.h"
#include "global.h"

DamageTable gDamageTables[23] = {
    {
    0x10, 0x01, 0x01, 0x02, 
    0xE0, 0x01, 0xF2, 0x10, 
    0xF1, 0xF2, 0xF2, 0x22, 
    0x01, 0x01, 0x00, 0x00, 
    0x00, 0x22, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0x02, 
    0x02, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x10, 0x01, 0x01, 0x02, 
    0xE0, 0x01, 0xF2, 0x10, 
    0xF1, 0xF2, 0xF2, 0x22, 
    0x01, 0x01, 0x00, 0x00, 
    0x00, 0x22, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0x02, 
    0x02, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x10, 0x02, 0x01, 0x02, 
    0x10, 0x02, 0x02, 0x02, 
    0x01, 0x02, 0x04, 0x04, 
    0x04, 0x04, 0x00, 0x00, 
    0x00, 0x04, 0x03, 0x00, 
    0x00, 0x00, 0x01, 0x02, 
    0x04, 0x02, 0x04, 0x08, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x10, 0x01, 0x01, 0x02, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    0x00, 0x00, 0x02, 0x02, 
    0x02, 0x02, 0x02, 0x02, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x10, 0x02, 0x01, 0x02, 
    0x01, 0x02, 0x02, 0x02, 
    0x01, 0x02, 0x04, 0x04, 
    0x04, 0x04, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0x02, 
    0x04, 0x02, 0x04, 0x08, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x10, 0x01, 0x01, 0x00, 
    0x10, 0x01, 0x01, 0x10, 
    0x01, 0x01, 0x01, 0x01, 
    0x31, 0x01, 0x00, 0x00, 
    0x00, 0x00, 0x31, 0x00, 
    0x00, 0x00, 0x01, 0x01, 
    0x01, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x00, 0x03, 0x00, 0x06, 
    0x00, 0x04, 0x04, 0x00, 
    0x02, 0x06, 0x00, 0x06, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x04, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x00, 0x03, 0x00, 0x06, 
    0x00, 0x04, 0x04, 0x00, 
    0x02, 0x06, 0x00, 0x06, 
    0x06, 0x00, 0x00, 0x00, 
    0x00, 0x04, 0x04, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x00, 0x03, 0x00, 0x00, 
    0x00, 0x04, 0x04, 0x00, 
    0x02, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x04, 0x04, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x00, 0x02, 0x00, 0x00, 
    0x01, 0x00, 0x02, 0x02, 
    0x01, 0x02, 0x04, 0x00, 
    0x04, 0x00, 0x00, 0x00, 
    0x00, 0x04, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0x02, 
    0x04, 0x02, 0x04, 0x08, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x10, 0x01, 0x00, 0xE2, 
    0x10, 0x01, 0x02, 0x10, 
    0xF1, 0xF2, 0xF2, 0x22, 
    0x32, 0x01, 0x00, 0x00, 
    0x00, 0x22, 0x32, 0x00, 
    0x00, 0x00, 0x01, 0x02, 
    0x02, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x09, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x00, 0x01, 0x00, 0x00, 
    0x00, 0x04, 0x04, 0x00, 
    0x02, 0x04, 0x04, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x04, 0x04, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x10, 0x01, 0x01, 0x02, 
    0x10, 0x01, 0x02, 0x10, 
    0x01, 0x02, 0x02, 0x22, 
    0x01, 0x01, 0x00, 0x00, 
    0x00, 0x22, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0x01, 
    0x01, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x01, 0x02, 0x01, 0x02, 
    0x01, 0x02, 0x02, 0x02, 
    0x01, 0x02, 0x04, 0x04, 
    0x04, 0x04, 0x00, 0x00, 
    0x00, 0x04, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0x02, 
    0x04, 0x02, 0x04, 0x08, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x00, 0x02, 0x01, 0x02, 
    0x01, 0x02, 0x02, 0x02, 
    0x01, 0x02, 0x04, 0x04, 
    0x04, 0x04, 0x00, 0x00, 
    0x00, 0x04, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0x02, 
    0x04, 0x02, 0x04, 0x08, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x10, 0x01, 0x00, 0x02, 
    0x10, 0x01, 0x02, 0x10, 
    0xF1, 0xF2, 0xF2, 0x22, 
    0x32, 0x01, 0x00, 0x00, 
    0x00, 0x22, 0x32, 0x00, 
    0x00, 0x00, 0x01, 0x02, 
    0x02, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x10, 0x01, 0x01, 0xF2, 
    0xE0, 0x01, 0xD2, 0x10, 
    0x01, 0x02, 0x02, 0x00, 
    0x32, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x32, 0x00, 
    0x00, 0x00, 0x01, 0x02, 
    0x02, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x10, 0x01, 0x00, 0xF0, 
    0x10, 0x01, 0xF0, 0x10, 
    0x01, 0x02, 0x02, 0x00, 
    0x12, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x12, 0x00, 
    0x00, 0x00, 0x01, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    },
    {
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 
    },
};

f32 Collision_GetDamageAndEffectOnBumper(Collider *toucher, ColliderBody *toucherBody, Collider *bumper, ColliderBody *bumperBody, s32 *effect) {
    static f32 gDamageMultipliers[] = {
        0.0f, 
        1.0f, 
        2.0f, 
        0.5f, 
        0.25f, 
        3.0f, 
        4.0f, 
        1.0f, 
        1.0f, 
        1.0f, 
        1.0f, 
        1.0f, 
        1.0f, 
        1.0f, 
        1.0f, 
        1.0f, 
    };

    DamageTable *damageTable;
    f32 toucherDamage;

    *effect = 0;
    toucherDamage = (s32)Collision_GetToucherDamage(toucher, toucherBody, bumper, bumperBody);
    damageTable = bumper->actor->colChkInfo.damageTable;

    if (damageTable != NULL) {
        u8 damage;
        u32 colliding = toucherBody->toucher.collidesWith;
        s32 i;
        
        for (i = 0; i < 32; i++, colliding >>= 1) {
            if (colliding == 1) {
                break;
            }
        }

        toucherDamage *= gDamageMultipliers[damageTable->attack[i] & 0xF];
        *effect = (damageTable->attack[i] >> 4) & 0xF;
    }

    return toucherDamage;
}

f32 func_800E04BC(f32 arg0, ColliderBody *rightBody) {
    f32 res = arg0 - rightBody->bumper.defense;
    return res;
}

u8 Collision_GetToucherDamage(Collider *toucher, ColliderBody *toucherBody, Collider *bumper, ColliderBody *bumperBody) {
    Actor *touchActor = toucher->actor;

    if ((touchActor != NULL) && (touchActor->id == ACTOR_EN_BOM)) {
        Actor* bumpActor = bumper->actor;
        if ((bumpActor != NULL) && (bumpActor->id == ACTOR_PLAYER)) {
            return 8;
        }
    }

    return toucherBody->toucher.damage;
}

s32 Collider_InitBase(GlobalContext *ctxt, Collider *collider) {
    static Collider init = { NULL, NULL, NULL, NULL, 0, 0, 0, 0, COLTYPE_UNK3, COLSHAPE_INVALID };
    
    *collider = init;
    
    return 1;
}

s32 Collider_DestroyBase(GlobalContext *ctxt, Collider *collider) {
    return 1;
}

s32 Collider_SetBase_Actor(GlobalContext *ctxt, Collider *collider, ColliderInit_Actor *src) {
    collider->actor = src->actor;
    collider->atFlags = src->atFlags;
    collider->acFlags = src->acFlags;
    collider->maskA = src->maskA;
    collider->maskB = 0x10;
    collider->shape = src->shape;
    return 1;
}

s32 Collider_SetBase_Set3(GlobalContext *globalCtx, Collider *collider, Actor *actor, ColliderInit_Set3 *src) {
    collider->actor = actor;
    collider->type = src->type;
    collider->atFlags = src->atFlags;
    collider->acFlags = src->acFlags;
    collider->maskA = src->maskA;
    collider->maskB = 0x10;
    collider->shape = src->shape;
    return 1;
}

s32 Collider_SetBase(GlobalContext *globalCtx, Collider *collider, Actor *actor, ColliderInit *init) {
    collider->actor = actor;
    collider->type = init->type;
    collider->atFlags = init->atFlags;
    collider->acFlags = init->acFlags;
    collider->maskA = init->maskA;
    collider->maskB = init->maskB;
    collider->shape = init->shape;
    return 1;
}

void Collider_BaseSetAT(GlobalContext *globalCtx, Collider *collider) {
    collider->at = NULL;
    collider->atFlags &= ~0x6;
}

void Collider_BaseSetAC(GlobalContext *globalCtx, Collider *collider) {
    collider->ac = NULL;
    collider->acFlags &= ~0x82;
}

void Collider_BaseSetOC(GlobalContext *globalCtx, Collider *collider) {
    collider->oc = NULL;
    collider->maskA &= ~0x2;
    collider->maskB &= ~0x1;
}

s32 Collider_InitTouch(GlobalContext *globalCtx, ColliderTouch *touch) {
    static ColliderTouch init = { 0, 0, 0 };

    *touch = init;
    return 1;
}

s32 Collider_DestroyTouch(GlobalContext *globalCtx, ColliderTouch *touch) {
    return 1;
}

s32 Collider_SetTouch(GlobalContext *globalCtx, ColliderTouch *touch, ColliderTouch *src) {
    touch->collidesWith = src->collidesWith;
    touch->effect = src->effect;
    touch->damage = src->damage;
    return 1;
}

void Collider_BodySetAT_Unk(GlobalContext *globalCtx, ColliderBody *body) {

}

s32 Collider_InitBump(GlobalContext *globalCtx, ColliderBump *bump) {
    static ColliderBump init = { 0xF7CFFFFF, 0, 0, { 0, 0, 0 } };

    *bump = init;
    return 1;
}

s32 Collider_DestroyBump(GlobalContext *globalCtx, ColliderBump *bump) {
    return 1;
}

s32 Collider_SetBump(GlobalContext *globalCtx, ColliderBump *bump, ColliderBumpInit *init) {
    bump->collidesWith = init->flags;
    bump->effect = init->effect;
    bump->defense = init->defense;
    return 1;
}

s32 Collider_InitBody(GlobalContext *globalCtx, ColliderBody *body) {
    static ColliderBody init = {
        { 0, 0, 0 }, { 0xF7CFFFFF, 0, 0, { 0, 0, 0 } }, 0, 0, 0, 0, NULL, NULL, NULL, NULL,
    };
    
    *body = init;
    Collider_InitTouch(globalCtx, &body->toucher);
    Collider_InitBump(globalCtx, &body->bumper);
    return 1;
}

s32 Collider_DestroyBody(GlobalContext *globalCtx, ColliderBody *body) {
    Collider_DestroyTouch(globalCtx, &body->toucher);
    Collider_DestroyBump(globalCtx, &body->bumper);
    return 1;
}

s32 Collider_SetBody(GlobalContext *globalCtx, ColliderBody *body, ColliderBodyInit *init) {
    body->flags = init->bodyFlags;
    Collider_SetTouch(globalCtx, &body->toucher, &init->toucher);
    Collider_SetBump(globalCtx, &body->bumper, &init->bumper);
    body->toucherFlags = init->toucherFlags;
    body->bumperFlags = init->bumperFlags;
    body->ocFlags = init->bodyFlags2;
    return 1;
}

void Collider_BodySetAT(GlobalContext* globalCtx, ColliderBody* body) {
    body->atHit = NULL;
    body->atHitItem = NULL;
    body->toucherFlags &= ~0x2;
    body->toucherFlags &= ~0x40;
    Collider_BodySetAT_Unk(globalCtx, body);
}

void Collider_BodySetAC(GlobalContext* globalCtx, ColliderBody* body) {
    body->bumper.unk_06.z = 0;
    body->bumperFlags &= ~0x2;
    body->bumperFlags &= ~0x80;
    body->acHit = NULL;
    body->acHitItem = NULL;
    body->bumper.unk_06.y = body->bumper.unk_06.z;
    body->bumper.unk_06.x = body->bumper.unk_06.z;
}

void Collider_BodySetOC(GlobalContext* globalCtx, ColliderBody* body) {
    body->ocFlags &= ~0x2;
}

s32 Collider_InitJntSphItemDim(GlobalContext *globalCtx, ColliderJntSphItemDim *dim) {
    static ColliderJntSphItemDim init = { 0 };

    *dim = init;
    return 1;
}

s32 Collider_DestroyJntSphItemDim(GlobalContext* globalCtx, ColliderJntSphItemDim* item) {
    return 1;
}

extern f32 D_801DD5C0; // 0.01f; RODATA FIX
s32 Collider_SetJntSphItemDim(GlobalContext *globalCtx, ColliderJntSphItemDim *dim, ColliderJntSphItemDimInit *init) {
    dim->joint = init->joint;
    dim->modelSphere = init->modelSphere;
    dim->scale = init->scale * D_801DD5C0;
    return 1;
}

s32 Collider_InitJntSphItem(GlobalContext *globalCtx, ColliderJntSphItem *item) {
    Collider_InitBody(globalCtx, &item->body);
    Collider_InitJntSphItemDim(globalCtx, &item->dim);
    return 1;
}

s32 Collider_DestroyJntSphItem(GlobalContext* globalCtx, ColliderJntSphItem* item) {
    Collider_DestroyBody(globalCtx, &item->body);
    Collider_DestroyJntSphItemDim(globalCtx, &item->dim);
    return 1;
}

s32 Collider_SetJntSphItem(GlobalContext* globalCtx, ColliderJntSphItem* item, ColliderJntSphItemInit* init) {
    Collider_SetBody(globalCtx, &item->body, &init->body);
    Collider_SetJntSphItemDim(globalCtx, &item->dim, &init->dim);
    return 1;
}

s32 Collider_JntSphItemSetAT(GlobalContext *globalCtx, ColliderJntSphItem *item) {
    Collider_BodySetAT(globalCtx, &item->body);
    return 1;
}

s32 Collider_JntSphItemSetAC(GlobalContext *globalCtx, ColliderJntSphItem *item) {
    Collider_BodySetAC(globalCtx, &item->body);
    return 1;
}

s32 Collider_JntSphItemSetOC(GlobalContext *globalCtx, ColliderJntSphItem *item) {
    Collider_BodySetOC(globalCtx, &item->body);
    return 1;
}

s32 Collider_InitJntSph(GlobalContext *globalCtx, ColliderJntSph *collider) {
    Collider_InitBase(globalCtx, &collider->base);
    collider->count = 0;
    collider->list = NULL;
    return 1;
}

s32 Collider_FreeJntSph(GlobalContext* globalCtx, ColliderJntSph* collider) {
    ColliderJntSphItem* next;

    Collider_DestroyBase(globalCtx, &collider->base);
    next = collider->list;

    while (next < collider->list + collider->count) {
        Collider_DestroyJntSphItem(globalCtx, next);
        next++;
    }

    collider->count = 0;
    if (collider->list != NULL) {
        zelda_free(collider->list);
    }
    collider->list = NULL;
    return 1;
}

s32 Collider_DestroyJntSph(GlobalContext *globalCtx, ColliderJntSph *collider) {
    ColliderJntSphItem* next;

    Collider_DestroyBase(globalCtx, &collider->base);
    next = collider->list;

    while (next < collider->list + collider->count) {

        Collider_DestroyJntSphItem(globalCtx, next);
        next++;
    }
    collider->count = 0;
    collider->list = NULL;
    return 1;
}

s32 Collider_SetJntSph_Set(GlobalContext* globalCtx, ColliderJntSph* collider, ColliderJntSphInit_Actor* init) {
    ColliderJntSphItem* colliderNext;
    ColliderJntSphItemInit* initNext;

    Collider_SetBase_Actor(globalCtx, &collider->base, &init->base);
    collider->count = init->count;
    collider->list = zelda_malloc(init->count * sizeof(ColliderJntSphItem));

    if (collider->list == NULL) {
        collider->count = 0;
        return 0;
    }

    colliderNext = collider->list;
    initNext = init->list;

    while (colliderNext < collider->list + collider->count) {
        Collider_InitJntSphItem(globalCtx, colliderNext);
        Collider_SetJntSphItem(globalCtx, colliderNext, initNext);
        colliderNext++;
        initNext++;
    }
    return 1;
}

s32 Collider_SetJntSph_Set3(GlobalContext *globalCtx, ColliderJntSph *collider, Actor *actor, ColliderJntSphInit_Set3 *init) {
    ColliderJntSphItem* colliderNext;
    ColliderJntSphItemInit* initNext;

    Collider_SetBase_Set3(globalCtx, &collider->base, actor, &init->base);
    collider->count = init->count;
    collider->list = zelda_malloc(init->count * sizeof(ColliderJntSphItem));

    if (collider->list == NULL) {
        collider->count = 0;
        return 0;
    }

    colliderNext = collider->list;
    initNext = init->list;

    while (colliderNext < collider->list + collider->count) {
        Collider_InitJntSphItem(globalCtx, colliderNext);
        Collider_SetJntSphItem(globalCtx, colliderNext, initNext);
        colliderNext++;
        initNext++;
    }
    return 1;
}

s32 Collider_SetJntSph(GlobalContext *globalCtx, ColliderJntSph *collider, Actor *actor, ColliderJntSphInit *init, ColliderJntSphItem *list) {
    ColliderJntSphItem* colliderNext;
    ColliderJntSphItemInit* initNext;

    Collider_SetBase(globalCtx, &collider->base, actor, &init->base);
    collider->count = init->count;
    collider->list = list;

    colliderNext = collider->list;
    initNext = init->list;

    while (colliderNext < collider->list + collider->count) {
        Collider_InitJntSphItem(globalCtx, colliderNext);
        Collider_SetJntSphItem(globalCtx, colliderNext, initNext);
        colliderNext++;
        initNext++;
    }
    return 1;
}

s32 Collision_InitSphereGroup(GlobalContext *globalCtx, ColliderJntSph *collider, Actor *actor, ColliderJntSphInit *init, ColliderJntSphItem *list) {
    Collider_InitJntSph(globalCtx, collider);
    Collider_SetJntSph(globalCtx, collider, actor, init, list);
    return 0;
}

s32 Collider_JntSphSetAT(GlobalContext *globalCtx, Collider *collider) {
    ColliderJntSphItem* next;
    ColliderJntSph* spheres = (ColliderJntSph*)collider;

    Collider_BaseSetAT(globalCtx, &spheres->base);
    next = spheres->list;

    while (next < spheres->list + spheres->count) {
        Collider_JntSphItemSetAT(globalCtx, next);
        next++;
    }
    return 1;
}

s32 Collider_JntSphSetAC(GlobalContext* globalCtx, Collider* collider) {
    ColliderJntSphItem* next;
    ColliderJntSph* spheres = (ColliderJntSph*)collider;

    Collider_BaseSetAC(globalCtx, &spheres->base);
    next = spheres->list;

    while (next < spheres->list + spheres->count) {
        Collider_JntSphItemSetAC(globalCtx, next);
        next++;
    }
    return 1;
}

s32 Collider_JntSphSetOC(GlobalContext* globalCtx, Collider* collider) {
    ColliderJntSphItem* next;
    ColliderJntSph* spheres = (ColliderJntSph*)collider;

    Collider_BaseSetOC(globalCtx, &spheres->base);
    next = spheres->list;
    
    while (next < spheres->list + spheres->count) {
        Collider_JntSphItemSetOC(globalCtx, next);
        next++;
    }
    return 1;
}

s32 Collider_InitCylinderDim(GlobalContext* globalCtx, Cylinder16* dim) {
    static Cylinder16 init = { 0 };
    *dim = init;
    return 1;
}

s32 Collider_DestroyCylinderDim(GlobalContext* globalCtx, Cylinder16* dim) {
    return 1;
}

s32 Collider_SetCylinderDim(GlobalContext* globalCtx, Cylinder16* dest, Cylinder16* src) {
    *dest = *src;
    return 1;
}

s32 Collider_InitCylinder(GlobalContext *globalCtx, ColliderCylinder *cylinder) {
    Collider_InitBase(globalCtx, &cylinder->base);
    Collider_InitBody(globalCtx, &cylinder->body);
    Collider_InitCylinderDim(globalCtx, &cylinder->dim);
    return 1;
}


s32 Collider_DestroyCylinder(GlobalContext* globalCtx, ColliderCylinder* collider) {
    Collider_DestroyBase(globalCtx, &collider->base);
    Collider_DestroyBody(globalCtx, &collider->body);
    Collider_DestroyCylinderDim(globalCtx, &collider->dim);
    return 1;
}

s32 Collider_SetCylinder_Actor(GlobalContext *globalCtx, ColliderCylinder *collider, ColliderCylinderInit_Actor *init) {
    Collider_SetBase_Actor(globalCtx, &collider->base, &init->base);
    Collider_SetBody(globalCtx, &collider->body, &init->body);
    Collider_SetCylinderDim(globalCtx, &collider->dim, &init->dim);
    return 1;
}

s32 Collider_SetCylinder_Set3(GlobalContext *globalCtx, ColliderCylinder *collider, Actor *actor, ColliderCylinderInit_Set3 *init) {
    Collider_SetBase_Set3(globalCtx, &collider->base, actor, &init->base);
    Collider_SetBody(globalCtx, &collider->body, &init->body);
    Collider_SetCylinderDim(globalCtx, &collider->dim, &init->dim);
    return 1;
}

s32 Collider_SetCylinder(GlobalContext *globalCtx, ColliderCylinder *cylinder, Actor *actor, ColliderCylinderInit *init) {
    Collider_SetBase(globalCtx, &cylinder->base, actor, &init->base);
    Collider_SetBody(globalCtx, &cylinder->body, &init->body);
    Collider_SetCylinderDim(globalCtx, &cylinder->dim, &init->dim);
    return 1;
}

s32 Collision_InitCylinder(GlobalContext *globalCtx, ColliderCylinder *cylinder, Actor *actor, ColliderCylinderInit *init) {
    Collider_InitCylinder(globalCtx, cylinder);
    Collider_SetCylinder(globalCtx, cylinder, actor, init);
    return 1;
}

s32 Collider_CylinderSetAT(GlobalContext* globalCtx, Collider* collider) {
    ColliderCylinder* cylinder = (ColliderCylinder*)collider;

    Collider_BaseSetAT(globalCtx, &cylinder->base);
    Collider_BodySetAT(globalCtx, &cylinder->body);
    return 1;
}

s32 Collider_CylinderSetAC(GlobalContext* globalCtx, Collider* collider) {
    ColliderCylinder* cylinder = (ColliderCylinder*)collider;
    
    Collider_BaseSetAC(globalCtx, &cylinder->base);
    Collider_BodySetAC(globalCtx, &cylinder->body);
    return 1;
}

s32 Collider_CylinderSetOC(GlobalContext* globalCtx, Collider* collider) {
    ColliderCylinder* cylinder = (ColliderCylinder*)collider;
    
    Collider_BaseSetOC(globalCtx, &cylinder->base);
    Collider_BodySetOC(globalCtx, &cylinder->body);
    return 1;
}

s32 Collider_InitTrisItemDim(GlobalContext* globalCtx, TriNorm* dim) {
    static TriNorm init = { 0 };

    *dim = init;
    return 1;
}

s32 Collider_DestroyTrisItemDim(GlobalContext* globalCtx, TriNorm* dim) {
    return 1;
}

s32 Collider_SetTrisItemDim(GlobalContext* globalCtx, TriNorm* dim, ColliderTrisItemDimInit* init) {
    Vec3f* d;
    Vec3f* s;
    f32 nx, ny, nz, nd;

    d = dim->vtx;
    s = init->vtx;
    while (d < dim->vtx + 3) {
        *d++ = *s++;
    }

    Math3D_UnitNormalVector(&init->vtx[0], &init->vtx[1], &init->vtx[2], &nx, &ny, &nz, &nd);

    dim->plane.normal.x = nx;
    dim->plane.normal.y = ny;
    dim->plane.normal.z = nz;
    dim->plane.originDist = nd;
    return 1;
}

s32 Collider_InitTrisItem(GlobalContext* globalCtx, ColliderTrisItem* item) {
    Collider_InitBody(globalCtx, &item->body);
    Collider_InitTrisItemDim(globalCtx, &item->dim);
    return 1;
}

s32 Collider_DestroyTrisItem(GlobalContext* globalCtx, ColliderTrisItem* item) {
    Collider_DestroyBody(globalCtx, &item->body);
    Collider_DestroyTrisItemDim(globalCtx, &item->dim);
    return 1;
}

s32 Collider_SetTrisItem(GlobalContext* globalCtx, ColliderTrisItem* item, ColliderTrisItemInit* init) {
    Collider_SetBody(globalCtx, &item->body, &init->body);
    Collider_SetTrisItemDim(globalCtx, &item->dim, &init->dim);
    return 1;
}

s32 Collider_TrisItemSetAT(GlobalContext* globalCtx, ColliderTrisItem* item) {
    Collider_BodySetAT(globalCtx, &item->body);
    return 1;
}

s32 Collider_TrisItemSetAC(GlobalContext* globalCtx, ColliderTrisItem* item) {
    Collider_BodySetAC(globalCtx, &item->body);
    return 1;
}

s32 Collider_TrisItemSetOC(GlobalContext* globalCtx, ColliderTrisItem* item) {
    Collider_BodySetOC(globalCtx, &item->body);
    return 1;
}

s32 Collider_InitTris(GlobalContext* globalCtx, ColliderTris* tris) {
    Collider_InitBase(globalCtx, &tris->base);
    tris->count = 0;
    tris->list = 0;
    return 1;
}

s32 Collider_FreeTris(GlobalContext* globalCtx, ColliderTris* tris) {
    ColliderTrisItem* next;

    Collider_DestroyBase(globalCtx, &tris->base);
    next = tris->list;

    while (next < tris->list + tris->count) {
        Collider_DestroyTrisItem(globalCtx, next);
        next++;
    }

    tris->count = 0;
    if (tris->list != NULL) {
        zelda_free(tris->list);
    }
    tris->list = NULL;
    return 1;
}

s32 Collider_DestroyTris(GlobalContext* globalCtx, ColliderTris* tris) {
    ColliderTrisItem* next;

    Collider_DestroyBase(globalCtx, &tris->base);
    next = tris->list;

    while (next < tris->list + tris->count) {
        Collider_DestroyTrisItem(globalCtx, next);
        next++;
    }
    tris->count = 0;
    tris->list = NULL;
    return 1;
}

s32 Collider_SetTris_Set3(GlobalContext* globalCtx, ColliderTris* dest, Actor* actor, ColliderTrisInit_Set3* src) {
    ColliderTrisItem* destNext;
    ColliderTrisItemInit* srcNext;

    Collider_SetBase_Set3(globalCtx, &dest->base, actor, &src->base);
    dest->count = src->count;
    dest->list = zelda_malloc(dest->count * sizeof(ColliderTrisItem));
    if (dest->list == NULL) {
        dest->count = 0;
        return 0;
    }
    destNext = dest->list;
    srcNext = src->list;

    while (destNext < dest->list + dest->count) {
        Collider_InitTrisItem(globalCtx, destNext);
        Collider_SetTrisItem(globalCtx, destNext, srcNext);
        destNext++;
        srcNext++;
    }
    return 1;
}

s32 Collider_SetTris(GlobalContext* globalCtx, ColliderTris* collider, Actor* actor, ColliderTrisInit* init, ColliderTrisItem* list) {
    ColliderTrisItem* destNext;
    ColliderTrisItemInit* srcNext;

    Collider_SetBase(globalCtx, &collider->base, actor, &init->base);
    collider->count = init->count;
    collider->list = list;

    destNext = collider->list;
    srcNext = init->list;

    while (destNext < collider->list + collider->count) {
        Collider_InitTrisItem(globalCtx, destNext);
        Collider_SetTrisItem(globalCtx, destNext, srcNext);
        destNext++;
        srcNext++;
    }
    return 1;
}

s32 Collision_InitTriGroup(GlobalContext *globalCtx, ColliderTris *collider, Actor *actor, ColliderTrisInit *init, ColliderTrisItem *list) {
    Collider_InitTris(globalCtx, collider);
    Collider_SetTris(globalCtx, collider, actor, init, list);
    return 0;
}

s32 Collider_TrisSetAT(GlobalContext* globalCtx, Collider* collider) {
    ColliderTrisItem* next;
    ColliderTris* tris = (ColliderTris*)collider;

    Collider_BaseSetAT(globalCtx, &tris->base);
    next = tris->list;

    while (next < tris->list + tris->count) {
        Collider_TrisItemSetAT(globalCtx, next);
        next++;
    }
    return 1;
}

s32 Collider_TrisSetAC(GlobalContext* globalCtx, Collider* collider) {
    ColliderTrisItem* next;
    ColliderTris* tris = (ColliderTris*)collider;

    Collider_BaseSetAC(globalCtx, &tris->base);
    next = tris->list;

    while (next < tris->list + tris->count) {
        Collider_TrisItemSetAC(globalCtx, next);
        next++;
    }
    return 1;
}

s32 Collider_TrisSetOC(GlobalContext* globalCtx, Collider* collider) {
    ColliderTrisItem* next;
    ColliderTris* tris = (ColliderTris*)collider;

    Collider_BaseSetOC(globalCtx, &tris->base);
    next = tris->list;

    while (next < tris->list + tris->count) {
        Collider_TrisItemSetOC(globalCtx, next);
        next++;
    }
    return 1;
}

s32 Collider_InitQuadDim(GlobalContext* globalCtx, ColliderQuadDim* dim) {
    static ColliderQuadDim init = {
        { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
        { 0, 0, 0 },
        { 0, 0, 0 },
        1.0E38f,
    };

    *dim = init;
    return 1;
}

s32 Collider_DestroyQuadDim(GlobalContext* globalCtx, ColliderQuadDim* dim) {
    return 1;
}

extern f32 D_801DD5C4; // 1.0E38f; RODATA FIX
s32 Collider_ResetQuadParamsForAT(GlobalContext* globalCtx, ColliderQuadDim* dim) {
    dim->unk_3C = D_801DD5C4;
    return 1;
}

void Collider_QuadCalcMidpoints(ColliderQuadDim* dim) {
    dim->dcMid.x = (dim->quad[3].x + dim->quad[2].x) * 0.5f;
    dim->dcMid.y = (dim->quad[3].y + dim->quad[2].y) * 0.5f;
    dim->dcMid.z = (dim->quad[3].z + dim->quad[2].z) * 0.5f;
    dim->baMid.x = (dim->quad[1].x + dim->quad[0].x) * 0.5f;
    dim->baMid.y = (dim->quad[1].y + dim->quad[0].y) * 0.5f;
    dim->baMid.z = (dim->quad[1].z + dim->quad[0].z) * 0.5f;
}

s32 Collider_SetQuadDim(GlobalContext* globalCtx, ColliderQuadDim* dim, ColliderQuadDimInit* init) {
    dim->quad[0] = init->quad[0];
    dim->quad[1] = init->quad[1];
    dim->quad[2] = init->quad[2];
    dim->quad[3] = init->quad[3];
    Collider_QuadCalcMidpoints(dim);
    return 1;
}

s32 Collider_InitQuad(GlobalContext* globalCtx, ColliderQuad* collider) {
    Collider_InitBase(globalCtx, &collider->base);
    Collider_InitBody(globalCtx, &collider->body);
    Collider_InitQuadDim(globalCtx, &collider->dim);
    return 1;
}

s32 Collider_DestroyQuad(GlobalContext* globalCtx, ColliderQuad* collider) {
    Collider_DestroyBase(globalCtx, &collider->base);
    Collider_DestroyBody(globalCtx, &collider->body);
    Collider_DestroyQuadDim(globalCtx, &collider->dim);
    return 1;
}

s32 func_800E1EB8(GlobalContext *globalCtx, ColliderQuad *collider, Actor *actor, ColliderQuadInit_Set3 *init) {
    Collider_SetBase_Set3(globalCtx, &collider->base, actor, &init->base);
    Collider_SetBody(globalCtx, &collider->body, &init->body);
    Collider_SetQuadDim(globalCtx, &collider->dim, &init->dim);
    return 1;
}

s32 Collider_InitQuadWithData(GlobalContext *globalCtx, ColliderQuad *collider, Actor *actor, ColliderQuadInit *init) {
    Collider_SetBase(globalCtx, &collider->base, actor, &init->base);
    Collider_SetBody(globalCtx, &collider->body, &init->body);
    Collider_SetQuadDim(globalCtx, &collider->dim, &init->dim);
    return 1;
}

s32 Collider_InitAndSetQuad(GlobalContext *globalCtx, ColliderQuad *collider, Actor *actor, ColliderQuadInit *init) {
    Collider_InitQuad(globalCtx, collider);
    Collider_InitQuadWithData(globalCtx, collider, actor, init);
    return 0;
}

s32 Collider_QuadSetAT(GlobalContext *globalCtx, Collider *collider) {
    ColliderQuad* quad = (ColliderQuad*)collider;

    Collider_BaseSetAT(globalCtx, &quad->base);
    Collider_BodySetAT(globalCtx, &quad->body);
    Collider_ResetQuadParamsForAT(globalCtx, &quad->dim);
    return 1;
}

s32 Collider_QuadSetAC(GlobalContext *globalCtx, Collider *collider) {
    ColliderQuad* quad = (ColliderQuad*)collider;
    
    Collider_BaseSetAC(globalCtx, &quad->base);
    Collider_BodySetAC(globalCtx, &quad->body);
    return 1;
}

s32 Collider_QuadSetOC(GlobalContext *globalCtx, Collider *collider) {
    ColliderQuad* quad = (ColliderQuad*)collider;
    
    Collider_BaseSetOC(globalCtx, &quad->base);
    Collider_BodySetOC(globalCtx, &quad->body);
    return 1;
}

s32 func_800E20A4(GlobalContext* globalCtx, ColliderQuad* quad, Vec3f* arg2) {
    f32 temp;
    Vec3f sp20;

    if (!(quad->body.toucherFlags & 4)) {
        return 1;
    }
    Math_Vec3s_ToVec3f(&sp20, &quad->dim.dcMid);
    temp = Math3D_DistanceSquared(&sp20, arg2);
    if (temp < quad->dim.unk_3C) {
        quad->dim.unk_3C = temp;
        if (quad->body.atHit != NULL) {
            Collider_BaseSetAC(globalCtx, quad->body.atHit);
        }
        if (quad->body.atHitItem != NULL) {
            Collider_BodySetAC(globalCtx, quad->body.atHitItem);
        }
        return 1;
    }
    return 0;
}

s32 Collider_InitSph(GlobalContext *globalCtx, ColliderSph *collider) {
    Collider_InitBase(globalCtx, &collider->base);
    Collider_InitBody(globalCtx, &collider->body);
    Collider_InitJntSphItemDim(globalCtx, &collider->dim);
    return 1;
}

s32 Collider_DestroySph(GlobalContext *globalCtx, ColliderSph *collider) {
    Collider_DestroyBase(globalCtx, &collider->base);
    Collider_DestroyBody(globalCtx, &collider->body);
    Collider_DestroyJntSphItemDim(globalCtx, &collider->dim);
    return 1;
}

s32 Collider_SetSph(GlobalContext *globalCtx, ColliderSph *collider, Actor *actor, ColliderSphInit *init) {
    Collider_SetBase(globalCtx, &collider->base, actor, &init->base);
    Collider_SetBody(globalCtx, &collider->body, &init->body);
    Collider_SetJntSphItemDim(globalCtx, &collider->dim, &init->dim);
    return 1;
}

s32 Collider_InitSphWithData(GlobalContext *globalCtx, ColliderSph *collider, Actor *actor, ColliderSphInit *init) {
    Collider_InitSph(globalCtx, collider);
    Collider_SetSph(globalCtx, collider, actor, init);
    return 0;
}

s32 Collider_SphSetAT(GlobalContext *globalCtx, Collider *collider) {
    ColliderSph* sphere = (ColliderSph*)collider;

    Collider_BaseSetAT(globalCtx, &sphere->base);
    Collider_BodySetAT(globalCtx, &sphere->body);
    return 1;
}

s32 Collider_SphSetAC(GlobalContext *globalCtx, Collider *collider) {
    ColliderSph* sphere = (ColliderSph*)collider;
    
    Collider_BaseSetAC(globalCtx, &sphere->base);
    Collider_BodySetAC(globalCtx, &sphere->body);
    return 1;
}

s32 Collider_SphSetOC(GlobalContext *globalCtx, Collider *collider) {
    ColliderSph* sphere = (ColliderSph*)collider;
    
    Collider_BaseSetOC(globalCtx, &sphere->base);
    Collider_BodySetOC(globalCtx, &sphere->body);
    return 1;
}

s32 Collider_InitOcLine(GlobalContext *globalCtx, OcLine *line) {
    static Vec3f init = { 0.0f, 0.0f, 0.0f };

    Math_Vec3f_Copy(&line->line.a, &init);
    Math_Vec3f_Copy(&line->line.b, &init);
    return 1;
}

s32 Collider_DestroyOcLine(GlobalContext* globalCtx, OcLine* line) {
    return 1;
}

s32 Collider_SetOcLinePoints(GlobalContext* globalCtx, OcLine* line, Vec3f* pointA, Vec3f* pointB) {
    Math_Vec3f_Copy(&line->line.a, pointA);
    Math_Vec3f_Copy(&line->line.b, pointB);
    return 1;
}

s32 Collider_SetOcLine(GlobalContext* globalCtx, OcLine* line, OcLine* init) {
    line->unk_18 = init->unk_18;
    Collider_SetOcLinePoints(globalCtx, line, &init->line.a, &init->line.b);
    return 1;
}

s32 func_800E2434(GlobalContext* globalCtx, OcLine* line) {
    line->unk_18 &= ~1;
    return 1;
}

void Collision_Init(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx) {
    colChkCtx->sacFlags = 0;
    CollisionCheck_InitContext(globalCtx, colChkCtx);
}

void CollisionCheck_DestroyContext(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx) {

}

void CollisionCheck_InitContext(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx) {
    Collider** c;
    OcLine** d;

    if (!(colChkCtx->sacFlags & 1)) {
        colChkCtx->colAtCount = 0;
        colChkCtx->colAcCount = 0;
        colChkCtx->colOcCount = 0;
        colChkCtx->colOcLineCount = 0;
        for (c = colChkCtx->colAt; c < colChkCtx->colAt + COLLISION_CHECK_AT_MAX; c++) {
            *c = NULL;
        }

        for (c = colChkCtx->colAc; c < colChkCtx->colAc + COLLISION_CHECK_AC_MAX; c++) {
            *c = NULL;
        }

        for (c = colChkCtx->colOc; c < colChkCtx->colOc + COLLISION_CHECK_OC_MAX; c++) {
            *c = NULL;
        }

        for (d = colChkCtx->colOcLine; d < colChkCtx->colOcLine + COLLISION_CHECK_OC_LINE_MAX; d++) {
            *d = NULL;
        }
    }
}

void CollisionCheck_EnableSAC(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx) {
    colChkCtx->sacFlags |= 1;
}

void CollisionCheck_DisableSAC(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx) {
    colChkCtx->sacFlags &= ~1;
}

static s32 (*ATFuncs[])(GlobalContext*, Collider*) = { 
    Collider_JntSphSetAT,
    Collider_CylinderSetAT,
    Collider_TrisSetAT,
    Collider_QuadSetAT,
    Collider_SphSetAT,
};

// Sets collider as an AT (attack) for the current frame, which will be checked against ACs (attack colliders)
s32 CollisionCheck_SetAT(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *collider) {
    s32 index;

    if (func_8016A01C(globalCtx)) {
        return -1;
    }

    ATFuncs[collider->shape](globalCtx, collider);

    if (collider->actor != NULL) {
        if (collider->actor->update == NULL) {
            return -1;
        }
    }

    if (colChkCtx->colAtCount >= COLLISION_CHECK_AT_MAX) {
        return -1;
    }

    if (colChkCtx->sacFlags & 1) {
        return -1;
    }

    index = colChkCtx->colAtCount;
    colChkCtx->colAt[colChkCtx->colAtCount++] = collider;
    return index;
}

// Unused. Sets collider as an AT (attack) for the current frame, which will be checked against ACs (attack colliders).
// If CollisionCheck_SAC is enabled, the collider will be inserted into the list at the specified index, otherwise it
// will be inserted into the next slot
s32 CollisionCheck_SetAT_SAC(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *collider, s32 index) {
    if (func_8016A01C(globalCtx)) {
        return -1;
    }

    ATFuncs[collider->shape](globalCtx, collider);

    if (collider->actor != NULL && collider->actor->update == NULL) {
        return -1;
    }

    if (colChkCtx->sacFlags & 1) {
        if (!(index < colChkCtx->colAtCount)) {
            return -1;
        }
        colChkCtx->colAt[index] = collider;
    } else {
        if (!(colChkCtx->colAtCount < COLLISION_CHECK_AT_MAX)) {
            return -1;
        }
        index = colChkCtx->colAtCount;
        colChkCtx->colAt[colChkCtx->colAtCount++] = collider;
    }
    return index;
}

static s32 (*ACFuncs[])(GlobalContext*, Collider*) = {
    Collider_JntSphSetAC, 
    Collider_CylinderSetAC, 
    Collider_TrisSetAC, 
    Collider_QuadSetAC, 
    Collider_SphSetAC, 
};

// Sets collider as an AC (attack collider) for the current frame, allowing it to detect ATs (attacks)
s32 CollisionCheck_SetAC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    s32 index;

    if (func_8016A01C(globalCtx)) {
        return -1;
    }

    ACFuncs[collider->shape](globalCtx, collider);

    if (collider->actor != NULL) {
        if (collider->actor->update == NULL) {
            return -1;
        }
    }

    if (colChkCtx->colAcCount >= COLLISION_CHECK_AC_MAX) {
        return -1;
    }

    if (colChkCtx->sacFlags & 1) {
        return -1;
    }

    index = colChkCtx->colAcCount;
    colChkCtx->colAc[colChkCtx->colAcCount++] = collider;
    return index;
}

// Unused. Sets collider as an AC (attack collider) for the current frame, allowing it to detect ATs (attacks).
// If CollisionCheck_SAC is enabled, the collider will be inserted into the list at the specified index, otherwise it
// will be inserted into the next slot
s32 CollisionCheck_SetAC_SAC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider, s32 index) {
    if (func_8016A01C(globalCtx)) {
        return -1;
    }

    ACFuncs[collider->shape](globalCtx, collider);

    if (collider->actor != NULL && collider->actor->update == NULL) {
        return -1;
    }

    if (colChkCtx->sacFlags & 1) {
        if (!(index < colChkCtx->colAcCount)) {
            return -1;
        }
        colChkCtx->colAc[index] = collider;
    } else {
        if (!(colChkCtx->colAcCount < COLLISION_CHECK_AC_MAX)) {
            return -1;
        }
        index = colChkCtx->colAcCount;
        colChkCtx->colAc[colChkCtx->colAcCount++] = collider;
    }
    return index;
}

static s32 (*OCFuncs[])(GlobalContext*, Collider*) = {
    Collider_JntSphSetOC,
    Collider_CylinderSetOC,
    Collider_TrisSetOC,
    Collider_QuadSetOC,
    Collider_SphSetOC,
};

// Sets collider as an OC (object collider) for the current frame, allowing it to detect other OCs
s32 CollisionCheck_SetOC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    s32 index;

    if (func_8016A01C(globalCtx)) {
        return -1;
    }

    OCFuncs[collider->shape](globalCtx, collider);

    if (collider->actor != NULL) {
        if (collider->actor->update == NULL) {
            return -1;
        }
    }

    if (colChkCtx->colOcCount >= COLLISION_CHECK_OC_MAX) {
        return -1;
    }

    if (colChkCtx->sacFlags & 1) {
        return -1;
    }

    index = colChkCtx->colOcCount;
    colChkCtx->colOc[colChkCtx->colOcCount++] = collider;
    return index;
}

// Unused. Sets collider as an OC (object collider) for the current frame, allowing it to detect other OCs
// If CollisionCheck_SAC is enabled, the collider will be inserted into the list at the specified index, otherwise it
// will be inserted into the next slot
s32 CollisionCheck_SetOC_SAC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider, s32 index) {
    if (func_8016A01C(globalCtx)) {
        return -1;
    }

    OCFuncs[collider->shape](globalCtx, collider);

    if (collider->actor != NULL && collider->actor->update == NULL) {
        return -1;
    }
    
    if (colChkCtx->sacFlags & 1) {
        if (!(index < colChkCtx->colOcCount)) {
            return -1;
        }
        //! @bug Should be colOc
        colChkCtx->colAt[index] = collider;
    } else {
        if (!(colChkCtx->colOcCount < COLLISION_CHECK_OC_MAX)) {
            return -1;
        }
        index = colChkCtx->colOcCount;
        colChkCtx->colOc[colChkCtx->colOcCount++] = collider;
    }
    return index;
}

s32 CollisionCheck_SetOCLine(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, OcLine* collider) {
    s32 index;

    if (func_8016A01C(globalCtx)) {
        return -1;
    }

    func_800E2434(globalCtx, collider);
    if (!(colChkCtx->colOcLineCount < COLLISION_CHECK_OC_LINE_MAX)) {
        return -1;
    }

    index = colChkCtx->colOcLineCount;
    colChkCtx->colOcLine[colChkCtx->colOcLineCount++] = collider;
    return index;
}

s32 Collision_CantBeToucherAC(ColliderBody *body) {
    if (!(body->toucherFlags & 1)) {
        return 1;
    }
    return 0;
}

s32 Collision_CantBeBumperAC(ColliderBody *body) {
    if (!(body->bumperFlags & 1)) {
        return 1;
    }
    return 0;
}

s32 Collision_ToucherIsExcluded(ColliderBody *toucher, ColliderBody *bumper) {
    if (!(toucher->toucher.collidesWith & bumper->bumper.collidesWith)) {
        return 1;
    }
    return 0;
}

void func_800E2C08(GlobalContext* globalCtx, Collider* collider, Vec3f* v) {

}

void func_800E2C1C(GlobalContext* globalCtx, Collider* collider, Vec3f* v) {
    static EffSparkParams D_801EEC00;
    s32 sp24;

    D_801EEC00.position.x = v->x;
    D_801EEC00.position.y = v->y;
    D_801EEC00.position.z = v->z;
    D_801EEC00.particleFactor1 = 5;
    D_801EEC00.particleFactor2 = 5;
    D_801EEC00.colorStart[0].red = 10;
    D_801EEC00.colorStart[0].green = 10;
    D_801EEC00.colorStart[0].blue = 200;
    D_801EEC00.colorStart[0].alpha = 255;
    D_801EEC00.colorStart[1].red = 0;
    D_801EEC00.colorStart[1].green = 0;
    D_801EEC00.colorStart[1].blue = 128;
    D_801EEC00.colorStart[1].alpha = 255;
    D_801EEC00.colorStart[2].red = 0;
    D_801EEC00.colorStart[2].green = 0;
    D_801EEC00.colorStart[2].blue = 128;
    D_801EEC00.colorStart[2].alpha = 255;
    D_801EEC00.colorStart[3].red = 0;
    D_801EEC00.colorStart[3].green = 0;
    D_801EEC00.colorStart[3].blue = 128;
    D_801EEC00.colorStart[3].alpha = 255;
    D_801EEC00.colorEnd[0].red = 0;
    D_801EEC00.colorEnd[0].green = 0;
    D_801EEC00.colorEnd[0].blue = 32;
    D_801EEC00.colorEnd[0].alpha = 0;
    D_801EEC00.colorEnd[1].red = 0;
    D_801EEC00.colorEnd[1].green = 0;
    D_801EEC00.colorEnd[1].blue = 32;
    D_801EEC00.colorEnd[1].alpha = 0;
    D_801EEC00.colorEnd[2].red = 0;
    D_801EEC00.colorEnd[2].green = 0;
    D_801EEC00.colorEnd[2].blue = 64;
    D_801EEC00.colorEnd[2].alpha = 0;
    D_801EEC00.colorEnd[3].red = 0;
    D_801EEC00.colorEnd[3].green = 0;
    D_801EEC00.colorEnd[3].blue = 64;
    D_801EEC00.colorEnd[3].alpha = 0;
    D_801EEC00.age = 0;
    D_801EEC00.duration = 16;
    D_801EEC00.velocity = 8.0f;
    D_801EEC00.gravity = -1.0f;

    Effect_Add(globalCtx, &sp24, 0, 0, 1, &D_801EEC00);
}

void func_800E2D88(GlobalContext* globalCtx, Collider* collider, Vec3f* v) {
    static EffSparkParams D_801EF0C8;
    s32 sp24;

    D_801EF0C8.position.x = v->x;
    D_801EF0C8.position.y = v->y;
    D_801EF0C8.position.z = v->z;
    D_801EF0C8.particleFactor1 = 5;
    D_801EF0C8.particleFactor2 = 5;
    D_801EF0C8.colorStart[0].red = 10;
    D_801EF0C8.colorStart[0].green = 200;
    D_801EF0C8.colorStart[0].blue = 10;
    D_801EF0C8.colorStart[0].alpha = 255;
    D_801EF0C8.colorStart[1].red = 0;
    D_801EF0C8.colorStart[1].green = 128;
    D_801EF0C8.colorStart[1].blue = 0;
    D_801EF0C8.colorStart[1].alpha = 255;
    D_801EF0C8.colorStart[2].red = 0;
    D_801EF0C8.colorStart[2].green = 128;
    D_801EF0C8.colorStart[2].blue = 0;
    D_801EF0C8.colorStart[2].alpha = 255;
    D_801EF0C8.colorStart[3].red = 0;
    D_801EF0C8.colorStart[3].green = 128;
    D_801EF0C8.colorStart[3].blue = 0;
    D_801EF0C8.colorStart[3].alpha = 255;
    D_801EF0C8.colorEnd[0].red = 0;
    D_801EF0C8.colorEnd[0].green = 32;
    D_801EF0C8.colorEnd[0].blue = 0;
    D_801EF0C8.colorEnd[0].alpha = 0;
    D_801EF0C8.colorEnd[1].red = 0;
    D_801EF0C8.colorEnd[1].green = 32;
    D_801EF0C8.colorEnd[1].blue = 0;
    D_801EF0C8.colorEnd[1].alpha = 0;
    D_801EF0C8.colorEnd[2].red = 0;
    D_801EF0C8.colorEnd[2].green = 64;
    D_801EF0C8.colorEnd[2].blue = 0;
    D_801EF0C8.colorEnd[2].alpha = 0;
    D_801EF0C8.colorEnd[3].red = 0;
    D_801EF0C8.colorEnd[3].green = 64;
    D_801EF0C8.colorEnd[3].blue = 0;
    D_801EF0C8.colorEnd[3].alpha = 0;
    D_801EF0C8.age = 0;
    D_801EF0C8.duration = 16;
    D_801EF0C8.velocity = 8.0f;
    D_801EF0C8.gravity = -1.0f;

    Effect_Add(globalCtx, &sp24, 0, 0, 1, &D_801EF0C8);
}

void func_800E2EF4(GlobalContext *globalCtx, Collider *collider, Vec3f *pos) {
    func_800B249C(globalCtx, pos);
    func_800E8478(globalCtx, pos);
}

void func_800E2F30(GlobalContext *globalCtx, Collider *collider, Vec3f *v) {
    func_800E8318(globalCtx, v);
}

void func_800E2F54(GlobalContext *globalCtx, Collider *collider, Vec3f *v) {
    func_800E8318(globalCtx, v);
}

void func_800E2F78(GlobalContext *globalCtx, ColliderBody *colliderBody, Collider *collider, Vec3f *arg3) {
    s32 flags = colliderBody->toucherFlags & 0x18;

    if ((flags == 0) && (collider->type != COLTYPE_METAL_SHIELD)) {
        func_800B2684(globalCtx, 0, arg3);
        if (collider->actor == NULL) {
            play_sound(0x1806);
        } else {
            Audio_PlaySoundGeneral(&collider->actor->projectedPos, 0x1806);
        }
    } else if (flags == 0) {
        func_800B2684(globalCtx, 3, arg3);
        if (collider->actor == NULL) {
            func_800E8668(globalCtx, arg3);
        } else {
            func_800E8690(globalCtx, arg3, &collider->actor->projectedPos);
        }
    } else if (flags == 8) {
        func_800B2684(globalCtx, 0, arg3);
        if (collider->actor == NULL) {
            play_sound(0x1806);
        } else {
            Audio_PlaySoundGeneral(&collider->actor->projectedPos, 0x1806);
        }
    } else if (flags == 0x10) {
        func_800B2684(globalCtx, 1, arg3);
        if (collider->actor == NULL) {
            play_sound(0x1837);
        } else {
            Audio_PlaySoundGeneral(&collider->actor->projectedPos, 0x1837);
        }
    }
}

s32 func_800E30C8(Collider *left, ColliderBody *rightBody) {
    if ((left->actor != NULL) && (left->actor->type == 2)) {
        if (rightBody->flags == 0) {
            Audio_PlaySoundGeneral(&left->actor->projectedPos, 0x1811);
        } else if (rightBody->flags == 1) {
            Audio_PlaySoundGeneral(&left->actor->projectedPos, 0x1824);
        } else if (rightBody->flags == 2) {
            Audio_PlaySoundGeneral(&left->actor->projectedPos, 0);
        } else if (rightBody->flags == 3) {
            Audio_PlaySoundGeneral(&left->actor->projectedPos, 0);
        }
    }
    return 1;
}

typedef struct {
    u8 unk00;
    u8 unk01;
} D_801BA38C_s;

void func_800E3168(GlobalContext* globalCtx, Collider* left, ColliderBody* leftBody, Collider* right,
                   ColliderBody* rightBody, Vec3f* arg5) {

    static void (*D_801BA374[])(GlobalContext*, Collider*, Vec3f*) = {
        func_800E2C08,
        func_800E2C1C,
        func_800E2D88,
        func_800E2EF4,
        func_800E2F30,
        func_800E2F54,
    };

    static D_801BA38C_s D_801BA38C[] = {
        { 1, 0 }, { 0, 1 }, { 2, 1 }, { 0, 0 }, { 3, 5 }, { 0, 2 }, { 2, 0 },
        { 4, 0 }, { 1, 2 }, { 0, 3 }, { 0, 5 }, { 0, 3 }, { 0, 3 }, { 0, 4 },
    };

    if (rightBody->bumperFlags & 0x40) {
        return;
    }

    if (!(leftBody->toucherFlags & 0x20) && leftBody->toucherFlags & 0x40) {
        return;
    }

    if (right->actor != NULL) {
        (*D_801BA374[D_801BA38C[right->type].unk00])(globalCtx, right, arg5);
    }

    if (right->actor != NULL) {
        if (D_801BA38C[right->type].unk01 == 3) {
            func_800E2F78(globalCtx, leftBody, right, arg5);
        } else if (D_801BA38C[right->type].unk01 == 4) {
            if (left->actor == NULL) {
                func_800E85D4(globalCtx, arg5);
                play_sound(0x1837);
            } else {
                func_800E86E0(globalCtx, arg5, &left->actor->projectedPos);
            }
        } else if (D_801BA38C[right->type].unk01 != 5) {
            func_800B2684(globalCtx, D_801BA38C[right->type].unk01, arg5);
            if (!(rightBody->bumperFlags & 0x20)) {
                func_800E30C8(left, rightBody);
            }
        }
    } else {
        func_800B2684(globalCtx, 0, arg5);
        if (right->actor == NULL) {
            play_sound(0x1806);
        } else {
            Audio_PlaySoundGeneral(&right->actor->projectedPos, 0x1806);
        }
    }
}

void func_800E3304(Collider *toucher, Collider *bumper) {
    toucher->atFlags |=  4;
    bumper->acFlags |= 0x80;
}

// Set AT to AC collision
s32 Collision_HandleCollisionATWithAC(GlobalContext* globalCtx, Collider* left, ColliderBody* leftBody, Vec3f* leftv, Collider* right,
                  ColliderBody* rightBody, Vec3f* rightv, Vec3f* arg7) {
    s32 pad;
    s32 sp38;
    f32 temp_f0;

    if (Collision_GetToucherDamage(left, leftBody, right, rightBody) != 0) {
        temp_f0 = Collision_GetDamageAndEffectOnBumper(left, leftBody, right, rightBody, &sp38);
        
        if (temp_f0 < 1.0f) {
            if (sp38 == 0) {
                return 0;
            }
        } else if ((func_800E04BC(temp_f0, rightBody) < 1.0f) && (sp38 == 0)) {
            return 0;
        }
    }

    if (right->acFlags & 4) {
        if ((left->actor != NULL) && (right->actor != NULL)) {
            func_800E3304(left, right);
        }
    }

    if (!(rightBody->bumperFlags & 8)) {
        left->atFlags |= 2;
        left->at = right->actor;
        leftBody->atHit = right;
        leftBody->toucherFlags |= 2;
        leftBody->atHitItem = rightBody;
        if (!(leftBody->bumperFlags & 2)) {
            leftBody->bumper.unk_06.x = arg7->x;
            leftBody->bumper.unk_06.y = arg7->y;
            leftBody->bumper.unk_06.z = arg7->z;
        }
        if (left->actor != NULL) {
            left->actor->colChkInfo.atHitEffect = rightBody->bumper.effect;
        }
    }

    if (!(leftBody->ocFlags & 4)) {
        right->acFlags |= 2;
        right->ac = left->actor;
        rightBody->acHit = left;
        rightBody->bumperFlags |= 2;
        rightBody->acHitItem = leftBody;
        if (right->actor != NULL) {
            right->actor->colChkInfo.acHitEffect = leftBody->toucher.effect;
        }
        rightBody->bumper.unk_06.x = arg7->x;
        rightBody->bumper.unk_06.y = arg7->y;
        rightBody->bumper.unk_06.z = arg7->z;
    }

    if (!(leftBody->toucherFlags & 0x20) && (right->type != COLTYPE_METAL_SHIELD) &&
        (right->type != COLTYPE_WOODEN_SHIELD) && (right->type != COLTYPE_UNK12)) {
        rightBody->bumperFlags |= 0x80;
    } else {
        func_800E3168(globalCtx, left, leftBody, right, rightBody, arg7);
        leftBody->toucherFlags |= 0x40;
    }
    return 1;
}

void Collision_TriCalcAvgPoint(ColliderTrisItem *tri, Vec3f *avg) {
    avg->x = (tri->dim.vtx[0].x + tri->dim.vtx[1].x + tri->dim.vtx[2].x) * (1.0f / 3);
    avg->y = (tri->dim.vtx[0].y + tri->dim.vtx[1].y + tri->dim.vtx[2].y) * (1.0f / 3);
    avg->z = (tri->dim.vtx[0].z + tri->dim.vtx[1].z + tri->dim.vtx[2].z) * (1.0f / 3);
}

void Collision_QuadCalcAvgPoint(ColliderQuad *quad, Vec3f *avg) {
    avg->x = (quad->dim.quad[0].x + (quad->dim.quad[1].x + (quad->dim.quad[3].x + quad->dim.quad[2].x))) * (1.0f / 4);
    avg->y = (quad->dim.quad[0].y + (quad->dim.quad[1].y + (quad->dim.quad[3].y + quad->dim.quad[2].y))) * (1.0f / 4);
    avg->z = (quad->dim.quad[0].z + (quad->dim.quad[1].z + (quad->dim.quad[3].z + quad->dim.quad[2].z))) * (1.0f / 4);
}

void CollisionCheck_AC_JntSphVsJntSph(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l,
                                      Collider* r) {
    ColliderJntSph* left;
    ColliderJntSph* right;
    ColliderJntSphItem* lItem;
    ColliderJntSphItem* rItem;
    f32 sp8C;
    f32 sp88;
    f32 temp_f0;
    Vec3f sp78;
    Vec3f sp6C;
    Vec3f sp60;

    left = (ColliderJntSph*)l;
    right = (ColliderJntSph*)r;
    if (left->count <= 0 || left->list == NULL || right->count <= 0 || right->list == NULL) {
        return;
    }

    for (lItem = left->list; lItem < left->list + left->count; lItem++) {
        if (Collision_CantBeToucherAC(&lItem->body)) {
            continue;
        }

        for (rItem = right->list; rItem < right->list + right->count; rItem++) {
            if (Collision_CantBeBumperAC(&rItem->body) || Collision_ToucherIsExcluded(&lItem->body, &rItem->body)) {
                continue;
            }

            if (Math3D_ColSphereSphereIntersectAndDistance(&lItem->dim.worldSphere, &rItem->dim.worldSphere, &sp8C, &sp88) != 0) {
                Math_Vec3s_ToVec3f(&sp6C, &lItem->dim.worldSphere.center);
                Math_Vec3s_ToVec3f(&sp60, &rItem->dim.worldSphere.center);
                if (!(fabsf(sp88) < 0.008f)) {
                    temp_f0 = rItem->dim.worldSphere.radius / sp88;
                    sp78.x = ((sp6C.x - sp60.x) * temp_f0) + sp60.x;
                    sp78.y = ((sp6C.y - sp60.y) * temp_f0) + sp60.y;
                    sp78.z = ((sp6C.z - sp60.z) * temp_f0) + sp60.z;
                } else {
                    Math_Vec3f_Copy(&sp78, &sp6C);
                }
                Collision_HandleCollisionATWithAC(globalCtx, &left->base, &lItem->body, &sp6C, &right->base, &rItem->body, &sp60, &sp78);
                if (!(right->base.maskB & 0x40)) {
                    return;
                }
            }
        }
    }
}

void CollisionCheck_AC_JntSphVsCyl(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l,
                                   Collider* r) {
    ColliderJntSph* left = (ColliderJntSph*)l;
    ColliderCylinder* right = (ColliderCylinder*)r;
    ColliderJntSphItem* lItem;
    f32 sp80;
    f32 sp7C;

    if (left->count <= 0 || left->list == NULL || right->dim.radius <= 0 || right->dim.height <= 0) {
        return;
    }

    if (Collision_CantBeBumperAC(&right->body)) {
        return;
    }

    for (lItem = left->list; lItem < left->list + left->count; lItem++) {
        Vec3f sp70;
        Vec3f sp64;
        Vec3f sp58;

        if (Collision_CantBeToucherAC(&lItem->body) || Collision_ToucherIsExcluded(&lItem->body, &right->body)) {
            continue;
        }

        if (Math3D_ColSphereCylinderDistanceAndAmount(&lItem->dim.worldSphere, &right->dim, &sp80, &sp7C)) {
            Math_Vec3s_ToVec3f(&sp64, &lItem->dim.worldSphere.center);
            Math_Vec3s_ToVec3f(&sp58, &right->dim.pos);
            if (!(fabsf(sp7C) < 0.008f)) {
                f32 temp_f0 = right->dim.radius / sp7C;

                if (temp_f0 <= 1.0f) {
                    sp70.x = ((sp64.x - sp58.x) * temp_f0) + sp58.x;
                    sp70.y = ((sp64.y - sp58.y) * temp_f0) + sp58.y;
                    sp70.z = ((sp64.z - sp58.z) * temp_f0) + sp58.z;
                } else {
                    Math_Vec3f_Copy(&sp70, &sp64);
                }
            } else {
                Math_Vec3f_Copy(&sp70, &sp64);
            }
            Collision_HandleCollisionATWithAC(globalCtx, &left->base, &lItem->body, &sp64, &right->base, &right->body, &sp58, &sp70);
            return;
        }
    }
}

void CollisionCheck_AC_JntSphVsTris(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l,
                                    Collider* r) {
    ColliderJntSph* left = (ColliderJntSph*)l;
    ColliderTris* right = (ColliderTris*)r;
    ColliderJntSphItem* lItem;
    ColliderTrisItem* rItem;
    
    if (left->count <= 0 || left->list == NULL || right->count <= 0 || right->list == NULL) {
        return;
    }

    for (lItem = left->list; lItem < left->list + left->count; lItem++) {
        if (Collision_CantBeToucherAC(&lItem->body)) {
            continue;
        }

        for (rItem = right->list; rItem < right->list + right->count; rItem++) {
            Vec3f sp6C;
            Vec3f sp60;
            Vec3f sp54;

            if (Collision_CantBeBumperAC(&rItem->body) || Collision_ToucherIsExcluded(&lItem->body, &rItem->body)) {
                continue;
            }

            if (Math3D_ColSphereTri(&lItem->dim.worldSphere, &rItem->dim, &sp6C)) {
                Math_Vec3s_ToVec3f(&sp60, &lItem->dim.worldSphere.center);
                Collision_TriCalcAvgPoint(rItem, &sp54);
                Collision_HandleCollisionATWithAC(globalCtx, &left->base, &lItem->body, &sp60, &right->base, &rItem->body, &sp54, &sp6C);
                return;
            }
        }
    }
}

void CollisionCheck_AC_JntSphVsQuad(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l,
                                    Collider* r) {
    static TriNorm D_801EF590;
    static TriNorm D_801EF5C8;

    ColliderJntSph* left = (ColliderJntSph*)l;
    ColliderQuad* right = (ColliderQuad*)r;
    Vec3f sp7C;
    ColliderJntSphItem* lItem;
    Vec3f sp6C;
    Vec3f sp60;

    if (left->count > 0 && left->list != NULL) {
        if (Collision_CantBeBumperAC(&right->body)) {
            return;
        }

        Math3D_TriSetCoords(&D_801EF590, &right->dim.quad[2], &right->dim.quad[3], &right->dim.quad[1]);
        Math3D_TriSetCoords(&D_801EF5C8, &right->dim.quad[1], &right->dim.quad[0], &right->dim.quad[2]);
        for (lItem = left->list; lItem < left->list + left->count; lItem++) {
            if (Collision_CantBeToucherAC(&lItem->body) || Collision_ToucherIsExcluded(&lItem->body, &right->body)) {
                continue;
            }

            if (Math3D_ColSphereTri(&lItem->dim.worldSphere, &D_801EF590, &sp7C) ||
                Math3D_ColSphereTri(&lItem->dim.worldSphere, &D_801EF5C8, &sp7C)) {
                Math_Vec3s_ToVec3f(&sp6C, &lItem->dim.worldSphere.center);
                Collision_QuadCalcAvgPoint(right, &sp60);
                Collision_HandleCollisionATWithAC(globalCtx, &left->base, &lItem->body, &sp6C, &right->base, &right->body, &sp60, &sp7C);
                return;
            }
        }
    }
}

void CollisionCheck_AC_JntSphVsSph(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *l, Collider *r) {
    ColliderJntSph* left = (ColliderJntSph*)l;
    ColliderSph* right = (ColliderSph*)r;
    ColliderJntSphItem* lItem;
    f32 sp90;
    f32 sp8C;
    f32 temp_f0;
    Vec3f sp7C;
    Vec3f sp70;
    Vec3f sp64;

    if (left->count > 0 && left->list != NULL) {
        if (Collision_CantBeBumperAC(&right->body)) {
            return;
        }

        for (lItem = left->list; lItem < left->list + left->count; lItem++) {
            if (Collision_CantBeToucherAC(&lItem->body) || Collision_ToucherIsExcluded(&lItem->body, &right->body)) {
                continue;
            }

            if (Math3D_ColSphereSphereIntersectAndDistance(&lItem->dim.worldSphere, &right->dim.worldSphere, &sp90, &sp8C)) {
                Math_Vec3s_ToVec3f(&sp70, &lItem->dim.worldSphere.center);
                Math_Vec3s_ToVec3f(&sp64, &right->dim.worldSphere.center);
                if (!(fabsf(sp8C) < 0.008f)) {
                    temp_f0 = right->dim.worldSphere.radius / sp8C;
                    sp7C.x = ((sp70.x - sp64.x) * temp_f0) + sp64.x;
                    sp7C.y = ((sp70.y - sp64.y) * temp_f0) + sp64.y;
                    sp7C.z = ((sp70.z - sp64.z) * temp_f0) + sp64.z;
                } else {
                    Math_Vec3f_Copy(&sp7C, &sp70);
                }
                Collision_HandleCollisionATWithAC(globalCtx, &left->base, &lItem->body, &sp70, &right->base, &right->body, &sp64, &sp7C);
            }
        }
    }
}

void CollisionCheck_AC_CylVsJntSph(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l,
                                   Collider* r) {
    ColliderCylinder* left = (ColliderCylinder*)l;
    ColliderJntSph* right = (ColliderJntSph*)r;
    f32 sp9C;
    f32 sp98;
    ColliderJntSphItem* rItem;
    Vec3f sp88;
    Vec3f sp7C;
    Vec3f sp70;
    f32 temp_f0;

    if (right->count <= 0 || right->list == NULL || left->dim.radius <= 0 || left->dim.height <= 0) {
        return;
    }
    if (Collision_CantBeToucherAC(&left->body)) {
        return;
    }
    for (rItem = right->list; rItem < right->list + right->count; rItem++) {
        if (Collision_CantBeBumperAC(&rItem->body) || Collision_ToucherIsExcluded(&left->body, &rItem->body)) {
            continue;
        }

        if (Math3D_ColSphereCylinderDistanceAndAmount(&rItem->dim.worldSphere, &left->dim, &sp9C, &sp98)) {
            Math_Vec3s_ToVec3f(&sp7C, &left->dim.pos);
            Math_Vec3s_ToVec3f(&sp70, &rItem->dim.worldSphere.center);
            if (!(fabsf(sp98) < 0.008f)) {
                temp_f0 = rItem->dim.worldSphere.radius / sp98;
                if (temp_f0 <= 1.0f) {
                    sp88.x = ((sp7C.x - sp70.x) * temp_f0) + sp70.x;
                    sp88.y = ((sp7C.y - sp70.y) * temp_f0) + sp70.y;
                    sp88.z = ((sp7C.z - sp70.z) * temp_f0) + sp70.z;
                } else {
                    Math_Vec3f_Copy(&sp88, &sp7C);
                }
            } else {
                Math_Vec3f_Copy(&sp88, &sp7C);
            }
            Collision_HandleCollisionATWithAC(globalCtx, &left->base, &left->body, &sp7C, &right->base, &rItem->body, &sp70, &sp88);
            if (!(right->base.maskB & 0x40)) {
                break;
            }
        }
    }
}

void CollisionCheck_AC_CylVsCyl(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l, Collider* r) {
    ColliderCylinder* left = (ColliderCylinder*)l;
    ColliderCylinder* right = (ColliderCylinder*)r;
    f32 sp6C;
    f32 sp68;
    Vec3f sp5C;
    Vec3f sp50;
    Vec3f sp44;

    if (left->dim.radius <= 0 || left->dim.height <= 0 || right->dim.radius <= 0 || right->dim.height <= 0) {
        return;
    }

    if (Collision_CantBeBumperAC(&right->body) || Collision_CantBeToucherAC(&left->body) || Collision_ToucherIsExcluded(&left->body, &right->body)) {
        return;
    }

    if (Math3D_ColCylinderCylinderAmountAndDistance(&left->dim, &right->dim, &sp6C, &sp68)) {
        Math_Vec3s_ToVec3f(&sp50, &left->dim.pos);
        Math_Vec3s_ToVec3f(&sp44, &right->dim.pos);
        if (!(fabsf(sp68) < 0.008f)) {
            f32 temp_f0 = right->dim.radius / sp68;
            f32 clamp;

            sp5C.y = (f32)left->dim.pos.y + left->dim.yShift + (left->dim.height * 0.5f);
            clamp = (f32)right->dim.pos.y + right->dim.yShift;
            if (sp5C.y < clamp) {
                sp5C.y = clamp;
            } else {
                clamp += right->dim.height;
                if (sp5C.y > clamp) {
                    sp5C.y = clamp;
                }
            }

            sp5C.x = (((f32)left->dim.pos.x - right->dim.pos.x) * temp_f0) + right->dim.pos.x;
            sp5C.z = (((f32)left->dim.pos.z - right->dim.pos.z) * temp_f0) + right->dim.pos.z;
        } else {
            Math_Vec3s_ToVec3f(&sp5C, &right->dim.pos);
        }
        Collision_HandleCollisionATWithAC(globalCtx, &left->base, &left->body, &sp50, &right->base, &right->body, &sp44, &sp5C);
    }
}

void CollisionCheck_AC_CylVsTris(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l, Collider* r) {
    ColliderCylinder* left = (ColliderCylinder*)l;
    ColliderTris* right = (ColliderTris*)r;
    ColliderTrisItem* rItem;
    
    if (left->dim.radius <= 0 || left->dim.height <= 0 || right->count <= 0 || right->list == NULL) {
        return;
    }

    if (Collision_CantBeToucherAC(&left->body)) {
        return;
    }

    for (rItem = right->list; rItem < right->list + right->count; rItem++) {
        Vec3f sp68;
        Vec3f sp5C;
        Vec3f sp50;

        if (Collision_CantBeBumperAC(&rItem->body) || Collision_ToucherIsExcluded(&left->body, &rItem->body)) {
            continue;
        }

        if (Math3D_ColCylinderTri(&left->dim, &rItem->dim, &sp68)) {
            Math_Vec3s_ToVec3f(&sp5C, &left->dim.pos);
            Collision_TriCalcAvgPoint(rItem, &sp50);
            Collision_HandleCollisionATWithAC(globalCtx, &left->base, &left->body, &sp5C, &right->base, &rItem->body, &sp50, &sp68);
            return;
        }
    }
}

void CollisionCheck_AC_CylVsQuad(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l, Collider* r) {
    static Vec3f D_801EDE00;
    static TriNorm D_801EF600;
    static TriNorm D_801EF638;

    ColliderCylinder* left = (ColliderCylinder*)l;
    ColliderQuad* right = (ColliderQuad*)r;
    Vec3f sp64;
    Vec3f sp58;
    Vec3f sp4C;
    Vec3f sp40;

    if (left->dim.height <= 0 || left->dim.radius <= 0) {
        return;
    }

    if (Collision_CantBeToucherAC(&left->body) || Collision_CantBeBumperAC(&right->body) || Collision_ToucherIsExcluded(&left->body, &right->body)) {
        return;
    }

    Math3D_TriSetCoords(&D_801EF600, &right->dim.quad[2], &right->dim.quad[3], &right->dim.quad[1]);
    Math3D_TriSetCoords(&D_801EF638, &right->dim.quad[1], &right->dim.quad[0], &right->dim.quad[2]);
    if (Math3D_ColCylinderTri(&left->dim, &D_801EF600, &D_801EDE00)) {
        Math_Vec3s_ToVec3f(&sp64, &left->dim.pos);
        Collision_QuadCalcAvgPoint(right, &sp58);
        Collision_HandleCollisionATWithAC(globalCtx, &left->base, &left->body, &sp64, &right->base, &right->body, &sp58, &D_801EDE00);
        return;
    }
    if (Math3D_ColCylinderTri(&left->dim, &D_801EF638, &D_801EDE00)) {
        Math_Vec3s_ToVec3f(&sp4C, &left->dim.pos);
        Collision_QuadCalcAvgPoint(right, &sp40);
        Collision_HandleCollisionATWithAC(globalCtx, &left->base, &left->body, &sp4C, &right->base, &right->body, &sp40, &D_801EDE00);
    }
}

void CollisionCheck_AC_CylVsSph(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *l, Collider *r) {
    ColliderCylinder* left = (ColliderCylinder*)l;
    ColliderSph* right = (ColliderSph*)r;
    f32 sp6C;
    f32 sp68;
    Vec3f sp5C;
    Vec3f sp50;
    Vec3f sp44;

    if (left->dim.radius <= 0 || left->dim.height <= 0) {
        return;
    }

    if (Collision_CantBeToucherAC(&left->body) || Collision_CantBeBumperAC(&right->body) || Collision_ToucherIsExcluded(&left->body, &right->body)) {
        return;
    }

    if (Math3D_ColSphereCylinderDistanceAndAmount(&right->dim.worldSphere, &left->dim, &sp6C, &sp68)) {
        Math_Vec3s_ToVec3f(&sp50, &left->dim.pos);
        Math_Vec3s_ToVec3f(&sp44, &right->dim.worldSphere.center);
        if (!(fabsf(sp68) < 0.008f)) {
            f32 temp_f0 = right->dim.worldSphere.radius / sp68;

            if (temp_f0 <= 1.0f) {
                sp5C.x = ((sp50.x - sp44.x) * temp_f0) + sp44.x;
                sp5C.y = ((sp50.y - sp44.y) * temp_f0) + sp44.y;
                sp5C.z = ((sp50.z - sp44.z) * temp_f0) + sp44.z;
            } else {
                Math_Vec3f_Copy(&sp5C, &sp50);
            }
        } else {
            Math_Vec3f_Copy(&sp5C, &sp50);
        }
        Collision_HandleCollisionATWithAC(globalCtx, &left->base, &left->body, &sp50, &right->base, &right->body, &sp44, &sp5C);
    }
}

void CollisionCheck_AC_TrisVsJntSph(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l,
                                    Collider* r) {
    ColliderTris* left = (ColliderTris*)l;
    ColliderTrisItem* lItem;
    ColliderJntSph* right = (ColliderJntSph*)r;
    ColliderJntSphItem* rItem;
    Vec3f sp7C;
    Vec3f sp70;
    Vec3f sp64;

    if (right->count <= 0 || right->list == NULL || left->count <= 0 || left->list == NULL) {
        return;
    }

    for (rItem = right->list; rItem < right->list + right->count; rItem++) {
        if (Collision_CantBeBumperAC(&rItem->body)) {
            continue;
        }

        for (lItem = left->list; lItem < left->list + left->count; lItem++) {
            if (Collision_CantBeToucherAC(&lItem->body) || Collision_ToucherIsExcluded(&lItem->body, &rItem->body)) {
                continue;
            }

            if (Math3D_ColSphereTri(&rItem->dim.worldSphere, &lItem->dim, &sp7C)) {
                Math_Vec3s_ToVec3f(&sp64, &rItem->dim.worldSphere.center);
                Collision_TriCalcAvgPoint(lItem, &sp70);
                Collision_HandleCollisionATWithAC(globalCtx, &left->base, &lItem->body, &sp70, &right->base, &rItem->body, &sp64,
                              &sp7C);
                if (!(right->base.maskB & 0x40)) {
                    return;
                }
            }
        }
    }
}


void CollisionCheck_AC_TrisVsCyl(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l, Collider* r) {
    static Vec3f D_801EDE10;
    
    ColliderTris* left = (ColliderTris*)l;
    ColliderCylinder* right = (ColliderCylinder*)r;
    ColliderTrisItem* lItem;
    

    if (right->dim.radius <= 0 || right->dim.height <= 0 || left->count <= 0 || left->list == NULL) {
        return;
    }

    if (Collision_CantBeBumperAC(&right->body)) {
        return;
    }

    for (lItem = left->list; lItem < left->list + left->count; lItem++) {
        Vec3f sp58;
        Vec3f sp4C;

        if (Collision_CantBeToucherAC(&lItem->body) || Collision_ToucherIsExcluded(&lItem->body, &right->body)) {
            continue;
        }

        if (Math3D_ColCylinderTri(&right->dim, &lItem->dim, &D_801EDE10)) {
            Collision_TriCalcAvgPoint(lItem, &sp58);
            Math_Vec3s_ToVec3f(&sp4C, &right->dim.pos);
            Collision_HandleCollisionATWithAC(globalCtx, &left->base, &lItem->body, &sp58, &right->base, &right->body, &sp4C,
                          &D_801EDE10);
            return;
        }
    }
}


void CollisionCheck_AC_TrisVsTris(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l,
                                  Collider* r) {
    static Vec3f D_801EDE20;

    ColliderTris* left = (ColliderTris*)l;
    ColliderTris* right = (ColliderTris*)r;
    ColliderTrisItem* lItem;
    ColliderTrisItem* rItem;

    if (right->count <= 0 || right->list == NULL || left->count <= 0 || left->list == NULL) {
        return;
    }

    for (rItem = right->list; rItem < right->list + right->count; rItem++) {
        if (Collision_CantBeBumperAC(&rItem->body)) {
            continue;
        }

        for (lItem = left->list; lItem < left->list + left->count; lItem++) {
            Vec3f sp5C;
            Vec3f sp50;

            if (Collision_CantBeToucherAC(&lItem->body) || Collision_ToucherIsExcluded(&lItem->body, &rItem->body)) {
                continue;
            }

            if (Math3d_ColTriTri(&lItem->dim, &rItem->dim, &D_801EDE20)) {
                Collision_TriCalcAvgPoint(lItem, &sp5C);
                Collision_TriCalcAvgPoint(rItem, &sp50);
                Collision_HandleCollisionATWithAC(globalCtx, &left->base, &lItem->body, &sp5C, &right->base, &rItem->body, &sp50,
                              &D_801EDE20);
                return;
            }
        }
    }
}

void CollisionCheck_AC_TrisVsQuad(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l,
                                  Collider* r) {
    static Vec3f D_801EDE30;
    static TriNorm D_801EDE40;
    static TriNorm D_801EDE78;

    ColliderTris* left = (ColliderTris*)l;
    ColliderQuad* right = (ColliderQuad*)r;
    ColliderTrisItem* lItem;
    
    if (left->count > 0 && left->list != NULL) {
        if (Collision_CantBeBumperAC(&right->body)) {
            return;
        }

        Math3D_TriSetCoords(&D_801EDE40, &right->dim.quad[2], &right->dim.quad[3], &right->dim.quad[1]);
        Math3D_TriSetCoords(&D_801EDE78, &right->dim.quad[1], &right->dim.quad[0], &right->dim.quad[2]);
        for (lItem = left->list; lItem < left->list + left->count; lItem++) {
            if (Collision_CantBeToucherAC(&lItem->body) || Collision_ToucherIsExcluded(&lItem->body, &right->body)) {
                continue;
            }

            if (Math3d_ColTriTri(&D_801EDE40, &lItem->dim, &D_801EDE30) ||
                Math3d_ColTriTri(&D_801EDE78, &lItem->dim, &D_801EDE30)) {
                Vec3f sp68;
                Vec3f sp5C;

                Collision_TriCalcAvgPoint(lItem, &sp68);
                Collision_QuadCalcAvgPoint(right, &sp5C);
                Collision_HandleCollisionATWithAC(globalCtx, &left->base, &lItem->body, &sp68, &right->base, &right->body, &sp5C,
                              &D_801EDE30);
                return;
            }
        }
    }
}

void CollisionCheck_AC_TrisVsSph(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *l, Collider *r) {
    ColliderTris* left = (ColliderTris*)l;
    ColliderSph* right = (ColliderSph*)r;
    ColliderTrisItem* lItem;
    
    if (left->count <= 0 || left->list == NULL) {
        return;
    }

    if (Collision_CantBeBumperAC(&right->body)) {
        return;
    }

    for (lItem = left->list; lItem < left->list + left->count; lItem++) {
        Vec3f sp70;
        Vec3f sp64;
        Vec3f sp58;

        if (Collision_CantBeToucherAC(&lItem->body) || Collision_ToucherIsExcluded(&lItem->body, &right->body)) {
            continue;
        }

        if (Math3D_ColSphereTri(&right->dim.worldSphere, &lItem->dim, &sp70)) {
            Math_Vec3s_ToVec3f(&sp58, &right->dim.worldSphere.center);
            Collision_TriCalcAvgPoint(lItem, &sp64);
            Collision_HandleCollisionATWithAC(globalCtx, &left->base, &lItem->body, &sp64, &right->base, &right->body, &sp58, &sp70);
        }
    }
}

void CollisionCheck_AC_QuadVsJntSph(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l,
                                    Collider* r) {
    static TriNorm D_801EDEC8;
    static TriNorm D_801EDF00;

    ColliderQuad* left = (ColliderQuad*)l;
    Vec3f sp80;
    ColliderJntSph* right = (ColliderJntSph*)r;
    ColliderJntSphItem* rItem;
    Vec3f sp6C;
    Vec3f sp60;

    if (right->count <= 0 || right->list == NULL) {
        return;
    }

    if (Collision_CantBeToucherAC(&left->body)) {
        return;
    }

    Math3D_TriSetCoords(&D_801EDEC8, &left->dim.quad[2], &left->dim.quad[3], &left->dim.quad[1]);
    Math3D_TriSetCoords(&D_801EDF00, &left->dim.quad[2], &left->dim.quad[1], &left->dim.quad[0]);
    for (rItem = right->list; rItem < right->list + right->count; rItem++) {
        if (Collision_CantBeBumperAC(&rItem->body) || Collision_ToucherIsExcluded(&left->body, &rItem->body)) {
            continue;
        }

        if (Math3D_ColSphereTri(&rItem->dim.worldSphere, &D_801EDEC8, &sp80) || Math3D_ColSphereTri(&rItem->dim.worldSphere, &D_801EDF00, &sp80)) {
            if (func_800E20A4(globalCtx, left, &sp80)) {
                Math_Vec3s_ToVec3f(&sp60, &rItem->dim.worldSphere.center);
                if (1){};
                Collision_QuadCalcAvgPoint(left, &sp6C);
                Collision_HandleCollisionATWithAC(globalCtx, &left->base, &left->body, &sp6C, &right->base, &rItem->body, &sp60, &sp80);
                if (!(right->base.maskB & 0x40)) {
                    return;
                }
            }
        }        
    }
}

void CollisionCheck_AC_QuadVsCyl(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l, Collider* r) {
    static TriNorm D_801EDF58;
    static TriNorm D_801EDF90;
    static Vec3f D_801EDFE0;

    ColliderQuad* left = (ColliderQuad*)l;
    ColliderCylinder* right = (ColliderCylinder*)r;

    if (right->dim.height <= 0 || right->dim.radius <= 0) {
        return;
    }

    if (Collision_CantBeBumperAC(&right->body) || Collision_CantBeToucherAC(&left->body) || Collision_ToucherIsExcluded(&left->body, &right->body)) {
        return;
    }

    Math3D_TriSetCoords(&D_801EDF58, &left->dim.quad[2], &left->dim.quad[3], &left->dim.quad[1]);
    Math3D_TriSetCoords(&D_801EDF90, &left->dim.quad[2], &left->dim.quad[1], &left->dim.quad[0]);
    if (Math3D_ColCylinderTri(&right->dim, &D_801EDF58, &D_801EDFE0) &&
        func_800E20A4(globalCtx, left, &D_801EDFE0)) {
        Vec3f sp64;
        Vec3f sp58;

        Collision_QuadCalcAvgPoint(left, &sp64);
        Math_Vec3s_ToVec3f(&sp58, &right->dim.pos);
        Collision_HandleCollisionATWithAC(globalCtx, &left->base, &left->body, &sp64, &right->base, &right->body, &sp58, &D_801EDFE0);
        return;
    }

    if (Math3D_ColCylinderTri(&right->dim, &D_801EDF90, &D_801EDFE0) &&
        func_800E20A4(globalCtx, left, &D_801EDFE0)) {
        Vec3f sp4C;
        Vec3f sp40;

        Collision_QuadCalcAvgPoint(left, &sp4C);
        Math_Vec3s_ToVec3f(&sp40, &right->dim.pos);
        Collision_HandleCollisionATWithAC(globalCtx, &left->base, &left->body, &sp4C, &right->base, &right->body, &sp40, &D_801EDFE0);
        return;
    }
}

void CollisionCheck_AC_QuadVsTris(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l,
                                  Collider* r) {
    static Vec3f D_801EDFF0;
    static TriNorm D_801EE000;
    static TriNorm D_801EE038;

    ColliderQuad* left = (ColliderQuad*)l;
    ColliderTris* right = (ColliderTris*)r;
    ColliderTrisItem* rItem;

    if (right->count <= 0 || right->list == NULL) {
        return;
    }

    if (Collision_CantBeToucherAC(&left->body)) {
        return;
    }

    Math3D_TriSetCoords(&D_801EE000, &left->dim.quad[2], &left->dim.quad[3], &left->dim.quad[1]);
    Math3D_TriSetCoords(&D_801EE038, &left->dim.quad[1], &left->dim.quad[0], &left->dim.quad[2]);
    for (rItem = right->list; rItem < right->list + right->count; rItem++) {
        Vec3f sp68;
        Vec3f sp5C;

        if (Collision_CantBeBumperAC(&rItem->body) || Collision_ToucherIsExcluded(&left->body, &rItem->body)) {
            continue;
        }

        if (Math3d_ColTriTri(&D_801EE000, &rItem->dim, &D_801EDFF0) ||
            Math3d_ColTriTri(&D_801EE038, &rItem->dim, &D_801EDFF0)) {
            if (func_800E20A4(globalCtx, left, &D_801EDFF0)) {
                Collision_TriCalcAvgPoint(rItem, &sp5C);
                Collision_QuadCalcAvgPoint(left, &sp68);
                Collision_HandleCollisionATWithAC(globalCtx, &left->base, &left->body, &sp68, &right->base, &rItem->body, &sp5C,
                              &D_801EDFF0);
                return;
            }
        }
    }
}

void CollisionCheck_AC_QuadVsQuad(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l,
                                  Collider* r) {
    static TriNorm D_801EE070[2];
    static Vec3f D_801EE0D8;
    static TriNorm D_801EE0E8[2];

    ColliderQuad* left = (ColliderQuad*)l;
    ColliderQuad* right = (ColliderQuad*)r;
    s32 i;
    s32 j;
    
    
    if (Collision_CantBeToucherAC(&left->body) || Collision_CantBeBumperAC(&right->body) || Collision_ToucherIsExcluded(&left->body, &right->body)) {
        return;
    }

    Math3D_TriSetCoords(&D_801EE0E8[0], &left->dim.quad[2], &left->dim.quad[3], &left->dim.quad[1]);
    Math3D_TriSetCoords(&D_801EE0E8[1], &left->dim.quad[2], &left->dim.quad[1], &left->dim.quad[0]);
    Math3D_TriSetCoords(&D_801EE070[0], &right->dim.quad[2], &right->dim.quad[3], &right->dim.quad[1]);
    Math3D_TriSetCoords(&D_801EE070[1], &right->dim.quad[2], &right->dim.quad[1], &right->dim.quad[0]);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            if (Math3d_ColTriTri(&D_801EE0E8[j], &D_801EE070[i], &D_801EE0D8) &&
                func_800E20A4(globalCtx, left, &D_801EE0D8)) {
                Vec3f sp64;
                Vec3f sp58;

                Collision_QuadCalcAvgPoint(left, &sp64);
                Collision_QuadCalcAvgPoint(right, &sp58);
                Collision_HandleCollisionATWithAC(globalCtx, &left->base, &left->body, &sp64, &right->base, &right->body, &sp58,
                              &D_801EE0D8);
                return;
            }
        }
    }
}

void CollisionCheck_AC_QuadVsSph(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *l, Collider *r) {
    static TriNorm D_801EE150;
    static TriNorm D_801EE188;

    ColliderQuad* left = (ColliderQuad*)l;
    Vec3f sp60;
    ColliderSph* right = (ColliderSph*)r;
    Vec3f sp50;
    Vec3f sp44;

    if (Collision_CantBeToucherAC(&left->body) || Collision_CantBeBumperAC(&right->body) || Collision_ToucherIsExcluded(&left->body, &right->body)) {
        return;
    }

    Math3D_TriSetCoords(&D_801EE150, &left->dim.quad[2], &left->dim.quad[3], &left->dim.quad[1]);
    Math3D_TriSetCoords(&D_801EE188, &left->dim.quad[2], &left->dim.quad[1], &left->dim.quad[0]);
    if (Math3D_ColSphereTri(&right->dim.worldSphere, &D_801EE150, &sp60) || 
        Math3D_ColSphereTri(&right->dim.worldSphere, &D_801EE188, &sp60)) {
        if (func_800E20A4(globalCtx, left, &sp60)) {
            Math_Vec3s_ToVec3f(&sp44, &right->dim.worldSphere.center);
            Collision_QuadCalcAvgPoint(left, &sp50);
            Collision_HandleCollisionATWithAC(globalCtx, &left->base, &left->body, &sp50, &right->base, &right->body, &sp44, &sp60);
        }
    }
}

void CollisionCheck_AC_SphVsJntSph(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *l, Collider *r) {
    ColliderSph* left = (ColliderSph*)l;
    ColliderJntSph* right = (ColliderJntSph*)r;
    ColliderJntSphItem* rItem = (ColliderJntSphItem*)r;
    f32 sp90;
    f32 sp8C;
    f32 temp_f0;
    Vec3f sp7C;
    Vec3f sp70;
    Vec3f sp64;

    if (right->count <= 0 || right->list == NULL || Collision_CantBeToucherAC(&left->body)){
        return;
    }

    for (rItem = right->list; rItem < right->list + right->count; rItem++) {
        if (Collision_CantBeBumperAC(&rItem->body) || Collision_ToucherIsExcluded(&left->body, &rItem->body)) {
            continue;
        }

        if (Math3D_ColSphereSphereIntersectAndDistance(&left->dim.worldSphere, &rItem->dim.worldSphere, &sp90, &sp8C)) {
            Math_Vec3s_ToVec3f(&sp70, &left->dim.worldSphere.center);
            Math_Vec3s_ToVec3f(&sp64, &rItem->dim.worldSphere.center);
            if (!(fabsf(sp8C) < 0.008f)) {
                temp_f0 = rItem->dim.worldSphere.radius / sp8C;
                sp7C.x = ((sp70.x - sp64.x) * temp_f0) + sp64.x;
                sp7C.y = ((sp70.y - sp64.y) * temp_f0) + sp64.y;
                sp7C.z = ((sp70.z - sp64.z) * temp_f0) + sp64.z;
            } else {
                Math_Vec3f_Copy(&sp7C, &sp70);
            }
            Collision_HandleCollisionATWithAC(globalCtx, &left->base, &left->body, &sp70, &right->base, &rItem->body, &sp64, &sp7C);
        }
    }
}

void CollisionCheck_AC_SphVsCyl(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *l, Collider *r) {
    ColliderSph* left = (ColliderSph*)l;
    ColliderCylinder* right = (ColliderCylinder*)r;
    f32 sp6C;
    f32 sp68;
    Vec3f sp5C;
    Vec3f sp50;
    Vec3f sp44;

    if (Collision_CantBeToucherAC(&left->body) || Collision_CantBeBumperAC(&right->body) || Collision_ToucherIsExcluded(&left->body, &right->body)) {
        return;
    }

    if (Math3D_ColSphereCylinderDistanceAndAmount(&left->dim.worldSphere, &right->dim, &sp6C, &sp68)) {
        Math_Vec3s_ToVec3f(&sp50, &left->dim.worldSphere.center);
        Math_Vec3s_ToVec3f(&sp44, &right->dim.pos);
        if (!(fabsf(sp68) < 0.008f)) {
            f32 temp_f0 = right->dim.radius / sp68;

            if (temp_f0 <= 1.0f) {
                sp5C.x = ((sp50.x - sp44.x) * temp_f0) + sp44.x;
                sp5C.y = ((sp50.y - sp44.y) * temp_f0) + sp44.y;
                sp5C.z = ((sp50.z - sp44.z) * temp_f0) + sp44.z;
            } else {
                Math_Vec3f_Copy(&sp5C, &sp50);
            }
        } else {
            Math_Vec3f_Copy(&sp5C, &sp50);
        }
        Collision_HandleCollisionATWithAC(globalCtx, &left->base, &left->body, &sp50, &right->base, &right->body, &sp44, &sp5C);
    }
}

void CollisionCheck_AC_SphVsTris(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *l, Collider *r) {
    ColliderSph* left = (ColliderSph*)l;
    ColliderTris* right = (ColliderTris*)r;
    ColliderTrisItem* rItem;
    
    if (Collision_CantBeToucherAC(&left->body)) {
        return;
    }

    for (rItem = right->list; rItem < right->list + right->count; rItem++) {
        Vec3f sp68;
        Vec3f sp5C;
        Vec3f sp50;

        if (Collision_CantBeBumperAC(&rItem->body) || Collision_ToucherIsExcluded(&left->body, &rItem->body)) {
            continue;
        }

        if (Math3D_ColSphereTri(&left->dim.worldSphere, &rItem->dim, &sp68)) {
            Math_Vec3s_ToVec3f(&sp5C, &left->dim.worldSphere.center);
            Collision_TriCalcAvgPoint(rItem, &sp50);
            Collision_HandleCollisionATWithAC(globalCtx, &left->base, &left->body, &sp5C, &right->base, &rItem->body, &sp50, &sp68);
            return;
        }
    }
}

void CollisionCheck_AC_SphVsQuad(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *l, Collider *r) {
    static TriNorm D_801EE6C8;
    static TriNorm D_801EE700;

    ColliderSph* left = (ColliderSph*)l;
    Vec3f sp60;
    ColliderQuad* right = (ColliderQuad*)r;
    Vec3f sp50;
    Vec3f sp44;

    if (Collision_CantBeToucherAC(&left->body) || Collision_CantBeBumperAC(&right->body) || Collision_ToucherIsExcluded(&left->body, &right->body)) {
        return;
    }

    Math3D_TriSetCoords(&D_801EE6C8, &right->dim.quad[2], &right->dim.quad[3], &right->dim.quad[1]);
    Math3D_TriSetCoords(&D_801EE700, &right->dim.quad[1], &right->dim.quad[0], &right->dim.quad[2]);
    if (Math3D_ColSphereTri(&left->dim.worldSphere, &D_801EE6C8, &sp60) || Math3D_ColSphereTri(&left->dim.worldSphere, &D_801EE700, &sp60)) {
        Math_Vec3s_ToVec3f(&sp50, &left->dim.worldSphere.center);
        Collision_QuadCalcAvgPoint(right, &sp44);
        Collision_HandleCollisionATWithAC(globalCtx, &left->base, &left->body, &sp50, &right->base, &right->body, &sp44, &sp60);
    }
}

void CollisionCheck_AC_SphVsSph(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *l, Collider *r) {
    ColliderSph* left = (ColliderSph*)l;
    ColliderSph* right = (ColliderSph*)r;
    f32 sp6C;
    f32 sp68;
    f32 temp_f0;
    Vec3f sp58;
    Vec3f sp4C;
    Vec3f sp40;

    if (Collision_CantBeToucherAC(&left->body) || Collision_CantBeBumperAC(&right->body) || Collision_ToucherIsExcluded(&left->body, &right->body)) {
        return;
    }

    if (Math3D_ColSphereSphereIntersectAndDistance(&left->dim.worldSphere, &right->dim.worldSphere, &sp6C, &sp68)) {
        Math_Vec3s_ToVec3f(&sp4C, &left->dim.worldSphere.center);
        Math_Vec3s_ToVec3f(&sp40, &right->dim.worldSphere.center);
        if (!(fabsf(sp68) < 0.008f)) {
            temp_f0 = right->dim.worldSphere.radius / sp68;
            sp58.x = ((sp4C.x - sp40.x) * temp_f0) + sp40.x;
            sp58.y = ((sp4C.y - sp40.y) * temp_f0) + sp40.y;
            sp58.z = ((sp4C.z - sp40.z) * temp_f0) + sp40.z;
        } else {
            Math_Vec3f_Copy(&sp58, &sp4C);
        }
        Collision_HandleCollisionATWithAC(globalCtx, &left->base, &left->body, &sp4C, &right->base, &right->body, &sp40, &sp58);
    }
}

void func_800E60C0(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    ColliderJntSph* spheres = (ColliderJntSph*)collider;
    ColliderJntSphItem* item;
    
    for (item = spheres->list; item < spheres->list + spheres->count; item++) {
        if ((item->body.bumperFlags & 0x80) && (item->body.acHitItem != NULL)) {
            if (!(item->body.acHitItem->toucherFlags & 0x40)) {
                Vec3f sp24;

                Math_Vec3s_ToVec3f(&sp24, &item->body.bumper.unk_06);
                func_800E3168(globalCtx, item->body.acHit, item->body.acHitItem, &spheres->base, &item->body, &sp24);
                item->body.acHitItem->toucherFlags |= 0x40;
                return;
            }
        }
    }
}

void func_800E61A0(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    ColliderCylinder* cylinder = (ColliderCylinder*)collider;
    
    if ((cylinder->body.bumperFlags & 0x80) && (cylinder->body.acHitItem != NULL)) {
        if (!(cylinder->body.acHitItem->toucherFlags & 0x40)) {
            Vec3f sp28;

            Math_Vec3s_ToVec3f(&sp28, &cylinder->body.bumper.unk_06);
            func_800E3168(globalCtx, cylinder->body.acHit, cylinder->body.acHitItem, &cylinder->base, &cylinder->body, &sp28);
            cylinder->body.acHitItem->toucherFlags |= 0x40;
        }
    }
}

void func_800E6238(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    ColliderTris* tris = (ColliderTris*)collider;
    ColliderTrisItem* item;
    
    for (item = tris->list; item < tris->list + tris->count; item++) {
        if ((item->body.bumperFlags & 0x80) && (item->body.acHitItem != NULL)) {
            if (!(item->body.acHitItem->toucherFlags & 0x40)) {
                Vec3f sp24;

                Math_Vec3s_ToVec3f(&sp24, &item->body.bumper.unk_06);
                func_800E3168(globalCtx, item->body.acHit, item->body.acHitItem, &tris->base, &item->body, &sp24);
                item->body.acHitItem->toucherFlags |= 0x40;
                return;
            }
        }
    }
}

void func_800E6320(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    ColliderQuad* quad = (ColliderQuad*)collider;

    if ((quad->body.bumperFlags & 0x80) && (quad->body.acHitItem != NULL)) {
        if (!(quad->body.acHitItem->toucherFlags & 0x40)) {
            Vec3f sp28;
            
            Math_Vec3s_ToVec3f(&sp28, &quad->body.bumper.unk_06);
            func_800E3168(globalCtx, quad->body.acHit, quad->body.acHitItem, &quad->base, &quad->body, &sp28);
            quad->body.acHitItem->toucherFlags |= 0x40;
        }
    }
}

void func_800E63B8(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *collider) {
    ColliderSph *sphere = (ColliderSph *)collider;

    if ((sphere->body.bumperFlags & 0x80) && (sphere->body.acHitItem != NULL)) {
        if (!(sphere->body.acHitItem->toucherFlags & 0x40)) {
            Vec3f sp28;

            Math_Vec3s_ToVec3f(&sp28, &sphere->body.bumper.unk_06);
            func_800E3168(globalCtx, sphere->body.acHit, sphere->body.acHitItem, &sphere->base, &sphere->body, &sp28);
            sphere->body.acHitItem->toucherFlags |= 0x40;
        }
    }
}

void func_800E6450(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx) {
    static void (*D_801BA3A8[5])(GlobalContext*, CollisionCheckContext*, Collider*) = {
        func_800E60C0,
        func_800E61A0,
        func_800E6238,
        func_800E6320,
        func_800E63B8,
    };

    Collider** col;
    Collider* temp;

    for (col = colChkCtx->colAc; col < colChkCtx->colAc + colChkCtx->colAcCount; col++) {
        temp = *col;
        if ((temp != NULL) && (temp->acFlags & 1)) {
            if (temp->actor == NULL || temp->actor->update != NULL) {
                (*D_801BA3A8[temp->shape])(globalCtx, colChkCtx, temp);
            }
        }
    }
}

void CollisionCheck_AC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    static void (*collisionFuncsATvsAC[5][5])(GlobalContext*, CollisionCheckContext*, Collider*, Collider*) = {
        { CollisionCheck_AC_JntSphVsJntSph, CollisionCheck_AC_JntSphVsCyl, CollisionCheck_AC_JntSphVsTris, CollisionCheck_AC_JntSphVsQuad, CollisionCheck_AC_JntSphVsSph, },
        { CollisionCheck_AC_CylVsJntSph, CollisionCheck_AC_CylVsCyl, CollisionCheck_AC_CylVsTris, CollisionCheck_AC_CylVsQuad, CollisionCheck_AC_CylVsSph, },
        { CollisionCheck_AC_TrisVsJntSph, CollisionCheck_AC_TrisVsCyl, CollisionCheck_AC_TrisVsTris, CollisionCheck_AC_TrisVsQuad, CollisionCheck_AC_TrisVsSph, },
        { CollisionCheck_AC_QuadVsJntSph, CollisionCheck_AC_QuadVsCyl, CollisionCheck_AC_QuadVsTris, CollisionCheck_AC_QuadVsQuad, CollisionCheck_AC_QuadVsSph, },
        { CollisionCheck_AC_SphVsJntSph, CollisionCheck_AC_SphVsCyl, CollisionCheck_AC_SphVsTris, CollisionCheck_AC_SphVsQuad, CollisionCheck_AC_SphVsSph, },
    };

    Collider** col;
    Collider* temp;

    for (col = colChkCtx->colAc; col < colChkCtx->colAc + colChkCtx->colAcCount; col++) {
        temp = *col;
        if (temp == NULL) {
            continue;
        } else if (!(temp->acFlags & 1)) {
            continue;
        } else if (temp->actor != NULL && temp->actor->update == NULL) {
            continue;
        } else if (!((temp->acFlags & collider->atFlags) & 0x38)) {
            continue;
        } else if (collider == temp) {
            continue;
        }

        else if ((collider->atFlags & 0x40) || collider->actor == NULL || temp->actor != collider->actor) {
            collisionFuncsATvsAC[collider->shape][temp->shape](globalCtx, colChkCtx, collider, temp);
        }
    }
}

// Test Attack Collisions
void CollisionCheck_ATvsAC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx) {
    Collider** colAt;
    Collider* colliderAt;

    if ((colChkCtx->colAtCount != 0) && (colChkCtx->colAcCount != 0)) {
        for (colAt = colChkCtx->colAt; colAt < colChkCtx->colAt + colChkCtx->colAtCount; colAt++) {
            colliderAt = *colAt;
            if ((colliderAt != NULL) && (colliderAt->atFlags & 1)) {
                if ((colliderAt->actor == NULL) || (colliderAt->actor->update != NULL)) {
                    CollisionCheck_AC(globalCtx, colChkCtx, colliderAt);
                }
            }
        }
        func_800E6450(globalCtx, colChkCtx);
    }
}

// Get mass type
s32 func_800E6724(u8 mass) {
    if (mass == 0xFF) {
        return 0;
    }
    if (mass == 0xFE) {
        return 1;
    }
    return 2;
}

// SetOC collision, perform elastic collision
void CollisionCheck_OCvsOC(GlobalContext* globalCtx, Collider* left, ColliderBody* leftBody, Vec3f* leftv, Collider* right, ColliderBody* rightBody,
                   Vec3f* rightv, f32 arg6) {
    f32 temp_f0;
    f32 leftDisplacementFactor;
    f32 rightDisplacementFactor;
    f32 xzDist;
    f32 leftMass;
    f32 rightMass;
    f32 totalMass;
    f32 inverseTotalMass;
    f32 xDelta;
    f32 zDelta;
    Actor* leftActor;
    Actor* rightActor;
    s32 rightMassType;
    s32 leftMassType;

    leftActor = left->actor;
    rightActor = right->actor;
    left->maskA |= 2;
    left->oc = rightActor;
    leftBody->ocFlags |= 2;
    if ((right->maskB & 8) != 0) {
        left->maskB |= 1;
    }

    right->oc = leftActor;
    right->maskA |= 2;
    rightBody->ocFlags |= 2;
    if ((left->maskB & 8) != 0) {
        right->maskB |= 1;
    }

    if (leftActor == NULL || rightActor == NULL || (left->maskA & 4) || (right->maskA & 4)) {
        return;
    }

    leftMassType = func_800E6724(leftActor->colChkInfo.mass);
    rightMassType = func_800E6724(rightActor->colChkInfo.mass);
    leftMass = leftActor->colChkInfo.mass;
    rightMass = rightActor->colChkInfo.mass;
    totalMass = leftMass + rightMass;
    if (fabsf(totalMass) < 0.008f) {
        leftMass = 1;
        rightMass = 1;
        totalMass = 2;
    }
    xDelta = rightv->x - leftv->x;
    zDelta = rightv->z - leftv->z;
    xzDist = sqrtf(SQ(xDelta) + SQ(zDelta));

    if (leftMassType == 0) {
        if (rightMassType == 0) {
            return;
        } else {
            leftDisplacementFactor = 0;
            rightDisplacementFactor = 1;
        }
    } else if (leftMassType == 1) {
        if (rightMassType == 0) {
            leftDisplacementFactor = 1;
            rightDisplacementFactor = 0;
        } else if (rightMassType == 1) {
            leftDisplacementFactor = 0.5f;
            rightDisplacementFactor = 0.5f;
        } else {
            leftDisplacementFactor = 0;
            rightDisplacementFactor = 1;
        }
    } else {
        if (rightMassType == 2) {
            inverseTotalMass = 1 / totalMass;
            leftDisplacementFactor = rightMass * inverseTotalMass;
            rightDisplacementFactor = leftMass * inverseTotalMass;
        } else {
            leftDisplacementFactor = 1;
            rightDisplacementFactor = 0;
        }
    }

    if (!(fabsf(xzDist) < 0.008f)) {
        temp_f0 = arg6 / xzDist;
        xDelta *= temp_f0;
        zDelta *= temp_f0;
        leftActor->colChkInfo.displacement.x += -xDelta * leftDisplacementFactor;
        leftActor->colChkInfo.displacement.z += -zDelta * leftDisplacementFactor;
        rightActor->colChkInfo.displacement.x += xDelta * rightDisplacementFactor;
        rightActor->colChkInfo.displacement.z += zDelta * rightDisplacementFactor;
    } else if (!(arg6 == 0.0f)) {
        leftActor->colChkInfo.displacement.x += -arg6 * leftDisplacementFactor;
        rightActor->colChkInfo.displacement.x += arg6 * rightDisplacementFactor;
    } else {
        leftActor->colChkInfo.displacement.x -= leftDisplacementFactor;
        rightActor->colChkInfo.displacement.x += rightDisplacementFactor;
    }
}

void CollisionCheck_OC_JntSphVsJntSph(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l,
                                      Collider* r) {
    ColliderJntSph* left = (ColliderJntSph*)l;
    ColliderJntSph* right = (ColliderJntSph*)r;
    ColliderJntSphItem* lItem;
    ColliderJntSphItem* rItem;
    f32 sp74;
    Vec3f sp68;
    Vec3f sp5C;

    if (left->count <= 0 || left->list == NULL || right->count <= 0 || right->list == NULL || 
        !(left->base.maskA & 1) || !(right->base.maskA & 1)) {
        return;
    }

    for (lItem = left->list; lItem < left->list + left->count; lItem++) {
        if (!(lItem->body.ocFlags & 1)) {
            continue;
        }

        for (rItem = right->list; rItem < right->list + right->count; rItem++) {
            if (!(rItem->body.ocFlags & 1)) {
                continue;
            }
            
            if (Math3D_ColSphereSphereIntersect(&lItem->dim.worldSphere, &rItem->dim.worldSphere, &sp74)) {
                Math_Vec3s_ToVec3f(&sp68, &lItem->dim.worldSphere.center);
                Math_Vec3s_ToVec3f(&sp5C, &rItem->dim.worldSphere.center);
                CollisionCheck_OCvsOC(globalCtx, &left->base, &lItem->body, &sp68, &right->base, &rItem->body, &sp5C, sp74);
            }
        }
    }
}

void CollisionCheck_OC_JntSphVsCyl(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l,
                                   Collider* r) {
    ColliderJntSph* left = (ColliderJntSph*)l;
    ColliderCylinder* right = (ColliderCylinder*)r;
    ColliderJntSphItem* lItem;
    f32 sp78;
    Vec3f sp6C;
    Vec3f sp60;

    if (left->count <= 0 || left->list == NULL || !(left->base.maskA & 1) || !(right->base.maskA & 1) || !(right->body.ocFlags & 1)) {
        return;
    }

    for (lItem = left->list; lItem < left->list + left->count; lItem++) {
        if (!(lItem->body.ocFlags & 1)) {
            continue;
        }

        if (Math3D_ColSphereCylinderDistance(&lItem->dim.worldSphere, &right->dim, &sp78)) {
            Math_Vec3s_ToVec3f(&sp6C, &lItem->dim.worldSphere.center);
            Math_Vec3s_ToVec3f(&sp60, &right->dim.pos);
            CollisionCheck_OCvsOC(globalCtx, &left->base, &lItem->body, &sp6C, &right->base, &right->body, &sp60, sp78);
        }
    }
}

void CollisionCheck_OC_JntSphVsSph(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *l, Collider *r) {
    ColliderJntSph* left = (ColliderJntSph*)l;
    ColliderSph* right = (ColliderSph*)r;
    ColliderJntSphItem* lItem;
    f32 sp78;
    Vec3f sp6C;
    Vec3f sp60;

    if (left->count <= 0 || left->list == NULL || !(left->base.maskA & 1) || !(right->base.maskA & 1) || !(right->body.ocFlags & 1)) {
        return;
    }

    for (lItem = left->list; lItem < left->list + left->count; lItem++) {
        if (!(lItem->body.ocFlags & 1)) {
            continue;
        }

        if (Math3D_ColSphereSphereIntersect(&lItem->dim.worldSphere, &right->dim.worldSphere, &sp78)) {
            Math_Vec3s_ToVec3f(&sp6C, &lItem->dim.worldSphere.center);
            Math_Vec3s_ToVec3f(&sp60, &right->dim.worldSphere.center);
            CollisionCheck_OCvsOC(globalCtx, &left->base, &lItem->body, &sp6C, &right->base, &right->body, &sp60, sp78);
        }
    }
}

void CollisionCheck_OC_CylVsJntSph(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *l, Collider *r) {
    CollisionCheck_OC_JntSphVsCyl(globalCtx, colChkCtx, r, l);
}

void CollisionCheck_OC_CylVsCyl(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l, Collider* r) {
    ColliderCylinder* left = (ColliderCylinder*)l;
    ColliderCylinder* right = (ColliderCylinder*)r;
    f32 sp4C;
    Vec3f sp40;
    Vec3f sp34;

    if (!(left->base.maskA & 1) || !(right->base.maskA & 1)) {
        return;
    }

    if (!(left->body.ocFlags & 1) || !(right->body.ocFlags & 1)) {
        return;
    }

    if (Math3D_ColCylinderCylinderAmount(&left->dim, &right->dim, &sp4C)) {
        Math_Vec3s_ToVec3f(&sp40, &left->dim.pos);
        Math_Vec3s_ToVec3f(&sp34, &right->dim.pos);
        CollisionCheck_OCvsOC(globalCtx, &left->base, &left->body, &sp40, &right->base, &right->body, &sp34, sp4C);
    }
}

void CollisionCheck_OC_CylVsSph(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* l, Collider* r) {
    ColliderCylinder* left = (ColliderCylinder*)l;
    ColliderSph* right = (ColliderSph*)r;
    f32 sp4C;
    Vec3f sp40;
    Vec3f sp34;

    if (!(left->base.maskA & 1) || !(left->body.ocFlags & 1)) {
        return;
    }

    if (!(right->base.maskA & 1) || !(right->body.ocFlags & 1)) {
        return;
    }

    if (Math3D_ColSphereCylinderDistance(&right->dim.worldSphere, &left->dim, &sp4C)) {
        Math_Vec3s_ToVec3f(&sp40, &left->dim.pos);
        Math_Vec3s_ToVec3f(&sp34, &right->dim.worldSphere.center);
        CollisionCheck_OCvsOC(globalCtx, &left->base, &left->body, &sp40, &right->base, &right->body, &sp34, sp4C);
    }
}

void CollisionCheck_OC_SphVsJntSph(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *l, Collider *r) {
    CollisionCheck_OC_JntSphVsSph(globalCtx, colChkCtx, r, l);
}

void CollisionCheck_OC_SphVsCyl(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *l, Collider *r) {
    CollisionCheck_OC_CylVsSph(globalCtx, colChkCtx, r, l);
}

void CollisionCheck_OC_SphVsSph(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *l, Collider *r) {
    ColliderSph* left = (ColliderSph*)l;
    ColliderSph* right = (ColliderSph*)r;
    f32 sp54;
    Vec3f sp48;
    Vec3f sp3C;

    if (!(left->base.maskA & 1) || !(left->body.ocFlags & 1)) {
        return;
    }

    if (!(right->base.maskA & 1) || !(right->body.ocFlags & 1)) {
        return;
    }

    if (Math3D_ColSphereSphereIntersect(&left->dim.worldSphere, &right->dim.worldSphere, &sp54)) {
        Math_Vec3s_ToVec3f(&sp48, &left->dim.worldSphere.center);
        Math_Vec3s_ToVec3f(&sp3C, &right->dim.worldSphere.center);
        CollisionCheck_OCvsOC(globalCtx, &left->base, &left->body, &sp48, &right->base, &right->body, &sp3C, sp54);
    }
}

// CollisionCheck_OC test ?
s32 func_800E7264(Collider* collider) {
    if (!(collider->maskA & 1)) {
        return 1;
    }
    return 0;
}

// CollisionCheck_OC test ?
s32 func_800E7288(Collider* arg0, Collider* arg1) {
    if (!((arg0->maskA & arg1->maskB) & 0x38) || !((arg0->maskB & arg1->maskA) & 0x38) ||
        ((arg0->maskB & 2) && (arg1->maskB & 4)) || ((arg1->maskB & 2) && (arg0->maskB & 4))) {
        return 1;
    }

    if (arg0->actor == arg1->actor) {
        return 1;
    }
    return 0;
}

void Collision_DoOTWithOT(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx) {
    static void (*collisionFuncTableOTwithOT[5][5])(GlobalContext*, CollisionCheckContext*, Collider*, Collider*) = {
        { CollisionCheck_OC_JntSphVsJntSph, CollisionCheck_OC_JntSphVsCyl, NULL, NULL, CollisionCheck_OC_JntSphVsSph, },
        { CollisionCheck_OC_CylVsJntSph, CollisionCheck_OC_CylVsCyl, NULL, NULL, CollisionCheck_OC_CylVsSph, },
        { NULL, NULL, NULL, NULL, NULL, },
        { NULL, NULL, NULL, NULL, NULL, },
        { CollisionCheck_OC_SphVsJntSph, CollisionCheck_OC_SphVsCyl, NULL, NULL, CollisionCheck_OC_SphVsSph, },
    };

    Collider** phi_s2;
    Collider** phi_s0;
    Collider** new_var;
    Collider** new_var2;
    void (*test)(GlobalContext*, CollisionCheckContext*, Collider*, Collider*);

    for (phi_s2 = colChkCtx->colOc; phi_s2 < colChkCtx->colOc + colChkCtx->colOcCount; phi_s2++) {
        if (*phi_s2 == NULL || func_800E7264(*phi_s2)) {
            continue;
        }
        for (phi_s0 = phi_s2 + 1; phi_s0 < colChkCtx->colOc + colChkCtx->colOcCount; phi_s0++) {
            if (*phi_s0 == NULL || func_800E7264(*phi_s0) || func_800E7288(*phi_s2, *phi_s0)) {
                continue;
            }
            new_var2 = phi_s0;
            new_var = phi_s2;
            test = collisionFuncTableOTwithOT[(*new_var)->shape][(*new_var2)->shape];
            if (test == NULL) {
                continue;
            }
            (*test)(globalCtx, colChkCtx, *new_var, *new_var2);
        }
    }
}

// Initialize CollisionCheckInfo
void func_800E7494(CollisionCheckInfo* info) {
    static CollisionCheckInfo init = { NULL, { 0, 0, 0 }, 10, 10, 0, 255, 8, 0, 0, 0, 0 };
    *info = init;
}

void func_800E74DC(CollisionCheckInfo *info) {
    info->damage = 0;
    info->damageEffect = 0;
    info->atHitEffect = 0;
    info->acHitEffect = 0;
    info->displacement.x = info->displacement.y = info->displacement.z = 0.0f;
}


void func_800E7508(CollisionCheckInfo* info, CollisionCheckInfoInit* init) {
    info->health = init->health;
    info->unk_10 = init->unk_02;
    info->unk_12 = init->unk_04;
    info->mass = init->mass;
}

void func_800E7530(CollisionCheckInfo* info, DamageTable* damageTable, CollisionCheckInfoInit* init) {
    info->health = init->health;
    info->damageTable = damageTable;
    info->unk_10 = init->unk_02;
    info->unk_12 = init->unk_04;
    info->mass = init->mass;
}

void func_800E755C(CollisionCheckInfo* info, DamageTable* damageTable, CollisionCheckInfoInit2* init) {
    info->health = init->health;
    info->damageTable = damageTable;
    info->unk_10 = init->unk_02;
    info->unk_12 = init->unk_04;
    info->unk_14 = init->unk_06;
    info->mass = init->mass;
}

void func_800E7590(CollisionCheckInfo* info, s32 index, CollisionCheckInfoInit2* init) {
    func_800E755C(info, DamageTable_Get(index), init);
}

// Apply AC damage effect
void func_800E75C8(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider, ColliderBody* body) {
    f32 sp3C;
    f32 sp38 = 0.0f;
    s32 pad;
    Collider* acHit;
    ColliderBody* acHitItem;
    s32 pad2;
    s32 sp24;

    if (collider->actor == NULL || !(collider->acFlags & 2)) {
        return;
    }

    if (!(body->bumperFlags & 2) || (body->bumperFlags & 0x10)) {
        return;
    }

    acHit = body->acHit;
    acHitItem = body->acHitItem;
    if (acHit == NULL || acHitItem == NULL || collider == NULL || body == NULL) {
        return;
    }

    sp3C = Collision_GetDamageAndEffectOnBumper(acHit, acHitItem, collider, body, &sp24);
    if (Collision_GetToucherDamage(acHit, acHitItem, collider, body) != 0) {
        if (sp3C < 1.0f) {
            if (sp24 == 0) {
                return;
            }
        } else {
            sp38 = func_800E04BC(sp3C, body);
            if (sp38 < 1.0f && sp24 == 0) {
                return;
            }
        }
    }

    if (collider->actor->colChkInfo.damageTable != NULL) {
        collider->actor->colChkInfo.damageEffect = sp24;
    }

    if (!(collider->acFlags & 4) || (collider->acFlags & 4 && acHitItem->toucher.collidesWith == 0x20000000)) {
        if (collider->actor->colChkInfo.damage < sp38) {
            collider->actor->colChkInfo.damage = sp38;
        }
    }
}

// Apply ColliderJntSph AC damage effect
void func_800E77EC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    ColliderJntSph* spheres = (ColliderJntSph*)collider;
    s32 i;

    if (spheres->count <= 0 || spheres->list == NULL) {
        return;
    }

    for (i = 0; i < spheres->count; i++) {
        func_800E75C8(globalCtx, colChkCtx, &spheres->base, &spheres->list[i].body);
    }
}

// Apply ColliderCylinder AC damage effect
void func_800E7894(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    ColliderCylinder* cylinder = (ColliderCylinder*)collider;

    func_800E75C8(globalCtx, colChkCtx, &cylinder->base, &cylinder->body);
}

// Apply ColliderTris AC damage effect
void func_800E78B4(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    ColliderTris* tris = (ColliderTris*)collider;
    s32 i;

    for (i = 0; i < tris->count; i++) {
        func_800E75C8(globalCtx, colChkCtx, collider, &tris->list[i].body);
    }
}

// Apply ColliderQuad AC damage effect
void func_800E7948(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Collider* collider) {
    ColliderQuad* quad = (ColliderQuad*)collider;

    func_800E75C8(globalCtx, colChkCtx, &quad->base, &quad->body);
}

void func_800E7968(GlobalContext *globalCtx, CollisionCheckContext *colChkCtx, Collider *collider) {
    ColliderSph* sphere = (ColliderSph*)collider;

    func_800E75C8(globalCtx, colChkCtx, &sphere->base, &sphere->body);
}

// Apply all AC damage effects
void func_800E7988(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx) {
    static void (*D_801BA4A0[5])(GlobalContext*, CollisionCheckContext*, Collider*) = {
        func_800E77EC,
        func_800E7894,
        func_800E78B4,
        func_800E7948,
        func_800E7968,
    };

    Collider* collider;
    s32 i;

    for (i = 0; i < colChkCtx->colAcCount; i++) {
        collider = colChkCtx->colAc[i];
        if (collider == 0) {
            continue;
        }
        if ((collider->acFlags & 0x40)) {
            continue;
        }

        D_801BA4A0[collider->shape](globalCtx, colChkCtx, collider);
    }
}

s32 CollisionCheck_generalLineOcCheck_JntSph(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx,
                                             Collider* collider, Vec3f* arg3, Vec3f* arg4) {
    static Linef D_801EDEB0;

    ColliderJntSph* jntSph = (ColliderJntSph*)collider;
    ColliderJntSphItem* item;
    s32 phi_s0;

    for (phi_s0 = 0; phi_s0 < jntSph->count; phi_s0++) {
        item = &jntSph->list[phi_s0];

        if (!(item->body.ocFlags & 1)) {
            continue;
        }

        D_801EDEB0.a = *arg3;
        D_801EDEB0.b = *arg4;
        if (Math3D_ColSphereLineSeg(&item->dim.worldSphere, &D_801EDEB0)) {
            return 1;
        }
    }
    return 0;
}

s32 CollisionCheck_generalLineOcCheck_Cyl(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx,
                                          Collider* collider, Vec3f* arg3, Vec3f* arg4) {
    static Vec3f D_801EDF38;
    static Vec3f D_801EDF48;

    ColliderCylinder* cylinder = (ColliderCylinder*)collider;

    if (!(cylinder->body.ocFlags & 1)) {
        return 0;
    }

    if (Math3D_CylVsLineSeg(&cylinder->dim, arg3, arg4, &D_801EDF38, &D_801EDF48)) {
        return 1;
    }

    return 0;
}

s32 CollisionCheck_generalLineOcCheck_Sph(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx,
                                          Collider* collider, Vec3f* arg3, Vec3f* arg4) {
    static Linef D_801EDFC8;

    ColliderSph* sphere = (ColliderSph*)collider;

    if (!(sphere->body.ocFlags & 1)) {
        return 0;
    }

    D_801EDFC8.a = *arg3;
    D_801EDFC8.b = *arg4;
    
    if (Math3D_ColSphereLineSeg(&sphere->dim.worldSphere, &D_801EDFC8)) {
        return 1;
    }

    return 0;
}

s32 CollisionCheck_GeneralLineOcCheck(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Vec3f* camera_3C,
                                      Vec3f* arg3, Actor** arg4, s32 arg5) {
    static s32 (*D_801BA4B4[5])(GlobalContext*, CollisionCheckContext*, Collider*, Vec3f*, Vec3f*) = {
        CollisionCheck_generalLineOcCheck_JntSph,
        CollisionCheck_generalLineOcCheck_Cyl,
        NULL,
        NULL,
        CollisionCheck_generalLineOcCheck_Sph,
    };

    Collider* collider;
    s32 (*t)(GlobalContext*, CollisionCheckContext*, Collider*, Vec3f*, Vec3f*);
    Collider** c;
    s32 i;
    s32 test;
    s32 result;

    result = 0;
    for (c = colChkCtx->colOc; c < colChkCtx->colOc + colChkCtx->colOcCount; c++) {
        if (func_800E7264(*c)) {
            continue;
        }
        test = 0;
        for (i = 0; i < arg5; i++) {
            if ((*c)->actor == arg4[i]) {
                test = 1;
                break;
            }
        }
        if (test) {
            continue;
        }
        collider = *c;
        t = D_801BA4B4[collider->shape];
        if (t != NULL) {
            result = (*t)(globalCtx, colChkCtx, collider, camera_3C, arg3);
            if (result != NULL) {
                break;
            }
        }
    }
    return result;
}

s32 func_800E7DA8(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Vec3f* arg2, Vec3f* arg3) {
    return CollisionCheck_GeneralLineOcCheck(globalCtx, colChkCtx, arg2, arg3, NULL, 0);
}

s32 func_800E7DCC(GlobalContext* globalCtx, CollisionCheckContext* colChkCtx, Vec3f* camera_3C, Vec3f* arg3,
                  Actor** arg4, s32 arg5) {
    return CollisionCheck_GeneralLineOcCheck(globalCtx, colChkCtx, camera_3C, arg3, arg4, arg5);
}

void Collider_CylinderUpdate(Actor *actor, ColliderCylinder *cylinder) {
    cylinder->dim.pos.x = actor->currPosRot.pos.x;
    cylinder->dim.pos.y = actor->currPosRot.pos.y;
    cylinder->dim.pos.z = actor->currPosRot.pos.z;
}

// Set ColliderCylinder position
void Collision_CylinderSetLoc(ColliderCylinder* collider, Vec3s* pos) {
    collider->dim.pos.x = pos->x;
    collider->dim.pos.y = pos->y;
    collider->dim.pos.z = pos->z;
}

// Set ColliderQuad vertices
void Collision_QuadSetCoords(ColliderQuad* collider, Vec3f* a, Vec3f* b, Vec3f* c, Vec3f* d) {
    Math_Vec3f_Copy(&collider->dim.quad[2], c);
    Math_Vec3f_Copy(&collider->dim.quad[3], d);
    Math_Vec3f_Copy(&collider->dim.quad[0], a);
    Math_Vec3f_Copy(&collider->dim.quad[1], b);
    Collider_QuadCalcMidpoints(&collider->dim);
}

// Set ColliderTrisItem at index
void Collision_TriGroupSetCoordsAtIndex(ColliderTris* collider, s32 index, Vec3f* a, Vec3f* b, Vec3f* c) {
    ColliderTrisItem* item;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    item = &collider->list[index];
    Math_Vec3f_Copy(&item->dim.vtx[0], a);
    Math_Vec3f_Copy(&item->dim.vtx[1], b);
    Math_Vec3f_Copy(&item->dim.vtx[2], c);
    Math3D_UnitNormalVector(a, b, c, &sp40, &sp3C, &sp38, &sp34);
    item->dim.plane.normal.x = sp40;
    item->dim.plane.normal.y = sp3C;
    item->dim.plane.normal.z = sp38;
    item->dim.plane.originDist = sp34;
}

// Set ColliderTrisItem at index
void Collision_InitTriParamsAtIndex(GlobalContext* globalCtx, ColliderTris* collider, s32 index, ColliderTrisItemDimInit* init) {
    ColliderTrisItem* item = &collider->list[index];
    
    Collider_SetTrisItemDim(globalCtx, &item->dim, init);
}

void func_800E7FDC(s32 arg0, ColliderJntSph* collider) {
    static Vec3f D_801EE1C0;
    static Vec3f D_801EE1D0;

    s32 i;

    for (i = 0; i < collider->count; i++) {
        if (arg0 == collider->list[i].dim.joint) {
            D_801EE1C0.x = collider->list[i].dim.modelSphere.center.x;
            D_801EE1C0.y = collider->list[i].dim.modelSphere.center.y;
            D_801EE1C0.z = collider->list[i].dim.modelSphere.center.z;
            Matrix_MultVec3f(&D_801EE1C0, &D_801EE1D0);
            collider->list[i].dim.worldSphere.center.x = D_801EE1D0.x;
            collider->list[i].dim.worldSphere.center.y = D_801EE1D0.y;
            collider->list[i].dim.worldSphere.center.z = D_801EE1D0.z;
            collider->list[i].dim.worldSphere.radius =
                collider->list[i].dim.modelSphere.radius * collider->list[i].dim.scale;
        }
    }
}

// Only called in ovl_En_Encount2
void func_800E8160(ColliderJntSph* collider, s32 index, Actor* actor) {
    if (index < collider->count) {
        collider->list[index].dim.worldSphere.center.x = collider->list[index].dim.modelSphere.center.x + actor->currPosRot.pos.x;
        collider->list[index].dim.worldSphere.center.y = collider->list[index].dim.modelSphere.center.y + actor->currPosRot.pos.y;
        collider->list[index].dim.worldSphere.center.z = collider->list[index].dim.modelSphere.center.z + actor->currPosRot.pos.z;
        collider->list[index].dim.worldSphere.radius =
            collider->list[index].dim.modelSphere.radius * collider->list[index].dim.scale;
    }
}

void func_800E823C(s32 arg0, ColliderSph* collider) {
    static Vec3f D_801EE1E0;
    static Vec3f D_801EE1F0;

    if (arg0 == collider->dim.joint) {
        D_801EE1E0.x = collider->dim.modelSphere.center.x;
        D_801EE1E0.y = collider->dim.modelSphere.center.y;
        D_801EE1E0.z = collider->dim.modelSphere.center.z;
        Matrix_MultVec3f(&D_801EE1E0, &D_801EE1F0);
        collider->dim.worldSphere.center.x = D_801EE1F0.x;
        collider->dim.worldSphere.center.y = D_801EE1F0.y;
        collider->dim.worldSphere.center.z = D_801EE1F0.z;
        collider->dim.worldSphere.radius =
            collider->dim.modelSphere.radius * collider->dim.scale;
    }
}

void func_800E8318(GlobalContext* globalCtx, Vec3f* pos) {
    static EffSparkParams D_801EE200;
    s32 sp24;

    D_801EE200.position.x = pos->x;
    D_801EE200.position.y = pos->y;
    D_801EE200.position.z = pos->z;
    D_801EE200.particleFactor1 = 5;
    D_801EE200.particleFactor2 = 5;
    D_801EE200.colorStart[0].red = 128;
    D_801EE200.colorStart[0].green = 0;
    D_801EE200.colorStart[0].blue = 64;
    D_801EE200.colorStart[0].alpha = 255;
    D_801EE200.colorStart[1].red = 128;
    D_801EE200.colorStart[1].green = 0;
    D_801EE200.colorStart[1].blue = 64;
    D_801EE200.colorStart[1].alpha = 255;
    D_801EE200.colorStart[2].red = 255;
    D_801EE200.colorStart[2].green = 128;
    D_801EE200.colorStart[2].blue = 0;
    D_801EE200.colorStart[2].alpha = 255;
    D_801EE200.colorStart[3].red = 255;
    D_801EE200.colorStart[3].green = 128;
    D_801EE200.colorStart[3].blue = 0;
    D_801EE200.colorStart[3].alpha = 255;
    D_801EE200.colorEnd[0].red = 64;
    D_801EE200.colorEnd[0].green = 0;
    D_801EE200.colorEnd[0].blue = 32;
    D_801EE200.colorEnd[0].alpha = 0;
    D_801EE200.colorEnd[1].red = 64;
    D_801EE200.colorEnd[1].green = 0;
    D_801EE200.colorEnd[1].blue = 32;
    D_801EE200.colorEnd[1].alpha = 0;
    D_801EE200.colorEnd[2].red = 128;
    D_801EE200.colorEnd[2].green = 0;
    D_801EE200.colorEnd[2].blue = 64;
    D_801EE200.colorEnd[2].alpha = 0;
    D_801EE200.colorEnd[3].red = 128;
    D_801EE200.colorEnd[3].green = 0;
    D_801EE200.colorEnd[3].blue = 64;
    D_801EE200.colorEnd[3].alpha = 0;
    D_801EE200.age = 0;
    D_801EE200.duration = 16;
    D_801EE200.velocity = 8.0f;
    D_801EE200.gravity = -1.0f;

    Effect_Add(globalCtx, &sp24, 0, 0, 1, &D_801EE200);
}

void func_800E8478(GlobalContext* globalCtx, Vec3f* pos) {
    static EffSparkParams D_801EE738;
    s32 sp24;

    D_801EE738.position.x = pos->x;
    D_801EE738.position.y = pos->y;
    D_801EE738.position.z = pos->z;
    D_801EE738.particleFactor1 = 5;
    D_801EE738.particleFactor2 = 5;
    D_801EE738.colorStart[0].red = 255;
    D_801EE738.colorStart[0].green = 255;
    D_801EE738.colorStart[0].blue = 255;
    D_801EE738.colorStart[0].alpha = 255;
    D_801EE738.colorStart[1].red = 100;
    D_801EE738.colorStart[1].green = 100;
    D_801EE738.colorStart[1].blue = 100;
    D_801EE738.colorStart[1].alpha = 100;
    D_801EE738.colorStart[2].red = 100;
    D_801EE738.colorStart[2].green = 100;
    D_801EE738.colorStart[2].blue = 100;
    D_801EE738.colorStart[2].alpha = 100;
    D_801EE738.colorStart[3].red = 100;
    D_801EE738.colorStart[3].green = 100;
    D_801EE738.colorStart[3].blue = 100;
    D_801EE738.colorStart[3].alpha = 100;
    D_801EE738.colorEnd[0].red = 50;
    D_801EE738.colorEnd[0].green = 50;
    D_801EE738.colorEnd[0].blue = 50;
    D_801EE738.colorEnd[0].alpha = 50;
    D_801EE738.colorEnd[1].red = 50;
    D_801EE738.colorEnd[1].green = 50;
    D_801EE738.colorEnd[1].blue = 50;
    D_801EE738.colorEnd[1].alpha = 50;
    D_801EE738.colorEnd[2].red = 50;
    D_801EE738.colorEnd[2].green = 50;
    D_801EE738.colorEnd[2].blue = 50;
    D_801EE738.colorEnd[2].alpha = 50;
    D_801EE738.colorEnd[3].red = 0;
    D_801EE738.colorEnd[3].green = 0;
    D_801EE738.colorEnd[3].blue = 0;
    D_801EE738.colorEnd[3].alpha = 0;
    D_801EE738.age = 0;
    D_801EE738.duration = 16;
    D_801EE738.velocity = 8.0f;
    D_801EE738.gravity = -1.0f;

    Effect_Add(globalCtx, &sp24, 0, 0, 1, &D_801EE738);
}

void func_800E85D4(GlobalContext* globalCtx, Vec3f* pos) {
    static EffShieldParticleInit init = {
        16,
        { 0.0f, 0.0f, 0.0f },
        { 0x00, 0xC8, 0xFF, 0xFF },
        { 0xFF, 0xFF, 0xFF, 0xFF },
        { 0xFF, 0xFF, 0x80, 0xFF },
        { 0xFF, 0xFF, 0x00, 0xFF },
        { 0xFF, 0x40, 0x00, 0xC8 },
        { 0xFF, 0x00, 0x00, 0xFF },
        2.1f,
        35.0f,
        30.0f,
        8,
        { 0, 0, 0, 0x00, 0x80, 0xFF, 0x00, 300 },
        1,
    };
    s32 sp24;

    init.position.x = pos->x;
    init.position.y = pos->y;
    init.position.z = pos->z;
    init.lightParams.posX = init.position.x;
    init.lightParams.posY = init.position.y;
    init.lightParams.posZ = init.position.z;

    Effect_Add(globalCtx, &sp24, 3, 0, 1, &init);
}

void func_800E8668(GlobalContext* globalCtx, Vec3f* v) {
    func_800E85D4(globalCtx, v);
    play_sound(0x1808);
}

void func_800E8690(GlobalContext *globalCtx, Vec3f *v, Vec3f *pos) {
    func_800E85D4(globalCtx, v);
    Audio_PlaySoundGeneral(pos, 0x1808);
}

void func_800E86C0(GlobalContext *globalCtx, Vec3f *v) {
    func_800E8668(globalCtx, v);
}

void func_800E86E0(GlobalContext* globalCtx, Vec3f* v, Vec3f* arg2) {
    static EffShieldParticleInit init = {
        16,
        { 0.0f, 0.0f, 0.0f },
        { 0x00, 0xC8, 0xFF, 0xFF },
        { 0xFF, 0xFF, 0xFF, 0xFF },
        { 0xFF, 0xFF, 0x80, 0xFF },
        { 0xFF, 0xFF, 0x00, 0xFF },
        { 0xFF, 0x40, 0x00, 0xC8 },
        { 0xFF, 0x00, 0x00, 0xFF },
        2.1f,
        35.0f,
        30.0f,
        8,
        { 0, 0, 0, 0x00, 0x80, 0xFF, 0x00, 300 },
        0,
    };
    s32 sp24;

    init.position.x = v->x;
    init.position.y = v->y;
    init.position.z = v->z;
    init.lightParams.posX = init.position.x;
    init.lightParams.posY = init.position.y;
    init.lightParams.posZ = init.position.z;

    Effect_Add(globalCtx, &sp24, 3, 0, 1, &init);
    Audio_PlaySoundGeneral(arg2, 0x1837);
}

#ifdef NON_MATCHING
s32 func_800E8784(f32 actor_ac_98_10, f32 actor_ac_98_12, f32 arg2, Vec3f* ac_actor_pos, Vec3f* at_actor_pos,
                  Vec3f* arg5, Vec3f* arg6, Vec3f* arg7) {
    // arg5 = SP + 0xA8, unk input
    // arg6 = SP + 0x90, unk output
    // arg7 = SP + 0x84, unk output2
    // sp -0x78

    Vec3f delta_a3_a4_sp6C;
    Vec3f delta_a3_a5_sp60;
    Vec3f delta_a4_a5_sp54;
    f32 sp50;
    f32 sp4C;
    f32 temp_f0;
    f32 temp_f0_3;
    f32 temp_f12;
    f32 temp_f14;
    f32 sp38;
    f32 temp_f16_2;
    f32 temp_f2;
    s32 phi_v0;
    s32 phi_v1;
    s32 phi_a0;
    s32 phi_a1;
    s32 phi_a2;

    sp4C = sp50 = 0.0f;
    phi_v0 = 0;

    delta_a3_a4_sp6C.x = at_actor_pos->x - ac_actor_pos->x;
    delta_a3_a4_sp6C.y = at_actor_pos->y - ac_actor_pos->y - arg2; // temp_f14
    delta_a3_a4_sp6C.z = at_actor_pos->z - ac_actor_pos->z;

    delta_a3_a5_sp60.x = arg5->x - ac_actor_pos->x;
    delta_a3_a5_sp60.y = arg5->y - ac_actor_pos->y - arg2; // temp_f6
    delta_a3_a5_sp60.z = arg5->z - ac_actor_pos->z;

    delta_a4_a5_sp54.x = delta_a3_a5_sp60.x - delta_a3_a4_sp6C.x; // temp_f16;
    delta_a4_a5_sp54.y = delta_a3_a5_sp60.y - delta_a3_a4_sp6C.y; // sp18; // temp_f8;
    delta_a4_a5_sp54.z = delta_a3_a5_sp60.z - delta_a3_a4_sp6C.z; // temp_f18;

    // ada12c:    bc1f    0xada138 ~>
    if (delta_a3_a4_sp6C.y > 0) {
        phi_v0 = 1;
    }
    // ada138:    beqzl   v0,0xada188 ~>
    if (phi_v0 && delta_a3_a4_sp6C.y < actor_ac_98_12) {
        if (sqrtf(SQ(delta_a3_a4_sp6C.x) + SQ(delta_a3_a4_sp6C.z)) < actor_ac_98_10) {
            return 3;
        }
    }

    phi_v1 = 0;
    if (delta_a3_a5_sp60.y > 0.0f) { // ada19c:    bc1f    0xada1a8 ~>
        phi_v1 = 1;
    }
    // ada1a8:    beqzl   v1,0xada1f4 ~>
    if ((phi_v1 && delta_a3_a5_sp60.y < actor_ac_98_12) && (sqrtf(SQ(delta_a3_a5_sp60.x) + SQ(delta_a3_a5_sp60.z)) < actor_ac_98_10)) {
        return 3;
    }

    // ada1f4
    sp38 = SQ(delta_a3_a4_sp6C.x) + SQ(delta_a3_a4_sp6C.z) - SQ(actor_ac_98_10); // temp_f12;
    temp_f2 = SQ(delta_a4_a5_sp54.x) + SQ(delta_a4_a5_sp54.z);
    if (!(fabsf(temp_f2) < 0.008f)) { // ada23c:    bc1t    0xada2f0 ~>
        temp_f14 = (delta_a4_a5_sp54.x + delta_a4_a5_sp54.x) * delta_a3_a4_sp6C.x +
                   (delta_a4_a5_sp54.z + delta_a4_a5_sp54.z) * delta_a3_a4_sp6C.z;
        temp_f0 = SQ(temp_f14);
        temp_f12 = (4.0f * temp_f2) * sp38;
        if (temp_f0 < temp_f12) { // ada280:    bc1f    0xada290 ~>
            return 0;
        }
        // ada290
        temp_f16_2 = temp_f0 - temp_f12;
        temp_f0 = sqrtf(temp_f16_2);
        if (temp_f16_2 > 0.0f) {
            phi_v0 = 1;
            phi_v1 = 1;
        } else {
            phi_v0 = 0;
            phi_v1 = 1;
        }

        sp50 = (temp_f0 - temp_f14) / (temp_f2 + temp_f2); // temp_f16_3;
        if (phi_v0) {
            sp4C = (-temp_f14 - temp_f0) / (temp_f2 + temp_f2);
        }
    } else { // 0xada2f0
        temp_f14 = ((delta_a4_a5_sp54.x + delta_a4_a5_sp54.x) * delta_a3_a4_sp6C.x) +
                   ((delta_a4_a5_sp54.z + delta_a4_a5_sp54.z) * delta_a3_a4_sp6C.z);
        if (!(fabsf(temp_f14) < 0.008f)) { // ada324
            sp50 = -sp38 / temp_f14;
            phi_v1 = 1;
            phi_v0 = 0;
        } // ada340:    b       0xada468
        else {
            if (sp38 <= 0.0f) { // ada358:    bc1f    0xada460
                phi_a0 = phi_v0;
                if (phi_v0) // ada360:    beqz    v0,0xada388 ~>
                {
                    phi_a0 = 0;
                    // ada37C
                    if (delta_a3_a4_sp6C.y < actor_ac_98_12) {
                        phi_a0 = 1;
                    }
                }
                phi_a1 = phi_a0;
                // ada38C
                phi_a0 = phi_v1;
                if (phi_v1) {
                    phi_a0 = 0;
                    if (delta_a3_a5_sp60.y < actor_ac_98_12) {
                        phi_a0 = 1;
                    }
                }
                if (phi_a1) {     // ada3b4
                    if (phi_a0) { // ada3bc
                        *arg6 = delta_a3_a4_sp6C;
                        *arg7 = delta_a3_a5_sp60;
                        return 2;
                    }
                }
                // ada408
                if (phi_a1) {
                    *arg6 = delta_a3_a4_sp6C;
                    return 1;
                }
                // ada434
                if (phi_a0) {
                    *arg6 = delta_a3_a5_sp60;
                    return 1;
                }
            }
            // ada460
            return 0;
        }
    }
    // ada468 800632C8
    if (!phi_v0) { // ada468:    bnezl   v0,0xada4a4 ~>
        if (sp50 < 0.0f || 1.0f < sp50) {
            return 0;
        }
    } else { // ada4a4
        phi_a1 = 0;
        if (sp50 < 0.0f) { // ada4ac
            phi_a1 = 1;
        }
        // ada4b8
        phi_a0 = phi_a1;
        if (!phi_a1) {
            phi_a1 = 0;
            if (1.0f < sp50) {
                phi_a1 = 1;
            }
        }
        // ada4dc
        phi_a2 = 0;
        if (sp4C < 0.0f) {
            phi_a2 = 1;
        }
        if (phi_a2 == 0) {
            phi_a2 = 0;
            if (1.0f < sp4C) {
                phi_a2 = 1;
            }
        }
        if (phi_a1) {
            if (phi_a2) {
                return 0;
            }
        }
        if (phi_a1) {
            phi_v1 = 0;
        }
        if (phi_a2) {
            phi_v0 = 0;
        }
    }
    if (phi_v1) {
        temp_f0_3 = sp50 * delta_a4_a5_sp54.y + delta_a3_a4_sp6C.y;
        if (temp_f0_3 < 0.0f || actor_ac_98_12 < temp_f0_3) {
            phi_v1 = 0;
        }
    }
    if (phi_v0) {
        temp_f0_3 = sp4C * delta_a4_a5_sp54.y + delta_a3_a4_sp6C.y;
        if (temp_f0_3 < 0.0f || actor_ac_98_12 < temp_f0_3) {
            phi_v0 = 0;
        }
    }
    if (!phi_v1 && !phi_v0) {
        return 0;
    }
    if (phi_v1) {
        if (phi_v0) {
            arg6->x = sp50 * delta_a4_a5_sp54.x + delta_a3_a4_sp6C.x + ac_actor_pos->x;
            arg6->y = sp50 * delta_a4_a5_sp54.y + delta_a3_a4_sp6C.y + ac_actor_pos->y;
            arg6->z = sp50 * delta_a4_a5_sp54.z + delta_a3_a4_sp6C.z + ac_actor_pos->z;
            arg7->x = sp4C * delta_a4_a5_sp54.x + delta_a3_a4_sp6C.x + ac_actor_pos->x;
            arg7->y = sp4C * delta_a4_a5_sp54.y + delta_a3_a4_sp6C.y + ac_actor_pos->y;
            arg7->z = sp4C * delta_a4_a5_sp54.z + delta_a3_a4_sp6C.z + ac_actor_pos->z;
            return 2;
        }
    }
    if (phi_v1) {
        arg6->x = sp50 * delta_a4_a5_sp54.x + delta_a3_a4_sp6C.x + ac_actor_pos->x;
        arg6->y = sp50 * delta_a4_a5_sp54.y + delta_a3_a4_sp6C.y + ac_actor_pos->y;
        arg6->z = sp50 * delta_a4_a5_sp54.z + delta_a3_a4_sp6C.z + ac_actor_pos->z;
        return 1;
    }
    if (phi_v0) { // ada700
        arg6->x = sp4C * delta_a4_a5_sp54.x + delta_a3_a4_sp6C.x + ac_actor_pos->x;
        arg6->y = sp4C * delta_a4_a5_sp54.y + delta_a3_a4_sp6C.y + ac_actor_pos->y;
        arg6->z = sp4C * delta_a4_a5_sp54.z + delta_a3_a4_sp6C.z + ac_actor_pos->z;
        return 1;
    }
    return 1;
}
#else
GLOBAL_ASM("asm/non_matchings/z_collision_check/func_800E8784.asm")
#endif
