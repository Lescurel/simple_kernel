#ifndef __PROCESS_H__
#define __PROCESS_H__

#include "inttypes.h"
#include "const.h"


typedef enum{
    ELECTED = 1,
    AVAILABLE = 0,
} p_state;

struct processus {
    int32_t pid;
    char name[P_NAME_MAX];
    p_state state;
    int32_t saved_register[N_REG_TO_SAVE];
    int32_t stack[STACK_SIZE];
};

struct processus table_proc[N_MAX_PROCESS];

void idle();

void proc1();

void init_table_proc();
#endif 
