#pragma once
#include "Action.h"
#include <vector>
#include <string>
class TrackRouteAndPredictDestAction :
    public Action
{
public:
    void onNewAircraft(Aircraft& aicraft);
protected:
    std::string internalUpdate(Aircraft& aircraft);
private:
    std::vector<std::string> types = { "Dornier Do-217", "Heinkel HE-177", "Junker Ju-87 Stuka"};
};