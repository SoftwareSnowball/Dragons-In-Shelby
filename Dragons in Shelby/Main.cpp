/*

Sources:
http://www.cprogramming.com/tutorial/bitwise_operators.html
https://msdn.microsoft.com/en-us/library/cc953fe1.aspx
http://www.cplusplus.com/reference/cstdlib/rand/

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

	Options stuff = Options(1);
	stuff.ref(0) = "Insert comment here";
	

	MenuManagerClass * pmenu = new MenuManagerClass();

	EncounterManagerClass * ehandle = new EncounterManagerClass(pmenu);


	ehandle->manageEncounter();




	


	delete pmenu;

	delete ehandle;
	

	int hold;
	std::cin >> hold;


    return 0;
}

