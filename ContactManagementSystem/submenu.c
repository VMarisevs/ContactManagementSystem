#include <stdlib.h>
#include <conio.h>

#include "menu.h"
#include "printstring.h"

void printSubMenuItems(int selectedItem, int selectedSubmenuItem)
{
	int subMX = 15, subMY = 3, arrX = 12;
	printMenuItems(selectedItem);

	switch (selectedItem)
	{
		//file menu
		case 0:
			{
				// selecting an element in menu list
				int itemsSelection[FILEBACKBTN+1] = {2,2,2,2,2};
				itemsSelection[selectedSubmenuItem] = 1;

				setCursorPosition(arrX,subMY);
				printColouredText("=>",2);

				setCursorPosition(subMX,subMY);	
				printColouredText("  Load    ",itemsSelection[0]);

				setCursorPosition(subMX,++subMY);
				printColouredText("  Save    ", itemsSelection[1]);

				setCursorPosition(subMX,++subMY);
				printColouredText("  Save As ",itemsSelection[2]);

				setCursorPosition(subMX,++subMY);
				printColouredText("  Save Encrypted ",itemsSelection[3]);

				setCursorPosition(subMX,++subMY);
				printColouredText("  Back    ",itemsSelection[4]);

				break;
			   }
		//edit menu
		case 1:
			{
				// selecting an element in menu list
				int itemsSelection[EDITBACKBTN+1] = {2,2,2,2};
				itemsSelection[selectedSubmenuItem] = 1;

				setCursorPosition(arrX,++subMY);
				printColouredText("=>",2);

				setCursorPosition(subMX,subMY);	
				printColouredText("  Add     ",itemsSelection[0]);

				setCursorPosition(subMX,++subMY);
				printColouredText("  Edit    ", itemsSelection[1]);

				setCursorPosition(subMX,++subMY);
				printColouredText("  Remove  ",itemsSelection[2]);

				setCursorPosition(subMX,++subMY);
				printColouredText("  Back    ",itemsSelection[3]);
				break;
			   }
		//view menu
		case 2:
			{
				// selecting an element in menu list
				int itemsSelection[VIEWBACKBTN+1] = {2,2,2,2};
				itemsSelection[selectedSubmenuItem] = 1;
				
				setCursorPosition(arrX,(subMY+=2));
				printColouredText("=>",2);

				setCursorPosition(subMX,subMY);	
				printColouredText("  Print  ",itemsSelection[0]);

				setCursorPosition(subMX,++subMY);
				printColouredText("  Sort   ", itemsSelection[1]);

				setCursorPosition(subMX,++subMY);
				printColouredText("  Search ",itemsSelection[2]);

				setCursorPosition(subMX,++subMY);
				printColouredText("  Back   ",itemsSelection[3]);
				break;
			   }

	}

}

int selectSubMenu(int selectedMenu)
{
	int keyPressed;
	int selectedSubMenuItem = 0;
	int menuMax[3] = {FILEBACKBTN,EDITBACKBTN,VIEWBACKBTN};

	printSubMenuItems(selectedMenu,selectedSubMenuItem);

	// menu view
	do
	{
		keyPressed = _getch();

		switch (keyPressed)
		{
		case UPARROW:
			selectedSubMenuItem--;
			if(selectedSubMenuItem<0)
			{
				selectedSubMenuItem = menuMax[selectedMenu];
			}

			break;


		case DOWNARROW:
			selectedSubMenuItem++;
			if(selectedSubMenuItem > menuMax[selectedMenu])
			{
				selectedSubMenuItem = 0;
			}
			break;
		}
		printSubMenuItems(selectedMenu,selectedSubMenuItem);
	}
	while (keyPressed!=ENTER);
	
	
return selectedSubMenuItem;
}