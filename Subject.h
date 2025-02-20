#pragma once
#include <vector>

class Observer;

class Subject
{
protected:
	std::vector<Observer*> myObservers;

public:
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	void notify();
};
