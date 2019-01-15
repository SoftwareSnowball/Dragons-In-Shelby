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

	num_options = i;

}

Options::~Options()
{
}

string & Options::ref(int i)
{
	assert(i >= 0 && i < num_options);
	return options[i];
}

int Options::giveNumOfOptions()
{
	return num_options;
}

void Options::append(const string& input)
{
	assert(num_options <= MaxOptions);

	options[num_options] = string(input);
	num_options++;
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
