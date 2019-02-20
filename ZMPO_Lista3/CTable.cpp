#include "pch.h"
#include "CTable.h"
#include <iostream>
using namespace std;

CTable::CTable()
{
	name = DEFAULT_TABLE_NAME;
	tableLength = DEFAULT_TABLE_SIZE;
	table = new int[tableLength];

	cout << "bezp: " + name << endl;
}

CTable::CTable(string name, int tableLength)
{
	this->name = name;
	table = new int[tableLength];
	this->tableLength = tableLength;

	cout << "parametr: " + name << endl;
}

CTable::CTable(CTable &otherTable)
{
	name = otherTable.name + "_copy";
	table = new int[otherTable.tableLength];
	this->tableLength = otherTable.tableLength;

	copyTable(otherTable);

	cout << "kopiuj: " + name << endl;
}


CTable::~CTable()
{
	cout << "usuwam: " + name << endl;
	delete table;
}

void CTable::setName(string name)
{
	this->name = name;
}

void CTable::changeTableLength(int length, int *statusCode)
{
	if (length <= 0)
	{
		*statusCode = NONPOSITIVE_LENGTH;
		return;
	}
	else
	{
		*statusCode = SUCCESS;

		int *newTable = new int[length];
		int copyLength = length < tableLength ? length : tableLength;

		for (int i = 0; i < copyLength; i++)
		{
			newTable[i] = table[i];
		}

		delete table;
		table = newTable;
		tableLength = length;
	}
}

void CTable::setElement(int offset, int element, int *statusCode)
{
	verifyOffset(offset, statusCode);
	if (*statusCode == SUCCESS)
	{
		table[offset] = element;
	}
}

int CTable::getElement(int offset, int *statusCode)
{
	verifyOffset(offset, statusCode);
	if (*statusCode == SUCCESS)
	{
		return table[offset];
	}
}

void CTable::setTableState(CTable &otherTable)
{
	tableLength = otherTable.tableLength;
	delete table;
	table = new int[tableLength];
	copyTable(otherTable);
}

string CTable::toString()
{
	string result = name + " len: " + to_string(tableLength) + " values: ";
	result += to_string(table[0]);;

	for (int i = 1; i < tableLength; i++)
	{
		result += ", " + to_string(table[i]);
	}
	return result;
}

void CTable::copyTable(CTable &otherTable)
{
	for (int i = 0; i < otherTable.tableLength; i++)
	{
		table[i] = otherTable.table[i];
	}
}

void CTable::verifyOffset(int offset, int *statusCode)
{
	if (offset < 0)
	{
		*statusCode = NEGATIVE_INDEX;
		return;
	}
	else if (offset >= tableLength)
	{
		*statusCode = INDEX_OUT_OF_BOUNDS;
		return;
	}
	else
	{
		*statusCode = SUCCESS;
	}
}
