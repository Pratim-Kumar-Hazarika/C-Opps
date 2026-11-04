#include<iostream>
#include<stdexcept>

using namespace std;

class Shape {
    public:
        virtual double area()= 0;
        virtual double volume()=0;//2D shapes doesn't have volume
};

class Square : public Shape{
    private:
        double size;
    public:
    Square(double s){
        size = s;
    }
    
    double area() override{
        return size*size;
    }

    double volume() override {
        throw logic_error("Square doesn't have volume");
    }
};


class Rectangle : public Shape {
    private: 
    double length, width;

    public:

    Rectangle(double length, double width){
        length = length,
        width = width;
    }

    double area() override {
        return length * width;
    }

       double volume() override {
        throw logic_error("Volume not applicable for Rectangle"); // Unnecessary method
    }

};

class Cube : public Shape {
    private:
        double side;
    public:

    Cube(double side){
        side = side;
    }

     double area() override {
        return 6 * side * side;
    }

    double volume() override {
        return side * side * side;
    }
};

int main(){
    Shape* sq = new Square(4);
    Shape* cube = new Cube(3);
    Shape* rec = new Rectangle(4,8);

    cout <<"Square area: " << sq->area() << endl;
    cout <<"Rectangle area: " << rec->area() << endl;
    cout <<"Cube area: " << cube->area() << endl;

       try {
        cout << "Square Volume: " << sq->volume() << endl; // Will throw an exception
    } catch (logic_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

}