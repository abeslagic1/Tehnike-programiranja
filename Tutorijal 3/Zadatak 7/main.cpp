#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <iomanip>

int NajvecaSirina(std::vector<std::vector<int>> v)
{
    int maxi(0), maximaxi(0), broj(0);

    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            maxi = 0;
            broj = v[i][j];
            if(broj < 0)
            {
                broj = fabs(broj);
                maxi++;
            }
            while( broj > 0)
            {
                broj /= 10;
                maxi++;
            }
            if(maxi > maximaxi)
            maximaxi = maxi;
        }

    }
    return maximaxi;
}

std::vector<std::vector<int>> PaskalovTrougao(int broj)
{
    std::vector<std::vector<int>> mat;

    if(broj == 0) return mat;
    if(broj < 0) throw std::domain_error ("Broj redova ne smije biti negativan.");

    // formiram grbavu matricu
    mat.resize(broj);
    for(int i=0; i<broj; i++)
    {
        mat[i].resize(i+1);
    }

    //popunjavam grbavu matricu
    mat[0][0] = 1;
    for(int i=1; i<broj; i++)
    {
        for(int j=0; j<mat[i].size(); j++)
        {
            if(j == 0 || j == i) mat[i][j] = 1;
            else
            {
                mat[i][j] = mat[i-1][j] + mat[i-1][j-1];
            }
        }
    }
    return mat;
}

int main()
{
    int n;
    std::cout << "Unesite broj redova: " << std::endl;
    std::cin >> n;

    std::vector<std::vector<int>> M;

    try
    {
        M = PaskalovTrougao(n);
    }
    catch(...)
    {

    }
    int sirina = NajvecaSirina(M);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<M[i].size(); j++)
        {

            std::cout << std::right << std::setw(sirina+1) <<  M[i][j];
        }
        std::cout << std::endl;

    }

    return 0;
}
