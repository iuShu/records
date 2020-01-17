#include <iostream>
#include "printer.cpp"

using namespace std;

int divide(int a, int b);

// define new exception
struct IllegalStateException : public exception {
    const char* err() const throw() {
        return "Illegal state occurred in programme";
    }
};

int main() {

    try {
        int r;
        r = divide(100, 0);
        // r = divide(100, -1);
        Printer::print(r);
    } catch (IllegalStateException e) {
        cerr<< e.err() <<endl;
    } catch (exception e) {
        cerr<< e.what() <<endl;
    } catch (const char* err) {
        cerr<< err <<endl;
    }


    return 0;
}

int divide(int a, int b) {
    if (b == 0) 
        throw "divide by zero.";
    
    if (b == -1)
        throw IllegalStateException();

    return (a / b);
}