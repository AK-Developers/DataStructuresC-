// WAP to insert a new element into an array
#include <iostream>
using namespace std;

// Function to insert an element into an array at a specified position
void insertElement(int arr[], int &size, int element, int position)
{
    if (position < 0 || position > size)
    {
        cout << "Invalid position. Element not inserted." << endl;
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = size; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }

    // Insert the new element at the specified position
    arr[position] = element;
    size++;
}

int main()
{
    const int maxSize = 100; // Maximum array size
    int arr[maxSize];        // Declare an array
    int size = 5;            // Current size of the array

    // Initialize the array
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }

    // Display the original array
    cout << "Original Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Insert a new element (e.g., 6) at position 2
    int newElement;
    cout << "Enter the Element to be inserted :";
    cin >> newElement;
    int insertPosition;
    cout << "Enter the position at which you want to insert :";
    cin >> insertPosition;
    insertElement(arr, size, newElement, insertPosition);

    // Display the modified array
    cout << "Modified Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}