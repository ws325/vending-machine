//
// Created by Wiktor Sroczyński on 17/12/2020.
//

#include "Gotowka.h"
#include "Walidacja.h"
#include <iostream>
using namespace std;

Gotowka::Gotowka()
{
przedstawieniePlatnosci();
}

void Gotowka:: przedstawieniePlatnosci()
{
    cout << "gotowka" << endl;
}

bool Gotowka::zaplac( int cena )
{
    int kwota = cena;
    int nominal;

    cout << endl <<"Wrzuc pieniadze do automatu" << endl
         << "Przyjmowane nominaly: "<< endl
         << "| 10gr~10  |   20gr~20  |   50gr~50 |" << endl
         << "+----------+------------+-----------+" << endl
         << "|  1zl~1   |    2zl~2   |    5zl~5  | " << endl << endl;
    cout << "Kwota do zaplaty: ";
    cout << Walidacja::wypisz_kwote(cena) << endl;

    while (kwota != 0) {

        try{
            nominal = Walidacja::wczytajInt( 1, 50 );
        }
        catch (Znaki_niebedace_liczba) {
            cout << "Wpisane znaki nie sa liczba. Spruboj ponowanie wrzucic monete do automatu." << endl;
            nominal=-1;
        }
        catch (Znaki_spoza_zakresu) {
            cout << "Wpisane znaki sa spoza zakresu. Automat przyjmuje monety od 1 do 50"
                    "\nSpruboj ponowanie wrzucic monete do automatu." << endl;
            nominal=-1;
        }

        switch (nominal) {
            case 1:
            case 2:
            case 5:
                if( kwota - nominal*100 < 0 )
                {
                    cout << "Wrzuc inna monete! Kwota do zaplaty ujemna!" << endl;
                    break;
                }
                kwota -= nominal * 100;
                break;
            case 10:
            case 20:
            case 50:
                if( kwota - nominal < 0 )
                {
                    cout << "Wrzuc monete o mniejszym nominale. Kwota do zaplaty ujemna !" << endl;
                    break;
                }
                kwota -= nominal;
                break;
            default: cout << "Nie ma takiego naminalu.\n";
        }
        if( kwota != 0 )
        {
            cout << "Kwota pozostala do zplaty: ";
            cout << Walidacja::wypisz_kwote(kwota);
            cout << endl;
        }
    }

    return kwota == 0;
}




