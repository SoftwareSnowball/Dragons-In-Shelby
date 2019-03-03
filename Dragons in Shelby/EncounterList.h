#ifndef _ENCOUNTER_LIST_H
#define _ENCOUNTER_LIST_H

#include <functional>

#include "resources.h"
#include "MenuManagerClass.h"
#include "Encounters.h"

struct NamedEncounter {
	std::function<Encounter*(MenuManagerClass* inputMenuInterface, PersistentStateFlags* instates)> generate;
	std::string name;
};

const NamedEncounter COMMON_ENCOUNTER_LIST[] = {
	{UndergraduateEncounter::Generate, "Undergraduate"},
	{WeekendEncounter::Generate, "Weekend"},
	{ProfessorEncounter::Generate, "Professor"},
	{VideoGameEncounter::Generate, "VideoGame"},
	{CancelledClassEncounter::Generate, "CancelledClass"},
	{NoisyNeighborsEncounter::Generate, "NoisyNeighbors"},
	{EmailEncounter::Generate, "Email"},
	{EasyAssigmentEncounter::Generate, "EasyAssignment"},
	//{AssignmentSetbackEncounter::Generate, "Professor"},

	{nullptr, "NULL"}
};

const NamedEncounter UNCOMMON_ENCOUNTER_LIST[] = {
	{BugEncounter::Generate, "Bug"},
	{RefrigeratorEncounter::Generate, "Refrigerator"},
	{CharityEncounter::Generate, "Charity"},
	{SicknessEncounter::Generate, "Sickness"},
	{BrokenNinjaEncounter::Generate, "BrokenNinja"},
	{MedicalStudentEncounter::Generate, "MedicalStudent"},
	//{BossRoomEncounter::Generate, "BossRoom"},
	//{TestEncounter::Generate, "Test"},
	
	{nullptr, "NULL"}
};

const NamedEncounter RARE_ENCOUNTER_LIST[] = {
	{TheDoctorEncounter::Generate, "TheDoctor"},
	{AnomalyEncounter::Generate, "Anomaly"},
	{AlienEncounter::Generate, "Alien"},
	{PentagramEncounter::Generate, "Pentagram"},
	

	{nullptr, "NULL"}
};

const NamedEncounter GAMEBREAKER_ENCOUNTER_LIST[] = {
	{CthulhuEncounter::Generate, "Cthulhu"},
	//{DragonEncounter::Generate, "Dragon"},


	{nullptr, "NULL"}
};


#endif