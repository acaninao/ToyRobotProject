#include <iostream>
#include "Board.h"
#include <string>
#include "CommandDispatcher.h"

using namespace ToyRobot;
using namespace std;

int main() {
	int xsize = 5;
	int ysize = 5;
	string command;

	cout << "Welcome to the Toy Robot Project\n";
	/*
	cout << "Enter the size of the board:\n";
	cout << "x-axis: ";
	cin >> xsize;
	cout << "y-axis: ";
	cin >> ysize;
	cin.ignore();
	*/

	Robot robot;
	Robot currentrobot;
	Board board(xsize, ysize, robot);

	while (1) {
		board.DisplayBoard();

		cout << "Enter command: " << endl;
		getline(cin, command);
		if (command == "quit") {
			break;
		}

		CommandDispatcher dispatcher(board);
		currentrobot = dispatcher.ExecuteCommand(command);
		board.SetRobot(currentrobot);
	}

	return 0;
}