#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include <iostream>
#include <iomanip>

using namespace std;

struct Wynik{
    double zdobyte_punkty;
    double ilosc_pytan;
};

void wyswietl_wynik(Wynik elem);

#endif
