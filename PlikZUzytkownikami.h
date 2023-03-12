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
    string nazwaPlikuZUzytkownikami;
    fstream plikTekstowy;
    bool czyPlikJestPusty ();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami (Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZUzytkownikami();
    void dopiszUzytkownikaDoPliku (Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();

};

#endif // PLIKZUZYTKOWNIKAMI_K
