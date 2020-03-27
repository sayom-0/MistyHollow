#include <iostream>
#include <ncurses.h>
#include "Player/Player.cpp"

using namespace std;

int main()
{
	cout << "	--- MistyHollow Alpha 5 C++20 ---	" << endl;

	WINDOW *win = stdscr;
	initscr();
	noecho();
	cbreak();

	cout << "	Developed by Sayom tal Rasha - \"I'm just a simple CS student trying to make my way in the Universe\""
		 << endl;

	cout << "What is your name, Hollow One?" << endl;
	string input;
	cin >> input;
	PLY::Player ply = PLY::Player(input);
	cout << "Well, " + input + " , welcome to Misty Hollow, you can find yourself here..." << endl;
	UT::hold();
	cout << "You wake up lost in an empty town, wondering why no one else is around..." << endl;
	UT::hold();
	while (!ply.isDead())
	{
		ply.handleEvent(EVNT::RandomEvent());
	}
	cout << "Well " + input + ", its a shame you wont live, but then again, who really does?" << endl;

	endwin();

	return 0;
}
