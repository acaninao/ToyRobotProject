#ifndef HELPER_H
#define HELPER_H

#include <string>
#include "../ToyRobot/Direction.h"

using namespace ToyRobot;
using namespace std;

namespace ToyRobotTests {
	class Helper
	{
	public:
		wstring ToString(Direction value);
	};
}

#endif HELPER_H