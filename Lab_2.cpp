// WAP to sort the array Elements in ascending order
#include <iostream>
using namespace std;

int main()
{
    // Performing Sorting on the given array
    int my_arr[] = {50, 60, 35, 45, 65, 14};
    int size = 6; // The number of elements in the array
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (my_arr[j] > my_arr[j + 1])
            {
                // Swap the elements if they are in the wrong order
                int temp = my_arr[j];
                my_arr[j] = my_arr[j + 1];
                my_arr[j + 1] = temp;
            }
        }
    }

    // Printing the Sorted Array
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << my_arr[i] << ", ";
    }

    return 0;
}
