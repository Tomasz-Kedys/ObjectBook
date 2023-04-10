#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>


#include "Uzytkownik.h"

using namespace std;

class MetodyPomocnicze {
private:
public:
    bool czyPlikJestPusty ();
    static string konwerjsaIntNaString (int liczba);
    static int konwersjaStringNaInt(string liczba);
    string wczytajLinie ();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    char wczytajZnak();
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);

};

#endif // METODYPOMOCNICZE_H
