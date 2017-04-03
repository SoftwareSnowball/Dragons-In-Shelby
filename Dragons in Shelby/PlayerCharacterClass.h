/*
Author : James Malloy
email : jem0044@tigermail.auburn.edu
id : 903518039

fileName: PlayerCharacterClass.h


This is a small container for all of the player information.
*/


#ifndef _PLAYER_CHARACTER_CLASS_H
#define _PLAYER_CHARACTER_CLASS_H


#include "resources.h"


class PlayerCharacterClass
{
public:
	PlayerCharacterClass();
	~PlayerCharacterClass();

	flag affectCharacterData(CharacterData input);
	flag affectStats(CharacterStats offset); //Adds the values of offset to myStats
	flag affectPosition(int input);

	void displayStats();
	CharacterStats giveStats();
	int getPosition();
	int getScore();





private:
	CharacterStats myStats;
	int position;




};

#endif