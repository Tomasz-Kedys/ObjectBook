#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikManager.rejestracjaUzytkownika();
}

int KsiazkaAdresowa::logowanieUzytkownika(){
    return uzytkownikManager.logowanieUzytkownika();
}

void KsiazkaAdresowa::ustawIdZalogowanegoUzytkownika(int noweId){
    if(noweId >= 0)
     uzytkownikManager.ustawIdZalogowanegoUzytkownika(noweId);
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika(){
    return uzytkownikManager.pobierzIdZalogowanegoUzytkownika();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego(){
    return metodyPomocnicze.wybierzOpcjeZMenuGlownego();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika(){
    return metodyPomocnicze.wybierzOpcjeZMenuUzytkownika();
}
