//
// Created by Wiktor Sroczyński on 20/11/2020.
//

#include "Automat.h"
#include <iostream>

using namespace std;

Automat::Automat(int gotowka, int karta,
                 int blik) {   //tworzac obiekt klasy automat i wywolujac konstruktor decydujemy jakie metody platnosci bedie posiadal automat

    wektor_polki.push_back(new Polka_na_produkty<Produkt *>);
    wektor_polki[0]->dodajProdukt(new Napoj(0, 610, "Coca-cola"));
    wektor_polki[0]->dodajProdukt(new Napoj(1, 370, "Fanta"));
    wektor_polki[0]->dodajProdukt(new Napoj(2, 200, "Woda niegazowana"));
    wektor_polki[0]->dodajProdukt(new Napoj(3, 1000, "Red Bull"));

    wektor_polki.push_back(new Polka_na_produkty<Produkt *>);
    wektor_polki[1]->dodajProdukt(new Baton(4, 250, "Mars"));
    wektor_polki[1]->dodajProdukt(new Baton(5, 340, "Bounty"));
    wektor_polki[1]->dodajProdukt(new Baton(6, 300, "Twix"));
    wektor_polki[1]->dodajProdukt(new Baton(7, 500, "Snickers"));

    wektor_polki.push_back(new Polka_na_produkty<Produkt *>);
    wektor_polki[2]->dodajProdukt(new Chipsy(9, 250, "Zielona cebulka"));
    wektor_polki[2]->dodajProdukt(new Chipsy(10, 340, "Papryka"));
    wektor_polki[2]->dodajProdukt(new Chipsy(11, 300, "Solone"));
    wektor_polki[2]->dodajProdukt(new Chipsy(12, 500, "Fromage"));

    liczba_polek = wektor_polki[0]->zwrocLiczbePolek();
    liczba_produktow = LICZBA_PRODUKTOW;
    ilosc_sztuk = ILOSC_SZTUK;


    tab_ilosci_sztuk = new int *[liczba_polek];

    for (int i = 0; i < liczba_polek; i++) {
        int temp = wektor_polki[i]->zwrocLiczbeProduktowNaPolce();
        tab_ilosci_sztuk[i] = new int[temp];
        for (int j = 0; j < temp; j++) {
            tab_ilosci_sztuk[i][j] = ilosc_sztuk;
        }
    }

    cout << "Dostepne sposoby platnosci w automacie: " << endl;
    if (gotowka) {
        cout << " | ";
        wektor.push_back(new Gotowka);
    }
    if (karta) {
        cout << " | ";
        wektor.push_back(new Karta);
    }
    if (blik) {
        cout << " | ";
        wektor.push_back(new BLIK);
    }
}


int Automat::wybierz_napoj() {

    while (1) {
        cout << "Wybierz napoj podajac ID: " << endl;
        try {
            ID = Walidacja::wczytajInt(0, liczba_produktow);
        }
        catch (Znaki_niebedace_liczba) {
            cout << "Wpisane znaki nie sa liczba. Spruboj ponowanie wpisac ID." << endl;
            ID = -1;
        }
        catch (Znaki_spoza_zakresu) {
            cout << "Wpisane znaki sa spoza zakresu. W automacie ID jest z zakresu od 0 do " << liczba_produktow <<
                 ".\nSpruboj ponowanie wybrac inny napoj." << endl;
            ID = -1;
        }

        for (int i = 0; i < this->liczba_polek; i++) {
            for (int j = 0; j < wektor_polki[i]->zwrocLiczbeProduktowNaPolce(); j++)
                if (wektor_polki[i]->zwrocIDproduktu(j) == ID) {
                    if (tab_ilosci_sztuk[i][j] != 0) {
                        ID_y = i;
                        ID_x = j;
                        return wektor_polki[i]->zwrocCeneProduktu(j);
                    }
                    cout << endl << "Brak wybranego produktu. Wybierz inny napoj" << endl << endl;
                    napoje_info();
                }
        }
    }
}

bool Automat::wybor_platnosci(const int cena) {

    cout << "Wybierz sposob platnosci wybierajac odpowiednia liczbe" << endl;
    for (int i = 0; i < wektor.size(); i++) {
        cout << i << ". ";
        wektor[i]->przedstawieniePlatnosci();
    }

    int wybor;

    while (1) {
        try {
            wybor = Walidacja::wczytajInt(0, wektor.size() - 1);
            return wektor[wybor]->zaplac(cena);
        }
        catch (Znaki_niebedace_liczba) {
            cout << "Wpisane znaki nie sa liczba.\nSpruboj ponowanie wybrac sposob platnosci." << endl;
            wybor = -1;
        }
        catch (Znaki_spoza_zakresu) {
            cout << "Wpisane znaki sa spoza zakresu.\nSpruboj ponowanie wybrac sposob platnosci." << endl;
            wybor = -1;
        }
    }
}

int Automat::sprawdz_czy_zaplacone() {

    if (wybor_platnosci(wybierz_napoj())) {
        tab_ilosci_sztuk[ID_y][ID_x] -= 1;
        return 1;
    }
    cout << "Zakup nie zostal zrealizowany" << endl;
    return 0;
}


void Automat::napoje_info() {
    cout << "Dostpne produkty w automacie:" << endl;
    for (int i = 0; i < liczba_polek; i++) {
        wektor_polki[i]->wypisz(tab_ilosci_sztuk[i]);
        cout << endl;
    }

}


bool Automat::czy_pusty() {
    for (int i = 0; i < liczba_produktow; i++) {
        if (tab_ilosci_sztuk[i] != 0) return false;
    }
    return true;
}


Automat::~Automat() {
    for (int i = 0; i < liczba_polek; i++) {
        delete []  tab_ilosci_sztuk[i] ;
    }
    delete[] tab_ilosci_sztuk;

    for (int i = 0; i < liczba_polek; i++)
    {
        while (wektor_polki[i]->zwrocLiczbeProduktowNaPolce()) {
            delete wektor_polki[i]->zdejmijOstatniProdukt();
        }

        delete wektor_polki[i];
    }

    for (Platnosc *&i : wektor) {
        delete i;
    }

    cout << "Dowidzenia!" << endl;
}


