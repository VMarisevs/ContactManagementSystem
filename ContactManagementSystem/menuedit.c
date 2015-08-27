#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "printstring.h"
#include "contacts.h"

void insertNewContact(struct contact *headContact, struct contact *tailContact)
{
	int x = 40, y = 4;
	struct contact *newContact;

	newContact = (struct contact *)malloc(sizeof(struct contact));

		// read all variables
		setCursorPosition(x,++y); printColouredText("First Name:", 2);
		fflush(stdin);
		gets_s(newContact->firstName ,MAXSTRLENGTH);

		setCursorPosition(x,++y); printColouredText("Last Name:", 2);
		fflush(stdin);
		gets_s(newContact->lastName ,MAXSTRLENGTH);

		setCursorPosition(x,++y); printColouredText("PhoneNumber:", 2);
		fflush(stdin);
		gets_s(newContact->phoneNumber ,MAXSTRLENGTH);

		setCursorPosition(x,++y); printColouredText("Email:", 2);
		fflush(stdin);
		gets_s(newContact->email ,MAXSTRLENGTH);

		setCursorPosition(x,++y); printColouredText("Company:", 2);
		fflush(stdin);
		gets_s(newContact->company ,MAXSTRLENGTH);

		addNewContact(headContact, tailContact, newContact);
}

void editContact(struct contact *headContact)
{	
	int x = 40, y = 4;

	struct contact *newContact;
	newContact = (struct contact *)malloc(sizeof(struct contact));
	clearContact(newContact);

	setCursorPosition(x,y); printColouredText("please enter record id: ", 2);
	fflush(stdin);
	scanf_s("%i", &newContact->idNum);
	
	// read each part which should be altered
		setCursorPosition(x,++y); printColouredText("First Name:", 2);
		fflush(stdin);
		gets_s(newContact->firstName ,MAXSTRLENGTH);

		setCursorPosition(x,++y); printColouredText("Last Name:", 2);
		fflush(stdin);
		gets_s(newContact->lastName ,MAXSTRLENGTH);

		setCursorPosition(x,++y); printColouredText("PhoneNumber:", 2);
		fflush(stdin);
		gets_s(newContact->phoneNumber ,MAXSTRLENGTH);

		setCursorPosition(x,++y); printColouredText("Email:", 2);
		fflush(stdin);
		gets_s(newContact->email ,MAXSTRLENGTH);

		setCursorPosition(x,++y); printColouredText("Company:", 2);
		fflush(stdin);
		gets_s(newContact->company ,MAXSTRLENGTH);

	findEditContact(headContact, newContact);

	free(newContact);
}

void removeContact(struct contact *tailContact)
{
	struct contact *currentContact;
	currentContact = (struct contact *)malloc(sizeof(struct contact));
	clearContact(currentContact);

	setCursorPosition(40,4); printColouredText("please enter record id: ", 2);
	fflush(stdin);
	scanf_s("%i", &currentContact->idNum);
	

	findDeleteContact( tailContact, currentContact);

	free(currentContact);
}

