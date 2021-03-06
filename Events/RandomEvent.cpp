//
// Created by sjet on 3/24/20.
//

#include "RandomEvent.h"

RawEvent iev;

std::string RandomEvent::getText()
{
	return iev.getText();
}

std::string RandomEvent::getOpt()
{
	if (iev.getType() == 0)
		return " 1 - Attack \n 2 - Special Attack \n 3 - Run";
	if (iev.getType() == 1)
		return " 1 - Open the chest \n 2 - Ignore it";
	if (iev.getType() == 2)
		return " 1 - Enter the Town \n 2 - Continue your Journey";
	return "";
}

Enemy &RandomEvent::getEnemy()
{
	return iev.getEnemy();
}

Town &RandomEvent::getTown()
{
	return iev.getTown();
}

void RandomEvent::over()
{
	iev.over();
}

bool RandomEvent::isDgr()
{
	return iev.getChest().isDgr();
}

int RandomEvent::open()
{
	return iev.getChest().open();
}

int RandomEvent::getType()
{
	return iev.getType();
}

bool RandomEvent::isOver()
{
	return iev.isOver();
}

