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
	processEncounterOptions();

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
	current = new CthulhuEncounter();
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



