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
    void pobierzZPlikuIdOstatniegoAdresata();

public:
    PlikZAdresatami (string nazwaPlikuZAdresatami) : PlikTekstowy (nazwaPlikuZAdresatami) {
        idOstatniegoAdresata = 0;
    };
    void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami (Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku (int idZalogowanegoUzytkownika);
    void ustawIdOstatniegoAdresata (int noweIdOstatniegoAdresata);
    bool dopiszAdresataDoPliku (Adresat adresat);
    int pobierzIdOstatniegoAdresata();
    void zaktualizujDaneWybranegoAdresata (Adresat adresat, int idEdytowanegoAdresata);
    int zwrocNumerLiniiSzukanegoAdresata(int idAdresata);
    void usunWybranaLinieWPliku(int numerUsuwanejLinii);
    void podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata);
};

#endif // PLIKZADRESATAMI_H
