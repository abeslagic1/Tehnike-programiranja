#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>

const double PI = std::atan(1)*4;

class Ugao
{
	double radijani;
	void Domen(double &u)
	{
		while(u >= 2*PI)
		{
			u = u - 2*PI;
		}
		while(u < 0)
		{
			u = u + 2*PI;
		}
	}

	public:

	Ugao(double radijani = 0);
	Ugao(int stepeni, int minute, int sekunde);
	void Postavi(double radijani);
	void Postavi(int stepeni, int minute, int sekunde);
	double DajRadijane() const;
	void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde);
	int DajStepene() ;
	int DajMinute() const;
	int DajSekunde() const;
	void Ispisi() ;
	void IspisiKlasicno() ;
	Ugao &SaberiSa(const Ugao &u);
	Ugao &PomnoziSa(double x);
	friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2);
	friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x);

};

Ugao::Ugao(double radijani)
{
	Postavi(radijani);
}

Ugao::Ugao(int stepeni, int minute, int sekunde)
{
	Postavi(stepeni, minute, sekunde);
}

void Ugao::Postavi(double radijani)
{
	Ugao::radijani = radijani;
	Domen(Ugao::radijani);
}

void Ugao::Postavi(int stepeni, int minute, int sekunde)
{
	Ugao::radijani = ((stepeni * 3600) + (minute * 60) + sekunde) * (PI / (180*3600));
	Domen(Ugao::radijani);
}

double Ugao::DajRadijane() const
{
	return Ugao::radijani;
}

void Ugao::OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde)
{


	int temp = radijani * (180 * 3600) / PI;
	sekunde = temp % 60;
	temp /= 60;
	minute = temp % 60;
	temp /= 60;
	stepeni = temp;
}

int Ugao::DajStepene()
{
	Domen(radijani);

	int temp = radijani * (180 * 3600) / PI;
	temp /= 3600;
	int stepeni = temp;

	return stepeni;
}

int Ugao::DajMinute() const
{
	//Domen(radijani);

	int temp = radijani * (180 * 3600) / PI;
	temp /= 60;
	int	minute = temp % 60;

	return minute;
}

int Ugao::DajSekunde() const
{
	//Domen(radijani);
	int temp = radijani * (180 * 3600) / PI;
	int sekunde = temp % 60;

	return sekunde;
}

void Ugao::Ispisi()
{
	//Ugao::Domen(radijani);
	std::cout << std::fixed << std::setprecision(5) << radijani;
}

void Ugao::IspisiKlasicno()
{
	std::cout << DajStepene() << "deg " << DajMinute() << "min " << DajSekunde() << "sec";
}

Ugao &Ugao::SaberiSa(const Ugao &u)
{
	Ugao::radijani += u.DajRadijane();
	Domen(radijani);

	return *this;
}
Ugao &Ugao::PomnoziSa(double x)
{
	radijani *= x;
	Domen(radijani);

	return *this;
}

Ugao ZbirUglova(const Ugao &u1, const Ugao &u2)
{
	Ugao U(u1.DajRadijane() + u2.DajRadijane());

	return U;
}

Ugao ProduktUglaSaBrojem(const Ugao &u, double x)
{
	Ugao U(u.DajRadijane() * x);
	return U;
}


int main ()
{
	Ugao u1, u2(1), u3(100), u4(-55), u5 = 1, u6=-90;
u1.IspisiKlasicno(); std::cout << std::endl;
u2.IspisiKlasicno(); std::cout << std::endl;
u3.IspisiKlasicno(); std::cout << std::endl;
u4.IspisiKlasicno(); std::cout << std::endl;
u5.IspisiKlasicno(); std::cout << std::endl;
u6.IspisiKlasicno(); std::cout << std::endl;
	return 0;
}
