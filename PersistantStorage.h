#pragma once
#include <string>

class AircraftCollection;

class PersistantStorage
{
public:
	void SaveAircraft(const std::string& path, const AircraftCollection& aircraftCollection);
	void LoadAircraft(const std::string& path, AircraftCollection& aircraftCollection);
};
