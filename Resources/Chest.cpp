//
// Created by sjet on 3/25/20.
//

#include <string>
#include <vector>
#include "Chest.h"

namespace CHT
{
	class Chest
	{
	private:
		std::vector<std::string> msgs;
		std::string msg;
		int ov;
		bool dgr;
	public:
		Chest()
		{
			msgs.push_back("Gold Plated");
			msgs.push_back("Silver");
			msgs.push_back("Wooden");
			msgs.push_back("Icy");
			msg = msgs[rand() % msgs.size()];
			dgr = rand() % 2;
			ov = rand() % 20;
		}

		std::string getType()
		{
			return msg;
		}

		int open()
		{
			return ov;
		}

		bool isDgr()
		{
			return dgr;
		}
	};
}