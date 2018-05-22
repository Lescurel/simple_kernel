#include "ecran.h"
//
// uint16_t *ptr_mem(uint32_t lig, uint32_t col){
//   assert(col < 80 && lig < 25);
//   return (uint16_t *)(BEGIN_ADDR + 2*(lig*NB_COL + col));
// }

// void ecrit_car(uint32_t lig, uint32_t col, char c,
//   uint32_t coul_texte, uint32_t coul_fond){
//     *ptr_mem(lig, col) =  c | (coul_texte << 8) | (coul_fond << 12);
// }

void efface_ecran(void){
  for (size_t col = 0; col < NB_COL; col++) {
    for (size_t lig = 0; lig < NB_LINE; lig++) {
      ecrit_car(lig, col, ' ', WHITE, BLACK);
    }
  }
}

// void place_curseur(uint32_t lig, uint32_t col){
//   uint16_t pos = col + lig*NB_COL;
//   outb(LOW_PORT, CURSOR_COMMAND);
//   outb((uint8_t)pos, CURSOR_DATA);
//   outb(HIGH_PORT, CURSOR_COMMAND);
//   outb((uint8_t)(pos << 8), CURSOR_DATA);
// }
