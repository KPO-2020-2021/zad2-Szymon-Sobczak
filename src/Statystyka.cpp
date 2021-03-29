#include "Statystyka.hh"

/*
* Metoda inicjalizujaca statystyke.
* Argumenty:
*   dlugosc- ilosc pytan w tescie.
* Zwraca:
*   brak;
*/

void Wynik::ustaw_statystyke(unsigned int dlugosc){
    this->ilosc_pytan= dlugosc;
    this->zdobyte_punkty=0;
    this->stracone_punkty=0;
}
    
/*
* Metoda iterujaca ilosc zdobytych punktow w tescie.
* Argumenty:
*   brak;
* Zwraca:
*   brak;
*/  

void Wynik::dodaj_punkt(){
    this->zdobyte_punkty++;
}

/*
* Metoda iterujaca ilosc straconych punktow w tescie.
* Argumenty:
*   brak;
* Zwraca:
*   brak;
*/  

void Wynik::dodaj_niepoprawna_odp(){
    this->stracone_punkty++;
}

/*
* Metoda obliczjaca wartosc procentowa uzysktanych w tescie poprawynch odpowiedzi.
* Argumenty:
*   brak;
* Zwraca:
*   Wartosc procentowa usyskanych w tescie poprawnych odpowiedzi. 
*/  

double Wynik::oblicz_proc_poprawne(){
    return this->zdobyte_punkty/this->ilosc_pytan * 100;
}

/*
* Metoda obliczjaca wartosc procentowa uzysktanych w tescie niepoprawnych odpowiedzi.
* Argumenty:
*   brak;
* Zwraca:
*   Wartosc procentowa usyskanych w tescie niepoprawnychodpowiedzi. 
*/  

double Wynik::oblicz_proc_niepoprawne(){
    return this->stracone_punkty/this->ilosc_pytan * 100;
}

/*
* Przeciazenie operatora <<, pozwalajace na wypisanie statystyki na strumien typu ostream.
* Argumenty:
*   Wynik - Statystyka do wyswietlania.
*   StrmWy - wybrany strumien typu ostream.
* Zwraca:
*   Wypisane na wybrany strumien wyniki ze statystyki. 
*/ 

ostream & operator << (ostream & StrmWy, Wynik Wynik){
   StrmWy.precision(2);
    StrmWy << "Ilosc dobrych odpowiedzi: " << fixed << Wynik.zdobyte_punkty <<endl;
    StrmWy << "Ilosc blednych odpowiedzi: " << fixed  << Wynik.stracone_punkty << endl;
    StrmWy << "Wynik procentowy poprawnych odpowiedzi: " << fixed  << Wynik.oblicz_proc_poprawne() << "%" <<endl;
    return StrmWy; 
}