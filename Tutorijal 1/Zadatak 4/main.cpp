#include <iostream>
#include <cmath>

int main ()
{
    double n;

    for(;;)
    {
        std::cout << "Unesite prirodan broj ili 0 za kraj: ";
        std::cin >> n;



        if(!std::cin)
        {
            std::cout << "Niste unijeli prirodan broj!" << std::endl;
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            continue;
        }
        if(n < 0 || n != int(n))
        {
            std::cout << "Niste unijeli prirodan broj!" << std::endl;
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            continue;
        }
        if(n == 0)
        {
            std::cout << "Dovidjenja!" << std::endl;
            break;
        }

        int zbir(0);

        for(int i=1; i<n; i++)
        {
            if(int(n)%i == 0) zbir = zbir + i;
        }

        if(zbir == n) std::cout << "Broj " << n << " je savrsen!" << std::endl;
        else if(zbir < n) std::cout << "Broj " << n << " je manjkav!" << std::endl;
        else std::cout << "Broj " << n << " je obilan!" << std::endl;


    }


	return 0;
}
