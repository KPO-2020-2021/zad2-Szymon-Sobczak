#include "LZespolona.hh"

/*
* Metoda wykonujaca operacje sprzezania liczby zespolonej.
* Argumenty:
*   brak.
* Zwraca:
*   Sprzezona liczba zespolona.
*/

LZespolona LZespolona::Sprzezenie() {
  this->im*=-1;
  return *this;
}

/*
* Metoda wyznaczajaca modul z liczby zespolonej.
* Argumenty:
*   brak.
* Zwraca:
*   Modul z liczby zespolonej.
*/

double LZespolona::ModulZ(){
  return sqrt(pow(this->re,2)+pow(this->im,2));
}

/*
* Przeciazenie operatora >> do wczytywania liczby zespolonej do programu ze strumienia klasy istream.
* Argumenty:
*   Lz- Liczba zespolona, do ktorej zostanie przypisana zwracana wartosc.
*   StrmWy - wybrany strumien typu istream.
* Zwraca:
*   Wczytany obiekt- Liczba zespolona.
*/

istream & operator >> (istream & StrmWe, LZespolona & Ln){
  char Nawias, Litera; 
  StrmWe >> Nawias;
  if(StrmWe.fail()){
    return StrmWe;
  }
  if (Nawias != '('){
    StrmWe.setstate(ios::failbit);
    return StrmWe;
  }
  StrmWe >> Ln.re;
  if(StrmWe.fail()){
    return StrmWe;
  }
  StrmWe >> Ln.im;
  if(StrmWe.fail()){
    return StrmWe;
  }
  StrmWe >> Litera;
  if(StrmWe.fail()){
      return StrmWe;
  }
  if (Litera != 'i'){
    StrmWe.setstate(ios::failbit);
    return StrmWe;
  }
  StrmWe >> Nawias;
  if (Nawias != ')'){
    StrmWe.setstate(ios::failbit);
    return StrmWe;
  }
  return StrmWe;
}

/*
* Przeciazenie operatora >> do wczytywania liczby zespolonej do programu ze strumienia klasy ifstream.
* Argumenty:
*   Lz- Liczba zespolona, do ktorej zostanie przypisana zwracana wartosc.
*   StrmWy - wybrany strumien typu ifstream.
* Zwraca:
*   Wczytany obiekt- Liczba zespolona.
*/

ifstream & operator >> (ifstream & StrmWe, LZespolona & Ln){
  char Nawias, Litera; 
  StrmWe >> Nawias;
  if(StrmWe.fail()){
    return StrmWe;
  }
  if (Nawias != '('){
    StrmWe.setstate(ios::failbit);
    return StrmWe;
  }
  StrmWe >> Ln.re;
  if(StrmWe.fail()){
    return StrmWe;
  }
  StrmWe >> Ln.im;
  if(StrmWe.fail()){
    return StrmWe;
  }
  StrmWe >> Litera;
  if(StrmWe.fail()){
      return StrmWe;
  }
  if (Litera != 'i'){
    StrmWe.setstate(ios::failbit);
    return StrmWe;
  }
  StrmWe >> Nawias;
  if (Nawias != ')'){
    StrmWe.setstate(ios::failbit);
    return StrmWe;
  }
  return StrmWe;
}

/*
* Przeciazenie operatora <<, pozwalajace na wypisanie liczby zespolonej na strumien typu ostream.
* Argumenty:
*   Lz- Prawidlowo wprowadzona wartosc liczby zespolonej.
*   StrmWy - wybrany strumien typu ostream.
* Zwraca:
*   Wypisana liczba zespolona w odpowiednim fromacie na wskaznae wyjscie.
*/

ostream & operator << (ostream & StrmWy, LZespolona Lz){
  StrmWy.precision(2);
  return StrmWy << '(' << fixed  << Lz.re << showpos << Lz.im << noshowpos << 'i' << ')';
}

/*
* Metoda przeciazenia operatora ==, pozwalajaca na porownanie dwoch liczb zespolonych z uwzglednieniem bledu zaokraglenia.
* Argumenty:
*   Skl2 - Prawidlowo wprowadzona liczba zespolona do porownania.
* Zwraca:
*   True - gdy liczby sa sobie rowne w zakresie minimalnego bledu, 
*   False - gdy liczby sa rozne.
*/

bool LZespolona::operator == (LZespolona  Skl2) const{
  if((this->re >= Skl2.re - MIN_DIFF) && (this->re <= Skl2.re + MIN_DIFF) && (this->im >= Skl2.im - MIN_DIFF) && (this->im <= Skl2.im + MIN_DIFF))
    return true;
  else 
    return false;
}

/*
* Metoda przeciazenia operatora +.
* Argumenty:
*   Skl2 - drugi skladnik do zsumowania.
* Zwraca:
*   Suma dwoch liczb zespolonych.
*/

LZespolona  LZespolona::operator + (LZespolona  Skl2) const{
  Skl2.re += this->re;
  Skl2.im += this->im;
  return Skl2;
}

/*
* Metoda przeciazenia operatora -.
* Argumenty:
*   Skl2 - odjemnik.
* Zwraca:
*   Roznica dwoch liczb zespolonych.
*/

LZespolona  LZespolona::operator - (LZespolona  Skl2) const{
  LZespolona  Wynik;
  Wynik.re= this->re - Skl2.re;
  Wynik.im= this->im - Skl2.im;
  return Wynik;
}

/*
* Metoda przeciazenia operatora -.
* Argumenty:
*   Skl2 - drugi czynnik do pomnozenia.
* Zwraca:
*   Iloczyn dwoch liczb zespolonych.
*/

LZespolona  LZespolona::operator * (LZespolona  Skl2) const{
  LZespolona  Wynik;
  Wynik.re = this->re*Skl2.re - this->im*Skl2.im;
  Wynik.im = this->re*Skl2.im + this->im*Skl2.re;
  return Wynik;
}

/*
* Metoda przeciazenia operatora /, dzielenie przez skalar.
* Argumenty:
*   skalar - skalar przez ktory zostanie podzielona liczba zespolona.
* Warunki wstepne:
*   - skalar nie moze byc 0.
* Zwraca:
*   Iloraz liczby zespolonej i skalara.
*/

LZespolona  LZespolona::operator / (double skalar) const{ 
  LZespolona  Wynik;
  if (skalar==0){ /* Obsluga przypadku granicznego, gdy liczba zepolona zostanie podzielona przez 0 */
   throw runtime_error("Wykonano dzielenie przez 0, operacja niezdefiniowana. Konczenie pracy programu.\n");
  }
  Wynik.re= this->re/skalar; /* Dzielenie czesci rzeczywistej i urojonej przez skalar */
  Wynik.im= this->im/skalar;
  return Wynik;
}

/*
* Metoda przeciazenia operatora /, dzielenie dwoch liczb zespolonych.
* Argumenty:
*   Skl2 - dzielnik.
* Warunki wstepne:
*   - Skl2 nie moze byc 0+0i.
* Zwraca:
*   Iloraz liczb zespolonych.
*/

LZespolona  LZespolona::operator / (LZespolona  Skl2) const{
  LZespolona  Wynik;
  if (Skl2.ModulZ()==0){ /* Obsluga przypadku granicznego, gdy libcza zepolona zostanie podzielona przez 0+0i */
    throw runtime_error("Wykonano dzielenie przez 0+0i, operacja niezdefiniowana. Konczenie pracy programu.\n");
  }
  Wynik= (*this*Skl2.Sprzezenie())/pow(Skl2.ModulZ(),2); /* Wykonanie dzielenia dwoch liczb zespolonych */
  return Wynik;
}

