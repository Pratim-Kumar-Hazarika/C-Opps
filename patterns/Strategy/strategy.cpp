
#include <iostream>
using namespace std;

// Strategy interface: Walk
class WalkableRobot {
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() = default;
};

class NormalWalk : public WalkableRobot {
public:
    void walk() override {
        cout << "Walking normally..." << endl;
    }
};

class NoWalk : public WalkableRobot {
public:
    void walk() override {
        cout << "Not walking..." << endl;
    }
};

// Strategy interface: Fly
class FlyRobot {
public:
    virtual void fly() = 0;
    virtual ~FlyRobot() = default;
};

class FlyFast : public FlyRobot {
public:
    void fly() override {
        cout << "Flying fast..." << endl;
    }
};

class FlySlow : public FlyRobot {
public:
    void fly() override {
        cout << "Flying slowly..." << endl;
    }
};

// Strategy interface: Talk
class TalkRobot {
public:
    virtual void talk() = 0;
    virtual ~TalkRobot() = default;
};

class SlowTalk : public TalkRobot {
public:
    void talk() override {
        cout << "Slow talking..." << endl;
    }
};

class FastTalk : public TalkRobot {
public:
    void talk() override {
        cout << "Fast talking..." << endl;
    }
};

// Base Robot
class Robot {
private:
    WalkableRobot* walkBehaviour;
    FlyRobot* flyBehaviour;
    TalkRobot* talkBehaviour;

public:
    Robot(WalkableRobot* w, FlyRobot* f, TalkRobot* t) {
        walkBehaviour = w;
        flyBehaviour = f;
        talkBehaviour = t;
    }

    void walk() {
        walkBehaviour->walk();
    }

    void fly() {
        flyBehaviour->fly();
    }

    void talk() {
        talkBehaviour->talk();
    }

    // Change behaviour at runtime
    void setWalkBehaviour(WalkableRobot* w) {
        walkBehaviour = w;
    }

    virtual void projection() = 0;

    virtual ~Robot() = default;
};

class Robot1 : public Robot {
public:
    Robot1(WalkableRobot* w, FlyRobot* f, TalkRobot* t)
        : Robot(w, f, t) {}

    void projection() override {
        cout << "Robot1 stats" << endl;
    }
};

class Robot2 : public Robot {
public:
    Robot2(WalkableRobot* w, FlyRobot* f, TalkRobot* t)
        : Robot(w, f, t) {}

    void projection() override {
        cout << "Robot2 stats" << endl;
    }
};

int main() {

    Robot* robot1 = new Robot1(
        new NormalWalk(),
        new FlyFast(),
        new SlowTalk()
    );

    robot1->walk();
    robot1->fly();
    robot1->talk();

    cout << "\nChanging walking behaviour...\n";

    robot1->setWalkBehaviour(new NoWalk());

    robot1->walk();

    delete robot1;

    return 0;
}
