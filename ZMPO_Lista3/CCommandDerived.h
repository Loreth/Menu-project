#pragma once
#include "CCommand.h"
#include "CCommandTable.h"

class CreateObjects :
	public CCommandTable
{
public:
	CreateObjects(vector<CTable*> *tables);

	void runCommand();
};

class CreateObjectsDefault :
	public CCommandTable
{
public:
	CreateObjectsDefault(vector<CTable*> *tables);

	void runCommand();
};

class CreateObjectsParametric :
	public CCommandTable
{
public:
	CreateObjectsParametric(vector<CTable*> *tables);

	void runCommand();
};

class SetTableLength :
	public CCommandTable
{
public:
	SetTableLength(vector<CTable*> *tables);

	void runCommand();
};

class DeleteObject :
	public CCommandTable
{
public:
	DeleteObject(vector<CTable*> *tables);

	void runCommand();
};

class DeleteAllObjects :
	public CCommandTable
{
public:
	DeleteAllObjects(vector<CTable*> *tables);

	void runCommand();
};

class SetObjectName :
	public CCommandTable
{
public:
	SetObjectName(vector<CTable*> *tables);

	void runCommand();
};

class CloneThenAddObject :
	public CCommandTable
{
public:
	CloneThenAddObject(vector<CTable*> *tables);

	void runCommand();
};

class PrintObject :
	public CCommandTable
{
public:
	PrintObject(vector<CTable*> *tables);

	void runCommand();
};

class SetCellValueOfObject :
	public CCommandTable
{
public:
	SetCellValueOfObject(vector<CTable*> *tables);

	void runCommand();
};