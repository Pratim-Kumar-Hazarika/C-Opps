#include <iostream>
#include <vector>

using namespace std;

//product class representing a item of a ecommerce
class Product {
    public:
        string name;
        double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart{
    private:
       vector<Product*> products;
    public:
        void addProduct(Product* p){
           products.push_back(p);
        }
        
        const vector<Product*>& getProducts(){
            return products;
        }

        ///calculates total price
        double calculateTotal(){
            double total = 0;
            for(auto p : products){
                total+= p->price;
            }
            return total;
        }

        //violates Single responsibility principle should be in a different class
        void printInvoice(){
            cout << "Shopping cart:\n";
            for(auto p : products){
                cout << p->name << "- Rs " << p->price << ".. printing";
            }
            cout << "Total: Rs " << calculateTotal() << endl;
        }

                //violates Single responsibility principle should be in a different class
        void saveToDatabase() {
                cout << "Saving shopping cart to database..." << endl;
            }
};

int main(){
    ShoppingCart * cart = new ShoppingCart();

    cart->addProduct(new Product("Iphone", 50000));
    cart->addProduct(new Product("Samsung", 400));

    cart->printInvoice();
    cart->saveToDatabase();

    return 0;
}