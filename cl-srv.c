#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "msgs.h"

#define PORT_NUMBER 10
#define SERVER_OPR 0
#define SERVER_ADD_1 1
#define SERVER_DEL_1 2
#define SERVER_MOD_OLD_1 3
#define SERVER_MOD_NEW_1 4
#define SERVER_ADD_2 5
#define SERVER_DEL_2 6
#define SERVER_MOD_OLD_2 7
#define SERVER_MOD_NEW_2 8
#define CLIENT3_PORT 9

//Names:
//Pankil Bhatt(ASU ID: 1206302275)
//Nirmal Patel(ASU ID: 1206527422)

void client1(){
	char string[10][20] = {"c1_1_longer","c1_2_longer","c1_3_longer", "c1_4_longer", "c1_5_longer", "c1_6_longer","c1_7_longer", "c1_8_longer", "c1_9_longer", "c1_10_longer"};
	char new_string[10][20] = {"c1_1_new_longer","c1_2_new_longer","c1_3_new_longer", "c1_4_new_longer", "c1_5_new_longer", "c1_6_new_longer","c1_7_new_longer", "c1_8_new_longer", "c1_9_new_longer", "c1_10_new_longer"};

	int i=0;
	while(1)
	{

	int operation = rand()%3;
	switch (operation)
	{
		case 0:
			{
			Msg *mes = (Msg*)malloc(sizeof(Msg));
			mes->m[0]=0;
			mes->m[1]=1;
			int len = strlen(string[i]);
			mes->m[2]=len;
			mes->m[3]=0;
			send(SERVER_OPR,mes);
			int k=0;
			while(k!=len)
			{
				mes = (Msg*)malloc(sizeof(Msg));
				int j;
				for(j=0;string[i][k]!='\0' && j<9;j++,k++)
				{
					mes->m[j]=string[i][k];
				}
				mes->m[j]='\0';				
				send(SERVER_ADD_1,mes);
			}
			printf("client1 sent request to Add string %s\n\n", string[i]);						
			i=(i+1)%10;
			break;
			}
		case 1:
			if(i>0)
			{
				Msg *mes = (Msg*)malloc(sizeof(Msg));
				mes->m[0]=1;
				mes->m[1]=1;
				int pos = rand()%i;
				int len = strlen(string[pos]);
				mes->m[2]=len;
				mes->m[3]=0;
				send(SERVER_OPR,mes);
				int k=0;
				while(k!=len)
				{
					mes = (Msg*)malloc(sizeof(Msg));
					int j;
					for(j=0;string[pos][k]!='\0' && j<9;j++,k++)
					{
						mes->m[j]=string[pos][k];
					}
					mes->m[j]='\0';				
					send(SERVER_DEL_1,mes);
				}
				printf("client1 sent request to Delete string %s\n\n", string[pos]);
			}
			break;
		case 2:
			if(i>0)
			{
				Msg *mes = (Msg*)malloc(sizeof(Msg));
				mes->m[0]=2;
				mes->m[1]=1;
				int pos = rand()%i;
				int len1 = strlen(string[pos]);
				mes->m[2]=len1;
				int len2 = strlen(new_string[pos]);
				mes->m[3]=len2;
				send(SERVER_OPR,mes);
				int k=0;
				while(k!=len1)
				{
					mes = (Msg*)malloc(sizeof(Msg));
					int j;
					for(j=0;string[pos][k]!='\0' && j<9;j++,k++)
					{
						mes->m[j]=string[pos][k];
					}
					mes->m[j]='\0';				
					send(SERVER_MOD_OLD_1,mes);
				}
				k=0;
				while(k!=len2)
				{
					mes = (Msg*)malloc(sizeof(Msg));
					int j;
					for(j=0;new_string[pos][k]!='\0' && j<9;j++,k++)
					{
						mes->m[j]=new_string[pos][k];
					}
					mes->m[j]='\0';				
					send(SERVER_MOD_NEW_1,mes);
				}
				printf("client1 sent request to modify string %s\n\n", string[pos]);
			}
			break;
			
	}
	sleep(1);
	}

}

void client2(){
	char string[10][20] = {"c2_1_longer","c2_2_longer","c2_3_longer", "c2_4_longer", "c2_5_longer", "c2_6_longer","c2_7_longer", "c2_8_longer", "c2_9_longer", "c2_10_longer"};
	char new_string[10][20] = {"c2_1_new_longer","c2_2_new_longer","c2_3_new_longer", "c2_4_new_longer", "c2_5_new_longer", "c2_6_new_longer","c2_7_new_longer", "c2_8_new_longer", "c2_9_new_longer", "c2_10_new_longer"};

	int i=0;
	while(i<10){

	int operation = rand()%3;
	switch (operation)
	{
		case 0:{
			Msg *mes = (Msg*)malloc(sizeof(Msg));
			mes->m[0]=0;
			mes->m[1]=2;
			int len = strlen(string[i]);
			mes->m[2]=len;
			mes->m[3]=0;
			send(SERVER_OPR,mes);
			int k=0;
			while(k!=len)
			{
				mes = (Msg*)malloc(sizeof(Msg));
				int j;
				for(j=0;string[i][k]!='\0' && j<9;j++,k++)
				{
					mes->m[j]=string[i][k];
				}
				mes->m[j]='\0';				
				send(SERVER_ADD_2,mes);
			}
			printf("client2 sent request to Add string %s\n\n", string[i]);						
			i=(i+1)%10;
			break;
			}
		case 1:
			if(i>0)
			{
				Msg *mes = (Msg*)malloc(sizeof(Msg));
				mes->m[0]=1;
				mes->m[1]=2;
				int pos = rand()%i;
				int len = strlen(string[pos]);
				mes->m[2]=len;
				mes->m[3]=0;
				send(SERVER_OPR,mes);
				int k=0;
				while(k!=len)
				{
					mes = (Msg*)malloc(sizeof(Msg));
					int j;
					for(j=0;string[pos][k]!='\0' && j<9;j++,k++)
					{
						mes->m[j]=string[pos][k];
					}
					mes->m[j]='\0';				
					send(SERVER_DEL_2,mes);
				}
				printf("client2 sent request to Delete string %s\n\n", string[pos]);
			}
			break;
		case 2:
			if(i>0)
			{
				Msg *mes = (Msg*)malloc(sizeof(Msg));
				mes->m[0]=2;
				mes->m[1]=2;
				int pos = rand()%i;
				int len1 = strlen(string[pos]);
				mes->m[2]=len1;
				int len2 = strlen(new_string[pos]);
				mes->m[3]=len2;
				send(SERVER_OPR,mes);
				int k=0;
				while(k!=len1)
				{
					mes = (Msg*)malloc(sizeof(Msg));
					int j;
					for(j=0;string[pos][k]!='\0' && j<9;j++,k++)
					{
						mes->m[j]=string[pos][k];
					}
					mes->m[j]='\0';				
					send(SERVER_MOD_OLD_2,mes);
				}
				k=0;
				while(k!=len2)
				{
					mes = (Msg*)malloc(sizeof(Msg));
					int j;
					for(j=0;new_string[pos][k]!='\0' && j<9;j++,k++)
					{
						mes->m[j]=new_string[pos][k];
					}
					mes->m[j]='\0';				
					send(SERVER_MOD_NEW_2,mes);
				}
				printf("client2 sent request to modify string %s\n\n", string[pos]);
			}
			break;
			
	}
	sleep(1);
	}

}

void client3()
{
	int count = 0;
	while(1)
	{
		count=rand()%30;
		if(count%3 == 0)
		{			

			Msg *mes = (Msg*)malloc(sizeof(Msg));
			mes->m[0]=3;
			mes->m[1]=3;
			mes->m[2]=0;
			mes->m[3]=0;
			send(SERVER_OPR,mes);
			printf("client 3 sent request to print\n");
			int i;
			for(i=0;i<10;i++)
			{
				mes = (Msg*)malloc(sizeof(Msg));
				mes = receive(CLIENT3_PORT);
				int len = mes->m[0];
				char entry[80];
				int k=0;
				while(k!=len)
				{
					mes = (Msg*)malloc(sizeof(Msg));
					mes = receive(CLIENT3_PORT);
					int j;
					for(j=0;mes->m[j]!=0 && j<9 && k<len;j++,k++)
					{
						entry[k]=mes->m[j];
					}			
				}
				entry[k]='\0';
				printf("print string %s \n",entry);
			}
			printf("\n\n");
			yield();
		}
		else
		{
			printf("client 3 skipping printing\n\n");
			yield();
		}
	}
}

void server()
{
	char table[10][80];
	int index=0;
	int i;
	for(i=0;i<10;i++)
	{
		strcpy(table[i],"empty");
	}
	
	while(1)
	{
		Msg* mes = (Msg*)malloc(sizeof(Msg));
		mes = receive(SERVER_OPR);
		int operation = mes->m[0];
		int client = mes->m[1];
		int len1 = mes->m[2];
		int len2 = mes->m[3];
		switch (operation)
		{
			case 0:
				{
				int k=0;
				while(k!=len1)
				{
					mes = (Msg*)malloc(sizeof(Msg));
					if(client==1)
					{
						mes = receive(SERVER_ADD_1);
					}
					else if(client==2)
					{
						mes = receive(SERVER_ADD_2);
					}
					int j;
					for(j=0;mes->m[j]!=0 && j<9 && k<len1;j++,k++)
					{
						table[index][k]=mes->m[j];
					}			
				}
				table[index][k]='\0';			
				printf("Added string %s at Server\n\n", table[index]);
				index=(index+1)%10;
				break;
				}
			case 1:
				{
				int k=0;
				char entry[80];
				while(k!=len1)
				{
					mes = (Msg*)malloc(sizeof(Msg));
					if(client==1)
					{
						mes = receive(SERVER_DEL_1);
					}
					else if(client==2)
					{
						mes = receive(SERVER_DEL_2);
					}
					int j;
					for(j=0;mes->m[j]!=0 && j<9 && k<len1;j++,k++)
					{
						entry[k]=mes->m[j];
					}			
				}
				entry[k]='\0';
				int j;
				for(j=0;j<10;j++)
				{
					if(strcmp(entry,table[j])==0)
					{
						strcpy(table[j], "empty");
						printf("Deleted string %s at Server\n\n", entry);
					}
				}
				break;
				}
			case 2:
				{
				int k=0;
				char entry[80];
				while(k!=len1)
				{
					mes = (Msg*)malloc(sizeof(Msg));
					if(client==1)
					{
						mes = receive(SERVER_MOD_OLD_1);
					}
					else if(client==2)
					{
						mes = receive(SERVER_MOD_OLD_2);
					}
					int j;
					for(j=0;mes->m[j]!=0 && j<9 && k<len1;j++,k++)
					{
						entry[k]=mes->m[j];
					}			
				}
				entry[k]='\0';
				k=0;
				char new_entry[80];
				while(k!=len2)
				{
					mes = (Msg*)malloc(sizeof(Msg));
					if(client==1)
					{
						mes = receive(SERVER_MOD_NEW_1);
					}
					else if(client==2)
					{
						mes = receive(SERVER_MOD_NEW_2);
					}
					int j;
					for(j=0;mes->m[j]!=0 && j<9 && k<len2;j++,k++)
					{
						new_entry[k]=mes->m[j];
					}			
				}
				new_entry[k]='\0';				
				int j;
				for(j=0;j<10;j++)
				{
					if(strcmp(entry,table[j])==0)
					{
						strcpy(table[j], new_entry);
						printf("modified string %s to %s at Server\n\n", entry, table[j]);
					}
				}
				break;
				}
			case 3:
				{
				printf("sending data to client 3 to print\n");
				
				for(i=0;i<10;i++)
				{
					mes = (Msg*)malloc(sizeof(Msg));
					int len = strlen(table[i]);
					mes->m[0] = len;
					send(CLIENT3_PORT, mes);
					int k=0;
					while(k!=len)
					{
						mes = (Msg*)malloc(sizeof(Msg));
						int j;
						for(j=0;table[i][k]!='\0' && j<9 && k<len;j++,k++)
						{
							mes->m[j]=table[i][k];
						}
						mes->m[j]='\0';				
						send(CLIENT3_PORT,mes);
					}	
				}
				break;	
				}
		}

		sleep(1);
	}
}

void main(){
	
	int port_count;

	for(port_count=0; port_count<PORT_NUMBER; port_count++){
		p[port_count] = initPort();
	}
	printf("----------Documentation-----------\n");
	sleep(1);
	printf("We have used the strategy 1 of project 3 for message passing. Msgs.h is the msgs_1.h file of project 3\n\n");
	sleep(1);
	printf("A 2D char array is stored at server. Server uses several ports to offer add,delete,modify and print service to clients.\n\n");
	sleep(1);
	printf("Client 1 and 2 consists of array of strings that are to be sent to server. There is a separate array to send strings for add operation and separate array for strings to be sent for modify(the strings from first array will be modified to strings from second array.) \n\n");
	sleep(2);
	printf("The client uses a random function to select the type of operation it wants to perform and sends it to server using one port. It then sends the strings to add,delete or modify on other ports according to the type of operation. Server determines the type of operation by listening at one port and then listens to the other port according to type of operation \n\n");
	sleep(3);
	printf("Client uses a random function to determine the string to modify or delete from the strings that were added.\n\n");
	sleep(1);
	printf("Client3 uses a random function to determine whether to send a request to print. It sends a request to print if the random number generated is a multiple of 3. After sending request to print it listens on its dedicated to port to receive all the strings from server. Server on receiving print request sends all the strings in table to client 3 port\n\n");
	sleep(3);
	printf("To implement stage 2-handle strings longer than message size 10, the strings are sent as multiple nessage packets. To avoid race conditions I have used logic that once the connection is set up between the server and a client, server uses a unique port for subsequent communication with that client. The ports are hard coded for this program.\n\n");
	sleep(3);
	printf("The client also sends the length of the strings it will be sending to add, delete or modify when it sends the type of operation to be performed to the server. Similarly server sends length of string before sending actual string, when it sends strings to print to client 3.\n\n");
	sleep(3);
	printf("---------------------starting server and client(takes couple of seconds)---------------------------\n\n");
	RunQ = initQ(RunQ);
	mutex = CreateSem(1);
	start_thread(&server);
	start_thread(&client1);
	start_thread(&client2);
	start_thread(&client3);

	run();
}
