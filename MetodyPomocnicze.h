#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

class MetodyPomocnicze {
public:
    static bool czyPlikJestPusty ();
    static string konwerjsaIntNaString (int liczba);
    static int konwersjaStringNaInt(string liczba);
    static string wczytajLinie ();
    static char wybierzOpcjeZMenuGlownego();
    static char wybierzOpcjeZMenuUzytkownika();
    static char wczytajZnak();
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
};

#endif // METODYPOMOCNICZE_H
