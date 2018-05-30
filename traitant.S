#include "const.h"

# cette directive sert a rendre l’etiquette publique
.globl traitant_IT_32
.globl traitant_IT_40
.globl traitant_IT_33

# debut du traitant
traitant_IT_32:
# sauvegarde des registres importants
	pushl %eax
	pushl %edx
	pushl %ecx
# appel a la fonction C realisant le traitant
	call tic_PIT
# restauration des registres importants
	popl %ecx
	popl %edx
	popl %eax
# fin du traitant
	iret

traitant_IT_40:
# sauvegarde des registres importants
	pushl %eax
	pushl %edx
	pushl %ecx
# acquitter iqr 40
	movb $0x20, %al
	movw $IRQ_COMMAND, %dx
	outb %al, %dx
	movw $IRQ_SLAVE_COMMAND, %dx
	outb %al, %dx
# lecture RTC
    movb $0x8c, %al	
	movw $CMOS_COMMAND, %dx
	outb %al, %dx
	movw $CMOS_DATA, %dx
	inb %dx, %al
# appel a la fonction C realisant le traitant
	call affiche_date
# restauration des registres importants
	popl %ecx
	popl %edx
	popl %eax
# fin du traitant
	iret

traitant_IT_33:
# sauvegarde des registres importants
	pushl %eax
	pushl %edx
	pushl %ecx
# acquitter iqr 1
	movb $0x20, %al
	movw $IRQ_COMMAND, %dx
	outb %al, %dx
# lecture 0x60
    movw $0x60, %dx	
	inb %dx, %al
# appel a la fonction C realisant le traitant
	call print_char
# restauration des registres importants
	popl %ecx
	popl %edx
	popl %eax
# fin du traitant
	iret


