#ifndef COMMAND_DISPATCHER_H
#define COMMAND_DISPATCHER_H

#include <string>
#include "Robot.h"

namespace ToyRobot {
	class CommandDispatcher
	{
	public:
		Robot ExecuteCommand(std::string command, Robot robot);
	};
}

#endif COMMAND_DISPATCHER_H