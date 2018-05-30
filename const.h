#ifndef __CONST_H__
#define __CONST_H__


#define BEGIN_ADDR 0xB8000
#define NB_COL 80
#define NB_LINE 25

#define LOW_PORT 0x0F
#define HIGH_PORT 0x0E

#define CURSOR_COMMAND 0x3D4
#define CURSOR_DATA 0x3D5

#define WHITE 15
#define BLACK 0

#define IT_TABLE 0x1000

#define QUARTZ 0x1234DD
#define CLOCKFREQ 50
#define CLOCK_COMMAND 0x43
#define CLOCK_DATA 0x40

#define IRQ_COMMAND 0x20
#define IRQ 0x21
#define IRQ_SLAVE_COMMAND 0xA0
#define IRQ_SLAVE 0xA1

#define RTC_FREQ 15

#define CMOS_COMMAND 0x70
#define CMOS_DATA 0x71

#define CMOS_SECONDS 0
#define CMOS_MINUTES 2
#define CMOS_HOURS 4
#define CMOS_WEEKDAY 6
#define CMOS_MONTHDAY 7
#define CMOS_MONTH 8
#define CMOS_YEAR 9
#define CMOS_CENTURY 0x32

#define P_NAME_MAX 8
#define N_REG_TO_SAVE 5
#define STACK_SIZE 512
#define N_MAX_PROCESS 2
#endif
