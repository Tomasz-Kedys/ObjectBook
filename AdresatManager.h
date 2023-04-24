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
public:
    AdresatManager(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){
        idZalogowanegoUzytkownika = 0;
    };
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    int pobierzRozmiarAdresaci();
    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata(Adresat adresat);
    void ustawAdrecaci(Adresat adresat);
    int dodajAdresata();
    void ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika);
    int pobierzIdZalogowanegoUzytkownika();
    int pobierzIdOstatniegoAdresata();
    void ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata);
};
#endif // ADRESATMANAGER_H
