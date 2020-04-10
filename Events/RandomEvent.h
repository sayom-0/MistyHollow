//
// Created by sjet on 3/24/20.
//

#ifndef HOLLOW_RANDOMEVENT_H
#define HOLLOW_RANDOMEVENT_H

#include <string>
#include "../Events/RawEvent.h"

class RandomEvent
{
private:
	RawEvent iev;
public:

	std::string getText();

	std::string getOpt();

	Enemy &getEnemy();

	void over();

	bool isDgr();

	int open();

	int getType();

	bool isOver();
};


#endif //HOLLOW_RANDOMEVENT_H
