#ifndef TICKS_H
#define TICKS_H

#include <stdint.h>

static uint32_t volatile ticksElapsed; //static makes it retain its value, volatile means it can be modified at any time

void resetTicks(void);

uint32_t getTicks(void);

void incrementTicks(void);

#endif //TICKS_H