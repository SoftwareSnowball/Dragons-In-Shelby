/*
Author : James Malloy
email : jem0044@tigermail.auburn.edu
id : 903518039

fileName: Encounters.h


This files should contain all the specific encounter type which inherit from the Encounter class.
This is where all the fun gets defined.

I defined the menu options in the constructor.
I defined the text for the encounter in the showEncounter function
and I gave each one a function to determine what happens for each
user input.

All of the above except the constructor are overrides of virtual
functions in the Encounter class.

*/

#ifndef _ENCOUNTERS_H 
#define _ENCOUNTERS_H 

#include "resources.h"
#include "MenuManagerClass.h"

/*
In hind sight it probably would have been better to just have one encounter class
and have it's function vary based on data rather than having a subclass for every
encounter type. Oh well. I didn't do it this way two years ago and there's no
point in changing it now.
*/

/*
This class is special in that it is not meant to be instantiated directly, but
it is meant to be the parent of all the specific Encounter types in the
game.
*/
class Encounter
{
public:

	Encounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);
	virtual ~Encounter();

	const string encounterName = "Default Encounter";

	void linkInterfaces(MenuManagerClass * inputMenuInterface, PersistentStateFlags * inStates);

	EncounterResultPackage run();


protected:


	virtual void displayEncounter();
	virtual void encounterMechanics(); //overridden when needed to create more flexibility
	virtual CharacterData getOptionResult(int i); //legacy encounter system support


	EncounterResultPackage result;
	MenuManagerClass * menuInterface;
	PersistentStateFlags * states;
	Options opts;
	string encounterInfo;

};



//===================================================
//                 DEBUG ENCOUNTERS
//===================================================
class DebugEncounter : public Encounter //debug
{
public:
	DebugEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:

	void displayEncounter();
	void generateOptions();
	//EncounterResultPackage encounterMechanics();
	CharacterData getOptionResult(int i);

	const string encounterName = "DebugEncounter";
};

//===================================================
//                 COMMON ENCOUNTERS
//===================================================

class UndergraduateEncounter : public Encounter //Common
{
public:
	UndergraduateEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();

	void generateOptions();
	CharacterData getOptionResult(int i);

	const string encounterName = "Undergraduate Encounter";

};

class WeekendEncounter : public Encounter //Common
{
public:
	WeekendEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);

	const string encounterName = "Weekend Encounter";

};

class ProfessorEncounter : public Encounter //Common
{
public:
	ProfessorEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);
};

class VideoGameEncounter : public Encounter 
{
public:
	VideoGameEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);
};

class CancelledClassEncounter : public Encounter
{
public:
	CancelledClassEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);
	int typeRoll;

};

class NoisyNeighborsEncounter : public Encounter
{
public:
	NoisyNeighborsEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);
};

class EmailEncounter : public Encounter //done
{
public:
	EmailEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);
};

class EasyAssigmentEncounter : public Encounter //done
{
public:
	EasyAssigmentEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);
};

class AssignmentSetbackEncounter : public Encounter //incomplete
{
public:
	AssignmentSetbackEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);
};

//===================================================
//               UNCOMMON ENCOUNTERS
//===================================================

class BugEncounter : public Encounter
{
public:
	BugEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);
};


class RefrigeratorEncounter : public Encounter
{
public:
	RefrigeratorEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);

};


class CharityEncounter : public Encounter
{
public:
	CharityEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);

};

class SicknessEncounter : public Encounter //done
{
public:
	SicknessEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);
};

class BrokenNinjaEncounter : public Encounter
{
public:
	BrokenNinjaEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);
};

class MedicalStudentEncounter : public Encounter //done
{
public:
	MedicalStudentEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);
};

class BossRoomEncounter : public Encounter //incomplete
{
public:
	BossRoomEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);
};

class TestEncounter : public Encounter //incomplete
{
public:
	TestEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);
};


//===================================================
//                 RARE ENCOUNTERS
//===================================================

class TheDoctorEncounter : public Encounter //done
{
public:
	TheDoctorEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);
};

class AnomalyEncounter : public Encounter //rare
{
public:
	AnomalyEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);
};

class AlienEncounter : public Encounter //done
{
public:
	AlienEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);
};

class PentagramEncounter : public Encounter // done
{
public:
	PentagramEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);
};

//===================================================
//                 GAME BREAKERS
//===================================================

class CthulhuEncounter : public Encounter //Gamebreaker
{
public:
	CthulhuEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();
	CharacterData getOptionResult(int i);

	const string encounterName = "CthulhuEncounter";


};

class DragonEncounter : public Encounter //incomplete
{
public:
	DragonEncounter(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates);

private:
	void displayEncounter();

	//EncounterResultPackage encounterMechanics(); //Overrides base class encounter mechanics.

	CharacterData getOptionResult(int i);

	const string encounterName = "DragonEncounter\n";

	MenuManagerClass dragonMenu;
	int inflictTerror();
	bool gameOfRiddles();
	CharacterData reward();



};



#endif