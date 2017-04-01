/*

Sources:
http://www.cprogramming.com/tutorial/bitwise_operators.html
https://msdn.microsoft.com/en-us/library/cc953fe1.aspx
http://www.cplusplus.com/reference/cstdlib/rand/
https://www.tutorialspoint.com/cplusplus/cpp_arrays.htm
*/

#ifdef _WIN32
#include "stdafx.h"
#endif

#include "resources.h"
#include "MenuManagerClass.h"
#include "PlayerCharacterClass.h"
#include "EncounterManagerClass.h"

int main()
{

	srand(time(NULL));

	//MenuManagerClass * menuInterface = new MenuManagerClass();

	//EncounterManagerClass * encounterInterface = new EncounterManagerClass(menuInterface);

	//encounterInterface->manageEncounter();


	int hold;
	std::cin >> hold;


    return 0;
}

