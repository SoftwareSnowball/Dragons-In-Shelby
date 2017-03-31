#ifndef RESOURCES_H
#define RESOURCES_H

#include <iostream>
#include <cassert>
#include <string>

using std::string;

#define VictoryExitCode -4
#define DefeatExitCode -3
#define UserExitCode -2
#define ErrorExitCode -1


struct StatValues {

	int intelligence;
	int money;
	int time;

};

struct Options {
	string options[7];
	int NumOfOptions;
};




#endif
