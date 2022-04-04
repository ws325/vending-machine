//
// Created by Wiktor Sroczyński on 09/01/2021.
//

#ifndef SROCZYNSKIWIKTOR_ETAP2_BATON_H
#define SROCZYNSKIWIKTOR_ETAP2_BATON_H
#include "Produkt.h"

class Baton : public Produkt {
    public:

        Baton( int id, int cena, const std::string& nazwa ) : Produkt( id, cena, nazwa) {};
};


#endif //SROCZYNSKIWIKTOR_ETAP2_BATON_H
