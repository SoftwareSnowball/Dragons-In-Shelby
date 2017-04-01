#ifndef _PLAYER_CHARACTER_CLASS_H
#define _PLAYER_CHARACTER_CLASS_H


#include "resources.h"


class PlayerCharacterClass
{
public:
	PlayerCharacterClass();
	~PlayerCharacterClass();

	flag affectStats(CharacterStats offset); //Adds the values of offset to myStats
	void displayStats();
	CharacterStats giveStats();


private:
	CharacterStats myStats;




};

#endif