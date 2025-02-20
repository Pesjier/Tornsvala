#include <string>
#include <sstream>
#include "Subject.h"

using namespace std;

class Aircraft : public Subject
{
private:
    string tailCode = "";
    string type = "";
    time_t lastSpotted = 0;
    time_t lastNotified = 0;
    string routeAndDest = "";

public:
    Aircraft(const string& tailCode, const string& type);

    string getTailcode();
    string getType();
    string getInfo();
    string getTypeAndCode();
    string getRouteAndDest();
    time_t getLastSpotted();
    time_t getLastNotified();

    void setLastSpotted(time_t date);
    void setLastNotified(time_t date);
    void setRouteAndDest(string routeAndDest);

    bool operator ==(const std::string& string)
    {
        return string == tailCode;
    }
};

