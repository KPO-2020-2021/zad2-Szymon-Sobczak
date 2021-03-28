#include <iostream>

#include "BazaTestu.hh"
#include "Statystyka.hh"

using namespace std;

int tryb;

int main(int argc, char **argv)
{
  WyrazenieZesp   WyrZ_PytanieTestowe; /* Deklaracja zmiennych potrzebnych do przeprowadzenia testu */ 
  LZespolona LZsp_pyt, LZsp_test;
  Wynik podsumowaine;
  BazaTestu   BazaT = {nullptr, 0, 0}; 
/* Pobranie argumentu wywolania programu, w celu okreslenia poziomu trudnosci testu */
try{
  if ((argc < 2 && strcmp(argv[1],"wlasny")) || ((argc > 3)&& !strcmp(argv[1],"wlasny"))) { 
    throw runtime_error("Brak opcji okreslajacej rodzaj testu.\nDopuszczalne nazwy to:  latwy, trudny, wlasny\n");
  }

  if(!strcmp(argv[1],"wlasny")){
    BazaT.nazwa_zestawu = argv[2];
  }

    if (BazaT.InicjalizujTest(argv[1]) == false) { /* Inicjalizacja testu ze wzgledu na wybrany napis "latwy", "trudny" wraz z warunkiem, gdy napis nie zostanie podany*/
    throw runtime_error("Inicjalizacja testu nie powiodla sie.\n");
  }
  
  podsumowaine.ustaw_statystyke(BazaT.IloscPytan);
 
    while (BazaT.PobierzNastpnePytanie(&WyrZ_PytanieTestowe)) { /* Petla wczytujaca kolejne pytania z bazy testu */ 
      LZsp_test=WyrZ_PytanieTestowe.Oblicz(); /* Wyznaczenie i wyliczenie oczekiwanego wyniku, ktory ma podac egzaminowany */
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
              podsumowaine.dodaj_niepoprawna_odp();
              continue;
            }
          }   
        }
        if (LZsp_test == LZsp_pyt) { /* Warunek zaliczajacy poprawny wynik zapisany w poprawny sposob */
          cout<<":) Odpowiedz poprawna"<<endl;
          podsumowaine.dodaj_punkt();
          cin.clear();
        }
        else{ /* W przypadku blednej odpowiedzi jest ona wyswietlana na ekran */
          cout<<":( Blad. Prawidlowym wynikiem jest: "<< LZsp_test <<endl;
          podsumowaine.dodaj_niepoprawna_odp();
          cin.clear();
      }
      cin.clear(); 
      cout << endl;
    }
  }
  catch (runtime_error & e) 
  {
    cerr << "Wystapil blad!" << endl << e.what();
    exit(1);
  }

  cout << "Koniec testu" << endl << endl << podsumowaine;

  return 0;
}


/*
 cout << endl<< "Testy obliczen arytmetycznych i wyswietlajacych:" << endl << endl;
  
    LZespolona zesp1={3,2},zesp2{2,9},zesp3{0.53,0.2275},zesp4{0.000224,46}; 
    
    cout <<"L. zespolona 1: " << zesp1 << endl;
    cout <<"L. zespolona 2: " << zesp2 << endl;
    
    cout << "Bwah bwah:" << zesp3/zesp4 <<endl;

    cout << "Test dodawania, wartosc zakladana to (5+11i): "<< zesp1+zesp2 << endl;
    cout << "Test odejmowania, wartosc zakladana to (1-7i): "<< zesp1-zesp2  << endl;
    cout << "Test mnozenia, wartosc zakladana to (-12+31i): " << zesp1*zesp2  << endl;
    cout << "Test dzielenia przez liczbe zesp, wartosc zakladana to (0.282353-0.270588i): "<< zesp1/zesp2 << endl;
    cout << "Test dzielenia liczby zespolonej 1 przez skalar (2), wartosc zakladana to (1.5+1i): "<< zesp1/2 << endl;
    cout << "Test sprzerzenia z liczby zespolonej 1. wartosc zakladana to (3-2i): " << zesp1.Sprzezenie() << endl;
    cout << "Test wyznacznaia modulu z liczby zespolonej 1. wartosc zakladana to: 3.60555, Wynik: " << zesp1.ModulZ() << endl;

    cout << endl;
    cout << "Start testu arytmetyki zespolonej: " << argv[1] << endl;
    cout << endl;
    */