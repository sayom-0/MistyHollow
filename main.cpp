#include <iostream>
#include "Player/Player.cpp"

using namespace std;

int main()
{
	PLY::Player ply;
	EVNT::RandomEvent event;

	cout << "What is your name, Hollow One?" << endl;
	string input;
	cin >> input;
	ply = PLY::Player(input);
	cout << "Well, " + input + " , welcome to Misty Hollow, you can find yourself here..." << endl
		 << "You wake up lost in an empty town, wondering why no one else is around..." << endl;
	while (!ply.isDead())
	{
		event = EVNT::RandomEvent();
		ply.handleEvent(event);
	}
	cout << "Well " + input + ", its a shame you wont live, but then again, who really does?" << endl;
	return 0;
}
