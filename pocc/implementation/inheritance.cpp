#include <iostream>

using namespace std;

class Shape {
    protected:
        int width;
        int height;
    
    public:
        void setWidth(int width) {
            this->width = width;
        }    

        void setHeight(int height) {
            this->height = height;
        }
};

/**
 * Public Inheritance
 *     When deriving a class from a public base class, public members of the base class
 *     become public members of the derived class and protected members of the base class 
 *     become protected members of the derived class. A base class's private members 
 *     are never accessible directly from a derived class, but can be accessed through calls
 *     to the public and protected members of the base class.
 * 
 * Protected Inheritance 
 *     When deriving from a protected base class, public and protected members of 
 *     the base class become protected members of the derived class.
 * 
 * Private Inheritance
 *     When deriving from a private base class, public and protected members of 
 *     the base class become private members of the derived class.
 */
class Rectangle : public Shape {
    public:
        int getArea() {
            return width * this->height;
        }
};

class PaintCost {
    public: 
        int price;
        int getCost(int area) {
            return area * price;
        }

        void setPrice(int price) {
            this->price = price;
        }
};

/**
 * Multiple Inheritance
 * 
 */
class Cuboid : public Rectangle, public PaintCost {
    private:
        int tall;

    public: 
        void setTall(int tall) {
            this->tall = tall;
        }

        int getCost(int area) {     // override
            return area * this->tall * price;
        }
};

int main() {
    Rectangle rect;
    rect.setWidth(4);
    rect.setHeight(3);
    cout<< "area: " << rect.getArea() <<endl;

    Cuboid cuboid;
    cuboid.setWidth(5);
    cuboid.setHeight(5);
    cuboid.setTall(10);
    cuboid.setPrice(10);
    int cost = cuboid.getCost(cuboid.getArea());
    cout<< "cost: " << cost <<endl;
}