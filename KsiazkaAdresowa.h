#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "UzytkownikManager.h"
#include "AdresatManager.h"

using namespace std;

class KsiazkaAdresowa {
private:
    UzytkownikManager uzytkownikManager;
    AdresatManager *adresatManager;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa (string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
        : uzytkownikManager (nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami){
        adresatManager = NULL;
    };
    ~KsiazkaAdresowa(){
        delete adresatManager;
        adresatManager = NULL;
    };
    void rejestracjaUzytkownika();
    void wylogowanieUzytkowniaka();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    bool czyJestZalogowanyKtos();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void edytujAdresata();
    void usunAdresata();
};
#endif // KSIAZKAADRESOWA_H
