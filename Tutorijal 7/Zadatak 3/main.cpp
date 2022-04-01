
#include <iostream>
#include <new>
#include <string>
#include <cstring>
#include <algorithm>

int main ()
{
	int br_recenica;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> br_recenica;
	std::cin.ignore(1000, '\n');

	std::cout << "Unesite recenice: ";

	try
	{
		std::string **recenice = new std::string *[br_recenica];
		for(int i=0; i<br_recenica; i++)
			recenice[i] = nullptr;

		try
		{
			//Unos recenica:
			for(int i=0; i<br_recenica; i++)
			{
				recenice[i] = new std::string;
				std::getline(std::cin, *recenice[i]);

			//Sprtiranje pomocu f-je sort:

			std::sort(recenice, recenice+br_recenica, [](std::string *a, std::string *b){return *a < *b;});

		    std::cout << "Sortirane recenice: " << std::endl;
		    for(int i=0; i<br_recenica; i++)
			    std::cout << *recenice[i] << std::endl;
		    }
        }
		catch(std::bad_alloc)
		{
			for(int i=0; i<br_recenica; i++)
			{
				delete [] recenice[i];
			}
			delete [] recenice;
			throw;
		}

		for(int i=0; i<br_recenica; i++)
			{
				delete [] recenice[i];
			}
			delete [] recenice;


	}
	catch(...)
	{
		std::cout << "Problem sa memorijom! " << std::endl;
	}

	return 0;
}
