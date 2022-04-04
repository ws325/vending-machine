//
// Created by Wiktor Sroczyński on 17/12/2020.
//

#include "Karta.h"
#include <iostream>
using namespace std;

Karta::Karta()
{
    przedstawieniePlatnosci();
}

void Karta::przedstawieniePlatnosci()
{
    cout << "karta" << endl;
}

bool Karta:: zaplac( int cena )
{
    string napis;
    string decyzja = "y";

    while( decyzja == "y" ) {
        cout << "Wpisz numer karty ( XXXX-XXXX-XXXX-XXXX ) :" << endl;
        std::getline(std::cin, napis);
        cout << "Laczenie z bankiem ..." << endl;
        int wynik_operacji = Pseudo_baza_banku::sprawdz_dane( napis, cena );
        if( wynik_operacji == 1 ) return true;
        else if ( wynik_operacji == -1 ) return false;
        cout << "Bledny numer karty. Wcisnij y, aby sprobowac jeszcze raz lub n, aby anulowac zakup " << endl;
        decyzja = Walidacja::sprawdzString();
        if( decyzja == "n" ) return false;
        }
}

