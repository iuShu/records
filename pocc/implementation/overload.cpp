#include <iostream>

using namespace std;

class Printer {
    public:
        void print(int val) {
            cout<< "print int: " << val <<endl;
        }

        void print(double val) {        // overload
            cout<< "print double: " << val <<endl;
        }
};

class Line {
    private:
        int length;
    public: 
        void setLength(int length) {
            this->length = length;
        }

        int getLength() {
            return this->length;
        }

        Line operator+(const Line &square) {    // operator overload
            Line result;
            result.length = this->length + square.length;
            return result;
        }

        /**
         * following operators can not be overloaded:
         *      ::    .*    .    ?: 
         */

        // overload output
        friend ostream &operator<<(ostream &os,  const Line &line) {
            os << "Line: line=" << line.length;
            return os;
        }

        // overload input
        friend istream &operator>>(istream &is, Line &line) {
            is >> line.length;
            return is;
        }        
};

class SafeArray {
    private:
        int arr[10];

    public:
        SafeArray() {
            register int i;
            for (i=0; i<10; i++)
                this->arr[i] = i;
        }

        int &operator[](int index) {    // overload operator []
            if (index < 0 || index >= 10) {
                cout<< "illegal index: " << index <<endl;
                return this->arr[0];    // return first element
            }
            return this->arr[index];
        }
};

int main() {

    Printer printer;
    printer.print(888);
    printer.print(99.9);

    Line line1;
    Line line2;
    line1.setLength(10);
    line2.setLength(23);
    Line total = line1 + line2;    // appling overloaded operator

    printer.print(line1.getLength());
    printer.print(line2.getLength());
    printer.print(total.getLength());
    
    Line line3;
    cout<< "Enter the value of length: ";
    cin>> line3;
    cout<< line1 <<endl;
    cout<< line3 <<endl;

    int unsafeArray[] = {15, 92, 63};
    SafeArray arr;
    printer.print(arr[2]);
    printer.print(arr[5]);
    printer.print(arr[12]);
    printer.print(unsafeArray[2]);
    printer.print(unsafeArray[3]);
    printer.print(unsafeArray[4]);
    printer.print(unsafeArray[12]);

    return 0;
}