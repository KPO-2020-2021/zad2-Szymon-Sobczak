#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
#include <cmath>
#include <fstream>
#include <bits/stdc++.h>

#define MIN_DIFF 0.01 /* Definicja minimalnej roznicy- dokladnosci wyniku */

using namespace std;

/*!
 *  Plik zawiera definicje struktury LZesplona oraz przeciazenia 
 *  operatorow arytmetycznych dzialajacych na tej strukturze.
 */

/* Modeluje pojecie liczby zespolonej */

struct  LZespolona {
  double   re;    /* Pole repezentuje czesc rzeczywista */
  double   im;    /* Pole repezentuje czesc urojona */
  
  bool operator == (LZespolona  Skl2) const;
  double ModulZ();
  LZespolona Sprzezenie() ;
  
  LZespolona  operator + (LZespolona  Skl2) const;
  LZespolona  operator - (LZespolona  Skl2) const;
  LZespolona  operator * (LZespolona  Skl2) const;
  LZespolona  operator / (double skalar) const;
  LZespolona  operator / (LZespolona  Skl2) const;
};

double arg(LZespolona z);

LZespolona  operator += (LZespolona  & Skl1,LZespolona const & Arg2);
LZespolona  operator /= (LZespolona  & Skl1,LZespolona const & Arg2);

istream & operator >> (istream & StrmWe, LZespolona & Ln);
ostream & operator << (ostream & StrmWy, LZespolona Lz);

ifstream & operator >> (ifstream & StrmWe, LZespolona & Ln);

#endif 
