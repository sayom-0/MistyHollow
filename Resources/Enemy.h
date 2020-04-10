//
// Created by sjet on 3/24/20.
//

#ifndef HOLLOW_ENEMY_H
#define HOLLOW_ENEMY_H

#include <string>

class Enemy
{
private:
	std::string name;
	int health;
	int dmg;
	bool safeLoot;
public:

	Enemy();

	int attack();

	void hit(int i);

	int loot();

	bool isDead();

	bool isSafe();

	std::string getName();


};


#endif //HOLLOW_ENEMY_H
