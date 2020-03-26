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
			srand(time(0));
			health = rand() % 8;
			dmg = rand() % 5;
			safeLoot = rand() % 2;
		}

		int attack()
		{
			return dmg;
		}

		void hit(int i)
		{
			this->health -= i;
		}

		int loot()
		{
			return rand() % 5;
		}

		bool isDead()
		{
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
