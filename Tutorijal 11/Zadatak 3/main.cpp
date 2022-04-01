#include <iostream>
#include <string>
#include <stdexcept>
#include <cstring>
#include <iomanip>


class Tim
{
	char ime_tima[20];
	int broj_odigranih, broj_pobjeda, broj_nerijesenih, broj_poraza, broj_datih, broj_primljenih, broj_poena;

	public:

	Tim(const char ime []);
	void ObradiUtakmicu(int broj_datih, int broj_primljenih);
	const char *DajImeTima() const
	{
		return ime_tima;
	}
	int DajBrojPoena() const
	{
		return broj_poena;
	}
	int DajGolRazliku() const
	{
		return broj_datih - broj_primljenih;
	}
	void IspisiPodatke() const;
};

Tim::Tim(const char ime [])
{
	if(std::strlen(ime) > 20) throw std::range_error("Predugacko ime tima");

	std::strcpy(ime_tima, ime);

	broj_odigranih = 0;
	broj_pobjeda = 0;
	broj_nerijesenih = 0;
	broj_poraza = 0;
	broj_datih = 0;
	broj_primljenih = 0;
	broj_poena = 0;
}

void Tim::ObradiUtakmicu(int broj_datih, int broj_primljenih)
{
	if(broj_datih < 0 || broj_primljenih < 0) throw std::range_error("Neispravan broj golova");

	if(broj_datih > broj_primljenih)
	{
		broj_odigranih++;
		broj_pobjeda++;
		Tim::broj_datih += broj_datih;
		Tim::broj_primljenih += broj_primljenih;
		broj_poena += 3;
	}

	else if(broj_datih == broj_primljenih)
	{
		broj_odigranih++;
		broj_nerijesenih++;
		Tim::broj_datih += broj_datih;
		Tim::broj_primljenih += broj_primljenih;
		broj_poena++;
	}

	else if(broj_datih < broj_primljenih)
	{
		broj_odigranih++;
		broj_poraza++;
		Tim::broj_datih += broj_datih;
		Tim::broj_primljenih += broj_primljenih;
	}
}

void Tim::IspisiPodatke() const
{
	std::cout << std::setw(20) << std::left << DajImeTima() << std::setw(4) << std::right
							   << broj_odigranih << std::setw(4)
							   << broj_pobjeda << std::setw(4)
							   << broj_nerijesenih << std::setw(4)
							   << broj_poraza << std::setw(4)
							   << broj_datih  << std::setw(4)
							   << broj_primljenih << std::setw(4)
							   << broj_poena << std::endl;
}

int main ()
{
	Tim t1("NK Zeljeznicar");
	Tim t2("FK Sarajevo");
	Tim t3("HSK Zrinjski");

	t1.ObradiUtakmicu(1, 0);
	t1.ObradiUtakmicu(3, 0);
	t1.ObradiUtakmicu(2, 1);
	t2.ObradiUtakmicu(1, 1);
	t2.ObradiUtakmicu(1, 0);
	t2.ObradiUtakmicu(0, 5);
	t3.ObradiUtakmicu(0, 1);
	t3.ObradiUtakmicu(0, 2);
	t3.ObradiUtakmicu(1, 1);

	t1.IspisiPodatke();
	t2.IspisiPodatke();
	t3.IspisiPodatke();

	return 0;
}
