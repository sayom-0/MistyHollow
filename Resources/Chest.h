//
// Created by sjet on 3/25/20.
//

#ifndef HOLLOW_CHEST_H
#define HOLLOW_CHEST_H

#include <string>
#include <vector>

class Chest
{
private:
	std::vector<std::string> msgs;
	std::string msg;
	int ov;
	bool dgr;
public:
	Chest();

	std::string getType();

	int open();

	bool isDgr();

};


#endif //HOLLOW_CHEST_H
