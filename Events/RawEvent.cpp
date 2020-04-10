//
// Created by sjet on 3/25/20.
//


#include "RawEvent.h"

std::vector<std::string> ttv;
std::string text;
Enemy enemy;
Chest chest;
Town town;
int type;
bool fin;

RawEvent::RawEvent()
{
	srand(time(0));
	type = rand() % 3;

	if (type == 0)
	{
		ttv.push_back("A " + enemy.getName() + " has appeared... What will you do?");
		ttv.push_back("You hear footsteps behind you, you turn around and see a " + enemy.getName() +
					  " ready to attack.");
		text = ttv[rand() % ttv.size()];
	}
	if (type == 1)
	{
		ttv.push_back("You come across a mysterious " + chest.getType() + " chest");
		ttv.push_back(
				"You wipe the sweat off your face and blink, when you open your eyes again a " +
				chest.getType() + " chest has appeared.");

		text = ttv[rand() % ttv.size()];
	}
	if (type == 2)
	{
		ttv.push_back("You come across what seems to be a small town.");
		ttv.push_back("As you make your way out of a foliage dense path, you see a town in the distance.");

		text = ttv[rand() % ttv.size()];
	}


}

void RawEvent::over()
{
	fin = true;
}

std::string RawEvent::getText()
{
	return text;
}

Enemy &RawEvent::getEnemy()
{
	return enemy;
}

Chest RawEvent::getChest()
{
	return chest;
}

int RawEvent::getType()
{
	return type;
}

bool RawEvent::isOver()
{
	return fin;
}


