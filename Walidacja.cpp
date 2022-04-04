//
// Created by Wiktor Sroczyński on 17/12/2020.
//

#include "Walidacja.h"
#include <iostream>
using namespace std;

int Walidacja::wczytajInt( int min, int max ) {
    string ciag_znakow;
    int liczba;

            std::getline(std::cin, ciag_znakow);
            bool valid = true;
            for (int i = 0; i < ciag_znakow.length(); i++) {
                if (ciag_znakow[i] < '0' || ciag_znakow[i] > '9') {
                    Znaki_niebedace_liczba znakiNiebedaceLiczba;
                    throw znakiNiebedaceLiczba;
                }
            }
            liczba = atoi(ciag_znakow.c_str());
            if (liczba >= min && liczba <= max) return liczba;
            Znaki_spoza_zakresu znakiSpozaZakresu;
            throw znakiSpozaZakresu;
}

string Walidacja::sprawdzString() {
        string decision;
    do {
        std::getline(std::cin, decision);
        if (decision == "y" || decision == "n") return decision;
        cout << "Wpisano bledne znaki, sprobuj jeszcze raz wybierajac znak y lub n" << endl;
    }while( decision != "y" || decision!="n" );

}

std::string Walidacja::wypisz_kwote( const int kwota )
{
    return to_string( kwota / 100 ) + " zl " + to_string( kwota % 100 ) + " gr";
}