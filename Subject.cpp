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

std::string Subject::notify()
{
	std::string message = "";
	for (int i = 0; i < myObservers.size(); i++)
	{
		message += "\n" + myObservers[i]->Update(this);
	}
	return message;
}
