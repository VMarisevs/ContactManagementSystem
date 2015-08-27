#include "printstring.h"

#include <stdio.h>
#include <conio.h>
#include <windows.h>



void setCursorPosition(int X, int Y)
{	
// MAX X = 79
// MAX Y = 24
    COORD pos = {X, Y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void printColouredText(char varText[],int color)
{
	HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
	WORD oldColorAttrs, newColorAttrs;

	// saving default colors
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	oldColorAttrs = csbiInfo.wAttributes;

	switch(color)
	{
		case 1:
			{
			// selected menu item color
			newColorAttrs = ((FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY ) << 4);

			SetConsoleTextAttribute(h,newColorAttrs);
			
			break;
			}

		case 2:
			{
			// not selected menu item color
			newColorAttrs = ((0) << 4) + (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

			SetConsoleTextAttribute(h, newColorAttrs);
			break;
			}

		case 3:
			{
			// yellow
			newColorAttrs = ((0) << 4) + (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );

			SetConsoleTextAttribute(h, newColorAttrs);
			break;
			}

		case 4:
			{
			// white
			newColorAttrs = ((0) << 4) + (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

			SetConsoleTextAttribute(h, newColorAttrs);
			break;
			}

		case 5:
			{
			// Green
			newColorAttrs = ((0) << 4) + ( FOREGROUND_GREEN | FOREGROUND_INTENSITY );

			SetConsoleTextAttribute(h, newColorAttrs);
			break;
			}

		case 6:
			{
			// Blue
			newColorAttrs = ((0) << 4) + ( FOREGROUND_BLUE | FOREGROUND_INTENSITY );

			SetConsoleTextAttribute(h, newColorAttrs);
			break;
			}
		
	}
	printf(varText);
	//SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
	SetConsoleTextAttribute( h, oldColorAttrs);
}

void printCharSet(int firstChar, int lastChar)
{
	char varChar;
	int i;
	for (i = firstChar; i <= lastChar; i++)
	{
		varChar = (char)i;
		printf("%c ",varChar);
	}
}

void printframe(int xLeftTop, int yLeftTop, int xRightBottom, int yRightBottom, int color)
{
	char printChar[] = {"x"};
	int x,y;
	//drawing top line
	
		//printChar[0] = (char)(182);
		
		for (y = yLeftTop; y <= yRightBottom; y++)
		{
			for (x = xLeftTop; x <= xRightBottom; x++)
			{
				setCursorPosition(x,y);
				
				if ((x == xLeftTop) || (y == yLeftTop)  ||  (x == xRightBottom) || (y == yRightBottom))
				{
					printColouredText(printChar,color);
				}
			}
		}
		
}