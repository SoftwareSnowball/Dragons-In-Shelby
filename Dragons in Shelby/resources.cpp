#include "resources.h"

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
	encounterOptions.ref(0) = "There are no choices here\n";
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

CharacterStats Encounter::getOptionResult(int i)
{
	return CharacterStats();
}
