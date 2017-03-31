#ifndef RESOURCES_H
#define RESOURCES_H

#include <iostream>
#include <cassert>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

#define VictoryExitCode -4
#define DefeatExitCode -3
#define UserExitCode -2
#define ErrorExitCode -1


struct StatValues {

	int intelligence;
	int money;
	int time;

};

class Options {
public:
	Options(int i);
	~Options();
	string& ref(int i);
	int giveNumOfOptions();

private:
	string * options;
	int NumOfOptions;
};




#endif
