#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"

using namespace std;

int main(int argc, char **argv)
{
  if (argc < 2) { /* Pobranie argumentu wywolania programu, w celu okreslenia poziomu trudnosci testu */
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  BazaTestu   BazaT = { nullptr, 0, 0 }; 

  if (InicjalizujTest(&BazaT,argv[1]) == false) { /* Inicjalizacja testu ze wzgledu na wybrany napis "latwy", "trudny" wraz z warunkiem, gdy napis nie zostanie podany*/
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  cout << endl;
  cout << "Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe; /* Deklaracja zmiennych potrzebnych do przeprowadzenia testu */ 
  LZespolona LZsp_pyt, LZsp_test;
  Wynik podsumowaine;
  int k=0;

  podsumowaine.ilosc_pytan=BazaT.IloscPytan;

cout << "TEST DZIALANIA WCZYTANIA WYR ZSP" <<endl;

WyrazenieZesp Testy;
cin >> Testy.Arg1 >> Testy.Op >> Testy.Arg2;

cout<< "Wynik dzialania: " << Testy << endl;

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) { /* Petla wczytujaca kolejne pytania z bazy testu */ 
    cin.clear();

    LZsp_test=Oblicz(WyrZ_PytanieTestowe); /* Wyznaczenie i wyliczenie oczekiwanego wyniku, ktory ma podac egzaminowany */
    cout << ":? Podaj wynik operacji:  " << WyrZ_PytanieTestowe << " =" << endl << "   Twoja odpowiedz: "; /* Wyswietlenie pytania */
    cin >> LZsp_pyt;  /* Wprowadzenie odpowiedzi egzaminowanego- Liczby zespolonej bedacej wynikiem */

    if(cin.fail())
      {
        cin.clear(); 
        cin.ignore(10000,'\n'); 
        cerr << ":! Blad foramtu liczby zespolonej"<< endl;
        cout << ":! Wpisz wynik jeszcze raz: ";
        cin >> LZsp_pyt; /* Ponowna proba wpisania L. zesp. */
        
        if(cin.fail())
        {
          cerr << ":! Blad foramtu liczby zespolonej"<< endl;
          cin.clear(); 
          cin.ignore(10000,'\n'); 
          cout << ":! Wpisz wynik jeszcze raz: ";
          cin >> LZsp_pyt; /* Ponowna proba wpisania L. zesp. */
          if(cin.fail())
          {
            cin.clear(); 
            cin.ignore(10000,'\n'); 
            cout<<":( Blad. Prawidlowym wynikiem jest: "<< LZsp_test << endl;
            continue;
          }
        }   
      }

      if (LZsp_test == LZsp_pyt) { /* Warunek zaliczajacy poprawny wynik zapisay w poprawny sposob */
        cout<<":) Odpowiedz poprawna"<<endl;
        podsumowaine.zdobyte_punkty++;
        cin.clear();
      }
      else{ /* W przypadku blednej odpowiedzi jest ona wyswietlana na ekran */
        cout<<":( Blad. Prawidlowym wynikiem jest: "<< LZsp_test <<endl;
        cin.clear();
    }
    cin.clear(); 
    k=0;
    cout << endl;
  }

InicjalizujTest(&BazaT,argv[1]); /* zrestarowanie testu, aby wyswietlic przykladowe liczby zespolone. */
 
  cout << endl << "Test wyswietlania czesci liczb zespolonych z bazy testu \n";
   while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    Wyswietl(WyrZ_PytanieTestowe.Arg1);
    cout<<endl;
  }
  cout<<endl;  /* Test dzialania funkcji obliczajacych i wyswietlajacych */ 
  LZespolona zesp1,zesp2;
  zesp1.re=3; zesp1.im=6;
  zesp2.re=2.5; zesp2.im=9.5;
  cout<<"L. zespolona 1: " << zesp1 << endl;
  cout<<"L. zespolona 2: " << zesp2 << endl;

  cout << "Testy obliczen arytmetycznych" << endl;
  cout<< "Test dodawania, wartosc zakladana to (5.5+15.25i): "<< zesp1+zesp2 << endl;
  cout<< "Test odejmowania, wartosc zakladana to (0.5-3.25i): "<< zesp1-zesp2  << endl;
  cout<< "Test mnozenia, wartosc zakladana to (-48+42.75i): " << zesp1*zesp2  << endl;
  cout<< "Test dzielenia przez liczbe zesp, wartosc zakladana to (0.686181-0.13887i): "<< zesp1/zesp2 << endl;
  cout<< "Test dzielenia liczby zespolonej 1 przez skalar (2), wartosc zakladana to (1.5+3i): "<< zesp1/2 << endl;

  cout << endl;
  cout << "Koniec testu" << endl;
  cout << endl;
  wyswietl_wynik(podsumowaine);
}

