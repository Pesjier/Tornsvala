#pragma once
#include <string>

class AircraftFactory
{
public:

	static AircraftFactory& Instance()
	{
		static AircraftFactory instance;
		return instance;
	}

	//Aircraft* CreateAircraft(const std::string& tailcode, const std::string& type);

private:
	AircraftFactory();
	~AircraftFactory();
};

