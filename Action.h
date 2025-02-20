#pragma once
class Aircraft;
class Subject;
class Action
{

public:
	virtual void onNewAircraft(Aircraft* aircraft) = 0;
	
	void update(Subject* subjekt);

protected:
	virtual void internalUpdate(Aircraft* aircraft) = 0;
};

