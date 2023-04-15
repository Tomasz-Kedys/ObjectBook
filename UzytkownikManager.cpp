#include "UzytkownikManager.h"

void UzytkownikManager::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back (uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku (uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system ("pause");
}

Uzytkownik UzytkownikManager::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;

    uzytkownik.ustawId (pobierzIdNowegoUzytkownika() );

    string login, haslo;
    do {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin (login);
    } while (czyIstniejeLogin (uzytkownik.pobierzLogin() ) == true);

    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo (haslo);

    return uzytkownik;
}

int UzytkownikManager::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikManager::czyIstniejeLogin (string login) {
    for (int i = 0; i < (int) uzytkownicy.size(); i++) {
        if (uzytkownicy[i].pobierzLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikManager::wypiszWszystkichUzytkownikow() {
    for (int i = 0; i < (int) uzytkownicy.size(); i++) {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}
void UzytkownikManager::wczytajUzytkownikowZPliku() {
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

void UzytkownikManager::zapiszWszystkichUzytkownikowDoPliku (vector <Uzytkownik> &uzytkownicy) {
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku (uzytkownicy);
}

int UzytkownikManager::logowanieUzytkownika() {
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie ();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end() ) {
        if (itr -> Uzytkownik::pobierzLogin() == login) {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie ();

                if (itr -> Uzytkownik::pobierzHaslo() == haslo) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system ("pause");
                    return itr -> Uzytkownik::pobierzId();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system ("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system ("pause");
    return 0;
}

void UzytkownikManager::zmianaHaslaZalogowanegoUzytkownika() {

    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie ();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {
        if (itr -> Uzytkownik::pobierzId() == UzytkownikManager::pobierzIdZalogowanegoUzytkownika() ) {
            itr -> Uzytkownik::ustawHaslo (noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system ("pause");
        }
    }
    UzytkownikManager::zapiszWszystkichUzytkownikowDoPliku (uzytkownicy);
}

void UzytkownikManager::ustawIdZalogowanegoUzytkownika (int noweId) {
    if (noweId >= 0)
        idZalogowanegoUzytkownika = noweId;
}

int UzytkownikManager::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}

int UzytkownikManager::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami){
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}
