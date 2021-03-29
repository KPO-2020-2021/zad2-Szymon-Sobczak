/*Przygotowal: Szymon Sobczak, nr 259275*/
#include <iostream>

#include "BazaTestu.hh"
#include "Statystyka.hh"

using namespace std;

int main(int argc, char **argv){
  WyrazenieZesp   WyrZ_PytanieTestowe; /* Deklaracja zmiennych potrzebnych do przeprowadzenia testu */ 
  LZespolona LZsp_pyt, LZsp_test;
  Wynik podsumowaine;
  BazaTestu   BazaT = {nullptr, 0, 0}; 

  try{  
    /* Sprawdzenie poprawnosci argumetow wywolania programu */
    if ((argc < 2) || ((argc > 3) && !strcmp(argv[1],"wlasny"))) { 
      throw runtime_error("Brak opcji okreslajacej rodzaj testu.\nDopuszczalne nazwy to:  latwy, trudny, wlasny\n");
    }
    /* W wypadku wczytywania zestawu pytan z pliku, wczytanie nazwy pliku z ktorego beda czytane pytania */
    if(!strcmp(argv[1],"wlasny")){ 
      if(argv[2]==NULL)
        throw runtime_error("Brak nazwy pliku zawierajacego test\n");
      BazaT.nazwa_zestawu = argv[2];
    }
    /* Pobranie argumentu wywolania programu, w celu okreslenia poziomu trudnosci testu */
    if (BazaT.InicjalizujTest(argv[1]) == false) { /* Inicjalizacja testu ze wzgledu na wybrany napis "latwy", "trudny", "wlasny" */
      throw runtime_error("Inicjalizacja testu nie powiodla sie.\n"); /* Jesli inicjalziacja testu nie uda sie, zglos blad */
    }
    podsumowaine.ustaw_statystyke(BazaT.IloscPytan); /* Inicjalizacja statystyki testu */
    while (BazaT.PobierzNastpnePytanie(&WyrZ_PytanieTestowe)) { /* Petla wczytujaca kolejne pytania z bazy testu */ 
      LZsp_test=WyrZ_PytanieTestowe.Oblicz(); /* Wyznaczenie i wyliczenie oczekiwanego wyniku, ktory ma podac egzaminowany */
      cout << ":? Podaj wynik operacji:  " << WyrZ_PytanieTestowe << " =" << endl << "   Twoja odpowiedz: "; /* Wyswietlenie pytania */
      cin >> LZsp_pyt;  /* Wprowadzenie odpowiedzi egzaminowanego- Liczby zespolonej bedacej wynikiem */
      if(cin.fail()){ /* W wypadku podania blednego formatu liczby, uzytkownik posiada jeszcze dwie szanse na wpisanie poprawnego wyniku dzialania */
          cin.clear(); /* Opuszczenie flag informujacych o wystapieniu bledu na strumieniu */
          cin.ignore(10000,'\n'); /* Pominiecie blednych znakow */
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
              cout<<":( Blad. Prawidlowym wynikiem jest: "<< LZsp_test << endl << endl; /* Wyswietlanie informacji o prawidlowym wyniku */
              podsumowaine.dodaj_niepoprawna_odp(); /* Odnotowanie wystpaienia niepoprawnej odpwoiedzi */
              continue; /* Przejdz do kolejnego pytania */
            }
          }   
        }
        if (LZsp_test == LZsp_pyt) { /* Warunek zaliczajacy poprawny wynik, zapisany w poprawny sposob */
          cout<<":) Odpowiedz poprawna"<<endl;
          podsumowaine.dodaj_punkt(); /* Odnotowanie wystpaienia poprawnej odpowiedzi */
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
  catch (runtime_error & e){ /* Reakcja w wyniku wystapienia bledu */
    cerr << "Wystapil blad!" << endl << e.what();
    exit(1);
  }
  cout << "Koniec testu" << endl << endl << podsumowaine; /* Wyswietlenie statystyki przeprowadzonego testu */
  return 0;
} 