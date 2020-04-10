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
	msgs.push_back("Gold Plated");
	msgs.push_back("Silver");
	msgs.push_back("Wooden");
	msgs.push_back("Icy");
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