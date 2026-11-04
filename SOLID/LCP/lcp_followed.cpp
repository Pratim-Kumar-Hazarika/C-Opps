#include <iostream>
#include <vector>
#include <typeinfo>
#include<stdexcept>

using namespace std;

class DepositOnlyAccount {
    public:
        virtual void deposit(double amount)=0;
};

class WithdrawableAccount : public DepositOnlyAccount{
    public:
        virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public WithdrawableAccount{
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

    void withdraw(double amount){
        if(balance >= amount){
            balance-= amount;

            cout << "Windrawn amount : " << amount << " Avaiable amount in Savings Account "<< balance << ""  << endl;
        }else{
            cout << " Insufficient balance in Savings Account" << "...." << endl;
        }
    }
};

class CurrentAccount : public WithdrawableAccount {
    private:
        double balance;
    
    public:
        CurrentAccount() { 
            balance = 0; 
        }
    
        void deposit(double amount) {
            balance += amount;
            cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
        }
    
        void withdraw(double amount) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
            } else {
                cout << "Insufficient funds in Current Account!\n";
            }
        }
    };

class FixedAccount : public DepositOnlyAccount{
    private:
        double balance;

    public:
        FixedAccount(){
            balance = 0;
        }

        void deposit(double amount){
            balance+= amount;
            cout << " Deposited on fixed account .... New balance" << balance << endl;
        }
};

class BankClient{
    private:
        vector<WithdrawableAccount*> withdrawableaccounts;
        vector<DepositOnlyAccount*> depositonlyaccounts;
    public:
        BankClient(vector<WithdrawableAccount*> w,vector<DepositOnlyAccount*> d){
            this->withdrawableaccounts = w;
            this->depositonlyaccounts = d;
        }
        void processTransaction(){
            for(WithdrawableAccount* acc :  withdrawableaccounts){
                acc->deposit(5000);
                acc->withdraw(500);
            };
            for(DepositOnlyAccount* acc : depositonlyaccounts){
                acc->deposit(5000);
            }
        }
};

int main(){
    vector<WithdrawableAccount*> w;


    w.push_back(new SavingsAccount());
    w.push_back(new CurrentAccount());

     vector<DepositOnlyAccount*>d;
    d.push_back(new FixedAccount());

    BankClient* client = new BankClient(w,d);
    client->processTransaction();
    return 0;
}