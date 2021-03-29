#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("LZespolona - test dla niezerowej wartosci urojonej") {
    LZespolona x, y;
   
    x.re = 2.25;
    x.im = -8.35;

    y.re = 2.25;
    y.im = 8.35;

    CHECK(x.Sprzezenie() == y);
}

TEST_CASE("LZespolona - test dla zerowej wartosci urojonej") {
    LZespolona x, y;
   
    x.re = 2;
    x.im = 0;

    y.re = 2;
    y.im = 0;

    CHECK(x.Sprzezenie() == y);
} 