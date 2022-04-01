#include <iostream>
#include <cmath>
#include <limits>


int Cifre(long long int n, int &c_min, int &c_max)
{
    long long int nn(n);
    int broj, brojac(0);
    int min(9), max(0);

    if(nn == 0)
    {
        c_max = 0;
        c_min = 0;
        return 1;
    }

    while(nn != 0)
    {
        broj = std::abs(nn % 10);
        if(broj > max) max = broj;
        if(broj < min) min = broj;
        brojac++;
        nn = nn/10;
    }

    c_max = max;
    c_min = min;

    return brojac;

}

int main ()
{
    long long int br;
    int rez;
    int a(9), b(0);

    //std::cout << "Numeric limits min: " << std::numeric_limits<long long int>::min() << std::endl;
    //std::cout << "Numeric limits max: " << std::numeric_limits<long long int>::max() << std::endl;

    std::cout << "Unesite broj: ";
    std::cin >> br;

    rez = Cifre(br, a, b);

    std::cout << "Broj " << br << " ima " << rez << " cifara, najveca je " << b << " a najmanja " << a << ".";

	return 0;
}
