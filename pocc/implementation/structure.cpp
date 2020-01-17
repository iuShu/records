#include <iostream>
#include <cstring>

using namespace std;

void print_book(struct Book book);
void print_book_pt(struct Book *struct_pt);

struct Book {
    int id;
    char title[50];
    char author[50];
    char subject[100];
} book;

typedef struct {
    int id;
    char title[50];
    char author[50];
    char subject[100];
} Books;

int main() {

    struct Book cartoon;
    struct Book magazine;

    cartoon.id = 928382;
    strcpy(cartoon.title, "Assassinate");
    strcpy(cartoon.author, "John Lenon");
    strcpy(cartoon.subject, "Adventure");

    magazine.id = 838111;
    strcpy(magazine.title, "Man Decoration");
    strcpy(magazine.author, "Basa");
    strcpy(magazine.subject, "Fashion");

    print_book(cartoon);
    print_book(magazine);

    struct Book *struct_pt;
    struct_pt = &magazine;

    print_book(*struct_pt);
    print_book_pt(struct_pt);

    Books tdf_book;     // apply struct like a basic data type
    tdf_book.id = 92821120;      
    strcpy(tdf_book.title, "typdefine book");
    strcpy(tdf_book.author, "typdefine author");
    strcpy(tdf_book.subject, "typdefine subject");

    cout<< "tdf struct: " << tdf_book.title <<endl;

    return 1;
}

void print_book(struct Book book) {
    cout<< "book: " << book.id << "\t<" << book.title << ">\t";
    cout<< book.author << "\t(" << book.subject << ")" <<endl;
}

void print_book_pt(struct Book *struct_pt) {
    // access struct's member by pointer, using -> instead of .
    cout<< "struct: " << struct_pt->id << "\t<" << struct_pt->title << ">\t";
    cout<< struct_pt->author << "\t(" << struct_pt->subject << ")" <<endl;
}
