#ifndef ROBOT_H
#define ROBOT_H

#include "Direction.h"
#include <string>

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
		void Move(int maxxcoord, int maxycoord);
		void RotateLeft();
		void RotateRight();
		std::string ReportLocation();
	};
}

#endif ROBOT_H

