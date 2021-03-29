#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("LZespolona - dodawanie, dodawanie liczb zespolonych calkowitych"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
}

TEST_CASE("LZespolona - dodawanie, dodawanie zera do liczb zespolonych calkowitych"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 1;
    z.im = 1;
    
    CHECK(x+y == z);
}

TEST_CASE("LZespolona - dodawanie, dodawanie liczb zespolonych z czescia dziesietna"){
    LZespolona x, y, z;

    x.re = 1.3;
    x.im = 1.3;

    y.re = 1.1;
    y.im = 1.1;

    z.re = 2.4;
    z.im = 2.4;
    
    CHECK(x+y == z);
}

TEST_CASE("LZespolona - dodawanie, dodawanie liczb zespolonych z czescia dziesietna i zera"){
    LZespolona x, y, z;

    x.re = 1.1;
    x.im = 1.1;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 1.1;
    z.im = 1.1;
    
    CHECK(x+y == z);
}

TEST_CASE("LZespolona - dodawanie, dodawanie liczb zespolonych ze zmiana na granicy"){
    LZespolona x, y, z;

    x.re = 1.001;
    x.im = 1.001;

    y.re = 1.009;
    y.im = 1.009;

    z.re = 2.01;
    z.im = 2.01;
    
    CHECK(x+y == z);
}

TEST_CASE("LZespolona - dodawanie, dodawanie liczb zespolonych z warosciami poza przedzialem dokladnosci"){
    LZespolona x, y, z;

    x.re = 0.0009;
    x.im = 0.0009;

    y.re = 0.0001;
    y.im = 0.0001;

    z.re = 0.01;
    z.im = 0.01;
    
    CHECK(x+y == z);
}

TEST_CASE("LZespolona - dodawanie, test przeciazenia += dla liczb zespolonych o wylczanie dodatnich re i im"){
    LZespolona x, y, z;

    x.re = 5;
    x.im = 9;

    y.re = 7;
    y.im = 1;

    z.re = 12.00;
    z.im = 10.00;
    
    x+=y;

    CHECK(x == z);
}

TEST_CASE("LZespolona - dodawanie, test przeciazenia += dla liczb zespolonych o dodatnich i ujemnych re i im"){
    LZespolona x, y, z;

    x.re = 5;
    x.im = 9;

    y.re = -7;
    y.im = -1;

    z.re = -2.00;
    z.im = 8.00;
    
    x+=y;

    CHECK(x == z);
}

TEST_CASE("LZespolona - dodawanie, test przeciazenia += dla liczb zespolonych bedacych zerami"){
    LZespolona x, y, z;

    x.re = 0;
    x.im = 0;

    y.re = 0;
    y.im = 0;

    z.re = 0;
    z.im = 0;
    
    x+=y;

    CHECK(x == z);
}

TEST_CASE("LZespolona - dodawanie, test przeciazenia += dla liczb zespolonych o re i im zmiennoprzecinkowch"){
    LZespolona x, y, z;

    x.re = 0.02;
    x.im = 0.05;

    y.re = -0.8;
    y.im = 0;

    z.re = -0.78;
    z.im = 0.05;
    
    x+=y;

    CHECK(x == z);
}