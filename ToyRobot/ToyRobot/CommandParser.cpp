#include "CommandParser.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

namespace ToyRobot {

	CommandParser::CommandParser(string inputcmd)
	{
		string token;
		stringstream stream(inputcmd);

		tokens.clear();

		while (stream >> token) {
			tokens.push_back(token);
		}

		command = inputcmd;
	}

	string CommandParser::GetMainCommand()
	{
		string delimiter = " ";
		CommandParser cmdparser(command);
		return command.substr(0, command.find(delimiter));
	}

	int CommandParser::GetXCoordinate()
	{
		string delimiter = ",";
		size_t maxlength = tokens[1].length() + 1;
		char* nexttoken = NULL;

		char* convertedstring = (char *)malloc(maxlength);
		if (convertedstring == NULL) {
			return -1;
		}
		strcpy_s(convertedstring, maxlength, tokens[1].c_str());
		char* token = strtok_s(convertedstring, ",", &nexttoken);
		int x = atoi(token);

		free(convertedstring);

		return x;
	}

	int CommandParser::GetYCoordinate()
	{
		string delimiter = ",";
		size_t maxlength = tokens[1].length() + 1;
		char* nexttoken = NULL;

		char* convertedstring = (char*)malloc(maxlength);
		if (convertedstring == NULL) {
			return -1;
		}
		strcpy_s(convertedstring, maxlength, tokens[1].c_str());
		char* token = strtok_s(convertedstring, ",", &nexttoken);
		token = strtok_s(NULL, ",", &nexttoken);

		int y = atoi(token);

		free(convertedstring);

		return y;
	}

	Direction CommandParser::GetDirection()
	{
		string delimiter = ",";
		size_t maxlength = tokens[1].length() + 1;
		char* nexttoken = NULL;

		char* convertedstring = (char*)malloc(maxlength);
		if (convertedstring == NULL) {
			return Undefined;
		}
		strcpy_s(convertedstring, maxlength, tokens[1].c_str());
		char* token = strtok_s(convertedstring, ",", &nexttoken);
		token = strtok_s(NULL, ",", &nexttoken);
		token = strtok_s(NULL, ",", &nexttoken);

		if (strcmp(token, "NORTH") == 0) {
			return North;
		}
		if (strcmp(token, "SOUTH") == 0) {
			return South;
		}
		if (strcmp(token, "EAST") == 0) {
			return East;
		}
		if (strcmp(token, "WEST") == 0) {
			return West;
		}

		return Undefined;
	}
}
