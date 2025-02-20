#include "PersistantStorage.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "AircraftCollection.h"
#include "Aircraft.h"
#include "AircraftFactory.h"
#include "ActionResponse.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

void PersistantStorage::SaveAircraft(const std::string& path, AircraftCollection& aircraftCollection)
{
	std::ofstream stream;
	stream.open(path);

	if (stream.is_open())
	{
		const std::vector<Aircraft*>& allAircraft = aircraftCollection.getAircraft();
		int size = allAircraft.size();

		stream << size << std::endl;
		for (int i = 0; i < size; i++)
		{
			Aircraft& aircraft = *allAircraft[i];
			stream << aircraft.getTailcode() << std::endl;
			stream << aircraft.getType() << std::endl;
			stream << aircraft.getRouteAndDest() << std::endl;

			time_t timestamp = aircraft.getLastSpotted();
			char str[26];
			ctime_s(str, sizeof(str), &timestamp);
			stream << str << std::endl;

			timestamp = aircraft.getLastSpotted();
			ctime_s(str, sizeof(str), &timestamp);
			stream << str << std::endl;
		}
		stream.close();
	}
	else
	{
		//Bad, no file exists, and couldn't make a new one for some reason
		std::cout << "Failed to open" << std::endl;
	}
}

void PersistantStorage::LoadAircraft(const std::string& path, AircraftCollection& aircraftCollection, ActionResponse& responder)
{
	//Load file

	std::ifstream stream;
	stream.open(path);
	std::string line;
	std::vector<std::string>* result = new std::vector<std::string>();

	if (stream.is_open())
	{
		while (std::getline(stream, line))
		{
			result->push_back(line);
		}
		stream.close();

		int index = 0;
		int size = std::atoi((*result)[index].c_str());
		index++;

		for (int i = 0; i < size; i++)
		{
			std::string code = "";
			std::string type = "";
			std::string dest = "";
			time_t spotted = 0;
			time_t notified = 0;

			code = (*result)[index];
			index++;
			type = (*result)[index];
			index++;
			dest = (*result)[index];
			index++;
			string dateString = (*result)[index];
			std::tm tm = {};
			istringstream stringStream(dateString);

			stringStream >> get_time(&tm, "%a %b %d %H:%M:%S %Y");
			spotted = mktime(&tm);
			index++;

			dateString = (*result)[index];
			stringStream = istringstream(dateString);

			stringStream >> get_time(&tm, "%a %b %d %H:%M:%S %Y");
			spotted = mktime(&tm);
			index++;

			Aircraft* newAircraft = AircraftFactory::Instance().CreateAircraft(code, type);
			newAircraft->setLastNotified(notified);
			newAircraft->setLastSpotted(spotted);
			newAircraft->setRouteAndDest(dest);

			aircraftCollection.addAircraft(newAircraft);
			responder.onNewAircraft(*newAircraft);
		}
	}
	else
	{
		//Bad, no file exists
		std::cout << "Failed to open" << std::endl;
	}
}
