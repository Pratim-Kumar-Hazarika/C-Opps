#include<iostream>
#include<vector>
#include <typeinfo>
#include<stdexcept>

using namespace std;

class Account {
    public:
        virtual void deposit(double amount) = 0;
        virtual void withdrawl(double amount) = 0;
};

class SavingsAccount : public Account{
    private:
        double balance;
    public:
    SavingsAccount(){
        balance = 0;
    }

    void deposit(double amount){
        balance += amount;
        cout << "Deposited : " << amount << " New Balance "<< balance  << endl; 
    }

    void withdrawl(double amount){
        if(balance >= amount){
            balance-= amount;

            cout << "Windrawn amount : " << amount << " Avaiable amount in Savings Account "<< balance << ""  << endl;
        }else{
            cout << " Insufficient balance in Savings Account" << "...." << endl;
        }
    }

};

class CurrentAccount : public Account{
    private:
        double balance;
    public:
    CurrentAccount(){
        balance = 0;
    }

    void deposit(double amount){
        balance += amount;
        cout << "Deposited : " << amount << " New Balance "<< balance  << endl; 
    }

    void withdrawl(double amount){
        if(balance >= amount){
            balance-= amount;

            cout << "Windrawn amount : " << amount << " Avaiable amount in Current---Account "<< balance << ""  << endl;
        }else{
            cout << " Insufficient balance in Current---Account" << "...." << endl;
        }
    }

};

class FixedTermAccount : public Account {
private:
    double balance;

public:
    FixedTermAccount() { 
        balance = 0;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }

    void withdrawl(double amount) {
        throw logic_error("You can't withdraw from fixed term account");
    }
};

class BankClient {
    private:
        vector<Account*> accounts;
    public :
        BankClient(vector<Account*>  accountsList){
            this->accounts = accountsList;
        }   

        void processTransaction(){
            for(Account* acc : accounts){
                acc->deposit(50000);

                if(typeid(*acc) == typeid(FixedTermAccount)){
                    cout << "Skipping withdrawal for Fixed Term Account.\n" << endl;
                }else{
                    try{
                            acc->withdrawl(500);
                    }catch(const logic_error&e){
                        cout << "Exception " << e.what() << endl;
                    }
                }
            }   
        }
};

int main(){

    vector<Account*> accounts;
    accounts.push_back(new SavingsAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient(accounts);
    client->processTransaction();

    return 0;
}

