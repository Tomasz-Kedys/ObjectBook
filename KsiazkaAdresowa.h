#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"

using namespace std;

class KsiazkaAdresowa{
    private:
        int idZalogowanegoUzytkownika;
        int idOstatniegoAdresata;
        int idUsunietegoAdresata;

        vector <Uzytkownik> uzytkownicy;
        Uzytkownik podajDaneNowegoUzytkownika();
        int pobierzIdNowegoUzytkownika();
        bool czyIstniejeLogin(string login);
        void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
        string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
        string konwerjsaIntNaString(int liczba);
        bool czyPlikJestPusty(fstream &plikTekstowy);

        string nazwaPlikuZUzytkownikami;

    public:
        KsiazkaAdresowa();
        void rejestracjaUzytkownika();
        void wypiszWszystkichUzytkownikow();


};
