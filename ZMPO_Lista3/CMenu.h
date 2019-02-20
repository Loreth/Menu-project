#pragma once
#include "CMenuItem.h"
#include <vector>

#define NAME "nazwa: "
#define COMMAND_SPACED "  -> "
#define COMMAND "komenda: "
#define COMMAND_TO_REMOVE "komenda elementu do usuniecia: "
#define COMMAND_NOT_FOUND "Nie ma takiej komendy"
#define COMMAND_NOT_FOUND_HELP "Brak komendy"
#define COMMAND_NOT_FOUND_SEARCH "Komendy nie znaleziono"
#define COMMAND_NAME_NOT_GIVEN "Nie podano nazwy komendy"
#define WRONG_TYPE "Bledny typ"
#define BACK "back"
#define EXIT "exit"
#define HELP "help"
#define SEARCH "search"
#define HELP_SPACE "help "
#define SEARCH_SPACE "search "
#define ADD_ITEM "dodaj elem"
#define REMOVE_ITEM "usun elem"
#define ITEM_TYPE "Jaki element chcesz dodac (CMenuCommand/CMenu): "
#define TYPE_CMENUCOMMAND "CMenuCommand"
#define TYPE_CMENU "CCommand"
#define NAME_TAKEN "istnieje juz element o takiej nazwie"
#define COMMAND_TAKEN "istnieje juz komenda o takiej nazwie"
#define SUCCESS_TEXT "dzialanie zakonczone powodzeniem"
#define MAIN_MENU "Menu glowne"
#define MAIN_MENU_SHORT "glowne"
#define EXIT_MENU " | wyjscie z menu -> back"
#define EXIT_PROGRAM " | wyjscie z programu -> exit"
#define SHOW_HELP " | opis komendy -> help <nazwa komendy>"
#define SEARCH_TREE " | wyszukanie komendy -> search <nazwa komendy>"
#define PATH_SEPARATOR " -> "
#define MENU_OPENER '('
#define MENU_CLOSER ')'
#define MENU_SAVE_SUCCESS "Menu zostalo zapisane"
#define MENU_FILE_SAVE_FAILURE "Menu nie zostalo zapisane poprawnie (odmowa dostepu)"
#define MENU_READ_SUCCESS "Menu zostalo wczytane"
#define MENU_FILE_READ_FAILURE "Menu nie zostalo wczytane poprawnie (odmowa dostepu lub brak pliku)"
#define SAVE_NAME "Menu_glowne.txt"
#define LOAD_NAME "Menu_wczytaj.txt"


class CMenu :
	public CMenuItem
{
public:
	CMenu();
	CMenu(string name, string command, CMenu *root);
	~CMenu();
	bool run();
	vector<CMenuItem*> *getItems();
	string toString();
	string saveToFile(string fileName);
	string readFromFile(string fileName);
	void setRoot(CMenu *root);

private:
	vector<CMenuItem*> items;
	CMenu *root;

	void printSelf();
	void printSubitems();
	bool userCommand(bool *exitProgram);
	bool searchCommand(string commandName);
	bool searchCommandInSubmenus(CMenu *menu, string commandName, string path);
};

