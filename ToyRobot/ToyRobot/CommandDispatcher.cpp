#include "CommandDispatcher.h"
#include "CommandParser.h"
#include <iostream>

using namespace std;

namespace ToyRobot {
    CommandDispatcher::CommandDispatcher(Board board)
    {
        gameboard = board;
    }

    Robot CommandDispatcher::ExecuteCommand(string command)
    {
        Robot robot;
        CommandParser cmdparser(command);
        string maincmd = cmdparser.GetMainCommand();

        if (maincmd == "PLACE") {
            int x = cmdparser.GetXCoordinate();
            int y = cmdparser.GetYCoordinate();
            Direction dir = cmdparser.GetDirection();

            robot = gameboard.GetRobot();

            int maxx = gameboard.GetXSize();
            int maxy = gameboard.GetYSize();
            robot.SetLocation(x, y, dir, maxx, maxy);
        }
        else {
            cout << "Command ignored!\n";
        }

        return robot;
    }

}
