#include <iostream>
#include <exception>
using namespace std;

class InsufficientFundsException : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient funds to complete withdrawal!";
    }
};

class BankAccount {
private:
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFundsException();
        }
        balance -= amount;
        cout << "Withdrawal successful! New Balance: $" << balance << endl;
    }

    void displayBalance() {
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount acc(500);
    double amount;

    acc.displayBalance();
    cout << "Enter withdrawal amount: ";
    cin >> amount;

    try {
        acc.withdraw(amount);
    }
    catch (const InsufficientFundsException &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
