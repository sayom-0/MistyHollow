//
// Created by sjet on 3/25/20.
//

#include <string>
#include <vector>
#include "RawEvent.h"
#include "../Resources/Enemy.cpp"
#include "../Resources/Chest.cpp"

namespace REVNT
{// Types | 0: Enemy 1: Object Intractable 2: Custom
	class RawEvent
	{
	private:
		std::vector<std::string> ttv;
		std::string text;
		EMY::Enemy enemy;
		CHT::Chest chest;
		int type;
		bool fin;
	public:
		RawEvent()
		{
			srand(time(0));
			type = rand() % 2;

			if (type == 0)
			{
				ttv.push_back("A " + enemy.getName() + " has appeared... What will you do?");
				ttv.push_back("You hear footsteps behind you, you turn around and see a " + enemy.getName() +
							  " ready to attack.");
				text = ttv[rand() % ttv.size()];
			}
			if (type == 1)
			{
				ttv.push_back("You come across a mysterious " + chest.getType() + " chest");
				ttv.push_back(
						"You wipe the sweat off your face and blink, when you open your eyes again a " +
						chest.getType() + " chest has appeared.");

				text = ttv[rand() % ttv.size()];
			}
			if (type == 2)
			{
				ttv.push_back("");

				text = ttv[rand() % ttv.size()];
			}


		}

		void over()
		{
			fin = true;
		}

		std::string getText()
		{
			return text;
		}

		EMY::Enemy &getEnemy()
		{
			return enemy;
		}

		CHT::Chest getChest()
		{
			return chest;
		}

		int getType()
		{
			return type;
		}

		bool isOver()
		{
			return fin;
		}
	};
}
