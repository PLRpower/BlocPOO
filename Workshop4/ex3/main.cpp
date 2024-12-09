#include <iostream>
#include <memory>

#include "ex3/Voiture.h"
#include "ex3/Moto.h"
#include "ex3/StationDeLavage.h"

class Vehicule;
using namespace std;

int main() {
    shared_ptr<Vehicule> voiture1 = make_shared<Voiture>();
    shared_ptr<Vehicule> voiture2 = make_shared<Voiture>();
    shared_ptr<Vehicule> moto1 = make_shared<Moto>();

    StationDeLavage station;

    station.ajouterVehicule(voiture1);
    station.ajouterVehicule(voiture2);
    station.ajouterVehicule(moto1);

    cout << "Premier lavage :" << endl;
    station.laverTousLesVehicules();

    // Transformer voiture1 en moto
    shared_ptr<Vehicule> nouvelleMoto = make_shared<Moto>();
    station.retirerVehicule(0); // Supprimer voiture1
    station.ajouterVehicule(nouvelleMoto); // Ajouter la nouvelle moto

    // Relancer le lavage
    cout << "\nDeuxieme lavage (apres transformation) :" << endl;
    station.laverTousLesVehicules();

    return 0;
}