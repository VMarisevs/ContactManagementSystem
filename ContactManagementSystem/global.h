#pragma once
// removes warning

#ifndef GLOBALS_H
#define GLOBALS_H

	#define MAXSTRLENGTH 30

	struct contact
		{
			int idNum;
			char firstName[MAXSTRLENGTH];
			char lastName[MAXSTRLENGTH];
			char phoneNumber[MAXSTRLENGTH];
			char email[MAXSTRLENGTH];
			char company[MAXSTRLENGTH];

			struct contact *next;
			struct contact *prev;
		};

	char fileName[MAXSTRLENGTH];

	char secretkey[8];

	struct contact *listHead;	// main doubly linked list
	struct contact *listTail;

	struct contact *tmpListHead;	// temp doubly linked list
	struct contact *tmpListTail;	// used for search

	struct contact *searchCriteriaContact; // structure that used for search

	void initGlobals();	// init all global pointers

#endif