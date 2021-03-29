#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "Statystyka.hh"
#include "BazaTestu.hh"

TEST_CASE("Statystyka, inicjalizajca nowej statystyki") {
    Wynik x;
    BazaTestu y;
    y.IloscPytan = 5;

    x.ustaw_statystyke(y.IloscPytan);

    CHECK((x.ilosc_pytan == 5 && x.zdobyte_punkty == 0 && x.stracone_punkty == 0));
}

TEST_CASE("Statystyka, dodawanie do licznika poprawnych odpowiedzi") {
    Wynik x;
    BazaTestu y;
    y.IloscPytan = 5;

    x.ustaw_statystyke(y.IloscPytan);

    CHECK((x.zdobyte_punkty == 0));

    x.dodaj_punkt();

    CHECK((x.zdobyte_punkty == 1));
}

TEST_CASE("Statystyka, dodawanie do licznika blednych odpowiedzi") {
    Wynik x;
    BazaTestu y;
    y.IloscPytan = 5;

    x.ustaw_statystyke(y.IloscPytan);

    CHECK((x.stracone_punkty == 0));

    x.dodaj_niepoprawna_odp();

    CHECK((x.stracone_punkty == 1));
}

TEST_CASE("Statystyka, sprawdzenie wyswietlania i obliczania  procentu wlasciwych odpowiedzi") {
    Wynik x;
    BazaTestu y;
    y.IloscPytan = 5;
    double z;

    x.ustaw_statystyke(y.IloscPytan);
    x.dodaj_punkt();
    x.dodaj_punkt();
    x.dodaj_niepoprawna_odp();
    x.dodaj_punkt();
    x.dodaj_niepoprawna_odp();

    z=x.oblicz_proc_poprawne();
    std::ostringstream out;
    out << z << "%";
    std::cout << out.str() << std::endl;
    CHECK( "60%" == out.str() );
}

TEST_CASE("Statystyka, sprawdzenie wyswietlania i obliczania procentu niewlasciwych odpowiedzi") {
    Wynik x;
    BazaTestu y;
    y.IloscPytan = 5;
    double z;

    x.ustaw_statystyke(y.IloscPytan);
    x.dodaj_punkt();
    x.dodaj_punkt();
    x.dodaj_niepoprawna_odp();
    x.dodaj_punkt();
    x.dodaj_niepoprawna_odp();

    z=x.oblicz_proc_niepoprawne();
    std::ostringstream out;
    out << z << "%";
    std::cout << out.str() << std::endl;
    CHECK( "40%" == out.str() );
}

TEST_CASE("Statystyka, sprawdzenie wyswietlania wyniku statystyki testu") {
    Wynik x;
    BazaTestu y;
    y.IloscPytan = 5;

    x.ustaw_statystyke(y.IloscPytan);
    x.dodaj_punkt();
    x.dodaj_punkt();
    x.dodaj_niepoprawna_odp();
    x.dodaj_punkt();
    x.dodaj_niepoprawna_odp();
    
    std::ostringstream out;
    out << x;
    std::cout << out.str() << std::endl;
    CHECK("Ilosc dobrych odpowiedzi: 3.00\nIlosc blednych odpowiedzi: 2.00\nWynik procentowy poprawnych odpowiedzi: 60.00%\n" == out.str());
} 