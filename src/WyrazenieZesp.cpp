#include "WyrazenieZesp.hh"

/*
* Metoda obliczajaca wynik operacji arytmetycznej pomiedzy dwoma liczbami zespolonymi.
* Argumenty:
*   brak;
* Zwraca:
*   Wynik dzialania arytmetycznego na wyrazeniu zespolonym, bedacy liczba zespolona.
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
* Przeciazenie operatora << do wypisywania operatorow arytmetycznch na strumien typu ostream. 
* Argumenty:
*   WypSym- symbol operatora arytmetycznego do wyswietlenia.
*   StrmWy - wybrany strumien typu ostream.
* Zwraca:
*   Wypisany znak operatora arytmetycznego na wskazany strumien. 
*/

ostream & operator << (ostream & StrmWy, Operator & WypSym){
    const char ZnakOp[]="+-*/";
    return StrmWy << ZnakOp[WypSym];
}

/*
* Przeciazenie operatora >> do wczytywania operatorow arytmetycznch ze strumienia typu istream. 
* Argumenty:
*   WczytSym- symbol operatora arytmetycznego.
*   StrmWe - wybrany strumien typu istream.
* Zwraca:
*   Wczytany znak operatora arytmetycznego ze wskazanego strumienia. 
*/

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

/*
* Przeciazenie operatora >> do wczytywania operatorow arytmetycznch ze strumienia typu ifstream. 
* Argumenty:
*   WczytSym- symbol operatora arytmetycznego.
*   StrmWe - wybrany strumien typu ifstream.
* Zwraca:
*   Wczytany znak operatora arytmetycznego ze wskazanego strumienia. 
*/

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
* Przeciazenie operatora << do wypisywania wyrazen zespolonych na strumien typu ostream. 
* Argumenty:
*   WyrZ- wyrazenie zespolone do wypisania.
*   StrmWy - wybrany strumien typu ostream.
* Zwraca:
*   Wypisane wyrazenie zespolone na wskazany strumien. 
*/

ostream & operator << (ostream & StrmWy, WyrazenieZesp WyrZ){
  return StrmWy << WyrZ.Arg1 << " " << WyrZ.Op << " " << WyrZ.Arg2;
}

/*
* Przeciazenie operatora >> do wczytywania wyrazenia zespolonego ze strumienia typu istream. 
* Argumenty:
*   WyrZ- wyrazenie zespolone do wczytania.
*   StrmWe - wybrany strumien typu istream.
* Zwraca:
*   Wyczytane wyrazenie zespolone ze wskazanego strumienia. 
*/

istream & operator >> (istream & StrmWe, WyrazenieZesp & WyrZ){
    StrmWe >> WyrZ.Arg1 >> WyrZ.Op >> WyrZ.Arg2;
    return StrmWe;
}

/*
* Przeciazenie operatora >> do wczytywania wyrazenia zespolonego ze strumienia typu ifstream. 
* Argumenty:
*   WyrZ- wyrazenie zespolone do wczytania.
*   StrmWe - wybrany strumien typu ifstream.
* Zwraca:
*   Wyczytane wyrazenie zespolone ze wskazanego strumienia. 
*/

ifstream & operator >> (ifstream & StrmWe, WyrazenieZesp & WyrZ){
    StrmWe >> WyrZ.Arg1 >> WyrZ.Op >> WyrZ.Arg2;
    return StrmWe;
}

