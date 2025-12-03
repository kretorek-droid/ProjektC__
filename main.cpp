#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Samochod {
private:
  string marka;
  int rocznik;
  double spalanie_na100;
  int pojemnosc_baku;
  double licznik = 7.5;
  double stan_baku = 5;

  vector<string> karta_przegladu;



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

  void dodajPrzeglad(string data_przegladu) {
    karta_przegladu.push_back(data_przegladu);
  }

  void wypiszWszystkiePrzeglady() {
    for (int i=0; i<karta_przegladu.size(); i++) {
      cout << "samochod marki " << marka << " mial przeglad : " << karta_przegladu[i] <<endl;
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

  void setSpalanie_na100(double spalanie_na100_s) {
    spalanie_na100 = spalanie_na100_s;
  }

  double getSpalanie_na100( ) {
    return spalanie_na100;
  }

  void setPojemnosc_baku(int pojemnosc_baku_s) {
    pojemnosc_baku = pojemnosc_baku_s;
  }

  int getPojemnosc_baku( ) {
    return pojemnosc_baku;
  }

  void setLicznik(double licznik_s) {
    licznik = licznik_s;
  }

  double getLicznik( ) {
    return licznik;
  }

  void setStan_baku(double stan_baku_s) {
    stan_baku = stan_baku_s;
  }

  double getStan_baku( ) {
    return stan_baku;
  }
};

 int zwracanie(vector<int>& vect, int szukana_wartosc) {
   for(int i = 0 ; i < vect.size() ; i++) {
     if (vect[i] == szukana_wartosc) {
       return i;
     }
   }
 }


int main () {

  // Samochod s1("BMW", 1995, 7.3, 40);
  // s1.dodajPrzeglad("1.12.2018");
  // s1.tankowanie(15);
  // s1.jazda(330);
  //
  // // s1.podajDaneSamochodu();
  //
  // s1.jazda(11);
  // s1.tankowanie(30);
  // s1.jazda(300);
  //
  // s1.dodajPrzeglad("3.12.2020");
  //
  // s1.wypiszWszystkiePrzeglady();

  vector<int> liczby = {232,4545,4522,831,25,72,257,2311};


   cout << zwracanie(liczby , 257);


  return 0;
}

// pOBIERZ  Z KLAWIATURY 3 NEIUJEMNE LOICBZY CAKOWEITE. ZNAJDŹ NAJWIĘKSZĄ Z NICH. WYŚWIETL SUMĘ PZOOSTAŁYCH LICZB TYLE RAZY ILE WYNOSI WARTOŚĆ NAJWIĘKSZEJ LICZBY