#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include <iostream>
#include <sstream>


#include "Uzytkownik.h"

using namespace std;

class MetodyPomocnicze{
private:
public:
    static string konwerjsaIntNaString(int liczba);
    string wczytajLinie(string wejscie);
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    char wczytajZnak();

};

#endif // METODYPOMOCNICZE_H
