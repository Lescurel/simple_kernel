#include "const.h"

.text
.globl lit_CMOS
.globl set_tic_RTC

/*
uint8_t lit_CMOS(uint8_t reg){
    outb(0x80 | reg, CMOS_COMMAND);
    uint8_t bcd = inb(CMOS_DATA);
    return  ((bcd >> 4) & 0x0F) * 10 + (bcd & 0x0F) ;
}
*/

lit_CMOS:
	enter $4, $0
    // outb(0x80 | reg, CMOS_COMMAND);
	movb $0x80, %al
	movb 8(%ebp), %cl
	orb %cl, %al
	movw $CMOS_COMMAND, %dx
	outb %al, %dx
    // uint8_t bcd = inb(CMOS_DATA);
	movw $CMOS_DATA, %dx
	inb %dx, %al
	movb %al, -4(%ebp)
	shrb $4, %al
	andb $0x0F, %al
	movb $10, %cl
	mulb %cl
	movb %al, %cl
	movb -4(%ebp), %al
	andb $0x0F, %al
    addb %cl, %al
	leave 
	ret


/*
void set_tic_RTC(){
    uint8_t v;
    outb(0x8A, CMOS_COMMAND);
    v = inb(CMOS_DATA);
    outb(0x8A, CMOS_COMMAND);
    outb(RTC_FREQ | (v & 0xF0), CMOS_DATA);
}
*/

set_tic_RTC:
	enter $4, $0
	movb $0x8A, %al 
	movw $CMOS_COMMAND, %dx
	outb %al, %dx
	movw $CMOS_DATA, %dx
	inb %dx, %al 
	movb %al, -4(%ebp)
	movb $0x8A, %al 
	movw $CMOS_COMMAND, %dx
	outb %al, %dx
	movw $CMOS_DATA, %dx
	movb -4(%ebp), %al
	andb $0xF0, %al
	orb $RTC_FREQ, %al
	outb %al, %dx
	leave
	ret
