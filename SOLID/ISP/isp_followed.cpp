#include<iostream>

using namespace std;

class TwoDimensionalObjects {
    public:
        virtual double area() = 0;
};

class ThreeDimensionalObjects {
    public:
        virtual double area()=0;
        virtual double volume() =0;
};

class Square : public TwoDimensionalObjects{
    private:
        double side;
    public:
        Square(double s){
            side = s;
        };
    double area() override {
            return side* side;
    }
};

class Cube : public ThreeDimensionalObjects{
    private:
        double side;
    public:
        Cube(double s){
            side = s;
        };
    double area() override {
            return 6* side* side;
    }
    double volume() override {
        return side * side * side;
    }
};

int main(){

    TwoDimensionalObjects* sq = new Square(5);
    ThreeDimensionalObjects* cube = new Cube(6);

    cout << "Square : " << sq->area() << endl;
    cout << "Cube Area: ====" << cube->area() << endl;
     cout << "Cube Volume: ====" << cube->volume() << endl;


    return 0;
}

