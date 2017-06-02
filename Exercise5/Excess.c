#include "Excess.h"
#include <malloc.h>

Excess* new_Excess() {

    Excess* excess = malloc(sizeof(Excess));

    excess->income = 0;

    return excess;
}

void freeExcess(Excess* excess) {
    free(excess);
}
