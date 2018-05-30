#include "keyboard.h"

static struct keycode_char_pair {
    uint8_t keycode;
    char car;
} keycode_char_map[] = {
    {2, '1'},
    {3, '2'},
    {4, '3'},
    {5, '4'},
    {6, '5'},
    {7, '6'},
    {8, '7'},
    {9, '8'},
    {10, '9'},
    {11, '0'},
    {12, '-'},
    {13, '='},
    {14, '\b'},
    {15, '\t'},
    {16, 'Q'},
    {17, 'W'},
    {18, 'E'},
    {19, 'R'},
    {20, 'T'},
    {21, 'Y'},
    {22, 'U'},
    {23, 'I'},
    {24, 'O'},
    {25, 'P'},
    {26, '['},
    {27, ']'},
    {28, '\n'},
    {30, 'A'},
    {31, 'S'},
    {32, 'D'},
    {33, 'F'},
    {34, 'G'},
    {35, 'H'},
    {36, 'J'},
    {37, 'K'},
    {38, 'L'},
    {39, ';'},
    {40, '\''},
    {41, '`'},
    {43, '\\'},
    {44, 'Z'},
    {45, 'X'},
    {46, 'C'},
    {47, 'V'},
    {48, 'B'},
    {49, 'N'},
    {50, 'M'},
    {51, ','},
    {52, '.'},
    {53, '/'},
};

char code_to_usc(uint8_t code){
    int i;
    for(i = 0; i < 52; i++){
        if(keycode_char_map[i].keycode == code){
            return keycode_char_map[i].car;
        }
    }
    return 0;
}

void print_char(){
    uint8_t code = inb(0x60);
    char car = code_to_usc(code);
    char c[1];
    c[0] = car;
    if(car != 0){
       console_putbytes(c, 1); 
    }
}
