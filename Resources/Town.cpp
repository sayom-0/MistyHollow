//
// Created by sjet on 4/9/20.
//

#include "Town.h"

Town::Town()
{
	srand(time(0));
	rcost = rand() % 10;
	rest = rand() % 2;
	shop = rand() % 2;
	quest = rand() % 2;
}

bool Town::getRest()
{
	return rest;
}

bool Town::getShop()
{
	return shop;
}

bool Town::getQuest()
{
	return quest;
}

int Town::getRCost()
{
	return rcost;
}
