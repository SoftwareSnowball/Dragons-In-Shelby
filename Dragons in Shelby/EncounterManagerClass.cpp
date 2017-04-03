#include "EncounterManagerClass.h"

EncounterManagerClass::EncounterManagerClass(MenuManagerClass * inputMenuInterface)
{

	menuInterface = inputMenuInterface;

}

EncounterManagerClass::~EncounterManagerClass()
{
	menuInterface = 0;
	cleanEncounter();
}

flag EncounterManagerClass::manageEncounter()
{

	generateEncounter();

	if (current)
	{
		processEncounterOptions();
	}
	else
	{
		encounterEffects = CharacterData(CharacterStats(), 0);
		cout << "Nothing happens\n\n";
	}



	return statusFlag;
}

CharacterData EncounterManagerClass::giveResults()
{
	return encounterEffects;
}

void EncounterManagerClass::cleanEncounter()
{

	if (current)
	{
		delete current;
		current = 0;
	}


	encounterEffects = CharacterData();

}

void EncounterManagerClass::generateEncounter()
{

	int roll = rand() % 100;
	int i;

	if (roll < 25) //Nothing happens
	{
		current = 0;
	}
	else if (roll < 66) //A common event occurs
	{

		i = rand() % 3;

		switch (i)
		{
		case 0:
			current = new ProfessorEncounter();
			break;
		case 1:
			current = new UndergraduateEncounter();
			break;
		case 2:
			current = new WeekendEncounter();
		}


	}
	else if (roll < 87) //A rare event occurs
	{

		i = rand() % 2;

		switch (i)
		{
		case 0:
			current = new BugEncounter();
			break;
		case 1:
			current = new AnomalyEncounter();
			break;
		}

	}
	else //A game breaker occurs
	{
		current = new CthulhuEncounter();
	}

}

void EncounterManagerClass::processEncounterOptions()
{

	current->displayEncounter();

	cout << endl;

	int i = menuInterface->DisplayMenu(current->giveOptions());

	if (i == UserExitCode)
	{
		statusFlag = statusFlag | UserExitFlag;
		return;
	}

	cout << endl;
	encounterEffects = current->getOptionResult(i);

	cout << endl;
}



