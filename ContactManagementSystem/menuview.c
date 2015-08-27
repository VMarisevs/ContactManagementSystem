#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdlib.h>
#include <stdio.h>

#include "menuview.h"

#include "global.h"
#include "printstring.h"


void printList(struct contact *listHead)
	{
		char id[5];
		int x = 20, y=4, headerX= 5, headerY = 2;
		struct contact *selected;
		selected = listHead->next;

		system("cls");
		
		//header
		setCursorPosition(1, headerY);
		printColouredText("Id", 2);
		setCursorPosition(headerX,headerY);
		printColouredText("Name", 2);
		setCursorPosition((headerX+=10), headerY);
		printColouredText("Surname", 2);
		setCursorPosition((headerX+=11), headerY);
		printColouredText("Phone", 2);
		setCursorPosition((headerX+=10), headerY);
		printColouredText("Email", 2);
		setCursorPosition((headerX+=25), headerY);
		printColouredText("Company", 2);
		setCursorPosition((headerX+=15), headerY);
		
		while (selected->next != NULL)
		{
			x = 1;
			setCursorPosition(x,y);
			
			sprintf(id,"%i",selected->idNum);
			printColouredText(id, 2);

			setCursorPosition(x+=4,y);
			printColouredText(selected->firstName, 2);
			setCursorPosition((x+=10), y);
			printColouredText(selected->lastName, 2);
			setCursorPosition((x+=11), y);
			printColouredText(selected->phoneNumber, 2);
			setCursorPosition((x+=10), y);
			printColouredText(selected->email, 2);
			setCursorPosition((x+=25), y);
			printColouredText(selected->company, 2);
			setCursorPosition((x+=15), y);

			selected = selected->next;
			y++;
		}

		setCursorPosition(20,y+=4);
		system("pause");
	}