#pragma once
#include <vector>
# include<string>

using namespace std;
class Aircraft;
class AircraftCollection
{
private:
	vector<Aircraft> aircraft;
public:
	void add(string tailcode, string type);
	void addAircraft(Aircraft* aircraft);
	void remove(string tailcode);
	bool hasAicraft(string tailcode);
	const void getAircraft(string tailcode);
	const string getAircraft();

};