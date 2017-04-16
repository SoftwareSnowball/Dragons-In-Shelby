#include "MenuManagerClass.h"
/*
Author: James Malloy
email:	jem0044@tigermail.auburn.edu
id:		903518039

FileName: MenuManagerClass.cpp


See header file for description

*/


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

void MenuManagerClass::WriteOptionSet(Options& set)
{

	WriteOptionSet(set, 1);

}

//This function is used to start listing options from a number
//other than 1. Used for displaying two option sets together.
void MenuManagerClass::WriteOptionSet(Options& set, int j)
{

	for (int i = 0; i < set.giveNumOfOptions(); i++)
	{

		cout << j++ << ": " << set.ref(i) << endl;

	}


}

int MenuManagerClass::ProcessInput(int OptNum)
{
	int input;
	int i = 0;

	bool correctInput = false;

	while (!correctInput)
	{
		cout << "Player input: ";
		cin >> input;
		string flush;

		if (cin.fail())
		{
			cin.clear();
			cin >> flush;
			cout << "That input could not be processed.\n";
			cout << "Please enter a number from the list above\n";
		}
		else if (input < 1 || input > OptNum)
		{
			i = 1;
			cout << "That input could not be processed.\n";
			cout << "Please enter a number from the list above\n";
		}
		else
		{
			correctInput = true;
		}

		cout << endl;
	}


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
