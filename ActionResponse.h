#pragma once
#include<vector>
using namespace std;
class Aircraft;
class Action;
class ActionResponse
{
private:
	vector<Action*> actions;
public:
	ActionResponse();

	void onNewAircraft(Aircraft& aircraft);
};
