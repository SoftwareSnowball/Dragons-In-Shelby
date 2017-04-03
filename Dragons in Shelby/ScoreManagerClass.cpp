#include "ScoreManagerClass.h"


ScoreManagerClass::ScoreManagerClass()
{


	scores = new ScoreContainer[10]();

	for (int i = 0; i < 10; i++)
	{
		scores[i] = ScoreContainer();
	}

	fileName = "Scores.txt";

}

ScoreManagerClass::ScoreManagerClass(string fileNameOverride)
{


	scores = new ScoreContainer[10]();

	for (int i = 0; i < 10; i++)
	{
		scores[i] = ScoreContainer();
	}

	fileName = fileNameOverride;
}


ScoreManagerClass::~ScoreManagerClass()
{

	delete[] scores;

}

void ScoreManagerClass::addScore(string name, int score)
{

	readScores();

	if (score <= scores[9].score)
	{
		return;
	}

	ScoreContainer addedScore = ScoreContainer(name, score);


	cout << "Congratulations! You made one of the top 10 high scores!\n";

	

	int i = 9;

	while (i >= 0 && score > scores[i].score)
	{
		i--;
	}

	i++;

	shiftDown(i);
	scores[i] = addedScore;

	writeScores();

}

void ScoreManagerClass::outputScores()
{

	readScores();

	cout << endl;
	cout << "The top ten high scores are...\n\n";

	for (int i = 0; i < 10; i++)
	{

		if (scores[i].score == 0)
		{
			cout << "There are no more scores to show.\n";
			break;
		}

		cout.width(2);
		cout << std::left << i + 1 << ") ";
		cout.width(20);
		cout << std::left << scores[i].name << "     ";
		cout << scores[i].score << endl;

	}

	cout << endl;

}

bool ScoreManagerClass::readScores()
{


	ifstream reader;

	reader.open(fileName.c_str());


	if (reader.fail())
	{
		reader.close();
		return false;
	}


	for (int i = 0; i < 10; i++)
	{


		reader >> scores[i].name;
		reader >> scores[i].score;


	}


	reader.close();
	return true;

}

bool ScoreManagerClass::writeScores()
{

	ofstream writer;
	writer.open(fileName.c_str());

	if (writer.fail())
	{
		writer.close();
		return false;
	}


	for (int i = 0; i < 10; i++)
	{

		writer << scores[i].name << endl;
		writer << scores[i].score << endl;

	}



	writer.close();
	return true;
}

void ScoreManagerClass::shiftDown(int i)
{


	if (i < 0 || i > 9)
	{
		return;
	}

	
	scores[9] = scores[8];

	for (int k = 8; k > i; k--)
	{
		scores[k] = scores[k - 1];

	}


	scores[i] = ScoreContainer("Temp", -1);

}
