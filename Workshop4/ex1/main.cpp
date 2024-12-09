#include <iostream>
#include "Voiture.h"
#include "VoitureDeSport.h"

using namespace std;

int main() {
    Voiture voiture1(80, 2);
    VoitureDeSport voiture2(150, 5);

    cout << "Nombre total de voitures creees : " << Voiture::getNombreObjets() << endl;

    for (int i = 0; i < 5; i++) {
        voiture1.accelerer();
    }

    for (int i = 0; i < 5; i++) {
        voiture2.accelerer();
    }

    voiture1 = static_cast<Voiture>(VoitureDeSport(200, 8));

    cout << "Modification : voiture 1 devient une voiture de sport" << endl;

    voiture1.accelerer();
    for (int i = 0; i < 5; i++) {
        voiture1.accelerer();
    }

    return 0;
}