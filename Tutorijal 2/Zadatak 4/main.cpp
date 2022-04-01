
#include <iostream>
#include <complex>

int main ()
{
	int n;
	std::complex<double> Z, Zk, Suma;
	double R, X;

	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;

	for(int i=1; i<=n; i++)
	{
		std::cout << std::endl << "R" << i << " = ";
		std::cin >> R;
		std::cout << "X" << i << " = ";
		std::cin >> X;
		Zk = std::complex<double> (R, X);
		Suma = Suma + (1./Zk);
	}
	Z = 1./Suma;

	std::cout << std::endl << "Paralelna veza ovih elemenata ima R = " << Z.real() << " i " << "X = " << Z.imag() << ".";


	return 0;
}
