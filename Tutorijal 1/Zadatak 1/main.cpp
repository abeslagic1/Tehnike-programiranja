#include <iostream>
#include <cmath>

int main()
{
    int a, b, c, d, BRPL;
    double PB, PP, BrPl;
    const double x(0.00001);

    std::cout << "Unesite duzinu, sirinu i dubinu bazena u metrima: ";
    std::cin >> a >> b >> c;

    std::cout << "Unesite sirinu plocice u centimetrima: ";
    std::cin >> d;

    double d1(double(d)/100);

    PB = a*b + 2*(a*c) + 2*(b*c);
    PP = d1*d1;

    BrPl = PB/PP;
    BRPL = BrPl + x;

    if(fabs(BRPL - BrPl)<x)
    {
        std::cout << std::endl <<"Za poplocavanje bazena dimenzija " << a << "x" << b << "x" << c << "m sa plocicama dimenzija "
        << d << "x" << d << "cm" << std::endl << "potrebno je " << BrPl << " plocica.";
    }

    else
    {
        std::cout << std::endl <<"Poplocavanje bazena dimenzija " << a << "x" << b << "x" << c << "m sa plocicama dimenzija "
        << d << "x" << d << "cm" << std::endl <<"nije izvodljivo bez lomljenja plocica!" << std::endl;
    }

    return 0;
}
