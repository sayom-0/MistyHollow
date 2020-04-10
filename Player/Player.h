//
// Created by sjet on 3/24/20.
//

#ifndef HOLLOW_PLAYER_H
#define HOLLOW_PLAYER_H

#include <string>
#include <vector>
#include <iostream>
#include <ncurses.h>
#include "../Resources/Item.h"
#include "../Events/RandomEvent.h"
#include "../Util.cpp"

class Player
{
private:
	std::string name;
	std::vector<Item> inv;
	int healthMax;
	int healthCur;
	int gold;
	int manaMax;
	int manaCur;
	int xp;
public:

	Player();

	Player(std::string name);

	std::string toString();

	std::string purchase(Item i);

	void handleEvent(RandomEvent rv);

	void enemyDeath(RandomEvent &rv);

	int attack();

	int splattack();

	void dmg(int i);

	void rest();

	bool isDead();

};


#endif //HOLLOW_PLAYER_H
