#include <iostream>

class NeobicnaKlasa
{
	public:

	explicit NeobicnaKlasa(int br)
	{
		std::cout << "Direktna inicijalizacija" << std::endl;
	}

	NeobicnaKlasa(double br)
	{
		std::cout << "Kopirajuca inicijalizacija" << std::endl;
	}
};

int main ()
{
	NeobicnaKlasa k1(5);
	NeobicnaKlasa k2 = 5;

	return 0;
}
