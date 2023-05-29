#ifndef COMMAND_DISPATCHER_H
#define COMMAND_DISPATCHER_H

#include <string>
#include "Robot.h"
#include "Board.h"

using namespace std;

namespace ToyRobot {
	class CommandDispatcher
	{
		Board gameboard;
	public:
		CommandDispatcher(Board& board);
		Robot ExecuteCommand(string command);
	};
}

#endif COMMAND_DISPATCHER_H