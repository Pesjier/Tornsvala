#include "AircraftFactory.h"
#include "Aircraft.h"

Aircraft* AircraftFactory::CreateAircraft(const std::string& tailcode, const std::string& type)
{
    Aircraft* newAircraft = new Aircraft(tailcode, type);
    return newAircraft;
}

AircraftFactory::AircraftFactory()
{
}

AircraftFactory::~AircraftFactory()
{
}
