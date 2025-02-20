#pragma once
#include <string>
#include <vector>
#include "PersistantStorage.h"
#include "AircraftCollection.h"
#include "ActionResponse.h"

class Tornsvala
{
private:
	std::vector<std::string> aircraftTypes;
	AircraftCollection aircraft;
	ActionResponse responder;
	PersistantStorage storage;

public:
	std::string seen(const std::string& tailcode);
	std::string seen(const std::string& tailcode, const std::string& type);
	const std::vector<std::string>& listType();
	std::vector<std::string> listAircraft();
	std::string info(const std::string& tailcode);

	Tornsvala();
	~Tornsvala();
};
