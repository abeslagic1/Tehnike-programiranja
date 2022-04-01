#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

int NajvecaSirina(std::vector<std::vector<int>> a)
{
    int max(0), broj(0), pomocna(0);

    for(int i=0; i<a.size(); i++)
    {
        for(int j=0; j<a.at(i).size(); j++)
        {
            pomocna = 0;
            broj = a.at(i).at(j);
            if(broj < 0) pomocna++;
            broj = std::abs(a.at(i).at(j));
            while(broj != 0)
            {
                broj /=10;
                pomocna ++;
            }
            if(pomocna > max) max = pomocna;
        }

    }
    return max;
}

std::vector<std::vector<int>> KroneckerovProizvod(std::vector<int> a, std::vector<int> b)
{
    std::vector<std::vector<int>> Matrica;

    Matrica.resize(a.size());

    for(int i=0; i<a.size(); i++)
    {
        Matrica.at(i).resize(b.size());
    }

    for(int i=0; i<a.size(); i++)
    {
        for(int j=0; j<b.size(); j++)
        {
            Matrica.at(i).at(j) = a.at(i)*b.at(j);
        }
    }
    return Matrica;
}


int main ()
{
    std::vector<int> a, b;
    int m, n, x, y;


    std::cout << "Unesite broj elemenata prvog vektora: ";
    std::cin >> m;

   // a.resize(m);

    std::cout << "Unesite elemente prvog vektora: ";
    for(int i=0; i<m; i++)
    {
        std::cin >> x;
        a.push_back(x);
    }

    std::cout << "Unesite broj elemenata drugog vektora: ";
    std::cin >> n;

    //b.resize(n);

    std::cout << "Unesite elemente drugog vektora: " << std::endl;

    for(int i=0; i<n; i++)
    {
        std::cin >> y;
        b.push_back(y);
    }

    std::vector<std::vector<int>> mat;

    mat = KroneckerovProizvod(a,b);

    int sirina = NajvecaSirina(mat);

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            std::cout << std::right << std::setw(sirina+1) << mat.at(i).at(j);
        }
        std::cout << std::endl;
    }

	return 0;
}
