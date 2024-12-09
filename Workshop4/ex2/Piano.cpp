#include "Piano.h"
#include <iostream>

using namespace std;

void Piano::jouer() {
    cout << "Le piano joue une melodie" << endl;
    std::system("start C:/Users/pault/CLionProjects/Workshop4/piano.wav");
}
