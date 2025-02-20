#pragma once
#include "Action.h"
class TrackRouteAndPredictDestAction :
    public Action
{
public:
    void onNewAircraft(Aircraft* aicraft);
protected:
    void internalUpdate(Aircraft& aircraft);
}