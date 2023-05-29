#include "Robot.h"
#include "Direction.h"
#include <string>
#include <iostream>

using namespace std;

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

	void Robot::SetLocation(int x, int y, Direction dir, int maxxcoord, int maxycoord)
	{
		if (x < 0 || x >= maxxcoord) {
			cout << "Invalid x coordinate!\n";
			return;
		}

		if (y < 0 || y >= maxycoord) {
			cout << "Invalid y coordinate!\n";
			return;
		}

		if (dir == Undefined) {
			cout << "Invalid direction!\n";
			return;
		}

		xcoord = x;
		ycoord = y;
		direction = dir;
	}
}
