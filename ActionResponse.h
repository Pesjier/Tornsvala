#pragma once
#include<vector>
using namespace std;
class Aircraft;
class Action;
class ActionResponse
{
private:
	vector<Action> actions;
public:
	void onNewAircraft(Aircraft& aircraft);

};

