//
// Created by Wiktor Sroczyński on 17/12/2020.
//

#ifndef SROCZYNSKIWIKTOR_ETAP1_KARTA_H
#define SROCZYNSKIWIKTOR_ETAP1_KARTA_H
#include "Platnosc.h"
#include "Pseudo_baza_banku.h"

class Karta : public Platnosc{
public:
    explicit Karta();
    void przedstawieniePlatnosci() override;
    bool zaplac( int cena ) override;
};

#endif //SROCZYNSKIWIKTOR_ETAP1_KARTA_H
