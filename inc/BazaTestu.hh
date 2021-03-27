#ifndef BAZATESTU_HH
#define BAZATESTU_HH

#include "WyrazenieZesp.hh"

/*
 * Modeluje pojecie baze testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania, ktore ma byc pobrane
 * z bazy.
 */
 
struct BazaTestu {
  WyrazenieZesp  *wskTabTestu;   /* Wskaznik na tablice zawierajaca pytania testu */
  unsigned int    IloscPytan;    /* Ilosc wszystkich pytan */
  unsigned int    IndeksPytania; /* Numer pytania, ktore ma byc pobrane jako nastepne */

  void UstawTest(WyrazenieZesp *wskTabTestu, unsigned int IloscPytan);

  /* Inicjalizuje test powiazany z dana nazwa.*/
  bool InicjalizujTest(const char*  sNazwaTestu);

  /* Udostepnia nastepne pytanie z bazy. */
  bool PobierzNastpnePytanie( WyrazenieZesp *wskWyr);
};

#endif
