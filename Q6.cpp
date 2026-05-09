#include <iostream>
#include <unordered_map>
using namespace std;

class Bank {
private:
    unordered_map<int, int> accounts;

public:
    bool CREATE(int user, int amount) {
        if (accounts.find(user) == accounts.end()) {
            accounts[user] = amount;
            return true;
        }
        accounts[user] += amount;
        return false;
    }

    bool DEBIT(int user, int amount) {
        if (accounts.find(user) == accounts.end() || accounts[user] < amount) {
            return false;
        }
        accounts[user] -= amount;
        return true;
    }

    bool CREDIT(int user, int amount) {
        if (accounts.find(user) == accounts.end()) {
            return false;
        }
        accounts[user] += amount;
        return true;
    }

    int BALANCE(int user) {
        if (accounts.find(user) == accounts.end()) {
            return -1;
        }
        return accounts[user];
    }
};

int main() {
    int Q;
    cout << "Enter number of queries: ";
    cin >> Q;

    Bank bank;

    while (Q--) {
        string type;
        cout << "\nEnter query type (CREATE / DEBIT / CREDIT / BALANCE): ";
        cin >> type;

        if (type == "CREATE") {
            int x, y;
            cout << "Enter user ID: ";
            cin >> x;
            cout << "Enter initial amount: ";
            cin >> y;

            bool result = bank.CREATE(x, y);
            cout << "Result: " << (result ? "true" : "false") << endl;
        }
        else if (type == "DEBIT") {
            int x, y;
            cout << "Enter user ID: ";
            cin >> x;
            cout << "Enter amount to debit: ";
            cin >> y;

            bool result = bank.DEBIT(x, y);
            cout << "Result: " << (result ? "true" : "false") << endl;
        }
        else if (type == "CREDIT") {
            int x, y;
            cout << "Enter user ID: ";
            cin >> x;
            cout << "Enter amount to credit: ";
            cin >> y;

            bool result = bank.CREDIT(x, y);
            cout << "Result: " << (result ? "true" : "false") << endl;
        }
        else if (type == "BALANCE") {
            int x;
            cout << "Enter user ID: ";
            cin >> x;

            int result = bank.BALANCE(x);
            cout << "Balance: " << result << endl;
        }
        else {
            cout << "Invalid query type!" << endl;
        }
    }

    return 0;
}
