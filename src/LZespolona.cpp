#include "LZespolona.hh"

/*
* OPIS: Funkcja wyswietlajaca liczbe zespolona na terminal.
* PRE: Liczba zespolona do wyświetlania.
* POST: Wynik dzialania arytmetycznego na wyrazeniu zespolonym, bedacy liczba zespolona.
*/

void Wyswietl(LZespolona skl){
    cout << "(" << skl.re << showpos << skl.im << noshowpos  << "i)";
}


LZespolona Sprzezenie(LZespolona skl)
{
  skl.im*=-1;
  return skl;
}

double ModulZ(LZespolona skl)
{
  return sqrt(pow(skl.re,2)+pow(skl.im,2));
}

/*
* OPIS: Przeciazenie operatorw do wczytywania liczby zespolonej do programu.
* PRE: Czesc rzeczywista i czesc urojona liczy zespolonej wraz ze znakiem wprowadzone w odpowiednim schemacie.
* POST: Odpowiednie przyporzdkowanie podnaych wartosci do pol w strukturze liczby zespolonej.
*/

istream & operator >> (istream & StrmWe, LZespolona & Ln)
{
  if (StrmWe.fail())
    return StrmWe;

  if(StrmWe.get()!='('){
    StrmWe.setstate(StrmWe.failbit);
     return StrmWe;
  }
  
  StrmWe  >> Ln.re; 
  if (StrmWe.fail())
    return StrmWe;

  StrmWe >> Ln.im;
  if (StrmWe.fail())
    return StrmWe;

  if(StrmWe.get()!='i'){
    StrmWe.setstate(StrmWe.failbit);
     return StrmWe;
  }
    
  if(StrmWe.get()!=')'){
    StrmWe.setstate(StrmWe.failbit);
    return StrmWe;
  }
    
  StrmWe.ignore(); // pominiecie znaku enter
  return StrmWe;
}

ostream & operator << (ostream & StrmWy, LZespolona Lz){
  return StrmWy << '(' << Lz.re << showpos << Lz.im << noshowpos << 'i' << ')';
}

bool operator == (LZespolona  Skl1,  LZespolona  Skl2){
  if((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im)){
    return true;
  }
  else 
    return false;
}

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  Wynik.re = Skl1.re*Skl2.re - Skl1.im*Skl2.im;
  Wynik.im = Skl1.re*Skl2.im + Skl1.im*Skl2.re;
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl,  double skalar)
{
  LZespolona  Wynik;
  if (skalar==0){
   cerr << "Wykonano dzielenie przez 0, operacja niezdefiniowana. Konczenie pracy programu."<< endl; 
   exit(1);
  }
  Wynik.re= Skl.re/skalar;
  Wynik.im= Skl.im/skalar;
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  if (ModulZ(Skl2)==0){
   cerr << "Wykonano dzielenie przez 0+0i, operacja niezdefiniowana. Konczenie pracy programu." << endl; 
   exit(1);
  }
  Wynik= (Skl1*Sprzezenie(Skl2))/pow(ModulZ(Skl2),2);
  return Wynik;
}



