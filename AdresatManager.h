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
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    Adresat podajDaneNowegoAdresata();
    void ustawAdrecaci(Adresat adresat);
    void wyswietlDaneAdresata(Adresat adresat);
    int pobierzIdZalogowanegoUzytkownika();
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata);

public:
    AdresatManager(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku (ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    int pobierzRozmiarAdresaci();
    void wyswietlWszystkichAdresatow();
    void dodajAdresata();
    int pobierzIdOstatniegoAdresata();
    void ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata);
    void wyczyscVektorAdresatow();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void edytujAdresata();
    void usunAdresata();
    int podajIdWybranegoAdresata();
};
#endif // ADRESATMANAGER_H
