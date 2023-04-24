#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H
#include <iostream>
#include <string>
#include <vector>

#include "MetodyPomocnicze.h"
#include "Adresat.h"

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
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void dopiszAdresataDoPliku(Adresat adresat);
    void ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata);
    int pobierzIdOstatniegoAdresata();
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
};

#endif // PLIKZADRESATAMI_H
