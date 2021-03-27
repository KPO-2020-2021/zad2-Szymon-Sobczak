#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
#include <cmath>

#define MIN_DIFF 0.01

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
  
  bool operator == (LZespolona  Skl2) const;
  double ModulZ();
  LZespolona Sprzezenie() ;

  LZespolona  operator + (LZespolona  Skl2) const;
  LZespolona  operator - (LZespolona  Skl2) const;
  LZespolona  operator * (LZespolona  Skl2) const;
  LZespolona  operator / (double skalar) const;
  LZespolona  operator / (LZespolona  Skl2) const;
  
  //istream & operator << (istream & StrmWe);
};

/* Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow */

istream & operator >> ( istream & StrmWe, LZespolona & Ln);
ostream & operator << ( ostream & StrmWy, LZespolona Lz);

#endif
