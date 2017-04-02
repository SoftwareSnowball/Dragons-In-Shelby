#ifndef _SCORE_MANAGER_CLASS_H
#define _SCORE_MANAGER_CLASS_H

#include "resources.h"

class ScoreManagerClass
{
public:
	ScoreManagerClass();
	~ScoreManagerClass();

	void addScore(string name, int score);
	void outputScores();


private:

	bool readScores();
	bool writeScores();
	void shiftDown(int i);
	ScoreContainer scores[10];

	char fileName[20] = "Scores.txt";

};






#endif