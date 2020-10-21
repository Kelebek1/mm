#include <ultra64.h>
#include <global.h>

DamageTable* DamageTable_Get(s32 index) {
    if ((index < 0) || (index > 22)) return 0;
    return &(gDamageTables[index]);
}

// Zeroes out a DamageTable
void func_800E03CC(u8* index) {
    s32 i;
    u8* v1;

    for (i = 0, v1 = index; i < 32; i++) {
        *v1++ = 0;
    }
}
