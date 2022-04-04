//
// Created by Wiktor Sroczyński on 17/12/2020.
//

#ifndef SROCZYNSKIWIKTOR_ETAP1_GOTOWKA_H
#define SROCZYNSKIWIKTOR_ETAP1_GOTOWKA_H
#include "Platnosc.h"


class Gotowka : public Platnosc{
public:
     explicit Gotowka();
     void przedstawieniePlatnosci() override;
     bool zaplac( int cena ) override;
     //korzytsam z destruktorow domyslnych
};


#endif //SROCZYNSKIWIKTOR_ETAP1_GOTOWKA_H
