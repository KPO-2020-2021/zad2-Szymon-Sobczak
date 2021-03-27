#include "Statystyka.hh"

/*
* OPIS: Metoda wyswietlajaca wynik testu na wyjscie standardowe.
* PRE:  Struktura zawierajaca dane o przebiegu testu.
* POST: Wyswietlenie statystyki.
*/

void Wynik::ustaw_statystyke(BazaTestu BazaT){
    this->ilosc_pytan= BazaT.IloscPytan;
    this->zdobyte_punkty=0;
    this->stracone_punkty=0;
}
    
void Wynik::dodaj_punkt(){
    this->zdobyte_punkty+=1;
}

void Wynik::dodaj_niepoprawna_odp(){
    this->stracone_punkty+=1;
}

double Wynik::oblicz_proc_poprawne(){
    return this->zdobyte_punkty/this->ilosc_pytan * 100;
}

double Wynik::oblicz_proc_niepoprawne(){
    return this->stracone_punkty/this->ilosc_pytan * 100;
}
/*
void Wynik::wyswietl_wynik() {
    cout.precision(2);
    cout << "Ilosc dobrych odpowiedzi: " << fixed << this->zdobyte_punkty <<endl;
    cout << "Ilosc blednych odpowiedzi: " << fixed  << this->stracone_punkty << endl;
    cout << "Wynik procentowy poprawnych odpowiedzi: " << fixed  << this->oblicz_proc_poprawne() << "%" <<endl;
}
*/
ostream & operator << (ostream & StrmWy, Wynik Wynik){
   StrmWy.precision(2);
   //cout << "Ilosc dobrych odpowiedzi: " << fixed << Wynik.zdobyte_punkty << "\nIlosc blednych odpowiedzi: " << fixed  << Wynik.stracone_punkty << "\nWynik procentowy poprawnych odpowiedzi: " << fixed  << Wynik.oblicz_proc_poprawne() << "%\n" ;
    StrmWy << "Ilosc dobrych odpowiedzi: " << fixed << Wynik.zdobyte_punkty <<endl;
    StrmWy << "Ilosc blednych odpowiedzi: " << fixed  << Wynik.stracone_punkty << endl;
    StrmWy << "Wynik procentowy poprawnych odpowiedzi: " << fixed  << Wynik.oblicz_proc_poprawne() << "%" <<endl;
    return StrmWy;
}