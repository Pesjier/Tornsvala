#include "AircraftCollection.h"
#include "Aircraft.h"

void AircraftCollection::addAircraft(Aircraft* craft)
{
	aircraft.push_back(craft);
}

void AircraftCollection::remove(string tailcode)
{
	for (int i = 0; i < aircraft.size(); i++) {
		if ((*aircraft[i]).getTailcode() == tailcode) {
			aircraft[i] = aircraft[aircraft.size() - 1];
			aircraft.pop_back();
			break;
		}
	}
}

bool AircraftCollection::hasAicraft(string tailcode)
{
	for (int z = 0; z < aircraft.size(); z++) {
		if ((*aircraft[z]) == tailcode) {
			return true;
		}
	}
	return false;
}

Aircraft* AircraftCollection::getAircraft(const string& tailcode)
{
	for (int k = 0; k < aircraft.size(); k++) {
		if (*aircraft[k] == tailcode) {
			return aircraft[k];
		}
	}
	return nullptr;
}

AircraftCollection::~AircraftCollection()
{
	for (int i = 0; i < aircraft.size(); i++)
	{
		delete aircraft[i];
		aircraft[i] = nullptr;
	}
	aircraft.clear();
}

const vector<Aircraft*> AircraftCollection::getAircraft()
{
	return aircraft;
}




