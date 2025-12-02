#include <iostream>
#include <string>
using namespace std;

class Samochod {
private:
  string marka;
  int rocznik;
  double spalanie_na100;
  int pojemnosc_baku;
  double licznik = 7.5;
  double stan_baku = 5;

public:

  Samochod(string marka_k, int rocznik_k, double spalanie_na100_k, int pojemnosc_baku_k) {
    cout << "Utworzylem obiekt typu Samochod" << endl;
    marka = marka_k;
    rocznik = rocznik_k;
    spalanie_na100 = spalanie_na100_k;
    pojemnosc_baku = pojemnosc_baku_k;
  }

  void podajDaneSamochodu(){
    cout
    << "marka: " << marka << endl
    << "rocznik: " << rocznik << endl
    << "spalanie na 100: " << spalanie_na100 << endl
    << "pojemnosc baku: " << pojemnosc_baku << endl
    << "na liczniku: " << licznik << endl
    << "paliwa w baku: " << stan_baku << endl;
  }

  void tankowanie(double tankowane_paliwo) {
    double bak_przed_tankowaniem = stan_baku;
    stan_baku += tankowane_paliwo;

    if (stan_baku > pojemnosc_baku) {
      stan_baku = pojemnosc_baku;
    }
    cout << "Stan baku po zatankowaniu:" << stan_baku << endl;
    cout << "Zatankowane paliwo:" << stan_baku - bak_przed_tankowaniem << endl;

  }

  void jazda(double ilosc_km) {
    if(stan_baku <= 0) {
      cout << "Brak paliwa, nie pojedziesz" << endl;
    }else {
      double maksymalny_dystans = (stan_baku * 100)/spalanie_na100;
      // cout << "maksymalny dystans: " << maksymalny_dystans;

      if (ilosc_km >= maksymalny_dystans) {
        licznik += maksymalny_dystans;
        stan_baku = 0;
        cout << "Samochod stanal, brak paliwa " << endl;
        cout << "Przejechano tyle kilometrow " << maksymalny_dystans << endl;
      } else {
        licznik += ilosc_km;
        stan_baku -= ilosc_km*spalanie_na100/100;

        cout << "aktualny stan baku:" << stan_baku << endl;
        cout << "Przejechano tyle kilometrow" << ilosc_km << endl;

      }
    }

  }






  //-----------------------GET'ery i SEt'ery
  void setMarka(string marka_s) {
    marka = marka_s;
  }

  string getMarka() {
    return marka;
  }

  void setRocznik(int rocznik_s) {
    rocznik = rocznik_s;
  }

  int getRocznik() {
    return rocznik;
  }


};



int main () {

  Samochod s1("BMW", 1995, 7.3, 40);
  s1.tankowanie(15);
  s1.jazda(330);

  // s1.podajDaneSamochodu();

  s1.jazda(11);
  s1.tankowanie(30);
  s1.jazda(300);

  return 0;
}

// pOBIERZ  Z KLAWIATURY 3 NEIUJEMNE LOICBZY CAKOWEITE. ZNAJDŹ NAJWIĘKSZĄ Z NICH. WYŚWIETL SUMĘ PZOOSTAŁYCH LICZB TYLE RAZY ILE WYNOSI WARTOŚĆ NAJWIĘKSZEJ LICZBY