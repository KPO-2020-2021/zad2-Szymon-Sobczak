#include "Statystyka.hh"

void wyswietl_wynik(Wynik elem)
{
    cout << "Ilosc dobrych odpowiedzi: " << elem.zdobyte_punkty <<endl;
    cout << "Ilosc blednych odpowiedzi: " << elem.ilosc_pytan - elem.zdobyte_punkty << endl;
    cout << "Wynik procentowy poprawnych odpowiedzi: " << fixed << setprecision(1) << elem.zdobyte_punkty/elem.ilosc_pytan * 100 << "%" <<endl;
}