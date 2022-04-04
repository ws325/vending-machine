//
// Created by Wiktor Sroczyński on 09/01/2021.
//

#ifndef SROCZYNSKIWIKTOR_ETAP2_CHIPSY_H
#define SROCZYNSKIWIKTOR_ETAP2_CHIPSY_H

#include <string>
#include <utility>
#include "Automat.h"

using namespace std;

class Chipsy : public Produkt {
public:
    int ID;
    int cena;
    string nazwa;


    Chipsy( int id, int cena, string nazwa) : Produkt( id, cena, nazwa) {};

    friend class Automat;
};

#endif //SROCZYNSKIWIKTOR_ETAP2_CHIPSY_H
