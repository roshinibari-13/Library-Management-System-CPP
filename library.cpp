#include <iostream>
#include <fstream>
using namespace std;

class Book {
public:
    int id;
    char title[50];
    char author[50];
    bool issued;

    void addBook() {
        cout<<"Enter Book ID: ";
        cin>>id;
        cout<<"Enter Title: ";
        cin>>title;
        cout<<"Enter Author: ";
        cin>>author;
        issued = false;
    }

    void displayBook() {
        cout<<"Book ID: "<<id<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;

        if(issued)
            cout<<"Status: Issued"<<endl;
        else
            cout<<"Status: Available"<<endl;

        cout<<"-----------------------\n";
    }
};

void addBook() {
    Book b;
    ofstream file("library.txt", ios::app);

    b.addBook();
    file.write((char*)&b, sizeof(b));

    file.close();
}

void displayBooks() {
    Book b;
    ifstream file("library.txt");

    while(file.read((char*)&b, sizeof(b))) {
        b.displayBook();
    }

    file.close();
}

int main() {

    int choice;

    do {

        cout<<"\nLibrary Management System\n";
        cout<<"1. Add Book\n";
        cout<<"2. Display Books\n";
        cout<<"3. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice) {

            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                cout<<"Exiting...\n";
                break;

            default:
                cout<<"Invalid choice\n";
        }

    } while(choice != 3);

    return 0;
}