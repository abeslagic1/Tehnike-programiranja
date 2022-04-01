#include <iostream>
#include <vector>

template <typename tip1>
    std::vector<tip1> Presjek(std::vector<tip1> v1, std::vector<tip1> v2)
    {
        std::vector<tip1> rez;
        int postoji(0);

        for(int i=0; i<v1.size(); i++)
        {
            for(int j=0; j<v2.size(); j++)
            {
                if(v1.at(i) == v2.at(j))
                {
                    postoji = 0;

                    for(int k=0; k<rez.size(); k++)
                    {
                        if(v1.at(i) == rez.at(k)) postoji = 1;
                    }
                    if(postoji == 0) rez.push_back(v1.at(i));
                }
            }
        }
        return rez;
    }


int main ()
{
    int n1, n2;
    std::vector<double> v1, v2, v3;
    std::cout << "Test za realne brojeve..." << std::endl;
    std::cout << "Unesite broj elemenata prvog vektora: ";
    std::cin >> n1;
    std::cout << "Unesite elemente prvog vektora: ";

    for(int i=0; i<n1; i++)
    {
        int br;
        std::cin >> br;
        v1.push_back(br);
    }
    std::cout << "Unesite broj elemenata drugog vektora: ";
    std::cin >> n2;
    std::cout << "Unesite elemente drugog vektora: ";

    for(int i=0; i<n2; i++)
    {
        int br;
        std::cin >> br;
        v2.push_back(br);
    }


    v3 = Presjek(v1, v2);

    std::cout << "Zajednicki elementi su: ";
    for(int i=0; i<v3.size(); i++)
    {
        std::cout << v3.at(i) << " ";
    }

    std::cout << std::endl << std::endl;

    std::vector<std::string> vs1, vs2;
    int n3, n4;

    std::cout << "Test za stringove... " << std::endl;
    std::cout << "Unesite broj elemenata prvog vektora: ";
    std::cin >> n3;
    std::cout << "Unesite elemente prvog vektora (ENTER nakon svakog unosa): ";
    vs1.resize(n3);

    for(int i=0; i<n3; i++)
    {
        std::cin >> vs1.at(i);
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    std::cout << "Unesite broj elemenata drugog vektora: ";
    std::cin >> n4;
    std::cout << "Unesite elemente drugog vektora (ENTER nakon svakog unosa): ";
    vs2.resize(n4);

    for(int i=0; i<n4; i++)
    {
        std::cin >> vs2.at(i);
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    std::vector<std::string> vs3 (Presjek(vs1, vs2));

    std::cout << "Zajednicki elementi su: " << std::endl;
    for(int i=0; i<vs3.size(); i++)
    {
        std::cout << vs3.at(i) << " " ;
    }


	return 0;
}
