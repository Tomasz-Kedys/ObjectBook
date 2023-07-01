#include "PlikZAdresatami.h"

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku (int idZalogowanegoUzytkownika) {
    Adresat adresat;
    vector <Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;

    plikTekstowy.open (pobierzNazwePliku().c_str(), ios::in);

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

bool PlikZAdresatami::dopiszAdresataDoPliku (Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open (pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami (adresat);
        if (czyPlikJestPusty () == true) {
            plikTekstowy << liniaZDanymiAdresata;
        } else {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
        plikTekstowy.close();
        return true;
    } else {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    return false;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami (Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString (adresat.pobierzId() ) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString (adresat.pobierzIdUzytkownika() ) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

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
    Adresat adresat;
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

void PlikZAdresatami::usunWybranegoAdresataZPliku (int idAdresata) {

    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";

    odczytywanyPlikTekstowy.open (pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open (nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if ( (odczytywanyPlikTekstowy.good() == true) && (idAdresata != 0) ) {
        while (getline (odczytywanyPlikTekstowy, wczytanaLinia) ) {
            if (idAdresata != pobierzIdAdresataZDanychOddzielonychPionowymiKreskami (wczytanaLinia) ) {
                if((pobierzIdOstatniegoAdresata()-1) != pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia)){
                    tymczasowyPlikTekstowy << wczytanaLinia << endl;
                }else{
                    tymczasowyPlikTekstowy << wczytanaLinia;
                }
            }
        }
    }
    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();

    usunPlik(pobierzNazwePliku().c_str());
    zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami.c_str(), pobierzNazwePliku().c_str());
}

void PlikZAdresatami::usunPlik (string nazwaPlikuZRozszerzeniem) {
    if (remove (nazwaPlikuZRozszerzeniem.c_str() ) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zmienNazwePliku (string staraNazwa, string nowaNazwa) {
    if (rename (staraNazwa.c_str(), nowaNazwa.c_str() ) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

void PlikZAdresatami::podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata (int idUsuwanegoAdresata, int idOstatniegoAdresata) {
    if (idUsuwanegoAdresata == pobierzIdOstatniegoAdresata() )
        pobierzZPlikuIdOstatniegoAdresata();
}

void PlikZAdresatami::pobierzZPlikuIdOstatniegoAdresata() {
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open (pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline (plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami) ) {}
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "") {
        ustawIdOstatniegoAdresata (pobierzIdAdresataZDanychOddzielonychPionowymiKreskami (daneOstaniegoAdresataWPliku) );
    }
}

void PlikZAdresatami::edytujAdresataWPliku (Adresat adresat) {

    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string liniaZDanymiAdresataOddzielonePionowymiKreskami = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami (adresat);
    int numerWczytanejLinii = 1;

    odczytywanyPlikTekstowy.open (pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open (nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if ( (odczytywanyPlikTekstowy.good() == true) ) {
        while (getline (odczytywanyPlikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami) ) {
            if (adresat.pobierzId() == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami (daneJednegoAdresataOddzielonePionowymiKreskami) ) {
                if (numerWczytanejLinii == 1) {
                    tymczasowyPlikTekstowy << liniaZDanymiAdresataOddzielonePionowymiKreskami;
                } else if (numerWczytanejLinii > 1) {
                    tymczasowyPlikTekstowy << endl << liniaZDanymiAdresataOddzielonePionowymiKreskami;
                }
            } else {
                if (numerWczytanejLinii == 1) {
                    tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
                    numerWczytanejLinii++;
                } else if (numerWczytanejLinii > 1) {
                    tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;
                    numerWczytanejLinii++;
                }
            }
        }
    }
    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();

    usunPlik (pobierzNazwePliku() );
    zmienNazwePliku (nazwaTymczasowegoPlikuZAdresatami, pobierzNazwePliku() );
}
