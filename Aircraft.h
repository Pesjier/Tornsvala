#pragma once
#include <string>
#include <sstream>

using namespace std;

class Aircraft {
private:
    string tailCode;
    string type;
    Date lastSpotted;
    Date lastNotified;
    RouteAndPredictedDest routeAndDest;

public:
    Aircraft(const string& getTailcode);
    Aircraft(const string& getType);
    Aircraft(const string& getInfo);

    void setLastSpotted(Date date);
    void setLastNotified(Date date);
    void setRouteAndDest(RouteAndPredictedDest routeAndDest);

};

