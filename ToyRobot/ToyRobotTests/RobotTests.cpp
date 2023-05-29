#include "pch.h"
#include "CppUnitTest.h"
#include "../ToyRobot/Robot.h"
#include "Helper.h"

using namespace ToyRobot;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ToyRobotTests
{
	TEST_CLASS(RobotTests)
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
			Robot robot;

			Assert::AreEqual(0, robot.GetXCoord());
			Assert::AreEqual(0, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::Undefined), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestGetXCoord) {
			Robot robot(2, 3, Direction::North);

			Assert::AreEqual(2, robot.GetXCoord());
		}

		TEST_METHOD(TestGetYCoord) {
			Robot robot(2, 3, Direction::North);

			Assert::AreEqual(3, robot.GetYCoord());
		}

		TEST_METHOD(TestGetDirection) {
			Robot robot(2, 3, Direction::North);

			Assert::AreEqual(ToString(Direction::North), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestReportLocationNorth) {
			const string expected = "Output: 2,3,NORTH\n";
			Robot robot(2, 3, Direction::North);

			Assert::AreEqual(expected, robot.ReportLocation());
		}

		TEST_METHOD(TestReportLocationSouth) {
			const string expected = "Output: 1,2,SOUTH\n";
			Robot robot(1, 2, Direction::South);

			Assert::AreEqual(expected, robot.ReportLocation());
		}

		TEST_METHOD(TestReportLocationEast) {
			const string expected = "Output: 4,3,EAST\n";
			Robot robot(4, 3, Direction::East);

			Assert::AreEqual(expected, robot.ReportLocation());
		}

		TEST_METHOD(TestReportLocationWest) {
			const string expected = "Output: 6,7,WEST\n";
			Robot robot(6, 7, Direction::West);

			Assert::AreEqual(expected, robot.ReportLocation());
		}

		TEST_METHOD(TestRotateLeft) {
			Robot robot(3, 4, Direction::North);

			robot.RotateLeft();
			Assert::AreEqual(ToString(Direction::West), ToString(robot.GetDirection()));
			robot.RotateLeft();
			Assert::AreEqual(ToString(Direction::South), ToString(robot.GetDirection()));
			robot.RotateLeft();
			Assert::AreEqual(ToString(Direction::East), ToString(robot.GetDirection()));
			robot.RotateLeft();
			Assert::AreEqual(ToString(Direction::North), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestRotateRight) {
			Robot robot(3, 4, Direction::North);

			robot.RotateRight();
			Assert::AreEqual(ToString(Direction::East), ToString(robot.GetDirection()));
			robot.RotateRight();
			Assert::AreEqual(ToString(Direction::South), ToString(robot.GetDirection()));
			robot.RotateRight();
			Assert::AreEqual(ToString(Direction::West), ToString(robot.GetDirection()));
			robot.RotateRight();
			Assert::AreEqual(ToString(Direction::North), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestSetLocationValid) {
			Robot robot;

			robot.SetLocation(4, 5, Direction::North, 7, 7);
			Assert::AreEqual(4, robot.GetXCoord());
			Assert::AreEqual(5, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::North), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestSetLocationXCoordLessThanZero) {
			Robot robot;

			robot.SetLocation(-1, 5, Direction::North, 7, 7);
			Assert::AreEqual(0, robot.GetXCoord());
			Assert::AreEqual(0, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::Undefined), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestSetLocationXCoordExceedsMaxSize) {
			Robot robot;

			robot.SetLocation(7, 5, Direction::North, 7, 7);
			Assert::AreEqual(0, robot.GetXCoord());
			Assert::AreEqual(0, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::Undefined), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestSetLocationYCoordLessThanZero) {
			Robot robot;

			robot.SetLocation(5, -1, Direction::North, 7, 7);
			Assert::AreEqual(0, robot.GetXCoord());
			Assert::AreEqual(0, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::Undefined), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestSetLocationYCoordExceedsMaxSize) {
			Robot robot;

			robot.SetLocation(5, 7, Direction::North, 7, 7);
			Assert::AreEqual(0, robot.GetXCoord());
			Assert::AreEqual(0, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::Undefined), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestSetLocationDirectionInvalid) {
			Robot robot;

			robot.SetLocation(5, 7, Direction::Undefined, 7, 7);
			Assert::AreEqual(0, robot.GetXCoord());
			Assert::AreEqual(0, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::Undefined), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestMoveNorthValid) {
			Robot robot(3, 3, Direction::North);

			robot.Move(5, 5);
			Assert::AreEqual(3, robot.GetXCoord());
			Assert::AreEqual(4, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::North), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestMoveNorthInvalid) {
			Robot robot(2, 4, Direction::North);

			robot.Move(5, 5);
			Assert::AreEqual(2, robot.GetXCoord());
			Assert::AreEqual(4, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::North), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestMoveSouthValid) {
			Robot robot(3, 3, Direction::South);

			robot.Move(5, 5);
			Assert::AreEqual(3, robot.GetXCoord());
			Assert::AreEqual(2, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::South), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestMoveSouthInvalid) {
			Robot robot(2, 0, Direction::South);

			robot.Move(5, 5);
			Assert::AreEqual(2, robot.GetXCoord());
			Assert::AreEqual(0, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::South), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestMoveEastValid) {
			Robot robot(3, 3, Direction::East);

			robot.Move(5, 5);
			Assert::AreEqual(4, robot.GetXCoord());
			Assert::AreEqual(3, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::East), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestMoveEastInvalid) {
			Robot robot(4, 0, Direction::East);

			robot.Move(5, 5);
			Assert::AreEqual(4, robot.GetXCoord());
			Assert::AreEqual(0, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::East), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestMoveWestValid) {
			Robot robot(3, 3, Direction::West);

			robot.Move(5, 5);
			Assert::AreEqual(2, robot.GetXCoord());
			Assert::AreEqual(3, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::West), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestMoveWestInvalid) {
			Robot robot(0, 3, Direction::West);

			robot.Move(5, 5);
			Assert::AreEqual(0, robot.GetXCoord());
			Assert::AreEqual(3, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::West), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestMoveInvalidRobot) {
			Robot robot;

			robot.Move(5, 5);
			Assert::AreEqual(0, robot.GetXCoord());
			Assert::AreEqual(0, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::Undefined), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestRotateLeftInvalidRobot) {
			Robot robot;

			robot.RotateLeft();
			Assert::AreEqual(0, robot.GetXCoord());
			Assert::AreEqual(0, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::Undefined), ToString(robot.GetDirection()));
		}

		TEST_METHOD(TestRotateRightInvalidRobot) {
			Robot robot;

			robot.RotateRight();
			Assert::AreEqual(0, robot.GetXCoord());
			Assert::AreEqual(0, robot.GetYCoord());
			Assert::AreEqual(ToString(Direction::Undefined), ToString(robot.GetDirection()));
		}
	};
}
