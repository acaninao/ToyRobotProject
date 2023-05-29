#include "Robot.h"
#include "Direction.h"

namespace ToyRobot {
	Robot::Robot() {
		xcoord = 0;
		ycoord = 0;
		direction = Undefined;
	}

	Robot::Robot(int x, int y, Direction dir)
	{
		xcoord = x;
		ycoord = y;
		direction = dir;
	}

	int Robot::GetXCoord()
	{
		return xcoord;
	}

	int Robot::GetYCoord()
	{
		return ycoord;
	}

	Direction Robot::GetDirection()
	{
		return direction;
	}
}
