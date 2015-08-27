
#include <stdlib.h>
#include <stdio.h>

#include "menuviewsort.h"

#include "global.h"
#include "contacts.h"

void selectionSort(struct contact *sourceHead,struct contact *sourceTail, struct contact *tmpHeadContact, struct contact *tmpTailContact, char type)
{
	//
	struct contact *tempContact;
	struct contact *currentContact;
	int size = sourceTail->idNum;
	
	clearContactList(tmpTailContact);

	tempContact = (struct contact *)malloc(sizeof(struct contact));
	
	currentContact = sourceTail->prev;

	clearContact(tempContact);

	// comparing the size of both lists
	while (size != tmpTailContact->idNum)
	{
		while  (currentContact->prev != NULL)
		{
			if (((compare(currentContact, tempContact, type)) == -1) || (tempContact->idNum == 0))
			{
				copyContact(currentContact, tempContact);
			}

			currentContact = currentContact->prev;
			// before circle eds, we can copy from tmp to new array and remove
			if (currentContact->prev == NULL)
			{
				insertContact(tmpHeadContact, tmpTailContact, tempContact);
				findDeleteContact(sourceTail, tempContact);
				clearContact(tempContact);
			}
		}
		currentContact = sourceTail->prev;
	}


	free(tempContact);

	copyContactList(tmpHeadContact, tmpTailContact, sourceHead, sourceTail);
	clearContactList(tmpTailContact);

}