#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H
#include <iostream>
#include <string>

#include "UzytkownikManager.h"
#include "AdresatManager.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami {
private:
    string nazwaPlikuZAdresatami = "Adresaci.txt";
    Adresat adresat;
    UzytkownikManager uzytkownikManager;
    MetodyPomocnicze metodyPomocnicze;
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
public:
    PlikZAdresatami();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void dopiszAdresataDoPliku(Adresat adresat);
};

#endif // PLIKZADRESATAMI_H
