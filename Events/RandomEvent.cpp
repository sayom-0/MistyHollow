//
// Created by sjet on 3/24/20.
//

#include <string>
#include "RandomEvent.h"
#include "../Events/RawEvent.cpp"

namespace EVNT
{
	class RandomEvent
	{
	private:
		REVNT::RawEvent iev;
	public:
		RandomEvent()
		{
			iev = REVNT::RawEvent();
		}

		std::string getText()
		{
			return iev.getText();
		}

		std::string getOpt()
		{
			if (iev.getType() == 0)
				return "1 - Attack \n 2 - Special Attack \n 3 - Run";
			if (iev.getType() == 1)
				return "1 - Open the chest \n 2 - Ignore it";
		}

		int getType()
		{
			return iev.getType();
		}

		bool isOver()
		{
			return iev.isOver();
		}
	};
}
