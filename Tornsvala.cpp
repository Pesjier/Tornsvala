#include "Tornsvala.h"

Tornsvala::Tornsvala()
{
	//Load aircraftTypes
	//Load aircraftCollection
}

Tornsvala::~Tornsvala()
{
	//Save aircraftCollection
}

const char* Tornsvala::seen(const std::string& tailcode)
{
	//Sees aircraft with tailcode
	//If new, tell user to specify type aswell, then nothing more
	//Else, notify on aircraft and send back message with which actions responded to it
	return "Ok";
}

const char* Tornsvala::seen(const std::string& tailcode, const std::string& type)
{	
	//Sees aircraft with tailcode
	//If new, add to list etc. Message that we added to collection
	//Then notify on aircraft and send back message with which actions responded to it
	return "Ok";
}

const std::vector<std::string>& Tornsvala::listType()
{
	return aircraftTypes;
}

std::vector<std::string> Tornsvala::listAircraft()
{
	//Convert aircraftCollection list to string list of tailcodes
	return std::vector<std::string>();
}

const char* Tornsvala::info(const std::string& tailcode)
{
	//Return info of aircraft with the tailcode
	return "Ok";
}
