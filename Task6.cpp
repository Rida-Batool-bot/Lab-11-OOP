#include <iostream>
#include <exception>
using namespace std;

class InvalidAgeException : public exception {
public:
    const char* what() const noexcept override {
        return "Age must be between 1 and 119";
    }
};

class InvalidSalaryException : public exception {
public:
    const char* what() const noexcept override {
        return "Salary must be positive";
    }
};

class InvalidHeightException : public exception {
public:
    const char* what() const noexcept override {
        return "Height must be positive";
    }
};

int main() {
    int age;
    double salary, height;
    try {
        cout << "Enter age: ";
        cin >> age;

        if (age <= 0 || age >= 120) {
            throw InvalidAgeException();
        }
    }
    catch (const InvalidAgeException &e) {
        cout << "InvalidAgeException caught: " << e.what() << endl;
    }
   try {
        cout << "Enter salary: ";
        cin >> salary;

        if (salary <= 0) {
            throw InvalidSalaryException();
        }
    }
    catch (const InvalidSalaryException &e) {
        cout << "InvalidSalaryException caught: " << e.what() << endl;
    }

    try {
        cout << "Enter height: ";
        cin >> height;

        if (height <= 0) {
            throw InvalidHeightException();
        }
    }
    catch (const InvalidHeightException &e) {
        cout << "InvalidHeightException caught: " << e.what() << endl;
    }

    return 0;
}
