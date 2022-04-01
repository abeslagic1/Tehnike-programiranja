#include <iostream>
#include <stdexcept>
#include <iomanip>

class Sat
{
	int h, m, s;

public:

	static bool DaLiJeIspravno(int h, int m, int s)
	{ //Ovdje bi mozda mogla ici referenca i sto ne ide CONST?
		if(h<0 || h>23 || m<0 || m>59 || s<0 || s>59) return false;

		return true;
	}

	void Postavi(int sat, int min, int sek)
	{
		if(sat<0 || sat>23) throw std::domain_error("Neispravno vrijeme");
		if(min<0 || min>59) throw std::domain_error("Neispravno vrijeme");
		if(sek<0 || sek>59) throw std::domain_error("Neispravno vrijeme");

		h = sat;
		m = min;
		s = sek;
	}


	Sat PomjeriZa(int pomak)
	{
		s = s + pomak;

		if(s > 59)
		{
			s=s-60;
			m++;

			if(m>59)
			{
				m=m-60;
				h++;
			}
			if(h>23) h-=24;

		}
		else
		{
			if(s<0)
			{
				s=60 + s;
				m--;
			}
			if(m<0)
			{
				m=60 + m;
				h--;
			}
			if(h<0) h= 24+h;
		}
		return *this;
	}

	Sat Sljedeci()
	{
		s++;
		//PostaviNormalizirano(int h, int m, int s);

		if(s>59)
		{
			s=s-60;
			m++;
		}
		if(m>59)
		{
			m=m-60;
			h++;
		}
		if(h>23) h-=24;

		return *this;
	}

	Sat Prethodni()
	{
		s--;

		if(s<0)
		{
			s=60 + s;
			m--;
		}
		if(m<0)
		{
			m=60 + m;
			h--;
		}
		if(h<0) h= 24+h;

		//PostaviNormalizirano(int h, int m, int s);

		return *this;
	}


	int DajSate() const {
		return h;
	}
	int DajMinute() const {
		return m;
	}
	int DajSekunde() const {
		return s;
	}

	void Ispisi() const
	{
		std::cout << std::setfill('0') << std::setw(2) << DajSate() << ":" << std::setfill('0') << std::setw(2) << DajMinute() << ":" << std::setfill('0') << std::setw(2) << DajSekunde();
	}
	void PostaviNormalizirano(int h, int m, int s);

	friend int BrojSekundiIzmedju(Sat s1, Sat s2);

	static int Razmak(Sat s1, Sat s2);

};

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
	h = sati;
	m = minute;
	s = sekunde;
}

int BrojSekundiIzmedju(Sat s1, Sat s2)
{
	int vrijeme = s1.h*3600 + s1.m*60 + s1.s -(s2.h*3600 + s2.m*60 + s2.s);

	return vrijeme;
}

int Sat::Razmak(Sat s1, Sat s2)
{
	int vrijeme = s1.h*3600 + s1.m*60 + s1.s -(s2.h*3600 + s2.m*60 + s2.s);

	return vrijeme;
}

int main ()
{
	//std::cout << Sat::DaLiJeIspravno(10,15,30) << std::endl;

	Sat s, k, sk;

	s.Postavi(10, 20, 30);
	s.Ispisi();

	std::cout << std::endl;

	k.Postavi(10, 7, 1);
	k.Ispisi();

	std::cout << std::endl;
	k.PomjeriZa(-10);
	k.Ispisi();


	std::cout << std::endl <<BrojSekundiIzmedju(s,k) << std::endl << std::endl;

//	sk.Postavi(-1234, 1234, 2134);
	sk.PostaviNormalizirano(-1234, 1234, 2134);
	sk.Ispisi();

	//std::cout << std::endl << std::endl <<
	return 0;
}
