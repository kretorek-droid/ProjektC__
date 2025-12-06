#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Samochod {
private:
  string numer_rej;
  string marka;
  int rocznik;
  double spalanie_na100;
  int pojemnosc_baku;
  double licznik = 7.5;
  double stan_baku = 5;

  vector<string> karta_przegladu;



public:

  Samochod(string numer_rej_k, string marka_k, int rocznik_k, double spalanie_na100_k, int pojemnosc_baku_k) {
    cout << ">>>>>>>Utworzylem obiekt typu Samochod" << endl;
    numer_rej = numer_rej_k;
    marka = marka_k;
    rocznik = rocznik_k;
    spalanie_na100 = spalanie_na100_k;
    pojemnosc_baku = pojemnosc_baku_k;
  }

  void podajDaneSamochodu(){
    cout
    << "numer_rej" << numer_rej << endl
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
  void setNumer_rej(string numer_rej_s) {
    numer_rej = numer_rej_s;
  }

  string getNumer_rej() {
    return numer_rej;
  }

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





int main () {
  vector<Samochod> lista_samochodow;


  // lista_samochodow.push_back(Samochod("Mazda", 1986, 8.6, 56));
  // cout << lista_samochodow[0].getMarka() << endl;


  while (true) {
    cout << "======MENU======"<< endl;
    cout << "Aby dodac samochod: wybierz (1)" << endl;
    cout << "Aby wybrac samochod wybierz (2)" << endl;
    cout << "Aby zakonczyc program wybierz (3)" << endl;

    int numer_menu;
    cin >> numer_menu;


    if (numer_menu == 1) {
      cout << "Wybrano opcje 1 - dodawanie samochodu" << endl;
      string numer_rej;
      string marka;
      int rocznik;
      double spalanie;
      int poj_baku;
      cout << "Podaj nr rejestracyjny : " << endl;
      cin >> numer_rej;
      cout << "Podaj marke: " << endl;
      cin >> marka;
      cout << "Podaj rocznik: " << endl;
      cin >> rocznik;
      cout << "Podaj spalanie: " << endl;
      cin >> spalanie;
      cout << "Podaj pojemnosc baku:" << endl;
      cin >> poj_baku;
      lista_samochodow.push_back(Samochod(numer_rej, marka, rocznik, spalanie, poj_baku));

      cout << "...wracam do menu glowngo" << endl;
    }else if (numer_menu == 2) {
      string numer_rej;
      int indeks;
      cout << "Wybrano opcje 2" << endl;
      cout << "Podaj numer rejestracyjny pojazdu: " << endl;
      cin >> numer_rej;
      for (int i=0; i<lista_samochodow.size(); i++) {
        if (lista_samochodow[i].getNumer_rej() == numer_rej) {
          indeks = i;
        }
      }
      cout << "Aby jechac wybierz (1)" << endl;
      cout << "Aby tankowac wybierz (2)" << endl;
      cout << "Aby podac dane samochodu wybierz (3)" << endl;

      int numer_podmenu;
      cin >> numer_podmenu;

      if (numer_podmenu == 1) {
        cout << "Wybano 1" << endl;
      } else if (numer_podmenu == 2) {
        cout << "Wybrano 2" << endl;
      } else if (numer_podmenu == 3) {
        cout << "Wybrano 3" << endl;
      }


      // if ( indeks >= 0 && indeks <= lista_samochodow.size()-

      cout << "... wracam do menu glownego" << endl;
    }else if (numer_menu == 3) {
      cout << "wybrano opcje 3" << endl;
      cout << "... zakonczam program" << endl;
      break;
    }
  }



  return 0;
}











































