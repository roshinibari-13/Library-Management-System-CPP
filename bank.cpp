#include <iostream>
#include <fstream>
using namespace std;

class BankAccount {
private:
    int accNo;
    string name;
    double balance;

public:
    void createAccount() {
        cout<<"Enter Account Number: ";
        cin>>accNo;
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"Enter Initial Balance: ";
        cin>>balance;
    }

    void displayAccount() {
        cout<<"Account No: "<<accNo<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

    int getAccNo() {
        return accNo;
    }

    double getBalance() {
        return balance;
    }

    void deposit() {
        double amt;
        cout<<"Enter amount to deposit: ";
        cin>>amt;
        balance += amt;
    }

    void withdraw() {
        double amt;
        cout<<"Enter amount to withdraw: ";
        cin>>amt;
        if(amt > balance)
            cout<<"Insufficient Balance\n";
        else
            balance -= amt;
    }
};

void addAccount() {
    BankAccount acc;
    ofstream file("bank.txt", ios::app);

    acc.createAccount();
    file.write((char*)&acc, sizeof(acc));

    file.close();
}

void displayAccounts() {
    BankAccount acc;
    ifstream file("bank.txt");

    while(file.read((char*)&acc, sizeof(acc))) {
        acc.displayAccount();
        cout<<"------------------\n";
    }

    file.close();
}

int main() {

    int choice;

    do {
        cout<<"\nBank Management System\n";
        cout<<"1. Create Account\n";
        cout<<"2. Deposit\n";
        cout<<"3. Withdraw\n";
        cout<<"4. Display Accounts\n";
        cout<<"5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice) {

            case 1:
                addAccount();
                break;

            case 4:
                displayAccounts();
                break;

            case 5:
                cout<<"Thank you\n";
                break;

            default:
                cout<<"Invalid choice\n";
        }

    } while(choice != 5);

    return 0;
}