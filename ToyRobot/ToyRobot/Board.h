#ifndef BOARD_H
#define BOARD_H

#include "Robot.h"
#include <string>

using namespace std;

namespace ToyRobot {
	class Board
	{
		int xsize;
		int ysize;
		Robot robot;

	public:
		Board();
		Board(int xlength, int ylength, Robot& toyrobot);

		Robot GetRobot();
		void SetRobot(Robot toyrobot);

		int GetXSize();
		int GetYSize();

		void DisplayBoard();
		string GetRobotIcon(Direction direction);
	};
}

#endif BOARD_H

