#include <stdio.h>
#include <stdlib.h>
#include "tcb.h"

//queue structure that will be used to store the threads
typedef struct queue
{
	TCB_t *head;
	TCB_t *tail;
} Q;

//initialise queue by allocating memory
Q* initQ(Q *q)
{
       q = (Q*)malloc(sizeof(Q));
	q->head = NULL;
	q->tail = NULL;
	return q;
}

//function to add elements in queue
void addQ(Q *q, TCB_t *i)
{
	if(q->head == NULL || q->tail  == NULL)
	{
		q->head = i;
		q->head->next = q->head;
		q->head->prev = q->head;
		q->tail = q->head;
	}
	else
	{
		i->prev = q->tail;
		i->next = q->head;
		q->head->prev = i;
		q->tail->next = i;
		q->tail = i;
	}
}

//delete an item from head of queue
TCB_t* deleteQ(Q *q)
{
	if(q->head == NULL || q->tail == NULL)
	{
		return NULL;
	}
	else if(q->head == q->tail)
	{
		TCB_t *i = q->head;
		q->head = NULL;
		q->tail = NULL;
	return i;
	}
	else
	{
		TCB_t *i = q->head;
		q->head = q->head->next;
		q->head->prev = q->tail;
		q->tail->next = q->head;
		return i;
	}
}

//rotate queue
void rotateQ(Q *q)
{
	if(q->head!=NULL && q->tail!=NULL)
	{
		q->tail=q->head;
		q->head = q->head->next;
	}
}

