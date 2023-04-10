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
#include "UzytkownikManager.h"

using namespace std;

class AdresatManager {
private:
    PlikZAdresatami plikZAdresatami;
    MetodyPomocnicze metodyPomocnicze;
    UzytkownikManager uzytkownikManager;
    vector <Adresat> adresaci;
    int idOstatniegoAdresata;
    Adresat podajDaneNowegoAdresata();
public:
    AdresatManager();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    int pobierzRozmiarAdresaci();
    void ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata);
    int pobierzDaneAdresataIdOstatniegoAdresata();
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata(Adresat adresat);
    void ustawAdrecaci(Adresat adresat);
    int dodajAdresata();
};

#endif // ADRESATMANAGER_H
