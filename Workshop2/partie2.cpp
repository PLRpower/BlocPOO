#include <iostream>
using namespace std;

class Creature {
public:
    Creature() {} // Constructeur par défaut sans paramètre
    Creature(const Creature &c) {
        // Constructeur par copie
        cout << "A creature has been duplicated" << endl;
    }
    ~Creature() {
        // Destructeur
        cout << "A Creature has been destroyed" << endl;
    }
};

/** Passage par valeur : Une copie de l'objet est créée pour la fonction
 * Avantage : L'original reste inchangé
 * Inconvénient : La copie est coûteuse en temps et en mémoire (si l'objet est volumineux)
 *
 * Passage par référence : La fonction reçoit une référence de l'objet
 * Avantage : Economie de mémoire, et permet de modifier l'objet original
 * Inconvénient : Risque de modification accidentelle de l'original
 */
