#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
#include <cmath>

using namespace std;

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */

struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


void Wyswietl(LZespolona skl);

LZespolona Sprzezenie(LZespolona skl);

double ModulZ(LZespolona);

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

istream & operator >> ( istream & StrmWe, LZespolona & Ln);

ostream & operator << ( ostream & StrmWy, LZespolona Lz);

bool operator == (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2); 
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl,  double skalar);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);


#endif
