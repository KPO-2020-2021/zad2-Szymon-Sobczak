#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
 
TEST_CASE("WyrZespolone - sprawdzenie dzialania sumy liczb zespolonych z calkowitymi wspolczynnikami Re i Im") {
    WyrazenieZesp x;
    LZespolona y;
    x.Arg1.re = 5; x.Arg1.im = 7;
    x.Arg2.re = 1; x.Arg2.im = 3;
    x.Op = Op_Dodaj;
    
    y.re= 6; y.im= 10;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("WyrZespolone - sprawdzenie dzialania sumy liczb zespolonych z niecalkowitymi wspolczynnikami Re i Im") {
    WyrazenieZesp x;
    LZespolona y;
    x.Arg1.re = 5.518; x.Arg1.im = -7.358;
    x.Arg2.re = -1.15; x.Arg2.im = 3.05;
    x.Op = Op_Dodaj;
    
    y.re= 4.37; y.im= -4.31;
    
    CHECK(x.Oblicz() == y);
}

TEST_CASE("WyrZespolone - sprawdzenie dzialania roznicy liczb zespolonych z calkowitymi wspolczynnikami Re i Im") {
    WyrazenieZesp x;
    LZespolona y;
    x.Arg1.re = 5; x.Arg1.im = 7;
    x.Arg2.re = 1; x.Arg2.im = 3;
    x.Op = Op_Odejmij;
    
    y.re= 4; y.im= 4;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("WyrZespolone - sprawdzenie dzialania roznicy liczb zespolonych z niecalkowitymi wspolczynnikami Re i Im") {
    WyrazenieZesp x;
    LZespolona y;
    x.Arg1.re = 5.518; x.Arg1.im = -7.358;
    x.Arg2.re = -1.15; x.Arg2.im = 3.05;
    x.Op = Op_Odejmij;
    
    y.re= 6.67; y.im= -10.41;
    
    CHECK(x.Oblicz() == y);
}

TEST_CASE("WyrZespolone - sprawdzenie dzialania ilocznu liczb zespolonych z calkowitymi wspolczynnikami Re i Im") {
    WyrazenieZesp x;
    LZespolona y;
    x.Arg1.re = 5; x.Arg1.im = 7;
    x.Arg2.re = 1; x.Arg2.im = 3;
    x.Op = Op_Mnoz;
    
    y.re= -16; y.im= 22;
    
    CHECK(x.Oblicz() == y);
}

TEST_CASE("WyrZespolone - sprawdzenie dzialania ilocznu zespolonych z niecalkowitymi wspolczynnikami Re i Im") {
    WyrazenieZesp x;
    LZespolona y;
    x.Arg1.re = 5.518; x.Arg1.im = -7.358;
    x.Arg2.re = -1.15; x.Arg2.im = 3.05;
    x.Op = Op_Mnoz;
    
    y.re= 16.10; y.im= 25.29;
    
    CHECK(x.Oblicz() == y);
}

TEST_CASE("WyrZespolone - sprawdzenie dzialania ilorazu dwoch liczb zespolonych z calkowitymi wspolczynnikami Re i Im") {
    WyrazenieZesp x;
    LZespolona y;
    x.Arg1.re = 5; x.Arg1.im = 7;
    x.Arg2.re = 1; x.Arg2.im = 3;
    x.Op = Op_Dziel;
    
    y.re= 2.6; y.im= -0.8;
    
    CHECK(x.Oblicz() == y);
}

TEST_CASE("WyrZespolone - sprawdzenie dzialania ilorazu dwoch liczb zespolonych z niecalkowitymi wspolczynnikami Re i Im") {
    WyrazenieZesp x;
    LZespolona y;
    x.Arg1.re = 5.518; x.Arg1.im = -7.358;
    x.Arg2.re = -1.15; x.Arg2.im = 3.05;
    x.Op = Op_Dziel;
    
    y.re= -2.71; y.im= -0.79;
    
    CHECK(x.Oblicz() == y);
}

TEST_CASE("WyrZespolone - sprawdzenie dzialania ilorazu liczby zespolonej i zera") {
    WyrazenieZesp x;
    x.Arg1.re = 5.518; x.Arg1.im = -7.358;
    x.Arg2.re = 0; x.Arg2.im = 0;
    x.Op = Op_Dziel;

    WARN_THROWS(x.Oblicz());
} 