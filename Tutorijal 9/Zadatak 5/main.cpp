#include <iostream>
#include <iomanip>
#include <stdexcept>

class Sat
{
    int s;

public:
    static bool DaLiJeIspravno(int sat, int minuta, int sekunda);
    void Postavi(int sat, int minuta, int sekunda);
    void PostaviNormalizirano(int sati, int minute, int sekunde);
    Sat Sljedeci();
    Sat Prethodni();
    Sat PomjeriZa(int broj);
    void Ispisi() const
    {
    	int sati, minute, sekunde, r;

    	sati = DajSate();
    	minute = DajMinute();
    	sekunde = DajSekunde();

    	if(sekunde < 0)
    	{
    		r = 0 - sekunde ;
    		sekunde = 60 - r;
    		minute --;
    	}
    	if(minute < 0)
    	{
    		r = 0 - minute;
    		minute = 60 - r;
    		sati--;
    	}
    	if(sati < 0)
    	{
    		r = 0 - sati;
    		sati = 24 - r;
    	}

    	if(sekunde == 60) minute ++;
    	if(minute == 60) sati++;
    	if(sati == 24) sati = 0;



        std::cout << std::setfill('0') << std::setw(2) << sati << ":" << std::setfill('0') << std::setw(2) << minute<< ":" << std::setfill('0') << std::setw(2) << sekunde << std::endl;
    }
    int DajSate() const
    {
        return s / 3600;
    }
    int DajMinute() const
    {
        int sat, minuta;

        sat = int(s/3600);

        minuta = int((s - sat * 3600) / 60);
        return minuta;
    }
    int DajSekunde() const
    {
        int sat, minuta, sekunda;

        sat = int(s/3600);

        minuta = int((s - sat * 3600) / 60);

        sekunda = s - (sat * 3600) - (minuta * 60);

        return sekunda;
    }
    friend int BrojSekundiIzmedju(Sat &s1, Sat &s2);
    static int Razmak(Sat &s1, Sat &s2);
};

bool Sat::DaLiJeIspravno(int sat, int minuta, int sekunda)
{
    if(sat < 0 || sat > 23 || minuta < 0 || minuta > 59 || sekunda < 0 || sekunda > 59) return false;
    return true;
}

void Sat::Postavi(int sat, int minuta, int sekunda)
{
    if(sat < 0 || sat > 23 || minuta < 0 || minuta > 59 || sekunda < 0 || sekunda >59) throw std::domain_error("Neispravno vrijeme");


    s = sekunda + minuta*60 + sat*3600;
}

void Sat::PostaviNormalizirano(int sati, int minute, int sekunde)
{
    if(sati < 0 || minute < 0 || sekunde < 0) {

		if(sekunde > 59)
		{

			int buduce_minute=0;
			int buduce_sekunde=0;
			int temp(sekunde);

			buduce_minute = sekunde / 60;
			buduce_sekunde = sekunde % 60;

			sekunde = buduce_sekunde;
			minute += buduce_minute;
		}
		if(minute > 59)
		{
		    int buduci_sati=0;
			int buduce_minute=0;
			int temp(minute);

			buduci_sati = minute / 60;
			buduce_minute = minute % 60;

			minute = buduce_minute;
			sati += buduci_sati;
		}
		if(sati > 23) sati = sati  % 24;



		if(sekunde < 0)
		{
			sekunde = 60 + sekunde;
			minute--;
		}
		if(minute < 0)
		{
			minute = 60 + minute;
			sati--;
		}
		if(sati < 0) sati = 24 + (sati % 24);
	}
	else
	{
		if(sekunde > 59)
		{

			int buduce_minute=0;
			int buduce_sekunde=0;
			int temp(sekunde);

			buduce_minute = sekunde / 60;
			buduce_sekunde = sekunde % 60;

			sekunde = buduce_sekunde;
			minute += buduce_minute;
		}
		if(minute > 59)
		{
		    int buduci_sati=0;
			int buduce_minute=0;
			int temp(minute);

			buduci_sati = minute / 60;
			buduce_minute = minute % 60;

			minute = buduce_minute;
			sati += buduci_sati;
		}
		if(sati > 23) sati = sati  % 24;
	}
    s = sekunde + minute*60 + sati*3600;


}

Sat Sat::Sljedeci()
{
    s++;


    return *this;
}

Sat Sat::Prethodni()
{
   s--;
   return *this;
}

Sat Sat::PomjeriZa(int broj)
{
    s += broj;
    return *this;
}

int BrojSekundiIzmedju(Sat &s1, Sat &s2)
{
    return s1.s - s2.s;
}

int Sat::Razmak(Sat &s1, Sat &s2)
{
    return s1.s - s2.s;
}


int main()
{/*
    Sat s1, s2, s3, k;
    std::cout << "S1: ";
	s1.Postavi(3600);
	s1.Ispisi();

	std::cout << std::endl << "S2: ";

	s2.Postavi(60);
	s2.Ispisi();

	std::cout << std::endl << "S3: ";

	s3.Postavi(3);
	s3.Ispisi();

	std::cout << std::endl << "K: ";

	k.Postavi( 8951);
	k.Ispisi();

	std::cout << std::endl << "K pomjereno: ";
	k.PomjeriZa(10);
	k.Ispisi();


	std::cout << std::endl <<BrojSekundiIzmedju(s1,k) << std::endl << std::endl;

//	sk.Postavi(-1234, 1234, 2134);
	//sk.PostaviNormalizirano(-1234, 1234, 2134);
	//sk.Ispisi();*/
    return 0;
}
