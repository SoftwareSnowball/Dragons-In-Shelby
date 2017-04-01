#ifndef RESOURCES_H
#define RESOURCES_H

#include <iostream>
#include <cassert>
#include <string>
#include <random>
#include <time.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

#define DefeatByIntFlag 01
#define DefeatByMoneyFlag 02
#define DefeatByTimeFlag 04
#define FunctionErrorFlag 08
#define UserExitFlag 16 //do not confuse with UserExitCode. This is used in variables of type flag.
#define VictoryFlag 32
typedef unsigned short int flag;

#define StartIntRange 10 //Defines the difference between the max start intelligence and the minimum start intelligence
#define MinStartInt 10

#define StartMoneyRange 10
#define MinStartMoney 10

#define StartTimeRange 20
#define MinStartTime 10

#define HallLength 20

//Used in menu situations
#define UserExitCode -2 //This is used in type int returns from functions that take user inputs.
#define ErrorExitCode -1


#define MaxOptions 8

struct CharacterStats 
{

	int intelligence;
	int money;
	int time;

};

struct CharacterData
{

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

class Encounter
{
public:

	Encounter();
	~Encounter();

	string encounterName;

	void diplayEncounter();
	Options giveOptions();
	CharacterData getOptionResult(int i);


protected:

	Options encounterOptions;

};


#endif
