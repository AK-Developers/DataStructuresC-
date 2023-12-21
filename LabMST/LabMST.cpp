#include <iostream>
using namespace std;
void deleteElement(int arr[], int& size, int elementToDelete) {
    int foundIndex = -1;

    for (int i = 0; i < size; ++i) {
        if (arr[i] == elementToDelete) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size;
        cout << "Element " << elementToDelete << " deleted successfully." << std::endl;
    }
    else {
        cout << "Element " << elementToDelete << " not found in the array." << std::endl;
    }
}

int main() {
    const int maxSize = 100;
    int myArray[maxSize] = { 1, 2, 3, 4, 5 };
    int arraySize = 5;

    cout << "Original Array: ";
    for (int i = 0; i < arraySize; i++) {
        cout << myArray[i] << " ";
    }
    int elementToDelete;
    cout << "Enter an element to delete :";
    cin >> elementToDelete;
    deleteElement(myArray, arraySize, elementToDelete);

    // Printing the updated array
    cout << "Updated Array: ";
    for (int i = 0; i < arraySize; i++) {
        cout << myArray[i] << " ";
    }
}
