#include "Encounters.h"
/*

Author: James Malloy
email:	jem0044@tigermail.auburn.edu
id:		903518039

FileName: Encounters.cpp


See header file for description


*/

//===================================================
//                 DEBUG ENCOUNTERS
//===================================================

DebugEncounter::DebugEncounter()
{

	opts = Options(7);

	opts.ref(0) = "Do nothing";
	opts.ref(1) = "Teleport backwards";
	opts.ref(2) = "Kill all stats";
	opts.ref(3) = "Kill by int";
	opts.ref(4) = "kill by money";
	opts.ref(5) = "kill by time";
	opts.ref(6) = "jump to end";


}

void DebugEncounter::displayEncounter()
{
	cout << "Here we have a debug encounter thing.\n";
	cout << "It does stuff.\n\n";
}

CharacterData DebugEncounter::getOptionResult(int i)
{
	switch (i)
	{
	case 0:
		return CharacterData(CharacterStats(), 0);
		break;
	case 1:
		return CharacterData(CharacterStats(), -1);
		break;
	case 2:
		return CharacterData(CharacterStats(-100, -100, -100), 0);
		break;
	case 3:
		return CharacterData(CharacterStats(-100, 0, 0), 0);
		break;
	case 4:
		return CharacterData(CharacterStats(0, -100, 0), 0);
		break;
	case 5:
		return CharacterData(CharacterStats(0, 0, -100), 0);
		break;
	case 6:
		return CharacterData(CharacterStats(), HallLength);
		break;
	}

	return CharacterData();

}


//===========================================================================================//
//									  COMMON ENCOUNTERS
//===========================================================================================//

/************************************************/
//			UNDERGRADUATE ENCOUNTER
/************************************************/
UndergraduateEncounter::UndergraduateEncounter()
{
	opts = Options(3);

	opts.ref(0) = "Agree to regrade their papers";
	opts.ref(1) = "No. I don't have time for that right now.\nHere have some pity points";
	opts.ref(2) = "Umm... I'm not the TA for that class.";

}

void UndergraduateEncounter::displayEncounter()
{

	cout << "You encounter a group of undergraduates who want you to\n";
	cout << "regrade their papers.\n";

}

CharacterData UndergraduateEncounter::getOptionResult(int i)
{
	CharacterStats stats = CharacterStats();
	int roll;

	switch (i)
	{
	case 0:

		cout << "You may not like it but it needs to be done\n";
		cout << "so you get to work grading papers.\n";
		cout << "Thankfully, you at least get paid for this nonsense.\n";

		roll = rand() % 2;

		stats.time = -1 - roll;
		stats.money = 2;

		break;

	case 1:

		cout << "That was less than ideal, but you can't spend all day on this.\n";

		roll = rand() % 2;
		if (roll == 0)
		{
			cout << "Unfortunately you seem to have offended the undergraduate.\n";
			cout << "Oh well. Who cares about that.\n";
		}

		break;

	case 2:

		cout << "Well that's going to be interesting to explain to the professor.\n";

		roll = rand() % 3;

		stats.intelligence = -roll;

		break;

	}


	return CharacterData(stats, 0);
}
/************************************************/
//			END OF UNDERGRADUATE ENCOUNTER
/************************************************/


/************************************************/
//			WEEKEND ENCOUNTER
/************************************************/
WeekendEncounter::WeekendEncounter()
{
	opts = Options(3);

	opts.ref(0) = "Yay! Weekend! Time for a much needed break.";
	opts.ref(1) = "I could use this time to get some work done.";
	opts.ref(2) = "DUDE! PARTY!!!";


}

void WeekendEncounter::displayEncounter()
{

	cout << "After a long week of work you finally reach the weekend.\n";

}

CharacterData WeekendEncounter::getOptionResult(int i)
{
	CharacterStats stats = CharacterStats();
	int roll;


	switch (i)
	{
	case 0:

		cout << "Sometimes you just need to rest for a while.\n";
		cout << "You feel mentally rejuvenated.\n";
		stats.intelligence = 3;
		break;

	case 1:

		roll = (rand() % 7);
		stats.time = roll;

		if (roll >= 4)
		{
			cout << "You were totally on top of things!\n";
			cout << "This should put you way ahead!\n";

			stats.intelligence = roll / 2;
		}
		else if (roll == 0)
		{
			cout << "You tried your best, but you just couldn't focus\n";
			cout << "Now you feel exhausted.\n";
			stats.intelligence = -2;
		}
		else
		{
			cout << "You manage to get ahead on your work which should save\n";
			cout << "you a bit of time over the coming week.\n";
		}

		break;


	case 2:

		roll = rand() % 3;

		if (roll == 0)
		{
			cout << "Why? Those are loud. Why do people consider that fun?\n";
		}
		else if (roll == 1)
		{
			cout << "You're my downstairs neighbor, aren't you.\n";
		}
		else
		{
			cout << "The party gets out of hand, and you're fined for disturbing the peace.\n";
			stats.money = -4;
		}


		break;
	}


	return CharacterData(stats, 0);
}
/************************************************/
//			END OF WEEKEND ENCOUNTER
/************************************************/

/************************************************/
//			PROFESSOR ENCOUNTER
/************************************************/
ProfessorEncounter::ProfessorEncounter()
{

	opts = Options(3);

	opts.ref(0) = "Just keep walking.";
	opts.ref(1) = "Stop and talk about latest technical news";
	opts.ref(2) = "Try to get more funding.";


}

void ProfessorEncounter::displayEncounter()
{

	cout << "You encounter a professor in the hall\n";

}

CharacterData ProfessorEncounter::getOptionResult(int i)
{

	CharacterStats stats = CharacterStats();
	int roll;

	switch (i)
	{
	case 0:

		cout << "You both go you seperate ways.\n";
		cout << "You could have a least said hi.\n";
		break;

	case 1:

		roll = (rand() % 21) - 4;
		roll = roll / 4;
		stats.intelligence = roll;
		stats.time = -2;

		if (roll < 0)
		{
			cout << "A for effort, but you really didn't know what you were talking about\n";
		}
		else if (roll == 0)
		{
			cout << "The professor was busy and couldn't talk for very long\n";
			cout << "You didn't get much out of the conversation\n";
			stats.time = -1;
		}
		else
		{
			cout << "You have an insightful conversation with the professor.\n";
		}

		break;

	case 2:

		roll = rand() % 20;

		if (roll < 5)
		{
			cout << "You kind of made yourself look stupid\n";
			stats.intelligence = -2;
		}
		else if (roll < 15)
		{
			cout << "You talked for a while but the conversation didn't really go anywhere.\n";
			stats.time = -2;
		}
		else
		{
			cout << "You made a compelling argument that would make even the rocks cry.\n";
			cout << "Look out everybody! This grad student is getting paid!\n";
			stats.money = 5;
		}

		break;


	}


	return CharacterData(stats, 0);
}
/************************************************/
//			END OF PROFESSOR ENCOUNTER
/************************************************/

/************************************************/
//			VIDEO GAME ENCOUNTER
/************************************************/
VideoGameEncounter::VideoGameEncounter()
{

	opts = Options(4);

	opts.ref(0) = "I'll play for a few minutes.";
	opts.ref(1) = "Who cares? COMPUTER GAMES!";
	opts.ref(2) = "Uh... no. I don't have time for this! Or money for that matter.";
	opts.ref(3) = "What's a video game?";

}

void VideoGameEncounter::displayEncounter()
{
	cout << "You feel the urge to play games\n";
	cout << "but do you really have time for this?\n";
}

CharacterData VideoGameEncounter::getOptionResult(int i)
{
	CharacterStats stats = CharacterStats();
	int position = 0;
	int roll;


	switch (i)
	{
	case 0:

		roll = rand() % 2;

		if (roll == 0)
		{
			cout << "Self discipline is such a nice thing to have\n";
			cout << "You play for a bit and then go back to your work feeling refreshed\n";
			cout << "from your little break.\n";

			stats.intelligence = 2;
		}
		if (roll == 1)
		{
			cout << "One does not simply play for a few minutes.\n";
			stats.time = -1 - (rand() % 3);
		}
		break;

	case 1:

		cout << "What's this adult thing again? Oh yeah, it's the thing you're not doing right now.\n";

		stats.time = -2 - (rand() % 6);
		break;
	case 2:

		cout << "Wow. Way to be an adult. So tell me, do you actually have a life?\n";

		break;
	case 3:
		cout << "You monster.\n";
		break;
	}


	return CharacterData(stats, position);
}
/************************************************/
//			END OF VIDEO GAME ENCOUNTER
/************************************************/


//===========================================================================================//
//										 UNCOMMON ENCOUNTERS
//===========================================================================================//
/************************************************/
//			BUG ENCOUNTER
/************************************************/
BugEncounter::BugEncounter()
{

	opts = Options(4);

	opts.ref(0) = "Just walk away. Pretend it isn't there.";
	opts.ref(1) = "WHAT IS THE DEV DOING!? FIX THIS NONSENSE RIGHT NOW!";
	opts.ref(2) = "I wonder if I can exploit this?";
	opts.ref(3) = "Try pesticide.";

}

void BugEncounter::displayEncounter()
{

	cout << "Uh oh. You seem to have encountered a bug.\n";
	cout << "Hey no one's perfect.\n";

}

CharacterData BugEncounter::getOptionResult(int i)
{
	CharacterStats stats = CharacterStats();
	int position = 0;
	int roll = 0;


	switch (i)
	{
	case 0:

		cout << "That's one way to solve a problem.\n";
		break;

	case 1:

		cout << "Just for that\n";
		stats.money = -5;
		break;

	case 2:

		roll = rand() % 100;

		if (roll < 10)
		{

			int * badPointer = new int;

			cout << "Read access violation at " << badPointer << "\n";
			stats.intelligence = -45654743;

			delete badPointer;
			badPointer = 0;
		}
		else if (roll < 80)
		{
			cout << "I should make your game crash. You cheater.\n";
		}
		else
		{
			cout << "Stuff starts getting weird\n";
			stats.intelligence = (rand() % 80) - 40;
			stats.money = (rand() % 80) - 40;
			stats.time = (rand() % 80) - 40;
		}



		break;

	case 3:

		cout << "Full points for creativity, but no.\n";

		break;
	}


	return CharacterData(stats, position);
}
/************************************************/
//			END OF BUG ENCOUNTER
/************************************************/

//===========================================================================================//
//										 RARE ENCOUNTERS
//===========================================================================================//
/************************************************/
//			THE DOCTOR ENCOUNTER
/************************************************/
TheDoctorEncounter::TheDoctorEncounter()
{
}

void TheDoctorEncounter::displayEncounter()
{
}

CharacterData TheDoctorEncounter::getOptionResult(int i)
{
	CharacterStats stats = CharacterStats();
	int position = 0;


	switch (i)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}


	return CharacterData(stats, position);
}
/************************************************/
//			END OF THE DOCTOR ENCOUNTER
/************************************************/

/************************************************/
//			ANOMALY ENCOUNTER
/************************************************/
AnomalyEncounter::AnomalyEncounter()
{

	opts = Options(3);

	opts.ref(0) = "Walk away. In fact run! Just get away from that thing.";
	opts.ref(1) = "Study this strange new phenomenon. For science!";
	opts.ref(2) = "Walk into the rift";

}

void AnomalyEncounter::displayEncounter()
{

	cout << "A glowy pulsing light! Time and space seem to shift around it!\n";
	cout << "This could be dangerous!\n";

}

CharacterData AnomalyEncounter::getOptionResult(int i)
{
	CharacterStats stats = CharacterStats();
	int position = 0;
	int roll = 0;


	switch (i)
	{
	case 0:

		cout << "They say discretion is the better part of valor.\n";
		break;

	case 1:

		roll = rand() % 2;

		if (roll == 0)
		{
			cout << "You try to study the event, but it pulls you in!\n";
			cout << "You try to scream but you're caught in a vortex of light\n";
			cout << "and sound!\n\n";
		}
		else
		{

			roll = rand() % 4;

			if (roll == 0)
			{
				cout << "The notes you collect prove valuable to the scientific community,\n";
				cout << "and you eventually become one of the leading experts on the topic.\n";
				stats.intelligence = 50;
			}
			else
			{
				cout << "You are unable to make sense of the strange event before it vanishes in\n";
				cout << "in front of you.\n";
			}

			break;
		}

		//The break is left out on purpose

	case 2:

		roll = rand() % 3;

		cout << "It seems like you fall forever through the vortex\n";

		if (roll == 0)
		{
			cout << "until in an instant it all stops and you find youself\n";
			cout << "on moist earth. You look around you and see nothing but a\n";
			cout << "calm tropical forest.\n";
			cout << "...then you feel warm air brushing over your shoulder and neck.\n";
			cout << "You hear a soft, low snort, and slowly you turn to see the scaled\n";
			cout << "monster eyeing you from above.\n";
			cout << "Perhaps your bones will confuse some future archaeologist, but right\n";
			cout << "now you need to run!\n";

			stats.time = -1000000;
		}




		if (roll == 1)
		{
			cout << "until you find yourself lying on the ground in the hallway.\n";
			cout << "It seems you're further down the hall than when you started,\n";
			cout << "but all the clocks show an later time than when you left.\n";
			position = (rand() % 6) + 1;

			stats.time = -position;

		}

		if (roll == 2)
		{
			cout << "until you find yourself lying on the ground in the hallway.\n";
			cout << "It seems you're further back from where you started,\n";
			cout << "but all the clocks show an earlier time\n";

			position = -(rand() % 6) + 1;

			stats.time = -position;
		}

		break;

	}


	return CharacterData(stats, position);
}
/************************************************/
//			END OF ANOMALY ENCOUNTER
/************************************************/

//===========================================================================================//
//										GAME BREAKERS
//===========================================================================================//

/************************************************/
//                CTHULHU ENCOUNTER            
/************************************************/
CthulhuEncounter::CthulhuEncounter()
{

	opts = Options(4);

	opts.ref(0) = "Look at his face for a while";
	opts.ref(1) = "Nope... Just nope. I'm out";
	opts.ref(2) = "I will try to reason with it";
	opts.ref(3) = "Throw money at it";


}

void CthulhuEncounter::displayEncounter()
{

	cout << "A dark fiend has arisen! This evil creature will sap all your sanity\n";
	cout << "FEAR MORTAL FOR CTHULHU HAS COME TO CLAIM YOUR SOUL!\n\n";
	cout << "...Or maybe he's just here for tea. You never know about these things.\n";


}



CharacterData CthulhuEncounter::getOptionResult(int i)
{
	CharacterStats stats = CharacterStats();
	int position = 0;
	int roll = 0;

	switch (i)
	{
	case 0:
		cout << "You really thought that was a good idea?\n";
		stats.intelligence = -10000000;
		break;

	case 1:

		roll = rand() % 2;

		if (roll == 1)
		{
			cout << "You retreat back to your previous position\n";
			cout << "Let someone else deal with the fiend\n";
			position = -1;
			stats.time = -2;
		}
		else
		{
			cout << "You flee in terror. You don't think you'll ever be the same.\n";
			stats.time = -3;
			stats.intelligence = -5;
			position = -1;
		}
		break;

	case 2:

		roll = rand() % 100;

		if (roll == 99)
		{
			cout << "It turns out that Cthulu is really a nice guy after all.\n";
			cout << "He's actually a small business owner and is looking to promote academics and learning\n";
			cout << "He decides to give you a small scholarship to help you through school\n";
			stats.intelligence = 10;
			stats.money = 50;
		}
		else
		{
			cout << "Great. Reason with pure insanity. That was clearly a good idea\n";
			stats.intelligence = -1000000;
		}

		break;

	case 3:

		cout << "Ummm... what?\n";
		stats.money = -5;

	}



	return CharacterData(stats, position);
}
/************************************************/
//			END OF CTHULHU ENCOUNTER
/************************************************/

/************************************************/
//                DRAGON ENCOUNTER            
/************************************************/

DragonEncounter::DragonEncounter()
{

	opts = Options(4);

	opts.ref(0) = "RUN!!!!";
	opts.ref(1) = "Eat me! Why!?";
	opts.ref(2) = "Why don't we play a game of riddles instead.\n";



}

DragonEncounter::~DragonEncounter()
{
}

void DragonEncounter::displayEncounter()
{

	cout << "A fierce roar echos through campus and the ground begins to shake!\n";
	cout << "You see a flash of red out of the corner of your eye. Then a great dragon\n";
	cout << "lands in front of you! Its claws and teeth are pure white and its scales shimmer\n";
	cout << "in a rippling pattern of red flames.\n";

	cout << "It grins and says, \"A mortal. Perhaps I shall eat it\"\n";


}

CharacterData DragonEncounter::getOptionResult(int i)
{
	return CharacterData();
}

/************************************************/
//                END OF DRAGON ENCOUNTER            
/************************************************/