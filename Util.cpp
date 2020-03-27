//
// Created by sjet on 3/27/20.
//

#include <iostream>
#include <ncurses.h>

namespace UT
{
	void static hold()
	{
		std::cout << "Press Enter to Continue" << std::endl;
		char enter;

		do
			enter = getch();
		while (enter != '\n');
	}

}