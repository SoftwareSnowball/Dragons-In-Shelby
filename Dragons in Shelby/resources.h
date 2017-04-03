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

/*
Bit codes to be used with flag variables. These help
Control program flow

The codes below are only ever assigned to a variable of type flag
and type flag is only ever used with these codes.
*/
#define DefeatByIntFlag 01
#define DefeatByMoneyFlag 02
#define DefeatByTimeFlag 04
#define FunctionErrorFlag 08
#define UserExitFlag 16 //do not confuse with UserExitCode. This is used in variables of type flag.
#define VictoryFlag 32
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

/*
This class is special in that it is not meant to be instantiated directly, but
it is meant to be the parent of all the specific Encounter types in the
game.
*/
class Encounter
{
public:

	Encounter();
	virtual ~Encounter();

	const string encounterName = "Default Encounter";

	virtual void displayEncounter();
	virtual Options giveOptions();
	virtual CharacterData getOptionResult(int i);


protected:

	Options opts;
	string encounterInfo;

};


struct ScoreContainer
{
	ScoreContainer();
	ScoreContainer(string inputName, int inputScore);

	string name;
	int score;
};


#endif
