#ifndef _ENCOUNTER_MANAGER_CLASS_H
#define _ENCOUNTER_MANAGER_CLASS_H

#include "resources.h"
#include "MenuManagerClass.h"


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