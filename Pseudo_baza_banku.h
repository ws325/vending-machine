//
// Created by Wiktor Sroczyński on 21/12/2020.
//

#ifndef SROCZYNSKIWIKTOR_ETAP1_PSEUDO_BAZA_BANKU_H
#define SROCZYNSKIWIKTOR_ETAP1_PSEUDO_BAZA_BANKU_H

#include <iostream>
#include <string>

class Pseudo_baza_banku {

    struct klient {
        std::string imie;
        std::string nazwisko;
        std::string numer_karty;
        int pieniadze_na_koncie;
        std::string PIN;
    };

    klient *ptr;

protected:
    Pseudo_baza_banku();
    ~Pseudo_baza_banku() { delete [] ptr; delete _instance; };
    static Pseudo_baza_banku *_instance;

public:
    Pseudo_baza_banku(Pseudo_baza_banku &other) = delete;
    void operator=(const Pseudo_baza_banku &) = delete;
    static Pseudo_baza_banku *getInstance();
    static int sprawdz_dane( const std::string& numer_karty, const int cena);

};


#endif //SROCZYNSKIWIKTOR_ETAP1_PSEUDO_BAZA_BANKU_H
