//
// Created by sjet on 3/24/20.
//

#include "Player.h"

Player::Player()
{}

Player::Player(std::string
			   name)
{
	this->
			name = name;
	healthMax = 20;
	healthCur = healthMax;
	gold = 0;
	manaMax = 5;
	manaCur = manaMax;
}

std::string Player::toString()
{
	return this->name + "\n Health: " + std::to_string(healthCur) + "/" + std::to_string(healthMax) +
		   "\n Mana: " +
		   std::to_string(manaCur) + "/" + std::to_string(manaMax) +
		   "\n Gold: " + std::to_string(gold);
}

std::string Player::purchase(Item i)
{}

void Player::handleEvent(RandomEvent rv)
{
	if (system("CLS")) system("clear");
	std::cout << rv.getText() << std::endl;
	while (!rv.isOver())
	{
		std::cout << toString() << std::endl << std::endl;
		std::cout << rv.getOpt() << std::endl;
		initscr();
		noecho();
		cbreak();
		char opt = getch();
		endwin();
		if (rv.getType() == 0)
		{
			if (opt == '1')
			{
				std::cout << "You attack the enemy for " + std::to_string(attack()) + " damage." << std::endl;
				hold();
				rv.getEnemy().hit(attack());
				enemyDeath(rv);
				hold();
			} else if (opt == '2')
			{
				int dv = splattack();
				std::cout << "You smite the enemy for " + std::to_string(dv) + " damage." << std::endl;
				hold();
				rv.getEnemy().hit(dv);
				enemyDeath(rv);
				hold();
			} else if (opt == '3')
			{
				std::cout << "You run in the opposite direction as fast as you can." << std::endl;
				break;
			} else
			{
				std::cout << "Plagued by indecision, you freeze." << std::endl;
				hold();
			}
		} else if (rv.getType() == 1)
		{
			if (opt == '1')
			{
				std::cout << "You approach the Chest, And open it." << std::endl;
				if (rv.isDgr())
				{
					healthCur -= rv.open();
					std::cout << "The chest explodes dealing " + std::to_string(rv.open()) + " damage."
							  << std::endl;
					hold();
				} else
				{
					gold += rv.open();
					std::cout << "You find " + std::to_string(rv.open()) + " gold in the chest." << std::endl;
					hold();
				}
				break;
			} else
			{
				std::cout << "You pay the chest no mind and continue though Misty Hollow..." << std::endl;
				hold();
				break;
			}
		} else if (rv.getType() == 2)
		{

			if (opt == '1')
			{
				for (int i = 0; i != 1;)
				{
					if (system("CLS")) system("clear");
					std::cout << toString() << std::endl << std::endl;
					if (rv.getTown().getRest())
						std::cout << "1 - Enter Inn" << std::endl;
					if (rv.getTown().getShop())
						std::cout << "2 - Enter Shop" << std::endl;
					if (rv.getTown().getQuest())
						std::cout << "3 - Check Quest Board" << std::endl;
					std::cout << "4 - Exit Town" << std::endl;

					initscr();
					noecho();
					cbreak();
					switch (getch())
					{
						case '1':
							endwin();

							break;

						case '2':
							endwin();

							break;

						case '3':
							endwin();

							break;

						case '4':
							endwin();
							std::cout << "You gather your things and set out into the unknown..." << std::endl;
							hold();
							i = 1;
							break;

					}
				}
				break;

			} else if (opt == '2')
			{
				std::cout << "You ignore the town and continue through the hollow mist..." << std::endl;
				hold();
				break;
			}
		}
	}
	if (system("CLS")) system("clear");
}

void Player::enemyDeath(RandomEvent &rv)
{
	if (rv.getEnemy().isDead())
	{
		rv.over();
		std::cout << "You have slain the foe! Shall you claim your reward?\n 1 - Loot\n 2 - Leave" << std::endl;
		initscr();
		noecho();
		cbreak();
		char i = getch();
		endwin();
		if (i == '1')
		{
			if (rv.getEnemy().isSafe())
			{
				gold += rv.getEnemy().loot();
				std::cout << "You find " + std::to_string(rv.getEnemy().loot()) + " gold on the corpse."
						  << std::endl;
				hold();
				if (system("CLS")) system("clear");
			} else
			{
				healthCur -= rv.getEnemy().loot();
				std::cout << "The corpse explodes for " + std::to_string(rv.getEnemy().loot()) + " damage!"
						  << std::endl;
				hold();
				if (system("CLS")) system("clear");
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

int Player::attack()// Eventually I should make a real combat system
{
	return 5;
}

int Player::splattack()
{
	if (manaCur > 0)
	{
		manaCur--;

		return attack() + (attack() * 0.5);
	}
	return 0;
}

void Player::dmg(int i)
{
	healthCur -= i;
}

void Player::rest()
{
	manaCur = manaMax;
	healthCur = healthMax;
}

bool Player::isDead()
{
	if (healthCur > 0)
		return false;
	return true;
}
