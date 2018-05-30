#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__


#include "const.h"
#include "inttypes.h"
#include "cpu.h"
#include "ecran.h"


void print_char();

char code_to_usc(uint8_t code);

void traitant_IT_33();
#endif

