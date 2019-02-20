#pragma once
#include "CTable.h"
#include <vector>

#define OPTION_CREATE 1
#define OPTION_LENGTH 2
#define OPTION_DELETE 3
#define OPTION_DELETE_ALL 4
#define OPTION_SET_NAME 5
#define OPTION_CLONE 6
#define OPTION_PRINT 7
#define OPTION_SET_CELL 8
#define OPTION_EXIT 9

#define OPTION_CREATE_TEXT "1 - utworz obiekty CTable"
#define OPTION_LENGTH_TEXT "2 - okresl dlugosc tablicy dla obiektu"
#define OPTION_DELETE_TEXT "3 - skasuj obiekt"
#define OPTION_DELETE_ALL_TEXT "4 - skasuj wszystkie obiekty"
#define OPTION_SET_NAME_TEXT "5 - nadaj nazwe obiektowi"
#define OPTION_CLONE_TEXT "6 - sklonuj obiekt i dodaj do puli"
#define OPTION_PRINT_TEXT "7 - wypisz obiekt"
#define OPTION_SET_CELL_TEXT "8 - wpisz wartosc do komorki obiektu"
#define OPTION_EXIT_TEXT "9 - zakoncz"

#define CREATE_CONSTRUCTOR_TYPE "Wybierz typ konstruktora dla nowych obiektow: "
#define CREATE_DEFAULT "1 - konstruktor domyslny"
#define CREATE_PARAMETRIC "2 - konstruktor parametryczny"
#define CREATE_COUNT "ile obiektow: "

#define OBJECT_INDEX "indeks obiektu: "
#define CELL_INDEX "indeks komorki: "
#define GET_NAME "nazwa tablicy: "
#define GET_VALUE "wartosc komorki: "
#define TABLE_LENGTH "dlugosc tablicy: "
#define VECTOR_INDEX_OUT_OF_BOUNDS "indeks poza granicami wektora, aktualny rozmiar to: "
#define VECTOR_EMPTY "wektor jest aktualnie pusty, by wykonac te operacje najpierw dodaj obiekty"

#define POSITIVE "wartosc musi byc dodatnia!"
#define NONNEGATIVE "wartosc musi byc nieujemna!"
#define NOT_A_NUMBER "wartosc musi byc liczba!"

#define WELCOME_MSG "Witaj w programie! Co chcesz zrobic?: "
#define WRONG_COMMAND "Bledna komenda, podaj ponownie: "
#define INSERT_COMMAND "Podaj komende: "


class Interface
{
public:
	Interface();
	~Interface();

	void start();

private:
	std::vector<CTable*> tables;

	void createObjects(int count);
	void setTableLength(int length, int index);
	void deleteObject(int index);
	void deleteAllObjects();
	void setObjectName(string name, int index);
	void cloneThenAddObject(int index);
	void printObject(int index);
	void setCellValueOfObject(int value, int objectIndex, int cellIndex);
	int userGetIntVal(string message, string errorMessage);
	string userGetName(string message);
	void statusCodePrint(int *statusCode);

};

