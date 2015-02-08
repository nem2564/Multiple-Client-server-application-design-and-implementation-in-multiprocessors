#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>

//tcb structure as required
typedef struct tcb
{
    struct tcb *next;
    struct tcb *prev;
    ucontext_t context;
}TCB_t;

void init_TCB (TCB_t *tcb, void *function, void *stackP, int stack_size)
{
    memset(tcb, '\0', sizeof(TCB_t));
    getcontext(&tcb->context);
    tcb->context.uc_stack.ss_sp = stackP;
    tcb->context.uc_stack.ss_size = (size_t)stack_size;
    makecontext(&tcb->context, function, 0);
}
