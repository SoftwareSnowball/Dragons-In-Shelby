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

CharacterStats EncounterManagerClass::giveResults()
{
	return encounterResults;
}

void EncounterManagerClass::cleanEncounter()
{

	if (current)
	{
		delete current;
		current = 0;
	}


	encounterResults = CharacterStats();

}

void EncounterManagerClass::generateEncounter()
{
	current = new Encounter();
}

void EncounterManagerClass::processEncounterOptions()
{

	current->diplayEncounter();

	int i = menuInterface->DisplayMenu(current->giveOptions());

	if (i == UserExitCode)
	{
		statusFlag = statusFlag | UserExitFlag;
		return;
	}


	encounterResults = current->getOptionResult(i);


}



