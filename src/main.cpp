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
  podsumowaine.ilosc_pytan=BazaT.IloscPytan;
  podsumowaine.zdobyte_punkty=0;
  WyrazenieZesp Testy;

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) { /* Petla wczytujaca kolejne pytania z bazy testu */ 

    LZsp_test=Oblicz(WyrZ_PytanieTestowe); /* Wyznaczenie i wyliczenie oczekiwanego wyniku, ktory ma podac egzaminowany */
    cout << ":? Podaj wynik operacji:  " << WyrZ_PytanieTestowe << " =" << endl << "   Twoja odpowiedz: "; /* Wyswietlenie pytania */
    cin >> LZsp_pyt;  /* Wprowadzenie odpowiedzi egzaminowanego- Liczby zespolonej bedacej wynikiem */
    if(cin.fail()){ /* W wypadku podania blednego formatu liczby, uzytkownik posiada jeszcze dwie szanse na wpisanie poprawnego wyniku dzialania */
        cin.clear(); 
        cin.ignore(10000,'\n'); 
        cerr << ":! Blad foramtu liczby zespolonej"<< endl;
        cout << ":? Wpisz wynik jeszcze raz, masz jeszcze dwie szanse: ";
        cin >> LZsp_pyt; /* Ponowna proba wpisania L. zesp. */
        
        if(cin.fail()){
          cerr << ":! Blad foramtu liczby zespolonej"<< endl;
          cin.clear(); 
          cin.ignore(10000,'\n'); 
          cout << ":? Wpisz wynik jeszcze raz, ostatnia proba: ";
          cin >> LZsp_pyt; /* Ponowna proba wpisania L. zesp. */
          if(cin.fail()){
            cin.clear(); 
            cin.ignore(10000,'\n'); 
            cout<<":( Blad. Prawidlowym wynikiem jest: "<< LZsp_test << endl << endl;
            continue;
          }
        }   
      }

      if (LZsp_test == LZsp_pyt) { /* Warunek zaliczajacy poprawny wynik zapisany w poprawny sposob */
        cout<<":) Odpowiedz poprawna"<<endl;
        podsumowaine.zdobyte_punkty++;
        cin.clear();
      }
      else{ /* W przypadku blednej odpowiedzi jest ona wyswietlana na ekran */
        cout<<":( Blad. Prawidlowym wynikiem jest: "<< LZsp_test <<endl;
        cin.clear();
    }
    cin.clear(); 
    cout << endl;
  }

  cout << "Koniec testu" << endl << endl;
  wyswietl_wynik(podsumowaine);

  cout << endl << "Testy programu Tydzien 0 i 1:" << endl;

  InicjalizujTest(&BazaT,argv[1]); /* zrestarowanie testu, aby wyswietlic przykladowe liczby zespolone. */

  cout << endl << "Test wyswietlania czesci liczb zespolonych z bazy testu za pomoca przeciazenia operatora << \n";
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << WyrZ_PytanieTestowe.Arg1;
    cout<<endl;
  }
  cout<<endl;  

  LZespolona ZSP_test;

  cout << "Test wprowadzania i wyswietlania wprowadzonej l. zespolonej: " << endl << "Podaj liczbe zespolona do wyswietlenia np. (5+6i): ";

  do /* Test zakonczy sie gdy uzytkownik poda wlasciwe wyrazenie zespolone */
  {
     cin >> ZSP_test; 
     if (cin.fail()) /* Ponowna proba wprowadzenia wyrazenia zepolonego w przypadku bledu */
     {
       cout<< "Blad. Bledna forma liczby zespolonej "<<endl; 
       cin.clear();
       cin.ignore(10000,'\n'); 
       cout<< "  :? podaj liczbe zespolona ponownie: ";
       cin >> ZSP_test;;
     }
  }while (cin.fail());
  cout<< "Wprowadzona liczba zespolona: " << ZSP_test << endl; /* Wypisanie podanej liczby zespolonej na terminal */

  cout << endl<< "Testy obliczen arytmetycznych i wyswietlajacych:" << endl << endl;
  
  LZespolona zesp1={3,2},zesp2{2,9}; 
  
  cout <<"L. zespolona 1: " << zesp1 << endl;
  cout <<"L. zespolona 2: " << zesp2 << endl;

  cout << "Test dodawania, wartosc zakladana to (5+11i): "<< zesp1+zesp2 << endl;
  cout << "Test odejmowania, wartosc zakladana to (1-7i): "<< zesp1-zesp2  << endl;
  cout << "Test mnozenia, wartosc zakladana to (-12+31i): " << zesp1*zesp2  << endl;
  cout << "Test dzielenia przez liczbe zesp, wartosc zakladana to (0.282353-0.270588i): "<< zesp1/zesp2 << endl;
  cout << "Test dzielenia liczby zespolonej 1 przez skalar (2), wartosc zakladana to (1.5+1i): "<< zesp1/2 << endl;
  cout << "Test sprzerzenia z liczby zespolonej 1. wartosc zakladana to (3-2i): " << Sprzezenie(zesp1) << endl;
  cout << "Test wyznacznaia modulu z liczby zespolonej 1. wartosc zakladana to: 3.60555, Wynik: " << ModulZ(zesp1) << endl;
  
  cout << endl << "Test dzialania funkcji wczytujacej i wyswietlajacej wyrazenia zespolone" << endl << "  :? podaj wyrazenie np. (3+6i)-(9-9i): "; 
  do /* Test zakonczy sie gdy uzytkownik poda wlasciwe wyrazenie zespolone */
  {
     cin >> Testy; 
     if (cin.fail()) /* Ponowna proba wprowadzenia wyrazenia zepolonego w przypadku bledu */
     {
       cout<< "Blad. Bledne wyrazenie wyrazenia zespolonego "<<endl; 
       cin.clear();
       cin.ignore(10000,'\n'); 
       cout<< "  :? podaj wyrazenie ponownie: ";
       cin >> Testy;
     }
  }while (cin.fail());
  cout<< "Wprowadzone wyrazenie zespolone: " << Testy << endl; /* Wypisanie podanego wyrazenia zespolonego na terminal */
  cout<< "Koniec testow programu " << endl;
  return 0;
}

