#include "LogFightCodeAction.h"
#include "Aircraft.h"

void LogFightCodeAction::onNewAircraft(Aircraft& aicraft)
{
	for (int i = 0; i < types.size(); i++)
	{
		if (aicraft.getType() == types[i])
		{
			aicraft.addObserver(this);
		}
	}
}

std::string LogFightCodeAction::internalUpdate(Aircraft& aircraft)
{
	time_t timestamp;
	time(&timestamp);

	aircraft.setLastSpotted(timestamp);

	char str[26];
	ctime_s(str, sizeof(str), &timestamp);
	return "Logging " + aircraft.getTailcode() + " at " + str;
}
