#include "WyrazenieZesp.hh"
/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

/*
* OPIS: Funkcja obliczajaca wynik operacji arytmetycznej pomiedzy dwoma liczbami zespolonymi.
* PRE: Wrazenie zespolone zawierajace poprawie wprowadzone dwie liczby zespolone rozdzielone operatorem arytmetycznym. 
* POST: Wynik dzialania arytmetycznego na wyrazeniu zespolonym, bedacy liczba zespolona.
*/

LZespolona WyrazenieZesp::Oblicz() const{     
    LZespolona Wynik;
    switch(this->Op){   
        case Op_Dodaj:
            Wynik = this->Arg1 + this->Arg2;
            break;
        case Op_Odejmij:
            Wynik = this->Arg1 - this->Arg2;
            break;
        case Op_Mnoz:
            Wynik = this->Arg1 * this->Arg2;
            break;
        case Op_Dziel:
            Wynik = this->Arg1 / this->Arg2;
            break;
    }
    return Wynik;
}

/*
* OPIS: Przeciazenie operatora do wyswietlania operatory arytmetyczne. 
* PRE: Wrazenie zespolone do wyswietlania oraz strumien, na ktorym ma zostac wypisane wyrazenie.
* POST: wyswietlenie wyrazenia zespolonego na wskazanym strumieniu.
*/

ostream & operator << (ostream & StrmWy, Operator & WypSym){
    const char ZnakOp[]="+-*/";
    return StrmWy << ZnakOp[WypSym];
}

istream & operator >> (istream & StrmWe, Operator & WczytSym){
    Operator TabTypOp[] = {Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel}; 
    const char TabSymOp[] = "+-*/", *wSymOp;
    char CzytSymOp='x';
    wSymOp = TabSymOp;
    StrmWe >> CzytSymOp;
    if((wSymOp= strchr(wSymOp,CzytSymOp))==nullptr){
        StrmWe.setstate(ios::failbit);
    }
    else 
        WczytSym = TabTypOp[wSymOp-TabSymOp];
    return StrmWe;
}


ifstream & operator >> (ifstream & StrmWe, Operator & WczytSym){
    Operator TabTypOp[] = {Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel}; 
    const char TabSymOp[] = "+-*/", *wSymOp;
    char CzytSymOp='x';
    wSymOp = TabSymOp;
    StrmWe >> CzytSymOp;
    if((wSymOp= strchr(wSymOp,CzytSymOp))==nullptr){
        StrmWe.setstate(ios::failbit);
    }
    else 
        WczytSym = TabTypOp[wSymOp-TabSymOp];
    return StrmWe;
}

/*
* OPIS: Przeciazenie operatora do wyswietlania wyrazania zespolonego. 
* PRE: Wrazenie zespolone do wyswietlania oraz strumien, na ktorym ma zostac wypisane wyrazenie.
* POST: wyswietlenie wyrazenia zespolonego na wskazanym strumieniu.
*/

ostream & operator << (ostream & StrmWy, WyrazenieZesp WyrZ){
  return StrmWy << WyrZ.Arg1 << " " << WyrZ.Op << " " << WyrZ.Arg2;
}

/*
* OPIS: Przeciazenie operatora >> do wczytywania wyrazenia zespolonego.
* PRE: Dwie liczby zespolone rozdzielone operatorem arytmetycznym. 
* POST: Odpowiednie przyporzdkowanie podnane wartosci do pol w strukturze wyrazenai zespolonego.
*/

istream & operator >> (istream & StrmWe, WyrazenieZesp & WyrZ){
    StrmWe >> WyrZ.Arg1 >> WyrZ.Op >> WyrZ.Arg2;
    return StrmWe;
}


ifstream & operator >> (ifstream & StrmWe, WyrazenieZesp & WyrZ){
    StrmWe >> WyrZ.Arg1 >> WyrZ.Op >> WyrZ.Arg2;
    return StrmWe;
}

