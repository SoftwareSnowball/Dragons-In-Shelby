#ifndef RESOURCES_H
#define RESOURCES_H

#include <iostream>
#include <cassert>
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
typedef unsigned short int flag;

#define StartIntRange 10 //Defines the difference between the max start intelligence and the minimum start intelligence
#define MinStartInt 10

#define StartMoneyRange 10
#define MinStartMoney 10

#define StartTimeRange 20
#define MinStartTime 10

//Used in menu situations
#define VictoryExitCode -4
#define DefeatExitCode -3
#define UserExitCode -2 //This is used in type int returns from functions that take user inputs.
#define ErrorExitCode -1




#define MaxOptions 8

struct CharacterStats {

	int intelligence = 0;
	int money = 0;
	int time = 0;

};


struct Options 
{
public:
	char opt1[100] = "";
	char opt2[100] = ""; //herp derp
	char opt3[100] = "";
	char opt4[100] = "";
	char opt5[100] = "";
	char opt6[100] = "";
	char opt7[100] = "";

	int optsUsed = 0;

};

class Encounter
{
public:

	Encounter();
	~Encounter();

	const char encounterName[40] = "Default Encounter";

	void diplayEncounter();
	Options giveOptions();
	CharacterStats getOptionResult(int i);


protected:

	Options encounterOptions;

};


#endif
