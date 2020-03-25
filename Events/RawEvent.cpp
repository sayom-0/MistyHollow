//
// Created by sjet on 3/25/20.
//

#include <string>
#include <vector>
#include "RawEvent.h"

namespace REVNT
{// Types | 0: Enemy 1: Object Intractable 2: Custom
	class RawEvent
	{
	private:
		std::vector<std::vector<std::string>> ttv;
		std::string text;
		int type;
	public:
		RawEvent()
		{
			//Init of the Object
			for (int i = 0; i != 3; i++)
				ttv.push_back(std::vector<std::string>());

			ttv[0].push_back("");
			ttv[1].push_back("");
			ttv[2].push_back("");

			//Actual event generation
			type = rand() % 3;

		}
	};
}
