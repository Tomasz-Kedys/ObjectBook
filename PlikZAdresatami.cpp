#include "PlikZAdresatami.h"

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku (int idZalogowanegoUzytkownika) {
    vector <Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;

    plikTekstowy.open (nazwaPlikuZAdresatami.c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline (plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami) ) {
            if (idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami (daneJednegoAdresataOddzielonePionowymiKreskami) ) {
                adresat = pobierzDaneAdresata (daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back (adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    } else {
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;
    }
    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami (daneOstaniegoAdresataWPliku);
    }

    return adresaci;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami (string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of ('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt (MetodyPomocnicze::pobierzLiczbe (daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika) );

    return idUzytkownika;
}

void PlikZAdresatami::dopiszAdresataDoPliku (Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open (nazwaPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami (adresat);
        cout << liniaZDanymiAdresata << " zapisywanie do pliku" << endl;
        system ("pause");

        if (MetodyPomocnicze::czyPlikJestPusty() == true) {
            plikTekstowy << liniaZDanymiAdresata;
        } else {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
    } else {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    plikTekstowy.close();
    system ("pause");
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami (Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString (adresat.pobierzId() ) + '|';
    cout << adresat.pobierzIdUzytkownika() << " id uzytkownika w klasie adresat" << endl;
    system("pause");
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString (adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    cout << liniaZDanymiAdresata << " pobieranie danych z obiektu adresat" << endl;
    system("pause");

    return liniaZDanymiAdresata;
}

void PlikZAdresatami::ustawIdOstatniegoAdresata (int noweIdOstatniegoAdresata) {
    if (noweIdOstatniegoAdresata>0)
        idOstatniegoAdresata = noweIdOstatniegoAdresata;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata() {
    return idOstatniegoAdresata;
}

Adresat PlikZAdresatami::pobierzDaneAdresata (string daneAdresataOddzielonePionowymiKreskami) {
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < (int) daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch (numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawId (atoi (pojedynczaDanaAdresata.c_str() ) );
                break;
            case 2:
                adresat.ustawIdUzytkownika (atoi (pojedynczaDanaAdresata.c_str() ) );
                break;
            case 3:
                adresat.ustawImie (pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko (pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu (pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail (pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres (pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami (string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt (MetodyPomocnicze::pobierzLiczbe (daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata) );
    return idAdresata;
}
