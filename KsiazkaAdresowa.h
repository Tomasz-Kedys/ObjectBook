#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "UzytkownikManager.h"
#include "MetodyPomocnicze.h"
#include "AdresatManager.h"

using namespace std;

class KsiazkaAdresowa {
private:
    UzytkownikManager uzytkownikManager;
    AdresatManager adresatManager;
public:
    KsiazkaAdresowa (string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikManager (nazwaPlikuZUzytkownikami), adresatManager(nazwaPlikuZAdresatami){
        uzytkownikManager.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    void ustawIdZalogowanegoUzytkownika (int noweId);
    int pobierzIdZalogowanegoUzytkownika();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void ustawNazwePlikuZAdresatami (string nazwaPlikuZAdresatami);
    int pobierzRozmiarAdresaci();
    void ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata);
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int przekazaneIdZalogowanegoUzytkownika);
    int dodajAdresata();
    void wyswietlWszystkichAdresatow();
};

#endif // KSIAZKAADRESOWA_H
