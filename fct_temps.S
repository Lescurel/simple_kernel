#include "const.h"

/*
void set_freq(){
    outb(0x34, CLOCK_COMMAND);
    outb((QUARTZ/CLOCKFREQ) % 256, CLOCK_DATA);
    outb((uint8_t)((QUARTZ/CLOCKFREQ) >> 8), CLOCK_DATA);
}
*/

.text
.globl set_freq
.globl unmask_irq 

set_freq:
	enter $0, $0
	movw $CLOCK_COMMAND, %dx
	movb $0x34, %al
	outb %al, %dx
	movl $QUARTZ, %eax
	movl $0, %edx
	movl $CLOCKFREQ, %ecx
	divl %ecx
	movw $CLOCK_DATA, %dx
	outb %al, %dx
	movb %ah, %al
	outb %al, %dx
	leave 
	ret

/*
void unmask_irq(uint32_t x){
    assert(x < 16);
	uint8_t ir, ir_slave;
    ir = inb(IRQ);
	if(8 > x){
		ir &= ~(1 << x);
		outb(ir, IRQ);
	}else {
		ir_slave = inb(IRQ_SLAVE);
		ir &= ~(1 << 2);
		ir_slave &= ~(1 << x-8);
		outb(ir, IRQ);
		outb(ir_slave, IRQ_SLAVE);
	}
}
*/

unmask_irq:
	enter $0, $0
	cmpl $8, 8(%ebp)
	jae else
	movw $IRQ, %dx
	inb %dx, %al
    movl 8(%ebp), %ecx
	movb $1, %dl
	shlb %cl, %dl
	notb %dl
	andb %dl, %al
	movw $IRQ, %dx
    outb %al, %dx
	jmp fin
else:
	movw $IRQ, %dx
	inb %dx, %al
	movb $1, %dl
	shlb $2, %dl
	notb %dl
	andb %dl, %al
	movw $IRQ, %dx
    outb %al, %dx
	
	movw $IRQ_SLAVE, %dx
	inb %dx, %al
	movb $1, %dl
	movl 8(%ebp), %ecx
	subb $8, %cl 
	shlb %cl, %dl
	notb %dl
	andb %dl, %al
	movw $IRQ_SLAVE, %dx
    outb %al, %dx

fin:
	leave 
	ret
