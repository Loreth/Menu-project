#pragma once
#define DEFAULT_COMMAND "Komenda domyslna"

class CCommand
{
public:
	CCommand();
	virtual ~CCommand();
	virtual void runCommand();
};

