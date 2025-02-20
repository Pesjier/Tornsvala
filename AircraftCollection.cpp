#include "AircraftCollection.h"

void AircraftCollection::add(string tailcode, string type)
{


}

void AircraftCollection::addAircraft(Aircraft* craft)
{
	for (int i = 0; i < aircraft.size(); i++) {
		if (aircraft[i] != craft) {
			aircraft.push_back(craft);
			break;
		}
	}
}

void AircraftCollection::remove(string tailcode)
{
	for (int i = 0; i < aircraft.size(); i++) {
		if ((*aircraft[i]).getTailcode() == tailcode) {
			aircraft[i] = aircraft[aircraft.size() - 1];
			aircraft.pop_back(tailcode);
		}
}
}

bool AircraftCollection::hasAicraft(string tailcode)
{
	for (int z = 0; z < aircraft.size(); z++) {
		if ((*aircraft).getTailcode == tailcode) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

const string AircraftCollection::getAircraft(string tailcode)
{
	for (int k = 0; k < aircraft.size(); k++) {
		if ((*aircraft[k]).getTailcode() == tailcode) {
			return tailcode;
		}
	}
}

const void AircraftCollection::getAircraft()
{
	for (int j = 0; j < aircraft.size(); j++) {
		cout << aircraft[j] << endl;
	}
}




