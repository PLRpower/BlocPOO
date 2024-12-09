#include <iostream>

#include "Ex3/Carre.h"
#include "Ex3/Objet2D.h"
#include "Ex3/Rectangle.h"

using namespace std;

int main() {
    Objet2D* obj = new Objet2D();
    string texte;
    cout << "Entrez une forme (rectangle ou carre): ";
    cin >> texte;
    if(texte == "rectangle") {
        obj = new Rectangle(2, 3);
    } else if(texte == "carre") {
        obj = new Carre();
    }
    obj->afficheInfo();


    return 0;
}
