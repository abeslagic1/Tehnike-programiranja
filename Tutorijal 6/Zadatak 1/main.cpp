#include <iostream>
#include <new>
#include <stdexcept>
#include <cmath>

template <typename tip>
tip* GenerirajStepeneDvojke(int n)
{
    if(n <= 0) throw std::domain_error ("Broj elemenata mora biti pozitivan");

    tip *pok(new tip[n]);
    for(int i=0; i<n; i++)
    {
        pok[i] = std::pow(2,i);
    }

    return pok;
}

int main()
{
    int br;
    std::cout << "Koliko zelite elemenata: ";
    std::cin >> br;

    try
    {
        int *a = GenerirajStepeneDvojke<int>(br);

        for(int i=0; i < br; i++)
        {
            std::cout << a[i] << " " ;
        }

        delete[] a;
    }
    catch(std::domain_error izuzetak)
    {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
    catch(...)
    {
        std::cout << "Pogresan izuzetak! ";
    }

    return 0;
}
