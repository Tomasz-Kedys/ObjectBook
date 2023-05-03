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
    PlikZAdresatami plikZAdresatami;
    vector <Adresat> adresaci;
    int idZalogowanegoUzytkownika;
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    void ustawAdrecaci(Adresat adresat);
    void wyswietlDaneAdresata(Adresat adresat);
    int pobierzIdZalogowanegoUzytkownika();

public:
    AdresatManager(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){
        idZalogowanegoUzytkownika = 0;
    };
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    int pobierzRozmiarAdresaci();
    void wyswietlWszystkichAdresatow();
    int dodajAdresata();
    void ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    void ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata);
};
#endif // ADRESATMANAGER_H
