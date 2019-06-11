#include "GameAnalyticsClass.h"

#include <iostream>

int main()
{

	GAC gac;
	Event ev;
	ev.push_back("Param2", "Val2");
	ev.push_back("Param5", "Val3");
	gac.events.push_back(ev);

	Event ev2;
	ev2.push_back("3", "Val2");
	gac.events.push_back(ev2);

	Event ev3;
	ev3.push_back("123", "2");
	ev3.push_back("4343", "2424");
	gac.events.push_back(ev3);

	std::cout << gac.toString() << "\n\n";
	std::cout << gac.toXML("http://127.0.0.1:80", GAC::PostMethod::Server) << "\n\n";
	std::cout << gac.toJSON("http://127.0.0.1:80", GAC::PostMethod::Server) << "\n\n";
	std::cout << gac.toCSV("http://127.0.0.1:80", GAC::PostMethod::Server) << "\n\n";

	system("Pause");
	return 0;

} // main