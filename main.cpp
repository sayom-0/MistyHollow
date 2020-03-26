#include <iostream>
#include "Player/Player.cpp"

using namespace std;

int main()
{
	cout << "	--- MistyHollow Alpha 3 C++20 ---	" << endl;
	cout << "	Developed by Sayom tal Rasha \"I'm just a simple CS student trying to make my way in the universe\"" << endl;

	cout << "What is your name, Hollow One?" << endl;
	string input;
	cin >> input;
	PLY::Player ply = PLY::Player(input);
	cout << "Well, " + input + " , welcome to Misty Hollow, you can find yourself here..." << endl
		 << "You wake up lost in an empty town, wondering why no one else is around..." << endl;
	while (!ply.isDead())
	{
		EVNT::RandomEvent evnt;
		ply.handleEvent(evnt);
	}
	cout << "Well " + input + ", its a shame you wont live, but then again, who really does?" << endl;
	return 0;
}
