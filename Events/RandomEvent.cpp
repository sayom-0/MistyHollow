//
// Created by sjet on 3/24/20.
//

#include <string>
#include "RandomEvent.h"
#include "RawEvent.cpp"

namespace EVNT
{
	class RandomEvent
	{
	private:
		std::string text;
		std::string opt;
		RawEvent iev;
		bool hasEnemy;

	public:
		RandomEvent()
		{

		}
	};
}
