#include "pch.h"
#include "CMenuCommand.h"
#include <iostream>

CMenuCommand::CMenuCommand()
{
	this->commandPointer = nullptr;
}

CMenuCommand::CMenuCommand(string name, string command, string description, CCommand *commandPointer) :CMenuItem(name, command)
{
	this->commandPointer = commandPointer;
	this->description = description;
}

CMenuCommand::~CMenuCommand()
{
	delete commandPointer;
}

bool CMenuCommand::run()
{
	if (commandPointer == nullptr)
	{
		cout << EMPTY_COMMAND;
	}
	else
	{
		commandPointer->runCommand();
	}
	return false;
}

string CMenuCommand::getDescription()
{
	return description;
}

void CMenuCommand::setDescription(string description)
{
	this->description = description;
}

string CMenuCommand::toString()
{
	return string()
		+ COMMAND_OPENER + TEXT_INDICATOR + name
		+ TEXT_INDICATOR + TEXT_SEPARATOR + TEXT_INDICATOR + command
		+ TEXT_INDICATOR + TEXT_SEPARATOR + TEXT_INDICATOR + description
		+ TEXT_INDICATOR + COMMAND_CLOSER;
}
