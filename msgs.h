#include <stdio.h>
#include <stdlib.h>
#include "sem.h"

typedef struct message
{
	int m[10];
	struct message *next;
}Msg;

typedef struct msg_queue
{
	Msg *head;
	Msg *tail;
	Semaphore_t *prod;
	Semaphore_t *cons;
}Port;

Port *p[100];
Semaphore_t *mutex;

Port* initPort()
{
    	Port *por = (Port*)malloc(sizeof(Port));
	por->head = NULL;
	por->tail = NULL;
	por->prod = CreateSem(10);
	por->cons = CreateSem(0);
	return por;
}

void addMsg(Port *port, Msg *m)
{
	if(port->head == NULL || port->tail  == NULL)
	{
		port->head = m;
		port->head->next = NULL;
		port->tail = port->head;
	}
	else
	{
		port->tail->next = m;
		port->tail = port->tail->next;
		port->tail->next=NULL;
	}
}

void send(int port_num, Msg *m)
{
	Port *port = p[port_num];
	P(port->prod);
	P(mutex);

	addMsg(port, m);

	V(mutex);
	V(port->cons);
}

Msg* deleteMsg(Port *port)
{
	if(port->head == NULL || port->tail == NULL)
	{
		return NULL;
	}
	else if(port->head == port->tail)
	{
		Msg *m = port->head;
		port->head = NULL;
		port->tail = NULL;
		return m;
	}
	else
	{
		Msg *m = port->head;
		port->head = port->head->next;
		return m;
	}
}

Msg* receive(int port_num)
{
	Port *port = p[port_num];
	P(port->cons);
	P(mutex);

	Msg *m = deleteMsg(port);

	V(mutex);
	V(port->prod);

	return m;
}
