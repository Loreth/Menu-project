#include "pch.h"
#include "CMenuItem.h"


CMenuItem::CMenuItem()
{
}

CMenuItem::CMenuItem(string name, string command)
{
	this->name = name;
	this->command = command;
}


CMenuItem::~CMenuItem()
{
}

string CMenuItem::getName()
{
	return name;
}

string CMenuItem::getCommand()
{
	return command;
}

void CMenuItem::setName(string name)
{
	this->name = name;
}

void CMenuItem::setCommand(string command)
{
	this->command = command;
}
