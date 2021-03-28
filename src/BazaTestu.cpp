#include <iostream>
#include <cstring>
#include <cassert>
#include "BazaTestu.hh"

using namespace std;

/*
 * Tablica, ktora jest widoczna tylko w tym module.
 * Zawiera ona tresc latwego testu.
 */
static WyrazenieZesp  TestLatwy[] =
  { {{2,1}, Op_Dodaj, {1,2}},
    {{1,0}, Op_Odejmij, {0,1}},
    {{3,0}, Op_Mnoz, {0,3}},
    {{4,8}, Op_Dziel, {3,8}}, //1;0
  };

/*
 * Tablica zawierajaca tesc trudnego testu
 */
static WyrazenieZesp  TestTrudny[] =
  { {{7.5,5}, Op_Dodaj, {6,15.75}},
    {{3,8}, Op_Odejmij, {5,8}},
    {{9,0}, Op_Mnoz, {0,0.5}},
    {{15,9}, Op_Dziel, {10,13}},
  };

/*
 * W bazie testu ustawia wybrany test jako biezacy test i indeks pytania
 * ustawia na pierwsze z nich.
 * Parametry:
 *    wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu,
 *    wskTabTestu  - wskaznik na tablice zawierajaca wyrazenia arytmetyczne
 *                   bedace przedmiotem testu,
 *    IloscElemTab - ilosc pytan w tablicy.
 *   
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr wskTabTestu zawiera wskaznik na istniejaca tablice.
 *      - Parametr IloscPytan zawiera wartosc, ktora nie przekracza ilosci elementow
 *        w tablicy dostepnej poprzez wskTabTestu.
 */

void BazaTestu::UstawTest(WyrazenieZesp *wskTabTestu, unsigned int IloscPytan)
{
  this->wskTabTestu = wskTabTestu;
  this->IloscPytan = IloscPytan;
  this->IndeksPytania = 0;
}

/*
 * Inicjalizuje test kojarzac zmienna dostepna poprzez wskaznik wskBazaTestu
 * z dana tablica wyrazen, ktora reprezentuje jeden z dwoch dopuszczalnych 
 * testow.
 * Parametry:
 *    wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *    sNazwaTestu  - wskaznik na napis wybranego typu testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr sNazwaTestu musi wskazywac na jedna z nazw tzn. "latwe" lub "trudne".
 *       
 * Zwraca:
 *       true - gdy operacja sie powiedzie i test zostanie poprawnie
 *              zainicjalizowany,
 *       false - w przypadku przeciwnym.
 */

bool BazaTestu::InicjalizujTest(const char * sNazwaTestu)
{
  if (!strcmp(sNazwaTestu,"latwy")) {
    UstawTest(TestLatwy,sizeof(TestLatwy)/sizeof(WyrazenieZesp));
    return true;
  }

  if (!strcmp(sNazwaTestu,"trudny")) {
    UstawTest(TestTrudny,sizeof(TestTrudny)/sizeof(WyrazenieZesp));
    return true;
  }

  if (!strcmp(sNazwaTestu,"wlasny")) {
    Translacja_pliku_na_tab(nazwa_zestawu);
    UstawTest(wskTabTestu,IloscPytan);
    return true;
  }

  cerr << "Otwarcie testu '" << sNazwaTestu << "' nie powiodlo sie." << endl;
  return false;
}

/*!
 * Funkcja udostepnia nastepne pytania o ile jest odpowiednia ich ilosc.
 * Parametry:
 *       wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *       wskWyrazenie - wskaznik na zmienna, do ktorej zostanie wpisane
 *                      kolejne wyrazenie z bazy testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr wskWyrazenie nie moze byc pustym wskaznikiem. Musi wskazywac na
 *        istniejaca zmienna.
 *
 * Zwraca:
 *       true - gdy operacja sie powiedzie i parametrowi *wskWyrazenie zostanie
 *              przypisane nowe wyrazenie zespolone z bazy,
 *       false - w przypadku przeciwnym.
 */


bool BazaTestu::PobierzNastpnePytanie(WyrazenieZesp *wskWyr)
{
  if (this->IndeksPytania >= this->IloscPytan) return false;
  *wskWyr = this->wskTabTestu[this->IndeksPytania];
  ++this->IndeksPytania;
  return true;
}


BazaTestu  BazaTestu::Translacja_pliku_na_tab(string nazwa_pliku)
{
    ifstream PlikWe;
    BazaTestu TestzPliku;
    WyrazenieZesp * TestWlasny = NULL,* Temp = NULL;
    unsigned int dlugosc=0;
    PlikWe.open(nazwa_pliku);
    if(!PlikWe.is_open()){
      throw runtime_error("Inicjalizacja testu nie powiodla sie! Plik uszkodzony, badz nie istenieje\n");
    }
    cout << "WCZYTANO PLIK "<<endl;
    WyrazenieZesp pobrane_wyr;
    while(1)
    {
        char znak;
        PlikWe >> znak;
        if (znak=='.' || PlikWe.eof())
            break;
        PlikWe.putback(znak);
        PlikWe >> pobrane_wyr; 
        if(PlikWe.fail()){ 
            PlikWe.clear(); 
            PlikWe.ignore(10000,'\n'); 
            continue;
        }
        if (dlugosc == 0 ){
            TestWlasny = new WyrazenieZesp[1];
            TestWlasny[dlugosc] = pobrane_wyr;
            dlugosc++;
        }
        else{
            Temp = new WyrazenieZesp[dlugosc];
            for(unsigned int i=0; i<dlugosc;i++){
                Temp[i] = TestWlasny[i];
            }
            delete [] TestWlasny;
            TestWlasny = new WyrazenieZesp[dlugosc+1];
            for(unsigned int i=0; i<dlugosc;i++){
                TestWlasny[i] = Temp[i];
            }
            delete [] Temp;
            TestWlasny[dlugosc] = pobrane_wyr;
            dlugosc++;
        }
    }
  PlikWe.close();
  
  this->wskTabTestu=TestWlasny;
  this->IloscPytan=dlugosc;
  this->IndeksPytania=0;
  return TestzPliku;
}