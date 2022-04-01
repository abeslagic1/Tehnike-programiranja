#include <iostream>
#include <new>
#include <string>
#include <cstring>

int main ()
{
	int br_recenica;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> br_recenica;
	std::cin.ignore(1000, '\n');

	std::cout << "Unesite recenice:" << std::endl;

	try
	{
		char **recenice = new char *[br_recenica];
		for(int i=0; i<br_recenica; i++)
			recenice[i] = nullptr;

		try
		{
			//Unos recenica:
			for(int i=0; i<br_recenica; i++)
			{
				char probna_recenica[1000];
				std::cin.getline(probna_recenica, sizeof probna_recenica);

				recenice[i] = new char[std::strlen(probna_recenica) +1];
				std::strcpy(recenice[i], probna_recenica);
			}
			//Sortiranje recenica:
			for(int i=0; i<br_recenica-1; i++)
			{
				for(int j=0; j<br_recenica-i-1; j++)
				{
					if(std::string(recenice[j]) > std::string(recenice[j+1]))
					{
					char *pomocna = recenice[j];
					recenice[j] = recenice[j+1];
					recenice[j+1] = pomocna;
					}
				}
			}
		std::cout << "Sortirane recenice:" << std::endl;
		for(int i=0; i<br_recenica; i++)
			std::cout << recenice[i] << std::endl;
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
		std::cout << "Problemi s memorijom!" << std::endl;
	}

	return 0;
}
