#include "iostream"

using namespace std;

double dvals[] = {10.1, 12.6, 33.1, 24.1, 50.0};

void ref_swap (int&, int&);
double& ref_return (int);

int main () {

    int var = 12;
    int *pt;

    pt = &var;
    cout<< "after assigned: ";
    cout<< pt <<endl;

    cout<< "value of pointer's address: ";
    cout<< *pt <<endl;

    cout<< "pointer's pointer's address: ";
    cout<< &pt <<endl;

    int var2 = 22;
    cout<< "before reference swap: ";
    cout<< var << " " << var2 <<endl;
    ref_swap(var, var2);
    cout<< "after reference swap: ";
    cout<< var << " " << var2 <<endl;

    cout<< "before change reference: ";
    for (int i=0; i<5; i++)
        cout<< dvals[i] << "\t";
    cout<<endl;
    ref_return(1) = 111.11;
    ref_return(3) = 333.33;
    cout<< "after change reference: ";
    for (int i=0; i<5; i++)
        cout<< dvals[i] << "\t";
    cout<<endl;

    return 1;
}

// reference variable as parameters 
void ref_swap (int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// reference as return type (be aware at variable's apply scope)
double& ref_return (int index) {

    // unable to return local variable caused by excessed reference's apply scope. 
    double local_variable = 2.2;
    // return local_variable;   

    static double static_variable = 3.3;
    // return static_variable;  // legal return

    return dvals[index];
}