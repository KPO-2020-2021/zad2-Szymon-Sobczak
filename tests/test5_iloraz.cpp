#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test LZespolona dzielenie dwoch liczb zespolonych") {   
    LZespolona x, y, z;

    x.re = 8;
    x.im = 4;
    
    y.re = 2;
    y.im = -2;

    z.re = 1;
    z.im = 3;

    CHECK(x/y == z);
}

TEST_CASE("Test LZespolona dzielenie przez liczbe zespolona - zero") {
    LZespolona x,y;

    x.re = 9;
    x.im = 1;
    
    y.re = 0;
    y.im = 0;
 
   WARN_THROWS(x/y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}

TEST_CASE("LZespolona - dzielenie przez skalar - standardowe 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK((x/t) == y);
}

TEST_CASE("LZespolona - dzielenie przez skalar - standardowe z przyblizeniem") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.666;
    y.im = 0.666;
    std::cout << (x/t) << std::endl;
    std::cout << y << std::endl;
    std::cout << ((x/t) == y) << std::endl;
    CHECK((x/t) == y);
}

TEST_CASE("LZespolona - dzielenie, test przeciazenia operatora /= dla liczb zespolonych o wylacznie dodatnich Re i Im ") {
    LZespolona x, y, z;
    
    x.re = 5;
    x.im = 9;

    y.re = 7;
    y.im = 5;

    z.re = 1.08;
    z.im = 0.51;

    x/=y;
    CHECK(x == z);
}

TEST_CASE("LZespolona - dzielenie, test przeciazenia operatora /= dla liczb zespolonych o zmiennoprzecinkowych Re i Im ") {
    LZespolona x, y, z;
    
    x.re = 0.6;
    x.im = 0.9;

    y.re = 1.5;
    y.im = 8.5;

    z.re = 0.11;
    z.im = -0.05;

    x/=y;
    CHECK(x == z);
}

TEST_CASE("LZespolona - dzielenie, test przeciazenia operatora /= dla liczby zespolonej przez 0") {
    LZespolona x, y;
    
    x.re = 7;
    x.im = 9;

    y.re = 0;
    y.im = 0;

    WARN_THROWS(x/=y);
}
