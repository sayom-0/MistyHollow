//
// Created by sjet on 4/9/20.
//

#ifndef HOLLOW_TOWN_H
#define HOLLOW_TOWN_H

#include <time.h>
#include <cstdlib>

class Town
{
private:
	bool rest;
	bool shop;
	bool quest;
	int rcost;
public:
	Town();

	bool getRest();

	bool getShop();

	bool getQuest();

	int getRCost();
};


#endif //HOLLOW_TOWN_H
