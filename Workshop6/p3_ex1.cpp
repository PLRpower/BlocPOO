#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

class ChangeBase {
private:
    stack<int> digits;

public:
    stack<int> toBase(int n, int b) {
        if (b <= 0 || b > 10) {
            throw invalid_argument("La base doit être comprise entre 1 et 10.");
        }

        while (n > 0) {
            int remainder = n % b;
            digits.push(remainder);
            n /= b;
        }
        return digits;
    }

    void print() {
        if (digits.empty()) {
            cout << "Aucun chiffre à afficher. Faites une conversion d'abord !" << endl;
            return;
        }

        cout << "Résultat en base : ";
        while (!digits.empty()) {
            cout << digits.top();
            digits.pop();
        }
        cout << endl;
    }
};

int main() {
    try {
        ChangeBase converter;
        int n, b;

        cout << "Entrez un entier à convertir : ";
        cin >> n;

        cout << "Entrez la base de conversion (1 à 10) : ";
        cin >> b;

        converter.toBase(n, b);
        converter.print();
    } catch (const exception &e) {
        cerr << "Erreur : " << e.what() << endl;
    }

    return 0;
}