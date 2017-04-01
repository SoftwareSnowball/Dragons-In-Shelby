#include "resources.h"

Options::Options()
{
	Options(1);
}

Options::Options(int i)
{
	assert(i > 0 && i <= MaxOptions);

	NumOfOptions = i;

}

Options::~Options()
{
}

string & Options::ref(int i)
{
	assert(i >= 0 && i < NumOfOptions);
	return options[i];
}

int Options::giveNumOfOptions()
{
	return NumOfOptions;
}



Encounter::Encounter()
{
	encounterOptions = Options(1);
	encounterOptions.ref(0) = "There are no choices here";
	encounterName = "default encounter";
}

Encounter::~Encounter()
{
}

void Encounter::diplayEncounter()
{
	cout << "This is a default encounter\n";
}

Options Encounter::giveOptions()
{
	return encounterOptions;
}

CharacterData Encounter::getOptionResult(int i)
{
	return CharacterData();
}
