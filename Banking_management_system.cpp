#include <bits/stdc++.h>
using namespace std;

class Account {
private:
    string accountHolder;
    long long balance;
    string accountNumber;

public:
    // Constructor
    Account(string name, int initialBal, string accNum) {
        accountHolder = name;
        balance = initialBal;
        accountNumber = accNum;
    }

    string getAccountNumber() {
        return accountNumber;
    }

    void deposit(int amount) {
        balance += amount;
        cout << amount << " Rs deposited successfully!" << endl;
    }

    void withdraw(int amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
            return;
        }
        balance -= amount;
        cout << amount << " Rs withdrawn successfully!" << endl;
    }

    void showDetails() {
        cout << "\n--- Account Details ---\n";
        cout << "Account Holder : " << accountHolder << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Balance        : " << balance << endl;
        cout << "------------------------\n";
    }
};

// Generate 10-digit number starting with 6469
string generateAccountNumber() {
    long long last6 = rand() % 1000000;
    long long num = 6469000000LL + last6;
    return to_string(num);
}

// Search for an account in the vector
Account* findAccount(vector<Account> &accounts, string accNum) {
    for (auto &acc : accounts) {
        if (acc.getAccountNumber() == accNum) {
            return &acc;
        }
    }
    return nullptr; // Not found
}

int main() {
    srand(time(0));

    vector<Account> accounts;
    int choice;

    while (true) {
        cout << "\n======== Banking Management System ========\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Show Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int initialBal;
            cout << "Enter Account Holder Name: ";
            cin >> name;
            cout << "Enter Initial Balance: ";
            cin >> initialBal;

            string accNum = generateAccountNumber();
            accounts.emplace_back(name, initialBal, accNum);

            cout << "Account Created Successfully!" << endl;
            cout << "Your Account Number is: " << accNum << endl;
        }

        else if (choice == 2) {
            string accNum;
            int amt;
            cout << "Enter Account Number: ";
            cin >> accNum;

            Account* acc = findAccount(accounts, accNum);
            if (!acc) {
                cout << "Account not found!" << endl;
                continue;
            }

            cout << "Enter Deposit Amount: ";
            cin >> amt;

            acc->deposit(amt);
        }

        else if (choice == 3) {
            string accNum;
            int amt;
            cout << "Enter Account Number: ";
            cin >> accNum;

            Account* acc = findAccount(accounts, accNum);
            if (!acc) {
                cout << "Account not found!" << endl;
                continue;
            }

            cout << "Enter Withdraw Amount: ";
            cin >> amt;

            acc->withdraw(amt);
        }

        else if (choice == 4) {
            string accNum;
            cout << "Enter Account Number: ";
            cin >> accNum;

            Account* acc = findAccount(accounts, accNum);
            if (!acc) {
                cout << "Account not found!" << endl;
                continue;
            }

            acc->showDetails();
        }

        else if (choice == 5) {
            cout << "Thank you for using the Banking System!" << endl;
            break;
        }

        else {
            cout << "Invalid option! Try again." << endl;
        }
    }

    return 0;
}
