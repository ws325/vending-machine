//
// Created by Wiktor Sroczyński on 17/12/2020.
//

#ifndef SROCZYNSKIWIKTOR_ETAP1_WALIDACJA_H
#define SROCZYNSKIWIKTOR_ETAP1_WALIDACJA_H
#include <string>
#include "Helper.h"

class Walidacja {
private:
    Walidacja()= default;
    ~Walidacja()= default;
public:
    Walidacja(Walidacja &other) = delete;
    void operator=(const Walidacja&) = delete;
    static int wczytajInt( int min, int max );
    static std::string sprawdzString();
    static std::string wypisz_kwote( const int kwota );
};



#endif //SROCZYNSKIWIKTOR_ETAP1_WALIDACJA_H