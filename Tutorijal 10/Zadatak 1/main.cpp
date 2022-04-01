#include <iostream>
#include <stdexcept>

class StedniRacun
{
	double Stanje;

	public:

	StedniRacun(int stanje = 0)
	{
		if(stanje < 0) throw std::logic_error("Nedozvoljeno pocetno stanje");

		StedniRacun::Stanje = stanje;
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
};



int main ()
{
	return 0;
}
