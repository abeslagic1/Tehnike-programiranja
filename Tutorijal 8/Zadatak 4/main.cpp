
#include <iostream>
#include <map>
#include <string>

bool DaLiJeZnak(char znak)
{
    return ((znak >= 'a' && znak <= 'z') || (znak >= '0' && znak <= '9'));
}

std::string ZamijeniPremaRjecniku(std::string recenica, std::map<std::string,std::string> rijecnik)
{
    std::string pomocni;

    for(auto it(recenica.begin()); it != recenica.end(); it++)
    {
        std::string rijec;
        while(it != recenica.end() && !DaLiJeZnak(*it))
        {
            pomocni = pomocni + *it;
            it++;
        }
        while(it != recenica.end() && DaLiJeZnak(*it))
        {
            rijec = rijec + *it;
            it++;
        }

        if(rijecnik.count(rijec))
            pomocni = pomocni + rijecnik[rijec];
        else
        pomocni = pomocni + rijec;
        it--;
    }
    return pomocni;
}

int main ()
{
    std::map<std::string, std::string> moj_rjecnik{{"jabuka", "apple"}, {"da", "yes"}, {"kako", "how"}, {"ne", "no"}, {"majmun", "monkey"}};
    ZamijeniPremaRjecniku ("   kako    da   ne", moj_rjecnik);
	return 0;
}
