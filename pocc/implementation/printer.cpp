#include <iostream>

using namespace std;

class Printer {
    public:
        static void print(int val) {
            cout<< ">> " << val <<endl;
        }

        static void print(double val) {
            cout<< ">> " << val <<endl;
        }

        static void print(short val) {
            cout<< ">> " << val <<endl;
        }

        static void print(float val) {
            cout<< ">> " << val <<endl;
        }

        static void print(long val) {
            cout<< ">> " << val <<endl;
        }

        static void print(char val) {
            cout<< ">> " << val <<endl;
        }

        static void print(char* val) {
            cout<< ">> " << val <<endl;
        }

        static void endl() {
            cout<< "" <<endl;
        }

};