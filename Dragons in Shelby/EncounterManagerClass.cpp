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
	pstates = new PersistentStateFlags();

}

EncounterManagerClass::~EncounterManagerClass()
{
	menuInterface = 0;
	delete pstates;
	cleanEncounter();
}

EncounterResultPackage EncounterManagerClass::manageEncounter()
{

	generateEncounter();

	if (current)
	{
		encounterEffects = current->run();
	}
	else
	{
		encounterEffects = EncounterResultPackage();
	}

	encounterEffects.gameFlags = encounterEffects.gameFlags | statusFlag;

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



#if DEBUG_MODE


	current = new EasyAssigmentEncounter(menuInterface, pstates);

#else


	int roll = rand() % 100;

	if (roll < 10)
	{
		current = NULL;
		cout << "Nothing happens.\n";
	}
	else if (roll < 50) //common encounter
	{

		current = generateCommon();


		if (!current)
			statusFlag = statusFlag | (FunctionErrorFlag);

	}
	else if (roll < 88) //uncommon encounter
	{


		current = generateUncommon();

		if (!current)
			statusFlag = statusFlag | (FunctionErrorFlag);

	}
	else if (roll < 98) //rare encounter
	{

		current = generateRare();

		if (!current)
			statusFlag = statusFlag | (FunctionErrorFlag);

	}
	else //game breaker
	{

		current = generateGameBreaker();

		if (!current)
			statusFlag = statusFlag | (FunctionErrorFlag);

	}



#endif //ENCOUNTER_DEBUG

}



Encounter * EncounterManagerClass::generateFromList(const NamedEncounter * encounter_list)
{
	if (!encounter_list) {
		return nullptr;
	}

	int size = 0;
	while (encounter_list[size].generate != nullptr) {
		size++;
	}

	int roll = rand() % size;
	return encounter_list[roll].generate(menuInterface, pstates);
}

Encounter * EncounterManagerClass::generateCommon()
{
	Encounter* e = generateFromList(COMMON_ENCOUNTER_LIST);
	if (!e) {
		cout << "The generator was unable to create a common encounter type.\n";
	}
	return e;
}

Encounter * EncounterManagerClass::generateUncommon()
{
	Encounter* e = generateFromList(UNCOMMON_ENCOUNTER_LIST);
	if (!e) {
		cout << "The generator was unable to create a uncommon encounter type.\n";
	}
	return e;
}

Encounter * EncounterManagerClass::generateRare()
{
	Encounter* e = generateFromList(RARE_ENCOUNTER_LIST);
	if (!e) {
		cout << "The generator was unable to create a rare encounter type.\n";
	}
	return e;
}

Encounter * EncounterManagerClass::generateGameBreaker()
{
	Encounter* e = generateFromList(GAMEBREAKER_ENCOUNTER_LIST);
	if (!e) {
		cout << "The generator was unable to create a \"FUN\" encounter type.\n";
	}
	return e;
}