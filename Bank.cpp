#include <iostream>
#include <iomanip> // For formatting
#include<windows.h>
using namespace std;

// class
class Bank {
private:
    int acno;
    char name[30];
    long balance;

public:
    void OpenAccount();
    void ShowAccount();
    void Deposit();
    void Withdrawal();
    int Search(int);
};

void Bank::OpenAccount() {
    cout << "Enter Account Number: ";
    cin >> acno;
    cout << "Enter Name: ";
    cin.ignore(); // To ignore the newline character left in the input buffer
    cin.getline(name, 30);
    cout << "Enter Initial Balance: $";
    cin >> balance;
}

void Bank::ShowAccount() {
    cout << "--------------------------------------" << endl;
    cout << left << setw(20) << "Account Number:" << setw(10) << acno << endl;
    cout << left << setw(20) << "Account Holder:" << setw(10) << name << endl;
    cout << left << setw(20) << "Current Balance:" << setw(10) << fixed << setprecision(2) << balance << endl;
    cout << "--------------------------------------" << endl;
}

void Bank::Deposit() {
    long amt;
    cout << "Enter Amount to Deposit: $";
    cin >> amt;
    balance += amt;
    cout << "Deposit Successful. New Balance: $" << balance << endl;
}

void Bank::Withdrawal() {
    long amt;
    cout << "Enter Amount to Withdraw: $";
    cin >> amt;
    if (amt <= balance) {
        balance -= amt;
        cout << "Withdrawal Successful. New Balance: $" << balance << endl;
    } else {
        cout << "Error: Insufficient Balance. Withdrawal Denied." << endl;
    }
}

int Bank::Search(int a) {
    if (acno == a) {
        ShowAccount();
        return 1;
    }
    return 0;
}

// main code
int main() {
    Bank C[3]; // Array of 3 Bank objects

    int found = 0, a, ch, i;
    
    // Open accounts
    cout << "Welcome to the Bank" << endl;
    cout << "===================" << endl;
    for (i = 0; i < 3; i++) {
        cout << "\nOpening Account " << (i + 1) << endl;
        C[i].OpenAccount();
    }

    do {
    	system("cls");
        // Display menu options
        cout << "\n\n********** Bank Menu **********" << endl;
        cout << "1. Display All Accounts" << endl;
        cout << "2. Search by Account Number" << endl;
        cout << "3. Deposit Money" << endl;
        cout << "4. Withdraw Money" << endl;
        cout << "5. Exit" << endl;
        cout << "*********************************" << endl;
        cout << "Please input your choice (1-5): ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nDisplaying All Accounts:" << endl;
                for (i = 0; i < 3; i++) {
                    C[i].ShowAccount();
                }
                Sleep(5000);
                break;
                
            case 2:
                cout << "Enter Account Number to Search: ";
                cin >> a;
                found = 0;
                for (i = 0; i < 3; i++) {
                    found = C[i].Search(a);
                    if (found) break;
                }
                if (!found) cout << "Error: Account number " << a << " not found." << endl;
                Sleep(5000);
                break;

            case 3:
                cout << "Enter Account Number to Deposit Money: ";
                cin >> a;
                found = 0;
                for (i = 0; i < 3; i++) {
                    found = C[i].Search(a);
                    if (found) {
                        C[i].Deposit();
                        break;
                    }
                }
                if (!found) cout << "Error: Account number " << a << " not found." << endl;
                Sleep(5000);
                break;

            case 4:
                cout << "Enter Account Number to Withdraw Money: ";
                cin >> a;
                found = 0;
                for (i = 0; i < 3; i++) {
                    found = C[i].Search(a);
                    if (found) {
                        C[i].Withdrawal();
                        break;
                    }
                }
                if (!found) cout << "Error: Account number " << a << " not found." << endl;
                Sleep(5000);
                break;

            case 5:
                cout<<"\tPlease Wait!";
			    for(int i=0;i<3;i++)
			    {
			    cout<<".";
			    Sleep(800);
		        }
		        system("cls");
                cout << "\n\n\tExiting the program. Have a nice day!" << endl;
                break;

            default:
                cout << "Error: Invalid option. Please enter a number between 1 and 5." << endl;
        }
    } while (ch != 5);

    return 0;
}

