#include "Board.h"
#include <iostream>

namespace ToyRobot {
	Board::Board(int xlength, int ylength, Robot toyrobot)
		: xsize(xlength), ysize(ylength), robot(toyrobot) {}

	void Board::DisplayBoard()
	{
		for (int yctr = 0; yctr < ysize; yctr++) {
			std::cout << ".";
			for (int xctr = 0; xctr < xsize; xctr++) {
				std::cout << "___.";
			}
			std::cout << "\n";
			std::cout << "|";
			for (int xctr = 0; xctr < xsize; xctr++) {
				Direction robotdir = robot.GetDirection();
				int maxycoord = ysize - 1;
				if (robot.GetXCoord() == xctr && maxycoord - robot.GetYCoord() == yctr && robotdir != Undefined)
				{
					std::cout << " " << Board::GetRobotDisplay(robotdir) << " |";
				}
				else {
					std::cout << "   |";
				}
			}
			std::cout << "\n";
		}

		std::cout << ".";
		for (int xctr = 0; xctr < xsize; xctr++) {
			std::cout << "___.";
		}
		std::cout << "\n";
	}

	std::string Board::GetRobotDisplay(Direction direction)
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