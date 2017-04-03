#ifndef _ENCOUNTER_MANAGER_CLASS_H
#define _ENCOUNTER_MANAGER_CLASS_H
/*
Author : James Malloy
email : jem0044@tigermail.auburn.edu
id : 903518039

fileName: EncounterManagerClass.h

This file contains the encounter manager class which is
used to create encounters and relay the encounter results
back to the game instance.

The encounter is created on the freestore and the manager
holds a pointer to specific encounter generated. The 
encounter is deleted and the pointer set to NULL in
between encounters.

*/



#include "resources.h"
#include "MenuManagerClass.h"
#include "Encounters.h"


class EncounterManagerClass
{
public:
	EncounterManagerClass(MenuManagerClass * inputMenuInterface);
	~EncounterManagerClass();

	flag manageEncounter();
	CharacterData giveResults();
	void cleanEncounter(); //Deletes current and sets it to 0. Also reseults flags and encounter results.

private:

	void generateEncounter(); //Fills the Encounter current with an encounter type or void if no encounter is generated
	void processEncounterOptions(); //Should handle encounter text output and user input using menuClass


	MenuManagerClass * menuInterface = 0;
	Encounter * current = 0;
	flag statusFlag = 0;
	CharacterData encounterEffects;

};





#endif