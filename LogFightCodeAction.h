#pragma once
#include "Action.h"
#include <string>
#include <vector>
class LogFightCodeAction :
    public Action
{
public:
    void onNewAircraft(Aircraft& aicraft);
protected:
    std::string internalUpdate(Aircraft& aircraft);
private:
    std::vector<std::string> types = { "DH 98 Mosquito", "Hawker Hurricane", "Supermarine Spitfire", "Focke-Wulf FW190" };
};

