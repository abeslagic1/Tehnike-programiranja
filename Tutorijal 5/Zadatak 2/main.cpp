#include <iostream>
#include <vector>
#include <deque>

template <typename tip1, typename tip2>
// moze se na dva nacina odrediti povratni tip funkcije
// auto Razmijeni Blokove(tip1 pok1, tip1 pok2, tip2 pok3) -> decltype(pok3)

tip2 RazmijeniBlokove(tip1 pok1, tip1 pok2, tip2 pok3)
{
	while(pok1 != pok2)
	{
		char temp = *pok1;
		*pok1 = *pok3;
		*pok3 = temp;

		pok1++;
		pok3++;
	}
	return pok3;
}

int main ()
{
	std::vector<int> v {1, 2, 3, 4, 5};
	std::deque<int> d {6 , 7, 8, 9, 10};


	RazmijeniBlokove(v.begin(), v.end(), d.begin());
	return 0;
}
