/*
Author : James Malloy
email : jem0044@tigermail.auburn.edu
id : 903518039


This files should contain all the specific encounter type which inherit from the Encounter class.
This is where all the fun gets defined.
*/

#ifndef _ENCOUNTERS_H
#define _ENCOUNTERS_H

#include "resources.h"




class DebugEncounter : public Encounter //debug
{
public:
	DebugEncounter();
	void displayEncounter();
	CharacterData getOptionResult(int i);

	const string encounterName = "DebugEncounter";
};


class CthulhuEncounter : public Encounter //Gamebreaker
{
public:
	CthulhuEncounter();
	void displayEncounter();
	CharacterData getOptionResult(int i);

	const string encounterName = "CthulhuEncounter";


};

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

class TheDoctorEncounter : public Encounter //Rare NOT IMPLEMENTED
{
public:
	TheDoctorEncounter();
	void displayEncounter();
	CharacterData getOptionResult(int i);
};

class AnomalyEncounter : public Encounter //rare Breaker
{
public:
	AnomalyEncounter();
	void displayEncounter();
	CharacterData getOptionResult(int i);
};


class ProfessorEncounter : public Encounter //Common
{
public:
	ProfessorEncounter();
	void displayEncounter();
	CharacterData getOptionResult(int i);
};


class BugEncounter : public Encounter //rare
{
public:
	BugEncounter();
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

#endif