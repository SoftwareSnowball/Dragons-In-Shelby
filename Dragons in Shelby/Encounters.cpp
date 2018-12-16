#include "Encounters.h"
/*

Author: James Malloy
email:	jem0044@tigermail.auburn.edu
id:		903518039

FileName: Encounters.cpp


See header file for description


*/


Encounter::Encounter()
{

	menuInterface = nullptr;

	opts = Options(1);

	encounterInfo = "This is a default encounter\n";
	encounterInfo += "Like seriously you shouldn't even be able to see this\n";
	opts.ref(0) = "There are no choices here";


}

Encounter::~Encounter()
{
}

void Encounter::linkInterfaces(MenuManagerClass * inputMenuInterface, PersistentStateFlags * instates)
{

	states = instates;
	menuInterface = inputMenuInterface;
	EncounterResultPackage result = EncounterResultPackage();


}


EncounterResultPackage Encounter::run()
{

	displayEncounter();


	if (menuInterface)
	{
		encounterMechanics();
		return result;
	}


	EncounterResultPackage temp;

	temp.gameFlags = FunctionErrorFlag;

	return temp;
}

void Encounter::displayEncounter()
{
	cout << encounterInfo;
}


void Encounter::encounterMechanics()
{
	int i = menuInterface->Menu(opts);

	if (i == UserExitCode)
	{
		result.gameFlags = UserExitFlag;
	}
	else
	{
		result.gameFlags = 0;
		result.characterEffects = getOptionResult(i);
	}
}


CharacterData Encounter::getOptionResult(int i) //legacy encounter system support
{
	return CharacterData();
}


//===================================================
//                 DEBUG ENCOUNTERS
//===================================================

DebugEncounter::DebugEncounter()
{
	generateOptions();
}

void DebugEncounter::displayEncounter()
{
	cout << "Here we have a debug encounter thing.\n";
	cout << "It does stuff.\n\n";
}

void DebugEncounter::generateOptions()
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


//EncounterResultPackage DebugEncounter::encounterMechanics()
//{
//
//	int i = menuInterface->Menu(opts);
//
//	EncounterResultPackage result = EncounterResultPackage();
//
//	if (i == UserExitCode)
//	{
//		result.gameFlags = UserExitFlag;
//
//	}
//	else
//	{
//		result.gameFlags = 0;
//		result.characterEffects = getOptionResult(i);
//	}
//
//	return result;
//
//}



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
	generateOptions();
}



void UndergraduateEncounter::displayEncounter()
{
	cout << "You encounter a group of undergraduates who want you to\n";
	cout << "regrade their papers.\n";
}

void UndergraduateEncounter::generateOptions()
{
	opts = Options(3);

	opts.ref(0) = "Agree to regrade their papers";
	opts.ref(1) = "No. I don't have time for that right now.\nHere have some pity points";
	opts.ref(2) = "Umm... I'm not the TA for that class.";
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


/************************************************/
//			CANCELLED CLASS ENCOUNTER
/************************************************/

CancelledClassEncounter::CancelledClassEncounter()
{
	typeRoll = rand() % 2;

	if (typeRoll == 0)
	{

		opts = Options(4);

		opts.ref(0) = "Well... rats.";
		opts.ref(1) = "Yay. I guess I'll go back home then...";
		opts.ref(2) = "Awww. I was actually looking forward to class.";
		opts.ref(3) = "Well that stinks. I'm getting some food.";

	}
	else
	{
		opts = Options(3);

		opts.ref(0) = "Cool. I can catch up on my work.";
		opts.ref(1) = "I am so taking a nap.";
		opts.ref(2) = "Hmmm. I can't actually think of an option to put here.";
	}

}

void CancelledClassEncounter::displayEncounter()
{
	if (typeRoll == 0)
	{

		cout << "You show up for your class for the day...\n";
		cout << "Wait where is everyone... Oh.\n";
		cout << "Apparently you forgot to check your email and class was cancelled.\n";
		cout << "You were the only one who missed the memo... the ... only ... one.\n\n";
		cout << "So tell me, how does that make you feel?\n";

	}
	else
	{
		cout << "You get a message saying that class is cancelled today.\n";
		cout << "It's a good thing you checked your email.\n";
	}
}

CharacterData CancelledClassEncounter::getOptionResult(int i)
{

	CharacterStats stats;

	if (typeRoll == 0)
	{


		switch (i)
		{

		case 0:

			cout << "You know, the rats might be offended by that.\n";
			break;

		case 1:

			cout << "And now you get to slink home in shame.\n";
			break;

		case 2:

			cout << "You nerd.\n";
			stats.intelligence = 1;
			break;

		case 3:

			cout << "Three words: on campus dining.\n";
			stats.money = -1;
			break;

		}

	}
	else
	{
		switch (i)
		{
		case 0:

			cout << "Someone's feeling industrious today.\n";
			stats.time = 2;
			break;

		case 1:

			cout << "You feel a little refreshed from the nap.\n";
			cout << "Lazy bum.\n";
			stats.intelligence = 2;
			break;

		case 2:


			cout << "Oh sure. Break the game. Why not.\n";
			cout << "Ummmm... what am I supposed to say here.\n";
			cout << "Stop looking at me... no really I mean it.\n";
			cout << "...please...\n";
			cout << "Fine! have a dollar! Now go away!\n";

			stats.money = 1;
			break;
		}
	}


	return CharacterData(stats, 0);

}
/************************************************/
//			END OF CANCELLED CLASS ENCOUNTER
/************************************************/


/************************************************/
//			NOISY NEIGHBORS ENCOUNTER
/************************************************/
NoisyNeighborsEncounter::NoisyNeighborsEncounter()
{
	opts = Options(3);

	opts.ref(0) = "Just try to ignore it. They'll stop eventually.";
	opts.ref(1) = "Call the police. It is too late for this nonsense";
	opts.ref(2) = "Nope. That's it. I'm getting up and doing work.";
}

void NoisyNeighborsEncounter::displayEncounter()
{
	cout << "Ahhh. Finally after a long day of school you get to go\n";
	cout << "to sleep. You start to close your eyes and relax feeling\n";
	cout << "the cares of the day start to melt awa..... BAM BAM BAM BAM\n";
	cout << "YEAAAHHHHHH!!! PARTY!!!!!! WAHOOOOOOOOOO!!!!!!! WEEEEEED!!!!!\n";
	cout << "I'M SOOOO **** STONED!!!!!!!\n"; //Yes I have woken up to someone yelling that.
	cout << "The silence of the night is rent apart like a pure tapestry savagely\n";
	cout << "shreaded by feral beasts!\n";
	cout << "Welcome to college. Where your neighbors like to party all night.\n";
}


CharacterData NoisyNeighborsEncounter::getOptionResult(int i)
{
	CharacterStats stats;
	int roll = rand() % 2;

	switch (i)
	{
	case 0:

		if (roll == 0)
		{
			cout << "It feels like forever, but eventually they stop.\n";
			cout << "You climb into bed grumbling, hoping to salvage what little sleep you can.\n";
			stats.intelligence = -2;
		}
		else
		{
			cout << "Fortunately, they don't party for too long tonight. They're probably too drugged up\n";
			cout << "to stay awake\n";
			cout << "Still... losing sleep really doesn't help much.\n";
			stats.intelligence = -1;
		}


		break;

	case 1:

		cout << "Naturally, they decide to stop before the police arrive.\n";

		cout << "Unfortunately now you're mad. This is going to be a long night.\n";
		stats.intelligence = -2;
		break;

	case 2:

		if (roll == 0)
		{

			cout << "At least you got something done.\n";
			stats.time = 1;
			stats.intelligence = -2;
		}
		else
		{
			cout << "Nope. That didn't work.\n";
			stats.intelligence = -2;
		}


		break;
	}

	return CharacterData(stats, 0);
}

/************************************************/
//			END OF NOISY NEIGHBORS ENCOUNTER
/************************************************/

/************************************************/
//			EMAIL ENCOUNTER
/************************************************/

/************************************************/
//			END OF EMAIL ENCOUNTER
/************************************************/

/************************************************/
//			ASSIGNMENT SETBACK ENCOUNTER
/************************************************/

/************************************************/
//			END OF ASSIGNMENT SETBACK ENCOUNTER
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
	opts.ref(3) = "Try pesticide?";
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

			cout << "Read access violation at " << badPointer << "\n"; //should display memory address
			stats.intelligence = -45654743;

			delete badPointer;
			badPointer = nullptr;
		}
		else if (roll < 80)
		{
			cout << "I should make your game crash. You cheater.\n";
		}
		else
		{
			cout << "Stuff starts getting weird\n";
			stats.intelligence = (rand() % 81) - 40;
			stats.money = (rand() % 81) - 40;
			stats.time = (rand() % 81) - 40;
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

/************************************************/
//			REFRIGERATOR ENCOUNTER
/************************************************/

RefrigeratorEncounter::RefrigeratorEncounter()
{
	opts = Options(4);

	opts.ref(0) = "I guess I'll try to fix it.";
	opts.ref(1) = "Call a repairman.";
	opts.ref(2) = "I don't have the money for this. I'll get a repairman but not pay him.";
	opts.ref(3) = "I don't have time for this. I'll just eat out for a while.";
}

void RefrigeratorEncounter::displayEncounter()
{
	cout << "You come home from school, and instantly smell something wrong. You follow the foul odor...\n";
	cout << "to your refrigerator. It's broken. Like really broken. There's a puddle on the ground in front of it\n";
	cout << "and the inside is quite warm. At the very least you'll have to replace your food.\n";
}

CharacterData RefrigeratorEncounter::getOptionResult(int i)
{
	CharacterStats stats;
	int roll;

	switch (i)
	{

	case 0:
		roll = rand() % 4;

		if (roll == 0)
		{

			cout << "It takes a fair amount of work, but you manage to fix it.\n";

			stats.money = -1;
			stats.time = -1 - (rand() % 4);

		}
		else
		{

			cout << "You broke everything... At least everything that wasn't already broken\n";
			cout << "This is gonna be expensive to fix.\n";

			stats.time = -2;
			stats.money = -7;



			if (states->cheatedMechanic)
			{
				cout << "Unfortunately, it looks like the repairman isn't coming to help you.\n";
				cout << "I guess you're eating out.\n";
				stats.time = -5;
				stats.money = -6;
			}

		}
		break;

	case 1:

		roll = 2 + (rand() % 3);

		if (states->cheatedMechanic)
		{
			cout << "Yeah. No. They don't want to help you.\n";
			cout << "Looks like you're all out of luck.\n";
			stats.time = -5;
			stats.money = -6;

		}
		else if (roll <= 2)
		{
			cout << "At least the repair cost wasn't too bad.\n";
			stats.money = -roll;
		}
		else
		{
			cout << "Ouch.\n";
			stats.money = -roll;
		}
		break;

	case 2:

		if (states->cheatedMechanic)
		{
			cout << "They're not falling for that again. You're on your own.\n";
			stats.time = -5;
			stats.money = -6;
		}
		else
		{

			states->cheatedMechanic = true;

			cout << "You manage trick the mechanic into fixing the fridge and then send him off without pay.\n";
			cout << "He's furious, but without a writen contract there's nothing he can do.\n";

		}

			break;
	case 3:

		cout << "Turns out restraunts aren't cheap.\n";
		stats.time = -2;
		stats.money = -4;

		break;

	}

	return CharacterData(stats, 0);
}
/************************************************/
//			END OF REFRIGERATOR ENCOUNTER
/************************************************/


/************************************************/
//			CHARITY ENCOUNTER
/************************************************/
CharityEncounter::CharityEncounter()
{
	opts = Options(4);

	opts.ref(0) = "Look I'm broke. What do you want from me?";
	opts.ref(1) = "Fine. Have a dollar.";
	opts.ref(2) = "Here, have a small donation.";
	opts.ref(3) = "GIVE THEM NO QUARTERS!!!";
}

void CharityEncounter::displayEncounter()
{
	cout << "A wild charity institution appears. They seek donations...\n";
}

CharacterData CharityEncounter::getOptionResult(int i)
{
	CharacterStats stats;
	int roll;

	switch (i)
	{
	case 0:

		roll = rand() % 2;

		if (roll == 0)
		{

			cout << "You walk away.";

		}
		else
		{
			cout << "But think about the children...\n";
			cout << "They guilt trip you into donating.\n";

			roll = 1 + (rand() % 4);

			stats.money = -roll;
			
		}
		break;

	case 1:

		cout << "The token gesture allows you to make your escape.\n";

		stats.money = -1;

		break;

	case 2:

		cout << "Wow. You're generous. I hope you have enough to make it through the semester.\n";

		stats.money = -2;

		break;
	case 3:

		cout << "CHARGE!!! DOWN WITH CHARITY!!!\n";
		cout << "... you monster.\n";


		roll = rand() % 2;

		if (roll == 0)
		{
			cout << "Your somewhat bellicose response attracts the attention of the local police.\n";
			cout << "It takes a while to explain away your... interesting behavior.\n";

			stats.time = -3;
		}
		break;
	}

	return CharacterData(stats, 0);
}

/************************************************/
//			END OF CHARITY ENCOUNTER
/************************************************/

/************************************************/
//			SICKNESS ENCOUNTER
/************************************************/

SicknessEncounter::SicknessEncounter()
{
}

void SicknessEncounter::displayEncounter()
{
}

CharacterData SicknessEncounter::getOptionResult(int i)
{
	return CharacterData();
}


/************************************************/
//			END OF SICKNESS ENCOUNTER
/************************************************/

/************************************************/
//			BROKEN NINJA ENCOUNTER
/************************************************/

BrokenNinjaEncounter::BrokenNinjaEncounter()
{
	opts = Options(2);

	opts.ref(0) = "So it turns out the dev hasn't actually gotten around to making options for this.";
	opts.ref(1) = "y u no finish encounter?";
}


void BrokenNinjaEncounter::displayEncounter()
{
	cout << "Through the corner of your eye you see a man dressed in black.\n";
	cout << "Apparently he's hunting a six fingered man or something and it's getting\n";
	cout << "kind of late. Why am I still working on this!?\n";

}


CharacterData BrokenNinjaEncounter::getOptionResult(int i)
{
	CharacterStats stats;
	int roll;

	cout << "Here. Let's just pretend this was finished.\n";
	stats.money = 4;

	return CharacterData(stats, 0);
}
/************************************************/
//			END OF BROKEN NINJA ENCOUNTER
/************************************************/


/************************************************/
//			MEDICAL STUDENT ENCOUNTER
/************************************************/
MedicalStudentEncounter::MedicalStudentEncounter()
{
}

void MedicalStudentEncounter::displayEncounter()
{
}

CharacterData MedicalStudentEncounter::getOptionResult(int i)
{
	return CharacterData();
}
/************************************************/
//			END OF MEDICAL STUDENT ENCOUNTER
/************************************************/


/************************************************/
//			 TEST ENCOUNTER
/************************************************/


/************************************************/
//			END OF TEST ENCOUNTER
/************************************************/
//===========================================================================================//
//										 RARE ENCOUNTERS
//===========================================================================================//
/************************************************/
//			THE DOCTOR ENCOUNTER
/************************************************/
TheDoctorEncounter::TheDoctorEncounter()
{
	opts = Options(3);

	opts.ref(0) = "Just walk away.";
	opts.ref(1) = "Open the door and peek inside.";
	opts.ref(2) = "CALL THE POLICE!!!";

}

void TheDoctorEncounter::displayEncounter()
{
	cout << "As you walk down the hall, you see a flash of light\n";
	cout << "and a blue police box appears. A tall figure gets out\n";
	cout << "and moves hastily down a side passage.\n";
}

CharacterData TheDoctorEncounter::getOptionResult(int i)
{
	CharacterStats stats = CharacterStats();
	int position = 0;
	int roll = 0;


	switch (i)
	{
	case 0:
		cout << "You walk away. Some things are better left alone.\n";
		break;
	case 1:
		cout << "The figure comes back and befriends you taking you on an epic journey\n";
		cout << "through time which I'm too lazy to describe in any great detail.\n";
		cout << "At the end of the journey you die tragically, but then timey-wimey\n";
		cout << "things happen and it turns out that you never saw the strange blue box.\n\n";
		cout << "You feel a slight feeling of deju vu for a moment as if you can almost recall\n";
		cout << "something that happened in a dream, then you move on with your day.\n";

		roll = rand() % 7;

		if (roll != 0)
		{
			cout << "This alternate reality does make you smarter though for reasons I don't understand.\n";
			stats.intelligence = roll;
		}

		break;
	case 2:
		cout << "What exactly did you think they were going to do with this?\n";

		roll = rand() % 5;

		if (roll != 0)
		{
			cout << "You waste a bunch of time trying to explain to the police.\n";
			cout << "They think you're a complete nut.\n";
			cout << "One of them is judging you silently.\n";
			stats.time = -roll;
		}

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

/************************************************/
//				ALIEN ENCOUNTER
/************************************************/
AlienEncounter::AlienEncounter()
{
	opts = Options(3);

	opts.ref(0) = "";
}

void AlienEncounter::displayEncounter()
{
}

CharacterData AlienEncounter::getOptionResult(int i)
{
	return CharacterData();
}

/************************************************/
//			END OF ALIEN ENCOUNTER
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
	cout << "FEAR, MORTAL FOR CTHULHU HAS COME TO CLAIM YOUR SOUL!\n\n";
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

		if (roll < 5)
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
	opts.ref(2) = "Why don't we play a game of riddles instead?";
	opts.ref(3) = "BRING IT! FIGHT ME!";
}


void DragonEncounter::displayEncounter()
{
	cout << "A fierce roar echos through campus and the ground begins to shake!\n";
	cout << "You see a flash of red out of the corner of your eye. Then a great dragon\n";
	cout << "lands in front of you! Its claws and teeth are pure white and its scales shimmer\n";
	cout << "in a rippling pattern of red flames.\n";

	cout << "It grins and says, \"Ahhh. A mortal. Perhaps I shall eat it.\"\n";
}

CharacterData DragonEncounter::getOptionResult(int i)
{
	CharacterData effect;
	int roll;
	bool win;


	switch (i)
	{

	case 0:

		roll = rand() % 3;

		if (roll == 1)
		{
			cout << "You don't know how fast you ran, but you somehow got away from the beast.\n";
			cout << "The encounter has badly shaken you.\n";

			effect.stats.intelligence = inflictTerror();
		}
		else
		{
			cout << "The winged creature easily catches up to you. Opening its mouth, it unleashes\n";
			cout << "a roar and a firey torrent. The air shimmers around you as the flames descend.\n";
			cout << "After what feels like hours of indescribable pain, your concousness finally fades\n";
			cout << "into blissful oblivion.\n";
			result.gameFlags = SpecialDefeatFlag;
		}

		break;

	case 1:

		roll = rand() % 4;

		if (roll < 2)
		{
			cout << "The dragon roars and heaves on the ground. It takes you several seconds to realize its laughing.\n";
			cout << "\"The mortals always fall for that. Why would I bother to eat something so small.\"\n";
			cout << "With that statement, the dragon flies away.\n";

			effect.stats.intelligence = inflictTerror();

		}
		else
		{
			cout << "\"It has been so long since I tasted the flesh of a mortal. I'm looking forward to this.\"\n";
			cout << "With that, the dragon snaps forward and catches you in its claws. It then proceeds to slowly\n";
			cout << "devour your body bit by bit.\n";
			cout << "Even though you suffer immensely, the dragon prolongs your death eating you like a fine delicacy.\n";
			result.gameFlags = SpecialDefeatFlag;
		}
		break;

	case 2:

		cout << "The dragon snorts loudly. \"Yes indeed mortal. You dare challenge a dragon?\"\n";
		cout << "\"I will ask you questions then. Answer them if you can.\"\n";

		win = gameOfRiddles();

		if (win)
		{
			cout << "The dragon regards you for a while. \"Never has a mortal been able to answer\n";
			cout << "my questions. I shall give you a gift. Choose wisely, mortal. What is your desire\"\n";
			effect = reward();
		}
		else
		{

			cout << "\"That is the wrong answer.\" The dragon chuckles deep in its throat.\n";
			cout << "\"I'm going to enjoy this part,\" the dragon says, then licks its lips and launches\n";
			cout << "itself forward. You feel the dragons teeth closing around your torso and\n";
			cout << "piercing your body. You scream, but the sounds is quickly reduced to a wet\n";
			cout << "gurgling noise as your body dies. The light fades from your eyes,\n";
			cout << "and your vision goes black as you lose conciousness forever.\n\n";
			result.gameFlags = SpecialDefeatFlag;

		}

		break;

	case 3:

		roll = rand() % 20;

		if (roll != 19) {
			cout << "Yeah... that went well.\n";
			cout << "The dragon turns you into a light snack.\n";
			result.gameFlags = SpecialDefeatFlag;
		}
		else {
			cout << "Okay... this really really should not work, but the RNG loves you today.\n";
			cout << "You walk up and One Punch Man the dragon like a boss.\n";
			cout << "The hero league doesn't recogize you though, so you don't get anything for this.\n";	
		}
		break;

	}

	return effect;
}

int DragonEncounter::inflictTerror()
{
	int roll = rand() % 11;

	if (roll > 7)
	{
		cout << "You will never be the same again.\n";
		cout << "This terror will haunt you for the rest of your life.\n";
	}
	else if (roll >= 4)
	{
		cout << "You are badly shaken\n";
	}
	else if (roll >= 1)
	{
		cout << "You are somewhat shaken.\n";
	}
	else
	{
		cout << "You manage to shrug off the encounter and move on with the day\n";
	}

	return -roll;
}


bool DragonEncounter::gameOfRiddles()
{

	cout << "Riddles? Very well, mortal.\n";
	cout << "What is my favorite food?\n";


	Options riddle1(3);
	riddle1.ref(0) = "Cabbage";
	riddle1.ref(1) = "potatoes?";
	riddle1.ref(2) = "nothing";
	riddle1.ref(3) = "People?";
	riddle1.ref(4) = "What kind of riddle is this?";

	int choice = menuInterface->Menu(riddle1);


	switch (choice) {
	case 0:
		cout << "Why on Earth would I eat cabbage?\n";
		return false;
	case 1:
		cout << "I love potatoes! How did you know?\n";
		return true;
	case 2:
		cout << "Really?\n";
		return false;
	case 3:
		cout << "I love eating people. They're a fine delicacy but they're not my favorite.\n";
		return false;
	case 4:
		cout << "Okay fine. I was too lazy to think of one. Go away.\n";
		return true;
	}

	return false;
}

CharacterData DragonEncounter::reward()
{
	return CharacterData();
}

/************************************************/
//                END OF DRAGON ENCOUNTER            
/************************************************/