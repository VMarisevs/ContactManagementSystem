#pragma once
// removes warning

#ifndef MENU_H
#define MENU_H

	#define LASTMENUITEM 4 // it's always should be exit! starting from 0
	#define FILEBACKBTN 4
	#define EDITBACKBTN 3
	#define VIEWBACKBTN 3
	#define VIEWSORTBACKBTN 6
	#define VIEWSEARCHBACKBTN 8

	// keys
	#define ENTER 13
	#define ESC 27
	#define UPARROW 72
	#define DOWNARROW 80


	// functions
	void initMenu();
	void printMenuItems(int selectedItem);
	int selectMenu();

	void printSubMenuItems(int selectedItem, int selectedSubmenuItem);
	int selectSubMenu(int selectedMenu);

	void printSubSubMenuItems(int selectedItem, int selectedSubmenuItem, int selectedSubSubmenuItems);
	int selectSubSubMenu(int selectedMenu, int selectedSubMenu);
	
	//
	void printAbout();
#endif