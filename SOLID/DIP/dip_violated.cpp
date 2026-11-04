#include<iostream>
using namespace std;

class MySqlDb {
    public :
    void saveToSql(string name){
        cout << "Saving to sql ..." << name << endl;
    };
};


class MongoDb {
    public :
    void saveToMongoDb(string name){
        cout << "Saving to Mongodb ..." << name << endl;
    };
};

class User {
    private:
        MySqlDb* sql;
        MongoDb * mongo;
    public:
        void saveToSql(string name){
            sql->saveToSql(name);
        }
        void saveToMongo(string name){
            sql->saveToSql(name);
        }
};

int main(){
    User user;
    user.saveToMongo("Pratim");
    user.saveToSql("Sql");
}
