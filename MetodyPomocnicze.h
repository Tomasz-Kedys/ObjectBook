#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

class MetodyPomocnicze {
private:
    static char wczytajZnak();
public:
    static string konwerjsaIntNaString (int liczba);
    static int konwersjaStringNaInt(string liczba);
    static string wczytajLinie ();
    static char wybierzOpcjeZMenuGlownego();
    static char wybierzOpcjeZMenuUzytkownika();
    static char wybierzOpcjeZMenuEdycja();
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static int wczytajLiczbeCalkowita();
};

#endif // METODYPOMOCNICZE_H
