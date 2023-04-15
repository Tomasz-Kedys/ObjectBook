#ifndef ADRESATMANAGER_H
#define ADRESATMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatManager {
private:
    Adresat adresat;
    PlikZAdresatami plikZAdresatami;
    vector <Adresat> adresaci;
    int idZalogowanegoUzytkownika;
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
public:
    AdresatManager(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){
        idZalogowanegoUzytkownika = 0;
    };
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int przekazaneIdZalogowanegoUzytkownika);
    int pobierzRozmiarAdresaci();
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata(Adresat adresat);
    void ustawAdrecaci(Adresat adresat);
    int dodajAdresata();
    void ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika);
    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata);
};
#endif // ADRESATMANAGER_H
