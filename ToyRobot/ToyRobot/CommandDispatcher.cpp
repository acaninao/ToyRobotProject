#include "CommandDispatcher.h"
#include "CommandParser.h"
#include <iostream>

using namespace std;

namespace ToyRobot {
    CommandDispatcher::CommandDispatcher(Board& board)
    {
        gameboard = board;
    }

    Robot CommandDispatcher::ExecuteCommand(string command)
    {
        Robot robot = gameboard.GetRobot();
        int maxx = gameboard.GetXSize();
        int maxy = gameboard.GetYSize();

        CommandParser cmdparser(command);
        string maincmd = cmdparser.GetMainCommand();

        if (maincmd == "PLACE")
        {
            int x = cmdparser.GetXCoordinate();
            int y = cmdparser.GetYCoordinate();
            Direction dir = cmdparser.GetDirection();

            robot.SetLocation(x, y, dir, maxx, maxy);
        }
        else if (maincmd == "MOVE")
        {
            robot.Move(maxx, maxy);
        }
        else if (maincmd == "LEFT") {
            robot.RotateLeft();
        }
        else if (maincmd == "RIGHT") {
            robot.RotateRight();
        }
        else if (maincmd == "REPORT") {
            string message = robot.ReportLocation();
            cout << message;
        }
        else {
            cout << "Command ignored!\n";
        }

        return robot;
    }
}
