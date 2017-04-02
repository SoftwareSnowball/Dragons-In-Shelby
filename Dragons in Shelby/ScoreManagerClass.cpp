#include "ScoreManagerClass.h"



ScoreManagerClass::ScoreManagerClass()
{
	for (int i = 0; i < 10; i++)
	{
		scores[i] = ScoreContainer();
	}
}


ScoreManagerClass::~ScoreManagerClass()
{
}

void ScoreManagerClass::addScore(string name, int score)
{
}

void ScoreManagerClass::outputScores()
{

	cout << "The top ten high scores are...\n";

	for (int i = 0; i < 10; i++)
	{

		cout << i + 1 << ") " << scores[i].name << "	" << scores[i].score << endl;

	}


}

void ScoreManagerClass::readScores()
{
}
