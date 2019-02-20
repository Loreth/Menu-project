#include "pch.h"
#include <iostream>
#include "CCommand.h"

CCommand::CCommand()
{
}

CCommand::~CCommand()
{
}

void CCommand::runCommand()
{
	std::cout << DEFAULT_COMMAND;
}