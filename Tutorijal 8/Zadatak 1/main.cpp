#include <iostream>
#include <iomanip>
#include <stdexcept>

struct Vrijeme
{
    int sati, minute, sekunde;
};

void TestirajVrijeme(Vrijeme v)
{
    if(v.sati < 0 || v.sati > 23 || v.minute < 0 || v.minute > 59 || v.sekunde < 0 || v.sekunde > 59) throw std::domain_error ("Neispravno vrijeme");
}

void IspisiVrijeme(Vrijeme v)
{
    TestirajVrijeme(v);

    std::cout << std::setw(2) << std::setfill('0') << v.sati << ":"
              << std::setw(2) << std::setfill('0') << v.minute << ":"
              << std::setw(2) << std::setfill('0') << v.sekunde;
}

Vrijeme SaberiVrijeme(Vrijeme v1, Vrijeme v2)
{
    TestirajVrijeme(v1);
    TestirajVrijeme(v2);
    Vrijeme v3;

    v3.sati = v1.sati + v2.sati;
    v3.minute = v1.minute + v2.minute;
    v3.sekunde = v1.sekunde + v2.sekunde;

    if(v3.sekunde > 59)
    {
        v3.sekunde -= 60;
        v3.minute ++;
    }

    if(v3.minute > 59)
    {
        v3.minute -= 60;
        v3.sati++;
    }

    if(v3.sati > 23) v3.sati -=24;

    return v3;
}

int main ()
{
    try{

    Vrijeme v1, v2;

    std::cout << "Unesite prvo vrijeme (h m s): ";
    std::cin >> v1.sati >> v1.minute >> v1.sekunde;

    TestirajVrijeme(v1);

    std::cout << "Unesite drugo vrijeme (h m s): ";
    std::cin >> v2.sati >> v2.minute >> v2.sekunde;

    TestirajVrijeme(v2);

    std::cout  << "Prvo vrijeme: "; IspisiVrijeme(v1);
    std::cout << std::endl << "Drugo vrijeme: "; IspisiVrijeme(v2);

    Vrijeme v3(SaberiVrijeme(v1, v2));

    std::cout << std::endl << "Zbir vremena: "; IspisiVrijeme(v3);
    }
    catch(std::domain_error e)
    {
        std::cout << e.what();
    }
    return 0;
}
