#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include <iostream>
#include <iomanip>
#include "BazaTestu.hh"

using namespace std;

/* Modeluje pojecie statystyki testu. */
struct Wynik{ 
    double zdobyte_punkty,stracone_punkty,ilosc_pytan;

    void ustaw_statystyke(unsigned int dlugosc);
    void dodaj_punkt();
    void dodaj_niepoprawna_odp();
    void wyswietl_wynik();
    double oblicz_proc_poprawne();
    double oblicz_proc_niepoprawne();
};

ostream & operator << (ostream & StrmWy, Wynik Wynik);

#endif 