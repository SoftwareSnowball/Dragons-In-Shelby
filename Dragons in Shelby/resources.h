#ifndef RESOURCES_H
#define RESOURCES_H
/*
Author: James Malloy
email:	jem0044@tigermail.auburn.edu
id:		903518039

FileName: resources.h
This file contains most of the library includes that are used in the
rest of the program. Additionally it contains several definitions
for flag values used by the program logic. After that are definitions
used to determine game rules and then a few classes and structs to
help the other classes to run smoothly.

In short this is something of a catch all file.
*/

//Toggles for debug behavior


//Initial includes and housekeeping shenanigans
#include <iostream>
#include <cassert>
#include <string>
#include <random>
#include <time.h>
#include <fstream>

using std::ifstream;
using std::ofstream;

using std::string;
using std::cout;
using std::cin;
using std::endl;


#define DEBUG_MODE 1


/*
Bit codes to be used with flag variables. These help
Control program flow

The codes below are only ever assigned to a variable of type flag
and type flag is only ever used with these codes or with a
persistent state code. (Persistent state flags can be used as arguents
to affect the function of an encounter and such. They are defined in the
context of the encounter they affect.)
*/
#define DefeatByIntFlag 1
#define DefeatByMoneyFlag 2
#define DefeatByTimeFlag 4
#define FunctionErrorFlag 8
#define UserExitFlag 16 //do not confuse with UserExitCode. This is used in variables of type flag.
#define VictoryFlag 32
#define FunctionNotImplemented 64
typedef unsigned short int flag;


//A few extra codes used in menu situations
//These codes are only assigned to int. Never type flag.
#define UserExitCode -2 
#define ErrorExitCode -1



/*
The codes in this section are used to define the behavior
and balance of certain game mechanics.
*/


// Affects PlayerCharacter stat generation
#define StartIntRange 10 //Defines the difference between the max start intelligence and the minimum start intelligence
#define MinStartInt 10

#define StartMoneyRange 10
#define MinStartMoney 10

#define StartTimeRange 20
#define MinStartTime 15


#define MovementTimeCost 2

//defines read tech paper behavior
#define TechPaperTimeCost 2
#define TechPaperMaxGain 6

//defines loose change search behavior
#define LooseChangeSearchTimeCost 2
#define LooseChangeSearchMAXGain 6


//Controls number of spaces character has to move to win.
#define HallLength 20

//Control the maximum number of options that the Options class can hold.
#define MaxOptions 8




//These are a few classes and structs to make life easier.
struct CharacterStats 
{
	CharacterStats();
	CharacterStats(int inputInt, int inputMoney, int inputTime);


	int intelligence;
	int money;
	int time;

};

struct CharacterData
{
	CharacterData();
	CharacterData(CharacterStats inputStats, int inputPosition);

	CharacterStats stats;

	int position;


	//added in the encounter rework update. Will be used 
	//when I update the player character and add in different difficulties.
	int intelligenceGainRate;
	int timeGainRate;
	int moneyGainRate;

	int intelligenceLossRate;
	int timeLossRate;
	int moneyLossRate;
};

//Added in the encounter rework update
struct EncounterResultPackage
{

	CharacterData characterEffects;
	flag gameFlags;


};


class Options 
{
public:
	Options();
	Options(int i);
	~Options();
	string& ref(int i);
	int giveNumOfOptions();

private:
	string options[MaxOptions];
	int NumOfOptions;
};


struct ScoreContainer
{
	ScoreContainer();
	ScoreContainer(string inputName, int inputScore);

	string name;
	int score;
};


#endif
