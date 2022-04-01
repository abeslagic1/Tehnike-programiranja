#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>

const double PI = std::atan(1) * 4;

class Krug
{
	double poluprecnik;

	public:

	explicit Krug(double poluprecnik)
	{
		if(poluprecnik <= 0) throw std::domain_error ("Neispravan poluprecnik");
		Krug::poluprecnik = poluprecnik;
	}

	void Postavi(double poluprecnik)
	{
		if(poluprecnik <= 0) throw std::domain_error ("Neispravan poluprecnik");
		Krug::poluprecnik = poluprecnik;
	}

	double DajPoluprecnik() const
	{
		return Krug::poluprecnik;
	}

	double DajObim() const
	{
		return 2 * Krug::poluprecnik * PI;
	}

	double DajPovrsinu() const
	{
		return Krug::poluprecnik * Krug::poluprecnik * PI;
	}

	double Skaliraj(double x)
	{
		if(x <= 0) throw std::domain_error("Neispravan faktor skaliranja");
		return Krug::poluprecnik *= x;
	}

	void Ispisi() const
	{
		std::cout << std::fixed << std::setprecision(5) << "R=" << DajPoluprecnik() << " O=" << DajObim()  << " P=" << DajPovrsinu();
	}

	friend double DajPovrsinu(Krug k);
};

double DajPovrsinu(Krug k)
{
	return k.DajPovrsinu();
}

class Valjak
{
	Krug baza;
	double visina;

	public:

	Valjak(double poluprecnik, double visina) : baza(poluprecnik)
	{
		if(poluprecnik <= 0) throw std::domain_error ("Neispravan poluprecnik");
		if(visina <= 0) throw std::domain_error("Neispravna visina");
		Valjak::visina = visina;
	}

	void Postavi(double poluprecnik, double visina)
	{
		if(poluprecnik <= 0) throw std::domain_error ("Neispravan poluprecnik");
		if(visina <= 0) throw std::domain_error("Neispravna visina");
		baza.Postavi(poluprecnik);
		//Krug baza (6);

		Valjak::visina = visina;
	}

	Krug DajBazu() const
	{
		return baza;
	}

	double DajPoluprecnikBaze() const
	{
		return baza.DajPoluprecnik();
	}

	double DajVisinu() const
	{
		return visina;
	}

	double DajPovrsinu() const
	{
		return 2 * baza.DajPovrsinu() +  baza.DajObim() * visina;
	}

	double DajZapreminu() const
	{
		return baza.DajPovrsinu() * visina;
	}

	void Skaliraj(double x)
	{
		if(x <= 0) throw std::domain_error("Neispravan faktor skaliranja");

		visina *= x;
		baza.Postavi(baza.DajPoluprecnik() * x);
	}

	void Ispisi() const
	{
		std::cout << std::fixed << std::setprecision(5) << "R=" << DajPoluprecnikBaze() << " H=" << DajVisinu() << " P=" << DajPovrsinu() << " V=" << DajZapreminu();
	}
};



int main ()
{
	return 0;
}
