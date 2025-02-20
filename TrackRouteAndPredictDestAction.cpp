#include "TrackRouteAndPredictDestAction.h"
#include "Aircraft.h"

void TrackRouteAndPredictDestAction::onNewAircraft(Aircraft& aicraft)
{
	for (int i = 0; i < types.size(); i++)
	{
		if (aicraft.getType() == types[i])
		{
			aicraft.addObserver(this);
		}
	}
}

std::string TrackRouteAndPredictDestAction::internalUpdate(Aircraft& aircraft)
{
	aircraft.setRouteAndDest("Going to Karlskrona through Köpenhamn");
	return "Tracking route and predicting destination...";
}

