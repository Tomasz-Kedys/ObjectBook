#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikManager.rejestracjaUzytkownika();
}

int KsiazkaAdresowa::logowanieUzytkownika() {
    return uzytkownikManager.logowanieUzytkownika();
}

void KsiazkaAdresowa::ustawIdZalogowanegoUzytkownika (int noweId) {
    if (noweId >= 0)
        uzytkownikManager.ustawIdZalogowanegoUzytkownika (noweId);
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika() {
    return uzytkownikManager.pobierzIdZalogowanegoUzytkownika();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    return metodyPomocnicze.wybierzOpcjeZMenuGlownego();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    return metodyPomocnicze.wybierzOpcjeZMenuUzytkownika();
}

int KsiazkaAdresowa::pobierzRozmiarAdresaci(){
    return adresatManager.pobierzRozmiarAdresaci();
}

void KsiazkaAdresowa::ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata){
    adresatManager.ustawIdOstatniegoAdresata(noweIdOstatniegoAdresata);
}

int KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPliku(){
    return adresatManager.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}

int KsiazkaAdresowa::dodajAdresata(){
    return adresatManager.dodajAdresata();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){
    adresatManager.wyswietlWszystkichAdresatow();
}
