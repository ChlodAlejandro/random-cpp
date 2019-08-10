#include<iostream>
#include<string>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	if(size == 0)
	{
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	}
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}

main() {
	srand(time(NULL));
    setcursor(0,0);
    
    for (int z = 0; z < 200; z++) {
    	int randX = rand() % (47);
	    int randY = rand() % (21);
	    int randColor = rand() % (16 - 1) + 1;
	    
	    SetConsoleTextAttribute(console, randColor);
	    
		COORD pt = {randX, randY};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pt);
		
		cout << "bruh";
		
		Sleep(100);
	}
	
	SetConsoleTextAttribute(console, 7);
	system("pause > nul");
	Sleep(2000);
}
