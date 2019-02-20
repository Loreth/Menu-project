#pragma once
#include "CCommand.h"
#include <vector>
#include "CTable.h"
using namespace std;

#define OPTION_CREATE_TEXT "Utworz obiekty CTable"
#define OPTION_LENGTH_TEXT "Okresl dlugosc tablicy dla obiektu"
#define OPTION_DELETE_TEXT "Skasuj obiekt"
#define OPTION_DELETE_ALL_TEXT "Skasuj wszystkie obiekty"
#define OPTION_SET_NAME_TEXT "Nadaj nazwe obiektowi"
#define OPTION_CLONE_TEXT "Sklonuj obiekt i dodaj do puli"
#define OPTION_PRINT_TEXT "Wypisz obiekt"
#define OPTION_SET_CELL_TEXT "Wpisz wartosc do komorki obiektu"

#define OPTION_CREATE_SHORT "utworz"
#define OPTION_LENGTH_SHORT "dlugosc"
#define OPTION_DELETE_SHORT "usun"
#define OPTION_DELETE_ALL_SHORT "usun wsz"
#define OPTION_SET_NAME_SHORT "nazwa"
#define OPTION_CLONE_SHORT "klonuj"
#define OPTION_PRINT_SHORT "wypisz"
#define OPTION_SET_CELL_SHORT "wpisz"

#define OPTION_LENGTH_DESC "Pyta o dlugosc tablicy dla obiektu o podanym indeksie po czym ja zmienia"
#define OPTION_DELETE_DESC "Kasuje obiekt pod podanym indeksem"
#define OPTION_DELETE_ALL_DESC "Kasuje wszystkie obiekty"
#define OPTION_SET_NAME_DESC "Nadaje nazwe obiektowi pod podanym indeksem"
#define OPTION_CLONE_DESC "Klonuje obiekt pod podanym indeksem i dodaje go na koniec wektora"
#define OPTION_PRINT_DESC "Wypisuje obiekt znajdujacy sie pod podanym indeksem"
#define OPTION_SET_CELL_DESC "Wpisuje podana wartosc do komorki obiektu o podanym indeksie"

#define CREATE_CONSTRUCTOR_TYPE "Wybierz typ konstruktora dla nowych obiektow: "
#define CREATE_DEFAULT "Konstruktor domyslny"
#define CREATE_PARAMETRIC "Konstruktor parametryczny"
#define CREATE_DEFAULT_SHORT "domyslny"
#define CREATE_PARAMETRIC_SHORT "param"
#define CREATE_DEFAULT_DESC "Tworzy obiekty w konstruktorem domyslnym"
#define CREATE_PARAMETRIC_DESC "Tworzy obiekty w konstruktorem parametrycznym, pytajac kolejno o pola konieczne do ich utworzenia"
#define CREATE_COUNT "ile obiektow: "

#define OBJECT_INDEX "indeks obiektu: "
#define CELL_INDEX "indeks komorki: "
#define GET_NAME "nazwa tablicy: "
#define GET_VALUE "wartosc komorki: "
#define TABLE_LENGTH "dlugosc tablicy: "
#define VECTOR_INDEX_OUT_OF_BOUNDS "indeks poza granicami wektora, aktualny rozmiar to: "
#define VECTOR_EMPTY "wektor jest aktualnie pusty, by wykonac te operacje najpierw dodaj obiekty"
#define VECTOR_MAX "Jednorazowo dodac mozna maksymalnie "
#define VECTOR_MAX_NUM 9999
#define OBJECTS " obiektow"

#define POSITIVE "wartosc musi byc dodatnia!"
#define NONNEGATIVE "wartosc musi byc nieujemna!"
#define NOT_A_NUMBER "wartosc musi byc liczba!"

#define WELCOME_MSG "Witaj w programie! Co chcesz zrobic?: "
#define WRONG_COMMAND "Bledna komenda, podaj ponownie: "
#define INSERT_COMMAND "Podaj komende: "

class CCommandTable :
	public CCommand
{
public:
	CCommandTable(vector<CTable*> *tables);
	virtual ~CCommandTable();
	virtual void runCommand();

protected:
	vector<CTable*> *tables;

	int userGetIntVal(string message, string errorMessage);
	string userGetName(string message);
	void statusCodePrint(int *statusCode);
	bool isVectorEmpty();
};

