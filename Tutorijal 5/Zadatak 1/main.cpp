#include <iostream>


int main ()
{
	char niz[1000];

	std::cout << "Unesite recenicu: ";

	std::cin.getline(niz, sizeof niz);

	char *p = niz;

	while(*p == ' ') p++;
	while((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) p++;
	while(*p == ' ') p++;

	std::cout << "Recenica bez prve rijeci glasi: " << p << std::endl;



	return 0;
}
