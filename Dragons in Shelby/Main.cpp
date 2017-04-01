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
#include "GameInstanceClass.h"
#include "ScoreManagerClass.h"

int main()
{

	srand(time(0));

	int i = 0;

	MenuManagerClass * menuInterface = new MenuManagerClass();
	GameInstanceClass * gameInstance = 0;
	ScoreManagerClass * scoreInterface = 0; //fluffy


	while (i == 0)
	{

		i = menuInterface->DisplayMainMenu();

		if (i == 0)
		{

			gameInstance = new GameInstanceClass(menuInterface, scoreInterface);
			gameInstance->run();
			gameInstance->clean();

		}

	}


	delete menuInterface;
	


    return 0;
}

