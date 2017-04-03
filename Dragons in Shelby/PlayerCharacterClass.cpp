#include "PlayerCharacterClass.h"

/*
Author: James Malloy
email:	jem0044@tigermail.auburn.edu
id:		903518039

FileName: PlayerCharacterClass.cpp


See header file for description

*/

PlayerCharacterClass::PlayerCharacterClass()
{

	myStats.intelligence = MinStartInt + rand() % (StartIntRange + 1);
	myStats.money = MinStartMoney + rand() % (StartMoneyRange + 1);
	myStats.time = MinStartTime + rand() % (StartTimeRange + 1);

	position = 0;

}


PlayerCharacterClass::~PlayerCharacterClass()
{
}

flag PlayerCharacterClass::affectCharacterData(CharacterData input)
{

	flag statusFlags = affectStats(input.stats);

	statusFlags = statusFlags | affectPosition(input.position);

	return statusFlags;
}

flag PlayerCharacterClass::affectStats(CharacterStats offset)
{
	
	myStats.intelligence += offset.intelligence;
	myStats.money += offset.money;
	myStats.time += offset.time;


	if (offset.intelligence > 0)
	{
		cout << "You gain " << offset.intelligence << " intelligence points\n";
	}
	else if (offset.intelligence < 0)
	{
		cout << "You lose " << -offset.intelligence << " intelligence points\n";
	}

	if (offset.money > 0)
	{
		cout << "You gain $" << offset.money << endl;
	}
	else if (offset.money < 0)
	{
		cout << "You lose $" << -offset.money << endl;
	}

	if (offset.time > 0)
	{
		cout << "You gain " << offset.time << " units of time\n";
	}
	else if (offset.time < 0)
	{
		cout << "You lose " << -offset.time << " units of time\n";
	}

	if (offset.time == 0 && offset.money == 0 && offset.intelligence == 0)
	{
		//cout << "You're stats are unaffected\n";
	}



	flag statusFlags = 0;

	if (myStats.intelligence <= 0)
	{
		myStats.intelligence = 0;
		statusFlags = statusFlags | DefeatByIntFlag;
	}

	if (myStats.money <= 0)
	{
		myStats.money = 0;
		statusFlags = statusFlags | DefeatByMoneyFlag;
	}

	if (myStats.time <= 0)
	{
		myStats.time = 0;
		statusFlags = statusFlags | DefeatByTimeFlag;
	}


	return statusFlags; //I've spent way too much time in assembly

}

flag PlayerCharacterClass::affectPosition(int input)
{

	position += input;

	if (input == 1)
	{
		cout << "You move forward one space.\n";
	}
	else if (input > 0)
	{
		cout << "You move forward " << input << " spaces\n";
	}

	if (input < 0)
	{
		cout << "You move backward " << input << " spaces\n";
	}


	flag statusFlags = 0;

	if (position < 0)
	{
		position = 0;
	}

	if (position >= HallLength)
	{
		statusFlags = statusFlags | VictoryFlag;
	}

	return statusFlags;
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

int PlayerCharacterClass::getPosition()
{
	return position;
}

int PlayerCharacterClass::getScore()
{
	return myStats.intelligence * myStats.money * myStats.time;
}


