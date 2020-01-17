#include <iostream>
#include <iomanip>
#include <fstream>
#include "printer.cpp"

using namespace std;

void io();
bool check_dir(char* dir);
void fread(char* dir);
void fwrite(char* dir, char text[]);

int main() {

    char path[] = "/media/iushu/120bd41f-5ddb-45f2-9233-055fdc3aca07/pledge/pocc/implementation/demo.cpp";

    // io();

    // fread(path);

    char cache[100];
    Printer::print("please input the content you want to save into file: ");       
    // cin>> cache;
    cin.getline(cache, 99);
    fwrite(path, cache);

    return 0;
}

void io() {
    // char name[50];  // don't use character pointer
    // cout<< "please input your name: ";
    // cin>> name;
    // cout<< "your name is: " << name <<endl;

    int age;
    char gender[3]; // require 3 chars to store a chinese character
    cout<< "please continue to input your age and gender: ";
    cin>> age >> gender;
    cout<< "your age is: " << age <<endl;
    cout<< "your gender is: " << gender <<endl;

    int pid = 1928232;
    cerr<< "Error occurred during search the profile of person " << pid <<endl;
}

void fread(char* dir) {
    if (check_dir(dir))
        return;

    fstream file;
    file.open(dir, ios::in);
    if (file.is_open()) {
        char cache[100];
        file>>cache;
        file.close();
        cout<< cache <<endl;
        return;
    }

    cerr<< "no such file in " << dir <<endl;
}

void fwrite(char* dir, char text[]) {
    if (check_dir(dir))
        return;

    fstream file;
    file.open(dir, ios::app);
    if (file.is_open()) {
        file<< text <<endl;
        file.close();
        return;
    }

    cerr<< "no such file in " << dir <<endl;
}

bool check_dir(char* dir) {
    if (sizeof(dir) > 0)
        return false;
    cerr<< "dir is blank" <<endl;
    return true;
}
