//
// Created by sjet on 3/24/20.
//

#include "Enemy.h"

std::string name;
int health;
int dmg;
bool safeLoot;

Enemy::Enemy()
{
	name = "Generic Enemy";
	srand(time(0));
	health = rand() % 8;
	dmg = rand() % 5;
	safeLoot = rand() % 2;
}

int Enemy::attack()
{
	return dmg;
}

void Enemy::hit(int i)
{
	health -= i;
}

int Enemy::loot()
{
	return rand() % 5;
}

bool Enemy::isDead()
{
	return health > 0 ? false : true;
}

bool Enemy::isSafe()
{
	return safeLoot;
}

std::string Enemy::getName()
{
	return name;
}
