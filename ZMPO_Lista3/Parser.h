#pragma once
#include <string>
#include "CMenuItem.h"
#include "CMenuCommand.h"
#include "CMenu.h"

class Parser
{
public:
	Parser(string *file, int currentPosition, string *returnMessage);
	~Parser();
	int parseMenu(CMenu *menuToParse);

private:
	string *file;
	int currentPosition;
	string *returnMessage;

	int parseCommand(CMenuCommand *commandToParse);
	string createReturnMessage(const char expectedString);
	bool parseDelimiter(const char delimiter);
	bool parseText(string &textToSet);
};

