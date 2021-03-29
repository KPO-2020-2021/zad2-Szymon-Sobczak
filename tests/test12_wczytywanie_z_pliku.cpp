#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "BazaTestu.hh"

TEST_CASE("Wczytywanie z pliku, test wczytania przykladowych danych Dr. Kreczmera") {
    string x = "Arytmetyka_plik.txt";
    BazaTestu y;
    y.Translacja_pliku_na_bazatestu(x);
    std::ostringstream out;
    for (unsigned int i=0;i<y.IloscPytan;i++)
        out << y.wskTabTestu[i]<<endl;
    std::cout << out.str() << std::endl;
    CHECK("(1.20+2.00i) + (0.00+2.00i)\n(2.00-0.00i) * (-1.00+1.30i)\n(1.00-4.00i) / (0.00-2.00i)\n(1.00+2.00i) - (1.00-2.00i)\n(0.00+0.00i) * (1241.00-2890.00i)\n" == out.str());
} 

TEST_CASE("Wczytywanie z pliku, wykonanie obliczenia na 1. wyrazeniu zespolonym pochodzacym z pliku Dr. Kreczmera") {
    string x = "Arytmetyka_plik.txt";
    BazaTestu y;
    LZespolona z;
    
    z.re=1.20;
    z.im=4.00;

    y.Translacja_pliku_na_bazatestu(x);
    
    CHECK(y.wskTabTestu[0].Oblicz() ==z);
} 

TEST_CASE("Wczytywanie z pliku, test wczytania nieistniejacego pliku") {
    string x = "bledny";
    BazaTestu y;
    WARN_THROWS(y.Translacja_pliku_na_bazatestu(x));
} 