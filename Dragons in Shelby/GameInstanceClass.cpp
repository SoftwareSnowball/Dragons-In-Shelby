#include "GameInstanceClass.h"

GameInstanceClass::GameInstanceClass(MenuManagerClass * inputMenuInterface, ScoreManagerClass * inputScoreInterface)
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
	int score = 0;

}

GameInstanceClass::~GameInstanceClass()
{
	clean();
}

flag GameInstanceClass::run()
{

	cout << "\nStarting Game...\n\n";

	characterInterface->displayStats();
	cout << endl;

	int input;
	CharacterData temp;

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
			gameFlags = gameFlags | characterInterface->affectPosition(1);

			if (gameFlags != 0)
			{
				break;
			}

			gameFlags = gameFlags | encounterInterface->manageEncounter();

			if (gameFlags != 0)
			{
				cout << "There was a problem in encounterInterface.\n";
				break;
			}

			temp = encounterInterface->giveResults();

			gameFlags = gameFlags | characterInterface->affectCharacterData(temp);
			break;

		case 1:
			cout << "You seriously thought that would make you any smarter?\n";
			break;

		case 2:

			cout << "I suppose you could always get lucky, or you could move back into your parents basement.\n";
			break;

		case 3:

			characterInterface->displayStats();
			break;

		}


	}


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
