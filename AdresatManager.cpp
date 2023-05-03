#include "AdresatManager.h"
void AdresatManager::wczytajAdresatowZalogowanegoUzytkownikaZPliku () {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku (idZalogowanegoUzytkownika);
}

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
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatManager::ustawAdrecaci (Adresat adresat) {
    adresaci.push_back (adresat);
}

int AdresatManager::dodajAdresata() {

    Adresat adresat;
    int idOstatniegoAdresata = plikZAdresatami.pobierzIdOstatniegoAdresata();
    system ("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata (AdresatManager::pobierzIdZalogowanegoUzytkownika() );

    ustawAdrecaci (adresat);
    plikZAdresatami.dopiszAdresataDoPliku (adresat);

    return ++idOstatniegoAdresata;
}

Adresat AdresatManager::podajDaneNowegoAdresata (int idZalogowanegoUzytkownika) {
    Adresat adresat;
    adresat.ustawId (plikZAdresatami.pobierzIdOstatniegoAdresata()+1);
    adresat.ustawIdUzytkownika (idZalogowanegoUzytkownika);

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

void AdresatManager::ustawIdZalogowanegoUzytkownika (int noweIdZalogowanegoUzytkownika) {
    if (noweIdZalogowanegoUzytkownika > 0)
        idZalogowanegoUzytkownika = noweIdZalogowanegoUzytkownika;
}

int AdresatManager::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}

void AdresatManager::ustawIdOstatniegoAdresata (int noweIdOstatniegoAdresata) {
    plikZAdresatami.ustawIdOstatniegoAdresata (noweIdOstatniegoAdresata);
}
int AdresatManager::pobierzIdOstatniegoAdresata(){
    return plikZAdresatami.pobierzIdOstatniegoAdresata();
}
