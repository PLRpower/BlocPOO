#include <iostream>
#include <memory>

#include "ex3/Voiture.h"
#include "ex3/Moto.h"
#include "ex3/StationDeLavage.h"

class Vehicule;
using namespace std;

int main() {

    StationDeLavage station{};

    Voiture voiture1;
    Voiture voiture2;
    Moto moto1;

    station.ajouterVehicule(&voiture1);
    station.ajouterVehicule(&voiture2);
    station.ajouterVehicule(&moto1);

    cout << "Premier lavage :" << endl;
    station.laverTousLesVehicules();

    // Transformer voiture1 en moto
    Vehicule* nouvelleMoto = new Moto();
    station.retirerVehicule(0); // Supprimer voiture1
    station.ajouterVehicule(nouvelleMoto); // Ajouter la nouvelle moto

    // Relancer le lavage
    cout << "\nDeuxieme lavage (apres transformation) :" << endl;
    station.laverTousLesVehicules();

    return 0;
}