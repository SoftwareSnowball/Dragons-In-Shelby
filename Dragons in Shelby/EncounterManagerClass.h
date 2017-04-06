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

As of the encounter rework update, EncounterManager no longer handles
user input pertaining to encounters. It instead gives the menuInterface pointer
to the encounter on generation which allows for a more streamlined encounter
handling process. This also allows more flexibilty with the scope of an encounter.
ex. An encounter can now have multiple layers of user decisions.


*/



#include "resources.h"
#include "MenuManagerClass.h"
#include "Encounters.h"


class EncounterManagerClass
{
public:
	EncounterManagerClass(MenuManagerClass * inputMenuInterface);
	~EncounterManagerClass();

	EncounterResultPackage manageEncounter();
	

private:

	void generateEncounter(); //Fills the Encounter current with an encounter type or void if no encounter is generated
	void generateDebugEncounter(); //Called when program is in debug mode. Give user option to select encounter.
	void cleanEncounter(); //Deletes current and sets it to 0. Also reseults flags and encounter results.

	Encounter * generateCommon();
	Encounter * generateUncommon();
	Encounter * generateRare();
	Encounter * generateGameBreaker();


	MenuManagerClass * menuInterface = 0;
	Encounter * current = 0;
	flag statusFlag = 0;
	EncounterResultPackage encounterEffects;

};





#endif