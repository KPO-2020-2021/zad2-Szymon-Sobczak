#ifndef BAZATESTU_HH
#define BAZATESTU_HH

#include "WyrazenieZesp.hh"
#include <fstream>

/*
 * Modeluje pojecie baze testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania, ktore ma byc pobrane
 * z bazy.
 * Dodatkowo moze przechowywac informacje o znawie pliku, z ktrego beda wczytywane pytania.
 */
 
struct BazaTestu {
  WyrazenieZesp  *wskTabTestu;   /* Wskaznik na tablice zawierajaca pytania testu */
  unsigned int    IloscPytan;    /* Ilosc wszystkich pytan */
  unsigned int    IndeksPytania; /* Numer pytania, ktore ma byc pobrane jako nastepne */
  string nazwa_zestawu; /* Nazwa pliku, bedacego zewnetrzna baza testu */
  
  void UstawTest(WyrazenieZesp *wskTabTestu, unsigned int IloscPytan);
  bool InicjalizujTest(const char*  sNazwaTestu);
  bool PobierzNastpnePytanie( WyrazenieZesp *wskWyr);

  BazaTestu  Translacja_pliku_na_bazatestu(string nazwa_pliku);
};

#endif 