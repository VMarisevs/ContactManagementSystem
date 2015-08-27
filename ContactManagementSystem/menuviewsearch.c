#include <string.h>
#include <stdlib.h>
#include <stdio.h>


#include "menuviewsearch.h"

#include "global.h"
#include "contacts.h"
#include "printstring.h"

int x = 40, y = 4;

void setIDSearchCriteria(struct contact *searchCriteria)
{
	setCursorPosition(x,y); printColouredText("Id: ", 2);
	fflush(stdin);
	scanf_s("%i", &searchCriteria->idNum);
}

void setfnameCriteria(struct contact *searchCriteria)
{
	setCursorPosition(x,y); printColouredText("Name: ", 2);
	fflush(stdin);
	gets_s(searchCriteria->firstName ,MAXSTRLENGTH);
}

void setlnameCriteria(struct contact *searchCriteria)
{
	setCursorPosition(x,y); printColouredText("Surname: ", 2);
	fflush(stdin);
	gets_s(searchCriteria->lastName ,MAXSTRLENGTH);
}

void setphoneCriteria(struct contact *searchCriteria)
{
	setCursorPosition(x,y); printColouredText("Phone: ", 2);
	fflush(stdin);
	gets_s(searchCriteria->phoneNumber ,MAXSTRLENGTH);
}

void setemailCriteria(struct contact *searchCriteria)
{
	setCursorPosition(x,y); printColouredText("Email: ", 2);
	fflush(stdin);
	gets_s(searchCriteria->email ,MAXSTRLENGTH);
}

void setcompanyCriteria(struct contact *searchCriteria)
{
	setCursorPosition(x,y); printColouredText("Company: ", 2);
	fflush(stdin);
	gets_s(searchCriteria->company ,MAXSTRLENGTH);
}

void search(struct contact *searchCriteria, struct contact *listHead, struct contact *tmpListHead, struct contact *tmpListTail)
{
	int i = 0;
	int isSuitable = 0; // 0 = false, 1 = true

	struct contact *currentContact;
	currentContact = listHead->next;
	
	

	while (currentContact->next != NULL)
	{
		
		if (searchCriteria->idNum == currentContact->idNum)
		{
			// add new into temp list
			insertContact(tmpListHead, tmpListTail, currentContact);
			
		} else
		{
			isSuitable = 0;

			for (i = 0; i < 5; i++)
			{
				switch (i)
				{
					case 0:
						{
							if (strlen(searchCriteria->firstName)>0)
							{
								if (strstr(currentContact->firstName, searchCriteria->firstName))
								{
									isSuitable = 1;
								} else
								{
									isSuitable = 0;
								}
							}
							break;
						}
					case 1:
						{
							if (strlen(searchCriteria->lastName)>0)
							{
								if (strstr(currentContact->lastName, searchCriteria->lastName))
								{
									isSuitable = 1;
								}else
								{
									isSuitable = 0;
								}
							}
							break;
						}
					case 2:
						{
							if (strlen(searchCriteria->email)>0)
							{
								if (strstr(currentContact->email, searchCriteria->email))
								{
									isSuitable = 1;
								} else
								{
									isSuitable = 0;
								}
							}
							break;
						}
					case 3:
						{
							if (strlen(searchCriteria->phoneNumber)>0)
							{
								if (strstr(currentContact->phoneNumber, searchCriteria->phoneNumber))
								{
									isSuitable = 1;
								} else
								{
									isSuitable = 0;
								}
							}
							break;
						}
					case 4:
						{
							if (strlen(searchCriteria->company)>0)
							{
								if (strstr(currentContact->company, searchCriteria->company))
								{
									isSuitable = 1;
								} else
								{
									isSuitable = 0;
								}
							}
							break;
						}
				}
			}		
			
			if (isSuitable == 1 )
			{
				insertContact(tmpListHead, tmpListTail, currentContact);
			}
		}
			
		currentContact = currentContact->next;
		
	}
}