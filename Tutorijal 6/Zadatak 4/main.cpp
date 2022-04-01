#include <iostream>
#include <new>
#include <stdexcept>
//#include "TestCurenj.h"

int **KreirajTrougao(int n)
{
    if(n <= 0)
        throw std::domain_error ("Broj redova mora biti pozitivan");

    int **a(nullptr);
    a = new int *[n];

    int vel(0);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2*i+1; j++)
        {
            vel++;
        }
    }

  //  std::cout << vel << std::endl;

    a[0] = new int [vel]{};

   /* for(int i=1; i<n; i++)
        a[i]= nullptr; */

    for(int i=1; i<n; i++)
    {
        a[i] = a[i-1] + 2*(i-1)+1;
    }


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2*i+1; j++)
        {
            if(j < (2*i+1)/2)
                a[i][j] = (2*i+1)/2 - j + 1;
            else
                a[i][j] = j - (2*i+1)/2 + 1;
        }
    }
    return a;
}



int main()
{
    int br;
    std::cout << "Koliko zelite redova: ";
    std::cin >> br;
    try
    {
        int **a = KreirajTrougao(br);

        for(int i=0; i<br; i++)
        {
            for(int j=0; j<2*i+1; j++)
            {
                std::cout << a[i][j] << " ";
            }
            std::cout << std::endl;
        }
        delete[] a[0];

        delete[] a;
    }

    catch(std::domain_error izuzetak)
    {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
    catch(std::bad_alloc)
    {
        std::cout << "Izuzetak: Nedovoljno memorije!";
    }
    catch(...)
    {

    }

    return 0;
}
