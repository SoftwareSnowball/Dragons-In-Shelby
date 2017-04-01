#ifndef _MENU_MANAGER_CLASS_H
#define _MENU_MANAGER_CLASS_H

#include "resources.h"

class MenuManagerClass
{
public:
	MenuManagerClass();
	~MenuManagerClass();

	int DisplayMainMenu();
	int DisplayMenu(Options set);
private:

	void WriteOptionSet(Options set);
	void WriteOptionSet(Options set, int j);
	int ProcessInput(int OptNum);

	Options mainMenu = Options(3);
	Options exitOption = Options(1);
};

#endif
