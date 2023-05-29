#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <string>
#include <vector>
#include "Direction.h"

using namespace std;

namespace ToyRobot {
	class CommandParser
	{
		string command;
		vector<string> tokens;

	public:
		CommandParser(string inputcmd);
		string GetMainCommand();
		int GetXCoordinate();
		int GetYCoordinate();
		Direction GetDirection();
	};
}

#endif COMMAND_PARSER_H

