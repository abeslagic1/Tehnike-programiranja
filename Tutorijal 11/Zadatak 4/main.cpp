
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>

class Tim
{
    char ime_tima[20];
    int broj_odigranih, broj_pobjeda, broj_nerijesenih, broj_poraza, broj_datih, broj_primljenih, broj_poena;

public:
    Tim(const char ime[]);
    void ObradiUtakmicu(int broj_datih, int broj_primljenih);
    const char * DajImeTima() const;
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

Tim::Tim(const char ime[])
{
    if(strlen(ime) > 30) throw std::range_error ("Predugacko ime tima");

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

    if(broj_datih == broj_primljenih)
    {
        broj_odigranih++;
        broj_nerijesenih++;
        Tim::broj_datih += broj_datih;
        Tim::broj_primljenih += broj_primljenih;
        broj_poena++;
    }
    if(broj_datih < broj_primljenih)
    {
        broj_odigranih++;
        broj_poraza++;
        Tim::broj_datih += broj_datih;
        Tim::broj_primljenih += broj_primljenih;
    }
}

const char* Tim::DajImeTima() const
{
    return ime_tima;
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

// Dio vezan za klasu Liga:

class Liga
{
    int broj_timova, max_br_timova;
    Tim **timovi;

public:
    explicit Liga(int velicina_lige) : broj_timova(0), max_br_timova(velicina_lige),
    timovi(new Tim*[velicina_lige]{}) {}
    explicit Liga(std::initializer_list<Tim> lista_timova) : max_br_timova(lista_timova.size()), broj_timova(lista_timova.size()),
    timovi(new Tim*[lista_timova.size()])
    {
        int i(0);
        try{
            for(auto x: lista_timova) timovi[i++] = new Tim(x);
        }
        catch(...)
        {
            for(int i=0; i<broj_timova; i++) delete timovi[i];
            delete [] timovi;
        }
    }
    ~Liga()
    {
        for(int i=0; i<broj_timova; i++) delete timovi[i];
        delete [] timovi;
    }
    Liga(const Liga &l);
    Liga(Liga &&l);
    Liga &operator =(const Liga &l);
    Liga &operator =(Liga &&l);
    void DodajNoviTim(const char ime_tima[]);
    void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2);
    void IspisiTabelu();
};

Liga::Liga(const Liga &l) : broj_timova(l.broj_timova), max_br_timova(l.max_br_timova), timovi(new Tim*[l.max_br_timova] {})
{
    try
    {
        for(int i=0; i<l.broj_timova; i++)
        {
            timovi[i] = new Tim(*l.timovi[i]);
        }
    }
    catch(...)
    {
        for(int i=0; i<broj_timova; i++) delete timovi[i];
        delete [] timovi;
    }
}

Liga &Liga::operator = (const Liga &l)
{
    if(max_br_timova != l.max_br_timova) throw std::logic_error ("Nesaglasni kapaciteti liga");

    if(broj_timova < l.broj_timova)
    {
        try
        {
            for(int i=0; i<broj_timova; i++) delete timovi[i];

            for(int i=0; i<l.broj_timova; i++)
            {
                timovi[i] = new Tim(*l.timovi[i]);
            }
        }
        catch(...)
        {
            for(int i=0; i<broj_timova; i++) delete timovi[i];
            delete [] timovi;
        }
    }
    else
    {
        for(int i=broj_timova; i<l.broj_timova; i++)
        {
            delete timovi[i];
            timovi[i] = nullptr;
        }
    }
    broj_timova = l.broj_timova;
    for(int i=0; i<broj_timova; i++)
    {
        *timovi[i] = *l.timovi[i];
    }
    return *this;
}

Liga::Liga(Liga &&l) : timovi(l.timovi), max_br_timova(l.max_br_timova), broj_timova(l.broj_timova)
{
    l.timovi = nullptr;
    l.broj_timova = 0;
}

Liga &Liga::operator = (Liga &&l)
{
    if(max_br_timova != l.max_br_timova) throw std::logic_error ("Nesaglasni kapaciteti liga");

    std::swap(broj_timova, l.broj_timova);
    std::swap(timovi, l.timovi);

    return *this;
}

void Liga::DodajNoviTim(const char *ime_tima)
{
    Tim tim(ime_tima);

    for(int i=0; i<max_br_timova; i++)
    {
        if(timovi[i] == nullptr)
        {
            try
            {
                timovi[i] = new Tim(tim);
                broj_timova++;
                break;
            }
            catch(std::range_error)
            {
                throw;
            }
            catch(std::bad_alloc)
            {
                for(int i=0; i<broj_timova; i++)
                delete timovi[i];
                delete [] timovi;
            }
        }
        else
        {
            if(!strcmp(ime_tima, timovi[i]->DajImeTima())) throw std::logic_error ("Tim vec postoji");
        }
        if(i == max_br_timova - 1) throw std::range_error("Liga popunjena");
    }
}

void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2)
{
    bool ima1(false), ima2(false);
    int index1, index2;

    for(int i=0; i<broj_timova; i++)
    {
        if(!strcmp(tim1, timovi[i]->DajImeTima()))
        {
            ima1 = true;
            index1 = i;
        }
        if(!strcmp(tim2, timovi[i]->DajImeTima()))
        {
            ima2 = true;
            index2 = i;
        }
    }
    if(ima1 == false || ima2 == false) throw std::logic_error("Tim nije nadjen");
    if(rezultat_1 < 0 || rezultat_2 < 0) throw std::range_error("Neispravan broj golova");

    timovi[index1]->ObradiUtakmicu(rezultat_1, rezultat_2);
    timovi[index2]->ObradiUtakmicu(rezultat_2, rezultat_1);
}

void Liga::IspisiTabelu()
{
    std::sort(timovi, timovi + broj_timova, [](Tim *t1, Tim *t2)
              {
                if(t1->DajBrojPoena() != t2->DajBrojPoena()) return t1->DajBrojPoena() > t2->DajBrojPoena();
        else if(t1->DajGolRazliku() != t2->DajGolRazliku()) return t1->DajGolRazliku() > t2->DajGolRazliku();
        else {
            if(strcmp(t1->DajImeTima(), t2->DajImeTima()) < 0) return true;
            return false;
        }
    });
    for(int i = 0; i < broj_timova; i++) timovi[i]->IspisiPodatke();

}

int main()
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
