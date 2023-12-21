#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int myList[] = { 4, 2, 8, 1, 7, 6, 3 };
    int size = sizeof(myList) / sizeof(myList[0]);
    int targetElement = 7;

    int result = linearSearch(myList, size, targetElement);

    if (result != -1) {
        cout << "Element found at Position: " << result+1 << endl;
    }
    else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
