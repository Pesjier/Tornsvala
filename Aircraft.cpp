#include "Aircraft.h"

Aircraft::Aircraft(const string& tailCode, const string& type)
{
	this->tailCode = tailCode;
	this->type = type;
}

string Aircraft::getTailcode()
{
	return tailCode;
}

string Aircraft::getType()
{
	return type;
}

string Aircraft::getInfo()
{
	string finalInfo = getTypeAndCode();
	if (lastSpotted != 0)
	{
		finalInfo += "\n";
		char str[26];
		ctime_s(str, sizeof(str), &lastSpotted);
		finalInfo += "Last spotted during " + std::string(str);
	}
	if (lastNotified != 0)
	{
		finalInfo += "\n";
		char str[26];
		ctime_s(str, sizeof(str), &lastNotified);
		finalInfo += "Last notified command at " + std::string(str);
	}
	if (routeAndDest != "")
	{
		finalInfo += "\n";
		finalInfo += "Current Route: " + routeAndDest;
	}
	return finalInfo;
}

string Aircraft::getTypeAndCode()
{
	return type + " " + tailCode;
}

string Aircraft::getRouteAndDest()
{
	return routeAndDest;
}

time_t Aircraft::getLastSpotted()
{
	return lastSpotted;
}

time_t Aircraft::getLastNotified()
{
	return lastNotified;
}

void Aircraft::setLastSpotted(time_t date)
{
	lastSpotted = date;
}

void Aircraft::setLastNotified(time_t date)
{
	lastNotified = date;
}

void Aircraft::setRouteAndDest(string routeAndDest)
{
	this->routeAndDest = routeAndDest;
}
