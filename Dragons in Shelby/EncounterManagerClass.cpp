#include "EncounterManagerClass.h"
/*

Author: James Malloy
email:	jem0044@tigermail.auburn.edu
id:		903518039

FileName: EncounterManagerClass.cpp


See header file for description

*/


EncounterManagerClass::EncounterManagerClass(MenuManagerClass * inputMenuInterface)
{

	menuInterface = inputMenuInterface;

}

EncounterManagerClass::~EncounterManagerClass()
{
	menuInterface = 0;
	cleanEncounter();
}

EncounterResultPackage EncounterManagerClass::manageEncounter()
{

	generateEncounter();

	if (current)
	{
		current->linkMenuInterface(menuInterface);
		encounterEffects = current->run();
	}
	else
	{
		encounterEffects = EncounterResultPackage();
		cout << "Nothing happens\n\n";
	}



	return encounterEffects;
}

void EncounterManagerClass::cleanEncounter()
{

	if (current)
	{
		delete current;
		current = 0;
	}

}

void EncounterManagerClass::generateEncounter()
{



#ifdef DEBUG_MODE


	current = new DebugEncounter();

#endif



#ifndef DEBUG_MODE

	int roll = rand() % 100;
	int i;

	if (roll < 10)
	{
		current = NULL;
		cout << "Nothing happens.\n";
	}
	else if (roll < 70) //common encounter
	{





	}
	else if (roll < 90) //uncommon encounter
	{

	}
	else if (roll < 98) //rare encounter
	{


	}
	else //game breaker
	{

	}









#endif //ENCOUNTER_DEBUG

}



