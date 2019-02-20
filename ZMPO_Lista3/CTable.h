#pragma once
#include <string>
using namespace std;
#define SUCCESS 0
#define INDEX_OUT_OF_BOUNDS 1
#define NEGATIVE_INDEX 2
#define NONPOSITIVE_LENGTH 3

#define SUCCESS_TEXT "dzialanie zakonczone powodzeniem"
#define INDEX_OUT_OF_BOUNDS_TEXT "indeks poza granicami tablicy"
#define NEGATIVE_INDEX_TEXT "indeks nie moze byc ujemny"
#define NONPOSITIVE_LENGTH_TEXT "dlugosc tablicy nie moze byc niedodatnia"
#define MAX_TABLE_LENGTH_TEXT "maksymalna dlugosc tablicy wynosi "

#define MAX_TABLE_LENGTH 9999
#define DEFAULT_TABLE_SIZE 10
#define DEFAULT_TABLE_NAME "tablica"

class CTable
{
public:
	CTable();
	CTable(string name, int tableLength);
	CTable(CTable &pOtherTable);
	~CTable();

	string getName() { return name; };
	void setName(string name);

	void changeTableLength(int length, int * statusCode);
	void setElement(int offset, int element, int *statusCode);
	int getElement(int offset, int *statusCode);
	void setTableState(CTable &otherTable);
	string toString();

private:
	string name;
	int *table;
	int tableLength;

	void copyTable(CTable &otherTable);
	void verifyOffset(int offset, int *statusCode);
};

