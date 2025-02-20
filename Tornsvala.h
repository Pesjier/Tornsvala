#pragma once
#include <string>
#include <vector>

class Tornsvala
{
private:
	std::vector<std::string> aircraftTypes;
	//AircraftCollection aircraft;
	//ActionResponse responder;
	//PersistantStorage storage;

public:
	const char* seen(const std::string& tailcode);
	const char* seen(const std::string& tailcode, const std::string& type);
	const std::vector<std::string>& listType();
	std::vector<std::string> listAircraft();
	const char* info(const std::string& tailcode);

	Tornsvala();
	~Tornsvala();
};
