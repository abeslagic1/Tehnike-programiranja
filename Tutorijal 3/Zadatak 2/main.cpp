#include <iostream>
#include <vector>


bool paran(int n)
{
    int suma(0), x;

    while(n!=0)
    {
        x=n%10;
        suma+=x;
        n=n/10;

    }

    if(suma % 2 == 0) return true;
    else return false;
}

std::vector<int> IzdvojiElemente (std::vector<int> h, int n)
{
    std::vector<int> v;

    for(int m : h)
    {
        if(paran(m) == n) v.push_back(m);
    }
    return v;
}

int main ()
{
    int br_elemenata, x;
    std::vector<int> a, b, c;

    std::cout << "Koliko zelite unijeti elemenata: ";
    std::cin >> br_elemenata;

    if(br_elemenata<=0)
    {
        std::cout << "Broj elemenata mora biti veci od 0!";
        return 0;
    }

    std::cout << "Unesite elemente: ";

    for(int i=0; i<br_elemenata; i++)
    {
        std::cin >> x;
        a.push_back(x);
    }

    b = IzdvojiElemente(a, 1);
    c = IzdvojiElemente(a, 0);

    for(int i=0; i<b.size(); i++)
    {
       if(i == b.size()-1) std::cout << b.at(i);
       else std::cout << b.at(i) << ",";
    }

    std::cout << std::endl;

    for(int i=0; i<c.size(); i++)
    {
        if(i == c.size()-1) std::cout << c.at(i);
       else std::cout << c.at(i) << ",";
    }
    std::cout << std::endl;

	return 0;
}
