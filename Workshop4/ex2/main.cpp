#include <iostream>

#include "ex2/Piano.h"
#include "ex2/Saxophone.h"

using namespace std;

int main() {
    Instrument *instrument;

    cout << "Quel instrument voulez-vous jouer ?" << endl;
    cout << "1. Piano" << endl;
    cout << "2. Saxophone" << endl;

    int choix;
    cin >> choix;

    switch (choix) {
        case 1:
            instrument = new Piano();
            break;
        case 2:
            instrument = new Saxophone();
            break;
        default:
            cout << "Choix invalide" << endl;
            return 1;
    }

    instrument->jouer();

    return 0;
}