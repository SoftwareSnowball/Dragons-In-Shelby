#include "resources.h"

Options::Options(int i)
{
	assert(i > 0);

	NumOfOptions = i;

	options = new string[i];

}

Options::~Options()
{
	delete[] options;
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
