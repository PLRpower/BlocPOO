#include <iostream>
#include <map>

using namespace std;

enum class StateId { E1, E2, E3, E4, FINAL };

class AbstractState {
public:
    virtual ~AbstractState() = default;

    virtual void action() const = 0;
};

class StateE1 final : public AbstractState {
public:
    void action() const override {
        cout << "Action de l'etat E1" << endl;
    }
};

class StateE2 final : public AbstractState {
public:
    void action() const override {
        cout << "Action de l'etat E2" << endl;
    }
};

class StateE3 final : public AbstractState {
public:
    void action() const override {
        cout << "Action de l'etat E3" << endl;
    }
};

class StateE4 final : public AbstractState {
public:
    void action() const override {
        cout << "Action de l'etat E4" << endl;
    }
};

class Automata {
private:
    map<StateId, StateId> delta;
};

int main() {
    Automata automata;
    return 0;
}
