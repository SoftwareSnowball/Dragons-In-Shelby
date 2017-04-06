#include "GameInstanceClass.h"

/*
Author: James Malloy
email:	jem0044@tigermail.auburn.edu
id:		903518039

FileName: GameInstanceClass.cpp


See header file for description

*/



GameInstanceClass::GameInstanceClass(MenuManagerClass * inputMenuInterface, ScoreManagerClass * inputScoreInterface)
{
	menuInterface = inputMenuInterface;
	scoreInterface = inputScoreInterface;
	defaultOptions = Options(5);

	defaultOptions.ref(0) = "Move Forward.";
	defaultOptions.ref(1) = "Read technical papers";
	defaultOptions.ref(2) = "Search for loose change";
	defaultOptions.ref(3) = "Pull all nighter";
	defaultOptions.ref(4) = "View character";

	characterInterface = new PlayerCharacterClass();
	encounterInterface = new EncounterManagerClass(menuInterface);
	gameFlags = 0;

	cout << "Welcome to the game!\n";
	cout << "Please enter your name: ";
	cin >> playerName;
	cout << endl;



}

GameInstanceClass::~GameInstanceClass()
{
	clean();
}

flag GameInstanceClass::run()
{

	cout << "\nStarting Game...\n\n";

	cout << endl;

	characterInterface->displayStats();
	cout << endl;

	int input;

	while (gameFlags == 0)
	{

		cout << "You are " << HallLength - characterInterface->getPosition() << " Spaces from the end\n";


		input = menuInterface->DisplayMenu(defaultOptions);

		switch (input)
		{
		case UserExitCode:
			gameFlags = gameFlags | UserExitFlag;
			break;

		case 0:
			moveForward();
			cout << endl;
			break;

		case 1:
			readTechnicalPaper();
			cout << endl;
			break;

		case 2:
			searchForChange();
			cout << endl;
			break;

		case 3:

			pullAllNighter();
			cout << endl;
			break;

		case 4:

			characterInterface->displayStats();
			cout << endl;
			break;

		}


	}

	if (gameFlags & FunctionErrorFlag)
	{
		cout << "Error:\n";
		cout << "The program has encountered a problem and needs to close.\n";

	}
	else if ((gameFlags & VictoryFlag) != 0)
	{
		cout << "Congratulations! You won the game!\n";
		cout << "Yay!\n";
		cout << "Parties!\n";
		cout << "Okay, stop gloating and get back to work.\n";
		cout << endl;

		scoreInterface->addScore(playerName, characterInterface->getScore());
		cout << "Your score is " << characterInterface->getScore();
		cout << endl << endl;
	}
	else if ((gameFlags & DefeatByIntFlag) != 0)
	{
		cout << "You become a blabbering idiot\n";
	}
	else if ((gameFlags & DefeatByMoneyFlag) != 0)
	{
		cout << "Oh, look who's broke.\n";
	}
	else if ((gameFlags & DefeatByTimeFlag) != 0)
	{
		cout << "You die of old age before graduation. So sad.\n";
	}
	else if ((gameFlags & UserExitFlag) != 0)
	{
		cout << "Fine then. Quit, you loser.\n";
	}
	else
	{
		cout << "Something went wrong.\n";
		cout << "Best error message ever.\n";
	}

	cout << "\n\n";


	return gameFlags;
}

bool GameInstanceClass::clean()
{

	if (characterInterface)
	{
		delete characterInterface;
		characterInterface = 0;
	}

	if (encounterInterface)
	{
		delete encounterInterface;
		encounterInterface = 0;
	}


	return true;
}


void GameInstanceClass::moveForward()
{
	gameFlags = gameFlags | characterInterface->affectPosition(1);
	gameFlags = gameFlags | characterInterface->affectStats(CharacterStats(0, 0, -MovementTimeCost));

	EncounterResultPackage result;

	if (gameFlags != 0)
	{
		return;
	}

	cout << endl;
	result = encounterInterface->manageEncounter();

	gameFlags = gameFlags | result.gameFlags;

	CharacterData tempData = result.characterEffects;


	if (gameFlags != 0)
	{
		//cout << "There was a problem in encounterInterface.\n";
		return;
	}

	

	gameFlags = characterInterface->affectCharacterData(tempData);

}


void GameInstanceClass::readTechnicalPaper()
{

	CharacterStats effects = CharacterStats();
	effects.intelligence = rand() % (TechPaperMaxGain + 1);
	effects.time = -TechPaperTimeCost;


	assert(effects.money == 0);
	assert(effects.intelligence >= 0 && effects.intelligence <= TechPaperMaxGain);

	if (effects.intelligence == 0)
	{
		cout << "You seriously thought that would make you smarter?\n";
	}
	else
	{
		cout << "After several hours of reading you feel you understand the universe a little better\n";
		//cout << "You gain " << effects.intelligence << " intelligence\n";
		//cout << "You lose " << effects.time << " units of time\n";
	}


	gameFlags = characterInterface->affectStats(effects);

}

void GameInstanceClass::searchForChange()
{
	CharacterStats effects = CharacterStats();
	effects.money = rand() % (LooseChangeSearchMAXGain + 1);
	effects.time = -LooseChangeSearchTimeCost;

	assert(effects.intelligence == 0);
	assert(effects.money >= 0 && effects.intelligence <= LooseChangeSearchMAXGain);

	if (effects.money == 0)
	{
		cout << "I suppose you could always get lucky, or you could move back into your parents' basement.\n";
	}
	else
	{
		cout << "Desperate times call for desperate measures, but at least you have a bit more spending money\n";
		//cout << "You gained $" << effects.money << endl;
		//cout << "You lose " << effects.time << " units of time\n";
	}

	gameFlags = characterInterface->affectStats(effects);
}

void GameInstanceClass::pullAllNighter()
{

	CharacterStats effects = CharacterStats();

	cout << "It's always rough, but sometimes you just have too much work to finish during the day.\n";
	cout << "Hopefully you can get enough caffeine to get you through the night\n";

	int roll = 1 + (rand() % 5);

	effects.time = roll;

	if (roll < 3)
	{
		cout << "You got bogged down in your work, but you did get a little bit done.\n";
	}
	else
	{
		cout << "You were able to make a fair bit of progress over the night.\n";
	}

	roll = rand() % 6;

	effects.intelligence = -roll;

	cout << endl;
	cout << "Additionally...\n";


	if (roll == 0)
	{
		cout << "Sleep is totally for the weak! You feel fine!\n";
		cout << "...You perfect freak.\n";
	}
	else if (roll == 2)
	{
		cout << "You feel a little tired.\n";
	}
	else if (roll == 3)
	{
		cout << "You feel quite tired and it's having a clear effect.\n";
	}
	else
	{
		cout << "UGH! That was a mistake! Get coffee... now.\n";
		cout << "Must...have...coff...zzzzzzzzzzzzzzzzz\n";
	}

	cout << endl;
	characterInterface->affectStats(effects);

}



