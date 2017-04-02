/*

Sources:
https://msdn.microsoft.com/en-us/library/cc953fe1.aspx
http://www.cprogramming.com/tutorial/bitwise_operators.html
http://www.cplusplus.com/reference/cstdlib/rand/
http://stackoverflow.com/questions/134731/returning-a-const-reference-to-an-object-instead-of-a-copy
http://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const
http://stackoverflow.com/questions/8280023/does-a-c-struct-have-a-default-constructor
https://www.visualstudio.com/en-us/docs/git/tutorial/merging
https://www.tutorialspoint.com/cplusplus/cpp_arrays.htm
http://www.cprogramming.com/tutorial/lesson9.html
http://stackoverflow.com/questions/3323675/c-fastest-method-to-return-a-c-string
http://stackoverflow.com/questions/4847100/c-inheritance-inaccessible-base
http://www.studytonight.com/cpp/virtual-functions.php

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


	while (i != UserExitCode)
	{
		i = menuInterface->DisplayMainMenu();

		if (i == 0)
		{

			gameInstance = new GameInstanceClass(menuInterface, scoreInterface);
			gameInstance->run();
			gameInstance->clean();
			delete gameInstance;
			gameInstance = 0;

		}
		else if (i == 1)
		{
			cout << "High scores are not yet implemented\n";
		}

		cout << endl;
	}


	delete menuInterface;
	


    return 0;
}

