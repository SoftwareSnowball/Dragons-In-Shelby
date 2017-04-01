#include "PlayerCharacterClass.h"



PlayerCharacterClass::PlayerCharacterClass()
{

	myStats.intelligence = MinStartInt + rand() % (StartIntRange + 1);
	myStats.money = MinStartMoney + rand() % (StartMoneyRange + 1);
	myStats.time = MinStartTime + rand() % (StartTimeRange + 1);

}


PlayerCharacterClass::~PlayerCharacterClass()
{
}

flag PlayerCharacterClass::affectStats(CharacterStats offset)
{
	
	myStats.intelligence += offset.intelligence;
	myStats.money += offset.money;
	myStats.time += offset.time;


	flag statusFlags = 0;

	if (myStats.intelligence <= 0)
	{
		statusFlags = statusFlags | DefeatByIntFlag;
	}

	if (myStats.money <= 0)
	{
		statusFlags = statusFlags | DefeatByMoneyFlag;
	}

	if (myStats.time <= 0)
	{
		statusFlags = statusFlags | DefeatByTimeFlag;
	}


	return statusFlags; //I've spent way too much time in assembly

}

void PlayerCharacterClass::displayStats()
{
	cout << "You have...\n";
	cout << "intelligence: " << myStats.intelligence << endl;
	cout << "time: " << myStats.time << endl;
	cout << "money: " << myStats.money << endl;

}

CharacterStats PlayerCharacterClass::giveStats()
{
	return myStats;
}
