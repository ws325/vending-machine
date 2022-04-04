//
// Created by Wiktor Sroczyński on 20/11/2020.
//

#ifndef PROJEKT_1_AUTOMAT_H
#define PROJEKT_1_AUTOMAT_H

#define LICZBA_PRODUKTOW 12
#define ILOSC_SZTUK 3

#include "Polka_na_produkty.h"
#include "Baton.h"
#include "Napoj.h"
#include "Chipsy.h"
#include "Gotowka.h"
#include "Karta.h"
#include "BLIK.h"
#include <vector>

class Napoj;

class Automat final {     // final poneiwaz nic po tej kalsie nie bedie juz dziedziczyc
    int** tab_ilosci_sztuk;
    std::vector < Polka_na_produkty < Produkt* > *  > wektor_polki;
    std::vector < Platnosc* > wektor;
    int ID; //id ostatnio wybranego napoju
    int ID_y;
    int ID_x;

protected:
    int liczba_polek;
    int liczba_produktow;
    int ilosc_sztuk;

public:
    explicit Automat( int gotowka, int karta, int blik );
    ~Automat();
    void napoje_info();
    int wybierz_napoj();
    bool wybor_platnosci(const int cena );
    int sprawdz_czy_zaplacone();
    bool czy_pusty();
    friend class Platnosc;
};


#endif //PROJEKT_1_AUTOMAT_H
