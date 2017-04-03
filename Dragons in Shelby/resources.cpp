#include "resources.h"

/*
Author: James Malloy
email:	jem0044@tigermail.auburn.edu
id:		903518039

FileName: resources.cpp


See header file for description

*/

CharacterStats::CharacterStats()
{

	intelligence = 0;
	money = 0;
	time = 0;

}

CharacterStats::CharacterStats(int inputInt, int inputMoney, int inputTime)
{
	intelligence = inputInt;
	money = inputMoney;
	time = inputTime;
}

CharacterData Encounter::getOptionResult(int i)
{
	return CharacterData();
}

CharacterData::CharacterData()
{

	CharacterData(CharacterStats(), 0);

}

CharacterData::CharacterData(CharacterStats inputStats, int inputPosition)
{
	stats = inputStats;
	position = inputPosition;
}


Options::Options()
{
	Options(1);
}

Options::Options(int i)
{
	assert(i > 0 && i <= MaxOptions);

	NumOfOptions = i;

}

Options::~Options()
{
}

string & Options::ref(int i)
{
	assert(i >= 0 && i < NumOfOptions);
	return options[i];
}

int Options::giveNumOfOptions()
{
	return NumOfOptions;
}



Encounter::Encounter()
{
	opts = Options(1);

	encounterInfo = "This is a default encounter\n";
	encounterInfo += "Like seriously you shouldn't even be able to see this\n";
	opts.ref(0) = "There are no choices here";
}

Encounter::~Encounter()
{
}

void Encounter::displayEncounter()
{
	cout << encounterInfo;
}

Options Encounter::giveOptions()
{
	return opts;
}

ScoreContainer::ScoreContainer()
{

	name = "empty";
	score = 0;

}

ScoreContainer::ScoreContainer(string inputName, int inputScore)
{

	name = inputName;
	score = inputScore;


}
