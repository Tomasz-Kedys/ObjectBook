#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H
#include <iostream>
#include <string>

#include "AdresatManager.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami {
private:
    const string nazwaPlikuZAdresatami;
    Adresat adresat;
    int idOstatniegoAdresata;
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami (NAZWAPLIKUZADRESATAMI){
        idOstatniegoAdresata = 0;
    };
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika, int przekazaneIdZalogowanegoUzytkownika);
    void dopiszAdresataDoPliku(Adresat adresat);
    void ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata);
    int pobierzIdOstatniegoAdresata();
};

#endif // PLIKZADRESATAMI_H
