#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProst(int n)
{
	if(n<1) return false;
	if(n==1) return false;

	for(int i=2; i<=std::sqrt(n); i++)
	{
		if(n%i == 0) return false;
	}
	return true;
}


std::vector <int> ProstiBrojeviUOpsegu(int a, int b)
{
	std::vector<int> c;

	for(int i=a; i<=b; i++)
	{
		if(DaLiJeProst(i)) c.push_back(i);
		if(i==b) break;
	}
	return c;

}

int main ()
{
	int a, b;

	std::cout << "Unesite pocetnu i krajnju vrijednost: ";
	std::cin >> a >> b;

	std::vector<int> vektor;

	vektor = ProstiBrojeviUOpsegu(a, b);

	if(vektor.size() > 0)
	{
		std::cout << "Prosti brojevi u rasponu od " << a << " do "<< b << " su: ";
		for(int i=0; i<vektor.size()-1; i++)
		{
			std::cout << vektor.at(i) << ", ";
		}

		std::cout << vektor.at(vektor.size()-1) << std::endl;
	}
	else
	{
		std::cout << "Nema prostih brojeva u rasponu od " << a << " do " << b << "!";
	}

	return 0;
}
