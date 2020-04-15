//
// Created by sjet on 3/25/20.
//

#ifndef HOLLOW_RAWEVENT_H
#define HOLLOW_RAWEVENT_H


#include <string>
#include <vector>
#include "../Resources/Enemy.h"
#include "../Resources/Chest.h"
#include "../Resources/Town.h"

class RawEvent
{
private:
	std::vector<std::string> ttv;
	std::string text;
	Enemy enemy;
	Chest chest;
	Town town;
	int type;
	bool fin{};
public:
	RawEvent();

	void over();

	std::string getText();

	Enemy &getEnemy();

	Chest & getChest();

	int getType();

	bool isOver();

	Town & getTown();
};


#endif //HOLLOW_RAWEVENT_H
