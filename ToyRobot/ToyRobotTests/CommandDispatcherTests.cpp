#include "pch.h"
#include "CppUnitTest.h"
#include "../ToyRobot/CommandDispatcher.h"

using namespace ToyRobot;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ToyRobotTests
{
	TEST_CLASS(CommandDispatcherTests)
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

		TEST_METHOD(TestPlaceValid)
		{
			Robot robot;
			Board board(5, 5, robot);
			CommandDispatcher dispatcher(board);

			Robot result = dispatcher.ExecuteCommand("PLACE 2,3,SOUTH");

			Assert::AreEqual(2, result.GetXCoord());
			Assert::AreEqual(3, result.GetYCoord());
			Assert::AreEqual(ToString(Direction::South), ToString(result.GetDirection()));
		}

		TEST_METHOD(TestPlaceOutOfBounds)
		{
			Robot robot;
			Board board(5, 5, robot);
			CommandDispatcher dispatcher(board);

			Robot result = dispatcher.ExecuteCommand("PLACE 5,3,SOUTH");

			Assert::AreEqual(0, result.GetXCoord());
			Assert::AreEqual(0, result.GetYCoord());
			Assert::AreEqual(ToString(Direction::Undefined), ToString(result.GetDirection()));
		}

		TEST_METHOD(TestLeftValid)
		{
			Robot robot(3, 4, Direction::East);
			Board board(5, 5, robot);
			CommandDispatcher dispatcher(board);

			Robot result = dispatcher.ExecuteCommand("LEFT");

			Assert::AreEqual(ToString(Direction::North), ToString(result.GetDirection()));
		}

		TEST_METHOD(TestLeftNoRobot)
		{
			Robot robot;
			Board board(5, 5, robot);
			CommandDispatcher dispatcher(board);

			Robot result = dispatcher.ExecuteCommand("LEFT");

			Assert::AreEqual(ToString(Direction::Undefined), ToString(result.GetDirection()));
		}

		TEST_METHOD(TestRightValid)
		{
			Robot robot(3, 4, Direction::East);
			Board board(5, 5, robot);
			CommandDispatcher dispatcher(board);

			Robot result = dispatcher.ExecuteCommand("RIGHT");

			Assert::AreEqual(ToString(Direction::South), ToString(result.GetDirection()));
		}

		TEST_METHOD(TestRightNoRobot)
		{
			Robot robot;
			Board board(5, 5, robot);
			CommandDispatcher dispatcher(board);

			Robot result = dispatcher.ExecuteCommand("RIGHT");

			Assert::AreEqual(ToString(Direction::Undefined), ToString(result.GetDirection()));
		}

		TEST_METHOD(TestMoveOutOfBounds) {
			Robot robot(3, 4, Direction::North);
			Board board(5, 5, robot);
			CommandDispatcher dispatcher(board);

			Robot result = dispatcher.ExecuteCommand("MOVE");

			Assert::AreEqual(3, result.GetXCoord());
			Assert::AreEqual(4, result.GetYCoord());
			Assert::AreEqual(ToString(Direction::North), ToString(result.GetDirection()));
		}

		TEST_METHOD(TestMoveNoRobot) {
			Robot robot;
			Board board(5, 5, robot);
			CommandDispatcher dispatcher(board);

			Robot result = dispatcher.ExecuteCommand("MOVE");

			Assert::AreEqual(0, result.GetXCoord());
			Assert::AreEqual(0, result.GetYCoord());
			Assert::AreEqual(ToString(Direction::Undefined), ToString(result.GetDirection()));
		}

		TEST_METHOD(TestUnknownCommand) {
			Robot robot(3, 4, Direction::North);
			Board board(5, 5, robot);
			CommandDispatcher dispatcher(board);

			Robot result = dispatcher.ExecuteCommand("SOMECMD");

			Assert::AreEqual(3, result.GetXCoord());
			Assert::AreEqual(4, result.GetYCoord());
			Assert::AreEqual(ToString(Direction::North), ToString(result.GetDirection()));
		}

		TEST_METHOD(TestReport) {
			Robot robot(3, 4, Direction::North);
			Board board(5, 5, robot);
			CommandDispatcher dispatcher(board);

			Robot result = dispatcher.ExecuteCommand("REPORT");

			Assert::AreEqual(3, result.GetXCoord());
			Assert::AreEqual(4, result.GetYCoord());
			Assert::AreEqual(ToString(Direction::North), ToString(result.GetDirection()));
		}
	};
}