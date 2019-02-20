#include "pch.h"
#include "CCommandDerived.h"
#include "CCommandTable.h"
#include <iostream>

CreateObjects::CreateObjects(vector<CTable*> *tables) : CCommandTable(tables)
{
}

void CreateObjects::runCommand()
{
	int count = userGetIntVal(CREATE_COUNT, POSITIVE);
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
				tables->push_back(new CTable());
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
				tables->push_back(new CTable(tableName, tableLength));
			}
		}
	}
}

CreateObjectsDefault::CreateObjectsDefault(vector<CTable*>* tables) : CCommandTable(tables)
{
}

void CreateObjectsDefault::runCommand()
{
	int count = userGetIntVal(CREATE_COUNT, POSITIVE);

	for (int i = 0; i < count; i++)
	{
		tables->push_back(new CTable());
	}
}

CreateObjectsParametric::CreateObjectsParametric(vector<CTable*>* tables) : CCommandTable(tables)
{
}

void CreateObjectsParametric::runCommand()
{
	int count = userGetIntVal(CREATE_COUNT, POSITIVE);

	int tableLength;
	string tableName;

	for (int i = 0; i < count; i++)
	{
		tableLength = userGetIntVal(TABLE_LENGTH, POSITIVE);
		tableName = userGetName(GET_NAME);
		tables->push_back(new CTable(tableName, tableLength));
	}
}

SetTableLength::SetTableLength(vector<CTable*> *tables) : CCommandTable(tables)
{
}

void SetTableLength::runCommand()
{
	if (isVectorEmpty()) return;

	int length = userGetIntVal(TABLE_LENGTH, POSITIVE);
	int index = userGetIntVal(OBJECT_INDEX, VECTOR_INDEX_OUT_OF_BOUNDS);
	int *statusCode = new int();

	tables->at(index)->changeTableLength(length, statusCode);
	statusCodePrint(statusCode);
}

DeleteObject::DeleteObject(vector<CTable*> *tables) : CCommandTable(tables)
{
}

void DeleteObject::runCommand()
{
	if (isVectorEmpty()) return;

	int index = userGetIntVal(OBJECT_INDEX, VECTOR_INDEX_OUT_OF_BOUNDS);
	delete tables->at(index);
	tables->erase(tables->begin() + index);
}

DeleteAllObjects::DeleteAllObjects(vector<CTable*> *tables) : CCommandTable(tables)
{
}

void DeleteAllObjects::runCommand()
{
	if (isVectorEmpty()) return;

	for (int i = 0; i < tables->size(); i++)
	{
		delete tables->at(i);
	}
	tables->clear();
}

SetObjectName::SetObjectName(vector<CTable*> *tables) : CCommandTable(tables)
{
}

void SetObjectName::runCommand()
{
	if (isVectorEmpty()) return;

	string name = userGetName(GET_NAME);
	int index = userGetIntVal(OBJECT_INDEX, VECTOR_INDEX_OUT_OF_BOUNDS);
	tables->at(index)->setName(name);
}

CloneThenAddObject::CloneThenAddObject(vector<CTable*> *tables) : CCommandTable(tables)
{
}

void CloneThenAddObject::runCommand()
{
	if (isVectorEmpty()) return;

	int index = userGetIntVal(OBJECT_INDEX, VECTOR_INDEX_OUT_OF_BOUNDS);
	tables->push_back(new CTable(*tables->at(index)));
}

PrintObject::PrintObject(vector<CTable*> *tables) : CCommandTable(tables)
{
}

void PrintObject::runCommand()
{
	if (isVectorEmpty()) return;

	int index = userGetIntVal(OBJECT_INDEX, VECTOR_INDEX_OUT_OF_BOUNDS);
	cout << tables->at(index)->toString() << endl;
}

SetCellValueOfObject::SetCellValueOfObject(vector<CTable*> *tables) : CCommandTable(tables)
{
}

void SetCellValueOfObject::runCommand()
{
	if (isVectorEmpty()) return;

	int value = userGetIntVal(GET_VALUE, NOT_A_NUMBER);
	int objectIndex = userGetIntVal(OBJECT_INDEX, VECTOR_INDEX_OUT_OF_BOUNDS);
	int cellIndex = userGetIntVal(CELL_INDEX, NONNEGATIVE);
	int *statusCode = new int();

	tables->at(objectIndex)->setElement(cellIndex, value, statusCode);
	statusCodePrint(statusCode);
}
