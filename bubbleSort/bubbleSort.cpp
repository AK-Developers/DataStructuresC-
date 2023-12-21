#include <iostream>
using namespace std;
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int myArray[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(myArray) / sizeof(myArray[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << myArray[i] << " ";
    }

    bubbleSort(myArray, n);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << myArray[i] << " ";
    }

    return 0;
}
