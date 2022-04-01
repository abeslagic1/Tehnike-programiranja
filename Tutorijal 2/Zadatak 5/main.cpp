#include <iostream>
#include <complex>
#include <cmath>

int main ()
{
	int n;
	std::complex<double> Z, Zk, Suma;
	double r, fi, fis;

	const double PI (4*std::atan(1));

	std::cout << "Unesi broj elemenata:";
	std::cin >> n;

	for(int i=1; i<=n; i++)
	{
		std::cout << std::endl << "Z" << i << " = ";
		std::cin >> r;
		std::cout << "fi" << i << " = ";
		std::cin >> fi;

		fis = fi * PI / 180;
        Zk = std::polar(r, fis);

		Suma = Suma + (1./Zk);
	}
	Z = 1./Suma;

	std::cout << std::endl << "Paralelna veza ovih elemenata ima Z = " << std::abs(Z) << " i fi = " << std::arg(Z)*180/PI << ".";


	return 0;
}
