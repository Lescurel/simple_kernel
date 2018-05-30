#ifndef __DATE_H__
#define __DATE_H__ 

#include <inttypes.h>
#include "const.h"
#include "cpu.h"
#include "segment.h" 
#include "ecran.h"

uint8_t lit_CMOS(uint8_t reg);

void affiche_date(void);

void set_tic_RTC();

void set_sig_RTC();

void traitant_IT_40();
#endif
