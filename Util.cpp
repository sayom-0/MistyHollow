//
// Created by sjet on 3/27/20.
//

#include <iostream>
#include <ncurses.h>

namespace UT
{
	void static hold()
	{
		initscr();
		noecho();
		cbreak();
		std::cout << "Press any key to Continue" << std::endl;
		getch();
		if (system("CLS")) system("clear");
		endwin();
	}

}