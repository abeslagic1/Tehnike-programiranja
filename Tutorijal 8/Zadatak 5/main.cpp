#include <iostream>
#include <utility>
#include <tuple>

typedef std::tuple<double, double, double> Vektor3d;

void UnesiVektor(Vektor3d &v)
{
    std::cout << "X = ";
    std::cin >> std::get<0>(v);
    std::cout << "Y = ";
    std::cin >> std::get<1>(v);
    std::cout << "Z = ";
    std::cin >> std::get<2>(v);
}

Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2)
{
    Vektor3d h;
    //return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
    std::get<0>(h) = std::get<0>(v1) + std::get<0>(v2);
    std::get<1>(h) = std::get<1>(v1) + std::get<1>(v2);
    std::get<2>(h) = std::get<2>(v1) + std::get<2>(v2);

    return h;
}
Vektor3d VektorskiProizvod(const Vektor3d &v1, const Vektor3d &v2)
{
    //return {v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x};
    Vektor3d h;

    std::get<0>(h) = std::get<1>(v1) * std::get<2>(v2) - std::get<2>(v1) * std::get<1>(v2);
    std::get<1>(h) = std::get<2>(v1) * std::get<0>(v2) - std::get<0>(v1) * std::get<2>(v2);
    std::get<2>(h) = std::get<0>(v1) * std::get<1>(v2) - std::get<1>(v1) * std::get<0>(v2);

    return h;

}


void IspisiVektor(const Vektor3d &v)
{
    double a, b, c;
    std::tie(a, b, c) = v;
    std::cout << "{" << a << "," << b << "," << c << "}";
}
int main()
{
    Vektor3d a, b;
    std::cout << "Unesi prvi vektor:\n";
    UnesiVektor(a);
    std::cout << "Unesi drugi vektor:\n";
    UnesiVektor(b);
    std::cout << "Suma ova dva vektora je: ";
    IspisiVektor(ZbirVektora(a, b));
    std::cout << std::endl << "Njihov vektorski prozivod je: ";
    IspisiVektor(VektorskiProizvod(a, b));
    return 0;
}
