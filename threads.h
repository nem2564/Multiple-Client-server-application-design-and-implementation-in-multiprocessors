#include "q.h"

//global variable for queue
Q *RunQ = NULL;

void start_thread(void (*function)())
{
     void *stack = malloc(8192); //allocate stack
     TCB_t *tcb = (TCB_t*)malloc(sizeof(TCB_t)); //allocate memory to tcb
     init_TCB(tcb, function, stack, 8192); //initialise tcb
     addQ(RunQ, tcb); //add thread to queue
}

void run()
{
    ucontext_t parent;
    getcontext(&parent);
    swapcontext(&parent, &(RunQ->head->context)); //switch context to thread at head of queue
}

void yield()
{
   rotateQ(RunQ);			 //rotate queue
   swapcontext(&(RunQ->tail->context), &(RunQ->head->context));//swap context from the thread to next thread in queue
}
