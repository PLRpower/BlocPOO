#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class UniqueList {
private:
    vector<int> list;
    unordered_map<int, bool> hashTable;

public:
    bool hasValue(const int val) const {
        return hashTable.contains(val);
    }

    bool addValue(const int val) {
        if (hasValue(val)) {
            return false;
        }
        list.push_back(val);
        hashTable[val] = true;
        return true;
    }

    bool remove(const int val) {
        if (!hasValue(val)) {
            return false;
        }
        hashTable.erase(val);
        for (int i = 0; i < list.size(); i++) {
            if (list[i] == val) {
                list.erase(list.begin() + i);
                break;
            }
        }
        return true;
    }

    void print() const {
        cout << "[ ";
        for (int val : list) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }
};

int main() {
    UniqueList uniqueList;

    uniqueList.addValue(10);
    uniqueList.addValue(20);
    uniqueList.addValue(30);
    uniqueList.addValue(20);  // Doublon, ne sera pas ajouté

    uniqueList.print();

    cout << "20 present dans la liste ? " << (uniqueList.hasValue(20) ? "Oui" : "Non") << endl;
    cout << "40 present dans la liste ? " << (uniqueList.hasValue(40) ? "Oui" : "Non") << endl;

    uniqueList.remove(20);

    uniqueList.print();

    return 0;
}
