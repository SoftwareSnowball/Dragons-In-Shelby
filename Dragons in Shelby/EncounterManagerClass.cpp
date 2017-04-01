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


	encounterEffects = current->getOptionResult(i);


}



