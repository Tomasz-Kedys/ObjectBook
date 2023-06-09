#ifndef UZYTKOWNIKMANAGER_H
#define UZYTKOWNIKMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class UzytkownikManager {
private:
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;

    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin (string login);
    Uzytkownik podajDaneNowegoUzytkownika();
    void zapiszWszystkichUzytkownikowDoPliku (vector <Uzytkownik> &uzytkownicy);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

public:
    UzytkownikManager (string nazwaPlikuZUzytkownikami) : plikZUzytkownikami (nazwaPlikuZUzytkownikami) {
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
        idZalogowanegoUzytkownika = 0;
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    bool czyJestZalogowanyKtos();
    void ustawIdZalogowanegoUzytkownika (int noweId);
    int pobierzIdZalogowanegoUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
};

#endif // UZYTKOWNIKMANAGER_H
