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
    {{4,8}, Op_Dziel, {1,0}}, 
  };

/*
 * Tablica zawierajaca tresc trudnego testu.
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
 *      - Parametr sNazwaTestu musi wskazywac na jedna z nazw tzn. "latwy", "trudny" lub "wlasny".
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
    Translacja_pliku_na_bazatestu(nazwa_zestawu);
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

/*
* Metoda wczytujaca pytania z pliku. Pytania i dane o tescie umieszczone sa w obiekcie typu BazaTestu.
* Argumenty:
*   nazwa_pliku - nazwa pliku- bazy pytan.
* Zwraca:
*   BazaTestu uzupelniona o dane wczytanego z pliku testu.
*/

BazaTestu  BazaTestu::Translacja_pliku_na_bazatestu(string nazwa_pliku){
    ifstream PlikWe;
    BazaTestu TestzPliku;
    WyrazenieZesp * TestWlasny = NULL,* Temp = NULL, pobrane_wyr;
    unsigned int dlugosc=0;
    PlikWe.open(nazwa_pliku); /* Otwarcie pliku o wskazanej w argumencie wywolania nazwie */
    /* Jesli otwracie pliku o wskazanej nazwie nie uda sie, zglos blad */
    if(!PlikWe.is_open()){
      throw runtime_error("Inicjalizacja testu nie powiodla sie! Plik uszkodzony, badz nie istenieje\n");
    }
    cout << "WCZYTANO PLIK "<<endl;
    while(1) /* Petla realizujaca wczytywanie kolejnych linii z pliku */
    {
      char znak;
      PlikWe >> znak;
      if (znak=='.' || PlikWe.eof()) /* Jesli program napotka na "." lub koniec pliku konczy wczytywanie z pliku */
          break;
      PlikWe.putback(znak); /* Cofniecie sie o sprawdzany znak w strumieniu aby wczytac wyrazenie zespolone */
      PlikWe >> pobrane_wyr; /* Wczytanie wyrazenia zespolonego */
      if(PlikWe.fail()){  /* Warunek pomijajacy blednie zapisane wyrazenia zespolone */
          PlikWe.clear(); 
          PlikWe.ignore(10000,'\n'); 
          continue;
      }
      /* Przypisywanie wczytanych pytan do tablic alokowanych dynamicznie */
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
  PlikWe.close(); /* Zakonczenie czytania pliku */
  this->wskTabTestu=TestWlasny; /* Uzupelnienie BazyTestu o zebrane pytania i informacje o tescie */
  this->IloscPytan=dlugosc;
  this->IndeksPytania=0;
  return TestzPliku;
} 