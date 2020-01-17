#include <iostream>

using namespace std;

class Box {                         

    double cost;                    // private (default)
    double profit;                  // private (default)

    private:                        // private section
        double price;

    protected:
        double bargain = 0.5;

    public:
        // protected:               // will effecting all the following members/methods
        //     int amount;

        Box();                      // constructor (require definition before using the class)
        Box(int amount);            // initialize lists   
        Box(const Box &box);        // copy constructor
        ~Box();                     // also require declare         
        Box(double length) {   // constructor with parameter
            cout<< "-- initialize class with parameter: " << length <<endl;
            visitCount++;
        }

        double length;
        double breadth;
        double height;

        int *store;                 // dynamic memory allocation require a copy constructor

        static int visitCount;

        double getVolume(void);     // declaration
        
        double bottomArea(void) {   // definition
            return breadth * length;
        }

        int getAmount() {           // public method to access protected member
            return amount;
        }

        // define outside the class and have the right to access all private  
        // and protected members of the class.
        // friend function do not have a 'this' pointer
        friend void printBargain(Box box);   

        int compare(Box other) {    // this pointer (an implicit parameter to all member of functions)
            return this->getVolume() > other.getVolume();
        }

        static int getVisitCount() {   // static function can only access static member
            return visitCount;
        }

        protected:                  // available declare in public section
            int amount;
      
};

int Box::visitCount = 5;            // initialize static member

Box::Box() {
    cout<< "-- initialize class" <<endl;
}

Box::Box(int amount):amount(amount) {           // another syntax to initialize with parameter
    cout<< "-- initialize class list with parameter" << amount <<endl;

    // allocate memory for pointer (dynamic memory allocation)
    store = new int;
    *store = amount;
}

Box::Box(const Box &box) {
    cout<< "-- copy constructor allocating pointer" <<endl;

    store = new int;
    *store = *box.store;    // copy the value for dynamic memory allocation
}

Box::~Box() {
    cout<< "-- object is being destructed" <<endl;
}

double Box::getVolume(void) {       // definition (outside the class body)
    return length * breadth * height;
}

void getStore(Box box) {
    cout<< "small pointer address: " << box.store <<endl;
    cout<< "small pointer value: " << *box.store <<endl;
}

void printBargain(Box box) {
    cout<< "friend function is able to access private member outside: " << box.bargain <<endl;
}

int main() {

    Box large;          // create class
    Box middle(7.0);    // create with parameter 
    Box small(9);    // class initialize list 

    cout<< "-- class initialize over" <<endl;

    large.height = 8.0;
    large.breadth = 10.0;
    large.height = 10.0;

    middle.height = 4.0;
    middle.breadth = 6.0;
    middle.height = 6.0;

    small.height = 2.0;
    small.breadth = 4.0;
    small.height = 4.0;

    cout<< "large box volume: " << large.height * large.breadth * large.length <<endl;
    cout<< "middle box volume: " << middle.height * middle.breadth * middle.length <<endl;
    cout<< "small box volume: " << small.height * small.breadth * small.length <<endl;

    cout<< "large box volume(method): " << large.getVolume() <<endl;
    cout<< "large box bottom area: " << large.bottomArea() <<endl;
    cout<< "small box amount: " << small.getAmount() <<endl;

    getStore(small);

    printBargain(middle);

    int cmp = small.compare(large);
    cout<< "small compare to large: " << cmp <<endl;

    Box *package;
    package = &middle;  // must initialize before using it.
    cout<< "class pointer access volume method: " << package->getVolume() <<endl;

    cout<< "Box visit count: " << small.visitCount <<endl;
    cout<< "Box visit static function: " << Box::getVisitCount() <<endl;

    cout<< "-- end" <<endl;
    return 0;
}
