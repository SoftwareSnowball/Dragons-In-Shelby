/*
Author : James Malloy
email : jem0044@tigermail.auburn.edu
id : 903518039


Filename: GameInstanceClass.h

This file contains the game instance which controls the game logic
and the primary game loop. It also calls the score manager if necessary
to record player high scores.

*/


#ifndef _GAME_INSTANCE_CLASS_H
#define _GAME_INSTANCE_CLASS_H

#include "resources.h"
#include "MenuManagerClass.h"
#include "EncounterManagerClass.h"
#include "PlayerCharacterClass.h"
#include "ScoreManagerClass.h"

class GameInstanceClass
{
public:
	GameInstanceClass(string name, MenuManagerClass * inputMenuInterface, ScoreManagerClass * inputScoreInterface);
	~GameInstanceClass(); 

	flag run();
	bool clean();



private:

	void moveForward();
	void readTechnicalPaper();
	void searchForChange();


	MenuManagerClass * menuInterface;
	ScoreManagerClass * scoreInterface;
	PlayerCharacterClass * characterInterface;
	EncounterManagerClass * encounterInterface;

	flag gameFlags = 0;

	int score;

	Options defaultOptions = Options(4);
	
	string playerName;


};

#endif