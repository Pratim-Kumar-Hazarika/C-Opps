#include<iostream>
#include <vector>

using namespace std;

class Product {
    public:
        string name;
        double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }
};

//1. Shopping cart only responsible for cart related business logic
class ShoppingCart{
    private:
        vector<Product*> products;
    public:
        void addProducts(Product* p){
            products.push_back(p);
        }
        
        const vector<Product*>& getProducts(){
            return products;
        }

        double calculateTotal(){
            double total = 0;
            
            for(auto p : products){
                total += p->price;
            }
            return total;
        }
};

//2. Shopping Printer responsible for prinitng invoice

class ShoppingPrinter{
    private:
        ShoppingCart* cart;
    public:
        ShoppingPrinter(ShoppingCart* cart){
            this->cart = cart;
        }
    
        void printInvoice(){
            for(auto p : cart->getProducts()){
                cout << p->name << p->price;
            }
             cout << "Total: Rs " << cart->calculateTotal() << endl;
        }
};

// //3. Save tot db class responsible only to save to db

// class ShoppingCartStorage{
//     private:
//         ShoppingCart* cart;
//     public :
//     ShoppingCartStorage(ShoppingCart* cart){
//         this->cart = cart;
//     }
//     void saveToSql(){
//         for(auto p : cart->getProducts()){
//             cout << " Save to db this product" << p->name << "..";
//         }
//     }
//        void saveToMongoDb(){
//         for(auto p : cart->getProducts()){
//             cout << " Save to db this product" << p->name << "..";
//         }
//     }
//        void saveToCassandra(){
//         for(auto p : cart->getProducts()){
//             cout << " Save to db this product" << p->name << "..";
//         }
//     }
// };



class Persistence{
    private:
    ShoppingCart* cart;
    public: 
        virtual void save(ShoppingCart*cart) = 0;//Pure virtual function
};

class SqlPersistence : public Persistence{
    public:
        void save(ShoppingCart* cart) override {
          cout << "Saving shopping cart to SQL DB..." << endl;
        }
};

class MongoPersistence : public Persistence{
    public:
      void save(ShoppingCart* cart) override {
          cout << "Saving shopping cart to MonoDb..." << endl;
    }
};


int main(){
    ShoppingCart* cart =new ShoppingCart();
    cart->addProducts(new Product("Iphone", 4000));
    cart->addProducts(new Product("Samsung", 4000));

    ShoppingPrinter* print = new ShoppingPrinter(cart);
    print->printInvoice();

    // ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    // db->saveToSql();

    Persistence* sql = new SqlPersistence();
    sql->save(cart);

    Persistence* mongo = new MongoPersistence();
    mongo->save(cart);
    

    return 0;
}