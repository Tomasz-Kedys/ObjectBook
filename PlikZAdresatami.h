#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H
#include <iostream>
#include <string>
#include <vector>

#include "MetodyPomocnicze.h"
#include "Adresat.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami : public PlikTekstowy {
private:
    int idOstatniegoAdresata;
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami (string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami (string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata (string daneJednegoAdresataOddzielonePionowymiKreskami);
    const string nazwaTymczasowegoPlikuZAdresatami = "temp.txt";
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public:
    PlikZAdresatami (string nazwaPlikuZAdresatami) : PlikTekstowy (nazwaPlikuZAdresatami) {
        idOstatniegoAdresata = 0;
    };
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami (Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku (int idZalogowanegoUzytkownika);
    void ustawIdOstatniegoAdresata (int noweIdOstatniegoAdresata);
    bool dopiszAdresataDoPliku (Adresat adresat);
    int pobierzIdOstatniegoAdresata();
    void usunWybranegoAdresataZPliku(int idAdresata);
    void edytujAdresataWPliku(Adresat adresat);
};

#endif // PLIKZADRESATAMI_H
