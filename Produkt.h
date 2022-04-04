//
// Created by Wiktor Sroczyński on 09/01/2021.
//

#ifndef SROCZYNSKIWIKTOR_ETAP2_PRODUKT_H
#define SROCZYNSKIWIKTOR_ETAP2_PRODUKT_H
#include <string>
#include <utility>

class Produkt {
public:
    int ID;
    int cena;
    std::string nazwa;

    Produkt( int id, int _cena, std::string nazwa) : ID(id), cena(_cena), nazwa(std::move(nazwa)) {};

};


#endif //SROCZYNSKIWIKTOR_ETAP2_PRODUKT_H
