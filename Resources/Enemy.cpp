//
// Created by sjet on 3/24/20.
//

#include <string>
#include <iostream>
#include "Enemy.h"

namespace EMY
{
	class Enemy
	{
	private:
		std::string name;
		int health;
		int dmg;
		bool safeLoot;
	public:

		Enemy()
		{
			name = "Generic Enemy";
			health = (rand() % 8) + 1;
			dmg = rand() % 5;
			safeLoot = rand() % 2;
			std::cout << "Health (INIT) : " + std::to_string(health) << std::endl;
		}

		int attack()
		{
			return dmg;
		}

		void hit(int i)
		{
			health = health - i;
			std::cout << "Health : " + std::to_string(health) << std::endl;
		}

		int loot()
		{
			return rand() % 5;
		}

		bool isDead()
		{
			std::cout << std::to_string(health) + " dead check" << std::endl;
			return health > 0 ? false : true;
		}

		bool isSafe()
		{
			return safeLoot;
		}

		std::string getName()
		{
			return name;
		}


	};
}
