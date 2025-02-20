#pragma once
#include <vector>
# include<string>

using namespace std;
class Aircraft;
class AircraftCollection
{
private:
	vector<Aircraft*> aircraft;
public:
	void addAircraft(Aircraft* aircraft);
	void remove(string tailcode);
	bool hasAicraft(string tailcode);
	const vector<Aircraft*> getAircraft();
	Aircraft* getAircraft(const string& tailcode);

	~AircraftCollection();
};