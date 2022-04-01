#include <iostream>
#include <cmath>

int main ()
{
    double a, b, c;

    std::cout << "Unesite tri broja: ";
    std::cin >> a >> b >> c;

    if(a<0 || b<0 || c<0 || a+b<=c || a+c<=b || b+c<=a) std::cout <<"Ne postoji trougao cije su duzine stranica " << a << ", " << b << " i " << c << "!";

    else
    {
        double obim, povrsina, s;

        obim = a + b + c;

        s = (a + b + c) / 2;

        povrsina = std::sqrt(s*(s-a)*(s-b)*(s-c));


        std::cout << "Obim trougla sa duzinama stranica " << a << ", " << b << " i " << c << " iznosi " << obim << "." << std::endl
        << "Njegova povrsina iznosi " << povrsina << "." << std::endl;


        double pi = 4*atan(1);
        double u1, u2, u3;

        u1 = acos((a*a + b*b - c*c) / (2*a*b));
        u2 = acos((-a*a + b*b + c*c) / (2*b*c));
        u3 = acos((a*a - b*b + c*c) / (2*a*c));

      //  std::cout << "uglovi: " << u1 << std::endl << u2 << std::endl << u3 << std::endl;

        double stepen1, stepen2, stepen3;

        stepen1 = u1*(180./pi);
        stepen2 = u2*(180./pi);
        stepen3 = u3*(180./pi);


       // std::cout << "Stepeni :" << stepen1 << std::endl << stepen2 << std::endl << stepen3 << std::endl;

        if((stepen1 <= stepen2) && (stepen1 <= stepen3))
        {
            int stepeni = stepen1;
            int minute = (stepen1 - stepeni)*60;
            int sekunde = (((stepen1 - stepeni)*60)-minute)*60;
            std::cout << "Njegov najmanji ugao ima " << stepeni << " stepeni, "
            << minute << " minuta i " << sekunde << " sekundi. " << std::endl;
        }

        else if((stepen2 <= stepen1) && (stepen2 <= stepen3))
        {
            int stepeni = stepen2;
            int minute = (stepen2 - stepeni)*60;
            int sekunde = (((stepen2 - stepeni)*60)-minute)*60;
            std::cout << "Njegov najmanji ugao ima " << stepeni << " stepeni, "
            << minute << " minuta i " << sekunde << " sekundi. " << std::endl;

        }

        else if((stepen3 < stepen2) && (stepen3 < stepen1))
        {
            int stepeni = stepen3;
            int minute = (stepen3 - stepeni)*60;
            int sekunde = (((stepen3 - stepeni)*60)-minute)*60;
            std::cout << "Njegov najmanji ugao ima " << stepeni << " stepeni, "
            << minute << " minuta i " << sekunde << " sekundi. " << std::endl;

        }

    }


	return 0;
}
