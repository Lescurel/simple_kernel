#include <cpu.h>
#include <inttypes.h>
#include "ecran.h"
#include "temps.h"
#include "date.h"
#include "keyboard.h"
#include "malloc.c.h"

// on peut s'entrainer a utiliser GDB avec ce code de base
// par exemple afficher les valeurs de x, n et res avec la commande display

// une fonction bien connue
uint32_t fact(uint32_t n)
{
    uint32_t res;
    if (n <= 1) {
        res = 1;
    } else {
        res = fact(n - 1) * n;
    }
    return res;
}

void kernel_start(void)
{
    // uint16_t *ptr = ptr_mem(0,0);
    // (void)ptr;
    // efface_ecran();
    // place_curseur(2,2);
    // console_putbytes("Hello World!\n", 13);
    char * c = malloc(80);
    (void)c; 
    efface_ecran();
    init_traitant_IT_X(traitant_IT_32, 32);
    set_freq();
    unmask_irq(0);
    
    init_traitant_IT_X(traitant_IT_40, 40);
    set_tic_RTC();
    set_sig_RTC();
    unmask_irq(8);
    
    init_traitant_IT_X(traitant_IT_33, 33);
    unmask_irq(1);
    
    sti();
    // quand on saura gerer l'ecran, on pourra afficher x
    // (void)x;
    // on ne doit jamais sortir de kernel_start
    while (1) {
        // cette fonction arrete le processeur
        hlt();
    }
}
