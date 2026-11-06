#include<iostream>
using namespace std;


class Burger {
    public:
        virtual void prepare() =0;
        virtual ~Burger()=0;
};


class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};

class BasicWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandardWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};


//Product 2

class GarlicBread {
    public:
        virtual void prepare()=0;
     
};

class BasicGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Basic Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandardGarlicBread : public GarlicBread{
public:
    void prepare() override {
        cout << "Preparing Standard Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};
class MealFactory {
    public:
        virtual Burger* createBurger(string &type)=0;
        virtual GarlicBread* createGarlicBread(string&type)=0;
};

class SinghBurger : public MealFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "basic") {
            return new BasicBurger();
        } else if (type == "standard") {
            return new StandardBurger();
        } else if (type == "premium") {
            return new PremiumBurger();
        } else {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }

    GarlicBread* createGarlicBread(string&type) override {
        if(type == "basic"){
            return new BasicGarlicBread();
        }else{
            cout <<"Invalid garlic bread"<< endl;
        }
    }
};

class KingBurger : public MealFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "basic") {
            return new BasicWheatBurger();
        } else if (type == "standard") {
            return new StandardWheatBurger();
        } else if (type == "premium") {
            return new PremiumWheatBurger();
        } else {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }

        GarlicBread* createGarlicBread(string&type) override {
        if(type == "standard"){
            return new StandardGarlicBread();
        }else{
            cout <<"Invalid garlic bread"<< endl;
        }
    }
};

int main(){
    string burgerType = "basic";
    string garlicBreadType = "standard";

    MealFactory* factory = new SinghBurger();
    Burger* burger = factory->createBurger(burgerType);
    GarlicBread* garlic = factory->createGarlicBread(garlicBreadType);
    burger->prepare();
    garlic->prepare();
    return 0;
}