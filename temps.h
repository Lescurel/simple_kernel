#ifndef __TEMPS_H__
#define __TEMPS_H__ 

#include "cpu.h"
#include "segment.h" 
#include "const.h"
#include "ecran.h"

void tic_PIT();

void init_traitant_IT_X(void (*traitant)(void), int x);

void set_freq();

void traitant_IT_32();

void unmask_irq(uint32_t x);

#endif
