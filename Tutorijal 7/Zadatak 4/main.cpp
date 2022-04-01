#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <memory>
#include <new>

typedef std::shared_ptr<std::string>dijeljeni;

int main ()
{
	int br_recenica;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> br_recenica;
	std::cin.ignore(1000, '\n');

	std::cout << "Unesite recenice:" << std::endl;

	try
	{
		//std::string **recenice = new std::string *[br_recenica];
		std::unique_ptr<dijeljeni[]>recenice(new dijeljeni[br_recenica]) ;


			//Unos recenica:
			for(int i=0; i<br_recenica; i++)
			{
				recenice[i] = std::make_shared <std::string>();
				std::getline(std::cin, *recenice[i]);
			}
			//Sprtiranje pomocu f-je sort:

			auto pok (recenice.get());
			std::sort(pok, pok+br_recenica, [](dijeljeni a, dijeljeni b){return *a < *b;});

		std::cout << "Sortirane recenice:" << std::endl;
		for(int i=0; i<br_recenica; i++)
			std::cout << *recenice[i] << std::endl;



	}
	catch(...)
	{
		std::cout << "Problemi s memorijom! " << std::endl;
	}

	return 0;
}
