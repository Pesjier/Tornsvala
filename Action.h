#pragma once
#include <string>
#include "Observer.h"

class Aircraft;
class Subject;
class Action : public Observer
{

public:
	virtual void onNewAircraft(Aircraft& aircraft) = 0;
	
	std::string Update(Subject* subject);

protected:
	virtual std::string internalUpdate(Aircraft& aircraft) = 0;
};

