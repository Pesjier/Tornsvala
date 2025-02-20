#pragma once
#include "Action.h"
#include <vector>
#include <string>
class NotifyFighterCommandAction :
    public Action
{
public:
    void onNewAircraft(Aircraft& aicraft);
protected:
    std::string internalUpdate(Aircraft& aircraft);
private:
    std::vector<std::string> types = { "Messersvhmitt BF109", "Focke-Wulf FW190", "Junker Ju-87 Stuka"};
};

