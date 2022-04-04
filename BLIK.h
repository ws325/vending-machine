//
// Created by Wiktor Sroczyński on 17/12/2020.
//

#ifndef SROCZYNSKIWIKTOR_ETAP1_BLIK_H
#define SROCZYNSKIWIKTOR_ETAP1_BLIK_H

#include "Platnosc.h"

class BLIK : public Platnosc{
public:
    explicit BLIK();
    void przedstawieniePlatnosci() override;
    bool zaplac( int cena ) override;

};


#endif //SROCZYNSKIWIKTOR_ETAP1_BLIK_H
