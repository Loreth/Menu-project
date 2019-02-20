#include "pch.h"
#include "CMenu.h"
#include <iostream>
#include <fstream>
#include "CMenuCommand.h"
#include "Parser.h"
using namespace std;

CMenu::CMenu()
{
}

CMenu::CMenu(string name, string command, CMenu *root) :CMenuItem(name, command)
{
	this->root = root;
}


CMenu::~CMenu()
{
	for (int i = 0; i < items.size(); i++) {
		delete items[i];
	}
	items.clear();
}

bool CMenu::run()
{
	bool exitProgram = false;
	do
	{
		if (exitProgram) return true;
		printSelf();
		cout << EXIT_MENU << endl;
		cout << EXIT_PROGRAM << endl;
		cout << SHOW_HELP << endl;
		cout << SEARCH_TREE << endl;
		printSubitems();
	} while (userCommand(&exitProgram));
	return false;
}

vector<CMenuItem*> *CMenu::getItems()
{
	return &items;
}

string CMenu::toString()
{
	string result = string()
		+ MENU_OPENER + TEXT_INDICATOR + name
		+ TEXT_INDICATOR + TEXT_SEPARATOR + TEXT_INDICATOR + command
		+ TEXT_INDICATOR + CHILD_SEPARATOR;

	for (int i = 0; i < items.size(); i++)
	{
		result += items[i]->toString() + TEXT_SEPARATOR;
	}

	//usuniecie zbytecznego przecinka po ostatnim dziecku
	if (items.size() > 0)
	{
		result.erase(result.end() - 1);
	}
	result += MENU_CLOSER;

	return result;
}

string CMenu::saveToFile(string fileName)
{
	string returnMessage;

	fstream menuFile(fileName, ios::out);
	if (menuFile.good())
	{
		menuFile << this->toString();
		returnMessage = MENU_SAVE_SUCCESS;
	}
	else
	{
		returnMessage = MENU_FILE_SAVE_FAILURE;
	}
	menuFile.close();

	return returnMessage;
}

string CMenu::readFromFile(string fileName)
{
	string returnMessage;

	fstream menuFile(fileName, ios::in);
	if (menuFile.good())
	{
		string fileContent;
		getline(menuFile, fileContent, '\0');
		returnMessage = MENU_READ_SUCCESS;
		menuFile.close();

		Parser(&fileContent, 0, &returnMessage).parseMenu(this);
	}
	else
	{
		returnMessage = MENU_FILE_READ_FAILURE;
	}

	return returnMessage;
}

void CMenu::setRoot(CMenu *root)
{
	this->root = root;
}

void CMenu::printSelf()
{
	cout << endl << name;
	cout << COMMAND_SPACED << command << endl;
}

void CMenu::printSubitems()
{
	for (int i = 0; i < items.size(); i++)
	{
		cout << items[i]->getName();
		cout << COMMAND_SPACED << items[i]->getCommand();
		cout << endl;
	}
}

bool CMenu::userCommand(bool *exitProgram)
{
	string input;
	string returnMessage = COMMAND_NOT_FOUND;
	getline(cin, input);
	bool success = false;

	if (input == BACK)
	{
		return false;
	}
	else if (input == EXIT)
	{
		success = true;
		*exitProgram = true;
	}
	else if (input == HELP || input == SEARCH)
	{
		returnMessage = COMMAND_NAME_NOT_GIVEN;
	}
	else if (input.substr(0, 5) == HELP_SPACE)
	{
		for (int i = 0; i < items.size(); i++)
		{
			if (input.substr(5) == items[i]->getCommand())
			{
				CMenuCommand *command = dynamic_cast<CMenuCommand*>(items[i]);
				if (command != NULL)
				{
					success = true;
					cout << endl << command->getDescription() << endl;
					return true;
				}
			}
		}
		returnMessage = COMMAND_NOT_FOUND_HELP;
	}
	else if (input.substr(0, 7) == SEARCH_SPACE)
	{
		success = searchCommand(input.substr(7));
		returnMessage = COMMAND_NOT_FOUND_SEARCH;
	}
	else
	{
		for (int i = 0; i < items.size(); i++)
		{
			if (input == items[i]->getCommand())
			{
				success = true;
				*exitProgram = items[i]->run();
			}
		}
	}

	if (!success)
	{
		cout << endl << returnMessage << endl;
	}

	return true;
}

bool CMenu::searchCommand(string commandName)
{
	CMenu *mainMenu = this;
	while (mainMenu->root != nullptr)
	{
		mainMenu = mainMenu->root;
	}

	return searchCommandInSubmenus(mainMenu, commandName, mainMenu->command);
}

bool CMenu::searchCommandInSubmenus(CMenu *menu, string commandName, string path)
{
	bool commandFoundAtLeastOnce = false;

	for (int i = 0; i < menu->items.size(); i++)
	{
		CMenu *submenu = dynamic_cast<CMenu*>(menu->items[i]);
		if (submenu != NULL)
		{
			commandFoundAtLeastOnce = searchCommandInSubmenus(submenu, commandName, path + PATH_SEPARATOR + submenu->getCommand()) || commandFoundAtLeastOnce;
		}
		else if (menu->items[i]->getCommand() == commandName)
		{
			cout << endl << path + PATH_SEPARATOR + commandName << endl;
			commandFoundAtLeastOnce = true;
		}
	}

	return commandFoundAtLeastOnce;
}
