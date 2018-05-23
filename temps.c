#include "temps.h"

char * temps;

void tic_PIT(){
    outb(0x20,0x20);
    print_right_top(temps);
}
