#include "Statystyka.hh"

/*
* OPIS: Metoda wyswietlajaca wynik testu na wyjscie standardowe.
* PRE:  Struktura zawierajaca dane o przebiegu testu.
* POST: Wyswietlenie statystyki.
*/

void wyswietl_wynik(Wynik elem){
    cout << "Ilosc dobrych odpowiedzi: " << elem.zdobyte_punkty <<endl;
    cout << "Ilosc blednych odpowiedzi: " << elem.ilosc_pytan - elem.zdobyte_punkty << endl;
    cout << "Wynik procentowy poprawnych odpowiedzi: " << elem.zdobyte_punkty/elem.ilosc_pytan * 100 << "%" <<endl;
}