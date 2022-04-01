#include <iostream>
#include <complex>

int main ()
{
	int n;
	std::complex<double> Z, Zk, Suma;

	std::cout << "Unesite broj elemenata: " << std::endl;
	std::cin >> n;

	for(int i=1; i<=n; i++)
	{
		std::cout << "Z_" << i << " = ";
		std::cin >> Zk;
		Suma = Suma + (1./Zk);
	}
	Z = 1./Suma;

	std::cout << std::endl << "Paralelna veza ovih elemenata ima impedansu Z_ = " << Z << ".";


	return 0;
}
