#include "GameInstanceClass.h"

GameInstanceClass::GameInstanceClass(string name, MenuManagerClass * inputMenuInterface, ScoreManagerClass * inputScoreInterface)
{
	menuInterface = inputMenuInterface;
	scoreInterface = inputScoreInterface;

	defaultOptions.ref(0) = "Move Forward.";
	defaultOptions.ref(1) = "Read technical papers";
	defaultOptions.ref(2) = "Search for loose change";
	defaultOptions.ref(3) = "View character";

	characterInterface = new PlayerCharacterClass();
	encounterInterface = new EncounterManagerClass(menuInterface);
	gameFlags = 0;

	playerName = name;

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

		cout << "You are at position " << characterInterface->getPosition() << endl << endl;


		input = menuInterface->DisplayMenu(defaultOptions);

		switch (input)
		{
		case UserExitCode:
			gameFlags = gameFlags | UserExitFlag;
			break;

		case 0:
			cout << endl;
			moveForward();
			break;

		case 1:
			cout << endl;
			readTechnicalPaper();
			break;

		case 2:
			cout << endl;
			searchForChange();
			break;

		case 3:

			characterInterface->displayStats();
			break;

		}

		cout << endl;

	}

	if ((gameFlags & VictoryFlag) != 0)
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

	if (gameFlags != 0)
	{
		return;
	}

	cout << endl;
	gameFlags = encounterInterface->manageEncounter();


	if (gameFlags != 0)
	{
		//cout << "There was a problem in encounterInterface.\n";
		return;
	}

	CharacterData tempData = encounterInterface->giveResults();

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



