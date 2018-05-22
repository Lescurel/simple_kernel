#include "const.h"

.text
.globl ptr_mem
.globl ecrit_car
.globl place_curseur

ptr_mem:
  enter $0, $0
  movl 8(%ebp), %eax
  movl $NB_COL, %ecx
  mull %ecx
  addl 12(%ebp), %eax
  movl $2, %ecx
  mull %ecx
  addl $BEGIN_ADDR, %eax
  leave
  ret
/*void ecrit_car(uint32_t lig, uint32_t col, char c,
   uint32_t coul_texte, uint32_t coul_fond){
     *ptr_mem(lig, col) =  c | (coul_texte << 8) | (coul_fond << 12);
}*/
ecrit_car:
  enter $0, $0
  pushl 12(%ebp)
  pushl 8(%ebp)
  call ptr_mem
  addl $8, %esp
  movl 16(%ebp), %ecx
  movl 20(%ebp), %edx
  shl $8, %edx
  orl %edx, %ecx
  movl 24(%ebp), %edx
  shl $12, %edx
  orl %edx, %ecx
  movl %ecx, (%eax)
  leave
  ret

place_curseur:
  enter $0, $0
  //   outb(LOW_PORT, CURSOR_COMMAND)
  movb $CURSOR_COMMAND, %dx
  movb $LOW_PORT, %al
  outb %al, %dx
  movl 8(%ebp), %eax
  movl $NB_COL, %ecx
  mull %ecx
  addl 12(%ebp), %eax
  movb $CURSOR_DATA, %dx
  outb %al, %dx
  //   outb(HIGH_PORT, CURSOR_COMMAND);
  movb $CURSOR_COMMAND, %dx
  movb $HIGH_PORT, %al
  outb %al, %dx
  // outb((uint8_t)(pos << 8), CURSOR_DATA);
  movb $CURSOR_DATA, %dx
  shl $8, %eax
  outb %al, %dx
  leave
  ret
