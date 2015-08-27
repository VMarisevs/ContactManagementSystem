#include <stdlib.h>
#include <conio.h>

#include "menu.h"
#include "printstring.h"


void printSubSubMenuItems(int selectedItem, int selectedSubmenuItem, int selectedSubSubmenuItems)
{
	int subMX = 29, subMY = 3, arrX = 26;
	printSubMenuItems(selectedItem, selectedSubmenuItem);

	switch(selectedItem)
	{
		case 0:
			{
				break;
			}
		case 1:
			{
				break;
			}
		case 2:
			//view menu
			{
				switch(selectedSubmenuItem)
				{
					case 0:
						{//print
							break;
						}
					case 1:
						{//sort
							int itemsSelection[VIEWSORTBACKBTN+1] = {2,2,2,2,2,2,2};
							itemsSelection[selectedSubSubmenuItems] = 1;

							setCursorPosition(arrX,subMY+=3);
							printColouredText("=>",2);

							setCursorPosition(subMX,subMY);
							printColouredText(" Id      ", itemsSelection[0]);

							setCursorPosition(subMX,++subMY);
							printColouredText(" Name    ", itemsSelection[1]);

							setCursorPosition(subMX,++subMY);
							printColouredText(" Surname ",itemsSelection[2]);

							setCursorPosition(subMX,++subMY);
							printColouredText(" Phone   ",itemsSelection[3]);

							setCursorPosition(subMX,++subMY);
							printColouredText(" Email   ",itemsSelection[4]);

							setCursorPosition(subMX,++subMY);
							printColouredText(" Company ",itemsSelection[5]);

							setCursorPosition(subMX,++subMY);
							printColouredText(" Back   ",itemsSelection[6]);


							break;
						}
					case 2:
						{//search
							int itemsSelection[VIEWSEARCHBACKBTN+1] = {2,2,2,2,2,2,2,2};
							itemsSelection[selectedSubSubmenuItems] = 1;
							
							setCursorPosition(arrX,subMY+=4);
							printColouredText("=>",2);

							setCursorPosition(subMX,subMY);	
							printColouredText(" Clear   ",itemsSelection[0]);

							setCursorPosition(subMX,++subMY);
							printColouredText(" Id      ", itemsSelection[1]);

							setCursorPosition(subMX,++subMY);
							printColouredText(" Name    ", itemsSelection[2]);

							setCursorPosition(subMX,++subMY);
							printColouredText(" Surname ",itemsSelection[3]);

							setCursorPosition(subMX,++subMY);
							printColouredText(" Phone   ",itemsSelection[4]);

							setCursorPosition(subMX,++subMY);
							printColouredText(" Email   ",itemsSelection[5]);

							setCursorPosition(subMX,++subMY);
							printColouredText(" Company ",itemsSelection[6]);

							setCursorPosition(subMX,++subMY);
							printColouredText(" Search  ",itemsSelection[7]);

							setCursorPosition(subMX,++subMY);
							printColouredText(" Back   ",itemsSelection[8]);
							break;
						}
				}
				break;
			}
	}
}

int selectSubSubMenu(int selectedMenu, int selectedSubMenu)
{
	int keyPressed;
	int selectedSubSubMenuItem = 0;
	int menuMax[3] = {0,VIEWSORTBACKBTN,VIEWSEARCHBACKBTN};

	printSubSubMenuItems(selectedMenu,selectedSubMenu,selectedSubSubMenuItem);

		// menu view
	do
	{
		keyPressed = _getch();

		switch (keyPressed)
		{
		case UPARROW:
			selectedSubSubMenuItem--;
			if(selectedSubSubMenuItem<0)
			{
				selectedSubSubMenuItem = menuMax[selectedSubMenu];
			}

			break;


		case DOWNARROW:
			selectedSubSubMenuItem++;
			if(selectedSubSubMenuItem > menuMax[selectedSubMenu])
			{
				selectedSubSubMenuItem = 0;
			}
			break;
		}
		printSubSubMenuItems(selectedMenu,selectedSubMenu,selectedSubSubMenuItem);
	}
	while (keyPressed!=ENTER);
	
	
return selectedSubSubMenuItem;
}