#include "resources.h"


Encounter::Encounter()
{
	encounterOptions.opt1 = "There are no choices here\n";
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
