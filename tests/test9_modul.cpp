#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("LZespolona - test dzialania modlulu z liczby zespolonej, gdy czesci Re i Im calkowitych") {
    LZespolona x;

    x.re = 3;
    x.im = 7;

    CHECK( (x.ModulZ() >= 7.61 && x.ModulZ() <= 7.62));
}

TEST_CASE("LZespolona - test dzialania modlulu z liczby zespolonej, gdy czesci Re i Im zmiennoprzecinkowych") {
    LZespolona x;
   
    x.re = 1.15;
    x.im = -8.75;
    
    CHECK((x.ModulZ() >= 8.81 && x.ModulZ() <= 8.83));
}

TEST_CASE("LZespolona - test dzialania modlulu z liczby zespolonej, gdy czesci Re i Im sa zerami") {
    LZespolona x;
   
    x.re = 0;
    x.im = 0;
    
    CHECK(x.ModulZ() == 0);
}