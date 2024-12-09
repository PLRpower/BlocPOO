#include <iostream>
#include <cstdlib>

using namespace std;

class Creature {
    private:
        int pv;
        int pa;
        int niveau;

    public:
    static int cpt;
        Creature() {
            pv = 1;
            pa = 1;
            niveau = 1;
            cpt++;
        }

        Creature(int pv, int pa, int niveau) {
            this->pv = pv;
            this->pa = pa;
            this->niveau = niveau;
            cpt++;
        }

        Creature(const Creature& c) {
            pv = c.pv;
            pa = c.pa;
            niveau = c.niveau;
            cpt++;
        }

        ~Creature() {
            cpt--;
        }

        void affiche() const {
            std::cout << "---- " << std::endl;
            std::cout << "PV: " << pv << std::endl;
            std::cout << "PA: " << pa << std::endl;
            std::cout << "Niveau: " << niveau << std::endl;
            std::cout << "---- " << std::endl;
        }

        int attaque() const {
            return pa * (1+ rand() % 2);
        }

        void subitDegat(const int degat) {
            pv -= degat;
        }

        void estVivant() const {
            if (pv > 0) {
                std::cout << "La creature est vivante" << std::endl;
            }
            else {
                std::cout << "La creature est morte" << std::endl;
            }
        }
};

class Heros {
    private:
        std::string nom;
        int pv;
        int pa;

    public:
        Heros() {
            nom = "Inconnu";
            pv = 5;
            pa = 5;
        }

        Heros(std::string nom, int pv, int pa) {
            this->nom = nom;
            this->pv = pv;
            this->pa = pa;
        }

        void affiche() const {
            std::cout << "---- " << std::endl;
            std::cout << "Nom: " << nom << std::endl;
            std::cout << "PV: " << pv << std::endl;
            std::cout << "PA: " << pa << std::endl;
            std::cout << "---- " << std::endl;
        }

        int attaque() const {
            return pa * (1+ rand() % 2);
        }

        void subitDegat(const int degat) {
            pv -= degat;
        }

        void estVivant() const {
            if (pv > 0) {
                std::cout << "Le heros est vivant" << std::endl;
            }
            else {
                std::cout << "Le heros est mort" << std::endl;
            }
        }
};

int Creature::cpt = 0;



void bar(Creature c1) {
    Creature c2;
    cout << "Nombre de creatures: " << Creature::cpt << endl;
}

int main() {
    cout << "Test 2: \n";
    Creature c1;
    Creature c2(10, 2, 2);
    cout << "Nombre de creatures: " << Creature::cpt << endl;
    bar(c2);
    cout << "Nombre de creatures: " << Creature::cpt << endl;
    return 0;
}