#include <iostream>
#include <vector>

bool TestPerioda(std::vector<double> v, int p)
{
	bool periodicna(true);

	if(v.size()<2 || p>=v.size()) return false;

	for(int i=0; i<v.size(); i++)
	{
		if(i+p < v.size())
		{
			if(v.at(i) != v.at(i+p)) periodicna = false;
		}
	}
	return periodicna;
}


int OdrediOsnovniPeriod(std::vector<double> v)
{
	for(int i=1; i<v.size(); i++)
	{
		if(TestPerioda(v,i) == true) return i;
	}
	return 0;
}



int main ()
{
	std::vector<double>v;
	int brojperioda;
	double broj;

	std::cout << "Unesite slijed brojeva (0 za kraj): ";

	for(;;)
	{
		std::cin >> broj;
		if(broj == 0) break;
		v.push_back(broj);
	}


	brojperioda = OdrediOsnovniPeriod(v);

	if(brojperioda == 0) std::cout << "Slijed nije periodican! ";
	else std::cout << "Slijed je periodican sa osnovnim periodom " << brojperioda << ".";

	return 0;
}
