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
//===================================================
//                 DEBUG ENCOUNTERS
//===================================================
class DebugEncounter : public Encounter //debug
{
public:
	DebugEncounter();
	void displayEncounter();
	CharacterData getOptionResult(int i);

	const string encounterName = "DebugEncounter";
};

//===================================================
//                 COMMON ENCOUNTERS
//===================================================

class UndergraduateEncounter : public Encounter //Common
{
public:
	UndergraduateEncounter();
	void displayEncounter();
	CharacterData getOptionResult(int i);

	const string encounterName = "Undergraduate Encounter";

};

class WeekendEncounter : public Encounter //Common
{
public:
	WeekendEncounter();
	void displayEncounter();
	CharacterData getOptionResult(int i);

	const string encounterName = "Weekend Encounter";

};

class ProfessorEncounter : public Encounter //Common
{
public:
	ProfessorEncounter();
	void displayEncounter();
	CharacterData getOptionResult(int i);
};

class VideoGameEncounter : public Encounter //common NOT IMPLEMENTED
{
public:
	VideoGameEncounter();
	void displayEncounter();
	CharacterData getOptionResult(int i);
};



//===================================================
//               UNCOMMON ENCOUNTERS
//===================================================


class BugEncounter : public Encounter //rare
{
public:
	BugEncounter();
	void displayEncounter();
	CharacterData getOptionResult(int i);
};



//===================================================
//                 RARE ENCOUNTERS
//===================================================

class TheDoctorEncounter : public Encounter //Rare NOT IMPLEMENTED
{
public:
	TheDoctorEncounter();
	void displayEncounter();
	CharacterData getOptionResult(int i);
};

class AnomalyEncounter : public Encounter //rare
{
public:
	AnomalyEncounter();
	void displayEncounter();
	CharacterData getOptionResult(int i);
};


//===================================================
//                 GAME BREAKERS
//===================================================

class CthulhuEncounter : public Encounter //Gamebreaker
{
public:
	CthulhuEncounter();
	void displayEncounter();
	CharacterData getOptionResult(int i);

	const string encounterName = "CthulhuEncounter";


};




















#endif