//
// Created by Wiktor Sroczyński on 17/12/2020.
//

#ifndef SROCZYNSKIWIKTOR_ETAP1_PLATNOSC_H
#define SROCZYNSKIWIKTOR_ETAP1_PLATNOSC_H

#include "Walidacja.h"


class Platnosc {   //kalsa abstrakcyjna
public:
    explicit Platnosc() = default;   //definiuje domyslny konstruktor
    virtual ~Platnosc() = default;  //definiuje wirtualny domyslny destruktor
    virtual void przedstawieniePlatnosci() = 0;   //metoda czystko wirtualna
    virtual bool zaplac(int cena) = 0;   //metoda czystko wirtualna

    friend class Autmoat;
};


#endif //SROCZYNSKIWIKTOR_ETAP1_PLATNOSC_H
