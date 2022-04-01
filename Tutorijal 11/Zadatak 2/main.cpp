#include <iostream>
#include <stdexcept>

class StedniRacun
{
	double Stanje;

	static int Br_A;
	static int Br_k;

	public:

	StedniRacun(int stanje = 0)
	{
		if(stanje < 0) throw std::logic_error("Nedozvoljeno pocetno stanje");

		StedniRacun::Stanje = stanje;
		Br_A++;
		Br_k++;
	}

	StedniRacun(const StedniRacun &r)
	{
		Br_A++;
		Br_k++;
	}

	~StedniRacun()
	{
		Br_A--;
	}

	void Ulozi(double ulog)
	{
		if(ulog < 0) throw std::logic_error("Transakcija odbijena");
		StedniRacun::Stanje += ulog;
	}

	void Podigni (double iznos)
	{
		if(iznos > Stanje) throw std::logic_error("Transakcija odbijena");

		Stanje -= iznos;
	}

	double DajStanje() const
	{
		return Stanje;
	}

	void ObracunajKamatu(double kamata)
	{
		if(kamata < 0) throw std::logic_error("Nedozvoljena kamatna stopa");

		Stanje = Stanje + Stanje * (kamata/100);
	}

	int static DajBrojKreiranih()
	{
		return Br_k;
	}
	int static DajBrojAktivnih()
	{
		return Br_A;
	}
};

int StedniRacun::Br_A = 0;
int StedniRacun::Br_k = 0;

int main ()
{
	StedniRacun s1(100), s2, s3(200), s4, s5;
{
	StedniRacun s6, s7(1000), s8, s9, s10;
	s9.Ulozi(1000);

	std::cout << s6.DajStanje() << " " << s7.DajStanje() << " " << s8.DajStanje() <<" " << s9.DajStanje() <<" " << s10.DajStanje() << std::endl;
	std::cout << "Broj kreiranih: " << StedniRacun::DajBrojKreiranih() << std::endl;
	std::cout << "Broj aktivnih: " << StedniRacun::DajBrojAktivnih() << std::endl;
}

s1.Podigni(50);
s3.Podigni(200);
s2.Ulozi(555);

try {

	StedniRacun s6, s7(1000);

	s1.Podigni(50);
	s2.Podigni(555);
	s4.ObracunajKamatu(-10);
	StedniRacun s8, s9, s10;
	s3.Ulozi(555);
	s1.Ulozi(50000);
	s4.Ulozi(33);
	s5.Ulozi(666);
}
catch(std::logic_error e)
{
	std::cout << e.what() << std::endl;
}

std::cout << s1.DajStanje() << " " << s2.DajStanje() << " " << s3.DajStanje() << " " << s4.DajStanje() << " " << s5.DajStanje() << std::endl;
std::cout << "Broj kreiranih: " << StedniRacun::DajBrojKreiranih() << std::endl;
std::cout << "Broj aktivnih: " << StedniRacun::DajBrojAktivnih() << std::endl;

	return 0;
}
