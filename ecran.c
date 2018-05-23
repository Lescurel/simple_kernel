#include "ecran.h"

uint16_t poscrsr = 0;

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
//

void pos_curseur(){
    uint16_t lig = poscrsr / NB_COL;
    uint16_t col = poscrsr % NB_COL;
    place_curseur(lig, col); 
}

void traite_car(char c){
    uint16_t lig = poscrsr / NB_COL;
    uint16_t col = poscrsr % NB_COL;
    if(c == 8){
        if(col != 0){
            poscrsr--;
        }
    } else if(c == 9){
        poscrsr += (8 - col%8);
        if(lig < poscrsr/NB_COL){
            poscrsr = lig*NB_COL + NB_COL-1;
        }
    } else if(c == 10){
        poscrsr += (NB_COL - col);
    } else if(c == 12){
        efface_ecran();
        poscrsr = 0;
    } else if(c == 13){
        poscrsr -= col;
    }else if(c < 127 && c > 31){
       ecrit_car(lig, col, c, WHITE, BLACK);
       poscrsr++;
    }
    pos_curseur();
}


void console_putbytes(char *chaine, int32_t taille){
    for(size_t i =0; i < taille; i++){
        traite_car(chaine[i]);
    }
}


void print_right_top(char *chaine){
    uint16_t tmp;
    char * s_time = "";
    size_t l;
    l = sprintf(s_time, chaine);
    tmp = poscrsr;
    poscrsr = NB_COL - l;
    console_putbytes(s_time, l);
    poscrsr = tmp;
}

