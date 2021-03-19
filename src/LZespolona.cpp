#include "LZespolona.hh"
/*
* OPIS: Funckja wykonujaca operacje sprzezania liczby zespolonej.
* PRE: Liczba zespolona, ktora zostanie poddana sprzezeniu.
* POST: Sprzezona wartosc liczby zespolonej.
*/

LZespolona Sprzezenie(LZespolona skl){
  skl.im*=-1;
  return skl;
}

/*
* OPIS: Funckja wykonujaca operacje sprzezania liczby zespolonej.
* PRE: Liczba zespolona, ktora zostanie poddana sprzezeniu.
* POST: Sprzezona wartosc liczby zespolonej.
*/

double ModulZ(LZespolona skl){
  return sqrt(pow(skl.re,2)+pow(skl.im,2));
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
  return StrmWy << '(' << Lz.re << showpos << Lz.im << noshowpos << 'i' << ')';
}

/*
* OPIS: Przeciazenie operatora ==, pozwalajace na porownanie dwoch liczb zespolonych.
* PRE: Prawidlowo wprowadzone liczby zespolonej do porownania.
* POST: True - gdy liczby sa sobie rowne, false - gdy liczby sa rozne.
*/

bool operator == (LZespolona  Skl1,  LZespolona  Skl2){
  if((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
    return true;
  else 
    return false;
}

/*
* OPIS: Przeciazenie operatora +.
* PRE: Prawidlowo wprowadzone dwie liczby zespolonej, skladniki do zsumowania.
* POST: Suma 2 liczb zespolonych.
*/

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;
  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*
* OPIS: Przeciazenie operatora -.
* PRE: Prawidlowo wprowadzone dwie liczby zespolonej do odjecia, odjemna i odjemnik.
* POST: Roznica 2 liczb zespolonych.
*/

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;
  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

/*
* OPIS: Przeciazenie operatora *.
* PRE: Prawidlowo wprowadzone dwie liczby zespolonej do pomnzenia, czynniki.
* POST: Iloczyn 2 liczb zespolonych.
*/

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;
  Wynik.re = Skl1.re*Skl2.re - Skl1.im*Skl2.im;
  Wynik.im = Skl1.re*Skl2.im + Skl1.im*Skl2.re;
  return Wynik;
}

/*
* OPIS: Przeciazenie operatora /, dzielenie przez skalar.
* PRE: Prawidlowo wprowadzona liczba zespolona- dzielna oraz skalar- dzielnik.
* POST: Iloraz liczby zespolonej i skalara.
*/

LZespolona  operator / (LZespolona  Skl,  double skalar){
  LZespolona  Wynik;
  if (skalar==0){ /* Obsluga przypadku granicznego, gdy libcza zepolona zostanie podzielona przez 0 */
   cerr << "Wykonano dzielenie przez 0, operacja niezdefiniowana. Konczenie pracy programu."<< endl; 
   exit(1);
  }
  Wynik.re= Skl.re/skalar; /* Dzielenie czesci rzeczywistej i urojonej przez skalar */
  Wynik.im= Skl.im/skalar;
  return Wynik;
}

/*
* OPIS: Przeciazenie operatora /, dzielenie dwoch liczb zespolonych.
* PRE: Prawidlowo wprowadzone dwie liczby zespolonej do podzelenia, dzielna i dzielnik.
* POST: Iloraz liczb zespolonych.
*/

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;
  if (ModulZ(Skl2)==0){ /* Obsluga przypadku granicznego, gdy libcza zepolona zostanie podzielona przez 0+0i */
   cerr << "Wykonano dzielenie przez 0+0i, operacja niezdefiniowana. Konczenie pracy programu." << endl; 
   exit(1);
  }
  Wynik= (Skl1*Sprzezenie(Skl2))/pow(ModulZ(Skl2),2); /* Wykonanie dzielenia dwoch liczb zespolonych */
  return Wynik;
}



