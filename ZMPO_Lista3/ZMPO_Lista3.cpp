#include "pch.h"
#include "ZMPO_Lista3.h"
#include "CMenu.h"
#include "CTable.h"
#include "CCommandDerived.h"
#include "CMenuCommand.h"
#include "CCommandTable.h"`
#include <iostream>

int main()
{
	run();
}

void run()
{
	vector<CTable*> tables;
	/*CMenu *menu = new CMenu(MAIN_MENU, MAIN_MENU_SHORT, nullptr);
	CMenu *createObjectsMenu = new CMenu(OPTION_CREATE_TEXT, OPTION_CREATE_SHORT, menu);

	createObjectsMenu->getItems()->push_back(new CMenuCommand(CREATE_DEFAULT, CREATE_DEFAULT_SHORT, CREATE_DEFAULT_DESC, new CreateObjectsDefault(&tables)));
	createObjectsMenu->getItems()->push_back(new CMenuCommand(CREATE_PARAMETRIC, CREATE_PARAMETRIC_SHORT, CREATE_PARAMETRIC_DESC, new CreateObjectsParametric(&tables)));

	menu->getItems()->push_back(createObjectsMenu);
	menu->getItems()->push_back(new CMenuCommand(OPTION_LENGTH_TEXT, OPTION_LENGTH_SHORT, OPTION_LENGTH_DESC, new SetTableLength(&tables)));
	menu->getItems()->push_back(new CMenuCommand(OPTION_DELETE_TEXT, OPTION_DELETE_SHORT, OPTION_DELETE_DESC, new DeleteObject(&tables)));
	menu->getItems()->push_back(new CMenuCommand(OPTION_DELETE_ALL_TEXT, OPTION_DELETE_ALL_SHORT, OPTION_DELETE_ALL_DESC, new DeleteAllObjects(&tables)));
	menu->getItems()->push_back(new CMenuCommand(OPTION_SET_NAME_TEXT, OPTION_SET_NAME_SHORT, OPTION_SET_NAME_DESC, new SetObjectName(&tables)));
	menu->getItems()->push_back(new CMenuCommand(OPTION_CLONE_TEXT, OPTION_CLONE_SHORT, OPTION_CLONE_DESC, new CloneThenAddObject(&tables)));
	menu->getItems()->push_back(new CMenuCommand(OPTION_PRINT_TEXT, OPTION_PRINT_SHORT, OPTION_PRINT_DESC, new PrintObject(&tables)));
	menu->getItems()->push_back(new CMenuCommand(OPTION_SET_CELL_TEXT, OPTION_SET_CELL_SHORT, OPTION_SET_CELL_DESC, new SetCellValueOfObject(&tables)));

	CMenu *testMenu = new CMenu(TEST_MENU, TEST_MENU_SHORT, menu);
	testMenu->getItems()->push_back(new CMenuCommand(TEST_COMMAND, TEST_COMMAND_SHORT, TEST_COMMAND_DESC, new CCommand()));
	CMenu *test1Menu = new CMenu(TEST_MENU_1, TEST_MENU_1_SHORT, testMenu);
	test1Menu->getItems()->push_back(new CMenuCommand(TEST_COMMAND, TEST_COMMAND_SHORT, TEST_COMMAND_DESC, new CCommand()));
	testMenu->getItems()->push_back(test1Menu);
	testMenu->getItems()->push_back(new CMenu(TEST_MENU_2, TEST_MENU_2_SHORT, testMenu));
	menu->getItems()->push_back(testMenu);

	cout << menu->saveToFile(SAVE_NAME) << endl;*/
	CMenu *menu = new CMenu();
	menu->setRoot(nullptr);
	string menuReadResult = menu->readFromFile(LOAD_NAME);
	cout << menuReadResult;
	if (menuReadResult == MENU_READ_SUCCESS)
	{
		menu->run();
	}
	
	for (int i = 0; i < tables.size(); i++)
	{
		delete tables.at(i);
	}
	tables.clear();
	delete menu;
}