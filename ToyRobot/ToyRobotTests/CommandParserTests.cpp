#include "pch.h"
#include "CppUnitTest.h"
#include "../ToyRobot/CommandParser.h"

using namespace ToyRobot;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ToyRobotTests
{
	TEST_CLASS(CommandParserTests)
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

		TEST_METHOD(TestParsePlaceValid)
		{
			string expectedmaincmd = "PLACE";
			CommandParser parser("PLACE 2,3,NORTH");

			Assert::AreEqual(expectedmaincmd, parser.GetMainCommand());
			Assert::AreEqual(2, parser.GetXCoordinate());
			Assert::AreEqual(3, parser.GetYCoordinate());
			Assert::AreEqual(ToString(Direction::North), ToString(parser.GetDirection()));
		}

		TEST_METHOD(TestParsePlaceNoXCoord) {
			string expectedmaincmd = "PLACE";
			CommandParser parser("PLACE ");

			Assert::AreEqual(expectedmaincmd, parser.GetMainCommand());

			try {
				parser.GetXCoordinate();
				Microsoft::VisualStudio::CppUnitTestFramework::Assert::Fail();
			}
			catch (...) {
				// Passes if exception is thrown.
			}
		}

		TEST_METHOD(TestParsePlaceNoYCoord) {
			string expectedmaincmd = "PLACE";
			CommandParser parser("PLACE 2,");

			Assert::AreEqual(expectedmaincmd, parser.GetMainCommand());
			Assert::AreEqual(2, parser.GetXCoordinate());

			try {
				parser.GetYCoordinate();
				Microsoft::VisualStudio::CppUnitTestFramework::Assert::Fail();
			}
			catch (...) {
				// Passes if exception is thrown.
			}
		}

		TEST_METHOD(TestParsePlaceNoDirection) {
			string expectedmaincmd = "PLACE";
			CommandParser parser("PLACE 2,3");

			Assert::AreEqual(expectedmaincmd, parser.GetMainCommand());
			Assert::AreEqual(2, parser.GetXCoordinate());
			Assert::AreEqual(3, parser.GetYCoordinate());

			try {
				parser.GetDirection();
				Microsoft::VisualStudio::CppUnitTestFramework::Assert::Fail();
			}
			catch (...) {
				// Passes if exception is thrown.
			}
		}

		TEST_METHOD(TestParseMoveValid)
		{
			string expectedmaincmd = "MOVE";
			CommandParser parser("MOVE");

			Assert::AreEqual(expectedmaincmd, parser.GetMainCommand());
		}

		TEST_METHOD(TestParseLeftValid)
		{
			string expectedmaincmd = "LEFT";
			CommandParser parser("LEFT");

			Assert::AreEqual(expectedmaincmd, parser.GetMainCommand());
		}

		TEST_METHOD(TestParseRightValid)
		{
			string expectedmaincmd = "RIGHT";
			CommandParser parser("RIGHT");

			Assert::AreEqual(expectedmaincmd, parser.GetMainCommand());
		}

		TEST_METHOD(TestParseReportValid)
		{
			string expectedmaincmd = "REPORT";
			CommandParser parser("REPORT");

			Assert::AreEqual(expectedmaincmd, parser.GetMainCommand());
		}
	};
}