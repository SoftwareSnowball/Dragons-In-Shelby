// Main.cpp : Defines the entry point for the console application.
//

#ifdef _WIN32
#include "stdafx.h"
#endif

#include "resources.h"
#include "MenuManagerClass.h"

int main()
{


	//MenuManagerClass pMenu = MenuManagerClass();

	//pMenu.DisplayMainMenu();

	Options * test = new Options(1);
	test->ref(0) = "HI";

	delete test;


	int hold;
	std::cin >> hold;


    return 0;
}

