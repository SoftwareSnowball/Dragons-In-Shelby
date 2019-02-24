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



Encounter * EncounterManagerClass::generateCommon()
{

	int i = rand() % 8;

	switch (i)
	{
	case 0:
		return new UndergraduateEncounter(menuInterface, pstates);

	case 1:
		return new WeekendEncounter(menuInterface, pstates);

	case 2:
		return new ProfessorEncounter(menuInterface, pstates);

	case 3:
		return new VideoGameEncounter(menuInterface, pstates);
	
	case 4:
		return new CancelledClassEncounter(menuInterface, pstates);

	case 5:
		return new NoisyNeighborsEncounter(menuInterface, pstates);

	case 6:
		return new EmailEncounter(menuInterface, pstates);

	case 7:
		return new EasyAssigmentEncounter(menuInterface, pstates);
	}


	cout << "The generator was unable to create a common encounter type.\n";

	return nullptr;
}

Encounter * EncounterManagerClass::generateUncommon()
{

	int i = rand() % 6;

	switch (i)
	{

	case 0:
		return new BugEncounter(menuInterface, pstates);

	case 1:
		return new RefrigeratorEncounter(menuInterface, pstates);

	case 2:
		return new CharityEncounter(menuInterface, pstates);

	case 3:
		return new SicknessEncounter(menuInterface, pstates);

	case 4:
		return new BrokenNinjaEncounter(menuInterface, pstates);

	case 5:
		return new MedicalStudentEncounter(menuInterface, pstates);
	}



	cout << "The generator was unable to create an uncommon encounter type.\n";

	return nullptr;
}

Encounter * EncounterManagerClass::generateRare()
{

	int i = rand() % 4;

	switch (i)
	{
	case 0:
		return new AnomalyEncounter(menuInterface, pstates);
	case 1:
		return new TheDoctorEncounter(menuInterface, pstates);
	case 2:
		return new AlienEncounter(menuInterface, pstates);
	case 3:
		return new PentagramEncounter(menuInterface, pstates);
	}

	cout << "The generator was unable to create a rare encounter type\n";

	return nullptr;
}

Encounter * EncounterManagerClass::generateGameBreaker()
{

	int i = rand() % 1;

	switch (i)
	{
	case 0:
		return new CthulhuEncounter(menuInterface, pstates);
	}


	cout << "The generator was unable to create a \"FUN\" encounter type.\n";
	return nullptr;
}