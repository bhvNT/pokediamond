#ifndef POKEDIAMOND_FIELD_MOVE_ENVIRONMENT_H
#define POKEDIAMOND_FIELD_MOVE_ENVIRONMENT_H

#include "heap.h"
#include "pokemon.h"
#include "save.h"

typedef struct FieldMoveData {
    u32 partySlot;
} FieldMoveData;

typedef struct FieldMoveEnvironment {
    Pokemon *mon;
    FieldMoveData *moveData;
} FieldMoveEnvironment;

FieldMoveEnvironment *FieldMove_CreateEnvironment(HeapID heapId, u8 slotNo, SaveData *saveData);

#endif // POKEDIAMOND_FIELD_MOVE_ENVIRONMENT_H
