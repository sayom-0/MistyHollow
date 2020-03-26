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
		std::string name;
		std::vector<IT::Item> inv;
		int healthMax;
		int healthCur;
		int gold;
		int manaMax;
		int manaCur;
		int xp;
	public:

		Player()
		{

		}

		Player(std::string name)
		{
			this->name = name;
			healthMax = 20;
			healthCur = healthMax;
			gold = 0;
			manaMax = 5;
			manaCur = manaMax;
		}

		std::string toString()
		{
			return this->name + "\n Health: " + std::to_string(healthCur) + "/" + std::to_string(healthMax) +
				   "\n Mana: " +
				   std::to_string(manaCur) + "/" + std::to_string(manaMax) +
				   "\n Gold: " + std::to_string(gold);
		}

		std::string purchase(IT::Item i);

		void handleEvent(EVNT::RandomEvent &rv)
		{
			std::cout << rv.getText() << std::endl;
			while (!rv.isOver())
			{
				std::cout << toString() << std::endl << std::endl;
				std::cout << rv.getOpt() << std::endl;
				int opt;
				std::cin >> opt;
				if (rv.getType() == 0)
					if (opt == 1)
					{
						std::cout << "You attack the enemy for " + std::to_string(attack()) + " damage." << std::endl;
						rv.getEnemy().hit(attack());
						enemyDeath(rv);
					} else if (opt == 2)
					{
						int dv = splattack();
						std::cout << "You smite the enemy for " + std::to_string(dv) + " damage." << std::endl;
						rv.getEnemy().hit(dv);
						enemyDeath(rv);
					} else if (opt == 3)
					{
						std::cout << "You run in the opposite direction as fast as you can." << std::endl;
						break;
					} else
						std::cout << "Plagued by indecision, you freeze." << std::endl;
				else if (rv.getType() == 1)
					if (opt == 1)
					{
						std::cout << "You approach the Chest, And open it." << std::endl;
						if (rv.isDgr())
						{
							healthCur -= rv.open();
							std::cout << "The chest explodes dealing " + std::to_string(rv.open()) + " damage."
									  << std::endl;
						} else
						{
							gold += rv.open();
							std::cout << "You find " + std::to_string(rv.open()) + " gold in the chest." << std::endl;
						}
						break;
					} else
					{
						std::cout << "You pay the chest no mind and continue though Misty Hollow..." << std::endl;
						break;
					}
			}
		}

		void enemyDeath(EVNT::RandomEvent &rv)
		{
			if (rv.getEnemy().isDead())
			{
				rv.over();
				std::cout << "You have slain the foe! Shall you claim your reward?\n 1 - Loot\n2 - Leave" << std::endl;
				int i;
				std::cin >> i;

				if (i == 1)
				{
					if (rv.getEnemy().isSafe())
					{
						gold += rv.getEnemy().loot();
						std::cout << "You find " + std::to_string(rv.getEnemy().loot()) + " gold on the corpse."
								  << std::endl;
					} else
					{
						healthCur -= rv.getEnemy().loot();
						std::cout << "The corpse explodes for " + std::to_string(rv.getEnemy().loot()) + " damage!"
								  << std::endl;
					}
				}
			} else
			{
				std::cout << "The enemy strikes you for " + std::to_string(rv.getEnemy().attack()) + " damage!"
						  << std::endl;
				healthCur -= rv.getEnemy().attack();
				if (isDead())
					rv.over();
			}
		}

		int attack()// Eventually I should make a real combat system
		{
			return 5;
		}

		int splattack()
		{
			if (manaCur > 0)
			{
				manaCur--;

				return attack() + (attack() * 0.5);
			}
			return 0;
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