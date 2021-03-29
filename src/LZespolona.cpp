#include "LZespolona.hh"

/*
* Metoda wykonujaca operacje sprzezania liczby zespolonej.
* Argumenty:
*   brak.
* Zwraca:
*   Sprzezona liczba zespolona.
*/

LZespolona LZespolona::Sprzezenie(){
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
* Przeciazenie operatora >> do wczytywania liczby zespolonej do programu ze strumienia typu istream.
* Argumenty:
*   Lz- Liczba zespolona, do ktorej zostanie przypisana wczytana liczba.
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
* Przeciazenie operatora >> do wczytywania liczby zespolonej do programu ze strumienia typu ifstream.
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
*   Lz- liczba zespolona do wyswietlenia.
*   StrmWy - wybrany strumien typu ostream.
* Zwraca:
*   Wypisana liczba zespolona w odpowiednim fromacie na wskazane wyjscie.
*/

ostream & operator << (ostream & StrmWy, LZespolona Lz){
  StrmWy.precision(2); /* Ustawienie dokladnosci wyswietlania liczbyt zmiennoprzecinkowej do dwoch miejsc po przecinku */
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
*   Suma dwoch liczb zespolonych bedaca liczba zespolona. 
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
*   Roznica dwoch liczb zespolonych bedaca liczba zespolona.
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
*   Iloczyn dwoch liczb zespolonych bedacy liczba zespolona.
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
*   Iloraz liczby zespolonej i skalara bedacy liczba zespolona.
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
*   Iloraz dwoch liczb zespolonych.
*/

LZespolona  LZespolona::operator / (LZespolona  Skl2) const{
  LZespolona  Wynik;
  if (Skl2.ModulZ()==0){ /* Obsluga przypadku granicznego, gdy libcza zepolona zostanie podzielona przez 0+0i */
    throw runtime_error("Wykonano dzielenie przez 0+0i, operacja niezdefiniowana. Konczenie pracy programu.\n");
  }
  Wynik= (*this*Skl2.Sprzezenie())/pow(Skl2.ModulZ(),2); /* Wykonanie dzielenia dwoch liczb zespolonych */
  return Wynik;
}

/*
* Funkcja wyznaczajaca Arg. glowny liczby zespolonej.
* Argumenty:
*   z - liczba zespolona z ktorej ma zostac wyznaczony i  wypisany Arg. glowny.
* Zwraca:
*   Argument glowny liczby zespolonej bedacy typu double
*/

double arg(LZespolona z)
{
  double kat;
  if (z.re==0){
    if(z.im > 0)
      kat = 0.5 * M_PI;
    if(z.im < 0)
      kat = -0.5 * M_PI;
    if(z.im == 0) /* Dla Re = 0 i Im = 0 Arg. jest niezdefiniowany */ 
      throw runtime_error("Arg. jest niezdefiniowany");
  }
  else{
    if(z.re > 0)
      kat = atan2(z.im, z.re);
    if(z.re < 0)
      kat = atan2(z.im, z.re) + M_PI;
  }
  return kat;
}

/*
* Przeciazenie operatora +=, pozwalajace na obliczenie sumy dwoch liczb zespolonych i przypisanie wyniku do 1 skladnika sumy.
* Argumenty:
*   Arg1- pierwszy skladnik dodawania.
*   Arg2 - drugi skladnik dodawania.
* Zwraca:
*   Liczbe zespolona bedaca suma dwoch skladnikow.
*/

LZespolona  operator += (LZespolona  & Arg1,LZespolona const & Arg2){
  return Arg1 = Arg1 + Arg2;
}

/*
* Przeciazenie operatora /=, pozwalajace na obliczenie ilraozu liczb zespolonych i przypisanie wyniku do licznika.
* Argumenty:
*   Arg1- licznik.
*   Arg2 - mianownik.
* Zwraca:
*   Liczbe zespolona bedaca ilorazem dwoch liczb zespolonych.
*/

LZespolona  operator /= (LZespolona  & Arg1,LZespolona const & Arg2){
  return Arg1 = Arg1 / Arg2;
}