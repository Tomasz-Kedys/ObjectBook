#ifndef PLIKZUZYTKOWNIKAMI_K
#define PLIKZUZYTKOWNIKAMI_H
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

class PlikZUzytkownikami : public PlikTekstowy {
private:
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami (Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika (string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZUzytkownikami (string nazwaPlikuZUzytkownikami) :  PlikTekstowy (nazwaPlikuZUzytkownikami) {};
    void dopiszUzytkownikaDoPliku (Uzytkownik uzytkownik);
    void zapiszWszystkichUzytkownikowDoPliku (vector <Uzytkownik> &uzytkownicy);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();

};

#endif // PLIKZUZYTKOWNIKAMI_K
