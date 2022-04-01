#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <memory>


class Tim
{
    char ime_tima[20];
    int broj_odigranih = 0;
    int broj_pobjeda = 0;
    int broj_nerjesenih = 0;
    int broj_poraza = 0;
    int broj_datih = 0;
    int broj_primljenih = 0;
    int broj_poena = 0;
public:
    Tim(const char *ime) {
        if(std::strlen(ime) > 19) throw std::range_error("Predugacko ime tima");
        int vel = std::strlen(ime) + 1;
        std::copy(ime, ime + vel, ime_tima);
    }
    void ObradiUtakmicu(int broj_datih, int broj_primljenih);

    const char *DajImeTima() const {
        return ime_tima;
    }

    int DajBrojPoena() const {
        return broj_poena;
    }

    int DajGolRazliku() const {
        return broj_datih - broj_primljenih;
    }
    void IspisiPodatke() const {
        std::cout << std::setw(20) << std::left << ime_tima << std::right << std::setw(4) << broj_odigranih << std::setw(4) << broj_pobjeda << std::setw(4) << broj_nerjesenih << std::setw(4)  << broj_poraza << std::setw(4)
                  << broj_datih << std::setw(4) << broj_primljenih << std::setw(4) << broj_poena << std::setw(4) << std::endl;
    }


};

void Tim::ObradiUtakmicu(int broj_datih, int broj_primljenih)
{
    if(broj_datih < 0|| broj_primljenih < 0) throw std::range_error("Neispravan broj golova");
    if(broj_datih > broj_primljenih) {
        broj_poena += 3;
        broj_pobjeda++;
    } else if(broj_datih == broj_primljenih) {
        broj_poena++;
        broj_nerjesenih++;
    } else broj_poraza++;
    broj_odigranih++;
    Tim::broj_datih += broj_datih;
    Tim::broj_primljenih += broj_primljenih;
}

class Liga
{

    std::vector<std::shared_ptr<Tim>> timovi;
public:
    explicit Liga() {}
    explicit Liga(std::initializer_list<Tim> lista_timova) {
    	timovi.resize(lista_timova.size());
        int i(0);
        try {
            for(auto x : lista_timova) timovi[i++] = std::make_shared<Tim> (x);
        } catch(...) {
           throw;
        }
    }

    Liga(const Liga &l);
    Liga(Liga &&l);
    Liga &operator =(const Liga &l);
    Liga &operator =(Liga &&l);
    void DodajNoviTim(const char ime_tima[]);
    void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2);
    void IspisiTabelu();

};

Liga::Liga(const Liga &l)
{
    try {
    	timovi.resize(l.timovi.size());
        for(int i = 0; i < l.timovi.size(); i++) timovi[i] = std::make_shared<Tim> (*l.timovi[i]);
    } catch (...) {
        throw;
    }
}

Liga &Liga::operator = (const Liga &l)
{
    //if(timovi.size() != l.timovi.size()) throw std::logic_error("Nesaglasni kapaciteti liga");

        timovi.resize(l.timovi.size());
        for(int i = 0; i < l.timovi.size(); i++)
            timovi[i] = l.timovi[i];

    return *this;
}

Liga::Liga(Liga &&l)
{
    timovi = std::move(l.timovi);
}

Liga &Liga::operator =(Liga &&l)
{
    timovi = std::move(l.timovi);
    return *this;
}

void Liga::DodajNoviTim(const char *ime_tima)
{
    timovi.push_back(std::make_shared<Tim> (ime_tima));
    for(int i=0; i<timovi.size(); i++)
    {
      if(!strcmp(ime_tima, timovi[i]->DajImeTima())) throw std::logic_error("Tim vec postoji");
    }


}

void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2)
{
    bool ima1(false),ima2(false);
    int indx1,indx2;
    for(int i = 0; i < timovi.size(); i++) {
        if(!strcmp(tim1, timovi[i]->DajImeTima())) {
            ima1 = true; indx1 = i;
        }
        if(!strcmp(tim2, timovi[i]->DajImeTima())) {
            ima2 = true;
            indx2 = i;
        }
    }
    if(ima1 == false || ima2 == false) throw std::logic_error("Tim nije nadjen");
    if(rezultat_1 < 0 || rezultat_2 < 0) throw std::range_error("Neispravan broj golova");

    timovi[indx1]->ObradiUtakmicu(rezultat_1,rezultat_2);
    timovi[indx2]->ObradiUtakmicu(rezultat_2,rezultat_1);

}

void Liga::IspisiTabelu()
{
    std::sort(timovi.begin(), timovi.end(), [] (std::shared_ptr<Tim> t1, std::shared_ptr<Tim> t2) {
        if(t1->DajBrojPoena() != t2->DajBrojPoena()) return t1->DajBrojPoena() > t2->DajBrojPoena();
        else if(t1->DajGolRazliku() != t2->DajGolRazliku()) return t1->DajGolRazliku() > t2->DajGolRazliku();
        else {
            if(strcmp(t1->DajImeTima(), t2->DajImeTima()) < 0) return true;
            return false;
        }
    });
    for(int i = 0; i < timovi.size(); i++) timovi[i]->IspisiPodatke();
}

int main ()
{
    return 0;
}
