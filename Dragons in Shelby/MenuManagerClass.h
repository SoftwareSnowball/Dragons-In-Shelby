#ifndef _MENU_MANAGER_CLASS_H
#define _MENU_MANAGER_CLASS_H

#include "resources.h"

class MenuManagerClass
{
public:
	MenuManagerClass();
	~MenuManagerClass();

	int DisplayMainMenu();
	int DisplayMenu(Options choices);
private:

	Options mainMenu = Options(3);
	Options defaultOptions = Options(1);
};

#endif
