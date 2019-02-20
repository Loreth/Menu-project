#pragma once
#include "CMenuItem.h"
#include "CCommand.h"

#define EMPTY_COMMAND "pusta komenda"
#define COMMAND_OPENER '['
#define COMMAND_CLOSER ']'

class CMenuCommand :
	public CMenuItem
{
public:
	CMenuCommand();
	CMenuCommand(string name, string command, string description, CCommand *commandPointer);
	~CMenuCommand();
	bool run();
	string getDescription();
	void setDescription(string description);
	string toString();

private:
	CCommand *commandPointer;
	string description;
};

