#include<iostream>
using namespace std;

class Database{
    public:
        virtual void save(string name)=0;
};

class MySql : public Database{
    public:
        void save(string name) override {
            cout << " Save to mysql " << name << endl;
        }
};



class MongoDb : public Database{
    public:
        void save(string name) override {
            cout << " Save to mongoDb " << name << endl;
        }
};

class User {
    private:
        Database* db;
    public:
        User(Database* x){
            db = x;///dependecy indjection
        }
    void save(string name){
        db->save(name);
    };
};

int main(){
    MongoDb mongo;
    MySql sql;

    User* service1  = new User(&mongo);
    service1->save("Pratim");


     User* servic2  = new User(&sql);
    servic2->save("pr");
    return 0;
}