#include <stdlib.h>
#include <conio.h>

#include "menu.h"
#include "printstring.h"
#include "global.h"
#include "contacts.h"

#include "menufile.h"
#include "menuedit.h"
#include "menuview.h"
#include "menuviewsearch.h"
#include "menuviewsort.h"

// menu functions


void printMenuItems(int selectedItem)
{
	// array of colors for menu
	int itemsSelection[LASTMENUITEM+1] = {2,2,2,2,2};
	int x = 3, y = 3;

	// setting the selected item
	itemsSelection[selectedItem] = 1;
	system("cls");

	setCursorPosition(1,1);
	printColouredText("User Menu:", 2);
	setCursorPosition(1,2);
	printColouredText("-------------------------",2);
	// printing whole menu
		setCursorPosition(x,y);	
		printColouredText("  File  ",itemsSelection[0]);

		setCursorPosition(x,++y);
		printColouredText("  Edit  ", itemsSelection[1]);

		setCursorPosition(x,++y);
		printColouredText("  View  ",itemsSelection[2]);

		setCursorPosition(x,++y);
		printColouredText("  About ",itemsSelection[3]);

		setCursorPosition(x,++y);
		printColouredText("  Exit  ",itemsSelection[4]);

}

int selectMenu()
{
	int keyPressed;
	int selectedMenuItem = 0;

	printMenuItems(selectedMenuItem);

	// menu view
	do
	{
		keyPressed = _getch();

		switch (keyPressed)
		{
		case UPARROW:
			selectedMenuItem--;
			if(selectedMenuItem<0)
			{
				selectedMenuItem = LASTMENUITEM;
			}

			break;


		case DOWNARROW:
			selectedMenuItem++;
			if(selectedMenuItem>LASTMENUITEM)
			{
				selectedMenuItem = 0;
			}
			break;
		}
		printMenuItems(selectedMenuItem);
	}
	while (keyPressed!=ENTER);
	
	
return selectedMenuItem;
}

void initMenu()
{
	int selectedMenuItem;
	int selectedSubMenuItem;
	int selectedSubSubMenuItem;

	do
	{
		selectedMenuItem = selectMenu();
		

		switch(selectedMenuItem)
		{
			// 1 menu item, File menu
			case 0:
				system("cls");
				// sub menu print
				
				do {
					selectedSubMenuItem = selectSubMenu(selectedMenuItem);

					switch(selectedSubMenuItem)
					{
						
					case 0:
						{					
							// File => Load
							clearContactList(listTail);
							readFiles(listHead, listTail);
							break;
						   }
						
					case 1:
						{
							// File => Save
							saveFile(listHead, listTail, 0);
							break;
						   }
						
					case 2:
						{
							// File => Save As
							saveAsFile(listHead, listTail, 0);
							break;
						   }
					case 3:
						{
							// File => Save As encoded
							saveAsFile(listHead, listTail, 1);
							break;
						   }
					}
				}
				while (selectedSubMenuItem != FILEBACKBTN);

				break;

			// 2 menu item
			case 1:
				system("cls");
				// sub menu print
				
				do {
					selectedSubMenuItem = selectSubMenu(selectedMenuItem);

					switch(selectedSubMenuItem)
					{
						
					case 0:
						{
							// Edit => Add
							insertNewContact(listHead, listTail);
							break;
						   }
						
					case 1:
						{
							// Edit => Edit
							editContact(listHead);
							break;
						   }
						
					case 2:
						{
							// Edit => Remove
							removeContact(listTail);
							break;
						   }
					}
				}
				while (selectedSubMenuItem != EDITBACKBTN);

				break;

			// 3 menu item
			case 2:
				// sub menu print
				
				do {
					selectedSubMenuItem = selectSubMenu(selectedMenuItem);

					switch(selectedSubMenuItem)
					{
						// View => Print
					case 0:
						{
							printList(listHead);
							break;
						   }
						// View => Sort
					case 1:
						{
							do
							{
								selectedSubSubMenuItem = selectSubSubMenu(selectedMenuItem,selectedSubMenuItem);
								switch(selectedSubSubMenuItem)
								{
									case 0:
										{
											// sort by id
											selectionSort(listHead, listTail, tmpListHead, tmpListTail, 'i');
										break;
										}
									case 1:
										{ 
											selectionSort(listHead, listTail, tmpListHead, tmpListTail, 'f');
										break;
										}
									case 2:
										{
											selectionSort(listHead, listTail, tmpListHead, tmpListTail, 's');
										break;
										}
									case 3:
										{
											selectionSort(listHead, listTail, tmpListHead, tmpListTail, 'p');
										break;
										}
									case 4:
										{
											selectionSort(listHead, listTail, tmpListHead, tmpListTail, 'e');										
										break;
										}
									case 5:
										{
											selectionSort(listHead, listTail, tmpListHead, tmpListTail, 'c');
										break;
										}
									
								}
							} while (selectedSubSubMenuItem != VIEWSORTBACKBTN);
							break;
						   }
						// View => Search
					case 2:
						{
							// sub sub menu
							do
							{
								selectedSubSubMenuItem = selectSubSubMenu(selectedMenuItem,selectedSubMenuItem);
								switch(selectedSubSubMenuItem)
								{
									case 0:
										{
											// clear search criteria
											clearContact(searchCriteriaContact);
										break;
										}
									case 1:
										{ // set id
											setIDSearchCriteria(searchCriteriaContact);
										break;
										}
									case 2:
										{
											//set fname criteria
											setfnameCriteria(searchCriteriaContact);
										break;
										}
									case 3:
										{
											setlnameCriteria(searchCriteriaContact);
										break;
										}
									case 4:
										{
											setphoneCriteria(searchCriteriaContact);
										break;
										}
									case 5:
										{
											setemailCriteria(searchCriteriaContact);
										break;
										}
									case 6:
										{
											setcompanyCriteria(searchCriteriaContact);
										break;
										}
									case 7:
										{
											clearContactList(tmpListTail);
											search(searchCriteriaContact, listHead, tmpListHead, tmpListTail);
											printList(tmpListHead);
										//search
										break;
										}

								}
							}
							while (selectedSubSubMenuItem != VIEWSEARCHBACKBTN);

							break;
						   }
					}
				}
				while (selectedSubMenuItem != EDITBACKBTN);

				break;

			// 4 menu item, About
			case 3:
				system("cls");

				printAbout();
				
				break;
		}
	}
	while (selectedMenuItem != LASTMENUITEM);
}