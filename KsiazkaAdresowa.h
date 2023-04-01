#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "UzytkownikManager.h"
#include "MetodyPomocnicze.h"

using namespace std;

class KsiazkaAdresowa{
    private:
        UzytkownikManager uzytkownikManager;
        MetodyPomocnicze metodyPomocnicze;
    public:
        KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikManager(nazwaPlikuZUzytkownikami){
            uzytkownikManager.wczytajUzytkownikowZPliku();
        };
        void rejestracjaUzytkownika();
        void wypiszWszystkichUzytkownikow();
        int logowanieUzytkownika();
        void ustawIdZalogowanegoUzytkownika(int noweId);
        int pobierzIdZalogowanegoUzytkownika();
        char wybierzOpcjeZMenuGlownego();
        char wybierzOpcjeZMenuUzytkownika();
        void zmianaHaslaZalogowanegoUzytkownika();
};

#endif // KSIAZKAADRESOWA_H
