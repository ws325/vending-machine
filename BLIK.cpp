//
// Created by Wiktor Sroczyński on 17/12/2020.
//
#include "BLIK.h"
#include <time.h>
#include <cstdlib>
#include <iostream>
using namespace std;


BLIK::BLIK()
{
    przedstawieniePlatnosci();
}



void BLIK::przedstawieniePlatnosci()
{
    cout << "blik" << endl;
}



bool BLIK::zaplac( int cena )
{
    char kodBLIK[6];
    srand( time( NULL ) );

    for(char & i : kodBLIK)
    {
        i = rand()%10 + '0';
        cout << i;
    }
    cout << endl << "Wpisz wyswietlony powyzej kod BLIK, aby zakonczyc transakcje:" << endl ;
    string napis;
    std::getline(std::cin, napis );
    for( int i = 0; i < napis.length(); i++)
    {
        if ( kodBLIK[i] != napis[i] )
        {
            cout << "Transakcja sie nie powiodla" << endl;
            return false;
        }

    }
    cout << "Transakcja sie powiodla" << endl;
    return true;
}