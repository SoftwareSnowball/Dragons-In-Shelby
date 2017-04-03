/*
Author : James Malloy
email : jem0044@tigermail.auburn.edu
id : 903518039

fileName: ScoreManager.h

This file contains the ScoreManagerClass which displays user high scores,
adds high scores to a list on file, and can read scores from file.

*/

#ifndef _SCORE_MANAGER_CLASS_H
#define _SCORE_MANAGER_CLASS_H

#include "resources.h"

class ScoreManagerClass
{
public:
	ScoreManagerClass();
	ScoreManagerClass(string fileNameOverride);
	~ScoreManagerClass();

	void addScore(string name, int score);
	void outputScores();


private:

	bool readScores();
	bool writeScores();
	void shiftDown(int i);
	ScoreContainer * scores;

	string fileName;

//	char fileName[20] = "Scores.txt";

};






#endif