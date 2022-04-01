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

	std::cout << "Unesite recenice: ";

	try
	{
		//std::string **recenice = new std::string *[br_recenica];
		std::shared_ptr<dijeljeni>recenice(new dijeljeni[br_recenica], [](dijeljeni *p){delete [] p;}) ;


			//Unos recenica:
			for(int i=0; i<br_recenica; i++)
			{
				*(recenice.get()+i) = std::make_shared <std::string>();
				std::getline(std::cin, *(*(recenice.get()+i)));
			}
			//Sprtiranje pomocu f-je sort:

			auto pok (recenice.get());
			std::sort(pok, pok+br_recenica, [](dijeljeni a, dijeljeni b){return *a < *b;});

		std::cout << "Sortirane recenice: " << std::endl;
		for(int i=0; i<br_recenica; i++)
			std::cout << *(*(recenice.get()+i)) << std::endl;



	}
	catch(...)
	{
		std::cout << "Problem sa memorijom! " << std::endl;
	}

	return 0;
}
