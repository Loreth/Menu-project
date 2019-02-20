#include "pch.h"
#include "Interface.h"
#include "CTable.h"
#include <vector>
#include <iostream>
#include <cstdlib>

Interface::Interface()
{
}

Interface::~Interface()
{
	deleteAllObjects();
}

void Interface::start()
{
	int command = 1;
	string chosenCommand;

	cout << WELCOME_MSG << endl;
	cout << OPTION_CREATE_TEXT << endl;
	cout << OPTION_LENGTH_TEXT << endl;
	cout << OPTION_DELETE_TEXT << endl;
	cout << OPTION_DELETE_ALL_TEXT << endl;
	cout << OPTION_SET_NAME_TEXT << endl;
	cout << OPTION_CLONE_TEXT << endl;
	cout << OPTION_PRINT_TEXT << endl;
	cout << OPTION_SET_CELL_TEXT << endl;
	cout << OPTION_EXIT_TEXT << endl;

	while (command != OPTION_EXIT)
	{
		command = 0;
		while (command == 0)
		{
			cout << INSERT_COMMAND << endl;
			getline(cin, chosenCommand);
			command = atoi(chosenCommand.c_str());

			if (command == 0)
			{
				cout << WRONG_COMMAND << endl;
			}
			else if (tables.size() == 0 && command >= 2 && command <= 8)
			{
				cout << VECTOR_EMPTY << endl;
				command = 0;
			}
		}

		switch (command)
		{
		case OPTION_CREATE:
			createObjects(userGetIntVal(CREATE_COUNT, POSITIVE));
			break;
		case OPTION_LENGTH:
			setTableLength(userGetIntVal(TABLE_LENGTH, POSITIVE), userGetIntVal(OBJECT_INDEX, VECTOR_INDEX_OUT_OF_BOUNDS));
			break;
		case OPTION_DELETE:
			deleteObject(userGetIntVal(OBJECT_INDEX, VECTOR_INDEX_OUT_OF_BOUNDS));
			break;
		case OPTION_DELETE_ALL:
			deleteAllObjects();
			break;
		case OPTION_SET_NAME:
			setObjectName(userGetName(GET_NAME), userGetIntVal(OBJECT_INDEX, VECTOR_INDEX_OUT_OF_BOUNDS));
			break;
		case OPTION_CLONE:
			cloneThenAddObject(userGetIntVal(OBJECT_INDEX, VECTOR_INDEX_OUT_OF_BOUNDS));
			break;
		case OPTION_PRINT:
			printObject(userGetIntVal(OBJECT_INDEX, VECTOR_INDEX_OUT_OF_BOUNDS));
			break;
		case OPTION_SET_CELL:
			setCellValueOfObject(userGetIntVal(GET_VALUE, NOT_A_NUMBER), userGetIntVal(OBJECT_INDEX, VECTOR_INDEX_OUT_OF_BOUNDS), userGetIntVal(CELL_INDEX, NONNEGATIVE));
			break;
		default:
			break;
		}
	}
}

void Interface::createObjects(int count)
{
	int constructorType = 0;
	cout << CREATE_CONSTRUCTOR_TYPE << endl;
	cout << CREATE_DEFAULT << endl;
	cout << CREATE_PARAMETRIC << endl;

	while (constructorType != 1 && constructorType != 2)
	{
		constructorType = userGetIntVal("", WRONG_COMMAND);

		if (constructorType == 1)
		{
			for (int i = 0; i < count; i++)
			{
				tables.push_back(new CTable());
			}
		}
		else if (constructorType == 2)
		{
			int tableLength;
			string tableName;

			for (int i = 0; i < count; i++)
			{
				tableLength = userGetIntVal(TABLE_LENGTH, POSITIVE);
				tableName = userGetName(GET_NAME);
				tables.push_back(new CTable(tableName, tableLength));
			}

		}
	}
}

void Interface::setTableLength(int length, int index)
{
	int *statusCode = new int();

	tables.at(index)->changeTableLength(length, statusCode);
	statusCodePrint(statusCode);
}

void Interface::deleteObject(int index)
{
	delete tables.at(index);
	tables.erase(tables.begin() + index);
}

void Interface::deleteAllObjects()
{
	for (CTable *table : tables)
	{
		delete table;
	}
	tables.clear();
}

void Interface::setObjectName(string name, int index)
{
	tables.at(index)->setName(name);
}

void Interface::cloneThenAddObject(int index)
{
	tables.push_back(new CTable(*tables.at(index)));
}

void Interface::printObject(int index)
{
	cout << tables.at(index)->toString() << endl;
}

void Interface::setCellValueOfObject(int value, int objectIndex, int cellIndex)
{
	int *statusCode = new int();

	tables.at(objectIndex)->setElement(cellIndex, value, statusCode);
	statusCodePrint(statusCode);
}

int Interface::userGetIntVal(string message, string errorMessage)
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
		else if (message == TABLE_LENGTH && value > MAX_TABLE_LENGTH)
		{
			cout << MAX_TABLE_LENGTH_TEXT << MAX_TABLE_LENGTH << endl;
		}
		else if (value < 0 && errorMessage == NONNEGATIVE || value <= 0 && errorMessage == POSITIVE || value != 1 && value != 2 && errorMessage == WRONG_COMMAND)
		{
			cout << errorMessage << endl;
		}
		else if (errorMessage == VECTOR_INDEX_OUT_OF_BOUNDS && (value < 0 || value >= tables.size()))
		{
			cout << errorMessage << tables.size() << endl;
		}
		else
		{
			success = true;
		}
	}

	return value;
}

string Interface::userGetName(string message)
{
	string name;
	cout << message;
	getline(cin, name);

	return name;
}

void Interface::statusCodePrint(int *statusCode)
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
