#ifndef PLIKZUZYTKOWNIKAMI_K
#define PLIKZUZYTKOWNIKAMI_H
#include <iostream>
#include <vector>
#include <fstream>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

class PlikZUzytkownikami {
private:
    string nazwaPlikuZUzytkownikami;
    fstream plikTekstowy;
    bool czyPlikJestPusty ();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami (Uzytkownik uzytkownik);

public:
    PlikZUzytkownikami();
    void dopiszUzytkownikaDoPliku (Uzytkownik uzytkownik);

};

#endif // PLIKZUZYTKOWNIKAMI_K
