#include <stdlib.h>

#include "menu.h"
#include "printstring.h"

void printAbout()
{
	printframe(8, 3, 72, 18, 4);
	printframe(9, 3, 71, 18, 2);

	printframe(25, 7, 55, 9, 6);
	setCursorPosition(28,8);
	printColouredText("Contact Management System",3);

	setCursorPosition(37,12);
	printColouredText("Prepared by: Vladislavs Marisevs",5);
	setCursorPosition(32,13);
	printColouredText("For the attention of: Damien Costello",5);
	setCursorPosition(35,14);
	printColouredText("Class: Software Development year 2",5);
	setCursorPosition(25,15);
	printColouredText("College: Galway Mayo Institute of Technology",5);
	setCursorPosition(37,16);
	printColouredText("Submission Date: April 28th 2014",5);

	setCursorPosition(28,24);
	system("pause");
}