#include <iostream>
#include <algorithm>
#include <cmath>

void Unos(int &x)
{
	std::cin >> x;
}

bool DaLiJeKvadrat(int x)
{
	double a(std::sqrt(x));
	a+=0.00001;

	a = int(a);
	if(a * a == x) return true;
	else return false;
}

bool Trocifren(int x)
{
    int br(3);
    int brojac(0);
    int h = x;

    if(h < 10 && h > 0) return true;

    while(h!=0)
    {
        h/=10;
        brojac++;
    }
    if(brojac == br) return true;
}


int main ()
{
	int niz[1000], niz2[1000], n;

	std::cout << "Unesite broj elemenata (max. 1000): ";
	std::cin >> n;

	std::cout << "Unesite elemente: ";
	std::for_each(niz, niz + n, Unos);

	int *a = std::max_element(niz, niz + n);
	std::cout << "Najveci element niza je: " << *a << std::endl;

	int *b = std::min_element(niz, niz + n);

	std::cout << "Najmanji element se pojavljuje " << std::count(niz, niz + n, *b) << " puta u nizu" << std::endl;

	int d = std::count_if(niz, niz + n, DaLiJeKvadrat);

	std::cout << "U nizu ima " << d << " brojeva koji su potpuni kvadrati" << std::endl;

	int minelement = *std::min_element(niz, niz + n, [](int y, int z)
	{
		auto suma1(0), suma2(0);

		while(y != 0)
		{
			y/=10;
			suma1++;
		}
		while(z != 0)
		{
			z/=10;
			suma2++;
		}

		return suma1<suma2;
	});

	std::cout << "Prvi element sa najmanjim brojem cifara je " << minelement << std::endl;

	return 0;
}
