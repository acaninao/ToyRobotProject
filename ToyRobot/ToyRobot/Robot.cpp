#include "Robot.h"
#include "Direction.h"
#include <string>
#include <iostream>

using namespace ToyRobot;
using namespace std;

namespace ToyRobot {
	Robot::Robot() {
		xcoord = 0;
		ycoord = 0;
		direction = Direction::Undefined;
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

		if (dir == Direction::Undefined) {
			cout << "Invalid direction!\n";
			return;
		}

		xcoord = x;
		ycoord = y;
		direction = dir;
	}

	void Robot::Move(int maxxcoord, int maxycoord)
	{
		if (direction == Direction::North) {
			if (ycoord+1 < maxycoord) {
				ycoord++;
			}
			else {
				cout << "Cannot move up!\n";
			}

		} else if (direction == Direction::South) {
			if (ycoord > 0) {
				ycoord--;
			}
			else {
				cout << "Cannot move down!\n";
			}
		} else if (direction == Direction::East) {
			if (xcoord+1 < maxxcoord) {
				xcoord++;
			}
			else {
				cout << "Cannot move right!\n";
			}
		} else if (direction == Direction::West) {
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
		if (direction == Direction::North) {
			direction = Direction::West;
		}
		else if (direction == Direction::West) {
			direction = Direction::South;
		}
		else if (direction == Direction::South) {
			direction = Direction::East;
		}
		else if (direction == Direction::East) {
			direction = Direction::North;
		}
	}

	void Robot::RotateRight()
	{
		if (direction == Direction::North) {
			direction = Direction::East;
		}
		else if (direction == Direction::East) {
			direction = Direction::South;
		}
		else if (direction == Direction::South) {
			direction = Direction::West;
		}
		else if (direction == Direction::West) {
			direction = Direction::North;
		}
	}

	void Robot::ReportLocation()
	{
		string dirtext;

		if (direction == Direction::North) {
			dirtext = "NORTH";
		} else if (direction == Direction::South) {
			dirtext = "SOUTH";
		} else if (direction == Direction::West) {
			dirtext = "WEST";
		} else if (direction == Direction::East) {
			dirtext = "EAST";
		} else {
			dirtext = "Undefined";
		}

		cout << "Output: " << xcoord << "," << ycoord << "," << dirtext << endl;
	}
}
