#pragma once
#include <string>

class AircraftCollection;
class ActionResponse;

class PersistantStorage
{
public:
	void SaveAircraft(const std::string& path, AircraftCollection& aircraftCollection);
	void LoadAircraft(const std::string& path, AircraftCollection& aircraftCollection, ActionResponse& responder);
};
