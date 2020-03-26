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
			dmg = rand() % 3;
			safeLoot = rand() % 2;
		}

		int attack()
		{
			return dmg;
		}

		void hit(int i)
		{
			health -= i;
			std::cout << "Health : " + std::to_string(health) << std::endl;
		}

		int loot()
		{
			return rand() % 5;
		}

		bool isDead()
		{
			if (health > 0)
				return false;
			return true;
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
