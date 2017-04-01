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
	GameInstanceClass(MenuManagerClass * inputMenuInterface, ScoreManagerClass * inputScoreInterface);
	~GameInstanceClass(); 

	flag run();
	bool clean();

private:

	MenuManagerClass * menuInterface;
	ScoreManagerClass * scoreInterface;
	PlayerCharacterClass * characterInterface;
	EncounterManagerClass * encounterInterface;

	flag gameFlags = 0;

	int score;

	Options defaultOptions = Options(4);


};

#endif