#include <iostream>
using namespace std;

class acc {
public:
    string name;
    int acc_no;
    float balance;
    virtual void get_data() {
        cout << "----------------Hello dear customer! Welcome to ABC bank!----------------" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Account number: ";
        cin >> acc_no;
        cout << "Enter your balance: ";
        cin >> balance;
        cout << "                  ---xxx---                   " << endl;
    }
    virtual void deposit() = 0; // Make deposit() a pure virtual function if every derived class must implement it
};

class sav : public acc {
public:
    float time;
    float wdraw;
    void interest() {
        cout << "For how long do you intend to keep the money (in years)? ";
        cin >> time;
        float ci = (balance * time * 10) / 100;
        balance += ci;
        cout << "You shall earn " << ci << " rupees in " << time << " years" << endl;
        cout << "Balance: " << balance <<endl;
        cout<<"                  ---xxx---                   " << endl;
    }
    void withdraw() {
        cout << "How much money would you want to withdraw? ";
        cin >> wdraw;
        if (wdraw >= balance) {
            cout << "Sorry! The value is greater than the balance :(" << endl;
        } else {
            balance -= wdraw;
            cout << "Withdrawn successfully! Balance: " << balance<<endl;;
        }
        cout << "                  ---xxx---                   " << endl;
    }
    void deposit() override {
        float deposit;
        cout << "How much would you like to deposit? ";
        cin >> deposit;
        balance += deposit;
        cout << "Successfully deposited. Balance: " << balance<<endl;
        cout<< "                  ---xxx---                   " << endl;
    }
};

class cur : public acc {
public:
    float minimum = 1000; // Initialize directly
    void mini() {
        if (balance <= minimum) {
            cout << "Oh no! Low balance... Kindly make it up to minimum balance. As per bank regulations, you are charged a penalty." << endl;
            cout << "Penalty fee: Rs.200 " << endl;
            cout << "                  ---xxx---                   " << endl;
        } else {
            cout << "It's nice that you maintain the balance. No penalties :)" << endl;
        }
    }
    void deposit() override {
        float deposit;
        cout << "How much would you like to deposit? ";
        cin >> deposit;
        balance += deposit;
        cout << "Successfully deposited. Balance: " << balance<<endl;
        cout<< "                  ---xxx---                   " << endl;
    }
};

int main() {
    int choice1;
    cout << "Hi! Welcome! Kindly choose an account type: " << endl;
    cout << "1. Savings Account " << endl;
    cout << "2. Current Account " << endl;
    cin >> choice1;
    cout << "                  ---xxx---                   " << endl;
    if (choice1 == 1) {
        sav ac1;
        ac1.get_data();
        int choice2;
        do {
            cout << "Welcome Dear Customer! Under savings account, we have 3 features for you to choose from: " << endl;
            cout << "1. Check interest " << endl;
            cout << "2. Withdrawal " << endl;
            cout << "3. Deposition " << endl;
            cout << "4. Exit " << endl;
            cin >> choice2;
            cout << "                  ---xxx---                   " << endl;
            if (choice2 == 1) {
                ac1.interest();
            } else if (choice2 == 2) {
                ac1.withdraw();
            } else if (choice2 == 3) {
                ac1.deposit();
            } else if (choice2 == 4) {
                break;
            }
        } while (true);
    } else if (choice1 == 2) {
        cur ac2;
        ac2.get_data();
        int choice3;
        do {
            cout << "Welcome Dear Customer! Under current account, we have 2 features for you to choose from:" << endl;
            cout << "1. Check Penalty " << endl;
            cout << "2. Deposition " << endl;
            cout << "3. Exit " << endl;
            cin >> choice3;
            cout << "                  ---xxx---                   " << endl;
            switch (choice3) {
                case 1: ac2.mini(); break;
                case 2: ac2.deposit(); break;
                case 3: break;
            }
        } while (choice3 != 3);
    }
    return 0;
}

