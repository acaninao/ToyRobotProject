#include "pch.h"
#include "CppUnitTest.h"
#include "../ToyRobot/Board.h"
#include "Helper.h"

using namespace ToyRobot;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ToyRobotTests
{
	TEST_CLASS(BoardTests)
	{
		std::wstring ToString(Direction value)
		{
			switch (value) {
			case Direction::North: return L"NORTH";
			case Direction::South: return L"SOUTH";
			case Direction::East: return L"EAST";
			case Direction::West: return L"WEST";
			default: return L"Undefined";
			}

			return std::to_wstring(static_cast<int>(value));
		}

	public:

		TEST_METHOD(TestBoardNullInit)
		{
			Board board;

			Assert::AreEqual(0, board.GetXSize());
			Assert::AreEqual(0, board.GetYSize());

			Robot result = board.GetRobot();
			Assert::AreEqual(0, result.GetXCoord());
			Assert::AreEqual(0, result.GetYCoord());
			Assert::AreEqual(ToString(Direction::Undefined), ToString(result.GetDirection()));
		}
		
		TEST_METHOD(TestGetBoardXSize)
		{
			int xsize = 5;
			int ysize = 6;
			Robot robot;

			Board board(xsize, ysize, robot);
			
			Assert::AreEqual(xsize, board.GetXSize());
		}

		TEST_METHOD(TestGetBoardYSize)
		{
			int xsize = 5;
			int ysize = 6;
			Robot robot;

			Board board(xsize, ysize, robot);

			Assert::AreEqual(ysize, board.GetYSize());
		}

		TEST_METHOD(TestGetRobot)
		{
			Robot robot(2, 3, Direction::North);
			Board board(5, 6, robot);

			Robot result = board.GetRobot();

			Assert::AreEqual(2, result.GetXCoord());
			Assert::AreEqual(3, result.GetYCoord());
			Assert::AreEqual(ToString(Direction::North), ToString(result.GetDirection()));
		}

		TEST_METHOD(TestSetRobot)
		{
			Robot robot;
			Board board(5, 6, robot);
			Robot newrobot(4, 1, Direction::South);

			board.SetRobot(newrobot);
			Robot result = board.GetRobot();

			Assert::AreEqual(4, result.GetXCoord());
			Assert::AreEqual(1, result.GetYCoord());
			Assert::AreEqual(ToString(Direction::South), ToString(result.GetDirection()));
		}

		TEST_METHOD(TestGetRobotIconNorth)
		{
			Board board;
			string expected = "^";

			string result = board.GetRobotIcon(Direction::North);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestGetRobotIconSouth)
		{
			Board board;
			string expected = "v";

			string result = board.GetRobotIcon(Direction::South);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestGetRobotIconEast)
		{
			Board board;
			string expected = ">";

			string result = board.GetRobotIcon(Direction::East);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestGetRobotIconWest)
		{
			Board board;
			string expected = "<";

			string result = board.GetRobotIcon(Direction::West);

			Assert::AreEqual(expected, result);
		}
	};
}
