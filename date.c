#include "date.h"
/*
uint8_t lit_CMOS(uint8_t reg){
    outb(0x80 | reg, CMOS_COMMAND);
    uint8_t bcd = inb(CMOS_DATA);
    return  ((bcd >> 4) & 0x0F) * 10 + (bcd & 0x0F) ;
}
*/
void affiche_date(void){
    uint8_t cc, yy, MM, dd, hh, mm, ss;
    int len;
    char str[80];
    cc = lit_CMOS(CMOS_CENTURY);
    yy = lit_CMOS(CMOS_YEAR);
    MM = lit_CMOS(CMOS_MONTH);
    dd = lit_CMOS(CMOS_MONTHDAY);
    hh = lit_CMOS(CMOS_HOURS);
    mm = lit_CMOS(CMOS_MINUTES);
    ss = lit_CMOS(CMOS_SECONDS);
    len = sprintf(str, "DATE : %02d%02d-%02d-%02d|%02d:%02d:%02d", cc, yy, MM, dd, hh, mm, ss);
    print_at_pos(str, len, TOP_LEFT);
}
/*
void set_tic_RTC(){
    uint8_t v;
    outb(0x8A, CMOS_COMMAND);
    v = inb(CMOS_DATA);
    outb(0x8A, CMOS_COMMAND);
    outb(RTC_FREQ | v, CMOS_DATA);
}
*/
void set_sig_RTC(){
    uint8_t v;
    outb(0x8B, CMOS_COMMAND);
    v = inb(CMOS_DATA);
    outb(0x8B, CMOS_COMMAND);
    v |= (1 << 6);
    outb(v, CMOS_DATA);
}

