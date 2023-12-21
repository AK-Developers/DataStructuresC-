#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid; 
        }
        else if (arr[mid] > target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    int myList[] = { 1, 2, 3, 4, 6, 7, 8 };
    int size = sizeof(myList) / sizeof(myList[0]);
    int targetElement = 6;

    int result = binarySearch(myList, size, targetElement);

    if (result != -1) {
        cout << "Element found at Position: " << result+1 << endl;
        cout << "Element found at index : " << result << endl;
    }
    else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
