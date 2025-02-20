#include "Subject.h"
#include "Observer.h"

void Subject::addObserver(Observer* observer)
{
	myObservers.push_back(observer);
}

void Subject::removeObserver(Observer* observer)
{
	for (int i = 0; i < myObservers.size(); i++)
	{
		if (myObservers[i] == observer)
		{
			myObservers[i] = myObservers[myObservers.size() - 1];
			myObservers.pop_back();
			break;
		}
	}
}

void Subject::notify()
{
	for (int i = 0; i < myObservers.size(); i++)
	{
		myObservers[i]->Update(this);
	}
}
