#include "ActionResponse.h"
#include "NotifyFighterCommandAction.h"
#include "TrackRouteAndPredictDestAction.h"
#include "LogFightCodeAction.h"

ActionResponse::ActionResponse()
{
	LogFightCodeAction* logAction = new LogFightCodeAction();
	TrackRouteAndPredictDestAction* trackAction = new TrackRouteAndPredictDestAction();
	NotifyFighterCommandAction* notifyAction = new NotifyFighterCommandAction();

	actions.push_back(notifyAction);
	actions.push_back(trackAction);
	actions.push_back(logAction);
}

ActionResponse::~ActionResponse()
{
	for (int i = 0; i < actions.size(); i++)
	{
		delete actions[i];
		actions[i] = nullptr;
	}
	actions.clear();
}

void ActionResponse::onNewAircraft(Aircraft& aircraft)
{
	for (int i = 0; i < actions.size(); i++)
	{
		actions[i]->onNewAircraft(aircraft);
	}
}
