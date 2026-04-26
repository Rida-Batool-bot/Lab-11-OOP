#include <iostream>
#include <string>
using namespace std;
template <typename T>
T findMax(T arr[], int size) {
    T maxVal = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    return maxVal;
}

int main() {
    int intArr[] = {10, 20, 5, 30, 25};
    int size1 = 5;

    cout << "Array: [10, 20, 5, 30, 25]" << endl;
    cout << "Maximum: " << findMax(intArr, size1) << endl;

    cout << endl;
    string strArr[] = {"Apple", "Mango", "Banana", "Peach"};
    int size2 = 4;

    cout << "Array: [\"Apple\", \"Mango\", \"Banana\", \"Peach\"]" << endl;
    cout << "Maximum: " << findMax(strArr, size2) << endl;

    return 0;
}
