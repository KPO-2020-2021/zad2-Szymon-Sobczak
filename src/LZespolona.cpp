#include "LZespolona.hh"
/*
* OPIS: Funckja wykonujaca operacje sprzezania liczby zespolonej.
* PRE: Liczba zespolona, ktora zostanie poddana sprzezeniu.
* POST: Sprzezona wartosc liczby zespolonej.
*/

LZespolona LZespolona::Sprzezenie() {
  this->im*=-1;
  return *this;
}

/*
* OPIS: Funckja wykonujaca operacje sprzezania liczby zespolonej.
* PRE: Liczba zespolona, ktora zostanie poddana sprzezeniu.
* POST: Sprzezona wartosc liczby zespolonej.
*/

double LZespolona::ModulZ(){
  return sqrt(pow(this->re,2)+pow(this->im,2));
}

/*
* OPIS: Przeciazenie operatora >> do wczytywania liczby zespolonej do programu.
* PRE: Czesc rzeczywista i czesc urojona liczy zespolonej wraz ze znakiem wprowadzone w odpowiednim schemacie.
* POST: Odpowiednie przyporzdkowanie podnane wartosci do pol w strukturze liczby zespolonej.
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
* OPIS: Przeciazenie operatora <<, pozwalajace na wyswietlenie liczby zespolonej.
* PRE: Prawidlowo wprowadzona wartosc liczby zespolonej.
* POST: Wypisanie liczby zespolonej w odpowiednim fromacie na wskaznae wyjscie.
*/

ostream & operator << (ostream & StrmWy, LZespolona Lz){
  StrmWy.precision(2);
  return StrmWy << '(' << fixed  << Lz.re << showpos << Lz.im << noshowpos << 'i' << ')';
}

/*
* OPIS: Przeciazenie operatora ==, pozwalajace na porownanie dwoch liczb zespolonych.
* PRE: Prawidlowo wprowadzone liczby zespolonej do porownania.
* POST: True - gdy liczby sa sobie rowne, false - gdy liczby sa rozne.
*/

bool LZespolona::operator == (LZespolona  Skl2) const{
  if((this->re >= Skl2.re - MIN_DIFF) && (this->re <= Skl2.re + MIN_DIFF) && (this->im >= Skl2.im - MIN_DIFF) && (this->im <= Skl2.im + MIN_DIFF))
    return true;
  else 
    return false;
}

/*
* OPIS: Przeciazenie operatora +.
* PRE: Prawidlowo wprowadzone dwie liczby zespolonej, skladniki do zsumowania.
* POST: Suma 2 liczb zespolonych.
*/

LZespolona  LZespolona::operator + (LZespolona  Skl2) const
{
  Skl2.re += this->re;
  Skl2.im += this->im;
  return Skl2;
}


/*
* OPIS: Przeciazenie operatora -.
* PRE: Prawidlowo wprowadzone dwie liczby zespolonej do odjecia, odjemna i odjemnik.
* POST: Roznica 2 liczb zespolonych.
*/

LZespolona  LZespolona::operator - (LZespolona  Skl2) const
{
  LZespolona  Wynik;
  Wynik.re= this->re - Skl2.re;
  Wynik.im= this->im - Skl2.im;
  return Wynik;
}

/*
* OPIS: Przeciazenie operatora *.
* PRE: Prawidlowo wprowadzone dwie liczby zespolonej do pomnzenia, czynniki.
* POST: Iloczyn 2 liczb zespolonych.
*/
LZespolona  LZespolona::operator * (LZespolona  Skl2) const
{
  LZespolona  Wynik;
  Wynik.re = this->re*Skl2.re - this->im*Skl2.im;
  Wynik.im = this->re*Skl2.im + this->im*Skl2.re;
  return Wynik;
}

/*
* OPIS: Przeciazenie operatora /, dzielenie przez skalar.
* PRE: Prawidlowo wprowadzona liczba zespolona- dzielna oraz skalar- dzielnik.
* POST: Iloraz liczby zespolonej i skalara.
*/
LZespolona  LZespolona::operator / (double skalar) const
{ 
  LZespolona  Wynik;
  if (skalar==0){ /* Obsluga przypadku granicznego, gdy liczba zepolona zostanie podzielona przez 0 */
   throw runtime_error("Wykonano dzielenie przez 0, operacja niezdefiniowana. Konczenie pracy programu.\n");
  }
  Wynik.re= this->re/skalar; /* Dzielenie czesci rzeczywistej i urojonej przez skalar */
  Wynik.im= this->im/skalar;
  return Wynik;
}

/*
* OPIS: Przeciazenie operatora /, dzielenie dwoch liczb zespolonych.
* PRE: Prawidlowo wprowadzone dwie liczby zespolonej do podzelenia, dzielna i dzielnik.
* POST: Iloraz liczb zespolonych.
*/
LZespolona  LZespolona::operator / (LZespolona  Skl2) const
{
  LZespolona  Wynik;
  if (Skl2.ModulZ()==0){ /* Obsluga przypadku granicznego, gdy libcza zepolona zostanie podzielona przez 0+0i */
    throw runtime_error("Wykonano dzielenie przez 0+0i, operacja niezdefiniowana. Konczenie pracy programu.\n");
  }
  Wynik= (*this*Skl2.Sprzezenie())/pow(Skl2.ModulZ(),2); /* Wykonanie dzielenia dwoch liczb zespolonych */
  return Wynik;
}

