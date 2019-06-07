#include "GameAnalyticsClass.h"

#include <iostream>

int main()
{

	Event ev;
	ev.push_back("Param2", "Val2");
	ev.push_back("Param5", "Val3");
	ev.push_back("Param4", "Val4");
	ev.push_back("Param3", "Val5");
	std::cout << ev.toXML() << "\n\n";

	system("Pause");
	return 0;

} // main