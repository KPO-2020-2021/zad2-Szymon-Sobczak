#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"


TEST_CASE("LZespolona - porownanie 1, rowne") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 2;
    y.im = 2;
   
    CHECK(x == y);
}

TEST_CASE("LZespolona - porownanie 2, nireowne") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(!(x == y));
}

TEST_CASE("LZespolona - porownanie 3, minimalne nierowne") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 2.01;
    y.im = 1.99;
   
    CHECK(x == y);
}

TEST_CASE("LZespolona - porownanie 4, rzad mniejsze niz zalozona minimalna roznica") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 1.999;
    y.im = 1.999;
   
    CHECK(x == y);
} 