#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt","Adresaci.txt");
    char wybor;

    while (true) {
        if (ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() == 0) {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch (wybor) {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.ustawIdZalogowanegoUzytkownika (ksiazkaAdresowa.logowanieUzytkownika());
                break;
            case '3':
                ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
                system ("pause");
                break;
            case '9':
                exit (0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system ("pause");
                break;
            }
        } else {
            cout << ksiazkaAdresowa.pobierzRozmiarAdresaci() << " rozmiar adresatow" << endl;
            cout << ksiazkaAdresowa.pobierzIdOstatniegoAdresata() << " id ostatniego adresata" << endl;
            system("pause");
            if (ksiazkaAdresowa.pobierzRozmiarAdresaci() == 0){
                ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
            }

            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch (wybor) {
            case '1':
                ksiazkaAdresowa.ustawIdOstatniegoAdresata (ksiazkaAdresowa.dodajAdresata() );
                break;
            case '2':
                //wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
                //wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                //idUsunietegoAdresata = usunAdresata(adresaci);
                //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                //edytujAdresata(adresaci);
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.ustawIdZalogowanegoUzytkownika (0);
                cout << "Wylogowano cie" << endl;
                system ("pause");
                //adresaci.clear();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system ("pause");
                break;
            }
        }
    }
    return 0;
}

