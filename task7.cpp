#include <iostream>
#include <exception>
#include <string>
using namespace std;

class OutOfBoundsException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid index access attempted!";
    }
};

template <typename T>
class SmartArray {
private:
    T* arr;
    int size;

public:
    SmartArray(int s) {
        size = s;
        arr = new T[size];
    }
    ~SmartArray() {
        delete[] arr;
    }

    void input() {
        cout << "Enter elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw OutOfBoundsException();
        }
        return arr[index];
    }

    int getSize() {
        return size;
    }
};

int main() {
    int n;
    cout << "Array size: ";
    cin >> n;

    SmartArray<int> intArr(n);
    intArr.input();

    try {
        cout << "Accessing index 2: " << intArr[2] << endl;

        cout << "Accessing index 5:" << endl;
        cout << intArr[5] << endl; 
    }
    catch (const OutOfBoundsException &e) {
        cout << "OutOfBoundsException caught: " << e.what() << endl;
    }

    cout << endl;

    
    SmartArray<string> strArr(3);
    strArr.input();

    try {
        cout << "Accessing index 1: " << strArr[1] << endl;
    }
    catch (const OutOfBoundsException &e) {
        cout << "OutOfBoundsException caught: " << e.what() << endl;
    }

    return 0;
}
