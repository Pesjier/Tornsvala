#include "Tornsvala.h"
#include "Aircraft.h"
#include "AircraftFactory.h"

Tornsvala::Tornsvala()
{
	//Could load these from file but whatever
	aircraftTypes = { "Avro Lancaster",
		"Bristol Blenheim",
		"DH 98 Mosquito",
		"Hawker Hurricane",
		"Supermarine Spitfire",
		"Messerschmitt BF109",
		"Focke-Wulf FW190",
		"Dornier Do-217",
		"Heinkel HE-177",
		"Junker Ju-87 Stuka" };

	//Load aircraftCollection
	storage.LoadAircraft("aircraft.aircraft", aircraft, responder);
}

Tornsvala::~Tornsvala()
{
	//Save aircraftCollection
	storage.SaveAircraft("aircraft.aircraft", aircraft);
}

std::string Tornsvala::seen(const std::string& tailcode)
{
	const std::vector<Aircraft*>& allAircraft = aircraft.getAircraft();
	for (int i = 0; i < allAircraft.size(); i++)
	{
		if (*allAircraft[i] == tailcode)
		{
			Aircraft& seenAircraft = (*allAircraft[i]);
			return "Existing Aircraft " + seenAircraft.getTypeAndCode() + seenAircraft.notify();
		}
	}

	return "This is a new aircraft.\nPlease add the type to your observation : 'seen G-CFGJ «aircraft-type»'";
}

std::string Tornsvala::seen(const std::string& tailcode, const std::string& type)
{	
	const std::vector<Aircraft*>& allAircraft = aircraft.getAircraft();
	for (int i = 0; i < allAircraft.size(); i++)
	{
		if (*allAircraft[i] == tailcode)
		{
			Aircraft& seenAircraft = (*allAircraft[i]);
			return "Existing Aircraft " + seenAircraft.getTypeAndCode() + seenAircraft.notify();
		}
	}

	for (int i = 0; i < aircraftTypes.size(); i++)
	{
		if (aircraftTypes[i] == type)
		{
			Aircraft& newAircraft = *AircraftFactory::Instance().CreateAircraft(tailcode, type);
			aircraft.addAircraft(&newAircraft);

			responder.onNewAircraft(newAircraft);

			return "Added " + newAircraft.getTypeAndCode() + " to Collection" + newAircraft.notify();
		}
	}

	return "That aircraft type is not supported!";
}

const std::vector<std::string>& Tornsvala::listType()
{
	return aircraftTypes;
}

std::vector<std::string> Tornsvala::listAircraft()
{
	const std::vector<Aircraft*>& allAircraft = aircraft.getAircraft();
	std::vector<std::string> allAircraftInText;

	for (int i = 0; i < allAircraft.size(); i++)
	{
		allAircraftInText.push_back(allAircraft[i]->getTypeAndCode());
	}

	return allAircraftInText;
}

std::string Tornsvala::info(const std::string& tailcode)
{
	if (aircraft.hasAicraft(tailcode))
	{
		return aircraft.getAircraft(tailcode)->getInfo();
	}
	return "That aircraft has not been seen.";
}
