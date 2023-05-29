#ifndef BOARD_H
#define BOARD_H

#include "Robot.h"
#include <string>

namespace ToyRobot {
	class Board
	{
		int xsize;
		int ysize;
		Robot robot;

	public:
		Board(int xlength, int ylength, Robot toyrobot);

		void DisplayBoard();
		std::string GetRobotDisplay(Direction direction);
	};
}

#endif BOARD_H

