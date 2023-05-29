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
	};
}
