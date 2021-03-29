#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

TEST_CASE("LZespolona - wczytywanie standard") {
    LZespolona x;
    
    std::istringstream in("(3.75+1.10i)");
    in >> x;
    std::ostringstream out;
    out << x; 
    
    CHECK("(3.75+1.10i)" == out.str());
}

TEST_CASE("LZespolona test przeciazenia wczytania- wychwycenie bledu w zapisie LZespolonej, niewlasciwe znaki") {
    LZespolona x;
    std::istringstream in("#8?8.15z)");
    in >> x;
    CHECK(in.fail());
}

TEST_CASE("LZespolona test przeciazenia wczytania- wychwycenie bledu w zapisie LZespolonej, brak nawiasu otwierajacego") {
    LZespolona x;
    std::istringstream in("8+8.15i)");
    in >> x;
    CHECK(in.fail());
}

TEST_CASE("LZespolona test przeciazenia wczytania- wychwycenie bledu w zapisie LZespolonej, brak czesci rzeczywistej LZespolonej") {
    LZespolona x;
    std::istringstream in("(+8.15i)");
    in >> x;
    CHECK(in.fail());
}

TEST_CASE("LZespolona test przeciazenia wczytania- wychwycenie bledu w zapisie LZespolonej, brak symblou arytmetycnego") {
    LZespolona x;
    std::istringstream in("(8?8.15i)");
    in >> x;
    CHECK(in.fail());
}

TEST_CASE("LZespolona test przeciazenia wczytania- wychwycenie bledu w zapisie LZespolonej, brak symolu 'i'") {
    LZespolona x;
    std::istringstream in("(+8.15)");
    in >> x;
    CHECK(in.fail());
}

TEST_CASE("LZespolona test przeciazenia wczytania- wychwycenie bledu w zapisie LZespolonej, brak nawiasu zamykającego") {
    LZespolona x;
    std::istringstream in("(8+8.15i");
    in >> x;
    CHECK(in.fail());
}

TEST_CASE("WyrZsespolone - wczytywanie standard") {
    WyrazenieZesp x;
    
    std::istringstream in("(3.75+1.1i)+(4+9i)");
    in >> x;
    std::ostringstream out;
    out << x; 
    
    CHECK("(3.75+1.10i) + (4.00+9.00i)" == out.str());
}

TEST_CASE("WyrZsespolone test przeciazenia wczytania- wychwycenie bledu w zapisie WyrZsespolonego, brak 1 argumentu") {
    WyrazenieZesp x; 

    std::istringstream in("+(4+9i)");
    in >> x;
    CHECK(in.fail());
}

TEST_CASE("WyrZsespolone test przeciazenia wczytania- wychwycenie bledu w zapisie WyrZsespolonego, brak operatora") {
    WyrazenieZesp x; 

    std::istringstream in("(3.75+1.1i)(4+9i)");
    in >> x;
    
    CHECK(in.fail());
}

TEST_CASE("WyrZsespolone test przeciazenia wczytania- wychwycenie bledu w zapisie WyrZsespolonego, bledny operator arytmetyczny") {
    WyrazenieZesp x;

    std::istringstream in("(3.75+1.1i)?(4+9i)");
    in >> x;
    
    CHECK(in.fail());
}