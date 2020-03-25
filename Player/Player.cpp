//
// Created by sjet on 3/24/20.
//

#include <vector>
#include <iostream>
#include "Player.h"
#include "../Events/RandomEvent.cpp"

namespace PLY
{
	class Player
	{
	private:
		string name;
		std::vector<IT::Item> inv;
		int healthMax;
		int healthCur;
		int gold;
		int manaMax;
		int manaCur;
	public:

		Player()
		{

		}

		Player(string name)
		{
			this->name = name;
			healthMax = 10;
			healthCur = healthMax;
			gold = 0;
			manaMax = 5;
			manaCur = manaMax;
		}

		string toString()
		{
			return this->name + "\n Health: " + to_string(healthCur) + "/" + to_string(healthMax) + "\n Mana: " +
				   to_string(manaCur) + "/" + to_string(manaMax) +
				   "\n Gold: " + to_string(gold);
		}

		string purchase(IT::Item i);

		string handleEvent(EVNT::RandomEvent rv)
		{
			std::cout << rv.getText() << std::endl;
			while (!rv.isOver())
			{
				std::cout << rv.getOpt() << std::endl;
				int opt;
				std::cin >> opt;
				if (rv.getType() == 0)
					if (opt == 1)
						std::cout << "" << std::endl;
					else if (opt == 2)
						std::cout << "" << std::endl;
					else if (opt == 3)
					{
						std::cout << "" << std::endl;
						break;
					} else
						std::cout << "Plagued by indecision, you freeze" << std::endl;
				else if (rv.getType() == 1)
					if (opt == 1)
					{
						std::cout << "You approach the Chest, And open it." << std::endl;
					} else
					{
						std::cout << "You pay the chest no mind and continue though Misty Hollow..." << std::endl;
						break;
					}

			}
		}

		int attack()// Eventually I should make a real combat system
		{
			return 5;
		}

		int splattack()
		{
			manaCur--;

			return attack() + (attack() * 0.5);
		}

		void dmg(int i)
		{
			healthCur -= i;
		}

		void rest()
		{
			manaCur = manaMax;
			healthCur = healthMax;
		}

		bool isDead()
		{
			if (healthCur > 0)
				return false;
			return true;
		}

	};
}