#include "AdresatManager.h"

void AdresatManager::wyswietlWszystkichAdresatow() {
    system ("cls");
    if (!adresaci.empty() ) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            wyswietlDaneAdresata (*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system ("pause");
}

int AdresatManager::pobierzRozmiarAdresaci() {
    return AdresatManager::adresaci.size();
}

void AdresatManager::wyswietlDaneAdresata (Adresat adresat) {
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    //cout << "Id Uzytkoenika:     " << adresat.pobierzIdUzytkownika() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatManager::dodajAdresata() {

    Adresat adresat;
    int idOstatniegoAdresata = plikZAdresatami.pobierzIdOstatniegoAdresata();
    system ("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata ();

    adresaci.push_back (adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku (adresat) ) {
        cout << "Sukcess!!!" << endl;
    } else {
        cout << "Dodanie adresata do pliku sie nie powiodlo!!!!" << endl;
    }
    plikZAdresatami.ustawIdOstatniegoAdresata (++idOstatniegoAdresata);
}

Adresat AdresatManager::podajDaneNowegoAdresata () {
    Adresat adresat;
    adresat.ustawId (plikZAdresatami.pobierzIdOstatniegoAdresata()+1);
    adresat.ustawIdUzytkownika (ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie (MetodyPomocnicze::wczytajLinie() );
    adresat.ustawImie (MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale (adresat.pobierzImie() ) );

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko (MetodyPomocnicze::wczytajLinie() );
    adresat.ustawNazwisko (MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale (adresat.pobierzNazwisko() ) );

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu (MetodyPomocnicze::wczytajLinie() );

    cout << "Podaj email: ";
    adresat.ustawEmail (MetodyPomocnicze::wczytajLinie() );

    cout << "Podaj adres: ";
    adresat.ustawAdres (MetodyPomocnicze::wczytajLinie() );

    return adresat;
}

int AdresatManager::pobierzIdZalogowanegoUzytkownika() {
    return ID_ZALOGOWANEGO_UZYTKOWNIKA;
}

void AdresatManager::ustawIdOstatniegoAdresata (int noweIdOstatniegoAdresata) {
    plikZAdresatami.ustawIdOstatniegoAdresata (noweIdOstatniegoAdresata);
}

int AdresatManager::pobierzIdOstatniegoAdresata() {
    return plikZAdresatami.pobierzIdOstatniegoAdresata();
}

void AdresatManager::wyczyscVektorAdresatow() {
    adresaci.clear();
}

void AdresatManager::wyszukajAdresatowPoImieniu() {
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system ("cls");
    if (!adresaci.empty() ) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale (MetodyPomocnicze::wczytajLinie() );

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> Adresat::pobierzImie() == imiePoszukiwanegoAdresata) {
                wyswietlDaneAdresata (*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow (iloscAdresatow);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system ("pause");
}

void AdresatManager::wyszukajAdresatowPoNazwisku() {
    string nazwiskoPoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system ("cls");
    if (!adresaci.empty() ) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale (MetodyPomocnicze::wczytajLinie() );

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> Adresat::pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata) {
                wyswietlDaneAdresata (*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow (iloscAdresatow);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system ("pause");
}

void AdresatManager::wyswietlIloscWyszukanychAdresatow (int iloscAdresatow) {
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void AdresatManager::edytujAdresata() {
    system ("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = MetodyPomocnicze::wczytajLiczbeCalkowita();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < (int) adresaci.size(); i++) {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata) {
            czyIstniejeAdresat = true;
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuEdycja();

            switch (wybor) {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie (MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale (MetodyPomocnicze::wczytajLinie() ) );
                zaktualizujDaneWybranegoAdresata (adresaci[i]);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko (MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale (MetodyPomocnicze::wczytajLinie() ) );
                zaktualizujDaneWybranegoAdresata (adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu (MetodyPomocnicze::wczytajLinie() );
                zaktualizujDaneWybranegoAdresata (adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail (MetodyPomocnicze::wczytajLinie() );
                zaktualizujDaneWybranegoAdresata (adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres (MetodyPomocnicze::wczytajLinie() );
                zaktualizujDaneWybranegoAdresata (adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system ("pause");
}

void AdresatManager::zaktualizujDaneWybranegoAdresata (Adresat adresat) {

    plikZAdresatami.edytujAdresataWPliku (adresat);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

void AdresatManager::usunAdresata() {
    int idUsuwanegoAdresata = 0;

    system ("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
        if (itr -> Adresat::pobierzId() == idUsuwanegoAdresata) {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't' || znak == 'T') {
                plikZAdresatami.usunWybranegoAdresataZPliku (idUsuwanegoAdresata);
                adresaci.erase (itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                plikZAdresatami.podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata (idUsuwanegoAdresata,plikZAdresatami.pobierzIdOstatniegoAdresata());
                system ("pause");
            } else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system ("pause");
            }
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system ("pause");
    }
}

int AdresatManager::podajIdWybranegoAdresata() {
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}
