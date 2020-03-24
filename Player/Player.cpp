//
// Created by sjet on 3/24/20.
//

#include <vector>
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

		string handleEvent(EVNT::RandomEvent rv);

		int attack();

		int splattack();

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
			if(healthCur > 0)
				return true;
			return false;
		}

	};
}