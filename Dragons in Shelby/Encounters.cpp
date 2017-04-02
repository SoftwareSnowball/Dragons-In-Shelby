#include "Encounters.h"

// DEBUG ENCOUNTER

DebugEncounter::DebugEncounter()
{

	opts = Options(7);

	opts.ref(0) = "Do nothing";
	opts.ref(1) = "Teleport backwards";
	opts.ref(2) = "Kill all stats";
	opts.ref(3) = "Kill by int";
	opts.ref(4) = "kill by money";
	opts.ref(5) = "kill by time";
	opts.ref(6) = "jump to end";


}

void DebugEncounter::displayEncounter()
{
	cout << "Here we have a debug encounter thing.\n";
	cout << "It does stuff.\n\n";
}

CharacterData DebugEncounter::getOptionResult(int i)
{
	cout << i;
	switch (i)
	{
	case 0:
		return CharacterData(CharacterStats(), 0);
		break;	
	case 1:
		return CharacterData(CharacterStats(), -1);
		break;
	case 2:
		return CharacterData(CharacterStats(-100, -100, -100), 0);
		break;
	case 3:
		return CharacterData(CharacterStats(-100, 0, 0), 0);
		break;
	case 4:
		return CharacterData(CharacterStats(0, -100, 0), 0);
		break;
	case 5:
		return CharacterData(CharacterStats(0, 0, -100), 0);
		break;
	case 6:
		return CharacterData(CharacterStats(), HallLength);
		break;
	}


}

// CTHULHU ENCOUNTER

CthulhuEncounter::CthulhuEncounter()
{

	opts = Options(4);

	opts.ref(0) = "Look at his face for a while";
	opts.ref(1) = "Nope... Just nope. I'm out";
	opts.ref(2) = "I will try to reason with it";
	opts.ref(3) = "Throw money at it";

}

void CthulhuEncounter::displayEncounter()
{

	cout << "A dark fiend has arisen! This evil creature will sap all your sanity\n";
	cout << "FEAR MORTAL FOR CTHULHU HAS COME TO CLAIM YOUR SOUL!\n\n";
	cout << "...Or maybe he's just here for tea. You never know about these things.\n";


}

CharacterData CthulhuEncounter::getOptionResult(int i)
{
	CharacterStats stats = CharacterStats();
	int position = 0;
	int roll = 0;

	switch (i)
	{
	case 0:
		cout << "You really thought that was a good idea?\n";
		stats.intelligence = -10000000;
		break;

	case 1:

		roll = rand() % 2;

		if (roll == 1)
		{
			cout << "You retreat back to your previous position\n";
			cout << "Let someone else deal with the fiend\n";
			position = -1;
			stats.time = -2;
		}
		else
		{
			cout << "You flee in terror. You don't think you'll ever be the same.\n";
			stats.time = -3;
			stats.intelligence = -5;
			position = -1;
		}
		break;

	case 2:

		roll = rand() % 100;

		if (roll == 99)
		{
			cout << "It turns out that Cthulu is really a nice guy after all.\n";
			cout << "He's actually a small business owner and is looking to promote academics and learning\n";
			cout << "He decides to give you a small scholarship to help you through school\n";
			stats.intelligence = 10;
			stats.money = 50;
		}
		else
		{
			cout << "Great. Reason with pure insanity. That was clearly a good idea\n";
			stats.intelligence = -1000000;
		}

		break;

	case 3:

		cout << "Ummm... what?\n";
		stats.money = -5;

	}



	return CharacterData(stats, position);
}
