#ifndef _ENCOUNTERS_H
#define _ENCOUNTERS_H

#include "resources.h"


/*
This files should contain all the specific encounter type which inherit from the Encounter class.
*/

class DebugEncounter : public Encounter
{
public:
	DebugEncounter();
	void displayEncounter();
	CharacterData getOptionResult(int i);

	const string encounterName = "DebugEncounter";
};


class CthulhuEncounter : public Encounter
{
public:
	CthulhuEncounter();
	void displayEncounter();
	CharacterData getOptionResult(int i);

	const string encounterName = "CthulhuEncounter";


};






#endif