#pragma once
#include <string>
using namespace std;

#define TEXT_INDICATOR '\''
#define TEXT_SEPARATOR ','
#define CHILD_SEPARATOR ';'
#define FAILURE_AT_POSITION "Blad odczytu na pozycji "
#define FAILURE_EXPECTED ", oczekiwano: "

class CMenuItem
{
public:
	CMenuItem();
	CMenuItem(string name, string command);
	virtual ~CMenuItem();
	virtual bool run() = 0;
	string getName();
	string getCommand();
	void setName(string name);
	void setCommand(string command);
	virtual string toString() = 0;

protected:
	string name;
	string command;
};

