#include "Action.h"

std::string Action::Update(Subject* subjekt)
{
	Aircraft* aircraft = reinterpret_cast<Aircraft*>(subjekt);
	return internalUpdate(*aircraft);
}
