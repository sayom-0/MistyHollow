#include <iostream>
#include "Player/Player.h"

using namespace std;

int main()
{
	if (system("CLS")) system("clear");
	cout << "	--- MistyHollow Alpha 6 C++20 ---	" << endl;
	cout << "	Developed by Sayom tal Rasha - \"I'm just a simple CS student trying to make my way in the Universe\""
		 << endl;

	cout << "What is your name, Hollow One?" << endl;
	string input;
	cin >> input;
	Player ply = Player(input);
	cout << "Well, " + input + " , welcome to Misty Hollow, you can find yourself here..." << endl;
	hold();
	cout << "You wake up lost in an empty town, wondering why no one else is around..." << endl;
	hold();
	while (!ply.isDead())
	{
		ply.handleEvent(RandomEvent());
	}
	cout << "Well " + input + ", its a shame you wont live, but then again, who really does?" << endl;
	return 0;
}
