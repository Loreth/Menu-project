#include "pch.h"
#include "Parser.h"

Parser::Parser(string *file, int currentPosition, string *returnMessage)
{
	this->file = file;
	this->currentPosition = currentPosition;
	this->returnMessage = returnMessage;
}

Parser::~Parser()
{
}


int Parser::parseMenu(CMenu *menuToParse)
{
	string name;
	string command;

	if (parseDelimiter(MENU_OPENER)
		&& parseText(name)
		&& parseDelimiter(TEXT_SEPARATOR)
		&& parseText(command)
		&& parseDelimiter(CHILD_SEPARATOR)
		)
	{
		menuToParse->setName(name);
		menuToParse->setCommand(command);

		bool childrenFinished = false;

		while (!childrenFinished)
		{
			if ((*file)[currentPosition] == MENU_CLOSER)
			{
				currentPosition++;
				childrenFinished = true;
			}
			else if ((*file)[currentPosition - 1] != CHILD_SEPARATOR && !parseDelimiter(TEXT_SEPARATOR))
			{
				childrenFinished = true;
			}
			else if ((*file)[currentPosition] == MENU_OPENER)
			{
				CMenu *submenu = new CMenu();
				menuToParse->getItems()->push_back(submenu);
				submenu->setRoot(menuToParse);
				currentPosition = parseMenu(submenu);
			}
			else if ((*file)[currentPosition] == COMMAND_OPENER)
			{
				CMenuCommand *menuCommand = new CMenuCommand();
				menuToParse->getItems()->push_back(menuCommand);
				currentPosition = parseCommand(menuCommand);
			}
			//Ponowne sprawdzenie MENU_CLOSER ze wzgledu na !parseDelimiter(TEXT_SEPARATOR) we wczesniejszym warunku inkrementujacy currentPosition.
			//Konieczne, bo na poczatku petli trzeba sprawdzic czy nie nastapil koniec menu, ale nie mozna tego oczekiwac, gdyz moga wystapic inne przypaki
			else if (parseDelimiter(MENU_CLOSER))
			{
				childrenFinished = true;
			}

			if (*returnMessage != MENU_READ_SUCCESS)
			{
				childrenFinished = true;
			}
		}
	}

	return currentPosition;
}

int Parser::parseCommand(CMenuCommand *commandToParse)
{
	string name;
	string command;
	string description;

	if (parseDelimiter(COMMAND_OPENER)
		&& parseText(name)
		&& parseDelimiter(TEXT_SEPARATOR)
		&& parseText(command)
		&& parseDelimiter(TEXT_SEPARATOR)
		&& parseText(description)
		&& parseDelimiter(COMMAND_CLOSER)
		)
	{
		commandToParse->setName(name);
		commandToParse->setCommand(command);
		commandToParse->setDescription(description);
	}

	return currentPosition;
}

string Parser::createReturnMessage(const char expectedString)
{
	return FAILURE_AT_POSITION + to_string(currentPosition) + FAILURE_EXPECTED + expectedString;
}

bool Parser::parseDelimiter(const char delimiter)
{
	if ((*file)[currentPosition] != delimiter)
	{
		*returnMessage = createReturnMessage(delimiter);
		return false;
	}
	else
	{
		currentPosition++;
		return true;
	}
}

bool Parser::parseText(string &textToSet)
{
	if (parseDelimiter(TEXT_INDICATOR))
	{
		int closingTextIndicatorPos = file->find_first_of(TEXT_INDICATOR, currentPosition);
		if (closingTextIndicatorPos == string::npos)
		{
			currentPosition = file->size();
			*returnMessage = createReturnMessage(TEXT_INDICATOR);
			return false;
		}
		else
		{
			textToSet = file->substr(currentPosition, closingTextIndicatorPos - currentPosition);
			currentPosition = closingTextIndicatorPos + 1;
			return true;
		}
	}

	return false;
}
