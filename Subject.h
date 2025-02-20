#pragma once
#include <vector>
#include <string>

class Observer;

class Subject
{
protected:
	std::vector<Observer*> myObservers;

public:
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	std::string notify();
};
