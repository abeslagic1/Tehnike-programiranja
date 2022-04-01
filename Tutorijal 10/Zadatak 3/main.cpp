#include <iostream>
#include <cmath>

class Vektor3d
{
	mutable int brojac=0;
	double koordinate [3];

	public:

	Vektor3d()
	{
		koordinate[0] = 0;
		koordinate[1] = 0;
		koordinate[2] = 0;

	}

	Vektor3d(const Vektor3d &v)
	{

		koordinate[0] = v.DajX();
		koordinate[1] = v.DajY();
		koordinate[2] = v.DajZ();

		brojac = 0;
	}

	Vektor3d(double x, double y, double z)
	{
		Postavi(x, y, z);

	}

	int DajBrojIspisa() const
	{
		return brojac;
	}

	void Postavi(double x, double y, double z)
	{
		Vektor3d::koordinate[0] = x;
		Vektor3d::koordinate[1] = y;
		Vektor3d::koordinate[2] = z;
	}

	void Ocitaj(double &x, double &y, double &z) const
	{
		x = Vektor3d::koordinate[0];
		y = Vektor3d::koordinate[1];
		z = Vektor3d::koordinate[2];
	}

	void Ispisi() const
	{
		std::cout << "{" << koordinate[0] << "," << koordinate[1] << "," << koordinate[2] << "}";
		brojac++;
	}

	double DajX() const { return koordinate[0]; }
	double DajY() const { return koordinate[1]; }
	double DajZ() const { return koordinate[2]; }

	double DajDuzinu() const { return std::sqrt(koordinate[0] * koordinate[0] + koordinate[1] * koordinate[1] + koordinate[2] * koordinate[2]); }

	Vektor3d &PomnoziSaSkalarom(double s)
	{
		koordinate[0] *= s;
		koordinate[1] *= s;
		koordinate[2] *= s;

		return *this;
	}

	Vektor3d &SaberiSa(const Vektor3d &v)
	{
		koordinate[0] += v.koordinate[0];
		koordinate[1] += v.koordinate[1];
		koordinate[2] += v.koordinate[2];

		return *this;
	}

	void PostaviX(double x)
	{
		Vektor3d::koordinate[0] = x;
	}

	void PostaviY(double y)
	{
		Vektor3d::koordinate[1] = y;
	}

	void PostaviZ(double z)
	{
		Vektor3d::koordinate[2] = z;
	}

	friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);

};

Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2)
{
	double v1_x, v1_y, v1_z, v2_x, v2_y, v2_z;
	v1.Ocitaj(v1_x, v1_y, v1_z);
	v2.Ocitaj(v2_x, v2_y, v2_z);
	Vektor3d v3;

	v3.Postavi(v1_x + v2_x, v1_y + v2_y, v1_z + v2_z);
	return v3;
}


int main ()
{
	Vektor3d v1(1, 1, 1);
	for(int i=0; i<3; i++)
	{
		v1.Ispisi();
		std::cout << " ";
	}
	std::cout << std::endl;

	const Vektor3d v2(v1);
	v2.Ispisi();
	std::cout << std::endl;
	std::cout << v2.DajBrojIspisa() << std::endl;

	const Vektor3d v3(v2);
	std::cout << v3.DajBrojIspisa();
	return 0;
}
