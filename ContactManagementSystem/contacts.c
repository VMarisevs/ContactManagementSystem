
#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "contacts.h"
#include "global.h"

void clearContact(struct contact *currentContact)
{
	currentContact->idNum = 0;
	strcpy(currentContact->firstName , "");
	strcpy(currentContact->lastName , "");
	strcpy(currentContact->phoneNumber , "");
	strcpy(currentContact->email , "");
	strcpy(currentContact->company , "");

}

void clearContactList(struct contact *tailContact)
{
	struct contact *selected;
	selected = tailContact->prev;

	while (selected->prev != NULL)
		{
			selected->prev->next = selected->next; // removing links from next(tail) and previous elements
			selected->next->prev = selected->prev;

			free(selected); 

			selected = tailContact->prev;

			tailContact->idNum--;
		}

		tailContact->prev->idNum = 0; // wipes the auto increment
}

void copyContactList(struct contact *sourceHead,struct contact *sourceTail,struct contact *destinationHead,struct contact *destinationTail)
{
	struct contact *currentContact;
	currentContact = sourceHead->next;

	while  (currentContact->next != NULL)
	{
		insertContact(destinationHead, destinationTail, currentContact);
		currentContact = currentContact->next;
	}



}

void addNewContact(struct contact *headContact, struct contact *tailContact, struct contact *currentContact)
{
	struct contact *newContact;
	newContact = (struct contact *)malloc(sizeof(struct contact));

	// assigning new values
	newContact->idNum = ++headContact->idNum;
	strcpy(newContact->firstName, currentContact->firstName);
	strcpy(newContact->lastName, currentContact->lastName);
	strcpy(newContact->email, currentContact->email);
	strcpy(newContact->company, currentContact->company);
	strcpy(newContact->phoneNumber, currentContact->phoneNumber);

	// changing pointers on new element
	newContact->next = tailContact;
	newContact->prev = tailContact->prev;

	// changing pointers in the list
	tailContact->prev->next = newContact;
	tailContact->prev = newContact;

	// keeps the size of list
	tailContact->idNum++;

	// updates auto increment 
	if (newContact->idNum > headContact->idNum)
	{
		headContact->idNum = newContact->idNum;
	}


}

void insertContact(struct contact *headContact, struct contact *tailContact, struct contact *currentContact)
{
	struct contact *newContact;
	newContact = (struct contact *)malloc(sizeof(struct contact));

	// assigning new values
	newContact->idNum = currentContact->idNum;
	strcpy(newContact->firstName, currentContact->firstName);
	strcpy(newContact->lastName, currentContact->lastName);
	strcpy(newContact->email, currentContact->email);
	strcpy(newContact->company, currentContact->company);
	strcpy(newContact->phoneNumber, currentContact->phoneNumber);

	// changing pointers on new element
	newContact->next = tailContact;
	newContact->prev = tailContact->prev;

	// changing pointers in the list
	tailContact->prev->next = newContact;
	tailContact->prev = newContact;

	// keeps the size of list
	tailContact->idNum++;

	// updates auto increment 
	if (newContact->idNum > headContact->idNum)
	{
		headContact->idNum = newContact->idNum;
	}

}

void copyContact(struct contact *sourceContact, struct contact *destinationContact)
{
	destinationContact->idNum = sourceContact->idNum;
	strcpy(destinationContact->firstName, sourceContact->firstName);
	strcpy(destinationContact->lastName, sourceContact->lastName);
	strcpy(destinationContact->phoneNumber, sourceContact->phoneNumber);
	strcpy(destinationContact->email, sourceContact->email);
	strcpy(destinationContact->company, sourceContact->company);
}


int deleteLastContact(struct contact *tailContact)
{
	struct contact *currentContact;
	currentContact = tailContact->prev;

	// removing from the list if it is not head element
	if (currentContact->prev != NULL)
	{
		currentContact->prev->next = currentContact->next;
		currentContact->next->prev = currentContact->prev;
		free(currentContact);

		// decreasing list size
		tailContact->idNum--;
	
		// returns true if contact was deleted
		return 1;
	}

	//returns false if there was no record in the list
	return 0;
}

int findDeleteContact( struct contact *tailContact, struct contact *deletedContact)
{
	struct contact *currentContact;
	currentContact = tailContact->prev;
	
	// while it's not the last element except first element
	while (currentContact->prev != NULL)
	{
		if (deletedContact->idNum == currentContact->idNum)
		{
			// comparing id numbers
			// removing links in the list
			currentContact->prev->next = currentContact->next;
			currentContact->next->prev = currentContact->prev;
			//removing element from memory
			free(currentContact);
			
			tailContact->idNum--;
			// returns true if the record was deleted
			return 1;
		}

		currentContact = currentContact->prev;
	}


	// returns false if there was no record with certain id
	return 0;
}

int findEditContact(struct contact *headContact, struct contact *editedContact)
{
	struct contact *currentContact;
	currentContact = headContact->next;

	//
	while (currentContact->next != NULL)
	{
		if (editedContact->idNum == currentContact->idNum)
		{
			if (strlen(editedContact->firstName) > 0)
			{
				strcpy(currentContact->firstName, editedContact->firstName);
			}

			if (strlen(editedContact->lastName) > 0)
			{
				strcpy(currentContact->lastName, editedContact->lastName);
			}

			if (strlen(editedContact->phoneNumber) > 0)
			{
				strcpy(currentContact->phoneNumber, editedContact->phoneNumber);
			}

			if (strlen(editedContact->email) > 0)
			{
				strcpy(currentContact->email, editedContact->email);
			}

			if (strlen(editedContact->company) > 0)
			{
				strcpy(currentContact->company, editedContact->company);
			}

			return 1;
		}

		currentContact = currentContact->next;
	}

	return 0;
}

int compare(struct contact *firstContact, struct contact *secondContact, char compareBy)
{
	// compareBy : 
	// i - id; 
	// f - first name; 
	// s - surname;
	// p - phone;
	// e - email;
	// c - compare;

	int result = 0; // 0 equals, 1 first > second, -1 first < second

	switch (compareBy)
	{
		case 'i':
			{
				if (firstContact->idNum > secondContact->idNum)
				{
					result = 1;
				} 
				else if (firstContact->idNum < secondContact->idNum)
				{
					result = -1;
				}

				break;
			}
		case 'f':
			{
				result = strcmp(firstContact->firstName, secondContact->firstName);
				break;
			}
		case 's':
			{
				result = strcmp(firstContact->lastName, secondContact->lastName);
				break;
			}
		case 'p':
			{
				result = strcmp(firstContact->phoneNumber, secondContact->phoneNumber);
				break;
			}
		case 'e':
			{
				result = strcmp(firstContact->email, secondContact->email);
				break;
			}
		case 'c':
			{
				result = strcmp(firstContact->company, secondContact->company);
				break;
			}
	}

	return result;
}
