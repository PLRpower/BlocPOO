#include <iostream>
#include <vector>

using namespace std;

void tri_insertion(vector<int> &l, const int n) {
    for (int i = 1; i < n; i++) {
        const int v = l[i];
        int j = i;
        while (j > 0 && l[j - 1] > v) {
            l[j] = l[j - 1];
            j = j - 1;
        }
        l[j] = v;
    }
}

int main() {
    vector liste = {12, 5, 8, 3, 7, 10, 2, 1};
    tri_insertion(liste, liste.size());
    for (int i = 0; i < liste.size(); i++) {
        cout << liste[i] << " ";
    }
    return 0;
}