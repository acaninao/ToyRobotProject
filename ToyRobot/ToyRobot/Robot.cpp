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

	void Robot::Move(int maxxcoord, int maxycoord)
	{
		if (direction == North) {
			if (ycoord+1 < maxycoord) {
				ycoord++;
			}
			else {
				cout << "Cannot move up!\n";
			}

		} else if (direction == South) {
			if (ycoord > 0) {
				ycoord--;
			}
			else {
				cout << "Cannot move down!\n";
			}
		} else if (direction == East) {
			if (xcoord+1 < maxxcoord) {
				xcoord++;
			}
			else {
				cout << "Cannot move right!\n";
			}
		} else if (direction == West) {
			if (xcoord > 0) {
				xcoord--;
			}
			else {
				cout << "Cannot move left!\n";
			}
		}
	}

	void Robot::RotateLeft()
	{
		if (direction == North) {
			direction = West;
		}
		else if (direction == West) {
			direction = South;
		}
		else if (direction == South) {
			direction = East;
		}
		else if (direction = East) {
			direction = North;
		}
	}

	void Robot::RotateRight()
	{
		if (direction == North) {
			direction = East;
		}
		else if (direction == East) {
			direction = South;
		}
		else if (direction == South) {
			direction = West;
		}
		else if (direction = West) {
			direction = North;
		}
	}

	void Robot::ReportLocation()
	{
		string dirtext;

		switch (direction) {
		case North:
			dirtext = "NORTH";
			break;
		case South:
			dirtext = "SOUTH";
			break;
		case West:
			dirtext = "WEST";
			break;
		case East:
			dirtext = "EAST";
			break;
		default:
			dirtext = "Undefined";
			break;
		}

		cout << "Output: " << xcoord << "," << ycoord << "," << dirtext << endl;
	}
}
