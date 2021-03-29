#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("LZespolona - roznica 1, odejmowanie liczb zespolonych calkowitych"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 0;
    z.im = 4;
    
    CHECK(x-y == z);
}

TEST_CASE("LZespolona - roznica 2, odejmowanie zera do liczb zespolonych calkowitych"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 1;
    z.im = 1;
    
    CHECK(x-y == z);
}

TEST_CASE("LZespolona - roznica 3, odejmowanie liczb zespolonych z czescia dziesietna"){
    LZespolona x, y, z;

    x.re = 1.3;
    x.im = 1.3;

    y.re = 1.1;
    y.im = 1.1;

    z.re = 0.2;
    z.im = 0.2;
    
    CHECK(x-y == z);
}

TEST_CASE("LZespolona - roznica 4, odejmowanie liczb zespolonych z czescia dziesietna i zera"){
    LZespolona x, y, z;

    x.re = 1.1;
    x.im = 1.1;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 1.1;
    z.im = 1.1;
    
    CHECK(x-y == z);
}

TEST_CASE("LZespolona - roznica 5, odejmowanie liczb zespolonych ze zmiana na granicy"){
    LZespolona x, y, z;

    x.re = 1.001;
    x.im = 1.001;

    y.re = 1.009;
    y.im = 1.009;

    z.re = -0.01;
    z.im = -0.01;
    
    CHECK(x-y == z);
}

TEST_CASE("LZespolona - roznica 6, odejmowanie liczb zespolonych z warosciami poza przedzialem dokladnosci"){
    LZespolona x, y, z;

    x.re = 0.0009;
    x.im = 0.0009;

    y.re = 0.0001;
    y.im = 0.0001;

    z.re = 0.01;
    z.im = 0.01;
    
    CHECK(x-y == z);
}