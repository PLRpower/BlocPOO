#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
using namespace this_thread;

class AvatarState {
public:
    virtual ~AvatarState() = default;
    virtual void action() const = 0;
    virtual AvatarState* next() const = 0;
};

class Glad final : public AvatarState {
public:
    void action() const override {
        cout << "😊 Glad" << endl;
    }
    AvatarState* next() const override;
};

class Happy final : public AvatarState {
public:
    void action() const override {
        cout << "😀 Happy" << endl;
    }
    AvatarState* next() const override;
};

class Sad final : public AvatarState {
public:
    void action() const override {
        cout << "😢 Sad" << endl;
    }
    AvatarState* next() const override;
};

class Angry final : public AvatarState {
public:
    void action() const override {
        cout << "😡 Angry" << endl;
    }
    AvatarState* next() const override;
};

class Grumpy final : public AvatarState {
public:
    void action() const override {
        cout << "😤 Grumpy" << endl;
    }
    AvatarState* next() const override;
};

AvatarState* Glad::next() const {return new Happy();}
AvatarState* Happy::next() const {return new Sad();}
AvatarState* Sad::next() const {return new Angry();}
AvatarState* Angry::next() const {return new Grumpy();}
AvatarState* Grumpy::next() const {return new Glad();}

class Avatar {
private:
    AvatarState* currentState;

public:
    Avatar() : currentState(new Glad()) {}

    ~Avatar() {
        delete currentState;
    }

    void run() {
        while (true) {
            currentState->action();
            sleep_for(seconds(5));
            AvatarState* nextState = currentState->next();
            delete currentState;
            currentState = nextState;
        }
    }
};

int main () {
    Avatar avatar;
    avatar.run();
    return 0;
}
