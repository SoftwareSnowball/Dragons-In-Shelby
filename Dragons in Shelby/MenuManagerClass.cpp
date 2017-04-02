#include "MenuManagerClass.h"



MenuManagerClass::MenuManagerClass()
{
	mainMenu.ref(0) = "Start a new game of Shelby and Dragons!";
	mainMenu.ref(1) = "View top 10 high scores";
	mainMenu.ref(2) = "Exit Program";

	exitOption.ref(0) = "Quit game?";
}

MenuManagerClass::~MenuManagerClass()
{
}

int MenuManagerClass::DisplayMainMenu()
{
	WriteOptionSet(mainMenu);

	return ProcessInput(mainMenu.giveNumOfOptions());

}

int MenuManagerClass::DisplayMenu(Options set)
{

	WriteOptionSet(set);
	WriteOptionSet(exitOption, set.giveNumOfOptions() + 1);

	return ProcessInput(set.giveNumOfOptions() + 1);


}

void MenuManagerClass::WriteOptionSet(Options set)
{

	WriteOptionSet(set, 1);

}

void MenuManagerClass::WriteOptionSet(Options set, int j)
{

	for (int i = 0; i < set.giveNumOfOptions(); i++)
	{

		cout << "Option " << j++ << ": " << set.ref(i) << endl;

	}


}

int MenuManagerClass::ProcessInput(int OptNum)
{
	int input;
	do
	{
		cout << "Please input one of the numbers on the menu\n";
		cin >> input;
	} while (input < 1 || input > OptNum);


	if (input == OptNum)
	{
		input = UserExitCode;
	}
	else
	{
		input--;
	}


	return input;
}
