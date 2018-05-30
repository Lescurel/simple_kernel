#ifndef __ECRAN_H__
#define __ECRAN_H__ 

#include <stdio.h>
#include "types.h"
#include "string.h"
#include "inttypes.h"
#include "const.h"
#include "cpu.h"

typedef enum{
    TOP_LEFT = 0,
    TOP_MIDDLE = 1,
    TOP_RIGHT = 2,
    BOTTOM_LEFT = 3,
    BOTTOM_MIDDLE = 4,
    BOTTOM_RIGHT = 5
} pos_id;
uint16_t *ptr_mem(uint32_t lig, uint32_t col);

void ecrit_car(uint32_t lig, uint32_t col, char c,
    uint32_t coul_texte, uint32_t coul_fond);

void efface_ecran(void);

void place_curseur(uint32_t lig, uint32_t col);

void traite_car(char c);

void defilement(void);

void console_putbytes(char *chaine, int32_t taille);

void print_at_pos(char *chaine, int32_t len, pos_id pos);

#endif
