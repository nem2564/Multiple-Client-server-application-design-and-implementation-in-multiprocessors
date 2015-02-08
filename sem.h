#ifndef SEM_H_INCLUDED
#define SEM_H_INCLUDED
#include "threads.h"
#endif // Q_H_INCLUDED

typedef struct semaphore{
    int count;
    Q *queue;
} Semaphore_t;

Semaphore_t *CreateSem(int InputValue){

    Semaphore_t *sem = (Semaphore_t*)malloc(sizeof(Semaphore_t));
    sem->count = InputValue;
    sem->queue = initQ(sem->queue);
    return sem;
}
void P(Semaphore_t *sem){
    sem->count = sem->count - 1;
    if(sem->count < 0)
    {
        TCB_t* temp = deleteQ(RunQ);
        addQ(sem->queue, temp);
        swapcontext(&(temp->context), &(RunQ->head->context));
    }    
}

void V(Semaphore_t * sem){

    sem->count++;
    if(sem->count <= 0){
         TCB_t* temp = deleteQ(sem->queue);
         addQ(RunQ, temp);
    }
	yield();
}
