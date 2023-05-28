#ifndef PLIKZUZYTKOWNIKAMI_K
#define PLIKZUZYTKOWNIKAMI_H
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

class PlikZUzytkownikami {
private:
    const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami (Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika (string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZUzytkownikami (string nazwaPlikuZUzytkownikami) :  NAZWA_PLIKU_Z_UZYTKOWNIKAMI (nazwaPlikuZUzytkownikami) {};
    void dopiszUzytkownikaDoPliku (Uzytkownik uzytkownik);
    void zapiszWszystkichUzytkownikowDoPliku (vector <Uzytkownik> &uzytkownicy);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();

};

#endif // PLIKZUZYTKOWNIKAMI_K
