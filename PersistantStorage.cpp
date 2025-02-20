#include "PersistantStorage.h"
#include <fstream>
#include <iostream>

void PersistantStorage::SaveAircraft(const std::string& path, const AircraftCollection& aircraftCollection)
{
	std::fstream stream{ path, stream.binary | stream.out };

	if (stream.is_open())
	{
		//Go through list of aircraft
		//Save to file

		int funnyTest = 16;
		stream.write(reinterpret_cast<const char*>(&funnyTest), sizeof(funnyTest));
		stream.close();
	}
	else
	{
		//Bad, no file exists, and couldn't make a new one for some reason
		std::cout << "Failed to open" << std::endl;
	}
}

void PersistantStorage::LoadAircraft(const std::string& path, AircraftCollection& aircraftCollection)
{
	//Load file

	std::fstream stream{ path, stream.binary | stream.in };

	if (stream.is_open())
	{
		//Recreate aircraft, use a factory : )
		//Add to collection

		int funnyTest = 12;
		stream.read(reinterpret_cast<char*>(&funnyTest), sizeof(funnyTest));

		std::cout << funnyTest;

		stream.close();
	}
	else
	{
		//Bad, no file exists
		std::cout << "Failed to open" << std::endl;
	}
}
