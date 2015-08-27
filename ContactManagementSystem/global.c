
#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "contacts.h"

void initGlobals()
{
		
		secretkey[0] = 29; secretkey[1] = 8; secretkey[2] = 27; secretkey[3] = 28;
		secretkey[4] = 20; secretkey[5] = 7; secretkey[6] = 30; secretkey[7] = 18;

	// main doubly linked list initialization
		listHead = (struct contact *)malloc(sizeof(struct contact));
		listTail = (struct contact *)malloc(sizeof(struct contact));

		listHead->idNum = 0; // head id will keep autoincrement value
		listTail->idNum = 0;	// tail will keep the size of list

		listHead->next = listTail;	// empty list, head's next node is tail
		listHead->prev = NULL;		// head doesn't have any previous nodes

		listTail->prev = listHead;	// empty list, tail's previous node is head
		listTail->next = NULL;		// tail doesn't have any next nodes

	// temporary doubly linked list initialization
		tmpListHead = (struct contact *)malloc(sizeof(struct contact));
		tmpListTail = (struct contact *)malloc(sizeof(struct contact));

		tmpListHead->idNum = 0; // head id will keep autoincrement value
		tmpListTail->idNum = 0;	// tail will keep the size of list

		tmpListHead->next = tmpListTail;	// empty list, head's next node is tail
		tmpListHead->prev = NULL;		// head doesn't have any previous nodes

		tmpListTail->prev = tmpListHead;	// empty list, tail's previous node is head
		tmpListTail->next = NULL;		// tail doesn't have any next nodes

	// search criteria node
		searchCriteriaContact = (struct contact *)malloc(sizeof(struct contact));
		clearContact(searchCriteriaContact);

	// default loading and saving file
		strcpy(fileName,"default.csv");
}

