#include <iostream>
#include <fstream>
#include "Automat.h"
#include "Walidacja.h"
using namespace std;

int main(int argc, const char *argv[]) {

    ifstream input;
    if (argc == 2) {
        input.open(argv[1]);
        cin.rdbuf(input.rdbuf());
    }

    Automat a(1, 1, 0);

    string decision = "y";

    while (decision == "y") {

        if (a.czy_pusty()) {
            cout << "Brak napojow w automacie. Przepraszamy";
            break;
        }
        a.napoje_info();
        if (a.sprawdz_czy_zaplacone()) {
            cout << "Dziekujemy za zakupy!" << endl;
            cout << " Czy chcesz zakupic kolejny produkt ? (y/n): ";
        } else {
            cout << " Czy chcesz sprobowac jeszcze raz zakupic produkt ? (y/n): ";
        }
        decision = Walidacja::sprawdzString();
    }

    return 0;
}
