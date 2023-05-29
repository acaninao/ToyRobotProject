#include <iostream>
#include "Board.h"
#include <string>

using namespace ToyRobot;

int main() {
	int xsize;
	int ysize;
	std::string command;

	std::cout << "Welcome to the Toy Robot Project\n";
	std::cout << "Enter the size of the board:\n";
	std::cout << "x-axis: ";
	std::cin >> xsize;
	std::cout << "y-axis: ";
	std::cin >> ysize;

	Robot robot;
	Board board(xsize, ysize, robot);

	while (1) {
		board.DisplayBoard();
		std::cout << "Enter command: ";
		std::cin >> command;
	}

	return 0;
}