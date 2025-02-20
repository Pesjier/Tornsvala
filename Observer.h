#pragma once
#include <string>

class Subject;

class Observer
{
public:
	virtual std::string Update(Subject* subject) = 0;
};
