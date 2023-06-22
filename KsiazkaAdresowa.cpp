#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikManager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikManager.logowanieUzytkownika();
    if (uzytkownikManager.czyJestZalogowanyKtos() ) {
        adresatManager = new AdresatManager (NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikManager.pobierzIdZalogowanegoUzytkownika() );
    }
}

bool KsiazkaAdresowa::czyJestZalogowanyKtos() {
    if (uzytkownikManager.czyJestZalogowanyKtos() ) {
        return true;
    } else
        return false;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    return MetodyPomocnicze::wybierzOpcjeZMenuGlownego();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    return MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkowniaka() {
    adresatManager->wyczyscVektorAdresatow();
    delete adresatManager;
    adresatManager = NULL;
    uzytkownikManager.ustawIdZalogowanegoUzytkownika (0);
}

void KsiazkaAdresowa::dodajAdresata() {
    if (uzytkownikManager.czyJestZalogowanyKtos() )
        adresatManager->dodajAdresata();
    else {
        cout << "Najpierw trzeba sie zalogowac " << endl;
        system ("pause");
    }
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    adresatManager->wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu() {
    adresatManager->wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku() {
    adresatManager->wyszukajAdresatowPoNazwisku();
}

void KsiazkaAdresowa::edytujAdresata(){
    adresatManager->edytujAdresata();
}
