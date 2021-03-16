#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH
#include "LZespolona.hh"
#include <cstring>
/*
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel};

/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};

/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 */

void Wyswietl(WyrazenieZesp  WyrZ); /* Funckja wyswietlajaca wyrazenie zespolone   */

LZespolona Oblicz(WyrazenieZesp  WyrZ); /* Funckja obliczajaca wyrazenie zespolone */

ostream & operator << (ostream & StrmWy, Operator WypSym); 

istream & operator >> (istream & StrmWe, Operator & WczytSym); /* Przeciązenie operatorow, dpo wczyania operatora arytmetycznego w wyrazaniu zespolonym*/

ostream & operator << ( ostream & StrmWy, WyrazenieZesp WyrZ); /* Przeciązenie operatorow, do wyswietlania wyrazaenia zespolonego */

//istream & operator >> ( istream & StrmWe, WyrazenieZesp & WyrZ);

#endif
