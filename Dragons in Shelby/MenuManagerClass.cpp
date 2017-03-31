#include "MenuManagerClass.h"



MenuManagerClass::MenuManagerClass()
{
	mainMenu.ref(0) = "New Game";
	mainMenu.ref(1) = "Show High Scores";
	mainMenu.ref(2) = "Exit Program";

	defaultOptions.ref(0) = "Quit game?";
}

MenuManagerClass::~MenuManagerClass()
{
}

int MenuManagerClass::DisplayMainMenu()
{
	return DisplayMenu(mainMenu);
}

int MenuManagerClass::DisplayMenu(Options choices)
{

	for (int i = 0; i < choices.giveNumOfOptions(); i++) 
	{

		cout << "Option " << i << ": " << choices.ref(i) << endl;


	}




	return 0;
}
