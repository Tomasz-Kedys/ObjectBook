#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(){
    uzytkownikManager.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikManager.rejestracjaUzytkownika();
}
