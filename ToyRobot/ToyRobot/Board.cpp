#include "Board.h"
#include <iostream>

using namespace std;

namespace ToyRobot {
	Board::Board()
	{
		xsize = 0;
		ysize = 0;
		robot = Robot();
	}

	Board::Board(int xlength, int ylength, Robot toyrobot)
		: xsize(xlength), ysize(ylength), robot(toyrobot) {}

	Robot Board::GetRobot()
	{
		return robot;
	}

	void Board::SetRobot(Robot toyrobot)
	{
		robot = toyrobot;
	}

	int Board::GetXSize()
	{
		return xsize;
	}

	int Board::GetYSize()
	{
		return ysize;
	}

	void Board::DisplayBoard()
	{
		for (int yctr = 0; yctr < ysize; yctr++) {
			cout << ".";
			for (int xctr = 0; xctr < xsize; xctr++) {
				cout << "___.";
			}
			cout << "\n";
			cout << "|";
			for (int xctr = 0; xctr < xsize; xctr++) {
				Direction robotdir = robot.GetDirection();
				int maxycoord = ysize - 1;
				if (robot.GetXCoord() == xctr && maxycoord - robot.GetYCoord() == yctr && robotdir != Undefined)
				{
					cout << " " << Board::GetRobotIcon(robotdir) << " |";
				}
				else {
					cout << "   |";
				}
			}
			cout << "\n";
		}

		cout << ".";
		for (int xctr = 0; xctr < xsize; xctr++) {
			cout << "___.";
		}
		cout << "\n";
	}

	string Board::GetRobotIcon(Direction direction)
	{
		switch (direction) {
		case North:
			return "^";
		case South:
			return "v";
		case East:
			return ">";
		case West:
			return "<";
		}

		return " ";
	}
}