#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include <string>
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

TEST_CASE("LZespolona - wyswietlanie standard") {
    LZespolona x;
   
    x.re = 2;
    x.im = 2;
    
    std::ostringstream out;
    
    out << x;
    std::cout << out.str() << std::endl;
    CHECK( "(2.00+2.00i)" == out.str() );
}

TEST_CASE("LZespolona - wyswietlanie zaokraglane") {
    LZespolona x;
   
    x.re = 2.0/3.0;
    x.im = 2.0/3.0;
    
    std::ostringstream out;
    
    out << x;
    std::cout << out.str() << std::endl;
    CHECK( "(0.67+0.67i)" == out.str() );
}

TEST_CASE("WyrZespolone - wyswietlanie standard") {
    WyrazenieZesp x;
    x.Arg1.re = 5; x.Arg1.im = 7;
    x.Arg2.re = 1; x.Arg2.im = 3;
    x.Op = Op_Dodaj;
    std::ostringstream out;
    out << x;
    std::cout << out.str() << std::endl;
    CHECK( "(5.00+7.00i) + (1.00+3.00i)" == out.str());
}

TEST_CASE("WyrZespolone - wyswietlanie zaokraglane") {
    WyrazenieZesp x;
    x.Arg1.re = -5.126; x.Arg1.im = 7.985;
    x.Arg2.re = 7.351; x.Arg2.im = -3.852;
    x.Op = Op_Mnoz;
    std::ostringstream out;
    out << x;
    std::cout << out.str() << std::endl;
    CHECK( "(-5.13+7.99i) * (7.35-3.85i)" == out.str());
}

TEST_CASE("Test funkcji arg() wyznaczajacej Arg. gl. dla liczby zespolonej o Re = 0 i Im = 0") {
    LZespolona x;
    x.re = 0;
    x.im = 0;
    WARN_THROWS (arg(x));
}

TEST_CASE("Test funkcji arg() wyznaczajacej Arg. gl. dla liczby zespolonej o Re > 0 i Im > 0") {
    LZespolona x;
    x.re = 5;
    x.im = 9;
    CHECK((arg(x) > 1.05 && arg(x) < 1.07));
}

TEST_CASE("Test funkcji arg() wyznaczajacej Arg. gl. dla liczby zespolonej o Re > 0 i Im > 0 bedacych libczami zmiennoprzecinkowymi ") {
    LZespolona x;
    x.re = 0.9;
    x.im = -0.2;
    CHECK((arg(x) > -0.22 && arg(x) < -0.20));
}

TEST_CASE("Test funkcji arg() wyznaczajacej Arg. gl. dla liczby zespolonej o Re = 0 i Im > 0") {
    LZespolona x;
    x.re = 0;
    x.im = 5;
    CHECK((arg(x) > 1.56 && arg(x) < 1.58));
}

TEST_CASE("Test funkcji arg() wyznaczajacej Arg. gl. dla liczby zespolonej o Re = 0 i Im < 0") {
    LZespolona x;
    x.re = 0;
    x.im = -9;
    CHECK((arg(x) > -1.58 && arg(x) < -1.56));
}