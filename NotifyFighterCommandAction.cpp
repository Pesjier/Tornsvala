#include "NotifyFighterCommandAction.h"
#include "Aircraft.h"

void NotifyFighterCommandAction::onNewAircraft(Aircraft& aicraft)
{
	for (int i = 0; i < types.size(); i++)
	{
		if (aicraft.getType() == types[i])
		{
			aicraft.addObserver(this);
		}
	}
}

std::string NotifyFighterCommandAction::internalUpdate(Aircraft& aircraft)
{
	time_t timestamp;
	time(&timestamp);

	aircraft.setLastNotified(timestamp);

	return "Alert! Notifying Fighter Command!";
}
