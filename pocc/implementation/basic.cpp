#include <iostream>
#include <string>   // String in CPP
#include <cstring>  // for process string 
#include <cmath>    // for basic math operation
#include <ctime>    // time component
#include <cstdlib>  // utilities
using namespace std;

typedef int Integer;    // typedef: giving the type a new name (Integer)

extern char repeatableUse;  // extern: make a variable can be access in other cpp files.
                            // global constant define

static double factor = 0.01; // static: global constant define

#define DEFAULT_CAPACITY 10; // define a constant

const wchar_t NEWLINE = '\n';   // define a constant

int versionControll();  // predefine a function  

int main() {

    // define a constant within the function
    #define CAPCOM 12;
    const int CAPACITY = 1024;
    static double t_factor = 0.001;

    register int counter = 3;   // maybe save in register(寄存器), represents a variable require access hurry.

    bool right = false;
    char code = 'c';
    short s = 127;
    int integer = 1023;
    float f = 3.232f;
    double d = 32.132;

    wchar_t wc = 'm';
    char string[] = "hello world";

    signed int si = 934;
    unsigned long usl = 29232;
    short int sii = 777;
    long long ll = 9999999;

    Integer stillInt = 666;

    // Lambda expression
    [si](int x, int y) -> int {int z = x + y + si; return z + x;}; // capture = si
    [](int x, int y) -> int {int z = x + y; return z + x;}; // with return typed(int) 
    [](int x){x + 10;};     // without return type

}

enum Enumilation {
    red,
    green,
    black,
    orange,
    pink,
    grape,
    pray
} Example;

int function(int, int) {
    printf("this type also can be accepted if you don't need parameters.\n");
    return 1;
}

int default_parameter(int a, int b = 20) {
    return a + b;
}

void array() {

    Example = orange;

    double balance[5];
    double price[4] = {1.1, 12.99, 19.99, 5499};
    double discount[] = {1.1, 12.99, 19.99, 5499};

    double *arrP = discount;
    double select = *(arrP + 1);    // 12.99

    // dispatch an array as function parameter
    [arrP](double *arrP) {cout << *(arrP + 1);};
    [arrP](double arrP[4]) {cout << arrP[1];};
    [arrP](double arrP[]) {cout << arrP[1];};

    // return an array as return type
    [arrP]() -> double * {return arrP;};

}