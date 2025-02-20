#pragma once
#include "Action.h"
class NotifyFighterCommandAction :
    public Action
{
public:
    void onNewAircraft(Aircraft* aicraft);
protected:
    void internalUpdate(Aircraft& aircraft);
};

