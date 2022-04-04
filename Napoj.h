//
// Created by Wiktor Sroczyński on 20/11/2020.
//

#ifndef PROJEKT_1_NAPOJ_H
#define PROJEKT_1_NAPOJ_H


#include "Produkt.h"

class Napoj : public Produkt {
public:

    Napoj( int id, int cena, const std::string& nazwa ) : Produkt( id, cena, nazwa) {};
};

//#include <string>
//#include <utility>
//#include "Automat.h"
//
//using namespace std;
//
//class Napoj {
//public:
//    int ID;
//    int cena;
//    string nazwa;
//
//
//    Napoj( int id, int cena, string nazwa) : ID(id), cena(cena), nazwa(std::move(nazwa)) {};
//
//    friend class Automat;
//};


#endif //PROJEKT_1_NAPOJ_H
