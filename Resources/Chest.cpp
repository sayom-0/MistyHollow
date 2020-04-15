//
// Created by sjet on 3/25/20.
//

#include "Chest.h"

std::vector<std::string> msgs;
std::string msg;
int ov;
bool dgr;

Chest::Chest()
{
	srand(time(0));
	msgs.emplace_back("Gold Plated");
	msgs.emplace_back("Silver");
	msgs.emplace_back("Wooden");
	msgs.emplace_back("Icy");
	msg = msgs[rand() % msgs.size()];
	dgr = rand() % 2;
	ov = rand() % 20;
}

std::string Chest::getType()
{
	return msg;
}

int Chest::open()
{
	return ov;
}

bool Chest::isDgr()
{
	return dgr;
}