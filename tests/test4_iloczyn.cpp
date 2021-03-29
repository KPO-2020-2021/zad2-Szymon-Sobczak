#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("LZespolona - iloczyn 1, mnozenie liczb zespolonych calkowitych"){
    LZespolona x, y, z;

    x.re = 8;
    x.im = 9;

    y.re = 3;
    y.im = 4;

    z.re = -12;
    z.im = 59;
    
    CHECK(x*y == z);
}

TEST_CASE("LZespolona - iloczyn 2, mnozenie liczby zespolonej calkowitych i (1+0i)"){
    LZespolona x, y, z;

    x.re = 3;
    x.im = 5;

    y.re = 1;
    y.im = 0;

    z.re = 3;
    z.im = 5;
    
    CHECK(x*y == z);
}

TEST_CASE("LZespolona - iloczyn 3, mnozenie liczby zespolonej  calkowitych i (0+1i))"){
    LZespolona x, y, z;

    x.re = 3;
    x.im = 5;

    y.re = 0;
    y.im = 1;

    z.re = -5;
    z.im = 3;
    
    CHECK(x*y == z);
}

TEST_CASE("LZespolona - iloczyn 4, mnozenie liczb zespolonych calkowitych i (0+0i)"){
    LZespolona x, y, z;

    x.re = 3;
    x.im = 5;

    y.re = 0;
    y.im = 0;

    z.re = 0;
    z.im = 0;
    
    CHECK(x*y == z);
}


TEST_CASE("LZespolona - iloczyn 5, mnozenie liczb zespolonych calkowitych i (1+1i)"){
    LZespolona x, y, z;

    x.re = 3;
    x.im = 5;

    y.re = 1;
    y.im = 1;

    z.re = -2;
    z.im = 8;
    
    CHECK(x*y == z);
}
TEST_CASE("LZespolona - iloczyn 6, mnozenie liczb zespolonych z czescia dziesietna i setna w celu sprawdzenia zaokraglenia"){
    LZespolona x, y, z;

    x.re = 1.25;
    x.im = 3.75;

    y.re = 5.35;
    y.im = 7.45;

    z.re = -21.25;
    z.im = 29.38;
    
    CHECK(x*y == z);
}

TEST_CASE("LZespolona - iloczyn 7, mnozenie liczb zespolonych z waroscaimi przekraczajacymi minimalna roznica"){
    LZespolona x, y, z;

    x.re = 0.0005;
    x.im = 0.0005;

    y.re = 0.0009;
    y.im = 0.0009;

    z.re = 0.01;
    z.im = 0.01;
    
    CHECK(x*y == z);
} 