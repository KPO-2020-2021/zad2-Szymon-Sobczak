#include "WyrazenieZesp.hh"

/*
* OPIS: Funkcja obliczajaca wynik operacji arytmetycznej pomiedzy dwoma liczbami zespolonymi.
* PRE: Wrazenie zespolone zawierajace poprawie wprowadzone dwie liczby zespolone rozdzielone operatorem arytmetycznym. 
* POST: Wynik dzialania arytmetycznego na wyrazeniu zespolonym, bedacy liczba zespolona.
*/

LZespolona Oblicz(WyrazenieZesp  WyrZ){     
    switch(WyrZ.Op){   
        case Op_Dodaj:
            return WyrZ.Arg1 + WyrZ.Arg2;
        break;
        
        case Op_Odejmij:
            return WyrZ.Arg1 - WyrZ.Arg2;
        break;
        
        case Op_Mnoz:
            return WyrZ.Arg1 * WyrZ.Arg2;
        break;
        
        case Op_Dziel:
            return WyrZ.Arg1 / WyrZ.Arg2;
        break;
    }
}

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

/*
* OPIS: Funkcja wyswietlajaca wyrazenie zespolone na terminal.
* PRE: Wrazenie zespolone do wyswietlania.
* POST: Wyswietlenie wyrazenia zespolonego na strumieniu standardowym.
*/




/*
* OPIS: Przeciazenie operatora do wyswietlania wyrazania zespolonego. 
* PRE: Wrazenie zespolone do wyswietlania oraz strumien, na ktorym ma zostac wypisane wyrazenie.
* POST: wyswietlenie wyrazenia zespolonego na wskazanym strumieniu.
*/


ostream & operator << (ostream & StrmWy, Operator WypSym)
{
    const char ZnakOp[]="+-*/";
    return StrmWy << ZnakOp[WypSym];
}

istream & operator >> (istream & StrmWe, Operator & WczytSym)
{
    Operator TabTypOp[] = {Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel};
    const char TabSymOp[] = "+-*/", *wSymOp;
    char CzytSymOp='x';

    StrmWe >> CzytSymOp;

    if((wSymOp= strchr(TabSymOp,CzytSymOp)) ==nullptr){
        StrmWe.setstate(ios::failbit);
    }
    else {
        WczytSym = TabTypOp[wSymOp-TabSymOp];
    }
    return StrmWe;
}

ostream & operator << (ostream & StrmWy, WyrazenieZesp WyrZ){
  return StrmWy << WyrZ.Arg1 << " " << WyrZ.Op << " " << WyrZ.Arg2;
}

/*
istream & operator >> ( istream & StrmWe, WyrazenieZesp & WyrZ)
{
    StrmWe >> WyrZ.Arg1 >> WyrZ.Op >> WyrZ.Arg2;
    return StrmWe;
}
*/