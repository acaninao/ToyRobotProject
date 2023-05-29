#ifndef ROBOT_H
#define ROBOT_H

#include "Direction.h"

namespace ToyRobot {
	class Robot
	{
		int xcoord;
		int ycoord;
		Direction direction;

	public:
		Robot();
		Robot(int x, int y, Direction dir);
		int GetXCoord();
		int GetYCoord();
		Direction GetDirection();
		void SetLocation(int x, int y, Direction dir, int maxxcoord, int maxycoord);
	};
}

#endif ROBOT_H

