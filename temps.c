#include "temps.h"

uint32_t clk_time;

void tic_PIT(){
    outb(0x20,0x20);
    clk_time++;
    char str[80];
    int32_t l,h,m,s;
    if(!(clk_time % 5)){
        h = ((clk_time/CLOCKFREQ)/3600)%60 ;
        m = ((clk_time/CLOCKFREQ)/60)%60;
        s = (clk_time/CLOCKFREQ) % 60;
        l = sprintf(str, "UP : %02d:%02d:%02d", h,m,s);
        print_at_pos(str, l, TOP_RIGHT);
    }
}

void init_traitant_IT_X(void (*traitant)(void), int x){
    uint32_t *addr = (uint32_t *)(IT_TABLE + 2*4*x);
    *addr = (KERNEL_CS << 16) | ((uint32_t)(traitant) & 0xFFFF);
    addr++;
    *addr = ((uint32_t)traitant & 0xFFFF0000) | 0x8E00;
}
/*
void set_freq(){
    outb(0x34, CLOCK_COMMAND);
    outb((QUARTZ/CLOCKFREQ) % 256, CLOCK_DATA);
    outb((uint8_t)((QUARTZ/CLOCKFREQ) >> 8), CLOCK_DATA);
}
*/
/*
void unmask_irq(uint32_t x){
    assert(x < 8);
    uint8_t ir;
    ir = inb(IRQ);
    ir &= ~(1 << x);
    outb(ir, IRQ);
}
*/

