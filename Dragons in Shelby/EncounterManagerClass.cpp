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
		runEncounter();
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

#define ENCOUNTER_DEBUG 1

#ifdef ENCOUNTER_DEBUG


	current = new VideoGameEncounter();

#endif



#ifndef ENCOUNTER_DEBUG

	int roll = rand() % 100;
	int i;

	if (roll < 25) //Nothing happens
	{
		current = 0;
	}
	else if (roll < 75) //A common event occurs
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
	else if (roll < 98) //A rare event occurs
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


#endif //ENCOUNTER_DEBUG

}




