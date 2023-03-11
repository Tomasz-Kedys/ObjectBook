#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "UzytkownikManager.h"

using namespace std;

class KsiazkaAdresowa{
    private:
        UzytkownikManager uzytkownikManager;
    public:
        void rejestracjaUzytkownika();
        void wypiszWszystkichUzytkownikow();
};

#endif // KSIAZKAADRESOWA_H
