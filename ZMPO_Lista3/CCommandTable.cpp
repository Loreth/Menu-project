#include "pch.h"
#include "CCommandTable.h"
#include <iostream>

CCommandTable::CCommandTable(vector<CTable*> *tables)
{
	this->tables = tables;
}

CCommandTable::~CCommandTable()
{
}

void CCommandTable::runCommand()
{
	std::cout << DEFAULT_COMMAND;
}

int CCommandTable::userGetIntVal(string message, string errorMessage)
{
	int value = 0;
	string sValue;
	char *endOfNumber;
	bool success = false;

	while (!success)
	{
		cout << message;
		getline(cin, sValue);
		value = (int)strtol(sValue.c_str(), &endOfNumber, 10);

		if (endOfNumber == sValue)
		{
			cout << NOT_A_NUMBER << endl;
		}
		else if (message == CREATE_COUNT && value > VECTOR_MAX_NUM)
		{
			cout << VECTOR_MAX << VECTOR_MAX_NUM << OBJECTS << endl;
		}
		else if (message == TABLE_LENGTH && value > MAX_TABLE_LENGTH)
		{
			cout << MAX_TABLE_LENGTH_TEXT << MAX_TABLE_LENGTH << endl;
		}
		else if (value < 0 && errorMessage == NONNEGATIVE || value <= 0 && errorMessage == POSITIVE || value != 1 && value != 2 && errorMessage == WRONG_COMMAND)
		{
			cout << errorMessage << endl;
		}
		else if (errorMessage == VECTOR_INDEX_OUT_OF_BOUNDS && (value < 0 || value >= tables->size()))
		{
			cout << errorMessage << tables->size() << endl;
		}
		else
		{
			success = true;
		}
	}

	return value;
}

string CCommandTable::userGetName(string message)
{
	string name;
	cout << message;
	getline(cin, name);

	return name;
}

void CCommandTable::statusCodePrint(int * statusCode)
{
	switch (*statusCode)
	{
	case SUCCESS:
		cout << SUCCESS_TEXT << endl;
		break;
	case INDEX_OUT_OF_BOUNDS:
		cout << INDEX_OUT_OF_BOUNDS_TEXT << endl;
		break;
	case NEGATIVE_INDEX:
		cout << NEGATIVE_INDEX_TEXT << endl;
		break;
	case NONPOSITIVE_LENGTH:
		cout << NONPOSITIVE_LENGTH_TEXT << endl;
		break;
	default:
		break;
	}
}

bool CCommandTable::isVectorEmpty()
{
	if (tables->size() == 0)
	{
		cout << endl << VECTOR_EMPTY << endl;
		return true;
	}
	return false;
}
