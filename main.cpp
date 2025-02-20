#include <iostream>
#include <string>
#include "Tornsvala.h"

int main()
{
	Tornsvala tornsvala;
	while (true)
	{
		std::string input;
		std::cout << "Write something" << std::endl;

		std::cin >> input;

		if (input == "seen")
		{
			std::cout << "Write Type: ";
			std::getline(std::cin, input);
			std::getline(std::cin, input);
			std::string type = input;
			std::cout << "Write Code: ";
			std::cin >> input;
			std::string tailCode = input;

			std::cout << tornsvala.seen(tailCode, type) << std::endl;
		}
		if (input == "seen2")
		{
			std::cin >> input;
			std::string tailCode = input;

			std::cout << tornsvala.seen(tailCode) << std::endl;
		}
		if (input == "info")
		{
			std::cin >> input;
			std::string tailCode = input;

			std::cout << tornsvala.info(tailCode) << std::endl;
		}
		if (input == "listT")
		{
			auto ts = tornsvala.listType();
			for (int i = 0; i < ts.size(); i++)
			{
				std::cout << ts[i] << std::endl;
			}
		}
		if (input == "listA")
		{
			auto as = tornsvala.listAircraft();
			for (int i = 0; i < as.size(); i++)
			{
				std::cout << as[i] << std::endl;
			}
		}
		if (input == "end")
		{
			break;
		}
	}
}
