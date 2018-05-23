#include <stdio.h>
#include "types.h"
#include "inttypes.h"
#include "const.h"
#include "cpu.h"

uint16_t *ptr_mem(uint32_t lig, uint32_t col);

void ecrit_car(uint32_t lig, uint32_t col, char c,
    uint32_t coul_texte, uint32_t coul_fond);

void efface_ecran(void);

void place_curseur(uint32_t lig, uint32_t col);

void traite_car(char c);

void defilement(void);

void console_putbytes(char *chaine, int32_t taille);

void print_right_top(char *chaine);
