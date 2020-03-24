//
// Created by sjet on 3/24/20.
//

#include <string>
#include "Enemy.h"

namespace EMY
{
	class Enemy
	{
	private:
		std::string name;
		int health;
		int dmg;
	public:

		Enemy()
		{
			name = "Generic Enemy";
			health = (rand() % 8) + 1;
			dmg = rand() % 3;
		}


	};
}
