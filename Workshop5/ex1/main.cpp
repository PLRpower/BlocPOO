#include <iostream>
#include <vector>

class Observable;
using namespace std;

class Observers {
public:
    virtual void update(Observable* observed) = 0;
    virtual ~Observers() = default;
};

class Observable {
protected:
    vector<Observers*> observers;
public:
    virtual int subscribe(Observers* observer) = 0;
    virtual int unsubscribe(const Observers* observer) = 0;
    virtual void notify() = 0;

    virtual ~Observable() = default;
};

class ConcreteObservers final : public Observers {
public:
    void update(Observable* observed) override {
        cout << "Evenement observe" << endl;
    }
};

class ConcreteObservable final : public Observable {
public:
    int subscribe(Observers* observer) override {
        observers.push_back(observer);
        return 1;
    }

    int unsubscribe(const Observers* obs) override  {
        for (int i = 0; i < observers.size(); i++) {
            if (observers[i] == obs) {
                observers.erase(observers.begin() + i);
                return 0;
            }
        }
        return -1;
    }

    void notify() override {
        for (const auto observer : observers) {
            observer->update(this);
        }
    }
};

class Client {
private:
    ConcreteObservable observable;
    ConcreteObservers observer;
public:
    Client() = default;

    void test() {
        observable.subscribe(&observer);
        observable.notify();
        observable.unsubscribe(&observer);
    }
};

int main() {
    Client c;
    c.test();

    return 0;
}