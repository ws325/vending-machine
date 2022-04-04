//
// Created by Wiktor Sroczyński on 08/01/2021.
//

#ifndef SROCZYNSKIWIKTOR_ETAP2_POLKA_NA_PRODUKTY_H
#define SROCZYNSKIWIKTOR_ETAP2_POLKA_NA_PRODUKTY_H

#include <string>
#include <iostream>

#include "Produkt.h"
#include "Baton.h"
#include "Walidacja.h"

using namespace std;


template<typename T>
class Polka_na_produkty {
    static int liczba_polek;
    static int najdluzszy_string;
    int liczba_produktow;
    std::vector<T> wektor;
    void najdluzszaNazwa(int dlugosc);
    void wypiszPomocnicza(const int wartosc, const string &napis);

public:
    explicit Polka_na_produkty() {
        liczba_produktow = 0;
        liczba_polek++;
    };

    void dodajProdukt(T obiekt);

    int zwrocLiczbePolek() { return liczba_polek; };

    int zwrocLiczbeProduktowNaPolce() { return liczba_produktow; }

    int zwrocIDproduktu(int indeks);

    int zwrocCeneProduktu(int indeks);



    void wypisz(const int *tab);
    T zdejmijOstatniProdukt();


};

template<typename T>
int Polka_na_produkty<T>::liczba_polek = 0;

template<typename T>
int Polka_na_produkty<T>::najdluzszy_string = 11;

template<typename T>
void Polka_na_produkty<T>::dodajProdukt(T obiekt) {
    wektor.push_back(obiekt);
    najdluzszaNazwa(obiekt->nazwa.length());
    liczba_produktow += 1;
}

template<typename T>
void Polka_na_produkty<T>::wypiszPomocnicza(const int wartosc, const string &napis) {
    int temp;
    if (wartosc != 0) {
        cout << "|";
        cout << napis;
        temp = najdluzszy_string - napis.length();
        while (temp) {
            cout << " ";
            temp--;
        }
        cout << "|";
    } else {
        cout << "|";
        temp = najdluzszy_string;
        while (temp) {
            cout << " ";
            temp--;
        }
        cout << "|";
    }
}

template<typename T>
void Polka_na_produkty<T>::wypisz(const int *tab) {
    cout << "nazwa: ";
    for (int j = 0; j < liczba_produktow; j++)
        wypiszPomocnicza(tab[j], wektor[j]->nazwa);

    cout << "\ncena:  ";
    for (int j = 0; j < liczba_produktow; j++)
        wypiszPomocnicza(tab[j], Walidacja::wypisz_kwote(wektor[j]->cena));

    cout << "\nID:    ";
    for (int j = 0; j < liczba_produktow; j++)
        wypiszPomocnicza(tab[j], to_string(wektor[j]->ID));

    for (int i = 0; i < 2; ++i) {
        cout << "\n-------+";
        for (int i = 0; i < liczba_produktow; i++) {
            if (i) {
                cout << "++";
            }
            int temp = najdluzszy_string;
            while (temp--) {
                cout << "-";
            }
        }
        cout << "+";
    }
}

template<typename T>
int Polka_na_produkty<T>::zwrocIDproduktu(int indeks) {
    return wektor[indeks]->ID;
}

template<typename T>
int Polka_na_produkty<T>::zwrocCeneProduktu(int indeks) {
    return wektor[indeks]->cena;
}

template<typename T>
void Polka_na_produkty<T>::najdluzszaNazwa(int dlugosc) {
    if (dlugosc > najdluzszy_string) {
        najdluzszy_string = dlugosc;
    }
}

template<typename T>
T Polka_na_produkty<T>::zdejmijOstatniProdukt()
{
    T ret = wektor[liczba_produktow-1];
    wektor.pop_back();
    liczba_produktow-=1;
    return ret;
}


#endif //SROCZYNSKIWIKTOR_ETAP2_POLKA_NA_PRODUKTY_H
