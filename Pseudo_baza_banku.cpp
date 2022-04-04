//
// Created by Wiktor Sroczyński on 21/12/2020.
//

#include "Pseudo_baza_banku.h"
#include <iostream>

Pseudo_baza_banku* Pseudo_baza_banku::_instance = nullptr;
int liczba_klientow_w_bazie = 3;

Pseudo_baza_banku::Pseudo_baza_banku() {

    ptr = new klient[liczba_klientow_w_bazie];

    ptr[0].imie = "Jan";
    ptr[0].nazwisko = "Kowalski";
    ptr[0].numer_karty = "3111-1111-1111-1113";
    ptr[0].pieniadze_na_koncie = 500;
    ptr[0].PIN = "0000";

    ptr[1].imie = "Adam";
    ptr[1].nazwisko = "Nowak";
    ptr[1].numer_karty = "3111-0000-1111-1113";
    ptr[1].pieniadze_na_koncie = 350;
    ptr[1].PIN = "1111";

    ptr[2].imie = "Jakub";
    ptr[2].nazwisko = "Krawiec";
    ptr[2].numer_karty = "5555-1111-1111-1113";
    ptr[2].pieniadze_na_koncie = 150;
    ptr[2].PIN = "2222";
}


Pseudo_baza_banku *Pseudo_baza_banku::getInstance() {
    if (_instance == nullptr) {
        _instance = new Pseudo_baza_banku;
    }
    return _instance;
}

int Pseudo_baza_banku::sprawdz_dane( const std::string& numer_karty, const int cena )
{
    for( int i = 0; i < liczba_klientow_w_bazie; i++ )
    {
        if( getInstance()->ptr[i].numer_karty == numer_karty )
        {
            std::string PIN;
            int proby = 3;
            while( proby ) {
                std::cout << "Podaj 4-cyfrowy PIN do karty (pozostalo prob: " << proby << " )" << std::endl;
                getline(std::cin, PIN);
                if( getInstance()->ptr[i].PIN == PIN ) {
                    if( (getInstance()->ptr[i].pieniadze_na_koncie -= cena) >= 0 ) {
                        std::cout << "Transkacja przebiegla pomyslnie" << std::endl;
                        return 1;
                    }
                    std::cout << "Brak srodkow na koncie" << std::endl;
                    return -1;
                }
                proby--;
            }
            std::cout << "Transakcja anulowana, wpisano 3 razy bledny PIN " << std::endl;
            return -1;
        }
    }
}
